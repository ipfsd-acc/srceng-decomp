// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mathlib/camera.cpp
// Functions: 3
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00676330
// Name: void ComputeViewMatrix(class VMatrix __near *,struct Camera_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeViewMatrix(VMatrix *pWorldToView, const Camera_t *camera)
{
  VMatrix matRotateX; // [esp+4h] [ebp-12Ch] BYREF
  VMatrix matRotateZ; // [esp+44h] [ebp-ECh] BYREF
  matrix3x4_t invTransform; // [esp+84h] [ebp-ACh] BYREF
  matrix3x4_t transform; // [esp+B4h] [ebp-7Ch] BYREF
  VMatrix matRotate; // [esp+E4h] [ebp-4Ch] BYREF
  Vector vAxisOfRot; // [esp+124h] [ebp-Ch] BYREF

  AngleMatrix(angles: &camera->m_angles, position: &camera->m_origin, matrix: &transform);
  *(matrix3x4_t *)&matRotate.m[0][0] = transform;
  *(_QWORD *)&matRotate.m[3][0] = 0;
  *(_QWORD *)&matRotate.m[3][2] = 0x3F80000000000000LL;
  vAxisOfRot.x = 0.0;
  vAxisOfRot.y = 0.0;
  vAxisOfRot.z = 1.0;
  MatrixBuildRotationAboutAxis(dst: (matrix3x4_t *)&matRotateZ, &vAxisOfRot, angleDegrees: -90.0);
  MatrixMultiply(src1: &matRotate, src2: &matRotateZ, dst: &matRotate);
  vAxisOfRot.x = 1.0;
  vAxisOfRot.y = 0.0;
  vAxisOfRot.z = 0.0;
  MatrixBuildRotationAboutAxis(dst: (matrix3x4_t *)&matRotateX, &vAxisOfRot, angleDegrees: 90.0);
  MatrixMultiply(src1: &matRotate, src2: &matRotateX, dst: &matRotate);
  transform = *(matrix3x4_t *)&matRotate.m[0][0];
  MatrixInvert(in: &transform, out: &invTransform);
  *(matrix3x4_t *)&pWorldToView->m[0][0] = invTransform;
  *(_QWORD *)&pWorldToView->m[3][0] = 0;
  pWorldToView->m[3][2] = 0.0;
  pWorldToView->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x00676500
// Name: void ComputeProjectionMatrix(class VMatrix __near *,struct Camera_t const __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeProjectionMatrix(VMatrix *pCameraToProjection, const Camera_t *camera, int width, int height)
{
  __m128i v4; // xmm0
  double v5; // xmm0_8
  float m_flZFar; // [esp+0h] [ebp-8h]
  float m_flZNear; // [esp+4h] [ebp-4h]

  m_flZNear = camera->m_flZNear;
  m_flZFar = camera->m_flZFar;
  v4 = (__m128i)_mm_cvtps_pd((__m128)LODWORD(camera->m_flFOVX));
  *(double *)v4.m128i_i64 = *(double *)v4.m128i_i64 * 3.141592653589793 * 0.002777777777777778;
  __libm_sse2_tan(X: v4);
  *(float *)&v5 = v5;
  memset(dst: (int)pCameraToProjection, value: 0, count: sizeof(VMatrix));
  pCameraToProjection->m[0][0] = 1.0 / *(float *)&v5;
  pCameraToProjection->m[1][1] = 1.0 / (float)(*(float *)&v5 / (float)((float)width / (float)height));
  pCameraToProjection->m[2][2] = m_flZFar / (float)(m_flZNear - m_flZFar);
  pCameraToProjection->m[3][2] = -1.0;
  pCameraToProjection->m[2][3] = (float)(m_flZNear * m_flZFar) / (float)(m_flZNear - m_flZFar);
}

//------------------------------------------------------------------------------
// Address: 0x006765D0
// Name: void ComputeScreenSpacePosition(class Vector2D __near *,class Vector const __near &,struct Camera_t const __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeScreenSpacePosition(
        Vector2D *pScreenPosition,
        Vector *vecWorldPosition,
        const Camera_t *camera,
        int width,
        int height)
{
  __m128i v5; // xmm0
  double v6; // xmm0_8
  VMatrix viewproj; // [esp+4h] [ebp-D4h] BYREF
  VMatrix view; // [esp+44h] [ebp-94h] BYREF
  VMatrix proj; // [esp+84h] [ebp-54h] BYREF
  Vector vecScreenPos; // [esp+C4h] [ebp-14h] BYREF
  float m_flZFar; // [esp+D0h] [ebp-8h]
  float m_flZNear; // [esp+D4h] [ebp-4h]

  ComputeViewMatrix(pWorldToView: &view, camera);
  m_flZNear = camera->m_flZNear;
  m_flZFar = camera->m_flZFar;
  v5 = (__m128i)_mm_cvtps_pd((__m128)LODWORD(camera->m_flFOVX));
  *(double *)v5.m128i_i64 = *(double *)v5.m128i_i64 * 3.141592653589793 * 0.002777777777777778;
  __libm_sse2_tan(X: v5);
  *(float *)&v6 = v6;
  memset(dst: (int)&proj, value: 0, count: sizeof(proj));
  proj.m[0][0] = 1.0 / *(float *)&v6;
  proj.m[1][1] = 1.0 / (float)(*(float *)&v6 / (float)((float)width / (float)height));
  proj.m[2][2] = m_flZFar / (float)(m_flZNear - m_flZFar);
  proj.m[3][2] = -1.0;
  proj.m[2][3] = (float)(m_flZNear * m_flZFar) / (float)(m_flZNear - m_flZFar);
  MatrixMultiply(src1: &proj, src2: &view, dst: &viewproj);
  Vector3DMultiplyPositionProjective(src1: &viewproj, src2: vecWorldPosition, dst: &vecScreenPos);
  *(float *)&v6 = (float)((float)(1.0 - vecScreenPos.y) * (float)height) * 0.5;
  pScreenPosition->x = (float)((float)(vecScreenPos.x + 1.0) * (float)width) * 0.5;
  pScreenPosition->y = *(float *)&v6;
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x104C3D50
// Name: void ComputeViewMatrix(class VMatrix __near *,struct Camera_t const __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __cdecl ComputeViewMatrix(VMatrix *pWorldToView, VMatrix *camera)
{
  float angleDegrees; // [esp+0h] [ebp-12Ch] BYREF
  VMatrix matRotateX; // [esp+4h] [ebp-128h] BYREF
  _BYTE matRotateZ_60[164]; // [esp+80h] [ebp-ACh] OVERLAPPED BYREF
  Vector vAxisOfRot; // [esp+124h] [ebp-8h]

  AngleMatrix(
    angles: (const QAngle *)&camera->m[0][3],
    position: (const Vector *)camera,
    matrix: (matrix3x4_t *)&matRotateZ_60[48]);
  *(_QWORD *)&matRotateZ_60[96] = *(_QWORD *)&matRotateZ_60[48];
  *(_QWORD *)&matRotateZ_60[104] = *(_QWORD *)&matRotateZ_60[56];
  *(_QWORD *)&matRotateZ_60[112] = *(_QWORD *)&matRotateZ_60[64];
  *(_QWORD *)&matRotateZ_60[120] = *(_QWORD *)&matRotateZ_60[72];
  *(_QWORD *)&matRotateZ_60[128] = *(_QWORD *)&matRotateZ_60[80];
  *(_QWORD *)&matRotateZ_60[136] = *(_QWORD *)&matRotateZ_60[88];
  memset(&matRotateZ_60[144], 0, 12);
  vAxisOfRot.x = 0.0;
  *(_QWORD *)&matRotateZ_60[156] = 1065353216;
  vAxisOfRot.y = 1.0;
  MatrixBuildRotationAboutAxis(
    dst: (matrix3x4_t *)&matRotateX.m[3][3],
    vAxisOfRot: (const Vector *)&matRotateZ_60[160],
    angleDegrees: -90.0);
  MatrixMultiply(
    src1: (VMatrix *)&matRotateZ_60[96],
    src2: (VMatrix *)&matRotateX.m[3][3],
    dst: (VMatrix *)&matRotateZ_60[96]);
  *(_DWORD *)&matRotateZ_60[160] = 1065353216;
  vAxisOfRot.x = 0.0;
  vAxisOfRot.y = 0.0;
  MatrixBuildRotationAboutAxis(
    dst: (matrix3x4_t *)&angleDegrees,
    vAxisOfRot: (const Vector *)&matRotateZ_60[160],
    angleDegrees: 90.0);
  MatrixMultiply(
    src1: (VMatrix *)&matRotateZ_60[96],
    src2: (VMatrix *)&angleDegrees,
    dst: (VMatrix *)&matRotateZ_60[96]);
  *(_QWORD *)&matRotateZ_60[48] = *(_QWORD *)&matRotateZ_60[96];
  *(_QWORD *)&matRotateZ_60[56] = *(_QWORD *)&matRotateZ_60[104];
  *(_QWORD *)&matRotateZ_60[64] = *(_QWORD *)&matRotateZ_60[112];
  *(_QWORD *)&matRotateZ_60[72] = *(_QWORD *)&matRotateZ_60[120];
  *(_QWORD *)&matRotateZ_60[80] = *(_QWORD *)&matRotateZ_60[128];
  *(_QWORD *)&matRotateZ_60[88] = *(_QWORD *)&matRotateZ_60[136];
  MatrixInvert(in: (const matrix3x4_t *)&matRotateZ_60[48], out: (matrix3x4_t *)matRotateZ_60);
  qmemcpy(pWorldToView, matRotateZ_60, 48);
  *(_QWORD *)&pWorldToView->m[3][0] = 0;
  pWorldToView->m[3][2] = 0.0;
  pWorldToView->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x104C3F20
// Name: void ComputeProjectionMatrix(class VMatrix __near *,struct Camera_t const __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall ComputeProjectionMatrix(
        int a1@<esi>,
        VMatrix *pCameraToProjection,
        const Camera_t *camera,
        int width,
        int height)
{
  double v5; // xmm0_8
  long double v6; // [esp-4h] [ebp-Ch]
  float v7; // [esp+0h] [ebp-8h]
  float m_flZNear; // [esp+4h] [ebp-4h]

  m_flZNear = camera->m_flZNear;
  HIDWORD(v6) = LODWORD(camera->m_flZFar);
  v5 = camera->m_flFOVX * 3.141592653589793 * 0.002777777777777778;
  LODWORD(v6) = a1;
  __libm_sse2_tan(x: v6);
  *(float *)&v5 = v5;
  memset(dst: (unsigned __int8 *)pCameraToProjection, value: 0, count: sizeof(VMatrix));
  pCameraToProjection->m[0][0] = 1.0 / *(float *)&v5;
  pCameraToProjection->m[1][1] = 1.0 / (float)(*(float *)&v5 / (float)((float)width / (float)height));
  pCameraToProjection->m[2][2] = v7 / (float)(m_flZNear - v7);
  pCameraToProjection->m[3][2] = -1.0;
  pCameraToProjection->m[2][3] = (float)(m_flZNear * v7) / (float)(m_flZNear - v7);
}

//------------------------------------------------------------------------------
// Address: 0x104C3FF0
// Name: void ComputeScreenSpacePosition(class Vector2D __near *,class Vector const __near &,struct Camera_t const __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeScreenSpacePosition(
        Vector2D *pScreenPosition,
        Vector *vecWorldPosition,
        VMatrix *camera,
        int width,
        int height)
{
  double v5; // xmm0_8
  long double v6; // [esp-8h] [ebp-E0h]
  VMatrix viewproj; // [esp+4h] [ebp-D4h] BYREF
  VMatrix view; // [esp+44h] [ebp-94h] BYREF
  VMatrix proj; // [esp+84h] [ebp-54h] BYREF
  Vector vecScreenPos; // [esp+C4h] [ebp-14h] BYREF
  float v11; // [esp+D0h] [ebp-8h]
  float v12; // [esp+D4h] [ebp-4h]

  ComputeViewMatrix(pWorldToView: &view, camera);
  v12 = camera->m[1][3];
  v11 = camera->m[2][0];
  v5 = camera->m[1][2] * 3.141592653589793 * 0.002777777777777778;
  __libm_sse2_tan(x: v6);
  *(float *)&v5 = v5;
  memset(dst: (unsigned __int8 *)&proj, value: 0, count: sizeof(proj));
  proj.m[0][0] = 1.0 / *(float *)&v5;
  proj.m[1][1] = 1.0 / (float)(*(float *)&v5 / (float)((float)width / (float)height));
  proj.m[2][2] = v11 / (float)(v12 - v11);
  proj.m[3][2] = -1.0;
  proj.m[2][3] = (float)(v12 * v11) / (float)(v12 - v11);
  MatrixMultiply(src1: &proj, src2: &view, dst: &viewproj);
  Vector3DMultiplyPositionProjective(src1: &viewproj, src2: vecWorldPosition, dst: &vecScreenPos);
  *(float *)&v5 = (float)((float)(1.0 - vecScreenPos.y) * (float)height) * 0.5;
  pScreenPosition->x = (float)((float)(vecScreenPos.x + 1.0) * (float)width) * 0.5;
  pScreenPosition->y = *(float *)&v5;
}

} // namespace hammer_dll

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x004B3DB0
// Name: void ComputeViewMatrix(class VMatrix __near *,struct Camera_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeViewMatrix(VMatrix *pWorldToView, const Camera_t *camera)
{
  VMatrix matRotateX; // [esp+4h] [ebp-12Ch] BYREF
  VMatrix matRotateZ; // [esp+44h] [ebp-ECh] BYREF
  matrix3x4_t invTransform; // [esp+84h] [ebp-ACh] BYREF
  matrix3x4_t transform; // [esp+B4h] [ebp-7Ch] BYREF
  VMatrix matRotate; // [esp+E4h] [ebp-4Ch] BYREF
  Vector vAxisOfRot; // [esp+124h] [ebp-Ch] BYREF

  AngleMatrix(angles: &camera->m_angles, position: &camera->m_origin, matrix: &transform);
  *(matrix3x4_t *)&matRotate.m[0][0] = transform;
  *(_QWORD *)&matRotate.m[3][0] = 0;
  *(_QWORD *)&matRotate.m[3][2] = 0x3F80000000000000LL;
  vAxisOfRot.x = 0.0;
  vAxisOfRot.y = 0.0;
  vAxisOfRot.z = 1.0;
  MatrixBuildRotationAboutAxis(dst: (matrix3x4_t *)&matRotateZ, &vAxisOfRot, angleDegrees: -90.0);
  MatrixMultiply(src1: &matRotate, src2: &matRotateZ, dst: &matRotate);
  vAxisOfRot.x = 1.0;
  vAxisOfRot.y = 0.0;
  vAxisOfRot.z = 0.0;
  MatrixBuildRotationAboutAxis(dst: (matrix3x4_t *)&matRotateX, &vAxisOfRot, angleDegrees: 90.0);
  MatrixMultiply(src1: &matRotate, src2: &matRotateX, dst: &matRotate);
  transform = *(matrix3x4_t *)&matRotate.m[0][0];
  MatrixInvert(in: &transform, out: &invTransform);
  *(matrix3x4_t *)&pWorldToView->m[0][0] = invTransform;
  *(_QWORD *)&pWorldToView->m[3][0] = 0;
  pWorldToView->m[3][2] = 0.0;
  pWorldToView->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x004B3F80
// Name: void ComputeProjectionMatrix(class VMatrix __near *,struct Camera_t const __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeProjectionMatrix(VMatrix *pCameraToProjection, const Camera_t *camera, int width, int height)
{
  __m128i v4; // xmm0
  double v5; // xmm0_8
  float m_flZFar; // [esp+0h] [ebp-8h]
  float m_flZNear; // [esp+4h] [ebp-4h]

  m_flZNear = camera->m_flZNear;
  m_flZFar = camera->m_flZFar;
  v4 = (__m128i)_mm_cvtps_pd((__m128)LODWORD(camera->m_flFOVX));
  *(double *)v4.m128i_i64 = *(double *)v4.m128i_i64 * 3.141592653589793 * 0.002777777777777778;
  __libm_sse2_tan(X: v4);
  *(float *)&v5 = v5;
  memset(dst: (int)pCameraToProjection, value: 0, count: sizeof(VMatrix));
  pCameraToProjection->m[0][0] = 1.0 / *(float *)&v5;
  pCameraToProjection->m[1][1] = 1.0 / (float)(*(float *)&v5 / (float)((float)width / (float)height));
  pCameraToProjection->m[2][2] = m_flZFar / (float)(m_flZNear - m_flZFar);
  pCameraToProjection->m[3][2] = -1.0;
  pCameraToProjection->m[2][3] = (float)(m_flZNear * m_flZFar) / (float)(m_flZNear - m_flZFar);
}

} // namespace modelbrowser

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x006A51D0
// Name: void ComputeViewMatrix(class VMatrix __near *,struct Camera_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeViewMatrix(VMatrix *pWorldToView, const Camera_t *camera)
{
  VMatrix matRotateX; // [esp+4h] [ebp-12Ch] BYREF
  VMatrix matRotateZ; // [esp+44h] [ebp-ECh] BYREF
  matrix3x4_t invTransform; // [esp+84h] [ebp-ACh] BYREF
  matrix3x4_t transform; // [esp+B4h] [ebp-7Ch] BYREF
  VMatrix matRotate; // [esp+E4h] [ebp-4Ch] BYREF
  Vector vAxisOfRot; // [esp+124h] [ebp-Ch] BYREF

  AngleMatrix(angles: &camera->m_angles, position: &camera->m_origin, matrix: &transform);
  *(matrix3x4_t *)&matRotate.m[0][0] = transform;
  *(_QWORD *)&matRotate.m[3][0] = 0;
  *(_QWORD *)&matRotate.m[3][2] = 0x3F80000000000000LL;
  vAxisOfRot.x = 0.0;
  vAxisOfRot.y = 0.0;
  vAxisOfRot.z = 1.0;
  MatrixBuildRotationAboutAxis(dst: (matrix3x4_t *)&matRotateZ, &vAxisOfRot, angleDegrees: -90.0);
  MatrixMultiply(src1: &matRotate, src2: &matRotateZ, dst: &matRotate);
  vAxisOfRot.x = 1.0;
  vAxisOfRot.y = 0.0;
  vAxisOfRot.z = 0.0;
  MatrixBuildRotationAboutAxis(dst: (matrix3x4_t *)&matRotateX, &vAxisOfRot, angleDegrees: 90.0);
  MatrixMultiply(src1: &matRotate, src2: &matRotateX, dst: &matRotate);
  transform = *(matrix3x4_t *)&matRotate.m[0][0];
  MatrixInvert(in: &transform, out: &invTransform);
  *(matrix3x4_t *)&pWorldToView->m[0][0] = invTransform;
  *(_QWORD *)&pWorldToView->m[3][0] = 0;
  pWorldToView->m[3][2] = 0.0;
  pWorldToView->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x006A53A0
// Name: void ComputeProjectionMatrix(class VMatrix __near *,struct Camera_t const __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeProjectionMatrix(VMatrix *pCameraToProjection, const Camera_t *camera, int width, int height)
{
  __m128i v4; // xmm0
  double v5; // xmm0_8
  float m_flZFar; // [esp+0h] [ebp-8h]
  float m_flZNear; // [esp+4h] [ebp-4h]

  m_flZNear = camera->m_flZNear;
  m_flZFar = camera->m_flZFar;
  v4 = (__m128i)_mm_cvtps_pd((__m128)LODWORD(camera->m_flFOVX));
  *(double *)v4.m128i_i64 = *(double *)v4.m128i_i64 * 3.141592653589793 * 0.002777777777777778;
  __libm_sse2_tan(X: v4);
  *(float *)&v5 = v5;
  memset(dst: (int)pCameraToProjection, value: 0, count: sizeof(VMatrix));
  pCameraToProjection->m[0][0] = 1.0 / *(float *)&v5;
  pCameraToProjection->m[1][1] = 1.0 / (float)(*(float *)&v5 / (float)((float)width / (float)height));
  pCameraToProjection->m[2][2] = m_flZFar / (float)(m_flZNear - m_flZFar);
  pCameraToProjection->m[3][2] = -1.0;
  pCameraToProjection->m[2][3] = (float)(m_flZNear * m_flZFar) / (float)(m_flZNear - m_flZFar);
}

//------------------------------------------------------------------------------
// Address: 0x006A5470
// Name: void ComputeScreenSpacePosition(class Vector2D __near *,class Vector const __near &,struct Camera_t const __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeScreenSpacePosition(
        Vector2D *pScreenPosition,
        Vector *vecWorldPosition,
        const Camera_t *camera,
        int width,
        int height)
{
  __m128i v5; // xmm0
  double v6; // xmm0_8
  VMatrix viewproj; // [esp+4h] [ebp-D4h] BYREF
  VMatrix view; // [esp+44h] [ebp-94h] BYREF
  VMatrix proj; // [esp+84h] [ebp-54h] BYREF
  Vector vecScreenPos; // [esp+C4h] [ebp-14h] BYREF
  float m_flZFar; // [esp+D0h] [ebp-8h]
  float m_flZNear; // [esp+D4h] [ebp-4h]

  ComputeViewMatrix(pWorldToView: &view, camera);
  m_flZNear = camera->m_flZNear;
  m_flZFar = camera->m_flZFar;
  v5 = (__m128i)_mm_cvtps_pd((__m128)LODWORD(camera->m_flFOVX));
  *(double *)v5.m128i_i64 = *(double *)v5.m128i_i64 * 3.141592653589793 * 0.002777777777777778;
  __libm_sse2_tan(X: v5);
  *(float *)&v6 = v6;
  memset(dst: (int)&proj, value: 0, count: sizeof(proj));
  proj.m[0][0] = 1.0 / *(float *)&v6;
  proj.m[1][1] = 1.0 / (float)(*(float *)&v6 / (float)((float)width / (float)height));
  proj.m[2][2] = m_flZFar / (float)(m_flZNear - m_flZFar);
  proj.m[3][2] = -1.0;
  proj.m[2][3] = (float)(m_flZNear * m_flZFar) / (float)(m_flZNear - m_flZFar);
  MatrixMultiply(src1: &proj, src2: &view, dst: &viewproj);
  Vector3DMultiplyPositionProjective(src1: &viewproj, src2: vecWorldPosition, dst: &vecScreenPos);
  *(float *)&v6 = (float)((float)(1.0 - vecScreenPos.y) * (float)height) * 0.5;
  pScreenPosition->x = (float)((float)(vecScreenPos.x + 1.0) * (float)width) * 0.5;
  pScreenPosition->y = *(float *)&v6;
}

} // namespace sceneviewer

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x1040CE40
// Name: void ComputeViewMatrix(class VMatrix __near *,struct Camera_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeViewMatrix(VMatrix *pWorldToView, const Camera_t *camera)
{
  VMatrix matRotateX; // [esp+4h] [ebp-12Ch] BYREF
  VMatrix matRotateZ; // [esp+44h] [ebp-ECh] BYREF
  matrix3x4_t invTransform; // [esp+84h] [ebp-ACh] BYREF
  matrix3x4_t transform; // [esp+B4h] [ebp-7Ch] BYREF
  VMatrix matRotate; // [esp+E4h] [ebp-4Ch] BYREF
  Vector vAxisOfRot; // [esp+124h] [ebp-Ch] BYREF

  AngleMatrix(angles: &camera->m_angles, position: &camera->m_origin, matrix: &transform);
  *(matrix3x4_t *)&matRotate.m[0][0] = transform;
  *(_QWORD *)&matRotate.m[3][0] = 0;
  *(_QWORD *)&matRotate.m[3][2] = 0x3F80000000000000LL;
  vAxisOfRot.x = 0.0;
  vAxisOfRot.y = 0.0;
  vAxisOfRot.z = 1.0;
  MatrixBuildRotationAboutAxis(dst: &matRotateZ, &vAxisOfRot, angleDegrees: -90.0);
  MatrixMultiply(src1: &matRotate, src2: &matRotateZ, dst: &matRotate);
  vAxisOfRot.x = 1.0;
  vAxisOfRot.y = 0.0;
  vAxisOfRot.z = 0.0;
  MatrixBuildRotationAboutAxis(dst: &matRotateX, &vAxisOfRot, angleDegrees: 90.0);
  MatrixMultiply(src1: &matRotate, src2: &matRotateX, dst: &matRotate);
  transform = *(matrix3x4_t *)&matRotate.m[0][0];
  MatrixInvert(in: &transform, out: &invTransform);
  *(matrix3x4_t *)&pWorldToView->m[0][0] = invTransform;
  *(_QWORD *)&pWorldToView->m[3][0] = 0;
  pWorldToView->m[3][2] = 0.0;
  pWorldToView->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x1040D010
// Name: void ComputeProjectionMatrix(class VMatrix __near *,struct Camera_t const __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall ComputeProjectionMatrix(
        int a1@<esi>,
        VMatrix *pCameraToProjection,
        const Camera_t *camera,
        int width,
        int height)
{
  double v5; // xmm0_8
  long double v6; // [esp-4h] [ebp-Ch]
  float v7; // [esp+0h] [ebp-8h]
  float m_flZNear; // [esp+4h] [ebp-4h]

  m_flZNear = camera->m_flZNear;
  HIDWORD(v6) = LODWORD(camera->m_flZFar);
  v5 = camera->m_flFOVX * 3.141592653589793 * 0.002777777777777778;
  LODWORD(v6) = a1;
  __libm_sse2_tan(x: v6);
  *(float *)&v5 = v5;
  memset(dst: (unsigned __int8 *)pCameraToProjection, value: 0, count: sizeof(VMatrix));
  pCameraToProjection->m[0][0] = 1.0 / *(float *)&v5;
  pCameraToProjection->m[1][1] = 1.0 / (float)(*(float *)&v5 / (float)((float)width / (float)height));
  pCameraToProjection->m[2][2] = v7 / (float)(m_flZNear - v7);
  pCameraToProjection->m[3][2] = -1.0;
  pCameraToProjection->m[2][3] = (float)(m_flZNear * v7) / (float)(m_flZNear - v7);
}

} // namespace client
