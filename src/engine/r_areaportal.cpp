// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/r_areaportal.cpp
// Functions: 11
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x100FD310
// Name: void __near * MemAlloc_ReallocAligned(void __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl MemAlloc_ReallocAligned(unsigned __int8 *ptr, unsigned int size, unsigned int align)
{
  void *v4; // ebx
  unsigned int v5; // esi
  unsigned __int8 *pResult; // [esp+10h] [ebp+10h]

  if ( ((align - 1) & align) != 0 )
    return nullptr;
  if ( ((align - 1) & (unsigned int)ptr) != 0 )
    return nullptr;
  if ( ptr == nullptr )
    return (unsigned __int8 *)MemAlloc_AllocAlignedUnattributed(size, align);
  v4 = *(void **)(((unsigned int)ptr & 0xFFFFFFFC) - 4);
  v5 = _g_pMemAlloc->GetSize(this: _g_pMemAlloc, a2: v4);
  if ( v5 >= ptr - (_BYTE *)v4 + size )
    return ptr;
  pResult = (unsigned __int8 *)MemAlloc_AllocAlignedUnattributed(size, align);
  memcpy(dst: pResult, src: ptr, count: v5 - (ptr - (_BYTE *)v4));
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
  return pResult;
}

//------------------------------------------------------------------------------
// Address: 0x100FD3B0
// Name: GetPortalScreenExtents
// Source: json
//------------------------------------------------------------------------------
bool __cdecl GetPortalScreenExtents(
        dareaportal_t *pPortal,
        portalclip_t *clip,
        CPortalRect *portalRect,
        float *pReflectionWaterHeight,
        VPlane *pFrustumPlanes)
{
  CPortalRect *v5; // eax
  unsigned int m_nClipPortalVerts; // ecx
  int v7; // edi
  int v8; // ebx
  Vector *v9; // eax
  float *v10; // edx
  float *v11; // ecx
  float *v12; // eax
  unsigned int v13; // esi
  bool v14; // zf
  int v15; // esi
  float *v16; // eax
  Vector *v17; // ecx
  int v18; // edx
  float *v19; // eax
  BOOL v20; // ecx
  Vector *v21; // esi
  float v22; // xmm0_4
  BOOL v23; // ecx
  Vector *v24; // edx
  float v25; // xmm1_4
  int v26; // edi
  float *v27; // ecx
  float v28; // xmm0_4
  float v29; // xmm2_4
  int v30; // ebx
  float v31; // xmm1_4
  portalclip_t *v32; // esi
  double x; // st7
  double left; // st6
  double y; // st6
  double bottom; // st5
  double v37; // st5
  double top; // st6
  double v39; // st6
  double right; // st7
  Vector screenPos; // [esp+0h] [ebp-3Ch] BYREF
  int nPassCount; // [esp+Ch] [ebp-30h]
  BOOL v44; // [esp+10h] [ebp-2Ch]
  int v45; // [esp+14h] [ebp-28h]
  float *p_z; // [esp+18h] [ebp-24h]
  int iPlane; // [esp+1Ch] [ebp-20h]
  int v48; // [esp+20h] [ebp-1Ch]
  worldbrushdata_t *pBrushData; // [esp+24h] [ebp-18h]
  float *v50; // [esp+28h] [ebp-14h]
  int nOutVerts; // [esp+2Ch] [ebp-10h]
  int nStartVerts; // [esp+30h] [ebp-Ch]
  int j; // [esp+34h] [ebp-8h]
  bool bValidExtents; // [esp+3Bh] [ebp-1h]

  v5 = portalRect;
  portalRect->bottom = 1.0e24;
  portalRect->left = 1.0e24;
  portalRect->top = -1.0e24;
  portalRect->right = -1.0e24;
  pBrushData = host_state.worldbrush;
  m_nClipPortalVerts = pPortal->m_nClipPortalVerts;
  bValidExtents = false;
  if ( m_nClipPortalVerts >= 0x20 )
  {
    v7 = 32;
    nStartVerts = 32;
  }
  else
  {
    v7 = m_nClipPortalVerts;
    nStartVerts = m_nClipPortalVerts;
  }
  j = 0;
  nPassCount = (pReflectionWaterHeight != nullptr) + 1;
  if ( (pReflectionWaterHeight != nullptr) == -1 )
    goto LABEL_52;
  p_z = &pFrustumPlanes->m_Normal.z;
  do
  {
    v8 = 0;
    if ( v7 >= 4 )
    {
      v9 = &pBrushData->m_pClipPortalVerts[pPortal->m_FirstClipPortalVert];
      v10 = &v9->z;
      v11 = &clip->v0[1].z;
      v12 = &v9[1].z;
      v13 = ((unsigned int)(v7 - 4) >> 2) + 1;
      v8 = 4 * v13;
      do
      {
        v14 = j == 1;
        *(v11 - 5) = *(v10 - 2);
        *(v11 - 4) = *(v10 - 1);
        *(v11 - 3) = *v10;
        if ( v14 )
          *(v11 - 3) = (float)(*pReflectionWaterHeight * 2.0) - *(v11 - 3);
        v14 = j == 1;
        *(v11 - 2) = v10[1];
        *(v11 - 1) = *(v12 - 1);
        *v11 = *v12;
        if ( v14 )
          *v11 = (float)(*pReflectionWaterHeight * 2.0) - *v11;
        v14 = j == 1;
        v11[1] = v10[4];
        v11[2] = v12[2];
        v11[3] = v12[3];
        if ( v14 )
          v11[3] = (float)(*pReflectionWaterHeight * 2.0) - v11[3];
        v14 = j == 1;
        v11[4] = v10[7];
        v11[5] = v12[5];
        v11[6] = v12[6];
        if ( v14 )
          v11[6] = (float)(*pReflectionWaterHeight * 2.0) - v11[6];
        v10 += 12;
        v12 += 12;
        v11 += 12;
        --v13;
      }
      while ( v13 != 0 );
      v7 = nStartVerts;
    }
    if ( v8 < v7 )
    {
      v15 = j;
      v16 = &clip->v0[v8].z;
      v17 = &pBrushData->m_pClipPortalVerts[v8 + pPortal->m_FirstClipPortalVert];
      v18 = v7 - v8;
      do
      {
        *(v16 - 2) = v17->x;
        *(v16 - 1) = v17->y;
        *v16 = v17->z;
        if ( v15 == 1 )
          *v16 = (float)(*pReflectionWaterHeight * 2.0) - *v16;
        ++v17;
        v16 += 3;
        --v18;
      }
      while ( v18 != 0 );
    }
    v19 = p_z;
    v20 = false;
    iPlane = 0;
    v50 = p_z;
    while ( 1 )
    {
      v21 = clip->lists[v20];
      v22 = *(v19 - 2);
      nOutVerts = 0;
      v23 = !v20;
      v24 = clip->lists[v23];
      v44 = v23;
      v25 = (float)((float)((float)(v21[v7 - 1].y * *(v19 - 1)) + (float)(v22 * v21[v7 - 1].x))
                  + (float)(v21[v7 - 1].z * *v19))
          - v19[1];
      if ( v7 <= 0 )
        break;
      v45 = -8 - (_DWORD)v21;
      v26 = 4 * (3 * v7 - 3);
      v27 = &v21->z;
      v48 = nStartVerts;
      while ( 1 )
      {
        v28 = *(v27 - 2);
        v29 = (float)((float)((float)(*(v27 - 1) * *(v19 - 1)) + (float)(*(v19 - 2) * v28)) + (float)(*v19 * *v27))
            - v19[1];
        v30 = nOutVerts;
        if ( v29 > 0.0 != v25 > 0.0 && nOutVerts < 32 )
        {
          v31 = v25 / (float)(v25 - v29);
          v24->x = (float)((float)(v28 - *(float *)((char *)&v21->x + v26)) * v31) + *(float *)((char *)&v21->x + v26);
          v24->y = (float)((float)(*(v27 - 1) - *(float *)((char *)&v21->y + v26)) * v31)
                 + *(float *)((char *)&v21->y + v26);
          ++v30;
          v24->z = (float)((float)(*v27 - *(float *)((char *)&v21->z + v26)) * v31) + *(float *)((char *)&v21->z + v26);
          nOutVerts = v30;
          ++v24;
        }
        if ( v29 > 0.0 && v30 < 32 )
        {
          ++v30;
          v24->x = *(v27 - 2);
          nOutVerts = v30;
          ++v24;
          v24[-1].y = *(v27 - 1);
          v24[-1].z = *v27;
        }
        v26 = (int)v27 + v45;
        v27 += 3;
        v14 = v48-- == 1;
        v25 = v29;
        if ( v14 )
          break;
        v19 = v50;
      }
      if ( v30 == 0 )
      {
        v7 = nStartVerts;
        break;
      }
      v20 = v44;
      v19 = v50 + 4;
      v7 = v30;
      nStartVerts = v30;
      ++iPlane;
      v50 += 4;
      if ( iPlane >= 4 )
      {
        if ( v30 > 0 )
        {
          v32 = clip;
          do
          {
            g_EngineRenderer->ClipTransform(this: g_EngineRenderer, a2: (const Vector *)v32, a3: &screenPos);
            x = screenPos.x;
            left = portalRect->left;
            if ( screenPos.x <= left )
              left = screenPos.x;
            portalRect->left = left;
            y = screenPos.y;
            bottom = portalRect->bottom;
            if ( screenPos.y <= bottom )
              bottom = screenPos.y;
            portalRect->bottom = bottom;
            v37 = y;
            top = portalRect->top;
            if ( v37 >= top )
              top = v37;
            portalRect->top = top;
            v39 = x;
            right = portalRect->right;
            if ( v39 >= right )
              right = v39;
            v32 = (portalclip_t *)((char *)v32 + 12);
            portalRect->right = right;
            --v30;
          }
          while ( v30 != 0 );
        }
        bValidExtents = true;
        break;
      }
    }
    ++j;
  }
  while ( j < nPassCount );
  if ( !bValidExtents )
  {
    v5 = portalRect;
LABEL_52:
    v5->bottom = 0.0;
    v5->left = 0.0;
    v5->top = 0.0;
    v5->right = 0.0;
  }
  return bValidExtents;
}

//------------------------------------------------------------------------------
// Address: 0x100FD810
// Name: bool GetRectIntersection(class CPortalRect const __near *,class CPortalRect const __near *,class CPortalRect __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl GetRectIntersection(const CPortalRect *pRect1, const CPortalRect *pRect2, CPortalRect *pOut)
{
  double left; // st7
  double right; // st6
  double bottom; // st7
  double top; // st6

  left = pRect2->left;
  if ( pRect1->left >= left )
    left = pRect1->left;
  pOut->left = left;
  right = pRect2->right;
  if ( pRect1->right <= right )
    right = pRect1->right;
  pOut->right = right;
  if ( left >= right )
    return false;
  bottom = pRect2->bottom;
  if ( pRect1->bottom >= bottom )
    bottom = pRect1->bottom;
  pOut->bottom = bottom;
  top = pRect2->top;
  if ( pRect1->top <= top )
    top = pRect1->top;
  pOut->top = top;
  return bottom < top;
}

//------------------------------------------------------------------------------
// Address: 0x100FD920
// Name: R_SetupVisibleAreaFrustums
// Source: json
//------------------------------------------------------------------------------
void R_SetupVisibleAreaFrustums()
{
  const CViewSetup *v0; // eax
  const CViewSetup *v1; // ebx
  float m_OrthoRight; // xmm1_4
  float m_OrthoTop; // xmm2_4
  double v4; // st7
  float (__thiscall *GetFovY)(IRender *); // edx
  long double v6; // st7
  long double v7; // st7
  int v8; // edx
  int v9; // edi
  int v10; // ecx
  CPortalRect *v11; // eax
  float v12; // xmm3_4
  Frustum_t *v13; // esi
  bool v14; // zf
  float v15; // xmm3_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  ConVar *m_pParent; // esi
  int i; // edi
  int m_nValue; // ecx
  int v21; // eax
  Frustum_t *v22; // esi
  unsigned int dist; // [esp+4h] [ebp-DCh]
  int v24; // [esp+8h] [ebp-D8h]
  VPlane pPlanes; // [esp+1Ch] [ebp-C4h] BYREF
  float z; // [esp+2Ch] [ebp-B4h]
  float x; // [esp+30h] [ebp-B0h]
  float y; // [esp+34h] [ebp-ACh]
  float v29; // [esp+38h] [ebp-A8h]
  float bottom; // [esp+3Ch] [ebp-A4h]
  float v31; // [esp+40h] [ebp-A0h]
  float v32; // [esp+44h] [ebp-9Ch]
  float v33; // [esp+48h] [ebp-98h]
  float v34; // [esp+4Ch] [ebp-94h]
  float v35; // [esp+50h] [ebp-90h]
  float v36; // [esp+54h] [ebp-8Ch]
  float v37; // [esp+58h] [ebp-88h]
  float v38; // [esp+5Ch] [ebp-84h]
  float v39; // [esp+60h] [ebp-80h]
  float v40; // [esp+64h] [ebp-7Ch]
  float v41; // [esp+68h] [ebp-78h]
  float v42; // [esp+6Ch] [ebp-74h]
  float v43; // [esp+70h] [ebp-70h]
  float v44; // [esp+74h] [ebp-6Ch]
  float v45; // [esp+78h] [ebp-68h]
  float v46; // [esp+7Ch] [ebp-64h]
  CPortalRect portalWindow; // [esp+80h] [ebp-60h]
  float v48; // [esp+90h] [ebp-50h]
  float m_OrthoLeft; // [esp+94h] [ebp-4Ch]
  CPortalRect viewWindow; // [esp+98h] [ebp-48h]
  Vector up; // [esp+A8h] [ebp-38h] BYREF
  Vector right; // [esp+B4h] [ebp-2Ch]
  Vector viewOrigin; // [esp+C0h] [ebp-20h] BYREF
  Vector forward; // [esp+CCh] [ebp-14h] BYREF
  Vector normal; // [esp+D8h] [ebp-8h]

  v0 = g_EngineRenderer->ViewGetCurrent(this: g_EngineRenderer);
  v1 = v0;
  if ( v0->m_bOrtho )
  {
    m_OrthoRight = v0->m_OrthoRight;
    m_OrthoTop = v0->m_OrthoTop;
    m_OrthoLeft = v0->m_OrthoLeft;
    viewWindow.right = v0->m_OrthoBottom;
  }
  else
  {
    v4 = ((double (__thiscall *)(IRender *))g_EngineRenderer->GetFov)(a1: g_EngineRenderer);
    GetFovY = g_EngineRenderer->GetFovY;
    v6 = tan(v4 * 0.5 * 0.017453292);
    viewWindow.top = v6;
    m_OrthoLeft = -v6;
    m_OrthoRight = viewWindow.top;
    v7 = tan(((double (__thiscall *)(IRender *))GetFovY)(a1: g_EngineRenderer) * 0.5 * 0.017453292);
    viewWindow.left = v7;
    viewWindow.right = -v7;
    m_OrthoTop = viewWindow.left;
  }
  viewOrigin.y = g_CurrentViewOrigin.z;
  forward.y = g_CurrentViewForward.z;
  right.z = g_CurrentViewOrigin.x;
  viewOrigin.x = g_CurrentViewOrigin.y;
  right.y = g_CurrentViewRight.z;
  viewOrigin.z = g_CurrentViewForward.x;
  forward.x = g_CurrentViewForward.y;
  up.y = g_CurrentViewUp.z;
  v8 = g_nVisibleAreas;
  up.z = g_CurrentViewRight.x;
  right.x = g_CurrentViewRight.y;
  v9 = 0;
  viewWindow.bottom = g_CurrentViewUp.x;
  up.x = g_CurrentViewUp.y;
  if ( g_nVisibleAreas > 0 )
  {
    v48 = m_OrthoRight - m_OrthoLeft;
    portalWindow.bottom = m_OrthoTop - viewWindow.right;
    do
    {
      v10 = g_VisibleAreas[v9];
      v11 = &g_AreaRect[v10];
      v12 = v11->right;
      v46 = (float)((float)((float)(v11->left - -1.0) * v48) * 0.5) + m_OrthoLeft;
      portalWindow.left = (float)((float)((float)(v11->top - -1.0) * portalWindow.bottom) * 0.5) + viewWindow.right;
      v13 = &g_AreaFrustum.m_Memory.m_pMemory[v10];
      v14 = !v1->m_bOrtho;
      v15 = (float)((float)((float)(v12 - -1.0) * v48) * 0.5) + m_OrthoLeft;
      portalWindow.right = (float)((float)((float)(v11->bottom - -1.0) * portalWindow.bottom) * 0.5) + viewWindow.right;
      if ( v14 )
      {
        forward.z = (float)(viewOrigin.z * v15) - up.z;
        normal.x = (float)(forward.x * v15) - right.x;
        normal.y = (float)(forward.y * v15) - right.y;
        VectorNormalize(vec: (Vector *)&forward.z);
        pPlanes.m_Normal.x = forward.z;
        pPlanes.m_Normal.y = normal.x;
        pPlanes.m_Normal.z = normal.y;
        pPlanes.m_Dist = (float)((float)(forward.z * right.z) + (float)(normal.x * viewOrigin.x))
                       + (float)(normal.y * viewOrigin.y);
        forward.z = g_CurrentViewRight.x - (float)(viewOrigin.z * v46);
        normal.x = g_CurrentViewRight.y - (float)(forward.x * v46);
        normal.y = g_CurrentViewRight.z - (float)(forward.y * v46);
        VectorNormalize(vec: (Vector *)&forward.z);
        z = forward.z;
        x = normal.x;
        y = normal.y;
        v29 = (float)((float)(forward.z * right.z) + (float)(normal.x * viewOrigin.x))
            + (float)(normal.y * viewOrigin.y);
        forward.z = (float)(viewOrigin.z * portalWindow.left) - viewWindow.bottom;
        normal.x = (float)(forward.x * portalWindow.left) - up.x;
        normal.y = (float)(forward.y * portalWindow.left) - up.y;
        VectorNormalize(vec: (Vector *)&forward.z);
        bottom = forward.z;
        v31 = normal.x;
        v32 = normal.y;
        v33 = (float)((float)(forward.z * right.z) + (float)(normal.x * viewOrigin.x))
            + (float)(normal.y * viewOrigin.y);
        forward.z = viewWindow.bottom - (float)(viewOrigin.z * portalWindow.right);
        normal.x = up.x - (float)(forward.x * portalWindow.right);
        normal.y = up.y - (float)(forward.y * portalWindow.right);
        VectorNormalize(vec: (Vector *)&forward.z);
        v34 = forward.z;
        v35 = normal.x;
        v36 = normal.y;
        v37 = (float)((float)(forward.z * right.z) + (float)(normal.x * viewOrigin.x))
            + (float)(normal.y * viewOrigin.y);
        v41 = (float)((float)((float)(viewOrigin.z * right.z) + (float)(forward.x * viewOrigin.x))
                    + (float)(forward.y * viewOrigin.y))
            + v1->zNear;
        v38 = viewOrigin.z;
        v39 = forward.x;
        v40 = forward.y;
        v17 = (float)((float)((float)((float)-viewOrigin.z * right.z) + (float)((float)-forward.x * viewOrigin.x))
                    + (float)((float)-forward.y * viewOrigin.y))
            - v1->zFar;
      }
      else
      {
        y = right.y;
        v29 = (float)((float)((float)(viewOrigin.x * right.x) + (float)(right.z * up.z))
                    + (float)(viewOrigin.y * right.y))
            + v46;
        pPlanes.m_Normal.z = -right.y;
        pPlanes.m_Dist = (float)-v15
                       - (float)((float)((float)(viewOrigin.x * right.x) + (float)(right.z * up.z))
                               + (float)(viewOrigin.y * right.y));
        x = right.x;
        bottom = viewWindow.bottom;
        pPlanes.m_Normal.y = -right.x;
        v34 = -viewWindow.bottom;
        v16 = (float)((float)(viewWindow.bottom * right.z) + (float)(up.x * viewOrigin.x))
            + (float)(up.y * viewOrigin.y);
        v31 = up.x;
        v32 = up.y;
        v35 = -up.x;
        v37 = (float)-portalWindow.right - v16;
        z = up.z;
        v36 = -up.y;
        v38 = viewOrigin.z;
        v39 = forward.x;
        v40 = forward.y;
        v17 = -1000000.0;
        pPlanes.m_Normal.x = -up.z;
        v33 = v16 + portalWindow.left;
        v41 = 0.0;
      }
      v42 = -viewOrigin.z;
      v43 = -forward.x;
      v44 = -forward.y;
      v45 = v17;
      Frustum_t::SetPlanes(this: v13, &pPlanes);
      v8 = g_nVisibleAreas;
      ++v9;
    }
    while ( v9 < g_nVisibleAreas );
  }
  m_pParent = r_snapportal.m_pParent;
  if ( r_snapportal.m_pParent == nullptr || r_snapportal.m_pParent->m_Value.m_nValue >= 0 )
  {
    for ( i = 0; i < v8; ++i )
    {
      if ( m_pParent != nullptr )
        m_nValue = m_pParent->m_Value.m_nValue;
      else
        m_nValue = 0;
      v21 = g_VisibleAreas[i];
      if ( v21 == m_nValue )
      {
        v22 = &g_AreaFrustum.m_Memory.m_pMemory[v21];
        Frustum_t::SetPlane(
          this: v22,
          i: 4,
          vecNormal: (Vector *)&viewOrigin.z,
          dist: (float)((float)(viewOrigin.z * right.z) + (float)(forward.x * viewOrigin.x))
        + (float)(forward.y * viewOrigin.y));
        up.z = -viewOrigin.z;
        right.x = -forward.x;
        right.y = -forward.y;
        Frustum_t::SetPlane(
          this: v22,
          i: 5,
          vecNormal: (Vector *)&up.z,
          dist: (float)((float)((float)-viewOrigin.z * (float)((float)(viewOrigin.z * 500.0) + right.z))
                + (float)((float)-forward.x * (float)((float)(forward.x * 500.0) + viewOrigin.x)))
        + (float)((float)-forward.y * (float)((float)(forward.y * 500.0) + viewOrigin.y)));
        CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&r_snapportal.IConVar, value: -1, a2: dist, a3: v24);
        CSGFrustum(frustum: v22);
        v8 = g_nVisibleAreas;
        m_pParent = r_snapportal.m_pParent;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FE0C0
// Name: bool R_CullNode(struct mnode_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl R_CullNode(mnode_t *pNode)
{
  __int16 area; // ax

  if ( g_bViewerInSolidSpace )
    return CullNodeSIMD(frustum: &g_Frustum, pNode);
  area = pNode->area;
  if ( area <= 0 )
    return CullNodeSIMD(frustum: &g_Frustum, pNode);
  if ( (`GetBitForBitnum'::`2'::bitsForBitnum[area & 7] & g_RenderAreaBits[area >> 3]) != 0 )
    return CullNodeSIMD(frustum: &g_AreaFrustum.m_Memory.m_pMemory[area], pNode);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100FE120
// Name: class Frustum_t const __near * GetAreaFrustum(int)
// Source: json
//------------------------------------------------------------------------------
const Frustum_t *__cdecl GetAreaFrustum(int area)
{
  if ( g_AreaCounter[area] == g_GlobalCounter )
    return &g_AreaFrustum.m_Memory.m_pMemory[area];
  else
    return &g_Frustum;
}

//------------------------------------------------------------------------------
// Address: 0x100FE150
// Name: int GetAllAreaFrustums(class Frustum_t __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetAllAreaFrustums(Frustum_t **pFrustumList, int listMax)
{
  int result; // eax
  Frustum_t **v3; // ecx
  int v4; // edx
  int i; // esi

  result = g_AreaFrustum.m_Size;
  if ( listMax < g_AreaFrustum.m_Size )
    result = listMax;
  if ( result > 0 )
  {
    v3 = pFrustumList;
    v4 = 0;
    for ( i = result; i != 0; --i )
    {
      if ( *(Frustum_t **)((char *)v3 + (char *)g_AreaCounter - (char *)pFrustumList) == (Frustum_t *)g_GlobalCounter )
        *v3 = &g_AreaFrustum.m_Memory.m_pMemory[v4];
      else
        *v3 = &g_Frustum;
      ++v4;
      ++v3;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100FE2D0
// Name: void R_Areaportal_LevelShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_Areaportal_LevelShutdown()
{
  Frustum_t *m_pMemory; // eax
  CPortalRect *v1; // eax

  m_pMemory = g_AreaFrustum.m_Memory.m_pMemory;
  g_AreaFrustum.m_Size = 0;
  if ( g_AreaFrustum.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_AreaFrustum.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(((int)g_AreaFrustum.m_Memory.m_pMemory & 0xFFFFFFFC) - 4));
      m_pMemory = nullptr;
      g_AreaFrustum.m_Memory.m_pMemory = nullptr;
    }
    g_AreaFrustum.m_Memory.m_nAllocationCount = 0;
  }
  g_AreaFrustum.m_pElements = m_pMemory;
  g_PortalRects.m_Size = 0;
  if ( g_PortalRects.m_Memory.m_nGrowSize < 0 )
  {
    g_PortalRects.m_pElements = g_PortalRects.m_Memory.m_pMemory;
  }
  else
  {
    v1 = g_PortalRects.m_Memory.m_pMemory;
    if ( g_PortalRects.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_PortalRects.m_Memory.m_pMemory);
      v1 = nullptr;
      g_PortalRects.m_Memory.m_pMemory = nullptr;
    }
    g_PortalRects.m_Memory.m_nAllocationCount = 0;
    g_PortalRects.m_pElements = v1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FE360
// Name: R_FlowThroughArea
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_FlowThroughArea(
        int area,
        const Vector *vecVisOrigin,
        const CPortalRect *pClipRect,
        const VisOverrideData_t *pVisData,
        float *pReflectionWaterHeight)
{
  unsigned int v5; // ecx
  int v6; // eax
  CPortalRect *v7; // ecx
  double left; // st7
  double bottom; // st7
  double top; // st7
  double right; // st7
  char v12; // al
  int v13; // ebx
  darea_t *v14; // esi
  bool v15; // cc
  dareaportal_t *v16; // esi
  int m_PortalKey; // edi
  cplane_t *planes; // edx
  int otherarea; // edi
  float m_fDistToAreaPortalTolerance; // xmm0_4
  portalclip_t clipTmp; // [esp+8h] [ebp-398h] BYREF
  VPlane frustumPlanes[6]; // [esp+310h] [ebp-90h] BYREF
  CPortalRect intersection; // [esp+370h] [ebp-30h] BYREF
  CPortalRect portalRect; // [esp+380h] [ebp-20h] BYREF
  float flDist; // [esp+390h] [ebp-10h]
  darea_t *pArea; // [esp+394h] [ebp-Ch]
  worldbrushdata_t *pBrushData; // [esp+398h] [ebp-8h]
  int iAreaPortal; // [esp+39Ch] [ebp-4h]

  v5 = g_GlobalCounter;
  if ( g_AreaCounter[area] == g_GlobalCounter )
  {
    v7 = &g_AreaRect[area];
    left = pClipRect->left;
    if ( v7->left <= left )
      left = v7->left;
    v7->left = left;
    bottom = pClipRect->bottom;
    if ( v7->bottom <= bottom )
      bottom = v7->bottom;
    v7->bottom = bottom;
    top = pClipRect->top;
    if ( v7->top >= top )
      top = v7->top;
    v7->top = top;
    right = pClipRect->right;
    if ( v7->right >= right )
      right = v7->right;
    v7->right = right;
  }
  else
  {
    v6 = g_nVisibleAreas;
    g_VisibleAreas[g_nVisibleAreas] = area;
    g_nVisibleAreas = v6 + 1;
    g_AreaCounter[area] = v5;
    g_AreaRect[area] = *pClipRect;
  }
  v12 = 1 << (area & 7);
  v13 = area >> 3;
  g_RenderAreaBits[v13] |= v12;
  g_AreaStack[v13] |= v12;
  pBrushData = host_state.worldbrush;
  v14 = &host_state.worldbrush->m_pAreas[area];
  clipTmp.lists[0] = (Vector *)&clipTmp;
  pArea = v14;
  clipTmp.lists[1] = clipTmp.v1;
  Frustum_t::GetPlanes(this: &g_Frustum, pPlanesOut: frustumPlanes);
  v15 = v14->numareaportals <= 0;
  iAreaPortal = 0;
  if ( !v15 )
  {
    while ( 1 )
    {
      v16 = &pBrushData->m_pAreaPortals[iAreaPortal + v14->firstareaportal];
      if ( ((unsigned __int8)(1 << (v16->otherarea & 7)) & g_AreaStack[(int)v16->otherarea >> 3]) == 0 )
      {
        m_PortalKey = v16->m_PortalKey;
        if ( ((unsigned __int8)(1 << (m_PortalKey & 7)) & GetBaseLocalClient()->m_chAreaPortalBits[m_PortalKey >> 3]) != 0 )
        {
          planes = pBrushData->planes;
          flDist = (float)((float)((float)(planes[v16->planenum].normal.y * vecVisOrigin->y)
                                 + (float)(planes[v16->planenum].normal.x * vecVisOrigin->x))
                         + (float)(planes[v16->planenum].normal.z * vecVisOrigin->z))
                 - planes[v16->planenum].dist;
          if ( flDist >= -0.1 )
          {
            otherarea = v16->otherarea;
            if ( ((unsigned __int8)(1 << (otherarea & 7)) & GetBaseLocalClient()->m_chAreaBits[otherarea >> 3]) != 0 )
            {
              if ( pVisData != nullptr )
                m_fDistToAreaPortalTolerance = pVisData->m_fDistToAreaPortalTolerance;
              else
                m_fDistToAreaPortalTolerance = 0.1;
              if ( flDist <= m_fDistToAreaPortalTolerance )
              {
                portalRect.left = -1.0;
                portalRect.top = 1.0;
                portalRect.right = 1.0;
                portalRect.bottom = -1.0;
              }
              else if ( !GetPortalScreenExtents(
                           pPortal: v16,
                           clip: &clipTmp,
                           &portalRect,
                           pReflectionWaterHeight,
                           pFrustumPlanes: frustumPlanes) )
              {
                goto LABEL_29;
              }
              if ( GetRectIntersection(pRect1: &portalRect, pRect2: pClipRect, pOut: &intersection) )
              {
                if ( r_DrawPortals.m_pParent != nullptr && r_DrawPortals.m_pParent->m_Value.m_nValue != 0 )
                  CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
                    this: (CUtlVector<CSosOperator::InputData_t,CUtlMemory<CSosOperator::InputData_t,int> > *)&g_PortalRects,
                    elem: g_PortalRects.m_Size,
                    src: (const CSosOperator::InputData_t *)&intersection);
                R_FlowThroughArea(
                  area: v16->otherarea,
                  vecVisOrigin,
                  pClipRect: &intersection,
                  pVisData,
                  pReflectionWaterHeight);
              }
            }
          }
        }
      }
LABEL_29:
      if ( ++iAreaPortal >= pArea->numareaportals )
        break;
      v14 = pArea;
    }
  }
  g_AreaStack[v13] &= ~(1 << (area & 7));
}

//------------------------------------------------------------------------------
// Address: 0x100FE640
// Name: void R_SetupAreaBits(int,struct VisOverrideData_t const __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall R_SetupAreaBits(
        int a1@<ebp>,
        int iForceViewLeaf,
        const VisOverrideData_t *pVisData,
        float *pWaterReflectionHeight)
{
  const VisOverrideData_t *v4; // edi
  const VisOverrideData_t *v5; // eax
  int v6; // esi
  int v7; // esi
  float v8; // ecx
  float v9; // eax
  float v10; // edx
  CPortalRect *v11; // esi
  float left; // ecx
  int v13; // esi
  float z; // esi
  double v15; // st7
  double v16; // st6
  double v17; // st5
  __int128 v18; // xmm0
  Vector *m_vPortalCorners; // esi
  int i; // edi
  double v21; // st6
  double v22; // st4
  double v23; // st7
  double v24; // rt1
  double v25; // st4
  double v26; // st7
  double v27; // st5
  double v28; // rtt
  double v29; // st4
  double v30; // st5
  double v31; // st3
  double v32; // st6
  double v33; // rt1
  double v34; // st4
  double v35; // st7
  double v36; // st6
  double v37; // st7
  float v38; // [esp-Ch] [ebp-48h] BYREF
  float v39; // [esp-8h] [ebp-44h]
  float v40; // [esp-4h] [ebp-40h]
  CPortalRect rect; // [esp+0h] [ebp-3Ch] BYREF
  __int128 vVisOrigin; // [esp+10h] [ebp-2Ch] OVERLAPPED BYREF
  Vector vScreenPos; // [esp+20h] [ebp-1Ch]
  float v44; // [esp+2Ch] [ebp-10h]
  int v45; // [esp+30h] [ebp-Ch]
  int area; // [esp+34h] [ebp-8h]
  int retaddr; // [esp+3Ch] [ebp+0h]

  v45 = a1;
  area = retaddr;
  if ( g_GlobalCounter == -1 )
  {
    if ( g_AreaFrustum.m_Size > 0 )
      memset(g_AreaCounter, 0, 4 * g_AreaFrustum.m_Size);
    g_GlobalCounter = 1;
  }
  else
  {
    ++g_GlobalCounter;
  }
  v4 = pVisData;
  if ( pVisData != nullptr )
    v5 = pVisData;
  else
    v5 = (const VisOverrideData_t *)g_EngineRenderer->ViewOrigin(this: g_EngineRenderer);
  v6 = iForceViewLeaf;
  rect.top = v5->m_vecVisOrigin.x;
  rect.right = v5->m_vecVisOrigin.y;
  rect.bottom = v5->m_vecVisOrigin.z;
  rect.left = -1.0;
  v38 = -1.0;
  *(_DWORD *)g_RenderAreaBits = 0;
  dword_105FAB6C = 0;
  dword_105FAB70 = 0;
  dword_105FAB74 = 0;
  dword_105FAB78 = 0;
  dword_105FAB7C = 0;
  dword_105FAB80 = 0;
  dword_105FAB84 = 0;
  *(_DWORD *)g_AreaStack = 0;
  *(_DWORD *)&g_AreaStack[4] = 0;
  *(_DWORD *)&g_AreaStack[8] = 0;
  *(_DWORD *)&g_AreaStack[12] = 0;
  *(_DWORD *)&g_AreaStack[16] = 0;
  *(_DWORD *)&g_AreaStack[20] = 0;
  *(_DWORD *)&g_AreaStack[24] = 0;
  *(_DWORD *)&g_AreaStack[28] = 0;
  v40 = 1.0;
  v39 = 1.0;
  if ( iForceViewLeaf == -1 )
    v6 = CM_PointLeafnum(p: (const Vector *)&rect.top);
  g_bViewerInSolidSpace = false;
  if ( r_portalscloseall.m_pParent != nullptr && r_portalscloseall.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( !GetBaseLocalClient()->m_bAreaBitsValid )
    {
      g_bViewerInSolidSpace = true;
      return;
    }
    *(_DWORD *)g_RenderAreaBits = 0;
    dword_105FAB6C = 0;
    dword_105FAB70 = 0;
    dword_105FAB74 = 0;
    dword_105FAB78 = 0;
    dword_105FAB7C = 0;
    dword_105FAB80 = 0;
    dword_105FAB84 = 0;
    v7 = host_state.worldbrush->leafs[v6].area;
    v8 = v38;
    g_AreaCounter[v7] = g_GlobalCounter;
    v9 = v40;
    g_RenderAreaBits[v7 >> 3] |= 1 << (v7 & 7);
    v10 = v39;
    g_VisibleAreas[0] = v7;
    v11 = &g_AreaRect[v7];
    v11->left = v8;
    left = rect.left;
    v11->top = v10;
    v11->right = v9;
    g_nVisibleAreas = 1;
    v11->bottom = left;
    goto LABEL_53;
  }
  v13 = v6 << 6;
  if ( (*((_BYTE *)&host_state.worldbrush->leafs->contents + v13) & 1) == 0
    && !GetBaseLocalClient()->ishltv
    && GetBaseLocalClient()->m_bAreaBitsValid
    && (r_portalsopenall.m_pParent == nullptr || r_portalsopenall.m_pParent->m_Value.m_nValue == 0) )
  {
    LODWORD(z) = *(__int16 *)((char *)&host_state.worldbrush->leafs->area + v13);
    vScreenPos.z = z;
    if ( r_ShowViewerArea.m_pParent != nullptr && r_ShowViewerArea.m_pParent->m_Value.m_nValue != 0 )
      Con_NPrintf(idx: 3u, fmt: "(%d) Viewer area: %d", 0, z);
    g_nVisibleAreas = 0;
    if ( pVisData != nullptr
      && pVisData->m_bTrimFrustumToPortalCorners
      && r_ClipAreaFrustums.m_pParent != nullptr
      && r_ClipAreaFrustums.m_pParent->m_Value.m_nValue != 0 )
    {
      v15 = g_CurrentViewOrigin.x - pVisData->m_vPortalOrigin.x;
      *((float *)&vVisOrigin + 1) = v15;
      v16 = g_CurrentViewOrigin.y - pVisData->m_vPortalOrigin.y;
      *((float *)&vVisOrigin + 2) = v16;
      v17 = g_CurrentViewOrigin.z - pVisData->m_vPortalOrigin.z;
      *((float *)&vVisOrigin + 3) = v17;
      if ( fabs(
             v15 * pVisData->m_vPortalForward.x
           + v16 * pVisData->m_vPortalForward.y
           + v17 * pVisData->m_vPortalForward.z) > 16.0
        || (v44 = *((float *)&vVisOrigin + 2) * *((float *)&vVisOrigin + 2),
            v18 = 0,
            *(float *)&v18 = fsqrt(
                               (float)((float)(*((float *)&vVisOrigin + 2) * *((float *)&vVisOrigin + 2))
                                     + (float)(*((float *)&vVisOrigin + 3) * *((float *)&vVisOrigin + 3)))
                             + (float)(*((float *)&vVisOrigin + 1) * *((float *)&vVisOrigin + 1))),
            vVisOrigin = v18,
            *(float *)&v18 > pVisData->m_flPortalRadius) )
      {
        rect.left = 1.0;
        v38 = 1.0;
        m_vPortalCorners = pVisData->m_vPortalCorners;
        v39 = -1.0;
        v40 = -1.0;
        for ( i = 4; i != 0; --i )
        {
          g_EngineRenderer->ClipTransform(
            this: g_EngineRenderer,
            a2: m_vPortalCorners,
            a3: (Vector *)((char *)&vVisOrigin + 4));
          v21 = v38;
          if ( *((float *)&vVisOrigin + 1) <= (double)v38 )
            v21 = *((float *)&vVisOrigin + 1);
          v38 = v21;
          v22 = rect.left;
          if ( *((float *)&vVisOrigin + 2) <= (double)rect.left )
            v22 = *((float *)&vVisOrigin + 2);
          rect.left = v22;
          v23 = v40;
          if ( *((float *)&vVisOrigin + 1) >= (double)v40 )
            v23 = *((float *)&vVisOrigin + 1);
          v24 = v22;
          v25 = v23;
          v26 = v24;
          v40 = v25;
          v27 = v39;
          if ( *((float *)&vVisOrigin + 2) >= (double)v39 )
            v27 = *((float *)&vVisOrigin + 2);
          v28 = v25;
          v29 = v27;
          v30 = v28;
          ++m_vPortalCorners;
          v39 = v29;
        }
        v31 = v21;
        v32 = -1.0;
        if ( v31 < -1.0 )
          v31 = -1.0;
        v38 = v31;
        v33 = v29;
        v34 = v26;
        v35 = v33;
        if ( v34 >= -1.0 )
          v32 = v34;
        rect.left = v32;
        if ( v30 > 1.0 )
          v30 = 1.0;
        v40 = v30;
        v36 = v35;
        v37 = 1.0;
        if ( v36 <= 1.0 )
          v37 = v36;
        v4 = pVisData;
        v39 = v37;
        z = vScreenPos.z;
      }
    }
    R_FlowThroughArea(
      area: SLODWORD(z),
      vecVisOrigin: (const Vector *)&rect.top,
      pClipRect: (const CPortalRect *)&v38,
      pVisData: v4,
      pReflectionWaterHeight: pWaterReflectionHeight);
    goto LABEL_53;
  }
  g_bViewerInSolidSpace = true;
  if ( r_ShowViewerArea.m_pParent != nullptr && r_ShowViewerArea.m_pParent->m_Value.m_nValue != 0 )
  {
    Con_NPrintf(idx: 3u, fmt: "(%d), Viewer area: (solid space)", 0);
LABEL_53:
    if ( !g_bViewerInSolidSpace )
      R_SetupVisibleAreaFrustums();
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FEAA0
// Name: void R_Areaportal_LevelInit(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_Areaportal_LevelInit()
{
  int m_nAreas; // [esp-4h] [ebp-4h]

  m_nAreas = host_state.worldbrush->m_nAreas;
  g_AreaFrustum.m_Size = 0;
  CUtlVector<Frustum_t,CUtlMemoryAligned<Frustum_t,16>>::InsertMultipleBefore(
    this: &g_AreaFrustum,
    elem: 0,
    num: m_nAreas);
  _V_memset(dest: g_AreaCounter, fill: 0, count: 1024);
  g_GlobalCounter = 1;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x100FD370
// Name: void __near * MemAlloc_ReallocAligned(void __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl MemAlloc_ReallocAligned(unsigned __int8 *ptr, unsigned int size, unsigned int align)
{
  void *v4; // ebx
  unsigned int v5; // esi
  unsigned __int8 *pResult; // [esp+10h] [ebp+10h]

  if ( ((align - 1) & align) != 0 )
    return nullptr;
  if ( ((align - 1) & (unsigned int)ptr) != 0 )
    return nullptr;
  if ( ptr == nullptr )
    return (unsigned __int8 *)MemAlloc_AllocAlignedUnattributed(size, align);
  v4 = *(void **)(((unsigned int)ptr & 0xFFFFFFFC) - 4);
  v5 = _g_pMemAlloc->GetSize(this: _g_pMemAlloc, a2: v4);
  if ( v5 >= ptr - (_BYTE *)v4 + size )
    return ptr;
  pResult = (unsigned __int8 *)MemAlloc_AllocAlignedUnattributed(size, align);
  memcpy(dst: pResult, src: ptr, count: v5 - (ptr - (_BYTE *)v4));
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
  return pResult;
}

//------------------------------------------------------------------------------
// Address: 0x100FD410
// Name: GetPortalScreenExtents
// Source: json
//------------------------------------------------------------------------------
bool __cdecl GetPortalScreenExtents(
        dareaportal_t *pPortal,
        portalclip_t *clip,
        CPortalRect *portalRect,
        float *pReflectionWaterHeight,
        VPlane *pFrustumPlanes)
{
  CPortalRect *v5; // eax
  unsigned int m_nClipPortalVerts; // ecx
  int v7; // edi
  int v8; // ebx
  Vector *v9; // eax
  float *v10; // edx
  float *v11; // ecx
  float *v12; // eax
  unsigned int v13; // esi
  bool v14; // zf
  int v15; // esi
  float *v16; // eax
  Vector *v17; // ecx
  int v18; // edx
  float *v19; // eax
  BOOL v20; // ecx
  Vector *v21; // esi
  float v22; // xmm0_4
  BOOL v23; // ecx
  Vector *v24; // edx
  float v25; // xmm1_4
  int v26; // edi
  float *v27; // ecx
  float v28; // xmm0_4
  float v29; // xmm2_4
  int v30; // ebx
  float v31; // xmm1_4
  portalclip_t *v32; // esi
  double x; // st7
  double left; // st6
  double y; // st6
  double bottom; // st5
  double v37; // st5
  double top; // st6
  double v39; // st6
  double right; // st7
  Vector screenPos; // [esp+0h] [ebp-3Ch] BYREF
  int nPassCount; // [esp+Ch] [ebp-30h]
  BOOL v44; // [esp+10h] [ebp-2Ch]
  int v45; // [esp+14h] [ebp-28h]
  float *p_z; // [esp+18h] [ebp-24h]
  int iPlane; // [esp+1Ch] [ebp-20h]
  int v48; // [esp+20h] [ebp-1Ch]
  worldbrushdata_t *pBrushData; // [esp+24h] [ebp-18h]
  float *v50; // [esp+28h] [ebp-14h]
  int nOutVerts; // [esp+2Ch] [ebp-10h]
  int nStartVerts; // [esp+30h] [ebp-Ch]
  int j; // [esp+34h] [ebp-8h]
  bool bValidExtents; // [esp+3Bh] [ebp-1h]

  v5 = portalRect;
  portalRect->bottom = 1.0e24;
  portalRect->left = 1.0e24;
  portalRect->top = -1.0e24;
  portalRect->right = -1.0e24;
  pBrushData = host_state.worldbrush;
  m_nClipPortalVerts = pPortal->m_nClipPortalVerts;
  bValidExtents = false;
  if ( m_nClipPortalVerts >= 0x20 )
  {
    v7 = 32;
    nStartVerts = 32;
  }
  else
  {
    v7 = m_nClipPortalVerts;
    nStartVerts = m_nClipPortalVerts;
  }
  j = 0;
  nPassCount = (pReflectionWaterHeight != nullptr) + 1;
  if ( (pReflectionWaterHeight != nullptr) == -1 )
    goto LABEL_52;
  p_z = &pFrustumPlanes->m_Normal.z;
  do
  {
    v8 = 0;
    if ( v7 >= 4 )
    {
      v9 = &pBrushData->m_pClipPortalVerts[pPortal->m_FirstClipPortalVert];
      v10 = &v9->z;
      v11 = &clip->v0[1].z;
      v12 = &v9[1].z;
      v13 = ((unsigned int)(v7 - 4) >> 2) + 1;
      v8 = 4 * v13;
      do
      {
        v14 = j == 1;
        *(v11 - 5) = *(v10 - 2);
        *(v11 - 4) = *(v10 - 1);
        *(v11 - 3) = *v10;
        if ( v14 )
          *(v11 - 3) = (float)(*pReflectionWaterHeight * 2.0) - *(v11 - 3);
        v14 = j == 1;
        *(v11 - 2) = v10[1];
        *(v11 - 1) = *(v12 - 1);
        *v11 = *v12;
        if ( v14 )
          *v11 = (float)(*pReflectionWaterHeight * 2.0) - *v11;
        v14 = j == 1;
        v11[1] = v10[4];
        v11[2] = v12[2];
        v11[3] = v12[3];
        if ( v14 )
          v11[3] = (float)(*pReflectionWaterHeight * 2.0) - v11[3];
        v14 = j == 1;
        v11[4] = v10[7];
        v11[5] = v12[5];
        v11[6] = v12[6];
        if ( v14 )
          v11[6] = (float)(*pReflectionWaterHeight * 2.0) - v11[6];
        v10 += 12;
        v12 += 12;
        v11 += 12;
        --v13;
      }
      while ( v13 != 0 );
      v7 = nStartVerts;
    }
    if ( v8 < v7 )
    {
      v15 = j;
      v16 = &clip->v0[v8].z;
      v17 = &pBrushData->m_pClipPortalVerts[v8 + pPortal->m_FirstClipPortalVert];
      v18 = v7 - v8;
      do
      {
        *(v16 - 2) = v17->x;
        *(v16 - 1) = v17->y;
        *v16 = v17->z;
        if ( v15 == 1 )
          *v16 = (float)(*pReflectionWaterHeight * 2.0) - *v16;
        ++v17;
        v16 += 3;
        --v18;
      }
      while ( v18 != 0 );
    }
    v19 = p_z;
    v20 = false;
    iPlane = 0;
    v50 = p_z;
    while ( 1 )
    {
      v21 = clip->lists[v20];
      v22 = *(v19 - 2);
      nOutVerts = 0;
      v23 = !v20;
      v24 = clip->lists[v23];
      v44 = v23;
      v25 = (float)((float)((float)(v21[v7 - 1].y * *(v19 - 1)) + (float)(v22 * v21[v7 - 1].x))
                  + (float)(v21[v7 - 1].z * *v19))
          - v19[1];
      if ( v7 <= 0 )
        break;
      v45 = -8 - (_DWORD)v21;
      v26 = 4 * (3 * v7 - 3);
      v27 = &v21->z;
      v48 = nStartVerts;
      while ( 1 )
      {
        v28 = *(v27 - 2);
        v29 = (float)((float)((float)(*(v27 - 1) * *(v19 - 1)) + (float)(*(v19 - 2) * v28)) + (float)(*v19 * *v27))
            - v19[1];
        v30 = nOutVerts;
        if ( v29 > 0.0 != v25 > 0.0 && nOutVerts < 32 )
        {
          v31 = v25 / (float)(v25 - v29);
          v24->x = (float)((float)(v28 - *(float *)((char *)&v21->x + v26)) * v31) + *(float *)((char *)&v21->x + v26);
          v24->y = (float)((float)(*(v27 - 1) - *(float *)((char *)&v21->y + v26)) * v31)
                 + *(float *)((char *)&v21->y + v26);
          ++v30;
          v24->z = (float)((float)(*v27 - *(float *)((char *)&v21->z + v26)) * v31) + *(float *)((char *)&v21->z + v26);
          nOutVerts = v30;
          ++v24;
        }
        if ( v29 > 0.0 && v30 < 32 )
        {
          ++v30;
          v24->x = *(v27 - 2);
          nOutVerts = v30;
          ++v24;
          v24[-1].y = *(v27 - 1);
          v24[-1].z = *v27;
        }
        v26 = (int)v27 + v45;
        v27 += 3;
        v14 = v48-- == 1;
        v25 = v29;
        if ( v14 )
          break;
        v19 = v50;
      }
      if ( v30 == 0 )
      {
        v7 = nStartVerts;
        break;
      }
      v20 = v44;
      v19 = v50 + 4;
      v7 = v30;
      nStartVerts = v30;
      ++iPlane;
      v50 += 4;
      if ( iPlane >= 4 )
      {
        if ( v30 > 0 )
        {
          v32 = clip;
          do
          {
            g_EngineRenderer->ClipTransform(this: g_EngineRenderer, a2: (const Vector *)v32, a3: &screenPos);
            x = screenPos.x;
            left = portalRect->left;
            if ( screenPos.x <= left )
              left = screenPos.x;
            portalRect->left = left;
            y = screenPos.y;
            bottom = portalRect->bottom;
            if ( screenPos.y <= bottom )
              bottom = screenPos.y;
            portalRect->bottom = bottom;
            v37 = y;
            top = portalRect->top;
            if ( v37 >= top )
              top = v37;
            portalRect->top = top;
            v39 = x;
            right = portalRect->right;
            if ( v39 >= right )
              right = v39;
            v32 = (portalclip_t *)((char *)v32 + 12);
            portalRect->right = right;
            --v30;
          }
          while ( v30 != 0 );
        }
        bValidExtents = true;
        break;
      }
    }
    ++j;
  }
  while ( j < nPassCount );
  if ( !bValidExtents )
  {
    v5 = portalRect;
LABEL_52:
    v5->bottom = 0.0;
    v5->left = 0.0;
    v5->top = 0.0;
    v5->right = 0.0;
  }
  return bValidExtents;
}

//------------------------------------------------------------------------------
// Address: 0x100FD870
// Name: bool GetRectIntersection(class CPortalRect const __near *,class CPortalRect const __near *,class CPortalRect __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl GetRectIntersection(const CPortalRect *pRect1, const CPortalRect *pRect2, CPortalRect *pOut)
{
  double left; // st7
  double right; // st6
  double bottom; // st7
  double top; // st6

  left = pRect2->left;
  if ( pRect1->left >= left )
    left = pRect1->left;
  pOut->left = left;
  right = pRect2->right;
  if ( pRect1->right <= right )
    right = pRect1->right;
  pOut->right = right;
  if ( left >= right )
    return false;
  bottom = pRect2->bottom;
  if ( pRect1->bottom >= bottom )
    bottom = pRect1->bottom;
  pOut->bottom = bottom;
  top = pRect2->top;
  if ( pRect1->top <= top )
    top = pRect1->top;
  pOut->top = top;
  return bottom < top;
}

//------------------------------------------------------------------------------
// Address: 0x100FD980
// Name: R_SetupVisibleAreaFrustums
// Source: json
//------------------------------------------------------------------------------
void R_SetupVisibleAreaFrustums()
{
  const CViewSetup *v0; // eax
  const CViewSetup *v1; // ebx
  float m_OrthoRight; // xmm1_4
  float m_OrthoTop; // xmm2_4
  double v4; // st7
  float (__thiscall *GetFovY)(IRender *); // edx
  long double v6; // st7
  long double v7; // st7
  int v8; // edx
  int v9; // edi
  int v10; // ecx
  CPortalRect *v11; // eax
  float v12; // xmm3_4
  Frustum_t *v13; // esi
  bool v14; // zf
  float v15; // xmm3_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  ConVar *m_pParent; // esi
  int i; // edi
  int m_nValue; // ecx
  int v21; // eax
  Frustum_t *v22; // esi
  VPlane planes[6]; // [esp+1Ch] [ebp-C4h] BYREF
  CPortalRect portalWindow; // [esp+7Ch] [ebp-64h]
  float v25; // [esp+8Ch] [ebp-54h]
  float v26; // [esp+90h] [ebp-50h]
  CPortalRect viewWindow; // [esp+94h] [ebp-4Ch]
  Vector up; // [esp+A4h] [ebp-3Ch]
  Vector right; // [esp+B0h] [ebp-30h] BYREF
  Vector viewOrigin; // [esp+BCh] [ebp-24h]
  Vector forward; // [esp+C8h] [ebp-18h] BYREF
  Vector normal; // [esp+D4h] [ebp-Ch] BYREF

  v0 = g_EngineRenderer->ViewGetCurrent(this: g_EngineRenderer);
  v1 = v0;
  if ( v0->m_bOrtho )
  {
    m_OrthoRight = v0->m_OrthoRight;
    m_OrthoTop = v0->m_OrthoTop;
    viewWindow.left = v0->m_OrthoLeft;
    viewWindow.bottom = v0->m_OrthoBottom;
  }
  else
  {
    v4 = ((double (__thiscall *)(IRender *))g_EngineRenderer->GetFov)(a1: g_EngineRenderer);
    GetFovY = g_EngineRenderer->GetFovY;
    v6 = tan(v4 * 0.5 * 0.017453292);
    viewWindow.right = v6;
    viewWindow.left = -v6;
    m_OrthoRight = viewWindow.right;
    v7 = tan(((double (__thiscall *)(IRender *))GetFovY)(a1: g_EngineRenderer) * 0.5 * 0.017453292);
    viewWindow.top = v7;
    viewWindow.bottom = -v7;
    m_OrthoTop = viewWindow.top;
  }
  viewOrigin = g_CurrentViewOrigin;
  forward = g_CurrentViewForward;
  right = g_CurrentViewRight;
  up = g_CurrentViewUp;
  v8 = g_nVisibleAreas;
  v9 = 0;
  if ( g_nVisibleAreas > 0 )
  {
    v26 = m_OrthoRight - viewWindow.left;
    v25 = m_OrthoTop - viewWindow.bottom;
    do
    {
      v10 = g_VisibleAreas[v9];
      v11 = &g_AreaRect[v10];
      v12 = v11->right;
      portalWindow.left = (float)((float)((float)(v11->left - -1.0) * v26) * 0.5) + viewWindow.left;
      portalWindow.top = (float)((float)((float)(v11->top - -1.0) * v25) * 0.5) + viewWindow.bottom;
      v13 = &g_AreaFrustum.m_Memory.m_pMemory[v10];
      v14 = !v1->m_bOrtho;
      v15 = (float)((float)((float)(v12 - -1.0) * v26) * 0.5) + viewWindow.left;
      portalWindow.bottom = (float)((float)((float)(v11->bottom - -1.0) * v25) * 0.5) + viewWindow.bottom;
      if ( v14 )
      {
        normal.x = (float)(forward.x * v15) - right.x;
        normal.y = (float)(forward.y * v15) - right.y;
        normal.z = (float)(forward.z * v15) - right.z;
        VectorNormalize(vec: &normal);
        planes[0].m_Normal = normal;
        planes[0].m_Dist = (float)((float)(normal.x * viewOrigin.x) + (float)(normal.y * viewOrigin.y))
                         + (float)(normal.z * viewOrigin.z);
        normal.x = g_CurrentViewRight.x - (float)(forward.x * portalWindow.left);
        normal.y = g_CurrentViewRight.y - (float)(forward.y * portalWindow.left);
        normal.z = g_CurrentViewRight.z - (float)(forward.z * portalWindow.left);
        VectorNormalize(vec: &normal);
        planes[1].m_Normal = normal;
        planes[1].m_Dist = (float)((float)(normal.x * viewOrigin.x) + (float)(normal.y * viewOrigin.y))
                         + (float)(normal.z * viewOrigin.z);
        normal.x = (float)(forward.x * portalWindow.top) - up.x;
        normal.y = (float)(forward.y * portalWindow.top) - up.y;
        normal.z = (float)(forward.z * portalWindow.top) - up.z;
        VectorNormalize(vec: &normal);
        planes[2].m_Normal = normal;
        planes[2].m_Dist = (float)((float)(normal.x * viewOrigin.x) + (float)(normal.y * viewOrigin.y))
                         + (float)(normal.z * viewOrigin.z);
        normal.x = up.x - (float)(forward.x * portalWindow.bottom);
        normal.y = up.y - (float)(forward.y * portalWindow.bottom);
        normal.z = up.z - (float)(forward.z * portalWindow.bottom);
        VectorNormalize(vec: &normal);
        planes[3].m_Normal = normal;
        planes[3].m_Dist = (float)((float)(normal.x * viewOrigin.x) + (float)(normal.y * viewOrigin.y))
                         + (float)(normal.z * viewOrigin.z);
        planes[4].m_Dist = (float)((float)((float)(forward.x * viewOrigin.x) + (float)(forward.y * viewOrigin.y))
                                 + (float)(forward.z * viewOrigin.z))
                         + v1->zNear;
        planes[4].m_Normal = forward;
        v17 = (float)((float)((float)((float)-forward.x * viewOrigin.x) + (float)((float)-forward.y * viewOrigin.y))
                    + (float)((float)-forward.z * viewOrigin.z))
            - v1->zFar;
      }
      else
      {
        planes[1].m_Normal = right;
        planes[1].m_Dist = (float)((float)((float)(viewOrigin.y * right.y) + (float)(viewOrigin.x * right.x))
                                 + (float)(viewOrigin.z * right.z))
                         + portalWindow.left;
        planes[0].m_Normal.z = -right.z;
        planes[0].m_Dist = (float)-v15
                         - (float)((float)((float)(viewOrigin.y * right.y) + (float)(viewOrigin.x * right.x))
                                 + (float)(viewOrigin.z * right.z));
        planes[2].m_Normal = up;
        planes[0].m_Normal.y = -right.y;
        planes[3].m_Normal.x = -up.x;
        v16 = (float)((float)(up.x * viewOrigin.x) + (float)(up.y * viewOrigin.y)) + (float)(up.z * viewOrigin.z);
        planes[3].m_Normal.y = -up.y;
        planes[3].m_Dist = (float)-portalWindow.bottom - v16;
        planes[3].m_Normal.z = -up.z;
        planes[4].m_Normal = forward;
        v17 = -1000000.0;
        planes[0].m_Normal.x = -right.x;
        planes[2].m_Dist = v16 + portalWindow.top;
        planes[4].m_Dist = 0.0;
      }
      planes[5].m_Normal.x = -forward.x;
      planes[5].m_Normal.y = -forward.y;
      planes[5].m_Normal.z = -forward.z;
      planes[5].m_Dist = v17;
      Frustum_t::SetPlanes(this: v13, pPlanes: planes);
      v8 = g_nVisibleAreas;
      ++v9;
    }
    while ( v9 < g_nVisibleAreas );
  }
  m_pParent = r_snapportal.m_pParent;
  if ( r_snapportal.m_pParent == nullptr || r_snapportal.m_pParent->m_Value.m_nValue >= 0 )
  {
    for ( i = 0; i < v8; ++i )
    {
      if ( m_pParent != nullptr )
        m_nValue = m_pParent->m_Value.m_nValue;
      else
        m_nValue = 0;
      v21 = g_VisibleAreas[i];
      if ( v21 == m_nValue )
      {
        v22 = &g_AreaFrustum.m_Memory.m_pMemory[v21];
        Frustum_t::SetPlane(
          this: v22,
          i: 4,
          vecNormal: &forward,
          dist: (float)((float)(forward.x * viewOrigin.x) + (float)(forward.y * viewOrigin.y))
        + (float)(forward.z * viewOrigin.z));
        right.x = -forward.x;
        right.y = -forward.y;
        right.z = -forward.z;
        Frustum_t::SetPlane(
          this: v22,
          i: 5,
          vecNormal: &right,
          dist: (float)((float)((float)-forward.x * (float)((float)(forward.x * 500.0) + viewOrigin.x))
                + (float)((float)-forward.y * (float)((float)(forward.y * 500.0) + viewOrigin.y)))
        + (float)((float)-forward.z * (float)((float)(forward.z * 500.0) + viewOrigin.z)));
        CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&r_snapportal.IConVar, value: -1);
        CSGFrustum(frustum: v22);
        v8 = g_nVisibleAreas;
        m_pParent = r_snapportal.m_pParent;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FE180
// Name: class Frustum_t const __near * GetAreaFrustum(int)
// Source: json
//------------------------------------------------------------------------------
const Frustum_t *__cdecl GetAreaFrustum(int area)
{
  if ( g_AreaCounter[area] == g_GlobalCounter )
    return &g_AreaFrustum.m_Memory.m_pMemory[area];
  else
    return &g_Frustum;
}

//------------------------------------------------------------------------------
// Address: 0x100FE1B0
// Name: int GetAllAreaFrustums(class Frustum_t __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetAllAreaFrustums(Frustum_t **pFrustumList, int listMax)
{
  int result; // eax
  Frustum_t **v3; // ecx
  int v4; // edx
  int i; // esi

  result = g_AreaFrustum.m_Size;
  if ( listMax < g_AreaFrustum.m_Size )
    result = listMax;
  if ( result > 0 )
  {
    v3 = pFrustumList;
    v4 = 0;
    for ( i = result; i != 0; --i )
    {
      if ( *(Frustum_t **)((char *)v3 + (char *)g_AreaCounter - (char *)pFrustumList) == (Frustum_t *)g_GlobalCounter )
        *v3 = &g_AreaFrustum.m_Memory.m_pMemory[v4];
      else
        *v3 = &g_Frustum;
      ++v4;
      ++v3;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100FE2B0
// Name: void R_Areaportal_LevelShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_Areaportal_LevelShutdown()
{
  Frustum_t *m_pMemory; // eax
  CPortalRect *v1; // eax

  m_pMemory = g_AreaFrustum.m_Memory.m_pMemory;
  g_AreaFrustum.m_Size = 0;
  if ( g_AreaFrustum.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_AreaFrustum.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(((int)g_AreaFrustum.m_Memory.m_pMemory & 0xFFFFFFFC) - 4));
      m_pMemory = nullptr;
      g_AreaFrustum.m_Memory.m_pMemory = nullptr;
    }
    g_AreaFrustum.m_Memory.m_nAllocationCount = 0;
  }
  g_AreaFrustum.m_pElements = m_pMemory;
  g_PortalRects.m_Size = 0;
  if ( g_PortalRects.m_Memory.m_nGrowSize < 0 )
  {
    g_PortalRects.m_pElements = g_PortalRects.m_Memory.m_pMemory;
  }
  else
  {
    v1 = g_PortalRects.m_Memory.m_pMemory;
    if ( g_PortalRects.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_PortalRects.m_Memory.m_pMemory);
      v1 = nullptr;
      g_PortalRects.m_Memory.m_pMemory = nullptr;
    }
    g_PortalRects.m_Memory.m_nAllocationCount = 0;
    g_PortalRects.m_pElements = v1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FE340
// Name: R_FlowThroughArea
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_FlowThroughArea(
        int area,
        const Vector *vecVisOrigin,
        const CPortalRect *pClipRect,
        const VisOverrideData_t *pVisData,
        float *pReflectionWaterHeight)
{
  unsigned int v5; // ecx
  int v6; // eax
  CPortalRect *v7; // ecx
  double left; // st7
  double bottom; // st7
  double top; // st7
  double right; // st7
  char v12; // al
  int v13; // ebx
  darea_t *v14; // esi
  bool v15; // cc
  dareaportal_t *v16; // esi
  int m_PortalKey; // edi
  cplane_t *planes; // edx
  int otherarea; // edi
  float m_fDistToAreaPortalTolerance; // xmm0_4
  portalclip_t clipTmp; // [esp+8h] [ebp-398h] BYREF
  VPlane frustumPlanes[6]; // [esp+310h] [ebp-90h] BYREF
  CPortalRect intersection; // [esp+370h] [ebp-30h] BYREF
  CPortalRect portalRect; // [esp+380h] [ebp-20h] BYREF
  float flDist; // [esp+390h] [ebp-10h]
  darea_t *pArea; // [esp+394h] [ebp-Ch]
  worldbrushdata_t *pBrushData; // [esp+398h] [ebp-8h]
  int iAreaPortal; // [esp+39Ch] [ebp-4h]

  v5 = g_GlobalCounter;
  if ( g_AreaCounter[area] == g_GlobalCounter )
  {
    v7 = &g_AreaRect[area];
    left = pClipRect->left;
    if ( v7->left <= left )
      left = v7->left;
    v7->left = left;
    bottom = pClipRect->bottom;
    if ( v7->bottom <= bottom )
      bottom = v7->bottom;
    v7->bottom = bottom;
    top = pClipRect->top;
    if ( v7->top >= top )
      top = v7->top;
    v7->top = top;
    right = pClipRect->right;
    if ( v7->right >= right )
      right = v7->right;
    v7->right = right;
  }
  else
  {
    v6 = g_nVisibleAreas;
    g_VisibleAreas[g_nVisibleAreas] = area;
    g_nVisibleAreas = v6 + 1;
    g_AreaCounter[area] = v5;
    g_AreaRect[area] = *pClipRect;
  }
  v12 = 1 << (area & 7);
  v13 = area >> 3;
  g_RenderAreaBits[v13] |= v12;
  g_AreaStack[v13] |= v12;
  pBrushData = host_state.worldbrush;
  v14 = &host_state.worldbrush->m_pAreas[area];
  clipTmp.lists[0] = (Vector *)&clipTmp;
  pArea = v14;
  clipTmp.lists[1] = clipTmp.v1;
  Frustum_t::GetPlanes(this: &g_Frustum, pPlanesOut: frustumPlanes);
  v15 = v14->numareaportals <= 0;
  iAreaPortal = 0;
  if ( !v15 )
  {
    while ( 1 )
    {
      v16 = &pBrushData->m_pAreaPortals[iAreaPortal + v14->firstareaportal];
      if ( ((unsigned __int8)(1 << (v16->otherarea & 7)) & g_AreaStack[(int)v16->otherarea >> 3]) == 0 )
      {
        m_PortalKey = v16->m_PortalKey;
        if ( ((unsigned __int8)(1 << (m_PortalKey & 7)) & GetBaseLocalClient()->m_chAreaPortalBits[m_PortalKey >> 3]) != 0 )
        {
          planes = pBrushData->planes;
          flDist = (float)((float)((float)(planes[v16->planenum].normal.y * vecVisOrigin->y)
                                 + (float)(planes[v16->planenum].normal.x * vecVisOrigin->x))
                         + (float)(planes[v16->planenum].normal.z * vecVisOrigin->z))
                 - planes[v16->planenum].dist;
          if ( flDist >= -0.1 )
          {
            otherarea = v16->otherarea;
            if ( ((unsigned __int8)(1 << (otherarea & 7)) & GetBaseLocalClient()->m_chAreaBits[otherarea >> 3]) != 0 )
            {
              if ( pVisData != nullptr )
                m_fDistToAreaPortalTolerance = pVisData->m_fDistToAreaPortalTolerance;
              else
                m_fDistToAreaPortalTolerance = 0.1;
              if ( flDist <= m_fDistToAreaPortalTolerance )
              {
                portalRect.left = -1.0;
                portalRect.top = 1.0;
                portalRect.right = 1.0;
                portalRect.bottom = -1.0;
              }
              else if ( !GetPortalScreenExtents(
                           pPortal: v16,
                           clip: &clipTmp,
                           &portalRect,
                           pReflectionWaterHeight,
                           pFrustumPlanes: frustumPlanes) )
              {
                goto LABEL_29;
              }
              if ( GetRectIntersection(pRect1: &portalRect, pRect2: pClipRect, pOut: &intersection) )
              {
                if ( r_DrawPortals.m_pParent != nullptr && r_DrawPortals.m_pParent->m_Value.m_nValue != 0 )
                  CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
                    this: (CUtlVector<CSosOperator::InputData_t,CUtlMemory<CSosOperator::InputData_t,int> > *)&g_PortalRects,
                    elem: g_PortalRects.m_Size,
                    src: (const CSosOperator::InputData_t *)&intersection);
                R_FlowThroughArea(
                  area: v16->otherarea,
                  vecVisOrigin,
                  pClipRect: &intersection,
                  pVisData,
                  pReflectionWaterHeight);
              }
            }
          }
        }
      }
LABEL_29:
      if ( ++iAreaPortal >= pArea->numareaportals )
        break;
      v14 = pArea;
    }
  }
  g_AreaStack[v13] &= ~(1 << (area & 7));
}

//------------------------------------------------------------------------------
// Address: 0x100FE620
// Name: void R_SetupAreaBits(int,struct VisOverrideData_t const __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall R_SetupAreaBits(
        int a1@<ebp>,
        int iForceViewLeaf,
        const VisOverrideData_t *pVisData,
        float *pWaterReflectionHeight)
{
  const VisOverrideData_t *v4; // edi
  const VisOverrideData_t *v5; // eax
  int v6; // esi
  int v7; // esi
  float v8; // ecx
  float v9; // eax
  float v10; // edx
  CPortalRect *v11; // esi
  float left; // ecx
  int v13; // esi
  float z; // esi
  double v15; // st7
  double v16; // st6
  double v17; // st5
  __int128 v18; // xmm0
  Vector *m_vPortalCorners; // esi
  int i; // edi
  double v21; // st6
  double v22; // st4
  double v23; // st7
  double v24; // rt1
  double v25; // st4
  double v26; // st7
  double v27; // st5
  double v28; // rtt
  double v29; // st4
  double v30; // st5
  double v31; // st3
  double v32; // st6
  double v33; // rt1
  double v34; // st4
  double v35; // st7
  double v36; // st6
  double v37; // st7
  float v38; // [esp-Ch] [ebp-48h] BYREF
  float v39; // [esp-8h] [ebp-44h]
  float v40; // [esp-4h] [ebp-40h]
  CPortalRect rect; // [esp+0h] [ebp-3Ch] BYREF
  __int128 vVisOrigin; // [esp+10h] [ebp-2Ch] OVERLAPPED BYREF
  Vector vScreenPos; // [esp+20h] [ebp-1Ch]
  float v44; // [esp+2Ch] [ebp-10h]
  int v45; // [esp+30h] [ebp-Ch]
  int area; // [esp+34h] [ebp-8h]
  int retaddr; // [esp+3Ch] [ebp+0h]

  v45 = a1;
  area = retaddr;
  if ( g_GlobalCounter == -1 )
  {
    if ( g_AreaFrustum.m_Size > 0 )
      memset(g_AreaCounter, 0, 4 * g_AreaFrustum.m_Size);
    g_GlobalCounter = 1;
  }
  else
  {
    ++g_GlobalCounter;
  }
  v4 = pVisData;
  if ( pVisData != nullptr )
    v5 = pVisData;
  else
    v5 = (const VisOverrideData_t *)g_EngineRenderer->ViewOrigin(this: g_EngineRenderer);
  v6 = iForceViewLeaf;
  rect.top = v5->m_vecVisOrigin.x;
  rect.right = v5->m_vecVisOrigin.y;
  rect.bottom = v5->m_vecVisOrigin.z;
  rect.left = -1.0;
  v38 = -1.0;
  *(_DWORD *)g_RenderAreaBits = 0;
  dword_105FAB6C = 0;
  dword_105FAB70 = 0;
  dword_105FAB74 = 0;
  dword_105FAB78 = 0;
  dword_105FAB7C = 0;
  dword_105FAB80 = 0;
  dword_105FAB84 = 0;
  *(_DWORD *)g_AreaStack = 0;
  *(_DWORD *)&g_AreaStack[4] = 0;
  *(_DWORD *)&g_AreaStack[8] = 0;
  *(_DWORD *)&g_AreaStack[12] = 0;
  *(_DWORD *)&g_AreaStack[16] = 0;
  *(_DWORD *)&g_AreaStack[20] = 0;
  *(_DWORD *)&g_AreaStack[24] = 0;
  *(_DWORD *)&g_AreaStack[28] = 0;
  v40 = 1.0;
  v39 = 1.0;
  if ( iForceViewLeaf == -1 )
    v6 = CM_PointLeafnum(p: (const Vector *)&rect.top);
  g_bViewerInSolidSpace = false;
  if ( r_portalscloseall.m_pParent != nullptr && r_portalscloseall.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( !GetBaseLocalClient()->m_bAreaBitsValid )
    {
      g_bViewerInSolidSpace = true;
      return;
    }
    *(_DWORD *)g_RenderAreaBits = 0;
    dword_105FAB6C = 0;
    dword_105FAB70 = 0;
    dword_105FAB74 = 0;
    dword_105FAB78 = 0;
    dword_105FAB7C = 0;
    dword_105FAB80 = 0;
    dword_105FAB84 = 0;
    v7 = host_state.worldbrush->leafs[v6].area;
    v8 = v38;
    g_AreaCounter[v7] = g_GlobalCounter;
    v9 = v40;
    g_RenderAreaBits[v7 >> 3] |= 1 << (v7 & 7);
    v10 = v39;
    g_VisibleAreas[0] = v7;
    v11 = &g_AreaRect[v7];
    v11->left = v8;
    left = rect.left;
    v11->top = v10;
    v11->right = v9;
    g_nVisibleAreas = 1;
    v11->bottom = left;
    goto LABEL_53;
  }
  v13 = v6 << 6;
  if ( (*((_BYTE *)&host_state.worldbrush->leafs->contents + v13) & 1) == 0
    && !GetBaseLocalClient()->ishltv
    && GetBaseLocalClient()->m_bAreaBitsValid
    && (r_portalsopenall.m_pParent == nullptr || r_portalsopenall.m_pParent->m_Value.m_nValue == 0) )
  {
    LODWORD(z) = *(__int16 *)((char *)&host_state.worldbrush->leafs->area + v13);
    vScreenPos.z = z;
    if ( r_ShowViewerArea.m_pParent != nullptr && r_ShowViewerArea.m_pParent->m_Value.m_nValue != 0 )
      Con_NPrintf(idx: 3, fmt: "(%d) Viewer area: %d", 0, z);
    g_nVisibleAreas = 0;
    if ( pVisData != nullptr
      && pVisData->m_bTrimFrustumToPortalCorners
      && r_ClipAreaFrustums.m_pParent != nullptr
      && r_ClipAreaFrustums.m_pParent->m_Value.m_nValue != 0 )
    {
      v15 = g_CurrentViewOrigin.x - pVisData->m_vPortalOrigin.x;
      *((float *)&vVisOrigin + 1) = v15;
      v16 = g_CurrentViewOrigin.y - pVisData->m_vPortalOrigin.y;
      *((float *)&vVisOrigin + 2) = v16;
      v17 = g_CurrentViewOrigin.z - pVisData->m_vPortalOrigin.z;
      *((float *)&vVisOrigin + 3) = v17;
      if ( fabs(
             v15 * pVisData->m_vPortalForward.x
           + v16 * pVisData->m_vPortalForward.y
           + v17 * pVisData->m_vPortalForward.z) > 16.0
        || (v44 = *((float *)&vVisOrigin + 2) * *((float *)&vVisOrigin + 2),
            v18 = 0,
            *(float *)&v18 = fsqrt(
                               (float)((float)(*((float *)&vVisOrigin + 2) * *((float *)&vVisOrigin + 2))
                                     + (float)(*((float *)&vVisOrigin + 3) * *((float *)&vVisOrigin + 3)))
                             + (float)(*((float *)&vVisOrigin + 1) * *((float *)&vVisOrigin + 1))),
            vVisOrigin = v18,
            *(float *)&v18 > pVisData->m_flPortalRadius) )
      {
        rect.left = 1.0;
        v38 = 1.0;
        m_vPortalCorners = pVisData->m_vPortalCorners;
        v39 = -1.0;
        v40 = -1.0;
        for ( i = 4; i != 0; --i )
        {
          g_EngineRenderer->ClipTransform(
            this: g_EngineRenderer,
            a2: m_vPortalCorners,
            a3: (Vector *)((char *)&vVisOrigin + 4));
          v21 = v38;
          if ( *((float *)&vVisOrigin + 1) <= (double)v38 )
            v21 = *((float *)&vVisOrigin + 1);
          v38 = v21;
          v22 = rect.left;
          if ( *((float *)&vVisOrigin + 2) <= (double)rect.left )
            v22 = *((float *)&vVisOrigin + 2);
          rect.left = v22;
          v23 = v40;
          if ( *((float *)&vVisOrigin + 1) >= (double)v40 )
            v23 = *((float *)&vVisOrigin + 1);
          v24 = v22;
          v25 = v23;
          v26 = v24;
          v40 = v25;
          v27 = v39;
          if ( *((float *)&vVisOrigin + 2) >= (double)v39 )
            v27 = *((float *)&vVisOrigin + 2);
          v28 = v25;
          v29 = v27;
          v30 = v28;
          ++m_vPortalCorners;
          v39 = v29;
        }
        v31 = v21;
        v32 = -1.0;
        if ( v31 < -1.0 )
          v31 = -1.0;
        v38 = v31;
        v33 = v29;
        v34 = v26;
        v35 = v33;
        if ( v34 >= -1.0 )
          v32 = v34;
        rect.left = v32;
        if ( v30 > 1.0 )
          v30 = 1.0;
        v40 = v30;
        v36 = v35;
        v37 = 1.0;
        if ( v36 <= 1.0 )
          v37 = v36;
        v4 = pVisData;
        v39 = v37;
        z = vScreenPos.z;
      }
    }
    R_FlowThroughArea(
      area: SLODWORD(z),
      vecVisOrigin: (const Vector *)&rect.top,
      pClipRect: (const CPortalRect *)&v38,
      pVisData: v4,
      pReflectionWaterHeight: pWaterReflectionHeight);
    goto LABEL_53;
  }
  g_bViewerInSolidSpace = true;
  if ( r_ShowViewerArea.m_pParent != nullptr && r_ShowViewerArea.m_pParent->m_Value.m_nValue != 0 )
  {
    Con_NPrintf(idx: 3, fmt: "(%d), Viewer area: (solid space)", 0);
LABEL_53:
    if ( !g_bViewerInSolidSpace )
      R_SetupVisibleAreaFrustums();
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FEA80
// Name: void R_Areaportal_LevelInit(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_Areaportal_LevelInit()
{
  int m_nAreas; // [esp-4h] [ebp-4h]

  m_nAreas = host_state.worldbrush->m_nAreas;
  g_AreaFrustum.m_Size = 0;
  CUtlVector<Frustum_t,CUtlMemoryAligned<Frustum_t,16>>::InsertMultipleBefore(
    this: &g_AreaFrustum,
    elem: 0,
    num: m_nAreas);
  _V_memset(dest: g_AreaCounter, fill: 0, count: 1024);
  g_GlobalCounter = 1;
}

} // namespace engine_xlsp
