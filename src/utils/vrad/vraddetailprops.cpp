// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vrad/vraddetailprops.cpp
// Functions: 21
// ============================================================

#include "utils\vrad\vraddetailprops.h"

//------------------------------------------------------------------------------
// Address: 0x100246E0
// Name: public: void Ray_t::Init(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Ray_t::Init(
        Ray_t *this,
        const Vector *start,
        const Vector *end,
        const Vector *mins,
        const Vector *maxs)
{
  this->m_Delta.x = end->x - start->x;
  this->m_Delta.y = end->y - start->y;
  this->m_Delta.z = end->z - start->z;
  this->m_pWorldAxisTransform = nullptr;
  this->m_IsSwept = (float)((float)((float)(this->m_Delta.x * this->m_Delta.x)
                                  + (float)(this->m_Delta.y * this->m_Delta.y))
                          + (float)(this->m_Delta.z * this->m_Delta.z)) != 0.0;
  this->m_Extents.x = maxs->x - mins->x;
  this->m_Extents.y = maxs->y - mins->y;
  this->m_Extents.z = maxs->z - mins->z;
  this->m_Extents.x = this->m_Extents.x * 0.5;
  this->m_Extents.y = this->m_Extents.y * 0.5;
  this->m_Extents.z = this->m_Extents.z * 0.5;
  this->m_IsRay = (float)((float)((float)(this->m_Extents.x * this->m_Extents.x)
                                + (float)(this->m_Extents.y * this->m_Extents.y))
                        + (float)(this->m_Extents.z * this->m_Extents.z)) < 0.000001;
  this->m_StartOffset.x = mins->x + maxs->x;
  this->m_StartOffset.y = maxs->y + mins->y;
  this->m_StartOffset.z = mins->z + maxs->z;
  this->m_StartOffset.x = this->m_StartOffset.x * 0.5;
  this->m_StartOffset.y = this->m_StartOffset.y * 0.5;
  this->m_StartOffset.z = this->m_StartOffset.z * 0.5;
  this->m_Start.x = start->x + this->m_StartOffset.x;
  this->m_Start.y = this->m_StartOffset.y + start->y;
  this->m_Start.z = this->m_StartOffset.z + start->z;
  this->m_StartOffset.x = this->m_StartOffset.x * -1.0;
  this->m_StartOffset.y = this->m_StartOffset.y * -1.0;
  this->m_StartOffset.z = this->m_StartOffset.z * -1.0;
}

//------------------------------------------------------------------------------
// Address: 0x100248B0
// Name: void VRadDetailProps_SetHDRMode(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VRadDetailProps_SetHDRMode(bool bHDR)
{
  s_pDetailPropLightStyleLump = &s_DetailPropLightStyleLumpHDR;
  if ( !bHDR )
    s_pDetailPropLightStyleLump = &s_DetailPropLightStyleLumpLDR;
}

//------------------------------------------------------------------------------
// Address: 0x100248D0
// Name: private: bool CLightSurface::TestPointAgainstSurface(class Vector const __near &,struct dface_t __near *,struct texinfo_s __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CLightSurface::TestPointAgainstSurface(
        CLightSurface *this,
        const Vector *pt,
        dface_t *pFace,
        texinfo_s *pTex)
{
  float v4; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm3_4
  float v8; // xmm0_4
  float v9; // xmm1_4

  if ( (pTex->flags & 0x400) != 0 )
    return 0;
  v4 = (float)((float)((float)(pTex->lightmapVecsLuxelsPerWorldUnits[0][1] * pt->y)
                     + (float)(pt->x * pTex->lightmapVecsLuxelsPerWorldUnits[0][0]))
             + (float)(pTex->lightmapVecsLuxelsPerWorldUnits[0][2] * pt->z))
     + pTex->lightmapVecsLuxelsPerWorldUnits[0][3];
  v5 = (float)((float)((float)(pTex->lightmapVecsLuxelsPerWorldUnits[1][1] * pt->y)
                     + (float)(pTex->lightmapVecsLuxelsPerWorldUnits[1][0] * pt->x))
             + (float)(pTex->lightmapVecsLuxelsPerWorldUnits[1][2] * pt->z))
     + pTex->lightmapVecsLuxelsPerWorldUnits[1][3];
  v6 = (float)pFace->m_LightmapTextureMinsInLuxels[0];
  if ( v6 > v4 )
    return 0;
  v7 = (float)pFace->m_LightmapTextureMinsInLuxels[1];
  if ( v7 > v5 )
    return 0;
  v8 = v4 - v6;
  v9 = v5 - v7;
  if ( v8 > (float)pFace->m_LightmapTextureSizeInLuxels[0] || v9 > (float)pFace->m_LightmapTextureSizeInLuxels[1] )
    return 0;
  this->m_LuxelCoord.x = v8;
  this->m_LuxelCoord.y = v9;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10024990
// Name: bool CastRayInLeaf(int,class Vector const __near &,class Vector const __near &,int,float __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
bool __usercall CastRayInLeaf@<al>(
        float a1@<ebp>,
        int a2@<edi>,
        int a3@<esi>,
        int iThread,
        const Vector *start,
        const Vector *end,
        int leafIndex,
        float *pFraction,
        Vector *pNormal)
{
  IVRadDispMgr *v9; // eax
  IVRadDispMgr *v10; // eax
  void (__thiscall *ClipRayToDispInLeaf)(IVRadDispMgr *, DispTested_t *, const Ray_t *, int, float *, Vector *); // edx
  _BYTE v13[12]; // [esp-Ch] [ebp-ACh] BYREF
  Ray_t ray; // [esp+0h] [ebp-A0h] BYREF
  CBaseTrace trace; // [esp+58h] [ebp-48h] BYREF
  Vector normal; // [esp+90h] [ebp-10h] BYREF
  float retaddr; // [esp+A0h] [ebp+0h]

  normal.y = a1;
  normal.z = retaddr;
  *pFraction = 1.0;
  ray.m_Extents.y = 0.0;
  Ray_t::Init(this: (Ray_t *)v13, start, end, mins: &vec3_origin, maxs: &vec3_origin);
  if ( TraceLeafBrushes(leafIndex, start, end, traceOut: (CBaseTrace *)(&ray.m_IsSwept + 7)) != 1.0 )
  {
    *pFraction = trace.plane.normal.z;
    *pNormal = trace.endpos;
  }
  v9 = StaticDispMgr();
  ((void (__thiscall *)(IVRadDispMgr *, DispTested_t *, int, int))v9->StartRayTest)(
    a1: v9,
    a2: &s_DispTested[iThread],
    a3: a2,
    a4: a3);
  v10 = StaticDispMgr();
  ClipRayToDispInLeaf = v10->ClipRayToDispInLeaf;
  *(_DWORD *)&trace.dispFlags = &trace.fraction;
  ((void (__thiscall *)(IVRadDispMgr *, DispTested_t *, _BYTE *, int, Vector *))ClipRayToDispInLeaf)(
    a1: v10,
    a2: &s_DispTested[iThread],
    a3: v13,
    a4: leafIndex,
    a5: &normal);
  if ( *pFraction > normal.x )
  {
    *pFraction = normal.x;
    *pNormal = *(Vector *)&trace.fraction;
  }
  return *pFraction != 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10024B60
// Name: ComputeWorldCenter
// Source: json
//------------------------------------------------------------------------------
void __usercall ComputeWorldCenter(DetailObjectLump_t *prop@<edi>, Vector *center@<esi>, Vector *normal)
{
  float m_flScale; // xmm3_4
  float v4; // xmm0_4
  float v5; // xmm4_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm5_4
  float x; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm3_4
  float z; // xmm4_4
  float v15; // xmm4_4
  float v16; // xmm4_4
  float v17; // xmm0_4
  float v18; // xmm2_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  float v21; // xmm3_4
  float v22; // xmm4_4
  float v23; // xmm2_4
  float v24; // xmm1_4
  float v25; // xmm1_4
  float v26; // xmm0_4
  Vector right; // [esp+4h] [ebp-18h] BYREF
  Vector forward; // [esp+10h] [ebp-Ch] BYREF

  AngleVectors(angles: &prop->m_Angles, &forward, &right, up: normal);
  *center = prop->m_Origin;
  if ( prop->m_Type != 0 )
  {
    if ( prop->m_Type == 1 )
    {
      m_flScale = prop->m_flScale;
      v4 = g_SpriteCenterOffset.m_Memory.m_pMemory[prop->m_DetailModel].x * m_flScale;
      v5 = (float)(forward.y * v4) + center->y;
      v6 = g_SpriteCenterOffset.m_Memory.m_pMemory[prop->m_DetailModel].y * m_flScale;
      v7 = g_SpriteCenterOffset.m_Memory.m_pMemory[prop->m_DetailModel].z * m_flScale;
      v8 = (float)(forward.x * v4) + center->x;
      v9 = (float)(forward.z * v4) + center->z;
      x = right.x;
      center->x = v8;
      center->y = v5;
      center->z = v9;
      LODWORD(v11) = LODWORD(v6) ^ _mask__NegFloat_;
      v12 = (float)(x * v11) + v8;
      v13 = (float)(right.y * v11) + v5;
      z = right.z;
      center->x = v12;
      center->y = v13;
      v15 = (float)(z * v11) + v9;
      center->z = v15;
      center->x = (float)(normal->x * v7) + v12;
      center->y = (float)(normal->y * v7) + v13;
      center->z = (float)(normal->z * v7) + v15;
    }
  }
  else
  {
    v16 = right.x;
    v17 = g_ModelCenterOffset.m_Memory.m_pMemory[prop->m_DetailModel].x;
    v18 = (float)(forward.x * v17) + center->x;
    center->x = v18;
    v19 = (float)(v17 * forward.y) + center->y;
    v20 = (float)(v17 * forward.z) + center->z;
    center->y = v19;
    center->z = v20;
    LODWORD(v21) = LODWORD(g_ModelCenterOffset.m_Memory.m_pMemory[prop->m_DetailModel].y) ^ _mask__NegFloat_;
    v22 = (float)(v16 * v21) + v18;
    v23 = (float)(right.y * v21) + v19;
    v24 = right.z;
    center->y = v23;
    center->x = v22;
    v25 = (float)(v24 * v21) + v20;
    center->z = v25;
    v26 = g_ModelCenterOffset.m_Memory.m_pMemory[prop->m_DetailModel].z;
    center->x = (float)(normal->x * v26) + v22;
    center->y = (float)(normal->y * v26) + v23;
    center->z = (float)(normal->z * v26) + v25;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10024D60
// Name: ComputeLightmapColorFromAverage
// Source: json
//------------------------------------------------------------------------------
void __usercall ComputeLightmapColorFromAverage(
        dface_t *pFace@<esi>,
        directlight_t *pSkylight,
        float scale,
        Vector *pColor)
{
  float v4; // xmm2_4
  float v5; // xmm3_4
  float v6; // xmm0_4
  int v7; // edx
  unsigned __int8 *styles; // ecx
  unsigned __int8 *v9; // eax
  float v10; // xmm3_4
  float v11; // xmm0_4
  float v12; // xmm2_4
  float v13; // xmm1_4
  texinfo_s *v14; // eax
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  dtexdata_t *v18; // eax
  Vector *v19; // eax
  float v20; // xmm1_4
  float v21; // xmm2_4

  if ( (texinfo.m_Memory.m_pMemory[pFace->texinfo].flags & 4) != 0 )
  {
    if ( pSkylight != nullptr )
    {
      v4 = (float)(pSkylight->light.intensity.z * 0.0039215689) * scale;
      v5 = pColor->x + (float)((float)(pSkylight->light.intensity.x * 0.0039215689) * scale);
      pColor->y = pColor->y + (float)((float)(pSkylight->light.intensity.y * 0.0039215689) * scale);
      v6 = pColor->z + v4;
      pColor->x = v5;
      pColor->z = v6;
    }
  }
  else
  {
    v7 = 0;
    styles = pFace->styles;
    do
    {
      if ( *styles == 0xFF )
        break;
      v9 = &pdlightdata->m_Memory.m_pMemory[pFace->lightofs - v7 - 4];
      v10 = dword_10135B00[(char)v9[3]];
      v11 = (float)*v9;
      v12 = (float)v9[2];
      v13 = (float)v9[1];
      v14 = &texinfo.m_Memory.m_pMemory[pFace->texinfo];
      v15 = v11 * v10;
      v16 = v13 * v10;
      v17 = v12 * v10;
      if ( v14 != nullptr )
      {
        if ( (v14->flags & 4) != 0 )
        {
          if ( pSkylight != nullptr )
          {
            v15 = pSkylight->light.intensity.x * 0.0039215689;
            v16 = pSkylight->light.intensity.y * 0.0039215689;
            v17 = pSkylight->light.intensity.z * 0.0039215689;
          }
        }
        else
        {
          v18 = &dtexdata[v14->texdata];
          v15 = v15 * v18->reflectivity.x;
          v16 = v16 * v18->reflectivity.y;
          v17 = v17 * v18->reflectivity.z;
        }
      }
      v19 = &pColor[*styles];
      v20 = (float)(v16 * scale) + v19->y;
      v21 = (float)(v17 * scale) + v19->z;
      v19->x = v19->x + (float)(v15 * scale);
      v19->y = v20;
      v19->z = v21;
      ++styles;
      v7 += 4;
    }
    while ( (int)&styles[-16 - (_DWORD)pFace] < 4 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10024F10
// Name: ComputeLightmapColorPointSample
// Source: json
//------------------------------------------------------------------------------
void __usercall ComputeLightmapColorPointSample(
        int a1@<edi>,
        float a2@<xmm4>,
        directlight_t *pSkylight,
        const Vector2D *luv,
        Vector *pColor)
{
  int x; // edx
  int v6; // ecx
  int y; // edx
  int flags; // esi
  unsigned __int8 *v9; // ecx
  _BYTE *v10; // esi
  float v11; // xmm3_4
  texinfo_s *v12; // eax
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  dtexdata_t *v16; // eax
  Vector *v17; // eax
  float v18; // xmm3_4
  float z; // xmm0_4
  int offset; // [esp+8h] [ebp-8h]
  int v21; // [esp+Ch] [ebp-4h]

  if ( *(_DWORD *)(a1 + 20) != -1 )
  {
    x = (int)luv->x;
    v6 = *(_DWORD *)(a1 + 36) + 1;
    if ( x >= 0 )
    {
      v21 = *(_DWORD *)(a1 + 36);
      if ( x <= v21 )
        v21 = (int)luv->x;
    }
    else
    {
      v21 = 0;
    }
    y = (int)luv->y;
    if ( y >= 0 )
    {
      if ( y > *(_DWORD *)(a1 + 40) )
        y = *(_DWORD *)(a1 + 40);
    }
    else
    {
      y = 0;
    }
    flags = texinfo.m_Memory.m_pMemory[*(__int16 *)(a1 + 10)].flags;
    offset = v6 * (*(_DWORD *)(a1 + 40) + 1);
    if ( (flags & 0x800) != 0 && (flags & 0x400) == 0 )
      offset = 4 * v6 * (*(_DWORD *)(a1 + 40) + 1);
    v9 = &pdlightdata->m_Memory.m_pMemory[4 * v21 + 4 * v6 * y + *(_DWORD *)(a1 + 20)];
    v10 = (_BYTE *)(a1 + 16);
    do
    {
      if ( *v10 == 0xFF )
        break;
      v11 = dword_10135B00[(char)v9[3]];
      v12 = &texinfo.m_Memory.m_pMemory[*(__int16 *)(a1 + 10)];
      v13 = (float)*v9 * v11;
      v14 = (float)v9[1] * v11;
      v15 = (float)v9[2] * v11;
      if ( v12 != nullptr )
      {
        if ( (v12->flags & 4) != 0 )
        {
          if ( pSkylight != nullptr )
          {
            v13 = pSkylight->light.intensity.x * 0.0039215689;
            v14 = pSkylight->light.intensity.y * 0.0039215689;
            v15 = pSkylight->light.intensity.z * 0.0039215689;
          }
        }
        else
        {
          v16 = &dtexdata[v12->texdata];
          v13 = v13 * v16->reflectivity.x;
          v14 = v14 * v16->reflectivity.y;
          v15 = v15 * v16->reflectivity.z;
        }
      }
      v17 = &pColor[(unsigned __int8)*v10];
      v18 = v17->x + (float)(v13 * a2);
      v17->y = v17->y + (float)(v14 * a2);
      z = v17->z;
      v17->x = v18;
      v17->z = z + (float)(v15 * a2);
      ++v10;
      v9 += 4 * offset;
    }
    while ( (int)&v10[-16 - a1] < 4 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100250C0
// Name: public: virtual bool CLightSurface::EnumerateNode(int,struct Ray_t const __near &,float,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CLightSurface::EnumerateNode(CLightSurface *this, int node, const Ray_t *ray, float f, int context)
{
  CLightSurface *v5; // edx
  dnode_t *v6; // edi
  float x; // xmm5_4
  float y; // xmm4_4
  float z; // xmm3_4
  dface_t *v10; // ecx
  dface_t *v11; // esi
  texinfo_s *v12; // eax
  int flags; // ecx
  winding_t *v14; // ebx
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm6_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  Vector origin; // [esp+Ch] [ebp-20h] BYREF
  Vector pt; // [esp+18h] [ebp-14h] BYREF
  dface_t *pSkySurface; // [esp+24h] [ebp-8h]
  CLightSurface *v25; // [esp+28h] [ebp-4h]
  int i; // [esp+34h] [ebp+8h]
  bool ray_3; // [esp+3Bh] [ebp+Fh]

  v5 = this;
  v25 = this;
  v6 = &dnodes[node];
  x = (float)(ray->m_Delta.x * f) + ray->m_Start.x;
  y = (float)(ray->m_Delta.y * f) + ray->m_Start.y;
  z = (float)(ray->m_Delta.z * f) + ray->m_Start.z;
  v10 = nullptr;
  v11 = &g_pFaces[v6->firstface];
  pSkySurface = nullptr;
  pt.x = x;
  pt.y = y;
  pt.z = z;
  i = 0;
  if ( v6->numfaces == 0 )
  {
LABEL_14:
    v5->m_pSurface = v10;
    return v10 == nullptr;
  }
  while ( 1 )
  {
    if ( v11->onNode != 0 && v11->dispinfo == -1 )
    {
      v12 = &texinfo.m_Memory.m_pMemory[v11->texinfo];
      flags = v12->flags;
      if ( (flags & 4) == 0 )
        break;
      memset(&origin, 0, sizeof(origin));
      v14 = WindingFromFace(f: (winding_t *)v11, &origin);
      ray_3 = PointInWinding(&pt, pWinding: v14);
      FreeWinding(w: v14);
      z = pt.z;
      y = pt.y;
      x = pt.x;
      v5 = v25;
      if ( ray_3 )
        pSkySurface = v11;
    }
LABEL_12:
    ++v11;
    if ( ++i >= v6->numfaces )
    {
      v10 = pSkySurface;
      goto LABEL_14;
    }
  }
  if ( (flags & 0x400) != 0 )
    goto LABEL_12;
  v15 = (float)((float)((float)(v12->lightmapVecsLuxelsPerWorldUnits[0][1] * y)
                      + (float)(v12->lightmapVecsLuxelsPerWorldUnits[0][0] * x))
              + (float)(v12->lightmapVecsLuxelsPerWorldUnits[0][2] * z))
      + v12->lightmapVecsLuxelsPerWorldUnits[0][3];
  v16 = (float)((float)((float)(v12->lightmapVecsLuxelsPerWorldUnits[1][1] * y)
                      + (float)(v12->lightmapVecsLuxelsPerWorldUnits[1][0] * x))
              + (float)(v12->lightmapVecsLuxelsPerWorldUnits[1][2] * z))
      + v12->lightmapVecsLuxelsPerWorldUnits[1][3];
  v17 = (float)v11->m_LightmapTextureMinsInLuxels[0];
  if ( v17 > v15 )
    goto LABEL_12;
  v18 = (float)v11->m_LightmapTextureMinsInLuxels[1];
  if ( v18 > v16 )
    goto LABEL_12;
  v19 = v15 - v17;
  v20 = v16 - v18;
  if ( v19 > (float)v11->m_LightmapTextureSizeInLuxels[0] || v20 > (float)v11->m_LightmapTextureSizeInLuxels[1] )
    goto LABEL_12;
  v5->m_pSurface = v11;
  v5->m_LuxelCoord.x = v19;
  v5->m_LuxelCoord.y = v20;
  v5->m_HitFrac = f;
  v5->m_bHasLuxel = true;
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x100252C0
// Name: public: virtual bool CLightSurface::EnumerateLeaf(int,struct Ray_t const __near &,float,float,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CLightSurface::EnumerateLeaf(
        CLightSurface *this,
        int leaf,
        const Ray_t *ray,
        float start,
        float end,
        int context)
{
  dleaf_t *v7; // ebx
  int v8; // eax
  dface_t *v9; // esi
  texinfo_s *v10; // edx
  float y; // xmm1_4
  float z; // xmm4_4
  float v13; // xmm0_4
  float v14; // xmm3_4
  float v15; // xmm7_4
  float *v16; // eax
  float v17; // xmm2_4
  float v18; // xmm5_4
  float v19; // xmm4_4
  float v20; // xmm6_4
  float v21; // xmm1_4
  float v22; // xmm3_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  float v25; // xmm2_4
  float v26; // xmm1_4
  bool v27; // cf
  int numleaffaces; // ecx
  IVRadDispMgr *v29; // eax
  dface_t *v30; // eax
  float v31; // xmm0_4
  Vector pt; // [esp+8h] [ebp-34h] BYREF
  Vector2D luxelCoord; // [esp+14h] [ebp-28h] BYREF
  dface_t *pDispFace; // [esp+1Ch] [ebp-20h] BYREF
  float dist; // [esp+20h] [ebp-1Ch] BYREF
  float mid; // [esp+24h] [ebp-18h]
  float v38; // [esp+28h] [ebp-14h]
  float v39; // [esp+2Ch] [ebp-10h]
  float x; // [esp+30h] [ebp-Ch]
  int i; // [esp+34h] [ebp-8h]
  bool hit; // [esp+3Bh] [ebp-1h]

  v7 = &dleafs[leaf];
  v8 = 0;
  hit = false;
  i = 0;
  if ( v7->numleaffaces != 0 )
  {
    do
    {
      v9 = &g_pFaces[dleaffaces[v8 + v7->firstleafface]];
      if ( v9->dispinfo == -1 && v9->onNode == 0 )
      {
        v10 = &texinfo.m_Memory.m_pMemory[v9->texinfo];
        y = ray->m_Delta.y;
        z = ray->m_Delta.z;
        v13 = *(&dplanes.y + 5 * v9->planenum);
        v14 = *(&dplanes.x + 5 * v9->planenum);
        v15 = *(&dplanes.z + 5 * v9->planenum);
        v16 = &dplanes.x + 5 * v9->planenum;
        x = ray->m_Delta.x;
        v39 = y;
        v38 = z;
        v17 = (float)((float)(x * v14) + (float)(y * v13)) + (float)(z * v15);
        if ( v17 <= 0.0 )
        {
          v18 = ray->m_Start.x;
          v19 = ray->m_Start.y;
          v20 = ray->m_Start.z;
          v21 = (float)(ray->m_Start.x * v14) + (float)(v19 * v13);
          v22 = v16[3];
          v23 = v21 + (float)(v20 * v15);
          v24 = (float)((float)(v17 * start) + v23) - v22;
          v25 = (float)((float)(v17 * end) + v23) - v22;
          if ( v25 < 0.0 != v24 < 0.0 )
          {
            v26 = (float)((float)(1.0 - (float)(v24 / (float)(v24 - v25))) * start)
                + (float)((float)(v24 / (float)(v24 - v25)) * end);
            v27 = v26 < this->m_HitFrac;
            mid = v26;
            if ( v27 )
            {
              pt.x = (float)(x * v26) + v18;
              pt.y = (float)(v39 * v26) + v19;
              pt.z = (float)(v38 * v26) + v20;
              if ( CLightSurface::TestPointAgainstSurface(this, &pt, pFace: v9, pTex: v10) != 0 )
              {
                this->m_HitFrac = mid;
                this->m_pSurface = v9;
                hit = true;
                this->m_bHasLuxel = true;
              }
            }
          }
        }
      }
      numleaffaces = v7->numleaffaces;
      v8 = i + 1;
      i = v8;
    }
    while ( v8 < numleaffaces );
  }
  v29 = StaticDispMgr();
  v29->ClipRayToDispInLeaf_2(
    this: v29,
    a2: &s_DispTested[this->m_iThread],
    a3: ray,
    a4: leaf,
    a5: &dist,
    a6: &pDispFace,
    a7: &luxelCoord);
  if ( this->m_HitFrac <= dist )
    return !hit;
  v30 = pDispFace;
  this->m_HitFrac = dist;
  v31 = luxelCoord.x;
  this->m_pSurface = v30;
  this->m_LuxelCoord.x = v31;
  this->m_LuxelCoord.y = luxelCoord.y;
  this->m_bHasLuxel = true;
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10025540
// Name: void CalcRayAmbientLighting(int,class Vector const __near &,class Vector const __near &,float,class Vector __near * const)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __usercall CalcRayAmbientLighting(
        int a1@<ebp>,
        int a2@<edi>,
        int a3@<esi>,
        int iThread,
        const Vector *vStart,
        const Vector *vEnd,
        float tanTheta,
        Vector *color)
{
  directlight_t *v8; // edi
  directlight_t *v9; // eax
  IVRadDispMgr *v10; // eax
  __int128 v11; // xmm0
  float scale; // xmm0_4
  float v13; // xmm7_4
  _BYTE v15[12]; // [esp+1Ch] [ebp-9Ch] BYREF
  Ray_t ray; // [esp+28h] [ebp-90h] BYREF
  dface_t *v17; // [esp+78h] [ebp-40h]
  _BYTE surfEnum[32]; // [esp+7Ch] [ebp-3Ch] OVERLAPPED BYREF
  float v19; // [esp+A8h] [ebp-10h]
  int v20; // [esp+ACh] [ebp-Ch]
  void *v21; // [esp+B0h] [ebp-8h]
  void *retaddr; // [esp+B8h] [ebp+0h]

  v20 = a1;
  v21 = retaddr;
  ray.m_Extents.y = 0.0;
  Ray_t::Init(this: (Ray_t *)v15, start: vStart, end: vEnd, mins: &vec3_origin, maxs: &vec3_origin);
  v8 = pSkylight;
  if ( pSkylight == nullptr )
  {
    v9 = activelights;
    if ( activelights != nullptr )
    {
      while ( v9->light.type != emit_skyambient )
      {
        v9 = v9->next;
        if ( v9 == nullptr )
          goto LABEL_7;
      }
      v8 = v9;
      pSkylight = v9;
    }
  }
LABEL_7:
  *(_DWORD *)(&ray.m_IsSwept + 3) = &CLightSurface::`vftable';
  *(_DWORD *)(&ray.m_IsSwept + 7) = iThread;
  v17 = nullptr;
  *(_DWORD *)surfEnum = 1065353216;
  surfEnum[12] = 0;
  v10 = StaticDispMgr();
  ((void (__thiscall *)(IVRadDispMgr *, DispTested_t *, int, int))v10->StartRayTest)(
    a1: v10,
    a2: &s_DispTested[*(_DWORD *)(&ray.m_IsSwept + 7)],
    a3: a2,
    a4: a3);
  if ( !EnumerateNodesAlongRay(ray: (const Ray_t *)v15, pEnum: (IBSPNodeEnumerator *)(&ray.m_IsSwept + 3), context: 0) )
  {
    v19 = ray.m_Start.w * ray.m_Start.w;
    v11 = 0;
    *(float *)&v11 = fsqrt(
                       (float)((float)(ray.m_Start.w * ray.m_Start.w) + (float)(ray.m_Start.y * ray.m_Start.y))
                     + (float)(ray.m_Start.z * ray.m_Start.z));
    *(_OWORD *)&surfEnum[16] = v11;
    scale = (float)((float)((float)(*(float *)&v11 * tanTheta) * *(float *)surfEnum) - 20.0) * 0.050000001;
    if ( scale >= 0.0 )
    {
      if ( scale > 1.0 )
        scale = 1.0;
    }
    else
    {
      scale = 0.0;
    }
    if ( surfEnum[12] == 0 )
      scale = 1.0;
    v13 = 1.0 - scale;
    if ( scale != 0.0 )
      ComputeLightmapColorFromAverage(pFace: v17, pSkylight: v8, scale, pColor: color);
    if ( v13 != 0.0 )
      ComputeLightmapColorPointSample(
        a1: (int)v17,
        a2: v13,
        pSkylight: v8,
        luv: (const Vector2D *)&surfEnum[4],
        pColor: color);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100256E0
// Name: ComputeAmbientLightingAtPoint
// Source: json
//------------------------------------------------------------------------------
void __usercall ComputeAmbientLightingAtPoint(
        const Vector *origin@<edi>,
        unsigned int a2@<ebx>,
        unsigned int a3@<esi>,
        int iThread,
        Vector *radcolor)
{
  float *p_z; // eax
  int i; // ecx
  float *v7; // esi
  float *v8; // eax
  int j; // ecx
  Vector upend; // [esp+10h] [ebp-10h] BYREF
  float tanTheta; // [esp+1Ch] [ebp-4h]
  int savedregs; // [esp+20h] [ebp+0h] BYREF

  p_z = &radcolor->z;
  for ( i = 64; i != 0; --i )
  {
    *(p_z - 2) = 0.0;
    *(p_z - 1) = 0.0;
    *p_z = 0.0;
    p_z += 3;
  }
  __libm_sse2_tan(x: COERCE_LONG_DOUBLE(__PAIR64__(a2, a3)));
  tanTheta = 0.1269727051258087;
  v7 = &g_anorms[0].z;
  do
  {
    upend.x = (float)(*(v7 - 2) * 57016.32) + origin->x;
    upend.y = (float)(*(v7 - 1) * 57016.32) + origin->y;
    upend.z = (float)(*v7 * 57016.32) + origin->z;
    CalcRayAmbientLighting(
      a1: (int)&savedregs,
      a2: (int)origin,
      a3: (int)v7,
      iThread,
      vStart: origin,
      vEnd: &upend,
      tanTheta,
      color: radcolor);
    v7 += 3;
  }
  while ( (int)v7 < (int)&vec2_invalid_51 );
  v8 = &radcolor[1].z;
  for ( j = 8; j != 0; --j )
  {
    *(v8 - 5) = *(v8 - 5) * 1.574074;
    *(v8 - 4) = *(v8 - 4) * 1.574074;
    *(v8 - 3) = *(v8 - 3) * 1.574074;
    *(v8 - 2) = *(v8 - 2) * 1.574074;
    *(v8 - 1) = *(v8 - 1) * 1.574074;
    *v8 = *v8 * 1.574074;
    v8[1] = v8[1] * 1.574074;
    v8[2] = v8[2] * 1.574074;
    v8[3] = v8[3] * 1.574074;
    v8[4] = v8[4] * 1.574074;
    v8[5] = v8[5] * 1.574074;
    v8[6] = v8[6] * 1.574074;
    v8[7] = v8[7] * 1.574074;
    v8[8] = v8[8] * 1.574074;
    v8[9] = v8[9] * 1.574074;
    v8[10] = v8[10] * 1.574074;
    v8[11] = v8[11] * 1.574074;
    v8[12] = v8[12] * 1.574074;
    v8[13] = v8[13] * 1.574074;
    v8[14] = v8[14] * 1.574074;
    v8[15] = v8[15] * 1.574074;
    v8[16] = v8[16] * 1.574074;
    v8[17] = v8[17] * 1.574074;
    v8[18] = v8[18] * 1.574074;
    v8 += 24;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025910
// Name: void ComputeIndirectLightingAtPoint(class Vector __near &,class Vector __near *,class Vector __near *,int,int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall ComputeIndirectLightingAtPoint(
        int a1@<ebp>,
        double a2@<esi:edi>,
        Vector *position,
        Vector *normals,
        Vector *outColors,
        int numNormals,
        int iThread,
        bool force_fast,
        bool bIgnoreNormals)
{
  float *p_z; // edi
  int v10; // esi
  double Element; // st7
  double v12; // st7
  double v13; // xmm0_8
  double v14; // xmm0_8
  double v15; // xmm0_8
  float v16; // xmm1_4
  float v17; // xmm1_4
  float v18; // xmm0_4
  float v19; // xmm2_4
  float z; // xmm5_4
  float x; // xmm3_4
  float v22; // xmm0_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  IVRadDispMgr *v26; // eax
  float v27; // esi
  float v28; // ecx
  int v29; // edx
  int v30; // eax
  dtexdata_t *v31; // eax
  float v32; // xmm1_4
  float v33; // xmm2_4
  float v34; // xmm3_4
  float v35; // xmm0_4
  float v36; // xmm2_4
  int v37; // [esp-D4h] [ebp-E0h]
  int v38; // [esp-D4h] [ebp-E0h]
  long double v39; // [esp-D0h] [ebp-DCh]
  long double v40; // [esp-D0h] [ebp-DCh]
  long double v41; // [esp-D0h] [ebp-DCh]
  long double v42; // [esp-D0h] [ebp-DCh]
  Ray_t v43; // [esp-C0h] [ebp-CCh] BYREF
  float v44; // [esp-68h] [ebp-74h]
  HaltonSequenceGenerator_t v45; // [esp-5Ch] [ebp-68h] BYREF
  HaltonSequenceGenerator_t v46; // [esp-50h] [ebp-5Ch] BYREF
  IBSPNodeEnumerator v47; // [esp-44h] [ebp-50h] BYREF
  int v48; // [esp-40h] [ebp-4Ch]
  int v49; // [esp-3Ch] [ebp-48h]
  int v50; // [esp-38h] [ebp-44h]
  float v51; // [esp-34h] [ebp-40h]
  float v52; // [esp-30h] [ebp-3Ch]
  char v53; // [esp-2Ch] [ebp-38h]
  Vector v54; // [esp-28h] [ebp-34h] BYREF
  int i; // [esp-1Ch] [ebp-28h]
  float v56; // [esp-18h] [ebp-24h]
  int j; // [esp-14h] [ebp-20h]
  Vector *v58; // [esp-10h] [ebp-1Ch]
  float v59; // [esp-Ch] [ebp-18h]
  float v60; // [esp-8h] [ebp-14h]
  float v61; // [esp-4h] [ebp-10h]
  int v62; // [esp+0h] [ebp-Ch]
  void *v63; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v62 = a1;
  v63 = retaddr;
  v39 = a2;
  if ( numNormals > 0 )
  {
    v58 = normals;
    p_z = &outColors->z;
    for ( i = numNormals; i != 0; --i )
    {
      *(p_z - 2) = 0.0;
      *(p_z - 1) = 0.0;
      *p_z = 0.0;
      v43.m_pWorldAxisTransform = nullptr;
      v47.__vftable = (IBSPNodeEnumerator_vtbl *)&CLightSurface::`vftable';
      v48 = iThread;
      v49 = 0;
      v50 = 1065353216;
      v53 = 0;
      if ( do_fast != 0 || force_fast )
        v10 = 40;
      else
        v10 = (int)(float)(g_flSkySampleScale * 162.0);
      v59 = 0.0;
      HaltonSequenceGenerator_t::HaltonSequenceGenerator_t(this: &v45, b: 2);
      HaltonSequenceGenerator_t::HaltonSequenceGenerator_t(this: &v46, b: 3);
      if ( v10 > 0 )
      {
        for ( j = v10; j != 0; --j )
        {
          v37 = v45.seed++;
          Element = HaltonSequenceGenerator_t::GetElement(this: &v45, elem: v37);
          v38 = v46.seed++;
          v61 = Element + Element - 1.0;
          v12 = HaltonSequenceGenerator_t::GetElement(this: &v46, elem: v38);
          v13 = v61;
          v60 = v12 * 6.283185307179586;
          __libm_sse2_acos(x: v39);
          *(float *)&v13 = v13;
          __libm_sse2_sin(x: v40);
          v56 = *(float *)&v13;
          v14 = v60;
          __libm_sse2_cos(x: v41);
          *(float *)&v14 = v14;
          v44 = *(float *)&v14 * v56;
          v15 = v60;
          __libm_sse2_sin(x: v42);
          v16 = v15;
          v17 = v16 * v56;
          if ( bIgnoreNormals )
          {
            v18 = 0.35354999;
            v19 = v61;
          }
          else
          {
            v19 = v61;
            v18 = (float)((float)(v58->y * v17) + (float)(v58->x * v44)) + (float)(v58->z * v61);
          }
          if ( v18 > 0.001 )
          {
            v59 = v18 + v59;
            z = position->z;
            x = position->x;
            v22 = (float)(position->x + (float)(v44 * 56755.84)) - position->x;
            v43.m_Delta.y = (float)(position->y + (float)(v17 * 56755.84)) - position->y;
            v43.m_Delta.x = v22;
            v43.m_Delta.z = (float)(z + (float)(v19 * 56755.84)) - z;
            v43.m_pWorldAxisTransform = nullptr;
            v43.m_IsSwept = (float)((float)((float)(v43.m_Delta.y * v43.m_Delta.y) + (float)(v22 * v22))
                                  + (float)(v43.m_Delta.z * v43.m_Delta.z)) != 0.0;
            memset(&v43.m_Extents, 0, 12);
            v23 = (float)(vec3_origin.x * 2.0) * 0.5;
            v43.m_Start.x = x + v23;
            v24 = (float)(vec3_origin.y * 2.0) * 0.5;
            v43.m_Start.y = v24 + position->y;
            v25 = (float)(vec3_origin.z * 2.0) * 0.5;
            v43.m_Start.z = v25 + z;
            v43.m_IsRay = true;
            v43.m_StartOffset.x = v23 * -1.0;
            v43.m_StartOffset.y = v24 * -1.0;
            v43.m_StartOffset.z = v25 * -1.0;
            v26 = StaticDispMgr();
            v26->StartRayTest(this: v26, a2: &s_DispTested[v48]);
            if ( !EnumerateNodesAlongRay(ray: &v43, pEnum: &v47, context: 0) )
            {
              LODWORD(v27) = &texinfo.m_Memory.m_pMemory[*(__int16 *)(v49 + 10)];
              v61 = v27;
              if ( v27 != 0.0 && (*(_BYTE *)(LODWORD(v27) + 64) & 4) == 0 && *(_BYTE *)(v49 + 16) != 0xFF )
              {
                v28 = *(float *)(v49 + 20);
                v60 = v28;
                if ( v28 >= 0.0 )
                {
                  if ( v53 != 0 )
                  {
                    v29 = (int)v51;
                    v30 = *(_DWORD *)(v49 + 40);
                    if ( (int)v51 >= 0 )
                    {
                      if ( v29 > *(_DWORD *)(v49 + 36) )
                        v29 = *(_DWORD *)(v49 + 36);
                    }
                    else
                    {
                      v29 = 0;
                    }
                    if ( (int)v52 >= 0 )
                    {
                      if ( (int)v52 <= v30 )
                        v30 = (int)v52;
                    }
                    else
                    {
                      v30 = 0;
                    }
                    ColorRGBExp32ToVector(
                      in: (const ColorRGBExp32 *)&pdlightdata->m_Memory.m_pMemory[4 * v29
                                                                            + 4 * (*(_DWORD *)(v49 + 36) + 1) * v30
                                                                            + LODWORD(v60)],
                      out: &v54);
                    v27 = v61;
                  }
                  else
                  {
                    ColorRGBExp32ToVector(
                      in: (const ColorRGBExp32 *)&pdlightdata->m_Memory.m_pMemory[LODWORD(v28) - 4],
                      out: &v54);
                  }
                  v31 = &dtexdata[*(_DWORD *)(LODWORD(v27) + 68)];
                  v32 = v31->reflectivity.y * v54.y;
                  v33 = v31->reflectivity.z * v54.z;
                  v34 = *(p_z - 2) + (float)(v31->reflectivity.x * v54.x);
                  v54.x = v31->reflectivity.x * v54.x;
                  *(p_z - 1) = *(p_z - 1) + v32;
                  v35 = *p_z + v33;
                  v54.y = v32;
                  v54.z = v33;
                  *(p_z - 2) = v34;
                  *p_z = v35;
                }
              }
            }
          }
        }
        v36 = v59;
        if ( v59 != 0.0 )
        {
          *(p_z - 2) = *(p_z - 2) * (float)(1.0 / v59);
          *(p_z - 1) = *(p_z - 1) * (float)(1.0 / v36);
          *p_z = *p_z * (float)(1.0 / v36);
        }
      }
      ++v58;
      p_z += 3;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025DC0
// Name: ComputeAmbientLighting
// Source: json
//------------------------------------------------------------------------------
void __usercall ComputeAmbientLighting(
        DetailObjectLump_t *prop@<ecx>,
        unsigned int a2@<ebx>,
        int iThread,
        Vector *color)
{
  float *p_z; // eax
  int i; // ecx
  Vector normal; // [esp+8h] [ebp-1Ch] BYREF
  Vector origin; // [esp+14h] [ebp-10h] BYREF
  float x; // [esp+20h] [ebp-4h]

  ComputeWorldCenter(prop, center: &origin, &normal);
  x = origin.x;
  if ( (LODWORD(origin.x) & 0x7F800000) == 0x7F800000
    || (x = origin.y, (LODWORD(origin.y) & 0x7F800000) == 0x7F800000)
    || (x = origin.z, (LODWORD(origin.z) & 0x7F800000) == 0x7F800000)
    || (x = normal.x, (LODWORD(normal.x) & 0x7F800000) == 0x7F800000)
    || (x = normal.y, (LODWORD(normal.y) & 0x7F800000) == 0x7F800000)
    || (x = normal.z, (LODWORD(normal.z) & 0x7F800000) == 0x7F800000) )
  {
    if ( !s_Warned )
    {
      _Warning(a1: "WARNING: Bogus detail props encountered!\n");
      s_Warned = true;
    }
    p_z = &color->z;
    for ( i = 64; i != 0; --i )
    {
      *(p_z - 2) = 1.0;
      *(p_z - 1) = 0.0;
      *p_z = 0.0;
      p_z += 3;
    }
  }
  else
  {
    ComputeAmbientLightingAtPoint(&origin, a2, a3: (unsigned int)&origin, iThread, radcolor: color);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025F60
// Name: WriteDetailLightingLump
// Source: json
//------------------------------------------------------------------------------
void __cdecl WriteDetailLightingLump(
        int lumpID,
        int lumpVersion,
        CUtlVector<DetailPropLightstylesLump_t,CUtlMemory<DetailPropLightstylesLump_t,int> > *lumpData)
{
  unsigned __int16 GameLumpHandle; // si
  int v4; // edi
  unsigned __int16 GameLump; // ax
  const void *v6; // eax
  int m_Size; // [esp-4h] [ebp-40h]
  CUtlBuffer buf; // [esp+Ch] [ebp-30h] BYREF

  GameLumpHandle = CGameLump::GetGameLumpHandle(this: &g_GameLumps, id: lumpID);
  if ( GameLumpHandle != CGameLump::InvalidGameLump(this: &g_GameLumps) )
    CGameLump::DestroyGameLump(this: &g_GameLumps, handle: GameLumpHandle);
  v4 = 5 * lumpData->m_Size;
  GameLump = CGameLump::CreateGameLump(this: &g_GameLumps, id: lumpID, size: v4 + 4, flags: 0, version: lumpVersion);
  v6 = CGameLump::GetGameLump(this: &g_GameLumps, id: GameLump);
  CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: v6, nSize: v4 + 4, nFlags: 0);
  m_Size = lumpData->m_Size;
  if ( (buf.m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: &buf, pFmt: "%d", m_Size);
  else
    CUtlBuffer::PutTypeBin<int>(this: &buf, src: m_Size);
  if ( v4 != 0 )
    CUtlBuffer::Put(this: &buf, pMem: lumpData->m_Memory.m_pMemory, size: v4);
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10026030
// Name: ComputeMaxDirectLighting
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __usercall ComputeMaxDirectLighting(DetailObjectLump_t *prop@<ecx>, float a2@<ebp>, int a3, int a4)
{
  int y_low; // eax
  directlight_t *v5; // edi
  directlight_t **m_pMemory; // esi
  unsigned __int8 *pvs; // esi
  char v8; // al
  float x; // ecx
  directlight_t **v10; // ecx
  _DWORD *v11; // eax
  int j; // ecx
  int v13; // edi
  directlight_t *v14; // esi
  float v15; // xmm0_4
  float *v16; // eax
  _DWORD *v17; // eax
  int i; // ecx
  float v19; // [esp+14h] [ebp-12Ch] BYREF
  _BYTE out_52[140]; // [esp+54h] [ebp-ECh] OVERLAPPED BYREF
  float v21; // [esp+E0h] [ebp-60h]
  float v22; // [esp+E4h] [ebp-5Ch]
  Vector delta; // [esp+E8h] [ebp-58h] BYREF
  CUtlVector<Vector,CUtlMemory<Vector,int> > directions; // [esp+F4h] [ebp-4Ch] BYREF
  Vector normal; // [esp+108h] [ebp-38h] BYREF
  int v26; // [esp+114h] [ebp-2Ch]
  CUtlVector<directlight_t *,CUtlMemory<directlight_t *,int> > lights; // [esp+118h] [ebp-28h] BYREF
  Vector origin; // [esp+12Ch] [ebp-14h]
  void *v29; // [esp+138h] [ebp-8h]
  void *retaddr; // [esp+140h] [ebp+0h]

  origin.z = a2;
  v29 = retaddr;
  ComputeWorldCenter(
    prop,
    center: (Vector *)&lights.m_Memory.m_nGrowSize,
    normal: (Vector *)&directions.m_Memory.m_nGrowSize);
  LODWORD(origin.y) = lights.m_Memory.m_nGrowSize;
  if ( (lights.m_Memory.m_nGrowSize & 0x7F800000) == 0x7F800000
    || (LODWORD(origin.y) = lights.m_Size, (lights.m_Size & 0x7F800000) == 0x7F800000)
    || (LODWORD(origin.y) = lights.m_pElements, ((int)lights.m_pElements & 0x7F800000) == 0x7F800000)
    || (LODWORD(origin.y) = directions.m_Memory.m_nGrowSize, (directions.m_Memory.m_nGrowSize & 0x7F800000) == 0x7F800000)
    || (LODWORD(origin.y) = directions.m_Size, (directions.m_Size & 0x7F800000) == 0x7F800000)
    || (LODWORD(origin.y) = directions.m_pElements, ((int)directions.m_pElements & 0x7F800000) == 0x7F800000) )
  {
    if ( !s_Warned_0 )
    {
      _Warning(a1: "WARNING: Bogus detail props encountered!\n");
      s_Warned_0 = true;
    }
    v17 = (_DWORD *)(a3 + 8);
    for ( i = 64; i != 0; --i )
    {
      *(v17 - 2) = 1065353216;
      *(v17 - 1) = 0;
      *v17 = 0;
      v17 += 3;
    }
  }
  else
  {
    y_low = ClusterFromPoint(point: (const Vector *)&lights.m_Memory.m_nGrowSize);
    v5 = activelights;
    m_pMemory = nullptr;
    LODWORD(origin.y) = y_low;
    normal.y = 0.0;
    normal.z = 0.0;
    v26 = 0;
    lights.m_Memory.m_pMemory = nullptr;
    lights.m_Memory.m_nAllocationCount = 0;
    memset(&delta, 0, sizeof(delta));
    directions.m_Memory.m_pMemory = nullptr;
    directions.m_Memory.m_nAllocationCount = 0;
    if ( activelights != nullptr )
    {
      do
      {
        if ( v5->light.type != emit_skyambient )
        {
          if ( y_low < 0
            || (pvs = v5->pvs,
                HIBYTE(origin.x) = 1 << (y_low & 7),
                v8 = HIBYTE(origin.x) & pvs[y_low >> 3],
                m_pMemory = lights.m_Memory.m_pMemory,
                v8 != 0) )
          {
            x = *(float *)&m_pMemory;
            LODWORD(normal.x) = m_pMemory;
            if ( (int)m_pMemory + 1 > SLODWORD(normal.z) )
            {
              CUtlMemory<int,int>::Grow(
                this: (CUtlMemory<S3RGBA,int> *)&normal.y,
                num: (int)m_pMemory - LODWORD(normal.z) + 1);
              m_pMemory = lights.m_Memory.m_pMemory;
              x = normal.x;
            }
            m_pMemory = (directlight_t **)((char *)m_pMemory + 1);
            lights.m_Memory.m_pMemory = m_pMemory;
            lights.m_Memory.m_nAllocationCount = LODWORD(normal.y);
            if ( (int)m_pMemory - LODWORD(x) - 1 > 0 )
            {
              _V_memmove(
                dest: (void *)(LODWORD(normal.y) + 4 * LODWORD(x) + 4),
                src: (const void *)(LODWORD(normal.y) + 4 * LODWORD(x)),
                count: 4 * (_DWORD)((char *)m_pMemory - LODWORD(x) - 1));
              x = normal.x;
            }
            v10 = (directlight_t **)(LODWORD(normal.y) + 4 * LODWORD(x));
            if ( v10 != nullptr )
              *v10 = v5;
            *(float *)&out_52[136] = v5->light.origin.x - *(float *)&lights.m_Memory.m_nGrowSize;
            v21 = v5->light.origin.y - *(float *)&lights.m_Size;
            v22 = v5->light.origin.z - *(float *)&lights.m_pElements;
            VectorNormalize(vec: (Vector *)&out_52[136]);
            CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int>>::InsertBefore(
              this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&delta,
              elem: (int)directions.m_Memory.m_pMemory,
              src: (const CVTFTexture::ResourceMemorySection *)&out_52[136]);
          }
          y_low = LODWORD(origin.y);
        }
        v5 = v5->next;
      }
      while ( v5 != nullptr );
    }
    v11 = (_DWORD *)(a3 + 8);
    for ( j = 64; j != 0; --j )
    {
      *(v11 - 2) = 0;
      *(v11 - 1) = 0;
      *v11 = 0;
      v11 += 3;
    }
    v13 = 0;
    if ( (int)m_pMemory > 0 )
    {
      do
      {
        v14 = *(directlight_t **)(LODWORD(normal.y) + 4 * v13);
        *(__m128 *)&out_52[80] = _mm_shuffle_ps(
                                   (__m128)(unsigned int)lights.m_Memory.m_nGrowSize,
                                   (__m128)(unsigned int)lights.m_Memory.m_nGrowSize,
                                   0);
        *(__m128 *)&out_52[96] = _mm_shuffle_ps(
                                   (__m128)(unsigned int)lights.m_Size,
                                   (__m128)(unsigned int)lights.m_Size,
                                   0);
        *(__m128 *)&out_52[112] = _mm_shuffle_ps(
                                    (__m128)(unsigned int)lights.m_pElements,
                                    (__m128)(unsigned int)lights.m_pElements,
                                    0);
        *(__m128 *)&out_52[32] = _mm_shuffle_ps(
                                   (__m128)(unsigned int)directions.m_Memory.m_nGrowSize,
                                   (__m128)(unsigned int)directions.m_Memory.m_nGrowSize,
                                   0);
        *(__m128 *)&out_52[48] = _mm_shuffle_ps(
                                   (__m128)(unsigned int)directions.m_Size,
                                   (__m128)(unsigned int)directions.m_Size,
                                   0);
        *(__m128 *)&out_52[64] = _mm_shuffle_ps(
                                   (__m128)(unsigned int)directions.m_pElements,
                                   (__m128)(unsigned int)directions.m_pElements,
                                   0);
        GatherSampleLightSSE(
          out: (SSE_sampleLightOutput_t *)&v19,
          dl: v14,
          facenum: -1,
          pos: (const FourVectors *)&out_52[80],
          pNormals: (FourVectors *)&out_52[32],
          normalCount: 1,
          iThread: a4,
          nLFlags: 0,
          static_prop_index_to_ignore: -1,
          flEpsilon: 0.0);
        v15 = v19 * *(float *)out_52;
        v16 = (float *)(a3 + 12 * v14->light.style);
        *v16 = (float)(v14->light.intensity.x * (float)(v19 * *(float *)out_52)) + *v16;
        v16[1] = (float)(v14->light.intensity.y * v15) + v16[1];
        ++v13;
        v16[2] = (float)(v14->light.intensity.z * v15) + v16[2];
      }
      while ( v13 < (int)lights.m_Memory.m_pMemory );
    }
    if ( delta.z >= 0.0 && LODWORD(delta.x) != 0 )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)LODWORD(delta.x));
    if ( v26 >= 0 && LODWORD(normal.y) != 0 )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)LODWORD(normal.y));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10026400
// Name: ComputeLighting
// Source: json
//------------------------------------------------------------------------------
void __usercall ComputeLighting(int iThread@<eax>, unsigned int a2@<ebx>, DetailObjectLump_t *prop)
{
  DetailObjectLump_t *v3; // esi
  CUtlVector<DetailPropLightstylesLump_t,CUtlMemory<DetailPropLightstylesLump_t,int> > *v5; // ecx
  int v6; // edx
  float v7; // xmm1_4
  float v8; // xmm2_4
  int m_Size; // esi
  int m_nAllocationCount; // eax
  int *p_m_Size; // edi
  CUtlVector<DetailPropLightstylesLump_t,CUtlMemory<DetailPropLightstylesLump_t,int> > *v12; // ebx
  DetailPropLightstylesLump_t *m_pMemory; // edx
  int v14; // eax
  int v15; // esi
  Vector ambColor[64]; // [esp+Ch] [ebp-618h] BYREF
  Vector directColor[64]; // [esp+30Ch] [ebp-318h] BYREF
  Vector totalColor; // [esp+60Ch] [ebp-18h] BYREF
  int v19; // [esp+618h] [ebp-Ch]
  int i; // [esp+61Ch] [ebp-8h]
  bool hasLightstyles; // [esp+623h] [ebp-1h]
  int savedregs; // [esp+624h] [ebp+0h] BYREF

  v3 = prop;
  ComputeMaxDirectLighting(prop, a2: COERCE_FLOAT(&savedregs), a3: (int)directColor, a4: iThread);
  ComputeAmbientLighting(prop, a2, iThread, color: ambColor);
  totalColor.x = ambColor[0].x + directColor[0].x;
  totalColor.y = ambColor[0].y + directColor[0].y;
  totalColor.z = directColor[0].z + ambColor[0].z;
  VectorToColorRGBExp32(vin: &totalColor, c: &prop->m_Lighting);
  v5 = s_pDetailPropLightStyleLump;
  v6 = 0;
  hasLightstyles = false;
  prop->m_LightStyleCount = 0;
  i = 1;
  v19 = 0;
  do
  {
    v7 = (float)(*(float *)((char *)&directColor[1].y + v6) + *(float *)((char *)&ambColor[1].y + v6)) * 0.5;
    v8 = (float)(*(float *)((char *)&directColor[1].z + v6) + *(float *)((char *)&ambColor[1].z + v6)) * 0.5;
    totalColor.x = (float)(*(float *)((char *)&ambColor[1].x + v6) + *(float *)((char *)&directColor[1].x + v6)) * 0.5;
    totalColor.y = v7;
    totalColor.z = v8;
    if ( totalColor.x != 0.0 || v7 != 0.0 || v8 != 0.0 )
    {
      if ( !hasLightstyles )
      {
        v3->m_LightStyles = v5->m_Size;
        hasLightstyles = true;
      }
      m_Size = v5->m_Size;
      m_nAllocationCount = v5->m_Memory.m_nAllocationCount;
      p_m_Size = &v5->m_Size;
      v12 = v5;
      if ( m_Size + 1 > m_nAllocationCount )
      {
        CUtlMemory<DetailPropLightstylesLump_t,int>::Grow(this: &v5->m_Memory, num: m_Size - m_nAllocationCount + 1);
        v5 = s_pDetailPropLightStyleLump;
      }
      ++*p_m_Size;
      m_pMemory = v12->m_Memory.m_pMemory;
      v14 = *p_m_Size - m_Size - 1;
      v12->m_pElements = v12->m_Memory.m_pMemory;
      if ( v14 > 0 )
      {
        _V_memmove(
          dest: (char *)&m_pMemory[1].m_Lighting + 4 * m_Size + m_Size,
          src: (char *)&m_pMemory->m_Lighting + 4 * m_Size + m_Size,
          count: 5 * v14);
        v5 = s_pDetailPropLightStyleLump;
      }
      v15 = m_Size;
      VectorToColorRGBExp32(vin: &totalColor, c: &v5->m_Memory.m_pMemory[v15].m_Lighting);
      v5 = s_pDetailPropLightStyleLump;
      s_pDetailPropLightStyleLump->m_Memory.m_pMemory[v15].m_Style = i;
      v6 = v19;
      ++prop->m_LightStyleCount;
      v3 = prop;
    }
    ++i;
    v6 += 12;
    v19 = v6;
  }
  while ( v6 < 756 );
}

//------------------------------------------------------------------------------
// Address: 0x100265D0
// Name: UnserializeModelDict
// Source: json
//------------------------------------------------------------------------------
void __usercall UnserializeModelDict(CUtlBuffer *buf@<edi>)
{
  int i; // ebx
  int m_Size; // eax
  int v3; // esi
  int v4; // eax
  char v5; // al
  Vector *m_pMemory; // ecx
  bool v7; // zf
  int v8; // eax
  float *v9; // esi
  int v10; // eax
  float *v11; // eax
  Vector *v12; // eax
  DetailObjectDictLump_t lump; // [esp+4h] [ebp-B0h] BYREF
  CUtlBuffer mdlbuf; // [esp+84h] [ebp-30h] BYREF

  for ( i = CUtlBuffer::GetInt(this: buf) - 1; i >= 0; --i )
  {
    CUtlBuffer::Get(this: buf, pMem: &lump, size: 128);
    m_Size = g_ModelCenterOffset.m_Size;
    v3 = g_ModelCenterOffset.m_Size;
    if ( g_ModelCenterOffset.m_Size + 1 > g_ModelCenterOffset.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<UtlLinkedListElem_t<CMasterMulticastThread::CMulticastFile *,int>,int>::Grow(
        this: (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)&g_ModelCenterOffset,
        num: g_ModelCenterOffset.m_Size - g_ModelCenterOffset.m_Memory.m_nAllocationCount + 1);
      m_Size = g_ModelCenterOffset.m_Size;
    }
    g_ModelCenterOffset.m_Size = m_Size + 1;
    v4 = m_Size - v3;
    g_ModelCenterOffset.m_pElements = g_ModelCenterOffset.m_Memory.m_pMemory;
    if ( v4 > 0 )
      _V_memmove(
        dest: &g_ModelCenterOffset.m_Memory.m_pMemory[v3 + 1],
        src: &g_ModelCenterOffset.m_Memory.m_pMemory[v3],
        count: 12 * v4);
    CUtlBuffer::CUtlBuffer(this: &mdlbuf, growSize: 0, initSize: 0, nFlags: 0);
    v5 = LoadStudioModel(pModelName: lump.m_Name, buf: &mdlbuf);
    m_pMemory = g_ModelCenterOffset.m_Memory.m_pMemory;
    v7 = v5 == 0;
    v8 = 3 * v3;
    if ( v7 )
    {
      v12 = &g_ModelCenterOffset.m_Memory.m_pMemory[v3];
      v12->x = 0.0;
      v12->y = 0.0;
      v12->z = 0.0;
    }
    else
    {
      v9 = (float *)mdlbuf.m_Memory.m_pMemory;
      v10 = 4 * v8;
      *(float *)((char *)&g_ModelCenterOffset.m_Memory.m_pMemory->x + v10) = *((float *)mdlbuf.m_Memory.m_pMemory + 29)
                                                                           + *((float *)mdlbuf.m_Memory.m_pMemory + 26);
      *(float *)((char *)&m_pMemory->y + v10) = v9[27] + v9[30];
      *(float *)((char *)&m_pMemory->z + v10) = v9[28] + v9[31];
      v11 = (float *)((char *)&g_ModelCenterOffset.m_Memory.m_pMemory->x + v10);
      *v11 = *v11 * 0.5;
      v11[1] = v11[1] * 0.5;
      v11[2] = v11[2] * 0.5;
    }
    if ( mdlbuf.m_Memory.m_nGrowSize >= 0 && mdlbuf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: mdlbuf.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10026740
// Name: UnserializeSpriteDict
// Source: json
//------------------------------------------------------------------------------
void __cdecl UnserializeSpriteDict(CUtlBuffer *buf)
{
  int i; // edi
  int m_Size; // eax
  int v3; // esi
  Vector *m_pMemory; // ecx
  int v5; // eax
  int v6; // eax
  Vector *v7; // eax
  DetailSpriteDictLump_t lump; // [esp+8h] [ebp-20h] BYREF

  for ( i = CUtlBuffer::GetInt(this: buf) - 1; i >= 0; v7->z = v7->z * 0.5 )
  {
    CUtlBuffer::Get(this: buf, pMem: &lump, size: 32);
    m_Size = g_SpriteCenterOffset.m_Size;
    v3 = g_SpriteCenterOffset.m_Size;
    if ( g_SpriteCenterOffset.m_Size + 1 > g_SpriteCenterOffset.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<UtlLinkedListElem_t<CMasterMulticastThread::CMulticastFile *,int>,int>::Grow(
        this: (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)&g_SpriteCenterOffset,
        num: g_SpriteCenterOffset.m_Size - g_SpriteCenterOffset.m_Memory.m_nAllocationCount + 1);
      m_Size = g_SpriteCenterOffset.m_Size;
    }
    m_pMemory = g_SpriteCenterOffset.m_Memory.m_pMemory;
    g_SpriteCenterOffset.m_Size = m_Size + 1;
    v5 = m_Size - v3;
    g_SpriteCenterOffset.m_pElements = g_SpriteCenterOffset.m_Memory.m_pMemory;
    if ( v5 > 0 )
    {
      _V_memmove(
        dest: &g_SpriteCenterOffset.m_Memory.m_pMemory[v3 + 1],
        src: &g_SpriteCenterOffset.m_Memory.m_pMemory[v3],
        count: 12 * v5);
      m_pMemory = g_SpriteCenterOffset.m_Memory.m_pMemory;
    }
    v6 = v3;
    m_pMemory[v6].x = 0.0;
    g_SpriteCenterOffset.m_Memory.m_pMemory[v6].y = lump.m_UL.x + lump.m_LR.x;
    g_SpriteCenterOffset.m_Memory.m_pMemory[v6].z = lump.m_UL.y + lump.m_LR.y;
    v7 = &g_SpriteCenterOffset.m_Memory.m_pMemory[v3];
    --i;
    v7->x = v7->x * 0.5;
    v7->y = v7->y * 0.5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10026850
// Name: UnserializeDetailProps
// Source: json
//------------------------------------------------------------------------------
int __cdecl UnserializeDetailProps(DetailObjectLump_t **pProps)
{
  unsigned __int16 GameLumpHandle; // si
  const void *GameLump; // eax
  int Int; // esi
  unsigned __int8 *m_pMemory; // eax
  int v6; // [esp-Ch] [ebp-44h]
  CUtlBuffer buf; // [esp+8h] [ebp-30h] BYREF

  GameLumpHandle = CGameLump::GetGameLumpHandle(this: &g_GameLumps, id: 1685090928);
  if ( CGameLump::GetGameLumpVersion(this: &g_GameLumps, handle: GameLumpHandle) != 4 )
    return 0;
  v6 = CGameLump::GameLumpSize(this: &g_GameLumps, id: GameLumpHandle);
  GameLump = CGameLump::GetGameLump(this: &g_GameLumps, id: GameLumpHandle);
  CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: GameLump, nSize: v6, nFlags: 8);
  UnserializeModelDict(&buf);
  UnserializeSpriteDict(&buf);
  Int = CUtlBuffer::GetInt(this: &buf);
  m_pMemory = buf.m_Memory.m_pMemory;
  if ( Int != 0 )
    *pProps = (DetailObjectLump_t *)&buf.m_Memory.m_pMemory[buf.m_Get - buf.m_nOffset];
  else
    *pProps = nullptr;
  if ( buf.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  return Int;
}

//------------------------------------------------------------------------------
// Address: 0x10026900
// Name: void UnserializeDetailPropLighting(int,int,class CUtlVector<struct DetailPropLightstylesLump_t,class CUtlMemory<struct DetailPropLightstylesLump_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UnserializeDetailPropLighting(
        int lumpID,
        int lumpVersion,
        CUtlVector<DetailPropLightstylesLump_t,CUtlMemory<DetailPropLightstylesLump_t,int> > *lumpData)
{
  unsigned __int16 GameLumpHandle; // si
  const void *GameLump; // eax
  int Int; // eax
  int v6; // [esp-8h] [ebp-3Ch]
  CUtlBuffer buf; // [esp+4h] [ebp-30h] BYREF

  GameLumpHandle = CGameLump::GetGameLumpHandle(this: &g_GameLumps, id: lumpID);
  if ( GameLumpHandle != CGameLump::InvalidGameLump(this: &g_GameLumps)
    && CGameLump::GetGameLumpVersion(this: &g_GameLumps, handle: GameLumpHandle) == lumpVersion )
  {
    v6 = CGameLump::GameLumpSize(this: &g_GameLumps, id: GameLumpHandle);
    GameLump = CGameLump::GetGameLump(this: &g_GameLumps, id: GameLumpHandle);
    CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: GameLump, nSize: v6, nFlags: 8);
    Int = CUtlBuffer::GetInt(this: &buf);
    if ( Int != 0 )
    {
      lumpData->m_Size = 0;
      CUtlVector<DetailPropLightstylesLump_t,CUtlMemory<DetailPropLightstylesLump_t,int>>::InsertMultipleBefore(
        this: lumpData,
        elem: 0,
        num: Int);
      CUtlBuffer::Get(this: &buf, pMem: lumpData->m_Memory.m_pMemory, size: 5 * lumpData->m_Size);
    }
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100269C0
// Name: void ComputeDetailPropLighting(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeDetailPropLighting(int iThread)
{
  signed int v1; // ebx
  int v2; // esi
  DetailObjectLump_t *v3; // edi
  DetailObjectLump_t *pProps; // [esp+14h] [ebp-4h] BYREF

  v1 = UnserializeDetailProps(&pProps);
  if ( v1 != 0 )
  {
    if ( g_bHDR )
      UnserializeDetailPropLighting(lumpID: 1685089396, lumpVersion: 0, lumpData: &s_DetailPropLightStyleLumpLDR);
    else
      UnserializeDetailPropLighting(lumpID: 1685089384, lumpVersion: 0, lumpData: &s_DetailPropLightStyleLumpHDR);
    StartPacifier(pPrefix: "Computing detail prop lighting : ");
    v2 = 0;
    if ( v1 > 0 )
    {
      v3 = pProps;
      do
      {
        UpdatePacifier(flPercent: (float)v2 / (float)v1);
        ComputeLighting(iThread, a2: v1, prop: v3);
        ++v2;
        ++v3;
      }
      while ( v2 < v1 );
    }
    WriteDetailLightingLump(lumpID: 1685089396, lumpVersion: 0, lumpData: &s_DetailPropLightStyleLumpLDR);
    WriteDetailLightingLump(lumpID: 1685089384, lumpVersion: 0, lumpData: &s_DetailPropLightStyleLumpHDR);
    EndPacifier(bCarriageReturn: true);
  }
}
