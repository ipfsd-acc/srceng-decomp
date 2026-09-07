// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: fow/fow_lineoccluder.cpp
// Functions: 2
// ============================================================

#include "fow\fow_lineoccluder.h"

//------------------------------------------------------------------------------
// Address: 0x101FCAA0
// Name: public: CFoW_LineOccluder::CFoW_LineOccluder(float,float,float,float,class Vector2D __near &,int)
// Source: json
//------------------------------------------------------------------------------
CFoW_LineOccluder *__thiscall CFoW_LineOccluder::CFoW_LineOccluder(
        CFoW_LineOccluder *this,
        Vector2D bx,
        Vector2D ex,
        Vector2D *vNormal,
        int nSliceNum)
{
  this->m_vStart = bx;
  this->m_vEnd = ex;
  CFOW_2DPlane::Init(this: &this->m_Plane, bx: bx.x, by: bx.y, ex: ex.x, ey: ex.y);
  if ( fabs(this->m_Plane.m_vNormal.x - vNormal->x) >= 0.1 )
  {
    this->m_nSliceNum = nSliceNum;
    return this;
  }
  else
  {
    if ( fabs(this->m_Plane.m_vNormal.y - vNormal->y) < 0.1 )
    {
      this->m_vStart = ex;
      this->m_vEnd = bx;
      CFOW_2DPlane::Init(this: &this->m_Plane, bx: ex.x, by: ex.y, ex: bx.x, ey: bx.y);
    }
    this->m_nSliceNum = nSliceNum;
    return this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FCBA0
// Name: public: void CFoW_LineOccluder::ObstructViewer(class CFoW __near *,class CFoW_Viewer __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CFoW_LineOccluder::ObstructViewer(
        CFoW_LineOccluder *this@<ecx>,
        long double a2@<esi:edi>,
        CFoW *pFoW,
        CFoW_Viewer *pViewer)
{
  float v5; // xmm1_4
  float v6; // xmm0_4
  float v7; // xmm4_4
  float v8; // xmm0_4
  float v9; // xmm2_4
  float v10; // xmm1_4
  float v11; // xmm7_4
  float v12; // xmm3_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm0_4
  int m_nRadiusUnits; // edi
  float v19; // xmm3_4
  int v20; // edx
  int i; // esi
  double v22; // st7
  long double v24; // [esp+10h] [ebp-5Ch]
  float v25[3]; // [esp+24h] [ebp-48h]
  float v26; // [esp+30h] [ebp-3Ch]
  int *m_pVisibilityRadius; // [esp+40h] [ebp-2Ch]
  float v28; // [esp+48h] [ebp-24h]
  CFOW_2DPlane *p_m_Plane; // [esp+4Ch] [ebp-20h]
  float v30; // [esp+50h] [ebp-1Ch]
  float v31; // [esp+54h] [ebp-18h]
  float v32; // [esp+5Ch] [ebp-10h]
  float v33; // [esp+5Ch] [ebp-10h]

  *(_QWORD *)v25 = *(_QWORD *)&pViewer->m_vRealLocation.x;
  m_pVisibilityRadius = pViewer->m_pVisibilityRadius;
  p_m_Plane = &this->m_Plane;
  if ( CFOW_2DPlane::DistanceFrom(this: &this->m_Plane, px: v25[0], py: v25[1]) >= 0.0 )
  {
    v5 = this->m_vStart.x - v25[0];
    v6 = this->m_vStart.y - v25[1];
    v26 = fsqrt((float)(v6 * v6) + (float)(v5 * v5));
    if ( v26 == 0.0 )
    {
      v8 = 0.0;
      v7 = 0.0;
    }
    else
    {
      v7 = (float)(1.0 / v26) * v5;
      v8 = v6 * (float)(1.0 / v26);
    }
    v9 = this->m_vEnd.x - v25[0];
    v10 = this->m_vEnd.y - v25[1];
    v11 = fsqrt((float)(v10 * v10) + (float)(v9 * v9));
    if ( v11 == 0.0 )
    {
      v13 = 0.0;
      v12 = 0.0;
    }
    else
    {
      v12 = (float)(1.0 / v11) * v9;
      v13 = v10 * (float)(1.0 / v11);
    }
    if ( fabs((float)(v13 * v8) + (float)(v12 * v7)) <= 0.99994999 )
    {
      __libm_sse2_acos(x: a2);
      v14 = (float)(v7 * 0.0) + v8;
      v32 = v14;
      if ( v7 < 0.0 )
        v32 = 6.2831855 - v14;
      __libm_sse2_acos(x: v24);
      v15 = (float)(v12 * 0.0) + v13;
      if ( v12 < 0.0 )
        v15 = 6.2831855 - v15;
      v16 = v32;
      if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(v32 - v15) & _mask__AbsFloat_) > 3.1415927 )
      {
        if ( v15 <= v32 )
          v15 = v15 + 6.2831855;
        else
          v16 = v32 + 6.2831855;
      }
      if ( v15 <= v16 )
      {
        v17 = v15;
        v15 = v16;
      }
      else
      {
        v17 = v16;
      }
      m_nRadiusUnits = pViewer->m_nRadiusUnits;
      v19 = 6.2831855 / (float)m_nRadiusUnits;
      v20 = (int)(float)(v17 / v19) % m_nRadiusUnits;
      v33 = v17;
      if ( v20 < 0 )
        v20 += m_nRadiusUnits;
      for ( i = v20; v15 > v17; v33 = v17 )
      {
        if ( i >= m_nRadiusUnits )
          i = 0;
        v30 = (float)(v17 * 40.743664) + 12582976.0;
        v31 = (float)(v17 * 40.743664) + 12582912.0;
        v22 = CFOW_2DPlane::DistanceFromRay(
                this: p_m_Plane,
                bx: v25[0],
                by: v25[1],
                dx: SinCosTable[LOBYTE(v31)],
                dy: SinCosTable[LOBYTE(v30)]);
        v28 = v22;
        if ( v22 >= 0.0 && (float)m_pVisibilityRadius[i] > (float)(v28 * v28) )
          m_pVisibilityRadius[i] = (int)(float)(v28 * v28);
        v17 = v19 + v33;
        ++i;
      }
    }
  }
}
