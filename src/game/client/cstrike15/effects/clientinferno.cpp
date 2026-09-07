// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/effects/clientinferno.cpp
// Functions: 40
// ============================================================

#include "game\client\cstrike15\effects\clientinferno.h"

//------------------------------------------------------------------------------
// Address: 0x101CEAD0
// Name: public: virtual void InfernoMaterialsPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall InfernoMaterialsPrecache::CResourcePrecacher::Cache(
        InfernoMaterialsPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "sprites/white",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "sprites/white",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "sprites/white",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "sprites/white",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "sprites/white",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "sprites/white",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101CEB60
// Name: public: virtual class ClientClass __near * C_Inferno::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_Inferno::GetClientClass(C_Inferno *this)
{
  return &__g_C_InfernoClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x101CECE0
// Name: public: virtual class ClientClass __near * C_FireCrackerBlast::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_FireCrackerBlast::GetClientClass(C_FireCrackerBlast *this)
{
  return &__g_C_FireCrackerBlastClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x101CED60
// Name: public: virtual void C_Inferno::GetRenderBounds(class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Inferno::GetRenderBounds(C_Inferno *this, Vector *mins, Vector *maxs)
{
  float *v4; // eax
  float v5; // xmm1_4
  float v6; // xmm2_4
  float *v7; // eax
  float v8; // xmm0_4
  float v9; // xmm2_4

  if ( LODWORD(this->m_drawable[99].m_maxSize) != 0 )
  {
    v4 = (float *)((int (__thiscall *)(C_Inferno *))this->SetRefEHandle)(a1: this);
    v5 = this->m_minBounds.x - v4[1];
    v6 = this->m_minBounds.y - v4[2];
    mins->x = this->m_maxFireHeight - *v4;
    mins->y = v5;
    mins->z = v6;
    v7 = (float *)((int (__thiscall *)(C_Inferno *))this->SetRefEHandle)(a1: this);
    v8 = this->m_minBounds.z - *v7;
    v9 = this->m_maxBounds.y - v7[2];
    maxs->y = this->m_maxBounds.x - v7[1];
    maxs->z = v9;
    maxs->x = v8;
  }
  else
  {
    mins->x = 0.0;
    mins->y = 0.0;
    mins->z = 0.0;
    maxs->y = 0.0;
    maxs->z = 0.0;
    maxs->x = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CEE20
// Name: public: virtual void C_Inferno::GetRenderBoundsWorldspace(class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Inferno::GetRenderBoundsWorldspace(C_Inferno *this, Vector *mins, Vector *maxs)
{
  if ( LODWORD(this->m_drawable[99].m_maxSize) != 0 )
  {
    *mins = *(Vector *)&this->m_maxFireHeight;
    *maxs = *(Vector *)&this->m_minBounds.z;
  }
  else
  {
    mins->x = 0.0;
    mins->y = 0.0;
    mins->z = 0.0;
    maxs->x = 0.0;
    maxs->y = 0.0;
    maxs->z = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CEE90
// Name: private: void C_Inferno::RecomputeBounds(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Inferno::RecomputeBounds(C_Inferno *this)
{
  int v1; // edx
  float *p_y; // eax
  float m_maxFireHalfWidth; // xmm1_4
  float v4; // xmm0_4
  float v5; // xmm0_4
  float v6; // xmm0_4
  float v7; // xmm0_4
  float v8; // xmm0_4
  float v9; // xmm0_4

  this->m_minBounds.x = 999999.88;
  this->m_minBounds.y = 999999.88;
  this->m_minBounds.z = 999999.88;
  v1 = 0;
  this->m_maxBounds.x = -999999.88;
  this->m_maxBounds.y = -999999.88;
  this->m_maxBounds.z = -999999.88;
  if ( this->m_drawableCount > 0 )
  {
    p_y = &this->m_drawable[0].m_pos.y;
    do
    {
      if ( *((_DWORD *)p_y + 9) != 3 )
      {
        m_maxFireHalfWidth = this->m_maxFireHalfWidth;
        v4 = *(p_y - 1) - m_maxFireHalfWidth;
        if ( this->m_minBounds.x > v4 )
          this->m_minBounds.x = v4;
        v5 = *(p_y - 1) + m_maxFireHalfWidth;
        if ( v5 > this->m_maxBounds.x )
          this->m_maxBounds.x = v5;
        v6 = *p_y - m_maxFireHalfWidth;
        if ( this->m_minBounds.y > v6 )
          this->m_minBounds.y = v6;
        v7 = *p_y + m_maxFireHalfWidth;
        if ( v7 > this->m_maxBounds.y )
          this->m_maxBounds.y = v7;
        v8 = p_y[1];
        if ( this->m_minBounds.z > v8 )
          this->m_minBounds.z = v8;
        v9 = this->m_maxFireHeight + p_y[1];
        if ( v9 > this->m_maxBounds.z )
          this->m_maxBounds.z = v9;
      }
      ++v1;
      p_y += 14;
    }
    while ( v1 < this->m_drawableCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CEFB0
// Name: private: struct C_Inferno::Drawable __near * C_Inferno::GetDrawable(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
C_Inferno::Drawable *__thiscall C_Inferno::GetDrawable(C_Inferno *this, const Vector *pos)
{
  int m_drawableCount; // edi
  int v3; // eax
  float x; // xmm2_4
  float *i; // edx
  C_Inferno::Drawable *result; // eax

  m_drawableCount = this->m_drawableCount;
  v3 = 0;
  if ( m_drawableCount <= 0 )
    return nullptr;
  x = pos->x;
  for ( i = &this->m_drawable[0].m_pos.z;
        fabs(*(i - 2) - x) > 12.0 || fabs(*(i - 1) - pos->y) > 12.0 || fabs(*i - pos->z) > 12.0;
        i += 14 )
  {
    if ( ++v3 >= m_drawableCount )
      return nullptr;
  }
  result = &this->m_drawable[v3];
  result->m_pos.x = x;
  result->m_pos.y = pos->y;
  result->m_pos.z = pos->z;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101CF050
// Name: private: void C_Inferno::SynchronizeDrawables(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Inferno::SynchronizeDrawables(C_Inferno *this)
{
  int v2; // eax
  C_Inferno::FireState *p_m_state; // ecx
  const Vector *v4; // eax
  bool v5; // cc
  Vector *m_BurnNormal; // esi
  unsigned int *m_fireYDelta; // ebx
  int v8; // eax
  __m128i v9; // xmm5
  __m128i v10; // xmm6
  float z; // edx
  __int64 v12; // xmm0_8
  float v13; // xmm4_4
  float v14; // xmm5_4
  float v15; // xmm6_4
  C_Inferno::Drawable *Drawable; // eax
  int m_drawableCount; // eax
  C_Inferno::Drawable *v18; // esi
  double v19; // st7
  int v20; // eax
  int v21; // edx
  int v22; // ecx
  float *p_z; // eax
  int v24; // ecx
  float *p_m_stateTimestamp; // eax
  float fireNormal_8; // [esp+40h] [ebp-28h]
  __int64 vInfernoOrigin; // [esp+44h] [ebp-24h]
  float vInfernoOrigin_8; // [esp+4Ch] [ebp-1Ch]
  Vector firePos; // [esp+50h] [ebp-18h] BYREF
  Vector *v30; // [esp+5Ch] [ebp-Ch]
  int i; // [esp+60h] [ebp-8h]
  int *v32; // [esp+64h] [ebp-4h]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "C_Inferno::SynchronizeDrawables",
    a3: 0,
    a4: "Magic",
    a5: false,
    a6: 4);
  v2 = 0;
  if ( this->m_drawableCount > 0 )
  {
    p_m_state = &this->m_drawable[0].m_state;
    do
    {
      if ( *p_m_state == BURNING )
        *p_m_state = UNKNOWN;
      ++v2;
      p_m_state += 14;
    }
    while ( v2 < this->m_drawableCount );
  }
  v4 = this->GetAbsOrigin(this);
  v5 = this->m_fireCount <= 0;
  vInfernoOrigin = *(_QWORD *)&v4->x;
  vInfernoOrigin_8 = v4->z;
  i = 0;
  if ( !v5 )
  {
    m_BurnNormal = this->m_BurnNormal;
    m_fireYDelta = (unsigned int *)this->m_fireYDelta;
    v30 = this->m_BurnNormal;
    v32 = this->m_fireYDelta;
    do
    {
      v8 = *(m_fireYDelta - 100);
      if ( v8 != 0 || *m_fireYDelta != 0 )
      {
        v9 = _mm_cvtsi32_si128(*m_fireYDelta);
        v10 = _mm_cvtsi32_si128(m_fireYDelta[100]);
        z = m_BurnNormal->z;
        *(_QWORD *)&firePos.x = vInfernoOrigin;
        v12 = *(_QWORD *)&m_BurnNormal->x;
        v13 = (float)v8 + *(float *)&vInfernoOrigin;
        v14 = _mm_cvtepi32_ps(v9).m128_f32[0] + *((float *)&vInfernoOrigin + 1);
        v15 = _mm_cvtepi32_ps(v10).m128_f32[0] + vInfernoOrigin_8;
        firePos.x = v13;
        firePos.y = v14;
        firePos.z = v15;
        fireNormal_8 = z;
        Drawable = C_Inferno::GetDrawable(this, pos: &firePos);
        if ( Drawable != nullptr )
        {
          if ( Drawable->m_state == UNKNOWN )
            Drawable->m_state = BURNING;
        }
        else
        {
          m_drawableCount = this->m_drawableCount;
          if ( m_drawableCount < 100 )
          {
            v18 = &this->m_drawable[m_drawableCount];
            v18->m_state = STARTING;
            v19 = *(float *)gpGlobals.m_Index;
            v18->m_pos.x = v13;
            v18->m_stateTimestamp = v19;
            v18->m_pos.y = v14;
            v18->m_pos.z = v15;
            *(_QWORD *)&v18->m_normal.x = v12;
            v18->m_normal.z = fireNormal_8;
            v18->m_frame = 0;
            v18->m_framerate = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                 a1: random,
                                 a2: 1025758986,
                                 a3: 1031127695);
            v20 = random->RandomInt(this: random, a2: 0, a3: 100);
            v18->m_size = 0.0;
            v18->m_mirror = v20 < 50;
            v18->m_maxSize = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                               a1: random,
                               a2: 1116471296,
                               a3: 1119092736);
            v21 = this->m_drawableCount;
            v22 = 0;
            if ( v21 <= 0 )
            {
LABEL_20:
              v18->m_dlightIndex = this->index + v21 + 0x10000000;
            }
            else
            {
              p_z = &this->m_drawable[0].m_pos.z;
              while ( 1 )
              {
                if ( *((_DWORD *)p_z + 8) != 3 && *((int *)p_z + 7) > 0 )
                {
                  m_fireYDelta = (unsigned int *)v32;
                  if ( (float)(InfernoDlightSpacing.m_pParent->m_Value.m_fValue
                             * InfernoDlightSpacing.m_pParent->m_Value.m_fValue) > (float)((float)((float)((float)(*(p_z - 1) - firePos.y) * (float)(*(p_z - 1) - firePos.y))
                                                                                                 + (float)((float)(*(p_z - 2) - firePos.x) * (float)(*(p_z - 2) - firePos.x)))
                                                                                         + (float)((float)(*p_z - firePos.z)
                                                                                                 * (float)(*p_z - firePos.z))) )
                    break;
                }
                ++v22;
                p_z += 14;
                if ( v22 >= v21 )
                  goto LABEL_20;
              }
              v18->m_dlightIndex = 0;
            }
            C_Inferno::RecomputeBounds(this);
            if ( this->m_hRender != 0xFFFF )
              g_pClientLeafSystem->RenderableChanged(this: g_pClientLeafSystem, a2: this->m_hRender);
            ++this->m_drawableCount;
            m_BurnNormal = v30;
          }
        }
      }
      ++m_fireYDelta;
      ++m_BurnNormal;
      ++i;
      v32 = (int *)m_fireYDelta;
      v30 = m_BurnNormal;
    }
    while ( i < this->m_fireCount );
  }
  v24 = 0;
  if ( this->m_drawableCount > 0 )
  {
    p_m_stateTimestamp = &this->m_drawable[0].m_stateTimestamp;
    do
    {
      if ( *((_DWORD *)p_m_stateTimestamp - 1) == 4 )
      {
        *((_DWORD *)p_m_stateTimestamp - 1) = 2;
        *p_m_stateTimestamp = *(float *)gpGlobals.m_Index;
      }
      ++v24;
      p_m_stateTimestamp += 14;
    }
    while ( v24 < this->m_drawableCount );
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x101CF380
// Name: private: void C_Inferno::DrawFire(struct C_Inferno::Drawable __near *,class IMesh __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge C_Inferno::DrawFire(C_Inferno *this@<ecx>, int a2@<edi>, C_Inferno::Drawable *fire, IMesh *mesh)
{
  const Vector *v5; // eax
  Vector *p_top; // eax
  __int64 v7; // xmm0_8
  float z; // eax
  float x; // xmm1_4
  float v10; // xmm6_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float *m_pCurrPosition; // eax
  float v14; // xmm4_4
  float v15; // xmm5_4
  float *v16; // eax
  float *v17; // eax
  float v18; // xmm1_4
  float v19; // xmm2_4
  float *v20; // eax
  float *v21; // eax
  float v22; // xmm1_4
  float v23; // xmm2_4
  float *v24; // eax
  float v25; // xmm3_4
  float *v26; // eax
  float v27; // xmm1_4
  float v28; // xmm2_4
  float *v29; // eax
  int m_nVertexCount; // eax
  void (__thiscall *Draw_2)(IMesh *, int, int); // edx
  int m_dlightIndex; // eax
  float m_fValue; // xmm5_4
  float v34; // xmm4_4
  float v35; // xmm0_4
  float v36; // xmm2_4
  float v37; // xmm0_4
  float v38; // xmm0_4
  dlight_t *(__thiscall *CL_AllocElight)(IVEfx *, int); // eax
  int v40; // edi
  int v41; // [esp+30h] [ebp-214h]
  CMeshBuilder meshBuilder; // [esp+40h] [ebp-204h] BYREF
  __int64 v43; // [esp+228h] [ebp-1Ch]
  float v44; // [esp+230h] [ebp-14h]
  Vector top; // [esp+234h] [ebp-10h] BYREF
  float v46; // [esp+240h] [ebp-4h]
  float scale; // [esp+24Ch] [ebp+8h]
  float scalea; // [esp+24Ch] [ebp+8h]

  scale = fire->m_size * 0.33333334;
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  meshBuilder.m_pMesh = mesh;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_QUADS;
  ((void (__thiscall *)(IMesh *, int, int))mesh->SetPrimitiveType)(a1: mesh, a2: 2, a3: a2);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 6, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &mesh->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: mesh, nMaxVertexCount: 4, desc: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  if ( fire->m_mirror )
  {
    v5 = CurrentViewRight();
    top.x = -v5->x;
    top.y = -v5->y;
    top.z = -v5->z;
    p_top = &top;
  }
  else
  {
    p_top = CurrentViewRight();
  }
  v7 = *(_QWORD *)&p_top->x;
  z = p_top->z;
  x = fire->m_pos.x;
  v10 = scale;
  v43 = v7;
  v11 = x + (float)(fire->m_size * 0.0);
  v12 = fire->m_pos.y + (float)(fire->m_size * 0.0);
  *(float *)&v7 = fire->m_pos.z + fire->m_size;
  v44 = z;
  m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  v14 = *((float *)&v43 + 1) * scale;
  scalea = *(float *)&v43 * scale;
  v15 = v44 * v10;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = scalea + v11;
  v46 = v15;
  m_pCurrPosition[1] = v14 + v12;
  m_pCurrPosition[2] = v15 + *(float *)&v7;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -6908266;
  v16 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  LODWORD(top.z) = v7;
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
  top.x = v11;
  top.y = v12;
  v16[1] = 0.0;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  v17 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  v18 = fire->m_pos.y + v14;
  v19 = fire->m_pos.z + v46;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = fire->m_pos.x + scalea;
  v17[1] = v18;
  v17[2] = v19;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -6908266;
  v20 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
  v20[1] = 1.0;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  v21 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  v22 = fire->m_pos.y - v14;
  v23 = fire->m_pos.z - v46;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = fire->m_pos.x - scalea;
  v21[1] = v22;
  v21[2] = v23;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -6908266;
  v24 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
  v24[1] = 1.0;
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  v25 = v46;
  v26 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  v27 = top.y - v14;
  v28 = top.z;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = top.x - scalea;
  v26[1] = v27;
  v26[2] = v28 - v25;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -6908266;
  v29 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
  v29[1] = 0.0;
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
  Draw_2 = mesh->Draw_2;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  meshBuilder.m_pMesh = nullptr;
  Draw_2(this: mesh, a2: -1, a3: 0);
  m_dlightIndex = fire->m_dlightIndex;
  if ( m_dlightIndex > 0 )
  {
    m_fValue = InfernoDlights.m_pParent->m_Value.m_fValue;
    if ( m_fValue >= 1.0 )
    {
      v34 = *(float *)gpGlobals.m_Index;
      v35 = *(float *)gpGlobals.m_Index - lastRealTime;
      if ( v35 <= 2.0 && v35 > 0.0 )
      {
        v36 = 1.0 / v35;
        v37 = 1.0 / v35;
        if ( AverageFPS >= 0.0 )
        {
          v37 = (float)(v36 * 0.1) + (float)(AverageFPS * 0.89999998);
        }
        else
        {
          high = (int)v36;
          low = (int)v36;
        }
        AverageFPS = v37;
        if ( (int)v36 < low )
          low = (int)v36;
        if ( (int)v36 > high )
          high = (int)v36;
        if ( m_fValue > (float)(int)v37 )
        {
          fire->m_dlightIndex = 0;
          lastRealTime = *(float *)gpGlobals.m_Index;
          CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
          return;
        }
      }
      v38 = (float)(fire->m_size / fire->m_maxSize) * 1.5;
      v41 = m_dlightIndex;
      CL_AllocElight = effects->CL_AllocElight;
      lastRealTime = v34;
      v40 = (int)CL_AllocElight(this: effects, a2: v41);
      *(float *)(v40 + 4) = fire->m_pos.x;
      *(float *)(v40 + 8) = fire->m_pos.y;
      *(float *)(v40 + 12) = fire->m_pos.z;
      *(float *)(v40 + 12) = (float)(v38 * 16.0) + *(float *)(v40 + 12);
      *(_WORD *)(v40 + 20) = 25854;
      *(_BYTE *)(v40 + 22) = 10;
      *(float *)(v40 + 16) = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                               a1: random,
                               a2: 1112014848,
                               a3: 1124270080)
                           * v38;
      *(float *)(v40 + 24) = *(float *)(gpGlobals.m_Index + 12) + 0.1;
      *(_BYTE *)(v40 + 23) = 5;
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

//------------------------------------------------------------------------------
// Address: 0x101CF910
// Name: public: virtual int C_Inferno::DrawModel(int,struct RenderableInstance_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge C_Inferno::DrawModel@<eax>(
        C_Inferno *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        int flags,
        const RenderableInstance_t *instance)
{
  int m_nValue; // eax
  IVModelInfoClient_vtbl *v7; // esi
  int v8; // eax
  int v9; // eax
  int v10; // eax
  CEngineSprite *v11; // edi
  int v12; // ebx
  int v13; // eax
  IMatRenderContext *m_pObject; // esi
  int v15; // ebx
  C_Inferno::Drawable *p_m_lastFireCount; // esi
  CMatRenderContextPtr pRenderContext; // [esp+0h] [ebp-Ch]
  IMesh *pMesh; // [esp+4h] [ebp-8h]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "C_Inferno::DrawModel",
    a3: 0,
    a4: "DeadRun",
    a5: false,
    a6: 4);
  if ( InfernoFire.m_pParent != nullptr )
    m_nValue = InfernoFire.m_pParent->m_Value.m_nValue;
  else
    LOBYTE(m_nValue) = 0;
  if ( (m_nValue & 1) != 0 )
  {
    v7 = modelinfo->__vftable;
    v8 = ((int (__thiscall *)(IVModelInfoClient *, const char *, int))modelinfo->GetModelIndex)(
           a1: modelinfo,
           a2: "sprites/fire1.vmt",
           a3: a4);
    v9 = (int)v7->GetModel(this: modelinfo, a2: v8);
    if ( v9 != 0 )
    {
      v10 = ((int (__thiscall *)(IVModelInfoClient *, int, int))modelinfo->GetModelExtraData)(a1: modelinfo, a2: v9, a3);
      v11 = (CEngineSprite *)v10;
      if ( v10 != 0 )
      {
        v12 = *(_DWORD *)(v10 + 36);
        if ( v12 != 0 )
        {
          v13 = ((int (__thiscall *)(IMaterialSystem *, int))materials->GetRenderContext)(a1: materials, a2);
          m_pObject = (IMatRenderContext *)v13;
          pRenderContext.m_pObject = (IMatRenderContext *)v13;
          if ( v13 != 0 )
            (*(void (__thiscall **)(int))(*(_DWORD *)v13 + 8))(a1: v13);
          ((void (__thiscall *)(IMatRenderContext *, int))m_pObject->Bind)(a1: m_pObject, a2: v12);
          pMesh = m_pObject->GetDynamicMesh(this: m_pObject, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
          if ( pMesh != nullptr )
          {
            v15 = 0;
            if ( SLODWORD(this->m_drawable[99].m_maxSize) > 0 )
            {
              p_m_lastFireCount = (C_Inferno::Drawable *)&this->m_lastFireCount;
              do
              {
                CEngineSprite::SetFrame(
                  this: v11,
                  nRenderMode: kRenderTransAdd,
                  nFrame: (int)(float)(*(float *)gpGlobals.m_Index / p_m_lastFireCount->m_framerate) % v11->m_numFrames);
                C_Inferno::DrawFire(
                  this: (C_Inferno *)((char *)this - 4),
                  a2: (int)v11,
                  fire: p_m_lastFireCount,
                  mesh: pMesh);
                ++v15;
                ++p_m_lastFireCount;
              }
              while ( v15 < SLODWORD(this->m_drawable[99].m_maxSize) );
              m_pObject = pRenderContext.m_pObject;
            }
          }
          m_pObject->EndRender(this: m_pObject);
          m_pObject->Release(this: m_pObject);
        }
      }
    }
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101CFAA0
// Name: public: virtual C_Inferno::~C_Inferno(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Inferno::~C_Inferno(C_Inferno *this)
{
  CNewParticleEffect *m_pObject; // ecx
  CNewParticleEffect *v3; // eax

  m_pObject = this->m_burnParticleEffect.m_pObject;
  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_Inferno_vtbl *)&C_Inferno::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_Inferno::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_Inferno::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_Inferno::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_Inferno::`vftable';
  if ( m_pObject != nullptr )
    CNewParticleEffect::StopEmission(
      this: m_pObject,
      bInfiniteOnly: false,
      bRemoveAllParticles: false,
      bWakeOnStop: false,
      bPlayEndCap: false);
  v3 = this->m_burnParticleEffect.m_pObject;
  if ( v3 != nullptr )
  {
    CUtlIntrusiveDList<CUtlReference<CNewParticleEffect>>::RemoveNode(
      this: (CUtlIntrusiveDList<CUtlReference<CSheet> > *)&v3->m_References,
      which: (CUtlReference<CSheet> *)&this->m_burnParticleEffect);
    this->m_burnParticleEffect.m_pObject = nullptr;
  }
  C_BaseEntity::~C_BaseEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x101CFB10
// Name: public: C_Inferno::C_Inferno(void)
// Source: json
//------------------------------------------------------------------------------
C_Inferno *__thiscall C_Inferno::C_Inferno(C_Inferno *this)
{
  CNewParticleEffect *m_pObject; // eax

  C_BaseEntity::C_BaseEntity(this);
  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_Inferno_vtbl *)&C_Inferno::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_Inferno::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_Inferno::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_Inferno::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_Inferno::`vftable';
  this->m_burnParticleEffect.m_pPrev = nullptr;
  this->m_burnParticleEffect.m_pNext = nullptr;
  this->m_burnParticleEffect.m_pObject = nullptr;
  this->m_maxFireHalfWidth = 30.0;
  this->m_maxFireHeight = 80.0;
  m_pObject = this->m_burnParticleEffect.m_pObject;
  if ( m_pObject != nullptr )
  {
    CUtlIntrusiveDList<CUtlReference<CNewParticleEffect>>::RemoveNode(
      this: (CUtlIntrusiveDList<CUtlReference<CSheet> > *)&m_pObject->m_References,
      which: (CUtlReference<CSheet> *)&this->m_burnParticleEffect);
    this->m_burnParticleEffect.m_pObject = nullptr;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101CFBD0
// Name: public: virtual void C_Inferno::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Inferno::Spawn(C_Inferno *this)
{
  CNewParticleEffect *m_pObject; // eax

  C_BaseAnimating::ShutdownBoneSetupThreadPool((vgui::PropertyPage *)this);
  this->m_fireCount = 0;
  this->m_lastFireCount = 0;
  this->m_drawableCount = 0;
  m_pObject = this->m_burnParticleEffect.m_pObject;
  if ( m_pObject != nullptr )
  {
    CUtlIntrusiveDList<CUtlReference<CNewParticleEffect>>::RemoveNode(
      this: (CUtlIntrusiveDList<CUtlReference<CSheet> > *)&m_pObject->m_References,
      which: (CUtlReference<CSheet> *)&this->m_burnParticleEffect);
    this->m_burnParticleEffect.m_pObject = nullptr;
  }
  this->m_minBounds.x = 0.0;
  this->m_minBounds.y = 0.0;
  this->m_minBounds.z = 0.0;
  this->m_maxBounds.x = 0.0;
  this->m_maxBounds.y = 0.0;
  this->m_maxBounds.z = 0.0;
  ((void (__thiscall *)(C_Inferno *, int))this->SetNextClientThink)(a1: this, a2: -996040704);
}

//------------------------------------------------------------------------------
// Address: 0x101CFC60
// Name: public: virtual void C_Inferno::OnNewParticleEffect(char const __near *,class CNewParticleEffect __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Inferno::OnNewParticleEffect(
        C_Inferno *this,
        const char *pszParticleName,
        CNewParticleEffect *pNewParticleEffect)
{
  const char *v4; // eax
  CNewParticleEffect *m_pObject; // eax
  CUtlReference<CSheet> *p_m_burnParticleEffect; // esi
  CUtlReference<CNewParticleEffect> *m_pHead; // eax

  v4 = this->GetParticleEffectName(this);
  if ( _V_stricmp(s1: pszParticleName, s2: v4) == 0 )
  {
    m_pObject = this->m_burnParticleEffect.m_pObject;
    p_m_burnParticleEffect = (CUtlReference<CSheet> *)&this->m_burnParticleEffect;
    if ( m_pObject != pNewParticleEffect )
    {
      if ( m_pObject != nullptr )
      {
        CUtlIntrusiveDList<CUtlReference<CNewParticleEffect>>::RemoveNode(
          this: (CUtlIntrusiveDList<CUtlReference<CSheet> > *)&m_pObject->m_References,
          which: p_m_burnParticleEffect);
        p_m_burnParticleEffect->m_pObject = nullptr;
      }
      p_m_burnParticleEffect->m_pObject = (CSheet *)pNewParticleEffect;
      if ( pNewParticleEffect != nullptr )
      {
        p_m_burnParticleEffect->m_pNext = (CUtlReference<CSheet> *)pNewParticleEffect->m_References.m_pHead;
        m_pHead = pNewParticleEffect->m_References.m_pHead;
        if ( m_pHead != nullptr )
          m_pHead->m_pPrev = (CUtlReference<CNewParticleEffect> *)p_m_burnParticleEffect;
        p_m_burnParticleEffect->m_pPrev = nullptr;
        pNewParticleEffect->m_References.m_pHead = (CUtlReference<CNewParticleEffect> *)p_m_burnParticleEffect;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CFCE0
// Name: public: virtual void C_Inferno::OnParticleEffectDeleted(class CNewParticleEffect __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Inferno::OnParticleEffectDeleted(C_Inferno *this, CNewParticleEffect *pParticleEffect)
{
  CNewParticleEffect *m_pObject; // eax
  CUtlReference<CNewParticleEffect> *p_m_burnParticleEffect; // esi

  if ( pParticleEffect == this->m_burnParticleEffect.m_pObject )
  {
    m_pObject = this->m_burnParticleEffect.m_pObject;
    p_m_burnParticleEffect = &this->m_burnParticleEffect;
    if ( m_pObject != nullptr )
    {
      CUtlIntrusiveDList<CUtlReference<CNewParticleEffect>>::RemoveNode(
        this: (CUtlIntrusiveDList<CUtlReference<CSheet> > *)&m_pObject->m_References,
        which: (CUtlReference<CSheet> *)&this->m_burnParticleEffect);
      p_m_burnParticleEffect->m_pObject = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CFD20
// Name: private: void C_Inferno::UpdateParticles(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Inferno::UpdateParticles(C_Inferno *this)
{
  int m_nValue; // eax
  IMDLCache *v3; // esi
  const char *v4; // eax
  CNewParticleEffect *v5; // eax
  CUtlReference<CSheet> *p_m_burnParticleEffect; // ebx
  CNewParticleEffect *v7; // edi
  CUtlIntrusiveDList<CUtlReference<CSheet> > *p_m_References; // eax
  CUtlReference<CNewParticleEffect> *m_pHead; // eax
  int v10; // esi
  float *p_y; // edi
  dlight_t *v12; // esi
  double v13; // st7
  CNewParticleEffect *m_pObject; // esi
  const Vector *v15; // eax
  CNewParticleEffect *v16; // ebx
  int i; // [esp+24h] [ebp-4h]
  Vector v18; // 0:^C.12

  if ( this->m_drawableCount > 0
    && (InfernoFire.m_pParent == nullptr ? (LOBYTE(m_nValue) = 0) : (m_nValue = InfernoFire.m_pParent->m_Value.m_nValue),
        (m_nValue & 2) != 0) )
  {
    if ( this->m_burnParticleEffect.m_pObject != nullptr )
    {
      v10 = 0;
      i = 0;
      p_y = &this->m_drawable[0].m_pos.y;
      do
      {
        if ( v10 >= 64 )
          break;
        CNewParticleEffect::SetControlPointEntity(
          this: this->m_burnParticleEffect.m_pObject,
          nWhichPoint: v10,
          pEntity: nullptr);
        CNewParticleEffect::SetControlPoint(
          this: this->m_burnParticleEffect.m_pObject,
          nWhichPoint: v10,
          v: (const Vector *)(p_y - 1));
        if ( v10 % 2 == 0 )
        {
          v12 = effects->CL_AllocElight(this: effects, a2: *((_DWORD *)p_y + 8));
          v12->origin.x = *(p_y - 1);
          v12->origin.y = *p_y;
          v12->origin.z = p_y[1];
          v12->origin.z = v12->origin.z + 64.0;
          *(_WORD *)&v12->color.r = 25854;
          v12->color.b = 10;
          v12->radius = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                          a1: random,
                          a2: 1106247680,
                          a3: 1114636288);
          v13 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                  a1: random,
                  a2: 1008981770,
                  a3: 1020054733)
              + *(float *)(gpGlobals.m_Index + 12);
          v12->color.exponent = 5;
          v12->die = v13;
          v10 = i;
        }
        ++v10;
        p_y += 14;
        i = v10;
      }
      while ( v10 < this->m_drawableCount );
      ((void (__thiscall *)(C_Inferno *, int))this->SetNextClientThink)(a1: this, a2: 1036831949);
      *((_BYTE *)this->m_burnParticleEffect.m_pObject + 944) |= 8u;
      m_pObject = this->m_burnParticleEffect.m_pObject;
      v15 = this->GetAbsOrigin(this);
      m_pObject->m_vSortOrigin.x = v15->x;
      m_pObject->m_vSortOrigin.y = v15->y;
      m_pObject->m_vSortOrigin.z = v15->z;
    }
    else
    {
      v3 = mdlcache;
      mdlcache->BeginLock(this: mdlcache);
      v18 = vec3_origin;
      v4 = this->GetParticleEffectName(this);
      v5 = CParticleProperty::Create(
             this: &this->m_Particles,
             pszParticleName: v4,
             iAttachType: PATTACH_ABSORIGIN_FOLLOW,
             iAttachmentPoint: -1,
             vecOriginOffset: v18,
             matOffset: nullptr);
      p_m_burnParticleEffect = (CUtlReference<CSheet> *)&this->m_burnParticleEffect;
      v7 = v5;
      p_m_References = &p_m_burnParticleEffect->m_pObject->m_References;
      if ( p_m_References != (CUtlIntrusiveDList<CUtlReference<CSheet> > *)v7 )
      {
        if ( p_m_References != nullptr )
        {
          CUtlIntrusiveDList<CUtlReference<CNewParticleEffect>>::RemoveNode(
            this: p_m_References + 232,
            which: p_m_burnParticleEffect);
          p_m_burnParticleEffect->m_pObject = nullptr;
        }
        p_m_burnParticleEffect->m_pObject = (CSheet *)v7;
        if ( v7 != nullptr )
        {
          p_m_burnParticleEffect->m_pNext = (CUtlReference<CSheet> *)v7->m_References.m_pHead;
          m_pHead = v7->m_References.m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = (CUtlReference<CNewParticleEffect> *)p_m_burnParticleEffect;
          p_m_burnParticleEffect->m_pPrev = nullptr;
          v7->m_References.m_pHead = (CUtlReference<CNewParticleEffect> *)p_m_burnParticleEffect;
        }
      }
      v3->EndLock(this: v3);
    }
  }
  else
  {
    v16 = this->m_burnParticleEffect.m_pObject;
    if ( v16 != nullptr )
      CNewParticleEffect::StopEmission(
        this: v16,
        bInfiniteOnly: false,
        bRemoveAllParticles: false,
        bWakeOnStop: false,
        bPlayEndCap: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CFFE0
// Name: public: virtual void C_Inferno::ClientThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Inferno::ClientThink(C_Inferno *this)
{
  unsigned int v2; // ecx
  IHandleEntity *m_pEntity; // eax
  bool v4; // cc
  C_Inferno::FireState *p_m_state; // esi
  int v6; // eax
  float v7; // xmm0_4
  int m_flOldAnimTime_high; // eax
  float v9; // xmm1_4
  float v10; // xmm0_4
  int i; // [esp+8h] [ebp-8h]
  bool bIsAttachedToMovingObject; // [esp+Eh] [ebp-2h]
  bool bDidRecomputeBounds; // [esp+Fh] [ebp-1h]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "C_Inferno::ClientThink",
    a3: 0,
    a4: "Magic",
    a5: false,
    a6: 4);
  v2 = *(_DWORD *)&this->m_iParentAttachment;
  if ( v2 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v2].m_SerialNumber != HIWORD(v2) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v2].m_pEntity;
  bIsAttachedToMovingObject = m_pEntity != nullptr;
  C_Inferno::SynchronizeDrawables(this: (C_Inferno *)((char *)this - 12));
  v4 = SLODWORD(this->m_drawable[99].m_stateTimestamp) <= 0;
  this->m_fireUniqueID[99] = this->m_fireUniqueID[97];
  bDidRecomputeBounds = false;
  i = 0;
  if ( !v4 )
  {
    p_m_state = &this->m_drawable[0].m_state;
    do
    {
      v6 = *((_DWORD *)p_m_state - 3);
      if ( v6 != 0 )
      {
        if ( v6 == 2 )
        {
          v7 = *(float *)p_m_state
             - (float)((float)(*(float *)gpGlobals.m_Index - *((float *)p_m_state - 2))
                     * (float)(*(float *)p_m_state * 0.5));
          *((float *)p_m_state - 1) = v7;
          if ( v7 <= 0.0 )
          {
            *((_DWORD *)p_m_state - 3) = 3;
            *(p_m_state - 2) = *(C_Inferno::FireState *)gpGlobals.m_Index;
            C_Inferno::RecomputeBounds(this: (C_Inferno *)((char *)this - 12));
            m_flOldAnimTime_high = HIWORD(this->m_flOldAnimTime);
            bDidRecomputeBounds = true;
            if ( (_WORD)m_flOldAnimTime_high != 0xFFFF )
              g_pClientLeafSystem->RenderableChanged(this: g_pClientLeafSystem, a2: m_flOldAnimTime_high);
          }
        }
      }
      else
      {
        v9 = *(float *)p_m_state;
        v10 = (float)(*(float *)gpGlobals.m_Index - *((float *)p_m_state - 2)) * (float)(*(float *)p_m_state * 0.5);
        *((float *)p_m_state - 1) = v10;
        if ( v10 > v9 )
        {
          *((float *)p_m_state - 1) = v9;
          *((_DWORD *)p_m_state - 3) = 1;
          *(p_m_state - 2) = *(C_Inferno::FireState *)gpGlobals.m_Index;
        }
      }
      p_m_state += 14;
      ++i;
    }
    while ( i < SLODWORD(this->m_drawable[99].m_stateTimestamp) );
  }
  if ( bIsAttachedToMovingObject && !bDidRecomputeBounds )
    C_Inferno::RecomputeBounds(this: (C_Inferno *)((char *)this - 12));
  C_Inferno::UpdateParticles(this: (C_Inferno *)((char *)this - 12));
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x10423A30
// Name: InfernoMaterialsPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *InfernoMaterialsPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  InfernoMaterialsPrecache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &InfernoMaterialsPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10423B00
// Name: DT_Inferno::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_Inferno::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_Inferno::g_RecvTable);
  return atexit(func: DT_Inferno::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10423B20
// Name: DT_Inferno::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_Inferno::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_Inferno::ignored>();
  DT_Inferno::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10423B50
// Name: DT_FireCrackerBlast::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_FireCrackerBlast::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_FireCrackerBlast::g_RecvTable);
  return atexit(func: DT_FireCrackerBlast::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10423B70
// Name: DT_FireCrackerBlast::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_FireCrackerBlast::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_FireCrackerBlast::ignored>();
  DT_FireCrackerBlast::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10435940
// Name: DT_Inferno::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_Inferno::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_Inferno::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10435950
// Name: DT_FireCrackerBlast::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_FireCrackerBlast::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_FireCrackerBlast::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x101CFF90
// Name: _C_Inferno_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_Inferno_CreateObject(int entnum, int serialNum)
{
  C_Inferno *v2; // eax
  C_Inferno *v3; // eax
  C_Inferno *v4; // esi

  v2 = (C_Inferno *)C_BaseEntity::operator new(stAllocateBlock: 0x2A90u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_Inferno::C_Inferno(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x101D0190
// Name: _C_FireCrackerBlast_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_FireCrackerBlast_CreateObject(int entnum, int serialNum)
{
  C_Inferno *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_Inferno *)C_BaseEntity::operator new(stAllocateBlock: 0x2A90u);
  v3 = &v2->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_Inferno::C_Inferno(this: v2);
  *v3 = &C_FireCrackerBlast::`vftable'{for `IClientUnknown'};
  v3[1] = &C_FireCrackerBlast::`vftable'{for `IClientRenderable'};
  v3[2] = &C_FireCrackerBlast::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_FireCrackerBlast::`vftable'{for `IClientThinkable'};
  v3[4] = &C_FireCrackerBlast::`vftable';
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10423A50
// Name: _dynamic_initializer_for__InfernoDlightSpacing__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__InfernoDlightSpacing__()
{
  ConVar::ConVar(
    this: &InfernoDlightSpacing,
    pName: "inferno_dlight_spacing",
    pDefaultValue: "200",
    flags: 0x4000,
    pHelpString: "Inferno dlights are at least this far apart");
  return atexit(func: dynamic_atexit_destructor_for__InfernoDlightSpacing__);
}

//------------------------------------------------------------------------------
// Address: 0x10423A80
// Name: _dynamic_initializer_for__InfernoDlights__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__InfernoDlights__()
{
  ConVar::ConVar(
    this: &InfernoDlights,
    pName: "inferno_dlights",
    pDefaultValue: "30",
    flags: 0,
    pHelpString: "Min FPS at which molotov dlights will be created");
  return atexit(func: dynamic_atexit_destructor_for__InfernoDlights__);
}

//------------------------------------------------------------------------------
// Address: 0x10423AB0
// Name: _dynamic_initializer_for__InfernoFire__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__InfernoFire__()
{
  ConVar::ConVar(this: &InfernoFire, pName: "inferno_fire", pDefaultValue: "2", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__InfernoFire__);
}

//------------------------------------------------------------------------------
// Address: 0x10423AE0
// Name: _dynamic_initializer_for____g_C_InfernoClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_InfernoClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_InfernoClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_InfernoClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10423B30
// Name: _dynamic_initializer_for____g_C_FireCrackerBlastClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_FireCrackerBlastClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_FireCrackerBlastClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_FireCrackerBlastClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10435960
// Name: _dynamic_atexit_destructor_for__condump_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__condump_command__()
{
  ConCommand::~ConCommand(this: &condump_command);
}

//------------------------------------------------------------------------------
// Address: 0x10435970
// Name: _dynamic_atexit_destructor_for__g_GameConsole__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_GameConsole__()
{
  g_GameConsole.m_bInitialized = false;
  g_GameConsole.__vftable = (CGameConsole_vtbl *)&IBaseInterface::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10435990
// Name: _dynamic_atexit_destructor_for__g_GameUI___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_GameUI___0()
{
  g_GameUI.__vftable = (CGameUI_vtbl *)&CGameUI::`vftable';
  g_pGameUI = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x104359B0
// Name: _dynamic_atexit_destructor_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyConVar__()
{
  ConVar::~ConVar(this: &s_EmptyConVar);
}

//------------------------------------------------------------------------------
// Address: 0x104359C0
// Name: _dynamic_atexit_destructor_for__ui_loading_tip_refresh__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ui_loading_tip_refresh__()
{
  ConVar::~ConVar(this: &ui_loading_tip_refresh);
}

//------------------------------------------------------------------------------
// Address: 0x104359D0
// Name: _dynamic_atexit_destructor_for__ui_loading_tip_f1__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ui_loading_tip_f1__()
{
  ConVar::~ConVar(this: &ui_loading_tip_f1);
}

//------------------------------------------------------------------------------
// Address: 0x104359E0
// Name: _dynamic_atexit_destructor_for__ui_loading_tip_f2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ui_loading_tip_f2__()
{
  ConVar::~ConVar(this: &ui_loading_tip_f2);
}

//------------------------------------------------------------------------------
// Address: 0x104359F0
// Name: _ModInfo_::_2_::_dynamic_atexit_destructor_for__s_ModInfo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ModInfo_::_2_::_dynamic_atexit_destructor_for__s_ModInfo__()
{
  if ( s_ModInfo.m_pModData != nullptr )
  {
    KeyValues::deleteThis(this: s_ModInfo.m_pModData);
    s_ModInfo.m_pModData = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10435A10
// Name: _dynamic_atexit_destructor_for____g_CRunGameEngine_singleton__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____g_CRunGameEngine_singleton__()
{
  _g_CRunGameEngine_singleton.__vftable = (CRunGameEngine_vtbl *)&IBaseInterface::`vftable';
}
