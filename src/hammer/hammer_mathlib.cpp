// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/hammer_mathlib.cpp
// Functions: 23
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x100441B0
// Name: float fixang(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl fixang(float a)
{
  double result; // st7

  result = a;
  if ( a < 0.0 )
    return result + 360.0;
  if ( a > 359.9 )
    return result - 360.0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100441E0
// Name: float lineangle(float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
long double __cdecl lineangle(float x1, float y1, float x2, float y2)
{
  bool v4; // zf
  float x; // [esp+8h] [ebp+8h]

  v4 = (float)(x2 - x1) == 0.0;
  x = x2 - x1;
  if ( v4 && (float)(y2 - y1) == 0.0 )
    return 0.0;
  else
    return atan2((float)(y2 - y1), x) * 57.29578;
}

//------------------------------------------------------------------------------
// Address: 0x10044230
// Name: float rint(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl rint(float f)
{
  if ( f > 0.0 )
    return floor(X: f + 0.5);
  if ( f >= 0.0 )
    return 0.0;
  return ceil(X: (float)(f - 0.5));
}

//------------------------------------------------------------------------------
// Address: 0x10044280
// Name: void AxisAngleMatrix(class VMatrix __near &,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AxisAngleMatrix(VMatrix *Matrix, const Vector *Axis, float fAngle)
{
  float y; // xmm4_4
  float z; // xmm5_4
  float x; // xmm7_4
  float v6; // xmm4_4
  long double fSin; // [esp+0h] [ebp-4h]
  long double fSina; // [esp+0h] [ebp-4h]
  float fSinb; // [esp+0h] [ebp-4h]
  float fRadians; // [esp+14h] [ebp+10h]

  fRadians = fAngle * 3.141592653589793 * 0.005555555555555556;
  __libm_sse2_sin(x: fSin);
  *(float *)&fSina = fRadians;
  __libm_sse2_cos(x: fSina);
  y = Axis->y;
  z = Axis->z;
  Matrix->m[0][0] = (float)((float)(1.0 - (float)(Axis->x * Axis->x)) * fRadians) + (float)(Axis->x * Axis->x);
  Matrix->m[1][0] = (float)((float)(Axis->y * Axis->x) * (float)(1.0 - fRadians)) + (float)(Axis->z * fSinb);
  Matrix->m[2][0] = (float)((float)(Axis->z * Axis->x) * (float)(1.0 - fRadians)) - (float)(Axis->y * fSinb);
  Matrix->m[3][0] = 0.0;
  Matrix->m[0][1] = (float)((float)(Axis->y * Axis->x) * (float)(1.0 - fRadians)) - (float)(Axis->z * fSinb);
  Matrix->m[1][1] = (float)((float)(1.0 - (float)(y * y)) * fRadians) + (float)(y * y);
  x = Axis->x;
  v6 = (float)(Axis->z * Axis->y) * (float)(1.0 - fRadians);
  Matrix->m[3][1] = 0.0;
  Matrix->m[2][1] = v6 + (float)(x * fSinb);
  Matrix->m[0][2] = (float)((float)(Axis->z * Axis->x) * (float)(1.0 - fRadians)) + (float)(Axis->y * fSinb);
  Matrix->m[1][2] = (float)((float)(Axis->z * Axis->y) * (float)(1.0 - fRadians)) - (float)(Axis->x * fSinb);
  Matrix->m[2][2] = (float)((float)(1.0 - (float)(z * z)) * fRadians) + (float)(z * z);
  Matrix->m[3][2] = 0.0;
  Matrix->m[0][3] = 0.0;
  Matrix->m[1][3] = 0.0;
  Matrix->m[2][3] = 0.0;
  Matrix->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10044430
// Name: void RotateAroundAxis(class VMatrix __near &,float,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall RotateAroundAxis(long double a1@<esi:edi>, VMatrix *Matrix, float fDegrees, int nAxis)
{
  int v5; // edi
  int v6; // esi
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm2_4
  float v10; // xmm3_4
  float v11; // xmm4_4
  float v12; // xmm5_4
  float v13; // xmm6_4
  long double v15; // [esp-8h] [ebp-20h]
  float Temp2a; // [esp+0h] [ebp-18h]
  float Temp1a; // [esp+4h] [ebp-14h]
  float Temp0a; // [esp+8h] [ebp-10h]
  float v19; // [esp+Ch] [ebp-Ch]
  float v20; // [esp+10h] [ebp-8h]
  float fRadians; // [esp+14h] [ebp-4h]
  float fSin; // [esp+24h] [ebp+Ch]
  float fSina; // [esp+24h] [ebp+Ch]

  if ( fDegrees != 0.0 )
  {
    v5 = 2;
    if ( nAxis != 0 )
    {
      v6 = 0;
      if ( nAxis != 1 )
        v5 = 1;
    }
    else
    {
      v6 = 1;
    }
    __libm_sse2_sin(x: a1);
    fSin = fDegrees * 0.017453292;
    __libm_sse2_cos(x: v15);
    v7 = fDegrees * 0.017453292;
    v8 = v7;
    if ( nAxis == 1 )
      LODWORD(v8) = LODWORD(fSin) ^ _mask__NegFloat_;
    v9 = Matrix->m[0][v5];
    fSina = Matrix->m[0][v6];
    fRadians = Matrix->m[1][v6];
    Temp0a = (float)(v9 * v8) + (float)(fSina * v7);
    v10 = Matrix->m[1][v5];
    v20 = Matrix->m[2][v6];
    Temp1a = (float)(v10 * v8) + (float)(fRadians * v7);
    v11 = Matrix->m[2][v5];
    Temp2a = (float)(v11 * v8) + (float)(v20 * v7);
    v12 = Matrix->m[3][v5];
    v19 = Matrix->m[3][v6];
    v13 = (float)(v12 * v8) + (float)(v19 * v7);
    if ( nAxis == 1 )
      LODWORD(v8) ^= _mask__NegFloat_;
    Matrix->m[0][v6] = Temp0a;
    Matrix->m[1][v6] = Temp1a;
    Matrix->m[2][v6] = Temp2a;
    Matrix->m[3][v6] = v13;
    Matrix->m[0][v5] = (float)(v9 * v7) - (float)(fSina * v8);
    Matrix->m[1][v5] = (float)(v10 * v7) - (float)(fRadians * v8);
    Matrix->m[2][v5] = (float)(v11 * v7) - (float)(v20 * v8);
    Matrix->m[3][v5] = (float)(v12 * v7) - (float)(v19 * v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100445E0
// Name: bool IsLineInside(class Vector2D const __near &,class Vector2D const __near &,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsLineInside(const Vector2D *pt1, const Vector2D *pt2, int x1, int y1, int x2, int y2)
{
  int x; // ecx
  int y; // esi
  int v8; // edi
  int v9; // eax
  int v10; // eax
  int v11; // edx
  int v12; // eax
  int v14; // eax
  int v15; // eax
  int ly2; // [esp+8h] [ebp+8h]

  x = (int)pt1->x;
  y = (int)pt1->y;
  v8 = (int)pt2->x;
  v9 = (int)pt2->y;
  ly2 = v9;
  if ( (v8 <= x2 || x <= x2) && (v8 >= x1 || x >= x1) && (v9 <= y2 || y <= y2) && (v9 >= y1 || y >= y1) )
  {
    if ( x >= x1 && x <= x2 && y >= y1 && y <= y2 )
      return 1;
    if ( v8 >= x1 && v8 <= x2 && v9 >= y1 && v9 <= y2 )
      return 1;
    if ( y > y1 != v9 > y1 )
    {
      v10 = x + (y1 - y) * (v8 - x) / (v9 - y);
      if ( v10 >= x1 && v10 <= x2 )
        return 1;
    }
    if ( y > y2 == ly2 > y2 )
    {
      v11 = x1;
    }
    else
    {
      v11 = x1;
      v12 = x + (y2 - y) * (v8 - x) / (ly2 - y);
      if ( v12 >= x1 && v12 <= x2 )
        return 1;
    }
    if ( x > v11 != v8 > v11 )
    {
      v14 = y + (v11 - x) * (ly2 - y) / (v8 - x);
      if ( v14 >= y1 && v14 <= y2 )
        return 1;
    }
    if ( x > x2 != v8 > x2 )
    {
      v15 = y + (x2 - x) * (ly2 - y) / (v8 - x);
      if ( v15 >= y1 && v15 <= y2 )
        return 1;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10044740
// Name: bool IsPointInside(class Vector2D const __near &,class Vector2D const __near &,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl IsPointInside(const Vector2D *pt, const Vector2D *mins, const Vector2D *maxs)
{
  float y; // xmm0_4
  BOOL result; // eax

  result = false;
  if ( pt->x >= mins->x )
  {
    y = pt->y;
    if ( y >= mins->y && maxs->x >= pt->x && maxs->y >= y )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10044780
// Name: bool IsBoxInside(class Vector2D const __near &,class Vector2D const __near &,class Vector2D const __near &,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsBoxInside(const Vector2D *min1, const Vector2D *max1, const Vector2D *min2, const Vector2D *max2)
{
  return min2->x <= min1->x && max1->x <= max2->x && min2->y <= min1->y && max1->y <= max2->y;
}

//------------------------------------------------------------------------------
// Address: 0x100447D0
// Name: bool IsBoxIntersecting(class Vector2D const __near &,class Vector2D const __near &,class Vector2D const __near &,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsBoxIntersecting(const Vector2D *min1, const Vector2D *max1, const Vector2D *min2, const Vector2D *max2)
{
  return min1->x < max2->x && min2->x < max1->x && min1->y < max2->y && min2->y < max1->y;
}

//------------------------------------------------------------------------------
// Address: 0x10044820
// Name: bool IsValidBox(class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl IsValidBox(Vector *mins, Vector *maxs)
{
  return maxs->x >= mins->x && maxs->y >= mins->y && maxs->z >= mins->z;
}

//------------------------------------------------------------------------------
// Address: 0x10044860
// Name: void LimitBox(class Vector __near &,class Vector __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LimitBox(Vector *mins, Vector *maxs, float limit)
{
  float v3; // xmm0_4

  LODWORD(v3) = LODWORD(limit) ^ _mask__NegFloat_;
  if ( COERCE_FLOAT(LODWORD(limit) ^ _mask__NegFloat_) > mins->x )
    mins->x = v3;
  if ( maxs->x > limit )
    maxs->x = limit;
  if ( v3 > mins->y )
    mins->y = v3;
  if ( maxs->y > limit )
    maxs->y = limit;
  if ( v3 > mins->z )
    mins->z = v3;
  if ( maxs->z > limit )
    maxs->z = limit;
}

//------------------------------------------------------------------------------
// Address: 0x100448D0
// Name: void PointsFromBox(class Vector const __near &,class Vector const __near &,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PointsFromBox(const Vector *mins, const Vector *maxs, Vector *points)
{
  *points = *mins;
  points[1].x = mins->x;
  points[1].y = mins->y;
  points[1].z = maxs->z;
  points[2].x = mins->x;
  points[2].y = maxs->y;
  points[2].z = mins->z;
  points[3].x = mins->x;
  points[3].y = maxs->y;
  points[3].z = maxs->z;
  points[4].x = maxs->x;
  points[4].y = mins->y;
  points[4].z = mins->z;
  points[5].x = maxs->x;
  points[5].y = mins->y;
  points[5].z = maxs->z;
  points[6].x = maxs->x;
  points[6].y = maxs->y;
  points[6].z = mins->z;
  points[7] = *maxs;
}

//------------------------------------------------------------------------------
// Address: 0x10044970
// Name: void RoundVector(class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RoundVector(Vector2D *v)
{
  v->x = (float)(int)(float)(v->x + 0.5);
  v->y = (float)(int)(float)(v->y + 0.5);
}

//------------------------------------------------------------------------------
// Address: 0x100449B0
// Name: void PointsRevertOrder(class Vector __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PointsRevertOrder(Vector *pPoints, int nPoints)
{
  void *v2; // esp
  int v3; // edi
  float *v4; // ecx
  float *p_z; // eax
  unsigned int v6; // edx
  float *v7; // ecx
  int v8; // edx
  float *v9; // eax
  double v10; // st7
  _DWORD v11[3]; // [esp+0h] [ebp-Ch] BYREF

  v2 = alloca(12 * nPoints);
  memcpy(dst: (unsigned __int8 *)v11, src: (unsigned __int8 *)pPoints, count: 12 * nPoints);
  v3 = 0;
  if ( nPoints >= 4 )
  {
    v4 = (float *)&v11[3 * nPoints - 1];
    p_z = &pPoints[1].z;
    v6 = ((unsigned int)(nPoints - 4) >> 2) + 1;
    v3 = 4 * v6;
    do
    {
      p_z += 12;
      *(p_z - 17) = *(v4 - 2);
      v4 -= 12;
      --v6;
      *(p_z - 16) = v4[11];
      *(p_z - 15) = v4[12];
      *(p_z - 14) = v4[7];
      *(p_z - 13) = v4[8];
      *(p_z - 12) = v4[9];
      *(p_z - 11) = v4[4];
      *(p_z - 10) = v4[5];
      *(p_z - 9) = v4[6];
      *(p_z - 8) = v4[1];
      *(p_z - 7) = v4[2];
      *(p_z - 6) = v4[3];
    }
    while ( v6 != 0 );
  }
  if ( v3 < nPoints )
  {
    v7 = &pPoints[v3].z;
    v8 = nPoints - v3;
    v9 = (float *)&v11[3 * (nPoints - v3) - 1];
    do
    {
      v10 = *(v9 - 2);
      v9 -= 3;
      *(v7 - 2) = v10;
      v7 += 3;
      --v8;
      *(v7 - 4) = v9[2];
      *(v7 - 3) = v9[3];
    }
    while ( v8 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10044AA0
// Name: class Vector const __near & GetNormalFromPoints(class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
const Vector *__cdecl GetNormalFromPoints(const Vector *p0, const Vector *p1, const Vector *p2)
{
  float y; // xmm6_4
  float z; // xmm7_4
  float v5; // xmm5_4
  float v6; // xmm0_4
  float v7; // xmm3_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm4_4

  if ( (_S1_0 & 1) == 0 )
    _S1_0 |= 1u;
  y = p1->y;
  z = p1->z;
  v5 = p2->y - y;
  v6 = p0->x - p1->x;
  v7 = p0->y - y;
  v8 = p2->x - p1->x;
  v9 = p2->z - z;
  v10 = p0->z - z;
  vNormal.x = (float)(v9 * v7) - (float)(v5 * v10);
  vNormal.y = (float)(v8 * v10) - (float)(v9 * v6);
  vNormal.z = (float)(v6 * v5) - (float)(v8 * v7);
  VectorNormalize(vec: &vNormal);
  return &vNormal;
}

//------------------------------------------------------------------------------
// Address: 0x10044B90
// Name: bool SolveLinearEquation(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl SolveLinearEquation(const Vector *v0, const Vector *v1, const Vector *v2, const Vector *v3, Vector *vOut)
{
  float z; // xmm0_4
  float y; // xmm1_4
  float v7; // xmm1_4
  bool result; // al
  float v9; // xmm2_4
  float v10; // xmm0_4
  VMatrix inverse; // [esp+0h] [ebp-80h] BYREF
  VMatrix matrix; // [esp+40h] [ebp-40h] BYREF

  *(_QWORD *)&matrix.m[0][0] = *(_QWORD *)&v1->x;
  z = v1->z;
  *(_QWORD *)&matrix.m[1][0] = *(_QWORD *)&v2->x;
  *(_QWORD *)&matrix.m[1][2] = LODWORD(v2->z);
  matrix.m[2][0] = v3->x;
  y = v3->y;
  *(_QWORD *)&matrix.m[0][2] = LODWORD(z);
  matrix.m[2][1] = y;
  v7 = v3->z;
  *(_QWORD *)&matrix.m[3][0] = 0;
  *(_QWORD *)&matrix.m[3][2] = 0x3F80000000000000LL;
  *(_QWORD *)&matrix.m[2][2] = LODWORD(v7);
  result = VMatrix::InverseGeneral(this: &matrix, vInverse: &inverse);
  if ( result )
  {
    v9 = (float)((float)(v0->x * inverse.m[0][1]) + (float)(v0->y * inverse.m[1][1])) + (float)(v0->z * inverse.m[2][1]);
    v10 = (float)((float)(v0->x * inverse.m[0][2]) + (float)(v0->y * inverse.m[1][2]))
        + (float)(v0->z * inverse.m[2][2]);
    vOut->x = (float)((float)(v0->y * inverse.m[1][0]) + (float)(v0->x * inverse.m[0][0]))
            + (float)(v0->z * inverse.m[2][0]);
    vOut->y = v9;
    vOut->z = v10;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10044CC0
// Name: bool BuildAxesFromNormal(class Vector const __near &,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl BuildAxesFromNormal(const Vector *vNormal, Vector *vHorz, Vector *vVert)
{
  float v3; // xmm1_4
  int v4; // edx
  float v5; // xmm0_4
  float v6; // xmm0_4
  float v7; // xmm0_4

  v3 = 99999.0;
  vHorz->x = 0.0;
  vHorz->y = 0.0;
  vHorz->z = 0.0;
  vVert->x = 0.0;
  vVert->y = 0.0;
  vVert->z = 0.0;
  v4 = -1;
  v5 = fabs(vNormal->x);
  if ( v5 < 99999.0 )
  {
    v4 = 0;
    v3 = v5;
  }
  v6 = fabs(vNormal->y);
  if ( v3 > v6 )
  {
    v4 = 1;
    v3 = v6;
  }
  if ( v3 > fabs(vNormal->z) )
  {
    v4 = 2;
LABEL_7:
    *((_DWORD *)&vHorz->x + v4) = 1065353216;
    vVert->x = (float)(vHorz->z * vNormal->y) - (float)(vNormal->z * vHorz->y);
    vVert->y = (float)(vNormal->z * vHorz->x) - (float)(vHorz->z * vNormal->x);
    v7 = (float)(vNormal->x * vHorz->y) - (float)(vNormal->y * vHorz->x);
    vVert->z = v7;
    vHorz->x = (float)(v7 * vNormal->y) - (float)(vNormal->z * vVert->y);
    vHorz->y = (float)(vNormal->z * vVert->x) - (float)(vNormal->x * vVert->z);
    vHorz->z = (float)(vVert->y * vNormal->x) - (float)(vNormal->y * vVert->x);
    VectorNormalize(vec: vHorz);
    VectorNormalize(vec: vVert);
    return 1;
  }
  if ( v4 != -1 )
    goto LABEL_7;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10044E10
// Name: void polyMake(float,float,float,float,int,float,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall polyMake(
        int a1@<edi>,
        int a2@<esi>,
        float x1,
        float y1,
        float x2,
        float y2,
        int npoints,
        unsigned int start_ang,
        Vector *pmPoints)
{
  float v10; // xmm3_4
  double v11; // xmm2_8
  int v12; // ecx
  __m128d v13; // xmm0
  Vector *v14; // esi
  int v15; // edi
  __m128 v16; // xmm0
  __m128 v17; // xmm1
  float v18; // xmm2_4
  __m128 v19; // xmm3
  __m128 v20; // xmm1
  __m128 v21; // xmm2
  float v22; // xmm0_4
  __m128 v23; // xmm1
  __m128 v24; // xmm3
  __m128 v25; // xmm0
  __m128 v26; // xmm1
  Vector *v27; // eax
  long double v28; // [esp-8h] [ebp-1Ch]
  long double v29; // [esp-8h] [ebp-1Ch]
  double X; // [esp+0h] [ebp-14h]
  double v31; // [esp+8h] [ebp-Ch]
  int angle_delta; // [esp+10h] [ebp-4h]
  float angle_4; // [esp+1Ch] [ebp+8h]
  int point; // [esp+20h] [ebp+Ch]
  float v35; // [esp+24h] [ebp+10h]
  float v36; // [esp+24h] [ebp+10h]
  float v37; // [esp+28h] [ebp+14h]
  float x1a; // [esp+2Ch] [ebp+18h]
  float yCenter; // [esp+30h] [ebp+1Ch]

  X = 360.0 / (double)npoints;
  v10 = x1 + (float)((float)(x2 - x1) * 0.5);
  x1a = v10;
  v11 = (float)((float)(y2 - y1) * 0.5);
  v12 = 0;
  v13 = _mm_cvtps_pd((__m128)start_ang);
  v31 = v13.m128d_f64[0];
  *(float *)&point = y1 + v11;
  if ( npoints > 0 )
  {
    HIDWORD(v28) = a2;
    v14 = pmPoints;
    yCenter = (float)(x2 - x1) * 0.5;
    LODWORD(v28) = a1;
    v37 = v11;
    v15 = npoints;
    angle_delta = npoints;
    do
    {
      if ( v13.m128d_f64[0] > 360.0 )
      {
        v13.m128d_f64[0] = v13.m128d_f64[0] - 360.0;
        v31 = v13.m128d_f64[0];
      }
      v16 = _mm_cvtpd_ps(v13);
      angle_4 = v16.m128_f32[0] * 0.017453292;
      *(double *)v16.m128_u64 = (float)(v16.m128_f32[0] * 0.017453292);
      __libm_sse2_sin(x: v28);
      v16.m128_f32[0] = *(double *)v16.m128_u64;
      v16.m128_f32[0] = (float)(v16.m128_f32[0] * yCenter) + x1a;
      if ( v16.m128_f32[0] <= 0.0 )
      {
        if ( v16.m128_f32[0] >= 0.0 )
        {
          v16.m128_i32[0] = 0;
        }
        else
        {
          v35 = ceil(X: (float)(v16.m128_f32[0] - 0.5));
          v16.m128_f32[0] = v35;
        }
      }
      else
      {
        v16.m128_f32[0] = v16.m128_f32[0] + 0.5;
        v17.m128_i32[0] = 1258291200;
        v18 = v16.m128_f32[0];
        v19 = _mm_and_ps((__m128)0x80000000, v16);
        v17.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v16, v19), v17).m128_f32[0]) & 0x4B000000
                        | v19.m128_i32[0];
        v16.m128_f32[0] = (float)(v16.m128_f32[0] + v17.m128_f32[0]) - v17.m128_f32[0];
        v20 = v16;
        v20.m128_f32[0] = v16.m128_f32[0] - v18;
        v16.m128_f32[0] = v16.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v20, v19).m128_u32[0] & 0x3F800000);
      }
      LODWORD(v14->x) = v16.m128_i32[0];
      __libm_sse2_cos(x: v29);
      v21 = 0;
      v21.m128_f32[0] = (float)(angle_4 * v37) + *(float *)&point;
      v22 = 0.0;
      if ( v21.m128_f32[0] <= 0.0 )
      {
        if ( v21.m128_f32[0] < 0.0 )
        {
          v36 = ceil(X: (float)(v21.m128_f32[0] - 0.5));
          v22 = v36;
        }
      }
      else
      {
        v21.m128_f32[0] = v21.m128_f32[0] + 0.5;
        v23.m128_i32[0] = 1258291200;
        v24 = _mm_and_ps((__m128)0x80000000, v21);
        v23.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v21, v24), v23).m128_f32[0]) & 0x4B000000
                        | v24.m128_i32[0];
        v25 = v21;
        v25.m128_f32[0] = (float)(v21.m128_f32[0] + v23.m128_f32[0]) - v23.m128_f32[0];
        v26 = v25;
        v26.m128_f32[0] = v25.m128_f32[0] - v21.m128_f32[0];
        v22 = v25.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v26, v24).m128_u32[0] & 0x3F800000);
      }
      v14->y = v22;
      v13 = (__m128d)*(unsigned __int64 *)&X;
      v13.m128d_f64[0] = X + v31;
      ++v14;
      --v15;
      v31 = X + v31;
    }
    while ( v15 != 0 );
    v12 = angle_delta;
  }
  v27 = &pmPoints[v12];
  v27->x = pmPoints->x;
  v27->y = pmPoints->y;
}

//------------------------------------------------------------------------------
// Address: 0x10045080
// Name: void NormalizeBox(class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NormalizeBox(Vector *mins, Vector *maxs)
{
  float x; // xmm0_4
  float y; // xmm0_4
  float z; // xmm0_4

  x = mins->x;
  if ( mins->x > maxs->x )
  {
    mins->x = maxs->x;
    maxs->x = x;
  }
  y = mins->y;
  if ( y > maxs->y )
  {
    mins->y = maxs->y;
    maxs->y = y;
  }
  z = mins->z;
  if ( z > maxs->z )
  {
    mins->z = maxs->z;
    maxs->z = z;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100450D0
// Name: void NormalizeBox(class Vector2D __near &,class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NormalizeBox(Vector2D *mins, Vector2D *maxs)
{
  float x; // xmm0_4
  float y; // xmm0_4

  x = mins->x;
  if ( mins->x > maxs->x )
  {
    mins->x = maxs->x;
    maxs->x = x;
  }
  y = mins->y;
  if ( y > maxs->y )
  {
    mins->y = maxs->y;
    maxs->y = y;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10045110
// Name: void GetAxisFromFace(int,class Vector __near &,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetAxisFromFace(int nFace, Vector *vHorz, Vector *vVert, Vector *vThrd)
{
  __int64 v4; // xmm0_8
  int v5; // ecx
  int v6; // eax
  float v7; // edx
  __int64 v8; // xmm0_8
  float v9; // xmm1_4
  float v10; // eax
  float v11; // xmm1_4
  float v12; // xmm2_4
  float y; // xmm5_4
  float z; // xmm3_4
  float x; // xmm4_4
  Vector points[8]; // [esp+0h] [ebp-84h] BYREF
  Vector p2; // [esp+60h] [ebp-24h]
  Vector p3; // [esp+6Ch] [ebp-18h] BYREF
  Vector p1; // [esp+78h] [ebp-Ch] BYREF

  p3.x = 1.0;
  p3.y = 1.0;
  p3.z = 1.0;
  memset(&p1, 0, sizeof(p1));
  PointsFromBox(mins: &p1, maxs: &p3, points);
  v4 = *(_QWORD *)&points[s_BoxFaces[nFace][0]].x;
  p1.z = points[s_BoxFaces[nFace][0]].z;
  v5 = s_BoxFaces[nFace][1];
  v6 = s_BoxFaces[nFace][2];
  *(_QWORD *)&p1.x = v4;
  v5 *= 3;
  v7 = *(&points[0].z + v5);
  v6 *= 3;
  *(_QWORD *)&p2.x = *(_QWORD *)(&points[0].x + v5);
  v8 = *(_QWORD *)(&points[0].x + v6);
  v9 = p2.y - p1.y;
  v10 = *(&points[0].z + v6);
  *(_QWORD *)&p3.x = v8;
  p3.z = v10;
  vHorz->x = p2.x - p1.x;
  *(float *)&v8 = p3.x - p1.x;
  vHorz->y = v9;
  v11 = p3.y - p1.y;
  p2.z = v7;
  vHorz->z = v7 - p1.z;
  v12 = p3.z - p1.z;
  LODWORD(vVert->x) = v8;
  vVert->y = v11;
  vVert->z = v12;
  y = vHorz->y;
  z = vHorz->z;
  x = vHorz->x;
  vThrd->x = (float)(y * v12) - (float)(z * v11);
  vThrd->y = (float)(z * *(float *)&v8) - (float)(x * v12);
  vThrd->z = (float)(x * v11) - (float)(y * *(float *)&v8);
}

//------------------------------------------------------------------------------
// Address: 0x10045280
// Name: float IntersectionLineAABBox(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
double __usercall IntersectionLineAABBox@<st0>(
        int a1@<ebp>,
        const Vector *mins,
        const Vector *maxs,
        const Vector *vStart,
        const Vector *vEnd,
        int *nFace)
{
  float y; // xmm1_4
  float x; // xmm0_4
  float v8; // xmm2_4
  float v9; // xmm7_4
  float v10; // xmm1_4
  float v11; // xmm5_4
  float z; // xmm6_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float v15; // xmm4_4
  float v16; // xmm5_4
  float v17; // xmm4_4
  float v18; // xmm3_4
  float v19; // xmm0_4
  float v20; // xmm6_4
  float v21; // xmm5_4
  int *v22; // esi
  float v23; // xmm1_4
  __int64 v24; // xmm0_8
  int v25; // eax
  float v26; // xmm2_4
  __int64 v27; // xmm0_8
  float v28; // ecx
  int v29; // eax
  float v30; // edx
  float v31; // xmm1_4
  float v32; // xmm1_4
  float v33; // xmm1_4
  float v34; // xmm2_4
  float v35; // xmm0_4
  __int128 v36; // xmm0
  Vector v38; // [esp-Ch] [ebp-154h] BYREF
  Vector points[8]; // [esp+0h] [ebp-148h] BYREF
  float v40; // [esp+64h] [ebp-E4h]
  float v41; // [esp+68h] [ebp-E0h]
  float v42; // [esp+6Ch] [ebp-DCh]
  float v43; // [esp+74h] [ebp-D4h]
  float v44; // [esp+78h] [ebp-D0h]
  float v45; // [esp+7Ch] [ebp-CCh]
  VMatrix v46; // [esp+94h] [ebp-B4h] BYREF
  __int64 v47; // [esp+D8h] [ebp-70h]
  float v48; // [esp+E0h] [ebp-68h]
  Vector p2; // [esp+E4h] [ebp-64h]
  float v50; // [esp+F0h] [ebp-58h]
  Vector p1; // [esp+F4h] [ebp-54h]
  float v52; // [esp+100h] [ebp-48h]
  Vector v0; // [esp+104h] [ebp-44h]
  float v54; // [esp+110h] [ebp-38h]
  float v55; // [esp+114h] [ebp-34h]
  float v56; // [esp+118h] [ebp-30h]
  __int128 vCenter; // [esp+11Ch] [ebp-2Ch] OVERLAPPED
  Vector p3_4; // [esp+130h] [ebp-18h] OVERLAPPED
  int v59; // [esp+13Ch] [ebp-Ch]
  float fDistance; // [esp+140h] [ebp-8h]
  float retaddr; // [esp+148h] [ebp+0h]

  v59 = a1;
  fDistance = retaddr;
  y = vEnd->y;
  x = vEnd->x;
  v8 = vStart->y;
  v9 = vStart->x;
  p3_4.x = vStart->z;
  v10 = y - v8;
  p2.x = v8;
  v11 = maxs->y;
  z = maxs->z;
  v13 = vEnd->z - p3_4.x;
  v14 = mins->x + maxs->x;
  p3_4.y = maxs->x;
  v15 = mins->y + v11;
  p3_4.z = v11;
  v16 = mins->z + z;
  p1.x = z;
  v17 = v15 * 0.5;
  v18 = v14 * 0.5;
  v56 = v16 * 0.5;
  *((float *)&vCenter + 2) = p3_4.z - v17;
  v55 = v17;
  v19 = x - v9;
  v20 = (float)((float)((float)(p3_4.z - v17) * (float)(p3_4.z - v17))
              + (float)((float)(p3_4.y - v18) * (float)(p3_4.y - v18)))
      + (float)((float)(z - (float)(v16 * 0.5)) * (float)(z - (float)(v16 * 0.5)));
  *((float *)&vCenter + 3) = p3_4.x - (float)(v16 * 0.5);
  *((float *)&vCenter + 1) = v9 - v18;
  v21 = (float)((float)((float)((float)(v13 * (float)(v9 - v18)) - (float)(*((float *)&vCenter + 3) * v19))
                      * (float)((float)(v13 * (float)(v9 - v18)) - (float)(*((float *)&vCenter + 3) * v19)))
              + (float)((float)((float)(*((float *)&vCenter + 3) * v10) - (float)((float)(p2.x - v17) * v13))
                      * (float)((float)(*((float *)&vCenter + 3) * v10) - (float)((float)(p2.x - v17) * v13))))
      + (float)((float)((float)((float)(p2.x - v55) * v19) - (float)(*((float *)&vCenter + 1) * v10))
              * (float)((float)((float)(p2.x - v55) * v19) - (float)(*((float *)&vCenter + 1) * v10)));
  *nFace = -1;
  if ( (float)(v21 / (float)((float)((float)(v19 * v19) + (float)(v10 * v10)) + (float)(v13 * v13))) > v20 )
    return -1.0;
  PointsFromBox(mins, maxs, points: &v38);
  v0.x = -v19;
  v54 = -v19;
  v0.y = -v10;
  v0.z = -v13;
  v55 = -v10;
  v56 = -v13;
  *(_QWORD *)&p3_4.y = 1232348144;
  v22 = &s_BoxFaces[0][1];
  do
  {
    v23 = vStart->x;
    v24 = *(_QWORD *)(&v38.x + 3 * *(v22 - 1));
    v50 = *(&v38.z + 3 * *(v22 - 1));
    v25 = *v22;
    *(_QWORD *)&p2.y = v24;
    v26 = *((float *)&v24 + 1);
    v25 *= 3;
    v27 = *(_QWORD *)(&v38.x + v25);
    v28 = *(&v38.z + v25);
    v29 = v22[1];
    v47 = v27;
    v29 *= 3;
    v30 = *(&v38.z + v29);
    *(_QWORD *)((char *)&vCenter + 4) = *(_QWORD *)(&v38.x + v29);
    p1.y = v23 - p2.y;
    v31 = vStart->y;
    *((float *)&vCenter + 3) = v30;
    v46.m[1][2] = v30 - v50;
    p1.z = v31 - v26;
    v32 = vStart->z - v50;
    *(_QWORD *)&v46.m[2][0] = *(_QWORD *)&v0.x;
    v48 = v28;
    v52 = v32;
    *(_QWORD *)&v46.m[2][2] = LODWORD(v0.z);
    v46.m[0][0] = *(float *)&v27 - p2.y;
    v46.m[0][1] = *((float *)&v27 + 1) - v26;
    v46.m[0][2] = v28 - v50;
    v46.m[0][3] = 0.0;
    v46.m[1][0] = *((float *)&vCenter + 1) - p2.y;
    v46.m[1][1] = *((float *)&vCenter + 2) - v26;
    v46.m[1][3] = 0.0;
    *(_QWORD *)&v46.m[3][0] = 0;
    *(_QWORD *)&v46.m[3][2] = 0x3F80000000000000LL;
    if ( VMatrix::InverseGeneral(this: &v46, vInverse: (VMatrix *)&points[7]) )
    {
      v33 = (float)((float)(v40 * p1.z) + (float)(points[7].x * p1.y)) + (float)(v43 * v52);
      v34 = (float)((float)(v41 * p1.z) + (float)(points[7].y * p1.y)) + (float)(v44 * v52);
      v35 = (float)((float)(v42 * p1.z) + (float)(points[7].z * p1.y)) + (float)(v45 * v52);
      if ( v35 >= 0.0 && v35 <= 1.0 && v33 >= 0.0 && v33 <= 1.0 && v34 >= 0.0 && v34 <= 1.0 && p3_4.y > v35 )
      {
        *nFace = LODWORD(p3_4.z);
        p3_4.y = v35;
      }
    }
    ++LODWORD(p3_4.z);
    v22 += 3;
  }
  while ( (int)v22 < (int)&vec2_invalid_38.y );
  if ( *nFace < 0 )
    return -1.0;
  p3_4.x = v55 * v55;
  v36 = 0;
  *(float *)&v36 = fsqrt((float)((float)(v55 * v55) + (float)(v56 * v56)) + (float)(v54 * v54));
  vCenter = v36;
  return *(float *)&v36 * p3_4.y;
}

//------------------------------------------------------------------------------
// Address: 0x10045740
// Name: class Vector const __near & GetNormalFromFace(int)
// Source: json
//------------------------------------------------------------------------------
const Vector *__cdecl GetNormalFromFace(int nFace)
{
  Vector *v1; // edx
  Vector *v2; // ecx
  Vector *v3; // esi
  float v4; // xmm1_4
  float v5; // xmm3_4
  float v6; // xmm2_4
  float v7; // xmm0_4
  float v8; // xmm4_4
  float v9; // xmm5_4
  Vector points[8]; // [esp+0h] [ebp-84h] BYREF
  Vector mins; // [esp+60h] [ebp-24h] BYREF
  Vector maxs; // [esp+6Ch] [ebp-18h] BYREF
  int v14; // [esp+80h] [ebp-4h]

  maxs.x = 1.0;
  maxs.y = 1.0;
  maxs.z = 1.0;
  memset(&mins, 0, sizeof(mins));
  PointsFromBox(&mins, &maxs, points);
  v1 = &points[s_BoxFaces[nFace][2]];
  v2 = &points[s_BoxFaces[nFace][1]];
  v3 = &points[s_BoxFaces[nFace][0]];
  if ( (_S1_0 & 1) == 0 )
  {
    _S1_0 |= 1u;
    v14 = -1;
  }
  v4 = v1->y - v2->y;
  v5 = v1->z - v2->z;
  v6 = v3->y - v2->y;
  v7 = v3->z - v2->z;
  v8 = v3->x - v2->x;
  v9 = v1->x - v2->x;
  vNormal.x = (float)(v5 * v6) - (float)(v4 * v7);
  vNormal.y = (float)(v7 * v9) - (float)(v5 * v8);
  vNormal.z = (float)(v4 * v8) - (float)(v6 * v9);
  VectorNormalize(vec: &vNormal);
  return &vNormal;
}
