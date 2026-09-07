// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vbsp2lib/vbspmathutil.cpp
// Functions: 15
// ============================================================

#include "vbsp2lib\vbspmathutil.h"

//------------------------------------------------------------------------------
// Address: 0x1006ECD0
// Name: enum PlaneSide_t GetPlaneSide(class Vector const __near &,class Vector const __near &,struct Plane_t __near *)
// Source: json
//------------------------------------------------------------------------------
PlaneSide_t __cdecl GetPlaneSide(const Vector *vMin, const Vector *vMax, Plane_t *pPlane)
{
  int m_Type; // ecx
  PlaneSide_t result; // eax
  bool v5; // cc
  float x; // xmm7_4
  float v7; // xmm1_4
  float y; // xmm6_4
  float v9; // xmm1_4
  float z; // xmm5_4
  float v11; // xmm0_4
  float v12; // xmm2_4
  float v13; // xmm1_4
  float v14; // xmm7_4
  float v15; // xmm6_4
  float v16; // xmm0_4
  float vCorners_12; // [esp+10h] [ebp-Ch]
  float vCorners_16; // [esp+14h] [ebp-8h]

  m_Type = pPlane->m_Type;
  result = PLANE_SIDE_INVALID;
  if ( m_Type >= 3 )
  {
    if ( pPlane->m_vNormal.x >= 0.0 )
    {
      x = vMax->x;
      v7 = vMin->x;
    }
    else
    {
      x = vMin->x;
      v7 = vMax->x;
    }
    vCorners_12 = v7;
    if ( pPlane->m_vNormal.y >= 0.0 )
    {
      y = vMax->y;
      v9 = vMin->y;
    }
    else
    {
      y = vMin->y;
      v9 = vMax->y;
    }
    vCorners_16 = v9;
    if ( pPlane->m_vNormal.z >= 0.0 )
    {
      z = vMax->z;
      v11 = vMin->z;
    }
    else
    {
      z = vMin->z;
      v11 = vMax->z;
    }
    v12 = pPlane->m_vNormal.y;
    v13 = pPlane->m_vNormal.x * x;
    v14 = v12 * y;
    v15 = pPlane->m_vNormal.z;
    v16 = (float)((float)((float)(pPlane->m_vNormal.x * vCorners_12) + (float)(v12 * vCorners_16)) + (float)(v15 * v11))
        - pPlane->m_flDistance;
    if ( (float)((float)((float)(v13 + v14) + (float)(v15 * z)) - pPlane->m_flDistance) >= 0.1 )
      result = PLANE_SIDE_FRONT;
    v5 = v16 >= 0.1;
  }
  else
  {
    result = *(&vMax->x + m_Type) > (float)(pPlane->m_flDistance + 0.1);
    v5 = (float)(pPlane->m_flDistance - 0.1) <= *(&vMin->x + m_Type);
  }
  if ( !v5 )
    return result | 2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006EDF0
// Name: bool SnapVector(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SnapVector(Vector *vNormal)
{
  int v1; // ecx

  v1 = 0;
  while ( 1 )
  {
    if ( fabs(*(&vNormal->x + v1) - 1.0) < 0.0000099999997 )
    {
      *(_QWORD *)&vNormal->y = 0;
      vNormal->x = 0.0;
      *((_DWORD *)&vNormal->x + v1) = 1065353216;
      return 1;
    }
    if ( fabs(*(&vNormal->x + v1) - -1.0) < 0.0000099999997 )
      break;
    if ( ++v1 >= 3 )
      return 0;
  }
  *(_QWORD *)&vNormal->y = 0;
  vNormal->x = 0.0;
  *((_DWORD *)&vNormal->x + v1) = -1082130432;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1006EE80
// Name: class Vector TriangleNormal(class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
Vector *__cdecl TriangleNormal(Vector *result, const Vector *v0, const Vector *v1, const Vector *v2)
{
  float y; // xmm5_4
  float z; // xmm6_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm4_4
  float v10; // xmm5_4
  float v11; // xmm3_4

  y = v0->y;
  z = v0->z;
  v6 = v2->x - v0->x;
  v7 = v1->x - v0->x;
  v8 = v1->y - y;
  v9 = v2->y - y;
  v10 = v2->z - z;
  v11 = v1->z - z;
  result->x = (float)(v9 * v11) - (float)(v10 * v8);
  result->y = (float)(v7 * v10) - (float)(v6 * v11);
  result->z = (float)(v6 * v8) - (float)(v7 * v9);
  VectorNormalize(vec: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006EF20
// Name: bool IsPolygonTiny(class Polygon_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsPolygonTiny(Polygon_t *pPolygon)
{
  int m_Size; // edi
  int v2; // eax
  float *i; // ecx
  int v4; // esi
  int v5; // eax
  float v6; // xmm0_4
  Vector *m_pMemory; // [esp-8h] [ebp-14h]
  int v9; // [esp-4h] [ebp-10h]

  m_Size = pPolygon->m_Points.m_Size;
  v2 = 0;
  v9 = 0;
  if ( m_Size <= 0 )
    return 1;
  m_pMemory = pPolygon->m_Points.m_Memory.m_pMemory;
  for ( i = &m_pMemory->z; ; i += 3 )
  {
    v4 = v2 + 1;
    v5 = (v2 + 1) % m_Size;
    v6 = m_pMemory[v5].x - *(i - 2);
    if ( fsqrt(
           (float)((float)((float)(m_pMemory[v5].y - *(i - 1)) * (float)(m_pMemory[v5].y - *(i - 1)))
                 + (float)((float)(m_pMemory[v5].z - *i) * (float)(m_pMemory[v5].z - *i)))
         + (float)(v6 * v6)) > 0.2
      && ++v9 >= 3 )
    {
      break;
    }
    v2 = v4;
    if ( v4 >= m_Size )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1006EFF0
// Name: float ComputePolygonArea(class Polygon_t const __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl ComputePolygonArea(const Polygon_t *polygon)
{
  int m_Size; // edx
  Vector *m_pMemory; // ecx
  float *p_z; // eax
  int v4; // edx
  float v5; // xmm1_4
  float v6; // xmm0_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm5_4
  float v10; // xmm6_4
  float v12; // [esp-4h] [ebp-10h]

  m_Size = polygon->m_Points.m_Size;
  v12 = 0.0;
  if ( m_Size > 2 )
  {
    m_pMemory = polygon->m_Points.m_Memory.m_pMemory;
    p_z = &m_pMemory[1].z;
    v4 = m_Size - 2;
    do
    {
      v5 = p_z[2] - m_pMemory->y;
      v6 = *p_z - m_pMemory->z;
      v7 = p_z[1] - m_pMemory->x;
      v8 = p_z[3] - m_pMemory->z;
      v9 = *(p_z - 2) - m_pMemory->x;
      v10 = *(p_z - 1) - m_pMemory->y;
      p_z += 3;
      --v4;
      v12 = fsqrt(
              (float)((float)((float)((float)(v6 * v7) - (float)(v8 * v9)) * (float)((float)(v6 * v7) - (float)(v8 * v9)))
                    + (float)((float)((float)(v5 * v9) - (float)(v7 * v10))
                            * (float)((float)(v5 * v9) - (float)(v7 * v10))))
            + (float)((float)((float)(v8 * v10) - (float)(v5 * v6)) * (float)((float)(v8 * v10) - (float)(v5 * v6))))
          + v12;
    }
    while ( v4 != 0 );
  }
  return v12 * 0.5;
}

//------------------------------------------------------------------------------
// Address: 0x1006F0E0
// Name: public: void CVertexHash::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVertexHash::Purge(CVertexHash *this)
{
  this->m_Vertices.m_Size = 0;
  if ( this->m_Vertices.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Vertices.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Vertices.m_Memory.m_pMemory);
      this->m_Vertices.m_Memory.m_pMemory = nullptr;
    }
    this->m_Vertices.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Vertices.m_pElements = this->m_Vertices.m_Memory.m_pMemory;
  this->m_VertexHashChain.m_Size = 0;
  if ( this->m_VertexHashChain.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_VertexHashChain.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_VertexHashChain.m_Memory.m_pMemory);
      this->m_VertexHashChain.m_Memory.m_pMemory = nullptr;
    }
    this->m_VertexHashChain.m_Memory.m_nAllocationCount = 0;
  }
  this->m_VertexHashChain.m_pElements = this->m_VertexHashChain.m_Memory.m_pMemory;
  _V_memset(dest: (unsigned __int8 *)this, fill: 0xFFu, count: 0x10000u);
}

//------------------------------------------------------------------------------
// Address: 0x1006F180
// Name: void CreatePolygonFromPlane(class Vector const __near &,float,class Polygon_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CreatePolygonFromPlane(const Vector *vNormal, float flDistance, Polygon_t *pPolygon)
{
  float v3; // xmm1_4
  int v4; // edi
  float v5; // xmm0_4
  float v6; // xmm0_4
  float x; // xmm5_4
  float z; // xmm4_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm3_4
  float y; // xmm0_4
  float v13; // xmm4_4
  int m_Size; // edi
  int m_nAllocationCount; // ecx
  float v16; // xmm5_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm0_4
  Vector *m_pMemory; // ecx
  int v21; // eax
  Vector *v22; // eax
  float v23; // xmm4_4
  float v24; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm5_4
  float v27; // xmm3_4
  float v28; // xmm2_4
  float org_4; // [esp+4h] [ebp-20h]
  float org_8; // [esp+8h] [ebp-1Ch]
  float vright; // [esp+Ch] [ebp-18h]
  Vector vup; // [esp+18h] [ebp-Ch] BYREF

  v3 = -1.0;
  v4 = -1;
  v5 = fabs(vNormal->x);
  if ( v5 > -1.0 )
  {
    v4 = 0;
    v3 = v5;
  }
  v6 = fabs(vNormal->y);
  if ( v6 > v3 )
  {
    v4 = 1;
    v3 = v6;
  }
  if ( fabs(vNormal->z) <= v3 )
  {
    if ( v4 == -1 )
      _Error(a1: "BasePolygonForPlane: no axis found");
  }
  else
  {
    v4 = 2;
  }
  x = vec3_origin.x;
  z = vec3_origin.z;
  if ( v4 >= 0 )
  {
    if ( v4 <= 1 )
      z = 1.0;
    else
      x = 1.0;
  }
  LODWORD(v9) = COERCE_UNSIGNED_INT((float)((float)(vNormal->y * vec3_origin.y) + (float)(vNormal->x * x)) + (float)(vNormal->z * z))
              ^ _mask__NegFloat_;
  v10 = (float)(vNormal->y * v9) + vec3_origin.y;
  v11 = (float)(vNormal->z * v9) + z;
  vup.x = (float)(vNormal->x * v9) + x;
  vup.y = v10;
  vup.z = v11;
  VectorNormalize(vec: &vup);
  y = vNormal->y;
  v13 = vNormal->z;
  m_Size = pPolygon->m_Points.m_Size;
  m_nAllocationCount = pPolygon->m_Points.m_Memory.m_nAllocationCount;
  org_4 = y * flDistance;
  v16 = vNormal->x * flDistance;
  org_8 = v13 * flDistance;
  v17 = (float)(v13 * vup.y) - (float)(y * vup.z);
  v18 = (float)((float)(vNormal->x * vup.z) - (float)(v13 * vup.x)) * 65536.0;
  v19 = (float)((float)(y * vup.x) - (float)(vNormal->x * vup.y)) * 65536.0;
  vup.x = vup.x * 65536.0;
  vup.y = vup.y * 65536.0;
  vup.z = vup.z * 65536.0;
  vright = v17 * 65536.0;
  if ( m_Size + 4 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      this: (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)&pPolygon->m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >,
      num: m_Size - m_nAllocationCount + 4);
  pPolygon->m_Points.m_Size += 4;
  m_pMemory = pPolygon->m_Points.m_Memory.m_pMemory;
  v21 = pPolygon->m_Points.m_Size - m_Size - 4;
  pPolygon->m_Points.m_pElements = m_pMemory;
  if ( v21 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 4],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 12 * v21);
  v22 = pPolygon->m_Points.m_Memory.m_pMemory;
  v23 = org_8 - v19;
  v22->z = org_8 - v19;
  v24 = v19 + org_8;
  v25 = v16 - vright;
  v22->x = v16 - vright;
  v26 = v16 + vright;
  v27 = org_4 - v18;
  v22->y = org_4 - v18;
  v28 = v18 + org_4;
  v22->x = v25 + vup.x;
  v22->y = v22->y + vup.y;
  v22->z = v22->z + vup.z;
  v22[1].z = v24;
  v22[1].x = v26;
  v22[1].y = v28;
  v22[1].x = v26 + vup.x;
  v22[1].y = v22[1].y + vup.y;
  v22[1].z = v22[1].z + vup.z;
  v22[2].z = v24;
  v22[2].x = v26;
  v22[2].y = v28;
  v22[2].x = v26 - vup.x;
  v22[2].y = v22[2].y - vup.y;
  v22[2].z = v22[2].z - vup.z;
  v22[3].x = v25;
  v22[3].y = v27;
  v22[3].z = v23;
  v22[3].x = v25 - vup.x;
  v22[3].y = v22[3].y - vup.y;
  v22[3].z = v22[3].z - vup.z;
}

//------------------------------------------------------------------------------
// Address: 0x1006F4D0
// Name: void ChopPolygonInPlace(class Polygon_t __near *,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ChopPolygonInPlace(Polygon_t *pPolygon, const Vector *vNormal, float flDistance)
{
  Polygon_t *v3; // ebx
  int m_Size; // ecx
  int v5; // esi
  int v6; // eax
  float y; // xmm1_4
  float x; // xmm2_4
  float z; // xmm3_4
  Vector *m_pMemory; // edi
  float v11; // xmm0_4
  float v12; // xmm0_4
  int v13; // edx
  float *p_z; // edi
  Vector *v15; // ebx
  int v16; // edx
  double v17; // st7
  int v18; // eax
  float v19; // xmm1_4
  Vector *v20; // eax
  const Vector *v21; // ecx
  int v22; // edx
  int v23; // ecx
  Vector vNewPolygonPoints[68]; // [esp+4h] [ebp-574h] BYREF
  float flPlaneDistances[68]; // [esp+334h] [ebp-244h]
  int nSides[68]; // [esp+444h] [ebp-134h]
  Vector *v27; // [esp+554h] [ebp-24h]
  int v28; // [esp+558h] [ebp-20h]
  int v29; // [esp+55Ch] [ebp-1Ch]
  int v30; // [esp+560h] [ebp-18h]
  int v31; // [esp+564h] [ebp-14h]
  Vector vMid; // [esp+568h] [ebp-10h] BYREF
  int nNewPolygonPoints; // [esp+574h] [ebp-4h]

  v3 = pPolygon;
  m_Size = pPolygon->m_Points.m_Size;
  v28 = m_Size;
  if ( m_Size >= 64 )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
      _LoggingSystem_Log(a1: LOG_VBSP2, a2: 3, a3: "Too many points in polygon.\n");
    return;
  }
  v5 = 0;
  v6 = 0;
  memset(&vMid, 0, sizeof(vMid));
  if ( m_Size > 0 )
  {
    y = vNormal->y;
    x = vNormal->x;
    z = vNormal->z;
    m_pMemory = pPolygon->m_Points.m_Memory.m_pMemory;
    do
    {
      v11 = (float)((float)((float)(m_pMemory->y * y) + (float)(x * m_pMemory->x)) + (float)(m_pMemory->z * z))
          - flDistance;
      flPlaneDistances[v6] = v11;
      if ( v11 <= 0.0099999998 )
      {
        if ( v11 >= -0.0099999998 )
          nSides[v6] = 2;
        else
          nSides[v6] = 1;
      }
      else
      {
        nSides[v6] = 0;
      }
      ++*((_DWORD *)&vMid.x + nSides[v6++]);
      ++m_pMemory;
    }
    while ( v6 < m_Size );
  }
  v12 = flPlaneDistances[0];
  nSides[v6] = nSides[0];
  flPlaneDistances[v6] = v12;
  if ( LODWORD(vMid.x) == 0 )
  {
    pPolygon->m_Points.m_Size = 0;
    return;
  }
  if ( LODWORD(vMid.y) != 0 )
  {
    v13 = 0;
    nNewPolygonPoints = 0;
    if ( m_Size <= 0 )
      goto LABEL_34;
    v27 = pPolygon->m_Points.m_Memory.m_pMemory;
    p_z = &v27->z;
    v15 = vNewPolygonPoints;
    v29 = -8 - (_DWORD)vNormal;
    while ( 1 )
    {
      v16 = nSides[v5];
      if ( v16 == 2 )
      {
        v15->x = *(p_z - 2);
        v15->y = *(p_z - 1);
        v15->z = *p_z;
      }
      else
      {
        if ( v16 == 0 )
        {
          v17 = *(p_z - 2);
          ++nNewPolygonPoints;
          v15->x = v17;
          ++v15;
          v15[-1].y = *(p_z - 1);
          v15[-1].z = *p_z;
        }
        v18 = nSides[v5 + 1];
        if ( v18 == 2 || v18 == v16 )
          goto LABEL_32;
        v19 = flPlaneDistances[v5] / (float)(flPlaneDistances[v5] - flPlaneDistances[v5 + 1]);
        v31 = 3;
        v20 = &v27[(v5 + 1) % m_Size];
        v21 = vNormal;
        v30 = (char *)v20 - (char *)vNormal;
        v22 = (char *)&vMid - (char *)vNormal;
        do
        {
          if ( v21->x == 1.0 )
          {
            *(float *)((char *)&v21->x + v22) = flDistance;
          }
          else if ( v21->x == -1.0 )
          {
            *(float *)((char *)&v21->x + v22) = -flDistance;
          }
          else
          {
            *(float *)((char *)&v21->x + v22) = (float)((float)(*(float *)((char *)&v21->x + v30)
                                                              - *(float *)((char *)p_z + v29 + (_DWORD)v21))
                                                      * v19)
                                              + *(float *)((char *)p_z + v29 + (_DWORD)v21);
          }
          v21 = (const Vector *)((char *)v21 + 4);
          --v31;
        }
        while ( v31 != 0 );
        m_Size = v28;
        *v15 = vMid;
      }
      ++nNewPolygonPoints;
      ++v15;
LABEL_32:
      ++v5;
      p_z += 3;
      if ( v5 >= m_Size )
      {
        v3 = pPolygon;
        v13 = nNewPolygonPoints;
LABEL_34:
        if ( v13 > m_Size + 4 )
        {
          _Error(a1: "ChopPolygonInPlace: Num points exceeded estimate");
          v3 = pPolygon;
          v13 = nNewPolygonPoints;
        }
        if ( v13 > 64 )
        {
          _Error(a1: "ChopPolygonInPlace: Exceeded MAX_POINTS_ON_POLYGON");
          v3 = pPolygon;
          v13 = nNewPolygonPoints;
        }
        v23 = v3->m_Points.m_Size;
        if ( v13 - v23 <= 0 )
        {
          if ( v13 - v23 < 0 )
            v3->m_Points.m_Size = v13;
        }
        else
        {
          CUtlVector<dbrush_t,CUtlMemory<dbrush_t,int>>::InsertMultipleBefore(
            this: &v3->m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >,
            elem: v23,
            num: v13 - v23);
          v13 = nNewPolygonPoints;
        }
        memcpy(
          dst: (unsigned __int8 *)v3->m_Points.m_Memory.m_pMemory,
          src: (unsigned __int8 *)vNewPolygonPoints,
          count: 12 * v13);
        return;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006F7F0
// Name: public: CPlaneHash::CPlaneHash(void)
// Source: json
//------------------------------------------------------------------------------
CPlaneHash *__thiscall CPlaneHash::CPlaneHash(CPlaneHash *this)
{
  this->m_Planes.m_Memory.m_pMemory = nullptr;
  this->m_Planes.m_Memory.m_nAllocationCount = 0;
  this->m_Planes.m_Memory.m_nGrowSize = 0;
  this->m_Planes.m_Size = 0;
  this->m_Planes.m_pElements = nullptr;
  this->m_Planes.__vftable = (CCopyableUtlVector<HashedPlane_t>_vtbl *)&CCopyableUtlVector<HashedPlane_t>::`vftable';
  memset(dst: (unsigned __int8 *)this->m_HashTable, value: 0xFFu, count: sizeof(this->m_HashTable));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1006F830
// Name: private: struct HashedPlane_t __near * CPlaneHash::AllocateNewPlane(void)
// Source: json
//------------------------------------------------------------------------------
HashedPlane_t *__thiscall CPlaneHash::AllocateNewPlane(CPlaneHash *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  HashedPlane_t *m_pMemory; // ecx
  int v5; // eax
  HashedPlane_t *v6; // eax

  m_nAllocationCount = this->m_Planes.m_Memory.m_nAllocationCount;
  m_Size = this->m_Planes.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,void *,int>::Node_t,int>,int>::Grow(
      this: (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)&this->m_Planes.CUtlVector<HashedPlane_t,CUtlMemory<HashedPlane_t,int> >,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Planes.m_Size;
  m_pMemory = this->m_Planes.m_Memory.m_pMemory;
  v5 = this->m_Planes.m_Size - m_Size - 1;
  this->m_Planes.m_pElements = m_pMemory;
  if ( v5 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 24 * v5);
  v6 = &this->m_Planes.m_Memory.m_pMemory[this->m_Planes.m_Size - 1];
  *(_QWORD *)&v6->m_vNormal.x = 0;
  *(_QWORD *)&v6->m_vNormal.z = 0;
  *(_QWORD *)&v6->m_Type = 0;
  v6->m_nNextPlaneIndex = -1;
  return &this->m_Planes.m_Memory.m_pMemory[this->m_Planes.m_Size - 1];
}

//------------------------------------------------------------------------------
// Address: 0x1006F8C0
// Name: public: CVertexHash::CVertexHash(void)
// Source: json
//------------------------------------------------------------------------------
CVertexHash *__thiscall CVertexHash::CVertexHash(CVertexHash *this)
{
  this->m_VertexHashChain.m_Memory.m_pMemory = nullptr;
  this->m_VertexHashChain.m_Memory.m_nAllocationCount = 0;
  this->m_VertexHashChain.m_Memory.m_nGrowSize = 0;
  this->m_VertexHashChain.m_Size = 0;
  this->m_VertexHashChain.m_pElements = nullptr;
  this->m_Vertices.m_Memory.m_pMemory = nullptr;
  this->m_Vertices.m_Memory.m_nAllocationCount = 0;
  this->m_Vertices.m_Memory.m_nGrowSize = 0;
  this->m_Vertices.m_Size = 0;
  this->m_Vertices.m_pElements = nullptr;
  _V_memset(dest: (unsigned __int8 *)this, fill: 0xFFu, count: 0x10000u);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1006F920
// Name: public: int CVertexHash::FindVertexIndex(class Vector const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVertexHash::FindVertexIndex(CVertexHash *this, const Vector *vertex, bool bAlwaysAdd)
{
  const Vector *v3; // esi
  int v4; // ebx
  int v5; // edi
  int v6; // eax
  unsigned int v7; // eax
  int result; // eax
  float *v9; // ecx
  CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *v10; // esi
  UtlLinkedListElem_t<vgui::TreeNode *,int> *m_pMemory; // edi
  int m_nAllocationCount; // eax
  int v13; // ebx
  UtlLinkedListElem_t<vgui::TreeNode *,int> *v14; // ecx
  int v15; // eax
  Vector *v16; // eax
  int v17; // edi
  int m_nGrowSize; // eax
  int v19; // ecx
  int v20; // eax
  _DWORD *v21; // eax
  int nBucket[3]; // [esp+0h] [ebp-1Ch] BYREF
  Vector roundedVertex; // [esp+Ch] [ebp-10h] BYREF
  CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *v24; // [esp+18h] [ebp-4h]
  int nBucketIndex; // [esp+24h] [ebp+8h]
  int nBucketIndexa; // [esp+24h] [ebp+8h]

  v3 = vertex;
  v4 = (char *)&roundedVertex - (char *)vertex;
  v24 = (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this;
  v5 = (char *)nBucket - (char *)vertex;
  for ( nBucketIndex = 3; nBucketIndex != 0; --nBucketIndex )
  {
    v6 = (int)(float)(v3->x + 0.5);
    if ( fabs(v3->x - (float)v6) >= 0.0099999998 )
      *(float *)((char *)&v3->x + v4) = v3->x;
    else
      *(float *)((char *)&v3->x + v4) = (float)v6;
    v7 = (v6 + 0x4000) >> 8;
    *(_DWORD *)((char *)&v3->x + v5) = v7;
    if ( v7 >= 0x80 && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
      _LoggingSystem_Log(a1: LOG_VBSP2, a2: 3, a3: "CVertexHash::FindVertexIndex: point outside valid range.\n");
    v3 = (const Vector *)((char *)v3 + 4);
  }
  nBucketIndexa = nBucket[0] + (nBucket[1] << 7);
  if ( bAlwaysAdd || (result = *((_DWORD *)&v24->m_pMemory + 128 * nBucket[1] + nBucket[0])) == -1 )
  {
LABEL_15:
    v10 = v24;
    m_pMemory = v24[5464].m_pMemory;
    m_nAllocationCount = v24[5463].m_nAllocationCount;
    v13 = v24[5462].m_nAllocationCount;
    if ( (int)&m_pMemory->m_Element + 1 > m_nAllocationCount )
      CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
        this: v24 + 5463,
        num: (int)&m_pMemory->m_Element - m_nAllocationCount + 1);
    ++v10[5464].m_pMemory;
    v14 = v10[5463].m_pMemory;
    v15 = (char *)v10[5464].m_pMemory - (char *)m_pMemory - 1;
    v10[5464].m_nAllocationCount = (int)v14;
    if ( v15 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&v14[(int)m_pMemory + 1],
        src: (unsigned __int8 *)&v14[(_DWORD)m_pMemory],
        count: 12 * v15);
    v16 = (Vector *)&v10[5463].m_pMemory[(_DWORD)m_pMemory];
    if ( v16 != nullptr )
      *v16 = roundedVertex;
    v17 = v10[5462].m_nAllocationCount;
    m_nGrowSize = v10[5461].m_nGrowSize;
    if ( v17 + 1 > m_nGrowSize )
      CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&v10[5461].m_nAllocationCount,
        num: v17 - m_nGrowSize + 1);
    ++v10[5462].m_nAllocationCount;
    v19 = v10[5461].m_nAllocationCount;
    v20 = v10[5462].m_nAllocationCount - v17 - 1;
    v10[5462].m_nGrowSize = v19;
    if ( v20 > 0 )
      _V_memmove(dest: (unsigned __int8 *)(v19 + 4 * v17 + 4), src: (unsigned __int8 *)(v19 + 4 * v17), count: 4 * v20);
    v21 = (_DWORD *)(v10[5461].m_nAllocationCount + 4 * v17);
    if ( v21 != nullptr )
      *v21 = *((_DWORD *)&v10->m_pMemory + nBucketIndexa);
    *((_DWORD *)&v10->m_pMemory + nBucketIndexa) = v13;
    return v13;
  }
  else
  {
    while ( 1 )
    {
      v9 = (float *)&v24[5463].m_pMemory[result];
      if ( fabs(*v9 - roundedVertex.x) < 0.1
        && fabs(v9[1] - roundedVertex.y) < 0.1
        && fabs(v9[2] - roundedVertex.z) < 0.1 )
      {
        break;
      }
      result = *(_DWORD *)(v24[5461].m_nAllocationCount + 4 * result);
      if ( result == -1 )
        goto LABEL_15;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006FB80
// Name: public: int CPlaneHash::FindPlaneIndex(class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPlaneHash::FindPlaneIndex(CPlaneHash *this, const Vector *vNormal, float flDistance)
{
  float v4; // xmm5_4
  __m128 v5; // xmm2
  __m128 v6; // xmm0
  __m128 v7; // xmm4
  __m128 v8; // xmm1
  __m128 v9; // xmm2
  float v10; // xmm0_4
  int v11; // ebx
  float y; // xmm6_4
  float z; // xmm4_4
  int v14; // esi
  int result; // eax
  HashedPlane_t *v16; // ecx
  HashedPlane_t *NewPlane; // esi
  HashedPlane_t *v18; // eax
  HashedPlane_t *v19; // ecx
  float v20; // xmm0_4
  float v21; // xmm2_4
  float v22; // xmm1_4
  int v23; // eax
  int v24; // edx
  __int64 v25; // xmm0_8
  float v26; // eax
  double m_flDistance; // st7
  Vector vTemp; // 0:^C.12

  v4 = flDistance;
  v5.m128_i32[0] = 1258291200;
  v6 = (__m128)LODWORD(flDistance);
  v6.m128_f32[0] = flDistance + 0.5;
  v7 = _mm_and_ps((__m128)0x80000000, v6);
  v5.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v6, v7), v5).m128_f32[0]) & 0x4B000000 | v7.m128_i32[0];
  v8 = v6;
  v8.m128_f32[0] = (float)((float)(flDistance + 0.5) + v5.m128_f32[0]) - v5.m128_f32[0];
  v9 = v8;
  v9.m128_f32[0] = v8.m128_f32[0] - (float)(flDistance + 0.5);
  v10 = v8.m128_f32[0] - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v9, v7).m128_f32[0]) & 0x3F800000);
  v11 = ((int)fabs(flDistance) / 8) & 0x3FF;
  if ( fabs(flDistance - v10) < 0.0099999998 )
  {
    v4 = v10;
    flDistance = v10;
  }
  vTemp = *vNormal;
  if ( fabs(vNormal->x) < 0.0000099999997 )
    vTemp.x = 0.0;
  y = vTemp.y;
  if ( fabs(vTemp.y) < 0.0000099999997 )
  {
    y = 0.0;
    vTemp.y = 0.0;
  }
  z = vNormal->z;
  if ( fabs(vTemp.z) < 0.0000099999997 )
  {
    z = 0.0;
    vTemp.z = 0.0;
  }
  v14 = -1;
  while ( 1 )
  {
    result = this->m_HashTable[((_WORD)v14 + (_WORD)v11) & 0x3FF];
    if ( result != -1 )
      break;
LABEL_16:
    if ( ++v14 > 1 )
    {
      NewPlane = CPlaneHash::AllocateNewPlane(this);
      v18 = CPlaneHash::AllocateNewPlane(this);
      NewPlane->m_vNormal = vTemp;
      v19 = v18;
      v18->m_vNormal.x = -vTemp.x;
      v18->m_vNormal.y = -vTemp.y;
      v18->m_vNormal.z = -vTemp.z;
      NewPlane->m_flDistance = flDistance;
      v18->m_flDistance = -flDistance;
      if ( vTemp.x == 1.0 || vTemp.x == -1.0 )
      {
        v23 = 0;
      }
      else if ( vTemp.y == 1.0 || vTemp.y == -1.0 )
      {
        v23 = 1;
      }
      else if ( vTemp.z == 1.0 || vTemp.z == -1.0 )
      {
        v23 = 2;
      }
      else
      {
        v20 = fabs(vTemp.x);
        v21 = fabs(vTemp.y);
        v22 = fabs(vTemp.z);
        if ( v20 < v21 || v20 < v22 )
        {
          if ( v21 < v20 || v21 < v22 )
            v23 = 5;
          else
            v23 = 4;
        }
        else
        {
          v23 = 3;
        }
      }
      v19->m_Type = v23;
      NewPlane->m_Type = v23;
      result = this->m_Planes.m_Size - 2;
      v24 = result + 1;
      NewPlane->m_nNextPlaneIndex = result + 1;
      v19->m_nNextPlaneIndex = this->m_HashTable[v11];
      this->m_HashTable[v11] = result;
      if ( NewPlane->m_Type < 3
        && (NewPlane->m_vNormal.x < 0.0 || NewPlane->m_vNormal.y < 0.0 || NewPlane->m_vNormal.z < 0.0) )
      {
        v25 = *(_QWORD *)&NewPlane->m_vNormal.x;
        v26 = NewPlane->m_vNormal.z;
        NewPlane->m_vNormal.x = v19->m_vNormal.x;
        NewPlane->m_vNormal.y = v19->m_vNormal.y;
        NewPlane->m_vNormal.z = v19->m_vNormal.z;
        LODWORD(v19->m_vNormal.x) = v25;
        m_flDistance = v19->m_flDistance;
        v19->m_vNormal.y = *((float *)&v25 + 1);
        v19->m_vNormal.z = v26;
        *(float *)&v25 = NewPlane->m_flDistance;
        NewPlane->m_flDistance = m_flDistance;
        LODWORD(v19->m_flDistance) = v25;
        return v24;
      }
      return result;
    }
  }
  while ( 1 )
  {
    v16 = &this->m_Planes.m_Memory.m_pMemory[result];
    if ( fabs(v16->m_vNormal.x - vTemp.x) < 0.0000099999997
      && fabs(v16->m_vNormal.y - y) < 0.0000099999997
      && fabs(v16->m_vNormal.z - z) < 0.0000099999997
      && fabs(v16->m_flDistance - v4) < 0.0099999998 )
    {
      return result;
    }
    result = v16->m_nNextPlaneIndex;
    if ( result == -1 )
      goto LABEL_16;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006FEA0
// Name: public: int CPlaneHash::FindPlaneIndex(class Vector __near * const)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CPlaneHash::FindPlaneIndex@<eax>(CPlaneHash *this@<ecx>, int a2@<ebp>, Vector *vPoints)
{
  float v4; // xmm1_4
  float v5; // xmm3_4
  float v6; // xmm2_4
  float v7; // xmm0_4
  float v8; // xmm4_4
  float v9; // xmm5_4
  float z; // xmm4_4
  __m128 y_low; // xmm7
  __m128 v13; // xmm6
  __m128 v14; // xmm0
  __m128 v15; // xmm2
  __m128 v16; // xmm0
  __m128 v17; // xmm3
  __m128 v18; // xmm1
  __m128 v19; // xmm2
  float v20; // xmm0_4
  Vector v21; // [esp+30h] [ebp-20h] BYREF
  float flDistance; // [esp+3Ch] [ebp-14h]
  float x; // [esp+40h] [ebp-10h]
  int v24; // [esp+44h] [ebp-Ch]
  int v25; // [esp+48h] [ebp-8h]
  int vars0; // [esp+50h] [ebp+0h]

  v24 = a2;
  v25 = vars0;
  v4 = vPoints[2].y - vPoints[1].y;
  v5 = vPoints[2].z - vPoints[1].z;
  v6 = vPoints->y - vPoints[1].y;
  v7 = vPoints->z - vPoints[1].z;
  v8 = vPoints->x - vPoints[1].x;
  v9 = vPoints[2].x - vPoints[1].x;
  v21.x = (float)(v5 * v6) - (float)(v4 * v7);
  v21.y = (float)(v7 * v9) - (float)(v5 * v8);
  v21.z = (float)(v4 * v8) - (float)(v6 * v9);
  VectorNormalize(vec: &v21);
  if ( fsqrt((float)((float)(v21.y * v21.y) + (float)(v21.z * v21.z)) + (float)(v21.x * v21.x)) >= 0.5 )
  {
    z = vPoints->z;
    y_low = (__m128)LODWORD(vPoints->y);
    x = vPoints->x;
    flDistance = z;
    v13 = y_low;
    v13.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * v21.y) + (float)(x * v21.x)) + (float)(z * v21.z);
    if ( SnapVector(vNormal: &v21) != 0 )
    {
      v14 = (__m128)LODWORD(vPoints[2].y);
      v14.m128_f32[0] = (float)((float)((float)((float)(v14.m128_f32[0] + (float)(y_low.m128_f32[0] + vPoints[1].y))
                                              * 0.33333334)
                                      * v21.y)
                              + (float)((float)((float)((float)(x + vPoints[1].x) + vPoints[2].x) * 0.33333334) * v21.x))
                      + (float)((float)((float)((float)(flDistance + vPoints[1].z) + vPoints[2].z) * 0.33333334) * v21.z);
      v13 = v14;
    }
    v15.m128_i32[0] = 1258291200;
    v16 = v13;
    v16.m128_f32[0] = v13.m128_f32[0] + 0.5;
    v17 = _mm_and_ps((__m128)0x80000000, v16);
    v15.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v16, v17), v15).m128_f32[0]) & 0x4B000000
                    | v17.m128_i32[0];
    v18 = v16;
    v18.m128_f32[0] = (float)((float)(v13.m128_f32[0] + 0.5) + v15.m128_f32[0]) - v15.m128_f32[0];
    v19 = v18;
    v19.m128_f32[0] = v18.m128_f32[0] - (float)(v13.m128_f32[0] + 0.5);
    v20 = v18.m128_f32[0] - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v19, v17).m128_f32[0]) & 0x3F800000);
    if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(v13.m128_f32[0] - v20) & _mask__AbsFloat_) < 0.0000099999997 )
      v13.m128_f32[0] = v20;
    return CPlaneHash::FindPlaneIndex(this, vNormal: &v21, flDistance: v13.m128_f32[0]);
  }
  else
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
      _LoggingSystem_Log(a1: LOG_VBSP2, a2: 3, a3: "Invalid normal vector for plane.\n");
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10070100
// Name: void ChopPolygon(class Polygon_t const __near &,class Vector const __near &,float,class Polygon_t __near *,class Polygon_t __near *,class Polygon_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ChopPolygon(
        const Polygon_t *polygon,
        const Vector *vNormal,
        float flDistance,
        Polygon_t *pOn,
        Polygon_t *pFront,
        Polygon_t *pBack)
{
  const Polygon_t *v6; // ebx
  int m_Size; // ecx
  float v8; // xmm5_4
  float v9; // edi
  float v10; // edx
  int v11; // eax
  float y; // xmm1_4
  float x; // xmm2_4
  float z; // xmm3_4
  Vector *m_pMemory; // edi
  float v16; // xmm0_4
  float v17; // xmm0_4
  int v18; // edi
  int v19; // eax
  const Vector *v20; // esi
  int v21; // eax
  int v22; // edx
  float v23; // xmm1_4
  const Vector *v24; // ecx
  int v25; // ebx
  int v26; // esi
  int v27; // edx
  int v28; // eax
  float flPlaneDistances[68]; // [esp+8h] [ebp-238h]
  int nSides[68]; // [esp+118h] [ebp-128h]
  Vector vMid; // [esp+228h] [ebp-18h] BYREF
  int v32; // [esp+234h] [ebp-Ch]
  CUtlVector<Vector,CUtlMemory<Vector,int> > *v33; // [esp+238h] [ebp-8h]
  CUtlVector<Vector,CUtlMemory<Vector,int> > *v34; // [esp+23Ch] [ebp-4h]
  Polygon_t *pOna; // [esp+254h] [ebp+14h]

  if ( pOn != nullptr )
    pOn->m_Points.m_Size = 0;
  v6 = polygon;
  pFront->m_Points.m_Size = 0;
  v33 = &pFront->m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >;
  pBack->m_Points.m_Size = 0;
  m_Size = polygon->m_Points.m_Size;
  v34 = &pBack->m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >;
  if ( m_Size >= 64 )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
      _LoggingSystem_Log(a1: LOG_VBSP2, a2: 3, a3: "Too many points in polygon.\n");
    return;
  }
  v8 = flDistance;
  v9 = 0.0;
  v10 = 0.0;
  v11 = 0;
  memset(&vMid, 0, sizeof(vMid));
  if ( m_Size > 0 )
  {
    y = vNormal->y;
    x = vNormal->x;
    z = vNormal->z;
    m_pMemory = polygon->m_Points.m_Memory.m_pMemory;
    do
    {
      v16 = (float)((float)((float)(m_pMemory->y * y) + (float)(x * m_pMemory->x)) + (float)(m_pMemory->z * z))
          - flDistance;
      flPlaneDistances[v11] = v16;
      if ( v16 <= 0.0099999998 )
      {
        if ( v16 >= -0.0099999998 )
          nSides[v11] = 2;
        else
          nSides[v11] = 1;
      }
      else
      {
        nSides[v11] = 0;
      }
      ++*((_DWORD *)&vMid.x + nSides[v11++]);
      ++m_pMemory;
    }
    while ( v11 < m_Size );
    v9 = vMid.y;
    v10 = vMid.x;
  }
  v17 = flPlaneDistances[0];
  nSides[v11] = nSides[0];
  flPlaneDistances[v11] = v17;
  if ( pOn != nullptr )
  {
    if ( v10 == 0.0 )
    {
      if ( v9 == 0.0 )
      {
        CUtlVector<Vector,CUtlMemory<Vector,int>>::operator=(
          this: &pOn->m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >,
          other: &polygon->m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >);
        return;
      }
      goto LABEL_20;
    }
  }
  else if ( v10 == 0.0 )
  {
LABEL_20:
    CUtlVector<Vector,CUtlMemory<Vector,int>>::operator=(
      this: v34,
      other: &polygon->m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >);
    return;
  }
  if ( v9 == 0.0 )
  {
    CUtlVector<Vector,CUtlMemory<Vector,int>>::operator=(
      this: v33,
      other: &polygon->m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >);
    return;
  }
  v18 = 0;
  if ( m_Size > 0 )
  {
    pOna = nullptr;
    do
    {
      v19 = nSides[v18];
      v20 = (const Vector *)((char *)pOna + (unsigned int)v6->m_Points.m_Memory.m_pMemory);
      if ( v19 == 2 )
      {
        CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
          this: v34,
          elem: v34->m_Size,
          src: (const Vector *)((char *)pOna + (unsigned int)v6->m_Points.m_Memory.m_pMemory));
        CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(this: v33, elem: v33->m_Size, src: v20);
        goto LABEL_42;
      }
      if ( v19 != 0 )
      {
        if ( v19 != 1 )
          goto LABEL_32;
        CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
          this: v34,
          elem: v34->m_Size,
          src: (const Vector *)((char *)pOna + (unsigned int)v6->m_Points.m_Memory.m_pMemory));
      }
      else
      {
        CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
          this: v33,
          elem: v33->m_Size,
          src: (const Vector *)((char *)pOna + (unsigned int)v6->m_Points.m_Memory.m_pMemory));
      }
      v8 = flDistance;
LABEL_32:
      v21 = nSides[v18 + 1];
      if ( v21 == 2 || v21 == nSides[v18] )
        goto LABEL_43;
      v22 = (v18 + 1) % v6->m_Points.m_Size;
      v23 = flPlaneDistances[v18] / (float)(flPlaneDistances[v18] - flPlaneDistances[v18 + 1]);
      v32 = 3;
      v24 = vNormal;
      v25 = (char *)&v6->m_Points.m_Memory.m_pMemory[v22] - (char *)vNormal;
      v26 = (char *)v20 - (char *)vNormal;
      v27 = (char *)&vMid - (char *)vNormal;
      do
      {
        if ( v24->x == 1.0 )
        {
          *(float *)((char *)&v24->x + v27) = v8;
        }
        else if ( v24->x == -1.0 )
        {
          *(_DWORD *)((char *)&v24->x + v27) = LODWORD(v8) ^ _mask__NegFloat_;
        }
        else
        {
          *(float *)((char *)&v24->x + v27) = (float)((float)(*(float *)((char *)&v24->x + v25)
                                                            - *(float *)((char *)&v24->x + v26))
                                                    * v23)
                                            + *(float *)((char *)&v24->x + v26);
        }
        v24 = (const Vector *)((char *)v24 + 4);
        --v32;
      }
      while ( v32 != 0 );
      CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(this: v34, elem: v34->m_Size, src: &vMid);
      CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(this: v33, elem: v33->m_Size, src: &vMid);
      v6 = polygon;
LABEL_42:
      v8 = flDistance;
LABEL_43:
      pOna = (Polygon_t *)((char *)pOna + 12);
      ++v18;
    }
    while ( v18 < v6->m_Points.m_Size );
  }
  v28 = v6->m_Points.m_Size + 4;
  if ( pBack->m_Points.m_Size > v28 || pFront->m_Points.m_Size > v28 )
    _Error(a1: "ChopPolygon: Num points exceeded estimate");
  if ( pBack->m_Points.m_Size > 64 || pFront->m_Points.m_Size > 64 )
    _Error(a1: "ChopPolygon: Exceeded MAX_POINTS_ON_POLYGON");
}

// ============================================================
// Overlay from vbsp2 (Missing functions)
// ============================================================
namespace vbsp2 {

//------------------------------------------------------------------------------
// Address: 0x004224A0
// Name: enum PlaneSide_t GetPlaneSide(class Vector const __near &,class Vector const __near &,struct Plane_t __near *)
// Source: json
//------------------------------------------------------------------------------
PlaneSide_t __cdecl GetPlaneSide(const Vector *vMin, const Vector *vMax, Plane_t *pPlane)
{
  int m_Type; // ecx
  PlaneSide_t result; // eax
  bool v5; // cc
  float x; // xmm7_4
  float v7; // xmm1_4
  float y; // xmm6_4
  float v9; // xmm1_4
  float z; // xmm5_4
  float v11; // xmm0_4
  float v12; // xmm2_4
  float v13; // xmm1_4
  float v14; // xmm7_4
  float v15; // xmm6_4
  float v16; // xmm0_4
  float vCorners_12; // [esp+10h] [ebp-Ch]
  float vCorners_16; // [esp+14h] [ebp-8h]

  m_Type = pPlane->m_Type;
  result = PLANE_SIDE_INVALID;
  if ( m_Type >= 3 )
  {
    if ( pPlane->m_vNormal.x >= 0.0 )
    {
      x = vMax->x;
      v7 = vMin->x;
    }
    else
    {
      x = vMin->x;
      v7 = vMax->x;
    }
    vCorners_12 = v7;
    if ( pPlane->m_vNormal.y >= 0.0 )
    {
      y = vMax->y;
      v9 = vMin->y;
    }
    else
    {
      y = vMin->y;
      v9 = vMax->y;
    }
    vCorners_16 = v9;
    if ( pPlane->m_vNormal.z >= 0.0 )
    {
      z = vMax->z;
      v11 = vMin->z;
    }
    else
    {
      z = vMin->z;
      v11 = vMax->z;
    }
    v12 = pPlane->m_vNormal.y;
    v13 = pPlane->m_vNormal.x * x;
    v14 = v12 * y;
    v15 = pPlane->m_vNormal.z;
    v16 = (float)((float)((float)(pPlane->m_vNormal.x * vCorners_12) + (float)(v12 * vCorners_16)) + (float)(v15 * v11))
        - pPlane->m_flDistance;
    if ( (float)((float)((float)(v13 + v14) + (float)(v15 * z)) - pPlane->m_flDistance) >= 0.1 )
      result = PLANE_SIDE_FRONT;
    v5 = v16 >= 0.1;
  }
  else
  {
    result = *(&vMax->x + m_Type) > (float)(pPlane->m_flDistance + 0.1);
    v5 = (float)(pPlane->m_flDistance - 0.1) <= *(&vMin->x + m_Type);
  }
  if ( !v5 )
    return result | 2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004225C0
// Name: bool SnapVector(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SnapVector(Vector *vNormal)
{
  int v1; // ecx

  v1 = 0;
  while ( 1 )
  {
    if ( fabs(*(&vNormal->x + v1) - 1.0) < 0.0000099999997 )
    {
      *(_QWORD *)&vNormal->y = 0;
      vNormal->x = 0.0;
      *((_DWORD *)&vNormal->x + v1) = 1065353216;
      return 1;
    }
    if ( fabs(*(&vNormal->x + v1) - -1.0) < 0.0000099999997 )
      break;
    if ( ++v1 >= 3 )
      return 0;
  }
  *(_QWORD *)&vNormal->y = 0;
  vNormal->x = 0.0;
  *((_DWORD *)&vNormal->x + v1) = -1082130432;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00422650
// Name: class Vector TriangleNormal(class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
Vector *__cdecl TriangleNormal(Vector *result, const Vector *v0, const Vector *v1, const Vector *v2)
{
  float y; // xmm5_4
  float z; // xmm6_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm4_4
  float v10; // xmm5_4
  float v11; // xmm3_4

  y = v0->y;
  z = v0->z;
  v6 = v2->x - v0->x;
  v7 = v1->x - v0->x;
  v8 = v1->y - y;
  v9 = v2->y - y;
  v10 = v2->z - z;
  v11 = v1->z - z;
  result->x = (float)(v9 * v11) - (float)(v10 * v8);
  result->y = (float)(v7 * v10) - (float)(v6 * v11);
  result->z = (float)(v6 * v8) - (float)(v7 * v9);
  VectorNormalize(vec: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004226F0
// Name: bool IsPolygonTiny(class Polygon_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsPolygonTiny(Polygon_t *pPolygon)
{
  int m_Size; // edi
  int v2; // eax
  float *i; // ecx
  int v4; // esi
  int v5; // eax
  float v6; // xmm0_4
  Vector *m_pMemory; // [esp-8h] [ebp-14h]
  int v9; // [esp-4h] [ebp-10h]

  m_Size = pPolygon->m_Points.m_Size;
  v2 = 0;
  v9 = 0;
  if ( m_Size <= 0 )
    return 1;
  m_pMemory = pPolygon->m_Points.m_Memory.m_pMemory;
  for ( i = &m_pMemory->z; ; i += 3 )
  {
    v4 = v2 + 1;
    v5 = (v2 + 1) % m_Size;
    v6 = m_pMemory[v5].x - *(i - 2);
    if ( fsqrt(
           (float)((float)((float)(m_pMemory[v5].y - *(i - 1)) * (float)(m_pMemory[v5].y - *(i - 1)))
                 + (float)((float)(m_pMemory[v5].z - *i) * (float)(m_pMemory[v5].z - *i)))
         + (float)(v6 * v6)) > 0.2
      && ++v9 >= 3 )
    {
      break;
    }
    v2 = v4;
    if ( v4 >= m_Size )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004227C0
// Name: float ComputePolygonArea(class Polygon_t const __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl ComputePolygonArea(const Polygon_t *polygon)
{
  int m_Size; // edx
  Vector *m_pMemory; // ecx
  float *p_z; // eax
  int v4; // edx
  float v5; // xmm1_4
  float v6; // xmm0_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm5_4
  float v10; // xmm6_4
  float v12; // [esp-4h] [ebp-10h]

  m_Size = polygon->m_Points.m_Size;
  v12 = 0.0;
  if ( m_Size > 2 )
  {
    m_pMemory = polygon->m_Points.m_Memory.m_pMemory;
    p_z = &m_pMemory[1].z;
    v4 = m_Size - 2;
    do
    {
      v5 = p_z[2] - m_pMemory->y;
      v6 = *p_z - m_pMemory->z;
      v7 = p_z[1] - m_pMemory->x;
      v8 = p_z[3] - m_pMemory->z;
      v9 = *(p_z - 2) - m_pMemory->x;
      v10 = *(p_z - 1) - m_pMemory->y;
      p_z += 3;
      --v4;
      v12 = fsqrt(
              (float)((float)((float)((float)(v6 * v7) - (float)(v8 * v9)) * (float)((float)(v6 * v7) - (float)(v8 * v9)))
                    + (float)((float)((float)(v5 * v9) - (float)(v7 * v10))
                            * (float)((float)(v5 * v9) - (float)(v7 * v10))))
            + (float)((float)((float)(v8 * v10) - (float)(v5 * v6)) * (float)((float)(v8 * v10) - (float)(v5 * v6))))
          + v12;
    }
    while ( v4 != 0 );
  }
  return v12 * 0.5;
}

//------------------------------------------------------------------------------
// Address: 0x004228B0
// Name: public: void CVertexHash::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVertexHash::Purge(CVertexHash *this)
{
  this->m_Vertices.m_Size = 0;
  if ( this->m_Vertices.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Vertices.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Vertices.m_Memory.m_pMemory);
      this->m_Vertices.m_Memory.m_pMemory = nullptr;
    }
    this->m_Vertices.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Vertices.m_pElements = this->m_Vertices.m_Memory.m_pMemory;
  this->m_VertexHashChain.m_Size = 0;
  if ( this->m_VertexHashChain.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_VertexHashChain.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_VertexHashChain.m_Memory.m_pMemory);
      this->m_VertexHashChain.m_Memory.m_pMemory = nullptr;
    }
    this->m_VertexHashChain.m_Memory.m_nAllocationCount = 0;
  }
  this->m_VertexHashChain.m_pElements = this->m_VertexHashChain.m_Memory.m_pMemory;
  _V_memset(dest: (unsigned __int8 *)this, fill: 0xFFu, count: 0x10000u);
}

//------------------------------------------------------------------------------
// Address: 0x00422950
// Name: void CreatePolygonFromPlane(class Vector const __near &,float,class Polygon_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CreatePolygonFromPlane(const Vector *vNormal, float flDistance, Polygon_t *pPolygon)
{
  float v3; // xmm1_4
  int v4; // edi
  float v5; // xmm0_4
  float v6; // xmm0_4
  float x; // xmm5_4
  float z; // xmm4_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm3_4
  float y; // xmm0_4
  float v13; // xmm4_4
  int m_Size; // edi
  int m_nAllocationCount; // ecx
  float v16; // xmm5_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm0_4
  Vector *m_pMemory; // ecx
  int v21; // eax
  Vector *v22; // eax
  float v23; // xmm4_4
  float v24; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm5_4
  float v27; // xmm3_4
  float v28; // xmm2_4
  float org_4; // [esp+4h] [ebp-20h]
  float org_8; // [esp+8h] [ebp-1Ch]
  float vright; // [esp+Ch] [ebp-18h]
  Vector vup; // [esp+18h] [ebp-Ch] BYREF

  v3 = -1.0;
  v4 = -1;
  v5 = fabs(vNormal->x);
  if ( v5 > -1.0 )
  {
    v4 = 0;
    v3 = v5;
  }
  v6 = fabs(vNormal->y);
  if ( v6 > v3 )
  {
    v4 = 1;
    v3 = v6;
  }
  if ( fabs(vNormal->z) <= v3 )
  {
    if ( v4 == -1 )
      _Error(a1: "BasePolygonForPlane: no axis found");
  }
  else
  {
    v4 = 2;
  }
  x = vec3_origin.x;
  z = vec3_origin.z;
  if ( v4 >= 0 )
  {
    if ( v4 <= 1 )
      z = 1.0;
    else
      x = 1.0;
  }
  LODWORD(v9) = COERCE_UNSIGNED_INT((float)((float)(vNormal->y * vec3_origin.y) + (float)(vNormal->x * x)) + (float)(vNormal->z * z))
              ^ _mask__NegFloat_;
  v10 = (float)(vNormal->y * v9) + vec3_origin.y;
  v11 = (float)(vNormal->z * v9) + z;
  vup.x = (float)(vNormal->x * v9) + x;
  vup.y = v10;
  vup.z = v11;
  VectorNormalize(vec: &vup);
  y = vNormal->y;
  v13 = vNormal->z;
  m_Size = pPolygon->m_Points.m_Size;
  m_nAllocationCount = pPolygon->m_Points.m_Memory.m_nAllocationCount;
  org_4 = y * flDistance;
  v16 = vNormal->x * flDistance;
  org_8 = v13 * flDistance;
  v17 = (float)(v13 * vup.y) - (float)(y * vup.z);
  v18 = (float)((float)(vNormal->x * vup.z) - (float)(v13 * vup.x)) * 65536.0;
  v19 = (float)((float)(y * vup.x) - (float)(vNormal->x * vup.y)) * 65536.0;
  vup.x = vup.x * 65536.0;
  vup.y = vup.y * 65536.0;
  vup.z = vup.z * 65536.0;
  vright = v17 * 65536.0;
  if ( m_Size + 4 > m_nAllocationCount )
    CUtlMemory<Vector,int>::Grow(
      this: (CUtlMemory<MapEntityKeyValuePair_t,int> *)&pPolygon->m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >,
      num: m_Size - m_nAllocationCount + 4);
  pPolygon->m_Points.m_Size += 4;
  m_pMemory = pPolygon->m_Points.m_Memory.m_pMemory;
  v21 = pPolygon->m_Points.m_Size - m_Size - 4;
  pPolygon->m_Points.m_pElements = m_pMemory;
  if ( v21 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 4], src: &m_pMemory[m_Size], count: 12 * v21);
  v22 = pPolygon->m_Points.m_Memory.m_pMemory;
  v23 = org_8 - v19;
  v22->z = org_8 - v19;
  v24 = v19 + org_8;
  v25 = v16 - vright;
  v22->x = v16 - vright;
  v26 = v16 + vright;
  v27 = org_4 - v18;
  v22->y = org_4 - v18;
  v28 = v18 + org_4;
  v22->x = v25 + vup.x;
  v22->y = v22->y + vup.y;
  v22->z = v22->z + vup.z;
  v22[1].z = v24;
  v22[1].x = v26;
  v22[1].y = v28;
  v22[1].x = v26 + vup.x;
  v22[1].y = v22[1].y + vup.y;
  v22[1].z = v22[1].z + vup.z;
  v22[2].z = v24;
  v22[2].x = v26;
  v22[2].y = v28;
  v22[2].x = v26 - vup.x;
  v22[2].y = v22[2].y - vup.y;
  v22[2].z = v22[2].z - vup.z;
  v22[3].x = v25;
  v22[3].y = v27;
  v22[3].z = v23;
  v22[3].x = v25 - vup.x;
  v22[3].y = v22[3].y - vup.y;
  v22[3].z = v22[3].z - vup.z;
}

//------------------------------------------------------------------------------
// Address: 0x00422CA0
// Name: void ChopPolygonInPlace(class Polygon_t __near *,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ChopPolygonInPlace(Polygon_t *pPolygon, const Vector *vNormal, float flDistance)
{
  Polygon_t *v3; // ebx
  int m_Size; // ecx
  int v5; // esi
  int v6; // eax
  float y; // xmm1_4
  float x; // xmm2_4
  float z; // xmm3_4
  Vector *m_pMemory; // edi
  float v11; // xmm0_4
  float v12; // xmm0_4
  int v13; // edx
  float *p_z; // edi
  Vector *v15; // ebx
  int v16; // edx
  double v17; // st7
  int v18; // eax
  float v19; // xmm1_4
  Vector *v20; // eax
  const Vector *v21; // ecx
  int v22; // edx
  int v23; // ecx
  Vector vNewPolygonPoints[68]; // [esp+4h] [ebp-574h] BYREF
  float flPlaneDistances[68]; // [esp+334h] [ebp-244h]
  int nSides[68]; // [esp+444h] [ebp-134h]
  Vector *v27; // [esp+554h] [ebp-24h]
  int v28; // [esp+558h] [ebp-20h]
  int v29; // [esp+55Ch] [ebp-1Ch]
  int v30; // [esp+560h] [ebp-18h]
  int v31; // [esp+564h] [ebp-14h]
  Vector vMid; // [esp+568h] [ebp-10h] BYREF
  int nNewPolygonPoints; // [esp+574h] [ebp-4h]

  v3 = pPolygon;
  m_Size = pPolygon->m_Points.m_Size;
  v28 = m_Size;
  if ( m_Size >= 64 )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
      _LoggingSystem_Log(a1: LOG_VBSP2, a2: 3, a3: "Too many points in polygon.\n");
    return;
  }
  v5 = 0;
  v6 = 0;
  memset(&vMid, 0, sizeof(vMid));
  if ( m_Size > 0 )
  {
    y = vNormal->y;
    x = vNormal->x;
    z = vNormal->z;
    m_pMemory = pPolygon->m_Points.m_Memory.m_pMemory;
    do
    {
      v11 = (float)((float)((float)(m_pMemory->y * y) + (float)(x * m_pMemory->x)) + (float)(m_pMemory->z * z))
          - flDistance;
      flPlaneDistances[v6] = v11;
      if ( v11 <= 0.0099999998 )
      {
        if ( v11 >= -0.0099999998 )
          nSides[v6] = 2;
        else
          nSides[v6] = 1;
      }
      else
      {
        nSides[v6] = 0;
      }
      ++*((_DWORD *)&vMid.x + nSides[v6++]);
      ++m_pMemory;
    }
    while ( v6 < m_Size );
  }
  v12 = flPlaneDistances[0];
  nSides[v6] = nSides[0];
  flPlaneDistances[v6] = v12;
  if ( LODWORD(vMid.x) == 0 )
  {
    pPolygon->m_Points.m_Size = 0;
    return;
  }
  if ( LODWORD(vMid.y) != 0 )
  {
    v13 = 0;
    nNewPolygonPoints = 0;
    if ( m_Size <= 0 )
      goto LABEL_34;
    v27 = pPolygon->m_Points.m_Memory.m_pMemory;
    p_z = &v27->z;
    v15 = vNewPolygonPoints;
    v29 = -8 - (_DWORD)vNormal;
    while ( 1 )
    {
      v16 = nSides[v5];
      if ( v16 == 2 )
      {
        v15->x = *(p_z - 2);
        v15->y = *(p_z - 1);
        v15->z = *p_z;
      }
      else
      {
        if ( v16 == 0 )
        {
          v17 = *(p_z - 2);
          ++nNewPolygonPoints;
          v15->x = v17;
          ++v15;
          v15[-1].y = *(p_z - 1);
          v15[-1].z = *p_z;
        }
        v18 = nSides[v5 + 1];
        if ( v18 == 2 || v18 == v16 )
          goto LABEL_32;
        v19 = flPlaneDistances[v5] / (float)(flPlaneDistances[v5] - flPlaneDistances[v5 + 1]);
        v31 = 3;
        v20 = &v27[(v5 + 1) % m_Size];
        v21 = vNormal;
        v30 = (char *)v20 - (char *)vNormal;
        v22 = (char *)&vMid - (char *)vNormal;
        do
        {
          if ( v21->x == 1.0 )
          {
            *(float *)((char *)&v21->x + v22) = flDistance;
          }
          else if ( v21->x == -1.0 )
          {
            *(float *)((char *)&v21->x + v22) = -flDistance;
          }
          else
          {
            *(float *)((char *)&v21->x + v22) = (float)((float)(*(float *)((char *)&v21->x + v30)
                                                              - *(float *)((char *)p_z + v29 + (_DWORD)v21))
                                                      * v19)
                                              + *(float *)((char *)p_z + v29 + (_DWORD)v21);
          }
          v21 = (const Vector *)((char *)v21 + 4);
          --v31;
        }
        while ( v31 != 0 );
        m_Size = v28;
        *v15 = vMid;
      }
      ++nNewPolygonPoints;
      ++v15;
LABEL_32:
      ++v5;
      p_z += 3;
      if ( v5 >= m_Size )
      {
        v3 = pPolygon;
        v13 = nNewPolygonPoints;
LABEL_34:
        if ( v13 > m_Size + 4 )
        {
          _Error(a1: "ChopPolygonInPlace: Num points exceeded estimate");
          v3 = pPolygon;
          v13 = nNewPolygonPoints;
        }
        if ( v13 > 64 )
        {
          _Error(a1: "ChopPolygonInPlace: Exceeded MAX_POINTS_ON_POLYGON");
          v3 = pPolygon;
          v13 = nNewPolygonPoints;
        }
        v23 = v3->m_Points.m_Size;
        if ( v13 - v23 <= 0 )
        {
          if ( v13 - v23 < 0 )
            v3->m_Points.m_Size = v13;
        }
        else
        {
          CUtlVector<dbrush_t,CUtlMemory<dbrush_t,int>>::InsertMultipleBefore(
            this: &v3->m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >,
            elem: v23,
            num: v13 - v23);
          v13 = nNewPolygonPoints;
        }
        memcpy(
          dst: (unsigned __int8 *)v3->m_Points.m_Memory.m_pMemory,
          src: (unsigned __int8 *)vNewPolygonPoints,
          count: 12 * v13);
        return;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00422FC0
// Name: public: CPlaneHash::CPlaneHash(void)
// Source: json
//------------------------------------------------------------------------------
CPlaneHash *__thiscall CPlaneHash::CPlaneHash(CPlaneHash *this)
{
  this->m_Planes.m_Memory.m_pMemory = nullptr;
  this->m_Planes.m_Memory.m_nAllocationCount = 0;
  this->m_Planes.m_Memory.m_nGrowSize = 0;
  this->m_Planes.m_Size = 0;
  this->m_Planes.m_pElements = nullptr;
  this->m_Planes.__vftable = (CCopyableUtlVector<HashedPlane_t>_vtbl *)&CCopyableUtlVector<HashedPlane_t>::`vftable';
  memset(dst: (unsigned __int8 *)this->m_HashTable, value: 0xFFu, count: sizeof(this->m_HashTable));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00423000
// Name: private: struct HashedPlane_t __near * CPlaneHash::AllocateNewPlane(void)
// Source: json
//------------------------------------------------------------------------------
HashedPlane_t *__thiscall CPlaneHash::AllocateNewPlane(CPlaneHash *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  HashedPlane_t *m_pMemory; // ecx
  int v5; // eax
  HashedPlane_t *v6; // eax

  m_nAllocationCount = this->m_Planes.m_Memory.m_nAllocationCount;
  m_Size = this->m_Planes.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<HashedPlane_t,int>::Grow(
      this: (CUtlMemory<CDispBox,int> *)&this->m_Planes.CUtlVector<HashedPlane_t,CUtlMemory<HashedPlane_t,int> >,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Planes.m_Size;
  m_pMemory = this->m_Planes.m_Memory.m_pMemory;
  v5 = this->m_Planes.m_Size - m_Size - 1;
  this->m_Planes.m_pElements = m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 24 * v5);
  v6 = &this->m_Planes.m_Memory.m_pMemory[this->m_Planes.m_Size - 1];
  *(_QWORD *)&v6->m_vNormal.x = 0;
  *(_QWORD *)&v6->m_vNormal.z = 0;
  *(_QWORD *)&v6->m_Type = 0;
  v6->m_nNextPlaneIndex = -1;
  return &this->m_Planes.m_Memory.m_pMemory[this->m_Planes.m_Size - 1];
}

//------------------------------------------------------------------------------
// Address: 0x00423090
// Name: public: CVertexHash::CVertexHash(void)
// Source: json
//------------------------------------------------------------------------------
CVertexHash *__thiscall CVertexHash::CVertexHash(CVertexHash *this)
{
  this->m_VertexHashChain.m_Memory.m_pMemory = nullptr;
  this->m_VertexHashChain.m_Memory.m_nAllocationCount = 0;
  this->m_VertexHashChain.m_Memory.m_nGrowSize = 0;
  this->m_VertexHashChain.m_Size = 0;
  this->m_VertexHashChain.m_pElements = nullptr;
  this->m_Vertices.m_Memory.m_pMemory = nullptr;
  this->m_Vertices.m_Memory.m_nAllocationCount = 0;
  this->m_Vertices.m_Memory.m_nGrowSize = 0;
  this->m_Vertices.m_Size = 0;
  this->m_Vertices.m_pElements = nullptr;
  _V_memset(dest: (unsigned __int8 *)this, fill: 0xFFu, count: 0x10000u);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004230F0
// Name: public: int CVertexHash::FindVertexIndex(class Vector const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVertexHash::FindVertexIndex(CVertexHash *this, const Vector *vertex, bool bAlwaysAdd)
{
  const Vector *v3; // esi
  int v4; // ebx
  int v5; // edi
  int v6; // eax
  unsigned int v7; // eax
  int result; // eax
  float *v9; // ecx
  CUtlMemory<MapEntityKeyValuePair_t,int> *v10; // esi
  MapEntityKeyValuePair_t *m_pMemory; // edi
  int m_nAllocationCount; // eax
  int v13; // ebx
  MapEntityKeyValuePair_t *v14; // ecx
  int v15; // eax
  Vector *v16; // eax
  int v17; // edi
  int m_nGrowSize; // eax
  int v19; // ecx
  int v20; // eax
  _DWORD *v21; // eax
  int nBucket[3]; // [esp+0h] [ebp-1Ch] BYREF
  Vector roundedVertex; // [esp+Ch] [ebp-10h] BYREF
  CUtlMemory<MapEntityKeyValuePair_t,int> *v24; // [esp+18h] [ebp-4h]
  int nBucketIndex; // [esp+24h] [ebp+8h]
  int nBucketIndexa; // [esp+24h] [ebp+8h]

  v3 = vertex;
  v4 = (char *)&roundedVertex - (char *)vertex;
  v24 = (CUtlMemory<MapEntityKeyValuePair_t,int> *)this;
  v5 = (char *)nBucket - (char *)vertex;
  for ( nBucketIndex = 3; nBucketIndex != 0; --nBucketIndex )
  {
    v6 = (int)(float)(v3->x + 0.5);
    if ( fabs(v3->x - (float)v6) >= 0.0099999998 )
      *(float *)((char *)&v3->x + v4) = v3->x;
    else
      *(float *)((char *)&v3->x + v4) = (float)v6;
    v7 = (v6 + 0x4000) >> 8;
    *(_DWORD *)((char *)&v3->x + v5) = v7;
    if ( v7 >= 0x80 && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
      _LoggingSystem_Log(a1: LOG_VBSP2, a2: 3, a3: "CVertexHash::FindVertexIndex: point outside valid range.\n");
    v3 = (const Vector *)((char *)v3 + 4);
  }
  nBucketIndexa = nBucket[0] + (nBucket[1] << 7);
  if ( bAlwaysAdd || (result = *((_DWORD *)&v24->m_pMemory + 128 * nBucket[1] + nBucket[0])) == -1 )
  {
LABEL_15:
    v10 = v24;
    m_pMemory = v24[5464].m_pMemory;
    m_nAllocationCount = v24[5463].m_nAllocationCount;
    v13 = v24[5462].m_nAllocationCount;
    if ( (int)&m_pMemory->m_pKey + 1 > m_nAllocationCount )
      CUtlMemory<Vector,int>::Grow(this: v24 + 5463, num: (int)&m_pMemory->m_pKey - m_nAllocationCount + 1);
    ++v10[5464].m_pMemory;
    v14 = v10[5463].m_pMemory;
    v15 = (char *)v10[5464].m_pMemory - (char *)m_pMemory - 1;
    v10[5464].m_nAllocationCount = (int)v14;
    if ( v15 > 0 )
      _V_memmove(dest: &v14[(int)m_pMemory + 1], src: &v14[(_DWORD)m_pMemory], count: 12 * v15);
    v16 = (Vector *)&v10[5463].m_pMemory[(_DWORD)m_pMemory];
    if ( v16 != nullptr )
      *v16 = roundedVertex;
    v17 = v10[5462].m_nAllocationCount;
    m_nGrowSize = v10[5461].m_nGrowSize;
    if ( v17 + 1 > m_nGrowSize )
      CUtlMemory<ColorRGBExp32,int>::Grow(
        this: (CUtlMemory<BSPCluster_t,int> *)&v10[5461].m_nAllocationCount,
        num: v17 - m_nGrowSize + 1);
    ++v10[5462].m_nAllocationCount;
    v19 = v10[5461].m_nAllocationCount;
    v20 = v10[5462].m_nAllocationCount - v17 - 1;
    v10[5462].m_nGrowSize = v19;
    if ( v20 > 0 )
      _V_memmove(dest: (void *)(v19 + 4 * v17 + 4), src: (const void *)(v19 + 4 * v17), count: 4 * v20);
    v21 = (_DWORD *)(v10[5461].m_nAllocationCount + 4 * v17);
    if ( v21 != nullptr )
      *v21 = *((_DWORD *)&v10->m_pMemory + nBucketIndexa);
    *((_DWORD *)&v10->m_pMemory + nBucketIndexa) = v13;
    return v13;
  }
  else
  {
    while ( 1 )
    {
      v9 = (float *)&v24[5463].m_pMemory[result];
      if ( fabs(*v9 - roundedVertex.x) < 0.1
        && fabs(v9[1] - roundedVertex.y) < 0.1
        && fabs(v9[2] - roundedVertex.z) < 0.1 )
      {
        break;
      }
      result = *(_DWORD *)(v24[5461].m_nAllocationCount + 4 * result);
      if ( result == -1 )
        goto LABEL_15;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00423350
// Name: public: int CPlaneHash::FindPlaneIndex(class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPlaneHash::FindPlaneIndex(CPlaneHash *this, const Vector *vNormal, float flDistance)
{
  float v4; // xmm5_4
  __m128 v5; // xmm2
  __m128 v6; // xmm0
  __m128 v7; // xmm4
  __m128 v8; // xmm1
  __m128 v9; // xmm2
  float v10; // xmm0_4
  int v11; // ebx
  float y; // xmm6_4
  float z; // xmm4_4
  int v14; // esi
  int result; // eax
  HashedPlane_t *v16; // ecx
  HashedPlane_t *NewPlane; // esi
  HashedPlane_t *v18; // eax
  HashedPlane_t *v19; // ecx
  float v20; // xmm0_4
  float v21; // xmm2_4
  float v22; // xmm1_4
  int v23; // eax
  int v24; // edx
  __int64 v25; // xmm0_8
  float v26; // eax
  double m_flDistance; // st7
  Vector vTemp; // 0:^C.12

  v4 = flDistance;
  v5.m128_i32[0] = 1258291200;
  v6 = (__m128)LODWORD(flDistance);
  v6.m128_f32[0] = flDistance + 0.5;
  v7 = _mm_and_ps((__m128)0x80000000, v6);
  v5.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v6, v7), v5).m128_f32[0]) & 0x4B000000 | v7.m128_i32[0];
  v8 = v6;
  v8.m128_f32[0] = (float)((float)(flDistance + 0.5) + v5.m128_f32[0]) - v5.m128_f32[0];
  v9 = v8;
  v9.m128_f32[0] = v8.m128_f32[0] - (float)(flDistance + 0.5);
  v10 = v8.m128_f32[0] - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v9, v7).m128_f32[0]) & 0x3F800000);
  v11 = ((int)fabs(flDistance) / 8) & 0x3FF;
  if ( fabs(flDistance - v10) < 0.0099999998 )
  {
    v4 = v10;
    flDistance = v10;
  }
  vTemp = *vNormal;
  if ( fabs(vNormal->x) < 0.0000099999997 )
    vTemp.x = 0.0;
  y = vTemp.y;
  if ( fabs(vTemp.y) < 0.0000099999997 )
  {
    y = 0.0;
    vTemp.y = 0.0;
  }
  z = vNormal->z;
  if ( fabs(vTemp.z) < 0.0000099999997 )
  {
    z = 0.0;
    vTemp.z = 0.0;
  }
  v14 = -1;
  while ( 1 )
  {
    result = this->m_HashTable[((_WORD)v14 + (_WORD)v11) & 0x3FF];
    if ( result != -1 )
      break;
LABEL_16:
    if ( ++v14 > 1 )
    {
      NewPlane = CPlaneHash::AllocateNewPlane(this);
      v18 = CPlaneHash::AllocateNewPlane(this);
      NewPlane->m_vNormal = vTemp;
      v19 = v18;
      v18->m_vNormal.x = -vTemp.x;
      v18->m_vNormal.y = -vTemp.y;
      v18->m_vNormal.z = -vTemp.z;
      NewPlane->m_flDistance = flDistance;
      v18->m_flDistance = -flDistance;
      if ( vTemp.x == 1.0 || vTemp.x == -1.0 )
      {
        v23 = 0;
      }
      else if ( vTemp.y == 1.0 || vTemp.y == -1.0 )
      {
        v23 = 1;
      }
      else if ( vTemp.z == 1.0 || vTemp.z == -1.0 )
      {
        v23 = 2;
      }
      else
      {
        v20 = fabs(vTemp.x);
        v21 = fabs(vTemp.y);
        v22 = fabs(vTemp.z);
        if ( v20 < v21 || v20 < v22 )
        {
          if ( v21 < v20 || v21 < v22 )
            v23 = 5;
          else
            v23 = 4;
        }
        else
        {
          v23 = 3;
        }
      }
      v19->m_Type = v23;
      NewPlane->m_Type = v23;
      result = this->m_Planes.m_Size - 2;
      v24 = result + 1;
      NewPlane->m_nNextPlaneIndex = result + 1;
      v19->m_nNextPlaneIndex = this->m_HashTable[v11];
      this->m_HashTable[v11] = result;
      if ( NewPlane->m_Type < 3
        && (NewPlane->m_vNormal.x < 0.0 || NewPlane->m_vNormal.y < 0.0 || NewPlane->m_vNormal.z < 0.0) )
      {
        v25 = *(_QWORD *)&NewPlane->m_vNormal.x;
        v26 = NewPlane->m_vNormal.z;
        NewPlane->m_vNormal.x = v19->m_vNormal.x;
        NewPlane->m_vNormal.y = v19->m_vNormal.y;
        NewPlane->m_vNormal.z = v19->m_vNormal.z;
        LODWORD(v19->m_vNormal.x) = v25;
        m_flDistance = v19->m_flDistance;
        v19->m_vNormal.y = *((float *)&v25 + 1);
        v19->m_vNormal.z = v26;
        *(float *)&v25 = NewPlane->m_flDistance;
        NewPlane->m_flDistance = m_flDistance;
        LODWORD(v19->m_flDistance) = v25;
        return v24;
      }
      return result;
    }
  }
  while ( 1 )
  {
    v16 = &this->m_Planes.m_Memory.m_pMemory[result];
    if ( fabs(v16->m_vNormal.x - vTemp.x) < 0.0000099999997
      && fabs(v16->m_vNormal.y - y) < 0.0000099999997
      && fabs(v16->m_vNormal.z - z) < 0.0000099999997
      && fabs(v16->m_flDistance - v4) < 0.0099999998 )
    {
      return result;
    }
    result = v16->m_nNextPlaneIndex;
    if ( result == -1 )
      goto LABEL_16;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00423670
// Name: public: int CPlaneHash::FindPlaneIndex(class Vector __near * const)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CPlaneHash::FindPlaneIndex@<eax>(CPlaneHash *this@<ecx>, float a2@<ebp>, Vector *vPoints)
{
  float v4; // xmm1_4
  float v5; // xmm3_4
  float v6; // xmm2_4
  float v7; // xmm0_4
  float v8; // xmm4_4
  float v9; // xmm5_4
  float z; // xmm4_4
  __m128 y_low; // xmm7
  __m128 flDistance; // xmm6
  __m128 v14; // xmm0
  __m128 v15; // xmm2
  __m128 v16; // xmm0
  __m128 v17; // xmm3
  __m128 v18; // xmm1
  __m128 v19; // xmm2
  float v20; // xmm0_4
  Vector v21; // [esp+30h] [ebp-20h] BYREF
  Vector vNormal; // [esp+3Ch] [ebp-14h]
  void *v23; // [esp+48h] [ebp-8h]
  void *retaddr; // [esp+50h] [ebp+0h]

  vNormal.z = a2;
  v23 = retaddr;
  v4 = vPoints[2].y - vPoints[1].y;
  v5 = vPoints[2].z - vPoints[1].z;
  v6 = vPoints->y - vPoints[1].y;
  v7 = vPoints->z - vPoints[1].z;
  v8 = vPoints->x - vPoints[1].x;
  v9 = vPoints[2].x - vPoints[1].x;
  v21.x = (float)(v5 * v6) - (float)(v4 * v7);
  v21.y = (float)(v7 * v9) - (float)(v5 * v8);
  v21.z = (float)(v4 * v8) - (float)(v6 * v9);
  VectorNormalize(vec: &v21);
  if ( fsqrt((float)((float)(v21.y * v21.y) + (float)(v21.z * v21.z)) + (float)(v21.x * v21.x)) >= 0.5 )
  {
    z = vPoints->z;
    y_low = (__m128)LODWORD(vPoints->y);
    vNormal.y = vPoints->x;
    vNormal.x = z;
    flDistance = y_low;
    flDistance.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * v21.y) + (float)(vNormal.y * v21.x))
                           + (float)(z * v21.z);
    if ( SnapVector(vNormal: &v21) != 0 )
    {
      v14 = (__m128)LODWORD(vPoints[2].y);
      v14.m128_f32[0] = (float)((float)((float)((float)(v14.m128_f32[0] + (float)(y_low.m128_f32[0] + vPoints[1].y))
                                              * 0.33333334)
                                      * v21.y)
                              + (float)((float)((float)((float)(vNormal.y + vPoints[1].x) + vPoints[2].x) * 0.33333334)
                                      * v21.x))
                      + (float)((float)((float)((float)(vNormal.x + vPoints[1].z) + vPoints[2].z) * 0.33333334) * v21.z);
      flDistance = v14;
    }
    v15.m128_i32[0] = 1258291200;
    v16 = flDistance;
    v16.m128_f32[0] = flDistance.m128_f32[0] + 0.5;
    v17 = _mm_and_ps((__m128)0x80000000, v16);
    v15.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v16, v17), v15).m128_f32[0]) & 0x4B000000
                    | v17.m128_i32[0];
    v18 = v16;
    v18.m128_f32[0] = (float)((float)(flDistance.m128_f32[0] + 0.5) + v15.m128_f32[0]) - v15.m128_f32[0];
    v19 = v18;
    v19.m128_f32[0] = v18.m128_f32[0] - (float)(flDistance.m128_f32[0] + 0.5);
    v20 = v18.m128_f32[0] - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v19, v17).m128_f32[0]) & 0x3F800000);
    if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(flDistance.m128_f32[0] - v20) & _mask__AbsFloat_) < 0.0000099999997 )
      flDistance.m128_f32[0] = v20;
    return CPlaneHash::FindPlaneIndex(this, vNormal: &v21, flDistance: flDistance.m128_f32[0]);
  }
  else
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
      _LoggingSystem_Log(a1: LOG_VBSP2, a2: 3, a3: "Invalid normal vector for plane.\n");
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004238D0
// Name: void ChopPolygon(class Polygon_t const __near &,class Vector const __near &,float,class Polygon_t __near *,class Polygon_t __near *,class Polygon_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ChopPolygon(
        const Polygon_t *polygon,
        const Vector *vNormal,
        float flDistance,
        Polygon_t *pOn,
        Polygon_t *pFront,
        Polygon_t *pBack)
{
  const Polygon_t *v6; // ebx
  int m_Size; // ecx
  float v8; // xmm5_4
  float v9; // edi
  float v10; // edx
  int v11; // eax
  float y; // xmm1_4
  float x; // xmm2_4
  float z; // xmm3_4
  Vector *m_pMemory; // edi
  float v16; // xmm0_4
  float v17; // xmm0_4
  int v18; // edi
  int v19; // eax
  const Vector *v20; // esi
  int v21; // eax
  int v22; // edx
  float v23; // xmm1_4
  const Vector *v24; // ecx
  int v25; // ebx
  int v26; // esi
  int v27; // edx
  int v28; // eax
  float flPlaneDistances[68]; // [esp+8h] [ebp-238h]
  int nSides[68]; // [esp+118h] [ebp-128h]
  Vector vMid; // [esp+228h] [ebp-18h] BYREF
  int v32; // [esp+234h] [ebp-Ch]
  CUtlVector<Vector,CUtlMemory<Vector,int> > *v33; // [esp+238h] [ebp-8h]
  CUtlVector<Vector,CUtlMemory<Vector,int> > *v34; // [esp+23Ch] [ebp-4h]
  Polygon_t *pOna; // [esp+254h] [ebp+14h]

  if ( pOn != nullptr )
    pOn->m_Points.m_Size = 0;
  v6 = polygon;
  pFront->m_Points.m_Size = 0;
  v33 = &pFront->m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >;
  pBack->m_Points.m_Size = 0;
  m_Size = polygon->m_Points.m_Size;
  v34 = &pBack->m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >;
  if ( m_Size >= 64 )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
      _LoggingSystem_Log(a1: LOG_VBSP2, a2: 3, a3: "Too many points in polygon.\n");
    return;
  }
  v8 = flDistance;
  v9 = 0.0;
  v10 = 0.0;
  v11 = 0;
  memset(&vMid, 0, sizeof(vMid));
  if ( m_Size > 0 )
  {
    y = vNormal->y;
    x = vNormal->x;
    z = vNormal->z;
    m_pMemory = polygon->m_Points.m_Memory.m_pMemory;
    do
    {
      v16 = (float)((float)((float)(m_pMemory->y * y) + (float)(x * m_pMemory->x)) + (float)(m_pMemory->z * z))
          - flDistance;
      flPlaneDistances[v11] = v16;
      if ( v16 <= 0.0099999998 )
      {
        if ( v16 >= -0.0099999998 )
          nSides[v11] = 2;
        else
          nSides[v11] = 1;
      }
      else
      {
        nSides[v11] = 0;
      }
      ++*((_DWORD *)&vMid.x + nSides[v11++]);
      ++m_pMemory;
    }
    while ( v11 < m_Size );
    v9 = vMid.y;
    v10 = vMid.x;
  }
  v17 = flPlaneDistances[0];
  nSides[v11] = nSides[0];
  flPlaneDistances[v11] = v17;
  if ( pOn != nullptr )
  {
    if ( v10 == 0.0 )
    {
      if ( v9 == 0.0 )
      {
        CUtlVector<Vector,CUtlMemory<Vector,int>>::operator=(
          this: &pOn->m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >,
          other: &polygon->m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >);
        return;
      }
      goto LABEL_20;
    }
  }
  else if ( v10 == 0.0 )
  {
LABEL_20:
    CUtlVector<Vector,CUtlMemory<Vector,int>>::operator=(
      this: v34,
      other: &polygon->m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >);
    return;
  }
  if ( v9 == 0.0 )
  {
    CUtlVector<Vector,CUtlMemory<Vector,int>>::operator=(
      this: v33,
      other: &polygon->m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >);
    return;
  }
  v18 = 0;
  if ( m_Size > 0 )
  {
    pOna = nullptr;
    do
    {
      v19 = nSides[v18];
      v20 = (const Vector *)((char *)pOna + (unsigned int)v6->m_Points.m_Memory.m_pMemory);
      if ( v19 == 2 )
      {
        CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
          this: v34,
          elem: v34->m_Size,
          src: (const Vector *)((char *)pOna + (unsigned int)v6->m_Points.m_Memory.m_pMemory));
        CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(this: v33, elem: v33->m_Size, src: v20);
        goto LABEL_42;
      }
      if ( v19 != 0 )
      {
        if ( v19 != 1 )
          goto LABEL_32;
        CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
          this: v34,
          elem: v34->m_Size,
          src: (const Vector *)((char *)pOna + (unsigned int)v6->m_Points.m_Memory.m_pMemory));
      }
      else
      {
        CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
          this: v33,
          elem: v33->m_Size,
          src: (const Vector *)((char *)pOna + (unsigned int)v6->m_Points.m_Memory.m_pMemory));
      }
      v8 = flDistance;
LABEL_32:
      v21 = nSides[v18 + 1];
      if ( v21 == 2 || v21 == nSides[v18] )
        goto LABEL_43;
      v22 = (v18 + 1) % v6->m_Points.m_Size;
      v23 = flPlaneDistances[v18] / (float)(flPlaneDistances[v18] - flPlaneDistances[v18 + 1]);
      v32 = 3;
      v24 = vNormal;
      v25 = (char *)&v6->m_Points.m_Memory.m_pMemory[v22] - (char *)vNormal;
      v26 = (char *)v20 - (char *)vNormal;
      v27 = (char *)&vMid - (char *)vNormal;
      do
      {
        if ( v24->x == 1.0 )
        {
          *(float *)((char *)&v24->x + v27) = v8;
        }
        else if ( v24->x == -1.0 )
        {
          *(_DWORD *)((char *)&v24->x + v27) = LODWORD(v8) ^ _mask__NegFloat_;
        }
        else
        {
          *(float *)((char *)&v24->x + v27) = (float)((float)(*(float *)((char *)&v24->x + v25)
                                                            - *(float *)((char *)&v24->x + v26))
                                                    * v23)
                                            + *(float *)((char *)&v24->x + v26);
        }
        v24 = (const Vector *)((char *)v24 + 4);
        --v32;
      }
      while ( v32 != 0 );
      CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(this: v34, elem: v34->m_Size, src: &vMid);
      CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(this: v33, elem: v33->m_Size, src: &vMid);
      v6 = polygon;
LABEL_42:
      v8 = flDistance;
LABEL_43:
      pOna = (Polygon_t *)((char *)pOna + 12);
      ++v18;
    }
    while ( v18 < v6->m_Points.m_Size );
  }
  v28 = v6->m_Points.m_Size + 4;
  if ( pBack->m_Points.m_Size > v28 || pFront->m_Points.m_Size > v28 )
    _Error(a1: "ChopPolygon: Num points exceeded estimate");
  if ( pBack->m_Points.m_Size > 64 || pFront->m_Points.m_Size > 64 )
    _Error(a1: "ChopPolygon: Exceeded MAX_POINTS_ON_POLYGON");
}

} // namespace vbsp2
