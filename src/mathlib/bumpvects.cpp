// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mathlib/bumpvects.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10261660
// Name: void GetBumpNormals(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector __near * const)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetBumpNormals(
        const Vector *sVect,
        const Vector *tVect,
        const Vector *flatNormal,
        const Vector *phongNormal,
        Vector *bumpNormals)
{
  bool v5; // bl
  TableVector *v6; // esi
  matrix3x4_t smoothBasis; // [esp+Ch] [ebp-30h] BYREF

  v5 = (float)((float)((float)(flatNormal->y * (float)((float)(tVect->x * sVect->z) - (float)(sVect->x * tVect->z)))
                     + (float)(flatNormal->x * (float)((float)(tVect->z * sVect->y) - (float)(tVect->y * sVect->z))))
             + (float)(flatNormal->z * (float)((float)(sVect->x * tVect->y) - (float)(tVect->x * sVect->y)))) < 0.0;
  CrossProduct(v1: &phongNormal->x, v2: &sVect->x, cross: smoothBasis.m_flMatVal[1]);
  VectorNormalize(vec: (Vector *)smoothBasis.m_flMatVal[1]);
  CrossProduct(v1: smoothBasis.m_flMatVal[1], v2: &phongNormal->x, cross: (float *)&smoothBasis);
  VectorNormalize(vec: (Vector *)&smoothBasis);
  *(Vector *)&smoothBasis.m_flMatVal[2][0] = *phongNormal;
  if ( v5 )
  {
    *(_QWORD *)&smoothBasis.m_flMatVal[1][0] ^= 0x8000000080000000uLL;
    smoothBasis.m_flMatVal[1][2] = -smoothBasis.m_flMatVal[1][2];
  }
  v6 = (TableVector *)g_localBumpBasis_1;
  do
  {
    VectorIRotate(
      in1: &v6->x,
      in2: &smoothBasis,
      out: (float *)((char *)&v6->x + (char *)bumpNormals - (char *)g_localBumpBasis_1));
    ++v6;
  }
  while ( (int)v6 < (int)&FLOAT_1_0eN10 );
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10261690
// Name: void GetBumpNormals(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector __near * const)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetBumpNormals(
        const Vector *sVect,
        const Vector *tVect,
        const Vector *flatNormal,
        const Vector *phongNormal,
        Vector *bumpNormals)
{
  bool v5; // bl
  TableVector *v6; // esi
  matrix3x4_t smoothBasis; // [esp+Ch] [ebp-30h] BYREF

  v5 = (float)((float)((float)(flatNormal->y * (float)((float)(tVect->x * sVect->z) - (float)(sVect->x * tVect->z)))
                     + (float)(flatNormal->x * (float)((float)(tVect->z * sVect->y) - (float)(tVect->y * sVect->z))))
             + (float)(flatNormal->z * (float)((float)(sVect->x * tVect->y) - (float)(tVect->x * sVect->y)))) < 0.0;
  CrossProduct(v1: &phongNormal->x, v2: &sVect->x, cross: smoothBasis.m_flMatVal[1]);
  VectorNormalize(vec: (Vector *)smoothBasis.m_flMatVal[1]);
  CrossProduct(v1: smoothBasis.m_flMatVal[1], v2: &phongNormal->x, cross: (float *)&smoothBasis);
  VectorNormalize(vec: (Vector *)&smoothBasis);
  *(Vector *)&smoothBasis.m_flMatVal[2][0] = *phongNormal;
  if ( v5 )
  {
    *(_QWORD *)&smoothBasis.m_flMatVal[1][0] ^= 0x8000000080000000uLL;
    smoothBasis.m_flMatVal[1][2] = -smoothBasis.m_flMatVal[1][2];
  }
  v6 = (TableVector *)g_localBumpBasis_1;
  do
  {
    VectorIRotate(
      in1: &v6->x,
      in2: &smoothBasis,
      out: (float *)((char *)&v6->x + (char *)bumpNormals - (char *)g_localBumpBasis_1));
    ++v6;
  }
  while ( (int)v6 < (int)&FLOAT_1_0eN10 );
}

} // namespace engine_xlsp
