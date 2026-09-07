// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/createarch.cpp
// Functions: 14
// ============================================================

#include "hammer\createarch.h"

//------------------------------------------------------------------------------
// Address: 0x10016370
// Name: public: void CMapAtom::TransMove(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapAtom::TransMove(CMapAtom *this, const Vector *Delta)
{
  void (__thiscall *DoTransform)(CMapAtom *, const VMatrix *); // edx
  VMatrix matrix; // [esp+4h] [ebp-40h] BYREF

  MatrixSetIdentity(dst: &matrix);
  DoTransform = this->DoTransform;
  matrix.m[0][3] = Delta->x;
  matrix.m[1][3] = Delta->y;
  matrix.m[2][3] = Delta->z;
  DoTransform(this, a2: &matrix);
  this->PostUpdate(this, a2: Notify_Transform);
}

//------------------------------------------------------------------------------
// Address: 0x100163D0
// Name: public: void CMapAtom::TransScale(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapAtom::TransScale(CMapAtom *this, const Vector *RefPoint, const Vector *Scale)
{
  const VMatrix *v4; // eax
  void (__thiscall *DoTransform)(CMapAtom *, const VMatrix *); // edx
  float v6; // xmm6_4
  float v7; // xmm3_4
  float v8; // xmm5_4
  VMatrix result; // [esp+4h] [ebp-80h] BYREF
  VMatrix matrix; // [esp+44h] [ebp-40h] BYREF

  MatrixSetIdentity(dst: &matrix);
  v4 = VMatrix::Scale(this: &matrix, &result, vScale: Scale);
  VMatrix::operator=(this: &matrix, mOther: v4);
  DoTransform = this->DoTransform;
  v6 = 1.0
     / (float)((float)((float)((float)(RefPoint->x * matrix.m[3][0]) + (float)(RefPoint->y * matrix.m[3][1]))
                     + (float)(RefPoint->z * matrix.m[3][2]))
             + matrix.m[3][3]);
  v7 = RefPoint->y
     - (float)((float)((float)((float)((float)(RefPoint->x * matrix.m[1][0]) + (float)(RefPoint->y * matrix.m[1][1]))
                             + (float)(RefPoint->z * matrix.m[1][2]))
                     + matrix.m[1][3])
             * v6);
  v8 = RefPoint->z
     - (float)((float)((float)((float)((float)(RefPoint->x * matrix.m[2][0]) + (float)(RefPoint->y * matrix.m[2][1]))
                             + (float)(RefPoint->z * matrix.m[2][2]))
                     + matrix.m[2][3])
             * v6);
  matrix.m[0][3] = RefPoint->x
                 - (float)((float)((float)((float)((float)(RefPoint->y * matrix.m[0][1])
                                                 + (float)(RefPoint->x * matrix.m[0][0]))
                                         + (float)(RefPoint->z * matrix.m[0][2]))
                                 + matrix.m[0][3])
                         * v6);
  matrix.m[1][3] = v7;
  matrix.m[2][3] = v8;
  DoTransform(this, a2: &matrix);
  this->PostUpdate(this, a2: Notify_Transform);
}

//------------------------------------------------------------------------------
// Address: 0x10016500
// Name: public: CMapGroup::CMapGroup(void)
// Source: json
//------------------------------------------------------------------------------
CMapGroup *__thiscall CMapGroup::CMapGroup(CMapGroup *this)
{
  CMapClass::CMapClass(this);
  this->__vftable = (CMapGroup_vtbl *)&CMapGroup::`vftable';
  this->m_vecLogicalPosition.x = 99999.0;
  this->m_vecLogicalPosition.y = 99999.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10016570
// Name: public: virtual bool CMapAtom::IsSelected(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMapAtom::IsSelected(CMapAtom *this)
{
  return this->m_eSelectionState != SELECT_NONE;
}

//------------------------------------------------------------------------------
// Address: 0x10016580
// Name: public: virtual void CMapAtom::GetRenderColor(unsigned char __near &,unsigned char __near &,unsigned char __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapAtom::GetRenderColor(
        CMapAtom *this,
        unsigned __int8 *red,
        unsigned __int8 *green,
        unsigned __int8 *blue)
{
  *red = this->r;
  *green = this->g;
  *blue = this->b;
}

//------------------------------------------------------------------------------
// Address: 0x100165B0
// Name: public: virtual struct color32_s CMapAtom::GetRenderColor(void)
// Source: json
//------------------------------------------------------------------------------
color32_s __thiscall CMapAtom::GetRenderColor(CMapAtom *this, unsigned __int8 *a2)
{
  unsigned __int8 g; // dl
  unsigned __int8 b; // cl

  *a2 = this->r;
  g = this->g;
  b = this->b;
  a2[1] = g;
  a2[2] = b;
  a2[3] = 0;
  return (color32_s)a2;
}

//------------------------------------------------------------------------------
// Address: 0x100165E0
// Name: CreateSegment
// Source: json
//------------------------------------------------------------------------------
CMapSolid *__usercall CreateSegment@<eax>(
        float (*fOuterPoints)[2]@<ecx>,
        int iEnd@<edi>,
        float fZMin,
        float fZMax,
        float (*fInnerPoints)[2],
        int iStart,
        int bCreateSouthFace)
{
  CMapSolid *v9; // eax
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm3_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm3_4
  TextureAlignment_t Id; // eax
  CMapFace Face; // [esp+8h] [ebp-208h] BYREF
  float *v29; // [esp+1C4h] [ebp-4Ch]
  float *v30; // [esp+1C8h] [ebp-48h]
  int iNorthSouthPoints; // [esp+1CCh] [ebp-44h]
  float *v32; // [esp+1D0h] [ebp-40h]
  Vector points[4]; // [esp+1D4h] [ebp-3Ch] BYREF
  int v34; // [esp+20Ch] [ebp-4h]
  CMapSolid *iStarta; // [esp+224h] [ebp+14h]

  CMapFace::CMapFace(this: &Face);
  v34 = 0;
  v9 = (CMapSolid *)operator new(nSize: 0x240u);
  iNorthSouthPoints = (int)v9;
  LOBYTE(v34) = 1;
  if ( v9 != nullptr )
    iStarta = CMapSolid::CMapSolid(this: v9, Parent0: nullptr);
  else
    iStarta = nullptr;
  LOBYTE(v34) = 0;
  v10 = (*fOuterPoints)[2 * iStart];
  points[1].x = (*fOuterPoints)[2 * iEnd];
  v11 = (*fOuterPoints)[2 * iEnd + 1];
  points[0].x = v10;
  v12 = (*fOuterPoints)[2 * iStart + 1];
  v29 = &(*fOuterPoints)[2 * iStart + 1];
  points[1].y = v11;
  *(_QWORD *)&points[2].x = *(_QWORD *)&(*fInnerPoints)[2 * iEnd];
  points[3].x = (*fInnerPoints)[2 * iStart];
  v13 = (*fInnerPoints)[2 * iStart + 1];
  v30 = &(*fInnerPoints)[2 * iStart + 1];
  iNorthSouthPoints = (bCreateSouthFace != 0) + 3;
  points[0].y = v12;
  points[0].z = fZMin;
  points[1].z = fZMin;
  v32 = &(*fInnerPoints)[2 * iEnd + 1];
  points[2].z = fZMin;
  points[3].y = v13;
  points[3].z = fZMin;
  CMapFace::CreateFace(this: &Face, pPoints: points, _nPoints: iNorthSouthPoints, bIsCordonFace: false);
  CMapSolid::AddFace(this: iStarta, pFace: &Face);
  points[0].z = fZMax;
  points[1].z = fZMax;
  points[2].z = fZMax;
  points[3].z = fZMax;
  CMapFace::CreateFace(this: &Face, pPoints: points, _nPoints: -iNorthSouthPoints, bIsCordonFace: false);
  CMapSolid::AddFace(this: iStarta, pFace: &Face);
  v14 = *v29;
  points[0].x = (*fOuterPoints)[2 * iStart];
  points[0].y = v14;
  points[1].x = points[0].x;
  v15 = (*fInnerPoints)[2 * iStart];
  points[1].y = v14;
  v16 = *v30;
  points[0].z = fZMax;
  points[1].z = fZMin;
  points[2].x = v15;
  points[2].y = v16;
  points[2].z = fZMin;
  points[3].x = v15;
  points[3].y = v16;
  points[3].z = fZMax;
  CMapFace::CreateFace(this: &Face, pPoints: points, _nPoints: 4, bIsCordonFace: false);
  CMapSolid::AddFace(this: iStarta, pFace: &Face);
  v17 = (*fOuterPoints)[2 * iEnd];
  points[0].y = (*fOuterPoints)[2 * iEnd + 1];
  points[1].y = points[0].y;
  v18 = *v32;
  points[0].x = v17;
  points[1].x = v17;
  v19 = (*fInnerPoints)[2 * iEnd];
  points[0].z = fZMin;
  points[1].z = fZMax;
  points[2].x = v19;
  points[2].y = v18;
  points[2].z = fZMax;
  points[3].x = v19;
  points[3].y = v18;
  points[3].z = fZMin;
  CMapFace::CreateFace(this: &Face, pPoints: points, _nPoints: 4, bIsCordonFace: false);
  CMapSolid::AddFace(this: iStarta, pFace: &Face);
  v20 = *v29;
  v21 = (*fOuterPoints)[2 * iEnd];
  v22 = (*fOuterPoints)[2 * iEnd + 1];
  points[1].x = (*fOuterPoints)[2 * iStart];
  points[2].x = points[1].x;
  points[0].x = v21;
  points[0].y = v22;
  points[0].z = fZMin;
  points[1].y = v20;
  points[1].z = fZMin;
  points[2].y = v20;
  points[2].z = fZMax;
  points[3].x = v21;
  points[3].y = v22;
  points[3].z = fZMax;
  CMapFace::CreateFace(this: &Face, pPoints: points, _nPoints: 4, bIsCordonFace: false);
  CMapSolid::AddFace(this: iStarta, pFace: &Face);
  if ( bCreateSouthFace != 0 )
  {
    v23 = (*fInnerPoints)[2 * iStart];
    v24 = *v30;
    v25 = *v32;
    points[1].x = (*fInnerPoints)[2 * iEnd];
    points[2].x = points[1].x;
    points[0].x = v23;
    points[0].y = v24;
    points[0].z = fZMin;
    points[1].y = v25;
    points[1].z = fZMin;
    points[2].y = v25;
    points[2].z = fZMax;
    points[3].x = v23;
    points[3].y = v24;
    points[3].z = fZMax;
    CMapFace::CreateFace(this: &Face, pPoints: points, _nPoints: 4, bIsCordonFace: false);
    CMapSolid::AddFace(this: iStarta, pFace: &Face);
  }
  Id = CParticleOperatorDefinition<C_OP_RemapBoundingVolumetoCP>::GetId(this: (ConCommandBase *)&Options);
  CMapSolid::InitializeTextureAxes(this: iStarta, eAlignment: Id, dwFlags: 0x1Fu);
  v34 = -1;
  CMapFace::~CMapFace(this: &Face);
  return iStarta;
}

//------------------------------------------------------------------------------
// Address: 0x10016980
// Name: CreateSegment_0
// Source: json
//------------------------------------------------------------------------------
CMapSolid *__fastcall CreateSegment_0(
        int iEnd,
        int iStart,
        float (*fStartOuterPoints)[3],
        float (*fStartInnerPoints)[3],
        float (*fEndOuterPoints)[3],
        float (*fEndInnerPoints)[3],
        int bCreateSouthFace)
{
  CMapSolid *v10; // eax
  int v11; // esi
  int v12; // edi
  float v13; // xmm0_4
  float v14; // xmm0_4
  float v15; // xmm0_4
  float v16; // xmm0_4
  float v17; // xmm0_4
  float v18; // xmm0_4
  float v19; // xmm0_4
  float v20; // xmm0_4
  TextureAlignment_t Id; // eax
  CMapFace Face; // [esp+Ch] [ebp-220h] BYREF
  float *v24; // [esp+1C8h] [ebp-64h]
  float *v25; // [esp+1CCh] [ebp-60h]
  float *v26; // [esp+1D0h] [ebp-5Ch]
  float *v27; // [esp+1D4h] [ebp-58h]
  float *v28; // [esp+1D8h] [ebp-54h]
  float *v29; // [esp+1DCh] [ebp-50h]
  float *v30; // [esp+1E0h] [ebp-4Ch]
  float *v31; // [esp+1E4h] [ebp-48h]
  float *v32; // [esp+1E8h] [ebp-44h]
  void *p; // [esp+1ECh] [ebp-40h]
  Vector points[4]; // [esp+1F0h] [ebp-3Ch] BYREF
  int v35; // [esp+228h] [ebp-4h]
  CMapSolid *fEndOuterPointsa; // [esp+23Ch] [ebp+10h]

  CMapFace::CMapFace(this: &Face);
  v35 = 0;
  v10 = (CMapSolid *)operator new(nSize: 0x240u);
  p = v10;
  LOBYTE(v35) = 1;
  if ( v10 != nullptr )
    fEndOuterPointsa = CMapSolid::CMapSolid(this: v10, Parent0: nullptr);
  else
    fEndOuterPointsa = nullptr;
  LOBYTE(v35) = 0;
  v11 = 3 * iStart;
  points[0] = *(Vector *)&(*fStartOuterPoints)[v11];
  v28 = &(*fStartOuterPoints)[v11 + 1];
  v12 = 3 * iEnd;
  points[1] = *(Vector *)&(*fStartOuterPoints)[v12];
  v13 = (*fStartInnerPoints)[v12];
  v27 = &(*fStartOuterPoints)[v11 + 2];
  points[2].x = v13;
  v14 = (*fStartInnerPoints)[v12 + 1];
  v26 = &(*fStartInnerPoints)[v12 + 1];
  points[2].y = v14;
  points[2].z = (*fStartInnerPoints)[v12 + 2];
  points[3].x = (*fStartInnerPoints)[v11];
  points[3].y = (*fStartInnerPoints)[v11 + 1];
  v15 = (*fStartInnerPoints)[v11 + 2];
  v32 = &(*fStartInnerPoints)[v12 + 2];
  points[3].z = v15;
  CMapFace::CreateFace(this: &Face, pPoints: points, _nPoints: -4, bIsCordonFace: false);
  CMapSolid::AddFace(this: fEndOuterPointsa, pFace: &Face);
  points[0] = *(Vector *)&(*fEndOuterPoints)[v11];
  points[1].x = (*fEndOuterPoints)[v12];
  points[1].y = (*fEndOuterPoints)[v12 + 1];
  v16 = (*fEndOuterPoints)[v12 + 2];
  v25 = &(*fEndOuterPoints)[v12 + 1];
  points[1].z = v16;
  v30 = &(*fEndOuterPoints)[v12 + 2];
  points[2].x = (*fEndInnerPoints)[v12];
  v17 = (*fEndInnerPoints)[v12 + 1];
  v24 = &(*fEndInnerPoints)[v12 + 1];
  points[2].y = v17;
  points[2].z = (*fEndInnerPoints)[v12 + 2];
  v18 = (*fEndInnerPoints)[v11];
  v31 = &(*fEndInnerPoints)[v12 + 2];
  points[3].x = v18;
  v19 = (*fEndInnerPoints)[v11 + 1];
  v29 = &(*fEndInnerPoints)[v11 + 1];
  points[3].y = v19;
  v20 = (*fEndInnerPoints)[v11 + 2];
  p = &(*fEndInnerPoints)[v11 + 2];
  points[3].z = v20;
  CMapFace::CreateFace(this: &Face, pPoints: points, _nPoints: 4, bIsCordonFace: false);
  CMapSolid::AddFace(this: fEndOuterPointsa, pFace: &Face);
  points[0] = *(Vector *)&(*fEndOuterPoints)[v11];
  points[1].x = (*fStartOuterPoints)[v11];
  points[1].y = *v28;
  points[1].z = *v27;
  points[2] = *(Vector *)&(*fStartInnerPoints)[v11];
  points[3].x = (*fEndInnerPoints)[v11];
  points[3].y = *v29;
  points[3].z = *(float *)p;
  CMapFace::CreateFace(this: &Face, pPoints: points, _nPoints: -4, bIsCordonFace: false);
  CMapSolid::AddFace(this: fEndOuterPointsa, pFace: &Face);
  points[0] = *(Vector *)&(*fStartOuterPoints)[v12];
  points[1].x = (*fEndOuterPoints)[v12];
  points[1].y = *v25;
  points[1].z = *v30;
  points[2].x = (*fEndInnerPoints)[v12];
  points[2].y = *v24;
  points[2].z = *v31;
  points[3].x = (*fStartInnerPoints)[v12];
  points[3].y = *v26;
  points[3].z = *v32;
  CMapFace::CreateFace(this: &Face, pPoints: points, _nPoints: -4, bIsCordonFace: false);
  CMapSolid::AddFace(this: fEndOuterPointsa, pFace: &Face);
  points[0] = *(Vector *)&(*fStartOuterPoints)[v12];
  points[1].x = (*fStartOuterPoints)[v11];
  points[1].y = *v28;
  points[1].z = *v27;
  points[2] = *(Vector *)&(*fEndOuterPoints)[v11];
  points[3].x = (*fEndOuterPoints)[v12];
  points[3].y = *v25;
  points[3].z = *v30;
  CMapFace::CreateFace(this: &Face, pPoints: points, _nPoints: -4, bIsCordonFace: false);
  CMapSolid::AddFace(this: fEndOuterPointsa, pFace: &Face);
  if ( bCreateSouthFace != 0 )
  {
    points[0] = *(Vector *)&(*fStartInnerPoints)[v11];
    points[1].x = (*fStartInnerPoints)[v12];
    points[1].y = *v26;
    points[1].z = *v32;
    points[2].x = (*fEndInnerPoints)[v12];
    points[2].y = *v24;
    points[2].z = *v31;
    points[3].x = (*fEndInnerPoints)[v11];
    points[3].y = *v29;
    points[3].z = *(float *)p;
    CMapFace::CreateFace(this: &Face, pPoints: points, _nPoints: -4, bIsCordonFace: false);
    CMapSolid::AddFace(this: fEndOuterPointsa, pFace: &Face);
  }
  Id = CParticleOperatorDefinition<C_OP_RemapBoundingVolumetoCP>::GetId(this: (ConCommandBase *)&Options);
  CMapSolid::InitializeTextureAxes(this: fEndOuterPointsa, eAlignment: Id, dwFlags: 0x1Fu);
  v35 = -1;
  CMapFace::~CMapFace(this: &Face);
  return fEndOuterPointsa;
}

//------------------------------------------------------------------------------
// Address: 0x10016E80
// Name: void MakeArcCenterRadius(float,float,float,float,int,float,float,float (__near * const)[2])
// Source: json
//------------------------------------------------------------------------------
void __usercall MakeArcCenterRadius(
        __int64 a1@<esi:edi>,
        float xCenter,
        float yCenter,
        float xrad,
        float yrad,
        int npoints,
        float start_ang,
        float fArc,
        float (*points)[2])
{
  float v9; // xmm2_4
  float v10; // xmm0_4
  int v11; // ebx
  int v12; // esi
  _BYTE v13[12]; // [esp-10h] [ebp-14h]
  float f; // [esp+0h] [ebp-4h]

  v9 = fArc;
  v10 = start_ang;
  v11 = npoints;
  f = fArc / (float)npoints;
  *(_QWORD *)&v13[4] = a1;
  if ( fArc != 360.0 )
    v11 = npoints + 1;
  v12 = 0;
  if ( v11 > 0 )
  {
    do
    {
      if ( v10 > 360.0 )
      {
        v10 = v10 - 360.0;
        start_ang = v10;
      }
      __libm_sse2_cos(x: *(long double *)&v13[4]);
      (*points)[2 * v12] = rint(f: (float)((float)(v10 * 0.017453292) * xrad) + xCenter);
      __libm_sse2_sin(x: *(long double *)v13);
      (*points)[2 * v12 + 1] = rint(f: (float)((float)(v10 * 0.017453292) * yrad) + yCenter);
      v10 = f + start_ang;
      ++v12;
      start_ang = f + start_ang;
    }
    while ( v12 < v11 );
    v9 = fArc;
  }
  if ( v9 == 360.0 )
  {
    (*points)[2 * v12] = (*points)[0];
    (*points)[2 * v12 + 1] = (*points)[1];
  }
}

//------------------------------------------------------------------------------
// Address: 0x10016F80
// Name: void MakeArc(float,float,float,float,int,float,float,float (__near * const)[2])
// Source: json
//------------------------------------------------------------------------------
void __usercall MakeArc(
        __int64 a1@<esi:edi>,
        float x1,
        float y1,
        float x2,
        float y2,
        int npoints,
        float start_ang,
        float fArc,
        float (*points)[2])
{
  MakeArcCenterRadius(
    a1,
    xCenter: (float)((float)(x2 - x1) * 0.5) + x1,
    yCenter: (float)((float)(y2 - y1) * 0.5) + y1,
    xrad: (float)(x2 - x1) * 0.5,
    yrad: (float)(y2 - y1) * 0.5,
    npoints,
    start_ang,
    fArc,
    points);
}

//------------------------------------------------------------------------------
// Address: 0x10017000
// Name: class CMapClass __near * CreateArch(class BoundBox __near *,float,int,float,int,int,int)
// Source: json
//------------------------------------------------------------------------------
CMapClass *__usercall CreateArch@<eax>(
        int a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        BoundBox *pBox,
        float fStartAngle,
        int iSides,
        float fArc,
        int iWallWidth,
        int iAddHeight)
{
  float v9; // xmm1_4
  float v10; // xmm0_4
  unsigned __int64 v11; // rdi
  float v12; // xmm3_4
  float v13; // xmm4_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float y; // xmm0_4
  float x; // xmm1_4
  int i; // eax
  CMapClass *v20; // eax
  CMapClass *v21; // ebx
  float fZMin; // xmm1_4
  float z; // xmm0_4
  int v24; // ecx
  int v25; // eax
  CMapSolid *Segment; // esi
  void (__thiscall *DoTransform)(CMapAtom *, const VMatrix *); // edx
  const VMatrix *v28; // eax
  void (__thiscall *v29)(CMapAtom *, const VMatrix *); // edx
  float v30; // xmm6_4
  float xCenter[2]; // [esp+2Ch] [ebp-100D8h] BYREF
  float v36[11]; // [esp+802Ch] [ebp-80D8h] BYREF
  VMatrix v37; // [esp+1002Ch] [ebp-D8h] BYREF
  Vector v38; // [esp+1006Ch] [ebp-98h] BYREF
  Vector v39; // [esp+10078h] [ebp-8Ch] BYREF
  Vector v40; // [esp+10084h] [ebp-80h] BYREF
  float v41[2]; // [esp+10090h] [ebp-74h] BYREF
  Vector v42; // [esp+10098h] [ebp-6Ch] BYREF
  Vector size; // [esp+100A4h] [ebp-60h]
  Vector ptdest; // [esp+100B0h] [ebp-54h]
  Vector v45; // [esp+100BCh] [ebp-48h]
  VMatrix dst; // [esp+100C8h] [ebp-3Ch] BYREF
  float v47; // [esp+1011Ch] [ebp+18h]

  v9 = (float)(pBox->bmaxs.y - pBox->bmins.y) * 0.5;
  v10 = (float)(pBox->bmaxs.x - pBox->bmins.x) * 0.5;
  v11 = __PAIR64__((unsigned int)pBox, iSides);
  MakeArcCenterRadius(
    a1: __SPAIR64__((unsigned int)pBox, iSides),
    xCenter: v10 + pBox->bmins.x,
    yCenter: v9 + pBox->bmins.y,
    xrad: v10,
    yrad: v9,
    npoints: iSides,
    start_ang: fStartAngle,
    fArc,
    points: (float (*)[2])xCenter);
  v12 = (float)iWallWidth + pBox->bmins.x;
  v13 = pBox->bmins.y + (float)iWallWidth;
  v14 = (float)((float)(pBox->bmaxs.x - (float)iWallWidth) - v12) * 0.5;
  v15 = (float)((float)(pBox->bmaxs.y - (float)iWallWidth) - v13) * 0.5;
  MakeArcCenterRadius(
    a1: v11,
    xCenter: v14 + v12,
    yCenter: v15 + v13,
    xrad: v14,
    yrad: v15,
    npoints: v11,
    start_ang: fStartAngle,
    fArc,
    points: (float (*)[2])v36);
  LODWORD(dst.m[2][3]) = 1;
  BoundBox::GetBoundsCenter(this: pBox, ptdest: &v40);
  v16 = (float)(2 * iWallWidth + 8);
  if ( v16 >= (float)(pBox->bmaxs.x - pBox->bmins.x) || v16 >= (float)(pBox->bmaxs.y - pBox->bmins.y) )
  {
    y = v40.y;
    x = v40.x;
    for ( i = 0; i < 4096; ++i )
    {
      v36[2 * i] = x;
      v36[2 * i + 1] = y;
    }
    dst.m[2][3] = 0.0;
  }
  v20 = (CMapClass *)operator new(nSize: 0xE0u);
  v21 = v20;
  dst.m[3][2] = 0.0;
  if ( v20 != nullptr )
  {
    CMapClass::CMapClass(this: v20);
    v21->__vftable = (CMapClass_vtbl *)&CMapGroup::`vftable';
    v21[1].__vftable = (CMapClass_vtbl *)1203982208;
    v21[1].m_nObjectID = 1203982208;
    LOBYTE(dst.m[3][2]) = 0;
  }
  else
  {
    v21 = nullptr;
  }
  dst.m[3][2] = NAN;
  fZMin = pBox->bmins.z;
  dst.m[2][1] = 0.0;
  z = pBox->bmaxs.z;
  dst.m[1][1] = fZMin;
  dst.m[2][2] = z;
  if ( (float)(z - fZMin) < 1.0 )
  {
    z = fZMin + 1.0;
    dst.m[2][2] = fZMin + 1.0;
  }
  v24 = 0;
  v47 = 0.0;
  if ( iSides > 0 )
  {
    while ( 1 )
    {
      v25 = v24 + 1;
      LODWORD(dst.m[1][2]) = v24 + 1;
      if ( v24 + 1 >= (int)v11 + 1 )
        v25 = 0;
      Segment = CreateSegment(
                  fOuterPoints: (float (*)[2])xCenter,
                  iEnd: v25,
                  fZMin,
                  fZMax: z,
                  fInnerPoints: (float (*)[2])v36,
                  iStart: v24,
                  bCreateSouthFace: SLODWORD(dst.m[2][3]));
      v21->AddChild(this: v21, a2: Segment);
      if ( iAddHeight != 0 && v47 != 0.0 )
      {
        dst.m[2][1] = (float)iAddHeight + dst.m[2][1];
        MatrixSetIdentity(dst: (VMatrix *)&v42.y);
        DoTransform = Segment->DoTransform;
        size.y = 0.0;
        ptdest.z = 0.0;
        dst.m[0][0] = dst.m[2][1];
        DoTransform(this: Segment, a2: (const VMatrix *)&v42.y);
        Segment->PostUpdate(this: Segment, a2: Notify_Transform);
      }
      v47 = dst.m[1][2];
      if ( SLODWORD(dst.m[1][2]) >= iSides )
        break;
      z = dst.m[2][2];
      fZMin = dst.m[1][1];
      LODWORD(v11) = iSides;
      v24 = LODWORD(dst.m[1][2]);
    }
    HIDWORD(v11) = pBox;
  }
  ((void (__thiscall *)(CMapClass *, int, int, int, int))v21->CalcBounds)(a1: v21, a2: 1, a3: a2, a4: a3, a5: a1);
  if ( Options.general.bStretchArches != 0 )
  {
    BoundBox::GetBoundsSize(this: (BoundBox *)HIDWORD(v11), size: &v39);
    BoundBox::GetBoundsSize(this: &v21->m_Render2DBox, size: &v38);
    if ( v39.x > v38.x || v39.y > v38.y )
    {
      dst.m[1][3] = v39.x / v38.x;
      dst.m[2][0] = v39.y / v38.y;
      dst.m[2][1] = 1.0;
      BoundBox::GetBoundsCenter(this: (BoundBox *)HIDWORD(v11), ptdest: (Vector *)v41);
      MatrixSetIdentity(dst: (VMatrix *)&v42.y);
      v28 = VMatrix::Scale(this: (VMatrix *)&v42.y, result: &v37, vScale: (const Vector *)&dst.m[1][3]);
      VMatrix::operator=(this: (VMatrix *)&v42.y, mOther: v28);
      v29 = v21->DoTransform;
      v30 = 1.0
          / (float)((float)((float)((float)(v41[1] * dst.m[0][2]) + (float)(dst.m[0][1] * v41[0]))
                          + (float)(v42.x * dst.m[0][3]))
                  + dst.m[1][0]);
      size.y = v41[0]
             - (float)((float)((float)((float)((float)(v42.z * v41[1]) + (float)(v42.y * v41[0]))
                                     + (float)(size.x * v42.x))
                             + size.y)
                     * v30);
      ptdest.z = v41[1]
               - (float)((float)((float)((float)((float)(ptdest.x * v41[1]) + (float)(size.z * v41[0]))
                                       + (float)(ptdest.y * v42.x))
                               + ptdest.z)
                       * v30);
      dst.m[0][0] = v42.x
                  - (float)((float)((float)((float)((float)(v45.y * v41[1]) + (float)(v45.x * v41[0]))
                                          + (float)(v45.z * v42.x))
                                  + dst.m[0][0])
                          * v30);
      v29(this: v21, a2: (const VMatrix *)&v42.y);
      v21->PostUpdate(this: v21, a2: Notify_Transform);
    }
  }
  return v21;
}

//------------------------------------------------------------------------------
// Address: 0x100174D0
// Name: class CMapClass __near * CreateTorus(class BoundBox __near *,float,int,float,int,float,float,int,float,int,int)
// Source: json
//------------------------------------------------------------------------------
CMapClass *__usercall CreateTorus@<eax>(
        int a1@<ebx>,
        __int64 a2@<esi:edi>,
        BoundBox *pBox,
        float fStartAngle,
        int iSides,
        float fArc,
        int iWallWidth,
        float flCrossSectionalRadius,
        float fRotationStartAngle,
        int iRotationSides,
        float fRotationArc,
        int iAddHeight)
{
  float y; // xmm2_4
  float x; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm2_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  int v18; // eax
  float v19; // xmm4_4
  float v20; // xmm0_4
  int v21; // esi
  int i; // eax
  float *v23; // eax
  float *v24; // edi
  float v25; // xmm1_4
  float v26; // xmm0_4
  float *v27; // ebx
  bool v28; // zf
  double v29; // xmm0_8
  float v30; // xmm4_4
  float v31; // xmm5_4
  float *v32; // eax
  float *v33; // xmm3_4
  float v34; // xmm1_4
  float v35; // xmm2_4
  int v36; // edx
  __int64 v37; // rdi
  float *v38; // ecx
  float v39; // xmm6_4
  float v40; // xmm0_4
  float v41; // xmm6_4
  float v42; // xmm0_4
  CMapSolid *Segment_0; // eax
  const VMatrix *v44; // eax
  void (__thiscall *v45)(float *, VMatrix *); // edx
  float v46; // xmm6_4
  long double v48; // [esp+1Ch] [ebp-40114h]
  long double v49; // [esp+1Ch] [ebp-40114h]
  float v51[8202]; // [esp+18028h] [ebp-28108h] BYREF
  char v52; // [esp+2C028h] [ebp-14108h] BYREF
  float v53[10]; // [esp+38028h] [ebp-8108h] BYREF
  VMatrix v54; // [esp+40028h] [ebp-108h] BYREF
  Vector v55; // [esp+40068h] [ebp-C8h] BYREF
  Vector v56; // [esp+40074h] [ebp-BCh] BYREF
  Vector v57; // [esp+40080h] [ebp-B0h] BYREF
  Vector v58; // [esp+4008Ch] [ebp-A4h] BYREF
  VMatrix v59; // [esp+40098h] [ebp-98h] BYREF
  int v60; // [esp+400D8h] [ebp-58h]
  float v61; // [esp+400DCh] [ebp-54h]
  float (*v62)[3]; // [esp+400E0h] [ebp-50h]
  float v63; // [esp+400E4h] [ebp-4Ch]
  float (*v64)[3]; // [esp+400E8h] [ebp-48h]
  float v65; // [esp+400ECh] [ebp-44h]
  int v66; // [esp+400F0h] [ebp-40h]
  float v67; // [esp+400F4h] [ebp-3Ch]
  float v68; // [esp+400F8h] [ebp-38h]
  float v69; // [esp+400FCh] [ebp-34h]
  float v70; // [esp+40100h] [ebp-30h]
  float v71; // [esp+40104h] [ebp-2Ch]
  float (*fStartInnerPoints)[3]; // [esp+40108h] [ebp-28h]
  float v73; // [esp+4010Ch] [ebp-24h]
  float (*fStartOuterPoints)[3]; // [esp+40110h] [ebp-20h]
  int v75; // [esp+40114h] [ebp-1Ch]
  float *v76; // [esp+40118h] [ebp-18h]
  float v77; // [esp+4011Ch] [ebp-14h]
  float v78; // [esp+40120h] [ebp-10h]
  int v79; // [esp+4012Ch] [ebp-4h]
  float *v80; // [esp+40148h] [ebp+18h]
  char v81; // [esp+4014Fh] [ebp+1Fh]
  int v82; // [esp+40154h] [ebp+24h]
  int v83; // [esp+40158h] [ebp+28h]
  float v84; // [esp+4015Ch] [ebp+2Ch]

  y = pBox->bmaxs.y;
  x = pBox->bmaxs.x;
  v14 = (float)(pBox->bmins.x + x) * 0.5;
  v61 = (float)(pBox->bmins.y + y) * 0.5;
  v15 = y - v61;
  v16 = x - v14;
  v63 = v14;
  if ( v16 < 0.0 )
    v16 = 0.0;
  if ( v15 < 0.0 )
    v15 = 0.0;
  v17 = flCrossSectionalRadius;
  if ( flCrossSectionalRadius > (float)(v16 * 0.5) )
    v17 = v16 * 0.5;
  if ( v17 > (float)(v15 * 0.5) )
    v17 = v15 * 0.5;
  v18 = iWallWidth;
  if ( v17 <= (float)iWallWidth )
  {
    v18 = (int)v17;
    v19 = 0.0;
  }
  else
  {
    v19 = v17 - (float)iWallWidth;
  }
  HIDWORD(v48) = a2;
  LODWORD(a2) = iSides;
  v78 = (float)v18;
  v20 = (float)v18 + v19;
  v70 = v16 - v20;
  v69 = v15 - v20;
  MakeArcCenterRadius(
    a1: a2,
    xCenter: 0.0,
    yCenter: 0.0,
    xrad: v20,
    yrad: v20,
    npoints: iSides,
    start_ang: fStartAngle,
    fArc,
    points: (float (*)[2])v53);
  v75 = 1;
  if ( v19 == 0.0 )
  {
    v21 = 0;
    for ( i = 0; i < iSides; ++i )
    {
      v51[2 * i + 1] = 0.0;
      v51[2 * i] = 0.0;
    }
    v75 = 0;
  }
  else
  {
    MakeArcCenterRadius(
      a1: a2,
      xCenter: 0.0,
      yCenter: 0.0,
      xrad: v19,
      yrad: v19,
      npoints: a2,
      start_ang: fStartAngle,
      fArc,
      points: (float (*)[2])v51);
    v21 = 0;
  }
  *(float *)&v23 = COERCE_FLOAT(operator new(nSize: 0xE0u));
  v24 = v23;
  fStartOuterPoints = (float (*)[3])v23;
  v79 = 0;
  if ( *(float *)&v23 == 0.0 )
  {
    v80 = nullptr;
  }
  else
  {
    CMapClass::CMapClass(this: (CMapClass *)v23);
    *(_DWORD *)v24 = &CMapGroup::`vftable';
    v24[54] = 99999.0;
    v24[55] = 99999.0;
    LOBYTE(v79) = 0;
    v80 = v24;
  }
  LODWORD(v48) = a1;
  v79 = -1;
  v77 = (float)(pBox->bmins.z + v78) + v19;
  v25 = (float)iAddHeight;
  *(float *)&fStartOuterPoints = (float)iAddHeight / (float)iRotationSides;
  v26 = fRotationStartAngle;
  v27 = (float *)&v52;
  v84 = fRotationStartAngle;
  v71 = fRotationArc / (float)iRotationSides;
  if ( v25 != 0.0 || (v81 = 1, fRotationArc != 360.0) )
    v81 = 0;
  v28 = iRotationSides == -1;
  v82 = iRotationSides + 1;
  v83 = 0;
  if ( !v28 )
  {
    while ( 1 )
    {
      if ( v81 != 0 && v83 == v82 - 1 )
      {
        v26 = fRotationStartAngle;
        v84 = fRotationStartAngle;
      }
      v68 = v26 * 0.017453292;
      __libm_sse2_cos(x: v48);
      v73 = v26 * 0.017453292;
      v29 = v68;
      __libm_sse2_sin(x: v49);
      v30 = v73;
      v31 = v77;
      v62 = (float (*)[3])v27;
      v27 = &v51[12288 * v21 + 0x2000];
      v32 = v51 + 12288 * v21 + 24574;
      v60 = 1 - v21;
      *(float *)&v33 = v29;
      v34 = (float)(v73 * v70) + v63;
      v35 = (float)(*(float *)&v33 * v69) + v61;
      v36 = -1;
      v64 = (float (*)[3])(v27 + 2);
      fStartInnerPoints = (float (*)[3])v33;
      v67 = v34;
      v65 = v35;
      v78 = *(float *)&v32;
      v76 = v32;
      v37 = (unsigned int)(v27 + 2);
      v66 = (char *)v32 - (char *)v27;
      do
      {
        v38 = v76;
        v39 = v51[2 * HIDWORD(v37)];
        *(float *)(v37 - 4) = (float)(v39 * *(float *)&v33) + v35;
        *(float *)v37 = v51[2 * HIDWORD(v37) + 1] + v31;
        v40 = v53[2 * HIDWORD(v37)];
        *(float *)(v37 - 8) = (float)(v39 * v30) + v34;
        v41 = v40;
        v38[1] = (float)(v40 * *(float *)&v33) + v35;
        v42 = v53[2 * HIDWORD(v37) + 1];
        *v38 = (float)(v41 * v30) + v34;
        *(float *)(v66 + v37) = v42 + v31;
        if ( v83 != 0 && v36 != -1 )
        {
          Segment_0 = CreateSegment_0(
                        iEnd: SHIDWORD(v37),
                        iStart: v36,
                        fStartOuterPoints: v64,
                        fStartInnerPoints: v62,
                        fEndOuterPoints: (float (*)[3])v32,
                        fEndInnerPoints: (float (*)[3])v27,
                        bCreateSouthFace: v75);
          (*(void (__thiscall **)(float *, CMapSolid *))(*(_DWORD *)v80 + 104))(a1: v80, a2: Segment_0);
          v31 = v77;
          v30 = v73;
          v33 = (float *)fStartInnerPoints;
          v34 = v67;
          v35 = v65;
          *(float *)&v32 = v78;
        }
        v76 += 3;
        v36 = HIDWORD(v37)++;
        LODWORD(v37) = v37 + 12;
      }
      while ( v36 != iSides );
      v26 = v71 + v84;
      v77 = *(float *)&fStartOuterPoints + v31;
      v84 = v71 + v84;
      if ( v84 >= 360.0 )
      {
        v26 = v26 - 360.0;
        v84 = v26;
      }
      if ( ++v83 == v82 )
        break;
      v21 = v60;
    }
  }
  (*(void (__thiscall **)(float *, int, _DWORD, _DWORD))(*(_DWORD *)v80 + 176))(
    a1: v80,
    a2: 1,
    a3: LODWORD(v48),
    a4: HIDWORD(v48));
  if ( Options.general.bStretchArches == 0 )
    return (CMapClass *)v80;
  BoundBox::GetBoundsSize(this: pBox, size: &v56);
  BoundBox::GetBoundsSize(this: (BoundBox *)(v80 + 24), size: &v55);
  if ( v56.x > v55.x || v56.y > v55.y )
  {
    v58.x = v56.x / v55.x;
    v58.y = v56.y / v55.y;
    v58.z = 1.0;
    BoundBox::GetBoundsCenter(this: pBox, ptdest: &v57);
    MatrixSetIdentity(dst: &v59);
    v44 = VMatrix::Scale(this: &v59, result: &v54, vScale: &v58);
    VMatrix::operator=(this: &v59, mOther: v44);
    v45 = *(void (__thiscall **)(float *, VMatrix *))(*(_DWORD *)v80 + 76);
    v46 = 1.0
        / (float)((float)((float)((float)(v57.x * v59.m[3][0]) + (float)(v57.y * v59.m[3][1]))
                        + (float)(v57.z * v59.m[3][2]))
                + v59.m[3][3]);
    v59.m[0][3] = v57.x
                - (float)((float)((float)((float)((float)(v59.m[0][1] * v57.y) + (float)(v59.m[0][0] * v57.x))
                                        + (float)(v59.m[0][2] * v57.z))
                                + v59.m[0][3])
                        * v46);
    v59.m[1][3] = v57.y
                - (float)((float)((float)((float)((float)(v59.m[1][0] * v57.x) + (float)(v59.m[1][1] * v57.y))
                                        + (float)(v59.m[1][2] * v57.z))
                                + v59.m[1][3])
                        * v46);
    v59.m[2][3] = v57.z
                - (float)((float)((float)((float)((float)(v59.m[2][0] * v57.x) + (float)(v59.m[2][1] * v57.y))
                                        + (float)(v59.m[2][2] * v57.z))
                                + v59.m[2][3])
                        * v46);
    v45(a1: v80, a2: &v59);
    (*(void (__thiscall **)(float *, int))(*(_DWORD *)v80 + 60))(a1: v80, a2: 3);
  }
  return (CMapClass *)v80;
}

//------------------------------------------------------------------------------
// Address: 0x101222B0
// Name: public: virtual bool CMapGroup::IsVisibleLogical(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMapGroup::IsVisibleLogical(CMapGroup *this)
{
  return (*((_BYTE *)&this->CMapClass + 180) & 2) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10133430
// Name: public: virtual void CMapClass::SetParent(class CMapAtom __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapClass::SetParent(CMapClass *this, CMapClass *pParent)
{
  CMapClass::UpdateParent(this, pNewParent: pParent);
}
