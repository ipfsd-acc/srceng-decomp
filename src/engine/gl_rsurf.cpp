// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/gl_rsurf.cpp
// Functions: 118
// ============================================================

#include "engine\gl_rsurf.h"

//------------------------------------------------------------------------------
// Address: 0x10065730
// Name: void R_Surface_LevelInit(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_Surface_LevelInit()
{
  CBrushBatchRender::LevelInit(this: &g_BrushBatchRenderer);
}

//------------------------------------------------------------------------------
// Address: 0x100CED90
// Name: void Vector2DSubtract(class Vector2D const __near &,class Vector2D const __near &,class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Vector2DSubtract(const Vector2D *a, const Vector2D *b, Vector2D *c)
{
  c->x = a->x - b->x;
  c->y = a->y - b->y;
}

//------------------------------------------------------------------------------
// Address: 0x100CEDC0
// Name: bool MatrixIsIdentity(struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl MatrixIsIdentity(const matrix3x4_t *m)
{
  return m->m_flMatVal[0][0] == 1.0
      && m->m_flMatVal[0][1] == 0.0
      && m->m_flMatVal[0][2] == 0.0
      && m->m_flMatVal[0][3] == 0.0
      && m->m_flMatVal[1][0] == 0.0
      && m->m_flMatVal[1][1] == 1.0
      && m->m_flMatVal[1][2] == 0.0
      && m->m_flMatVal[1][3] == 0.0
      && m->m_flMatVal[2][0] == 0.0
      && m->m_flMatVal[2][1] == 0.0
      && m->m_flMatVal[2][2] == 1.0
      && m->m_flMatVal[2][3] == 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x100CEE90
// Name: int R_GetBrushModelPlaneCount(struct model_t const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl R_GetBrushModelPlaneCount(const model_t *model)
{
  return model->brush.nummodelsurfaces;
}

//------------------------------------------------------------------------------
// Address: 0x100CEEA0
// Name: int SortInfoToLightmapPage(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl SortInfoToLightmapPage(int sortID)
{
  return materialSortInfoArray[sortID].lightmapPageID;
}

//------------------------------------------------------------------------------
// Address: 0x100CEEC0
// Name: void R_DrawTopView(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_DrawTopView(bool enable)
{
  r_drawtopview = enable;
}

//------------------------------------------------------------------------------
// Address: 0x100CEED0
// Name: void R_TopViewBounds(class Vector2D const __near &,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_TopViewBounds(const Vector2D *mins, const Vector2D *maxs)
{
  float v2; // xmm1_4

  s_OrthographicCenter.x = mins->x + maxs->x;
  v2 = (float)(mins->y + maxs->y) * 0.5;
  s_OrthographicCenter.x = s_OrthographicCenter.x * 0.5;
  s_OrthographicCenter.y = v2;
  s_OrthographicHalfDiagonal.x = maxs->x - s_OrthographicCenter.x;
  s_OrthographicHalfDiagonal.y = maxs->y - v2;
}

//------------------------------------------------------------------------------
// Address: 0x100CEF40
// Name: DrawSurfaceID
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawSurfaceID(IMatRenderContext *pRenderContext, msurface2_t *surfID, IMatRenderContext *vecCentroid)
{
  char duration[8]; // [esp+0h] [ebp-20h] BYREF

  V_snprintf(pDest: duration, maxLen: 32, pFormat: &args.m_pArgSBuffer[240], surfID);
  CDebugOverlay::AddTextOverlay(textPos: (const Vector *)vecCentroid, duration: 0.0, text: duration);
}

//------------------------------------------------------------------------------
// Address: 0x100CEF80
// Name: DrawSurfaceIDAsInt
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawSurfaceIDAsInt(IMatRenderContext *pRenderContext, msurface2_t *surfID, IMatRenderContext *vecCentroid)
{
  char duration[8]; // [esp+0h] [ebp-20h] BYREF

  V_snprintf(pDest: duration, maxLen: 32, pFormat: "%d", surfID - host_state.worldbrush->surfaces2);
  CDebugOverlay::AddTextOverlay(textPos: (const Vector *)vecCentroid, duration: 0.0, text: duration);
}

//------------------------------------------------------------------------------
// Address: 0x100CEFD0
// Name: class IMaterial __near * R_GetFogVolumeMaterial(int,bool)
// Source: json
//------------------------------------------------------------------------------
IMaterial *__cdecl R_GetFogVolumeMaterial(int nFogVolume, bool bEyeInFogVolume)
{
  IMaterial *material; // esi
  int v3; // eax
  const char *v4; // eax

  if ( nFogVolume < 0 || nFogVolume > host_state.worldbrush->numleafwaterdata )
    return nullptr;
  material = host_state.worldbrush->texinfo[host_state.worldbrush->leafwaterdata[nFogVolume].surfaceTexInfoID].material;
  if ( bEyeInFogVolume )
  {
    v3 = (int)material->FindVar(this: material, a2: &args.m_pArgSBuffer[248], a3: nullptr, a4: true);
    if ( v3 != 0 )
    {
      v4 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v3 + 28))(a1: v3);
      if ( v4 != nullptr )
        return materials->FindMaterial(this: materials, a2: v4, a3: "Other textures", a4: 1, a5: 0);
    }
  }
  return material;
}

//------------------------------------------------------------------------------
// Address: 0x100CF050
// Name: private: bool CVisibleFogVolumeQuery::RecursiveGetVisibleFogVolume(struct mnode_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVisibleFogVolumeQuery::RecursiveGetVisibleFogVolume(CVisibleFogVolumeQuery *this, mnode_t *node)
{
  mnode_t *v2; // esi
  cplane_t *plane; // eax
  unsigned __int8 type; // cl
  float v6; // xmm0_4
  BOOL v7; // edi
  __int16 plane_high; // ax

  v2 = node;
  if ( node->contents != 1 )
  {
    while ( v2->visframe == r_visframecount && !R_CullNode(pNode: v2) )
    {
      if ( v2->contents >= 0 )
      {
        plane_high = HIWORD(v2->plane);
        if ( plane_high != -1 && (v2->contents & 0x10) == 0 )
        {
          this->m_nVisibleFogVolume = plane_high;
          this->m_nVisibleFogVolumeLeaf = ((char *)v2 - (char *)host_state.worldbrush->leafs) >> 6;
          return 0;
        }
        return 1;
      }
      plane = v2->plane;
      type = plane->type;
      if ( type > 2u )
        v6 = (float)((float)(plane->normal.y * this->m_vecSearchPoint.y)
                   + (float)(plane->normal.x * this->m_vecSearchPoint.x))
           + (float)(plane->normal.z * this->m_vecSearchPoint.z);
      else
        v6 = *(&this->m_vecSearchPoint.x + type);
      v7 = (float)(v6 - plane->dist) < 0.0;
      if ( !CVisibleFogVolumeQuery::RecursiveGetVisibleFogVolume(this, node: v2->children[v7]) )
        return 0;
      v2 = v2->children[!v7];
      if ( v2->contents == 1 )
        return 1;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100CF140
// Name: public: virtual void CBrushSurface::ComputeTextureCoordinate(class Vector const __near &,class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBrushSurface::ComputeTextureCoordinate(
        CBrushSurface *this,
        const Vector *worldPos,
        Vector2D *texCoord)
{
  SurfComputeTextureCoordinate(surfID: this->m_SurfaceID, vec: worldPos, pUV: &texCoord->x);
}

//------------------------------------------------------------------------------
// Address: 0x100CF160
// Name: public: virtual void CBrushSurface::ComputeLightmapCoordinate(class Vector const __near &,class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBrushSurface::ComputeLightmapCoordinate(
        CBrushSurface *this,
        const Vector *worldPos,
        Vector2D *lightmapCoord)
{
  SurfComputeLightmapCoordinate(ctx: &this->m_Ctx, surfID: this->m_SurfaceID, vec: worldPos, uv: lightmapCoord);
}

//------------------------------------------------------------------------------
// Address: 0x100CF180
// Name: void R_InstallBrushRenderOverride(class IBrushRenderer __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_InstallBrushRenderOverride(IBrushRenderer *pBrushRenderer)
{
  s_pBrushRenderOverride = pBrushRenderer;
}

//------------------------------------------------------------------------------
// Address: 0x100CF190
// Name: int R_MarkDlightsOnBrushModel(struct model_t __near *,class IClientRenderable __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl R_MarkDlightsOnBrushModel(model_t *model, IClientRenderable *pRenderable)
{
  int v2; // edi
  const Vector *v3; // eax
  float *p_z; // esi
  CClientState *BaseLocalClient; // eax
  float v6; // xmm2_4
  float v7; // xmm4_4
  float v8; // xmm5_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  mnode_t *v11; // edi
  const QAngle *v13; // [esp-Ch] [ebp-30h]
  float v14; // [esp+10h] [ebp-14h]
  float v15; // [esp+14h] [ebp-10h]
  float v16; // [esp+18h] [ebp-Ch]
  int saveOrigin; // [esp+1Ch] [ebp-8h]
  int saveOrigin_4; // [esp+20h] [ebp-4h]

  v2 = 0;
  saveOrigin_4 = 0;
  if ( g_bActiveDlights )
  {
    v13 = pRenderable->GetRenderAngles(this: pRenderable);
    v3 = pRenderable->GetRenderOrigin(this: pRenderable);
    VMatrix::SetupMatrixOrgAngles(this: &g_BrushToWorldMatrix, origin: v3, vAngles: v13);
    saveOrigin = 1;
    p_z = &cl_dlights[0].origin.z;
    do
    {
      BaseLocalClient = GetBaseLocalClient();
      if ( CClientState::GetTime(this: BaseLocalClient) <= p_z[3] && (float)(p_z[1] > 0.0) != 0.0 )
      {
        v15 = *(p_z - 1);
        v16 = *p_z;
        v14 = *(p_z - 2);
        v6 = *p_z - g_BrushToWorldMatrix.m[2][3];
        v7 = (float)((float)(g_BrushToWorldMatrix.m[1][1] * (float)(v15 - g_BrushToWorldMatrix.m[1][3]))
                   + (float)(g_BrushToWorldMatrix.m[0][1] * (float)(v14 - g_BrushToWorldMatrix.m[0][3])))
           + (float)(g_BrushToWorldMatrix.m[2][1] * v6);
        v8 = g_BrushToWorldMatrix.m[1][2] * (float)(v15 - g_BrushToWorldMatrix.m[1][3]);
        v9 = g_BrushToWorldMatrix.m[0][2] * (float)(v14 - g_BrushToWorldMatrix.m[0][3]);
        v10 = g_BrushToWorldMatrix.m[2][2];
        *(p_z - 2) = (float)((float)(g_BrushToWorldMatrix.m[1][0] * (float)(v15 - g_BrushToWorldMatrix.m[1][3]))
                           + (float)(g_BrushToWorldMatrix.m[0][0] * (float)(v14 - g_BrushToWorldMatrix.m[0][3])))
                   + (float)(g_BrushToWorldMatrix.m[2][0] * v6);
        *(p_z - 1) = v7;
        *p_z = (float)(v8 + v9) + (float)(v10 * v6);
        v11 = (mnode_t *)(*(_DWORD *)(model->sprite.numframes + 84) + (model->brush.firstnode << 6));
        if ( IsBoxIntersectingSphereExtents(
               boxCenter: &v11->m_vecCenter,
               boxHalfDiag: &v11->m_vecHalfDiagonal,
               center: (const Vector *)(p_z - 2),
               radius: p_z[1]) )
        {
          saveOrigin_4 += R_MarkLights(light: (dlight_t *)(p_z - 3), bit: saveOrigin, node: v11);
        }
        v2 = saveOrigin_4;
        *(p_z - 2) = v14;
        *(p_z - 1) = v15;
        *p_z = v16;
      }
      p_z += 17;
      saveOrigin = __ROL4__(saveOrigin, 1);
    }
    while ( (int)p_z < (int)&cl_elights[0].origin.z );
    if ( v2 != 0 )
      model->flags |= 0x20u;
    MatrixSetIdentity(dst: &g_BrushToWorldMatrix);
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x100CF3B0
// Name: void Shader_BrushEnd(class IMatRenderContext __near *,class VMatrix const __near *,struct model_t __near *,bool,class IClientEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Shader_BrushEnd(
        IMatRenderContext *pRenderContext,
        const VMatrix *pBrushToWorld,
        IMatRenderContext *model,
        bool bShadowDepth)
{
  if ( !bShadowDepth )
  {
    DecalSurfaceDraw(pRenderContext, renderGroup: 4, flFade: r_blend);
    ((void (__thiscall *)(IShadowMgrInternal *, IMatRenderContext *, int, _DWORD, _DWORD))g_pShadowMgr->DrawFlashlightDecals)(
      a1: g_pShadowMgr,
      a2: pRenderContext,
      a3: 4,
      a4: 0,
      a5: LODWORD(r_blend));
    R_DecalFlushDestroyList();
    g_pShadowMgr->RenderProjectedTextures(this: g_pShadowMgr, a2: pRenderContext, a3: pBrushToWorld);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CF410
// Name: public: CBrushModelTransform::CBrushModelTransform(class Vector const __near &,class QAngle const __near &,class IMatRenderContext __near *)
// Source: json
//------------------------------------------------------------------------------
CBrushModelTransform *__thiscall CBrushModelTransform::CBrushModelTransform(
        CBrushModelTransform *this,
        const Vector *origin,
        const QAngle *angles,
        IMatRenderContext *pRenderContext)
{
  bool v5; // cl
  bool v6; // al
  const Vector *v8; // eax
  float v9; // xmm5_4
  float x; // [esp+0h] [ebp-Ch]
  float y; // [esp+4h] [ebp-8h]
  float z; // [esp+8h] [ebp-4h]

  v5 = angles->x != 0.0 || angles->y != 0.0 || angles->z != 0.0;
  v6 = vec3_origin.x == origin->x && vec3_origin.y == origin->y && vec3_origin.z == origin->z && !v5;
  this->m_bIdentity = v6;
  if ( !v6 )
  {
    this->m_savedModelorg = modelorg;
    pRenderContext->MatrixMode(this: pRenderContext, a2: MATERIAL_MODEL);
    pRenderContext->PushMatrix(this: pRenderContext);
    VMatrix::SetupMatrixOrgAngles(this: &g_BrushToWorldMatrix, origin, vAngles: angles);
    pRenderContext->LoadMatrix_2(this: pRenderContext, a2: &g_BrushToWorldMatrix);
    v8 = g_EngineRenderer->ViewOrigin(this: g_EngineRenderer);
    x = v8->x;
    y = v8->y;
    z = v8->z;
    v9 = (float)((float)(g_BrushToWorldMatrix.m[1][2] * (float)(y - g_BrushToWorldMatrix.m[1][3]))
               + (float)(g_BrushToWorldMatrix.m[0][2] * (float)(v8->x - g_BrushToWorldMatrix.m[0][3])))
       + (float)(g_BrushToWorldMatrix.m[2][2] * (float)(z - g_BrushToWorldMatrix.m[2][3]));
    modelorg.x = (float)((float)(g_BrushToWorldMatrix.m[1][0] * (float)(y - g_BrushToWorldMatrix.m[1][3]))
                       + (float)(g_BrushToWorldMatrix.m[0][0] * (float)(v8->x - g_BrushToWorldMatrix.m[0][3])))
               + (float)(g_BrushToWorldMatrix.m[2][0] * (float)(z - g_BrushToWorldMatrix.m[2][3]));
    modelorg.y = (float)((float)(g_BrushToWorldMatrix.m[1][1] * (float)(y - g_BrushToWorldMatrix.m[1][3]))
                       + (float)(g_BrushToWorldMatrix.m[0][1] * (float)(x - g_BrushToWorldMatrix.m[0][3])))
               + (float)(g_BrushToWorldMatrix.m[2][1] * (float)(z - g_BrushToWorldMatrix.m[2][3]));
    modelorg.z = v9;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100CF5F0
// Name: public: CBrushModelTransform::CBrushModelTransform(class matrix3x4a_t const __near &,class IMatRenderContext __near *)
// Source: json
//------------------------------------------------------------------------------
CBrushModelTransform *__thiscall CBrushModelTransform::CBrushModelTransform(
        CBrushModelTransform *this,
        const matrix3x4a_t *matrix,
        IMatRenderContext *pRenderContext)
{
  bool IsIdentity; // al
  const Vector *v6; // eax
  float x; // [esp+8h] [ebp-10h]
  float y; // [esp+Ch] [ebp-Ch]
  float z; // [esp+10h] [ebp-8h]

  IsIdentity = MatrixIsIdentity(m: matrix);
  this->m_bIdentity = IsIdentity;
  if ( IsIdentity )
    return this;
  this->m_savedModelorg = modelorg;
  pRenderContext->MatrixMode(this: pRenderContext, a2: MATERIAL_MODEL);
  pRenderContext->PushMatrix(this: pRenderContext);
  *(matrix3x4a_t *)&g_BrushToWorldMatrix.m[0][0] = *matrix;
  *(_QWORD *)&g_BrushToWorldMatrix.m[3][0] = 0;
  *(_QWORD *)&g_BrushToWorldMatrix.m[3][2] = 0x3F80000000000000LL;
  pRenderContext->LoadMatrix_2(this: pRenderContext, a2: &g_BrushToWorldMatrix);
  v6 = g_EngineRenderer->ViewOrigin(this: g_EngineRenderer);
  x = v6->x;
  y = v6->y;
  z = v6->z;
  modelorg.x = (float)((float)(g_BrushToWorldMatrix.m[1][0] * (float)(y - g_BrushToWorldMatrix.m[1][3]))
                     + (float)(g_BrushToWorldMatrix.m[0][0] * (float)(v6->x - g_BrushToWorldMatrix.m[0][3])))
             + (float)(g_BrushToWorldMatrix.m[2][0] * (float)(z - g_BrushToWorldMatrix.m[2][3]));
  modelorg.y = (float)((float)(g_BrushToWorldMatrix.m[1][1] * (float)(y - g_BrushToWorldMatrix.m[1][3]))
                     + (float)(g_BrushToWorldMatrix.m[0][1] * (float)(x - g_BrushToWorldMatrix.m[0][3])))
             + (float)(g_BrushToWorldMatrix.m[2][1] * (float)(z - g_BrushToWorldMatrix.m[2][3]));
  modelorg.z = (float)((float)(g_BrushToWorldMatrix.m[1][2] * (float)(y - g_BrushToWorldMatrix.m[1][3]))
                     + (float)(g_BrushToWorldMatrix.m[0][2] * (float)(x - g_BrushToWorldMatrix.m[0][3])))
             + (float)(g_BrushToWorldMatrix.m[2][2] * (float)(z - g_BrushToWorldMatrix.m[2][3]));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100CF7C0
// Name: EnumerateLeavesAlongRay_R
// Source: json
//------------------------------------------------------------------------------
bool __cdecl EnumerateLeavesAlongRay_R(
        mnode_t *node,
        const Ray_t *ray,
        float start,
        float end,
        ISpatialLeafEnumerator *pEnum,
        const Ray_t *context)
{
  mnode_t *v6; // esi
  int contents; // eax
  float v8; // xmm6_4
  float v9; // xmm5_4
  cplane_t *plane; // eax
  int type; // ecx
  float v12; // xmm2_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  BOOL v16; // edi
  float v18; // [esp+24h] [ebp+8h]

  v6 = node;
  contents = node->contents;
  if ( node->contents == 1 )
    return true;
  v8 = end;
  v9 = start;
  while ( 1 )
  {
    if ( contents >= 0 )
      return pEnum->EnumerateLeaf(
               this: pEnum,
               a2: ((char *)v6 - (char *)host_state.worldbrush->leafs) >> 6,
               a3: (int)context);
    plane = v6->plane;
    if ( plane->type > 2u )
    {
      v12 = (float)((float)(ray->m_Start.y * plane->normal.y) + (float)(ray->m_Start.x * plane->normal.x))
          + (float)(ray->m_Start.z * plane->normal.z);
      v13 = (float)((float)(ray->m_Delta.y * plane->normal.y) + (float)(plane->normal.x * ray->m_Delta.x))
          + (float)(ray->m_Delta.z * plane->normal.z);
    }
    else
    {
      type = plane->type;
      v12 = *(&ray->m_Start.x + type);
      v13 = *(&ray->m_Delta.x + type);
    }
    v14 = (float)((float)(v13 * v9) + v12) - plane->dist;
    v15 = (float)((float)(v13 * v8) + v12) - plane->dist;
    v16 = v14 < 0.0;
    if ( v15 < 0.0 != v16 )
      break;
    v6 = v6->children[v16];
LABEL_11:
    contents = v6->contents;
    if ( v6->contents == 1 )
      return true;
  }
  v18 = (float)((float)(1.0 - (float)(v14 / (float)(v14 - v15))) * v9) + (float)((float)(v14 / (float)(v14 - v15)) * v8);
  if ( EnumerateLeavesAlongRay_R(node: v6->children[v16], ray, start, end: v18, pEnum, (int)context) )
  {
    v9 = (float)((float)(1.0 - (float)(v14 / (float)(v14 - v15))) * v9)
       + (float)((float)(v14 / (float)(v14 - v15)) * v8);
    v8 = end;
    start = v18;
    v6 = v6->children[v14 >= 0.0];
    goto LABEL_11;
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x100CF940
// Name: public: virtual bool CEngineBSPTree::EnumerateLeavesAtPoint(class Vector const __near &,class ISpatialLeafEnumerator __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineBSPTree::EnumerateLeavesAtPoint(
        CEngineBSPTree *this,
        const Vector *pt,
        ISpatialLeafEnumerator *pEnum,
        int context)
{
  int v4; // eax

  v4 = CM_PointLeafnum(p: pt);
  return pEnum->EnumerateLeaf(this: pEnum, a2: v4, a3: context);
}

//------------------------------------------------------------------------------
// Address: 0x100CF970
// Name: public: virtual int CEngineBSPTree::ListLeavesInSphereWithFlagSet(int __near *,class Vector const __near &,float,int,unsigned short const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineBSPTree::ListLeavesInSphereWithFlagSet(
        CEngineBSPTree *this,
        int *pLeafsInSphere,
        const Vector *vecCenter,
        float flRadius,
        int nLeafCount,
        const unsigned __int16 *pLeafs,
        const unsigned __int16 *nLeafStride,
        int nFlagsCheck)
{
  int v8; // ebx
  int i; // esi
  mleaf_t *v11; // eax

  v8 = 0;
  for ( i = 0; i < nLeafCount; ++i )
  {
    v11 = &host_state.worldbrush->leafs[*pLeafs];
    if ( (v11->flags & nFlagsCheck) != 0
      && IsBoxIntersectingSphereExtents(
           boxCenter: &v11->m_vecCenter,
           boxHalfDiag: &v11->m_vecHalfDiagonal,
           center: vecCenter,
           radius: flRadius) )
    {
      pLeafsInSphere[v8++] = i;
    }
    pLeafs = (const unsigned __int16 *)((char *)pLeafs + (_DWORD)nLeafStride);
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x100CF9E0
// Name: public: virtual bool CEngineBSPTree::EnumerateLeavesInBox(class Vector const __near &,class Vector const __near &,class ISpatialLeafEnumerator __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CEngineBSPTree::EnumerateLeavesInBox@<al>(
        CEngineBSPTree *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        const Vector *mins,
        const Vector *maxs,
        ISpatialLeafEnumerator *pEnum,
        int context)
{
  int v8; // edi
  int i; // esi
  unsigned __int16 list[1024]; // [esp+0h] [ebp-800h] BYREF

  if ( host_state.worldmodel == nullptr )
    return 0;
  v8 = ((int (__thiscall *)(CEngineBSPTree *, const Vector *, const Vector *, unsigned __int16 *, int, int, int))this->ListLeavesInBox)(
         a1: this,
         a2: mins,
         a3: maxs,
         a4: list,
         a5: 1024,
         a6: a2,
         a7: a3);
  for ( i = 0; i < v8; ++i )
  {
    if ( pEnum->EnumerateLeaf(this: pEnum, a2: list[i], a3: context) == 0 )
      break;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100CFA50
// Name: public: void CIndexBuilder::FastIndexList(unsigned short const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIndexBuilder::FastIndexList(CIndexBuilder *this, char *pIndexList, int startVert, int indexCount)
{
  signed int v4; // esi
  unsigned __int16 *v5; // eax
  char *v6; // edx
  unsigned int v7; // edi
  unsigned __int16 v8; // bx
  int m_nCurrentIndex; // eax
  int startVerta; // [esp+10h] [ebp+Ch]

  v4 = indexCount * this->m_nIndexSize;
  v5 = &this->m_pIndices[this->m_nCurrentIndex];
  startVerta = this->m_nIndexOffset + startVert;
  if ( v4 > 0 )
  {
    v6 = (char *)(pIndexList - (char *)v5);
    v7 = indexCount * this->m_nIndexSize;
    do
    {
      v8 = startVerta + *(unsigned __int16 *)((char *)v5++ + (_DWORD)v6);
      --v7;
      *(v5 - 1) = v8;
    }
    while ( v7 != 0 );
  }
  this->m_nCurrentIndex += v4 * this->m_nIndexSize;
  m_nCurrentIndex = this->m_nCurrentIndex;
  if ( m_nCurrentIndex > this->m_nIndexCount )
    this->m_nIndexCount = m_nCurrentIndex;
}

//------------------------------------------------------------------------------
// Address: 0x100CFAB0
// Name: struct cplane_t const __near & R_GetBrushModelPlane(struct model_t const __near *,int,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
const cplane_t *__cdecl R_GetBrushModelPlane(const model_t *model, int nIndex, Vector *pOrigin)
{
  int v3; // eax
  float *v5; // edx
  float v6; // xmm0_4

  v3 = *(_DWORD *)(model->sprite.numframes + 124) + 32 * (nIndex + model->brush.firstmodelsurface);
  if ( pOrigin != nullptr )
  {
    if ( *(_BYTE *)(v3 + 3) != 0 )
    {
      *pOrigin = *(Vector *)(*(_DWORD *)(model->sprite.numframes + 36)
                           + 12
                           * *(unsigned __int16 *)(*(_DWORD *)(model->sprite.numframes + 148) + 2 * *(_DWORD *)(v3 + 8)));
      return *(const cplane_t **)(v3 + 4);
    }
    v5 = *(float **)(v3 + 4);
    v6 = v5[3];
    pOrigin->x = *v5 * v6;
    pOrigin->y = v5[1] * v6;
    pOrigin->z = v5[2] * v6;
  }
  return *(const cplane_t **)(v3 + 4);
}

//------------------------------------------------------------------------------
// Address: 0x100CFB50
// Name: void Surf_ComputeCentroid(struct msurface2_t __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Surf_ComputeCentroid(msurface2_t *surfID, Vector *pVecCentroid)
{
  int firstvertindex; // edx
  worldbrushdata_t *worldbrush; // esi
  mvertex_t *v4; // eax
  float z; // xmm6_4
  float y; // xmm7_4
  unsigned __int16 *v7; // edx
  mvertex_t *vertexes; // esi
  float *p_x; // eax
  float v10; // edi
  float *v11; // eax
  float v12; // edx
  float v13; // eax
  float v14; // xmm4_4
  float v15; // xmm2_4
  float v16; // xmm1_4
  float v17; // xmm4_4
  float v18; // xmm5_4
  float v19; // xmm0_4
  bool v20; // zf
  float v21; // xmm1_4
  float v22; // [esp-24h] [ebp-5Ch]
  float v23; // [esp-Ch] [ebp-44h]
  float v2; // [esp+0h] [ebp-38h]
  float v2_8; // [esp+8h] [ebp-30h]
  float v1; // [esp+Ch] [ebp-2Ch]
  float v1_4; // [esp+10h] [ebp-28h]
  float v1_8; // [esp+14h] [ebp-24h]
  int vecApex; // [esp+18h] [ebp-20h]
  int vecApexa; // [esp+18h] [ebp-20h]
  float vecApex_4; // [esp+1Ch] [ebp-1Ch]
  float vecApex_8; // [esp+20h] [ebp-18h]
  float nCount; // [esp+24h] [ebp-14h]
  int v34; // [esp+28h] [ebp-10h]

  firstvertindex = surfID->firstvertindex;
  vecApex = HIBYTE(surfID->flags);
  pVecCentroid->x = 0.0;
  pVecCentroid->y = 0.0;
  pVecCentroid->z = 0.0;
  worldbrush = host_state.worldbrush;
  v4 = &host_state.worldbrush->vertexes[host_state.worldbrush->vertindices[firstvertindex]];
  v1 = v4->position.x;
  v1_8 = v4->position.z;
  nCount = 0.0;
  v1_4 = v4->position.y;
  if ( vecApex - 1 > 1 )
  {
    z = v4->position.z;
    y = v4->position.y;
    vecApex_8 = 0.0;
    vecApex_4 = 0.0;
    v34 = 2 * firstvertindex + 2;
    vecApexa = vecApex - 2;
    while ( 1 )
    {
      v7 = (unsigned __int16 *)((char *)worldbrush->vertindices + v34);
      vertexes = worldbrush->vertexes;
      p_x = &vertexes[*v7].position.x;
      v2 = *p_x;
      v10 = p_x[1];
      v2_8 = p_x[2];
      v11 = &vertexes[v7[1]].position.x;
      v23 = *v11;
      v12 = v11[1];
      v13 = v11[2];
      v14 = (float)(v12 - v10) * (float)(v2_8 - z);
      v15 = (float)(v2_8 - z) * (float)(v23 - v2);
      z = v1_8;
      v16 = (float)((float)((float)((float)(v13 - v2_8) * (float)(v2 - v1)) - v15)
                  * (float)((float)((float)(v13 - v2_8) * (float)(v2 - v1)) - v15))
          + (float)((float)((float)((float)(v10 - y) * (float)(v23 - v2))
                          - (float)((float)(v12 - v10) * (float)(v2 - v1)))
                  * (float)((float)((float)(v10 - y) * (float)(v23 - v2))
                          - (float)((float)(v12 - v10) * (float)(v2 - v1))));
      v17 = v14 - (float)((float)(v13 - v2_8) * (float)(v10 - y));
      y = v1_4;
      v22 = fsqrt(v16 + (float)(v17 * v17));
      v18 = v22 + nCount;
      v19 = pVecCentroid->x + (float)((float)((float)((float)(v1 + v2) + v23) * v22) * 0.33333334);
      nCount = v22 + nCount;
      pVecCentroid->x = v19;
      vecApex_8 = (float)((float)((float)((float)(v1_4 + v10) + v12) * v22) * 0.33333334) + vecApex_8;
      v34 += 2;
      v20 = vecApexa-- == 1;
      pVecCentroid->y = vecApex_8;
      v21 = vecApex_4 + (float)((float)((float)((float)(v1_8 + v2_8) + v13) * v22) * 0.33333334);
      vecApex_4 = v21;
      pVecCentroid->z = v21;
      if ( v20 )
        break;
      worldbrush = host_state.worldbrush;
    }
    if ( v18 != 0.0 )
    {
      pVecCentroid->x = v19 * (float)(1.0 / v18);
      pVecCentroid->y = vecApex_8 * (float)(1.0 / v18);
      pVecCentroid->z = v21 * (float)(1.0 / v18);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CFDB0
// Name: class IMaterial __near * Shader_SetChainTextureState(class IMatRenderContext __near *,struct msurface2_t __near *,class IClientEntity __near *,bool)
// Source: json
//------------------------------------------------------------------------------
IMaterial *__cdecl Shader_SetChainTextureState(
        IMatRenderContext *pRenderContext,
        msurface2_t *surfID,
        IClientEntity *pBaseEntity,
        bool bShadowDepth)
{
  IMaterial *material; // esi
  BOOL v5; // ebx
  IMaterial *v6; // edi
  IMaterialVar *v7; // ebx
  IMaterialVar *v8; // esi
  int v9; // eax
  int v10; // eax
  IClientRenderable *v12; // eax
  IMatRenderContext_vtbl *v13; // edx
  void (__thiscall *BindLightmapPage)(IMatRenderContext *, int); // eax
  float v15; // [esp+0h] [ebp-1Ch]
  int v16; // [esp+10h] [ebp-Ch]
  int v17; // [esp+14h] [ebp-8h]
  int v18; // [esp+18h] [ebp-4h]
  IMaterialVar_vtbl *v19; // [esp+28h] [ebp+Ch]
  int v20; // [esp+30h] [ebp+14h]

  material = host_state.worldbrush->texinfo[*((unsigned __int16 *)surfID + 11) >> 1].material;
  if ( bShadowDepth )
  {
    v5 = material->IsAlphaTested(this: host_state.worldbrush->texinfo[*((unsigned __int16 *)surfID + 11) >> 1].material);
    v6 = g_pMaterialDepthWrite[v5][(unsigned __int8)material->IsTwoSided(this: material)];
    if ( v5 )
    {
      v7 = material->FindVarFast(this: material, a2: "$basetexture", a3: &originalTextureVarCache_2);
      v17 = (int)material->FindVarFast(this: material, a2: "$frame", a3: &originalTextureFrameVarCache_2);
      v16 = (int)material->FindVarFast(this: material, a2: "$AlphaTestReference", a3: &originalAlphaRefCache_2);
      v8 = v6->FindVarFast(this: v6, a2: "$basetexture", a3: &textureVarCache_2);
      v18 = (int)v6->FindVarFast(this: v6, a2: "$frame", a3: &textureFrameVarCache_2);
      v20 = (int)v6->FindVarFast(this: v6, a2: "$AlphaTestReference", a3: &alphaRefCache_2);
      if ( v8 != nullptr && v7 != nullptr )
      {
        v19 = v8->__vftable;
        v9 = v7->GetTextureValue(this: v7);
        v19->SetTextureValue(this: v8, a2: (ITexture *)v9);
      }
      if ( v18 != 0 && v17 != 0 )
      {
        v10 = (*(int (__thiscall **)(int))(*(_DWORD *)v17 + 108))(a1: v17);
        (*(void (__thiscall **)(int, int))(*(_DWORD *)v18 + 20))(a1: v18, a2: v10);
      }
      if ( v20 != 0 && v16 != 0 )
      {
        v15 = ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v16 + 112))(a1: v16);
        (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v20 + 16))(a1: LODWORD(v15));
      }
    }
    pRenderContext->Bind(this: pRenderContext, a2: v6, a3: nullptr);
    return v6;
  }
  else
  {
    if ( pBaseEntity != nullptr )
      v12 = pBaseEntity->GetClientRenderable(this: pBaseEntity);
    else
      v12 = nullptr;
    pRenderContext->Bind(this: pRenderContext, a2: material, a3: (void *)v12);
    v13 = pRenderContext->__vftable;
    if ( g_pMaterialSystemConfig->nFullbright == 1 )
    {
      BindLightmapPage = v13->BindLightmapPage;
      if ( (surfID->flags & 8) != 0 )
        BindLightmapPage(this: pRenderContext, a2: -2);
      else
        BindLightmapPage(this: pRenderContext, a2: -1);
      return material;
    }
    else
    {
      v13->BindLightmapPage(this: pRenderContext, a2: materialSortInfoArray[surfID->materialSortID].lightmapPageID);
      return material;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CFF90
// Name: void Shader_AddSurfaceDynamic(class CMeshBuilder __near &,struct msurface2_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Shader_AddSurfaceDynamic(CMeshBuilder *meshBuilder, msurface2_t *surfID)
{
  worldbrushdata_t *worldbrush; // edi
  CIndexBuilder *p_m_IndexBuilder; // ecx
  unsigned __int16 firstPrimID; // ax
  int v6; // eax
  int startVert; // [esp+14h] [ebp+8h]

  worldbrush = host_state.worldbrush;
  startVert = meshBuilder->m_VertexBuilder.m_nVertexCount;
  BuildMSurfaceVertexArrays(pBrushData: host_state.worldbrush, surfID, builder: meshBuilder);
  p_m_IndexBuilder = &meshBuilder->m_IndexBuilder;
  if ( (surfID->flags & 0x8000) != 0 )
  {
    if ( (surfID->flags & 0x800) != 0 )
      firstPrimID = 0;
    else
      firstPrimID = worldbrush->surfaces1[surfID - worldbrush->surfaces2].prims.firstPrimID;
    v6 = (int)&worldbrush->primitives[firstPrimID];
    CIndexBuilder::FastIndexList(
      this: p_m_IndexBuilder,
      pIndexList: (char *)&worldbrush->primindices[*(unsigned __int16 *)(v6 + 4)],
      startVert,
      indexCount: *(unsigned __int16 *)(v6 + 6));
  }
  else
  {
    CIndexBuilder::FastPolygon(this: p_m_IndexBuilder, startVert, triangleCount: HIBYTE(surfID->flags) - 2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D0030
// Name: DrawSurfaceMaterial
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawSurfaceMaterial(
        IMatRenderContext *pRenderContext,
        msurface2_t *surfID,
        IMatRenderContext *vecCentroid)
{
  mtexinfo_t *v3; // eax
  unsigned __int8 *v4; // esi
  unsigned int v5; // eax
  unsigned int v6; // edi
  unsigned int v7; // eax
  char *v8; // eax

  v3 = &host_state.worldbrush->texinfo[*((unsigned __int16 *)surfID + 11) >> 1];
  if ( v3->material != nullptr )
    v4 = (unsigned __int8 *)v3->material->GetName(this: v3->material);
  else
    v4 = "no material";
  strrchr(string: v4, chr: 0x2Fu);
  v6 = v5;
  strrchr(string: v4, chr: 0x5Cu);
  if ( v6 > v7 )
    v7 = v6;
  if ( v7 != 0 )
    v8 = (char *)(v7 + 1);
  else
    v8 = (char *)v4;
  CDebugOverlay::AddTextOverlay(textPos: (const Vector *)vecCentroid, duration: 0.0, text: v8);
}

//------------------------------------------------------------------------------
// Address: 0x100D00B0
// Name: void Shader_DrawSurfaceDebuggingInfo(class IMatRenderContext __near *,struct msurface2_t __near * __near *,int,void (*)(class IMatRenderContext __near *,struct msurface2_t __near *,class Vector const __near &))
// Source: json
//------------------------------------------------------------------------------
void __usercall Shader_DrawSurfaceDebuggingInfo(
        int a1@<ebp>,
        IMatRenderContext *pRenderContext,
        msurface2_t **pList,
        int listCount,
        void (__cdecl *func)(IMatRenderContext *, msurface2_t *, const Vector *))
{
  float v5; // ecx
  msurface2_t *v6; // edi
  unsigned __int8 flags_high; // al
  unsigned __int16 *vertindices; // edx
  int firstvertindex; // ecx
  mvertex_t *v10; // eax
  float y; // edx
  float v12; // xmm6_4
  float v13; // xmm7_4
  float v14; // xmm4_4
  int v15; // ecx
  unsigned __int16 *v16; // ecx
  mvertex_t *vertexes; // edx
  float *p_x; // eax
  float v19; // edi
  float *v20; // eax
  float v21; // xmm5_4
  float v22; // xmm4_4
  float v23; // xmm2_4
  float v24; // xmm0_4
  float v25; // xmm4_4
  float v26; // xmm1_4
  float v27; // xmm5_4
  float v28; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm2_4
  bool v31; // zf
  float v32; // edi
  float v33; // [esp-4Ch] [ebp-6Ch]
  float v34; // [esp-2Ch] [ebp-4Ch]
  float v35; // [esp-28h] [ebp-48h]
  float v36; // [esp-24h] [ebp-44h]
  float v37; // [esp-1Ch] [ebp-3Ch]
  float x; // [esp-18h] [ebp-38h]
  float v39; // [esp-14h] [ebp-34h]
  float z; // [esp-10h] [ebp-30h]
  float v41; // [esp-Ch] [ebp-2Ch] BYREF
  float v42; // [esp-8h] [ebp-28h]
  float v43; // [esp-4h] [ebp-24h]
  Vector vecCentroid; // [esp+0h] [ebp-20h]
  int i; // [esp+Ch] [ebp-14h]
  msurface2_t *surfID; // [esp+10h] [ebp-10h]
  int v47; // [esp+14h] [ebp-Ch]
  void *v48; // [esp+18h] [ebp-8h]
  void *retaddr; // [esp+20h] [ebp+0h]

  v47 = a1;
  v48 = retaddr;
  v5 = 0.0;
  vecCentroid.x = 0.0;
  if ( listCount > 0 )
  {
    do
    {
      v6 = pList[LODWORD(v5)];
      flags_high = HIBYTE(v6->flags);
      LODWORD(vecCentroid.y) = v6;
      if ( flags_high >= 3u )
      {
        v41 = 0.0;
        v42 = 0.0;
        v43 = 0.0;
        vertindices = host_state.worldbrush->vertindices;
        LODWORD(vecCentroid.z) = flags_high;
        firstvertindex = v6->firstvertindex;
        v10 = &host_state.worldbrush->vertexes[vertindices[firstvertindex]];
        x = v10->position.x;
        y = v10->position.y;
        z = v10->position.z;
        *(float *)&surfID = 0.0;
        v39 = y;
        v12 = z;
        v13 = y;
        v14 = x;
        v15 = 2 * firstvertindex + 2;
        i = v15;
        LODWORD(vecCentroid.z) -= 2;
        do
        {
          v16 = (unsigned __int16 *)((char *)host_state.worldbrush->vertindices + v15);
          vertexes = host_state.worldbrush->vertexes;
          p_x = &vertexes[*v16].position.x;
          v36 = *p_x;
          v19 = p_x[1];
          v37 = p_x[2];
          v20 = &vertexes[v16[1]].position.x;
          v21 = v36 - v14;
          v34 = v20[1];
          v35 = v20[2];
          v22 = (float)(v34 - v19) * (float)(v37 - v12);
          v23 = (float)(v37 - v12) * (float)(*v20 - v36);
          v12 = z;
          v24 = (float)((float)(v19 - v13) * (float)(*v20 - v36)) - (float)((float)(v34 - v19) * v21);
          v25 = v22 - (float)((float)(v35 - v37) * (float)(v19 - v13));
          v13 = v39;
          v26 = (float)((float)((float)((float)((float)(v35 - v37) * v21) - v23)
                              * (float)((float)((float)(v35 - v37) * v21) - v23))
                      + (float)(v24 * v24))
              + (float)(v25 * v25);
          v14 = x;
          v33 = fsqrt(v26);
          v27 = v33 + *(float *)&surfID;
          v28 = (float)((float)((float)((float)(x + v36) + *v20) * v33) * 0.33333334) + v41;
          v29 = (float)((float)((float)((float)(v39 + v19) + v34) * v33) * 0.33333334) + v42;
          v30 = (float)((float)((float)((float)(z + v37) + v35) * v33) * 0.33333334) + v43;
          *(float *)&surfID = v33 + *(float *)&surfID;
          v41 = v28;
          v42 = v29;
          v43 = v30;
          v15 = i + 2;
          v31 = LODWORD(vecCentroid.z)-- == 1;
          i += 2;
        }
        while ( !v31 );
        v32 = vecCentroid.y;
        if ( v27 != 0.0 )
        {
          v41 = v28 * (float)(1.0 / v27);
          v42 = (float)(1.0 / v27) * v29;
          v43 = (float)(1.0 / v27) * v30;
        }
        VectorTransform(in1: &v41, in2: (const matrix3x4_t *)&g_BrushToWorldMatrix, out: &v41);
        func(a1: pRenderContext, a2: (msurface2_t *)LODWORD(v32), a3: (const Vector *)&v41);
        v5 = vecCentroid.x;
      }
      ++LODWORD(v5);
      vecCentroid.x = v5;
    }
    while ( SLODWORD(v5) < listCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D0340
// Name: ComputeFogVolumeInfo
// Source: json
//------------------------------------------------------------------------------
void __usercall ComputeFogVolumeInfo(FogVolumeInfo_t *pFogVolume@<edi>)
{
  int v1; // eax
  mleaf_t *v2; // eax
  int leafWaterDataID; // ecx
  mleafwaterdata_t *v4; // ebx
  __int16 surfaceTexInfoID; // ax
  IMaterial *material; // esi
  int v7; // esi
  double minZ; // st7
  IMaterialVar *pFogStartVar; // [esp+0h] [ebp-Ch]
  IMaterialVar *pFogColorVar; // [esp+4h] [ebp-8h]
  IMaterialVar *pFogEnableVar; // [esp+8h] [ebp-4h]

  pFogVolume->m_InFogVolume = false;
  v1 = CM_PointLeafnum(p: &g_CurrentViewOrigin);
  if ( v1 >= 0 && v1 < host_state.worldbrush->numleafs )
  {
    v2 = &host_state.worldbrush->leafs[v1];
    leafWaterDataID = v2->leafWaterDataID;
    pFogVolume->m_FogVolumeID = leafWaterDataID;
    if ( leafWaterDataID != -1 )
    {
      pFogVolume->m_InFogVolume = true;
      v4 = &host_state.worldbrush->leafwaterdata[v2->leafWaterDataID];
      surfaceTexInfoID = v4->surfaceTexInfoID;
      if ( surfaceTexInfoID == -1 )
      {
        pFogVolume->m_FogEnabled = false;
      }
      else
      {
        material = host_state.worldbrush->texinfo[surfaceTexInfoID].material;
        if ( material != nullptr )
        {
          pFogColorVar = material->FindVar(this: material, a2: &args.m_pArgSBuffer[368], a3: nullptr, a4: true);
          pFogEnableVar = material->FindVar(this: material, a2: &args.m_pArgSBuffer[356], a3: nullptr, a4: true);
          pFogStartVar = material->FindVar(this: material, a2: &args.m_pArgSBuffer[344], a3: nullptr, a4: true);
          v7 = (int)material->FindVar(this: material, a2: &args.m_pArgSBuffer[336], a3: nullptr, a4: true);
          pFogVolume->m_FogEnabled = pFogEnableVar->GetIntValueInternal(this: pFogEnableVar) != 0;
          pFogColorVar->GetVecValueInternal(this: pFogColorVar, a2: pFogVolume->m_FogColor, a3: 3);
          pFogVolume->m_FogStart = -((double (__thiscall *)(IMaterialVar *))pFogStartVar->GetFloatValueInternal)(a1: pFogStartVar);
          pFogVolume->m_FogEnd = -((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v7 + 112))(a1: v7);
          pFogVolume->m_FogSurfaceZ = v4->surfaceZ;
          minZ = v4->minZ;
          pFogVolume->m_FogMode = MATERIAL_FOG_LINEAR;
          pFogVolume->m_FogMinZ = minZ;
        }
        else
        {
          if ( !bComplained )
          {
            _Warning(a1: &args.m_pArgSBuffer[268]);
            bComplained = true;
          }
          pFogVolume->m_FogEnabled = false;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D04A0
// Name: void Shader_GetSurfVertexAndIndexCount(struct msurface2_t __near *,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Shader_GetSurfVertexAndIndexCount(msurface2_t *surfaceHandle, int *pVertexCount, int *pIndexCount)
{
  unsigned __int16 firstPrimID; // ax
  mprimitive_t *primitives; // edx
  int v5; // eax
  bool v6; // zf
  mprimitive_t *v7; // eax
  int flags_high; // eax

  *pIndexCount = 0;
  *pVertexCount = 0;
  if ( (surfaceHandle->flags & 0x8000) != 0 )
  {
    if ( (surfaceHandle->flags & 0x800) != 0 )
      firstPrimID = 0;
    else
      firstPrimID = host_state.worldbrush->surfaces1[surfaceHandle - host_state.worldbrush->surfaces2].prims.firstPrimID;
    primitives = host_state.worldbrush->primitives;
    v5 = firstPrimID;
    v6 = primitives[v5].vertCount == 0;
    v7 = &primitives[v5];
    if ( v6 )
    {
      *pVertexCount = HIBYTE(surfaceHandle->flags);
      *pIndexCount = v7->indexCount;
    }
  }
  else
  {
    flags_high = HIBYTE(surfaceHandle->flags);
    *pVertexCount = flags_high;
    *pIndexCount = 3 * flags_high - 6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D0530
// Name: public: void CVisibleFogVolumeQuery::FindVisibleFogVolume(class Vector const __near &,struct VisOverrideData_t const __near *,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVisibleFogVolumeQuery::FindVisibleFogVolume(
        CVisibleFogVolumeQuery *this,
        const Vector *vecViewPoint,
        const VisOverrideData_t *pVisOverrideData,
        int *pVisibleFogVolume,
        int *pVisibleFogVolumeLeaf)
{
  double z; // st7

  R_SetupAreaBits(iForceViewLeaf: -1, pVisData: pVisOverrideData, pWaterReflectionHeight: nullptr);
  this->m_vecSearchPoint.x = vecViewPoint->x;
  this->m_vecSearchPoint.y = vecViewPoint->y;
  z = vecViewPoint->z;
  this->m_nVisibleFogVolume = -1;
  this->m_vecSearchPoint.z = z;
  this->m_nVisibleFogVolumeLeaf = -1;
  CVisibleFogVolumeQuery::RecursiveGetVisibleFogVolume(this, node: host_state.worldbrush->nodes);
  *pVisibleFogVolume = this->m_nVisibleFogVolume;
  *pVisibleFogVolumeLeaf = this->m_nVisibleFogVolumeLeaf;
}

//------------------------------------------------------------------------------
// Address: 0x100D0590
// Name: void R_GetVisibleFogVolume(class Vector const __near &,struct VisOverrideData_t const __near *,struct VisibleFogVolumeInfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_GetVisibleFogVolume(
        const Vector *vEyePoint,
        const VisOverrideData_t *pVisOverrideData,
        VisibleFogVolumeInfo_t *pInfo)
{
  int v3; // ebx
  mleaf_t *v4; // eax
  VisibleFogVolumeInfo_t *v5; // esi
  int v6; // eax
  float surfaceZ; // xmm0_4
  int m_nVisibleFogVolume; // eax
  IMaterial *material; // ecx
  unsigned __int16 *m_LeafMinDistToWater; // eax
  float v11; // xmm0_4
  int leafWaterDataID; // [esp-14h] [ebp-28h]
  CVisibleFogVolumeQuery query; // [esp+0h] [ebp-14h] BYREF

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: &args.m_pArgSBuffer[380],
    a3: 0,
    a4: &args.m_pArgSBuffer[404],
    a5: false,
    a6: 4);
  if ( *(_DWORD *)(host_state.worldmodel->sprite.numframes + 24) == 0 )
  {
    pInfo->m_bEyeInFogVolume = false;
    pInfo->m_nVisibleFogVolume = -1;
    pInfo->m_nVisibleFogVolumeLeaf = -1;
    *(_QWORD *)&pInfo->m_flWaterHeight = 1232348160;
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return;
  }
  v3 = CM_PointLeafnum(p: vEyePoint);
  v4 = &host_state.worldbrush->leafs[v3];
  if ( v4->leafWaterDataID == -1 )
  {
    if ( (v4->contents & 0x100) != 0 )
    {
      if ( fast_fogvolume.m_pParent != nullptr
        && fast_fogvolume.m_pParent->m_Value.m_nValue != 0
        && host_state.worldbrush->numleafwaterdata == 1 )
      {
        v5 = pInfo;
        pInfo->m_nVisibleFogVolume = 0;
        pInfo->m_nVisibleFogVolumeLeaf = host_state.worldbrush->leafwaterdata->firstLeafIndex;
      }
      else
      {
        v5 = pInfo;
        CVisibleFogVolumeQuery::FindVisibleFogVolume(
          this: &query,
          vecViewPoint: vEyePoint,
          pVisOverrideData,
          pVisibleFogVolume: &pInfo->m_nVisibleFogVolume,
          pVisibleFogVolumeLeaf: &pInfo->m_nVisibleFogVolumeLeaf);
      }
      m_nVisibleFogVolume = v5->m_nVisibleFogVolume;
      v5->m_bEyeInFogVolume = false;
      if ( m_nVisibleFogVolume < 0 || m_nVisibleFogVolume > host_state.worldbrush->numleafwaterdata )
        material = nullptr;
      else
        material = host_state.worldbrush->texinfo[host_state.worldbrush->leafwaterdata[m_nVisibleFogVolume].surfaceTexInfoID].material;
      v5->m_pFogVolumeMaterial = material;
      if ( m_nVisibleFogVolume >= 0 && m_nVisibleFogVolume <= host_state.worldbrush->numleafwaterdata )
      {
        surfaceZ = host_state.worldbrush->leafwaterdata[m_nVisibleFogVolume].surfaceZ;
        goto LABEL_22;
      }
    }
    else
    {
      v5 = pInfo;
      pInfo->m_bEyeInFogVolume = false;
      pInfo->m_nVisibleFogVolume = -1;
      pInfo->m_nVisibleFogVolumeLeaf = -1;
      pInfo->m_pFogVolumeMaterial = nullptr;
    }
LABEL_21:
    surfaceZ = 1000000.0;
    goto LABEL_22;
  }
  v5 = pInfo;
  pInfo->m_bEyeInFogVolume = true;
  leafWaterDataID = v4->leafWaterDataID;
  pInfo->m_nVisibleFogVolume = leafWaterDataID;
  pInfo->m_nVisibleFogVolumeLeaf = v3;
  pInfo->m_pFogVolumeMaterial = R_GetFogVolumeMaterial(nFogVolume: leafWaterDataID, bEyeInFogVolume: true);
  v6 = pInfo->m_nVisibleFogVolume;
  if ( pInfo->m_nVisibleFogVolume < 0 || v6 > host_state.worldbrush->numleafwaterdata )
    goto LABEL_21;
  surfaceZ = host_state.worldbrush->leafwaterdata[v6].surfaceZ;
LABEL_22:
  v5->m_flWaterHeight = surfaceZ;
  m_LeafMinDistToWater = host_state.worldbrush->m_LeafMinDistToWater;
  if ( m_LeafMinDistToWater != nullptr )
    v11 = (float)m_LeafMinDistToWater[v3];
  else
    v11 = 0.0;
  v5->m_flDistanceToWater = v11;
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x100D0760
// Name: public: virtual int CBrushSurface::GetVertexCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBrushSurface::GetVertexCount(CBrushSurface *this)
{
  msurface2_t *m_SurfaceID; // eax

  m_SurfaceID = this->m_SurfaceID;
  if ( (m_SurfaceID->flags & 0x8000) != 0 )
    return 0;
  else
    return HIBYTE(m_SurfaceID->flags);
}

//------------------------------------------------------------------------------
// Address: 0x100D0780
// Name: public: virtual void CBrushSurface::GetVertexData(struct BrushVertex_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBrushSurface::GetVertexData(CBrushSurface *this, BrushVertex_t *pVerts)
{
  msurface2_t *m_SurfaceID; // eax

  m_SurfaceID = this->m_SurfaceID;
  if ( (m_SurfaceID->flags & 0x8000) == 0 )
    BuildBrushModelVertexArray(pBrushData: host_state.worldbrush, surfID: m_SurfaceID, pVerts);
}

//------------------------------------------------------------------------------
// Address: 0x100D07B0
// Name: public: virtual class IMaterial __near * CBrushSurface::GetMaterial(void)
// Source: json
//------------------------------------------------------------------------------
IMaterial *__thiscall CBrushSurface::GetMaterial(CBrushSurface *this)
{
  return host_state.worldbrush->texinfo[*((unsigned __int16 *)this->m_SurfaceID + 11) >> 1].material;
}

//------------------------------------------------------------------------------
// Address: 0x100D07D0
// Name: ListLeafsInBox
// Source: json
//------------------------------------------------------------------------------
int __cdecl ListLeafsInBox(const Vector *center, const Vector *extents, unsigned __int16 *pList, int listMax)
{
  mnode_t *node; // ecx
  int result; // eax
  int v6; // edi
  int v7; // esi
  cplane_t *plane; // edx
  float x; // xmm2_4
  float y; // xmm0_4
  float z; // xmm3_4
  float v12; // xmm0_4
  double v13; // st7
  mnode_t *v14; // edx
  _DWORD v15[1025]; // [esp+0h] [ebp-1010h]
  float v16; // [esp+1004h] [ebp-Ch]
  float v17; // [esp+1008h] [ebp-8h]
  float v18; // [esp+100Ch] [ebp-4h]

  result = 0;
  v6 = 0;
  v7 = 0;
  while ( 1 )
  {
    while ( node->contents < 0 )
    {
      plane = node->plane;
      x = plane->normal.x;
      y = center->y;
      z = plane->normal.z;
      v17 = plane->normal.y;
      v12 = (float)((float)((float)(y * v17) + (float)(center->x * x)) + (float)(center->z * z)) - plane->dist;
      v13 = extents->y;
      *(float *)&v15[1024] = x;
      v18 = z;
      v16 = fabs(v13 * v17) + fabs(extents->x * x) + fabs(extents->z * z);
      if ( v12 < v16 )
      {
        if ( (float)-v16 <= v12 )
        {
          v14 = node->children[0];
          node = node->children[1];
          v15[v7] = v14;
          v7 = ((_WORD)v7 + 1) & 0x3FF;
        }
        else
        {
          node = node->children[1];
        }
      }
      else
      {
        node = node->children[0];
      }
    }
    if ( node->contents != 1 && result < listMax )
      pList[result++] = ((char *)node - (char *)host_state.worldbrush->leafs) >> 6;
    if ( v6 == v7 )
      break;
    node = (mnode_t *)v15[v6];
    v6 = ((_WORD)v6 + 1) & 0x3FF;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D08E0
// Name: EnumerateLeavesAlongExtrudedRay_R
// Source: json
//------------------------------------------------------------------------------
bool __cdecl EnumerateLeavesAlongExtrudedRay_R(
        mnode_t *node,
        const Ray_t *ray,
        float start,
        float end,
        ISpatialLeafEnumerator *pEnum,
        const Ray_t *context)
{
  mnode_t *v6; // esi
  int contents; // eax
  long double v8; // st7
  double v9; // st6
  double v10; // st5
  float v11; // xmm5_4
  cplane_t *plane; // eax
  int type; // ecx
  float v14; // xmm3_4
  float v15; // xmm2_4
  float v16; // xmm0_4
  long double v17; // st4
  double x; // st4
  float v19; // xmm2_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm0_4
  double v23; // st7
  float v24; // xmm3_4
  double v25; // st3
  long double v26; // st2
  int v27; // ebx
  long double v28; // st7
  long double v29; // st6
  long double v30; // st6
  double v31; // st7
  float v32; // xmm1_4
  float v34; // [esp+0h] [ebp-38h]
  float v35; // [esp+0h] [ebp-38h]
  int v36; // [esp+20h] [ebp-18h] BYREF
  float v37; // [esp+24h] [ebp-14h]
  float v38; // [esp+28h] [ebp-10h]
  float v39; // [esp+2Ch] [ebp-Ch]
  int minVal; // [esp+30h] [ebp-8h] BYREF
  float t2; // [esp+34h] [ebp-4h] BYREF
  float frac; // [esp+40h] [ebp+8h]

  v6 = node;
  contents = node->contents;
  if ( node->contents == 1 )
    return true;
  v8 = 0.03125;
  v9 = 1.0;
  v10 = start;
  v11 = start;
  while ( 1 )
  {
    if ( contents >= 0 )
      return pEnum->EnumerateLeaf(
               this: pEnum,
               a2: ((char *)v6 - (char *)host_state.worldbrush->leafs) >> 6,
               a3: (int)context);
    plane = v6->plane;
    if ( plane->type > 2u )
    {
      x = ray->m_Extents.x;
      v19 = ray->m_Start.y * plane->normal.y;
      v20 = ray->m_Start.x;
      v39 = plane->normal.x;
      v15 = (float)(v19 + (float)(v20 * v39)) + (float)(ray->m_Start.z * plane->normal.z);
      v16 = (float)((float)(ray->m_Delta.y * plane->normal.y) + (float)(v39 * ray->m_Delta.x))
          + (float)(ray->m_Delta.z * plane->normal.z);
      v17 = fabs(x * v39) + fabs(ray->m_Extents.y * plane->normal.y) + fabs(ray->m_Extents.z * plane->normal.z) + v8;
      frac = v17;
      v14 = frac;
    }
    else
    {
      type = plane->type;
      v14 = *(&ray->m_Extents.x + type) + 0.03125;
      v15 = *(&ray->m_Start.x + type);
      v16 = *(&ray->m_Delta.x + type);
      v17 = v14;
    }
    v21 = (float)((float)(v16 * v11) + v15) - plane->dist;
    v22 = (float)((float)(v16 * end) + v15) - plane->dist;
    v38 = v21;
    v37 = v22;
    if ( v21 > v14 && v22 > v14 )
    {
      v6 = v6->children[0];
      v23 = v10;
      goto LABEL_29;
    }
    LODWORD(v24) = LODWORD(v14) ^ _mask__NegFloat_;
    if ( v24 > v21 && v24 > v22 )
    {
      v6 = v6->children[1];
      v23 = v10;
      goto LABEL_29;
    }
    v25 = v38;
    v26 = v38 - v37;
    if ( v8 > fabs(v26) )
    {
      v34 = v10;
      if ( !EnumerateLeavesAlongExtrudedRay_R(node: v6->children[0], ray, start: v34, end, pEnum, (int)context) )
        return false;
      v6 = v6->children[1];
      v23 = start;
      goto LABEL_28;
    }
    if ( v22 <= v21 )
    {
      v27 = 0;
      if ( v21 <= v22 )
      {
        v32 = 1.0;
        t2 = 0.0;
        v31 = v10;
        goto LABEL_26;
      }
      v28 = v9 / v26;
      t2 = (v25 - v17) * (v9 / v26);
      v29 = v38 + v17;
    }
    else
    {
      v27 = 1;
      v28 = v9 / v26;
      t2 = (v25 + v17) * (v9 / v26);
      v29 = v38 - v17;
    }
    v30 = v28 * v29;
    v31 = v10;
    *(float *)&minVal = v30;
    v32 = *(float *)&minVal;
    if ( *(float *)&minVal >= 0.0 )
    {
      if ( *(float *)&minVal > 1.0 )
        v32 = 1.0;
    }
    else
    {
      v32 = 0.0;
    }
LABEL_26:
    v35 = v31;
    if ( !EnumerateLeavesAlongExtrudedRay_R(
            node: v6->children[v27],
            ray,
            start: v35,
            end: (float)((float)(end - v11) * v32) + v11,
            pEnum,
            (int)context) )
      return false;
    minVal = 1;
    v36 = 0;
    v23 = clamp<float,int,int>(val: &t2, minVal: &v36, maxVal: &minVal) * (float)(end - v11) + start;
    start = v23;
    v6 = v6->children[v27 == 0];
LABEL_28:
    v11 = start;
LABEL_29:
    contents = v6->contents;
    if ( v6->contents == 1 )
      return true;
    v9 = 1.0;
    v10 = v23;
    v8 = 0.03125;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D0BB0
// Name: public: virtual int CEngineBSPTree::ListLeavesInBox(class Vector const __near &,class Vector const __near &,unsigned short __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineBSPTree::ListLeavesInBox(
        CEngineBSPTree *this,
        const Vector *mins,
        const Vector *maxs,
        unsigned __int16 *pList,
        int listMax)
{
  float x; // xmm3_4
  float y; // xmm4_4
  float z; // xmm5_4
  mnode_t *nodes; // ecx
  float v9; // xmm1_4
  float v10; // xmm2_4
  Vector center; // [esp+0h] [ebp-18h] BYREF
  Vector extents; // [esp+Ch] [ebp-Ch] BYREF

  x = maxs->x;
  y = maxs->y;
  z = maxs->z;
  nodes = host_state.worldbrush->nodes;
  v9 = (float)(mins->y + y) * 0.5;
  v10 = (float)(mins->z + z) * 0.5;
  center.x = (float)(mins->x + maxs->x) * 0.5;
  center.y = v9;
  center.z = v10;
  extents.x = x - center.x;
  extents.y = y - v9;
  extents.z = z - v10;
  return ListLeafsInBox(node: nodes, &center, &extents, pList, listMax);
}

//------------------------------------------------------------------------------
// Address: 0x100D0C50
// Name: public: virtual bool CEngineBSPTree::EnumerateLeavesAlongRay(struct Ray_t const __near &,class ISpatialLeafEnumerator __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineBSPTree::EnumerateLeavesAlongRay(
        CEngineBSPTree *this,
        const Ray_t *ray,
        ISpatialLeafEnumerator *pEnum,
        int context)
{
  float y; // xmm2_4
  float z; // xmm6_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm6_4
  float v12; // xmm2_4
  bool (__thiscall *EnumerateLeavesInBox)(struct CEngineBSPTree *, const Vector *, const Vector *, ISpatialLeafEnumerator *, int); // eax
  float start[3]; // [esp+10h] [ebp-18h] BYREF
  float v16; // [esp+1Ch] [ebp-Ch] BYREF
  Vector mins; // [esp+20h] [ebp-8h]

  if ( ray->m_IsSwept )
  {
    if ( ray->m_IsRay )
      return EnumerateLeavesAlongRay_R(node: host_state.worldbrush->nodes, ray, start: 0.0, end: 1.0, pEnum, context);
    else
      return EnumerateLeavesAlongExtrudedRay_R(
               node: host_state.worldbrush->nodes,
               ray,
               start: 0.0,
               end: 1.0,
               pEnum,
               context);
  }
  else
  {
    y = ray->m_Extents.y;
    z = ray->m_Extents.z;
    v6 = ray->m_Start.x - ray->m_Extents.x;
    v16 = ray->m_Extents.x + ray->m_Start.x;
    v7 = ray->m_Start.y;
    v8 = y + v7;
    v9 = v7 - ray->m_Extents.y;
    mins.x = v8;
    v10 = ray->m_Start.z;
    v11 = z + v10;
    v12 = v10 - ray->m_Extents.z;
    EnumerateLeavesInBox = this->EnumerateLeavesInBox;
    mins.y = v11;
    start[0] = v6;
    start[1] = v9;
    start[2] = v12;
    return EnumerateLeavesInBox(this, a2: (const Vector *)start, a3: (const Vector *)&v16, a4: pEnum, a5: context);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D0D40
// Name: bool EnumerateLeafInSphere_R<0>(struct mnode_t __near *,struct EnumLeafSphereInfo_t __near &,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl EnumerateLeafInSphere_R<0>(mnode_t *node, EnumLeafSphereInfo_t *info, int nTestFlags)
{
  mnode_t *v3; // esi
  int contents; // eax
  float x; // xmm0_4
  float y; // xmm0_4
  float z; // xmm0_4
  cplane_t *plane; // eax
  unsigned __int8 type; // cl
  float v11; // xmm0_4
  float dist; // xmm2_4
  float v14; // [esp+18h] [ebp+8h]
  float v15; // [esp+18h] [ebp+8h]
  float v16; // [esp+18h] [ebp+8h]

  v3 = node;
  contents = node->contents;
  if ( node->contents != 1 )
  {
    while ( 1 )
    {
      if ( contents >= 0 )
      {
        if ( nTestFlags == 0
          || IsBoxIntersectingSphereExtents(
               boxCenter: &v3->m_vecCenter,
               boxHalfDiag: &v3->m_vecHalfDiagonal,
               center: &info->m_vecCenter,
               radius: info->m_flRadius) )
        {
          return info->m_pIterator->EnumerateLeaf(
                   this: info->m_pIterator,
                   a2: ((char *)v3 - (char *)host_state.worldbrush->leafs) >> 6,
                   a3: info->m_nContext);
        }
        return true;
      }
      if ( nTestFlags != 0 )
      {
        if ( contents == -1 )
        {
          if ( (nTestFlags & 0x10000000) != 0 )
          {
            x = v3->m_vecHalfDiagonal.x;
            v14 = fabs(v3->m_vecCenter.x - info->m_vecBoxCenter.x);
            if ( v14 > (float)(info->m_vecBoxHalfDiagonal.x + x) )
              return true;
            if ( info->m_vecBoxHalfDiagonal.x > (float)(x + v14) )
              nTestFlags &= ~0x10000000u;
          }
          if ( (nTestFlags & 0x20000000) != 0 )
          {
            y = v3->m_vecHalfDiagonal.y;
            v15 = fabs(v3->m_vecCenter.y - info->m_vecBoxCenter.y);
            if ( v15 > (float)(info->m_vecBoxHalfDiagonal.y + y) )
              return true;
            if ( info->m_vecBoxHalfDiagonal.y > (float)(y + v15) )
              nTestFlags &= ~0x20000000u;
          }
          if ( (nTestFlags & 0x40000000) != 0 )
          {
            z = v3->m_vecHalfDiagonal.z;
            v16 = fabs(v3->m_vecCenter.z - info->m_vecBoxCenter.z);
            if ( v16 > (float)(info->m_vecBoxHalfDiagonal.z + z) )
              return true;
            if ( info->m_vecBoxHalfDiagonal.z > (float)(z + v16) )
              nTestFlags &= ~0x40000000u;
          }
        }
        else if ( contents == -2 )
        {
          nTestFlags &= 0x8FFFFFFF;
        }
      }
      plane = v3->plane;
      type = plane->type;
      if ( type > 2u )
        v11 = (float)((float)(plane->normal.y * info->m_vecCenter.y) + (float)(plane->normal.x * info->m_vecCenter.x))
            + (float)(plane->normal.z * info->m_vecCenter.z);
      else
        v11 = *(&info->m_vecCenter.x + type);
      dist = plane->dist;
      if ( dist >= (float)(info->m_flRadius + v11) )
        goto LABEL_26;
      if ( (float)(v11 - info->m_flRadius) < dist )
        break;
      v3 = v3->children[0];
LABEL_27:
      contents = v3->contents;
      if ( v3->contents == 1 )
        return true;
    }
    if ( !EnumerateLeafInSphere_R<0>(node: v3->children[0], info, nTestFlags) )
      return false;
LABEL_26:
    v3 = v3->children[1];
    goto LABEL_27;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x100D0F20
// Name: bool EnumerateLeafInSphere_R<1>(struct mnode_t __near *,struct EnumLeafSphereInfo_t __near &,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl EnumerateLeafInSphere_R<1>(mnode_t *node, EnumLeafSphereInfo_t *info, int nTestFlags)
{
  mnode_t *v3; // esi
  int contents; // eax
  float x; // xmm0_4
  float y; // xmm0_4
  float z; // xmm0_4
  cplane_t *plane; // eax
  unsigned __int8 type; // cl
  float v11; // xmm0_4
  float dist; // xmm2_4
  float v14; // [esp+18h] [ebp+8h]
  float v15; // [esp+18h] [ebp+8h]
  float v16; // [esp+18h] [ebp+8h]

  v3 = node;
  contents = node->contents;
  if ( node->contents != 1 )
  {
    while ( 1 )
    {
      if ( contents >= 0 )
      {
        if ( nTestFlags == 0
          || IsBoxIntersectingSphereExtents(
               boxCenter: &v3->m_vecCenter,
               boxHalfDiag: &v3->m_vecHalfDiagonal,
               center: &info->m_vecCenter,
               radius: info->m_flRadius) )
        {
          return info->m_pIterator->EnumerateLeaf(
                   this: info->m_pIterator,
                   a2: ((char *)v3 - (char *)host_state.worldbrush->leafs) >> 6,
                   a3: info->m_nContext);
        }
        return true;
      }
      if ( nTestFlags != 0 )
      {
        if ( contents == -1 )
        {
          if ( (v3->flags & nTestFlags) == 0 )
            return true;
          if ( (nTestFlags & 0x10000000) != 0 )
          {
            x = v3->m_vecHalfDiagonal.x;
            v14 = fabs(v3->m_vecCenter.x - info->m_vecBoxCenter.x);
            if ( v14 > (float)(info->m_vecBoxHalfDiagonal.x + x) )
              return true;
            if ( info->m_vecBoxHalfDiagonal.x > (float)(x + v14) )
              nTestFlags &= ~0x10000000u;
          }
          if ( (nTestFlags & 0x20000000) != 0 )
          {
            y = v3->m_vecHalfDiagonal.y;
            v15 = fabs(v3->m_vecCenter.y - info->m_vecBoxCenter.y);
            if ( v15 > (float)(info->m_vecBoxHalfDiagonal.y + y) )
              return true;
            if ( info->m_vecBoxHalfDiagonal.y > (float)(y + v15) )
              nTestFlags &= ~0x20000000u;
          }
          if ( (nTestFlags & 0x40000000) != 0 )
          {
            z = v3->m_vecHalfDiagonal.z;
            v16 = fabs(v3->m_vecCenter.z - info->m_vecBoxCenter.z);
            if ( v16 > (float)(info->m_vecBoxHalfDiagonal.z + z) )
              return true;
            if ( info->m_vecBoxHalfDiagonal.z > (float)(z + v16) )
              nTestFlags &= ~0x40000000u;
          }
        }
        else if ( contents == -2 )
        {
          nTestFlags &= 0x8FFFFFFF;
        }
      }
      plane = v3->plane;
      type = plane->type;
      if ( type > 2u )
        v11 = (float)((float)(plane->normal.y * info->m_vecCenter.y) + (float)(plane->normal.x * info->m_vecCenter.x))
            + (float)(plane->normal.z * info->m_vecCenter.z);
      else
        v11 = *(&info->m_vecCenter.x + type);
      dist = plane->dist;
      if ( dist >= (float)(info->m_flRadius + v11) )
        goto LABEL_27;
      if ( (float)(v11 - info->m_flRadius) < dist )
        break;
      v3 = v3->children[0];
LABEL_28:
      contents = v3->contents;
      if ( v3->contents == 1 )
        return true;
    }
    if ( !EnumerateLeafInSphere_R<1>(node: v3->children[0], info, nTestFlags) )
      return false;
LABEL_27:
    v3 = v3->children[1];
    goto LABEL_28;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x100D1100
// Name: private: void CVarBitVecBase<unsigned short>::ReallocInts(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVarBitVecBase<unsigned short>::ReallocInts(CVarBitVecBase<unsigned short> *this, int numInts)
{
  CVarBitVecBase<unsigned short> *m_pInt; // eax
  unsigned int *p_m_iBitStringStorage; // edi
  unsigned int *v5; // eax
  unsigned int v6; // ecx

  if ( numInts != 0 )
  {
    m_pInt = (CVarBitVecBase<unsigned short> *)this->m_pInt;
    p_m_iBitStringStorage = &this->m_iBitStringStorage;
    if ( m_pInt == (CVarBitVecBase<unsigned short> *)&this->m_iBitStringStorage )
    {
      if ( numInts != 1 )
      {
        v5 = (unsigned int *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * numInts);
        v6 = *p_m_iBitStringStorage;
        this->m_pInt = v5;
        *v5 = v6;
      }
    }
    else if ( numInts == 1 )
    {
      *p_m_iBitStringStorage = *(_DWORD *)&m_pInt->m_numBits;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pInt);
      this->m_pInt = p_m_iBitStringStorage;
    }
    else
    {
      this->m_pInt = (unsigned int *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pInt, a3: 4 * numInts);
    }
  }
  else
  {
    if ( this->m_numInts > 1u )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pInt);
    this->m_pInt = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D11B0
// Name: void BuildIndicesForWorldSurface(class CIndexBuilder __near &,struct msurface2_t __near *,struct worldbrushdata_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildIndicesForWorldSurface(CIndexBuilder *meshBuilder, msurface2_t *surfID, worldbrushdata_t *pData)
{
  unsigned __int16 firstPrimID; // cx
  mprimitive_t *v4; // ecx

  if ( (surfID->flags & 0x8000) != 0 )
  {
    if ( (surfID->flags & 0x800) != 0 )
      firstPrimID = 0;
    else
      firstPrimID = pData->surfaces1[surfID - pData->surfaces2].prims.firstPrimID;
    v4 = &pData->primitives[firstPrimID];
    CIndexBuilder::FastIndexList(
      this: meshBuilder,
      pIndexList: (char *)&pData->primindices[v4->firstIndex],
      startVert: surfID->vertBufferIndex,
      indexCount: v4->indexCount);
  }
  else
  {
    BuildIndicesForSurface(meshBuilder, surfID);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D1230
// Name: public: void CWorldRenderList::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorldRenderList::Reset(CWorldRenderList *this)
{
  int *p_m_Size; // eax
  int i; // ecx
  unsigned __int8 *m_pInt; // eax

  CMSurfaceSortList::Reset(this: &this->m_SortList);
  this->m_AlphaSurfaces.m_Size = 0;
  CMSurfaceSortList::Reset(this: &this->m_DispSortList);
  *(_WORD *)&this->m_bSkyVisible = 0;
  p_m_Size = &this->m_DlightSurfaces[0].m_Size;
  for ( i = 4; i != 0; --i )
  {
    *(p_m_Size - 20) = 0;
    *p_m_Size = 0;
    p_m_Size[20] = 0;
    p_m_Size += 5;
  }
  this->m_leaves.m_Size = 0;
  m_pInt = (unsigned __int8 *)this->m_VisitedSurfs.m_bits.m_pInt;
  if ( m_pInt != nullptr )
    memset(dst: m_pInt, value: 0, count: 4 * this->m_VisitedSurfs.m_bits.m_numInts);
}

//------------------------------------------------------------------------------
// Address: 0x100D12A0
// Name: public: void CWorldRenderList::CountTranslucentSurfaces(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorldRenderList::CountTranslucentSurfaces(CWorldRenderList *this)
{
  int m_Size; // edi
  int firstTranslucentSurface; // esi
  int i; // eax
  int v4; // edx
  int v5; // eax

  m_Size = this->m_leaves.m_Size;
  if ( m_Size > 0 )
  {
    firstTranslucentSurface = this->m_leaves.m_Memory.m_pMemory->firstTranslucentSurface;
    for ( i = 1; i < m_Size; ++i )
    {
      v4 = this->m_leaves.m_Memory.m_pMemory[i].firstTranslucentSurface - firstTranslucentSurface;
      if ( v4 != 0 )
      {
        this->m_leaves.m_Memory.m_pMemory[i - 1].translucentSurfaceCount = v4;
        firstTranslucentSurface = this->m_leaves.m_Memory.m_pMemory[i].firstTranslucentSurface;
      }
    }
    v5 = this->m_AlphaSurfaces.m_Size;
    if ( this->m_leaves.m_Memory.m_pMemory[m_Size - 1].firstTranslucentSurface != v5 )
      this->m_leaves.m_Memory.m_pMemory[m_Size - 1].translucentSurfaceCount = v5
                                                                            - this->m_leaves.m_Memory.m_pMemory[m_Size - 1].firstTranslucentSurface;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D1320
// Name: void Shader_DrawSurfaceDynamic(class IMatRenderContext __near *,struct msurface2_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Shader_DrawSurfaceDynamic(IMatRenderContext *pRenderContext, msurface2_t *surfID)
{
  msurface2_t *v2; // edi
  IMesh *v3; // esi
  int flags_high; // edi
  int v5; // eax
  unsigned __int16 firstPrimID; // ax
  mprimitive_t *v7; // esi
  IMatRenderContext_vtbl *v8; // edx
  bool v9; // zf
  IMesh *(__thiscall *GetDynamicMesh)(IMatRenderContext *, bool, IMesh *, IMesh *, IMaterial *); // eax
  unsigned __int16 *v11; // esi
  unsigned __int16 v12; // ax
  int v13; // eax
  int v14; // eax
  int v15; // ecx
  unsigned int m_nCurrentIndex; // eax
  int indexCount; // edx
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+Ch] [ebp-1F4h] BYREF
  unsigned __int16 *p_vertCount; // [esp+1F4h] [ebp-Ch]
  IMesh *pMesh; // [esp+1F8h] [ebp-8h]
  int i; // [esp+1FCh] [ebp-4h]
  msurface2_t *surfIDa; // [esp+20Ch] [ebp+Ch]

  v2 = surfID;
  if ( (surfID->flags & 0x8000) != 0 )
  {
    if ( (surfID->flags & 0x800) != 0 )
      firstPrimID = 0;
    else
      firstPrimID = host_state.worldbrush->surfaces1[surfID - host_state.worldbrush->surfaces2].prims.firstPrimID;
    v7 = &host_state.worldbrush->primitives[firstPrimID];
    v8 = pRenderContext->__vftable;
    v9 = v7->vertCount == 0;
    p_vertCount = &v7->vertCount;
    GetDynamicMesh = v8->GetDynamicMesh;
    if ( v9 )
    {
      surfIDa = (msurface2_t *)((int (__stdcall *)(int, _DWORD, _DWORD, _DWORD))GetDynamicMesh)(
                                 a1: 1,
                                 a2: 0,
                                 a3: 0,
                                 a4: 0);
      CMeshBuilder::CMeshBuilder(this: &meshBuilder);
      CMeshBuilder::Begin(
        this: &meshBuilder,
        pMesh: (IMesh *)surfIDa,
        type: MATERIAL_TRIANGLES,
        nVertexCount: HIBYTE(v2->flags),
        nIndexCount: v7->indexCount,
        pMeshSettings: nullptr);
      BuildMSurfaceVertexArrays(pBrushData: host_state.worldbrush, surfID: v2, builder: &meshBuilder);
      v15 = 0;
      if ( v7->indexCount != 0 )
      {
        m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nCurrentIndex;
        do
        {
          meshBuilder.m_IndexBuilder.m_pIndices[m_nCurrentIndex] = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset)
                                                                 + host_state.worldbrush->primindices[v15 + v7->firstIndex];
          m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
          indexCount = v7->indexCount;
          ++v15;
          meshBuilder.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
          meshBuilder.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
        }
        while ( v15 < indexCount );
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
      (*(void (__thiscall **)(msurface2_t *, int, _DWORD))(surfIDa->flags + 48))(a1: surfIDa, a2: -1, a3: 0);
    }
    else
    {
      pMesh = (IMesh *)((int (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))GetDynamicMesh)(a1: 0, a2: 0, a3: 0, a4: 0);
      CMeshBuilder::CMeshBuilder(this: &meshBuilder);
      v11 = p_vertCount;
      i = 0;
      while ( 1 )
      {
        v12 = (v2->flags & 0x800) != 0 || (v2->flags & 0x8000) == 0
            ? 0
            : host_state.worldbrush->surfaces1[v2 - host_state.worldbrush->surfaces2].prims.numPrims;
        if ( i >= v12 )
          break;
        v13 = *(_DWORD *)(v11 - 5);
        if ( v13 != 0 )
        {
          if ( v13 != 1 )
            goto LABEL_12;
          CMeshBuilder::Begin(
            this: &meshBuilder,
            pMesh,
            type: MATERIAL_TRIANGLE_STRIP,
            nVertexCount: *v11,
            nIndexCount: *(v11 - 2),
            pMeshSettings: nullptr);
        }
        else
        {
          CMeshBuilder::Begin(
            this: &meshBuilder,
            pMesh,
            type: MATERIAL_TRIANGLES,
            nVertexCount: *v11,
            nIndexCount: *(v11 - 2),
            pMeshSettings: nullptr);
        }
        BuildMSurfacePrimVerts(
          pBrushData: host_state.worldbrush,
          prim: (mprimitive_t *)(v11 - 5),
          builder: &meshBuilder,
          surfID);
        BuildMSurfacePrimIndices(
          pBrushData: host_state.worldbrush,
          prim: (mprimitive_t *)(v11 - 5),
          builder: &meshBuilder);
        if ( meshBuilder.m_bGenerateIndices )
        {
          switch ( meshBuilder.m_Type )
          {
            case MATERIAL_LINE_STRIP:
              v14 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
              break;
            case MATERIAL_LINE_LOOP:
              v14 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
              break;
            case MATERIAL_POLYGON:
              v14 = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
              break;
            case MATERIAL_QUADS:
              v14 = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
              break;
            case MATERIAL_INSTANCED_QUADS:
              v14 = 0;
              break;
            default:
              v14 = meshBuilder.m_VertexBuilder.m_nVertexCount;
              break;
          }
          CIndexBuilder::GenerateIndices(
            this: &meshBuilder.m_IndexBuilder,
            primitiveType: meshBuilder.m_Type,
            nIndexCount: v14);
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
        ++i;
        v2 = surfID;
        v11 += 6;
      }
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
  }
  else
  {
    v3 = pRenderContext->GetDynamicMesh(this: pRenderContext, a2: 1, a3: 0, a4: 0, a5: 0);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    flags_high = HIBYTE(surfID->flags);
    meshBuilder.m_pMesh = v3;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_POLYGON;
    v3->SetPrimitiveType(this: v3, a2: MATERIAL_TRIANGLES);
    meshBuilder.m_pMesh->LockMesh(
      this: meshBuilder.m_pMesh,
      a2: flags_high,
      a3: 3 * flags_high - 6,
      a4: &meshBuilder,
      a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v3->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 3 * flags_high - 6;
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::AttachBegin(
      this: &meshBuilder.m_VertexBuilder,
      pMesh: v3,
      nMaxVertexCount: flags_high,
      desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    BuildMSurfaceVertexArrays(pBrushData: host_state.worldbrush, surfID, builder: &meshBuilder);
    if ( meshBuilder.m_bGenerateIndices )
    {
      switch ( meshBuilder.m_Type )
      {
        case MATERIAL_LINE_STRIP:
          v5 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
          break;
        case MATERIAL_LINE_LOOP:
          v5 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
        case MATERIAL_POLYGON:
          v5 = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
          break;
        case MATERIAL_QUADS:
          v5 = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
          break;
        case MATERIAL_INSTANCED_QUADS:
          v5 = 0;
          break;
        default:
          v5 = meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
      }
      CIndexBuilder::GenerateIndices(
        this: &meshBuilder.m_IndexBuilder,
        primitiveType: meshBuilder.m_Type,
        nIndexCount: v5);
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
    v3->Draw_2(this: v3, a2: -1, a3: 0);
LABEL_12:
    CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D1890
// Name: void Shader_DrawSurfaceListStatic(class IMatRenderContext __near *,struct msurface2_t __near * __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Shader_DrawSurfaceListStatic(
        IMatRenderContext *pRenderContext,
        msurface2_t **pList,
        int listCount,
        int triangleCount)
{
  IMesh *v4; // ebx
  int j; // esi
  int m_nVertexCount; // eax
  int i; // esi
  CMeshBuilder meshBuilder; // [esp+Ch] [ebp-1E8h] BYREF

  if ( mat_forcedynamic.m_pParent != nullptr && mat_forcedynamic.m_pParent->m_Value.m_nValue != 0
    || ((*pList)->flags & 0x10000) != 0 )
  {
    for ( i = 0; i < listCount; ++i )
      Shader_DrawSurfaceDynamic(pRenderContext, surfID: pList[i]);
  }
  else if ( triangleCount != 0 )
  {
    v4 = pRenderContext->GetDynamicMesh(
           this: pRenderContext,
           a2: 1,
           a3: g_WorldStaticMeshes.m_Memory.m_pMemory[(*pList)->materialSortID],
           a4: 0,
           a5: 0);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    CMeshBuilder::Begin(
      this: &meshBuilder,
      pMesh: v4,
      type: MATERIAL_TRIANGLES,
      nVertexCount: 0,
      nIndexCount: 3 * triangleCount,
      pMeshSettings: nullptr);
    for ( j = 0; j < listCount; ++j )
      BuildIndicesForWorldSurface(
        meshBuilder: &meshBuilder.m_IndexBuilder,
        surfID: pList[j],
        pData: host_state.worldbrush);
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
    v4->Draw_2(this: v4, a2: -1, a3: 0);
    CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D1A50
// Name: void BuildMSurfaceVertexArraysTextureOnly(struct worldbrushdata_t __near *,struct msurface2_t __near *,class CMeshBuilder __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildMSurfaceVertexArraysTextureOnly(
        worldbrushdata_t *pBrushData,
        msurface2_t *surfID,
        CMeshBuilder *builder)
{
  unsigned __int16 *v4; // ecx
  int v5; // edi
  float *m_pCurrPosition; // ecx
  mvertex_t *v7; // eax
  int v8; // eax
  Vector2D uv; // [esp+8h] [ebp-Ch] BYREF
  int vertCount; // [esp+10h] [ebp-4h]
  unsigned __int16 *pVertIndex; // [esp+20h] [ebp+Ch]

  v4 = &pBrushData->vertindices[surfID->firstvertindex];
  v5 = 0;
  vertCount = HIBYTE(surfID->flags);
  pVertIndex = v4;
  if ( vertCount != 0 )
  {
    do
    {
      m_pCurrPosition = builder->m_VertexBuilder.m_pCurrPosition;
      v7 = &pBrushData->vertexes[pVertIndex[v5]];
      *m_pCurrPosition = v7->position.x;
      m_pCurrPosition[1] = v7->position.y;
      m_pCurrPosition[2] = v7->position.z;
      SurfComputeTextureCoordinate(surfID, vec: &v7->position, pUV: &uv.x);
      *(Vector2D *)builder->m_VertexBuilder.m_pCurrTexCoord[0] = uv;
      *(_DWORD *)builder->m_VertexBuilder.m_pCurrColor = flatColor[2]
                                                       | ((flatColor[1] | ((flatColor[0] | (flatColor[3] << 8)) << 8)) << 8);
      v8 = ++builder->m_VertexBuilder.m_nCurrentVertex;
      if ( v8 > builder->m_VertexBuilder.m_nVertexCount )
        builder->m_VertexBuilder.m_nVertexCount = v8;
      builder->m_VertexBuilder.m_pCurrPosition = (float *)((char *)builder->m_VertexBuilder.m_pCurrPosition
                                                         + builder->m_VertexBuilder.m_VertexSize_Position);
      builder->m_VertexBuilder.m_pCurrColor += builder->m_VertexBuilder.m_VertexSize_Color;
      builder->m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)builder->m_VertexBuilder.m_pCurrTexCoord[0]
                                                            + builder->m_VertexBuilder.m_VertexSize_TexCoord[0]);
      ++v5;
    }
    while ( v5 < vertCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D1B60
// Name: void Shader_AddSurfaceDynamicTextureOnly(class CMeshBuilder __near &,struct msurface2_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Shader_AddSurfaceDynamicTextureOnly(CMeshBuilder *meshBuilder, msurface2_t *surfID)
{
  worldbrushdata_t *worldbrush; // edi
  CIndexBuilder *p_m_IndexBuilder; // ecx
  unsigned __int16 firstPrimID; // ax
  int v6; // eax
  int startVert; // [esp+14h] [ebp+8h]

  worldbrush = host_state.worldbrush;
  startVert = meshBuilder->m_VertexBuilder.m_nVertexCount;
  BuildMSurfaceVertexArraysTextureOnly(pBrushData: host_state.worldbrush, surfID, builder: meshBuilder);
  p_m_IndexBuilder = &meshBuilder->m_IndexBuilder;
  if ( (surfID->flags & 0x8000) != 0 )
  {
    if ( (surfID->flags & 0x800) != 0 )
      firstPrimID = 0;
    else
      firstPrimID = worldbrush->surfaces1[surfID - worldbrush->surfaces2].prims.firstPrimID;
    v6 = (int)&worldbrush->primitives[firstPrimID];
    CIndexBuilder::FastIndexList(
      this: p_m_IndexBuilder,
      pIndexList: (char *)&worldbrush->primindices[*(unsigned __int16 *)(v6 + 4)],
      startVert,
      indexCount: *(unsigned __int16 *)(v6 + 6));
  }
  else
  {
    CIndexBuilder::FastPolygon(this: p_m_IndexBuilder, startVert, triangleCount: HIBYTE(surfID->flags) - 2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D1C00
// Name: void Shader_DrawWireframePolygons(class IMatRenderContext __near *,struct msurface2_t __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Shader_DrawWireframePolygons(IMatRenderContext *pRenderContext, msurface2_t **pList, int listCount)
{
  IIndexBuffer *j; // ebx
  int v4; // edi
  int v5; // eax
  unsigned int flags_high; // ecx
  IMesh *v7; // esi
  void (__thiscall *SetPrimitiveType)(IMesh *, MaterialPrimitiveType_t); // edx
  int v9; // edi
  worldbrushdata_t *worldbrush; // ecx
  int v11; // eax
  msurface2_t *v12; // eax
  unsigned int v13; // edx
  int firstvertindex; // esi
  int v15; // eax
  float v16; // edi
  float v17; // eax
  float z; // xmm2_4
  float y; // xmm1_4
  float x; // xmm0_4
  int v21; // edi
  float *p_x; // esi
  float *m_pCurrPosition; // eax
  float *v24; // eax
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-1FCh] BYREF
  Vector vecPrevPos; // [esp+1F0h] [ebp-14h]
  IMesh *pMesh; // [esp+1FCh] [ebp-8h]
  int i; // [esp+200h] [ebp-4h]

  j = nullptr;
  v4 = 0;
  v5 = 0;
  if ( listCount > 0 )
  {
    do
    {
      flags_high = HIBYTE(pList[v5]->flags);
      if ( flags_high >= 3 )
        v4 += flags_high;
      ++v5;
    }
    while ( v5 < listCount );
    if ( v4 != 0 )
    {
      pRenderContext->Bind(this: pRenderContext, a2: g_materialWorldWireframe, a3: nullptr);
      v7 = pRenderContext->GetDynamicMesh(this: pRenderContext, a2: 0, a3: 0, a4: 0, a5: 0);
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
      meshBuilder.m_pMesh = v7;
      meshBuilder.m_bGenerateIndices = true;
      meshBuilder.m_Type = MATERIAL_LINES;
      SetPrimitiveType = v7->SetPrimitiveType;
      v9 = 2 * v4;
      pMesh = v7;
      i = v9;
      SetPrimitiveType(this: v7, a2: MATERIAL_LINES);
      meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: v9, a3: v9, a4: &meshBuilder, a5: nullptr);
      meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v7->IIndexBuffer;
      meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
      meshBuilder.m_IndexBuilder.m_nMaxIndexCount = v9;
      meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
      meshBuilder.m_VertexBuilder.m_pVertexBuffer = v7;
      meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
      meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
      meshBuilder.m_IndexBuilder.m_bModify = false;
      meshBuilder.m_VertexBuilder.VertexDesc_t = meshBuilder.VertexDesc_t;
      meshBuilder.m_VertexBuilder.m_nMaxVertexCount = i;
      meshBuilder.m_VertexBuilder.m_NumBoneWeights = meshBuilder.m_NumBoneWeights != 0 ? 2 : 0;
      meshBuilder.m_VertexBuilder.m_nVertexCount = 0;
      meshBuilder.m_VertexBuilder.m_bModify = false;
      if ( meshBuilder.m_VertexBuilder.m_nBufferOffset == -1 )
      {
        meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
        meshBuilder.m_VertexBuilder.m_nBufferOffset = meshBuilder.MeshDesc_t::VertexDesc_t::m_nOffset;
        meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = meshBuilder.m_nFirstVertex;
      }
      meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
      CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
      worldbrush = host_state.worldbrush;
      v11 = 0;
      i = 0;
      do
      {
        v12 = pList[v11];
        v13 = HIBYTE(v12->flags);
        if ( v13 >= 3 )
        {
          firstvertindex = v12->firstvertindex;
          v15 = (int)&worldbrush->vertexes[worldbrush->vertindices[firstvertindex - 1 + v13]];
          vecPrevPos.x = *(float *)v15;
          v16 = *(float *)(v15 + 4);
          v17 = *(float *)(v15 + 8);
          vecPrevPos.y = v16;
          vecPrevPos.z = v17;
          z = vecPrevPos.z;
          y = vecPrevPos.y;
          x = vecPrevPos.x;
          v21 = firstvertindex;
          for ( j = (IIndexBuffer *)v13; j != nullptr; j = (IIndexBuffer *)((char *)j - 1) )
          {
            p_x = &worldbrush->vertexes[worldbrush->vertindices[v21]].position.x;
            m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
            *meshBuilder.m_VertexBuilder.m_pCurrPosition = x;
            m_pCurrPosition[1] = y;
            m_pCurrPosition[2] = z;
            CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
            v24 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
            *meshBuilder.m_VertexBuilder.m_pCurrPosition = *p_x;
            v24[1] = p_x[1];
            v24[2] = p_x[2];
            CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
            x = *p_x;
            y = p_x[1];
            z = p_x[2];
            worldbrush = host_state.worldbrush;
            ++v21;
          }
        }
        v11 = i + 1;
        i = v11;
      }
      while ( v11 < listCount );
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
      meshBuilder.m_IndexBuilder.m_pIndexBuffer = j;
      meshBuilder.m_IndexBuilder.m_nMaxIndexCount = (int)j;
      meshBuilder.m_VertexBuilder.m_nMaxVertexCount = (int)j;
      meshBuilder.m_VertexBuilder.m_pVertexBuffer = (IVertexBuffer *)j;
      meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
      meshBuilder.m_pMesh = (IMesh *)j;
      pMesh->Draw_2(this: pMesh, a2: -1, a3: (int)j);
      if ( (IIndexBuffer *)meshBuilder.m_VertexBuilder.m_pVertexBuffer != j
        && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
      {
        meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
      }
      if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != j
        && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
      {
        meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D1F90
// Name: Shader_DrawChainsWireframe
// Source: json
//------------------------------------------------------------------------------
void __usercall Shader_DrawChainsWireframe(IMatRenderContext *pRenderContext@<edi>, msurface2_t **pList, int listCount)
{
  int m_nValue; // eax
  IMaterial *v4; // ecx
  int i; // esi

  if ( (sv_cheats.m_pParent == nullptr || sv_cheats.m_pParent->m_Value.m_nValue == 0) && !Cmd_IsRptActive()
    || mat_wireframe.m_pParent == nullptr )
  {
    goto LABEL_7;
  }
  m_nValue = mat_wireframe.m_pParent->m_Value.m_nValue;
  if ( m_nValue == 3 )
  {
    Shader_DrawWireframePolygons(pRenderContext, pList, listCount);
    return;
  }
  v4 = g_materialWorldWireframeZBuffer;
  if ( m_nValue != 2 )
LABEL_7:
    v4 = g_materialWorldWireframe;
  pRenderContext->Bind(this: pRenderContext, a2: v4, a3: nullptr);
  for ( i = 0; i < listCount; ++i )
    Shader_DrawSurfaceDynamic(pRenderContext, surfID: pList[i]);
}

//------------------------------------------------------------------------------
// Address: 0x100D2010
// Name: Shader_DrawChainNormals
// Source: json
//------------------------------------------------------------------------------
void __usercall Shader_DrawChainNormals(
        CMeshBuilder *p_meshBuilder@<edi>,
        IMatRenderContext *pRenderContext,
        msurface2_t **pList,
        int listCount)
{
  IMatRenderContext *v4; // esi
  void (__thiscall *Bind)(IMatRenderContext *, IMaterial *, void *); // edx
  int v6; // ebx
  msurface2_t *v7; // edi
  IMesh *(__thiscall *GetDynamicMesh)(IMatRenderContext *, bool, IMesh *, IMesh *, IMaterial *); // eax
  IMesh *v9; // esi
  int v10; // eax
  int v11; // edi
  void (__thiscall *SetPrimitiveType)(IMesh *, MaterialPrimitiveType_t); // eax
  bool v13; // al
  msurface2_t *v14; // edx
  bool v15; // zf
  mvertex_t *v16; // esi
  Vector *v17; // edi
  float *m_pCurrPosition; // eax
  float *v19; // eax
  float v20; // xmm1_4
  float v21; // xmm2_4
  float *v22; // eax
  float *v23; // eax
  float v24; // xmm1_4
  float v25; // xmm2_4
  float *v26; // eax
  float *v27; // eax
  float v28; // xmm1_4
  float v29; // xmm2_4
  int m_nVertexCount; // eax
  Vector tVect; // [esp+8h] [ebp-224h] BYREF
  CMeshBuilder meshBuilder; // [esp+14h] [ebp-218h] BYREF
  Vector tangentS; // [esp+1FCh] [ebp-30h] BYREF
  Vector tangentT; // [esp+208h] [ebp-24h] BYREF
  IMesh *pMesh; // [esp+214h] [ebp-18h]
  worldbrushdata_t *pBrushData; // [esp+218h] [ebp-14h]
  int v38; // [esp+21Ch] [ebp-10h]
  BOOL negate; // [esp+220h] [ebp-Ch]
  int i; // [esp+224h] [ebp-8h]
  msurface2_t *surfID; // [esp+228h] [ebp-4h]

  v4 = pRenderContext;
  Bind = pRenderContext->Bind;
  pBrushData = host_state.worldbrush;
  v6 = 0;
  Bind(this: pRenderContext, a2: g_pMaterialWireframeVertexColor, a3: nullptr);
  i = 0;
  if ( listCount > 0 )
  {
    while ( 1 )
    {
      GetDynamicMesh = v4->GetDynamicMesh;
      surfID = pList[i];
      v7 = surfID;
      v9 = (IMesh *)((int (__thiscall *)(IMatRenderContext *, int, _DWORD, _DWORD, _DWORD, CMeshBuilder *))GetDynamicMesh)(
                      a1: v4,
                      a2: 1,
                      a3: 0,
                      a4: 0,
                      a5: 0,
                      a6: p_meshBuilder);
      meshBuilder.m_IndexBuilder.m_nBufferOffset = -1;
      meshBuilder.m_VertexBuilder.m_nBufferOffset = -1;
      meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
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
      v10 = 3 * HIBYTE(v7->flags);
      meshBuilder.m_pMesh = v9;
      meshBuilder.m_bGenerateIndices = true;
      meshBuilder.m_Type = MATERIAL_LINES;
      v11 = 2 * v10;
      SetPrimitiveType = v9->SetPrimitiveType;
      pMesh = v9;
      v38 = v11;
      SetPrimitiveType(this: v9, a2: MATERIAL_LINES);
      meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: v11, a3: v11, a4: &meshBuilder, a5: nullptr);
      meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v9->IIndexBuffer;
      meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
      meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
      meshBuilder.m_IndexBuilder.m_nMaxIndexCount = v11;
      meshBuilder.m_VertexBuilder.m_pVertexBuffer = v9;
      meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
      meshBuilder.m_IndexBuilder.m_bModify = false;
      meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
      meshBuilder.m_VertexBuilder.VertexDesc_t = meshBuilder.VertexDesc_t;
      meshBuilder.m_VertexBuilder.m_nMaxVertexCount = v38;
      meshBuilder.m_VertexBuilder.m_NumBoneWeights = meshBuilder.m_NumBoneWeights != 0 ? 2 : 0;
      meshBuilder.m_VertexBuilder.m_nVertexCount = 0;
      meshBuilder.m_VertexBuilder.m_bModify = false;
      if ( meshBuilder.m_VertexBuilder.m_nBufferOffset == -1 )
      {
        meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
        meshBuilder.m_VertexBuilder.m_nBufferOffset = meshBuilder.MeshDesc_t::VertexDesc_t::m_nOffset;
        meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = meshBuilder.m_nFirstVertex;
      }
      meshBuilder.m_VertexBuilder.m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pPosition;
      qmemcpy(
        meshBuilder.m_VertexBuilder.m_pCurrTexCoord,
        meshBuilder.m_VertexBuilder.m_pTexCoord,
        sizeof(meshBuilder.m_VertexBuilder.m_pCurrTexCoord));
      meshBuilder.m_VertexBuilder.m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pNormal;
      meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
      meshBuilder.m_VertexBuilder.m_nCurrentVertex = 0;
      meshBuilder.m_VertexBuilder.m_pCurrColor = meshBuilder.m_VertexBuilder.m_pColor;
      v13 = TangentSpaceSurfaceSetup(surfID, &tVect);
      v14 = surfID;
      v15 = HIBYTE(surfID->flags) == 0;
      LOBYTE(negate) = v13;
      if ( !v15 )
      {
        while ( 1 )
        {
          v16 = &pBrushData->vertexes[pBrushData->vertindices[v6 + v14->firstvertindex]];
          v17 = &pBrushData->vertnormals[pBrushData->vertnormalindices[v6
                                                                     + host_state.worldbrush->surfacenormals[v14 - host_state.worldbrush->surfaces2].firstvertnormal]];
          TangentSpaceComputeBasis(&tangentS, &tangentT, normal: v17, &tVect, negateTangent: negate);
          m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          *meshBuilder.m_VertexBuilder.m_pCurrPosition = v16->position.x;
          m_pCurrPosition[1] = v16->position.y;
          m_pCurrPosition[2] = v16->position.z;
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          v19 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          v20 = (float)(v17->y * 5.0) + v16->position.y;
          v21 = (float)(v17->z * 5.0) + v16->position.z;
          *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)(v17->x * 5.0) + v16->position.x;
          v19[1] = v20;
          v19[2] = v21;
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          v22 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          *meshBuilder.m_VertexBuilder.m_pCurrPosition = v16->position.x;
          v22[1] = v16->position.y;
          v22[2] = v16->position.z;
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          v23 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          v24 = (float)(tangentT.y * 5.0) + v16->position.y;
          v25 = (float)(tangentT.z * 5.0) + v16->position.z;
          *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)(tangentT.x * 5.0) + v16->position.x;
          v23[1] = v24;
          v23[2] = v25;
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          v26 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          *meshBuilder.m_VertexBuilder.m_pCurrPosition = v16->position.x;
          v26[1] = v16->position.y;
          v26[2] = v16->position.z;
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          v27 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          v28 = (float)(tangentS.y * 5.0) + v16->position.y;
          v29 = (float)(tangentS.z * 5.0) + v16->position.z;
          *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)(tangentS.x * 5.0) + v16->position.x;
          v27[1] = v28;
          v27[2] = v29;
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          if ( ++v6 >= HIBYTE(surfID->flags) )
            break;
          v14 = surfID;
        }
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
      p_meshBuilder = &meshBuilder;
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
      if ( ++i >= listCount )
        break;
      v4 = pRenderContext;
      v6 = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D2540
// Name: Shader_DrawChainBumpBasis
// Source: json
//------------------------------------------------------------------------------
void __usercall Shader_DrawChainBumpBasis(
        CMeshBuilder *p_meshBuilder@<edi>,
        IMatRenderContext *pRenderContext,
        msurface2_t **pList,
        int listCount)
{
  IMatRenderContext *v4; // esi
  void (__thiscall *Bind)(IMatRenderContext *, IMaterial *, void *); // edx
  int v6; // ebx
  msurface2_t *v7; // edi
  IMesh *(__thiscall *GetDynamicMesh)(IMatRenderContext *, bool, IMesh *, IMesh *, IMaterial *); // eax
  IMesh *v9; // esi
  int v10; // eax
  int v11; // edi
  void (__thiscall *SetPrimitiveType)(IMesh *, MaterialPrimitiveType_t); // eax
  bool v13; // al
  msurface2_t *v14; // edx
  bool v15; // zf
  mvertex_t *v16; // esi
  Vector *v17; // edi
  float y; // xmm3_4
  float z; // xmm4_4
  float v20; // xmm2_4
  float v21; // xmm4_4
  float v22; // xmm7_4
  float *m_pCurrPosition; // eax
  double v24; // st7
  float v25; // xmm0_4
  float v26; // xmm5_4
  float v27; // xmm1_4
  float *v28; // eax
  float v29; // xmm1_4
  float v30; // xmm2_4
  float *v31; // eax
  float *v32; // eax
  float v33; // xmm1_4
  float v34; // xmm2_4
  float *v35; // eax
  float *v36; // eax
  float v37; // xmm1_4
  float v38; // xmm2_4
  int m_nVertexCount; // eax
  Vector tVect; // [esp+8h] [ebp-250h] BYREF
  CMeshBuilder meshBuilder; // [esp+14h] [ebp-244h] BYREF
  Vector worldSpaceBumpBasis[3]; // [esp+1FCh] [ebp-5Ch]
  float x; // [esp+220h] [ebp-38h]
  IMesh *pMesh; // [esp+224h] [ebp-34h]
  int v46; // [esp+228h] [ebp-30h]
  Vector tangentS; // [esp+22Ch] [ebp-2Ch] BYREF
  BOOL negate; // [esp+238h] [ebp-20h]
  worldbrushdata_t *pBrushData; // [esp+23Ch] [ebp-1Ch]
  float v50; // [esp+240h] [ebp-18h]
  Vector tangentT; // [esp+244h] [ebp-14h] BYREF
  int i; // [esp+250h] [ebp-8h]
  msurface2_t *surfID; // [esp+254h] [ebp-4h]

  v4 = pRenderContext;
  Bind = pRenderContext->Bind;
  pBrushData = host_state.worldbrush;
  v6 = 0;
  Bind(this: pRenderContext, a2: g_pMaterialWireframeVertexColor, a3: nullptr);
  i = 0;
  if ( listCount > 0 )
  {
    while ( 1 )
    {
      GetDynamicMesh = v4->GetDynamicMesh;
      surfID = pList[i];
      v7 = surfID;
      v9 = (IMesh *)((int (__thiscall *)(IMatRenderContext *, int, _DWORD, _DWORD, _DWORD, CMeshBuilder *))GetDynamicMesh)(
                      a1: v4,
                      a2: 1,
                      a3: 0,
                      a4: 0,
                      a5: 0,
                      a6: p_meshBuilder);
      meshBuilder.m_IndexBuilder.m_nBufferOffset = -1;
      meshBuilder.m_VertexBuilder.m_nBufferOffset = -1;
      meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
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
      v10 = 3 * HIBYTE(v7->flags);
      meshBuilder.m_pMesh = v9;
      meshBuilder.m_bGenerateIndices = true;
      meshBuilder.m_Type = MATERIAL_LINES;
      v11 = 2 * v10;
      SetPrimitiveType = v9->SetPrimitiveType;
      pMesh = v9;
      v46 = v11;
      SetPrimitiveType(this: v9, a2: MATERIAL_LINES);
      meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: v11, a3: v11, a4: &meshBuilder, a5: nullptr);
      meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v9->IIndexBuffer;
      meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
      meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
      meshBuilder.m_IndexBuilder.m_nMaxIndexCount = v11;
      meshBuilder.m_VertexBuilder.m_pVertexBuffer = v9;
      meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
      meshBuilder.m_IndexBuilder.m_bModify = false;
      meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
      meshBuilder.m_VertexBuilder.VertexDesc_t = meshBuilder.VertexDesc_t;
      meshBuilder.m_VertexBuilder.m_nMaxVertexCount = v46;
      meshBuilder.m_VertexBuilder.m_NumBoneWeights = meshBuilder.m_NumBoneWeights != 0 ? 2 : 0;
      meshBuilder.m_VertexBuilder.m_nVertexCount = 0;
      meshBuilder.m_VertexBuilder.m_bModify = false;
      if ( meshBuilder.m_VertexBuilder.m_nBufferOffset == -1 )
      {
        meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
        meshBuilder.m_VertexBuilder.m_nBufferOffset = meshBuilder.MeshDesc_t::VertexDesc_t::m_nOffset;
        meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = meshBuilder.m_nFirstVertex;
      }
      meshBuilder.m_VertexBuilder.m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pPosition;
      qmemcpy(
        meshBuilder.m_VertexBuilder.m_pCurrTexCoord,
        meshBuilder.m_VertexBuilder.m_pTexCoord,
        sizeof(meshBuilder.m_VertexBuilder.m_pCurrTexCoord));
      meshBuilder.m_VertexBuilder.m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pNormal;
      meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
      meshBuilder.m_VertexBuilder.m_nCurrentVertex = 0;
      meshBuilder.m_VertexBuilder.m_pCurrColor = meshBuilder.m_VertexBuilder.m_pColor;
      v13 = TangentSpaceSurfaceSetup(surfID, &tVect);
      v14 = surfID;
      v15 = HIBYTE(surfID->flags) == 0;
      LOBYTE(negate) = v13;
      if ( !v15 )
      {
        while ( 1 )
        {
          v16 = &pBrushData->vertexes[pBrushData->vertindices[v6 + v14->firstvertindex]];
          v17 = &pBrushData->vertnormals[pBrushData->vertnormalindices[v6
                                                                     + host_state.worldbrush->surfacenormals[v14 - host_state.worldbrush->surfaces2].firstvertnormal]];
          TangentSpaceComputeBasis(&tangentS, &tangentT, normal: v17, &tVect, negateTangent: negate);
          y = v17->y;
          worldSpaceBumpBasis[0].x = (float)((float)(tangentS.y * 0.0) + (float)(tangentS.x * 0.81649661))
                                   + (float)(tangentS.z * 0.57735026);
          z = v17->z;
          v20 = tangentT.z * 0.57735026;
          worldSpaceBumpBasis[0].y = (float)((float)(tangentT.y * 0.0) + (float)(tangentT.x * 0.81649661))
                                   + (float)(tangentT.z * 0.57735026);
          x = v17->x;
          v21 = z * 0.57735026;
          worldSpaceBumpBasis[0].z = (float)((float)(x * 0.81649661) + (float)(y * 0.0)) + v21;
          worldSpaceBumpBasis[1].x = (float)((float)(tangentS.y * 0.70710677) + (float)(tangentS.x * -0.40824822))
                                   + (float)(tangentS.z * 0.57735026);
          v50 = -0.40824822 * tangentT.x;
          v22 = x * -0.40824822;
          worldSpaceBumpBasis[1].y = (float)((float)(tangentT.y * 0.70710677) + (float)(-0.40824822 * tangentT.x))
                                   + (float)(tangentT.z * 0.57735026);
          m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          v24 = v16->position.x;
          worldSpaceBumpBasis[1].z = (float)((float)(y * 0.70710677) + (float)(x * -0.40824822)) + v21;
          v25 = -0.40824822 * tangentT.x;
          v26 = (float)((float)(tangentS.x * -0.40824822) - (float)(tangentS.y * 0.70710677))
              + (float)(tangentS.z * 0.57735026);
          v27 = tangentT.y;
          *meshBuilder.m_VertexBuilder.m_pCurrPosition = v24;
          m_pCurrPosition[1] = v16->position.y;
          m_pCurrPosition[2] = v16->position.z;
          worldSpaceBumpBasis[2].x = v26;
          worldSpaceBumpBasis[2].y = (float)(v25 - (float)(v27 * 0.70710677)) + v20;
          worldSpaceBumpBasis[2].z = (float)(v22 - (float)(y * 0.70710677)) + v21;
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          v28 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          v29 = (float)(worldSpaceBumpBasis[0].y * 5.0) + v16->position.y;
          v30 = (float)(worldSpaceBumpBasis[0].z * 5.0) + v16->position.z;
          *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)(worldSpaceBumpBasis[0].x * 5.0) + v16->position.x;
          v28[1] = v29;
          v28[2] = v30;
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          v31 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          *meshBuilder.m_VertexBuilder.m_pCurrPosition = v16->position.x;
          v31[1] = v16->position.y;
          v31[2] = v16->position.z;
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          v32 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          v33 = (float)(worldSpaceBumpBasis[1].y * 5.0) + v16->position.y;
          v34 = (float)(worldSpaceBumpBasis[1].z * 5.0) + v16->position.z;
          *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)(worldSpaceBumpBasis[1].x * 5.0) + v16->position.x;
          v32[1] = v33;
          v32[2] = v34;
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          v35 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          *meshBuilder.m_VertexBuilder.m_pCurrPosition = v16->position.x;
          v35[1] = v16->position.y;
          v35[2] = v16->position.z;
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          v36 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          v37 = (float)(worldSpaceBumpBasis[2].y * 5.0) + v16->position.y;
          v38 = (float)(worldSpaceBumpBasis[2].z * 5.0) + v16->position.z;
          *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)(worldSpaceBumpBasis[2].x * 5.0) + v16->position.x;
          v36[1] = v37;
          v36[2] = v38;
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          if ( ++v6 >= HIBYTE(surfID->flags) )
            break;
          v14 = surfID;
        }
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
      p_meshBuilder = &meshBuilder;
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
      if ( ++i >= listCount )
        break;
      v4 = pRenderContext;
      v6 = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D2C20
// Name: Shader_DrawLuxels
// Source: json
//------------------------------------------------------------------------------
void __usercall Shader_DrawLuxels(IMatRenderContext *pRenderContext@<esi>, msurface2_t **pList, int listCount)
{
  int i; // edi
  msurface2_t *v4; // ebx

  pRenderContext->Bind(this: pRenderContext, a2: g_materialDebugLuxels, a3: nullptr);
  for ( i = 0; i < listCount; ++i )
  {
    v4 = pList[i];
    pRenderContext->BindLightmapPage(this: pRenderContext, a2: materialSortInfoArray[v4->materialSortID].lightmapPageID);
    Shader_DrawSurfaceDynamic(pRenderContext, surfID: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D2C80
// Name: ComputeDebugSettings
// Source: json
//------------------------------------------------------------------------------
bool ComputeDebugSettings()
{
  int m_nValue; // eax
  bool v1; // bl
  int v2; // eax
  int v3; // eax
  int v4; // eax
  bool v5; // dl
  int v6; // ecx
  int v7; // eax
  bool result; // al

  v1 = (sv_cheats.m_pParent != nullptr && sv_cheats.m_pParent->m_Value.m_nValue != 0 || Cmd_IsRptActive())
    && (mat_wireframe.m_pParent == nullptr ? (m_nValue = 0) : (m_nValue = mat_wireframe.m_pParent->m_Value.m_nValue),
        m_nValue != 0)
    || r_drawworld.m_pParent != nullptr && r_drawworld.m_pParent->m_Value.m_nValue == 2;
  g_ShaderDebug.wireframe = v1;
  if ( mat_normals.m_pParent != nullptr )
    v2 = mat_normals.m_pParent->m_Value.m_nValue;
  else
    v2 = 0;
  g_ShaderDebug.normals = v2 != 0;
  if ( mat_luxels.m_pParent != nullptr )
    v3 = mat_luxels.m_pParent->m_Value.m_nValue;
  else
    v3 = 0;
  g_ShaderDebug.luxels = v3 != 0;
  if ( mat_bumpbasis.m_pParent != nullptr )
    v4 = mat_bumpbasis.m_pParent->m_Value.m_nValue;
  else
    v4 = 0;
  v5 = v4 != 0;
  g_ShaderDebug.bumpBasis = v4 != 0;
  if ( mat_surfaceid.m_pParent != nullptr )
    v6 = mat_surfaceid.m_pParent->m_Value.m_nValue;
  else
    v6 = 0;
  g_ShaderDebug.surfaceid = v6;
  if ( mat_surfacemat.m_pParent != nullptr )
    v7 = mat_surfacemat.m_pParent->m_Value.m_nValue;
  else
    v7 = 0;
  result = v7 != 0;
  g_ShaderDebug.surfacematerials = result;
  if ( v1 || g_ShaderDebug.normals || g_ShaderDebug.luxels || v5 || v6 != 0 || (g_ShaderDebug.anydebug = false, result) )
    g_ShaderDebug.anydebug = true;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D2D80
// Name: void DrawDebugInformation(class IMatRenderContext __near *,struct msurface2_t __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawDebugInformation(IMatRenderContext *pRenderContext, msurface2_t **pList, int listCount)
{
  msurface2_t **v3; // esi
  void (__cdecl *v4)(IMatRenderContext *, msurface2_t *, const Vector *); // eax
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  v3 = pList;
  if ( g_ShaderDebug.wireframe )
    Shader_DrawChainsWireframe(pRenderContext, pList, listCount);
  if ( g_ShaderDebug.normals )
    Shader_DrawChainNormals(p_meshBuilder: (CMeshBuilder *)pRenderContext, pRenderContext, pList, listCount);
  if ( g_ShaderDebug.bumpBasis )
    Shader_DrawChainBumpBasis(p_meshBuilder: (CMeshBuilder *)pRenderContext, pRenderContext, pList, listCount);
  if ( g_ShaderDebug.luxels )
  {
    Shader_DrawLuxels(pRenderContext, pList, listCount);
    v3 = pList;
  }
  if ( g_ShaderDebug.surfaceid != 0 )
  {
    v4 = (void (__cdecl *)(IMatRenderContext *, msurface2_t *, const Vector *))DrawSurfaceID;
    if ( g_ShaderDebug.surfaceid == 2 )
      v4 = (void (__cdecl *)(IMatRenderContext *, msurface2_t *, const Vector *))DrawSurfaceIDAsInt;
    Shader_DrawSurfaceDebuggingInfo(a1: (int)&savedregs, pRenderContext, pList: v3, listCount, func: v4);
  }
  else if ( g_ShaderDebug.surfacematerials )
  {
    Shader_DrawSurfaceDebuggingInfo(
      a1: (int)&savedregs,
      pRenderContext,
      pList: v3,
      listCount,
      func: (void (__cdecl *)(IMatRenderContext *, msurface2_t *, const Vector *))DrawSurfaceMaterial);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D2E30
// Name: Shader_BuildDynamicLightmaps
// Source: json
//------------------------------------------------------------------------------
void __cdecl Shader_BuildDynamicLightmaps(CWorldRenderList *pRenderList)
{
  CUtlVector<msurface2_t *,CUtlMemory<msurface2_t *,int> > *m_DlightSurfaces; // edi
  int i; // ebx
  int j; // esi

  R_DLightStartView();
  m_DlightSurfaces = pRenderList->m_DlightSurfaces;
  for ( i = 4; i != 0; --i )
  {
    for ( j = m_DlightSurfaces->m_Size - 1; j >= 0; --j )
      R_CheckForLightmapUpdates(surfID: m_DlightSurfaces->m_Memory.m_pMemory[j], nTransformIndex: 0);
    ++m_DlightSurfaces;
  }
  R_DLightEndView();
}

//------------------------------------------------------------------------------
// Address: 0x100D2E80
// Name: void Shader_WorldBegin(class CWorldRenderList __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Shader_WorldBegin(CWorldRenderList *pRenderList)
{
  int m_nValue; // eax
  int v2; // eax
  IOverlayMgr *v3; // eax

  if ( r_drawworld.m_pParent != nullptr )
    m_nValue = r_drawworld.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  s_ShaderConvars.m_bDrawWorld = m_nValue != 0;
  if ( r_drawleaf.m_pParent != nullptr )
    s_ShaderConvars.m_nDrawLeaf = r_drawleaf.m_pParent->m_Value.m_nValue;
  else
    s_ShaderConvars.m_nDrawLeaf = 0;
  if ( r_drawfuncdetail.m_pParent != nullptr )
    v2 = r_drawfuncdetail.m_pParent->m_Value.m_nValue;
  else
    v2 = 0;
  s_ShaderConvars.m_bDrawFuncDetail = v2 != 0;
  if ( pRenderList != nullptr )
    CWorldRenderList::Reset(this: pRenderList);
  DecalSurfacesInit(bBrushModel: false);
  v3 = OverlayMgr();
  v3->ClearRenderLists_2(this: v3);
  g_pShadowMgr->ClearShadowRenderList(this: g_pShadowMgr);
}

//------------------------------------------------------------------------------
// Address: 0x100D2F10
// Name: Shader_WorldZFillSurfChain_SinglePrimitive
// Source: json
//------------------------------------------------------------------------------
void __usercall Shader_WorldZFillSurfChain_SinglePrimitive(
        CMeshBuilder *meshBuilder@<esi>,
        msurface2_t *surfaceHandle,
        int *nStartVert)
{
  worldbrushdata_t *worldbrush; // eax
  unsigned __int16 firstPrimID; // cx
  mprimitive_t *primitives; // edx
  int v6; // ecx
  bool v7; // zf
  mprimitive_t *v8; // edx
  int v9; // ebx
  int firstvertindex; // edi
  float *p_x; // eax
  float *m_pCurrPosition; // ecx
  int v13; // ecx
  mprimitive_t *pPrim; // [esp+4h] [ebp-8h]
  mvertex_t *pWorldVerts; // [esp+8h] [ebp-4h]

  worldbrush = host_state.worldbrush;
  pWorldVerts = host_state.worldbrush->vertexes;
  if ( (surfaceHandle->flags & 0x800) != 0 )
    firstPrimID = 0;
  else
    firstPrimID = host_state.worldbrush->surfaces1[surfaceHandle - host_state.worldbrush->surfaces2].prims.firstPrimID;
  primitives = host_state.worldbrush->primitives;
  v6 = firstPrimID;
  v7 = primitives[v6].vertCount == 0;
  v8 = &primitives[v6];
  pPrim = v8;
  if ( v7 )
  {
    v9 = 0;
    if ( HIBYTE(surfaceHandle->flags) != 0 )
    {
      firstvertindex = surfaceHandle->firstvertindex;
      do
      {
        p_x = &pWorldVerts[worldbrush->vertindices[firstvertindex]].position.x;
        m_pCurrPosition = meshBuilder->m_VertexBuilder.m_pCurrPosition;
        *m_pCurrPosition = *p_x;
        m_pCurrPosition[1] = p_x[1];
        m_pCurrPosition[2] = p_x[2];
        CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
        worldbrush = host_state.worldbrush;
        ++v9;
        ++firstvertindex;
      }
      while ( v9 < HIBYTE(surfaceHandle->flags) );
      v8 = pPrim;
    }
    v13 = 0;
    if ( v8->indexCount != 0 )
    {
      while ( 1 )
      {
        meshBuilder->m_IndexBuilder.m_pIndices[meshBuilder->m_IndexBuilder.m_nCurrentIndex] = *(_WORD *)nStartVert
                                                                                            + LOWORD(meshBuilder->m_IndexBuilder.m_nIndexOffset)
                                                                                            + worldbrush->primindices[v13 + v8->firstIndex];
        meshBuilder->m_IndexBuilder.m_nCurrentIndex += meshBuilder->m_IndexBuilder.m_nIndexSize;
        meshBuilder->m_IndexBuilder.m_nIndexCount = meshBuilder->m_IndexBuilder.m_nCurrentIndex;
        if ( ++v13 >= v8->indexCount )
          break;
        worldbrush = host_state.worldbrush;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D3030
// Name: Shader_WorldZFillSurfChain_Single
// Source: json
//------------------------------------------------------------------------------
void __usercall Shader_WorldZFillSurfChain_Single(
        msurface2_t *surfaceHandle@<eax>,
        CMeshBuilder *meshBuilder@<ecx>,
        int *nStartVert@<edi>)
{
  mvertex_t *vertexes; // ecx
  unsigned __int16 *v5; // ebx
  float *v6; // eax
  float *v7; // ecx
  int v8; // eax
  int v9; // eax
  float *v10; // eax
  float *v11; // ecx
  float *v12; // esi
  float *v13; // eax
  float *v14; // ecx
  float *v15; // eax
  float *v16; // eax
  float *v17; // ecx
  float *v18; // eax
  float *v19; // ecx
  float *v20; // ecx
  float *v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  unsigned __int16 v25; // ax
  float *m_pCurrPosition; // eax
  float *p_x; // ecx
  float *v28; // eax
  float *v29; // ecx
  float *v30; // ecx
  float *v31; // eax
  int m_nCurrentIndex; // eax
  int v; // [esp+8h] [ebp-Ch]
  CVertexBuilder *va; // [esp+8h] [ebp-Ch]
  int nSurfTriangleCount; // [esp+Ch] [ebp-8h]
  mvertex_t *pWorldVerts; // [esp+10h] [ebp-4h]

  nSurfTriangleCount = HIBYTE(surfaceHandle->flags) - 2;
  vertexes = host_state.worldbrush->vertexes;
  v5 = &host_state.worldbrush->vertindices[surfaceHandle->firstvertindex];
  pWorldVerts = vertexes;
  if ( (surfaceHandle->flags & 0x8000) != 0 )
  {
    Shader_WorldZFillSurfChain_SinglePrimitive(meshBuilder, surfaceHandle, nStartVert);
    *nStartVert += nSurfTriangleCount + 2;
    return;
  }
  if ( HIBYTE(surfaceHandle->flags) == 3 )
  {
    m_pCurrPosition = meshBuilder->m_VertexBuilder.m_pCurrPosition;
    p_x = &vertexes[*v5].position.x;
    *m_pCurrPosition = *p_x;
    m_pCurrPosition[1] = p_x[1];
    m_pCurrPosition[2] = p_x[2];
    CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
    v28 = &pWorldVerts[v5[1]].position.x;
    v29 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
    *v29 = *v28;
    v29[1] = v28[1];
    v29[2] = v28[2];
    CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
    v30 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
    v31 = &pWorldVerts[v5[2]].position.x;
    *v30 = *v31;
    v30[1] = v31[1];
    v30[2] = v31[2];
    CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
    meshBuilder->m_IndexBuilder.m_pIndices[meshBuilder->m_IndexBuilder.m_nCurrentIndex] = *(_WORD *)nStartVert
                                                                                        + LOWORD(meshBuilder->m_IndexBuilder.m_nIndexOffset);
    meshBuilder->m_IndexBuilder.m_nCurrentIndex += meshBuilder->m_IndexBuilder.m_nIndexSize;
    m_nCurrentIndex = meshBuilder->m_IndexBuilder.m_nCurrentIndex;
    meshBuilder->m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
    meshBuilder->m_IndexBuilder.m_pIndices[m_nCurrentIndex] = *(_WORD *)nStartVert
                                                            + LOWORD(meshBuilder->m_IndexBuilder.m_nIndexOffset)
                                                            + 1;
    meshBuilder->m_IndexBuilder.m_nCurrentIndex += meshBuilder->m_IndexBuilder.m_nIndexSize;
    meshBuilder->m_IndexBuilder.m_nIndexCount = meshBuilder->m_IndexBuilder.m_nCurrentIndex;
    v25 = *(_WORD *)nStartVert + LOWORD(meshBuilder->m_IndexBuilder.m_nIndexOffset) + 2;
    goto LABEL_10;
  }
  if ( HIBYTE(surfaceHandle->flags) == 4 )
  {
    v14 = &vertexes[*v5].position.x;
    v15 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
    *v15 = *v14;
    v15[1] = v14[1];
    v15[2] = v14[2];
    CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
    v16 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
    v17 = &pWorldVerts[v5[1]].position.x;
    *v16 = *v17;
    v16[1] = v17[1];
    v16[2] = v17[2];
    CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
    v18 = &pWorldVerts[v5[2]].position.x;
    v19 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
    *v19 = *v18;
    v19[1] = v18[1];
    v19[2] = v18[2];
    CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
    v20 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
    v21 = &pWorldVerts[v5[3]].position.x;
    *v20 = *v21;
    v20[1] = v21[1];
    v20[2] = v21[2];
    CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
    meshBuilder->m_IndexBuilder.m_pIndices[meshBuilder->m_IndexBuilder.m_nCurrentIndex] = *(_WORD *)nStartVert
                                                                                        + LOWORD(meshBuilder->m_IndexBuilder.m_nIndexOffset);
    meshBuilder->m_IndexBuilder.m_nCurrentIndex += meshBuilder->m_IndexBuilder.m_nIndexSize;
    v22 = meshBuilder->m_IndexBuilder.m_nCurrentIndex;
    meshBuilder->m_IndexBuilder.m_nIndexCount = v22;
    meshBuilder->m_IndexBuilder.m_pIndices[v22] = *(_WORD *)nStartVert
                                                + LOWORD(meshBuilder->m_IndexBuilder.m_nIndexOffset)
                                                + 1;
    meshBuilder->m_IndexBuilder.m_nCurrentIndex += meshBuilder->m_IndexBuilder.m_nIndexSize;
    meshBuilder->m_IndexBuilder.m_nIndexCount = meshBuilder->m_IndexBuilder.m_nCurrentIndex;
    meshBuilder->m_IndexBuilder.m_pIndices[meshBuilder->m_IndexBuilder.m_nCurrentIndex] = *(_WORD *)nStartVert
                                                                                        + LOWORD(meshBuilder->m_IndexBuilder.m_nIndexOffset)
                                                                                        + 2;
    meshBuilder->m_IndexBuilder.m_nCurrentIndex += meshBuilder->m_IndexBuilder.m_nIndexSize;
    v23 = meshBuilder->m_IndexBuilder.m_nCurrentIndex;
    meshBuilder->m_IndexBuilder.m_nIndexCount = v23;
    meshBuilder->m_IndexBuilder.m_pIndices[v23] = *(_WORD *)nStartVert
                                                + LOWORD(meshBuilder->m_IndexBuilder.m_nIndexOffset);
    meshBuilder->m_IndexBuilder.m_nCurrentIndex += meshBuilder->m_IndexBuilder.m_nIndexSize;
    v24 = meshBuilder->m_IndexBuilder.m_nCurrentIndex;
    meshBuilder->m_IndexBuilder.m_nIndexCount = v24;
    meshBuilder->m_IndexBuilder.m_pIndices[v24] = *(_WORD *)nStartVert
                                                + LOWORD(meshBuilder->m_IndexBuilder.m_nIndexOffset)
                                                + 2;
    meshBuilder->m_IndexBuilder.m_nCurrentIndex += meshBuilder->m_IndexBuilder.m_nIndexSize;
    meshBuilder->m_IndexBuilder.m_nIndexCount = meshBuilder->m_IndexBuilder.m_nCurrentIndex;
    v25 = *(_WORD *)nStartVert + LOWORD(meshBuilder->m_IndexBuilder.m_nIndexOffset) + 3;
LABEL_10:
    meshBuilder->m_IndexBuilder.m_pIndices[meshBuilder->m_IndexBuilder.m_nCurrentIndex] = v25;
    meshBuilder->m_IndexBuilder.m_nCurrentIndex += meshBuilder->m_IndexBuilder.m_nIndexSize;
    meshBuilder->m_IndexBuilder.m_nIndexCount = meshBuilder->m_IndexBuilder.m_nCurrentIndex;
    *nStartVert += nSurfTriangleCount + 2;
    return;
  }
  for ( v = 0; (unsigned __int16)v < nSurfTriangleCount; ++v )
  {
    v6 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
    v7 = &vertexes[*v5++].position.x;
    *v6 = *v7;
    v6[1] = v7[1];
    v6[2] = v7[2];
    CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
    meshBuilder->m_IndexBuilder.m_pIndices[meshBuilder->m_IndexBuilder.m_nCurrentIndex] = *(_WORD *)nStartVert
                                                                                        + LOWORD(meshBuilder->m_IndexBuilder.m_nIndexOffset);
    meshBuilder->m_IndexBuilder.m_nCurrentIndex += meshBuilder->m_IndexBuilder.m_nIndexSize;
    v8 = meshBuilder->m_IndexBuilder.m_nCurrentIndex;
    meshBuilder->m_IndexBuilder.m_nIndexCount = v8;
    meshBuilder->m_IndexBuilder.m_pIndices[v8] = v
                                               + *(_WORD *)nStartVert
                                               + LOWORD(meshBuilder->m_IndexBuilder.m_nIndexOffset)
                                               + 1;
    meshBuilder->m_IndexBuilder.m_nCurrentIndex += meshBuilder->m_IndexBuilder.m_nIndexSize;
    v9 = meshBuilder->m_IndexBuilder.m_nCurrentIndex;
    meshBuilder->m_IndexBuilder.m_nIndexCount = v9;
    meshBuilder->m_IndexBuilder.m_pIndices[v9] = v
                                               + *(_WORD *)nStartVert
                                               + LOWORD(meshBuilder->m_IndexBuilder.m_nIndexOffset)
                                               + 2;
    meshBuilder->m_IndexBuilder.m_nCurrentIndex += meshBuilder->m_IndexBuilder.m_nIndexSize;
    vertexes = pWorldVerts;
    meshBuilder->m_IndexBuilder.m_nIndexCount = meshBuilder->m_IndexBuilder.m_nCurrentIndex;
  }
  v10 = &vertexes[*v5].position.x;
  v11 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
  *v11 = *v10;
  v11[1] = v10[1];
  v11[2] = v10[2];
  va = &meshBuilder->m_VertexBuilder;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
  v12 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
  v13 = &pWorldVerts[v5[1]].position.x;
  *v12 = *v13;
  v12[1] = v13[1];
  v12[2] = v13[2];
  CVertexBuilder::AdvanceVertex(this: va);
  *nStartVert += nSurfTriangleCount + 2;
}

//------------------------------------------------------------------------------
// Address: 0x100D34D0
// Name: bool Shader_LeafContainsTranslucentSurfaces(class IWorldRenderList __near *,int,unsigned long)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Shader_LeafContainsTranslucentSurfaces(IWorldRenderList *pRenderListIn, int sortIndex)
{
  return HIWORD(pRenderListIn[164].__vftable[sortIndex].Release) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100D34F0
// Name: void R_GetWorldListIndicesInfo(struct WorldListIndicesInfo_t __near *,class IWorldRenderList __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_GetWorldListIndicesInfo(
        WorldListIndicesInfo_t *pInfoOut,
        IWorldRenderList *pRenderListIn,
        unsigned int nFlags)
{
  int v3; // edi
  char *v4; // edx
  int v5; // ebx
  unsigned int v6; // esi
  IWorldRenderList_vtbl *v7; // ecx
  IWorldRenderList_vtbl *v8; // edx
  IWorldRenderList_vtbl *i; // edi
  unsigned int v10; // eax
  int v11; // [esp+Ch] [ebp-8h]
  char *v12; // [esp+10h] [ebp-4h]

  v3 = 1;
  v4 = &args.m_pArgSBuffer[188];
  v5 = 0;
  v6 = 0;
  v11 = 1;
  v12 = &args.m_pArgSBuffer[188];
  do
  {
    if ( (v3 & nFlags) != 0 )
    {
      v7 = pRenderListIn[5 * *(_DWORD *)v4 + 21].__vftable;
      if ( (int)v7 > 0 )
      {
        v8 = pRenderListIn[5 * *(_DWORD *)v4 + 18].__vftable;
        for ( i = v7; i != nullptr; i = (IWorldRenderList_vtbl *)((char *)i - 1) )
        {
          v10 = *((_DWORD *)v8->AddRef + 6);
          v5 += v10;
          if ( v6 <= v10 )
            v6 = *((_DWORD *)v8->AddRef + 6);
          v8 = (IWorldRenderList_vtbl *)((char *)v8 + 4);
        }
        v3 = v11;
        v4 = v12;
      }
    }
    v4 += 4;
    v3 = __ROL4__(v3, 1);
    v12 = v4;
    v11 = v3;
  }
  while ( (int)v4 < (int)&args.m_pArgSBuffer[204] );
  pInfoOut->m_nMaxBatchIndices = 3 * v6;
  pInfoOut->m_nTotalIndices = 3 * v5;
}

//------------------------------------------------------------------------------
// Address: 0x100D3580
// Name: void R_SceneBegin(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl R_SceneBegin()
{
  ComputeDebugSettings();
}

//------------------------------------------------------------------------------
// Address: 0x100D3590
// Name: public: virtual bool CEngineBSPTree::EnumerateLeavesInSphere(class Vector const __near &,float,class ISpatialLeafEnumerator __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineBSPTree::EnumerateLeavesInSphere(
        CEngineBSPTree *this,
        const Vector *center,
        float radius,
        ISpatialLeafEnumerator *pEnum,
        int context)
{
  float y; // xmm2_4
  float z; // xmm3_4
  EnumLeafSphereInfo_t info; // [esp+0h] [ebp-30h] BYREF

  y = center->y;
  z = center->z;
  info.m_vecCenter.x = center->x;
  info.m_vecCenter.y = y;
  info.m_vecCenter.z = z;
  info.m_flRadius = radius;
  info.m_nContext = context;
  info.m_vecBoxCenter = info.m_vecCenter;
  info.m_vecBoxHalfDiagonal.x = radius;
  info.m_vecBoxHalfDiagonal.y = radius;
  *(_QWORD *)&info.m_vecBoxHalfDiagonal.z = __PAIR64__((unsigned int)pEnum, LODWORD(radius));
  return EnumerateLeafInSphere_R<0>(node: host_state.worldbrush->nodes, &info, nTestFlags: 1879048192);
}

//------------------------------------------------------------------------------
// Address: 0x100D3610
// Name: public: virtual bool CEngineBSPTree::EnumerateLeavesInSphereWithFlagSet(class Vector const __near &,float,class ISpatialLeafEnumerator __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineBSPTree::EnumerateLeavesInSphereWithFlagSet(
        CEngineBSPTree *this,
        const Vector *center,
        float radius,
        ISpatialLeafEnumerator *pEnum,
        int context,
        int nFlags)
{
  float x; // xmm1_4
  float y; // xmm2_4
  float z; // xmm3_4
  EnumLeafSphereInfo_t info; // [esp+0h] [ebp-30h] BYREF

  x = center->x;
  y = center->y;
  z = center->z;
  info.m_nContext = context;
  info.m_vecCenter.x = x;
  info.m_vecCenter.y = y;
  info.m_vecCenter.z = z;
  info.m_flRadius = radius;
  info.m_vecBoxCenter.x = x;
  info.m_vecBoxCenter.y = y;
  info.m_vecBoxCenter.z = z;
  info.m_vecBoxHalfDiagonal.x = radius;
  info.m_vecBoxHalfDiagonal.y = radius;
  *(_QWORD *)&info.m_vecBoxHalfDiagonal.z = __PAIR64__((unsigned int)pEnum, LODWORD(radius));
  return EnumerateLeafInSphere_R<1>(node: host_state.worldbrush->nodes, &info, nTestFlags: nFlags | 0x70000000);
}

//------------------------------------------------------------------------------
// Address: 0x100D3690
// Name: public: void CVarBitVecBase<unsigned short>::Resize(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVarBitVecBase<unsigned short>::Resize(
        CVarBitVecBase<unsigned short> *this,
        int resizeNumBits,
        bool bClearAll)
{
  int m_numInts; // ecx
  int v5; // edi
  unsigned int *v6; // eax
  unsigned int *p_m_iBitStringStorage; // eax
  unsigned __int8 *m_pInt; // eax
  unsigned int *v9; // eax

  m_numInts = this->m_numInts;
  v5 = (resizeNumBits + 31) / 32;
  if ( v5 != m_numInts )
  {
    if ( this->m_pInt != nullptr )
    {
      CVarBitVecBase<unsigned short>::ReallocInts(this, numInts: (resizeNumBits + 31) / 32);
      if ( !bClearAll && resizeNumBits >= this->m_numBits )
      {
        v6 = &this->m_pInt[this->m_numInts - 1];
        *v6 &= `GetEndMask'::`2'::bitStringEndMasks[this->m_numBits & 0x1F];
        memset(dst: (unsigned __int8 *)&this->m_pInt[this->m_numInts], value: 0, count: 4 * (v5 - this->m_numInts));
      }
    }
    else
    {
      if ( v5 != 0 )
      {
        if ( v5 == 1 )
          p_m_iBitStringStorage = &this->m_iBitStringStorage;
        else
          p_m_iBitStringStorage = (unsigned int *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * v5);
        this->m_pInt = p_m_iBitStringStorage;
      }
      bClearAll = true;
    }
    this->m_numInts = v5;
    if ( !bClearAll )
      goto LABEL_15;
    goto LABEL_13;
  }
  if ( bClearAll )
  {
LABEL_13:
    m_pInt = (unsigned __int8 *)this->m_pInt;
    if ( m_pInt != nullptr )
      memset(dst: m_pInt, value: 0, count: 4 * v5);
LABEL_15:
    this->m_numBits = resizeNumBits;
    return;
  }
  if ( resizeNumBits < this->m_numBits )
    goto LABEL_15;
  v9 = this->m_pInt;
  if ( v9 == nullptr )
    goto LABEL_15;
  v9[m_numInts - 1] &= `GetEndMask'::`2'::bitStringEndMasks[this->m_numBits & 0x1F];
  this->m_numBits = resizeNumBits;
}

//------------------------------------------------------------------------------
// Address: 0x100D37A0
// Name: public: void CWorldRenderList::Init(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorldRenderList::Init(CWorldRenderList *this, int nSurfaces)
{
  int v3; // eax
  int v4; // eax
  WorldListLeafData_t *m_pMemory; // eax
  IMemAlloc_vtbl *v6; // edx
  WorldListLeafData_t *v7; // eax

  v3 = materials->GetNumSortIDs(this: materials);
  CMSurfaceSortList::Init(this: &this->m_SortList, maxSortIDs: v3, minMaterialLists: 512);
  v4 = materials->GetNumSortIDs(this: materials);
  CMSurfaceSortList::Init(this: &this->m_DispSortList, maxSortIDs: v4, minMaterialLists: 32);
  CVarBitVecBase<unsigned short>::Resize(this: &this->m_VisitedSurfs.m_bits, resizeNumBits: nSurfaces, bClearAll: false);
  if ( this->m_leaves.m_Memory.m_nAllocationCount < 1024 && this->m_leaves.m_Memory.m_nGrowSize >= 0 )
  {
    this->m_leaves.m_Memory.m_nAllocationCount = 1024;
    m_pMemory = this->m_leaves.m_Memory.m_pMemory;
    v6 = _g_pMemAlloc->__vftable;
    if ( m_pMemory != nullptr )
      v7 = (WorldListLeafData_t *)((int (__stdcall *)(WorldListLeafData_t *, int))v6->Realloc_2)(
                                    a1: m_pMemory,
                                    a2: 0x2000);
    else
      v7 = (WorldListLeafData_t *)((int (__stdcall *)(int))v6->Alloc_2)(a1: 0x2000);
    this->m_leaves.m_Memory.m_pMemory = v7;
  }
  this->m_leaves.m_pElements = this->m_leaves.m_Memory.m_pMemory;
  *(_WORD *)&this->m_bSkyVisible = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100D3860
// Name: public: void CWorldRenderList::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorldRenderList::Purge(CWorldRenderList *this)
{
  int *p_m_nGrowSize; // esi
  msurface2_t **m_pMemory; // ecx
  int i; // [esp+8h] [ebp-4h]

  this->m_leaves.m_Size = 0;
  if ( this->m_leaves.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_leaves.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_leaves.m_Memory.m_pMemory);
      this->m_leaves.m_Memory.m_pMemory = nullptr;
    }
    this->m_leaves.m_Memory.m_nAllocationCount = 0;
  }
  this->m_leaves.m_pElements = this->m_leaves.m_Memory.m_pMemory;
  p_m_nGrowSize = &this->m_ShadowHandles[0].m_Memory.m_nGrowSize;
  for ( i = 4; i != 0; --i )
  {
    p_m_nGrowSize[1] = 0;
    if ( *p_m_nGrowSize >= 0 )
    {
      if ( *(p_m_nGrowSize - 2) != 0 )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)*(p_m_nGrowSize - 2));
        *(p_m_nGrowSize - 2) = 0;
      }
      *(p_m_nGrowSize - 1) = 0;
    }
    p_m_nGrowSize[2] = *(p_m_nGrowSize - 2);
    p_m_nGrowSize[21] = 0;
    if ( p_m_nGrowSize[20] >= 0 )
    {
      if ( p_m_nGrowSize[18] != 0 )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)p_m_nGrowSize[18]);
        p_m_nGrowSize[18] = 0;
      }
      p_m_nGrowSize[19] = 0;
    }
    p_m_nGrowSize[22] = p_m_nGrowSize[18];
    p_m_nGrowSize[41] = 0;
    if ( p_m_nGrowSize[40] >= 0 )
    {
      if ( p_m_nGrowSize[38] != 0 )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)p_m_nGrowSize[38]);
        p_m_nGrowSize[38] = 0;
      }
      p_m_nGrowSize[39] = 0;
    }
    p_m_nGrowSize[42] = p_m_nGrowSize[38];
    p_m_nGrowSize += 5;
  }
  CColorBalanceUIPanel::Init(this: (vgui::PropertyPage *)&this->m_SortList);
  CColorBalanceUIPanel::Init(this: (vgui::PropertyPage *)&this->m_DispSortList);
  this->m_AlphaSurfaces.m_Size = 0;
  if ( this->m_AlphaSurfaces.m_Memory.m_nGrowSize < 0 )
  {
    this->m_AlphaSurfaces.m_pElements = this->m_AlphaSurfaces.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_AlphaSurfaces.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_AlphaSurfaces.m_Memory.m_pMemory);
      this->m_AlphaSurfaces.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_AlphaSurfaces.m_Memory.m_pMemory;
    this->m_AlphaSurfaces.m_Memory.m_nAllocationCount = 0;
    this->m_AlphaSurfaces.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D39D0
// Name: Shader_DrawDynamicChain
// Source: json
//------------------------------------------------------------------------------
void __usercall Shader_DrawDynamicChain(
        IMatRenderContext *pRenderContext@<ecx>,
        const surfacesortgroup_t *group@<eax>,
        CMSurfaceSortList *sortList,
        bool bShadowDepth)
{
  CMSurfaceSortList *v4; // ebx
  msurface2_t *SurfaceAtHead; // eax
  IMesh *v8; // eax
  IMatRenderContext_vtbl *v9; // edx
  int v10; // eax
  int (__thiscall *GetMaxVerticesToRender)(IMatRenderContext *, IMaterial *); // edx
  int v12; // eax
  signed int vertexCount; // edx
  IMesh *v14; // edi
  __int16 listHead; // ax
  int v16; // eax
  char *v17; // esi
  int v18; // edi
  msurface2_t **v19; // ebx
  int v20; // eax
  char *v21; // esi
  int v22; // edi
  msurface2_t **v23; // ebx
  int m_nVertexCount; // eax
  __int16 v25; // ax
  int v26; // eax
  IMesh *v27; // esi
  int v28; // ebx
  CMeshBuilder meshBuilder; // [esp+Ch] [ebp-1F8h] BYREF
  int nMaxIndices; // [esp+1F4h] [ebp-10h]
  int nCurrIndexCount; // [esp+1F8h] [ebp-Ch]
  int nCurrVertexCount; // [esp+1FCh] [ebp-8h]
  IMesh *pMesh; // [esp+200h] [ebp-4h]

  v4 = sortList;
  SurfaceAtHead = CMSurfaceSortList::GetSurfaceAtHead(this: sortList, group);
  if ( SurfaceAtHead == nullptr )
    return;
  v8 = (IMesh *)Shader_SetChainTextureState(pRenderContext, surfID: SurfaceAtHead, pBaseEntity: nullptr, bShadowDepth);
  v9 = pRenderContext->__vftable;
  pMesh = v8;
  v10 = v9->GetMaxIndicesToRender(this: pRenderContext);
  GetMaxVerticesToRender = pRenderContext->GetMaxVerticesToRender;
  nMaxIndices = v10;
  v12 = GetMaxVerticesToRender(this: pRenderContext, a2: (IMaterial *)pMesh);
  vertexCount = group->vertexCount;
  nCurrIndexCount = 3 * group->triangleCount;
  nCurrVertexCount = vertexCount;
  if ( nCurrIndexCount < nMaxIndices && vertexCount < v12 )
  {
    v14 = pRenderContext->GetDynamicMesh(this: pRenderContext, a2: 0, a3: 0, a4: 0, a5: 0);
    pMesh = v14;
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    CMeshBuilder::Begin(
      this: &meshBuilder,
      pMesh: v14,
      type: MATERIAL_TRIANGLES,
      nVertexCount: nCurrVertexCount,
      nIndexCount: nCurrIndexCount,
      pMeshSettings: nullptr);
    listHead = group->listHead;
    if ( bShadowDepth )
    {
      if ( listHead != -1 )
      {
        do
        {
          v16 = listHead << 6;
          v17 = (char *)v4->m_list.m_Memory.m_pMemory + v16;
          v18 = 0;
          nCurrVertexCount = v16;
          if ( *((int *)v17 + 1) > 0 )
          {
            v19 = (msurface2_t **)(v17 + 8);
            do
            {
              Shader_AddSurfaceDynamicTextureOnly(&meshBuilder, surfID: *v19);
              ++v18;
              ++v19;
            }
            while ( v18 < *((_DWORD *)v17 + 1) );
            v16 = nCurrVertexCount;
            v4 = sortList;
          }
          listHead = *(_WORD *)((char *)&v4->m_list.m_Memory.m_pMemory->nextBlock + v16);
        }
        while ( listHead != -1 );
LABEL_18:
        v14 = pMesh;
      }
    }
    else if ( listHead != -1 )
    {
      do
      {
        v20 = listHead << 6;
        v21 = (char *)v4->m_list.m_Memory.m_pMemory + v20;
        v22 = 0;
        nCurrVertexCount = v20;
        if ( *((int *)v21 + 1) > 0 )
        {
          v23 = (msurface2_t **)(v21 + 8);
          do
          {
            Shader_AddSurfaceDynamic(&meshBuilder, surfID: *v23);
            ++v22;
            ++v23;
          }
          while ( v22 < *((_DWORD *)v21 + 1) );
          v20 = nCurrVertexCount;
          v4 = sortList;
        }
        listHead = *(_WORD *)((char *)&v4->m_list.m_Memory.m_pMemory->nextBlock + v20);
      }
      while ( listHead != -1 );
      goto LABEL_18;
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
    v14->Draw_2(this: v14, a2: -1, a3: 0);
    CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
    return;
  }
  v25 = group->listHead;
  if ( LOWORD(group->listHead) != 0xFFFF )
  {
    while ( 1 )
    {
      v26 = v25 << 6;
      v27 = (IMesh *)((char *)v4->m_list.m_Memory.m_pMemory + v26);
      v28 = 0;
      nCurrVertexCount = v26;
      if ( (int)v27->IIndexBuffer::__vftable > 0 )
      {
        pMesh = v27 + 1;
        do
        {
          Shader_DrawSurfaceDynamic(pRenderContext, surfID: (msurface2_t *)pMesh->IVertexBuffer::__vftable);
          pMesh = (IMesh *)((char *)pMesh + 4);
          ++v28;
        }
        while ( v28 < (int)v27->IIndexBuffer::__vftable );
        v26 = nCurrVertexCount;
      }
      v25 = *(_WORD *)((char *)&sortList->m_list.m_Memory.m_pMemory->nextBlock + v26);
      if ( v25 == -1 )
        break;
      v4 = sortList;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D3C70
// Name: void Shader_DrawChainsDynamic(class IMatRenderContext __near *,class CMSurfaceSortList const __near &,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall Shader_DrawChainsDynamic(
        int m_nIndexCount@<edi>,
        CMeshBuilder *p_meshBuilder@<esi>,
        IMatRenderContext *pRenderContext,
        CMSurfaceSortList *sortList,
        int nSortGroup,
        bool bShadowDepth)
{
  CMSurfaceSortList *v6; // ebx
  int v7; // eax
  int v8; // edx
  const CUtlVector<surfacesortgroup_t *,CUtlMemory<surfacesortgroup_t *,int> > *v9; // eax
  int v10; // ecx
  const surfacesortgroup_t *v11; // edi
  msurface2_t *SurfaceAtHead; // eax
  int v13; // eax
  int (__thiscall *GetMaxVerticesToRender)(IMatRenderContext *, IMaterial *); // edx
  int v15; // eax
  int vertexCount; // edx
  IMesh *v17; // esi
  __int16 listHead; // ax
  int v19; // eax
  char *v20; // esi
  int v21; // edi
  msurface2_t **v22; // ebx
  int v23; // eax
  char *v24; // esi
  int v25; // edi
  msurface2_t **v26; // ebx
  int m_nVertexCount; // eax
  __int16 i; // ax
  int v29; // eax
  char *v30; // esi
  int v31; // edi
  msurface2_t **v32; // ebx
  CMeshBuilder meshBuilder; // [esp+4h] [ebp-200h] BYREF
  const CUtlVector<surfacesortgroup_t *,CUtlMemory<surfacesortgroup_t *,int> > *_groupList; // [esp+1ECh] [ebp-18h]
  int _count; // [esp+1F0h] [ebp-14h]
  int v38; // [esp+1F4h] [ebp-10h]
  int nIndexCount; // [esp+1F8h] [ebp-Ch]
  int _listIndex; // [esp+1FCh] [ebp-8h]
  int nVertexCount; // [esp+200h] [ebp-4h]
  IMaterial *nSortGroupc; // [esp+214h] [ebp+10h]
  int nSortGroupa; // [esp+214h] [ebp+10h]
  int nSortGroupb; // [esp+214h] [ebp+10h]

  v6 = sortList;
  v7 = 5 * nSortGroup + 15;
  v8 = *(&sortList->m_list.m_Size + v7);
  v9 = (const CUtlVector<surfacesortgroup_t *,CUtlMemory<surfacesortgroup_t *,int> > *)(&sortList->m_list.m_Memory.m_pMemory
                                                                                      + v7);
  v10 = 0;
  _groupList = v9;
  _count = v8;
  _listIndex = 0;
  if ( v8 > 0 )
  {
    while ( 1 )
    {
      v11 = v9->m_Memory.m_pMemory[v10];
      SurfaceAtHead = CMSurfaceSortList::GetSurfaceAtHead(this: v6, group: v11);
      if ( SurfaceAtHead == nullptr )
        goto LABEL_43;
      nSortGroupc = Shader_SetChainTextureState(
                      pRenderContext,
                      surfID: SurfaceAtHead,
                      pBaseEntity: nullptr,
                      bShadowDepth);
      v13 = pRenderContext->GetMaxIndicesToRender(this: pRenderContext);
      GetMaxVerticesToRender = pRenderContext->GetMaxVerticesToRender;
      v38 = v13;
      v15 = GetMaxVerticesToRender(this: pRenderContext, a2: nSortGroupc);
      vertexCount = v11->vertexCount;
      nIndexCount = 3 * v11->triangleCount;
      nVertexCount = vertexCount;
      if ( nIndexCount < v38 && vertexCount < v15 )
        break;
      for ( i = v11->listHead; i != -1; i = *(_WORD *)((char *)&v6->m_list.m_Memory.m_pMemory->nextBlock + v29) )
      {
        v29 = i << 6;
        v30 = (char *)v6->m_list.m_Memory.m_pMemory + v29;
        v31 = 0;
        nSortGroupb = v29;
        if ( *((int *)v30 + 1) > 0 )
        {
          v32 = (msurface2_t **)(v30 + 8);
          do
          {
            Shader_DrawSurfaceDynamic(pRenderContext, surfID: *v32);
            ++v31;
            ++v32;
          }
          while ( v31 < *((_DWORD *)v30 + 1) );
          v29 = nSortGroupb;
          v6 = sortList;
        }
      }
LABEL_43:
      v10 = _listIndex + 1;
      _listIndex = v10;
      if ( v10 >= _count )
        return;
      v9 = _groupList;
    }
    v17 = (IMesh *)((int (__thiscall *)(IMatRenderContext *, _DWORD, _DWORD, _DWORD, _DWORD, int, CMeshBuilder *))pRenderContext->GetDynamicMesh)(
                     a1: pRenderContext,
                     a2: 0,
                     a3: 0,
                     a4: 0,
                     a5: 0,
                     a6: m_nIndexCount,
                     a7: p_meshBuilder);
    nSortGroupa = (int)v17;
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    CMeshBuilder::Begin(
      this: &meshBuilder,
      pMesh: v17,
      type: MATERIAL_TRIANGLES,
      nVertexCount,
      nIndexCount,
      pMeshSettings: nullptr);
    listHead = v11->listHead;
    if ( bShadowDepth )
    {
      if ( listHead != -1 )
      {
        do
        {
          v19 = listHead << 6;
          v20 = (char *)v6->m_list.m_Memory.m_pMemory + v19;
          v21 = 0;
          nVertexCount = v19;
          if ( *((int *)v20 + 1) > 0 )
          {
            v22 = (msurface2_t **)(v20 + 8);
            do
            {
              Shader_AddSurfaceDynamicTextureOnly(&meshBuilder, surfID: *v22);
              ++v21;
              ++v22;
            }
            while ( v21 < *((_DWORD *)v20 + 1) );
            v19 = nVertexCount;
            v6 = sortList;
          }
          listHead = *(_WORD *)((char *)&v6->m_list.m_Memory.m_pMemory->nextBlock + v19);
        }
        while ( listHead != -1 );
LABEL_21:
        v17 = (IMesh *)nSortGroupa;
      }
    }
    else if ( listHead != -1 )
    {
      do
      {
        v23 = listHead << 6;
        v24 = (char *)v6->m_list.m_Memory.m_pMemory + v23;
        v25 = 0;
        nVertexCount = v23;
        if ( *((int *)v24 + 1) > 0 )
        {
          v26 = (msurface2_t **)(v24 + 8);
          do
          {
            Shader_AddSurfaceDynamic(&meshBuilder, surfID: *v26);
            ++v25;
            ++v26;
          }
          while ( v25 < *((_DWORD *)v24 + 1) );
          v23 = nVertexCount;
          v6 = sortList;
        }
        listHead = *(_WORD *)((char *)&v6->m_list.m_Memory.m_pMemory->nextBlock + v23);
      }
      while ( listHead != -1 );
      goto LABEL_21;
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
    p_meshBuilder = &meshBuilder;
    m_nIndexCount = meshBuilder.m_IndexBuilder.m_nIndexCount;
    ((void (__thiscall *)(IMesh *, int))meshBuilder.m_pMesh->UnlockMesh)(
      a1: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    v17->Draw_2(this: v17, a2: -1, a3: 0);
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
    goto LABEL_43;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D3F70
// Name: Shader_DrawDispChain
// Source: json
//------------------------------------------------------------------------------
void __cdecl Shader_DrawDispChain(
        IMatRenderContext *pRenderContext,
        int nSortGroup,
        const CMSurfaceSortList *list,
        __int16 flags,
        IMaterial *bShadowDepth)
{
  const CMSurfaceSortList *v5; // ebx
  int v6; // edi
  int v7; // esi
  int v8; // eax
  int v9; // edx
  materiallist_t **v10; // eax
  int v11; // ecx
  materiallist_t *v12; // eax
  unsigned int v13; // ecx
  void *v14; // esp
  int v15; // edx
  int v16; // ecx
  int v17; // esi
  __int16 v18; // ax
  int v19; // edx
  char *v20; // eax
  int v21; // ecx
  msurface2_t **v22; // edx
  const CViewSetup *v23; // eax
  msurface2_t *v24[3]; // [esp+0h] [ebp-20h] BYREF
  int _count; // [esp+Ch] [ebp-14h]
  int v26; // [esp+10h] [ebp-10h]
  int _listIndex; // [esp+14h] [ebp-Ch]
  materiallist_t **v28; // [esp+18h] [ebp-8h]
  int count; // [esp+1Ch] [ebp-4h]

  v5 = list;
  v6 = 0;
  v7 = 0;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: &args.m_pArgSBuffer[480],
    a3: 0,
    a4: &args.m_pArgSBuffer[504],
    a5: false,
    a6: 4);
  v8 = 5 * nSortGroup + 15;
  v9 = *(&list->m_list.m_Size + v8);
  v10 = &list->m_list.m_Memory.m_pMemory + v8;
  v11 = 0;
  count = 0;
  v28 = v10;
  if ( v9 >= 2 )
  {
    v12 = *v10;
    v13 = ((unsigned int)(v9 - 2) >> 1) + 1;
    _listIndex = 2 * v13;
    do
    {
      v7 += *(_DWORD *)(v12->nextBlock + 28);
      v6 += *(_DWORD *)(v12->count + 28);
      v12 = (materiallist_t *)((char *)v12 + 8);
      --v13;
    }
    while ( v13 != 0 );
    v11 = _listIndex;
    v5 = list;
    v10 = v28;
  }
  if ( v11 < v9 )
    count = *(_DWORD *)(*(&(*v10)->nextBlock + v11) + 28);
  count += v7 + v6;
  if ( count != 0 )
  {
    v14 = alloca(4 * count);
    v15 = (int)v28[3];
    v16 = 0;
    v17 = 0;
    _count = v15;
    for ( _listIndex = 0; v16 < v15; _listIndex = v16 )
    {
      v18 = **((_WORD **)&(*v28)->nextBlock + v16);
      if ( v18 != -1 )
      {
        do
        {
          v19 = v18 << 6;
          v20 = (char *)v5->m_list.m_Memory.m_pMemory + v19;
          v21 = 0;
          v26 = v19;
          if ( *((int *)v20 + 1) > 0 )
          {
            v22 = (msurface2_t **)(v20 + 8);
            do
            {
              v24[v17] = *v22;
              ++v21;
              ++v17;
              ++v22;
            }
            while ( v21 < *((_DWORD *)v20 + 1) );
            v5 = list;
            v19 = v26;
          }
          v18 = *(_WORD *)((char *)&v5->m_list.m_Memory.m_pMemory->nextBlock + v19);
        }
        while ( v18 != -1 );
        v16 = _listIndex;
        v15 = _count;
      }
      ++v16;
    }
    v23 = g_EngineRenderer->ViewGetCurrent(this: g_EngineRenderer);
    DispInfo_RenderListWorld(
      a1: (int)v5,
      a2: (int)v24,
      pRenderContext,
      nSortGroup,
      pList: v24,
      listCount: count,
      bOrtho: v23->m_bOrtho,
      flags,
      bShadowDepth);
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x100D40C0
// Name: void Shader_DrawDispChainDecalsAndOverlays(class IMatRenderContext __near *,int,class CMSurfaceSortList const __near &,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Shader_DrawDispChainDecalsAndOverlays(
        IMatRenderContext *pRenderContext,
        int nSortGroup,
        const CMSurfaceSortList *list,
        __int16 flags)
{
  int v4; // edi
  int v5; // esi
  const CMSurfaceSortList *v6; // ebx
  int v7; // eax
  int v8; // ecx
  materiallist_t **v9; // eax
  int v10; // edx
  materiallist_t *v11; // eax
  unsigned int v12; // ecx
  void *v13; // esp
  int v14; // edx
  int v15; // ecx
  int v16; // esi
  __int16 v17; // ax
  int v18; // edx
  char *v19; // eax
  int v20; // ecx
  msurface2_t **v21; // edx
  const CViewSetup *v22; // eax
  msurface2_t *v23[3]; // [esp+0h] [ebp-20h] BYREF
  int _count; // [esp+Ch] [ebp-14h]
  int v25; // [esp+10h] [ebp-10h]
  int _listIndex; // [esp+14h] [ebp-Ch]
  materiallist_t **v27; // [esp+18h] [ebp-8h]
  int count; // [esp+1Ch] [ebp-4h]

  v4 = 0;
  v5 = 0;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: &args.m_pArgSBuffer[480],
    a3: 0,
    a4: &args.m_pArgSBuffer[504],
    a5: false,
    a6: 4);
  v6 = list;
  v7 = 5 * nSortGroup + 15;
  v8 = *(&list->m_list.m_Size + v7);
  v9 = &list->m_list.m_Memory.m_pMemory + v7;
  v10 = 0;
  count = 0;
  v27 = v9;
  if ( v8 >= 2 )
  {
    v11 = *v9;
    v12 = ((unsigned int)(v8 - 2) >> 1) + 1;
    _listIndex = 2 * v12;
    do
    {
      v5 += *(_DWORD *)(v11->nextBlock + 28);
      v4 += *(_DWORD *)(v11->count + 28);
      v11 = (materiallist_t *)((char *)v11 + 8);
      --v12;
    }
    while ( v12 != 0 );
    v9 = v27;
    v10 = _listIndex;
  }
  if ( v10 < (int)v9[3] )
    count = *(_DWORD *)(*(&(*v9)->nextBlock + v10) + 28);
  count += v5 + v4;
  if ( count != 0 )
  {
    v13 = alloca(4 * count);
    v14 = (int)v27[3];
    v15 = 0;
    v16 = 0;
    _count = v14;
    for ( _listIndex = 0; v15 < v14; _listIndex = v15 )
    {
      v17 = **((_WORD **)&(*v27)->nextBlock + v15);
      if ( v17 != -1 )
      {
        do
        {
          v18 = v17 << 6;
          v19 = (char *)v6->m_list.m_Memory.m_pMemory + v18;
          v20 = 0;
          v25 = v18;
          if ( *((int *)v19 + 1) > 0 )
          {
            v21 = (msurface2_t **)(v19 + 8);
            do
            {
              v23[v16] = *v21;
              ++v20;
              ++v16;
              ++v21;
            }
            while ( v20 < *((_DWORD *)v19 + 1) );
            v6 = list;
            v18 = v25;
          }
          v17 = *(_WORD *)((char *)&v6->m_list.m_Memory.m_pMemory->nextBlock + v18);
        }
        while ( v17 != -1 );
        v15 = _listIndex;
        v14 = _count;
      }
      ++v15;
    }
    v22 = g_EngineRenderer->ViewGetCurrent(this: g_EngineRenderer);
    DispInfo_RenderListDecalsAndOverlays(
      pRenderContext,
      nSortGroup,
      pList: v23,
      listCount: count,
      bOrtho: v22->m_bOrtho,
      flags);
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x100D4210
// Name: Shader_WorldZFill
// Source: json
//------------------------------------------------------------------------------
void __usercall Shader_WorldZFill(
        CWorldRenderList *pRenderList@<eax>,
        IMatRenderContext *pRenderContext,
        unsigned int flags)
{
  int v3; // ebx
  char *v4; // edx
  const CUtlVector<surfacesortgroup_t *,CUtlMemory<surfacesortgroup_t *,int> > *v5; // eax
  int m_Size; // ecx
  const surfacesortgroup_t *v7; // edi
  IMaterial *material; // esi
  unsigned int indexCountNoDetail; // ecx
  int v11; // edi
  int (__thiscall *GetMaxVerticesToRender)(IMatRenderContext *, IMaterial *); // edx
  int v13; // eax
  const CUtlVector<surfacesortgroup_t *,CUtlMemory<surfacesortgroup_t *,int> > *v14; // edx
  int v15; // ecx
  int v16; // esi
  materiallist_t **v17; // ecx
  int v18; // eax
  const surfacesortgroup_t *v19; // esi
  msurface2_t *SurfaceAtHead; // eax
  IMaterial *v21; // edi
  __int16 i; // ax
  int v23; // eax
  const materiallist_t *v24; // ecx
  char *v25; // edi
  unsigned int v26; // eax
  int indexCount; // ebx
  int v28; // esi
  unsigned __int16 firstPrimID; // ax
  int v30; // edx
  mprimitive_t *primitives; // eax
  bool v32; // zf
  mprimitive_t *v33; // eax
  int v34; // edi
  int m_nVertexCount; // eax
  int v36; // eax
  CMeshBuilder meshBuilder; // [esp+Ch] [ebp-234h] BYREF
  msurface2_t *nSurfID; // [esp+1F4h] [ebp-4Ch]
  int v39; // [esp+1F8h] [ebp-48h]
  int v40; // [esp+1FCh] [ebp-44h]
  materiallist_t **v41; // [esp+200h] [ebp-40h]
  int nMaxIndices; // [esp+204h] [ebp-3Ch]
  const materiallist_t *_pList; // [esp+208h] [ebp-38h]
  int nMaxVertices; // [esp+20Ch] [ebp-34h]
  int _index; // [esp+210h] [ebp-30h]
  int nStartVert; // [esp+214h] [ebp-2Ch] BYREF
  int _listIndex; // [esp+218h] [ebp-28h]
  IMesh *pMesh; // [esp+21Ch] [ebp-24h]
  const CUtlVector<surfacesortgroup_t *,CUtlMemory<surfacesortgroup_t *,int> > *_groupList; // [esp+220h] [ebp-20h]
  const CMSurfaceSortList *sortList; // [esp+224h] [ebp-1Ch]
  msurface2_t **pSurfaces; // [esp+228h] [ebp-18h]
  int nIndexCount; // [esp+22Ch] [ebp-14h]
  int v53; // [esp+230h] [ebp-10h]
  int nVertexCount; // [esp+234h] [ebp-Ch]
  int nBatchIndexCount; // [esp+238h] [ebp-8h]
  int nBatchVertexCount; // [esp+23Ch] [ebp-4h]

  v3 = 0;
  v4 = &args.m_pArgSBuffer[188];
  nVertexCount = 0;
  nIndexCount = 0;
  sortList = &pRenderList->m_SortList;
  v53 = 1;
  pSurfaces = (msurface2_t **)&args.m_pArgSBuffer[188];
  do
  {
    if ( (flags & v53) != 0 )
    {
      v5 = &sortList->m_sortGroupLists[*(_DWORD *)v4];
      m_Size = v5->m_Size;
      _groupList = v5;
      _listIndex = m_Size;
      if ( m_Size > 0 )
      {
        while ( 1 )
        {
          v7 = v5->m_Memory.m_pMemory[v3];
          material = host_state.worldbrush->texinfo[*((unsigned __int16 *)CMSurfaceSortList::GetSurfaceAtHead(
                                                                            this: (CMSurfaceSortList *)sortList,
                                                                            group: v7)
                                                    + 11) >> 1].material;
          if ( !material->IsAlphaTested(this: material) && !material->IsTranslucent(this: material) )
          {
            indexCountNoDetail = v7->indexCountNoDetail;
            nVertexCount += v7->vertexCountNoDetail;
            nIndexCount += indexCountNoDetail;
          }
          if ( ++v3 >= _listIndex )
            break;
          v5 = _groupList;
        }
        v4 = (char *)pSurfaces;
        v3 = 0;
      }
    }
    v4 += 4;
    pSurfaces = (msurface2_t **)v4;
    v53 = __ROL4__(v53, 1);
  }
  while ( (int)v4 < (int)&args.m_pArgSBuffer[204] );
  if ( nVertexCount != 0 )
  {
    pRenderContext->Bind(this: pRenderContext, a2: g_pMaterialWriteZ, a3: nullptr);
    pMesh = pRenderContext->GetDynamicMesh(this: pRenderContext, a2: 0, a3: 0, a4: 0, a5: 0);
    v11 = pRenderContext->GetMaxIndicesToRender(this: pRenderContext);
    GetMaxVerticesToRender = pRenderContext->GetMaxVerticesToRender;
    nMaxIndices = v11;
    v13 = GetMaxVerticesToRender(this: pRenderContext, a2: g_pMaterialWriteZ);
    nMaxVertices = v13;
    nBatchIndexCount = nIndexCount;
    if ( nIndexCount >= v11 )
      nBatchIndexCount = v11;
    nBatchVertexCount = nVertexCount;
    if ( nVertexCount >= v13 )
      nBatchVertexCount = v13;
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
    CMeshBuilder::Begin(
      this: &meshBuilder,
      pMesh,
      type: MATERIAL_TRIANGLES,
      nVertexCount: nBatchVertexCount,
      nIndexCount: nBatchIndexCount,
      pMeshSettings: nullptr);
    v14 = (const CUtlVector<surfacesortgroup_t *,CUtlMemory<surfacesortgroup_t *,int> > *)&args.m_pArgSBuffer[188];
    nStartVert = 0;
    v53 = 1;
    _groupList = (const CUtlVector<surfacesortgroup_t *,CUtlMemory<surfacesortgroup_t *,int> > *)&args.m_pArgSBuffer[188];
    do
    {
      if ( (flags & v53) != 0 )
      {
        v15 = 5 * (int)v14->m_Memory.m_pMemory + 15;
        v16 = *(&sortList->m_list.m_Size + v15);
        v17 = &sortList->m_list.m_Memory.m_pMemory + v15;
        v18 = 0;
        v41 = v17;
        v39 = v16;
        _listIndex = 0;
        if ( v16 > 0 )
        {
          while ( 1 )
          {
            v19 = (const surfacesortgroup_t *)*(&(*v17)->nextBlock + v18);
            SurfaceAtHead = CMSurfaceSortList::GetSurfaceAtHead(this: (CMSurfaceSortList *)sortList, group: v19);
            if ( v19->triangleCount != 0 && v19->vertexCount != 0 )
            {
              v21 = host_state.worldbrush->texinfo[*((unsigned __int16 *)SurfaceAtHead + 11) >> 1].material;
              if ( !v21->IsAlphaTested(this: v21) && !v21->IsTranslucent(this: v21) )
              {
                for ( i = v19->listHead;
                      i != -1;
                      i = *(_WORD *)((char *)&sortList->m_list.m_Memory.m_pMemory->nextBlock + v23) )
                {
                  v23 = i << 6;
                  v24 = (materiallist_t *)((char *)sortList->m_list.m_Memory.m_pMemory + v23);
                  v40 = v23;
                  _pList = v24;
                  _index = 0;
                  if ( v24->count > 0 )
                  {
                    pSurfaces = v24->pSurfaces;
                    do
                    {
                      v25 = (char *)*pSurfaces;
                      v26 = (*pSurfaces)->flags;
                      nSurfID = *pSurfaces;
                      if ( (v26 & 2) != 0 && (v26 & 0x10000) == 0 )
                      {
                        indexCount = 0;
                        v28 = 0;
                        if ( (v26 & 0x8000) != 0 )
                        {
                          if ( (v26 & 0x800) != 0 )
                            firstPrimID = 0;
                          else
                            firstPrimID = host_state.worldbrush->surfaces1[(v25
                                                                          - (char *)host_state.worldbrush->surfaces2) >> 5].prims.firstPrimID;
                          v30 = firstPrimID;
                          primitives = host_state.worldbrush->primitives;
                          v32 = primitives[v30].vertCount == 0;
                          v33 = &primitives[v30];
                          if ( v32 )
                          {
                            v28 = (unsigned __int8)v25[3];
                            indexCount = v33->indexCount;
                          }
                        }
                        else
                        {
                          v28 = (unsigned __int8)v25[3];
                          indexCount = 3 * v28 - 6;
                        }
                        v34 = nMaxIndices;
                        if ( v28 > nMaxVertices || indexCount > nMaxIndices )
                        {
                          _Error(a1: &args.m_pArgvBuffer[20], v28, nMaxVertices, indexCount, nMaxIndices);
                        }
                        else
                        {
                          if ( nBatchIndexCount < indexCount || nBatchVertexCount < v28 )
                          {
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
                            nBatchIndexCount = nIndexCount;
                            if ( nIndexCount >= v34 )
                              nBatchIndexCount = v34;
                            nBatchVertexCount = nVertexCount;
                            if ( nVertexCount >= nMaxVertices )
                              nBatchVertexCount = nMaxVertices;
                            pMesh = pRenderContext->GetDynamicMesh(this: pRenderContext, a2: 0, a3: 0, a4: 0, a5: 0);
                            CMeshBuilder::Begin(
                              this: &meshBuilder,
                              pMesh,
                              type: MATERIAL_TRIANGLES,
                              nVertexCount: nBatchVertexCount,
                              nIndexCount: nBatchIndexCount,
                              pMeshSettings: nullptr);
                            nStartVert = 0;
                          }
                          Shader_WorldZFillSurfChain_Single(surfaceHandle: nSurfID, &meshBuilder, &nStartVert);
                          nBatchIndexCount -= indexCount;
                          nBatchVertexCount -= v28;
                          nIndexCount -= indexCount;
                          nVertexCount -= v28;
                        }
                        v24 = _pList;
                      }
                      ++pSurfaces;
                      ++_index;
                    }
                    while ( _index < v24->count );
                    v23 = v40;
                  }
                }
              }
            }
            v18 = _listIndex + 1;
            _listIndex = v18;
            if ( v18 >= v39 )
              break;
            v17 = v41;
          }
          v14 = _groupList;
        }
      }
      v14 = (const CUtlVector<surfacesortgroup_t *,CUtlMemory<surfacesortgroup_t *,int> > *)((char *)v14 + 4);
      _groupList = v14;
      v53 = __ROL4__(v53, 1);
    }
    while ( (int)v14 < (int)&args.m_pArgSBuffer[204] );
    if ( meshBuilder.m_bGenerateIndices )
    {
      switch ( meshBuilder.m_Type )
      {
        case MATERIAL_LINE_STRIP:
          v36 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
          break;
        case MATERIAL_LINE_LOOP:
          v36 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
        case MATERIAL_POLYGON:
          v36 = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
          break;
        case MATERIAL_QUADS:
          v36 = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
          break;
        case MATERIAL_INSTANCED_QUADS:
          v36 = 0;
          break;
        default:
          v36 = meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
      }
      CIndexBuilder::GenerateIndices(
        this: &meshBuilder.m_IndexBuilder,
        primitiveType: meshBuilder.m_Type,
        nIndexCount: v36);
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
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D4820
// Name: void DrawSimpleWorldModel(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __usercall DrawSimpleWorldModel(int a1@<ebx>, int a2@<edi>, int a3@<esi>, __int16 flags)
{
  int v4; // esi
  IOverlayMgr *v5; // eax
  DrawModelInfo_t info; // [esp+0h] [ebp-210h] BYREF
  matrix3x4_t modelToWorld; // [esp+1E0h] [ebp-30h] BYREF

  if ( (flags & 0x1800) != 0
    && ((flags & 0x800) != 0 && g_pSimpleWorldModel != nullptr
     || (flags & 0x1000) != 0 && g_pSimpleWorldModelWater != nullptr) )
  {
    memset(&info.m_Decals, 0, 29);
    info.m_LightingState.m_nLocalLightCount = 0;
    info.m_LightingState.m_vecAmbientCube[0].x = 1.0;
    info.m_LightingState.m_vecAmbientCube[0].y = 1.0;
    info.m_LightingState.m_vecAmbientCube[0].z = 1.0;
    info.m_LightingState.m_vecAmbientCube[1].x = 1.0;
    info.m_LightingState.m_vecAmbientCube[1].y = 1.0;
    info.m_LightingState.m_vecAmbientCube[1].z = 1.0;
    info.m_LightingState.m_vecAmbientCube[2].x = 1.0;
    info.m_LightingState.m_vecAmbientCube[2].y = 1.0;
    info.m_LightingState.m_vecAmbientCube[2].z = 1.0;
    info.m_LightingState.m_vecAmbientCube[3].x = 1.0;
    info.m_LightingState.m_vecAmbientCube[3].y = 1.0;
    info.m_LightingState.m_vecAmbientCube[3].z = 1.0;
    info.m_LightingState.m_vecAmbientCube[4].x = 1.0;
    info.m_LightingState.m_vecAmbientCube[4].y = 1.0;
    info.m_LightingState.m_vecAmbientCube[4].z = 1.0;
    info.m_LightingState.m_vecAmbientCube[5].x = 1.0;
    info.m_LightingState.m_vecAmbientCube[5].y = 1.0;
    info.m_LightingState.m_vecAmbientCube[5].z = 1.0;
    *(_QWORD *)&modelToWorld.m_flMatVal[0][0] = 0x3F80000000000000LL;
    *(_QWORD *)&modelToWorld.m_flMatVal[0][2] = 0;
    *(_QWORD *)&modelToWorld.m_flMatVal[1][0] = 3212836864LL;
    memset(&modelToWorld.m_flMatVal[1][2], 0, 16);
    *(_QWORD *)&modelToWorld.m_flMatVal[2][2] = 1065353216;
    v4 = ((int (__thiscall *)(IMaterialSystem *, int, int, int))materials->GetRenderContext)(
           a1: materials,
           a2: a3,
           a3: a2,
           a4: a1);
    if ( v4 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 8))(a1: v4);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v4 + 80))(a1: v4, a2: 0);
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 84))(a1: v4);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 80))(a1: v4, a2: 10);
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 84))(a1: v4);
    g_pShadowMgr->PushSinglePassFlashlightStateEnabled(this: g_pShadowMgr, a2: true);
    if ( (flags & 0x800) != 0 && g_pSimpleWorldModel != nullptr )
    {
      info.m_pStudioHdr = (studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: g_pSimpleWorldModel->studio);
      info.m_pHardwareData = (studiohwdata_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetHardwareData)(a1: g_pSimpleWorldModel->studio);
      g_pStudioRender->DrawModelStaticProp(this: g_pStudioRender, a2: &info, a3: &modelToWorld, a4: 0);
    }
    if ( (flags & 0x1000) != 0 && g_pSimpleWorldModelWater != nullptr )
    {
      info.m_pStudioHdr = (studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: g_pSimpleWorldModelWater->studio);
      info.m_pHardwareData = (studiohwdata_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetHardwareData)(a1: g_pSimpleWorldModelWater->studio);
      g_pStudioRender->DrawModelStaticProp(this: g_pStudioRender, a2: &info, a3: &modelToWorld, a4: 0);
    }
    g_pShadowMgr->PopSinglePassFlashlightStateEnabled(this: g_pShadowMgr);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v4 + 80))(a1: v4, a2: 0);
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 88))(a1: v4);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 80))(a1: v4, a2: 10);
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 88))(a1: v4);
    v5 = OverlayMgr();
    ((void (__thiscall *)(IOverlayMgr *))v5->RenderAllUnlitOverlays)(a1: v5);
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 12))(a1: v4);
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 4))(a1: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D4B00
// Name: void R_SetFogVolumeState(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_SetFogVolumeState(int fogVolume, bool useHeightFog)
{
  IMaterial *FogVolumeMaterial; // esi
  IMaterialVar *v3; // edi
  int v4; // ebx
  IMatRenderContext *v5; // esi
  void (__thiscall *FogMode)(IMatRenderContext *, MaterialFogMode_t); // edx
  void (__thiscall *FogColor3fv)(IMatRenderContext *, const float *); // edx
  _DWORD v8[3]; // [esp+10h] [ebp-14h] BYREF
  int v9; // [esp+1Ch] [ebp-8h]
  int v10; // [esp+20h] [ebp-4h]
  mleafwaterdata_t *nFogVolume; // [esp+2Ch] [ebp+8h]

  FogVolumeMaterial = R_GetFogVolumeMaterial(nFogVolume: fogVolume, bEyeInFogVolume: !useHeightFog);
  nFogVolume = &host_state.worldbrush->leafwaterdata[fogVolume];
  v3 = FogVolumeMaterial->FindVar(this: FogVolumeMaterial, a2: &args.m_pArgSBuffer[368], a3: nullptr, a4: true);
  v4 = (int)FogVolumeMaterial->FindVar(this: FogVolumeMaterial, a2: &args.m_pArgSBuffer[356], a3: nullptr, a4: true);
  v10 = (int)FogVolumeMaterial->FindVar(this: FogVolumeMaterial, a2: &args.m_pArgSBuffer[344], a3: nullptr, a4: true);
  v9 = (int)FogVolumeMaterial->FindVar(this: FogVolumeMaterial, a2: &args.m_pArgSBuffer[336], a3: nullptr, a4: true);
  v5 = materials->GetRenderContext(this: materials);
  if ( v5 != nullptr )
    v5->BeginRender(this: v5);
  if ( *(_DWORD *)(v4 + 8) != 0
    && fog_enable_water_fog.m_pParent != nullptr
    && fog_enable_water_fog.m_pParent->m_Value.m_nValue != 0 )
  {
    ((void (__thiscall *)(IMatRenderContext *, _DWORD))v5->SetFogZ)(a1: v5, a2: nFogVolume->surfaceZ);
    FogMode = v5->FogMode;
    if ( useHeightFog )
      ((void (__stdcall *)(int))FogMode)(a1: 2);
    else
      ((void (__stdcall *)(int))FogMode)(a1: 1);
    FogColor3fv = v5->FogColor3fv;
    v8[0] = LODWORD(v3->m_VecVal.x);
    v8[1] = LODWORD(v3->m_VecVal.y);
    v8[2] = LODWORD(v3->m_VecVal.z);
    FogColor3fv(this: v5, a2: (const float *)v8);
    ((void (__thiscall *)(IMatRenderContext *, _DWORD))v5->FogStart)(a1: v5, a2: *(float *)(v10 + 12));
    ((void (__thiscall *)(IMatRenderContext *, _DWORD))v5->FogEnd)(a1: v5, a2: *(float *)(v9 + 12));
    ((void (__thiscall *)(IMatRenderContext *, _DWORD))v5->FogMaxDensity)(a1: v5, a2: 1.0);
  }
  else
  {
    v5->FogMode(this: v5, a2: MATERIAL_FOG_NONE);
  }
  v5->EndRender(this: v5);
  v5->Release(this: v5);
}

//------------------------------------------------------------------------------
// Address: 0x100D4C90
// Name: void Shader_DrawLightmapPageSurface(struct msurface2_t __near *,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Shader_DrawLightmapPageSurface(msurface2_t *surfID)
{
  IMatRenderContext *v1; // eax
  IMatRenderContext *m_pObject; // esi
  IMesh *v3; // esi
  int flags_high; // eax
  int v5; // edi
  void (__thiscall *SetPrimitiveType)(IMesh *, MaterialPrimitiveType_t); // eax
  int m_nVertexCount; // edx
  float *m_pPosition; // eax
  int v9; // esi
  float *p_x; // edi
  float v11; // xmm0_4
  int v12; // ecx
  float v13; // xmm0_4
  float *m_pCurrPosition; // eax
  int v15; // eax
  Vector2D lightCoords[32][4]; // [esp+Ch] [ebp-608h] BYREF
  CMeshBuilder meshBuilder; // [esp+40Ch] [ebp-208h] BYREF
  int v18; // [esp+5F4h] [ebp-20h]
  int count; // [esp+5F8h] [ebp-1Ch]
  IMesh *pMesh; // [esp+5FCh] [ebp-18h]
  int lightmapPageHeight; // [esp+600h] [ebp-14h] BYREF
  int lightmapPageWidth; // [esp+604h] [ebp-10h] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+608h] [ebp-Ch]
  Vector2D *v24; // [esp+60Ch] [ebp-8h]
  int bumpID; // [esp+610h] [ebp-4h]

  count = (surfID->flags & 8) != 0 ? 4 : 1;
  BuildMSurfaceVerts(pBrushData: host_state.worldbrush, surfID, verts: nullptr, texCoords: nullptr, lightCoords);
  v1 = materials->GetRenderContext(this: materials);
  m_pObject = v1;
  pRenderContext.m_pObject = v1;
  if ( v1 != nullptr )
    v1->BeginRender(this: v1);
  m_pObject->Bind(this: m_pObject, a2: g_materialWireframe, a3: nullptr);
  materials->GetLightmapPageSize(
    this: materials,
    a2: materialSortInfoArray[surfID->materialSortID].lightmapPageID,
    a3: &lightmapPageWidth,
    a4: &lightmapPageHeight);
  bumpID = 0;
  v24 = lightCoords[0];
  do
  {
    v3 = m_pObject->GetDynamicMesh(this: m_pObject, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nBufferOffset = -1;
    meshBuilder.m_VertexBuilder.m_nBufferOffset = -1;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    flags_high = HIBYTE(surfID->flags);
    memset(&meshBuilder.m_IndexBuilder.m_pIndexBuffer, 0, 12);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    meshBuilder.m_IndexBuilder.m_nTotalIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_nBufferFirstIndex = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = 0;
    memset(&meshBuilder.m_VertexBuilder.m_nMaxVertexCount, 0, 12);
    meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
    meshBuilder.m_pMesh = v3;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_LINES;
    v5 = 2 * flags_high;
    SetPrimitiveType = v3->SetPrimitiveType;
    pMesh = v3;
    v18 = v5;
    SetPrimitiveType(this: v3, a2: MATERIAL_LINES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: v5, a3: v5, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v3->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = v5;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = v3;
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    meshBuilder.m_VertexBuilder.VertexDesc_t = meshBuilder.VertexDesc_t;
    meshBuilder.m_VertexBuilder.m_NumBoneWeights = meshBuilder.m_NumBoneWeights != 0 ? 2 : 0;
    m_nVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = v18;
    meshBuilder.m_VertexBuilder.m_nVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_bModify = false;
    if ( meshBuilder.m_VertexBuilder.m_nBufferOffset == -1 )
    {
      meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
      meshBuilder.m_VertexBuilder.m_nBufferOffset = meshBuilder.MeshDesc_t::VertexDesc_t::m_nOffset;
      meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = meshBuilder.m_nFirstVertex;
    }
    meshBuilder.m_VertexBuilder.m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pNormal;
    qmemcpy(
      meshBuilder.m_VertexBuilder.m_pCurrTexCoord,
      meshBuilder.m_VertexBuilder.m_pTexCoord,
      sizeof(meshBuilder.m_VertexBuilder.m_pCurrTexCoord));
    m_pPosition = meshBuilder.m_VertexBuilder.m_pPosition;
    meshBuilder.m_VertexBuilder.m_pCurrColor = meshBuilder.m_VertexBuilder.m_pColor;
    v9 = 0;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = 0;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pPosition;
    if ( HIBYTE(surfID->flags) != 0 )
    {
      p_x = &v24->x;
      while ( 1 )
      {
        v11 = (float)lightmapPageHeight * p_x[1];
        *m_pPosition = (float)lightmapPageWidth * *p_x;
        m_pPosition[1] = v11;
        m_pPosition[2] = 0.0;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        v12 = bumpID + 4 * (++v9 % HIBYTE(surfID->flags));
        v13 = (float)lightmapPageHeight * lightCoords[0][v12].y;
        m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)lightmapPageWidth * lightCoords[0][v12].x;
        m_pCurrPosition[1] = v13;
        m_pCurrPosition[2] = 0.0;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        p_x += 8;
        if ( v9 >= HIBYTE(surfID->flags) )
          break;
        m_pPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      }
      m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
    }
    if ( meshBuilder.m_bGenerateIndices )
    {
      switch ( meshBuilder.m_Type )
      {
        case MATERIAL_LINE_STRIP:
          v15 = 2 * m_nVertexCount - 2;
          break;
        case MATERIAL_LINE_LOOP:
          v15 = 2 * m_nVertexCount;
          break;
        case MATERIAL_POLYGON:
          v15 = 3 * m_nVertexCount - 6;
          break;
        case MATERIAL_QUADS:
          v15 = 6 * m_nVertexCount / 4;
          break;
        case MATERIAL_INSTANCED_QUADS:
          v15 = 0;
          break;
        default:
          v15 = m_nVertexCount;
          break;
      }
      CIndexBuilder::GenerateIndices(
        this: &meshBuilder.m_IndexBuilder,
        primitiveType: meshBuilder.m_Type,
        nIndexCount: v15);
      m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
    }
    meshBuilder.m_pMesh->UnlockMesh(
      this: meshBuilder.m_pMesh,
      a2: m_nVertexCount,
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
    ++v24;
    m_pObject = pRenderContext.m_pObject;
    ++bumpID;
  }
  while ( bumpID < count );
  pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x100D50E0
// Name: void Shader_DrawLightmapPageChains(class IWorldRenderList __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Shader_DrawLightmapPageChains(IWorldRenderList *pRenderListIn, int pageId)
{
  IWorldRenderList *v2; // ebx
  IWorldRenderList *v3; // ecx
  CMSurfaceSortList *v4; // esi
  const surfacesortgroup_t *v5; // edi
  __int16 i; // ax
  int v7; // eax
  char *v8; // esi
  int v9; // edi
  msurface2_t **v10; // ebx
  IWorldRenderList_vtbl *v11; // esi
  int v12; // edx
  __int16 v13; // ax
  int v14; // eax
  char *v15; // esi
  int v16; // edi
  char *v17; // ebx
  bool v18; // zf
  int v19; // [esp+18h] [ebp-14h]
  int v20; // [esp+18h] [ebp-14h]
  int v21; // [esp+1Ch] [ebp-10h]
  IWorldRenderList_vtbl *v22; // [esp+1Ch] [ebp-10h]
  int v23; // [esp+20h] [ebp-Ch]
  int _count; // [esp+24h] [ebp-8h]
  int _counta; // [esp+24h] [ebp-8h]
  IWorldRenderList *v26; // [esp+28h] [ebp-4h]

  v2 = pRenderListIn;
  v3 = pRenderListIn + 69;
  v26 = pRenderListIn + 69;
  v23 = 4;
  do
  {
    v19 = (int)v3[-48].__vftable;
    _count = 0;
    if ( v19 > 0 )
    {
      v4 = (CMSurfaceSortList *)&v2[3];
      do
      {
        v5 = *((const surfacesortgroup_t **)&v3[-51].AddRef + _count);
        if ( materialSortInfoArray[CMSurfaceSortList::GetSurfaceAtHead(this: v4, group: v5)->materialSortID].lightmapPageID == pageId )
        {
          for ( i = v5->listHead; i != -1; v4 = (CMSurfaceSortList *)&v2[3] )
          {
            v7 = i << 6;
            v8 = (char *)v4->m_list.m_Memory.m_pMemory + v7;
            v9 = 0;
            v21 = v7;
            if ( *((int *)v8 + 1) > 0 )
            {
              v10 = (msurface2_t **)(v8 + 8);
              do
              {
                Shader_DrawLightmapPageSurface(surfID: *v10);
                ++v9;
                ++v10;
              }
              while ( v9 < *((_DWORD *)v8 + 1) );
              v2 = pRenderListIn;
              v7 = v21;
            }
            i = *(_WORD *)((char *)&v2[3].AddRef + v7);
          }
        }
        v3 = v26;
        ++_count;
      }
      while ( _count < v19 );
    }
    v11 = v3->__vftable;
    v12 = 0;
    v22 = v3->__vftable;
    for ( _counta = 0; v12 < (int)v11; _counta = v12 )
    {
      v13 = **((_WORD **)&v3[-3].AddRef + v12);
      if ( v13 != -1 )
      {
        do
        {
          v14 = v13 << 6;
          v15 = (char *)v2[51].__vftable + v14;
          v16 = 0;
          v20 = v14;
          if ( *((int *)v15 + 1) > 0 )
          {
            v17 = v15 + 8;
            do
            {
              (*(void (__thiscall **)(_DWORD, int))(**(_DWORD **)(*(_DWORD *)v17 + 24) + 8))(
                a1: *(_DWORD *)(*(_DWORD *)v17 + 24),
                a2: pageId);
              ++v16;
              v17 += 4;
            }
            while ( v16 < *((_DWORD *)v15 + 1) );
            v14 = v20;
            v2 = pRenderListIn;
          }
          v13 = *(_WORD *)((char *)&v2[51].AddRef + v14);
        }
        while ( v13 != -1 );
        v3 = v26;
        v11 = v22;
        v12 = _counta;
      }
      ++v12;
    }
    v3 += 5;
    v18 = v23-- == 1;
    v26 = v3;
  }
  while ( !v18 );
}

//------------------------------------------------------------------------------
// Address: 0x100D5250
// Name: public: CBrushModelTransform::~CBrushModelTransform(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBrushModelTransform::~CBrushModelTransform(CBrushModelTransform *this@<ecx>, int a2@<esi>)
{
  int v3; // esi

  if ( !this->m_bIdentity )
  {
    v3 = ((int (__thiscall *)(IMaterialSystem *, int))materials->GetRenderContext)(a1: materials, a2);
    if ( v3 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 8))(a1: v3);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v3 + 80))(a1: v3, a2: 10);
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 88))(a1: v3);
    MatrixSetIdentity(dst: &g_BrushToWorldMatrix);
    modelorg = this->m_savedModelorg;
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 12))(a1: v3);
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 4))(a1: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D52E0
// Name: void DrawDebugInformation(class IMatRenderContext __near *,class matrix3x4a_t const __near &,struct msurface2_t __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawDebugInformation(
        IMatRenderContext *pRenderContext,
        const matrix3x4a_t *brushToWorld,
        msurface2_t **pList,
        int listCount)
{
  CBrushModelTransform transform; // [esp+4h] [ebp-10h] BYREF

  CBrushModelTransform::CBrushModelTransform(this: &transform, matrix: brushToWorld, pRenderContext);
  DrawDebugInformation(pRenderContext, pList, listCount);
  CBrushModelTransform::~CBrushModelTransform(this: &transform, a2: (int)pRenderContext);
}

//------------------------------------------------------------------------------
// Address: 0x100D5320
// Name: void R_DrawBrushModelShadow(class IClientRenderable __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_DrawBrushModelShadow(IClientRenderable *pRenderable)
{
  model_t *v2; // ebx
  IMatRenderContext *v3; // edi
  CBrushModelTransform brushTransform; // [esp+0h] [ebp-18h] BYREF
  const Vector *origin; // [esp+10h] [ebp-8h]
  const QAngle *angles; // [esp+14h] [ebp-4h]

  if ( r_drawbrushmodels.m_pParent != nullptr && r_drawbrushmodels.m_pParent->m_Value.m_nValue != 0 )
  {
    v2 = (model_t *)pRenderable->GetModel(this: pRenderable);
    origin = pRenderable->GetRenderOrigin(this: pRenderable);
    angles = pRenderable->GetRenderAngles(this: pRenderable);
    v3 = materials->GetRenderContext(this: materials);
    if ( v3 != nullptr )
      v3->BeginRender(this: v3);
    CBrushModelTransform::CBrushModelTransform(this: &brushTransform, origin, angles, pRenderContext: v3);
    CBrushBatchRender::DrawBrushModelShadow(
      this: &g_BrushBatchRenderer,
      a2: (int)v3,
      a3: (int)pRenderable,
      pRenderContext: v3,
      model: v2,
      pRenderable);
    CBrushModelTransform::~CBrushModelTransform(this: &brushTransform, a2: (int)pRenderable);
    if ( v3 != nullptr )
    {
      v3->EndRender(this: v3);
      v3->Release(this: v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D53D0
// Name: public: void CObjectPool<class CWorldRenderList,0,1>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CObjectPool<CWorldRenderList,0,1>::Purge(CObjectPool<CWorldRenderList,0,1> *this)
{
  TSLNodeBase_t *Next; // esi
  int DepthAndSequence; // eax
  int v4; // ebx

  while ( 1 )
  {
    Next = this->m_AvailableObjects.m_Head.value.Next;
    DepthAndSequence = this->m_AvailableObjects.m_Head.value32.DepthAndSequence;
    if ( this->m_AvailableObjects.m_Head.value.Next == nullptr )
      break;
    while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                               a1: this,
                               a2: Next->Next,
                               a3: DepthAndSequence - 1,
                               a4: Next,
                               a5: DepthAndSequence) == 0 )
    {
      _mm_pause();
      Next = this->m_AvailableObjects.m_Head.value.Next;
      DepthAndSequence = this->m_AvailableObjects.m_Head.value32.DepthAndSequence;
      if ( this->m_AvailableObjects.m_Head.value.Next == nullptr )
        return;
    }
    if ( Next == nullptr )
      break;
    v4 = *((_DWORD *)&Next->Next + 1);
    free(pMem: Next);
    if ( v4 != 0 )
      (**(void (__thiscall ***)(int, int))(v4 + 4))(a1: v4 + 4, a2: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D5430
// Name: void Shader_TranslucentWorldSurface(class CWorldRenderList __near *,struct msurface2_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Shader_TranslucentWorldSurface(CWorldRenderList *pRenderList, msurface2_t *surfID)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  unsigned int v4; // ebx
  msurface2_t **m_pMemory; // ecx
  int v6; // eax
  msurface2_t **v7; // edi
  int v8; // edi
  int v9; // eax
  CUtlMemory<S3RGBA,int> *v10; // esi
  S3RGBA *v11; // ecx
  int v12; // eax
  S3RGBA *v13; // edi

  m_nAllocationCount = pRenderList->m_AlphaSurfaces.m_Memory.m_nAllocationCount;
  m_Size = pRenderList->m_AlphaSurfaces.m_Size;
  v4 = (surfID->flags >> 22) & 3;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<INetMessage *,int>::Grow(
      this: (CUtlMemory<S3RGBA,int> *)&pRenderList->m_AlphaSurfaces,
      num: m_Size - m_nAllocationCount + 1);
  ++pRenderList->m_AlphaSurfaces.m_Size;
  m_pMemory = pRenderList->m_AlphaSurfaces.m_Memory.m_pMemory;
  v6 = pRenderList->m_AlphaSurfaces.m_Size - m_Size - 1;
  pRenderList->m_AlphaSurfaces.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &pRenderList->m_AlphaSurfaces.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = surfID;
  if ( (surfID->flags & 0x80400) != 0 )
  {
    v8 = pRenderList->m_DlightSurfaces[v4].m_Size;
    v9 = pRenderList->m_DlightSurfaces[v4].m_Memory.m_nAllocationCount;
    v10 = (CUtlMemory<S3RGBA,int> *)&pRenderList->m_DlightSurfaces[v4];
    if ( v8 + 1 > v9 )
      CUtlMemory<INetMessage *,int>::Grow(this: v10, num: v8 - v9 + 1);
    ++pRenderList->m_DlightSurfaces[v4].m_Size;
    v11 = v10->m_pMemory;
    v12 = pRenderList->m_DlightSurfaces[v4].m_Size - v8 - 1;
    pRenderList->m_DlightSurfaces[v4].m_pElements = pRenderList->m_DlightSurfaces[v4].m_Memory.m_pMemory;
    if ( v12 > 0 )
      _V_memmove(dest: &v11[v8 + 1], src: &v11[v8], count: 4 * v12);
    v13 = &v10->m_pMemory[v8];
    if ( v13 != nullptr )
      *v13 = (S3RGBA)surfID;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D5530
// Name: Shader_WorldSurface
// Source: json
//------------------------------------------------------------------------------
void __cdecl Shader_WorldSurface(CWorldRenderList *pRenderList, msurface2_t *surfID)
{
  msurface2_t *v2; // esi
  unsigned int v3; // ebx
  int m_Size; // edi
  CUtlVector<msurface2_t *,CUtlMemory<msurface2_t *,int> > *v5; // esi
  int m_nAllocationCount; // eax
  msurface2_t **m_pMemory; // ecx
  int v8; // eax
  msurface2_t **v9; // edi
  int v10; // edi
  CUtlVector<msurface2_t *,CUtlMemory<msurface2_t *,int> > *v11; // esi
  int v12; // eax
  msurface2_t **v13; // ecx
  int v14; // eax
  msurface2_t **v15; // edi
  int nMaterialSortID; // [esp+Ch] [ebp-4h]

  v2 = surfID;
  v3 = (surfID->flags >> 22) & 3;
  if ( surfID->decals != 0xFFFF )
    DecalSurfaceAdd(surfID, iGroup: (surfID->flags >> 22) & 3);
  nMaterialSortID = surfID->materialSortID;
  if ( (surfID->flags & 0x80400) != 0 )
  {
    m_Size = pRenderList->m_DlightSurfaces[v3].m_Size;
    v5 = &pRenderList->m_DlightSurfaces[v3];
    m_nAllocationCount = pRenderList->m_DlightSurfaces[v3].m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<INetMessage *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&pRenderList->m_DlightSurfaces[v3],
        num: m_Size - m_nAllocationCount + 1);
    ++pRenderList->m_DlightSurfaces[v3].m_Size;
    m_pMemory = v5->m_Memory.m_pMemory;
    v8 = pRenderList->m_DlightSurfaces[v3].m_Size - m_Size - 1;
    pRenderList->m_DlightSurfaces[v3].m_pElements = pRenderList->m_DlightSurfaces[v3].m_Memory.m_pMemory;
    if ( v8 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
    v9 = &v5->m_Memory.m_pMemory[m_Size];
    if ( v9 != nullptr )
      *v9 = surfID;
    v2 = surfID;
  }
  if ( (v2->flags & 0x200000) != 0 )
  {
    v10 = pRenderList->m_PaintedSurfaces[v3].m_Size;
    v11 = &pRenderList->m_PaintedSurfaces[v3];
    v12 = pRenderList->m_PaintedSurfaces[v3].m_Memory.m_nAllocationCount;
    if ( v10 + 1 > v12 )
      CUtlMemory<INetMessage *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&pRenderList->m_PaintedSurfaces[v3],
        num: v10 - v12 + 1);
    ++pRenderList->m_PaintedSurfaces[v3].m_Size;
    v13 = v11->m_Memory.m_pMemory;
    v14 = pRenderList->m_PaintedSurfaces[v3].m_Size - v10 - 1;
    pRenderList->m_PaintedSurfaces[v3].m_pElements = pRenderList->m_PaintedSurfaces[v3].m_Memory.m_pMemory;
    if ( v14 > 0 )
      _V_memmove(dest: &v13[v10 + 1], src: &v13[v10], count: 4 * v14);
    v15 = &v11->m_Memory.m_pMemory[v10];
    if ( v15 != nullptr )
      *v15 = surfID;
    v2 = surfID;
  }
  CMSurfaceSortList::AddSurfaceToTail(
    this: &pRenderList->m_SortList,
    pSurface: v2,
    sortGroup: v3,
    sortID: nMaterialSortID);
}

//------------------------------------------------------------------------------
// Address: 0x100D5660
// Name: void Shader_TranslucentDisplacementSurface(class CWorldRenderList __near *,struct msurface2_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Shader_TranslucentDisplacementSurface(CWorldRenderList *pRenderList, msurface2_t *surfID)
{
  unsigned int flags; // eax
  int v3; // ecx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlVector<msurface2_t *,CUtlMemory<msurface2_t *,int> > *v6; // esi
  msurface2_t **m_pMemory; // ecx
  int v8; // eax
  msurface2_t **v9; // eax
  int v10; // edi
  int v11; // eax
  msurface2_t **v12; // ecx
  int v13; // eax
  msurface2_t **v14; // eax

  flags = surfID->flags;
  if ( (surfID->flags & 0x80400) != 0 )
  {
    v3 = (flags >> 22) & 3;
    m_Size = pRenderList->m_DlightSurfaces[(flags >> 22) & 3].m_Size;
    m_nAllocationCount = pRenderList->m_DlightSurfaces[(flags >> 22) & 3].m_Memory.m_nAllocationCount;
    v6 = &pRenderList->m_DlightSurfaces[v3];
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<INetMessage *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&pRenderList->m_DlightSurfaces[v3],
        num: m_Size - m_nAllocationCount + 1);
    ++v6->m_Size;
    m_pMemory = v6->m_Memory.m_pMemory;
    v8 = v6->m_Size - m_Size - 1;
    v6->m_pElements = v6->m_Memory.m_pMemory;
    if ( v8 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
    v9 = &v6->m_Memory.m_pMemory[m_Size];
    if ( v9 != nullptr )
      *v9 = surfID;
  }
  v10 = pRenderList->m_AlphaSurfaces.m_Size;
  v11 = pRenderList->m_AlphaSurfaces.m_Memory.m_nAllocationCount;
  if ( v10 + 1 > v11 )
    CUtlMemory<INetMessage *,int>::Grow(
      this: (CUtlMemory<S3RGBA,int> *)&pRenderList->m_AlphaSurfaces,
      num: v10 - v11 + 1);
  ++pRenderList->m_AlphaSurfaces.m_Size;
  v12 = pRenderList->m_AlphaSurfaces.m_Memory.m_pMemory;
  v13 = pRenderList->m_AlphaSurfaces.m_Size - v10 - 1;
  pRenderList->m_AlphaSurfaces.m_pElements = v12;
  if ( v13 > 0 )
    _V_memmove(dest: &v12[v10 + 1], src: &v12[v10], count: 4 * v13);
  v14 = &pRenderList->m_AlphaSurfaces.m_Memory.m_pMemory[v10];
  if ( v14 != nullptr )
    *v14 = surfID;
}

//------------------------------------------------------------------------------
// Address: 0x100D5760
// Name: Shader_DisplacementSurface
// Source: json
//------------------------------------------------------------------------------
void __cdecl Shader_DisplacementSurface(CWorldRenderList *pRenderList, msurface2_t *surfID)
{
  msurface2_t *v2; // edx
  unsigned int v3; // ebx
  CUtlVector<msurface2_t *,CUtlMemory<msurface2_t *,int> > *v4; // esi
  int m_nAllocationCount; // eax
  int m_Size; // edi
  msurface2_t **m_pMemory; // ecx
  int v8; // eax
  msurface2_t **v9; // edi
  int nMaterialSortID; // [esp+4h] [ebp-4h]

  v2 = surfID;
  v3 = (surfID->flags >> 22) & 3;
  nMaterialSortID = surfID->materialSortID;
  if ( (surfID->flags & 0x80400) != 0 )
  {
    v4 = &pRenderList->m_DlightSurfaces[v3];
    m_nAllocationCount = pRenderList->m_DlightSurfaces[v3].m_Memory.m_nAllocationCount;
    m_Size = pRenderList->m_DlightSurfaces[v3].m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
    {
      CUtlMemory<INetMessage *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&pRenderList->m_DlightSurfaces[v3],
        num: m_Size - m_nAllocationCount + 1);
      v2 = surfID;
    }
    ++pRenderList->m_DlightSurfaces[v3].m_Size;
    m_pMemory = v4->m_Memory.m_pMemory;
    v8 = pRenderList->m_DlightSurfaces[v3].m_Size - m_Size - 1;
    pRenderList->m_DlightSurfaces[v3].m_pElements = pRenderList->m_DlightSurfaces[v3].m_Memory.m_pMemory;
    if ( v8 > 0 )
    {
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
      v2 = surfID;
    }
    v9 = &v4->m_Memory.m_pMemory[m_Size];
    if ( v9 != nullptr )
      *v9 = v2;
  }
  CMSurfaceSortList::AddSurfaceToTail(
    this: &pRenderList->m_DispSortList,
    pSurface: v2,
    sortGroup: v3,
    sortID: nMaterialSortID);
}

//------------------------------------------------------------------------------
// Address: 0x100D5800
// Name: AddProjectedTextureDecalsToList
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddProjectedTextureDecalsToList(CWorldRenderList *pRenderList, int nSortGroup)
{
  CWorldRenderList *v2; // ecx
  int v3; // edi
  int v4; // eax
  int v5; // ebx
  const CUtlVector<surfacesortgroup_t *,CUtlMemory<surfacesortgroup_t *,int> > *v6; // esi
  int v7; // edx
  __int16 listHead; // ax
  int v9; // eax
  const materiallist_t *v10; // esi
  msurface2_t *v11; // ebx
  int v12; // eax
  int m_Size; // edi
  CUtlMemory<wchar_t,int> *v14; // esi
  int m_nAllocationCount; // eax
  wchar_t *m_pMemory; // ecx
  int v17; // eax
  wchar_t *v18; // ecx
  wchar_t *v19; // eax
  IOverlayMgr *v20; // eax
  const CUtlVector<surfacesortgroup_t *,CUtlMemory<surfacesortgroup_t *,int> > *_groupList; // [esp+Ch] [ebp-1Ch]
  int _count; // [esp+10h] [ebp-18h]
  int v23; // [esp+14h] [ebp-14h]
  int _listIndex; // [esp+18h] [ebp-10h]
  int _index; // [esp+1Ch] [ebp-Ch]
  const materiallist_t *_pList; // [esp+20h] [ebp-8h]
  msurface2_t **pSurfaces; // [esp+24h] [ebp-4h]

  v2 = pRenderList;
  v3 = nSortGroup;
  v4 = 5 * nSortGroup + 15;
  v5 = *(&pRenderList->m_SortList.m_list.m_Size + v4);
  v6 = (const CUtlVector<surfacesortgroup_t *,CUtlMemory<surfacesortgroup_t *,int> > *)(&pRenderList->m_SortList.m_list.m_Memory.m_pMemory
                                                                                      + v4);
  v7 = 0;
  _groupList = v6;
  _count = v5;
  for ( _listIndex = 0; v7 < v5; _listIndex = v7 )
  {
    listHead = v6->m_Memory.m_pMemory[v7]->listHead;
    if ( listHead != -1 )
    {
      do
      {
        v9 = listHead << 6;
        v10 = (materiallist_t *)((char *)v2->m_SortList.m_list.m_Memory.m_pMemory + v9);
        v23 = v9;
        _pList = v10;
        _index = 0;
        if ( v10->count > 0 )
        {
          pSurfaces = v10->pSurfaces;
          do
          {
            v11 = *pSurfaces;
            if ( (*pSurfaces)->m_ShadowDecals != 0xFFFF && (v11->flags & 0x2000) == 0 )
            {
              v12 = v3;
              m_Size = v2->m_ShadowHandles[v3].m_Size;
              v14 = (CUtlMemory<wchar_t,int> *)&v2->m_ShadowHandles[v12];
              m_nAllocationCount = v2->m_ShadowHandles[v12].m_Memory.m_nAllocationCount;
              if ( m_Size + 1 > m_nAllocationCount )
                CUtlMemory<wchar_t,int>::Grow(this: v14, num: m_Size - m_nAllocationCount + 1);
              ++v14[1].m_pMemory;
              m_pMemory = v14->m_pMemory;
              v17 = (int)v14[1].m_pMemory - m_Size - 1;
              v14[1].m_nAllocationCount = (int)v14->m_pMemory;
              if ( v17 > 0 )
                _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 2 * v17);
              v18 = v14->m_pMemory;
              v10 = _pList;
              v19 = &v18[m_Size];
              v3 = nSortGroup;
              if ( v19 != nullptr )
                *v19 = v11->m_ShadowDecals;
            }
            if ( v11->m_nFirstOverlayFragment != 0xFFFF )
            {
              v20 = OverlayMgr();
              v20->AddFragmentListToRenderList(this: v20, a2: v3, a3: v11->m_nFirstOverlayFragment, a4: false);
            }
            ++pSurfaces;
            v2 = pRenderList;
            ++_index;
          }
          while ( _index < v10->count );
          v9 = v23;
        }
        listHead = *(_WORD *)((char *)&v2->m_SortList.m_list.m_Memory.m_pMemory->nextBlock + v9);
      }
      while ( listHead != -1 );
      v5 = _count;
      v6 = _groupList;
      v7 = _listIndex;
    }
    ++v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D5960
// Name: Shader_DrawWorldDecalsAndOverlays
// Source: json
//------------------------------------------------------------------------------
void __usercall Shader_DrawWorldDecalsAndOverlays(
        IMatRenderContext *pRenderContext@<edi>,
        CWorldRenderList *pRenderList,
        unsigned int flags,
        float waterZAdjust)
{
  int *v4; // eax
  int v5; // esi
  char *v6; // eax
  int i; // ebx
  IOverlayMgr *v8; // eax
  IOverlayMgr *v9; // eax
  char *v10; // [esp+14h] [ebp-10h]
  bool v11; // [esp+18h] [ebp-Ch]
  int v12; // [esp+20h] [ebp-4h]

  v4 = (int *)&args.m_pArgSBuffer[200];
  v12 = 8;
  v10 = &args.m_pArgSBuffer[200];
  do
  {
    if ( (flags & v12) != 0 )
    {
      v5 = *v4;
      if ( *v4 == 3 && waterZAdjust != 0.0 )
      {
        pRenderContext->MatrixMode(this: pRenderContext, a2: MATERIAL_MODEL);
        pRenderContext->PushMatrix(this: pRenderContext);
        pRenderContext->LoadIdentity(this: pRenderContext);
        ((void (__thiscall *)(IMatRenderContext *, _DWORD, _DWORD, _DWORD))pRenderContext->Translate)(
          a1: pRenderContext,
          a2: 0.0,
          a3: 0.0,
          a4: LODWORD(waterZAdjust));
      }
      Shader_DrawDispChainDecalsAndOverlays(pRenderContext, nSortGroup: v5, list: &pRenderList->m_DispSortList, flags);
      AddProjectedTextureDecalsToList(pRenderList, nSortGroup: v5);
      v6 = (char *)pRenderList + 20 * v5;
      for ( i = *((_DWORD *)v6 + 107) - 1; i >= 0; v6 = (char *)pRenderList + 20 * v5 )
        g_pShadowMgr->AddShadowsOnSurfaceToRenderList(
          this: g_pShadowMgr,
          a2: *(unsigned __int16 *)(*((_DWORD *)v6 + 104) + 2 * i--));
      *((_DWORD *)v6 + 107) = 0;
      if ( (flags & 0x80u) != 0 || (v11 = true, (flags & 0x100) != 0) )
        v11 = false;
      g_pShadowMgr->SetFlashlightStencilMasks(this: g_pShadowMgr, a2: v11);
      g_pShadowMgr->RenderFlashlights(this: g_pShadowMgr, a2: v11, a3: false, a4: nullptr);
      v8 = OverlayMgr();
      v8->RenderOverlays(this: v8, a2: pRenderContext, a3: v5);
      g_pShadowMgr->DrawFlashlightOverlays(this: g_pShadowMgr, a2: pRenderContext, a3: v5, a4: v11);
      v9 = OverlayMgr();
      v9->ClearRenderLists(this: v9, a2: v5);
      DecalSurfaceDraw(pRenderContext, renderGroup: v5, flFade: 1.0);
      ((void (__thiscall *)(IShadowMgrInternal *, IMatRenderContext *, int, bool, _DWORD))g_pShadowMgr->DrawFlashlightDecals)(
        a1: g_pShadowMgr,
        a2: pRenderContext,
        a3: v5,
        a4: v11,
        a5: 1.0);
      g_pShadowMgr->RenderFlashlights(this: g_pShadowMgr, a2: v11, a3: true, a4: nullptr);
      R_DecalFlushDestroyList();
      g_pShadowMgr->RenderShadows(this: g_pShadowMgr, a2: pRenderContext, a3: nullptr);
      g_pShadowMgr->ClearShadowRenderList(this: g_pShadowMgr);
      if ( v5 == 3 && waterZAdjust != 0.0 )
      {
        pRenderContext->MatrixMode(this: pRenderContext, a2: MATERIAL_MODEL);
        pRenderContext->PopMatrix(this: pRenderContext);
      }
    }
    v4 = (int *)(v10 - 4);
    v10 = (char *)v4;
    v12 = __ROR4__(v12, 1);
  }
  while ( (int)v4 >= (int)&args.m_pArgSBuffer[188] );
}

//------------------------------------------------------------------------------
// Address: 0x100D5B60
// Name: DrawDisplacementsInLeaf
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawDisplacementsInLeaf(CWorldRenderList *pRenderList, mleaf_t *pLeaf)
{
  mleaf_t *v2; // ecx
  int v3; // eax
  IDispInfo *v4; // eax
  msurface2_t *v5; // edi
  int v6; // esi
  unsigned int *v7; // edx
  bool v8; // bl
  int i; // [esp+0h] [ebp-4h]

  v2 = pLeaf;
  if ( pLeaf->dispCount != 0 )
  {
    v3 = 0;
    i = 0;
    do
    {
      v4 = DispInfo_IndexArray(
             hArray: (_DWORD *)host_state.worldbrush->hDispInfos,
             iElement: host_state.worldbrush->m_pDispInfoReferences[v3 + v2->dispListStart]);
      v5 = (msurface2_t *)v4[91].__vftable;
      v6 = 1 << ((v5 - host_state.worldbrush->surfaces2) & 0x1F);
      v7 = &pRenderList->m_VisitedSurfs.m_bits.m_pInt[((char *)v5 - (char *)host_state.worldbrush->surfaces2) >> 10];
      v8 = (*v7 & v6) != 0;
      *v7 |= v6;
      if ( !v8 && Frustum_t::CullBox(this: &g_Frustum, mins: (const Vector *)&v4[2], maxs: (const Vector *)&v4[5]) == 0 )
      {
        if ( (v5->flags & 0x20) != 0 )
          Shader_TranslucentDisplacementSurface(pRenderList, surfID: v5);
        else
          Shader_DisplacementSurface(pRenderList, surfID: v5);
      }
      v2 = pLeaf;
      v3 = i + 1;
      i = v3;
    }
    while ( v3 < pLeaf->dispCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D5C40
// Name: UpdateVisibleLeafLists
// Source: json
//------------------------------------------------------------------------------
void __cdecl UpdateVisibleLeafLists(CWorldRenderList *pRenderList, mleaf_t *pLeaf)
{
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  int v4; // edi
  WorldListLeafData_t *m_pMemory; // ecx
  int v6; // eax
  WorldListLeafData_t *v7; // eax
  __int16 leafWaterDataID; // cx

  m_Size = pRenderList->m_leaves.m_Size;
  m_nAllocationCount = pRenderList->m_leaves.m_Memory.m_nAllocationCount;
  v4 = pLeaf - host_state.worldbrush->leafs;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CAsyncWavDataCache::DeadBufferEntry_t,int>::Grow(
      this: (CUtlMemory<ResourceEntryInfo,int> *)&pRenderList->m_leaves,
      num: m_Size - m_nAllocationCount + 1);
  ++pRenderList->m_leaves.m_Size;
  m_pMemory = pRenderList->m_leaves.m_Memory.m_pMemory;
  v6 = pRenderList->m_leaves.m_Size - m_Size - 1;
  pRenderList->m_leaves.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 8 * v6);
  v7 = &pRenderList->m_leaves.m_Memory.m_pMemory[m_Size];
  leafWaterDataID = pLeaf->leafWaterDataID;
  v7->firstTranslucentSurface = pRenderList->m_AlphaSurfaces.m_Size;
  v7->leafIndex = v4;
  v7->translucentSurfaceCount = 0;
  v7->waterData = leafWaterDataID;
  if ( leafWaterDataID != -1 )
    pRenderList->m_bWaterVisible = true;
}

//------------------------------------------------------------------------------
// Address: 0x100D5CF0
// Name: R_DrawLeaf
// Source: json
//------------------------------------------------------------------------------
void __stdcall R_DrawLeaf(CWorldRenderList *pRenderLista, mleaf_t *pleafa)
{
  mleaf_t *v4; // ebx
  CWorldRenderList *v5; // edi
  int nummarknodesurfaces; // edx
  int v7; // esi
  unsigned int *v8; // eax
  int v9; // ebx
  msurface2_t *v10; // ebx
  int v11; // edx
  unsigned int *v12; // esi
  bool v13; // cl
  unsigned int v14; // ecx
  int v15; // edx
  CUtlMemory<S3RGBA,int> *v16; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  S3RGBA *m_pMemory; // ecx
  int v20; // eax
  msurface2_t **v21; // eax
  int v22; // eax
  CUtlMemory<S3RGBA,int> *m_PaintedSurfaces; // esi
  int v24; // edi
  S3RGBA *v25; // ecx
  int v26; // eax
  msurface2_t **v27; // eax
  int v28; // eax
  CUtlMemory<S3RGBA,int> *p_m_AlphaSurfaces; // esi
  int v30; // edi
  S3RGBA *v31; // ecx
  int v32; // eax
  msurface2_t **v33; // eax
  msurface2_t **pSurfID; // [esp+8h] [ebp-10h]
  int i; // [esp+Ch] [ebp-Ch]
  unsigned int flags; // [esp+10h] [ebp-8h]
  int sortGroup; // [esp+14h] [ebp-4h]

  v4 = pleafa;
  v5 = pRenderLista;
  pSurfID = &host_state.worldbrush->marksurfaces[pleafa->firstmarksurface];
  UpdateVisibleLeafLists(pRenderList: pRenderLista, pLeaf: pleafa);
  if ( s_ShaderConvars.m_nDrawLeaf < 0 || s_ShaderConvars.m_nDrawLeaf == pleafa - host_state.worldbrush->leafs )
  {
    DrawDisplacementsInLeaf(pRenderList: pRenderLista, pLeaf: pleafa);
    if ( s_ShaderConvars.m_bDrawWorld )
    {
      nummarknodesurfaces = pleafa->nummarknodesurfaces;
      v7 = 0;
      i = 0;
      if ( nummarknodesurfaces > 0 )
      {
        do
        {
          v8 = &pRenderLista->m_VisitedSurfs.m_bits.m_pInt[((char *)pSurfID[v7]
                                                          - (char *)host_state.worldbrush->surfaces2) >> 10];
          v9 = 1 << ((pSurfID[v7++] - host_state.worldbrush->surfaces2) & 0x1F);
          *v8 |= v9;
        }
        while ( v7 < nummarknodesurfaces );
        v4 = pleafa;
        i = v7;
      }
      if ( s_ShaderConvars.m_bDrawFuncDetail && v7 < v4->nummarksurfaces )
      {
        while ( 1 )
        {
          v10 = pSurfID[v7];
          v11 = 1 << ((v10 - host_state.worldbrush->surfaces2) & 0x1F);
          v12 = &v5->m_VisitedSurfs.m_bits.m_pInt[((char *)v10 - (char *)host_state.worldbrush->surfaces2) >> 10];
          v13 = (*v12 & v11) != 0;
          *v12 |= v11;
          if ( !v13 )
          {
            v14 = v10->flags;
            flags = v10->flags;
            if ( (v10->flags & 0x200) != 0
              || (float)((float)((float)((float)(v10->plane->normal.y * modelorg.y)
                                       + (float)(v10->plane->normal.x * modelorg.x))
                               + (float)(v10->plane->normal.z * modelorg.z))
                       - v10->plane->dist) >= -0.0099999998 )
            {
              v15 = (v14 >> 22) & 3;
              sortGroup = v15;
              if ( (v14 & 0x80400) != 0 )
              {
                v16 = (CUtlMemory<S3RGBA,int> *)&v5->m_DlightSurfaces[v15];
                m_Size = v5->m_DlightSurfaces[v15].m_Size;
                m_nAllocationCount = v16->m_nAllocationCount;
                if ( m_Size + 1 > m_nAllocationCount )
                {
                  CUtlMemory<INetMessage *,int>::Grow(this: v16, num: m_Size - m_nAllocationCount + 1);
                  v15 = sortGroup;
                }
                ++v16[1].m_pMemory;
                m_pMemory = v16->m_pMemory;
                v20 = (int)v16[1].m_pMemory - m_Size - 1;
                v16[1].m_nAllocationCount = (int)v16->m_pMemory;
                if ( v20 > 0 )
                {
                  _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v20);
                  v15 = sortGroup;
                }
                v21 = (msurface2_t **)&v16->m_pMemory[m_Size];
                v5 = pRenderLista;
                v14 = flags;
                if ( v21 != nullptr )
                  *v21 = v10;
              }
              if ( (v14 & 0x200000) != 0 )
              {
                v22 = v5->m_PaintedSurfaces[0].m_Memory.m_nAllocationCount;
                m_PaintedSurfaces = (CUtlMemory<S3RGBA,int> *)v5->m_PaintedSurfaces;
                v24 = v5->m_PaintedSurfaces[0].m_Size;
                if ( v24 + 1 > v22 )
                {
                  CUtlMemory<INetMessage *,int>::Grow(this: m_PaintedSurfaces, num: v24 - v22 + 1);
                  v15 = sortGroup;
                }
                ++m_PaintedSurfaces[1].m_pMemory;
                v25 = m_PaintedSurfaces->m_pMemory;
                v26 = (int)m_PaintedSurfaces[1].m_pMemory - v24 - 1;
                m_PaintedSurfaces[1].m_nAllocationCount = (int)m_PaintedSurfaces->m_pMemory;
                if ( v26 > 0 )
                {
                  _V_memmove(dest: &v25[v24 + 1], src: &v25[v24], count: 4 * v26);
                  v15 = sortGroup;
                }
                v27 = (msurface2_t **)&m_PaintedSurfaces->m_pMemory[v24];
                v5 = pRenderLista;
                LOBYTE(v14) = flags;
                if ( v27 != nullptr )
                  *v27 = v10;
              }
              if ( (v14 & 0x20) != 0 )
              {
                v28 = v5->m_AlphaSurfaces.m_Memory.m_nAllocationCount;
                p_m_AlphaSurfaces = (CUtlMemory<S3RGBA,int> *)&v5->m_AlphaSurfaces;
                v30 = v5->m_AlphaSurfaces.m_Size;
                if ( v30 + 1 > v28 )
                  CUtlMemory<INetMessage *,int>::Grow(this: p_m_AlphaSurfaces, num: v30 - v28 + 1);
                ++p_m_AlphaSurfaces[1].m_pMemory;
                v31 = p_m_AlphaSurfaces->m_pMemory;
                v32 = (int)p_m_AlphaSurfaces[1].m_pMemory - v30 - 1;
                p_m_AlphaSurfaces[1].m_nAllocationCount = (int)p_m_AlphaSurfaces->m_pMemory;
                if ( v32 > 0 )
                  _V_memmove(dest: &v31[v30 + 1], src: &v31[v30], count: 4 * v32);
                v33 = (msurface2_t **)&p_m_AlphaSurfaces->m_pMemory[v30];
                v5 = pRenderLista;
                if ( v33 != nullptr )
                  *v33 = v10;
              }
              else
              {
                if ( v10->decals != 0xFFFF )
                {
                  DecalSurfaceAdd(surfID: v10, iGroup: v15);
                  v15 = sortGroup;
                }
                CMSurfaceSortList::AddSurfaceToTail(
                  this: &v5->m_SortList,
                  pSurface: v10,
                  sortGroup: v15,
                  sortID: v10->materialSortID);
              }
            }
          }
          if ( ++i >= pleafa->nummarksurfaces )
            break;
          v7 = i;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D5FD0
// Name: R_BuildWorldListNoCull
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_BuildWorldListNoCull(CWorldRenderList *pRenderList)
{
  mnode_t *node; // ecx
  mnode_t *v2; // esi
  int v3; // ecx
  int v4; // edi
  int v5; // ebx
  bool v6; // al
  mleaf_t *v7; // eax
  mleaf_t *v8; // edi
  CWorldRenderList *v9; // esi
  int v10; // ebx
  msurface2_t *v11; // edi
  int v12; // edx
  unsigned int *v13; // esi
  bool v14; // cl
  mleaf_t *pLeaf[2048]; // [esp+Ch] [ebp-2010h]
  mleaf_t *v16; // [esp+200Ch] [ebp-10h]
  msurface2_t **v17; // [esp+2010h] [ebp-Ch]
  int v18; // [esp+2014h] [ebp-8h]
  int v19; // [esp+2018h] [ebp-4h]

  v2 = node;
  v3 = 0;
  v4 = 0;
  v19 = 0;
  v5 = 0;
  while ( 1 )
  {
    while ( 1 )
    {
      if ( v2->contents == 1 )
        goto LABEL_9;
      if ( v2->visframe != r_visframecount )
        goto LABEL_9;
      if ( v2->contents >= -1 )
      {
        v6 = R_CullNode(pNode: v2);
        v3 = v19;
        if ( v6 )
          goto LABEL_9;
      }
      if ( v2->contents >= 0 )
        break;
      v7 = (mleaf_t *)v2->children[0];
      v2 = v2->children[1];
      pLeaf[v5 + 1024] = v7;
      v5 = ((_WORD)v5 + 1) & 0x3FF;
    }
    if ( v3 < 1024 )
    {
      pLeaf[v3++] = (mleaf_t *)v2;
      v19 = v3;
    }
LABEL_9:
    if ( v4 == v5 )
      break;
    v2 = (mnode_t *)pLeaf[v4 + 1024];
    v4 = ((_WORD)v4 + 1) & 0x3FF;
  }
  v18 = 0;
  if ( v3 > 0 )
  {
    do
    {
      v9 = pRenderList;
      v16 = pLeaf[v18];
      v8 = v16;
      UpdateVisibleLeafLists(pRenderList, pLeaf: v16);
      DrawDisplacementsInLeaf(pRenderList, pLeaf: v8);
      v10 = 0;
      v17 = &host_state.worldbrush->marksurfaces[v8->firstmarksurface];
      if ( v8->nummarksurfaces != 0 )
      {
        while ( 1 )
        {
          v11 = v17[v10];
          v12 = 1 << ((v11 - host_state.worldbrush->surfaces2) & 0x1F);
          v13 = &v9->m_VisitedSurfs.m_bits.m_pInt[((char *)v11 - (char *)host_state.worldbrush->surfaces2) >> 10];
          v14 = (*v13 & v12) != 0;
          *v13 |= v12;
          if ( !v14 && (v11->flags & 0x24) == 0 )
            CMSurfaceSortList::AddSurfaceToTail(
              this: &pRenderList->m_SortList,
              pSurface: v11,
              sortGroup: (v11->flags >> 22) & 3,
              sortID: v11->materialSortID);
          if ( ++v10 >= v16->nummarksurfaces )
            break;
          v9 = pRenderList;
        }
      }
      ++v18;
    }
    while ( v18 < v19 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D6140
// Name: R_RecursiveWorldNode
// Source: json
//------------------------------------------------------------------------------
void __fastcall R_RecursiveWorldNode(CWorldRenderList *pRenderList, mnode_t *node)
{
  mnode_t *v2; // ebx
  int contents; // eax
  CWorldRenderList *v4; // esi
  cplane_t *plane; // eax
  unsigned __int8 type; // cl
  float v7; // xmm0_4
  msurface2_t *v8; // edi
  int v9; // esi
  int v10; // eax
  int v11; // ebx
  unsigned int flags; // ecx
  int nLastSurface; // [esp+8h] [ebp-10h]
  mnode_t *v14; // [esp+Ch] [ebp-Ch]
  BOOL side; // [esp+10h] [ebp-8h]

  v2 = node;
  contents = node->contents;
  v4 = pRenderList;
  v14 = node;
  if ( node->contents != 1 )
  {
    while ( v2->visframe == r_visframecount && (contents < -1 || !R_CullNode(pNode: v2)) )
    {
      if ( v2->contents >= 0 )
      {
        R_DrawLeaf(pRenderLista: v4, pleafa: (mleaf_t *)v2);
        return;
      }
      plane = v2->plane;
      type = plane->type;
      if ( type > 2u )
        v7 = (float)((float)(plane->normal.y * modelorg.y) + (float)(plane->normal.x * modelorg.x))
           + (float)(plane->normal.z * modelorg.z);
      else
        v7 = *(&modelorg.x + type);
      side = (float)(v7 - plane->dist) < 0.0;
      R_RecursiveWorldNode(pRenderList: v4, node: v2->children[side]);
      v8 = &host_state.worldbrush->surfaces2[v2->firstsurface];
      v9 = (32 * v2->firstsurface) >> 5;
      v10 = v9 + v2->numsurfaces;
      v11 = __ROL4__(1, v9);
      nLastSurface = v10;
      if ( v9 < (unsigned int)v10 )
      {
        do
        {
          if ( (v11 & pRenderList->m_VisitedSurfs.m_bits.m_pInt[v9 >> 5]) != 0 )
          {
            flags = v8->flags;
            if ( (v8->flags & 0x20000) != 0 || side == ((v8->flags & 0x40) != 0) )
            {
              if ( (flags & 4) != 0 )
              {
                pRenderList->m_bSkyVisible = true;
              }
              else
              {
                if ( (flags & 0x20) != 0 )
                  Shader_TranslucentWorldSurface(pRenderList, surfID: v8);
                else
                  Shader_WorldSurface(pRenderList, surfID: v8);
                v10 = nLastSurface;
              }
            }
          }
          ++v9;
          v11 = __ROL4__(v11, 1);
          ++v8;
        }
        while ( v9 < v10 );
      }
      v14 = v14->children[!side];
      contents = v14->contents;
      if ( v14->contents == 1 )
        return;
      v2 = v14;
      v4 = pRenderList;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D62D0
// Name: R_DrawTopViewLeaf
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_DrawTopViewLeaf(CWorldRenderList *pRenderList, mleaf_t *pleaf)
{
  CWorldRenderList *v2; // esi
  int v3; // ebx
  msurface2_t *v4; // edi
  int v5; // edx
  unsigned int *v6; // esi
  bool v7; // cl
  unsigned int flags; // eax
  msurface2_t **pHandle; // [esp+8h] [ebp-4h]

  v2 = pRenderList;
  UpdateVisibleLeafLists(pRenderList, pLeaf: pleaf);
  DrawDisplacementsInLeaf(pRenderList, pLeaf: pleaf);
  if ( s_ShaderConvars.m_bDrawWorld )
  {
    v3 = 0;
    pHandle = &host_state.worldbrush->marksurfaces[pleaf->firstmarksurface];
    if ( pleaf->nummarksurfaces != 0 )
    {
      while ( 1 )
      {
        v4 = pHandle[v3];
        v5 = 1 << ((v4 - host_state.worldbrush->surfaces2) & 0x1F);
        v6 = &v2->m_VisitedSurfs.m_bits.m_pInt[((char *)v4 - (char *)host_state.worldbrush->surfaces2) >> 10];
        v7 = (*v6 & v5) != 0;
        *v6 |= v5;
        if ( !v7 )
        {
          flags = v4->flags;
          if ( (v4->flags & 0x800) == 0
            && (flags & 2) == 0
            && ((flags & 0x200) != 0 || v4->plane->normal.z > 0.0)
            && (flags & 0x20) == 0 )
          {
            Shader_WorldSurface(pRenderList, surfID: v4);
          }
        }
        if ( ++v3 >= pleaf->nummarksurfaces )
          break;
        v2 = pRenderList;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D63B0
// Name: R_RenderWorldTopView
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_RenderWorldTopView(CWorldRenderList *pRenderList, int node)
{
  msurface2_t *v3; // edi
  int v4; // edx
  unsigned int *v5; // esi
  bool v6; // cl
  unsigned int flags; // eax
  int i; // [esp+28h] [ebp+Ch]

  while ( *(_DWORD *)node != 1
       && *(_DWORD *)(node + 4) == r_visframecount
       && fabs(*(float *)(node + 16) - s_OrthographicCenter.x) <= *(float *)(node + 32) + s_OrthographicHalfDiagonal.x
       && fabs((float)(*(float *)(node + 20) - s_OrthographicCenter.y)) <= (float)(*(float *)(node + 36)
                                                                                 + s_OrthographicHalfDiagonal.y) )
  {
    if ( *(int *)node >= 0 )
    {
      R_DrawTopViewLeaf(pRenderList, pleaf: (mleaf_t *)node);
      return;
    }
    if ( s_ShaderConvars.m_bDrawWorld )
    {
      v3 = &host_state.worldbrush->surfaces2[*(unsigned __int16 *)(node + 60)];
      i = 0;
      if ( *(_WORD *)(node + 62) != 0 )
      {
        do
        {
          v4 = 1 << ((v3 - host_state.worldbrush->surfaces2) & 0x1F);
          v5 = &pRenderList->m_VisitedSurfs.m_bits.m_pInt[((char *)v3 - (char *)host_state.worldbrush->surfaces2) >> 10];
          v6 = (*v5 & v4) != 0;
          *v5 |= v4;
          if ( !v6 )
          {
            flags = v3->flags;
            if ( (v3->flags & 0x800) == 0
              && (flags & 0x20004) == 0
              && ((flags & 0x200) != 0 || v3->plane->normal.z > 0.0)
              && (flags & 0x20) == 0 )
            {
              Shader_WorldSurface(pRenderList, surfID: v3);
            }
          }
          ++v3;
          ++i;
        }
        while ( i < *(unsigned __int16 *)(node + 62) );
      }
    }
    R_RenderWorldTopView(pRenderList, node: *(mnode_t **)(node + 52));
    node = *(_DWORD *)(node + 56);
    if ( node == 0 )
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D6530
// Name: void R_BuildWorldLists(class IWorldRenderList __near *,struct WorldListInfo_t __near *,int,struct VisOverrideData_t const __near *,bool,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_BuildWorldLists(
        CWorldRenderList *pRenderListIn,
        WorldListInfo_t *pInfo,
        int iForceViewLeaf,
        const VisOverrideData_t *pVisData,
        bool bShadowDepth,
        float *pWaterReflectionHeight)
{
  FogVolumeInfo_t fogInfo; // [esp+0h] [ebp-2Ch] BYREF

  if ( g_LostVideoMemory )
  {
    if ( pInfo != nullptr )
    {
      pInfo->m_ViewFogVolume = 0;
      pInfo->m_LeafCount = 0;
      pInfo->m_pLeafDataList = pRenderListIn->m_leaves.m_Memory.m_pMemory;
      pInfo->m_bHasWater = pRenderListIn->m_bWaterVisible;
    }
  }
  else
  {
    modelorg = *g_EngineRenderer->ViewOrigin(this: g_EngineRenderer);
    Shader_WorldBegin(pRenderList: pRenderListIn);
    if ( r_drawtopview )
    {
      R_RenderWorldTopView(pRenderList: pRenderListIn, node: (int)host_state.worldbrush->nodes);
    }
    else
    {
      R_SetupAreaBits(iForceViewLeaf, pVisData, pWaterReflectionHeight);
      if ( bShadowDepth )
        R_BuildWorldListNoCull(pRenderList: pRenderListIn);
      else
        R_RecursiveWorldNode(pRenderList: pRenderListIn, node: host_state.worldbrush->nodes);
    }
    CWorldRenderList::CountTranslucentSurfaces(this: pRenderListIn);
    if ( !r_drawtopview && !bShadowDepth )
      Shader_BuildDynamicLightmaps(pRenderList: pRenderListIn);
    if ( pInfo != nullptr )
    {
      if ( bShadowDepth )
      {
        pInfo->m_ViewFogVolume = 0;
      }
      else
      {
        ComputeFogVolumeInfo(pFogVolume: &fogInfo);
        pInfo->m_ViewFogVolume = fogInfo.m_InFogVolume;
      }
      pInfo->m_LeafCount = pRenderListIn->m_leaves.m_Size;
      pInfo->m_pLeafDataList = pRenderListIn->m_leaves.m_Memory.m_pMemory;
      pInfo->m_bHasWater = pRenderListIn->m_bWaterVisible;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D6680
// Name: R_DrawBrushModel_Override
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_DrawBrushModel_Override(IMatRenderContext *pRenderContext, IClientEntity *baseentity, model_t *model)
{
  msurface2_t *v3; // esi
  msurface2_t **m_pMemory; // edi
  IMatRenderContext_vtbl *v5; // edx
  void (__thiscall *BindLightmapPage)(IMatRenderContext *, int); // eax
  char v7; // al
  int v8; // ecx
  int m_Size; // esi
  int v10; // ebx
  int *v11; // ebx
  _DWORD v12[2]; // [esp+Ch] [ebp-48h] BYREF
  SurfaceCtx_t ctx; // [esp+14h] [ebp-40h] BYREF
  CUtlVector<msurface2_t *,CUtlMemory<msurface2_t *,int> > surfaceList; // [esp+38h] [ebp-1Ch] BYREF
  int j; // [esp+4Ch] [ebp-8h]
  int i; // [esp+50h] [ebp-4h]

  v3 = (msurface2_t *)(*(_DWORD *)(model->sprite.numframes + 124) + 32 * model->brush.firstmodelsurface);
  m_pMemory = nullptr;
  i = 0;
  if ( model->brush.nummodelsurfaces > 0 )
  {
    do
    {
      v5 = pRenderContext->__vftable;
      if ( g_pMaterialSystemConfig->nFullbright == 1 )
      {
        BindLightmapPage = v5->BindLightmapPage;
        if ( (v3->flags & 8) != 0 )
          ((void (__stdcall *)(int))BindLightmapPage)(a1: -2);
        else
          ((void (__stdcall *)(int))BindLightmapPage)(a1: -1);
      }
      else
      {
        ((void (__stdcall *)(int))v5->BindLightmapPage)(a1: materialSortInfoArray[v3->materialSortID].lightmapPageID);
      }
      v12[0] = &args.m_pArgSBuffer[424];
      v12[1] = v3;
      SurfSetupSurfaceContext(&ctx, surfID: v3);
      v7 = s_pBrushRenderOverride->RenderBrushModelSurface(
             this: s_pBrushRenderOverride,
             a2: baseentity,
             a3: (IBrushSurface *)v12);
      if ( v3->decals != 0xFFFF && v7 != 0 )
        DecalSurfaceAdd(surfID: v3, iGroup: 4);
      if ( v3->m_ShadowDecals != 0xFFFF )
        g_pShadowMgr->AddShadowsOnSurfaceToRenderList(this: g_pShadowMgr, a2: v3->m_ShadowDecals);
      ++v3;
      ++i;
    }
    while ( i < model->brush.nummodelsurfaces );
    m_pMemory = nullptr;
  }
  if ( g_ShaderDebug.anydebug )
  {
    v8 = *(_DWORD *)(model->sprite.numframes + 124) + 32 * model->brush.firstmodelsurface;
    m_Size = 0;
    memset(&surfaceList, 0, sizeof(surfaceList));
    i = v8;
    for ( j = 0; j < model->brush.nummodelsurfaces; i = v8 )
    {
      v10 = m_Size;
      if ( m_Size + 1 > surfaceList.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<INetMessage *,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)&surfaceList,
          num: m_Size - surfaceList.m_Memory.m_nAllocationCount + 1);
        m_Size = surfaceList.m_Size;
        m_pMemory = surfaceList.m_Memory.m_pMemory;
        v8 = i;
      }
      surfaceList.m_Size = ++m_Size;
      surfaceList.m_pElements = m_pMemory;
      if ( m_Size - v10 - 1 > 0 )
      {
        _V_memmove(dest: &m_pMemory[v10 + 1], src: &m_pMemory[v10], count: 4 * (m_Size - v10 - 1));
        v8 = i;
      }
      v11 = (int *)&m_pMemory[v10];
      if ( v11 != nullptr )
        *v11 = v8;
      v8 += 32;
      ++j;
    }
    DrawDebugInformation(pRenderContext, pList: m_pMemory, listCount: m_Size);
    if ( surfaceList.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D6840
// Name: void R_DrawBrushModel(class IClientEntity __near *,struct model_t __near *,class matrix3x4a_t const __near &,bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_DrawBrushModel(
        IClientEntity *baseentity,
        model_t *model,
        const matrix3x4a_t *brushModelToWorld,
        bool bShadowDepth,
        bool bDrawOpaque,
        bool bDrawTranslucent)
{
  int m_nValue; // eax
  IMatRenderContext *v7; // eax
  IMatRenderContext *v8; // esi
  CBrushModelTransform brushTransform; // [esp+0h] [ebp-14h] BYREF
  bool bWireframe; // [esp+13h] [ebp-1h]

  if ( r_drawbrushmodels.m_pParent != nullptr )
  {
    m_nValue = r_drawbrushmodels.m_pParent->m_Value.m_nValue;
    if ( m_nValue != 0 )
    {
      bWireframe = false;
      if ( m_nValue == 2 )
      {
        bWireframe = g_ShaderDebug.wireframe;
        g_ShaderDebug.wireframe = true;
        g_ShaderDebug.anydebug = true;
      }
      v7 = materials->GetRenderContext(this: materials);
      v8 = v7;
      if ( v7 != nullptr )
        v7->BeginRender(this: v7);
      CBrushModelTransform::CBrushModelTransform(this: &brushTransform, matrix: brushModelToWorld, pRenderContext: v8);
      DecalSurfacesInit(bBrushModel: true);
      g_pShadowMgr->ClearShadowRenderList(this: g_pShadowMgr);
      if ( s_pBrushRenderOverride != nullptr )
      {
        R_DrawBrushModel_Override(pRenderContext: v8, baseentity, model);
      }
      else if ( (model->flags & 2) != 0 )
      {
        if ( !bShadowDepth )
          CBrushBatchRender::DrawTranslucentBrushModel(
            this: &g_BrushBatchRenderer,
            pRenderContext: v8,
            baseentity,
            model,
            bShadowDepth: false,
            bDrawOpaque,
            bDrawTranslucent);
      }
      else if ( bDrawOpaque )
      {
        CBrushBatchRender::DrawOpaqueBrushModel(
          this: &g_BrushBatchRenderer,
          a2: (CMeshBuilder *)model,
          pRenderContext: v8,
          baseentity,
          model,
          bShadowDepth);
      }
      Shader_BrushEnd(
        pRenderContext: v8,
        pBrushToWorld: brushTransform.m_bIdentity ? nullptr : &g_BrushToWorldMatrix,
        (IMatRenderContext *)model,
        bShadowDepth);
      if ( r_drawbrushmodels.m_pParent != nullptr && r_drawbrushmodels.m_pParent->m_Value.m_nValue == 2 )
      {
        g_ShaderDebug.wireframe = bWireframe;
        if ( bWireframe
          || g_ShaderDebug.normals
          || g_ShaderDebug.luxels != bWireframe
          || g_ShaderDebug.bumpBasis != bWireframe
          || g_ShaderDebug.surfaceid != 0
          || (g_ShaderDebug.anydebug = bWireframe, g_ShaderDebug.surfacematerials != bWireframe) )
        {
          g_ShaderDebug.anydebug = true;
        }
      }
      CBrushModelTransform::~CBrushModelTransform(this: &brushTransform, a2: (int)v8);
      if ( v8 != nullptr )
      {
        v8->EndRender(this: v8);
        v8->Release(this: v8);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D69C0
// Name: void R_DrawBrushModel(class IClientEntity __near *,struct model_t __near *,class Vector const __near &,class QAngle const __near &,bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall R_DrawBrushModel(
        unsigned int a1@<ebp>,
        IClientEntity *baseentity,
        model_t *model,
        const Vector *origin,
        const QAngle *angles,
        bool bShadowDepth,
        bool bDrawOpaque,
        bool bDrawTranslucent)
{
  _BYTE v8[12]; // [esp-Ch] [ebp-3Ch] BYREF
  matrix3x4a_t mat; // [esp+0h] [ebp-30h]
  unsigned int retaddr; // [esp+30h] [ebp+0h]

  *(_QWORD *)&mat.m_flMatVal[2][1] = __PAIR64__(retaddr, a1);
  AngleMatrix(angles, position: origin, matrix: (matrix3x4_t *)v8);
  R_DrawBrushModel(
    baseentity,
    model,
    brushModelToWorld: (const matrix3x4a_t *)v8,
    bShadowDepth,
    bDrawOpaque,
    bDrawTranslucent);
}

//------------------------------------------------------------------------------
// Address: 0x100D6A20
// Name: void R_DrawIdentityBrushModel(class IWorldRenderList __near *,struct model_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_DrawIdentityBrushModel(CWorldRenderList *pRenderListIn, model_t *model)
{
  msurface2_t *v2; // esi
  int i; // edi

  if ( model != nullptr )
  {
    v2 = (msurface2_t *)(*(_DWORD *)(model->sprite.numframes + 124) + 32 * model->brush.firstmodelsurface);
    for ( i = 0; i < model->brush.nummodelsurfaces; ++v2 )
    {
      if ( (v2->flags & 0x20) != 0 )
        Shader_TranslucentWorldSurface(pRenderList: pRenderListIn, surfID: v2);
      else
        Shader_WorldSurface(pRenderList: pRenderListIn, surfID: v2);
      ++i;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D6A80
// Name: public: CMSurfaceSortList::CMSurfaceSortList(void)
// Source: json
//------------------------------------------------------------------------------
CMSurfaceSortList *__thiscall CMSurfaceSortList::CMSurfaceSortList(CMSurfaceSortList *this)
{
  CMSurfaceSortList *result; // eax
  CUtlVector<surfacesortgroup_t *,CUtlMemory<surfacesortgroup_t *,int> > *m_sortGroupLists; // edx
  int i; // esi

  result = this;
  this->m_list.m_Memory.m_pMemory = nullptr;
  this->m_list.m_Memory.m_nAllocationCount = 0;
  this->m_list.m_Memory.m_nGrowSize = 0;
  this->m_list.m_Size = 0;
  this->m_list.m_pElements = nullptr;
  this->m_groups.m_Memory.m_pMemory = nullptr;
  this->m_groups.m_Memory.m_nAllocationCount = 0;
  this->m_groups.m_Memory.m_nGrowSize = 0;
  this->m_groups.m_Size = 0;
  this->m_groups.m_pElements = nullptr;
  this->m_groupUsed.m_Memory.m_pMemory = nullptr;
  this->m_groupUsed.m_Memory.m_nAllocationCount = 0;
  this->m_groupUsed.m_Memory.m_nGrowSize = 0;
  this->m_groupUsed.m_Size = 0;
  this->m_groupUsed.m_pElements = nullptr;
  m_sortGroupLists = this->m_sortGroupLists;
  for ( i = 3; i >= 0; --i )
  {
    m_sortGroupLists->m_Memory.m_pMemory = nullptr;
    m_sortGroupLists->m_Memory.m_nAllocationCount = 0;
    m_sortGroupLists->m_Memory.m_nGrowSize = 0;
    m_sortGroupLists->m_Size = 0;
    m_sortGroupLists->m_pElements = nullptr;
    ++m_sortGroupLists;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D6AD0
// Name: public: CMSurfaceSortList::~CMSurfaceSortList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMSurfaceSortList::~CMSurfaceSortList(CMSurfaceSortList *this)
{
  surfacesortgroup_t *p_m_emptyGroup; // esi
  int i; // ebx
  void *listHead; // eax

  p_m_emptyGroup = &this->m_emptyGroup;
  for ( i = 3; i >= 0; --i )
  {
    p_m_emptyGroup = (surfacesortgroup_t *)((char *)p_m_emptyGroup - 20);
    p_m_emptyGroup->vertexCount = 0;
    if ( p_m_emptyGroup->groupListIndex >= 0 )
    {
      if ( p_m_emptyGroup->listHead != 0 )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)p_m_emptyGroup->listHead);
        p_m_emptyGroup->listHead = 0;
      }
      p_m_emptyGroup->listTail = 0;
    }
    listHead = (void *)p_m_emptyGroup->listHead;
    p_m_emptyGroup->vertexCountNoDetail = p_m_emptyGroup->listHead;
    if ( p_m_emptyGroup->groupListIndex >= 0 )
    {
      if ( listHead != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: listHead);
        p_m_emptyGroup->listHead = 0;
      }
      p_m_emptyGroup->listTail = 0;
    }
  }
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_groupUsed);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_groups);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>((CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x100D6B60
// Name: Shader_WorldShadowDepthFill
// Source: json
//------------------------------------------------------------------------------
void __cdecl Shader_WorldShadowDepthFill(
        IMatRenderContext *pRenderContext,
        CWorldRenderList *pRenderList,
        unsigned int flags)
{
  int v3; // ebx
  int v4; // edi
  int *v5; // esi
  int v6; // eax
  const materiallist_t *v7; // ecx
  const surfacesortgroup_t *v8; // edi
  msurface2_t *SurfaceAtHead; // eax
  IMaterial *material; // esi
  int m_Size; // eax
  int v12; // esi
  int v13; // eax
  const surfacesortgroup_t **v14; // eax
  unsigned int triangleCount; // eax
  int v17; // esi
  int (__thiscall *GetMaxVerticesToRender)(IMatRenderContext *, IMaterial *); // edx
  int v19; // eax
  CMSurfaceSortList *v20; // ebx
  const surfacesortgroup_t *v21; // esi
  msurface2_t *v22; // eax
  IMaterial *v23; // edi
  __int16 i; // ax
  int v25; // eax
  const materiallist_t *v26; // ecx
  bool v27; // cc
  char *v28; // edi
  unsigned int v29; // eax
  int indexCount; // ebx
  int v31; // esi
  unsigned __int16 firstPrimID; // ax
  int v33; // edx
  mprimitive_t *primitives; // eax
  bool v35; // zf
  mprimitive_t *v36; // eax
  int m_nVertexCount; // eax
  int v38; // eax
  int v39; // esi
  int v40; // edi
  const surfacesortgroup_t **m_pMemory; // ebx
  CMeshBuilder meshBuilder; // [esp+Ch] [ebp-244h] BYREF
  int v43; // [esp+1F4h] [ebp-5Ch]
  CUtlVector<surfacesortgroup_t *,CUtlMemory<surfacesortgroup_t *,int> > *v44; // [esp+1F8h] [ebp-58h]
  int v45; // [esp+1FCh] [ebp-54h]
  msurface2_t *nSurfID; // [esp+200h] [ebp-50h]
  int nMaxIndices; // [esp+204h] [ebp-4Ch]
  msurface2_t **pSurfaces; // [esp+208h] [ebp-48h]
  int nMaxVertices; // [esp+20Ch] [ebp-44h]
  int _listIndex; // [esp+210h] [ebp-40h]
  CUtlVector<surfacesortgroup_t const *,CUtlMemory<surfacesortgroup_t const *,int> > alphatestedGroups; // [esp+214h] [ebp-3Ch] BYREF
  int _index; // [esp+228h] [ebp-28h]
  const materiallist_t *_pList; // [esp+22Ch] [ebp-24h]
  int nSortGroup; // [esp+230h] [ebp-20h] BYREF
  IMesh *pMesh; // [esp+234h] [ebp-1Ch]
  const CMSurfaceSortList *sortList; // [esp+238h] [ebp-18h]
  int v57; // [esp+23Ch] [ebp-14h]
  char *v58; // [esp+240h] [ebp-10h]
  int nIndexCount; // [esp+244h] [ebp-Ch]
  int nVertexCount; // [esp+248h] [ebp-8h]
  int nBatchVertexCount; // [esp+24Ch] [ebp-4h]
  int nBatchIndexCount; // [esp+25Ch] [ebp+Ch]

  v3 = 0;
  v4 = 1;
  v5 = (int *)&args.m_pArgSBuffer[188];
  nVertexCount = 0;
  nIndexCount = 0;
  memset(&alphatestedGroups, 0, sizeof(alphatestedGroups));
  sortList = &pRenderList->m_SortList;
  v57 = 1;
  v58 = &args.m_pArgSBuffer[188];
  do
  {
    if ( (v4 & flags) != 0 )
    {
      v6 = *v5;
      _index = (int)&sortList->m_sortGroupLists[*v5];
      v7 = *(const materiallist_t **)(_index + 12);
      nSortGroup = v6;
      _pList = v7;
      if ( (int)v7 > 0 )
      {
        do
        {
          v8 = *(const surfacesortgroup_t **)(*(_DWORD *)_index + 4 * v3);
          SurfaceAtHead = CMSurfaceSortList::GetSurfaceAtHead(this: (CMSurfaceSortList *)sortList, group: v8);
          if ( (SurfaceAtHead->flags & 0x10000) == 0 )
          {
            material = host_state.worldbrush->texinfo[*((unsigned __int16 *)SurfaceAtHead + 11) >> 1].material;
            if ( !material->IsTranslucent(this: material) )
            {
              if ( material->IsAlphaTested(this: material) )
              {
                m_Size = alphatestedGroups.m_Size;
                v12 = alphatestedGroups.m_Size;
                if ( alphatestedGroups.m_Size + 1 > alphatestedGroups.m_Memory.m_nAllocationCount )
                {
                  CUtlMemory<INetMessage *,int>::Grow(
                    this: (CUtlMemory<S3RGBA,int> *)&alphatestedGroups,
                    num: alphatestedGroups.m_Size - alphatestedGroups.m_Memory.m_nAllocationCount + 1);
                  m_Size = alphatestedGroups.m_Size;
                }
                alphatestedGroups.m_Size = m_Size + 1;
                v13 = m_Size - v12;
                alphatestedGroups.m_pElements = alphatestedGroups.m_Memory.m_pMemory;
                if ( v13 > 0 )
                  _V_memmove(
                    dest: &alphatestedGroups.m_Memory.m_pMemory[v12 + 1],
                    src: &alphatestedGroups.m_Memory.m_pMemory[v12],
                    count: 4 * v13);
                v14 = &alphatestedGroups.m_Memory.m_pMemory[v12];
                if ( v14 != nullptr )
                  *v14 = v8;
              }
              else
              {
                triangleCount = v8->triangleCount;
                nVertexCount += v8->vertexCount;
                nIndexCount += triangleCount + 2 * triangleCount;
              }
            }
          }
          ++v3;
        }
        while ( v3 < (int)_pList );
        v5 = (int *)v58;
        v4 = v57;
        v6 = nSortGroup;
        v3 = 0;
      }
      Shader_DrawDispChain(
        pRenderContext,
        nSortGroup: v6,
        list: &pRenderList->m_DispSortList,
        flags,
        bShadowDepth: (IMaterial *)1);
    }
    ++v5;
    v4 = __ROL4__(v4, 1);
    v58 = (char *)v5;
    v57 = v4;
  }
  while ( (int)v5 < (int)&args.m_pArgSBuffer[204] );
  if ( nVertexCount != 0 )
  {
    pRenderContext->Bind(this: pRenderContext, a2: (IMaterial *)dword_105F3008, a3: nullptr);
    pMesh = pRenderContext->GetDynamicMesh(this: pRenderContext, a2: 0, a3: 0, a4: 0, a5: 0);
    v17 = pRenderContext->GetMaxIndicesToRender(this: pRenderContext);
    GetMaxVerticesToRender = pRenderContext->GetMaxVerticesToRender;
    nMaxIndices = v17;
    v19 = GetMaxVerticesToRender(this: pRenderContext, a2: (IMaterial *)dword_105F3008);
    nMaxVertices = v19;
    if ( nIndexCount >= v17 )
    {
      nBatchIndexCount = v17;
    }
    else
    {
      v17 = nIndexCount;
      nBatchIndexCount = nIndexCount;
    }
    if ( nVertexCount >= v19 )
    {
      nBatchVertexCount = v19;
    }
    else
    {
      v19 = nVertexCount;
      nBatchVertexCount = nVertexCount;
    }
    meshBuilder.m_IndexBuilder.m_nBufferOffset = -1;
    meshBuilder.m_VertexBuilder.m_nBufferOffset = -1;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
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
    CMeshBuilder::Begin(
      this: &meshBuilder,
      pMesh,
      type: MATERIAL_TRIANGLES,
      nVertexCount: v19,
      nIndexCount: v17,
      pMeshSettings: nullptr);
    nSortGroup = 0;
    v57 = 1;
    v58 = &args.m_pArgSBuffer[188];
    do
    {
      if ( (v57 & flags) != 0 )
      {
        v20 = (CMSurfaceSortList *)sortList;
        v44 = &sortList->m_sortGroupLists[*(_DWORD *)v58];
        v45 = v44->m_Size;
        for ( _listIndex = 0; _listIndex < v45; ++_listIndex )
        {
          v21 = v44->m_Memory.m_pMemory[_listIndex];
          v22 = CMSurfaceSortList::GetSurfaceAtHead(this: v20, group: v21);
          if ( v21->triangleCount != 0 && v21->vertexCount != 0 )
          {
            v23 = host_state.worldbrush->texinfo[*((unsigned __int16 *)v22 + 11) >> 1].material;
            if ( !v23->IsTranslucent(this: v23) && !v23->IsAlphaTested(this: v23) )
            {
              for ( i = v21->listHead; i != -1; i = *(_WORD *)((char *)&v20->m_list.m_Memory.m_pMemory->nextBlock + v25) )
              {
                v25 = i << 6;
                v26 = (materiallist_t *)((char *)v20->m_list.m_Memory.m_pMemory + v25);
                v27 = v26->count <= 0;
                v43 = v25;
                _pList = v26;
                _index = 0;
                if ( !v27 )
                {
                  pSurfaces = v26->pSurfaces;
                  do
                  {
                    v28 = (char *)*pSurfaces;
                    v29 = (*pSurfaces)->flags;
                    nSurfID = *pSurfaces;
                    if ( v29 != 0 && (v29 & 0x10000) == 0 )
                    {
                      indexCount = 0;
                      v31 = 0;
                      if ( (v29 & 0x8000) != 0 )
                      {
                        if ( (v29 & 0x800) != 0 )
                          firstPrimID = 0;
                        else
                          firstPrimID = host_state.worldbrush->surfaces1[(v28 - (char *)host_state.worldbrush->surfaces2) >> 5].prims.firstPrimID;
                        v33 = firstPrimID;
                        primitives = host_state.worldbrush->primitives;
                        v35 = primitives[v33].vertCount == 0;
                        v36 = &primitives[v33];
                        if ( v35 )
                        {
                          v31 = (unsigned __int8)v28[3];
                          indexCount = v36->indexCount;
                        }
                      }
                      else
                      {
                        v31 = (unsigned __int8)v28[3];
                        indexCount = 3 * v31 - 6;
                      }
                      if ( v31 > nMaxVertices || indexCount > nMaxIndices )
                      {
                        _Error(a1: &args.m_pArgvBuffer[20], v31, nMaxVertices, indexCount, nMaxIndices);
                      }
                      else
                      {
                        if ( nBatchIndexCount < indexCount || nBatchVertexCount < v31 )
                        {
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
                          nBatchIndexCount = nIndexCount;
                          if ( nIndexCount >= nMaxIndices )
                            nBatchIndexCount = nMaxIndices;
                          nBatchVertexCount = nVertexCount;
                          if ( nVertexCount >= nMaxVertices )
                            nBatchVertexCount = nMaxVertices;
                          pMesh = pRenderContext->GetDynamicMesh(this: pRenderContext, a2: 0, a3: 0, a4: 0, a5: 0);
                          CMeshBuilder::Begin(
                            this: &meshBuilder,
                            pMesh,
                            type: MATERIAL_TRIANGLES,
                            nVertexCount: nBatchVertexCount,
                            nIndexCount: nBatchIndexCount,
                            pMeshSettings: nullptr);
                          nSortGroup = 0;
                        }
                        Shader_WorldZFillSurfChain_Single(surfaceHandle: nSurfID, &meshBuilder, nStartVert: &nSortGroup);
                        nBatchIndexCount -= indexCount;
                        nBatchVertexCount -= v31;
                        nIndexCount -= indexCount;
                        nVertexCount -= v31;
                      }
                      v26 = _pList;
                    }
                    ++pSurfaces;
                    ++_index;
                  }
                  while ( _index < v26->count );
                  v20 = (CMSurfaceSortList *)sortList;
                  v25 = v43;
                }
              }
            }
          }
        }
      }
      v58 += 4;
      v57 = __ROL4__(v57, 1);
    }
    while ( (int)v58 < (int)&args.m_pArgSBuffer[204] );
    if ( meshBuilder.m_bGenerateIndices )
    {
      switch ( meshBuilder.m_Type )
      {
        case MATERIAL_LINE_STRIP:
          v38 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
          break;
        case MATERIAL_LINE_LOOP:
          v38 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
        case MATERIAL_POLYGON:
          v38 = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
          break;
        case MATERIAL_QUADS:
          v38 = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
          break;
        case MATERIAL_INSTANCED_QUADS:
          v38 = 0;
          break;
        default:
          v38 = meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
      }
      CIndexBuilder::GenerateIndices(
        this: &meshBuilder.m_IndexBuilder,
        primitiveType: meshBuilder.m_Type,
        nIndexCount: v38);
    }
    meshBuilder.m_pMesh->UnlockMesh(
      this: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
      a4: &meshBuilder);
    v39 = 0;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
    v40 = alphatestedGroups.m_Size;
    m_pMemory = alphatestedGroups.m_Memory.m_pMemory;
    if ( alphatestedGroups.m_Size > 0 )
    {
      do
        Shader_DrawDynamicChain(
          pRenderContext,
          group: m_pMemory[v39++],
          (CMSurfaceSortList *)sortList,
          bShadowDepth: true);
      while ( v39 < v40 );
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
    if ( alphatestedGroups.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
  else if ( alphatestedGroups.m_Memory.m_nGrowSize >= 0 && alphatestedGroups.m_Memory.m_pMemory != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: alphatestedGroups.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D7290
// Name: public: CWorldRenderList::CWorldRenderList(void)
// Source: json
//------------------------------------------------------------------------------
CWorldRenderList *__thiscall CWorldRenderList::CWorldRenderList(CWorldRenderList *this)
{
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *m_ShadowHandles; // ecx
  int i; // edx
  CUtlVector<msurface2_t *,CUtlMemory<msurface2_t *,int> > *m_DlightSurfaces; // ecx
  int j; // edx
  CUtlVector<msurface2_t *,CUtlMemory<msurface2_t *,int> > *m_PaintedSurfaces; // ecx
  int k; // edx

  this->m_iRefs = 1;
  this->CRefCounted1<IWorldRenderList,CRefCountServiceBase<1,CRefMT> >::IWorldRenderList::IRefCounted::__vftable = (CWorldRenderList_vtbl *)&args.m_pArgvBuffer[108];
  this->CRefCounted1<IWorldRenderList,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&args.m_pArgvBuffer[96];
  CMSurfaceSortList::CMSurfaceSortList(this: &this->m_SortList);
  CMSurfaceSortList::CMSurfaceSortList(this: &this->m_DispSortList);
  this->m_AlphaSurfaces.m_Memory.m_pMemory = nullptr;
  this->m_AlphaSurfaces.m_Memory.m_nAllocationCount = 0;
  this->m_AlphaSurfaces.m_Memory.m_nGrowSize = 0;
  this->m_AlphaSurfaces.m_Size = 0;
  this->m_AlphaSurfaces.m_pElements = nullptr;
  m_ShadowHandles = this->m_ShadowHandles;
  for ( i = 3; i >= 0; --i )
  {
    m_ShadowHandles->m_Memory.m_pMemory = nullptr;
    m_ShadowHandles->m_Memory.m_nAllocationCount = 0;
    m_ShadowHandles->m_Memory.m_nGrowSize = 0;
    m_ShadowHandles->m_Size = 0;
    m_ShadowHandles->m_pElements = nullptr;
    ++m_ShadowHandles;
  }
  m_DlightSurfaces = this->m_DlightSurfaces;
  for ( j = 3; j >= 0; --j )
  {
    m_DlightSurfaces->m_Memory.m_pMemory = nullptr;
    m_DlightSurfaces->m_Memory.m_nAllocationCount = 0;
    m_DlightSurfaces->m_Memory.m_nGrowSize = 0;
    m_DlightSurfaces->m_Size = 0;
    m_DlightSurfaces->m_pElements = nullptr;
    ++m_DlightSurfaces;
  }
  m_PaintedSurfaces = this->m_PaintedSurfaces;
  for ( k = 3; k >= 0; --k )
  {
    m_PaintedSurfaces->m_Memory.m_pMemory = nullptr;
    m_PaintedSurfaces->m_Memory.m_nAllocationCount = 0;
    m_PaintedSurfaces->m_Memory.m_nGrowSize = 0;
    m_PaintedSurfaces->m_Size = 0;
    m_PaintedSurfaces->m_pElements = nullptr;
    ++m_PaintedSurfaces;
  }
  this->m_leaves.m_Memory.m_pMemory = nullptr;
  this->m_leaves.m_Memory.m_nAllocationCount = 0;
  this->m_leaves.m_Memory.m_nGrowSize = 0;
  this->m_leaves.m_Size = 0;
  this->m_leaves.m_pElements = nullptr;
  *(_DWORD *)&this->m_VisitedSurfs.m_bits.m_numBits = 0;
  this->m_VisitedSurfs.m_bits.m_iBitStringStorage = 0;
  this->m_VisitedSurfs.m_bits.m_pInt = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100D73E0
// Name: public: virtual bool CWorldRenderList::OnFinalRelease(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWorldRenderList::OnFinalRelease(CWorldRenderList *this)
{
  char *v1; // esi
  TSLNodeBase_t *v2; // eax

  v1 = (char *)this - 4;
  CWorldRenderList::Reset(this: (CWorldRenderList *)((char *)this - 4));
  v2 = (TSLNodeBase_t *)MemAlloc_Alloc(nSize: 8u);
  if ( v2 != nullptr )
  {
    *((_DWORD *)&v2->Next + 1) = v1;
    CTSListBase::Push(this: &CWorldRenderList::g_Pool.m_AvailableObjects, pNode: v2);
  }
  else
  {
    CTSListBase::Push(this: &CWorldRenderList::g_Pool.m_AvailableObjects, pNode: nullptr);
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x100D7420
// Name: public: virtual CWorldRenderList::~CWorldRenderList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorldRenderList::~CWorldRenderList(CWorldRenderList *this)
{
  CUtlVector<WorldListLeafData_t,CUtlMemory<WorldListLeafData_t,int> > *p_m_leaves; // esi
  int i; // ebx
  WorldListLeafData_t *m_pMemory; // eax
  CUtlVector<msurface2_t *,CUtlMemory<msurface2_t *,int> > *m_PaintedSurfaces; // esi
  int j; // ebx
  msurface2_t **v7; // eax
  CUtlVector<msurface2_t *,CUtlMemory<msurface2_t *,int> > *m_DlightSurfaces; // esi
  int k; // ebx
  msurface2_t **v10; // eax

  this->CRefCounted1<IWorldRenderList,CRefCountServiceBase<1,CRefMT> >::IWorldRenderList::IRefCounted::__vftable = (CWorldRenderList_vtbl *)&args.m_pArgvBuffer[108];
  this->CRefCounted1<IWorldRenderList,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&args.m_pArgvBuffer[96];
  CWorldRenderList::Purge(this);
  if ( this->m_VisitedSurfs.m_bits.m_numInts > 1u )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_VisitedSurfs.m_bits.m_pInt);
  this->m_VisitedSurfs.m_bits.m_pInt = nullptr;
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_leaves);
  p_m_leaves = &this->m_leaves;
  for ( i = 3; i >= 0; --i )
  {
    --p_m_leaves;
    p_m_leaves->m_Size = 0;
    if ( p_m_leaves->m_Memory.m_nGrowSize >= 0 )
    {
      if ( p_m_leaves->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_leaves->m_Memory.m_pMemory);
        p_m_leaves->m_Memory.m_pMemory = nullptr;
      }
      p_m_leaves->m_Memory.m_nAllocationCount = 0;
    }
    m_pMemory = p_m_leaves->m_Memory.m_pMemory;
    p_m_leaves->m_pElements = p_m_leaves->m_Memory.m_pMemory;
    if ( p_m_leaves->m_Memory.m_nGrowSize >= 0 )
    {
      if ( m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
        p_m_leaves->m_Memory.m_pMemory = nullptr;
      }
      p_m_leaves->m_Memory.m_nAllocationCount = 0;
    }
  }
  m_PaintedSurfaces = this->m_PaintedSurfaces;
  for ( j = 3; j >= 0; --j )
  {
    --m_PaintedSurfaces;
    m_PaintedSurfaces->m_Size = 0;
    if ( m_PaintedSurfaces->m_Memory.m_nGrowSize >= 0 )
    {
      if ( m_PaintedSurfaces->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_PaintedSurfaces->m_Memory.m_pMemory);
        m_PaintedSurfaces->m_Memory.m_pMemory = nullptr;
      }
      m_PaintedSurfaces->m_Memory.m_nAllocationCount = 0;
    }
    v7 = m_PaintedSurfaces->m_Memory.m_pMemory;
    m_PaintedSurfaces->m_pElements = m_PaintedSurfaces->m_Memory.m_pMemory;
    if ( m_PaintedSurfaces->m_Memory.m_nGrowSize >= 0 )
    {
      if ( v7 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v7);
        m_PaintedSurfaces->m_Memory.m_pMemory = nullptr;
      }
      m_PaintedSurfaces->m_Memory.m_nAllocationCount = 0;
    }
  }
  m_DlightSurfaces = this->m_DlightSurfaces;
  for ( k = 3; k >= 0; --k )
  {
    --m_DlightSurfaces;
    m_DlightSurfaces->m_Size = 0;
    if ( m_DlightSurfaces->m_Memory.m_nGrowSize >= 0 )
    {
      if ( m_DlightSurfaces->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_DlightSurfaces->m_Memory.m_pMemory);
        m_DlightSurfaces->m_Memory.m_pMemory = nullptr;
      }
      m_DlightSurfaces->m_Memory.m_nAllocationCount = 0;
    }
    v10 = m_DlightSurfaces->m_Memory.m_pMemory;
    m_DlightSurfaces->m_pElements = m_DlightSurfaces->m_Memory.m_pMemory;
    if ( m_DlightSurfaces->m_Memory.m_nGrowSize >= 0 )
    {
      if ( v10 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v10);
        m_DlightSurfaces->m_Memory.m_pMemory = nullptr;
      }
      m_DlightSurfaces->m_Memory.m_nAllocationCount = 0;
    }
  }
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_AlphaSurfaces);
  CMSurfaceSortList::~CMSurfaceSortList(this: &this->m_DispSortList);
  CMSurfaceSortList::~CMSurfaceSortList(this: &this->m_SortList);
}

//------------------------------------------------------------------------------
// Address: 0x100D75F0
// Name: Shader_DrawChainsStatic
// Source: json
//------------------------------------------------------------------------------
void __cdecl Shader_DrawChainsStatic(IMatRenderContext *pRenderContext, CMSurfaceSortList *sortList, bool bShadowDepth)
{
  int nSortGroup; // ecx
  int v4; // edi
  int v5; // ecx
  int v6; // edi
  int (__thiscall *GetMaxIndicesToRender)(IMatRenderContext *); // edx
  int v8; // esi
  msurface2_t *SurfaceAtHead; // eax
  unsigned __int8 *v10; // esi
  msurface2_t *v11; // ecx
  bool v12; // zf
  int v13; // eax
  int v14; // ebx
  unsigned int v15; // esi
  S3RGBA *v16; // edi
  S3RGBA *m_pMemory; // ecx
  int v18; // eax
  unsigned __int8 **v19; // ecx
  int v20; // edi
  int materialSortID; // ebx
  int v22; // esi
  IMesh **v23; // ecx
  int v24; // eax
  IMesh *v25; // ecx
  int v26; // esi
  unsigned int v27; // ebx
  ResourceEntryInfo *v28; // ecx
  int v29; // eax
  int v30; // edx
  ResourceEntryInfo *v31; // eax
  int v32; // ecx
  __int16 v33; // ax
  int m_nCurrentIndex; // ebx
  worldbrushdata_t *worldbrush; // edi
  int v36; // eax
  char *v37; // esi
  bool v38; // cc
  int v39; // ecx
  unsigned __int16 firstPrimID; // ax
  __int16 v41; // cx
  int v42; // eax
  int v43; // edx
  signed int v44; // eax
  int v45; // esi
  unsigned __int16 *v46; // edx
  int v47; // esi
  signed int i; // edi
  IMaterial *material; // ecx
  char *v50; // eax
  int m_nVertexCount; // eax
  int v52; // esi
  int j; // eax
  int v54; // edx
  char v55; // bl
  int v56; // ecx
  int v57; // eax
  int v58; // esi
  IMaterial *v59; // eax
  void (__thiscall *BindBatch)(IMatRenderContext *, IMesh *, IMaterial *); // edx
  _WORD *v61; // esi
  IMatRenderContext *v62; // ebx
  unsigned __int16 *v63; // edi
  IMaterial *v64; // esi
  BOOL v65; // ebx
  IMaterial *v66; // edi
  IMaterialVar *v67; // ebx
  int v68; // eax
  IMaterial_vtbl *v69; // edx
  int v70; // eax
  IMaterial_vtbl *v71; // edx
  IMesh **v72; // esi
  int v73; // eax
  IMaterial_vtbl *v74; // edx
  ITexture *(__thiscall *GetTextureValue)(IMaterialVar *); // edx
  int v76; // eax
  int v77; // eax
  IMatRenderContext_vtbl *v78; // edx
  void (__thiscall *BindLightmapPage)(IMatRenderContext *, int); // eax
  int v80; // edx
  int k; // esi
  S3RGBA *v82; // eax
  ResourceEntryInfo *v83; // eax
  IMesh *v84; // [esp-4h] [ebp-1894h]
  float v85; // [esp+0h] [ebp-1890h]
  CUtlMemory<ResourceEntryInfo,int> v86; // [esp+10h] [ebp-1880h] BYREF
  int v87; // [esp+1Ch] [ebp-1874h]
  _BYTE v88[92]; // [esp+20h] [ebp-1870h] BYREF
  int v89; // [esp+1020h] [ebp-870h]
  _DWORD v90[129]; // [esp+1024h] [ebp-86Ch]
  _WORD v91[4]; // [esp+1228h] [ebp-668h] BYREF
  int v92; // [esp+1628h] [ebp-268h]
  _WORD *v93; // [esp+162Ch] [ebp-264h]
  CMeshBuilder v94; // [esp+1630h] [ebp-260h] BYREF
  unsigned __int16 *v95; // [esp+1818h] [ebp-78h]
  CUtlMemory<S3RGBA,int> v96; // [esp+181Ch] [ebp-74h] BYREF
  int v97; // [esp+1828h] [ebp-68h]
  _BYTE v98[32]; // [esp+182Ch] [ebp-64h] BYREF
  int v99; // [esp+184Ch] [ebp-44h]
  S3RGBA *v100; // [esp+1850h] [ebp-40h]
  materiallist_t **v101; // [esp+1854h] [ebp-3Ch]
  int v102; // [esp+1858h] [ebp-38h]
  int v103; // [esp+185Ch] [ebp-34h]
  IMesh *v104; // [esp+1860h] [ebp-30h]
  int v105; // [esp+1864h] [ebp-2Ch]
  IMesh *v106; // [esp+1868h] [ebp-28h]
  unsigned __int16 *v107; // [esp+186Ch] [ebp-24h]
  int v108; // [esp+1870h] [ebp-20h]
  int v109; // [esp+1874h] [ebp-1Ch]
  int v110; // [esp+1878h] [ebp-18h]
  char *v111; // [esp+187Ch] [ebp-14h]
  int v112; // [esp+1880h] [ebp-10h]
  int v113; // [esp+1884h] [ebp-Ch]
  unsigned __int8 *src; // [esp+1888h] [ebp-8h]
  char v115; // [esp+188Eh] [ebp-2h]
  bool v116; // [esp+188Fh] [ebp-1h]

  v4 = nSortGroup;
  v86.m_pMemory = (ResourceEntryInfo *)v88;
  v93 = v91;
  v90[0] = v88;
  v96.m_pMemory = (S3RGBA *)v98;
  v92 = 0;
  v86.m_nAllocationCount = 512;
  v86.m_nGrowSize = -1;
  v87 = 0;
  v89 = 0;
  v96.m_nAllocationCount = 8;
  v96.m_nGrowSize = -1;
  v97 = 0;
  v99 = 0;
  v100 = (S3RGBA *)v98;
  v115 = 1;
  CMeshBuilder::CMeshBuilder(this: &v94);
  v116 = g_pMaterialSystemConfig->nFullbright == 1;
  v5 = 5 * v4 + 15;
  v6 = *(&sortList->m_list.m_Size + v5);
  v101 = &sortList->m_list.m_Memory.m_pMemory + v5;
  GetMaxIndicesToRender = pRenderContext->GetMaxIndicesToRender;
  v103 = v6;
  v108 = 0;
  v102 = GetMaxIndicesToRender(this: pRenderContext);
  if ( v6 <= 0 )
    goto LABEL_97;
  do
  {
    v8 = v108;
    SurfaceAtHead = CMSurfaceSortList::GetSurfaceAtHead(
                      this: sortList,
                      group: *((const surfacesortgroup_t **)&(*v101)->nextBlock + v108));
    v104 = pRenderContext->GetDynamicMesh(
             this: pRenderContext,
             a2: 0,
             a3: g_WorldStaticMeshes.m_Memory.m_pMemory[SurfaceAtHead->materialSortID],
             a4: 0,
             a5: 0);
    CMeshBuilder::Begin(
      this: &v94,
      pMesh: v104,
      type: MATERIAL_TRIANGLES,
      nVertexCount: 0,
      nIndexCount: v102,
      pMeshSettings: nullptr);
    v106 = nullptr;
    v112 = 0;
    v110 = -1;
    if ( v8 >= v103 )
      goto LABEL_54;
    while ( 1 )
    {
      src = (unsigned __int8 *)*(&(*v101)->nextBlock + v108);
      v10 = src;
      v11 = CMSurfaceSortList::GetSurfaceAtHead(this: sortList, group: (const surfacesortgroup_t *)src);
      v12 = SLOBYTE(v11->flags) >= 0;
      v105 = (int)v11;
      if ( !v12 )
      {
        v13 = v99;
        v14 = v99;
        if ( v99 + 1 > v96.m_nAllocationCount )
        {
          v113 = v99 - v96.m_nAllocationCount + 1;
          if ( v96.m_nGrowSize < 0 )
          {
            v96.m_nGrowSize = v97;
            if ( v96.m_nAllocationCount != 0 )
            {
              v15 = 4 * v96.m_nAllocationCount;
              v16 = (S3RGBA *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * v96.m_nAllocationCount);
              memcpy(dst: (unsigned __int8 *)v16, src: (unsigned __int8 *)v96.m_pMemory, count: v15);
              v10 = src;
              v96.m_pMemory = v16;
            }
            else
            {
              v96.m_pMemory = nullptr;
            }
          }
          CUtlMemory<INetMessage *,int>::Grow(this: &v96, num: v113);
          v13 = v99;
        }
        m_pMemory = v96.m_pMemory;
        v99 = v13 + 1;
        v18 = v13 - v14;
        v100 = v96.m_pMemory;
        if ( v18 > 0 )
        {
          _V_memmove(dest: &v96.m_pMemory[v14 + 1], src: &v96.m_pMemory[v14], count: 4 * v18);
          m_pMemory = v96.m_pMemory;
        }
        v19 = (unsigned __int8 **)&m_pMemory[v14];
        if ( v19 != nullptr )
          *v19 = v10;
        goto LABEL_46;
      }
      v20 = 3 * *((_DWORD *)v10 + 6);
      if ( v20 + v112 > v102 )
        break;
      materialSortID = v11->materialSortID;
      if ( g_WorldStaticMeshes.m_Memory.m_pMemory[materialSortID] == v106 )
      {
        v24 = v89;
      }
      else
      {
        if ( v92 >= 127 )
        {
          if ( v115 != 0 )
          {
            _DevWarning(a1: 2, a2: &args.m_pArgvBuffer[236]);
            v115 = 0;
          }
          goto LABEL_46;
        }
        v22 = v92++;
        v93 = v91;
        v23 = g_WorldStaticMeshes.m_Memory.m_pMemory;
        v91[4 * v22] = 0;
        v24 = v89;
        v91[4 * v22 + 1] = v89;
        v25 = v23[materialSortID];
        v110 = v22;
        v106 = v25;
        *(_DWORD *)&v91[4 * v22 + 2] = v25;
      }
      v26 = v24;
      if ( v24 + 1 > v86.m_nAllocationCount )
      {
        v107 = (unsigned __int16 *)(v24 - v86.m_nAllocationCount + 1);
        if ( v86.m_nGrowSize < 0 )
        {
          v86.m_nGrowSize = v87;
          if ( v86.m_nAllocationCount != 0 )
          {
            v27 = 8 * v86.m_nAllocationCount;
            v113 = (int)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 8 * v86.m_nAllocationCount);
            memcpy(dst: (unsigned __int8 *)v113, src: (unsigned __int8 *)v86.m_pMemory, count: v27);
            v86.m_pMemory = (ResourceEntryInfo *)v113;
          }
          else
          {
            v86.m_pMemory = nullptr;
          }
        }
        CUtlMemory<CAsyncWavDataCache::DeadBufferEntry_t,int>::Grow(this: &v86, num: (int)v107);
        v24 = v89;
      }
      v28 = v86.m_pMemory;
      v89 = v24 + 1;
      v29 = v24 - v26;
      v90[0] = v86.m_pMemory;
      if ( v29 > 0 )
      {
        _V_memmove(dest: &v86.m_pMemory[v26 + 1], src: &v86.m_pMemory[v26], count: 8 * v29);
        v28 = v86.m_pMemory;
      }
      v30 = v105;
      v31 = &v28[v26];
      v32 = v112;
      LOWORD(v31->resData) = v112;
      v31->eType = v30;
      HIWORD(v31->resData) = v20;
      ++v91[4 * v110];
      v112 = (unsigned __int16)v20 + v32;
      v33 = *(_WORD *)src;
      if ( *(_WORD *)src != 0xFFFF )
      {
        m_nCurrentIndex = v94.m_IndexBuilder.m_nCurrentIndex;
        worldbrush = host_state.worldbrush;
        do
        {
          v36 = v33 << 6;
          v37 = (char *)sortList->m_list.m_Memory.m_pMemory + v36;
          v38 = *((_DWORD *)v37 + 1) <= 0;
          v113 = v36;
          v111 = v37;
          v109 = 0;
          if ( !v38 )
          {
            src = (unsigned __int8 *)(v37 + 8);
            do
            {
              v39 = *(_DWORD *)src;
              if ( (**(_DWORD **)src & 0x8000) != 0 )
              {
                if ( (**(_DWORD **)src & 0x800) != 0 )
                  firstPrimID = 0;
                else
                  firstPrimID = worldbrush->surfaces1[(signed int)(v39 - (unsigned int)worldbrush->surfaces2) >> 5].prims.firstPrimID;
                v41 = LOWORD(v94.m_IndexBuilder.m_nIndexOffset) + *(_WORD *)(v39 + 20);
                v42 = (int)&worldbrush->primitives[firstPrimID];
                v43 = *(unsigned __int16 *)(v42 + 4);
                v44 = v94.m_IndexBuilder.m_nIndexSize * *(unsigned __int16 *)(v42 + 6);
                v45 = (int)&worldbrush->primindices[v43];
                v46 = &v94.m_IndexBuilder.m_pIndices[m_nCurrentIndex];
                if ( v44 > 0 )
                {
                  v47 = v45 - (_DWORD)v46;
                  for ( i = v44; i != 0; --i )
                  {
                    *v46 = v41 + *(unsigned __int16 *)((char *)v46 + v47);
                    ++v46;
                  }
                  m_nCurrentIndex = v94.m_IndexBuilder.m_nCurrentIndex;
                  worldbrush = host_state.worldbrush;
                }
                v37 = v111;
                m_nCurrentIndex += v94.m_IndexBuilder.m_nIndexSize * v44;
                v94.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
                if ( m_nCurrentIndex > v94.m_IndexBuilder.m_nIndexCount )
                  v94.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
              }
              else
              {
                BuildIndicesForSurface(meshBuilder: &v94.m_IndexBuilder, surfID: *(msurface2_t **)src);
                m_nCurrentIndex = v94.m_IndexBuilder.m_nCurrentIndex;
                worldbrush = host_state.worldbrush;
              }
              src += 4;
              ++v109;
            }
            while ( v109 < *((_DWORD *)v37 + 1) );
          }
          v33 = *(_WORD *)((char *)&sortList->m_list.m_Memory.m_pMemory->nextBlock + v113);
        }
        while ( v33 != -1 );
      }
LABEL_46:
      if ( ++v108 >= v103 )
        goto LABEL_54;
    }
    if ( v20 <= v102 )
    {
      v106 = nullptr;
    }
    else
    {
      material = materialSortInfoArray[v11->materialSortID].material;
      if ( material != nullptr )
        v50 = (char *)material->GetName(this: material);
      else
        v50 = &args.m_pArgvBuffer[228];
      DevMsg(a1: &args.m_pArgvBuffer[140], v50, v20, v102);
    }
LABEL_54:
    if ( v94.m_bGenerateIndices )
    {
      switch ( v94.m_Type )
      {
        case MATERIAL_LINE_STRIP:
          m_nVertexCount = 2 * v94.m_VertexBuilder.m_nVertexCount - 2;
          break;
        case MATERIAL_LINE_LOOP:
          m_nVertexCount = 2 * v94.m_VertexBuilder.m_nVertexCount;
          break;
        case MATERIAL_POLYGON:
          m_nVertexCount = 3 * v94.m_VertexBuilder.m_nVertexCount - 6;
          break;
        case MATERIAL_QUADS:
          m_nVertexCount = 6 * v94.m_VertexBuilder.m_nVertexCount / 4;
          break;
        case MATERIAL_INSTANCED_QUADS:
          m_nVertexCount = 0;
          break;
        default:
          m_nVertexCount = v94.m_VertexBuilder.m_nVertexCount;
          break;
      }
      CIndexBuilder::GenerateIndices(this: &v94.m_IndexBuilder, primitiveType: v94.m_Type, nIndexCount: m_nVertexCount);
    }
    v94.m_pMesh->UnlockMesh(
      this: v94.m_pMesh,
      a2: v94.m_VertexBuilder.m_nVertexCount,
      a3: v94.m_IndexBuilder.m_nIndexCount,
      a4: &v94);
    v52 = v92;
    v94.m_IndexBuilder.m_pIndexBuffer = nullptr;
    v94.m_IndexBuilder.m_nMaxIndexCount = 0;
    v94.m_VertexBuilder.m_nMaxVertexCount = 0;
    v94.m_VertexBuilder.m_pVertexBuffer = nullptr;
    v94.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    v94.m_pMesh = nullptr;
    v113 = v92;
    if ( (_S1_8 & 1) == 0 )
    {
      _S1_8 |= 1u;
      counter_1.m_pCounter = CVProfile::FindOrCreateCounter(
                               this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                               a2: &args.m_pArgvBuffer[116],
                               a3: COUNTER_GROUP_DEFAULT);
      atexit(func: Shader_DrawChainsStatic_::_37_::_dynamic_atexit_destructor_for___counter__);
    }
    *counter_1.m_pCounter += v52;
    for ( j = 0; j < v52; ++j )
      v90[j + 1] = j;
    do
    {
      v54 = 1;
      v55 = 0;
      if ( v52 <= 1 )
        break;
      do
      {
        v56 = v90[v54 + 1];
        v57 = v90[v54];
        if ( *(_DWORD *)&v91[4 * v56 + 2] < *(_DWORD *)&v91[4 * v57 + 2] )
        {
          v90[v54] = v56;
          v90[v54 + 1] = v57;
          v55 = 1;
        }
        ++v54;
      }
      while ( v54 < v52 );
    }
    while ( v55 != 0 );
    pRenderContext->BeginBatch(this: pRenderContext, a2: v104);
    v112 = 0;
    if ( v52 > 0 )
    {
      do
      {
        v58 = v90[v112 + 1];
        v59 = materialSortInfoArray[*(__int16 *)(v86.m_pMemory[(unsigned __int16)v91[4 * v58 + 1]].eType + 18)].material;
        BindBatch = pRenderContext->BindBatch;
        v61 = &v91[4 * v58];
        v84 = *((IMesh **)v61 + 1);
        v107 = v61;
        BindBatch(this: pRenderContext, a2: v84, a3: v59);
        src = nullptr;
        if ( *v61 != 0 )
        {
          v62 = pRenderContext;
          do
          {
            v63 = (unsigned __int16 *)&v86.m_pMemory[(_DWORD)&src[v107[1]]];
            v64 = materialSortInfoArray[*(__int16 *)(*(_DWORD *)v63 + 18)].material;
            v95 = v63;
            if ( bShadowDepth )
            {
              v65 = v64->IsAlphaTested(this: v64);
              v66 = g_pMaterialDepthWrite[v65][(unsigned __int8)v64->IsTwoSided(this: v64)];
              if ( v65 )
              {
                v67 = v64->FindVarFast(this: v64, a2: "$basetexture", a3: &originalTextureVarCache_3);
                v68 = (int)v64->FindVarFast(this: v64, a2: "$frame", a3: &originalTextureFrameVarCache_3);
                v69 = v64->__vftable;
                v109 = v68;
                v70 = (int)v69->FindVarFast(this: v64, a2: "$AlphaTestReference", a3: &originalAlphaRefCache_3);
                v71 = v66->__vftable;
                v110 = v70;
                v72 = (IMesh **)v71->FindVarFast(this: v66, a2: "$basetexture", a3: &textureVarCache_3);
                v73 = (int)v66->FindVarFast(this: v66, a2: "$frame", a3: &textureFrameVarCache_3);
                v74 = v66->__vftable;
                v111 = (char *)v73;
                v105 = (int)v74->FindVarFast(this: v66, a2: "$AlphaTestReference", a3: &alphaRefCache_3);
                if ( v72 != nullptr && v67 != nullptr )
                {
                  GetTextureValue = v67->GetTextureValue;
                  v104 = *v72;
                  v76 = (int)GetTextureValue(this: v67);
                  ((void (__thiscall *)(IMesh **, int))v104[7].IIndexBuffer::__vftable)(a1: v72, a2: v76);
                }
                if ( v111 != nullptr && v109 != 0 )
                {
                  v77 = (*(int (__thiscall **)(int))(*(_DWORD *)v109 + 108))(a1: v109);
                  (*(void (__thiscall **)(char *, int))(*(_DWORD *)v111 + 20))(a1: v111, a2: v77);
                }
                if ( v105 != 0 && v110 != 0 )
                {
                  v85 = ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v110 + 112))(a1: v110);
                  (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v105 + 16))(a1: LODWORD(v85));
                }
              }
              v62 = pRenderContext;
              pRenderContext->Bind(this: pRenderContext, a2: v66, a3: nullptr);
              v63 = v95;
            }
            else
            {
              v62->Bind(this: v62, a2: v64, a3: nullptr);
              v78 = v62->__vftable;
              if ( v116 )
              {
                BindLightmapPage = v78->BindLightmapPage;
                if ( (**(_BYTE **)v63 & 8) != 0 )
                  BindLightmapPage(this: v62, a2: -2);
                else
                  BindLightmapPage(this: v62, a2: -1);
              }
              else
              {
                v78->BindLightmapPage(
                  this: v62,
                  a2: materialSortInfoArray[*(__int16 *)(*(_DWORD *)v63 + 18)].lightmapPageID);
              }
            }
            v62->DrawBatch(this: v62, a2: MATERIAL_TRIANGLES, a3: v63[2], a4: v63[3]);
            v80 = *v107;
            ++src;
          }
          while ( (int)src < v80 );
        }
        ++v112;
      }
      while ( v112 < v113 );
    }
    pRenderContext->EndBatch(this: pRenderContext);
    if ( v106 != nullptr )
      break;
    if ( v113 == 0 )
      break;
    v92 = 0;
    v89 = 0;
  }
  while ( v108 < v103 );
LABEL_97:
  for ( k = 0; k < v99; ++k )
    Shader_DrawDynamicChain(
      pRenderContext,
      group: *(const surfacesortgroup_t **)&v96.m_pMemory[k],
      sortList,
      bShadowDepth);
  if ( v94.m_VertexBuilder.m_pVertexBuffer != nullptr
    && v94.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: v94.m_VertexBuilder.m_pVertexBuffer) )
  {
    v94.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: v94.m_VertexBuilder.m_pVertexBuffer);
  }
  if ( v94.m_IndexBuilder.m_pIndexBuffer != nullptr
    && v94.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: v94.m_IndexBuilder.m_pIndexBuffer) )
  {
    v94.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: v94.m_IndexBuilder.m_pIndexBuffer);
  }
  v82 = v96.m_pMemory;
  v99 = 0;
  if ( v96.m_nGrowSize >= 0 )
  {
    if ( v96.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v96.m_pMemory);
      v82 = nullptr;
      v96.m_pMemory = nullptr;
    }
    v96.m_nAllocationCount = 0;
  }
  v100 = v82;
  if ( v96.m_nGrowSize >= 0 )
  {
    if ( v82 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v82);
      v96.m_pMemory = nullptr;
    }
    v96.m_nAllocationCount = 0;
  }
  v83 = v86.m_pMemory;
  v89 = 0;
  if ( v86.m_nGrowSize >= 0 )
  {
    if ( v86.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v86.m_pMemory);
      v83 = nullptr;
      v86.m_pMemory = nullptr;
    }
    v86.m_nAllocationCount = 0;
  }
  v90[0] = v83;
  if ( v86.m_nGrowSize >= 0 && v83 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v83);
}

//------------------------------------------------------------------------------
// Address: 0x100D8080
// Name: Shader_DrawChains
// Source: json
//------------------------------------------------------------------------------
void __usercall Shader_DrawChains(
        CMeshBuilder *pRenderContext@<esi>,
        int a2@<edi>,
        const CWorldRenderList *pRenderList,
        int nSortGroup,
        bool bShadowDepth)
{
  int v5; // edi
  char *v6; // eax
  int v7; // edi
  IMatRenderContext_vtbl *m_VertexSize_Position; // edx
  void (__thiscall *BindLightmapPage)(IMatRenderContext *, int); // eax
  int v10; // eax
  int v11; // ecx
  msurface2_t **m_pMemory; // eax
  bool v13; // cc
  msurface2_t **v14; // eax
  const surfacesortgroup_t *v15; // [esp-4h] [ebp-28h]
  const surfacesortgroup_t *v16; // [esp-4h] [ebp-28h]
  CUtlVector<msurface2_t *,CUtlMemory<msurface2_t *,int> > surfList; // [esp+8h] [ebp-1Ch] BYREF
  int _count; // [esp+1Ch] [ebp-8h]
  int i; // [esp+20h] [ebp-4h]
  int _listIndex; // [esp+34h] [ebp+10h]
  int _listIndexa; // [esp+34h] [ebp+10h]

  if ( mat_forcedynamic.m_pParent != nullptr && mat_forcedynamic.m_pParent->m_Value.m_nValue != 0
    || g_pMaterialSystemConfig->bDrawFlat )
  {
    if ( g_VBAllocTracker != nullptr )
      g_VBAllocTracker->TrackMeshAllocations(this: g_VBAllocTracker, a2: &args.m_pArgvBuffer[304]);
    Shader_DrawChainsDynamic(
      m_nIndexCount: a2,
      p_meshBuilder: pRenderContext,
      (IMatRenderContext *)pRenderContext,
      sortList: &pRenderList->m_SortList,
      nSortGroup,
      bShadowDepth);
    v5 = nSortGroup;
  }
  else
  {
    if ( g_VBAllocTracker != nullptr )
      g_VBAllocTracker->TrackMeshAllocations(this: g_VBAllocTracker, a2: &args.m_pArgvBuffer[332]);
    v5 = nSortGroup;
    Shader_DrawChainsStatic((IMatRenderContext *)pRenderContext, sortList: &pRenderList->m_SortList, bShadowDepth);
  }
  if ( g_VBAllocTracker != nullptr )
    g_VBAllocTracker->TrackMeshAllocations(this: g_VBAllocTracker, a2: nullptr);
  if ( r_hidepaintedsurfaces.m_pParent == nullptr || r_hidepaintedsurfaces.m_pParent->m_Value.m_nValue == 0 )
  {
    (*(void (__thiscall **)(CMeshBuilder *, int))(pRenderContext->m_VertexSize_Position + 792))(
      a1: pRenderContext,
      a2: 1);
    v6 = (char *)pRenderList + 20 * v5;
    i = 0;
    _count = (int)v6;
    if ( *((int *)v6 + 147) > 0 )
    {
      while ( 1 )
      {
        v7 = *(_DWORD *)(*((_DWORD *)v6 + 144) + 4 * i);
        (*(void (__thiscall **)(CMeshBuilder *, IMaterial *, _DWORD))(pRenderContext->m_VertexSize_Position + 36))(
          a1: pRenderContext,
          a2: host_state.worldbrush->texinfo[*(unsigned __int16 *)(v7 + 22) >> 1].material,
          a3: 0);
        m_VertexSize_Position = (IMatRenderContext_vtbl *)pRenderContext->m_VertexSize_Position;
        if ( g_pMaterialSystemConfig->nFullbright == 1 )
        {
          BindLightmapPage = m_VertexSize_Position->BindLightmapPage;
          if ( (*(_BYTE *)v7 & 8) != 0 )
            BindLightmapPage(this: (IMatRenderContext *)pRenderContext, a2: -2);
          else
            BindLightmapPage(this: (IMatRenderContext *)pRenderContext, a2: -1);
        }
        else
        {
          m_VertexSize_Position->BindLightmapPage(
            this: (IMatRenderContext *)pRenderContext,
            a2: materialSortInfoArray[*(__int16 *)(v7 + 18)].lightmapPageID);
        }
        Shader_DrawSurfaceDynamic((IMatRenderContext *)pRenderContext, surfID: (msurface2_t *)v7);
        if ( ++i >= *(_DWORD *)(_count + 588) )
          break;
        v6 = (char *)_count;
      }
      v5 = nSortGroup;
    }
    (*(void (__thiscall **)(CMeshBuilder *, _DWORD))(pRenderContext->m_VertexSize_Position + 792))(
      a1: pRenderContext,
      a2: 0);
  }
  if ( !bShadowDepth && g_ShaderDebug.anydebug )
  {
    v10 = 4 * (5 * v5 + 15);
    v11 = *(int *)((char *)&pRenderList->m_SortList.m_list.m_Size + v10);
    i = v10;
    _count = v11;
    _listIndex = 0;
    if ( v11 > 0 )
    {
      do
      {
        v15 = (const surfacesortgroup_t *)*(&(*(materiallist_t **)((char *)&pRenderList->m_SortList.m_list.m_Memory.m_pMemory
                                                                 + v10))->nextBlock
                                          + _listIndex);
        memset(&surfList, 0, sizeof(surfList));
        CMSurfaceSortList::GetSurfaceListForGroup(
          this: &pRenderList->m_SortList,
          list: (CUtlMemory<S3RGBA,int> *)&surfList,
          group: v15);
        DrawDebugInformation(
          (IMatRenderContext *)pRenderContext,
          pList: surfList.m_Memory.m_pMemory,
          listCount: surfList.m_Size);
        m_pMemory = surfList.m_Memory.m_pMemory;
        surfList.m_Size = 0;
        if ( surfList.m_Memory.m_nGrowSize >= 0 )
        {
          if ( surfList.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: surfList.m_Memory.m_pMemory);
            m_pMemory = nullptr;
            surfList.m_Memory.m_pMemory = nullptr;
          }
          surfList.m_Memory.m_nAllocationCount = 0;
        }
        surfList.m_pElements = m_pMemory;
        if ( surfList.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
        v13 = ++_listIndex < _count;
        v10 = i;
      }
      while ( v13 );
    }
    _count = *(int *)((char *)&pRenderList->m_DispSortList.m_list.m_Size + v10);
    _listIndexa = 0;
    if ( _count > 0 )
    {
      while ( 1 )
      {
        v16 = (const surfacesortgroup_t *)*(&(*(materiallist_t **)((char *)&pRenderList->m_DispSortList.m_list.m_Memory.m_pMemory
                                                                 + v10))->nextBlock
                                          + _listIndexa);
        memset(&surfList, 0, sizeof(surfList));
        CMSurfaceSortList::GetSurfaceListForGroup(
          this: &pRenderList->m_DispSortList,
          list: (CUtlMemory<S3RGBA,int> *)&surfList,
          group: v16);
        DispInfo_RenderListDebug(
          (IMatRenderContext *)pRenderContext,
          pList: surfList.m_Memory.m_pMemory,
          listCount: (CMeshBuilder *)surfList.m_Size);
        v14 = surfList.m_Memory.m_pMemory;
        surfList.m_Size = 0;
        if ( surfList.m_Memory.m_nGrowSize >= 0 )
        {
          if ( surfList.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: surfList.m_Memory.m_pMemory);
            v14 = nullptr;
            surfList.m_Memory.m_pMemory = nullptr;
          }
          surfList.m_Memory.m_nAllocationCount = 0;
        }
        surfList.m_pElements = v14;
        if ( surfList.m_Memory.m_nGrowSize >= 0 && v14 != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v14);
        if ( ++_listIndexa >= _count )
          break;
        v10 = i;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D8370
// Name: Shader_WorldEnd
// Source: json
//------------------------------------------------------------------------------
void __usercall Shader_WorldEnd(
        IMatRenderContext *pRenderContext@<eax>,
        CWorldRenderList *pRenderList,
        unsigned int flags,
        float waterZAdjust)
{
  MaterialHeightClipMode_t v6; // edi
  int *v7; // eax
  int v8; // edi
  MaterialHeightClipMode_t v9; // edi
  float v10; // [esp+4h] [ebp-1Ch]
  float v11; // [esp+4h] [ebp-1Ch]
  float v12; // [esp+4h] [ebp-1Ch]
  float v13; // [esp+4h] [ebp-1Ch]
  char *v14; // [esp+18h] [ebp-8h]
  bool v15; // [esp+1Ch] [ebp-4h]
  unsigned int v16; // [esp+2Ch] [ebp+Ch]

  if ( (flags & 0x40) != 0 )
  {
    Shader_WorldShadowDepthFill(pRenderContext, pRenderList, flags);
  }
  else
  {
    if ( (r_skybox_draw_last.m_pParent == nullptr || r_skybox_draw_last.m_pParent->m_Value.m_nValue == 0)
      && (flags & 0x10) != 0
      && (pRenderList->m_bSkyVisible || Map_VisForceFullSky()) )
    {
      if ( (flags & 0x20) != 0 )
      {
        v10 = g_EngineRenderer->GetZFar(this: g_EngineRenderer);
        R_DrawSkyBox(zFar: v10, nDrawFlags: 63);
      }
      else
      {
        v6 = pRenderContext->GetHeightClipMode(this: pRenderContext);
        pRenderContext->SetHeightClipMode(this: pRenderContext, a2: MATERIAL_HEIGHTCLIPMODE_DISABLE);
        v11 = g_EngineRenderer->GetZFar(this: g_EngineRenderer);
        R_DrawSkyBox(zFar: v11, nDrawFlags: 63);
        pRenderContext->SetHeightClipMode(this: pRenderContext, a2: v6);
      }
    }
    if ( r_fastzreject.m_pParent != nullptr && r_fastzreject.m_pParent->m_Value.m_nValue != 0 )
      Shader_WorldZFill(pRenderList, pRenderContext, flags);
    v7 = (int *)&args.m_pArgSBuffer[200];
    v16 = 8;
    v14 = &args.m_pArgSBuffer[200];
    do
    {
      if ( (flags & v16) != 0 )
      {
        v8 = *v7;
        if ( *v7 == 3 )
        {
          if ( waterZAdjust != 0.0 )
          {
            pRenderContext->MatrixMode(this: pRenderContext, a2: MATERIAL_MODEL);
            pRenderContext->PushMatrix(this: pRenderContext);
            pRenderContext->LoadIdentity(this: pRenderContext);
            ((void (__thiscall *)(IMatRenderContext *, _DWORD, _DWORD, _DWORD))pRenderContext->Translate)(
              a1: pRenderContext,
              a2: 0.0,
              a3: 0.0,
              a4: LODWORD(waterZAdjust));
          }
          g_pShadowMgr->PushSinglePassFlashlightStateEnabled(this: g_pShadowMgr, a2: true);
        }
        if ( (flags & 0x80u) != 0 || (v15 = true, (flags & 0x100) != 0) )
          v15 = false;
        g_pShadowMgr->SetFlashlightStencilMasks(this: g_pShadowMgr, a2: v15);
        Shader_DrawDispChain(
          pRenderContext,
          nSortGroup: v8,
          list: &pRenderList->m_DispSortList,
          flags,
          bShadowDepth: nullptr);
        Shader_DrawChains((CMeshBuilder *)pRenderContext, a2: v8, pRenderList, nSortGroup: v8, bShadowDepth: false);
        if ( v8 == 3 )
        {
          g_pShadowMgr->PopSinglePassFlashlightStateEnabled(this: g_pShadowMgr);
          if ( waterZAdjust != 0.0 )
          {
            pRenderContext->MatrixMode(this: pRenderContext, a2: MATERIAL_MODEL);
            pRenderContext->PopMatrix(this: pRenderContext);
          }
        }
      }
      v7 = (int *)(v14 - 4);
      v14 = (char *)v7;
      v16 = __ROR4__(v16, 1);
    }
    while ( (int)v7 >= (int)&args.m_pArgSBuffer[188] );
    if ( r_skybox_draw_last.m_pParent != nullptr
      && r_skybox_draw_last.m_pParent->m_Value.m_nValue != 0
      && (flags & 0x10) != 0
      && (pRenderList->m_bSkyVisible || Map_VisForceFullSky()) )
    {
      if ( (flags & 0x20) != 0 )
      {
        v12 = g_EngineRenderer->GetZFar(this: g_EngineRenderer);
        R_DrawSkyBox(zFar: v12, nDrawFlags: 63);
      }
      else
      {
        v9 = pRenderContext->GetHeightClipMode(this: pRenderContext);
        pRenderContext->SetHeightClipMode(this: pRenderContext, a2: MATERIAL_HEIGHTCLIPMODE_DISABLE);
        v13 = g_EngineRenderer->GetZFar(this: g_EngineRenderer);
        R_DrawSkyBox(zFar: v13, nDrawFlags: 63);
        pRenderContext->SetHeightClipMode(this: pRenderContext, a2: v9);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D8610
// Name: void Shader_DrawTranslucentSurfaces(class IMatRenderContext __near *,class IWorldRenderList __near *,int __near *,int,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __usercall Shader_DrawTranslucentSurfaces(
        int a1@<ebx>,
        int a2@<edi>,
        IMatRenderContext *pRenderContext,
        IWorldRenderList *pRenderListIn,
        int *pSortList,
        int sortCount,
        unsigned int flags)
{
  transsurfacebatch_t *v7; // esi
  bool v8; // zf
  unsigned int v9; // ebx
  int m_nAllocationCount; // edi
  int v11; // ecx
  int m_Size; // eax
  int v13; // edx
  IWorldRenderList_vtbl *v14; // edx
  int Release_low; // ebx
  int v16; // edx
  int v17; // ebx
  int v18; // esi
  unsigned int v19; // edi
  unsigned __int8 *v20; // ebx
  int v21; // eax
  int v22; // edx
  IMaterial *material; // eax
  msurface2_t *v24; // edi
  int v25; // edx
  int v26; // esi
  unsigned int v27; // edi
  unsigned __int8 *v28; // ebx
  msurface2_t **m_pMemory; // ecx
  int v30; // edx
  msurface2_t **v31; // esi
  int v32; // edx
  int v33; // ebx
  unsigned int v34; // esi
  unsigned __int8 *v35; // edi
  msurface2_t **v36; // ecx
  int v37; // edx
  msurface2_t **v38; // eax
  msurface2_t *v39; // edi
  int v40; // ecx
  int v41; // esi
  unsigned int v42; // edi
  unsigned __int8 *v43; // ebx
  msurface2_t **v44; // edx
  msurface2_t **v45; // eax
  _DWORD *v46; // esi
  msurface2_t *v47; // ebx
  int v48; // eax
  msurface2_t *v49; // edi
  int v50; // esi
  IOverlayMgr *v51; // eax
  IOverlayMgr *v52; // eax
  IOverlayMgr *v53; // eax
  int v54; // ecx
  int v55; // esi
  BOOL v56; // esi
  msurface2_t **v57; // edi
  int v58; // esi
  int v59; // ebx
  int v60; // eax
  IWorldRenderList_vtbl *v61; // ecx
  int v62; // edx
  int v63; // ecx
  int v64; // eax
  _DWORD *v65; // ecx
  int v66; // edx
  int v67; // ebx
  unsigned int v68; // esi
  unsigned __int8 *v69; // edi
  int *v70; // ecx
  int v71; // esi
  const CViewSetup *v72; // eax
  int v73; // esi
  msurface2_t **v74; // edi
  const CViewSetup *v75; // eax
  transsurfacebatch_t *v76; // eax
  msurface2_t **v77; // eax
  msurface2_t **v78; // eax
  msurface2_t **v79; // eax
  CUtlVectorFixedGrowable<transsurfacebatch_t,16> batches; // [esp+4h] [ebp-2E4h] BYREF
  CUtlVectorFixedGrowable<msurface2_t *,16> surfaceList; // [esp+15Ch] [ebp-18Ch] BYREF
  CUtlVectorFixedGrowable<msurface2_t *,16> flashlightSurfaceList; // [esp+1B4h] [ebp-134h] BYREF
  CUtlVectorFixedGrowable<msurface2_t *,16> decalSurfaceList; // [esp+20Ch] [ebp-DCh] BYREF
  CUtlVectorFixedGrowable<msurface2_t *,16> dispList; // [esp+264h] [ebp-84h] BYREF
  int surfaceIndexStart; // [esp+2BCh] [ebp-2Ch]
  int j; // [esp+2C0h] [ebp-28h]
  transsurfacebatch_t *pLastBatch; // [esp+2C4h] [ebp-24h]
  int v90; // [esp+2C8h] [ebp-20h]
  int bFlashlightMask; // [esp+2CCh] [ebp-1Ch]
  int sortID; // [esp+2D0h] [ebp-18h]
  int i; // [esp+2D4h] [ebp-14h]
  bool skipLight; // [esp+2DBh] [ebp-Dh]
  int leaf; // [esp+2DCh] [ebp-Ch]
  int mask; // [esp+2E0h] [ebp-8h]
  bool bHasDisp; // [esp+2E7h] [ebp-1h]

  v7 = nullptr;
  if ( r_drawtranslucentworld.m_pParent != nullptr && r_drawtranslucentworld.m_pParent->m_Value.m_nValue != 0 )
  {
    v8 = g_pMaterialSystemConfig->nFullbright == 1;
    skipLight = false;
    if ( v8 )
    {
      pRenderContext->BindLightmapPage(this: pRenderContext, a2: -2);
      skipLight = true;
    }
    surfaceList.m_pElements = surfaceList.m_Memory.m_pFixedMemory;
    decalSurfaceList.m_pElements = decalSurfaceList.m_Memory.m_pFixedMemory;
    surfaceList.m_Memory.m_pMemory = surfaceList.m_Memory.m_pFixedMemory;
    flashlightSurfaceList.m_Memory.m_pMemory = flashlightSurfaceList.m_Memory.m_pFixedMemory;
    flashlightSurfaceList.m_pElements = flashlightSurfaceList.m_Memory.m_pFixedMemory;
    v9 = flags;
    m_nAllocationCount = 16;
    surfaceList.m_Memory.m_nGrowSize = -1;
    decalSurfaceList.m_Memory.m_pMemory = decalSurfaceList.m_Memory.m_pFixedMemory;
    decalSurfaceList.m_Memory.m_nGrowSize = -1;
    v11 = 0;
    flashlightSurfaceList.m_Memory.m_nGrowSize = -1;
    dispList.m_Memory.m_pMemory = dispList.m_Memory.m_pFixedMemory;
    dispList.m_Memory.m_nGrowSize = -1;
    dispList.m_pElements = dispList.m_Memory.m_pFixedMemory;
    batches.m_Memory.m_nGrowSize = -1;
    m_Size = 0;
    surfaceList.m_Memory.m_nAllocationCount = 16;
    surfaceList.m_Memory.m_nMallocGrowSize = 0;
    surfaceList.m_Size = 0;
    decalSurfaceList.m_Memory.m_nAllocationCount = 16;
    decalSurfaceList.m_Memory.m_nMallocGrowSize = 0;
    decalSurfaceList.m_Size = 0;
    flashlightSurfaceList.m_Memory.m_nAllocationCount = 16;
    flashlightSurfaceList.m_Memory.m_nMallocGrowSize = 0;
    flashlightSurfaceList.m_Size = 0;
    dispList.m_Memory.m_nAllocationCount = 16;
    dispList.m_Memory.m_nMallocGrowSize = 0;
    dispList.m_Size = 0;
    batches.m_Memory.m_pMemory = batches.m_Memory.m_pFixedMemory;
    batches.m_Memory.m_nAllocationCount = 16;
    batches.m_Memory.m_nMallocGrowSize = 0;
    batches.m_Size = 0;
    batches.m_pElements = batches.m_Memory.m_pFixedMemory;
    pLastBatch = nullptr;
    if ( (flags & 0x80u) != 0 || (LOBYTE(bFlashlightMask) = 1, (flags & 0x100) != 0) )
      LOBYTE(bFlashlightMask) = 0;
    bHasDisp = false;
    i = 0;
    mask = 1;
    do
    {
      if ( (v9 & mask) != 0 )
      {
        v13 = 0;
        leaf = 0;
        if ( sortCount > 0 )
        {
          do
          {
            v14 = &pRenderListIn[164].__vftable[pSortList[v13]];
            Release_low = LOWORD(v14->Release);
            v16 = HIWORD(v14->Release) + Release_low - 1;
            surfaceIndexStart = Release_low;
            for ( j = v16; v16 >= surfaceIndexStart; j = v16 )
            {
              v90 = *((_DWORD *)&pRenderListIn[99].AddRef + v16);
              if ( ((*(_DWORD *)v90 >> 22) & 3) == i )
              {
                if ( *(_DWORD *)(v90 + 24) == 0 )
                {
                  v17 = *(__int16 *)(v90 + 18);
                  sortID = v17;
                  if ( v7 == nullptr || v17 != v7->sortID )
                  {
                    v18 = m_Size;
                    if ( m_Size + 1 > m_nAllocationCount )
                    {
                      pLastBatch = (transsurfacebatch_t *)(m_Size - m_nAllocationCount + 1);
                      if ( batches.m_Memory.m_nGrowSize < 0 )
                      {
                        batches.m_Memory.m_nGrowSize = batches.m_Memory.m_nMallocGrowSize;
                        if ( m_nAllocationCount != 0 )
                        {
                          v19 = 20 * m_nAllocationCount;
                          v20 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v19);
                          memcpy(dst: v20, src: (unsigned __int8 *)batches.m_Memory.m_pMemory, count: v19);
                          batches.m_Memory.m_pMemory = (transsurfacebatch_t *)v20;
                          v17 = sortID;
                        }
                        else
                        {
                          batches.m_Memory.m_pMemory = nullptr;
                        }
                      }
                      CUtlMemory<UtlRBTreeNode_t<void *,int>,int>::Grow(
                        this: (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)&batches,
                        num: (int)pLastBatch);
                      m_Size = batches.m_Size;
                    }
                    batches.m_Size = m_Size + 1;
                    v21 = m_Size - v18;
                    batches.m_pElements = batches.m_Memory.m_pMemory;
                    if ( v21 > 0 )
                      _V_memmove(
                        dest: &batches.m_Memory.m_pMemory[v18 + 1],
                        src: &batches.m_Memory.m_pMemory[v18],
                        count: 20 * v21);
                    v7 = &batches.m_Memory.m_pMemory[v18];
                    v22 = v90;
                    v7->firstSurface = surfaceList.m_Size;
                    v7->surfaceCount = 0;
                    material = host_state.worldbrush->texinfo[*(unsigned __int16 *)(v22 + 22) >> 1].material;
                    pLastBatch = v7;
                    v7->pMaterial = material;
                    v7->sortID = v17;
                    v7->triangleCount = 0;
                  }
                  ++v7->surfaceCount;
                  v24 = (msurface2_t *)v90;
                  v7->triangleCount += *(unsigned __int8 *)(v90 + 3) - 2;
                  v25 = surfaceList.m_Size;
                  v26 = surfaceList.m_Size;
                  if ( surfaceList.m_Size + 1 > surfaceList.m_Memory.m_nAllocationCount )
                  {
                    sortID = surfaceList.m_Size - surfaceList.m_Memory.m_nAllocationCount + 1;
                    if ( surfaceList.m_Memory.m_nGrowSize < 0 )
                    {
                      surfaceList.m_Memory.m_nGrowSize = surfaceList.m_Memory.m_nMallocGrowSize;
                      if ( surfaceList.m_Memory.m_nAllocationCount != 0 )
                      {
                        v27 = 4 * surfaceList.m_Memory.m_nAllocationCount;
                        v28 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(
                                                   this: _g_pMemAlloc,
                                                   a2: 4 * surfaceList.m_Memory.m_nAllocationCount);
                        memcpy(dst: v28, src: (unsigned __int8 *)surfaceList.m_Memory.m_pMemory, count: v27);
                        v24 = (msurface2_t *)v90;
                        surfaceList.m_Memory.m_pMemory = (msurface2_t **)v28;
                      }
                      else
                      {
                        surfaceList.m_Memory.m_pMemory = nullptr;
                      }
                    }
                    CUtlMemory<INetMessage *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&surfaceList, num: sortID);
                    v25 = surfaceList.m_Size;
                  }
                  m_pMemory = surfaceList.m_Memory.m_pMemory;
                  v30 = v25 + 1;
                  surfaceList.m_Size = v30;
                  surfaceList.m_pElements = surfaceList.m_Memory.m_pMemory;
                  if ( v30 - v26 - 1 > 0 )
                  {
                    _V_memmove(
                      dest: &surfaceList.m_Memory.m_pMemory[v26 + 1],
                      src: &surfaceList.m_Memory.m_pMemory[v26],
                      count: 4 * (v30 - v26 - 1));
                    m_pMemory = surfaceList.m_Memory.m_pMemory;
                  }
                  v31 = &m_pMemory[v26];
                  if ( v31 != nullptr )
                    *v31 = v24;
                  if ( v24->m_ShadowDecals != 0xFFFF )
                  {
                    v32 = flashlightSurfaceList.m_Size;
                    v33 = flashlightSurfaceList.m_Size;
                    if ( flashlightSurfaceList.m_Size + 1 > flashlightSurfaceList.m_Memory.m_nAllocationCount )
                    {
                      sortID = flashlightSurfaceList.m_Size - flashlightSurfaceList.m_Memory.m_nAllocationCount + 1;
                      if ( flashlightSurfaceList.m_Memory.m_nGrowSize < 0 )
                      {
                        flashlightSurfaceList.m_Memory.m_nGrowSize = flashlightSurfaceList.m_Memory.m_nMallocGrowSize;
                        if ( flashlightSurfaceList.m_Memory.m_nAllocationCount != 0 )
                        {
                          v34 = 4 * flashlightSurfaceList.m_Memory.m_nAllocationCount;
                          v35 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(
                                                     this: _g_pMemAlloc,
                                                     a2: 4 * flashlightSurfaceList.m_Memory.m_nAllocationCount);
                          memcpy(dst: v35, src: (unsigned __int8 *)flashlightSurfaceList.m_Memory.m_pMemory, count: v34);
                          flashlightSurfaceList.m_Memory.m_pMemory = (msurface2_t **)v35;
                        }
                        else
                        {
                          flashlightSurfaceList.m_Memory.m_pMemory = nullptr;
                        }
                      }
                      CUtlMemory<INetMessage *,int>::Grow(
                        this: (CUtlMemory<S3RGBA,int> *)&flashlightSurfaceList,
                        num: sortID);
                      v32 = flashlightSurfaceList.m_Size;
                    }
                    v36 = flashlightSurfaceList.m_Memory.m_pMemory;
                    v37 = v32 + 1;
                    flashlightSurfaceList.m_Size = v37;
                    flashlightSurfaceList.m_pElements = flashlightSurfaceList.m_Memory.m_pMemory;
                    if ( v37 - v33 - 1 > 0 )
                    {
                      _V_memmove(
                        dest: &flashlightSurfaceList.m_Memory.m_pMemory[v33 + 1],
                        src: &flashlightSurfaceList.m_Memory.m_pMemory[v33],
                        count: 4 * (v37 - v33 - 1));
                      v36 = flashlightSurfaceList.m_Memory.m_pMemory;
                    }
                    v38 = &v36[v33];
                    if ( v38 != nullptr )
                      *v38 = (msurface2_t *)v90;
                  }
                  v39 = (msurface2_t *)v90;
                  if ( *(_WORD *)(v90 + 12) == 0xFFFF && *(_WORD *)(v90 + 16) == 0xFFFF )
                  {
                    v7 = pLastBatch;
LABEL_60:
                    v11 = decalSurfaceList.m_Size;
                  }
                  else
                  {
                    v40 = decalSurfaceList.m_Size;
                    v41 = decalSurfaceList.m_Size;
                    if ( decalSurfaceList.m_Size + 1 > decalSurfaceList.m_Memory.m_nAllocationCount )
                    {
                      sortID = decalSurfaceList.m_Size - decalSurfaceList.m_Memory.m_nAllocationCount + 1;
                      if ( decalSurfaceList.m_Memory.m_nGrowSize < 0 )
                      {
                        decalSurfaceList.m_Memory.m_nGrowSize = decalSurfaceList.m_Memory.m_nMallocGrowSize;
                        if ( decalSurfaceList.m_Memory.m_nAllocationCount != 0 )
                        {
                          v42 = 4 * decalSurfaceList.m_Memory.m_nAllocationCount;
                          v43 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(
                                                     this: _g_pMemAlloc,
                                                     a2: 4 * decalSurfaceList.m_Memory.m_nAllocationCount);
                          memcpy(dst: v43, src: (unsigned __int8 *)decalSurfaceList.m_Memory.m_pMemory, count: v42);
                          v39 = (msurface2_t *)v90;
                          decalSurfaceList.m_Memory.m_pMemory = (msurface2_t **)v43;
                        }
                        else
                        {
                          decalSurfaceList.m_Memory.m_pMemory = nullptr;
                        }
                      }
                      CUtlMemory<INetMessage *,int>::Grow(
                        this: (CUtlMemory<S3RGBA,int> *)&decalSurfaceList,
                        num: sortID);
                      v40 = decalSurfaceList.m_Size;
                    }
                    v44 = decalSurfaceList.m_Memory.m_pMemory;
                    v11 = v40 + 1;
                    decalSurfaceList.m_Size = v11;
                    decalSurfaceList.m_pElements = decalSurfaceList.m_Memory.m_pMemory;
                    if ( v11 - v41 - 1 > 0 )
                    {
                      _V_memmove(
                        dest: &decalSurfaceList.m_Memory.m_pMemory[v41 + 1],
                        src: &decalSurfaceList.m_Memory.m_pMemory[v41],
                        count: 4 * (v11 - v41 - 1));
                      v11 = decalSurfaceList.m_Size;
                      v44 = decalSurfaceList.m_Memory.m_pMemory;
                    }
                    v45 = &v44[v41];
                    v7 = pLastBatch;
                    if ( v45 != nullptr )
                    {
                      *v45 = v39;
                      goto LABEL_60;
                    }
                  }
                  m_Size = batches.m_Size;
                  m_nAllocationCount = batches.m_Memory.m_nAllocationCount;
                  goto LABEL_62;
                }
                bHasDisp = true;
              }
LABEL_62:
              v16 = j - 1;
            }
            v13 = leaf + 1;
            leaf = v13;
          }
          while ( v13 < sortCount );
          v9 = flags;
        }
      }
      ++i;
      mask *= 2;
    }
    while ( i < 4 );
    leaf = 0;
    if ( m_Size > 0 )
    {
      mask = 0;
      do
      {
        v46 = (int *)((char *)&batches.m_Memory.m_pMemory->firstSurface + mask);
        v47 = surfaceList.m_Memory.m_pMemory[*(int *)((char *)&batches.m_Memory.m_pMemory->firstSurface + mask)];
        pRenderContext->Bind(
          this: pRenderContext,
          a2: host_state.worldbrush->texinfo[*((unsigned __int16 *)v47 + 11) >> 1].material,
          a3: nullptr);
        if ( !skipLight )
          pRenderContext->BindLightmapPage(
            this: pRenderContext,
            a2: materialSortInfoArray[v47->materialSortID].lightmapPageID);
        Shader_DrawSurfaceListStatic(
          pRenderContext,
          pList: &surfaceList.m_Memory.m_pMemory[*v46],
          listCount: v46[1],
          triangleCount: v46[4]);
        mask += 20;
        ++leaf;
      }
      while ( leaf < batches.m_Size );
      v11 = decalSurfaceList.m_Size;
    }
    v48 = 0;
    for ( leaf = 0; v48 < v11; leaf = v48 )
    {
      v49 = decalSurfaceList.m_Memory.m_pMemory[v48];
      v50 = (v49->flags >> 22) & 3;
      if ( v49->m_nFirstOverlayFragment != 0xFFFF )
      {
        v51 = OverlayMgr();
        v51->AddFragmentListToRenderList(this: v51, a2: v50, a3: v49->m_nFirstOverlayFragment, a4: false);
        v52 = OverlayMgr();
        v52->RenderOverlays(this: v52, a2: pRenderContext, a3: v50);
        g_pShadowMgr->DrawFlashlightOverlays(this: g_pShadowMgr, a2: pRenderContext, a3: v50, a4: bFlashlightMask);
        v53 = OverlayMgr();
        v53->ClearRenderLists(this: v53, a2: v50);
        v11 = decalSurfaceList.m_Size;
      }
      if ( v49->decals != 0xFFFF )
      {
        DrawDecalsOnSingleSurface(pRenderContext, surfID: v49);
        v11 = decalSurfaceList.m_Size;
      }
      v48 = leaf + 1;
    }
    v54 = flashlightSurfaceList.m_Size;
    if ( flashlightSurfaceList.m_Size != 0 )
    {
      v55 = 0;
      if ( flashlightSurfaceList.m_Size > 0 )
      {
        do
        {
          if ( flashlightSurfaceList.m_Memory.m_pMemory[v55]->m_ShadowDecals != 0xFFFF )
          {
            g_pShadowMgr->AddShadowsOnSurfaceToRenderList(
              this: g_pShadowMgr,
              a2: flashlightSurfaceList.m_Memory.m_pMemory[v55]->m_ShadowDecals);
            v54 = flashlightSurfaceList.m_Size;
          }
          ++v55;
        }
        while ( v55 < v54 );
      }
      v56 = bFlashlightMask;
      ((void (__thiscall *)(IShadowMgrInternal *, int, _DWORD, _DWORD, int, int))g_pShadowMgr->RenderFlashlights)(
        a1: g_pShadowMgr,
        a2: bFlashlightMask,
        a3: 0,
        a4: 0,
        a5: a2,
        a6: a1);
      if ( decalSurfaceList.m_Size != 0 )
        g_pShadowMgr->DrawFlashlightDecalsOnSurfaceList(
          this: g_pShadowMgr,
          a2: pRenderContext,
          a3: flashlightSurfaceList.m_Memory.m_pMemory,
          a4: flashlightSurfaceList.m_Size,
          a5: v56);
      g_pShadowMgr->RenderShadows(this: g_pShadowMgr, a2: pRenderContext, a3: nullptr);
      g_pShadowMgr->ClearShadowRenderList(this: g_pShadowMgr);
    }
    DrawDebugInformation(pRenderContext, pList: surfaceList.m_Memory.m_pMemory, listCount: surfaceList.m_Size);
    v57 = dispList.m_Memory.m_pMemory;
    if ( bHasDisp )
    {
      v58 = dispList.m_Memory.m_nAllocationCount;
      v59 = 0;
      i = 0;
      mask = 1;
      do
      {
        if ( (flags & mask) != 0 )
        {
          for ( bFlashlightMask = 0; bFlashlightMask < sortCount; ++bFlashlightMask )
          {
            v60 = pSortList[bFlashlightMask];
            v61 = pRenderListIn[164].__vftable;
            v62 = LOWORD(v61[v60].Release);
            v63 = v62 + HIWORD(v61[v60].Release) - 1;
            v64 = 0;
            j = v62;
            dispList.m_Size = 0;
            leaf = v63;
            if ( v63 >= v62 )
            {
              while ( 1 )
              {
                v65 = *((_DWORD **)&pRenderListIn[99].AddRef + v63);
                v66 = (*v65 >> 22) & 3;
                sortID = (int)v65;
                if ( v66 == v59 && v65[6] != 0 )
                {
                  v67 = v64;
                  if ( v64 + 1 > v58 )
                  {
                    surfaceIndexStart = v64 - v58 + 1;
                    if ( dispList.m_Memory.m_nGrowSize < 0 )
                    {
                      dispList.m_Memory.m_nGrowSize = dispList.m_Memory.m_nMallocGrowSize;
                      if ( v58 != 0 )
                      {
                        v68 = 4 * v58;
                        v69 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v68);
                        memcpy(dst: v69, src: (unsigned __int8 *)dispList.m_Memory.m_pMemory, count: v68);
                        dispList.m_Memory.m_pMemory = (msurface2_t **)v69;
                      }
                      else
                      {
                        dispList.m_Memory.m_pMemory = nullptr;
                      }
                    }
                    CUtlMemory<INetMessage *,int>::Grow(
                      this: (CUtlMemory<S3RGBA,int> *)&dispList,
                      num: surfaceIndexStart);
                    v64 = dispList.m_Size;
                    v58 = dispList.m_Memory.m_nAllocationCount;
                    v57 = dispList.m_Memory.m_pMemory;
                  }
                  dispList.m_Size = ++v64;
                  dispList.m_pElements = v57;
                  if ( v64 - v67 - 1 > 0 )
                  {
                    _V_memmove(dest: &v57[v67 + 1], src: &v57[v67], count: 4 * (v64 - v67 - 1));
                    v64 = dispList.m_Size;
                    v58 = dispList.m_Memory.m_nAllocationCount;
                    v57 = dispList.m_Memory.m_pMemory;
                  }
                  v70 = (int *)&v57[v67];
                  if ( v70 != nullptr )
                  {
                    *v70 = sortID;
                    v64 = dispList.m_Size;
                    v58 = dispList.m_Memory.m_nAllocationCount;
                    v57 = dispList.m_Memory.m_pMemory;
                  }
                }
                v63 = leaf - 1;
                leaf = v63;
                if ( v63 < j )
                  break;
                v59 = i;
              }
              if ( v64 != 0 )
              {
                v71 = v64;
                v72 = g_EngineRenderer->ViewGetCurrent(this: g_EngineRenderer);
                v59 = i;
                DispInfo_RenderListWorld(
                  a1: i,
                  a2: (int)v57,
                  pRenderContext,
                  nSortGroup: i,
                  pList: v57,
                  listCount: v71,
                  bOrtho: v72->m_bOrtho,
                  flags,
                  bShadowDepth: nullptr);
                v73 = dispList.m_Size;
                v74 = dispList.m_Memory.m_pMemory;
                v75 = g_EngineRenderer->ViewGetCurrent(this: g_EngineRenderer);
                DispInfo_RenderListDecalsAndOverlays(
                  pRenderContext,
                  nSortGroup: v59,
                  pList: v74,
                  listCount: v73,
                  bOrtho: v75->m_bOrtho,
                  flags);
                v58 = dispList.m_Memory.m_nAllocationCount;
                v57 = dispList.m_Memory.m_pMemory;
              }
              else
              {
                v59 = i;
              }
            }
          }
        }
        mask *= 2;
        i = ++v59;
      }
      while ( v59 < 4 );
    }
    v76 = batches.m_Memory.m_pMemory;
    batches.m_Size = 0;
    if ( batches.m_Memory.m_nGrowSize >= 0 )
    {
      if ( batches.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: batches.m_Memory.m_pMemory);
        v57 = dispList.m_Memory.m_pMemory;
        v76 = nullptr;
        batches.m_Memory.m_pMemory = nullptr;
      }
      batches.m_Memory.m_nAllocationCount = 0;
    }
    batches.m_pElements = v76;
    if ( batches.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v76 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v76);
        v57 = dispList.m_Memory.m_pMemory;
        batches.m_Memory.m_pMemory = nullptr;
      }
      batches.m_Memory.m_nAllocationCount = 0;
    }
    dispList.m_Size = 0;
    if ( dispList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v57 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v57);
        v57 = nullptr;
        dispList.m_Memory.m_pMemory = nullptr;
      }
      dispList.m_Memory.m_nAllocationCount = 0;
    }
    dispList.m_pElements = v57;
    if ( dispList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v57 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v57);
        dispList.m_Memory.m_pMemory = nullptr;
      }
      dispList.m_Memory.m_nAllocationCount = 0;
    }
    v77 = flashlightSurfaceList.m_Memory.m_pMemory;
    flashlightSurfaceList.m_Size = 0;
    if ( flashlightSurfaceList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( flashlightSurfaceList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: flashlightSurfaceList.m_Memory.m_pMemory);
        v77 = nullptr;
        flashlightSurfaceList.m_Memory.m_pMemory = nullptr;
      }
      flashlightSurfaceList.m_Memory.m_nAllocationCount = 0;
    }
    flashlightSurfaceList.m_pElements = v77;
    if ( flashlightSurfaceList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v77 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v77);
        flashlightSurfaceList.m_Memory.m_pMemory = nullptr;
      }
      flashlightSurfaceList.m_Memory.m_nAllocationCount = 0;
    }
    v78 = decalSurfaceList.m_Memory.m_pMemory;
    decalSurfaceList.m_Size = 0;
    if ( decalSurfaceList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( decalSurfaceList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: decalSurfaceList.m_Memory.m_pMemory);
        v78 = nullptr;
        decalSurfaceList.m_Memory.m_pMemory = nullptr;
      }
      decalSurfaceList.m_Memory.m_nAllocationCount = 0;
    }
    decalSurfaceList.m_pElements = v78;
    if ( decalSurfaceList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v78 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v78);
        decalSurfaceList.m_Memory.m_pMemory = nullptr;
      }
      decalSurfaceList.m_Memory.m_nAllocationCount = 0;
    }
    v79 = surfaceList.m_Memory.m_pMemory;
    surfaceList.m_Size = 0;
    if ( surfaceList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( surfaceList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: surfaceList.m_Memory.m_pMemory);
        v79 = nullptr;
        surfaceList.m_Memory.m_pMemory = nullptr;
      }
      surfaceList.m_Memory.m_nAllocationCount = 0;
    }
    surfaceList.m_pElements = v79;
    if ( surfaceList.m_Memory.m_nGrowSize >= 0 && v79 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v79);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D91C0
// Name: void R_DrawWorldLists(class IMatRenderContext __near *,class IWorldRenderList __near *,unsigned long,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_DrawWorldLists(
        IMatRenderContext *pRenderContext,
        CWorldRenderList *pRenderListIn,
        unsigned int flags,
        float waterZAdjust)
{
  if ( !g_bTextMode && !g_LostVideoMemory )
  {
    if ( (flags & 0x200) != 0 )
    {
      Shader_WorldEnd(pRenderContext, pRenderList: pRenderListIn, flags, waterZAdjust);
    }
    else if ( (flags & 0x1800) != 0 )
    {
      DrawSimpleWorldModel(a1: (int)pRenderListIn, a2: (int)pRenderContext, a3: flags, flags);
    }
    if ( (flags & 0x400) != 0 )
      Shader_DrawWorldDecalsAndOverlays(pRenderContext, pRenderList: pRenderListIn, flags, waterZAdjust);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D9230
// Name: public: static class CWorldRenderList __near * CWorldRenderList::FindOrCreateList(int)
// Source: json
//------------------------------------------------------------------------------
CWorldRenderList *__cdecl CWorldRenderList::FindOrCreateList(int nSurfaces)
{
  TSLNodeBase_t *v1; // eax
  CWorldRenderList *v2; // esi
  CWorldRenderList *v3; // eax

  v1 = CTSListBase::Pop(this: &CWorldRenderList::g_Pool.m_AvailableObjects);
  if ( v1 != nullptr )
  {
    v2 = *((CWorldRenderList **)&v1->Next + 1);
    free(pMem: v1);
  }
  else
  {
    v3 = (CWorldRenderList *)MemAlloc_Alloc(nSize: 0x2B4u);
    if ( v3 != nullptr )
      v2 = CWorldRenderList::CWorldRenderList(this: v3);
    else
      v2 = nullptr;
  }
  if ( v2->m_VisitedSurfs.m_bits.m_numBits == nSurfaces )
    v2->AddRef(this: v2);
  else
    CWorldRenderList::Init(this: v2, nSurfaces);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x100D92A0
// Name: public: static void CWorldRenderList::PurgeAll(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CWorldRenderList::PurgeAll()
{
  TSLHead_t m_Head; // kr00_8
  int v1; // edi

  while ( 1 )
  {
    m_Head = CWorldRenderList::g_Pool.m_AvailableObjects.m_Head;
    if ( CWorldRenderList::g_Pool.m_AvailableObjects.m_Head.value.Next == nullptr )
      break;
    while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                               a1: &CWorldRenderList::g_Pool,
                               a2: m_Head.value.Next->Next,
                               a3: m_Head.value32.DepthAndSequence - 1,
                               a4: m_Head.value.Next,
                               a5: m_Head.value32.DepthAndSequence) == 0 )
    {
      _mm_pause();
      m_Head = CWorldRenderList::g_Pool.m_AvailableObjects.m_Head;
      if ( CWorldRenderList::g_Pool.m_AvailableObjects.m_Head.value.Next == nullptr )
        return;
    }
    if ( m_Head.value.Next == nullptr )
      break;
    v1 = *((_DWORD *)&m_Head.value.Next->Next + 1);
    free(pMem: m_Head.value.Next);
    if ( v1 == 0 )
      break;
    CWorldRenderList::Purge(this: (CWorldRenderList *)v1);
    (**(void (__thiscall ***)(int, int))(v1 + 4))(a1: v1 + 4, a2: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D9320
// Name: class IWorldRenderList __near * AllocWorldRenderList(void)
// Source: json
//------------------------------------------------------------------------------
CWorldRenderList *__cdecl AllocWorldRenderList()
{
  return CWorldRenderList::FindOrCreateList(nSurfaces: host_state.worldbrush->numsurfaces);
}

//------------------------------------------------------------------------------
// Address: 0x100D9340
// Name: void R_Surface_LevelShutdown(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl R_Surface_LevelShutdown()
{
  CWorldRenderList::PurgeAll();
}

//------------------------------------------------------------------------------
// Address: 0x10314D70
// Name: _dynamic_initializer_for__CWorldRenderList::g_Pool__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CWorldRenderList::g_Pool__()
{
  if ( ((unsigned __int8)&CWorldRenderList::g_Pool & 7) != 0 )
  {
    _Error(a1: "CTSListBase: Misaligned list\n");
    __debugbreak();
  }
  CWorldRenderList::g_Pool = 0;
  return atexit(func: dynamic_atexit_destructor_for__CWorldRenderList::g_Pool__);
}

//------------------------------------------------------------------------------
// Address: 0x10323170
// Name: _dynamic_atexit_destructor_for__CWorldRenderList::g_Pool__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CWorldRenderList::g_Pool__()
{
  TSLNodeBase_t *v0; // eax
  TSLNodeBase_t *Next; // esi

  CObjectPool<CWorldRenderList,0,1>::Purge(this: &CWorldRenderList::g_Pool);
  v0 = CTSListBase::Detach(this: &CWorldRenderList::g_Pool.m_AvailableObjects);
  if ( v0 != nullptr )
  {
    do
    {
      Next = v0->Next;
      free(pMem: v0);
      v0 = Next;
    }
    while ( Next != nullptr );
  }
  CTSListBase::Detach(this: &CWorldRenderList::g_Pool.m_AvailableObjects);
}

//------------------------------------------------------------------------------
// Address: 0x103231B0
// Name: _dynamic_atexit_destructor_for__g_cv_miniprofiler_dump__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_cv_miniprofiler_dump__()
{
  ConVar::~ConVar(this: &g_cv_miniprofiler_dump);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x100CE980
// Name: void Vector2DSubtract(class Vector2D const __near &,class Vector2D const __near &,class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Vector2DSubtract(const Vector2D *a, const Vector2D *b, Vector2D *c)
{
  c->x = a->x - b->x;
  c->y = a->y - b->y;
}

//------------------------------------------------------------------------------
// Address: 0x100CE9B0
// Name: bool MatrixIsIdentity(struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl MatrixIsIdentity(const matrix3x4_t *m)
{
  return m->m_flMatVal[0][0] == 1.0
      && m->m_flMatVal[0][1] == 0.0
      && m->m_flMatVal[0][2] == 0.0
      && m->m_flMatVal[0][3] == 0.0
      && m->m_flMatVal[1][0] == 0.0
      && m->m_flMatVal[1][1] == 1.0
      && m->m_flMatVal[1][2] == 0.0
      && m->m_flMatVal[1][3] == 0.0
      && m->m_flMatVal[2][0] == 0.0
      && m->m_flMatVal[2][1] == 0.0
      && m->m_flMatVal[2][2] == 1.0
      && m->m_flMatVal[2][3] == 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x100CEA80
// Name: int R_GetBrushModelPlaneCount(struct model_t const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl R_GetBrushModelPlaneCount(const model_t *model)
{
  return model->brush.nummodelsurfaces;
}

//------------------------------------------------------------------------------
// Address: 0x100CEA90
// Name: int SortInfoToLightmapPage(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl SortInfoToLightmapPage(int sortID)
{
  return materialSortInfoArray[sortID].lightmapPageID;
}

//------------------------------------------------------------------------------
// Address: 0x100CEAB0
// Name: void R_DrawTopView(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_DrawTopView(bool enable)
{
  r_drawtopview = enable;
}

//------------------------------------------------------------------------------
// Address: 0x100CEAC0
// Name: void R_TopViewBounds(class Vector2D const __near &,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_TopViewBounds(const Vector2D *mins, const Vector2D *maxs)
{
  float v2; // xmm1_4

  s_OrthographicCenter.x = mins->x + maxs->x;
  v2 = (float)(mins->y + maxs->y) * 0.5;
  s_OrthographicCenter.x = s_OrthographicCenter.x * 0.5;
  s_OrthographicCenter.y = v2;
  s_OrthographicHalfDiagonal.x = maxs->x - s_OrthographicCenter.x;
  s_OrthographicHalfDiagonal.y = maxs->y - v2;
}

//------------------------------------------------------------------------------
// Address: 0x100CEB30
// Name: DrawSurfaceID
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawSurfaceID(IMatRenderContext *pRenderContext, msurface2_t *surfID, const Vector *vecCentroid)
{
  char buf[32]; // [esp+8h] [ebp-20h] BYREF

  V_snprintf(pDest: buf, maxLen: 32, pFormat: &args.m_pArgSBuffer[240], surfID);
  CDebugOverlay::AddTextOverlay(textPos: vecCentroid, duration: 0.0, text: buf);
}

//------------------------------------------------------------------------------
// Address: 0x100CEB70
// Name: DrawSurfaceIDAsInt
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawSurfaceIDAsInt(IMatRenderContext *pRenderContext, msurface2_t *surfID, const Vector *vecCentroid)
{
  char buf[32]; // [esp+8h] [ebp-20h] BYREF

  V_snprintf(pDest: buf, maxLen: 32, pFormat: "%d", surfID - host_state.worldbrush->surfaces2);
  CDebugOverlay::AddTextOverlay(textPos: vecCentroid, duration: 0.0, text: buf);
}

//------------------------------------------------------------------------------
// Address: 0x100CEBC0
// Name: class IMaterial __near * R_GetFogVolumeMaterial(int,bool)
// Source: json
//------------------------------------------------------------------------------
IMaterial *__cdecl R_GetFogVolumeMaterial(int nFogVolume, bool bEyeInFogVolume)
{
  IMaterial *material; // esi
  int v3; // eax
  const char *v4; // eax

  if ( nFogVolume < 0 || nFogVolume > host_state.worldbrush->numleafwaterdata )
    return nullptr;
  material = host_state.worldbrush->texinfo[host_state.worldbrush->leafwaterdata[nFogVolume].surfaceTexInfoID].material;
  if ( bEyeInFogVolume )
  {
    v3 = (int)material->FindVar(this: material, a2: &args.m_pArgSBuffer[248], a3: nullptr, a4: true);
    if ( v3 != 0 )
    {
      v4 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v3 + 28))(a1: v3);
      if ( v4 != nullptr )
        return materials->FindMaterial(this: materials, a2: v4, a3: "Other textures", a4: 1, a5: 0);
    }
  }
  return material;
}

//------------------------------------------------------------------------------
// Address: 0x100CEC40
// Name: private: bool CVisibleFogVolumeQuery::RecursiveGetVisibleFogVolume(struct mnode_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVisibleFogVolumeQuery::RecursiveGetVisibleFogVolume(CVisibleFogVolumeQuery *this, mnode_t *node)
{
  mnode_t *v2; // esi
  cplane_t *plane; // eax
  unsigned __int8 type; // cl
  float v6; // xmm0_4
  BOOL v7; // edi
  __int16 plane_high; // ax

  v2 = node;
  if ( node->contents != 1 )
  {
    while ( v2->visframe == r_visframecount && !R_CullNode(pNode: v2) )
    {
      if ( v2->contents >= 0 )
      {
        plane_high = HIWORD(v2->plane);
        if ( plane_high != -1 && (v2->contents & 0x10) == 0 )
        {
          this->m_nVisibleFogVolume = plane_high;
          this->m_nVisibleFogVolumeLeaf = ((char *)v2 - (char *)host_state.worldbrush->leafs) >> 6;
          return 0;
        }
        return 1;
      }
      plane = v2->plane;
      type = plane->type;
      if ( type > 2u )
        v6 = (float)((float)(plane->normal.y * this->m_vecSearchPoint.y)
                   + (float)(plane->normal.x * this->m_vecSearchPoint.x))
           + (float)(plane->normal.z * this->m_vecSearchPoint.z);
      else
        v6 = *(&this->m_vecSearchPoint.x + type);
      v7 = (float)(v6 - plane->dist) < 0.0;
      if ( !CVisibleFogVolumeQuery::RecursiveGetVisibleFogVolume(this, node: v2->children[v7]) )
        return 0;
      v2 = v2->children[!v7];
      if ( v2->contents == 1 )
        return 1;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100CED30
// Name: public: virtual void CBrushSurface::ComputeTextureCoordinate(class Vector const __near &,class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBrushSurface::ComputeTextureCoordinate(
        CBrushSurface *this,
        const Vector *worldPos,
        Vector2D *texCoord)
{
  SurfComputeTextureCoordinate(surfID: this->m_SurfaceID, vec: worldPos, pUV: &texCoord->x);
}

//------------------------------------------------------------------------------
// Address: 0x100CED50
// Name: public: virtual void CBrushSurface::ComputeLightmapCoordinate(class Vector const __near &,class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBrushSurface::ComputeLightmapCoordinate(
        CBrushSurface *this,
        const Vector *worldPos,
        Vector2D *lightmapCoord)
{
  SurfComputeLightmapCoordinate(ctx: &this->m_Ctx, surfID: this->m_SurfaceID, vec: worldPos, uv: lightmapCoord);
}

//------------------------------------------------------------------------------
// Address: 0x100CED70
// Name: void R_InstallBrushRenderOverride(class IBrushRenderer __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_InstallBrushRenderOverride(IBrushRenderer *pBrushRenderer)
{
  s_pBrushRenderOverride = pBrushRenderer;
}

//------------------------------------------------------------------------------
// Address: 0x100CED80
// Name: void R_Surface_LevelInit(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_Surface_LevelInit()
{
  CBrushBatchRender::LevelInit(this: &g_BrushBatchRenderer);
}

//------------------------------------------------------------------------------
// Address: 0x100CEFB0
// Name: void Shader_BrushEnd(class IMatRenderContext __near *,class VMatrix const __near *,struct model_t __near *,bool,class IClientEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Shader_BrushEnd(
        IMatRenderContext *pRenderContext,
        const VMatrix *pBrushToWorld,
        model_t *model,
        bool bShadowDepth)
{
  if ( !bShadowDepth )
  {
    DecalSurfaceDraw(pRenderContext, renderGroup: 4, flFade: r_blend);
    ((void (__thiscall *)(IShadowMgrInternal *, IMatRenderContext *, int, _DWORD, _DWORD))g_pShadowMgr->DrawFlashlightDecals)(
      a1: g_pShadowMgr,
      a2: pRenderContext,
      a3: 4,
      a4: 0,
      a5: LODWORD(r_blend));
    R_DecalFlushDestroyList();
    g_pShadowMgr->RenderProjectedTextures(this: g_pShadowMgr, a2: pRenderContext, a3: pBrushToWorld);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CF010
// Name: public: CBrushModelTransform::CBrushModelTransform(class Vector const __near &,class QAngle const __near &,class IMatRenderContext __near *)
// Source: json
//------------------------------------------------------------------------------
CBrushModelTransform *__thiscall CBrushModelTransform::CBrushModelTransform(
        CBrushModelTransform *this,
        const Vector *origin,
        const QAngle *angles,
        IMatRenderContext *pRenderContext)
{
  bool v5; // cl
  bool v6; // al
  const Vector *v8; // eax
  float v9; // xmm5_4
  float x; // [esp+0h] [ebp-Ch]
  float y; // [esp+4h] [ebp-8h]
  float z; // [esp+8h] [ebp-4h]

  v5 = angles->x != 0.0 || angles->y != 0.0 || angles->z != 0.0;
  v6 = vec3_origin.x == origin->x && vec3_origin.y == origin->y && vec3_origin.z == origin->z && !v5;
  this->m_bIdentity = v6;
  if ( !v6 )
  {
    this->m_savedModelorg = modelorg;
    pRenderContext->MatrixMode(this: pRenderContext, a2: MATERIAL_MODEL);
    pRenderContext->PushMatrix(this: pRenderContext);
    VMatrix::SetupMatrixOrgAngles(this: &g_BrushToWorldMatrix, origin, vAngles: angles);
    pRenderContext->LoadMatrix_2(this: pRenderContext, a2: &g_BrushToWorldMatrix);
    v8 = g_EngineRenderer->ViewOrigin(this: g_EngineRenderer);
    x = v8->x;
    y = v8->y;
    z = v8->z;
    v9 = (float)((float)(g_BrushToWorldMatrix.m[1][2] * (float)(y - g_BrushToWorldMatrix.m[1][3]))
               + (float)(g_BrushToWorldMatrix.m[0][2] * (float)(v8->x - g_BrushToWorldMatrix.m[0][3])))
       + (float)(g_BrushToWorldMatrix.m[2][2] * (float)(z - g_BrushToWorldMatrix.m[2][3]));
    modelorg.x = (float)((float)(g_BrushToWorldMatrix.m[1][0] * (float)(y - g_BrushToWorldMatrix.m[1][3]))
                       + (float)(g_BrushToWorldMatrix.m[0][0] * (float)(v8->x - g_BrushToWorldMatrix.m[0][3])))
               + (float)(g_BrushToWorldMatrix.m[2][0] * (float)(z - g_BrushToWorldMatrix.m[2][3]));
    modelorg.y = (float)((float)(g_BrushToWorldMatrix.m[1][1] * (float)(y - g_BrushToWorldMatrix.m[1][3]))
                       + (float)(g_BrushToWorldMatrix.m[0][1] * (float)(x - g_BrushToWorldMatrix.m[0][3])))
               + (float)(g_BrushToWorldMatrix.m[2][1] * (float)(z - g_BrushToWorldMatrix.m[2][3]));
    modelorg.z = v9;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100CF1F0
// Name: public: CBrushModelTransform::CBrushModelTransform(class matrix3x4a_t const __near &,class IMatRenderContext __near *)
// Source: json
//------------------------------------------------------------------------------
CBrushModelTransform *__thiscall CBrushModelTransform::CBrushModelTransform(
        CBrushModelTransform *this,
        const matrix3x4a_t *matrix,
        IMatRenderContext *pRenderContext)
{
  bool IsIdentity; // al
  const Vector *v6; // eax
  float x; // [esp+8h] [ebp-10h]
  float y; // [esp+Ch] [ebp-Ch]
  float z; // [esp+10h] [ebp-8h]

  IsIdentity = MatrixIsIdentity(m: matrix);
  this->m_bIdentity = IsIdentity;
  if ( IsIdentity )
    return this;
  this->m_savedModelorg = modelorg;
  pRenderContext->MatrixMode(this: pRenderContext, a2: MATERIAL_MODEL);
  pRenderContext->PushMatrix(this: pRenderContext);
  *(matrix3x4a_t *)&g_BrushToWorldMatrix.m[0][0] = *matrix;
  *(_QWORD *)&g_BrushToWorldMatrix.m[3][0] = 0;
  *(_QWORD *)&g_BrushToWorldMatrix.m[3][2] = 0x3F80000000000000LL;
  pRenderContext->LoadMatrix_2(this: pRenderContext, a2: &g_BrushToWorldMatrix);
  v6 = g_EngineRenderer->ViewOrigin(this: g_EngineRenderer);
  x = v6->x;
  y = v6->y;
  z = v6->z;
  modelorg.x = (float)((float)(g_BrushToWorldMatrix.m[1][0] * (float)(y - g_BrushToWorldMatrix.m[1][3]))
                     + (float)(g_BrushToWorldMatrix.m[0][0] * (float)(v6->x - g_BrushToWorldMatrix.m[0][3])))
             + (float)(g_BrushToWorldMatrix.m[2][0] * (float)(z - g_BrushToWorldMatrix.m[2][3]));
  modelorg.y = (float)((float)(g_BrushToWorldMatrix.m[1][1] * (float)(y - g_BrushToWorldMatrix.m[1][3]))
                     + (float)(g_BrushToWorldMatrix.m[0][1] * (float)(x - g_BrushToWorldMatrix.m[0][3])))
             + (float)(g_BrushToWorldMatrix.m[2][1] * (float)(z - g_BrushToWorldMatrix.m[2][3]));
  modelorg.z = (float)((float)(g_BrushToWorldMatrix.m[1][2] * (float)(y - g_BrushToWorldMatrix.m[1][3]))
                     + (float)(g_BrushToWorldMatrix.m[0][2] * (float)(x - g_BrushToWorldMatrix.m[0][3])))
             + (float)(g_BrushToWorldMatrix.m[2][2] * (float)(z - g_BrushToWorldMatrix.m[2][3]));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100CF3C0
// Name: EnumerateLeavesAlongRay_R
// Source: json
//------------------------------------------------------------------------------
bool __cdecl EnumerateLeavesAlongRay_R(
        mnode_t *node,
        const Ray_t *ray,
        float start,
        float end,
        ISpatialLeafEnumerator *pEnum,
        int context)
{
  mnode_t *v6; // esi
  int contents; // eax
  float v8; // xmm6_4
  float v9; // xmm5_4
  cplane_t *plane; // eax
  int type; // ecx
  float v12; // xmm2_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  BOOL v16; // edi
  float mid; // [esp+24h] [ebp+8h]

  v6 = node;
  contents = node->contents;
  if ( node->contents == 1 )
    return true;
  v8 = end;
  v9 = start;
  while ( 1 )
  {
    if ( contents >= 0 )
      return pEnum->EnumerateLeaf(
               this: pEnum,
               a2: ((char *)v6 - (char *)host_state.worldbrush->leafs) >> 6,
               a3: context);
    plane = v6->plane;
    if ( plane->type > 2u )
    {
      v12 = (float)((float)(ray->m_Start.y * plane->normal.y) + (float)(ray->m_Start.x * plane->normal.x))
          + (float)(ray->m_Start.z * plane->normal.z);
      v13 = (float)((float)(ray->m_Delta.y * plane->normal.y) + (float)(plane->normal.x * ray->m_Delta.x))
          + (float)(ray->m_Delta.z * plane->normal.z);
    }
    else
    {
      type = plane->type;
      v12 = *(&ray->m_Start.x + type);
      v13 = *(&ray->m_Delta.x + type);
    }
    v14 = (float)((float)(v13 * v9) + v12) - plane->dist;
    v15 = (float)((float)(v13 * v8) + v12) - plane->dist;
    v16 = v14 < 0.0;
    if ( v15 < 0.0 != v16 )
      break;
    v6 = v6->children[v16];
LABEL_11:
    contents = v6->contents;
    if ( v6->contents == 1 )
      return true;
  }
  mid = (float)((float)(1.0 - (float)(v14 / (float)(v14 - v15))) * v9) + (float)((float)(v14 / (float)(v14 - v15)) * v8);
  if ( EnumerateLeavesAlongRay_R(node: v6->children[v16], ray, start, end: mid, pEnum, context) )
  {
    v9 = (float)((float)(1.0 - (float)(v14 / (float)(v14 - v15))) * v9)
       + (float)((float)(v14 / (float)(v14 - v15)) * v8);
    v8 = end;
    start = mid;
    v6 = v6->children[v14 >= 0.0];
    goto LABEL_11;
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x100CF540
// Name: public: virtual bool CEngineBSPTree::EnumerateLeavesAtPoint(class Vector const __near &,class ISpatialLeafEnumerator __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineBSPTree::EnumerateLeavesAtPoint(
        CEngineBSPTree *this,
        const Vector *pt,
        ISpatialLeafEnumerator *pEnum,
        int context)
{
  int v4; // eax

  v4 = CM_PointLeafnum(p: pt);
  return pEnum->EnumerateLeaf(this: pEnum, a2: v4, a3: context);
}

//------------------------------------------------------------------------------
// Address: 0x100CF570
// Name: public: virtual int CEngineBSPTree::ListLeavesInSphereWithFlagSet(int __near *,class Vector const __near &,float,int,unsigned short const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineBSPTree::ListLeavesInSphereWithFlagSet(
        CEngineBSPTree *this,
        int *pLeafsInSphere,
        const Vector *vecCenter,
        float flRadius,
        int nLeafCount,
        const unsigned __int16 *pLeafs,
        int nLeafStride,
        int nFlagsCheck)
{
  int v8; // ebx
  int i; // esi
  mleaf_t *v11; // eax

  v8 = 0;
  for ( i = 0; i < nLeafCount; ++i )
  {
    v11 = &host_state.worldbrush->leafs[*pLeafs];
    if ( (v11->flags & nFlagsCheck) != 0
      && IsBoxIntersectingSphereExtents(
           boxCenter: &v11->m_vecCenter,
           boxHalfDiag: &v11->m_vecHalfDiagonal,
           center: vecCenter,
           radius: flRadius) )
    {
      pLeafsInSphere[v8++] = i;
    }
    pLeafs = (const unsigned __int16 *)((char *)pLeafs + nLeafStride);
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x100CF5E0
// Name: public: virtual bool CEngineBSPTree::EnumerateLeavesInBox(class Vector const __near &,class Vector const __near &,class ISpatialLeafEnumerator __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CEngineBSPTree::EnumerateLeavesInBox@<al>(
        CEngineBSPTree *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        const Vector *mins,
        const Vector *maxs,
        ISpatialLeafEnumerator *pEnum,
        int context)
{
  int v8; // edi
  int i; // esi
  unsigned __int16 list[1024]; // [esp+0h] [ebp-800h] BYREF

  if ( host_state.worldmodel == nullptr )
    return 0;
  v8 = ((int (__thiscall *)(CEngineBSPTree *, const Vector *, const Vector *, unsigned __int16 *, int, int, int))this->ListLeavesInBox)(
         a1: this,
         a2: mins,
         a3: maxs,
         a4: list,
         a5: 1024,
         a6: a2,
         a7: a3);
  for ( i = 0; i < v8; ++i )
  {
    if ( pEnum->EnumerateLeaf(this: pEnum, a2: list[i], a3: context) == 0 )
      break;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100CF650
// Name: public: void CIndexBuilder::FastIndexList(unsigned short const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CIndexBuilder::FastIndexList(CIndexBuilder *this, char *pIndexList, int startVert, int indexCount)
{
  signed int v4; // esi
  unsigned __int16 *v5; // eax
  char *v6; // edx
  unsigned int v7; // edi
  unsigned __int16 v8; // bx
  int m_nCurrentIndex; // eax
  int startVerta; // [esp+10h] [ebp+Ch]

  v4 = indexCount * this->m_nIndexSize;
  v5 = &this->m_pIndices[this->m_nCurrentIndex];
  startVerta = this->m_nIndexOffset + startVert;
  if ( v4 > 0 )
  {
    v6 = (char *)(pIndexList - (char *)v5);
    v7 = indexCount * this->m_nIndexSize;
    do
    {
      v8 = startVerta + *(unsigned __int16 *)((char *)v5++ + (_DWORD)v6);
      --v7;
      *(v5 - 1) = v8;
    }
    while ( v7 != 0 );
  }
  this->m_nCurrentIndex += v4 * this->m_nIndexSize;
  m_nCurrentIndex = this->m_nCurrentIndex;
  if ( m_nCurrentIndex > this->m_nIndexCount )
    this->m_nIndexCount = m_nCurrentIndex;
}

//------------------------------------------------------------------------------
// Address: 0x100CF6B0
// Name: struct cplane_t const __near & R_GetBrushModelPlane(struct model_t const __near *,int,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
const cplane_t *__cdecl R_GetBrushModelPlane(const model_t *model, int nIndex, Vector *pOrigin)
{
  int v3; // eax
  float *v5; // edx
  float v6; // xmm0_4

  v3 = *(_DWORD *)(model->sprite.numframes + 124) + 32 * (nIndex + model->brush.firstmodelsurface);
  if ( pOrigin != nullptr )
  {
    if ( *(_BYTE *)(v3 + 3) != 0 )
    {
      *pOrigin = *(Vector *)(*(_DWORD *)(model->sprite.numframes + 36)
                           + 12
                           * *(unsigned __int16 *)(*(_DWORD *)(model->sprite.numframes + 148) + 2 * *(_DWORD *)(v3 + 8)));
      return *(const cplane_t **)(v3 + 4);
    }
    v5 = *(float **)(v3 + 4);
    v6 = v5[3];
    pOrigin->x = *v5 * v6;
    pOrigin->y = v5[1] * v6;
    pOrigin->z = v5[2] * v6;
  }
  return *(const cplane_t **)(v3 + 4);
}

//------------------------------------------------------------------------------
// Address: 0x100CF750
// Name: void Surf_ComputeCentroid(struct msurface2_t __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Surf_ComputeCentroid(msurface2_t *surfID, Vector *pVecCentroid)
{
  int firstvertindex; // edx
  worldbrushdata_t *worldbrush; // esi
  mvertex_t *v4; // eax
  float z; // xmm6_4
  float y; // xmm7_4
  unsigned __int16 *v7; // edx
  mvertex_t *vertexes; // esi
  float *p_x; // eax
  float v10; // edi
  float *v11; // eax
  float v12; // edx
  float v13; // eax
  float v14; // xmm4_4
  float v15; // xmm2_4
  float v16; // xmm1_4
  float v17; // xmm4_4
  float v18; // xmm5_4
  float v19; // xmm0_4
  bool v20; // zf
  float v21; // xmm1_4
  float v22; // [esp-24h] [ebp-5Ch]
  float v23; // [esp-Ch] [ebp-44h]
  float v2; // [esp+0h] [ebp-38h]
  float v2_8; // [esp+8h] [ebp-30h]
  float v1; // [esp+Ch] [ebp-2Ch]
  float v1_4; // [esp+10h] [ebp-28h]
  float v1_8; // [esp+14h] [ebp-24h]
  int vecApex; // [esp+18h] [ebp-20h]
  int vecApexa; // [esp+18h] [ebp-20h]
  float vecApex_4; // [esp+1Ch] [ebp-1Ch]
  float vecApex_8; // [esp+20h] [ebp-18h]
  float nCount; // [esp+24h] [ebp-14h]
  int v34; // [esp+28h] [ebp-10h]

  firstvertindex = surfID->firstvertindex;
  vecApex = HIBYTE(surfID->flags);
  pVecCentroid->x = 0.0;
  pVecCentroid->y = 0.0;
  pVecCentroid->z = 0.0;
  worldbrush = host_state.worldbrush;
  v4 = &host_state.worldbrush->vertexes[host_state.worldbrush->vertindices[firstvertindex]];
  v1 = v4->position.x;
  v1_8 = v4->position.z;
  nCount = 0.0;
  v1_4 = v4->position.y;
  if ( vecApex - 1 > 1 )
  {
    z = v4->position.z;
    y = v4->position.y;
    vecApex_8 = 0.0;
    vecApex_4 = 0.0;
    v34 = 2 * firstvertindex + 2;
    vecApexa = vecApex - 2;
    while ( 1 )
    {
      v7 = (unsigned __int16 *)((char *)worldbrush->vertindices + v34);
      vertexes = worldbrush->vertexes;
      p_x = &vertexes[*v7].position.x;
      v2 = *p_x;
      v10 = p_x[1];
      v2_8 = p_x[2];
      v11 = &vertexes[v7[1]].position.x;
      v23 = *v11;
      v12 = v11[1];
      v13 = v11[2];
      v14 = (float)(v12 - v10) * (float)(v2_8 - z);
      v15 = (float)(v2_8 - z) * (float)(v23 - v2);
      z = v1_8;
      v16 = (float)((float)((float)((float)(v13 - v2_8) * (float)(v2 - v1)) - v15)
                  * (float)((float)((float)(v13 - v2_8) * (float)(v2 - v1)) - v15))
          + (float)((float)((float)((float)(v10 - y) * (float)(v23 - v2))
                          - (float)((float)(v12 - v10) * (float)(v2 - v1)))
                  * (float)((float)((float)(v10 - y) * (float)(v23 - v2))
                          - (float)((float)(v12 - v10) * (float)(v2 - v1))));
      v17 = v14 - (float)((float)(v13 - v2_8) * (float)(v10 - y));
      y = v1_4;
      v22 = fsqrt(v16 + (float)(v17 * v17));
      v18 = v22 + nCount;
      v19 = pVecCentroid->x + (float)((float)((float)((float)(v1 + v2) + v23) * v22) * 0.33333334);
      nCount = v22 + nCount;
      pVecCentroid->x = v19;
      vecApex_8 = (float)((float)((float)((float)(v1_4 + v10) + v12) * v22) * 0.33333334) + vecApex_8;
      v34 += 2;
      v20 = vecApexa-- == 1;
      pVecCentroid->y = vecApex_8;
      v21 = vecApex_4 + (float)((float)((float)((float)(v1_8 + v2_8) + v13) * v22) * 0.33333334);
      vecApex_4 = v21;
      pVecCentroid->z = v21;
      if ( v20 )
        break;
      worldbrush = host_state.worldbrush;
    }
    if ( v18 != 0.0 )
    {
      pVecCentroid->x = v19 * (float)(1.0 / v18);
      pVecCentroid->y = vecApex_8 * (float)(1.0 / v18);
      pVecCentroid->z = v21 * (float)(1.0 / v18);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CF9B0
// Name: class IMaterial __near * Shader_SetChainTextureState(class IMatRenderContext __near *,struct msurface2_t __near *,class IClientEntity __near *,bool)
// Source: json
//------------------------------------------------------------------------------
IMaterial *__cdecl Shader_SetChainTextureState(
        IMatRenderContext *pRenderContext,
        msurface2_t *surfID,
        IClientEntity *pBaseEntity,
        bool bShadowDepth)
{
  IMaterial *material; // esi
  BOOL v5; // ebx
  IMaterial *v6; // edi
  IMaterialVar *v7; // ebx
  msurface2_t **v8; // esi
  int v9; // eax
  int v10; // eax
  IClientRenderable *v12; // eax
  IMatRenderContext_vtbl *v13; // edx
  void (__thiscall *BindLightmapPage)(IMatRenderContext *, int); // eax
  float v15; // [esp+38h] [ebp-1Ch]
  IMaterialVar *pOriginalAlphaRefVar; // [esp+48h] [ebp-Ch]
  IMaterialVar *pOriginalTextureFrameVar; // [esp+4Ch] [ebp-8h]
  IMaterialVar *pTextureFrameVar; // [esp+50h] [ebp-4h]
  msurface2_t *surfIDa; // [esp+60h] [ebp+Ch]
  IMaterialVar *pAlphaRefVar; // [esp+68h] [ebp+14h]

  material = host_state.worldbrush->texinfo[*((unsigned __int16 *)surfID + 11) >> 1].material;
  if ( bShadowDepth )
  {
    v5 = material->IsAlphaTested(this: host_state.worldbrush->texinfo[*((unsigned __int16 *)surfID + 11) >> 1].material);
    v6 = g_pMaterialDepthWrite[v5][(unsigned __int8)material->IsTwoSided(this: material)];
    if ( v5 )
    {
      v7 = material->FindVarFast(this: material, a2: "$basetexture", a3: &originalTextureVarCache_2);
      pOriginalTextureFrameVar = material->FindVarFast(
                                   this: material,
                                   a2: "$frame",
                                   a3: &originalTextureFrameVarCache_2);
      pOriginalAlphaRefVar = material->FindVarFast(
                               this: material,
                               a2: "$AlphaTestReference",
                               a3: &originalAlphaRefCache_2);
      v8 = (msurface2_t **)v6->FindVarFast(this: v6, a2: "$basetexture", a3: &textureVarCache_2);
      pTextureFrameVar = v6->FindVarFast(this: v6, a2: "$frame", a3: &textureFrameVarCache_2);
      pAlphaRefVar = v6->FindVarFast(this: v6, a2: "$AlphaTestReference", a3: &alphaRefCache_2);
      if ( v8 != nullptr && v7 != nullptr )
      {
        surfIDa = *v8;
        v9 = v7->GetTextureValue(this: v7);
        ((void (__thiscall *)(msurface2_t **, int))surfIDa[1].visframe)(a1: v8, a2: v9);
      }
      if ( pTextureFrameVar != nullptr && pOriginalTextureFrameVar != nullptr )
      {
        v10 = pOriginalTextureFrameVar->GetIntValueInternal(this: pOriginalTextureFrameVar);
        pTextureFrameVar->SetIntValue(this: pTextureFrameVar, a2: v10);
      }
      if ( pAlphaRefVar != nullptr && pOriginalAlphaRefVar != nullptr )
      {
        v15 = pOriginalAlphaRefVar->GetFloatValueInternal(this: pOriginalAlphaRefVar);
        ((void (__stdcall *)(_DWORD))pAlphaRefVar->SetFloatValue)(a1: LODWORD(v15));
      }
    }
    pRenderContext->Bind(this: pRenderContext, a2: v6, a3: nullptr);
    return v6;
  }
  else
  {
    if ( pBaseEntity != nullptr )
      v12 = pBaseEntity->GetClientRenderable(this: pBaseEntity);
    else
      v12 = nullptr;
    pRenderContext->Bind(this: pRenderContext, a2: material, a3: (void *)v12);
    v13 = pRenderContext->__vftable;
    if ( g_pMaterialSystemConfig->nFullbright == 1 )
    {
      BindLightmapPage = v13->BindLightmapPage;
      if ( (surfID->flags & 8) != 0 )
        BindLightmapPage(this: pRenderContext, a2: -2);
      else
        BindLightmapPage(this: pRenderContext, a2: -1);
      return material;
    }
    else
    {
      v13->BindLightmapPage(this: pRenderContext, a2: materialSortInfoArray[surfID->materialSortID].lightmapPageID);
      return material;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CFB90
// Name: void Shader_AddSurfaceDynamic(class CMeshBuilder __near &,struct msurface2_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Shader_AddSurfaceDynamic(CMeshBuilder *meshBuilder, msurface2_t *surfID)
{
  worldbrushdata_t *worldbrush; // edi
  CIndexBuilder *p_m_IndexBuilder; // ecx
  unsigned __int16 firstPrimID; // ax
  int v6; // eax
  int startVert; // [esp+14h] [ebp+8h]

  worldbrush = host_state.worldbrush;
  startVert = meshBuilder->m_VertexBuilder.m_nVertexCount;
  BuildMSurfaceVertexArrays(pBrushData: host_state.worldbrush, surfID, builder: meshBuilder);
  p_m_IndexBuilder = &meshBuilder->m_IndexBuilder;
  if ( (surfID->flags & 0x8000) != 0 )
  {
    if ( (surfID->flags & 0x800) != 0 )
      firstPrimID = 0;
    else
      firstPrimID = worldbrush->surfaces1[surfID - worldbrush->surfaces2].prims.firstPrimID;
    v6 = (int)&worldbrush->primitives[firstPrimID];
    CIndexBuilder::FastIndexList(
      this: p_m_IndexBuilder,
      pIndexList: (char *)&worldbrush->primindices[*(unsigned __int16 *)(v6 + 4)],
      startVert,
      indexCount: *(unsigned __int16 *)(v6 + 6));
  }
  else
  {
    CIndexBuilder::FastPolygon(this: p_m_IndexBuilder, startVert, triangleCount: HIBYTE(surfID->flags) - 2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CFC30
// Name: DrawSurfaceMaterial
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawSurfaceMaterial(IMatRenderContext *pRenderContext, msurface2_t *surfID, const Vector *vecCentroid)
{
  mtexinfo_t *v3; // eax
  unsigned __int8 *v4; // esi
  unsigned int v5; // eax
  unsigned int v6; // edi
  unsigned int v7; // eax
  const char *v8; // eax

  v3 = &host_state.worldbrush->texinfo[*((unsigned __int16 *)surfID + 11) >> 1];
  if ( v3->material != nullptr )
    v4 = (unsigned __int8 *)v3->material->GetName(this: v3->material);
  else
    v4 = "no material";
  strrchr(string: v4, chr: 0x2Fu);
  v6 = v5;
  strrchr(string: v4, chr: 0x5Cu);
  if ( v6 > v7 )
    v7 = v6;
  if ( v7 != 0 )
    v8 = (const char *)(v7 + 1);
  else
    v8 = (const char *)v4;
  CDebugOverlay::AddTextOverlay(textPos: vecCentroid, duration: 0.0, text: v8);
}

//------------------------------------------------------------------------------
// Address: 0x100CFCB0
// Name: void Shader_DrawSurfaceDebuggingInfo(class IMatRenderContext __near *,struct msurface2_t __near * __near *,int,void (*)(class IMatRenderContext __near *,struct msurface2_t __near *,class Vector const __near &))
// Source: json
//------------------------------------------------------------------------------
void __usercall Shader_DrawSurfaceDebuggingInfo(
        int a1@<ebp>,
        IMatRenderContext *pRenderContext,
        msurface2_t **pList,
        int listCount,
        void (__cdecl *func)(IMatRenderContext *, msurface2_t *, const Vector *))
{
  float v5; // ecx
  msurface2_t *v6; // edi
  unsigned __int8 flags_high; // al
  unsigned __int16 *vertindices; // edx
  int firstvertindex; // ecx
  mvertex_t *v10; // eax
  float y; // edx
  float v12; // xmm6_4
  float v13; // xmm7_4
  float v14; // xmm4_4
  int v15; // ecx
  unsigned __int16 *v16; // ecx
  mvertex_t *vertexes; // edx
  float *p_x; // eax
  float v19; // edi
  float *v20; // eax
  float v21; // xmm5_4
  float v22; // xmm4_4
  float v23; // xmm2_4
  float v24; // xmm0_4
  float v25; // xmm4_4
  float v26; // xmm1_4
  float v27; // xmm5_4
  float v28; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm2_4
  bool v31; // zf
  float v32; // edi
  float v33; // [esp-4Ch] [ebp-6Ch]
  float v34; // [esp-2Ch] [ebp-4Ch]
  float v35; // [esp-28h] [ebp-48h]
  float v36; // [esp-24h] [ebp-44h]
  float v37; // [esp-1Ch] [ebp-3Ch]
  float x; // [esp-18h] [ebp-38h]
  float v39; // [esp-14h] [ebp-34h]
  float z; // [esp-10h] [ebp-30h]
  float v41; // [esp-Ch] [ebp-2Ch] BYREF
  float v42; // [esp-8h] [ebp-28h]
  float v43; // [esp-4h] [ebp-24h]
  Vector vecCentroid; // [esp+0h] [ebp-20h]
  int i; // [esp+Ch] [ebp-14h]
  msurface2_t *surfID; // [esp+10h] [ebp-10h]
  int v47; // [esp+14h] [ebp-Ch]
  void *v48; // [esp+18h] [ebp-8h]
  void *retaddr; // [esp+20h] [ebp+0h]

  v47 = a1;
  v48 = retaddr;
  v5 = 0.0;
  vecCentroid.x = 0.0;
  if ( listCount > 0 )
  {
    do
    {
      v6 = pList[LODWORD(v5)];
      flags_high = HIBYTE(v6->flags);
      LODWORD(vecCentroid.y) = v6;
      if ( flags_high >= 3u )
      {
        v41 = 0.0;
        v42 = 0.0;
        v43 = 0.0;
        vertindices = host_state.worldbrush->vertindices;
        LODWORD(vecCentroid.z) = flags_high;
        firstvertindex = v6->firstvertindex;
        v10 = &host_state.worldbrush->vertexes[vertindices[firstvertindex]];
        x = v10->position.x;
        y = v10->position.y;
        z = v10->position.z;
        *(float *)&surfID = 0.0;
        v39 = y;
        v12 = z;
        v13 = y;
        v14 = x;
        v15 = 2 * firstvertindex + 2;
        i = v15;
        LODWORD(vecCentroid.z) -= 2;
        do
        {
          v16 = (unsigned __int16 *)((char *)host_state.worldbrush->vertindices + v15);
          vertexes = host_state.worldbrush->vertexes;
          p_x = &vertexes[*v16].position.x;
          v36 = *p_x;
          v19 = p_x[1];
          v37 = p_x[2];
          v20 = &vertexes[v16[1]].position.x;
          v21 = v36 - v14;
          v34 = v20[1];
          v35 = v20[2];
          v22 = (float)(v34 - v19) * (float)(v37 - v12);
          v23 = (float)(v37 - v12) * (float)(*v20 - v36);
          v12 = z;
          v24 = (float)((float)(v19 - v13) * (float)(*v20 - v36)) - (float)((float)(v34 - v19) * v21);
          v25 = v22 - (float)((float)(v35 - v37) * (float)(v19 - v13));
          v13 = v39;
          v26 = (float)((float)((float)((float)((float)(v35 - v37) * v21) - v23)
                              * (float)((float)((float)(v35 - v37) * v21) - v23))
                      + (float)(v24 * v24))
              + (float)(v25 * v25);
          v14 = x;
          v33 = fsqrt(v26);
          v27 = v33 + *(float *)&surfID;
          v28 = (float)((float)((float)((float)(x + v36) + *v20) * v33) * 0.33333334) + v41;
          v29 = (float)((float)((float)((float)(v39 + v19) + v34) * v33) * 0.33333334) + v42;
          v30 = (float)((float)((float)((float)(z + v37) + v35) * v33) * 0.33333334) + v43;
          *(float *)&surfID = v33 + *(float *)&surfID;
          v41 = v28;
          v42 = v29;
          v43 = v30;
          v15 = i + 2;
          v31 = LODWORD(vecCentroid.z)-- == 1;
          i += 2;
        }
        while ( !v31 );
        v32 = vecCentroid.y;
        if ( v27 != 0.0 )
        {
          v41 = v28 * (float)(1.0 / v27);
          v42 = (float)(1.0 / v27) * v29;
          v43 = (float)(1.0 / v27) * v30;
        }
        VectorTransform(in1: &v41, in2: (const matrix3x4_t *)&g_BrushToWorldMatrix, out: &v41);
        func(a1: pRenderContext, a2: (msurface2_t *)LODWORD(v32), a3: (const Vector *)&v41);
        v5 = vecCentroid.x;
      }
      ++LODWORD(v5);
      vecCentroid.x = v5;
    }
    while ( SLODWORD(v5) < listCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CFF40
// Name: ComputeFogVolumeInfo
// Source: json
//------------------------------------------------------------------------------
void __usercall ComputeFogVolumeInfo(FogVolumeInfo_t *pFogVolume@<edi>)
{
  int v1; // eax
  mleaf_t *v2; // eax
  int leafWaterDataID; // ecx
  mleafwaterdata_t *v4; // ebx
  __int16 surfaceTexInfoID; // ax
  IMaterial *material; // esi
  int v7; // esi
  double minZ; // st7
  IMaterialVar *pFogStartVar; // [esp+0h] [ebp-Ch]
  IMaterialVar *pFogColorVar; // [esp+4h] [ebp-8h]
  IMaterialVar *pFogEnableVar; // [esp+8h] [ebp-4h]

  pFogVolume->m_InFogVolume = false;
  v1 = CM_PointLeafnum(p: &g_CurrentViewOrigin);
  if ( v1 >= 0 && v1 < host_state.worldbrush->numleafs )
  {
    v2 = &host_state.worldbrush->leafs[v1];
    leafWaterDataID = v2->leafWaterDataID;
    pFogVolume->m_FogVolumeID = leafWaterDataID;
    if ( leafWaterDataID != -1 )
    {
      pFogVolume->m_InFogVolume = true;
      v4 = &host_state.worldbrush->leafwaterdata[v2->leafWaterDataID];
      surfaceTexInfoID = v4->surfaceTexInfoID;
      if ( surfaceTexInfoID == -1 )
      {
        pFogVolume->m_FogEnabled = false;
      }
      else
      {
        material = host_state.worldbrush->texinfo[surfaceTexInfoID].material;
        if ( material != nullptr )
        {
          pFogColorVar = material->FindVar(this: material, a2: &args.m_pArgSBuffer[368], a3: nullptr, a4: true);
          pFogEnableVar = material->FindVar(this: material, a2: &args.m_pArgSBuffer[356], a3: nullptr, a4: true);
          pFogStartVar = material->FindVar(this: material, a2: &args.m_pArgSBuffer[344], a3: nullptr, a4: true);
          v7 = (int)material->FindVar(this: material, a2: &args.m_pArgSBuffer[336], a3: nullptr, a4: true);
          pFogVolume->m_FogEnabled = pFogEnableVar->GetIntValueInternal(this: pFogEnableVar) != 0;
          pFogColorVar->GetVecValueInternal(this: pFogColorVar, a2: pFogVolume->m_FogColor, a3: 3);
          pFogVolume->m_FogStart = -((double (__thiscall *)(IMaterialVar *))pFogStartVar->GetFloatValueInternal)(a1: pFogStartVar);
          pFogVolume->m_FogEnd = -((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v7 + 112))(a1: v7);
          pFogVolume->m_FogSurfaceZ = v4->surfaceZ;
          minZ = v4->minZ;
          pFogVolume->m_FogMode = MATERIAL_FOG_LINEAR;
          pFogVolume->m_FogMinZ = minZ;
        }
        else
        {
          if ( !bComplained )
          {
            _Warning(a1: &args.m_pArgSBuffer[268]);
            bComplained = true;
          }
          pFogVolume->m_FogEnabled = false;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D00A0
// Name: void Shader_GetSurfVertexAndIndexCount(struct msurface2_t __near *,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Shader_GetSurfVertexAndIndexCount(msurface2_t *surfaceHandle, int *pVertexCount, int *pIndexCount)
{
  unsigned __int16 firstPrimID; // ax
  mprimitive_t *primitives; // edx
  int v5; // eax
  bool v6; // zf
  mprimitive_t *v7; // eax
  int flags_high; // eax

  *pIndexCount = 0;
  *pVertexCount = 0;
  if ( (surfaceHandle->flags & 0x8000) != 0 )
  {
    if ( (surfaceHandle->flags & 0x800) != 0 )
      firstPrimID = 0;
    else
      firstPrimID = host_state.worldbrush->surfaces1[surfaceHandle - host_state.worldbrush->surfaces2].prims.firstPrimID;
    primitives = host_state.worldbrush->primitives;
    v5 = firstPrimID;
    v6 = primitives[v5].vertCount == 0;
    v7 = &primitives[v5];
    if ( v6 )
    {
      *pVertexCount = HIBYTE(surfaceHandle->flags);
      *pIndexCount = v7->indexCount;
    }
  }
  else
  {
    flags_high = HIBYTE(surfaceHandle->flags);
    *pVertexCount = flags_high;
    *pIndexCount = 3 * flags_high - 6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D0130
// Name: public: void CVisibleFogVolumeQuery::FindVisibleFogVolume(class Vector const __near &,struct VisOverrideData_t const __near *,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVisibleFogVolumeQuery::FindVisibleFogVolume(
        CVisibleFogVolumeQuery *this,
        const Vector *vecViewPoint,
        const VisOverrideData_t *pVisOverrideData,
        int *pVisibleFogVolume,
        int *pVisibleFogVolumeLeaf)
{
  double z; // st7

  R_SetupAreaBits(iForceViewLeaf: -1, pVisData: pVisOverrideData, pWaterReflectionHeight: nullptr);
  this->m_vecSearchPoint.x = vecViewPoint->x;
  this->m_vecSearchPoint.y = vecViewPoint->y;
  z = vecViewPoint->z;
  this->m_nVisibleFogVolume = -1;
  this->m_vecSearchPoint.z = z;
  this->m_nVisibleFogVolumeLeaf = -1;
  CVisibleFogVolumeQuery::RecursiveGetVisibleFogVolume(this, node: host_state.worldbrush->nodes);
  *pVisibleFogVolume = this->m_nVisibleFogVolume;
  *pVisibleFogVolumeLeaf = this->m_nVisibleFogVolumeLeaf;
}

//------------------------------------------------------------------------------
// Address: 0x100D0190
// Name: void R_GetVisibleFogVolume(class Vector const __near &,struct VisOverrideData_t const __near *,struct VisibleFogVolumeInfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_GetVisibleFogVolume(
        const Vector *vEyePoint,
        const VisOverrideData_t *pVisOverrideData,
        VisibleFogVolumeInfo_t *pInfo)
{
  int v3; // ebx
  mleaf_t *v4; // eax
  VisibleFogVolumeInfo_t *v5; // esi
  int v6; // eax
  float surfaceZ; // xmm0_4
  int m_nVisibleFogVolume; // eax
  IMaterial *material; // ecx
  unsigned __int16 *m_LeafMinDistToWater; // eax
  float v11; // xmm0_4
  int leafWaterDataID; // [esp-14h] [ebp-28h]
  CVisibleFogVolumeQuery query; // [esp+0h] [ebp-14h] BYREF

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: &args.m_pArgSBuffer[380],
    a3: 0,
    a4: &args.m_pArgSBuffer[404],
    a5: false,
    a6: 4);
  if ( *(_DWORD *)(host_state.worldmodel->sprite.numframes + 24) == 0 )
  {
    pInfo->m_bEyeInFogVolume = false;
    pInfo->m_nVisibleFogVolume = -1;
    pInfo->m_nVisibleFogVolumeLeaf = -1;
    *(_QWORD *)&pInfo->m_flWaterHeight = 1232348160;
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return;
  }
  v3 = CM_PointLeafnum(p: vEyePoint);
  v4 = &host_state.worldbrush->leafs[v3];
  if ( v4->leafWaterDataID == -1 )
  {
    if ( (v4->contents & 0x100) != 0 )
    {
      if ( fast_fogvolume.m_pParent != nullptr
        && fast_fogvolume.m_pParent->m_Value.m_nValue != 0
        && host_state.worldbrush->numleafwaterdata == 1 )
      {
        v5 = pInfo;
        pInfo->m_nVisibleFogVolume = 0;
        pInfo->m_nVisibleFogVolumeLeaf = host_state.worldbrush->leafwaterdata->firstLeafIndex;
      }
      else
      {
        v5 = pInfo;
        CVisibleFogVolumeQuery::FindVisibleFogVolume(
          this: &query,
          vecViewPoint: vEyePoint,
          pVisOverrideData,
          pVisibleFogVolume: &pInfo->m_nVisibleFogVolume,
          pVisibleFogVolumeLeaf: &pInfo->m_nVisibleFogVolumeLeaf);
      }
      m_nVisibleFogVolume = v5->m_nVisibleFogVolume;
      v5->m_bEyeInFogVolume = false;
      if ( m_nVisibleFogVolume < 0 || m_nVisibleFogVolume > host_state.worldbrush->numleafwaterdata )
        material = nullptr;
      else
        material = host_state.worldbrush->texinfo[host_state.worldbrush->leafwaterdata[m_nVisibleFogVolume].surfaceTexInfoID].material;
      v5->m_pFogVolumeMaterial = material;
      if ( m_nVisibleFogVolume >= 0 && m_nVisibleFogVolume <= host_state.worldbrush->numleafwaterdata )
      {
        surfaceZ = host_state.worldbrush->leafwaterdata[m_nVisibleFogVolume].surfaceZ;
        goto LABEL_22;
      }
    }
    else
    {
      v5 = pInfo;
      pInfo->m_bEyeInFogVolume = false;
      pInfo->m_nVisibleFogVolume = -1;
      pInfo->m_nVisibleFogVolumeLeaf = -1;
      pInfo->m_pFogVolumeMaterial = nullptr;
    }
LABEL_21:
    surfaceZ = 1000000.0;
    goto LABEL_22;
  }
  v5 = pInfo;
  pInfo->m_bEyeInFogVolume = true;
  leafWaterDataID = v4->leafWaterDataID;
  pInfo->m_nVisibleFogVolume = leafWaterDataID;
  pInfo->m_nVisibleFogVolumeLeaf = v3;
  pInfo->m_pFogVolumeMaterial = R_GetFogVolumeMaterial(nFogVolume: leafWaterDataID, bEyeInFogVolume: true);
  v6 = pInfo->m_nVisibleFogVolume;
  if ( pInfo->m_nVisibleFogVolume < 0 || v6 > host_state.worldbrush->numleafwaterdata )
    goto LABEL_21;
  surfaceZ = host_state.worldbrush->leafwaterdata[v6].surfaceZ;
LABEL_22:
  v5->m_flWaterHeight = surfaceZ;
  m_LeafMinDistToWater = host_state.worldbrush->m_LeafMinDistToWater;
  if ( m_LeafMinDistToWater != nullptr )
    v11 = (float)m_LeafMinDistToWater[v3];
  else
    v11 = 0.0;
  v5->m_flDistanceToWater = v11;
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x100D0360
// Name: public: virtual int CBrushSurface::GetVertexCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBrushSurface::GetVertexCount(CBrushSurface *this)
{
  msurface2_t *m_SurfaceID; // eax

  m_SurfaceID = this->m_SurfaceID;
  if ( (m_SurfaceID->flags & 0x8000) != 0 )
    return 0;
  else
    return HIBYTE(m_SurfaceID->flags);
}

//------------------------------------------------------------------------------
// Address: 0x100D0380
// Name: public: virtual void CBrushSurface::GetVertexData(struct BrushVertex_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBrushSurface::GetVertexData(CBrushSurface *this, BrushVertex_t *pVerts)
{
  msurface2_t *m_SurfaceID; // eax

  m_SurfaceID = this->m_SurfaceID;
  if ( (m_SurfaceID->flags & 0x8000) == 0 )
    BuildBrushModelVertexArray(pBrushData: host_state.worldbrush, surfID: (int)m_SurfaceID, pVerts);
}

//------------------------------------------------------------------------------
// Address: 0x100D03B0
// Name: public: virtual class IMaterial __near * CBrushSurface::GetMaterial(void)
// Source: json
//------------------------------------------------------------------------------
IMaterial *__thiscall CBrushSurface::GetMaterial(CBrushSurface *this)
{
  return host_state.worldbrush->texinfo[*((unsigned __int16 *)this->m_SurfaceID + 11) >> 1].material;
}

//------------------------------------------------------------------------------
// Address: 0x100D03D0
// Name: ListLeafsInBox
// Source: json
//------------------------------------------------------------------------------
int __cdecl ListLeafsInBox(const Vector *center, const Vector *extents, unsigned __int16 *pList, int listMax)
{
  mnode_t *node; // ecx
  int result; // eax
  int v6; // edi
  int v7; // esi
  cplane_t *plane; // edx
  float x; // xmm2_4
  float y; // xmm0_4
  float z; // xmm3_4
  float v12; // xmm0_4
  double v13; // st7
  mnode_t *v14; // edx
  _DWORD v15[1025]; // [esp+0h] [ebp-1010h]
  float v16; // [esp+1004h] [ebp-Ch]
  float v17; // [esp+1008h] [ebp-8h]
  float v18; // [esp+100Ch] [ebp-4h]

  result = 0;
  v6 = 0;
  v7 = 0;
  while ( 1 )
  {
    while ( node->contents < 0 )
    {
      plane = node->plane;
      x = plane->normal.x;
      y = center->y;
      z = plane->normal.z;
      v17 = plane->normal.y;
      v12 = (float)((float)((float)(y * v17) + (float)(center->x * x)) + (float)(center->z * z)) - plane->dist;
      v13 = extents->y;
      *(float *)&v15[1024] = x;
      v18 = z;
      v16 = fabs(v13 * v17) + fabs(extents->x * x) + fabs(extents->z * z);
      if ( v12 < v16 )
      {
        if ( (float)-v16 <= v12 )
        {
          v14 = node->children[0];
          node = node->children[1];
          v15[v7] = v14;
          v7 = ((_WORD)v7 + 1) & 0x3FF;
        }
        else
        {
          node = node->children[1];
        }
      }
      else
      {
        node = node->children[0];
      }
    }
    if ( node->contents != 1 && result < listMax )
      pList[result++] = ((char *)node - (char *)host_state.worldbrush->leafs) >> 6;
    if ( v6 == v7 )
      break;
    node = (mnode_t *)v15[v6];
    v6 = ((_WORD)v6 + 1) & 0x3FF;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D04E0
// Name: EnumerateLeavesAlongExtrudedRay_R
// Source: json
//------------------------------------------------------------------------------
bool __cdecl EnumerateLeavesAlongExtrudedRay_R(
        mnode_t *node,
        const Ray_t *ray,
        float start,
        float end,
        ISpatialLeafEnumerator *pEnum,
        int context)
{
  mnode_t *v6; // esi
  int contents; // eax
  long double v8; // st7
  double v9; // st6
  double v10; // st5
  float v11; // xmm5_4
  cplane_t *plane; // eax
  int type; // ecx
  float v14; // xmm3_4
  float v15; // xmm2_4
  float v16; // xmm0_4
  long double v17; // st4
  double x; // st4
  float v19; // xmm2_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm0_4
  double v23; // st7
  float v24; // xmm3_4
  double v25; // st3
  long double v26; // st2
  int v27; // ebx
  long double v28; // st7
  long double v29; // st6
  long double v30; // st6
  double v31; // st7
  float v32; // xmm1_4
  float v34; // [esp+0h] [ebp-38h]
  float v35; // [esp+0h] [ebp-38h]
  int minVal; // [esp+20h] [ebp-18h] BYREF
  float t2; // [esp+24h] [ebp-14h]
  float t1; // [esp+28h] [ebp-10h]
  float v39; // [esp+2Ch] [ebp-Ch]
  float frac; // [esp+30h] [ebp-8h] BYREF
  float frac2; // [esp+34h] [ebp-4h] BYREF
  float offset; // [esp+40h] [ebp+8h]

  v6 = node;
  contents = node->contents;
  if ( node->contents == 1 )
    return true;
  v8 = 0.03125;
  v9 = 1.0;
  v10 = start;
  v11 = start;
  while ( 1 )
  {
    if ( contents >= 0 )
      return pEnum->EnumerateLeaf(
               this: pEnum,
               a2: ((char *)v6 - (char *)host_state.worldbrush->leafs) >> 6,
               a3: context);
    plane = v6->plane;
    if ( plane->type > 2u )
    {
      x = ray->m_Extents.x;
      v19 = ray->m_Start.y * plane->normal.y;
      v20 = ray->m_Start.x;
      v39 = plane->normal.x;
      v15 = (float)(v19 + (float)(v20 * v39)) + (float)(ray->m_Start.z * plane->normal.z);
      v16 = (float)((float)(ray->m_Delta.y * plane->normal.y) + (float)(v39 * ray->m_Delta.x))
          + (float)(ray->m_Delta.z * plane->normal.z);
      v17 = fabs(x * v39) + fabs(ray->m_Extents.y * plane->normal.y) + fabs(ray->m_Extents.z * plane->normal.z) + v8;
      offset = v17;
      v14 = offset;
    }
    else
    {
      type = plane->type;
      v14 = *(&ray->m_Extents.x + type) + 0.03125;
      v15 = *(&ray->m_Start.x + type);
      v16 = *(&ray->m_Delta.x + type);
      v17 = v14;
    }
    v21 = (float)((float)(v16 * v11) + v15) - plane->dist;
    v22 = (float)((float)(v16 * end) + v15) - plane->dist;
    t1 = v21;
    t2 = v22;
    if ( v21 > v14 && v22 > v14 )
    {
      v6 = v6->children[0];
      v23 = v10;
      goto LABEL_29;
    }
    LODWORD(v24) = LODWORD(v14) ^ _mask__NegFloat_;
    if ( v24 > v21 && v24 > v22 )
    {
      v6 = v6->children[1];
      v23 = v10;
      goto LABEL_29;
    }
    v25 = t1;
    v26 = t1 - t2;
    if ( v8 > fabs(v26) )
    {
      v34 = v10;
      if ( !EnumerateLeavesAlongExtrudedRay_R(node: v6->children[0], ray, start: v34, end, pEnum, context) )
        return false;
      v6 = v6->children[1];
      v23 = start;
      goto LABEL_28;
    }
    if ( v22 <= v21 )
    {
      v27 = 0;
      if ( v21 <= v22 )
      {
        v32 = 1.0;
        frac2 = 0.0;
        v31 = v10;
        goto LABEL_26;
      }
      v28 = v9 / v26;
      frac2 = (v25 - v17) * (v9 / v26);
      v29 = t1 + v17;
    }
    else
    {
      v27 = 1;
      v28 = v9 / v26;
      frac2 = (v25 + v17) * (v9 / v26);
      v29 = t1 - v17;
    }
    v30 = v28 * v29;
    v31 = v10;
    frac = v30;
    v32 = frac;
    if ( frac >= 0.0 )
    {
      if ( frac > 1.0 )
        v32 = 1.0;
    }
    else
    {
      v32 = 0.0;
    }
LABEL_26:
    v35 = v31;
    if ( !EnumerateLeavesAlongExtrudedRay_R(
            node: v6->children[v27],
            ray,
            start: v35,
            end: (float)((float)(end - v11) * v32) + v11,
            pEnum,
            context) )
      return false;
    LODWORD(frac) = 1;
    minVal = 0;
    v23 = clamp<float,int,int>(val: &frac2, &minVal, maxVal: (const int *)&frac) * (float)(end - v11) + start;
    start = v23;
    v6 = v6->children[v27 == 0];
LABEL_28:
    v11 = start;
LABEL_29:
    contents = v6->contents;
    if ( v6->contents == 1 )
      return true;
    v9 = 1.0;
    v10 = v23;
    v8 = 0.03125;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D0850
// Name: public: virtual bool CEngineBSPTree::EnumerateLeavesAlongRay(struct Ray_t const __near &,class ISpatialLeafEnumerator __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineBSPTree::EnumerateLeavesAlongRay(
        CEngineBSPTree *this,
        const Ray_t *ray,
        ISpatialLeafEnumerator *pEnum,
        int context)
{
  float y; // xmm2_4
  float z; // xmm6_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm6_4
  float v12; // xmm2_4
  bool (__thiscall *EnumerateLeavesInBox)(struct CEngineBSPTree *, const Vector *, const Vector *, ISpatialLeafEnumerator *, int); // eax
  Vector mins; // [esp+10h] [ebp-18h] BYREF
  Vector maxs; // [esp+1Ch] [ebp-Ch] BYREF

  if ( ray->m_IsSwept )
  {
    if ( ray->m_IsRay )
      return EnumerateLeavesAlongRay_R(node: host_state.worldbrush->nodes, ray, start: 0.0, end: 1.0, pEnum, context);
    else
      return EnumerateLeavesAlongExtrudedRay_R(
               node: host_state.worldbrush->nodes,
               ray,
               start: 0.0,
               end: 1.0,
               pEnum,
               context);
  }
  else
  {
    y = ray->m_Extents.y;
    z = ray->m_Extents.z;
    v6 = ray->m_Start.x - ray->m_Extents.x;
    maxs.x = ray->m_Extents.x + ray->m_Start.x;
    v7 = ray->m_Start.y;
    v8 = y + v7;
    v9 = v7 - ray->m_Extents.y;
    maxs.y = v8;
    v10 = ray->m_Start.z;
    v11 = z + v10;
    v12 = v10 - ray->m_Extents.z;
    EnumerateLeavesInBox = this->EnumerateLeavesInBox;
    maxs.z = v11;
    mins.x = v6;
    mins.y = v9;
    mins.z = v12;
    return EnumerateLeavesInBox(this, a2: &mins, a3: &maxs, a4: pEnum, a5: context);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D0940
// Name: bool EnumerateLeafInSphere_R<0>(struct mnode_t __near *,struct EnumLeafSphereInfo_t __near &,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl EnumerateLeafInSphere_R<0>(mnode_t *node, EnumLeafSphereInfo_t *info, int nTestFlags)
{
  mnode_t *v3; // esi
  int contents; // eax
  float x; // xmm0_4
  float y; // xmm0_4
  float z; // xmm0_4
  cplane_t *plane; // eax
  unsigned __int8 type; // cl
  float v11; // xmm0_4
  float dist; // xmm2_4
  float flDelta; // [esp+18h] [ebp+8h]
  float flDeltaa; // [esp+18h] [ebp+8h]
  float flDeltab; // [esp+18h] [ebp+8h]

  v3 = node;
  contents = node->contents;
  if ( node->contents != 1 )
  {
    while ( 1 )
    {
      if ( contents >= 0 )
      {
        if ( nTestFlags == 0
          || IsBoxIntersectingSphereExtents(
               boxCenter: &v3->m_vecCenter,
               boxHalfDiag: &v3->m_vecHalfDiagonal,
               center: &info->m_vecCenter,
               radius: info->m_flRadius) )
        {
          return info->m_pIterator->EnumerateLeaf(
                   this: info->m_pIterator,
                   a2: ((char *)v3 - (char *)host_state.worldbrush->leafs) >> 6,
                   a3: info->m_nContext);
        }
        return true;
      }
      if ( nTestFlags != 0 )
      {
        if ( contents == -1 )
        {
          if ( (nTestFlags & 0x10000000) != 0 )
          {
            x = v3->m_vecHalfDiagonal.x;
            flDelta = fabs(v3->m_vecCenter.x - info->m_vecBoxCenter.x);
            if ( flDelta > (float)(info->m_vecBoxHalfDiagonal.x + x) )
              return true;
            if ( info->m_vecBoxHalfDiagonal.x > (float)(x + flDelta) )
              nTestFlags &= ~0x10000000u;
          }
          if ( (nTestFlags & 0x20000000) != 0 )
          {
            y = v3->m_vecHalfDiagonal.y;
            flDeltaa = fabs(v3->m_vecCenter.y - info->m_vecBoxCenter.y);
            if ( flDeltaa > (float)(info->m_vecBoxHalfDiagonal.y + y) )
              return true;
            if ( info->m_vecBoxHalfDiagonal.y > (float)(y + flDeltaa) )
              nTestFlags &= ~0x20000000u;
          }
          if ( (nTestFlags & 0x40000000) != 0 )
          {
            z = v3->m_vecHalfDiagonal.z;
            flDeltab = fabs(v3->m_vecCenter.z - info->m_vecBoxCenter.z);
            if ( flDeltab > (float)(info->m_vecBoxHalfDiagonal.z + z) )
              return true;
            if ( info->m_vecBoxHalfDiagonal.z > (float)(z + flDeltab) )
              nTestFlags &= ~0x40000000u;
          }
        }
        else if ( contents == -2 )
        {
          nTestFlags &= 0x8FFFFFFF;
        }
      }
      plane = v3->plane;
      type = plane->type;
      if ( type > 2u )
        v11 = (float)((float)(plane->normal.y * info->m_vecCenter.y) + (float)(plane->normal.x * info->m_vecCenter.x))
            + (float)(plane->normal.z * info->m_vecCenter.z);
      else
        v11 = *(&info->m_vecCenter.x + type);
      dist = plane->dist;
      if ( dist >= (float)(info->m_flRadius + v11) )
        goto LABEL_26;
      if ( (float)(v11 - info->m_flRadius) < dist )
        break;
      v3 = v3->children[0];
LABEL_27:
      contents = v3->contents;
      if ( v3->contents == 1 )
        return true;
    }
    if ( !EnumerateLeafInSphere_R<0>(node: v3->children[0], info, nTestFlags) )
      return false;
LABEL_26:
    v3 = v3->children[1];
    goto LABEL_27;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x100D0B20
// Name: bool EnumerateLeafInSphere_R<1>(struct mnode_t __near *,struct EnumLeafSphereInfo_t __near &,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl EnumerateLeafInSphere_R<1>(mnode_t *node, EnumLeafSphereInfo_t *info, int nTestFlags)
{
  mnode_t *v3; // esi
  int contents; // eax
  float x; // xmm0_4
  float y; // xmm0_4
  float z; // xmm0_4
  cplane_t *plane; // eax
  unsigned __int8 type; // cl
  float v11; // xmm0_4
  float dist; // xmm2_4
  float flDelta; // [esp+18h] [ebp+8h]
  float flDeltaa; // [esp+18h] [ebp+8h]
  float flDeltab; // [esp+18h] [ebp+8h]

  v3 = node;
  contents = node->contents;
  if ( node->contents != 1 )
  {
    while ( 1 )
    {
      if ( contents >= 0 )
      {
        if ( nTestFlags == 0
          || IsBoxIntersectingSphereExtents(
               boxCenter: &v3->m_vecCenter,
               boxHalfDiag: &v3->m_vecHalfDiagonal,
               center: &info->m_vecCenter,
               radius: info->m_flRadius) )
        {
          return info->m_pIterator->EnumerateLeaf(
                   this: info->m_pIterator,
                   a2: ((char *)v3 - (char *)host_state.worldbrush->leafs) >> 6,
                   a3: info->m_nContext);
        }
        return true;
      }
      if ( nTestFlags != 0 )
      {
        if ( contents == -1 )
        {
          if ( (v3->flags & nTestFlags) == 0 )
            return true;
          if ( (nTestFlags & 0x10000000) != 0 )
          {
            x = v3->m_vecHalfDiagonal.x;
            flDelta = fabs(v3->m_vecCenter.x - info->m_vecBoxCenter.x);
            if ( flDelta > (float)(info->m_vecBoxHalfDiagonal.x + x) )
              return true;
            if ( info->m_vecBoxHalfDiagonal.x > (float)(x + flDelta) )
              nTestFlags &= ~0x10000000u;
          }
          if ( (nTestFlags & 0x20000000) != 0 )
          {
            y = v3->m_vecHalfDiagonal.y;
            flDeltaa = fabs(v3->m_vecCenter.y - info->m_vecBoxCenter.y);
            if ( flDeltaa > (float)(info->m_vecBoxHalfDiagonal.y + y) )
              return true;
            if ( info->m_vecBoxHalfDiagonal.y > (float)(y + flDeltaa) )
              nTestFlags &= ~0x20000000u;
          }
          if ( (nTestFlags & 0x40000000) != 0 )
          {
            z = v3->m_vecHalfDiagonal.z;
            flDeltab = fabs(v3->m_vecCenter.z - info->m_vecBoxCenter.z);
            if ( flDeltab > (float)(info->m_vecBoxHalfDiagonal.z + z) )
              return true;
            if ( info->m_vecBoxHalfDiagonal.z > (float)(z + flDeltab) )
              nTestFlags &= ~0x40000000u;
          }
        }
        else if ( contents == -2 )
        {
          nTestFlags &= 0x8FFFFFFF;
        }
      }
      plane = v3->plane;
      type = plane->type;
      if ( type > 2u )
        v11 = (float)((float)(plane->normal.y * info->m_vecCenter.y) + (float)(plane->normal.x * info->m_vecCenter.x))
            + (float)(plane->normal.z * info->m_vecCenter.z);
      else
        v11 = *(&info->m_vecCenter.x + type);
      dist = plane->dist;
      if ( dist >= (float)(info->m_flRadius + v11) )
        goto LABEL_27;
      if ( (float)(v11 - info->m_flRadius) < dist )
        break;
      v3 = v3->children[0];
LABEL_28:
      contents = v3->contents;
      if ( v3->contents == 1 )
        return true;
    }
    if ( !EnumerateLeafInSphere_R<1>(node: v3->children[0], info, nTestFlags) )
      return false;
LABEL_27:
    v3 = v3->children[1];
    goto LABEL_28;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x100D0D00
// Name: private: void CVarBitVecBase<unsigned short>::ReallocInts(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVarBitVecBase<unsigned short>::ReallocInts(CVarBitVecBase<unsigned short> *this, int numInts)
{
  CVarBitVecBase<unsigned short> *m_pInt; // eax
  unsigned int *p_m_iBitStringStorage; // edi
  unsigned int *v5; // eax
  unsigned int v6; // ecx

  if ( numInts != 0 )
  {
    m_pInt = (CVarBitVecBase<unsigned short> *)this->m_pInt;
    p_m_iBitStringStorage = &this->m_iBitStringStorage;
    if ( m_pInt == (CVarBitVecBase<unsigned short> *)&this->m_iBitStringStorage )
    {
      if ( numInts != 1 )
      {
        v5 = (unsigned int *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * numInts);
        v6 = *p_m_iBitStringStorage;
        this->m_pInt = v5;
        *v5 = v6;
      }
    }
    else if ( numInts == 1 )
    {
      *p_m_iBitStringStorage = *(_DWORD *)&m_pInt->m_numBits;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pInt);
      this->m_pInt = p_m_iBitStringStorage;
    }
    else
    {
      this->m_pInt = (unsigned int *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pInt, a3: 4 * numInts);
    }
  }
  else
  {
    if ( this->m_numInts > 1u )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pInt);
    this->m_pInt = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D0DB0
// Name: void BuildIndicesForWorldSurface(class CIndexBuilder __near &,struct msurface2_t __near *,struct worldbrushdata_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildIndicesForWorldSurface(CIndexBuilder *meshBuilder, msurface2_t *surfID, worldbrushdata_t *pData)
{
  unsigned __int16 firstPrimID; // cx
  mprimitive_t *v4; // ecx

  if ( (surfID->flags & 0x8000) != 0 )
  {
    if ( (surfID->flags & 0x800) != 0 )
      firstPrimID = 0;
    else
      firstPrimID = pData->surfaces1[surfID - pData->surfaces2].prims.firstPrimID;
    v4 = &pData->primitives[firstPrimID];
    CIndexBuilder::FastIndexList(
      this: meshBuilder,
      pIndexList: (char *)&pData->primindices[v4->firstIndex],
      startVert: surfID->vertBufferIndex,
      indexCount: v4->indexCount);
  }
  else
  {
    BuildIndicesForSurface(meshBuilder, surfID);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D0E30
// Name: public: void CWorldRenderList::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorldRenderList::Reset(CWorldRenderList *this)
{
  int *p_m_Size; // eax
  int i; // ecx
  unsigned __int8 *m_pInt; // eax

  CMSurfaceSortList::Reset(this: &this->m_SortList);
  this->m_AlphaSurfaces.m_Size = 0;
  CMSurfaceSortList::Reset(this: &this->m_DispSortList);
  *(_WORD *)&this->m_bSkyVisible = 0;
  p_m_Size = &this->m_DlightSurfaces[0].m_Size;
  for ( i = 4; i != 0; --i )
  {
    *(p_m_Size - 20) = 0;
    *p_m_Size = 0;
    p_m_Size[20] = 0;
    p_m_Size += 5;
  }
  this->m_leaves.m_Size = 0;
  m_pInt = (unsigned __int8 *)this->m_VisitedSurfs.m_bits.m_pInt;
  if ( m_pInt != nullptr )
    memset(dst: m_pInt, value: 0, count: 4 * this->m_VisitedSurfs.m_bits.m_numInts);
}

//------------------------------------------------------------------------------
// Address: 0x100D0EA0
// Name: public: void CWorldRenderList::CountTranslucentSurfaces(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorldRenderList::CountTranslucentSurfaces(CWorldRenderList *this)
{
  int m_Size; // edi
  int firstTranslucentSurface; // esi
  int i; // eax
  int v4; // edx
  int v5; // eax

  m_Size = this->m_leaves.m_Size;
  if ( m_Size > 0 )
  {
    firstTranslucentSurface = this->m_leaves.m_Memory.m_pMemory->firstTranslucentSurface;
    for ( i = 1; i < m_Size; ++i )
    {
      v4 = this->m_leaves.m_Memory.m_pMemory[i].firstTranslucentSurface - firstTranslucentSurface;
      if ( v4 != 0 )
      {
        this->m_leaves.m_Memory.m_pMemory[i - 1].translucentSurfaceCount = v4;
        firstTranslucentSurface = this->m_leaves.m_Memory.m_pMemory[i].firstTranslucentSurface;
      }
    }
    v5 = this->m_AlphaSurfaces.m_Size;
    if ( this->m_leaves.m_Memory.m_pMemory[m_Size - 1].firstTranslucentSurface != v5 )
      this->m_leaves.m_Memory.m_pMemory[m_Size - 1].translucentSurfaceCount = v5
                                                                            - this->m_leaves.m_Memory.m_pMemory[m_Size - 1].firstTranslucentSurface;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D1490
// Name: void Shader_DrawSurfaceListStatic(class IMatRenderContext __near *,struct msurface2_t __near * __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Shader_DrawSurfaceListStatic(
        IMatRenderContext *pRenderContext,
        msurface2_t **pList,
        int listCount,
        int triangleCount)
{
  IMesh *v4; // ebx
  int j; // esi
  int m_nVertexCount; // eax
  int i; // esi
  CMeshBuilder meshBuilder; // [esp+Ch] [ebp-1E8h] BYREF

  if ( mat_forcedynamic.m_pParent != nullptr && mat_forcedynamic.m_pParent->m_Value.m_nValue != 0
    || ((*pList)->flags & 0x10000) != 0 )
  {
    for ( i = 0; i < listCount; ++i )
      Shader_DrawSurfaceDynamic(pRenderContext, surfID: pList[i]);
  }
  else if ( triangleCount != 0 )
  {
    v4 = pRenderContext->GetDynamicMesh(
           this: pRenderContext,
           a2: 1,
           a3: g_WorldStaticMeshes.m_Memory.m_pMemory[(*pList)->materialSortID],
           a4: 0,
           a5: 0);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    CMeshBuilder::Begin(
      this: &meshBuilder,
      pMesh: v4,
      type: MATERIAL_TRIANGLES,
      nVertexCount: 0,
      nIndexCount: 3 * triangleCount,
      pMeshSettings: nullptr);
    for ( j = 0; j < listCount; ++j )
      BuildIndicesForWorldSurface(
        meshBuilder: &meshBuilder.m_IndexBuilder,
        surfID: pList[j],
        pData: host_state.worldbrush);
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
    v4->Draw_2(this: v4, a2: -1, a3: 0);
    CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D1650
// Name: void BuildMSurfaceVertexArraysTextureOnly(struct worldbrushdata_t __near *,struct msurface2_t __near *,class CMeshBuilder __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildMSurfaceVertexArraysTextureOnly(
        worldbrushdata_t *pBrushData,
        msurface2_t *surfID,
        CMeshBuilder *builder)
{
  unsigned __int16 *v4; // ecx
  int v5; // edi
  float *m_pCurrPosition; // ecx
  mvertex_t *v7; // eax
  int v8; // eax
  Vector2D uv; // [esp+8h] [ebp-Ch] BYREF
  int vertCount; // [esp+10h] [ebp-4h]
  unsigned __int16 *pVertIndex; // [esp+20h] [ebp+Ch]

  v4 = &pBrushData->vertindices[surfID->firstvertindex];
  v5 = 0;
  vertCount = HIBYTE(surfID->flags);
  pVertIndex = v4;
  if ( vertCount != 0 )
  {
    do
    {
      m_pCurrPosition = builder->m_VertexBuilder.m_pCurrPosition;
      v7 = &pBrushData->vertexes[pVertIndex[v5]];
      *m_pCurrPosition = v7->position.x;
      m_pCurrPosition[1] = v7->position.y;
      m_pCurrPosition[2] = v7->position.z;
      SurfComputeTextureCoordinate(surfID, vec: &v7->position, pUV: &uv.x);
      *(Vector2D *)builder->m_VertexBuilder.m_pCurrTexCoord[0] = uv;
      *(_DWORD *)builder->m_VertexBuilder.m_pCurrColor = flatColor[2]
                                                       | ((flatColor[1] | ((flatColor[0] | (flatColor[3] << 8)) << 8)) << 8);
      v8 = ++builder->m_VertexBuilder.m_nCurrentVertex;
      if ( v8 > builder->m_VertexBuilder.m_nVertexCount )
        builder->m_VertexBuilder.m_nVertexCount = v8;
      builder->m_VertexBuilder.m_pCurrPosition = (float *)((char *)builder->m_VertexBuilder.m_pCurrPosition
                                                         + builder->m_VertexBuilder.m_VertexSize_Position);
      builder->m_VertexBuilder.m_pCurrColor += builder->m_VertexBuilder.m_VertexSize_Color;
      builder->m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)builder->m_VertexBuilder.m_pCurrTexCoord[0]
                                                            + builder->m_VertexBuilder.m_VertexSize_TexCoord[0]);
      ++v5;
    }
    while ( v5 < vertCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D1760
// Name: void Shader_AddSurfaceDynamicTextureOnly(class CMeshBuilder __near &,struct msurface2_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Shader_AddSurfaceDynamicTextureOnly(CMeshBuilder *meshBuilder, msurface2_t *surfID)
{
  worldbrushdata_t *worldbrush; // edi
  CIndexBuilder *p_m_IndexBuilder; // ecx
  unsigned __int16 firstPrimID; // ax
  int v6; // eax
  int startVert; // [esp+14h] [ebp+8h]

  worldbrush = host_state.worldbrush;
  startVert = meshBuilder->m_VertexBuilder.m_nVertexCount;
  BuildMSurfaceVertexArraysTextureOnly(pBrushData: host_state.worldbrush, surfID, builder: meshBuilder);
  p_m_IndexBuilder = &meshBuilder->m_IndexBuilder;
  if ( (surfID->flags & 0x8000) != 0 )
  {
    if ( (surfID->flags & 0x800) != 0 )
      firstPrimID = 0;
    else
      firstPrimID = worldbrush->surfaces1[surfID - worldbrush->surfaces2].prims.firstPrimID;
    v6 = (int)&worldbrush->primitives[firstPrimID];
    CIndexBuilder::FastIndexList(
      this: p_m_IndexBuilder,
      pIndexList: (char *)&worldbrush->primindices[*(unsigned __int16 *)(v6 + 4)],
      startVert,
      indexCount: *(unsigned __int16 *)(v6 + 6));
  }
  else
  {
    CIndexBuilder::FastPolygon(this: p_m_IndexBuilder, startVert, triangleCount: HIBYTE(surfID->flags) - 2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D1800
// Name: void Shader_DrawWireframePolygons(class IMatRenderContext __near *,struct msurface2_t __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Shader_DrawWireframePolygons(IMatRenderContext *pRenderContext, msurface2_t **pList, int listCount)
{
  IIndexBuffer *j; // ebx
  int v4; // edi
  int v5; // eax
  unsigned int flags_high; // ecx
  IMesh *v7; // esi
  void (__thiscall *SetPrimitiveType)(IMesh *, MaterialPrimitiveType_t); // edx
  int v9; // edi
  worldbrushdata_t *worldbrush; // ecx
  int v11; // eax
  msurface2_t *v12; // eax
  unsigned int v13; // edx
  int firstvertindex; // esi
  int v15; // eax
  float v16; // edi
  float v17; // eax
  float z; // xmm2_4
  float y; // xmm1_4
  float x; // xmm0_4
  int v21; // edi
  float *p_x; // esi
  float *m_pCurrPosition; // eax
  float *v24; // eax
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-1FCh] BYREF
  Vector vecPrevPos; // [esp+1F0h] [ebp-14h]
  IMesh *pMesh; // [esp+1FCh] [ebp-8h]
  int i; // [esp+200h] [ebp-4h]

  j = nullptr;
  v4 = 0;
  v5 = 0;
  if ( listCount > 0 )
  {
    do
    {
      flags_high = HIBYTE(pList[v5]->flags);
      if ( flags_high >= 3 )
        v4 += flags_high;
      ++v5;
    }
    while ( v5 < listCount );
    if ( v4 != 0 )
    {
      pRenderContext->Bind(this: pRenderContext, a2: g_materialWorldWireframe, a3: nullptr);
      v7 = pRenderContext->GetDynamicMesh(this: pRenderContext, a2: 0, a3: 0, a4: 0, a5: 0);
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
      meshBuilder.m_pMesh = v7;
      meshBuilder.m_bGenerateIndices = true;
      meshBuilder.m_Type = MATERIAL_LINES;
      SetPrimitiveType = v7->SetPrimitiveType;
      v9 = 2 * v4;
      pMesh = v7;
      i = v9;
      SetPrimitiveType(this: v7, a2: MATERIAL_LINES);
      meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: v9, a3: v9, a4: &meshBuilder, a5: nullptr);
      meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v7->IIndexBuffer;
      meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
      meshBuilder.m_IndexBuilder.m_nMaxIndexCount = v9;
      meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
      meshBuilder.m_VertexBuilder.m_pVertexBuffer = v7;
      meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
      meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
      meshBuilder.m_IndexBuilder.m_bModify = false;
      meshBuilder.m_VertexBuilder.VertexDesc_t = meshBuilder.VertexDesc_t;
      meshBuilder.m_VertexBuilder.m_nMaxVertexCount = i;
      meshBuilder.m_VertexBuilder.m_NumBoneWeights = meshBuilder.m_NumBoneWeights != 0 ? 2 : 0;
      meshBuilder.m_VertexBuilder.m_nVertexCount = 0;
      meshBuilder.m_VertexBuilder.m_bModify = false;
      if ( meshBuilder.m_VertexBuilder.m_nBufferOffset == -1 )
      {
        meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
        meshBuilder.m_VertexBuilder.m_nBufferOffset = meshBuilder.MeshDesc_t::VertexDesc_t::m_nOffset;
        meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = meshBuilder.m_nFirstVertex;
      }
      meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
      CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
      worldbrush = host_state.worldbrush;
      v11 = 0;
      i = 0;
      do
      {
        v12 = pList[v11];
        v13 = HIBYTE(v12->flags);
        if ( v13 >= 3 )
        {
          firstvertindex = v12->firstvertindex;
          v15 = (int)&worldbrush->vertexes[worldbrush->vertindices[firstvertindex - 1 + v13]];
          vecPrevPos.x = *(float *)v15;
          v16 = *(float *)(v15 + 4);
          v17 = *(float *)(v15 + 8);
          vecPrevPos.y = v16;
          vecPrevPos.z = v17;
          z = vecPrevPos.z;
          y = vecPrevPos.y;
          x = vecPrevPos.x;
          v21 = firstvertindex;
          for ( j = (IIndexBuffer *)v13; j != nullptr; j = (IIndexBuffer *)((char *)j - 1) )
          {
            p_x = &worldbrush->vertexes[worldbrush->vertindices[v21]].position.x;
            m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
            *meshBuilder.m_VertexBuilder.m_pCurrPosition = x;
            m_pCurrPosition[1] = y;
            m_pCurrPosition[2] = z;
            CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
            v24 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
            *meshBuilder.m_VertexBuilder.m_pCurrPosition = *p_x;
            v24[1] = p_x[1];
            v24[2] = p_x[2];
            CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
            x = *p_x;
            y = p_x[1];
            z = p_x[2];
            worldbrush = host_state.worldbrush;
            ++v21;
          }
        }
        v11 = i + 1;
        i = v11;
      }
      while ( v11 < listCount );
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
      meshBuilder.m_IndexBuilder.m_pIndexBuffer = j;
      meshBuilder.m_IndexBuilder.m_nMaxIndexCount = (int)j;
      meshBuilder.m_VertexBuilder.m_nMaxVertexCount = (int)j;
      meshBuilder.m_VertexBuilder.m_pVertexBuffer = (IVertexBuffer *)j;
      meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
      meshBuilder.m_pMesh = (IMesh *)j;
      pMesh->Draw_2(this: pMesh, a2: -1, a3: (int)j);
      if ( (IIndexBuffer *)meshBuilder.m_VertexBuilder.m_pVertexBuffer != j
        && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
      {
        meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
      }
      if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != j
        && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
      {
        meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D1B90
// Name: Shader_DrawChainsWireframe
// Source: json
//------------------------------------------------------------------------------
void __usercall Shader_DrawChainsWireframe(IMatRenderContext *pRenderContext@<edi>, msurface2_t **pList, int listCount)
{
  int m_nValue; // eax
  IMaterial *v4; // ecx
  int i; // esi

  if ( (sv_cheats.m_pParent == nullptr || sv_cheats.m_pParent->m_Value.m_nValue == 0) && !Cmd_IsRptActive()
    || mat_wireframe.m_pParent == nullptr )
  {
    goto LABEL_7;
  }
  m_nValue = mat_wireframe.m_pParent->m_Value.m_nValue;
  if ( m_nValue == 3 )
  {
    Shader_DrawWireframePolygons(pRenderContext, pList, listCount);
    return;
  }
  v4 = g_materialWorldWireframeZBuffer;
  if ( m_nValue != 2 )
LABEL_7:
    v4 = g_materialWorldWireframe;
  pRenderContext->Bind(this: pRenderContext, a2: v4, a3: nullptr);
  for ( i = 0; i < listCount; ++i )
    Shader_DrawSurfaceDynamic(pRenderContext, surfID: pList[i]);
}

//------------------------------------------------------------------------------
// Address: 0x100D1C10
// Name: Shader_DrawChainNormals
// Source: json
//------------------------------------------------------------------------------
void __usercall Shader_DrawChainNormals(
        CMeshBuilder *p_meshBuilder@<edi>,
        IMatRenderContext *pRenderContext,
        msurface2_t **pList,
        int listCount)
{
  IMatRenderContext *v4; // esi
  void (__thiscall *Bind)(IMatRenderContext *, IMaterial *, void *); // edx
  int v6; // ebx
  msurface2_t *v7; // edi
  IMesh *(__thiscall *GetDynamicMesh)(IMatRenderContext *, bool, IMesh *, IMesh *, IMaterial *); // eax
  IMesh *v9; // esi
  int v10; // eax
  int v11; // edi
  void (__thiscall *SetPrimitiveType)(IMesh *, MaterialPrimitiveType_t); // eax
  bool v13; // al
  msurface2_t *v14; // edx
  bool v15; // zf
  mvertex_t *v16; // esi
  Vector *v17; // edi
  float *m_pCurrPosition; // eax
  float *v19; // eax
  float v20; // xmm1_4
  float v21; // xmm2_4
  float *v22; // eax
  float *v23; // eax
  float v24; // xmm1_4
  float v25; // xmm2_4
  float *v26; // eax
  float *v27; // eax
  float v28; // xmm1_4
  float v29; // xmm2_4
  int m_nVertexCount; // eax
  Vector tVect; // [esp+8h] [ebp-224h] BYREF
  CMeshBuilder meshBuilder; // [esp+14h] [ebp-218h] BYREF
  Vector tangentS; // [esp+1FCh] [ebp-30h] BYREF
  Vector tangentT; // [esp+208h] [ebp-24h] BYREF
  IMesh *pMesh; // [esp+214h] [ebp-18h]
  worldbrushdata_t *pBrushData; // [esp+218h] [ebp-14h]
  int v38; // [esp+21Ch] [ebp-10h]
  BOOL negate; // [esp+220h] [ebp-Ch]
  int i; // [esp+224h] [ebp-8h]
  msurface2_t *surfID; // [esp+228h] [ebp-4h]

  v4 = pRenderContext;
  Bind = pRenderContext->Bind;
  pBrushData = host_state.worldbrush;
  v6 = 0;
  Bind(this: pRenderContext, a2: g_pMaterialWireframeVertexColor, a3: nullptr);
  i = 0;
  if ( listCount > 0 )
  {
    while ( 1 )
    {
      GetDynamicMesh = v4->GetDynamicMesh;
      surfID = pList[i];
      v7 = surfID;
      v9 = (IMesh *)((int (__thiscall *)(IMatRenderContext *, int, _DWORD, _DWORD, _DWORD, CMeshBuilder *))GetDynamicMesh)(
                      a1: v4,
                      a2: 1,
                      a3: 0,
                      a4: 0,
                      a5: 0,
                      a6: p_meshBuilder);
      meshBuilder.m_IndexBuilder.m_nBufferOffset = -1;
      meshBuilder.m_VertexBuilder.m_nBufferOffset = -1;
      meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
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
      v10 = 3 * HIBYTE(v7->flags);
      meshBuilder.m_pMesh = v9;
      meshBuilder.m_bGenerateIndices = true;
      meshBuilder.m_Type = MATERIAL_LINES;
      v11 = 2 * v10;
      SetPrimitiveType = v9->SetPrimitiveType;
      pMesh = v9;
      v38 = v11;
      SetPrimitiveType(this: v9, a2: MATERIAL_LINES);
      meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: v11, a3: v11, a4: &meshBuilder, a5: nullptr);
      meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v9->IIndexBuffer;
      meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
      meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
      meshBuilder.m_IndexBuilder.m_nMaxIndexCount = v11;
      meshBuilder.m_VertexBuilder.m_pVertexBuffer = v9;
      meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
      meshBuilder.m_IndexBuilder.m_bModify = false;
      meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
      meshBuilder.m_VertexBuilder.VertexDesc_t = meshBuilder.VertexDesc_t;
      meshBuilder.m_VertexBuilder.m_nMaxVertexCount = v38;
      meshBuilder.m_VertexBuilder.m_NumBoneWeights = meshBuilder.m_NumBoneWeights != 0 ? 2 : 0;
      meshBuilder.m_VertexBuilder.m_nVertexCount = 0;
      meshBuilder.m_VertexBuilder.m_bModify = false;
      if ( meshBuilder.m_VertexBuilder.m_nBufferOffset == -1 )
      {
        meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
        meshBuilder.m_VertexBuilder.m_nBufferOffset = meshBuilder.MeshDesc_t::VertexDesc_t::m_nOffset;
        meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = meshBuilder.m_nFirstVertex;
      }
      meshBuilder.m_VertexBuilder.m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pPosition;
      qmemcpy(
        meshBuilder.m_VertexBuilder.m_pCurrTexCoord,
        meshBuilder.m_VertexBuilder.m_pTexCoord,
        sizeof(meshBuilder.m_VertexBuilder.m_pCurrTexCoord));
      meshBuilder.m_VertexBuilder.m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pNormal;
      meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
      meshBuilder.m_VertexBuilder.m_nCurrentVertex = 0;
      meshBuilder.m_VertexBuilder.m_pCurrColor = meshBuilder.m_VertexBuilder.m_pColor;
      v13 = TangentSpaceSurfaceSetup(surfID, &tVect);
      v14 = surfID;
      v15 = HIBYTE(surfID->flags) == 0;
      LOBYTE(negate) = v13;
      if ( !v15 )
      {
        while ( 1 )
        {
          v16 = &pBrushData->vertexes[pBrushData->vertindices[v6 + v14->firstvertindex]];
          v17 = &pBrushData->vertnormals[pBrushData->vertnormalindices[v6
                                                                     + host_state.worldbrush->surfacenormals[v14 - host_state.worldbrush->surfaces2].firstvertnormal]];
          TangentSpaceComputeBasis(&tangentS, &tangentT, normal: v17, &tVect, negateTangent: negate);
          m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          *meshBuilder.m_VertexBuilder.m_pCurrPosition = v16->position.x;
          m_pCurrPosition[1] = v16->position.y;
          m_pCurrPosition[2] = v16->position.z;
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          v19 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          v20 = (float)(v17->y * 5.0) + v16->position.y;
          v21 = (float)(v17->z * 5.0) + v16->position.z;
          *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)(v17->x * 5.0) + v16->position.x;
          v19[1] = v20;
          v19[2] = v21;
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          v22 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          *meshBuilder.m_VertexBuilder.m_pCurrPosition = v16->position.x;
          v22[1] = v16->position.y;
          v22[2] = v16->position.z;
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          v23 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          v24 = (float)(tangentT.y * 5.0) + v16->position.y;
          v25 = (float)(tangentT.z * 5.0) + v16->position.z;
          *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)(tangentT.x * 5.0) + v16->position.x;
          v23[1] = v24;
          v23[2] = v25;
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          v26 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          *meshBuilder.m_VertexBuilder.m_pCurrPosition = v16->position.x;
          v26[1] = v16->position.y;
          v26[2] = v16->position.z;
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          v27 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          v28 = (float)(tangentS.y * 5.0) + v16->position.y;
          v29 = (float)(tangentS.z * 5.0) + v16->position.z;
          *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)(tangentS.x * 5.0) + v16->position.x;
          v27[1] = v28;
          v27[2] = v29;
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          if ( ++v6 >= HIBYTE(surfID->flags) )
            break;
          v14 = surfID;
        }
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
      p_meshBuilder = &meshBuilder;
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
      if ( ++i >= listCount )
        break;
      v4 = pRenderContext;
      v6 = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D2140
// Name: Shader_DrawChainBumpBasis
// Source: json
//------------------------------------------------------------------------------
void __usercall Shader_DrawChainBumpBasis(
        CMeshBuilder *p_meshBuilder@<edi>,
        IMatRenderContext *pRenderContext,
        msurface2_t **pList,
        int listCount)
{
  IMatRenderContext *v4; // esi
  void (__thiscall *Bind)(IMatRenderContext *, IMaterial *, void *); // edx
  int v6; // ebx
  msurface2_t *v7; // edi
  IMesh *(__thiscall *GetDynamicMesh)(IMatRenderContext *, bool, IMesh *, IMesh *, IMaterial *); // eax
  IMesh *v9; // esi
  int v10; // eax
  int v11; // edi
  void (__thiscall *SetPrimitiveType)(IMesh *, MaterialPrimitiveType_t); // eax
  bool v13; // al
  msurface2_t *v14; // edx
  bool v15; // zf
  mvertex_t *v16; // esi
  Vector *v17; // edi
  float y; // xmm3_4
  float z; // xmm4_4
  float v20; // xmm2_4
  float v21; // xmm4_4
  float v22; // xmm7_4
  float *m_pCurrPosition; // eax
  double v24; // st7
  float v25; // xmm0_4
  float v26; // xmm5_4
  float v27; // xmm1_4
  float *v28; // eax
  float v29; // xmm1_4
  float v30; // xmm2_4
  float *v31; // eax
  float *v32; // eax
  float v33; // xmm1_4
  float v34; // xmm2_4
  float *v35; // eax
  float *v36; // eax
  float v37; // xmm1_4
  float v38; // xmm2_4
  int m_nVertexCount; // eax
  Vector tVect; // [esp+8h] [ebp-250h] BYREF
  CMeshBuilder meshBuilder; // [esp+14h] [ebp-244h] BYREF
  Vector worldSpaceBumpBasis[3]; // [esp+1FCh] [ebp-5Ch]
  float x; // [esp+220h] [ebp-38h]
  IMesh *pMesh; // [esp+224h] [ebp-34h]
  int v46; // [esp+228h] [ebp-30h]
  Vector tangentS; // [esp+22Ch] [ebp-2Ch] BYREF
  BOOL negate; // [esp+238h] [ebp-20h]
  worldbrushdata_t *pBrushData; // [esp+23Ch] [ebp-1Ch]
  float v50; // [esp+240h] [ebp-18h]
  Vector tangentT; // [esp+244h] [ebp-14h] BYREF
  int i; // [esp+250h] [ebp-8h]
  msurface2_t *surfID; // [esp+254h] [ebp-4h]

  v4 = pRenderContext;
  Bind = pRenderContext->Bind;
  pBrushData = host_state.worldbrush;
  v6 = 0;
  Bind(this: pRenderContext, a2: g_pMaterialWireframeVertexColor, a3: nullptr);
  i = 0;
  if ( listCount > 0 )
  {
    while ( 1 )
    {
      GetDynamicMesh = v4->GetDynamicMesh;
      surfID = pList[i];
      v7 = surfID;
      v9 = (IMesh *)((int (__thiscall *)(IMatRenderContext *, int, _DWORD, _DWORD, _DWORD, CMeshBuilder *))GetDynamicMesh)(
                      a1: v4,
                      a2: 1,
                      a3: 0,
                      a4: 0,
                      a5: 0,
                      a6: p_meshBuilder);
      meshBuilder.m_IndexBuilder.m_nBufferOffset = -1;
      meshBuilder.m_VertexBuilder.m_nBufferOffset = -1;
      meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
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
      v10 = 3 * HIBYTE(v7->flags);
      meshBuilder.m_pMesh = v9;
      meshBuilder.m_bGenerateIndices = true;
      meshBuilder.m_Type = MATERIAL_LINES;
      v11 = 2 * v10;
      SetPrimitiveType = v9->SetPrimitiveType;
      pMesh = v9;
      v46 = v11;
      SetPrimitiveType(this: v9, a2: MATERIAL_LINES);
      meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: v11, a3: v11, a4: &meshBuilder, a5: nullptr);
      meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v9->IIndexBuffer;
      meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
      meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
      meshBuilder.m_IndexBuilder.m_nMaxIndexCount = v11;
      meshBuilder.m_VertexBuilder.m_pVertexBuffer = v9;
      meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
      meshBuilder.m_IndexBuilder.m_bModify = false;
      meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
      meshBuilder.m_VertexBuilder.VertexDesc_t = meshBuilder.VertexDesc_t;
      meshBuilder.m_VertexBuilder.m_nMaxVertexCount = v46;
      meshBuilder.m_VertexBuilder.m_NumBoneWeights = meshBuilder.m_NumBoneWeights != 0 ? 2 : 0;
      meshBuilder.m_VertexBuilder.m_nVertexCount = 0;
      meshBuilder.m_VertexBuilder.m_bModify = false;
      if ( meshBuilder.m_VertexBuilder.m_nBufferOffset == -1 )
      {
        meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
        meshBuilder.m_VertexBuilder.m_nBufferOffset = meshBuilder.MeshDesc_t::VertexDesc_t::m_nOffset;
        meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = meshBuilder.m_nFirstVertex;
      }
      meshBuilder.m_VertexBuilder.m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pPosition;
      qmemcpy(
        meshBuilder.m_VertexBuilder.m_pCurrTexCoord,
        meshBuilder.m_VertexBuilder.m_pTexCoord,
        sizeof(meshBuilder.m_VertexBuilder.m_pCurrTexCoord));
      meshBuilder.m_VertexBuilder.m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pNormal;
      meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
      meshBuilder.m_VertexBuilder.m_nCurrentVertex = 0;
      meshBuilder.m_VertexBuilder.m_pCurrColor = meshBuilder.m_VertexBuilder.m_pColor;
      v13 = TangentSpaceSurfaceSetup(surfID, &tVect);
      v14 = surfID;
      v15 = HIBYTE(surfID->flags) == 0;
      LOBYTE(negate) = v13;
      if ( !v15 )
      {
        while ( 1 )
        {
          v16 = &pBrushData->vertexes[pBrushData->vertindices[v6 + v14->firstvertindex]];
          v17 = &pBrushData->vertnormals[pBrushData->vertnormalindices[v6
                                                                     + host_state.worldbrush->surfacenormals[v14 - host_state.worldbrush->surfaces2].firstvertnormal]];
          TangentSpaceComputeBasis(&tangentS, &tangentT, normal: v17, &tVect, negateTangent: negate);
          y = v17->y;
          worldSpaceBumpBasis[0].x = (float)((float)(tangentS.y * 0.0) + (float)(tangentS.x * 0.81649661))
                                   + (float)(tangentS.z * 0.57735026);
          z = v17->z;
          v20 = tangentT.z * 0.57735026;
          worldSpaceBumpBasis[0].y = (float)((float)(tangentT.y * 0.0) + (float)(tangentT.x * 0.81649661))
                                   + (float)(tangentT.z * 0.57735026);
          x = v17->x;
          v21 = z * 0.57735026;
          worldSpaceBumpBasis[0].z = (float)((float)(x * 0.81649661) + (float)(y * 0.0)) + v21;
          worldSpaceBumpBasis[1].x = (float)((float)(tangentS.y * 0.70710677) + (float)(tangentS.x * -0.40824822))
                                   + (float)(tangentS.z * 0.57735026);
          v50 = -0.40824822 * tangentT.x;
          v22 = x * -0.40824822;
          worldSpaceBumpBasis[1].y = (float)((float)(tangentT.y * 0.70710677) + (float)(-0.40824822 * tangentT.x))
                                   + (float)(tangentT.z * 0.57735026);
          m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          v24 = v16->position.x;
          worldSpaceBumpBasis[1].z = (float)((float)(y * 0.70710677) + (float)(x * -0.40824822)) + v21;
          v25 = -0.40824822 * tangentT.x;
          v26 = (float)((float)(tangentS.x * -0.40824822) - (float)(tangentS.y * 0.70710677))
              + (float)(tangentS.z * 0.57735026);
          v27 = tangentT.y;
          *meshBuilder.m_VertexBuilder.m_pCurrPosition = v24;
          m_pCurrPosition[1] = v16->position.y;
          m_pCurrPosition[2] = v16->position.z;
          worldSpaceBumpBasis[2].x = v26;
          worldSpaceBumpBasis[2].y = (float)(v25 - (float)(v27 * 0.70710677)) + v20;
          worldSpaceBumpBasis[2].z = (float)(v22 - (float)(y * 0.70710677)) + v21;
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          v28 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          v29 = (float)(worldSpaceBumpBasis[0].y * 5.0) + v16->position.y;
          v30 = (float)(worldSpaceBumpBasis[0].z * 5.0) + v16->position.z;
          *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)(worldSpaceBumpBasis[0].x * 5.0) + v16->position.x;
          v28[1] = v29;
          v28[2] = v30;
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -65536;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          v31 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          *meshBuilder.m_VertexBuilder.m_pCurrPosition = v16->position.x;
          v31[1] = v16->position.y;
          v31[2] = v16->position.z;
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          v32 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          v33 = (float)(worldSpaceBumpBasis[1].y * 5.0) + v16->position.y;
          v34 = (float)(worldSpaceBumpBasis[1].z * 5.0) + v16->position.z;
          *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)(worldSpaceBumpBasis[1].x * 5.0) + v16->position.x;
          v32[1] = v33;
          v32[2] = v34;
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16711936;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          v35 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          *meshBuilder.m_VertexBuilder.m_pCurrPosition = v16->position.x;
          v35[1] = v16->position.y;
          v35[2] = v16->position.z;
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          v36 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          v37 = (float)(worldSpaceBumpBasis[2].y * 5.0) + v16->position.y;
          v38 = (float)(worldSpaceBumpBasis[2].z * 5.0) + v16->position.z;
          *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)(worldSpaceBumpBasis[2].x * 5.0) + v16->position.x;
          v36[1] = v37;
          v36[2] = v38;
          *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16776961;
          CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
          if ( ++v6 >= HIBYTE(surfID->flags) )
            break;
          v14 = surfID;
        }
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
      p_meshBuilder = &meshBuilder;
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
      if ( ++i >= listCount )
        break;
      v4 = pRenderContext;
      v6 = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D2820
// Name: Shader_DrawLuxels
// Source: json
//------------------------------------------------------------------------------
void __usercall Shader_DrawLuxels(IMatRenderContext *pRenderContext@<esi>, msurface2_t **pList, int listCount)
{
  int i; // edi
  msurface2_t *v4; // ebx

  pRenderContext->Bind(this: pRenderContext, a2: g_materialDebugLuxels, a3: nullptr);
  for ( i = 0; i < listCount; ++i )
  {
    v4 = pList[i];
    pRenderContext->BindLightmapPage(this: pRenderContext, a2: materialSortInfoArray[v4->materialSortID].lightmapPageID);
    Shader_DrawSurfaceDynamic(pRenderContext, surfID: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D2880
// Name: ComputeDebugSettings
// Source: json
//------------------------------------------------------------------------------
bool ComputeDebugSettings()
{
  int m_nValue; // eax
  bool v1; // bl
  int v2; // eax
  int v3; // eax
  int v4; // eax
  bool v5; // dl
  int v6; // ecx
  int v7; // eax
  bool result; // al

  v1 = (sv_cheats.m_pParent != nullptr && sv_cheats.m_pParent->m_Value.m_nValue != 0 || Cmd_IsRptActive())
    && (mat_wireframe.m_pParent == nullptr ? (m_nValue = 0) : (m_nValue = mat_wireframe.m_pParent->m_Value.m_nValue),
        m_nValue != 0)
    || r_drawworld.m_pParent != nullptr && r_drawworld.m_pParent->m_Value.m_nValue == 2;
  g_ShaderDebug.wireframe = v1;
  if ( mat_normals.m_pParent != nullptr )
    v2 = mat_normals.m_pParent->m_Value.m_nValue;
  else
    v2 = 0;
  g_ShaderDebug.normals = v2 != 0;
  if ( mat_luxels.m_pParent != nullptr )
    v3 = mat_luxels.m_pParent->m_Value.m_nValue;
  else
    v3 = 0;
  g_ShaderDebug.luxels = v3 != 0;
  if ( mat_bumpbasis.m_pParent != nullptr )
    v4 = mat_bumpbasis.m_pParent->m_Value.m_nValue;
  else
    v4 = 0;
  v5 = v4 != 0;
  g_ShaderDebug.bumpBasis = v4 != 0;
  if ( mat_surfaceid.m_pParent != nullptr )
    v6 = mat_surfaceid.m_pParent->m_Value.m_nValue;
  else
    v6 = 0;
  g_ShaderDebug.surfaceid = v6;
  if ( mat_surfacemat.m_pParent != nullptr )
    v7 = mat_surfacemat.m_pParent->m_Value.m_nValue;
  else
    v7 = 0;
  result = v7 != 0;
  g_ShaderDebug.surfacematerials = result;
  if ( v1 || g_ShaderDebug.normals || g_ShaderDebug.luxels || v5 || v6 != 0 || (g_ShaderDebug.anydebug = false, result) )
    g_ShaderDebug.anydebug = true;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D2980
// Name: void DrawDebugInformation(class IMatRenderContext __near *,struct msurface2_t __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawDebugInformation(IMatRenderContext *pRenderContext, msurface2_t **pList, int listCount)
{
  msurface2_t **v3; // esi
  void (__cdecl *v4)(IMatRenderContext *, msurface2_t *, const Vector *); // eax
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  v3 = pList;
  if ( g_ShaderDebug.wireframe )
    Shader_DrawChainsWireframe(pRenderContext, pList, listCount);
  if ( g_ShaderDebug.normals )
    Shader_DrawChainNormals(p_meshBuilder: (CMeshBuilder *)pRenderContext, pRenderContext, pList, listCount);
  if ( g_ShaderDebug.bumpBasis )
    Shader_DrawChainBumpBasis(p_meshBuilder: (CMeshBuilder *)pRenderContext, pRenderContext, pList, listCount);
  if ( g_ShaderDebug.luxels )
  {
    Shader_DrawLuxels(pRenderContext, pList, listCount);
    v3 = pList;
  }
  if ( g_ShaderDebug.surfaceid != 0 )
  {
    v4 = DrawSurfaceID;
    if ( g_ShaderDebug.surfaceid == 2 )
      v4 = DrawSurfaceIDAsInt;
    Shader_DrawSurfaceDebuggingInfo(a1: (int)&savedregs, pRenderContext, pList: v3, listCount, func: v4);
  }
  else if ( g_ShaderDebug.surfacematerials )
  {
    Shader_DrawSurfaceDebuggingInfo(
      a1: (int)&savedregs,
      pRenderContext,
      pList: v3,
      listCount,
      func: DrawSurfaceMaterial);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D2A30
// Name: Shader_BuildDynamicLightmaps
// Source: json
//------------------------------------------------------------------------------
void __cdecl Shader_BuildDynamicLightmaps(CWorldRenderList *pRenderList)
{
  CUtlVector<msurface2_t *,CUtlMemory<msurface2_t *,int> > *m_DlightSurfaces; // edi
  int i; // ebx
  int j; // esi

  R_DLightStartView();
  m_DlightSurfaces = pRenderList->m_DlightSurfaces;
  for ( i = 4; i != 0; --i )
  {
    for ( j = m_DlightSurfaces->m_Size - 1; j >= 0; --j )
      R_CheckForLightmapUpdates(surfID: m_DlightSurfaces->m_Memory.m_pMemory[j], nTransformIndex: 0);
    ++m_DlightSurfaces;
  }
  R_DLightEndView();
}

//------------------------------------------------------------------------------
// Address: 0x100D2A80
// Name: void Shader_WorldBegin(class CWorldRenderList __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Shader_WorldBegin(CWorldRenderList *pRenderList)
{
  int m_nValue; // eax
  int v2; // eax
  IOverlayMgr *v3; // eax

  if ( r_drawworld.m_pParent != nullptr )
    m_nValue = r_drawworld.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  s_ShaderConvars.m_bDrawWorld = m_nValue != 0;
  if ( r_drawleaf.m_pParent != nullptr )
    s_ShaderConvars.m_nDrawLeaf = r_drawleaf.m_pParent->m_Value.m_nValue;
  else
    s_ShaderConvars.m_nDrawLeaf = 0;
  if ( r_drawfuncdetail.m_pParent != nullptr )
    v2 = r_drawfuncdetail.m_pParent->m_Value.m_nValue;
  else
    v2 = 0;
  s_ShaderConvars.m_bDrawFuncDetail = v2 != 0;
  if ( pRenderList != nullptr )
    CWorldRenderList::Reset(this: pRenderList);
  DecalSurfacesInit(bBrushModel: false);
  v3 = OverlayMgr();
  v3->ClearRenderLists_2(this: v3);
  g_pShadowMgr->ClearShadowRenderList(this: g_pShadowMgr);
}

//------------------------------------------------------------------------------
// Address: 0x100D2B10
// Name: Shader_WorldZFillSurfChain_SinglePrimitive
// Source: json
//------------------------------------------------------------------------------
void __usercall Shader_WorldZFillSurfChain_SinglePrimitive(
        CMeshBuilder *meshBuilder@<esi>,
        msurface2_t *surfaceHandle,
        int *nStartVert)
{
  worldbrushdata_t *worldbrush; // eax
  unsigned __int16 firstPrimID; // cx
  mprimitive_t *primitives; // edx
  int v6; // ecx
  bool v7; // zf
  mprimitive_t *v8; // edx
  int v9; // ebx
  int firstvertindex; // edi
  float *p_x; // eax
  float *m_pCurrPosition; // ecx
  int v13; // ecx
  mprimitive_t *pPrim; // [esp+4h] [ebp-8h]
  mvertex_t *pWorldVerts; // [esp+8h] [ebp-4h]

  worldbrush = host_state.worldbrush;
  pWorldVerts = host_state.worldbrush->vertexes;
  if ( (surfaceHandle->flags & 0x800) != 0 )
    firstPrimID = 0;
  else
    firstPrimID = host_state.worldbrush->surfaces1[surfaceHandle - host_state.worldbrush->surfaces2].prims.firstPrimID;
  primitives = host_state.worldbrush->primitives;
  v6 = firstPrimID;
  v7 = primitives[v6].vertCount == 0;
  v8 = &primitives[v6];
  pPrim = v8;
  if ( v7 )
  {
    v9 = 0;
    if ( HIBYTE(surfaceHandle->flags) != 0 )
    {
      firstvertindex = surfaceHandle->firstvertindex;
      do
      {
        p_x = &pWorldVerts[worldbrush->vertindices[firstvertindex]].position.x;
        m_pCurrPosition = meshBuilder->m_VertexBuilder.m_pCurrPosition;
        *m_pCurrPosition = *p_x;
        m_pCurrPosition[1] = p_x[1];
        m_pCurrPosition[2] = p_x[2];
        CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
        worldbrush = host_state.worldbrush;
        ++v9;
        ++firstvertindex;
      }
      while ( v9 < HIBYTE(surfaceHandle->flags) );
      v8 = pPrim;
    }
    v13 = 0;
    if ( v8->indexCount != 0 )
    {
      while ( 1 )
      {
        meshBuilder->m_IndexBuilder.m_pIndices[meshBuilder->m_IndexBuilder.m_nCurrentIndex] = *(_WORD *)nStartVert
                                                                                            + LOWORD(meshBuilder->m_IndexBuilder.m_nIndexOffset)
                                                                                            + worldbrush->primindices[v13 + v8->firstIndex];
        meshBuilder->m_IndexBuilder.m_nCurrentIndex += meshBuilder->m_IndexBuilder.m_nIndexSize;
        meshBuilder->m_IndexBuilder.m_nIndexCount = meshBuilder->m_IndexBuilder.m_nCurrentIndex;
        if ( ++v13 >= v8->indexCount )
          break;
        worldbrush = host_state.worldbrush;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D2C30
// Name: Shader_WorldZFillSurfChain_Single
// Source: json
//------------------------------------------------------------------------------
void __usercall Shader_WorldZFillSurfChain_Single(
        msurface2_t *surfaceHandle@<eax>,
        CMeshBuilder *meshBuilder@<ecx>,
        int *nStartVert@<edi>)
{
  mvertex_t *vertexes; // ecx
  unsigned __int16 *v5; // ebx
  float *v6; // eax
  float *v7; // ecx
  int v8; // eax
  int v9; // eax
  float *v10; // eax
  float *v11; // ecx
  float *v12; // esi
  float *v13; // eax
  float *v14; // ecx
  float *v15; // eax
  float *v16; // eax
  float *v17; // ecx
  float *v18; // eax
  float *v19; // ecx
  float *v20; // ecx
  float *v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  unsigned __int16 v25; // ax
  float *m_pCurrPosition; // eax
  float *p_x; // ecx
  float *v28; // eax
  float *v29; // ecx
  float *v30; // ecx
  float *v31; // eax
  int m_nCurrentIndex; // eax
  int v; // [esp+8h] [ebp-Ch]
  CVertexBuilder *va; // [esp+8h] [ebp-Ch]
  int nSurfTriangleCount; // [esp+Ch] [ebp-8h]
  mvertex_t *pWorldVerts; // [esp+10h] [ebp-4h]

  nSurfTriangleCount = HIBYTE(surfaceHandle->flags) - 2;
  vertexes = host_state.worldbrush->vertexes;
  v5 = &host_state.worldbrush->vertindices[surfaceHandle->firstvertindex];
  pWorldVerts = vertexes;
  if ( (surfaceHandle->flags & 0x8000) != 0 )
  {
    Shader_WorldZFillSurfChain_SinglePrimitive(meshBuilder, surfaceHandle, nStartVert);
    *nStartVert += nSurfTriangleCount + 2;
    return;
  }
  if ( HIBYTE(surfaceHandle->flags) == 3 )
  {
    m_pCurrPosition = meshBuilder->m_VertexBuilder.m_pCurrPosition;
    p_x = &vertexes[*v5].position.x;
    *m_pCurrPosition = *p_x;
    m_pCurrPosition[1] = p_x[1];
    m_pCurrPosition[2] = p_x[2];
    CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
    v28 = &pWorldVerts[v5[1]].position.x;
    v29 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
    *v29 = *v28;
    v29[1] = v28[1];
    v29[2] = v28[2];
    CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
    v30 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
    v31 = &pWorldVerts[v5[2]].position.x;
    *v30 = *v31;
    v30[1] = v31[1];
    v30[2] = v31[2];
    CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
    meshBuilder->m_IndexBuilder.m_pIndices[meshBuilder->m_IndexBuilder.m_nCurrentIndex] = *(_WORD *)nStartVert
                                                                                        + LOWORD(meshBuilder->m_IndexBuilder.m_nIndexOffset);
    meshBuilder->m_IndexBuilder.m_nCurrentIndex += meshBuilder->m_IndexBuilder.m_nIndexSize;
    m_nCurrentIndex = meshBuilder->m_IndexBuilder.m_nCurrentIndex;
    meshBuilder->m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
    meshBuilder->m_IndexBuilder.m_pIndices[m_nCurrentIndex] = *(_WORD *)nStartVert
                                                            + LOWORD(meshBuilder->m_IndexBuilder.m_nIndexOffset)
                                                            + 1;
    meshBuilder->m_IndexBuilder.m_nCurrentIndex += meshBuilder->m_IndexBuilder.m_nIndexSize;
    meshBuilder->m_IndexBuilder.m_nIndexCount = meshBuilder->m_IndexBuilder.m_nCurrentIndex;
    v25 = *(_WORD *)nStartVert + LOWORD(meshBuilder->m_IndexBuilder.m_nIndexOffset) + 2;
    goto LABEL_10;
  }
  if ( HIBYTE(surfaceHandle->flags) == 4 )
  {
    v14 = &vertexes[*v5].position.x;
    v15 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
    *v15 = *v14;
    v15[1] = v14[1];
    v15[2] = v14[2];
    CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
    v16 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
    v17 = &pWorldVerts[v5[1]].position.x;
    *v16 = *v17;
    v16[1] = v17[1];
    v16[2] = v17[2];
    CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
    v18 = &pWorldVerts[v5[2]].position.x;
    v19 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
    *v19 = *v18;
    v19[1] = v18[1];
    v19[2] = v18[2];
    CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
    v20 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
    v21 = &pWorldVerts[v5[3]].position.x;
    *v20 = *v21;
    v20[1] = v21[1];
    v20[2] = v21[2];
    CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
    meshBuilder->m_IndexBuilder.m_pIndices[meshBuilder->m_IndexBuilder.m_nCurrentIndex] = *(_WORD *)nStartVert
                                                                                        + LOWORD(meshBuilder->m_IndexBuilder.m_nIndexOffset);
    meshBuilder->m_IndexBuilder.m_nCurrentIndex += meshBuilder->m_IndexBuilder.m_nIndexSize;
    v22 = meshBuilder->m_IndexBuilder.m_nCurrentIndex;
    meshBuilder->m_IndexBuilder.m_nIndexCount = v22;
    meshBuilder->m_IndexBuilder.m_pIndices[v22] = *(_WORD *)nStartVert
                                                + LOWORD(meshBuilder->m_IndexBuilder.m_nIndexOffset)
                                                + 1;
    meshBuilder->m_IndexBuilder.m_nCurrentIndex += meshBuilder->m_IndexBuilder.m_nIndexSize;
    meshBuilder->m_IndexBuilder.m_nIndexCount = meshBuilder->m_IndexBuilder.m_nCurrentIndex;
    meshBuilder->m_IndexBuilder.m_pIndices[meshBuilder->m_IndexBuilder.m_nCurrentIndex] = *(_WORD *)nStartVert
                                                                                        + LOWORD(meshBuilder->m_IndexBuilder.m_nIndexOffset)
                                                                                        + 2;
    meshBuilder->m_IndexBuilder.m_nCurrentIndex += meshBuilder->m_IndexBuilder.m_nIndexSize;
    v23 = meshBuilder->m_IndexBuilder.m_nCurrentIndex;
    meshBuilder->m_IndexBuilder.m_nIndexCount = v23;
    meshBuilder->m_IndexBuilder.m_pIndices[v23] = *(_WORD *)nStartVert
                                                + LOWORD(meshBuilder->m_IndexBuilder.m_nIndexOffset);
    meshBuilder->m_IndexBuilder.m_nCurrentIndex += meshBuilder->m_IndexBuilder.m_nIndexSize;
    v24 = meshBuilder->m_IndexBuilder.m_nCurrentIndex;
    meshBuilder->m_IndexBuilder.m_nIndexCount = v24;
    meshBuilder->m_IndexBuilder.m_pIndices[v24] = *(_WORD *)nStartVert
                                                + LOWORD(meshBuilder->m_IndexBuilder.m_nIndexOffset)
                                                + 2;
    meshBuilder->m_IndexBuilder.m_nCurrentIndex += meshBuilder->m_IndexBuilder.m_nIndexSize;
    meshBuilder->m_IndexBuilder.m_nIndexCount = meshBuilder->m_IndexBuilder.m_nCurrentIndex;
    v25 = *(_WORD *)nStartVert + LOWORD(meshBuilder->m_IndexBuilder.m_nIndexOffset) + 3;
LABEL_10:
    meshBuilder->m_IndexBuilder.m_pIndices[meshBuilder->m_IndexBuilder.m_nCurrentIndex] = v25;
    meshBuilder->m_IndexBuilder.m_nCurrentIndex += meshBuilder->m_IndexBuilder.m_nIndexSize;
    meshBuilder->m_IndexBuilder.m_nIndexCount = meshBuilder->m_IndexBuilder.m_nCurrentIndex;
    *nStartVert += nSurfTriangleCount + 2;
    return;
  }
  for ( v = 0; (unsigned __int16)v < nSurfTriangleCount; ++v )
  {
    v6 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
    v7 = &vertexes[*v5++].position.x;
    *v6 = *v7;
    v6[1] = v7[1];
    v6[2] = v7[2];
    CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
    meshBuilder->m_IndexBuilder.m_pIndices[meshBuilder->m_IndexBuilder.m_nCurrentIndex] = *(_WORD *)nStartVert
                                                                                        + LOWORD(meshBuilder->m_IndexBuilder.m_nIndexOffset);
    meshBuilder->m_IndexBuilder.m_nCurrentIndex += meshBuilder->m_IndexBuilder.m_nIndexSize;
    v8 = meshBuilder->m_IndexBuilder.m_nCurrentIndex;
    meshBuilder->m_IndexBuilder.m_nIndexCount = v8;
    meshBuilder->m_IndexBuilder.m_pIndices[v8] = v
                                               + *(_WORD *)nStartVert
                                               + LOWORD(meshBuilder->m_IndexBuilder.m_nIndexOffset)
                                               + 1;
    meshBuilder->m_IndexBuilder.m_nCurrentIndex += meshBuilder->m_IndexBuilder.m_nIndexSize;
    v9 = meshBuilder->m_IndexBuilder.m_nCurrentIndex;
    meshBuilder->m_IndexBuilder.m_nIndexCount = v9;
    meshBuilder->m_IndexBuilder.m_pIndices[v9] = v
                                               + *(_WORD *)nStartVert
                                               + LOWORD(meshBuilder->m_IndexBuilder.m_nIndexOffset)
                                               + 2;
    meshBuilder->m_IndexBuilder.m_nCurrentIndex += meshBuilder->m_IndexBuilder.m_nIndexSize;
    vertexes = pWorldVerts;
    meshBuilder->m_IndexBuilder.m_nIndexCount = meshBuilder->m_IndexBuilder.m_nCurrentIndex;
  }
  v10 = &vertexes[*v5].position.x;
  v11 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
  *v11 = *v10;
  v11[1] = v10[1];
  v11[2] = v10[2];
  va = &meshBuilder->m_VertexBuilder;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder->m_VertexBuilder);
  v12 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
  v13 = &pWorldVerts[v5[1]].position.x;
  *v12 = *v13;
  v12[1] = v13[1];
  v12[2] = v13[2];
  CVertexBuilder::AdvanceVertex(this: va);
  *nStartVert += nSurfTriangleCount + 2;
}

//------------------------------------------------------------------------------
// Address: 0x100D30D0
// Name: bool Shader_LeafContainsTranslucentSurfaces(class IWorldRenderList __near *,int,unsigned long)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Shader_LeafContainsTranslucentSurfaces(IWorldRenderList *pRenderListIn, int sortIndex)
{
  return HIWORD(pRenderListIn[164].__vftable[sortIndex].Release) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100D30F0
// Name: void R_GetWorldListIndicesInfo(struct WorldListIndicesInfo_t __near *,class IWorldRenderList __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_GetWorldListIndicesInfo(
        WorldListIndicesInfo_t *pInfoOut,
        IWorldRenderList *pRenderListIn,
        unsigned int nFlags)
{
  int v3; // edi
  char *v4; // edx
  int v5; // ebx
  unsigned int v6; // esi
  IWorldRenderList_vtbl *v7; // ecx
  IWorldRenderList_vtbl *v8; // edx
  IWorldRenderList_vtbl *i; // edi
  unsigned int v10; // eax
  int v11; // [esp+Ch] [ebp-8h]
  char *v12; // [esp+10h] [ebp-4h]

  v3 = 1;
  v4 = &args.m_pArgSBuffer[188];
  v5 = 0;
  v6 = 0;
  v11 = 1;
  v12 = &args.m_pArgSBuffer[188];
  do
  {
    if ( (v3 & nFlags) != 0 )
    {
      v7 = pRenderListIn[5 * *(_DWORD *)v4 + 21].__vftable;
      if ( (int)v7 > 0 )
      {
        v8 = pRenderListIn[5 * *(_DWORD *)v4 + 18].__vftable;
        for ( i = v7; i != nullptr; i = (IWorldRenderList_vtbl *)((char *)i - 1) )
        {
          v10 = *((_DWORD *)v8->AddRef + 6);
          v5 += v10;
          if ( v6 <= v10 )
            v6 = *((_DWORD *)v8->AddRef + 6);
          v8 = (IWorldRenderList_vtbl *)((char *)v8 + 4);
        }
        v3 = v11;
        v4 = v12;
      }
    }
    v4 += 4;
    v3 = __ROL4__(v3, 1);
    v12 = v4;
    v11 = v3;
  }
  while ( (int)v4 < (int)&args.m_pArgSBuffer[204] );
  pInfoOut->m_nMaxBatchIndices = 3 * v6;
  pInfoOut->m_nTotalIndices = 3 * v5;
}

//------------------------------------------------------------------------------
// Address: 0x100D3180
// Name: void R_SceneBegin(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl R_SceneBegin()
{
  ComputeDebugSettings();
}

//------------------------------------------------------------------------------
// Address: 0x100D3190
// Name: public: virtual bool CEngineBSPTree::EnumerateLeavesInSphere(class Vector const __near &,float,class ISpatialLeafEnumerator __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineBSPTree::EnumerateLeavesInSphere(
        CEngineBSPTree *this,
        const Vector *center,
        float radius,
        ISpatialLeafEnumerator *pEnum,
        int context)
{
  float y; // xmm2_4
  float z; // xmm3_4
  EnumLeafSphereInfo_t info; // [esp+0h] [ebp-30h] BYREF

  y = center->y;
  z = center->z;
  info.m_vecCenter.x = center->x;
  info.m_vecCenter.y = y;
  info.m_vecCenter.z = z;
  info.m_flRadius = radius;
  info.m_nContext = context;
  info.m_vecBoxCenter = info.m_vecCenter;
  info.m_vecBoxHalfDiagonal.x = radius;
  info.m_vecBoxHalfDiagonal.y = radius;
  *(_QWORD *)&info.m_vecBoxHalfDiagonal.z = __PAIR64__((unsigned int)pEnum, LODWORD(radius));
  return EnumerateLeafInSphere_R<0>(node: host_state.worldbrush->nodes, &info, nTestFlags: 1879048192);
}

//------------------------------------------------------------------------------
// Address: 0x100D3210
// Name: public: virtual bool CEngineBSPTree::EnumerateLeavesInSphereWithFlagSet(class Vector const __near &,float,class ISpatialLeafEnumerator __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineBSPTree::EnumerateLeavesInSphereWithFlagSet(
        CEngineBSPTree *this,
        const Vector *center,
        float radius,
        ISpatialLeafEnumerator *pEnum,
        int context,
        int nFlags)
{
  float x; // xmm1_4
  float y; // xmm2_4
  float z; // xmm3_4
  EnumLeafSphereInfo_t info; // [esp+0h] [ebp-30h] BYREF

  x = center->x;
  y = center->y;
  z = center->z;
  info.m_nContext = context;
  info.m_vecCenter.x = x;
  info.m_vecCenter.y = y;
  info.m_vecCenter.z = z;
  info.m_flRadius = radius;
  info.m_vecBoxCenter.x = x;
  info.m_vecBoxCenter.y = y;
  info.m_vecBoxCenter.z = z;
  info.m_vecBoxHalfDiagonal.x = radius;
  info.m_vecBoxHalfDiagonal.y = radius;
  *(_QWORD *)&info.m_vecBoxHalfDiagonal.z = __PAIR64__((unsigned int)pEnum, LODWORD(radius));
  return EnumerateLeafInSphere_R<1>(node: host_state.worldbrush->nodes, &info, nTestFlags: nFlags | 0x70000000);
}

//------------------------------------------------------------------------------
// Address: 0x100D3290
// Name: public: void CVarBitVecBase<unsigned short>::Resize(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVarBitVecBase<unsigned short>::Resize(
        CVarBitVecBase<unsigned short> *this,
        int resizeNumBits,
        bool bClearAll)
{
  int m_numInts; // ecx
  int v5; // edi
  unsigned int *v6; // eax
  unsigned int *p_m_iBitStringStorage; // eax
  unsigned __int8 *m_pInt; // eax
  unsigned int *v9; // eax

  m_numInts = this->m_numInts;
  v5 = (resizeNumBits + 31) / 32;
  if ( v5 != m_numInts )
  {
    if ( this->m_pInt != nullptr )
    {
      CVarBitVecBase<unsigned short>::ReallocInts(this, numInts: (resizeNumBits + 31) / 32);
      if ( !bClearAll && resizeNumBits >= this->m_numBits )
      {
        v6 = &this->m_pInt[this->m_numInts - 1];
        *v6 &= `GetEndMask'::`2'::bitStringEndMasks[this->m_numBits & 0x1F];
        memset(dst: (unsigned __int8 *)&this->m_pInt[this->m_numInts], value: 0, count: 4 * (v5 - this->m_numInts));
      }
    }
    else
    {
      if ( v5 != 0 )
      {
        if ( v5 == 1 )
          p_m_iBitStringStorage = &this->m_iBitStringStorage;
        else
          p_m_iBitStringStorage = (unsigned int *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * v5);
        this->m_pInt = p_m_iBitStringStorage;
      }
      bClearAll = true;
    }
    this->m_numInts = v5;
    if ( !bClearAll )
      goto LABEL_15;
    goto LABEL_13;
  }
  if ( bClearAll )
  {
LABEL_13:
    m_pInt = (unsigned __int8 *)this->m_pInt;
    if ( m_pInt != nullptr )
      memset(dst: m_pInt, value: 0, count: 4 * v5);
LABEL_15:
    this->m_numBits = resizeNumBits;
    return;
  }
  if ( resizeNumBits < this->m_numBits )
    goto LABEL_15;
  v9 = this->m_pInt;
  if ( v9 == nullptr )
    goto LABEL_15;
  v9[m_numInts - 1] &= `GetEndMask'::`2'::bitStringEndMasks[this->m_numBits & 0x1F];
  this->m_numBits = resizeNumBits;
}

//------------------------------------------------------------------------------
// Address: 0x100D33A0
// Name: public: void CWorldRenderList::Init(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorldRenderList::Init(CWorldRenderList *this, int nSurfaces)
{
  int v3; // eax
  int v4; // eax
  WorldListLeafData_t *m_pMemory; // eax
  IMemAlloc_vtbl *v6; // edx
  WorldListLeafData_t *v7; // eax

  v3 = materials->GetNumSortIDs(this: materials);
  CMSurfaceSortList::Init(this: &this->m_SortList, maxSortIDs: v3, minMaterialLists: 512);
  v4 = materials->GetNumSortIDs(this: materials);
  CMSurfaceSortList::Init(this: &this->m_DispSortList, maxSortIDs: v4, minMaterialLists: 32);
  CVarBitVecBase<unsigned short>::Resize(this: &this->m_VisitedSurfs.m_bits, resizeNumBits: nSurfaces, bClearAll: false);
  if ( this->m_leaves.m_Memory.m_nAllocationCount < 1024 && this->m_leaves.m_Memory.m_nGrowSize >= 0 )
  {
    this->m_leaves.m_Memory.m_nAllocationCount = 1024;
    m_pMemory = this->m_leaves.m_Memory.m_pMemory;
    v6 = _g_pMemAlloc->__vftable;
    if ( m_pMemory != nullptr )
      v7 = (WorldListLeafData_t *)((int (__stdcall *)(WorldListLeafData_t *, int))v6->Realloc_2)(
                                    a1: m_pMemory,
                                    a2: 0x2000);
    else
      v7 = (WorldListLeafData_t *)((int (__stdcall *)(int))v6->Alloc_2)(a1: 0x2000);
    this->m_leaves.m_Memory.m_pMemory = v7;
  }
  this->m_leaves.m_pElements = this->m_leaves.m_Memory.m_pMemory;
  *(_WORD *)&this->m_bSkyVisible = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100D3460
// Name: public: void CWorldRenderList::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorldRenderList::Purge(CWorldRenderList *this)
{
  int *p_m_nGrowSize; // esi
  msurface2_t **m_pMemory; // ecx
  int i; // [esp+8h] [ebp-4h]

  this->m_leaves.m_Size = 0;
  if ( this->m_leaves.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_leaves.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_leaves.m_Memory.m_pMemory);
      this->m_leaves.m_Memory.m_pMemory = nullptr;
    }
    this->m_leaves.m_Memory.m_nAllocationCount = 0;
  }
  this->m_leaves.m_pElements = this->m_leaves.m_Memory.m_pMemory;
  p_m_nGrowSize = &this->m_ShadowHandles[0].m_Memory.m_nGrowSize;
  for ( i = 4; i != 0; --i )
  {
    p_m_nGrowSize[1] = 0;
    if ( *p_m_nGrowSize >= 0 )
    {
      if ( *(p_m_nGrowSize - 2) != 0 )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)*(p_m_nGrowSize - 2));
        *(p_m_nGrowSize - 2) = 0;
      }
      *(p_m_nGrowSize - 1) = 0;
    }
    p_m_nGrowSize[2] = *(p_m_nGrowSize - 2);
    p_m_nGrowSize[21] = 0;
    if ( p_m_nGrowSize[20] >= 0 )
    {
      if ( p_m_nGrowSize[18] != 0 )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)p_m_nGrowSize[18]);
        p_m_nGrowSize[18] = 0;
      }
      p_m_nGrowSize[19] = 0;
    }
    p_m_nGrowSize[22] = p_m_nGrowSize[18];
    p_m_nGrowSize[41] = 0;
    if ( p_m_nGrowSize[40] >= 0 )
    {
      if ( p_m_nGrowSize[38] != 0 )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)p_m_nGrowSize[38]);
        p_m_nGrowSize[38] = 0;
      }
      p_m_nGrowSize[39] = 0;
    }
    p_m_nGrowSize[42] = p_m_nGrowSize[38];
    p_m_nGrowSize += 5;
  }
  CColorBalanceUIPanel::Init(this: (vgui::PropertyPage *)&this->m_SortList);
  CColorBalanceUIPanel::Init(this: (vgui::PropertyPage *)&this->m_DispSortList);
  this->m_AlphaSurfaces.m_Size = 0;
  if ( this->m_AlphaSurfaces.m_Memory.m_nGrowSize < 0 )
  {
    this->m_AlphaSurfaces.m_pElements = this->m_AlphaSurfaces.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_AlphaSurfaces.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_AlphaSurfaces.m_Memory.m_pMemory);
      this->m_AlphaSurfaces.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_AlphaSurfaces.m_Memory.m_pMemory;
    this->m_AlphaSurfaces.m_Memory.m_nAllocationCount = 0;
    this->m_AlphaSurfaces.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D35D0
// Name: Shader_DrawDynamicChain
// Source: json
//------------------------------------------------------------------------------
void __usercall Shader_DrawDynamicChain(
        IMatRenderContext *pRenderContext@<ecx>,
        const surfacesortgroup_t *group@<eax>,
        CMSurfaceSortList *sortList,
        bool bShadowDepth)
{
  CMSurfaceSortList *v4; // ebx
  msurface2_t *SurfaceAtHead; // eax
  IMesh *v8; // eax
  IMatRenderContext_vtbl *v9; // edx
  int v10; // eax
  int (__thiscall *GetMaxVerticesToRender)(IMatRenderContext *, IMaterial *); // edx
  int v12; // eax
  signed int vertexCount; // edx
  IMesh *v14; // edi
  __int16 listHead; // ax
  int v16; // eax
  char *v17; // esi
  int v18; // edi
  msurface2_t **v19; // ebx
  int v20; // eax
  char *v21; // esi
  int v22; // edi
  msurface2_t **v23; // ebx
  int m_nVertexCount; // eax
  __int16 v25; // ax
  int v26; // eax
  IMesh *v27; // esi
  int v28; // ebx
  CMeshBuilder meshBuilder; // [esp+Ch] [ebp-1F8h] BYREF
  int nMaxIndices; // [esp+1F4h] [ebp-10h]
  int nCurrIndexCount; // [esp+1F8h] [ebp-Ch]
  int nCurrVertexCount; // [esp+1FCh] [ebp-8h]
  IMesh *pMesh; // [esp+200h] [ebp-4h]

  v4 = sortList;
  SurfaceAtHead = CMSurfaceSortList::GetSurfaceAtHead(this: sortList, group);
  if ( SurfaceAtHead == nullptr )
    return;
  v8 = (IMesh *)Shader_SetChainTextureState(pRenderContext, surfID: SurfaceAtHead, pBaseEntity: nullptr, bShadowDepth);
  v9 = pRenderContext->__vftable;
  pMesh = v8;
  v10 = v9->GetMaxIndicesToRender(this: pRenderContext);
  GetMaxVerticesToRender = pRenderContext->GetMaxVerticesToRender;
  nMaxIndices = v10;
  v12 = GetMaxVerticesToRender(this: pRenderContext, a2: (IMaterial *)pMesh);
  vertexCount = group->vertexCount;
  nCurrIndexCount = 3 * group->triangleCount;
  nCurrVertexCount = vertexCount;
  if ( nCurrIndexCount < nMaxIndices && vertexCount < v12 )
  {
    v14 = pRenderContext->GetDynamicMesh(this: pRenderContext, a2: 0, a3: 0, a4: 0, a5: 0);
    pMesh = v14;
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    CMeshBuilder::Begin(
      this: &meshBuilder,
      pMesh: v14,
      type: MATERIAL_TRIANGLES,
      nVertexCount: nCurrVertexCount,
      nIndexCount: nCurrIndexCount,
      pMeshSettings: nullptr);
    listHead = group->listHead;
    if ( bShadowDepth )
    {
      if ( listHead != -1 )
      {
        do
        {
          v16 = listHead << 6;
          v17 = (char *)v4->m_list.m_Memory.m_pMemory + v16;
          v18 = 0;
          nCurrVertexCount = v16;
          if ( *((int *)v17 + 1) > 0 )
          {
            v19 = (msurface2_t **)(v17 + 8);
            do
            {
              Shader_AddSurfaceDynamicTextureOnly(&meshBuilder, surfID: *v19);
              ++v18;
              ++v19;
            }
            while ( v18 < *((_DWORD *)v17 + 1) );
            v16 = nCurrVertexCount;
            v4 = sortList;
          }
          listHead = *(_WORD *)((char *)&v4->m_list.m_Memory.m_pMemory->nextBlock + v16);
        }
        while ( listHead != -1 );
LABEL_18:
        v14 = pMesh;
      }
    }
    else if ( listHead != -1 )
    {
      do
      {
        v20 = listHead << 6;
        v21 = (char *)v4->m_list.m_Memory.m_pMemory + v20;
        v22 = 0;
        nCurrVertexCount = v20;
        if ( *((int *)v21 + 1) > 0 )
        {
          v23 = (msurface2_t **)(v21 + 8);
          do
          {
            Shader_AddSurfaceDynamic(&meshBuilder, surfID: *v23);
            ++v22;
            ++v23;
          }
          while ( v22 < *((_DWORD *)v21 + 1) );
          v20 = nCurrVertexCount;
          v4 = sortList;
        }
        listHead = *(_WORD *)((char *)&v4->m_list.m_Memory.m_pMemory->nextBlock + v20);
      }
      while ( listHead != -1 );
      goto LABEL_18;
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
    v14->Draw_2(this: v14, a2: -1, a3: 0);
    CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
    return;
  }
  v25 = group->listHead;
  if ( LOWORD(group->listHead) != 0xFFFF )
  {
    while ( 1 )
    {
      v26 = v25 << 6;
      v27 = (IMesh *)((char *)v4->m_list.m_Memory.m_pMemory + v26);
      v28 = 0;
      nCurrVertexCount = v26;
      if ( (int)v27->IIndexBuffer::__vftable > 0 )
      {
        pMesh = v27 + 1;
        do
        {
          Shader_DrawSurfaceDynamic(pRenderContext, surfID: (msurface2_t *)pMesh->IVertexBuffer::__vftable);
          pMesh = (IMesh *)((char *)pMesh + 4);
          ++v28;
        }
        while ( v28 < (int)v27->IIndexBuffer::__vftable );
        v26 = nCurrVertexCount;
      }
      v25 = *(_WORD *)((char *)&sortList->m_list.m_Memory.m_pMemory->nextBlock + v26);
      if ( v25 == -1 )
        break;
      v4 = sortList;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D3870
// Name: void Shader_DrawChainsDynamic(class IMatRenderContext __near *,class CMSurfaceSortList const __near &,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall Shader_DrawChainsDynamic(
        int m_nIndexCount@<edi>,
        CMeshBuilder *p_meshBuilder@<esi>,
        IMatRenderContext *pRenderContext,
        CMSurfaceSortList *sortList,
        int nSortGroup,
        bool bShadowDepth)
{
  CMSurfaceSortList *v6; // ebx
  int v7; // eax
  int v8; // edx
  const CUtlVector<surfacesortgroup_t *,CUtlMemory<surfacesortgroup_t *,int> > *v9; // eax
  int v10; // ecx
  const surfacesortgroup_t *v11; // edi
  msurface2_t *SurfaceAtHead; // eax
  int v13; // eax
  int (__thiscall *GetMaxVerticesToRender)(IMatRenderContext *, IMaterial *); // edx
  int v15; // eax
  int vertexCount; // edx
  IMesh *v17; // esi
  __int16 listHead; // ax
  int v19; // eax
  char *v20; // esi
  int v21; // edi
  msurface2_t **v22; // ebx
  int v23; // eax
  char *v24; // esi
  int v25; // edi
  msurface2_t **v26; // ebx
  int m_nVertexCount; // eax
  __int16 i; // ax
  int v29; // eax
  char *v30; // esi
  int v31; // edi
  msurface2_t **v32; // ebx
  CMeshBuilder meshBuilder; // [esp+4h] [ebp-200h] BYREF
  const CUtlVector<surfacesortgroup_t *,CUtlMemory<surfacesortgroup_t *,int> > *_groupList; // [esp+1ECh] [ebp-18h]
  int _count; // [esp+1F0h] [ebp-14h]
  int v38; // [esp+1F4h] [ebp-10h]
  int nIndexCount; // [esp+1F8h] [ebp-Ch]
  int _listIndex; // [esp+1FCh] [ebp-8h]
  int nVertexCount; // [esp+200h] [ebp-4h]
  IMaterial *nSortGroupc; // [esp+214h] [ebp+10h]
  int nSortGroupa; // [esp+214h] [ebp+10h]
  int nSortGroupb; // [esp+214h] [ebp+10h]

  v6 = sortList;
  v7 = 5 * nSortGroup + 15;
  v8 = *(&sortList->m_list.m_Size + v7);
  v9 = (const CUtlVector<surfacesortgroup_t *,CUtlMemory<surfacesortgroup_t *,int> > *)(&sortList->m_list.m_Memory.m_pMemory
                                                                                      + v7);
  v10 = 0;
  _groupList = v9;
  _count = v8;
  _listIndex = 0;
  if ( v8 > 0 )
  {
    while ( 1 )
    {
      v11 = v9->m_Memory.m_pMemory[v10];
      SurfaceAtHead = CMSurfaceSortList::GetSurfaceAtHead(this: v6, group: v11);
      if ( SurfaceAtHead == nullptr )
        goto LABEL_43;
      nSortGroupc = Shader_SetChainTextureState(
                      pRenderContext,
                      surfID: SurfaceAtHead,
                      pBaseEntity: nullptr,
                      bShadowDepth);
      v13 = pRenderContext->GetMaxIndicesToRender(this: pRenderContext);
      GetMaxVerticesToRender = pRenderContext->GetMaxVerticesToRender;
      v38 = v13;
      v15 = GetMaxVerticesToRender(this: pRenderContext, a2: nSortGroupc);
      vertexCount = v11->vertexCount;
      nIndexCount = 3 * v11->triangleCount;
      nVertexCount = vertexCount;
      if ( nIndexCount < v38 && vertexCount < v15 )
        break;
      for ( i = v11->listHead; i != -1; i = *(_WORD *)((char *)&v6->m_list.m_Memory.m_pMemory->nextBlock + v29) )
      {
        v29 = i << 6;
        v30 = (char *)v6->m_list.m_Memory.m_pMemory + v29;
        v31 = 0;
        nSortGroupb = v29;
        if ( *((int *)v30 + 1) > 0 )
        {
          v32 = (msurface2_t **)(v30 + 8);
          do
          {
            Shader_DrawSurfaceDynamic(pRenderContext, surfID: *v32);
            ++v31;
            ++v32;
          }
          while ( v31 < *((_DWORD *)v30 + 1) );
          v29 = nSortGroupb;
          v6 = sortList;
        }
      }
LABEL_43:
      v10 = _listIndex + 1;
      _listIndex = v10;
      if ( v10 >= _count )
        return;
      v9 = _groupList;
    }
    v17 = (IMesh *)((int (__thiscall *)(IMatRenderContext *, _DWORD, _DWORD, _DWORD, _DWORD, int, CMeshBuilder *))pRenderContext->GetDynamicMesh)(
                     a1: pRenderContext,
                     a2: 0,
                     a3: 0,
                     a4: 0,
                     a5: 0,
                     a6: m_nIndexCount,
                     a7: p_meshBuilder);
    nSortGroupa = (int)v17;
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    CMeshBuilder::Begin(
      this: &meshBuilder,
      pMesh: v17,
      type: MATERIAL_TRIANGLES,
      nVertexCount,
      nIndexCount,
      pMeshSettings: nullptr);
    listHead = v11->listHead;
    if ( bShadowDepth )
    {
      if ( listHead != -1 )
      {
        do
        {
          v19 = listHead << 6;
          v20 = (char *)v6->m_list.m_Memory.m_pMemory + v19;
          v21 = 0;
          nVertexCount = v19;
          if ( *((int *)v20 + 1) > 0 )
          {
            v22 = (msurface2_t **)(v20 + 8);
            do
            {
              Shader_AddSurfaceDynamicTextureOnly(&meshBuilder, surfID: *v22);
              ++v21;
              ++v22;
            }
            while ( v21 < *((_DWORD *)v20 + 1) );
            v19 = nVertexCount;
            v6 = sortList;
          }
          listHead = *(_WORD *)((char *)&v6->m_list.m_Memory.m_pMemory->nextBlock + v19);
        }
        while ( listHead != -1 );
LABEL_21:
        v17 = (IMesh *)nSortGroupa;
      }
    }
    else if ( listHead != -1 )
    {
      do
      {
        v23 = listHead << 6;
        v24 = (char *)v6->m_list.m_Memory.m_pMemory + v23;
        v25 = 0;
        nVertexCount = v23;
        if ( *((int *)v24 + 1) > 0 )
        {
          v26 = (msurface2_t **)(v24 + 8);
          do
          {
            Shader_AddSurfaceDynamic(&meshBuilder, surfID: *v26);
            ++v25;
            ++v26;
          }
          while ( v25 < *((_DWORD *)v24 + 1) );
          v23 = nVertexCount;
          v6 = sortList;
        }
        listHead = *(_WORD *)((char *)&v6->m_list.m_Memory.m_pMemory->nextBlock + v23);
      }
      while ( listHead != -1 );
      goto LABEL_21;
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
    p_meshBuilder = &meshBuilder;
    m_nIndexCount = meshBuilder.m_IndexBuilder.m_nIndexCount;
    ((void (__thiscall *)(IMesh *, int))meshBuilder.m_pMesh->UnlockMesh)(
      a1: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    v17->Draw_2(this: v17, a2: -1, a3: 0);
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
    goto LABEL_43;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D3B70
// Name: Shader_DrawDispChain
// Source: json
//------------------------------------------------------------------------------
void __cdecl Shader_DrawDispChain(
        IMatRenderContext *pRenderContext,
        int nSortGroup,
        const CMSurfaceSortList *list,
        __int16 flags,
        IMaterial *bShadowDepth)
{
  const CMSurfaceSortList *v5; // ebx
  int v6; // edi
  int v7; // esi
  int v8; // eax
  int v9; // edx
  materiallist_t **v10; // eax
  int v11; // ecx
  materiallist_t *v12; // eax
  unsigned int v13; // ecx
  void *v14; // esp
  int v15; // edx
  int v16; // ecx
  int v17; // esi
  __int16 v18; // ax
  int v19; // edx
  char *v20; // eax
  int v21; // ecx
  msurface2_t **v22; // edx
  const CViewSetup *v23; // eax
  msurface2_t *v24[3]; // [esp+0h] [ebp-20h] BYREF
  int _count; // [esp+Ch] [ebp-14h]
  int v26; // [esp+10h] [ebp-10h]
  int _listIndex; // [esp+14h] [ebp-Ch]
  materiallist_t **v28; // [esp+18h] [ebp-8h]
  int count; // [esp+1Ch] [ebp-4h]

  v5 = list;
  v6 = 0;
  v7 = 0;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: &args.m_pArgSBuffer[480],
    a3: 0,
    a4: &args.m_pArgSBuffer[504],
    a5: false,
    a6: 4);
  v8 = 5 * nSortGroup + 15;
  v9 = *(&list->m_list.m_Size + v8);
  v10 = &list->m_list.m_Memory.m_pMemory + v8;
  v11 = 0;
  count = 0;
  v28 = v10;
  if ( v9 >= 2 )
  {
    v12 = *v10;
    v13 = ((unsigned int)(v9 - 2) >> 1) + 1;
    _listIndex = 2 * v13;
    do
    {
      v7 += *(_DWORD *)(v12->nextBlock + 28);
      v6 += *(_DWORD *)(v12->count + 28);
      v12 = (materiallist_t *)((char *)v12 + 8);
      --v13;
    }
    while ( v13 != 0 );
    v11 = _listIndex;
    v5 = list;
    v10 = v28;
  }
  if ( v11 < v9 )
    count = *(_DWORD *)(*(&(*v10)->nextBlock + v11) + 28);
  count += v7 + v6;
  if ( count != 0 )
  {
    v14 = alloca(4 * count);
    v15 = (int)v28[3];
    v16 = 0;
    v17 = 0;
    _count = v15;
    for ( _listIndex = 0; v16 < v15; _listIndex = v16 )
    {
      v18 = **((_WORD **)&(*v28)->nextBlock + v16);
      if ( v18 != -1 )
      {
        do
        {
          v19 = v18 << 6;
          v20 = (char *)v5->m_list.m_Memory.m_pMemory + v19;
          v21 = 0;
          v26 = v19;
          if ( *((int *)v20 + 1) > 0 )
          {
            v22 = (msurface2_t **)(v20 + 8);
            do
            {
              v24[v17] = *v22;
              ++v21;
              ++v17;
              ++v22;
            }
            while ( v21 < *((_DWORD *)v20 + 1) );
            v5 = list;
            v19 = v26;
          }
          v18 = *(_WORD *)((char *)&v5->m_list.m_Memory.m_pMemory->nextBlock + v19);
        }
        while ( v18 != -1 );
        v16 = _listIndex;
        v15 = _count;
      }
      ++v16;
    }
    v23 = g_EngineRenderer->ViewGetCurrent(this: g_EngineRenderer);
    DispInfo_RenderListWorld(
      a1: (int)v5,
      a2: (int)v24,
      pRenderContext,
      nSortGroup,
      pList: v24,
      listCount: count,
      bOrtho: v23->m_bOrtho,
      flags,
      bShadowDepth);
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x100D3CC0
// Name: void Shader_DrawDispChainDecalsAndOverlays(class IMatRenderContext __near *,int,class CMSurfaceSortList const __near &,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Shader_DrawDispChainDecalsAndOverlays(
        IMatRenderContext *pRenderContext,
        int nSortGroup,
        const CMSurfaceSortList *list,
        __int16 flags)
{
  int v4; // edi
  int v5; // esi
  const CMSurfaceSortList *v6; // ebx
  int v7; // eax
  int v8; // ecx
  materiallist_t **v9; // eax
  int v10; // edx
  materiallist_t *v11; // eax
  unsigned int v12; // ecx
  void *v13; // esp
  int v14; // edx
  int v15; // ecx
  int v16; // esi
  __int16 v17; // ax
  int v18; // edx
  char *v19; // eax
  int v20; // ecx
  msurface2_t **v21; // edx
  const CViewSetup *v22; // eax
  msurface2_t *v23[3]; // [esp+0h] [ebp-20h] BYREF
  int _count; // [esp+Ch] [ebp-14h]
  int v25; // [esp+10h] [ebp-10h]
  int _listIndex; // [esp+14h] [ebp-Ch]
  materiallist_t **v27; // [esp+18h] [ebp-8h]
  int count; // [esp+1Ch] [ebp-4h]

  v4 = 0;
  v5 = 0;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: &args.m_pArgSBuffer[480],
    a3: 0,
    a4: &args.m_pArgSBuffer[504],
    a5: false,
    a6: 4);
  v6 = list;
  v7 = 5 * nSortGroup + 15;
  v8 = *(&list->m_list.m_Size + v7);
  v9 = &list->m_list.m_Memory.m_pMemory + v7;
  v10 = 0;
  count = 0;
  v27 = v9;
  if ( v8 >= 2 )
  {
    v11 = *v9;
    v12 = ((unsigned int)(v8 - 2) >> 1) + 1;
    _listIndex = 2 * v12;
    do
    {
      v5 += *(_DWORD *)(v11->nextBlock + 28);
      v4 += *(_DWORD *)(v11->count + 28);
      v11 = (materiallist_t *)((char *)v11 + 8);
      --v12;
    }
    while ( v12 != 0 );
    v9 = v27;
    v10 = _listIndex;
  }
  if ( v10 < (int)v9[3] )
    count = *(_DWORD *)(*(&(*v9)->nextBlock + v10) + 28);
  count += v5 + v4;
  if ( count != 0 )
  {
    v13 = alloca(4 * count);
    v14 = (int)v27[3];
    v15 = 0;
    v16 = 0;
    _count = v14;
    for ( _listIndex = 0; v15 < v14; _listIndex = v15 )
    {
      v17 = **((_WORD **)&(*v27)->nextBlock + v15);
      if ( v17 != -1 )
      {
        do
        {
          v18 = v17 << 6;
          v19 = (char *)v6->m_list.m_Memory.m_pMemory + v18;
          v20 = 0;
          v25 = v18;
          if ( *((int *)v19 + 1) > 0 )
          {
            v21 = (msurface2_t **)(v19 + 8);
            do
            {
              v23[v16] = *v21;
              ++v20;
              ++v16;
              ++v21;
            }
            while ( v20 < *((_DWORD *)v19 + 1) );
            v6 = list;
            v18 = v25;
          }
          v17 = *(_WORD *)((char *)&v6->m_list.m_Memory.m_pMemory->nextBlock + v18);
        }
        while ( v17 != -1 );
        v15 = _listIndex;
        v14 = _count;
      }
      ++v15;
    }
    v22 = g_EngineRenderer->ViewGetCurrent(this: g_EngineRenderer);
    DispInfo_RenderListDecalsAndOverlays(
      pRenderContext,
      nSortGroup,
      pList: v23,
      listCount: count,
      bOrtho: v22->m_bOrtho,
      flags);
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x100D3E10
// Name: Shader_WorldZFill
// Source: json
//------------------------------------------------------------------------------
void __usercall Shader_WorldZFill(
        CWorldRenderList *pRenderList@<eax>,
        IMatRenderContext *pRenderContext,
        unsigned int flags)
{
  int v3; // ebx
  char *v4; // edx
  const CUtlVector<surfacesortgroup_t *,CUtlMemory<surfacesortgroup_t *,int> > *v5; // eax
  int m_Size; // ecx
  const surfacesortgroup_t *v7; // edi
  IMaterial *material; // esi
  unsigned int indexCountNoDetail; // ecx
  int v11; // edi
  int (__thiscall *GetMaxVerticesToRender)(IMatRenderContext *, IMaterial *); // edx
  int v13; // eax
  const CUtlVector<surfacesortgroup_t *,CUtlMemory<surfacesortgroup_t *,int> > *v14; // edx
  int v15; // ecx
  int v16; // esi
  materiallist_t **v17; // ecx
  int v18; // eax
  const surfacesortgroup_t *v19; // esi
  msurface2_t *SurfaceAtHead; // eax
  IMaterial *v21; // edi
  __int16 i; // ax
  int v23; // eax
  const materiallist_t *v24; // ecx
  char *v25; // edi
  unsigned int v26; // eax
  int indexCount; // ebx
  int v28; // esi
  unsigned __int16 firstPrimID; // ax
  int v30; // edx
  mprimitive_t *primitives; // eax
  bool v32; // zf
  mprimitive_t *v33; // eax
  int v34; // edi
  int m_nVertexCount; // eax
  int v36; // eax
  CMeshBuilder meshBuilder; // [esp+Ch] [ebp-234h] BYREF
  msurface2_t *nSurfID; // [esp+1F4h] [ebp-4Ch]
  int v39; // [esp+1F8h] [ebp-48h]
  int v40; // [esp+1FCh] [ebp-44h]
  materiallist_t **v41; // [esp+200h] [ebp-40h]
  int nMaxIndices; // [esp+204h] [ebp-3Ch]
  const materiallist_t *_pList; // [esp+208h] [ebp-38h]
  int nMaxVertices; // [esp+20Ch] [ebp-34h]
  int _index; // [esp+210h] [ebp-30h]
  int nStartVert; // [esp+214h] [ebp-2Ch] BYREF
  int _listIndex; // [esp+218h] [ebp-28h]
  IMesh *pMesh; // [esp+21Ch] [ebp-24h]
  const CUtlVector<surfacesortgroup_t *,CUtlMemory<surfacesortgroup_t *,int> > *_groupList; // [esp+220h] [ebp-20h]
  const CMSurfaceSortList *sortList; // [esp+224h] [ebp-1Ch]
  msurface2_t **pSurfaces; // [esp+228h] [ebp-18h]
  int nIndexCount; // [esp+22Ch] [ebp-14h]
  int v53; // [esp+230h] [ebp-10h]
  int nVertexCount; // [esp+234h] [ebp-Ch]
  int nBatchIndexCount; // [esp+238h] [ebp-8h]
  int nBatchVertexCount; // [esp+23Ch] [ebp-4h]

  v3 = 0;
  v4 = &args.m_pArgSBuffer[188];
  nVertexCount = 0;
  nIndexCount = 0;
  sortList = &pRenderList->m_SortList;
  v53 = 1;
  pSurfaces = (msurface2_t **)&args.m_pArgSBuffer[188];
  do
  {
    if ( (flags & v53) != 0 )
    {
      v5 = &sortList->m_sortGroupLists[*(_DWORD *)v4];
      m_Size = v5->m_Size;
      _groupList = v5;
      _listIndex = m_Size;
      if ( m_Size > 0 )
      {
        while ( 1 )
        {
          v7 = v5->m_Memory.m_pMemory[v3];
          material = host_state.worldbrush->texinfo[*((unsigned __int16 *)CMSurfaceSortList::GetSurfaceAtHead(
                                                                            this: (CMSurfaceSortList *)sortList,
                                                                            group: v7)
                                                    + 11) >> 1].material;
          if ( !material->IsAlphaTested(this: material) && !material->IsTranslucent(this: material) )
          {
            indexCountNoDetail = v7->indexCountNoDetail;
            nVertexCount += v7->vertexCountNoDetail;
            nIndexCount += indexCountNoDetail;
          }
          if ( ++v3 >= _listIndex )
            break;
          v5 = _groupList;
        }
        v4 = (char *)pSurfaces;
        v3 = 0;
      }
    }
    v4 += 4;
    pSurfaces = (msurface2_t **)v4;
    v53 = __ROL4__(v53, 1);
  }
  while ( (int)v4 < (int)&args.m_pArgSBuffer[204] );
  if ( nVertexCount != 0 )
  {
    pRenderContext->Bind(this: pRenderContext, a2: g_pMaterialWriteZ, a3: nullptr);
    pMesh = pRenderContext->GetDynamicMesh(this: pRenderContext, a2: 0, a3: 0, a4: 0, a5: 0);
    v11 = pRenderContext->GetMaxIndicesToRender(this: pRenderContext);
    GetMaxVerticesToRender = pRenderContext->GetMaxVerticesToRender;
    nMaxIndices = v11;
    v13 = GetMaxVerticesToRender(this: pRenderContext, a2: g_pMaterialWriteZ);
    nMaxVertices = v13;
    nBatchIndexCount = nIndexCount;
    if ( nIndexCount >= v11 )
      nBatchIndexCount = v11;
    nBatchVertexCount = nVertexCount;
    if ( nVertexCount >= v13 )
      nBatchVertexCount = v13;
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
    CMeshBuilder::Begin(
      this: &meshBuilder,
      pMesh,
      type: MATERIAL_TRIANGLES,
      nVertexCount: nBatchVertexCount,
      nIndexCount: nBatchIndexCount,
      pMeshSettings: nullptr);
    v14 = (const CUtlVector<surfacesortgroup_t *,CUtlMemory<surfacesortgroup_t *,int> > *)&args.m_pArgSBuffer[188];
    nStartVert = 0;
    v53 = 1;
    _groupList = (const CUtlVector<surfacesortgroup_t *,CUtlMemory<surfacesortgroup_t *,int> > *)&args.m_pArgSBuffer[188];
    do
    {
      if ( (flags & v53) != 0 )
      {
        v15 = 5 * (int)v14->m_Memory.m_pMemory + 15;
        v16 = *(&sortList->m_list.m_Size + v15);
        v17 = &sortList->m_list.m_Memory.m_pMemory + v15;
        v18 = 0;
        v41 = v17;
        v39 = v16;
        _listIndex = 0;
        if ( v16 > 0 )
        {
          while ( 1 )
          {
            v19 = (const surfacesortgroup_t *)*(&(*v17)->nextBlock + v18);
            SurfaceAtHead = CMSurfaceSortList::GetSurfaceAtHead(this: (CMSurfaceSortList *)sortList, group: v19);
            if ( v19->triangleCount != 0 && v19->vertexCount != 0 )
            {
              v21 = host_state.worldbrush->texinfo[*((unsigned __int16 *)SurfaceAtHead + 11) >> 1].material;
              if ( !v21->IsAlphaTested(this: v21) && !v21->IsTranslucent(this: v21) )
              {
                for ( i = v19->listHead;
                      i != -1;
                      i = *(_WORD *)((char *)&sortList->m_list.m_Memory.m_pMemory->nextBlock + v23) )
                {
                  v23 = i << 6;
                  v24 = (materiallist_t *)((char *)sortList->m_list.m_Memory.m_pMemory + v23);
                  v40 = v23;
                  _pList = v24;
                  _index = 0;
                  if ( v24->count > 0 )
                  {
                    pSurfaces = v24->pSurfaces;
                    do
                    {
                      v25 = (char *)*pSurfaces;
                      v26 = (*pSurfaces)->flags;
                      nSurfID = *pSurfaces;
                      if ( (v26 & 2) != 0 && (v26 & 0x10000) == 0 )
                      {
                        indexCount = 0;
                        v28 = 0;
                        if ( (v26 & 0x8000) != 0 )
                        {
                          if ( (v26 & 0x800) != 0 )
                            firstPrimID = 0;
                          else
                            firstPrimID = host_state.worldbrush->surfaces1[(v25
                                                                          - (char *)host_state.worldbrush->surfaces2) >> 5].prims.firstPrimID;
                          v30 = firstPrimID;
                          primitives = host_state.worldbrush->primitives;
                          v32 = primitives[v30].vertCount == 0;
                          v33 = &primitives[v30];
                          if ( v32 )
                          {
                            v28 = (unsigned __int8)v25[3];
                            indexCount = v33->indexCount;
                          }
                        }
                        else
                        {
                          v28 = (unsigned __int8)v25[3];
                          indexCount = 3 * v28 - 6;
                        }
                        v34 = nMaxIndices;
                        if ( v28 > nMaxVertices || indexCount > nMaxIndices )
                        {
                          _Error(a1: &args.m_pArgvBuffer[20], v28, nMaxVertices, indexCount, nMaxIndices);
                        }
                        else
                        {
                          if ( nBatchIndexCount < indexCount || nBatchVertexCount < v28 )
                          {
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
                            nBatchIndexCount = nIndexCount;
                            if ( nIndexCount >= v34 )
                              nBatchIndexCount = v34;
                            nBatchVertexCount = nVertexCount;
                            if ( nVertexCount >= nMaxVertices )
                              nBatchVertexCount = nMaxVertices;
                            pMesh = pRenderContext->GetDynamicMesh(this: pRenderContext, a2: 0, a3: 0, a4: 0, a5: 0);
                            CMeshBuilder::Begin(
                              this: &meshBuilder,
                              pMesh,
                              type: MATERIAL_TRIANGLES,
                              nVertexCount: nBatchVertexCount,
                              nIndexCount: nBatchIndexCount,
                              pMeshSettings: nullptr);
                            nStartVert = 0;
                          }
                          Shader_WorldZFillSurfChain_Single(surfaceHandle: nSurfID, &meshBuilder, &nStartVert);
                          nBatchIndexCount -= indexCount;
                          nBatchVertexCount -= v28;
                          nIndexCount -= indexCount;
                          nVertexCount -= v28;
                        }
                        v24 = _pList;
                      }
                      ++pSurfaces;
                      ++_index;
                    }
                    while ( _index < v24->count );
                    v23 = v40;
                  }
                }
              }
            }
            v18 = _listIndex + 1;
            _listIndex = v18;
            if ( v18 >= v39 )
              break;
            v17 = v41;
          }
          v14 = _groupList;
        }
      }
      v14 = (const CUtlVector<surfacesortgroup_t *,CUtlMemory<surfacesortgroup_t *,int> > *)((char *)v14 + 4);
      _groupList = v14;
      v53 = __ROL4__(v53, 1);
    }
    while ( (int)v14 < (int)&args.m_pArgSBuffer[204] );
    if ( meshBuilder.m_bGenerateIndices )
    {
      switch ( meshBuilder.m_Type )
      {
        case MATERIAL_LINE_STRIP:
          v36 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
          break;
        case MATERIAL_LINE_LOOP:
          v36 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
        case MATERIAL_POLYGON:
          v36 = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
          break;
        case MATERIAL_QUADS:
          v36 = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
          break;
        case MATERIAL_INSTANCED_QUADS:
          v36 = 0;
          break;
        default:
          v36 = meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
      }
      CIndexBuilder::GenerateIndices(
        this: &meshBuilder.m_IndexBuilder,
        primitiveType: meshBuilder.m_Type,
        nIndexCount: v36);
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
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D4420
// Name: void DrawSimpleWorldModel(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __usercall DrawSimpleWorldModel(int a1@<ebx>, int a2@<edi>, int a3@<esi>, __int16 flags)
{
  int v4; // esi
  IOverlayMgr *v5; // eax
  DrawModelInfo_t info; // [esp+0h] [ebp-210h] BYREF
  matrix3x4_t modelToWorld; // [esp+1E0h] [ebp-30h] BYREF

  if ( (flags & 0x1800) != 0
    && ((flags & 0x800) != 0 && g_pSimpleWorldModel != nullptr
     || (flags & 0x1000) != 0 && g_pSimpleWorldModelWater != nullptr) )
  {
    memset(&info.m_Decals, 0, 29);
    info.m_LightingState.m_nLocalLightCount = 0;
    info.m_LightingState.m_vecAmbientCube[0].x = 1.0;
    info.m_LightingState.m_vecAmbientCube[0].y = 1.0;
    info.m_LightingState.m_vecAmbientCube[0].z = 1.0;
    info.m_LightingState.m_vecAmbientCube[1].x = 1.0;
    info.m_LightingState.m_vecAmbientCube[1].y = 1.0;
    info.m_LightingState.m_vecAmbientCube[1].z = 1.0;
    info.m_LightingState.m_vecAmbientCube[2].x = 1.0;
    info.m_LightingState.m_vecAmbientCube[2].y = 1.0;
    info.m_LightingState.m_vecAmbientCube[2].z = 1.0;
    info.m_LightingState.m_vecAmbientCube[3].x = 1.0;
    info.m_LightingState.m_vecAmbientCube[3].y = 1.0;
    info.m_LightingState.m_vecAmbientCube[3].z = 1.0;
    info.m_LightingState.m_vecAmbientCube[4].x = 1.0;
    info.m_LightingState.m_vecAmbientCube[4].y = 1.0;
    info.m_LightingState.m_vecAmbientCube[4].z = 1.0;
    info.m_LightingState.m_vecAmbientCube[5].x = 1.0;
    info.m_LightingState.m_vecAmbientCube[5].y = 1.0;
    info.m_LightingState.m_vecAmbientCube[5].z = 1.0;
    *(_QWORD *)&modelToWorld.m_flMatVal[0][0] = 0x3F80000000000000LL;
    *(_QWORD *)&modelToWorld.m_flMatVal[0][2] = 0;
    *(_QWORD *)&modelToWorld.m_flMatVal[1][0] = 3212836864LL;
    memset(&modelToWorld.m_flMatVal[1][2], 0, 16);
    *(_QWORD *)&modelToWorld.m_flMatVal[2][2] = 1065353216;
    v4 = ((int (__thiscall *)(IMaterialSystem *, int, int, int))materials->GetRenderContext)(
           a1: materials,
           a2: a3,
           a3: a2,
           a4: a1);
    if ( v4 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 8))(a1: v4);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v4 + 80))(a1: v4, a2: 0);
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 84))(a1: v4);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 80))(a1: v4, a2: 10);
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 84))(a1: v4);
    g_pShadowMgr->PushSinglePassFlashlightStateEnabled(this: g_pShadowMgr, a2: true);
    if ( (flags & 0x800) != 0 && g_pSimpleWorldModel != nullptr )
    {
      info.m_pStudioHdr = (studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: g_pSimpleWorldModel->studio);
      info.m_pHardwareData = (studiohwdata_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetHardwareData)(a1: g_pSimpleWorldModel->studio);
      g_pStudioRender->DrawModelStaticProp(this: g_pStudioRender, a2: &info, a3: &modelToWorld, a4: 0);
    }
    if ( (flags & 0x1000) != 0 && g_pSimpleWorldModelWater != nullptr )
    {
      info.m_pStudioHdr = (studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: g_pSimpleWorldModelWater->studio);
      info.m_pHardwareData = (studiohwdata_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetHardwareData)(a1: g_pSimpleWorldModelWater->studio);
      g_pStudioRender->DrawModelStaticProp(this: g_pStudioRender, a2: &info, a3: &modelToWorld, a4: 0);
    }
    g_pShadowMgr->PopSinglePassFlashlightStateEnabled(this: g_pShadowMgr);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v4 + 80))(a1: v4, a2: 0);
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 88))(a1: v4);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 80))(a1: v4, a2: 10);
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 88))(a1: v4);
    v5 = OverlayMgr();
    ((void (__thiscall *)(IOverlayMgr *))v5->RenderAllUnlitOverlays)(a1: v5);
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 12))(a1: v4);
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 4))(a1: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D4700
// Name: void R_SetFogVolumeState(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_SetFogVolumeState(int fogVolume, bool useHeightFog)
{
  IMaterial *FogVolumeMaterial; // esi
  float *v3; // edi
  int v4; // ebx
  IMatRenderContext *v5; // esi
  void (__thiscall *FogMode)(IMatRenderContext *, MaterialFogMode_t); // edx
  void (__thiscall *FogColor3fv)(IMatRenderContext *, const float *); // edx
  float fogColor[3]; // [esp+54h] [ebp-14h] BYREF
  IMaterialVar *pFogEndVar; // [esp+60h] [ebp-8h]
  IMaterialVar *pFogStartVar; // [esp+64h] [ebp-4h]
  mleafwaterdata_t *pLeafWaterData; // [esp+70h] [ebp+8h]

  FogVolumeMaterial = R_GetFogVolumeMaterial(nFogVolume: fogVolume, bEyeInFogVolume: !useHeightFog);
  pLeafWaterData = &host_state.worldbrush->leafwaterdata[fogVolume];
  v3 = (float *)FogVolumeMaterial->FindVar(this: FogVolumeMaterial, a2: &args.m_pArgSBuffer[368], a3: nullptr, a4: true);
  v4 = (int)FogVolumeMaterial->FindVar(this: FogVolumeMaterial, a2: &args.m_pArgSBuffer[356], a3: nullptr, a4: true);
  pFogStartVar = FogVolumeMaterial->FindVar(
                   this: FogVolumeMaterial,
                   a2: &args.m_pArgSBuffer[344],
                   a3: nullptr,
                   a4: true);
  pFogEndVar = FogVolumeMaterial->FindVar(this: FogVolumeMaterial, a2: &args.m_pArgSBuffer[336], a3: nullptr, a4: true);
  v5 = materials->GetRenderContext(this: materials);
  if ( v5 != nullptr )
    v5->BeginRender(this: v5);
  if ( *(_DWORD *)(v4 + 8) != 0
    && fog_enable_water_fog.m_pParent != nullptr
    && fog_enable_water_fog.m_pParent->m_Value.m_nValue != 0 )
  {
    ((void (__thiscall *)(IMatRenderContext *, _DWORD))v5->SetFogZ)(a1: v5, a2: pLeafWaterData->surfaceZ);
    FogMode = v5->FogMode;
    if ( useHeightFog )
      ((void (__stdcall *)(int))FogMode)(a1: 2);
    else
      ((void (__stdcall *)(int))FogMode)(a1: 1);
    FogColor3fv = v5->FogColor3fv;
    fogColor[0] = v3[3];
    fogColor[1] = v3[4];
    fogColor[2] = v3[5];
    FogColor3fv(this: v5, a2: fogColor);
    v5->FogStart(this: v5, a2: pFogStartVar->m_VecVal.x);
    v5->FogEnd(this: v5, a2: pFogEndVar->m_VecVal.x);
    ((void (__thiscall *)(IMatRenderContext *, _DWORD))v5->FogMaxDensity)(a1: v5, a2: 1.0);
  }
  else
  {
    v5->FogMode(this: v5, a2: MATERIAL_FOG_NONE);
  }
  v5->EndRender(this: v5);
  v5->Release(this: v5);
}

//------------------------------------------------------------------------------
// Address: 0x100D4890
// Name: void Shader_DrawLightmapPageSurface(struct msurface2_t __near *,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Shader_DrawLightmapPageSurface(msurface2_t *surfID)
{
  IMatRenderContext *v1; // eax
  IMatRenderContext *m_pObject; // esi
  IMesh *v3; // esi
  int flags_high; // eax
  int v5; // edi
  void (__thiscall *SetPrimitiveType)(IMesh *, MaterialPrimitiveType_t); // eax
  int m_nVertexCount; // edx
  float *m_pPosition; // eax
  int v9; // esi
  float *p_x; // edi
  float v11; // xmm0_4
  int v12; // ecx
  float v13; // xmm0_4
  float *m_pCurrPosition; // eax
  int v15; // eax
  Vector2D lightCoords[32][4]; // [esp+Ch] [ebp-608h] BYREF
  CMeshBuilder meshBuilder; // [esp+40Ch] [ebp-208h] BYREF
  int v18; // [esp+5F4h] [ebp-20h]
  int count; // [esp+5F8h] [ebp-1Ch]
  IMesh *pMesh; // [esp+5FCh] [ebp-18h]
  int lightmapPageHeight; // [esp+600h] [ebp-14h] BYREF
  int lightmapPageWidth; // [esp+604h] [ebp-10h] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+608h] [ebp-Ch]
  Vector2D *v24; // [esp+60Ch] [ebp-8h]
  int bumpID; // [esp+610h] [ebp-4h]

  count = (surfID->flags & 8) != 0 ? 4 : 1;
  BuildMSurfaceVerts(pBrushData: host_state.worldbrush, surfID, verts: nullptr, texCoords: nullptr, lightCoords);
  v1 = materials->GetRenderContext(this: materials);
  m_pObject = v1;
  pRenderContext.m_pObject = v1;
  if ( v1 != nullptr )
    v1->BeginRender(this: v1);
  m_pObject->Bind(this: m_pObject, a2: g_materialWireframe, a3: nullptr);
  materials->GetLightmapPageSize(
    this: materials,
    a2: materialSortInfoArray[surfID->materialSortID].lightmapPageID,
    a3: &lightmapPageWidth,
    a4: &lightmapPageHeight);
  bumpID = 0;
  v24 = lightCoords[0];
  do
  {
    v3 = m_pObject->GetDynamicMesh(this: m_pObject, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nBufferOffset = -1;
    meshBuilder.m_VertexBuilder.m_nBufferOffset = -1;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    flags_high = HIBYTE(surfID->flags);
    memset(&meshBuilder.m_IndexBuilder.m_pIndexBuffer, 0, 12);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    meshBuilder.m_IndexBuilder.m_nTotalIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_nBufferFirstIndex = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = 0;
    memset(&meshBuilder.m_VertexBuilder.m_nMaxVertexCount, 0, 12);
    meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
    meshBuilder.m_pMesh = v3;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_LINES;
    v5 = 2 * flags_high;
    SetPrimitiveType = v3->SetPrimitiveType;
    pMesh = v3;
    v18 = v5;
    SetPrimitiveType(this: v3, a2: MATERIAL_LINES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: v5, a3: v5, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v3->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = v5;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = v3;
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    meshBuilder.m_VertexBuilder.VertexDesc_t = meshBuilder.VertexDesc_t;
    meshBuilder.m_VertexBuilder.m_NumBoneWeights = meshBuilder.m_NumBoneWeights != 0 ? 2 : 0;
    m_nVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = v18;
    meshBuilder.m_VertexBuilder.m_nVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_bModify = false;
    if ( meshBuilder.m_VertexBuilder.m_nBufferOffset == -1 )
    {
      meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
      meshBuilder.m_VertexBuilder.m_nBufferOffset = meshBuilder.MeshDesc_t::VertexDesc_t::m_nOffset;
      meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = meshBuilder.m_nFirstVertex;
    }
    meshBuilder.m_VertexBuilder.m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pNormal;
    qmemcpy(
      meshBuilder.m_VertexBuilder.m_pCurrTexCoord,
      meshBuilder.m_VertexBuilder.m_pTexCoord,
      sizeof(meshBuilder.m_VertexBuilder.m_pCurrTexCoord));
    m_pPosition = meshBuilder.m_VertexBuilder.m_pPosition;
    meshBuilder.m_VertexBuilder.m_pCurrColor = meshBuilder.m_VertexBuilder.m_pColor;
    v9 = 0;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = 0;
    meshBuilder.m_VertexBuilder.m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pPosition;
    if ( HIBYTE(surfID->flags) != 0 )
    {
      p_x = &v24->x;
      while ( 1 )
      {
        v11 = (float)lightmapPageHeight * p_x[1];
        *m_pPosition = (float)lightmapPageWidth * *p_x;
        m_pPosition[1] = v11;
        m_pPosition[2] = 0.0;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        v12 = bumpID + 4 * (++v9 % HIBYTE(surfID->flags));
        v13 = (float)lightmapPageHeight * lightCoords[0][v12].y;
        m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)lightmapPageWidth * lightCoords[0][v12].x;
        m_pCurrPosition[1] = v13;
        m_pCurrPosition[2] = 0.0;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        p_x += 8;
        if ( v9 >= HIBYTE(surfID->flags) )
          break;
        m_pPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      }
      m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
    }
    if ( meshBuilder.m_bGenerateIndices )
    {
      switch ( meshBuilder.m_Type )
      {
        case MATERIAL_LINE_STRIP:
          v15 = 2 * m_nVertexCount - 2;
          break;
        case MATERIAL_LINE_LOOP:
          v15 = 2 * m_nVertexCount;
          break;
        case MATERIAL_POLYGON:
          v15 = 3 * m_nVertexCount - 6;
          break;
        case MATERIAL_QUADS:
          v15 = 6 * m_nVertexCount / 4;
          break;
        case MATERIAL_INSTANCED_QUADS:
          v15 = 0;
          break;
        default:
          v15 = m_nVertexCount;
          break;
      }
      CIndexBuilder::GenerateIndices(
        this: &meshBuilder.m_IndexBuilder,
        primitiveType: meshBuilder.m_Type,
        nIndexCount: v15);
      m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
    }
    meshBuilder.m_pMesh->UnlockMesh(
      this: meshBuilder.m_pMesh,
      a2: m_nVertexCount,
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
    ++v24;
    m_pObject = pRenderContext.m_pObject;
    ++bumpID;
  }
  while ( bumpID < count );
  pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x100D4CE0
// Name: void Shader_DrawLightmapPageChains(class IWorldRenderList __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Shader_DrawLightmapPageChains(IWorldRenderList *pRenderListIn, int pageId)
{
  IWorldRenderList *v2; // ebx
  IWorldRenderList *v3; // ecx
  CMSurfaceSortList *v4; // esi
  const surfacesortgroup_t *v5; // edi
  __int16 i; // ax
  int v7; // eax
  char *v8; // esi
  int v9; // edi
  msurface2_t **v10; // ebx
  IWorldRenderList_vtbl *v11; // esi
  int v12; // edx
  __int16 v13; // ax
  int v14; // eax
  char *v15; // esi
  int v16; // edi
  char *v17; // ebx
  bool v18; // zf
  int _count; // [esp+18h] [ebp-14h]
  int _counta; // [esp+18h] [ebp-14h]
  int v21; // [esp+1Ch] [ebp-10h]
  IWorldRenderList_vtbl *v22; // [esp+1Ch] [ebp-10h]
  int v23; // [esp+20h] [ebp-Ch]
  int _listIndex; // [esp+24h] [ebp-8h]
  int _listIndexa; // [esp+24h] [ebp-8h]
  IWorldRenderList *v26; // [esp+28h] [ebp-4h]

  v2 = pRenderListIn;
  v3 = pRenderListIn + 69;
  v26 = pRenderListIn + 69;
  v23 = 4;
  do
  {
    _count = (int)v3[-48].__vftable;
    _listIndex = 0;
    if ( _count > 0 )
    {
      v4 = (CMSurfaceSortList *)&v2[3];
      do
      {
        v5 = *((const surfacesortgroup_t **)&v3[-51].AddRef + _listIndex);
        if ( materialSortInfoArray[CMSurfaceSortList::GetSurfaceAtHead(this: v4, group: v5)->materialSortID].lightmapPageID == pageId )
        {
          for ( i = v5->listHead; i != -1; v4 = (CMSurfaceSortList *)&v2[3] )
          {
            v7 = i << 6;
            v8 = (char *)v4->m_list.m_Memory.m_pMemory + v7;
            v9 = 0;
            v21 = v7;
            if ( *((int *)v8 + 1) > 0 )
            {
              v10 = (msurface2_t **)(v8 + 8);
              do
              {
                Shader_DrawLightmapPageSurface(surfID: *v10);
                ++v9;
                ++v10;
              }
              while ( v9 < *((_DWORD *)v8 + 1) );
              v2 = pRenderListIn;
              v7 = v21;
            }
            i = *(_WORD *)((char *)&v2[3].AddRef + v7);
          }
        }
        v3 = v26;
        ++_listIndex;
      }
      while ( _listIndex < _count );
    }
    v11 = v3->__vftable;
    v12 = 0;
    v22 = v3->__vftable;
    for ( _listIndexa = 0; v12 < (int)v11; _listIndexa = v12 )
    {
      v13 = **((_WORD **)&v3[-3].AddRef + v12);
      if ( v13 != -1 )
      {
        do
        {
          v14 = v13 << 6;
          v15 = (char *)v2[51].__vftable + v14;
          v16 = 0;
          _counta = v14;
          if ( *((int *)v15 + 1) > 0 )
          {
            v17 = v15 + 8;
            do
            {
              (*(void (__thiscall **)(_DWORD, int))(**(_DWORD **)(*(_DWORD *)v17 + 24) + 8))(
                a1: *(_DWORD *)(*(_DWORD *)v17 + 24),
                a2: pageId);
              ++v16;
              v17 += 4;
            }
            while ( v16 < *((_DWORD *)v15 + 1) );
            v14 = _counta;
            v2 = pRenderListIn;
          }
          v13 = *(_WORD *)((char *)&v2[51].AddRef + v14);
        }
        while ( v13 != -1 );
        v3 = v26;
        v11 = v22;
        v12 = _listIndexa;
      }
      ++v12;
    }
    v3 += 5;
    v18 = v23-- == 1;
    v26 = v3;
  }
  while ( !v18 );
}

//------------------------------------------------------------------------------
// Address: 0x100D4E50
// Name: public: CBrushModelTransform::~CBrushModelTransform(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBrushModelTransform::~CBrushModelTransform(CBrushModelTransform *this@<ecx>, int a2@<esi>)
{
  int v3; // esi

  if ( !this->m_bIdentity )
  {
    v3 = ((int (__thiscall *)(IMaterialSystem *, int))materials->GetRenderContext)(a1: materials, a2);
    if ( v3 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 8))(a1: v3);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v3 + 80))(a1: v3, a2: 10);
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 88))(a1: v3);
    MatrixSetIdentity(dst: &g_BrushToWorldMatrix);
    modelorg = this->m_savedModelorg;
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 12))(a1: v3);
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 4))(a1: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D4EE0
// Name: void DrawDebugInformation(class IMatRenderContext __near *,class matrix3x4a_t const __near &,struct msurface2_t __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawDebugInformation(
        IMatRenderContext *pRenderContext,
        const matrix3x4a_t *brushToWorld,
        msurface2_t **pList,
        int listCount)
{
  CBrushModelTransform transform; // [esp+4h] [ebp-10h] BYREF

  CBrushModelTransform::CBrushModelTransform(this: &transform, matrix: brushToWorld, pRenderContext);
  DrawDebugInformation(pRenderContext, pList, listCount);
  CBrushModelTransform::~CBrushModelTransform(this: &transform, a2: (int)pRenderContext);
}

//------------------------------------------------------------------------------
// Address: 0x100D4F20
// Name: void R_DrawBrushModelShadow(class IClientRenderable __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_DrawBrushModelShadow(IClientRenderable *pRenderable)
{
  model_t *v2; // ebx
  IMatRenderContext *v3; // edi
  CBrushModelTransform brushTransform; // [esp+0h] [ebp-18h] BYREF
  const Vector *origin; // [esp+10h] [ebp-8h]
  const QAngle *angles; // [esp+14h] [ebp-4h]

  if ( r_drawbrushmodels.m_pParent != nullptr && r_drawbrushmodels.m_pParent->m_Value.m_nValue != 0 )
  {
    v2 = (model_t *)pRenderable->GetModel(this: pRenderable);
    origin = pRenderable->GetRenderOrigin(this: pRenderable);
    angles = pRenderable->GetRenderAngles(this: pRenderable);
    v3 = materials->GetRenderContext(this: materials);
    if ( v3 != nullptr )
      v3->BeginRender(this: v3);
    CBrushModelTransform::CBrushModelTransform(this: &brushTransform, origin, angles, pRenderContext: v3);
    CBrushBatchRender::DrawBrushModelShadow(
      this: &g_BrushBatchRenderer,
      a2: (int)v3,
      a3: (int)pRenderable,
      pRenderContext: v3,
      model: v2,
      pRenderable);
    CBrushModelTransform::~CBrushModelTransform(this: &brushTransform, a2: (int)pRenderable);
    if ( v3 != nullptr )
    {
      v3->EndRender(this: v3);
      v3->Release(this: v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D4FD0
// Name: public: void CObjectPool<class CWorldRenderList,0,1>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CObjectPool<CWorldRenderList,0,1>::Purge(CObjectPool<CWorldRenderList,0,1> *this)
{
  TSLNodeBase_t *Next; // esi
  int DepthAndSequence; // eax
  int v4; // ebx

  while ( 1 )
  {
    Next = this->m_AvailableObjects.m_Head.value.Next;
    DepthAndSequence = this->m_AvailableObjects.m_Head.value32.DepthAndSequence;
    if ( this->m_AvailableObjects.m_Head.value.Next == nullptr )
      break;
    while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                               a1: this,
                               a2: Next->Next,
                               a3: DepthAndSequence - 1,
                               a4: Next,
                               a5: DepthAndSequence) == 0 )
    {
      _mm_pause();
      Next = this->m_AvailableObjects.m_Head.value.Next;
      DepthAndSequence = this->m_AvailableObjects.m_Head.value32.DepthAndSequence;
      if ( this->m_AvailableObjects.m_Head.value.Next == nullptr )
        return;
    }
    if ( Next == nullptr )
      break;
    v4 = *((_DWORD *)&Next->Next + 1);
    free(pMem: Next);
    if ( v4 != 0 )
      (**(void (__thiscall ***)(int, int))(v4 + 4))(a1: v4 + 4, a2: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D5030
// Name: void Shader_TranslucentWorldSurface(class CWorldRenderList __near *,struct msurface2_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Shader_TranslucentWorldSurface(CWorldRenderList *pRenderList, msurface2_t *surfID)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  unsigned int v4; // ebx
  msurface2_t **m_pMemory; // ecx
  int v6; // eax
  msurface2_t **v7; // edi
  int v8; // edi
  int v9; // eax
  CUtlMemory<S3RGBA,int> *v10; // esi
  S3RGBA *v11; // ecx
  int v12; // eax
  S3RGBA *v13; // edi

  m_nAllocationCount = pRenderList->m_AlphaSurfaces.m_Memory.m_nAllocationCount;
  m_Size = pRenderList->m_AlphaSurfaces.m_Size;
  v4 = (surfID->flags >> 22) & 3;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<INetMessage *,int>::Grow(
      this: (CUtlMemory<S3RGBA,int> *)&pRenderList->m_AlphaSurfaces,
      num: m_Size - m_nAllocationCount + 1);
  ++pRenderList->m_AlphaSurfaces.m_Size;
  m_pMemory = pRenderList->m_AlphaSurfaces.m_Memory.m_pMemory;
  v6 = pRenderList->m_AlphaSurfaces.m_Size - m_Size - 1;
  pRenderList->m_AlphaSurfaces.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &pRenderList->m_AlphaSurfaces.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = surfID;
  if ( (surfID->flags & 0x80400) != 0 )
  {
    v8 = pRenderList->m_DlightSurfaces[v4].m_Size;
    v9 = pRenderList->m_DlightSurfaces[v4].m_Memory.m_nAllocationCount;
    v10 = (CUtlMemory<S3RGBA,int> *)&pRenderList->m_DlightSurfaces[v4];
    if ( v8 + 1 > v9 )
      CUtlMemory<INetMessage *,int>::Grow(this: v10, num: v8 - v9 + 1);
    ++pRenderList->m_DlightSurfaces[v4].m_Size;
    v11 = v10->m_pMemory;
    v12 = pRenderList->m_DlightSurfaces[v4].m_Size - v8 - 1;
    pRenderList->m_DlightSurfaces[v4].m_pElements = pRenderList->m_DlightSurfaces[v4].m_Memory.m_pMemory;
    if ( v12 > 0 )
      _V_memmove(dest: &v11[v8 + 1], src: &v11[v8], count: 4 * v12);
    v13 = &v10->m_pMemory[v8];
    if ( v13 != nullptr )
      *v13 = (S3RGBA)surfID;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D5130
// Name: Shader_WorldSurface
// Source: json
//------------------------------------------------------------------------------
void __cdecl Shader_WorldSurface(CWorldRenderList *pRenderList, msurface2_t *surfID)
{
  msurface2_t *v2; // esi
  unsigned int v3; // ebx
  int m_Size; // edi
  CUtlVector<msurface2_t *,CUtlMemory<msurface2_t *,int> > *v5; // esi
  int m_nAllocationCount; // eax
  msurface2_t **m_pMemory; // ecx
  int v8; // eax
  msurface2_t **v9; // edi
  int v10; // edi
  CUtlVector<msurface2_t *,CUtlMemory<msurface2_t *,int> > *v11; // esi
  int v12; // eax
  msurface2_t **v13; // ecx
  int v14; // eax
  msurface2_t **v15; // edi
  int nMaterialSortID; // [esp+Ch] [ebp-4h]

  v2 = surfID;
  v3 = (surfID->flags >> 22) & 3;
  if ( surfID->decals != 0xFFFF )
    DecalSurfaceAdd(surfID, iGroup: (surfID->flags >> 22) & 3);
  nMaterialSortID = surfID->materialSortID;
  if ( (surfID->flags & 0x80400) != 0 )
  {
    m_Size = pRenderList->m_DlightSurfaces[v3].m_Size;
    v5 = &pRenderList->m_DlightSurfaces[v3];
    m_nAllocationCount = pRenderList->m_DlightSurfaces[v3].m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<INetMessage *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&pRenderList->m_DlightSurfaces[v3],
        num: m_Size - m_nAllocationCount + 1);
    ++pRenderList->m_DlightSurfaces[v3].m_Size;
    m_pMemory = v5->m_Memory.m_pMemory;
    v8 = pRenderList->m_DlightSurfaces[v3].m_Size - m_Size - 1;
    pRenderList->m_DlightSurfaces[v3].m_pElements = pRenderList->m_DlightSurfaces[v3].m_Memory.m_pMemory;
    if ( v8 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
    v9 = &v5->m_Memory.m_pMemory[m_Size];
    if ( v9 != nullptr )
      *v9 = surfID;
    v2 = surfID;
  }
  if ( (v2->flags & 0x200000) != 0 )
  {
    v10 = pRenderList->m_PaintedSurfaces[v3].m_Size;
    v11 = &pRenderList->m_PaintedSurfaces[v3];
    v12 = pRenderList->m_PaintedSurfaces[v3].m_Memory.m_nAllocationCount;
    if ( v10 + 1 > v12 )
      CUtlMemory<INetMessage *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&pRenderList->m_PaintedSurfaces[v3],
        num: v10 - v12 + 1);
    ++pRenderList->m_PaintedSurfaces[v3].m_Size;
    v13 = v11->m_Memory.m_pMemory;
    v14 = pRenderList->m_PaintedSurfaces[v3].m_Size - v10 - 1;
    pRenderList->m_PaintedSurfaces[v3].m_pElements = pRenderList->m_PaintedSurfaces[v3].m_Memory.m_pMemory;
    if ( v14 > 0 )
      _V_memmove(dest: &v13[v10 + 1], src: &v13[v10], count: 4 * v14);
    v15 = &v11->m_Memory.m_pMemory[v10];
    if ( v15 != nullptr )
      *v15 = surfID;
    v2 = surfID;
  }
  CMSurfaceSortList::AddSurfaceToTail(
    this: &pRenderList->m_SortList,
    pSurface: v2,
    sortGroup: v3,
    sortID: nMaterialSortID);
}

//------------------------------------------------------------------------------
// Address: 0x100D5260
// Name: void Shader_TranslucentDisplacementSurface(class CWorldRenderList __near *,struct msurface2_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Shader_TranslucentDisplacementSurface(CWorldRenderList *pRenderList, msurface2_t *surfID)
{
  unsigned int flags; // eax
  int v3; // ecx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlVector<msurface2_t *,CUtlMemory<msurface2_t *,int> > *v6; // esi
  msurface2_t **m_pMemory; // ecx
  int v8; // eax
  msurface2_t **v9; // eax
  int v10; // edi
  int v11; // eax
  msurface2_t **v12; // ecx
  int v13; // eax
  msurface2_t **v14; // eax

  flags = surfID->flags;
  if ( (surfID->flags & 0x80400) != 0 )
  {
    v3 = (flags >> 22) & 3;
    m_Size = pRenderList->m_DlightSurfaces[(flags >> 22) & 3].m_Size;
    m_nAllocationCount = pRenderList->m_DlightSurfaces[(flags >> 22) & 3].m_Memory.m_nAllocationCount;
    v6 = &pRenderList->m_DlightSurfaces[v3];
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<INetMessage *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&pRenderList->m_DlightSurfaces[v3],
        num: m_Size - m_nAllocationCount + 1);
    ++v6->m_Size;
    m_pMemory = v6->m_Memory.m_pMemory;
    v8 = v6->m_Size - m_Size - 1;
    v6->m_pElements = v6->m_Memory.m_pMemory;
    if ( v8 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
    v9 = &v6->m_Memory.m_pMemory[m_Size];
    if ( v9 != nullptr )
      *v9 = surfID;
  }
  v10 = pRenderList->m_AlphaSurfaces.m_Size;
  v11 = pRenderList->m_AlphaSurfaces.m_Memory.m_nAllocationCount;
  if ( v10 + 1 > v11 )
    CUtlMemory<INetMessage *,int>::Grow(
      this: (CUtlMemory<S3RGBA,int> *)&pRenderList->m_AlphaSurfaces,
      num: v10 - v11 + 1);
  ++pRenderList->m_AlphaSurfaces.m_Size;
  v12 = pRenderList->m_AlphaSurfaces.m_Memory.m_pMemory;
  v13 = pRenderList->m_AlphaSurfaces.m_Size - v10 - 1;
  pRenderList->m_AlphaSurfaces.m_pElements = v12;
  if ( v13 > 0 )
    _V_memmove(dest: &v12[v10 + 1], src: &v12[v10], count: 4 * v13);
  v14 = &pRenderList->m_AlphaSurfaces.m_Memory.m_pMemory[v10];
  if ( v14 != nullptr )
    *v14 = surfID;
}

//------------------------------------------------------------------------------
// Address: 0x100D5360
// Name: Shader_DisplacementSurface
// Source: json
//------------------------------------------------------------------------------
void __cdecl Shader_DisplacementSurface(CWorldRenderList *pRenderList, msurface2_t *surfID)
{
  msurface2_t *v2; // edx
  unsigned int v3; // ebx
  CUtlVector<msurface2_t *,CUtlMemory<msurface2_t *,int> > *v4; // esi
  int m_nAllocationCount; // eax
  int m_Size; // edi
  msurface2_t **m_pMemory; // ecx
  int v8; // eax
  msurface2_t **v9; // edi
  int nMaterialSortID; // [esp+4h] [ebp-4h]

  v2 = surfID;
  v3 = (surfID->flags >> 22) & 3;
  nMaterialSortID = surfID->materialSortID;
  if ( (surfID->flags & 0x80400) != 0 )
  {
    v4 = &pRenderList->m_DlightSurfaces[v3];
    m_nAllocationCount = pRenderList->m_DlightSurfaces[v3].m_Memory.m_nAllocationCount;
    m_Size = pRenderList->m_DlightSurfaces[v3].m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
    {
      CUtlMemory<INetMessage *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&pRenderList->m_DlightSurfaces[v3],
        num: m_Size - m_nAllocationCount + 1);
      v2 = surfID;
    }
    ++pRenderList->m_DlightSurfaces[v3].m_Size;
    m_pMemory = v4->m_Memory.m_pMemory;
    v8 = pRenderList->m_DlightSurfaces[v3].m_Size - m_Size - 1;
    pRenderList->m_DlightSurfaces[v3].m_pElements = pRenderList->m_DlightSurfaces[v3].m_Memory.m_pMemory;
    if ( v8 > 0 )
    {
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
      v2 = surfID;
    }
    v9 = &v4->m_Memory.m_pMemory[m_Size];
    if ( v9 != nullptr )
      *v9 = v2;
  }
  CMSurfaceSortList::AddSurfaceToTail(
    this: &pRenderList->m_DispSortList,
    pSurface: v2,
    sortGroup: v3,
    sortID: nMaterialSortID);
}

//------------------------------------------------------------------------------
// Address: 0x100D5400
// Name: AddProjectedTextureDecalsToList
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddProjectedTextureDecalsToList(CWorldRenderList *pRenderList, int nSortGroup)
{
  CWorldRenderList *v2; // ecx
  int v3; // edi
  int v4; // eax
  int v5; // ebx
  const CUtlVector<surfacesortgroup_t *,CUtlMemory<surfacesortgroup_t *,int> > *v6; // esi
  int v7; // edx
  __int16 listHead; // ax
  int v9; // eax
  const materiallist_t *v10; // esi
  msurface2_t *v11; // ebx
  int v12; // eax
  int m_Size; // edi
  CUtlMemory<wchar_t,int> *v14; // esi
  int m_nAllocationCount; // eax
  wchar_t *m_pMemory; // ecx
  int v17; // eax
  wchar_t *v18; // ecx
  wchar_t *v19; // eax
  IOverlayMgr *v20; // eax
  const CUtlVector<surfacesortgroup_t *,CUtlMemory<surfacesortgroup_t *,int> > *_groupList; // [esp+Ch] [ebp-1Ch]
  int _count; // [esp+10h] [ebp-18h]
  int v23; // [esp+14h] [ebp-14h]
  int _listIndex; // [esp+18h] [ebp-10h]
  int _index; // [esp+1Ch] [ebp-Ch]
  const materiallist_t *_pList; // [esp+20h] [ebp-8h]
  msurface2_t **pSurfaces; // [esp+24h] [ebp-4h]

  v2 = pRenderList;
  v3 = nSortGroup;
  v4 = 5 * nSortGroup + 15;
  v5 = *(&pRenderList->m_SortList.m_list.m_Size + v4);
  v6 = (const CUtlVector<surfacesortgroup_t *,CUtlMemory<surfacesortgroup_t *,int> > *)(&pRenderList->m_SortList.m_list.m_Memory.m_pMemory
                                                                                      + v4);
  v7 = 0;
  _groupList = v6;
  _count = v5;
  for ( _listIndex = 0; v7 < v5; _listIndex = v7 )
  {
    listHead = v6->m_Memory.m_pMemory[v7]->listHead;
    if ( listHead != -1 )
    {
      do
      {
        v9 = listHead << 6;
        v10 = (materiallist_t *)((char *)v2->m_SortList.m_list.m_Memory.m_pMemory + v9);
        v23 = v9;
        _pList = v10;
        _index = 0;
        if ( v10->count > 0 )
        {
          pSurfaces = v10->pSurfaces;
          do
          {
            v11 = *pSurfaces;
            if ( (*pSurfaces)->m_ShadowDecals != 0xFFFF && (v11->flags & 0x2000) == 0 )
            {
              v12 = v3;
              m_Size = v2->m_ShadowHandles[v3].m_Size;
              v14 = (CUtlMemory<wchar_t,int> *)&v2->m_ShadowHandles[v12];
              m_nAllocationCount = v2->m_ShadowHandles[v12].m_Memory.m_nAllocationCount;
              if ( m_Size + 1 > m_nAllocationCount )
                CUtlMemory<wchar_t,int>::Grow(this: v14, num: m_Size - m_nAllocationCount + 1);
              ++v14[1].m_pMemory;
              m_pMemory = v14->m_pMemory;
              v17 = (int)v14[1].m_pMemory - m_Size - 1;
              v14[1].m_nAllocationCount = (int)v14->m_pMemory;
              if ( v17 > 0 )
                _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 2 * v17);
              v18 = v14->m_pMemory;
              v10 = _pList;
              v19 = &v18[m_Size];
              v3 = nSortGroup;
              if ( v19 != nullptr )
                *v19 = v11->m_ShadowDecals;
            }
            if ( v11->m_nFirstOverlayFragment != 0xFFFF )
            {
              v20 = OverlayMgr();
              v20->AddFragmentListToRenderList(this: v20, a2: v3, a3: v11->m_nFirstOverlayFragment, a4: false);
            }
            ++pSurfaces;
            v2 = pRenderList;
            ++_index;
          }
          while ( _index < v10->count );
          v9 = v23;
        }
        listHead = *(_WORD *)((char *)&v2->m_SortList.m_list.m_Memory.m_pMemory->nextBlock + v9);
      }
      while ( listHead != -1 );
      v5 = _count;
      v6 = _groupList;
      v7 = _listIndex;
    }
    ++v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D5560
// Name: Shader_DrawWorldDecalsAndOverlays
// Source: json
//------------------------------------------------------------------------------
void __usercall Shader_DrawWorldDecalsAndOverlays(
        IMatRenderContext *pRenderContext@<edi>,
        CWorldRenderList *pRenderList,
        unsigned int flags,
        float waterZAdjust)
{
  int *v4; // eax
  int v5; // esi
  char *v6; // eax
  int i; // ebx
  IOverlayMgr *v8; // eax
  IOverlayMgr *v9; // eax
  char *v10; // [esp+48h] [ebp-10h]
  bool bFlashlightMask; // [esp+4Ch] [ebp-Ch]
  int v12; // [esp+54h] [ebp-4h]

  v4 = (int *)&args.m_pArgSBuffer[200];
  v12 = 8;
  v10 = &args.m_pArgSBuffer[200];
  do
  {
    if ( (flags & v12) != 0 )
    {
      v5 = *v4;
      if ( *v4 == 3 && waterZAdjust != 0.0 )
      {
        pRenderContext->MatrixMode(this: pRenderContext, a2: MATERIAL_MODEL);
        pRenderContext->PushMatrix(this: pRenderContext);
        pRenderContext->LoadIdentity(this: pRenderContext);
        ((void (__thiscall *)(IMatRenderContext *, _DWORD, _DWORD, _DWORD))pRenderContext->Translate)(
          a1: pRenderContext,
          a2: 0.0,
          a3: 0.0,
          a4: LODWORD(waterZAdjust));
      }
      Shader_DrawDispChainDecalsAndOverlays(pRenderContext, nSortGroup: v5, list: &pRenderList->m_DispSortList, flags);
      AddProjectedTextureDecalsToList(pRenderList, nSortGroup: v5);
      v6 = (char *)pRenderList + 20 * v5;
      for ( i = *((_DWORD *)v6 + 107) - 1; i >= 0; v6 = (char *)pRenderList + 20 * v5 )
        g_pShadowMgr->AddShadowsOnSurfaceToRenderList(
          this: g_pShadowMgr,
          a2: *(unsigned __int16 *)(*((_DWORD *)v6 + 104) + 2 * i--));
      *((_DWORD *)v6 + 107) = 0;
      if ( (flags & 0x80u) != 0 || (bFlashlightMask = true, (flags & 0x100) != 0) )
        bFlashlightMask = false;
      g_pShadowMgr->SetFlashlightStencilMasks(this: g_pShadowMgr, a2: bFlashlightMask);
      g_pShadowMgr->RenderFlashlights(this: g_pShadowMgr, a2: bFlashlightMask, a3: false, a4: nullptr);
      v8 = OverlayMgr();
      v8->RenderOverlays(this: v8, a2: pRenderContext, a3: v5);
      g_pShadowMgr->DrawFlashlightOverlays(this: g_pShadowMgr, a2: pRenderContext, a3: v5, a4: bFlashlightMask);
      v9 = OverlayMgr();
      v9->ClearRenderLists(this: v9, a2: v5);
      DecalSurfaceDraw(pRenderContext, renderGroup: v5, flFade: 1.0);
      ((void (__thiscall *)(IShadowMgrInternal *, IMatRenderContext *, int, bool, _DWORD))g_pShadowMgr->DrawFlashlightDecals)(
        a1: g_pShadowMgr,
        a2: pRenderContext,
        a3: v5,
        a4: bFlashlightMask,
        a5: 1.0);
      g_pShadowMgr->RenderFlashlights(this: g_pShadowMgr, a2: bFlashlightMask, a3: true, a4: nullptr);
      R_DecalFlushDestroyList();
      g_pShadowMgr->RenderShadows(this: g_pShadowMgr, a2: pRenderContext, a3: nullptr);
      g_pShadowMgr->ClearShadowRenderList(this: g_pShadowMgr);
      if ( v5 == 3 && waterZAdjust != 0.0 )
      {
        pRenderContext->MatrixMode(this: pRenderContext, a2: MATERIAL_MODEL);
        pRenderContext->PopMatrix(this: pRenderContext);
      }
    }
    v4 = (int *)(v10 - 4);
    v10 = (char *)v4;
    v12 = __ROR4__(v12, 1);
  }
  while ( (int)v4 >= (int)&args.m_pArgSBuffer[188] );
}

//------------------------------------------------------------------------------
// Address: 0x100D5840
// Name: UpdateVisibleLeafLists
// Source: json
//------------------------------------------------------------------------------
void __cdecl UpdateVisibleLeafLists(CWorldRenderList *pRenderList, mleaf_t *pLeaf)
{
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  int v4; // edi
  WorldListLeafData_t *m_pMemory; // ecx
  int v6; // eax
  WorldListLeafData_t *v7; // eax
  __int16 leafWaterDataID; // cx

  m_Size = pRenderList->m_leaves.m_Size;
  m_nAllocationCount = pRenderList->m_leaves.m_Memory.m_nAllocationCount;
  v4 = pLeaf - host_state.worldbrush->leafs;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CAsyncWavDataCache::DeadBufferEntry_t,int>::Grow(
      this: (CUtlMemory<ResourceEntryInfo,int> *)&pRenderList->m_leaves,
      num: m_Size - m_nAllocationCount + 1);
  ++pRenderList->m_leaves.m_Size;
  m_pMemory = pRenderList->m_leaves.m_Memory.m_pMemory;
  v6 = pRenderList->m_leaves.m_Size - m_Size - 1;
  pRenderList->m_leaves.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 8 * v6);
  v7 = &pRenderList->m_leaves.m_Memory.m_pMemory[m_Size];
  leafWaterDataID = pLeaf->leafWaterDataID;
  v7->firstTranslucentSurface = pRenderList->m_AlphaSurfaces.m_Size;
  v7->leafIndex = v4;
  v7->translucentSurfaceCount = 0;
  v7->waterData = leafWaterDataID;
  if ( leafWaterDataID != -1 )
    pRenderList->m_bWaterVisible = true;
}

//------------------------------------------------------------------------------
// Address: 0x100D58F0
// Name: R_DrawLeaf
// Source: json
//------------------------------------------------------------------------------
void __stdcall R_DrawLeaf(CWorldRenderList *pRenderLista, mleaf_t *pleafa)
{
  mleaf_t *v4; // ebx
  CWorldRenderList *v5; // edi
  int nummarknodesurfaces; // edx
  int v7; // esi
  unsigned int *v8; // eax
  int v9; // ebx
  msurface2_t *v10; // ebx
  int v11; // edx
  unsigned int *v12; // esi
  bool v13; // cl
  unsigned int v14; // ecx
  int v15; // edx
  CUtlMemory<S3RGBA,int> *v16; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  S3RGBA *m_pMemory; // ecx
  int v20; // eax
  msurface2_t **v21; // eax
  int v22; // eax
  CUtlMemory<S3RGBA,int> *m_PaintedSurfaces; // esi
  int v24; // edi
  S3RGBA *v25; // ecx
  int v26; // eax
  msurface2_t **v27; // eax
  int v28; // eax
  CUtlMemory<S3RGBA,int> *p_m_AlphaSurfaces; // esi
  int v30; // edi
  S3RGBA *v31; // ecx
  int v32; // eax
  msurface2_t **v33; // eax
  msurface2_t **pSurfID; // [esp+8h] [ebp-10h]
  int i; // [esp+Ch] [ebp-Ch]
  unsigned int flags; // [esp+10h] [ebp-8h]
  int sortGroup; // [esp+14h] [ebp-4h]

  v4 = pleafa;
  v5 = pRenderLista;
  pSurfID = &host_state.worldbrush->marksurfaces[pleafa->firstmarksurface];
  UpdateVisibleLeafLists(pRenderList: pRenderLista, pLeaf: pleafa);
  if ( s_ShaderConvars.m_nDrawLeaf < 0 || s_ShaderConvars.m_nDrawLeaf == pleafa - host_state.worldbrush->leafs )
  {
    DrawDisplacementsInLeaf(pRenderList: pRenderLista, pLeaf: pleafa);
    if ( s_ShaderConvars.m_bDrawWorld )
    {
      nummarknodesurfaces = pleafa->nummarknodesurfaces;
      v7 = 0;
      i = 0;
      if ( nummarknodesurfaces > 0 )
      {
        do
        {
          v8 = &pRenderLista->m_VisitedSurfs.m_bits.m_pInt[((char *)pSurfID[v7]
                                                          - (char *)host_state.worldbrush->surfaces2) >> 10];
          v9 = 1 << ((pSurfID[v7++] - host_state.worldbrush->surfaces2) & 0x1F);
          *v8 |= v9;
        }
        while ( v7 < nummarknodesurfaces );
        v4 = pleafa;
        i = v7;
      }
      if ( s_ShaderConvars.m_bDrawFuncDetail && v7 < v4->nummarksurfaces )
      {
        while ( 1 )
        {
          v10 = pSurfID[v7];
          v11 = 1 << ((v10 - host_state.worldbrush->surfaces2) & 0x1F);
          v12 = &v5->m_VisitedSurfs.m_bits.m_pInt[((char *)v10 - (char *)host_state.worldbrush->surfaces2) >> 10];
          v13 = (*v12 & v11) != 0;
          *v12 |= v11;
          if ( !v13 )
          {
            v14 = v10->flags;
            flags = v10->flags;
            if ( (v10->flags & 0x200) != 0
              || (float)((float)((float)((float)(v10->plane->normal.y * modelorg.y)
                                       + (float)(v10->plane->normal.x * modelorg.x))
                               + (float)(v10->plane->normal.z * modelorg.z))
                       - v10->plane->dist) >= -0.0099999998 )
            {
              v15 = (v14 >> 22) & 3;
              sortGroup = v15;
              if ( (v14 & 0x80400) != 0 )
              {
                v16 = (CUtlMemory<S3RGBA,int> *)&v5->m_DlightSurfaces[v15];
                m_Size = v5->m_DlightSurfaces[v15].m_Size;
                m_nAllocationCount = v16->m_nAllocationCount;
                if ( m_Size + 1 > m_nAllocationCount )
                {
                  CUtlMemory<INetMessage *,int>::Grow(this: v16, num: m_Size - m_nAllocationCount + 1);
                  v15 = sortGroup;
                }
                ++v16[1].m_pMemory;
                m_pMemory = v16->m_pMemory;
                v20 = (int)v16[1].m_pMemory - m_Size - 1;
                v16[1].m_nAllocationCount = (int)v16->m_pMemory;
                if ( v20 > 0 )
                {
                  _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v20);
                  v15 = sortGroup;
                }
                v21 = (msurface2_t **)&v16->m_pMemory[m_Size];
                v5 = pRenderLista;
                v14 = flags;
                if ( v21 != nullptr )
                  *v21 = v10;
              }
              if ( (v14 & 0x200000) != 0 )
              {
                v22 = v5->m_PaintedSurfaces[0].m_Memory.m_nAllocationCount;
                m_PaintedSurfaces = (CUtlMemory<S3RGBA,int> *)v5->m_PaintedSurfaces;
                v24 = v5->m_PaintedSurfaces[0].m_Size;
                if ( v24 + 1 > v22 )
                {
                  CUtlMemory<INetMessage *,int>::Grow(this: m_PaintedSurfaces, num: v24 - v22 + 1);
                  v15 = sortGroup;
                }
                ++m_PaintedSurfaces[1].m_pMemory;
                v25 = m_PaintedSurfaces->m_pMemory;
                v26 = (int)m_PaintedSurfaces[1].m_pMemory - v24 - 1;
                m_PaintedSurfaces[1].m_nAllocationCount = (int)m_PaintedSurfaces->m_pMemory;
                if ( v26 > 0 )
                {
                  _V_memmove(dest: &v25[v24 + 1], src: &v25[v24], count: 4 * v26);
                  v15 = sortGroup;
                }
                v27 = (msurface2_t **)&m_PaintedSurfaces->m_pMemory[v24];
                v5 = pRenderLista;
                LOBYTE(v14) = flags;
                if ( v27 != nullptr )
                  *v27 = v10;
              }
              if ( (v14 & 0x20) != 0 )
              {
                v28 = v5->m_AlphaSurfaces.m_Memory.m_nAllocationCount;
                p_m_AlphaSurfaces = (CUtlMemory<S3RGBA,int> *)&v5->m_AlphaSurfaces;
                v30 = v5->m_AlphaSurfaces.m_Size;
                if ( v30 + 1 > v28 )
                  CUtlMemory<INetMessage *,int>::Grow(this: p_m_AlphaSurfaces, num: v30 - v28 + 1);
                ++p_m_AlphaSurfaces[1].m_pMemory;
                v31 = p_m_AlphaSurfaces->m_pMemory;
                v32 = (int)p_m_AlphaSurfaces[1].m_pMemory - v30 - 1;
                p_m_AlphaSurfaces[1].m_nAllocationCount = (int)p_m_AlphaSurfaces->m_pMemory;
                if ( v32 > 0 )
                  _V_memmove(dest: &v31[v30 + 1], src: &v31[v30], count: 4 * v32);
                v33 = (msurface2_t **)&p_m_AlphaSurfaces->m_pMemory[v30];
                v5 = pRenderLista;
                if ( v33 != nullptr )
                  *v33 = v10;
              }
              else
              {
                if ( v10->decals != 0xFFFF )
                {
                  DecalSurfaceAdd(surfID: v10, iGroup: v15);
                  v15 = sortGroup;
                }
                CMSurfaceSortList::AddSurfaceToTail(
                  this: &v5->m_SortList,
                  pSurface: v10,
                  sortGroup: v15,
                  sortID: v10->materialSortID);
              }
            }
          }
          if ( ++i >= pleafa->nummarksurfaces )
            break;
          v7 = i;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D5BD0
// Name: R_BuildWorldListNoCull
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_BuildWorldListNoCull(CWorldRenderList *pRenderList)
{
  mnode_t *node; // ecx
  mnode_t *v2; // esi
  int v3; // ecx
  int v4; // edi
  int v5; // ebx
  bool v6; // al
  mleaf_t *v7; // eax
  mleaf_t *v8; // edi
  CWorldRenderList *v9; // esi
  int v10; // ebx
  msurface2_t *v11; // edi
  int v12; // edx
  unsigned int *v13; // esi
  bool v14; // cl
  mleaf_t *pLeaf[2048]; // [esp+Ch] [ebp-2010h]
  mleaf_t *v16; // [esp+200Ch] [ebp-10h]
  msurface2_t **v17; // [esp+2010h] [ebp-Ch]
  int v18; // [esp+2014h] [ebp-8h]
  int v19; // [esp+2018h] [ebp-4h]

  v2 = node;
  v3 = 0;
  v4 = 0;
  v19 = 0;
  v5 = 0;
  while ( 1 )
  {
    while ( 1 )
    {
      if ( v2->contents == 1 )
        goto LABEL_9;
      if ( v2->visframe != r_visframecount )
        goto LABEL_9;
      if ( v2->contents >= -1 )
      {
        v6 = R_CullNode(pNode: v2);
        v3 = v19;
        if ( v6 )
          goto LABEL_9;
      }
      if ( v2->contents >= 0 )
        break;
      v7 = (mleaf_t *)v2->children[0];
      v2 = v2->children[1];
      pLeaf[v5 + 1024] = v7;
      v5 = ((_WORD)v5 + 1) & 0x3FF;
    }
    if ( v3 < 1024 )
    {
      pLeaf[v3++] = (mleaf_t *)v2;
      v19 = v3;
    }
LABEL_9:
    if ( v4 == v5 )
      break;
    v2 = (mnode_t *)pLeaf[v4 + 1024];
    v4 = ((_WORD)v4 + 1) & 0x3FF;
  }
  v18 = 0;
  if ( v3 > 0 )
  {
    do
    {
      v9 = pRenderList;
      v16 = pLeaf[v18];
      v8 = v16;
      UpdateVisibleLeafLists(pRenderList, pLeaf: v16);
      DrawDisplacementsInLeaf(pRenderList, pLeaf: v8);
      v10 = 0;
      v17 = &host_state.worldbrush->marksurfaces[v8->firstmarksurface];
      if ( v8->nummarksurfaces != 0 )
      {
        while ( 1 )
        {
          v11 = v17[v10];
          v12 = 1 << ((v11 - host_state.worldbrush->surfaces2) & 0x1F);
          v13 = &v9->m_VisitedSurfs.m_bits.m_pInt[((char *)v11 - (char *)host_state.worldbrush->surfaces2) >> 10];
          v14 = (*v13 & v12) != 0;
          *v13 |= v12;
          if ( !v14 && (v11->flags & 0x24) == 0 )
            CMSurfaceSortList::AddSurfaceToTail(
              this: &pRenderList->m_SortList,
              pSurface: v11,
              sortGroup: (v11->flags >> 22) & 3,
              sortID: v11->materialSortID);
          if ( ++v10 >= v16->nummarksurfaces )
            break;
          v9 = pRenderList;
        }
      }
      ++v18;
    }
    while ( v18 < v19 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D5D40
// Name: R_RecursiveWorldNode
// Source: json
//------------------------------------------------------------------------------
void __fastcall R_RecursiveWorldNode(CWorldRenderList *pRenderList, mnode_t *node)
{
  mnode_t *v2; // ebx
  int contents; // eax
  CWorldRenderList *v4; // esi
  cplane_t *plane; // eax
  unsigned __int8 type; // cl
  float v7; // xmm0_4
  msurface2_t *v8; // edi
  int v9; // esi
  int v10; // eax
  int v11; // ebx
  unsigned int flags; // ecx
  int nLastSurface; // [esp+8h] [ebp-10h]
  mnode_t *v14; // [esp+Ch] [ebp-Ch]
  BOOL side; // [esp+10h] [ebp-8h]

  v2 = node;
  contents = node->contents;
  v4 = pRenderList;
  v14 = node;
  if ( node->contents != 1 )
  {
    while ( v2->visframe == r_visframecount && (contents < -1 || !R_CullNode(pNode: v2)) )
    {
      if ( v2->contents >= 0 )
      {
        R_DrawLeaf(pRenderLista: v4, pleafa: (mleaf_t *)v2);
        return;
      }
      plane = v2->plane;
      type = plane->type;
      if ( type > 2u )
        v7 = (float)((float)(plane->normal.y * modelorg.y) + (float)(plane->normal.x * modelorg.x))
           + (float)(plane->normal.z * modelorg.z);
      else
        v7 = *(&modelorg.x + type);
      side = (float)(v7 - plane->dist) < 0.0;
      R_RecursiveWorldNode(pRenderList: v4, node: v2->children[side]);
      v8 = &host_state.worldbrush->surfaces2[v2->firstsurface];
      v9 = (32 * v2->firstsurface) >> 5;
      v10 = v9 + v2->numsurfaces;
      v11 = __ROL4__(1, v9);
      nLastSurface = v10;
      if ( v9 < (unsigned int)v10 )
      {
        do
        {
          if ( (v11 & pRenderList->m_VisitedSurfs.m_bits.m_pInt[v9 >> 5]) != 0 )
          {
            flags = v8->flags;
            if ( (v8->flags & 0x20000) != 0 || side == ((v8->flags & 0x40) != 0) )
            {
              if ( (flags & 4) != 0 )
              {
                pRenderList->m_bSkyVisible = true;
              }
              else
              {
                if ( (flags & 0x20) != 0 )
                  Shader_TranslucentWorldSurface(pRenderList, surfID: v8);
                else
                  Shader_WorldSurface(pRenderList, surfID: v8);
                v10 = nLastSurface;
              }
            }
          }
          ++v9;
          v11 = __ROL4__(v11, 1);
          ++v8;
        }
        while ( v9 < v10 );
      }
      v14 = v14->children[!side];
      contents = v14->contents;
      if ( v14->contents == 1 )
        return;
      v2 = v14;
      v4 = pRenderList;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D5ED0
// Name: R_DrawTopViewLeaf
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_DrawTopViewLeaf(CWorldRenderList *pRenderList, mleaf_t *pleaf)
{
  CWorldRenderList *v2; // esi
  int v3; // ebx
  msurface2_t *v4; // edi
  int v5; // edx
  unsigned int *v6; // esi
  bool v7; // cl
  unsigned int flags; // eax
  msurface2_t **pHandle; // [esp+8h] [ebp-4h]

  v2 = pRenderList;
  UpdateVisibleLeafLists(pRenderList, pLeaf: pleaf);
  DrawDisplacementsInLeaf(pRenderList, pLeaf: pleaf);
  if ( s_ShaderConvars.m_bDrawWorld )
  {
    v3 = 0;
    pHandle = &host_state.worldbrush->marksurfaces[pleaf->firstmarksurface];
    if ( pleaf->nummarksurfaces != 0 )
    {
      while ( 1 )
      {
        v4 = pHandle[v3];
        v5 = 1 << ((v4 - host_state.worldbrush->surfaces2) & 0x1F);
        v6 = &v2->m_VisitedSurfs.m_bits.m_pInt[((char *)v4 - (char *)host_state.worldbrush->surfaces2) >> 10];
        v7 = (*v6 & v5) != 0;
        *v6 |= v5;
        if ( !v7 )
        {
          flags = v4->flags;
          if ( (v4->flags & 0x800) == 0
            && (flags & 2) == 0
            && ((flags & 0x200) != 0 || v4->plane->normal.z > 0.0)
            && (flags & 0x20) == 0 )
          {
            Shader_WorldSurface(pRenderList, surfID: v4);
          }
        }
        if ( ++v3 >= pleaf->nummarksurfaces )
          break;
        v2 = pRenderList;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D5FB0
// Name: R_RenderWorldTopView
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_RenderWorldTopView(CWorldRenderList *pRenderList, int node)
{
  msurface2_t *v3; // edi
  int v4; // edx
  unsigned int *v5; // esi
  bool v6; // cl
  unsigned int flags; // eax
  int i; // [esp+28h] [ebp+Ch]

  while ( *(_DWORD *)node != 1
       && *(_DWORD *)(node + 4) == r_visframecount
       && fabs(*(float *)(node + 16) - s_OrthographicCenter.x) <= *(float *)(node + 32) + s_OrthographicHalfDiagonal.x
       && fabs((float)(*(float *)(node + 20) - s_OrthographicCenter.y)) <= (float)(*(float *)(node + 36)
                                                                                 + s_OrthographicHalfDiagonal.y) )
  {
    if ( *(int *)node >= 0 )
    {
      R_DrawTopViewLeaf(pRenderList, pleaf: (mleaf_t *)node);
      return;
    }
    if ( s_ShaderConvars.m_bDrawWorld )
    {
      v3 = &host_state.worldbrush->surfaces2[*(unsigned __int16 *)(node + 60)];
      i = 0;
      if ( *(_WORD *)(node + 62) != 0 )
      {
        do
        {
          v4 = 1 << ((v3 - host_state.worldbrush->surfaces2) & 0x1F);
          v5 = &pRenderList->m_VisitedSurfs.m_bits.m_pInt[((char *)v3 - (char *)host_state.worldbrush->surfaces2) >> 10];
          v6 = (*v5 & v4) != 0;
          *v5 |= v4;
          if ( !v6 )
          {
            flags = v3->flags;
            if ( (v3->flags & 0x800) == 0
              && (flags & 0x20004) == 0
              && ((flags & 0x200) != 0 || v3->plane->normal.z > 0.0)
              && (flags & 0x20) == 0 )
            {
              Shader_WorldSurface(pRenderList, surfID: v3);
            }
          }
          ++v3;
          ++i;
        }
        while ( i < *(unsigned __int16 *)(node + 62) );
      }
    }
    R_RenderWorldTopView(pRenderList, node: *(mnode_t **)(node + 52));
    node = *(_DWORD *)(node + 56);
    if ( node == 0 )
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D6130
// Name: void R_BuildWorldLists(class IWorldRenderList __near *,struct WorldListInfo_t __near *,int,struct VisOverrideData_t const __near *,bool,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_BuildWorldLists(
        CWorldRenderList *pRenderListIn,
        WorldListInfo_t *pInfo,
        int iForceViewLeaf,
        const VisOverrideData_t *pVisData,
        bool bShadowDepth,
        float *pWaterReflectionHeight)
{
  FogVolumeInfo_t fogInfo; // [esp+0h] [ebp-2Ch] BYREF

  if ( g_LostVideoMemory )
  {
    if ( pInfo != nullptr )
    {
      pInfo->m_ViewFogVolume = 0;
      pInfo->m_LeafCount = 0;
      pInfo->m_pLeafDataList = pRenderListIn->m_leaves.m_Memory.m_pMemory;
      pInfo->m_bHasWater = pRenderListIn->m_bWaterVisible;
    }
  }
  else
  {
    modelorg = *g_EngineRenderer->ViewOrigin(this: g_EngineRenderer);
    Shader_WorldBegin(pRenderList: pRenderListIn);
    if ( r_drawtopview )
    {
      R_RenderWorldTopView(pRenderList: pRenderListIn, node: (int)host_state.worldbrush->nodes);
    }
    else
    {
      R_SetupAreaBits(iForceViewLeaf, pVisData, pWaterReflectionHeight);
      if ( bShadowDepth )
        R_BuildWorldListNoCull(pRenderList: pRenderListIn);
      else
        R_RecursiveWorldNode(pRenderList: pRenderListIn, node: host_state.worldbrush->nodes);
    }
    CWorldRenderList::CountTranslucentSurfaces(this: pRenderListIn);
    if ( !r_drawtopview && !bShadowDepth )
      Shader_BuildDynamicLightmaps(pRenderList: pRenderListIn);
    if ( pInfo != nullptr )
    {
      if ( bShadowDepth )
      {
        pInfo->m_ViewFogVolume = 0;
      }
      else
      {
        ComputeFogVolumeInfo(pFogVolume: &fogInfo);
        pInfo->m_ViewFogVolume = fogInfo.m_InFogVolume;
      }
      pInfo->m_LeafCount = pRenderListIn->m_leaves.m_Size;
      pInfo->m_pLeafDataList = pRenderListIn->m_leaves.m_Memory.m_pMemory;
      pInfo->m_bHasWater = pRenderListIn->m_bWaterVisible;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D6280
// Name: R_DrawBrushModel_Override
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_DrawBrushModel_Override(IMatRenderContext *pRenderContext, IClientEntity *baseentity, model_t *model)
{
  msurface2_t *v3; // esi
  msurface2_t **m_pMemory; // edi
  IMatRenderContext_vtbl *v5; // edx
  void (__thiscall *BindLightmapPage)(IMatRenderContext *, int); // eax
  char v7; // al
  int v8; // ecx
  int m_Size; // esi
  int v10; // ebx
  int *v11; // ebx
  _DWORD v12[2]; // [esp+Ch] [ebp-48h] BYREF
  SurfaceCtx_t ctx; // [esp+14h] [ebp-40h] BYREF
  CUtlVector<msurface2_t *,CUtlMemory<msurface2_t *,int> > surfaceList; // [esp+38h] [ebp-1Ch] BYREF
  int j; // [esp+4Ch] [ebp-8h]
  int i; // [esp+50h] [ebp-4h]

  v3 = (msurface2_t *)(*(_DWORD *)(model->sprite.numframes + 124) + 32 * model->brush.firstmodelsurface);
  m_pMemory = nullptr;
  i = 0;
  if ( model->brush.nummodelsurfaces > 0 )
  {
    do
    {
      v5 = pRenderContext->__vftable;
      if ( g_pMaterialSystemConfig->nFullbright == 1 )
      {
        BindLightmapPage = v5->BindLightmapPage;
        if ( (v3->flags & 8) != 0 )
          ((void (__stdcall *)(int))BindLightmapPage)(a1: -2);
        else
          ((void (__stdcall *)(int))BindLightmapPage)(a1: -1);
      }
      else
      {
        ((void (__stdcall *)(int))v5->BindLightmapPage)(a1: materialSortInfoArray[v3->materialSortID].lightmapPageID);
      }
      v12[0] = &args.m_pArgSBuffer[424];
      v12[1] = v3;
      SurfSetupSurfaceContext(&ctx, surfID: v3);
      v7 = s_pBrushRenderOverride->RenderBrushModelSurface(
             this: s_pBrushRenderOverride,
             a2: baseentity,
             a3: (IBrushSurface *)v12);
      if ( v3->decals != 0xFFFF && v7 != 0 )
        DecalSurfaceAdd(surfID: v3, iGroup: 4);
      if ( v3->m_ShadowDecals != 0xFFFF )
        g_pShadowMgr->AddShadowsOnSurfaceToRenderList(this: g_pShadowMgr, a2: v3->m_ShadowDecals);
      ++v3;
      ++i;
    }
    while ( i < model->brush.nummodelsurfaces );
    m_pMemory = nullptr;
  }
  if ( g_ShaderDebug.anydebug )
  {
    v8 = *(_DWORD *)(model->sprite.numframes + 124) + 32 * model->brush.firstmodelsurface;
    m_Size = 0;
    memset(&surfaceList, 0, sizeof(surfaceList));
    i = v8;
    for ( j = 0; j < model->brush.nummodelsurfaces; i = v8 )
    {
      v10 = m_Size;
      if ( m_Size + 1 > surfaceList.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<INetMessage *,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)&surfaceList,
          num: m_Size - surfaceList.m_Memory.m_nAllocationCount + 1);
        m_Size = surfaceList.m_Size;
        m_pMemory = surfaceList.m_Memory.m_pMemory;
        v8 = i;
      }
      surfaceList.m_Size = ++m_Size;
      surfaceList.m_pElements = m_pMemory;
      if ( m_Size - v10 - 1 > 0 )
      {
        _V_memmove(dest: &m_pMemory[v10 + 1], src: &m_pMemory[v10], count: 4 * (m_Size - v10 - 1));
        v8 = i;
      }
      v11 = (int *)&m_pMemory[v10];
      if ( v11 != nullptr )
        *v11 = v8;
      v8 += 32;
      ++j;
    }
    DrawDebugInformation(pRenderContext, pList: m_pMemory, listCount: m_Size);
    if ( surfaceList.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D6440
// Name: void R_DrawBrushModel(class IClientEntity __near *,struct model_t __near *,class matrix3x4a_t const __near &,bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_DrawBrushModel(
        IClientEntity *baseentity,
        model_t *model,
        const matrix3x4a_t *brushModelToWorld,
        bool bShadowDepth,
        bool bDrawOpaque,
        bool bDrawTranslucent)
{
  int m_nValue; // eax
  IMatRenderContext *v7; // eax
  IMatRenderContext *v8; // esi
  CBrushModelTransform brushTransform; // [esp+0h] [ebp-14h] BYREF
  bool bWireframe; // [esp+13h] [ebp-1h]

  if ( r_drawbrushmodels.m_pParent != nullptr )
  {
    m_nValue = r_drawbrushmodels.m_pParent->m_Value.m_nValue;
    if ( m_nValue != 0 )
    {
      bWireframe = false;
      if ( m_nValue == 2 )
      {
        bWireframe = g_ShaderDebug.wireframe;
        g_ShaderDebug.wireframe = true;
        g_ShaderDebug.anydebug = true;
      }
      v7 = materials->GetRenderContext(this: materials);
      v8 = v7;
      if ( v7 != nullptr )
        v7->BeginRender(this: v7);
      CBrushModelTransform::CBrushModelTransform(this: &brushTransform, matrix: brushModelToWorld, pRenderContext: v8);
      DecalSurfacesInit(bBrushModel: true);
      g_pShadowMgr->ClearShadowRenderList(this: g_pShadowMgr);
      if ( s_pBrushRenderOverride != nullptr )
      {
        R_DrawBrushModel_Override(pRenderContext: v8, baseentity, model);
      }
      else if ( (model->flags & 2) != 0 )
      {
        if ( !bShadowDepth )
          CBrushBatchRender::DrawTranslucentBrushModel(
            this: &g_BrushBatchRenderer,
            pRenderContext: v8,
            baseentity,
            model,
            bShadowDepth: false,
            bDrawOpaque,
            bDrawTranslucent);
      }
      else if ( bDrawOpaque )
      {
        CBrushBatchRender::DrawOpaqueBrushModel(
          this: &g_BrushBatchRenderer,
          a2: (CMeshBuilder *)model,
          pRenderContext: v8,
          baseentity,
          model,
          bShadowDepth);
      }
      Shader_BrushEnd(
        pRenderContext: v8,
        pBrushToWorld: brushTransform.m_bIdentity ? nullptr : &g_BrushToWorldMatrix,
        model,
        bShadowDepth);
      if ( r_drawbrushmodels.m_pParent != nullptr && r_drawbrushmodels.m_pParent->m_Value.m_nValue == 2 )
      {
        g_ShaderDebug.wireframe = bWireframe;
        if ( bWireframe
          || g_ShaderDebug.normals
          || g_ShaderDebug.luxels != bWireframe
          || g_ShaderDebug.bumpBasis != bWireframe
          || g_ShaderDebug.surfaceid != 0
          || (g_ShaderDebug.anydebug = bWireframe, g_ShaderDebug.surfacematerials != bWireframe) )
        {
          g_ShaderDebug.anydebug = true;
        }
      }
      CBrushModelTransform::~CBrushModelTransform(this: &brushTransform, a2: (int)v8);
      if ( v8 != nullptr )
      {
        v8->EndRender(this: v8);
        v8->Release(this: v8);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D65C0
// Name: void R_DrawBrushModel(class IClientEntity __near *,struct model_t __near *,class Vector const __near &,class QAngle const __near &,bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall R_DrawBrushModel(
        unsigned int a1@<ebp>,
        IClientEntity *baseentity,
        model_t *model,
        const Vector *origin,
        const QAngle *angles,
        bool bShadowDepth,
        bool bDrawOpaque,
        bool bDrawTranslucent)
{
  _BYTE v8[12]; // [esp-Ch] [ebp-3Ch] BYREF
  matrix3x4a_t mat; // [esp+0h] [ebp-30h]
  unsigned int retaddr; // [esp+30h] [ebp+0h]

  *(_QWORD *)&mat.m_flMatVal[2][1] = __PAIR64__(retaddr, a1);
  AngleMatrix(angles, position: origin, matrix: (matrix3x4_t *)v8);
  R_DrawBrushModel(
    baseentity,
    model,
    brushModelToWorld: (const matrix3x4a_t *)v8,
    bShadowDepth,
    bDrawOpaque,
    bDrawTranslucent);
}

//------------------------------------------------------------------------------
// Address: 0x100D6620
// Name: void R_DrawIdentityBrushModel(class IWorldRenderList __near *,struct model_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_DrawIdentityBrushModel(CWorldRenderList *pRenderListIn, model_t *model)
{
  msurface2_t *v2; // esi
  int i; // edi

  if ( model != nullptr )
  {
    v2 = (msurface2_t *)(*(_DWORD *)(model->sprite.numframes + 124) + 32 * model->brush.firstmodelsurface);
    for ( i = 0; i < model->brush.nummodelsurfaces; ++v2 )
    {
      if ( (v2->flags & 0x20) != 0 )
        Shader_TranslucentWorldSurface(pRenderList: pRenderListIn, surfID: v2);
      else
        Shader_WorldSurface(pRenderList: pRenderListIn, surfID: v2);
      ++i;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D66D0
// Name: public: CMSurfaceSortList::~CMSurfaceSortList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMSurfaceSortList::~CMSurfaceSortList(CMSurfaceSortList *this)
{
  surfacesortgroup_t *p_m_emptyGroup; // esi
  int i; // ebx
  void *listHead; // eax

  p_m_emptyGroup = &this->m_emptyGroup;
  for ( i = 3; i >= 0; --i )
  {
    p_m_emptyGroup = (surfacesortgroup_t *)((char *)p_m_emptyGroup - 20);
    p_m_emptyGroup->vertexCount = 0;
    if ( p_m_emptyGroup->groupListIndex >= 0 )
    {
      if ( p_m_emptyGroup->listHead != 0 )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)p_m_emptyGroup->listHead);
        p_m_emptyGroup->listHead = 0;
      }
      p_m_emptyGroup->listTail = 0;
    }
    listHead = (void *)p_m_emptyGroup->listHead;
    p_m_emptyGroup->vertexCountNoDetail = p_m_emptyGroup->listHead;
    if ( p_m_emptyGroup->groupListIndex >= 0 )
    {
      if ( listHead != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: listHead);
        p_m_emptyGroup->listHead = 0;
      }
      p_m_emptyGroup->listTail = 0;
    }
  }
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_groupUsed);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_groups);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>((CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x100D6760
// Name: Shader_WorldShadowDepthFill
// Source: json
//------------------------------------------------------------------------------
void __cdecl Shader_WorldShadowDepthFill(
        IMatRenderContext *pRenderContext,
        CWorldRenderList *pRenderList,
        unsigned int flags)
{
  int v3; // ebx
  int v4; // edi
  int *v5; // esi
  int v6; // eax
  const materiallist_t *v7; // ecx
  const surfacesortgroup_t *v8; // edi
  msurface2_t *SurfaceAtHead; // eax
  IMaterial *material; // esi
  int m_Size; // eax
  int v12; // esi
  int v13; // eax
  const surfacesortgroup_t **v14; // eax
  unsigned int triangleCount; // eax
  int v17; // esi
  int (__thiscall *GetMaxVerticesToRender)(IMatRenderContext *, IMaterial *); // edx
  int v19; // eax
  CMSurfaceSortList *v20; // ebx
  const surfacesortgroup_t *v21; // esi
  msurface2_t *v22; // eax
  IMaterial *v23; // edi
  __int16 i; // ax
  int v25; // eax
  const materiallist_t *v26; // ecx
  bool v27; // cc
  char *v28; // edi
  unsigned int v29; // eax
  int indexCount; // ebx
  int v31; // esi
  unsigned __int16 firstPrimID; // ax
  int v33; // edx
  mprimitive_t *primitives; // eax
  bool v35; // zf
  mprimitive_t *v36; // eax
  int m_nVertexCount; // eax
  int v38; // eax
  int v39; // esi
  int v40; // edi
  const surfacesortgroup_t **m_pMemory; // ebx
  CMeshBuilder meshBuilder; // [esp+Ch] [ebp-244h] BYREF
  int v43; // [esp+1F4h] [ebp-5Ch]
  CUtlVector<surfacesortgroup_t *,CUtlMemory<surfacesortgroup_t *,int> > *v44; // [esp+1F8h] [ebp-58h]
  int v45; // [esp+1FCh] [ebp-54h]
  msurface2_t *nSurfID; // [esp+200h] [ebp-50h]
  int nMaxIndices; // [esp+204h] [ebp-4Ch]
  msurface2_t **pSurfaces; // [esp+208h] [ebp-48h]
  int nMaxVertices; // [esp+20Ch] [ebp-44h]
  int _listIndex; // [esp+210h] [ebp-40h]
  CUtlVector<surfacesortgroup_t const *,CUtlMemory<surfacesortgroup_t const *,int> > alphatestedGroups; // [esp+214h] [ebp-3Ch] BYREF
  int _index; // [esp+228h] [ebp-28h]
  const materiallist_t *_pList; // [esp+22Ch] [ebp-24h]
  int nSortGroup; // [esp+230h] [ebp-20h] BYREF
  IMesh *pMesh; // [esp+234h] [ebp-1Ch]
  const CMSurfaceSortList *sortList; // [esp+238h] [ebp-18h]
  int v57; // [esp+23Ch] [ebp-14h]
  char *v58; // [esp+240h] [ebp-10h]
  int nIndexCount; // [esp+244h] [ebp-Ch]
  int nVertexCount; // [esp+248h] [ebp-8h]
  int nBatchVertexCount; // [esp+24Ch] [ebp-4h]
  int nBatchIndexCount; // [esp+25Ch] [ebp+Ch]

  v3 = 0;
  v4 = 1;
  v5 = (int *)&args.m_pArgSBuffer[188];
  nVertexCount = 0;
  nIndexCount = 0;
  memset(&alphatestedGroups, 0, sizeof(alphatestedGroups));
  sortList = &pRenderList->m_SortList;
  v57 = 1;
  v58 = &args.m_pArgSBuffer[188];
  do
  {
    if ( (v4 & flags) != 0 )
    {
      v6 = *v5;
      _index = (int)&sortList->m_sortGroupLists[*v5];
      v7 = *(const materiallist_t **)(_index + 12);
      nSortGroup = v6;
      _pList = v7;
      if ( (int)v7 > 0 )
      {
        do
        {
          v8 = *(const surfacesortgroup_t **)(*(_DWORD *)_index + 4 * v3);
          SurfaceAtHead = CMSurfaceSortList::GetSurfaceAtHead(this: (CMSurfaceSortList *)sortList, group: v8);
          if ( (SurfaceAtHead->flags & 0x10000) == 0 )
          {
            material = host_state.worldbrush->texinfo[*((unsigned __int16 *)SurfaceAtHead + 11) >> 1].material;
            if ( !material->IsTranslucent(this: material) )
            {
              if ( material->IsAlphaTested(this: material) )
              {
                m_Size = alphatestedGroups.m_Size;
                v12 = alphatestedGroups.m_Size;
                if ( alphatestedGroups.m_Size + 1 > alphatestedGroups.m_Memory.m_nAllocationCount )
                {
                  CUtlMemory<INetMessage *,int>::Grow(
                    this: (CUtlMemory<S3RGBA,int> *)&alphatestedGroups,
                    num: alphatestedGroups.m_Size - alphatestedGroups.m_Memory.m_nAllocationCount + 1);
                  m_Size = alphatestedGroups.m_Size;
                }
                alphatestedGroups.m_Size = m_Size + 1;
                v13 = m_Size - v12;
                alphatestedGroups.m_pElements = alphatestedGroups.m_Memory.m_pMemory;
                if ( v13 > 0 )
                  _V_memmove(
                    dest: &alphatestedGroups.m_Memory.m_pMemory[v12 + 1],
                    src: &alphatestedGroups.m_Memory.m_pMemory[v12],
                    count: 4 * v13);
                v14 = &alphatestedGroups.m_Memory.m_pMemory[v12];
                if ( v14 != nullptr )
                  *v14 = v8;
              }
              else
              {
                triangleCount = v8->triangleCount;
                nVertexCount += v8->vertexCount;
                nIndexCount += triangleCount + 2 * triangleCount;
              }
            }
          }
          ++v3;
        }
        while ( v3 < (int)_pList );
        v5 = (int *)v58;
        v4 = v57;
        v6 = nSortGroup;
        v3 = 0;
      }
      Shader_DrawDispChain(
        pRenderContext,
        nSortGroup: v6,
        list: &pRenderList->m_DispSortList,
        flags,
        bShadowDepth: (IMaterial *)1);
    }
    ++v5;
    v4 = __ROL4__(v4, 1);
    v58 = (char *)v5;
    v57 = v4;
  }
  while ( (int)v5 < (int)&args.m_pArgSBuffer[204] );
  if ( nVertexCount != 0 )
  {
    pRenderContext->Bind(this: pRenderContext, a2: (IMaterial *)dword_105F3008, a3: nullptr);
    pMesh = pRenderContext->GetDynamicMesh(this: pRenderContext, a2: 0, a3: 0, a4: 0, a5: 0);
    v17 = pRenderContext->GetMaxIndicesToRender(this: pRenderContext);
    GetMaxVerticesToRender = pRenderContext->GetMaxVerticesToRender;
    nMaxIndices = v17;
    v19 = GetMaxVerticesToRender(this: pRenderContext, a2: (IMaterial *)dword_105F3008);
    nMaxVertices = v19;
    if ( nIndexCount >= v17 )
    {
      nBatchIndexCount = v17;
    }
    else
    {
      v17 = nIndexCount;
      nBatchIndexCount = nIndexCount;
    }
    if ( nVertexCount >= v19 )
    {
      nBatchVertexCount = v19;
    }
    else
    {
      v19 = nVertexCount;
      nBatchVertexCount = nVertexCount;
    }
    meshBuilder.m_IndexBuilder.m_nBufferOffset = -1;
    meshBuilder.m_VertexBuilder.m_nBufferOffset = -1;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
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
    CMeshBuilder::Begin(
      this: &meshBuilder,
      pMesh,
      type: MATERIAL_TRIANGLES,
      nVertexCount: v19,
      nIndexCount: v17,
      pMeshSettings: nullptr);
    nSortGroup = 0;
    v57 = 1;
    v58 = &args.m_pArgSBuffer[188];
    do
    {
      if ( (v57 & flags) != 0 )
      {
        v20 = (CMSurfaceSortList *)sortList;
        v44 = &sortList->m_sortGroupLists[*(_DWORD *)v58];
        v45 = v44->m_Size;
        for ( _listIndex = 0; _listIndex < v45; ++_listIndex )
        {
          v21 = v44->m_Memory.m_pMemory[_listIndex];
          v22 = CMSurfaceSortList::GetSurfaceAtHead(this: v20, group: v21);
          if ( v21->triangleCount != 0 && v21->vertexCount != 0 )
          {
            v23 = host_state.worldbrush->texinfo[*((unsigned __int16 *)v22 + 11) >> 1].material;
            if ( !v23->IsTranslucent(this: v23) && !v23->IsAlphaTested(this: v23) )
            {
              for ( i = v21->listHead; i != -1; i = *(_WORD *)((char *)&v20->m_list.m_Memory.m_pMemory->nextBlock + v25) )
              {
                v25 = i << 6;
                v26 = (materiallist_t *)((char *)v20->m_list.m_Memory.m_pMemory + v25);
                v27 = v26->count <= 0;
                v43 = v25;
                _pList = v26;
                _index = 0;
                if ( !v27 )
                {
                  pSurfaces = v26->pSurfaces;
                  do
                  {
                    v28 = (char *)*pSurfaces;
                    v29 = (*pSurfaces)->flags;
                    nSurfID = *pSurfaces;
                    if ( v29 != 0 && (v29 & 0x10000) == 0 )
                    {
                      indexCount = 0;
                      v31 = 0;
                      if ( (v29 & 0x8000) != 0 )
                      {
                        if ( (v29 & 0x800) != 0 )
                          firstPrimID = 0;
                        else
                          firstPrimID = host_state.worldbrush->surfaces1[(v28 - (char *)host_state.worldbrush->surfaces2) >> 5].prims.firstPrimID;
                        v33 = firstPrimID;
                        primitives = host_state.worldbrush->primitives;
                        v35 = primitives[v33].vertCount == 0;
                        v36 = &primitives[v33];
                        if ( v35 )
                        {
                          v31 = (unsigned __int8)v28[3];
                          indexCount = v36->indexCount;
                        }
                      }
                      else
                      {
                        v31 = (unsigned __int8)v28[3];
                        indexCount = 3 * v31 - 6;
                      }
                      if ( v31 > nMaxVertices || indexCount > nMaxIndices )
                      {
                        _Error(a1: &args.m_pArgvBuffer[20], v31, nMaxVertices, indexCount, nMaxIndices);
                      }
                      else
                      {
                        if ( nBatchIndexCount < indexCount || nBatchVertexCount < v31 )
                        {
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
                          nBatchIndexCount = nIndexCount;
                          if ( nIndexCount >= nMaxIndices )
                            nBatchIndexCount = nMaxIndices;
                          nBatchVertexCount = nVertexCount;
                          if ( nVertexCount >= nMaxVertices )
                            nBatchVertexCount = nMaxVertices;
                          pMesh = pRenderContext->GetDynamicMesh(this: pRenderContext, a2: 0, a3: 0, a4: 0, a5: 0);
                          CMeshBuilder::Begin(
                            this: &meshBuilder,
                            pMesh,
                            type: MATERIAL_TRIANGLES,
                            nVertexCount: nBatchVertexCount,
                            nIndexCount: nBatchIndexCount,
                            pMeshSettings: nullptr);
                          nSortGroup = 0;
                        }
                        Shader_WorldZFillSurfChain_Single(surfaceHandle: nSurfID, &meshBuilder, nStartVert: &nSortGroup);
                        nBatchIndexCount -= indexCount;
                        nBatchVertexCount -= v31;
                        nIndexCount -= indexCount;
                        nVertexCount -= v31;
                      }
                      v26 = _pList;
                    }
                    ++pSurfaces;
                    ++_index;
                  }
                  while ( _index < v26->count );
                  v20 = (CMSurfaceSortList *)sortList;
                  v25 = v43;
                }
              }
            }
          }
        }
      }
      v58 += 4;
      v57 = __ROL4__(v57, 1);
    }
    while ( (int)v58 < (int)&args.m_pArgSBuffer[204] );
    if ( meshBuilder.m_bGenerateIndices )
    {
      switch ( meshBuilder.m_Type )
      {
        case MATERIAL_LINE_STRIP:
          v38 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
          break;
        case MATERIAL_LINE_LOOP:
          v38 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
        case MATERIAL_POLYGON:
          v38 = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
          break;
        case MATERIAL_QUADS:
          v38 = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
          break;
        case MATERIAL_INSTANCED_QUADS:
          v38 = 0;
          break;
        default:
          v38 = meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
      }
      CIndexBuilder::GenerateIndices(
        this: &meshBuilder.m_IndexBuilder,
        primitiveType: meshBuilder.m_Type,
        nIndexCount: v38);
    }
    meshBuilder.m_pMesh->UnlockMesh(
      this: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
      a4: &meshBuilder);
    v39 = 0;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
    v40 = alphatestedGroups.m_Size;
    m_pMemory = alphatestedGroups.m_Memory.m_pMemory;
    if ( alphatestedGroups.m_Size > 0 )
    {
      do
        Shader_DrawDynamicChain(
          pRenderContext,
          group: m_pMemory[v39++],
          (CMSurfaceSortList *)sortList,
          bShadowDepth: true);
      while ( v39 < v40 );
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
    if ( alphatestedGroups.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
  else if ( alphatestedGroups.m_Memory.m_nGrowSize >= 0 && alphatestedGroups.m_Memory.m_pMemory != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: alphatestedGroups.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D6E90
// Name: public: CWorldRenderList::CWorldRenderList(void)
// Source: json
//------------------------------------------------------------------------------
CWorldRenderList *__thiscall CWorldRenderList::CWorldRenderList(CWorldRenderList *this)
{
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *m_ShadowHandles; // ecx
  int i; // edx
  CUtlVector<msurface2_t *,CUtlMemory<msurface2_t *,int> > *m_DlightSurfaces; // ecx
  int j; // edx
  CUtlVector<msurface2_t *,CUtlMemory<msurface2_t *,int> > *m_PaintedSurfaces; // ecx
  int k; // edx

  this->m_iRefs = 1;
  this->CRefCounted1<IWorldRenderList,CRefCountServiceBase<1,CRefMT> >::IWorldRenderList::IRefCounted::__vftable = (CWorldRenderList_vtbl *)&args.m_pArgvBuffer[108];
  this->CRefCounted1<IWorldRenderList,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&args.m_pArgvBuffer[96];
  CMSurfaceSortList::CMSurfaceSortList(this: &this->m_SortList);
  CMSurfaceSortList::CMSurfaceSortList(this: &this->m_DispSortList);
  this->m_AlphaSurfaces.m_Memory.m_pMemory = nullptr;
  this->m_AlphaSurfaces.m_Memory.m_nAllocationCount = 0;
  this->m_AlphaSurfaces.m_Memory.m_nGrowSize = 0;
  this->m_AlphaSurfaces.m_Size = 0;
  this->m_AlphaSurfaces.m_pElements = nullptr;
  m_ShadowHandles = this->m_ShadowHandles;
  for ( i = 3; i >= 0; --i )
  {
    m_ShadowHandles->m_Memory.m_pMemory = nullptr;
    m_ShadowHandles->m_Memory.m_nAllocationCount = 0;
    m_ShadowHandles->m_Memory.m_nGrowSize = 0;
    m_ShadowHandles->m_Size = 0;
    m_ShadowHandles->m_pElements = nullptr;
    ++m_ShadowHandles;
  }
  m_DlightSurfaces = this->m_DlightSurfaces;
  for ( j = 3; j >= 0; --j )
  {
    m_DlightSurfaces->m_Memory.m_pMemory = nullptr;
    m_DlightSurfaces->m_Memory.m_nAllocationCount = 0;
    m_DlightSurfaces->m_Memory.m_nGrowSize = 0;
    m_DlightSurfaces->m_Size = 0;
    m_DlightSurfaces->m_pElements = nullptr;
    ++m_DlightSurfaces;
  }
  m_PaintedSurfaces = this->m_PaintedSurfaces;
  for ( k = 3; k >= 0; --k )
  {
    m_PaintedSurfaces->m_Memory.m_pMemory = nullptr;
    m_PaintedSurfaces->m_Memory.m_nAllocationCount = 0;
    m_PaintedSurfaces->m_Memory.m_nGrowSize = 0;
    m_PaintedSurfaces->m_Size = 0;
    m_PaintedSurfaces->m_pElements = nullptr;
    ++m_PaintedSurfaces;
  }
  this->m_leaves.m_Memory.m_pMemory = nullptr;
  this->m_leaves.m_Memory.m_nAllocationCount = 0;
  this->m_leaves.m_Memory.m_nGrowSize = 0;
  this->m_leaves.m_Size = 0;
  this->m_leaves.m_pElements = nullptr;
  *(_DWORD *)&this->m_VisitedSurfs.m_bits.m_numBits = 0;
  this->m_VisitedSurfs.m_bits.m_iBitStringStorage = 0;
  this->m_VisitedSurfs.m_bits.m_pInt = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100D6FB0
// Name: public: virtual bool CWorldRenderList::OnFinalRelease(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWorldRenderList::OnFinalRelease(CWorldRenderList *this)
{
  char *v1; // esi
  TSLNodeBase_t *v2; // eax

  v1 = (char *)this - 4;
  CWorldRenderList::Reset(this: (CWorldRenderList *)((char *)this - 4));
  v2 = (TSLNodeBase_t *)MemAlloc_Alloc(nSize: 8u);
  if ( v2 != nullptr )
  {
    *((_DWORD *)&v2->Next + 1) = v1;
    CTSListBase::Push(this: &CWorldRenderList::g_Pool.m_AvailableObjects, pNode: v2);
  }
  else
  {
    CTSListBase::Push(this: &CWorldRenderList::g_Pool.m_AvailableObjects, pNode: nullptr);
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x100D7000
// Name: public: virtual CWorldRenderList::~CWorldRenderList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorldRenderList::~CWorldRenderList(CWorldRenderList *this)
{
  CUtlVector<WorldListLeafData_t,CUtlMemory<WorldListLeafData_t,int> > *p_m_leaves; // esi
  int i; // ebx
  WorldListLeafData_t *m_pMemory; // eax
  CUtlVector<msurface2_t *,CUtlMemory<msurface2_t *,int> > *m_PaintedSurfaces; // esi
  int j; // ebx
  msurface2_t **v7; // eax
  CUtlVector<msurface2_t *,CUtlMemory<msurface2_t *,int> > *m_DlightSurfaces; // esi
  int k; // ebx
  msurface2_t **v10; // eax

  this->CRefCounted1<IWorldRenderList,CRefCountServiceBase<1,CRefMT> >::IWorldRenderList::IRefCounted::__vftable = (CWorldRenderList_vtbl *)&args.m_pArgvBuffer[108];
  this->CRefCounted1<IWorldRenderList,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&args.m_pArgvBuffer[96];
  CWorldRenderList::Purge(this);
  if ( this->m_VisitedSurfs.m_bits.m_numInts > 1u )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_VisitedSurfs.m_bits.m_pInt);
  this->m_VisitedSurfs.m_bits.m_pInt = nullptr;
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_leaves);
  p_m_leaves = &this->m_leaves;
  for ( i = 3; i >= 0; --i )
  {
    --p_m_leaves;
    p_m_leaves->m_Size = 0;
    if ( p_m_leaves->m_Memory.m_nGrowSize >= 0 )
    {
      if ( p_m_leaves->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_leaves->m_Memory.m_pMemory);
        p_m_leaves->m_Memory.m_pMemory = nullptr;
      }
      p_m_leaves->m_Memory.m_nAllocationCount = 0;
    }
    m_pMemory = p_m_leaves->m_Memory.m_pMemory;
    p_m_leaves->m_pElements = p_m_leaves->m_Memory.m_pMemory;
    if ( p_m_leaves->m_Memory.m_nGrowSize >= 0 )
    {
      if ( m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
        p_m_leaves->m_Memory.m_pMemory = nullptr;
      }
      p_m_leaves->m_Memory.m_nAllocationCount = 0;
    }
  }
  m_PaintedSurfaces = this->m_PaintedSurfaces;
  for ( j = 3; j >= 0; --j )
  {
    --m_PaintedSurfaces;
    m_PaintedSurfaces->m_Size = 0;
    if ( m_PaintedSurfaces->m_Memory.m_nGrowSize >= 0 )
    {
      if ( m_PaintedSurfaces->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_PaintedSurfaces->m_Memory.m_pMemory);
        m_PaintedSurfaces->m_Memory.m_pMemory = nullptr;
      }
      m_PaintedSurfaces->m_Memory.m_nAllocationCount = 0;
    }
    v7 = m_PaintedSurfaces->m_Memory.m_pMemory;
    m_PaintedSurfaces->m_pElements = m_PaintedSurfaces->m_Memory.m_pMemory;
    if ( m_PaintedSurfaces->m_Memory.m_nGrowSize >= 0 )
    {
      if ( v7 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v7);
        m_PaintedSurfaces->m_Memory.m_pMemory = nullptr;
      }
      m_PaintedSurfaces->m_Memory.m_nAllocationCount = 0;
    }
  }
  m_DlightSurfaces = this->m_DlightSurfaces;
  for ( k = 3; k >= 0; --k )
  {
    --m_DlightSurfaces;
    m_DlightSurfaces->m_Size = 0;
    if ( m_DlightSurfaces->m_Memory.m_nGrowSize >= 0 )
    {
      if ( m_DlightSurfaces->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_DlightSurfaces->m_Memory.m_pMemory);
        m_DlightSurfaces->m_Memory.m_pMemory = nullptr;
      }
      m_DlightSurfaces->m_Memory.m_nAllocationCount = 0;
    }
    v10 = m_DlightSurfaces->m_Memory.m_pMemory;
    m_DlightSurfaces->m_pElements = m_DlightSurfaces->m_Memory.m_pMemory;
    if ( m_DlightSurfaces->m_Memory.m_nGrowSize >= 0 )
    {
      if ( v10 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v10);
        m_DlightSurfaces->m_Memory.m_pMemory = nullptr;
      }
      m_DlightSurfaces->m_Memory.m_nAllocationCount = 0;
    }
  }
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_AlphaSurfaces);
  CMSurfaceSortList::~CMSurfaceSortList(this: &this->m_DispSortList);
  CMSurfaceSortList::~CMSurfaceSortList(this: &this->m_SortList);
}

//------------------------------------------------------------------------------
// Address: 0x100D71D0
// Name: Shader_DrawChainsStatic
// Source: json
//------------------------------------------------------------------------------
void __cdecl Shader_DrawChainsStatic(IMatRenderContext *pRenderContext, CMSurfaceSortList *sortList, bool bShadowDepth)
{
  int nSortGroup; // ecx
  int v4; // edi
  int v5; // ecx
  int v6; // edi
  int (__thiscall *GetMaxIndicesToRender)(IMatRenderContext *); // edx
  int v8; // esi
  msurface2_t *SurfaceAtHead; // eax
  int v10; // esi
  msurface2_t *v11; // ecx
  bool v12; // zf
  int v13; // eax
  int v14; // ebx
  unsigned int v15; // esi
  S3RGBA *v16; // edi
  S3RGBA *m_pMemory; // ecx
  int v18; // eax
  int *v19; // ecx
  int v20; // edi
  int materialSortID; // ebx
  int v22; // esi
  IMesh **v23; // ecx
  int v24; // eax
  IMesh *v25; // ecx
  int v26; // esi
  unsigned int v27; // ebx
  ResourceEntryInfo *v28; // ecx
  int v29; // eax
  int v30; // edx
  ResourceEntryInfo *v31; // eax
  int v32; // ecx
  __int16 v33; // ax
  int m_nCurrentIndex; // ebx
  worldbrushdata_t *worldbrush; // edi
  int v36; // eax
  char *v37; // esi
  bool v38; // cc
  int v39; // ecx
  unsigned __int16 firstPrimID; // ax
  __int16 v41; // cx
  int v42; // eax
  int v43; // edx
  signed int v44; // eax
  int v45; // esi
  unsigned __int16 *v46; // edx
  int v47; // esi
  signed int i; // edi
  IMaterial *material; // ecx
  char *v50; // eax
  int m_nVertexCount; // eax
  int v52; // esi
  int j; // eax
  int v54; // edx
  char v55; // bl
  int v56; // ecx
  int v57; // eax
  int v58; // esi
  IMaterial *v59; // eax
  void (__thiscall *BindBatch)(IMatRenderContext *, IMesh *, IMaterial *); // edx
  _WORD *v61; // esi
  IMatRenderContext *v62; // ebx
  unsigned __int16 *v63; // edi
  IMaterial *v64; // esi
  BOOL v65; // ebx
  IMaterial *v66; // edi
  IMaterialVar *v67; // ebx
  int v68; // eax
  IMaterial_vtbl *v69; // edx
  int v70; // eax
  IMaterial_vtbl *v71; // edx
  IMesh **v72; // esi
  int v73; // eax
  IMaterial_vtbl *v74; // edx
  ITexture *(__thiscall *GetTextureValue)(IMaterialVar *); // edx
  int v76; // eax
  int v77; // eax
  IMatRenderContext_vtbl *v78; // edx
  void (__thiscall *BindLightmapPage)(IMatRenderContext *, int); // eax
  int v80; // edx
  int k; // esi
  S3RGBA *v82; // eax
  ResourceEntryInfo *v83; // eax
  IMesh *v84; // [esp+64h] [ebp-1894h]
  float v85; // [esp+68h] [ebp-1890h]
  CUtlMemory<ResourceEntryInfo,int> v86; // [esp+78h] [ebp-1880h] BYREF
  int v87; // [esp+84h] [ebp-1874h]
  _BYTE v88[4096]; // [esp+88h] [ebp-1870h] BYREF
  int v89; // [esp+1088h] [ebp-870h]
  _DWORD v90[129]; // [esp+108Ch] [ebp-86Ch]
  _WORD v91[4]; // [esp+1290h] [ebp-668h] BYREF
  int v92; // [esp+1690h] [ebp-268h]
  _WORD *v93; // [esp+1694h] [ebp-264h]
  CMeshBuilder v94; // [esp+1698h] [ebp-260h] BYREF
  unsigned __int16 *v95; // [esp+1880h] [ebp-78h]
  CUtlMemory<S3RGBA,int> src; // [esp+1884h] [ebp-74h] BYREF
  int v97; // [esp+1890h] [ebp-68h]
  _BYTE v98[32]; // [esp+1894h] [ebp-64h] BYREF
  int v99; // [esp+18B4h] [ebp-44h]
  S3RGBA *v100; // [esp+18B8h] [ebp-40h]
  materiallist_t **v101; // [esp+18BCh] [ebp-3Ch]
  int nIndexCount; // [esp+18C0h] [ebp-38h]
  int v103; // [esp+18C4h] [ebp-34h]
  IMesh *v104; // [esp+18C8h] [ebp-30h]
  int v105; // [esp+18CCh] [ebp-2Ch]
  IMesh *v106; // [esp+18D0h] [ebp-28h]
  int v107; // [esp+18D4h] [ebp-24h]
  int v108; // [esp+18D8h] [ebp-20h]
  int v109; // [esp+18DCh] [ebp-1Ch]
  int v110; // [esp+18E0h] [ebp-18h]
  char *v111; // [esp+18E4h] [ebp-14h]
  int v112; // [esp+18E8h] [ebp-10h]
  int num; // [esp+18ECh] [ebp-Ch]
  int v114; // [esp+18F0h] [ebp-8h]
  char v115; // [esp+18F6h] [ebp-2h]
  bool v116; // [esp+18F7h] [ebp-1h]

  v4 = nSortGroup;
  v86.m_pMemory = (ResourceEntryInfo *)v88;
  v93 = v91;
  v90[0] = v88;
  src.m_pMemory = (S3RGBA *)v98;
  v92 = 0;
  v86.m_nAllocationCount = 512;
  v86.m_nGrowSize = -1;
  v87 = 0;
  v89 = 0;
  src.m_nAllocationCount = 8;
  src.m_nGrowSize = -1;
  v97 = 0;
  v99 = 0;
  v100 = (S3RGBA *)v98;
  v115 = 1;
  CMeshBuilder::CMeshBuilder(this: &v94);
  v116 = g_pMaterialSystemConfig->nFullbright == 1;
  v5 = 5 * v4 + 15;
  v6 = *(&sortList->m_list.m_Size + v5);
  v101 = &sortList->m_list.m_Memory.m_pMemory + v5;
  GetMaxIndicesToRender = pRenderContext->GetMaxIndicesToRender;
  v103 = v6;
  v108 = 0;
  nIndexCount = GetMaxIndicesToRender(this: pRenderContext);
  if ( v6 <= 0 )
    goto LABEL_97;
  do
  {
    v8 = v108;
    SurfaceAtHead = CMSurfaceSortList::GetSurfaceAtHead(
                      this: sortList,
                      group: *((const surfacesortgroup_t **)&(*v101)->nextBlock + v108));
    v104 = pRenderContext->GetDynamicMesh(
             this: pRenderContext,
             a2: 0,
             a3: g_WorldStaticMeshes.m_Memory.m_pMemory[SurfaceAtHead->materialSortID],
             a4: 0,
             a5: 0);
    CMeshBuilder::Begin(
      this: &v94,
      pMesh: v104,
      type: MATERIAL_TRIANGLES,
      nVertexCount: 0,
      nIndexCount,
      pMeshSettings: nullptr);
    v106 = nullptr;
    v112 = 0;
    v110 = -1;
    if ( v8 >= v103 )
      goto LABEL_54;
    while ( 1 )
    {
      v114 = *(&(*v101)->nextBlock + v108);
      v10 = v114;
      v11 = CMSurfaceSortList::GetSurfaceAtHead(this: sortList, group: (const surfacesortgroup_t *)v114);
      v12 = SLOBYTE(v11->flags) >= 0;
      v105 = (int)v11;
      if ( !v12 )
      {
        v13 = v99;
        v14 = v99;
        if ( v99 + 1 > src.m_nAllocationCount )
        {
          num = v99 - src.m_nAllocationCount + 1;
          if ( src.m_nGrowSize < 0 )
          {
            src.m_nGrowSize = v97;
            if ( src.m_nAllocationCount != 0 )
            {
              v15 = 4 * src.m_nAllocationCount;
              v16 = (S3RGBA *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * src.m_nAllocationCount);
              memcpy(dst: (unsigned __int8 *)v16, src: (unsigned __int8 *)src.m_pMemory, count: v15);
              v10 = v114;
              src.m_pMemory = v16;
            }
            else
            {
              src.m_pMemory = nullptr;
            }
          }
          CUtlMemory<INetMessage *,int>::Grow(this: &src, num);
          v13 = v99;
        }
        m_pMemory = src.m_pMemory;
        v99 = v13 + 1;
        v18 = v13 - v14;
        v100 = src.m_pMemory;
        if ( v18 > 0 )
        {
          _V_memmove(dest: &src.m_pMemory[v14 + 1], src: &src.m_pMemory[v14], count: 4 * v18);
          m_pMemory = src.m_pMemory;
        }
        v19 = (int *)&m_pMemory[v14];
        if ( v19 != nullptr )
          *v19 = v10;
        goto LABEL_46;
      }
      v20 = 3 * *(_DWORD *)(v10 + 24);
      if ( v20 + v112 > nIndexCount )
        break;
      materialSortID = v11->materialSortID;
      if ( g_WorldStaticMeshes.m_Memory.m_pMemory[materialSortID] == v106 )
      {
        v24 = v89;
      }
      else
      {
        if ( v92 >= 127 )
        {
          if ( v115 != 0 )
          {
            _DevWarning(a1: 2, a2: &args.m_pArgvBuffer[236]);
            v115 = 0;
          }
          goto LABEL_46;
        }
        v22 = v92++;
        v93 = v91;
        v23 = g_WorldStaticMeshes.m_Memory.m_pMemory;
        v91[4 * v22] = 0;
        v24 = v89;
        v91[4 * v22 + 1] = v89;
        v25 = v23[materialSortID];
        v110 = v22;
        v106 = v25;
        *(_DWORD *)&v91[4 * v22 + 2] = v25;
      }
      v26 = v24;
      if ( v24 + 1 > v86.m_nAllocationCount )
      {
        v107 = v24 - v86.m_nAllocationCount + 1;
        if ( v86.m_nGrowSize < 0 )
        {
          v86.m_nGrowSize = v87;
          if ( v86.m_nAllocationCount != 0 )
          {
            v27 = 8 * v86.m_nAllocationCount;
            num = (int)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 8 * v86.m_nAllocationCount);
            memcpy(dst: (unsigned __int8 *)num, src: (unsigned __int8 *)v86.m_pMemory, count: v27);
            v86.m_pMemory = (ResourceEntryInfo *)num;
          }
          else
          {
            v86.m_pMemory = nullptr;
          }
        }
        CUtlMemory<CAsyncWavDataCache::DeadBufferEntry_t,int>::Grow(this: &v86, num: v107);
        v24 = v89;
      }
      v28 = v86.m_pMemory;
      v89 = v24 + 1;
      v29 = v24 - v26;
      v90[0] = v86.m_pMemory;
      if ( v29 > 0 )
      {
        _V_memmove(dest: &v86.m_pMemory[v26 + 1], src: &v86.m_pMemory[v26], count: 8 * v29);
        v28 = v86.m_pMemory;
      }
      v30 = v105;
      v31 = &v28[v26];
      v32 = v112;
      LOWORD(v31->resData) = v112;
      v31->eType = v30;
      HIWORD(v31->resData) = v20;
      ++v91[4 * v110];
      v112 = (unsigned __int16)v20 + v32;
      v33 = *(_WORD *)v114;
      if ( *(_WORD *)v114 != 0xFFFF )
      {
        m_nCurrentIndex = v94.m_IndexBuilder.m_nCurrentIndex;
        worldbrush = host_state.worldbrush;
        do
        {
          v36 = v33 << 6;
          v37 = (char *)sortList->m_list.m_Memory.m_pMemory + v36;
          v38 = *((_DWORD *)v37 + 1) <= 0;
          num = v36;
          v111 = v37;
          v109 = 0;
          if ( !v38 )
          {
            v114 = (int)(v37 + 8);
            do
            {
              v39 = *(_DWORD *)v114;
              if ( (**(_DWORD **)v114 & 0x8000) != 0 )
              {
                if ( (**(_DWORD **)v114 & 0x800) != 0 )
                  firstPrimID = 0;
                else
                  firstPrimID = worldbrush->surfaces1[(signed int)(v39 - (unsigned int)worldbrush->surfaces2) >> 5].prims.firstPrimID;
                v41 = LOWORD(v94.m_IndexBuilder.m_nIndexOffset) + *(_WORD *)(v39 + 20);
                v42 = (int)&worldbrush->primitives[firstPrimID];
                v43 = *(unsigned __int16 *)(v42 + 4);
                v44 = v94.m_IndexBuilder.m_nIndexSize * *(unsigned __int16 *)(v42 + 6);
                v45 = (int)&worldbrush->primindices[v43];
                v46 = &v94.m_IndexBuilder.m_pIndices[m_nCurrentIndex];
                if ( v44 > 0 )
                {
                  v47 = v45 - (_DWORD)v46;
                  for ( i = v44; i != 0; --i )
                  {
                    *v46 = v41 + *(unsigned __int16 *)((char *)v46 + v47);
                    ++v46;
                  }
                  m_nCurrentIndex = v94.m_IndexBuilder.m_nCurrentIndex;
                  worldbrush = host_state.worldbrush;
                }
                v37 = v111;
                m_nCurrentIndex += v94.m_IndexBuilder.m_nIndexSize * v44;
                v94.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
                if ( m_nCurrentIndex > v94.m_IndexBuilder.m_nIndexCount )
                  v94.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
              }
              else
              {
                BuildIndicesForSurface(meshBuilder: &v94.m_IndexBuilder, surfID: *(msurface2_t **)v114);
                m_nCurrentIndex = v94.m_IndexBuilder.m_nCurrentIndex;
                worldbrush = host_state.worldbrush;
              }
              v114 += 4;
              ++v109;
            }
            while ( v109 < *((_DWORD *)v37 + 1) );
          }
          v33 = *(_WORD *)((char *)&sortList->m_list.m_Memory.m_pMemory->nextBlock + num);
        }
        while ( v33 != -1 );
      }
LABEL_46:
      if ( ++v108 >= v103 )
        goto LABEL_54;
    }
    if ( v20 <= nIndexCount )
    {
      v106 = nullptr;
    }
    else
    {
      material = materialSortInfoArray[v11->materialSortID].material;
      if ( material != nullptr )
        v50 = (char *)material->GetName(this: material);
      else
        v50 = &args.m_pArgvBuffer[228];
      DevMsg(a1: &args.m_pArgvBuffer[140], v50, v20, nIndexCount);
    }
LABEL_54:
    if ( v94.m_bGenerateIndices )
    {
      switch ( v94.m_Type )
      {
        case MATERIAL_LINE_STRIP:
          m_nVertexCount = 2 * v94.m_VertexBuilder.m_nVertexCount - 2;
          break;
        case MATERIAL_LINE_LOOP:
          m_nVertexCount = 2 * v94.m_VertexBuilder.m_nVertexCount;
          break;
        case MATERIAL_POLYGON:
          m_nVertexCount = 3 * v94.m_VertexBuilder.m_nVertexCount - 6;
          break;
        case MATERIAL_QUADS:
          m_nVertexCount = 6 * v94.m_VertexBuilder.m_nVertexCount / 4;
          break;
        case MATERIAL_INSTANCED_QUADS:
          m_nVertexCount = 0;
          break;
        default:
          m_nVertexCount = v94.m_VertexBuilder.m_nVertexCount;
          break;
      }
      CIndexBuilder::GenerateIndices(this: &v94.m_IndexBuilder, primitiveType: v94.m_Type, nIndexCount: m_nVertexCount);
    }
    v94.m_pMesh->UnlockMesh(
      this: v94.m_pMesh,
      a2: v94.m_VertexBuilder.m_nVertexCount,
      a3: v94.m_IndexBuilder.m_nIndexCount,
      a4: &v94);
    v52 = v92;
    v94.m_IndexBuilder.m_pIndexBuffer = nullptr;
    v94.m_IndexBuilder.m_nMaxIndexCount = 0;
    v94.m_VertexBuilder.m_nMaxVertexCount = 0;
    v94.m_VertexBuilder.m_pVertexBuffer = nullptr;
    v94.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    v94.m_pMesh = nullptr;
    num = v92;
    if ( (_S1_8 & 1) == 0 )
    {
      _S1_8 |= 1u;
      counter_1.m_pCounter = CVProfile::FindOrCreateCounter(
                               this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                               a2: &args.m_pArgvBuffer[116],
                               a3: COUNTER_GROUP_DEFAULT);
      atexit(func: Shader_DrawChainsStatic_::_37_::_dynamic_atexit_destructor_for___counter__);
    }
    *counter_1.m_pCounter += v52;
    for ( j = 0; j < v52; ++j )
      v90[j + 1] = j;
    do
    {
      v54 = 1;
      v55 = 0;
      if ( v52 <= 1 )
        break;
      do
      {
        v56 = v90[v54 + 1];
        v57 = v90[v54];
        if ( *(_DWORD *)&v91[4 * v56 + 2] < *(_DWORD *)&v91[4 * v57 + 2] )
        {
          v90[v54] = v56;
          v90[v54 + 1] = v57;
          v55 = 1;
        }
        ++v54;
      }
      while ( v54 < v52 );
    }
    while ( v55 != 0 );
    pRenderContext->BeginBatch(this: pRenderContext, a2: v104);
    v112 = 0;
    if ( v52 > 0 )
    {
      do
      {
        v58 = v90[v112 + 1];
        v59 = materialSortInfoArray[*(__int16 *)(v86.m_pMemory[(unsigned __int16)v91[4 * v58 + 1]].eType + 18)].material;
        BindBatch = pRenderContext->BindBatch;
        v61 = &v91[4 * v58];
        v84 = *((IMesh **)v61 + 1);
        v107 = (int)v61;
        BindBatch(this: pRenderContext, a2: v84, a3: v59);
        v114 = 0;
        if ( *v61 != 0 )
        {
          v62 = pRenderContext;
          do
          {
            v63 = (unsigned __int16 *)&v86.m_pMemory[v114 + *(unsigned __int16 *)(v107 + 2)];
            v64 = materialSortInfoArray[*(__int16 *)(*(_DWORD *)v63 + 18)].material;
            v95 = v63;
            if ( bShadowDepth )
            {
              v65 = v64->IsAlphaTested(this: v64);
              v66 = g_pMaterialDepthWrite[v65][(unsigned __int8)v64->IsTwoSided(this: v64)];
              if ( v65 )
              {
                v67 = v64->FindVarFast(this: v64, a2: "$basetexture", a3: &originalTextureVarCache_3);
                v68 = (int)v64->FindVarFast(this: v64, a2: "$frame", a3: &originalTextureFrameVarCache_3);
                v69 = v64->__vftable;
                v109 = v68;
                v70 = (int)v69->FindVarFast(this: v64, a2: "$AlphaTestReference", a3: &originalAlphaRefCache_3);
                v71 = v66->__vftable;
                v110 = v70;
                v72 = (IMesh **)v71->FindVarFast(this: v66, a2: "$basetexture", a3: &textureVarCache_3);
                v73 = (int)v66->FindVarFast(this: v66, a2: "$frame", a3: &textureFrameVarCache_3);
                v74 = v66->__vftable;
                v111 = (char *)v73;
                v105 = (int)v74->FindVarFast(this: v66, a2: "$AlphaTestReference", a3: &alphaRefCache_3);
                if ( v72 != nullptr && v67 != nullptr )
                {
                  GetTextureValue = v67->GetTextureValue;
                  v104 = *v72;
                  v76 = (int)GetTextureValue(this: v67);
                  ((void (__thiscall *)(IMesh **, int))v104[7].IIndexBuffer::__vftable)(a1: v72, a2: v76);
                }
                if ( v111 != nullptr && v109 != 0 )
                {
                  v77 = (*(int (__thiscall **)(int))(*(_DWORD *)v109 + 108))(a1: v109);
                  (*(void (__thiscall **)(char *, int))(*(_DWORD *)v111 + 20))(a1: v111, a2: v77);
                }
                if ( v105 != 0 && v110 != 0 )
                {
                  v85 = ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v110 + 112))(a1: v110);
                  (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v105 + 16))(a1: LODWORD(v85));
                }
              }
              v62 = pRenderContext;
              pRenderContext->Bind(this: pRenderContext, a2: v66, a3: nullptr);
              v63 = v95;
            }
            else
            {
              v62->Bind(this: v62, a2: v64, a3: nullptr);
              v78 = v62->__vftable;
              if ( v116 )
              {
                BindLightmapPage = v78->BindLightmapPage;
                if ( (**(_BYTE **)v63 & 8) != 0 )
                  BindLightmapPage(this: v62, a2: -2);
                else
                  BindLightmapPage(this: v62, a2: -1);
              }
              else
              {
                v78->BindLightmapPage(
                  this: v62,
                  a2: materialSortInfoArray[*(__int16 *)(*(_DWORD *)v63 + 18)].lightmapPageID);
              }
            }
            v62->DrawBatch(this: v62, a2: MATERIAL_TRIANGLES, a3: v63[2], a4: v63[3]);
            v80 = *(unsigned __int16 *)v107;
            ++v114;
          }
          while ( v114 < v80 );
        }
        ++v112;
      }
      while ( v112 < num );
    }
    pRenderContext->EndBatch(this: pRenderContext);
    if ( v106 != nullptr )
      break;
    if ( num == 0 )
      break;
    v92 = 0;
    v89 = 0;
  }
  while ( v108 < v103 );
LABEL_97:
  for ( k = 0; k < v99; ++k )
    Shader_DrawDynamicChain(
      pRenderContext,
      group: *(const surfacesortgroup_t **)&src.m_pMemory[k],
      sortList,
      bShadowDepth);
  if ( v94.m_VertexBuilder.m_pVertexBuffer != nullptr
    && v94.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: v94.m_VertexBuilder.m_pVertexBuffer) )
  {
    v94.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: v94.m_VertexBuilder.m_pVertexBuffer);
  }
  if ( v94.m_IndexBuilder.m_pIndexBuffer != nullptr
    && v94.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: v94.m_IndexBuilder.m_pIndexBuffer) )
  {
    v94.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: v94.m_IndexBuilder.m_pIndexBuffer);
  }
  v82 = src.m_pMemory;
  v99 = 0;
  if ( src.m_nGrowSize >= 0 )
  {
    if ( src.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_pMemory);
      v82 = nullptr;
      src.m_pMemory = nullptr;
    }
    src.m_nAllocationCount = 0;
  }
  v100 = v82;
  if ( src.m_nGrowSize >= 0 )
  {
    if ( v82 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v82);
      src.m_pMemory = nullptr;
    }
    src.m_nAllocationCount = 0;
  }
  v83 = v86.m_pMemory;
  v89 = 0;
  if ( v86.m_nGrowSize >= 0 )
  {
    if ( v86.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v86.m_pMemory);
      v83 = nullptr;
      v86.m_pMemory = nullptr;
    }
    v86.m_nAllocationCount = 0;
  }
  v90[0] = v83;
  if ( v86.m_nGrowSize >= 0 && v83 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v83);
}

//------------------------------------------------------------------------------
// Address: 0x100D7C60
// Name: Shader_DrawChains
// Source: json
//------------------------------------------------------------------------------
void __usercall Shader_DrawChains(
        CMeshBuilder *pRenderContext@<esi>,
        int a2@<edi>,
        const CWorldRenderList *pRenderList,
        int nSortGroup,
        bool bShadowDepth)
{
  int v5; // edi
  char *v6; // eax
  int v7; // edi
  IMatRenderContext_vtbl *m_VertexSize_Position; // edx
  void (__thiscall *BindLightmapPage)(IMatRenderContext *, int); // eax
  int v10; // eax
  int v11; // ecx
  msurface2_t **m_pMemory; // eax
  bool v13; // cc
  msurface2_t **v14; // eax
  const surfacesortgroup_t *v15; // [esp-4h] [ebp-28h]
  const surfacesortgroup_t *v16; // [esp-4h] [ebp-28h]
  CUtlVector<msurface2_t *,CUtlMemory<msurface2_t *,int> > surfList; // [esp+8h] [ebp-1Ch] BYREF
  int _count; // [esp+1Ch] [ebp-8h]
  int i; // [esp+20h] [ebp-4h]
  int _listIndex; // [esp+34h] [ebp+10h]
  int _listIndexa; // [esp+34h] [ebp+10h]

  if ( mat_forcedynamic.m_pParent != nullptr && mat_forcedynamic.m_pParent->m_Value.m_nValue != 0
    || g_pMaterialSystemConfig->bDrawFlat )
  {
    if ( g_VBAllocTracker != nullptr )
      g_VBAllocTracker->TrackMeshAllocations(this: g_VBAllocTracker, a2: &args.m_pArgvBuffer[304]);
    Shader_DrawChainsDynamic(
      m_nIndexCount: a2,
      p_meshBuilder: pRenderContext,
      (IMatRenderContext *)pRenderContext,
      sortList: &pRenderList->m_SortList,
      nSortGroup,
      bShadowDepth);
    v5 = nSortGroup;
  }
  else
  {
    if ( g_VBAllocTracker != nullptr )
      g_VBAllocTracker->TrackMeshAllocations(this: g_VBAllocTracker, a2: &args.m_pArgvBuffer[332]);
    v5 = nSortGroup;
    Shader_DrawChainsStatic((IMatRenderContext *)pRenderContext, sortList: &pRenderList->m_SortList, bShadowDepth);
  }
  if ( g_VBAllocTracker != nullptr )
    g_VBAllocTracker->TrackMeshAllocations(this: g_VBAllocTracker, a2: nullptr);
  if ( r_hidepaintedsurfaces.m_pParent == nullptr || r_hidepaintedsurfaces.m_pParent->m_Value.m_nValue == 0 )
  {
    (*(void (__thiscall **)(CMeshBuilder *, int))(pRenderContext->m_VertexSize_Position + 792))(
      a1: pRenderContext,
      a2: 1);
    v6 = (char *)pRenderList + 20 * v5;
    i = 0;
    _count = (int)v6;
    if ( *((int *)v6 + 147) > 0 )
    {
      while ( 1 )
      {
        v7 = *(_DWORD *)(*((_DWORD *)v6 + 144) + 4 * i);
        (*(void (__thiscall **)(CMeshBuilder *, IMaterial *, _DWORD))(pRenderContext->m_VertexSize_Position + 36))(
          a1: pRenderContext,
          a2: host_state.worldbrush->texinfo[*(unsigned __int16 *)(v7 + 22) >> 1].material,
          a3: 0);
        m_VertexSize_Position = (IMatRenderContext_vtbl *)pRenderContext->m_VertexSize_Position;
        if ( g_pMaterialSystemConfig->nFullbright == 1 )
        {
          BindLightmapPage = m_VertexSize_Position->BindLightmapPage;
          if ( (*(_BYTE *)v7 & 8) != 0 )
            BindLightmapPage(this: (IMatRenderContext *)pRenderContext, a2: -2);
          else
            BindLightmapPage(this: (IMatRenderContext *)pRenderContext, a2: -1);
        }
        else
        {
          m_VertexSize_Position->BindLightmapPage(
            this: (IMatRenderContext *)pRenderContext,
            a2: materialSortInfoArray[*(__int16 *)(v7 + 18)].lightmapPageID);
        }
        Shader_DrawSurfaceDynamic((IMatRenderContext *)pRenderContext, surfID: (msurface2_t *)v7);
        if ( ++i >= *(_DWORD *)(_count + 588) )
          break;
        v6 = (char *)_count;
      }
      v5 = nSortGroup;
    }
    (*(void (__thiscall **)(CMeshBuilder *, _DWORD))(pRenderContext->m_VertexSize_Position + 792))(
      a1: pRenderContext,
      a2: 0);
  }
  if ( !bShadowDepth && g_ShaderDebug.anydebug )
  {
    v10 = 4 * (5 * v5 + 15);
    v11 = *(int *)((char *)&pRenderList->m_SortList.m_list.m_Size + v10);
    i = v10;
    _count = v11;
    _listIndex = 0;
    if ( v11 > 0 )
    {
      do
      {
        v15 = (const surfacesortgroup_t *)*(&(*(materiallist_t **)((char *)&pRenderList->m_SortList.m_list.m_Memory.m_pMemory
                                                                 + v10))->nextBlock
                                          + _listIndex);
        memset(&surfList, 0, sizeof(surfList));
        CMSurfaceSortList::GetSurfaceListForGroup(
          this: &pRenderList->m_SortList,
          list: (CUtlMemory<S3RGBA,int> *)&surfList,
          group: v15);
        DrawDebugInformation(
          (IMatRenderContext *)pRenderContext,
          pList: surfList.m_Memory.m_pMemory,
          listCount: surfList.m_Size);
        m_pMemory = surfList.m_Memory.m_pMemory;
        surfList.m_Size = 0;
        if ( surfList.m_Memory.m_nGrowSize >= 0 )
        {
          if ( surfList.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: surfList.m_Memory.m_pMemory);
            m_pMemory = nullptr;
            surfList.m_Memory.m_pMemory = nullptr;
          }
          surfList.m_Memory.m_nAllocationCount = 0;
        }
        surfList.m_pElements = m_pMemory;
        if ( surfList.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
        v13 = ++_listIndex < _count;
        v10 = i;
      }
      while ( v13 );
    }
    _count = *(int *)((char *)&pRenderList->m_DispSortList.m_list.m_Size + v10);
    _listIndexa = 0;
    if ( _count > 0 )
    {
      while ( 1 )
      {
        v16 = (const surfacesortgroup_t *)*(&(*(materiallist_t **)((char *)&pRenderList->m_DispSortList.m_list.m_Memory.m_pMemory
                                                                 + v10))->nextBlock
                                          + _listIndexa);
        memset(&surfList, 0, sizeof(surfList));
        CMSurfaceSortList::GetSurfaceListForGroup(
          this: &pRenderList->m_DispSortList,
          list: (CUtlMemory<S3RGBA,int> *)&surfList,
          group: v16);
        DispInfo_RenderListDebug(
          (IMatRenderContext *)pRenderContext,
          pList: surfList.m_Memory.m_pMemory,
          listCount: (CMeshBuilder *)surfList.m_Size);
        v14 = surfList.m_Memory.m_pMemory;
        surfList.m_Size = 0;
        if ( surfList.m_Memory.m_nGrowSize >= 0 )
        {
          if ( surfList.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: surfList.m_Memory.m_pMemory);
            v14 = nullptr;
            surfList.m_Memory.m_pMemory = nullptr;
          }
          surfList.m_Memory.m_nAllocationCount = 0;
        }
        surfList.m_pElements = v14;
        if ( surfList.m_Memory.m_nGrowSize >= 0 && v14 != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v14);
        if ( ++_listIndexa >= _count )
          break;
        v10 = i;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D7F50
// Name: Shader_WorldEnd
// Source: json
//------------------------------------------------------------------------------
void __usercall Shader_WorldEnd(
        IMatRenderContext *pRenderContext@<eax>,
        CWorldRenderList *pRenderList,
        unsigned int flags,
        float waterZAdjust)
{
  MaterialHeightClipMode_t v6; // edi
  int *v7; // eax
  int v8; // edi
  MaterialHeightClipMode_t v9; // edi
  float zFar; // [esp+28h] [ebp-1Ch]
  float zFara; // [esp+28h] [ebp-1Ch]
  float zFarb; // [esp+28h] [ebp-1Ch]
  float zFarc; // [esp+28h] [ebp-1Ch]
  char *v14; // [esp+3Ch] [ebp-8h]
  bool bFlashlightMask; // [esp+40h] [ebp-4h]
  unsigned int flagsa; // [esp+50h] [ebp+Ch]

  if ( (flags & 0x40) != 0 )
  {
    Shader_WorldShadowDepthFill(pRenderContext, pRenderList, flags);
  }
  else
  {
    if ( (r_skybox_draw_last.m_pParent == nullptr || r_skybox_draw_last.m_pParent->m_Value.m_nValue == 0)
      && (flags & 0x10) != 0
      && (pRenderList->m_bSkyVisible || Map_VisForceFullSky()) )
    {
      if ( (flags & 0x20) != 0 )
      {
        zFar = g_EngineRenderer->GetZFar(this: g_EngineRenderer);
        R_DrawSkyBox(zFar, nDrawFlags: 63);
      }
      else
      {
        v6 = pRenderContext->GetHeightClipMode(this: pRenderContext);
        pRenderContext->SetHeightClipMode(this: pRenderContext, a2: MATERIAL_HEIGHTCLIPMODE_DISABLE);
        zFara = g_EngineRenderer->GetZFar(this: g_EngineRenderer);
        R_DrawSkyBox(zFar: zFara, nDrawFlags: 63);
        pRenderContext->SetHeightClipMode(this: pRenderContext, a2: v6);
      }
    }
    if ( r_fastzreject.m_pParent != nullptr && r_fastzreject.m_pParent->m_Value.m_nValue != 0 )
      Shader_WorldZFill(pRenderList, pRenderContext, flags);
    v7 = (int *)&args.m_pArgSBuffer[200];
    flagsa = 8;
    v14 = &args.m_pArgSBuffer[200];
    do
    {
      if ( (flags & flagsa) != 0 )
      {
        v8 = *v7;
        if ( *v7 == 3 )
        {
          if ( waterZAdjust != 0.0 )
          {
            pRenderContext->MatrixMode(this: pRenderContext, a2: MATERIAL_MODEL);
            pRenderContext->PushMatrix(this: pRenderContext);
            pRenderContext->LoadIdentity(this: pRenderContext);
            ((void (__thiscall *)(IMatRenderContext *, _DWORD, _DWORD, _DWORD))pRenderContext->Translate)(
              a1: pRenderContext,
              a2: 0.0,
              a3: 0.0,
              a4: LODWORD(waterZAdjust));
          }
          g_pShadowMgr->PushSinglePassFlashlightStateEnabled(this: g_pShadowMgr, a2: true);
        }
        if ( (flags & 0x80u) != 0 || (bFlashlightMask = true, (flags & 0x100) != 0) )
          bFlashlightMask = false;
        g_pShadowMgr->SetFlashlightStencilMasks(this: g_pShadowMgr, a2: bFlashlightMask);
        Shader_DrawDispChain(
          pRenderContext,
          nSortGroup: v8,
          list: &pRenderList->m_DispSortList,
          flags,
          bShadowDepth: nullptr);
        Shader_DrawChains((CMeshBuilder *)pRenderContext, a2: v8, pRenderList, nSortGroup: v8, bShadowDepth: false);
        if ( v8 == 3 )
        {
          g_pShadowMgr->PopSinglePassFlashlightStateEnabled(this: g_pShadowMgr);
          if ( waterZAdjust != 0.0 )
          {
            pRenderContext->MatrixMode(this: pRenderContext, a2: MATERIAL_MODEL);
            pRenderContext->PopMatrix(this: pRenderContext);
          }
        }
      }
      v7 = (int *)(v14 - 4);
      v14 = (char *)v7;
      flagsa = __ROR4__(flagsa, 1);
    }
    while ( (int)v7 >= (int)&args.m_pArgSBuffer[188] );
    if ( r_skybox_draw_last.m_pParent != nullptr
      && r_skybox_draw_last.m_pParent->m_Value.m_nValue != 0
      && (flags & 0x10) != 0
      && (pRenderList->m_bSkyVisible || Map_VisForceFullSky()) )
    {
      if ( (flags & 0x20) != 0 )
      {
        zFarb = g_EngineRenderer->GetZFar(this: g_EngineRenderer);
        R_DrawSkyBox(zFar: zFarb, nDrawFlags: 63);
      }
      else
      {
        v9 = pRenderContext->GetHeightClipMode(this: pRenderContext);
        pRenderContext->SetHeightClipMode(this: pRenderContext, a2: MATERIAL_HEIGHTCLIPMODE_DISABLE);
        zFarc = g_EngineRenderer->GetZFar(this: g_EngineRenderer);
        R_DrawSkyBox(zFar: zFarc, nDrawFlags: 63);
        pRenderContext->SetHeightClipMode(this: pRenderContext, a2: v9);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D81F0
// Name: void Shader_DrawTranslucentSurfaces(class IMatRenderContext __near *,class IWorldRenderList __near *,int __near *,int,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __usercall Shader_DrawTranslucentSurfaces(
        int a1@<ebx>,
        int a2@<edi>,
        IMatRenderContext *pRenderContext,
        IWorldRenderList *pRenderListIn,
        int *pSortList,
        int sortCount,
        unsigned int flags)
{
  transsurfacebatch_t *v7; // esi
  bool v8; // zf
  unsigned int v9; // ebx
  int m_nAllocationCount; // edi
  int v11; // ecx
  int m_Size; // eax
  int v13; // edx
  IWorldRenderList_vtbl *v14; // edx
  int Release_low; // ebx
  int v16; // edx
  int v17; // ebx
  int v18; // esi
  unsigned int v19; // edi
  unsigned __int8 *v20; // ebx
  int v21; // eax
  int v22; // edx
  IMaterial *material; // eax
  msurface2_t *v24; // edi
  int v25; // edx
  int v26; // esi
  unsigned int v27; // edi
  unsigned __int8 *v28; // ebx
  msurface2_t **m_pMemory; // ecx
  int v30; // edx
  msurface2_t **v31; // esi
  int v32; // edx
  int v33; // ebx
  unsigned int v34; // esi
  unsigned __int8 *v35; // edi
  msurface2_t **v36; // ecx
  int v37; // edx
  msurface2_t **v38; // eax
  msurface2_t *v39; // edi
  int v40; // ecx
  int v41; // esi
  unsigned int v42; // edi
  unsigned __int8 *v43; // ebx
  msurface2_t **v44; // edx
  msurface2_t **v45; // eax
  _DWORD *v46; // esi
  msurface2_t *v47; // ebx
  int v48; // eax
  msurface2_t *v49; // edi
  int v50; // esi
  IOverlayMgr *v51; // eax
  IOverlayMgr *v52; // eax
  IOverlayMgr *v53; // eax
  int v54; // ecx
  int v55; // esi
  BOOL v56; // esi
  msurface2_t **v57; // edi
  int v58; // esi
  int v59; // ebx
  int v60; // eax
  IWorldRenderList_vtbl *v61; // ecx
  int v62; // edx
  int v63; // ecx
  int v64; // eax
  _DWORD *v65; // ecx
  int v66; // edx
  int v67; // ebx
  unsigned int v68; // esi
  unsigned __int8 *v69; // edi
  int *v70; // ecx
  int v71; // esi
  const CViewSetup *v72; // eax
  int v73; // esi
  msurface2_t **v74; // edi
  const CViewSetup *v75; // eax
  transsurfacebatch_t *v76; // eax
  msurface2_t **v77; // eax
  msurface2_t **v78; // eax
  msurface2_t **v79; // eax
  CUtlVectorFixedGrowable<transsurfacebatch_t,16> batches; // [esp+4h] [ebp-2E4h] BYREF
  CUtlVectorFixedGrowable<msurface2_t *,16> surfaceList; // [esp+15Ch] [ebp-18Ch] BYREF
  CUtlVectorFixedGrowable<msurface2_t *,16> flashlightSurfaceList; // [esp+1B4h] [ebp-134h] BYREF
  CUtlVectorFixedGrowable<msurface2_t *,16> decalSurfaceList; // [esp+20Ch] [ebp-DCh] BYREF
  CUtlVectorFixedGrowable<msurface2_t *,16> dispList; // [esp+264h] [ebp-84h] BYREF
  int surfaceIndexStart; // [esp+2BCh] [ebp-2Ch]
  int j; // [esp+2C0h] [ebp-28h]
  transsurfacebatch_t *pLastBatch; // [esp+2C4h] [ebp-24h]
  int v90; // [esp+2C8h] [ebp-20h]
  int bFlashlightMask; // [esp+2CCh] [ebp-1Ch]
  int sortID; // [esp+2D0h] [ebp-18h]
  int i; // [esp+2D4h] [ebp-14h]
  bool skipLight; // [esp+2DBh] [ebp-Dh]
  int leaf; // [esp+2DCh] [ebp-Ch]
  int mask; // [esp+2E0h] [ebp-8h]
  bool bHasDisp; // [esp+2E7h] [ebp-1h]

  v7 = nullptr;
  if ( r_drawtranslucentworld.m_pParent != nullptr && r_drawtranslucentworld.m_pParent->m_Value.m_nValue != 0 )
  {
    v8 = g_pMaterialSystemConfig->nFullbright == 1;
    skipLight = false;
    if ( v8 )
    {
      pRenderContext->BindLightmapPage(this: pRenderContext, a2: -2);
      skipLight = true;
    }
    surfaceList.m_pElements = surfaceList.m_Memory.m_pFixedMemory;
    decalSurfaceList.m_pElements = decalSurfaceList.m_Memory.m_pFixedMemory;
    surfaceList.m_Memory.m_pMemory = surfaceList.m_Memory.m_pFixedMemory;
    flashlightSurfaceList.m_Memory.m_pMemory = flashlightSurfaceList.m_Memory.m_pFixedMemory;
    flashlightSurfaceList.m_pElements = flashlightSurfaceList.m_Memory.m_pFixedMemory;
    v9 = flags;
    m_nAllocationCount = 16;
    surfaceList.m_Memory.m_nGrowSize = -1;
    decalSurfaceList.m_Memory.m_pMemory = decalSurfaceList.m_Memory.m_pFixedMemory;
    decalSurfaceList.m_Memory.m_nGrowSize = -1;
    v11 = 0;
    flashlightSurfaceList.m_Memory.m_nGrowSize = -1;
    dispList.m_Memory.m_pMemory = dispList.m_Memory.m_pFixedMemory;
    dispList.m_Memory.m_nGrowSize = -1;
    dispList.m_pElements = dispList.m_Memory.m_pFixedMemory;
    batches.m_Memory.m_nGrowSize = -1;
    m_Size = 0;
    surfaceList.m_Memory.m_nAllocationCount = 16;
    surfaceList.m_Memory.m_nMallocGrowSize = 0;
    surfaceList.m_Size = 0;
    decalSurfaceList.m_Memory.m_nAllocationCount = 16;
    decalSurfaceList.m_Memory.m_nMallocGrowSize = 0;
    decalSurfaceList.m_Size = 0;
    flashlightSurfaceList.m_Memory.m_nAllocationCount = 16;
    flashlightSurfaceList.m_Memory.m_nMallocGrowSize = 0;
    flashlightSurfaceList.m_Size = 0;
    dispList.m_Memory.m_nAllocationCount = 16;
    dispList.m_Memory.m_nMallocGrowSize = 0;
    dispList.m_Size = 0;
    batches.m_Memory.m_pMemory = batches.m_Memory.m_pFixedMemory;
    batches.m_Memory.m_nAllocationCount = 16;
    batches.m_Memory.m_nMallocGrowSize = 0;
    batches.m_Size = 0;
    batches.m_pElements = batches.m_Memory.m_pFixedMemory;
    pLastBatch = nullptr;
    if ( (flags & 0x80u) != 0 || (LOBYTE(bFlashlightMask) = 1, (flags & 0x100) != 0) )
      LOBYTE(bFlashlightMask) = 0;
    bHasDisp = false;
    i = 0;
    mask = 1;
    do
    {
      if ( (v9 & mask) != 0 )
      {
        v13 = 0;
        leaf = 0;
        if ( sortCount > 0 )
        {
          do
          {
            v14 = &pRenderListIn[164].__vftable[pSortList[v13]];
            Release_low = LOWORD(v14->Release);
            v16 = HIWORD(v14->Release) + Release_low - 1;
            surfaceIndexStart = Release_low;
            for ( j = v16; v16 >= surfaceIndexStart; j = v16 )
            {
              v90 = *((_DWORD *)&pRenderListIn[99].AddRef + v16);
              if ( ((*(_DWORD *)v90 >> 22) & 3) == i )
              {
                if ( *(_DWORD *)(v90 + 24) == 0 )
                {
                  v17 = *(__int16 *)(v90 + 18);
                  sortID = v17;
                  if ( v7 == nullptr || v17 != v7->sortID )
                  {
                    v18 = m_Size;
                    if ( m_Size + 1 > m_nAllocationCount )
                    {
                      pLastBatch = (transsurfacebatch_t *)(m_Size - m_nAllocationCount + 1);
                      if ( batches.m_Memory.m_nGrowSize < 0 )
                      {
                        batches.m_Memory.m_nGrowSize = batches.m_Memory.m_nMallocGrowSize;
                        if ( m_nAllocationCount != 0 )
                        {
                          v19 = 20 * m_nAllocationCount;
                          v20 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v19);
                          memcpy(dst: v20, src: (unsigned __int8 *)batches.m_Memory.m_pMemory, count: v19);
                          batches.m_Memory.m_pMemory = (transsurfacebatch_t *)v20;
                          v17 = sortID;
                        }
                        else
                        {
                          batches.m_Memory.m_pMemory = nullptr;
                        }
                      }
                      CUtlMemory<UtlRBTreeNode_t<void *,int>,int>::Grow(
                        this: (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)&batches,
                        num: (int)pLastBatch);
                      m_Size = batches.m_Size;
                    }
                    batches.m_Size = m_Size + 1;
                    v21 = m_Size - v18;
                    batches.m_pElements = batches.m_Memory.m_pMemory;
                    if ( v21 > 0 )
                      _V_memmove(
                        dest: &batches.m_Memory.m_pMemory[v18 + 1],
                        src: &batches.m_Memory.m_pMemory[v18],
                        count: 20 * v21);
                    v7 = &batches.m_Memory.m_pMemory[v18];
                    v22 = v90;
                    v7->firstSurface = surfaceList.m_Size;
                    v7->surfaceCount = 0;
                    material = host_state.worldbrush->texinfo[*(unsigned __int16 *)(v22 + 22) >> 1].material;
                    pLastBatch = v7;
                    v7->pMaterial = material;
                    v7->sortID = v17;
                    v7->triangleCount = 0;
                  }
                  ++v7->surfaceCount;
                  v24 = (msurface2_t *)v90;
                  v7->triangleCount += *(unsigned __int8 *)(v90 + 3) - 2;
                  v25 = surfaceList.m_Size;
                  v26 = surfaceList.m_Size;
                  if ( surfaceList.m_Size + 1 > surfaceList.m_Memory.m_nAllocationCount )
                  {
                    sortID = surfaceList.m_Size - surfaceList.m_Memory.m_nAllocationCount + 1;
                    if ( surfaceList.m_Memory.m_nGrowSize < 0 )
                    {
                      surfaceList.m_Memory.m_nGrowSize = surfaceList.m_Memory.m_nMallocGrowSize;
                      if ( surfaceList.m_Memory.m_nAllocationCount != 0 )
                      {
                        v27 = 4 * surfaceList.m_Memory.m_nAllocationCount;
                        v28 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(
                                                   this: _g_pMemAlloc,
                                                   a2: 4 * surfaceList.m_Memory.m_nAllocationCount);
                        memcpy(dst: v28, src: (unsigned __int8 *)surfaceList.m_Memory.m_pMemory, count: v27);
                        v24 = (msurface2_t *)v90;
                        surfaceList.m_Memory.m_pMemory = (msurface2_t **)v28;
                      }
                      else
                      {
                        surfaceList.m_Memory.m_pMemory = nullptr;
                      }
                    }
                    CUtlMemory<INetMessage *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&surfaceList, num: sortID);
                    v25 = surfaceList.m_Size;
                  }
                  m_pMemory = surfaceList.m_Memory.m_pMemory;
                  v30 = v25 + 1;
                  surfaceList.m_Size = v30;
                  surfaceList.m_pElements = surfaceList.m_Memory.m_pMemory;
                  if ( v30 - v26 - 1 > 0 )
                  {
                    _V_memmove(
                      dest: &surfaceList.m_Memory.m_pMemory[v26 + 1],
                      src: &surfaceList.m_Memory.m_pMemory[v26],
                      count: 4 * (v30 - v26 - 1));
                    m_pMemory = surfaceList.m_Memory.m_pMemory;
                  }
                  v31 = &m_pMemory[v26];
                  if ( v31 != nullptr )
                    *v31 = v24;
                  if ( v24->m_ShadowDecals != 0xFFFF )
                  {
                    v32 = flashlightSurfaceList.m_Size;
                    v33 = flashlightSurfaceList.m_Size;
                    if ( flashlightSurfaceList.m_Size + 1 > flashlightSurfaceList.m_Memory.m_nAllocationCount )
                    {
                      sortID = flashlightSurfaceList.m_Size - flashlightSurfaceList.m_Memory.m_nAllocationCount + 1;
                      if ( flashlightSurfaceList.m_Memory.m_nGrowSize < 0 )
                      {
                        flashlightSurfaceList.m_Memory.m_nGrowSize = flashlightSurfaceList.m_Memory.m_nMallocGrowSize;
                        if ( flashlightSurfaceList.m_Memory.m_nAllocationCount != 0 )
                        {
                          v34 = 4 * flashlightSurfaceList.m_Memory.m_nAllocationCount;
                          v35 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(
                                                     this: _g_pMemAlloc,
                                                     a2: 4 * flashlightSurfaceList.m_Memory.m_nAllocationCount);
                          memcpy(dst: v35, src: (unsigned __int8 *)flashlightSurfaceList.m_Memory.m_pMemory, count: v34);
                          flashlightSurfaceList.m_Memory.m_pMemory = (msurface2_t **)v35;
                        }
                        else
                        {
                          flashlightSurfaceList.m_Memory.m_pMemory = nullptr;
                        }
                      }
                      CUtlMemory<INetMessage *,int>::Grow(
                        this: (CUtlMemory<S3RGBA,int> *)&flashlightSurfaceList,
                        num: sortID);
                      v32 = flashlightSurfaceList.m_Size;
                    }
                    v36 = flashlightSurfaceList.m_Memory.m_pMemory;
                    v37 = v32 + 1;
                    flashlightSurfaceList.m_Size = v37;
                    flashlightSurfaceList.m_pElements = flashlightSurfaceList.m_Memory.m_pMemory;
                    if ( v37 - v33 - 1 > 0 )
                    {
                      _V_memmove(
                        dest: &flashlightSurfaceList.m_Memory.m_pMemory[v33 + 1],
                        src: &flashlightSurfaceList.m_Memory.m_pMemory[v33],
                        count: 4 * (v37 - v33 - 1));
                      v36 = flashlightSurfaceList.m_Memory.m_pMemory;
                    }
                    v38 = &v36[v33];
                    if ( v38 != nullptr )
                      *v38 = (msurface2_t *)v90;
                  }
                  v39 = (msurface2_t *)v90;
                  if ( *(_WORD *)(v90 + 12) == 0xFFFF && *(_WORD *)(v90 + 16) == 0xFFFF )
                  {
                    v7 = pLastBatch;
LABEL_60:
                    v11 = decalSurfaceList.m_Size;
                  }
                  else
                  {
                    v40 = decalSurfaceList.m_Size;
                    v41 = decalSurfaceList.m_Size;
                    if ( decalSurfaceList.m_Size + 1 > decalSurfaceList.m_Memory.m_nAllocationCount )
                    {
                      sortID = decalSurfaceList.m_Size - decalSurfaceList.m_Memory.m_nAllocationCount + 1;
                      if ( decalSurfaceList.m_Memory.m_nGrowSize < 0 )
                      {
                        decalSurfaceList.m_Memory.m_nGrowSize = decalSurfaceList.m_Memory.m_nMallocGrowSize;
                        if ( decalSurfaceList.m_Memory.m_nAllocationCount != 0 )
                        {
                          v42 = 4 * decalSurfaceList.m_Memory.m_nAllocationCount;
                          v43 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(
                                                     this: _g_pMemAlloc,
                                                     a2: 4 * decalSurfaceList.m_Memory.m_nAllocationCount);
                          memcpy(dst: v43, src: (unsigned __int8 *)decalSurfaceList.m_Memory.m_pMemory, count: v42);
                          v39 = (msurface2_t *)v90;
                          decalSurfaceList.m_Memory.m_pMemory = (msurface2_t **)v43;
                        }
                        else
                        {
                          decalSurfaceList.m_Memory.m_pMemory = nullptr;
                        }
                      }
                      CUtlMemory<INetMessage *,int>::Grow(
                        this: (CUtlMemory<S3RGBA,int> *)&decalSurfaceList,
                        num: sortID);
                      v40 = decalSurfaceList.m_Size;
                    }
                    v44 = decalSurfaceList.m_Memory.m_pMemory;
                    v11 = v40 + 1;
                    decalSurfaceList.m_Size = v11;
                    decalSurfaceList.m_pElements = decalSurfaceList.m_Memory.m_pMemory;
                    if ( v11 - v41 - 1 > 0 )
                    {
                      _V_memmove(
                        dest: &decalSurfaceList.m_Memory.m_pMemory[v41 + 1],
                        src: &decalSurfaceList.m_Memory.m_pMemory[v41],
                        count: 4 * (v11 - v41 - 1));
                      v11 = decalSurfaceList.m_Size;
                      v44 = decalSurfaceList.m_Memory.m_pMemory;
                    }
                    v45 = &v44[v41];
                    v7 = pLastBatch;
                    if ( v45 != nullptr )
                    {
                      *v45 = v39;
                      goto LABEL_60;
                    }
                  }
                  m_Size = batches.m_Size;
                  m_nAllocationCount = batches.m_Memory.m_nAllocationCount;
                  goto LABEL_62;
                }
                bHasDisp = true;
              }
LABEL_62:
              v16 = j - 1;
            }
            v13 = leaf + 1;
            leaf = v13;
          }
          while ( v13 < sortCount );
          v9 = flags;
        }
      }
      ++i;
      mask *= 2;
    }
    while ( i < 4 );
    leaf = 0;
    if ( m_Size > 0 )
    {
      mask = 0;
      do
      {
        v46 = (int *)((char *)&batches.m_Memory.m_pMemory->firstSurface + mask);
        v47 = surfaceList.m_Memory.m_pMemory[*(int *)((char *)&batches.m_Memory.m_pMemory->firstSurface + mask)];
        pRenderContext->Bind(
          this: pRenderContext,
          a2: host_state.worldbrush->texinfo[*((unsigned __int16 *)v47 + 11) >> 1].material,
          a3: nullptr);
        if ( !skipLight )
          pRenderContext->BindLightmapPage(
            this: pRenderContext,
            a2: materialSortInfoArray[v47->materialSortID].lightmapPageID);
        Shader_DrawSurfaceListStatic(
          pRenderContext,
          pList: &surfaceList.m_Memory.m_pMemory[*v46],
          listCount: v46[1],
          triangleCount: v46[4]);
        mask += 20;
        ++leaf;
      }
      while ( leaf < batches.m_Size );
      v11 = decalSurfaceList.m_Size;
    }
    v48 = 0;
    for ( leaf = 0; v48 < v11; leaf = v48 )
    {
      v49 = decalSurfaceList.m_Memory.m_pMemory[v48];
      v50 = (v49->flags >> 22) & 3;
      if ( v49->m_nFirstOverlayFragment != 0xFFFF )
      {
        v51 = OverlayMgr();
        v51->AddFragmentListToRenderList(this: v51, a2: v50, a3: v49->m_nFirstOverlayFragment, a4: false);
        v52 = OverlayMgr();
        v52->RenderOverlays(this: v52, a2: pRenderContext, a3: v50);
        g_pShadowMgr->DrawFlashlightOverlays(this: g_pShadowMgr, a2: pRenderContext, a3: v50, a4: bFlashlightMask);
        v53 = OverlayMgr();
        v53->ClearRenderLists(this: v53, a2: v50);
        v11 = decalSurfaceList.m_Size;
      }
      if ( v49->decals != 0xFFFF )
      {
        DrawDecalsOnSingleSurface(pRenderContext, surfID: v49);
        v11 = decalSurfaceList.m_Size;
      }
      v48 = leaf + 1;
    }
    v54 = flashlightSurfaceList.m_Size;
    if ( flashlightSurfaceList.m_Size != 0 )
    {
      v55 = 0;
      if ( flashlightSurfaceList.m_Size > 0 )
      {
        do
        {
          if ( flashlightSurfaceList.m_Memory.m_pMemory[v55]->m_ShadowDecals != 0xFFFF )
          {
            g_pShadowMgr->AddShadowsOnSurfaceToRenderList(
              this: g_pShadowMgr,
              a2: flashlightSurfaceList.m_Memory.m_pMemory[v55]->m_ShadowDecals);
            v54 = flashlightSurfaceList.m_Size;
          }
          ++v55;
        }
        while ( v55 < v54 );
      }
      v56 = bFlashlightMask;
      ((void (__thiscall *)(IShadowMgrInternal *, int, _DWORD, _DWORD, int, int))g_pShadowMgr->RenderFlashlights)(
        a1: g_pShadowMgr,
        a2: bFlashlightMask,
        a3: 0,
        a4: 0,
        a5: a2,
        a6: a1);
      if ( decalSurfaceList.m_Size != 0 )
        g_pShadowMgr->DrawFlashlightDecalsOnSurfaceList(
          this: g_pShadowMgr,
          a2: pRenderContext,
          a3: flashlightSurfaceList.m_Memory.m_pMemory,
          a4: flashlightSurfaceList.m_Size,
          a5: v56);
      g_pShadowMgr->RenderShadows(this: g_pShadowMgr, a2: pRenderContext, a3: nullptr);
      g_pShadowMgr->ClearShadowRenderList(this: g_pShadowMgr);
    }
    DrawDebugInformation(pRenderContext, pList: surfaceList.m_Memory.m_pMemory, listCount: surfaceList.m_Size);
    v57 = dispList.m_Memory.m_pMemory;
    if ( bHasDisp )
    {
      v58 = dispList.m_Memory.m_nAllocationCount;
      v59 = 0;
      i = 0;
      mask = 1;
      do
      {
        if ( (flags & mask) != 0 )
        {
          for ( bFlashlightMask = 0; bFlashlightMask < sortCount; ++bFlashlightMask )
          {
            v60 = pSortList[bFlashlightMask];
            v61 = pRenderListIn[164].__vftable;
            v62 = LOWORD(v61[v60].Release);
            v63 = v62 + HIWORD(v61[v60].Release) - 1;
            v64 = 0;
            j = v62;
            dispList.m_Size = 0;
            leaf = v63;
            if ( v63 >= v62 )
            {
              while ( 1 )
              {
                v65 = *((_DWORD **)&pRenderListIn[99].AddRef + v63);
                v66 = (*v65 >> 22) & 3;
                sortID = (int)v65;
                if ( v66 == v59 && v65[6] != 0 )
                {
                  v67 = v64;
                  if ( v64 + 1 > v58 )
                  {
                    surfaceIndexStart = v64 - v58 + 1;
                    if ( dispList.m_Memory.m_nGrowSize < 0 )
                    {
                      dispList.m_Memory.m_nGrowSize = dispList.m_Memory.m_nMallocGrowSize;
                      if ( v58 != 0 )
                      {
                        v68 = 4 * v58;
                        v69 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v68);
                        memcpy(dst: v69, src: (unsigned __int8 *)dispList.m_Memory.m_pMemory, count: v68);
                        dispList.m_Memory.m_pMemory = (msurface2_t **)v69;
                      }
                      else
                      {
                        dispList.m_Memory.m_pMemory = nullptr;
                      }
                    }
                    CUtlMemory<INetMessage *,int>::Grow(
                      this: (CUtlMemory<S3RGBA,int> *)&dispList,
                      num: surfaceIndexStart);
                    v64 = dispList.m_Size;
                    v58 = dispList.m_Memory.m_nAllocationCount;
                    v57 = dispList.m_Memory.m_pMemory;
                  }
                  dispList.m_Size = ++v64;
                  dispList.m_pElements = v57;
                  if ( v64 - v67 - 1 > 0 )
                  {
                    _V_memmove(dest: &v57[v67 + 1], src: &v57[v67], count: 4 * (v64 - v67 - 1));
                    v64 = dispList.m_Size;
                    v58 = dispList.m_Memory.m_nAllocationCount;
                    v57 = dispList.m_Memory.m_pMemory;
                  }
                  v70 = (int *)&v57[v67];
                  if ( v70 != nullptr )
                  {
                    *v70 = sortID;
                    v64 = dispList.m_Size;
                    v58 = dispList.m_Memory.m_nAllocationCount;
                    v57 = dispList.m_Memory.m_pMemory;
                  }
                }
                v63 = leaf - 1;
                leaf = v63;
                if ( v63 < j )
                  break;
                v59 = i;
              }
              if ( v64 != 0 )
              {
                v71 = v64;
                v72 = g_EngineRenderer->ViewGetCurrent(this: g_EngineRenderer);
                v59 = i;
                DispInfo_RenderListWorld(
                  a1: i,
                  a2: (int)v57,
                  pRenderContext,
                  nSortGroup: i,
                  pList: v57,
                  listCount: v71,
                  bOrtho: v72->m_bOrtho,
                  flags,
                  bShadowDepth: nullptr);
                v73 = dispList.m_Size;
                v74 = dispList.m_Memory.m_pMemory;
                v75 = g_EngineRenderer->ViewGetCurrent(this: g_EngineRenderer);
                DispInfo_RenderListDecalsAndOverlays(
                  pRenderContext,
                  nSortGroup: v59,
                  pList: v74,
                  listCount: v73,
                  bOrtho: v75->m_bOrtho,
                  flags);
                v58 = dispList.m_Memory.m_nAllocationCount;
                v57 = dispList.m_Memory.m_pMemory;
              }
              else
              {
                v59 = i;
              }
            }
          }
        }
        mask *= 2;
        i = ++v59;
      }
      while ( v59 < 4 );
    }
    v76 = batches.m_Memory.m_pMemory;
    batches.m_Size = 0;
    if ( batches.m_Memory.m_nGrowSize >= 0 )
    {
      if ( batches.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: batches.m_Memory.m_pMemory);
        v57 = dispList.m_Memory.m_pMemory;
        v76 = nullptr;
        batches.m_Memory.m_pMemory = nullptr;
      }
      batches.m_Memory.m_nAllocationCount = 0;
    }
    batches.m_pElements = v76;
    if ( batches.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v76 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v76);
        v57 = dispList.m_Memory.m_pMemory;
        batches.m_Memory.m_pMemory = nullptr;
      }
      batches.m_Memory.m_nAllocationCount = 0;
    }
    dispList.m_Size = 0;
    if ( dispList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v57 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v57);
        v57 = nullptr;
        dispList.m_Memory.m_pMemory = nullptr;
      }
      dispList.m_Memory.m_nAllocationCount = 0;
    }
    dispList.m_pElements = v57;
    if ( dispList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v57 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v57);
        dispList.m_Memory.m_pMemory = nullptr;
      }
      dispList.m_Memory.m_nAllocationCount = 0;
    }
    v77 = flashlightSurfaceList.m_Memory.m_pMemory;
    flashlightSurfaceList.m_Size = 0;
    if ( flashlightSurfaceList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( flashlightSurfaceList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: flashlightSurfaceList.m_Memory.m_pMemory);
        v77 = nullptr;
        flashlightSurfaceList.m_Memory.m_pMemory = nullptr;
      }
      flashlightSurfaceList.m_Memory.m_nAllocationCount = 0;
    }
    flashlightSurfaceList.m_pElements = v77;
    if ( flashlightSurfaceList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v77 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v77);
        flashlightSurfaceList.m_Memory.m_pMemory = nullptr;
      }
      flashlightSurfaceList.m_Memory.m_nAllocationCount = 0;
    }
    v78 = decalSurfaceList.m_Memory.m_pMemory;
    decalSurfaceList.m_Size = 0;
    if ( decalSurfaceList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( decalSurfaceList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: decalSurfaceList.m_Memory.m_pMemory);
        v78 = nullptr;
        decalSurfaceList.m_Memory.m_pMemory = nullptr;
      }
      decalSurfaceList.m_Memory.m_nAllocationCount = 0;
    }
    decalSurfaceList.m_pElements = v78;
    if ( decalSurfaceList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v78 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v78);
        decalSurfaceList.m_Memory.m_pMemory = nullptr;
      }
      decalSurfaceList.m_Memory.m_nAllocationCount = 0;
    }
    v79 = surfaceList.m_Memory.m_pMemory;
    surfaceList.m_Size = 0;
    if ( surfaceList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( surfaceList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: surfaceList.m_Memory.m_pMemory);
        v79 = nullptr;
        surfaceList.m_Memory.m_pMemory = nullptr;
      }
      surfaceList.m_Memory.m_nAllocationCount = 0;
    }
    surfaceList.m_pElements = v79;
    if ( surfaceList.m_Memory.m_nGrowSize >= 0 && v79 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v79);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D8DA0
// Name: void R_DrawWorldLists(class IMatRenderContext __near *,class IWorldRenderList __near *,unsigned long,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_DrawWorldLists(
        IMatRenderContext *pRenderContext,
        CWorldRenderList *pRenderListIn,
        unsigned int flags,
        float waterZAdjust)
{
  if ( !g_bTextMode && !g_LostVideoMemory )
  {
    if ( (flags & 0x200) != 0 )
    {
      Shader_WorldEnd(pRenderContext, pRenderList: pRenderListIn, flags, waterZAdjust);
    }
    else if ( (flags & 0x1800) != 0 )
    {
      DrawSimpleWorldModel(a1: (int)pRenderListIn, a2: (int)pRenderContext, a3: flags, flags);
    }
    if ( (flags & 0x400) != 0 )
      Shader_DrawWorldDecalsAndOverlays(pRenderContext, pRenderList: pRenderListIn, flags, waterZAdjust);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D8E10
// Name: public: static class CWorldRenderList __near * CWorldRenderList::FindOrCreateList(int)
// Source: json
//------------------------------------------------------------------------------
CWorldRenderList *__cdecl CWorldRenderList::FindOrCreateList(int nSurfaces)
{
  TSLNodeBase_t *v1; // eax
  CWorldRenderList *v2; // esi
  CWorldRenderList *v3; // eax

  v1 = CTSListBase::Pop(this: &CWorldRenderList::g_Pool.m_AvailableObjects);
  if ( v1 != nullptr )
  {
    v2 = *((CWorldRenderList **)&v1->Next + 1);
    free(pMem: v1);
  }
  else
  {
    v3 = (CWorldRenderList *)MemAlloc_Alloc(nSize: 0x2B4u);
    if ( v3 != nullptr )
      v2 = CWorldRenderList::CWorldRenderList(this: v3);
    else
      v2 = nullptr;
  }
  if ( v2->m_VisitedSurfs.m_bits.m_numBits == nSurfaces )
    v2->AddRef(this: v2);
  else
    CWorldRenderList::Init(this: v2, nSurfaces);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x100D8E80
// Name: public: static void CWorldRenderList::PurgeAll(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CWorldRenderList::PurgeAll()
{
  TSLHead_t m_Head; // kr00_8
  int v1; // edi

  while ( 1 )
  {
    m_Head = CWorldRenderList::g_Pool.m_AvailableObjects.m_Head;
    if ( CWorldRenderList::g_Pool.m_AvailableObjects.m_Head.value.Next == nullptr )
      break;
    while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                               a1: &CWorldRenderList::g_Pool,
                               a2: m_Head.value.Next->Next,
                               a3: m_Head.value32.DepthAndSequence - 1,
                               a4: m_Head.value.Next,
                               a5: m_Head.value32.DepthAndSequence) == 0 )
    {
      _mm_pause();
      m_Head = CWorldRenderList::g_Pool.m_AvailableObjects.m_Head;
      if ( CWorldRenderList::g_Pool.m_AvailableObjects.m_Head.value.Next == nullptr )
        return;
    }
    if ( m_Head.value.Next == nullptr )
      break;
    v1 = *((_DWORD *)&m_Head.value.Next->Next + 1);
    free(pMem: m_Head.value.Next);
    if ( v1 == 0 )
      break;
    CWorldRenderList::Purge(this: (CWorldRenderList *)v1);
    (**(void (__thiscall ***)(int, int))(v1 + 4))(a1: v1 + 4, a2: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D8F00
// Name: class IWorldRenderList __near * AllocWorldRenderList(void)
// Source: json
//------------------------------------------------------------------------------
CWorldRenderList *__cdecl AllocWorldRenderList()
{
  return CWorldRenderList::FindOrCreateList(nSurfaces: host_state.worldbrush->numsurfaces);
}

//------------------------------------------------------------------------------
// Address: 0x100D8F20
// Name: void R_Surface_LevelShutdown(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl R_Surface_LevelShutdown()
{
  CWorldRenderList::PurgeAll();
}

//------------------------------------------------------------------------------
// Address: 0x10314F30
// Name: _dynamic_initializer_for__CWorldRenderList::g_Pool__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CWorldRenderList::g_Pool__()
{
  if ( ((unsigned __int8)&CWorldRenderList::g_Pool & 7) != 0 )
  {
    _Error(a1: "CTSListBase: Misaligned list\n");
    __debugbreak();
  }
  CWorldRenderList::g_Pool = 0;
  return atexit(func: dynamic_atexit_destructor_for__CWorldRenderList::g_Pool__);
}

//------------------------------------------------------------------------------
// Address: 0x10323350
// Name: _dynamic_atexit_destructor_for__CWorldRenderList::g_Pool__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CWorldRenderList::g_Pool__()
{
  TSLNodeBase_t *v0; // eax
  TSLNodeBase_t *Next; // esi

  CObjectPool<CWorldRenderList,0,1>::Purge(this: &CWorldRenderList::g_Pool);
  v0 = CTSListBase::Detach(this: &CWorldRenderList::g_Pool.m_AvailableObjects);
  if ( v0 != nullptr )
  {
    do
    {
      Next = v0->Next;
      free(pMem: v0);
      v0 = Next;
    }
    while ( Next != nullptr );
  }
  CTSListBase::Detach(this: &CWorldRenderList::g_Pool.m_AvailableObjects);
}

//------------------------------------------------------------------------------
// Address: 0x10323390
// Name: _dynamic_atexit_destructor_for__g_cv_miniprofiler_dump__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_cv_miniprofiler_dump__()
{
  ConVar::~ConVar(this: &g_cv_miniprofiler_dump);
}

} // namespace engine_xlsp
