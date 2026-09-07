// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: fow/fow_2dplane.cpp
// Functions: 3
// ============================================================

#include "fow\fow_2dplane.h"

//------------------------------------------------------------------------------
// Address: 0x101FCEC0
// Name: public: float CFOW_2DPlane::DistanceFrom(float,float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CFOW_2DPlane::DistanceFrom(CFOW_2DPlane *this, float px, float py)
{
  return this->m_vNormal.y * py + this->m_vNormal.x * px - this->m_flDistance;
}

//------------------------------------------------------------------------------
// Address: 0x101FCEE0
// Name: public: float CFOW_2DPlane::DistanceFromRay(float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CFOW_2DPlane::DistanceFromRay(CFOW_2DPlane *this, float bx, float by, float dx, float dy)
{
  float y; // [esp+0h] [ebp-8h]
  float flNormalDiff; // [esp+18h] [ebp+10h]

  y = this->m_vNormal.y;
  flNormalDiff = (float)(this->m_vNormal.x * dx) + (float)(y * dy);
  if ( flNormalDiff == 0.0 )
    return 0.0;
  else
    return (this->m_vNormal.x * bx + y * by - this->m_flDistance) * (-1.0 / flNormalDiff);
}

//------------------------------------------------------------------------------
// Address: 0x101FCF50
// Name: public: void CFOW_2DPlane::Init(float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFOW_2DPlane::Init(CFOW_2DPlane *this, float bx, float by, float ex, float ey)
{
  float v5; // xmm1_4
  float v6; // xmm0_4
  float v7; // xmm1_4

  v5 = 1.0 / fsqrt((float)((float)(ey - by) * (float)(ey - by)) + (float)((float)(ex - bx) * (float)(ex - bx)));
  LODWORD(v6) = COERCE_UNSIGNED_INT(v5 * (float)(ex - bx)) ^ _mask__NegFloat_;
  v7 = v5 * (float)(ey - by);
  this->m_vNormal.y = v6;
  this->m_vNormal.x = v7;
  this->m_flDistance = (float)(v6 * by) + (float)(v7 * bx);
}
