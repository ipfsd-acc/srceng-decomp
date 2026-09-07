// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/decal_clip.cpp
// Functions: 11
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x100B56C0
// Name: void R_SetupDecalVertsForMSurface(struct decal_t restrict __near *,struct msurface2_t __near *,class Vector restrict __near *,class CDecalVert restrict __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_SetupDecalVertsForMSurface(
        decal_t *pDecal,
        msurface2_t *surfID,
        Vector *pTextureSpaceBasis,
        CDecalVert *pVerts)
{
  worldbrushdata_t *worldbrush; // eax
  signed int flags_high; // ebx
  unsigned __int16 *v6; // ecx
  float v7; // xmm1_4
  float v8; // xmm2_4
  signed int v9; // esi
  mvertex_t *vertexes; // edx
  float y; // xmm3_4
  float x; // xmm4_4
  unsigned __int16 *v13; // ecx
  float *p_y; // eax
  unsigned int v15; // ebx
  float v16; // xmm5_4
  float *p_x; // esi
  double v18; // st7
  int v19; // esi
  float v20; // xmm5_4
  double v21; // st7
  int v22; // esi
  double v23; // st7
  float *v24; // esi
  float v25; // xmm5_4
  int v26; // esi
  float v27; // xmm5_4
  float v28; // xmm3_4
  float v29; // xmm4_4
  float v30; // xmm5_4
  float *v31; // eax
  float *v32; // edx
  unsigned __int16 *pIndices; // [esp+0h] [ebp-14h]
  unsigned __int16 *pIndicesa; // [esp+0h] [ebp-14h]
  int count; // [esp+4h] [ebp-10h]
  int j; // [esp+8h] [ebp-Ch]
  float z; // [esp+Ch] [ebp-8h]
  float v38; // [esp+10h] [ebp-4h]
  float v39; // [esp+10h] [ebp-4h]
  float pDecala; // [esp+1Ch] [ebp+8h]
  float pDecalb; // [esp+1Ch] [ebp+8h]
  float surfIDa; // [esp+20h] [ebp+Ch]
  float surfIDb; // [esp+20h] [ebp+Ch]

  worldbrush = host_state.worldbrush;
  flags_high = HIBYTE(surfID->flags);
  v6 = &host_state.worldbrush->vertindices[surfID->firstvertindex];
  v7 = 0.5 - pDecal->dx;
  v8 = 0.5 - pDecal->dy;
  v9 = 0;
  pIndices = v6;
  count = flags_high;
  if ( (unsigned int)flags_high >= 4 )
  {
    vertexes = host_state.worldbrush->vertexes;
    y = pTextureSpaceBasis->y;
    x = pTextureSpaceBasis->x;
    z = pTextureSpaceBasis->z;
    pDecala = pTextureSpaceBasis[1].y;
    v13 = v6 + 2;
    p_y = &pVerts[1].m_vPos.y;
    v15 = ((unsigned int)(flags_high - 4) >> 2) + 1;
    surfIDa = pTextureSpaceBasis[1].x;
    v38 = pTextureSpaceBasis[1].z;
    j = 4 * v15;
    do
    {
      v16 = vertexes[*(v13 - 2)].position.z;
      p_x = &vertexes[*(v13 - 2)].position.x;
      *(p_y - 9) = *p_x;
      v18 = p_x[1];
      v19 = *(v13 - 1);
      *(p_y - 8) = v18;
      *(p_y - 7) = v16;
      *(p_y - 5) = (float)((float)((float)(x * *(p_y - 9)) + (float)(*(p_y - 8) * y)) + (float)(z * v16)) + v7;
      *(p_y - 4) = (float)((float)((float)(surfIDa * *(p_y - 9)) + (float)(pDecala * *(p_y - 8)))
                         + (float)(v38 * *(p_y - 7)))
                 + v8;
      *(p_y - 3) = 0.0;
      *(p_y - 2) = 0.0;
      v19 *= 3;
      v20 = *(&vertexes->position.z + v19);
      *(p_y - 1) = *(&vertexes->position.x + v19);
      v21 = *(&vertexes->position.y + v19);
      v22 = *v13;
      *p_y = v21;
      p_y[1] = v20;
      p_y[3] = (float)((float)((float)(x * *(p_y - 1)) + (float)(*p_y * y)) + (float)(z * v20)) + v7;
      v22 *= 3;
      v23 = *(&vertexes->position.x + v22);
      v24 = &vertexes->position.x + v22;
      p_y[4] = (float)((float)((float)(surfIDa * *(p_y - 1)) + (float)(pDecala * *p_y)) + (float)(v38 * p_y[1])) + v8;
      v25 = v24[2];
      p_y[5] = 0.0;
      p_y[6] = 0.0;
      p_y[7] = v23;
      p_y[8] = v24[1];
      p_y[9] = v25;
      p_y[11] = (float)((float)((float)(y * p_y[8]) + (float)(x * p_y[7])) + (float)(z * v25)) + v7;
      v26 = v13[1];
      p_y[12] = (float)((float)((float)(pDecala * p_y[8]) + (float)(surfIDa * p_y[7])) + (float)(v38 * p_y[9])) + v8;
      p_y[13] = 0.0;
      p_y[14] = 0.0;
      v26 *= 3;
      v27 = *(&vertexes->position.z + v26);
      p_y[15] = *(&vertexes->position.x + v26);
      p_y[16] = *(&vertexes->position.y + v26);
      p_y[17] = v27;
      p_y[19] = (float)((float)((float)(x * p_y[15]) + (float)(p_y[16] * y)) + (float)(z * v27)) + v7;
      p_y[20] = (float)((float)((float)(surfIDa * p_y[15]) + (float)(pDecala * p_y[16])) + (float)(v38 * p_y[17])) + v8;
      p_y[21] = 0.0;
      p_y[22] = 0.0;
      v13 += 4;
      p_y += 32;
      --v15;
    }
    while ( v15 != 0 );
    v9 = j;
    flags_high = count;
    v6 = pIndices;
    worldbrush = host_state.worldbrush;
  }
  if ( v9 < flags_high )
  {
    v28 = pTextureSpaceBasis->y;
    v29 = pTextureSpaceBasis->x;
    v30 = pTextureSpaceBasis->z;
    pDecalb = pTextureSpaceBasis[1].y;
    surfIDb = pTextureSpaceBasis[1].x;
    pIndicesa = (unsigned __int16 *)worldbrush->vertexes;
    v39 = pTextureSpaceBasis[1].z;
    v31 = &pVerts[v9].m_vPos.y;
    do
    {
      v32 = (float *)&pIndicesa[6 * v6[v9++]];
      *(v31 - 1) = *v32;
      v31 += 8;
      *(v31 - 8) = v32[1];
      *(v31 - 7) = v32[2];
      *(v31 - 5) = (float)((float)((float)(v29 * *(v31 - 9)) + (float)(v28 * *(v31 - 8))) + (float)(v30 * *(v31 - 7)))
                 + v7;
      *(v31 - 4) = (float)((float)((float)(surfIDb * *(v31 - 9)) + (float)(pDecalb * *(v31 - 8)))
                         + (float)(v39 * *(v31 - 7)))
                 + v8;
      *(v31 - 3) = 0.0;
      *(v31 - 2) = 0.0;
    }
    while ( v9 < flags_high );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B5A70
// Name: void R_DecalComputeBasis(class Vector const __near &,class Vector const __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_DecalComputeBasis(const Vector *surfaceNormal, const Vector *pSAxis, Vector *textureSpaceBasis)
{
  float v3; // xmm0_4
  float x; // xmm3_4
  float y; // xmm2_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm0_4
  float v10; // xmm0_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm3_4
  float v16; // xmm2_4
  float v17; // xmm1_4
  float z; // xmm3_4
  float v19; // xmm0_4
  float v20; // xmm4_4
  float v21; // [esp-10h] [ebp-1Ch]

  textureSpaceBasis[2] = *surfaceNormal;
  if ( pSAxis != nullptr
    && (textureSpaceBasis[1].x = (float)(pSAxis->y * textureSpaceBasis[2].z)
                               - (float)(textureSpaceBasis[2].y * pSAxis->z),
        textureSpaceBasis[1].y = (float)(pSAxis->z * textureSpaceBasis[2].x)
                               - (float)(pSAxis->x * textureSpaceBasis[2].z),
        v3 = (float)(pSAxis->x * textureSpaceBasis[2].y) - (float)(pSAxis->y * textureSpaceBasis[2].x),
        textureSpaceBasis[1].z = v3,
        textureSpaceBasis[1].x * textureSpaceBasis[1].x
      + textureSpaceBasis[1].y * textureSpaceBasis[1].y
      + textureSpaceBasis[1].z * textureSpaceBasis[1].z > 0.000001) )
  {
    textureSpaceBasis->x = (float)(v3 * textureSpaceBasis[2].y)
                         - (float)(textureSpaceBasis[2].z * textureSpaceBasis[1].y);
    x = textureSpaceBasis->x;
    textureSpaceBasis->y = (float)(textureSpaceBasis[1].x * textureSpaceBasis[2].z)
                         - (float)(textureSpaceBasis[1].z * textureSpaceBasis[2].x);
    y = textureSpaceBasis->y;
    v6 = (float)(textureSpaceBasis[1].y * textureSpaceBasis[2].x)
       - (float)(textureSpaceBasis[1].x * textureSpaceBasis[2].y);
    textureSpaceBasis->z = v6;
    v7 = (float)((float)((float)(x * x) + 0.00000011920929) + (float)(y * y)) + (float)(v6 * v6);
    v8 = 1.0 / fsqrt(v7);
    v9 = (float)(3.0 - (float)((float)(v8 * v7) * v8)) * (float)(v8 * 0.5);
    textureSpaceBasis->x = x * v9;
    textureSpaceBasis->y = y * v9;
  }
  else
  {
    if ( fabs(surfaceNormal->z) <= 0.70710677 )
    {
      textureSpaceBasis[1].x = 0.0;
      textureSpaceBasis[1].y = 0.0;
      textureSpaceBasis[1].z = -1.0;
      textureSpaceBasis->x = (float)(-1.0 * textureSpaceBasis[2].y)
                           - (float)(textureSpaceBasis[2].z * textureSpaceBasis[1].y);
      textureSpaceBasis->y = (float)(textureSpaceBasis[1].x * textureSpaceBasis[2].z)
                           - (float)(textureSpaceBasis[1].z * textureSpaceBasis[2].x);
      v11 = (float)(textureSpaceBasis[1].y * textureSpaceBasis[2].x)
          - (float)(textureSpaceBasis[1].x * textureSpaceBasis[2].y);
      v12 = textureSpaceBasis->y;
      textureSpaceBasis->z = v11;
      textureSpaceBasis[1].x = (float)(v12 * textureSpaceBasis[2].z) - (float)(v11 * textureSpaceBasis[2].y);
      textureSpaceBasis[1].y = (float)(textureSpaceBasis->z * textureSpaceBasis[2].x)
                             - (float)(textureSpaceBasis->x * textureSpaceBasis[2].z);
      textureSpaceBasis[1].z = (float)(textureSpaceBasis->x * textureSpaceBasis[2].y)
                             - (float)(textureSpaceBasis->y * textureSpaceBasis[2].x);
    }
    else
    {
      textureSpaceBasis->x = 1.0;
      textureSpaceBasis->y = 0.0;
      textureSpaceBasis->z = 0.0;
      textureSpaceBasis[1].x = (float)(0.0 * textureSpaceBasis[2].z)
                             - (float)(textureSpaceBasis->z * textureSpaceBasis[2].y);
      textureSpaceBasis[1].y = (float)(textureSpaceBasis->z * textureSpaceBasis[2].x)
                             - (float)(textureSpaceBasis->x * textureSpaceBasis[2].z);
      v10 = (float)(textureSpaceBasis->x * textureSpaceBasis[2].y)
          - (float)(textureSpaceBasis->y * textureSpaceBasis[2].x);
      textureSpaceBasis[1].z = v10;
      textureSpaceBasis->x = (float)(v10 * textureSpaceBasis[2].y)
                           - (float)(textureSpaceBasis[2].z * textureSpaceBasis[1].y);
      textureSpaceBasis->y = (float)(textureSpaceBasis[1].x * textureSpaceBasis[2].z)
                           - (float)(textureSpaceBasis[1].z * textureSpaceBasis[2].x);
      textureSpaceBasis->z = (float)(textureSpaceBasis[1].y * textureSpaceBasis[2].x)
                           - (float)(textureSpaceBasis[1].x * textureSpaceBasis[2].y);
    }
    v13 = textureSpaceBasis->y;
    v14 = (float)((float)((float)(textureSpaceBasis->x * textureSpaceBasis->x) + 0.00000011920929) + (float)(v13 * v13))
        + (float)(textureSpaceBasis->z * textureSpaceBasis->z);
    v15 = 1.0 / fsqrt(v14);
    v9 = (float)(3.0 - (float)((float)(v15 * v14) * v15)) * (float)(v15 * 0.5);
    textureSpaceBasis->x = textureSpaceBasis->x * v9;
    textureSpaceBasis->y = v13 * v9;
  }
  textureSpaceBasis->z = textureSpaceBasis->z * v9;
  v16 = textureSpaceBasis[1].x;
  v17 = textureSpaceBasis[1].y;
  z = textureSpaceBasis[1].z;
  v19 = (float)((float)((float)(v16 * v16) + 0.00000011920929) + (float)(v17 * v17)) + (float)(z * z);
  v21 = 1.0 / fsqrt(v19);
  v20 = (float)(3.0 - (float)((float)(v21 * v19) * v21)) * (float)(v21 * 0.5);
  textureSpaceBasis[1].z = z * v20;
  textureSpaceBasis[1].y = v17 * v20;
  textureSpaceBasis[1].x = v16 * v20;
}

//------------------------------------------------------------------------------
// Address: 0x100B5EA0
// Name: void R_SetupDecalTextureSpaceBasis(struct decal_t __near *,class Vector __near &,class IMaterial __near *,class Vector __near * const,float __near * const)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_SetupDecalTextureSpaceBasis(
        decal_t *pDecal,
        Vector *vSurfNormal,
        IMaterial *pMaterial,
        Vector *textureSpaceBasis,
        float *decalWorldScale)
{
  Vector *p_saxis; // eax
  int v7; // esi
  int v8; // eax
  float v9; // xmm0_4
  float v10; // xmm0_4
  float v11; // xmm0_4
  int nWidth; // [esp+20h] [ebp+14h]

  if ( SLOBYTE(pDecal->flags) >= 0 )
    p_saxis = nullptr;
  else
    p_saxis = &pDecal->saxis;
  R_DecalComputeBasis(surfaceNormal: vSurfNormal, pSAxis: p_saxis, textureSpaceBasis);
  if ( pMaterial->GetMappingWidth(this: pMaterial) <= 1 )
    nWidth = 1;
  else
    nWidth = pMaterial->GetMappingWidth(this: pMaterial);
  if ( pMaterial->GetMappingHeight(this: pMaterial) <= 1 )
    v7 = 1;
  else
    v7 = pMaterial->GetMappingHeight(this: pMaterial);
  *decalWorldScale = pDecal->scale / (float)nWidth;
  decalWorldScale[1] = pDecal->scale / (float)v7;
  if ( (pDecal->flags & 0x1000) != 0 )
  {
    v8 = v7 / 64;
    if ( nWidth / 64 > v7 / 64 )
      v8 = nWidth / 64;
    v9 = (float)v8;
    if ( (float)v8 > 1.0 )
    {
      *decalWorldScale = *decalWorldScale * v9;
      decalWorldScale[1] = decalWorldScale[1] * v9;
    }
  }
  v10 = *decalWorldScale;
  textureSpaceBasis->x = textureSpaceBasis->x * *decalWorldScale;
  textureSpaceBasis->y = textureSpaceBasis->y * v10;
  textureSpaceBasis->z = textureSpaceBasis->z * v10;
  v11 = decalWorldScale[1];
  textureSpaceBasis[1].x = textureSpaceBasis[1].x * v11;
  textureSpaceBasis[1].y = textureSpaceBasis[1].y * v11;
  textureSpaceBasis[1].z = textureSpaceBasis[1].z * v11;
}

//------------------------------------------------------------------------------
// Address: 0x100B5FF0
// Name: void R_SetupDecalClip(class CDecalVert __near * __near &,struct decal_t __near *,class Vector __near &,class IMaterial __near *,class Vector __near * const,float __near * const)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_SetupDecalClip(
        CDecalVert **pOutVerts,
        decal_t *pDecal,
        Vector *vSurfNormal,
        IMaterial *pMaterial,
        Vector *textureSpaceBasis,
        float *decalWorldScale)
{
  R_SetupDecalTextureSpaceBasis(pDecal, vSurfNormal, pMaterial, textureSpaceBasis, decalWorldScale);
  pDecal->dx = (float)((float)(textureSpaceBasis->y * pDecal->position.y)
                     + (float)(textureSpaceBasis->x * pDecal->position.x))
             + (float)(textureSpaceBasis->z * pDecal->position.z);
  pDecal->dy = (float)((float)(textureSpaceBasis[1].y * pDecal->position.y)
                     + (float)(textureSpaceBasis[1].x * pDecal->position.x))
             + (float)(textureSpaceBasis[1].z * pDecal->position.z);
}

//------------------------------------------------------------------------------
// Address: 0x100B6070
// Name: SHClip_CPlane_Top_
// Source: json
//------------------------------------------------------------------------------
int __fastcall SHClip_CPlane_Top_(CDecalVert *pDecalClipVerts, CDecalVert *out, int vertCount)
{
  int v3; // edi
  int result; // eax
  CDecalVert *v5; // esi
  float *p_y; // ecx
  float v7; // xmm0_4
  float y; // xmm1_4
  float v9; // xmm0_4

  v3 = vertCount;
  result = 0;
  v5 = &pDecalClipVerts[vertCount - 1];
  if ( vertCount > 0 )
  {
    p_y = &pDecalClipVerts->m_ctCoords.y;
    do
    {
      if ( *p_y >= 1.0 )
      {
        y = v5->m_ctCoords.y;
        if ( y < 1.0 )
        {
          v9 = (float)(1.0 - *p_y) / (float)(y - *p_y);
          out->m_vPos.x = (float)((float)(v5->m_vPos.x - *(p_y - 5)) * v9) + *(p_y - 5);
          out->m_vPos.y = (float)((float)(v5->m_vPos.y - *(p_y - 4)) * v9) + *(p_y - 4);
          out->m_vPos.z = (float)((float)(v5->m_vPos.z - *(p_y - 3)) * v9) + *(p_y - 3);
          out->m_cLMCoords.x = (float)((float)(v5->m_cLMCoords.x - p_y[1]) * v9) + p_y[1];
          out->m_cLMCoords.y = (float)((float)(v5->m_cLMCoords.y - p_y[2]) * v9) + p_y[2];
          out->m_ctCoords.x = (float)((float)(v5->m_ctCoords.x - *(p_y - 1)) * v9) + *(p_y - 1);
          out->m_ctCoords.y = (float)((float)(v5->m_ctCoords.y - *p_y) * v9) + *p_y;
          ++out;
          ++result;
        }
      }
      else
      {
        if ( v5->m_ctCoords.y >= 1.0 )
        {
          v7 = (float)(1.0 - v5->m_ctCoords.y) / (float)(*p_y - v5->m_ctCoords.y);
          out->m_vPos.x = (float)((float)(*(p_y - 5) - v5->m_vPos.x) * v7) + v5->m_vPos.x;
          out->m_vPos.y = (float)((float)(*(p_y - 4) - v5->m_vPos.y) * v7) + v5->m_vPos.y;
          out->m_vPos.z = (float)((float)(*(p_y - 3) - v5->m_vPos.z) * v7) + v5->m_vPos.z;
          out->m_cLMCoords.x = (float)((float)(p_y[1] - v5->m_cLMCoords.x) * v7) + v5->m_cLMCoords.x;
          out->m_cLMCoords.y = (float)((float)(p_y[2] - v5->m_cLMCoords.y) * v7) + v5->m_cLMCoords.y;
          out->m_ctCoords.x = (float)((float)(*(p_y - 1) - v5->m_ctCoords.x) * v7) + v5->m_ctCoords.x;
          out->m_ctCoords.y = (float)((float)(*p_y - v5->m_ctCoords.y) * v7) + v5->m_ctCoords.y;
          out[1].m_vPos.x = *(p_y - 5);
          result += 2;
          out += 2;
        }
        else
        {
          ++result;
          out->m_vPos.x = *(p_y - 5);
          ++out;
        }
        out[-1].m_vPos.y = *(p_y - 4);
        out[-1].m_vPos.z = *(p_y - 3);
        out[-1].m_decalIndex = *(int *)(p_y - 2);
        out[-1].m_ctCoords = *(Vector2D *)(p_y - 1);
        out[-1].m_cLMCoords = *(Vector2D *)(p_y + 1);
      }
      v5 = (CDecalVert *)(p_y - 5);
      p_y += 8;
      --v3;
    }
    while ( v3 != 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B62C0
// Name: SHClip_CPlane_Left_
// Source: json
//------------------------------------------------------------------------------
int __fastcall SHClip_CPlane_Left_(CDecalVert *pDecalClipVerts, CDecalVert *out, int vertCount)
{
  int v3; // edi
  int result; // eax
  CDecalVert *v5; // esi
  float *p_y; // ecx
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm0_4
  float x; // xmm1_4
  float v11; // xmm0_4

  v3 = vertCount;
  result = 0;
  v5 = &pDecalClipVerts[vertCount - 1];
  if ( vertCount > 0 )
  {
    p_y = &pDecalClipVerts->m_ctCoords.y;
    do
    {
      v7 = *(p_y - 1);
      if ( v7 <= 0.0 )
      {
        x = v5->m_ctCoords.x;
        if ( x > 0.0 )
        {
          v11 = *(p_y - 1) / (float)(*(p_y - 1) - x);
          out->m_vPos.x = (float)((float)(v5->m_vPos.x - *(p_y - 5)) * v11) + *(p_y - 5);
          out->m_vPos.y = (float)((float)(v5->m_vPos.y - *(p_y - 4)) * v11) + *(p_y - 4);
          out->m_vPos.z = (float)((float)(v5->m_vPos.z - *(p_y - 3)) * v11) + *(p_y - 3);
          out->m_cLMCoords.x = (float)((float)(v5->m_cLMCoords.x - p_y[1]) * v11) + p_y[1];
          out->m_cLMCoords.y = (float)((float)(v5->m_cLMCoords.y - p_y[2]) * v11) + p_y[2];
          out->m_ctCoords.x = (float)((float)(v5->m_ctCoords.x - *(p_y - 1)) * v11) + *(p_y - 1);
          out->m_ctCoords.y = (float)((float)(v5->m_ctCoords.y - *p_y) * v11) + *p_y;
          ++out;
          ++result;
        }
      }
      else
      {
        v8 = v5->m_ctCoords.x;
        if ( v8 <= 0.0 )
        {
          v9 = v8 / (float)(v8 - v7);
          out->m_vPos.x = (float)((float)(*(p_y - 5) - v5->m_vPos.x) * v9) + v5->m_vPos.x;
          out->m_vPos.y = (float)((float)(*(p_y - 4) - v5->m_vPos.y) * v9) + v5->m_vPos.y;
          out->m_vPos.z = (float)((float)(*(p_y - 3) - v5->m_vPos.z) * v9) + v5->m_vPos.z;
          out->m_cLMCoords.x = (float)((float)(p_y[1] - v5->m_cLMCoords.x) * v9) + v5->m_cLMCoords.x;
          out->m_cLMCoords.y = (float)((float)(p_y[2] - v5->m_cLMCoords.y) * v9) + v5->m_cLMCoords.y;
          out->m_ctCoords.x = (float)((float)(*(p_y - 1) - v5->m_ctCoords.x) * v9) + v5->m_ctCoords.x;
          out->m_ctCoords.y = (float)((float)(*p_y - v5->m_ctCoords.y) * v9) + v5->m_ctCoords.y;
          out[1].m_vPos.x = *(p_y - 5);
          result += 2;
          out += 2;
        }
        else
        {
          ++result;
          out->m_vPos.x = *(p_y - 5);
          ++out;
        }
        out[-1].m_vPos.y = *(p_y - 4);
        out[-1].m_vPos.z = *(p_y - 3);
        out[-1].m_decalIndex = *(int *)(p_y - 2);
        out[-1].m_ctCoords = *(Vector2D *)(p_y - 1);
        out[-1].m_cLMCoords = *(Vector2D *)(p_y + 1);
      }
      v5 = (CDecalVert *)(p_y - 5);
      p_y += 8;
      --v3;
    }
    while ( v3 != 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B6500
// Name: SHClip_CPlane_Right_
// Source: json
//------------------------------------------------------------------------------
int __fastcall SHClip_CPlane_Right_(CDecalVert *pDecalClipVerts, CDecalVert *out, int vertCount)
{
  int v3; // edi
  int result; // eax
  CDecalVert *v5; // esi
  float *p_y; // ecx
  float v7; // xmm1_4
  float v8; // xmm0_4
  float x; // xmm1_4
  float v10; // xmm0_4

  v3 = vertCount;
  result = 0;
  v5 = &pDecalClipVerts[vertCount - 1];
  if ( vertCount > 0 )
  {
    p_y = &pDecalClipVerts->m_ctCoords.y;
    do
    {
      v7 = *(p_y - 1);
      if ( v7 >= 1.0 )
      {
        x = v5->m_ctCoords.x;
        if ( x < 1.0 )
        {
          v10 = (float)(1.0 - *(p_y - 1)) / (float)(x - *(p_y - 1));
          out->m_vPos.x = (float)((float)(v5->m_vPos.x - *(p_y - 5)) * v10) + *(p_y - 5);
          out->m_vPos.y = (float)((float)(v5->m_vPos.y - *(p_y - 4)) * v10) + *(p_y - 4);
          out->m_vPos.z = (float)((float)(v5->m_vPos.z - *(p_y - 3)) * v10) + *(p_y - 3);
          out->m_cLMCoords.x = (float)((float)(v5->m_cLMCoords.x - p_y[1]) * v10) + p_y[1];
          out->m_cLMCoords.y = (float)((float)(v5->m_cLMCoords.y - p_y[2]) * v10) + p_y[2];
          out->m_ctCoords.x = (float)((float)(v5->m_ctCoords.x - *(p_y - 1)) * v10) + *(p_y - 1);
          out->m_ctCoords.y = (float)((float)(v5->m_ctCoords.y - *p_y) * v10) + *p_y;
          ++out;
          ++result;
        }
      }
      else
      {
        if ( v5->m_ctCoords.x >= 1.0 )
        {
          v8 = (float)(1.0 - v5->m_ctCoords.x) / (float)(v7 - v5->m_ctCoords.x);
          out->m_vPos.x = (float)((float)(*(p_y - 5) - v5->m_vPos.x) * v8) + v5->m_vPos.x;
          out->m_vPos.y = (float)((float)(*(p_y - 4) - v5->m_vPos.y) * v8) + v5->m_vPos.y;
          out->m_vPos.z = (float)((float)(*(p_y - 3) - v5->m_vPos.z) * v8) + v5->m_vPos.z;
          out->m_cLMCoords.x = (float)((float)(p_y[1] - v5->m_cLMCoords.x) * v8) + v5->m_cLMCoords.x;
          out->m_cLMCoords.y = (float)((float)(p_y[2] - v5->m_cLMCoords.y) * v8) + v5->m_cLMCoords.y;
          out->m_ctCoords.x = (float)((float)(*(p_y - 1) - v5->m_ctCoords.x) * v8) + v5->m_ctCoords.x;
          out->m_ctCoords.y = (float)((float)(*p_y - v5->m_ctCoords.y) * v8) + v5->m_ctCoords.y;
          out[1].m_vPos.x = *(p_y - 5);
          result += 2;
          out += 2;
        }
        else
        {
          ++result;
          out->m_vPos.x = *(p_y - 5);
          ++out;
        }
        out[-1].m_vPos.y = *(p_y - 4);
        out[-1].m_vPos.z = *(p_y - 3);
        out[-1].m_decalIndex = *(int *)(p_y - 2);
        out[-1].m_ctCoords = *(Vector2D *)(p_y - 1);
        out[-1].m_cLMCoords = *(Vector2D *)(p_y + 1);
      }
      v5 = (CDecalVert *)(p_y - 5);
      p_y += 8;
      --v3;
    }
    while ( v3 != 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B6750
// Name: SHClip_CPlane_Bottom_
// Source: json
//------------------------------------------------------------------------------
int __fastcall SHClip_CPlane_Bottom_(CDecalVert *pDecalClipVerts, CDecalVert *out, int vertCount)
{
  int v3; // edi
  int result; // eax
  CDecalVert *v5; // esi
  float *p_y; // ecx
  float v7; // xmm0_4
  float v8; // xmm0_4
  float y; // xmm1_4
  float v10; // xmm0_4

  v3 = vertCount;
  result = 0;
  v5 = &pDecalClipVerts[vertCount - 1];
  if ( vertCount > 0 )
  {
    p_y = &pDecalClipVerts->m_ctCoords.y;
    do
    {
      if ( *p_y <= 0.0 )
      {
        y = v5->m_ctCoords.y;
        if ( y > 0.0 )
        {
          v10 = *p_y / (float)(*p_y - y);
          out->m_vPos.x = (float)((float)(v5->m_vPos.x - *(p_y - 5)) * v10) + *(p_y - 5);
          out->m_vPos.y = (float)((float)(v5->m_vPos.y - *(p_y - 4)) * v10) + *(p_y - 4);
          out->m_vPos.z = (float)((float)(v5->m_vPos.z - *(p_y - 3)) * v10) + *(p_y - 3);
          out->m_cLMCoords.x = (float)((float)(v5->m_cLMCoords.x - p_y[1]) * v10) + p_y[1];
          out->m_cLMCoords.y = (float)((float)(v5->m_cLMCoords.y - p_y[2]) * v10) + p_y[2];
          out->m_ctCoords.x = (float)((float)(v5->m_ctCoords.x - *(p_y - 1)) * v10) + *(p_y - 1);
          out->m_ctCoords.y = (float)((float)(v5->m_ctCoords.y - *p_y) * v10) + *p_y;
          ++out;
          ++result;
        }
      }
      else
      {
        v7 = v5->m_ctCoords.y;
        if ( v7 <= 0.0 )
        {
          v8 = v7 / (float)(v7 - *p_y);
          out->m_vPos.x = (float)((float)(*(p_y - 5) - v5->m_vPos.x) * v8) + v5->m_vPos.x;
          out->m_vPos.y = (float)((float)(*(p_y - 4) - v5->m_vPos.y) * v8) + v5->m_vPos.y;
          out->m_vPos.z = (float)((float)(*(p_y - 3) - v5->m_vPos.z) * v8) + v5->m_vPos.z;
          out->m_cLMCoords.x = (float)((float)(p_y[1] - v5->m_cLMCoords.x) * v8) + v5->m_cLMCoords.x;
          out->m_cLMCoords.y = (float)((float)(p_y[2] - v5->m_cLMCoords.y) * v8) + v5->m_cLMCoords.y;
          out->m_ctCoords.x = (float)((float)(*(p_y - 1) - v5->m_ctCoords.x) * v8) + v5->m_ctCoords.x;
          out->m_ctCoords.y = (float)((float)(*p_y - v5->m_ctCoords.y) * v8) + v5->m_ctCoords.y;
          out[1].m_vPos.x = *(p_y - 5);
          result += 2;
          out += 2;
        }
        else
        {
          ++result;
          out->m_vPos.x = *(p_y - 5);
          ++out;
        }
        out[-1].m_vPos.y = *(p_y - 4);
        out[-1].m_vPos.z = *(p_y - 3);
        out[-1].m_decalIndex = *(int *)(p_y - 2);
        out[-1].m_ctCoords = *(Vector2D *)(p_y - 1);
        out[-1].m_cLMCoords = *(Vector2D *)(p_y + 1);
      }
      v5 = (CDecalVert *)(p_y - 5);
      p_y += 8;
      --v3;
    }
    while ( v3 != 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B6990
// Name: class CDecalVert __near * R_DoDecalSHClip(class CDecalVert __near *,class CDecalVert __near *,struct decal_t __near *,int,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl R_DoDecalSHClip(
        CDecalVert *pInVerts,
        CDecalVert *pOutVerts,
        decal_t *pDecal,
        int nStartVerts,
        const Vector *vecNormal)
{
  CDecalVert *v5; // ebx
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int result; // eax
  int v10; // esi
  int v11; // edi
  unsigned int v12; // edx
  float *p_z; // eax
  float *v14; // eax
  int v15; // edx
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm3_4
  int v20; // edx
  unsigned int v21; // ecx
  float *p_y; // eax
  float *v23; // eax
  int v24; // esi
  float scale[2]; // [esp+8h] [ebp-10h] BYREF
  float offset[2]; // [esp+10h] [ebp-8h] BYREF

  v5 = pOutVerts;
  if ( pOutVerts == nullptr )
    v5 = g_DecalClipVerts;
  v6 = SHClip_CPlane_Top_(pDecalClipVerts: pInVerts, out: g_DecalClipVerts2, vertCount: nStartVerts);
  v7 = SHClip_CPlane_Left_(pDecalClipVerts: g_DecalClipVerts2, out: g_DecalClipVerts, vertCount: v6);
  v8 = SHClip_CPlane_Right_(pDecalClipVerts: g_DecalClipVerts, out: g_DecalClipVerts2, vertCount: v7);
  result = SHClip_CPlane_Bottom_(pDecalClipVerts: g_DecalClipVerts2, out: v5, vertCount: v8);
  v10 = result;
  pDecal->clippedVertCount = result;
  if ( result != 0 )
  {
    v11 = 0;
    if ( result >= 4 )
    {
      v12 = ((unsigned int)(result - 4) >> 2) + 1;
      p_z = &v5[1].m_vPos.z;
      v11 = 4 * v12;
      do
      {
        *(p_z - 10) = (float)(vecNormal->x * 0.1) + *(p_z - 10);
        *(p_z - 9) = (float)(vecNormal->y * 0.1) + *(p_z - 9);
        *(p_z - 8) = (float)(vecNormal->z * 0.1) + *(p_z - 8);
        *(p_z - 2) = (float)(vecNormal->x * 0.1) + *(p_z - 2);
        *(p_z - 1) = (float)(vecNormal->y * 0.1) + *(p_z - 1);
        *p_z = (float)(vecNormal->z * 0.1) + *p_z;
        p_z[6] = (float)(vecNormal->x * 0.1) + p_z[6];
        p_z[7] = (float)(vecNormal->y * 0.1) + p_z[7];
        p_z[8] = (float)(vecNormal->z * 0.1) + p_z[8];
        p_z[14] = (float)(vecNormal->x * 0.1) + p_z[14];
        p_z[15] = (float)(vecNormal->y * 0.1) + p_z[15];
        p_z[16] = (float)(vecNormal->z * 0.1) + p_z[16];
        p_z += 32;
        --v12;
      }
      while ( v12 != 0 );
    }
    if ( v11 < v10 )
    {
      v14 = &v5[v11].m_vPos.z;
      v15 = v10 - v11;
      do
      {
        *(v14 - 2) = (float)(vecNormal->x * 0.1) + *(v14 - 2);
        *(v14 - 1) = (float)(vecNormal->y * 0.1) + *(v14 - 1);
        *v14 = (float)(vecNormal->z * 0.1) + *v14;
        v14 += 8;
        --v15;
      }
      while ( v15 != 0 );
    }
    if ( pDecal->material->InMaterialPage(this: pDecal->material) )
    {
      pDecal->material->GetMaterialOffset(this: pDecal->material, a2: offset);
      pDecal->material->GetMaterialScale(this: pDecal->material, a2: scale);
      v16 = offset[1];
      v17 = offset[0];
      v18 = scale[1];
      v19 = scale[0];
      v20 = 0;
      if ( v10 >= 4 )
      {
        v21 = ((unsigned int)(v10 - 4) >> 2) + 1;
        p_y = &v5->m_ctCoords.y;
        v20 = 4 * v21;
        do
        {
          *(p_y - 1) = (float)(v19 * *(p_y - 1)) + v17;
          *p_y = (float)(v18 * *p_y) + v16;
          p_y[7] = (float)(p_y[7] * v19) + v17;
          p_y[8] = (float)(p_y[8] * v18) + v16;
          p_y[15] = (float)(p_y[15] * v19) + v17;
          p_y[16] = (float)(v18 * p_y[16]) + v16;
          p_y[23] = (float)(p_y[23] * v19) + v17;
          p_y[24] = (float)(p_y[24] * v18) + v16;
          p_y += 32;
          --v21;
        }
        while ( v21 != 0 );
      }
      if ( v20 < v10 )
      {
        v23 = &v5[v20].m_ctCoords.y;
        v24 = v10 - v20;
        do
        {
          *(v23 - 1) = (float)(v19 * *(v23 - 1)) + v17;
          *v23 = (float)(v18 * *v23) + v16;
          v23 += 8;
          --v24;
        }
        while ( v24 != 0 );
      }
    }
    return (int)v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B6CA0
// Name: class CDecalVert __near * R_DecalVertsClip(class CDecalVert __near *,struct decal_t __near *,struct msurface2_t __near *,class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
CDecalVert *__cdecl R_DecalVertsClip(CDecalVert *pOutVerts, decal_t *pDecal, msurface2_t *surfID, IMaterial *pMaterial)
{
  Vector textureSpaceBasis[3]; // [esp+8h] [ebp-2Ch] BYREF
  float decalWorldScale[2]; // [esp+2Ch] [ebp-8h] BYREF

  R_SetupDecalTextureSpaceBasis(
    pDecal,
    vSurfNormal: &surfID->plane->normal,
    pMaterial,
    textureSpaceBasis,
    decalWorldScale);
  pDecal->dx = (float)((float)(pDecal->position.x * textureSpaceBasis[0].x)
                     + (float)(pDecal->position.y * textureSpaceBasis[0].y))
             + (float)(pDecal->position.z * textureSpaceBasis[0].z);
  pDecal->dy = (float)((float)(pDecal->position.x * textureSpaceBasis[1].x)
                     + (float)(pDecal->position.y * textureSpaceBasis[1].y))
             + (float)(pDecal->position.z * textureSpaceBasis[1].z);
  R_SetupDecalVertsForMSurface(pDecal, surfID, pTextureSpaceBasis: textureSpaceBasis, pVerts: g_DecalClipVerts);
  return (CDecalVert *)R_DoDecalSHClip(
                         pInVerts: g_DecalClipVerts,
                         pOutVerts,
                         pDecal,
                         nStartVerts: HIBYTE(surfID->flags),
                         vecNormal: &surfID->plane->normal);
}

//------------------------------------------------------------------------------
// Address: 0x1025AD80
// Name: void CrossProduct(class Vector const __near &,class Vector const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CrossProduct(const float *v1, const float *v2, float *cross)
{
  *cross = (float)(v2[2] * v1[1]) - (float)(v1[2] * v2[1]);
  cross[1] = (float)(v1[2] * *v2) - (float)(*v1 * v2[2]);
  cross[2] = (float)(*v1 * v2[1]) - (float)(*v2 * v1[1]);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x100B5360
// Name: void R_SetupDecalVertsForMSurface(struct decal_t restrict __near *,struct msurface2_t __near *,class Vector restrict __near *,class CDecalVert restrict __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_SetupDecalVertsForMSurface(
        decal_t *pDecal,
        msurface2_t *surfID,
        Vector *pTextureSpaceBasis,
        CDecalVert *pVerts)
{
  worldbrushdata_t *worldbrush; // eax
  signed int flags_high; // ebx
  unsigned __int16 *v6; // ecx
  float v7; // xmm1_4
  float v8; // xmm2_4
  signed int v9; // esi
  mvertex_t *vertexes; // edx
  float y; // xmm3_4
  float x; // xmm4_4
  unsigned __int16 *v13; // ecx
  float *p_y; // eax
  unsigned int v15; // ebx
  float v16; // xmm5_4
  float *p_x; // esi
  double v18; // st7
  int v19; // esi
  float v20; // xmm5_4
  double v21; // st7
  int v22; // esi
  double v23; // st7
  float *v24; // esi
  float v25; // xmm5_4
  int v26; // esi
  float v27; // xmm5_4
  float v28; // xmm3_4
  float v29; // xmm4_4
  float v30; // xmm5_4
  float *v31; // eax
  float *v32; // edx
  unsigned __int16 *pIndices; // [esp+0h] [ebp-14h]
  unsigned __int16 *pIndicesa; // [esp+0h] [ebp-14h]
  int count; // [esp+4h] [ebp-10h]
  int j; // [esp+8h] [ebp-Ch]
  float z; // [esp+Ch] [ebp-8h]
  float v38; // [esp+10h] [ebp-4h]
  float v39; // [esp+10h] [ebp-4h]
  float pDecala; // [esp+1Ch] [ebp+8h]
  float pDecalb; // [esp+1Ch] [ebp+8h]
  float surfIDa; // [esp+20h] [ebp+Ch]
  float surfIDb; // [esp+20h] [ebp+Ch]

  worldbrush = host_state.worldbrush;
  flags_high = HIBYTE(surfID->flags);
  v6 = &host_state.worldbrush->vertindices[surfID->firstvertindex];
  v7 = 0.5 - pDecal->dx;
  v8 = 0.5 - pDecal->dy;
  v9 = 0;
  pIndices = v6;
  count = flags_high;
  if ( (unsigned int)flags_high >= 4 )
  {
    vertexes = host_state.worldbrush->vertexes;
    y = pTextureSpaceBasis->y;
    x = pTextureSpaceBasis->x;
    z = pTextureSpaceBasis->z;
    pDecala = pTextureSpaceBasis[1].y;
    v13 = v6 + 2;
    p_y = &pVerts[1].m_vPos.y;
    v15 = ((unsigned int)(flags_high - 4) >> 2) + 1;
    surfIDa = pTextureSpaceBasis[1].x;
    v38 = pTextureSpaceBasis[1].z;
    j = 4 * v15;
    do
    {
      v16 = vertexes[*(v13 - 2)].position.z;
      p_x = &vertexes[*(v13 - 2)].position.x;
      *(p_y - 9) = *p_x;
      v18 = p_x[1];
      v19 = *(v13 - 1);
      *(p_y - 8) = v18;
      *(p_y - 7) = v16;
      *(p_y - 5) = (float)((float)((float)(x * *(p_y - 9)) + (float)(*(p_y - 8) * y)) + (float)(z * v16)) + v7;
      *(p_y - 4) = (float)((float)((float)(surfIDa * *(p_y - 9)) + (float)(pDecala * *(p_y - 8)))
                         + (float)(v38 * *(p_y - 7)))
                 + v8;
      *(p_y - 3) = 0.0;
      *(p_y - 2) = 0.0;
      v19 *= 3;
      v20 = *(&vertexes->position.z + v19);
      *(p_y - 1) = *(&vertexes->position.x + v19);
      v21 = *(&vertexes->position.y + v19);
      v22 = *v13;
      *p_y = v21;
      p_y[1] = v20;
      p_y[3] = (float)((float)((float)(x * *(p_y - 1)) + (float)(*p_y * y)) + (float)(z * v20)) + v7;
      v22 *= 3;
      v23 = *(&vertexes->position.x + v22);
      v24 = &vertexes->position.x + v22;
      p_y[4] = (float)((float)((float)(surfIDa * *(p_y - 1)) + (float)(pDecala * *p_y)) + (float)(v38 * p_y[1])) + v8;
      v25 = v24[2];
      p_y[5] = 0.0;
      p_y[6] = 0.0;
      p_y[7] = v23;
      p_y[8] = v24[1];
      p_y[9] = v25;
      p_y[11] = (float)((float)((float)(y * p_y[8]) + (float)(x * p_y[7])) + (float)(z * v25)) + v7;
      v26 = v13[1];
      p_y[12] = (float)((float)((float)(pDecala * p_y[8]) + (float)(surfIDa * p_y[7])) + (float)(v38 * p_y[9])) + v8;
      p_y[13] = 0.0;
      p_y[14] = 0.0;
      v26 *= 3;
      v27 = *(&vertexes->position.z + v26);
      p_y[15] = *(&vertexes->position.x + v26);
      p_y[16] = *(&vertexes->position.y + v26);
      p_y[17] = v27;
      p_y[19] = (float)((float)((float)(x * p_y[15]) + (float)(p_y[16] * y)) + (float)(z * v27)) + v7;
      p_y[20] = (float)((float)((float)(surfIDa * p_y[15]) + (float)(pDecala * p_y[16])) + (float)(v38 * p_y[17])) + v8;
      p_y[21] = 0.0;
      p_y[22] = 0.0;
      v13 += 4;
      p_y += 32;
      --v15;
    }
    while ( v15 != 0 );
    v9 = j;
    flags_high = count;
    v6 = pIndices;
    worldbrush = host_state.worldbrush;
  }
  if ( v9 < flags_high )
  {
    v28 = pTextureSpaceBasis->y;
    v29 = pTextureSpaceBasis->x;
    v30 = pTextureSpaceBasis->z;
    pDecalb = pTextureSpaceBasis[1].y;
    surfIDb = pTextureSpaceBasis[1].x;
    pIndicesa = (unsigned __int16 *)worldbrush->vertexes;
    v39 = pTextureSpaceBasis[1].z;
    v31 = &pVerts[v9].m_vPos.y;
    do
    {
      v32 = (float *)&pIndicesa[6 * v6[v9++]];
      *(v31 - 1) = *v32;
      v31 += 8;
      *(v31 - 8) = v32[1];
      *(v31 - 7) = v32[2];
      *(v31 - 5) = (float)((float)((float)(v29 * *(v31 - 9)) + (float)(v28 * *(v31 - 8))) + (float)(v30 * *(v31 - 7)))
                 + v7;
      *(v31 - 4) = (float)((float)((float)(surfIDb * *(v31 - 9)) + (float)(pDecalb * *(v31 - 8)))
                         + (float)(v39 * *(v31 - 7)))
                 + v8;
      *(v31 - 3) = 0.0;
      *(v31 - 2) = 0.0;
    }
    while ( v9 < flags_high );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B5710
// Name: void R_DecalComputeBasis(class Vector const __near &,class Vector const __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_DecalComputeBasis(const Vector *surfaceNormal, const Vector *pSAxis, Vector *textureSpaceBasis)
{
  float v3; // xmm0_4
  float x; // xmm3_4
  float y; // xmm2_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm0_4
  float v10; // xmm0_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm3_4
  float v16; // xmm2_4
  float v17; // xmm1_4
  float z; // xmm3_4
  float v19; // xmm0_4
  float v20; // xmm4_4
  float v21; // [esp-10h] [ebp-1Ch]

  textureSpaceBasis[2] = *surfaceNormal;
  if ( pSAxis != nullptr
    && (textureSpaceBasis[1].x = (float)(pSAxis->y * textureSpaceBasis[2].z)
                               - (float)(textureSpaceBasis[2].y * pSAxis->z),
        textureSpaceBasis[1].y = (float)(pSAxis->z * textureSpaceBasis[2].x)
                               - (float)(pSAxis->x * textureSpaceBasis[2].z),
        v3 = (float)(pSAxis->x * textureSpaceBasis[2].y) - (float)(pSAxis->y * textureSpaceBasis[2].x),
        textureSpaceBasis[1].z = v3,
        textureSpaceBasis[1].x * textureSpaceBasis[1].x
      + textureSpaceBasis[1].y * textureSpaceBasis[1].y
      + textureSpaceBasis[1].z * textureSpaceBasis[1].z > 0.000001) )
  {
    textureSpaceBasis->x = (float)(v3 * textureSpaceBasis[2].y)
                         - (float)(textureSpaceBasis[2].z * textureSpaceBasis[1].y);
    x = textureSpaceBasis->x;
    textureSpaceBasis->y = (float)(textureSpaceBasis[1].x * textureSpaceBasis[2].z)
                         - (float)(textureSpaceBasis[1].z * textureSpaceBasis[2].x);
    y = textureSpaceBasis->y;
    v6 = (float)(textureSpaceBasis[1].y * textureSpaceBasis[2].x)
       - (float)(textureSpaceBasis[1].x * textureSpaceBasis[2].y);
    textureSpaceBasis->z = v6;
    v7 = (float)((float)((float)(x * x) + 0.00000011920929) + (float)(y * y)) + (float)(v6 * v6);
    v8 = 1.0 / fsqrt(v7);
    v9 = (float)(3.0 - (float)((float)(v8 * v7) * v8)) * (float)(v8 * 0.5);
    textureSpaceBasis->x = x * v9;
    textureSpaceBasis->y = y * v9;
  }
  else
  {
    if ( fabs(surfaceNormal->z) <= 0.70710677 )
    {
      textureSpaceBasis[1].x = 0.0;
      textureSpaceBasis[1].y = 0.0;
      textureSpaceBasis[1].z = -1.0;
      textureSpaceBasis->x = (float)(-1.0 * textureSpaceBasis[2].y)
                           - (float)(textureSpaceBasis[2].z * textureSpaceBasis[1].y);
      textureSpaceBasis->y = (float)(textureSpaceBasis[1].x * textureSpaceBasis[2].z)
                           - (float)(textureSpaceBasis[1].z * textureSpaceBasis[2].x);
      v11 = (float)(textureSpaceBasis[1].y * textureSpaceBasis[2].x)
          - (float)(textureSpaceBasis[1].x * textureSpaceBasis[2].y);
      v12 = textureSpaceBasis->y;
      textureSpaceBasis->z = v11;
      textureSpaceBasis[1].x = (float)(v12 * textureSpaceBasis[2].z) - (float)(v11 * textureSpaceBasis[2].y);
      textureSpaceBasis[1].y = (float)(textureSpaceBasis->z * textureSpaceBasis[2].x)
                             - (float)(textureSpaceBasis->x * textureSpaceBasis[2].z);
      textureSpaceBasis[1].z = (float)(textureSpaceBasis->x * textureSpaceBasis[2].y)
                             - (float)(textureSpaceBasis->y * textureSpaceBasis[2].x);
    }
    else
    {
      textureSpaceBasis->x = 1.0;
      textureSpaceBasis->y = 0.0;
      textureSpaceBasis->z = 0.0;
      textureSpaceBasis[1].x = (float)(0.0 * textureSpaceBasis[2].z)
                             - (float)(textureSpaceBasis->z * textureSpaceBasis[2].y);
      textureSpaceBasis[1].y = (float)(textureSpaceBasis->z * textureSpaceBasis[2].x)
                             - (float)(textureSpaceBasis->x * textureSpaceBasis[2].z);
      v10 = (float)(textureSpaceBasis->x * textureSpaceBasis[2].y)
          - (float)(textureSpaceBasis->y * textureSpaceBasis[2].x);
      textureSpaceBasis[1].z = v10;
      textureSpaceBasis->x = (float)(v10 * textureSpaceBasis[2].y)
                           - (float)(textureSpaceBasis[2].z * textureSpaceBasis[1].y);
      textureSpaceBasis->y = (float)(textureSpaceBasis[1].x * textureSpaceBasis[2].z)
                           - (float)(textureSpaceBasis[1].z * textureSpaceBasis[2].x);
      textureSpaceBasis->z = (float)(textureSpaceBasis[1].y * textureSpaceBasis[2].x)
                           - (float)(textureSpaceBasis[1].x * textureSpaceBasis[2].y);
    }
    v13 = textureSpaceBasis->y;
    v14 = (float)((float)((float)(textureSpaceBasis->x * textureSpaceBasis->x) + 0.00000011920929) + (float)(v13 * v13))
        + (float)(textureSpaceBasis->z * textureSpaceBasis->z);
    v15 = 1.0 / fsqrt(v14);
    v9 = (float)(3.0 - (float)((float)(v15 * v14) * v15)) * (float)(v15 * 0.5);
    textureSpaceBasis->x = textureSpaceBasis->x * v9;
    textureSpaceBasis->y = v13 * v9;
  }
  textureSpaceBasis->z = textureSpaceBasis->z * v9;
  v16 = textureSpaceBasis[1].x;
  v17 = textureSpaceBasis[1].y;
  z = textureSpaceBasis[1].z;
  v19 = (float)((float)((float)(v16 * v16) + 0.00000011920929) + (float)(v17 * v17)) + (float)(z * z);
  v21 = 1.0 / fsqrt(v19);
  v20 = (float)(3.0 - (float)((float)(v21 * v19) * v21)) * (float)(v21 * 0.5);
  textureSpaceBasis[1].z = z * v20;
  textureSpaceBasis[1].y = v17 * v20;
  textureSpaceBasis[1].x = v16 * v20;
}

//------------------------------------------------------------------------------
// Address: 0x100B5B40
// Name: void R_SetupDecalTextureSpaceBasis(struct decal_t __near *,class Vector __near &,class IMaterial __near *,class Vector __near * const,float __near * const)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_SetupDecalTextureSpaceBasis(
        decal_t *pDecal,
        Vector *vSurfNormal,
        IMaterial *pMaterial,
        Vector *textureSpaceBasis,
        float *decalWorldScale)
{
  Vector *p_saxis; // eax
  int v7; // esi
  int v8; // eax
  float v9; // xmm0_4
  float v10; // xmm0_4
  float v11; // xmm0_4
  int nWidth; // [esp+20h] [ebp+14h]

  if ( SLOBYTE(pDecal->flags) >= 0 )
    p_saxis = nullptr;
  else
    p_saxis = &pDecal->saxis;
  R_DecalComputeBasis(surfaceNormal: vSurfNormal, pSAxis: p_saxis, textureSpaceBasis);
  if ( pMaterial->GetMappingWidth(this: pMaterial) <= 1 )
    nWidth = 1;
  else
    nWidth = pMaterial->GetMappingWidth(this: pMaterial);
  if ( pMaterial->GetMappingHeight(this: pMaterial) <= 1 )
    v7 = 1;
  else
    v7 = pMaterial->GetMappingHeight(this: pMaterial);
  *decalWorldScale = pDecal->scale / (float)nWidth;
  decalWorldScale[1] = pDecal->scale / (float)v7;
  if ( (pDecal->flags & 0x1000) != 0 )
  {
    v8 = v7 / 64;
    if ( nWidth / 64 > v7 / 64 )
      v8 = nWidth / 64;
    v9 = (float)v8;
    if ( (float)v8 > 1.0 )
    {
      *decalWorldScale = *decalWorldScale * v9;
      decalWorldScale[1] = decalWorldScale[1] * v9;
    }
  }
  v10 = *decalWorldScale;
  textureSpaceBasis->x = textureSpaceBasis->x * *decalWorldScale;
  textureSpaceBasis->y = textureSpaceBasis->y * v10;
  textureSpaceBasis->z = textureSpaceBasis->z * v10;
  v11 = decalWorldScale[1];
  textureSpaceBasis[1].x = textureSpaceBasis[1].x * v11;
  textureSpaceBasis[1].y = textureSpaceBasis[1].y * v11;
  textureSpaceBasis[1].z = textureSpaceBasis[1].z * v11;
}

//------------------------------------------------------------------------------
// Address: 0x100B5C90
// Name: void R_SetupDecalClip(class CDecalVert __near * __near &,struct decal_t __near *,class Vector __near &,class IMaterial __near *,class Vector __near * const,float __near * const)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_SetupDecalClip(
        CDecalVert **pOutVerts,
        decal_t *pDecal,
        Vector *vSurfNormal,
        IMaterial *pMaterial,
        Vector *textureSpaceBasis,
        float *decalWorldScale)
{
  R_SetupDecalTextureSpaceBasis(pDecal, vSurfNormal, pMaterial, textureSpaceBasis, decalWorldScale);
  pDecal->dx = (float)((float)(textureSpaceBasis->y * pDecal->position.y)
                     + (float)(textureSpaceBasis->x * pDecal->position.x))
             + (float)(textureSpaceBasis->z * pDecal->position.z);
  pDecal->dy = (float)((float)(textureSpaceBasis[1].y * pDecal->position.y)
                     + (float)(textureSpaceBasis[1].x * pDecal->position.x))
             + (float)(textureSpaceBasis[1].z * pDecal->position.z);
}

//------------------------------------------------------------------------------
// Address: 0x100B5D10
// Name: SHClip_CPlane_Top_
// Source: json
//------------------------------------------------------------------------------
int __fastcall SHClip_CPlane_Top_(CDecalVert *pDecalClipVerts, CDecalVert *out, int vertCount)
{
  int v3; // edi
  int result; // eax
  CDecalVert *v5; // esi
  float *p_y; // ecx
  float v7; // xmm0_4
  float y; // xmm1_4
  float v9; // xmm0_4

  v3 = vertCount;
  result = 0;
  v5 = &pDecalClipVerts[vertCount - 1];
  if ( vertCount > 0 )
  {
    p_y = &pDecalClipVerts->m_ctCoords.y;
    do
    {
      if ( *p_y >= 1.0 )
      {
        y = v5->m_ctCoords.y;
        if ( y < 1.0 )
        {
          v9 = (float)(1.0 - *p_y) / (float)(y - *p_y);
          out->m_vPos.x = (float)((float)(v5->m_vPos.x - *(p_y - 5)) * v9) + *(p_y - 5);
          out->m_vPos.y = (float)((float)(v5->m_vPos.y - *(p_y - 4)) * v9) + *(p_y - 4);
          out->m_vPos.z = (float)((float)(v5->m_vPos.z - *(p_y - 3)) * v9) + *(p_y - 3);
          out->m_cLMCoords.x = (float)((float)(v5->m_cLMCoords.x - p_y[1]) * v9) + p_y[1];
          out->m_cLMCoords.y = (float)((float)(v5->m_cLMCoords.y - p_y[2]) * v9) + p_y[2];
          out->m_ctCoords.x = (float)((float)(v5->m_ctCoords.x - *(p_y - 1)) * v9) + *(p_y - 1);
          out->m_ctCoords.y = (float)((float)(v5->m_ctCoords.y - *p_y) * v9) + *p_y;
          ++out;
          ++result;
        }
      }
      else
      {
        if ( v5->m_ctCoords.y >= 1.0 )
        {
          v7 = (float)(1.0 - v5->m_ctCoords.y) / (float)(*p_y - v5->m_ctCoords.y);
          out->m_vPos.x = (float)((float)(*(p_y - 5) - v5->m_vPos.x) * v7) + v5->m_vPos.x;
          out->m_vPos.y = (float)((float)(*(p_y - 4) - v5->m_vPos.y) * v7) + v5->m_vPos.y;
          out->m_vPos.z = (float)((float)(*(p_y - 3) - v5->m_vPos.z) * v7) + v5->m_vPos.z;
          out->m_cLMCoords.x = (float)((float)(p_y[1] - v5->m_cLMCoords.x) * v7) + v5->m_cLMCoords.x;
          out->m_cLMCoords.y = (float)((float)(p_y[2] - v5->m_cLMCoords.y) * v7) + v5->m_cLMCoords.y;
          out->m_ctCoords.x = (float)((float)(*(p_y - 1) - v5->m_ctCoords.x) * v7) + v5->m_ctCoords.x;
          out->m_ctCoords.y = (float)((float)(*p_y - v5->m_ctCoords.y) * v7) + v5->m_ctCoords.y;
          out[1].m_vPos.x = *(p_y - 5);
          result += 2;
          out += 2;
        }
        else
        {
          ++result;
          out->m_vPos.x = *(p_y - 5);
          ++out;
        }
        out[-1].m_vPos.y = *(p_y - 4);
        out[-1].m_vPos.z = *(p_y - 3);
        out[-1].m_decalIndex = *(int *)(p_y - 2);
        out[-1].m_ctCoords = *(Vector2D *)(p_y - 1);
        out[-1].m_cLMCoords = *(Vector2D *)(p_y + 1);
      }
      v5 = (CDecalVert *)(p_y - 5);
      p_y += 8;
      --v3;
    }
    while ( v3 != 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B5F60
// Name: SHClip_CPlane_Left_
// Source: json
//------------------------------------------------------------------------------
int __fastcall SHClip_CPlane_Left_(CDecalVert *pDecalClipVerts, CDecalVert *out, int vertCount)
{
  int v3; // edi
  int result; // eax
  CDecalVert *v5; // esi
  float *p_y; // ecx
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm0_4
  float x; // xmm1_4
  float v11; // xmm0_4

  v3 = vertCount;
  result = 0;
  v5 = &pDecalClipVerts[vertCount - 1];
  if ( vertCount > 0 )
  {
    p_y = &pDecalClipVerts->m_ctCoords.y;
    do
    {
      v7 = *(p_y - 1);
      if ( v7 <= 0.0 )
      {
        x = v5->m_ctCoords.x;
        if ( x > 0.0 )
        {
          v11 = *(p_y - 1) / (float)(*(p_y - 1) - x);
          out->m_vPos.x = (float)((float)(v5->m_vPos.x - *(p_y - 5)) * v11) + *(p_y - 5);
          out->m_vPos.y = (float)((float)(v5->m_vPos.y - *(p_y - 4)) * v11) + *(p_y - 4);
          out->m_vPos.z = (float)((float)(v5->m_vPos.z - *(p_y - 3)) * v11) + *(p_y - 3);
          out->m_cLMCoords.x = (float)((float)(v5->m_cLMCoords.x - p_y[1]) * v11) + p_y[1];
          out->m_cLMCoords.y = (float)((float)(v5->m_cLMCoords.y - p_y[2]) * v11) + p_y[2];
          out->m_ctCoords.x = (float)((float)(v5->m_ctCoords.x - *(p_y - 1)) * v11) + *(p_y - 1);
          out->m_ctCoords.y = (float)((float)(v5->m_ctCoords.y - *p_y) * v11) + *p_y;
          ++out;
          ++result;
        }
      }
      else
      {
        v8 = v5->m_ctCoords.x;
        if ( v8 <= 0.0 )
        {
          v9 = v8 / (float)(v8 - v7);
          out->m_vPos.x = (float)((float)(*(p_y - 5) - v5->m_vPos.x) * v9) + v5->m_vPos.x;
          out->m_vPos.y = (float)((float)(*(p_y - 4) - v5->m_vPos.y) * v9) + v5->m_vPos.y;
          out->m_vPos.z = (float)((float)(*(p_y - 3) - v5->m_vPos.z) * v9) + v5->m_vPos.z;
          out->m_cLMCoords.x = (float)((float)(p_y[1] - v5->m_cLMCoords.x) * v9) + v5->m_cLMCoords.x;
          out->m_cLMCoords.y = (float)((float)(p_y[2] - v5->m_cLMCoords.y) * v9) + v5->m_cLMCoords.y;
          out->m_ctCoords.x = (float)((float)(*(p_y - 1) - v5->m_ctCoords.x) * v9) + v5->m_ctCoords.x;
          out->m_ctCoords.y = (float)((float)(*p_y - v5->m_ctCoords.y) * v9) + v5->m_ctCoords.y;
          out[1].m_vPos.x = *(p_y - 5);
          result += 2;
          out += 2;
        }
        else
        {
          ++result;
          out->m_vPos.x = *(p_y - 5);
          ++out;
        }
        out[-1].m_vPos.y = *(p_y - 4);
        out[-1].m_vPos.z = *(p_y - 3);
        out[-1].m_decalIndex = *(int *)(p_y - 2);
        out[-1].m_ctCoords = *(Vector2D *)(p_y - 1);
        out[-1].m_cLMCoords = *(Vector2D *)(p_y + 1);
      }
      v5 = (CDecalVert *)(p_y - 5);
      p_y += 8;
      --v3;
    }
    while ( v3 != 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B61A0
// Name: SHClip_CPlane_Right_
// Source: json
//------------------------------------------------------------------------------
int __fastcall SHClip_CPlane_Right_(CDecalVert *pDecalClipVerts, CDecalVert *out, int vertCount)
{
  int v3; // edi
  int result; // eax
  CDecalVert *v5; // esi
  float *p_y; // ecx
  float v7; // xmm1_4
  float v8; // xmm0_4
  float x; // xmm1_4
  float v10; // xmm0_4

  v3 = vertCount;
  result = 0;
  v5 = &pDecalClipVerts[vertCount - 1];
  if ( vertCount > 0 )
  {
    p_y = &pDecalClipVerts->m_ctCoords.y;
    do
    {
      v7 = *(p_y - 1);
      if ( v7 >= 1.0 )
      {
        x = v5->m_ctCoords.x;
        if ( x < 1.0 )
        {
          v10 = (float)(1.0 - *(p_y - 1)) / (float)(x - *(p_y - 1));
          out->m_vPos.x = (float)((float)(v5->m_vPos.x - *(p_y - 5)) * v10) + *(p_y - 5);
          out->m_vPos.y = (float)((float)(v5->m_vPos.y - *(p_y - 4)) * v10) + *(p_y - 4);
          out->m_vPos.z = (float)((float)(v5->m_vPos.z - *(p_y - 3)) * v10) + *(p_y - 3);
          out->m_cLMCoords.x = (float)((float)(v5->m_cLMCoords.x - p_y[1]) * v10) + p_y[1];
          out->m_cLMCoords.y = (float)((float)(v5->m_cLMCoords.y - p_y[2]) * v10) + p_y[2];
          out->m_ctCoords.x = (float)((float)(v5->m_ctCoords.x - *(p_y - 1)) * v10) + *(p_y - 1);
          out->m_ctCoords.y = (float)((float)(v5->m_ctCoords.y - *p_y) * v10) + *p_y;
          ++out;
          ++result;
        }
      }
      else
      {
        if ( v5->m_ctCoords.x >= 1.0 )
        {
          v8 = (float)(1.0 - v5->m_ctCoords.x) / (float)(v7 - v5->m_ctCoords.x);
          out->m_vPos.x = (float)((float)(*(p_y - 5) - v5->m_vPos.x) * v8) + v5->m_vPos.x;
          out->m_vPos.y = (float)((float)(*(p_y - 4) - v5->m_vPos.y) * v8) + v5->m_vPos.y;
          out->m_vPos.z = (float)((float)(*(p_y - 3) - v5->m_vPos.z) * v8) + v5->m_vPos.z;
          out->m_cLMCoords.x = (float)((float)(p_y[1] - v5->m_cLMCoords.x) * v8) + v5->m_cLMCoords.x;
          out->m_cLMCoords.y = (float)((float)(p_y[2] - v5->m_cLMCoords.y) * v8) + v5->m_cLMCoords.y;
          out->m_ctCoords.x = (float)((float)(*(p_y - 1) - v5->m_ctCoords.x) * v8) + v5->m_ctCoords.x;
          out->m_ctCoords.y = (float)((float)(*p_y - v5->m_ctCoords.y) * v8) + v5->m_ctCoords.y;
          out[1].m_vPos.x = *(p_y - 5);
          result += 2;
          out += 2;
        }
        else
        {
          ++result;
          out->m_vPos.x = *(p_y - 5);
          ++out;
        }
        out[-1].m_vPos.y = *(p_y - 4);
        out[-1].m_vPos.z = *(p_y - 3);
        out[-1].m_decalIndex = *(int *)(p_y - 2);
        out[-1].m_ctCoords = *(Vector2D *)(p_y - 1);
        out[-1].m_cLMCoords = *(Vector2D *)(p_y + 1);
      }
      v5 = (CDecalVert *)(p_y - 5);
      p_y += 8;
      --v3;
    }
    while ( v3 != 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B63F0
// Name: SHClip_CPlane_Bottom_
// Source: json
//------------------------------------------------------------------------------
int __fastcall SHClip_CPlane_Bottom_(CDecalVert *pDecalClipVerts, CDecalVert *out, int vertCount)
{
  int v3; // edi
  int result; // eax
  CDecalVert *v5; // esi
  float *p_y; // ecx
  float v7; // xmm0_4
  float v8; // xmm0_4
  float y; // xmm1_4
  float v10; // xmm0_4

  v3 = vertCount;
  result = 0;
  v5 = &pDecalClipVerts[vertCount - 1];
  if ( vertCount > 0 )
  {
    p_y = &pDecalClipVerts->m_ctCoords.y;
    do
    {
      if ( *p_y <= 0.0 )
      {
        y = v5->m_ctCoords.y;
        if ( y > 0.0 )
        {
          v10 = *p_y / (float)(*p_y - y);
          out->m_vPos.x = (float)((float)(v5->m_vPos.x - *(p_y - 5)) * v10) + *(p_y - 5);
          out->m_vPos.y = (float)((float)(v5->m_vPos.y - *(p_y - 4)) * v10) + *(p_y - 4);
          out->m_vPos.z = (float)((float)(v5->m_vPos.z - *(p_y - 3)) * v10) + *(p_y - 3);
          out->m_cLMCoords.x = (float)((float)(v5->m_cLMCoords.x - p_y[1]) * v10) + p_y[1];
          out->m_cLMCoords.y = (float)((float)(v5->m_cLMCoords.y - p_y[2]) * v10) + p_y[2];
          out->m_ctCoords.x = (float)((float)(v5->m_ctCoords.x - *(p_y - 1)) * v10) + *(p_y - 1);
          out->m_ctCoords.y = (float)((float)(v5->m_ctCoords.y - *p_y) * v10) + *p_y;
          ++out;
          ++result;
        }
      }
      else
      {
        v7 = v5->m_ctCoords.y;
        if ( v7 <= 0.0 )
        {
          v8 = v7 / (float)(v7 - *p_y);
          out->m_vPos.x = (float)((float)(*(p_y - 5) - v5->m_vPos.x) * v8) + v5->m_vPos.x;
          out->m_vPos.y = (float)((float)(*(p_y - 4) - v5->m_vPos.y) * v8) + v5->m_vPos.y;
          out->m_vPos.z = (float)((float)(*(p_y - 3) - v5->m_vPos.z) * v8) + v5->m_vPos.z;
          out->m_cLMCoords.x = (float)((float)(p_y[1] - v5->m_cLMCoords.x) * v8) + v5->m_cLMCoords.x;
          out->m_cLMCoords.y = (float)((float)(p_y[2] - v5->m_cLMCoords.y) * v8) + v5->m_cLMCoords.y;
          out->m_ctCoords.x = (float)((float)(*(p_y - 1) - v5->m_ctCoords.x) * v8) + v5->m_ctCoords.x;
          out->m_ctCoords.y = (float)((float)(*p_y - v5->m_ctCoords.y) * v8) + v5->m_ctCoords.y;
          out[1].m_vPos.x = *(p_y - 5);
          result += 2;
          out += 2;
        }
        else
        {
          ++result;
          out->m_vPos.x = *(p_y - 5);
          ++out;
        }
        out[-1].m_vPos.y = *(p_y - 4);
        out[-1].m_vPos.z = *(p_y - 3);
        out[-1].m_decalIndex = *(int *)(p_y - 2);
        out[-1].m_ctCoords = *(Vector2D *)(p_y - 1);
        out[-1].m_cLMCoords = *(Vector2D *)(p_y + 1);
      }
      v5 = (CDecalVert *)(p_y - 5);
      p_y += 8;
      --v3;
    }
    while ( v3 != 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B6630
// Name: class CDecalVert __near * R_DoDecalSHClip(class CDecalVert __near *,class CDecalVert __near *,struct decal_t __near *,int,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl R_DoDecalSHClip(
        CDecalVert *pInVerts,
        CDecalVert *pOutVerts,
        decal_t *pDecal,
        int nStartVerts,
        const Vector *vecNormal)
{
  CDecalVert *v5; // ebx
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int result; // eax
  int v10; // esi
  int v11; // edi
  unsigned int v12; // edx
  float *p_z; // eax
  float *v14; // eax
  int v15; // edx
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm3_4
  int v20; // edx
  unsigned int v21; // ecx
  float *p_y; // eax
  float *v23; // eax
  int v24; // esi
  float scale[2]; // [esp+8h] [ebp-10h] BYREF
  float offset[2]; // [esp+10h] [ebp-8h] BYREF

  v5 = pOutVerts;
  if ( pOutVerts == nullptr )
    v5 = g_DecalClipVerts;
  v6 = SHClip_CPlane_Top_(pDecalClipVerts: pInVerts, out: g_DecalClipVerts2, vertCount: nStartVerts);
  v7 = SHClip_CPlane_Left_(pDecalClipVerts: g_DecalClipVerts2, out: g_DecalClipVerts, vertCount: v6);
  v8 = SHClip_CPlane_Right_(pDecalClipVerts: g_DecalClipVerts, out: g_DecalClipVerts2, vertCount: v7);
  result = SHClip_CPlane_Bottom_(pDecalClipVerts: g_DecalClipVerts2, out: v5, vertCount: v8);
  v10 = result;
  pDecal->clippedVertCount = result;
  if ( result != 0 )
  {
    v11 = 0;
    if ( result >= 4 )
    {
      v12 = ((unsigned int)(result - 4) >> 2) + 1;
      p_z = &v5[1].m_vPos.z;
      v11 = 4 * v12;
      do
      {
        *(p_z - 10) = (float)(vecNormal->x * 0.1) + *(p_z - 10);
        *(p_z - 9) = (float)(vecNormal->y * 0.1) + *(p_z - 9);
        *(p_z - 8) = (float)(vecNormal->z * 0.1) + *(p_z - 8);
        *(p_z - 2) = (float)(vecNormal->x * 0.1) + *(p_z - 2);
        *(p_z - 1) = (float)(vecNormal->y * 0.1) + *(p_z - 1);
        *p_z = (float)(vecNormal->z * 0.1) + *p_z;
        p_z[6] = (float)(vecNormal->x * 0.1) + p_z[6];
        p_z[7] = (float)(vecNormal->y * 0.1) + p_z[7];
        p_z[8] = (float)(vecNormal->z * 0.1) + p_z[8];
        p_z[14] = (float)(vecNormal->x * 0.1) + p_z[14];
        p_z[15] = (float)(vecNormal->y * 0.1) + p_z[15];
        p_z[16] = (float)(vecNormal->z * 0.1) + p_z[16];
        p_z += 32;
        --v12;
      }
      while ( v12 != 0 );
    }
    if ( v11 < v10 )
    {
      v14 = &v5[v11].m_vPos.z;
      v15 = v10 - v11;
      do
      {
        *(v14 - 2) = (float)(vecNormal->x * 0.1) + *(v14 - 2);
        *(v14 - 1) = (float)(vecNormal->y * 0.1) + *(v14 - 1);
        *v14 = (float)(vecNormal->z * 0.1) + *v14;
        v14 += 8;
        --v15;
      }
      while ( v15 != 0 );
    }
    if ( pDecal->material->InMaterialPage(this: pDecal->material) )
    {
      pDecal->material->GetMaterialOffset(this: pDecal->material, a2: offset);
      pDecal->material->GetMaterialScale(this: pDecal->material, a2: scale);
      v16 = offset[1];
      v17 = offset[0];
      v18 = scale[1];
      v19 = scale[0];
      v20 = 0;
      if ( v10 >= 4 )
      {
        v21 = ((unsigned int)(v10 - 4) >> 2) + 1;
        p_y = &v5->m_ctCoords.y;
        v20 = 4 * v21;
        do
        {
          *(p_y - 1) = (float)(v19 * *(p_y - 1)) + v17;
          *p_y = (float)(v18 * *p_y) + v16;
          p_y[7] = (float)(p_y[7] * v19) + v17;
          p_y[8] = (float)(p_y[8] * v18) + v16;
          p_y[15] = (float)(p_y[15] * v19) + v17;
          p_y[16] = (float)(v18 * p_y[16]) + v16;
          p_y[23] = (float)(p_y[23] * v19) + v17;
          p_y[24] = (float)(p_y[24] * v18) + v16;
          p_y += 32;
          --v21;
        }
        while ( v21 != 0 );
      }
      if ( v20 < v10 )
      {
        v23 = &v5[v20].m_ctCoords.y;
        v24 = v10 - v20;
        do
        {
          *(v23 - 1) = (float)(v19 * *(v23 - 1)) + v17;
          *v23 = (float)(v18 * *v23) + v16;
          v23 += 8;
          --v24;
        }
        while ( v24 != 0 );
      }
    }
    return (int)v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B6940
// Name: class CDecalVert __near * R_DecalVertsClip(class CDecalVert __near *,struct decal_t __near *,struct msurface2_t __near *,class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
CDecalVert *__cdecl R_DecalVertsClip(CDecalVert *pOutVerts, decal_t *pDecal, msurface2_t *surfID, IMaterial *pMaterial)
{
  Vector textureSpaceBasis[3]; // [esp+8h] [ebp-2Ch] BYREF
  float decalWorldScale[2]; // [esp+2Ch] [ebp-8h] BYREF

  R_SetupDecalTextureSpaceBasis(
    pDecal,
    vSurfNormal: &surfID->plane->normal,
    pMaterial,
    textureSpaceBasis,
    decalWorldScale);
  pDecal->dx = (float)((float)(pDecal->position.x * textureSpaceBasis[0].x)
                     + (float)(pDecal->position.y * textureSpaceBasis[0].y))
             + (float)(pDecal->position.z * textureSpaceBasis[0].z);
  pDecal->dy = (float)((float)(pDecal->position.x * textureSpaceBasis[1].x)
                     + (float)(pDecal->position.y * textureSpaceBasis[1].y))
             + (float)(pDecal->position.z * textureSpaceBasis[1].z);
  R_SetupDecalVertsForMSurface(pDecal, surfID, pTextureSpaceBasis: textureSpaceBasis, pVerts: g_DecalClipVerts);
  return (CDecalVert *)R_DoDecalSHClip(
                         pInVerts: g_DecalClipVerts,
                         pOutVerts,
                         pDecal,
                         nStartVerts: HIBYTE(surfID->flags),
                         vecNormal: &surfID->plane->normal);
}

//------------------------------------------------------------------------------
// Address: 0x1025ADB0
// Name: void CrossProduct(class Vector const __near &,class Vector const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CrossProduct(const float *v1, const float *v2, float *cross)
{
  *cross = (float)(v2[2] * v1[1]) - (float)(v1[2] * v2[1]);
  cross[1] = (float)(v1[2] * *v2) - (float)(*v1 * v2[2]);
  cross[2] = (float)(*v1 * v2[1]) - (float)(*v2 * v1[1]);
}

} // namespace engine_xlsp
