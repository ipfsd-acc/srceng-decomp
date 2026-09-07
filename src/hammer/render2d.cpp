// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/render2d.cpp
// Functions: 9
// ============================================================

#include "hammer\render2d.h"

//------------------------------------------------------------------------------
// Address: 0x10095250
// Name: public: CRender2D::CRender2D(void)
// Source: json
//------------------------------------------------------------------------------
CRender2D *__thiscall CRender2D::CRender2D(CRender2D *this)
{
  CRender::CRender(this);
  this->__vftable = (CRender2D_vtbl *)&CRender2D::`vftable';
  this->m_vCurLine.x = 0.0;
  this->m_vCurLine.y = 0.0;
  this->m_vCurLine.z = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100952C0
// Name: public: virtual CRender2D::~CRender2D(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender2D::~CRender2D(CRender2D *this)
{
  this->__vftable = (CRender2D_vtbl *)&CRender2D::`vftable';
  CRender::~CRender(this);
}

//------------------------------------------------------------------------------
// Address: 0x10095300
// Name: public: void CRender2D::MoveTo(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender2D::MoveTo(CRender2D *this, const Vector *vPoint)
{
  this->m_vCurLine = *vPoint;
}

//------------------------------------------------------------------------------
// Address: 0x10095330
// Name: public: void CRender2D::DrawLineTo(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender2D::DrawLineTo(CRender2D *this, const Vector *vPoint)
{
  Vector *p_m_vCurLine; // esi

  p_m_vCurLine = &this->m_vCurLine;
  CRender::DrawLine(this, a2: (int)vPoint, a3: (int)&this->m_vCurLine, vStart: &this->m_vCurLine, vEnd: vPoint);
  *p_m_vCurLine = *vPoint;
}

//------------------------------------------------------------------------------
// Address: 0x10095360
// Name: public: void CRender2D::DrawCircle(class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CRender2D::DrawCircle(
        CRender2D *this@<ecx>,
        unsigned int a2@<ebx>,
        unsigned int a3@<edi>,
        const Vector *vCenter,
        float fRadius)
{
  CCamera *Camera; // eax
  Vector ViewForward; // [esp+4h] [ebp-Ch] BYREF

  Camera = CRender::GetCamera(this);
  CCamera::GetViewForward(this: Camera, &ViewForward);
  CRender::DrawCircle(this, a2, a3, vCenter, vNormal: &ViewForward, flRadius: fRadius, nSegments: 32);
}

//------------------------------------------------------------------------------
// Address: 0x10095400
// Name: public: void CRender2D::DrawRectangle(class Vector const __near &,class Vector const __near &,bool,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender2D::DrawRectangle(
        CRender2D *this,
        const Vector *vMins,
        const Vector *vMaxs,
        bool bFill,
        int extent)
{
  float x; // xmm2_4
  float v7; // xmm4_4
  float y; // xmm1_4
  float v9; // xmm3_4
  char v10; // bl
  Vector2D ptMin; // [esp+4h] [ebp-10h] BYREF
  Vector2D ptMax; // [esp+Ch] [ebp-8h] BYREF

  CRender::TransformPoint(this, vClient: &ptMin, vWorld: vMins);
  CRender::TransformPoint(this, vClient: &ptMax, vWorld: vMaxs);
  x = ptMin.x;
  v7 = ptMax.x;
  if ( ptMin.x > ptMax.x )
  {
    x = ptMax.x;
    v7 = ptMin.x;
    ptMin.x = ptMax.x;
    ptMax.x = v7;
  }
  y = ptMin.y;
  v9 = ptMax.y;
  if ( ptMin.y > ptMax.y )
  {
    y = ptMax.y;
    v9 = ptMin.y;
    ptMin.y = ptMax.y;
    ptMax.y = v9;
  }
  if ( extent != 0 )
  {
    ptMin.y = y - (float)extent;
    ptMin.x = x - (float)extent;
    ptMax.x = (float)extent + v7;
    ptMax.y = (float)extent + v9;
  }
  v10 = CRender::BeginClientSpace(this, a2: (int)this);
  if ( bFill )
    CRender::DrawFilledRect(this, ul: &ptMin, lr: &ptMax, pColor: (unsigned __int8 *)&this->m_DrawColor, bBorder: false);
  else
    CRender::DrawRect(this, ul: &ptMin, lr: &ptMax, pColor: (unsigned __int8 *)&this->m_DrawColor);
  if ( v10 != 0 )
    CRender::EndClientSpace(this);
}

//------------------------------------------------------------------------------
// Address: 0x100954F0
// Name: public: virtual void CRender2D::DrawBox(class Vector const __near &,class Vector const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRender2D::DrawBox(CRender2D *this, const Vector *vMins, const Vector *vMaxs, bool bFill)
{
  int v5; // eax
  Vector points[8]; // [esp+Ch] [ebp-60h] BYREF

  PointsFromBox(mins: vMins, maxs: vMaxs, points);
  CMeshBuilder::Begin(this: &this->meshBuilder, pMesh: this->m_pMesh, type: MATERIAL_LINE_LOOP, numPrimitives: 6);
  *(Vector *)this->meshBuilder.m_VertexBuilder.m_pCurrPosition = points[0];
  *(_DWORD *)this->meshBuilder.m_VertexBuilder.m_pCurrColor = this->m_DrawColor._color[2]
                                                            | ((this->m_DrawColor._color[1]
                                                              | ((this->m_DrawColor._color[0]
                                                                | (this->m_DrawColor._color[3] << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &this->meshBuilder.m_VertexBuilder);
  *(Vector *)this->meshBuilder.m_VertexBuilder.m_pCurrPosition = points[4];
  *(_DWORD *)this->meshBuilder.m_VertexBuilder.m_pCurrColor = this->m_DrawColor._color[2]
                                                            | ((this->m_DrawColor._color[1]
                                                              | ((this->m_DrawColor._color[0]
                                                                | (this->m_DrawColor._color[3] << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &this->meshBuilder.m_VertexBuilder);
  *(Vector *)this->meshBuilder.m_VertexBuilder.m_pCurrPosition = points[6];
  *(_DWORD *)this->meshBuilder.m_VertexBuilder.m_pCurrColor = this->m_DrawColor._color[2]
                                                            | ((this->m_DrawColor._color[1]
                                                              | ((this->m_DrawColor._color[0]
                                                                | (this->m_DrawColor._color[3] << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &this->meshBuilder.m_VertexBuilder);
  *(Vector *)this->meshBuilder.m_VertexBuilder.m_pCurrPosition = points[7];
  *(_DWORD *)this->meshBuilder.m_VertexBuilder.m_pCurrColor = this->m_DrawColor._color[2]
                                                            | ((this->m_DrawColor._color[1]
                                                              | ((this->m_DrawColor._color[0]
                                                                | (this->m_DrawColor._color[3] << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &this->meshBuilder.m_VertexBuilder);
  *(Vector *)this->meshBuilder.m_VertexBuilder.m_pCurrPosition = points[3];
  *(_DWORD *)this->meshBuilder.m_VertexBuilder.m_pCurrColor = this->m_DrawColor._color[2]
                                                            | ((this->m_DrawColor._color[1]
                                                              | ((this->m_DrawColor._color[0]
                                                                | (this->m_DrawColor._color[3] << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &this->meshBuilder.m_VertexBuilder);
  *(Vector *)this->meshBuilder.m_VertexBuilder.m_pCurrPosition = points[1];
  *(_DWORD *)this->meshBuilder.m_VertexBuilder.m_pCurrColor = this->m_DrawColor._color[2]
                                                            | ((this->m_DrawColor._color[1]
                                                              | ((this->m_DrawColor._color[0]
                                                                | (this->m_DrawColor._color[3] << 8)) << 8)) << 8);
  CVertexBuilder::AdvanceVertex(this: &this->meshBuilder.m_VertexBuilder);
  if ( this->meshBuilder.m_bGenerateIndices )
  {
    v5 = CMeshBuilder::IndicesFromVertices(
           this: &this->meshBuilder,
           type: this->meshBuilder.m_Type,
           nVertexCount: this->meshBuilder.m_VertexBuilder.m_nVertexCount);
    CIndexBuilder::GenerateIndices(
      this: &this->meshBuilder.m_IndexBuilder,
      primitiveType: this->meshBuilder.m_Type,
      nIndexCount: v5);
  }
  this->meshBuilder.m_pMesh->UnlockMesh(
    this: this->meshBuilder.m_pMesh,
    a2: this->meshBuilder.m_VertexBuilder.m_nVertexCount,
    a3: this->meshBuilder.m_IndexBuilder.m_nIndexCount,
    a4: &this->meshBuilder);
  this->meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  this->meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
  this->meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
  this->meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  this->meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  this->meshBuilder.m_pMesh = nullptr;
  this->m_pMesh->Draw_2(this: this->m_pMesh, a2: -1, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10095800
// Name: _CompareHits
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl CompareHits(_DWORD *pHit1, _DWORD *pHit2)
{
  unsigned int v2; // eax
  unsigned int v3; // ecx

  v2 = pHit1[2];
  v3 = pHit2[2];
  if ( v3 <= v2 )
    return v3 < v2;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10095820
// Name: _CompareHitsReverse
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl CompareHitsReverse(_DWORD *pHit1, _DWORD *pHit2)
{
  unsigned int v2; // eax
  unsigned int v3; // ecx

  v2 = pHit1[2];
  v3 = pHit2[2];
  if ( v2 <= v3 )
    return v2 < v3;
  else
    return -1;
}
