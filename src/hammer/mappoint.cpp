// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/mappoint.cpp
// Functions: 4
// ============================================================

#include "hammer\mappoint.h"

//------------------------------------------------------------------------------
// Address: 0x1013D060
// Name: public: CMapPoint::CMapPoint(void)
// Source: json
//------------------------------------------------------------------------------
CMapPoint *__thiscall CMapPoint::CMapPoint(CMapPoint *this)
{
  this->__vftable = (CMapPoint_vtbl *)&CMapAtom::`vftable';
  this->m_eSelectionState = SELECT_NONE;
  this->m_pParent = nullptr;
  this->m_nObjectID = CMapAtom::s_nObjectIDCtr++;
  this->__vftable = (CMapPoint_vtbl *)&CMapPoint::`vftable';
  this->m_Origin.x = 0.0;
  this->m_Origin.y = 0.0;
  this->m_Origin.z = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1013D0A0
// Name: public: virtual void CMapPoint::GetOrigin(class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapPoint::GetOrigin(CCamera *this, Vector *ViewUp)
{
  *ViewUp = *(Vector *)&this->m_ViewMatrix.m[1][0];
}

//------------------------------------------------------------------------------
// Address: 0x1013D0C0
// Name: public: virtual void CMapPoint::SetOrigin(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapPoint::SetOrigin(CMapPoint *this, Vector *Origin)
{
  this->m_Origin = *Origin;
}

//------------------------------------------------------------------------------
// Address: 0x1013D0E0
// Name: protected: virtual void CMapPoint::DoTransform(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapPoint::DoTransform(CMapPoint *this, const VMatrix *matrix)
{
  float x; // xmm1_4
  float v3; // xmm0_4
  Vector m_Origin; // 0:^0.12

  m_Origin = this->m_Origin;
  x = this->m_Origin.x;
  v3 = 1.0
     / (float)((float)((float)((float)(matrix->m[3][0] * m_Origin.x) + (float)(matrix->m[3][1] * m_Origin.y))
                     + (float)(matrix->m[3][2] * m_Origin.z))
             + matrix->m[3][3]);
  this->m_Origin.x = (float)((float)((float)((float)(matrix->m[0][1] * m_Origin.y)
                                           + (float)(matrix->m[0][0] * m_Origin.x))
                                   + (float)(matrix->m[0][2] * m_Origin.z))
                           + matrix->m[0][3])
                   * v3;
  this->m_Origin.y = (float)((float)((float)((float)(matrix->m[1][0] * x) + (float)(matrix->m[1][1] * m_Origin.y))
                                   + (float)(matrix->m[1][2] * m_Origin.z))
                           + matrix->m[1][3])
                   * v3;
  this->m_Origin.z = (float)((float)((float)((float)(matrix->m[2][0] * x) + (float)(matrix->m[2][1] * m_Origin.y))
                                   + (float)(matrix->m[2][2] * m_Origin.z))
                           + matrix->m[2][3])
                   * v3;
}
