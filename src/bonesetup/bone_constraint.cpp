// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: bonesetup/bone_constraint.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x004A44B0
// Name: void ComputeTwistBones(class Quaternion __near *,int,bool,class Vector const __near &,class Quaternion const __near &,struct matrix3x4_t const __near &,class Quaternion const __near &,float const __near *,class Quaternion const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeTwistBones(
        Quaternion *pqTwists,
        int nCount,
        bool bInverse,
        const Vector *vUp,
        const Quaternion *qParent,
        const matrix3x4_t *mChild,
        const Quaternion *qBaseInv,
        const float *pflWeights,
        const Quaternion *pqTwistBinds)
{
  const Vector *v9; // esi
  float x; // xmm7_4
  float y; // xmm4_4
  float z; // xmm3_4
  float v13; // xmm6_4
  float v14; // xmm5_4
  float v15; // xmm0_4
  float v16; // xmm4_4
  float v17; // xmm3_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  float v20; // xmm0_4
  float v21; // xmm6_4
  float v22; // xmm7_4
  double v23; // xmm0_8
  float v24; // xmm0_4
  float v25; // xmm0_4
  int v26; // edi
  const Quaternion *v27; // esi
  const Quaternion *v28; // esi
  Quaternion qChild; // [esp+10h] [ebp-7Ch] BYREF
  Quaternion qTmp1; // [esp+20h] [ebp-6Ch] BYREF
  Quaternion qTmp0; // [esp+30h] [ebp-5Ch] BYREF
  Vector vUpRotate; // [esp+40h] [ebp-4Ch] BYREF
  Vector vLocalTranslation; // [esp+4Ch] [ebp-40h] BYREF
  Vector vUpProject; // [esp+58h] [ebp-34h] BYREF
  Vector vUpRotateProject; // [esp+64h] [ebp-28h] BYREF
  Vector vRotatedTranslation; // [esp+70h] [ebp-1Ch] BYREF
  Vector vTmp0; // [esp+7Ch] [ebp-10h] BYREF
  float v38; // [esp+88h] [ebp-4h]

  MatrixAngles(matrix: mChild, q: &qChild, pos: &vLocalTranslation);
  v38 = vLocalTranslation.y * vLocalTranslation.y;
  if ( (float)((float)((float)(vLocalTranslation.y * vLocalTranslation.y)
                     + (float)(vLocalTranslation.x * vLocalTranslation.x))
             + (float)(vLocalTranslation.z * vLocalTranslation.z)) < 1.4210855e-12 )
  {
    _V_memcpy(dest: pqTwists, src: pqTwistBinds, count: 16 * nCount);
    return;
  }
  VectorNormalize(vec: &vLocalTranslation);
  if ( bInverse )
  {
    QuaternionMult(p: qBaseInv, q: qParent, qt: &qTmp0);
    v9 = vUp;
    VectorRotate(in1: vUp, in2: &qTmp0, out: &vUpRotate);
    x = vLocalTranslation.x;
    y = vLocalTranslation.y;
    z = vLocalTranslation.z;
    vRotatedTranslation = vLocalTranslation;
  }
  else
  {
    QuaternionMult(p: qBaseInv, q: &qChild, qt: &qTmp0);
    v9 = vUp;
    VectorRotate(in1: vUp, in2: &qTmp0, out: &vUpRotate);
    VectorRotate(in1: &vLocalTranslation, in2: qBaseInv, out: &vRotatedTranslation);
    z = vRotatedTranslation.z;
    y = vRotatedTranslation.y;
    x = vRotatedTranslation.x;
  }
  v13 = v9->x;
  v14 = v9->x * x;
  if ( (float)(1.0 - fabs((float)((float)(v9->y * y) + v14) + (float)(v9->z * z))) < 0.0000011920929
    || (float)(1.0 - fabs((float)((float)(vUpRotate.y * y) + (float)(vUpRotate.x * x)) + (float)(vUpRotate.z * z))) < 0.0000011920929 )
  {
    goto LABEL_12;
  }
  v15 = (float)((float)(v9->y * y) + v14) + (float)(v9->z * z);
  v16 = y * v15;
  v17 = z * v15;
  v18 = v9->y - v16;
  v19 = v9->z - v17;
  vTmp0.x = v15 * x;
  vTmp0.y = v16;
  vTmp0.z = v17;
  vUpProject.x = v13 - (float)(v15 * x);
  vUpProject.y = v18;
  vUpProject.z = v19;
  VectorNormalize(vec: &vUpProject);
  v20 = (float)((float)(vUpRotate.y * vRotatedTranslation.y) + (float)(vUpRotate.x * vRotatedTranslation.x))
      + (float)(vUpRotate.z * vRotatedTranslation.z);
  vTmp0.x = v20 * vRotatedTranslation.x;
  vTmp0.y = vRotatedTranslation.y * v20;
  vTmp0.z = vRotatedTranslation.z * v20;
  vUpRotateProject.x = vUpRotate.x - (float)(v20 * vRotatedTranslation.x);
  vUpRotateProject.y = vUpRotate.y - (float)(vRotatedTranslation.y * v20);
  vUpRotateProject.z = vUpRotate.z - (float)(vRotatedTranslation.z * v20);
  VectorNormalize(vec: &vUpRotateProject);
  v21 = vUpProject.y;
  v22 = vUpRotateProject.z;
  if ( fabs(vUpProject.x - vUpRotateProject.x) <= 0.001 )
  {
    v22 = vUpRotateProject.z;
    if ( fabs(vUpProject.y - vUpRotateProject.y) <= 0.001 )
    {
      if ( fabs(vUpProject.z - vUpRotateProject.z) <= 0.001 )
      {
LABEL_12:
        _V_memcpy(dest: pqTwists, src: pqTwistBinds, count: 16 * nCount);
        return;
      }
      v21 = vUpProject.y;
    }
  }
  vTmp0.x = (float)(v22 * v21) - (float)(vUpRotateProject.y * vUpProject.z);
  vTmp0.y = (float)(vUpProject.z * vUpRotateProject.x) - (float)(v22 * vUpProject.x);
  vTmp0.z = (float)(vUpRotateProject.y * vUpProject.x) - (float)(v21 * vUpRotateProject.x);
  VectorNormalize(vec: &vTmp0);
  v23 = (float)((float)((float)(vUpRotateProject.y * vUpProject.y) + (float)(vUpRotateProject.x * vUpProject.x))
              + (float)(vUpRotateProject.z * vUpProject.z));
  if ( (float)((float)((float)(vTmp0.y * vRotatedTranslation.y) + (float)(vTmp0.x * vRotatedTranslation.x))
             + (float)(vTmp0.z * vRotatedTranslation.z)) >= 0.0 )
  {
    __libm_sse2_acos();
    v25 = v23;
  }
  else
  {
    __libm_sse2_acos();
    v24 = v23;
    LODWORD(v25) = LODWORD(v24) ^ _mask__NegFloat_;
  }
  AxisAngleQuaternion(axis: &vLocalTranslation, angle: v25 * 57.29578, q: &qTmp0);
  v26 = 0;
  if ( bInverse )
  {
    if ( nCount > 0 )
    {
      v27 = pqTwistBinds;
      LODWORD(v38) = (char *)pqTwists - (char *)pqTwistBinds;
      do
      {
        QuaternionScale(p: &qTmp0, t: pflWeights[v26] - 1.0, q: &qTmp1);
        QuaternionMult(p: &qTmp1, q: v27, qt: (Quaternion *)((char *)v27 + LODWORD(v38)));
        ++v26;
        ++v27;
      }
      while ( v26 < nCount );
    }
  }
  else if ( nCount > 0 )
  {
    v28 = pqTwistBinds;
    LODWORD(v38) = (char *)pqTwists - (char *)pqTwistBinds;
    do
    {
      QuaternionScale(p: &qTmp0, t: pflWeights[v26], q: &qTmp1);
      QuaternionMult(p: &qTmp1, q: v28, qt: (Quaternion *)((char *)v28 + LODWORD(v38)));
      ++v26;
      ++v28;
    }
    while ( v26 < nCount );
  }
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x1019C860
// Name: void ComputeTwistBones(class Quaternion __near *,int,bool,class Vector const __near &,class Quaternion const __near &,struct matrix3x4_t const __near &,class Quaternion const __near &,float const __near *,class Quaternion const __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall ComputeTwistBones(
        long double a1@<esi:edi>,
        Quaternion *pqTwists,
        int nCount,
        bool bInverse,
        const Vector *vUp,
        const Quaternion *qParent,
        const matrix3x4_t *mChild,
        const Quaternion *qBaseInv,
        const Vector *pflWeights,
        const Quaternion *pqTwistBinds)
{
  const Vector *v10; // esi
  float w; // xmm7_4
  float x; // xmm4_4
  float y; // xmm3_4
  float v14; // xmm6_4
  float v15; // xmm5_4
  float v16; // xmm0_4
  float v17; // xmm4_4
  float v18; // xmm3_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  float v21; // xmm0_4
  float v22; // xmm6_4
  float v23; // xmm7_4
  double v24; // xmm0_8
  float v25; // xmm0_4
  float v26; // xmm0_4
  int v27; // edi
  const Quaternion *v28; // esi
  const Quaternion *v29; // esi
  Quaternion angle; // [esp+0h] [ebp-7Ch] BYREF
  Quaternion qChild; // [esp+10h] [ebp-6Ch] BYREF
  Quaternion qTmp1; // [esp+20h] [ebp-5Ch] BYREF
  Quaternion qTmp0; // [esp+30h] [ebp-4Ch] BYREF
  Vector vUpRotate; // [esp+40h] [ebp-3Ch] BYREF
  Vector vLocalTranslation; // [esp+4Ch] [ebp-30h] BYREF
  Vector vUpProject; // [esp+58h] [ebp-24h] BYREF
  Vector vUpRotateProject; // [esp+64h] [ebp-18h] BYREF
  Vector vRotatedTranslation; // [esp+70h] [ebp-Ch]

  MatrixAngles(matrix: mChild, q: &angle, pos: (Vector *)&qTmp0.w);
  vRotatedTranslation.z = vUpRotate.x * vUpRotate.x;
  if ( (float)((float)((float)(vUpRotate.x * vUpRotate.x) + (float)(qTmp0.w * qTmp0.w))
             + (float)(vUpRotate.y * vUpRotate.y)) < 1.4210855e-12 )
  {
    _V_memcpy(dest: pqTwists, src: pqTwistBinds, count: 16 * nCount);
    return;
  }
  VectorNormalize(vec: (Vector *)&qTmp0.w);
  if ( bInverse )
  {
    QuaternionMult(p: qBaseInv, q: qParent, qt: &qTmp1);
    v10 = vUp;
    VectorRotate(in1: vUp, in2: &qTmp1, out: (Vector *)&qTmp0);
    w = qTmp0.w;
    x = vUpRotate.x;
    y = vUpRotate.y;
    vUpProject.z = qTmp0.w;
    vUpRotateProject.x = vUpRotate.x;
    vUpRotateProject.y = vUpRotate.y;
  }
  else
  {
    QuaternionMult(p: qBaseInv, q: &angle, qt: &qTmp1);
    v10 = vUp;
    VectorRotate(in1: vUp, in2: &qTmp1, out: (Vector *)&qTmp0);
    VectorRotate(in1: (const Vector *)&qTmp0.w, in2: qBaseInv, out: (Vector *)&vUpProject.z);
    y = vUpRotateProject.y;
    x = vUpRotateProject.x;
    w = vUpProject.z;
  }
  v14 = v10->x;
  v15 = v10->x * w;
  if ( (float)(1.0 - fabs((float)((float)(v10->y * x) + v15) + (float)(v10->z * y))) < 0.0000011920929
    || (float)(1.0 - fabs((float)((float)(qTmp0.y * x) + (float)(qTmp0.x * w)) + (float)(qTmp0.z * y))) < 0.0000011920929 )
  {
    goto LABEL_12;
  }
  v16 = (float)((float)(v10->y * x) + v15) + (float)(v10->z * y);
  v17 = x * v16;
  v18 = y * v16;
  v19 = v10->y - v17;
  v20 = v10->z - v18;
  vUpRotateProject.z = v16 * w;
  vRotatedTranslation.x = v17;
  vRotatedTranslation.y = v18;
  vUpRotate.z = v14 - (float)(v16 * w);
  vLocalTranslation.x = v19;
  vLocalTranslation.y = v20;
  VectorNormalize(vec: (Vector *)&vUpRotate.z);
  v21 = (float)((float)(qTmp0.y * vUpRotateProject.x) + (float)(qTmp0.x * vUpProject.z))
      + (float)(qTmp0.z * vUpRotateProject.y);
  vUpRotateProject.z = v21 * vUpProject.z;
  vRotatedTranslation.x = vUpRotateProject.x * v21;
  vRotatedTranslation.y = vUpRotateProject.y * v21;
  vLocalTranslation.z = qTmp0.x - (float)(v21 * vUpProject.z);
  vUpProject.x = qTmp0.y - (float)(vUpRotateProject.x * v21);
  vUpProject.y = qTmp0.z - (float)(vUpRotateProject.y * v21);
  VectorNormalize(vec: (Vector *)&vLocalTranslation.z);
  v22 = vLocalTranslation.x;
  v23 = vUpProject.y;
  if ( fabs(vUpRotate.z - vLocalTranslation.z) <= 0.001 )
  {
    v23 = vUpProject.y;
    if ( fabs(vLocalTranslation.x - vUpProject.x) <= 0.001 )
    {
      if ( fabs(vLocalTranslation.y - vUpProject.y) <= 0.001 )
      {
LABEL_12:
        _V_memcpy(dest: pqTwists, src: pqTwistBinds, count: 16 * nCount);
        return;
      }
      v22 = vLocalTranslation.x;
    }
  }
  vUpRotateProject.z = (float)(v23 * v22) - (float)(vUpProject.x * vLocalTranslation.y);
  vRotatedTranslation.x = (float)(vLocalTranslation.y * vLocalTranslation.z) - (float)(v23 * vUpRotate.z);
  vRotatedTranslation.y = (float)(vUpProject.x * vUpRotate.z) - (float)(v22 * vLocalTranslation.z);
  VectorNormalize(vec: (Vector *)&vUpRotateProject.z);
  v24 = (float)((float)((float)(vUpProject.x * vLocalTranslation.x) + (float)(vLocalTranslation.z * vUpRotate.z))
              + (float)(vUpProject.y * vLocalTranslation.y));
  if ( (float)((float)((float)(vRotatedTranslation.x * vUpRotateProject.x) + (float)(vUpRotateProject.z * vUpProject.z))
             + (float)(vRotatedTranslation.y * vUpRotateProject.y)) >= 0.0 )
  {
    __libm_sse2_acos(x: a1);
    v26 = v24;
  }
  else
  {
    __libm_sse2_acos(x: a1);
    v25 = v24;
    LODWORD(v26) = LODWORD(v25) ^ _mask__NegFloat_;
  }
  AxisAngleQuaternion(axis: (const Vector *)&qTmp0.w, angle: v26 * 57.29578, q: &qTmp1);
  v27 = 0;
  if ( bInverse )
  {
    if ( nCount > 0 )
    {
      v28 = pqTwistBinds;
      LODWORD(vRotatedTranslation.z) = (char *)pqTwists - (char *)pqTwistBinds;
      do
      {
        QuaternionScale(p: &qTmp1, t: *(&pflWeights->x + v27) - 1.0, q: &qChild);
        QuaternionMult(p: &qChild, q: v28, qt: (Quaternion *)((char *)v28 + LODWORD(vRotatedTranslation.z)));
        ++v27;
        ++v28;
      }
      while ( v27 < nCount );
    }
  }
  else if ( nCount > 0 )
  {
    v29 = pqTwistBinds;
    LODWORD(vRotatedTranslation.z) = (char *)pqTwists - (char *)pqTwistBinds;
    do
    {
      QuaternionScale(p: &qTmp1, t: *(&pflWeights->x + v27), q: &qChild);
      QuaternionMult(p: &qChild, q: v29, qt: (Quaternion *)((char *)v29 + LODWORD(vRotatedTranslation.z)));
      ++v27;
      ++v29;
    }
    while ( v27 < nCount );
  }
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x0043B200
// Name: void ComputeTwistBones(class Quaternion __near *,int,bool,class Vector const __near &,class Quaternion const __near &,struct matrix3x4_t const __near &,class Quaternion const __near &,float const __near *,class Quaternion const __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall ComputeTwistBones(
        long double a1@<esi:edi>,
        Quaternion *pqTwists,
        int nCount,
        bool bInverse,
        const Vector *vUp,
        const Quaternion *qParent,
        const matrix3x4_t *mChild,
        const Quaternion *qBaseInv,
        const float *pflWeights,
        const Quaternion *pqTwistBinds)
{
  const Vector *v10; // esi
  float x; // xmm7_4
  float y; // xmm4_4
  float z; // xmm3_4
  float v14; // xmm6_4
  float v15; // xmm5_4
  float v16; // xmm0_4
  float v17; // xmm4_4
  float v18; // xmm3_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  float v21; // xmm0_4
  float v22; // xmm6_4
  float v23; // xmm7_4
  double v24; // xmm0_8
  float v25; // xmm0_4
  float v26; // xmm0_4
  int v27; // edi
  const Quaternion *v28; // esi
  const Quaternion *v29; // esi
  Quaternion qChild; // [esp+10h] [ebp-7Ch] BYREF
  Quaternion qTmp1; // [esp+20h] [ebp-6Ch] BYREF
  Quaternion qTmp0; // [esp+30h] [ebp-5Ch] BYREF
  Vector vUpRotate; // [esp+40h] [ebp-4Ch] BYREF
  Vector vLocalTranslation; // [esp+4Ch] [ebp-40h] BYREF
  Vector vUpProject; // [esp+58h] [ebp-34h] BYREF
  Vector vUpRotateProject; // [esp+64h] [ebp-28h] BYREF
  Vector vRotatedTranslation; // [esp+70h] [ebp-1Ch] BYREF
  Vector vTmp0; // [esp+7Ch] [ebp-10h] BYREF
  float v40; // [esp+88h] [ebp-4h]

  MatrixAngles(matrix: mChild, q: &qChild, pos: &vLocalTranslation);
  v40 = vLocalTranslation.y * vLocalTranslation.y;
  if ( (float)((float)((float)(vLocalTranslation.y * vLocalTranslation.y)
                     + (float)(vLocalTranslation.x * vLocalTranslation.x))
             + (float)(vLocalTranslation.z * vLocalTranslation.z)) < 1.4210855e-12 )
  {
    _V_memcpy(dest: pqTwists, src: pqTwistBinds, count: 16 * nCount);
    return;
  }
  VectorNormalize(vec: &vLocalTranslation);
  if ( bInverse )
  {
    QuaternionMult(p: qBaseInv, q: qParent, qt: &qTmp0);
    v10 = vUp;
    VectorRotate(in1: vUp, in2: &qTmp0, out: &vUpRotate);
    x = vLocalTranslation.x;
    y = vLocalTranslation.y;
    z = vLocalTranslation.z;
    vRotatedTranslation = vLocalTranslation;
  }
  else
  {
    QuaternionMult(p: qBaseInv, q: &qChild, qt: &qTmp0);
    v10 = vUp;
    VectorRotate(in1: vUp, in2: &qTmp0, out: &vUpRotate);
    VectorRotate(in1: &vLocalTranslation, in2: qBaseInv, out: &vRotatedTranslation);
    z = vRotatedTranslation.z;
    y = vRotatedTranslation.y;
    x = vRotatedTranslation.x;
  }
  v14 = v10->x;
  v15 = v10->x * x;
  if ( (float)(1.0 - fabs((float)((float)(v10->y * y) + v15) + (float)(v10->z * z))) < 0.0000011920929
    || (float)(1.0 - fabs((float)((float)(vUpRotate.y * y) + (float)(vUpRotate.x * x)) + (float)(vUpRotate.z * z))) < 0.0000011920929 )
  {
    goto LABEL_12;
  }
  v16 = (float)((float)(v10->y * y) + v15) + (float)(v10->z * z);
  v17 = y * v16;
  v18 = z * v16;
  v19 = v10->y - v17;
  v20 = v10->z - v18;
  vTmp0.x = v16 * x;
  vTmp0.y = v17;
  vTmp0.z = v18;
  vUpProject.x = v14 - (float)(v16 * x);
  vUpProject.y = v19;
  vUpProject.z = v20;
  VectorNormalize(vec: &vUpProject);
  v21 = (float)((float)(vUpRotate.y * vRotatedTranslation.y) + (float)(vUpRotate.x * vRotatedTranslation.x))
      + (float)(vUpRotate.z * vRotatedTranslation.z);
  vTmp0.x = v21 * vRotatedTranslation.x;
  vTmp0.y = vRotatedTranslation.y * v21;
  vTmp0.z = vRotatedTranslation.z * v21;
  vUpRotateProject.x = vUpRotate.x - (float)(v21 * vRotatedTranslation.x);
  vUpRotateProject.y = vUpRotate.y - (float)(vRotatedTranslation.y * v21);
  vUpRotateProject.z = vUpRotate.z - (float)(vRotatedTranslation.z * v21);
  VectorNormalize(vec: &vUpRotateProject);
  v22 = vUpProject.y;
  v23 = vUpRotateProject.z;
  if ( fabs(vUpProject.x - vUpRotateProject.x) <= 0.001 )
  {
    v23 = vUpRotateProject.z;
    if ( fabs(vUpProject.y - vUpRotateProject.y) <= 0.001 )
    {
      if ( fabs(vUpProject.z - vUpRotateProject.z) <= 0.001 )
      {
LABEL_12:
        _V_memcpy(dest: pqTwists, src: pqTwistBinds, count: 16 * nCount);
        return;
      }
      v22 = vUpProject.y;
    }
  }
  vTmp0.x = (float)(v23 * v22) - (float)(vUpRotateProject.y * vUpProject.z);
  vTmp0.y = (float)(vUpProject.z * vUpRotateProject.x) - (float)(v23 * vUpProject.x);
  vTmp0.z = (float)(vUpRotateProject.y * vUpProject.x) - (float)(v22 * vUpRotateProject.x);
  VectorNormalize(vec: &vTmp0);
  v24 = (float)((float)((float)(vUpRotateProject.y * vUpProject.y) + (float)(vUpRotateProject.x * vUpProject.x))
              + (float)(vUpRotateProject.z * vUpProject.z));
  if ( (float)((float)((float)(vTmp0.y * vRotatedTranslation.y) + (float)(vTmp0.x * vRotatedTranslation.x))
             + (float)(vTmp0.z * vRotatedTranslation.z)) >= 0.0 )
  {
    __libm_sse2_acos(x: a1);
    v26 = v24;
  }
  else
  {
    __libm_sse2_acos(x: a1);
    v25 = v24;
    LODWORD(v26) = LODWORD(v25) ^ _mask__NegFloat_;
  }
  AxisAngleQuaternion(axis: &vLocalTranslation, angle: v26 * 57.29578, q: &qTmp0);
  v27 = 0;
  if ( bInverse )
  {
    if ( nCount > 0 )
    {
      v28 = pqTwistBinds;
      LODWORD(v40) = (char *)pqTwists - (char *)pqTwistBinds;
      do
      {
        QuaternionScale(p: &qTmp0, t: pflWeights[v27] - 1.0, q: &qTmp1);
        QuaternionMult(p: &qTmp1, q: v28, qt: (Quaternion *)((char *)v28 + LODWORD(v40)));
        ++v27;
        ++v28;
      }
      while ( v27 < nCount );
    }
  }
  else if ( nCount > 0 )
  {
    v29 = pqTwistBinds;
    LODWORD(v40) = (char *)pqTwists - (char *)pqTwistBinds;
    do
    {
      QuaternionScale(p: &qTmp0, t: pflWeights[v27], q: &qTmp1);
      QuaternionMult(p: &qTmp1, q: v29, qt: (Quaternion *)((char *)v29 + LODWORD(v40)));
      ++v27;
      ++v29;
    }
    while ( v27 < nCount );
  }
}

} // namespace hlmv

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x102B5840
// Name: void ComputeTwistBones(class Quaternion __near *,int,bool,class Vector const __near &,class Quaternion const __near &,struct matrix3x4_t const __near &,class Quaternion const __near &,float const __near *,class Quaternion const __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall ComputeTwistBones(
        long double a1@<esi:edi>,
        Quaternion *pqTwists,
        int nCount,
        bool bInverse,
        const Vector *vUp,
        const Quaternion *qParent,
        const matrix3x4_t *mChild,
        const Quaternion *qBaseInv,
        const float *pflWeights,
        const Quaternion *pqTwistBinds)
{
  const Vector *v10; // esi
  float x; // xmm7_4
  float y; // xmm4_4
  float z; // xmm3_4
  float v14; // xmm6_4
  float v15; // xmm5_4
  float v16; // xmm0_4
  float v17; // xmm4_4
  float v18; // xmm3_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  float v21; // xmm0_4
  float v22; // xmm6_4
  float v23; // xmm7_4
  double v24; // xmm0_8
  float v25; // xmm0_4
  float v26; // xmm0_4
  int v27; // edi
  const Quaternion *v28; // esi
  const Quaternion *v29; // esi
  Quaternion qChild; // [esp+10h] [ebp-7Ch] BYREF
  Quaternion qTmp1; // [esp+20h] [ebp-6Ch] BYREF
  Quaternion qTmp0; // [esp+30h] [ebp-5Ch] BYREF
  Vector vUpRotate; // [esp+40h] [ebp-4Ch] BYREF
  Vector vLocalTranslation; // [esp+4Ch] [ebp-40h] BYREF
  Vector vUpProject; // [esp+58h] [ebp-34h] BYREF
  Vector vUpRotateProject; // [esp+64h] [ebp-28h] BYREF
  Vector vRotatedTranslation; // [esp+70h] [ebp-1Ch] BYREF
  Vector vTmp0; // [esp+7Ch] [ebp-10h] BYREF
  float v40; // [esp+88h] [ebp-4h]

  MatrixAngles(matrix: mChild, q: &qChild, pos: &vLocalTranslation);
  v40 = vLocalTranslation.y * vLocalTranslation.y;
  if ( (float)((float)((float)(vLocalTranslation.y * vLocalTranslation.y)
                     + (float)(vLocalTranslation.x * vLocalTranslation.x))
             + (float)(vLocalTranslation.z * vLocalTranslation.z)) < 1.4210855e-12 )
  {
    _V_memcpy(dest: (void *)pqTwists, src: pqTwistBinds, count: 16 * nCount);
    return;
  }
  VectorNormalize(vec: &vLocalTranslation);
  if ( bInverse )
  {
    QuaternionMult(p: qBaseInv, q: qParent, qt: &qTmp0);
    v10 = vUp;
    VectorRotate(in1: vUp, in2: &qTmp0, out: &vUpRotate);
    x = vLocalTranslation.x;
    y = vLocalTranslation.y;
    z = vLocalTranslation.z;
    vRotatedTranslation = vLocalTranslation;
  }
  else
  {
    QuaternionMult(p: qBaseInv, q: &qChild, qt: &qTmp0);
    v10 = vUp;
    VectorRotate(in1: vUp, in2: &qTmp0, out: &vUpRotate);
    VectorRotate(in1: &vLocalTranslation, in2: qBaseInv, out: &vRotatedTranslation);
    z = vRotatedTranslation.z;
    y = vRotatedTranslation.y;
    x = vRotatedTranslation.x;
  }
  v14 = v10->x;
  v15 = v10->x * x;
  if ( (float)(1.0 - fabs((float)((float)(v10->y * y) + v15) + (float)(v10->z * z))) < 0.0000011920929
    || (float)(1.0 - fabs((float)((float)(vUpRotate.y * y) + (float)(vUpRotate.x * x)) + (float)(vUpRotate.z * z))) < 0.0000011920929 )
  {
    goto LABEL_12;
  }
  v16 = (float)((float)(v10->y * y) + v15) + (float)(v10->z * z);
  v17 = y * v16;
  v18 = z * v16;
  v19 = v10->y - v17;
  v20 = v10->z - v18;
  vTmp0.x = v16 * x;
  vTmp0.y = v17;
  vTmp0.z = v18;
  vUpProject.x = v14 - (float)(v16 * x);
  vUpProject.y = v19;
  vUpProject.z = v20;
  VectorNormalize(vec: &vUpProject);
  v21 = (float)((float)(vUpRotate.y * vRotatedTranslation.y) + (float)(vUpRotate.x * vRotatedTranslation.x))
      + (float)(vUpRotate.z * vRotatedTranslation.z);
  vTmp0.x = v21 * vRotatedTranslation.x;
  vTmp0.y = vRotatedTranslation.y * v21;
  vTmp0.z = vRotatedTranslation.z * v21;
  vUpRotateProject.x = vUpRotate.x - (float)(v21 * vRotatedTranslation.x);
  vUpRotateProject.y = vUpRotate.y - (float)(vRotatedTranslation.y * v21);
  vUpRotateProject.z = vUpRotate.z - (float)(vRotatedTranslation.z * v21);
  VectorNormalize(vec: &vUpRotateProject);
  v22 = vUpProject.y;
  v23 = vUpRotateProject.z;
  if ( fabs(vUpProject.x - vUpRotateProject.x) <= 0.001 )
  {
    v23 = vUpRotateProject.z;
    if ( fabs(vUpProject.y - vUpRotateProject.y) <= 0.001 )
    {
      if ( fabs(vUpProject.z - vUpRotateProject.z) <= 0.001 )
      {
LABEL_12:
        _V_memcpy(dest: (void *)pqTwists, src: pqTwistBinds, count: 16 * nCount);
        return;
      }
      v22 = vUpProject.y;
    }
  }
  vTmp0.x = (float)(v23 * v22) - (float)(vUpRotateProject.y * vUpProject.z);
  vTmp0.y = (float)(vUpProject.z * vUpRotateProject.x) - (float)(v23 * vUpProject.x);
  vTmp0.z = (float)(vUpRotateProject.y * vUpProject.x) - (float)(v22 * vUpRotateProject.x);
  VectorNormalize(vec: &vTmp0);
  v24 = (float)((float)((float)(vUpRotateProject.y * vUpProject.y) + (float)(vUpRotateProject.x * vUpProject.x))
              + (float)(vUpRotateProject.z * vUpProject.z));
  if ( (float)((float)((float)(vTmp0.y * vRotatedTranslation.y) + (float)(vTmp0.x * vRotatedTranslation.x))
             + (float)(vTmp0.z * vRotatedTranslation.z)) >= 0.0 )
  {
    __libm_sse2_acos(x: a1);
    v26 = v24;
  }
  else
  {
    __libm_sse2_acos(x: a1);
    v25 = v24;
    LODWORD(v26) = LODWORD(v25) ^ _mask__NegFloat_;
  }
  AxisAngleQuaternion(axis: &vLocalTranslation, angle: v26 * 57.29578, q: &qTmp0);
  v27 = 0;
  if ( bInverse )
  {
    if ( nCount > 0 )
    {
      v28 = pqTwistBinds;
      LODWORD(v40) = (char *)pqTwists - (char *)pqTwistBinds;
      do
      {
        QuaternionScale(p: &qTmp0, t: pflWeights[v27] - 1.0, q: &qTmp1);
        QuaternionMult(p: &qTmp1, q: v28, qt: (const Quaternion *)((char *)v28 + LODWORD(v40)));
        ++v27;
        ++v28;
      }
      while ( v27 < nCount );
    }
  }
  else if ( nCount > 0 )
  {
    v29 = pqTwistBinds;
    LODWORD(v40) = (char *)pqTwists - (char *)pqTwistBinds;
    do
    {
      QuaternionScale(p: &qTmp0, t: pflWeights[v27], q: &qTmp1);
      QuaternionMult(p: &qTmp1, q: v29, qt: (const Quaternion *)((char *)v29 + LODWORD(v40)));
      ++v27;
      ++v29;
    }
    while ( v27 < nCount );
  }
}

} // namespace client
