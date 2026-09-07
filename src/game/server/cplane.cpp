// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cplane.cpp
// Functions: 4
// ============================================================

#include "game\server\cplane.h"

//------------------------------------------------------------------------------
// Address: 0x100F9C90
// Name: public: CPlane::CPlane(void)
// Source: json
//------------------------------------------------------------------------------
CPlane *__thiscall CPlane::CPlane(CPlane *this)
{
  this->m_fInitialized = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100F9CA0
// Name: public: void CPlane::InitializePlane(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlane::InitializePlane(CPlane *this, const Vector *vecNormal, const Vector *vecPoint)
{
  float z; // xmm0_4

  this->m_vecNormal.x = vecNormal->x;
  this->m_vecNormal.y = vecNormal->y;
  z = vecNormal->z;
  this->m_vecNormal.z = z;
  this->m_flDist = (float)((float)(vecPoint->y * this->m_vecNormal.y) + (float)(vecPoint->x * this->m_vecNormal.x))
                 + (float)(vecPoint->z * z);
  this->m_fInitialized = true;
}

//------------------------------------------------------------------------------
// Address: 0x100F9CF0
// Name: public: bool CPlane::PointInFront(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPlane::PointInFront(CPlane *this, const Vector *vecPoint)
{
  return this->m_fInitialized
      && (float)((float)((float)((float)(vecPoint->y * this->m_vecNormal.y) + (float)(vecPoint->x * this->m_vecNormal.x))
                       + (float)(vecPoint->z * this->m_vecNormal.z))
               - this->m_flDist) >= 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x100F9D40
// Name: public: float CPlane::PointDist(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CPlane::PointDist(CPlane *this, const Vector *vecPoint)
{
  if ( this->m_fInitialized )
    return vecPoint->y * this->m_vecNormal.y
         + vecPoint->x * this->m_vecNormal.x
         + vecPoint->z * this->m_vecNormal.z
         - this->m_flDist;
  else
    return 0.0;
}
