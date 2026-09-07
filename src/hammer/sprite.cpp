// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/sprite.cpp
// Functions: 18
// ============================================================

#include "hammer\sprite.h"

//------------------------------------------------------------------------------
// Address: 0x100A6130
// Name: protected: static bool CSpriteCache::AddSprite(class CSpriteModel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CSpriteCache::AddSprite(CSpriteModel *pSprite, const char *pszSpritePath)
{
  _BYTE *v2; // eax
  const char *v3; // ecx
  int v4; // edx
  char v5; // al
  int v6; // ecx

  CSpriteCache::m_Cache[CSpriteCache::m_nItems].pSprite = pSprite;
  v2 = operator new[](nSize: strlen(pszSpritePath) + 1);
  dword_107A8994[3 * CSpriteCache::m_nItems] = (int)v2;
  if ( v2 == nullptr )
    return 0;
  v3 = pszSpritePath;
  v4 = v2 - pszSpritePath;
  do
  {
    v5 = *v3;
    v3[v4] = *v3;
    ++v3;
  }
  while ( v5 != 0 );
  v6 = 3 * CSpriteCache::m_nItems++;
  dword_107A8998[v6] = 1;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100A61B0
// Name: public: static void CSpriteCache::AddRef(class CSpriteModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CSpriteCache::AddRef(CSpriteModel *pSprite)
{
  int v1; // eax
  SpriteCache_t *i; // ecx

  v1 = 0;
  if ( CSpriteCache::m_nItems > 0 )
  {
    for ( i = CSpriteCache::m_Cache; i->pSprite != pSprite; ++i )
    {
      if ( ++v1 >= CSpriteCache::m_nItems )
        return;
    }
    ++dword_107A8998[3 * v1];
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A61F0
// Name: public: CSpriteModel::CSpriteModel(void)
// Source: json
//------------------------------------------------------------------------------
CSpriteModel *__thiscall CSpriteModel::CSpriteModel(CSpriteModel *this)
{
  this->m_Origin.x = 0.0;
  this->m_Origin.y = 0.0;
  this->m_Origin.z = 0.0;
  this->m_fScale = 1.0;
  this->m_NumFrames = -1;
  this->m_pMaterial = nullptr;
  this->m_bInvert = false;
  this->m_TexUL.x = 0.0;
  this->m_TexUL.y = 1.0;
  this->m_TexLR.x = 1.0;
  this->m_TexLR.y = 0.0;
  this->m_UL.x = 0.0;
  this->m_UL.y = 0.0;
  this->m_LR.x = 0.0;
  this->m_LR.y = 0.0;
  this->m_Normal.x = 0.0;
  this->m_Normal.y = 0.0;
  this->m_Normal.z = 1.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100A6260
// Name: public: void CSpriteModel::SetRenderMode(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpriteModel::SetRenderMode(CSpriteModel *this, int mode)
{
  IMaterialVar *m_pRenderModeVar; // ecx
  IMaterial *v4; // eax

  if ( this->m_pMaterial != nullptr )
  {
    m_pRenderModeVar = this->m_pRenderModeVar;
    if ( m_pRenderModeVar != nullptr && mode != m_pRenderModeVar->GetIntValueInternal(this: m_pRenderModeVar) )
    {
      this->m_pRenderModeVar->SetIntValue(this: this->m_pRenderModeVar, a2: mode);
      v4 = this->m_pMaterial->GetMaterial(this: this->m_pMaterial, a2: 1);
      v4->RecomputeStateSnapshots(this: v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A62B0
// Name: protected: void CSpriteModel::GetSpriteAxes(class QAngle __near &,int,class Vector __near &,class Vector __near &,class Vector __near &,class Vector __near &,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSpriteModel::GetSpriteAxes(
        CSpriteModel *this@<ecx>,
        long double a2@<esi:edi>,
        QAngle *Angles,
        int type,
        Vector *forward,
        Vector *right,
        Vector *up,
        Vector *ViewUp,
        Vector *ViewRight,
        Vector *ViewForward)
{
  float z; // xmm0_4
  int v11; // eax
  Vector *v12; // esi
  float y; // xmm1_4
  float v14; // xmm0_4
  long double v15; // [esp-8h] [ebp-14h]
  Vector tvec; // [esp+0h] [ebp-Ch] BYREF
  float angle; // [esp+14h] [ebp+8h]

  z = Angles->z;
  v11 = type;
  if ( z != 0.0 && type == 2 )
    v11 = 4;
  switch ( v11 )
  {
    case 0:
      v14 = ViewForward->z;
      if ( v14 <= 0.999848 && v14 >= -0.999848 )
      {
        v12 = right;
        up->x = 0.0;
        up->y = 0.0;
        up->z = 1.0;
        right->x = ViewForward->y;
        LODWORD(right->y) = LODWORD(ViewForward->x) ^ _mask__NegFloat_;
        right->z = 0.0;
        goto LABEL_12;
      }
      break;
    case 1:
      tvec.x = -this->m_Origin.x;
      tvec.y = -this->m_Origin.y;
      tvec.z = -this->m_Origin.z;
      VectorNormalize(vec: &tvec);
      if ( tvec.z <= 0.999848 && tvec.z >= -0.999848 )
      {
        v12 = right;
        up->z = 1.0;
        y = tvec.y;
        up->x = 0.0;
        up->y = 0.0;
        right->x = y;
        *(_QWORD *)&right->y = LODWORD(tvec.x) ^ (unsigned int)_mask__NegFloat_;
LABEL_12:
        VectorNormalize(vec: v12);
        LODWORD(forward->x) = LODWORD(v12->y) ^ _mask__NegFloat_;
        forward->y = v12->x;
        forward->z = 0.0;
      }
      break;
    case 2:
      up->x = ViewUp->x;
      right->x = ViewRight->x;
      forward->x = ViewForward->x;
      up->y = ViewUp->y;
      right->y = ViewRight->y;
      forward->y = ViewForward->y;
      up->z = ViewUp->z;
      right->z = ViewRight->z;
      forward->z = ViewForward->z;
      break;
    case 3:
      AngleVectors(angles: Angles, forward, right, up);
      break;
    case 4:
      angle = z * 0.0174532925199433;
      __libm_sse2_sin(x: a2);
      __libm_sse2_cos(x: v15);
      forward->x = ViewForward->x;
      right->x = (float)(ViewUp->x * angle) + (float)(ViewRight->x * angle);
      up->x = (float)(ViewUp->x * angle) - (float)(ViewRight->x * angle);
      forward->y = ViewForward->y;
      right->y = (float)(ViewRight->y * angle) + (float)(ViewUp->y * angle);
      up->y = (float)(ViewUp->y * angle) - (float)(ViewRight->y * angle);
      forward->z = ViewForward->z;
      right->z = (float)(ViewRight->z * angle) + (float)(ViewUp->z * angle);
      up->z = (float)(ViewUp->z * angle) - (float)(ViewRight->z * angle);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A65C0
// Name: public: void CSpriteModel::SetScale(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpriteModel::SetScale(CSpriteModel *this, float fScale)
{
  this->m_fScale = fScale;
}

//------------------------------------------------------------------------------
// Address: 0x100A65E0
// Name: public: void CSpriteModel::SetOrigin(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpriteModel::SetOrigin(CSpriteModel *this, const Vector *v)
{
  this->m_Origin = *v;
}

//------------------------------------------------------------------------------
// Address: 0x100A6600
// Name: public: void CSpriteModel::GetOrigin(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpriteModel::GetOrigin(CSpriteModel *this, Vector *v)
{
  *v = this->m_Origin;
}

//------------------------------------------------------------------------------
// Address: 0x100A6620
// Name: public: void CSpriteModel::SetInvert(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpriteModel::SetInvert(CSpriteModel *this, bool b)
{
  this->m_bInvert = b;
}

//------------------------------------------------------------------------------
// Address: 0x100A6630
// Name: public: void CSpriteModel::SetAngles(class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpriteModel::SetAngles(CSpriteModel *this, const QAngle *pfAngles)
{
  this->m_Angles = *pfAngles;
}

//------------------------------------------------------------------------------
// Address: 0x100A6650
// Name: public: void CSpriteModel::SetMaterialPrimitiveType(enum MaterialPrimitiveType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpriteModel::SetMaterialPrimitiveType(CSpriteModel *this, MaterialPrimitiveType_t type)
{
  this->m_MaterialPrimitiveType = type;
}

//------------------------------------------------------------------------------
// Address: 0x100A6660
// Name: public: void CSpriteModel::Bind(class CRender __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpriteModel::Bind(CSpriteModel *this, CRender *pRender, int frame)
{
  if ( this->m_pMaterial != nullptr && this->m_pFrameVar != nullptr )
  {
    this->m_pFrameVar->SetIntValue(this: this->m_pFrameVar, a2: frame);
    CRender::BindTexture(this: pRender, pTexture: this->m_pMaterial);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A66A0
// Name: public: int CSpriteModel::GetFrameCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSpriteModel::GetFrameCount(CSpriteModel *this)
{
  CMaterial *m_pMaterial; // ecx
  int v3; // eax

  if ( this->m_NumFrames < 0 )
  {
    m_pMaterial = this->m_pMaterial;
    if ( m_pMaterial != nullptr )
    {
      v3 = (int)m_pMaterial->GetMaterial(this: m_pMaterial, a2: true);
      this->m_NumFrames = (*(int (__thiscall **)(int))(*(_DWORD *)v3 + 24))(a1: v3);
    }
  }
  return this->m_NumFrames < 0 ? 0 : this->m_NumFrames;
}

//------------------------------------------------------------------------------
// Address: 0x100A66E0
// Name: public: static void CSpriteCache::Release(class CSpriteModel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CSpriteCache::Release(CSpriteModel *pSprite)
{
  int v1; // eax
  SpriteCache_t *i; // ecx
  unsigned int v3; // esi
  int v4; // eax

  v1 = 0;
  if ( CSpriteCache::m_nItems > 0 )
  {
    for ( i = CSpriteCache::m_Cache; i->pSprite != pSprite; ++i )
    {
      if ( ++v1 >= CSpriteCache::m_nItems )
        return;
    }
    --dword_107A8998[3 * v1];
    v3 = 3 * v1;
    if ( dword_107A8998[3 * v1] <= 0 )
    {
      operator delete(p: (void *)dword_107A8994[3 * v1]);
      if ( CSpriteCache::m_Cache[v3 / 3].pSprite != nullptr )
        operator delete(p: CSpriteCache::m_Cache[v3 / 3].pSprite);
      --CSpriteCache::m_nItems;
      v4 = 3 * CSpriteCache::m_nItems;
      CSpriteCache::m_Cache[v3 / 3].pSprite = CSpriteCache::m_Cache[CSpriteCache::m_nItems].pSprite;
      dword_107A8994[v3] = dword_107A8994[v4];
      dword_107A8998[v3] = dword_107A8998[v4];
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A6820
// Name: public: void CSpriteModel::DrawSprite3D(class CRender3D __near *,unsigned char __near * const)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSpriteModel::DrawSprite3D(
        CSpriteModel *this@<ecx>,
        long double a2@<esi:edi>,
        CRender3D *pRender,
        unsigned __int8 *color)
{
  float v4; // xmm4_4
  float v5; // xmm0_4
  float v6; // xmm5_4
  float v7; // xmm6_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm3_4
  float v11; // xmm2_4
  char v12; // al
  float v13; // xmm0_4
  float v14; // xmm0_4
  float v15; // xmm0_4
  IMatRenderContext *(__thiscall *GetRenderContext)(IMaterialSystem *); // eax
  IMatRenderContext *v17; // eax
  float *m_pCurrNormal; // eax
  float *m_pCurrPosition; // eax
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  float *v23; // eax
  int v24; // ecx
  unsigned int v25; // edx
  float *v26; // eax
  float *v27; // eax
  float v28; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm2_4
  float *v31; // eax
  double v32; // st7
  float *v33; // eax
  float v34; // xmm1_4
  float v35; // xmm2_4
  float x; // xmm0_4
  float *v37; // eax
  float *v38; // eax
  int m_nVertexCount; // eax
  IMatRenderContext *v40; // esi
  Vector spritez; // [esp+Ch] [ebp-260h] BYREF
  CMeshBuilder meshBuilder; // [esp+18h] [ebp-254h] BYREF
  Vector ViewRight; // [esp+200h] [ebp-6Ch] BYREF
  Vector ViewUp; // [esp+20Ch] [ebp-60h] BYREF
  Vector ViewForward; // [esp+218h] [ebp-54h] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+224h] [ebp-48h]
  IMatRenderContext *v47; // [esp+228h] [ebp-44h]
  Vector2D texlr; // [esp+22Ch] [ebp-40h]
  Vector2D texul; // [esp+234h] [ebp-38h]
  Vector spritex; // [esp+23Ch] [ebp-30h] BYREF
  Vector spritey; // [esp+248h] [ebp-24h] BYREF
  Vector corner; // [esp+254h] [ebp-18h]
  int v53; // [esp+268h] [ebp-4h]
  IMesh *pMesh; // [esp+274h] [ebp+8h]

  LODWORD(a2) = this;
  CRender::GetViewUp(this: pRender, &ViewUp);
  CRender::GetViewRight(this: pRender, &ViewRight);
  CRender::GetViewForward(this: pRender, &ViewForward);
  CSpriteModel::GetSpriteAxes(
    this: (CSpriteModel *)LODWORD(a2),
    a2,
    Angles: (QAngle *)(LODWORD(a2) + 24),
    type: *(_DWORD *)(LODWORD(a2) + 60),
    forward: &spritez,
    right: &spritex,
    up: &spritey,
    &ViewUp,
    &ViewRight,
    &ViewForward);
  v4 = *(float *)(LODWORD(a2) + 36);
  v5 = v4 * *(float *)(LODWORD(a2) + 92);
  v6 = (float)(spritex.y * v5) + *(float *)(LODWORD(a2) + 4);
  v7 = (float)(spritex.z * v5) + *(float *)(LODWORD(a2) + 8);
  v8 = *(float *)(LODWORD(a2) + 96) * v4;
  v9 = *(float *)(LODWORD(a2) + 104) * v4;
  v10 = (float)(*(float *)(LODWORD(a2) + 100) * v4) - v5;
  corner.x = (float)(spritey.x * v9) + (float)((float)(spritex.x * v5) + *(float *)LODWORD(a2));
  spritex.x = spritex.x * v10;
  spritex.y = spritex.y * v10;
  corner.y = (float)(spritey.y * v9) + v6;
  spritex.z = spritex.z * v10;
  v11 = v8 - v9;
  corner.z = (float)(spritey.z * v9) + v7;
  v12 = *(_BYTE *)(LODWORD(a2) + 72);
  spritey.x = spritey.x * v11;
  v13 = *(float *)(LODWORD(a2) + 76);
  spritey.y = spritey.y * v11;
  spritey.z = spritey.z * v11;
  texul.x = v13;
  if ( v12 != 0 )
    v14 = *(float *)(LODWORD(a2) + 88);
  else
    v14 = *(float *)(LODWORD(a2) + 80);
  texul.y = v14;
  texlr.x = *(float *)(LODWORD(a2) + 84);
  if ( v12 != 0 )
    v15 = *(float *)(LODWORD(a2) + 80);
  else
    v15 = *(float *)(LODWORD(a2) + 88);
  GetRenderContext = materials->GetRenderContext;
  texlr.y = v15;
  v17 = GetRenderContext(this: materials);
  HIDWORD(a2) = v17;
  v47 = v17;
  pRenderContext.m_pObject = v17;
  v53 = 0;
  if ( v17 != nullptr )
    v17->BeginRender(this: v17);
  v53 = 1;
  CRender::BindTexture(this: pRender, pTexture: *(IEditorTexture **)(LODWORD(a2) + 44));
  pMesh = (IMesh *)(*(int (__thiscall **)(_DWORD, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)HIDWORD(a2) + 228))(
                     a1: HIDWORD(a2),
                     a2: 1,
                     a3: 0,
                     a4: 0,
                     a5: 0);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  LOBYTE(v53) = 2;
  CMeshBuilder::Begin(this: &meshBuilder, pMesh, type: *(MaterialPrimitiveType_t *)(LODWORD(a2) + 40), numPrimitives: 4);
  *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = corner;
  *(Vector2D *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = texul;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = color[2] | ((color[1] | ((*color | 0xFFFFFF00) << 8)) << 8);
  m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pCurrNormal;
  *meshBuilder.m_VertexBuilder.m_pCurrNormal = *(float *)(LODWORD(a2) + 12);
  m_pCurrNormal[1] = *(float *)(LODWORD(a2) + 16);
  m_pCurrNormal[2] = *(float *)(LODWORD(a2) + 20);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  v20 = spritey.x + corner.x;
  v21 = spritey.y + corner.y;
  v22 = spritey.z + corner.z;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = spritey.x + corner.x;
  m_pCurrPosition[1] = v21;
  m_pCurrPosition[2] = v22;
  v23 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  corner.x = v20;
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = texul.x;
  v23[1] = texlr.y;
  v24 = color[1];
  v25 = (*color | 0xFFFFFF00) << 8;
  corner.y = v21;
  corner.z = v22;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = color[2] | ((v24 | v25) << 8);
  v26 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
  *meshBuilder.m_VertexBuilder.m_pCurrNormal = *(float *)(LODWORD(a2) + 12);
  v26[1] = *(float *)(LODWORD(a2) + 16);
  v26[2] = *(float *)(LODWORD(a2) + 20);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  v27 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  v28 = corner.x + spritex.x;
  v29 = corner.y + spritex.y;
  v30 = corner.z + spritex.z;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = corner.x + spritex.x;
  v27[1] = v29;
  v27[2] = v30;
  corner.x = v28;
  *(Vector2D *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = texlr;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = color[2] | ((color[1] | ((*color | 0xFFFFFF00) << 8)) << 8);
  v31 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
  v32 = *(float *)(LODWORD(a2) + 12);
  corner.y = v29;
  *meshBuilder.m_VertexBuilder.m_pCurrNormal = v32;
  corner.z = v30;
  v31[1] = *(float *)(LODWORD(a2) + 16);
  v31[2] = *(float *)(LODWORD(a2) + 20);
  CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
  v33 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
  v34 = corner.y - spritey.y;
  v35 = corner.z - spritey.z;
  *meshBuilder.m_VertexBuilder.m_pCurrPosition = corner.x - spritey.x;
  x = texlr.x;
  v33[1] = v34;
  v33[2] = v35;
  v37 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
  *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = x;
  v37[1] = texul.y;
  *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = color[2] | ((color[1] | ((*color | 0xFFFFFF00) << 8)) << 8);
  v38 = meshBuilder.m_VertexBuilder.m_pCurrNormal;
  *meshBuilder.m_VertexBuilder.m_pCurrNormal = *(float *)(LODWORD(a2) + 12);
  v38[1] = *(float *)(LODWORD(a2) + 16);
  v38[2] = *(float *)(LODWORD(a2) + 20);
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
  LOBYTE(v53) = 1;
  CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
  v53 = 3;
  v40 = v47;
  v47->EndRender(this: v47);
  v53 = -1;
  v40->Release(this: v40);
}

//------------------------------------------------------------------------------
// Address: 0x100A8140
// Name: class CSpriteDataCache __near * LookupSpriteDataCache(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSpriteDataCache *__usercall LookupSpriteDataCache@<eax>(const char *a1@<edi>, int a2@<esi>, const char *pSpritePath)
{
  int v3; // eax
  CMaterial **v4; // esi
  CMaterial *Material; // eax
  int v6; // eax
  CMaterial *v7; // ecx
  int v8; // eax
  CMaterial *v9; // ecx
  int v10; // eax
  int v11; // eax
  bool v12; // zf
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  CMaterial *v17; // ecx
  int v18; // eax
  char filename[260]; // [esp+0h] [ebp-110h] BYREF
  CUtlMap<char const *,CSpriteDataCache *,int>::Node_t search; // [esp+104h] [ebp-Ch] BYREF
  bool bFound; // [esp+10Fh] [ebp-1h] BYREF

  V_strncpy(pDest: filename, pSrc: pSpritePath, maxLen: 260);
  V_FixSlashes(pname: filename, separator: 92);
  search.key = filename;
  v3 = CUtlRBTree<CUtlMap<char const *,CSpriteDataCache *,int>::Node_t,int,CUtlMap<char const *,CSpriteDataCache *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSpriteDataCache *,int>::Node_t,int>,int>>::Find(
         this: &g_SpriteDataCache.m_Elements.m_Tree,
         &search);
  if ( v3 != -1 )
    return g_SpriteDataCache.m_Elements.m_Tree.m_Elements.m_pMemory[v3].m_Data.elem;
  v4 = (CMaterial **)operator new(nSize: 0x20u);
  *(_QWORD *)v4 = 0;
  *((_QWORD *)v4 + 1) = 0;
  *((_QWORD *)v4 + 2) = 0;
  *((_QWORD *)v4 + 3) = 0;
  search.key = _strdup(string: filename);
  search.elem = (CSpriteDataCache *)v4;
  CUtlRBTree<CUtlMap<char const *,CSpriteDataCache *,int>::Node_t,int,CUtlMap<char const *,CSpriteDataCache *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSpriteDataCache *,int>::Node_t,int>,int>>::Insert(
    this: &g_SpriteDataCache.m_Elements.m_Tree,
    a2: a1,
    insert: &search);
  Material = CMaterial::CreateMaterial(pszMaterialName: filename, bLoadImmediately: true, pFound: nullptr);
  *v4 = Material;
  if ( Material != nullptr && Material->GetMaterial(this: Material, a2: true) != nullptr )
  {
    v6 = ((int (__thiscall *)(CMaterial *, int))(*v4)->GetWidth)(a1: *v4, a2);
    v7 = *v4;
    v4[5] = (CMaterial *)v6;
    v8 = v7->GetHeight(this: v7);
    v9 = *v4;
    v4[6] = (CMaterial *)v8;
    v10 = (int)v9->GetMaterial(this: v9, a2: true);
    v11 = (*(int (__thiscall **)(int, const char *, bool *, int))(*(_DWORD *)v10 + 44))(
            a1: v10,
            a2: "$spriteFrame",
            a3: &bFound,
            a4: 1);
    v12 = !bFound;
    v4[1] = (CMaterial *)v11;
    if ( v12 )
      v4[1] = nullptr;
    v13 = (int)(*v4)->GetMaterial(this: *v4, a2: true);
    v14 = (*(int (__thiscall **)(int, const char *, bool *, int))(*(_DWORD *)v13 + 44))(
            a1: v13,
            a2: "$spriterendermode",
            a3: &bFound,
            a4: 1);
    v12 = !bFound;
    v4[2] = (CMaterial *)v14;
    if ( v12 )
      v4[2] = nullptr;
    v15 = (int)(*v4)->GetMaterial(this: *v4, a2: true);
    v16 = (*(int (__thiscall **)(int, const char *, int, _DWORD))(*(_DWORD *)v15 + 44))(
            a1: v15,
            a2: "$spriteOrientation",
            a3: (int)v4 + 29,
            a4: 0);
    v17 = *v4;
    v4[3] = (CMaterial *)v16;
    v18 = (int)v17->GetMaterial(this: v17, a2: true);
    v4[4] = (CMaterial *)(*(int (__thiscall **)(int, const char *, CMaterial **, int))(*(_DWORD *)v18 + 44))(
                           a1: v18,
                           a2: "$spriteorigin",
                           a3: v4 + 7,
                           a4: 1);
  }
  return (CSpriteDataCache *)v4;
}

//------------------------------------------------------------------------------
// Address: 0x100A82E0
// Name: public: bool CSpriteModel::LoadSprite(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CSpriteModel::LoadSprite@<al>(
        CSpriteModel *this@<ecx>,
        const char *a2@<edi>,
        const char *pszSpritePath)
{
  CSpriteDataCache *v4; // edi
  CMaterial *m_pMaterial; // ecx
  IMaterialVar *m_pOriginVar; // ecx
  int m_Width; // eax
  float m_Height; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  Vector originVarValue; // [esp+8h] [ebp-Ch] BYREF

  v4 = LookupSpriteDataCache(a1: a2, a2: (int)this, pSpritePath: pszSpritePath);
  m_pMaterial = v4->m_pMaterial;
  this->m_pMaterial = v4->m_pMaterial;
  if ( m_pMaterial == nullptr || m_pMaterial->GetMaterial(this: m_pMaterial, a2: true) == nullptr )
    return 0;
  this->m_Width = v4->m_Width;
  this->m_Height = v4->m_Height;
  this->m_pFrameVar = v4->m_pFrameVar;
  this->m_pRenderModeVar = v4->m_pRenderModeVar;
  if ( v4->m_bOrientationVarFound )
    this->m_Type = v4->m_pOrientationVar->GetIntValueInternal(this: v4->m_pOrientationVar);
  else
    this->m_Type = 0;
  m_pOriginVar = v4->m_pOriginVar;
  if ( v4->m_bOriginVarFound && (*((_BYTE *)m_pOriginVar + 28) & 0xF) == 2 )
  {
    m_pOriginVar->GetVecValueInternal(this: m_pOriginVar, a2: &originVarValue.x, a3: 3);
    m_Width = this->m_Width;
    m_Height = (float)this->m_Height;
    v9 = (float)-m_Width * originVarValue.x;
    v10 = m_Height * originVarValue.y;
  }
  else
  {
    m_Width = this->m_Width;
    m_Height = (float)this->m_Height;
    v9 = (float)-m_Width * 0.5;
    v10 = m_Height * 0.5;
  }
  this->m_UL.y = v10;
  this->m_LR.y = v10 - m_Height;
  this->m_UL.x = v9;
  this->m_LR.x = (float)m_Width + v9;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100A83F0
// Name: public: static class CSpriteModel __near * CSpriteCache::CreateSprite(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSpriteModel *__cdecl CSpriteCache::CreateSprite(const char *pszSpritePath)
{
  int v1; // esi
  const char **v2; // edi
  _DWORD *v3; // eax
  CSpriteModel *v4; // esi

  v1 = 0;
  if ( CSpriteCache::m_nItems <= 0 )
  {
LABEL_5:
    v3 = operator new(nSize: 0x6Cu);
    if ( v3 != nullptr )
    {
      *v3 = 0;
      v3[1] = 0;
      v3[2] = 0;
      v3[9] = 1065353216;
      v3[11] = 0;
      v3[14] = -1;
      *((_BYTE *)v3 + 72) = 0;
      v3[19] = 0;
      v3[20] = 1065353216;
      v3[21] = 1065353216;
      v3[22] = 0;
      v3[23] = 0;
      v3[24] = 0;
      v3[25] = 0;
      v3[26] = 0;
      v3[3] = 0;
      v3[4] = 0;
      v3[5] = 1065353216;
      v4 = (CSpriteModel *)v3;
    }
    else
    {
      v4 = nullptr;
    }
    if ( v4 != nullptr )
    {
      if ( CSpriteModel::LoadSprite(this: v4, a2: pszSpritePath, pszSpritePath) == 0 )
      {
        operator delete(p: v4);
        return nullptr;
      }
      CSpriteCache::AddSprite(pSprite: v4, pszSpritePath);
    }
    return v4;
  }
  else
  {
    v2 = (const char **)dword_107A8994;
    while ( _V_stricmp(s1: pszSpritePath, s2: *v2) != 0 )
    {
      ++v1;
      v2 += 3;
      if ( v1 >= CSpriteCache::m_nItems )
        goto LABEL_5;
    }
    ++dword_107A8998[3 * v1];
    return CSpriteCache::m_Cache[v1].pSprite;
  }
}
