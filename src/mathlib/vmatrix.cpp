// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mathlib/vmatrix.cpp
// Functions: 19
// ============================================================

#include "mathlib\vmatrix.h"

//------------------------------------------------------------------------------
// Address: 0x1025F3B0
// Name: public: class VMatrix __near & VMatrix::operator=(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
VMatrix *__thiscall VMatrix::operator=(VMatrix *this, const VMatrix *mOther)
{
  *this = *mOther;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1025F420
// Name: public: void VMatrix::SetupMatrixOrgAngles(class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VMatrix::SetupMatrixOrgAngles(VMatrix *this, const Vector *origin, const QAngle *vAngles)
{
  float v4; // xmm1_4
  float v5; // xmm1_4
  double z; // st7
  float v7; // [esp+8h] [ebp-18h]
  float cr; // [esp+Ch] [ebp-14h]
  float sr; // [esp+10h] [ebp-10h]
  float sy; // [esp+14h] [ebp-Ch]
  float cy; // [esp+18h] [ebp-8h]
  float cp; // [esp+1Ch] [ebp-4h]
  float vAnglesa; // [esp+2Ch] [ebp+Ch]

  v4 = vAngles->y * 0.017453292;
  cy = cos(v4);
  sy = sin(v4);
  v5 = vAngles->x * 0.017453292;
  cp = cos(v5);
  vAnglesa = sin(v5);
  v7 = vAngles->z * 0.017453292;
  cr = cos(v7);
  sr = sin(v7);
  this->m[0][0] = cp * cy;
  this->m[1][0] = cp * sy;
  LODWORD(this->m[2][0]) = LODWORD(vAnglesa) ^ _mask__NegFloat_;
  this->m[0][1] = (float)((float)(sr * vAnglesa) * cy) - (float)(cr * sy);
  this->m[1][1] = (float)((float)(sr * vAnglesa) * sy) + (float)(cr * cy);
  this->m[2][1] = sr * cp;
  this->m[1][2] = (float)((float)(cr * vAnglesa) * sy) - (float)(sr * cy);
  this->m[0][3] = 0.0;
  this->m[1][3] = 0.0;
  this->m[2][3] = 0.0;
  this->m[0][2] = (float)((float)(cr * vAnglesa) * cy) + (float)(sr * sy);
  this->m[2][2] = cr * cp;
  this->m[0][3] = origin->x;
  this->m[1][3] = origin->y;
  z = origin->z;
  this->m[3][0] = 0.0;
  this->m[2][3] = z;
  *(_QWORD *)&this->m[3][1] = 0;
  this->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x1025F5B0
// Name: void MatrixSetIdentity(class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixSetIdentity(VMatrix *dst)
{
  *(_QWORD *)&dst->m[0][0] = 1065353216;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = 0.0;
  *(_QWORD *)&dst->m[1][1] = 1065353216;
  dst->m[1][3] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[2][2] = 1065353216;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x1025F640
// Name: void MatrixMultiply(class VMatrix const __near &,class VMatrix const __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixMultiply(const VMatrix *src1, const VMatrix *src2, VMatrix *dst)
{
  float *p_tmp1; // edx
  VMatrix *v4; // edi
  float *p_tmp2; // eax
  VMatrix tmp2; // [esp+Ch] [ebp-80h] BYREF
  VMatrix tmp1; // [esp+4Ch] [ebp-40h] BYREF

  p_tmp1 = (float *)&tmp1;
  if ( src1 != dst )
    p_tmp1 = (float *)src1;
  v4 = src2;
  p_tmp2 = (float *)&tmp2;
  if ( src2 != dst )
    p_tmp2 = (float *)src2;
  if ( src1 == dst && src1 != &tmp1 )
  {
    tmp1 = *src1;
    v4 = src2;
  }
  if ( v4 == dst && v4 != &tmp2 )
    tmp2 = *v4;
  dst->m[0][0] = (float)((float)((float)(p_tmp1[1] * p_tmp2[4]) + (float)(*p_tmp2 * *p_tmp1))
                       + (float)(p_tmp2[8] * p_tmp1[2]))
               + (float)(p_tmp2[12] * p_tmp1[3]);
  dst->m[0][1] = (float)((float)((float)(p_tmp1[1] * p_tmp2[5]) + (float)(*p_tmp1 * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[2]))
               + (float)(p_tmp2[13] * p_tmp1[3]);
  dst->m[0][2] = (float)((float)((float)(p_tmp1[1] * p_tmp2[6]) + (float)(*p_tmp1 * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[2]))
               + (float)(p_tmp2[14] * p_tmp1[3]);
  dst->m[0][3] = (float)((float)((float)(p_tmp1[1] * p_tmp2[7]) + (float)(*p_tmp1 * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[2]))
               + (float)(p_tmp2[15] * p_tmp1[3]);
  dst->m[1][0] = (float)((float)((float)(p_tmp1[5] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[4]))
                       + (float)(p_tmp2[8] * p_tmp1[6]))
               + (float)(p_tmp2[12] * p_tmp1[7]);
  dst->m[1][1] = (float)((float)((float)(p_tmp1[5] * p_tmp2[5]) + (float)(p_tmp1[4] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[6]))
               + (float)(p_tmp2[13] * p_tmp1[7]);
  dst->m[1][2] = (float)((float)((float)(p_tmp1[5] * p_tmp2[6]) + (float)(p_tmp1[4] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[6]))
               + (float)(p_tmp2[14] * p_tmp1[7]);
  dst->m[1][3] = (float)((float)((float)(p_tmp1[5] * p_tmp2[7]) + (float)(p_tmp1[4] * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[6]))
               + (float)(p_tmp1[7] * p_tmp2[15]);
  dst->m[2][0] = (float)((float)((float)(p_tmp1[9] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[8]))
                       + (float)(p_tmp2[8] * p_tmp1[10]))
               + (float)(p_tmp2[12] * p_tmp1[11]);
  dst->m[2][1] = (float)((float)((float)(p_tmp1[9] * p_tmp2[5]) + (float)(p_tmp1[8] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[10]))
               + (float)(p_tmp2[13] * p_tmp1[11]);
  dst->m[2][2] = (float)((float)((float)(p_tmp1[9] * p_tmp2[6]) + (float)(p_tmp1[8] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[10]))
               + (float)(p_tmp2[14] * p_tmp1[11]);
  dst->m[2][3] = (float)((float)((float)(p_tmp1[8] * p_tmp2[3]) + (float)(p_tmp1[9] * p_tmp2[7]))
                       + (float)(p_tmp2[11] * p_tmp1[10]))
               + (float)(p_tmp1[11] * p_tmp2[15]);
  dst->m[3][0] = (float)((float)((float)(p_tmp1[13] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[12]))
                       + (float)(p_tmp2[8] * p_tmp1[14]))
               + (float)(p_tmp2[12] * p_tmp1[15]);
  dst->m[3][1] = (float)((float)((float)(p_tmp1[13] * p_tmp2[5]) + (float)(p_tmp1[12] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[14]))
               + (float)(p_tmp2[13] * p_tmp1[15]);
  dst->m[3][2] = (float)((float)((float)(p_tmp1[13] * p_tmp2[6]) + (float)(p_tmp1[12] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[14]))
               + (float)(p_tmp2[14] * p_tmp1[15]);
  dst->m[3][3] = (float)((float)((float)(p_tmp1[13] * p_tmp2[7]) + (float)(p_tmp1[12] * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[14]))
               + (float)(p_tmp1[15] * p_tmp2[15]);
}

//------------------------------------------------------------------------------
// Address: 0x1025FA30
// Name: void Vector4DMultiply(class VMatrix const __near &,class Vector4D const __near &,class Vector4D __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Vector4DMultiply(const VMatrix *src1, Vector4D *src2, Vector4D *dst)
{
  Vector4D *p_tmp; // eax
  Vector4D tmp; // [esp+0h] [ebp-10h] BYREF

  p_tmp = &tmp;
  if ( src2 == dst )
    tmp = *src2;
  else
    p_tmp = src2;
  dst->x = (float)((float)((float)(src1->m[0][1] * p_tmp->y) + (float)(p_tmp->x * src1->m[0][0]))
                 + (float)(src1->m[0][2] * p_tmp->z))
         + (float)(src1->m[0][3] * p_tmp->w);
  dst->y = (float)((float)((float)(src1->m[1][1] * p_tmp->y) + (float)(src1->m[1][0] * p_tmp->x))
                 + (float)(src1->m[1][2] * p_tmp->z))
         + (float)(src1->m[1][3] * p_tmp->w);
  dst->z = (float)((float)((float)(src1->m[2][1] * p_tmp->y) + (float)(src1->m[2][0] * p_tmp->x))
                 + (float)(src1->m[2][2] * p_tmp->z))
         + (float)(src1->m[2][3] * p_tmp->w);
  dst->w = (float)((float)((float)(src1->m[3][1] * p_tmp->y) + (float)(src1->m[3][0] * p_tmp->x))
                 + (float)(src1->m[3][2] * p_tmp->z))
         + (float)(src1->m[3][3] * p_tmp->w);
}

//------------------------------------------------------------------------------
// Address: 0x1025FB60
// Name: void Vector3DMultiply(class VMatrix const __near &,class Vector const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Vector3DMultiply(const VMatrix *src1, Vector *src2, Vector *dst)
{
  Vector *p_tmp; // eax
  __int64 v4; // xmm0_8
  float z; // edx
  float v6; // xmm3_4
  float v7; // xmm2_4
  float v8; // xmm4_4
  Vector tmp; // [esp+0h] [ebp-18h] BYREF
  __int64 v10; // [esp+Ch] [ebp-Ch]
  float v11; // [esp+14h] [ebp-4h]

  p_tmp = src2;
  if ( src2 == dst )
    p_tmp = &tmp;
  v4 = *(_QWORD *)&p_tmp->x;
  z = p_tmp->z;
  v6 = src1->m[0][1];
  v7 = src1->m[0][0];
  v8 = src1->m[0][2];
  v10 = v4;
  v11 = z;
  dst->x = (float)((float)(v6 * *((float *)&v4 + 1)) + (float)(v7 * *(float *)&v4)) + (float)(v8 * z);
  dst->y = (float)((float)(src1->m[1][0] * *(float *)&v4) + (float)(src1->m[1][1] * *((float *)&v4 + 1)))
         + (float)(src1->m[1][2] * z);
  dst->z = (float)((float)(src1->m[2][0] * *(float *)&v4) + (float)(src1->m[2][1] * *((float *)&v4 + 1)))
         + (float)(src1->m[2][2] * z);
}

//------------------------------------------------------------------------------
// Address: 0x1025FC20
// Name: void Vector3DMultiplyPositionProjective(class VMatrix const __near &,class Vector const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Vector3DMultiplyPositionProjective(const VMatrix *src1, Vector *src2, Vector *dst)
{
  Vector *p_tmp; // eax
  float z; // ecx
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm0_4
  float v8; // xmm4_4
  Vector tmp; // [esp+0h] [ebp-18h] BYREF
  __int64 v10; // [esp+Ch] [ebp-Ch]
  float v11; // [esp+14h] [ebp-4h]

  p_tmp = src2;
  if ( src2 == dst )
    p_tmp = &tmp;
  z = p_tmp->z;
  v10 = *(_QWORD *)&p_tmp->x;
  v5 = *(float *)&v10;
  v6 = *((float *)&v10 + 1);
  v11 = z;
  v7 = (float)((float)((float)(src1->m[3][0] * *(float *)&v10) + (float)(src1->m[3][1] * *((float *)&v10 + 1)))
             + (float)(src1->m[3][2] * z))
     + src1->m[3][3];
  if ( v7 != 0.0 )
    v7 = 1.0 / v7;
  dst->x = (float)((float)((float)(src1->m[0][1] * *((float *)&v10 + 1)) + (float)(src1->m[0][0] * *(float *)&v10))
                 + (float)(src1->m[0][2] * v11))
         + src1->m[0][3];
  dst->y = (float)((float)((float)(src1->m[1][0] * v5) + (float)(src1->m[1][1] * v6)) + (float)(src1->m[1][2] * z))
         + src1->m[1][3];
  v8 = (float)((float)((float)(src1->m[2][0] * v5) + (float)(src1->m[2][1] * v6)) + (float)(src1->m[2][2] * z))
     + src1->m[2][3];
  dst->x = dst->x * v7;
  dst->y = dst->y * v7;
  dst->z = v8 * v7;
}

//------------------------------------------------------------------------------
// Address: 0x1025FD60
// Name: void MatrixTransformPlane(class VMatrix const __near &,struct cplane_t const __near &,struct cplane_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixTransformPlane(const VMatrix *src, const cplane_t *inPlane, cplane_t *outPlane)
{
  const cplane_t *v3; // eax
  __int64 v4; // xmm0_8
  float z; // eax
  float x; // xmm2_4
  float v7; // xmm3_4
  float v8; // xmm1_4
  _DWORD v9[6]; // [esp+0h] [ebp-18h] BYREF

  if ( inPlane == outPlane )
    v3 = (const cplane_t *)v9;
  else
    v3 = inPlane;
  v4 = *(_QWORD *)&v3->normal.x;
  z = v3->normal.z;
  *(_QWORD *)&v9[3] = v4;
  *(float *)&v9[5] = z;
  outPlane->normal.x = (float)((float)(src->m[0][1] * *((float *)&v4 + 1)) + (float)(src->m[0][0] * *(float *)&v4))
                     + (float)(src->m[0][2] * z);
  outPlane->normal.y = (float)((float)(src->m[1][0] * *(float *)&v4) + (float)(src->m[1][1] * *((float *)&v4 + 1)))
                     + (float)(src->m[1][2] * z);
  x = outPlane->normal.x;
  v7 = (float)((float)(src->m[2][0] * *(float *)&v4) + (float)(src->m[2][1] * *((float *)&v4 + 1)))
     + (float)(src->m[2][2] * z);
  *(float *)&v4 = outPlane->normal.y;
  outPlane->normal.z = v7;
  v8 = (float)((float)((float)(x * x) + (float)(*(float *)&v4 * *(float *)&v4)) + (float)(v7 * v7)) * inPlane->dist;
  outPlane->dist = v8;
  outPlane->dist = (float)((float)((float)(*(float *)&v4 * src->m[1][3]) + (float)(x * src->m[0][3]))
                         + (float)(v7 * src->m[2][3]))
                 + v8;
}

//------------------------------------------------------------------------------
// Address: 0x1025FE80
// Name: void MatrixBuildTranslation(class VMatrix __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildTranslation(VMatrix *dst, const Vector *translation)
{
  dst->m[0][3] = 0.0;
  dst->m[1][3] = 0.0;
  dst->m[2][3] = 0.0;
  *(_QWORD *)&dst->m[0][0] = 1065353216;
  dst->m[0][2] = 0.0;
  dst->m[1][0] = 0.0;
  *(_QWORD *)&dst->m[1][1] = 1065353216;
  *(_QWORD *)&dst->m[2][0] = 0;
  dst->m[2][2] = 1.0;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[3][3] = 1.0;
  dst->m[0][3] = translation->x;
  dst->m[1][3] = translation->y;
  dst->m[2][3] = translation->z;
}

//------------------------------------------------------------------------------
// Address: 0x1025FF50
// Name: void CalculateAABBFromProjectionMatrixInverse(class VMatrix const __near &,class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CalculateAABBFromProjectionMatrixInverse(const VMatrix *volumeToWorld, Vector *pMins, Vector *pMaxs)
{
  float v3; // xmm1_4
  float v4; // xmm2_4
  float v5; // xmm3_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm2_4
  float v10; // xmm3_4
  float v11; // xmm0_4
  float v12; // xmm3_4
  float v13; // xmm4_4
  float v14; // xmm0_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm0_4
  float v18; // xmm3_4
  float v19; // xmm4_4
  float v20; // xmm0_4
  float v21; // xmm2_4
  float v22; // xmm3_4
  float v23; // xmm0_4
  float v24; // xmm2_4
  float v25; // xmm3_4
  float v26; // xmm0_4
  float v27; // xmm2_4
  float v28; // xmm3_4
  Vector v; // [esp+Ch] [ebp-Ch] BYREF

  ClearBounds(mins: pMins, maxs: pMaxs);
  v3 = (float)((float)((float)(volumeToWorld->m[3][1] + volumeToWorld->m[3][0]) + volumeToWorld->m[3][2]) * 0.0)
     + volumeToWorld->m[3][3];
  if ( v3 != 0.0 )
    v3 = 1.0 / v3;
  v4 = (float)(volumeToWorld->m[1][1] + volumeToWorld->m[1][0]) + volumeToWorld->m[1][2];
  v5 = (float)(volumeToWorld->m[2][1] + volumeToWorld->m[2][0]) + volumeToWorld->m[2][2];
  v.x = (float)((float)((float)((float)(volumeToWorld->m[0][0] + volumeToWorld->m[0][1]) + volumeToWorld->m[0][2]) * 0.0)
              + volumeToWorld->m[0][3])
      * v3;
  v6 = v3 * (float)((float)(v4 * 0.0) + volumeToWorld->m[1][3]);
  v7 = v3 * (float)((float)(v5 * 0.0) + volumeToWorld->m[2][3]);
  v.y = v6;
  v.z = v7;
  AddPointToBounds(&v, mins: pMins, maxs: pMaxs);
  v8 = (float)((float)((float)(volumeToWorld->m[3][1] + volumeToWorld->m[3][0]) * 0.0) + volumeToWorld->m[3][2])
     + volumeToWorld->m[3][3];
  if ( v8 != 0.0 )
    v8 = 1.0 / v8;
  v9 = (float)((float)((float)((float)(volumeToWorld->m[1][1] + volumeToWorld->m[1][0]) * 0.0) + volumeToWorld->m[1][2])
             + volumeToWorld->m[1][3])
     * v8;
  v10 = (float)((float)((float)((float)(volumeToWorld->m[2][1] + volumeToWorld->m[2][0]) * 0.0) + volumeToWorld->m[2][2])
              + volumeToWorld->m[2][3])
      * v8;
  v.x = (float)((float)((float)((float)(volumeToWorld->m[0][0] + volumeToWorld->m[0][1]) * 0.0) + volumeToWorld->m[0][2])
              + volumeToWorld->m[0][3])
      * v8;
  v.y = v9;
  v.z = v10;
  AddPointToBounds(&v, mins: pMins, maxs: pMaxs);
  v11 = (float)((float)((float)(volumeToWorld->m[3][0] * 0.0) + volumeToWorld->m[3][1])
              + (float)(volumeToWorld->m[3][2] * 0.0))
      + volumeToWorld->m[3][3];
  if ( v11 != 0.0 )
    v11 = 1.0 / v11;
  v12 = (float)((float)((float)((float)(volumeToWorld->m[1][0] * 0.0) + volumeToWorld->m[1][1])
                      + (float)(volumeToWorld->m[1][2] * 0.0))
              + volumeToWorld->m[1][3])
      * v11;
  v13 = (float)((float)((float)((float)(volumeToWorld->m[2][0] * 0.0) + volumeToWorld->m[2][1])
                      + (float)(volumeToWorld->m[2][2] * 0.0))
              + volumeToWorld->m[2][3])
      * v11;
  v.x = (float)((float)((float)((float)(volumeToWorld->m[0][0] * 0.0) + volumeToWorld->m[0][1])
                      + (float)(volumeToWorld->m[0][2] * 0.0))
              + volumeToWorld->m[0][3])
      * v11;
  v.y = v12;
  v.z = v13;
  AddPointToBounds(&v, mins: pMins, maxs: pMaxs);
  v14 = (float)((float)((float)(volumeToWorld->m[3][0] * 0.0) + volumeToWorld->m[3][1]) + volumeToWorld->m[3][2])
      + volumeToWorld->m[3][3];
  if ( v14 != 0.0 )
    v14 = 1.0 / v14;
  v15 = (float)((float)((float)((float)(volumeToWorld->m[1][0] * 0.0) + volumeToWorld->m[1][1]) + volumeToWorld->m[1][2])
              + volumeToWorld->m[1][3])
      * v14;
  v16 = (float)((float)((float)((float)(volumeToWorld->m[2][0] * 0.0) + volumeToWorld->m[2][1]) + volumeToWorld->m[2][2])
              + volumeToWorld->m[2][3])
      * v14;
  v.x = (float)((float)((float)((float)(volumeToWorld->m[0][0] * 0.0) + volumeToWorld->m[0][1]) + volumeToWorld->m[0][2])
              + volumeToWorld->m[0][3])
      * v14;
  v.y = v15;
  v.z = v16;
  AddPointToBounds(&v, mins: pMins, maxs: pMaxs);
  v17 = (float)((float)((float)(volumeToWorld->m[3][1] * 0.0) + volumeToWorld->m[3][0])
              + (float)(volumeToWorld->m[3][2] * 0.0))
      + volumeToWorld->m[3][3];
  if ( v17 != 0.0 )
    v17 = 1.0 / v17;
  v18 = (float)((float)((float)((float)(volumeToWorld->m[1][1] * 0.0) + volumeToWorld->m[1][0])
                      + (float)(volumeToWorld->m[1][2] * 0.0))
              + volumeToWorld->m[1][3])
      * v17;
  v19 = (float)((float)((float)((float)(volumeToWorld->m[2][1] * 0.0) + volumeToWorld->m[2][0])
                      + (float)(volumeToWorld->m[2][2] * 0.0))
              + volumeToWorld->m[2][3])
      * v17;
  v.x = (float)((float)((float)((float)(volumeToWorld->m[0][1] * 0.0) + volumeToWorld->m[0][0])
                      + (float)(volumeToWorld->m[0][2] * 0.0))
              + volumeToWorld->m[0][3])
      * v17;
  v.y = v18;
  v.z = v19;
  AddPointToBounds(&v, mins: pMins, maxs: pMaxs);
  v20 = (float)((float)((float)(volumeToWorld->m[3][1] * 0.0) + volumeToWorld->m[3][0]) + volumeToWorld->m[3][2])
      + volumeToWorld->m[3][3];
  if ( v20 != 0.0 )
    v20 = 1.0 / v20;
  v21 = (float)((float)((float)((float)(volumeToWorld->m[1][1] * 0.0) + volumeToWorld->m[1][0]) + volumeToWorld->m[1][2])
              + volumeToWorld->m[1][3])
      * v20;
  v22 = (float)((float)((float)((float)(volumeToWorld->m[2][1] * 0.0) + volumeToWorld->m[2][0]) + volumeToWorld->m[2][2])
              + volumeToWorld->m[2][3])
      * v20;
  v.x = (float)((float)((float)((float)(volumeToWorld->m[0][1] * 0.0) + volumeToWorld->m[0][0]) + volumeToWorld->m[0][2])
              + volumeToWorld->m[0][3])
      * v20;
  v.y = v21;
  v.z = v22;
  AddPointToBounds(&v, mins: pMins, maxs: pMaxs);
  v23 = (float)((float)(volumeToWorld->m[3][1] + volumeToWorld->m[3][0]) + (float)(volumeToWorld->m[3][2] * 0.0))
      + volumeToWorld->m[3][3];
  if ( v23 != 0.0 )
    v23 = 1.0 / v23;
  v24 = (float)((float)((float)(volumeToWorld->m[1][1] + volumeToWorld->m[1][0]) + (float)(volumeToWorld->m[1][2] * 0.0))
              + volumeToWorld->m[1][3])
      * v23;
  v25 = (float)((float)((float)(volumeToWorld->m[2][1] + volumeToWorld->m[2][0]) + (float)(volumeToWorld->m[2][2] * 0.0))
              + volumeToWorld->m[2][3])
      * v23;
  v.x = (float)((float)((float)(volumeToWorld->m[0][0] + volumeToWorld->m[0][1]) + (float)(volumeToWorld->m[0][2] * 0.0))
              + volumeToWorld->m[0][3])
      * v23;
  v.y = v24;
  v.z = v25;
  AddPointToBounds(&v, mins: pMins, maxs: pMaxs);
  v26 = (float)((float)(volumeToWorld->m[3][1] + volumeToWorld->m[3][0]) + volumeToWorld->m[3][2])
      + volumeToWorld->m[3][3];
  if ( v26 != 0.0 )
    v26 = 1.0 / v26;
  v27 = (float)((float)((float)(volumeToWorld->m[1][1] + volumeToWorld->m[1][0]) + volumeToWorld->m[1][2])
              + volumeToWorld->m[1][3])
      * v26;
  v28 = (float)((float)((float)(volumeToWorld->m[2][1] + volumeToWorld->m[2][0]) + volumeToWorld->m[2][2])
              + volumeToWorld->m[2][3])
      * v26;
  v.x = (float)((float)((float)(volumeToWorld->m[0][0] + volumeToWorld->m[0][1]) + volumeToWorld->m[0][2])
              + volumeToWorld->m[0][3])
      * v26;
  v.y = v27;
  v.z = v28;
  AddPointToBounds(&v, mins: pMins, maxs: pMaxs);
}

//------------------------------------------------------------------------------
// Address: 0x102604D0
// Name: FrustumPlanesFromMatrixHelper
// Source: json
//------------------------------------------------------------------------------
void __usercall FrustumPlanesFromMatrixHelper(
        const Vector *p1@<eax>,
        Vector *p2@<edx>,
        Vector *p3@<edi>,
        VPlane *plane@<esi>,
        const VMatrix *shadowToWorld)
{
  __int64 v5; // xmm0_8
  float z; // eax
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm3_4
  float v11; // xmm6_4
  float v12; // xmm0_4
  Vector *p_world2; // eax
  __int64 v14; // xmm0_8
  float v15; // eax
  float v16; // xmm3_4
  float v17; // xmm2_4
  float v18; // xmm1_4
  Vector *p_world3; // eax
  float v20; // edx
  float v21; // xmm5_4
  float v22; // xmm5_4
  float v23; // xmm6_4
  float v24; // xmm0_4
  float v25; // xmm4_4
  float v26; // xmm5_4
  float v27; // xmm2_4
  float v28; // xmm4_4
  float v29; // xmm1_4
  float v30; // xmm0_4
  Vector world3; // [esp+4h] [ebp-30h] BYREF
  Vector world2; // [esp+10h] [ebp-24h] BYREF
  __int64 v33; // [esp+1Ch] [ebp-18h]
  float v34; // [esp+24h] [ebp-10h]
  Vector world1; // [esp+28h] [ebp-Ch] BYREF

  if ( p1 == &world1 )
  {
    world2 = world3;
    p1 = &world2;
  }
  v5 = *(_QWORD *)&p1->x;
  z = p1->z;
  v7 = shadowToWorld->m[3][1];
  *(_QWORD *)&world1.x = v5;
  world1.z = z;
  v8 = (float)((float)((float)(*(float *)&v5 * shadowToWorld->m[3][0]) + (float)(v7 * *((float *)&v5 + 1)))
             + (float)(z * shadowToWorld->m[3][2]))
     + shadowToWorld->m[3][3];
  if ( v8 != 0.0 )
    v8 = 1.0 / v8;
  v9 = (float)((float)((float)(shadowToWorld->m[0][0] * *(float *)&v5)
                     + (float)(*((float *)&v5 + 1) * shadowToWorld->m[0][1]))
             + (float)(z * shadowToWorld->m[0][2]))
     + shadowToWorld->m[0][3];
  v10 = (float)(*(float *)&v5 * shadowToWorld->m[1][0]) + (float)(shadowToWorld->m[1][1] * *((float *)&v5 + 1));
  v11 = shadowToWorld->m[1][2] * z;
  v12 = (float)((float)((float)(*(float *)&v5 * shadowToWorld->m[2][0])
                      + (float)(*((float *)&v5 + 1) * shadowToWorld->m[2][1]))
              + (float)(z * shadowToWorld->m[2][2]))
      + shadowToWorld->m[2][3];
  world1.x = v9 * v8;
  world1.y = v8 * (float)((float)(v10 + v11) + shadowToWorld->m[1][3]);
  world1.z = v12 * v8;
  if ( p2 == &world2 )
  {
    world2 = world3;
    p_world2 = &world2;
  }
  else
  {
    p_world2 = p2;
  }
  v14 = *(_QWORD *)&p_world2->x;
  v15 = p_world2->z;
  v33 = v14;
  v34 = v15;
  v16 = (float)((float)((float)(*(float *)&v14 * shadowToWorld->m[3][0])
                      + (float)(*((float *)&v14 + 1) * shadowToWorld->m[3][1]))
              + (float)(v15 * shadowToWorld->m[3][2]))
      + shadowToWorld->m[3][3];
  if ( v16 != 0.0 )
    v16 = 1.0 / v16;
  v17 = (float)((float)((float)((float)(shadowToWorld->m[0][0] * *(float *)&v14)
                              + (float)(*((float *)&v14 + 1) * shadowToWorld->m[0][1]))
                      + (float)(v15 * shadowToWorld->m[0][2]))
              + shadowToWorld->m[0][3])
      * v16;
  v18 = (float)((float)((float)((float)(*(float *)&v14 * shadowToWorld->m[2][0])
                              + (float)(*((float *)&v14 + 1) * shadowToWorld->m[2][1]))
                      + (float)(v15 * shadowToWorld->m[2][2]))
              + shadowToWorld->m[2][3])
      * v16;
  world2.y = (float)((float)((float)((float)(*(float *)&v14 * shadowToWorld->m[1][0])
                                   + (float)(*((float *)&v14 + 1) * shadowToWorld->m[1][1]))
                           + (float)(shadowToWorld->m[1][2] * v15))
                   + shadowToWorld->m[1][3])
           * v16;
  world2.z = v18;
  if ( p3 == &world3 )
    p_world3 = &world3;
  else
    p_world3 = p3;
  v20 = p_world3->z;
  v33 = *(_QWORD *)&p_world3->x;
  v21 = (float)(*(float *)&v33 * shadowToWorld->m[3][0]) + (float)(*((float *)&v33 + 1) * shadowToWorld->m[3][1]);
  v34 = v20;
  v22 = (float)(v21 + (float)(v20 * shadowToWorld->m[3][2])) + shadowToWorld->m[3][3];
  if ( v22 != 0.0 )
    v22 = 1.0 / v22;
  v23 = v17 - world1.x;
  v24 = (float)((float)((float)((float)((float)(*(float *)&v33 * shadowToWorld->m[1][0])
                                      + (float)(*((float *)&v33 + 1) * shadowToWorld->m[1][1]))
                              + (float)(shadowToWorld->m[1][2] * v20))
                      + shadowToWorld->m[1][3])
              * v22)
      - world1.y;
  v25 = (float)((float)((float)((float)(v20 * shadowToWorld->m[2][2])
                              + (float)((float)(*(float *)&v33 * shadowToWorld->m[2][0])
                                      + (float)(*((float *)&v33 + 1) * shadowToWorld->m[2][1])))
                      + shadowToWorld->m[2][3])
              * v22)
      - world1.z;
  v26 = (float)((float)((float)((float)((float)(shadowToWorld->m[0][0] * *(float *)&v33)
                                      + (float)(*((float *)&v33 + 1) * shadowToWorld->m[0][1]))
                              + (float)(v20 * shadowToWorld->m[0][2]))
                      + shadowToWorld->m[0][3])
              * v22)
      - world1.x;
  v27 = v25 * (float)(v17 - world1.x);
  v28 = (float)(v25 * (float)(world2.y - world1.y)) - (float)(v24 * (float)(world2.z - world1.z));
  v29 = (float)((float)(world2.z - world1.z) * v26) - v27;
  v30 = (float)(v24 * v23) - (float)((float)(world2.y - world1.y) * v26);
  plane->m_Normal.x = v28;
  plane->m_Normal.y = v29;
  plane->m_Normal.z = v30;
  VectorNormalize(vec: &plane->m_Normal);
  plane->m_Dist = (float)((float)(plane->m_Normal.y * world1.y) + (float)(world1.x * plane->m_Normal.x))
                + (float)(plane->m_Normal.z * world1.z);
}

//------------------------------------------------------------------------------
// Address: 0x10260860
// Name: void FrustumPlanesFromMatrix(class VMatrix const __near &,class Frustum_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FrustumPlanesFromMatrix(const VMatrix *clipToWorld, Frustum_t *frustum)
{
  VPlane planes[6]; // [esp+0h] [ebp-84h] BYREF
  Vector p3; // [esp+60h] [ebp-24h] BYREF
  Vector p1; // [esp+6Ch] [ebp-18h] BYREF
  Vector p2; // [esp+78h] [ebp-Ch] BYREF

  p3.x = 0.0;
  p3.y = 1.0;
  p3.z = 0.0;
  p2.x = 1.0;
  p2.y = 0.0;
  p2.z = 0.0;
  memset(&p1, 0, sizeof(p1));
  FrustumPlanesFromMatrixHelper(&p1, &p2, &p3, plane: &planes[4], shadowToWorld: clipToWorld);
  p1.x = 1.0;
  p1.y = 0.0;
  p1.z = 1.0;
  p2.x = 0.0;
  p2.y = 1.0;
  p2.z = 1.0;
  p3.x = 0.0;
  p3.y = 0.0;
  p3.z = 1.0;
  FrustumPlanesFromMatrixHelper(p1: &p3, &p2, p3: &p1, plane: &planes[5], shadowToWorld: clipToWorld);
  p1.x = 1.0;
  p1.y = 1.0;
  p1.z = 0.0;
  p2.x = 1.0;
  p2.y = 1.0;
  p2.z = 1.0;
  p3.x = 1.0;
  p3.y = 0.0;
  p3.z = 0.0;
  FrustumPlanesFromMatrixHelper(p1: &p3, &p2, p3: &p1, plane: planes, shadowToWorld: clipToWorld);
  p1.x = 0.0;
  p1.y = 0.0;
  p1.z = 1.0;
  p2.x = 0.0;
  p2.y = 1.0;
  p2.z = 1.0;
  memset(&p3, 0, sizeof(p3));
  FrustumPlanesFromMatrixHelper(p1: &p3, &p2, p3: &p1, plane: &planes[1], shadowToWorld: clipToWorld);
  p1.x = 0.0;
  p1.y = 1.0;
  p1.z = 1.0;
  p2.x = 1.0;
  p2.y = 1.0;
  p2.z = 1.0;
  p3.x = 1.0;
  p3.y = 1.0;
  p3.z = 0.0;
  FrustumPlanesFromMatrixHelper(p1: &p3, &p2, p3: &p1, plane: &planes[2], shadowToWorld: clipToWorld);
  p1.x = 1.0;
  p1.y = 0.0;
  p1.z = 1.0;
  p2.x = 0.0;
  p2.y = 0.0;
  p2.z = 1.0;
  p3.x = 1.0;
  p3.y = 0.0;
  p3.z = 0.0;
  FrustumPlanesFromMatrixHelper(p1: &p3, &p2, p3: &p1, plane: &planes[3], shadowToWorld: clipToWorld);
  Frustum_t::SetPlanes(this: frustum, pPlanes: planes);
}

//------------------------------------------------------------------------------
// Address: 0x10260A50
// Name: void MatrixBuildOrtho(class VMatrix __near &,double,double,double,double,double,double)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildOrtho(
        VMatrix *dst,
        long double left,
        long double top,
        long double right,
        long double bottom,
        long double zNear,
        long double zFar)
{
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm1_4
  long double v11; // xmm1_8

  v7 = 2.0 / (right - left);
  v8 = (left + right) / (left - right);
  dst->m[0][3] = v8;
  v9 = 2.0 / (bottom - top);
  dst->m[1][1] = v9;
  dst->m[0][0] = v7;
  v10 = (top + bottom) / (top - bottom);
  dst->m[1][3] = v10;
  v11 = 1.0 / (zNear - zFar);
  *(_QWORD *)&dst->m[0][1] = 0;
  dst->m[1][0] = 0.0;
  dst->m[1][2] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[2][2] = v11;
  dst->m[2][3] = v11 * zNear;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10260B50
// Name: void MatrixBuildPerspectiveX(class VMatrix __near &,double,double,double,double)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildPerspectiveX(
        VMatrix *dst,
        long double flFovX,
        long double flAspect,
        long double flZNear,
        long double flZFar)
{
  float v5; // xmm0_4
  float v6; // xmm2_4
  double v7; // xmm0_8
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm1_4
  float v11; // xmm4_4
  double v12; // [esp+0h] [ebp-8h]

  __libm_sse2_tan(x: flZNear * 2.0);
  v5 = flFovX * 3.141592653589793 * 0.002777777777777778;
  v6 = v5 * v12;
  v7 = v6;
  v8 = v6 / flAspect;
  v9 = v12 / v8;
  dst->m[1][1] = v9;
  *(float *)&v7 = v12 / v7;
  v10 = flZNear * flZFar / (flZNear - flZFar);
  dst->m[0][0] = *(float *)&v7;
  dst->m[2][3] = v10;
  v11 = flZFar / (flZNear - flZFar);
  *(_QWORD *)&dst->m[0][1] = 0;
  dst->m[0][3] = 0.0;
  dst->m[1][0] = 0.0;
  *(_QWORD *)&dst->m[1][2] = 0;
  *(_QWORD *)&dst->m[2][0] = 0;
  dst->m[2][2] = v11;
  *(_QWORD *)&dst->m[3][0] = 0;
  *(_QWORD *)&dst->m[3][2] = 3212836864LL;
}

//------------------------------------------------------------------------------
// Address: 0x10260C60
// Name: void MatrixBuildPerspectiveOffCenterX(class VMatrix __near &,double,double,double,double,double,double,double,double)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildPerspectiveOffCenterX(
        VMatrix *dst,
        long double flFovX,
        long double flAspect,
        long double flZNear,
        long double flZFar,
        long double bottom,
        long double top,
        long double left,
        long double right)
{
  float v9; // xmm0_4
  float v10; // xmm0_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  long double v13; // xmm5_8
  float v14; // xmm1_4
  long double v15; // xmm6_8
  float v16; // xmm2_4
  float v17; // xmm0_4
  float v18; // xmm3_4
  float v19; // xmm1_4
  double v20; // [esp+0h] [ebp-8h]

  __libm_sse2_tan(x: flZNear * 2.0);
  v9 = flFovX * 3.141592653589793 * 0.002777777777777778;
  v10 = v9 * v20;
  v11 = (float)(v10 / flAspect) * 0.5;
  v12 = v10 * 0.5;
  v13 = v12 * left - (1.0 - left) * v12;
  v14 = v12 * right - (1.0 - right) * v12;
  v15 = v11 * bottom - (1.0 - bottom) * v11;
  *(float *)&v13 = v13;
  v16 = v11 * top - (1.0 - top) * v11;
  dst->m[0][2] = (float)(v14 + *(float *)&v13) / (float)(v14 - *(float *)&v13);
  *(float *)&v15 = v15;
  v17 = v20 / (float)(v14 - *(float *)&v13);
  dst->m[0][0] = v17;
  v18 = v20 / (float)(v16 - *(float *)&v15);
  dst->m[0][1] = 0.0;
  dst->m[0][3] = 0.0;
  dst->m[1][0] = 0.0;
  dst->m[1][1] = v18;
  dst->m[1][2] = (float)(v16 + *(float *)&v15) / (float)(v16 - *(float *)&v15);
  v19 = flZNear * flZFar / (flZNear - flZFar);
  dst->m[2][3] = v19;
  dst->m[1][3] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  dst->m[2][2] = flZFar / (flZNear - flZFar);
  *(_QWORD *)&dst->m[3][0] = 0;
  *(_QWORD *)&dst->m[3][2] = 3212836864LL;
}

//------------------------------------------------------------------------------
// Address: 0x10260E30
// Name: class VMatrix SetupMatrixScale(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
VMatrix *__cdecl SetupMatrixScale(VMatrix *result, const Vector *vScale)
{
  double x; // st7
  double y; // st7
  double z; // st7

  x = vScale->x;
  result->m[0][1] = 0.0;
  result->m[0][0] = x;
  result->m[0][2] = 0.0;
  y = vScale->y;
  result->m[0][3] = 0.0;
  result->m[1][1] = y;
  result->m[1][0] = 0.0;
  z = vScale->z;
  *(_QWORD *)&result->m[1][2] = 0;
  result->m[2][2] = z;
  *(_QWORD *)&result->m[2][0] = 0;
  result->m[2][3] = 0.0;
  *(_QWORD *)&result->m[3][0] = 0;
  result->m[3][2] = 0.0;
  result->m[3][3] = 1.0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10260EA0
// Name: bool MatrixInverseGeneral(class VMatrix const __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl MatrixInverseGeneral(const VMatrix *src, VMatrix *dst)
{
  int v3; // edx
  _DWORD *v4; // eax
  float *v5; // ecx
  int v6; // ebx
  int v7; // edx
  int i; // edi
  int v9; // ecx
  float v10; // xmm0_4
  int v11; // eax
  float v12; // xmm1_4
  float v13; // xmm1_4
  float v14; // xmm1_4
  float v15; // xmm1_4
  float v16; // xmm1_4
  int v17; // eax
  float v18; // xmm1_4
  float *v19; // eax
  float v20; // xmm0_4
  int j; // esi
  float *v22; // ecx
  float v23; // xmm0_4
  int k; // edx
  float *v26; // ecx
  float v27; // esi
  float v28; // ecx
  float mat[4][8]; // [esp+0h] [ebp-90h] BYREF
  int rowMap[4]; // [esp+80h] [ebp-10h] BYREF

  v3 = 0;
  v4 = &mat[0][5];
  do
  {
    *(v4 - 5) = LODWORD(src->m[0][0]);
    v5 = (float *)(v4 - 5);
    v5[1] = src->m[0][1];
    v5[2] = src->m[0][2];
    v5[3] = src->m[0][3];
    *(v4 - 1) = 0;
    *v4 = 0;
    v4[1] = 0;
    v4[2] = 0;
    rowMap[v3] = v3;
    v6 = (int)&v4[v3++ - 5] + 16 - (_DWORD)rowMap;
    src = (const VMatrix *)((char *)src + 16);
    v4 += 8;
    *(int *)((char *)rowMap + v6) = 1065353216;
  }
  while ( v3 < 4 );
  v7 = 0;
  for ( i = 4; i > 0; --i )
  {
    v9 = -1;
    v10 = 0.000001;
    v11 = v7;
    if ( i >= 4 )
    {
      do
      {
        v12 = fabs(mat[rowMap[v11]][v7]);
        if ( v12 > v10 )
        {
          v9 = v11;
          v10 = v12;
        }
        v13 = fabs(mat[rowMap[v11 + 1]][v7]);
        if ( v13 > v10 )
        {
          v9 = v11 + 1;
          v10 = v13;
        }
        v14 = fabs(mat[rowMap[v11 + 2]][v7]);
        if ( v14 > v10 )
        {
          v9 = v11 + 2;
          v10 = v14;
        }
        v15 = fabs(mat[rowMap[v11 + 3]][v7]);
        if ( v15 > v10 )
        {
          v9 = v11 + 3;
          v10 = v15;
        }
        v11 += 4;
      }
      while ( v11 < 1 );
    }
    for ( ; v11 < 4; ++v11 )
    {
      v16 = fabs(mat[rowMap[v11]][v7]);
      if ( v16 > v10 )
      {
        v9 = v11;
        v10 = v16;
      }
    }
    if ( v9 == -1 )
      return 0;
    v17 = rowMap[v9];
    rowMap[v9] = rowMap[v7];
    rowMap[v7] = v17;
    v17 *= 32;
    v18 = *(float *)((char *)mat[0] + v17);
    v19 = (float *)((char *)mat[0] + v17);
    v20 = 1.0 / v19[v7];
    *v19 = v18 * v20;
    v19[1] = v19[1] * v20;
    v19[2] = v19[2] * v20;
    v19[3] = v19[3] * v20;
    v19[4] = v19[4] * v20;
    v19[5] = v19[5] * v20;
    v19[6] = v19[6] * v20;
    v19[7] = v19[7] * v20;
    v19[v7] = 1.0;
    for ( j = 0; j < 4; ++j )
    {
      if ( j != v7 )
      {
        v22 = mat[rowMap[j]];
        v23 = -v22[v7];
        *v22 = (float)(*v19 * v23) + *v22;
        v22[1] = (float)(v19[1] * v23) + v22[1];
        v22[2] = (float)(v19[2] * v23) + v22[2];
        v22[3] = (float)(v19[3] * v23) + v22[3];
        v22[4] = (float)(v19[4] * v23) + v22[4];
        v22[5] = (float)(v19[5] * v23) + v22[5];
        v22[6] = (float)(v19[6] * v23) + v22[6];
        v22[7] = (float)(v19[7] * v23) + v22[7];
        v22[v7] = 0.0;
      }
    }
    ++v7;
  }
  for ( k = 0; k < 4; ++k )
  {
    v26 = &mat[rowMap[k]][4];
    dst->m[0][0] = *v26;
    dst->m[0][1] = v26[1];
    v27 = v26[2];
    v28 = v26[3];
    dst->m[0][2] = v27;
    dst->m[0][3] = v28;
    dst = (VMatrix *)((char *)dst + 16);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102611C0
// Name: void MatrixInverseTR(class VMatrix const __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixInverseTR(const VMatrix *src, VMatrix *dst)
{
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm4_4
  float v8; // xmm5_4
  float v9; // xmm1_4
  float v10; // xmm0_4

  dst->m[0][0] = src->m[0][0];
  dst->m[0][1] = src->m[1][0];
  dst->m[0][2] = src->m[2][0];
  dst->m[1][0] = src->m[0][1];
  dst->m[1][1] = src->m[1][1];
  dst->m[1][2] = src->m[2][1];
  dst->m[2][0] = src->m[0][2];
  dst->m[2][1] = src->m[1][2];
  dst->m[2][2] = src->m[2][2];
  v3 = -src->m[0][3];
  v4 = -src->m[1][3];
  v5 = -src->m[2][3];
  v6 = (float)((float)(dst->m[0][0] * v3) + (float)(v4 * dst->m[0][1])) + (float)(dst->m[0][2] * v5);
  v7 = (float)((float)(dst->m[1][1] * v4) + (float)(dst->m[1][0] * v3)) + (float)(v5 * dst->m[1][2]);
  v8 = dst->m[2][1] * v4;
  v9 = dst->m[2][0] * v3;
  v10 = dst->m[2][2] * v5;
  dst->m[0][3] = v6;
  dst->m[1][3] = v7;
  dst->m[2][3] = (float)(v8 + v9) + v10;
  *(_QWORD *)&dst->m[3][1] = 0;
  dst->m[3][0] = 0.0;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x102612C0
// Name: void CalculateSphereFromProjectionMatrixInverse(class VMatrix const __near &,class Vector __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CalculateSphereFromProjectionMatrixInverse(
        const VMatrix *volumeToWorld,
        Vector *pCenter,
        float *pflRadius)
{
  float v3; // xmm6_4
  float v4; // xmm5_4
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm7_4
  float v9; // xmm0_4
  float v10; // xmm4_4
  float v11; // xmm1_4
  float v12; // xmm6_4
  float v13; // xmm7_4
  float v14; // xmm6_4
  float v15; // xmm5_4
  float v16; // xmm2_4
  float v17; // xmm0_4
  float v18; // [esp-4h] [ebp-34h]
  float vecFarEdge_4; // [esp+4h] [ebp-2Ch]
  float vecFarEdge_8; // [esp+8h] [ebp-28h]
  float vecCenterFar; // [esp+Ch] [ebp-24h]
  float vecCenterFar_4; // [esp+10h] [ebp-20h]
  float vecCenterFar_8; // [esp+14h] [ebp-1Ch]
  float vecNearEdge; // [esp+18h] [ebp-18h]
  float vecNearEdge_4; // [esp+1Ch] [ebp-14h]
  float vecNearEdge_8; // [esp+20h] [ebp-10h]

  v3 = (float)((float)((float)(volumeToWorld->m[3][1] + volumeToWorld->m[3][0]) * 0.5)
             + (float)(volumeToWorld->m[3][2] * 0.0))
     + volumeToWorld->m[3][3];
  if ( v3 != 0.0 )
    v3 = 1.0 / v3;
  v4 = (float)((float)((float)((float)(volumeToWorld->m[0][0] + volumeToWorld->m[0][1]) * 0.5)
                     + (float)(volumeToWorld->m[0][2] * 0.0))
             + volumeToWorld->m[0][3])
     * v3;
  v5 = (float)((float)((float)(volumeToWorld->m[3][1] + volumeToWorld->m[3][0]) * 0.5) + volumeToWorld->m[3][2])
     + volumeToWorld->m[3][3];
  vecNearEdge = v4;
  vecNearEdge_4 = (float)((float)((float)((float)(volumeToWorld->m[1][1] + volumeToWorld->m[1][0]) * 0.5)
                                + (float)(volumeToWorld->m[1][2] * 0.0))
                        + volumeToWorld->m[1][3])
                * v3;
  vecNearEdge_8 = (float)((float)((float)((float)(volumeToWorld->m[2][1] + volumeToWorld->m[2][0]) * 0.5)
                                + (float)(volumeToWorld->m[2][2] * 0.0))
                        + volumeToWorld->m[2][3])
                * v3;
  if ( v5 != 0.0 )
    v5 = 1.0 / v5;
  v6 = (float)((float)((float)((float)(volumeToWorld->m[1][1] + volumeToWorld->m[1][0]) * 0.5) + volumeToWorld->m[1][2])
             + volumeToWorld->m[1][3])
     * v5;
  v7 = (float)((float)((float)((float)(volumeToWorld->m[2][1] + volumeToWorld->m[2][0]) * 0.5) + volumeToWorld->m[2][2])
             + volumeToWorld->m[2][3])
     * v5;
  v8 = (float)((float)((float)((float)(volumeToWorld->m[0][0] + volumeToWorld->m[0][1]) * 0.5) + volumeToWorld->m[0][2])
             + volumeToWorld->m[0][3])
     * v5;
  v9 = (float)((float)((float)(volumeToWorld->m[3][1] + volumeToWorld->m[3][0]) + volumeToWorld->m[3][2]) * 0.0)
     + volumeToWorld->m[3][3];
  vecFarEdge_4 = v6;
  vecFarEdge_8 = v7;
  if ( v9 != 0.0 )
    v9 = 1.0 / v9;
  v10 = (float)((float)((float)(volumeToWorld->m[3][1] + volumeToWorld->m[3][0]) * 0.0) + volumeToWorld->m[3][2])
      + volumeToWorld->m[3][3];
  if ( v10 != 0.0 )
    v10 = 1.0 / v10;
  v11 = (float)((float)((float)(volumeToWorld->m[1][1] + volumeToWorld->m[1][0]) * 0.0) + volumeToWorld->m[1][2])
      + volumeToWorld->m[1][3];
  v18 = (float)((float)((float)((float)(volumeToWorld->m[2][1] + volumeToWorld->m[2][0]) * 0.0) + volumeToWorld->m[2][2])
              + volumeToWorld->m[2][3])
      * v10;
  v12 = v8;
  v13 = v8
      - (float)((float)((float)((float)((float)(volumeToWorld->m[0][0] + volumeToWorld->m[0][1]) * 0.0)
                              + volumeToWorld->m[0][2])
                      + volumeToWorld->m[0][3])
              * v10);
  v14 = v12 - v4;
  vecCenterFar = (float)((float)((float)((float)(volumeToWorld->m[0][0] + volumeToWorld->m[0][1])
                                       + volumeToWorld->m[0][2])
                               * 0.0)
                       + volumeToWorld->m[0][3])
               * v9;
  vecCenterFar_4 = (float)((float)((float)((float)(volumeToWorld->m[1][1] + volumeToWorld->m[1][0])
                                         + volumeToWorld->m[1][2])
                                 * 0.0)
                         + volumeToWorld->m[1][3])
                 * v9;
  vecCenterFar_8 = (float)((float)((float)((float)(volumeToWorld->m[2][1] + volumeToWorld->m[2][0])
                                         + volumeToWorld->m[2][2])
                                 * 0.0)
                         + volumeToWorld->m[2][3])
                 * v9;
  v15 = (float)((float)((float)(vecNearEdge_4 - vecCenterFar_4) * (float)(vecNearEdge_4 - vecCenterFar_4))
              + (float)((float)(v4 - vecCenterFar) * (float)(v4 - vecCenterFar)))
      + (float)((float)(vecNearEdge_8 - vecCenterFar_8) * (float)(vecNearEdge_8 - vecCenterFar_8));
  v16 = fsqrt(
          (float)((float)((float)(vecFarEdge_4 - vecNearEdge_4) * (float)(vecFarEdge_4 - vecNearEdge_4))
                + (float)((float)(v7 - vecNearEdge_8) * (float)(v7 - vecNearEdge_8)))
        + (float)(v14 * v14));
  v17 = (float)((float)((float)((float)((float)((float)(vecFarEdge_4 - (float)(v11 * v10))
                                              * (float)(vecFarEdge_4 - (float)(v11 * v10)))
                                      + (float)(v13 * v13))
                              + (float)((float)(vecFarEdge_8 - v18) * (float)(vecFarEdge_8 - v18)))
                      + (float)(v16 * v16))
              - v15)
      / (float)(v16 * 2.0);
  pCenter->x = (float)((float)(v17 / v16) * v14) + vecNearEdge;
  pCenter->y = (float)((float)(vecFarEdge_4 - vecNearEdge_4) * (float)(v17 / v16)) + vecNearEdge_4;
  pCenter->z = (float)((float)(vecFarEdge_8 - vecNearEdge_8) * (float)(v17 / v16)) + vecNearEdge_8;
  *pflRadius = fsqrt((float)(v17 * v17) + v15);
}

// ============================================================
// Overlay from MaterialSystem (Missing functions)
// ============================================================
namespace MaterialSystem {

//------------------------------------------------------------------------------
// Address: 0x10250740
// Name: public: class VMatrix __near & VMatrix::operator=(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
VMatrix *__thiscall VMatrix::operator=(VMatrix *this, const VMatrix *mOther)
{
  *this = *mOther;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102507B0
// Name: public: void VMatrix::MatrixMul(class VMatrix const __near &,class VMatrix __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall VMatrix::MatrixMul(VMatrix *this, const VMatrix *vm, VMatrix *out)
{
  float v4; // xmm0_4
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm4_4
  float v8; // xmm5_4
  float v9; // xmm1_4
  float v10; // xmm7_4
  float v11; // xmm6_4
  float v12; // xmm0_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm3_4
  float v18; // xmm1_4
  float v19; // [esp+0h] [ebp-3Ch]
  float v20; // [esp+4h] [ebp-38h]
  float v21; // [esp+8h] [ebp-34h]
  float v22; // [esp+Ch] [ebp-30h]
  float v23; // [esp+10h] [ebp-2Ch]
  float v24; // [esp+14h] [ebp-28h]
  float v25; // [esp+18h] [ebp-24h]
  float v26; // [esp+1Ch] [ebp-20h]
  float v27; // [esp+20h] [ebp-1Ch]
  float v28; // [esp+24h] [ebp-18h]
  float v29; // [esp+28h] [ebp-14h]
  float v30; // [esp+28h] [ebp-14h]
  float v31; // [esp+28h] [ebp-14h]
  float v32; // [esp+2Ch] [ebp-10h]
  float v33; // [esp+30h] [ebp-Ch]
  float v34; // [esp+34h] [ebp-8h]
  __int64 v35; // [esp+34h] [ebp-8h]
  __int64 v36; // [esp+34h] [ebp-8h]
  float v37; // [esp+38h] [ebp-4h]
  float vma; // [esp+44h] [ebp+8h]

  v4 = this->m[0][1];
  v5 = this->m[0][2];
  v6 = this->m[0][3];
  v7 = (float)((float)((float)(this->m[0][0] * vm->m[0][1]) + (float)(v4 * vm->m[1][1])) + (float)(v5 * vm->m[2][1]))
     + (float)(v6 * vm->m[3][1]);
  v8 = (float)((float)((float)(vm->m[0][2] * this->m[0][0]) + (float)(vm->m[1][2] * v4)) + (float)(vm->m[2][2] * v5))
     + (float)(vm->m[3][2] * v6);
  v33 = vm->m[2][0];
  v37 = this->m[1][2];
  v32 = vm->m[3][0];
  v34 = this->m[1][3];
  v9 = vm->m[0][0];
  v10 = vm->m[1][0];
  v29 = this->m[1][1];
  v11 = (float)((float)((float)(vm->m[0][3] * this->m[0][0]) + (float)(vm->m[1][3] * v4)) + (float)(vm->m[2][3] * v5))
      + (float)(vm->m[3][3] * v6);
  v12 = this->m[1][0];
  v28 = (float)((float)((float)(vm->m[0][0] * v12) + (float)(v29 * v10)) + (float)(v37 * v33)) + (float)(v34 * v32);
  v27 = (float)((float)((float)(v12 * vm->m[0][1]) + (float)(v29 * vm->m[1][1])) + (float)(v37 * vm->m[2][1]))
      + (float)(v34 * vm->m[3][1]);
  v26 = (float)((float)((float)(v12 * vm->m[0][2]) + (float)(v29 * vm->m[1][2])) + (float)(v37 * vm->m[2][2]))
      + (float)(v34 * vm->m[3][2]);
  v13 = this->m[2][0];
  v25 = (float)((float)((float)(v12 * vm->m[0][3]) + (float)(v29 * vm->m[1][3])) + (float)(v37 * vm->m[2][3]))
      + (float)(v34 * vm->m[3][3]);
  v35 = *(_QWORD *)&this->m[2][2];
  v30 = this->m[2][1];
  v24 = (float)((float)((float)(v13 * vm->m[0][0]) + (float)(v30 * v10)) + (float)(*(float *)&v35 * v33))
      + (float)(*((float *)&v35 + 1) * v32);
  v23 = (float)((float)((float)(v13 * vm->m[0][1]) + (float)(v30 * vm->m[1][1])) + (float)(*(float *)&v35 * vm->m[2][1]))
      + (float)(*((float *)&v35 + 1) * vm->m[3][1]);
  v22 = (float)((float)((float)(v13 * vm->m[0][2]) + (float)(v30 * vm->m[1][2])) + (float)(*(float *)&v35 * vm->m[2][2]))
      + (float)(*((float *)&v35 + 1) * vm->m[3][2]);
  v21 = (float)((float)((float)(v13 * vm->m[0][3]) + (float)(v30 * vm->m[1][3])) + (float)(*(float *)&v35 * vm->m[2][3]))
      + (float)(*((float *)&v35 + 1) * vm->m[3][3]);
  v14 = this->m[3][0];
  v36 = *(_QWORD *)&this->m[3][2];
  v31 = this->m[3][1];
  v20 = (float)((float)((float)(v14 * vm->m[0][0]) + (float)(v31 * v10)) + (float)(*(float *)&v36 * v33))
      + (float)(*((float *)&v36 + 1) * v32);
  v19 = (float)((float)((float)(v14 * vm->m[0][1]) + (float)(v31 * vm->m[1][1])) + (float)(*(float *)&v36 * vm->m[2][1]))
      + (float)(*((float *)&v36 + 1) * vm->m[3][1]);
  v15 = v14 * vm->m[0][2];
  v16 = v14 * vm->m[0][3];
  vma = (float)((float)(v15 + (float)(v31 * vm->m[1][2])) + (float)(*(float *)&v36 * vm->m[2][2]))
      + (float)(*((float *)&v36 + 1) * vm->m[3][2]);
  v17 = (float)((float)(v16 + (float)(v31 * vm->m[1][3])) + (float)(*(float *)&v36 * vm->m[2][3]))
      + (float)(*((float *)&v36 + 1) * vm->m[3][3]);
  v18 = (float)((float)((float)(v9 * this->m[0][0]) + (float)(v10 * this->m[0][1])) + (float)(v33 * this->m[0][2]))
      + (float)(v32 * this->m[0][3]);
  out->m[1][0] = v28;
  out->m[1][1] = v27;
  out->m[1][2] = v26;
  out->m[1][3] = v25;
  out->m[0][0] = v18;
  out->m[0][1] = v7;
  out->m[0][2] = v8;
  out->m[0][3] = v11;
  out->m[2][0] = v24;
  out->m[2][1] = v23;
  out->m[2][2] = v22;
  out->m[2][3] = v21;
  out->m[3][0] = v20;
  out->m[3][1] = v19;
  out->m[3][2] = vma;
  out->m[3][3] = v17;
}

//------------------------------------------------------------------------------
// Address: 0x10250C70
// Name: public: class VMatrix VMatrix::operator*(class VMatrix const __near &)const
// Source: json
//------------------------------------------------------------------------------
VMatrix *__thiscall VMatrix::operator*(VMatrix *this, VMatrix *result, const VMatrix *vm)
{
  int v3; // edx

  VMatrix::MatrixMul(this, vm, out: result);
  return (VMatrix *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x10250C90
// Name: void MatrixSetIdentity(class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixSetIdentity(VMatrix *dst)
{
  *(_QWORD *)&dst->m[0][0] = 1065353216;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = 0.0;
  *(_QWORD *)&dst->m[1][1] = 1065353216;
  dst->m[1][3] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[2][2] = 1065353216;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10250D00
// Name: void MatrixTranspose(class VMatrix const __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixTranspose(const VMatrix *src, VMatrix *dst)
{
  float v2; // xmm0_4
  float v3; // xmm0_4
  float v4; // xmm0_4
  float v5; // xmm0_4
  float v6; // xmm0_4
  float v7; // xmm0_4

  if ( src == dst )
  {
    v2 = dst->m[0][1];
    dst->m[0][1] = dst->m[1][0];
    dst->m[1][0] = v2;
    v3 = dst->m[0][2];
    dst->m[0][2] = dst->m[2][0];
    dst->m[2][0] = v3;
    v4 = dst->m[0][3];
    dst->m[0][3] = dst->m[3][0];
    dst->m[3][0] = v4;
    v5 = dst->m[1][2];
    dst->m[1][2] = dst->m[2][1];
    dst->m[2][1] = v5;
    v6 = dst->m[1][3];
    dst->m[1][3] = dst->m[3][1];
    dst->m[3][1] = v6;
    v7 = dst->m[2][3];
    dst->m[2][3] = dst->m[3][2];
    dst->m[3][2] = v7;
  }
  else
  {
    dst->m[0][0] = src->m[0][0];
    dst->m[0][1] = src->m[1][0];
    dst->m[0][2] = src->m[2][0];
    dst->m[0][3] = src->m[3][0];
    dst->m[1][0] = src->m[0][1];
    dst->m[1][1] = src->m[1][1];
    dst->m[1][2] = src->m[2][1];
    dst->m[1][3] = src->m[3][1];
    dst->m[2][0] = src->m[0][2];
    dst->m[2][1] = src->m[1][2];
    dst->m[2][2] = src->m[2][2];
    dst->m[2][3] = src->m[3][2];
    dst->m[3][0] = src->m[0][3];
    dst->m[3][1] = src->m[1][3];
    dst->m[3][2] = src->m[2][3];
    dst->m[3][3] = src->m[3][3];
  }
}

//------------------------------------------------------------------------------
// Address: 0x10250DD0
// Name: void MatrixCopy(class VMatrix const __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixCopy(const VMatrix *src, VMatrix *dst)
{
  if ( src != dst )
    *dst = *src;
}

//------------------------------------------------------------------------------
// Address: 0x10250DF0
// Name: void MatrixMultiply(class VMatrix const __near &,class VMatrix const __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixMultiply(const VMatrix *src1, const VMatrix *src2, VMatrix *dst)
{
  float *p_tmp1; // edx
  VMatrix *v4; // edi
  float *p_tmp2; // eax
  VMatrix tmp2; // [esp+Ch] [ebp-80h] BYREF
  VMatrix tmp1; // [esp+4Ch] [ebp-40h] BYREF

  p_tmp1 = (float *)&tmp1;
  if ( src1 != dst )
    p_tmp1 = (float *)src1;
  v4 = src2;
  p_tmp2 = (float *)&tmp2;
  if ( src2 != dst )
    p_tmp2 = (float *)src2;
  if ( src1 == dst && src1 != &tmp1 )
  {
    tmp1 = *src1;
    v4 = src2;
  }
  if ( v4 == dst && v4 != &tmp2 )
    tmp2 = *v4;
  dst->m[0][0] = (float)((float)((float)(p_tmp1[1] * p_tmp2[4]) + (float)(*p_tmp2 * *p_tmp1))
                       + (float)(p_tmp2[8] * p_tmp1[2]))
               + (float)(p_tmp2[12] * p_tmp1[3]);
  dst->m[0][1] = (float)((float)((float)(p_tmp1[1] * p_tmp2[5]) + (float)(*p_tmp1 * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[2]))
               + (float)(p_tmp2[13] * p_tmp1[3]);
  dst->m[0][2] = (float)((float)((float)(p_tmp1[1] * p_tmp2[6]) + (float)(*p_tmp1 * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[2]))
               + (float)(p_tmp2[14] * p_tmp1[3]);
  dst->m[0][3] = (float)((float)((float)(p_tmp1[1] * p_tmp2[7]) + (float)(*p_tmp1 * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[2]))
               + (float)(p_tmp2[15] * p_tmp1[3]);
  dst->m[1][0] = (float)((float)((float)(p_tmp1[5] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[4]))
                       + (float)(p_tmp2[8] * p_tmp1[6]))
               + (float)(p_tmp2[12] * p_tmp1[7]);
  dst->m[1][1] = (float)((float)((float)(p_tmp1[5] * p_tmp2[5]) + (float)(p_tmp1[4] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[6]))
               + (float)(p_tmp2[13] * p_tmp1[7]);
  dst->m[1][2] = (float)((float)((float)(p_tmp1[5] * p_tmp2[6]) + (float)(p_tmp1[4] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[6]))
               + (float)(p_tmp2[14] * p_tmp1[7]);
  dst->m[1][3] = (float)((float)((float)(p_tmp1[5] * p_tmp2[7]) + (float)(p_tmp1[4] * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[6]))
               + (float)(p_tmp1[7] * p_tmp2[15]);
  dst->m[2][0] = (float)((float)((float)(p_tmp1[9] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[8]))
                       + (float)(p_tmp2[8] * p_tmp1[10]))
               + (float)(p_tmp2[12] * p_tmp1[11]);
  dst->m[2][1] = (float)((float)((float)(p_tmp1[9] * p_tmp2[5]) + (float)(p_tmp1[8] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[10]))
               + (float)(p_tmp2[13] * p_tmp1[11]);
  dst->m[2][2] = (float)((float)((float)(p_tmp1[9] * p_tmp2[6]) + (float)(p_tmp1[8] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[10]))
               + (float)(p_tmp2[14] * p_tmp1[11]);
  dst->m[2][3] = (float)((float)((float)(p_tmp1[8] * p_tmp2[3]) + (float)(p_tmp1[9] * p_tmp2[7]))
                       + (float)(p_tmp2[11] * p_tmp1[10]))
               + (float)(p_tmp1[11] * p_tmp2[15]);
  dst->m[3][0] = (float)((float)((float)(p_tmp1[13] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[12]))
                       + (float)(p_tmp2[8] * p_tmp1[14]))
               + (float)(p_tmp2[12] * p_tmp1[15]);
  dst->m[3][1] = (float)((float)((float)(p_tmp1[13] * p_tmp2[5]) + (float)(p_tmp1[12] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[14]))
               + (float)(p_tmp2[13] * p_tmp1[15]);
  dst->m[3][2] = (float)((float)((float)(p_tmp1[13] * p_tmp2[6]) + (float)(p_tmp1[12] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[14]))
               + (float)(p_tmp2[14] * p_tmp1[15]);
  dst->m[3][3] = (float)((float)((float)(p_tmp1[13] * p_tmp2[7]) + (float)(p_tmp1[12] * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[14]))
               + (float)(p_tmp1[15] * p_tmp2[15]);
}

//------------------------------------------------------------------------------
// Address: 0x102511E0
// Name: void Vector4DMultiply(class VMatrix const __near &,class Vector4D const __near &,class Vector4D __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Vector4DMultiply(const VMatrix *src1, Vector4D *src2, Vector4D *dst)
{
  Vector4D *p_tmp; // eax
  Vector4D tmp; // [esp+0h] [ebp-10h] BYREF

  p_tmp = &tmp;
  if ( src2 == dst )
    tmp = *src2;
  else
    p_tmp = src2;
  dst->x = (float)((float)((float)(src1->m[0][1] * p_tmp->y) + (float)(p_tmp->x * src1->m[0][0]))
                 + (float)(src1->m[0][2] * p_tmp->z))
         + (float)(src1->m[0][3] * p_tmp->w);
  dst->y = (float)((float)((float)(src1->m[1][1] * p_tmp->y) + (float)(src1->m[1][0] * p_tmp->x))
                 + (float)(src1->m[1][2] * p_tmp->z))
         + (float)(src1->m[1][3] * p_tmp->w);
  dst->z = (float)((float)((float)(src1->m[2][1] * p_tmp->y) + (float)(src1->m[2][0] * p_tmp->x))
                 + (float)(src1->m[2][2] * p_tmp->z))
         + (float)(src1->m[2][3] * p_tmp->w);
  dst->w = (float)((float)((float)(src1->m[3][1] * p_tmp->y) + (float)(src1->m[3][0] * p_tmp->x))
                 + (float)(src1->m[3][2] * p_tmp->z))
         + (float)(src1->m[3][3] * p_tmp->w);
}

//------------------------------------------------------------------------------
// Address: 0x10251310
// Name: void MatrixBuildTranslation(class VMatrix __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildTranslation(VMatrix *dst, float x, float y, float z)
{
  *(_QWORD *)&dst->m[0][1] = 0;
  dst->m[1][0] = 0.0;
  dst->m[1][2] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[0][3] = x;
  dst->m[1][3] = y;
  dst->m[0][0] = 1.0;
  dst->m[1][1] = 1.0;
  dst->m[2][2] = 1.0;
  dst->m[3][3] = 1.0;
  dst->m[2][3] = z;
}

//------------------------------------------------------------------------------
// Address: 0x10251390
// Name: void MatrixBuildTranslation(class VMatrix __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildTranslation(VMatrix *dst, const Vector *translation)
{
  dst->m[0][3] = 0.0;
  dst->m[1][3] = 0.0;
  dst->m[2][3] = 0.0;
  *(_QWORD *)&dst->m[0][0] = 1065353216;
  dst->m[0][2] = 0.0;
  dst->m[1][0] = 0.0;
  *(_QWORD *)&dst->m[1][1] = 1065353216;
  *(_QWORD *)&dst->m[2][0] = 0;
  dst->m[2][2] = 1.0;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[3][3] = 1.0;
  dst->m[0][3] = translation->x;
  dst->m[1][3] = translation->y;
  dst->m[2][3] = translation->z;
}

//------------------------------------------------------------------------------
// Address: 0x10251460
// Name: void MatrixBuildRotateZ(class VMatrix __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildRotateZ(VMatrix *dst, float angleDegrees)
{
  long double fSin; // [esp+0h] [ebp-4h]
  long double fSina; // [esp+0h] [ebp-4h]
  float fSinb; // [esp+0h] [ebp-4h]
  float radians; // [esp+10h] [ebp+Ch]

  radians = angleDegrees * 0.0174532925199433;
  __libm_sse2_sin(x: fSin);
  *(float *)&fSina = radians;
  __libm_sse2_cos(x: fSina);
  dst->m[0][0] = radians;
  LODWORD(dst->m[0][1]) = LODWORD(fSinb) ^ _mask__NegFloat_;
  dst->m[1][1] = radians;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = fSinb;
  *(_QWORD *)&dst->m[1][2] = 0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[2][2] = 1065353216;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10251520
// Name: void MatrixBuildScale(class VMatrix __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildScale(VMatrix *dst, unsigned int x, unsigned int y, float z)
{
  *(_QWORD *)&dst->m[0][0] = x;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = 0.0;
  *(_QWORD *)&dst->m[1][1] = y;
  dst->m[1][3] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  dst->m[2][3] = 0.0;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[2][2] = z;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x102515A0
// Name: void MatrixBuildOrtho(class VMatrix __near &,double,double,double,double,double,double)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildOrtho(
        VMatrix *dst,
        long double left,
        long double top,
        long double right,
        long double bottom,
        long double zNear,
        long double zFar)
{
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm1_4
  long double v11; // xmm1_8

  v7 = 2.0 / (right - left);
  v8 = (left + right) / (left - right);
  dst->m[0][3] = v8;
  v9 = 2.0 / (bottom - top);
  dst->m[1][1] = v9;
  dst->m[0][0] = v7;
  v10 = (top + bottom) / (top - bottom);
  dst->m[1][3] = v10;
  v11 = 1.0 / (zNear - zFar);
  *(_QWORD *)&dst->m[0][1] = 0;
  dst->m[1][0] = 0.0;
  dst->m[1][2] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[2][2] = v11;
  dst->m[2][3] = v11 * zNear;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x102516A0
// Name: void MatrixBuildPerspectiveX(class VMatrix __near &,double,double,double,double)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildPerspectiveX(
        VMatrix *dst,
        long double flFovX,
        long double flAspect,
        long double flZNear,
        long double flZFar)
{
  float v5; // xmm0_4
  float v6; // xmm2_4
  double v7; // xmm0_8
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm1_4
  float v11; // xmm4_4
  double v12; // [esp+0h] [ebp-8h]

  __libm_sse2_tan(x: flZNear * 2.0);
  v5 = flFovX * 3.141592653589793 * 0.002777777777777778;
  v6 = v5 * v12;
  v7 = v6;
  v8 = v6 / flAspect;
  v9 = v12 / v8;
  dst->m[1][1] = v9;
  *(float *)&v7 = v12 / v7;
  v10 = flZNear * flZFar / (flZNear - flZFar);
  dst->m[0][0] = *(float *)&v7;
  dst->m[2][3] = v10;
  v11 = flZFar / (flZNear - flZFar);
  *(_QWORD *)&dst->m[0][1] = 0;
  dst->m[0][3] = 0.0;
  dst->m[1][0] = 0.0;
  *(_QWORD *)&dst->m[1][2] = 0;
  *(_QWORD *)&dst->m[2][0] = 0;
  dst->m[2][2] = v11;
  *(_QWORD *)&dst->m[3][0] = 0;
  *(_QWORD *)&dst->m[3][2] = 3212836864LL;
}

//------------------------------------------------------------------------------
// Address: 0x102517B0
// Name: void MatrixBuildPerspectiveOffCenterX(class VMatrix __near &,double,double,double,double,double,double,double,double)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildPerspectiveOffCenterX(
        VMatrix *dst,
        long double flFovX,
        long double flAspect,
        long double flZNear,
        long double flZFar,
        long double bottom,
        long double top,
        long double left,
        long double right)
{
  float v9; // xmm0_4
  float v10; // xmm0_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  long double v13; // xmm5_8
  float v14; // xmm1_4
  long double v15; // xmm6_8
  float v16; // xmm2_4
  float v17; // xmm0_4
  float v18; // xmm3_4
  float v19; // xmm1_4
  double v20; // [esp+0h] [ebp-8h]

  __libm_sse2_tan(x: flZNear * 2.0);
  v9 = flFovX * 3.141592653589793 * 0.002777777777777778;
  v10 = v9 * v20;
  v11 = (float)(v10 / flAspect) * 0.5;
  v12 = v10 * 0.5;
  v13 = v12 * left - (1.0 - left) * v12;
  v14 = v12 * right - (1.0 - right) * v12;
  v15 = v11 * bottom - (1.0 - bottom) * v11;
  *(float *)&v13 = v13;
  v16 = v11 * top - (1.0 - top) * v11;
  dst->m[0][2] = (float)(v14 + *(float *)&v13) / (float)(v14 - *(float *)&v13);
  *(float *)&v15 = v15;
  v17 = v20 / (float)(v14 - *(float *)&v13);
  dst->m[0][0] = v17;
  v18 = v20 / (float)(v16 - *(float *)&v15);
  dst->m[0][1] = 0.0;
  dst->m[0][3] = 0.0;
  dst->m[1][0] = 0.0;
  dst->m[1][1] = v18;
  dst->m[1][2] = (float)(v16 + *(float *)&v15) / (float)(v16 - *(float *)&v15);
  v19 = flZNear * flZFar / (flZNear - flZFar);
  dst->m[2][3] = v19;
  dst->m[1][3] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  dst->m[2][2] = flZFar / (flZNear - flZFar);
  *(_QWORD *)&dst->m[3][0] = 0;
  *(_QWORD *)&dst->m[3][2] = 3212836864LL;
}

} // namespace MaterialSystem

// ============================================================
// Overlay from shaderapidx9 (Missing functions)
// ============================================================
namespace shaderapidx9 {

//------------------------------------------------------------------------------
// Address: 0x100D1730
// Name: public: class VMatrix __near & VMatrix::operator=(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
VMatrix *__thiscall VMatrix::operator=(VMatrix *this, const VMatrix *mOther)
{
  *this = *mOther;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100D17A0
// Name: public: void VMatrix::SetupMatrixOrgAngles(class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VMatrix::SetupMatrixOrgAngles(VMatrix *this, const Vector *origin, const QAngle *vAngles)
{
  float v4; // xmm1_4
  float v5; // xmm1_4
  double z; // st7
  float v7; // [esp+8h] [ebp-18h]
  float cr; // [esp+Ch] [ebp-14h]
  float sr; // [esp+10h] [ebp-10h]
  float sy; // [esp+14h] [ebp-Ch]
  float cy; // [esp+18h] [ebp-8h]
  float cp; // [esp+1Ch] [ebp-4h]
  float vAnglesa; // [esp+2Ch] [ebp+Ch]

  v4 = vAngles->y * 0.017453292;
  cy = cos(v4);
  sy = sin(v4);
  v5 = vAngles->x * 0.017453292;
  cp = cos(v5);
  vAnglesa = sin(v5);
  v7 = vAngles->z * 0.017453292;
  cr = cos(v7);
  sr = sin(v7);
  this->m[0][0] = cp * cy;
  this->m[1][0] = cp * sy;
  LODWORD(this->m[2][0]) = LODWORD(vAnglesa) ^ _mask__NegFloat_;
  this->m[0][1] = (float)((float)(sr * vAnglesa) * cy) - (float)(cr * sy);
  this->m[1][1] = (float)((float)(sr * vAnglesa) * sy) + (float)(cr * cy);
  this->m[2][1] = sr * cp;
  this->m[1][2] = (float)((float)(cr * vAnglesa) * sy) - (float)(sr * cy);
  this->m[0][3] = 0.0;
  this->m[1][3] = 0.0;
  this->m[2][3] = 0.0;
  this->m[0][2] = (float)((float)(cr * vAnglesa) * cy) + (float)(sr * sy);
  this->m[2][2] = cr * cp;
  this->m[0][3] = origin->x;
  this->m[1][3] = origin->y;
  z = origin->z;
  this->m[3][0] = 0.0;
  this->m[2][3] = z;
  *(_QWORD *)&this->m[3][1] = 0;
  this->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x100D1930
// Name: void MatrixTranspose(class VMatrix const __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixTranspose(const VMatrix *src, VMatrix *dst)
{
  float v2; // xmm0_4
  float v3; // xmm0_4
  float v4; // xmm0_4
  float v5; // xmm0_4
  float v6; // xmm0_4
  float v7; // xmm0_4

  if ( src == dst )
  {
    v2 = dst->m[0][1];
    dst->m[0][1] = dst->m[1][0];
    dst->m[1][0] = v2;
    v3 = dst->m[0][2];
    dst->m[0][2] = dst->m[2][0];
    dst->m[2][0] = v3;
    v4 = dst->m[0][3];
    dst->m[0][3] = dst->m[3][0];
    dst->m[3][0] = v4;
    v5 = dst->m[1][2];
    dst->m[1][2] = dst->m[2][1];
    dst->m[2][1] = v5;
    v6 = dst->m[1][3];
    dst->m[1][3] = dst->m[3][1];
    dst->m[3][1] = v6;
    v7 = dst->m[2][3];
    dst->m[2][3] = dst->m[3][2];
    dst->m[3][2] = v7;
  }
  else
  {
    dst->m[0][0] = src->m[0][0];
    dst->m[0][1] = src->m[1][0];
    dst->m[0][2] = src->m[2][0];
    dst->m[0][3] = src->m[3][0];
    dst->m[1][0] = src->m[0][1];
    dst->m[1][1] = src->m[1][1];
    dst->m[1][2] = src->m[2][1];
    dst->m[1][3] = src->m[3][1];
    dst->m[2][0] = src->m[0][2];
    dst->m[2][1] = src->m[1][2];
    dst->m[2][2] = src->m[2][2];
    dst->m[2][3] = src->m[3][2];
    dst->m[3][0] = src->m[0][3];
    dst->m[3][1] = src->m[1][3];
    dst->m[3][2] = src->m[2][3];
    dst->m[3][3] = src->m[3][3];
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D1A00
// Name: bool MatrixInverseGeneral(class VMatrix const __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl MatrixInverseGeneral(const VMatrix *src, VMatrix *dst)
{
  int v3; // edx
  _DWORD *v4; // eax
  float *v5; // ecx
  int v6; // ebx
  int v7; // edx
  int i; // edi
  int v9; // ecx
  float v10; // xmm0_4
  int v11; // eax
  float v12; // xmm1_4
  float v13; // xmm1_4
  float v14; // xmm1_4
  float v15; // xmm1_4
  float v16; // xmm1_4
  int v17; // eax
  float v18; // xmm1_4
  float *v19; // eax
  float v20; // xmm0_4
  int j; // esi
  float *v22; // ecx
  float v23; // xmm0_4
  int k; // edx
  float *v26; // ecx
  float v27; // esi
  float v28; // ecx
  float mat[4][8]; // [esp+0h] [ebp-90h] BYREF
  int rowMap[4]; // [esp+80h] [ebp-10h] BYREF

  v3 = 0;
  v4 = &mat[0][5];
  do
  {
    *(v4 - 5) = LODWORD(src->m[0][0]);
    v5 = (float *)(v4 - 5);
    v5[1] = src->m[0][1];
    v5[2] = src->m[0][2];
    v5[3] = src->m[0][3];
    *(v4 - 1) = 0;
    *v4 = 0;
    v4[1] = 0;
    v4[2] = 0;
    rowMap[v3] = v3;
    v6 = (int)&v4[v3++ - 5] + 16 - (_DWORD)rowMap;
    src = (const VMatrix *)((char *)src + 16);
    v4 += 8;
    *(int *)((char *)rowMap + v6) = 1065353216;
  }
  while ( v3 < 4 );
  v7 = 0;
  for ( i = 4; i > 0; --i )
  {
    v9 = -1;
    v10 = 0.000001;
    v11 = v7;
    if ( i >= 4 )
    {
      do
      {
        v12 = fabs(mat[rowMap[v11]][v7]);
        if ( v12 > v10 )
        {
          v9 = v11;
          v10 = v12;
        }
        v13 = fabs(mat[rowMap[v11 + 1]][v7]);
        if ( v13 > v10 )
        {
          v9 = v11 + 1;
          v10 = v13;
        }
        v14 = fabs(mat[rowMap[v11 + 2]][v7]);
        if ( v14 > v10 )
        {
          v9 = v11 + 2;
          v10 = v14;
        }
        v15 = fabs(mat[rowMap[v11 + 3]][v7]);
        if ( v15 > v10 )
        {
          v9 = v11 + 3;
          v10 = v15;
        }
        v11 += 4;
      }
      while ( v11 < 1 );
    }
    for ( ; v11 < 4; ++v11 )
    {
      v16 = fabs(mat[rowMap[v11]][v7]);
      if ( v16 > v10 )
      {
        v9 = v11;
        v10 = v16;
      }
    }
    if ( v9 == -1 )
      return 0;
    v17 = rowMap[v9];
    rowMap[v9] = rowMap[v7];
    rowMap[v7] = v17;
    v17 *= 32;
    v18 = *(float *)((char *)mat[0] + v17);
    v19 = (float *)((char *)mat[0] + v17);
    v20 = 1.0 / v19[v7];
    *v19 = v18 * v20;
    v19[1] = v19[1] * v20;
    v19[2] = v19[2] * v20;
    v19[3] = v19[3] * v20;
    v19[4] = v19[4] * v20;
    v19[5] = v19[5] * v20;
    v19[6] = v19[6] * v20;
    v19[7] = v19[7] * v20;
    v19[v7] = 1.0;
    for ( j = 0; j < 4; ++j )
    {
      if ( j != v7 )
      {
        v22 = mat[rowMap[j]];
        v23 = -v22[v7];
        *v22 = (float)(*v19 * v23) + *v22;
        v22[1] = (float)(v19[1] * v23) + v22[1];
        v22[2] = (float)(v19[2] * v23) + v22[2];
        v22[3] = (float)(v19[3] * v23) + v22[3];
        v22[4] = (float)(v19[4] * v23) + v22[4];
        v22[5] = (float)(v19[5] * v23) + v22[5];
        v22[6] = (float)(v19[6] * v23) + v22[6];
        v22[7] = (float)(v19[7] * v23) + v22[7];
        v22[v7] = 0.0;
      }
    }
    ++v7;
  }
  for ( k = 0; k < 4; ++k )
  {
    v26 = &mat[rowMap[k]][4];
    dst->m[0][0] = *v26;
    dst->m[0][1] = v26[1];
    v27 = v26[2];
    v28 = v26[3];
    dst->m[0][2] = v27;
    dst->m[0][3] = v28;
    dst = (VMatrix *)((char *)dst + 16);
  }
  return 1;
}

} // namespace shaderapidx9

// ============================================================
// Overlay from dmxconvert (Missing functions)
// ============================================================
namespace dmxconvert {

//------------------------------------------------------------------------------
// Address: 0x0045DA40
// Name: public: class VMatrix __near & VMatrix::operator=(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
VMatrix *__thiscall VMatrix::operator=(VMatrix *this, const VMatrix *mOther)
{
  *this = *mOther;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0045DAB0
// Name: public: bool VMatrix::operator==(class VMatrix const __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall VMatrix::operator==(VMatrix *this, const VMatrix *src)
{
  unsigned int v3; // eax

  v3 = 64;
  while ( LODWORD(src->m[0][0]) == LODWORD(this->m[0][0]) )
  {
    v3 -= 4;
    this = (VMatrix *)((char *)this + 4);
    src = (const VMatrix *)((char *)src + 4);
    if ( v3 < 4 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0045DB20
// Name: void MatrixSetIdentity(class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixSetIdentity(VMatrix *dst)
{
  *(_QWORD *)&dst->m[0][0] = 1065353216;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = 0.0;
  *(_QWORD *)&dst->m[1][1] = 1065353216;
  dst->m[1][3] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[2][2] = 1065353216;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x0045DB90
// Name: void MatrixMultiply(class VMatrix const __near &,class VMatrix const __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixMultiply(VMatrix *src1, VMatrix *src2, VMatrix *dst)
{
  float *p_tmp1; // edx
  VMatrix *v4; // edi
  float *p_tmp2; // eax
  VMatrix tmp2; // [esp+Ch] [ebp-80h] BYREF
  VMatrix tmp1; // [esp+4Ch] [ebp-40h] BYREF

  p_tmp1 = (float *)&tmp1;
  if ( src1 != dst )
    p_tmp1 = (float *)src1;
  v4 = src2;
  p_tmp2 = (float *)&tmp2;
  if ( src2 != dst )
    p_tmp2 = (float *)src2;
  if ( src1 == dst && src1 != &tmp1 )
  {
    tmp1 = *src1;
    v4 = src2;
  }
  if ( v4 == dst && v4 != &tmp2 )
    tmp2 = *v4;
  dst->m[0][0] = (float)((float)((float)(p_tmp1[1] * p_tmp2[4]) + (float)(*p_tmp2 * *p_tmp1))
                       + (float)(p_tmp2[8] * p_tmp1[2]))
               + (float)(p_tmp2[12] * p_tmp1[3]);
  dst->m[0][1] = (float)((float)((float)(p_tmp1[1] * p_tmp2[5]) + (float)(*p_tmp1 * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[2]))
               + (float)(p_tmp2[13] * p_tmp1[3]);
  dst->m[0][2] = (float)((float)((float)(p_tmp1[1] * p_tmp2[6]) + (float)(*p_tmp1 * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[2]))
               + (float)(p_tmp2[14] * p_tmp1[3]);
  dst->m[0][3] = (float)((float)((float)(p_tmp1[1] * p_tmp2[7]) + (float)(*p_tmp1 * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[2]))
               + (float)(p_tmp2[15] * p_tmp1[3]);
  dst->m[1][0] = (float)((float)((float)(p_tmp1[5] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[4]))
                       + (float)(p_tmp2[8] * p_tmp1[6]))
               + (float)(p_tmp2[12] * p_tmp1[7]);
  dst->m[1][1] = (float)((float)((float)(p_tmp1[5] * p_tmp2[5]) + (float)(p_tmp1[4] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[6]))
               + (float)(p_tmp2[13] * p_tmp1[7]);
  dst->m[1][2] = (float)((float)((float)(p_tmp1[5] * p_tmp2[6]) + (float)(p_tmp1[4] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[6]))
               + (float)(p_tmp2[14] * p_tmp1[7]);
  dst->m[1][3] = (float)((float)((float)(p_tmp1[5] * p_tmp2[7]) + (float)(p_tmp1[4] * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[6]))
               + (float)(p_tmp1[7] * p_tmp2[15]);
  dst->m[2][0] = (float)((float)((float)(p_tmp1[9] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[8]))
                       + (float)(p_tmp2[8] * p_tmp1[10]))
               + (float)(p_tmp2[12] * p_tmp1[11]);
  dst->m[2][1] = (float)((float)((float)(p_tmp1[9] * p_tmp2[5]) + (float)(p_tmp1[8] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[10]))
               + (float)(p_tmp2[13] * p_tmp1[11]);
  dst->m[2][2] = (float)((float)((float)(p_tmp1[9] * p_tmp2[6]) + (float)(p_tmp1[8] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[10]))
               + (float)(p_tmp2[14] * p_tmp1[11]);
  dst->m[2][3] = (float)((float)((float)(p_tmp1[8] * p_tmp2[3]) + (float)(p_tmp1[9] * p_tmp2[7]))
                       + (float)(p_tmp2[11] * p_tmp1[10]))
               + (float)(p_tmp1[11] * p_tmp2[15]);
  dst->m[3][0] = (float)((float)((float)(p_tmp1[13] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[12]))
                       + (float)(p_tmp2[8] * p_tmp1[14]))
               + (float)(p_tmp2[12] * p_tmp1[15]);
  dst->m[3][1] = (float)((float)((float)(p_tmp1[13] * p_tmp2[5]) + (float)(p_tmp1[12] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[14]))
               + (float)(p_tmp2[13] * p_tmp1[15]);
  dst->m[3][2] = (float)((float)((float)(p_tmp1[13] * p_tmp2[6]) + (float)(p_tmp1[12] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[14]))
               + (float)(p_tmp2[14] * p_tmp1[15]);
  dst->m[3][3] = (float)((float)((float)(p_tmp1[13] * p_tmp2[7]) + (float)(p_tmp1[12] * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[14]))
               + (float)(p_tmp1[15] * p_tmp2[15]);
}

//------------------------------------------------------------------------------
// Address: 0x0045DF80
// Name: void MatrixBuildTranslation(class VMatrix __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildTranslation(VMatrix *dst, float x, float y, float z)
{
  *(_QWORD *)&dst->m[0][1] = 0;
  dst->m[1][0] = 0.0;
  dst->m[1][2] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[0][3] = x;
  dst->m[1][3] = y;
  dst->m[0][0] = 1.0;
  dst->m[1][1] = 1.0;
  dst->m[2][2] = 1.0;
  dst->m[3][3] = 1.0;
  dst->m[2][3] = z;
}

//------------------------------------------------------------------------------
// Address: 0x0045E000
// Name: void MatrixBuildRotateZ(class VMatrix __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildRotateZ(VMatrix *dst, float angleDegrees)
{
  long double fSin; // [esp+0h] [ebp-4h]
  long double fSina; // [esp+0h] [ebp-4h]
  float fSinb; // [esp+0h] [ebp-4h]
  float radians; // [esp+10h] [ebp+Ch]

  radians = angleDegrees * 0.0174532925199433;
  __libm_sse2_sin(x: fSin);
  *(float *)&fSina = radians;
  __libm_sse2_cos(x: fSina);
  dst->m[0][0] = radians;
  LODWORD(dst->m[0][1]) = LODWORD(fSinb) ^ _mask__NegFloat_;
  dst->m[1][1] = radians;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = fSinb;
  *(_QWORD *)&dst->m[1][2] = 0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[2][2] = 1065353216;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x0045E0C0
// Name: void MatrixBuildScale(class VMatrix __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildScale(VMatrix *dst, unsigned int x, unsigned int y, float z)
{
  *(_QWORD *)&dst->m[0][0] = x;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = 0.0;
  *(_QWORD *)&dst->m[1][1] = y;
  dst->m[1][3] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  dst->m[2][3] = 0.0;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[2][2] = z;
  dst->m[3][3] = 1.0;
}

} // namespace dmxconvert

// ============================================================
// Overlay from dmxedit (Missing functions)
// ============================================================
namespace dmxedit {

//------------------------------------------------------------------------------
// Address: 0x0048FE40
// Name: public: class VMatrix __near & VMatrix::operator=(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
VMatrix *__thiscall VMatrix::operator=(VMatrix *this, const VMatrix *mOther)
{
  *this = *mOther;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0048FEB0
// Name: public: bool VMatrix::operator==(class VMatrix const __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall VMatrix::operator==(VMatrix *this, const VMatrix *src)
{
  unsigned int v3; // eax

  v3 = 64;
  while ( LODWORD(src->m[0][0]) == LODWORD(this->m[0][0]) )
  {
    v3 -= 4;
    this = (VMatrix *)((char *)this + 4);
    src = (const VMatrix *)((char *)src + 4);
    if ( v3 < 4 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0048FF20
// Name: void MatrixSetIdentity(class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixSetIdentity(VMatrix *dst)
{
  *(_QWORD *)&dst->m[0][0] = 1065353216;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = 0.0;
  *(_QWORD *)&dst->m[1][1] = 1065353216;
  dst->m[1][3] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[2][2] = 1065353216;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x0048FF90
// Name: void MatrixTranspose(class VMatrix const __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixTranspose(const VMatrix *src, VMatrix *dst)
{
  float v2; // xmm0_4
  float v3; // xmm0_4
  float v4; // xmm0_4
  float v5; // xmm0_4
  float v6; // xmm0_4
  float v7; // xmm0_4

  if ( src == dst )
  {
    v2 = dst->m[0][1];
    dst->m[0][1] = dst->m[1][0];
    dst->m[1][0] = v2;
    v3 = dst->m[0][2];
    dst->m[0][2] = dst->m[2][0];
    dst->m[2][0] = v3;
    v4 = dst->m[0][3];
    dst->m[0][3] = dst->m[3][0];
    dst->m[3][0] = v4;
    v5 = dst->m[1][2];
    dst->m[1][2] = dst->m[2][1];
    dst->m[2][1] = v5;
    v6 = dst->m[1][3];
    dst->m[1][3] = dst->m[3][1];
    dst->m[3][1] = v6;
    v7 = dst->m[2][3];
    dst->m[2][3] = dst->m[3][2];
    dst->m[3][2] = v7;
  }
  else
  {
    dst->m[0][0] = src->m[0][0];
    dst->m[0][1] = src->m[1][0];
    dst->m[0][2] = src->m[2][0];
    dst->m[0][3] = src->m[3][0];
    dst->m[1][0] = src->m[0][1];
    dst->m[1][1] = src->m[1][1];
    dst->m[1][2] = src->m[2][1];
    dst->m[1][3] = src->m[3][1];
    dst->m[2][0] = src->m[0][2];
    dst->m[2][1] = src->m[1][2];
    dst->m[2][2] = src->m[2][2];
    dst->m[2][3] = src->m[3][2];
    dst->m[3][0] = src->m[0][3];
    dst->m[3][1] = src->m[1][3];
    dst->m[3][2] = src->m[2][3];
    dst->m[3][3] = src->m[3][3];
  }
}

//------------------------------------------------------------------------------
// Address: 0x00490060
// Name: void MatrixMultiply(class VMatrix const __near &,class VMatrix const __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixMultiply(VMatrix *src1, VMatrix *src2, VMatrix *dst)
{
  float *p_tmp1; // edx
  VMatrix *v4; // edi
  float *p_tmp2; // eax
  VMatrix tmp2; // [esp+Ch] [ebp-80h] BYREF
  VMatrix tmp1; // [esp+4Ch] [ebp-40h] BYREF

  p_tmp1 = (float *)&tmp1;
  if ( src1 != dst )
    p_tmp1 = (float *)src1;
  v4 = src2;
  p_tmp2 = (float *)&tmp2;
  if ( src2 != dst )
    p_tmp2 = (float *)src2;
  if ( src1 == dst && src1 != &tmp1 )
  {
    tmp1 = *src1;
    v4 = src2;
  }
  if ( v4 == dst && v4 != &tmp2 )
    tmp2 = *v4;
  dst->m[0][0] = (float)((float)((float)(p_tmp1[1] * p_tmp2[4]) + (float)(*p_tmp2 * *p_tmp1))
                       + (float)(p_tmp2[8] * p_tmp1[2]))
               + (float)(p_tmp2[12] * p_tmp1[3]);
  dst->m[0][1] = (float)((float)((float)(p_tmp1[1] * p_tmp2[5]) + (float)(*p_tmp1 * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[2]))
               + (float)(p_tmp2[13] * p_tmp1[3]);
  dst->m[0][2] = (float)((float)((float)(p_tmp1[1] * p_tmp2[6]) + (float)(*p_tmp1 * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[2]))
               + (float)(p_tmp2[14] * p_tmp1[3]);
  dst->m[0][3] = (float)((float)((float)(p_tmp1[1] * p_tmp2[7]) + (float)(*p_tmp1 * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[2]))
               + (float)(p_tmp2[15] * p_tmp1[3]);
  dst->m[1][0] = (float)((float)((float)(p_tmp1[5] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[4]))
                       + (float)(p_tmp2[8] * p_tmp1[6]))
               + (float)(p_tmp2[12] * p_tmp1[7]);
  dst->m[1][1] = (float)((float)((float)(p_tmp1[5] * p_tmp2[5]) + (float)(p_tmp1[4] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[6]))
               + (float)(p_tmp2[13] * p_tmp1[7]);
  dst->m[1][2] = (float)((float)((float)(p_tmp1[5] * p_tmp2[6]) + (float)(p_tmp1[4] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[6]))
               + (float)(p_tmp2[14] * p_tmp1[7]);
  dst->m[1][3] = (float)((float)((float)(p_tmp1[5] * p_tmp2[7]) + (float)(p_tmp1[4] * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[6]))
               + (float)(p_tmp1[7] * p_tmp2[15]);
  dst->m[2][0] = (float)((float)((float)(p_tmp1[9] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[8]))
                       + (float)(p_tmp2[8] * p_tmp1[10]))
               + (float)(p_tmp2[12] * p_tmp1[11]);
  dst->m[2][1] = (float)((float)((float)(p_tmp1[9] * p_tmp2[5]) + (float)(p_tmp1[8] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[10]))
               + (float)(p_tmp2[13] * p_tmp1[11]);
  dst->m[2][2] = (float)((float)((float)(p_tmp1[9] * p_tmp2[6]) + (float)(p_tmp1[8] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[10]))
               + (float)(p_tmp2[14] * p_tmp1[11]);
  dst->m[2][3] = (float)((float)((float)(p_tmp1[8] * p_tmp2[3]) + (float)(p_tmp1[9] * p_tmp2[7]))
                       + (float)(p_tmp2[11] * p_tmp1[10]))
               + (float)(p_tmp1[11] * p_tmp2[15]);
  dst->m[3][0] = (float)((float)((float)(p_tmp1[13] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[12]))
                       + (float)(p_tmp2[8] * p_tmp1[14]))
               + (float)(p_tmp2[12] * p_tmp1[15]);
  dst->m[3][1] = (float)((float)((float)(p_tmp1[13] * p_tmp2[5]) + (float)(p_tmp1[12] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[14]))
               + (float)(p_tmp2[13] * p_tmp1[15]);
  dst->m[3][2] = (float)((float)((float)(p_tmp1[13] * p_tmp2[6]) + (float)(p_tmp1[12] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[14]))
               + (float)(p_tmp2[14] * p_tmp1[15]);
  dst->m[3][3] = (float)((float)((float)(p_tmp1[13] * p_tmp2[7]) + (float)(p_tmp1[12] * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[14]))
               + (float)(p_tmp1[15] * p_tmp2[15]);
}

//------------------------------------------------------------------------------
// Address: 0x00490450
// Name: void MatrixBuildTranslation(class VMatrix __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildTranslation(VMatrix *dst, float x, float y, float z)
{
  *(_QWORD *)&dst->m[0][1] = 0;
  dst->m[1][0] = 0.0;
  dst->m[1][2] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[0][3] = x;
  dst->m[1][3] = y;
  dst->m[0][0] = 1.0;
  dst->m[1][1] = 1.0;
  dst->m[2][2] = 1.0;
  dst->m[3][3] = 1.0;
  dst->m[2][3] = z;
}

//------------------------------------------------------------------------------
// Address: 0x00490520
// Name: void MatrixBuildRotateZ(class VMatrix __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildRotateZ(VMatrix *dst, float angleDegrees)
{
  long double fSin; // [esp+0h] [ebp-4h]
  long double fSina; // [esp+0h] [ebp-4h]
  float fSinb; // [esp+0h] [ebp-4h]
  float radians; // [esp+10h] [ebp+Ch]

  radians = angleDegrees * 0.0174532925199433;
  __libm_sse2_sin(x: fSin);
  *(float *)&fSina = radians;
  __libm_sse2_cos(x: fSina);
  dst->m[0][0] = radians;
  LODWORD(dst->m[0][1]) = LODWORD(fSinb) ^ _mask__NegFloat_;
  dst->m[1][1] = radians;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = fSinb;
  *(_QWORD *)&dst->m[1][2] = 0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[2][2] = 1065353216;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x004905E0
// Name: void MatrixBuildScale(class VMatrix __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildScale(VMatrix *dst, unsigned int x, unsigned int y, float z)
{
  *(_QWORD *)&dst->m[0][0] = x;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = 0.0;
  *(_QWORD *)&dst->m[1][1] = y;
  dst->m[1][3] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  dst->m[2][3] = 0.0;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[2][2] = z;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x00490660
// Name: bool MatrixInverseGeneral(class VMatrix const __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl MatrixInverseGeneral(const VMatrix *src, VMatrix *dst)
{
  int v3; // edx
  _DWORD *v4; // eax
  float *v5; // ecx
  int v6; // ebx
  int v7; // edx
  int i; // edi
  int v9; // ecx
  float v10; // xmm0_4
  int v11; // eax
  float v12; // xmm1_4
  float v13; // xmm1_4
  float v14; // xmm1_4
  float v15; // xmm1_4
  float v16; // xmm1_4
  int v17; // eax
  float v18; // xmm1_4
  float *v19; // eax
  float v20; // xmm0_4
  int j; // esi
  float *v22; // ecx
  float v23; // xmm0_4
  int k; // edx
  float *v26; // ecx
  float v27; // esi
  float v28; // ecx
  float mat[4][8]; // [esp+0h] [ebp-90h] BYREF
  int rowMap[4]; // [esp+80h] [ebp-10h] BYREF

  v3 = 0;
  v4 = &mat[0][5];
  do
  {
    *(v4 - 5) = LODWORD(src->m[0][0]);
    v5 = (float *)(v4 - 5);
    v5[1] = src->m[0][1];
    v5[2] = src->m[0][2];
    v5[3] = src->m[0][3];
    *(v4 - 1) = 0;
    *v4 = 0;
    v4[1] = 0;
    v4[2] = 0;
    rowMap[v3] = v3;
    v6 = (int)&v4[v3++ - 5] + 16 - (_DWORD)rowMap;
    src = (const VMatrix *)((char *)src + 16);
    v4 += 8;
    *(int *)((char *)rowMap + v6) = 1065353216;
  }
  while ( v3 < 4 );
  v7 = 0;
  for ( i = 4; i > 0; --i )
  {
    v9 = -1;
    v10 = 0.000001;
    v11 = v7;
    if ( i >= 4 )
    {
      do
      {
        v12 = fabs(mat[rowMap[v11]][v7]);
        if ( v12 > v10 )
        {
          v9 = v11;
          v10 = v12;
        }
        v13 = fabs(mat[rowMap[v11 + 1]][v7]);
        if ( v13 > v10 )
        {
          v9 = v11 + 1;
          v10 = v13;
        }
        v14 = fabs(mat[rowMap[v11 + 2]][v7]);
        if ( v14 > v10 )
        {
          v9 = v11 + 2;
          v10 = v14;
        }
        v15 = fabs(mat[rowMap[v11 + 3]][v7]);
        if ( v15 > v10 )
        {
          v9 = v11 + 3;
          v10 = v15;
        }
        v11 += 4;
      }
      while ( v11 < 1 );
    }
    for ( ; v11 < 4; ++v11 )
    {
      v16 = fabs(mat[rowMap[v11]][v7]);
      if ( v16 > v10 )
      {
        v9 = v11;
        v10 = v16;
      }
    }
    if ( v9 == -1 )
      return 0;
    v17 = rowMap[v9];
    rowMap[v9] = rowMap[v7];
    rowMap[v7] = v17;
    v17 *= 32;
    v18 = *(float *)((char *)mat[0] + v17);
    v19 = (float *)((char *)mat[0] + v17);
    v20 = 1.0 / v19[v7];
    *v19 = v18 * v20;
    v19[1] = v19[1] * v20;
    v19[2] = v19[2] * v20;
    v19[3] = v19[3] * v20;
    v19[4] = v19[4] * v20;
    v19[5] = v19[5] * v20;
    v19[6] = v19[6] * v20;
    v19[7] = v19[7] * v20;
    v19[v7] = 1.0;
    for ( j = 0; j < 4; ++j )
    {
      if ( j != v7 )
      {
        v22 = mat[rowMap[j]];
        v23 = -v22[v7];
        *v22 = (float)(*v19 * v23) + *v22;
        v22[1] = (float)(v19[1] * v23) + v22[1];
        v22[2] = (float)(v19[2] * v23) + v22[2];
        v22[3] = (float)(v19[3] * v23) + v22[3];
        v22[4] = (float)(v19[4] * v23) + v22[4];
        v22[5] = (float)(v19[5] * v23) + v22[5];
        v22[6] = (float)(v19[6] * v23) + v22[6];
        v22[7] = (float)(v19[7] * v23) + v22[7];
        v22[v7] = 0.0;
      }
    }
    ++v7;
  }
  for ( k = 0; k < 4; ++k )
  {
    v26 = &mat[rowMap[k]][4];
    dst->m[0][0] = *v26;
    dst->m[0][1] = v26[1];
    v27 = v26[2];
    v28 = v26[3];
    dst->m[0][2] = v27;
    dst->m[0][3] = v28;
    dst = (VMatrix *)((char *)dst + 16);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00490980
// Name: void MatrixInverseTranspose(struct matrix3x4_t const __near &,struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixInverseTranspose(const matrix3x4_t *src, matrix3x4_t *dst)
{
  VMatrix out; // [esp+0h] [ebp-80h] BYREF
  VMatrix tmp; // [esp+40h] [ebp-40h] BYREF

  *(matrix3x4_t *)&tmp.m[0][0] = *src;
  memset(tmp.m[3], 0, 12);
  tmp.m[3][3] = 1.0;
  MatrixInverseGeneral(src: &tmp, dst: &out);
  MatrixTranspose(src: &out, dst: &out);
  *dst = *(matrix3x4_t *)&out.m[0][0];
}

} // namespace dmxedit

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x004B4E90
// Name: public: class VMatrix __near & VMatrix::operator=(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
VMatrix *__thiscall VMatrix::operator=(VMatrix *this, const VMatrix *mOther)
{
  *this = *mOther;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004B4F00
// Name: public: bool VMatrix::operator==(class VMatrix const __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall VMatrix::operator==(VMatrix *this, const VMatrix *src)
{
  unsigned int v3; // eax

  v3 = 64;
  while ( LODWORD(src->m[0][0]) == LODWORD(this->m[0][0]) )
  {
    v3 -= 4;
    this = (VMatrix *)((char *)this + 4);
    src = (const VMatrix *)((char *)src + 4);
    if ( v3 < 4 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004B4F70
// Name: void MatrixSetIdentity(class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixSetIdentity(VMatrix *dst)
{
  *(_QWORD *)&dst->m[0][0] = 1065353216;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = 0.0;
  *(_QWORD *)&dst->m[1][1] = 1065353216;
  dst->m[1][3] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[2][2] = 1065353216;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x004B4FE0
// Name: void MatrixMultiply(class VMatrix const __near &,class VMatrix const __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixMultiply(VMatrix *src1, VMatrix *src2, VMatrix *dst)
{
  float *p_tmp1; // edx
  VMatrix *v4; // edi
  float *p_tmp2; // eax
  VMatrix tmp2; // [esp+Ch] [ebp-80h] BYREF
  VMatrix tmp1; // [esp+4Ch] [ebp-40h] BYREF

  p_tmp1 = (float *)&tmp1;
  if ( src1 != dst )
    p_tmp1 = (float *)src1;
  v4 = src2;
  p_tmp2 = (float *)&tmp2;
  if ( src2 != dst )
    p_tmp2 = (float *)src2;
  if ( src1 == dst && src1 != &tmp1 )
  {
    tmp1 = *src1;
    v4 = src2;
  }
  if ( v4 == dst && v4 != &tmp2 )
    tmp2 = *v4;
  dst->m[0][0] = (float)((float)((float)(p_tmp1[1] * p_tmp2[4]) + (float)(*p_tmp2 * *p_tmp1))
                       + (float)(p_tmp2[8] * p_tmp1[2]))
               + (float)(p_tmp2[12] * p_tmp1[3]);
  dst->m[0][1] = (float)((float)((float)(p_tmp1[1] * p_tmp2[5]) + (float)(*p_tmp1 * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[2]))
               + (float)(p_tmp2[13] * p_tmp1[3]);
  dst->m[0][2] = (float)((float)((float)(p_tmp1[1] * p_tmp2[6]) + (float)(*p_tmp1 * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[2]))
               + (float)(p_tmp2[14] * p_tmp1[3]);
  dst->m[0][3] = (float)((float)((float)(p_tmp1[1] * p_tmp2[7]) + (float)(*p_tmp1 * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[2]))
               + (float)(p_tmp2[15] * p_tmp1[3]);
  dst->m[1][0] = (float)((float)((float)(p_tmp1[5] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[4]))
                       + (float)(p_tmp2[8] * p_tmp1[6]))
               + (float)(p_tmp2[12] * p_tmp1[7]);
  dst->m[1][1] = (float)((float)((float)(p_tmp1[5] * p_tmp2[5]) + (float)(p_tmp1[4] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[6]))
               + (float)(p_tmp2[13] * p_tmp1[7]);
  dst->m[1][2] = (float)((float)((float)(p_tmp1[5] * p_tmp2[6]) + (float)(p_tmp1[4] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[6]))
               + (float)(p_tmp2[14] * p_tmp1[7]);
  dst->m[1][3] = (float)((float)((float)(p_tmp1[5] * p_tmp2[7]) + (float)(p_tmp1[4] * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[6]))
               + (float)(p_tmp1[7] * p_tmp2[15]);
  dst->m[2][0] = (float)((float)((float)(p_tmp1[9] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[8]))
                       + (float)(p_tmp2[8] * p_tmp1[10]))
               + (float)(p_tmp2[12] * p_tmp1[11]);
  dst->m[2][1] = (float)((float)((float)(p_tmp1[9] * p_tmp2[5]) + (float)(p_tmp1[8] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[10]))
               + (float)(p_tmp2[13] * p_tmp1[11]);
  dst->m[2][2] = (float)((float)((float)(p_tmp1[9] * p_tmp2[6]) + (float)(p_tmp1[8] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[10]))
               + (float)(p_tmp2[14] * p_tmp1[11]);
  dst->m[2][3] = (float)((float)((float)(p_tmp1[8] * p_tmp2[3]) + (float)(p_tmp1[9] * p_tmp2[7]))
                       + (float)(p_tmp2[11] * p_tmp1[10]))
               + (float)(p_tmp1[11] * p_tmp2[15]);
  dst->m[3][0] = (float)((float)((float)(p_tmp1[13] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[12]))
                       + (float)(p_tmp2[8] * p_tmp1[14]))
               + (float)(p_tmp2[12] * p_tmp1[15]);
  dst->m[3][1] = (float)((float)((float)(p_tmp1[13] * p_tmp2[5]) + (float)(p_tmp1[12] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[14]))
               + (float)(p_tmp2[13] * p_tmp1[15]);
  dst->m[3][2] = (float)((float)((float)(p_tmp1[13] * p_tmp2[6]) + (float)(p_tmp1[12] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[14]))
               + (float)(p_tmp2[14] * p_tmp1[15]);
  dst->m[3][3] = (float)((float)((float)(p_tmp1[13] * p_tmp2[7]) + (float)(p_tmp1[12] * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[14]))
               + (float)(p_tmp1[15] * p_tmp2[15]);
}

//------------------------------------------------------------------------------
// Address: 0x004B53D0
// Name: void Vector3DMultiply(class VMatrix const __near &,class Vector const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Vector3DMultiply(const VMatrix *src1, Vector *src2, Vector *dst)
{
  Vector *p_tmp; // eax
  __int64 v4; // xmm0_8
  float z; // edx
  float v6; // xmm3_4
  float v7; // xmm2_4
  float v8; // xmm4_4
  Vector tmp; // [esp+0h] [ebp-18h] BYREF
  __int64 v10; // [esp+Ch] [ebp-Ch]
  float v11; // [esp+14h] [ebp-4h]

  p_tmp = src2;
  if ( src2 == dst )
    p_tmp = &tmp;
  v4 = *(_QWORD *)&p_tmp->x;
  z = p_tmp->z;
  v6 = src1->m[0][1];
  v7 = src1->m[0][0];
  v8 = src1->m[0][2];
  v10 = v4;
  v11 = z;
  dst->x = (float)((float)(v6 * *((float *)&v4 + 1)) + (float)(v7 * *(float *)&v4)) + (float)(v8 * z);
  dst->y = (float)((float)(src1->m[1][0] * *(float *)&v4) + (float)(src1->m[1][1] * *((float *)&v4 + 1)))
         + (float)(src1->m[1][2] * z);
  dst->z = (float)((float)(src1->m[2][0] * *(float *)&v4) + (float)(src1->m[2][1] * *((float *)&v4 + 1)))
         + (float)(src1->m[2][2] * z);
}

//------------------------------------------------------------------------------
// Address: 0x004B5490
// Name: void Vector3DMultiplyPositionProjective(class VMatrix const __near &,class Vector const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Vector3DMultiplyPositionProjective(const VMatrix *src1, Vector *src2, Vector *dst)
{
  Vector *p_tmp; // eax
  float z; // ecx
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm0_4
  float v8; // xmm4_4
  Vector tmp; // [esp+0h] [ebp-18h] BYREF
  __int64 v10; // [esp+Ch] [ebp-Ch]
  float v11; // [esp+14h] [ebp-4h]

  p_tmp = src2;
  if ( src2 == dst )
    p_tmp = &tmp;
  z = p_tmp->z;
  v10 = *(_QWORD *)&p_tmp->x;
  v5 = *(float *)&v10;
  v6 = *((float *)&v10 + 1);
  v11 = z;
  v7 = (float)((float)((float)(src1->m[3][0] * *(float *)&v10) + (float)(src1->m[3][1] * *((float *)&v10 + 1)))
             + (float)(src1->m[3][2] * z))
     + src1->m[3][3];
  if ( v7 != 0.0 )
    v7 = 1.0 / v7;
  dst->x = (float)((float)((float)(src1->m[0][1] * *((float *)&v10 + 1)) + (float)(src1->m[0][0] * *(float *)&v10))
                 + (float)(src1->m[0][2] * v11))
         + src1->m[0][3];
  dst->y = (float)((float)((float)(src1->m[1][0] * v5) + (float)(src1->m[1][1] * v6)) + (float)(src1->m[1][2] * z))
         + src1->m[1][3];
  v8 = (float)((float)((float)(src1->m[2][0] * v5) + (float)(src1->m[2][1] * v6)) + (float)(src1->m[2][2] * z))
     + src1->m[2][3];
  dst->x = dst->x * v7;
  dst->y = dst->y * v7;
  dst->z = v8 * v7;
}

//------------------------------------------------------------------------------
// Address: 0x004B55D0
// Name: void MatrixBuildTranslation(class VMatrix __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildTranslation(VMatrix *dst, float x, float y, float z)
{
  *(_QWORD *)&dst->m[0][1] = 0;
  dst->m[1][0] = 0.0;
  dst->m[1][2] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[0][3] = x;
  dst->m[1][3] = y;
  dst->m[0][0] = 1.0;
  dst->m[1][1] = 1.0;
  dst->m[2][2] = 1.0;
  dst->m[3][3] = 1.0;
  dst->m[2][3] = z;
}

//------------------------------------------------------------------------------
// Address: 0x004B56A0
// Name: void MatrixBuildRotateZ(class VMatrix __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildRotateZ(VMatrix *dst, float angleDegrees)
{
  double v2; // xmm0_8
  float v3; // xmm1_4
  long double fSin; // [esp+0h] [ebp-4h]
  unsigned int radians; // [esp+10h] [ebp+Ch]

  *(float *)&radians = angleDegrees * 0.0174532925199433;
  __libm_sse2_sin(x: fSin);
  __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)radians));
  v3 = v2;
  dst->m[0][0] = v3;
  LODWORD(dst->m[0][1]) = radians ^ _mask__NegFloat_;
  dst->m[1][1] = v3;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = *(float *)&radians;
  *(_QWORD *)&dst->m[1][2] = 0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[2][2] = 1065353216;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x004B5760
// Name: void MatrixBuildScale(class VMatrix __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildScale(VMatrix *dst, unsigned int x, unsigned int y, float z)
{
  *(_QWORD *)&dst->m[0][0] = x;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = 0.0;
  *(_QWORD *)&dst->m[1][1] = y;
  dst->m[1][3] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  dst->m[2][3] = 0.0;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[2][2] = z;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x004B57E0
// Name: void MatrixInverseTR(class VMatrix const __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixInverseTR(const VMatrix *src, VMatrix *dst)
{
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm4_4
  float v8; // xmm5_4
  float v9; // xmm1_4
  float v10; // xmm0_4

  dst->m[0][0] = src->m[0][0];
  dst->m[0][1] = src->m[1][0];
  dst->m[0][2] = src->m[2][0];
  dst->m[1][0] = src->m[0][1];
  dst->m[1][1] = src->m[1][1];
  dst->m[1][2] = src->m[2][1];
  dst->m[2][0] = src->m[0][2];
  dst->m[2][1] = src->m[1][2];
  dst->m[2][2] = src->m[2][2];
  v3 = -src->m[0][3];
  v4 = -src->m[1][3];
  v5 = -src->m[2][3];
  v6 = (float)((float)(dst->m[0][0] * v3) + (float)(v4 * dst->m[0][1])) + (float)(dst->m[0][2] * v5);
  v7 = (float)((float)(dst->m[1][1] * v4) + (float)(dst->m[1][0] * v3)) + (float)(v5 * dst->m[1][2]);
  v8 = dst->m[2][1] * v4;
  v9 = dst->m[2][0] * v3;
  v10 = dst->m[2][2] * v5;
  dst->m[0][3] = v6;
  dst->m[1][3] = v7;
  dst->m[2][3] = (float)(v8 + v9) + v10;
  *(_QWORD *)&dst->m[3][1] = 0;
  dst->m[3][0] = 0.0;
  dst->m[3][3] = 1.0;
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1025F3E0
// Name: public: class VMatrix __near & VMatrix::operator=(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
VMatrix *__thiscall VMatrix::operator=(VMatrix *this, const VMatrix *mOther)
{
  *this = *mOther;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1025F450
// Name: public: void VMatrix::SetupMatrixOrgAngles(class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VMatrix::SetupMatrixOrgAngles(VMatrix *this, const Vector *origin, const QAngle *vAngles)
{
  float v4; // xmm1_4
  float v5; // xmm1_4
  double z; // st7
  float v7; // [esp+8h] [ebp-18h]
  float cr; // [esp+Ch] [ebp-14h]
  float sr; // [esp+10h] [ebp-10h]
  float sy; // [esp+14h] [ebp-Ch]
  float cy; // [esp+18h] [ebp-8h]
  float cp; // [esp+1Ch] [ebp-4h]
  float vAnglesa; // [esp+2Ch] [ebp+Ch]

  v4 = vAngles->y * 0.017453292;
  cy = cos(v4);
  sy = sin(v4);
  v5 = vAngles->x * 0.017453292;
  cp = cos(v5);
  vAnglesa = sin(v5);
  v7 = vAngles->z * 0.017453292;
  cr = cos(v7);
  sr = sin(v7);
  this->m[0][0] = cp * cy;
  this->m[1][0] = cp * sy;
  LODWORD(this->m[2][0]) = LODWORD(vAnglesa) ^ _mask__NegFloat_;
  this->m[0][1] = (float)((float)(sr * vAnglesa) * cy) - (float)(cr * sy);
  this->m[1][1] = (float)((float)(sr * vAnglesa) * sy) + (float)(cr * cy);
  this->m[2][1] = sr * cp;
  this->m[1][2] = (float)((float)(cr * vAnglesa) * sy) - (float)(sr * cy);
  this->m[0][3] = 0.0;
  this->m[1][3] = 0.0;
  this->m[2][3] = 0.0;
  this->m[0][2] = (float)((float)(cr * vAnglesa) * cy) + (float)(sr * sy);
  this->m[2][2] = cr * cp;
  this->m[0][3] = origin->x;
  this->m[1][3] = origin->y;
  z = origin->z;
  this->m[3][0] = 0.0;
  this->m[2][3] = z;
  *(_QWORD *)&this->m[3][1] = 0;
  this->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x1025F5E0
// Name: void MatrixSetIdentity(class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixSetIdentity(VMatrix *dst)
{
  *(_QWORD *)&dst->m[0][0] = 1065353216;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = 0.0;
  *(_QWORD *)&dst->m[1][1] = 1065353216;
  dst->m[1][3] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[2][2] = 1065353216;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x1025F670
// Name: void MatrixMultiply(class VMatrix const __near &,class VMatrix const __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixMultiply(const VMatrix *src1, const VMatrix *src2, VMatrix *dst)
{
  float *p_tmp1; // edx
  VMatrix *v4; // edi
  float *p_tmp2; // eax
  VMatrix tmp2; // [esp+Ch] [ebp-80h] BYREF
  VMatrix tmp1; // [esp+4Ch] [ebp-40h] BYREF

  p_tmp1 = (float *)&tmp1;
  if ( src1 != dst )
    p_tmp1 = (float *)src1;
  v4 = src2;
  p_tmp2 = (float *)&tmp2;
  if ( src2 != dst )
    p_tmp2 = (float *)src2;
  if ( src1 == dst && src1 != &tmp1 )
  {
    tmp1 = *src1;
    v4 = src2;
  }
  if ( v4 == dst && v4 != &tmp2 )
    tmp2 = *v4;
  dst->m[0][0] = (float)((float)((float)(p_tmp1[1] * p_tmp2[4]) + (float)(*p_tmp2 * *p_tmp1))
                       + (float)(p_tmp2[8] * p_tmp1[2]))
               + (float)(p_tmp2[12] * p_tmp1[3]);
  dst->m[0][1] = (float)((float)((float)(p_tmp1[1] * p_tmp2[5]) + (float)(*p_tmp1 * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[2]))
               + (float)(p_tmp2[13] * p_tmp1[3]);
  dst->m[0][2] = (float)((float)((float)(p_tmp1[1] * p_tmp2[6]) + (float)(*p_tmp1 * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[2]))
               + (float)(p_tmp2[14] * p_tmp1[3]);
  dst->m[0][3] = (float)((float)((float)(p_tmp1[1] * p_tmp2[7]) + (float)(*p_tmp1 * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[2]))
               + (float)(p_tmp2[15] * p_tmp1[3]);
  dst->m[1][0] = (float)((float)((float)(p_tmp1[5] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[4]))
                       + (float)(p_tmp2[8] * p_tmp1[6]))
               + (float)(p_tmp2[12] * p_tmp1[7]);
  dst->m[1][1] = (float)((float)((float)(p_tmp1[5] * p_tmp2[5]) + (float)(p_tmp1[4] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[6]))
               + (float)(p_tmp2[13] * p_tmp1[7]);
  dst->m[1][2] = (float)((float)((float)(p_tmp1[5] * p_tmp2[6]) + (float)(p_tmp1[4] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[6]))
               + (float)(p_tmp2[14] * p_tmp1[7]);
  dst->m[1][3] = (float)((float)((float)(p_tmp1[5] * p_tmp2[7]) + (float)(p_tmp1[4] * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[6]))
               + (float)(p_tmp1[7] * p_tmp2[15]);
  dst->m[2][0] = (float)((float)((float)(p_tmp1[9] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[8]))
                       + (float)(p_tmp2[8] * p_tmp1[10]))
               + (float)(p_tmp2[12] * p_tmp1[11]);
  dst->m[2][1] = (float)((float)((float)(p_tmp1[9] * p_tmp2[5]) + (float)(p_tmp1[8] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[10]))
               + (float)(p_tmp2[13] * p_tmp1[11]);
  dst->m[2][2] = (float)((float)((float)(p_tmp1[9] * p_tmp2[6]) + (float)(p_tmp1[8] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[10]))
               + (float)(p_tmp2[14] * p_tmp1[11]);
  dst->m[2][3] = (float)((float)((float)(p_tmp1[8] * p_tmp2[3]) + (float)(p_tmp1[9] * p_tmp2[7]))
                       + (float)(p_tmp2[11] * p_tmp1[10]))
               + (float)(p_tmp1[11] * p_tmp2[15]);
  dst->m[3][0] = (float)((float)((float)(p_tmp1[13] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[12]))
                       + (float)(p_tmp2[8] * p_tmp1[14]))
               + (float)(p_tmp2[12] * p_tmp1[15]);
  dst->m[3][1] = (float)((float)((float)(p_tmp1[13] * p_tmp2[5]) + (float)(p_tmp1[12] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[14]))
               + (float)(p_tmp2[13] * p_tmp1[15]);
  dst->m[3][2] = (float)((float)((float)(p_tmp1[13] * p_tmp2[6]) + (float)(p_tmp1[12] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[14]))
               + (float)(p_tmp2[14] * p_tmp1[15]);
  dst->m[3][3] = (float)((float)((float)(p_tmp1[13] * p_tmp2[7]) + (float)(p_tmp1[12] * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[14]))
               + (float)(p_tmp1[15] * p_tmp2[15]);
}

//------------------------------------------------------------------------------
// Address: 0x1025FA60
// Name: void Vector4DMultiply(class VMatrix const __near &,class Vector4D const __near &,class Vector4D __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Vector4DMultiply(const VMatrix *src1, Vector4D *src2, Vector4D *dst)
{
  Vector4D *p_tmp; // eax
  Vector4D tmp; // [esp+0h] [ebp-10h] BYREF

  p_tmp = &tmp;
  if ( src2 == dst )
    tmp = *src2;
  else
    p_tmp = src2;
  dst->x = (float)((float)((float)(src1->m[0][1] * p_tmp->y) + (float)(p_tmp->x * src1->m[0][0]))
                 + (float)(src1->m[0][2] * p_tmp->z))
         + (float)(src1->m[0][3] * p_tmp->w);
  dst->y = (float)((float)((float)(src1->m[1][1] * p_tmp->y) + (float)(src1->m[1][0] * p_tmp->x))
                 + (float)(src1->m[1][2] * p_tmp->z))
         + (float)(src1->m[1][3] * p_tmp->w);
  dst->z = (float)((float)((float)(src1->m[2][1] * p_tmp->y) + (float)(src1->m[2][0] * p_tmp->x))
                 + (float)(src1->m[2][2] * p_tmp->z))
         + (float)(src1->m[2][3] * p_tmp->w);
  dst->w = (float)((float)((float)(src1->m[3][1] * p_tmp->y) + (float)(src1->m[3][0] * p_tmp->x))
                 + (float)(src1->m[3][2] * p_tmp->z))
         + (float)(src1->m[3][3] * p_tmp->w);
}

//------------------------------------------------------------------------------
// Address: 0x1025FB90
// Name: void Vector3DMultiply(class VMatrix const __near &,class Vector const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Vector3DMultiply(const VMatrix *src1, Vector *src2, Vector *dst)
{
  Vector *p_tmp; // eax
  __int64 v4; // xmm0_8
  float z; // edx
  float v6; // xmm3_4
  float v7; // xmm2_4
  float v8; // xmm4_4
  Vector tmp; // [esp+0h] [ebp-18h] BYREF
  __int64 v10; // [esp+Ch] [ebp-Ch]
  float v11; // [esp+14h] [ebp-4h]

  p_tmp = src2;
  if ( src2 == dst )
    p_tmp = &tmp;
  v4 = *(_QWORD *)&p_tmp->x;
  z = p_tmp->z;
  v6 = src1->m[0][1];
  v7 = src1->m[0][0];
  v8 = src1->m[0][2];
  v10 = v4;
  v11 = z;
  dst->x = (float)((float)(v6 * *((float *)&v4 + 1)) + (float)(v7 * *(float *)&v4)) + (float)(v8 * z);
  dst->y = (float)((float)(src1->m[1][0] * *(float *)&v4) + (float)(src1->m[1][1] * *((float *)&v4 + 1)))
         + (float)(src1->m[1][2] * z);
  dst->z = (float)((float)(src1->m[2][0] * *(float *)&v4) + (float)(src1->m[2][1] * *((float *)&v4 + 1)))
         + (float)(src1->m[2][2] * z);
}

//------------------------------------------------------------------------------
// Address: 0x1025FC50
// Name: void Vector3DMultiplyPositionProjective(class VMatrix const __near &,class Vector const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Vector3DMultiplyPositionProjective(const VMatrix *src1, Vector *src2, Vector *dst)
{
  Vector *p_tmp; // eax
  float z; // ecx
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm0_4
  float v8; // xmm4_4
  Vector tmp; // [esp+0h] [ebp-18h] BYREF
  __int64 v10; // [esp+Ch] [ebp-Ch]
  float v11; // [esp+14h] [ebp-4h]

  p_tmp = src2;
  if ( src2 == dst )
    p_tmp = &tmp;
  z = p_tmp->z;
  v10 = *(_QWORD *)&p_tmp->x;
  v5 = *(float *)&v10;
  v6 = *((float *)&v10 + 1);
  v11 = z;
  v7 = (float)((float)((float)(src1->m[3][0] * *(float *)&v10) + (float)(src1->m[3][1] * *((float *)&v10 + 1)))
             + (float)(src1->m[3][2] * z))
     + src1->m[3][3];
  if ( v7 != 0.0 )
    v7 = 1.0 / v7;
  dst->x = (float)((float)((float)(src1->m[0][1] * *((float *)&v10 + 1)) + (float)(src1->m[0][0] * *(float *)&v10))
                 + (float)(src1->m[0][2] * v11))
         + src1->m[0][3];
  dst->y = (float)((float)((float)(src1->m[1][0] * v5) + (float)(src1->m[1][1] * v6)) + (float)(src1->m[1][2] * z))
         + src1->m[1][3];
  v8 = (float)((float)((float)(src1->m[2][0] * v5) + (float)(src1->m[2][1] * v6)) + (float)(src1->m[2][2] * z))
     + src1->m[2][3];
  dst->x = dst->x * v7;
  dst->y = dst->y * v7;
  dst->z = v8 * v7;
}

//------------------------------------------------------------------------------
// Address: 0x1025FD90
// Name: void MatrixTransformPlane(class VMatrix const __near &,struct cplane_t const __near &,struct cplane_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixTransformPlane(const VMatrix *src, const cplane_t *inPlane, cplane_t *outPlane)
{
  const cplane_t *v3; // eax
  __int64 v4; // xmm0_8
  float z; // eax
  float x; // xmm2_4
  float v7; // xmm3_4
  float v8; // xmm1_4
  _DWORD v9[6]; // [esp+0h] [ebp-18h] BYREF

  if ( inPlane == outPlane )
    v3 = (const cplane_t *)v9;
  else
    v3 = inPlane;
  v4 = *(_QWORD *)&v3->normal.x;
  z = v3->normal.z;
  *(_QWORD *)&v9[3] = v4;
  *(float *)&v9[5] = z;
  outPlane->normal.x = (float)((float)(src->m[0][1] * *((float *)&v4 + 1)) + (float)(src->m[0][0] * *(float *)&v4))
                     + (float)(src->m[0][2] * z);
  outPlane->normal.y = (float)((float)(src->m[1][0] * *(float *)&v4) + (float)(src->m[1][1] * *((float *)&v4 + 1)))
                     + (float)(src->m[1][2] * z);
  x = outPlane->normal.x;
  v7 = (float)((float)(src->m[2][0] * *(float *)&v4) + (float)(src->m[2][1] * *((float *)&v4 + 1)))
     + (float)(src->m[2][2] * z);
  *(float *)&v4 = outPlane->normal.y;
  outPlane->normal.z = v7;
  v8 = (float)((float)((float)(x * x) + (float)(*(float *)&v4 * *(float *)&v4)) + (float)(v7 * v7)) * inPlane->dist;
  outPlane->dist = v8;
  outPlane->dist = (float)((float)((float)(*(float *)&v4 * src->m[1][3]) + (float)(x * src->m[0][3]))
                         + (float)(v7 * src->m[2][3]))
                 + v8;
}

//------------------------------------------------------------------------------
// Address: 0x1025FEB0
// Name: void MatrixBuildTranslation(class VMatrix __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildTranslation(VMatrix *dst, const Vector *translation)
{
  dst->m[0][3] = 0.0;
  dst->m[1][3] = 0.0;
  dst->m[2][3] = 0.0;
  *(_QWORD *)&dst->m[0][0] = 1065353216;
  dst->m[0][2] = 0.0;
  dst->m[1][0] = 0.0;
  *(_QWORD *)&dst->m[1][1] = 1065353216;
  *(_QWORD *)&dst->m[2][0] = 0;
  dst->m[2][2] = 1.0;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[3][3] = 1.0;
  dst->m[0][3] = translation->x;
  dst->m[1][3] = translation->y;
  dst->m[2][3] = translation->z;
}

//------------------------------------------------------------------------------
// Address: 0x1025FF80
// Name: void CalculateAABBFromProjectionMatrixInverse(class VMatrix const __near &,class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CalculateAABBFromProjectionMatrixInverse(const VMatrix *volumeToWorld, Vector *pMins, Vector *pMaxs)
{
  float v3; // xmm1_4
  float v4; // xmm2_4
  float v5; // xmm3_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm2_4
  float v10; // xmm3_4
  float v11; // xmm0_4
  float v12; // xmm3_4
  float v13; // xmm4_4
  float v14; // xmm0_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm0_4
  float v18; // xmm3_4
  float v19; // xmm4_4
  float v20; // xmm0_4
  float v21; // xmm2_4
  float v22; // xmm3_4
  float v23; // xmm0_4
  float v24; // xmm2_4
  float v25; // xmm3_4
  float v26; // xmm0_4
  float v27; // xmm2_4
  float v28; // xmm3_4
  Vector v; // [esp+Ch] [ebp-Ch] BYREF

  ClearBounds(mins: pMins, maxs: pMaxs);
  v3 = (float)((float)((float)(volumeToWorld->m[3][1] + volumeToWorld->m[3][0]) + volumeToWorld->m[3][2]) * 0.0)
     + volumeToWorld->m[3][3];
  if ( v3 != 0.0 )
    v3 = 1.0 / v3;
  v4 = (float)(volumeToWorld->m[1][1] + volumeToWorld->m[1][0]) + volumeToWorld->m[1][2];
  v5 = (float)(volumeToWorld->m[2][1] + volumeToWorld->m[2][0]) + volumeToWorld->m[2][2];
  v.x = (float)((float)((float)((float)(volumeToWorld->m[0][0] + volumeToWorld->m[0][1]) + volumeToWorld->m[0][2]) * 0.0)
              + volumeToWorld->m[0][3])
      * v3;
  v6 = v3 * (float)((float)(v4 * 0.0) + volumeToWorld->m[1][3]);
  v7 = v3 * (float)((float)(v5 * 0.0) + volumeToWorld->m[2][3]);
  v.y = v6;
  v.z = v7;
  AddPointToBounds(&v, mins: pMins, maxs: pMaxs);
  v8 = (float)((float)((float)(volumeToWorld->m[3][1] + volumeToWorld->m[3][0]) * 0.0) + volumeToWorld->m[3][2])
     + volumeToWorld->m[3][3];
  if ( v8 != 0.0 )
    v8 = 1.0 / v8;
  v9 = (float)((float)((float)((float)(volumeToWorld->m[1][1] + volumeToWorld->m[1][0]) * 0.0) + volumeToWorld->m[1][2])
             + volumeToWorld->m[1][3])
     * v8;
  v10 = (float)((float)((float)((float)(volumeToWorld->m[2][1] + volumeToWorld->m[2][0]) * 0.0) + volumeToWorld->m[2][2])
              + volumeToWorld->m[2][3])
      * v8;
  v.x = (float)((float)((float)((float)(volumeToWorld->m[0][0] + volumeToWorld->m[0][1]) * 0.0) + volumeToWorld->m[0][2])
              + volumeToWorld->m[0][3])
      * v8;
  v.y = v9;
  v.z = v10;
  AddPointToBounds(&v, mins: pMins, maxs: pMaxs);
  v11 = (float)((float)((float)(volumeToWorld->m[3][0] * 0.0) + volumeToWorld->m[3][1])
              + (float)(volumeToWorld->m[3][2] * 0.0))
      + volumeToWorld->m[3][3];
  if ( v11 != 0.0 )
    v11 = 1.0 / v11;
  v12 = (float)((float)((float)((float)(volumeToWorld->m[1][0] * 0.0) + volumeToWorld->m[1][1])
                      + (float)(volumeToWorld->m[1][2] * 0.0))
              + volumeToWorld->m[1][3])
      * v11;
  v13 = (float)((float)((float)((float)(volumeToWorld->m[2][0] * 0.0) + volumeToWorld->m[2][1])
                      + (float)(volumeToWorld->m[2][2] * 0.0))
              + volumeToWorld->m[2][3])
      * v11;
  v.x = (float)((float)((float)((float)(volumeToWorld->m[0][0] * 0.0) + volumeToWorld->m[0][1])
                      + (float)(volumeToWorld->m[0][2] * 0.0))
              + volumeToWorld->m[0][3])
      * v11;
  v.y = v12;
  v.z = v13;
  AddPointToBounds(&v, mins: pMins, maxs: pMaxs);
  v14 = (float)((float)((float)(volumeToWorld->m[3][0] * 0.0) + volumeToWorld->m[3][1]) + volumeToWorld->m[3][2])
      + volumeToWorld->m[3][3];
  if ( v14 != 0.0 )
    v14 = 1.0 / v14;
  v15 = (float)((float)((float)((float)(volumeToWorld->m[1][0] * 0.0) + volumeToWorld->m[1][1]) + volumeToWorld->m[1][2])
              + volumeToWorld->m[1][3])
      * v14;
  v16 = (float)((float)((float)((float)(volumeToWorld->m[2][0] * 0.0) + volumeToWorld->m[2][1]) + volumeToWorld->m[2][2])
              + volumeToWorld->m[2][3])
      * v14;
  v.x = (float)((float)((float)((float)(volumeToWorld->m[0][0] * 0.0) + volumeToWorld->m[0][1]) + volumeToWorld->m[0][2])
              + volumeToWorld->m[0][3])
      * v14;
  v.y = v15;
  v.z = v16;
  AddPointToBounds(&v, mins: pMins, maxs: pMaxs);
  v17 = (float)((float)((float)(volumeToWorld->m[3][1] * 0.0) + volumeToWorld->m[3][0])
              + (float)(volumeToWorld->m[3][2] * 0.0))
      + volumeToWorld->m[3][3];
  if ( v17 != 0.0 )
    v17 = 1.0 / v17;
  v18 = (float)((float)((float)((float)(volumeToWorld->m[1][1] * 0.0) + volumeToWorld->m[1][0])
                      + (float)(volumeToWorld->m[1][2] * 0.0))
              + volumeToWorld->m[1][3])
      * v17;
  v19 = (float)((float)((float)((float)(volumeToWorld->m[2][1] * 0.0) + volumeToWorld->m[2][0])
                      + (float)(volumeToWorld->m[2][2] * 0.0))
              + volumeToWorld->m[2][3])
      * v17;
  v.x = (float)((float)((float)((float)(volumeToWorld->m[0][1] * 0.0) + volumeToWorld->m[0][0])
                      + (float)(volumeToWorld->m[0][2] * 0.0))
              + volumeToWorld->m[0][3])
      * v17;
  v.y = v18;
  v.z = v19;
  AddPointToBounds(&v, mins: pMins, maxs: pMaxs);
  v20 = (float)((float)((float)(volumeToWorld->m[3][1] * 0.0) + volumeToWorld->m[3][0]) + volumeToWorld->m[3][2])
      + volumeToWorld->m[3][3];
  if ( v20 != 0.0 )
    v20 = 1.0 / v20;
  v21 = (float)((float)((float)((float)(volumeToWorld->m[1][1] * 0.0) + volumeToWorld->m[1][0]) + volumeToWorld->m[1][2])
              + volumeToWorld->m[1][3])
      * v20;
  v22 = (float)((float)((float)((float)(volumeToWorld->m[2][1] * 0.0) + volumeToWorld->m[2][0]) + volumeToWorld->m[2][2])
              + volumeToWorld->m[2][3])
      * v20;
  v.x = (float)((float)((float)((float)(volumeToWorld->m[0][1] * 0.0) + volumeToWorld->m[0][0]) + volumeToWorld->m[0][2])
              + volumeToWorld->m[0][3])
      * v20;
  v.y = v21;
  v.z = v22;
  AddPointToBounds(&v, mins: pMins, maxs: pMaxs);
  v23 = (float)((float)(volumeToWorld->m[3][1] + volumeToWorld->m[3][0]) + (float)(volumeToWorld->m[3][2] * 0.0))
      + volumeToWorld->m[3][3];
  if ( v23 != 0.0 )
    v23 = 1.0 / v23;
  v24 = (float)((float)((float)(volumeToWorld->m[1][1] + volumeToWorld->m[1][0]) + (float)(volumeToWorld->m[1][2] * 0.0))
              + volumeToWorld->m[1][3])
      * v23;
  v25 = (float)((float)((float)(volumeToWorld->m[2][1] + volumeToWorld->m[2][0]) + (float)(volumeToWorld->m[2][2] * 0.0))
              + volumeToWorld->m[2][3])
      * v23;
  v.x = (float)((float)((float)(volumeToWorld->m[0][0] + volumeToWorld->m[0][1]) + (float)(volumeToWorld->m[0][2] * 0.0))
              + volumeToWorld->m[0][3])
      * v23;
  v.y = v24;
  v.z = v25;
  AddPointToBounds(&v, mins: pMins, maxs: pMaxs);
  v26 = (float)((float)(volumeToWorld->m[3][1] + volumeToWorld->m[3][0]) + volumeToWorld->m[3][2])
      + volumeToWorld->m[3][3];
  if ( v26 != 0.0 )
    v26 = 1.0 / v26;
  v27 = (float)((float)((float)(volumeToWorld->m[1][1] + volumeToWorld->m[1][0]) + volumeToWorld->m[1][2])
              + volumeToWorld->m[1][3])
      * v26;
  v28 = (float)((float)((float)(volumeToWorld->m[2][1] + volumeToWorld->m[2][0]) + volumeToWorld->m[2][2])
              + volumeToWorld->m[2][3])
      * v26;
  v.x = (float)((float)((float)(volumeToWorld->m[0][0] + volumeToWorld->m[0][1]) + volumeToWorld->m[0][2])
              + volumeToWorld->m[0][3])
      * v26;
  v.y = v27;
  v.z = v28;
  AddPointToBounds(&v, mins: pMins, maxs: pMaxs);
}

//------------------------------------------------------------------------------
// Address: 0x10260500
// Name: FrustumPlanesFromMatrixHelper
// Source: json
//------------------------------------------------------------------------------
void __usercall FrustumPlanesFromMatrixHelper(
        const Vector *p1@<eax>,
        Vector *p2@<edx>,
        Vector *p3@<edi>,
        VPlane *plane@<esi>,
        const VMatrix *shadowToWorld)
{
  __int64 v5; // xmm0_8
  float z; // eax
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm3_4
  float v11; // xmm6_4
  float v12; // xmm0_4
  Vector *p_world2; // eax
  __int64 v14; // xmm0_8
  float v15; // eax
  float v16; // xmm3_4
  float v17; // xmm2_4
  float v18; // xmm1_4
  Vector *p_world3; // eax
  float v20; // edx
  float v21; // xmm5_4
  float v22; // xmm5_4
  float v23; // xmm6_4
  float v24; // xmm0_4
  float v25; // xmm4_4
  float v26; // xmm5_4
  float v27; // xmm2_4
  float v28; // xmm4_4
  float v29; // xmm1_4
  float v30; // xmm0_4
  Vector world3; // [esp+4h] [ebp-30h] BYREF
  Vector world2; // [esp+10h] [ebp-24h] BYREF
  __int64 v33; // [esp+1Ch] [ebp-18h]
  float v34; // [esp+24h] [ebp-10h]
  Vector world1; // [esp+28h] [ebp-Ch] BYREF

  if ( p1 == &world1 )
  {
    world2 = world3;
    p1 = &world2;
  }
  v5 = *(_QWORD *)&p1->x;
  z = p1->z;
  v7 = shadowToWorld->m[3][1];
  *(_QWORD *)&world1.x = v5;
  world1.z = z;
  v8 = (float)((float)((float)(*(float *)&v5 * shadowToWorld->m[3][0]) + (float)(v7 * *((float *)&v5 + 1)))
             + (float)(z * shadowToWorld->m[3][2]))
     + shadowToWorld->m[3][3];
  if ( v8 != 0.0 )
    v8 = 1.0 / v8;
  v9 = (float)((float)((float)(shadowToWorld->m[0][0] * *(float *)&v5)
                     + (float)(*((float *)&v5 + 1) * shadowToWorld->m[0][1]))
             + (float)(z * shadowToWorld->m[0][2]))
     + shadowToWorld->m[0][3];
  v10 = (float)(*(float *)&v5 * shadowToWorld->m[1][0]) + (float)(shadowToWorld->m[1][1] * *((float *)&v5 + 1));
  v11 = shadowToWorld->m[1][2] * z;
  v12 = (float)((float)((float)(*(float *)&v5 * shadowToWorld->m[2][0])
                      + (float)(*((float *)&v5 + 1) * shadowToWorld->m[2][1]))
              + (float)(z * shadowToWorld->m[2][2]))
      + shadowToWorld->m[2][3];
  world1.x = v9 * v8;
  world1.y = v8 * (float)((float)(v10 + v11) + shadowToWorld->m[1][3]);
  world1.z = v12 * v8;
  if ( p2 == &world2 )
  {
    world2 = world3;
    p_world2 = &world2;
  }
  else
  {
    p_world2 = p2;
  }
  v14 = *(_QWORD *)&p_world2->x;
  v15 = p_world2->z;
  v33 = v14;
  v34 = v15;
  v16 = (float)((float)((float)(*(float *)&v14 * shadowToWorld->m[3][0])
                      + (float)(*((float *)&v14 + 1) * shadowToWorld->m[3][1]))
              + (float)(v15 * shadowToWorld->m[3][2]))
      + shadowToWorld->m[3][3];
  if ( v16 != 0.0 )
    v16 = 1.0 / v16;
  v17 = (float)((float)((float)((float)(shadowToWorld->m[0][0] * *(float *)&v14)
                              + (float)(*((float *)&v14 + 1) * shadowToWorld->m[0][1]))
                      + (float)(v15 * shadowToWorld->m[0][2]))
              + shadowToWorld->m[0][3])
      * v16;
  v18 = (float)((float)((float)((float)(*(float *)&v14 * shadowToWorld->m[2][0])
                              + (float)(*((float *)&v14 + 1) * shadowToWorld->m[2][1]))
                      + (float)(v15 * shadowToWorld->m[2][2]))
              + shadowToWorld->m[2][3])
      * v16;
  world2.y = (float)((float)((float)((float)(*(float *)&v14 * shadowToWorld->m[1][0])
                                   + (float)(*((float *)&v14 + 1) * shadowToWorld->m[1][1]))
                           + (float)(shadowToWorld->m[1][2] * v15))
                   + shadowToWorld->m[1][3])
           * v16;
  world2.z = v18;
  if ( p3 == &world3 )
    p_world3 = &world3;
  else
    p_world3 = p3;
  v20 = p_world3->z;
  v33 = *(_QWORD *)&p_world3->x;
  v21 = (float)(*(float *)&v33 * shadowToWorld->m[3][0]) + (float)(*((float *)&v33 + 1) * shadowToWorld->m[3][1]);
  v34 = v20;
  v22 = (float)(v21 + (float)(v20 * shadowToWorld->m[3][2])) + shadowToWorld->m[3][3];
  if ( v22 != 0.0 )
    v22 = 1.0 / v22;
  v23 = v17 - world1.x;
  v24 = (float)((float)((float)((float)((float)(*(float *)&v33 * shadowToWorld->m[1][0])
                                      + (float)(*((float *)&v33 + 1) * shadowToWorld->m[1][1]))
                              + (float)(shadowToWorld->m[1][2] * v20))
                      + shadowToWorld->m[1][3])
              * v22)
      - world1.y;
  v25 = (float)((float)((float)((float)(v20 * shadowToWorld->m[2][2])
                              + (float)((float)(*(float *)&v33 * shadowToWorld->m[2][0])
                                      + (float)(*((float *)&v33 + 1) * shadowToWorld->m[2][1])))
                      + shadowToWorld->m[2][3])
              * v22)
      - world1.z;
  v26 = (float)((float)((float)((float)((float)(shadowToWorld->m[0][0] * *(float *)&v33)
                                      + (float)(*((float *)&v33 + 1) * shadowToWorld->m[0][1]))
                              + (float)(v20 * shadowToWorld->m[0][2]))
                      + shadowToWorld->m[0][3])
              * v22)
      - world1.x;
  v27 = v25 * (float)(v17 - world1.x);
  v28 = (float)(v25 * (float)(world2.y - world1.y)) - (float)(v24 * (float)(world2.z - world1.z));
  v29 = (float)((float)(world2.z - world1.z) * v26) - v27;
  v30 = (float)(v24 * v23) - (float)((float)(world2.y - world1.y) * v26);
  plane->m_Normal.x = v28;
  plane->m_Normal.y = v29;
  plane->m_Normal.z = v30;
  VectorNormalize(vec: &plane->m_Normal);
  plane->m_Dist = (float)((float)(plane->m_Normal.y * world1.y) + (float)(world1.x * plane->m_Normal.x))
                + (float)(plane->m_Normal.z * world1.z);
}

//------------------------------------------------------------------------------
// Address: 0x10260890
// Name: void FrustumPlanesFromMatrix(class VMatrix const __near &,class Frustum_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FrustumPlanesFromMatrix(const VMatrix *clipToWorld, Frustum_t *frustum)
{
  VPlane planes[6]; // [esp+0h] [ebp-84h] BYREF
  Vector p3; // [esp+60h] [ebp-24h] BYREF
  Vector p1; // [esp+6Ch] [ebp-18h] BYREF
  Vector p2; // [esp+78h] [ebp-Ch] BYREF

  p3.x = 0.0;
  p3.y = 1.0;
  p3.z = 0.0;
  p2.x = 1.0;
  p2.y = 0.0;
  p2.z = 0.0;
  memset(&p1, 0, sizeof(p1));
  FrustumPlanesFromMatrixHelper(&p1, &p2, &p3, plane: &planes[4], shadowToWorld: clipToWorld);
  p1.x = 1.0;
  p1.y = 0.0;
  p1.z = 1.0;
  p2.x = 0.0;
  p2.y = 1.0;
  p2.z = 1.0;
  p3.x = 0.0;
  p3.y = 0.0;
  p3.z = 1.0;
  FrustumPlanesFromMatrixHelper(p1: &p3, &p2, p3: &p1, plane: &planes[5], shadowToWorld: clipToWorld);
  p1.x = 1.0;
  p1.y = 1.0;
  p1.z = 0.0;
  p2.x = 1.0;
  p2.y = 1.0;
  p2.z = 1.0;
  p3.x = 1.0;
  p3.y = 0.0;
  p3.z = 0.0;
  FrustumPlanesFromMatrixHelper(p1: &p3, &p2, p3: &p1, plane: planes, shadowToWorld: clipToWorld);
  p1.x = 0.0;
  p1.y = 0.0;
  p1.z = 1.0;
  p2.x = 0.0;
  p2.y = 1.0;
  p2.z = 1.0;
  memset(&p3, 0, sizeof(p3));
  FrustumPlanesFromMatrixHelper(p1: &p3, &p2, p3: &p1, plane: &planes[1], shadowToWorld: clipToWorld);
  p1.x = 0.0;
  p1.y = 1.0;
  p1.z = 1.0;
  p2.x = 1.0;
  p2.y = 1.0;
  p2.z = 1.0;
  p3.x = 1.0;
  p3.y = 1.0;
  p3.z = 0.0;
  FrustumPlanesFromMatrixHelper(p1: &p3, &p2, p3: &p1, plane: &planes[2], shadowToWorld: clipToWorld);
  p1.x = 1.0;
  p1.y = 0.0;
  p1.z = 1.0;
  p2.x = 0.0;
  p2.y = 0.0;
  p2.z = 1.0;
  p3.x = 1.0;
  p3.y = 0.0;
  p3.z = 0.0;
  FrustumPlanesFromMatrixHelper(p1: &p3, &p2, p3: &p1, plane: &planes[3], shadowToWorld: clipToWorld);
  Frustum_t::SetPlanes(this: frustum, pPlanes: (__m128 *)planes);
}

//------------------------------------------------------------------------------
// Address: 0x10260A80
// Name: void MatrixBuildOrtho(class VMatrix __near &,double,double,double,double,double,double)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildOrtho(
        VMatrix *dst,
        long double left,
        long double top,
        long double right,
        long double bottom,
        long double zNear,
        long double zFar)
{
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm1_4
  long double v11; // xmm1_8

  v7 = 2.0 / (right - left);
  v8 = (left + right) / (left - right);
  dst->m[0][3] = v8;
  v9 = 2.0 / (bottom - top);
  dst->m[1][1] = v9;
  dst->m[0][0] = v7;
  v10 = (top + bottom) / (top - bottom);
  dst->m[1][3] = v10;
  v11 = 1.0 / (zNear - zFar);
  *(_QWORD *)&dst->m[0][1] = 0;
  dst->m[1][0] = 0.0;
  dst->m[1][2] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[2][2] = v11;
  dst->m[2][3] = v11 * zNear;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10260B80
// Name: void MatrixBuildPerspectiveX(class VMatrix __near &,double,double,double,double)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildPerspectiveX(
        VMatrix *dst,
        unsigned __int64 flFovX,
        long double flAspect,
        long double flZNear,
        long double flZFar)
{
  __m128d v5; // xmm0
  __m128i v6; // xmm0
  double v7; // xmm0_8
  float v8; // xmm2_4
  double v9; // xmm0_8
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm1_4
  float v13; // xmm4_4

  v5 = (__m128d)flFovX;
  v5.m128d_f64[0] = *(double *)&flFovX * 3.141592653589793 * 0.002777777777777778;
  v6 = (__m128i)_mm_cvtpd_ps(v5);
  *(double *)v6.m128i_i64 = *(float *)v6.m128i_i32;
  __libm_sse2_tan(a1: v6);
  *(float *)&v7 = v7;
  v8 = *(float *)&v7 * (flZNear * 2.0);
  v9 = v8;
  v10 = v8 / flAspect;
  v11 = flZNear * 2.0 / v10;
  dst->m[1][1] = v11;
  *(float *)&v9 = flZNear * 2.0 / v9;
  v12 = flZNear * flZFar / (flZNear - flZFar);
  dst->m[0][0] = *(float *)&v9;
  dst->m[2][3] = v12;
  v13 = flZFar / (flZNear - flZFar);
  *(_QWORD *)&dst->m[0][1] = 0;
  dst->m[0][3] = 0.0;
  dst->m[1][0] = 0.0;
  *(_QWORD *)&dst->m[1][2] = 0;
  *(_QWORD *)&dst->m[2][0] = 0;
  dst->m[2][2] = v13;
  *(_QWORD *)&dst->m[3][0] = 0;
  *(_QWORD *)&dst->m[3][2] = 3212836864LL;
}

//------------------------------------------------------------------------------
// Address: 0x10260C90
// Name: void MatrixBuildPerspectiveOffCenterX(class VMatrix __near &,double,double,double,double,double,double,double,double)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildPerspectiveOffCenterX(
        VMatrix *dst,
        unsigned __int64 flFovX,
        long double flAspect,
        long double flZNear,
        long double flZFar,
        long double bottom,
        long double top,
        long double left,
        long double right)
{
  __m128d v9; // xmm0
  __m128i v10; // xmm0
  double v11; // xmm0_8
  float v12; // xmm2_4
  float v13; // xmm1_4
  long double v14; // xmm5_8
  float v15; // xmm1_4
  long double v16; // xmm6_8
  float v17; // xmm2_4
  float v18; // xmm3_4
  float v19; // xmm1_4

  v9 = (__m128d)flFovX;
  v9.m128d_f64[0] = *(double *)&flFovX * 3.141592653589793 * 0.002777777777777778;
  v10 = (__m128i)_mm_cvtpd_ps(v9);
  *(double *)v10.m128i_i64 = *(float *)v10.m128i_i32;
  __libm_sse2_tan(a1: v10);
  *(float *)&v11 = v11;
  *(float *)&v11 = *(float *)&v11 * (flZNear * 2.0);
  v12 = (float)(*(float *)&v11 / flAspect) * 0.5;
  v13 = *(float *)&v11 * 0.5;
  v14 = v13 * left - (1.0 - left) * v13;
  v15 = v13 * right - (1.0 - right) * v13;
  v16 = v12 * bottom - (1.0 - bottom) * v12;
  *(float *)&v14 = v14;
  v17 = v12 * top - (1.0 - top) * v12;
  dst->m[0][2] = (float)(v15 + *(float *)&v14) / (float)(v15 - *(float *)&v14);
  *(float *)&v16 = v16;
  *(float *)&v11 = flZNear * 2.0 / (float)(v15 - *(float *)&v14);
  dst->m[0][0] = *(float *)&v11;
  v18 = flZNear * 2.0 / (float)(v17 - *(float *)&v16);
  dst->m[0][1] = 0.0;
  dst->m[0][3] = 0.0;
  dst->m[1][0] = 0.0;
  dst->m[1][1] = v18;
  dst->m[1][2] = (float)(v17 + *(float *)&v16) / (float)(v17 - *(float *)&v16);
  v19 = flZNear * flZFar / (flZNear - flZFar);
  dst->m[2][3] = v19;
  dst->m[1][3] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  dst->m[2][2] = flZFar / (flZNear - flZFar);
  *(_QWORD *)&dst->m[3][0] = 0;
  *(_QWORD *)&dst->m[3][2] = 3212836864LL;
}

//------------------------------------------------------------------------------
// Address: 0x10260E60
// Name: class VMatrix SetupMatrixScale(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
VMatrix *__cdecl SetupMatrixScale(VMatrix *result, const Vector *vScale)
{
  double x; // st7
  double y; // st7
  double z; // st7

  x = vScale->x;
  result->m[0][1] = 0.0;
  result->m[0][0] = x;
  result->m[0][2] = 0.0;
  y = vScale->y;
  result->m[0][3] = 0.0;
  result->m[1][1] = y;
  result->m[1][0] = 0.0;
  z = vScale->z;
  *(_QWORD *)&result->m[1][2] = 0;
  result->m[2][2] = z;
  *(_QWORD *)&result->m[2][0] = 0;
  result->m[2][3] = 0.0;
  *(_QWORD *)&result->m[3][0] = 0;
  result->m[3][2] = 0.0;
  result->m[3][3] = 1.0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10260ED0
// Name: bool MatrixInverseGeneral(class VMatrix const __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl MatrixInverseGeneral(const VMatrix *src, VMatrix *dst)
{
  int v3; // edx
  _DWORD *v4; // eax
  float *v5; // ecx
  int v6; // ebx
  int v7; // edx
  int i; // edi
  int v9; // ecx
  float v10; // xmm0_4
  int v11; // eax
  float v12; // xmm1_4
  float v13; // xmm1_4
  float v14; // xmm1_4
  float v15; // xmm1_4
  float v16; // xmm1_4
  int v17; // eax
  float v18; // xmm1_4
  float *v19; // eax
  float v20; // xmm0_4
  int j; // esi
  float *v22; // ecx
  float v23; // xmm0_4
  int k; // edx
  float *v26; // ecx
  float v27; // esi
  float v28; // ecx
  float mat[4][8]; // [esp+0h] [ebp-90h] BYREF
  int rowMap[4]; // [esp+80h] [ebp-10h] BYREF

  v3 = 0;
  v4 = &mat[0][5];
  do
  {
    *(v4 - 5) = LODWORD(src->m[0][0]);
    v5 = (float *)(v4 - 5);
    v5[1] = src->m[0][1];
    v5[2] = src->m[0][2];
    v5[3] = src->m[0][3];
    *(v4 - 1) = 0;
    *v4 = 0;
    v4[1] = 0;
    v4[2] = 0;
    rowMap[v3] = v3;
    v6 = (int)&v4[v3++ - 5] + 16 - (_DWORD)rowMap;
    src = (const VMatrix *)((char *)src + 16);
    v4 += 8;
    *(int *)((char *)rowMap + v6) = 1065353216;
  }
  while ( v3 < 4 );
  v7 = 0;
  for ( i = 4; i > 0; --i )
  {
    v9 = -1;
    v10 = 0.000001;
    v11 = v7;
    if ( i >= 4 )
    {
      do
      {
        v12 = fabs(mat[rowMap[v11]][v7]);
        if ( v12 > v10 )
        {
          v9 = v11;
          v10 = v12;
        }
        v13 = fabs(mat[rowMap[v11 + 1]][v7]);
        if ( v13 > v10 )
        {
          v9 = v11 + 1;
          v10 = v13;
        }
        v14 = fabs(mat[rowMap[v11 + 2]][v7]);
        if ( v14 > v10 )
        {
          v9 = v11 + 2;
          v10 = v14;
        }
        v15 = fabs(mat[rowMap[v11 + 3]][v7]);
        if ( v15 > v10 )
        {
          v9 = v11 + 3;
          v10 = v15;
        }
        v11 += 4;
      }
      while ( v11 < 1 );
    }
    for ( ; v11 < 4; ++v11 )
    {
      v16 = fabs(mat[rowMap[v11]][v7]);
      if ( v16 > v10 )
      {
        v9 = v11;
        v10 = v16;
      }
    }
    if ( v9 == -1 )
      return 0;
    v17 = rowMap[v9];
    rowMap[v9] = rowMap[v7];
    rowMap[v7] = v17;
    v17 *= 32;
    v18 = *(float *)((char *)mat[0] + v17);
    v19 = (float *)((char *)mat[0] + v17);
    v20 = 1.0 / v19[v7];
    *v19 = v18 * v20;
    v19[1] = v19[1] * v20;
    v19[2] = v19[2] * v20;
    v19[3] = v19[3] * v20;
    v19[4] = v19[4] * v20;
    v19[5] = v19[5] * v20;
    v19[6] = v19[6] * v20;
    v19[7] = v19[7] * v20;
    v19[v7] = 1.0;
    for ( j = 0; j < 4; ++j )
    {
      if ( j != v7 )
      {
        v22 = mat[rowMap[j]];
        v23 = -v22[v7];
        *v22 = (float)(*v19 * v23) + *v22;
        v22[1] = (float)(v19[1] * v23) + v22[1];
        v22[2] = (float)(v19[2] * v23) + v22[2];
        v22[3] = (float)(v19[3] * v23) + v22[3];
        v22[4] = (float)(v19[4] * v23) + v22[4];
        v22[5] = (float)(v19[5] * v23) + v22[5];
        v22[6] = (float)(v19[6] * v23) + v22[6];
        v22[7] = (float)(v19[7] * v23) + v22[7];
        v22[v7] = 0.0;
      }
    }
    ++v7;
  }
  for ( k = 0; k < 4; ++k )
  {
    v26 = &mat[rowMap[k]][4];
    dst->m[0][0] = *v26;
    dst->m[0][1] = v26[1];
    v27 = v26[2];
    v28 = v26[3];
    dst->m[0][2] = v27;
    dst->m[0][3] = v28;
    dst = (VMatrix *)((char *)dst + 16);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102611F0
// Name: void MatrixInverseTR(class VMatrix const __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixInverseTR(const VMatrix *src, VMatrix *dst)
{
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm4_4
  float v8; // xmm5_4
  float v9; // xmm1_4
  float v10; // xmm0_4

  dst->m[0][0] = src->m[0][0];
  dst->m[0][1] = src->m[1][0];
  dst->m[0][2] = src->m[2][0];
  dst->m[1][0] = src->m[0][1];
  dst->m[1][1] = src->m[1][1];
  dst->m[1][2] = src->m[2][1];
  dst->m[2][0] = src->m[0][2];
  dst->m[2][1] = src->m[1][2];
  dst->m[2][2] = src->m[2][2];
  v3 = -src->m[0][3];
  v4 = -src->m[1][3];
  v5 = -src->m[2][3];
  v6 = (float)((float)(dst->m[0][0] * v3) + (float)(v4 * dst->m[0][1])) + (float)(dst->m[0][2] * v5);
  v7 = (float)((float)(dst->m[1][1] * v4) + (float)(dst->m[1][0] * v3)) + (float)(v5 * dst->m[1][2]);
  v8 = dst->m[2][1] * v4;
  v9 = dst->m[2][0] * v3;
  v10 = dst->m[2][2] * v5;
  dst->m[0][3] = v6;
  dst->m[1][3] = v7;
  dst->m[2][3] = (float)(v8 + v9) + v10;
  *(_QWORD *)&dst->m[3][1] = 0;
  dst->m[3][0] = 0.0;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x102612F0
// Name: void CalculateSphereFromProjectionMatrixInverse(class VMatrix const __near &,class Vector __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CalculateSphereFromProjectionMatrixInverse(
        const VMatrix *volumeToWorld,
        Vector *pCenter,
        float *pflRadius)
{
  float v3; // xmm6_4
  float v4; // xmm5_4
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm7_4
  float v9; // xmm0_4
  float v10; // xmm4_4
  float v11; // xmm1_4
  float v12; // xmm6_4
  float v13; // xmm7_4
  float v14; // xmm6_4
  float v15; // xmm5_4
  float v16; // xmm2_4
  float v17; // xmm0_4
  float v18; // [esp-4h] [ebp-34h]
  float vecFarEdge_4; // [esp+4h] [ebp-2Ch]
  float vecFarEdge_8; // [esp+8h] [ebp-28h]
  float vecCenterFar; // [esp+Ch] [ebp-24h]
  float vecCenterFar_4; // [esp+10h] [ebp-20h]
  float vecCenterFar_8; // [esp+14h] [ebp-1Ch]
  float vecNearEdge; // [esp+18h] [ebp-18h]
  float vecNearEdge_4; // [esp+1Ch] [ebp-14h]
  float vecNearEdge_8; // [esp+20h] [ebp-10h]

  v3 = (float)((float)((float)(volumeToWorld->m[3][1] + volumeToWorld->m[3][0]) * 0.5)
             + (float)(volumeToWorld->m[3][2] * 0.0))
     + volumeToWorld->m[3][3];
  if ( v3 != 0.0 )
    v3 = 1.0 / v3;
  v4 = (float)((float)((float)((float)(volumeToWorld->m[0][0] + volumeToWorld->m[0][1]) * 0.5)
                     + (float)(volumeToWorld->m[0][2] * 0.0))
             + volumeToWorld->m[0][3])
     * v3;
  v5 = (float)((float)((float)(volumeToWorld->m[3][1] + volumeToWorld->m[3][0]) * 0.5) + volumeToWorld->m[3][2])
     + volumeToWorld->m[3][3];
  vecNearEdge = v4;
  vecNearEdge_4 = (float)((float)((float)((float)(volumeToWorld->m[1][1] + volumeToWorld->m[1][0]) * 0.5)
                                + (float)(volumeToWorld->m[1][2] * 0.0))
                        + volumeToWorld->m[1][3])
                * v3;
  vecNearEdge_8 = (float)((float)((float)((float)(volumeToWorld->m[2][1] + volumeToWorld->m[2][0]) * 0.5)
                                + (float)(volumeToWorld->m[2][2] * 0.0))
                        + volumeToWorld->m[2][3])
                * v3;
  if ( v5 != 0.0 )
    v5 = 1.0 / v5;
  v6 = (float)((float)((float)((float)(volumeToWorld->m[1][1] + volumeToWorld->m[1][0]) * 0.5) + volumeToWorld->m[1][2])
             + volumeToWorld->m[1][3])
     * v5;
  v7 = (float)((float)((float)((float)(volumeToWorld->m[2][1] + volumeToWorld->m[2][0]) * 0.5) + volumeToWorld->m[2][2])
             + volumeToWorld->m[2][3])
     * v5;
  v8 = (float)((float)((float)((float)(volumeToWorld->m[0][0] + volumeToWorld->m[0][1]) * 0.5) + volumeToWorld->m[0][2])
             + volumeToWorld->m[0][3])
     * v5;
  v9 = (float)((float)((float)(volumeToWorld->m[3][1] + volumeToWorld->m[3][0]) + volumeToWorld->m[3][2]) * 0.0)
     + volumeToWorld->m[3][3];
  vecFarEdge_4 = v6;
  vecFarEdge_8 = v7;
  if ( v9 != 0.0 )
    v9 = 1.0 / v9;
  v10 = (float)((float)((float)(volumeToWorld->m[3][1] + volumeToWorld->m[3][0]) * 0.0) + volumeToWorld->m[3][2])
      + volumeToWorld->m[3][3];
  if ( v10 != 0.0 )
    v10 = 1.0 / v10;
  v11 = (float)((float)((float)(volumeToWorld->m[1][1] + volumeToWorld->m[1][0]) * 0.0) + volumeToWorld->m[1][2])
      + volumeToWorld->m[1][3];
  v18 = (float)((float)((float)((float)(volumeToWorld->m[2][1] + volumeToWorld->m[2][0]) * 0.0) + volumeToWorld->m[2][2])
              + volumeToWorld->m[2][3])
      * v10;
  v12 = v8;
  v13 = v8
      - (float)((float)((float)((float)((float)(volumeToWorld->m[0][0] + volumeToWorld->m[0][1]) * 0.0)
                              + volumeToWorld->m[0][2])
                      + volumeToWorld->m[0][3])
              * v10);
  v14 = v12 - v4;
  vecCenterFar = (float)((float)((float)((float)(volumeToWorld->m[0][0] + volumeToWorld->m[0][1])
                                       + volumeToWorld->m[0][2])
                               * 0.0)
                       + volumeToWorld->m[0][3])
               * v9;
  vecCenterFar_4 = (float)((float)((float)((float)(volumeToWorld->m[1][1] + volumeToWorld->m[1][0])
                                         + volumeToWorld->m[1][2])
                                 * 0.0)
                         + volumeToWorld->m[1][3])
                 * v9;
  vecCenterFar_8 = (float)((float)((float)((float)(volumeToWorld->m[2][1] + volumeToWorld->m[2][0])
                                         + volumeToWorld->m[2][2])
                                 * 0.0)
                         + volumeToWorld->m[2][3])
                 * v9;
  v15 = (float)((float)((float)(vecNearEdge_4 - vecCenterFar_4) * (float)(vecNearEdge_4 - vecCenterFar_4))
              + (float)((float)(v4 - vecCenterFar) * (float)(v4 - vecCenterFar)))
      + (float)((float)(vecNearEdge_8 - vecCenterFar_8) * (float)(vecNearEdge_8 - vecCenterFar_8));
  v16 = fsqrt(
          (float)((float)((float)(vecFarEdge_4 - vecNearEdge_4) * (float)(vecFarEdge_4 - vecNearEdge_4))
                + (float)((float)(v7 - vecNearEdge_8) * (float)(v7 - vecNearEdge_8)))
        + (float)(v14 * v14));
  v17 = (float)((float)((float)((float)((float)((float)(vecFarEdge_4 - (float)(v11 * v10))
                                              * (float)(vecFarEdge_4 - (float)(v11 * v10)))
                                      + (float)(v13 * v13))
                              + (float)((float)(vecFarEdge_8 - v18) * (float)(vecFarEdge_8 - v18)))
                      + (float)(v16 * v16))
              - v15)
      / (float)(v16 * 2.0);
  pCenter->x = (float)((float)(v17 / v16) * v14) + vecNearEdge;
  pCenter->y = (float)((float)(vecFarEdge_4 - vecNearEdge_4) * (float)(v17 / v16)) + vecNearEdge_4;
  pCenter->z = (float)((float)(vecFarEdge_8 - vecNearEdge_8) * (float)(v17 / v16)) + vecNearEdge_8;
  *pflRadius = fsqrt((float)(v17 * v17) + v15);
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x10203400
// Name: public: class VMatrix __near & VMatrix::operator=(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
VMatrix *__thiscall VMatrix::operator=(VMatrix *this, const VMatrix *mOther)
{
  *this = *mOther;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10203470
// Name: public: bool VMatrix::operator==(class VMatrix const __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall VMatrix::operator==(VMatrix *this, const VMatrix *src)
{
  unsigned int v3; // eax

  v3 = 64;
  while ( LODWORD(src->m[0][0]) == LODWORD(this->m[0][0]) )
  {
    v3 -= 4;
    this = (VMatrix *)((char *)this + 4);
    src = (const VMatrix *)((char *)src + 4);
    if ( v3 < 4 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102034E0
// Name: public: void VMatrix::MatrixMul(class VMatrix const __near &,class VMatrix __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall VMatrix::MatrixMul(VMatrix *this, const VMatrix *vm, VMatrix *out)
{
  float v4; // xmm0_4
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm4_4
  float v8; // xmm5_4
  float v9; // xmm1_4
  float v10; // xmm7_4
  float v11; // xmm6_4
  float v12; // xmm0_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm3_4
  float v18; // xmm1_4
  float v19; // [esp+0h] [ebp-3Ch]
  float v20; // [esp+4h] [ebp-38h]
  float v21; // [esp+8h] [ebp-34h]
  float v22; // [esp+Ch] [ebp-30h]
  float v23; // [esp+10h] [ebp-2Ch]
  float v24; // [esp+14h] [ebp-28h]
  float v25; // [esp+18h] [ebp-24h]
  float v26; // [esp+1Ch] [ebp-20h]
  float v27; // [esp+20h] [ebp-1Ch]
  float v28; // [esp+24h] [ebp-18h]
  float v29; // [esp+28h] [ebp-14h]
  float v30; // [esp+28h] [ebp-14h]
  float v31; // [esp+28h] [ebp-14h]
  float v32; // [esp+2Ch] [ebp-10h]
  float v33; // [esp+30h] [ebp-Ch]
  float v34; // [esp+34h] [ebp-8h]
  __int64 v35; // [esp+34h] [ebp-8h]
  __int64 v36; // [esp+34h] [ebp-8h]
  float v37; // [esp+38h] [ebp-4h]
  float vma; // [esp+44h] [ebp+8h]

  v4 = this->m[0][1];
  v5 = this->m[0][2];
  v6 = this->m[0][3];
  v7 = (float)((float)((float)(this->m[0][0] * vm->m[0][1]) + (float)(v4 * vm->m[1][1])) + (float)(v5 * vm->m[2][1]))
     + (float)(v6 * vm->m[3][1]);
  v8 = (float)((float)((float)(vm->m[0][2] * this->m[0][0]) + (float)(vm->m[1][2] * v4)) + (float)(vm->m[2][2] * v5))
     + (float)(vm->m[3][2] * v6);
  v33 = vm->m[2][0];
  v37 = this->m[1][2];
  v32 = vm->m[3][0];
  v34 = this->m[1][3];
  v9 = vm->m[0][0];
  v10 = vm->m[1][0];
  v29 = this->m[1][1];
  v11 = (float)((float)((float)(vm->m[0][3] * this->m[0][0]) + (float)(vm->m[1][3] * v4)) + (float)(vm->m[2][3] * v5))
      + (float)(vm->m[3][3] * v6);
  v12 = this->m[1][0];
  v28 = (float)((float)((float)(vm->m[0][0] * v12) + (float)(v29 * v10)) + (float)(v37 * v33)) + (float)(v34 * v32);
  v27 = (float)((float)((float)(v12 * vm->m[0][1]) + (float)(v29 * vm->m[1][1])) + (float)(v37 * vm->m[2][1]))
      + (float)(v34 * vm->m[3][1]);
  v26 = (float)((float)((float)(v12 * vm->m[0][2]) + (float)(v29 * vm->m[1][2])) + (float)(v37 * vm->m[2][2]))
      + (float)(v34 * vm->m[3][2]);
  v13 = this->m[2][0];
  v25 = (float)((float)((float)(v12 * vm->m[0][3]) + (float)(v29 * vm->m[1][3])) + (float)(v37 * vm->m[2][3]))
      + (float)(v34 * vm->m[3][3]);
  v35 = *(_QWORD *)&this->m[2][2];
  v30 = this->m[2][1];
  v24 = (float)((float)((float)(v13 * vm->m[0][0]) + (float)(v30 * v10)) + (float)(*(float *)&v35 * v33))
      + (float)(*((float *)&v35 + 1) * v32);
  v23 = (float)((float)((float)(v13 * vm->m[0][1]) + (float)(v30 * vm->m[1][1])) + (float)(*(float *)&v35 * vm->m[2][1]))
      + (float)(*((float *)&v35 + 1) * vm->m[3][1]);
  v22 = (float)((float)((float)(v13 * vm->m[0][2]) + (float)(v30 * vm->m[1][2])) + (float)(*(float *)&v35 * vm->m[2][2]))
      + (float)(*((float *)&v35 + 1) * vm->m[3][2]);
  v21 = (float)((float)((float)(v13 * vm->m[0][3]) + (float)(v30 * vm->m[1][3])) + (float)(*(float *)&v35 * vm->m[2][3]))
      + (float)(*((float *)&v35 + 1) * vm->m[3][3]);
  v14 = this->m[3][0];
  v36 = *(_QWORD *)&this->m[3][2];
  v31 = this->m[3][1];
  v20 = (float)((float)((float)(v14 * vm->m[0][0]) + (float)(v31 * v10)) + (float)(*(float *)&v36 * v33))
      + (float)(*((float *)&v36 + 1) * v32);
  v19 = (float)((float)((float)(v14 * vm->m[0][1]) + (float)(v31 * vm->m[1][1])) + (float)(*(float *)&v36 * vm->m[2][1]))
      + (float)(*((float *)&v36 + 1) * vm->m[3][1]);
  v15 = v14 * vm->m[0][2];
  v16 = v14 * vm->m[0][3];
  vma = (float)((float)(v15 + (float)(v31 * vm->m[1][2])) + (float)(*(float *)&v36 * vm->m[2][2]))
      + (float)(*((float *)&v36 + 1) * vm->m[3][2]);
  v17 = (float)((float)(v16 + (float)(v31 * vm->m[1][3])) + (float)(*(float *)&v36 * vm->m[2][3]))
      + (float)(*((float *)&v36 + 1) * vm->m[3][3]);
  v18 = (float)((float)((float)(v9 * this->m[0][0]) + (float)(v10 * this->m[0][1])) + (float)(v33 * this->m[0][2]))
      + (float)(v32 * this->m[0][3]);
  out->m[1][0] = v28;
  out->m[1][1] = v27;
  out->m[1][2] = v26;
  out->m[1][3] = v25;
  out->m[0][0] = v18;
  out->m[0][1] = v7;
  out->m[0][2] = v8;
  out->m[0][3] = v11;
  out->m[2][0] = v24;
  out->m[2][1] = v23;
  out->m[2][2] = v22;
  out->m[2][3] = v21;
  out->m[3][0] = v20;
  out->m[3][1] = v19;
  out->m[3][2] = vma;
  out->m[3][3] = v17;
}

//------------------------------------------------------------------------------
// Address: 0x102039A0
// Name: public: class VMatrix VMatrix::operator*(class VMatrix const __near &)const
// Source: json
//------------------------------------------------------------------------------
VMatrix *__thiscall VMatrix::operator*(VMatrix *this, VMatrix *result, const VMatrix *vm)
{
  int v3; // edx

  VMatrix::MatrixMul(this, vm, out: result);
  return (VMatrix *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x102039C0
// Name: public: void VMatrix::SetupMatrixOrgAngles(class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VMatrix::SetupMatrixOrgAngles(VMatrix *this, const Vector *origin, const QAngle *vAngles)
{
  float v4; // xmm1_4
  float v5; // xmm1_4
  double z; // st7
  float v7; // [esp+8h] [ebp-18h]
  float cr; // [esp+Ch] [ebp-14h]
  float sr; // [esp+10h] [ebp-10h]
  float sy; // [esp+14h] [ebp-Ch]
  float cy; // [esp+18h] [ebp-8h]
  float cp; // [esp+1Ch] [ebp-4h]
  float vAnglesa; // [esp+2Ch] [ebp+Ch]

  v4 = vAngles->y * 0.017453292;
  cy = cos(v4);
  sy = sin(v4);
  v5 = vAngles->x * 0.017453292;
  cp = cos(v5);
  vAnglesa = sin(v5);
  v7 = vAngles->z * 0.017453292;
  cr = cos(v7);
  sr = sin(v7);
  this->m[0][0] = cp * cy;
  this->m[1][0] = cp * sy;
  LODWORD(this->m[2][0]) = LODWORD(vAnglesa) ^ _mask__NegFloat_;
  this->m[0][1] = (float)((float)(sr * vAnglesa) * cy) - (float)(cr * sy);
  this->m[1][1] = (float)((float)(sr * vAnglesa) * sy) + (float)(cr * cy);
  this->m[2][1] = sr * cp;
  this->m[1][2] = (float)((float)(cr * vAnglesa) * sy) - (float)(sr * cy);
  this->m[0][3] = 0.0;
  this->m[1][3] = 0.0;
  this->m[2][3] = 0.0;
  this->m[0][2] = (float)((float)(cr * vAnglesa) * cy) + (float)(sr * sy);
  this->m[2][2] = cr * cp;
  this->m[0][3] = origin->x;
  this->m[1][3] = origin->y;
  z = origin->z;
  this->m[3][0] = 0.0;
  this->m[2][3] = z;
  *(_QWORD *)&this->m[3][1] = 0;
  this->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10203B50
// Name: void MatrixSetIdentity(class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixSetIdentity(VMatrix *dst)
{
  *(_QWORD *)&dst->m[0][0] = 1065353216;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = 0.0;
  *(_QWORD *)&dst->m[1][1] = 1065353216;
  dst->m[1][3] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[2][2] = 1065353216;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10203BC0
// Name: void MatrixFromAngles(class QAngle const __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixFromAngles(const QAngle *vAngles, VMatrix *dst)
{
  VMatrix::SetupMatrixOrgAngles(this: dst, origin: &vec3_origin, vAngles);
}

//------------------------------------------------------------------------------
// Address: 0x10203BE0
// Name: void MatrixMultiply(class VMatrix const __near &,class VMatrix const __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixMultiply(VMatrix *src1, VMatrix *src2, VMatrix *dst)
{
  float *p_tmp1; // edx
  VMatrix *v4; // edi
  float *p_tmp2; // eax
  VMatrix tmp2; // [esp+Ch] [ebp-80h] BYREF
  VMatrix tmp1; // [esp+4Ch] [ebp-40h] BYREF

  p_tmp1 = (float *)&tmp1;
  if ( src1 != dst )
    p_tmp1 = (float *)src1;
  v4 = src2;
  p_tmp2 = (float *)&tmp2;
  if ( src2 != dst )
    p_tmp2 = (float *)src2;
  if ( src1 == dst && src1 != &tmp1 )
  {
    tmp1 = *src1;
    v4 = src2;
  }
  if ( v4 == dst && v4 != &tmp2 )
    tmp2 = *v4;
  dst->m[0][0] = (float)((float)((float)(p_tmp1[1] * p_tmp2[4]) + (float)(*p_tmp2 * *p_tmp1))
                       + (float)(p_tmp2[8] * p_tmp1[2]))
               + (float)(p_tmp2[12] * p_tmp1[3]);
  dst->m[0][1] = (float)((float)((float)(p_tmp1[1] * p_tmp2[5]) + (float)(*p_tmp1 * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[2]))
               + (float)(p_tmp2[13] * p_tmp1[3]);
  dst->m[0][2] = (float)((float)((float)(p_tmp1[1] * p_tmp2[6]) + (float)(*p_tmp1 * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[2]))
               + (float)(p_tmp2[14] * p_tmp1[3]);
  dst->m[0][3] = (float)((float)((float)(p_tmp1[1] * p_tmp2[7]) + (float)(*p_tmp1 * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[2]))
               + (float)(p_tmp2[15] * p_tmp1[3]);
  dst->m[1][0] = (float)((float)((float)(p_tmp1[5] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[4]))
                       + (float)(p_tmp2[8] * p_tmp1[6]))
               + (float)(p_tmp2[12] * p_tmp1[7]);
  dst->m[1][1] = (float)((float)((float)(p_tmp1[5] * p_tmp2[5]) + (float)(p_tmp1[4] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[6]))
               + (float)(p_tmp2[13] * p_tmp1[7]);
  dst->m[1][2] = (float)((float)((float)(p_tmp1[5] * p_tmp2[6]) + (float)(p_tmp1[4] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[6]))
               + (float)(p_tmp2[14] * p_tmp1[7]);
  dst->m[1][3] = (float)((float)((float)(p_tmp1[5] * p_tmp2[7]) + (float)(p_tmp1[4] * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[6]))
               + (float)(p_tmp1[7] * p_tmp2[15]);
  dst->m[2][0] = (float)((float)((float)(p_tmp1[9] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[8]))
                       + (float)(p_tmp2[8] * p_tmp1[10]))
               + (float)(p_tmp2[12] * p_tmp1[11]);
  dst->m[2][1] = (float)((float)((float)(p_tmp1[9] * p_tmp2[5]) + (float)(p_tmp1[8] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[10]))
               + (float)(p_tmp2[13] * p_tmp1[11]);
  dst->m[2][2] = (float)((float)((float)(p_tmp1[9] * p_tmp2[6]) + (float)(p_tmp1[8] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[10]))
               + (float)(p_tmp2[14] * p_tmp1[11]);
  dst->m[2][3] = (float)((float)((float)(p_tmp1[8] * p_tmp2[3]) + (float)(p_tmp1[9] * p_tmp2[7]))
                       + (float)(p_tmp2[11] * p_tmp1[10]))
               + (float)(p_tmp1[11] * p_tmp2[15]);
  dst->m[3][0] = (float)((float)((float)(p_tmp1[13] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[12]))
                       + (float)(p_tmp2[8] * p_tmp1[14]))
               + (float)(p_tmp2[12] * p_tmp1[15]);
  dst->m[3][1] = (float)((float)((float)(p_tmp1[13] * p_tmp2[5]) + (float)(p_tmp1[12] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[14]))
               + (float)(p_tmp2[13] * p_tmp1[15]);
  dst->m[3][2] = (float)((float)((float)(p_tmp1[13] * p_tmp2[6]) + (float)(p_tmp1[12] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[14]))
               + (float)(p_tmp2[14] * p_tmp1[15]);
  dst->m[3][3] = (float)((float)((float)(p_tmp1[13] * p_tmp2[7]) + (float)(p_tmp1[12] * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[14]))
               + (float)(p_tmp1[15] * p_tmp2[15]);
}

//------------------------------------------------------------------------------
// Address: 0x10203FD0
// Name: void Vector4DMultiply(class VMatrix const __near &,class Vector4D const __near &,class Vector4D __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Vector4DMultiply(const VMatrix *src1, Vector4D *src2, Vector4D *dst)
{
  Vector4D *p_tmp; // eax
  Vector4D tmp; // [esp+0h] [ebp-10h] BYREF

  p_tmp = &tmp;
  if ( src2 == dst )
    tmp = *src2;
  else
    p_tmp = src2;
  dst->x = (float)((float)((float)(src1->m[0][1] * p_tmp->y) + (float)(p_tmp->x * src1->m[0][0]))
                 + (float)(src1->m[0][2] * p_tmp->z))
         + (float)(src1->m[0][3] * p_tmp->w);
  dst->y = (float)((float)((float)(src1->m[1][1] * p_tmp->y) + (float)(src1->m[1][0] * p_tmp->x))
                 + (float)(src1->m[1][2] * p_tmp->z))
         + (float)(src1->m[1][3] * p_tmp->w);
  dst->z = (float)((float)((float)(src1->m[2][1] * p_tmp->y) + (float)(src1->m[2][0] * p_tmp->x))
                 + (float)(src1->m[2][2] * p_tmp->z))
         + (float)(src1->m[2][3] * p_tmp->w);
  dst->w = (float)((float)((float)(src1->m[3][1] * p_tmp->y) + (float)(src1->m[3][0] * p_tmp->x))
                 + (float)(src1->m[3][2] * p_tmp->z))
         + (float)(src1->m[3][3] * p_tmp->w);
}

//------------------------------------------------------------------------------
// Address: 0x10204100
// Name: void Vector3DMultiply(class VMatrix const __near &,class Vector const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Vector3DMultiply(const VMatrix *src1, Vector *src2, Vector *dst)
{
  Vector *p_tmp; // eax
  __int64 v4; // xmm0_8
  float z; // edx
  float v6; // xmm3_4
  float v7; // xmm2_4
  float v8; // xmm4_4
  Vector tmp; // [esp+0h] [ebp-18h] BYREF
  __int64 v10; // [esp+Ch] [ebp-Ch]
  float v11; // [esp+14h] [ebp-4h]

  p_tmp = src2;
  if ( src2 == dst )
    p_tmp = &tmp;
  v4 = *(_QWORD *)&p_tmp->x;
  z = p_tmp->z;
  v6 = src1->m[0][1];
  v7 = src1->m[0][0];
  v8 = src1->m[0][2];
  v10 = v4;
  v11 = z;
  dst->x = (float)((float)(v6 * *((float *)&v4 + 1)) + (float)(v7 * *(float *)&v4)) + (float)(v8 * z);
  dst->y = (float)((float)(src1->m[1][0] * *(float *)&v4) + (float)(src1->m[1][1] * *((float *)&v4 + 1)))
         + (float)(src1->m[1][2] * z);
  dst->z = (float)((float)(src1->m[2][0] * *(float *)&v4) + (float)(src1->m[2][1] * *((float *)&v4 + 1)))
         + (float)(src1->m[2][2] * z);
}

//------------------------------------------------------------------------------
// Address: 0x102041C0
// Name: void Vector3DMultiplyPositionProjective(class VMatrix const __near &,class Vector const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Vector3DMultiplyPositionProjective(const VMatrix *src1, Vector *src2, Vector *dst)
{
  Vector *p_tmp; // eax
  float z; // ecx
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm0_4
  float v8; // xmm4_4
  Vector tmp; // [esp+0h] [ebp-18h] BYREF
  __int64 v10; // [esp+Ch] [ebp-Ch]
  float v11; // [esp+14h] [ebp-4h]

  p_tmp = src2;
  if ( src2 == dst )
    p_tmp = &tmp;
  z = p_tmp->z;
  v10 = *(_QWORD *)&p_tmp->x;
  v5 = *(float *)&v10;
  v6 = *((float *)&v10 + 1);
  v11 = z;
  v7 = (float)((float)((float)(src1->m[3][0] * *(float *)&v10) + (float)(src1->m[3][1] * *((float *)&v10 + 1)))
             + (float)(src1->m[3][2] * z))
     + src1->m[3][3];
  if ( v7 != 0.0 )
    v7 = 1.0 / v7;
  dst->x = (float)((float)((float)(src1->m[0][1] * *((float *)&v10 + 1)) + (float)(src1->m[0][0] * *(float *)&v10))
                 + (float)(src1->m[0][2] * v11))
         + src1->m[0][3];
  dst->y = (float)((float)((float)(src1->m[1][0] * v5) + (float)(src1->m[1][1] * v6)) + (float)(src1->m[1][2] * z))
         + src1->m[1][3];
  v8 = (float)((float)((float)(src1->m[2][0] * v5) + (float)(src1->m[2][1] * v6)) + (float)(src1->m[2][2] * z))
     + src1->m[2][3];
  dst->x = dst->x * v7;
  dst->y = dst->y * v7;
  dst->z = v8 * v7;
}

//------------------------------------------------------------------------------
// Address: 0x10204300
// Name: void MatrixBuildTranslation(class VMatrix __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildTranslation(VMatrix *dst, float x, float y, float z)
{
  *(_QWORD *)&dst->m[0][1] = 0;
  dst->m[1][0] = 0.0;
  dst->m[1][2] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[0][3] = x;
  dst->m[1][3] = y;
  dst->m[0][0] = 1.0;
  dst->m[1][1] = 1.0;
  dst->m[2][2] = 1.0;
  dst->m[3][3] = 1.0;
  dst->m[2][3] = z;
}

//------------------------------------------------------------------------------
// Address: 0x10204380
// Name: void MatrixBuildTranslation(class VMatrix __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildTranslation(VMatrix *dst, const Vector *translation)
{
  dst->m[0][3] = 0.0;
  dst->m[1][3] = 0.0;
  dst->m[2][3] = 0.0;
  *(_QWORD *)&dst->m[0][0] = 1065353216;
  dst->m[0][2] = 0.0;
  dst->m[1][0] = 0.0;
  *(_QWORD *)&dst->m[1][1] = 1065353216;
  *(_QWORD *)&dst->m[2][0] = 0;
  dst->m[2][2] = 1.0;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[3][3] = 1.0;
  dst->m[0][3] = translation->x;
  dst->m[1][3] = translation->y;
  dst->m[2][3] = translation->z;
}

//------------------------------------------------------------------------------
// Address: 0x10204450
// Name: void MatrixBuildRotateZ(class VMatrix __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildRotateZ(VMatrix *dst, float angleDegrees)
{
  long double fSin; // [esp+0h] [ebp-4h]
  long double fSina; // [esp+0h] [ebp-4h]
  float fSinb; // [esp+0h] [ebp-4h]
  float radians; // [esp+10h] [ebp+Ch]

  radians = angleDegrees * 0.0174532925199433;
  __libm_sse2_sin(x: fSin);
  *(float *)&fSina = radians;
  __libm_sse2_cos(x: fSina);
  dst->m[0][0] = radians;
  LODWORD(dst->m[0][1]) = LODWORD(fSinb) ^ _mask__NegFloat_;
  dst->m[1][1] = radians;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = fSinb;
  *(_QWORD *)&dst->m[1][2] = 0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[2][2] = 1065353216;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10204510
// Name: void MatrixBuildScale(class VMatrix __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildScale(VMatrix *dst, unsigned int x, unsigned int y, float z)
{
  *(_QWORD *)&dst->m[0][0] = x;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = 0.0;
  *(_QWORD *)&dst->m[1][1] = y;
  dst->m[1][3] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  dst->m[2][3] = 0.0;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[2][2] = z;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10204590
// Name: class VMatrix SetupMatrixTranslation(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
VMatrix *__cdecl SetupMatrixTranslation(VMatrix *result, const Vector *vTranslation)
{
  double y; // st7
  double z; // st7

  result->m[0][3] = vTranslation->x;
  y = vTranslation->y;
  result->m[0][0] = 1.0;
  result->m[1][3] = y;
  result->m[0][1] = 0.0;
  z = vTranslation->z;
  result->m[0][2] = 0.0;
  result->m[2][3] = z;
  result->m[1][0] = 0.0;
  *(_QWORD *)&result->m[1][1] = 1065353216;
  *(_QWORD *)&result->m[2][0] = 0;
  result->m[2][2] = 1.0;
  *(_QWORD *)&result->m[3][0] = 0;
  result->m[3][2] = 0.0;
  result->m[3][3] = 1.0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10204600
// Name: class VMatrix SetupMatrixAxisRot(class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
VMatrix *__cdecl SetupMatrixAxisRot(VMatrix *result, const Vector *vAxis, float fDegrees)
{
  float v3; // xmm7_4
  float z; // xmm5_4
  float y; // xmm0_4
  float v7; // xmm4_4
  long double ty; // [esp+0h] [ebp-8h]
  long double tya; // [esp+0h] [ebp-8h]
  float tyb; // [esp+0h] [ebp-8h]
  float sx; // [esp+4h] [ebp-4h]
  float sxa; // [esp+4h] [ebp-4h]
  float sy; // [esp+18h] [ebp+10h]

  sy = fDegrees * 0.0174532925199433;
  __libm_sse2_sin(x: ty);
  *((float *)&tya + 1) = sy;
  __libm_sse2_cos(x: tya);
  v3 = sx;
  z = vAxis->z;
  y = vAxis->y;
  tyb = y * (float)(1.0 - sy);
  sxa = vAxis->x * sx;
  v7 = vAxis->x * (float)(1.0 - sy);
  result->m[0][0] = (float)(vAxis->x * v7) + sy;
  result->m[1][1] = (float)(y * tyb) + sy;
  result->m[0][1] = (float)(y * v7) - (float)(z * v3);
  result->m[2][1] = (float)(z * tyb) + sxa;
  result->m[0][2] = (float)(z * v7) + (float)(y * v3);
  result->m[2][2] = (float)((float)(z * (float)(1.0 - sy)) * z) + sy;
  result->m[0][3] = 0.0;
  result->m[1][0] = (float)(y * v7) + (float)(z * v3);
  result->m[1][2] = (float)(z * tyb) - sxa;
  result->m[1][3] = 0.0;
  result->m[2][0] = (float)(z * v7) - (float)(y * v3);
  result->m[2][3] = 0.0;
  *(_QWORD *)&result->m[3][0] = 0;
  result->m[3][2] = 0.0;
  result->m[3][3] = 1.0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10204760
// Name: class VMatrix SetupMatrixOrgAngles(class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
VMatrix *__cdecl SetupMatrixOrgAngles(VMatrix *result, const Vector *origin, const QAngle *vAngles)
{
  int v3; // ecx

  VMatrix::SetupMatrixOrgAngles(this: result, origin, vAngles);
  return (VMatrix *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x10204780
// Name: bool MatrixInverseGeneral(class VMatrix const __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl MatrixInverseGeneral(const VMatrix *src, VMatrix *dst)
{
  int v3; // edx
  _DWORD *v4; // eax
  float *v5; // ecx
  int v6; // ebx
  int v7; // edx
  int i; // edi
  int v9; // ecx
  float v10; // xmm0_4
  int v11; // eax
  float v12; // xmm1_4
  float v13; // xmm1_4
  float v14; // xmm1_4
  float v15; // xmm1_4
  float v16; // xmm1_4
  int v17; // eax
  float v18; // xmm1_4
  float *v19; // eax
  float v20; // xmm0_4
  int j; // esi
  float *v22; // ecx
  float v23; // xmm0_4
  int k; // edx
  float *v26; // ecx
  float v27; // esi
  float v28; // ecx
  float mat[4][8]; // [esp+0h] [ebp-90h] BYREF
  int rowMap[4]; // [esp+80h] [ebp-10h] BYREF

  v3 = 0;
  v4 = &mat[0][5];
  do
  {
    *(v4 - 5) = LODWORD(src->m[0][0]);
    v5 = (float *)(v4 - 5);
    v5[1] = src->m[0][1];
    v5[2] = src->m[0][2];
    v5[3] = src->m[0][3];
    *(v4 - 1) = 0;
    *v4 = 0;
    v4[1] = 0;
    v4[2] = 0;
    rowMap[v3] = v3;
    v6 = (int)&v4[v3++ - 5] + 16 - (_DWORD)rowMap;
    src = (const VMatrix *)((char *)src + 16);
    v4 += 8;
    *(int *)((char *)rowMap + v6) = 1065353216;
  }
  while ( v3 < 4 );
  v7 = 0;
  for ( i = 4; i > 0; --i )
  {
    v9 = -1;
    v10 = 0.000001;
    v11 = v7;
    if ( i >= 4 )
    {
      do
      {
        v12 = fabs(mat[rowMap[v11]][v7]);
        if ( v12 > v10 )
        {
          v9 = v11;
          v10 = v12;
        }
        v13 = fabs(mat[rowMap[v11 + 1]][v7]);
        if ( v13 > v10 )
        {
          v9 = v11 + 1;
          v10 = v13;
        }
        v14 = fabs(mat[rowMap[v11 + 2]][v7]);
        if ( v14 > v10 )
        {
          v9 = v11 + 2;
          v10 = v14;
        }
        v15 = fabs(mat[rowMap[v11 + 3]][v7]);
        if ( v15 > v10 )
        {
          v9 = v11 + 3;
          v10 = v15;
        }
        v11 += 4;
      }
      while ( v11 < 1 );
    }
    for ( ; v11 < 4; ++v11 )
    {
      v16 = fabs(mat[rowMap[v11]][v7]);
      if ( v16 > v10 )
      {
        v9 = v11;
        v10 = v16;
      }
    }
    if ( v9 == -1 )
      return 0;
    v17 = rowMap[v9];
    rowMap[v9] = rowMap[v7];
    rowMap[v7] = v17;
    v17 *= 32;
    v18 = *(float *)((char *)mat[0] + v17);
    v19 = (float *)((char *)mat[0] + v17);
    v20 = 1.0 / v19[v7];
    *v19 = v18 * v20;
    v19[1] = v19[1] * v20;
    v19[2] = v19[2] * v20;
    v19[3] = v19[3] * v20;
    v19[4] = v19[4] * v20;
    v19[5] = v19[5] * v20;
    v19[6] = v19[6] * v20;
    v19[7] = v19[7] * v20;
    v19[v7] = 1.0;
    for ( j = 0; j < 4; ++j )
    {
      if ( j != v7 )
      {
        v22 = mat[rowMap[j]];
        v23 = -v22[v7];
        *v22 = (float)(*v19 * v23) + *v22;
        v22[1] = (float)(v19[1] * v23) + v22[1];
        v22[2] = (float)(v19[2] * v23) + v22[2];
        v22[3] = (float)(v19[3] * v23) + v22[3];
        v22[4] = (float)(v19[4] * v23) + v22[4];
        v22[5] = (float)(v19[5] * v23) + v22[5];
        v22[6] = (float)(v19[6] * v23) + v22[6];
        v22[7] = (float)(v19[7] * v23) + v22[7];
        v22[v7] = 0.0;
      }
    }
    ++v7;
  }
  for ( k = 0; k < 4; ++k )
  {
    v26 = &mat[rowMap[k]][4];
    dst->m[0][0] = *v26;
    dst->m[0][1] = v26[1];
    v27 = v26[2];
    v28 = v26[3];
    dst->m[0][2] = v27;
    dst->m[0][3] = v28;
    dst = (VMatrix *)((char *)dst + 16);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10204AA0
// Name: void MatrixInverseTR(class VMatrix const __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixInverseTR(const VMatrix *src, VMatrix *dst)
{
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm4_4
  float v8; // xmm5_4
  float v9; // xmm1_4
  float v10; // xmm0_4

  dst->m[0][0] = src->m[0][0];
  dst->m[0][1] = src->m[1][0];
  dst->m[0][2] = src->m[2][0];
  dst->m[1][0] = src->m[0][1];
  dst->m[1][1] = src->m[1][1];
  dst->m[1][2] = src->m[2][1];
  dst->m[2][0] = src->m[0][2];
  dst->m[2][1] = src->m[1][2];
  dst->m[2][2] = src->m[2][2];
  v3 = -src->m[0][3];
  v4 = -src->m[1][3];
  v5 = -src->m[2][3];
  v6 = (float)((float)(dst->m[0][0] * v3) + (float)(v4 * dst->m[0][1])) + (float)(dst->m[0][2] * v5);
  v7 = (float)((float)(dst->m[1][1] * v4) + (float)(dst->m[1][0] * v3)) + (float)(v5 * dst->m[1][2]);
  v8 = dst->m[2][1] * v4;
  v9 = dst->m[2][0] * v3;
  v10 = dst->m[2][2] * v5;
  dst->m[0][3] = v6;
  dst->m[1][3] = v7;
  dst->m[2][3] = (float)(v8 + v9) + v10;
  *(_QWORD *)&dst->m[3][1] = 0;
  dst->m[3][0] = 0.0;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10204BA0
// Name: public: void VMatrix::InverseTR(class VMatrix __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall VMatrix::InverseTR(VMatrix *this, VMatrix *ret)
{
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm4_4
  float v8; // xmm5_4
  float v9; // xmm1_4
  float v10; // xmm0_4

  ret->m[0][0] = this->m[0][0];
  ret->m[0][1] = this->m[1][0];
  ret->m[0][2] = this->m[2][0];
  ret->m[1][0] = this->m[0][1];
  ret->m[1][1] = this->m[1][1];
  ret->m[1][2] = this->m[2][1];
  ret->m[2][0] = this->m[0][2];
  ret->m[2][1] = this->m[1][2];
  ret->m[2][2] = this->m[2][2];
  v3 = -this->m[0][3];
  v4 = -this->m[1][3];
  v5 = -this->m[2][3];
  v6 = (float)((float)(ret->m[0][0] * v3) + (float)(v4 * ret->m[0][1])) + (float)(ret->m[0][2] * v5);
  v7 = (float)((float)(ret->m[1][1] * v4) + (float)(ret->m[1][0] * v3)) + (float)(v5 * ret->m[1][2]);
  v8 = ret->m[2][1] * v4;
  v9 = ret->m[2][0] * v3;
  v10 = ret->m[2][2] * v5;
  ret->m[0][3] = v6;
  ret->m[1][3] = v7;
  ret->m[2][3] = (float)(v8 + v9) + v10;
  *(_QWORD *)&ret->m[3][1] = 0;
  ret->m[3][0] = 0.0;
  ret->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10204CA0
// Name: public: class VMatrix VMatrix::Scale(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
VMatrix *__thiscall VMatrix::Scale(VMatrix *this, VMatrix *result, const Vector *vScale)
{
  float x; // xmm0_4
  float v5; // xmm2_4
  float v6; // xmm3_4
  float y; // xmm1_4
  float z; // xmm2_4
  float v9; // xmm3_4

  result->m[0][3] = this->m[0][3];
  x = vScale->x;
  v5 = this->m[0][1];
  result->m[1][3] = this->m[1][3];
  v6 = this->m[0][2];
  result->m[2][3] = this->m[2][3];
  result->m[0][0] = x * this->m[0][0];
  y = vScale->y;
  result->m[0][1] = v5 * y;
  z = vScale->z;
  result->m[0][2] = v6 * z;
  result->m[1][0] = this->m[1][0] * x;
  result->m[1][1] = this->m[1][1] * y;
  result->m[1][2] = this->m[1][2] * z;
  result->m[2][0] = this->m[2][0] * x;
  result->m[2][1] = this->m[2][1] * y;
  result->m[2][2] = this->m[2][2] * z;
  v9 = this->m[3][0] * x;
  result->m[3][1] = this->m[3][1] * y;
  result->m[3][2] = this->m[3][2] * z;
  result->m[3][0] = v9;
  result->m[3][3] = 1.0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10204D80
// Name: public: bool VMatrix::InverseGeneral(class VMatrix __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall VMatrix::InverseGeneral(VMatrix *this, VMatrix *vInverse)
{
  return MatrixInverseGeneral(src: this, dst: vInverse);
}

//------------------------------------------------------------------------------
// Address: 0x10204DA0
// Name: bool PlaneIntersection(class VPlane const __near &,class VPlane const __near &,class VPlane const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl PlaneIntersection(const VPlane *vp1, const VPlane *vp2, const VPlane *vp3, Vector *vOut)
{
  float m_Dist; // xmm1_4
  float v5; // xmm1_4
  VMatrix mInverse; // [esp+0h] [ebp-80h] BYREF
  VMatrix mMat; // [esp+40h] [ebp-40h] BYREF

  m_Dist = vp1->m_Dist;
  *(Vector *)&mMat.m[0][0] = vp1->m_Normal;
  mMat.m[0][3] = -m_Dist;
  *(Vector *)&mMat.m[1][0] = vp2->m_Normal;
  mMat.m[1][3] = -vp2->m_Dist;
  *(Vector *)&mMat.m[2][0] = vp3->m_Normal;
  v5 = -vp3->m_Dist;
  *(_QWORD *)&mMat.m[3][0] = 0;
  *(_QWORD *)&mMat.m[3][2] = 0x3F80000000000000LL;
  mMat.m[2][3] = v5;
  if ( MatrixInverseGeneral(src: &mMat, dst: &mInverse) == 0 )
    return 0;
  vOut->x = mInverse.m[0][3];
  vOut->y = mInverse.m[1][3];
  vOut->z = mInverse.m[2][3];
  return 1;
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x0049B0F0
// Name: public: class VMatrix __near & VMatrix::operator=(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
VMatrix *__thiscall VMatrix::operator=(VMatrix *this, const VMatrix *mOther)
{
  *this = *mOther;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0049B160
// Name: public: bool VMatrix::operator==(class VMatrix const __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall VMatrix::operator==(VMatrix *this, const VMatrix *src)
{
  unsigned int v3; // eax

  v3 = 64;
  while ( LODWORD(src->m[0][0]) == LODWORD(this->m[0][0]) )
  {
    v3 -= 4;
    this = (VMatrix *)((char *)this + 4);
    src = (const VMatrix *)((char *)src + 4);
    if ( v3 < 4 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0049B1D0
// Name: void MatrixSetIdentity(class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixSetIdentity(VMatrix *dst)
{
  *(_QWORD *)&dst->m[0][0] = 1065353216;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = 0.0;
  *(_QWORD *)&dst->m[1][1] = 1065353216;
  dst->m[1][3] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[2][2] = 1065353216;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x0049B240
// Name: void MatrixMultiply(class VMatrix const __near &,class VMatrix const __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixMultiply(const VMatrix *src1, const VMatrix *src2, VMatrix *dst)
{
  float *p_tmp1; // edx
  VMatrix *v4; // edi
  float *p_tmp2; // eax
  VMatrix tmp2; // [esp+Ch] [ebp-80h] BYREF
  VMatrix tmp1; // [esp+4Ch] [ebp-40h] BYREF

  p_tmp1 = (float *)&tmp1;
  if ( src1 != dst )
    p_tmp1 = (float *)src1;
  v4 = src2;
  p_tmp2 = (float *)&tmp2;
  if ( src2 != dst )
    p_tmp2 = (float *)src2;
  if ( src1 == dst && src1 != &tmp1 )
  {
    tmp1 = *src1;
    v4 = src2;
  }
  if ( v4 == dst && v4 != &tmp2 )
    tmp2 = *v4;
  dst->m[0][0] = (float)((float)((float)(p_tmp1[1] * p_tmp2[4]) + (float)(*p_tmp2 * *p_tmp1))
                       + (float)(p_tmp2[8] * p_tmp1[2]))
               + (float)(p_tmp2[12] * p_tmp1[3]);
  dst->m[0][1] = (float)((float)((float)(p_tmp1[1] * p_tmp2[5]) + (float)(*p_tmp1 * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[2]))
               + (float)(p_tmp2[13] * p_tmp1[3]);
  dst->m[0][2] = (float)((float)((float)(p_tmp1[1] * p_tmp2[6]) + (float)(*p_tmp1 * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[2]))
               + (float)(p_tmp2[14] * p_tmp1[3]);
  dst->m[0][3] = (float)((float)((float)(p_tmp1[1] * p_tmp2[7]) + (float)(*p_tmp1 * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[2]))
               + (float)(p_tmp2[15] * p_tmp1[3]);
  dst->m[1][0] = (float)((float)((float)(p_tmp1[5] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[4]))
                       + (float)(p_tmp2[8] * p_tmp1[6]))
               + (float)(p_tmp2[12] * p_tmp1[7]);
  dst->m[1][1] = (float)((float)((float)(p_tmp1[5] * p_tmp2[5]) + (float)(p_tmp1[4] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[6]))
               + (float)(p_tmp2[13] * p_tmp1[7]);
  dst->m[1][2] = (float)((float)((float)(p_tmp1[5] * p_tmp2[6]) + (float)(p_tmp1[4] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[6]))
               + (float)(p_tmp2[14] * p_tmp1[7]);
  dst->m[1][3] = (float)((float)((float)(p_tmp1[5] * p_tmp2[7]) + (float)(p_tmp1[4] * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[6]))
               + (float)(p_tmp1[7] * p_tmp2[15]);
  dst->m[2][0] = (float)((float)((float)(p_tmp1[9] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[8]))
                       + (float)(p_tmp2[8] * p_tmp1[10]))
               + (float)(p_tmp2[12] * p_tmp1[11]);
  dst->m[2][1] = (float)((float)((float)(p_tmp1[9] * p_tmp2[5]) + (float)(p_tmp1[8] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[10]))
               + (float)(p_tmp2[13] * p_tmp1[11]);
  dst->m[2][2] = (float)((float)((float)(p_tmp1[9] * p_tmp2[6]) + (float)(p_tmp1[8] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[10]))
               + (float)(p_tmp2[14] * p_tmp1[11]);
  dst->m[2][3] = (float)((float)((float)(p_tmp1[8] * p_tmp2[3]) + (float)(p_tmp1[9] * p_tmp2[7]))
                       + (float)(p_tmp2[11] * p_tmp1[10]))
               + (float)(p_tmp1[11] * p_tmp2[15]);
  dst->m[3][0] = (float)((float)((float)(p_tmp1[13] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[12]))
                       + (float)(p_tmp2[8] * p_tmp1[14]))
               + (float)(p_tmp2[12] * p_tmp1[15]);
  dst->m[3][1] = (float)((float)((float)(p_tmp1[13] * p_tmp2[5]) + (float)(p_tmp1[12] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[14]))
               + (float)(p_tmp2[13] * p_tmp1[15]);
  dst->m[3][2] = (float)((float)((float)(p_tmp1[13] * p_tmp2[6]) + (float)(p_tmp1[12] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[14]))
               + (float)(p_tmp2[14] * p_tmp1[15]);
  dst->m[3][3] = (float)((float)((float)(p_tmp1[13] * p_tmp2[7]) + (float)(p_tmp1[12] * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[14]))
               + (float)(p_tmp1[15] * p_tmp2[15]);
}

//------------------------------------------------------------------------------
// Address: 0x0049B630
// Name: void MatrixBuildTranslation(class VMatrix __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildTranslation(VMatrix *dst, float x, float y, float z)
{
  *(_QWORD *)&dst->m[0][1] = 0;
  dst->m[1][0] = 0.0;
  dst->m[1][2] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[0][3] = x;
  dst->m[1][3] = y;
  dst->m[0][0] = 1.0;
  dst->m[1][1] = 1.0;
  dst->m[2][2] = 1.0;
  dst->m[3][3] = 1.0;
  dst->m[2][3] = z;
}

//------------------------------------------------------------------------------
// Address: 0x0049B700
// Name: void MatrixBuildRotateZ(class VMatrix __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildRotateZ(VMatrix *dst, float angleDegrees)
{
  long double fSin; // [esp+0h] [ebp-4h]
  long double fSina; // [esp+0h] [ebp-4h]
  float fSinb; // [esp+0h] [ebp-4h]
  float radians; // [esp+10h] [ebp+Ch]

  radians = angleDegrees * 0.0174532925199433;
  __libm_sse2_sin(x: fSin);
  *(float *)&fSina = radians;
  __libm_sse2_cos(x: fSina);
  dst->m[0][0] = radians;
  LODWORD(dst->m[0][1]) = LODWORD(fSinb) ^ _mask__NegFloat_;
  dst->m[1][1] = radians;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = fSinb;
  *(_QWORD *)&dst->m[1][2] = 0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[2][2] = 1065353216;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x0049B7C0
// Name: void MatrixBuildScale(class VMatrix __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildScale(VMatrix *dst, unsigned int x, unsigned int y, float z)
{
  *(_QWORD *)&dst->m[0][0] = x;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = 0.0;
  *(_QWORD *)&dst->m[1][1] = y;
  dst->m[1][3] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  dst->m[2][3] = 0.0;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[2][2] = z;
  dst->m[3][3] = 1.0;
}

} // namespace hlmv

// ============================================================
// Overlay from makegamedata (Missing functions)
// ============================================================
namespace makegamedata {

//------------------------------------------------------------------------------
// Address: 0x005274F0
// Name: public: class VMatrix __near & VMatrix::operator=(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
VMatrix *__thiscall VMatrix::operator=(VMatrix *this, const VMatrix *mOther)
{
  *this = *mOther;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00527560
// Name: public: bool VMatrix::operator==(class VMatrix const __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall VMatrix::operator==(VMatrix *this, const VMatrix *src)
{
  unsigned int v3; // eax

  v3 = 64;
  while ( LODWORD(src->m[0][0]) == LODWORD(this->m[0][0]) )
  {
    v3 -= 4;
    this = (VMatrix *)((char *)this + 4);
    src = (const VMatrix *)((char *)src + 4);
    if ( v3 < 4 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x005275D0
// Name: void MatrixSetIdentity(class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixSetIdentity(VMatrix *dst)
{
  *(_QWORD *)&dst->m[0][0] = 1065353216;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = 0.0;
  *(_QWORD *)&dst->m[1][1] = 1065353216;
  dst->m[1][3] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[2][2] = 1065353216;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x00527640
// Name: void MatrixMultiply(class VMatrix const __near &,class VMatrix const __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixMultiply(const VMatrix *src1, const VMatrix *src2, VMatrix *dst)
{
  float *p_tmp1; // edx
  VMatrix *v4; // edi
  float *p_tmp2; // eax
  VMatrix tmp2; // [esp+Ch] [ebp-80h] BYREF
  VMatrix tmp1; // [esp+4Ch] [ebp-40h] BYREF

  p_tmp1 = (float *)&tmp1;
  if ( src1 != dst )
    p_tmp1 = (float *)src1;
  v4 = src2;
  p_tmp2 = (float *)&tmp2;
  if ( src2 != dst )
    p_tmp2 = (float *)src2;
  if ( src1 == dst && src1 != &tmp1 )
  {
    tmp1 = *src1;
    v4 = src2;
  }
  if ( v4 == dst && v4 != &tmp2 )
    tmp2 = *v4;
  dst->m[0][0] = (float)((float)((float)(p_tmp1[1] * p_tmp2[4]) + (float)(*p_tmp2 * *p_tmp1))
                       + (float)(p_tmp2[8] * p_tmp1[2]))
               + (float)(p_tmp2[12] * p_tmp1[3]);
  dst->m[0][1] = (float)((float)((float)(p_tmp1[1] * p_tmp2[5]) + (float)(*p_tmp1 * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[2]))
               + (float)(p_tmp2[13] * p_tmp1[3]);
  dst->m[0][2] = (float)((float)((float)(p_tmp1[1] * p_tmp2[6]) + (float)(*p_tmp1 * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[2]))
               + (float)(p_tmp2[14] * p_tmp1[3]);
  dst->m[0][3] = (float)((float)((float)(p_tmp1[1] * p_tmp2[7]) + (float)(*p_tmp1 * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[2]))
               + (float)(p_tmp2[15] * p_tmp1[3]);
  dst->m[1][0] = (float)((float)((float)(p_tmp1[5] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[4]))
                       + (float)(p_tmp2[8] * p_tmp1[6]))
               + (float)(p_tmp2[12] * p_tmp1[7]);
  dst->m[1][1] = (float)((float)((float)(p_tmp1[5] * p_tmp2[5]) + (float)(p_tmp1[4] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[6]))
               + (float)(p_tmp2[13] * p_tmp1[7]);
  dst->m[1][2] = (float)((float)((float)(p_tmp1[5] * p_tmp2[6]) + (float)(p_tmp1[4] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[6]))
               + (float)(p_tmp2[14] * p_tmp1[7]);
  dst->m[1][3] = (float)((float)((float)(p_tmp1[5] * p_tmp2[7]) + (float)(p_tmp1[4] * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[6]))
               + (float)(p_tmp1[7] * p_tmp2[15]);
  dst->m[2][0] = (float)((float)((float)(p_tmp1[9] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[8]))
                       + (float)(p_tmp2[8] * p_tmp1[10]))
               + (float)(p_tmp2[12] * p_tmp1[11]);
  dst->m[2][1] = (float)((float)((float)(p_tmp1[9] * p_tmp2[5]) + (float)(p_tmp1[8] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[10]))
               + (float)(p_tmp2[13] * p_tmp1[11]);
  dst->m[2][2] = (float)((float)((float)(p_tmp1[9] * p_tmp2[6]) + (float)(p_tmp1[8] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[10]))
               + (float)(p_tmp2[14] * p_tmp1[11]);
  dst->m[2][3] = (float)((float)((float)(p_tmp1[8] * p_tmp2[3]) + (float)(p_tmp1[9] * p_tmp2[7]))
                       + (float)(p_tmp2[11] * p_tmp1[10]))
               + (float)(p_tmp1[11] * p_tmp2[15]);
  dst->m[3][0] = (float)((float)((float)(p_tmp1[13] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[12]))
                       + (float)(p_tmp2[8] * p_tmp1[14]))
               + (float)(p_tmp2[12] * p_tmp1[15]);
  dst->m[3][1] = (float)((float)((float)(p_tmp1[13] * p_tmp2[5]) + (float)(p_tmp1[12] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[14]))
               + (float)(p_tmp2[13] * p_tmp1[15]);
  dst->m[3][2] = (float)((float)((float)(p_tmp1[13] * p_tmp2[6]) + (float)(p_tmp1[12] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[14]))
               + (float)(p_tmp2[14] * p_tmp1[15]);
  dst->m[3][3] = (float)((float)((float)(p_tmp1[13] * p_tmp2[7]) + (float)(p_tmp1[12] * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[14]))
               + (float)(p_tmp1[15] * p_tmp2[15]);
}

//------------------------------------------------------------------------------
// Address: 0x00527A30
// Name: void MatrixBuildTranslation(class VMatrix __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildTranslation(VMatrix *dst, float x, float y, float z)
{
  *(_QWORD *)&dst->m[0][1] = 0;
  dst->m[1][0] = 0.0;
  dst->m[1][2] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[0][3] = x;
  dst->m[1][3] = y;
  dst->m[0][0] = 1.0;
  dst->m[1][1] = 1.0;
  dst->m[2][2] = 1.0;
  dst->m[3][3] = 1.0;
  dst->m[2][3] = z;
}

//------------------------------------------------------------------------------
// Address: 0x00527AB0
// Name: void MatrixBuildRotateZ(class VMatrix __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildRotateZ(VMatrix *dst, float angleDegrees)
{
  long double fSin; // [esp+0h] [ebp-4h]
  long double fSina; // [esp+0h] [ebp-4h]
  float fSinb; // [esp+0h] [ebp-4h]
  float radians; // [esp+10h] [ebp+Ch]

  radians = angleDegrees * 0.0174532925199433;
  __libm_sse2_sin(x: fSin);
  *(float *)&fSina = radians;
  __libm_sse2_cos(x: fSina);
  dst->m[0][0] = radians;
  LODWORD(dst->m[0][1]) = LODWORD(fSinb) ^ _mask__NegFloat_;
  dst->m[1][1] = radians;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = fSinb;
  *(_QWORD *)&dst->m[1][2] = 0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[2][2] = 1065353216;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x00527B70
// Name: void MatrixBuildScale(class VMatrix __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildScale(VMatrix *dst, unsigned int x, unsigned int y, float z)
{
  *(_QWORD *)&dst->m[0][0] = x;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = 0.0;
  *(_QWORD *)&dst->m[1][1] = y;
  dst->m[1][3] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  dst->m[2][3] = 0.0;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[2][2] = z;
  dst->m[3][3] = 1.0;
}

} // namespace makegamedata

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004DFAE0
// Name: public: class VMatrix __near & VMatrix::operator=(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
VMatrix *__thiscall VMatrix::operator=(VMatrix *this, const VMatrix *mOther)
{
  *this = *mOther;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004DFB50
// Name: public: bool VMatrix::operator==(class VMatrix const __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall VMatrix::operator==(VMatrix *this, const VMatrix *src)
{
  unsigned int v3; // eax

  v3 = 64;
  while ( LODWORD(src->m[0][0]) == LODWORD(this->m[0][0]) )
  {
    v3 -= 4;
    this = (VMatrix *)((char *)this + 4);
    src = (const VMatrix *)((char *)src + 4);
    if ( v3 < 4 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004DFBC0
// Name: void MatrixSetIdentity(class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixSetIdentity(VMatrix *dst)
{
  *(_QWORD *)&dst->m[0][0] = 1065353216;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = 0.0;
  *(_QWORD *)&dst->m[1][1] = 1065353216;
  dst->m[1][3] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[2][2] = 1065353216;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x004DFC30
// Name: void MatrixTranspose(class VMatrix const __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixTranspose(const VMatrix *src, VMatrix *dst)
{
  float v2; // xmm0_4
  float v3; // xmm0_4
  float v4; // xmm0_4
  float v5; // xmm0_4
  float v6; // xmm0_4
  float v7; // xmm0_4

  if ( src == dst )
  {
    v2 = dst->m[0][1];
    dst->m[0][1] = dst->m[1][0];
    dst->m[1][0] = v2;
    v3 = dst->m[0][2];
    dst->m[0][2] = dst->m[2][0];
    dst->m[2][0] = v3;
    v4 = dst->m[0][3];
    dst->m[0][3] = dst->m[3][0];
    dst->m[3][0] = v4;
    v5 = dst->m[1][2];
    dst->m[1][2] = dst->m[2][1];
    dst->m[2][1] = v5;
    v6 = dst->m[1][3];
    dst->m[1][3] = dst->m[3][1];
    dst->m[3][1] = v6;
    v7 = dst->m[2][3];
    dst->m[2][3] = dst->m[3][2];
    dst->m[3][2] = v7;
  }
  else
  {
    dst->m[0][0] = src->m[0][0];
    dst->m[0][1] = src->m[1][0];
    dst->m[0][2] = src->m[2][0];
    dst->m[0][3] = src->m[3][0];
    dst->m[1][0] = src->m[0][1];
    dst->m[1][1] = src->m[1][1];
    dst->m[1][2] = src->m[2][1];
    dst->m[1][3] = src->m[3][1];
    dst->m[2][0] = src->m[0][2];
    dst->m[2][1] = src->m[1][2];
    dst->m[2][2] = src->m[2][2];
    dst->m[2][3] = src->m[3][2];
    dst->m[3][0] = src->m[0][3];
    dst->m[3][1] = src->m[1][3];
    dst->m[3][2] = src->m[2][3];
    dst->m[3][3] = src->m[3][3];
  }
}

//------------------------------------------------------------------------------
// Address: 0x004DFD00
// Name: void MatrixMultiply(class VMatrix const __near &,class VMatrix const __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixMultiply(const VMatrix *src1, const VMatrix *src2, VMatrix *dst)
{
  float *p_tmp1; // edx
  VMatrix *v4; // edi
  float *p_tmp2; // eax
  VMatrix tmp2; // [esp+Ch] [ebp-80h] BYREF
  VMatrix tmp1; // [esp+4Ch] [ebp-40h] BYREF

  p_tmp1 = (float *)&tmp1;
  if ( src1 != dst )
    p_tmp1 = (float *)src1;
  v4 = src2;
  p_tmp2 = (float *)&tmp2;
  if ( src2 != dst )
    p_tmp2 = (float *)src2;
  if ( src1 == dst && src1 != &tmp1 )
  {
    tmp1 = *src1;
    v4 = src2;
  }
  if ( v4 == dst && v4 != &tmp2 )
    tmp2 = *v4;
  dst->m[0][0] = (float)((float)((float)(p_tmp1[1] * p_tmp2[4]) + (float)(*p_tmp2 * *p_tmp1))
                       + (float)(p_tmp2[8] * p_tmp1[2]))
               + (float)(p_tmp2[12] * p_tmp1[3]);
  dst->m[0][1] = (float)((float)((float)(p_tmp1[1] * p_tmp2[5]) + (float)(*p_tmp1 * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[2]))
               + (float)(p_tmp2[13] * p_tmp1[3]);
  dst->m[0][2] = (float)((float)((float)(p_tmp1[1] * p_tmp2[6]) + (float)(*p_tmp1 * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[2]))
               + (float)(p_tmp2[14] * p_tmp1[3]);
  dst->m[0][3] = (float)((float)((float)(p_tmp1[1] * p_tmp2[7]) + (float)(*p_tmp1 * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[2]))
               + (float)(p_tmp2[15] * p_tmp1[3]);
  dst->m[1][0] = (float)((float)((float)(p_tmp1[5] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[4]))
                       + (float)(p_tmp2[8] * p_tmp1[6]))
               + (float)(p_tmp2[12] * p_tmp1[7]);
  dst->m[1][1] = (float)((float)((float)(p_tmp1[5] * p_tmp2[5]) + (float)(p_tmp1[4] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[6]))
               + (float)(p_tmp2[13] * p_tmp1[7]);
  dst->m[1][2] = (float)((float)((float)(p_tmp1[5] * p_tmp2[6]) + (float)(p_tmp1[4] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[6]))
               + (float)(p_tmp2[14] * p_tmp1[7]);
  dst->m[1][3] = (float)((float)((float)(p_tmp1[5] * p_tmp2[7]) + (float)(p_tmp1[4] * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[6]))
               + (float)(p_tmp1[7] * p_tmp2[15]);
  dst->m[2][0] = (float)((float)((float)(p_tmp1[9] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[8]))
                       + (float)(p_tmp2[8] * p_tmp1[10]))
               + (float)(p_tmp2[12] * p_tmp1[11]);
  dst->m[2][1] = (float)((float)((float)(p_tmp1[9] * p_tmp2[5]) + (float)(p_tmp1[8] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[10]))
               + (float)(p_tmp2[13] * p_tmp1[11]);
  dst->m[2][2] = (float)((float)((float)(p_tmp1[9] * p_tmp2[6]) + (float)(p_tmp1[8] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[10]))
               + (float)(p_tmp2[14] * p_tmp1[11]);
  dst->m[2][3] = (float)((float)((float)(p_tmp1[8] * p_tmp2[3]) + (float)(p_tmp1[9] * p_tmp2[7]))
                       + (float)(p_tmp2[11] * p_tmp1[10]))
               + (float)(p_tmp1[11] * p_tmp2[15]);
  dst->m[3][0] = (float)((float)((float)(p_tmp1[13] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[12]))
                       + (float)(p_tmp2[8] * p_tmp1[14]))
               + (float)(p_tmp2[12] * p_tmp1[15]);
  dst->m[3][1] = (float)((float)((float)(p_tmp1[13] * p_tmp2[5]) + (float)(p_tmp1[12] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[14]))
               + (float)(p_tmp2[13] * p_tmp1[15]);
  dst->m[3][2] = (float)((float)((float)(p_tmp1[13] * p_tmp2[6]) + (float)(p_tmp1[12] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[14]))
               + (float)(p_tmp2[14] * p_tmp1[15]);
  dst->m[3][3] = (float)((float)((float)(p_tmp1[13] * p_tmp2[7]) + (float)(p_tmp1[12] * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[14]))
               + (float)(p_tmp1[15] * p_tmp2[15]);
}

//------------------------------------------------------------------------------
// Address: 0x004E00F0
// Name: void MatrixBuildTranslation(class VMatrix __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildTranslation(VMatrix *dst, float x, float y, float z)
{
  *(_QWORD *)&dst->m[0][1] = 0;
  dst->m[1][0] = 0.0;
  dst->m[1][2] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[0][3] = x;
  dst->m[1][3] = y;
  dst->m[0][0] = 1.0;
  dst->m[1][1] = 1.0;
  dst->m[2][2] = 1.0;
  dst->m[3][3] = 1.0;
  dst->m[2][3] = z;
}

//------------------------------------------------------------------------------
// Address: 0x004E01C0
// Name: void MatrixBuildRotateZ(class VMatrix __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildRotateZ(VMatrix *dst, float angleDegrees)
{
  long double fSin; // [esp+0h] [ebp-4h]
  long double fSina; // [esp+0h] [ebp-4h]
  float fSinb; // [esp+0h] [ebp-4h]
  float radians; // [esp+10h] [ebp+Ch]

  radians = angleDegrees * 0.0174532925199433;
  __libm_sse2_sin(x: fSin);
  *(float *)&fSina = radians;
  __libm_sse2_cos(x: fSina);
  dst->m[0][0] = radians;
  LODWORD(dst->m[0][1]) = LODWORD(fSinb) ^ _mask__NegFloat_;
  dst->m[1][1] = radians;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = fSinb;
  *(_QWORD *)&dst->m[1][2] = 0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[2][2] = 1065353216;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x004E0280
// Name: void MatrixBuildScale(class VMatrix __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildScale(VMatrix *dst, unsigned int x, unsigned int y, float z)
{
  *(_QWORD *)&dst->m[0][0] = x;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = 0.0;
  *(_QWORD *)&dst->m[1][1] = y;
  dst->m[1][3] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  dst->m[2][3] = 0.0;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[2][2] = z;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x004E0300
// Name: bool MatrixInverseGeneral(class VMatrix const __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl MatrixInverseGeneral(const VMatrix *src, VMatrix *dst)
{
  int v3; // edx
  _DWORD *v4; // eax
  float *v5; // ecx
  int v6; // ebx
  int v7; // edx
  int i; // edi
  int v9; // ecx
  float v10; // xmm0_4
  int v11; // eax
  float v12; // xmm1_4
  float v13; // xmm1_4
  float v14; // xmm1_4
  float v15; // xmm1_4
  float v16; // xmm1_4
  int v17; // eax
  float v18; // xmm1_4
  float *v19; // eax
  float v20; // xmm0_4
  int j; // esi
  float *v22; // ecx
  float v23; // xmm0_4
  int k; // edx
  float *v26; // ecx
  float v27; // esi
  float v28; // ecx
  float mat[4][8]; // [esp+0h] [ebp-90h] BYREF
  int rowMap[4]; // [esp+80h] [ebp-10h] BYREF

  v3 = 0;
  v4 = &mat[0][5];
  do
  {
    *(v4 - 5) = LODWORD(src->m[0][0]);
    v5 = (float *)(v4 - 5);
    v5[1] = src->m[0][1];
    v5[2] = src->m[0][2];
    v5[3] = src->m[0][3];
    *(v4 - 1) = 0;
    *v4 = 0;
    v4[1] = 0;
    v4[2] = 0;
    rowMap[v3] = v3;
    v6 = (int)&v4[v3++ - 5] + 16 - (_DWORD)rowMap;
    src = (const VMatrix *)((char *)src + 16);
    v4 += 8;
    *(int *)((char *)rowMap + v6) = 1065353216;
  }
  while ( v3 < 4 );
  v7 = 0;
  for ( i = 4; i > 0; --i )
  {
    v9 = -1;
    v10 = 0.000001;
    v11 = v7;
    if ( i >= 4 )
    {
      do
      {
        v12 = fabs(mat[rowMap[v11]][v7]);
        if ( v12 > v10 )
        {
          v9 = v11;
          v10 = v12;
        }
        v13 = fabs(mat[rowMap[v11 + 1]][v7]);
        if ( v13 > v10 )
        {
          v9 = v11 + 1;
          v10 = v13;
        }
        v14 = fabs(mat[rowMap[v11 + 2]][v7]);
        if ( v14 > v10 )
        {
          v9 = v11 + 2;
          v10 = v14;
        }
        v15 = fabs(mat[rowMap[v11 + 3]][v7]);
        if ( v15 > v10 )
        {
          v9 = v11 + 3;
          v10 = v15;
        }
        v11 += 4;
      }
      while ( v11 < 1 );
    }
    for ( ; v11 < 4; ++v11 )
    {
      v16 = fabs(mat[rowMap[v11]][v7]);
      if ( v16 > v10 )
      {
        v9 = v11;
        v10 = v16;
      }
    }
    if ( v9 == -1 )
      return 0;
    v17 = rowMap[v9];
    rowMap[v9] = rowMap[v7];
    rowMap[v7] = v17;
    v17 *= 32;
    v18 = *(float *)((char *)mat[0] + v17);
    v19 = (float *)((char *)mat[0] + v17);
    v20 = 1.0 / v19[v7];
    *v19 = v18 * v20;
    v19[1] = v19[1] * v20;
    v19[2] = v19[2] * v20;
    v19[3] = v19[3] * v20;
    v19[4] = v19[4] * v20;
    v19[5] = v19[5] * v20;
    v19[6] = v19[6] * v20;
    v19[7] = v19[7] * v20;
    v19[v7] = 1.0;
    for ( j = 0; j < 4; ++j )
    {
      if ( j != v7 )
      {
        v22 = mat[rowMap[j]];
        v23 = -v22[v7];
        *v22 = (float)(*v19 * v23) + *v22;
        v22[1] = (float)(v19[1] * v23) + v22[1];
        v22[2] = (float)(v19[2] * v23) + v22[2];
        v22[3] = (float)(v19[3] * v23) + v22[3];
        v22[4] = (float)(v19[4] * v23) + v22[4];
        v22[5] = (float)(v19[5] * v23) + v22[5];
        v22[6] = (float)(v19[6] * v23) + v22[6];
        v22[7] = (float)(v19[7] * v23) + v22[7];
        v22[v7] = 0.0;
      }
    }
    ++v7;
  }
  for ( k = 0; k < 4; ++k )
  {
    v26 = &mat[rowMap[k]][4];
    dst->m[0][0] = *v26;
    dst->m[0][1] = v26[1];
    v27 = v26[2];
    v28 = v26[3];
    dst->m[0][2] = v27;
    dst->m[0][3] = v28;
    dst = (VMatrix *)((char *)dst + 16);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004E0620
// Name: void MatrixInverseTranspose(struct matrix3x4_t const __near &,struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixInverseTranspose(const matrix3x4_t *src, matrix3x4_t *dst)
{
  VMatrix out; // [esp+0h] [ebp-80h] BYREF
  VMatrix tmp; // [esp+40h] [ebp-40h] BYREF

  *(matrix3x4_t *)&tmp.m[0][0] = *src;
  memset(tmp.m[3], 0, 12);
  tmp.m[3][3] = 1.0;
  MatrixInverseGeneral(src: &tmp, dst: &out);
  MatrixTranspose(src: &out, dst: &out);
  *dst = *(matrix3x4_t *)&out.m[0][0];
}

} // namespace mdlcompile

// ============================================================
// Overlay from mksheet (Missing functions)
// ============================================================
namespace mksheet {

//------------------------------------------------------------------------------
// Address: 0x00463750
// Name: public: class VMatrix __near & VMatrix::operator=(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
VMatrix *__thiscall VMatrix::operator=(VMatrix *this, const VMatrix *mOther)
{
  *this = *mOther;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004637C0
// Name: public: bool VMatrix::operator==(class VMatrix const __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall VMatrix::operator==(VMatrix *this, const VMatrix *src)
{
  unsigned int v3; // eax

  v3 = 64;
  while ( LODWORD(src->m[0][0]) == LODWORD(this->m[0][0]) )
  {
    v3 -= 4;
    this = (VMatrix *)((char *)this + 4);
    src = (const VMatrix *)((char *)src + 4);
    if ( v3 < 4 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00463830
// Name: void MatrixSetIdentity(class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixSetIdentity(VMatrix *dst)
{
  *(_QWORD *)&dst->m[0][0] = 1065353216;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = 0.0;
  *(_QWORD *)&dst->m[1][1] = 1065353216;
  dst->m[1][3] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[2][2] = 1065353216;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x004638A0
// Name: void MatrixMultiply(class VMatrix const __near &,class VMatrix const __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixMultiply(VMatrix *src1, VMatrix *src2, VMatrix *dst)
{
  float *p_tmp1; // edx
  VMatrix *v4; // edi
  float *p_tmp2; // eax
  VMatrix tmp2; // [esp+Ch] [ebp-80h] BYREF
  VMatrix tmp1; // [esp+4Ch] [ebp-40h] BYREF

  p_tmp1 = (float *)&tmp1;
  if ( src1 != dst )
    p_tmp1 = (float *)src1;
  v4 = src2;
  p_tmp2 = (float *)&tmp2;
  if ( src2 != dst )
    p_tmp2 = (float *)src2;
  if ( src1 == dst && src1 != &tmp1 )
  {
    tmp1 = *src1;
    v4 = src2;
  }
  if ( v4 == dst && v4 != &tmp2 )
    tmp2 = *v4;
  dst->m[0][0] = (float)((float)((float)(p_tmp1[1] * p_tmp2[4]) + (float)(*p_tmp2 * *p_tmp1))
                       + (float)(p_tmp2[8] * p_tmp1[2]))
               + (float)(p_tmp2[12] * p_tmp1[3]);
  dst->m[0][1] = (float)((float)((float)(p_tmp1[1] * p_tmp2[5]) + (float)(*p_tmp1 * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[2]))
               + (float)(p_tmp2[13] * p_tmp1[3]);
  dst->m[0][2] = (float)((float)((float)(p_tmp1[1] * p_tmp2[6]) + (float)(*p_tmp1 * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[2]))
               + (float)(p_tmp2[14] * p_tmp1[3]);
  dst->m[0][3] = (float)((float)((float)(p_tmp1[1] * p_tmp2[7]) + (float)(*p_tmp1 * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[2]))
               + (float)(p_tmp2[15] * p_tmp1[3]);
  dst->m[1][0] = (float)((float)((float)(p_tmp1[5] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[4]))
                       + (float)(p_tmp2[8] * p_tmp1[6]))
               + (float)(p_tmp2[12] * p_tmp1[7]);
  dst->m[1][1] = (float)((float)((float)(p_tmp1[5] * p_tmp2[5]) + (float)(p_tmp1[4] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[6]))
               + (float)(p_tmp2[13] * p_tmp1[7]);
  dst->m[1][2] = (float)((float)((float)(p_tmp1[5] * p_tmp2[6]) + (float)(p_tmp1[4] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[6]))
               + (float)(p_tmp2[14] * p_tmp1[7]);
  dst->m[1][3] = (float)((float)((float)(p_tmp1[5] * p_tmp2[7]) + (float)(p_tmp1[4] * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[6]))
               + (float)(p_tmp1[7] * p_tmp2[15]);
  dst->m[2][0] = (float)((float)((float)(p_tmp1[9] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[8]))
                       + (float)(p_tmp2[8] * p_tmp1[10]))
               + (float)(p_tmp2[12] * p_tmp1[11]);
  dst->m[2][1] = (float)((float)((float)(p_tmp1[9] * p_tmp2[5]) + (float)(p_tmp1[8] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[10]))
               + (float)(p_tmp2[13] * p_tmp1[11]);
  dst->m[2][2] = (float)((float)((float)(p_tmp1[9] * p_tmp2[6]) + (float)(p_tmp1[8] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[10]))
               + (float)(p_tmp2[14] * p_tmp1[11]);
  dst->m[2][3] = (float)((float)((float)(p_tmp1[8] * p_tmp2[3]) + (float)(p_tmp1[9] * p_tmp2[7]))
                       + (float)(p_tmp2[11] * p_tmp1[10]))
               + (float)(p_tmp1[11] * p_tmp2[15]);
  dst->m[3][0] = (float)((float)((float)(p_tmp1[13] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[12]))
                       + (float)(p_tmp2[8] * p_tmp1[14]))
               + (float)(p_tmp2[12] * p_tmp1[15]);
  dst->m[3][1] = (float)((float)((float)(p_tmp1[13] * p_tmp2[5]) + (float)(p_tmp1[12] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[14]))
               + (float)(p_tmp2[13] * p_tmp1[15]);
  dst->m[3][2] = (float)((float)((float)(p_tmp1[13] * p_tmp2[6]) + (float)(p_tmp1[12] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[14]))
               + (float)(p_tmp2[14] * p_tmp1[15]);
  dst->m[3][3] = (float)((float)((float)(p_tmp1[13] * p_tmp2[7]) + (float)(p_tmp1[12] * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[14]))
               + (float)(p_tmp1[15] * p_tmp2[15]);
}

//------------------------------------------------------------------------------
// Address: 0x00463C90
// Name: void MatrixBuildTranslation(class VMatrix __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildTranslation(VMatrix *dst, float x, float y, float z)
{
  *(_QWORD *)&dst->m[0][1] = 0;
  dst->m[1][0] = 0.0;
  dst->m[1][2] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[0][3] = x;
  dst->m[1][3] = y;
  dst->m[0][0] = 1.0;
  dst->m[1][1] = 1.0;
  dst->m[2][2] = 1.0;
  dst->m[3][3] = 1.0;
  dst->m[2][3] = z;
}

//------------------------------------------------------------------------------
// Address: 0x00463D10
// Name: void MatrixBuildRotateZ(class VMatrix __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildRotateZ(VMatrix *dst, float angleDegrees)
{
  long double fSin; // [esp+0h] [ebp-4h]
  long double fSina; // [esp+0h] [ebp-4h]
  float fSinb; // [esp+0h] [ebp-4h]
  float radians; // [esp+10h] [ebp+Ch]

  radians = angleDegrees * 0.0174532925199433;
  __libm_sse2_sin(x: fSin);
  *(float *)&fSina = radians;
  __libm_sse2_cos(x: fSina);
  dst->m[0][0] = radians;
  LODWORD(dst->m[0][1]) = LODWORD(fSinb) ^ _mask__NegFloat_;
  dst->m[1][1] = radians;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = fSinb;
  *(_QWORD *)&dst->m[1][2] = 0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[2][2] = 1065353216;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x00463DD0
// Name: void MatrixBuildScale(class VMatrix __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildScale(VMatrix *dst, unsigned int x, unsigned int y, float z)
{
  *(_QWORD *)&dst->m[0][0] = x;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = 0.0;
  *(_QWORD *)&dst->m[1][1] = y;
  dst->m[1][3] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  dst->m[2][3] = 0.0;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[2][2] = z;
  dst->m[3][3] = 1.0;
}

} // namespace mksheet

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x004B4050
// Name: void MatrixMultiply(class VMatrix const __near &,class VMatrix const __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixMultiply(VMatrix *src1, VMatrix *src2, VMatrix *dst)
{
  float *p_tmp1; // edx
  VMatrix *v4; // edi
  float *p_tmp2; // eax
  VMatrix tmp2; // [esp+Ch] [ebp-80h] BYREF
  VMatrix tmp1; // [esp+4Ch] [ebp-40h] BYREF

  p_tmp1 = (float *)&tmp1;
  if ( src1 != dst )
    p_tmp1 = (float *)src1;
  v4 = src2;
  p_tmp2 = (float *)&tmp2;
  if ( src2 != dst )
    p_tmp2 = (float *)src2;
  if ( src1 == dst && src1 != &tmp1 )
  {
    tmp1 = *src1;
    v4 = src2;
  }
  if ( v4 == dst && v4 != &tmp2 )
    tmp2 = *v4;
  dst->m[0][0] = (float)((float)((float)(p_tmp1[1] * p_tmp2[4]) + (float)(*p_tmp2 * *p_tmp1))
                       + (float)(p_tmp2[8] * p_tmp1[2]))
               + (float)(p_tmp2[12] * p_tmp1[3]);
  dst->m[0][1] = (float)((float)((float)(p_tmp1[1] * p_tmp2[5]) + (float)(*p_tmp1 * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[2]))
               + (float)(p_tmp2[13] * p_tmp1[3]);
  dst->m[0][2] = (float)((float)((float)(p_tmp1[1] * p_tmp2[6]) + (float)(*p_tmp1 * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[2]))
               + (float)(p_tmp2[14] * p_tmp1[3]);
  dst->m[0][3] = (float)((float)((float)(p_tmp1[1] * p_tmp2[7]) + (float)(*p_tmp1 * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[2]))
               + (float)(p_tmp2[15] * p_tmp1[3]);
  dst->m[1][0] = (float)((float)((float)(p_tmp1[5] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[4]))
                       + (float)(p_tmp2[8] * p_tmp1[6]))
               + (float)(p_tmp2[12] * p_tmp1[7]);
  dst->m[1][1] = (float)((float)((float)(p_tmp1[5] * p_tmp2[5]) + (float)(p_tmp1[4] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[6]))
               + (float)(p_tmp2[13] * p_tmp1[7]);
  dst->m[1][2] = (float)((float)((float)(p_tmp1[5] * p_tmp2[6]) + (float)(p_tmp1[4] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[6]))
               + (float)(p_tmp2[14] * p_tmp1[7]);
  dst->m[1][3] = (float)((float)((float)(p_tmp1[5] * p_tmp2[7]) + (float)(p_tmp1[4] * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[6]))
               + (float)(p_tmp1[7] * p_tmp2[15]);
  dst->m[2][0] = (float)((float)((float)(p_tmp1[9] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[8]))
                       + (float)(p_tmp2[8] * p_tmp1[10]))
               + (float)(p_tmp2[12] * p_tmp1[11]);
  dst->m[2][1] = (float)((float)((float)(p_tmp1[9] * p_tmp2[5]) + (float)(p_tmp1[8] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[10]))
               + (float)(p_tmp2[13] * p_tmp1[11]);
  dst->m[2][2] = (float)((float)((float)(p_tmp1[9] * p_tmp2[6]) + (float)(p_tmp1[8] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[10]))
               + (float)(p_tmp2[14] * p_tmp1[11]);
  dst->m[2][3] = (float)((float)((float)(p_tmp1[8] * p_tmp2[3]) + (float)(p_tmp1[9] * p_tmp2[7]))
                       + (float)(p_tmp2[11] * p_tmp1[10]))
               + (float)(p_tmp1[11] * p_tmp2[15]);
  dst->m[3][0] = (float)((float)((float)(p_tmp1[13] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[12]))
                       + (float)(p_tmp2[8] * p_tmp1[14]))
               + (float)(p_tmp2[12] * p_tmp1[15]);
  dst->m[3][1] = (float)((float)((float)(p_tmp1[13] * p_tmp2[5]) + (float)(p_tmp1[12] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[14]))
               + (float)(p_tmp2[13] * p_tmp1[15]);
  dst->m[3][2] = (float)((float)((float)(p_tmp1[13] * p_tmp2[6]) + (float)(p_tmp1[12] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[14]))
               + (float)(p_tmp2[14] * p_tmp1[15]);
  dst->m[3][3] = (float)((float)((float)(p_tmp1[13] * p_tmp2[7]) + (float)(p_tmp1[12] * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[14]))
               + (float)(p_tmp1[15] * p_tmp2[15]);
}

//------------------------------------------------------------------------------
// Address: 0x004B4490
// Name: void MatrixInverseTR(class VMatrix const __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixInverseTR(const VMatrix *src, VMatrix *dst)
{
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm4_4
  float v8; // xmm5_4
  float v9; // xmm1_4
  float v10; // xmm0_4

  dst->m[0][0] = src->m[0][0];
  dst->m[0][1] = src->m[1][0];
  dst->m[0][2] = src->m[2][0];
  dst->m[1][0] = src->m[0][1];
  dst->m[1][1] = src->m[1][1];
  dst->m[1][2] = src->m[2][1];
  dst->m[2][0] = src->m[0][2];
  dst->m[2][1] = src->m[1][2];
  dst->m[2][2] = src->m[2][2];
  v3 = -src->m[0][3];
  v4 = -src->m[1][3];
  v5 = -src->m[2][3];
  v6 = (float)((float)(dst->m[0][0] * v3) + (float)(v4 * dst->m[0][1])) + (float)(dst->m[0][2] * v5);
  v7 = (float)((float)(dst->m[1][1] * v4) + (float)(dst->m[1][0] * v3)) + (float)(v5 * dst->m[1][2]);
  v8 = dst->m[2][1] * v4;
  v9 = dst->m[2][0] * v3;
  v10 = dst->m[2][2] * v5;
  dst->m[0][3] = v6;
  dst->m[1][3] = v7;
  dst->m[2][3] = (float)(v8 + v9) + v10;
  *(_QWORD *)&dst->m[3][1] = 0;
  dst->m[3][0] = 0.0;
  dst->m[3][3] = 1.0;
}

} // namespace modelbrowser

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x00465690
// Name: public: class VMatrix __near & VMatrix::operator=(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
VMatrix *__thiscall VMatrix::operator=(VMatrix *this, const VMatrix *mOther)
{
  *this = *mOther;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00465700
// Name: public: bool VMatrix::operator==(class VMatrix const __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall VMatrix::operator==(VMatrix *this, const VMatrix *src)
{
  unsigned int v3; // eax

  v3 = 64;
  while ( LODWORD(src->m[0][0]) == LODWORD(this->m[0][0]) )
  {
    v3 -= 4;
    this = (VMatrix *)((char *)this + 4);
    src = (const VMatrix *)((char *)src + 4);
    if ( v3 < 4 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00465770
// Name: void MatrixSetIdentity(class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixSetIdentity(VMatrix *dst)
{
  *(_QWORD *)&dst->m[0][0] = 1065353216;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = 0.0;
  *(_QWORD *)&dst->m[1][1] = 1065353216;
  dst->m[1][3] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[2][2] = 1065353216;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x004657E0
// Name: void MatrixMultiply(class VMatrix const __near &,class VMatrix const __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixMultiply(const VMatrix *src1, const VMatrix *src2, VMatrix *dst)
{
  float *p_tmp1; // edx
  VMatrix *v4; // edi
  float *p_tmp2; // eax
  VMatrix tmp2; // [esp+Ch] [ebp-80h] BYREF
  VMatrix tmp1; // [esp+4Ch] [ebp-40h] BYREF

  p_tmp1 = (float *)&tmp1;
  if ( src1 != dst )
    p_tmp1 = (float *)src1;
  v4 = src2;
  p_tmp2 = (float *)&tmp2;
  if ( src2 != dst )
    p_tmp2 = (float *)src2;
  if ( src1 == dst && src1 != &tmp1 )
  {
    tmp1 = *src1;
    v4 = src2;
  }
  if ( v4 == dst && v4 != &tmp2 )
    tmp2 = *v4;
  dst->m[0][0] = (float)((float)((float)(p_tmp1[1] * p_tmp2[4]) + (float)(*p_tmp2 * *p_tmp1))
                       + (float)(p_tmp2[8] * p_tmp1[2]))
               + (float)(p_tmp2[12] * p_tmp1[3]);
  dst->m[0][1] = (float)((float)((float)(p_tmp1[1] * p_tmp2[5]) + (float)(*p_tmp1 * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[2]))
               + (float)(p_tmp2[13] * p_tmp1[3]);
  dst->m[0][2] = (float)((float)((float)(p_tmp1[1] * p_tmp2[6]) + (float)(*p_tmp1 * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[2]))
               + (float)(p_tmp2[14] * p_tmp1[3]);
  dst->m[0][3] = (float)((float)((float)(p_tmp1[1] * p_tmp2[7]) + (float)(*p_tmp1 * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[2]))
               + (float)(p_tmp2[15] * p_tmp1[3]);
  dst->m[1][0] = (float)((float)((float)(p_tmp1[5] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[4]))
                       + (float)(p_tmp2[8] * p_tmp1[6]))
               + (float)(p_tmp2[12] * p_tmp1[7]);
  dst->m[1][1] = (float)((float)((float)(p_tmp1[5] * p_tmp2[5]) + (float)(p_tmp1[4] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[6]))
               + (float)(p_tmp2[13] * p_tmp1[7]);
  dst->m[1][2] = (float)((float)((float)(p_tmp1[5] * p_tmp2[6]) + (float)(p_tmp1[4] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[6]))
               + (float)(p_tmp2[14] * p_tmp1[7]);
  dst->m[1][3] = (float)((float)((float)(p_tmp1[5] * p_tmp2[7]) + (float)(p_tmp1[4] * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[6]))
               + (float)(p_tmp1[7] * p_tmp2[15]);
  dst->m[2][0] = (float)((float)((float)(p_tmp1[9] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[8]))
                       + (float)(p_tmp2[8] * p_tmp1[10]))
               + (float)(p_tmp2[12] * p_tmp1[11]);
  dst->m[2][1] = (float)((float)((float)(p_tmp1[9] * p_tmp2[5]) + (float)(p_tmp1[8] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[10]))
               + (float)(p_tmp2[13] * p_tmp1[11]);
  dst->m[2][2] = (float)((float)((float)(p_tmp1[9] * p_tmp2[6]) + (float)(p_tmp1[8] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[10]))
               + (float)(p_tmp2[14] * p_tmp1[11]);
  dst->m[2][3] = (float)((float)((float)(p_tmp1[8] * p_tmp2[3]) + (float)(p_tmp1[9] * p_tmp2[7]))
                       + (float)(p_tmp2[11] * p_tmp1[10]))
               + (float)(p_tmp1[11] * p_tmp2[15]);
  dst->m[3][0] = (float)((float)((float)(p_tmp1[13] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[12]))
                       + (float)(p_tmp2[8] * p_tmp1[14]))
               + (float)(p_tmp2[12] * p_tmp1[15]);
  dst->m[3][1] = (float)((float)((float)(p_tmp1[13] * p_tmp2[5]) + (float)(p_tmp1[12] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[14]))
               + (float)(p_tmp2[13] * p_tmp1[15]);
  dst->m[3][2] = (float)((float)((float)(p_tmp1[13] * p_tmp2[6]) + (float)(p_tmp1[12] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[14]))
               + (float)(p_tmp2[14] * p_tmp1[15]);
  dst->m[3][3] = (float)((float)((float)(p_tmp1[13] * p_tmp2[7]) + (float)(p_tmp1[12] * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[14]))
               + (float)(p_tmp1[15] * p_tmp2[15]);
}

//------------------------------------------------------------------------------
// Address: 0x00465BD0
// Name: void MatrixBuildTranslation(class VMatrix __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildTranslation(VMatrix *dst, float x, float y, float z)
{
  *(_QWORD *)&dst->m[0][1] = 0;
  dst->m[1][0] = 0.0;
  dst->m[1][2] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[0][3] = x;
  dst->m[1][3] = y;
  dst->m[0][0] = 1.0;
  dst->m[1][1] = 1.0;
  dst->m[2][2] = 1.0;
  dst->m[3][3] = 1.0;
  dst->m[2][3] = z;
}

//------------------------------------------------------------------------------
// Address: 0x00465CA0
// Name: void MatrixBuildRotateZ(class VMatrix __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildRotateZ(VMatrix *dst, float angleDegrees)
{
  double v2; // xmm0_8
  float v3; // xmm1_4
  long double fSin; // [esp+0h] [ebp-4h]
  unsigned int radians; // [esp+10h] [ebp+Ch]

  *(float *)&radians = angleDegrees * 0.0174532925199433;
  __libm_sse2_sin(x: fSin);
  __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)radians));
  v3 = v2;
  dst->m[0][0] = v3;
  LODWORD(dst->m[0][1]) = radians ^ _mask__NegFloat_;
  dst->m[1][1] = v3;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = *(float *)&radians;
  *(_QWORD *)&dst->m[1][2] = 0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[2][2] = 1065353216;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x00465D60
// Name: void MatrixBuildScale(class VMatrix __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildScale(VMatrix *dst, unsigned int x, unsigned int y, float z)
{
  *(_QWORD *)&dst->m[0][0] = x;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = 0.0;
  *(_QWORD *)&dst->m[1][1] = y;
  dst->m[1][3] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  dst->m[2][3] = 0.0;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[2][2] = z;
  dst->m[3][3] = 1.0;
}

} // namespace particle_import

// ============================================================
// Overlay from pcffix (Missing functions)
// ============================================================
namespace pcffix {

//------------------------------------------------------------------------------
// Address: 0x00441E50
// Name: public: class VMatrix __near & VMatrix::operator=(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
VMatrix *__thiscall VMatrix::operator=(VMatrix *this, const VMatrix *mOther)
{
  *this = *mOther;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00441EC0
// Name: public: bool VMatrix::operator==(class VMatrix const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall VMatrix::operator==(VMatrix *this, const VMatrix *src)
{
  unsigned int i; // edx
  int v5; // esi
  unsigned int v6; // edx
  unsigned __int8 *v7; // eax
  unsigned __int8 *v8; // ecx
  unsigned int v9; // edx
  unsigned __int8 *v10; // eax
  unsigned __int8 *v11; // ecx
  unsigned __int8 *v12; // eax
  unsigned __int8 *v13; // ecx
  int v14; // eax

  for ( i = 64; i >= 4; i -= 4 )
  {
    if ( LODWORD(src->m[0][0]) != LODWORD(this->m[0][0]) )
      goto LABEL_5;
    this = (VMatrix *)((char *)this + 4);
    src = (const VMatrix *)((char *)src + 4);
  }
  if ( i == 0 )
  {
LABEL_14:
    v14 = 0;
    return v14 == 0;
  }
LABEL_5:
  v5 = LOBYTE(src->m[0][0]) - LOBYTE(this->m[0][0]);
  if ( v5 == 0 )
  {
    v6 = i - 1;
    v7 = (unsigned __int8 *)&this->m[0][0] + 1;
    v8 = (unsigned __int8 *)&src->m[0][0] + 1;
    if ( v6 == 0 )
      goto LABEL_14;
    v5 = *v8 - *v7;
    if ( v5 == 0 )
    {
      v9 = v6 - 1;
      v10 = v7 + 1;
      v11 = v8 + 1;
      if ( v9 == 0 )
        goto LABEL_14;
      v5 = *v11 - *v10;
      if ( v5 == 0 )
      {
        v12 = v10 + 1;
        v13 = v11 + 1;
        if ( v9 == 1 )
          goto LABEL_14;
        v5 = *v13 - *v12;
        if ( v5 == 0 )
          goto LABEL_14;
      }
    }
  }
  v14 = 1;
  if ( v5 <= 0 )
    return false;
  return v14 == 0;
}

//------------------------------------------------------------------------------
// Address: 0x00441F70
// Name: void MatrixSetIdentity(class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixSetIdentity(VMatrix *dst)
{
  dst->m[0][0] = 1.0;
  dst->m[0][1] = 0.0;
  dst->m[0][2] = 0.0;
  dst->m[0][3] = 0.0;
  dst->m[1][0] = 0.0;
  dst->m[1][2] = 0.0;
  dst->m[1][3] = 0.0;
  dst->m[2][0] = 0.0;
  dst->m[2][1] = 0.0;
  dst->m[2][3] = 0.0;
  dst->m[3][0] = 0.0;
  dst->m[3][1] = 0.0;
  dst->m[3][2] = 0.0;
  dst->m[1][1] = 1.0;
  dst->m[2][2] = 1.0;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x00441FB0
// Name: void MatrixMultiply(class VMatrix const __near &,class VMatrix const __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __cdecl MatrixMultiply(VMatrix *src1, VMatrix *src2, VMatrix *dst)
{
  float *v3; // edx
  float *v4; // eax
  _BYTE tmp1_4[128]; // [esp+10h] [ebp-80h] OVERLAPPED BYREF

  v3 = (float *)tmp1_4;
  if ( src1 != dst )
    v3 = (float *)src1;
  v4 = (float *)&tmp1_4[64];
  if ( src2 != dst )
    v4 = (float *)src2;
  if ( src1 == dst && src1 != (VMatrix *)tmp1_4 )
    *(VMatrix *)tmp1_4 = *src1;
  if ( src2 == dst && src2 != (VMatrix *)&tmp1_4[64] )
    *(VMatrix *)&tmp1_4[64] = *src2;
  dst->m[0][0] = v3[3] * v4[12] + *v4 * *v3 + v3[2] * v4[8] + v3[1] * v4[4];
  dst->m[0][1] = v3[3] * v4[13] + *v3 * v4[1] + v3[2] * v4[9] + v3[1] * v4[5];
  dst->m[0][2] = v4[6] * v3[1] + v3[3] * v4[14] + v4[2] * *v3 + v3[2] * v4[10];
  dst->m[0][3] = v4[7] * v3[1] + *v3 * v4[3] + v3[3] * v4[15] + v4[11] * v3[2];
  dst->m[1][0] = v3[7] * v4[12] + *v4 * v3[4] + v3[6] * v4[8] + v4[4] * v3[5];
  dst->m[1][1] = v3[7] * v4[13] + v3[6] * v4[9] + v4[5] * v3[5] + v4[1] * v3[4];
  dst->m[1][2] = v4[6] * v3[5] + v3[7] * v4[14] + v3[6] * v4[10] + v4[2] * v3[4];
  dst->m[1][3] = v4[7] * v3[5] + v3[7] * v4[15] + v3[6] * v4[11] + v3[4] * v4[3];
  dst->m[2][0] = v3[11] * v4[12] + *v4 * v3[8] + v3[10] * v4[8] + v4[4] * v3[9];
  dst->m[2][1] = v3[11] * v4[13] + v3[10] * v4[9] + v4[5] * v3[9] + v4[1] * v3[8];
  dst->m[2][2] = v4[6] * v3[9] + v3[11] * v4[14] + v3[10] * v4[10] + v4[2] * v3[8];
  dst->m[2][3] = v4[7] * v3[9] + v3[11] * v4[15] + v3[10] * v4[11] + v3[8] * v4[3];
  dst->m[3][0] = v3[15] * v4[12] + *v4 * v3[12] + v4[4] * v3[13] + v3[14] * v4[8];
  dst->m[3][1] = v3[14] * v4[9] + v3[15] * v4[13] + v4[5] * v3[13] + v4[1] * v3[12];
  dst->m[3][2] = v4[6] * v3[13] + v3[15] * v4[14] + v4[2] * v3[12] + v3[14] * v4[10];
  dst->m[3][3] = v4[7] * v3[13] + v3[15] * v4[15] + v3[14] * v4[11] + v3[12] * v4[3];
}

//------------------------------------------------------------------------------
// Address: 0x00442230
// Name: void MatrixBuildTranslation(class VMatrix __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildTranslation(VMatrix *dst, float x, float y, float z)
{
  dst->m[0][0] = 1.0;
  dst->m[0][1] = 0.0;
  dst->m[0][2] = 0.0;
  dst->m[1][0] = 0.0;
  dst->m[1][2] = 0.0;
  dst->m[2][0] = 0.0;
  dst->m[2][1] = 0.0;
  dst->m[3][0] = 0.0;
  dst->m[3][1] = 0.0;
  dst->m[3][2] = 0.0;
  dst->m[1][1] = 1.0;
  dst->m[2][2] = 1.0;
  dst->m[3][3] = 1.0;
  dst->m[0][3] = x;
  dst->m[1][3] = y;
  dst->m[2][3] = z;
}

//------------------------------------------------------------------------------
// Address: 0x00442280
// Name: void MatrixBuildRotateZ(class VMatrix __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildRotateZ(VMatrix *dst, float angleDegrees)
{
  long double v2; // st7
  long double v3; // rt0
  long double v4; // st6

  v2 = angleDegrees * 0.0174532925199433;
  v3 = sin(v2);
  v4 = cos(v2);
  dst->m[0][0] = v4;
  dst->m[0][1] = -v3;
  dst->m[0][2] = 0.0;
  dst->m[0][3] = 0.0;
  dst->m[1][2] = 0.0;
  dst->m[1][3] = 0.0;
  dst->m[2][0] = 0.0;
  dst->m[2][1] = 0.0;
  dst->m[1][0] = v3;
  dst->m[1][1] = v4;
  dst->m[2][2] = 1.0;
  dst->m[3][3] = 1.0;
  dst->m[2][3] = 0.0;
  dst->m[3][0] = 0.0;
  dst->m[3][1] = 0.0;
  dst->m[3][2] = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x004422D0
// Name: void MatrixBuildScale(class VMatrix __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildScale(VMatrix *dst, float x, float y, float z)
{
  dst->m[0][0] = x;
  dst->m[0][1] = 0.0;
  dst->m[0][2] = 0.0;
  dst->m[0][3] = 0.0;
  dst->m[1][0] = 0.0;
  dst->m[1][1] = y;
  dst->m[1][2] = 0.0;
  dst->m[1][3] = 0.0;
  dst->m[2][0] = 0.0;
  dst->m[2][1] = 0.0;
  dst->m[2][2] = z;
  dst->m[2][3] = 0.0;
  dst->m[3][0] = 0.0;
  dst->m[3][1] = 0.0;
  dst->m[3][2] = 0.0;
  dst->m[3][3] = 1.0;
}

} // namespace pcffix

// ============================================================
// Overlay from pcfmanager (Missing functions)
// ============================================================
namespace pcfmanager {

//------------------------------------------------------------------------------
// Address: 0x00460040
// Name: public: class VMatrix __near & VMatrix::operator=(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
VMatrix *__thiscall VMatrix::operator=(VMatrix *this, const VMatrix *mOther)
{
  *this = *mOther;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004600B0
// Name: public: bool VMatrix::operator==(class VMatrix const __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall VMatrix::operator==(VMatrix *this, const VMatrix *src)
{
  unsigned int v3; // eax

  v3 = 64;
  while ( LODWORD(src->m[0][0]) == LODWORD(this->m[0][0]) )
  {
    v3 -= 4;
    this = (VMatrix *)((char *)this + 4);
    src = (const VMatrix *)((char *)src + 4);
    if ( v3 < 4 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00460120
// Name: void MatrixSetIdentity(class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixSetIdentity(VMatrix *dst)
{
  *(_QWORD *)&dst->m[0][0] = 1065353216;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = 0.0;
  *(_QWORD *)&dst->m[1][1] = 1065353216;
  dst->m[1][3] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[2][2] = 1065353216;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x00460190
// Name: void MatrixMultiply(class VMatrix const __near &,class VMatrix const __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixMultiply(VMatrix *src1, VMatrix *src2, VMatrix *dst)
{
  float *p_tmp1; // edx
  VMatrix *v4; // edi
  float *p_tmp2; // eax
  VMatrix tmp2; // [esp+Ch] [ebp-80h] BYREF
  VMatrix tmp1; // [esp+4Ch] [ebp-40h] BYREF

  p_tmp1 = (float *)&tmp1;
  if ( src1 != dst )
    p_tmp1 = (float *)src1;
  v4 = src2;
  p_tmp2 = (float *)&tmp2;
  if ( src2 != dst )
    p_tmp2 = (float *)src2;
  if ( src1 == dst && src1 != &tmp1 )
  {
    tmp1 = *src1;
    v4 = src2;
  }
  if ( v4 == dst && v4 != &tmp2 )
    tmp2 = *v4;
  dst->m[0][0] = (float)((float)((float)(p_tmp1[1] * p_tmp2[4]) + (float)(*p_tmp2 * *p_tmp1))
                       + (float)(p_tmp2[8] * p_tmp1[2]))
               + (float)(p_tmp2[12] * p_tmp1[3]);
  dst->m[0][1] = (float)((float)((float)(p_tmp1[1] * p_tmp2[5]) + (float)(*p_tmp1 * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[2]))
               + (float)(p_tmp2[13] * p_tmp1[3]);
  dst->m[0][2] = (float)((float)((float)(p_tmp1[1] * p_tmp2[6]) + (float)(*p_tmp1 * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[2]))
               + (float)(p_tmp2[14] * p_tmp1[3]);
  dst->m[0][3] = (float)((float)((float)(p_tmp1[1] * p_tmp2[7]) + (float)(*p_tmp1 * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[2]))
               + (float)(p_tmp2[15] * p_tmp1[3]);
  dst->m[1][0] = (float)((float)((float)(p_tmp1[5] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[4]))
                       + (float)(p_tmp2[8] * p_tmp1[6]))
               + (float)(p_tmp2[12] * p_tmp1[7]);
  dst->m[1][1] = (float)((float)((float)(p_tmp1[5] * p_tmp2[5]) + (float)(p_tmp1[4] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[6]))
               + (float)(p_tmp2[13] * p_tmp1[7]);
  dst->m[1][2] = (float)((float)((float)(p_tmp1[5] * p_tmp2[6]) + (float)(p_tmp1[4] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[6]))
               + (float)(p_tmp2[14] * p_tmp1[7]);
  dst->m[1][3] = (float)((float)((float)(p_tmp1[5] * p_tmp2[7]) + (float)(p_tmp1[4] * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[6]))
               + (float)(p_tmp1[7] * p_tmp2[15]);
  dst->m[2][0] = (float)((float)((float)(p_tmp1[9] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[8]))
                       + (float)(p_tmp2[8] * p_tmp1[10]))
               + (float)(p_tmp2[12] * p_tmp1[11]);
  dst->m[2][1] = (float)((float)((float)(p_tmp1[9] * p_tmp2[5]) + (float)(p_tmp1[8] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[10]))
               + (float)(p_tmp2[13] * p_tmp1[11]);
  dst->m[2][2] = (float)((float)((float)(p_tmp1[9] * p_tmp2[6]) + (float)(p_tmp1[8] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[10]))
               + (float)(p_tmp2[14] * p_tmp1[11]);
  dst->m[2][3] = (float)((float)((float)(p_tmp1[8] * p_tmp2[3]) + (float)(p_tmp1[9] * p_tmp2[7]))
                       + (float)(p_tmp2[11] * p_tmp1[10]))
               + (float)(p_tmp1[11] * p_tmp2[15]);
  dst->m[3][0] = (float)((float)((float)(p_tmp1[13] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[12]))
                       + (float)(p_tmp2[8] * p_tmp1[14]))
               + (float)(p_tmp2[12] * p_tmp1[15]);
  dst->m[3][1] = (float)((float)((float)(p_tmp1[13] * p_tmp2[5]) + (float)(p_tmp1[12] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[14]))
               + (float)(p_tmp2[13] * p_tmp1[15]);
  dst->m[3][2] = (float)((float)((float)(p_tmp1[13] * p_tmp2[6]) + (float)(p_tmp1[12] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[14]))
               + (float)(p_tmp2[14] * p_tmp1[15]);
  dst->m[3][3] = (float)((float)((float)(p_tmp1[13] * p_tmp2[7]) + (float)(p_tmp1[12] * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[14]))
               + (float)(p_tmp1[15] * p_tmp2[15]);
}

//------------------------------------------------------------------------------
// Address: 0x00460580
// Name: void MatrixBuildTranslation(class VMatrix __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildTranslation(VMatrix *dst, float x, float y, float z)
{
  *(_QWORD *)&dst->m[0][1] = 0;
  dst->m[1][0] = 0.0;
  dst->m[1][2] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[0][3] = x;
  dst->m[1][3] = y;
  dst->m[0][0] = 1.0;
  dst->m[1][1] = 1.0;
  dst->m[2][2] = 1.0;
  dst->m[3][3] = 1.0;
  dst->m[2][3] = z;
}

//------------------------------------------------------------------------------
// Address: 0x00460600
// Name: void MatrixBuildRotateZ(class VMatrix __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildRotateZ(VMatrix *dst, float angleDegrees)
{
  long double fSin; // [esp+0h] [ebp-4h]
  long double fSina; // [esp+0h] [ebp-4h]
  float fSinb; // [esp+0h] [ebp-4h]
  float radians; // [esp+10h] [ebp+Ch]

  radians = angleDegrees * 0.0174532925199433;
  __libm_sse2_sin(x: fSin);
  *(float *)&fSina = radians;
  __libm_sse2_cos(x: fSina);
  dst->m[0][0] = radians;
  LODWORD(dst->m[0][1]) = LODWORD(fSinb) ^ _mask__NegFloat_;
  dst->m[1][1] = radians;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = fSinb;
  *(_QWORD *)&dst->m[1][2] = 0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[2][2] = 1065353216;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x004606C0
// Name: void MatrixBuildScale(class VMatrix __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildScale(VMatrix *dst, unsigned int x, unsigned int y, float z)
{
  *(_QWORD *)&dst->m[0][0] = x;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = 0.0;
  *(_QWORD *)&dst->m[1][1] = y;
  dst->m[1][3] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  dst->m[2][3] = 0.0;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[2][2] = z;
  dst->m[3][3] = 1.0;
}

} // namespace pcfmanager

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x00468A90
// Name: public: class VMatrix __near & VMatrix::operator=(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
VMatrix *__thiscall VMatrix::operator=(VMatrix *this, const VMatrix *mOther)
{
  *this = *mOther;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00468B00
// Name: public: bool VMatrix::operator==(class VMatrix const __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall VMatrix::operator==(VMatrix *this, const VMatrix *src)
{
  unsigned int v3; // eax

  v3 = 64;
  while ( LODWORD(src->m[0][0]) == LODWORD(this->m[0][0]) )
  {
    v3 -= 4;
    this = (VMatrix *)((char *)this + 4);
    src = (const VMatrix *)((char *)src + 4);
    if ( v3 < 4 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00468B70
// Name: void MatrixSetIdentity(class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixSetIdentity(VMatrix *dst)
{
  *(_QWORD *)&dst->m[0][0] = 1065353216;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = 0.0;
  *(_QWORD *)&dst->m[1][1] = 1065353216;
  dst->m[1][3] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[2][2] = 1065353216;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x00468BE0
// Name: void MatrixMultiply(class VMatrix const __near &,class VMatrix const __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixMultiply(const VMatrix *src1, const VMatrix *src2, VMatrix *dst)
{
  float *p_tmp1; // edx
  VMatrix *v4; // edi
  float *p_tmp2; // eax
  VMatrix tmp2; // [esp+Ch] [ebp-80h] BYREF
  VMatrix tmp1; // [esp+4Ch] [ebp-40h] BYREF

  p_tmp1 = (float *)&tmp1;
  if ( src1 != dst )
    p_tmp1 = (float *)src1;
  v4 = src2;
  p_tmp2 = (float *)&tmp2;
  if ( src2 != dst )
    p_tmp2 = (float *)src2;
  if ( src1 == dst && src1 != &tmp1 )
  {
    tmp1 = *src1;
    v4 = src2;
  }
  if ( v4 == dst && v4 != &tmp2 )
    tmp2 = *v4;
  dst->m[0][0] = (float)((float)((float)(p_tmp1[1] * p_tmp2[4]) + (float)(*p_tmp2 * *p_tmp1))
                       + (float)(p_tmp2[8] * p_tmp1[2]))
               + (float)(p_tmp2[12] * p_tmp1[3]);
  dst->m[0][1] = (float)((float)((float)(p_tmp1[1] * p_tmp2[5]) + (float)(*p_tmp1 * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[2]))
               + (float)(p_tmp2[13] * p_tmp1[3]);
  dst->m[0][2] = (float)((float)((float)(p_tmp1[1] * p_tmp2[6]) + (float)(*p_tmp1 * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[2]))
               + (float)(p_tmp2[14] * p_tmp1[3]);
  dst->m[0][3] = (float)((float)((float)(p_tmp1[1] * p_tmp2[7]) + (float)(*p_tmp1 * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[2]))
               + (float)(p_tmp2[15] * p_tmp1[3]);
  dst->m[1][0] = (float)((float)((float)(p_tmp1[5] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[4]))
                       + (float)(p_tmp2[8] * p_tmp1[6]))
               + (float)(p_tmp2[12] * p_tmp1[7]);
  dst->m[1][1] = (float)((float)((float)(p_tmp1[5] * p_tmp2[5]) + (float)(p_tmp1[4] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[6]))
               + (float)(p_tmp2[13] * p_tmp1[7]);
  dst->m[1][2] = (float)((float)((float)(p_tmp1[5] * p_tmp2[6]) + (float)(p_tmp1[4] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[6]))
               + (float)(p_tmp2[14] * p_tmp1[7]);
  dst->m[1][3] = (float)((float)((float)(p_tmp1[5] * p_tmp2[7]) + (float)(p_tmp1[4] * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[6]))
               + (float)(p_tmp1[7] * p_tmp2[15]);
  dst->m[2][0] = (float)((float)((float)(p_tmp1[9] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[8]))
                       + (float)(p_tmp2[8] * p_tmp1[10]))
               + (float)(p_tmp2[12] * p_tmp1[11]);
  dst->m[2][1] = (float)((float)((float)(p_tmp1[9] * p_tmp2[5]) + (float)(p_tmp1[8] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[10]))
               + (float)(p_tmp2[13] * p_tmp1[11]);
  dst->m[2][2] = (float)((float)((float)(p_tmp1[9] * p_tmp2[6]) + (float)(p_tmp1[8] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[10]))
               + (float)(p_tmp2[14] * p_tmp1[11]);
  dst->m[2][3] = (float)((float)((float)(p_tmp1[8] * p_tmp2[3]) + (float)(p_tmp1[9] * p_tmp2[7]))
                       + (float)(p_tmp2[11] * p_tmp1[10]))
               + (float)(p_tmp1[11] * p_tmp2[15]);
  dst->m[3][0] = (float)((float)((float)(p_tmp1[13] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[12]))
                       + (float)(p_tmp2[8] * p_tmp1[14]))
               + (float)(p_tmp2[12] * p_tmp1[15]);
  dst->m[3][1] = (float)((float)((float)(p_tmp1[13] * p_tmp2[5]) + (float)(p_tmp1[12] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[14]))
               + (float)(p_tmp2[13] * p_tmp1[15]);
  dst->m[3][2] = (float)((float)((float)(p_tmp1[13] * p_tmp2[6]) + (float)(p_tmp1[12] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[14]))
               + (float)(p_tmp2[14] * p_tmp1[15]);
  dst->m[3][3] = (float)((float)((float)(p_tmp1[13] * p_tmp2[7]) + (float)(p_tmp1[12] * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[14]))
               + (float)(p_tmp1[15] * p_tmp2[15]);
}

//------------------------------------------------------------------------------
// Address: 0x00468FD0
// Name: void MatrixBuildTranslation(class VMatrix __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildTranslation(VMatrix *dst, float x, float y, float z)
{
  *(_QWORD *)&dst->m[0][1] = 0;
  dst->m[1][0] = 0.0;
  dst->m[1][2] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[0][3] = x;
  dst->m[1][3] = y;
  dst->m[0][0] = 1.0;
  dst->m[1][1] = 1.0;
  dst->m[2][2] = 1.0;
  dst->m[3][3] = 1.0;
  dst->m[2][3] = z;
}

//------------------------------------------------------------------------------
// Address: 0x004690A0
// Name: void MatrixBuildRotateZ(class VMatrix __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildRotateZ(VMatrix *dst, float angleDegrees)
{
  long double fSin; // [esp+0h] [ebp-4h]
  long double fSina; // [esp+0h] [ebp-4h]
  float fSinb; // [esp+0h] [ebp-4h]
  float radians; // [esp+10h] [ebp+Ch]

  radians = angleDegrees * 0.0174532925199433;
  __libm_sse2_sin(x: fSin);
  *(float *)&fSina = radians;
  __libm_sse2_cos(x: fSina);
  dst->m[0][0] = radians;
  LODWORD(dst->m[0][1]) = LODWORD(fSinb) ^ _mask__NegFloat_;
  dst->m[1][1] = radians;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = fSinb;
  *(_QWORD *)&dst->m[1][2] = 0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[2][2] = 1065353216;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x00469160
// Name: void MatrixBuildScale(class VMatrix __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildScale(VMatrix *dst, unsigned int x, unsigned int y, float z)
{
  *(_QWORD *)&dst->m[0][0] = x;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = 0.0;
  *(_QWORD *)&dst->m[1][1] = y;
  dst->m[1][3] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  dst->m[2][3] = 0.0;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[2][2] = z;
  dst->m[3][3] = 1.0;
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x004C4130
// Name: public: class VMatrix __near & VMatrix::operator=(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
VMatrix *__thiscall VMatrix::operator=(VMatrix *this, const VMatrix *mOther)
{
  *this = *mOther;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004C41A0
// Name: public: bool VMatrix::operator==(class VMatrix const __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall VMatrix::operator==(VMatrix *this, const VMatrix *src)
{
  unsigned int v3; // eax

  v3 = 64;
  while ( LODWORD(src->m[0][0]) == LODWORD(this->m[0][0]) )
  {
    v3 -= 4;
    this = (VMatrix *)((char *)this + 4);
    src = (const VMatrix *)((char *)src + 4);
    if ( v3 < 4 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004C4210
// Name: void MatrixSetIdentity(class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixSetIdentity(VMatrix *dst)
{
  *(_QWORD *)&dst->m[0][0] = 1065353216;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = 0.0;
  *(_QWORD *)&dst->m[1][1] = 1065353216;
  dst->m[1][3] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[2][2] = 1065353216;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x004C4280
// Name: void MatrixTranspose(class VMatrix const __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixTranspose(const VMatrix *src, VMatrix *dst)
{
  float v2; // xmm0_4
  float v3; // xmm0_4
  float v4; // xmm0_4
  float v5; // xmm0_4
  float v6; // xmm0_4
  float v7; // xmm0_4

  if ( src == dst )
  {
    v2 = dst->m[0][1];
    dst->m[0][1] = dst->m[1][0];
    dst->m[1][0] = v2;
    v3 = dst->m[0][2];
    dst->m[0][2] = dst->m[2][0];
    dst->m[2][0] = v3;
    v4 = dst->m[0][3];
    dst->m[0][3] = dst->m[3][0];
    dst->m[3][0] = v4;
    v5 = dst->m[1][2];
    dst->m[1][2] = dst->m[2][1];
    dst->m[2][1] = v5;
    v6 = dst->m[1][3];
    dst->m[1][3] = dst->m[3][1];
    dst->m[3][1] = v6;
    v7 = dst->m[2][3];
    dst->m[2][3] = dst->m[3][2];
    dst->m[3][2] = v7;
  }
  else
  {
    dst->m[0][0] = src->m[0][0];
    dst->m[0][1] = src->m[1][0];
    dst->m[0][2] = src->m[2][0];
    dst->m[0][3] = src->m[3][0];
    dst->m[1][0] = src->m[0][1];
    dst->m[1][1] = src->m[1][1];
    dst->m[1][2] = src->m[2][1];
    dst->m[1][3] = src->m[3][1];
    dst->m[2][0] = src->m[0][2];
    dst->m[2][1] = src->m[1][2];
    dst->m[2][2] = src->m[2][2];
    dst->m[2][3] = src->m[3][2];
    dst->m[3][0] = src->m[0][3];
    dst->m[3][1] = src->m[1][3];
    dst->m[3][2] = src->m[2][3];
    dst->m[3][3] = src->m[3][3];
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C4350
// Name: void MatrixMultiply(class VMatrix const __near &,class VMatrix const __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixMultiply(VMatrix *src1, VMatrix *src2, VMatrix *dst)
{
  float *p_tmp1; // edx
  VMatrix *v4; // edi
  float *p_tmp2; // eax
  VMatrix tmp2; // [esp+Ch] [ebp-80h] BYREF
  VMatrix tmp1; // [esp+4Ch] [ebp-40h] BYREF

  p_tmp1 = (float *)&tmp1;
  if ( src1 != dst )
    p_tmp1 = (float *)src1;
  v4 = src2;
  p_tmp2 = (float *)&tmp2;
  if ( src2 != dst )
    p_tmp2 = (float *)src2;
  if ( src1 == dst && src1 != &tmp1 )
  {
    tmp1 = *src1;
    v4 = src2;
  }
  if ( v4 == dst && v4 != &tmp2 )
    tmp2 = *v4;
  dst->m[0][0] = (float)((float)((float)(p_tmp1[1] * p_tmp2[4]) + (float)(*p_tmp2 * *p_tmp1))
                       + (float)(p_tmp2[8] * p_tmp1[2]))
               + (float)(p_tmp2[12] * p_tmp1[3]);
  dst->m[0][1] = (float)((float)((float)(p_tmp1[1] * p_tmp2[5]) + (float)(*p_tmp1 * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[2]))
               + (float)(p_tmp2[13] * p_tmp1[3]);
  dst->m[0][2] = (float)((float)((float)(p_tmp1[1] * p_tmp2[6]) + (float)(*p_tmp1 * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[2]))
               + (float)(p_tmp2[14] * p_tmp1[3]);
  dst->m[0][3] = (float)((float)((float)(p_tmp1[1] * p_tmp2[7]) + (float)(*p_tmp1 * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[2]))
               + (float)(p_tmp2[15] * p_tmp1[3]);
  dst->m[1][0] = (float)((float)((float)(p_tmp1[5] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[4]))
                       + (float)(p_tmp2[8] * p_tmp1[6]))
               + (float)(p_tmp2[12] * p_tmp1[7]);
  dst->m[1][1] = (float)((float)((float)(p_tmp1[5] * p_tmp2[5]) + (float)(p_tmp1[4] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[6]))
               + (float)(p_tmp2[13] * p_tmp1[7]);
  dst->m[1][2] = (float)((float)((float)(p_tmp1[5] * p_tmp2[6]) + (float)(p_tmp1[4] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[6]))
               + (float)(p_tmp2[14] * p_tmp1[7]);
  dst->m[1][3] = (float)((float)((float)(p_tmp1[5] * p_tmp2[7]) + (float)(p_tmp1[4] * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[6]))
               + (float)(p_tmp1[7] * p_tmp2[15]);
  dst->m[2][0] = (float)((float)((float)(p_tmp1[9] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[8]))
                       + (float)(p_tmp2[8] * p_tmp1[10]))
               + (float)(p_tmp2[12] * p_tmp1[11]);
  dst->m[2][1] = (float)((float)((float)(p_tmp1[9] * p_tmp2[5]) + (float)(p_tmp1[8] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[10]))
               + (float)(p_tmp2[13] * p_tmp1[11]);
  dst->m[2][2] = (float)((float)((float)(p_tmp1[9] * p_tmp2[6]) + (float)(p_tmp1[8] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[10]))
               + (float)(p_tmp2[14] * p_tmp1[11]);
  dst->m[2][3] = (float)((float)((float)(p_tmp1[8] * p_tmp2[3]) + (float)(p_tmp1[9] * p_tmp2[7]))
                       + (float)(p_tmp2[11] * p_tmp1[10]))
               + (float)(p_tmp1[11] * p_tmp2[15]);
  dst->m[3][0] = (float)((float)((float)(p_tmp1[13] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[12]))
                       + (float)(p_tmp2[8] * p_tmp1[14]))
               + (float)(p_tmp2[12] * p_tmp1[15]);
  dst->m[3][1] = (float)((float)((float)(p_tmp1[13] * p_tmp2[5]) + (float)(p_tmp1[12] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[14]))
               + (float)(p_tmp2[13] * p_tmp1[15]);
  dst->m[3][2] = (float)((float)((float)(p_tmp1[13] * p_tmp2[6]) + (float)(p_tmp1[12] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[14]))
               + (float)(p_tmp2[14] * p_tmp1[15]);
  dst->m[3][3] = (float)((float)((float)(p_tmp1[13] * p_tmp2[7]) + (float)(p_tmp1[12] * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[14]))
               + (float)(p_tmp1[15] * p_tmp2[15]);
}

//------------------------------------------------------------------------------
// Address: 0x004C4740
// Name: void Vector3DMultiply(class VMatrix const __near &,class Vector const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Vector3DMultiply(const VMatrix *src1, Vector *src2, Vector *dst)
{
  Vector *p_tmp; // eax
  __int64 v4; // xmm0_8
  float z; // edx
  float v6; // xmm3_4
  float v7; // xmm2_4
  float v8; // xmm4_4
  Vector tmp; // [esp+0h] [ebp-18h] BYREF
  __int64 v10; // [esp+Ch] [ebp-Ch]
  float v11; // [esp+14h] [ebp-4h]

  p_tmp = src2;
  if ( src2 == dst )
    p_tmp = &tmp;
  v4 = *(_QWORD *)&p_tmp->x;
  z = p_tmp->z;
  v6 = src1->m[0][1];
  v7 = src1->m[0][0];
  v8 = src1->m[0][2];
  v10 = v4;
  v11 = z;
  dst->x = (float)((float)(v6 * *((float *)&v4 + 1)) + (float)(v7 * *(float *)&v4)) + (float)(v8 * z);
  dst->y = (float)((float)(src1->m[1][0] * *(float *)&v4) + (float)(src1->m[1][1] * *((float *)&v4 + 1)))
         + (float)(src1->m[1][2] * z);
  dst->z = (float)((float)(src1->m[2][0] * *(float *)&v4) + (float)(src1->m[2][1] * *((float *)&v4 + 1)))
         + (float)(src1->m[2][2] * z);
}

//------------------------------------------------------------------------------
// Address: 0x004C4800
// Name: void Vector3DMultiplyPositionProjective(class VMatrix const __near &,class Vector const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Vector3DMultiplyPositionProjective(const VMatrix *src1, Vector *src2, Vector *dst)
{
  Vector *p_tmp; // eax
  float z; // ecx
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm0_4
  float v8; // xmm4_4
  Vector tmp; // [esp+0h] [ebp-18h] BYREF
  __int64 v10; // [esp+Ch] [ebp-Ch]
  float v11; // [esp+14h] [ebp-4h]

  p_tmp = src2;
  if ( src2 == dst )
    p_tmp = &tmp;
  z = p_tmp->z;
  v10 = *(_QWORD *)&p_tmp->x;
  v5 = *(float *)&v10;
  v6 = *((float *)&v10 + 1);
  v11 = z;
  v7 = (float)((float)((float)(src1->m[3][0] * *(float *)&v10) + (float)(src1->m[3][1] * *((float *)&v10 + 1)))
             + (float)(src1->m[3][2] * z))
     + src1->m[3][3];
  if ( v7 != 0.0 )
    v7 = 1.0 / v7;
  dst->x = (float)((float)((float)(src1->m[0][1] * *((float *)&v10 + 1)) + (float)(src1->m[0][0] * *(float *)&v10))
                 + (float)(src1->m[0][2] * v11))
         + src1->m[0][3];
  dst->y = (float)((float)((float)(src1->m[1][0] * v5) + (float)(src1->m[1][1] * v6)) + (float)(src1->m[1][2] * z))
         + src1->m[1][3];
  v8 = (float)((float)((float)(src1->m[2][0] * v5) + (float)(src1->m[2][1] * v6)) + (float)(src1->m[2][2] * z))
     + src1->m[2][3];
  dst->x = dst->x * v7;
  dst->y = dst->y * v7;
  dst->z = v8 * v7;
}

//------------------------------------------------------------------------------
// Address: 0x004C4940
// Name: void MatrixBuildTranslation(class VMatrix __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildTranslation(VMatrix *dst, float x, float y, float z)
{
  *(_QWORD *)&dst->m[0][1] = 0;
  dst->m[1][0] = 0.0;
  dst->m[1][2] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[0][3] = x;
  dst->m[1][3] = y;
  dst->m[0][0] = 1.0;
  dst->m[1][1] = 1.0;
  dst->m[2][2] = 1.0;
  dst->m[3][3] = 1.0;
  dst->m[2][3] = z;
}

//------------------------------------------------------------------------------
// Address: 0x004C4A10
// Name: void MatrixBuildRotateZ(class VMatrix __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildRotateZ(VMatrix *dst, float angleDegrees)
{
  long double fSin; // [esp+0h] [ebp-4h]
  long double fSina; // [esp+0h] [ebp-4h]
  float fSinb; // [esp+0h] [ebp-4h]
  float radians; // [esp+10h] [ebp+Ch]

  radians = angleDegrees * 0.0174532925199433;
  __libm_sse2_sin(x: fSin);
  *(float *)&fSina = radians;
  __libm_sse2_cos(x: fSina);
  dst->m[0][0] = radians;
  LODWORD(dst->m[0][1]) = LODWORD(fSinb) ^ _mask__NegFloat_;
  dst->m[1][1] = radians;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = fSinb;
  *(_QWORD *)&dst->m[1][2] = 0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[2][2] = 1065353216;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x004C4AD0
// Name: void MatrixBuildScale(class VMatrix __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildScale(VMatrix *dst, unsigned int x, unsigned int y, float z)
{
  *(_QWORD *)&dst->m[0][0] = x;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = 0.0;
  *(_QWORD *)&dst->m[1][1] = y;
  dst->m[1][3] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  dst->m[2][3] = 0.0;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[2][2] = z;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x004C4B50
// Name: bool MatrixInverseGeneral(class VMatrix const __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl MatrixInverseGeneral(const VMatrix *src, VMatrix *dst)
{
  int v3; // edx
  _DWORD *v4; // eax
  float *v5; // ecx
  int v6; // ebx
  int v7; // edx
  int i; // edi
  int v9; // ecx
  float v10; // xmm0_4
  int v11; // eax
  float v12; // xmm1_4
  float v13; // xmm1_4
  float v14; // xmm1_4
  float v15; // xmm1_4
  float v16; // xmm1_4
  int v17; // eax
  float v18; // xmm1_4
  float *v19; // eax
  float v20; // xmm0_4
  int j; // esi
  float *v22; // ecx
  float v23; // xmm0_4
  int k; // edx
  float *v26; // ecx
  float v27; // esi
  float v28; // ecx
  float mat[4][8]; // [esp+0h] [ebp-90h] BYREF
  int rowMap[4]; // [esp+80h] [ebp-10h] BYREF

  v3 = 0;
  v4 = &mat[0][5];
  do
  {
    *(v4 - 5) = LODWORD(src->m[0][0]);
    v5 = (float *)(v4 - 5);
    v5[1] = src->m[0][1];
    v5[2] = src->m[0][2];
    v5[3] = src->m[0][3];
    *(v4 - 1) = 0;
    *v4 = 0;
    v4[1] = 0;
    v4[2] = 0;
    rowMap[v3] = v3;
    v6 = (int)&v4[v3++ - 5] + 16 - (_DWORD)rowMap;
    src = (const VMatrix *)((char *)src + 16);
    v4 += 8;
    *(int *)((char *)rowMap + v6) = 1065353216;
  }
  while ( v3 < 4 );
  v7 = 0;
  for ( i = 4; i > 0; --i )
  {
    v9 = -1;
    v10 = 0.000001;
    v11 = v7;
    if ( i >= 4 )
    {
      do
      {
        v12 = fabs(mat[rowMap[v11]][v7]);
        if ( v12 > v10 )
        {
          v9 = v11;
          v10 = v12;
        }
        v13 = fabs(mat[rowMap[v11 + 1]][v7]);
        if ( v13 > v10 )
        {
          v9 = v11 + 1;
          v10 = v13;
        }
        v14 = fabs(mat[rowMap[v11 + 2]][v7]);
        if ( v14 > v10 )
        {
          v9 = v11 + 2;
          v10 = v14;
        }
        v15 = fabs(mat[rowMap[v11 + 3]][v7]);
        if ( v15 > v10 )
        {
          v9 = v11 + 3;
          v10 = v15;
        }
        v11 += 4;
      }
      while ( v11 < 1 );
    }
    for ( ; v11 < 4; ++v11 )
    {
      v16 = fabs(mat[rowMap[v11]][v7]);
      if ( v16 > v10 )
      {
        v9 = v11;
        v10 = v16;
      }
    }
    if ( v9 == -1 )
      return 0;
    v17 = rowMap[v9];
    rowMap[v9] = rowMap[v7];
    rowMap[v7] = v17;
    v17 *= 32;
    v18 = *(float *)((char *)mat[0] + v17);
    v19 = (float *)((char *)mat[0] + v17);
    v20 = 1.0 / v19[v7];
    *v19 = v18 * v20;
    v19[1] = v19[1] * v20;
    v19[2] = v19[2] * v20;
    v19[3] = v19[3] * v20;
    v19[4] = v19[4] * v20;
    v19[5] = v19[5] * v20;
    v19[6] = v19[6] * v20;
    v19[7] = v19[7] * v20;
    v19[v7] = 1.0;
    for ( j = 0; j < 4; ++j )
    {
      if ( j != v7 )
      {
        v22 = mat[rowMap[j]];
        v23 = -v22[v7];
        *v22 = (float)(*v19 * v23) + *v22;
        v22[1] = (float)(v19[1] * v23) + v22[1];
        v22[2] = (float)(v19[2] * v23) + v22[2];
        v22[3] = (float)(v19[3] * v23) + v22[3];
        v22[4] = (float)(v19[4] * v23) + v22[4];
        v22[5] = (float)(v19[5] * v23) + v22[5];
        v22[6] = (float)(v19[6] * v23) + v22[6];
        v22[7] = (float)(v19[7] * v23) + v22[7];
        v22[v7] = 0.0;
      }
    }
    ++v7;
  }
  for ( k = 0; k < 4; ++k )
  {
    v26 = &mat[rowMap[k]][4];
    dst->m[0][0] = *v26;
    dst->m[0][1] = v26[1];
    v27 = v26[2];
    v28 = v26[3];
    dst->m[0][2] = v27;
    dst->m[0][3] = v28;
    dst = (VMatrix *)((char *)dst + 16);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004C4E70
// Name: void MatrixInverseTR(class VMatrix const __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixInverseTR(const VMatrix *src, VMatrix *dst)
{
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm4_4
  float v8; // xmm5_4
  float v9; // xmm1_4
  float v10; // xmm0_4

  dst->m[0][0] = src->m[0][0];
  dst->m[0][1] = src->m[1][0];
  dst->m[0][2] = src->m[2][0];
  dst->m[1][0] = src->m[0][1];
  dst->m[1][1] = src->m[1][1];
  dst->m[1][2] = src->m[2][1];
  dst->m[2][0] = src->m[0][2];
  dst->m[2][1] = src->m[1][2];
  dst->m[2][2] = src->m[2][2];
  v3 = -src->m[0][3];
  v4 = -src->m[1][3];
  v5 = -src->m[2][3];
  v6 = (float)((float)(dst->m[0][0] * v3) + (float)(v4 * dst->m[0][1])) + (float)(dst->m[0][2] * v5);
  v7 = (float)((float)(dst->m[1][1] * v4) + (float)(dst->m[1][0] * v3)) + (float)(v5 * dst->m[1][2]);
  v8 = dst->m[2][1] * v4;
  v9 = dst->m[2][0] * v3;
  v10 = dst->m[2][2] * v5;
  dst->m[0][3] = v6;
  dst->m[1][3] = v7;
  dst->m[2][3] = (float)(v8 + v9) + v10;
  *(_QWORD *)&dst->m[3][1] = 0;
  dst->m[3][0] = 0.0;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x004C4F70
// Name: void MatrixInverseTranspose(struct matrix3x4_t const __near &,struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixInverseTranspose(const matrix3x4_t *src, matrix3x4_t *dst)
{
  VMatrix out; // [esp+0h] [ebp-80h] BYREF
  VMatrix tmp; // [esp+40h] [ebp-40h] BYREF

  *(matrix3x4_t *)&tmp.m[0][0] = *src;
  memset(tmp.m[3], 0, 12);
  tmp.m[3][3] = 1.0;
  MatrixInverseGeneral(src: &tmp, dst: &out);
  MatrixTranspose(src: &out, dst: &out);
  *dst = *(matrix3x4_t *)&out.m[0][0];
}

} // namespace sceneviewer

// ============================================================
// Overlay from ScratchPad3DViewer (Missing functions)
// ============================================================
namespace ScratchPad3DViewer {

//------------------------------------------------------------------------------
// Address: 0x00408750
// Name: public: class VMatrix __near & VMatrix::operator=(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
VMatrix *__thiscall VMatrix::operator=(VMatrix *this, const VMatrix *mOther)
{
  *this = *mOther;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004087C0
// Name: public: void VMatrix::MatrixMul(class VMatrix const __near &,class VMatrix __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall VMatrix::MatrixMul(VMatrix *this, const VMatrix *vm, VMatrix *out)
{
  float v4; // xmm0_4
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm4_4
  float v8; // xmm5_4
  float v9; // xmm1_4
  float v10; // xmm7_4
  float v11; // xmm6_4
  float v12; // xmm0_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm3_4
  float v18; // xmm1_4
  float v19; // [esp+0h] [ebp-3Ch]
  float v20; // [esp+4h] [ebp-38h]
  float v21; // [esp+8h] [ebp-34h]
  float v22; // [esp+Ch] [ebp-30h]
  float v23; // [esp+10h] [ebp-2Ch]
  float v24; // [esp+14h] [ebp-28h]
  float v25; // [esp+18h] [ebp-24h]
  float v26; // [esp+1Ch] [ebp-20h]
  float v27; // [esp+20h] [ebp-1Ch]
  float v28; // [esp+24h] [ebp-18h]
  float v29; // [esp+28h] [ebp-14h]
  float v30; // [esp+28h] [ebp-14h]
  float v31; // [esp+28h] [ebp-14h]
  float v32; // [esp+2Ch] [ebp-10h]
  float v33; // [esp+30h] [ebp-Ch]
  float v34; // [esp+34h] [ebp-8h]
  __int64 v35; // [esp+34h] [ebp-8h]
  __int64 v36; // [esp+34h] [ebp-8h]
  float v37; // [esp+38h] [ebp-4h]
  float vma; // [esp+44h] [ebp+8h]

  v4 = this->m[0][1];
  v5 = this->m[0][2];
  v6 = this->m[0][3];
  v7 = (float)((float)((float)(this->m[0][0] * vm->m[0][1]) + (float)(v4 * vm->m[1][1])) + (float)(v5 * vm->m[2][1]))
     + (float)(v6 * vm->m[3][1]);
  v8 = (float)((float)((float)(vm->m[0][2] * this->m[0][0]) + (float)(vm->m[1][2] * v4)) + (float)(vm->m[2][2] * v5))
     + (float)(vm->m[3][2] * v6);
  v33 = vm->m[2][0];
  v37 = this->m[1][2];
  v32 = vm->m[3][0];
  v34 = this->m[1][3];
  v9 = vm->m[0][0];
  v10 = vm->m[1][0];
  v29 = this->m[1][1];
  v11 = (float)((float)((float)(vm->m[0][3] * this->m[0][0]) + (float)(vm->m[1][3] * v4)) + (float)(vm->m[2][3] * v5))
      + (float)(vm->m[3][3] * v6);
  v12 = this->m[1][0];
  v28 = (float)((float)((float)(vm->m[0][0] * v12) + (float)(v29 * v10)) + (float)(v37 * v33)) + (float)(v34 * v32);
  v27 = (float)((float)((float)(v12 * vm->m[0][1]) + (float)(v29 * vm->m[1][1])) + (float)(v37 * vm->m[2][1]))
      + (float)(v34 * vm->m[3][1]);
  v26 = (float)((float)((float)(v12 * vm->m[0][2]) + (float)(v29 * vm->m[1][2])) + (float)(v37 * vm->m[2][2]))
      + (float)(v34 * vm->m[3][2]);
  v13 = this->m[2][0];
  v25 = (float)((float)((float)(v12 * vm->m[0][3]) + (float)(v29 * vm->m[1][3])) + (float)(v37 * vm->m[2][3]))
      + (float)(v34 * vm->m[3][3]);
  v35 = *(_QWORD *)&this->m[2][2];
  v30 = this->m[2][1];
  v24 = (float)((float)((float)(v13 * vm->m[0][0]) + (float)(v30 * v10)) + (float)(*(float *)&v35 * v33))
      + (float)(*((float *)&v35 + 1) * v32);
  v23 = (float)((float)((float)(v13 * vm->m[0][1]) + (float)(v30 * vm->m[1][1])) + (float)(*(float *)&v35 * vm->m[2][1]))
      + (float)(*((float *)&v35 + 1) * vm->m[3][1]);
  v22 = (float)((float)((float)(v13 * vm->m[0][2]) + (float)(v30 * vm->m[1][2])) + (float)(*(float *)&v35 * vm->m[2][2]))
      + (float)(*((float *)&v35 + 1) * vm->m[3][2]);
  v21 = (float)((float)((float)(v13 * vm->m[0][3]) + (float)(v30 * vm->m[1][3])) + (float)(*(float *)&v35 * vm->m[2][3]))
      + (float)(*((float *)&v35 + 1) * vm->m[3][3]);
  v14 = this->m[3][0];
  v36 = *(_QWORD *)&this->m[3][2];
  v31 = this->m[3][1];
  v20 = (float)((float)((float)(v14 * vm->m[0][0]) + (float)(v31 * v10)) + (float)(*(float *)&v36 * v33))
      + (float)(*((float *)&v36 + 1) * v32);
  v19 = (float)((float)((float)(v14 * vm->m[0][1]) + (float)(v31 * vm->m[1][1])) + (float)(*(float *)&v36 * vm->m[2][1]))
      + (float)(*((float *)&v36 + 1) * vm->m[3][1]);
  v15 = v14 * vm->m[0][2];
  v16 = v14 * vm->m[0][3];
  vma = (float)((float)(v15 + (float)(v31 * vm->m[1][2])) + (float)(*(float *)&v36 * vm->m[2][2]))
      + (float)(*((float *)&v36 + 1) * vm->m[3][2]);
  v17 = (float)((float)(v16 + (float)(v31 * vm->m[1][3])) + (float)(*(float *)&v36 * vm->m[2][3]))
      + (float)(*((float *)&v36 + 1) * vm->m[3][3]);
  v18 = (float)((float)((float)(v9 * this->m[0][0]) + (float)(v10 * this->m[0][1])) + (float)(v33 * this->m[0][2]))
      + (float)(v32 * this->m[0][3]);
  out->m[1][0] = v28;
  out->m[1][1] = v27;
  out->m[1][2] = v26;
  out->m[1][3] = v25;
  out->m[0][0] = v18;
  out->m[0][1] = v7;
  out->m[0][2] = v8;
  out->m[0][3] = v11;
  out->m[2][0] = v24;
  out->m[2][1] = v23;
  out->m[2][2] = v22;
  out->m[2][3] = v21;
  out->m[3][0] = v20;
  out->m[3][1] = v19;
  out->m[3][2] = vma;
  out->m[3][3] = v17;
}

//------------------------------------------------------------------------------
// Address: 0x00408C80
// Name: public: class VMatrix VMatrix::operator*(class VMatrix const __near &)const
// Source: json
//------------------------------------------------------------------------------
VMatrix *__thiscall VMatrix::operator*(VMatrix *this, VMatrix *result, const VMatrix *vm)
{
  int v3; // edx

  VMatrix::MatrixMul(this, vm, out: result);
  return (VMatrix *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x00408CA0
// Name: public: void VMatrix::SetupMatrixOrgAngles(class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VMatrix::SetupMatrixOrgAngles(VMatrix *this, const Vector *origin, const QAngle *vAngles)
{
  float v4; // xmm1_4
  float v5; // xmm1_4
  double z; // st7
  float v7; // [esp+8h] [ebp-18h]
  float cr; // [esp+Ch] [ebp-14h]
  float sr; // [esp+10h] [ebp-10h]
  float sy; // [esp+14h] [ebp-Ch]
  float cy; // [esp+18h] [ebp-8h]
  float cp; // [esp+1Ch] [ebp-4h]
  float vAnglesa; // [esp+2Ch] [ebp+Ch]

  v4 = vAngles->y * 0.017453292;
  cy = cos(v4);
  sy = sin(v4);
  v5 = vAngles->x * 0.017453292;
  cp = cos(v5);
  vAnglesa = sin(v5);
  v7 = vAngles->z * 0.017453292;
  cr = cos(v7);
  sr = sin(v7);
  this->m[0][0] = cp * cy;
  this->m[1][0] = cp * sy;
  LODWORD(this->m[2][0]) = LODWORD(vAnglesa) ^ _mask__NegFloat_;
  this->m[0][1] = (float)((float)(sr * vAnglesa) * cy) - (float)(cr * sy);
  this->m[1][1] = (float)((float)(sr * vAnglesa) * sy) + (float)(cr * cy);
  this->m[2][1] = sr * cp;
  this->m[1][2] = (float)((float)(cr * vAnglesa) * sy) - (float)(sr * cy);
  this->m[0][3] = 0.0;
  this->m[1][3] = 0.0;
  this->m[2][3] = 0.0;
  this->m[0][2] = (float)((float)(cr * vAnglesa) * cy) + (float)(sr * sy);
  this->m[2][2] = cr * cp;
  this->m[0][3] = origin->x;
  this->m[1][3] = origin->y;
  z = origin->z;
  this->m[3][0] = 0.0;
  this->m[2][3] = z;
  *(_QWORD *)&this->m[3][1] = 0;
  this->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x00408E30
// Name: class VMatrix SetupMatrixIdentity(void)
// Source: json
//------------------------------------------------------------------------------
VMatrix *__cdecl SetupMatrixIdentity(VMatrix *result)
{
  *(_QWORD *)&result->m[0][0] = 1065353216;
  *(_QWORD *)&result->m[0][2] = 0;
  result->m[1][0] = 0.0;
  *(_QWORD *)&result->m[1][1] = 1065353216;
  result->m[1][3] = 0.0;
  *(_QWORD *)&result->m[2][0] = 0;
  *(_QWORD *)&result->m[2][2] = 1065353216;
  *(_QWORD *)&result->m[3][0] = 0;
  result->m[3][2] = 0.0;
  result->m[3][3] = 1.0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00408EA0
// Name: class VMatrix SetupMatrixTranslation(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
VMatrix *__cdecl SetupMatrixTranslation(VMatrix *result, const Vector *vTranslation)
{
  double y; // st7
  double z; // st7

  result->m[0][3] = vTranslation->x;
  y = vTranslation->y;
  result->m[0][0] = 1.0;
  result->m[1][3] = y;
  result->m[0][1] = 0.0;
  z = vTranslation->z;
  result->m[0][2] = 0.0;
  result->m[2][3] = z;
  result->m[1][0] = 0.0;
  *(_QWORD *)&result->m[1][1] = 1065353216;
  *(_QWORD *)&result->m[2][0] = 0;
  result->m[2][2] = 1.0;
  *(_QWORD *)&result->m[3][0] = 0;
  result->m[3][2] = 0.0;
  result->m[3][3] = 1.0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00408F10
// Name: class VMatrix SetupMatrixAngles(class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
VMatrix *__cdecl SetupMatrixAngles(VMatrix *result, const QAngle *vAngles)
{
  int v2; // ecx

  VMatrix::SetupMatrixOrgAngles(this: result, origin: &vec3_origin, vAngles);
  return (VMatrix *)v2;
}

//------------------------------------------------------------------------------
// Address: 0x00408F30
// Name: bool MatrixInverseGeneral(class VMatrix const __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl MatrixInverseGeneral(const VMatrix *src, VMatrix *dst)
{
  int v3; // edx
  _DWORD *v4; // eax
  float *v5; // ecx
  int v6; // ebx
  int v7; // edx
  int i; // edi
  int v9; // ecx
  float v10; // xmm0_4
  int v11; // eax
  float v12; // xmm1_4
  float v13; // xmm1_4
  float v14; // xmm1_4
  float v15; // xmm1_4
  float v16; // xmm1_4
  int v17; // eax
  float v18; // xmm1_4
  float *v19; // eax
  float v20; // xmm0_4
  int j; // esi
  float *v22; // ecx
  float v23; // xmm0_4
  int k; // edx
  float *v26; // ecx
  float v27; // esi
  float v28; // ecx
  float mat[4][8]; // [esp+0h] [ebp-90h] BYREF
  int rowMap[4]; // [esp+80h] [ebp-10h] BYREF

  v3 = 0;
  v4 = &mat[0][5];
  do
  {
    *(v4 - 5) = LODWORD(src->m[0][0]);
    v5 = (float *)(v4 - 5);
    v5[1] = src->m[0][1];
    v5[2] = src->m[0][2];
    v5[3] = src->m[0][3];
    *(v4 - 1) = 0;
    *v4 = 0;
    v4[1] = 0;
    v4[2] = 0;
    rowMap[v3] = v3;
    v6 = (int)&v4[v3++ - 5] + 16 - (_DWORD)rowMap;
    src = (const VMatrix *)((char *)src + 16);
    v4 += 8;
    *(int *)((char *)rowMap + v6) = 1065353216;
  }
  while ( v3 < 4 );
  v7 = 0;
  for ( i = 4; i > 0; --i )
  {
    v9 = -1;
    v10 = 0.000001;
    v11 = v7;
    if ( i >= 4 )
    {
      do
      {
        v12 = fabs(mat[rowMap[v11]][v7]);
        if ( v12 > v10 )
        {
          v9 = v11;
          v10 = v12;
        }
        v13 = fabs(mat[rowMap[v11 + 1]][v7]);
        if ( v13 > v10 )
        {
          v9 = v11 + 1;
          v10 = v13;
        }
        v14 = fabs(mat[rowMap[v11 + 2]][v7]);
        if ( v14 > v10 )
        {
          v9 = v11 + 2;
          v10 = v14;
        }
        v15 = fabs(mat[rowMap[v11 + 3]][v7]);
        if ( v15 > v10 )
        {
          v9 = v11 + 3;
          v10 = v15;
        }
        v11 += 4;
      }
      while ( v11 < 1 );
    }
    for ( ; v11 < 4; ++v11 )
    {
      v16 = fabs(mat[rowMap[v11]][v7]);
      if ( v16 > v10 )
      {
        v9 = v11;
        v10 = v16;
      }
    }
    if ( v9 == -1 )
      return 0;
    v17 = rowMap[v9];
    rowMap[v9] = rowMap[v7];
    rowMap[v7] = v17;
    v17 *= 32;
    v18 = *(float *)((char *)mat[0] + v17);
    v19 = (float *)((char *)mat[0] + v17);
    v20 = 1.0 / v19[v7];
    *v19 = v18 * v20;
    v19[1] = v19[1] * v20;
    v19[2] = v19[2] * v20;
    v19[3] = v19[3] * v20;
    v19[4] = v19[4] * v20;
    v19[5] = v19[5] * v20;
    v19[6] = v19[6] * v20;
    v19[7] = v19[7] * v20;
    v19[v7] = 1.0;
    for ( j = 0; j < 4; ++j )
    {
      if ( j != v7 )
      {
        v22 = mat[rowMap[j]];
        v23 = -v22[v7];
        *v22 = (float)(*v19 * v23) + *v22;
        v22[1] = (float)(v19[1] * v23) + v22[1];
        v22[2] = (float)(v19[2] * v23) + v22[2];
        v22[3] = (float)(v19[3] * v23) + v22[3];
        v22[4] = (float)(v19[4] * v23) + v22[4];
        v22[5] = (float)(v19[5] * v23) + v22[5];
        v22[6] = (float)(v19[6] * v23) + v22[6];
        v22[7] = (float)(v19[7] * v23) + v22[7];
        v22[v7] = 0.0;
      }
    }
    ++v7;
  }
  for ( k = 0; k < 4; ++k )
  {
    v26 = &mat[rowMap[k]][4];
    dst->m[0][0] = *v26;
    dst->m[0][1] = v26[1];
    v27 = v26[2];
    v28 = v26[3];
    dst->m[0][2] = v27;
    dst->m[0][3] = v28;
    dst = (VMatrix *)((char *)dst + 16);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00409250
// Name: public: class VMatrix VMatrix::Transpose(void)const
// Source: json
//------------------------------------------------------------------------------
VMatrix *__thiscall VMatrix::Transpose(VMatrix *this, VMatrix *result)
{
  result->m[0][0] = this->m[0][0];
  result->m[0][1] = this->m[1][0];
  result->m[0][2] = this->m[2][0];
  result->m[0][3] = this->m[3][0];
  result->m[1][0] = this->m[0][1];
  result->m[1][1] = this->m[1][1];
  result->m[1][2] = this->m[2][1];
  result->m[1][3] = this->m[3][1];
  result->m[2][0] = this->m[0][2];
  result->m[2][1] = this->m[1][2];
  result->m[2][2] = this->m[2][2];
  result->m[2][3] = this->m[3][2];
  result->m[3][0] = this->m[0][3];
  result->m[3][1] = this->m[1][3];
  result->m[3][2] = this->m[2][3];
  result->m[3][3] = this->m[3][3];
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004092C0
// Name: public: class VMatrix VMatrix::Transpose3x3(void)const
// Source: json
//------------------------------------------------------------------------------
VMatrix *__thiscall VMatrix::Transpose3x3(VMatrix *this, VMatrix *result)
{
  result->m[0][0] = this->m[0][0];
  result->m[0][1] = this->m[1][0];
  result->m[0][2] = this->m[2][0];
  result->m[0][3] = this->m[0][3];
  result->m[1][0] = this->m[0][1];
  result->m[1][1] = this->m[1][1];
  result->m[1][2] = this->m[2][1];
  result->m[1][3] = this->m[1][3];
  result->m[2][0] = this->m[0][2];
  result->m[2][1] = this->m[1][2];
  result->m[2][2] = this->m[2][2];
  result->m[2][3] = this->m[2][3];
  *(_OWORD *)&result->m[3][0] = *(_OWORD *)&this->m[3][0];
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00409330
// Name: public: bool VMatrix::InverseGeneral(class VMatrix __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall VMatrix::InverseGeneral(VMatrix *this, VMatrix *vInverse)
{
  return MatrixInverseGeneral(src: this, dst: vInverse);
}

} // namespace ScratchPad3DViewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x00469660
// Name: public: class VMatrix __near & VMatrix::operator=(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
VMatrix *__thiscall VMatrix::operator=(VMatrix *this, const VMatrix *mOther)
{
  *this = *mOther;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004696D0
// Name: public: bool VMatrix::operator==(class VMatrix const __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall VMatrix::operator==(VMatrix *this, const VMatrix *src)
{
  unsigned int v3; // eax

  v3 = 64;
  while ( LODWORD(src->m[0][0]) == LODWORD(this->m[0][0]) )
  {
    v3 -= 4;
    this = (VMatrix *)((char *)this + 4);
    src = (const VMatrix *)((char *)src + 4);
    if ( v3 < 4 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00469740
// Name: void MatrixSetIdentity(class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixSetIdentity(VMatrix *dst)
{
  *(_QWORD *)&dst->m[0][0] = 1065353216;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = 0.0;
  *(_QWORD *)&dst->m[1][1] = 1065353216;
  dst->m[1][3] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[2][2] = 1065353216;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x004697B0
// Name: void MatrixMultiply(class VMatrix const __near &,class VMatrix const __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixMultiply(const VMatrix *src1, const VMatrix *src2, VMatrix *dst)
{
  float *p_tmp1; // edx
  VMatrix *v4; // edi
  float *p_tmp2; // eax
  VMatrix tmp2; // [esp+Ch] [ebp-80h] BYREF
  VMatrix tmp1; // [esp+4Ch] [ebp-40h] BYREF

  p_tmp1 = (float *)&tmp1;
  if ( src1 != dst )
    p_tmp1 = (float *)src1;
  v4 = src2;
  p_tmp2 = (float *)&tmp2;
  if ( src2 != dst )
    p_tmp2 = (float *)src2;
  if ( src1 == dst && src1 != &tmp1 )
  {
    tmp1 = *src1;
    v4 = src2;
  }
  if ( v4 == dst && v4 != &tmp2 )
    tmp2 = *v4;
  dst->m[0][0] = (float)((float)((float)(p_tmp1[1] * p_tmp2[4]) + (float)(*p_tmp2 * *p_tmp1))
                       + (float)(p_tmp2[8] * p_tmp1[2]))
               + (float)(p_tmp2[12] * p_tmp1[3]);
  dst->m[0][1] = (float)((float)((float)(p_tmp1[1] * p_tmp2[5]) + (float)(*p_tmp1 * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[2]))
               + (float)(p_tmp2[13] * p_tmp1[3]);
  dst->m[0][2] = (float)((float)((float)(p_tmp1[1] * p_tmp2[6]) + (float)(*p_tmp1 * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[2]))
               + (float)(p_tmp2[14] * p_tmp1[3]);
  dst->m[0][3] = (float)((float)((float)(p_tmp1[1] * p_tmp2[7]) + (float)(*p_tmp1 * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[2]))
               + (float)(p_tmp2[15] * p_tmp1[3]);
  dst->m[1][0] = (float)((float)((float)(p_tmp1[5] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[4]))
                       + (float)(p_tmp2[8] * p_tmp1[6]))
               + (float)(p_tmp2[12] * p_tmp1[7]);
  dst->m[1][1] = (float)((float)((float)(p_tmp1[5] * p_tmp2[5]) + (float)(p_tmp1[4] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[6]))
               + (float)(p_tmp2[13] * p_tmp1[7]);
  dst->m[1][2] = (float)((float)((float)(p_tmp1[5] * p_tmp2[6]) + (float)(p_tmp1[4] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[6]))
               + (float)(p_tmp2[14] * p_tmp1[7]);
  dst->m[1][3] = (float)((float)((float)(p_tmp1[5] * p_tmp2[7]) + (float)(p_tmp1[4] * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[6]))
               + (float)(p_tmp1[7] * p_tmp2[15]);
  dst->m[2][0] = (float)((float)((float)(p_tmp1[9] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[8]))
                       + (float)(p_tmp2[8] * p_tmp1[10]))
               + (float)(p_tmp2[12] * p_tmp1[11]);
  dst->m[2][1] = (float)((float)((float)(p_tmp1[9] * p_tmp2[5]) + (float)(p_tmp1[8] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[10]))
               + (float)(p_tmp2[13] * p_tmp1[11]);
  dst->m[2][2] = (float)((float)((float)(p_tmp1[9] * p_tmp2[6]) + (float)(p_tmp1[8] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[10]))
               + (float)(p_tmp2[14] * p_tmp1[11]);
  dst->m[2][3] = (float)((float)((float)(p_tmp1[8] * p_tmp2[3]) + (float)(p_tmp1[9] * p_tmp2[7]))
                       + (float)(p_tmp2[11] * p_tmp1[10]))
               + (float)(p_tmp1[11] * p_tmp2[15]);
  dst->m[3][0] = (float)((float)((float)(p_tmp1[13] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[12]))
                       + (float)(p_tmp2[8] * p_tmp1[14]))
               + (float)(p_tmp2[12] * p_tmp1[15]);
  dst->m[3][1] = (float)((float)((float)(p_tmp1[13] * p_tmp2[5]) + (float)(p_tmp1[12] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[14]))
               + (float)(p_tmp2[13] * p_tmp1[15]);
  dst->m[3][2] = (float)((float)((float)(p_tmp1[13] * p_tmp2[6]) + (float)(p_tmp1[12] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[14]))
               + (float)(p_tmp2[14] * p_tmp1[15]);
  dst->m[3][3] = (float)((float)((float)(p_tmp1[13] * p_tmp2[7]) + (float)(p_tmp1[12] * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[14]))
               + (float)(p_tmp1[15] * p_tmp2[15]);
}

//------------------------------------------------------------------------------
// Address: 0x00469BA0
// Name: void MatrixBuildTranslation(class VMatrix __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildTranslation(VMatrix *dst, float x, float y, float z)
{
  *(_QWORD *)&dst->m[0][1] = 0;
  dst->m[1][0] = 0.0;
  dst->m[1][2] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[0][3] = x;
  dst->m[1][3] = y;
  dst->m[0][0] = 1.0;
  dst->m[1][1] = 1.0;
  dst->m[2][2] = 1.0;
  dst->m[3][3] = 1.0;
  dst->m[2][3] = z;
}

//------------------------------------------------------------------------------
// Address: 0x00469C70
// Name: void MatrixBuildRotateZ(class VMatrix __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildRotateZ(VMatrix *dst, float angleDegrees)
{
  long double fSin; // [esp+0h] [ebp-4h]
  long double fSina; // [esp+0h] [ebp-4h]
  float fSinb; // [esp+0h] [ebp-4h]
  float radians; // [esp+10h] [ebp+Ch]

  radians = angleDegrees * 0.0174532925199433;
  __libm_sse2_sin(x: fSin);
  *(float *)&fSina = radians;
  __libm_sse2_cos(x: fSina);
  dst->m[0][0] = radians;
  LODWORD(dst->m[0][1]) = LODWORD(fSinb) ^ _mask__NegFloat_;
  dst->m[1][1] = radians;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = fSinb;
  *(_QWORD *)&dst->m[1][2] = 0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[2][2] = 1065353216;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x00469D30
// Name: void MatrixBuildScale(class VMatrix __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildScale(VMatrix *dst, unsigned int x, unsigned int y, float z)
{
  *(_QWORD *)&dst->m[0][0] = x;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = 0.0;
  *(_QWORD *)&dst->m[1][1] = y;
  dst->m[1][3] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  dst->m[2][3] = 0.0;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[2][2] = z;
  dst->m[3][3] = 1.0;
}

} // namespace sfmgen

// ============================================================
// Overlay from shaderapidx10 (Missing functions)
// ============================================================
namespace shaderapidx10 {

//------------------------------------------------------------------------------
// Address: 0x10041B90
// Name: public: class VMatrix __near & VMatrix::operator=(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
VMatrix *__thiscall VMatrix::operator=(VMatrix *this, const VMatrix *mOther)
{
  *this = *mOther;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10041C00
// Name: bool MatrixInverseGeneral(class VMatrix const __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl MatrixInverseGeneral(const VMatrix *src, VMatrix *dst)
{
  int v3; // edx
  _DWORD *v4; // eax
  float *v5; // ecx
  int v6; // ebx
  int v7; // edx
  int i; // edi
  int v9; // ecx
  float v10; // xmm0_4
  int v11; // eax
  float v12; // xmm1_4
  float v13; // xmm1_4
  float v14; // xmm1_4
  float v15; // xmm1_4
  float v16; // xmm1_4
  int v17; // eax
  float v18; // xmm1_4
  float *v19; // eax
  float v20; // xmm0_4
  int j; // esi
  float *v22; // ecx
  float v23; // xmm0_4
  int k; // edx
  float *v26; // ecx
  float v27; // esi
  float v28; // ecx
  int rowMap[4]; // [esp+0h] [ebp-94h] BYREF
  _DWORD mat[33]; // [esp+10h] [ebp-84h] BYREF

  v3 = 0;
  v4 = &mat[6];
  do
  {
    *(v4 - 5) = LODWORD(src->m[0][0]);
    v5 = (float *)(v4 - 5);
    v5[1] = src->m[0][1];
    v5[2] = src->m[0][2];
    v5[3] = src->m[0][3];
    *(v4 - 1) = 0;
    *v4 = 0;
    v4[1] = 0;
    v4[2] = 0;
    rowMap[v3 + 1] = v3;
    v6 = (int)&v4[v3++ - 5] + 16 - (_DWORD)&rowMap[1];
    src = (const VMatrix *)((char *)src + 16);
    v4 += 8;
    *(int *)((char *)&rowMap[1] + v6) = 1065353216;
  }
  while ( v3 < 4 );
  v7 = 0;
  for ( i = 4; i > 0; --i )
  {
    v9 = -1;
    v10 = 0.000001;
    v11 = v7;
    if ( i >= 4 )
    {
      do
      {
        v12 = fabs(*(float *)&mat[8 * rowMap[v11 + 1] + 1 + v7]);
        if ( v12 > v10 )
        {
          v9 = v11;
          v10 = v12;
        }
        v13 = fabs(*(float *)&mat[8 * rowMap[v11 + 2] + 1 + v7]);
        if ( v13 > v10 )
        {
          v9 = v11 + 1;
          v10 = v13;
        }
        v14 = fabs(*(float *)&mat[8 * rowMap[v11 + 3] + 1 + v7]);
        if ( v14 > v10 )
        {
          v9 = v11 + 2;
          v10 = v14;
        }
        v15 = fabs(*(float *)&mat[8 * mat[v11] + 1 + v7]);
        if ( v15 > v10 )
        {
          v9 = v11 + 3;
          v10 = v15;
        }
        v11 += 4;
      }
      while ( v11 < 1 );
    }
    for ( ; v11 < 4; ++v11 )
    {
      v16 = fabs(*(float *)&mat[8 * rowMap[v11 + 1] + 1 + v7]);
      if ( v16 > v10 )
      {
        v9 = v11;
        v10 = v16;
      }
    }
    if ( v9 == -1 )
      return 0;
    v17 = rowMap[v9 + 1];
    rowMap[v9 + 1] = rowMap[v7 + 1];
    rowMap[v7 + 1] = v17;
    v17 *= 32;
    v18 = *(float *)((char *)&mat[1] + v17);
    v19 = (float *)((char *)&mat[1] + v17);
    v20 = 1.0 / v19[v7];
    *v19 = v18 * v20;
    v19[1] = v19[1] * v20;
    v19[2] = v19[2] * v20;
    v19[3] = v19[3] * v20;
    v19[4] = v19[4] * v20;
    v19[5] = v19[5] * v20;
    v19[6] = v19[6] * v20;
    v19[7] = v19[7] * v20;
    v19[v7] = 1.0;
    for ( j = 0; j < 4; ++j )
    {
      if ( j != v7 )
      {
        v22 = (float *)&mat[8 * rowMap[j + 1] + 1];
        v23 = -0.0 - v22[v7];
        *v22 = (float)(*v19 * v23) + *v22;
        v22[1] = (float)(v19[1] * v23) + v22[1];
        v22[2] = (float)(v19[2] * v23) + v22[2];
        v22[3] = (float)(v19[3] * v23) + v22[3];
        v22[4] = (float)(v19[4] * v23) + v22[4];
        v22[5] = (float)(v19[5] * v23) + v22[5];
        v22[6] = (float)(v19[6] * v23) + v22[6];
        v22[7] = (float)(v19[7] * v23) + v22[7];
        v22[v7] = 0.0;
      }
    }
    ++v7;
  }
  for ( k = 0; k < 4; ++k )
  {
    v26 = (float *)&mat[8 * rowMap[k + 1] + 5];
    dst->m[0][0] = *v26;
    dst->m[0][1] = v26[1];
    v27 = v26[2];
    v28 = v26[3];
    dst->m[0][2] = v27;
    dst->m[0][3] = v28;
    dst = (VMatrix *)((char *)dst + 16);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10041F20
// Name: public: void VMatrix::SetupMatrixOrgAngles(class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VMatrix::SetupMatrixOrgAngles(VMatrix *this, const Vector *origin, float vAngles)
{
  const QAngle *v3; // esi
  float v4; // xmm1_4
  float v5; // xmm1_4
  float v6; // xmm1_4
  float v7; // xmm5_4
  float v8; // xmm3_4
  float v9; // xmm4_4
  const QAngle *v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm2_4
  float v14; // xmm0_4
  double z; // st7
  float cy; // [esp+4h] [ebp-20h] BYREF
  float sy; // [esp+8h] [ebp-1Ch] BYREF
  float sr; // [esp+Ch] [ebp-18h] BYREF
  float cr; // [esp+10h] [ebp-14h] BYREF
  float v20; // [esp+14h] [ebp-10h] BYREF
  float v21; // [esp+18h] [ebp-Ch]
  float *p_sy; // [esp+1Ch] [ebp-8h]
  float v23; // [esp+20h] [ebp-4h]

  v3 = (const QAngle *)LODWORD(vAngles);
  v4 = *(float *)(LODWORD(vAngles) + 4) * 0.017453292;
  p_sy = &sy;
  v21 = COERCE_FLOAT(&sr);
  v23 = v4;
  sy = cos(v4);
  sr = sin(v4);
  v5 = *(float *)LODWORD(vAngles) * 0.017453292;
  p_sy = &cy;
  v23 = COERCE_FLOAT(&vAngles);
  v21 = v5;
  cy = cos(v5);
  vAngles = sin(v5);
  v6 = v3->z * 0.017453292;
  p_sy = &v20;
  v23 = COERCE_FLOAT(&cr);
  v21 = v6;
  v20 = cos(v6);
  cr = sin(v6);
  v7 = cy;
  v8 = sy;
  v9 = sr;
  *(float *)&v10 = vAngles;
  v11 = cr;
  this->m[0][0] = cy * sy;
  this->m[1][0] = v7 * v9;
  this->m[2][0] = -0.0 - *(float *)&v10;
  v12 = v11 * *(float *)&v10;
  v13 = v20;
  this->m[0][1] = (float)(v12 * v8) - (float)(v20 * v9);
  this->m[1][1] = (float)(v12 * v9) + (float)(v13 * v8);
  this->m[2][1] = v11 * v7;
  v14 = v13 * vAngles;
  this->m[1][2] = (float)((float)(v13 * vAngles) * v9) - (float)(v11 * v8);
  this->m[0][3] = 0.0;
  this->m[1][3] = 0.0;
  this->m[0][2] = (float)(v14 * v8) + (float)(v11 * v9);
  this->m[2][2] = v13 * v7;
  this->m[2][3] = 0.0;
  this->m[0][3] = origin->x;
  this->m[1][3] = origin->y;
  z = origin->z;
  *(_QWORD *)&this->m[3][0] = 0;
  this->m[2][3] = z;
  this->m[3][2] = 0.0;
  this->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x100420D0
// Name: void MatrixTranspose(class VMatrix const __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixTranspose(const VMatrix *src, VMatrix *dst)
{
  float v2; // xmm0_4
  float v3; // xmm0_4
  float v4; // xmm0_4
  float v5; // xmm0_4
  float v6; // xmm0_4
  float v7; // xmm0_4

  if ( src == dst )
  {
    v2 = dst->m[0][1];
    dst->m[0][1] = dst->m[1][0];
    dst->m[1][0] = v2;
    v3 = dst->m[0][2];
    dst->m[0][2] = dst->m[2][0];
    dst->m[2][0] = v3;
    v4 = dst->m[0][3];
    dst->m[0][3] = dst->m[3][0];
    dst->m[3][0] = v4;
    v5 = dst->m[1][2];
    dst->m[1][2] = dst->m[2][1];
    dst->m[2][1] = v5;
    v6 = dst->m[1][3];
    dst->m[1][3] = dst->m[3][1];
    dst->m[3][1] = v6;
    v7 = dst->m[2][3];
    dst->m[2][3] = dst->m[3][2];
    dst->m[3][2] = v7;
  }
  else
  {
    dst->m[0][0] = src->m[0][0];
    dst->m[0][1] = src->m[1][0];
    dst->m[0][2] = src->m[2][0];
    dst->m[0][3] = src->m[3][0];
    dst->m[1][0] = src->m[0][1];
    dst->m[1][1] = src->m[1][1];
    dst->m[1][2] = src->m[2][1];
    dst->m[1][3] = src->m[3][1];
    dst->m[2][0] = src->m[0][2];
    dst->m[2][1] = src->m[1][2];
    dst->m[2][2] = src->m[2][2];
    dst->m[2][3] = src->m[3][2];
    dst->m[3][0] = src->m[0][3];
    dst->m[3][1] = src->m[1][3];
    dst->m[3][2] = src->m[2][3];
    dst->m[3][3] = src->m[3][3];
  }
}

} // namespace shaderapidx10

// ============================================================
// Overlay from stdshader_dx9 (Missing functions)
// ============================================================
namespace stdshader_dx9 {

//------------------------------------------------------------------------------
// Address: 0x10047D30
// Name: public: class VMatrix __near & VMatrix::operator=(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
VMatrix *__thiscall VMatrix::operator=(VMatrix *this, const VMatrix *mOther)
{
  *this = *mOther;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10047DA0
// Name: public: void VMatrix::MatrixMul(class VMatrix const __near &,class VMatrix __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall VMatrix::MatrixMul(VMatrix *this, const VMatrix *vm, VMatrix *out)
{
  float v4; // xmm0_4
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm4_4
  float v8; // xmm5_4
  float v9; // xmm1_4
  float v10; // xmm7_4
  float v11; // xmm6_4
  float v12; // xmm0_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm3_4
  float v18; // xmm1_4
  float v19; // [esp+0h] [ebp-3Ch]
  float v20; // [esp+4h] [ebp-38h]
  float v21; // [esp+8h] [ebp-34h]
  float v22; // [esp+Ch] [ebp-30h]
  float v23; // [esp+10h] [ebp-2Ch]
  float v24; // [esp+14h] [ebp-28h]
  float v25; // [esp+18h] [ebp-24h]
  float v26; // [esp+1Ch] [ebp-20h]
  float v27; // [esp+20h] [ebp-1Ch]
  float v28; // [esp+24h] [ebp-18h]
  float v29; // [esp+28h] [ebp-14h]
  float v30; // [esp+28h] [ebp-14h]
  float v31; // [esp+28h] [ebp-14h]
  float v32; // [esp+2Ch] [ebp-10h]
  float v33; // [esp+30h] [ebp-Ch]
  float v34; // [esp+34h] [ebp-8h]
  __int64 v35; // [esp+34h] [ebp-8h]
  __int64 v36; // [esp+34h] [ebp-8h]
  float v37; // [esp+38h] [ebp-4h]
  float vma; // [esp+44h] [ebp+8h]

  v4 = this->m[0][1];
  v5 = this->m[0][2];
  v6 = this->m[0][3];
  v7 = (float)((float)((float)(this->m[0][0] * vm->m[0][1]) + (float)(v4 * vm->m[1][1])) + (float)(v5 * vm->m[2][1]))
     + (float)(v6 * vm->m[3][1]);
  v8 = (float)((float)((float)(vm->m[0][2] * this->m[0][0]) + (float)(vm->m[1][2] * v4)) + (float)(vm->m[2][2] * v5))
     + (float)(vm->m[3][2] * v6);
  v33 = vm->m[2][0];
  v37 = this->m[1][2];
  v32 = vm->m[3][0];
  v34 = this->m[1][3];
  v9 = vm->m[0][0];
  v10 = vm->m[1][0];
  v29 = this->m[1][1];
  v11 = (float)((float)((float)(vm->m[0][3] * this->m[0][0]) + (float)(vm->m[1][3] * v4)) + (float)(vm->m[2][3] * v5))
      + (float)(vm->m[3][3] * v6);
  v12 = this->m[1][0];
  v28 = (float)((float)((float)(vm->m[0][0] * v12) + (float)(v29 * v10)) + (float)(v37 * v33)) + (float)(v34 * v32);
  v27 = (float)((float)((float)(v12 * vm->m[0][1]) + (float)(v29 * vm->m[1][1])) + (float)(v37 * vm->m[2][1]))
      + (float)(v34 * vm->m[3][1]);
  v26 = (float)((float)((float)(v12 * vm->m[0][2]) + (float)(v29 * vm->m[1][2])) + (float)(v37 * vm->m[2][2]))
      + (float)(v34 * vm->m[3][2]);
  v13 = this->m[2][0];
  v25 = (float)((float)((float)(v12 * vm->m[0][3]) + (float)(v29 * vm->m[1][3])) + (float)(v37 * vm->m[2][3]))
      + (float)(v34 * vm->m[3][3]);
  v35 = *(_QWORD *)&this->m[2][2];
  v30 = this->m[2][1];
  v24 = (float)((float)((float)(v13 * vm->m[0][0]) + (float)(v30 * v10)) + (float)(*(float *)&v35 * v33))
      + (float)(*((float *)&v35 + 1) * v32);
  v23 = (float)((float)((float)(v13 * vm->m[0][1]) + (float)(v30 * vm->m[1][1])) + (float)(*(float *)&v35 * vm->m[2][1]))
      + (float)(*((float *)&v35 + 1) * vm->m[3][1]);
  v22 = (float)((float)((float)(v13 * vm->m[0][2]) + (float)(v30 * vm->m[1][2])) + (float)(*(float *)&v35 * vm->m[2][2]))
      + (float)(*((float *)&v35 + 1) * vm->m[3][2]);
  v21 = (float)((float)((float)(v13 * vm->m[0][3]) + (float)(v30 * vm->m[1][3])) + (float)(*(float *)&v35 * vm->m[2][3]))
      + (float)(*((float *)&v35 + 1) * vm->m[3][3]);
  v14 = this->m[3][0];
  v36 = *(_QWORD *)&this->m[3][2];
  v31 = this->m[3][1];
  v20 = (float)((float)((float)(v14 * vm->m[0][0]) + (float)(v31 * v10)) + (float)(*(float *)&v36 * v33))
      + (float)(*((float *)&v36 + 1) * v32);
  v19 = (float)((float)((float)(v14 * vm->m[0][1]) + (float)(v31 * vm->m[1][1])) + (float)(*(float *)&v36 * vm->m[2][1]))
      + (float)(*((float *)&v36 + 1) * vm->m[3][1]);
  v15 = v14 * vm->m[0][2];
  v16 = v14 * vm->m[0][3];
  vma = (float)((float)(v15 + (float)(v31 * vm->m[1][2])) + (float)(*(float *)&v36 * vm->m[2][2]))
      + (float)(*((float *)&v36 + 1) * vm->m[3][2]);
  v17 = (float)((float)(v16 + (float)(v31 * vm->m[1][3])) + (float)(*(float *)&v36 * vm->m[2][3]))
      + (float)(*((float *)&v36 + 1) * vm->m[3][3]);
  v18 = (float)((float)((float)(v9 * this->m[0][0]) + (float)(v10 * this->m[0][1])) + (float)(v33 * this->m[0][2]))
      + (float)(v32 * this->m[0][3]);
  out->m[1][0] = v28;
  out->m[1][1] = v27;
  out->m[1][2] = v26;
  out->m[1][3] = v25;
  out->m[0][0] = v18;
  out->m[0][1] = v7;
  out->m[0][2] = v8;
  out->m[0][3] = v11;
  out->m[2][0] = v24;
  out->m[2][1] = v23;
  out->m[2][2] = v22;
  out->m[2][3] = v21;
  out->m[3][0] = v20;
  out->m[3][1] = v19;
  out->m[3][2] = vma;
  out->m[3][3] = v17;
}

//------------------------------------------------------------------------------
// Address: 0x10048260
// Name: public: class VMatrix VMatrix::operator*(class VMatrix const __near &)const
// Source: json
//------------------------------------------------------------------------------
VMatrix *__thiscall VMatrix::operator*(VMatrix *this, VMatrix *result, const VMatrix *vm)
{
  int v3; // edx

  VMatrix::MatrixMul(this, vm, out: result);
  return (VMatrix *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x10048280
// Name: void MatrixSetIdentity(class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixSetIdentity(VMatrix *dst)
{
  *(_QWORD *)&dst->m[0][0] = 1065353216;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = 0.0;
  *(_QWORD *)&dst->m[1][1] = 1065353216;
  dst->m[1][3] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[2][2] = 1065353216;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x100482F0
// Name: void MatrixTranspose(class VMatrix const __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixTranspose(const VMatrix *src, VMatrix *dst)
{
  float v2; // xmm0_4
  float v3; // xmm0_4
  float v4; // xmm0_4
  float v5; // xmm0_4
  float v6; // xmm0_4
  float v7; // xmm0_4

  if ( src == dst )
  {
    v2 = dst->m[0][1];
    dst->m[0][1] = dst->m[1][0];
    dst->m[1][0] = v2;
    v3 = dst->m[0][2];
    dst->m[0][2] = dst->m[2][0];
    dst->m[2][0] = v3;
    v4 = dst->m[0][3];
    dst->m[0][3] = dst->m[3][0];
    dst->m[3][0] = v4;
    v5 = dst->m[1][2];
    dst->m[1][2] = dst->m[2][1];
    dst->m[2][1] = v5;
    v6 = dst->m[1][3];
    dst->m[1][3] = dst->m[3][1];
    dst->m[3][1] = v6;
    v7 = dst->m[2][3];
    dst->m[2][3] = dst->m[3][2];
    dst->m[3][2] = v7;
  }
  else
  {
    dst->m[0][0] = src->m[0][0];
    dst->m[0][1] = src->m[1][0];
    dst->m[0][2] = src->m[2][0];
    dst->m[0][3] = src->m[3][0];
    dst->m[1][0] = src->m[0][1];
    dst->m[1][1] = src->m[1][1];
    dst->m[1][2] = src->m[2][1];
    dst->m[1][3] = src->m[3][1];
    dst->m[2][0] = src->m[0][2];
    dst->m[2][1] = src->m[1][2];
    dst->m[2][2] = src->m[2][2];
    dst->m[2][3] = src->m[3][2];
    dst->m[3][0] = src->m[0][3];
    dst->m[3][1] = src->m[1][3];
    dst->m[3][2] = src->m[2][3];
    dst->m[3][3] = src->m[3][3];
  }
}

//------------------------------------------------------------------------------
// Address: 0x100483C0
// Name: void MatrixMultiply(class VMatrix const __near &,class VMatrix const __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixMultiply(const VMatrix *src1, const VMatrix *src2, VMatrix *dst)
{
  float *p_tmp1; // edx
  VMatrix *v4; // edi
  float *p_tmp2; // eax
  VMatrix tmp2; // [esp+Ch] [ebp-80h] BYREF
  VMatrix tmp1; // [esp+4Ch] [ebp-40h] BYREF

  p_tmp1 = (float *)&tmp1;
  if ( src1 != dst )
    p_tmp1 = (float *)src1;
  v4 = src2;
  p_tmp2 = (float *)&tmp2;
  if ( src2 != dst )
    p_tmp2 = (float *)src2;
  if ( src1 == dst && src1 != &tmp1 )
  {
    tmp1 = *src1;
    v4 = src2;
  }
  if ( v4 == dst && v4 != &tmp2 )
    tmp2 = *v4;
  dst->m[0][0] = (float)((float)((float)(p_tmp1[1] * p_tmp2[4]) + (float)(*p_tmp2 * *p_tmp1))
                       + (float)(p_tmp2[8] * p_tmp1[2]))
               + (float)(p_tmp2[12] * p_tmp1[3]);
  dst->m[0][1] = (float)((float)((float)(p_tmp1[1] * p_tmp2[5]) + (float)(*p_tmp1 * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[2]))
               + (float)(p_tmp2[13] * p_tmp1[3]);
  dst->m[0][2] = (float)((float)((float)(p_tmp1[1] * p_tmp2[6]) + (float)(*p_tmp1 * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[2]))
               + (float)(p_tmp2[14] * p_tmp1[3]);
  dst->m[0][3] = (float)((float)((float)(p_tmp1[1] * p_tmp2[7]) + (float)(*p_tmp1 * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[2]))
               + (float)(p_tmp2[15] * p_tmp1[3]);
  dst->m[1][0] = (float)((float)((float)(p_tmp1[5] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[4]))
                       + (float)(p_tmp2[8] * p_tmp1[6]))
               + (float)(p_tmp2[12] * p_tmp1[7]);
  dst->m[1][1] = (float)((float)((float)(p_tmp1[5] * p_tmp2[5]) + (float)(p_tmp1[4] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[6]))
               + (float)(p_tmp2[13] * p_tmp1[7]);
  dst->m[1][2] = (float)((float)((float)(p_tmp1[5] * p_tmp2[6]) + (float)(p_tmp1[4] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[6]))
               + (float)(p_tmp2[14] * p_tmp1[7]);
  dst->m[1][3] = (float)((float)((float)(p_tmp1[5] * p_tmp2[7]) + (float)(p_tmp1[4] * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[6]))
               + (float)(p_tmp1[7] * p_tmp2[15]);
  dst->m[2][0] = (float)((float)((float)(p_tmp1[9] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[8]))
                       + (float)(p_tmp2[8] * p_tmp1[10]))
               + (float)(p_tmp2[12] * p_tmp1[11]);
  dst->m[2][1] = (float)((float)((float)(p_tmp1[9] * p_tmp2[5]) + (float)(p_tmp1[8] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[10]))
               + (float)(p_tmp2[13] * p_tmp1[11]);
  dst->m[2][2] = (float)((float)((float)(p_tmp1[9] * p_tmp2[6]) + (float)(p_tmp1[8] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[10]))
               + (float)(p_tmp2[14] * p_tmp1[11]);
  dst->m[2][3] = (float)((float)((float)(p_tmp1[8] * p_tmp2[3]) + (float)(p_tmp1[9] * p_tmp2[7]))
                       + (float)(p_tmp2[11] * p_tmp1[10]))
               + (float)(p_tmp1[11] * p_tmp2[15]);
  dst->m[3][0] = (float)((float)((float)(p_tmp1[13] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[12]))
                       + (float)(p_tmp2[8] * p_tmp1[14]))
               + (float)(p_tmp2[12] * p_tmp1[15]);
  dst->m[3][1] = (float)((float)((float)(p_tmp1[13] * p_tmp2[5]) + (float)(p_tmp1[12] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[14]))
               + (float)(p_tmp2[13] * p_tmp1[15]);
  dst->m[3][2] = (float)((float)((float)(p_tmp1[13] * p_tmp2[6]) + (float)(p_tmp1[12] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[14]))
               + (float)(p_tmp2[14] * p_tmp1[15]);
  dst->m[3][3] = (float)((float)((float)(p_tmp1[13] * p_tmp2[7]) + (float)(p_tmp1[12] * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[14]))
               + (float)(p_tmp1[15] * p_tmp2[15]);
}

//------------------------------------------------------------------------------
// Address: 0x100487B0
// Name: public: class VMatrix VMatrix::Transpose(void)const
// Source: json
//------------------------------------------------------------------------------
VMatrix *__thiscall VMatrix::Transpose(VMatrix *this, VMatrix *result)
{
  result->m[0][0] = this->m[0][0];
  result->m[0][1] = this->m[1][0];
  result->m[0][2] = this->m[2][0];
  result->m[0][3] = this->m[3][0];
  result->m[1][0] = this->m[0][1];
  result->m[1][1] = this->m[1][1];
  result->m[1][2] = this->m[2][1];
  result->m[1][3] = this->m[3][1];
  result->m[2][0] = this->m[0][2];
  result->m[2][1] = this->m[1][2];
  result->m[2][2] = this->m[2][2];
  result->m[2][3] = this->m[3][2];
  result->m[3][0] = this->m[0][3];
  result->m[3][1] = this->m[1][3];
  result->m[3][2] = this->m[2][3];
  result->m[3][3] = this->m[3][3];
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10048820
// Name: public: class VMatrix VMatrix::Transpose3x3(void)const
// Source: json
//------------------------------------------------------------------------------
VMatrix *__thiscall VMatrix::Transpose3x3(VMatrix *this, VMatrix *result)
{
  result->m[0][0] = this->m[0][0];
  result->m[0][1] = this->m[1][0];
  result->m[0][2] = this->m[2][0];
  result->m[0][3] = this->m[0][3];
  result->m[1][0] = this->m[0][1];
  result->m[1][1] = this->m[1][1];
  result->m[1][2] = this->m[2][1];
  result->m[1][3] = this->m[1][3];
  result->m[2][0] = this->m[0][2];
  result->m[2][1] = this->m[1][2];
  result->m[2][2] = this->m[2][2];
  result->m[2][3] = this->m[2][3];
  *(_OWORD *)&result->m[3][0] = *(_OWORD *)&this->m[3][0];
  return result;
}

} // namespace stdshader_dx9

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004D8EA0
// Name: public: class VMatrix __near & VMatrix::operator=(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
VMatrix *__thiscall VMatrix::operator=(VMatrix *this, const VMatrix *mOther)
{
  *this = *mOther;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004D8F10
// Name: public: bool VMatrix::operator==(class VMatrix const __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall VMatrix::operator==(VMatrix *this, const VMatrix *src)
{
  unsigned int v3; // eax

  v3 = 64;
  while ( LODWORD(src->m[0][0]) == LODWORD(this->m[0][0]) )
  {
    v3 -= 4;
    this = (VMatrix *)((char *)this + 4);
    src = (const VMatrix *)((char *)src + 4);
    if ( v3 < 4 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004D8F80
// Name: void MatrixSetIdentity(class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixSetIdentity(VMatrix *dst)
{
  *(_QWORD *)&dst->m[0][0] = 1065353216;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = 0.0;
  *(_QWORD *)&dst->m[1][1] = 1065353216;
  dst->m[1][3] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[2][2] = 1065353216;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x004D8FF0
// Name: void MatrixTranspose(class VMatrix const __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixTranspose(const VMatrix *src, VMatrix *dst)
{
  float v2; // xmm0_4
  float v3; // xmm0_4
  float v4; // xmm0_4
  float v5; // xmm0_4
  float v6; // xmm0_4
  float v7; // xmm0_4

  if ( src == dst )
  {
    v2 = dst->m[0][1];
    dst->m[0][1] = dst->m[1][0];
    dst->m[1][0] = v2;
    v3 = dst->m[0][2];
    dst->m[0][2] = dst->m[2][0];
    dst->m[2][0] = v3;
    v4 = dst->m[0][3];
    dst->m[0][3] = dst->m[3][0];
    dst->m[3][0] = v4;
    v5 = dst->m[1][2];
    dst->m[1][2] = dst->m[2][1];
    dst->m[2][1] = v5;
    v6 = dst->m[1][3];
    dst->m[1][3] = dst->m[3][1];
    dst->m[3][1] = v6;
    v7 = dst->m[2][3];
    dst->m[2][3] = dst->m[3][2];
    dst->m[3][2] = v7;
  }
  else
  {
    dst->m[0][0] = src->m[0][0];
    dst->m[0][1] = src->m[1][0];
    dst->m[0][2] = src->m[2][0];
    dst->m[0][3] = src->m[3][0];
    dst->m[1][0] = src->m[0][1];
    dst->m[1][1] = src->m[1][1];
    dst->m[1][2] = src->m[2][1];
    dst->m[1][3] = src->m[3][1];
    dst->m[2][0] = src->m[0][2];
    dst->m[2][1] = src->m[1][2];
    dst->m[2][2] = src->m[2][2];
    dst->m[2][3] = src->m[3][2];
    dst->m[3][0] = src->m[0][3];
    dst->m[3][1] = src->m[1][3];
    dst->m[3][2] = src->m[2][3];
    dst->m[3][3] = src->m[3][3];
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D90C0
// Name: void MatrixMultiply(class VMatrix const __near &,class VMatrix const __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixMultiply(const VMatrix *src1, const VMatrix *src2, VMatrix *dst)
{
  float *p_tmp1; // edx
  VMatrix *v4; // edi
  float *p_tmp2; // eax
  VMatrix tmp2; // [esp+Ch] [ebp-80h] BYREF
  VMatrix tmp1; // [esp+4Ch] [ebp-40h] BYREF

  p_tmp1 = (float *)&tmp1;
  if ( src1 != dst )
    p_tmp1 = (float *)src1;
  v4 = src2;
  p_tmp2 = (float *)&tmp2;
  if ( src2 != dst )
    p_tmp2 = (float *)src2;
  if ( src1 == dst && src1 != &tmp1 )
  {
    tmp1 = *src1;
    v4 = src2;
  }
  if ( v4 == dst && v4 != &tmp2 )
    tmp2 = *v4;
  dst->m[0][0] = (float)((float)((float)(p_tmp1[1] * p_tmp2[4]) + (float)(*p_tmp2 * *p_tmp1))
                       + (float)(p_tmp2[8] * p_tmp1[2]))
               + (float)(p_tmp2[12] * p_tmp1[3]);
  dst->m[0][1] = (float)((float)((float)(p_tmp1[1] * p_tmp2[5]) + (float)(*p_tmp1 * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[2]))
               + (float)(p_tmp2[13] * p_tmp1[3]);
  dst->m[0][2] = (float)((float)((float)(p_tmp1[1] * p_tmp2[6]) + (float)(*p_tmp1 * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[2]))
               + (float)(p_tmp2[14] * p_tmp1[3]);
  dst->m[0][3] = (float)((float)((float)(p_tmp1[1] * p_tmp2[7]) + (float)(*p_tmp1 * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[2]))
               + (float)(p_tmp2[15] * p_tmp1[3]);
  dst->m[1][0] = (float)((float)((float)(p_tmp1[5] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[4]))
                       + (float)(p_tmp2[8] * p_tmp1[6]))
               + (float)(p_tmp2[12] * p_tmp1[7]);
  dst->m[1][1] = (float)((float)((float)(p_tmp1[5] * p_tmp2[5]) + (float)(p_tmp1[4] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[6]))
               + (float)(p_tmp2[13] * p_tmp1[7]);
  dst->m[1][2] = (float)((float)((float)(p_tmp1[5] * p_tmp2[6]) + (float)(p_tmp1[4] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[6]))
               + (float)(p_tmp2[14] * p_tmp1[7]);
  dst->m[1][3] = (float)((float)((float)(p_tmp1[5] * p_tmp2[7]) + (float)(p_tmp1[4] * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[6]))
               + (float)(p_tmp1[7] * p_tmp2[15]);
  dst->m[2][0] = (float)((float)((float)(p_tmp1[9] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[8]))
                       + (float)(p_tmp2[8] * p_tmp1[10]))
               + (float)(p_tmp2[12] * p_tmp1[11]);
  dst->m[2][1] = (float)((float)((float)(p_tmp1[9] * p_tmp2[5]) + (float)(p_tmp1[8] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[10]))
               + (float)(p_tmp2[13] * p_tmp1[11]);
  dst->m[2][2] = (float)((float)((float)(p_tmp1[9] * p_tmp2[6]) + (float)(p_tmp1[8] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[10]))
               + (float)(p_tmp2[14] * p_tmp1[11]);
  dst->m[2][3] = (float)((float)((float)(p_tmp1[8] * p_tmp2[3]) + (float)(p_tmp1[9] * p_tmp2[7]))
                       + (float)(p_tmp2[11] * p_tmp1[10]))
               + (float)(p_tmp1[11] * p_tmp2[15]);
  dst->m[3][0] = (float)((float)((float)(p_tmp1[13] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[12]))
                       + (float)(p_tmp2[8] * p_tmp1[14]))
               + (float)(p_tmp2[12] * p_tmp1[15]);
  dst->m[3][1] = (float)((float)((float)(p_tmp1[13] * p_tmp2[5]) + (float)(p_tmp1[12] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[14]))
               + (float)(p_tmp2[13] * p_tmp1[15]);
  dst->m[3][2] = (float)((float)((float)(p_tmp1[13] * p_tmp2[6]) + (float)(p_tmp1[12] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[14]))
               + (float)(p_tmp2[14] * p_tmp1[15]);
  dst->m[3][3] = (float)((float)((float)(p_tmp1[13] * p_tmp2[7]) + (float)(p_tmp1[12] * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[14]))
               + (float)(p_tmp1[15] * p_tmp2[15]);
}

//------------------------------------------------------------------------------
// Address: 0x004D94B0
// Name: void MatrixBuildTranslation(class VMatrix __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildTranslation(VMatrix *dst, float x, float y, float z)
{
  *(_QWORD *)&dst->m[0][1] = 0;
  dst->m[1][0] = 0.0;
  dst->m[1][2] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[0][3] = x;
  dst->m[1][3] = y;
  dst->m[0][0] = 1.0;
  dst->m[1][1] = 1.0;
  dst->m[2][2] = 1.0;
  dst->m[3][3] = 1.0;
  dst->m[2][3] = z;
}

//------------------------------------------------------------------------------
// Address: 0x004D9580
// Name: void MatrixBuildRotateZ(class VMatrix __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildRotateZ(VMatrix *dst, float angleDegrees)
{
  long double fSin; // [esp+0h] [ebp-4h]
  long double fSina; // [esp+0h] [ebp-4h]
  float fSinb; // [esp+0h] [ebp-4h]
  float radians; // [esp+10h] [ebp+Ch]

  radians = angleDegrees * 0.0174532925199433;
  __libm_sse2_sin(x: fSin);
  *(float *)&fSina = radians;
  __libm_sse2_cos(x: fSina);
  dst->m[0][0] = radians;
  LODWORD(dst->m[0][1]) = LODWORD(fSinb) ^ _mask__NegFloat_;
  dst->m[1][1] = radians;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = fSinb;
  *(_QWORD *)&dst->m[1][2] = 0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[2][2] = 1065353216;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x004D9640
// Name: void MatrixBuildScale(class VMatrix __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildScale(VMatrix *dst, unsigned int x, unsigned int y, float z)
{
  *(_QWORD *)&dst->m[0][0] = x;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = 0.0;
  *(_QWORD *)&dst->m[1][1] = y;
  dst->m[1][3] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  dst->m[2][3] = 0.0;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[2][2] = z;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x004D96C0
// Name: bool MatrixInverseGeneral(class VMatrix const __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl MatrixInverseGeneral(const VMatrix *src, VMatrix *dst)
{
  int v3; // edx
  _DWORD *v4; // eax
  float *v5; // ecx
  int v6; // ebx
  int v7; // edx
  int i; // edi
  int v9; // ecx
  float v10; // xmm0_4
  int v11; // eax
  float v12; // xmm1_4
  float v13; // xmm1_4
  float v14; // xmm1_4
  float v15; // xmm1_4
  float v16; // xmm1_4
  int v17; // eax
  float v18; // xmm1_4
  float *v19; // eax
  float v20; // xmm0_4
  int j; // esi
  float *v22; // ecx
  float v23; // xmm0_4
  int k; // edx
  float *v26; // ecx
  float v27; // esi
  float v28; // ecx
  float mat[4][8]; // [esp+0h] [ebp-90h] BYREF
  int rowMap[4]; // [esp+80h] [ebp-10h] BYREF

  v3 = 0;
  v4 = &mat[0][5];
  do
  {
    *(v4 - 5) = LODWORD(src->m[0][0]);
    v5 = (float *)(v4 - 5);
    v5[1] = src->m[0][1];
    v5[2] = src->m[0][2];
    v5[3] = src->m[0][3];
    *(v4 - 1) = 0;
    *v4 = 0;
    v4[1] = 0;
    v4[2] = 0;
    rowMap[v3] = v3;
    v6 = (int)&v4[v3++ - 5] + 16 - (_DWORD)rowMap;
    src = (const VMatrix *)((char *)src + 16);
    v4 += 8;
    *(int *)((char *)rowMap + v6) = 1065353216;
  }
  while ( v3 < 4 );
  v7 = 0;
  for ( i = 4; i > 0; --i )
  {
    v9 = -1;
    v10 = 0.000001;
    v11 = v7;
    if ( i >= 4 )
    {
      do
      {
        v12 = fabs(mat[rowMap[v11]][v7]);
        if ( v12 > v10 )
        {
          v9 = v11;
          v10 = v12;
        }
        v13 = fabs(mat[rowMap[v11 + 1]][v7]);
        if ( v13 > v10 )
        {
          v9 = v11 + 1;
          v10 = v13;
        }
        v14 = fabs(mat[rowMap[v11 + 2]][v7]);
        if ( v14 > v10 )
        {
          v9 = v11 + 2;
          v10 = v14;
        }
        v15 = fabs(mat[rowMap[v11 + 3]][v7]);
        if ( v15 > v10 )
        {
          v9 = v11 + 3;
          v10 = v15;
        }
        v11 += 4;
      }
      while ( v11 < 1 );
    }
    for ( ; v11 < 4; ++v11 )
    {
      v16 = fabs(mat[rowMap[v11]][v7]);
      if ( v16 > v10 )
      {
        v9 = v11;
        v10 = v16;
      }
    }
    if ( v9 == -1 )
      return 0;
    v17 = rowMap[v9];
    rowMap[v9] = rowMap[v7];
    rowMap[v7] = v17;
    v17 *= 32;
    v18 = *(float *)((char *)mat[0] + v17);
    v19 = (float *)((char *)mat[0] + v17);
    v20 = 1.0 / v19[v7];
    *v19 = v18 * v20;
    v19[1] = v19[1] * v20;
    v19[2] = v19[2] * v20;
    v19[3] = v19[3] * v20;
    v19[4] = v19[4] * v20;
    v19[5] = v19[5] * v20;
    v19[6] = v19[6] * v20;
    v19[7] = v19[7] * v20;
    v19[v7] = 1.0;
    for ( j = 0; j < 4; ++j )
    {
      if ( j != v7 )
      {
        v22 = mat[rowMap[j]];
        v23 = -v22[v7];
        *v22 = (float)(*v19 * v23) + *v22;
        v22[1] = (float)(v19[1] * v23) + v22[1];
        v22[2] = (float)(v19[2] * v23) + v22[2];
        v22[3] = (float)(v19[3] * v23) + v22[3];
        v22[4] = (float)(v19[4] * v23) + v22[4];
        v22[5] = (float)(v19[5] * v23) + v22[5];
        v22[6] = (float)(v19[6] * v23) + v22[6];
        v22[7] = (float)(v19[7] * v23) + v22[7];
        v22[v7] = 0.0;
      }
    }
    ++v7;
  }
  for ( k = 0; k < 4; ++k )
  {
    v26 = &mat[rowMap[k]][4];
    dst->m[0][0] = *v26;
    dst->m[0][1] = v26[1];
    v27 = v26[2];
    v28 = v26[3];
    dst->m[0][2] = v27;
    dst->m[0][3] = v28;
    dst = (VMatrix *)((char *)dst + 16);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004D99E0
// Name: void MatrixInverseTranspose(struct matrix3x4_t const __near &,struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixInverseTranspose(const matrix3x4_t *src, matrix3x4_t *dst)
{
  VMatrix out; // [esp+0h] [ebp-80h] BYREF
  VMatrix tmp; // [esp+40h] [ebp-40h] BYREF

  *(matrix3x4_t *)&tmp.m[0][0] = *src;
  memset(tmp.m[3], 0, 12);
  tmp.m[3][3] = 1.0;
  MatrixInverseGeneral(src: &tmp, dst: &out);
  MatrixTranspose(src: &out, dst: &out);
  *dst = *(matrix3x4_t *)&out.m[0][0];
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x00473E10
// Name: public: class VMatrix __near & VMatrix::operator=(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
VMatrix *__thiscall VMatrix::operator=(VMatrix *this, const VMatrix *mOther)
{
  *this = *mOther;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00473E80
// Name: public: bool VMatrix::operator==(class VMatrix const __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall VMatrix::operator==(VMatrix *this, const VMatrix *src)
{
  unsigned int v3; // eax

  v3 = 64;
  while ( LODWORD(src->m[0][0]) == LODWORD(this->m[0][0]) )
  {
    v3 -= 4;
    this = (VMatrix *)((char *)this + 4);
    src = (const VMatrix *)((char *)src + 4);
    if ( v3 < 4 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00473EF0
// Name: void MatrixSetIdentity(class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixSetIdentity(VMatrix *dst)
{
  *(_QWORD *)&dst->m[0][0] = 1065353216;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = 0.0;
  *(_QWORD *)&dst->m[1][1] = 1065353216;
  dst->m[1][3] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[2][2] = 1065353216;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x00473F60
// Name: void MatrixMultiply(class VMatrix const __near &,class VMatrix const __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixMultiply(const VMatrix *src1, const VMatrix *src2, VMatrix *dst)
{
  float *p_tmp1; // edx
  VMatrix *v4; // edi
  float *p_tmp2; // eax
  VMatrix tmp2; // [esp+Ch] [ebp-80h] BYREF
  VMatrix tmp1; // [esp+4Ch] [ebp-40h] BYREF

  p_tmp1 = (float *)&tmp1;
  if ( src1 != dst )
    p_tmp1 = (float *)src1;
  v4 = src2;
  p_tmp2 = (float *)&tmp2;
  if ( src2 != dst )
    p_tmp2 = (float *)src2;
  if ( src1 == dst && src1 != &tmp1 )
  {
    tmp1 = *src1;
    v4 = src2;
  }
  if ( v4 == dst && v4 != &tmp2 )
    tmp2 = *v4;
  dst->m[0][0] = (float)((float)((float)(p_tmp1[1] * p_tmp2[4]) + (float)(*p_tmp2 * *p_tmp1))
                       + (float)(p_tmp2[8] * p_tmp1[2]))
               + (float)(p_tmp2[12] * p_tmp1[3]);
  dst->m[0][1] = (float)((float)((float)(p_tmp1[1] * p_tmp2[5]) + (float)(*p_tmp1 * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[2]))
               + (float)(p_tmp2[13] * p_tmp1[3]);
  dst->m[0][2] = (float)((float)((float)(p_tmp1[1] * p_tmp2[6]) + (float)(*p_tmp1 * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[2]))
               + (float)(p_tmp2[14] * p_tmp1[3]);
  dst->m[0][3] = (float)((float)((float)(p_tmp1[1] * p_tmp2[7]) + (float)(*p_tmp1 * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[2]))
               + (float)(p_tmp2[15] * p_tmp1[3]);
  dst->m[1][0] = (float)((float)((float)(p_tmp1[5] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[4]))
                       + (float)(p_tmp2[8] * p_tmp1[6]))
               + (float)(p_tmp2[12] * p_tmp1[7]);
  dst->m[1][1] = (float)((float)((float)(p_tmp1[5] * p_tmp2[5]) + (float)(p_tmp1[4] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[6]))
               + (float)(p_tmp2[13] * p_tmp1[7]);
  dst->m[1][2] = (float)((float)((float)(p_tmp1[5] * p_tmp2[6]) + (float)(p_tmp1[4] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[6]))
               + (float)(p_tmp2[14] * p_tmp1[7]);
  dst->m[1][3] = (float)((float)((float)(p_tmp1[5] * p_tmp2[7]) + (float)(p_tmp1[4] * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[6]))
               + (float)(p_tmp1[7] * p_tmp2[15]);
  dst->m[2][0] = (float)((float)((float)(p_tmp1[9] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[8]))
                       + (float)(p_tmp2[8] * p_tmp1[10]))
               + (float)(p_tmp2[12] * p_tmp1[11]);
  dst->m[2][1] = (float)((float)((float)(p_tmp1[9] * p_tmp2[5]) + (float)(p_tmp1[8] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[10]))
               + (float)(p_tmp2[13] * p_tmp1[11]);
  dst->m[2][2] = (float)((float)((float)(p_tmp1[9] * p_tmp2[6]) + (float)(p_tmp1[8] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[10]))
               + (float)(p_tmp2[14] * p_tmp1[11]);
  dst->m[2][3] = (float)((float)((float)(p_tmp1[8] * p_tmp2[3]) + (float)(p_tmp1[9] * p_tmp2[7]))
                       + (float)(p_tmp2[11] * p_tmp1[10]))
               + (float)(p_tmp1[11] * p_tmp2[15]);
  dst->m[3][0] = (float)((float)((float)(p_tmp1[13] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[12]))
                       + (float)(p_tmp2[8] * p_tmp1[14]))
               + (float)(p_tmp2[12] * p_tmp1[15]);
  dst->m[3][1] = (float)((float)((float)(p_tmp1[13] * p_tmp2[5]) + (float)(p_tmp1[12] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[14]))
               + (float)(p_tmp2[13] * p_tmp1[15]);
  dst->m[3][2] = (float)((float)((float)(p_tmp1[13] * p_tmp2[6]) + (float)(p_tmp1[12] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[14]))
               + (float)(p_tmp2[14] * p_tmp1[15]);
  dst->m[3][3] = (float)((float)((float)(p_tmp1[13] * p_tmp2[7]) + (float)(p_tmp1[12] * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[14]))
               + (float)(p_tmp1[15] * p_tmp2[15]);
}

//------------------------------------------------------------------------------
// Address: 0x00474350
// Name: void MatrixBuildTranslation(class VMatrix __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildTranslation(VMatrix *dst, float x, float y, float z)
{
  *(_QWORD *)&dst->m[0][1] = 0;
  dst->m[1][0] = 0.0;
  dst->m[1][2] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[0][3] = x;
  dst->m[1][3] = y;
  dst->m[0][0] = 1.0;
  dst->m[1][1] = 1.0;
  dst->m[2][2] = 1.0;
  dst->m[3][3] = 1.0;
  dst->m[2][3] = z;
}

//------------------------------------------------------------------------------
// Address: 0x00474420
// Name: void MatrixBuildRotateZ(class VMatrix __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildRotateZ(VMatrix *dst, unsigned int angleDegrees)
{
  __m128d v2; // xmm0
  __m128i v3; // xmm0
  double v4; // xmm0_8
  double v5; // xmm0_8
  float v6; // xmm1_4
  float fSin; // [esp+0h] [ebp-4h]
  int radians; // [esp+10h] [ebp+Ch]

  v2 = _mm_cvtps_pd((__m128)angleDegrees);
  v2.m128d_f64[0] = v2.m128d_f64[0] * 0.0174532925199433;
  v3 = (__m128i)_mm_cvtpd_ps(v2);
  radians = v3.m128i_i32[0];
  *(double *)v3.m128i_i64 = *(float *)v3.m128i_i32;
  __libm_sse2_sin(X: v3);
  *(float *)&v4 = v4;
  fSin = *(float *)&v4;
  __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)(unsigned int)radians));
  v6 = v5;
  dst->m[0][0] = v6;
  LODWORD(dst->m[0][1]) = LODWORD(fSin) ^ _mask__NegFloat_;
  dst->m[1][1] = v6;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = fSin;
  *(_QWORD *)&dst->m[1][2] = 0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[2][2] = 1065353216;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x004744E0
// Name: void MatrixBuildScale(class VMatrix __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildScale(VMatrix *dst, unsigned int x, unsigned int y, float z)
{
  *(_QWORD *)&dst->m[0][0] = x;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = 0.0;
  *(_QWORD *)&dst->m[1][1] = y;
  dst->m[1][3] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  dst->m[2][3] = 0.0;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[2][2] = z;
  dst->m[3][3] = 1.0;
}

} // namespace uvlightmap

// ============================================================
// Overlay from vbsp (Missing functions)
// ============================================================
namespace vbsp {

//------------------------------------------------------------------------------
// Address: 0x00454F90
// Name: public: class VMatrix __near & VMatrix::operator=(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
VMatrix *__thiscall VMatrix::operator=(VMatrix *this, const VMatrix *mOther)
{
  *this = *mOther;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00455000
// Name: public: void VMatrix::MatrixMul(class VMatrix const __near &,class VMatrix __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall VMatrix::MatrixMul(VMatrix *this, const VMatrix *vm, VMatrix *out)
{
  float v4; // xmm0_4
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm4_4
  float v8; // xmm5_4
  float v9; // xmm1_4
  float v10; // xmm7_4
  float v11; // xmm6_4
  float v12; // xmm0_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm3_4
  float v18; // xmm1_4
  float v19; // [esp+0h] [ebp-3Ch]
  float v20; // [esp+4h] [ebp-38h]
  float v21; // [esp+8h] [ebp-34h]
  float v22; // [esp+Ch] [ebp-30h]
  float v23; // [esp+10h] [ebp-2Ch]
  float v24; // [esp+14h] [ebp-28h]
  float v25; // [esp+18h] [ebp-24h]
  float v26; // [esp+1Ch] [ebp-20h]
  float v27; // [esp+20h] [ebp-1Ch]
  float v28; // [esp+24h] [ebp-18h]
  float v29; // [esp+28h] [ebp-14h]
  float v30; // [esp+28h] [ebp-14h]
  float v31; // [esp+28h] [ebp-14h]
  float v32; // [esp+2Ch] [ebp-10h]
  float v33; // [esp+30h] [ebp-Ch]
  float v34; // [esp+34h] [ebp-8h]
  __int64 v35; // [esp+34h] [ebp-8h]
  __int64 v36; // [esp+34h] [ebp-8h]
  float v37; // [esp+38h] [ebp-4h]
  float vma; // [esp+44h] [ebp+8h]

  v4 = this->m[0][1];
  v5 = this->m[0][2];
  v6 = this->m[0][3];
  v7 = (float)((float)((float)(this->m[0][0] * vm->m[0][1]) + (float)(v4 * vm->m[1][1])) + (float)(v5 * vm->m[2][1]))
     + (float)(v6 * vm->m[3][1]);
  v8 = (float)((float)((float)(vm->m[0][2] * this->m[0][0]) + (float)(vm->m[1][2] * v4)) + (float)(vm->m[2][2] * v5))
     + (float)(vm->m[3][2] * v6);
  v33 = vm->m[2][0];
  v37 = this->m[1][2];
  v32 = vm->m[3][0];
  v34 = this->m[1][3];
  v9 = vm->m[0][0];
  v10 = vm->m[1][0];
  v29 = this->m[1][1];
  v11 = (float)((float)((float)(vm->m[0][3] * this->m[0][0]) + (float)(vm->m[1][3] * v4)) + (float)(vm->m[2][3] * v5))
      + (float)(vm->m[3][3] * v6);
  v12 = this->m[1][0];
  v28 = (float)((float)((float)(vm->m[0][0] * v12) + (float)(v29 * v10)) + (float)(v37 * v33)) + (float)(v34 * v32);
  v27 = (float)((float)((float)(v12 * vm->m[0][1]) + (float)(v29 * vm->m[1][1])) + (float)(v37 * vm->m[2][1]))
      + (float)(v34 * vm->m[3][1]);
  v26 = (float)((float)((float)(v12 * vm->m[0][2]) + (float)(v29 * vm->m[1][2])) + (float)(v37 * vm->m[2][2]))
      + (float)(v34 * vm->m[3][2]);
  v13 = this->m[2][0];
  v25 = (float)((float)((float)(v12 * vm->m[0][3]) + (float)(v29 * vm->m[1][3])) + (float)(v37 * vm->m[2][3]))
      + (float)(v34 * vm->m[3][3]);
  v35 = *(_QWORD *)&this->m[2][2];
  v30 = this->m[2][1];
  v24 = (float)((float)((float)(v13 * vm->m[0][0]) + (float)(v30 * v10)) + (float)(*(float *)&v35 * v33))
      + (float)(*((float *)&v35 + 1) * v32);
  v23 = (float)((float)((float)(v13 * vm->m[0][1]) + (float)(v30 * vm->m[1][1])) + (float)(*(float *)&v35 * vm->m[2][1]))
      + (float)(*((float *)&v35 + 1) * vm->m[3][1]);
  v22 = (float)((float)((float)(v13 * vm->m[0][2]) + (float)(v30 * vm->m[1][2])) + (float)(*(float *)&v35 * vm->m[2][2]))
      + (float)(*((float *)&v35 + 1) * vm->m[3][2]);
  v21 = (float)((float)((float)(v13 * vm->m[0][3]) + (float)(v30 * vm->m[1][3])) + (float)(*(float *)&v35 * vm->m[2][3]))
      + (float)(*((float *)&v35 + 1) * vm->m[3][3]);
  v14 = this->m[3][0];
  v36 = *(_QWORD *)&this->m[3][2];
  v31 = this->m[3][1];
  v20 = (float)((float)((float)(v14 * vm->m[0][0]) + (float)(v31 * v10)) + (float)(*(float *)&v36 * v33))
      + (float)(*((float *)&v36 + 1) * v32);
  v19 = (float)((float)((float)(v14 * vm->m[0][1]) + (float)(v31 * vm->m[1][1])) + (float)(*(float *)&v36 * vm->m[2][1]))
      + (float)(*((float *)&v36 + 1) * vm->m[3][1]);
  v15 = v14 * vm->m[0][2];
  v16 = v14 * vm->m[0][3];
  vma = (float)((float)(v15 + (float)(v31 * vm->m[1][2])) + (float)(*(float *)&v36 * vm->m[2][2]))
      + (float)(*((float *)&v36 + 1) * vm->m[3][2]);
  v17 = (float)((float)(v16 + (float)(v31 * vm->m[1][3])) + (float)(*(float *)&v36 * vm->m[2][3]))
      + (float)(*((float *)&v36 + 1) * vm->m[3][3]);
  v18 = (float)((float)((float)(v9 * this->m[0][0]) + (float)(v10 * this->m[0][1])) + (float)(v33 * this->m[0][2]))
      + (float)(v32 * this->m[0][3]);
  out->m[1][0] = v28;
  out->m[1][1] = v27;
  out->m[1][2] = v26;
  out->m[1][3] = v25;
  out->m[0][0] = v18;
  out->m[0][1] = v7;
  out->m[0][2] = v8;
  out->m[0][3] = v11;
  out->m[2][0] = v24;
  out->m[2][1] = v23;
  out->m[2][2] = v22;
  out->m[2][3] = v21;
  out->m[3][0] = v20;
  out->m[3][1] = v19;
  out->m[3][2] = vma;
  out->m[3][3] = v17;
}

//------------------------------------------------------------------------------
// Address: 0x004554C0
// Name: public: class VMatrix VMatrix::operator*(class VMatrix const __near &)const
// Source: json
//------------------------------------------------------------------------------
VMatrix *__thiscall VMatrix::operator*(VMatrix *this, VMatrix *result, const VMatrix *vm)
{
  int v3; // edx

  VMatrix::MatrixMul(this, vm, out: result);
  return (VMatrix *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x004554E0
// Name: void MatrixSetIdentity(class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixSetIdentity(VMatrix *dst)
{
  *(_QWORD *)&dst->m[0][0] = 1065353216;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = 0.0;
  *(_QWORD *)&dst->m[1][1] = 1065353216;
  dst->m[1][3] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[2][2] = 1065353216;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x00455690
// Name: class VMatrix SetupMatrixAxisRot(class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
VMatrix *__cdecl SetupMatrixAxisRot(VMatrix *result, const Vector *vAxis, float fDegrees)
{
  float v3; // xmm7_4
  float z; // xmm5_4
  float y; // xmm0_4
  float v7; // xmm4_4
  long double ty; // [esp+0h] [ebp-8h]
  long double tya; // [esp+0h] [ebp-8h]
  float tyb; // [esp+0h] [ebp-8h]
  float sx; // [esp+4h] [ebp-4h]
  float sxa; // [esp+4h] [ebp-4h]
  float sy; // [esp+18h] [ebp+10h]

  sy = fDegrees * 0.0174532925199433;
  __libm_sse2_sin(x: ty);
  *((float *)&tya + 1) = sy;
  __libm_sse2_cos(x: tya);
  v3 = sx;
  z = vAxis->z;
  y = vAxis->y;
  tyb = y * (float)(1.0 - sy);
  sxa = vAxis->x * sx;
  v7 = vAxis->x * (float)(1.0 - sy);
  result->m[0][0] = (float)(vAxis->x * v7) + sy;
  result->m[1][1] = (float)(y * tyb) + sy;
  result->m[0][1] = (float)(y * v7) - (float)(z * v3);
  result->m[2][1] = (float)(z * tyb) + sxa;
  result->m[0][2] = (float)(z * v7) + (float)(y * v3);
  result->m[2][2] = (float)((float)(z * (float)(1.0 - sy)) * z) + sy;
  result->m[0][3] = 0.0;
  result->m[1][0] = (float)(y * v7) + (float)(z * v3);
  result->m[1][2] = (float)(z * tyb) - sxa;
  result->m[1][3] = 0.0;
  result->m[2][0] = (float)(z * v7) - (float)(y * v3);
  result->m[2][3] = 0.0;
  *(_QWORD *)&result->m[3][0] = 0;
  result->m[3][2] = 0.0;
  result->m[3][3] = 1.0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004557F0
// Name: public: class VMatrix VMatrix::Transpose(void)const
// Source: json
//------------------------------------------------------------------------------
VMatrix *__thiscall VMatrix::Transpose(VMatrix *this, VMatrix *result)
{
  result->m[0][0] = this->m[0][0];
  result->m[0][1] = this->m[1][0];
  result->m[0][2] = this->m[2][0];
  result->m[0][3] = this->m[3][0];
  result->m[1][0] = this->m[0][1];
  result->m[1][1] = this->m[1][1];
  result->m[1][2] = this->m[2][1];
  result->m[1][3] = this->m[3][1];
  result->m[2][0] = this->m[0][2];
  result->m[2][1] = this->m[1][2];
  result->m[2][2] = this->m[2][2];
  result->m[2][3] = this->m[3][2];
  result->m[3][0] = this->m[0][3];
  result->m[3][1] = this->m[1][3];
  result->m[3][2] = this->m[2][3];
  result->m[3][3] = this->m[3][3];
  return result;
}

} // namespace vbsp

// ============================================================
// Overlay from vguimatsurface (Missing functions)
// ============================================================
namespace vguimatsurface {

//------------------------------------------------------------------------------
// Address: 0x10041530
// Name: void MatrixMultiply(class VMatrix const __near &,class VMatrix const __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixMultiply(VMatrix *src1, VMatrix *src2, VMatrix *dst)
{
  float *p_tmp1; // edx
  VMatrix *v4; // edi
  float *p_tmp2; // eax
  VMatrix tmp2; // [esp+Ch] [ebp-80h] BYREF
  VMatrix tmp1; // [esp+4Ch] [ebp-40h] BYREF

  p_tmp1 = (float *)&tmp1;
  if ( src1 != dst )
    p_tmp1 = (float *)src1;
  v4 = src2;
  p_tmp2 = (float *)&tmp2;
  if ( src2 != dst )
    p_tmp2 = (float *)src2;
  if ( src1 == dst && src1 != &tmp1 )
  {
    tmp1 = *src1;
    v4 = src2;
  }
  if ( v4 == dst && v4 != &tmp2 )
    tmp2 = *v4;
  dst->m[0][0] = (float)((float)((float)(p_tmp1[1] * p_tmp2[4]) + (float)(*p_tmp2 * *p_tmp1))
                       + (float)(p_tmp2[8] * p_tmp1[2]))
               + (float)(p_tmp2[12] * p_tmp1[3]);
  dst->m[0][1] = (float)((float)((float)(p_tmp1[1] * p_tmp2[5]) + (float)(*p_tmp1 * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[2]))
               + (float)(p_tmp2[13] * p_tmp1[3]);
  dst->m[0][2] = (float)((float)((float)(p_tmp1[1] * p_tmp2[6]) + (float)(*p_tmp1 * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[2]))
               + (float)(p_tmp2[14] * p_tmp1[3]);
  dst->m[0][3] = (float)((float)((float)(p_tmp1[1] * p_tmp2[7]) + (float)(*p_tmp1 * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[2]))
               + (float)(p_tmp2[15] * p_tmp1[3]);
  dst->m[1][0] = (float)((float)((float)(p_tmp1[5] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[4]))
                       + (float)(p_tmp2[8] * p_tmp1[6]))
               + (float)(p_tmp2[12] * p_tmp1[7]);
  dst->m[1][1] = (float)((float)((float)(p_tmp1[5] * p_tmp2[5]) + (float)(p_tmp1[4] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[6]))
               + (float)(p_tmp2[13] * p_tmp1[7]);
  dst->m[1][2] = (float)((float)((float)(p_tmp1[5] * p_tmp2[6]) + (float)(p_tmp1[4] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[6]))
               + (float)(p_tmp2[14] * p_tmp1[7]);
  dst->m[1][3] = (float)((float)((float)(p_tmp1[5] * p_tmp2[7]) + (float)(p_tmp1[4] * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[6]))
               + (float)(p_tmp1[7] * p_tmp2[15]);
  dst->m[2][0] = (float)((float)((float)(p_tmp1[9] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[8]))
                       + (float)(p_tmp2[8] * p_tmp1[10]))
               + (float)(p_tmp2[12] * p_tmp1[11]);
  dst->m[2][1] = (float)((float)((float)(p_tmp1[9] * p_tmp2[5]) + (float)(p_tmp1[8] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[10]))
               + (float)(p_tmp2[13] * p_tmp1[11]);
  dst->m[2][2] = (float)((float)((float)(p_tmp1[9] * p_tmp2[6]) + (float)(p_tmp1[8] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[10]))
               + (float)(p_tmp2[14] * p_tmp1[11]);
  dst->m[2][3] = (float)((float)((float)(p_tmp1[8] * p_tmp2[3]) + (float)(p_tmp1[9] * p_tmp2[7]))
                       + (float)(p_tmp2[11] * p_tmp1[10]))
               + (float)(p_tmp1[11] * p_tmp2[15]);
  dst->m[3][0] = (float)((float)((float)(p_tmp1[13] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[12]))
                       + (float)(p_tmp2[8] * p_tmp1[14]))
               + (float)(p_tmp2[12] * p_tmp1[15]);
  dst->m[3][1] = (float)((float)((float)(p_tmp1[13] * p_tmp2[5]) + (float)(p_tmp1[12] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[14]))
               + (float)(p_tmp2[13] * p_tmp1[15]);
  dst->m[3][2] = (float)((float)((float)(p_tmp1[13] * p_tmp2[6]) + (float)(p_tmp1[12] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[14]))
               + (float)(p_tmp2[14] * p_tmp1[15]);
  dst->m[3][3] = (float)((float)((float)(p_tmp1[13] * p_tmp2[7]) + (float)(p_tmp1[12] * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[14]))
               + (float)(p_tmp1[15] * p_tmp2[15]);
}

//------------------------------------------------------------------------------
// Address: 0x10041920
// Name: void MatrixBuildScale(class VMatrix __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildScale(VMatrix *dst, unsigned int x, unsigned int y, float z)
{
  *(_QWORD *)&dst->m[0][0] = x;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = 0.0;
  *(_QWORD *)&dst->m[1][1] = y;
  dst->m[1][3] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  dst->m[2][3] = 0.0;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[2][2] = z;
  dst->m[3][3] = 1.0;
}

} // namespace vguimatsurface

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x00530CE0
// Name: public: class VMatrix __near & VMatrix::operator=(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
VMatrix *__thiscall VMatrix::operator=(VMatrix *this, const VMatrix *mOther)
{
  *this = *mOther;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00530D50
// Name: public: bool VMatrix::operator==(class VMatrix const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall VMatrix::operator==(VMatrix *this, const VMatrix *src)
{
  unsigned int i; // edx
  int v5; // esi
  unsigned int v6; // edx
  unsigned __int8 *v7; // eax
  unsigned __int8 *v8; // ecx
  unsigned int v9; // edx
  unsigned __int8 *v10; // eax
  unsigned __int8 *v11; // ecx
  unsigned __int8 *v12; // eax
  unsigned __int8 *v13; // ecx
  int v14; // eax

  for ( i = 64; i >= 4; i -= 4 )
  {
    if ( LODWORD(src->m[0][0]) != LODWORD(this->m[0][0]) )
      goto LABEL_5;
    this = (VMatrix *)((char *)this + 4);
    src = (const VMatrix *)((char *)src + 4);
  }
  if ( i == 0 )
  {
LABEL_14:
    v14 = 0;
    return v14 == 0;
  }
LABEL_5:
  v5 = LOBYTE(src->m[0][0]) - LOBYTE(this->m[0][0]);
  if ( v5 == 0 )
  {
    v6 = i - 1;
    v7 = (unsigned __int8 *)&this->m[0][0] + 1;
    v8 = (unsigned __int8 *)&src->m[0][0] + 1;
    if ( v6 == 0 )
      goto LABEL_14;
    v5 = *v8 - *v7;
    if ( v5 == 0 )
    {
      v9 = v6 - 1;
      v10 = v7 + 1;
      v11 = v8 + 1;
      if ( v9 == 0 )
        goto LABEL_14;
      v5 = *v11 - *v10;
      if ( v5 == 0 )
      {
        v12 = v10 + 1;
        v13 = v11 + 1;
        if ( v9 == 1 )
          goto LABEL_14;
        v5 = *v13 - *v12;
        if ( v5 == 0 )
          goto LABEL_14;
      }
    }
  }
  v14 = 1;
  if ( v5 <= 0 )
    return false;
  return v14 == 0;
}

//------------------------------------------------------------------------------
// Address: 0x00530E00
// Name: void MatrixSetIdentity(class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixSetIdentity(VMatrix *dst)
{
  *(_QWORD *)&dst->m[0][0] = 1065353216;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = 0.0;
  *(_QWORD *)&dst->m[1][1] = 1065353216;
  dst->m[1][3] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[2][2] = 1065353216;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[3][3] = 1.0;
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x0056EF60
// Name: public: class VMatrix __near & VMatrix::operator=(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
VMatrix *__thiscall VMatrix::operator=(VMatrix *this, const VMatrix *mOther)
{
  *this = *mOther;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0056EFD0
// Name: public: bool VMatrix::operator==(class VMatrix const __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall VMatrix::operator==(VMatrix *this, const VMatrix *src)
{
  unsigned int v3; // eax

  v3 = 64;
  while ( LODWORD(src->m[0][0]) == LODWORD(this->m[0][0]) )
  {
    v3 -= 4;
    this = (VMatrix *)((char *)this + 4);
    src = (const VMatrix *)((char *)src + 4);
    if ( v3 < 4 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0056F040
// Name: public: void VMatrix::MatrixMul(class VMatrix const __near &,class VMatrix __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall VMatrix::MatrixMul(VMatrix *this, const VMatrix *vm, VMatrix *out)
{
  float v4; // xmm0_4
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm4_4
  float v8; // xmm5_4
  float v9; // xmm1_4
  float v10; // xmm7_4
  float v11; // xmm6_4
  float v12; // xmm0_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm3_4
  float v18; // xmm1_4
  float v19; // [esp+0h] [ebp-3Ch]
  float v20; // [esp+4h] [ebp-38h]
  float v21; // [esp+8h] [ebp-34h]
  float v22; // [esp+Ch] [ebp-30h]
  float v23; // [esp+10h] [ebp-2Ch]
  float v24; // [esp+14h] [ebp-28h]
  float v25; // [esp+18h] [ebp-24h]
  float v26; // [esp+1Ch] [ebp-20h]
  float v27; // [esp+20h] [ebp-1Ch]
  float v28; // [esp+24h] [ebp-18h]
  float v29; // [esp+28h] [ebp-14h]
  float v30; // [esp+28h] [ebp-14h]
  float v31; // [esp+28h] [ebp-14h]
  float v32; // [esp+2Ch] [ebp-10h]
  float v33; // [esp+30h] [ebp-Ch]
  float v34; // [esp+34h] [ebp-8h]
  __int64 v35; // [esp+34h] [ebp-8h]
  __int64 v36; // [esp+34h] [ebp-8h]
  float v37; // [esp+38h] [ebp-4h]
  float vma; // [esp+44h] [ebp+8h]

  v4 = this->m[0][1];
  v5 = this->m[0][2];
  v6 = this->m[0][3];
  v7 = (float)((float)((float)(this->m[0][0] * vm->m[0][1]) + (float)(v4 * vm->m[1][1])) + (float)(v5 * vm->m[2][1]))
     + (float)(v6 * vm->m[3][1]);
  v8 = (float)((float)((float)(vm->m[0][2] * this->m[0][0]) + (float)(vm->m[1][2] * v4)) + (float)(vm->m[2][2] * v5))
     + (float)(vm->m[3][2] * v6);
  v33 = vm->m[2][0];
  v37 = this->m[1][2];
  v32 = vm->m[3][0];
  v34 = this->m[1][3];
  v9 = vm->m[0][0];
  v10 = vm->m[1][0];
  v29 = this->m[1][1];
  v11 = (float)((float)((float)(vm->m[0][3] * this->m[0][0]) + (float)(vm->m[1][3] * v4)) + (float)(vm->m[2][3] * v5))
      + (float)(vm->m[3][3] * v6);
  v12 = this->m[1][0];
  v28 = (float)((float)((float)(vm->m[0][0] * v12) + (float)(v29 * v10)) + (float)(v37 * v33)) + (float)(v34 * v32);
  v27 = (float)((float)((float)(v12 * vm->m[0][1]) + (float)(v29 * vm->m[1][1])) + (float)(v37 * vm->m[2][1]))
      + (float)(v34 * vm->m[3][1]);
  v26 = (float)((float)((float)(v12 * vm->m[0][2]) + (float)(v29 * vm->m[1][2])) + (float)(v37 * vm->m[2][2]))
      + (float)(v34 * vm->m[3][2]);
  v13 = this->m[2][0];
  v25 = (float)((float)((float)(v12 * vm->m[0][3]) + (float)(v29 * vm->m[1][3])) + (float)(v37 * vm->m[2][3]))
      + (float)(v34 * vm->m[3][3]);
  v35 = *(_QWORD *)&this->m[2][2];
  v30 = this->m[2][1];
  v24 = (float)((float)((float)(v13 * vm->m[0][0]) + (float)(v30 * v10)) + (float)(*(float *)&v35 * v33))
      + (float)(*((float *)&v35 + 1) * v32);
  v23 = (float)((float)((float)(v13 * vm->m[0][1]) + (float)(v30 * vm->m[1][1])) + (float)(*(float *)&v35 * vm->m[2][1]))
      + (float)(*((float *)&v35 + 1) * vm->m[3][1]);
  v22 = (float)((float)((float)(v13 * vm->m[0][2]) + (float)(v30 * vm->m[1][2])) + (float)(*(float *)&v35 * vm->m[2][2]))
      + (float)(*((float *)&v35 + 1) * vm->m[3][2]);
  v21 = (float)((float)((float)(v13 * vm->m[0][3]) + (float)(v30 * vm->m[1][3])) + (float)(*(float *)&v35 * vm->m[2][3]))
      + (float)(*((float *)&v35 + 1) * vm->m[3][3]);
  v14 = this->m[3][0];
  v36 = *(_QWORD *)&this->m[3][2];
  v31 = this->m[3][1];
  v20 = (float)((float)((float)(v14 * vm->m[0][0]) + (float)(v31 * v10)) + (float)(*(float *)&v36 * v33))
      + (float)(*((float *)&v36 + 1) * v32);
  v19 = (float)((float)((float)(v14 * vm->m[0][1]) + (float)(v31 * vm->m[1][1])) + (float)(*(float *)&v36 * vm->m[2][1]))
      + (float)(*((float *)&v36 + 1) * vm->m[3][1]);
  v15 = v14 * vm->m[0][2];
  v16 = v14 * vm->m[0][3];
  vma = (float)((float)(v15 + (float)(v31 * vm->m[1][2])) + (float)(*(float *)&v36 * vm->m[2][2]))
      + (float)(*((float *)&v36 + 1) * vm->m[3][2]);
  v17 = (float)((float)(v16 + (float)(v31 * vm->m[1][3])) + (float)(*(float *)&v36 * vm->m[2][3]))
      + (float)(*((float *)&v36 + 1) * vm->m[3][3]);
  v18 = (float)((float)((float)(v9 * this->m[0][0]) + (float)(v10 * this->m[0][1])) + (float)(v33 * this->m[0][2]))
      + (float)(v32 * this->m[0][3]);
  out->m[1][0] = v28;
  out->m[1][1] = v27;
  out->m[1][2] = v26;
  out->m[1][3] = v25;
  out->m[0][0] = v18;
  out->m[0][1] = v7;
  out->m[0][2] = v8;
  out->m[0][3] = v11;
  out->m[2][0] = v24;
  out->m[2][1] = v23;
  out->m[2][2] = v22;
  out->m[2][3] = v21;
  out->m[3][0] = v20;
  out->m[3][1] = v19;
  out->m[3][2] = vma;
  out->m[3][3] = v17;
}

//------------------------------------------------------------------------------
// Address: 0x0056F500
// Name: public: class VMatrix VMatrix::operator*(class VMatrix const __near &)const
// Source: json
//------------------------------------------------------------------------------
VMatrix *__thiscall VMatrix::operator*(VMatrix *this, VMatrix *result, const VMatrix *vm)
{
  int v3; // edx

  VMatrix::MatrixMul(this, vm, out: result);
  return (VMatrix *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x0056F520
// Name: void MatrixSetIdentity(class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixSetIdentity(VMatrix *dst)
{
  *(_QWORD *)&dst->m[0][0] = 1065353216;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = 0.0;
  *(_QWORD *)&dst->m[1][1] = 1065353216;
  dst->m[1][3] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[2][2] = 1065353216;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x0056F590
// Name: void MatrixToAngles(class VMatrix const __near &,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall MatrixToAngles(int a1@<esi>, const VMatrix *src, QAngle *vAngles)
{
  float v3; // xmm0_4
  float v4; // xmm2_4
  long double v5; // [esp-4h] [ebp-28h]
  long double v6; // [esp-4h] [ebp-28h]
  long double v7; // [esp-4h] [ebp-28h]
  long double v8; // [esp-4h] [ebp-28h]
  long double up_4; // [esp+4h] [ebp-20h]
  long double up_4a; // [esp+4h] [ebp-20h]
  long double up_4b; // [esp+4h] [ebp-20h]
  long double up_4c; // [esp+4h] [ebp-20h]
  float left_8; // [esp+14h] [ebp-10h]
  float forward_8; // [esp+20h] [ebp-4h]

  v3 = src->m[1][0];
  left_8 = src->m[2][1];
  HIDWORD(up_4) = LODWORD(src->m[2][2]);
  forward_8 = src->m[2][0];
  v4 = src->m[0][1];
  LODWORD(v5) = a1;
  if ( fsqrt((float)(v3 * v3) + (float)(src->m[0][0] * src->m[0][0])) <= 0.001 )
  {
    __libm_sse2_atan2(y: v5, x: up_4);
    vAngles->y = COERCE_FLOAT(LODWORD(v4) ^ _mask__NegFloat_) * 57.29578;
    __libm_sse2_atan2(y: v8, x: up_4c);
    vAngles->x = COERCE_FLOAT(LODWORD(forward_8) ^ _mask__NegFloat_) * 57.29578;
    vAngles->z = 0.0;
  }
  else
  {
    __libm_sse2_atan2(y: v5, x: up_4);
    vAngles->y = v3 * 57.29578;
    __libm_sse2_atan2(y: v6, x: up_4a);
    vAngles->x = COERCE_FLOAT(LODWORD(forward_8) ^ _mask__NegFloat_) * 57.29578;
    __libm_sse2_atan2(y: v7, x: up_4b);
    vAngles->z = left_8 * 57.29578;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0056F6D0
// Name: void MatrixMultiply(class VMatrix const __near &,class VMatrix const __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixMultiply(const VMatrix *src1, const VMatrix *src2, VMatrix *dst)
{
  float *p_tmp1; // edx
  VMatrix *v4; // edi
  float *p_tmp2; // eax
  VMatrix tmp2; // [esp+Ch] [ebp-80h] BYREF
  VMatrix tmp1; // [esp+4Ch] [ebp-40h] BYREF

  p_tmp1 = (float *)&tmp1;
  if ( src1 != dst )
    p_tmp1 = (float *)src1;
  v4 = src2;
  p_tmp2 = (float *)&tmp2;
  if ( src2 != dst )
    p_tmp2 = (float *)src2;
  if ( src1 == dst && src1 != &tmp1 )
  {
    tmp1 = *src1;
    v4 = src2;
  }
  if ( v4 == dst && v4 != &tmp2 )
    tmp2 = *v4;
  dst->m[0][0] = (float)((float)((float)(p_tmp1[1] * p_tmp2[4]) + (float)(*p_tmp2 * *p_tmp1))
                       + (float)(p_tmp2[8] * p_tmp1[2]))
               + (float)(p_tmp2[12] * p_tmp1[3]);
  dst->m[0][1] = (float)((float)((float)(p_tmp1[1] * p_tmp2[5]) + (float)(*p_tmp1 * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[2]))
               + (float)(p_tmp2[13] * p_tmp1[3]);
  dst->m[0][2] = (float)((float)((float)(p_tmp1[1] * p_tmp2[6]) + (float)(*p_tmp1 * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[2]))
               + (float)(p_tmp2[14] * p_tmp1[3]);
  dst->m[0][3] = (float)((float)((float)(p_tmp1[1] * p_tmp2[7]) + (float)(*p_tmp1 * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[2]))
               + (float)(p_tmp2[15] * p_tmp1[3]);
  dst->m[1][0] = (float)((float)((float)(p_tmp1[5] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[4]))
                       + (float)(p_tmp2[8] * p_tmp1[6]))
               + (float)(p_tmp2[12] * p_tmp1[7]);
  dst->m[1][1] = (float)((float)((float)(p_tmp1[5] * p_tmp2[5]) + (float)(p_tmp1[4] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[6]))
               + (float)(p_tmp2[13] * p_tmp1[7]);
  dst->m[1][2] = (float)((float)((float)(p_tmp1[5] * p_tmp2[6]) + (float)(p_tmp1[4] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[6]))
               + (float)(p_tmp2[14] * p_tmp1[7]);
  dst->m[1][3] = (float)((float)((float)(p_tmp1[5] * p_tmp2[7]) + (float)(p_tmp1[4] * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[6]))
               + (float)(p_tmp1[7] * p_tmp2[15]);
  dst->m[2][0] = (float)((float)((float)(p_tmp1[9] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[8]))
                       + (float)(p_tmp2[8] * p_tmp1[10]))
               + (float)(p_tmp2[12] * p_tmp1[11]);
  dst->m[2][1] = (float)((float)((float)(p_tmp1[9] * p_tmp2[5]) + (float)(p_tmp1[8] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[10]))
               + (float)(p_tmp2[13] * p_tmp1[11]);
  dst->m[2][2] = (float)((float)((float)(p_tmp1[9] * p_tmp2[6]) + (float)(p_tmp1[8] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[10]))
               + (float)(p_tmp2[14] * p_tmp1[11]);
  dst->m[2][3] = (float)((float)((float)(p_tmp1[8] * p_tmp2[3]) + (float)(p_tmp1[9] * p_tmp2[7]))
                       + (float)(p_tmp2[11] * p_tmp1[10]))
               + (float)(p_tmp1[11] * p_tmp2[15]);
  dst->m[3][0] = (float)((float)((float)(p_tmp1[13] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[12]))
                       + (float)(p_tmp2[8] * p_tmp1[14]))
               + (float)(p_tmp2[12] * p_tmp1[15]);
  dst->m[3][1] = (float)((float)((float)(p_tmp1[13] * p_tmp2[5]) + (float)(p_tmp1[12] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[14]))
               + (float)(p_tmp2[13] * p_tmp1[15]);
  dst->m[3][2] = (float)((float)((float)(p_tmp1[13] * p_tmp2[6]) + (float)(p_tmp1[12] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[14]))
               + (float)(p_tmp2[14] * p_tmp1[15]);
  dst->m[3][3] = (float)((float)((float)(p_tmp1[13] * p_tmp2[7]) + (float)(p_tmp1[12] * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[14]))
               + (float)(p_tmp1[15] * p_tmp2[15]);
}

//------------------------------------------------------------------------------
// Address: 0x0056FAC0
// Name: void MatrixBuildTranslation(class VMatrix __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildTranslation(VMatrix *dst, float x, float y, float z)
{
  *(_QWORD *)&dst->m[0][1] = 0;
  dst->m[1][0] = 0.0;
  dst->m[1][2] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[0][3] = x;
  dst->m[1][3] = y;
  dst->m[0][0] = 1.0;
  dst->m[1][1] = 1.0;
  dst->m[2][2] = 1.0;
  dst->m[3][3] = 1.0;
  dst->m[2][3] = z;
}

//------------------------------------------------------------------------------
// Address: 0x0056FB90
// Name: void MatrixBuildRotateZ(class VMatrix __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildRotateZ(VMatrix *dst, float angleDegrees)
{
  long double fSin; // [esp+0h] [ebp-4h]
  long double fSina; // [esp+0h] [ebp-4h]
  float fSinb; // [esp+0h] [ebp-4h]
  float radians; // [esp+10h] [ebp+Ch]

  radians = angleDegrees * 0.0174532925199433;
  __libm_sse2_sin(x: fSin);
  *(float *)&fSina = radians;
  __libm_sse2_cos(x: fSina);
  dst->m[0][0] = radians;
  LODWORD(dst->m[0][1]) = LODWORD(fSinb) ^ _mask__NegFloat_;
  dst->m[1][1] = radians;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = fSinb;
  *(_QWORD *)&dst->m[1][2] = 0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[2][2] = 1065353216;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x0056FC50
// Name: void MatrixBuildScale(class VMatrix __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildScale(VMatrix *dst, unsigned int x, unsigned int y, float z)
{
  *(_QWORD *)&dst->m[0][0] = x;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = 0.0;
  *(_QWORD *)&dst->m[1][1] = y;
  dst->m[1][3] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  dst->m[2][3] = 0.0;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[2][2] = z;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x0056FCD0
// Name: class VMatrix SetupMatrixAxisRot(class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
VMatrix *__cdecl SetupMatrixAxisRot(VMatrix *result, const Vector *vAxis, float fDegrees)
{
  float v3; // xmm7_4
  float z; // xmm5_4
  float y; // xmm0_4
  float v7; // xmm4_4
  long double ty; // [esp+0h] [ebp-8h]
  long double tya; // [esp+0h] [ebp-8h]
  float tyb; // [esp+0h] [ebp-8h]
  float sx; // [esp+4h] [ebp-4h]
  float sxa; // [esp+4h] [ebp-4h]
  float sy; // [esp+18h] [ebp+10h]

  sy = fDegrees * 0.0174532925199433;
  __libm_sse2_sin(x: ty);
  *((float *)&tya + 1) = sy;
  __libm_sse2_cos(x: tya);
  v3 = sx;
  z = vAxis->z;
  y = vAxis->y;
  tyb = y * (float)(1.0 - sy);
  sxa = vAxis->x * sx;
  v7 = vAxis->x * (float)(1.0 - sy);
  result->m[0][0] = (float)(vAxis->x * v7) + sy;
  result->m[1][1] = (float)(y * tyb) + sy;
  result->m[0][1] = (float)(y * v7) - (float)(z * v3);
  result->m[2][1] = (float)(z * tyb) + sxa;
  result->m[0][2] = (float)(z * v7) + (float)(y * v3);
  result->m[2][2] = (float)((float)(z * (float)(1.0 - sy)) * z) + sy;
  result->m[0][3] = 0.0;
  result->m[1][0] = (float)(y * v7) + (float)(z * v3);
  result->m[1][2] = (float)(z * tyb) - sxa;
  result->m[1][3] = 0.0;
  result->m[2][0] = (float)(z * v7) - (float)(y * v3);
  result->m[2][3] = 0.0;
  *(_QWORD *)&result->m[3][0] = 0;
  result->m[3][2] = 0.0;
  result->m[3][3] = 1.0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0056FE30
// Name: public: class VMatrix VMatrix::Transpose(void)const
// Source: json
//------------------------------------------------------------------------------
VMatrix *__thiscall VMatrix::Transpose(VMatrix *this, VMatrix *result)
{
  result->m[0][0] = this->m[0][0];
  result->m[0][1] = this->m[1][0];
  result->m[0][2] = this->m[2][0];
  result->m[0][3] = this->m[3][0];
  result->m[1][0] = this->m[0][1];
  result->m[1][1] = this->m[1][1];
  result->m[1][2] = this->m[2][1];
  result->m[1][3] = this->m[3][1];
  result->m[2][0] = this->m[0][2];
  result->m[2][1] = this->m[1][2];
  result->m[2][2] = this->m[2][2];
  result->m[2][3] = this->m[3][2];
  result->m[3][0] = this->m[0][3];
  result->m[3][1] = this->m[1][3];
  result->m[3][2] = this->m[2][3];
  result->m[3][3] = this->m[3][3];
  return result;
}

} // namespace vmap

// ============================================================
// Overlay from vrad_dll (Missing functions)
// ============================================================
namespace vrad_dll {

//------------------------------------------------------------------------------
// Address: 0x10078210
// Name: public: void VMatrix::SetupMatrixOrgAngles(class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VMatrix::SetupMatrixOrgAngles(VMatrix *this, const Vector *origin, const QAngle *vAngles)
{
  float v4; // xmm1_4
  float v5; // xmm1_4
  double z; // st7
  float v7; // [esp+8h] [ebp-18h]
  float cr; // [esp+Ch] [ebp-14h]
  float sr; // [esp+10h] [ebp-10h]
  float sy; // [esp+14h] [ebp-Ch]
  float cy; // [esp+18h] [ebp-8h]
  float cp; // [esp+1Ch] [ebp-4h]
  float vAnglesa; // [esp+2Ch] [ebp+Ch]

  v4 = vAngles->y * 0.017453292;
  cy = cos(v4);
  sy = sin(v4);
  v5 = vAngles->x * 0.017453292;
  cp = cos(v5);
  vAnglesa = sin(v5);
  v7 = vAngles->z * 0.017453292;
  cr = cos(v7);
  sr = sin(v7);
  this->m[0][0] = cp * cy;
  this->m[1][0] = cp * sy;
  LODWORD(this->m[2][0]) = LODWORD(vAnglesa) ^ _mask__NegFloat_;
  this->m[0][1] = (float)((float)(sr * vAnglesa) * cy) - (float)(cr * sy);
  this->m[1][1] = (float)((float)(sr * vAnglesa) * sy) + (float)(cr * cy);
  this->m[2][1] = sr * cp;
  this->m[1][2] = (float)((float)(cr * vAnglesa) * sy) - (float)(sr * cy);
  this->m[0][3] = 0.0;
  this->m[1][3] = 0.0;
  this->m[2][3] = 0.0;
  this->m[0][2] = (float)((float)(cr * vAnglesa) * cy) + (float)(sr * sy);
  this->m[2][2] = cr * cp;
  this->m[0][3] = origin->x;
  this->m[1][3] = origin->y;
  z = origin->z;
  this->m[3][0] = 0.0;
  this->m[2][3] = z;
  *(_QWORD *)&this->m[3][1] = 0;
  this->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x100783A0
// Name: void MatrixSetIdentity(class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixSetIdentity(VMatrix *dst)
{
  *(_QWORD *)&dst->m[0][0] = 1065353216;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = 0.0;
  *(_QWORD *)&dst->m[1][1] = 1065353216;
  dst->m[1][3] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[2][2] = 1065353216;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[3][3] = 1.0;
}

} // namespace vrad_dll

// ============================================================
// Overlay from vtex_dll (Missing functions)
// ============================================================
namespace vtex_dll {

//------------------------------------------------------------------------------
// Address: 0x10096350
// Name: public: class VMatrix __near & VMatrix::operator=(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
VMatrix *__thiscall VMatrix::operator=(VMatrix *this, const VMatrix *mOther)
{
  *this = *mOther;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100963C0
// Name: public: bool VMatrix::operator==(class VMatrix const __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall VMatrix::operator==(VMatrix *this, const VMatrix *src)
{
  unsigned int v3; // eax

  v3 = 64;
  while ( LODWORD(src->m[0][0]) == LODWORD(this->m[0][0]) )
  {
    v3 -= 4;
    this = (VMatrix *)((char *)this + 4);
    src = (const VMatrix *)((char *)src + 4);
    if ( v3 < 4 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10096430
// Name: void MatrixSetIdentity(class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixSetIdentity(VMatrix *dst)
{
  *(_QWORD *)&dst->m[0][0] = 1065353216;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = 0.0;
  *(_QWORD *)&dst->m[1][1] = 1065353216;
  dst->m[1][3] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[2][2] = 1065353216;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x100964A0
// Name: void MatrixMultiply(class VMatrix const __near &,class VMatrix const __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixMultiply(const VMatrix *src1, const VMatrix *src2, VMatrix *dst)
{
  float *p_tmp1; // edx
  VMatrix *v4; // edi
  float *p_tmp2; // eax
  VMatrix tmp2; // [esp+Ch] [ebp-80h] BYREF
  VMatrix tmp1; // [esp+4Ch] [ebp-40h] BYREF

  p_tmp1 = (float *)&tmp1;
  if ( src1 != dst )
    p_tmp1 = (float *)src1;
  v4 = src2;
  p_tmp2 = (float *)&tmp2;
  if ( src2 != dst )
    p_tmp2 = (float *)src2;
  if ( src1 == dst && src1 != &tmp1 )
  {
    tmp1 = *src1;
    v4 = src2;
  }
  if ( v4 == dst && v4 != &tmp2 )
    tmp2 = *v4;
  dst->m[0][0] = (float)((float)((float)(p_tmp1[1] * p_tmp2[4]) + (float)(*p_tmp2 * *p_tmp1))
                       + (float)(p_tmp2[8] * p_tmp1[2]))
               + (float)(p_tmp2[12] * p_tmp1[3]);
  dst->m[0][1] = (float)((float)((float)(p_tmp1[1] * p_tmp2[5]) + (float)(*p_tmp1 * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[2]))
               + (float)(p_tmp2[13] * p_tmp1[3]);
  dst->m[0][2] = (float)((float)((float)(p_tmp1[1] * p_tmp2[6]) + (float)(*p_tmp1 * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[2]))
               + (float)(p_tmp2[14] * p_tmp1[3]);
  dst->m[0][3] = (float)((float)((float)(p_tmp1[1] * p_tmp2[7]) + (float)(*p_tmp1 * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[2]))
               + (float)(p_tmp2[15] * p_tmp1[3]);
  dst->m[1][0] = (float)((float)((float)(p_tmp1[5] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[4]))
                       + (float)(p_tmp2[8] * p_tmp1[6]))
               + (float)(p_tmp2[12] * p_tmp1[7]);
  dst->m[1][1] = (float)((float)((float)(p_tmp1[5] * p_tmp2[5]) + (float)(p_tmp1[4] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[6]))
               + (float)(p_tmp2[13] * p_tmp1[7]);
  dst->m[1][2] = (float)((float)((float)(p_tmp1[5] * p_tmp2[6]) + (float)(p_tmp1[4] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[6]))
               + (float)(p_tmp2[14] * p_tmp1[7]);
  dst->m[1][3] = (float)((float)((float)(p_tmp1[5] * p_tmp2[7]) + (float)(p_tmp1[4] * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[6]))
               + (float)(p_tmp1[7] * p_tmp2[15]);
  dst->m[2][0] = (float)((float)((float)(p_tmp1[9] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[8]))
                       + (float)(p_tmp2[8] * p_tmp1[10]))
               + (float)(p_tmp2[12] * p_tmp1[11]);
  dst->m[2][1] = (float)((float)((float)(p_tmp1[9] * p_tmp2[5]) + (float)(p_tmp1[8] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[10]))
               + (float)(p_tmp2[13] * p_tmp1[11]);
  dst->m[2][2] = (float)((float)((float)(p_tmp1[9] * p_tmp2[6]) + (float)(p_tmp1[8] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[10]))
               + (float)(p_tmp2[14] * p_tmp1[11]);
  dst->m[2][3] = (float)((float)((float)(p_tmp1[8] * p_tmp2[3]) + (float)(p_tmp1[9] * p_tmp2[7]))
                       + (float)(p_tmp2[11] * p_tmp1[10]))
               + (float)(p_tmp1[11] * p_tmp2[15]);
  dst->m[3][0] = (float)((float)((float)(p_tmp1[13] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[12]))
                       + (float)(p_tmp2[8] * p_tmp1[14]))
               + (float)(p_tmp2[12] * p_tmp1[15]);
  dst->m[3][1] = (float)((float)((float)(p_tmp1[13] * p_tmp2[5]) + (float)(p_tmp1[12] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[14]))
               + (float)(p_tmp2[13] * p_tmp1[15]);
  dst->m[3][2] = (float)((float)((float)(p_tmp1[13] * p_tmp2[6]) + (float)(p_tmp1[12] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[14]))
               + (float)(p_tmp2[14] * p_tmp1[15]);
  dst->m[3][3] = (float)((float)((float)(p_tmp1[13] * p_tmp2[7]) + (float)(p_tmp1[12] * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[14]))
               + (float)(p_tmp1[15] * p_tmp2[15]);
}

//------------------------------------------------------------------------------
// Address: 0x10096890
// Name: void MatrixBuildTranslation(class VMatrix __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildTranslation(VMatrix *dst, float x, float y, float z)
{
  *(_QWORD *)&dst->m[0][1] = 0;
  dst->m[1][0] = 0.0;
  dst->m[1][2] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[0][3] = x;
  dst->m[1][3] = y;
  dst->m[0][0] = 1.0;
  dst->m[1][1] = 1.0;
  dst->m[2][2] = 1.0;
  dst->m[3][3] = 1.0;
  dst->m[2][3] = z;
}

//------------------------------------------------------------------------------
// Address: 0x10096910
// Name: void MatrixBuildRotateZ(class VMatrix __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildRotateZ(VMatrix *dst, float angleDegrees)
{
  long double fSin; // [esp+0h] [ebp-4h]
  long double fSina; // [esp+0h] [ebp-4h]
  float fSinb; // [esp+0h] [ebp-4h]
  float radians; // [esp+10h] [ebp+Ch]

  radians = angleDegrees * 0.0174532925199433;
  __libm_sse2_sin(x: fSin);
  *(float *)&fSina = radians;
  __libm_sse2_cos(x: fSina);
  dst->m[0][0] = radians;
  LODWORD(dst->m[0][1]) = LODWORD(fSinb) ^ _mask__NegFloat_;
  dst->m[1][1] = radians;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = fSinb;
  *(_QWORD *)&dst->m[1][2] = 0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[2][2] = 1065353216;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x100969D0
// Name: void MatrixBuildScale(class VMatrix __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildScale(VMatrix *dst, unsigned int x, unsigned int y, float z)
{
  *(_QWORD *)&dst->m[0][0] = x;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = 0.0;
  *(_QWORD *)&dst->m[1][1] = y;
  dst->m[1][3] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  dst->m[2][3] = 0.0;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[2][2] = z;
  dst->m[3][3] = 1.0;
}

} // namespace vtex_dll

// ============================================================
// Overlay from worldrenderertest (Missing functions)
// ============================================================
namespace worldrenderertest {

//------------------------------------------------------------------------------
// Address: 0x0040DC30
// Name: _cosf
// Source: json
//------------------------------------------------------------------------------
long double __cdecl cosf(float _X)
{
  return cos(_X);
}

//------------------------------------------------------------------------------
// Address: 0x0040DC40
// Name: void SinCos(float,float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SinCos(float radians, float *sine, float *cosine)
{
  *cosine = cos(radians);
  *sine = sin(radians);
}

//------------------------------------------------------------------------------
// Address: 0x0040DC60
// Name: public: class VMatrix __near & VMatrix::operator=(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
VMatrix *__thiscall VMatrix::operator=(VMatrix *this, const VMatrix *mOther)
{
  *this = *mOther;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0040DCD0
// Name: public: void VMatrix::MatrixMul(class VMatrix const __near &,class VMatrix __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall VMatrix::MatrixMul(VMatrix *this, const VMatrix *vm, VMatrix *out)
{
  double v4; // st7
  double v5; // st6
  double v6; // st5
  double v7; // st4
  double v8; // st3
  double v9; // st2
  float v10; // [esp+0h] [ebp-20h]
  float v11; // [esp+4h] [ebp-1Ch]
  float v12; // [esp+8h] [ebp-18h]
  float v13; // [esp+Ch] [ebp-14h]
  float v14; // [esp+10h] [ebp-10h]
  float v15; // [esp+14h] [ebp-Ch]
  float v16; // [esp+18h] [ebp-8h]
  float v17; // [esp+1Ch] [ebp-4h]
  float vma; // [esp+24h] [ebp+4h]

  v4 = vm->m[2][1] * this->m[0][2]
     + vm->m[1][1] * this->m[0][1]
     + this->m[0][3] * vm->m[3][1]
     + vm->m[0][1] * this->m[0][0];
  v5 = vm->m[1][2] * this->m[0][1]
     + vm->m[2][2] * this->m[0][2]
     + this->m[0][0] * vm->m[0][2]
     + vm->m[3][2] * this->m[0][3];
  v6 = vm->m[3][3] * this->m[0][3]
     + vm->m[1][3] * this->m[0][1]
     + vm->m[2][3] * this->m[0][2]
     + vm->m[0][3] * this->m[0][0];
  v7 = vm->m[2][0] * this->m[1][2]
     + vm->m[1][0] * this->m[1][1]
     + this->m[1][0] * vm->m[0][0]
     + this->m[1][3] * vm->m[3][0];
  v8 = vm->m[2][1] * this->m[1][2]
     + vm->m[1][1] * this->m[1][1]
     + this->m[1][3] * vm->m[3][1]
     + vm->m[0][1] * this->m[1][0];
  v9 = vm->m[1][2] * this->m[1][1]
     + this->m[1][0] * vm->m[0][2]
     + vm->m[2][2] * this->m[1][2]
     + vm->m[3][2] * this->m[1][3];
  vma = vm->m[3][3] * this->m[1][3]
      + vm->m[1][3] * this->m[1][1]
      + vm->m[2][3] * this->m[1][2]
      + vm->m[0][3] * this->m[1][0];
  v10 = vm->m[0][0] * this->m[2][0]
      + vm->m[1][0] * this->m[2][1]
      + this->m[2][3] * vm->m[3][0]
      + vm->m[2][0] * this->m[2][2];
  v11 = vm->m[1][1] * this->m[2][1]
      + this->m[2][3] * vm->m[3][1]
      + vm->m[2][1] * this->m[2][2]
      + vm->m[0][1] * this->m[2][0];
  v12 = vm->m[1][2] * this->m[2][1]
      + this->m[2][3] * vm->m[3][2]
      + this->m[2][2] * vm->m[2][2]
      + this->m[2][0] * vm->m[0][2];
  v13 = vm->m[1][3] * this->m[2][1]
      + this->m[2][3] * vm->m[3][3]
      + this->m[2][2] * vm->m[2][3]
      + vm->m[0][3] * this->m[2][0];
  v14 = vm->m[0][0] * this->m[3][0]
      + this->m[3][3] * vm->m[3][0]
      + vm->m[1][0] * this->m[3][1]
      + vm->m[2][0] * this->m[3][2];
  v15 = this->m[3][3] * vm->m[3][1]
      + vm->m[1][1] * this->m[3][1]
      + vm->m[0][1] * this->m[3][0]
      + vm->m[2][1] * this->m[3][2];
  v16 = vm->m[1][2] * this->m[3][1]
      + this->m[3][3] * vm->m[3][2]
      + this->m[3][2] * vm->m[2][2]
      + this->m[3][0] * vm->m[0][2];
  v17 = vm->m[1][3] * this->m[3][1]
      + this->m[3][3] * vm->m[3][3]
      + this->m[3][2] * vm->m[2][3]
      + vm->m[0][3] * this->m[3][0];
  out->m[0][0] = vm->m[2][0] * this->m[0][2]
               + vm->m[1][0] * this->m[0][1]
               + vm->m[0][0] * this->m[0][0]
               + this->m[0][3] * vm->m[3][0];
  out->m[0][1] = v4;
  out->m[0][2] = v5;
  out->m[0][3] = v6;
  out->m[1][0] = v7;
  out->m[1][1] = v8;
  out->m[1][2] = v9;
  out->m[1][3] = vma;
  out->m[2][0] = v10;
  out->m[2][1] = v11;
  out->m[2][2] = v12;
  out->m[2][3] = v13;
  out->m[3][0] = v14;
  out->m[3][1] = v15;
  out->m[3][2] = v16;
  out->m[3][3] = v17;
}

//------------------------------------------------------------------------------
// Address: 0x0040DF40
// Name: public: class VMatrix VMatrix::operator*(class VMatrix const __near &)const
// Source: json
//------------------------------------------------------------------------------
VMatrix *__thiscall VMatrix::operator*(VMatrix *this, VMatrix *result, const VMatrix *vm)
{
  int v3; // edx

  VMatrix::MatrixMul(this, vm, out: result);
  return (VMatrix *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x0040DF60
// Name: void MatrixSetIdentity(class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixSetIdentity(VMatrix *dst)
{
  dst->m[0][0] = 1.0;
  dst->m[0][1] = 0.0;
  dst->m[0][2] = 0.0;
  dst->m[0][3] = 0.0;
  dst->m[1][0] = 0.0;
  dst->m[1][2] = 0.0;
  dst->m[1][3] = 0.0;
  dst->m[2][0] = 0.0;
  dst->m[2][1] = 0.0;
  dst->m[2][3] = 0.0;
  dst->m[3][0] = 0.0;
  dst->m[3][1] = 0.0;
  dst->m[3][2] = 0.0;
  dst->m[1][1] = 1.0;
  dst->m[2][2] = 1.0;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x0040DFA0
// Name: public: class VMatrix VMatrix::Transpose(void)const
// Source: json
//------------------------------------------------------------------------------
VMatrix *__thiscall VMatrix::Transpose(VMatrix *this, VMatrix *result)
{
  result->m[0][0] = this->m[0][0];
  result->m[0][1] = this->m[1][0];
  result->m[0][2] = this->m[2][0];
  result->m[0][3] = this->m[3][0];
  result->m[1][0] = this->m[0][1];
  result->m[1][1] = this->m[1][1];
  result->m[1][2] = this->m[2][1];
  result->m[1][3] = this->m[3][1];
  result->m[2][0] = this->m[0][2];
  result->m[2][1] = this->m[1][2];
  result->m[2][2] = this->m[2][2];
  result->m[2][3] = this->m[3][2];
  result->m[3][0] = this->m[0][3];
  result->m[3][1] = this->m[1][3];
  result->m[3][2] = this->m[2][3];
  result->m[3][3] = this->m[3][3];
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00423CB8
// Name: public: class DName __near & DName::operator=(class DName const __near &)
// Source: json
//------------------------------------------------------------------------------
DName *__thiscall DName::operator=(DName *this, const DName *rd)
{
  DName *result; // eax
  int v3; // esi
  int v4; // ecx
  int v5; // edx
  int v6; // esi
  int v7; // edx
  int v8; // esi
  int v9; // edx

  result = this;
  v3 = *((_DWORD *)this + 1);
  v4 = v3 << 28 >> 28;
  if ( v4 == 0 || v4 == 2 )
  {
    v5 = v3 ^ ((unsigned __int8)v3 ^ (unsigned __int8)((int)(*((_DWORD *)rd + 1) << 28) >> 28)) & 0xF;
    *((_DWORD *)result + 1) = v5;
    v6 = v5 ^ ((unsigned __int8)v5 ^ (unsigned __int8)*((_DWORD *)rd + 1)) & 0x10;
    *((_DWORD *)result + 1) = v6;
    v7 = v6 ^ ((unsigned __int8)v6 ^ (unsigned __int8)*((_DWORD *)rd + 1)) & 0x20;
    *((_DWORD *)result + 1) = v7;
    v8 = v7 ^ ((unsigned __int8)v7 ^ (unsigned __int8)*((_DWORD *)rd + 1)) & 0x40;
    *((_DWORD *)result + 1) = v8;
    v9 = v8 ^ ((unsigned __int8)v8 ^ (unsigned __int8)*((_DWORD *)rd + 1)) & 0x80;
    *((_DWORD *)result + 1) = v9;
    *((_DWORD *)result + 1) = v9 ^ ((unsigned __int16)v9 ^ (unsigned __int16)*((_DWORD *)rd + 1)) & 0x800;
    result->node = rd->node;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004240AA
// Name: public: class DName __near & DName::operator=(enum DNameStatus)
// Source: json
//------------------------------------------------------------------------------
DName *__thiscall DName::operator=(DName *this, DNameStatus st)
{
  int v3; // eax
  int v4; // ecx
  char *Memory; // eax
  DNameStatusNode *v6; // eax
  int v7; // eax

  if ( st == DN_invalid || st == DN_error )
  {
    v7 = *((_DWORD *)this + 1);
    this->node = nullptr;
    if ( (v7 & 0xF) != 3 )
      *((_DWORD *)this + 1) = v7 ^ ((unsigned __int8)st ^ (unsigned __int8)v7) & 0xF;
  }
  else
  {
    v3 = *((_DWORD *)this + 1);
    v4 = v3 << 28 >> 28;
    if ( v4 == 0 || v4 == 2 )
    {
      *((_DWORD *)this + 1) = v3 & 0xFFFFF70F;
      Memory = HeapManager::getMemory(this: &heap, sz: 0x10u, noBuffer: 0);
      if ( Memory != nullptr )
        v6 = DNameStatusNode::DNameStatusNode(this: (DNameStatusNode *)Memory, stat: st);
      else
        v6 = nullptr;
      this->node = v6;
      if ( v6 == nullptr )
        *((_DWORD *)this + 1) = *((_DWORD *)this + 1) & 0xFFFFFFF0 | 3;
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00424764
// Name: public: class DName __near & DName::operator=(char)
// Source: json
//------------------------------------------------------------------------------
DName *__thiscall DName::operator=(DName *this, char ch)
{
  *((_DWORD *)this + 1) &= 0xFFFFF70F;
  DName::doPchar(this, str: &ch, len: 1);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00424780
// Name: public: class DName __near & DName::operator=(char const __near *)
// Source: json
//------------------------------------------------------------------------------
DName *__thiscall DName::operator=(DName *this, const char *str)
{
  int v3; // ecx

  *((_DWORD *)this + 1) &= 0xFFFFF70F;
  v3 = 0;
  if ( *str != 0 )
  {
    do
      ++v3;
    while ( str[v3] != 0 );
  }
  DName::doPchar(this, str, len: v3);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0042412B
// Name: public: Replicator::Replicator(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
Replicator *__thiscall Replicator::Replicator(Replicator *this)
{
  DName::DName(this: (DName *)&this->ErrorDName, st: DN_error);
  DName::DName(this: (DName *)&this->InvalidDName, st: DN_invalid);
  this->index = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00424149
// Name: public: class Replicator __near & Replicator::operator+=(class DName const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
Replicator *__thiscall Replicator::operator+=(Replicator *this, DName *rd)
{
  char *Memory; // eax
  DName *v4; // eax

  if ( this->index != 9 && !DName::isEmpty(this: rd) )
  {
    Memory = HeapManager::getMemory(this: &heap, sz: 8u, noBuffer: 0);
    if ( Memory != nullptr )
      v4 = DName::DName(this: (DName *)Memory, rd);
    else
      v4 = nullptr;
    if ( v4 != nullptr )
      this->dNameBuffer[++this->index] = v4;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00424190
// Name: public: class DNameNode __near * DNameNode::clone(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
pDNameNode *__thiscall DNameNode::clone(DNameNode *this)
{
  char *Memory; // ebx
  char *v3; // eax

  Memory = HeapManager::getMemory(this: &heap, sz: 0xCu, noBuffer: 0);
  if ( Memory == nullptr )
    return nullptr;
  v3 = HeapManager::getMemory(this: &heap, sz: 8u, noBuffer: 0);
  if ( v3 != nullptr )
  {
    *((_DWORD *)v3 + 1) &= 0xFFFFF000;
    *(_DWORD *)v3 = this;
  }
  else
  {
    v3 = nullptr;
  }
  return pDNameNode::pDNameNode(this: (pDNameNode *)Memory, pName: (DName *)v3);
}

//------------------------------------------------------------------------------
// Address: 0x004241D7
// Name: public: pcharNode::pcharNode(char const __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
pcharNode *__thiscall pcharNode::pcharNode(pcharNode *this, char *str, int len)
{
  int v3; // edi
  char *Memory; // eax

  v3 = len;
  this->next = nullptr;
  this->__vftable = (pcharNode_vtbl *)&pcharNode::`vftable';
  if ( len == 0 )
  {
    if ( str == nullptr )
      goto LABEL_9;
    v3 = 0;
    if ( *str != 0 )
    {
      do
        ++v3;
      while ( str[v3] != 0 );
    }
    if ( v3 == 0 )
      goto LABEL_9;
  }
  if ( str != nullptr )
  {
    Memory = HeapManager::getMemory(this: &heap, sz: v3, noBuffer: 0);
    this->me = Memory;
    this->myLen = v3;
    if ( Memory != nullptr )
      und_strncpy(src: str, dst: Memory, len: v3);
  }
  else
  {
LABEL_9:
    this->me = nullptr;
    this->myLen = 0;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0042423C
// Name: public: virtual char pcharNode::getLastChar(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __thiscall pcharNode::getLastChar(pcharNode *this)
{
  int myLen; // eax

  myLen = this->myLen;
  if ( myLen != 0 )
    return this->me[myLen - 1];
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0042424E
// Name: public: virtual char __near * pcharNode::getString(char __near *,int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__thiscall pcharNode::getString(pcharNode *this, char *buf, int len)
{
  unsigned int myLen; // edx
  char *me; // ecx
  char *result; // eax

  myLen = len;
  if ( len > this->myLen )
    myLen = this->myLen;
  me = this->me;
  result = nullptr;
  if ( me != nullptr && buf != nullptr && myLen != 0 )
    return und_strncpy(src: me, dst: buf, len: myLen);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042427F
// Name: public: virtual int pDNameNode::length(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall pDNameNode::length(pDNameNode *this)
{
  DName *me; // ecx

  me = this->me;
  if ( me != nullptr )
    return DName::length(this: me);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0042428E
// Name: public: virtual char pDNameNode::getLastChar(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __thiscall pDNameNode::getLastChar(pDNameNode *this)
{
  DName *me; // ecx

  me = this->me;
  if ( me != nullptr )
    return DName::getLastChar(this: me);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0042429D
// Name: public: virtual char __near * pDNameNode::getString(char __near *,int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__thiscall pDNameNode::getString(pDNameNode *this, char *buf, char *len)
{
  DName *me; // ecx
  char *result; // eax

  me = this->me;
  result = nullptr;
  if ( me != nullptr && buf != nullptr && len != nullptr )
    return DName::getString(this: me, buf, max: len);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004242BA
// Name: public: virtual char __near * DNameStatusNode::getString(char __near *,int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__thiscall DNameStatusNode::getString(DNameStatusNode *this, char *buf, int len)
{
  unsigned int myLen; // edx
  char *result; // eax

  myLen = len;
  if ( len > this->myLen )
    myLen = this->myLen;
  result = nullptr;
  if ( this->me == DN_truncated && buf != nullptr && myLen != 0 )
    return und_strncpy(src: " ?? ", dst: buf, len: myLen);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004242ED
// Name: public: UnDecorator::UnDecorator(char __near *,char const __near *,int,char __near * (*)(long),unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
UnDecorator *__thiscall UnDecorator::UnDecorator(
        UnDecorator *this,
        char *output,
        const char *dName,
        int maxLen,
        char *(__cdecl *pGetParameter)(int),
        unsigned int disable)
{
  Replicator::Replicator(this: &this->ArgList);
  Replicator::Replicator(this: &this->ZNameList);
  UnDecorator::name = dName;
  UnDecorator::gName = dName;
  if ( output != nullptr )
  {
    UnDecorator::maxStringLength = maxLen - 1;
    UnDecorator::outputString = output;
  }
  else
  {
    UnDecorator::outputString = nullptr;
    UnDecorator::maxStringLength = 0;
  }
  UnDecorator::disableFlags = disable;
  UnDecorator::pZNameList = &this->ZNameList;
  UnDecorator::m_pGetParameter = pGetParameter;
  UnDecorator::pArgList = &this->ArgList;
  UnDecorator::fExplicitTemplateParams = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00424360
// Name: private: static class DName UnDecorator::getReturnType(class DName __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__cdecl UnDecorator::getReturnType(DName *result, DName *pDeclarator)
{
  if ( *UnDecorator::gName == 64 )
  {
    ++UnDecorator::gName;
    DName::DName(this: result, pd: pDeclarator);
  }
  else
  {
    UnDecorator::getDataType(result, pDeclarator);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042438F
// Name: public: class DName __near & DName::operator+=(enum DNameStatus)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__thiscall DName::operator+=(DName *this, DNameStatus st)
{
  DName *v3; // ecx
  char *Memory; // eax
  DNameStatusNode *v5; // edi
  pDNameNode *v6; // eax

  if ( DName::isEmpty(this) || st == DN_invalid || st == DN_error )
  {
    DName::operator=(this: v3, st);
    return this;
  }
  Memory = HeapManager::getMemory(this: &heap, sz: 0x10u, noBuffer: 0);
  if ( Memory != nullptr )
    v5 = DNameStatusNode::DNameStatusNode(this: (DNameStatusNode *)Memory, stat: st);
  else
    v5 = nullptr;
  if ( v5 != nullptr )
  {
    v6 = DNameNode::clone(this: this->node);
    this->node = v6;
    if ( v6 == nullptr )
    {
LABEL_12:
      *((_DWORD *)this + 1) = *((_DWORD *)this + 1) & 0xFFFFFFF0 | 3;
      return this;
    }
    DNameNode::operator+=(this: v6, pNode: v5);
  }
  else
  {
    this->node = nullptr;
  }
  if ( this->node == nullptr )
    goto LABEL_12;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00424408
// Name: private: void DName::doPchar(char const __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall DName::doPchar(DName *this, char *str, int len)
{
  int v4; // eax
  int v5; // ecx
  char *v6; // eax
  DNameNode *Memory; // eax
  unsigned int v8; // eax
  char v9; // cl

  v4 = *((_DWORD *)this + 1);
  v5 = v4 << 28 >> 28;
  if ( v5 != 1 && v5 != 3 )
  {
    if ( this->node != nullptr )
    {
      DName::operator=(this, st: DN_error);
      return;
    }
    if ( str == nullptr || len == 0 )
    {
      v8 = v4 & 0xFFFFFFF0 | 1;
      goto LABEL_16;
    }
    if ( len == 1 )
    {
      Memory = (DNameNode *)HeapManager::getMemory(this: &heap, sz: 0xCu, noBuffer: 0);
      if ( Memory != nullptr )
      {
        v9 = *str;
        Memory->next = nullptr;
        Memory->__vftable = (DNameNode_vtbl *)&charNode::`vftable';
        LOBYTE(Memory[1].__vftable) = v9;
      }
      else
      {
        Memory = nullptr;
      }
    }
    else
    {
      v6 = HeapManager::getMemory(this: &heap, sz: 0x10u, noBuffer: 0);
      if ( v6 != nullptr )
        Memory = pcharNode::pcharNode(this: (pcharNode *)v6, str, len);
      else
        Memory = nullptr;
    }
    this->node = Memory;
    if ( Memory == nullptr )
    {
      v8 = *((_DWORD *)this + 1) & 0xFFFFFFF0 | 3;
LABEL_16:
      *((_DWORD *)this + 1) = v8;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004244AE
// Name: public: DName::DName(char)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__thiscall DName::DName(DName *this, char c)
{
  this->node = nullptr;
  *((_DWORD *)this + 1) &= 0xFFFFF000;
  if ( c != 0 )
    DName::doPchar(this, str: &c, len: 1);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004244D4
// Name: public: DName::DName(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__thiscall DName::DName(DName *this, char *s)
{
  int v3; // ecx

  *((_DWORD *)this + 1) &= 0xFFFFF000;
  this->node = nullptr;
  if ( s != nullptr )
  {
    v3 = 0;
    if ( *s != 0 )
    {
      do
        ++v3;
      while ( s[v3] != 0 );
    }
    DName::doPchar(this, str: s, len: v3);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00424505
// Name: public: DName::DName(char const __near * __near &,char)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__thiscall DName::DName(DName *this, char **name, char terminator)
{
  int v4; // eax
  int v5; // ebx
  char *v6; // ecx
  char *v7; // edx
  char v8; // al
  char v9; // cl
  unsigned int v10; // eax

  *((_DWORD *)this + 1) &= 0xFFFFF000;
  v4 = *((_DWORD *)this + 1);
  v5 = 0;
  this->node = nullptr;
  v6 = *name;
  if ( *name == nullptr )
  {
LABEL_22:
    v10 = v4 & 0xFFFFFFF0 | 1;
LABEL_23:
    *((_DWORD *)this + 1) = v10;
    return this;
  }
  if ( *v6 == 0 )
  {
LABEL_27:
    v10 = v4 & 0xFFFFFFF0 | 2;
    goto LABEL_23;
  }
  do
  {
    v7 = *name;
    v8 = **name;
    if ( v8 == terminator )
      break;
    if ( v8 != 95
      && v8 != 36
      && v8 != 60
      && v8 != 62
      && v8 != 45
      && (v8 < 97 || v8 > 122)
      && (v8 < 65 || v8 > 90)
      && (v8 < 48 || v8 > 57)
      && v8 >= -1
      && (UnDecorator::disableFlags & 0x10000) == 0 )
    {
      v4 = *((_DWORD *)this + 1);
      goto LABEL_22;
    }
    ++v5;
    *name = v7 + 1;
  }
  while ( v7[1] != 0 );
  DName::doPchar(this, str: v6, len: v5);
  v9 = **name;
  if ( v9 == 0 )
  {
    v4 = *((_DWORD *)this + 1);
    if ( (v4 & 0xF) != 0 )
      return this;
    goto LABEL_27;
  }
  ++*name;
  if ( v9 != terminator )
  {
    v10 = *((_DWORD *)this + 1) & 0xFFFFFFF0 | 3;
    this->node = nullptr;
    goto LABEL_23;
  }
  *((_DWORD *)this + 1) &= 0xFFFFFFF0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004245D5
// Name: public: DName::DName(unsigned __int64)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__thiscall DName::DName(DName *this, unsigned __int64 num)
{
  char *v3; // esi
  unsigned __int64 v4; // rcx
  char buf[24]; // [esp+14h] [ebp-1Ch] BYREF

  this->node = nullptr;
  *((_DWORD *)this + 1) &= 0xFFFFF000;
  v3 = &buf[20];
  buf[20] = 0;
  do
  {
    --v3;
    v4 = num % 0xA;
    num /= 0xAu;
    *v3 = v4 + 48;
  }
  while ( num != 0 );
  DName::doPchar(this, str: v3, len: &buf[20] - v3);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0042463E
// Name: public: DName::DName(__int64)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__thiscall DName::DName(DName *this, __int64 num)
{
  unsigned int v2; // eax
  char *v4; // edi
  unsigned __int64 v5; // rax
  unsigned __int64 v6; // rcx
  bool fSigned; // [esp+13h] [ebp-1Dh]
  char buf[24]; // [esp+14h] [ebp-1Ch] BYREF

  v2 = HIDWORD(num);
  *((_DWORD *)this + 1) &= 0xFFFFF000;
  v4 = &buf[21];
  this->node = nullptr;
  buf[21] = 0;
  fSigned = false;
  if ( num < 0 )
  {
    fSigned = true;
    v2 = (unsigned __int64)-num >> 32;
    LODWORD(num) = -(int)num;
  }
  do
  {
    --v4;
    v6 = __PAIR64__(v2, num) % 0xA;
    v5 = __PAIR64__(v2, num) / 0xA;
    LODWORD(num) = v5;
    *v4 = v6 + 48;
    v2 = HIDWORD(v5);
  }
  while ( __PAIR64__(HIDWORD(v5), num) != 0 );
  if ( fSigned )
    *--v4 = 45;
  DName::doPchar(this, str: v4, len: &buf[21] - v4);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004246D4
// Name: public: class DName DName::operator+(enum DNameStatus)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__thiscall DName::operator+(DName *this, DName *result, DNameStatus st)
{
  DName *v3; // ecx

  DName::DName(this: result, rd: this);
  if ( DName::isEmpty(this: result) )
    DName::operator=(this: v3, st);
  else
    DName::operator+=(this: v3, st);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00424702
// Name: public: class DName __near & DName::operator+=(class DName const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__thiscall DName::operator+=(DName *this, DName *rd)
{
  DName *v3; // ecx
  pDNameNode *v4; // eax

  if ( DName::isEmpty(this: rd) )
  {
    DName::operator+=(this, st: (DNameStatus)((int)(*((_DWORD *)rd + 1) << 28) >> 28));
  }
  else if ( DName::isEmpty(this) )
  {
    DName::operator=(this: v3, rd);
  }
  else
  {
    v4 = DNameNode::clone(this: this->node);
    this->node = v4;
    if ( v4 != nullptr )
      DNameNode::operator+=(this: v4, pNode: rd->node);
    else
      *((_DWORD *)this + 1) = *((_DWORD *)this + 1) & 0xFFFFFFF0 | 3;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004247AA
// Name: private: static class DName UnDecorator::getCallingConvention(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__cdecl UnDecorator::getCallingConvention(DName *result)
{
  unsigned int v1; // eax
  unsigned int v2; // eax
  unsigned int v3; // eax
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // eax
  const char *v7; // eax
  DName callType; // [esp+0h] [ebp-8h] BYREF

  if ( *UnDecorator::gName == 0 )
  {
    DName::DName(this: result, st: DN_truncated);
    return result;
  }
  v1 = *UnDecorator::gName++ - 65;
  if ( v1 > 0xC )
  {
    DName::DName(this: result, st: DN_invalid);
    return result;
  }
  callType.node = nullptr;
  *((_DWORD *)&callType + 1) &= 0xFFFFF000;
  if ( (~(UnDecorator::disableFlags >> 1) & 1) != 0 )
  {
    v2 = v1 & 0xFFFFFFFE;
    if ( v2 == 0 )
    {
      v7 = UnDecorator::UScore(tok: TOK_cdecl);
      goto LABEL_16;
    }
    v3 = v2 - 2;
    if ( v3 == 0 )
    {
      v7 = UnDecorator::UScore(tok: TOK_pascal);
      goto LABEL_16;
    }
    v4 = v3 - 2;
    if ( v4 == 0 )
    {
      v7 = UnDecorator::UScore(tok: TOK_thiscall);
      goto LABEL_16;
    }
    v5 = v4 - 2;
    if ( v5 == 0 )
    {
      v7 = UnDecorator::UScore(tok: TOK_stdcall);
      goto LABEL_16;
    }
    v6 = v5 - 2;
    if ( v6 == 0 )
    {
      v7 = UnDecorator::UScore(tok: TOK_fastcall);
      goto LABEL_16;
    }
    if ( v6 == 4 )
    {
      v7 = UnDecorator::UScore(tok: TOK_cocall);
LABEL_16:
      DName::operator=(this: &callType, str: v7);
    }
  }
  DName::DName(this: result, rd: &callType);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00424850
// Name: private: static class DName UnDecorator::getVCallThunkType(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__cdecl UnDecorator::getVCallThunkType(DName *result)
{
  if ( *UnDecorator::gName != 0 )
  {
    if ( *UnDecorator::gName == 65 )
    {
      ++UnDecorator::gName;
      DName::DName(this: result, s: "{flat}");
    }
    else
    {
      DName::DName(this: result, st: DN_invalid);
    }
  }
  else
  {
    DName::DName(this: result, st: DN_truncated);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00424887
// Name: public: class DName DName::operator+(class DName const __near &)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__thiscall DName::operator+(DName *this, DName *result, DName *rd)
{
  DName *v3; // ecx
  int v4; // ecx

  DName::DName(this: result, rd: this);
  if ( DName::isEmpty(this: result) )
  {
    DName::operator=(this: v3, rd);
  }
  else if ( DName::isEmpty(this: rd) )
  {
    DName::operator+=(this: result, st: (DNameStatus)((int)(*(_DWORD *)(v4 + 4) << 28) >> 28));
  }
  else
  {
    DName::operator+=(this: result, rd: (DName *)v4);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004248D8
// Name: public: class DName __near & DName::operator+=(char)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__thiscall DName::operator+=(DName *this, char ch)
{
  DName *v3; // ecx
  pDNameNode *v4; // eax
  char *Memory; // eax

  if ( ch != 0 )
  {
    if ( DName::isEmpty(this) )
    {
      DName::operator=(this: v3, ch);
    }
    else
    {
      v4 = DNameNode::clone(this: this->node);
      this->node = v4;
      if ( v4 != nullptr )
      {
        Memory = HeapManager::getMemory(this: &heap, sz: 0xCu, noBuffer: 0);
        if ( Memory != nullptr )
        {
          *((_DWORD *)Memory + 1) = 0;
          *(_DWORD *)Memory = &charNode::`vftable';
          Memory[8] = ch;
        }
        else
        {
          Memory = nullptr;
        }
        DNameNode::operator+=(this: this->node, pNode: (DNameNode *)Memory);
      }
      else
      {
        *((_DWORD *)this + 1) = *((_DWORD *)this + 1) & 0xFFFFFFF0 | 3;
      }
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00424942
// Name: public: class DName __near & DName::operator+=(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__thiscall DName::operator+=(DName *this, char *str)
{
  DName *v3; // ecx
  pDNameNode *v4; // eax
  char *Memory; // eax
  pcharNode *v6; // eax

  if ( str != nullptr && *str != 0 )
  {
    if ( DName::isEmpty(this) )
    {
      DName::operator=(this: v3, str);
    }
    else
    {
      v4 = DNameNode::clone(this: this->node);
      this->node = v4;
      if ( v4 != nullptr )
      {
        Memory = HeapManager::getMemory(this: &heap, sz: 0x10u, noBuffer: 0);
        if ( Memory != nullptr )
          v6 = pcharNode::pcharNode(this: (pcharNode *)Memory, str, len: 0);
        else
          v6 = nullptr;
        DNameNode::operator+=(this: this->node, pNode: v6);
      }
      else
      {
        *((_DWORD *)this + 1) = *((_DWORD *)this + 1) & 0xFFFFFFF0 | 3;
      }
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004249AE
// Name: private: static class DName UnDecorator::getArgumentList(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__cdecl UnDecorator::getArgumentList(DName *result)
{
  int v1; // eax
  const char *v2; // eax
  unsigned int v3; // ecx
  DName *p_arg; // eax
  const char *v5; // ebx
  DName arg; // [esp+8h] [ebp-14h] BYREF
  DName superType; // [esp+10h] [ebp-Ch] BYREF
  int first; // [esp+18h] [ebp-4h]

  result->node = nullptr;
  *((_DWORD *)result + 1) &= 0xFFFFF000;
  v1 = *((_DWORD *)result + 1);
  first = 1;
  if ( (v1 & 0xF) == 0 )
  {
    do
    {
      v2 = UnDecorator::gName;
      if ( *UnDecorator::gName == 64 || *UnDecorator::gName == 90 )
        break;
      if ( first != 0 )
      {
        first = 0;
      }
      else
      {
        DName::operator+=(this: result, ch: 44);
        v2 = UnDecorator::gName;
      }
      if ( *v2 == 0 )
      {
        DName::operator+=(this: result, st: DN_truncated);
        return result;
      }
      v3 = *v2 - 48;
      if ( v3 > 9 )
      {
        superType.node = nullptr;
        *((_DWORD *)&superType + 1) &= 0xFFFFF000;
        v5 = v2;
        UnDecorator::getPrimaryDataType(result: &arg, &superType);
        if ( UnDecorator::gName - v5 > 1 && UnDecorator::pArgList->index != 9 )
          Replicator::operator+=(this: UnDecorator::pArgList, rd: &arg);
        p_arg = &arg;
      }
      else
      {
        UnDecorator::gName = v2 + 1;
        p_arg = (DName *)Replicator::operator[](this: UnDecorator::pArgList, x: v3);
      }
      DName::operator+=(this: result, rd: p_arg);
    }
    while ( (*((_BYTE *)result + 4) & 0xF) == 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00424A8E
// Name: private: static class DName UnDecorator::getVdispMapType(class DName const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__cdecl UnDecorator::getVdispMapType(DName *result, const DName *superType)
{
  DName *Scope; // eax
  DName v4; // [esp+4h] [ebp-8h] BYREF

  DName::DName(this: result, rd: superType);
  DName::operator+=(this: result, str: "{for ");
  Scope = UnDecorator::getScope(result: &v4);
  DName::operator+=(this: result, rd: Scope);
  DName::operator+=(this: result, ch: 125);
  if ( *UnDecorator::gName == 64 )
    ++UnDecorator::gName;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00424ADD
// Name: class DName operator+(char,class DName const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__cdecl operator+(DName *result, char c, DName *rd)
{
  DName *v3; // eax
  DName v5; // [esp+0h] [ebp-8h] BYREF

  v3 = DName::DName(this: &v5, c);
  DName::operator+(this: v3, result, rd);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00424AFF
// Name: class DName operator+(enum DNameStatus,class DName const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__cdecl operator+(DName *result, DNameStatus st, DName *rd)
{
  DName *v3; // eax
  DName v5; // [esp+0h] [ebp-8h] BYREF

  v3 = DName::DName(this: &v5, st);
  DName::operator+(this: v3, result, rd);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00424B21
// Name: class DName operator+(char const __near *,class DName const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__cdecl operator+(DName *result, char *s, DName *rd)
{
  DName *v3; // eax
  DName v5; // [esp+0h] [ebp-8h] BYREF

  v3 = DName::DName(this: &v5, s);
  DName::operator+(this: v3, result, rd);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00424B43
// Name: public: class DName DName::operator+(char)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__thiscall DName::operator+(DName *this, DName *result, char ch)
{
  DName *v3; // ecx

  DName::DName(this: result, rd: this);
  if ( DName::isEmpty(this: result) )
    DName::operator=(this: v3, ch);
  else
    DName::operator+=(this: v3, ch);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00424B71
// Name: public: class DName DName::operator+(char const __near *)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__thiscall DName::operator+(DName *this, DName *result, char *str)
{
  DName *v3; // ecx

  DName::DName(this: result, rd: this);
  if ( DName::isEmpty(this: result) )
    DName::operator=(this: v3, str);
  else
    DName::operator+=(this: v3, str);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00424B9F
// Name: private: static class DName UnDecorator::getDimension(bool)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__cdecl UnDecorator::getDimension(DName *result, bool fSigned)
{
  const char *v2; // esi
  int v3; // ecx
  bool v4; // zf
  char v5; // al
  unsigned __int64 v6; // rax
  DName *v7; // eax
  DName *v8; // eax
  unsigned int v9; // edi
  int v10; // ebx
  char v11; // al
  DName *v12; // eax
  DName *v13; // eax
  DName v15; // [esp+4h] [ebp-1Ch] BYREF
  DName v16; // [esp+Ch] [ebp-14h] BYREF
  DName v17; // [esp+14h] [ebp-Ch] BYREF
  char *prefix; // [esp+1Ch] [ebp-4h]

  v2 = UnDecorator::gName;
  v3 = 0;
  v4 = *UnDecorator::gName == 81;
  prefix = nullptr;
  if ( v4 )
  {
    v2 = UnDecorator::gName + 1;
    prefix = "`non-type-template-parameter";
    ++UnDecorator::gName;
  }
  v5 = *v2;
  if ( *v2 == 0 )
  {
    DName::DName(this: result, st: DN_truncated);
    return result;
  }
  if ( v5 < 48 || v5 > 57 )
  {
    v9 = 0;
    while ( v5 != 64 )
    {
      if ( v5 == 0 )
      {
        DName::DName(this: result, st: DN_truncated);
        return result;
      }
      if ( v5 < 65 || v5 > 80 )
        goto LABEL_23;
      v10 = v5 - 65;
      *((_DWORD *)&v17 + 1) = v10 >> 31;
      ++v2;
      v9 = (16 * __PAIR64__(v9, v3) + v10) >> 32;
      UnDecorator::gName = v2;
      v5 = *v2;
      v3 = 16 * v3 + v10;
    }
    v11 = *v2;
    UnDecorator::gName = v2 + 1;
    if ( v11 != 64 )
    {
LABEL_23:
      DName::DName(this: result, st: DN_invalid);
      return result;
    }
    if ( fSigned )
    {
      if ( prefix == nullptr )
      {
        v13 = DName::DName(this: &v17, num: __SPAIR64__(v9, v3));
LABEL_29:
        DName::DName(this: result, rd: v13);
        return result;
      }
      v12 = DName::DName(this: &v15, num: __SPAIR64__(v9, v3));
    }
    else
    {
      if ( prefix == nullptr )
      {
        v13 = DName::DName(this: &v17, num: __PAIR64__(v9, v3));
        goto LABEL_29;
      }
      v12 = DName::DName(this: &v15, num: __PAIR64__(v9, v3));
    }
    v13 = operator+(result: &v16, s: prefix, rd: v12);
    goto LABEL_29;
  }
  v6 = *v2 - 47;
  UnDecorator::gName = v2 + 1;
  if ( prefix != nullptr )
  {
    v7 = DName::DName(this: &v17, num: v6);
    v8 = operator+(result: &v16, s: prefix, rd: v7);
  }
  else
  {
    v8 = DName::DName(this: &v15, num: v6);
  }
  DName::DName(this: result, rd: v8);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00424CE0
// Name: private: static class DName UnDecorator::getEnumType(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__cdecl UnDecorator::getEnumType(DName *result)
{
  char v1; // al
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  DName *v6; // eax
  DName v8; // [esp+0h] [ebp-10h] BYREF
  DName ecsuName; // [esp+8h] [ebp-8h] BYREF

  v1 = *UnDecorator::gName;
  ecsuName.node = nullptr;
  *((_DWORD *)&ecsuName + 1) &= 0xFFFFF000;
  if ( v1 != 0 )
  {
    switch ( v1 )
    {
      case '0':
      case '1':
        DName::operator=(this: &ecsuName, str: "char ");
        goto $LN11_9;
      case '2':
      case '3':
        DName::operator=(this: &ecsuName, str: "short ");
        goto $LN11_9;
      case '4':
        goto $LN11_9;
      case '5':
        DName::operator=(this: &ecsuName, str: "int ");
        goto $LN11_9;
      case '6':
      case '7':
        DName::operator=(this: &ecsuName, str: "long ");
$LN11_9:
        v2 = *UnDecorator::gName++;
        v3 = v2 - 49;
        if ( v3 == 0 || (v4 = v3 - 2) == 0 || (v5 = v4 - 2) == 0 || v5 == 2 )
        {
          v6 = operator+(result: &v8, s: "unsigned ", rd: &ecsuName);
          DName::operator=(this: &ecsuName, rd: v6);
        }
        DName::DName(this: result, rd: &ecsuName);
        break;
      default:
        DName::DName(this: result, st: DN_invalid);
        break;
    }
  }
  else
  {
    DName::DName(this: result, st: DN_truncated);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00424DB4
// Name: private: static class DName UnDecorator::getArgumentTypes(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__cdecl UnDecorator::getArgumentTypes(DName *result)
{
  char v1; // al
  char *v2; // eax
  DName *p_arguments; // eax
  char *v4; // eax
  DName v6; // [esp+0h] [ebp-10h] BYREF
  DName arguments; // [esp+8h] [ebp-8h] BYREF

  if ( *UnDecorator::gName == 88 )
  {
    ++UnDecorator::gName;
    DName::DName(this: result, s: "void");
    return result;
  }
  if ( *UnDecorator::gName != 90 )
  {
    UnDecorator::getArgumentList(result: &arguments);
    if ( (*((_BYTE *)&arguments + 4) & 0xF) == 0 )
    {
      v1 = *UnDecorator::gName;
      if ( *UnDecorator::gName != 0 )
      {
        if ( v1 != 64 )
        {
          if ( v1 != 90 )
          {
            DName::DName(this: result, st: DN_invalid);
            return result;
          }
          ++UnDecorator::gName;
          v2 = ",...";
          if ( (UnDecorator::disableFlags & 0x40000) != 0 )
            v2 = ",<ellipsis>";
          p_arguments = DName::operator+(this: &arguments, result: &v6, str: v2);
LABEL_11:
          DName::DName(this: result, rd: p_arguments);
          return result;
        }
        ++UnDecorator::gName;
      }
    }
    p_arguments = &arguments;
    goto LABEL_11;
  }
  ++UnDecorator::gName;
  v4 = "...";
  if ( (UnDecorator::disableFlags & 0x40000) != 0 )
    v4 = "<ellipsis>";
  DName::DName(this: result, s: v4);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00424E78
// Name: private: static class DName UnDecorator::getThrowTypes(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__cdecl UnDecorator::getThrowTypes(DName *result)
{
  DName *ArgumentTypes; // eax
  DName *v2; // eax
  DName *v3; // eax
  DName *v4; // eax
  DName v6; // [esp+0h] [ebp-10h] BYREF
  DName rd; // [esp+8h] [ebp-8h] BYREF

  if ( *UnDecorator::gName != 0 )
  {
    if ( *UnDecorator::gName == 90 )
    {
      ++UnDecorator::gName;
      rd.node = nullptr;
      *((_DWORD *)&rd + 1) &= 0xFFFFF000;
      DName::DName(this: result, &rd);
    }
    else
    {
      ArgumentTypes = UnDecorator::getArgumentTypes(result: &rd);
      v2 = operator+(result: &v6, s: " throw(", rd: ArgumentTypes);
      DName::operator+(this: v2, result, ch: 41);
    }
  }
  else
  {
    v3 = DName::DName(this: &rd, s: " throw(");
    v4 = DName::operator+(this: v3, result: &v6, st: DN_truncated);
    DName::operator+(this: v4, result, ch: 41);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00424EF6
// Name: private: static class DName UnDecorator::getExtendedDataIndirectType(char __near &,bool __near &,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__cdecl UnDecorator::getExtendedDataIndirectType(DName *result, char *prType, bool *fIsPinPtr, int thisFlag)
{
  const char *v4; // edx
  unsigned int v5; // esi
  DName *v6; // eax
  const DName *v7; // eax
  const DName *v8; // eax
  const DName *v9; // eax
  DName v11; // [esp+4h] [ebp-28h] BYREF
  DName v12; // [esp+Ch] [ebp-20h] BYREF
  DName v13; // [esp+14h] [ebp-18h] BYREF
  DName v14; // [esp+1Ch] [ebp-10h] BYREF
  DName szComPlusIndirSpecifier; // [esp+24h] [ebp-8h] BYREF

  szComPlusIndirSpecifier.node = nullptr;
  *((_DWORD *)&szComPlusIndirSpecifier + 1) &= 0xFFFFF000;
  v4 = UnDecorator::gName + 1;
  UnDecorator::gName = v4;
  switch ( *v4 )
  {
    case 'A':
      if ( thisFlag == 0 )
        *prType = *prType != 38 ? 94 : 37;
      goto LABEL_14;
    case 'B':
      *fIsPinPtr = true;
      DName::operator=(this: &szComPlusIndirSpecifier, ch: 62);
      goto LABEL_14;
    case 'C':
      *prType = 37;
LABEL_14:
      ++UnDecorator::gName;
      result->node = nullptr;
      *((_DWORD *)result + 1) &= 0xFFFFF000;
      return result;
    default:
      break;
  }
  v5 = 16 * (*v4 - 48) + v4[1] - 48;
  UnDecorator::gName = v4 + 2;
  if ( v5 > 1 )
  {
    DName::operator=(this: &szComPlusIndirSpecifier, ch: 44);
    v6 = DName::DName(this: &v14, num: v5);
    v7 = DName::operator+(this: &szComPlusIndirSpecifier, result: &v13, rd: v6);
    DName::operator=(this: &szComPlusIndirSpecifier, rd: v7);
  }
  v8 = DName::operator+(this: &szComPlusIndirSpecifier, result: &v12, ch: 62);
  DName::operator=(this: &szComPlusIndirSpecifier, rd: v8);
  if ( *UnDecorator::gName == 36 )
  {
    ++UnDecorator::gName;
  }
  else
  {
    v9 = DName::operator+(this: &szComPlusIndirSpecifier, result: &v11, ch: 94);
    DName::operator=(this: &szComPlusIndirSpecifier, rd: v9);
  }
  ++UnDecorator::gName;
  *((_DWORD *)&szComPlusIndirSpecifier + 1) |= 0x400u;
  DName::DName(this: result, rd: &szComPlusIndirSpecifier);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042501B
// Name: private: static class DName UnDecorator::getArrayType(class DName const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__cdecl UnDecorator::getArrayType(DName *result, DName *superType)
{
  int NumberOfDimensions; // edi
  bool v3; // zf
  DName *p_arrayType; // eax
  DName *v5; // eax
  DName *v6; // eax
  const DName *v7; // eax
  DName *Dimension; // eax
  DName *v10; // eax
  DName *v11; // eax
  DName *v12; // ecx
  DName *v13; // eax
  const DName *v14; // eax
  DName *v15; // ecx
  DName *v16; // eax
  DName *v17; // [esp-10h] [ebp-3Ch]
  DName *p_newType; // [esp-8h] [ebp-34h]
  DName v19; // [esp+4h] [ebp-28h] BYREF
  DName v20; // [esp+Ch] [ebp-20h] BYREF
  DName v21; // [esp+14h] [ebp-18h] BYREF
  DName newType; // [esp+1Ch] [ebp-10h] BYREF
  DName arrayType; // [esp+24h] [ebp-8h] BYREF

  if ( *UnDecorator::gName == 0 )
  {
    v3 = !DName::isEmpty(this: superType);
    p_newType = &v19;
    p_arrayType = &v20;
    if ( v3 )
    {
      v17 = &v20;
      v16 = operator+(result: &newType, c: 40, rd: v15);
      v5 = DName::operator+(this: v16, result: &v21, str: ")[");
      goto LABEL_7;
    }
LABEL_6:
    v17 = p_arrayType;
    v5 = DName::DName(this: &v21, c: 91);
LABEL_7:
    v6 = DName::operator+(this: v5, result: v17, st: DN_truncated);
    v7 = DName::operator+(this: v6, result: p_newType, ch: 93);
    UnDecorator::getBasicDataType(result, superType: v7);
    return result;
  }
  NumberOfDimensions = UnDecorator::getNumberOfDimensions();
  v3 = NumberOfDimensions == 0;
  if ( NumberOfDimensions < 0 )
  {
    NumberOfDimensions = 0;
    v3 = true;
  }
  if ( v3 )
  {
    p_newType = &newType;
    p_arrayType = &arrayType;
    goto LABEL_6;
  }
  arrayType.node = nullptr;
  *((_DWORD *)&arrayType + 1) &= 0xFFFFF000;
  if ( *((char *)superType + 4) < 0 )
    DName::operator+=(this: &arrayType, str: "[]");
  do
  {
    --NumberOfDimensions;
    Dimension = UnDecorator::getDimension(result: &v20, fSigned: false);
    v10 = operator+(result: &v19, c: 91, rd: Dimension);
    v11 = DName::operator+(this: v10, result: &v21, ch: 93);
    DName::operator+=(this: &arrayType, rd: v11);
  }
  while ( NumberOfDimensions != 0 );
  if ( !DName::isEmpty(this: superType) )
  {
    if ( *((char *)superType + 4) >= 0 )
    {
      v13 = operator+(result: &v21, c: 40, rd: superType);
      v12 = DName::operator+(this: v13, result: &v20, ch: 41);
    }
    v14 = DName::operator+(this: v12, result: &v19, rd: &arrayType);
    DName::operator=(this: &arrayType, rd: v14);
  }
  UnDecorator::getPrimaryDataType(result: &newType, superType: &arrayType);
  *((_DWORD *)&newType + 1) |= 0x80u;
  DName::DName(this: result, rd: &newType);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042517A
// Name: private: static class DName UnDecorator::getLexicalFrame(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__cdecl UnDecorator::getLexicalFrame(DName *result)
{
  DName *Dimension; // eax
  DName *v2; // eax
  DName v4; // [esp+0h] [ebp-10h] BYREF
  DName v5; // [esp+8h] [ebp-8h] BYREF

  Dimension = UnDecorator::getDimension(result: &v5, fSigned: false);
  v2 = operator+(result: &v4, c: 96, rd: Dimension);
  DName::operator+(this: v2, result, ch: 39);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004251AB
// Name: private: static class DName UnDecorator::getVfTableType(class DName const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__cdecl UnDecorator::getVfTableType(DName *result, const DName *superType)
{
  DName *v2; // ecx
  DName *v3; // eax
  const DName *v4; // eax
  DName *v5; // ecx
  DName *Scope; // eax
  DName *v7; // eax
  DName *v8; // eax
  _BYTE *v9; // edx
  DName *v10; // ecx
  DName *v11; // ecx
  const DName *v12; // eax
  DName v14; // [esp+4h] [ebp-18h] BYREF
  DName v15; // [esp+Ch] [ebp-10h] BYREF
  DName v16; // [esp+14h] [ebp-8h] BYREF

  DName::DName(this: result, rd: superType);
  if ( DName::isValid(this: result) && *UnDecorator::gName != 0 )
  {
    UnDecorator::getDataIndirectType(result: &v16);
    v3 = DName::operator+(this: &v16, result: &v14, ch: 32);
    v4 = DName::operator+(this: v3, result: &v15, rd: result);
    DName::operator=(this: result, rd: v4);
    if ( DName::isValid(this: result) )
    {
      if ( *UnDecorator::gName == 64 )
        goto LABEL_19;
      DName::operator+=(this: v5, str: "{for ");
      while ( DName::isValid(this: result) && *UnDecorator::gName != 0 && *UnDecorator::gName != 64 )
      {
        Scope = UnDecorator::getScope(result: &v15);
        v7 = operator+(result: &v16, c: 96, rd: Scope);
        v8 = DName::operator+(this: v7, result: &v14, ch: 39);
        DName::operator+=(this: result, rd: v8);
        if ( *UnDecorator::gName == 64 )
          ++UnDecorator::gName;
        if ( DName::isValid(this: result) && *v9 != 64 )
          DName::operator+=(this: v10, str: "s ");
      }
      if ( DName::isValid(this: result) )
      {
        if ( *UnDecorator::gName == 0 )
          DName::operator+=(this: v11, st: DN_truncated);
        DName::operator+=(this: result, ch: 125);
      }
      if ( *UnDecorator::gName == 64 )
LABEL_19:
        ++UnDecorator::gName;
    }
  }
  else if ( DName::isValid(this: v2) )
  {
    v12 = operator+(result: &v14, st: DN_truncated, rd: result);
    DName::operator=(this: result, rd: v12);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004252FB
// Name: private: static class DName UnDecorator::getStringEncoding(char __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__cdecl UnDecorator::getStringEncoding(DName *result, char *prefix)
{
  char v2; // al
  char v3; // al
  const char *v4; // eax
  char v5; // cl
  DName v7; // [esp+0h] [ebp-10h] BYREF
  DName v8; // [esp+8h] [ebp-8h] BYREF

  DName::DName(this: &v8, s: prefix);
  v2 = *UnDecorator::gName++;
  if ( v2 == 64 && (v3 = *UnDecorator::gName, ++UnDecorator::gName, v3 == 95) )
  {
    ++UnDecorator::gName;
    UnDecorator::getDimension(result: &v7, fSigned: false);
    UnDecorator::getDimension(result: &v7, fSigned: false);
    v4 = UnDecorator::gName;
    v5 = *UnDecorator::gName;
    if ( *UnDecorator::gName == 0 )
      goto LABEL_7;
    do
    {
      if ( v5 == 64 )
        break;
      UnDecorator::gName = ++v4;
      v5 = *v4;
    }
    while ( *v4 != 0 );
    if ( *v4 != 0 )
    {
      UnDecorator::gName = v4 + 1;
      DName::DName(this: result, rd: &v8);
    }
    else
    {
LABEL_7:
      UnDecorator::gName = v4 - 1;
      DName::DName(this: result, st: DN_truncated);
    }
  }
  else
  {
    DName::DName(this: result, st: DN_invalid);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042539B
// Name: private: static class DName UnDecorator::getSignedDimension(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__cdecl UnDecorator::getSignedDimension(DName *result)
{
  DName *Dimension; // eax
  DName v3; // [esp+0h] [ebp-8h] BYREF

  if ( *UnDecorator::gName != 0 )
  {
    if ( *UnDecorator::gName == 63 )
    {
      ++UnDecorator::gName;
      Dimension = UnDecorator::getDimension(result: &v3, fSigned: false);
      operator+(result, c: 45, rd: Dimension);
    }
    else
    {
      UnDecorator::getDimension(result, fSigned: false);
    }
  }
  else
  {
    DName::DName(this: result, st: DN_truncated);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004253EB
// Name: private: static class DName UnDecorator::getTemplateConstant(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__cdecl UnDecorator::getTemplateConstant(DName *result)
{
  char v1; // bl
  DName *v2; // eax
  DName *v3; // eax
  int v4; // eax
  char *Parameter; // eax
  DName *v6; // eax
  DName *v7; // eax
  DName *v8; // eax
  DName *v9; // eax
  DName *SignedDimension; // eax
  DName *v12; // [esp-8h] [ebp-70h]
  DName *DecoratedName; // [esp-4h] [ebp-6Ch]
  DName v14; // [esp+Ch] [ebp-5Ch] BYREF
  DName v15; // [esp+14h] [ebp-54h] BYREF
  DName v16; // [esp+1Ch] [ebp-4Ch] BYREF
  DName v17; // [esp+24h] [ebp-44h] BYREF
  DName v18; // [esp+2Ch] [ebp-3Ch] BYREF
  DName v19; // [esp+34h] [ebp-34h] BYREF
  DName v20; // [esp+3Ch] [ebp-2Ch] BYREF
  DName v21; // [esp+44h] [ebp-24h] BYREF
  DName v22; // [esp+4Ch] [ebp-1Ch] BYREF
  DName v23; // [esp+54h] [ebp-14h] BYREF
  DName ptm; // [esp+5Ch] [ebp-Ch] BYREF
  char buf[100]; // [esp+64h] [ebp-4h] BYREF
  char nptr[8]; // [esp+C8h] [ebp+60h] BYREF
  DName v27; // [esp+D0h] [ebp+68h] BYREF

  v1 = *UnDecorator::gName++;
  if ( v1 <= 68 )
  {
    if ( v1 != 68 )
    {
      if ( v1 != 0 )
      {
        if ( v1 == 48 )
        {
          UnDecorator::getSignedDimension(result);
          return result;
        }
        if ( v1 == 49 )
        {
          if ( *UnDecorator::gName == 64 )
          {
            ++UnDecorator::gName;
            DName::DName(this: result, s: "NULL");
            return result;
          }
          DecoratedName = UnDecorator::getDecoratedName(result: &v21);
          v12 = result;
          v3 = DName::DName(this: &v17, s: "&");
LABEL_16:
          DName::operator+(this: v3, result: v12, rd: DecoratedName);
          return result;
        }
        if ( v1 != 50 )
        {
LABEL_10:
          DName::DName(this: result, st: DN_invalid);
          return result;
        }
        UnDecorator::getSignedDimension(result: &ptm);
        UnDecorator::getSignedDimension(result: &v27);
        if ( DName::isValid(this: &ptm) && DName::isValid(this: &v27) )
        {
          if ( DName::getString(this: &ptm, buf: &buf[1], max: (char *)0x64) == nullptr )
            goto LABEL_10;
          buf[0] = buf[1];
          if ( buf[1] == 45 )
          {
            buf[1] = buf[2];
            buf[2] = 46;
          }
          else
          {
            buf[1] = 46;
          }
          DecoratedName = &v27;
          v12 = result;
          v2 = DName::DName(this: &v14, s: buf);
          v3 = DName::operator+(this: v2, result: &v19, ch: 101);
          goto LABEL_16;
        }
      }
      else
      {
        --UnDecorator::gName;
      }
      DName::DName(this: result, st: DN_truncated);
      return result;
    }
    goto LABEL_30;
  }
  if ( v1 == 69 )
  {
    UnDecorator::getDecoratedName(result);
    return result;
  }
  if ( v1 <= 69 )
    goto LABEL_10;
  if ( v1 <= 74 )
  {
    DName::DName(this: &ptm, c: 123);
    if ( v1 >= 72 && v1 <= 74 )
    {
      v7 = UnDecorator::getDecoratedName(result: &v22);
      DName::operator+=(this: &ptm, rd: v7);
      DName::operator+=(this: &ptm, ch: 44);
    }
    if ( v1 == 70 )
      goto LABEL_46;
    if ( v1 != 71 )
    {
      if ( v1 == 72 )
      {
LABEL_47:
        SignedDimension = UnDecorator::getSignedDimension(result: &v16);
        DName::operator+=(this: &ptm, rd: SignedDimension);
        goto LABEL_48;
      }
      if ( v1 == 73 )
      {
LABEL_46:
        v9 = UnDecorator::getSignedDimension(result: &v18);
        DName::operator+=(this: &ptm, rd: v9);
        DName::operator+=(this: &ptm, ch: 44);
        goto LABEL_47;
      }
      if ( v1 != 74 )
      {
LABEL_48:
        DName::operator+(this: &ptm, result, ch: 125);
        return result;
      }
    }
    v8 = UnDecorator::getSignedDimension(result: &v20);
    DName::operator+=(this: &ptm, rd: v8);
    DName::operator+=(this: &ptm, ch: 44);
    goto LABEL_46;
  }
  if ( v1 == 81 )
  {
LABEL_30:
    UnDecorator::getSignedDimension(result: &ptm);
    if ( (UnDecorator::disableFlags & 0x4000) != 0
      && (DName::getString(this: &ptm, buf: nptr, max: (char *)0x10),
          v4 = atol(nptr),
          (Parameter = UnDecorator::m_pGetParameter(a1: v4)) != nullptr) )
    {
      DName::DName(this: result, s: Parameter);
    }
    else
    {
      if ( v1 == 68 )
        v6 = operator+(result: &v23, s: "`template-parameter", rd: &ptm);
      else
        v6 = operator+(result: &v15, s: "`non-type-template-parameter", rd: &ptm);
      DName::operator+(this: v6, result, str: "'");
    }
    return result;
  }
  if ( v1 != 82 )
    goto LABEL_10;
  UnDecorator::getZName(result: &v27, fUpdateCachedNames: false);
  UnDecorator::getSignedDimension(result: &ptm);
  DName::DName(this: result, rd: &v27);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004256A6
// Name: private: static class DName UnDecorator::getPtrRefDataType(class DName const __near &,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__cdecl UnDecorator::getPtrRefDataType(DName *result, DName *superType, int isPtr)
{
  DName *v3; // ecx
  int v4; // eax
  DName *v5; // eax
  DName v7; // [esp+0h] [ebp-10h] BYREF
  DName bdt; // [esp+8h] [ebp-8h] BYREF

  if ( *UnDecorator::gName == 0 )
  {
    operator+(result, st: DN_truncated, rd: superType);
    return result;
  }
  if ( isPtr == 0 || *UnDecorator::gName != 88 )
  {
    if ( *UnDecorator::gName == 89 )
    {
      ++UnDecorator::gName;
      UnDecorator::getArrayType(result, superType);
      return result;
    }
    UnDecorator::getBasicDataType(result: &bdt, superType);
    v4 = *((_DWORD *)superType + 1);
    if ( (v4 & 0x400) != 0 )
    {
      v5 = operator+(result: &v7, s: "cli::array<", rd: &bdt);
    }
    else
    {
      if ( (v4 & 0x200) == 0 )
      {
LABEL_14:
        DName::DName(this: result, rd: &bdt);
        return result;
      }
      v5 = operator+(result: &v7, s: "cli::pin_ptr<", rd: &bdt);
    }
    DName::operator=(this: &bdt, rd: v5);
    goto LABEL_14;
  }
  ++UnDecorator::gName;
  if ( DName::isEmpty(this: superType) )
    DName::DName(this: result, s: "void");
  else
    operator+(result, s: "void ", rd: v3);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042577F
// Name: private: static class DName UnDecorator::getTemplateArgumentList(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__cdecl UnDecorator::getTemplateArgumentList(DName *result)
{
  bool v1; // zf
  const char *v2; // eax
  char v3; // dl
  unsigned int v4; // ecx
  DName *p_arg; // eax
  const char *v6; // ebx
  const char *v7; // eax
  DName *PrimaryDataType; // eax
  int v9; // eax
  const char *Parameter; // eax
  DName *v11; // eax
  DName *v13; // [esp-Ch] [ebp-74h]
  DName v14; // [esp+8h] [ebp-60h] BYREF
  char v15; // [esp+10h] [ebp-58h] BYREF
  DName v16; // [esp+18h] [ebp-50h] BYREF
  DName v17; // [esp+20h] [ebp-48h] BYREF
  DName v18; // [esp+28h] [ebp-40h] BYREF
  DName v19; // [esp+30h] [ebp-38h] BYREF
  DName superType; // [esp+38h] [ebp-30h] BYREF
  DName dimension; // [esp+40h] [ebp-28h] BYREF
  int first; // [esp+48h] [ebp-20h]
  DName arg; // [esp+4Ch] [ebp-1Ch] BYREF
  char buffer[16]; // [esp+54h] [ebp-14h] BYREF

  result->node = nullptr;
  *((_DWORD *)result + 1) &= 0xFFFFF000;
  UnDecorator::fGetTemplateArgumentList = true;
  v1 = (*((_BYTE *)result + 4) & 0xF) == 0;
  first = 1;
  if ( v1 )
  {
    while ( 1 )
    {
      v2 = UnDecorator::gName;
      if ( *UnDecorator::gName == 0 || *UnDecorator::gName == 64 )
        goto LABEL_29;
      if ( first != 0 )
      {
        first = 0;
      }
      else
      {
        DName::operator+=(this: result, ch: 44);
        v2 = UnDecorator::gName;
      }
      v3 = *v2;
      v4 = *v2 - 48;
      if ( v4 > 9 )
        break;
      UnDecorator::gName = v2 + 1;
      p_arg = (DName *)Replicator::operator[](this: UnDecorator::pTemplateArgList, x: v4);
LABEL_28:
      DName::operator+=(this: result, rd: p_arg);
      if ( (*((_BYTE *)result + 4) & 0xF) != 0 )
        goto LABEL_29;
    }
    arg.node = nullptr;
    *((_DWORD *)&arg + 1) &= 0xFFFFF000;
    v6 = v2;
    if ( v3 == 88 )
    {
      UnDecorator::gName = v2 + 1;
      DName::operator=(this: &arg, str: "void");
    }
    else
    {
      if ( v3 != 36 || *(v7 = v2 + 1) == 36 )
      {
        if ( v3 == 63 )
        {
          UnDecorator::getSignedDimension(result: &dimension);
          if ( (UnDecorator::disableFlags & 0x4000) != 0 )
          {
            DName::getString(this: &dimension, buf: buffer, max: (char *)0x10);
            v9 = atol(nptr: buffer);
            Parameter = UnDecorator::m_pGetParameter(a1: v9);
            if ( Parameter != nullptr )
            {
              DName::operator=(this: &arg, str: Parameter);
              goto LABEL_24;
            }
            v13 = &v19;
            v11 = operator+(result: &v17, s: "`template-parameter", rd: &dimension);
          }
          else
          {
            v13 = (DName *)&v15;
            v11 = operator+(result: &v18, s: "`template-parameter", rd: &dimension);
          }
          PrimaryDataType = DName::operator+(this: v11, result: v13, str: "'");
        }
        else
        {
          superType.node = nullptr;
          *((_DWORD *)&superType + 1) &= 0xFFFFF000;
          PrimaryDataType = UnDecorator::getPrimaryDataType(result: &v16, &superType);
        }
      }
      else
      {
        UnDecorator::gName = v7;
        PrimaryDataType = UnDecorator::getTemplateConstant(result: &v14);
      }
      DName::operator=(this: &arg, rd: PrimaryDataType);
    }
LABEL_24:
    if ( UnDecorator::gName - v6 > 1 && UnDecorator::pTemplateArgList->index != 9 )
      Replicator::operator+=(this: UnDecorator::pTemplateArgList, rd: &arg);
    p_arg = &arg;
    goto LABEL_28;
  }
LABEL_29:
  UnDecorator::fGetTemplateArgumentList = false;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00425937
// Name: private: static class DName UnDecorator::getOperatorName(bool,bool __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__cdecl UnDecorator::getOperatorName(DName *result, bool fIsTemplate, bool *pfReadTemplateArguments)
{
  int v3; // edx
  int v4; // esi
  const char *v5; // eax
  DName *v6; // ecx
  DName *v7; // eax
  DName *p_name; // eax
  DName *TemplateArgumentList; // eax
  DName *v11; // eax
  const char *v12; // esi
  const DName *ZName; // eax
  DName *v14; // ecx
  const DName *v15; // eax
  DName *v16; // ecx
  int v17; // ecx
  int v18; // ecx
  int v19; // ecx
  int v20; // ecx
  int v21; // eax
  DName *p_operatorName; // ecx
  DName *SignedDimension; // eax
  DName *v24; // eax
  DName *v25; // eax
  DName *v26; // eax
  DName *v27; // eax
  DName *v28; // eax
  DName *Dimension; // eax
  DName *v30; // eax
  DName *v31; // eax
  const DName *v32; // eax
  int v33; // ecx
  const char *v34; // eax
  DName *DecoratedName; // eax
  DName *SymbolName; // eax
  DName *v37; // [esp-8h] [ebp-44h]
  DName v38; // [esp+8h] [ebp-34h] BYREF
  DName v39; // [esp+10h] [ebp-2Ch] BYREF
  DName v40; // [esp+18h] [ebp-24h] BYREF
  DName v41; // [esp+20h] [ebp-1Ch] BYREF
  DName v42; // [esp+28h] [ebp-14h] BYREF
  DName v43; // [esp+30h] [ebp-Ch] BYREF
  DName v44; // [esp+38h] [ebp-4h] BYREF
  DName v45; // [esp+40h] [ebp+4h] BYREF
  DName v46; // [esp+48h] [ebp+Ch] BYREF
  DName v47; // [esp+50h] [ebp+14h] BYREF
  DName v48; // [esp+58h] [ebp+1Ch] BYREF
  DName v49; // [esp+60h] [ebp+24h] BYREF
  DName v50; // [esp+68h] [ebp+2Ch] BYREF
  DName v51; // [esp+70h] [ebp+34h] BYREF
  DName v52; // [esp+78h] [ebp+3Ch] BYREF
  DName v53; // [esp+80h] [ebp+44h] BYREF
  DName v54; // [esp+88h] [ebp+4Ch] BYREF
  DName templateArguments; // [esp+90h] [ebp+54h] BYREF
  DName name; // [esp+98h] [ebp+5Ch] BYREF
  DName operatorName; // [esp+A0h] [ebp+64h] BYREF

  v3 = *UnDecorator::gName;
  *((_DWORD *)&operatorName + 1) &= 0xFFFFF000;
  *((_DWORD *)&templateArguments + 1) &= 0xFFFFF000;
  v4 = 0;
  v5 = UnDecorator::gName + 1;
  operatorName.node = nullptr;
  templateArguments.node = nullptr;
  ++UnDecorator::gName;
  if ( v3 > 65 )
  {
    if ( v3 == 66 )
    {
      v4 = 1;
    }
    else if ( v3 > 90 )
    {
      if ( v3 != 95 )
        goto LABEL_49;
      v17 = *v5++;
      UnDecorator::gName = v5;
      if ( v17 <= 79 )
      {
        if ( v17 < 68 )
        {
          if ( v17 <= 57 )
          {
            if ( v17 != 57 )
            {
              if ( v17 != 0 )
              {
                if ( v17 > 47 )
                {
                  if ( v17 > 54 )
                  {
                    DName::DName(this: result, s: (char *)tokenTable[*(v5 - 1) + 2]);
                    return result;
                  }
                  DName::operator=(this: &operatorName, str: tokenTable[*(v5 - 1) + 2]);
                  goto LABEL_8;
                }
                goto LABEL_49;
              }
              goto LABEL_26;
            }
            DName::DName(this: &name, s: (char *)tokenTable[*(v5 - 1) + 2]);
            *((_DWORD *)&name + 1) |= 0x800u;
LABEL_41:
            p_name = &name;
            goto LABEL_11;
          }
          if ( v17 == 63 )
          {
            v18 = *v5++;
            UnDecorator::gName = v5;
            if ( v18 == 0 )
              goto LABEL_26;
            if ( v18 != 48 )
              goto LABEL_49;
            UnDecorator::getStringEncoding(result: &name, prefix: "`anonymous namespace'");
            goto LABEL_46;
          }
          if ( v17 <= 64 )
            goto LABEL_49;
          if ( v17 > 66 )
          {
            UnDecorator::getStringEncoding(result: &name, prefix: "`string'");
LABEL_46:
            *((_DWORD *)&name + 1) |= 0x100u;
            goto LABEL_41;
          }
        }
LABEL_81:
        DName::DName(this: result, s: (&dword_43B564)[*(v5 - 1)]);
        return result;
      }
      if ( v17 > 84 )
      {
        if ( v17 > 86 )
        {
          if ( v17 <= 87 )
            goto LABEL_49;
          if ( v17 > 89 )
          {
            if ( v17 != 95 )
              goto LABEL_49;
            v33 = *v5;
            v34 = v5 + 1;
            UnDecorator::gName = v34;
            if ( v33 < 65 )
              goto LABEL_49;
            if ( v33 > 68 )
            {
              if ( v33 <= 70 )
              {
                DName::DName(this: &name, s: (char *)nameTable[*(v34 - 1) + 4]);
                if ( *UnDecorator::gName == 63 )
                {
                  DecoratedName = UnDecorator::getDecoratedName(result: &v40);
                  DName::operator+=(this: &name, rd: DecoratedName);
                  if ( *UnDecorator::gName == 64 )
                    ++UnDecorator::gName;
                }
                else
                {
                  SymbolName = UnDecorator::getSymbolName(result: &v54);
                  DName::operator+=(this: &name, rd: SymbolName);
                }
                DName::operator+=(this: &name, str: "''");
                goto LABEL_41;
              }
              if ( v33 > 74 )
                goto LABEL_49;
            }
            DName::DName(this: result, s: (char *)nameTable[*(v34 - 1) + 4]);
            return result;
          }
          goto LABEL_81;
        }
        DName::operator=(this: &operatorName, str: (&dword_43B564)[*(v5 - 1)]);
      }
      else
      {
        if ( v17 >= 83 )
          goto LABEL_81;
        v19 = v17 - 80;
        if ( v19 == 0 )
        {
          DName::operator=(this: &operatorName, str: (&dword_43B564)[*(v5 - 1)]);
          v32 = UnDecorator::getOperatorName(result: &v42, fIsTemplate: false, pfReadTemplateArguments: nullptr);
          DName::operator=(this: &templateArguments, rd: v32);
          if ( !DName::isEmpty(this: &templateArguments) && (*((_BYTE *)&templateArguments + 4) & 0x40) != 0 )
            goto LABEL_49;
          goto LABEL_59;
        }
        v20 = v19 - 1;
        if ( v20 != 0 )
        {
          if ( v20 != 1 )
            goto LABEL_49;
          DName::operator=(this: &operatorName, str: (&dword_43B564)[*(v5 - 1)]);
          DName::operator=(this: &templateArguments, str: *(const char **)&asc_43B4E4[4 * *UnDecorator::gName]);
          v21 = *UnDecorator::gName++;
          if ( v21 == 48 )
          {
            UnDecorator::getDataType(result: &name, pDeclarator: nullptr);
            v37 = result;
            v31 = DName::operator+(this: &name, result: &v44, ch: 32);
            p_operatorName = DName::operator+(this: v31, result: &v46, rd: &operatorName);
            goto LABEL_60;
          }
          if ( v21 == 49 )
          {
            DName::operator+(this: &operatorName, result: &name, rd: &templateArguments);
            SignedDimension = UnDecorator::getSignedDimension(result: &v43);
            v24 = DName::operator+(this: SignedDimension, result: &v49, ch: 44);
            DName::operator+=(this: &name, rd: v24);
            v25 = UnDecorator::getSignedDimension(result: &v39);
            v26 = DName::operator+(this: v25, result: &v53, ch: 44);
            DName::operator+=(this: &name, rd: v26);
            v27 = UnDecorator::getSignedDimension(result: &v52);
            v28 = DName::operator+(this: v27, result: &v45, ch: 44);
            DName::operator+=(this: &name, rd: v28);
            Dimension = UnDecorator::getDimension(result: &v48, fSigned: false);
            v30 = DName::operator+(this: Dimension, result: &v50, ch: 41);
            DName::operator+=(this: &name, rd: v30);
            DName::operator+(this: &name, result, ch: 39);
            return result;
          }
          if ( (unsigned int)(v21 - 50) > 2 )
          {
            --UnDecorator::gName;
            goto LABEL_27;
          }
LABEL_59:
          v37 = result;
          p_operatorName = &operatorName;
LABEL_60:
          DName::operator+(this: p_operatorName, result: v37, rd: &templateArguments);
          return result;
        }
      }
LABEL_8:
      if ( !DName::isEmpty(this: &operatorName) )
      {
        v7 = operator+(result: &v54, s: "operator", rd: v6);
        DName::operator=(this: &operatorName, rd: v7);
      }
      goto LABEL_10;
    }
LABEL_84:
    DName::operator=(this: &operatorName, str: *(const char **)&aOperator[4 * *(v5 - 1) + 4]);
    if ( v4 != 0 )
    {
      if ( !DName::isEmpty(this: &operatorName) )
        *((_DWORD *)&operatorName + 1) |= 0x20u;
      goto LABEL_10;
    }
    goto LABEL_8;
  }
  if ( v3 == 65 )
    goto LABEL_84;
  if ( v3 == 0 )
  {
LABEL_26:
    UnDecorator::gName = v5 - 1;
LABEL_27:
    DName::DName(this: result, st: DN_truncated);
    return result;
  }
  if ( v3 <= 47 )
    goto LABEL_49;
  if ( v3 > 49 )
  {
    if ( v3 <= 57 )
    {
      DName::operator=(this: &operatorName, str: *(const char **)&asc_43B4F0[4 * *(v5 - 1)]);
      goto LABEL_8;
    }
LABEL_49:
    DName::DName(this: result, st: DN_invalid);
    return result;
  }
  *((_DWORD *)&templateArguments + 1) &= 0xFFFFF000;
  templateArguments.node = nullptr;
  if ( fIsTemplate )
  {
    TemplateArgumentList = UnDecorator::getTemplateArgumentList(result: &v47);
    v11 = operator+(result: &v38, c: 60, rd: TemplateArgumentList);
    DName::operator+=(this: &templateArguments, rd: v11);
    if ( DName::getLastChar(this: &templateArguments) == 62 )
      DName::operator+=(this: &templateArguments, ch: 32);
    DName::operator+=(this: &templateArguments, ch: 62);
    if ( pfReadTemplateArguments != nullptr )
      *pfReadTemplateArguments = true;
    if ( *UnDecorator::gName == 0 )
    {
      p_name = &templateArguments;
      goto LABEL_11;
    }
    v5 = ++UnDecorator::gName;
  }
  v12 = v5;
  ZName = UnDecorator::getZName(result: &v51, fUpdateCachedNames: false);
  DName::operator=(this: &operatorName, rd: ZName);
  UnDecorator::gName = v12;
  if ( !DName::isEmpty(this: &operatorName) && *(v12 - 1) == 49 )
  {
    v15 = operator+(result: &v41, c: 126, rd: v14);
    DName::operator=(this: &operatorName, rd: v15);
  }
  if ( !DName::isEmpty(this: &templateArguments) )
    DName::operator+=(this: &operatorName, rd: v16);
LABEL_10:
  p_name = &operatorName;
LABEL_11:
  DName::DName(this: result, rd: p_name);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00425EA6
// Name: private: static class DName UnDecorator::getTemplateName(bool)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__cdecl UnDecorator::getTemplateName(DName *result, bool fReadTerminator)
{
  Replicator *v2; // ebx
  Replicator *v3; // esi
  Replicator *v4; // edi
  bool v5; // zf
  const DName *OperatorName; // eax
  DName *TemplateArgumentList; // eax
  DName *v8; // eax
  Replicator localTemplateArgList; // [esp+0h] [ebp-60h] BYREF
  Replicator localArgList; // [esp+3Ch] [ebp-24h] BYREF
  Replicator localZNameList; // [esp+78h] [ebp+18h] BYREF
  DName v13; // [esp+B4h] [ebp+54h] BYREF
  DName v14; // [esp+BCh] [ebp+5Ch] BYREF
  DName templateName; // [esp+C4h] [ebp+64h] BYREF
  bool fReadTemplateArguments; // [esp+CFh] [ebp+6Fh] BYREF

  if ( *UnDecorator::gName == 63 && UnDecorator::gName[1] == 36 )
  {
    v2 = UnDecorator::pTemplateArgList;
    v3 = UnDecorator::pArgList;
    v4 = UnDecorator::pZNameList;
    UnDecorator::gName += 2;
    Replicator::Replicator(this: &localArgList);
    Replicator::Replicator(this: &localZNameList);
    Replicator::Replicator(this: &localTemplateArgList);
    templateName.node = nullptr;
    *((_DWORD *)&templateName + 1) &= 0xFFFFF000;
    UnDecorator::pArgList = &localArgList;
    UnDecorator::pZNameList = &localZNameList;
    UnDecorator::pTemplateArgList = &localTemplateArgList;
    v5 = *UnDecorator::gName == 63;
    fReadTemplateArguments = false;
    if ( v5 )
    {
      ++UnDecorator::gName;
      OperatorName = UnDecorator::getOperatorName(
                       result: &v14,
                       fIsTemplate: true,
                       pfReadTemplateArguments: &fReadTemplateArguments);
    }
    else
    {
      OperatorName = UnDecorator::getZName(result: &v14, fUpdateCachedNames: true);
    }
    DName::operator=(this: &templateName, rd: OperatorName);
    if ( DName::isEmpty(this: &templateName) )
      UnDecorator::fExplicitTemplateParams = true;
    if ( !fReadTemplateArguments )
    {
      TemplateArgumentList = UnDecorator::getTemplateArgumentList(result: &v14);
      v8 = operator+(result: &v13, c: 60, rd: TemplateArgumentList);
      DName::operator+=(this: &templateName, rd: v8);
      if ( DName::getLastChar(this: &templateName) == 62 )
        DName::operator+=(this: &templateName, ch: 32);
      DName::operator+=(this: &templateName, ch: 62);
      if ( fReadTerminator )
        ++UnDecorator::gName;
    }
    UnDecorator::pArgList = v3;
    UnDecorator::pZNameList = v4;
    UnDecorator::pTemplateArgList = v2;
    DName::DName(this: result, rd: &templateName);
  }
  else
  {
    DName::DName(this: result, st: DN_invalid);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00425FF9
// Name: private: static class DName UnDecorator::getZName(bool)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__cdecl UnDecorator::getZName(DName *result, bool fUpdateCachedNames)
{
  char v2; // dl
  unsigned int v3; // ecx
  const DName *v4; // eax
  const DName *TemplateName; // eax
  const char *v7; // eax
  const char *v9; // ecx
  const char *v10; // edi
  const char *v11; // esi
  int i; // ebx
  const char *v13; // eax
  const char *v14; // edi
  const char *v15; // esi
  int j; // ebx
  char *v17; // esi
  int v18; // eax
  const char *Parameter; // eax
  DName *v20; // eax
  DName *v21; // eax
  DName *v22; // eax
  DName *v23; // [esp-10h] [ebp-4Ch]
  DName v24; // [esp+4h] [ebp-38h] BYREF
  DName v25; // [esp+Ch] [ebp-30h] BYREF
  DName *v26; // [esp+14h] [ebp-28h]
  DName dimension; // [esp+18h] [ebp-24h] BYREF
  DName zName; // [esp+20h] [ebp-1Ch] BYREF
  char buffer[16]; // [esp+28h] [ebp-14h] BYREF

  v2 = *UnDecorator::gName;
  v3 = *UnDecorator::gName - 48;
  v26 = result;
  if ( v3 <= 9 )
  {
    ++UnDecorator::gName;
    v4 = Replicator::operator[](this: UnDecorator::pZNameList, x: v3);
    DName::DName(this: result, rd: v4);
    return result;
  }
  zName.node = nullptr;
  *((_DWORD *)&zName + 1) &= 0xFFFFF000;
  if ( v2 == 63 )
  {
    TemplateName = UnDecorator::getTemplateName(result: &dimension, fReadTerminator: false);
    DName::operator=(this: &zName, rd: TemplateName);
    v7 = UnDecorator::gName + 1;
    if ( *UnDecorator::gName++ != 64 )
    {
      UnDecorator::gName = v7 - 1;
      DName::operator=(this: &zName, st: (DNameStatus)((*(v7 - 1) == 0) + 1));
    }
    goto LABEL_25;
  }
  v9 = "template-parameter-";
  v10 = "template-parameter-";
  v11 = UnDecorator::gName;
  for ( i = 18; i != 0; --i )
  {
    if ( *v11 == 0 )
      break;
    if ( *v11 != *v10 )
      break;
    ++v11;
    ++v10;
  }
  if ( *(unsigned __int8 *)v11 == *(unsigned __int8 *)v10 )
  {
    v13 = UnDecorator::gName + 19;
  }
  else
  {
    v9 = "generic-type-";
    v14 = "generic-type-";
    v15 = UnDecorator::gName;
    for ( j = 12; j != 0; --j )
    {
      if ( *v15 == 0 )
        break;
      if ( *v15 != *v14 )
        break;
      ++v15;
      ++v14;
    }
    if ( *(unsigned __int8 *)v15 != *(unsigned __int8 *)v14 )
    {
      v22 = DName::DName(this: &v25, name: (char **)&UnDecorator::gName, terminator: 64);
      DName::operator=(this: &zName, rd: v22);
      goto LABEL_25;
    }
    v13 = UnDecorator::gName + 13;
  }
  UnDecorator::gName = v13;
  v17 = (char *)v9;
  UnDecorator::getSignedDimension(result: &dimension);
  if ( (UnDecorator::disableFlags & 0x4000) == 0 )
  {
    DName::operator=(this: &zName, str: "`");
    v23 = &v25;
    v20 = operator+(result: &v24, s: v17, rd: &dimension);
    goto LABEL_23;
  }
  DName::getString(this: &dimension, buf: buffer, max: (char *)0x10);
  v18 = atol(nptr: buffer);
  Parameter = UnDecorator::m_pGetParameter(a1: v18);
  if ( Parameter == nullptr )
  {
    DName::operator=(this: &zName, str: "`");
    v23 = &v24;
    v20 = operator+(result: &v25, s: v17, rd: &dimension);
LABEL_23:
    v21 = DName::operator+(this: v20, result: v23, str: "'");
    DName::operator+=(this: &zName, rd: v21);
    goto LABEL_25;
  }
  DName::operator=(this: &zName, str: Parameter);
LABEL_25:
  if ( fUpdateCachedNames && UnDecorator::pZNameList->index != 9 )
    Replicator::operator+=(this: UnDecorator::pZNameList, rd: &zName);
  DName::DName(this: v26, rd: &zName);
  return v26;
}

//------------------------------------------------------------------------------
// Address: 0x004261E3
// Name: private: static class DName UnDecorator::getScopedName(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__cdecl UnDecorator::getScopedName(DName *result)
{
  const DName *ZName; // eax
  DName *Scope; // eax
  DName *v3; // eax
  const DName *v4; // eax
  int v5; // eax
  DName *v6; // ecx
  DName *v7; // eax
  DName *v8; // eax
  const DName *v9; // eax
  DName v11; // [esp+8h] [ebp-18h] BYREF
  DName v12; // [esp+10h] [ebp-10h] BYREF
  DName v13; // [esp+18h] [ebp-8h] BYREF

  result->node = nullptr;
  *((_DWORD *)result + 1) &= 0xFFFFF000;
  ZName = UnDecorator::getZName(result: &v13, fUpdateCachedNames: true);
  DName::operator=(this: result, rd: ZName);
  if ( (*((_BYTE *)result + 4) & 0xF) == 0 && *UnDecorator::gName != 0 )
  {
    if ( *UnDecorator::gName == 64 )
    {
LABEL_6:
      ++UnDecorator::gName;
      return result;
    }
    Scope = UnDecorator::getScope(result: &v11);
    v3 = DName::operator+(this: Scope, result: &v12, str: "::");
    v4 = DName::operator+(this: v3, result: &v13, rd: result);
    DName::operator=(this: result, rd: v4);
  }
  if ( *UnDecorator::gName == 64 )
    goto LABEL_6;
  if ( *UnDecorator::gName != 0 )
  {
    v5 = *((_DWORD *)result + 1);
    result->node = nullptr;
    if ( (v5 & 0xF) != 3 )
      *((_DWORD *)result + 1) = v5 & 0xFFFFFFF0 | 1;
  }
  else if ( DName::isEmpty(this: result) )
  {
    DName::operator=(this: v6, st: DN_truncated);
  }
  else
  {
    v7 = DName::DName(this: &v13, st: DN_truncated);
    v8 = DName::operator+(this: v7, result: &v12, str: "::");
    v9 = DName::operator+(this: v8, result: &v11, rd: result);
    DName::operator=(this: result, rd: v9);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004262C7
// Name: private: static class DName UnDecorator::getECSUDataType(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__cdecl UnDecorator::getECSUDataType(DName *result)
{
  BOOL v1; // ebx
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  DName *EnumType; // eax
  DName *v9; // eax
  DName v11; // [esp+8h] [ebp-18h] BYREF
  DName ecsuDataType; // [esp+10h] [ebp-10h] BYREF
  DName Prefix; // [esp+18h] [ebp-8h] BYREF

  v1 = true;
  if ( (UnDecorator::disableFlags & 0x8000) != 0 || (UnDecorator::disableFlags & 0x1000) != 0 )
    v1 = false;
  v2 = *UnDecorator::gName;
  Prefix.node = nullptr;
  *((_DWORD *)&Prefix + 1) &= 0xFFFFF000;
  ++UnDecorator::gName;
  if ( v2 != 0 )
  {
    v3 = v2 - 84;
    if ( v3 != 0 )
    {
      v4 = v3 - 1;
      if ( v4 != 0 )
      {
        v5 = v4 - 1;
        if ( v5 != 0 )
        {
          v6 = v5 - 1;
          if ( v6 != 0 )
          {
            v7 = v6 - 1;
            if ( v7 != 0 )
            {
              if ( v7 == 1 )
                DName::operator=(this: &Prefix, str: "cointerface ");
            }
            else
            {
              DName::operator=(this: &Prefix, str: "coclass ");
            }
          }
          else
          {
            v1 = (UnDecorator::disableFlags & 0x8000) == 0;
            EnumType = UnDecorator::getEnumType(result: &ecsuDataType);
            v9 = operator+(result: &v11, s: "enum ", rd: EnumType);
            DName::operator=(this: &Prefix, rd: v9);
          }
        }
        else
        {
          DName::operator=(this: &Prefix, str: "class ");
        }
      }
      else
      {
        DName::operator=(this: &Prefix, str: "struct ");
      }
    }
    else
    {
      DName::operator=(this: &Prefix, str: "union ");
    }
    ecsuDataType.node = nullptr;
    *((_DWORD *)&ecsuDataType + 1) &= 0xFFFFF000;
    if ( v1 )
      DName::operator=(this: &ecsuDataType, rd: &Prefix);
    UnDecorator::getScopedName(result: &Prefix);
    DName::operator+=(this: &ecsuDataType, rd: &Prefix);
    DName::DName(this: result, rd: &ecsuDataType);
  }
  else
  {
    --UnDecorator::gName;
    DName::DName(this: result, s: "nknown ecsu'");
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004263C7
// Name: private: static class DName UnDecorator::getSymbolName(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__cdecl UnDecorator::getSymbolName(DName *result)
{
  if ( *UnDecorator::gName == 63 )
  {
    if ( UnDecorator::gName[1] == 36 )
    {
      UnDecorator::getTemplateName(result, fReadTerminator: true);
    }
    else
    {
      ++UnDecorator::gName;
      UnDecorator::getOperatorName(result, fIsTemplate: false, pfReadTemplateArguments: nullptr);
    }
  }
  else
  {
    UnDecorator::getZName(result, fUpdateCachedNames: true);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042640D
// Name: private: static class DName UnDecorator::getBasedType(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__cdecl UnDecorator::getBasedType(DName *result)
{
  char *v1; // eax
  int v2; // ecx
  int v3; // ecx
  DName *ScopedName; // eax
  DName v6; // [esp+0h] [ebp-10h] BYREF
  DName basedDecl; // [esp+8h] [ebp-8h] BYREF

  v1 = (char *)UnDecorator::UScore(tok: TOK_basedLp);
  DName::DName(this: &basedDecl, s: v1);
  if ( *UnDecorator::gName == 0 )
  {
    DName::operator+=(this: &basedDecl, st: DN_truncated);
    goto LABEL_9;
  }
  v2 = *UnDecorator::gName++ - 48;
  if ( v2 == 0 )
  {
    DName::operator+=(this: &basedDecl, str: "void");
    goto LABEL_9;
  }
  v3 = v2 - 2;
  if ( v3 == 0 )
  {
    ScopedName = UnDecorator::getScopedName(result: &v6);
    DName::operator+=(this: &basedDecl, rd: ScopedName);
    goto LABEL_9;
  }
  if ( v3 != 3 )
  {
LABEL_9:
    DName::operator+=(this: &basedDecl, str: ") ");
    DName::DName(this: result, rd: &basedDecl);
    return result;
  }
  DName::DName(this: result, st: DN_invalid);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042649F
// Name: private: static class DName UnDecorator::composeDeclaration(class DName const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__cdecl UnDecorator::composeDeclaration(DName *result, DName *symbol)
{
  int TypeEncoding; // edi
  int v3; // eax
  int v4; // eax
  DName *BasedType; // eax
  const DName *v6; // eax
  DName *v7; // eax
  int v8; // eax
  DName *v9; // eax
  DName *v10; // eax
  DName *v11; // eax
  DName *v12; // eax
  DName *v13; // eax
  DName *v14; // eax
  DName *p_returnType; // eax
  int v16; // eax
  const DName *v17; // eax
  DName *v18; // eax
  DName *CallingConvention; // eax
  const DName *v20; // eax
  DName *v21; // eax
  DName *v22; // eax
  DName *v23; // ebx
  DName *v24; // eax
  DName *v25; // eax
  char *Memory; // eax
  const DName *v27; // eax
  int v28; // esi
  int v29; // eax
  DName *v30; // eax
  DName *v31; // eax
  DName *v32; // eax
  DName *v33; // eax
  DName *v34; // eax
  DName *v35; // eax
  DName *v36; // eax
  DName *ArgumentTypes; // eax
  DName *v38; // eax
  DName *v39; // eax
  DName *v40; // eax
  DName *ThrowTypes; // eax
  DName *v42; // eax
  DName *v43; // eax
  int v44; // eax
  int v45; // eax
  int v46; // eax
  int v47; // eax
  int v48; // eax
  int v49; // eax
  int v50; // eax
  int v51; // eax
  int v52; // eax
  int v53; // eax
  DName *v55; // eax
  int v56; // eax
  int v57; // eax
  int v58; // eax
  int v59; // eax
  int v60; // eax
  DName *v61; // eax
  int v62; // eax
  int v63; // eax
  DName *v64; // eax
  int v65; // eax
  int v66; // eax
  int v67; // eax
  int v68; // eax
  int v69; // eax
  int v70; // eax
  DName *v71; // eax
  DName *v72; // eax
  DName *v74; // [esp-Ch] [ebp-80h]
  DName v75; // [esp+8h] [ebp-6Ch] BYREF
  DName v76; // [esp+10h] [ebp-64h] BYREF
  DName v77; // [esp+18h] [ebp-5Ch] BYREF
  DName v78; // [esp+20h] [ebp-54h] BYREF
  DName returnType; // [esp+28h] [ebp-4Ch] BYREF
  DName adjustment; // [esp+30h] [ebp-44h] BYREF
  DName vbptrDisp; // [esp+38h] [ebp-3Ch] BYREF
  DName vbindex; // [esp+40h] [ebp-34h] BYREF
  DName thisType; // [esp+48h] [ebp-2Ch] BYREF
  DName declaration; // [esp+50h] [ebp-24h] BYREF
  DName v85; // [esp+58h] [ebp-1Ch] BYREF
  DName vtorDisp; // [esp+60h] [ebp-14h] BYREF
  DName v87; // [esp+68h] [ebp-Ch] BYREF
  bool fSigned[4]; // [esp+70h] [ebp-4h]

  declaration.node = nullptr;
  *((_DWORD *)&declaration + 1) &= 0xFFFFF000;
  TypeEncoding = UnDecorator::getTypeEncoding();
  *((_DWORD *)&v85 + 1) = DName::isUDC(this: symbol);
  if ( TypeEncoding != 0xFFFF )
  {
    if ( TypeEncoding == 65534 )
    {
      operator+(result, st: DN_truncated, rd: symbol);
      return result;
    }
    if ( TypeEncoding == 65533 )
    {
      DName::DName(this: result, rd: symbol);
      return result;
    }
    *(_DWORD *)fSigned = TypeEncoding & 0x8000;
    if ( (TypeEncoding & 0x8000) != 0 )
    {
      *((_DWORD *)&vtorDisp + 1) = TypeEncoding & 0x1800;
      *((_DWORD *)&v87 + 1) = *((_DWORD *)&vtorDisp + 1) == 2048;
      v3 = *((_DWORD *)&vtorDisp + 1) == 2048 ? TypeEncoding & 0x400 : TypeEncoding & 0x1000;
      if ( v3 == 0 || (TypeEncoding & 0x1B00) != 0x1000 )
      {
        v4 = *((_DWORD *)&v87 + 1) != 0 ? TypeEncoding & 0x400 : TypeEncoding & 0x1000;
        if ( v4 == 0 || (TypeEncoding & 0x1B00) != 0x1100 && (TypeEncoding & 0x1B00) != 0x1200 )
        {
          if ( (TypeEncoding & 0x4000) != 0 )
          {
            if ( (~(UnDecorator::disableFlags >> 1) & 1) != 0 && (~(UnDecorator::disableFlags >> 3) & 1) != 0 )
            {
              BasedType = UnDecorator::getBasedType(result: &returnType);
              v6 = operator+(result: &adjustment, c: 32, rd: BasedType);
              DName::operator=(this: &declaration, rd: v6);
            }
            else
            {
              v7 = UnDecorator::getBasedType(result: &returnType);
              DName::operator|=(this: &declaration, rd: v7);
            }
          }
          if ( *((_DWORD *)&v87 + 1) != 0 )
            v8 = TypeEncoding & 0x400;
          else
            v8 = TypeEncoding & 0x1000;
          if ( v8 != 0 && *((_DWORD *)&vtorDisp + 1) == 6144 )
          {
            UnDecorator::getDimension(result: &returnType, fSigned: false);
            v9 = DName::operator+(this: symbol, result: &vbptrDisp, ch: 123);
            v10 = DName::operator+(this: v9, result: &adjustment, rd: &returnType);
            DName::operator+=(this: &declaration, rd: v10);
            UnDecorator::getVCallThunkType(result: &returnType);
            if ( (UnDecorator::disableFlags & 0x1000) == 0 )
            {
              v11 = operator+(result: &vbptrDisp, c: 44, rd: &returnType);
              v12 = DName::operator+(this: v11, result: &adjustment, str: "}' ");
              DName::operator+=(this: &declaration, rd: v12);
            }
            DName::operator+=(this: &declaration, str: "}'");
            UnDecorator::getCallingConvention(result: &returnType);
            if ( (~(UnDecorator::disableFlags >> 1) & 1) != 0
              && (~(UnDecorator::disableFlags >> 4) & 1) != 0
              && (UnDecorator::disableFlags & 0x1000) == 0 )
            {
              v13 = operator+(result: &vbindex, c: 32, rd: &returnType);
              v14 = DName::operator+(this: v13, result: &vbptrDisp, ch: 32);
              p_returnType = DName::operator+(this: v14, result: &adjustment, rd: &declaration);
LABEL_134:
              DName::operator=(this: &declaration, rd: p_returnType);
              goto LABEL_135;
            }
            goto LABEL_135;
          }
          *((_DWORD *)&vbptrDisp + 1) &= 0xFFFFF000;
          *((_DWORD *)&vbindex + 1) &= 0xFFFFF000;
          *((_DWORD *)&vtorDisp + 1) &= 0xFFFFF000;
          *((_DWORD *)&adjustment + 1) &= 0xFFFFF000;
          *((_DWORD *)&thisType + 1) &= 0xFFFFF000;
          vbptrDisp.node = nullptr;
          vbindex.node = nullptr;
          vtorDisp.node = nullptr;
          adjustment.node = nullptr;
          thisType.node = nullptr;
          if ( *((_DWORD *)&v87 + 1) != 0 )
            v16 = TypeEncoding & 0x400;
          else
            v16 = TypeEncoding & 0x1000;
          if ( v16 == 0 )
          {
LABEL_45:
            if ( *((_DWORD *)&v87 + 1) != 0 && (TypeEncoding & 0x700) != 0x200 )
            {
              if ( (UnDecorator::disableFlags & 0x60) == 0x60 )
              {
                v18 = UnDecorator::getThisType(result: &returnType);
                DName::operator|=(this: &thisType, rd: v18);
              }
              else
              {
                v17 = UnDecorator::getThisType(result: &returnType);
                DName::operator=(this: &thisType, rd: v17);
              }
            }
            if ( (~(UnDecorator::disableFlags >> 1) & 1) != 0 && (~(UnDecorator::disableFlags >> 4) & 1) != 0 )
            {
              CallingConvention = UnDecorator::getCallingConvention(result: &v78);
              v20 = DName::operator+(this: CallingConvention, result: &returnType, rd: &declaration);
              DName::operator=(this: &declaration, rd: v20);
            }
            else
            {
              v21 = UnDecorator::getCallingConvention(result: &v78);
              DName::operator|=(this: &declaration, rd: v21);
            }
            if ( !DName::isEmpty(this: symbol) )
            {
              if ( DName::isEmpty(this: &declaration) || (UnDecorator::disableFlags & 0x1000) != 0 )
              {
                DName::operator=(this: &declaration, rd: symbol);
              }
              else
              {
                v22 = operator+(result: &v78, c: 32, rd: symbol);
                DName::operator+=(this: &declaration, rd: v22);
              }
            }
            *((_DWORD *)&returnType + 1) &= 0xFFFFF000;
            v23 = nullptr;
            returnType.node = nullptr;
            if ( *((_DWORD *)&v85 + 1) != 0 )
            {
              v24 = UnDecorator::getReturnType(result: &v78, pDeclarator: nullptr);
              v25 = operator+(result: &v85, s: " ", rd: v24);
              DName::operator+=(this: &declaration, rd: v25);
              if ( (UnDecorator::disableFlags & 0x1000) != 0 )
                goto LABEL_213;
            }
            else
            {
              Memory = HeapManager::getMemory(this: &heap, sz: 8u, noBuffer: 0);
              if ( Memory != nullptr )
              {
                *(_DWORD *)Memory = 0;
                *((_DWORD *)Memory + 1) &= 0xFFFFF000;
                v23 = (DName *)Memory;
              }
              else
              {
                v23 = nullptr;
              }
              v27 = UnDecorator::getReturnType(result: &v78, pDeclarator: v23);
              DName::operator=(this: &returnType, rd: v27);
            }
            v28 = *((_DWORD *)&v87 + 1);
            if ( *((_DWORD *)&v87 + 1) != 0 )
              v29 = TypeEncoding & 0x400;
            else
              v29 = TypeEncoding & 0x1000;
            if ( v29 == 0 )
            {
LABEL_78:
              ArgumentTypes = UnDecorator::getArgumentTypes(result: &v76);
              v38 = operator+(result: &v77, c: 40, rd: ArgumentTypes);
              v39 = DName::operator+(this: v38, result: &v75, ch: 41);
              DName::operator+=(this: &declaration, rd: v39);
              if ( v28 != 0 && (TypeEncoding & 0x700) != 0x200 )
                DName::operator+=(this: &declaration, rd: &thisType);
              if ( (UnDecorator::disableFlags & 0x100) != 0 )
              {
                ThrowTypes = UnDecorator::getThrowTypes(result: &v75);
                DName::operator|=(this: &declaration, rd: ThrowTypes);
              }
              else
              {
                v40 = UnDecorator::getThrowTypes(result: &v75);
                DName::operator+=(this: &declaration, rd: v40);
              }
              if ( (~(UnDecorator::disableFlags >> 2) & 1) != 0 && v23 != nullptr )
              {
                DName::operator=(this: v23, rd: &declaration);
                p_returnType = &returnType;
                goto LABEL_134;
              }
LABEL_135:
              if ( *(_DWORD *)fSigned != 0 )
                v52 = (TypeEncoding & 0x1800) - 2048;
              else
                v52 = TypeEncoding & 0x6000;
              if ( v52 != 0 )
                goto LABEL_202;
              if ( (~(UnDecorator::disableFlags >> 9) & 1) != 0 )
              {
                if ( *(_DWORD *)fSigned != 0 )
                  v53 = (TypeEncoding & 0x1800) - 2048;
                else
                  v53 = TypeEncoding & 0x6000;
                if ( v53 == 0 && (*(_DWORD *)fSigned == 0 || (TypeEncoding & 0x700) == 512) )
                {
                  v55 = operator+(result: &v75, s: "static ", rd: &declaration);
                  DName::operator=(this: &declaration, rd: v55);
                }
                if ( *(_DWORD *)fSigned != 0 )
                {
                  if ( (TypeEncoding & 0x700) == 0x100 )
                  {
LABEL_172:
                    v61 = operator+(result: &v75, s: "virtual ", rd: &declaration);
                    DName::operator=(this: &declaration, rd: v61);
                    goto LABEL_173;
                  }
                  v56 = (TypeEncoding & 0x1800) - 2048;
                }
                else
                {
                  v56 = TypeEncoding & 0x6000;
                }
                if ( v56 != 0 )
                  v57 = TypeEncoding & 0x1000;
                else
                  v57 = TypeEncoding & 0x400;
                if ( v57 != 0 )
                {
                  v58 = *(_DWORD *)fSigned != 0 ? (TypeEncoding & 0x1800) - 2048 : TypeEncoding & 0x6000;
                  if ( v58 == 0 && (TypeEncoding & 0x700) == 0x500 )
                    goto LABEL_172;
                  v59 = *(_DWORD *)fSigned != 0 ? (TypeEncoding & 0x1800) - 2048 : TypeEncoding & 0x6000;
                  if ( v59 == 0 && (TypeEncoding & 0x700) == 0x600 )
                    goto LABEL_172;
                  v60 = *(_DWORD *)fSigned != 0 ? (TypeEncoding & 0x1800) - 2048 : TypeEncoding & 0x6000;
                  if ( v60 == 0 && (TypeEncoding & 0x700) == 0x400 )
                    goto LABEL_172;
                }
              }
LABEL_173:
              if ( (~(UnDecorator::disableFlags >> 7) & 1) != 0 )
              {
                if ( *(_DWORD *)fSigned != 0 )
                  v62 = (TypeEncoding & 0x1800) - 2048;
                else
                  v62 = TypeEncoding & 0x6000;
                if ( v62 != 0
                  || (*(_DWORD *)fSigned == 0
                    ? (v63 = -((TypeEncoding & 0x1800) != 2048))
                    : (v63 = -((TypeEncoding & 0xC0) != 64)),
                      v63 == -1) )
                {
                  if ( *(_DWORD *)fSigned != 0 )
                    v65 = (TypeEncoding & 0x1800) - 2048;
                  else
                    v65 = TypeEncoding & 0x6000;
                  if ( v65 != 0
                    || (*(_DWORD *)fSigned == 0
                      ? (v66 = -((TypeEncoding & 0x1800) != 4096))
                      : (v66 = -((TypeEncoding & 0xC0) != 0x80)),
                        v66 == -1) )
                  {
                    if ( *(_DWORD *)fSigned != 0 )
                      v67 = (TypeEncoding & 0x1800) - 2048;
                    else
                      v67 = TypeEncoding & 0x6000;
                    if ( v67 != 0 )
                      goto LABEL_202;
                    v68 = *(_DWORD *)fSigned != 0 ? -((TypeEncoding & 0xC0) != 0) : -((TypeEncoding & 0x1800) != 0);
                    if ( v68 == -1 )
                      goto LABEL_202;
                    v64 = operator+(result: &v75, s: "public: ", rd: &declaration);
                  }
                  else
                  {
                    v64 = operator+(result: &v75, s: "protected: ", rd: &declaration);
                  }
                }
                else
                {
                  v64 = operator+(result: &v75, s: "private: ", rd: &declaration);
                }
                DName::operator=(this: &declaration, rd: v64);
              }
LABEL_202:
              if ( *(_DWORD *)fSigned != 0 )
                v69 = (TypeEncoding & 0x1800) - 2048;
              else
                v69 = TypeEncoding & 0x6000;
              if ( v69 != 0 )
                v70 = TypeEncoding & 0x1000;
              else
                v70 = TypeEncoding & 0x400;
              if ( v70 != 0 && (UnDecorator::disableFlags & 0x1000) == 0 )
              {
                v71 = operator+(result: &v75, s: "[thunk]:", rd: &declaration);
                DName::operator=(this: &declaration, rd: v71);
              }
              if ( (TypeEncoding & 0x10000) != 0 )
              {
                v72 = operator+(result: &v75, s: "extern \"C\" ", rd: &declaration);
                DName::operator=(this: &declaration, rd: v72);
              }
              goto LABEL_213;
            }
            if ( *((_DWORD *)&v87 + 1) != 0 )
            {
              if ( (TypeEncoding & 0x700) == 0x600 )
              {
                v74 = &v78;
                v30 = operator+(result: &v75, s: "`vtordispex{", rd: &vbptrDisp);
                v31 = DName::operator+(this: v30, result: &v76, ch: 44);
                v32 = DName::operator+(this: v31, result: &v77, rd: &vbindex);
                v33 = DName::operator+(this: v32, result: &v87, ch: 44);
                v34 = DName::operator+(this: v33, result: &v85, rd: &vtorDisp);
LABEL_75:
                v35 = DName::operator+(this: v34, result: v74, ch: 44);
                DName::operator+=(this: &declaration, rd: v35);
LABEL_77:
                v36 = DName::operator+(this: &adjustment, result: &v75, str: "}' ");
                DName::operator+=(this: &declaration, rd: v36);
                goto LABEL_78;
              }
              if ( (TypeEncoding & 0x700) == 0x500 )
              {
                v74 = &v75;
                v34 = operator+(result: &v76, s: "`vtordisp{", rd: &vtorDisp);
                goto LABEL_75;
              }
            }
            DName::operator+=(this: &declaration, str: "`adjustor{");
            goto LABEL_77;
          }
          if ( *((_DWORD *)&v87 + 1) != 0 )
          {
            if ( (TypeEncoding & 0x700) == 0x600 )
            {
              UnDecorator::getDimension(result: &returnType, fSigned: true);
              DName::operator=(this: &vbptrDisp, rd: &returnType);
              UnDecorator::getDimension(result: &returnType, fSigned: true);
              DName::operator=(this: &vbindex, rd: &returnType);
LABEL_43:
              UnDecorator::getDimension(result: &returnType, fSigned: true);
              DName::operator=(this: &vtorDisp, rd: &returnType);
              goto LABEL_44;
            }
            if ( (TypeEncoding & 0x700) == 0x500 )
              goto LABEL_43;
          }
LABEL_44:
          UnDecorator::getDimension(result: &returnType, fSigned: true);
          DName::operator=(this: &adjustment, rd: &returnType);
          goto LABEL_45;
        }
      }
    }
    DName::operator+=(this: &declaration, rd: symbol);
    if ( *(_DWORD *)fSigned != 0 )
    {
      v44 = (TypeEncoding & 0x1800) - 2048;
    }
    else
    {
      switch ( TypeEncoding & 0x7C00 )
      {
        case 26624:
        case 28672:
          UnDecorator::getVfTableType(result, superType: &declaration);
          return result;
        case 24576:
          UnDecorator::getDimension(result: &returnType, fSigned: fSigned[0]);
          v42 = DName::operator+(this: &declaration, result: &v76, ch: 123);
          v43 = DName::operator+(this: v42, result: &v75, rd: &returnType);
          DName::operator+(this: v43, result, str: "}'");
          return result;
        case 31744:
          UnDecorator::getVdispMapType(result, superType: &declaration);
          return result;
        default:
          break;
      }
      v44 = TypeEncoding & 0x6000;
    }
    if ( v44 != 0 )
      v45 = TypeEncoding & 0x1000;
    else
      v45 = TypeEncoding & 0x400;
    if ( v45 != 0 && *(_DWORD *)fSigned != 0 && (TypeEncoding & 0x1B00) == 4096 )
    {
      DName::operator+=(this: &declaration, str: "`local static destructor helper'");
    }
    else
    {
      if ( *(_DWORD *)fSigned != 0 )
        v46 = (TypeEncoding & 0x1800) - 2048;
      else
        v46 = TypeEncoding & 0x6000;
      if ( v46 != 0 )
        v47 = TypeEncoding & 0x1000;
      else
        v47 = TypeEncoding & 0x400;
      if ( v47 != 0 && *(_DWORD *)fSigned != 0 && (TypeEncoding & 0x1B00) == 4352 )
      {
        DName::operator+=(this: &declaration, str: "`template static data member constructor helper'");
      }
      else
      {
        if ( *(_DWORD *)fSigned != 0 )
          v48 = (TypeEncoding & 0x1800) - 2048;
        else
          v48 = TypeEncoding & 0x6000;
        if ( v48 != 0 )
          v49 = TypeEncoding & 0x1000;
        else
          v49 = TypeEncoding & 0x400;
        if ( v49 != 0 && *(_DWORD *)fSigned != 0 && (TypeEncoding & 0x1B00) == 4608 )
        {
          DName::operator+=(this: &declaration, str: "`template static data member destructor helper'");
        }
        else
        {
          if ( *(_DWORD *)fSigned != 0 )
            goto LABEL_124;
          if ( (TypeEncoding & 0x7C00) == 0x7800 )
          {
LABEL_213:
            DName::DName(this: result, rd: &declaration);
            return result;
          }
        }
      }
    }
    if ( *(_DWORD *)fSigned == 0 )
    {
      v50 = TypeEncoding & 0x6000;
      goto LABEL_126;
    }
LABEL_124:
    v50 = (TypeEncoding & 0x1800) - 2048;
LABEL_126:
    if ( v50 != 0 )
      v51 = TypeEncoding & 0x1000;
    else
      v51 = TypeEncoding & 0x400;
    if ( v51 != 0
      && (*(_DWORD *)fSigned != 0 && (TypeEncoding & 0x1B00) == 4352
       || *(_DWORD *)fSigned != 0 && (TypeEncoding & 0x1B00) == 4608) )
    {
      p_returnType = operator+(result: &v75, s: " ", rd: &declaration);
    }
    else
    {
      p_returnType = UnDecorator::getExternalDataType(result: &v75, superType: &declaration);
    }
    goto LABEL_134;
  }
  DName::DName(this: result, st: DN_invalid);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00426FE1
// Name: private: static class DName UnDecorator::getDecoratedName(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__cdecl UnDecorator::getDecoratedName(DName *result)
{
  DName *p_symbolName; // eax
  const char *v2; // eax
  const char *i; // eax
  BOOL v4; // edi
  BOOL v5; // esi
  DName *v6; // ecx
  const DName *v7; // eax
  const DName *v8; // eax
  DName *v9; // eax
  DName *v10; // eax
  const DName *v11; // eax
  int v12; // edx
  DName *v14; // [esp-8h] [ebp-30h]
  DName v15; // [esp+8h] [ebp-20h] BYREF
  DName v16; // [esp+10h] [ebp-18h] BYREF
  DName scope; // [esp+18h] [ebp-10h] BYREF
  DName symbolName; // [esp+20h] [ebp-8h] BYREF

  if ( (UnDecorator::disableFlags & 0x2000) == 0 )
  {
    if ( *UnDecorator::gName != 63 )
    {
      if ( *UnDecorator::gName == 0 )
      {
        DName::DName(this: result, st: DN_truncated);
        return result;
      }
      goto LABEL_35;
    }
    v2 = UnDecorator::gName + 1;
    UnDecorator::gName = v2;
    if ( *v2 == 63 && v2[1] == 63 )
    {
      UnDecorator::getDecoratedName(result: &scope);
      for ( i = UnDecorator::gName; *i != 0; UnDecorator::gName = i )
        ++i;
      goto LABEL_3;
    }
    UnDecorator::getSymbolName(result: &symbolName);
    v4 = !DName::isEmpty(this: &symbolName) && (*((_BYTE *)&symbolName + 4) & 0x20) != 0;
    v5 = (*((_WORD *)&symbolName + 2) & 0x800) != 0;
    if ( !DName::isValid(this: &symbolName) )
    {
LABEL_17:
      p_symbolName = &symbolName;
      goto LABEL_4;
    }
    if ( *UnDecorator::gName != 0 && *UnDecorator::gName != 64 )
    {
      UnDecorator::getScope(result: &scope);
      if ( !DName::isEmpty(this: &scope) )
      {
        if ( !UnDecorator::fExplicitTemplateParams )
        {
          v14 = &v15;
          v9 = &v16;
          goto LABEL_25;
        }
        UnDecorator::fExplicitTemplateParams = false;
        v7 = DName::operator+(this: &symbolName, result: &v16, rd: v6);
        DName::operator=(this: &symbolName, rd: v7);
        if ( *UnDecorator::gName != 64 )
        {
          v8 = UnDecorator::getScope(result: &v16);
          DName::operator=(this: &scope, rd: v8);
          v14 = &v16;
          v9 = &v15;
LABEL_25:
          v10 = DName::operator+(this: &scope, result: v9, str: "::");
          v11 = DName::operator+(this: v10, result: v14, rd: &symbolName);
          DName::operator=(this: &symbolName, rd: v11);
        }
      }
    }
    if ( v4 && !DName::isEmpty(this: &symbolName) )
      *((_DWORD *)&symbolName + 1) |= 0x20u;
    if ( v5 )
      *((_DWORD *)&symbolName + 1) |= 0x800u;
    if ( DName::isEmpty(this: &symbolName) || (*((_WORD *)&symbolName + 2) & 0x100) != 0 )
      goto LABEL_17;
    if ( *UnDecorator::gName != 0 )
    {
      if ( *UnDecorator::gName != 64 )
      {
LABEL_35:
        DName::DName(this: result, st: DN_invalid);
        return result;
      }
      ++UnDecorator::gName;
    }
    if ( (UnDecorator::disableFlags & 0x1000) == 0 || v4 || (v12 & *((_DWORD *)&symbolName + 1)) != 0 )
    {
      UnDecorator::composeDeclaration(result, symbol: &symbolName);
      return result;
    }
    scope.node = nullptr;
    *((_DWORD *)&scope + 1) &= 0xFFFFF000;
    UnDecorator::composeDeclaration(result: &v15, symbol: &scope);
    goto LABEL_17;
  }
  UnDecorator::disableFlags &= ~0x2000u;
  UnDecorator::getDataType(result: &scope, pDeclarator: nullptr);
  UnDecorator::disableFlags |= 0x2000u;
LABEL_3:
  p_symbolName = &scope;
LABEL_4:
  DName::DName(this: result, rd: p_symbolName);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004271F2
// Name: private: static class DName UnDecorator::getScope(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__cdecl UnDecorator::getScope(DName *result)
{
  int v2; // eax
  DName *v3; // eax
  const DName *v4; // eax
  const char *v5; // ecx
  DName *ZName; // eax
  DName *v7; // eax
  DName *v8; // eax
  const DName *v9; // eax
  DName *OperatorName; // eax
  const DName *v11; // eax
  DName *DecoratedName; // eax
  DName *v13; // eax
  DName *v14; // eax
  DName *v15; // eax
  const DName *v16; // eax
  int v17; // eax
  DName *v18; // ecx
  DName *v19; // eax
  DName *v20; // eax
  const DName *v21; // eax
  DName *v23; // [esp-8h] [ebp-38h]
  DName *v24; // [esp-4h] [ebp-34h]
  DName v25; // [esp+Ch] [ebp-24h] BYREF
  DName v26; // [esp+14h] [ebp-1Ch] BYREF
  char v27; // [esp+1Ch] [ebp-14h] BYREF
  DName v28; // [esp+24h] [ebp-Ch] BYREF
  DName v29; // [esp+2Ch] [ebp-4h] BYREF
  DName v30; // [esp+34h] [ebp+4h] BYREF
  char v31; // [esp+3Ch] [ebp+Ch] BYREF
  char v32; // [esp+44h] [ebp+14h] BYREF
  DName v33; // [esp+4Ch] [ebp+1Ch] BYREF
  DName v34; // [esp+54h] [ebp+24h] BYREF
  DName v35; // [esp+5Ch] [ebp+2Ch] BYREF
  DName v36; // [esp+64h] [ebp+34h] BYREF
  DName v37; // [esp+6Ch] [ebp+3Ch] BYREF
  DName v38; // [esp+74h] [ebp+44h] BYREF
  DName v39; // [esp+7Ch] [ebp+4Ch] BYREF
  DName v40; // [esp+84h] [ebp+54h] BYREF
  DName v41; // [esp+8Ch] [ebp+5Ch] BYREF
  DName v42; // [esp+94h] [ebp+64h] BYREF
  DName namespaceName; // [esp+9Ch] [ebp+6Ch] BYREF
  bool fNeedBracket; // [esp+AFh] [ebp+7Fh]

  *((_DWORD *)result + 1) &= 0xFFFFF000;
  v2 = *((_DWORD *)result + 1);
  result->node = nullptr;
  fNeedBracket = false;
  if ( (v2 & 0xF) == 0 )
  {
    while ( 1 )
    {
      if ( *UnDecorator::gName == 0 || *UnDecorator::gName == 64 )
        goto LABEL_29;
      if ( UnDecorator::fExplicitTemplateParams && !UnDecorator::fGetTemplateArgumentList )
        return result;
      if ( !DName::isEmpty(this: result) )
      {
        v3 = operator+(result: &v26, s: "::", rd: result);
        DName::operator=(this: result, rd: v3);
        if ( fNeedBracket )
        {
          v4 = operator+(result: &v29, c: 91, rd: result);
          DName::operator=(this: result, rd: v4);
          fNeedBracket = false;
        }
      }
      if ( *UnDecorator::gName != 63 )
        break;
      v5 = UnDecorator::gName + 1;
      UnDecorator::gName = v5;
      switch ( *v5 )
      {
        case '$':
          v24 = result;
          v23 = (DName *)&v31;
          UnDecorator::gName = v5 - 1;
          v15 = &v42;
LABEL_26:
          ZName = UnDecorator::getZName(result: v15, fUpdateCachedNames: true);
          goto LABEL_27;
        case '%':
          goto LABEL_22;
        case '?':
          if ( v5[1] == 95 && v5[2] == 63 )
          {
            UnDecorator::gName = v5 + 1;
            OperatorName = UnDecorator::getOperatorName(
                             result: &v39,
                             fIsTemplate: false,
                             pfReadTemplateArguments: nullptr);
            v11 = DName::operator+(this: OperatorName, result: &v34, rd: result);
            DName::operator=(this: result, rd: v11);
            if ( *UnDecorator::gName == 64 )
              ++UnDecorator::gName;
            goto LABEL_28;
          }
          v24 = result;
          v23 = (DName *)&v32;
          DecoratedName = UnDecorator::getDecoratedName(result: &v37);
          v13 = operator+(result: &v35, c: 96, rd: DecoratedName);
          ZName = DName::operator+(this: v13, result: &v38, ch: 39);
          goto LABEL_27;
        case 'A':
LABEL_22:
          DName::DName(this: &namespaceName, name: (char **)&UnDecorator::gName, terminator: 64);
          v14 = operator+(result: &v33, s: "`anonymous namespace'", rd: result);
          DName::operator=(this: result, rd: v14);
          if ( UnDecorator::pZNameList->index != 9 )
            Replicator::operator+=(this: UnDecorator::pZNameList, rd: &namespaceName);
          goto LABEL_28;
        default:
          break;
      }
      v24 = result;
      if ( *v5 != 73 )
      {
        v23 = (DName *)&v27;
        ZName = UnDecorator::getLexicalFrame(result: &v25);
LABEL_27:
        v16 = DName::operator+(this: ZName, result: v23, rd: v24);
        DName::operator=(this: result, rd: v16);
        goto LABEL_28;
      }
      UnDecorator::gName = v5 + 1;
      v7 = UnDecorator::getZName(result: &v30, fUpdateCachedNames: true);
      v8 = DName::operator+(this: v7, result: &v36, ch: 93);
      v9 = DName::operator+(this: v8, result: &v28, rd: result);
      DName::operator=(this: result, rd: v9);
      fNeedBracket = true;
LABEL_28:
      if ( (*((_BYTE *)result + 4) & 0xF) != 0 )
        goto LABEL_29;
    }
    v24 = result;
    v23 = &v40;
    v15 = &v41;
    goto LABEL_26;
  }
LABEL_29:
  if ( *UnDecorator::gName != 0 )
  {
    if ( *UnDecorator::gName != 64 )
    {
      v17 = *((_DWORD *)result + 1);
      result->node = nullptr;
      if ( (v17 & 0xF) != 3 )
        *((_DWORD *)result + 1) = v17 & 0xFFFFFFF0 | 1;
    }
  }
  else if ( DName::isEmpty(this: result) )
  {
    DName::operator=(this: v18, st: DN_truncated);
  }
  else
  {
    v19 = DName::DName(this: &v42, st: DN_truncated);
    v20 = DName::operator+(this: v19, result: &v40, str: "::");
    v21 = DName::operator+(this: v20, result: &v41, rd: result);
    DName::operator=(this: result, rd: v21);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042747D
// Name: private: static class DName UnDecorator::getFunctionIndirectType(class DName const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__cdecl UnDecorator::getFunctionIndirectType(DName *result, DName *superType)
{
  char v2; // cl
  int v3; // ebx
  const char *v4; // eax
  bool v5; // cc
  DName *v6; // eax
  DName *Scope; // eax
  DName *v8; // eax
  const DName *v9; // eax
  const DName *v10; // eax
  DName *BasedType; // eax
  DName *v12; // eax
  const DName *v13; // eax
  DName *v14; // eax
  DName *v15; // eax
  DName *CallingConvention; // eax
  const DName *v17; // eax
  DName *v18; // eax
  DName *v19; // eax
  const DName *v20; // eax
  char *Memory; // eax
  DName *v22; // esi
  DName *ArgumentTypes; // eax
  DName *v24; // eax
  DName *v25; // eax
  DName *v26; // eax
  DName *ThrowTypes; // eax
  DName v29; // [esp+0h] [ebp-30h] BYREF
  DName v30; // [esp+8h] [ebp-28h] BYREF
  DName v31; // [esp+10h] [ebp-20h] BYREF
  DName returnType; // [esp+18h] [ebp-18h] BYREF
  DName thisType; // [esp+20h] [ebp-10h] BYREF
  DName fitType; // [esp+28h] [ebp-8h] BYREF

  v2 = *UnDecorator::gName;
  if ( *UnDecorator::gName == 0 )
  {
    operator+(result, st: DN_truncated, rd: superType);
    return result;
  }
  if ( (v2 < 54 || v2 > 57) && v2 != 95 )
  {
    DName::DName(this: result, st: DN_invalid);
    return result;
  }
  v3 = v2 - 54;
  v4 = ++UnDecorator::gName;
  if ( v2 == 95 )
  {
    if ( *v4 == 0 )
    {
      operator+(result, st: DN_truncated, rd: superType);
      return result;
    }
    v3 = *v4 - 61;
    UnDecorator::gName = v4 + 1;
    if ( v3 >= 4 )
    {
      v5 = v3 <= 7;
      goto LABEL_14;
    }
  }
  else if ( v3 >= 0 )
  {
    v5 = v3 <= 3;
LABEL_14:
    if ( v5 )
      goto LABEL_16;
  }
  v3 = -1;
LABEL_16:
  if ( v3 == -1 )
  {
    DName::DName(this: result, st: DN_invalid);
  }
  else
  {
    thisType.node = nullptr;
    *((_DWORD *)&thisType + 1) &= 0xFFFFF000;
    DName::DName(this: &fitType, rd: superType);
    if ( (v3 & 2) != 0 )
    {
      v6 = operator+(result: &v31, s: "::", rd: &fitType);
      DName::operator=(this: &fitType, rd: v6);
      if ( *UnDecorator::gName != 0 )
      {
        Scope = UnDecorator::getScope(result: &v30);
        v8 = operator+(result: &v29, c: 32, rd: Scope);
        v9 = DName::operator+(this: v8, result: &v31, rd: &fitType);
      }
      else
      {
        v9 = operator+(result: &v29, st: DN_truncated, rd: &fitType);
      }
      DName::operator=(this: &fitType, rd: v9);
      if ( *UnDecorator::gName == 0 )
      {
        operator+(result, st: DN_truncated, rd: &fitType);
        return result;
      }
      if ( *UnDecorator::gName != 64 )
      {
        DName::DName(this: result, st: DN_invalid);
        return result;
      }
      ++UnDecorator::gName;
      if ( (UnDecorator::disableFlags & 0x60) == 0x60 )
      {
        v14 = UnDecorator::getThisType(result: &v29);
        DName::operator|=(this: &thisType, rd: v14);
      }
      else
      {
        v10 = UnDecorator::getThisType(result: &v29);
        DName::operator=(this: &thisType, rd: v10);
      }
    }
    if ( (v3 & 4) != 0 )
    {
      if ( (~(UnDecorator::disableFlags >> 1) & 1) != 0 )
      {
        BasedType = UnDecorator::getBasedType(result: &v30);
        v12 = operator+(result: &v31, c: 32, rd: BasedType);
        v13 = DName::operator+(this: v12, result: &v29, rd: &fitType);
        DName::operator=(this: &fitType, rd: v13);
      }
      else
      {
        v15 = UnDecorator::getBasedType(result: &v29);
        DName::operator|=(this: &fitType, rd: v15);
      }
    }
    if ( (~(UnDecorator::disableFlags >> 1) & 1) != 0 )
    {
      CallingConvention = UnDecorator::getCallingConvention(result: &v30);
      v17 = DName::operator+(this: CallingConvention, result: &v29, rd: &fitType);
      DName::operator=(this: &fitType, rd: v17);
    }
    else
    {
      v18 = UnDecorator::getCallingConvention(result: &v29);
      DName::operator|=(this: &fitType, rd: v18);
    }
    if ( !DName::isEmpty(this: superType) )
    {
      v19 = operator+(result: &v30, c: 40, rd: &fitType);
      v20 = DName::operator+(this: v19, result: &v29, ch: 41);
      DName::operator=(this: &fitType, rd: v20);
    }
    Memory = HeapManager::getMemory(this: &heap, sz: 8u, noBuffer: 0);
    if ( Memory != nullptr )
    {
      *(_DWORD *)Memory = 0;
      *((_DWORD *)Memory + 1) &= 0xFFFFF000;
      v22 = (DName *)Memory;
    }
    else
    {
      v22 = nullptr;
    }
    UnDecorator::getReturnType(result: &returnType, pDeclarator: v22);
    ArgumentTypes = UnDecorator::getArgumentTypes(result: &v30);
    v24 = operator+(result: &v31, c: 40, rd: ArgumentTypes);
    v25 = DName::operator+(this: v24, result: &v29, ch: 41);
    DName::operator+=(this: &fitType, rd: v25);
    if ( (UnDecorator::disableFlags & 0x60) != 0x60 && (v3 & 2) != 0 )
      DName::operator+=(this: &fitType, rd: &thisType);
    if ( (UnDecorator::disableFlags & 0x100) != 0 )
    {
      ThrowTypes = UnDecorator::getThrowTypes(result: &v29);
      DName::operator|=(this: &fitType, rd: ThrowTypes);
    }
    else
    {
      v26 = UnDecorator::getThrowTypes(result: &v29);
      DName::operator+=(this: &fitType, rd: v26);
    }
    if ( v22 != nullptr )
    {
      DName::operator=(this: v22, rd: &fitType);
      DName::DName(this: result, rd: &returnType);
    }
    else
    {
      DName::DName(this: result, st: DN_error);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004277BE
// Name: private: static class DName UnDecorator::getDataIndirectType(class DName const __near &,char,class DName const __near &,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__cdecl UnDecorator::getDataIndirectType(
        DName *result,
        DName *superType,
        char prType,
        DName *cvType,
        int thisFlag)
{
  char v5; // al
  DName *v6; // ecx
  DName *p_ditType; // eax
  char v8; // al
  bool v9; // cl
  unsigned int v10; // ebx
  DName *v11; // eax
  DName *v12; // eax
  DName *v13; // eax
  DName *p_name; // ecx
  DName *v15; // ecx
  DName *v16; // eax
  const char *v17; // eax
  DName *p_msExtension; // ecx
  const DName *v19; // eax
  DName *v20; // ecx
  DName *v21; // eax
  const DName *v22; // eax
  DName *v23; // ecx
  DName *v24; // eax
  const DName *v25; // eax
  DName *v26; // eax
  DName *Scope; // eax
  const DName *v28; // eax
  DName *v29; // eax
  char v30; // al
  DName *v31; // eax
  const DName *v32; // eax
  DName *BasedType; // eax
  DName *v34; // eax
  DName *v35; // eax
  int v36; // edx
  int v37; // ebx
  DName *v38; // ecx
  DName *v39; // eax
  DName *v40; // eax
  DName *v41; // eax
  DName *v42; // ecx
  int v43; // edx
  DName *v44; // ecx
  DName *v45; // eax
  DName *v46; // eax
  DName *v47; // ecx
  DName *v49; // [esp-8h] [ebp-68h]
  Tokens v50; // [esp-4h] [ebp-64h]
  char *v51; // [esp-4h] [ebp-64h]
  char *v52; // [esp-4h] [ebp-64h]
  DName *v53; // [esp-4h] [ebp-64h]
  DName *v54; // [esp-4h] [ebp-64h]
  DName *v55; // [esp-4h] [ebp-64h]
  DName *v56; // [esp-4h] [ebp-64h]
  DName v57; // [esp+Ch] [ebp-54h] BYREF
  DName v58; // [esp+14h] [ebp-4Ch] BYREF
  DName v59; // [esp+1Ch] [ebp-44h] BYREF
  DName v60; // [esp+24h] [ebp-3Ch] BYREF
  DName v61; // [esp+2Ch] [ebp-34h] BYREF
  DName v62; // [esp+34h] [ebp-2Ch] BYREF
  DName szComPlusIndirSpecifier; // [esp+3Ch] [ebp-24h] BYREF
  DName name; // [esp+44h] [ebp-1Ch] BYREF
  DName msExtension; // [esp+4Ch] [ebp-14h] BYREF
  DName ditType; // [esp+54h] [ebp-Ch] BYREF
  bool bIsPinPtr; // [esp+5Fh] [ebp-1h] BYREF

  v5 = *UnDecorator::gName;
  *((_DWORD *)&szComPlusIndirSpecifier + 1) &= 0xFFFFF000;
  szComPlusIndirSpecifier.node = nullptr;
  bIsPinPtr = false;
  if ( v5 == 0 )
  {
    if ( thisFlag == 0 )
    {
      if ( !DName::isEmpty(this: superType) )
      {
        if ( (*(_BYTE *)(v43 + 4) & 0x10) != 0 || DName::isEmpty(this: cvType) )
        {
          operator+(result, st: DN_truncated, rd: (DName *)v43);
        }
        else
        {
          v56 = (DName *)v43;
          v45 = operator+(result: &v58, st: DN_truncated, rd: v44);
          v46 = DName::operator+(this: v45, result: &v57, ch: 32);
          DName::operator+(this: v46, result, rd: v56);
        }
        return result;
      }
      if ( !DName::isEmpty(this: cvType) )
      {
        operator+(result, st: DN_truncated, rd: v47);
        return result;
      }
    }
    DName::DName(this: result, st: DN_truncated);
    return result;
  }
  if ( v5 == 36 )
  {
    UnDecorator::getExtendedDataIndirectType(result: &name, &prType, fIsPinPtr: &bIsPinPtr, thisFlag);
    if ( !DName::isEmpty(this: &name) )
    {
      p_ditType = v6;
      goto LABEL_5;
    }
  }
  v8 = *UnDecorator::gName;
  v9 = *UnDecorator::gName < 65;
  *((_DWORD *)&msExtension + 1) &= 0xFFFFF000;
  msExtension.node = nullptr;
  v10 = v8 - (v9 ? 22 : 65);
  *((_DWORD *)&name + 1) &= 0xFFFFF000;
  name.node = nullptr;
  while ( v10 == 4 )
  {
    if ( (~(UnDecorator::disableFlags >> 1) & 1) != 0 && (~(UnDecorator::disableFlags >> 17) & 1) != 0 )
    {
      v50 = TOK_ptr64;
      if ( DName::isEmpty(this: &msExtension) )
      {
LABEL_23:
        v17 = UnDecorator::UScore(tok: v50);
        p_msExtension = &msExtension;
        goto LABEL_24;
      }
      v51 = (char *)UnDecorator::UScore(tok: TOK_ptr64);
      v49 = &v58;
      v11 = &v57;
LABEL_13:
      v12 = DName::operator+(this: &msExtension, result: v11, ch: 32);
      v13 = DName::operator+(this: v12, result: v49, str: v51);
      p_name = &msExtension;
LABEL_14:
      DName::operator=(this: p_name, rd: v13);
    }
LABEL_25:
    if ( *++UnDecorator::gName == 36 )
    {
      UnDecorator::getExtendedDataIndirectType(result: &ditType, &prType, fIsPinPtr: &bIsPinPtr, thisFlag);
      if ( !DName::isEmpty(this: &ditType) )
        goto LABEL_69;
    }
    v10 = *UnDecorator::gName - (*UnDecorator::gName < 65 ? 22 : 65);
  }
  if ( v10 == 5 )
  {
    if ( (~(UnDecorator::disableFlags >> 1) & 1) == 0 )
      goto LABEL_25;
    if ( DName::isEmpty(this: &name) )
    {
      v17 = UnDecorator::UScore(tok: TOK_unaligned);
      p_msExtension = &name;
LABEL_24:
      DName::operator=(this: p_msExtension, str: v17);
      goto LABEL_25;
    }
    v52 = (char *)UnDecorator::UScore(tok: TOK_unaligned);
    v16 = DName::operator+(this: v15, result: &v59, ch: 32);
    v13 = DName::operator+(this: v16, result: &v60, str: v52);
    p_name = &name;
    goto LABEL_14;
  }
  if ( v10 == 8 )
  {
    if ( (~(UnDecorator::disableFlags >> 1) & 1) != 0 )
    {
      v50 = TOK_restrict;
      if ( DName::isEmpty(this: &msExtension) )
        goto LABEL_23;
      v51 = (char *)UnDecorator::UScore(tok: TOK_restrict);
      v49 = &v62;
      v11 = &v61;
      goto LABEL_13;
    }
    goto LABEL_25;
  }
  ++UnDecorator::gName;
  if ( v10 > 0x1F )
  {
LABEL_35:
    DName::DName(this: result, st: DN_invalid);
    return result;
  }
  DName::DName(this: &ditType, c: prType);
  v19 = DName::operator+(this: &szComPlusIndirSpecifier, result: &v57, rd: &ditType);
  DName::operator=(this: &ditType, rd: v19);
  if ( !DName::isEmpty(this: &msExtension) )
  {
    v53 = v20;
    v21 = DName::operator+(this: &ditType, result: &v58, ch: 32);
    v22 = DName::operator+(this: v21, result: &v57, rd: v53);
    DName::operator=(this: &ditType, rd: v22);
  }
  if ( !DName::isEmpty(this: &name) )
  {
    v24 = DName::operator+(this: v23, result: &v58, ch: 32);
    v25 = DName::operator+(this: v24, result: &v57, rd: &ditType);
    DName::operator=(this: &ditType, rd: v25);
  }
  if ( (v10 & 0x10) != 0 )
  {
    if ( thisFlag != 0 )
      goto LABEL_35;
    if ( prType != 0 )
    {
      v26 = operator+(result: &v57, s: "::", rd: &ditType);
      DName::operator=(this: &ditType, rd: v26);
      if ( *UnDecorator::gName != 0 )
      {
        Scope = UnDecorator::getScope(result: &v58);
        v28 = DName::operator+(this: Scope, result: &v57, rd: &ditType);
      }
      else
      {
        v28 = operator+(result: &v57, st: DN_truncated, rd: &ditType);
      }
      DName::operator=(this: &ditType, rd: v28);
LABEL_43:
      v30 = *UnDecorator::gName;
      if ( *UnDecorator::gName == 0 )
        goto LABEL_44;
      ++UnDecorator::gName;
      if ( v30 != 64 )
        goto LABEL_35;
    }
    else
    {
      if ( *UnDecorator::gName != 0 )
      {
        v29 = UnDecorator::getScope(result: &v57);
        DName::operator|=(this: &ditType, rd: v29);
        goto LABEL_43;
      }
LABEL_44:
      DName::operator+=(this: &ditType, st: DN_truncated);
    }
  }
  if ( (UnDecorator::disableFlags & 2) != 0 )
  {
    if ( (v10 & 0xC) == 0xC )
    {
      BasedType = UnDecorator::getBasedType(result: &v57);
      DName::operator|=(this: &ditType, rd: BasedType);
    }
  }
  else if ( (v10 & 0xC) == 0xC )
  {
    if ( thisFlag != 0 )
      goto LABEL_35;
    v31 = UnDecorator::getBasedType(result: &v58);
    v32 = DName::operator+(this: v31, result: &v57, rd: &ditType);
    DName::operator=(this: &ditType, rd: v32);
  }
  if ( (v10 & 2) != 0 )
  {
    v34 = operator+(result: &v57, s: "volatile ", rd: &ditType);
    DName::operator=(this: &ditType, rd: v34);
  }
  if ( (v10 & 1) != 0 )
  {
    v35 = operator+(result: &v57, s: "const ", rd: &ditType);
    DName::operator=(this: &ditType, rd: v35);
  }
  if ( thisFlag == 0 )
  {
    if ( DName::isEmpty(this: superType) )
    {
      if ( !DName::isEmpty(this: cvType) )
      {
        v55 = v42;
        goto LABEL_65;
      }
    }
    else
    {
      v37 = *(_DWORD *)(v36 + 4);
      if ( (v37 & 0x10) == 0 && !DName::isEmpty(this: cvType) )
      {
        v54 = (DName *)v36;
        v39 = operator+(result: &v59, c: 32, rd: v38);
        v40 = DName::operator+(this: v39, result: &v58, ch: 32);
        v41 = DName::operator+(this: v40, result: &v57, rd: v54);
        goto LABEL_66;
      }
      v55 = (DName *)v36;
      if ( (v37 & 0x80u) != 0 )
      {
        DName::operator=(this: &ditType, rd: (const DName *)v36);
        goto LABEL_67;
      }
LABEL_65:
      v41 = operator+(result: &v57, c: 32, rd: v55);
LABEL_66:
      DName::operator+=(this: &ditType, rd: v41);
    }
  }
LABEL_67:
  *((_DWORD *)&ditType + 1) |= 0x10u;
  if ( bIsPinPtr )
    *((_DWORD *)&ditType + 1) |= 0x200u;
LABEL_69:
  p_ditType = &ditType;
LABEL_5:
  DName::DName(this: result, rd: p_ditType);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00427CA2
// Name: public: UnDecorator::operator char __near *(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__thiscall UnDecorator::operator char *(UnDecorator *this)
{
  char v1; // al
  DName *DecoratedName; // eax
  DName *v3; // eax
  const DName *TemplateName; // eax
  int v5; // eax
  char *result; // eax
  int v7; // eax
  char *v8; // eax
  char *v9; // edx
  char v10; // cl
  DName v11; // [esp+0h] [ebp-20h] BYREF
  DName v12; // [esp+8h] [ebp-18h] BYREF
  DName unDName; // [esp+10h] [ebp-10h] BYREF
  DName v14; // [esp+18h] [ebp-8h] BYREF

  v14.node = nullptr;
  unDName.node = nullptr;
  *((_DWORD *)&v14 + 1) &= 0xFFFFF000;
  *((_DWORD *)&unDName + 1) &= 0xFFFFF000;
  if ( UnDecorator::name != nullptr )
  {
    if ( *UnDecorator::name == 63 )
    {
      v1 = UnDecorator::name[1];
      if ( v1 == 64 )
      {
        UnDecorator::gName += 2;
        DecoratedName = UnDecorator::getDecoratedName(result: &v12);
        v3 = operator+(result: &v11, s: "CV: ", rd: DecoratedName);
LABEL_9:
        DName::operator=(this: &v14, rd: v3);
        goto LABEL_10;
      }
      if ( v1 == 36 )
      {
        TemplateName = UnDecorator::getTemplateName(result: &v11, fReadTerminator: false);
        DName::operator=(this: &v14, rd: TemplateName);
        if ( (*((_BYTE *)&v14 + 4) & 0xF) != 1 )
          goto LABEL_10;
        *((_DWORD *)&v14 + 1) &= 0xFFFFFFF0;
        UnDecorator::gName = UnDecorator::name;
      }
    }
    v3 = UnDecorator::getDecoratedName(result: &v11);
    goto LABEL_9;
  }
LABEL_10:
  v5 = (int)(*((_DWORD *)&v14 + 1) << 28) >> 28;
  if ( v5 == 3 )
    return nullptr;
  if ( v5 == 1 || (UnDecorator::disableFlags & 0x1000) == 0 && *UnDecorator::gName != 0 )
    DName::operator=(this: &unDName, str: UnDecorator::name);
  else
    DName::operator=(this: &unDName, rd: &v14);
  result = UnDecorator::outputString;
  if ( UnDecorator::outputString != nullptr
    || (v7 = DName::length(this: &unDName),
        UnDecorator::maxStringLength = v7 + 1,
        result = (char *)heap.pOpNew(a1: (v7 + 8) & 0xFFFFFFF8),
        UnDecorator::outputString = result,
        result != nullptr) )
  {
    DName::getString(this: &unDName, buf: result, max: (char *)UnDecorator::maxStringLength);
    v8 = UnDecorator::outputString;
    v9 = UnDecorator::outputString;
    while ( 1 )
    {
      v10 = *v8;
      if ( *v8 == 0 )
        break;
      if ( v10 == 32 )
      {
        ++v8;
        *v9++ = 32;
        while ( *v8 == 32 )
          ++v8;
      }
      else
      {
        *v9++ = v10;
        ++v8;
      }
    }
    *v9 = 0;
    return UnDecorator::outputString;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00427DEE
// Name: private: static class DName UnDecorator::getPtrRefType(class DName const __near &,class DName const __near &,char)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__cdecl UnDecorator::getPtrRefType(DName *result, DName *cvType, DName *superType, char ptrChar)
{
  char v4; // al
  DName *v5; // ecx
  DName trunk; // [esp+0h] [ebp-8h] BYREF

  v4 = *UnDecorator::gName;
  if ( *UnDecorator::gName != 0 )
  {
    if ( v4 >= 54 && v4 <= 57 || v4 == 95 )
    {
      DName::DName(this: &trunk, c: ptrChar);
      if ( !DName::isEmpty(this: cvType) && (DName::isEmpty(this: superType) || (*((_BYTE *)superType + 4) & 0x10) == 0) )
        DName::operator+=(this: &trunk, rd: cvType);
      if ( !DName::isEmpty(this: superType) )
        DName::operator+=(this: &trunk, rd: superType);
      UnDecorator::getFunctionIndirectType(result, superType: &trunk);
    }
    else
    {
      UnDecorator::getDataIndirectType(result: &trunk, superType, prType: ptrChar, cvType, thisFlag: 0);
      UnDecorator::getPtrRefDataType(result, superType: &trunk, isPtr: ptrChar == 42);
    }
  }
  else
  {
    DName::DName(this: &trunk, st: DN_truncated);
    DName::operator+=(this: &trunk, ch: ptrChar);
    if ( !DName::isEmpty(this: cvType) )
      DName::operator+=(this: &trunk, rd: v5);
    if ( !DName::isEmpty(this: superType) )
    {
      if ( !DName::isEmpty(this: cvType) )
        DName::operator+=(this: &trunk, ch: 32);
      DName::operator+=(this: &trunk, rd: superType);
    }
    DName::DName(this: result, rd: &trunk);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00427F04
// Name: ___unDName
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl __unDName(
        char *outputString,
        const char *name,
        int maxStringLength,
        void *(__cdecl *pAlloc)(unsigned int),
        void (__cdecl *pFree)(void *),
        unsigned __int16 disableFlags)
{
  UnDecorator unDecorate; // [esp+10h] [ebp-94h] BYREF
  char *unDecoratedName; // [esp+88h] [ebp-1Ch]
  CPPEH_RECORD ms_exc; // [esp+8Ch] [ebp-18h]

  if ( pAlloc == nullptr || _mtinitlocknum(locknum: 5) == 0 )
    return nullptr;
  _lock(locknum: 5);
  ms_exc.registration.TryLevel = 0;
  heap.pOpNew = pAlloc;
  heap.pOpDelete = pFree;
  heap.blockLeft = 0;
  heap.head = nullptr;
  heap.tail = nullptr;
  UnDecorator::UnDecorator(
    this: &unDecorate,
    output: outputString,
    dName: name,
    maxLen: maxStringLength,
    pGetParameter: nullptr,
    disable: disableFlags);
  unDecoratedName = UnDecorator::operator char *(this: &unDecorate);
  HeapManager::Destructor(this: &heap);
  ms_exc.registration.TryLevel = -2;
  _unlock(locknum: 5);
  return unDecoratedName;
}

//------------------------------------------------------------------------------
// Address: 0x00427FA7
// Name: private: static class DName UnDecorator::getBasicDataType(class DName const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__cdecl UnDecorator::getBasicDataType(DName *result, DName *superType)
{
  unsigned __int8 v2; // al
  int v3; // edi
  int v4; // ebx
  unsigned __int8 v5; // al
  DName *BasicDataType; // eax
  DName *p_superName; // eax
  const DName *ECSUDataType; // eax
  DName *p_cvType; // eax
  DName *v10; // eax
  DName *v11; // ecx
  DName *v12; // eax
  DName v14; // [esp+Ch] [ebp-24h] BYREF
  DName arType; // [esp+14h] [ebp-1Ch] BYREF
  DName superName; // [esp+1Ch] [ebp-14h] BYREF
  DName cvType; // [esp+24h] [ebp-Ch] BYREF
  unsigned __int8 extended_bdtCode; // [esp+2Fh] [ebp-1h]

  v2 = *UnDecorator::gName;
  if ( *UnDecorator::gName == 0 )
  {
    operator+(result, st: DN_truncated, rd: superType);
    return result;
  }
  ++UnDecorator::gName;
  cvType.node = nullptr;
  v3 = v2;
  *((_DWORD *)&cvType + 1) &= 0xFFFFF000;
  v4 = -1;
  if ( v2 <= 0x4Eu )
  {
    if ( v2 != 78 )
    {
      switch ( v2 )
      {
        case 'C':
        case 'D':
        case 'E':
          DName::operator=(this: &cvType, str: "char");
          goto LABEL_53;
        case 'F':
        case 'G':
          DName::operator=(this: &cvType, str: "short");
          goto LABEL_53;
        case 'H':
        case 'I':
          DName::operator=(this: &cvType, str: "int");
          goto LABEL_53;
        case 'J':
        case 'K':
          DName::operator=(this: &cvType, str: "long");
          goto LABEL_53;
        case 'M':
          DName::operator=(this: &cvType, str: "float");
          goto LABEL_53;
        default:
          goto LABEL_49;
      }
    }
    goto LABEL_51;
  }
  if ( v2 == 79 )
  {
    DName::operator=(this: &cvType, str: "long ");
LABEL_51:
    DName::operator+=(this: &cvType, str: "double");
LABEL_52:
    if ( v4 == -1 )
      goto LABEL_53;
    goto LABEL_41;
  }
  if ( v2 <= 0x4Fu )
    goto LABEL_49;
  if ( v2 <= 0x53u )
  {
    v4 = v2 & 3;
    goto LABEL_52;
  }
  if ( v2 == 88 )
  {
    DName::operator=(this: &cvType, str: "void");
    goto LABEL_53;
  }
  if ( v2 != 95 )
  {
LABEL_49:
    p_superName = &v14;
LABEL_35:
    --UnDecorator::gName;
    ECSUDataType = UnDecorator::getECSUDataType(result: p_superName);
    DName::operator=(this: &cvType, rd: ECSUDataType);
    if ( DName::isEmpty(this: &cvType) )
    {
LABEL_36:
      p_cvType = &cvType;
LABEL_37:
      DName::DName(this: result, rd: p_cvType);
      return result;
    }
LABEL_53:
    if ( v3 == 67 )
    {
      v10 = operator+(result: &superName, s: "signed ", rd: &cvType);
    }
    else if ( v3 == 69 || v3 == 71 || v3 == 73 || v3 == 75 )
    {
      v10 = operator+(result: &arType, s: "unsigned ", rd: &cvType);
    }
    else
    {
      if ( v3 != 95
        || extended_bdtCode != 69
        && extended_bdtCode != 71
        && extended_bdtCode != 73
        && extended_bdtCode != 75
        && extended_bdtCode != 77 )
      {
LABEL_68:
        if ( !DName::isEmpty(this: superType) )
        {
          v12 = operator+(result: &v14, c: 32, rd: v11);
          DName::operator+=(this: &cvType, rd: v12);
        }
        goto LABEL_36;
      }
      v10 = operator+(result: &v14, s: "unsigned ", rd: &cvType);
    }
    DName::operator=(this: &cvType, rd: v10);
    goto LABEL_68;
  }
  v5 = *UnDecorator::gName++;
  extended_bdtCode = v5;
  if ( v5 <= 0x4Du )
  {
    if ( v5 >= 0x4Cu )
    {
      DName::operator=(this: &cvType, str: "__int128");
      goto LABEL_53;
    }
    if ( v5 > 0x47u )
    {
      if ( v5 >= 0x48u )
      {
        if ( v5 <= 0x49u )
        {
          DName::operator=(this: &cvType, str: "__int32");
          goto LABEL_53;
        }
        if ( v5 <= 0x4Bu )
        {
          DName::operator=(this: &cvType, str: "__int64");
          goto LABEL_53;
        }
      }
    }
    else
    {
      if ( v5 >= 0x46u )
      {
        DName::operator=(this: &cvType, str: "__int16");
        goto LABEL_53;
      }
      if ( v5 == 36 )
      {
        BasicDataType = UnDecorator::getBasicDataType(result: &arType, superType);
        operator+(result, s: "__w64 ", rd: BasicDataType);
        return result;
      }
      if ( (unsigned int)v5 - 68 <= 1 )
      {
        DName::operator=(this: &cvType, str: "__int8");
        goto LABEL_53;
      }
    }
LABEL_38:
    DName::operator=(this: &cvType, str: "UNKNOWN");
    goto LABEL_53;
  }
  if ( v5 == 78 )
  {
    DName::operator=(this: &cvType, str: "bool");
    goto LABEL_53;
  }
  if ( v5 != 79 )
  {
    if ( v5 == 87 )
    {
      DName::operator=(this: &cvType, str: "wchar_t");
      goto LABEL_53;
    }
    if ( (unsigned int)v5 - 88 > 1 )
      goto LABEL_38;
    p_superName = &superName;
    goto LABEL_35;
  }
  v4 = -2;
LABEL_41:
  cvType.node = nullptr;
  *((_DWORD *)&cvType + 1) &= 0xFFFFF000;
  DName::DName(this: &superName, rd: superType);
  if ( v4 == -2 )
  {
    *((_DWORD *)&superName + 1) |= 0x80u;
    UnDecorator::getPtrRefType(result: &arType, &cvType, superType: &superName, ptrChar: 0);
    if ( *((char *)&arType + 4) >= 0 )
      DName::operator+=(this: &arType, str: "[]");
    p_cvType = &arType;
    goto LABEL_37;
  }
  if ( DName::isEmpty(this: superType) )
  {
    if ( (v4 & 1) != 0 )
    {
      DName::operator=(this: &cvType, str: "const");
      if ( (v4 & 2) != 0 )
        DName::operator+=(this: &cvType, str: " volatile");
    }
    else if ( (v4 & 2) != 0 )
    {
      DName::operator=(this: &cvType, str: "volatile");
    }
  }
  UnDecorator::getPtrRefType(result, &cvType, superType: &superName, ptrChar: 42);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042832E
// Name: private: static class DName UnDecorator::getPrimaryDataType(class DName const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__cdecl UnDecorator::getPrimaryDataType(DName *result, DName *superType)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  char v5; // al
  const char *v6; // esi
  DName *DataIndirectType; // eax
  DName v9; // [esp+4h] [ebp-18h] BYREF
  DName superName; // [esp+Ch] [ebp-10h] BYREF
  DName cvType; // [esp+14h] [ebp-8h] BYREF

  v2 = *UnDecorator::gName;
  *((_DWORD *)&cvType + 1) &= 0xFFFFF000;
  cvType.node = nullptr;
  if ( v2 == 0 )
    goto LABEL_19;
  v3 = v2 - 36;
  if ( v3 == 0 )
  {
    v5 = UnDecorator::gName[1];
    if ( v5 == 36 )
    {
      v6 = UnDecorator::gName + 2;
      UnDecorator::gName = v6;
      if ( *v6 != 0 )
      {
        switch ( *v6 )
        {
          case 'A':
            UnDecorator::gName = v6 + 1;
            UnDecorator::getFunctionIndirectType(result, superType);
            return result;
          case 'B':
            UnDecorator::gName = v6 + 1;
            UnDecorator::getPtrRefDataType(result, superType, isPtr: 1);
            return result;
          case 'C':
            *((_DWORD *)&superName + 1) &= 0xFFFFF000;
            UnDecorator::gName = v6 + 1;
            superName.node = nullptr;
            DataIndirectType = UnDecorator::getDataIndirectType(
                                 result: &v9,
                                 superType,
                                 prType: 0,
                                 cvType: &superName,
                                 thisFlag: 0);
            UnDecorator::getBasicDataType(result, superType: DataIndirectType);
            return result;
          default:
            break;
        }
        goto LABEL_11;
      }
    }
    else if ( v5 != 0 )
    {
LABEL_11:
      DName::DName(this: result, st: DN_invalid);
      return result;
    }
LABEL_19:
    operator+(result, st: DN_truncated, rd: superType);
    return result;
  }
  v4 = v3 - 29;
  if ( v4 == 0 )
  {
LABEL_8:
    DName::DName(this: &superName, rd: superType);
    ++UnDecorator::gName;
    *((_DWORD *)&superName + 1) |= 0x10u;
    UnDecorator::getPtrRefType(result, &cvType, superType: &superName, ptrChar: 38);
    return result;
  }
  if ( v4 == 1 )
  {
    DName::operator=(this: &cvType, str: "volatile");
    if ( !DName::isEmpty(this: superType) )
      DName::operator+=(this: &cvType, ch: 32);
    goto LABEL_8;
  }
  UnDecorator::getBasicDataType(result, superType);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042846C
// Name: private: static class DName UnDecorator::getDataType(class DName __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__cdecl UnDecorator::getDataType(DName *result, DName *pDeclarator)
{
  char v2; // al
  const DName *DataIndirectType; // eax
  DName v5; // [esp+0h] [ebp-18h] BYREF
  DName cvType; // [esp+8h] [ebp-10h] BYREF
  DName superType; // [esp+10h] [ebp-8h] BYREF

  DName::DName(this: &superType, pd: pDeclarator);
  v2 = *UnDecorator::gName;
  if ( *UnDecorator::gName == 0 )
  {
    operator+(result, st: DN_truncated, rd: &superType);
    return result;
  }
  if ( v2 == 63 )
  {
    ++UnDecorator::gName;
    *((_DWORD *)&cvType + 1) &= 0xFFFFF000;
    cvType.node = nullptr;
    DataIndirectType = UnDecorator::getDataIndirectType(result: &v5, &superType, prType: 0, &cvType, thisFlag: 0);
    DName::operator=(this: &superType, rd: DataIndirectType);
  }
  else if ( v2 == 88 )
  {
    ++UnDecorator::gName;
    if ( DName::isEmpty(this: &superType) )
      DName::DName(this: result, s: "void");
    else
      operator+(result, s: "void ", rd: &superType);
    return result;
  }
  UnDecorator::getPrimaryDataType(result, &superType);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042851D
// Name: private: static class DName UnDecorator::getExternalDataType(class DName const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__cdecl UnDecorator::getExternalDataType(DName *result, DName *superType)
{
  DName *v2; // esi
  char *Memory; // eax
  DName *v4; // eax
  const DName *v5; // eax
  DName v7; // [esp+4h] [ebp-18h] BYREF
  DName v8; // [esp+Ch] [ebp-10h] BYREF
  DName v9; // [esp+14h] [ebp-8h] BYREF

  v2 = nullptr;
  Memory = HeapManager::getMemory(this: &heap, sz: 8u, noBuffer: 0);
  if ( Memory != nullptr )
  {
    *((_DWORD *)Memory + 1) &= 0xFFFFF000;
    *(_DWORD *)Memory = 0;
    v2 = (DName *)Memory;
  }
  UnDecorator::getDataType(result, pDeclarator: v2);
  UnDecorator::getDataIndirectType(result: &v9);
  v4 = DName::operator+(this: &v9, result: &v7, ch: 32);
  v5 = DName::operator+(this: v4, result: &v8, rd: superType);
  DName::operator=(this: v2, rd: v5);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00428581
// Name: __initp_misc_winsig
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_misc_winsig(void (__cdecl *enull)(int))
{
  ctrlc_action = enull;
  ctrlbreak_action = enull;
  abort_action = enull;
  term_action = enull;
}

//------------------------------------------------------------------------------
// Address: 0x0042859A
// Name: siglookup
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_XCPT_ACTION *__usercall siglookup@<eax>(int signum@<edx>, _XCPT_ACTION *pxcptacttab)
{
  _XCPT_ACTION *result; // eax

  result = pxcptacttab;
  do
  {
    if ( result->SigNum == signum )
      break;
    ++result;
  }
  while ( result < &pxcptacttab[_XcptActTabCount] );
  if ( result >= &pxcptacttab[_XcptActTabCount] || result->SigNum != signum )
    return nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004285CE
// Name: ___get_sigabrt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void (__cdecl *__cdecl __get_sigabrt())(int)
{
  return (void (__cdecl *)(int))_decode_pointer(codedptr: abort_action);
}

//------------------------------------------------------------------------------
// Address: 0x004285DB
// Name: _raise
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall raise@<eax>(unsigned int a1@<esi>, int signum)
{
  _tiddata *v2; // edi
  _tiddata *v3; // eax
  int result; // eax
  void (__cdecl **p_XcptAction)(int); // esi
  void (__cdecl *v6)(int); // eax
  void (__cdecl *v7)(int); // eax
  int oldfpecode; // [esp+10h] [ebp-30h]
  _EXCEPTION_POINTERS *oldpxcptinfoptrs; // [esp+14h] [ebp-2Ch]
  int indx; // [esp+1Ch] [ebp-24h]
  void (__cdecl *sigact)(int); // [esp+20h] [ebp-20h]
  int siglock; // [esp+24h] [ebp-1Ch]

  v2 = nullptr;
  siglock = 0;
  if ( signum > 11 )
  {
    if ( signum == 15 )
    {
      p_XcptAction = &term_action;
      v6 = term_action;
      goto LABEL_18;
    }
    if ( signum == 21 )
    {
      p_XcptAction = &ctrlbreak_action;
      v6 = ctrlbreak_action;
      goto LABEL_18;
    }
    if ( signum != 22 )
      goto LABEL_14;
    goto LABEL_15;
  }
  if ( signum != 11 )
  {
    if ( signum == 2 )
    {
      p_XcptAction = &ctrlc_action;
      v6 = ctrlc_action;
LABEL_18:
      siglock = 1;
      v7 = (void (__cdecl *)(int))_decode_pointer(codedptr: v6);
      goto LABEL_19;
    }
    if ( signum != 4 )
    {
      if ( signum != 6 )
      {
        if ( signum == 8 )
          goto LABEL_7;
LABEL_14:
        *_errno() = 22;
        _invalid_parameter(a1: signum, a2: 0, a3: a1);
        return -1;
      }
LABEL_15:
      p_XcptAction = &abort_action;
      v6 = abort_action;
      goto LABEL_18;
    }
  }
LABEL_7:
  v3 = _getptd_noexit();
  v2 = v3;
  if ( v3 == nullptr )
    return -1;
  p_XcptAction = &siglookup(signum, pxcptacttab: (_XCPT_ACTION *)v3->_pxcptacttab)->XcptAction;
  v7 = *p_XcptAction;
LABEL_19:
  sigact = v7;
  result = 0;
  if ( sigact == (void (__cdecl *)(int))1 )
    return result;
  if ( sigact == nullptr )
    _exit(code: 3);
  if ( siglock != 0 )
    _lock(locknum: 0);
  if ( signum == 8 || signum == 11 || signum == 4 )
  {
    oldpxcptinfoptrs = (_EXCEPTION_POINTERS *)v2->_tpxcptinfoptrs;
    v2->_tpxcptinfoptrs = nullptr;
    if ( signum != 8 )
      goto LABEL_33;
    oldfpecode = v2->_tfpecode;
    v2->_tfpecode = 140;
  }
  if ( signum == 8 )
  {
    for ( indx = _First_FPE_Indx; indx < _First_FPE_Indx + _Num_FPE; ++indx )
      *((_DWORD *)v2->_pxcptacttab + 3 * indx + 2) = 0;
    goto $LN37_0;
  }
LABEL_33:
  *p_XcptAction = (void (__cdecl *)(int))_encoded_null();
$LN37_0:
  if ( siglock != 0 )
    _unlock(locknum: 0);
  if ( signum == 8 )
    ((void (__cdecl *)(int, int))sigact)(a1: 8, a2: v2->_tfpecode);
  else
    sigact(a1: signum);
  if ( signum == 8 || signum == 11 || signum == 4 )
  {
    v2->_tpxcptinfoptrs = oldpxcptinfoptrs;
    if ( signum == 8 )
      v2->_tfpecode = oldfpecode;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0042878B
// Name: ___crtMessageBoxA
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __crtMessageBoxA(const char *lpText, const char *lpCaption, unsigned int uType)
{
  HMODULE LibraryA; // eax
  HMODULE v4; // edi
  int (__stdcall *MessageBoxA)(HWND, LPCSTR, LPCSTR, UINT); // eax
  HWND (__stdcall *GetActiveWindow)(); // eax
  HWND (__stdcall *GetLastActivePopup)(HWND); // eax
  unsigned int v8; // eax
  unsigned int v9; // edx
  BOOL (__stdcall *GetUserObjectInformationA)(HANDLE, int, PVOID, DWORD, LPDWORD); // eax
  HWINSTA (__stdcall *GetProcessWindowStation)(); // eax
  int (*v12)(void); // esi
  int (__stdcall *v13)(int, int, tagUSEROBJECTFLAGS *, int, unsigned int *); // eax
  int (__stdcall *v14)(int, int, tagUSEROBJECTFLAGS *, int, unsigned int *); // edi
  int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // edx
  int (*v18)(void); // eax
  int (__stdcall *v19)(HWND__ *); // eax
  int (__stdcall *v20)(HWND__ *, const char *, const char *, unsigned int); // eax
  LPCSTR lpProcName; // [esp+0h] [ebp-30h]
  LPCSTR lpProcNamea; // [esp+0h] [ebp-30h]
  tagUSEROBJECTFLAGS uof; // [esp+10h] [ebp-20h] BYREF
  unsigned int nDummy; // [esp+1Ch] [ebp-14h] BYREF
  unsigned int winmajor; // [esp+20h] [ebp-10h] BYREF
  unsigned int osplatform; // [esp+24h] [ebp-Ch] BYREF
  void *enull; // [esp+28h] [ebp-8h]
  HWND__ *hWndParent; // [esp+2Ch] [ebp-4h]

  enull = _encoded_null();
  hWndParent = nullptr;
  osplatform = 0;
  winmajor = 0;
  if ( pfnMessageBox == nullptr )
  {
    LibraryA = LoadLibraryA(lpLibFileName: "USER32.DLL");
    v4 = LibraryA;
    if ( LibraryA == nullptr )
      return 0;
    MessageBoxA = (int (__stdcall *)(HWND, LPCSTR, LPCSTR, UINT))GetProcAddress(
                                                                   hModule: LibraryA,
                                                                   lpProcName: "MessageBoxA");
    if ( MessageBoxA == nullptr )
      return 0;
    pfnMessageBox = (int (__stdcall *)(HWND__ *, const char *, const char *, unsigned int))_encode_pointer(ptr: MessageBoxA);
    GetActiveWindow = (HWND (__stdcall *)())GetProcAddress(hModule: v4, lpProcName: "GetActiveWindow");
    pfnGetActiveWindow = (HWND__ *(__stdcall *)())_encode_pointer(ptr: GetActiveWindow);
    GetLastActivePopup = (HWND (__stdcall *)(HWND))GetProcAddress(hModule: v4, lpProcName: "GetLastActivePopup");
    pfnGetLastActivePopup = (HWND__ *(__stdcall *)(HWND__ *))_encode_pointer(ptr: GetLastActivePopup);
    v8 = _get_osplatform(a1: 0, a2: (unsigned int)v4, pValue: &osplatform);
    if ( v8 != 0 )
      _invoke_watson(
        a1: v8,
        a2: v9,
        a3: (unsigned int)lpProcName,
        a4: 0,
        a5: (unsigned int)v4,
        a6: (unsigned int)GetProcAddress);
    if ( osplatform == 2 )
    {
      GetUserObjectInformationA = (BOOL (__stdcall *)(HANDLE, int, PVOID, DWORD, LPDWORD))GetProcAddress(
                                                                                            hModule: v4,
                                                                                            lpProcName: "GetUserObjectInformationA");
      pfnGetUserObjectInformation = (int (__stdcall *)(void *, int, void *, unsigned int, unsigned int *))_encode_pointer(ptr: GetUserObjectInformationA);
      if ( pfnGetUserObjectInformation != nullptr )
      {
        GetProcessWindowStation = (HWINSTA (__stdcall *)())GetProcAddress(
                                                             hModule: v4,
                                                             lpProcName: "GetProcessWindowStation");
        pfnGetProcessWindowStation = (HWINSTA__ *(__stdcall *)())_encode_pointer(ptr: GetProcessWindowStation);
      }
    }
  }
  if ( pfnGetProcessWindowStation == enull
    || pfnGetUserObjectInformation == enull
    || (v12 = (int (*)(void))_decode_pointer(codedptr: pfnGetProcessWindowStation),
        v13 = (int (__stdcall *)(int, int, tagUSEROBJECTFLAGS *, int, unsigned int *))_decode_pointer(codedptr: pfnGetUserObjectInformation),
        v14 = v13,
        v12 == nullptr)
    || v13 == nullptr
    || (v15 = v12()) != 0 && v14(a1: v15, a2: 1, a3: &uof, a4: 12, a5: &nDummy) != 0 && (uof.dwFlags & 1) != 0 )
  {
    if ( pfnGetActiveWindow != enull )
    {
      v18 = (int (*)(void))_decode_pointer(codedptr: pfnGetActiveWindow);
      if ( v18 != nullptr )
      {
        hWndParent = (HWND__ *)v18();
        if ( hWndParent != nullptr && pfnGetLastActivePopup != enull )
        {
          v19 = (int (__stdcall *)(HWND__ *))_decode_pointer(codedptr: pfnGetLastActivePopup);
          if ( v19 != nullptr )
            hWndParent = (HWND__ *)v19(a1: hWndParent);
        }
      }
    }
  }
  else
  {
    v16 = _get_winmajor(a1: 0, a2: (unsigned int)v14, pValue: &winmajor);
    if ( v16 != 0 )
      _invoke_watson(
        a1: v16,
        a2: v17,
        a3: (unsigned int)lpProcNamea,
        a4: 0,
        a5: (unsigned int)v14,
        a6: (unsigned int)v12);
    if ( winmajor < 4 )
      uType |= 0x40000u;
    else
      uType |= 0x200000u;
  }
  v20 = (int (__stdcall *)(HWND__ *, const char *, const char *, unsigned int))_decode_pointer(codedptr: pfnMessageBox);
  if ( v20 != nullptr )
    return v20(a1: hWndParent, a2: lpText, a3: lpCaption, a4: uType);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00428948
// Name: _strcat_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall strcat_s@<eax>(unsigned int a1@<edi>, char *_Dst, unsigned int _SizeInBytes, const char *_Src)
{
  unsigned int v4; // esi
  const char *v6; // esi
  char *v7; // edx
  char v8; // cl

  if ( _Dst == nullptr )
    goto LABEL_3;
  a1 = _SizeInBytes;
  if ( _SizeInBytes == 0 )
    goto LABEL_3;
  v6 = _Src;
  if ( _Src != nullptr )
  {
    v7 = _Dst;
    do
    {
      if ( *v7 == 0 )
        break;
      ++v7;
      --a1;
    }
    while ( a1 != 0 );
    if ( a1 != 0 )
    {
      do
      {
        v8 = *v6;
        *v7++ = *v6++;
        if ( v8 == 0 )
          break;
        --a1;
      }
      while ( a1 != 0 );
      if ( a1 == 0 )
      {
        *_Dst = 0;
        *_errno() = 34;
        v4 = 34;
        goto LABEL_4;
      }
      return 0;
    }
  }
  *_Dst = 0;
LABEL_3:
  v4 = 22;
  *_errno() = 22;
LABEL_4:
  _invalid_parameter(a1: 0, a2: a1, a3: v4);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x004289B9
// Name: _strncpy_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall strncpy_s@<eax>(
        unsigned int a1@<edi>,
        char *_Dst,
        unsigned int _SizeInBytes,
        const char *_Src,
        unsigned int _Count)
{
  unsigned int v6; // esi
  const char *v7; // edx
  char *v8; // eax
  char v9; // cl
  char v10; // cl

  if ( _Count != 0 )
  {
    if ( _Dst == nullptr )
    {
LABEL_7:
      v6 = 22;
      *_errno() = 22;
LABEL_8:
      _invalid_parameter(a1: 0, a2: a1, a3: v6);
      return v6;
    }
  }
  else if ( _Dst == nullptr )
  {
    if ( _SizeInBytes == 0 )
      return 0;
    goto LABEL_7;
  }
  a1 = _SizeInBytes;
  if ( _SizeInBytes == 0 )
    goto LABEL_7;
  if ( _Count == 0 )
  {
    *_Dst = 0;
    return 0;
  }
  v7 = _Src;
  if ( _Src == nullptr )
  {
    *_Dst = 0;
    goto LABEL_7;
  }
  v8 = _Dst;
  if ( _Count == -1 )
  {
    do
    {
      v9 = *v7;
      *v8++ = *v7++;
      if ( v9 == 0 )
        break;
      --a1;
    }
    while ( a1 != 0 );
  }
  else
  {
    do
    {
      v10 = *v7;
      *v8++ = *v7++;
      if ( v10 == 0 )
        break;
      if ( --a1 == 0 )
        break;
      --_Count;
    }
    while ( _Count != 0 );
    if ( _Count == 0 )
      *v8 = 0;
  }
  if ( a1 != 0 )
    return 0;
  if ( _Count != -1 )
  {
    *_Dst = 0;
    *_errno() = 34;
    v6 = 34;
    goto LABEL_8;
  }
  _Dst[_SizeInBytes - 1] = 0;
  return 80;
}

//------------------------------------------------------------------------------
// Address: 0x00428A6C
// Name: __set_error_mode
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _set_error_mode@<eax>(unsigned int a1@<ebx>, unsigned int a2@<edi>, int em)
{
  int result; // eax

  if ( em >= 0 )
  {
    if ( em <= 2 )
    {
      result = __error_mode;
      __error_mode = em;
      return result;
    }
    if ( em == 3 )
      return __error_mode;
  }
  *_errno() = 22;
  _invalid_parameter(a1, a2, a3: 0);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00428AC0
// Name: __ValidateImageBase
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _ValidateImageBase(unsigned __int8 *pImageBase)
{
  unsigned __int8 *v2; // eax

  return *(_WORD *)pImageBase == 23117
      && *(_DWORD *)(v2 = &pImageBase[*((_DWORD *)pImageBase + 15)]) == 17744
      && *((_WORD *)v2 + 12) == 267;
}

//------------------------------------------------------------------------------
// Address: 0x00428AF0
// Name: __FindPESection
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_IMAGE_SECTION_HEADER *__cdecl _FindPESection(unsigned __int8 *pImageBase, unsigned int rva)
{
  unsigned __int8 *v2; // ecx
  unsigned int v3; // esi
  unsigned int v4; // edx
  _IMAGE_SECTION_HEADER *result; // eax
  unsigned int VirtualAddress; // ecx

  v2 = &pImageBase[*((_DWORD *)pImageBase + 15)];
  v3 = *((unsigned __int16 *)v2 + 3);
  v4 = 0;
  result = (_IMAGE_SECTION_HEADER *)&v2[*((unsigned __int16 *)v2 + 10) + 24];
  if ( *((_WORD *)v2 + 3) == 0 )
    return nullptr;
  while ( 1 )
  {
    VirtualAddress = result->VirtualAddress;
    if ( rva >= VirtualAddress && rva < VirtualAddress + result->Misc.PhysicalAddress )
      break;
    ++v4;
    ++result;
    if ( v4 >= v3 )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00428B40
// Name: __IsNonwritableInCurrentImage
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _IsNonwritableInCurrentImage(unsigned __int8 *pTarget)
{
  _IMAGE_SECTION_HEADER *PESection; // eax

  return _ValidateImageBase(pImageBase: (unsigned __int8 *)0x400000)
      && (PESection = _FindPESection(pImageBase: (unsigned __int8 *)0x400000, rva: (unsigned int)(pTarget - 0x400000))) != nullptr
      && (PESection->Characteristics & 0x80000000) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x00428BFB
// Name: void terminate(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn terminate()
{
  void (*v0)(void); // eax

  v0 = (void (*)(void))_getptd()->_terminate;
  if ( v0 != nullptr )
    v0();
  abort();
}

//------------------------------------------------------------------------------
// Address: 0x00428C34
// Name: __initp_eh_hooks
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_eh_hooks()
{
  __pInconsistency = (void (__cdecl *)())_encode_pointer(ptr: terminate);
}

//------------------------------------------------------------------------------
// Address: 0x00428C45
// Name: __initp_misc_rand_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_misc_rand_s(int (__stdcall *enull)(void *, unsigned int))
{
  g_pfnRtlGenRandom = enull;
}

//------------------------------------------------------------------------------
// Address: 0x00428C4F
// Name: __initp_misc_initcrit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_misc_initcrit(int (__stdcall *enull)(_RTL_CRITICAL_SECTION *, unsigned int))
{
  _pfnInitCritSecAndSpinCount = enull;
}

//------------------------------------------------------------------------------
// Address: 0x00428C59
// Name: __crtInitCritSecNoSpinCount
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall _crtInitCritSecNoSpinCount(_RTL_CRITICAL_SECTION *lpCriticalSection, unsigned int dwSpinCount)
{
  InitializeCriticalSection(lpCriticalSection);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00428C69
// Name: ___crtInitCritSecAndSpinCount
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __usercall __crtInitCritSecAndSpinCount@<eax>(
        unsigned int a1@<ebx>,
        _RTL_CRITICAL_SECTION *lpCriticalSection,
        DWORD dwSpinCount)
{
  BOOL (__stdcall *InitializeCriticalSectionAndSpinCount)(LPCRITICAL_SECTION, DWORD); // esi
  unsigned int v4; // eax
  unsigned int v5; // edx
  HMODULE ModuleHandleA; // eax
  unsigned int v8; // [esp-4h] [ebp-38h]
  unsigned int osplatform; // [esp+18h] [ebp-1Ch] BYREF
  CPPEH_RECORD ms_exc; // [esp+1Ch] [ebp-18h]

  osplatform = 0;
  InitializeCriticalSectionAndSpinCount = (BOOL (__stdcall *)(LPCRITICAL_SECTION, DWORD))_decode_pointer(codedptr: _pfnInitCritSecAndSpinCount);
  if ( InitializeCriticalSectionAndSpinCount == nullptr )
  {
    v4 = _get_osplatform(a1, a2: 0, pValue: &osplatform);
    if ( v4 != 0 )
      _invoke_watson(a1: v4, a2: v5, a3: v8, a4: a1, a5: 0, a6: 0);
    if ( osplatform == 1
      || (ModuleHandleA = GetModuleHandleA(lpModuleName: "kernel32.dll")) == nullptr
      || (InitializeCriticalSectionAndSpinCount = (BOOL (__stdcall *)(LPCRITICAL_SECTION, DWORD))GetProcAddress(
                                                                                                   hModule: ModuleHandleA,
                                                                                                   lpProcName: "InitializeCriticalSec"
                                                                                                   "tionAndSpinCount")) == nullptr )
    {
      InitializeCriticalSectionAndSpinCount = _crtInitCritSecNoSpinCount;
    }
    _pfnInitCritSecAndSpinCount = (int (__stdcall *)(_RTL_CRITICAL_SECTION *, unsigned int))_encode_pointer(ptr: InitializeCriticalSectionAndSpinCount);
  }
  ms_exc.registration.TryLevel = 0;
  return InitializeCriticalSectionAndSpinCount(lpCriticalSection, dwSpinCount);
}

//------------------------------------------------------------------------------
// Address: 0x00428D2E
// Name: __initp_heap_handler
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_heap_handler(int (__cdecl *enull)(unsigned int))
{
  _pnhHeap = enull;
}

//------------------------------------------------------------------------------
// Address: 0x00428D38
// Name: x_ismbbtype_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl x_ismbbtype_l(localeinfo_struct *plocinfo, unsigned __int8 tst, int cmask, unsigned __int8 kmask)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( (kmask & _loc_update.localeinfo.mbcinfo->mbctype[tst + 1]) != 0
    || (cmask == 0 ? (result = 0) : (result = (unsigned __int16)(cmask & _loc_update.localeinfo.locinfo->pctype[tst])),
        result != 0) )
  {
    result = 1;
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00428D89
// Name: __ismbblead
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ismbblead(unsigned __int8 tst)
{
  return x_ismbbtype_l(plocinfo: nullptr, tst, cmask: 0, kmask: 4u);
}

//------------------------------------------------------------------------------
// Address: 0x00428D9C
// Name: GetPdbDll
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HINSTANCE__ *__cdecl GetPdbDll()
{
  HINSTANCE__ *result; // eax
  HMODULE LibraryA; // eax
  HMODULE v2; // edi
  LSTATUS (__stdcall *RegQueryValueExA)(HKEY, LPCSTR, LPDWORD, LPDWORD, LPBYTE, LPDWORD); // ebx
  LSTATUS v4; // esi
  unsigned int v5; // ecx
  int v6; // eax
  char *v7; // ecx
  unsigned int type; // [esp+0h] [ebp-80h] BYREF
  int (__stdcall *pfnRegCloseKey)(HKEY__ *); // [esp+4h] [ebp-7Ch]
  int (__stdcall *pfnRegOpenKeyExA)(HKEY__ *, const char *, unsigned int, unsigned int, HKEY__ **); // [esp+8h] [ebp-78h]
  HKEY__ *key1; // [esp+Ch] [ebp-74h] BYREF
  unsigned int len; // [esp+10h] [ebp-70h] BYREF
  char buf[260]; // [esp+14h] [ebp-6Ch] BYREF

  if ( alreadyTried != 0 )
    return nullptr;
  alreadyTried = 1;
  result = LoadLibraryA(lpLibFileName: mspdbName);
  if ( result == nullptr )
  {
    LibraryA = LoadLibraryA(lpLibFileName: "ADVAPI32.DLL");
    v2 = LibraryA;
    if ( LibraryA == nullptr )
      return nullptr;
    pfnRegOpenKeyExA = (int (__stdcall *)(HKEY__ *, const char *, unsigned int, unsigned int, HKEY__ **))GetProcAddress(hModule: LibraryA, lpProcName: "RegOpenKeyExA");
    if ( pfnRegOpenKeyExA == nullptr )
      return nullptr;
    RegQueryValueExA = (LSTATUS (__stdcall *)(HKEY, LPCSTR, LPDWORD, LPDWORD, LPBYTE, LPDWORD))GetProcAddress(
                                                                                                 hModule: v2,
                                                                                                 lpProcName: "RegQueryValueExA");
    if ( RegQueryValueExA == nullptr )
      return nullptr;
    pfnRegCloseKey = (int (__stdcall *)(HKEY__ *))GetProcAddress(hModule: v2, lpProcName: "RegCloseKey");
    if ( pfnRegCloseKey == nullptr )
      return nullptr;
    if ( pfnRegOpenKeyExA(
           a1: (HKEY__ *)-2147483646,
           a2: "SOFTWARE\\Microsoft\\VisualStudio\\8.0\\Setup\\VS",
           a3: 0,
           a4: 1u,
           a5: &key1) != 0
      || RegQueryValueExA(
           hKey: key1,
           lpValueName: "EnvironmentDirectory",
           lpReserved: nullptr,
           lpType: &type,
           lpData: nullptr,
           lpcbData: &len) != 0
      || len + 13 >= 0x104 )
    {
      FreeLibrary(hLibModule: v2);
      return nullptr;
    }
    v4 = RegQueryValueExA(
           hKey: key1,
           lpValueName: "EnvironmentDirectory",
           lpReserved: nullptr,
           lpType: &type,
           lpData: (LPBYTE)buf,
           lpcbData: &len);
    pfnRegCloseKey(a1: key1);
    FreeLibrary(hLibModule: v2);
    if ( v4 != 0 )
      return nullptr;
    v5 = len;
    if ( buf[len - 2] == 92 )
      v5 = --len;
    else
      buf[len - 1] = 92;
    v6 = 0;
    v7 = &buf[v5];
    do
    {
      v7[v6] = mspdbName[v6];
      ++v6;
    }
    while ( v6 <= 11 );
    return LoadLibraryA(lpLibFileName: buf);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00428EF3
// Name: int _RTC_GetSrcLine(unsigned char __near *,wchar_t __near *,unsigned long,int __near *,wchar_t __near *,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _RTC_GetSrcLine(
        unsigned __int8 *address,
        wchar_t *source,
        unsigned int sourcelen,
        int *pline,
        wchar_t *moduleName,
        DWORD modulelen)
{
  unsigned __int8 *v6; // esi
  unsigned __int8 *v7; // esi
  int v9; // eax
  char *v10; // eax
  unsigned int v11; // ecx
  int v12; // eax
  unsigned int v13; // esi
  unsigned int v14; // edi
  _DWORD *v15; // eax
  FARPROC PDBOpenValidate5; // eax
  PDB_vtbl *v17; // eax
  EnumLines *v18; // ecx
  CV_Line_t *v19; // esi
  HANDLE ProcessHeap; // eax
  unsigned int i; // eax
  HANDLE v22; // eax
  unsigned int v23; // [esp-1Ch] [ebp-68h]
  wchar_t *v24; // [esp-18h] [ebp-64h]
  SIZE_T v25; // [esp-8h] [ebp-54h]
  _MEMORY_BASIC_INFORMATION mbi; // [esp+8h] [ebp-44h] BYREF
  int ec; // [esp+24h] [ebp-28h] BYREF
  unsigned int cbBlk; // [esp+28h] [ebp-24h] BYREF
  int res; // [esp+2Ch] [ebp-20h]
  DBI *pdbi; // [esp+30h] [ebp-1Ch] BYREF
  unsigned int offBlk; // [esp+34h] [ebp-18h] BYREF
  PDB *ppdb; // [esp+38h] [ebp-14h] BYREF
  Mod *pmod; // [esp+3Ch] [ebp-10h] BYREF
  unsigned int cLines; // [esp+40h] [ebp-Ch] BYREF
  EnumLines *penum; // [esp+44h] [ebp-8h] BYREF
  unsigned int idFile; // [esp+48h] [ebp-4h] BYREF

  v6 = address;
  *pline = 0;
  *source = 0;
  v7 = v6 - 1;
  if ( VirtualQuery(lpAddress: v7, lpBuffer: &mbi, dwLength: 0x1Cu) == 0 )
    return 0;
  if ( GetModuleFileNameW(hModule: (HMODULE)mbi.AllocationBase, lpFilename: moduleName, nSize: modulelen) == 0 )
    return 0;
  if ( *(_WORD *)mbi.AllocationBase != 23117 )
    return 0;
  v9 = *((_DWORD *)mbi.AllocationBase + 15);
  if ( v9 <= 0 )
    return 0;
  v10 = (char *)mbi.AllocationBase + v9;
  if ( *(_DWORD *)v10 != 17744 )
    return 0;
  v11 = *((unsigned __int16 *)v10 + 3);
  v12 = (int)&v10[*((unsigned __int16 *)v10 + 10) + 24];
  v13 = (char *)v7 - (char *)mbi.AllocationBase;
  v14 = 0;
  idFile = 0;
  if ( v11 != 0 )
  {
    v15 = (_DWORD *)(v12 + 12);
    do
    {
      if ( v13 >= *v15 )
      {
        v14 = v13 - *v15;
        if ( v13 < *(v15 - 1) )
          break;
      }
      ++idFile;
      v15 += 10;
    }
    while ( idFile < v11 );
  }
  if ( idFile == v11 )
    return 0;
  ++idFile;
  if ( !PDBOK )
  {
    if ( mspdb != nullptr )
      return 0;
    mspdb = GetPdbDll();
    if ( mspdb == nullptr )
      return 0;
    PDBOK = true;
  }
  PDBOpenValidate5 = GetProcAddress(hModule: mspdb, lpProcName: "PDBOpenValidate5");
  if ( PDBOpenValidate5 == nullptr
    || ((int (__cdecl *)(wchar_t *, _DWORD, _DWORD, _DWORD, int *, _DWORD, _DWORD, PDB **))PDBOpenValidate5)(
         a1: moduleName,
         a2: 0,
         a3: 0,
         a4: 0,
         a5: &ec,
         a6: 0,
         a7: 0,
         a8: &ppdb) == 0 )
  {
    return 0;
  }
  v17 = ppdb->__vftable;
  res = 0;
  if ( v17->QueryInterfaceVersion(this: ppdb) == 20030901
    && ppdb->OpenDBI(this: ppdb, a2: nullptr, a3: "r", a4: &pdbi) != 0 )
  {
    if ( pdbi->QueryModFromAddr(this: pdbi, a2: idFile, a3: v14, a4: &pmod, a5: nullptr, a6: nullptr, a7: nullptr) != 0 )
    {
      penum = nullptr;
      if ( pmod->GetEnumLines(this: pmod, a2: &penum) )
      {
        v18 = penum;
        if ( penum != nullptr )
        {
          v19 = nullptr;
          while ( 1 )
          {
            if ( v18->next(this: v18) == 0 )
              goto DONE5;
            if ( !penum->getLines(
                    this: penum,
                    a2: nullptr,
                    a3: &offBlk,
                    a4: (unsigned __int16 *)&address,
                    a5: &cbBlk,
                    a6: &cLines,
                    a7: nullptr) )
              goto DONE4;
            if ( (unsigned __int16)address == idFile && offBlk <= v14 && v14 < cbBlk + offBlk )
              break;
            v18 = penum;
          }
          if ( cLines != 0 && cLines < 0x1FFFFFFF )
          {
            v25 = 8 * cLines;
            ProcessHeap = GetProcessHeap();
            v19 = (CV_Line_t *)HeapAlloc(hHeap: ProcessHeap, dwFlags: 0, dwBytes: v25);
            if ( v19 != nullptr )
            {
              if ( penum->getLines(
                     this: penum,
                     a2: &idFile,
                     a3: nullptr,
                     a4: nullptr,
                     a5: nullptr,
                     a6: &cLines,
                     a7: v19)
                && v14 - offBlk >= v19->offset )
              {
                for ( i = 1; i < cLines; ++i )
                {
                  if ( v14 - offBlk < v19[i].offset )
                    break;
                }
                v24 = source;
                v23 = idFile;
                *pline = *((_DWORD *)&v19[i - 1] + 1) & 0xFFFFFF;
                if ( pmod->QueryFileNameInfo(
                       this: pmod,
                       a2: v23,
                       a3: v24,
                       a4: &sourcelen,
                       a5: nullptr,
                       a6: nullptr,
                       a7: nullptr) )
                {
                  res = 1;
                }
              }
DONE5:
              v22 = GetProcessHeap();
              HeapFree(hHeap: v22, dwFlags: 0, lpMem: v19);
            }
          }
DONE4:
          penum->release(this: penum);
        }
      }
      pmod->Close(this: pmod);
    }
    pdbi->Close(this: pdbi);
  }
  ppdb->Close(this: ppdb);
  return res;
}

//------------------------------------------------------------------------------
// Address: 0x00429169
// Name: __fcloseall
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fcloseall()
{
  int i; // edi
  int v1; // esi
  void **v2; // eax
  _iobuf *v3; // eax
  int count; // [esp+14h] [ebp-1Ch]

  count = 0;
  _lock(locknum: 1);
  for ( i = 3; i < (int)_nstream; ++i )
  {
    v1 = i;
    v2 = &__piob[i];
    if ( *v2 != nullptr )
    {
      v3 = (_iobuf *)*v2;
      if ( (v3->_flag & 0x83) != 0 && fclose(stream: v3) != -1 )
        ++count;
      if ( i >= 20 )
      {
        DeleteCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)__piob[v1] + 32));
        free(pMem: __piob[v1]);
        __piob[v1] = nullptr;
      }
    }
  }
  _unlock(locknum: 1);
  return count;
}

//------------------------------------------------------------------------------
// Address: 0x00429208
// Name: __toupper_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _toupper_l(unsigned int c, localeinfo_struct *plocinfo)
{
  threadlocaleinfostruct *locinfo; // ecx
  int v4; // eax
  unsigned int result; // eax
  int v6; // ecx
  int v7; // eax
  unsigned __int16 v8; // ax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-18h] BYREF
  char outbuffer[4]; // [esp+14h] [ebp-8h] BYREF
  char inbuffer[4]; // [esp+18h] [ebp-4h] BYREF
  int ca; // [esp+24h] [ebp+8h]

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( c >= 0x100 )
  {
    if ( _loc_update.localeinfo.locinfo->mb_cur_max > 1
      && (ca = (int)c >> 8, _isleadbyte_l(c: BYTE1(c), plocinfo: &_loc_update.localeinfo) != 0) )
    {
      inbuffer[0] = ca;
      inbuffer[1] = c;
      inbuffer[2] = 0;
      v6 = 2;
    }
    else
    {
      *_errno() = 42;
      inbuffer[0] = c;
      inbuffer[1] = 0;
      v6 = 1;
    }
    v7 = __crtLCMapStringA(
           plocinfo: &_loc_update.localeinfo,
           Locale: _loc_update.localeinfo.locinfo->lc_handle[2],
           dwMapFlags: 0x200u,
           lpSrcStr: inbuffer,
           cchSrc: v6,
           lpDestStr: outbuffer,
           cchDest: 3,
           code_page: _loc_update.localeinfo.locinfo->lc_codepage,
           bError: 1);
    if ( v7 != 0 )
    {
      if ( v7 == 1 )
      {
        result = (unsigned __int8)outbuffer[0];
      }
      else
      {
        LOBYTE(v8) = 0;
        HIBYTE(v8) = outbuffer[0];
        result = (unsigned __int8)outbuffer[1] | v8;
      }
      goto LABEL_18;
    }
  }
  else
  {
    locinfo = _loc_update.localeinfo.locinfo;
    if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    {
      v4 = _loc_update.localeinfo.locinfo->pctype[c] & 2;
    }
    else
    {
      v4 = _isctype_l(c, mask: 2, plocinfo: &_loc_update.localeinfo);
      locinfo = _loc_update.localeinfo.locinfo;
    }
    if ( v4 != 0 )
    {
      result = locinfo->pcumap[c];
LABEL_18:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return result;
    }
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return c;
}

//------------------------------------------------------------------------------
// Address: 0x00429320
// Name: _toupper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl toupper(unsigned int c)
{
  unsigned int result; // eax

  if ( __locale_changed != 0 )
    return _toupper_l(c, plocinfo: nullptr);
  result = c;
  if ( c - 97 <= 0x19 )
    return c - 32;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00429347
// Name: __set_osfhnd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _set_osfhnd(int fh, void *value)
{
  int v2; // esi

  if ( fh >= 0 && fh < _nhandle && *(int *)((char *)&__pioinfo[fh >> 5]->osfhnd + (v2 = fh & 0x1F)) == -1 )
  {
    if ( __app_type == 1 )
    {
      if ( fh != 0 )
      {
        if ( fh == 1 )
        {
          SetStdHandle(nStdHandle: 0xFFFFFFF5, hHandle: value);
        }
        else if ( fh == 2 )
        {
          SetStdHandle(nStdHandle: 0xFFFFFFF4, hHandle: value);
        }
      }
      else
      {
        SetStdHandle(nStdHandle: 0xFFFFFFF6, hHandle: value);
      }
    }
    __pioinfo[fh >> 5][v2].osfhnd = (int)value;
    return 0;
  }
  else
  {
    *_errno() = 9;
    *__doserrno() = 0;
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004293C4
// Name: __free_osfhnd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _free_osfhnd(int fh)
{
  int v1; // esi
  ioinfo *v2; // eax

  if ( fh < 0
    || fh >= _nhandle
    || (v1 = fh & 0x1F, ((v2 = &__pioinfo[fh >> 5][v1])->osfile & 1) == 0)
    || v2->osfhnd == -1 )
  {
    *_errno() = 9;
    *__doserrno() = 0;
    return -1;
  }
  else
  {
    if ( __app_type == 1 )
    {
      if ( fh != 0 )
      {
        if ( fh == 1 )
        {
          SetStdHandle(nStdHandle: 0xFFFFFFF5, hHandle: nullptr);
        }
        else if ( fh == 2 )
        {
          SetStdHandle(nStdHandle: 0xFFFFFFF4, hHandle: nullptr);
        }
      }
      else
      {
        SetStdHandle(nStdHandle: 0xFFFFFFF6, hHandle: nullptr);
      }
    }
    __pioinfo[fh >> 5][v1].osfhnd = -1;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00429445
// Name: __get_osfhandle
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _get_osfhandle@<eax>(unsigned int a1@<ebx>, unsigned int a2@<edi>, int fh)
{
  ioinfo *v4; // eax

  if ( fh == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  else if ( fh >= 0 && fh < _nhandle && ((v4 = &__pioinfo[fh >> 5][fh & 0x1F])->osfile & 1) != 0 )
  {
    return v4->osfhnd;
  }
  else
  {
    *__doserrno() = 0;
    *_errno() = 9;
    _invalid_parameter(a1, a2, a3: 0);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004294B6
// Name: ___lock_fhandle
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl __lock_fhandle(int fh)
{
  ioinfo *v1; // esi
  BOOL retval; // [esp+10h] [ebp-1Ch]

  v1 = &__pioinfo[fh >> 5][fh & 0x1F];
  retval = true;
  if ( v1->lockinitflag == 0 )
  {
    _lock(locknum: 10);
    if ( v1->lockinitflag == 0 )
    {
      retval = __crtInitCritSecAndSpinCount(a1: 0, lpCriticalSection: &v1->lock, dwSpinCount: 0xFA0u);
      ++v1->lockinitflag;
    }
    _unlock(locknum: 10);
  }
  if ( retval )
    EnterCriticalSection(lpCriticalSection: &__pioinfo[fh >> 5][fh & 0x1F].lock);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x00429556
// Name: __unlock_fhandle
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _unlock_fhandle(int fh)
{
  LeaveCriticalSection(lpCriticalSection: &__pioinfo[fh >> 5][fh & 0x1F].lock);
}

//------------------------------------------------------------------------------
// Address: 0x00429578
// Name: __alloc_osfhnd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _alloc_osfhnd()
{
  int v0; // edi
  ioinfo *v2; // esi
  ioinfo *v3; // eax
  int failed; // [esp+14h] [ebp-24h]
  int fh; // [esp+1Ch] [ebp-1Ch]

  fh = -1;
  v0 = 0;
  failed = 0;
  if ( _mtinitlocknum(locknum: 11) == 0 )
    return -1;
  _lock(locknum: 11);
  while ( v0 < 64 )
  {
    v2 = __pioinfo[v0];
    if ( v2 == nullptr )
    {
      v3 = (ioinfo *)calloc(count: 0x20u, size: 0x38u);
      if ( v3 != nullptr )
      {
        __pioinfo[v0] = v3;
        _nhandle += 32;
        while ( v3 < &__pioinfo[v0][32] )
        {
          v3->osfile = 0;
          v3->osfhnd = -1;
          v3->pipech = 10;
          v3->lockinitflag = 0;
          ++v3;
        }
        fh = 32 * v0;
        __pioinfo[(32 * v0) >> 5]->osfile = 1;
        if ( !__lock_fhandle(fh: 32 * v0) )
          fh = -1;
      }
      break;
    }
    while ( v2 < &__pioinfo[v0][32] )
    {
      if ( (v2->osfile & 1) == 0 )
      {
        if ( v2->lockinitflag == 0 )
        {
          _lock(locknum: 10);
          if ( v2->lockinitflag == 0 )
          {
            if ( __crtInitCritSecAndSpinCount(a1: 1u, lpCriticalSection: &v2->lock, dwSpinCount: 0xFA0u) )
              ++v2->lockinitflag;
            else
              failed = 1;
          }
          _unlock(locknum: 10);
        }
        if ( failed == 0 )
        {
          EnterCriticalSection(lpCriticalSection: &v2->lock);
          if ( (v2->osfile & 1) == 0 )
          {
            v2->osfile = 1;
            v2->osfhnd = -1;
            fh = 32 * v0 + v2 - __pioinfo[v0];
            break;
          }
          LeaveCriticalSection(lpCriticalSection: &v2->lock);
        }
      }
      ++v2;
    }
    if ( fh != -1 )
      break;
    ++v0;
  }
  _unlock(locknum: 11);
  return fh;
}

//------------------------------------------------------------------------------
// Address: 0x00429717
// Name: __commit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DWORD __usercall _commit@<eax>(unsigned int a1@<edi>, int a2@<esi>, int filedes)
{
  void *osfhandle; // eax
  DWORD retval; // [esp+14h] [ebp-1Ch]

  if ( filedes == -2 )
  {
    *_errno() = 9;
    return -1;
  }
  if ( filedes < 0
    || filedes >= _nhandle
    || (a1 = 4 * (filedes >> 5) + 4534976, (*(&__pioinfo[filedes >> 5]->osfile + (a2 = filedes & 0x1F)) & 1) == 0) )
  {
    *_errno() = 9;
    _invalid_parameter(a1: 0, a2: a1, a3: a2 * 56);
    return -1;
  }
  __lock_fhandle(fh: filedes);
  if ( (__pioinfo[filedes >> 5][a2].osfile & 1) != 0 )
  {
    osfhandle = (void *)_get_osfhandle(a1: 0, a2: a1, fh: filedes);
    if ( FlushFileBuffers(hFile: osfhandle) )
      retval = 0;
    else
      retval = GetLastError();
    if ( retval == 0 )
      goto good;
    *__doserrno() = retval;
  }
  *_errno() = 9;
  retval = -1;
good:
  _unlock_fhandle(fh: filedes);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x004297F8
// Name: _tsopen_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall tsopen_nolock@<eax>(
        int *pfh@<eax>,
        unsigned int a2@<edi>,
        int *punlock_flag,
        const char *path,
        int oflag,
        int shflag,
        char pmode)
{
  unsigned int v8; // eax
  unsigned int v9; // edx
  unsigned int v10; // eax
  unsigned int v11; // edx
  unsigned int v12; // edi
  unsigned int v13; // eax
  int v14; // eax
  char *p_osfile; // eax
  DWORD LastError; // eax
  int result; // eax
  DWORD FileType; // eax
  char *v19; // eax
  DWORD v20; // esi
  char v21; // cl
  _BYTE *v22; // eax
  int v23; // eax
  unsigned int v24; // eax
  int v25; // eax
  _BYTE *v26; // eax
  _BYTE *v27; // eax
  bool v28; // zf
  char *v29; // eax
  unsigned int v30; // edi
  HANDLE v31; // eax
  DWORD v32; // eax
  char *v33; // eax
  doubleint v34; // rax
  int v35; // eax
  doubleint v36; // rax
  unsigned int v37; // eax
  int v38; // edi
  int v39; // eax
  int v40; // [esp-Ch] [ebp-4Ch]
  DWORD v41; // [esp-8h] [ebp-48h]
  unsigned int v42; // [esp-4h] [ebp-44h]
  unsigned int v43; // [esp-4h] [ebp-44h]
  _SECURITY_ATTRIBUTES SecurityAttributes; // [esp+Ch] [ebp-34h] BYREF
  unsigned int osplatform; // [esp+18h] [ebp-28h] BYREF
  int fmode; // [esp+1Ch] [ebp-24h] BYREF
  int retvalue; // [esp+20h] [ebp-20h]
  void *osfh; // [esp+24h] [ebp-1Ch]
  int bom; // [esp+28h] [ebp-18h] BYREF
  int bomlen; // [esp+2Ch] [ebp-14h]
  unsigned int fileshare; // [esp+30h] [ebp-10h]
  unsigned int fileattrib; // [esp+34h] [ebp-Ch]
  unsigned int fileaccess; // [esp+38h] [ebp-8h]
  char inputbuf; // [esp+3Ch] [ebp-4h] BYREF
  char v55; // [esp+3Dh] [ebp-3h]
  char tmode; // [esp+3Eh] [ebp-2h]
  char fileflags; // [esp+3Fh] [ebp-1h]

  fmode = 0;
  osplatform = 0;
  tmode = 0;
  SecurityAttributes.nLength = 12;
  SecurityAttributes.lpSecurityDescriptor = nullptr;
  if ( (oflag & 0x80u) == 0 )
  {
    SecurityAttributes.bInheritHandle = 1;
    fileflags = 0;
  }
  else
  {
    SecurityAttributes.bInheritHandle = 0;
    fileflags = 16;
  }
  v8 = _get_fmode(pMode: &fmode);
  if ( v8 != 0 )
    _invoke_watson(a1: v8, a2: v9, a3: v42, a4: 0, a5: a2, a6: (unsigned int)pfh);
  v10 = _get_osplatform(a1: 0, a2, pValue: &osplatform);
  if ( v10 != 0 )
    _invoke_watson(a1: v10, a2: v11, a3: v43, a4: 0, a5: a2, a6: (unsigned int)pfh);
  if ( (oflag & 0x8000) == 0 && ((oflag & 0x74000) != 0 || fmode != 0x8000) )
    fileflags |= 0x80u;
  v12 = 0x80000000;
  if ( (oflag & 3) != 0 )
  {
    if ( (oflag & 3) != 1 )
    {
      if ( (oflag & 3) != 2 )
      {
LABEL_15:
        *__doserrno() = 0;
        *pfh = -1;
        *_errno() = 22;
        _invalid_parameter(a1: 0, a2: v12, a3: 0x16u);
        return 22;
      }
      goto LABEL_16;
    }
    if ( (oflag & 8) != 0 && (oflag & 0x70000) != 0 )
    {
LABEL_16:
      fileaccess = -1073741824;
      goto LABEL_21;
    }
    fileaccess = 0x40000000;
  }
  else
  {
    fileaccess = 0x80000000;
  }
LABEL_21:
  switch ( shflag )
  {
    case 16:
      fileshare = 0;
      break;
    case 32:
      fileshare = 1;
      break;
    case 48:
      fileshare = 2;
      break;
    case 64:
      fileshare = 3;
      break;
    case 128:
      fileshare = fileaccess == 0x80000000;
      break;
    default:
      goto LABEL_15;
  }
  v13 = oflag & 0x700;
  v12 = 256;
  if ( v13 > 0x400 )
  {
    if ( v13 != 1280 )
    {
      if ( v13 == 1536 )
        goto LABEL_54;
      if ( v13 != 1792 )
        goto LABEL_15;
    }
    bomlen = 1;
    goto LABEL_44;
  }
  if ( (oflag & 0x700) == 0x400 || (oflag & 0x700) == 0 )
  {
    bomlen = 3;
    goto LABEL_44;
  }
  if ( v13 == 256 )
  {
    bomlen = 4;
    goto LABEL_44;
  }
  if ( v13 == 512 )
  {
LABEL_54:
    bomlen = 5;
    goto LABEL_44;
  }
  if ( v13 != 768 )
    goto LABEL_15;
  bomlen = 2;
LABEL_44:
  fileattrib = 128;
  if ( (oflag & 0x100) != 0 && (pmode & ~(_BYTE)_umaskval & 0x80u) == 0 )
    fileattrib = 1;
  if ( (oflag & 0x40) != 0 )
  {
    fileattrib |= 0x4000000u;
    fileaccess |= 0x10000u;
    if ( osplatform == 2 )
      fileshare |= 4u;
  }
  if ( (oflag & 0x1000) != 0 )
    fileattrib |= 0x100u;
  if ( (oflag & 0x20) != 0 )
  {
    fileattrib |= 0x8000000u;
  }
  else if ( (oflag & 0x10) != 0 )
  {
    fileattrib |= 0x10000000u;
  }
  v14 = _alloc_osfhnd();
  *pfh = v14;
  if ( v14 == -1 )
  {
    *__doserrno() = 0;
    *pfh = -1;
    *_errno() = 24;
    return *_errno();
  }
  v41 = fileattrib;
  *punlock_flag = 1;
  osfh = CreateFileA(
           lpFileName: path,
           dwDesiredAccess: fileaccess,
           dwShareMode: fileshare,
           lpSecurityAttributes: &SecurityAttributes,
           dwCreationDisposition: bomlen,
           dwFlagsAndAttributes: v41,
           hTemplateFile: nullptr);
  if ( osfh == (void *)-1 )
  {
    if ( (fileaccess & 0xC0000000) != 0xC0000000
      || (oflag & 1) == 0
      || (fileaccess &= ~0x80000000,
          (osfh = CreateFileA(
                    lpFileName: path,
                    dwDesiredAccess: fileaccess,
                    dwShareMode: fileshare,
                    lpSecurityAttributes: &SecurityAttributes,
                    dwCreationDisposition: bomlen,
                    dwFlagsAndAttributes: fileattrib,
                    hTemplateFile: nullptr)) == (void *)-1) )
    {
      p_osfile = &__pioinfo[*pfh >> 5][*pfh & 0x1F].osfile;
      *p_osfile &= ~1u;
      LastError = GetLastError();
      _dosmaperr(oserrno: LastError);
      return *_errno();
    }
  }
  FileType = GetFileType(hFile: osfh);
  switch ( FileType )
  {
    case 0u:
      v19 = &__pioinfo[*pfh >> 5][*pfh & 0x1F].osfile;
      *v19 &= ~1u;
      v20 = GetLastError();
      _dosmaperr(oserrno: v20);
      CloseHandle(hObject: osfh);
      if ( v20 == 0 )
        *_errno() = 13;
      return *_errno();
    case 2u:
      fileflags |= 0x40u;
      break;
    case 3u:
      fileflags |= 8u;
      break;
    default:
      break;
  }
  _set_osfhnd(fh: *pfh, value: osfh);
  v21 = fileflags | 1;
  __pioinfo[*pfh >> 5][*pfh & 0x1F].osfile = fileflags | 1;
  v22 = (char *)&__pioinfo[*pfh >> 5][*pfh & 0x1F] + 36;
  *v22 &= 0x80u;
  v55 = v21 & 0x48;
  fileflags = v21;
  if ( (v21 & 0x48) == 0 )
  {
    if ( v21 >= 0 )
      goto LABEL_107;
    if ( (oflag & 2) != 0 )
    {
      bom = _lseek_nolock(fh: *pfh, pos: -1, mthd: 2u);
      if ( bom == -1 )
      {
        if ( *__doserrno() != 131 )
        {
LABEL_77:
          _close_nolock(fh: *pfh);
          return *_errno();
        }
      }
      else
      {
        v40 = *pfh;
        inputbuf = 0;
        if ( _read_nolock(a1: 0xFFFFFFFF, fh: v40, &inputbuf, cnt: 1u) == 0
          && inputbuf == 26
          && _chsize_nolock(filedes: *pfh, size: bom) == -1
          || _lseek_nolock(fh: *pfh, pos: 0, mthd: 0) == -1 )
        {
          goto LABEL_77;
        }
      }
    }
  }
  if ( fileflags < 0 )
  {
    if ( (oflag & 0x74000) == 0 )
    {
      if ( (fmode & 0x74000) != 0 )
        oflag |= fmode & 0x74000;
      else
        oflag |= 0x4000u;
    }
    v23 = oflag & 0x74000;
    if ( (oflag & 0x74000) == 0x4000 )
    {
      tmode = 0;
      goto LABEL_98;
    }
    if ( v23 == 0x10000 || v23 == 81920 )
    {
      if ( (oflag & 0x301) != 0x301 )
        goto LABEL_98;
    }
    else if ( v23 != 0x20000 && v23 != 147456 )
    {
      if ( v23 == 0x40000 || v23 == 278528 )
        tmode = 1;
LABEL_98:
      if ( (oflag & 0x70000) == 0 )
        goto LABEL_107;
      bom = 0;
      if ( (fileflags & 0x40) != 0 )
        goto LABEL_107;
      v24 = fileaccess & 0xC0000000;
      if ( (fileaccess & 0xC0000000) == 0x40000000 )
      {
        v25 = bomlen;
        if ( bomlen == 0 )
          goto LABEL_107;
        if ( (unsigned int)bomlen <= 2 )
          goto LABEL_135;
        if ( (unsigned int)bomlen > 4 )
          goto LABEL_106;
        if ( _lseeki64_nolock(fh: *pfh, pos: 0, mthd: 2u).bigint != 0 )
        {
          v36.bigint = _lseeki64_nolock(fh: *pfh, pos: 0, mthd: 0).bigint;
          v37 = v36.twoints.upperhalf & v36.twoints.lowerhalf;
          goto LABEL_126;
        }
      }
      else
      {
        if ( v24 == 0x80000000 )
          goto LABEL_116;
        if ( v24 != -1073741824 )
          goto LABEL_107;
        v25 = bomlen;
        if ( bomlen == 0 )
          goto LABEL_107;
        if ( (unsigned int)bomlen > 2 )
        {
          if ( (unsigned int)bomlen > 4 )
          {
LABEL_106:
            if ( v25 != 5 )
              goto LABEL_107;
            goto LABEL_135;
          }
          if ( _lseeki64_nolock(fh: *pfh, pos: 0, mthd: 2u).bigint != 0 )
          {
            v34.bigint = _lseeki64_nolock(fh: *pfh, pos: 0, mthd: 0).bigint;
            if ( (v34.twoints.upperhalf & v34.twoints.lowerhalf) == -1 )
              goto LABEL_77;
LABEL_116:
            v35 = _read_nolock(a1: 0x4000u, fh: *pfh, inputbuf: &bom, cnt: 3u);
            if ( v35 == -1 )
              goto LABEL_77;
            if ( v35 != 2 )
            {
              if ( v35 != 3 )
              {
LABEL_134:
                v37 = _lseek_nolock(fh: *pfh, pos: 0, mthd: 0);
LABEL_126:
                if ( v37 == -1 )
                  goto LABEL_77;
                goto LABEL_107;
              }
              if ( bom == 12565487 )
              {
                tmode = 1;
                goto LABEL_107;
              }
            }
            if ( (unsigned __int16)bom == 65534 )
            {
              _close_nolock(fh: *pfh);
              *_errno() = 22;
              return 22;
            }
            if ( (unsigned __int16)bom == 65279 )
            {
              if ( _lseek_nolock(fh: *pfh, pos: 2, mthd: 0) == -1 )
                goto LABEL_77;
              tmode = 2;
              goto LABEL_107;
            }
            goto LABEL_134;
          }
        }
      }
LABEL_135:
      v38 = 0;
      if ( tmode == 1 )
      {
        bom = 12565487;
        bomlen = 3;
LABEL_139:
        while ( 1 )
        {
          v39 = _write(a1: 0, a2: (int)pfh, fh: *pfh, buf: (char *)&bom + v38, cnt: bomlen - v38);
          if ( v39 == -1 )
            break;
          v38 += v39;
          if ( bomlen <= v38 )
            goto LABEL_107;
        }
        _close_nolock(fh: *pfh);
        result = *_errno();
        retvalue = result;
        return result;
      }
      if ( tmode == 2 )
      {
        bom = 65279;
        bomlen = 2;
        goto LABEL_139;
      }
      goto LABEL_107;
    }
    tmode = 2;
    goto LABEL_98;
  }
LABEL_107:
  v26 = (char *)&__pioinfo[*pfh >> 5][*pfh & 0x1F] + 36;
  *v26 ^= (tmode ^ *v26) & 0x7F;
  v27 = (char *)&__pioinfo[*pfh >> 5][*pfh & 0x1F] + 36;
  v28 = v55 == 0;
  *v27 = *v27 & 0x7F | (BYTE2(oflag) << 7);
  if ( v28 && (oflag & 8) != 0 )
  {
    v29 = &__pioinfo[*pfh >> 5][*pfh & 0x1F].osfile;
    *v29 |= 0x20u;
  }
  v30 = fileaccess;
  if ( (fileaccess & 0xC0000000) == 0xC0000000 && (oflag & 1) != 0 )
  {
    CloseHandle(hObject: osfh);
    v31 = CreateFileA(
            lpFileName: path,
            dwDesiredAccess: v30 & 0x7FFFFFFF,
            dwShareMode: fileshare,
            lpSecurityAttributes: &SecurityAttributes,
            dwCreationDisposition: 3u,
            dwFlagsAndAttributes: fileattrib,
            hTemplateFile: nullptr);
    if ( v31 == (HANDLE)-1 )
    {
      v32 = GetLastError();
      _dosmaperr(oserrno: v32);
      v33 = &__pioinfo[*pfh >> 5][*pfh & 0x1F].osfile;
      *v33 &= ~1u;
      _free_osfhnd(fh: *pfh);
      return *_errno();
    }
    __pioinfo[*pfh >> 5][*pfh & 0x1F].osfhnd = (int)v31;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00429F51
// Name: __sopen_helper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _sopen_helper@<eax>(
        unsigned int a1@<ebx>,
        const char *path,
        int oflag,
        int shflag,
        int pmode,
        int *pfh,
        int bSecure)
{
  int result; // eax
  char *p_osfile; // eax
  int retval; // [esp+14h] [ebp-20h]
  int unlock_flag; // [esp+18h] [ebp-1Ch] BYREF
  CPPEH_RECORD ms_exc; // [esp+1Ch] [ebp-18h]

  unlock_flag = 0;
  if ( pfh == nullptr || (*pfh = -1, path == nullptr) || bSecure != 0 && (pmode & 0xFFFFFE7F) != 0 )
  {
    *_errno() = 22;
    _invalid_parameter(a1, a2: 0x16u, a3: 0);
    return 22;
  }
  else
  {
    ms_exc.registration.TryLevel = 0;
    retval = tsopen_nolock(pfh, a2: (unsigned int)pfh, punlock_flag: &unlock_flag, path, oflag, shflag, pmode);
    ms_exc.registration.TryLevel = -2;
    if ( unlock_flag != 0 )
    {
      if ( retval != 0 )
      {
        p_osfile = &__pioinfo[*pfh >> 5][*pfh & 0x1F].osfile;
        *p_osfile &= ~1u;
      }
      _unlock_fhandle(fh: *pfh);
    }
    result = retval;
    if ( retval != 0 )
      *pfh = -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042A01D
// Name: __sopen_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _sopen_s@<eax>(unsigned int a1@<ebx>, int *pfh, const char *path, int oflag, int shflag, int pmode)
{
  return _sopen_helper(a1, path, oflag, shflag, pmode, pfh, bSecure: 1);
}

//------------------------------------------------------------------------------
// Address: 0x0042A03B
// Name: __mbsicmp_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _mbsicmp_l@<eax>(
        unsigned int a1@<ebx>,
        unsigned int a2@<edi>,
        const unsigned __int8 *s1,
        const unsigned __int8 *s2,
        localeinfo_struct *plocinfo)
{
  const unsigned __int8 *v5; // edx
  int result; // eax
  const unsigned __int8 *v7; // ebx
  threadmbcinfostruct *mbcinfo; // eax
  unsigned __int16 v9; // cx
  const unsigned __int8 *v10; // edx
  unsigned __int16 v11; // si
  int v12; // eax
  unsigned __int16 v13; // ax
  unsigned __int16 v14; // dx
  char *v15; // ecx
  unsigned __int16 v16; // cx
  unsigned __int16 v17; // cx
  int v18; // eax
  unsigned __int16 v19; // ax
  unsigned __int16 v20; // dx
  char *v21; // ecx
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-14h] BYREF
  unsigned __int8 szResult[4]; // [esp+14h] [ebp-4h] BYREF
  const unsigned __int8 *s1a; // [esp+20h] [ebp+8h]

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  v5 = s1;
  if ( s1 == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter(a1, a2, a3: 0);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  v7 = s2;
  if ( s2 == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter(a1: 0, a2, a3: 0);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  mbcinfo = _loc_update.localeinfo.mbcinfo;
  if ( _loc_update.localeinfo.mbcinfo->ismbcodepage == 0 )
  {
    result = _stricmp_l(dst: (const char *)s1, src: (const char *)s2, plocinfo: &_loc_update.localeinfo);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return result;
  }
  while ( 1 )
  {
    v9 = *v5;
    v10 = v5 + 1;
    s1a = v10;
    if ( (mbcinfo->mbctype[(unsigned __int8)v9 + 1] & 4) != 0 )
    {
      if ( *v10 != 0 )
      {
        v12 = __crtLCMapStringA(
                plocinfo: &_loc_update.localeinfo,
                Locale: mbcinfo->mblcid,
                dwMapFlags: 0x200u,
                lpSrcStr: (const char *)v10 - 1,
                cchSrc: 2,
                lpDestStr: (char *)szResult,
                cchDest: 2,
                code_page: mbcinfo->mbcodepage,
                bError: 1);
        if ( v12 == 1 )
        {
          v13 = szResult[0];
        }
        else
        {
          if ( v12 != 2 )
            goto LABEL_37;
          v13 = szResult[1] + (szResult[0] << 8);
        }
        ++s1a;
        v11 = v13;
        mbcinfo = _loc_update.localeinfo.mbcinfo;
      }
      else
      {
        v11 = 0;
      }
    }
    else
    {
      v14 = v9;
      v15 = (char *)mbcinfo + v9;
      v11 = (v15[29] & 0x10) != 0 ? (unsigned __int8)v15[285] : v14;
    }
    v16 = *v7++;
    if ( (mbcinfo->mbctype[(unsigned __int8)v16 + 1] & 4) != 0 )
      break;
    v20 = v16;
    v21 = (char *)mbcinfo + v16;
    if ( (v21[29] & 0x10) != 0 )
      v17 = (unsigned __int8)v21[285];
    else
      v17 = v20;
LABEL_34:
    if ( v17 != v11 )
    {
      result = v17 < v11 ? 1 : -1;
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return result;
    }
    if ( v11 == 0 )
    {
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 0;
    }
    v5 = s1a;
  }
  if ( *v7 == 0 )
  {
    v17 = 0;
    goto LABEL_34;
  }
  v18 = __crtLCMapStringA(
          plocinfo: &_loc_update.localeinfo,
          Locale: mbcinfo->mblcid,
          dwMapFlags: 0x200u,
          lpSrcStr: (const char *)v7 - 1,
          cchSrc: 2,
          lpDestStr: (char *)szResult,
          cchDest: 2,
          code_page: mbcinfo->mbcodepage,
          bError: 1);
  if ( v18 == 1 )
  {
    v19 = szResult[0];
LABEL_30:
    v17 = v19;
    mbcinfo = _loc_update.localeinfo.mbcinfo;
    ++v7;
    goto LABEL_34;
  }
  if ( v18 == 2 )
  {
    v19 = szResult[1] + (szResult[0] << 8);
    goto LABEL_30;
  }
LABEL_37:
  *_errno() = 22;
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return 0x7FFFFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x0042A255
// Name: __mbsicmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _mbsicmp@<eax>(
        unsigned int a1@<ebx>,
        unsigned int a2@<edi>,
        const unsigned __int8 *s1,
        const unsigned __int8 *s2)
{
  return _mbsicmp_l(a1, a2, s1, s2, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0042A268
// Name: __mbsnbcmp_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _mbsnbcmp_l@<eax>(
        unsigned int a1@<esi>,
        const unsigned __int8 *s1,
        const unsigned __int8 *s2,
        unsigned int n,
        localeinfo_struct *plocinfo)
{
  int result; // eax
  threadmbcinfostruct *mbcinfo; // edi
  const unsigned __int8 *v7; // esi
  unsigned __int16 v8; // cx
  const unsigned __int8 *v9; // eax
  int v10; // eax
  unsigned __int8 v11; // al
  unsigned __int16 v12; // dx
  unsigned __int8 v13; // dl
  __int16 v14; // bx
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  if ( n == 0 )
    return 0;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  mbcinfo = _loc_update.localeinfo.mbcinfo;
  if ( _loc_update.localeinfo.mbcinfo->ismbcodepage == 0 )
  {
    result = strncmp(first: (const char *)s1, last: (const char *)s2, count: n);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return result;
  }
  if ( s1 == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter(a1: 0, a2: (unsigned int)mbcinfo, a3: a1);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  v7 = s2;
  if ( s2 == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter(a1: 0, a2: (unsigned int)mbcinfo, a3: 0);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  while ( 1 )
  {
    --n;
    v8 = *s1;
    v9 = ++s1;
    if ( (_loc_update.localeinfo.mbcinfo->mbctype[(unsigned __int8)v8 + 1] & 4) == 0 )
      goto LABEL_21;
    if ( n != 0 )
    {
      v11 = *v9;
      if ( v11 != 0 )
      {
        ++s1;
        HIBYTE(v12) = v8;
        LOBYTE(v12) = v11;
        v8 = v12;
      }
      else
      {
        v8 = 0;
      }
LABEL_21:
      LOWORD(v10) = *v7++;
      if ( (_loc_update.localeinfo.mbcinfo->mbctype[(unsigned __int8)v10 + 1] & 4) != 0 )
      {
        if ( n != 0 && (v13 = *v7, --n, *v7 != 0) )
        {
          HIBYTE(v14) = v10;
          ++v7;
          LOBYTE(v14) = v13;
          LOWORD(v10) = v14;
        }
        else
        {
          LOWORD(v10) = 0;
        }
      }
      goto test;
    }
    v10 = *v7;
    v8 = 0;
    if ( (_loc_update.localeinfo.mbcinfo->mbctype[v10 + 1] & 4) != 0 )
      goto LABEL_29;
test:
    if ( (_WORD)v10 != v8 )
      break;
    if ( v8 == 0 || n == 0 )
    {
LABEL_29:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 0;
    }
  }
  result = (unsigned __int16)v10 < v8 ? 1 : -1;
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042A3D1
// Name: __mbsnbcmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _mbsnbcmp@<eax>(
        unsigned int a1@<esi>,
        const unsigned __int8 *s1,
        const unsigned __int8 *s2,
        unsigned int n)
{
  return _mbsnbcmp_l(a1, s1, s2, n, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0042A3E8
// Name: __global_unwind2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _global_unwind2(PVOID TargetFrame)
{
  RtlUnwind(TargetFrame, TargetIp: &gu_return, ExceptionRecord: nullptr, ReturnValue: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0042A408
// Name: __unwind_handler
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _unwind_handler(int a1, int a2, int a3, _DWORD *a4, int a5)
{
  int result; // eax

  result = 1;
  if ( (*(_DWORD *)(a1 + 4) & 6) != 0 )
  {
    _local_unwind2(a1: *(_DWORD *)(a5 + 36), a2: *(_DWORD *)(a5 + 40));
    *a4 = a2;
    return 3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042A44D
// Name: __local_unwind2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _local_unwind2(int a1, unsigned int a2)
{
  int result; // eax
  int v3; // ebx
  unsigned int v4; // esi
  int v5; // esi
  int v6; // ecx
  int v7; // [esp-4h] [ebp-24h]
  struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // [esp+0h] [ebp-20h]

  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  while ( 1 )
  {
    result = a1;
    v3 = *(_DWORD *)(a1 + 8);
    v4 = *(_DWORD *)(a1 + 12);
    if ( v4 == -1 || a2 != -1 && v4 <= a2 )
      break;
    v5 = 3 * v4;
    *(_DWORD *)(a1 + 12) = *(_DWORD *)(v3 + 4 * v5);
    if ( *(_DWORD *)(v3 + 4 * v5 + 4) == 0 )
    {
      _NLG_Notify(a1: 257);
      _NLG_Call(a1: v6, a2: v7, a3: ExceptionList);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042A4D1
// Name: __abnormal_termination
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _abnormal_termination()
{
  int result; // eax
  struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // ecx

  result = 0;
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  if ( (int (__cdecl *)(int, int, int, _DWORD *, int))ExceptionList->Handler == _unwind_handler )
    return ExceptionList[1].Next == *((_EXCEPTION_REGISTRATION_RECORD **)ExceptionList[1].Handler + 3);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042A4F4
// Name: __NLG_Notify1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall _NLG_Notify1(int a1)
{
  JUMPOUT(0x42A508);
}

//------------------------------------------------------------------------------
// Address: 0x0042A4FD
// Name: __NLG_Notify
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __userpurge _NLG_Notify@<eax>(unsigned int result@<eax>, unsigned int a2@<ebp>, unsigned int a3)
{
  _NLG_Destination.dwCode = a3;
  _NLG_Destination.uoffDestination = result;
  _NLG_Destination.uoffFramePointer = a2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042A51C
// Name: __NLG_Call
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _NLG_Call@<eax>(int (*a1)(void)@<eax>)
{
  return a1();
}

//------------------------------------------------------------------------------
// Address: 0x0042A51F
// Name: __crtCompareStringA_stat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall _crtCompareStringA_stat(
        localeinfo_struct *plocinfo,
        const char *lpString1,
        unsigned int Locale,
        DWORD dwCmpFlags,
        int cchCount1,
        const char *lpString2,
        int cchCount2,
        unsigned int code_page)
{
  int v10; // ecx
  const char *v11; // eax
  int v12; // edx
  LPCCH v13; // eax
  int v14; // ecx
  int result; // eax
  unsigned __int8 *LeadByte; // eax
  unsigned __int8 v17; // dl
  unsigned __int8 *i; // eax
  unsigned __int8 v19; // dl
  int v20; // eax
  int v21; // ebx
  unsigned int v22; // eax
  void *v23; // esp
  wchar_t *v24; // eax
  int v25; // eax
  int v26; // ebx
  unsigned int v27; // eax
  void *v28; // esp
  WCHAR *v29; // edi
  WCHAR *v30; // eax
  CHAR *v31; // edi
  char *v32; // ebx
  int v33; // eax
  int v34; // esi
  const CHAR *v35; // eax
  int v36; // esi
  _DWORD v38[2]; // [esp+0h] [ebp-38h] BYREF
  int v39; // [esp+8h] [ebp-30h] BYREF
  int buff_size1; // [esp+Ch] [ebp-2Ch]
  int retcode; // [esp+10h] [ebp-28h]
  LPCCH lpMultiByteStr; // [esp+14h] [ebp-24h]
  wchar_t *wbuffer1; // [esp+18h] [ebp-20h]
  LPCCH v44; // [esp+1Ch] [ebp-1Ch]
  _cpinfo lpCPInfo; // [esp+20h] [ebp-18h] BYREF

  lpMultiByteStr = lpString1;
  v44 = lpString2;
  if ( f_use_2 == 0 )
  {
    if ( CompareStringW(Locale: 0, dwCmpFlags: 0, lpString1: &String2, cchCount1: 1, lpString2: &String2, cchCount2: 1) != 0 )
    {
      f_use_2 = 1;
    }
    else if ( GetLastError() == 120 )
    {
      f_use_2 = 2;
    }
  }
  if ( cchCount1 <= 0 )
  {
    if ( cchCount1 < -1 )
      return 0;
  }
  else
  {
    v10 = cchCount1;
    v11 = lpString1;
    while ( 1 )
    {
      --v10;
      if ( *v11 == 0 )
        break;
      ++v11;
      if ( v10 == 0 )
      {
        v10 = -1;
        break;
      }
    }
    cchCount1 += -1 - v10;
  }
  v12 = cchCount2;
  if ( cchCount2 <= 0 )
  {
    if ( cchCount2 < -1 )
      return 0;
  }
  else
  {
    v13 = v44;
    v14 = cchCount2;
    while ( 1 )
    {
      --v14;
      if ( *v13 == 0 )
        break;
      ++v13;
      if ( v14 == 0 )
      {
        v14 = -1;
        break;
      }
    }
    v12 = -1 - v14 + cchCount2;
    cchCount2 = v12;
  }
  if ( f_use_2 == 2 || f_use_2 == 0 )
  {
    v31 = nullptr;
    v32 = nullptr;
    if ( Locale == 0 )
      Locale = plocinfo->locinfo->lc_handle[2];
    if ( code_page == 0 )
      code_page = plocinfo->locinfo->lc_codepage;
    v33 = __ansicp(lcid: Locale);
    v34 = v33;
    if ( v33 == -1 )
      return 0;
    if ( v33 != code_page )
    {
      v32 = __convertcp(
              fromCP: code_page,
              toCP: v33,
              lpSrcStr: lpMultiByteStr,
              pcchSrc: &cchCount1,
              lpDestStr: nullptr,
              cchDest: 0);
      if ( v32 == nullptr )
        return 0;
      v35 = __convertcp(
              fromCP: code_page,
              toCP: v34,
              lpSrcStr: v44,
              pcchSrc: &cchCount2,
              lpDestStr: nullptr,
              cchDest: 0);
      v31 = (CHAR *)v35;
      if ( v35 == nullptr )
      {
        free(pMem: v32);
        return 0;
      }
      lpMultiByteStr = v32;
      v44 = v35;
    }
    v36 = CompareStringA(Locale, dwCmpFlags, lpString1: lpMultiByteStr, cchCount1, lpString2: v44, cchCount2);
    if ( v32 != nullptr )
    {
      free(pMem: v32);
      free(pMem: v31);
    }
    return v36;
  }
  result = 1;
  if ( f_use_2 != 1 )
    return 0;
  retcode = 0;
  if ( code_page == 0 )
    code_page = plocinfo->locinfo->lc_codepage;
  if ( cchCount1 != 0 && v12 != 0 )
  {
LABEL_52:
    v20 = MultiByteToWideChar(
            CodePage: code_page,
            dwFlags: 9u,
            lpMultiByteStr: lpString1,
            cbMultiByte: cchCount1,
            lpWideCharStr: nullptr,
            cchWideChar: 0);
    v21 = v20;
    buff_size1 = v20;
    if ( v20 == 0 )
      return 0;
    if ( v20 <= 0 || 0xFFFFFFE0 / v20 < 2 )
    {
      wbuffer1 = nullptr;
LABEL_63:
      if ( wbuffer1 != nullptr )
      {
        if ( MultiByteToWideChar(
               CodePage: code_page,
               dwFlags: 1u,
               lpMultiByteStr,
               cbMultiByte: cchCount1,
               lpWideCharStr: wbuffer1,
               cchWideChar: v21) != 0 )
        {
          v25 = MultiByteToWideChar(
                  CodePage: code_page,
                  dwFlags: 9u,
                  lpMultiByteStr: v44,
                  cbMultiByte: cchCount2,
                  lpWideCharStr: nullptr,
                  cchWideChar: 0);
          v26 = v25;
          if ( v25 != 0 )
          {
            if ( v25 <= 0 || 0xFFFFFFE0 / v25 < 2 )
            {
              v29 = nullptr;
LABEL_75:
              if ( v29 != nullptr )
              {
                if ( MultiByteToWideChar(
                       CodePage: code_page,
                       dwFlags: 1u,
                       lpMultiByteStr: v44,
                       cbMultiByte: cchCount2,
                       lpWideCharStr: v29,
                       cchWideChar: v26) != 0 )
                  retcode = CompareStringW(
                              Locale,
                              dwCmpFlags,
                              lpString1: wbuffer1,
                              cchCount1: buff_size1,
                              lpString2: v29,
                              cchCount2: v26);
                _freea(_Memory: v29);
              }
              goto error_cleanup_0;
            }
            v27 = 2 * v25 + 8;
            if ( v27 > 0x400 )
            {
              v30 = (WCHAR *)operator new(nSize: 2 * v26 + 8);
              if ( v30 != nullptr )
              {
                *(_DWORD *)v30 = 56797;
                v30 += 4;
              }
              v29 = v30;
              goto LABEL_75;
            }
            v28 = alloca(v27);
            if ( v38 != nullptr )
            {
              v38[0] = 52428;
              v29 = (WCHAR *)&v39;
              goto LABEL_75;
            }
          }
        }
error_cleanup_0:
        _freea(_Memory: wbuffer1);
        return retcode;
      }
      return 0;
    }
    v22 = 2 * v20 + 8;
    if ( v22 > 0x400 )
    {
      v24 = (wchar_t *)operator new(nSize: 2 * v21 + 8);
      if ( v24 != nullptr )
      {
        *(_DWORD *)v24 = 56797;
        goto LABEL_60;
      }
    }
    else
    {
      v23 = alloca(v22);
      v24 = (wchar_t *)v38;
      if ( v38 != nullptr )
      {
        v38[0] = 52428;
LABEL_60:
        v24 += 4;
      }
    }
    wbuffer1 = v24;
    goto LABEL_63;
  }
  if ( cchCount1 == v12 )
    return 2;
  if ( v12 <= 1 )
  {
    if ( cchCount1 > 1 )
      return 3;
    if ( !GetCPInfo(CodePage: code_page, &lpCPInfo) )
      return 0;
    if ( cchCount1 > 0 )
    {
      if ( lpCPInfo.MaxCharSize >= 2 )
      {
        LeadByte = lpCPInfo.LeadByte;
        if ( lpCPInfo.LeadByte[0] != 0 )
        {
          while ( 1 )
          {
            v17 = LeadByte[1];
            if ( v17 == 0 )
              break;
            if ( (unsigned int)*lpString1 >= *LeadByte && (unsigned int)*lpString1 <= v17 )
              return 2;
            LeadByte += 2;
            if ( *LeadByte == 0 )
              return 3;
          }
        }
      }
      return 3;
    }
    if ( cchCount2 > 0 )
    {
      if ( lpCPInfo.MaxCharSize >= 2 )
      {
        for ( i = lpCPInfo.LeadByte; *i != 0; i += 2 )
        {
          v19 = i[1];
          if ( v19 == 0 )
            break;
          if ( (unsigned int)*v44 >= *i && (unsigned int)*v44 <= v19 )
            return 2;
        }
      }
      return 1;
    }
    goto LABEL_52;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042A8A8
// Name: ___crtCompareStringA
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __crtCompareStringA(
        localeinfo_struct *plocinfo,
        unsigned int Locale,
        DWORD dwCmpFlags,
        const char *lpString1,
        int cchCount1,
        const char *lpString2,
        int cchCount2,
        unsigned int code_page)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  result = _crtCompareStringA_stat(
             plocinfo: &_loc_update.localeinfo,
             lpString1,
             Locale,
             dwCmpFlags,
             cchCount1,
             lpString2,
             cchCount2,
             code_page);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042A8E8
// Name: __strnicoll_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _strnicoll_l@<eax>(
        unsigned int a1@<edi>,
        unsigned int a2@<esi>,
        const char *_string1,
        const char *_string2,
        unsigned int count,
        localeinfo_struct *plocinfo)
{
  int result; // eax
  unsigned int v7; // ecx
  int v8; // eax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( count == 0 )
  {
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0;
  }
  if ( _string1 != nullptr && _string2 != nullptr )
  {
    if ( count > 0x7FFFFFFF )
    {
      *_errno() = 22;
      _invalid_parameter(a1: 0, a2: a1, a3: 0x7FFFFFFFu);
LABEL_16:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 0x7FFFFFFF;
    }
    v7 = _loc_update.localeinfo.locinfo->lc_handle[1];
    if ( v7 != 0 )
    {
      v8 = __crtCompareStringA(
             plocinfo: &_loc_update.localeinfo,
             Locale: v7,
             dwCmpFlags: 0x1001u,
             lpString1: _string1,
             cchCount1: count,
             lpString2: _string2,
             cchCount2: count,
             code_page: _loc_update.localeinfo.locinfo->lc_collate_cp);
      if ( v8 == 0 )
      {
        *_errno() = 22;
        goto LABEL_16;
      }
      result = v8 - 2;
    }
    else
    {
      result = _strnicmp_l(dst: _string1, src: _string2, count, plocinfo: &_loc_update.localeinfo);
    }
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(a1: 0, a2: a1, a3: a2);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042A9E0
// Name: __dospawn
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _dospawn@<eax>(
        unsigned int a1@<edi>,
        unsigned int a2@<esi>,
        int mode,
        const char *name,
        char *cmdblk,
        char *envblk)
{
  void *hProcess; // ebx
  char *v7; // eax
  int v9; // esi
  signed int v10; // eax
  unsigned __int8 *v11; // eax
  unsigned __int8 *lpReserved2; // eax
  unsigned __int8 *v13; // ecx
  unsigned __int8 *v14; // edi
  ioinfo *v15; // eax
  char osfile; // dl
  _BYTE *v17; // ecx
  int v18; // edx
  unsigned __int8 *j; // eax
  int v20; // edi
  BOOL v21; // esi
  DWORD LastError; // edi
  _STARTUPINFOA StartupInfo; // [esp+8h] [ebp-68h] BYREF
  _PROCESS_INFORMATION ProcessInformation; // [esp+4Ch] [ebp-24h] BYREF
  unsigned int exitcode; // [esp+5Ch] [ebp-14h] BYREF
  char *CommandLine; // [esp+60h] [ebp-10h]
  unsigned int fdwCreate; // [esp+64h] [ebp-Ch]
  int i; // [esp+68h] [ebp-8h]
  char background; // [esp+6Fh] [ebp-1h]

  hProcess = nullptr;
  fdwCreate = 0;
  background = 0;
  if ( (unsigned int)mode >= 2 )
  {
    if ( mode <= 1 )
      goto LABEL_7;
    if ( mode > 3 )
    {
      if ( mode == 4 )
      {
        background = 1;
        goto LABEL_6;
      }
LABEL_7:
      *__doserrno() = 0;
      *_errno() = 22;
      _invalid_parameter(a1: 0, a2: a1, a3: a2);
      return -1;
    }
  }
LABEL_6:
  v7 = cmdblk;
  CommandLine = cmdblk;
  while ( *v7 != 0 )
  {
    do
      ++v7;
    while ( *v7 != 0 );
    if ( v7[1] != 0 )
      *v7++ = 32;
  }
  memset(dst: (int)&StartupInfo, value: nullptr, count: sizeof(StartupInfo));
  StartupInfo.cb = 68;
  v9 = _nhandle;
  if ( _nhandle == 0 )
    goto LABEL_47;
  v10 = _nhandle - 1;
  do
  {
    if ( __pioinfo[v10 >> 5][v10 & 0x1F].osfile != 0 )
      break;
    --v9;
    --v10;
  }
  while ( v9 != 0 );
  if ( v9 >= 0 )
  {
LABEL_47:
    if ( (unsigned int)v9 < 0x3332 )
    {
      StartupInfo.cbReserved2 = 5 * v9 + 4;
      v11 = (unsigned __int8 *)calloc(count: StartupInfo.cbReserved2, size: 1u);
      StartupInfo.lpReserved2 = v11;
      if ( v11 != nullptr )
      {
        *(_DWORD *)v11 = v9;
        lpReserved2 = StartupInfo.lpReserved2;
        v13 = StartupInfo.lpReserved2 + 4;
        v14 = &StartupInfo.lpReserved2[v9 + 4];
        i = 0;
        if ( v9 > 0 )
        {
          do
          {
            v15 = &__pioinfo[i >> 5][i & 0x1F];
            osfile = v15->osfile;
            if ( (osfile & 0x10) != 0 )
            {
              *v13 = 0;
              *(_DWORD *)v14 = -1;
            }
            else
            {
              *v13 = osfile;
              *(_DWORD *)v14 = v15->osfhnd;
            }
            ++i;
            ++v13;
            v14 += 4;
          }
          while ( i < v9 );
          lpReserved2 = StartupInfo.lpReserved2;
        }
        if ( background != 0 )
        {
          v17 = lpReserved2 + 4;
          v18 = 0;
          for ( j = &lpReserved2[v9 + 4]; ; j += 4 )
          {
            v20 = v9 >= 3 ? 3 : v9;
            if ( v18 >= v20 )
              break;
            *v17 = 0;
            *(_DWORD *)j = -1;
            ++v18;
            ++v17;
          }
          fdwCreate = 8;
        }
        *__doserrno() = 0;
        v21 = CreateProcessA(
                lpApplicationName: name,
                lpCommandLine: CommandLine,
                lpProcessAttributes: nullptr,
                lpThreadAttributes: nullptr,
                bInheritHandles: true,
                dwCreationFlags: fdwCreate,
                lpEnvironment: envblk,
                lpCurrentDirectory: nullptr,
                lpStartupInfo: &StartupInfo,
                lpProcessInformation: &ProcessInformation);
        LastError = GetLastError();
        free(pMem: StartupInfo.lpReserved2);
        if ( v21 )
        {
          if ( mode == 2 )
            _exit(code: 0);
          if ( mode != 0 )
          {
            if ( mode != 4 )
            {
              hProcess = ProcessInformation.hProcess;
              goto LABEL_42;
            }
          }
          else
          {
            WaitForSingleObject(hHandle: ProcessInformation.hProcess, dwMilliseconds: 0xFFFFFFFF);
            GetExitCodeProcess(hProcess: ProcessInformation.hProcess, lpExitCode: &exitcode);
            hProcess = (void *)exitcode;
          }
          CloseHandle(hObject: ProcessInformation.hProcess);
LABEL_42:
          CloseHandle(hObject: ProcessInformation.hThread);
          return (int)hProcess;
        }
        _dosmaperr(oserrno: LastError);
        return -1;
      }
    }
  }
  *_errno() = 12;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0042ABED
// Name: __cenvarg
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _cenvarg(const char **argv, char **envp, char **argblk, char **envblk)
{
  const char *const *v4; // edi
  char *v5; // eax
  unsigned int v6; // esi
  int v7; // eax
  char *v8; // eax
  void **v9; // esi
  int v11; // eax
  unsigned int v12; // edx
  unsigned int v13; // ecx
  int v14; // eax
  int v15; // edi
  int v16; // eax
  char **v17; // esi
  char *v18; // eax
  int v19; // edi
  int v20; // eax
  char *EnvironmentStringsA; // eax
  const char **v22; // edi
  char *v23; // esi
  char *v24; // esi
  char v25; // cl
  char *v26; // esi
  int v27; // eax
  int v28; // ecx
  char *v29; // ecx
  int v30; // eax
  char *v31; // eax
  const unsigned __int8 **v32; // esi
  unsigned int v33; // edi
  unsigned int v34; // eax
  char *v35; // eax
  unsigned int v36; // eax
  unsigned int v37; // edx
  unsigned int v38; // ecx
  int v39; // eax
  unsigned int v40; // eax
  unsigned int v41; // edx
  unsigned int v42; // ecx
  int v43; // eax
  char *v44; // esi
  unsigned __int8 *v45; // esi
  const char **i; // edi
  unsigned int v47; // eax
  unsigned int v48; // edx
  unsigned int v49; // ecx
  int v50; // eax
  unsigned int v51; // eax
  unsigned int v52; // edx
  unsigned int v53; // ecx
  unsigned int v54; // eax
  unsigned int v55; // edx
  unsigned int v56; // ecx
  unsigned int v57; // eax
  unsigned int v58; // edx
  unsigned int v59; // ecx
  unsigned int env_len; // [esp+Ch] [ebp-40h]
  int defined; // [esp+10h] [ebp-3Ch]
  unsigned int v62; // [esp+18h] [ebp-34h]
  unsigned int envsize; // [esp+1Ch] [ebp-30h]
  int cwd_end; // [esp+24h] [ebp-28h]
  int retval; // [esp+28h] [ebp-24h]
  int cwd_start; // [esp+30h] [ebp-1Ch]
  char *envbuf; // [esp+38h] [ebp-14h] BYREF
  char envpfx[12]; // [esp+3Ch] [ebp-10h] BYREF

  strcpy(envpfx, "SystemRoot");
  v4 = argv;
  v5 = (char *)*argv;
  retval = 0;
  envbuf = nullptr;
  defined = 0;
  v6 = 2;
  while ( v5 != nullptr )
  {
    strlen(buf: v5);
    ++v4;
    v6 += v7 + 1;
    v5 = (char *)*v4;
  }
  v62 = v6;
  v8 = (char *)calloc(count: v6, size: 1u);
  v9 = (void **)argblk;
  *argblk = v8;
  if ( v8 == nullptr )
  {
    *envblk = nullptr;
    *_errno() = 12;
    *__doserrno() = 8;
    return -1;
  }
  v11 = _dupenv_s(pBuffer: &envbuf, pBufferSizeInTChars: nullptr, varname: envpfx);
  if ( v11 != 0 )
  {
    if ( v11 == 22 )
      _invoke_watson(a1: 0x16u, a2: v12, a3: v13, a4: 0, a5: (unsigned int)v4, a6: (unsigned int)argblk);
    goto LABEL_18;
  }
  strlen(buf: envpfx);
  v15 = v14 + 2;
  envsize = v14 + 2;
  if ( envbuf != nullptr )
  {
    strlen(buf: envbuf);
    envsize = v16 + v15;
  }
  if ( envp == nullptr )
  {
    *envblk = nullptr;
    goto LABEL_20;
  }
  v17 = envp;
  v18 = *envp;
  v19 = 2;
  while ( v18 != nullptr )
  {
    strlen(buf: v18);
    ++v17;
    v19 += v20 + 1;
    v18 = *v17;
  }
  EnvironmentStringsA = _aenvptr;
  if ( _aenvptr != nullptr
    || (EnvironmentStringsA = (char *)__crtGetEnvironmentStringsA(),
        _aenvptr = EnvironmentStringsA,
        EnvironmentStringsA != nullptr) )
  {
    cwd_start = 0;
    if ( *EnvironmentStringsA != 0 )
    {
      v25 = *EnvironmentStringsA;
      v26 = EnvironmentStringsA;
      do
      {
        if ( v25 == 61 )
          break;
        strlen(buf: v26);
        v28 = cwd_start + v27 + 1;
        EnvironmentStringsA = _aenvptr;
        v26 = &_aenvptr[v28];
        cwd_start = v28;
        v25 = _aenvptr[v28];
      }
      while ( v25 != 0 );
    }
    v29 = (char *)cwd_start;
    for ( cwd_end = cwd_start; ; cwd_end = (int)EnvironmentStringsA )
    {
      v31 = &EnvironmentStringsA[(_DWORD)v29];
      if ( *v31 != 61 || v31[1] == 0 || v31[2] != 58 || v31[3] != 61 )
        break;
      strlen(buf: v31 + 4);
      EnvironmentStringsA = (char *)(cwd_end + v30 + 5);
      v29 = _aenvptr;
    }
    v32 = (const unsigned __int8 **)envp;
    v33 = cwd_end - cwd_start + v19;
    env_len = v33;
    while ( 1 )
    {
      if ( *v32 == nullptr )
      {
        v33 += envsize;
        goto LABEL_37;
      }
      strlen(buf: envpfx);
      if ( _mbsnicmp(s1: *v32, s2: (const unsigned __int8 *)envpfx, n: v34) == 0 )
        break;
      ++v32;
    }
    defined = 1;
LABEL_37:
    v35 = (char *)calloc(count: v33, size: 1u);
    v9 = (void **)argblk;
    *envblk = v35;
    if ( v35 == nullptr )
    {
      free(pMem: *argblk);
      *argblk = nullptr;
      *_errno() = 12;
      retval = -1;
      *__doserrno() = 8;
      goto done;
    }
LABEL_20:
    v22 = argv;
    v23 = (char *)*v9;
    if ( *argv != nullptr )
    {
      v36 = strcpy_s(a1: (unsigned int)argv, _Dst: v23, _SizeInBytes: v62, _Src: *argv);
      if ( v36 != 0 )
        _invoke_watson(a1: v36, a2: v37, a3: v38, a4: 0, a5: (unsigned int)argv, a6: (unsigned int)v23);
      strlen(buf: (char *)*argv);
      v24 = &v23[v39 + 1];
      v22 = argv + 1;
    }
    else
    {
      v24 = v23 + 1;
    }
    while ( *v22 != nullptr )
    {
      v40 = strcpy_s(a1: (unsigned int)v22, _Dst: v24, _SizeInBytes: v62 + *argblk - v24, _Src: *v22);
      if ( v40 != 0 )
        _invoke_watson(a1: v40, a2: v41, a3: v42, a4: 0, a5: (unsigned int)v22, a6: (unsigned int)v24);
      strlen(buf: (char *)*v22);
      v44 = &v24[v43];
      ++v22;
      *v44 = 32;
      v24 = v44 + 1;
    }
    *(v24 - 1) = 0;
    *v24 = 0;
    v45 = (unsigned __int8 *)*envblk;
    if ( envp != nullptr )
    {
      memcpy(dst: v45, src: (unsigned __int8 *)&_aenvptr[cwd_start], count: cwd_end - cwd_start);
      v45 += cwd_end - cwd_start;
      for ( i = (const char **)envp; *i != nullptr; ++i )
      {
        v47 = strcpy_s(
                a1: (unsigned int)i,
                _Dst: (char *)v45,
                _SizeInBytes: (unsigned int)&(*envblk)[env_len - (_DWORD)v45],
                _Src: *i);
        if ( v47 != 0 )
          _invoke_watson(a1: v47, a2: v48, a3: v49, a4: 0, a5: (unsigned int)i, a6: (unsigned int)v45);
        strlen(buf: (char *)*i);
        v45 += v50 + 1;
      }
      if ( defined == 0 )
      {
        v51 = strcpy_s(a1: envsize, _Dst: (char *)v45, _SizeInBytes: envsize, _Src: envpfx);
        if ( v51 != 0 )
          _invoke_watson(a1: v51, a2: v52, a3: v53, a4: 0, a5: envsize, a6: (unsigned int)v45);
        v54 = strcat_s(a1: envsize, _Dst: (char *)v45, _SizeInBytes: envsize, _Src: "=");
        if ( v54 != 0 )
          _invoke_watson(a1: v54, a2: v55, a3: v56, a4: 0, a5: envsize, a6: (unsigned int)v45);
        if ( envbuf != nullptr )
        {
          v57 = strcat_s(a1: envsize, _Dst: (char *)v45, _SizeInBytes: envsize, _Src: envbuf);
          if ( v57 != 0 )
            _invoke_watson(a1: v57, a2: v58, a3: v59, a4: 0, a5: envsize, a6: (unsigned int)v45);
        }
        v45 += envsize;
      }
    }
    if ( v45 != nullptr )
    {
      if ( v45 == (unsigned __int8 *)*envblk )
        *v45++ = 0;
      *v45 = 0;
    }
    goto done;
  }
  v9 = (void **)argblk;
LABEL_18:
  retval = -1;
  free(pMem: *v9);
  *v9 = nullptr;
  *envblk = nullptr;
done:
  if ( _aenvptr != nullptr )
    free(pMem: _aenvptr);
  _aenvptr = nullptr;
  if ( envbuf != nullptr )
    free(pMem: envbuf);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x0042AFC4
// Name: __mbsrchr_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _mbsrchr_l(unsigned int a1@<edi>, unsigned __int8 *str, unsigned int c, localeinfo_struct *plocinfo)
{
  threadmbcinfostruct *mbcinfo; // esi
  char *v5; // ecx
  unsigned __int8 v6; // dl
  int v7; // eax
  bool v8; // zf
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-14h] BYREF
  char *r; // [esp+18h] [ebp-4h]

  r = nullptr;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  mbcinfo = _loc_update.localeinfo.mbcinfo;
  if ( _loc_update.localeinfo.mbcinfo->ismbcodepage == 0 )
  {
    strrchr(string: str, chr: c);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return;
  }
  v5 = (char *)str;
  if ( str == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter(a1: 0, a2: a1, a3: (unsigned int)mbcinfo);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return;
  }
  do
  {
    v6 = *v5;
    v7 = (unsigned __int8)*v5;
    if ( (_loc_update.localeinfo.mbcinfo->mbctype[(unsigned __int8)v7 + 1] & 4) != 0 )
    {
      v6 = *++v5;
      if ( *v5 != 0 )
      {
        if ( c == (v6 | (v7 << 8)) )
          r = v5 - 1;
        goto LABEL_16;
      }
      v8 = r == nullptr;
    }
    else
    {
      v8 = c == v7;
    }
    if ( v8 )
      r = v5;
LABEL_16:
    ++v5;
  }
  while ( v6 != 0 );
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
}

//------------------------------------------------------------------------------
// Address: 0x0042B084
// Name: __mbsrchr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _mbsrchr(unsigned int a1@<edi>, unsigned __int8 *str, unsigned int c)
{
  _mbsrchr_l(a1, str, c, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0042B097
// Name: __wcsnicoll_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _wcsnicoll_l@<eax>(
        unsigned int a1@<edi>,
        unsigned int a2@<esi>,
        const wchar_t *_string1,
        const wchar_t *_string2,
        unsigned int count,
        localeinfo_struct *plocinfo)
{
  int result; // eax
  const wchar_t *v7; // edi
  unsigned int v8; // ecx
  wchar_t v9; // ax
  wchar_t v10; // cx
  wchar_t v11; // ax
  int v12; // eax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  if ( count == 0 )
    return 0;
  if ( _string1 == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter(a1: 0, a2: a1, a3: a2);
    return 0x7FFFFFFF;
  }
  v7 = _string2;
  if ( _string2 == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter(a1: 0, a2: 0, a3: a2);
    return 0x7FFFFFFF;
  }
  if ( count > 0x7FFFFFFF )
  {
    *_errno() = 22;
    _invalid_parameter(a1: 0, a2: (unsigned int)_string2, a3: 0x7FFFFFFFu);
    return 0x7FFFFFFF;
  }
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  v8 = _loc_update.localeinfo.locinfo->lc_handle[1];
  if ( v8 != 0 )
  {
    v12 = __crtCompareStringW(
            plocinfo: &_loc_update.localeinfo,
            Locale: v8,
            dwCmpFlags: 0x1001u,
            lpString1: _string1,
            cchCount1: count,
            lpString2: _string2,
            cchCount2: count,
            code_page: _loc_update.localeinfo.locinfo->lc_collate_cp);
    if ( v12 == 0 )
    {
      *_errno() = 22;
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 0x7FFFFFFF;
    }
    result = v12 - 2;
  }
  else
  {
    do
    {
      v9 = *_string1;
      if ( *_string1 >= 0x41u && v9 <= 0x5Au )
        v9 += 32;
      v10 = v9;
      v11 = *v7;
      if ( *v7 >= 0x41u && v11 <= 0x5Au )
        v11 += 32;
      ++_string1;
      ++v7;
      --count;
    }
    while ( count != 0 && v10 != 0 && v10 == v11 );
    result = v10 - v11;
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042B1D8
// Name: __wcsnicoll
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _wcsnicoll@<eax>(
        unsigned int a1@<esi>,
        const wchar_t *_string1,
        const wchar_t *_string2,
        unsigned int count)
{
  const wchar_t *v4; // ebx
  const wchar_t *v6; // edx
  wchar_t v7; // ax
  wchar_t v8; // cx
  wchar_t v9; // ax

  if ( __locale_changed != 0 )
    return _wcsnicoll_l(a1: 0, a2: a1, _string1, _string2, count, plocinfo: nullptr);
  v4 = _string1;
  if ( _string1 != nullptr && (v6 = _string2, _string2 != nullptr) && count <= 0x7FFFFFFF )
  {
    do
    {
      v7 = *v4;
      if ( *v4 >= 0x41u && v7 <= 0x5Au )
        v7 += 32;
      v8 = v7;
      v9 = *v6;
      if ( *v6 >= 0x41u && v9 <= 0x5Au )
        v9 += 32;
      ++v4;
      ++v6;
      --count;
    }
    while ( count != 0 && v8 != 0 && v8 == v9 );
    return v8 - v9;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(a1: (unsigned int)_string1, a2: 0, a3: a1);
    return 0x7FFFFFFF;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042B27A
// Name: _wcscpy_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall wcscpy_s@<eax>(
        unsigned int a1@<ebx>,
        unsigned __int16 *_Dst,
        unsigned int _SizeInWords,
        const wchar_t *_Src)
{
  unsigned int v4; // esi
  const wchar_t *v6; // esi
  unsigned __int16 *v7; // edx
  wchar_t v8; // ax

  if ( _Dst == nullptr )
    goto LABEL_3;
  a1 = _SizeInWords;
  if ( _SizeInWords == 0 )
    goto LABEL_3;
  v6 = _Src;
  if ( _Src == nullptr )
  {
    *_Dst = 0;
LABEL_3:
    v4 = 22;
    *_errno() = 22;
LABEL_4:
    _invalid_parameter(a1, a2: 0, a3: v4);
    return v4;
  }
  v7 = _Dst;
  do
  {
    v8 = *v6;
    *v7++ = *v6++;
    if ( v8 == 0 )
      break;
    --a1;
  }
  while ( a1 != 0 );
  if ( a1 == 0 )
  {
    *_Dst = 0;
    *_errno() = 34;
    v4 = 34;
    goto LABEL_4;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0042B2E6
// Name: ___mbtow_environ
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __mbtow_environ()
{
  LPCCH *v0; // esi
  const CHAR *v1; // eax
  unsigned int v2; // eax
  unsigned __int16 *v3; // eax
  int size; // [esp+Ch] [ebp-8h]
  unsigned __int16 *wenvp; // [esp+10h] [ebp-4h] BYREF

  v0 = (LPCCH *)_environ;
  wenvp = nullptr;
  v1 = *_environ;
  if ( *_environ == nullptr )
    return 0;
  while ( 1 )
  {
    v2 = MultiByteToWideChar(
           CodePage: 0,
           dwFlags: 0,
           lpMultiByteStr: v1,
           cbMultiByte: -1,
           lpWideCharStr: nullptr,
           cchWideChar: 0);
    size = v2;
    if ( v2 == 0 )
      return -1;
    v3 = (unsigned __int16 *)calloc(count: v2, size: 2u);
    wenvp = v3;
    if ( v3 == nullptr )
      return -1;
    if ( MultiByteToWideChar(
           CodePage: 0,
           dwFlags: 0,
           lpMultiByteStr: *v0,
           cbMultiByte: -1,
           lpWideCharStr: v3,
           cchWideChar: size) == 0 )
      goto LABEL_10;
    if ( __crtwsetenv(a1: 0, a2: (unsigned int)MultiByteToWideChar, poption: &wenvp, primary: 0) < 0 )
    {
      if ( wenvp == nullptr )
        return -1;
LABEL_10:
      free(pMem: wenvp);
      return -1;
    }
    v1 = *++v0;
    if ( *v0 == nullptr )
      return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042B36B
// Name: __wsetenvp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _wsetenvp()
{
  wchar_t *v0; // esi
  int v1; // edi
  unsigned __int16 **v3; // ebx
  wchar_t *i; // esi
  int v5; // eax
  unsigned int v6; // edi
  unsigned __int16 *v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // edx
  unsigned int v10; // ecx

  v0 = _wenvptr;
  v1 = 0;
  if ( _wenvptr == nullptr )
    return -1;
  while ( *v0 != 0 )
  {
    if ( *v0 != 61 )
      ++v1;
    v0 += wcslen(wcs: v0) + 1;
  }
  v3 = (unsigned __int16 **)calloc(count: v1 + 1, size: 4u);
  _wenviron = v3;
  if ( v3 == nullptr )
    return -1;
  for ( i = _wenvptr; ; i += v6 )
  {
    if ( *i == 0 )
    {
      free(pMem: _wenvptr);
      _wenvptr = nullptr;
      *v3 = nullptr;
      __env_initialized = 1;
      return 0;
    }
    v5 = wcslen(wcs: i);
    v6 = v5 + 1;
    if ( *i != 61 )
      break;
LABEL_15:
    ;
  }
  v7 = (unsigned __int16 *)calloc(count: v5 + 1, size: 2u);
  *v3 = v7;
  if ( v7 != nullptr )
  {
    v8 = wcscpy_s(a1: (unsigned int)v3, _Dst: v7, _SizeInWords: v6, _Src: i);
    if ( v8 != 0 )
      _invoke_watson(a1: v8, a2: v9, a3: v10, a4: (unsigned int)v3, a5: v6, a6: (unsigned int)i);
    ++v3;
    goto LABEL_15;
  }
  free(pMem: _wenviron);
  _wenviron = nullptr;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0042B445
// Name: ___crtGetEnvironmentStringsW
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl __crtGetEnvironmentStringsW()
{
  int v0; // eax
  int v1; // edi
  unsigned __int8 *EnvironmentStringsW; // esi
  unsigned __int8 *j; // eax
  unsigned int v5; // ebp
  unsigned __int8 *v6; // eax
  unsigned __int8 *v7; // ebx
  LPCH EnvironmentStrings; // eax
  char *v9; // ebp
  CHAR *i; // esi
  int v11; // eax
  int v12; // eax
  unsigned __int8 *v13; // eax
  char *v14; // edi
  wchar_t *v15; // esi
  int v16; // eax
  int v17; // [esp+10h] [ebp-4h]

  v0 = f_use_3;
  v1 = 0;
  EnvironmentStringsW = nullptr;
  if ( f_use_3 == 0 )
  {
    EnvironmentStringsW = (unsigned __int8 *)GetEnvironmentStringsW();
    if ( EnvironmentStringsW != nullptr )
    {
      f_use_3 = 1;
      goto LABEL_8;
    }
    if ( GetLastError() == 120 )
    {
      v0 = 2;
      f_use_3 = 2;
    }
    else
    {
      v0 = f_use_3;
    }
  }
  if ( v0 != 1 )
  {
    if ( v0 != 2 && v0 != 0 )
      return nullptr;
    EnvironmentStrings = GetEnvironmentStrings();
    v9 = EnvironmentStrings;
    if ( EnvironmentStrings == nullptr )
      return nullptr;
    for ( i = EnvironmentStrings; *i != 0; i += v12 + 1 )
    {
      v11 = MultiByteToWideChar(
              CodePage: 0,
              dwFlags: 1u,
              lpMultiByteStr: i,
              cbMultiByte: -1,
              lpWideCharStr: nullptr,
              cchWideChar: 0);
      if ( v11 == 0 )
        return nullptr;
      v1 += v11;
      strlen(buf: i);
    }
    v17 = v1 + 1;
    v13 = (unsigned __int8 *)calloc(count: v1 + 1, size: 2u);
    v7 = v13;
    if ( v13 != nullptr )
    {
      v14 = v9;
      v15 = (wchar_t *)v13;
      if ( *v9 == 0 )
      {
LABEL_28:
        *v15 = 0;
        FreeEnvironmentStringsA(penv: v9);
        return v7;
      }
      while ( MultiByteToWideChar(
                CodePage: 0,
                dwFlags: 1u,
                lpMultiByteStr: v14,
                cbMultiByte: -1,
                lpWideCharStr: v15,
                cchWideChar: v17 - (((char *)v15 - (char *)v7) >> 1)) != 0 )
      {
        strlen(buf: v14);
        v14 += v16 + 1;
        v15 += wcslen(wcs: v15) + 1;
        if ( *v14 == 0 )
          goto LABEL_28;
      }
      free(pMem: v7);
    }
    FreeEnvironmentStringsA(penv: v9);
    return nullptr;
  }
LABEL_8:
  if ( EnvironmentStringsW == nullptr )
  {
    EnvironmentStringsW = (unsigned __int8 *)GetEnvironmentStringsW();
    if ( EnvironmentStringsW == nullptr )
      return nullptr;
  }
  for ( j = EnvironmentStringsW; *(_WORD *)j != 0; j += 2 )
  {
    do
      j += 2;
    while ( *(_WORD *)j != 0 );
  }
  v5 = j - EnvironmentStringsW + 2;
  v6 = (unsigned __int8 *)operator new(nSize: v5);
  v7 = v6;
  if ( v6 != nullptr )
    memcpy(dst: v6, src: EnvironmentStringsW, count: v5);
  FreeEnvironmentStringsW(penv: (LPWCH)EnvironmentStringsW);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x0042B5A6
// Name: _wcschr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int16 *__cdecl wcschr(const wchar_t *string, wchar_t ch)
{
  unsigned __int16 *result; // eax

  for ( result = (unsigned __int16 *)string; *result != 0; ++result )
  {
    if ( *result == ch )
      return result;
  }
  if ( *result != ch )
    return nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042B5C8
// Name: ___report_gsfailure
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn __report_gsfailure()
{
  unsigned int v0; // eax
  unsigned int v1; // edx
  unsigned int v2; // ecx
  unsigned int v3; // ebx
  unsigned int v4; // edi
  unsigned int v5; // esi
  unsigned int v6; // kr00_4
  HANDLE CurrentProcess; // eax
  unsigned int vars0; // [esp+328h] [ebp+0h]
  void *retaddr; // [esp+32Ch] [ebp+4h]
  char v10; // [esp+330h] [ebp+8h] BYREF

  GS_ContextRecord.Eax = v0;
  GS_ContextRecord.Ecx = v2;
  GS_ContextRecord.Edx = v1;
  GS_ContextRecord.Ebx = v3;
  GS_ContextRecord.Esi = v5;
  GS_ContextRecord.Edi = v4;
  LOWORD(GS_ContextRecord.SegSs) = __SS__;
  LOWORD(GS_ContextRecord.SegCs) = __CS__;
  LOWORD(GS_ContextRecord.SegDs) = __DS__;
  LOWORD(GS_ContextRecord.SegEs) = __ES__;
  LOWORD(GS_ContextRecord.SegFs) = __FS__;
  LOWORD(GS_ContextRecord.SegGs) = __GS__;
  v6 = __readeflags();
  GS_ContextRecord.EFlags = v6;
  GS_ContextRecord.Ebp = vars0;
  GS_ContextRecord.Eip = (unsigned int)retaddr;
  GS_ContextRecord.Esp = (unsigned int)&v10;
  GS_ContextRecord.ContextFlags = 65537;
  GS_ExceptionRecord.ExceptionAddress = retaddr;
  GS_ExceptionRecord.ExceptionCode = -1073740791;
  GS_ExceptionRecord.ExceptionFlags = 1;
  DebuggerWasPresent = IsDebuggerPresent();
  _crt_debugger_hook();
  SetUnhandledExceptionFilter(lpTopLevelExceptionFilter: nullptr);
  UnhandledExceptionFilter(ExceptionInfo: &GS_ExceptionPointers);
  if ( DebuggerWasPresent == 0 )
    _crt_debugger_hook();
  CurrentProcess = GetCurrentProcess();
  TerminateProcess(hProcess: CurrentProcess, uExitCode: 0xC0000409);
}

//------------------------------------------------------------------------------
// Address: 0x0042B6CC
// Name: __87except
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _87except(int opcode, _exception *exc, unsigned __int16 *pcw16)
{
  unsigned int v3; // ecx
  bool v4; // zf
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // ebx
  unsigned int v12; // [esp+100h] [ebp-94h]
  unsigned int pcw; // [esp+110h] [ebp-84h] BYREF
  _FPIEEE_RECORD prec; // [esp+114h] [ebp-80h] BYREF

  v3 = *pcw16;
  v5 = exc->type - 1;
  v4 = exc->type == 1;
  pcw = v3;
  if ( v4 )
    goto LABEL_13;
  v6 = v5 - 1;
  if ( v6 == 0 )
  {
    v12 = 4;
    goto LABEL_14;
  }
  v7 = v6 - 1;
  if ( v7 == 0 )
  {
    v12 = 17;
    goto LABEL_14;
  }
  v8 = v7 - 1;
  if ( v8 == 0 )
  {
    v12 = 18;
    goto LABEL_14;
  }
  v9 = v8 - 1;
  if ( v9 == 0 )
  {
LABEL_13:
    v12 = 8;
LABEL_14:
    v11 = v12;
    if ( _handle_exc(flags: v12, presult: &exc->retval, cw: v3) == 0 )
    {
      if ( opcode == 16 || opcode == 22 || opcode == 29 )
      {
        prec.Operand2.Value.Fp64Value = exc->arg2;
        *((_DWORD *)&prec.Operand2 + 4) = *((_DWORD *)&prec.Operand2 + 4) & 0xFFFFFFE0 | 3;
      }
      else
      {
        *((_DWORD *)&prec.Operand2 + 4) &= ~1u;
      }
      _raise_exc(&prec, &pcw, flags: v11, opcode, parg1: &exc->arg1, presult: &exc->retval);
    }
    goto LABEL_21;
  }
  v10 = v9 - 2;
  if ( v10 == 0 )
  {
    exc->type = 1;
    goto LABEL_21;
  }
  if ( v10 == 1 )
  {
    v12 = 16;
    goto LABEL_14;
  }
LABEL_21:
  _ctrlfp(newctrl: pcw, _mask: 0xFFFFu);
  if ( exc->type == 8 || _matherr_flag != 0 || _matherr(pexcept: exc) == 0 )
    _set_errno_from_matherr(matherrtype: exc->type);
}

//------------------------------------------------------------------------------
// Address: 0x0042B7C8
// Name: __frnd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _frnd(long double x)
{
  return rint(x);
}

//------------------------------------------------------------------------------
// Address: 0x0042B7D9
// Name: __fpclass
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fpclass(long double x)
{
  int v1; // eax
  int v2; // eax
  int v4; // ecx

  if ( (HIWORD(x) & 0x7FF0) == 0x7FF0 )
  {
    v1 = _sptype(x) - 1;
    if ( v1 != 0 )
    {
      v2 = v1 - 1;
      if ( v2 == 0 )
        return 4;
      if ( v2 != 1 )
        return 1;
      return 2;
    }
    else
    {
      return 512;
    }
  }
  else
  {
    v4 = HIWORD(x) & 0x8000;
    if ( (HIWORD(x) & 0x7FF0) == 0 && ((HIDWORD(x) & 0xFFFFF) != 0 || LODWORD(x) != 0) )
    {
      return (HIWORD(x) & 0x8000) != 0 ? 16 : 128;
    }
    else if ( 0.0 == x )
    {
      return v4 != 0 ? 32 : 64;
    }
    else
    {
      return v4 != 0 ? 8 : 256;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042B86D
// Name: __set_exp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _set_exp(long double x, __int16 exp)
{
  long double retval; // [esp+0h] [ebp-8h]

  retval = x;
  HIWORD(retval) = HIWORD(x) & 0x800F | (16 * (exp + 1022));
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x0042B897
// Name: __sptype
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _sptype(long double x)
{
  if ( HIDWORD(x) == 2146435072 )
  {
    if ( LODWORD(x) == 0 )
      return 1;
  }
  else if ( x == -INFINITY )
  {
    return 2;
  }
  if ( (HIWORD(x) & 0x7FF8) == 0x7FF8 )
    return 3;
  if ( (HIWORD(x) & 0x7FF8) == 0x7FF0 && ((HIDWORD(x) & 0x7FFFF) != 0 || LODWORD(x) != 0) )
    return 4;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0042B8F2
// Name: __decomp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
long double __cdecl _decomp(long double x, int *pexp)
{
  long double result; // st7
  int v3; // edx
  int v4; // edx
  BOOL v5; // eax

  result = 0.0;
  if ( 0.0 == x )
  {
    v3 = 0;
  }
  else if ( (HIWORD(x) & 0x7FF0) == 0 && ((HIDWORD(x) & 0xFFFFF) != 0 || LODWORD(x) != 0) )
  {
    v4 = -1021;
    v5 = x < 0.0;
    while ( (BYTE6(x) & 0x10) == 0 )
    {
      HIDWORD(x) *= 2;
      if ( SLODWORD(x) < 0 )
        HIDWORD(x) |= 1u;
      LODWORD(x) *= 2;
      --v4;
    }
    HIWORD(x) &= ~0x10u;
    if ( v5 )
      HIWORD(x) |= 0x8000u;
    result = _set_exp(x, exp: 0);
  }
  else
  {
    result = _set_exp(x, exp: 0);
    v3 = ((*(_DWORD *)((char *)&x + 6) >> 4) & 0x7FF) - 1022;
  }
  *pexp = v3;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042B9A1
// Name: __matherr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _matherr()
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0042B9A4
// Name: __raise_exc_ex
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _raise_exc_ex(
        _FPIEEE_RECORD *prec,
        unsigned int *pcw,
        DWORD flags,
        int opcode,
        float *parg1,
        float *presult,
        int isfloat)
{
  char v7; // cl
  unsigned int *v8; // esi
  char v9; // al
  int v10; // eax
  _FPIEEE_RECORD *v11; // eax
  unsigned int v12; // ecx
  int v13; // eax
  _FPIEEE_RECORD *v14; // eax
  unsigned int v15; // ecx
  float *v16; // edi
  _FPIEEE_RECORD *v17; // ecx
  int v18; // eax
  int v19; // eax
  int v20; // eax
  unsigned int v21; // eax
  int v22; // eax
  int v23; // eax
  unsigned int v24; // eax

  v7 = flags;
  prec->Cause = 0;
  prec->Enable = 0;
  prec->Status = 0;
  if ( (v7 & 0x10) != 0 )
  {
    *(_DWORD *)&prec->Cause |= 1u;
    flags = -1073741681;
  }
  if ( (v7 & 2) != 0 )
  {
    *(_DWORD *)&prec->Cause |= 2u;
    flags = -1073741677;
  }
  if ( (v7 & 1) != 0 )
  {
    *(_DWORD *)&prec->Cause |= 4u;
    flags = -1073741679;
  }
  if ( (v7 & 4) != 0 )
  {
    *(_DWORD *)&prec->Cause |= 8u;
    flags = -1073741682;
  }
  if ( (v7 & 8) != 0 )
  {
    *(_DWORD *)&prec->Cause |= 0x10u;
    flags = -1073741680;
  }
  v8 = pcw;
  *(_DWORD *)&prec->Enable ^= (*(_DWORD *)&prec->Enable ^ ~(16 * *pcw)) & 0x10;
  *(_DWORD *)&prec->Enable ^= (*(_DWORD *)&prec->Enable ^ ~(2 * *v8)) & 8;
  *(_DWORD *)&prec->Enable ^= (*(_DWORD *)&prec->Enable ^ ~(*v8 >> 1)) & 4;
  *(_DWORD *)&prec->Enable ^= (*(_DWORD *)&prec->Enable ^ ~(*v8 >> 3)) & 2;
  *(_DWORD *)&prec->Enable ^= (*(_DWORD *)&prec->Enable ^ ~(*v8 >> 5)) & 1;
  v9 = _statfp();
  if ( (v9 & 1) != 0 )
    *(_DWORD *)&prec->Status |= 0x10u;
  if ( (v9 & 4) != 0 )
    *(_DWORD *)&prec->Status |= 8u;
  if ( (v9 & 8) != 0 )
    *(_DWORD *)&prec->Status |= 4u;
  if ( (v9 & 0x10) != 0 )
    *(_DWORD *)&prec->Status |= 2u;
  if ( (v9 & 0x20) != 0 )
    *(_DWORD *)&prec->Status |= 1u;
  v10 = *v8 & 0xC00;
  switch ( v10 )
  {
    case 0:
      *(_DWORD *)prec &= 0xFFFFFFFC;
      break;
    case 1024:
      v11 = prec;
      v12 = *(_DWORD *)prec & 0xFFFFFFFC | 1;
      goto LABEL_27;
    case 2048:
      v11 = prec;
      v12 = *(_DWORD *)prec & 0xFFFFFFFC | 2;
LABEL_27:
      *(_DWORD *)v11 = v12;
      break;
    case 3072:
      *(_DWORD *)prec |= 3u;
      break;
    default:
      break;
  }
  v13 = *v8 & 0x300;
  switch ( v13 )
  {
    case 0:
      v14 = prec;
      v15 = *(_DWORD *)prec & 0xFFFFFFE3 | 8;
      goto LABEL_36;
    case 512:
      v14 = prec;
      v15 = *(_DWORD *)prec & 0xFFFFFFE3 | 4;
LABEL_36:
      *(_DWORD *)v14 = v15;
      break;
    case 768:
      *(_DWORD *)prec &= 0xFFFFFFE3;
      break;
    default:
      break;
  }
  *(_DWORD *)prec ^= (*(_DWORD *)prec ^ (32 * opcode)) & 0x1FFE0;
  *((_DWORD *)&prec->Operand1 + 4) |= 1u;
  v16 = presult;
  if ( isfloat != 0 )
  {
    *((_DWORD *)&prec->Operand1 + 4) &= 0xFFFFFFE1;
    prec->Operand1.Value.Fp32Value = *parg1;
    *((_DWORD *)&prec->Result + 4) |= 1u;
    *((_DWORD *)&prec->Result + 4) &= 0xFFFFFFE1;
    prec->Result.Value.Fp32Value = *v16;
  }
  else
  {
    *((_DWORD *)&prec->Operand1 + 4) = *((_DWORD *)&prec->Operand1 + 4) & 0xFFFFFFE1 | 2;
    prec->Operand1.Value.Fp64Value = *(double *)parg1;
    *((_DWORD *)&prec->Result + 4) |= 1u;
    *((_DWORD *)&prec->Result + 4) = *((_DWORD *)&prec->Result + 4) & 0xFFFFFFE1 | 2;
    prec->Result.Value.Fp64Value = *(double *)v16;
  }
  _clrfp();
  RaiseException(
    dwExceptionCode: flags,
    dwExceptionFlags: 0,
    nNumberOfArguments: 1u,
    lpArguments: (const ULONG_PTR *)&prec);
  v17 = prec;
  if ( (*(_BYTE *)&prec->Enable & 0x10) != 0 )
    *v8 &= ~1u;
  if ( (*(_BYTE *)&v17->Enable & 8) != 0 )
    *v8 &= ~4u;
  if ( (*(_BYTE *)&v17->Enable & 4) != 0 )
    *v8 &= ~8u;
  if ( (*(_BYTE *)&v17->Enable & 2) != 0 )
    *v8 &= ~0x10u;
  if ( (*(_BYTE *)&v17->Enable & 1) != 0 )
    *v8 &= ~0x20u;
  v18 = *(_DWORD *)v17 & 3;
  if ( v18 == 0 )
  {
    *v8 &= 0xFFFFF3FF;
    goto LABEL_59;
  }
  v19 = v18 - 1;
  if ( v19 == 0 )
  {
    v21 = *v8 & 0xFFFFF3FF | 0x400;
    goto LABEL_56;
  }
  v20 = v19 - 1;
  if ( v20 == 0 )
  {
    v21 = *v8 & 0xFFFFF3FF | 0x800;
LABEL_56:
    *v8 = v21;
    goto LABEL_59;
  }
  if ( v20 == 1 )
    *v8 |= 0xC00u;
LABEL_59:
  v22 = (*(_DWORD *)v17 >> 2) & 7;
  if ( v22 == 0 )
  {
    v24 = *v8 & 0xFFFFF0FF | 0x300;
    goto LABEL_65;
  }
  v23 = v22 - 1;
  if ( v23 == 0 )
  {
    v24 = *v8 & 0xFFFFF1FF | 0x200;
LABEL_65:
    *v8 = v24;
    goto LABEL_66;
  }
  if ( v23 == 1 )
    *v8 &= 0xFFFFF3FF;
LABEL_66:
  if ( isfloat != 0 )
    *v16 = v17->Result.Value.Fp32Value;
  else
    *(double *)v16 = v17->Result.Value.Fp64Value;
}

//------------------------------------------------------------------------------
// Address: 0x0042BC7E
// Name: __raise_exc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _raise_exc(
        _FPIEEE_RECORD *prec,
        unsigned int *pcw,
        DWORD flags,
        int opcode,
        long double *parg1,
        long double *presult)
{
  _raise_exc_ex(prec, pcw, flags, opcode, (float *)parg1, (float *)presult, isfloat: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0042BC9F
// Name: __handle_exc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _handle_exc(char flags, long double *presult, __int16 cw)
{
  int v3; // esi
  int v4; // eax
  double *v5; // ecx
  long double dbl; // st7
  BOOL v7; // esi
  int v8; // ecx
  double v9; // st7
  BOOL v10; // edx
  int v11; // eax
  double v13; // [esp+18h] [ebp-10h]
  int expn; // [esp+20h] [ebp-8h] BYREF
  int flags_p; // [esp+24h] [ebp-4h]

  v3 = flags & 0x1F;
  flags_p = v3;
  if ( (flags & 8) != 0 && (cw & 1) != 0 )
  {
    _set_statfp(sw: 1u);
    v3 = flags & 0x17;
    goto LABEL_46;
  }
  if ( (flags & 4) != 0 && (cw & 4) != 0 )
  {
    _set_statfp(sw: 4u);
    v3 = flags & 0x1B;
    goto LABEL_46;
  }
  if ( (flags & 1) != 0 && (cw & 8) != 0 )
  {
    _set_statfp(sw: 8u);
    v4 = cw & 0xC00;
    if ( (cw & 0xC00) != 0 )
    {
      if ( v4 != 1024 )
      {
        if ( v4 != 2048 )
        {
          if ( v4 != 3072 )
          {
LABEL_24:
            v3 = flags & 0x1E;
            goto LABEL_46;
          }
          v5 = presult;
          dbl = _d_max.dbl;
          if ( *presult <= 0.0 )
            goto LABEL_22;
LABEL_23:
          *v5 = dbl;
          goto LABEL_24;
        }
        v5 = presult;
        if ( *presult <= 0.0 )
        {
          dbl = _d_max.dbl;
LABEL_22:
          dbl = -dbl;
          goto LABEL_23;
        }
LABEL_20:
        dbl = _d_inf.dbl;
        goto LABEL_23;
      }
      v5 = presult;
      if ( *presult > 0.0 )
      {
        dbl = _d_max.dbl;
        goto LABEL_23;
      }
    }
    else
    {
      v5 = presult;
      if ( *presult > 0.0 )
        goto LABEL_20;
    }
    dbl = _d_inf.dbl;
    goto LABEL_22;
  }
  if ( (flags & 2) != 0 && (cw & 0x10) != 0 )
  {
    v7 = (flags & 0x10) != 0;
    if ( 0.0 == *presult )
    {
      v7 = true;
      goto LABEL_43;
    }
    v13 = _decomp(x: *presult, pexp: &expn);
    v8 = expn - 1536;
    if ( expn - 1536 >= -1074 )
    {
      v10 = v13 < 0.0;
      HIWORD(v13) = BYTE6(v13) & 0xF | 0x10;
      if ( v8 < -1021 )
      {
        v11 = -1021 - v8;
        do
        {
          if ( (LOBYTE(v13) & 1) != 0 && !v7 )
            v7 = true;
          LODWORD(v13) >>= 1;
          if ( (BYTE4(v13) & 1) != 0 )
            LODWORD(v13) |= 0x80000000;
          HIDWORD(v13) >>= 1;
          --v11;
        }
        while ( v11 != 0 );
      }
      if ( !v10 )
        goto LABEL_41;
      v9 = -v13;
    }
    else
    {
      v7 = true;
      v9 = v13 * 0.0;
    }
    v13 = v9;
LABEL_41:
    *presult = v13;
LABEL_43:
    if ( v7 )
      _set_statfp(sw: 0x10u);
    flags_p &= ~2u;
    v3 = flags_p;
  }
LABEL_46:
  if ( (flags & 0x10) != 0 && (cw & 0x20) != 0 )
  {
    _set_statfp(sw: 0x20u);
    v3 &= ~0x10u;
  }
  return v3 == 0;
}

//------------------------------------------------------------------------------
// Address: 0x0042BE80
// Name: __set_errno_from_matherr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _set_errno_from_matherr(int matherrtype)
{
  if ( matherrtype == 1 )
  {
    *_errno() = 33;
  }
  else if ( matherrtype > 1 && matherrtype <= 3 )
  {
    *_errno() = 34;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042BEA8
// Name: __errcode
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _errcode(char flags)
{
  if ( (flags & 0x20) != 0 )
    return 5;
  if ( (flags & 8) != 0 )
    return 1;
  if ( (flags & 4) != 0 )
    return 2;
  if ( (flags & 1) != 0 )
    return 3;
  return 2 * (flags & 2);
}

//------------------------------------------------------------------------------
// Address: 0x0042BED5
// Name: __umatherr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _umatherr(
        int type,
        unsigned int opcode,
        long double arg1,
        long double arg2,
        long double retval,
        unsigned int cw)
{
  int v6; // eax
  char *v7; // eax

  v6 = 0;
  while ( dword_43FEA0[2 * v6] != opcode )
  {
    if ( ++v6 >= 29 )
    {
      v7 = nullptr;
      goto LABEL_5;
    }
  }
  v7 = (&off_43FEA4)[2 * v6];
LABEL_5:
  if ( v7 != nullptr )
  {
    _ctrlfp(newctrl: cw, _mask: 0xFFFFu);
    if ( _matherr() == 0 )
      _set_errno_from_matherr(matherrtype: type);
    return retval;
  }
  else
  {
    _ctrlfp(newctrl: cw, _mask: 0xFFFFu);
    _set_errno_from_matherr(matherrtype: type);
    return retval;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042BF73
// Name: __handle_qnan1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _handle_qnan1(unsigned int opcode, long double x, unsigned int savedcw)
{
  if ( _matherr_flag == 0 )
    return _umatherr(type: 1, opcode, arg1: x, arg2: 0.0, retval: x, cw: savedcw);
  *_errno() = 33;
  _ctrlfp(newctrl: savedcw, _mask: 0xFFFFu);
  return x;
}

//------------------------------------------------------------------------------
// Address: 0x0042BFC6
// Name: __except1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _except1(int flags, int opcode, long double arg, long double result, unsigned int cw)
{
  int v5; // eax
  _FPIEEE_RECORD prec; // [esp+80h] [ebp-80h] BYREF

  if ( !_handle_exc(flags, presult: &result, cw) )
  {
    *((_DWORD *)&prec.Operand2 + 4) &= ~1u;
    _raise_exc_ex(&prec, pcw: &cw, flags, opcode, parg1: (float *)&arg, presult: (float *)&result, isfloat: 0);
  }
  v5 = _errcode(flags);
  if ( _matherr_flag == 0 && v5 != 0 )
    return _umatherr(type: v5, opcode, arg1: arg, arg2: 0.0, retval: result, cw);
  _set_errno_from_matherr(matherrtype: v5);
  _ctrlfp(newctrl: cw, _mask: 0xFFFFu);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042C080
// Name: __statfp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall _statfp@<eax>(__int16 a1@<fpstat>)
{
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x0042C08B
// Name: __clrfp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall _clrfp@<eax>(__int16 a1@<fpstat>)
{
  __asm { fnclex }
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x0042C097
// Name: __ctrlfp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _ctrlfp()
{
  __int16 oldCw; // [esp+0h] [ebp-4h]

  return oldCw;
}

//------------------------------------------------------------------------------
// Address: 0x0042C0BE
// Name: __set_statfp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _set_statfp()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x0042C114
// Name: ___set_fpsr_sse2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __set_fpsr_sse2(unsigned int newMXCSR)
{
  if ( __sse2_available != 0 )
  {
    if ( (newMXCSR & 0x40) != 0 && _DAZ_ENABLED != 0 )
      _mm_setcsr(newMXCSR);
    else
      _mm_setcsr(newMXCSR & 0xFFFFFFBF);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042C186
// Name: __crtGetStringTypeA_stat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _crtGetStringTypeA_stat(
        DWORD dwInfoType,
        const char *lpSrcStr,
        int cchSrc,
        unsigned __int16 *lpCharType,
        unsigned int code_page,
        int lcid,
        int bError)
{
  localeinfo_struct *plocinfo; // ecx
  int v8; // eax
  wchar_t *v9; // ebx
  localeinfo_struct *v10; // edi
  int v11; // eax
  int v12; // edi
  unsigned int v13; // eax
  void *v14; // esp
  wchar_t *v15; // eax
  int v16; // eax
  char *v18; // esi
  int v19; // eax
  const char *v20; // eax
  BOOL StringTypeA; // edi
  _DWORD v22[3]; // [esp+0h] [ebp-14h] BYREF
  int retval2; // [esp+Ch] [ebp-8h] BYREF

  v8 = f_use_4;
  v9 = nullptr;
  v10 = plocinfo;
  if ( f_use_4 == 0 )
  {
    if ( GetStringTypeW(dwInfoType: 1u, lpSrcStr: &String2, cchSrc: 1, lpCharType: (LPWORD)&retval2) )
    {
      f_use_4 = 1;
      goto LABEL_10;
    }
    if ( GetLastError() == 120 )
    {
      v8 = 2;
      f_use_4 = 2;
    }
    else
    {
      v8 = f_use_4;
    }
  }
  if ( v8 != 2 && v8 != 0 )
  {
    if ( v8 != 1 )
      return 0;
LABEL_10:
    retval2 = 0;
    if ( code_page == 0 )
      code_page = v10->locinfo->lc_codepage;
    v11 = MultiByteToWideChar(
            CodePage: code_page,
            dwFlags: 8 * (bError != 0) + 1,
            lpMultiByteStr: lpSrcStr,
            cbMultiByte: cchSrc,
            lpWideCharStr: nullptr,
            cchWideChar: 0);
    v12 = v11;
    if ( v11 == 0 )
      return 0;
    if ( v11 > 0 && (unsigned int)v11 <= 0x7FFFFFF0 )
    {
      v13 = 2 * v11 + 8;
      if ( v13 > 0x400 )
      {
        v15 = (wchar_t *)operator new(nSize: 2 * v12 + 8);
        if ( v15 != nullptr )
        {
          *(_DWORD *)v15 = 56797;
          goto LABEL_20;
        }
      }
      else
      {
        v14 = alloca(v13);
        v15 = (wchar_t *)v22;
        if ( v22 != nullptr )
        {
          v22[0] = 52428;
LABEL_20:
          v15 += 4;
        }
      }
      v9 = v15;
    }
    if ( v9 != nullptr )
    {
      memset(dst: (int)v9, value: nullptr, count: 2 * v12);
      v16 = MultiByteToWideChar(
              CodePage: code_page,
              dwFlags: 1u,
              lpMultiByteStr: lpSrcStr,
              cbMultiByte: cchSrc,
              lpWideCharStr: v9,
              cchWideChar: v12);
      if ( v16 != 0 )
        retval2 = GetStringTypeW(dwInfoType, lpSrcStr: v9, cchSrc: v16, lpCharType);
      _freea(_Memory: v9);
      return retval2;
    }
    return 0;
  }
  v18 = nullptr;
  if ( lcid == 0 )
    lcid = v10->locinfo->lc_handle[2];
  if ( code_page == 0 )
    code_page = v10->locinfo->lc_codepage;
  v19 = __ansicp(lcid);
  if ( v19 == -1 )
    return 0;
  if ( v19 != code_page )
  {
    v20 = __convertcp(fromCP: code_page, toCP: v19, lpSrcStr, pcchSrc: &cchSrc, lpDestStr: nullptr, cchDest: 0);
    v18 = (char *)v20;
    if ( v20 == nullptr )
      return 0;
    lpSrcStr = v20;
  }
  StringTypeA = GetStringTypeA(Locale: lcid, dwInfoType, lpSrcStr, cchSrc, lpCharType);
  if ( v18 != nullptr )
    free(pMem: v18);
  return StringTypeA;
}

//------------------------------------------------------------------------------
// Address: 0x0042C33E
// Name: ___crtGetStringTypeA
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __crtGetStringTypeA(
        localeinfo_struct *plocinfo,
        DWORD dwInfoType,
        const char *lpSrcStr,
        int cchSrc,
        unsigned __int16 *lpCharType,
        unsigned int code_page,
        int lcid,
        int bError)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  result = _crtGetStringTypeA_stat(dwInfoType, lpSrcStr, cchSrc, lpCharType, code_page, lcid, bError);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042C37E
// Name: ___free_lc_time
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __free_lc_time(__lc_time_data *lc_time)
{
  if ( lc_time != nullptr )
  {
    free(pMem: lc_time->wday_abbr[1]);
    free(pMem: lc_time->wday_abbr[2]);
    free(pMem: lc_time->wday_abbr[3]);
    free(pMem: lc_time->wday_abbr[4]);
    free(pMem: lc_time->wday_abbr[5]);
    free(pMem: lc_time->wday_abbr[6]);
    free(pMem: lc_time->wday_abbr[0]);
    free(pMem: lc_time->wday[1]);
    free(pMem: lc_time->wday[2]);
    free(pMem: lc_time->wday[3]);
    free(pMem: lc_time->wday[4]);
    free(pMem: lc_time->wday[5]);
    free(pMem: lc_time->wday[6]);
    free(pMem: lc_time->wday[0]);
    free(pMem: lc_time->month_abbr[0]);
    free(pMem: lc_time->month_abbr[1]);
    free(pMem: lc_time->month_abbr[2]);
    free(pMem: lc_time->month_abbr[3]);
    free(pMem: lc_time->month_abbr[4]);
    free(pMem: lc_time->month_abbr[5]);
    free(pMem: lc_time->month_abbr[6]);
    free(pMem: lc_time->month_abbr[7]);
    free(pMem: lc_time->month_abbr[8]);
    free(pMem: lc_time->month_abbr[9]);
    free(pMem: lc_time->month_abbr[10]);
    free(pMem: lc_time->month_abbr[11]);
    free(pMem: lc_time->month[0]);
    free(pMem: lc_time->month[1]);
    free(pMem: lc_time->month[2]);
    free(pMem: lc_time->month[3]);
    free(pMem: lc_time->month[4]);
    free(pMem: lc_time->month[5]);
    free(pMem: lc_time->month[6]);
    free(pMem: lc_time->month[7]);
    free(pMem: lc_time->month[8]);
    free(pMem: lc_time->month[9]);
    free(pMem: lc_time->month[10]);
    free(pMem: lc_time->month[11]);
    free(pMem: lc_time->ampm[0]);
    free(pMem: lc_time->ampm[1]);
    free(pMem: lc_time->ww_sdatefmt);
    free(pMem: lc_time->ww_ldatefmt);
    free(pMem: lc_time->ww_timefmt);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042C50E
// Name: ___free_lconv_num
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __free_lconv_num(lconv *l)
{
  char *grouping; // esi

  if ( l != nullptr )
  {
    if ( l->decimal_point != __lconv_c.decimal_point )
      free(pMem: l->decimal_point);
    if ( l->thousands_sep != __lconv_c.thousands_sep )
      free(pMem: l->thousands_sep);
    grouping = l->grouping;
    if ( grouping != __lconv_c.grouping )
      free(pMem: grouping);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042C54E
// Name: ___free_lconv_mon
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __free_lconv_mon(lconv *l)
{
  char *negative_sign; // esi

  if ( l != nullptr )
  {
    if ( l->int_curr_symbol != __lconv_c.int_curr_symbol )
      free(pMem: l->int_curr_symbol);
    if ( l->currency_symbol != __lconv_c.currency_symbol )
      free(pMem: l->currency_symbol);
    if ( l->mon_decimal_point != __lconv_c.mon_decimal_point )
      free(pMem: l->mon_decimal_point);
    if ( l->mon_thousands_sep != __lconv_c.mon_thousands_sep )
      free(pMem: l->mon_thousands_sep);
    if ( l->mon_grouping != __lconv_c.mon_grouping )
      free(pMem: l->mon_grouping);
    if ( l->positive_sign != __lconv_c.positive_sign )
      free(pMem: l->positive_sign);
    negative_sign = l->negative_sign;
    if ( negative_sign != __lconv_c.negative_sign )
      free(pMem: negative_sign);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042C5E0
// Name: _strcspn
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strcspn(unsigned __int8 *string, unsigned __int8 *control)
{
  unsigned int v2; // eax
  int v5; // ecx
  signed __int32 v6[9]; // [esp+0h] [ebp-24h] BYREF

  v2 = 0;
  memset(v6, 0, 32);
  while ( 1 )
  {
    LOBYTE(v2) = *control;
    if ( *control == 0 )
      break;
    ++control;
    _bittestandset(v6, v2);
  }
  v5 = -1;
  do
  {
    ++v5;
    LOBYTE(v2) = *string;
    if ( *string == 0 )
      break;
    ++string;
  }
  while ( !_bittest(v6, v2) );
}

//------------------------------------------------------------------------------
// Address: 0x0042C626
// Name: _strncmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl strncmp(const char *first, const char *last, unsigned int count)
{
  const char *v4; // ecx
  const char *v5; // eax
  char v6; // dl
  char v7; // dl
  char v8; // dl
  char v9; // dl
  int v10; // eax
  int v11; // ecx
  unsigned int n; // [esp+4h] [ebp-4h]

  n = 0;
  if ( count == 0 )
    return 0;
  if ( count <= 4 )
  {
    v4 = last;
    v5 = first;
    goto LABEL_23;
  }
  v4 = last;
  v5 = first;
  do
  {
    v6 = *v5;
    v5 += 4;
    v4 += 4;
    if ( v6 == 0 || v6 != *(v4 - 4) )
    {
      v10 = *((unsigned __int8 *)v5 - 4);
      v11 = *((unsigned __int8 *)v4 - 4);
      return v10 - v11;
    }
    v7 = *(v5 - 3);
    if ( v7 == 0 || v7 != *(v4 - 3) )
    {
      v10 = *((unsigned __int8 *)v5 - 3);
      v11 = *((unsigned __int8 *)v4 - 3);
      return v10 - v11;
    }
    v8 = *(v5 - 2);
    if ( v8 == 0 || v8 != *(v4 - 2) )
    {
      v10 = *((unsigned __int8 *)v5 - 2);
      v11 = *((unsigned __int8 *)v4 - 2);
      return v10 - v11;
    }
    v9 = *(v5 - 1);
    if ( v9 == 0 || v9 != *(v4 - 1) )
    {
      v10 = *((unsigned __int8 *)v5 - 1);
      v11 = *((unsigned __int8 *)v4 - 1);
      return v10 - v11;
    }
    n += 4;
  }
  while ( n < count - 4 );
  while ( 1 )
  {
LABEL_23:
    if ( n >= count )
      return 0;
    if ( *v5 == 0 || *v5 != *v4 )
      break;
    ++v5;
    ++v4;
    ++n;
  }
  v10 = *(unsigned __int8 *)v5;
  v11 = *(unsigned __int8 *)v4;
  return v10 - v11;
}

//------------------------------------------------------------------------------
// Address: 0x0042C6F0
// Name: _strpbrk
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strpbrk(unsigned __int8 *string, unsigned __int8 *control)
{
  unsigned int v2; // eax
  signed __int32 v5[9]; // [esp+0h] [ebp-24h] BYREF

  v2 = 0;
  memset(v5, 0, 32);
  while ( 1 )
  {
    LOBYTE(v2) = *control;
    if ( *control == 0 )
      break;
    ++control;
    _bittestandset(v5, v2);
  }
  do
  {
    LOBYTE(v2) = *string;
    if ( *string == 0 )
      break;
    ++string;
  }
  while ( !_bittest(v5, v2) );
}

//------------------------------------------------------------------------------
// Address: 0x0042C730
// Name: __ld12tod
// Source: linker_block_proximity
//------------------------------------------------------------------------------
INTRNCVT_STATUS __cdecl _ld12tod(_LDBL12 *pld12, _CRT_DOUBLE *d)
{
  __int16 v2; // bx
  int v3; // ebx
  int v4; // eax
  int v5; // ebx
  int v6; // eax
  INTRNCVT_STATUS result; // eax
  int v8; // esi
  unsigned int *v9; // edi
  int v10; // eax
  bool i; // zf
  int v12; // eax
  unsigned int v13; // edx
  unsigned int *v14; // ecx
  bool v15; // cf
  unsigned int v16; // esi
  int v17; // eax
  int v18; // edx
  int *v19; // ebx
  unsigned int v20; // esi
  char v21; // cl
  int v22; // edx
  unsigned int *v23; // ecx
  int v24; // esi
  int v25; // eax
  unsigned int *v26; // ebx
  bool j; // zf
  int v28; // eax
  unsigned int v29; // edx
  unsigned int *v30; // ecx
  unsigned int v31; // edi
  int k; // ecx
  unsigned int *v33; // ecx
  unsigned int v34; // esi
  int v35; // edi
  int v36; // eax
  int v37; // edx
  int *v38; // ebx
  unsigned int v39; // esi
  char v40; // cl
  int v41; // edx
  unsigned int *v42; // ecx
  int v43; // eax
  int v44; // edx
  int *v45; // ebx
  unsigned int v46; // esi
  char v47; // cl
  int v48; // edx
  unsigned int *v49; // ecx
  int v50; // eax
  int v51; // edx
  unsigned int v52; // edi
  int v53; // edx
  unsigned int *v54; // ecx
  unsigned int v55; // ebx
  int v56; // edx
  unsigned int v57; // [esp+8h] [ebp-2Ch]
  int v58; // [esp+Ch] [ebp-28h]
  int v59; // [esp+10h] [ebp-24h]
  unsigned int v60; // [esp+14h] [ebp-20h] BYREF
  int v61; // [esp+18h] [ebp-1Ch]
  int v62; // [esp+1Ch] [ebp-18h] BYREF
  int v63; // [esp+20h] [ebp-14h]
  int v64; // [esp+24h] [ebp-10h]
  int v65; // [esp+28h] [ebp-Ch]
  int v66; // [esp+2Ch] [ebp-8h]
  int v67; // [esp+30h] [ebp-4h]
  _LDBL12 *pld12a; // [esp+3Ch] [ebp+8h]
  _LDBL12 *pld12b; // [esp+3Ch] [ebp+8h]
  _LDBL12 *pld12c; // [esp+3Ch] [ebp+8h]
  int pld12d; // [esp+3Ch] [ebp+8h]
  _LDBL12 *pld12e; // [esp+3Ch] [ebp+8h]
  _LDBL12 *pld12f; // [esp+3Ch] [ebp+8h]
  _LDBL12 *pld12g; // [esp+3Ch] [ebp+8h]

  v2 = *(_WORD *)&pld12->ld12[10];
  v63 = v2 & 0x8000;
  v60 = *(_DWORD *)&pld12->ld12[6];
  v3 = (v2 & 0x7FFF) - 0x3FFF;
  v4 = *(unsigned __int16 *)pld12->ld12 << 16;
  v61 = *(_DWORD *)&pld12->ld12[2];
  v62 = v4;
  if ( v3 != -16383 )
  {
    pld12a = nullptr;
    v57 = v60;
    v58 = v61;
    v59 = v62;
    v8 = DoubleFormat.precision - 1;
    v64 = v3;
    v65 = DoubleFormat.precision / 32;
    v9 = &v60 + DoubleFormat.precision / 32;
    v66 = 31 - DoubleFormat.precision % 32;
    if ( ((1 << (31 - DoubleFormat.precision % 32)) & *v9) != 0 )
    {
      v10 = v65;
      for ( i = (~(-1 << (31 - DoubleFormat.precision % 32)) & *(&v60 + v65)) == 0; i; i = *(&v60 + v10) == 0 )
      {
        if ( ++v10 >= 3 )
          goto LABEL_22;
      }
      v12 = v8 / 32;
      v67 = 0;
      v13 = 1 << (31 - v8 % 32);
      v14 = &v60 + v8 / 32;
      pld12b = (_LDBL12 *)(v13 + *v14);
      if ( (unsigned int)pld12b >= *v14 )
      {
        v15 = (unsigned int)pld12b < v13;
        goto LABEL_18;
      }
LABEL_19:
      v67 = 1;
      while ( 1 )
      {
        --v12;
        *v14 = (unsigned int)pld12b;
        if ( v12 < 0 || v67 == 0 )
          break;
        v67 = 0;
        v14 = &v60 + v12;
        v16 = *v14 + 1;
        pld12b = (_LDBL12 *)v16;
        if ( v16 >= *v14 )
        {
          v15 = v16 == 0;
LABEL_18:
          if ( !v15 )
            continue;
        }
        goto LABEL_19;
      }
      pld12a = (_LDBL12 *)v67;
    }
LABEL_22:
    *v9 &= -1 << v66;
    if ( v65 + 1 < 3 )
      memset(&v60 + v65 + 1, 0, 4 * (3 - (v65 + 1)));
    if ( pld12a != nullptr )
      ++v3;
    if ( v3 >= DoubleFormat.min_exp - DoubleFormat.precision )
    {
      if ( v3 > DoubleFormat.min_exp )
      {
        if ( v3 < DoubleFormat.max_exp )
        {
          v60 &= ~0x80000000;
          v5 = DoubleFormat.bias + v3;
          v50 = DoubleFormat.exp_width / 32;
          v51 = DoubleFormat.exp_width % 32;
          v65 = 0;
          pld12g = nullptr;
          v67 = 32 - DoubleFormat.exp_width % 32;
          do
          {
            v52 = *(&v60 + (_DWORD)pld12g);
            v64 = ~(-1 << v51) & v52;
            *(&v60 + (_DWORD)pld12g) = v65 | (v52 >> v51);
            pld12g = (_LDBL12 *)((char *)pld12g + 1);
            v65 = v64 << v67;
          }
          while ( (int)pld12g < 3 );
          v53 = 2;
          v54 = (unsigned int *)(&v62 - v50);
          do
          {
            if ( v53 < v50 )
              *(&v60 + v53) = 0;
            else
              *(&v60 + v53) = *v54;
            --v53;
            --v54;
          }
          while ( v53 >= 0 );
          result = INTRNCVT_OK;
        }
        else
        {
          v61 = 0;
          v62 = 0;
          v60 = 0x80000000;
          v43 = DoubleFormat.exp_width / 32;
          v44 = DoubleFormat.exp_width % 32;
          v65 = 0;
          pld12f = nullptr;
          v67 = 32 - DoubleFormat.exp_width % 32;
          do
          {
            v45 = (int *)(&v60 + (_DWORD)pld12f);
            v46 = *v45;
            v64 = ~(-1 << v44) & *v45;
            v47 = v67;
            *v45 = v65 | (v46 >> v44);
            pld12f = (_LDBL12 *)((char *)pld12f + 1);
            v65 = v64 << v47;
          }
          while ( (int)pld12f < 3 );
          v48 = 2;
          v49 = (unsigned int *)(&v62 - v43);
          do
          {
            if ( v48 < v43 )
              *(&v60 + v48) = 0;
            else
              *(&v60 + v48) = *v49;
            --v48;
            --v49;
          }
          while ( v48 >= 0 );
          v5 = DoubleFormat.bias + DoubleFormat.max_exp;
          result = INTRNCVT_OVERFLOW;
        }
        goto LABEL_79;
      }
      v60 = v57;
      v61 = v58;
      v17 = (DoubleFormat.min_exp - v64) / 32;
      v62 = v59;
      v18 = (DoubleFormat.min_exp - v64) % 32;
      v65 = 0;
      pld12c = nullptr;
      v67 = 32 - v18;
      do
      {
        v19 = (int *)(&v60 + (_DWORD)pld12c);
        v20 = *v19;
        v64 = ~(-1 << v18) & *v19;
        v21 = v67;
        *v19 = v65 | (v20 >> v18);
        pld12c = (_LDBL12 *)((char *)pld12c + 1);
        v65 = v64 << v21;
      }
      while ( (int)pld12c < 3 );
      v22 = 2;
      v23 = (unsigned int *)(&v62 - v17);
      do
      {
        if ( v22 < v17 )
          *(&v60 + v22) = 0;
        else
          *(&v60 + v22) = *v23;
        --v22;
        --v23;
      }
      while ( v22 >= 0 );
      v24 = DoubleFormat.precision - 1;
      v25 = DoubleFormat.precision / 32;
      v65 = DoubleFormat.precision / 32;
      v26 = &v60 + DoubleFormat.precision / 32;
      v64 = 31 - DoubleFormat.precision % 32;
      if ( ((1 << (31 - DoubleFormat.precision % 32)) & *v26) != 0 )
      {
        for ( j = (~(-1 << (31 - DoubleFormat.precision % 32)) & *(&v60 + v25)) == 0; j; j = *(&v60 + v25) == 0 )
        {
          if ( ++v25 >= 3 )
            goto LABEL_52;
        }
        v28 = v24 / 32;
        pld12d = 0;
        v29 = 1 << (31 - v24 % 32);
        v30 = &v60 + v24 / 32;
        v31 = *v30 + v29;
        if ( v31 < *v30 || v31 < v29 )
          pld12d = 1;
        *v30 = v31;
        for ( k = pld12d; --v28 >= 0 && k != 0; k = v35 )
        {
          v33 = &v60 + v28;
          v34 = *v33 + 1;
          v35 = 0;
          if ( v34 < *v33 || *v33 == -1 )
            v35 = 1;
          *v33 = v34;
        }
      }
LABEL_52:
      *v26 &= -1 << v64;
      if ( v65 + 1 < 3 )
        memset(&v60 + v65 + 1, 0, 4 * (3 - (v65 + 1)));
      v36 = (DoubleFormat.exp_width + 1) / 32;
      v37 = (DoubleFormat.exp_width + 1) % 32;
      v65 = 0;
      pld12e = nullptr;
      v67 = 32 - v37;
      do
      {
        v38 = (int *)(&v60 + (_DWORD)pld12e);
        v39 = *v38;
        v64 = ~(-1 << v37) & *v38;
        v40 = v67;
        *v38 = v65 | (v39 >> v37);
        pld12e = (_LDBL12 *)((char *)pld12e + 1);
        v65 = v64 << v40;
      }
      while ( (int)pld12e < 3 );
      v41 = 2;
      v42 = (unsigned int *)(&v62 - v36);
      do
      {
        if ( v41 < v36 )
          *(&v60 + v41) = 0;
        else
          *(&v60 + v41) = *v42;
        --v41;
        --v42;
      }
      while ( v41 >= 0 );
    }
    else
    {
      v60 = 0;
      v61 = 0;
      v62 = 0;
    }
    v5 = 0;
    result = INTRNCVT_UNDERFLOW;
    goto LABEL_79;
  }
  v5 = 0;
  v6 = 0;
  while ( *(&v60 + v6) == 0 )
  {
    if ( ++v6 >= 3 )
    {
      result = INTRNCVT_OK;
      goto LABEL_79;
    }
  }
  v60 = 0;
  v61 = 0;
  v62 = 0;
  result = INTRNCVT_UNDERFLOW;
LABEL_79:
  v55 = v60 | (v63 != 0 ? 0x80000000 : 0) | (v5 << (31 - LOBYTE(DoubleFormat.exp_width)));
  if ( DoubleFormat.format_width == 64 )
  {
    v56 = v61;
    HIDWORD(d->x) = v55;
    LODWORD(d->x) = v56;
  }
  else if ( DoubleFormat.format_width == 32 )
  {
    LODWORD(d->x) = v55;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042CC72
// Name: __ld12tof
// Source: linker_block_proximity
//------------------------------------------------------------------------------
INTRNCVT_STATUS __cdecl _ld12tof(_LDBL12 *pld12, _CRT_FLOAT *f)
{
  __int16 v2; // bx
  int v3; // ebx
  int v4; // eax
  int v5; // ebx
  int v6; // eax
  INTRNCVT_STATUS result; // eax
  int v8; // esi
  unsigned int *v9; // edi
  int v10; // eax
  bool i; // zf
  int v12; // eax
  unsigned int v13; // edx
  unsigned int *v14; // ecx
  bool v15; // cf
  unsigned int v16; // esi
  int v17; // eax
  int v18; // edx
  int *v19; // ebx
  unsigned int v20; // esi
  char v21; // cl
  int v22; // edx
  unsigned int *v23; // ecx
  int v24; // esi
  int v25; // eax
  unsigned int *v26; // ebx
  bool j; // zf
  int v28; // eax
  unsigned int v29; // edx
  unsigned int *v30; // ecx
  unsigned int v31; // edi
  int k; // ecx
  unsigned int *v33; // ecx
  unsigned int v34; // esi
  int v35; // edi
  int v36; // eax
  int v37; // edx
  int *v38; // ebx
  unsigned int v39; // esi
  char v40; // cl
  int v41; // edx
  unsigned int *v42; // ecx
  int v43; // eax
  int v44; // edx
  int *v45; // ebx
  unsigned int v46; // esi
  char v47; // cl
  int v48; // edx
  unsigned int *v49; // ecx
  int v50; // eax
  int v51; // edx
  unsigned int v52; // edi
  int v53; // edx
  unsigned int *v54; // ecx
  float v55; // ebx
  float v56; // edx
  unsigned int v57; // [esp+8h] [ebp-2Ch]
  float v58; // [esp+Ch] [ebp-28h]
  int v59; // [esp+10h] [ebp-24h]
  unsigned int v60; // [esp+14h] [ebp-20h] BYREF
  float v61; // [esp+18h] [ebp-1Ch]
  int v62; // [esp+1Ch] [ebp-18h] BYREF
  int v63; // [esp+20h] [ebp-14h]
  int v64; // [esp+24h] [ebp-10h]
  int v65; // [esp+28h] [ebp-Ch]
  int v66; // [esp+2Ch] [ebp-8h]
  int v67; // [esp+30h] [ebp-4h]
  _LDBL12 *pld12a; // [esp+3Ch] [ebp+8h]
  _LDBL12 *pld12b; // [esp+3Ch] [ebp+8h]
  _LDBL12 *pld12c; // [esp+3Ch] [ebp+8h]
  int pld12d; // [esp+3Ch] [ebp+8h]
  _LDBL12 *pld12e; // [esp+3Ch] [ebp+8h]
  _LDBL12 *pld12f; // [esp+3Ch] [ebp+8h]
  _LDBL12 *pld12g; // [esp+3Ch] [ebp+8h]

  v2 = *(_WORD *)&pld12->ld12[10];
  v63 = v2 & 0x8000;
  v60 = *(_DWORD *)&pld12->ld12[6];
  v3 = (v2 & 0x7FFF) - 0x3FFF;
  v4 = *(unsigned __int16 *)pld12->ld12 << 16;
  v61 = *(float *)&pld12->ld12[2];
  v62 = v4;
  if ( v3 != -16383 )
  {
    pld12a = nullptr;
    v57 = v60;
    v58 = v61;
    v59 = v62;
    v8 = FloatFormat.precision - 1;
    v64 = v3;
    v65 = FloatFormat.precision / 32;
    v9 = &v60 + FloatFormat.precision / 32;
    v66 = 31 - FloatFormat.precision % 32;
    if ( ((1 << (31 - FloatFormat.precision % 32)) & *v9) != 0 )
    {
      v10 = v65;
      for ( i = (~(-1 << (31 - FloatFormat.precision % 32)) & *(&v60 + v65)) == 0; i; i = *(&v60 + v10) == 0 )
      {
        if ( ++v10 >= 3 )
          goto LABEL_22;
      }
      v12 = v8 / 32;
      v67 = 0;
      v13 = 1 << (31 - v8 % 32);
      v14 = &v60 + v8 / 32;
      pld12b = (_LDBL12 *)(v13 + *v14);
      if ( (unsigned int)pld12b >= *v14 )
      {
        v15 = (unsigned int)pld12b < v13;
        goto LABEL_18;
      }
LABEL_19:
      v67 = 1;
      while ( 1 )
      {
        --v12;
        *v14 = (unsigned int)pld12b;
        if ( v12 < 0 || v67 == 0 )
          break;
        v67 = 0;
        v14 = &v60 + v12;
        v16 = *v14 + 1;
        pld12b = (_LDBL12 *)v16;
        if ( v16 >= *v14 )
        {
          v15 = v16 == 0;
LABEL_18:
          if ( !v15 )
            continue;
        }
        goto LABEL_19;
      }
      pld12a = (_LDBL12 *)v67;
    }
LABEL_22:
    *v9 &= -1 << v66;
    if ( v65 + 1 < 3 )
      memset(&v60 + v65 + 1, 0, 4 * (3 - (v65 + 1)));
    if ( pld12a != nullptr )
      ++v3;
    if ( v3 >= FloatFormat.min_exp - FloatFormat.precision )
    {
      if ( v3 > FloatFormat.min_exp )
      {
        if ( v3 < FloatFormat.max_exp )
        {
          v60 &= ~0x80000000;
          v5 = FloatFormat.bias + v3;
          v50 = FloatFormat.exp_width / 32;
          v51 = FloatFormat.exp_width % 32;
          v65 = 0;
          pld12g = nullptr;
          v67 = 32 - FloatFormat.exp_width % 32;
          do
          {
            v52 = *(&v60 + (_DWORD)pld12g);
            v64 = ~(-1 << v51) & v52;
            *(&v60 + (_DWORD)pld12g) = v65 | (v52 >> v51);
            pld12g = (_LDBL12 *)((char *)pld12g + 1);
            v65 = v64 << v67;
          }
          while ( (int)pld12g < 3 );
          v53 = 2;
          v54 = (unsigned int *)(&v62 - v50);
          do
          {
            if ( v53 < v50 )
              *(&v60 + v53) = 0;
            else
              *(&v60 + v53) = *v54;
            --v53;
            --v54;
          }
          while ( v53 >= 0 );
          result = INTRNCVT_OK;
        }
        else
        {
          v61 = 0.0;
          v62 = 0;
          v60 = 0x80000000;
          v43 = FloatFormat.exp_width / 32;
          v44 = FloatFormat.exp_width % 32;
          v65 = 0;
          pld12f = nullptr;
          v67 = 32 - FloatFormat.exp_width % 32;
          do
          {
            v45 = (int *)(&v60 + (_DWORD)pld12f);
            v46 = *v45;
            v64 = ~(-1 << v44) & *v45;
            v47 = v67;
            *v45 = v65 | (v46 >> v44);
            pld12f = (_LDBL12 *)((char *)pld12f + 1);
            v65 = v64 << v47;
          }
          while ( (int)pld12f < 3 );
          v48 = 2;
          v49 = (unsigned int *)(&v62 - v43);
          do
          {
            if ( v48 < v43 )
              *(&v60 + v48) = 0;
            else
              *(&v60 + v48) = *v49;
            --v48;
            --v49;
          }
          while ( v48 >= 0 );
          v5 = FloatFormat.bias + FloatFormat.max_exp;
          result = INTRNCVT_OVERFLOW;
        }
        goto LABEL_79;
      }
      v60 = v57;
      v61 = v58;
      v17 = (FloatFormat.min_exp - v64) / 32;
      v62 = v59;
      v18 = (FloatFormat.min_exp - v64) % 32;
      v65 = 0;
      pld12c = nullptr;
      v67 = 32 - v18;
      do
      {
        v19 = (int *)(&v60 + (_DWORD)pld12c);
        v20 = *v19;
        v64 = ~(-1 << v18) & *v19;
        v21 = v67;
        *v19 = v65 | (v20 >> v18);
        pld12c = (_LDBL12 *)((char *)pld12c + 1);
        v65 = v64 << v21;
      }
      while ( (int)pld12c < 3 );
      v22 = 2;
      v23 = (unsigned int *)(&v62 - v17);
      do
      {
        if ( v22 < v17 )
          *(&v60 + v22) = 0;
        else
          *(&v60 + v22) = *v23;
        --v22;
        --v23;
      }
      while ( v22 >= 0 );
      v24 = FloatFormat.precision - 1;
      v25 = FloatFormat.precision / 32;
      v65 = FloatFormat.precision / 32;
      v26 = &v60 + FloatFormat.precision / 32;
      v64 = 31 - FloatFormat.precision % 32;
      if ( ((1 << (31 - FloatFormat.precision % 32)) & *v26) != 0 )
      {
        for ( j = (~(-1 << (31 - FloatFormat.precision % 32)) & *(&v60 + v25)) == 0; j; j = *(&v60 + v25) == 0 )
        {
          if ( ++v25 >= 3 )
            goto LABEL_52;
        }
        v28 = v24 / 32;
        pld12d = 0;
        v29 = 1 << (31 - v24 % 32);
        v30 = &v60 + v24 / 32;
        v31 = *v30 + v29;
        if ( v31 < *v30 || v31 < v29 )
          pld12d = 1;
        *v30 = v31;
        for ( k = pld12d; --v28 >= 0 && k != 0; k = v35 )
        {
          v33 = &v60 + v28;
          v34 = *v33 + 1;
          v35 = 0;
          if ( v34 < *v33 || *v33 == -1 )
            v35 = 1;
          *v33 = v34;
        }
      }
LABEL_52:
      *v26 &= -1 << v64;
      if ( v65 + 1 < 3 )
        memset(&v60 + v65 + 1, 0, 4 * (3 - (v65 + 1)));
      v36 = (FloatFormat.exp_width + 1) / 32;
      v37 = (FloatFormat.exp_width + 1) % 32;
      v65 = 0;
      pld12e = nullptr;
      v67 = 32 - v37;
      do
      {
        v38 = (int *)(&v60 + (_DWORD)pld12e);
        v39 = *v38;
        v64 = ~(-1 << v37) & *v38;
        v40 = v67;
        *v38 = v65 | (v39 >> v37);
        pld12e = (_LDBL12 *)((char *)pld12e + 1);
        v65 = v64 << v40;
      }
      while ( (int)pld12e < 3 );
      v41 = 2;
      v42 = (unsigned int *)(&v62 - v36);
      do
      {
        if ( v41 < v36 )
          *(&v60 + v41) = 0;
        else
          *(&v60 + v41) = *v42;
        --v41;
        --v42;
      }
      while ( v41 >= 0 );
    }
    else
    {
      v60 = 0;
      v61 = 0.0;
      v62 = 0;
    }
    v5 = 0;
    result = INTRNCVT_UNDERFLOW;
    goto LABEL_79;
  }
  v5 = 0;
  v6 = 0;
  while ( *(&v60 + v6) == 0 )
  {
    if ( ++v6 >= 3 )
    {
      result = INTRNCVT_OK;
      goto LABEL_79;
    }
  }
  v60 = 0;
  v61 = 0.0;
  v62 = 0;
  result = INTRNCVT_UNDERFLOW;
LABEL_79:
  LODWORD(v55) = v60 | (v63 != 0 ? 0x80000000 : 0) | (v5 << (31 - LOBYTE(FloatFormat.exp_width)));
  if ( FloatFormat.format_width == 64 )
  {
    v56 = v61;
    f[1].f = v55;
    f->f = v56;
  }
  else if ( FloatFormat.format_width == 32 )
  {
    f->f = v55;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042D1B4
// Name: ___mtold12
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __mtold12(char *manptr, unsigned int manlen, _LDBL12 *ld12)
{
  int v3; // ecx
  unsigned int v4; // ebx
  unsigned int v5; // edx
  unsigned int v6; // edi
  int v7; // ebx
  unsigned int v8; // ecx
  unsigned int v9; // ebx
  int v10; // esi
  unsigned int v11; // ecx
  unsigned int v12; // edi
  int v13; // ebx
  unsigned int v14; // edx
  unsigned int v15; // esi
  int v16; // edx
  unsigned int v17; // ecx
  unsigned int v18; // esi
  unsigned int v19; // edi
  int v20; // ecx
  __int16 expn; // [esp+Ch] [ebp-18h]
  int v22; // [esp+10h] [ebp-14h]
  int v23; // [esp+10h] [ebp-14h]
  unsigned int tmp_4; // [esp+18h] [ebp-Ch]
  int tmp_8; // [esp+1Ch] [ebp-8h]

  expn = 16462;
  *(_DWORD *)ld12->ld12 = 0;
  *(_DWORD *)&ld12->ld12[4] = 0;
  for ( *(_DWORD *)&ld12->ld12[8] = 0; manlen != 0; ++manptr )
  {
    tmp_4 = *(_DWORD *)&ld12->ld12[4];
    tmp_8 = *(_DWORD *)&ld12->ld12[8];
    v22 = 0;
    v3 = __SPAIR64__(*(_QWORD *)&ld12->ld12[4] >> 31, *(__int64 *)ld12->ld12 >> 31) >> 31;
    v4 = *(_DWORD *)ld12->ld12;
    v5 = (2LL * *(_QWORD *)ld12->ld12) >> 31;
    v6 = 5 * *(_DWORD *)ld12->ld12;
    *(_DWORD *)ld12->ld12 *= 4;
    *(_DWORD *)&ld12->ld12[4] = v5;
    *(_DWORD *)&ld12->ld12[8] = v3;
    if ( 5 * v4 < 4 * v4 || v6 < v4 )
      v22 = 1;
    v7 = 0;
    *(_DWORD *)ld12->ld12 = v6;
    if ( v22 != 0 )
    {
      if ( v5 + 1 < v5 || v5 == -1 )
        v7 = 1;
      *(_DWORD *)&ld12->ld12[4] = v5 + 1;
      if ( v7 != 0 )
        *(_DWORD *)&ld12->ld12[8] = v3 + 1;
    }
    v8 = *(_DWORD *)&ld12->ld12[4];
    v9 = v8 + tmp_4;
    v10 = 0;
    if ( v8 + tmp_4 < v8 || v9 < tmp_4 )
      v10 = 1;
    *(_DWORD *)&ld12->ld12[4] = v9;
    if ( v10 != 0 )
      ++*(_DWORD *)&ld12->ld12[8];
    *(_DWORD *)&ld12->ld12[8] += tmp_8;
    v23 = 0;
    v11 = 2 * v6;
    v12 = (v6 >> 31) | (2 * v9);
    v13 = (v9 >> 31) | (2 * *(_DWORD *)&ld12->ld12[8]);
    *(_DWORD *)ld12->ld12 = v11;
    *(_DWORD *)&ld12->ld12[4] = v12;
    *(_DWORD *)&ld12->ld12[8] = v13;
    v14 = *manptr;
    v15 = v11 + v14;
    if ( v11 + v14 < v11 || v15 < v14 )
      v23 = 1;
    *(_DWORD *)ld12->ld12 = v15;
    if ( v23 != 0 )
    {
      v16 = 0;
      if ( v12 + 1 < v12 || v12 == -1 )
        v16 = 1;
      *(_DWORD *)&ld12->ld12[4] = v12 + 1;
      if ( v16 != 0 )
        *(_DWORD *)&ld12->ld12[8] = v13 + 1;
    }
    --manlen;
  }
  while ( *(_DWORD *)&ld12->ld12[8] == 0 )
  {
    v17 = *(_DWORD *)&ld12->ld12[4];
    *(_DWORD *)&ld12->ld12[8] = HIWORD(v17);
    expn -= 16;
    *(_QWORD *)ld12->ld12 = __PAIR64__(v17, *(_DWORD *)ld12->ld12) << 16;
  }
  if ( (*(_DWORD *)&ld12->ld12[8] & 0x8000) == 0 )
  {
    do
    {
      v18 = *(_DWORD *)ld12->ld12;
      v19 = *(_DWORD *)&ld12->ld12[4];
      --expn;
      *(_DWORD *)ld12->ld12 *= 2;
      v20 = (v19 >> 31) | (2 * *(_DWORD *)&ld12->ld12[8]);
      *(_DWORD *)&ld12->ld12[4] = (v18 >> 31) | (2 * v19);
      *(_DWORD *)&ld12->ld12[8] = v20;
    }
    while ( (v20 & 0x8000) == 0 );
  }
  *(_WORD *)&ld12->ld12[10] = expn;
}

//------------------------------------------------------------------------------
// Address: 0x0042D380
// Name: ___ansicp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __ansicp(LCID lcid)
{
  char LCData[8]; // [esp+0h] [ebp-Ch] BYREF

  LCData[6] = 0;
  if ( GetLocaleInfoA(Locale: lcid, LCType: 0x1004u, lpLCData: LCData, cchData: 6) != 0 )
    return atol(nptr: LCData);
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0042D3C7
// Name: ___convertcp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl __convertcp(UINT fromCP, UINT toCP, char *lpSrcStr, int *pcchSrc, char *lpDestStr, int cchDest)
{
  int v6; // esi
  int v7; // eax
  bool v8; // cc
  unsigned int v9; // eax
  void *v10; // esp
  unsigned __int16 *v11; // eax
  char *v13; // ebx
  char *v14; // eax
  int v15; // eax
  _DWORD v16[3]; // [esp+0h] [ebp-40h] BYREF
  LPSTR lpMultiByteStr; // [esp+Ch] [ebp-34h]
  int *v18; // [esp+10h] [ebp-30h]
  int sb; // [esp+14h] [ebp-2Ch]
  unsigned __int8 *buf; // [esp+18h] [ebp-28h]
  int cchSrc; // [esp+1Ch] [ebp-24h]
  char *cbuffer; // [esp+20h] [ebp-20h]
  unsigned __int16 *wbuffer; // [esp+24h] [ebp-1Ch]
  _cpinfo cpi; // [esp+28h] [ebp-18h] BYREF

  buf = (unsigned __int8 *)lpSrcStr;
  v18 = pcchSrc;
  cchSrc = *pcchSrc;
  lpMultiByteStr = lpDestStr;
  cbuffer = nullptr;
  sb = 0;
  if ( fromCP != toCP )
  {
    if ( GetCPInfo(CodePage: fromCP, lpCPInfo: &cpi)
      && cpi.MaxCharSize == 1
      && GetCPInfo(CodePage: toCP, lpCPInfo: &cpi)
      && cpi.MaxCharSize == 1 )
    {
      v6 = cchSrc;
      sb = 1;
      if ( cchSrc == -1 )
      {
        strlen((char *)buf);
        v6 = v7 + 1;
      }
      v8 = v6 <= 0;
    }
    else
    {
      v6 = MultiByteToWideChar(
             CodePage: fromCP,
             dwFlags: 1u,
             lpMultiByteStr: (LPCCH)buf,
             cbMultiByte: cchSrc,
             lpWideCharStr: nullptr,
             cchWideChar: 0);
      v8 = v6 <= 0;
      if ( v6 == 0 )
        return nullptr;
    }
    if ( v8 || (unsigned int)v6 > 0x7FFFFFF0 )
    {
      wbuffer = nullptr;
LABEL_21:
      if ( wbuffer != nullptr )
      {
        memset(dst: (int)wbuffer, value: nullptr, count: 2 * v6);
        if ( MultiByteToWideChar(
               CodePage: fromCP,
               dwFlags: 1u,
               lpMultiByteStr: (LPCCH)buf,
               cbMultiByte: cchSrc,
               lpWideCharStr: wbuffer,
               cchWideChar: v6) != 0 )
        {
          v13 = lpMultiByteStr;
          if ( lpMultiByteStr != nullptr )
          {
            if ( WideCharToMultiByte(
                   CodePage: toCP,
                   dwFlags: 0,
                   lpWideCharStr: wbuffer,
                   cchWideChar: v6,
                   lpMultiByteStr,
                   cbMultiByte: cchDest,
                   lpDefaultChar: nullptr,
                   lpUsedDefaultChar: nullptr) != 0 )
              cbuffer = v13;
          }
          else if ( sb != 0
                 || (v6 = WideCharToMultiByte(
                            CodePage: toCP,
                            dwFlags: 0,
                            lpWideCharStr: wbuffer,
                            cchWideChar: v6,
                            lpMultiByteStr: nullptr,
                            cbMultiByte: 0,
                            lpDefaultChar: nullptr,
                            lpUsedDefaultChar: nullptr)) != 0 )
          {
            v14 = (char *)calloc(count: 1u, size: v6);
            cbuffer = v14;
            if ( v14 != nullptr )
            {
              v15 = WideCharToMultiByte(
                      CodePage: toCP,
                      dwFlags: 0,
                      lpWideCharStr: wbuffer,
                      cchWideChar: v6,
                      lpMultiByteStr: v14,
                      cbMultiByte: v6,
                      lpDefaultChar: nullptr,
                      lpUsedDefaultChar: nullptr);
              if ( v15 != 0 )
              {
                if ( cchSrc != -1 )
                  *v18 = v15;
              }
              else
              {
                free(pMem: cbuffer);
                cbuffer = nullptr;
              }
            }
          }
        }
        _freea(_Memory: wbuffer);
        return cbuffer;
      }
      return nullptr;
    }
    v9 = 2 * v6 + 8;
    if ( v9 > 0x400 )
    {
      v11 = (unsigned __int16 *)operator new(nSize: 2 * v6 + 8);
      if ( v11 != nullptr )
      {
        *(_DWORD *)v11 = 56797;
        goto LABEL_18;
      }
    }
    else
    {
      v10 = alloca(v9);
      v11 = (unsigned __int16 *)v16;
      if ( v16 != nullptr )
      {
        v16[0] = 52428;
LABEL_18:
        v11 += 4;
      }
    }
    wbuffer = v11;
    goto LABEL_21;
  }
  return cbuffer;
}

//------------------------------------------------------------------------------
// Address: 0x0042D579
// Name: __mbtowc_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mbtowc_l(wchar_t *pwc, const char *s, signed int n, localeinfo_struct *plocinfo)
{
  int result; // eax
  threadlocaleinfostruct *locinfo; // eax
  int mb_cur_max; // ecx
  bool v7; // zf
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-10h] BYREF

  if ( s == nullptr || n == 0 )
    return 0;
  if ( *s == 0 )
  {
    if ( pwc != nullptr )
      *pwc = 0;
    return 0;
  }
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->lc_handle[2] == 0 )
  {
    if ( pwc != nullptr )
      *pwc = *(unsigned __int8 *)s;
    goto LABEL_11;
  }
  if ( _isleadbyte_l(c: *s, plocinfo: &_loc_update.localeinfo) != 0 )
  {
    locinfo = _loc_update.localeinfo.locinfo;
    mb_cur_max = _loc_update.localeinfo.locinfo->mb_cur_max;
    if ( mb_cur_max > 1
      && n >= mb_cur_max
      && (v7 = MultiByteToWideChar(
                 CodePage: _loc_update.localeinfo.locinfo->lc_codepage,
                 dwFlags: 9u,
                 lpMultiByteStr: s,
                 cbMultiByte: mb_cur_max,
                 lpWideCharStr: pwc,
                 cchWideChar: pwc != nullptr) == 0,
          locinfo = _loc_update.localeinfo.locinfo,
          !v7)
      || (unsigned int)n >= locinfo->mb_cur_max && s[1] != 0 )
    {
      result = locinfo->mb_cur_max;
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return result;
    }
  }
  else if ( MultiByteToWideChar(
              CodePage: _loc_update.localeinfo.locinfo->lc_codepage,
              dwFlags: 9u,
              lpMultiByteStr: s,
              cbMultiByte: 1,
              lpWideCharStr: pwc,
              cchWideChar: pwc != nullptr) != 0 )
  {
LABEL_11:
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 1;
  }
  *_errno() = 42;
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0042D68C
// Name: _mbtowc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl mbtowc(wchar_t *pwc, const char *s, unsigned int n)
{
  return _mbtowc_l(pwc, s, n, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0042D6A3
// Name: __wchartodigit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _wchartodigit(wchar_t ch)
{
  int v2; // ecx
  bool v3; // cf

  if ( ch < 0x30u )
    return -1;
  if ( ch < 0x3Au )
    return ch - 48;
  v2 = 65296;
  if ( ch >= 0xFF10u )
  {
    v3 = ch < 0xFF1Au;
LABEL_39:
    if ( v3 )
      return ch - v2;
    return -1;
  }
  v2 = 1632;
  if ( ch >= 0x660u )
  {
    if ( ch < 0x66Au )
      return ch - v2;
    v2 = 1776;
    if ( ch >= 0x6F0u )
    {
      if ( ch < 0x6FAu )
        return ch - v2;
      v2 = 2406;
      if ( ch >= 0x966u )
      {
        if ( ch < 0x970u )
          return ch - v2;
        v2 = 2534;
        if ( ch >= 0x9E6u )
        {
          if ( ch < 0x9F0u )
            return ch - v2;
          v2 = 2662;
          if ( ch >= 0xA66u )
          {
            if ( ch < 0xA70u )
              return ch - v2;
            v2 = 2790;
            if ( ch >= 0xAE6u )
            {
              if ( ch < 0xAF0u )
                return ch - v2;
              v2 = 2918;
              if ( ch >= 0xB66u )
              {
                if ( ch < 0xB70u )
                  return ch - v2;
                v2 = 3174;
                if ( ch >= 0xC66u )
                {
                  if ( ch < 0xC70u )
                    return ch - v2;
                  v2 = 3302;
                  if ( ch >= 0xCE6u )
                  {
                    if ( ch < 0xCF0u )
                      return ch - v2;
                    v2 = 3430;
                    if ( ch >= 0xD66u )
                    {
                      if ( ch < 0xD70u )
                        return ch - v2;
                      v2 = 3664;
                      if ( ch >= 0xE50u )
                      {
                        if ( ch < 0xE5Au )
                          return ch - v2;
                        v2 = 3792;
                        if ( ch >= 0xED0u )
                        {
                          if ( ch < 0xEDAu )
                            return ch - v2;
                          v2 = 3872;
                          if ( ch >= 0xF20u )
                          {
                            if ( ch < 0xF2Au )
                              return ch - v2;
                            v2 = 4160;
                            if ( ch >= 0x1040u )
                            {
                              if ( ch < 0x104Au )
                                return ch - v2;
                              v2 = 6112;
                              if ( ch >= 0x17E0u )
                              {
                                if ( ch < 0x17EAu )
                                  return ch - v2;
                                v2 = 6160;
                                if ( ch >= 0x1810u )
                                {
                                  v3 = ch < 0x181Au;
                                  goto LABEL_39;
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0042D825
// Name: __crtGetStringTypeW_stat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _crtGetStringTypeW_stat(
        localeinfo_struct *plocinfo,
        DWORD dwInfoType,
        const wchar_t *lpSrcStr,
        int cchSrc,
        unsigned __int16 *lpCharType,
        UINT code_page,
        LCID lcid)
{
  int v8; // eax
  int v9; // eax
  int v10; // eax
  unsigned int v11; // esi
  int v12; // eax
  void *v13; // esp
  unsigned __int8 *v14; // eax
  unsigned int v15; // eax
  void *v16; // esp
  unsigned __int16 *v17; // ebx
  unsigned __int16 *v18; // eax
  unsigned __int16 *v19; // esi
  BOOL StringTypeA; // eax
  bool v21; // zf
  unsigned __int8 *v22; // [esp-Ch] [ebp-28h]
  int v23; // [esp-8h] [ebp-24h]
  _DWORD v24[2]; // [esp+0h] [ebp-1Ch] BYREF
  int v25; // [esp+8h] [ebp-14h] BYREF
  int buff_size; // [esp+Ch] [ebp-10h]
  int retbool; // [esp+10h] [ebp-Ch]
  unsigned __int8 *buffer; // [esp+14h] [ebp-8h] BYREF

  if ( cchSrc < -1 )
    return 0;
  v8 = f_use_5;
  if ( f_use_5 == 0 )
  {
    if ( GetStringTypeW(dwInfoType: 1u, lpSrcStr: &String2, cchSrc: 1, lpCharType: (LPWORD)&buffer) )
    {
      f_use_5 = 1;
      return GetStringTypeW(dwInfoType, lpSrcStr, cchSrc, lpCharType);
    }
    if ( GetLastError() == 120 )
    {
      v8 = 2;
      f_use_5 = 2;
    }
    else
    {
      v8 = f_use_5;
    }
  }
  if ( v8 == 1 )
    return GetStringTypeW(dwInfoType, lpSrcStr, cchSrc, lpCharType);
  if ( v8 != 2 && v8 != 0 )
    return 0;
  retbool = 0;
  if ( lcid == 0 )
    lcid = plocinfo->locinfo->lc_handle[2];
  if ( code_page == 0 )
    code_page = plocinfo->locinfo->lc_codepage;
  v9 = __ansicp(lcid);
  if ( code_page != v9 && v9 != -1 )
    code_page = v9;
  v10 = WideCharToMultiByte(
          CodePage: code_page,
          dwFlags: 0,
          lpWideCharStr: lpSrcStr,
          cchWideChar: cchSrc,
          lpMultiByteStr: nullptr,
          cbMultiByte: 0,
          lpDefaultChar: nullptr,
          lpUsedDefaultChar: nullptr);
  v11 = v10;
  buff_size = v10;
  if ( v10 == 0 )
    return 0;
  if ( v10 > 0 )
  {
    v12 = v10 + 8;
    if ( v11 + 8 > 0x400 )
    {
      v14 = (unsigned __int8 *)operator new(nSize: v11 + 8);
      if ( v14 != nullptr )
      {
        *(_DWORD *)v14 = 56797;
        goto LABEL_27;
      }
    }
    else
    {
      v13 = alloca(v12);
      v14 = (unsigned __int8 *)v24;
      if ( v24 != nullptr )
      {
        v24[0] = 52428;
LABEL_27:
        v14 += 8;
      }
    }
    buffer = v14;
    goto LABEL_30;
  }
  buffer = nullptr;
LABEL_30:
  if ( buffer == nullptr )
    return 0;
  memset(dst: (int)buffer, value: nullptr, count: v11);
  if ( WideCharToMultiByte(
         CodePage: code_page,
         dwFlags: 0,
         lpWideCharStr: lpSrcStr,
         cchWideChar: cchSrc,
         lpMultiByteStr: (LPSTR)buffer,
         cbMultiByte: v11,
         lpDefaultChar: nullptr,
         lpUsedDefaultChar: nullptr) == 0 )
    goto error_cleanup_1;
  if ( (int)(v11 + 1) <= 0 || v11 + 1 > 0x7FFFFFF0 )
  {
    v17 = nullptr;
LABEL_41:
    if ( v17 != nullptr )
    {
      if ( lcid == 0 )
        lcid = plocinfo->locinfo->lc_handle[2];
      v23 = buff_size;
      v22 = buffer;
      v19 = &v17[cchSrc];
      *v19 = -1;
      *(v19 - 1) = -1;
      StringTypeA = GetStringTypeA(Locale: lcid, dwInfoType, lpSrcStr: (LPCSTR)v22, cchSrc: v23, lpCharType: v17);
      v21 = *(v19 - 1) == 0xFFFF;
      retbool = StringTypeA;
      if ( v21 || *v19 != 0xFFFF )
        retbool = 0;
      else
        memmove(dst: (unsigned __int8 *)lpCharType, src: (unsigned __int8 *)v17, count: 2 * cchSrc);
      _freea(_Memory: v17);
    }
    goto error_cleanup_1;
  }
  v15 = 2 * v11 + 10;
  if ( v15 > 0x400 )
  {
    v18 = (unsigned __int16 *)operator new(nSize: 2 * v11 + 10);
    if ( v18 != nullptr )
    {
      *(_DWORD *)v18 = 56797;
      v18 += 4;
    }
    v17 = v18;
    goto LABEL_41;
  }
  v16 = alloca(v15);
  if ( v24 != nullptr )
  {
    v24[0] = 52428;
    v17 = (unsigned __int16 *)&v25;
    goto LABEL_41;
  }
error_cleanup_1:
  _freea(_Memory: buffer);
  return retbool;
}

//------------------------------------------------------------------------------
// Address: 0x0042DA49
// Name: ___crtGetStringTypeW
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl __crtGetStringTypeW(
        localeinfo_struct *plocinfo,
        DWORD dwInfoType,
        const wchar_t *lpSrcStr,
        int cchSrc,
        unsigned __int16 *lpCharType,
        UINT code_page,
        LCID lcid)
{
  BOOL result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  result = _crtGetStringTypeW_stat(
             plocinfo: &_loc_update.localeinfo,
             dwInfoType,
             lpSrcStr,
             cchSrc,
             lpCharType,
             code_page,
             lcid);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042DA87
// Name: __putwch_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
wchar_t __cdecl _putwch_nolock(wchar_t ch)
{
  UINT ConsoleOutputCP; // eax
  DWORD v3; // eax
  int num_written; // [esp+4h] [ebp-10h] BYREF
  char mbc[8]; // [esp+8h] [ebp-Ch] BYREF

  if ( use_w == 0 )
    goto LABEL_10;
  if ( _confh == (HANDLE)-2 )
    __initconout();
  if ( _confh == (HANDLE)-1 )
    return -1;
  if ( !WriteConsoleW(
          hConsoleOutput: _confh,
          lpBuffer: &ch,
          nNumberOfCharsToWrite: 1u,
          lpNumberOfCharsWritten: (LPDWORD)&num_written,
          lpReserved: nullptr) )
  {
    if ( use_w != 2 || GetLastError() != 120 )
      return -1;
    use_w = 0;
LABEL_10:
    ConsoleOutputCP = GetConsoleOutputCP();
    v3 = WideCharToMultiByte(
           CodePage: ConsoleOutputCP,
           dwFlags: 0,
           lpWideCharStr: &ch,
           cchWideChar: 1,
           lpMultiByteStr: mbc,
           cbMultiByte: 5,
           lpDefaultChar: nullptr,
           lpUsedDefaultChar: nullptr);
    if ( _confh != (HANDLE)-1
      && WriteConsoleA(
           hConsoleOutput: _confh,
           lpBuffer: mbc,
           nNumberOfCharsToWrite: v3,
           lpNumberOfCharsWritten: (LPDWORD)&num_written,
           lpReserved: nullptr) )
    {
      return ch;
    }
    return -1;
  }
  use_w = 1;
  return ch;
}

//------------------------------------------------------------------------------
// Address: 0x0042DB49
// Name: _$I10_OUTPUT
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _I10_OUTPUT(_LDOUBLE ld, int ndigits, char output_flags, _FloatOutStruct *fos)
{
  __int16 v4; // cx
  unsigned __int16 v5; // dx
  int v6; // esi
  unsigned int v7; // edi
  unsigned int v9; // eax
  unsigned int v10; // edx
  unsigned int v11; // ecx
  unsigned int v12; // eax
  unsigned int v13; // edx
  unsigned int v14; // ecx
  int v15; // ebx
  int v16; // ecx
  _LDBL12 *v17; // ecx
  __int16 v18; // di
  __int16 v19; // cx
  unsigned __int16 v20; // di
  __int16 v21; // cx
  unsigned __int16 v22; // ax
  _BYTE *v23; // edi
  unsigned int v24; // edi
  unsigned int v25; // edx
  unsigned int v26; // esi
  __int16 v27; // ax
  unsigned int v28; // edx
  int v29; // edi
  int v30; // edx
  int v31; // edx
  int v32; // edi
  int v33; // edx
  bool v34; // zf
  __int16 v35; // cx
  unsigned __int16 v36; // di
  _WORD *v37; // eax
  unsigned int v38; // edx
  unsigned int v39; // esi
  unsigned int v40; // ebx
  __int16 v41; // di
  unsigned int v42; // edx
  int v43; // ebx
  int v44; // edx
  int v45; // eax
  int v46; // edx
  int v47; // ebx
  int v48; // edx
  int v49; // esi
  int k; // ebx
  unsigned int v51; // eax
  int v52; // edi
  int v53; // eax
  int v54; // esi
  int v55; // eax
  int v56; // edi
  int v57; // eax
  char *man; // ebx
  unsigned int v59; // edx
  unsigned int v60; // edi
  unsigned int v61; // ecx
  int v62; // esi
  int v63; // ecx
  unsigned int v64; // esi
  unsigned int v65; // edi
  int v66; // edx
  unsigned int v67; // edx
  char *v68; // ebx
  char v69; // al
  char *v70; // ebx
  _FloatOutStruct *v71; // eax
  char v72; // bl
  int v73; // [esp+10h] [ebp-70h]
  __int16 sign; // [esp+14h] [ebp-6Ch]
  _LDBL12 *v75; // [esp+18h] [ebp-68h]
  _LDBL12 *p_tmp12; // [esp+1Ch] [ebp-64h]
  int v77; // [esp+24h] [ebp-5Ch]
  unsigned __int8 *v78; // [esp+24h] [ebp-5Ch]
  unsigned __int8 *v79; // [esp+28h] [ebp-58h]
  int v80; // [esp+28h] [ebp-58h]
  unsigned __int8 *v81; // [esp+2Ch] [ebp-54h]
  int v82; // [esp+2Ch] [ebp-54h]
  int v83; // [esp+30h] [ebp-50h]
  int v84; // [esp+30h] [ebp-50h]
  __int16 digcount; // [esp+34h] [ebp-4Ch]
  int digcounta; // [esp+34h] [ebp-4Ch]
  int v87; // [esp+38h] [ebp-48h]
  unsigned __int8 *v88; // [esp+38h] [ebp-48h]
  _WORD *v89; // [esp+3Ch] [ebp-44h]
  int v90; // [esp+3Ch] [ebp-44h]
  int v91; // [esp+3Ch] [ebp-44h]
  unsigned int v92; // [esp+3Ch] [ebp-44h]
  int i; // [esp+40h] [ebp-40h]
  int j; // [esp+40h] [ebp-40h]
  char *v95; // [esp+40h] [ebp-40h]
  _LDBL12 tmp12; // [esp+44h] [ebp-3Ch] BYREF
  _LDBL12 ld12_one_tenth; // [esp+50h] [ebp-30h] BYREF
  _LDBL12 ld12; // [esp+60h] [ebp-20h] BYREF
  _BYTE v99[12]; // [esp+70h] [ebp-10h] BYREF

  *(_LDOUBLE *)v99 = ld;
  v4 = *(_WORD *)&ld.ld[8] & 0x8000;
  v5 = *(_WORD *)&ld.ld[8] & 0x7FFF;
  memset(&ld12_one_tenth, 204, 10);
  ld12_one_tenth.ld12[10] = -5;
  ld12_one_tenth.ld12[11] = 63;
  sign = *(_WORD *)&ld.ld[8] & 0x8000;
  if ( *(__int16 *)&ld.ld[8] >= 0 )
    fos->sign = 32;
  else
    fos->sign = 45;
  v6 = *(_DWORD *)&v99[4];
  v7 = *(_DWORD *)v99;
  if ( v5 == 0 && *(_DWORD *)&v99[4] == 0 && *(_DWORD *)v99 == 0 )
  {
    fos->exp = 0;
    fos->sign = v4 != -32768 ? 32 : 45;
    fos->ManLen = 1;
    fos->man[0] = 48;
    fos->man[1] = 0;
    return 1;
  }
  if ( v5 == 0x7FFF )
  {
    fos->exp = 1;
    if ( (v6 != 0x80000000 || v7 != 0) && (v6 & 0x40000000) == 0 )
    {
      v9 = strcpy_s(a1: v7, _Dst: fos->man, _SizeInBytes: 0x16u, _Src: "1#SNAN");
LABEL_25:
      if ( v9 != 0 )
        _invoke_watson(a1: v9, a2: v10, a3: v11, a4: (unsigned int)fos, a5: v7, a6: 0);
      fos->ManLen = 6;
      return 0;
    }
    if ( v4 != 0 && v6 == -1073741824 )
    {
      if ( v7 == 0 )
      {
        v12 = strcpy_s(a1: 0, _Dst: fos->man, _SizeInBytes: 0x16u, _Src: "1#IND");
LABEL_21:
        if ( v12 != 0 )
          _invoke_watson(a1: v12, a2: v13, a3: v14, a4: (unsigned int)fos, a5: 0, a6: 0);
        fos->ManLen = 5;
        return 0;
      }
    }
    else if ( v6 == 0x80000000 && v7 == 0 )
    {
      v12 = strcpy_s(a1: 0, _Dst: fos->man, _SizeInBytes: 0x16u, _Src: "1#INF");
      goto LABEL_21;
    }
    v9 = strcpy_s(a1: v7, _Dst: fos->man, _SizeInBytes: 0x16u, _Src: "1#QNAN");
    goto LABEL_25;
  }
  digcount = (77 * (HIBYTE(v5) + 2 * HIBYTE(*(_DWORD *)&v99[4])) + 19728 * (unsigned int)v5 - 323162868) >> 16;
  v15 = -digcount;
  *(_WORD *)&ld12.ld12[10] = *(_WORD *)&ld.ld[8] & 0x7FFF;
  *(_DWORD *)&ld12.ld12[6] = *(_DWORD *)&v99[4];
  *(_DWORD *)&ld12.ld12[2] = *(_DWORD *)v99;
  *(_WORD *)ld12.ld12 = 0;
  v75 = &_pow10pos[-8];
  if ( digcount != 0 )
  {
    if ( (__int16)((77 * (HIBYTE(v5) + 2 * HIBYTE(*(_DWORD *)&v99[4])) + 19728 * (unsigned int)v5 - 323162868) >> 16) > 0 )
    {
      v15 = (__int16)((77 * (HIBYTE(v5) + 2 * HIBYTE(*(_DWORD *)&v99[4])) + 19728 * (unsigned int)v5 - 323162868) >> 16);
      v75 = &_pow10neg[-8];
    }
    while ( v15 != 0 )
    {
      v75 += 7;
      v16 = v15 & 7;
      v15 >>= 3;
      if ( v16 != 0 )
      {
        v17 = &v75[v16];
        p_tmp12 = v17;
        if ( *(_WORD *)v17->ld12 >= 0x8000u )
        {
          tmp12 = *v17;
          --*(_DWORD *)&tmp12.ld12[2];
          p_tmp12 = &tmp12;
          v17 = &tmp12;
        }
        v18 = *(_WORD *)&v17->ld12[10];
        v19 = *(_WORD *)&ld12.ld12[10] ^ v18;
        v20 = v18 & 0x7FFF;
        v87 = 0;
        memset(v99, 0, sizeof(v99));
        v21 = v19 & 0x8000;
        v22 = v20 + (*(_WORD *)&ld12.ld12[10] & 0x7FFF);
        if ( (*(_WORD *)&ld12.ld12[10] & 0x7FFF) == 0x7FFF || v20 >= 0x7FFFu || v22 > 0xBFFDu )
        {
LABEL_81:
          *(_DWORD *)&ld12.ld12[4] = 0;
          *(_DWORD *)ld12.ld12 = 0;
          *(_DWORD *)&ld12.ld12[8] = v21 != 0 ? -32768 : 2147450880;
          continue;
        }
        if ( v22 <= 0x3FBFu )
          goto LABEL_40;
        if ( (*(_WORD *)&ld12.ld12[10] & 0x7FFF) == 0 )
        {
          ++v22;
          if ( (*(_DWORD *)&ld12.ld12[8] & 0x7FFFFFFF) == 0
            && *(_DWORD *)&ld12.ld12[4] == 0
            && *(_DWORD *)ld12.ld12 == 0 )
          {
            *(_WORD *)&ld12.ld12[10] = 0;
            continue;
          }
        }
        if ( v20 != 0
          || (++v22, (*(_DWORD *)&p_tmp12->ld12[8] & 0x7FFFFFFF) != 0)
          || *(_DWORD *)&p_tmp12->ld12[4] != 0
          || *(_DWORD *)p_tmp12->ld12 != 0 )
        {
          v23 = &v99[4];
          v77 = 0;
          v89 = &v99[4];
          for ( i = 5; i > 0; --i )
          {
            v83 = i;
            v79 = &ld12.ld12[2 * v77];
            v81 = &p_tmp12->ld12[8];
            do
            {
              v24 = *((_DWORD *)v23 - 1);
              v25 = *(unsigned __int16 *)v81 * *(unsigned __int16 *)v79;
              v73 = 0;
              v26 = v24 + v25;
              if ( v24 + v25 < v24 || v26 < v25 )
                v73 = 1;
              v23 = v89;
              *((_DWORD *)v89 - 1) = v26;
              if ( v73 != 0 )
                ++*v89;
              v79 += 2;
              v81 -= 2;
              --v83;
            }
            while ( v83 > 0 );
            v23 = v89 + 1;
            ++v77;
            ++v89;
          }
          v27 = v22 - 16382;
          if ( v27 <= 0 )
            goto LABEL_170;
          do
          {
            if ( *(int *)&v99[8] < 0 )
              break;
            v28 = *(_DWORD *)v99;
            *(_DWORD *)v99 *= 2;
            v29 = (v28 >> 31) | (2 * *(_DWORD *)&v99[4]);
            v30 = *(__int64 *)&v99[4] >> 31;
            --v27;
            *(_DWORD *)&v99[4] = v29;
            *(_DWORD *)&v99[8] = v30;
          }
          while ( v27 > 0 );
          if ( v27 <= 0 )
          {
LABEL_170:
            if ( --v27 < 0 )
            {
              v90 = (unsigned __int16)-v27;
              v27 = 0;
              do
              {
                if ( (v99[0] & 1) != 0 )
                  ++v87;
                v31 = *(_DWORD *)&v99[8];
                *(_DWORD *)&v99[8] >>= 1;
                v32 = (v31 << 31) | (*(_DWORD *)&v99[4] >> 1);
                v33 = *(__int64 *)v99 >> 1;
                v34 = v90-- == 1;
                *(_DWORD *)&v99[4] = v32;
                *(_DWORD *)v99 = v33;
              }
              while ( !v34 );
              if ( v87 != 0 )
                *(_WORD *)v99 |= 1u;
            }
          }
          if ( *(_WORD *)v99 > 0x8000u || (*(_DWORD *)v99 & 0x1FFFF) == 0x18000 )
          {
            if ( *(_DWORD *)&v99[2] == -1 )
            {
              *(_DWORD *)&v99[2] = 0;
              if ( *(_DWORD *)&v99[6] == -1 )
              {
                *(_DWORD *)&v99[6] = 0;
                if ( *(_WORD *)&v99[10] == 0xFFFF )
                {
                  *(_WORD *)&v99[10] = 0x8000;
                  ++v27;
                }
                else
                {
                  ++*(_WORD *)&v99[10];
                }
              }
              else
              {
                ++*(_DWORD *)&v99[6];
              }
            }
            else
            {
              ++*(_DWORD *)&v99[2];
            }
          }
          if ( (unsigned __int16)v27 >= 0x7FFFu )
            goto LABEL_81;
          *(_WORD *)ld12.ld12 = *(_WORD *)&v99[2];
          *(_QWORD *)&ld12.ld12[2] = *(_QWORD *)&v99[4];
          *(_WORD *)&ld12.ld12[10] = v21 | v27;
        }
        else
        {
LABEL_40:
          memset(&ld12, 0, sizeof(ld12));
        }
      }
    }
  }
  if ( *(_WORD *)&ld12.ld12[10] >= 0x3FFFu )
  {
    ++digcount;
    v35 = (*(_WORD *)&ld12.ld12[10] ^ *(_WORD *)&ld12_one_tenth.ld12[10]) & 0x8000;
    v80 = 0;
    memset(v99, 0, sizeof(v99));
    v36 = (*(_WORD *)&ld12_one_tenth.ld12[10] & 0x7FFF) + (*(_WORD *)&ld12.ld12[10] & 0x7FFF);
    if ( (*(_WORD *)&ld12.ld12[10] & 0x7FFF) == 0x7FFF
      || (*(_WORD *)&ld12_one_tenth.ld12[10] & 0x7FFF) == 0x7FFF
      || v36 > 0xBFFDu )
    {
      *(_DWORD *)&ld12.ld12[8] = ((*(_WORD *)&ld12.ld12[10] ^ *(_WORD *)&ld12_one_tenth.ld12[10]) & 0x8000u) != 0
                               ? -32768
                               : 2147450880;
    }
    else
    {
      if ( v36 > 0x3FBFu )
      {
        if ( (*(_WORD *)&ld12.ld12[10] & 0x7FFF) == 0 )
        {
          ++v36;
          if ( (*(_DWORD *)&ld12.ld12[8] & 0x7FFFFFFF) == 0
            && *(_DWORD *)&ld12.ld12[4] == 0
            && *(_DWORD *)ld12.ld12 == 0 )
          {
            *(_WORD *)&ld12.ld12[10] = 0;
            goto LABEL_132;
          }
        }
        if ( (*(_WORD *)&ld12_one_tenth.ld12[10] & 0x7FFF) != 0
          || (++v36, (*(_DWORD *)&ld12_one_tenth.ld12[8] & 0x7FFFFFFF) != 0)
          || *(_DWORD *)&ld12_one_tenth.ld12[4] != 0
          || *(_DWORD *)ld12_one_tenth.ld12 != 0 )
        {
          v82 = 0;
          v37 = &v99[4];
          for ( j = 5; j > 0; --j )
          {
            v84 = j;
            v78 = &ld12_one_tenth.ld12[8];
            v88 = &ld12.ld12[2 * v82];
            do
            {
              v91 = 0;
              v38 = *(unsigned __int16 *)v88 * *(unsigned __int16 *)v78;
              v39 = *((_DWORD *)v37 - 1);
              v40 = v39 + v38;
              if ( v39 + v38 < v39 || v40 < v38 )
                v91 = 1;
              *((_DWORD *)v37 - 1) = v40;
              if ( v91 != 0 )
                ++*v37;
              v88 += 2;
              v78 -= 2;
              --v84;
            }
            while ( v84 > 0 );
            ++v37;
            ++v82;
          }
          v41 = v36 - 16382;
          if ( v41 <= 0 )
            goto LABEL_171;
          do
          {
            if ( *(int *)&v99[8] < 0 )
              break;
            v42 = *(_DWORD *)v99;
            *(_DWORD *)v99 *= 2;
            v43 = (v42 >> 31) | (2 * *(_DWORD *)&v99[4]);
            v44 = *(__int64 *)&v99[4] >> 31;
            --v41;
            *(_DWORD *)&v99[4] = v43;
            *(_DWORD *)&v99[8] = v44;
          }
          while ( v41 > 0 );
          if ( v41 <= 0 )
          {
LABEL_171:
            if ( --v41 < 0 )
            {
              v45 = (unsigned __int16)-v41;
              v41 = 0;
              do
              {
                if ( (v99[0] & 1) != 0 )
                  ++v80;
                v46 = *(_DWORD *)&v99[8];
                *(_DWORD *)&v99[8] >>= 1;
                v47 = (v46 << 31) | (*(_DWORD *)&v99[4] >> 1);
                v48 = *(__int64 *)v99 >> 1;
                --v45;
                *(_DWORD *)&v99[4] = v47;
                *(_DWORD *)v99 = v48;
              }
              while ( v45 != 0 );
              if ( v80 != 0 )
                *(_WORD *)v99 |= 1u;
            }
          }
          if ( *(_WORD *)v99 > 0x8000u || (*(_DWORD *)v99 & 0x1FFFF) == 0x18000 )
          {
            if ( *(_DWORD *)&v99[2] == -1 )
            {
              *(_DWORD *)&v99[2] = 0;
              if ( *(_DWORD *)&v99[6] == -1 )
              {
                *(_DWORD *)&v99[6] = 0;
                if ( *(_WORD *)&v99[10] == 0xFFFF )
                {
                  *(_WORD *)&v99[10] = 0x8000;
                  ++v41;
                }
                else
                {
                  ++*(_WORD *)&v99[10];
                }
              }
              else
              {
                ++*(_DWORD *)&v99[6];
              }
            }
            else
            {
              ++*(_DWORD *)&v99[2];
            }
          }
          if ( (unsigned __int16)v41 < 0x7FFFu )
          {
            *(_WORD *)ld12.ld12 = *(_WORD *)&v99[2];
            *(_QWORD *)&ld12.ld12[2] = *(_QWORD *)&v99[4];
            *(_WORD *)&ld12.ld12[10] = v35 | v41;
          }
          else
          {
            *(_DWORD *)&ld12.ld12[4] = 0;
            *(_DWORD *)ld12.ld12 = 0;
            *(_DWORD *)&ld12.ld12[8] = v35 != 0 ? -32768 : 2147450880;
          }
          goto LABEL_132;
        }
      }
      *(_DWORD *)&ld12.ld12[8] = 0;
    }
    *(_DWORD *)&ld12.ld12[4] = 0;
    *(_DWORD *)ld12.ld12 = 0;
  }
LABEL_132:
  fos->exp = digcount;
  if ( (output_flags & 1) != 0 )
  {
    ndigits += digcount;
    if ( ndigits <= 0 )
    {
      fos->exp = 0;
      fos->ManLen = 1;
      fos->sign = sign != (__int16)0x8000 ? 32 : 45;
      fos->man[0] = 48;
      fos->man[1] = 0;
      return 1;
    }
  }
  if ( ndigits > 21 )
    ndigits = 21;
  v49 = *(unsigned __int16 *)&ld12.ld12[10] - 16382;
  *(_WORD *)&ld12.ld12[10] = 0;
  for ( k = 8; k != 0; --k )
  {
    v51 = *(_DWORD *)ld12.ld12;
    *(_DWORD *)ld12.ld12 *= 2;
    v52 = (v51 >> 31) | (2 * *(_DWORD *)&ld12.ld12[4]);
    v53 = *(__int64 *)&ld12.ld12[4] >> 31;
    *(_DWORD *)&ld12.ld12[4] = v52;
    *(_DWORD *)&ld12.ld12[8] = v53;
  }
  if ( v49 < 0 )
  {
    v54 = (unsigned __int8)-(char)v49;
    if ( v54 != 0 )
    {
      do
      {
        v55 = *(_DWORD *)&ld12.ld12[8];
        *(_DWORD *)&ld12.ld12[8] >>= 1;
        v56 = (v55 << 31) | (*(_DWORD *)&ld12.ld12[4] >> 1);
        v57 = *(__int64 *)ld12.ld12 >> 1;
        --v54;
        *(_DWORD *)&ld12.ld12[4] = v56;
        *(_DWORD *)ld12.ld12 = v57;
      }
      while ( v54 > 0 );
    }
  }
  man = fos->man;
  v95 = fos->man;
  for ( digcounta = ndigits + 1; digcounta > 0; ld12.ld12[11] = 0 )
  {
    v59 = *(_DWORD *)ld12.ld12;
    tmp12 = ld12;
    *(_DWORD *)ld12.ld12 *= 2;
    v60 = *(_DWORD *)ld12.ld12;
    *(_DWORD *)ld12.ld12 *= 2;
    v61 = (v59 >> 31) | (2 * *(_DWORD *)&ld12.ld12[4]);
    v62 = 2 * v61;
    v63 = (v61 >> 31) | (2 * (*(__int64 *)&ld12.ld12[4] >> 31));
    v64 = (v60 >> 31) | v62;
    v65 = *(_DWORD *)tmp12.ld12 + *(_DWORD *)ld12.ld12;
    if ( (unsigned int)(*(_DWORD *)tmp12.ld12 + *(_DWORD *)ld12.ld12) < *(_DWORD *)ld12.ld12
      || v65 < *(_DWORD *)tmp12.ld12 )
    {
      v66 = 0;
      if ( v64 + 1 < v64 || v64 == -1 )
        v66 = 1;
      ++v64;
      if ( v66 != 0 )
        ++v63;
    }
    v67 = *(_DWORD *)&tmp12.ld12[4] + v64;
    v92 = *(_DWORD *)&tmp12.ld12[4] + v64;
    if ( *(_DWORD *)&tmp12.ld12[4] + v64 < v64 || v67 < *(_DWORD *)&tmp12.ld12[4] )
      ++v63;
    *(_DWORD *)ld12.ld12 = 2 * v65;
    *(_DWORD *)&ld12.ld12[8] = (v67 >> 31) | (2 * (*(_DWORD *)&tmp12.ld12[8] + v63));
    *man++ = ld12.ld12[11] + 48;
    --digcounta;
    *(_DWORD *)&ld12.ld12[4] = (v65 >> 31) | (2 * v92);
  }
  v68 = man - 1;
  v69 = *v68;
  v70 = v68 - 1;
  if ( v69 >= 53 )
  {
    while ( v70 >= v95 && *v70 == 57 )
      *v70-- = 48;
    v71 = fos;
    if ( v70 < v95 )
    {
      ++v70;
      ++fos->exp;
    }
    ++*v70;
  }
  else
  {
    while ( v70 >= v95 && *v70 == 48 )
      --v70;
    v71 = fos;
    if ( v70 < v95 )
    {
      fos->exp = 0;
      fos->ManLen = 1;
      fos->sign = sign != (__int16)0x8000 ? 32 : 45;
      *v95 = 48;
      fos->man[1] = 0;
      return 1;
    }
  }
  v72 = (_BYTE)v70 - (_BYTE)v71 - 3;
  v71->ManLen = v72;
  v71->man[v72] = 0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0042E40F
// Name: _hw_cw
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall hw_cw@<eax>(unsigned int abstr@<ebx>)
{
  int result; // eax
  unsigned int v2; // ecx

  result = (abstr & 0x10) != 0;
  if ( (abstr & 8) != 0 )
    result |= 4u;
  if ( (abstr & 4) != 0 )
    result |= 8u;
  if ( (abstr & 2) != 0 )
    result |= 0x10u;
  if ( (abstr & 1) != 0 )
    result |= 0x20u;
  if ( (abstr & 0x80000) != 0 )
    result |= 2u;
  v2 = abstr & 0x300;
  if ( (abstr & 0x300) != 0 )
  {
    switch ( v2 )
    {
      case 0x100u:
        result |= 0x400u;
        break;
      case 0x200u:
        result |= 0x800u;
        break;
      case 0x300u:
        result |= 0xC00u;
        break;
      default:
        break;
    }
  }
  if ( (abstr & 0x30000) != 0 )
  {
    if ( (abstr & 0x30000) == 0x10000 )
      result |= 0x200u;
  }
  else
  {
    result |= 0x300u;
  }
  if ( (abstr & 0x40000) != 0 )
    return result | 0x1000;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042E49D
// Name: __hw_cw_sse2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __fastcall _hw_cw_sse2(int a1, unsigned int abstr)
{
  unsigned int result; // eax
  unsigned int v3; // ecx
  unsigned int v4; // edx

  result = 0;
  if ( (abstr & 0x10) != 0 )
    result = 128;
  if ( (abstr & 8) != 0 )
    result |= 0x200u;
  if ( (abstr & 4) != 0 )
    result |= 0x400u;
  if ( (abstr & 2) != 0 )
    result |= 0x800u;
  if ( (abstr & 1) != 0 )
    result |= 0x1000u;
  if ( (abstr & 0x80000) != 0 )
    result |= 0x100u;
  v3 = abstr & 0x300;
  if ( (abstr & 0x300) != 0 )
  {
    switch ( v3 )
    {
      case 0x100u:
        result |= 0x2000u;
        break;
      case 0x200u:
        result |= 0x4000u;
        break;
      case 0x300u:
        result |= 0x6000u;
        break;
      default:
        break;
    }
  }
  v4 = abstr & 0x3000000;
  switch ( v4 )
  {
    case 0x1000000u:
      result |= 0x8040u;
      break;
    case 0x2000000u:
      result |= 0x40u;
      break;
    case 0x3000000u:
      result |= 0x8000u;
      break;
    default:
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042E53D
// Name: __control87
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _control87(unsigned int newctrl, unsigned int mask)
{
  int v2; // edx
  int v3; // eax
  unsigned int result; // eax
  __int16 v5; // ax
  __int16 v6; // bx
  unsigned int v7; // edx
  int v8; // eax
  __int16 v9; // ax
  int v10; // esi
  int v11; // ecx
  int v12; // eax
  int v13; // eax
  unsigned int v14; // edx
  int v15; // eax
  __int16 v16; // ax
  int v17; // edx
  int v18; // ecx
  int v19; // eax
  int v20; // eax
  int v21; // edx
  __int16 v22; // [esp+14h] [ebp-Ch]
  unsigned int v23; // [esp+1Ch] [ebp-4h]
  unsigned int maska; // [esp+28h] [ebp+8h]

  v2 = 0;
  if ( (v22 & 1) != 0 )
    v2 = 16;
  if ( (v22 & 4) != 0 )
    v2 |= 8u;
  if ( (v22 & 8) != 0 )
    v2 |= 4u;
  if ( (v22 & 0x10) != 0 )
    v2 |= 2u;
  if ( (v22 & 0x20) != 0 )
    v2 |= 1u;
  if ( (v22 & 2) != 0 )
    v2 |= 0x80000u;
  v3 = v22 & 0xC00;
  if ( v3 != 0 )
  {
    switch ( v3 )
    {
      case 1024:
        v2 |= 0x100u;
        break;
      case 2048:
        v2 |= 0x200u;
        break;
      case 3072:
        v2 |= 0x300u;
        break;
      default:
        break;
    }
  }
  if ( (v22 & 0x300) != 0 )
  {
    if ( (v22 & 0x300) == 0x200 )
      v2 |= 0x10000u;
  }
  else
  {
    v2 |= 0x20000u;
  }
  if ( (v22 & 0x1000) != 0 )
    v2 |= 0x40000u;
  result = mask & newctrl | v2 & ~mask;
  v23 = result;
  if ( result != v2 )
  {
    v5 = hw_cw(abstr: mask & newctrl | v2 & ~mask);
    v6 = v5;
    v7 = 0;
    if ( (v5 & 1) != 0 )
      v7 = 16;
    if ( (v5 & 4) != 0 )
      v7 |= 8u;
    if ( (v5 & 8) != 0 )
      v7 |= 4u;
    if ( (v5 & 0x10) != 0 )
      v7 |= 2u;
    if ( (v5 & 0x20) != 0 )
      v7 |= 1u;
    if ( (v5 & 2) != 0 )
      v7 |= 0x80000u;
    v8 = v5 & 0xC00;
    if ( (v6 & 0xC00) != 0 )
    {
      switch ( v8 )
      {
        case 1024:
          v7 |= 0x100u;
          break;
        case 2048:
          v7 |= 0x200u;
          break;
        case 3072:
          v7 |= 0x300u;
          break;
        default:
          break;
      }
    }
    if ( (v6 & 0x300) != 0 )
    {
      if ( (v6 & 0x300) == 0x200 )
        v7 |= 0x10000u;
    }
    else
    {
      v7 |= 0x20000u;
    }
    if ( (v6 & 0x1000) != 0 )
      v7 |= 0x40000u;
    result = v7;
    v23 = v7;
  }
  if ( __sse2_available != 0 )
  {
    v9 = _mm_getcsr();
    v10 = 0;
    if ( (v9 & 0x80u) != 0 )
      v10 = 16;
    if ( (v9 & 0x200) != 0 )
      v10 |= 8u;
    if ( (v9 & 0x400) != 0 )
      v10 |= 4u;
    if ( (v9 & 0x800) != 0 )
      v10 |= 2u;
    if ( (v9 & 0x1000) != 0 )
      v10 |= 1u;
    if ( (v9 & 0x100) != 0 )
      v10 |= 0x80000u;
    v11 = v9 & 0x6000;
    if ( (v9 & 0x6000) != 0 )
    {
      switch ( v11 )
      {
        case 8192:
          v10 |= 0x100u;
          break;
        case 16384:
          v10 |= 0x200u;
          break;
        case 24576:
          v10 |= 0x300u;
          break;
        default:
          break;
      }
    }
    v12 = (v9 & 0x8040) - 64;
    if ( v12 != 0 )
    {
      v13 = v12 - 32704;
      if ( v13 != 0 )
      {
        if ( v13 == 64 )
          v10 |= 0x1000000u;
      }
      else
      {
        v10 |= 0x3000000u;
      }
    }
    else
    {
      v10 |= 0x2000000u;
    }
    v14 = newctrl & mask & 0x308031F | v10 & ~(mask & 0x308031F);
    if ( v14 == v10 )
    {
      v15 = v10;
    }
    else
    {
      maska = _hw_cw_sse2(a1: v11, abstr: v14);
      __set_fpsr_sse2(newMXCSR: maska);
      v16 = _mm_getcsr();
      v17 = 0;
      if ( (v16 & 0x80u) != 0 )
        v17 = 16;
      if ( (v16 & 0x200) != 0 )
        v17 |= 8u;
      if ( (v16 & 0x400) != 0 )
        v17 |= 4u;
      if ( (v16 & 0x800) != 0 )
        v17 |= 2u;
      if ( (v16 & 0x1000) != 0 )
        v17 |= 1u;
      if ( (v16 & 0x100) != 0 )
        v17 |= 0x80000u;
      v18 = v16 & 0x6000;
      if ( (v16 & 0x6000) != 0 )
      {
        switch ( v18 )
        {
          case 8192:
            v17 |= 0x100u;
            break;
          case 16384:
            v17 |= 0x200u;
            break;
          case 24576:
            v17 |= 0x300u;
            break;
          default:
            break;
        }
      }
      v19 = (v16 & 0x8040) - 64;
      if ( v19 != 0 )
      {
        v20 = v19 - 32704;
        if ( v20 != 0 )
        {
          if ( v20 == 64 )
            v17 |= 0x1000000u;
        }
        else
        {
          v17 |= 0x3000000u;
        }
      }
      else
      {
        v17 |= 0x2000000u;
      }
      v15 = v17;
    }
    v21 = v23 ^ v15;
    result = v23 | v15;
    if ( (v21 & 0x8031F) != 0 )
      result |= 0x80000000;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042E840
// Name: __chsize_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _chsize_nolock(int filedes, __int64 size)
{
  doubleint v2; // rax
  signed int v3; // edi
  unsigned int v4; // esi
  HANDLE ProcessHeap; // eax
  DWORD v7; // eax
  int v8; // eax
  bool v9; // of
  unsigned int v10; // kr08_4
  int v11; // esi
  HANDLE v12; // eax
  doubleint v13; // rax
  void *osfhandle; // eax
  unsigned int *v15; // esi
  doubleint v16; // rax
  __int64 place; // [esp+Ch] [ebp-18h]
  __int64 retval; // [esp+14h] [ebp-10h]
  int oldmode; // [esp+1Ch] [ebp-8h]
  char *v20; // [esp+20h] [ebp-4h]

  HIDWORD(retval) = 0;
  place = _lseeki64_nolock(fh: filedes, pos: 0, mthd: 1u).bigint;
  if ( (HIDWORD(place) & (unsigned int)place) == 0xFFFFFFFF )
    return *_errno();
  v2.bigint = _lseeki64_nolock(fh: filedes, pos: 0, mthd: 2u).bigint;
  if ( (v2.twoints.upperhalf & v2.twoints.lowerhalf) == -1 )
    return *_errno();
  v3 = (unsigned __int64)(size - v2.bigint) >> 32;
  v4 = size - v2.twoints.lowerhalf;
  if ( v3 >= 0 && (size >= v2.bigint && (unsigned __int64)(size - v2.bigint) >> 32 != 0 || v4 != 0) )
  {
    ProcessHeap = GetProcessHeap();
    v20 = (char *)HeapAlloc(hHeap: ProcessHeap, dwFlags: 8u, dwBytes: 0x1000u);
    if ( v20 == nullptr )
    {
      *_errno() = 12;
      return *_errno();
    }
    oldmode = _setmode_nolock(fh: filedes, mode: 0x8000);
    while ( 1 )
    {
      v7 = v3 < 0 || v3 <= 0 && v4 < 0x1000 ? v4 : 4096;
      v8 = _write_nolock(a1: 0x1000u, a2: v3, fh: filedes, buf: v20, cnt: v7);
      if ( v8 == -1 )
        break;
      v9 = __OFSUB__(__PAIR64__(v3, v4), v8);
      v10 = v4 - v8;
      v3 = (__PAIR64__(v3, v4) - v8) >> 32;
      v4 -= v8;
      if ( v3 < 0 || (v3 < 0) ^ v9 | (v3 == 0) && v10 == 0 )
      {
        v11 = 0;
        goto LABEL_20;
      }
    }
    if ( *__doserrno() == 5 )
      *_errno() = 13;
    v11 = -1;
    HIDWORD(retval) = -1;
LABEL_20:
    _setmode_nolock(fh: filedes, mode: oldmode);
    v12 = GetProcessHeap();
    HeapFree(hHeap: v12, dwFlags: 0, lpMem: v20);
    goto LABEL_28;
  }
  if ( v3 < 0 )
  {
    v13.bigint = _lseeki64_nolock(fh: filedes, pos: size, mthd: 0).bigint;
    if ( (v13.twoints.upperhalf & v13.twoints.lowerhalf) == -1 )
      return *_errno();
    osfhandle = (void *)_get_osfhandle(a1: 0, a2: v3, fh: filedes);
    retval = SetEndOfFile(hFile: osfhandle) - 1;
    if ( (HIDWORD(retval) & (unsigned int)retval) == 0xFFFFFFFF )
    {
      *_errno() = 13;
      v15 = __doserrno();
      *v15 = GetLastError();
      v11 = retval;
LABEL_28:
      if ( (HIDWORD(retval) & v11) == 0xFFFFFFFF )
        return *_errno();
    }
  }
  v16.bigint = _lseeki64_nolock(fh: filedes, pos: place, mthd: 0).bigint;
  if ( (v16.twoints.upperhalf & v16.twoints.lowerhalf) == -1 )
    return *_errno();
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0042E9F4
// Name: __setmode_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _setmode_nolock(int fh, int mode)
{
  unsigned int v2; // edx
  _DWORD *v3; // esi
  ioinfo *v4; // ecx
  int v5; // eax
  _BYTE *v6; // ecx
  char v7; // dl
  int oldmode; // [esp+14h] [ebp+8h]

  v2 = 56 * (fh & 0x1F);
  v3 = (_DWORD *)(4 * (fh >> 5) + 4534976);
  v4 = &__pioinfo[fh >> 5][v2 / 0x38];
  oldmode = v4->osfile & 0x80;
  v5 = (char)(2 * *((_BYTE *)v4 + 36)) >> 1;
  if ( mode == 0x4000 )
  {
    v4->osfile |= 0x80u;
    *(_BYTE *)(*v3 + v2 + 36) &= 0x80u;
  }
  else if ( mode == 0x8000 )
  {
    v4->osfile &= ~0x80u;
  }
  else
  {
    if ( mode == 0x10000 || mode == 0x20000 )
    {
      v4->osfile |= 0x80u;
      v6 = (_BYTE *)(*v3 + v2 + 36);
      v7 = *v6 & 0x80 | 2;
    }
    else
    {
      if ( mode != 0x40000 )
        goto LABEL_11;
      v4->osfile |= 0x80u;
      v6 = (_BYTE *)(*v3 + v2 + 36);
      v7 = *v6 & 0x80 | 1;
    }
    *v6 = v7;
  }
LABEL_11:
  if ( oldmode != 0 )
    return v5 != 0 ? 0x10000 : 0x4000;
  else
    return 0x8000;
}

//------------------------------------------------------------------------------
// Address: 0x0042EAB0
// Name: __get_fmode
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _get_fmode@<eax>(unsigned int a1@<ebx>, unsigned int a2@<edi>, int *pMode)
{
  if ( pMode != nullptr )
  {
    *pMode = _fmode;
    return 0;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(a1, a2, a3: 0);
    return 22;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042EAE4
// Name: ___ascii_stricmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __ascii_stricmp(const char *dst, const char *src)
{
  int v4; // eax
  int v5; // ecx

  do
  {
    v4 = *(unsigned __int8 *)dst++;
    if ( (unsigned int)(v4 - 65) <= 0x19 )
      v4 += 32;
    v5 = *(unsigned __int8 *)src++;
    if ( (unsigned int)(v5 - 65) <= 0x19 )
      v5 += 32;
  }
  while ( v4 != 0 && v4 == v5 );
  return v4 - v5;
}

//------------------------------------------------------------------------------
// Address: 0x0042EB19
// Name: __stricmp_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall _stricmp_l@<eax>(
        unsigned int a1@<edi>,
        unsigned int a2@<esi>,
        const char *dst,
        const char *src,
        localeinfo_struct *plocinfo)
{
  unsigned int result; // eax
  const char *v6; // edi
  unsigned int v7; // eax
  unsigned int v8; // esi
  unsigned int v9; // eax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( dst != nullptr )
  {
    v6 = src;
    if ( src != nullptr )
    {
      if ( _loc_update.localeinfo.locinfo->lc_handle[2] != 0 )
      {
        do
        {
          v7 = _tolower_l(c: *(unsigned __int8 *)dst++, plocinfo: &_loc_update.localeinfo);
          v8 = v7;
          v9 = _tolower_l(c: *(unsigned __int8 *)v6++, plocinfo: &_loc_update.localeinfo);
        }
        while ( v8 != 0 && v8 == v9 );
        result = v8 - v9;
      }
      else
      {
        result = __ascii_stricmp(dst, src);
      }
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter(a1: 0, a2: 0, a3: a2);
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 0x7FFFFFFF;
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(a1: 0, a2: a1, a3: a2);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042EBEC
// Name: __stricmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall _stricmp@<eax>(unsigned int a1@<ebx>, unsigned int a2@<edi>, const char *dst, const char *src)
{
  if ( __locale_changed != 0 )
    return _stricmp_l(a1: a2, a2: 0, dst, src, plocinfo: nullptr);
  if ( dst != nullptr && src != nullptr )
    return __ascii_stricmp(dst, src);
  *_errno() = 22;
  _invalid_parameter(a1, a2, a3: 0);
  return 0x7FFFFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x0042EC3C
// Name: __strnicmp_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _strnicmp_l(
        const char *a1@<edi>,
        unsigned int a2@<esi>,
        char *dst,
        char *src,
        unsigned int count,
        localeinfo_struct *plocinfo)
{
  unsigned int v6; // eax
  unsigned int v7; // esi
  unsigned int v8; // eax
  _LocaleUpdate _loc_update; // [esp+Ch] [ebp-10h] BYREF

  if ( count != 0 )
  {
    _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
    if ( dst != nullptr && (a1 = src, src != nullptr) )
    {
      if ( count <= 0x7FFFFFFF )
      {
        if ( _loc_update.localeinfo.locinfo->lc_handle[2] != 0 )
        {
          do
          {
            v6 = _tolower_l(c: (unsigned __int8)*dst++, plocinfo: &_loc_update.localeinfo);
            v7 = v6;
            v8 = _tolower_l(c: *(unsigned __int8 *)a1++, plocinfo: &_loc_update.localeinfo);
            --count;
          }
          while ( count != 0 && v7 != 0 && v7 == v8 );
        }
        else
        {
          __ascii_strnicmp(first: (unsigned __int8 *)dst, last: (unsigned __int8 *)src, count);
        }
        if ( _loc_update.updated )
          _loc_update.ptd->_ownlocale &= ~2u;
      }
      else
      {
        *_errno() = 22;
        _invalid_parameter(a1: 0, a2: (unsigned int)src, a3: 0x7FFFFFFFu);
        if ( _loc_update.updated )
          _loc_update.ptd->_ownlocale &= ~2u;
      }
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter(a1: 0, a2: (unsigned int)a1, a3: a2);
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042ED2C
// Name: __strnicmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _strnicmp(unsigned int a1@<ebx>, const char *a2@<edi>, char *dst, char *src, unsigned int count)
{
  if ( __locale_changed != 0 )
  {
    _strnicmp_l(a1: a2, a2: 0, dst, src, count, plocinfo: nullptr);
  }
  else if ( dst != nullptr && src != nullptr && count <= 0x7FFFFFFF )
  {
    __ascii_strnicmp(first: (unsigned __int8 *)dst, last: (unsigned __int8 *)src, count);
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(a1, (unsigned int)a2, a3: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042ED88
// Name: __mbsnicmp_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _mbsnicmp_l(
        const char *a1@<edi>,
        unsigned int a2@<esi>,
        char *s1,
        char *s2,
        unsigned int n,
        localeinfo_struct *plocinfo)
{
  char *v6; // edi
  unsigned __int8 v7; // cl
  char v8; // cl
  unsigned __int16 v9; // dx
  unsigned __int16 v10; // si
  bool v11; // cf
  const unsigned __int8 *v12; // ecx
  unsigned __int8 v13; // cl
  char *v14; // ecx
  int v15; // ecx
  unsigned __int16 v16; // dx
  unsigned __int16 v17; // cx
  char *v18; // ecx
  int v19; // ecx
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-14h] BYREF
  int c1; // [esp+14h] [ebp-4h]

  if ( n == 0 )
    return;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.mbcinfo->ismbcodepage == 0 )
  {
    _strnicmp(a1: 0, a2: a1, dst: s1, src: s2, count: n);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return;
  }
  v6 = s1;
  if ( s1 == nullptr || s2 == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter(a1: 0, a2: (unsigned int)s1, a3: a2);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return;
  }
  while ( 1 )
  {
    v7 = *v6;
    --n;
    c1 = (unsigned __int8)*v6++;
    if ( (_loc_update.localeinfo.mbcinfo->mbctype[v7 + 1] & 4) == 0 )
    {
      v14 = (char *)_loc_update.localeinfo.mbcinfo + (unsigned __int16)c1;
      if ( (v14[29] & 0x10) != 0 )
        v15 = (unsigned __int8)v14[285];
      else
        v15 = (unsigned __int16)c1;
      c1 = v15;
      goto LABEL_25;
    }
    v8 = *v6;
    if ( *v6 == 0 )
    {
      c1 = 0;
LABEL_25:
      v10 = c1;
      goto LABEL_16;
    }
    HIBYTE(v9) = c1;
    ++v6;
    LOBYTE(v9) = v8;
    v10 = v9;
    v11 = v9 < _loc_update.localeinfo.mbcinfo->mbulinfo[0];
    c1 = v9;
    if ( v11 || v9 > _loc_update.localeinfo.mbcinfo->mbulinfo[1] )
    {
      if ( v9 >= _loc_update.localeinfo.mbcinfo->mbulinfo[3] && v9 <= _loc_update.localeinfo.mbcinfo->mbulinfo[4] )
        v10 = _loc_update.localeinfo.mbcinfo->mbulinfo[5] + v9;
    }
    else
    {
      v10 = _loc_update.localeinfo.mbcinfo->mbulinfo[2] + v9;
    }
LABEL_16:
    c1 = (unsigned __int8)*s2;
    v12 = (const unsigned __int8 *)++s2;
    if ( (_loc_update.localeinfo.mbcinfo->mbctype[(unsigned __int8)c1 + 1] & 4) == 0 )
    {
      v18 = (char *)_loc_update.localeinfo.mbcinfo + (unsigned __int16)c1;
      if ( (v18[29] & 0x10) != 0 )
        v19 = (unsigned __int8)v18[285];
      else
        v19 = (unsigned __int16)c1;
      c1 = v19;
      goto LABEL_42;
    }
    v13 = *v12;
    if ( v13 == 0 )
    {
      c1 = 0;
LABEL_42:
      v17 = c1;
      goto LABEL_30;
    }
    HIBYTE(v16) = c1;
    ++s2;
    LOBYTE(v16) = v13;
    v17 = v16;
    v11 = v16 < _loc_update.localeinfo.mbcinfo->mbulinfo[0];
    c1 = v16;
    if ( v11 || v16 > _loc_update.localeinfo.mbcinfo->mbulinfo[1] )
    {
      if ( v16 >= _loc_update.localeinfo.mbcinfo->mbulinfo[3] && v16 <= _loc_update.localeinfo.mbcinfo->mbulinfo[4] )
        v17 = _loc_update.localeinfo.mbcinfo->mbulinfo[5] + v16;
    }
    else
    {
      v17 = _loc_update.localeinfo.mbcinfo->mbulinfo[2] + v16;
    }
LABEL_30:
    if ( v17 != v10 )
      break;
    if ( v10 == 0 || n == 0 )
    {
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return;
    }
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
}

//------------------------------------------------------------------------------
// Address: 0x0042EF51
// Name: __mbsnicmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _mbsnicmp(const char *a1@<edi>, unsigned int a2@<esi>, char *s1, char *s2, unsigned int n)
{
  _mbsnicmp_l(a1, a2, s1, s2, n, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0042EF68
// Name: wcsncnt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall wcsncnt@<eax>(const wchar_t *string@<eax>, int cnt)
{
  int v2; // ecx

  v2 = cnt;
  while ( v2 != 0 )
  {
    --v2;
    if ( *string == 0 )
      return cnt - v2 - 1;
    ++string;
  }
  v2 = -1;
  return cnt - v2 - 1;
}

//------------------------------------------------------------------------------
// Address: 0x0042EF84
// Name: __crtCompareStringW_stat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _crtCompareStringW_stat(
        LCID Locale,
        DWORD dwCmpFlags,
        const wchar_t *lpString1,
        int cchCount1,
        const wchar_t *lpString2,
        int cchCount2,
        UINT code_page)
{
  localeinfo_struct *plocinfo; // ecx
  localeinfo_struct *v8; // ebx
  int v10; // eax
  int v11; // eax
  int v12; // ebx
  int v13; // eax
  void *v14; // esp
  unsigned __int8 *v15; // eax
  int v16; // eax
  int v17; // ecx
  int v18; // eax
  void *v19; // esp
  CHAR *v20; // eax
  CHAR *v21; // ebx
  _DWORD v22[3]; // [esp+0h] [ebp-20h] BYREF
  int buff_size1; // [esp+Ch] [ebp-14h]
  int retcode; // [esp+10h] [ebp-10h]
  int buff_size2; // [esp+14h] [ebp-Ch]
  unsigned __int8 *buffer1; // [esp+18h] [ebp-8h]

  v8 = plocinfo;
  if ( f_use_6 == 0 )
  {
    if ( CompareStringW(Locale: 0, dwCmpFlags: 0, lpString1: &String2, cchCount1: 1, lpString2: &String2, cchCount2: 1) != 0 )
    {
      f_use_6 = 1;
    }
    else if ( GetLastError() == 120 )
    {
      f_use_6 = 2;
    }
  }
  if ( cchCount1 > 0 )
    cchCount1 = wcsncnt(string: lpString1, cnt: cchCount1);
  if ( cchCount2 > 0 )
    cchCount2 = wcsncnt(string: lpString2, cnt: cchCount2);
  if ( cchCount1 != 0 && cchCount2 != 0 )
  {
    if ( f_use_6 == 1 )
      return CompareStringW(Locale, dwCmpFlags, lpString1, cchCount1, lpString2, cchCount2);
    if ( f_use_6 != 2 && f_use_6 != 0 )
      return 0;
    retcode = 0;
    if ( Locale == 0 )
      Locale = v8->locinfo->lc_handle[2];
    if ( code_page == 0 )
      code_page = v8->locinfo->lc_codepage;
    v10 = __ansicp(lcid: Locale);
    if ( code_page != v10 && v10 != -1 )
      code_page = v10;
    v11 = WideCharToMultiByte(
            CodePage: code_page,
            dwFlags: 0,
            lpWideCharStr: lpString1,
            cchWideChar: cchCount1,
            lpMultiByteStr: nullptr,
            cbMultiByte: 0,
            lpDefaultChar: nullptr,
            lpUsedDefaultChar: nullptr);
    v12 = v11;
    buff_size1 = v11;
    if ( v11 == 0 )
      return 0;
    if ( v11 <= 0 || 0xFFFFFFE0 / v11 == 0 )
    {
      buffer1 = nullptr;
LABEL_35:
      if ( buffer1 == nullptr )
        return 0;
      if ( WideCharToMultiByte(
             CodePage: code_page,
             dwFlags: 0,
             lpWideCharStr: lpString1,
             cchWideChar: cchCount1,
             lpMultiByteStr: (LPSTR)buffer1,
             cbMultiByte: v12,
             lpDefaultChar: nullptr,
             lpUsedDefaultChar: nullptr) == 0 )
        goto error_cleanup_2;
      v16 = WideCharToMultiByte(
              CodePage: code_page,
              dwFlags: 0,
              lpWideCharStr: lpString2,
              cchWideChar: cchCount2,
              lpMultiByteStr: nullptr,
              cbMultiByte: 0,
              lpDefaultChar: nullptr,
              lpUsedDefaultChar: nullptr);
      v17 = v16;
      buff_size2 = v16;
      if ( v16 == 0 )
        goto error_cleanup_2;
      if ( v16 <= 0 || 0xFFFFFFE0 / v16 == 0 )
      {
        v21 = nullptr;
LABEL_48:
        if ( v21 != nullptr )
        {
          if ( WideCharToMultiByte(
                 CodePage: code_page,
                 dwFlags: 0,
                 lpWideCharStr: lpString2,
                 cchWideChar: cchCount2,
                 lpMultiByteStr: v21,
                 cbMultiByte: buff_size2,
                 lpDefaultChar: nullptr,
                 lpUsedDefaultChar: nullptr) != 0 )
            retcode = CompareStringA(
                        Locale,
                        dwCmpFlags,
                        lpString1: (PCNZCH)buffer1,
                        cchCount1: buff_size1,
                        lpString2: v21,
                        cchCount2: buff_size2);
          _freea(_Memory: v21);
        }
error_cleanup_2:
        _freea(_Memory: buffer1);
        return retcode;
      }
      v18 = v16 + 8;
      if ( (unsigned int)(v17 + 8) > 0x400 )
      {
        v20 = (CHAR *)operator new(nSize: v17 + 8);
        if ( v20 != nullptr )
        {
          *(_DWORD *)v20 = 56797;
          goto LABEL_45;
        }
      }
      else
      {
        v19 = alloca(v18);
        v20 = (CHAR *)v22;
        if ( v22 != nullptr )
        {
          v22[0] = 52428;
LABEL_45:
          v20 += 8;
        }
      }
      v21 = v20;
      goto LABEL_48;
    }
    v13 = v11 + 8;
    if ( (unsigned int)(v12 + 8) > 0x400 )
    {
      v15 = (unsigned __int8 *)operator new(nSize: v12 + 8);
      if ( v15 != nullptr )
      {
        *(_DWORD *)v15 = 56797;
        goto LABEL_32;
      }
    }
    else
    {
      v14 = alloca(v13);
      v15 = (unsigned __int8 *)v22;
      if ( v22 != nullptr )
      {
        v22[0] = 52428;
LABEL_32:
        v15 += 8;
      }
    }
    buffer1 = v15;
    goto LABEL_35;
  }
  if ( cchCount1 == cchCount2 )
    return 2;
  else
    return 2 * (cchCount1 - cchCount2 >= 0) + 1;
}

//------------------------------------------------------------------------------
// Address: 0x0042F1D4
// Name: ___crtCompareStringW
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __crtCompareStringW(
        localeinfo_struct *plocinfo,
        LCID Locale,
        DWORD dwCmpFlags,
        const wchar_t *lpString1,
        int cchCount1,
        const wchar_t *lpString2,
        int cchCount2,
        UINT code_page)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  result = _crtCompareStringW_stat(Locale, dwCmpFlags, lpString1, cchCount1, lpString2, cchCount2, code_page);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042F214
// Name: ___initconout
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HANDLE __initconout()
{
  HANDLE result; // eax

  result = CreateFileA(
             lpFileName: "CONOUT$",
             dwDesiredAccess: 0x40000000u,
             dwShareMode: 3u,
             lpSecurityAttributes: nullptr,
             dwCreationDisposition: 3u,
             dwFlagsAndAttributes: 0,
             hTemplateFile: nullptr);
  _confh = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042F233
// Name: ___termcon
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HANDLE __termcon()
{
  HANDLE result; // eax

  if ( _confh != (HANDLE)-1 && _confh != (HANDLE)-2 )
    CloseHandle(hObject: _confh);
  result = _coninpfh;
  if ( _coninpfh != (HANDLE)-1 && _coninpfh != (HANDLE)-2 )
    return (HANDLE)CloseHandle(hObject: _coninpfh);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042F260
// Name: ___ascii_strnicmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __ascii_strnicmp(unsigned __int8 *first, unsigned __int8 *last, unsigned int count)
{
  unsigned int i; // ecx
  unsigned __int8 v6; // ah
  unsigned __int8 v7; // al

  for ( i = count; i != 0; --i )
  {
    v6 = *first;
    v7 = *last;
    if ( *first == 0 || v7 == 0 )
      break;
    ++first;
    ++last;
    if ( v6 >= 0x41u && v6 <= 0x5Au )
      v6 += 32;
    if ( v7 >= 0x41u && v7 <= 0x5Au )
      v7 += 32;
    if ( v6 != v7 )
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042F2C2
// Name: RtlUnwind(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __stdcall RtlUnwind(PVOID TargetFrame, PVOID TargetIp, PEXCEPTION_RECORD ExceptionRecord, PVOID ReturnValue)
{
  __imp__RtlUnwind@16(TargetFrame, TargetIp, ExceptionRecord, ReturnValue);
}

//------------------------------------------------------------------------------
// Address: 0x0042F2C8
// Name: int _strlwr_s_l_stat(char __near *,unsigned int,struct localeinfo_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _strlwr_s_l_stat(char *string, unsigned int sizeInBytes, localeinfo_struct *plocinfo)
{
  int *v3; // eax
  unsigned int v4; // esi
  unsigned int v5; // ecx
  char *i; // ecx
  char v7; // al
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  void *v12; // esp
  unsigned __int8 *v13; // eax
  unsigned int v14; // [esp-4h] [ebp-1Ch]
  _DWORD v15[3]; // [esp+0h] [ebp-18h] BYREF
  int dstsize; // [esp+Ch] [ebp-Ch]
  unsigned __int8 *dst; // [esp+10h] [ebp-8h]

  if ( string == nullptr )
    goto LABEL_2;
  if ( strnlen(str: string, maxsize: sizeInBytes) >= sizeInBytes )
  {
    *string = 0;
LABEL_2:
    v3 = _errno();
    v14 = 22;
LABEL_3:
    v4 = v14;
    *v3 = v14;
    _invalid_parameter(a1: 0, a2: (unsigned int)string, a3: v14);
    return v4;
  }
  v5 = plocinfo->locinfo->lc_handle[2];
  if ( v5 != 0 )
  {
    v9 = __crtLCMapStringA(
           plocinfo,
           Locale: v5,
           dwMapFlags: 0x100u,
           lpSrcStr: string,
           cchSrc: -1,
           lpDestStr: nullptr,
           cchDest: 0,
           code_page: plocinfo->locinfo->lc_codepage,
           bError: 1);
    v10 = v9;
    dstsize = v9;
    if ( v9 == 0 )
    {
      *_errno() = 42;
      return *_errno();
    }
    if ( sizeInBytes < v9 )
    {
      *string = 0;
      v3 = _errno();
      v14 = 34;
      goto LABEL_3;
    }
    if ( v9 <= 0 || 0xFFFFFFE0 / v9 == 0 )
    {
      dst = nullptr;
      goto LABEL_28;
    }
    v11 = v9 + 8;
    if ( (unsigned int)(v10 + 8) > 0x400 )
    {
      v13 = (unsigned __int8 *)operator new(nSize: v10 + 8);
      if ( v13 != nullptr )
      {
        *(_DWORD *)v13 = 56797;
        goto LABEL_25;
      }
    }
    else
    {
      v12 = alloca(v11);
      v13 = (unsigned __int8 *)v15;
      if ( v15 != nullptr )
      {
        v15[0] = 52428;
LABEL_25:
        v13 += 8;
      }
    }
    v10 = dstsize;
    dst = v13;
LABEL_28:
    if ( dst != nullptr )
    {
      if ( __crtLCMapStringA(
             plocinfo,
             Locale: plocinfo->locinfo->lc_handle[2],
             dwMapFlags: 0x100u,
             lpSrcStr: string,
             cchSrc: -1,
             lpDestStr: (char *)dst,
             cchDest: v10,
             code_page: plocinfo->locinfo->lc_codepage,
             bError: 1) != 0 )
      {
        v4 = strcpy_s(a1: (unsigned int)string, _Dst: string, _SizeInBytes: sizeInBytes, _Src: (const char *)dst);
      }
      else
      {
        *_errno() = 42;
        v4 = 42;
      }
      _freea(_Memory: dst);
      return v4;
    }
    *_errno() = 12;
    return *_errno();
  }
  for ( i = string; *i != 0; ++i )
  {
    v7 = *i;
    if ( *i >= 65 && v7 <= 90 )
      *i = v7 + 32;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0042F449
// Name: __strlwr_s_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _strlwr_s_l(char *string, unsigned int sizeInBytes, localeinfo_struct *plocinfo)
{
  unsigned int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  result = _strlwr_s_l_stat(string, sizeInBytes, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042F47B
// Name: _strlwr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__usercall strlwr@<eax>(unsigned int a1@<edi>, unsigned int a2@<esi>, char *string)
{
  char *result; // eax
  char *i; // edx
  char v5; // cl

  if ( __locale_changed != 0 )
  {
    _strlwr_s_l(string, sizeInBytes: 0xFFFFFFFF, plocinfo: nullptr);
    return string;
  }
  else
  {
    result = string;
    if ( string != nullptr )
    {
      for ( i = string; *i != 0; ++i )
      {
        v5 = *i;
        if ( *i >= 65 && v5 <= 90 )
          *i = v5 + 32;
      }
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter(a1: 0, a2: a1, a3: a2);
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042F4E0
// Name: _dynamic_initializer_for____s_ApplicationObject__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____s_ApplicationObject__()
{
  CSteamAppSystemGroup::CSteamAppSystemGroup(this: &_s_ApplicationObject, a2: nullptr, a3: nullptr);
  _s_ApplicationObject.__vftable = (CRenderSystemTestApp_vtbl *)&CRenderSystemTestApp::`vftable';
  return atexit(func: dynamic_atexit_destructor_for____s_ApplicationObject__);
}

//------------------------------------------------------------------------------
// Address: 0x0042F510
// Name: _dynamic_initializer_for____s_SteamApplicationObject__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____s_SteamApplicationObject__()
{
  CSteamApplication::CSteamApplication(this: &_s_SteamApplicationObject, a2: &_s_ApplicationObject);
  return atexit(func: dynamic_atexit_destructor_for____s_SteamApplicationObject__);
}

//------------------------------------------------------------------------------
// Address: 0x0042F530
// Name: sub_42F530
// Source: linker_block_proximity
//------------------------------------------------------------------------------
Vector2D *sub_42F530()
{
  return Vector2D::Vector2D(this: &stru_4406F0, X: 0.0, Y: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x0042F580
// Name: sub_42F580
// Source: linker_block_proximity
//------------------------------------------------------------------------------
Vector2D *sub_42F580()
{
  return Vector2D::Vector2D(this: &stru_4406F8, X: 3.4028235e38, Y: 3.4028235e38);
}

//------------------------------------------------------------------------------
// Address: 0x0042F5D0
// Name: sub_42F5D0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
Vector2D *sub_42F5D0()
{
  return Vector2D::Vector2D(this: &stru_440704, X: 0.0, Y: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x0042F620
// Name: sub_42F620
// Source: linker_block_proximity
//------------------------------------------------------------------------------
Vector2D *sub_42F620()
{
  return Vector2D::Vector2D(this: &stru_44070C, X: 3.4028235e38, Y: 3.4028235e38);
}

//------------------------------------------------------------------------------
// Address: 0x0042F670
// Name: sub_42F670
// Source: linker_block_proximity
//------------------------------------------------------------------------------
Vector2D *sub_42F670()
{
  return Vector2D::Vector2D(this: &stru_440820, X: 0.0, Y: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x0042F6C0
// Name: sub_42F6C0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
Vector2D *sub_42F6C0()
{
  return Vector2D::Vector2D(this: &stru_440828, X: 3.4028235e38, Y: 3.4028235e38);
}

//------------------------------------------------------------------------------
// Address: 0x0042F710
// Name: _dynamic_initializer_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyConVar__()
{
  long double v0; // st7

  s_EmptyConVar.m_Value.m_StringLength = strlen("0") + 1;
  s_EmptyConVar.m_Value.m_pszString = (char *)operator new(nSize: s_EmptyConVar.m_Value.m_StringLength);
  memcpy(
    dst: (unsigned __int8 *)s_EmptyConVar.m_Value.m_pszString,
    src: (unsigned __int8 *)s_EmptyConVar.m_pszDefaultValue,
    count: s_EmptyConVar.m_Value.m_StringLength);
  v0 = atof(nptr: s_EmptyConVar.m_Value.m_pszString);
  s_EmptyConVar.m_Value.m_fValue = v0;
  s_EmptyConVar.m_pszHelpString = empty_string;
  s_EmptyConVar.m_Value.m_nValue = (int)v0;
  s_EmptyConVar.m_bRegistered = false;
  s_EmptyConVar.m_pszName = defaultValue;
  s_EmptyConVar.m_nFlags = 0;
  s_EmptyConVar.m_pNext = ConCommandBase::s_pConCommandBases;
  ConCommandBase::s_pConCommandBases = &s_EmptyConVar;
  if ( ConCommandBase::s_pAccessor != nullptr )
    ((void (*)(void))s_EmptyConVar.Init)();
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&CEmptyConVar::`vftable'{for `ConCommandBase'};
  s_EmptyConVar.ConVar::IConVar::__vftable = (IConVar_vtbl *)&CEmptyConVar::`vftable'{for `IConVar'};
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyConVar__);
}

//------------------------------------------------------------------------------
// Address: 0x0042F7E0
// Name: _dynamic_initializer_for__g_KVMutex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_KVMutex__()
{
  g_KVMutex.m_ownerID = 0;
  g_KVMutex.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0042F7F0
// Name: _dynamic_initializer_for__s_StringCharConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char **dynamic_initializer_for__s_StringCharConversion__()
{
  char **result; // eax
  int v1; // edx
  char v2; // cl

  CUtlCharConversion::CUtlCharConversion(
    this: &s_StringCharConversion,
    nEscapeChar: 92,
    pDelimiter: "\"",
    nCount: 11,
    pArray: s_pConversionArrays_StringCharConversion);
  s_StringCharConversion.__vftable = (CUtlCStringConversion_vtbl *)&CUtlCStringConversion::`vftable';
  memset(
    dst: (int)s_StringCharConversion.m_pConversion,
    value: nullptr,
    count: sizeof(s_StringCharConversion.m_pConversion));
  result = &s_pConversionArrays_StringCharConversion[0].m_pReplacementString;
  do
  {
    v1 = **result;
    v2 = *((_BYTE *)result - 4);
    result += 2;
    s_StringCharConversion.m_pConversion[v1] = v2;
  }
  while ( (int)result < (int)&s_pConversionArrays_NoEscConversion[0].m_pReplacementString );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042F850
// Name: _dynamic_initializer_for__s_NoEscConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CUtlCharConversion *dynamic_initializer_for__s_NoEscConversion__()
{
  CUtlCharConversion *result; // eax

  result = CUtlCharConversion::CUtlCharConversion(
             this: &s_NoEscConversion,
             nEscapeChar: 127,
             pDelimiter: "\"",
             nCount: 1,
             pArray: s_pConversionArrays_NoEscConversion);
  s_NoEscConversion.__vftable = (CUtlNoEscConversion_vtbl *)&CUtlNoEscConversion::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042F880
// Name: sub_42F880
// Source: linker_block_proximity
//------------------------------------------------------------------------------
Vector2D *sub_42F880()
{
  return Vector2D::Vector2D(this: &stru_451700, X: 0.0, Y: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x0042F8D0
// Name: sub_42F8D0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
Vector2D *sub_42F8D0()
{
  return Vector2D::Vector2D(this: &stru_451718, X: 3.4028235e38, Y: 3.4028235e38);
}

//------------------------------------------------------------------------------
// Address: 0x0042F920
// Name: sub_42F920
// Source: linker_block_proximity
//------------------------------------------------------------------------------
Vector4D *sub_42F920()
{
  return Vector4D::Vector4D(this: &stru_4516F0, X: 0.0, Y: 0.0, Z: 0.0, W: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x0042F980
// Name: sub_42F980
// Source: linker_block_proximity
//------------------------------------------------------------------------------
Vector4D *sub_42F980()
{
  return Vector4D::Vector4D(this: &stru_451708, X: 3.4028235e38, Y: 3.4028235e38, Z: 3.4028235e38, W: 3.4028235e38);
}

//------------------------------------------------------------------------------
// Address: 0x0042F9F0
// Name: sub_42F9F0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
Vector2D *sub_42F9F0()
{
  return Vector2D::Vector2D(this: &stru_451760, X: 0.0, Y: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x0042FA40
// Name: sub_42FA40
// Source: linker_block_proximity
//------------------------------------------------------------------------------
Vector2D *sub_42FA40()
{
  return Vector2D::Vector2D(this: &stru_451778, X: 3.4028235e38, Y: 3.4028235e38);
}

//------------------------------------------------------------------------------
// Address: 0x0042FA90
// Name: sub_42FA90
// Source: linker_block_proximity
//------------------------------------------------------------------------------
Vector4D *sub_42FA90()
{
  return Vector4D::Vector4D(this: &stru_451750, X: 0.0, Y: 0.0, Z: 0.0, W: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x0042FAF0
// Name: sub_42FAF0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
Vector4D *sub_42FAF0()
{
  return Vector4D::Vector4D(this: &stru_451768, X: 3.4028235e38, Y: 3.4028235e38, Z: 3.4028235e38, W: 3.4028235e38);
}

//------------------------------------------------------------------------------
// Address: 0x0042FB60
// Name: sub_42FB60
// Source: linker_block_proximity
//------------------------------------------------------------------------------
matrix3x4_t *sub_42FB60()
{
  return matrix3x4_t::matrix3x4_t(
           this: &in2,
           a2: 0.0,
           a3: 0.0,
           a4: -1.0,
           a5: 0.0,
           a6: -1.0,
           a7: 0.0,
           a8: 0.0,
           a9: 0.0,
           a10: 0.0,
           a11: 1.0,
           a12: 0.0,
           a13: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x0042FBF0
// Name: sub_42FBF0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
Vector2D *sub_42FBF0()
{
  return Vector2D::Vector2D(this: &stru_451794, X: 0.0, Y: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x0042FC40
// Name: sub_42FC40
// Source: linker_block_proximity
//------------------------------------------------------------------------------
Vector2D *sub_42FC40()
{
  return Vector2D::Vector2D(this: &stru_45179C, X: 3.4028235e38, Y: 3.4028235e38);
}

//------------------------------------------------------------------------------
// Address: 0x0042FC90
// Name: _dynamic_atexit_destructor_for____s_SteamApplicationObject__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____s_SteamApplicationObject__()
{
  CUtlDict<int,unsigned short>::RemoveAll(this: &_s_SteamApplicationObject.m_SystemDict);
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &_s_SteamApplicationObject.m_SystemDict.m_Elements.m_Tree);
  CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int>>::~CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int>>(this: &_s_SteamApplicationObject.m_Systems);
  CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int>>::~CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int>>(this: (CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int> > *)&_s_SteamApplicationObject.m_Modules);
}

//------------------------------------------------------------------------------
// Address: 0x0042FCC0
// Name: _dynamic_atexit_destructor_for____s_ApplicationObject__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____s_ApplicationObject__()
{
  CUtlDict<int,unsigned short>::RemoveAll(this: &_s_ApplicationObject.m_SystemDict);
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &_s_ApplicationObject.m_SystemDict.m_Elements.m_Tree);
  CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int>>::~CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int>>(this: &_s_ApplicationObject.m_Systems);
  CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int>>::~CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int>>(this: (CUtlVector<IAppSystem *,CUtlMemory<IAppSystem *,int> > *)&_s_ApplicationObject.m_Modules);
}

//------------------------------------------------------------------------------
// Address: 0x0042FCF0
// Name: _dynamic_atexit_destructor_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyConVar__()
{
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConVar::`vftable'{for `ConCommandBase'};
  s_EmptyConVar.ConVar::IConVar::__vftable = (IConVar_vtbl *)&ConVar::`vftable'{for `IConVar'};
  if ( s_EmptyConVar.m_Value.m_pszString != nullptr )
  {
    free(pMem: s_EmptyConVar.m_Value.m_pszString);
    s_EmptyConVar.m_Value.m_pszString = nullptr;
  }
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConCommandBase::`vftable';
}

} // namespace worldrenderertest

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x102C81A0
// Name: public: class VMatrix __near & VMatrix::operator=(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
VMatrix *__thiscall VMatrix::operator=(VMatrix *this, const VMatrix *mOther)
{
  *this = *mOther;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102C8210
// Name: public: void VMatrix::MatrixMul(class VMatrix const __near &,class VMatrix __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall VMatrix::MatrixMul(VMatrix *this, const VMatrix *vm, VMatrix *out)
{
  float v4; // xmm0_4
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm4_4
  float v8; // xmm5_4
  float v9; // xmm1_4
  float v10; // xmm7_4
  float v11; // xmm6_4
  float v12; // xmm0_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm3_4
  float v18; // xmm1_4
  float v19; // [esp+0h] [ebp-3Ch]
  float v20; // [esp+4h] [ebp-38h]
  float v21; // [esp+8h] [ebp-34h]
  float v22; // [esp+Ch] [ebp-30h]
  float v23; // [esp+10h] [ebp-2Ch]
  float v24; // [esp+14h] [ebp-28h]
  float v25; // [esp+18h] [ebp-24h]
  float v26; // [esp+1Ch] [ebp-20h]
  float v27; // [esp+20h] [ebp-1Ch]
  float v28; // [esp+24h] [ebp-18h]
  float v29; // [esp+28h] [ebp-14h]
  float v30; // [esp+28h] [ebp-14h]
  float v31; // [esp+28h] [ebp-14h]
  float v32; // [esp+2Ch] [ebp-10h]
  float v33; // [esp+30h] [ebp-Ch]
  float v34; // [esp+34h] [ebp-8h]
  __int64 v35; // [esp+34h] [ebp-8h]
  __int64 v36; // [esp+34h] [ebp-8h]
  float v37; // [esp+38h] [ebp-4h]
  float vma; // [esp+44h] [ebp+8h]

  v4 = this->m[0][1];
  v5 = this->m[0][2];
  v6 = this->m[0][3];
  v7 = (float)((float)((float)(this->m[0][0] * vm->m[0][1]) + (float)(v4 * vm->m[1][1])) + (float)(v5 * vm->m[2][1]))
     + (float)(v6 * vm->m[3][1]);
  v8 = (float)((float)((float)(vm->m[0][2] * this->m[0][0]) + (float)(vm->m[1][2] * v4)) + (float)(vm->m[2][2] * v5))
     + (float)(vm->m[3][2] * v6);
  v33 = vm->m[2][0];
  v37 = this->m[1][2];
  v32 = vm->m[3][0];
  v34 = this->m[1][3];
  v9 = vm->m[0][0];
  v10 = vm->m[1][0];
  v29 = this->m[1][1];
  v11 = (float)((float)((float)(vm->m[0][3] * this->m[0][0]) + (float)(vm->m[1][3] * v4)) + (float)(vm->m[2][3] * v5))
      + (float)(vm->m[3][3] * v6);
  v12 = this->m[1][0];
  v28 = (float)((float)((float)(vm->m[0][0] * v12) + (float)(v29 * v10)) + (float)(v37 * v33)) + (float)(v34 * v32);
  v27 = (float)((float)((float)(v12 * vm->m[0][1]) + (float)(v29 * vm->m[1][1])) + (float)(v37 * vm->m[2][1]))
      + (float)(v34 * vm->m[3][1]);
  v26 = (float)((float)((float)(v12 * vm->m[0][2]) + (float)(v29 * vm->m[1][2])) + (float)(v37 * vm->m[2][2]))
      + (float)(v34 * vm->m[3][2]);
  v13 = this->m[2][0];
  v25 = (float)((float)((float)(v12 * vm->m[0][3]) + (float)(v29 * vm->m[1][3])) + (float)(v37 * vm->m[2][3]))
      + (float)(v34 * vm->m[3][3]);
  v35 = *(_QWORD *)&this->m[2][2];
  v30 = this->m[2][1];
  v24 = (float)((float)((float)(v13 * vm->m[0][0]) + (float)(v30 * v10)) + (float)(*(float *)&v35 * v33))
      + (float)(*((float *)&v35 + 1) * v32);
  v23 = (float)((float)((float)(v13 * vm->m[0][1]) + (float)(v30 * vm->m[1][1])) + (float)(*(float *)&v35 * vm->m[2][1]))
      + (float)(*((float *)&v35 + 1) * vm->m[3][1]);
  v22 = (float)((float)((float)(v13 * vm->m[0][2]) + (float)(v30 * vm->m[1][2])) + (float)(*(float *)&v35 * vm->m[2][2]))
      + (float)(*((float *)&v35 + 1) * vm->m[3][2]);
  v21 = (float)((float)((float)(v13 * vm->m[0][3]) + (float)(v30 * vm->m[1][3])) + (float)(*(float *)&v35 * vm->m[2][3]))
      + (float)(*((float *)&v35 + 1) * vm->m[3][3]);
  v14 = this->m[3][0];
  v36 = *(_QWORD *)&this->m[3][2];
  v31 = this->m[3][1];
  v20 = (float)((float)((float)(v14 * vm->m[0][0]) + (float)(v31 * v10)) + (float)(*(float *)&v36 * v33))
      + (float)(*((float *)&v36 + 1) * v32);
  v19 = (float)((float)((float)(v14 * vm->m[0][1]) + (float)(v31 * vm->m[1][1])) + (float)(*(float *)&v36 * vm->m[2][1]))
      + (float)(*((float *)&v36 + 1) * vm->m[3][1]);
  v15 = v14 * vm->m[0][2];
  v16 = v14 * vm->m[0][3];
  vma = (float)((float)(v15 + (float)(v31 * vm->m[1][2])) + (float)(*(float *)&v36 * vm->m[2][2]))
      + (float)(*((float *)&v36 + 1) * vm->m[3][2]);
  v17 = (float)((float)(v16 + (float)(v31 * vm->m[1][3])) + (float)(*(float *)&v36 * vm->m[2][3]))
      + (float)(*((float *)&v36 + 1) * vm->m[3][3]);
  v18 = (float)((float)((float)(v9 * this->m[0][0]) + (float)(v10 * this->m[0][1])) + (float)(v33 * this->m[0][2]))
      + (float)(v32 * this->m[0][3]);
  out->m[1][0] = v28;
  out->m[1][1] = v27;
  out->m[1][2] = v26;
  out->m[1][3] = v25;
  out->m[0][0] = v18;
  out->m[0][1] = v7;
  out->m[0][2] = v8;
  out->m[0][3] = v11;
  out->m[2][0] = v24;
  out->m[2][1] = v23;
  out->m[2][2] = v22;
  out->m[2][3] = v21;
  out->m[3][0] = v20;
  out->m[3][1] = v19;
  out->m[3][2] = vma;
  out->m[3][3] = v17;
}

//------------------------------------------------------------------------------
// Address: 0x102C86F0
// Name: public: void VMatrix::SetupMatrixOrgAngles(class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VMatrix::SetupMatrixOrgAngles(VMatrix *this, const Vector *origin, const QAngle *vAngles)
{
  float v4; // xmm1_4
  float v5; // xmm1_4
  double z; // st7
  float v7; // [esp+8h] [ebp-18h]
  float cr; // [esp+Ch] [ebp-14h]
  float sr; // [esp+10h] [ebp-10h]
  float sy; // [esp+14h] [ebp-Ch]
  float cy; // [esp+18h] [ebp-8h]
  float cp; // [esp+1Ch] [ebp-4h]
  float vAnglesa; // [esp+2Ch] [ebp+Ch]

  v4 = vAngles->y * 0.017453292;
  cy = cos(v4);
  sy = sin(v4);
  v5 = vAngles->x * 0.017453292;
  cp = cos(v5);
  vAnglesa = sin(v5);
  v7 = vAngles->z * 0.017453292;
  cr = cos(v7);
  sr = sin(v7);
  this->m[0][0] = cp * cy;
  this->m[1][0] = cp * sy;
  LODWORD(this->m[2][0]) = LODWORD(vAnglesa) ^ _mask__NegFloat_;
  this->m[0][1] = (float)((float)(sr * vAnglesa) * cy) - (float)(cr * sy);
  this->m[1][1] = (float)((float)(sr * vAnglesa) * sy) + (float)(cr * cy);
  this->m[2][1] = sr * cp;
  this->m[1][2] = (float)((float)(cr * vAnglesa) * sy) - (float)(sr * cy);
  this->m[0][3] = 0.0;
  this->m[1][3] = 0.0;
  this->m[2][3] = 0.0;
  this->m[0][2] = (float)((float)(cr * vAnglesa) * cy) + (float)(sr * sy);
  this->m[2][2] = cr * cp;
  this->m[0][3] = origin->x;
  this->m[1][3] = origin->y;
  z = origin->z;
  this->m[3][0] = 0.0;
  this->m[2][3] = z;
  *(_QWORD *)&this->m[3][1] = 0;
  this->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x102C8880
// Name: void MatrixSetIdentity(class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixSetIdentity(VMatrix *dst)
{
  *(_QWORD *)&dst->m[0][0] = 1065353216;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = 0.0;
  *(_QWORD *)&dst->m[1][1] = 1065353216;
  dst->m[1][3] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[2][2] = 1065353216;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x102C8A30
// Name: void MatrixTranspose(class VMatrix const __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixTranspose(const VMatrix *src, VMatrix *dst)
{
  float v2; // xmm0_4
  float v3; // xmm0_4
  float v4; // xmm0_4
  float v5; // xmm0_4
  float v6; // xmm0_4
  float v7; // xmm0_4

  if ( src == dst )
  {
    v2 = dst->m[0][1];
    dst->m[0][1] = dst->m[1][0];
    dst->m[1][0] = v2;
    v3 = dst->m[0][2];
    dst->m[0][2] = dst->m[2][0];
    dst->m[2][0] = v3;
    v4 = dst->m[0][3];
    dst->m[0][3] = dst->m[3][0];
    dst->m[3][0] = v4;
    v5 = dst->m[1][2];
    dst->m[1][2] = dst->m[2][1];
    dst->m[2][1] = v5;
    v6 = dst->m[1][3];
    dst->m[1][3] = dst->m[3][1];
    dst->m[3][1] = v6;
    v7 = dst->m[2][3];
    dst->m[2][3] = dst->m[3][2];
    dst->m[3][2] = v7;
  }
  else
  {
    dst->m[0][0] = src->m[0][0];
    dst->m[0][1] = src->m[1][0];
    dst->m[0][2] = src->m[2][0];
    dst->m[0][3] = src->m[3][0];
    dst->m[1][0] = src->m[0][1];
    dst->m[1][1] = src->m[1][1];
    dst->m[1][2] = src->m[2][1];
    dst->m[1][3] = src->m[3][1];
    dst->m[2][0] = src->m[0][2];
    dst->m[2][1] = src->m[1][2];
    dst->m[2][2] = src->m[2][2];
    dst->m[2][3] = src->m[3][2];
    dst->m[3][0] = src->m[0][3];
    dst->m[3][1] = src->m[1][3];
    dst->m[3][2] = src->m[2][3];
    dst->m[3][3] = src->m[3][3];
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C8B20
// Name: void MatrixMultiply(class VMatrix const __near &,class VMatrix const __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixMultiply(VMatrix *src1, VMatrix *src2, VMatrix *dst)
{
  float *p_tmp1; // edx
  VMatrix *v4; // edi
  float *p_tmp2; // eax
  VMatrix tmp2; // [esp+Ch] [ebp-80h] BYREF
  VMatrix tmp1; // [esp+4Ch] [ebp-40h] BYREF

  p_tmp1 = (float *)&tmp1;
  if ( src1 != dst )
    p_tmp1 = (float *)src1;
  v4 = src2;
  p_tmp2 = (float *)&tmp2;
  if ( src2 != dst )
    p_tmp2 = (float *)src2;
  if ( src1 == dst && src1 != &tmp1 )
  {
    tmp1 = *src1;
    v4 = src2;
  }
  if ( v4 == dst && v4 != &tmp2 )
    tmp2 = *v4;
  dst->m[0][0] = (float)((float)((float)(p_tmp1[1] * p_tmp2[4]) + (float)(*p_tmp2 * *p_tmp1))
                       + (float)(p_tmp2[8] * p_tmp1[2]))
               + (float)(p_tmp2[12] * p_tmp1[3]);
  dst->m[0][1] = (float)((float)((float)(p_tmp1[1] * p_tmp2[5]) + (float)(*p_tmp1 * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[2]))
               + (float)(p_tmp2[13] * p_tmp1[3]);
  dst->m[0][2] = (float)((float)((float)(p_tmp1[1] * p_tmp2[6]) + (float)(*p_tmp1 * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[2]))
               + (float)(p_tmp2[14] * p_tmp1[3]);
  dst->m[0][3] = (float)((float)((float)(p_tmp1[1] * p_tmp2[7]) + (float)(*p_tmp1 * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[2]))
               + (float)(p_tmp2[15] * p_tmp1[3]);
  dst->m[1][0] = (float)((float)((float)(p_tmp1[5] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[4]))
                       + (float)(p_tmp2[8] * p_tmp1[6]))
               + (float)(p_tmp2[12] * p_tmp1[7]);
  dst->m[1][1] = (float)((float)((float)(p_tmp1[5] * p_tmp2[5]) + (float)(p_tmp1[4] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[6]))
               + (float)(p_tmp2[13] * p_tmp1[7]);
  dst->m[1][2] = (float)((float)((float)(p_tmp1[5] * p_tmp2[6]) + (float)(p_tmp1[4] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[6]))
               + (float)(p_tmp2[14] * p_tmp1[7]);
  dst->m[1][3] = (float)((float)((float)(p_tmp1[5] * p_tmp2[7]) + (float)(p_tmp1[4] * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[6]))
               + (float)(p_tmp1[7] * p_tmp2[15]);
  dst->m[2][0] = (float)((float)((float)(p_tmp1[9] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[8]))
                       + (float)(p_tmp2[8] * p_tmp1[10]))
               + (float)(p_tmp2[12] * p_tmp1[11]);
  dst->m[2][1] = (float)((float)((float)(p_tmp1[9] * p_tmp2[5]) + (float)(p_tmp1[8] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[10]))
               + (float)(p_tmp2[13] * p_tmp1[11]);
  dst->m[2][2] = (float)((float)((float)(p_tmp1[9] * p_tmp2[6]) + (float)(p_tmp1[8] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[10]))
               + (float)(p_tmp2[14] * p_tmp1[11]);
  dst->m[2][3] = (float)((float)((float)(p_tmp1[8] * p_tmp2[3]) + (float)(p_tmp1[9] * p_tmp2[7]))
                       + (float)(p_tmp2[11] * p_tmp1[10]))
               + (float)(p_tmp1[11] * p_tmp2[15]);
  dst->m[3][0] = (float)((float)((float)(p_tmp1[13] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[12]))
                       + (float)(p_tmp2[8] * p_tmp1[14]))
               + (float)(p_tmp2[12] * p_tmp1[15]);
  dst->m[3][1] = (float)((float)((float)(p_tmp1[13] * p_tmp2[5]) + (float)(p_tmp1[12] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[14]))
               + (float)(p_tmp2[13] * p_tmp1[15]);
  dst->m[3][2] = (float)((float)((float)(p_tmp1[13] * p_tmp2[6]) + (float)(p_tmp1[12] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[14]))
               + (float)(p_tmp2[14] * p_tmp1[15]);
  dst->m[3][3] = (float)((float)((float)(p_tmp1[13] * p_tmp2[7]) + (float)(p_tmp1[12] * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[14]))
               + (float)(p_tmp1[15] * p_tmp2[15]);
}

//------------------------------------------------------------------------------
// Address: 0x102C8F10
// Name: void Vector3DMultiply(class VMatrix const __near &,class Vector const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Vector3DMultiply(const VMatrix *src1, const Vector *src2, Vector *dst)
{
  Vector *p_tmp; // eax
  __int64 v4; // xmm0_8
  float z; // edx
  float v6; // xmm3_4
  float v7; // xmm2_4
  float v8; // xmm4_4
  Vector tmp; // [esp+0h] [ebp-18h] BYREF
  __int64 v10; // [esp+Ch] [ebp-Ch]
  float v11; // [esp+14h] [ebp-4h]

  p_tmp = src2;
  if ( src2 == dst )
    p_tmp = &tmp;
  v4 = *(_QWORD *)&p_tmp->x;
  z = p_tmp->z;
  v6 = src1->m[0][1];
  v7 = src1->m[0][0];
  v8 = src1->m[0][2];
  v10 = v4;
  v11 = z;
  dst->x = (float)((float)(v6 * *((float *)&v4 + 1)) + (float)(v7 * *(float *)&v4)) + (float)(v8 * z);
  dst->y = (float)((float)(src1->m[1][0] * *(float *)&v4) + (float)(src1->m[1][1] * *((float *)&v4 + 1)))
         + (float)(src1->m[1][2] * z);
  dst->z = (float)((float)(src1->m[2][0] * *(float *)&v4) + (float)(src1->m[2][1] * *((float *)&v4 + 1)))
         + (float)(src1->m[2][2] * z);
}

//------------------------------------------------------------------------------
// Address: 0x102C8FD0
// Name: void Vector3DMultiplyPositionProjective(class VMatrix const __near &,class Vector const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Vector3DMultiplyPositionProjective(const VMatrix *src1, const Vector *src2, Vector *dst)
{
  Vector *p_tmp; // eax
  float z; // ecx
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm0_4
  float v8; // xmm4_4
  Vector tmp; // [esp+0h] [ebp-18h] BYREF
  __int64 v10; // [esp+Ch] [ebp-Ch]
  float v11; // [esp+14h] [ebp-4h]

  p_tmp = src2;
  if ( src2 == dst )
    p_tmp = &tmp;
  z = p_tmp->z;
  v10 = *(_QWORD *)&p_tmp->x;
  v5 = *(float *)&v10;
  v6 = *((float *)&v10 + 1);
  v11 = z;
  v7 = (float)((float)((float)(src1->m[3][0] * *(float *)&v10) + (float)(src1->m[3][1] * *((float *)&v10 + 1)))
             + (float)(src1->m[3][2] * z))
     + src1->m[3][3];
  if ( v7 != 0.0 )
    v7 = 1.0 / v7;
  dst->x = (float)((float)((float)(src1->m[0][1] * *((float *)&v10 + 1)) + (float)(src1->m[0][0] * *(float *)&v10))
                 + (float)(src1->m[0][2] * v11))
         + src1->m[0][3];
  dst->y = (float)((float)((float)(src1->m[1][0] * v5) + (float)(src1->m[1][1] * v6)) + (float)(src1->m[1][2] * z))
         + src1->m[1][3];
  v8 = (float)((float)((float)(src1->m[2][0] * v5) + (float)(src1->m[2][1] * v6)) + (float)(src1->m[2][2] * z))
     + src1->m[2][3];
  dst->x = dst->x * v7;
  dst->y = dst->y * v7;
  dst->z = v8 * v7;
}

//------------------------------------------------------------------------------
// Address: 0x102C9110
// Name: void MatrixBuildTranslation(class VMatrix __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildTranslation(VMatrix *dst, float x, float y, float z)
{
  *(_QWORD *)&dst->m[0][1] = 0;
  dst->m[1][0] = 0.0;
  dst->m[1][2] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[0][3] = x;
  dst->m[1][3] = y;
  dst->m[0][0] = 1.0;
  dst->m[1][1] = 1.0;
  dst->m[2][2] = 1.0;
  dst->m[3][3] = 1.0;
  dst->m[2][3] = z;
}

//------------------------------------------------------------------------------
// Address: 0x102C9190
// Name: void MatrixBuildTranslation(class VMatrix __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildTranslation(VMatrix *dst, const Vector *translation)
{
  dst->m[0][3] = 0.0;
  dst->m[1][3] = 0.0;
  dst->m[2][3] = 0.0;
  *(_QWORD *)&dst->m[0][0] = 1065353216;
  dst->m[0][2] = 0.0;
  dst->m[1][0] = 0.0;
  *(_QWORD *)&dst->m[1][1] = 1065353216;
  *(_QWORD *)&dst->m[2][0] = 0;
  dst->m[2][2] = 1.0;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[3][3] = 1.0;
  dst->m[0][3] = translation->x;
  dst->m[1][3] = translation->y;
  dst->m[2][3] = translation->z;
}

//------------------------------------------------------------------------------
// Address: 0x102C9260
// Name: void MatrixBuildRotateZ(class VMatrix __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildRotateZ(VMatrix *dst, float angleDegrees)
{
  long double fSin; // [esp+0h] [ebp-4h]
  long double fSina; // [esp+0h] [ebp-4h]
  float fSinb; // [esp+0h] [ebp-4h]
  float radians; // [esp+10h] [ebp+Ch]

  radians = angleDegrees * 0.0174532925199433;
  __libm_sse2_sin(x: fSin);
  *(float *)&fSina = radians;
  __libm_sse2_cos(x: fSina);
  dst->m[0][0] = radians;
  LODWORD(dst->m[0][1]) = LODWORD(fSinb) ^ _mask__NegFloat_;
  dst->m[1][1] = radians;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = fSinb;
  *(_QWORD *)&dst->m[1][2] = 0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[2][2] = 1065353216;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x102C9320
// Name: void MatrixBuildScale(class VMatrix __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildScale(VMatrix *dst, unsigned int x, unsigned int y, float z)
{
  *(_QWORD *)&dst->m[0][0] = x;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = 0.0;
  *(_QWORD *)&dst->m[1][1] = y;
  dst->m[1][3] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  dst->m[2][3] = 0.0;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[2][2] = z;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x102C93A0
// Name: void CalculateAABBFromProjectionMatrixInverse(class VMatrix const __near &,class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CalculateAABBFromProjectionMatrixInverse(const VMatrix *volumeToWorld, Vector *pMins, Vector *pMaxs)
{
  float v3; // xmm1_4
  float v4; // xmm2_4
  float v5; // xmm3_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm2_4
  float v10; // xmm3_4
  float v11; // xmm0_4
  float v12; // xmm3_4
  float v13; // xmm4_4
  float v14; // xmm0_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm0_4
  float v18; // xmm3_4
  float v19; // xmm4_4
  float v20; // xmm0_4
  float v21; // xmm2_4
  float v22; // xmm3_4
  float v23; // xmm0_4
  float v24; // xmm2_4
  float v25; // xmm3_4
  float v26; // xmm0_4
  float v27; // xmm2_4
  float v28; // xmm3_4
  Vector v; // [esp+Ch] [ebp-Ch] BYREF

  ClearBounds(mins: pMins, maxs: pMaxs);
  v3 = (float)((float)((float)(volumeToWorld->m[3][1] + volumeToWorld->m[3][0]) + volumeToWorld->m[3][2]) * 0.0)
     + volumeToWorld->m[3][3];
  if ( v3 != 0.0 )
    v3 = 1.0 / v3;
  v4 = (float)(volumeToWorld->m[1][1] + volumeToWorld->m[1][0]) + volumeToWorld->m[1][2];
  v5 = (float)(volumeToWorld->m[2][1] + volumeToWorld->m[2][0]) + volumeToWorld->m[2][2];
  v.x = (float)((float)((float)((float)(volumeToWorld->m[0][0] + volumeToWorld->m[0][1]) + volumeToWorld->m[0][2]) * 0.0)
              + volumeToWorld->m[0][3])
      * v3;
  v6 = v3 * (float)((float)(v4 * 0.0) + volumeToWorld->m[1][3]);
  v7 = v3 * (float)((float)(v5 * 0.0) + volumeToWorld->m[2][3]);
  v.y = v6;
  v.z = v7;
  AddPointToBounds(&v, mins: pMins, maxs: pMaxs);
  v8 = (float)((float)((float)(volumeToWorld->m[3][1] + volumeToWorld->m[3][0]) * 0.0) + volumeToWorld->m[3][2])
     + volumeToWorld->m[3][3];
  if ( v8 != 0.0 )
    v8 = 1.0 / v8;
  v9 = (float)((float)((float)((float)(volumeToWorld->m[1][1] + volumeToWorld->m[1][0]) * 0.0) + volumeToWorld->m[1][2])
             + volumeToWorld->m[1][3])
     * v8;
  v10 = (float)((float)((float)((float)(volumeToWorld->m[2][1] + volumeToWorld->m[2][0]) * 0.0) + volumeToWorld->m[2][2])
              + volumeToWorld->m[2][3])
      * v8;
  v.x = (float)((float)((float)((float)(volumeToWorld->m[0][0] + volumeToWorld->m[0][1]) * 0.0) + volumeToWorld->m[0][2])
              + volumeToWorld->m[0][3])
      * v8;
  v.y = v9;
  v.z = v10;
  AddPointToBounds(&v, mins: pMins, maxs: pMaxs);
  v11 = (float)((float)((float)(volumeToWorld->m[3][0] * 0.0) + volumeToWorld->m[3][1])
              + (float)(volumeToWorld->m[3][2] * 0.0))
      + volumeToWorld->m[3][3];
  if ( v11 != 0.0 )
    v11 = 1.0 / v11;
  v12 = (float)((float)((float)((float)(volumeToWorld->m[1][0] * 0.0) + volumeToWorld->m[1][1])
                      + (float)(volumeToWorld->m[1][2] * 0.0))
              + volumeToWorld->m[1][3])
      * v11;
  v13 = (float)((float)((float)((float)(volumeToWorld->m[2][0] * 0.0) + volumeToWorld->m[2][1])
                      + (float)(volumeToWorld->m[2][2] * 0.0))
              + volumeToWorld->m[2][3])
      * v11;
  v.x = (float)((float)((float)((float)(volumeToWorld->m[0][0] * 0.0) + volumeToWorld->m[0][1])
                      + (float)(volumeToWorld->m[0][2] * 0.0))
              + volumeToWorld->m[0][3])
      * v11;
  v.y = v12;
  v.z = v13;
  AddPointToBounds(&v, mins: pMins, maxs: pMaxs);
  v14 = (float)((float)((float)(volumeToWorld->m[3][0] * 0.0) + volumeToWorld->m[3][1]) + volumeToWorld->m[3][2])
      + volumeToWorld->m[3][3];
  if ( v14 != 0.0 )
    v14 = 1.0 / v14;
  v15 = (float)((float)((float)((float)(volumeToWorld->m[1][0] * 0.0) + volumeToWorld->m[1][1]) + volumeToWorld->m[1][2])
              + volumeToWorld->m[1][3])
      * v14;
  v16 = (float)((float)((float)((float)(volumeToWorld->m[2][0] * 0.0) + volumeToWorld->m[2][1]) + volumeToWorld->m[2][2])
              + volumeToWorld->m[2][3])
      * v14;
  v.x = (float)((float)((float)((float)(volumeToWorld->m[0][0] * 0.0) + volumeToWorld->m[0][1]) + volumeToWorld->m[0][2])
              + volumeToWorld->m[0][3])
      * v14;
  v.y = v15;
  v.z = v16;
  AddPointToBounds(&v, mins: pMins, maxs: pMaxs);
  v17 = (float)((float)((float)(volumeToWorld->m[3][1] * 0.0) + volumeToWorld->m[3][0])
              + (float)(volumeToWorld->m[3][2] * 0.0))
      + volumeToWorld->m[3][3];
  if ( v17 != 0.0 )
    v17 = 1.0 / v17;
  v18 = (float)((float)((float)((float)(volumeToWorld->m[1][1] * 0.0) + volumeToWorld->m[1][0])
                      + (float)(volumeToWorld->m[1][2] * 0.0))
              + volumeToWorld->m[1][3])
      * v17;
  v19 = (float)((float)((float)((float)(volumeToWorld->m[2][1] * 0.0) + volumeToWorld->m[2][0])
                      + (float)(volumeToWorld->m[2][2] * 0.0))
              + volumeToWorld->m[2][3])
      * v17;
  v.x = (float)((float)((float)((float)(volumeToWorld->m[0][1] * 0.0) + volumeToWorld->m[0][0])
                      + (float)(volumeToWorld->m[0][2] * 0.0))
              + volumeToWorld->m[0][3])
      * v17;
  v.y = v18;
  v.z = v19;
  AddPointToBounds(&v, mins: pMins, maxs: pMaxs);
  v20 = (float)((float)((float)(volumeToWorld->m[3][1] * 0.0) + volumeToWorld->m[3][0]) + volumeToWorld->m[3][2])
      + volumeToWorld->m[3][3];
  if ( v20 != 0.0 )
    v20 = 1.0 / v20;
  v21 = (float)((float)((float)((float)(volumeToWorld->m[1][1] * 0.0) + volumeToWorld->m[1][0]) + volumeToWorld->m[1][2])
              + volumeToWorld->m[1][3])
      * v20;
  v22 = (float)((float)((float)((float)(volumeToWorld->m[2][1] * 0.0) + volumeToWorld->m[2][0]) + volumeToWorld->m[2][2])
              + volumeToWorld->m[2][3])
      * v20;
  v.x = (float)((float)((float)((float)(volumeToWorld->m[0][1] * 0.0) + volumeToWorld->m[0][0]) + volumeToWorld->m[0][2])
              + volumeToWorld->m[0][3])
      * v20;
  v.y = v21;
  v.z = v22;
  AddPointToBounds(&v, mins: pMins, maxs: pMaxs);
  v23 = (float)((float)(volumeToWorld->m[3][1] + volumeToWorld->m[3][0]) + (float)(volumeToWorld->m[3][2] * 0.0))
      + volumeToWorld->m[3][3];
  if ( v23 != 0.0 )
    v23 = 1.0 / v23;
  v24 = (float)((float)((float)(volumeToWorld->m[1][1] + volumeToWorld->m[1][0]) + (float)(volumeToWorld->m[1][2] * 0.0))
              + volumeToWorld->m[1][3])
      * v23;
  v25 = (float)((float)((float)(volumeToWorld->m[2][1] + volumeToWorld->m[2][0]) + (float)(volumeToWorld->m[2][2] * 0.0))
              + volumeToWorld->m[2][3])
      * v23;
  v.x = (float)((float)((float)(volumeToWorld->m[0][0] + volumeToWorld->m[0][1]) + (float)(volumeToWorld->m[0][2] * 0.0))
              + volumeToWorld->m[0][3])
      * v23;
  v.y = v24;
  v.z = v25;
  AddPointToBounds(&v, mins: pMins, maxs: pMaxs);
  v26 = (float)((float)(volumeToWorld->m[3][1] + volumeToWorld->m[3][0]) + volumeToWorld->m[3][2])
      + volumeToWorld->m[3][3];
  if ( v26 != 0.0 )
    v26 = 1.0 / v26;
  v27 = (float)((float)((float)(volumeToWorld->m[1][1] + volumeToWorld->m[1][0]) + volumeToWorld->m[1][2])
              + volumeToWorld->m[1][3])
      * v26;
  v28 = (float)((float)((float)(volumeToWorld->m[2][1] + volumeToWorld->m[2][0]) + volumeToWorld->m[2][2])
              + volumeToWorld->m[2][3])
      * v26;
  v.x = (float)((float)((float)(volumeToWorld->m[0][0] + volumeToWorld->m[0][1]) + volumeToWorld->m[0][2])
              + volumeToWorld->m[0][3])
      * v26;
  v.y = v27;
  v.z = v28;
  AddPointToBounds(&v, mins: pMins, maxs: pMaxs);
}

//------------------------------------------------------------------------------
// Address: 0x102C9920
// Name: void MatrixBuildOrtho(class VMatrix __near &,double,double,double,double,double,double)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildOrtho(
        VMatrix *dst,
        long double left,
        long double top,
        long double right,
        long double bottom,
        long double zNear,
        long double zFar)
{
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm1_4
  long double v11; // xmm1_8

  v7 = 2.0 / (right - left);
  v8 = (left + right) / (left - right);
  dst->m[0][3] = v8;
  v9 = 2.0 / (bottom - top);
  dst->m[1][1] = v9;
  dst->m[0][0] = v7;
  v10 = (top + bottom) / (top - bottom);
  dst->m[1][3] = v10;
  v11 = 1.0 / (zNear - zFar);
  *(_QWORD *)&dst->m[0][1] = 0;
  dst->m[1][0] = 0.0;
  dst->m[1][2] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[2][2] = v11;
  dst->m[2][3] = v11 * zNear;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x102C9A20
// Name: bool MatrixInverseGeneral(class VMatrix const __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl MatrixInverseGeneral(const VMatrix *src, VMatrix *dst)
{
  int v3; // edx
  _DWORD *v4; // eax
  float *v5; // ecx
  int v6; // ebx
  int v7; // edx
  int i; // edi
  int v9; // ecx
  float v10; // xmm0_4
  int v11; // eax
  float v12; // xmm1_4
  float v13; // xmm1_4
  float v14; // xmm1_4
  float v15; // xmm1_4
  float v16; // xmm1_4
  int v17; // eax
  float v18; // xmm1_4
  float *v19; // eax
  float v20; // xmm0_4
  int j; // esi
  float *v22; // ecx
  float v23; // xmm0_4
  int k; // edx
  float *v26; // ecx
  float v27; // esi
  float v28; // ecx
  float mat[4][8]; // [esp+0h] [ebp-90h] BYREF
  int rowMap[4]; // [esp+80h] [ebp-10h] BYREF

  v3 = 0;
  v4 = &mat[0][5];
  do
  {
    *(v4 - 5) = LODWORD(src->m[0][0]);
    v5 = (float *)(v4 - 5);
    v5[1] = src->m[0][1];
    v5[2] = src->m[0][2];
    v5[3] = src->m[0][3];
    *(v4 - 1) = 0;
    *v4 = 0;
    v4[1] = 0;
    v4[2] = 0;
    rowMap[v3] = v3;
    v6 = (int)&v4[v3++ - 5] + 16 - (_DWORD)rowMap;
    src = (const VMatrix *)((char *)src + 16);
    v4 += 8;
    *(int *)((char *)rowMap + v6) = 1065353216;
  }
  while ( v3 < 4 );
  v7 = 0;
  for ( i = 4; i > 0; --i )
  {
    v9 = -1;
    v10 = 0.000001;
    v11 = v7;
    if ( i >= 4 )
    {
      do
      {
        v12 = fabs(mat[rowMap[v11]][v7]);
        if ( v12 > v10 )
        {
          v9 = v11;
          v10 = v12;
        }
        v13 = fabs(mat[rowMap[v11 + 1]][v7]);
        if ( v13 > v10 )
        {
          v9 = v11 + 1;
          v10 = v13;
        }
        v14 = fabs(mat[rowMap[v11 + 2]][v7]);
        if ( v14 > v10 )
        {
          v9 = v11 + 2;
          v10 = v14;
        }
        v15 = fabs(mat[rowMap[v11 + 3]][v7]);
        if ( v15 > v10 )
        {
          v9 = v11 + 3;
          v10 = v15;
        }
        v11 += 4;
      }
      while ( v11 < 1 );
    }
    for ( ; v11 < 4; ++v11 )
    {
      v16 = fabs(mat[rowMap[v11]][v7]);
      if ( v16 > v10 )
      {
        v9 = v11;
        v10 = v16;
      }
    }
    if ( v9 == -1 )
      return 0;
    v17 = rowMap[v9];
    rowMap[v9] = rowMap[v7];
    rowMap[v7] = v17;
    v17 *= 32;
    v18 = *(float *)((char *)mat[0] + v17);
    v19 = (float *)((char *)mat[0] + v17);
    v20 = 1.0 / v19[v7];
    *v19 = v18 * v20;
    v19[1] = v19[1] * v20;
    v19[2] = v19[2] * v20;
    v19[3] = v19[3] * v20;
    v19[4] = v19[4] * v20;
    v19[5] = v19[5] * v20;
    v19[6] = v19[6] * v20;
    v19[7] = v19[7] * v20;
    v19[v7] = 1.0;
    for ( j = 0; j < 4; ++j )
    {
      if ( j != v7 )
      {
        v22 = mat[rowMap[j]];
        v23 = -v22[v7];
        *v22 = (float)(*v19 * v23) + *v22;
        v22[1] = (float)(v19[1] * v23) + v22[1];
        v22[2] = (float)(v19[2] * v23) + v22[2];
        v22[3] = (float)(v19[3] * v23) + v22[3];
        v22[4] = (float)(v19[4] * v23) + v22[4];
        v22[5] = (float)(v19[5] * v23) + v22[5];
        v22[6] = (float)(v19[6] * v23) + v22[6];
        v22[7] = (float)(v19[7] * v23) + v22[7];
        v22[v7] = 0.0;
      }
    }
    ++v7;
  }
  for ( k = 0; k < 4; ++k )
  {
    v26 = &mat[rowMap[k]][4];
    dst->m[0][0] = *v26;
    dst->m[0][1] = v26[1];
    v27 = v26[2];
    v28 = v26[3];
    dst->m[0][2] = v27;
    dst->m[0][3] = v28;
    dst = (VMatrix *)((char *)dst + 16);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102C9D40
// Name: void MatrixInverseTR(class VMatrix const __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixInverseTR(const VMatrix *src, VMatrix *dst)
{
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm4_4
  float v8; // xmm5_4
  float v9; // xmm1_4
  float v10; // xmm0_4

  dst->m[0][0] = src->m[0][0];
  dst->m[0][1] = src->m[1][0];
  dst->m[0][2] = src->m[2][0];
  dst->m[1][0] = src->m[0][1];
  dst->m[1][1] = src->m[1][1];
  dst->m[1][2] = src->m[2][1];
  dst->m[2][0] = src->m[0][2];
  dst->m[2][1] = src->m[1][2];
  dst->m[2][2] = src->m[2][2];
  v3 = -src->m[0][3];
  v4 = -src->m[1][3];
  v5 = -src->m[2][3];
  v6 = (float)((float)(dst->m[0][0] * v3) + (float)(v4 * dst->m[0][1])) + (float)(dst->m[0][2] * v5);
  v7 = (float)((float)(dst->m[1][1] * v4) + (float)(dst->m[1][0] * v3)) + (float)(v5 * dst->m[1][2]);
  v8 = dst->m[2][1] * v4;
  v9 = dst->m[2][0] * v3;
  v10 = dst->m[2][2] * v5;
  dst->m[0][3] = v6;
  dst->m[1][3] = v7;
  dst->m[2][3] = (float)(v8 + v9) + v10;
  *(_QWORD *)&dst->m[3][1] = 0;
  dst->m[3][0] = 0.0;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x102C9E40
// Name: public: class VMatrix VMatrix::InverseTR(void)const
// Source: json
//------------------------------------------------------------------------------
VMatrix *__thiscall VMatrix::InverseTR(VMatrix *this, VMatrix *result)
{
  VMatrix *v2; // eax
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm3_4
  float v10; // xmm4_4
  float v11; // xmm5_4
  float v12; // xmm1_4
  float v13; // xmm0_4

  v2 = result;
  result->m[0][0] = this->m[0][0];
  v3 = this->m[0][3];
  result->m[0][1] = this->m[1][0];
  v4 = this->m[1][3];
  v5 = this->m[2][3];
  result->m[0][2] = this->m[2][0];
  v6 = -v3;
  v7 = -v4;
  result->m[1][0] = this->m[0][1];
  v8 = -v5;
  result->m[1][1] = this->m[1][1];
  result->m[1][2] = this->m[2][1];
  result->m[2][0] = this->m[0][2];
  result->m[2][1] = this->m[1][2];
  result->m[2][2] = this->m[2][2];
  v9 = (float)((float)(v2->m[0][0] * v6) + (float)(v7 * v2->m[0][1])) + (float)(v2->m[0][2] * v8);
  v10 = (float)((float)(v2->m[1][1] * v7) + (float)(v2->m[1][0] * v6)) + (float)(v8 * v2->m[1][2]);
  v11 = result->m[2][1] * v7;
  v12 = result->m[2][0] * v6;
  v13 = result->m[2][2] * v8;
  result->m[0][3] = v9;
  result->m[1][3] = v10;
  result->m[2][3] = (float)(v11 + v12) + v13;
  *(_QWORD *)&result->m[3][1] = 0;
  result->m[3][0] = 0.0;
  result->m[3][3] = 1.0;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x102C9F40
// Name: public: class VMatrix VMatrix::Transpose(void)const
// Source: json
//------------------------------------------------------------------------------
VMatrix *__thiscall VMatrix::Transpose(VMatrix *this, VMatrix *result)
{
  result->m[0][0] = this->m[0][0];
  result->m[0][1] = this->m[1][0];
  result->m[0][2] = this->m[2][0];
  result->m[0][3] = this->m[3][0];
  result->m[1][0] = this->m[0][1];
  result->m[1][1] = this->m[1][1];
  result->m[1][2] = this->m[2][1];
  result->m[1][3] = this->m[3][1];
  result->m[2][0] = this->m[0][2];
  result->m[2][1] = this->m[1][2];
  result->m[2][2] = this->m[2][2];
  result->m[2][3] = this->m[3][2];
  result->m[3][0] = this->m[0][3];
  result->m[3][1] = this->m[1][3];
  result->m[3][2] = this->m[2][3];
  result->m[3][3] = this->m[3][3];
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C9FB0
// Name: void MatrixBuildPerspective(class VMatrix __near &,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildPerspective(VMatrix *dst, float fovX, float fovY, float zNear, float zFar)
{
  float v6; // xmm1_4
  float v7; // xmm1_4
  long double v8; // [esp-Ch] [ebp-50h]
  long double v9; // [esp-Ch] [ebp-50h]
  VMatrix addW; // [esp+4h] [ebp-40h] BYREF

  memset((unsigned __int8 *)dst, value: 0, count: sizeof(VMatrix));
  __libm_sse2_tan(x: v8);
  v6 = fovX * 0.0174532925199433 * 0.5 * (float)(zNear * 2.0);
  dst->m[0][0] = (float)(zNear * 2.0) / v6;
  __libm_sse2_tan(x: v9);
  v7 = fovY * 0.0174532925199433 * 0.5 * (float)(zNear * 2.0);
  dst->m[1][1] = (float)(zNear * 2.0) / v7;
  LODWORD(dst->m[2][2]) = COERCE_UNSIGNED_INT(zFar / (float)(zNear - zFar)) ^ _mask__NegFloat_;
  dst->m[2][3] = (float)(zNear * zFar) / (float)(zNear - zFar);
  dst->m[3][2] = 1.0;
  memset(&addW.m[0][2], 0, 12);
  memset(&addW.m[1][3], 0, 12);
  *(_QWORD *)&addW.m[2][2] = 1065353216;
  *(_QWORD *)&addW.m[3][0] = 0;
  *(_QWORD *)&addW.m[3][2] = 0x3F80000000000000LL;
  *(_QWORD *)&addW.m[0][0] = 3212836864LL;
  *(_QWORD *)&addW.m[1][1] = 3212836864LL;
  MatrixMultiply(src1: &addW, src2: dst, dst);
  *(_QWORD *)&addW.m[0][0] = 1065353216;
  *(_QWORD *)&addW.m[0][2] = 0x3F80000000000000LL;
  *(_QWORD *)&addW.m[1][0] = 0x3F80000000000000LL;
  *(_QWORD *)&addW.m[1][2] = 0x3F80000000000000LL;
  *(_QWORD *)&addW.m[2][0] = 0;
  *(_QWORD *)&addW.m[2][2] = 1065353216;
  *(_QWORD *)&addW.m[3][0] = 0;
  *(_QWORD *)&addW.m[3][2] = 0x3F80000000000000LL;
  MatrixMultiply(src1: &addW, src2: dst, dst);
  memset(&addW.m[0][2], 0, 12);
  memset(&addW.m[1][3], 0, 12);
  *(_QWORD *)&addW.m[2][2] = 1065353216;
  *(_QWORD *)&addW.m[3][0] = 0;
  *(_QWORD *)&addW.m[3][2] = 0x3F80000000000000LL;
  *(_QWORD *)&addW.m[0][0] = 1056964608;
  *(_QWORD *)&addW.m[1][1] = 1056964608;
  MatrixMultiply(src1: &addW, src2: dst, dst);
}

//------------------------------------------------------------------------------
// Address: 0x102CA1C0
// Name: void CalculateAABBFromProjectionMatrix(class VMatrix const __near &,class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CalculateAABBFromProjectionMatrix(const VMatrix *worldToVolume, Vector *pMins, Vector *pMaxs)
{
  VMatrix volumeToWorld; // [esp+0h] [ebp-40h] BYREF

  MatrixInverseGeneral(src: worldToVolume, dst: &volumeToWorld);
  CalculateAABBFromProjectionMatrixInverse(&volumeToWorld, pMins, pMaxs);
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10359180
// Name: public: class VMatrix __near & VMatrix::operator=(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
VMatrix *__thiscall VMatrix::operator=(VMatrix *this, const VMatrix *mOther)
{
  *this = *mOther;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103591F0
// Name: public: void VMatrix::MatrixMul(class VMatrix const __near &,class VMatrix __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall VMatrix::MatrixMul(VMatrix *this, const VMatrix *vm, VMatrix *out)
{
  float v4; // xmm0_4
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm4_4
  float v8; // xmm5_4
  float v9; // xmm1_4
  float v10; // xmm7_4
  float v11; // xmm6_4
  float v12; // xmm0_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm3_4
  float v18; // xmm1_4
  float v19; // [esp+0h] [ebp-3Ch]
  float v20; // [esp+4h] [ebp-38h]
  float v21; // [esp+8h] [ebp-34h]
  float v22; // [esp+Ch] [ebp-30h]
  float v23; // [esp+10h] [ebp-2Ch]
  float v24; // [esp+14h] [ebp-28h]
  float v25; // [esp+18h] [ebp-24h]
  float v26; // [esp+1Ch] [ebp-20h]
  float v27; // [esp+20h] [ebp-1Ch]
  float v28; // [esp+24h] [ebp-18h]
  float v29; // [esp+28h] [ebp-14h]
  float v30; // [esp+28h] [ebp-14h]
  float v31; // [esp+28h] [ebp-14h]
  float v32; // [esp+2Ch] [ebp-10h]
  float v33; // [esp+30h] [ebp-Ch]
  float v34; // [esp+34h] [ebp-8h]
  __int64 v35; // [esp+34h] [ebp-8h]
  __int64 v36; // [esp+34h] [ebp-8h]
  float v37; // [esp+38h] [ebp-4h]
  float vma; // [esp+44h] [ebp+8h]

  v4 = this->m[0][1];
  v5 = this->m[0][2];
  v6 = this->m[0][3];
  v7 = (float)((float)((float)(this->m[0][0] * vm->m[0][1]) + (float)(v4 * vm->m[1][1])) + (float)(v5 * vm->m[2][1]))
     + (float)(v6 * vm->m[3][1]);
  v8 = (float)((float)((float)(vm->m[0][2] * this->m[0][0]) + (float)(vm->m[1][2] * v4)) + (float)(vm->m[2][2] * v5))
     + (float)(vm->m[3][2] * v6);
  v33 = vm->m[2][0];
  v37 = this->m[1][2];
  v32 = vm->m[3][0];
  v34 = this->m[1][3];
  v9 = vm->m[0][0];
  v10 = vm->m[1][0];
  v29 = this->m[1][1];
  v11 = (float)((float)((float)(vm->m[0][3] * this->m[0][0]) + (float)(vm->m[1][3] * v4)) + (float)(vm->m[2][3] * v5))
      + (float)(vm->m[3][3] * v6);
  v12 = this->m[1][0];
  v28 = (float)((float)((float)(vm->m[0][0] * v12) + (float)(v29 * v10)) + (float)(v37 * v33)) + (float)(v34 * v32);
  v27 = (float)((float)((float)(v12 * vm->m[0][1]) + (float)(v29 * vm->m[1][1])) + (float)(v37 * vm->m[2][1]))
      + (float)(v34 * vm->m[3][1]);
  v26 = (float)((float)((float)(v12 * vm->m[0][2]) + (float)(v29 * vm->m[1][2])) + (float)(v37 * vm->m[2][2]))
      + (float)(v34 * vm->m[3][2]);
  v13 = this->m[2][0];
  v25 = (float)((float)((float)(v12 * vm->m[0][3]) + (float)(v29 * vm->m[1][3])) + (float)(v37 * vm->m[2][3]))
      + (float)(v34 * vm->m[3][3]);
  v35 = *(_QWORD *)&this->m[2][2];
  v30 = this->m[2][1];
  v24 = (float)((float)((float)(v13 * vm->m[0][0]) + (float)(v30 * v10)) + (float)(*(float *)&v35 * v33))
      + (float)(*((float *)&v35 + 1) * v32);
  v23 = (float)((float)((float)(v13 * vm->m[0][1]) + (float)(v30 * vm->m[1][1])) + (float)(*(float *)&v35 * vm->m[2][1]))
      + (float)(*((float *)&v35 + 1) * vm->m[3][1]);
  v22 = (float)((float)((float)(v13 * vm->m[0][2]) + (float)(v30 * vm->m[1][2])) + (float)(*(float *)&v35 * vm->m[2][2]))
      + (float)(*((float *)&v35 + 1) * vm->m[3][2]);
  v21 = (float)((float)((float)(v13 * vm->m[0][3]) + (float)(v30 * vm->m[1][3])) + (float)(*(float *)&v35 * vm->m[2][3]))
      + (float)(*((float *)&v35 + 1) * vm->m[3][3]);
  v14 = this->m[3][0];
  v36 = *(_QWORD *)&this->m[3][2];
  v31 = this->m[3][1];
  v20 = (float)((float)((float)(v14 * vm->m[0][0]) + (float)(v31 * v10)) + (float)(*(float *)&v36 * v33))
      + (float)(*((float *)&v36 + 1) * v32);
  v19 = (float)((float)((float)(v14 * vm->m[0][1]) + (float)(v31 * vm->m[1][1])) + (float)(*(float *)&v36 * vm->m[2][1]))
      + (float)(*((float *)&v36 + 1) * vm->m[3][1]);
  v15 = v14 * vm->m[0][2];
  v16 = v14 * vm->m[0][3];
  vma = (float)((float)(v15 + (float)(v31 * vm->m[1][2])) + (float)(*(float *)&v36 * vm->m[2][2]))
      + (float)(*((float *)&v36 + 1) * vm->m[3][2]);
  v17 = (float)((float)(v16 + (float)(v31 * vm->m[1][3])) + (float)(*(float *)&v36 * vm->m[2][3]))
      + (float)(*((float *)&v36 + 1) * vm->m[3][3]);
  v18 = (float)((float)((float)(v9 * this->m[0][0]) + (float)(v10 * this->m[0][1])) + (float)(v33 * this->m[0][2]))
      + (float)(v32 * this->m[0][3]);
  out->m[1][0] = v28;
  out->m[1][1] = v27;
  out->m[1][2] = v26;
  out->m[1][3] = v25;
  out->m[0][0] = v18;
  out->m[0][1] = v7;
  out->m[0][2] = v8;
  out->m[0][3] = v11;
  out->m[2][0] = v24;
  out->m[2][1] = v23;
  out->m[2][2] = v22;
  out->m[2][3] = v21;
  out->m[3][0] = v20;
  out->m[3][1] = v19;
  out->m[3][2] = vma;
  out->m[3][3] = v17;
}

//------------------------------------------------------------------------------
// Address: 0x103596B0
// Name: public: void VMatrix::SetupMatrixOrgAngles(class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VMatrix::SetupMatrixOrgAngles(VMatrix *this, const Vector *origin, const QAngle *vAngles)
{
  float v4; // xmm1_4
  float v5; // xmm1_4
  double z; // st7
  float v7; // [esp+8h] [ebp-18h]
  float cr; // [esp+Ch] [ebp-14h]
  float sr; // [esp+10h] [ebp-10h]
  float sy; // [esp+14h] [ebp-Ch]
  float cy; // [esp+18h] [ebp-8h]
  float cp; // [esp+1Ch] [ebp-4h]
  float vAnglesa; // [esp+2Ch] [ebp+Ch]

  v4 = vAngles->y * 0.017453292;
  cy = cos(v4);
  sy = sin(v4);
  v5 = vAngles->x * 0.017453292;
  cp = cos(v5);
  vAnglesa = sin(v5);
  v7 = vAngles->z * 0.017453292;
  cr = cos(v7);
  sr = sin(v7);
  this->m[0][0] = cp * cy;
  this->m[1][0] = cp * sy;
  LODWORD(this->m[2][0]) = LODWORD(vAnglesa) ^ _mask__NegFloat_;
  this->m[0][1] = (float)((float)(sr * vAnglesa) * cy) - (float)(cr * sy);
  this->m[1][1] = (float)((float)(sr * vAnglesa) * sy) + (float)(cr * cy);
  this->m[2][1] = sr * cp;
  this->m[1][2] = (float)((float)(cr * vAnglesa) * sy) - (float)(sr * cy);
  this->m[0][3] = 0.0;
  this->m[1][3] = 0.0;
  this->m[2][3] = 0.0;
  this->m[0][2] = (float)((float)(cr * vAnglesa) * cy) + (float)(sr * sy);
  this->m[2][2] = cr * cp;
  this->m[0][3] = origin->x;
  this->m[1][3] = origin->y;
  z = origin->z;
  this->m[3][0] = 0.0;
  this->m[2][3] = z;
  *(_QWORD *)&this->m[3][1] = 0;
  this->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10359840
// Name: void MatrixSetIdentity(class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixSetIdentity(VMatrix *dst)
{
  *(_QWORD *)&dst->m[0][0] = 1065353216;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = 0.0;
  *(_QWORD *)&dst->m[1][1] = 1065353216;
  dst->m[1][3] = 0.0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[2][2] = 1065353216;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x103598B0
// Name: void MatrixFromAngles(class QAngle const __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixFromAngles(const QAngle *vAngles, VMatrix *dst)
{
  VMatrix::SetupMatrixOrgAngles(this: dst, origin: &vec3_origin, vAngles);
}

//------------------------------------------------------------------------------
// Address: 0x10359A10
// Name: void MatrixMultiply(class VMatrix const __near &,class VMatrix const __near &,class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixMultiply(VMatrix *src1, VMatrix *src2, VMatrix *dst)
{
  float *p_tmp1; // edx
  VMatrix *v4; // edi
  float *p_tmp2; // eax
  VMatrix tmp2; // [esp+Ch] [ebp-80h] BYREF
  VMatrix tmp1; // [esp+4Ch] [ebp-40h] BYREF

  p_tmp1 = (float *)&tmp1;
  if ( src1 != dst )
    p_tmp1 = (float *)src1;
  v4 = src2;
  p_tmp2 = (float *)&tmp2;
  if ( src2 != dst )
    p_tmp2 = (float *)src2;
  if ( src1 == dst && src1 != &tmp1 )
  {
    tmp1 = *src1;
    v4 = src2;
  }
  if ( v4 == dst && v4 != &tmp2 )
    tmp2 = *v4;
  dst->m[0][0] = (float)((float)((float)(p_tmp1[1] * p_tmp2[4]) + (float)(*p_tmp2 * *p_tmp1))
                       + (float)(p_tmp2[8] * p_tmp1[2]))
               + (float)(p_tmp2[12] * p_tmp1[3]);
  dst->m[0][1] = (float)((float)((float)(p_tmp1[1] * p_tmp2[5]) + (float)(*p_tmp1 * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[2]))
               + (float)(p_tmp2[13] * p_tmp1[3]);
  dst->m[0][2] = (float)((float)((float)(p_tmp1[1] * p_tmp2[6]) + (float)(*p_tmp1 * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[2]))
               + (float)(p_tmp2[14] * p_tmp1[3]);
  dst->m[0][3] = (float)((float)((float)(p_tmp1[1] * p_tmp2[7]) + (float)(*p_tmp1 * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[2]))
               + (float)(p_tmp2[15] * p_tmp1[3]);
  dst->m[1][0] = (float)((float)((float)(p_tmp1[5] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[4]))
                       + (float)(p_tmp2[8] * p_tmp1[6]))
               + (float)(p_tmp2[12] * p_tmp1[7]);
  dst->m[1][1] = (float)((float)((float)(p_tmp1[5] * p_tmp2[5]) + (float)(p_tmp1[4] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[6]))
               + (float)(p_tmp2[13] * p_tmp1[7]);
  dst->m[1][2] = (float)((float)((float)(p_tmp1[5] * p_tmp2[6]) + (float)(p_tmp1[4] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[6]))
               + (float)(p_tmp2[14] * p_tmp1[7]);
  dst->m[1][3] = (float)((float)((float)(p_tmp1[5] * p_tmp2[7]) + (float)(p_tmp1[4] * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[6]))
               + (float)(p_tmp1[7] * p_tmp2[15]);
  dst->m[2][0] = (float)((float)((float)(p_tmp1[9] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[8]))
                       + (float)(p_tmp2[8] * p_tmp1[10]))
               + (float)(p_tmp2[12] * p_tmp1[11]);
  dst->m[2][1] = (float)((float)((float)(p_tmp1[9] * p_tmp2[5]) + (float)(p_tmp1[8] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[10]))
               + (float)(p_tmp2[13] * p_tmp1[11]);
  dst->m[2][2] = (float)((float)((float)(p_tmp1[9] * p_tmp2[6]) + (float)(p_tmp1[8] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[10]))
               + (float)(p_tmp2[14] * p_tmp1[11]);
  dst->m[2][3] = (float)((float)((float)(p_tmp1[8] * p_tmp2[3]) + (float)(p_tmp1[9] * p_tmp2[7]))
                       + (float)(p_tmp2[11] * p_tmp1[10]))
               + (float)(p_tmp1[11] * p_tmp2[15]);
  dst->m[3][0] = (float)((float)((float)(p_tmp1[13] * p_tmp2[4]) + (float)(*p_tmp2 * p_tmp1[12]))
                       + (float)(p_tmp2[8] * p_tmp1[14]))
               + (float)(p_tmp2[12] * p_tmp1[15]);
  dst->m[3][1] = (float)((float)((float)(p_tmp1[13] * p_tmp2[5]) + (float)(p_tmp1[12] * p_tmp2[1]))
                       + (float)(p_tmp2[9] * p_tmp1[14]))
               + (float)(p_tmp2[13] * p_tmp1[15]);
  dst->m[3][2] = (float)((float)((float)(p_tmp1[13] * p_tmp2[6]) + (float)(p_tmp1[12] * p_tmp2[2]))
                       + (float)(p_tmp2[10] * p_tmp1[14]))
               + (float)(p_tmp2[14] * p_tmp1[15]);
  dst->m[3][3] = (float)((float)((float)(p_tmp1[13] * p_tmp2[7]) + (float)(p_tmp1[12] * p_tmp2[3]))
                       + (float)(p_tmp2[11] * p_tmp1[14]))
               + (float)(p_tmp1[15] * p_tmp2[15]);
}

//------------------------------------------------------------------------------
// Address: 0x10359E50
// Name: void MatrixBuildRotateZ(class VMatrix __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatrixBuildRotateZ(VMatrix *dst, unsigned int angleDegrees)
{
  __m128d v2; // xmm0
  __m128i v3; // xmm0
  double v4; // xmm0_8
  double v5; // xmm0_8
  float v6; // xmm1_4
  float fSin; // [esp+0h] [ebp-4h]
  int radians; // [esp+10h] [ebp+Ch]

  v2 = _mm_cvtps_pd((__m128)angleDegrees);
  v2.m128d_f64[0] = v2.m128d_f64[0] * 0.0174532925199433;
  v3 = (__m128i)_mm_cvtpd_ps(v2);
  radians = v3.m128i_i32[0];
  *(double *)v3.m128i_i64 = *(float *)v3.m128i_i32;
  __libm_sse2_sin(X: v3);
  *(float *)&v4 = v4;
  fSin = *(float *)&v4;
  __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)(unsigned int)radians));
  v6 = v5;
  dst->m[0][0] = v6;
  LODWORD(dst->m[0][1]) = LODWORD(fSin) ^ _mask__NegFloat_;
  dst->m[1][1] = v6;
  *(_QWORD *)&dst->m[0][2] = 0;
  dst->m[1][0] = fSin;
  *(_QWORD *)&dst->m[1][2] = 0;
  *(_QWORD *)&dst->m[2][0] = 0;
  *(_QWORD *)&dst->m[2][2] = 1065353216;
  *(_QWORD *)&dst->m[3][0] = 0;
  dst->m[3][2] = 0.0;
  dst->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10359F10
// Name: class VMatrix SetupMatrixAngles(class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
VMatrix *__cdecl SetupMatrixAngles(VMatrix *result, const QAngle *vAngles)
{
  int v2; // ecx

  VMatrix::SetupMatrixOrgAngles(this: result, origin: &vec3_origin, vAngles);
  return (VMatrix *)v2;
}

//------------------------------------------------------------------------------
// Address: 0x10359F30
// Name: class VMatrix SetupMatrixOrgAngles(class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
VMatrix *__cdecl SetupMatrixOrgAngles(VMatrix *result, const Vector *origin, const QAngle *vAngles)
{
  int v3; // ecx

  VMatrix::SetupMatrixOrgAngles(this: result, origin, vAngles);
  return (VMatrix *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x10359F50
// Name: public: void VMatrix::InverseTR(class VMatrix __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall VMatrix::InverseTR(VMatrix *this, VMatrix *ret)
{
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm4_4
  float v8; // xmm5_4
  float v9; // xmm1_4
  float v10; // xmm0_4

  ret->m[0][0] = this->m[0][0];
  ret->m[0][1] = this->m[1][0];
  ret->m[0][2] = this->m[2][0];
  ret->m[1][0] = this->m[0][1];
  ret->m[1][1] = this->m[1][1];
  ret->m[1][2] = this->m[2][1];
  ret->m[2][0] = this->m[0][2];
  ret->m[2][1] = this->m[1][2];
  ret->m[2][2] = this->m[2][2];
  v3 = -this->m[0][3];
  v4 = -this->m[1][3];
  v5 = -this->m[2][3];
  v6 = (float)((float)(ret->m[0][0] * v3) + (float)(v4 * ret->m[0][1])) + (float)(ret->m[0][2] * v5);
  v7 = (float)((float)(ret->m[1][1] * v4) + (float)(ret->m[1][0] * v3)) + (float)(v5 * ret->m[1][2]);
  v8 = ret->m[2][1] * v4;
  v9 = ret->m[2][0] * v3;
  v10 = ret->m[2][2] * v5;
  ret->m[0][3] = v6;
  ret->m[1][3] = v7;
  ret->m[2][3] = (float)(v8 + v9) + v10;
  *(_QWORD *)&ret->m[3][1] = 0;
  ret->m[3][0] = 0.0;
  ret->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x1035A050
// Name: public: class VMatrix VMatrix::Transpose(void)const
// Source: json
//------------------------------------------------------------------------------
VMatrix *__thiscall VMatrix::Transpose(VMatrix *this, VMatrix *result)
{
  result->m[0][0] = this->m[0][0];
  result->m[0][1] = this->m[1][0];
  result->m[0][2] = this->m[2][0];
  result->m[0][3] = this->m[3][0];
  result->m[1][0] = this->m[0][1];
  result->m[1][1] = this->m[1][1];
  result->m[1][2] = this->m[2][1];
  result->m[1][3] = this->m[3][1];
  result->m[2][0] = this->m[0][2];
  result->m[2][1] = this->m[1][2];
  result->m[2][2] = this->m[2][2];
  result->m[2][3] = this->m[3][2];
  result->m[3][0] = this->m[0][3];
  result->m[3][1] = this->m[1][3];
  result->m[3][2] = this->m[2][3];
  result->m[3][3] = this->m[3][3];
  return result;
}

} // namespace server
