// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/stocksolids.cpp
// Functions: 14
// ============================================================

#include "hammer\stocksolids.h"

//------------------------------------------------------------------------------
// Address: 0x100AE050
// Name: public: StockSolid::~StockSolid(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StockSolid::~StockSolid(StockSolid *this)
{
  StockSolid::STSDATAFIELD *pFields; // eax

  pFields = this->pFields;
  this->__vftable = (StockSolid_vtbl *)&StockSolid::`vftable';
  if ( pFields != nullptr )
  {
    operator delete(p: pFields);
    this->pFields = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AE080
// Name: public: void StockSolid::SetFieldData(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StockSolid::SetFieldData(StockSolid *this, int iIndex, int iData)
{
  this->pFields[iIndex].iValue = iData;
}

//------------------------------------------------------------------------------
// Address: 0x100AE0A0
// Name: public: virtual void StockBlock::SetFromBox(class BoundBox __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StockBlock::SetFromBox(StockBlock *this, BoundBox *pBox)
{
  Vector o; // [esp+0h] [ebp-Ch] BYREF

  this->pFields->iValue = (int)(float)((float)(pBox->bmaxs.x - pBox->bmins.x) + 0.5);
  this->pFields[1].iValue = (int)(float)((float)(pBox->bmaxs.y - pBox->bmins.y) + 0.5);
  this->pFields[2].iValue = (int)(float)((float)(pBox->bmaxs.z - pBox->bmins.z) + 0.5);
  BoundBox::GetBoundsCenter(this: pBox, ptdest: &o);
  this->origin = o;
}

//------------------------------------------------------------------------------
// Address: 0x100AE140
// Name: public: virtual void StockBlock::CreateMapSolid(class CMapSolid __near *,enum TextureAlignment_t)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall StockBlock::CreateMapSolid(StockBlock *this, CMapSolid *pSolid, TextureAlignment_t eAlignment)
{
  __m128i v4; // xmm7
  float x; // xmm4_4
  float y; // xmm5_4
  float z; // xmm2_4
  float v8; // xmm6_4
  float v9; // xmm0_4
  float v10; // xmm4_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm3_4
  float v14; // xmm5_4
  float v15; // xmm2_4
  bool v16; // [esp-4h] [ebp-220h]
  bool v17; // [esp-4h] [ebp-220h]
  bool v18; // [esp-4h] [ebp-220h]
  bool v19; // [esp-4h] [ebp-220h]
  bool v20; // [esp-4h] [ebp-220h]
  bool v21; // [esp-4h] [ebp-220h]
  CMapFace Face; // [esp+4h] [ebp-218h] BYREF
  float fWidth; // [esp+1C0h] [ebp-5Ch]
  float fHeight; // [esp+1C4h] [ebp-58h]
  _BYTE bmaxs[24]; // [esp+1C8h] [ebp-54h] OVERLAPPED
  Vector Points[4]; // [esp+1E0h] [ebp-3Ch] BYREF
  int v27; // [esp+218h] [ebp-4h]

  CMapFace::CMapFace(this: &Face);
  v27 = 0;
  v4 = _mm_cvtsi32_si128(this->pFields[2].iValue);
  x = this->origin.x;
  y = this->origin.y;
  z = this->origin.z;
  v8 = (float)this->pFields[1].iValue * 0.5;
  fWidth = (float)this->pFields->iValue * 0.5;
  *(float *)v4.m128i_i32 = _mm_cvtepi32_ps(v4).m128_f32[0] * 0.5;
  v9 = x;
  v10 = (float)(x + fWidth) + this->cofs.x;
  v11 = (float)(v9 - fWidth) + this->cofs.x;
  v12 = (float)(y - v8) + this->cofs.y;
  v13 = (float)(z - *(float *)v4.m128i_i32) + this->cofs.z;
  v14 = (float)(y + v8) + this->cofs.y;
  v15 = (float)(z + *(float *)v4.m128i_i32) + this->cofs.z;
  v16 = (*((_BYTE *)pSolid + 568) & 2) != 0;
  fHeight = *(float *)v4.m128i_i32;
  *(_QWORD *)&bmaxs[12] = __PAIR64__(LODWORD(v12), LODWORD(v11));
  *(float *)&bmaxs[20] = v13;
  *(float *)bmaxs = v10;
  *(float *)&bmaxs[4] = v14;
  *(float *)&bmaxs[8] = v15;
  Points[0].x = v11;
  Points[0].y = v14;
  Points[0].z = v15;
  Points[1].x = v10;
  Points[1].y = v14;
  Points[1].z = v15;
  Points[2].x = v10;
  Points[2].y = v12;
  Points[2].z = v15;
  Points[3].x = v11;
  Points[3].y = v12;
  Points[3].z = v15;
  CMapFace::CreateFace(this: &Face, pPoints: Points, _nPoints: 4, bIsCordonFace: v16);
  CMapSolid::AddFace(this: pSolid, pFace: &Face);
  v17 = (*((_BYTE *)pSolid + 568) & 2) != 0;
  Points[0].z = *(float *)&bmaxs[20];
  Points[1].z = *(float *)&bmaxs[20];
  Points[2].z = *(float *)&bmaxs[20];
  Points[3].z = *(float *)&bmaxs[20];
  CMapFace::CreateFace(this: &Face, pPoints: Points, _nPoints: -4, bIsCordonFace: v17);
  CMapSolid::AddFace(this: pSolid, pFace: &Face);
  v18 = (*((_BYTE *)pSolid + 568) & 2) != 0;
  Points[0].x = *(float *)&bmaxs[12];
  Points[0].y = *(float *)&bmaxs[4];
  Points[0].z = *(float *)&bmaxs[8];
  *(_QWORD *)&Points[1].x = *(_QWORD *)&bmaxs[12];
  Points[1].z = *(float *)&bmaxs[8];
  Points[2] = *(Vector *)&bmaxs[12];
  Points[3].x = *(float *)&bmaxs[12];
  Points[3].y = *(float *)&bmaxs[4];
  Points[3].z = *(float *)&bmaxs[20];
  CMapFace::CreateFace(this: &Face, pPoints: Points, _nPoints: 4, bIsCordonFace: v18);
  CMapSolid::AddFace(this: pSolid, pFace: &Face);
  v19 = (*((_BYTE *)pSolid + 568) & 2) != 0;
  Points[0].x = *(float *)bmaxs;
  Points[1].x = *(float *)bmaxs;
  Points[2].x = *(float *)bmaxs;
  Points[3].x = *(float *)bmaxs;
  CMapFace::CreateFace(this: &Face, pPoints: Points, _nPoints: -4, bIsCordonFace: v19);
  CMapSolid::AddFace(this: pSolid, pFace: &Face);
  v20 = (*((_BYTE *)pSolid + 568) & 2) != 0;
  Points[0].x = *(float *)bmaxs;
  Points[0].y = *(float *)&bmaxs[4];
  *(_QWORD *)&Points[0].z = *(_QWORD *)&bmaxs[8];
  Points[1].y = *(float *)&bmaxs[4];
  *(_QWORD *)&Points[1].z = *(_QWORD *)&bmaxs[8];
  Points[2].y = *(float *)&bmaxs[4];
  Points[2].z = *(float *)&bmaxs[20];
  Points[3].x = *(float *)bmaxs;
  Points[3].y = *(float *)&bmaxs[4];
  Points[3].z = *(float *)&bmaxs[20];
  CMapFace::CreateFace(this: &Face, pPoints: Points, _nPoints: 4, bIsCordonFace: v20);
  CMapSolid::AddFace(this: pSolid, pFace: &Face);
  v21 = (*((_BYTE *)pSolid + 568) & 2) != 0;
  Points[0].y = *(float *)&bmaxs[16];
  Points[1].y = *(float *)&bmaxs[16];
  Points[2].y = *(float *)&bmaxs[16];
  Points[3].y = *(float *)&bmaxs[16];
  CMapFace::CreateFace(this: &Face, pPoints: Points, _nPoints: -4, bIsCordonFace: v21);
  CMapSolid::AddFace(this: pSolid, pFace: &Face);
  pSolid->CalcBounds(this: pSolid, a2: 0);
  CMapSolid::InitializeTextureAxes(this: pSolid, eAlignment, dwFlags: 0x1Fu);
  v27 = -1;
  CMapFace::~CMapFace(this: &Face);
}

//------------------------------------------------------------------------------
// Address: 0x100AE4B0
// Name: public: virtual void StockWedge::CreateMapSolid(class CMapSolid __near *,enum TextureAlignment_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StockWedge::CreateMapSolid(StockWedge *this, CMapSolid *pSolid, TextureAlignment_t eTextureAlignment)
{
  float y; // xmm5_4
  float x; // xmm3_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm6_4
  float v9; // xmm2_4
  float v10; // xmm0_4
  float v11; // xmm2_4
  float v12; // xmm5_4
  float v13; // xmm4_4
  float v14; // xmm0_4
  float v15; // xmm2_4
  float z; // xmm4_4
  float v17; // xmm2_4
  float v18; // xmm4_4
  CMapFace Face; // [esp+8h] [ebp-204h] BYREF
  float fDepth; // [esp+1C4h] [ebp-48h]
  Vector Points[4]; // [esp+1C8h] [ebp-44h] BYREF
  float fWidth; // [esp+1F8h] [ebp-14h]
  float fHeight; // [esp+1FCh] [ebp-10h]
  int v24; // [esp+208h] [ebp-4h]

  CMapFace::CMapFace(this: &Face);
  v24 = 0;
  y = this->origin.y;
  x = this->origin.x;
  v6 = (float)this->pFields[1].iValue * 0.5;
  v7 = (float)this->pFields->iValue * 0.5;
  v8 = (float)this->pFields[2].iValue * 0.5;
  Points[0].y = y + v6;
  v9 = this->origin.z + v8;
  fDepth = v6;
  fWidth = v7;
  fHeight = v8;
  Points[0].x = x + v7;
  Points[0].z = v9;
  Points[1].x = x + v7;
  Points[1].y = y - v6;
  Points[1].z = v9;
  Points[2].x = x - v7;
  Points[2].y = y - v6;
  Points[2].z = v9;
  CMapFace::CreateFace(this: &Face, pPoints: Points, _nPoints: 3, bIsCordonFace: false);
  CMapSolid::AddFace(this: pSolid, pFace: &Face);
  Points[0].z = this->origin.z - fHeight;
  Points[1].z = Points[0].z;
  Points[2].z = Points[0].z;
  CMapFace::CreateFace(this: &Face, pPoints: Points, _nPoints: -3, bIsCordonFace: false);
  CMapSolid::AddFace(this: pSolid, pFace: &Face);
  v10 = this->origin.x;
  v11 = this->origin.y;
  v12 = this->origin.z - fHeight;
  v13 = this->origin.z + fHeight;
  Points[0].x = v10 + fWidth;
  Points[0].y = v11 + fDepth;
  Points[0].z = v12;
  Points[1].x = v10 + fWidth;
  Points[1].y = v11 + fDepth;
  Points[1].z = v13;
  Points[2].x = v10 - fWidth;
  Points[2].y = v11 - fDepth;
  Points[2].z = v13;
  Points[3].x = v10 - fWidth;
  Points[3].y = v11 - fDepth;
  Points[3].z = v12;
  CMapFace::CreateFace(this: &Face, pPoints: Points, _nPoints: 4, bIsCordonFace: false);
  CMapSolid::AddFace(this: pSolid, pFace: &Face);
  v14 = this->origin.y - fDepth;
  v15 = this->origin.x;
  z = this->origin.z;
  Points[0].x = v15 + fWidth;
  Points[0].y = v14;
  Points[0].z = z + fHeight;
  Points[1].x = v15 + fWidth;
  Points[1].y = v14;
  Points[1].z = z - fHeight;
  Points[2].x = v15 - fWidth;
  Points[2].y = v14;
  Points[2].z = z - fHeight;
  Points[3].x = v15 - fWidth;
  Points[3].y = v14;
  Points[3].z = z + fHeight;
  CMapFace::CreateFace(this: &Face, pPoints: Points, _nPoints: 4, bIsCordonFace: false);
  CMapSolid::AddFace(this: pSolid, pFace: &Face);
  v17 = this->origin.y;
  v18 = this->origin.z;
  Points[0].x = this->origin.x + fWidth;
  Points[0].y = v17 + fDepth;
  Points[0].z = v18 + fHeight;
  Points[1].x = Points[0].x;
  Points[1].y = v17 + fDepth;
  Points[1].z = v18 - fHeight;
  Points[2].x = Points[0].x;
  Points[2].y = v17 - fDepth;
  Points[2].z = v18 - fHeight;
  Points[3].x = Points[0].x;
  Points[3].y = v17 - fDepth;
  Points[3].z = v18 + fHeight;
  CMapFace::CreateFace(this: &Face, pPoints: Points, _nPoints: 4, bIsCordonFace: false);
  CMapSolid::AddFace(this: pSolid, pFace: &Face);
  pSolid->CalcBounds(this: pSolid, a2: 0);
  CMapSolid::InitializeTextureAxes(this: pSolid, eAlignment: eTextureAlignment, dwFlags: 0x1Fu);
  v24 = -1;
  CMapFace::~CMapFace(this: &Face);
}

//------------------------------------------------------------------------------
// Address: 0x100AE7D0
// Name: public: virtual void StockSpike::SetFromBox(class BoundBox __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StockSpike::SetFromBox(StockSphere *this, BoundBox *pBox)
{
  Vector o; // [esp+4h] [ebp-Ch] BYREF

  this->pFields->iValue = (int)(float)(pBox->bmaxs.x - pBox->bmins.x);
  this->pFields[1].iValue = (int)(float)(pBox->bmaxs.y - pBox->bmins.y);
  this->pFields[2].iValue = (int)(float)(pBox->bmaxs.z - pBox->bmins.z);
  BoundBox::GetBoundsCenter(this: pBox, ptdest: &o);
  this->origin = o;
}

//------------------------------------------------------------------------------
// Address: 0x100AE850
// Name: public: virtual void StockCylinder::CreateMapSolid(class CMapSolid __near *,enum TextureAlignment_t)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge StockCylinder::CreateMapSolid(
        StockCylinder *this@<ecx>,
        int a2@<esi>,
        CMapSolid *pSolid,
        TextureAlignment_t eTextureAlignment)
{
  int iValue; // ebx
  float v6; // xmm0_4
  float v7; // xmm1_4
  float y; // xmm2_4
  int v9; // esi
  float v10; // xmm0_4
  float *p_z; // eax
  int v12; // ecx
  float v13; // xmm0_4
  float *v14; // eax
  CMapSolid *v15; // esi
  int *v16; // esi
  int v17; // xmm3_4
  Vector2D *v18; // xmm4_4
  int v19; // xmm5_4
  float z; // xmm1_4
  Vector y2; // [esp+28h] [ebp-4FCh] BYREF
  char v22; // [esp+38h] [ebp-4ECh] BYREF
  Vector pmPoints[64]; // [esp+44h] [ebp-4E0h] BYREF
  CMapFace Face; // [esp+344h] [ebp-1E0h] BYREF
  _BYTE Points[36]; // [esp+500h] [ebp-24h] OVERLAPPED

  CMapFace::CMapFace(this: (CMapFace *)&pmPoints[61].z);
  *(_DWORD *)&Points[32] = 0;
  iValue = this->pFields[3].iValue;
  v6 = (float)this->pFields[1].iValue * 0.5;
  v7 = (float)this->pFields->iValue * 0.5;
  y = this->origin.y;
  *(float *)&Points[20] = (float)this->pFields[2].iValue * 0.5;
  polyMake(
    a1: (int)this,
    a2,
    x1: this->origin.x - v7,
    y1: y - v6,
    x2: this->origin.x + v7,
    y2: y + v6,
    npoints: iValue,
    start_ang: 0,
    pmPoints: &y2);
  v9 = iValue + 1;
  if ( iValue + 1 > 0 )
  {
    v10 = this->origin.z - *(float *)&Points[20];
    p_z = &y2.z;
    v12 = iValue + 1;
    do
    {
      *p_z = v10;
      p_z += 3;
      --v12;
    }
    while ( v12 != 0 );
  }
  CMapFace::CreateFace(this: (CMapFace *)&pmPoints[61].z, pPoints: &y2, _nPoints: -iValue, bIsCordonFace: false);
  CMapSolid::AddFace(this: pSolid, pFace: (CMapFace *)&pmPoints[61].z);
  if ( v9 > 0 )
  {
    v13 = this->origin.z + *(float *)&Points[20];
    v14 = &y2.z;
    do
    {
      *v14 = v13;
      v14 += 3;
      --v9;
    }
    while ( v9 != 0 );
  }
  CMapFace::CreateFace(this: (CMapFace *)&pmPoints[61].z, pPoints: &y2, _nPoints: iValue, bIsCordonFace: false);
  v15 = pSolid;
  CMapSolid::AddFace(this: pSolid, pFace: (CMapFace *)&pmPoints[61].z);
  if ( iValue > 0 )
  {
    v16 = (int *)&v22;
    do
    {
      v17 = *(v16 - 3);
      v18 = (Vector2D *)*(v16 - 1);
      v19 = *v16;
      z = this->origin.z;
      Face.m_pTexture = (IEditorTexture *)*(v16 - 4);
      *(_DWORD *)&Face.m_DispHandle = v17;
      *(float *)&Face.m_pTextureCoords = z - *(float *)&Points[20];
      Face.m_pLightmapCoords = v18;
      *((_DWORD *)&Face + 108) = v19;
      *(float *)&Face.m_pTangentAxes = z - *(float *)&Points[20];
      Face.m_fSmoothingGroups = (unsigned int)v18;
      *(_DWORD *)Points = v19;
      *(float *)&Points[4] = z + *(float *)&Points[20];
      *(_DWORD *)&Points[8] = Face.m_pTexture;
      *(_DWORD *)&Points[12] = v17;
      *(float *)&Points[16] = z + *(float *)&Points[20];
      CMapFace::CreateFace(
        this: (CMapFace *)&pmPoints[61].z,
        pPoints: (Vector *)&Face.m_pTexture,
        _nPoints: 4,
        bIsCordonFace: false);
      LOBYTE(Face.texture.VAxis.x) = 1;
      CMapSolid::AddFace(this: pSolid, pFace: (CMapFace *)&pmPoints[61].z);
      v16 += 3;
      --iValue;
    }
    while ( iValue != 0 );
    v15 = pSolid;
  }
  v15->CalcBounds(this: v15, a2: 0);
  CMapSolid::InitializeTextureAxes(this: v15, eAlignment: eTextureAlignment, dwFlags: 0x1Fu);
  *(_DWORD *)&Points[32] = -1;
  CMapFace::~CMapFace(this: (CMapFace *)&pmPoints[61].z);
}

//------------------------------------------------------------------------------
// Address: 0x100AEAA0
// Name: public: virtual void StockSpike::CreateMapSolid(class CMapSolid __near *,enum TextureAlignment_t)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall StockSpike::CreateMapSolid(StockSpike *this, CMapSolid *pSolid, TextureAlignment_t eTextureAlignment)
{
  StockSolid::STSDATAFIELD *pFields; // eax
  int iValue; // edi
  float *p_z; // ebx
  float *p_y; // esi
  Vector x1; // [esp+28h] [ebp-4F8h] BYREF
  Vector pmPoints[64]; // [esp+50h] [ebp-4D0h] BYREF
  CMapFace NewFace; // [esp+350h] [ebp-1D0h] BYREF
  _BYTE Points[20]; // [esp+50Ch] [ebp-14h] OVERLAPPED

  pFields = this->pFields;
  *(float *)&Points[4] = (float)pFields[1].iValue * 0.5;
  *(float *)&NewFace.m_fSmoothingGroups = (float)pFields->iValue * 0.5;
  iValue = pFields[3].iValue;
  *(float *)Points = (float)pFields[2].iValue * 0.5;
  CMapFace::CMapFace(this: (CMapFace *)&pmPoints[60].z);
  *(_DWORD *)&Points[16] = 0;
  polyMake(
    a1: iValue,
    a2: (int)this,
    x1: this->origin.x - *(float *)&NewFace.m_fSmoothingGroups,
    y1: this->origin.y - *(float *)&Points[4],
    x2: this->origin.x + *(float *)&NewFace.m_fSmoothingGroups,
    y2: this->origin.y + *(float *)&Points[4],
    npoints: iValue,
    start_ang: 0,
    pmPoints: &x1);
  if ( iValue + 1 > 0 )
  {
    p_z = &x1.z;
    *(_DWORD *)&Points[4] = iValue + 1;
    do
    {
      *p_z = rint(f: this->origin.z - *(float *)Points);
      p_z += 3;
      --*(_DWORD *)&Points[4];
    }
    while ( *(_DWORD *)&Points[4] != 0 );
  }
  CMapFace::CreateFace(this: (CMapFace *)&pmPoints[60].z, pPoints: &x1, _nPoints: -iValue, bIsCordonFace: false);
  CMapSolid::AddFace(this: pSolid, pFace: (CMapFace *)&pmPoints[60].z);
  NewFace.m_pDetailObjects = (DetailObjects *)LODWORD(this->origin.x);
  *(float *)&NewFace.m_uchAlpha = this->origin.y;
  *(float *)&NewFace.m_nFaceID = rint(f: this->origin.z + *(float *)Points);
  if ( iValue > 0 )
  {
    p_y = &x1.y;
    do
    {
      NewFace.m_pTexture = *(IEditorTexture **)(p_y - 1);
      *(float *)&NewFace.m_DispHandle = *p_y;
      NewFace.m_pTextureCoords = (Vector2D *)p_y[1];
      NewFace.m_pLightmapCoords = (Vector2D *)p_y[2];
      *((float *)&NewFace + 108) = p_y[3];
      NewFace.m_pTangentAxes = (CMapFace::TangentSpaceAxes_t *)p_y[4];
      CMapFace::CreateFace(
        this: (CMapFace *)&pmPoints[60].z,
        pPoints: (Vector *)&NewFace.m_pDetailObjects,
        _nPoints: 3,
        bIsCordonFace: false);
      CMapSolid::AddFace(this: pSolid, pFace: (CMapFace *)&pmPoints[60].z);
      p_y += 3;
      --iValue;
    }
    while ( iValue != 0 );
  }
  pSolid->CalcBounds(this: pSolid, a2: 0);
  CMapSolid::InitializeTextureAxes(this: pSolid, eAlignment: eTextureAlignment, dwFlags: 0x1Fu);
  *(_DWORD *)&Points[16] = -1;
  CMapFace::~CMapFace(this: (CMapFace *)&pmPoints[60].z);
}

//------------------------------------------------------------------------------
// Address: 0x100AECD0
// Name: public: virtual void StockSphere::CreateMapSolid(class CMapSolid __near *,enum TextureAlignment_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StockSphere::CreateMapSolid(StockSphere *this, CMapSolid *pSolid, TextureAlignment_t eTextureAlignment)
{
  float v3; // esi
  int v4; // edi
  int *v5; // eax
  int v6; // ebx
  float x; // xmm0_4
  float v8; // xmm0_4
  double v9; // xmm0_8
  float v10; // xmm1_4
  double z; // xmm0_8
  float v12; // xmm0_4
  int v13; // esi
  int v14; // [esp+14h] [ebp-840h]
  long double x1; // [esp+1Ch] [ebp-838h]
  long double x1a; // [esp+1Ch] [ebp-838h]
  long double x1b; // [esp+1Ch] [ebp-838h]
  long double x1c; // [esp+1Ch] [ebp-838h]
  Vector y2[2]; // [esp+28h] [ebp-82Ch] BYREF
  Vector BottomPoints[64]; // [esp+44h] [ebp-810h] BYREF
  Vector TopPoints[64]; // [esp+344h] [ebp-510h] BYREF
  CMapFace Face; // [esp+644h] [ebp-210h] BYREF
  Vector Points[4]; // [esp+800h] [ebp-54h]
  float v24; // [esp+830h] [ebp-24h]
  int v25; // [esp+834h] [ebp-20h]
  float fAngle1; // [esp+838h] [ebp-1Ch]
  float v27; // [esp+83Ch] [ebp-18h]
  float v28; // [esp+840h] [ebp-14h]
  float fAngleStep; // [esp+844h] [ebp-10h]
  int v30; // [esp+850h] [ebp-4h]

  v3 = *(float *)&this;
  LODWORD(Points[2].z) = this;
  CMapFace::CMapFace(this: (CMapFace *)&TopPoints[61].z);
  v4 = 0;
  v30 = 0;
  v5 = *(int **)(LODWORD(v3) + 28);
  v6 = v5[147];
  fAngle1 = (float)v5[73] * 0.5;
  v28 = (float)v5[36] * 0.5;
  x = 0.0;
  fAngleStep = (float)v5[110] * 0.5;
  Points[3].y = 180.0 / (double)v6;
  if ( v6 > 0 )
  {
    while ( 1 )
    {
      v24 = x * 0.017453292;
      Points[3].x = Points[3].y + x;
      Points[2].y = Points[3].y + x;
      __libm_sse2_sin(x: x1);
      polyMake(
        a1: v4,
        a2: SLODWORD(v3),
        x1: *(float *)(LODWORD(v3) + 4) - (float)((float)(x * 0.017453292) * v28),
        y1: *(float *)(LODWORD(v3) + 8) - (float)((float)(x * 0.017453292) * fAngle1),
        x2: *(float *)(LODWORD(v3) + 4) + (float)((float)(x * 0.017453292) * v28),
        y2: *(float *)(LODWORD(v3) + 8) + (float)((float)(x * 0.017453292) * fAngle1),
        npoints: v6,
        start_ang: 0,
        pmPoints: (Vector *)&BottomPoints[61].z);
      v8 = Points[2].y * 0.017453292;
      Points[1].z = Points[2].y * 0.017453292;
      __libm_sse2_sin(x: x1a);
      polyMake(
        a1: v4,
        a2: SLODWORD(v3),
        x1: *(float *)(LODWORD(v3) + 4) - (float)(v8 * v28),
        y1: *(float *)(LODWORD(v3) + 8) - (float)(v8 * fAngle1),
        x2: *(float *)(LODWORD(v3) + 4) + (float)(v8 * v28),
        y2: *(float *)(LODWORD(v3) + 8) + (float)(v8 * fAngle1),
        npoints: v6,
        start_ang: 0,
        pmPoints: y2);
      v9 = v24;
      __libm_sse2_cos(x: x1b);
      v10 = *(float *)(LODWORD(v3) + 12);
      *(float *)&v9 = v9;
      v27 = (float)(*(float *)&v9 * fAngleStep) + v10;
      Points[2].x = v10;
      z = Points[1].z;
      __libm_sse2_cos(x: x1c);
      *(float *)&z = z;
      v12 = (float)(*(float *)&z * fAngleStep) + Points[2].x;
      Points[3].z = v12;
      v13 = 0;
      v25 = v6;
      while ( 1 )
      {
        if ( v4 != 0 )
        {
          Face.m_pTexture = (IEditorTexture *)LODWORD(BottomPoints[v13 + 62].z);
          *(float *)&Face.m_DispHandle = BottomPoints[v13 + 63].x;
          *(float *)&Face.m_pTextureCoords = v27;
        }
        Face.m_pLightmapCoords = (Vector2D *)LODWORD(BottomPoints[v13 + 61].z);
        *((_DWORD *)&Face + 108) = LODWORD(BottomPoints[v13 + 62].x);
        *(float *)&Face.m_pTangentAxes = v27;
        Face.m_fSmoothingGroups = LODWORD(y2[v13].x);
        Points[0].x = y2[v13].y;
        Points[0].y = v12;
        if ( v4 != v6 - 1 )
        {
          Points[0].z = y2[v13 + 1].x;
          Points[1].x = y2[v13 + 1].y;
          Points[1].y = v12;
        }
        if ( v4 != 0 )
        {
          v14 = v4 == v6 - 1 ? 3 : 4;
          CMapFace::CreateFace(
            this: (CMapFace *)&TopPoints[61].z,
            pPoints: (Vector *)&Face.m_pTexture,
            _nPoints: v14,
            bIsCordonFace: false);
        }
        else
        {
          CMapFace::CreateFace(
            this: (CMapFace *)&TopPoints[61].z,
            pPoints: (Vector *)&Face.m_pLightmapCoords,
            _nPoints: 3,
            bIsCordonFace: false);
        }
        LOBYTE(Face.texture.VAxis.x) = 1;
        CMapSolid::AddFace(this: pSolid, pFace: (CMapFace *)&TopPoints[61].z);
        ++v13;
        if ( --v25 == 0 )
          break;
        v12 = Points[3].z;
      }
      x = Points[3].x;
      if ( ++v4 >= v6 )
        break;
      v3 = Points[2].z;
    }
  }
  pSolid->CalcBounds(this: pSolid, a2: 0);
  CMapSolid::InitializeTextureAxes(this: pSolid, eAlignment: eTextureAlignment, dwFlags: 0x1Fu);
  v30 = -1;
  CMapFace::~CMapFace(this: (CMapFace *)&TopPoints[61].z);
}

//------------------------------------------------------------------------------
// Address: 0x100AF020
// Name: public: StockBlock::StockBlock(void)
// Source: json
//------------------------------------------------------------------------------
StockBlock *__thiscall StockBlock::StockBlock(StockBlock *this)
{
  StockSolid::STSDATAFIELD *v2; // eax
  const char *v3; // ecx
  int v4; // edx
  char v5; // al
  StockSolid::STSDATAFIELD *v6; // eax
  const char *v7; // ecx
  int v8; // edx
  char v9; // al
  StockSolid::STSDATAFIELD *v10; // eax
  const char *v11; // ecx
  int v12; // edx
  char v13; // al

  this->__vftable = (StockBlock_vtbl *)&StockSolid::`vftable';
  this->pFields = (StockSolid::STSDATAFIELD *)operator new[](nSize: 0x1BCu);
  this->iMaxFields = 3;
  this->nFields = 0;
  this->cofs.x = 0.0;
  this->cofs.y = 0.0;
  this->cofs.z = 0.0;
  v2 = &this->pFields[this->nFields++];
  this->__vftable = (StockBlock_vtbl *)&StockBlock::`vftable';
  v3 = "Width (X)";
  v2->type = DFTYPE_INTEGER;
  v2->flags = 0;
  v4 = v2->szName - "Width (X)";
  do
  {
    v5 = *v3;
    v3[v4] = *v3;
    ++v3;
  }
  while ( v5 != 0 );
  v6 = &this->pFields[this->nFields++];
  v7 = "Depth (Y)";
  v6->type = DFTYPE_INTEGER;
  v6->flags = 0;
  v8 = v6->szName - "Depth (Y)";
  do
  {
    v9 = *v7;
    v7[v8] = *v7;
    ++v7;
  }
  while ( v9 != 0 );
  v10 = &this->pFields[this->nFields++];
  v11 = "Height (Z)";
  v10->type = DFTYPE_INTEGER;
  v10->flags = 0;
  v12 = v10->szName - "Height (Z)";
  do
  {
    v13 = *v11;
    v11[v12] = *v11;
    ++v11;
  }
  while ( v13 != 0 );
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100AF140
// Name: public: StockWedge::StockWedge(void)
// Source: json
//------------------------------------------------------------------------------
StockWedge *__thiscall StockWedge::StockWedge(StockWedge *this)
{
  StockSolid::STSDATAFIELD *v2; // eax
  const char *v3; // ecx
  int v4; // edx
  char v5; // al
  StockSolid::STSDATAFIELD *v6; // eax
  const char *v7; // ecx
  int v8; // edx
  char v9; // al
  StockSolid::STSDATAFIELD *v10; // eax
  const char *v11; // ecx
  int v12; // edx
  char v13; // al

  this->__vftable = (StockWedge_vtbl *)&StockSolid::`vftable';
  this->pFields = (StockSolid::STSDATAFIELD *)operator new[](nSize: 0x1BCu);
  this->iMaxFields = 3;
  this->nFields = 0;
  this->cofs.x = 0.0;
  this->cofs.y = 0.0;
  this->cofs.z = 0.0;
  v2 = &this->pFields[this->nFields++];
  this->__vftable = (StockWedge_vtbl *)&StockWedge::`vftable';
  v3 = "Width (X)";
  v2->type = DFTYPE_INTEGER;
  v2->flags = 0;
  v4 = v2->szName - "Width (X)";
  do
  {
    v5 = *v3;
    v3[v4] = *v3;
    ++v3;
  }
  while ( v5 != 0 );
  v6 = &this->pFields[this->nFields++];
  v7 = "Depth (Y)";
  v6->type = DFTYPE_INTEGER;
  v6->flags = 0;
  v8 = v6->szName - "Depth (Y)";
  do
  {
    v9 = *v7;
    v7[v8] = *v7;
    ++v7;
  }
  while ( v9 != 0 );
  v10 = &this->pFields[this->nFields++];
  v11 = "Height (Z)";
  v10->type = DFTYPE_INTEGER;
  v10->flags = 0;
  v12 = v10->szName - "Height (Z)";
  do
  {
    v13 = *v11;
    v11[v12] = *v11;
    ++v11;
  }
  while ( v13 != 0 );
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100AF260
// Name: public: StockCylinder::StockCylinder(void)
// Source: json
//------------------------------------------------------------------------------
StockCylinder *__thiscall StockCylinder::StockCylinder(StockCylinder *this)
{
  StockSolid::STSDATAFIELD *v2; // eax
  const char *v3; // ecx
  int v4; // edx
  char v5; // al
  StockSolid::STSDATAFIELD *v6; // eax
  const char *v7; // ecx
  int v8; // edx
  char v9; // al
  StockSolid::STSDATAFIELD *v10; // eax
  const char *v11; // ecx
  int v12; // edx
  char v13; // al
  StockSolid::STSDATAFIELD *v14; // eax
  const char *v15; // ecx
  int v16; // edx
  char v17; // al

  this->__vftable = (StockCylinder_vtbl *)&StockSolid::`vftable';
  this->pFields = (StockSolid::STSDATAFIELD *)operator new[](nSize: 0x250u);
  this->iMaxFields = 4;
  this->nFields = 0;
  this->cofs.x = 0.0;
  this->cofs.y = 0.0;
  this->cofs.z = 0.0;
  v2 = &this->pFields[this->nFields++];
  this->__vftable = (StockCylinder_vtbl *)&StockCylinder::`vftable';
  v3 = "Width (X)";
  v2->type = DFTYPE_INTEGER;
  v2->flags = 0;
  v4 = v2->szName - "Width (X)";
  do
  {
    v5 = *v3;
    v3[v4] = *v3;
    ++v3;
  }
  while ( v5 != 0 );
  v6 = &this->pFields[this->nFields++];
  v7 = "Depth (Y)";
  v6->type = DFTYPE_INTEGER;
  v6->flags = 0;
  v8 = v6->szName - "Depth (Y)";
  do
  {
    v9 = *v7;
    v7[v8] = *v7;
    ++v7;
  }
  while ( v9 != 0 );
  v10 = &this->pFields[this->nFields++];
  v11 = "Height (Z)";
  v10->type = DFTYPE_INTEGER;
  v10->flags = 0;
  v12 = v10->szName - "Height (Z)";
  do
  {
    v13 = *v11;
    v11[v12] = *v11;
    ++v11;
  }
  while ( v13 != 0 );
  v14 = &this->pFields[this->nFields++];
  v15 = "Number of Sides";
  v14->type = DFTYPE_INTEGER;
  v14->flags = 0;
  v16 = v14->szName - "Number of Sides";
  do
  {
    v17 = *v15;
    v15[v16] = *v15;
    ++v15;
  }
  while ( v17 != 0 );
  this->pFields[3].iValue = 8;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100AF3B0
// Name: public: StockSpike::StockSpike(void)
// Source: json
//------------------------------------------------------------------------------
StockSpike *__thiscall StockSpike::StockSpike(StockSpike *this)
{
  StockSolid::STSDATAFIELD *v2; // eax
  const char *v3; // ecx
  int v4; // edx
  char v5; // al
  StockSolid::STSDATAFIELD *v6; // eax
  const char *v7; // ecx
  int v8; // edx
  char v9; // al
  StockSolid::STSDATAFIELD *v10; // eax
  const char *v11; // ecx
  int v12; // edx
  char v13; // al
  StockSolid::STSDATAFIELD *v14; // eax
  const char *v15; // ecx
  int v16; // edx
  char v17; // al

  this->__vftable = (StockSpike_vtbl *)&StockSolid::`vftable';
  this->pFields = (StockSolid::STSDATAFIELD *)operator new[](nSize: 0x250u);
  this->iMaxFields = 4;
  this->nFields = 0;
  this->cofs.x = 0.0;
  this->cofs.y = 0.0;
  this->cofs.z = 0.0;
  v2 = &this->pFields[this->nFields++];
  this->__vftable = (StockSpike_vtbl *)&StockSpike::`vftable';
  v3 = "Width (X)";
  v2->type = DFTYPE_INTEGER;
  v2->flags = 0;
  v4 = v2->szName - "Width (X)";
  do
  {
    v5 = *v3;
    v3[v4] = *v3;
    ++v3;
  }
  while ( v5 != 0 );
  v6 = &this->pFields[this->nFields++];
  v7 = "Depth (Y)";
  v6->type = DFTYPE_INTEGER;
  v6->flags = 0;
  v8 = v6->szName - "Depth (Y)";
  do
  {
    v9 = *v7;
    v7[v8] = *v7;
    ++v7;
  }
  while ( v9 != 0 );
  v10 = &this->pFields[this->nFields++];
  v11 = "Height (Z)";
  v10->type = DFTYPE_INTEGER;
  v10->flags = 0;
  v12 = v10->szName - "Height (Z)";
  do
  {
    v13 = *v11;
    v11[v12] = *v11;
    ++v11;
  }
  while ( v13 != 0 );
  v14 = &this->pFields[this->nFields++];
  v15 = "Number of Sides";
  v14->type = DFTYPE_INTEGER;
  v14->flags = 0;
  v16 = v14->szName - "Number of Sides";
  do
  {
    v17 = *v15;
    v15[v16] = *v15;
    ++v15;
  }
  while ( v17 != 0 );
  this->pFields[3].iValue = 8;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100AF500
// Name: public: StockSphere::StockSphere(void)
// Source: json
//------------------------------------------------------------------------------
StockSphere *__thiscall StockSphere::StockSphere(StockSphere *this)
{
  StockSolid::STSDATAFIELD *v2; // eax
  const char *v3; // ecx
  int v4; // edx
  char v5; // al
  StockSolid::STSDATAFIELD *v6; // eax
  const char *v7; // ecx
  int v8; // edx
  char v9; // al
  StockSolid::STSDATAFIELD *v10; // eax
  const char *v11; // ecx
  int v12; // edx
  char v13; // al
  StockSolid::STSDATAFIELD *v14; // eax
  const char *v15; // ecx
  int v16; // edx
  char v17; // al

  this->__vftable = (StockSphere_vtbl *)&StockSolid::`vftable';
  this->pFields = (StockSolid::STSDATAFIELD *)operator new[](nSize: 0x250u);
  this->iMaxFields = 4;
  this->nFields = 0;
  this->cofs.x = 0.0;
  this->cofs.y = 0.0;
  this->cofs.z = 0.0;
  v2 = &this->pFields[this->nFields++];
  this->__vftable = (StockSphere_vtbl *)&StockSphere::`vftable';
  v3 = "Width (X)";
  v2->type = DFTYPE_INTEGER;
  v2->flags = 0;
  v4 = v2->szName - "Width (X)";
  do
  {
    v5 = *v3;
    v3[v4] = *v3;
    ++v3;
  }
  while ( v5 != 0 );
  v6 = &this->pFields[this->nFields++];
  v7 = "Depth (Y)";
  v6->type = DFTYPE_INTEGER;
  v6->flags = 0;
  v8 = v6->szName - "Depth (Y)";
  do
  {
    v9 = *v7;
    v7[v8] = *v7;
    ++v7;
  }
  while ( v9 != 0 );
  v10 = &this->pFields[this->nFields++];
  v11 = "Height (Z)";
  v10->type = DFTYPE_INTEGER;
  v10->flags = 0;
  v12 = v10->szName - "Height (Z)";
  do
  {
    v13 = *v11;
    v11[v12] = *v11;
    ++v11;
  }
  while ( v13 != 0 );
  v14 = &this->pFields[this->nFields++];
  v15 = "Subdivisions";
  v14->type = DFTYPE_INTEGER;
  v14->flags = 0;
  v16 = v14->szName - "Subdivisions";
  do
  {
    v17 = *v15;
    v15[v16] = *v15;
    ++v15;
  }
  while ( v17 != 0 );
  this->pFields[3].iValue = 8;
  return this;
}
