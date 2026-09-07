// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: fow/fow_radiusoccluder.cpp
// Functions: 4
// ============================================================

#include "fow\fow_radiusoccluder.h"

//------------------------------------------------------------------------------
// Address: 0x101FC670
// Name: public: CFoW_RadiusOccluder::CFoW_RadiusOccluder(int)
// Source: json
//------------------------------------------------------------------------------
CFoW_RadiusOccluder *__thiscall CFoW_RadiusOccluder::CFoW_RadiusOccluder(CFoW_RadiusOccluder *this, int nID)
{
  this->m_nID = nID;
  this->m_flRadius = 0.0;
  *(_QWORD *)&this->m_vLocation.y = 0;
  this->m_vLocation.x = 0.0;
  *(_WORD *)&this->m_bEnabled = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101FC6A0
// Name: public: void CFoW_RadiusOccluder::UpdateSize(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoW_RadiusOccluder::UpdateSize(CFoW_RadiusOccluder *this, float flRadius)
{
  this->m_flRadius = flRadius;
}

//------------------------------------------------------------------------------
// Address: 0x101FC6C0
// Name: public: void CFoW_RadiusOccluder::UpdateLocation(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoW_RadiusOccluder::UpdateLocation(CFoW_RadiusOccluder *this, Vector *vLocation)
{
  this->m_vLocation = *vLocation;
}

//------------------------------------------------------------------------------
// Address: 0x101FC6E0
// Name: public: void CFoW_RadiusOccluder::ObstructViewerRadius(class CFoW __near *,class CFoW_Viewer __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CFoW_RadiusOccluder::ObstructViewerRadius(
        CFoW_RadiusOccluder *this@<ecx>,
        float a2@<ebp>,
        long double a3@<esi:edi>,
        CFoW *pFoW,
        CFoW_Viewer *pViewer)
{
  unsigned __int8 m_nHeightGroup; // al
  float z; // eax
  float v8; // xmm0_4
  __int128 v9; // xmm2
  float v10; // xmm4_4
  float v11; // xmm4_4
  float v12; // xmm2_4
  unsigned __int8 v13; // dl
  unsigned __int8 v14; // al
  float v15; // xmm1_4
  int m_nRadiusUnits; // edi
  float v17; // xmm1_4
  float v18; // xmm0_4
  int v19; // edx
  int v20; // esi
  double v21; // st7
  float v22; // xmm0_4
  long double v24; // [esp+10h] [ebp-5Ch]
  long double v25; // [esp+18h] [ebp-54h]
  _QWORD v26[2]; // [esp+20h] [ebp-4Ch] BYREF
  __int64 by; // [esp+34h] [ebp-38h]
  float ey; // [esp+3Ch] [ebp-30h]
  float v29; // [esp+40h] [ebp-2Ch]
  int *m_pVisibilityRadius; // [esp+44h] [ebp-28h]
  float v31; // [esp+48h] [ebp-24h]
  float m_nHorizontalGridSize; // [esp+4Ch] [ebp-20h]
  float v33; // [esp+50h] [ebp-1Ch]
  float v34; // [esp+54h] [ebp-18h]
  float m_flRadius; // [esp+58h] [ebp-14h]
  float v36; // [esp+5Ch] [ebp-10h]
  CFOW_2DPlane Plane; // [esp+60h] [ebp-Ch]
  float vars0; // [esp+6Ch] [ebp+0h]

  Plane.m_vNormal.x = a2;
  Plane.m_vNormal.y = vars0;
  if ( this->m_bEnabled )
  {
    m_flRadius = this->m_flRadius;
    if ( m_flRadius > 1.0 )
    {
      if ( pViewer->m_nHeightGroup == 0
        || (m_nHeightGroup = this->m_nHeightGroup) == 0
        || m_nHeightGroup >= (int)pViewer->m_nHeightGroup )
      {
        z = pViewer->m_vLocation.z;
        by = *(_QWORD *)&pViewer->m_vLocation.x;
        v8 = *(float *)&by - this->m_vLocation.x;
        v9 = 0;
        *(float *)&v9 = fsqrt(
                          (float)((float)((float)(*((float *)&by + 1) - this->m_vLocation.y)
                                        * (float)(*((float *)&by + 1) - this->m_vLocation.y))
                                + (float)(0.0 * 0.0))
                        + (float)(v8 * v8));
        *(_OWORD *)v26 = v9;
        v10 = *(float *)&v9;
        *(float *)&v9 = pViewer->m_flRadius + m_flRadius;
        ey = z;
        if ( *(float *)v26 <= *(float *)&v9 && m_flRadius < v10 )
        {
          __libm_sse2_atan2(y: a3, x: v25);
          v36 = v8 + 3.1415927;
          v34 = fsqrt((float)(*(float *)v26 * *(float *)v26) - (float)(this->m_flRadius * this->m_flRadius));
          __libm_sse2_asin(x: v24);
          v11 = v34;
          v12 = m_flRadius / *(float *)v26;
          v33 = v12 + (float)(v8 + 3.1415927);
          v34 = (float)(v33 * 40.743664) + 12582976.0;
          v13 = LOBYTE(v34);
          v36 = (float)(v8 + 3.1415927) - v12;
          m_flRadius = (float)(v33 * 40.743664) + 12582912.0;
          v34 = (float)(v36 * 40.743664) + 12582912.0;
          v14 = LOBYTE(v34);
          v15 = SinCosTable[LOBYTE(m_flRadius)];
          v34 = (float)(v36 * 40.743664) + 12582976.0;
          CFOW_2DPlane::Init(
            this: (CFOW_2DPlane *)((char *)v26 + 4),
            bx: (float)(SinCosTable[v14] * v11) + *(float *)&by,
            by: (float)(SinCosTable[LOBYTE(v34)] * v11) + *((float *)&by + 1),
            ex: (float)(v15 * v11) + *(float *)&by,
            ey: (float)(SinCosTable[v13] * v11) + *((float *)&by + 1));
          m_nRadiusUnits = pViewer->m_nRadiusUnits;
          m_pVisibilityRadius = pViewer->m_pVisibilityRadius;
          if ( CFOW_2DPlane::DistanceFrom(
                 this: (CFOW_2DPlane *)((char *)v26 + 4),
                 px: *(float *)&by,
                 py: *((float *)&by + 1)) >= 0.0 )
          {
            v17 = v33;
            if ( v36 <= v33 )
            {
              v18 = v36;
            }
            else
            {
              v18 = v33;
              v17 = v36;
            }
            v19 = (int)(float)(v18 / (float)(6.2831855 / (float)m_nRadiusUnits)) % m_nRadiusUnits;
            m_flRadius = v17;
            v36 = v18;
            v29 = 6.2831855 / (float)m_nRadiusUnits;
            if ( v19 < 0 )
              v19 += m_nRadiusUnits;
            m_nHorizontalGridSize = (float)pFoW->m_nHorizontalGridSize;
            v20 = v19;
            if ( v17 > v18 )
            {
              do
              {
                if ( v20 >= m_nRadiusUnits )
                  v20 = 0;
                v34 = (float)(v18 * 40.743664) + 12582976.0;
                v33 = (float)(v18 * 40.743664) + 12582912.0;
                v21 = CFOW_2DPlane::DistanceFromRay(
                        this: (CFOW_2DPlane *)((char *)v26 + 4),
                        bx: *(float *)&by,
                        by: *((float *)&by + 1),
                        dx: SinCosTable[LOBYTE(v33)],
                        dy: SinCosTable[LOBYTE(v34)]);
                v31 = v21;
                if ( v21 >= 0.0 )
                {
                  v22 = (float)((float)(m_nHorizontalGridSize * 1.1) + v31)
                      * (float)((float)(m_nHorizontalGridSize * 1.1) + v31);
                  if ( (float)m_pVisibilityRadius[v20] > v22 )
                    m_pVisibilityRadius[v20] = (int)v22;
                }
                v18 = v29 + v36;
                ++v20;
                v36 = v18;
              }
              while ( m_flRadius > v18 );
            }
          }
        }
      }
    }
    else
    {
      _Warning(a1: "FoW: Occluder %d has invalid radius\n", this->m_nID);
    }
  }
}
