// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_tracer.cpp
// Functions: 3
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10267350
// Name: bool Tracer_ComputeVerts(class Vector const __near &,class Vector const __near &,float,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl Tracer_ComputeVerts(const Vector *start, const Vector *delta, float width, Vector *pVerts)
{
  float z; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm3_4
  float x; // xmm4_4
  float y; // xmm5_4
  float v10; // xmm6_4
  float v11; // xmm7_4
  float v12; // xmm2_4
  float v13; // xmm1_4
  float v14; // xmm3_4
  float v15; // xmm2_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm3_4
  float clippedDelta; // [esp+0h] [ebp-24h]
  float clippedStart_4; // [esp+10h] [ebp-14h]
  float clippedStart_8; // [esp+14h] [ebp-10h]
  float sqLength; // [esp+2Ch] [ebp+8h]
  float sqLengtha; // [esp+2Ch] [ebp+8h]

  z = start->z;
  v6 = delta->z;
  LODWORD(v7) = LODWORD(z) ^ _mask__NegFloat_;
  sqLength = COERCE_FLOAT(LODWORD(z) ^ _mask__NegFloat_) - v6;
  if ( COERCE_FLOAT(LODWORD(z) ^ _mask__NegFloat_) <= 0.0 && (float)(v7 - v6) <= 0.0 )
    return 0;
  x = start->x;
  clippedStart_4 = start->y;
  clippedStart_8 = z;
  clippedDelta = delta->x;
  y = delta->y;
  v10 = delta->z;
  if ( v7 <= 0.0 || sqLength <= 0.0 )
  {
    v11 = sqLength - v7;
    if ( (float)(sqLength - v7) < 0.001 && v11 > -0.001 )
      return 0;
    LODWORD(sqLengtha) = COERCE_UNSIGNED_INT(v7 / v11) ^ _mask__NegFloat_;
    v12 = v6 * sqLengtha;
    if ( v7 > 0.0 )
    {
      clippedDelta = delta->x * sqLengtha;
      y = delta->y * sqLengtha;
      v10 = v12;
    }
    else
    {
      x = (float)(delta->x * sqLengtha) + start->x;
      clippedStart_4 = (float)(delta->y * sqLengtha) + start->y;
      clippedStart_8 = v12 + z;
    }
  }
  v13 = (float)(y * clippedStart_8) - (float)(v10 * clippedStart_4);
  v14 = (float)(clippedStart_4 * clippedDelta) - (float)(y * x);
  v15 = (float)(v10 * x) - (float)(clippedStart_8 * clippedDelta);
  if ( (float)((float)((float)(v15 * v15) + (float)(v13 * v13)) + (float)(v14 * v14)) >= 0.001 )
  {
    v16 = (float)(width * 0.5) / fsqrt((float)((float)(v15 * v15) + (float)(v13 * v13)) + (float)(v14 * v14));
    v17 = v13 * v16;
    v18 = v15 * v16;
    pVerts->y = clippedStart_4 - v18;
    v19 = v14 * v16;
    pVerts->x = x - v17;
    pVerts->z = clippedStart_8 - v19;
    pVerts[1].x = x + v17;
    pVerts[1].y = v18 + clippedStart_4;
    pVerts[1].z = v19 + clippedStart_8;
    pVerts[2].x = pVerts->x + clippedDelta;
    pVerts[2].y = pVerts->y + y;
    pVerts[2].z = pVerts->z + v10;
    pVerts[3].x = pVerts[1].x + clippedDelta;
    pVerts[3].y = y + pVerts[1].y;
    pVerts[3].z = v10 + pVerts[1].z;
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102675B0
// Name: void Tracer_Draw(class CMeshBuilder __near *,class Vector const __near &,class Vector const __near &,float,float __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Tracer_Draw(
        CMeshBuilder *pMeshBuilder,
        const Vector *start,
        const Vector *delta,
        float width,
        float *color,
        float startV,
        float endV)
{
  float *v7; // eax
  float *v8; // eax
  float *v9; // eax
  float *v10; // eax
  Vector verts[4]; // [esp+8h] [ebp-40h] BYREF
  float v12; // [esp+38h] [ebp-10h]
  float v13; // [esp+3Ch] [ebp-Ch]
  float v14; // [esp+40h] [ebp-8h]
  float v15; // [esp+44h] [ebp-4h]

  if ( Tracer_ComputeVerts(start, delta, width, pVerts: verts) != 0 )
  {
    *(Vector *)pMeshBuilder->m_VertexBuilder.m_pCurrPosition = verts[0];
    v7 = pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
    *v7 = 0.0;
    v7[1] = startV;
    if ( color != nullptr )
    {
      v12 = (float)(color[2] * 255.0) + 8388608.0;
      v13 = (float)(color[1] * 255.0) + 8388608.0;
      v14 = (float)(*color * 255.0) + 8388608.0;
      v15 = (float)(color[3] * 255.0) + 8388608.0;
      *(_DWORD *)pMeshBuilder->m_VertexBuilder.m_pCurrColor = LOBYTE(v12)
                                                            | ((LOBYTE(v13) | ((LOBYTE(v14) | (LOBYTE(v15) << 8)) << 8)) << 8);
    }
    else
    {
      *(_DWORD *)pMeshBuilder->m_VertexBuilder.m_pCurrColor = -1;
    }
    CVertexBuilder::AdvanceVertex(this: &pMeshBuilder->m_VertexBuilder);
    *(Vector *)pMeshBuilder->m_VertexBuilder.m_pCurrPosition = verts[1];
    v8 = pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
    *v8 = 1.0;
    v8[1] = startV;
    if ( color != nullptr )
    {
      v15 = (float)(color[2] * 255.0) + 8388608.0;
      v14 = (float)(color[1] * 255.0) + 8388608.0;
      v13 = (float)(*color * 255.0) + 8388608.0;
      v12 = (float)(color[3] * 255.0) + 8388608.0;
      *(_DWORD *)pMeshBuilder->m_VertexBuilder.m_pCurrColor = LOBYTE(v15)
                                                            | ((LOBYTE(v14) | ((LOBYTE(v13) | (LOBYTE(v12) << 8)) << 8)) << 8);
    }
    else
    {
      *(_DWORD *)pMeshBuilder->m_VertexBuilder.m_pCurrColor = -1;
    }
    CVertexBuilder::AdvanceVertex(this: &pMeshBuilder->m_VertexBuilder);
    *(Vector *)pMeshBuilder->m_VertexBuilder.m_pCurrPosition = verts[3];
    v9 = pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
    *v9 = 1.0;
    v9[1] = endV;
    if ( color != nullptr )
    {
      v15 = (float)(color[2] * 255.0) + 8388608.0;
      v14 = (float)(color[1] * 255.0) + 8388608.0;
      v13 = (float)(*color * 255.0) + 8388608.0;
      v12 = (float)(color[3] * 255.0) + 8388608.0;
      *(_DWORD *)pMeshBuilder->m_VertexBuilder.m_pCurrColor = LOBYTE(v15)
                                                            | ((LOBYTE(v14) | ((LOBYTE(v13) | (LOBYTE(v12) << 8)) << 8)) << 8);
    }
    else
    {
      *(_DWORD *)pMeshBuilder->m_VertexBuilder.m_pCurrColor = -1;
    }
    CVertexBuilder::AdvanceVertex(this: &pMeshBuilder->m_VertexBuilder);
    *(Vector *)pMeshBuilder->m_VertexBuilder.m_pCurrPosition = verts[2];
    v10 = pMeshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
    *v10 = 0.0;
    v10[1] = endV;
    if ( color != nullptr )
    {
      v15 = (float)(color[2] * 255.0) + 8388608.0;
      v14 = (float)(color[1] * 255.0) + 8388608.0;
      v13 = (float)(*color * 255.0) + 8388608.0;
      v12 = (float)(color[3] * 255.0) + 8388608.0;
      *(_DWORD *)pMeshBuilder->m_VertexBuilder.m_pCurrColor = LOBYTE(v15)
                                                            | ((LOBYTE(v14) | ((LOBYTE(v13) | (LOBYTE(v12) << 8)) << 8)) << 8);
    }
    else
    {
      *(_DWORD *)pMeshBuilder->m_VertexBuilder.m_pCurrColor = -1;
    }
    CVertexBuilder::AdvanceVertex(this: &pMeshBuilder->m_VertexBuilder);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10267970
// Name: void Tracer_Draw(class ParticleDraw __near *,class Vector const __near &,class Vector const __near &,float,float __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Tracer_Draw(
        ParticleDraw *pDraw,
        const Vector *start,
        const Vector *delta,
        float width,
        float *color,
        float startV,
        float endV)
{
  CMeshBuilder *m_pMeshBuilder; // eax

  m_pMeshBuilder = pDraw->m_pMeshBuilder;
  if ( m_pMeshBuilder != nullptr )
    Tracer_Draw(pMeshBuilder: m_pMeshBuilder, start, delta, width, color, startV, endV);
}
