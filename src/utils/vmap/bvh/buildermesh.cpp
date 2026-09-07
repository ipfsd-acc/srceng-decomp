// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vmap/bvh/buildermesh.cpp
// Functions: 27
// ============================================================

#include "utils\vmap\bvh\buildermesh.h"

//------------------------------------------------------------------------------
// Address: 0x00402010
// Name: public: Vector2D::Vector2D(void)
// Source: json
//------------------------------------------------------------------------------
Vector4D *__thiscall Vector2D::Vector2D(Vector4D *this)
{
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00402020
// Name: void Vector2DAdd(class Vector2D const __near &,class Vector2D const __near &,class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Vector2DAdd(const Vector2D *a, const Vector2D *b, Vector2D *c)
{
  c->x = a->x + b->x;
  c->y = a->y + b->y;
}

//------------------------------------------------------------------------------
// Address: 0x00402050
// Name: void Vector2DSubtract(class Vector2D const __near &,class Vector2D const __near &,class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Vector2DSubtract(const Vector2D *a, const Vector2D *b, Vector2D *c)
{
  c->x = a->x - b->x;
  c->y = a->y - b->y;
}

//------------------------------------------------------------------------------
// Address: 0x00402080
// Name: void Vector2DMultiply(class Vector2D const __near &,float,class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Vector2DMultiply(const Vector2D *a, float b, Vector2D *c)
{
  c->x = a->x * b;
  c->y = a->y * b;
}

//------------------------------------------------------------------------------
// Address: 0x004020B0
// Name: public: class Vector __near & Vector::operator=(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall Vector::operator=(Vector *this, const Vector *vOther)
{
  *this = *vOther;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004020D0
// Name: public: class Vector4D __near & Vector4D::operator=(class Vector4D const __near &)
// Source: json
//------------------------------------------------------------------------------
Vector4D *__thiscall Vector4D::operator=(Vector4D *this, const Vector4D *vOther)
{
  *this = *vOther;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00402100
// Name: public: struct BuilderMaterial_t __near & BuilderMaterial_t::operator=(struct BuilderMaterial_t const __near &)
// Source: json
//------------------------------------------------------------------------------
BuilderMaterial_t *__thiscall BuilderMaterial_t::operator=(BuilderMaterial_t *this, const BuilderMaterial_t *__that)
{
  TextureData_t **m_ppTextures; // eax
  int i; // esi

  qmemcpy(this, __that, 0xA8u);
  m_ppTextures = this->m_ppTextures;
  for ( i = 16; i != 0; --i )
  {
    *m_ppTextures = *(TextureData_t **)((char *)m_ppTextures + (char *)__that - (char *)this);
    ++m_ppTextures;
  }
  CUtlString::operator=(this: &this->m_originalMaterialName, src: &__that->m_originalMaterialName);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00402160
// Name: public: void CBuilderMesh::ComputeTangentFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBuilderMesh::ComputeTangentFrame(CBuilderMesh *this)
{
  if ( this->m_Material.m_Material.m_bNormalMap )
    CMesh::CalculateTangents(this: &this->m_mesh);
}

//------------------------------------------------------------------------------
// Address: 0x00402180
// Name: public: void CBuilderMesh::RationalizeUVs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBuilderMesh::RationalizeUVs(CBuilderMesh *this)
{
  RationalizeUVsInPlace(pMesh: &this->m_mesh);
}

//------------------------------------------------------------------------------
// Address: 0x00402190
// Name: public: int CBuilderMesh::ComputeAtlasHash(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBuilderMesh::ComputeAtlasHash(CBuilderMesh *this)
{
  int m_nTextures; // edx
  int result; // eax
  TextureData_t **m_ppTextures; // ecx

  m_nTextures = this->m_Material.m_nTextures;
  result = 0;
  if ( m_nTextures > 0 )
  {
    m_ppTextures = this->m_Material.m_ppTextures;
    do
    {
      result = (*m_ppTextures++)->m_pAtlas->m_ID + (result << 10);
      --m_nTextures;
    }
    while ( m_nTextures != 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004021C0
// Name: public: void CBuilderMesh::InitTextureData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBuilderMesh::InitTextureData(CBuilderMesh *this)
{
  TextureData_t **m_ppTextures; // ebx
  TextureData_t *v2; // edi
  IVTFTexture *v3; // esi
  int m_nTextures; // [esp+0h] [ebp-8h]
  int nFileSize; // [esp+4h] [ebp-4h] BYREF

  if ( this->m_Material.m_nTextures > 0 )
  {
    m_ppTextures = this->m_Material.m_ppTextures;
    m_nTextures = this->m_Material.m_nTextures;
    do
    {
      v2 = *m_ppTextures;
      if ( (*m_ppTextures)->m_XRes == 0 )
      {
        nFileSize = 0;
        v3 = LoadBasetexture(pszFileName: v2->m_szFileName, pFileSize: &nFileSize, pVTFName: v2->m_szVTFName);
        if ( v3 != nullptr )
        {
          v2->m_XRes = v3->Width(this: v3);
          v2->m_YRes = v3->Height(this: v3);
          v2->m_Format = v3->Format(this: v3);
          v2->m_Mips = v3->MipCount(this: v3);
          *(_WORD *)&v2->m_bUsed = 0;
          v2->m_SizeBytes = v3->ComputeTotalSize(this: v3);
          v2->m_nFileSizeBytes = nFileSize;
          DestroyVTFTexture(pTexture: v3);
        }
      }
      ++m_ppTextures;
      --m_nTextures;
    }
    while ( m_nTextures != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402280
// Name: public: void CBuilderMesh::ZeroTextureSizes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBuilderMesh::ZeroTextureSizes(CBuilderMesh *this)
{
  int m_nTextures; // edi
  int v2; // eax
  unsigned int v3; // esi
  TextureData_t **v4; // edx
  int v5; // eax
  TextureData_t *v6; // eax
  TextureData_t *v7; // eax
  TextureData_t *v8; // eax
  TextureData_t **v9; // ecx
  int v10; // edi
  TextureData_t *v11; // eax
  int t; // [esp+0h] [ebp-4h]

  m_nTextures = this->m_Material.m_nTextures;
  v2 = 0;
  if ( m_nTextures >= 4 )
  {
    v3 = ((unsigned int)(m_nTextures - 4) >> 2) + 1;
    v4 = &this->m_Material.m_ppTextures[1];
    t = 4 * v3;
    do
    {
      v5 = (int)*(v4 - 1);
      *(_DWORD *)(v5 + 28) = 2139095039;
      *(_DWORD *)(v5 + 32) = 2139095039;
      *(_DWORD *)(v5 + 36) = -8388609;
      *(_DWORD *)(v5 + 40) = -8388609;
      *(_DWORD *)(v5 + 52) = 0;
      *(_DWORD *)(v5 + 56) = 0;
      *(_DWORD *)(v5 + 44) = 0;
      *(_DWORD *)(v5 + 48) = 0;
      *(_BYTE *)(v5 + 332) = 0;
      v6 = *v4;
      v6->m_vMinUsedBounds.x = 3.4028235e38;
      v6->m_vMinUsedBounds.y = 3.4028235e38;
      v6->m_vMaxUsedBounds.x = -3.4028235e38;
      v6->m_vMaxUsedBounds.y = -3.4028235e38;
      v6->m_vMaxWorldPerUV.x = 0.0;
      v6->m_vMaxWorldPerUV.y = 0.0;
      v6->m_vMaxTextureSize.x = 0.0;
      v6->m_vMaxTextureSize.y = 0.0;
      v6->m_bUsed = false;
      v7 = v4[1];
      v7->m_vMinUsedBounds.x = 3.4028235e38;
      v7->m_vMinUsedBounds.y = 3.4028235e38;
      v7->m_vMaxUsedBounds.x = -3.4028235e38;
      v7->m_vMaxUsedBounds.y = -3.4028235e38;
      v7->m_vMaxWorldPerUV.x = 0.0;
      v7->m_vMaxWorldPerUV.y = 0.0;
      v7->m_vMaxTextureSize.x = 0.0;
      v7->m_vMaxTextureSize.y = 0.0;
      v7->m_bUsed = false;
      v8 = v4[2];
      v8->m_vMinUsedBounds.x = 3.4028235e38;
      v8->m_vMinUsedBounds.y = 3.4028235e38;
      v8->m_vMaxUsedBounds.x = -3.4028235e38;
      v8->m_vMaxUsedBounds.y = -3.4028235e38;
      v8->m_vMaxWorldPerUV.x = 0.0;
      v8->m_vMaxWorldPerUV.y = 0.0;
      v8->m_vMaxTextureSize.x = 0.0;
      v4 += 4;
      --v3;
      v8->m_vMaxTextureSize.y = 0.0;
      v8->m_bUsed = false;
    }
    while ( v3 != 0 );
    v2 = t;
  }
  if ( v2 < m_nTextures )
  {
    v9 = &this->m_Material.m_ppTextures[v2];
    v10 = m_nTextures - v2;
    do
    {
      v11 = *v9;
      v11->m_vMinUsedBounds.x = 3.4028235e38;
      v11->m_vMinUsedBounds.y = 3.4028235e38;
      v11->m_vMaxUsedBounds.x = -3.4028235e38;
      v11->m_vMaxUsedBounds.y = -3.4028235e38;
      v11->m_vMaxWorldPerUV.x = 0.0;
      v11->m_vMaxWorldPerUV.y = 0.0;
      ++v9;
      --v10;
      v11->m_vMaxTextureSize.x = 0.0;
      v11->m_vMaxTextureSize.y = 0.0;
      v11->m_bUsed = false;
    }
    while ( v10 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004023F0
// Name: public: int CBuilderMesh::ComputeTextureSizes(float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBuilderMesh::ComputeTextureSizes(
        CBuilderMesh *this,
        float flMinDistToCamera,
        float flHorzFOV,
        float flHalfScreenWidth,
        float flGutterSize)
{
  int m_nTextures; // edi
  int v7; // ebx
  float v8; // xmm7_4
  float v9; // xmm5_4
  TextureData_t **m_ppTextures; // ecx
  TextureData_t *v11; // eax
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm4_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float y; // xmm2_4
  float x; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm3_4
  float v22; // [esp+0h] [ebp-Ch]

  m_nTextures = this->m_Material.m_nTextures;
  v7 = 0;
  if ( m_nTextures > 0 )
  {
    __libm_sse2_tanf(x: v22);
    v8 = flGutterSize * 2.0;
    v9 = 1.0 / (float)((float)(flHorzFOV * 0.5) * flMinDistToCamera);
    m_ppTextures = this->m_Material.m_ppTextures;
    do
    {
      v11 = *m_ppTextures;
      v12 = (*m_ppTextures)->m_vMaxUsedBounds.x - (*m_ppTextures)->m_vMinUsedBounds.x;
      v13 = (*m_ppTextures)->m_vMaxUsedBounds.y - (*m_ppTextures)->m_vMinUsedBounds.y;
      v14 = (float)(*m_ppTextures)->m_XRes * v12;
      v15 = (float)(v9 * (float)((*m_ppTextures)->m_vMaxWorldPerUV.x * v12)) * flHalfScreenWidth;
      v16 = (float)(v9 * (float)((*m_ppTextures)->m_vMaxWorldPerUV.y * v13)) * flHalfScreenWidth;
      y = (float)(*m_ppTextures)->m_YRes * v13;
      v11->m_vMaxTextureSize.x = v15;
      v11->m_vMaxTextureSize.y = v16;
      if ( v15 > v14 )
        v15 = v14;
      v11->m_vMaxTextureSize.x = v15;
      if ( v11->m_vMaxTextureSize.y <= y )
        y = v11->m_vMaxTextureSize.y;
      v11->m_vMaxTextureSize.y = y;
      v11->m_vMaxTextureSize.x = v8 + v11->m_vMaxTextureSize.x;
      v11->m_vMaxTextureSize.y = v11->m_vMaxTextureSize.y + v8;
      x = v11->m_vMaxTextureSize.x;
      v19 = v11->m_vMaxTextureSize.y;
      if ( x <= v19 )
        v20 = v11->m_vMaxTextureSize.y;
      else
        v20 = v11->m_vMaxTextureSize.x;
      if ( (float)v7 <= v20 )
      {
        if ( x <= v19 )
          x = v11->m_vMaxTextureSize.y;
      }
      else
      {
        x = (float)v7;
      }
      ++m_ppTextures;
      --m_nTextures;
      v7 = (int)x;
    }
    while ( m_nTextures != 0 );
  }
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x00402530
// Name: public: struct AABB_t CBuilderMesh::CalculateBounds(int,int)
// Source: json
//------------------------------------------------------------------------------
AABB_t *__thiscall CBuilderMesh::CalculateBounds(CBuilderMesh *this, AABB_t *result, int nVertStart, int nVertCount)
{
  CMesh::CalculateBounds(
    this: &this->m_mesh,
    pMinOut: &result->m_vMinBounds,
    pMaxOut: &result->m_vMaxBounds,
    nStartVertex: nVertStart,
    nVertexCount: nVertCount);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00402560
// Name: public: BuilderDrawData_t::BuilderDrawData_t(struct BuilderDrawData_t const __near &)
// Source: json
//------------------------------------------------------------------------------
BuilderDrawData_t *__thiscall BuilderDrawData_t::BuilderDrawData_t(
        BuilderDrawData_t *this,
        const BuilderDrawData_t *__that)
{
  BuilderDrawData_t *result; // eax
  Vector4D *m_vTextureScales; // esi
  float *p_z; // edx
  int v5; // edi
  int v6; // ecx
  double x; // st7

  result = this;
  this->m_VertexStart = __that->m_VertexStart;
  this->m_VertexCount = __that->m_VertexCount;
  this->m_IndexStart = __that->m_IndexStart;
  m_vTextureScales = __that->m_vTextureScales;
  this->m_IndexCount = __that->m_IndexCount;
  p_z = &this->m_vTextureScales[0].z;
  v5 = (char *)__that - (char *)this;
  v6 = 2;
  do
  {
    x = m_vTextureScales->x;
    m_vTextureScales += 8;
    *(p_z - 2) = x;
    p_z += 32;
    --v6;
    *(p_z - 33) = m_vTextureScales[-8].y;
    *(p_z - 32) = *(float *)((char *)p_z + v5 - 128);
    *(p_z - 31) = m_vTextureScales[-8].w;
    *(p_z - 30) = m_vTextureScales[-7].x;
    *(p_z - 29) = m_vTextureScales[-7].y;
    *(p_z - 28) = m_vTextureScales[-7].z;
    *(p_z - 27) = m_vTextureScales[-7].w;
    *(p_z - 26) = m_vTextureScales[-6].x;
    *(p_z - 25) = m_vTextureScales[-6].y;
    *(p_z - 24) = m_vTextureScales[-6].z;
    *(p_z - 23) = m_vTextureScales[-6].w;
    *(p_z - 22) = m_vTextureScales[-5].x;
    *(p_z - 21) = m_vTextureScales[-5].y;
    *(p_z - 20) = m_vTextureScales[-5].z;
    *(p_z - 19) = m_vTextureScales[-5].w;
    *(p_z - 18) = m_vTextureScales[-4].x;
    *(p_z - 17) = m_vTextureScales[-4].y;
    *(p_z - 16) = m_vTextureScales[-4].z;
    *(p_z - 15) = m_vTextureScales[-4].w;
    *(p_z - 14) = m_vTextureScales[-3].x;
    *(p_z - 13) = m_vTextureScales[-3].y;
    *(p_z - 12) = m_vTextureScales[-3].z;
    *(p_z - 11) = m_vTextureScales[-3].w;
    *(p_z - 10) = m_vTextureScales[-2].x;
    *(p_z - 9) = m_vTextureScales[-2].y;
    *(p_z - 8) = m_vTextureScales[-2].z;
    *(p_z - 7) = m_vTextureScales[-2].w;
    *(p_z - 6) = m_vTextureScales[-1].x;
    *(p_z - 5) = m_vTextureScales[-1].y;
    *(p_z - 4) = m_vTextureScales[-1].z;
    *(p_z - 3) = m_vTextureScales[-1].w;
  }
  while ( v6 != 0 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00402710
// Name: public: void CBuilderMesh::ComputeTextureBounds(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBuilderMesh::ComputeTextureBounds(CBuilderMesh *this, bool bWrapInAtlas)
{
  int v3; // ebx
  TextureData_t *v4; // ecx
  int v5; // edx
  int v6; // edi
  __int128 x_low; // xmm7
  int v8; // eax
  __int128 v9; // xmm3
  __int128 y_low; // xmm2
  float x; // xmm1_4
  __int128 v12; // xmm4
  unsigned int v13; // edx
  float *m_pVerts; // ebx
  __int128 v15; // xmm0
  float *v16; // edx
  __int128 v17; // xmm0
  __int128 v18; // xmm0
  __int128 v19; // xmm0
  float v20; // xmm0_4
  int nFaces; // [esp+Ch] [ebp-1Ch]
  unsigned int *pIndices; // [esp+10h] [ebp-18h]
  int t; // [esp+14h] [ebp-14h]
  int f; // [esp+18h] [ebp-10h]
  float y; // [esp+1Ch] [ebp-Ch]
  int nTexOffset; // [esp+20h] [ebp-8h]
  TextureData_t **m_ppTextures; // [esp+24h] [ebp-4h]

  v3 = this->m_mesh.m_nIndexCount / 3;
  nFaces = v3;
  nTexOffset = CMesh::FindFirstAttributeOffset(this: &this->m_mesh, nType: VERTEX_ELEMENT_TEXCOORD2D_0);
  if ( nTexOffset == -1 )
    nTexOffset = CMesh::FindFirstAttributeOffset(this: &this->m_mesh, nType: VERTEX_ELEMENT_TEXCOORD3D_0);
  pIndices = this->m_mesh.m_pIndices;
  t = 0;
  if ( this->m_Material.m_nTextures > 0 )
  {
    m_ppTextures = this->m_Material.m_ppTextures;
    do
    {
      v4 = *m_ppTextures;
      v5 = 0;
      v6 = 0;
      f = 0;
      if ( v3 > 0 )
      {
        x_low = LODWORD(v4->m_vMaxWorldPerUV.x);
        y = v4->m_vMaxWorldPerUV.y;
        do
        {
          v8 = 0;
          if ( this->m_Combo.m_nIndicesPerFace > 0 )
          {
            v9 = LODWORD(v4->m_vMinUsedBounds.x);
            y_low = LODWORD(v4->m_vMinUsedBounds.y);
            x = v4->m_vMaxUsedBounds.x;
            v12 = LODWORD(v4->m_vMaxUsedBounds.y);
            do
            {
              v13 = nTexOffset + this->m_mesh.m_nVertexStrideFloats * pIndices[v6];
              m_pVerts = this->m_mesh.m_pVerts;
              v15 = LODWORD(m_pVerts[v13]);
              v16 = &m_pVerts[v13];
              if ( *(float *)&v9 <= *(float *)&v15 )
                v15 = v9;
              v9 = v15;
              LODWORD(v4->m_vMinUsedBounds.x) = v15;
              v17 = *((unsigned int *)v16 + 1);
              if ( *(float *)&y_low <= *(float *)&v17 )
                v17 = y_low;
              y_low = v17;
              LODWORD(v4->m_vMinUsedBounds.y) = v17;
              if ( *v16 > x )
                x = *v16;
              v4->m_vMaxUsedBounds.x = x;
              v18 = *((unsigned int *)v16 + 1);
              if ( *(float *)&v18 <= *(float *)&v12 )
                v18 = v12;
              v12 = v18;
              LODWORD(v4->m_vMaxUsedBounds.y) = v18;
              if ( !bWrapInAtlas )
              {
                if ( x >= 1.0 )
                {
                  x = 1.0;
                  v4->m_vMaxUsedBounds.x = 1.0;
                  v9 = 0;
                  v4->m_vMinUsedBounds.x = 0.0;
                }
                if ( *(float *)&v18 >= 1.0 )
                {
                  v12 = 0x3F800000u;
                  v4->m_vMaxUsedBounds.y = 1.0;
                  y_low = 0;
                  v4->m_vMinUsedBounds.y = 0.0;
                }
              }
              ++v8;
              ++v6;
            }
            while ( v8 < this->m_Combo.m_nIndicesPerFace );
            v3 = nFaces;
            v5 = f;
          }
          v19 = LODWORD(this->m_worldPerUV.m_Memory.m_pMemory[v5].x);
          if ( *(float *)&v19 <= *(float *)&x_low )
            v19 = x_low;
          x_low = v19;
          LODWORD(v4->m_vMaxWorldPerUV.x) = v19;
          v20 = this->m_worldPerUV.m_Memory.m_pMemory[v5].y;
          if ( v20 <= y )
            v20 = y;
          ++v5;
          y = v20;
          v4->m_vMaxWorldPerUV.y = v20;
          v4->m_bUsed = true;
          f = v5;
        }
        while ( v5 < v3 );
      }
      ++m_ppTextures;
      ++t;
    }
    while ( t < this->m_Material.m_nTextures );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004028E0
// Name: public: CUtlString::~CUtlString(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlString::~CUtlString(CUtlString *this)
{
  bool v2; // sf

  v2 = this->m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_Storage.m_nActualLength = 0;
  if ( !v2 )
  {
    if ( this->m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Storage.m_Memory.m_pMemory);
      this->m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_Storage.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402D80
// Name: public: CBuilderMesh::CBuilderMesh(void)
// Source: json
//------------------------------------------------------------------------------
CBuilderMesh *__thiscall CBuilderMesh::CBuilderMesh(CBuilderMesh *this)
{
  CMesh::CMesh(this: &this->m_mesh);
  this->m_worldPerUV.m_Memory.m_pMemory = nullptr;
  this->m_worldPerUV.m_Memory.m_nAllocationCount = 0;
  this->m_worldPerUV.m_Memory.m_nGrowSize = 0;
  this->m_worldPerUV.m_Size = 0;
  this->m_worldPerUV.m_pElements = nullptr;
  this->m_faceCenters.m_Memory.m_pMemory = nullptr;
  this->m_faceCenters.m_Memory.m_nAllocationCount = 0;
  this->m_faceCenters.m_Memory.m_nGrowSize = 0;
  this->m_faceCenters.m_Size = 0;
  this->m_faceCenters.m_pElements = nullptr;
  CUtlString::CUtlString(this: &this->m_Material.m_originalMaterialName);
  this->m_DrawData.m_Memory.m_pMemory = nullptr;
  this->m_DrawData.m_Memory.m_nAllocationCount = 0;
  this->m_DrawData.m_Memory.m_nGrowSize = 0;
  this->m_DrawData.m_Size = 0;
  this->m_DrawData.m_pElements = nullptr;
  this->m_nPerDrawIndexSets = 0;
  this->m_pPerDrawIndices = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00402DF0
// Name: public: CBuilderMesh::~CBuilderMesh(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBuilderMesh::~CBuilderMesh(CBuilderMesh *this)
{
  bool v2; // sf

  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_DrawData);
  v2 = this->m_Material.m_originalMaterialName.m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_Material.m_originalMaterialName.m_Storage.m_nActualLength = 0;
  if ( !v2 )
  {
    if ( this->m_Material.m_originalMaterialName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Material.m_originalMaterialName.m_Storage.m_Memory.m_pMemory);
      this->m_Material.m_originalMaterialName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_Material.m_originalMaterialName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_faceCenters);
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_worldPerUV);
  CMesh::~CMesh(this: &this->m_mesh);
}

//------------------------------------------------------------------------------
// Address: 0x00402E60
// Name: public: CBuilderMesh::CBuilderMesh(class CBuilderMesh const __near &)
// Source: json
//------------------------------------------------------------------------------
CBuilderMesh *__thiscall CBuilderMesh::CBuilderMesh(CBuilderMesh *this, const CBuilderMesh *Other)
{
  CMesh::CMesh(this: &this->m_mesh);
  this->m_worldPerUV.m_Memory.m_pMemory = nullptr;
  this->m_worldPerUV.m_Memory.m_nAllocationCount = 0;
  this->m_worldPerUV.m_Memory.m_nGrowSize = 0;
  this->m_worldPerUV.m_Size = 0;
  this->m_worldPerUV.m_pElements = nullptr;
  this->m_faceCenters.m_Memory.m_pMemory = nullptr;
  this->m_faceCenters.m_Memory.m_nAllocationCount = 0;
  this->m_faceCenters.m_Memory.m_nGrowSize = 0;
  this->m_faceCenters.m_Size = 0;
  this->m_faceCenters.m_pElements = nullptr;
  CUtlString::CUtlString(this: &this->m_Material.m_originalMaterialName);
  this->m_DrawData.m_Memory.m_pMemory = nullptr;
  this->m_DrawData.m_Memory.m_nAllocationCount = 0;
  this->m_DrawData.m_Memory.m_nGrowSize = 0;
  this->m_DrawData.m_Size = 0;
  this->m_DrawData.m_pElements = nullptr;
  this->m_nPerDrawIndexSets = 0;
  this->m_pPerDrawIndices = nullptr;
  this->m_Combo = Other->m_Combo;
  DuplicateMesh(pMeshOut: &this->m_mesh, inputMesh: &Other->m_mesh);
  CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertMultipleBefore(
    this: &this->m_faceCenters,
    elem: this->m_faceCenters.m_Size,
    num: Other->m_faceCenters.m_Size,
    pToInsert: Other->m_faceCenters.m_Memory.m_pMemory);
  CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertMultipleBefore(
    this: &this->m_worldPerUV,
    elem: this->m_worldPerUV.m_Size,
    num: Other->m_worldPerUV.m_Size,
    pToInsert: Other->m_worldPerUV.m_Memory.m_pMemory);
  BuilderMaterial_t::operator=(this: &this->m_Material, __that: &Other->m_Material);
  CUtlVector<BuilderDrawData_t,CUtlMemory<BuilderDrawData_t,int>>::InsertMultipleBefore(
    this: &this->m_DrawData,
    elem: this->m_DrawData.m_Size,
    num: Other->m_DrawData.m_Size,
    pToInsert: Other->m_DrawData.m_Memory.m_pMemory);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00402F40
// Name: public: void CBuilderMesh::Concatenate(class CBuilderMesh __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBuilderMesh::Concatenate(CBuilderMesh *this, CBuilderMesh *Other)
{
  int m_nIndexCount; // edx
  CBuilderMesh *v4; // edi
  int v5; // eax
  int m_nVertexCount; // ecx
  int v7; // ebx
  CMesh *p_m_mesh; // eax
  int m_nTextures; // ebx
  int v10; // edx
  BuilderDrawData_t *m_pMemory; // ecx
  Vector4D *v12; // edx
  float *p_z; // ecx
  unsigned int v14; // edi
  float *v15; // eax
  float *v16; // ecx
  float *v17; // eax
  int v18; // ebx
  double v19; // st7
  int m_nAllocationCount; // eax
  CUtlMemory<BuilderDrawData_t,int> *p_m_Memory; // esi
  int m_Size; // edi
  BuilderDrawData_t *v23; // ecx
  int v24; // eax
  BuilderDrawData_t *v25; // ecx
  BuilderDrawData_t drawData; // [esp+Ch] [ebp-11Ch] BYREF
  int nOldIndices; // [esp+11Ch] [ebp-Ch]
  CBuilderMesh *v28; // [esp+120h] [ebp-8h]
  int t; // [esp+124h] [ebp-4h]
  int nNewVerts; // [esp+130h] [ebp+8h]

  m_nIndexCount = Other->m_mesh.m_nIndexCount;
  v4 = this;
  v5 = this->m_mesh.m_nIndexCount;
  m_nVertexCount = Other->m_mesh.m_nVertexCount;
  v7 = v4->m_mesh.m_nVertexCount;
  nOldIndices = v5;
  p_m_mesh = &Other->m_mesh;
  nNewVerts = m_nVertexCount;
  v28 = v4;
  t = m_nIndexCount;
  CMesh::AppendMesh(this: &v4->m_mesh, inputMesh: p_m_mesh);
  CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertMultipleBefore(
    this: &v4->m_worldPerUV,
    elem: v4->m_worldPerUV.m_Size,
    num: Other->m_worldPerUV.m_Size,
    pToInsert: Other->m_worldPerUV.m_Memory.m_pMemory);
  CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertMultipleBefore(
    this: &v4->m_faceCenters,
    elem: v4->m_faceCenters.m_Size,
    num: Other->m_faceCenters.m_Size,
    pToInsert: Other->m_faceCenters.m_Memory.m_pMemory);
  _V_memset(dest: drawData.m_vTextureScales, fill: 0, count: 256);
  drawData.m_VertexStart = v7;
  m_nTextures = Other->m_Material.m_nTextures;
  drawData.m_VertexCount = nNewVerts;
  v10 = 0;
  drawData.m_IndexStart = nOldIndices;
  drawData.m_IndexCount = t;
  if ( m_nTextures >= 4 )
  {
    m_pMemory = Other->m_DrawData.m_Memory.m_pMemory;
    v12 = &m_pMemory->m_vTextureScales[1];
    p_z = &m_pMemory->m_vTextureScales[0].z;
    v14 = ((unsigned int)(m_nTextures - 4) >> 2) + 1;
    v15 = &drawData.m_vTextureScales[0].z;
    t = 4 * v14;
    do
    {
      p_z += 16;
      *(v15 - 2) = v12[-1].x;
      v15 += 16;
      v12 += 4;
      --v14;
      *(v15 - 17) = *(p_z - 17);
      *(v15 - 16) = *(p_z - 16);
      *(v15 - 15) = *(p_z - 15);
      *(v15 - 14) = v12[-4].x;
      *(v15 - 13) = *(p_z - 13);
      *(v15 - 12) = *(p_z - 12);
      *(v15 - 11) = *(p_z - 11);
      *(v15 - 10) = v12[-3].x;
      *(v15 - 9) = *(p_z - 9);
      *(v15 - 8) = *(p_z - 8);
      *(v15 - 7) = *(p_z - 7);
      *(v15 - 6) = v12[-2].x;
      *(v15 - 5) = *(p_z - 5);
      *(v15 - 4) = *(p_z - 4);
      *(v15 - 3) = *(p_z - 3);
    }
    while ( v14 != 0 );
    v4 = v28;
    v10 = t;
  }
  if ( v10 < m_nTextures )
  {
    v16 = &drawData.m_vTextureScales[v10].z;
    v17 = &Other->m_DrawData.m_Memory.m_pMemory->m_vTextureScales[v10].z;
    v18 = m_nTextures - v10;
    do
    {
      v19 = *(v17 - 2);
      v17 += 4;
      *(v16 - 2) = v19;
      v16 += 4;
      --v18;
      *(v16 - 5) = *(v17 - 5);
      *(v16 - 4) = *(v17 - 4);
      *(v16 - 3) = *(v17 - 3);
    }
    while ( v18 != 0 );
  }
  m_nAllocationCount = v4->m_DrawData.m_Memory.m_nAllocationCount;
  p_m_Memory = &v4->m_DrawData.m_Memory;
  m_Size = v4->m_DrawData.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<BuilderDrawData_t,int>::Grow(this: p_m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Memory[1].m_pMemory;
  v23 = p_m_Memory->m_pMemory;
  v24 = (int)p_m_Memory[1].m_pMemory - m_Size - 1;
  p_m_Memory[1].m_nAllocationCount = (int)p_m_Memory->m_pMemory;
  if ( v24 > 0 )
    _V_memmove(dest: &v23[m_Size + 1], src: &v23[m_Size], count: 272 * v24);
  v25 = &p_m_Memory->m_pMemory[m_Size];
  if ( v25 != nullptr )
    BuilderDrawData_t::BuilderDrawData_t(this: v25, __that: &drawData);
}

//------------------------------------------------------------------------------
// Address: 0x00403140
// Name: public: void CBuilderMesh::UpdateDrawData(int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBuilderMesh::UpdateDrawData(
        CBuilderMesh *this,
        int nAtlasTextureSizeX,
        int nAtlasTextureSizeY,
        float flGutterSize)
{
  int v4; // edi
  CUtlVector<BuilderDrawData_t,CUtlMemory<BuilderDrawData_t,int> > *p_m_DrawData; // ebx
  int m_nTextures; // eax
  int m_nVertexCount; // ecx
  int m_nIndexCount; // edx
  float v10; // xmm1_4
  float v11; // xmm2_4
  unsigned int v12; // edi
  TextureData_t **v13; // edx
  Vector2D *p_z; // ecx
  float *v15; // eax
  float v16; // xmm7_4
  float v17; // xmm3_4
  float v18; // xmm4_4
  float v19; // xmm5_4
  float v20; // xmm6_4
  float v21; // xmm5_4
  float v22; // xmm6_4
  float *v23; // eax
  float y; // xmm7_4
  float v25; // xmm3_4
  float v26; // xmm4_4
  float v27; // xmm7_4
  float v28; // xmm3_4
  float v29; // xmm6_4
  float v30; // xmm5_4
  float v31; // xmm4_4
  float v32; // xmm6_4
  float v33; // xmm5_4
  float *v34; // eax
  float v35; // xmm7_4
  float v36; // xmm4_4
  float v37; // xmm4_4
  float v38; // xmm7_4
  float v39; // xmm3_4
  float v40; // xmm6_4
  float v41; // xmm5_4
  float v42; // xmm4_4
  float v43; // xmm6_4
  float v44; // xmm5_4
  float x; // xmm6_4
  float *v46; // eax
  float v47; // xmm3_4
  float v48; // xmm7_4
  float v49; // xmm6_4
  float v50; // xmm7_4
  float v51; // xmm5_4
  float v52; // xmm4_4
  float v53; // xmm3_4
  float v54; // xmm6_4
  float v55; // xmm7_4
  float v56; // xmm3_4
  float v57; // xmm4_4
  float v58; // xmm7_4
  TextureData_t **v59; // edx
  float *v60; // ecx
  int v61; // esi
  float *v62; // eax
  float v63; // xmm6_4
  float v64; // xmm7_4
  float v65; // xmm5_4
  float v66; // xmm4_4
  float v67; // xmm3_4
  float v68; // xmm6_4
  float v69; // xmm7_4
  float v70; // xmm3_4
  float v71; // xmm4_4
  float v72; // xmm7_4
  float v73; // xmm4_4
  float v74; // xmm6_4
  int m_Size; // esi
  int m_nAllocationCount; // eax
  BuilderDrawData_t *m_pMemory; // ecx
  int v78; // eax
  BuilderDrawData_t *v79; // ecx
  BuilderDrawData_t drawData; // [esp+Ch] [ebp-138h] BYREF
  int v81; // [esp+11Ch] [ebp-28h]
  int t; // [esp+120h] [ebp-24h]
  float v83; // [esp+124h] [ebp-20h]
  float v84; // [esp+128h] [ebp-1Ch]
  Vector2D vDeltaAtlas; // [esp+12Ch] [ebp-18h]
  Vector2D vDeltaBounds; // [esp+134h] [ebp-10h]
  Vector2D vAtlasUVSize; // [esp+13Ch] [ebp-8h]
  int nAtlasTextureSizeXa; // [esp+14Ch] [ebp+8h]
  float flGutterSizea; // [esp+154h] [ebp+10h]
  float flGutterSizeb; // [esp+154h] [ebp+10h]

  v4 = 0;
  p_m_DrawData = &this->m_DrawData;
  this->m_DrawData.m_Size = 0;
  _V_memset(dest: drawData.m_vTextureScales, fill: 0, count: 256);
  m_nTextures = this->m_Material.m_nTextures;
  m_nVertexCount = this->m_mesh.m_nVertexCount;
  m_nIndexCount = this->m_mesh.m_nIndexCount;
  v10 = flGutterSize / (float)nAtlasTextureSizeX;
  drawData.m_VertexStart = 0;
  drawData.m_VertexCount = m_nVertexCount;
  drawData.m_IndexStart = 0;
  drawData.m_IndexCount = m_nIndexCount;
  v11 = flGutterSize / (float)nAtlasTextureSizeY;
  v81 = m_nTextures;
  if ( m_nTextures >= 4 )
  {
    v12 = ((unsigned int)(m_nTextures - 4) >> 2) + 1;
    v13 = &this->m_Material.m_ppTextures[1];
    p_z = (Vector2D *)&drawData.m_vTextureScales[0].z;
    t = 4 * v12;
    do
    {
      v15 = (float *)*(v13 - 1);
      v16 = v15[10];
      v17 = v15[15] + v10;
      v18 = v15[16] + v11;
      v19 = (float)(v15[17] - v10) - v17;
      vDeltaAtlas.y = (float)(v15[18] - v11) - v18;
      v20 = v15[9];
      vDeltaAtlas.x = v19;
      v21 = v15[7];
      vDeltaBounds.x = v20 - v21;
      v22 = v15[8];
      vDeltaBounds.y = v16 - v22;
      vAtlasUVSize.x = 0.0;
      vAtlasUVSize.y = 0.0;
      if ( vDeltaBounds.x != 0.0 && vDeltaBounds.y != 0.0 )
      {
        vAtlasUVSize.y = vDeltaAtlas.y / vDeltaBounds.y;
        vAtlasUVSize.x = vDeltaAtlas.x / vDeltaBounds.x;
      }
      v23 = (float *)*v13;
      y = vAtlasUVSize.y;
      v25 = v17 - (float)(v21 * vAtlasUVSize.x);
      p_z[-1] = vAtlasUVSize;
      p_z->x = v25;
      p_z->y = v18 - (float)(v22 * y);
      v26 = v23[16];
      v27 = v23[7];
      v28 = v23[15] + v10;
      v29 = v23[18] - v11;
      vDeltaAtlas.x = (float)(v23[17] - v10) - v28;
      v30 = v23[9];
      v31 = v26 + v11;
      vDeltaAtlas.y = v29 - v31;
      v32 = v23[10];
      vDeltaBounds.x = v30 - v27;
      v33 = v23[8];
      vDeltaBounds.y = v32 - v33;
      vAtlasUVSize.x = 0.0;
      vAtlasUVSize.y = 0.0;
      if ( vDeltaBounds.x != 0.0 && vDeltaBounds.y != 0.0 )
      {
        vAtlasUVSize.y = vDeltaAtlas.y / vDeltaBounds.y;
        vAtlasUVSize.x = vDeltaAtlas.x / vDeltaBounds.x;
      }
      v34 = (float *)v13[1];
      v35 = v27 * vAtlasUVSize.x;
      v36 = v31 - (float)(v33 * vAtlasUVSize.y);
      p_z[1] = vAtlasUVSize;
      p_z[2].x = v28 - v35;
      p_z[2].y = v36;
      v37 = v34[16];
      v38 = v34[7];
      v39 = v34[15] + v10;
      v40 = v34[18] - v11;
      vDeltaAtlas.x = (float)(v34[17] - v10) - v39;
      v41 = v34[9];
      v42 = v37 + v11;
      vDeltaAtlas.y = v40 - v42;
      v43 = v34[10];
      vDeltaBounds.x = v41 - v38;
      v44 = v34[8];
      vDeltaBounds.y = v43 - v44;
      vAtlasUVSize.x = 0.0;
      vAtlasUVSize.y = 0.0;
      if ( vDeltaBounds.x == 0.0 || vDeltaBounds.y == 0.0 )
      {
        x = vAtlasUVSize.x;
      }
      else
      {
        x = vDeltaAtlas.x / vDeltaBounds.x;
        vAtlasUVSize.y = vDeltaAtlas.y / vDeltaBounds.y;
      }
      v46 = (float *)v13[2];
      p_z[3].x = x;
      v83 = v38 * x;
      v47 = v39 - (float)(v38 * x);
      v48 = vAtlasUVSize.y;
      p_z[3].y = vAtlasUVSize.y;
      p_z[4].x = v47;
      p_z[4].y = v42 - (float)(v44 * v48);
      v49 = v46[16];
      v50 = v46[9];
      v51 = v46[15] + v10;
      v52 = v46[18] - v11;
      vDeltaAtlas.x = (float)(v46[17] - v10) - v51;
      v53 = v46[7];
      v54 = v49 + v11;
      v55 = v50 - v53;
      vDeltaAtlas.y = v52 - v54;
      flGutterSizea = v53;
      nAtlasTextureSizeXa = *((int *)v46 + 8);
      v56 = v46[10] - *(float *)&nAtlasTextureSizeXa;
      vAtlasUVSize.x = 0.0;
      v57 = 0.0;
      if ( v55 == 0.0 || v56 == 0.0 )
      {
        v58 = vAtlasUVSize.x;
      }
      else
      {
        v58 = vDeltaAtlas.x / v55;
        v57 = vDeltaAtlas.y / v56;
      }
      v83 = flGutterSizea * v58;
      p_z[5].x = v58;
      p_z[5].y = v57;
      p_z[6].x = v51 - (float)(flGutterSizea * v58);
      p_z[6].y = v54 - (float)(*(float *)&nAtlasTextureSizeXa * v57);
      v13 += 4;
      p_z += 8;
      --v12;
      v84 = *(float *)&nAtlasTextureSizeXa * v57;
    }
    while ( v12 != 0 );
    m_nTextures = v81;
    v4 = t;
  }
  if ( v4 < m_nTextures )
  {
    v59 = &this->m_Material.m_ppTextures[v4];
    v60 = &drawData.m_vTextureScales[v4].z;
    v61 = m_nTextures - v4;
    do
    {
      v62 = (float *)*v59;
      v63 = (*v59)->m_vAtlasMin.y;
      v64 = (*v59)->m_vMaxUsedBounds.x;
      v65 = (*v59)->m_vAtlasMin.x + v10;
      v66 = (*v59)->m_vAtlasMax.y - v11;
      vDeltaAtlas.x = (float)((*v59)->m_vAtlasMax.x - v10) - v65;
      v67 = v62[7];
      v68 = v63 + v11;
      vDeltaAtlas.y = v66 - v68;
      v69 = v64 - v67;
      flGutterSizeb = v67;
      v70 = v62[8];
      v71 = v62[10] - v70;
      vDeltaBounds.y = v71;
      vAtlasUVSize.x = 0.0;
      vAtlasUVSize.y = 0.0;
      if ( v69 == 0.0 || v71 == 0.0 )
      {
        v72 = vAtlasUVSize.x;
      }
      else
      {
        v72 = vDeltaAtlas.x / v69;
        vAtlasUVSize.y = vDeltaAtlas.y / vDeltaBounds.y;
      }
      v83 = flGutterSizeb * v72;
      v73 = vAtlasUVSize.y;
      v74 = v68 - (float)(v70 * vAtlasUVSize.y);
      *(v60 - 2) = v72;
      *(v60 - 1) = v73;
      *v60 = v65 - (float)(flGutterSizeb * v72);
      v60[1] = v74;
      ++v59;
      v60 += 4;
      --v61;
    }
    while ( v61 != 0 );
  }
  m_Size = p_m_DrawData->m_Size;
  m_nAllocationCount = p_m_DrawData->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<BuilderDrawData_t,int>::Grow(this: &p_m_DrawData->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++p_m_DrawData->m_Size;
  m_pMemory = p_m_DrawData->m_Memory.m_pMemory;
  v78 = p_m_DrawData->m_Size - m_Size - 1;
  p_m_DrawData->m_pElements = p_m_DrawData->m_Memory.m_pMemory;
  if ( v78 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 272 * v78);
  v79 = &p_m_DrawData->m_Memory.m_pMemory[m_Size];
  if ( v79 != nullptr )
    BuilderDrawData_t::BuilderDrawData_t(this: v79, __that: &drawData);
}

//------------------------------------------------------------------------------
// Address: 0x004036F0
// Name: public: void CBuilderMesh::ComputeTangentSpaces(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBuilderMesh::ComputeTangentSpaces(CBuilderMesh *this)
{
  int v2; // esi

  v2 = this->m_mesh.m_nIndexCount / 3;
  if ( this->m_worldPerUV.m_Size < v2 )
    CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertMultipleBefore(
      this: (CUtlVector<ResourceEntryInfo,CUtlMemory<ResourceEntryInfo,int> > *)&this->m_worldPerUV,
      elem: this->m_worldPerUV.m_Size,
      num: v2 - this->m_worldPerUV.m_Size);
  CMesh::CalculateTangentSpaceWorldLengthsPerFace(
    this: &this->m_mesh,
    pLengthsOut: this->m_worldPerUV.m_Memory.m_pMemory,
    nLengthsOut: v2,
    flMaxWorldPerUV: 256.0);
}

//------------------------------------------------------------------------------
// Address: 0x00403740
// Name: public: void CBuilderMesh::CalculateFaceData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBuilderMesh::CalculateFaceData(CBuilderMesh *this)
{
  int v2; // esi

  v2 = this->m_mesh.m_nIndexCount / 3;
  if ( this->m_faceCenters.m_Size < v2 )
    CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertMultipleBefore(
      this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&this->m_faceCenters,
      elem: this->m_faceCenters.m_Size,
      num: v2 - this->m_faceCenters.m_Size);
  CMesh::CalculateFaceCenters(this: &this->m_mesh, pCentersOut: this->m_faceCenters.m_Memory.m_pMemory, nCentersOut: v2);
}

//------------------------------------------------------------------------------
// Address: 0x00403780
// Name: public: void CBuilderMesh::ZeroFaceData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBuilderMesh::ZeroFaceData(CBuilderMesh *this)
{
  int v2; // ebx
  int v3; // ecx
  int v4; // edx
  Vector2D *m_pMemory; // eax
  Vector *v6; // eax
  Vector2D *v7; // eax
  int v8; // ebx
  Vector *v9; // eax
  int v10; // eax
  Vector2D *v11; // ebx
  Vector *v12; // eax
  int v13; // eax
  Vector2D *v14; // eax
  Vector *v15; // eax
  int v16; // edx
  Vector2D *v17; // eax
  Vector *v18; // eax
  int nFaces; // [esp+Ch] [ebp-8h]

  v2 = this->m_mesh.m_nIndexCount / 3;
  nFaces = v2;
  if ( this->m_worldPerUV.m_Size < v2 )
    CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertMultipleBefore(
      this: (CUtlVector<ResourceEntryInfo,CUtlMemory<ResourceEntryInfo,int> > *)&this->m_worldPerUV,
      elem: this->m_worldPerUV.m_Size,
      num: v2 - this->m_worldPerUV.m_Size);
  if ( this->m_faceCenters.m_Size < v2 )
    CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertMultipleBefore(
      this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&this->m_faceCenters,
      elem: this->m_faceCenters.m_Size,
      num: v2 - this->m_faceCenters.m_Size);
  v3 = 0;
  if ( v2 >= 4 )
  {
    v4 = 0;
    do
    {
      m_pMemory = this->m_worldPerUV.m_Memory.m_pMemory;
      m_pMemory[v3].x = 0.0;
      m_pMemory[v3].y = 0.0;
      v6 = this->m_faceCenters.m_Memory.m_pMemory;
      v6[v4].x = 0.0;
      v6[v4].y = 0.0;
      v6[v4].z = 0.0;
      v7 = this->m_worldPerUV.m_Memory.m_pMemory;
      v8 = v3;
      v7[v8 + 1].x = 0.0;
      v7[v8 + 1].y = 0.0;
      v9 = this->m_faceCenters.m_Memory.m_pMemory;
      v9[v4 + 1].x = 0.0;
      v9[v4 + 1].y = 0.0;
      v9[v4 + 1].z = 0.0;
      v10 = 8 * v3 + 24;
      v11 = this->m_worldPerUV.m_Memory.m_pMemory;
      *(float *)((char *)&v11[-1].x + v10) = 0.0;
      *(_DWORD *)((char *)v11 + v10 - 4) = 0;
      v12 = this->m_faceCenters.m_Memory.m_pMemory;
      v2 = nFaces;
      v12[v4 + 2].x = 0.0;
      v13 = (int)&v12[v4 + 2];
      *(_DWORD *)(v13 + 4) = 0;
      *(_DWORD *)(v13 + 8) = 0;
      v14 = &this->m_worldPerUV.m_Memory.m_pMemory[v3 + 3];
      v3 += 4;
      v14->x = 0.0;
      v14->y = 0.0;
      v15 = this->m_faceCenters.m_Memory.m_pMemory;
      v15[v4 + 3].x = 0.0;
      v15[v4 + 3].y = 0.0;
      v15[v4 + 3].z = 0.0;
      v4 += 4;
    }
    while ( v3 < nFaces - 3 );
  }
  if ( v3 < v2 )
  {
    v16 = v3;
    do
    {
      v17 = &this->m_worldPerUV.m_Memory.m_pMemory[v3];
      v17->x = 0.0;
      v17->y = 0.0;
      v18 = this->m_faceCenters.m_Memory.m_pMemory;
      v18[v16].x = 0.0;
      v18[v16].y = 0.0;
      v18[v16].z = 0.0;
      ++v3;
      ++v16;
    }
    while ( v3 < v2 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004038F0
// Name: public: void CBuilderMesh::RemoveRedundantVerts(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBuilderMesh::RemoveRedundantVerts(CBuilderMesh *this)
{
  float *v2; // edi
  int i; // eax
  CMesh *p_m_mesh; // ebx
  int m_Size; // edi
  int v6; // ecx
  int v7; // ebx
  int m_nAllocationCount; // edx
  Vector *m_pMemory; // edx
  int v10; // eax
  int m_nVertexStrideFloats; // [esp-4h] [ebp-4Ch]
  CMesh meshOut; // [esp+Ch] [ebp-3Ch] BYREF
  int v13; // [esp+3Ch] [ebp-Ch]
  CMesh *v14; // [esp+40h] [ebp-8h]
  int v15; // [esp+44h] [ebp-4h]

  v2 = (float *)MemAlloc_Alloc(
                  nSize: (unsigned __int64)(unsigned int)this->m_mesh.m_nVertexStrideFloats >> 30 != 0
                ? -1
                : 4 * this->m_mesh.m_nVertexStrideFloats);
  for ( i = 0; i < this->m_mesh.m_nVertexStrideFloats; ++i )
    v2[i] = 0.000001;
  CMesh::CMesh(this: &meshOut);
  m_nVertexStrideFloats = this->m_mesh.m_nVertexStrideFloats;
  p_m_mesh = &this->m_mesh;
  v14 = &this->m_mesh;
  WeldVertices(pMeshOut: &meshOut, inputMesh: &this->m_mesh, pEpsilons: v2, nEpsilons: m_nVertexStrideFloats);
  free(pMem: v2);
  CMesh::FreeAllMemory(this: &this->m_mesh);
  CleanMesh(pMeshOut: &this->m_mesh, inputMesh: &meshOut);
  CMesh::FreeAllMemory(this: &meshOut);
  m_Size = this->m_faceCenters.m_Size;
  v6 = this->m_mesh.m_nIndexCount / 3;
  v15 = v6;
  if ( m_Size < v6 )
  {
    v7 = v6 - m_Size;
    if ( v6 != m_Size )
    {
      m_nAllocationCount = this->m_faceCenters.m_Memory.m_nAllocationCount;
      v13 = v6;
      if ( v6 > m_nAllocationCount )
      {
        CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>::Grow(
          this: (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)&this->m_faceCenters,
          num: v6 - m_nAllocationCount);
        v6 = v15;
      }
      this->m_faceCenters.m_Size += v7;
      m_pMemory = this->m_faceCenters.m_Memory.m_pMemory;
      v10 = this->m_faceCenters.m_Size - m_Size - v7;
      this->m_faceCenters.m_pElements = m_pMemory;
      if ( v10 > 0 && v7 > 0 )
      {
        _V_memmove(dest: &m_pMemory[v13], src: &m_pMemory[m_Size], count: 12 * v10);
        v6 = v15;
      }
    }
    p_m_mesh = v14;
  }
  CMesh::CalculateFaceCenters(this: p_m_mesh, pCentersOut: this->m_faceCenters.m_Memory.m_pMemory, nCentersOut: v6);
  CMesh::~CMesh(this: &meshOut);
}

//------------------------------------------------------------------------------
// Address: 0x00403A20
// Name: public: bool CBuilderMesh::Simplify(struct AABB_t __near &,int,float,int,int,float,float,bool __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBuilderMesh::Simplify(
        CBuilderMesh *this,
        AABB_t *Bounds,
        int nTargetGeometrySizeBytes,
        float flBoundsEpsilon,
        int nAtlasTextureSizeX,
        int nAtlasTextureSizeY,
        float flGutterSize,
        float flUVMapThreshold,
        bool *bUVMapped)
{
  int m_nVertexCount; // eax
  int m_nVertexStrideFloats; // ecx
  int m_nIndexCount; // edi
  int v14; // ecx
  int v15; // ebx
  float v16; // xmm0_4
  float v17; // xmm2_4
  float *v18; // eax
  int v19; // ecx
  float *v20; // edi
  int i; // eax
  float *v22; // ecx
  int v23; // edi
  CMesh outputMesh; // [esp+1Ch] [ebp-F0h] BYREF
  CMesh meshWelded; // [esp+4Ch] [ebp-C0h] BYREF
  CMesh meshClean; // [esp+7Ch] [ebp-90h] BYREF
  float flEpsilons[15]; // [esp+ACh] [ebp-60h] BYREF
  mesh_simplifyparams_t params; // [esp+E8h] [ebp-24h] BYREF
  mesh_simplifyweights_t weights; // [esp+FCh] [ebp-10h] BYREF
  int nOriginalVerts; // [esp+104h] [ebp-8h]
  bool bSimplified; // [esp+10Bh] [ebp-1h]

  if ( this->m_Combo.m_nIndicesPerFace == 3 )
  {
    m_nVertexCount = this->m_mesh.m_nVertexCount;
    m_nVertexStrideFloats = this->m_mesh.m_nVertexStrideFloats;
    nOriginalVerts = m_nVertexCount;
    m_nIndexCount = this->m_mesh.m_nIndexCount;
    v14 = 4 * m_nVertexStrideFloats;
    v15 = m_nIndexCount / 3;
    bSimplified = false;
    if ( m_nVertexCount * v14 + 4 * m_nIndexCount > nTargetGeometrySizeBytes )
    {
      v16 = (float)v15 / (float)m_nVertexCount;
      v17 = (float)(v16 * 4.0) * 3.0;
      params.m_flMaxError = 0.0;
      params.m_flIntegrationPenalty = 0.89999998;
      params.m_nMaxTriangleCount = (int)(float)((float)(int)(float)((float)(nTargetGeometrySizeBytes / v14) + v17) * v16);
      params.m_flOpenEdgePenalty = 0.5;
      flEpsilons[0] = 0.5;
      flEpsilons[1] = 0.5;
      flEpsilons[2] = 0.5;
      params.m_nMaxVertexCount = (int)(float)((float)(nTargetGeometrySizeBytes / v14) + v17);
      flEpsilons[3] = 3.4028235e38;
      flEpsilons[4] = 3.4028235e38;
      flEpsilons[5] = 3.4028235e38;
      flEpsilons[6] = 3.4028235e38;
      flEpsilons[7] = 3.4028235e38;
      flEpsilons[8] = 3.4028235e38;
      flEpsilons[9] = 3.4028235e38;
      flEpsilons[10] = 3.4028235e38;
      flEpsilons[11] = 3.4028235e38;
      flEpsilons[12] = 3.4028235e38;
      flEpsilons[13] = 3.4028235e38;
      flEpsilons[14] = 3.4028235e38;
      CMesh::CMesh(this: &meshWelded);
      WeldVertices(
        pMeshOut: &meshWelded,
        inputMesh: &this->m_mesh,
        pEpsilons: flEpsilons,
        nEpsilons: this->m_mesh.m_nVertexStrideFloats);
      CMesh::CMesh(this: &meshClean);
      CleanMesh(pMeshOut: &meshClean, inputMesh: &meshWelded);
      CMesh::FreeAllMemory(this: &this->m_mesh);
      CMesh::FreeAllMemory(this: &meshWelded);
      v18 = (float *)MemAlloc_Alloc(
                       nSize: (unsigned __int64)(unsigned int)meshClean.m_nVertexCount >> 30 != 0
                     ? -1
                     : 4 * meshClean.m_nVertexCount);
      v19 = meshClean.m_nVertexCount;
      v20 = v18;
      for ( i = 0; i < meshClean.m_nVertexCount; ++i )
      {
        v22 = &meshClean.m_pVerts[i * meshClean.m_nVertexStrideFloats];
        if ( (float)(*v22 - Bounds->m_vMinBounds.x) >= 12.0
          && (float)(v22[1] - Bounds->m_vMinBounds.y) >= 12.0
          && (float)(v22[2] - Bounds->m_vMinBounds.z) >= 12.0
          && (float)(Bounds->m_vMaxBounds.x - meshClean.m_pVerts[i * meshClean.m_nVertexStrideFloats]) >= 12.0
          && (float)(Bounds->m_vMaxBounds.y - v22[1]) >= 12.0
          && (float)(Bounds->m_vMaxBounds.z - v22[2]) >= 12.0 )
        {
          v20[i] = 1.0;
        }
        else
        {
          v20[i] = 1000.0;
        }
        v19 = meshClean.m_nVertexCount;
      }
      weights.m_nVertexCount = v19;
      weights.m_pVertexWeights = v20;
      SimplifyMesh(meshOut: &this->m_mesh, input: &meshClean, &params, pWeights: &weights);
      free(pMem: v20);
      _Msg(
        a1: "Simplified\n%d / %d vertices\n%d / %d triangles\n",
        this->m_mesh.m_nVertexCount,
        nOriginalVerts,
        this->m_mesh.m_nIndexCount / 3,
        v15);
      CMesh::FreeAllMemory(this: &meshClean);
      v23 = this->m_mesh.m_nIndexCount / 3;
      if ( this->m_faceCenters.m_Size < v23 )
        CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertMultipleBefore(
          this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&this->m_faceCenters,
          elem: this->m_faceCenters.m_Size,
          num: v23 - this->m_faceCenters.m_Size);
      CMesh::CalculateFaceCenters(
        this: &this->m_mesh,
        pCentersOut: this->m_faceCenters.m_Memory.m_pMemory,
        nCentersOut: v23);
      bSimplified = true;
      CMesh::~CMesh(this: &meshClean);
      CMesh::~CMesh(this: &meshWelded);
    }
    CMesh::CMesh(this: &outputMesh);
    *bUVMapped = CreateUniqueUVParameterization(
                   pMeshOut: &outputMesh,
                   inputMesh: &this->m_mesh,
                   flThreshold: flUVMapThreshold,
                   nAtlasTextureSizeX,
                   nAtlasTextureSizeY,
                   flGutterSize);
    CMesh::FreeAllMemory(this: &this->m_mesh);
    DuplicateMesh(pMeshOut: &this->m_mesh, inputMesh: &outputMesh);
    CMesh::FreeAllMemory(this: &outputMesh);
    _Msg(
      a1: "Unique param:\n%d / %d vertices\n%d / %d triangles\n",
      this->m_mesh.m_nVertexCount,
      nOriginalVerts,
      this->m_mesh.m_nIndexCount / 3,
      v15);
    CMesh::~CMesh(this: &outputMesh);
    return bSimplified;
  }
  else
  {
    _Msg(a1: "Quads not supported yet!");
    return false;
  }
}
