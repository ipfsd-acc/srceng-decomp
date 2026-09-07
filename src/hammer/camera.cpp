// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/camera.cpp
// Functions: 144
// ============================================================

#include "hammer\camera.h"

//------------------------------------------------------------------------------
// Address: 0x1000A020
// Name: public: bool Vector::operator!=(class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall Vector::operator!=(Vector *this, const Vector *src)
{
  return src->x != this->x || src->y != this->y || src->z != this->z;
}

//------------------------------------------------------------------------------
// Address: 0x1000A060
// Name: public: virtual CCamera::~CCamera(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCamera::~CCamera(CCamera *this)
{
  this->__vftable = (CCamera_vtbl *)&CCamera::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1000A070
// Name: public: void CCamera::GetViewPort(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCamera::GetViewPort(CCamera *this, int *width, int *height)
{
  *width = this->m_nViewWidth;
  *height = this->m_nViewHeight;
}

//------------------------------------------------------------------------------
// Address: 0x1000A090
// Name: public: float CCamera::GetPitch(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CCamera::GetPitch(CCamera *this)
{
  return this->m_fPitch;
}

//------------------------------------------------------------------------------
// Address: 0x1000A0A0
// Name: public: float CCamera::GetRoll(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CCamera::GetRoll(CCamera *this)
{
  return this->m_fRoll;
}

//------------------------------------------------------------------------------
// Address: 0x1000A0B0
// Name: public: float CCamera::GetYaw(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CCamera::GetYaw(CCamera *this)
{
  return this->m_fYaw;
}

//------------------------------------------------------------------------------
// Address: 0x1000A0C0
// Name: public: class QAngle CCamera::GetAngles(void)
// Source: json
//------------------------------------------------------------------------------
QAngle *__thiscall CCamera::GetAngles(CCamera *this, QAngle *result)
{
  result->x = this->m_fPitch;
  result->y = this->m_fYaw;
  result->z = this->m_fRoll;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000A0E0
// Name: public: void CCamera::GetViewPoint(class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCamera::GetViewPoint(CCamera *this, Vector *ViewPoint)
{
  *ViewPoint = this->m_ViewPoint;
}

//------------------------------------------------------------------------------
// Address: 0x1000A100
// Name: public: void CCamera::GetViewForward(class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCamera::GetViewForward(CCamera *this, Vector *ViewForward)
{
  ViewForward->x = -this->m_ViewMatrix.m[2][0];
  ViewForward->y = -this->m_ViewMatrix.m[2][1];
  ViewForward->z = -this->m_ViewMatrix.m[2][2];
}

//------------------------------------------------------------------------------
// Address: 0x1000A140
// Name: public: void CCamera::GetViewRight(class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCamera::GetViewRight(CCamera *this, Vector *ViewRight)
{
  ViewRight->x = this->m_ViewMatrix.m[0][0];
  ViewRight->y = this->m_ViewMatrix.m[0][1];
  ViewRight->z = this->m_ViewMatrix.m[0][2];
}

//------------------------------------------------------------------------------
// Address: 0x1000A160
// Name: public: float CCamera::GetFOV(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CCamera::GetFOV(CCamera *this)
{
  return this->m_fHorizontalFOV;
}

//------------------------------------------------------------------------------
// Address: 0x1000A170
// Name: public: float CCamera::GetNearClip(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CCamera::GetNearClip(CCamera *this)
{
  return this->m_fNearClip;
}

//------------------------------------------------------------------------------
// Address: 0x1000A180
// Name: public: float CCamera::GetFarClip(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CCamera::GetFarClip(CCamera *this)
{
  return this->m_fFarClip;
}

//------------------------------------------------------------------------------
// Address: 0x1000A190
// Name: public: void CCamera::GetFrustumPlanes(class Vector4D __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCamera::GetFrustumPlanes(CCamera *this, Vector4D *Planes)
{
  float v3; // xmm1_4
  float v4; // xmm1_4
  float v5; // xmm1_4
  float v6; // xmm3_4
  float v7; // xmm0_4
  VMatrix CameraMatrix; // [esp+0h] [ebp-4Ch] BYREF
  Vector ViewForward; // [esp+40h] [ebp-Ch]

  ViewForward.x = -this->m_ViewMatrix.m[2][0];
  ViewForward.y = -this->m_ViewMatrix.m[2][1];
  ViewForward.z = -this->m_ViewMatrix.m[2][2];
  VMatrix::operator*(this: &this->m_ProjMatrix, result: &CameraMatrix, vm: &this->m_ViewMatrix);
  Planes->x = CameraMatrix.m[0][0] - CameraMatrix.m[3][0];
  Planes->y = CameraMatrix.m[0][1] - CameraMatrix.m[3][1];
  Planes->z = CameraMatrix.m[0][2] - CameraMatrix.m[3][2];
  VectorNormalize(vec: (Vector *)Planes);
  v3 = CameraMatrix.m[0][0];
  Planes->w = (float)((float)(this->m_ViewPoint.y * Planes->y) + (float)(this->m_ViewPoint.x * Planes->x))
            + (float)(this->m_ViewPoint.z * Planes->z);
  Planes[1].x = (float)-v3 - CameraMatrix.m[3][0];
  Planes[1].y = (float)-CameraMatrix.m[0][1] - CameraMatrix.m[3][1];
  Planes[1].z = (float)-CameraMatrix.m[0][2] - CameraMatrix.m[3][2];
  VectorNormalize(vec: (Vector *)&Planes[1]);
  Planes[1].w = (float)((float)(Planes[1].y * this->m_ViewPoint.y) + (float)(Planes[1].x * this->m_ViewPoint.x))
              + (float)(Planes[1].z * this->m_ViewPoint.z);
  Planes[2].x = CameraMatrix.m[1][0] - CameraMatrix.m[3][0];
  Planes[2].y = CameraMatrix.m[1][1] - CameraMatrix.m[3][1];
  Planes[2].z = CameraMatrix.m[1][2] - CameraMatrix.m[3][2];
  VectorNormalize(vec: (Vector *)&Planes[2]);
  v4 = CameraMatrix.m[1][0];
  Planes[2].w = (float)((float)(Planes[2].y * this->m_ViewPoint.y) + (float)(this->m_ViewPoint.x * Planes[2].x))
              + (float)(Planes[2].z * this->m_ViewPoint.z);
  Planes[3].x = (float)-v4 - CameraMatrix.m[3][0];
  Planes[3].y = (float)-CameraMatrix.m[1][1] - CameraMatrix.m[3][1];
  Planes[3].z = (float)-CameraMatrix.m[1][2] - CameraMatrix.m[3][2];
  VectorNormalize(vec: (Vector *)&Planes[3]);
  v5 = CameraMatrix.m[2][0];
  Planes[3].w = (float)((float)(Planes[3].y * this->m_ViewPoint.y) + (float)(this->m_ViewPoint.x * Planes[3].x))
              + (float)(Planes[3].z * this->m_ViewPoint.z);
  Planes[4].x = (float)-v5 - CameraMatrix.m[3][0];
  Planes[4].y = (float)-CameraMatrix.m[2][1] - CameraMatrix.m[3][1];
  Planes[4].z = (float)-CameraMatrix.m[2][2] - CameraMatrix.m[3][2];
  VectorNormalize(vec: (Vector *)&Planes[4]);
  v6 = (float)((float)(Planes[4].y * (float)(this->m_ViewPoint.y + (float)(ViewForward.y * this->m_fNearClip)))
             + (float)((float)(this->m_ViewPoint.x + (float)(ViewForward.x * this->m_fNearClip)) * Planes[4].x))
     + (float)(Planes[4].z * (float)(this->m_ViewPoint.z + (float)(ViewForward.z * this->m_fNearClip)));
  Planes[5].x = CameraMatrix.m[2][0] + CameraMatrix.m[3][0];
  Planes[5].y = CameraMatrix.m[2][1] + CameraMatrix.m[3][1];
  v7 = CameraMatrix.m[2][2];
  Planes[4].w = v6;
  Planes[5].z = v7 + CameraMatrix.m[3][2];
  VectorNormalize(vec: (Vector *)&Planes[5]);
  Planes[5].w = (float)((float)(Planes[5].y * (float)(this->m_ViewPoint.y + (float)(ViewForward.y * this->m_fFarClip)))
                      + (float)((float)(this->m_ViewPoint.x + (float)(ViewForward.x * this->m_fFarClip)) * Planes[5].x))
              + (float)(Planes[5].z * (float)(this->m_ViewPoint.z + (float)(ViewForward.z * this->m_fFarClip)));
}

//------------------------------------------------------------------------------
// Address: 0x1000A4E0
// Name: public: bool CCamera::IsOrthographic(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCamera::IsOrthographic(CCamera *this)
{
  return this->m_bIsOrthographic;
}

//------------------------------------------------------------------------------
// Address: 0x1000A4F0
// Name: protected: void CCamera::BuildProjMatrix(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCamera::BuildProjMatrix(CCamera *this)
{
  VMatrix *p_m_ProjMatrix; // edi
  float v3; // xmm0_4
  float v4; // xmm3_4
  double v5; // xmm0_8
  float v6; // xmm2_4
  const VMatrix *v7; // eax
  long double v8; // [esp+0h] [ebp-4Ch]
  VMatrix result; // [esp+Ch] [ebp-40h] BYREF

  p_m_ProjMatrix = &this->m_ProjMatrix;
  memset(dst: (unsigned __int8 *)&this->m_ProjMatrix, value: 0, count: sizeof(this->m_ProjMatrix));
  if ( this->m_bIsOrthographic )
  {
    v3 = 1.0 / this->m_fZoom;
    v4 = (float)this->m_nViewWidth * v3;
    p_m_ProjMatrix->m[1][1] = 2.0 / (float)((float)this->m_nViewHeight * v3);
    p_m_ProjMatrix->m[0][0] = 2.0 / v4;
    p_m_ProjMatrix->m[2][2] = 1.0 / (float)(this->m_fNearClip - this->m_fFarClip);
    p_m_ProjMatrix->m[2][3] = this->m_fNearClip / (float)(this->m_fNearClip - this->m_fFarClip);
    p_m_ProjMatrix->m[3][3] = 1.0;
  }
  else
  {
    v5 = this->m_fHorizontalFOV * 3.141592653589793 * 0.002777777777777778;
    __libm_sse2_tan(x: v8);
    v6 = v5 * (float)(this->m_fNearClip * 2.0);
    *(float *)&v5 = (float)((float)this->m_nViewHeight * v6) / (float)this->m_nViewWidth;
    p_m_ProjMatrix->m[0][0] = (float)(this->m_fNearClip * 2.0) / v6;
    p_m_ProjMatrix->m[1][1] = (float)(this->m_fNearClip * 2.0) / *(float *)&v5;
    p_m_ProjMatrix->m[2][2] = this->m_fFarClip / (float)(this->m_fNearClip - this->m_fFarClip);
    p_m_ProjMatrix->m[2][3] = (float)(this->m_fFarClip * this->m_fNearClip)
                            / (float)(this->m_fNearClip - this->m_fFarClip);
    p_m_ProjMatrix->m[3][2] = -1.0;
  }
  v7 = VMatrix::operator*(this: p_m_ProjMatrix, &result, vm: &this->m_ViewMatrix);
  VMatrix::operator=(this: &this->m_ViewProjMatrix, mOther: v7);
  VMatrix::InverseGeneral(this: &this->m_ViewProjMatrix, vInverse: &this->m_InvViewProjMatrix);
}

//------------------------------------------------------------------------------
// Address: 0x1000A6B0
// Name: public: void CCamera::SetFarClip(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCamera::SetFarClip(CCamera *this, float fFarClip)
{
  if ( this->m_fFarClip != fFarClip )
  {
    this->m_fFarClip = fFarClip;
    CCamera::BuildProjMatrix(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A6E0
// Name: protected: void CCamera::BuildViewMatrix(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CCamera::BuildViewMatrix(CCamera *this)
{
  VMatrix *p_m_ViewMatrix; // esi
  float v3; // xmm1_4
  float v4; // xmm2_4
  const VMatrix *v5; // eax
  const VMatrix *v6; // eax
  float fDegrees[5]; // [esp+0h] [ebp-80h] BYREF
  VMatrix result; // [esp+14h] [ebp-6Ch] BYREF
  _BYTE TempMatrix_8[20]; // [esp+5Ch] [ebp-24h] OVERLAPPED

  p_m_ViewMatrix = &this->m_ViewMatrix;
  *(_QWORD *)&this->m_ViewMatrix.m[0][0] = 1065353216;
  *(_QWORD *)&this->m_ViewMatrix.m[0][2] = 0;
  *(_QWORD *)&this->m_ViewMatrix.m[1][0] = 0;
  *(_QWORD *)&this->m_ViewMatrix.m[1][2] = 1065353216;
  this->m_ViewMatrix.m[2][0] = 0.0;
  *(_QWORD *)&this->m_ViewMatrix.m[2][1] = 3212836864LL;
  this->m_ViewMatrix.m[2][3] = 0.0;
  *(_QWORD *)&this->m_ViewMatrix.m[3][0] = 0;
  this->m_ViewMatrix.m[3][2] = 0.0;
  this->m_ViewMatrix.m[3][3] = 1.0;
  RotateAroundAxis(Matrix: &this->m_ViewMatrix, fDegrees: this->m_fPitch, nAxis: 0);
  RotateAroundAxis(Matrix: p_m_ViewMatrix, fDegrees: this->m_fRoll, nAxis: 1);
  RotateAroundAxis(Matrix: p_m_ViewMatrix, fDegrees: this->m_fYaw, nAxis: 2);
  MatrixSetIdentity(dst: (VMatrix *)&result.m[2][3]);
  v3 = -this->m_ViewPoint.y;
  v4 = -this->m_ViewPoint.z;
  result.m[3][2] = -this->m_ViewPoint.x;
  *(float *)TempMatrix_8 = v3;
  *(float *)&TempMatrix_8[16] = v4;
  v5 = VMatrix::operator*(this: p_m_ViewMatrix, result: (VMatrix *)fDegrees, vm: (VMatrix *)&result.m[2][3]);
  VMatrix::operator=(this: p_m_ViewMatrix, mOther: v5);
  v6 = VMatrix::operator*(this: &this->m_ProjMatrix, result: (VMatrix *)fDegrees, vm: p_m_ViewMatrix);
  VMatrix::operator=(this: &this->m_ViewProjMatrix, mOther: v6);
  VMatrix::InverseGeneral(this: &this->m_ViewProjMatrix, vInverse: &this->m_InvViewProjMatrix);
}

//------------------------------------------------------------------------------
// Address: 0x1000A820
// Name: public: void CCamera::GetViewMatrix(class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCamera::GetViewMatrix(CCamera *this, VMatrix *Matrix)
{
  VMatrix::operator=(this: Matrix, mOther: &this->m_ViewMatrix);
}

//------------------------------------------------------------------------------
// Address: 0x1000A840
// Name: public: void CCamera::GetProjMatrix(class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCamera::GetProjMatrix(CCamera *this, VMatrix *Matrix)
{
  VMatrix::operator=(this: Matrix, mOther: &this->m_ProjMatrix);
}

//------------------------------------------------------------------------------
// Address: 0x1000A860
// Name: public: void CCamera::GetViewProjMatrix(class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCamera::GetViewProjMatrix(CCamera *this, VMatrix *Matrix)
{
  VMatrix::operator=(this: Matrix, mOther: &this->m_ViewProjMatrix);
}

//------------------------------------------------------------------------------
// Address: 0x1000A880
// Name: public: void CCamera::SetZoom(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCamera::SetZoom(CCamera *this, float fScale)
{
  if ( this->m_fZoom != fScale )
  {
    this->m_fZoom = fScale;
    CCamera::BuildProjMatrix(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A8B0
// Name: public: float CCamera::GetZoom(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CCamera::GetZoom(CCamera *this)
{
  return this->m_fZoom;
}

//------------------------------------------------------------------------------
// Address: 0x1000A8C0
// Name: public: void CCamera::WorldToView(class Vector const __near &,class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCamera::WorldToView(CCamera *this, const Vector *vWorld, Vector2D *vView)
{
  float v4; // xmm0_4
  Vector vView3D; // [esp+4h] [ebp-Ch] BYREF

  Vector3DMultiplyPositionProjective(src1: &this->m_ViewProjMatrix, src2: vWorld, dst: &vView3D);
  v4 = (float)(1.0 - vView3D.y) * 0.5;
  vView->x = (float)((float)(vView3D.x + 1.0) * 0.5) * (double)this->m_nViewWidth;
  vView->y = v4 * (double)this->m_nViewHeight;
}

//------------------------------------------------------------------------------
// Address: 0x1000A950
// Name: public: void CCamera::ViewToWorld(class Vector2D const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCamera::ViewToWorld(CCamera *this, const Vector2D *vView, Vector *vWorld)
{
  float v3; // xmm2_4
  float v4; // xmm0_4
  Vector vView3D; // [esp+0h] [ebp-Ch] BYREF

  v3 = (float)(vView->x * 2.0) / (double)this->m_nViewWidth - 1.0;
  vView3D.x = v3;
  v4 = 1.0 - (float)(vView->y * 2.0) / (double)this->m_nViewHeight;
  vView3D.y = v4;
  vView3D.z = 0.0;
  Vector3DMultiplyPositionProjective(src1: &this->m_InvViewProjMatrix, src2: &vView3D, dst: vWorld);
}

//------------------------------------------------------------------------------
// Address: 0x1000A9E0
// Name: public: void CCamera::BuildRay(class Vector2D const __near &,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCamera::BuildRay(CCamera *this, const Vector2D *vView, Vector *vStart, Vector *vEnd)
{
  float v5; // xmm2_4
  float v6; // xmm0_4
  float x; // xmm2_4
  float y; // xmm0_4
  float z; // xmm1_4
  float v10; // xmm3_4
  float v11; // xmm0_4
  Vector vClickPoint; // [esp+0h] [ebp-24h] BYREF
  Vector src2; // [esp+Ch] [ebp-18h] BYREF
  Vector vRay; // [esp+18h] [ebp-Ch] BYREF

  v5 = (float)(vView->x * 2.0) / (double)this->m_nViewWidth - 1.0;
  src2.x = v5;
  v6 = 1.0 - (float)(vView->y * 2.0) / (double)this->m_nViewHeight;
  src2.y = v6;
  src2.z = 0.0;
  Vector3DMultiplyPositionProjective(src1: &this->m_InvViewProjMatrix, &src2, dst: &vClickPoint);
  vRay.x = vClickPoint.x - this->m_ViewPoint.x;
  vRay.y = vClickPoint.y - this->m_ViewPoint.y;
  vRay.z = vClickPoint.z - this->m_ViewPoint.z;
  VectorNormalize(vec: &vRay);
  vStart->x = this->m_ViewPoint.x;
  x = vRay.x;
  y = vRay.y;
  vStart->y = this->m_ViewPoint.y;
  z = this->m_ViewPoint.z;
  v10 = vRay.z;
  vStart->z = z;
  v11 = (float)(y * 99999.0) + vStart->y;
  vEnd->x = vStart->x + (float)(x * 99999.0);
  vEnd->y = v11;
  vEnd->z = z + (float)(v10 * 99999.0);
}

//------------------------------------------------------------------------------
// Address: 0x1000ABE0
// Name: public: void CCamera::SetViewPort(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCamera::SetViewPort(CCamera *this, int width, int height)
{
  if ( this->m_nViewWidth != width || this->m_nViewHeight != height )
  {
    this->m_nViewWidth = width;
    this->m_nViewHeight = height;
    CCamera::BuildProjMatrix(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000AC10
// Name: public: void CCamera::MoveRight(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCamera::MoveRight(CCamera *this, float fUnits)
{
  if ( fUnits != 0.0 )
  {
    this->m_ViewPoint.x = (float)(this->m_ViewMatrix.m[0][0] * fUnits) + this->m_ViewPoint.x;
    this->m_ViewPoint.y = (float)(this->m_ViewMatrix.m[0][1] * fUnits) + this->m_ViewPoint.y;
    this->m_ViewPoint.z = (float)(this->m_ViewMatrix.m[0][2] * fUnits) + this->m_ViewPoint.z;
    CCamera::BuildViewMatrix(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000AC70
// Name: public: void CCamera::MoveUp(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCamera::MoveUp(CCamera *this, float fUnits)
{
  if ( fUnits != 0.0 )
  {
    this->m_ViewPoint.x = (float)(this->m_ViewMatrix.m[1][0] * fUnits) + this->m_ViewPoint.x;
    this->m_ViewPoint.y = (float)(this->m_ViewMatrix.m[1][1] * fUnits) + this->m_ViewPoint.y;
    this->m_ViewPoint.z = (float)(this->m_ViewMatrix.m[1][2] * fUnits) + this->m_ViewPoint.z;
    CCamera::BuildViewMatrix(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000ACD0
// Name: public: void CCamera::MoveForward(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCamera::MoveForward(CCamera *this, float fUnits)
{
  if ( fUnits != 0.0 )
  {
    this->m_ViewPoint.x = this->m_ViewPoint.x - (float)(this->m_ViewMatrix.m[2][0] * fUnits);
    this->m_ViewPoint.y = this->m_ViewPoint.y - (float)(this->m_ViewMatrix.m[2][1] * fUnits);
    this->m_ViewPoint.z = this->m_ViewPoint.z - (float)(this->m_ViewMatrix.m[2][2] * fUnits);
    CCamera::BuildViewMatrix(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000AD40
// Name: public: void CCamera::SetPerspective(float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCamera::SetPerspective(CCamera *this, float fHorizontalFOV, float fNearClip, float fFarClip)
{
  this->m_fHorizontalFOV = fHorizontalFOV;
  this->m_fNearClip = fNearClip;
  this->m_bIsOrthographic = false;
  this->m_fFarClip = fFarClip;
  CCamera::BuildProjMatrix(this);
}

//------------------------------------------------------------------------------
// Address: 0x1000AD80
// Name: public: void CCamera::SetOrthographic(float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCamera::SetOrthographic(CCamera *this, float fZoom, float fNearClip, float fFarClip)
{
  this->m_fZoom = fZoom;
  this->m_fNearClip = fNearClip;
  this->m_fFarClip = fFarClip;
  this->m_bIsOrthographic = true;
  CCamera::BuildProjMatrix(this);
}

//------------------------------------------------------------------------------
// Address: 0x1000ADC0
// Name: public: void CCamera::SetPitch(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCamera::SetPitch(CCamera *this, float fDegrees)
{
  float v2; // xmm1_4

  if ( this->m_fPitch != fDegrees )
  {
    v2 = 90.0;
    this->m_fPitch = fDegrees;
    if ( fDegrees > 90.0 || (v2 = -90.0, fDegrees < -90.0) )
      this->m_fPitch = v2;
    CCamera::BuildViewMatrix(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000AE10
// Name: public: void CCamera::SetRoll(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCamera::SetRoll(CCamera *this, float fDegrees)
{
  float i; // xmm0_4

  for ( i = fDegrees; i >= 360.0; i = i - 360.0 )
    ;
  for ( ; i < 0.0; i = i + 360.0 )
    ;
  if ( this->m_fRoll != i )
  {
    this->m_fRoll = i;
    CCamera::BuildViewMatrix(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000AE60
// Name: public: void CCamera::SetYaw(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCamera::SetYaw(CCamera *this, float fDegrees)
{
  float i; // xmm0_4

  for ( i = fDegrees; i >= 360.0; i = i - 360.0 )
    ;
  for ( ; i < 0.0; i = i + 360.0 )
    ;
  if ( this->m_fYaw != i )
  {
    this->m_fYaw = i;
    CCamera::BuildViewMatrix(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000AEB0
// Name: public: void CCamera::SetViewPoint(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCamera::SetViewPoint(CCamera *this, const Vector *ViewPoint)
{
  if ( ViewPoint->x != this->m_ViewPoint.x || ViewPoint->y != this->m_ViewPoint.y || ViewPoint->z != this->m_ViewPoint.z )
  {
    this->m_ViewPoint = *ViewPoint;
    CCamera::BuildViewMatrix(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000AF00
// Name: public: void CCamera::SetViewTarget(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CCamera::SetViewTarget(CCamera *this@<ecx>, int a2@<esi>, const Vector *ViewTarget)
{
  float y; // xmm0_4
  float x; // xmm3_4
  float z; // xmm2_4
  float v7; // xmm3_4
  float v8; // xmm0_4
  double v9; // xmm0_8
  float i; // xmm0_4
  double v11; // xmm0_8
  float v12; // xmm0_4
  float v13; // xmm1_4
  __int128 v14; // [esp-4h] [ebp-10h] OVERLAPPED BYREF

  y = ViewTarget->y;
  x = ViewTarget->x;
  LODWORD(v14) = a2;
  z = this->m_ViewPoint.z;
  v7 = x - this->m_ViewPoint.x;
  *((float *)&v14 + 2) = y - this->m_ViewPoint.y;
  v8 = ViewTarget->z - z;
  *((float *)&v14 + 1) = v7;
  *((float *)&v14 + 3) = v8;
  VectorNormalize(vec: (Vector *)((char *)&v14 + 4));
  v9 = *((float *)&v14 + 1);
  __libm_sse2_atan2(y: *(long double *)&v14, x: *((long double *)&v14 + 1));
  *(float *)&v9 = v9;
  for ( i = *(float *)&v9 * 57.29578; i >= 360.0; i = i - 360.0 )
    ;
  for ( ; i < 0.0; i = i + 360.0 )
    ;
  if ( this->m_fYaw != i )
  {
    this->m_fYaw = i;
    CCamera::BuildViewMatrix(this);
  }
  v11 = *((float *)&v14 + 3);
  __libm_sse2_asin(x: *(long double *)&v14);
  *(float *)&v11 = v11;
  LODWORD(v12) = COERCE_UNSIGNED_INT(*(float *)&v11 * 57.29578) ^ _mask__NegFloat_;
  if ( this->m_fPitch != v12 )
  {
    v13 = 90.0;
    this->m_fPitch = v12;
    if ( v12 > 90.0 || (v13 = -90.0, v12 < -90.0) )
      this->m_fPitch = v13;
    CCamera::BuildViewMatrix(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B020
// Name: public: void CCamera::Move(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCamera::Move(CCamera *this, Vector *vDelta)
{
  this->m_ViewPoint.x = this->m_ViewPoint.x + vDelta->x;
  this->m_ViewPoint.y = vDelta->y + this->m_ViewPoint.y;
  this->m_ViewPoint.z = vDelta->z + this->m_ViewPoint.z;
  CCamera::BuildViewMatrix(this);
}

//------------------------------------------------------------------------------
// Address: 0x1000B060
// Name: public: void CCamera::Pitch(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCamera::Pitch(CCamera *this, float fDegrees)
{
  float v2; // xmm0_4
  float v3; // xmm1_4

  if ( fDegrees != 0.0 )
  {
    v2 = this->m_fPitch + fDegrees;
    if ( this->m_fPitch != v2 )
    {
      v3 = 90.0;
      this->m_fPitch = v2;
      if ( v2 > 90.0 || (v3 = -90.0, v2 < -90.0) )
        this->m_fPitch = v3;
      CCamera::BuildViewMatrix(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B0C0
// Name: public: void CCamera::Yaw(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCamera::Yaw(CCamera *this, float fDegrees)
{
  float i; // xmm0_4

  if ( fDegrees != 0.0 )
  {
    for ( i = this->m_fYaw + fDegrees; i >= 360.0; i = i - 360.0 )
      ;
    for ( ; i < 0.0; i = i + 360.0 )
      ;
    if ( this->m_fYaw != i )
    {
      this->m_fYaw = i;
      CCamera::BuildViewMatrix(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10370C61
// Name: public: void CDockContext::Move(class CPoint)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDockContext::Move(CDockContext *this, CPoint pt)
{
  int v3; // ebx
  bool v4; // zf
  unsigned int CanDock; // eax
  int dy; // [esp+10h] [ebp-4h]

  v3 = pt.x - this->m_ptLast.x;
  dy = pt.y - this->m_ptLast.y;
  OffsetRect(lprc: &this->m_rectDragHorz, dx: v3, dy);
  OffsetRect(lprc: &this->m_rectFrameDragHorz, dx: v3, dy);
  OffsetRect(lprc: &this->m_rectDragVert, dx: v3, dy);
  OffsetRect(lprc: &this->m_rectFrameDragVert, dx: v3, dy);
  v4 = this->m_bForceFrame == 0;
  this->m_ptLast = pt;
  if ( v4 )
    CanDock = CDockContext::CanDock(this);
  else
    CanDock = 0;
  this->m_dwOverDockStyle = CanDock;
  CDockContext::DrawFocusRect(this, bRemoveRect: 0);
}

//------------------------------------------------------------------------------
// Address: 0x103F8F50
// Name: public: virtual void CPaneDivider::Move(class CPoint __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPaneDivider::Move(CPaneDivider *this, CPoint *ptOffset, int __formal)
{
  HWND Parent; // eax
  CWnd *v5; // eax
  unsigned int v6; // ebx
  HWND v7; // eax
  CWnd *v8; // eax
  unsigned int m_dwDividerStyle; // eax
  bool v10; // zf
  int x; // ebx
  HWND__ *m_hWnd; // [esp-4h] [ebp-2Ch]
  void *hdwp; // [esp+Ch] [ebp-1Ch] BYREF
  CPoint *v14; // [esp+10h] [ebp-18h]
  CRect rectSlider; // [esp+14h] [ebp-14h] BYREF

  m_hWnd = this->m_hWnd;
  v14 = ptOffset;
  Parent = GetParent(hWnd: m_hWnd);
  v5 = CWnd::FromHandle(hWnd: Parent);
  memset(&rectSlider, 0, sizeof(rectSlider));
  v6 = CWnd::GetExStyle(this: v5) & 0x400000;
  GetWindowRect(hWnd: this->m_hWnd, lpRect: &rectSlider);
  v7 = GetParent(hWnd: this->m_hWnd);
  v8 = CWnd::FromHandle(hWnd: v7);
  CWnd::ScreenToClient(this: v8, lpRect: &rectSlider);
  m_dwDividerStyle = this->m_dwDividerStyle;
  if ( (m_dwDividerStyle & 2) != 0 )
  {
    v10 = v6 == 0;
    x = v14->x;
    if ( !v10 )
      x = -x;
    OffsetRect(lprc: &rectSlider, dx: x, dy: 0);
  }
  else
  {
    if ( (m_dwDividerStyle & 1) == 0 )
      return;
    x = v14->y;
    OffsetRect(lprc: &rectSlider, dx: 0, dy: x);
  }
  hdwp = BeginDeferWindowPos(nNumWindows: 50);
  if ( this->m_pContainerManager != nullptr )
    this->m_pContainerManager->OnPaneDividerMove(this: this->m_pContainerManager, a2: this, a3: 0, a4: x, a5: &hdwp);
  EndDeferWindowPos(hWinPosInfo: hdwp);
  this->AdjustDockingLayout(this, a2: nullptr);
  this->SetWindowPos(
    this,
    a2: nullptr,
    a3: rectSlider.left,
    a4: rectSlider.top,
    a5: rectSlider.right - rectSlider.left,
    a6: rectSlider.bottom - rectSlider.top,
    a7: 20u,
    a8: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x103FF4A4
// Name: public: virtual void CPaneContainer::Move(class CPoint)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPaneContainer::Move(CPaneContainer *this, CPoint ptNewLeftTop)
{
  CDockablePane *m_pBarLeftTop; // eax
  CPaneContainer *m_pLeftContainer; // ecx
  int v5; // eax
  CPaneDivider *m_pSlider; // ecx
  int v7; // ebx
  bool v8; // zf
  CPaneDivider_vtbl *v9; // eax
  CDockablePane *m_pBarRightBottom; // ecx
  CPaneContainer *m_pRightContainer; // esi
  int nTopOffset; // [esp+Ch] [ebp-28h]
  CRect rectRight; // [esp+10h] [ebp-24h] BYREF
  CRect rectLeft; // [esp+20h] [ebp-14h] BYREF

  memset(&rectLeft, 0, sizeof(rectLeft));
  SetRectEmpty(lprc: &rectLeft);
  memset(&rectRight, 0, sizeof(rectRight));
  SetRectEmpty(lprc: &rectRight);
  m_pBarLeftTop = this->m_pBarLeftTop;
  if ( m_pBarLeftTop != nullptr )
  {
    GetWindowRect(hWnd: m_pBarLeftTop->m_hWnd, lpRect: &rectLeft);
    this->m_pBarLeftTop->SetWindowPos(
      this: (CBasePane *)this->m_pBarLeftTop,
      a2: nullptr,
      a3: ptNewLeftTop.x,
      a4: ptNewLeftTop.y,
      a5: 0,
      a6: 0,
      a7: 21u,
      a8: nullptr);
  }
  m_pLeftContainer = this->m_pLeftContainer;
  if ( m_pLeftContainer != nullptr )
  {
    m_pLeftContainer->GetWindowRect(this: m_pLeftContainer, a2: &rectLeft, a3: 0);
    ((void (__thiscall *)(CPaneContainer *, int, int))this->m_pLeftContainer->Move)(
      a1: this->m_pLeftContainer,
      a2: ptNewLeftTop.x,
      a3: ptNewLeftTop.y);
  }
  v5 = rectLeft.bottom - rectLeft.top;
  m_pSlider = this->m_pSlider;
  v7 = rectLeft.right - rectLeft.left;
  nTopOffset = rectLeft.bottom - rectLeft.top;
  if ( m_pSlider != nullptr )
  {
    v8 = m_pSlider->IsHorizontal(this: m_pSlider) == 0;
    v9 = this->m_pSlider->__vftable;
    if ( v8 )
    {
      ((void (__stdcall *)(_DWORD, int, int))v9->SetWindowPos)(a1: 0, a2: v7 + ptNewLeftTop.x, a3: ptNewLeftTop.y);
      v7 += this->m_pSlider->m_nWidth;
      nTopOffset = 0;
      v5 = 0;
    }
    else
    {
      ((void (__stdcall *)(_DWORD, int, int))v9->SetWindowPos)(a1: 0, a2: ptNewLeftTop.x, a3: ptNewLeftTop.y);
      nTopOffset = this->m_pSlider->m_nWidth;
      v5 = nTopOffset;
      v7 = 0;
    }
  }
  m_pBarRightBottom = this->m_pBarRightBottom;
  if ( m_pBarRightBottom != nullptr )
  {
    m_pBarRightBottom->SetWindowPos(
      this: &this->m_pBarRightBottom->CPane,
      a2: nullptr,
      a3: v7 + ptNewLeftTop.x,
      a4: v5 + ptNewLeftTop.y,
      a5: 0,
      a6: 0,
      a7: 21u,
      a8: nullptr);
    v5 = nTopOffset;
  }
  m_pRightContainer = this->m_pRightContainer;
  if ( m_pRightContainer != nullptr )
    ((void (__thiscall *)(CPaneContainer *, int, int))m_pRightContainer->Move)(
      a1: m_pRightContainer,
      a2: ptNewLeftTop.x + v7,
      a3: ptNewLeftTop.y + v5);
}

//------------------------------------------------------------------------------
// Address: 0x10411F29
// Name: public: virtual void CDockingPanesRow::Move(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDockingPanesRow::Move(CDockingPanesRow *this, int nOffset)
{
  CObList::CNode *m_pNodeHead; // esi
  CPane *v4; // eax
  CObject *data; // [esp-4h] [ebp-10h]

  m_pNodeHead = this->m_lstControlBars.m_pNodeHead;
  while ( m_pNodeHead != nullptr )
  {
    data = m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    v4 = (CPane *)AfxDynamicDownCast(pClass: &CPane::classCPane, pObject: data);
    if ( v4 != nullptr )
      CPane::MoveByAlignment(this: v4, dwAlignment: this->m_dwRowAlignment, nOffset);
  }
  this->m_nRowOffset += nOffset;
}

//------------------------------------------------------------------------------
// Address: 0x10370CDB
// Name: public: void CDockContext::OnKey(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockContext::OnKey(CDockContext *this, int nChar, int bDown)
{
  if ( nChar == 17 )
    CDockContext::UpdateState(this, pFlag: &this->m_bForceFrame, bNewValue: bDown);
  if ( nChar == 16 )
    CDockContext::UpdateState(this, pFlag: &this->m_bFlip, bNewValue: bDown);
}

//------------------------------------------------------------------------------
// Address: 0x10370D11
// Name: public: void CDockContext::Stretch(class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockContext::Stretch(CDockContext *this, CPoint pt)
{
  int m_nHitTest; // edx
  int v4; // eax
  int v5; // ecx
  unsigned int v6; // edi
  int v7; // eax
  int SystemMetrics; // eax
  int v9; // eax
  CSize size; // [esp+8h] [ebp-3Ch] BYREF
  CRect rect; // [esp+10h] [ebp-34h] BYREF
  CRect rectDesk; // [esp+20h] [ebp-24h] BYREF
  CRect rectTemp; // [esp+30h] [ebp-14h] BYREF

  m_nHitTest = this->m_nHitTest;
  v4 = pt.x - this->m_ptLast.x;
  v5 = pt.y - this->m_ptLast.y;
  v6 = 2;
  if ( m_nHitTest == 10 )
  {
    this->m_rectDragHorz.left += v4;
    goto LABEL_9;
  }
  if ( m_nHitTest == 11 )
  {
    this->m_rectDragHorz.right += v4;
LABEL_9:
    v7 = this->m_rectDragHorz.right - this->m_rectDragHorz.left;
    goto LABEL_10;
  }
  v6 = 34;
  if ( m_nHitTest == 12 )
    this->m_rectDragHorz.top += v5;
  else
    this->m_rectDragHorz.bottom += v5;
  v7 = this->m_rectDragHorz.bottom - this->m_rectDragHorz.top;
LABEL_10:
  if ( v7 < 0 )
    v7 = 0;
  this->m_pBar->CalcDynamicLayout(this: this->m_pBar, result: &size, a3: v7, a4: v6);
  memset(&rectDesk, 0, sizeof(rectDesk));
  rectDesk.left = GetSystemMetrics(nIndex: 76);
  rectDesk.top = GetSystemMetrics(nIndex: 77);
  rectDesk.right = rectDesk.left + GetSystemMetrics(nIndex: 78);
  SystemMetrics = GetSystemMetrics(nIndex: 79);
  rectTemp.left = this->m_rectFrameDragHorz.left;
  rectTemp.top = this->m_rectFrameDragHorz.top;
  rectTemp.right = this->m_rectFrameDragHorz.right;
  rectDesk.bottom = rectDesk.top + SystemMetrics;
  v9 = this->m_nHitTest;
  rectTemp.bottom = this->m_rectFrameDragHorz.bottom;
  if ( v9 == 10 || v9 == 12 )
  {
    rectTemp.left = rectTemp.right + this->m_rectFrameDragVert.left - this->m_rectFrameDragVert.right - size.cx;
    rectTemp.top = rectTemp.bottom + this->m_rectFrameDragVert.top - this->m_rectFrameDragVert.bottom - size.cy;
    memset(&rect, 0, sizeof(rect));
    if ( IntersectRect(lprcDst: &rect, lprcSrc1: &rectDesk, lprcSrc2: &rectTemp) )
    {
      this->m_rectDragVert.left = this->m_rectDragVert.right - size.cx;
      this->m_rectDragVert.top = this->m_rectDragVert.bottom - size.cy;
      this->m_rectFrameDragHorz.left = rectTemp.left;
      this->m_rectFrameDragHorz.top = rectTemp.top;
    }
  }
  else
  {
    rectTemp.right = size.cx + rectTemp.left + this->m_rectFrameDragVert.right - this->m_rectFrameDragVert.left;
    rectTemp.bottom = size.cy + rectTemp.top + this->m_rectFrameDragVert.bottom - this->m_rectFrameDragVert.top;
    memset(&rect, 0, sizeof(rect));
    if ( IntersectRect(lprcDst: &rect, lprcSrc1: &rectDesk, lprcSrc2: &rectTemp) )
    {
      this->m_rectDragVert.right = size.cx + this->m_rectDragVert.left;
      this->m_rectDragVert.bottom = size.cy + this->m_rectDragVert.top;
      this->m_rectFrameDragHorz.right = rectTemp.right;
      this->m_rectFrameDragHorz.bottom = rectTemp.bottom;
    }
  }
  this->m_ptLast = pt;
  CDockContext::DrawFocusRect(this, bRemoveRect: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10370EC5
// Name: public: void CDockContext::CancelLoop(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockContext::CancelLoop(CDockContext *this)
{
  HWND DesktopWindow; // eax
  CWnd *v3; // edi
  CDC *m_pDC; // eax

  CDockContext::DrawFocusRect(this, bRemoveRect: 1);
  ReleaseCapture();
  DesktopWindow = GetDesktopWindow();
  v3 = CWnd::FromHandle(hWnd: DesktopWindow);
  LockWindowUpdate(hWndLock: nullptr);
  m_pDC = this->m_pDC;
  if ( m_pDC != nullptr )
  {
    ReleaseDC(hWnd: v3->m_hWnd, hDC: m_pDC->m_hDC);
    this->m_pDC = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10370F0E
// Name: public: void CDockContext::EndDrag(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockContext::EndDrag(CDockContext *this)
{
  unsigned int m_dwOverDockStyle; // eax
  CDockBar *DockBar; // eax
  CRect *p_m_rectDragVert; // esi
  int *p_top; // esi
  unsigned int DlgCtrlID; // eax
  unsigned int m_dwStyle; // eax
  unsigned int v8; // eax
  int top; // ecx
  CFrameWnd *m_pDockSite; // ecx
  CControlBar *m_pBar; // [esp-10h] [ebp-2Ch]
  CPoint v12; // [esp-Ch] [ebp-28h]
  unsigned int v13; // [esp-4h] [ebp-20h]
  CDockBar *pDockBar; // [esp+4h] [ebp-18h]
  CRect rect; // [esp+8h] [ebp-14h] BYREF

  CDockContext::CancelLoop(this);
  m_dwOverDockStyle = this->m_dwOverDockStyle;
  if ( m_dwOverDockStyle != 0 )
  {
    DockBar = CDockContext::GetDockBar(this, dwOverDockStyle: m_dwOverDockStyle);
    pDockBar = DockBar;
    p_m_rectDragVert = &this->m_rectDragVert;
    if ( (this->m_dwOverDockStyle & 0x5000) == 0 )
      p_m_rectDragVert = &this->m_rectDragHorz;
    rect.left = p_m_rectDragVert->left;
    p_top = &p_m_rectDragVert->top;
    rect.top = *p_top++;
    rect.right = *p_top;
    rect.bottom = p_top[1];
    DlgCtrlID = GetDlgCtrlID(hWnd: DockBar->m_hWnd);
    if ( DlgCtrlID - 59419 <= 3 )
    {
      this->m_uMRUDockID = DlgCtrlID;
      this->m_rectMRUDockPos = rect;
      CWnd::ScreenToClient(this: pDockBar, lpRect: &this->m_rectMRUDockPos);
    }
    CFrameWnd::DockControlBar(this: this->m_pDockSite, pBar: this->m_pBar, pDockBar, lpRect: &rect);
    this->m_pDockSite->RecalcLayout(this: this->m_pDockSite, a2: 1);
  }
  else
  {
    m_dwStyle = this->m_dwStyle;
    if ( (m_dwStyle & 4) != 0
      || (m_dwStyle & 0xA000) != 0 && this->m_bFlip == 0
      || (m_dwStyle & 0x5000) != 0 && this->m_bFlip != 0 )
    {
      v8 = this->m_dwDockStyle & 0x40 | 0x2000;
      this->m_ptMRUFloatPos.x = this->m_rectFrameDragHorz.left;
      top = this->m_rectFrameDragHorz.top;
      v13 = v8;
      v12.y = top;
      v12.x = this->m_rectFrameDragHorz.left;
    }
    else
    {
      v8 = this->m_dwDockStyle & 0x40 | 0x1000;
      this->m_ptMRUFloatPos.x = this->m_rectFrameDragVert.left;
      top = this->m_rectFrameDragVert.top;
      v13 = v8;
      v12.y = top;
      v12.x = this->m_rectFrameDragVert.left;
    }
    m_pBar = this->m_pBar;
    this->m_ptMRUFloatPos.y = top;
    m_pDockSite = this->m_pDockSite;
    this->m_dwMRUFloatStyle = v8;
    CFrameWnd::FloatControlBar(this: m_pDockSite, pBar: m_pBar, point: v12, dwStyle: v13);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10371028
// Name: public: void CDockContext::EndResize(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockContext::EndResize(CDockContext *this)
{
  _BYTE v2[8]; // [esp+4h] [ebp-8h] BYREF

  CDockContext::CancelLoop(this);
  this->m_pBar->CalcDynamicLayout(
    this: this->m_pBar,
    result: (CSize *)v2,
    a3: this->m_rectDragVert.right - this->m_rectDragVert.left,
    a4: 66u);
  CFrameWnd::FloatControlBar(
    this: this->m_pDockSite,
    pBar: this->m_pBar,
    point: *(CPoint *)&this->m_rectFrameDragHorz.left,
    dwStyle: this->m_dwDockStyle & 0x40 | 0x2004);
}

//------------------------------------------------------------------------------
// Address: 0x1037106F
// Name: public: int CDockContext::Track(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDockContext::Track(CDockContext *this)
{
  HWND v2; // eax
  HWND Capture; // eax
  HWND v4; // eax
  tagMSG msg; // [esp+Ch] [ebp-1Ch] BYREF

  if ( GetCapture() != nullptr )
    return 0;
  v2 = SetCapture(hWnd: this->m_pBar->m_hWnd);
  CWnd::FromHandle(hWnd: v2);
  Capture = GetCapture();
  if ( CWnd::FromHandle(hWnd: Capture) != this->m_pBar )
  {
LABEL_19:
    CDockContext::CancelLoop(this);
    return 0;
  }
  while ( 1 )
  {
    if ( !GetMessageA(lpMsg: &msg, hWnd: nullptr, wMsgFilterMin: 0, wMsgFilterMax: 0) )
    {
      AfxPostQuitMessage(nExitCode: msg.wParam);
      goto LABEL_19;
    }
    if ( msg.message != 256 )
      break;
    if ( this->m_bDragging != 0 )
      CDockContext::OnKey(this, nChar: msg.wParam, bDown: 1);
    if ( msg.wParam == 27 )
      goto LABEL_19;
LABEL_18:
    v4 = GetCapture();
    if ( CWnd::FromHandle(hWnd: v4) != this->m_pBar )
      goto LABEL_19;
  }
  if ( msg.message == 257 )
  {
    if ( this->m_bDragging != 0 )
      CDockContext::OnKey(this, nChar: msg.wParam, bDown: 0);
    goto LABEL_18;
  }
  if ( msg.message == 512 )
  {
    if ( this->m_bDragging != 0 )
      CDockContext::Move(this, pt: (CPoint)msg.pt);
    else
      CDockContext::Stretch(this, pt: (CPoint)msg.pt);
    goto LABEL_18;
  }
  if ( msg.message != 514 )
  {
    if ( msg.message == 516 )
      goto LABEL_19;
    DispatchMessageA(lpMsg: &msg);
    goto LABEL_18;
  }
  if ( this->m_bDragging != 0 )
    CDockContext::EndDrag(this);
  else
    CDockContext::EndResize(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1037118C
// Name: public: virtual void CDockContext::StartDrag(class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockContext::StartDrag(CDockContext *this, CPoint pt)
{
  CControlBar *m_pBar; // eax
  unsigned int m_dwStyle; // ecx
  CControlBar *v5; // ecx
  int left; // eax
  int top; // ecx
  int cx; // edx
  int right; // edx
  int v10; // edx
  CRect *v11; // esi
  CRect *p_m_rectFrameDragHorz; // eax
  CControlBar *v13; // ecx
  int v14; // eax
  int v15; // ecx
  CControlBar *v16; // ecx
  unsigned int v17; // edi
  int v18; // ecx
  int v19; // kr00_4
  int v20; // edx
  int v21; // edx
  int v22; // eax
  CRect *p_m_rectDragVert; // edi
  int v24; // ecx
  int v25; // kr04_4
  int v26; // edx
  int v27; // ecx
  int *v28; // edi
  int *p_top; // esi
  CSize sizeVert; // [esp+Ch] [ebp-5Ch] BYREF
  int v31; // [esp+14h] [ebp-54h]
  int v32; // [esp+18h] [ebp-50h]
  CSize sizeHorz; // [esp+1Ch] [ebp-4Ch] BYREF
  int v34; // [esp+24h] [ebp-44h]
  int v35; // [esp+28h] [ebp-40h]
  CSize size; // [esp+2Ch] [ebp-3Ch] BYREF
  int v37; // [esp+34h] [ebp-34h] BYREF
  int v38; // [esp+38h] [ebp-30h]
  int v39; // [esp+3Ch] [ebp-2Ch]
  int cy; // [esp+40h] [ebp-28h]
  tagRECT Rect; // [esp+44h] [ebp-24h] BYREF
  CRect rect; // [esp+54h] [ebp-14h] BYREF

  this->m_bDragging = 1;
  CDockContext::InitLoop(this);
  if ( (CDC::GetLayout(this: this->m_pDC) & 1) != 0 )
    CDC::SetLayout(this: this->m_pDC, dwSetLayout: 0);
  m_pBar = this->m_pBar;
  m_dwStyle = m_pBar->m_dwStyle;
  if ( (m_dwStyle & 4) != 0 )
  {
    memset(&rect, 0, sizeof(rect));
    GetWindowRect(hWnd: m_pBar->m_hWnd, lpRect: &rect);
    v5 = this->m_pBar;
    this->m_ptLast = pt;
    v5->CalcDynamicLayout(this: v5, result: &sizeHorz, a3: 0, a4: 10u);
    this->m_pBar->CalcDynamicLayout(this: this->m_pBar, result: &sizeVert, a3: 0, a4: 16u);
    this->m_pBar->CalcDynamicLayout(this: this->m_pBar, result: (CSize *)&Rect.right, a3: 0, a4: 6u);
    left = rect.left;
    size.cx = rect.left + sizeHorz.cx;
    top = rect.top;
    size.cy = rect.top + sizeHorz.cy;
    cx = sizeVert.cx;
    v35 = rect.top;
    this->m_rectDragHorz.left = rect.left;
    this->m_rectDragHorz.top = v35;
    *(CSize *)&this->m_rectDragHorz.right = size;
    size.cx = left + cx;
    size.cy = top + sizeVert.cy;
    right = Rect.right;
    v34 = left;
    v35 = top;
    this->m_rectDragVert.left = left;
    this->m_rectDragVert.top = v35;
    *(CSize *)&this->m_rectDragVert.right = size;
    v10 = left + right;
    size.cy = top + Rect.bottom;
    cy = top + Rect.bottom;
    v39 = v10;
    v38 = top;
    this->m_rectFrameDragHorz.left = left;
    this->m_rectFrameDragHorz.top = v38;
    this->m_rectFrameDragHorz.right = v39;
    this->m_rectFrameDragHorz.bottom = cy;
    v37 = left;
    v39 = v10;
    v38 = top;
    cy = size.cy;
    v11 = (CRect *)&v37;
    p_m_rectFrameDragHorz = &this->m_rectFrameDragHorz;
LABEL_11:
    this->m_rectFrameDragVert.left = v11->left;
    p_top = &v11->top;
    this->m_rectFrameDragVert.top = *p_top++;
    this->m_rectFrameDragVert.right = *p_top;
    this->m_rectFrameDragVert.bottom = p_top[1];
    CMiniFrameWnd::CalcBorders(lpClientRect: p_m_rectFrameDragHorz, dwStyle: 0xC40000u, dwExStyle: 0);
    goto LABEL_12;
  }
  if ( (m_dwStyle & 2) == 0 )
  {
    memset(&Rect, 0, sizeof(Rect));
    GetWindowRect(hWnd: m_pBar->m_hWnd, lpRect: &Rect);
    v16 = this->m_pBar;
    v17 = this->m_dwStyle & 0xA000;
    this->m_ptLast = pt;
    v16->CalcDynamicLayout(this: v16, result: &size, a3: -1, a4: v17 != 0 ? 16 : 10);
    if ( v17 != 0 )
    {
      v18 = Rect.top;
      v19 = Rect.bottom - Rect.top;
      this->m_rectDragHorz.left = Rect.left;
      this->m_rectDragHorz.top = Rect.top;
      v20 = size.cx;
      this->m_rectDragHorz.right = Rect.right;
      v37 = pt.x - v19 / 2;
      v21 = v37 + v20;
      v22 = v18 + size.cy;
      this->m_rectDragHorz.bottom = Rect.bottom;
      v38 = v18;
      cy = v22;
      p_m_rectDragVert = &this->m_rectDragVert;
    }
    else
    {
      v24 = Rect.left;
      v25 = Rect.right - Rect.left;
      this->m_rectDragVert.left = Rect.left;
      this->m_rectDragVert.top = Rect.top;
      v26 = size.cx;
      this->m_rectDragVert.right = Rect.right;
      v37 = v24;
      v21 = v24 + v26;
      v27 = pt.y - v25 / 2 + size.cy;
      this->m_rectDragVert.bottom = Rect.bottom;
      v38 = pt.y - v25 / 2;
      cy = v27;
      p_m_rectDragVert = &this->m_rectDragHorz;
    }
    v39 = v21;
    p_m_rectDragVert->left = v37;
    v28 = &p_m_rectDragVert->top;
    *v28++ = v38;
    *v28 = v39;
    v28[1] = cy;
    p_m_rectFrameDragHorz = &this->m_rectFrameDragHorz;
    this->m_rectFrameDragHorz.left = this->m_rectDragHorz.left;
    this->m_rectFrameDragHorz.top = this->m_rectDragHorz.top;
    this->m_rectFrameDragHorz.right = this->m_rectDragHorz.right;
    this->m_rectFrameDragHorz.bottom = this->m_rectDragHorz.bottom;
    v11 = &this->m_rectDragVert;
    goto LABEL_11;
  }
  memset(&rect, 0, sizeof(rect));
  GetWindowRect(hWnd: m_pBar->m_hWnd, lpRect: &rect);
  v13 = this->m_pBar;
  this->m_ptLast = pt;
  v13->CalcDynamicLayout(this: v13, result: (CSize *)&Rect.right, a3: -1, a4: 10u);
  this->m_pBar->CalcDynamicLayout(this: this->m_pBar, result: &sizeVert, a3: -1, a4: 16u);
  v14 = rect.left;
  v31 = rect.left;
  sizeHorz.cx = rect.left + Rect.right;
  v15 = rect.top;
  v32 = rect.top;
  sizeHorz.cy = rect.top + Rect.bottom;
  this->m_rectDragHorz.left = rect.left;
  this->m_rectDragHorz.top = v32;
  *(CSize *)&this->m_rectDragHorz.right = sizeHorz;
  this->m_rectFrameDragHorz.left = v31;
  this->m_rectFrameDragHorz.top = v32;
  *(CSize *)&this->m_rectFrameDragHorz.right = sizeHorz;
  v31 = v14;
  sizeHorz.cx = v14 + sizeVert.cx;
  v32 = v15;
  sizeHorz.cy = v15 + sizeVert.cy;
  this->m_rectDragVert.left = v14;
  this->m_rectDragVert.top = v32;
  *(CSize *)&this->m_rectDragVert.right = sizeHorz;
  this->m_rectFrameDragVert.left = v31;
  this->m_rectFrameDragVert.top = v32;
  *(CSize *)&this->m_rectFrameDragVert.right = sizeHorz;
  CMiniFrameWnd::CalcBorders(lpClientRect: &this->m_rectFrameDragHorz, dwStyle: 0xC40000u, dwExStyle: 0);
LABEL_12:
  CMiniFrameWnd::CalcBorders(lpClientRect: &this->m_rectFrameDragVert, dwStyle: 0xC40000u, dwExStyle: 0);
  InflateRect(lprc: &this->m_rectFrameDragHorz, dx: -afxData.cxBorder2, dy: -afxData.cyBorder2);
  InflateRect(lprc: &this->m_rectFrameDragVert, dx: -afxData.cxBorder2, dy: -afxData.cyBorder2);
  _AfxAdjustRectangle(rect: &this->m_rectDragHorz, pt);
  _AfxAdjustRectangle(rect: &this->m_rectDragVert, pt);
  _AfxAdjustRectangle(rect: &this->m_rectFrameDragHorz, pt);
  _AfxAdjustRectangle(rect: &this->m_rectFrameDragVert, pt);
  this->m_dwOverDockStyle = CDockContext::CanDock(this);
  CDockContext::Move(this, pt);
  CDockContext::Track(this);
}

//------------------------------------------------------------------------------
// Address: 0x10371508
// Name: public: virtual void CDockContext::StartResize(int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockContext::StartResize(CDockContext *this, int nHitTest, CPoint pt)
{
  CControlBar *m_pBar; // eax
  CControlBar *v5; // ecx
  int top; // edx
  int left; // eax
  int v8; // ecx
  int v9; // edx
  int v10; // edi
  int v11; // eax
  int v12; // ecx
  CSize size; // [esp+Ch] [ebp-30h] BYREF
  int v14; // [esp+14h] [ebp-28h]
  int v15; // [esp+18h] [ebp-24h]
  int v16; // [esp+1Ch] [ebp-20h]
  int v17; // [esp+20h] [ebp-1Ch]
  int v18; // [esp+24h] [ebp-18h]
  CRect rect; // [esp+28h] [ebp-14h] BYREF

  this->m_bDragging = 0;
  CDockContext::InitLoop(this);
  if ( (CDC::GetLayout(this: this->m_pDC) & 1) != 0 )
    CDC::SetLayout(this: this->m_pDC, dwSetLayout: 0);
  m_pBar = this->m_pBar;
  memset(&rect, 0, sizeof(rect));
  GetWindowRect(hWnd: m_pBar->m_hWnd, lpRect: &rect);
  v5 = this->m_pBar;
  this->m_ptLast = pt;
  this->m_nHitTest = nHitTest;
  v5->CalcDynamicLayout(this: v5, result: &size, a3: 0, a4: 6u);
  top = rect.top;
  left = rect.left;
  v14 = rect.top + size.cy;
  v18 = rect.top + size.cy;
  v16 = rect.top;
  v8 = rect.left + size.cx;
  v17 = rect.left + size.cx;
  this->m_rectDragHorz.left = rect.left;
  this->m_rectDragHorz.top = v16;
  this->m_rectDragHorz.right = v17;
  this->m_rectDragHorz.bottom = v18;
  v18 = v14;
  v17 = v8;
  v16 = top;
  this->m_rectDragVert.left = left;
  this->m_rectDragVert.top = v16;
  this->m_rectDragVert.right = v17;
  this->m_rectDragVert.bottom = v18;
  v15 = left;
  v18 = v14;
  v17 = v8;
  v16 = top;
  this->m_rectFrameDragHorz.left = left;
  this->m_rectFrameDragHorz.top = v16;
  this->m_rectFrameDragHorz.right = v17;
  this->m_rectFrameDragHorz.bottom = v18;
  CMiniFrameWnd::CalcBorders(lpClientRect: &this->m_rectFrameDragHorz, dwStyle: 0xC40000u, dwExStyle: 0);
  InflateRect(lprc: &this->m_rectFrameDragHorz, dx: -afxData.cxBorder2, dy: -afxData.cyBorder2);
  v9 = this->m_rectDragVert.right - this->m_rectDragVert.left;
  v10 = this->m_rectDragVert.bottom - this->m_rectDragVert.top;
  v11 = this->m_rectFrameDragHorz.right - this->m_rectFrameDragHorz.left;
  v12 = this->m_rectFrameDragHorz.bottom - this->m_rectFrameDragHorz.top;
  v15 = 0;
  v16 = 0;
  this->m_dwOverDockStyle = 0;
  v18 = v12 - v10;
  v17 = v11 - v9;
  this->m_rectFrameDragVert.left = v15;
  this->m_rectFrameDragVert.top = v16;
  this->m_rectFrameDragVert.right = v17;
  this->m_rectFrameDragVert.bottom = v18;
  CDockContext::Stretch(this, pt);
  CDockContext::Track(this);
}

//------------------------------------------------------------------------------
// Address: 0x1037166A
// Name: public: virtual CDockContext::~CDockContext(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __thiscall CDockContext::~CDockContext(CDockContext *this)
{
  CControlBar *m_pBar; // eax
  CDockBar *m_pDockBar; // ecx

  this->__vftable = (CDockContext_vtbl *)&CDockContext::`vftable';
  m_pBar = this->m_pBar;
  m_pDockBar = m_pBar->m_pDockBar;
  if ( m_pDockBar != nullptr )
    CDockBar::RemoveControlBar(this: m_pDockBar, pBar: m_pBar, nPosExclude: -1, nAddPlaceHolder: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1037176A
// Name: private: static long CThemeHelper::GetThemePartSizeFail(void __near *,struct HDC__ __near *,int,int,struct tagRECT __near *,enum THEMESIZE,struct tagSIZE __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __cdecl CThemeHelper::GetThemePartSizeFail()
{
  return -2147467259;
}

//------------------------------------------------------------------------------
// Address: 0x10371770
// Name: private: static void __near * CThemeHelper::GetProc(char const __near *,void __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
FARPROC __cdecl CThemeHelper::GetProc(const char *szProc, void *pfnFail)
{
  FARPROC ProcAddress; // eax

  if ( (_S1_37 & 1) == 0 )
  {
    _S1_37 |= 1u;
    hThemeDll = AfxCtxLoadLibraryW(lpLibFileName: L"UxTheme.dll");
  }
  if ( hThemeDll != nullptr )
  {
    ProcAddress = GetProcAddress(hModule: hThemeDll, lpProcName: szProc);
    if ( ProcAddress != nullptr )
      return ProcAddress;
  }
  return (FARPROC)pfnFail;
}

//------------------------------------------------------------------------------
// Address: 0x103717C4
// Name: public: static int CThemeHelper::IsAppThemed(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl CThemeHelper::IsAppThemed()
{
  if ( (_S2_19 & 1) == 0 )
  {
    _S2_19 |= 1u;
    pfnIsAppThemed = CThemeHelper::GetProc(szProc: "IsAppThemed", pfnFail: CMFCMenuBar::AllowShowOnPaneMenu);
  }
  return pfnIsAppThemed();
}

//------------------------------------------------------------------------------
// Address: 0x1037180A
// Name: public: static void __near * CThemeHelper::OpenThemeData(struct HWND__ __near *,wchar_t const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl CThemeHelper::OpenThemeData(HWND__ *hwnd, const wchar_t *pszClassList)
{
  if ( (_S3_11 & 1) == 0 )
  {
    _S3_11 |= 1u;
    pfnOpenThemeData = (void *(__stdcall *)(HWND__ *, const wchar_t *))CThemeHelper::GetProc(
                                                                         szProc: "OpenThemeData",
                                                                         pfnFail: CMFCMenuBar::AllowShowOnPaneMenu);
  }
  return pfnOpenThemeData(a1: hwnd, a2: pszClassList);
}

//------------------------------------------------------------------------------
// Address: 0x10371856
// Name: public: static long CThemeHelper::CloseThemeData(void __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __cdecl CThemeHelper::CloseThemeData(void *hTheme)
{
  if ( (_S4_8 & 1) == 0 )
  {
    _S4_8 |= 1u;
    pfnCloseThemeData = (HRESULT (__stdcall *)(void *))CThemeHelper::GetProc(
                                                         szProc: "CloseThemeData",
                                                         pfnFail: CThemeHelper::GetThemePartSizeFail);
  }
  return pfnCloseThemeData(a1: hTheme);
}

//------------------------------------------------------------------------------
// Address: 0x1037189F
// Name: public: static long CThemeHelper::DrawThemeBackground(void __near *,struct HDC__ __near *,int,int,struct tagRECT const __near *,struct tagRECT const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __cdecl CThemeHelper::DrawThemeBackground(
        void *hTheme,
        HDC__ *hdc,
        int nPartId,
        int nStateId,
        const tagRECT *pRect,
        const tagRECT *pClipRect)
{
  if ( (_S5_7 & 1) == 0 )
  {
    _S5_7 |= 1u;
    pfnDrawThemeBackground = (HRESULT (__stdcall *)(void *, HDC__ *, int, int, const tagRECT *, const tagRECT *))CThemeHelper::GetProc(szProc: "DrawThemeBackground", pfnFail: CThemeHelper::GetThemePartSizeFail);
  }
  return pfnDrawThemeBackground(a1: hTheme, a2: hdc, a3: nPartId, a4: nStateId, a5: pRect, a6: pClipRect);
}

//------------------------------------------------------------------------------
// Address: 0x103718F7
// Name: public: static long CThemeHelper::GetThemePartSize(void __near *,struct HDC__ __near *,int,int,struct tagRECT __near *,enum THEMESIZE,struct tagSIZE __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __cdecl CThemeHelper::GetThemePartSize(
        void *hTheme,
        HDC__ *hdc,
        int nPartId,
        int nStateId,
        tagRECT *pRect,
        THEMESIZE eSize,
        tagSIZE *psz)
{
  if ( (_S6_6 & 1) == 0 )
  {
    _S6_6 |= 1u;
    pfnGetThemePartSize = (HRESULT (__stdcall *)(void *, HDC__ *, int, int, tagRECT *, THEMESIZE, tagSIZE *))CThemeHelper::GetProc(szProc: "GetThemePartSize", pfnFail: CThemeHelper::GetThemePartSizeFail);
  }
  return pfnGetThemePartSize(a1: hTheme, a2: hdc, a3: nPartId, a4: nStateId, a5: pRect, a6: eSize, a7: psz);
}

//------------------------------------------------------------------------------
// Address: 0x10371952
// Name: public: static int CThemeHelper::IsThemeBackgroundPartiallyTransparent(void __near *,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl CThemeHelper::IsThemeBackgroundPartiallyTransparent(void *hTheme, int nPartId, int nStateId)
{
  if ( (_S7_4 & 1) == 0 )
  {
    _S7_4 |= 1u;
    pfnIsThemeBackgroundPartiallyTransparent = (int (__stdcall *)(void *, int, int))CThemeHelper::GetProc(
                                                                                      szProc: "IsThemeBackgroundPartiallyTransparent",
                                                                                      pfnFail: CMFCMenuBar::AllowShowOnPaneMenu);
  }
  return pfnIsThemeBackgroundPartiallyTransparent(a1: hTheme, a2: nPartId, a3: nStateId);
}

//------------------------------------------------------------------------------
// Address: 0x103719A1
// Name: public: static long CThemeHelper::DrawThemeParentBackground(struct HWND__ __near *,struct HDC__ __near *,struct tagRECT __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __cdecl CThemeHelper::DrawThemeParentBackground(HWND__ *hwnd, HDC__ *hdc, tagRECT *prc)
{
  if ( (_S8_3 & 1) == 0 )
  {
    _S8_3 |= 1u;
    pfnDrawThemeParentBackground = (HRESULT (__stdcall *)(HWND__ *, HDC__ *, tagRECT *))CThemeHelper::GetProc(
                                                                                          szProc: "DrawThemeParentBackground",
                                                                                          pfnFail: CThemeHelper::GetThemePartSizeFail);
  }
  return pfnDrawThemeParentBackground(a1: hwnd, a2: hdc, a3: prc);
}

//------------------------------------------------------------------------------
// Address: 0x103719F0
// Name: public: CToolTipCtrl::CToolTipCtrl(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CToolTipCtrl *__thiscall CToolTipCtrl::CToolTipCtrl(CToolTipCtrl *this)
{
  CWnd::CWnd(this);
  this->__vftable = (CToolTipCtrl_vtbl *)&CToolTipCtrl::`vftable';
  CMapStringToPtr::CMapStringToPtr(this: &this->m_mapString, nBlockSize: 10);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10371A22
// Name: public: virtual int CToolTipCtrl::CreateEx(class CWnd __near *,unsigned long,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CToolTipCtrl::CreateEx(
        CToolTipCtrl *this,
        CWnd *pParentWnd,
        unsigned int dwStyle,
        unsigned int dwExStyle)
{
  return this->Create_2(this, a2: pParentWnd, a3: dwStyle) != 0
      && CWnd::ModifyStyleEx(this, dwRemove: 0, dwAdd: dwExStyle, nFlags: 0) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10371A5A
// Name: public: virtual CToolTipCtrl::~CToolTipCtrl(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CToolTipCtrl::~CToolTipCtrl(CToolTipCtrl *this)
{
  this->__vftable = (CToolTipCtrl_vtbl *)&CToolTipCtrl::`vftable';
  CWnd::DestroyWindow(this);
  CMapStringToPtr::~CMapStringToPtr(this: &this->m_mapString);
  CWnd::~CWnd(this);
}

//------------------------------------------------------------------------------
// Address: 0x10371A9A
// Name: public: virtual int CToolTipCtrl::DestroyToolTipCtrl(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CToolTipCtrl::DestroyToolTipCtrl(CToolTipCtrl *this)
{
  this->DestroyWindow(this);
  ((void (__thiscall *)(CToolTipCtrl *, int))this->dtr_CObject)(a1: this, a2: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10371AB2
// Name: public: virtual struct CRuntimeClass __near * CToolTipCtrl::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CToolTipCtrl::GetRuntimeClass(CToolTipCtrl *this)
{
  return &CToolTipCtrl::classCToolTipCtrl;
}

//------------------------------------------------------------------------------
// Address: 0x10371AD9
// Name: public: virtual int CToolTipCtrl::Create(class CWnd __near *,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CToolTipCtrl::Create(CToolTipCtrl *this, CWnd *pParentWnd, unsigned int dwStyle)
{
  HWND__ *v4; // esi
  HWND__ *m_hWnd; // eax
  int result; // eax

  AfxEndDeferRegisterClass(fToRegister: 4096);
  v4 = nullptr;
  if ( pParentWnd != nullptr )
    m_hWnd = pParentWnd->m_hWnd;
  else
    m_hWnd = nullptr;
  result = CWnd::CreateEx(
             this,
             dwExStyle: 0,
             lpszClassName: "tooltips_class32",
             lpszWindowName: nullptr,
             dwStyle: dwStyle | 0x80000000,
             x: 0x80000000,
             y: 0x80000000,
             nWidth: 0x80000000,
             nHeight: 0x80000000,
             hWndParent: m_hWnd,
             nIDorHMenu: nullptr,
             lpParam: nullptr);
  if ( result != 0 )
  {
    if ( pParentWnd != nullptr )
      v4 = pParentWnd->m_hWnd;
    this->m_hWndOwner = v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10371B32
// Name: protected: long CToolTipCtrl::OnAddTool(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CToolTipCtrl::OnAddTool(CToolTipCtrl *this, unsigned int wParam, tagTOOLINFOA *lParam)
{
  void *pv; // [esp+Ch] [ebp-3Ch] BYREF
  const char *lpszText; // [esp+10h] [ebp-38h] BYREF
  tagTOOLINFOA ti; // [esp+14h] [ebp-34h] BYREF

  ti = *lParam;
  if ( ti.hinst == nullptr && ti.lpszText != (char *)-1 && ti.lpszText != nullptr )
  {
    if ( CMapStringToPtr::Lookup(this: &this->m_mapString, key: ti.lpszText, rValue: &pv) == 0 )
      *CMapStringToPtr::operator[](this: &this->m_mapString, key: ti.lpszText) = nullptr;
    lpszText = nullptr;
    CMapStringToPtr::LookupKey(this: &this->m_mapString, key: ti.lpszText, rKey: &lpszText);
    ti.lpszText = (char *)lpszText;
  }
  return this->DefWindowProcA(this, a2: 1028u, a3: wParam, a4: (int)&ti);
}

//------------------------------------------------------------------------------
// Address: 0x10371BC5
// Name: protected: long CToolTipCtrl::OnDisableModal(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CToolTipCtrl::OnDisableModal(CToolTipCtrl *this, unsigned int __formal, unsigned int __formala)
{
  SendMessageA(hWnd: this->m_hWnd, Msg: 0x401u, wParam: 0, lParam: 0);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10371BDC
// Name: protected: void CToolTipCtrl::OnEnable(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CToolTipCtrl::OnEnable(CToolTipCtrl *this, WPARAM bEnable)
{
  SendMessageA(hWnd: this->m_hWnd, Msg: 0x401u, wParam: bEnable, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10371BF8
// Name: protected: long CToolTipCtrl::OnWindowFromPoint(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HWND __thiscall CToolTipCtrl::OnWindowFromPoint(CToolTipCtrl *this, unsigned int __formal, int *lParam)
{
  HWND result; // eax
  HWND__ *v4; // esi
  HWND Parent; // eax
  HWND v6; // edi
  HWND v7; // eax
  HWND v8; // edi
  bool v9; // zf
  POINT v10; // [esp-8h] [ebp-14h]
  CPoint pt; // [esp+4h] [ebp-8h] BYREF

  pt.x = *lParam;
  v10.x = *lParam;
  pt.y = lParam[1];
  v10.y = pt.y;
  result = WindowFromPoint(Point: v10);
  v4 = result;
  if ( result != nullptr )
  {
    Parent = GetParent(hWnd: result);
    v6 = Parent;
    if ( Parent != nullptr && _AfxIsComboBoxControl(hWnd: Parent, nStyle: 2u) != 0 )
    {
      return v6;
    }
    else
    {
      ScreenToClient(hWnd: v4, lpPoint: &pt);
      v7 = _AfxChildWindowFromPoint(hWnd: v4, pt: pt.tagPOINT);
      v8 = v7;
      if ( v7 == nullptr )
        return v4;
      v9 = !IsWindowEnabled(hWnd: v7);
      result = v8;
      if ( !v9 )
        return v4;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10371C6D
// Name: public: void CToolTipCtrl::FillInToolInfo(struct tagTOOLINFOA __near &,class CWnd __near *,unsigned int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CToolTipCtrl::FillInToolInfo(CToolTipCtrl *this, tagTOOLINFOA *ti, CWnd *pWnd, unsigned int nIDTool)
{
  HWND m_hWnd; // edi

  memset(dst: (unsigned __int8 *)ti, value: 0, count: 0x2Cu);
  ti->cbSize = 44;
  if ( pWnd != nullptr )
    m_hWnd = pWnd->m_hWnd;
  else
    m_hWnd = nullptr;
  if ( nIDTool != 0 )
  {
    ti->uFlags = 0;
    ti->hwnd = m_hWnd;
    ti->uId = nIDTool;
  }
  else
  {
    ti->hwnd = GetParent(hWnd: m_hWnd);
    ti->uFlags = 1;
    ti->uId = (unsigned int)m_hWnd;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10371CC3
// Name: void _AfxRelayToolTipMessage(class CToolTipCtrl __near *,struct tagMSG __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall _AfxRelayToolTipMessage(CToolTipCtrl *pToolTip, tagMSG *pMsg)
{
  HWND__ *v2; // eax
  tagMSG msg; // [esp+Ch] [ebp-24h] BYREF
  CPoint pt; // [esp+28h] [ebp-8h] BYREF

  msg = *pMsg;
  v2 = (HWND__ *)SendMessageA(hWnd: pToolTip->m_hWnd, Msg: 0x410u, wParam: 0, lParam: (LPARAM)&msg.pt);
  pt = (CPoint)pMsg->pt;
  msg.hwnd = v2;
  if ( msg.message - 512 <= 9 )
    ScreenToClient(hWnd: v2, lpPoint: &pt);
  LOWORD(msg.lParam) = pt.x;
  HIWORD(msg.lParam) = pt.y;
  SendMessageA(hWnd: pToolTip->m_hWnd, Msg: 0x407u, wParam: 0, lParam: (LPARAM)&msg);
}

//------------------------------------------------------------------------------
// Address: 0x10371D43
// Name: protected: virtual struct AFX_MSGMAP const __near * CToolTipCtrl::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CToolTipCtrl::GetMessageMap(CToolTipCtrl *this)
{
  return &messageMap_28;
}

//------------------------------------------------------------------------------
// Address: 0x103F9068
// Name: public: virtual void CPaneDivider::RemovePane(class CDockablePane __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPaneDivider::RemovePane(CPaneDivider *this, CDockablePane *pBar)
{
  if ( this->m_pContainerManager != nullptr )
  {
    this->m_pContainerManager->RemovePaneFromPaneContainer(this: this->m_pContainerManager, a2: pBar);
    CBasePane::RemovePaneFromDockManager(
      this,
      pBar: &pBar->CPane,
      bDestroy: 0,
      bAdjustLayout: 0,
      bAutoHide: this->m_bAutoHideMode,
      pBarReplacement: nullptr);
    if ( !CPaneContainerManager::IsEmpty(this: this->m_pContainerManager)
      || CPaneContainerManager::GetTotalRefCount(this: this->m_pContainerManager) != 0
      || CRecentDockSiteInfo::GetRecentDefaultPaneDivider(this: &pBar->m_recentDockInfo) == this )
    {
      if ( this->CheckVisibility(this) == 0 )
        CWnd::ShowWindow(this, nCmdShow: 0);
    }
    else
    {
      CBasePane::RemovePaneFromDockManager(
        this,
        pBar: this,
        bDestroy: 1,
        bAdjustLayout: 0,
        bAutoHide: this->m_bAutoHideMode,
        pBarReplacement: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F90FA
// Name: public: virtual class CSize CPaneDivider::CalcFixedLayout(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSize *__thiscall CPaneDivider::CalcFixedLayout(CPaneDivider *this, CSize *result, int __formal, int a4)
{
  int v5; // ecx
  HWND__ *m_hWnd; // [esp-8h] [ebp-38h]
  CRect rectContainer; // [esp+Ch] [ebp-24h] BYREF
  CRect rectWnd; // [esp+1Ch] [ebp-14h] BYREF

  m_hWnd = this->m_hWnd;
  memset(&rectWnd, 0, sizeof(rectWnd));
  GetWindowRect(hWnd: m_hWnd, lpRect: &rectWnd);
  rectContainer.left = 0;
  result->cx = rectWnd.right - rectWnd.left;
  rectContainer.top = 0;
  result->cy = rectWnd.bottom - rectWnd.top;
  rectContainer.right = 0;
  rectContainer.bottom = 0;
  if ( this->m_pContainerManager != nullptr )
  {
    this->m_pContainerManager->GetWindowRect(this: this->m_pContainerManager, a2: &rectContainer);
    v5 = rectContainer.bottom - rectContainer.top;
    result->cx += rectContainer.right - rectContainer.left;
    result->cy += v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103F9189
// Name: protected: int CPaneDivider::OnCreate(struct tagCREATESTRUCTA __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CPaneDivider::OnCreate(CPaneDivider *this, tagCREATESTRUCTA *lpCreateStruct)
{
  int result; // eax
  AFX_MODULE_STATE *ModuleState; // eax
  AFX_MODULE_STATE *v4; // eax

  result = CWnd::Default(this);
  if ( result != -1 )
  {
    if ( afxGlobalData.m_hcurStretch == nullptr )
    {
      AfxGetModuleState();
      ModuleState = AfxGetModuleState();
      afxGlobalData.m_hcurStretch = LoadCursorW(
                                      hInstance: ModuleState->m_hCurrentResourceHandle,
                                      lpCursorName: (LPCWSTR)0x7904);
    }
    if ( afxGlobalData.m_hcurStretchVert == nullptr )
    {
      AfxGetModuleState();
      v4 = AfxGetModuleState();
      afxGlobalData.m_hcurStretchVert = LoadCursorW(
                                          hInstance: v4->m_hCurrentResourceHandle,
                                          lpCursorName: (LPCWSTR)0x7905);
    }
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103F91EA
// Name: public: static class CObject __near * CPaneDivider::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPaneDivider *__stdcall CPaneDivider::CreateObject()
{
  CPaneDivider *v0; // ecx
  CPaneDivider *result; // eax

  v0 = (CPaneDivider *)operator new(nSize: 0x15Cu);
  result = nullptr;
  if ( v0 != nullptr )
    return CPaneDivider::CPaneDivider(this: v0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FF5EF
// Name: public: virtual int CPaneContainer::CalcAvailablePaneSpace(int,class CPane __near *,class CPaneContainer __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CPaneContainer::CalcAvailablePaneSpace(
        CPaneContainer *this,
        int nRequiredOffset,
        CPane *pBar,
        CPaneContainer *pContainer,
        int bLeftBar)
{
  int result; // eax
  int v6; // eax
  int v7; // eax
  int IsPaneDividerHorz; // eax
  CPaneContainer_vtbl *v9; // edx
  _BYTE v10[8]; // [esp+Ch] [ebp-28h] BYREF
  _BYTE v11[4]; // [esp+14h] [ebp-20h] BYREF
  CPaneContainer *v12; // [esp+18h] [ebp-1Ch]
  int v13; // [esp+1Ch] [ebp-18h]
  CRect rectBar; // [esp+20h] [ebp-14h] BYREF

  v12 = this;
  v13 = bLeftBar;
  memset(&rectBar, 0, sizeof(rectBar));
  result = nRequiredOffset;
  if ( pBar != nullptr )
  {
    GetWindowRect(hWnd: pBar->m_hWnd, lpRect: &rectBar);
    if ( CPaneContainer::IsPaneDividerHorz(this: v12) != 0 )
    {
      if ( v13 != 0 )
        rectBar.bottom += nRequiredOffset;
      else
        rectBar.top += nRequiredOffset;
      v6 = ((int (__thiscall *)(CPane *, _BYTE *, int, int, int, int))pBar->CalcAvailableSize)(
             a1: pBar,
             a2: v11,
             a3: rectBar.left,
             a4: rectBar.top,
             a5: rectBar.right,
             a6: rectBar.bottom);
      return *(_DWORD *)(v6 + 4);
    }
    if ( v13 != 0 )
      rectBar.right += nRequiredOffset;
    else
      rectBar.left += nRequiredOffset;
    v7 = ((int (__thiscall *)(CPane *, _BYTE *, int, int, int, int))pBar->CalcAvailableSize)(
           a1: pBar,
           a2: v11,
           a3: rectBar.left,
           a4: rectBar.top,
           a5: rectBar.right,
           a6: rectBar.bottom);
  }
  else
  {
    if ( pContainer == nullptr )
      return result;
    IsPaneDividerHorz = CPaneContainer::IsPaneDividerHorz(this: v12);
    v9 = pContainer->__vftable;
    if ( IsPaneDividerHorz != 0 )
    {
      v6 = ((int (__thiscall *)(CPaneContainer *, _BYTE *, _DWORD, int, int))v9->CalcAvailableSpace)(
             a1: pContainer,
             a2: v11,
             a3: 0,
             a4: nRequiredOffset,
             a5: v13);
      return *(_DWORD *)(v6 + 4);
    }
    v7 = ((int (__thiscall *)(CPaneContainer *, _BYTE *, int, _DWORD, int))v9->CalcAvailableSpace)(
           a1: pContainer,
           a2: v10,
           a3: nRequiredOffset,
           a4: 0,
           a5: v13);
  }
  return *(_DWORD *)v7;
}

//------------------------------------------------------------------------------
// Address: 0x103FF6DC
// Name: public: int CPaneContainer::IsLeftPartEmpty(int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CPaneContainer::IsLeftPartEmpty(CPaneContainer *this, int bCheckVisibility)
{
  CDockablePane *m_pBarLeftTop; // ecx
  CPaneContainer *m_pLeftContainer; // esi
  BOOL result; // eax

  m_pBarLeftTop = this->m_pBarLeftTop;
  result = false;
  if ( m_pBarLeftTop == nullptr
    || bCheckVisibility != 0 && (CWnd::GetStyle(this: &m_pBarLeftTop->CPane) & 0x10000000) == 0 )
  {
    m_pLeftContainer = this->m_pLeftContainer;
    if ( m_pLeftContainer == nullptr
      || CPaneContainer::IsEmpty(this: m_pLeftContainer) != 0
      || bCheckVisibility != 0 && CPaneContainer::IsVisible(this: m_pLeftContainer) == 0 )
    {
      return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FF72B
// Name: public: int CPaneContainer::IsRightPartEmpty(int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CPaneContainer::IsRightPartEmpty(CPaneContainer *this, int bCheckVisibility)
{
  CDockablePane *m_pBarRightBottom; // ecx
  CPaneContainer *m_pRightContainer; // esi
  BOOL result; // eax

  m_pBarRightBottom = this->m_pBarRightBottom;
  result = false;
  if ( m_pBarRightBottom == nullptr
    || bCheckVisibility != 0 && (CWnd::GetStyle(this: &m_pBarRightBottom->CPane) & 0x10000000) == 0 )
  {
    m_pRightContainer = this->m_pRightContainer;
    if ( m_pRightContainer == nullptr
      || CPaneContainer::IsEmpty(this: m_pRightContainer) != 0
      || bCheckVisibility != 0 && CPaneContainer::IsVisible(this: m_pRightContainer) == 0 )
    {
      return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FF77A
// Name: protected: class CDockablePane __near * CPaneContainer::LoadTabbedPane(class CArchive __near &,class CList<unsigned int,unsigned int> __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDockablePane *__thiscall CPaneContainer::LoadTabbedPane(
        CPaneContainer *this,
        CArchive *ar,
        CList<unsigned int,unsigned int> *lstBarIDs)
{
  CDockablePane_vtbl *v4; // esi
  int v5; // eax
  unsigned int dwStyle; // [esp+Ch] [ebp-8h] BYREF
  CDockablePane *pBar; // [esp+10h] [ebp-4h] BYREF

  pBar = nullptr;
  dwStyle = 0;
  CBaseTabbedPane::LoadSiblingPaneIDs(ar, lstBarIDs);
  operator>>(ar, pOb: &pBar);
  CArchive::operator>>(this: ar, dw: &dwStyle);
  v4 = pBar->__vftable;
  v5 = ((int (__thiscall *)(CDockablePane *, int, _DWORD))pBar->GetControlBarStyle)(a1: pBar, a2: 15, a3: 0);
  if ( ((int (__stdcall *)(const char *, CWnd *, CRect *, int, int, unsigned int, int))v4->Create)(
         a1: &var,
         a2: this->m_pContainerManager->m_pDockSite,
         a3: &pBar->m_rectSavedDockedRect,
         a4: 1,
         a5: -1,
         a6: dwStyle,
         a7: v5) != 0 )
  {
    ((void (__thiscall *)(CDockablePane *, CArchive *))pBar->__vftable[1].GetInterfaceMap)(a1: pBar, a2: ar);
    pBar[1].__vftable = (CDockablePane_vtbl *)1;
    return pBar;
  }
  else
  {
    CList<HWND__ *,HWND__ * &>::RemoveAll(this: (CList<HWND__ *,HWND__ * &> *)lstBarIDs);
    if ( pBar != nullptr )
      ((void (__thiscall *)(CDockablePane *, int))pBar->dtr_CObject)(a1: pBar, a2: 1);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103FF822
// Name: public: virtual class CPaneContainer __near * CPaneContainer::Copy(class CPaneContainer __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPaneContainer *__thiscall CPaneContainer::Copy(CPaneContainer *this, CObject_vtbl *pParentContainer)
{
  CRuntimeClass *m_pContainerRTC; // ecx
  CPaneContainer *v4; // eax
  CPaneContainer *v5; // eax
  CObject *Object; // edi
  CDockablePane *m_pBarLeftTop; // ecx
  CDockablePane *m_pBarRightBottom; // ecx
  CPaneContainer *m_pLeftContainer; // ecx
  int v10; // eax
  CPaneContainer *m_pRightContainer; // ecx
  int v12; // eax
  CPaneDivider *m_pSlider; // ecx
  CPaneDivider *v14; // eax

  m_pContainerRTC = this->m_pContainerManager->m_pContainerRTC;
  if ( m_pContainerRTC != nullptr )
  {
    Object = CRuntimeClass::CreateObject(this: m_pContainerRTC);
    Object[7].__vftable = (CObject_vtbl *)this->m_pContainerManager;
    Object[1].__vftable = (CObject_vtbl *)this->m_pBarLeftTop;
    Object[2].__vftable = (CObject_vtbl *)this->m_pBarRightBottom;
    Object[3].__vftable = (CObject_vtbl *)this->m_pSlider;
  }
  else
  {
    v4 = (CPaneContainer *)operator new(nSize: 0x9Cu);
    if ( v4 != nullptr )
      v5 = CPaneContainer::CPaneContainer(
             this: v4,
             pManager: this->m_pContainerManager,
             pLeftBar: this->m_pBarLeftTop,
             pRightBar: this->m_pBarRightBottom,
             pSlider: this->m_pSlider);
    else
      v5 = nullptr;
    Object = v5;
  }
  m_pBarLeftTop = this->m_pBarLeftTop;
  if ( m_pBarLeftTop != nullptr )
  {
    if ( (CWnd::GetStyle(this: &m_pBarLeftTop->CPane) & 0x10000000) != 0 )
      this->m_pBarLeftTop = nullptr;
    else
      Object[1].__vftable = nullptr;
  }
  m_pBarRightBottom = this->m_pBarRightBottom;
  if ( m_pBarRightBottom != nullptr )
  {
    if ( (CWnd::GetStyle(this: &m_pBarRightBottom->CPane) & 0x10000000) != 0 )
      this->m_pBarRightBottom = nullptr;
    else
      Object[2].__vftable = nullptr;
  }
  Object[6].__vftable = pParentContainer;
  m_pLeftContainer = this->m_pLeftContainer;
  if ( m_pLeftContainer != nullptr )
  {
    v10 = (int)m_pLeftContainer->Copy(this: m_pLeftContainer, a2: Object);
    Object[4].__vftable = (CObject_vtbl *)v10;
    if ( v10 != 0 )
      *(_DWORD *)(v10 + 24) = Object;
  }
  m_pRightContainer = this->m_pRightContainer;
  if ( m_pRightContainer != nullptr )
  {
    v12 = (int)m_pRightContainer->Copy(this: m_pRightContainer, a2: Object);
    Object[5].__vftable = (CObject_vtbl *)v12;
    if ( v12 != 0 )
      *(_DWORD *)(v12 + 24) = Object;
  }
  m_pSlider = this->m_pSlider;
  if ( m_pSlider != nullptr )
  {
    if ( (CWnd::GetStyle(this: m_pSlider) & 0x10000000) != 0 )
    {
      v14 = this->m_pSlider;
      this->m_dwRecentSliderStyle = v14->m_dwDividerStyle;
      GetClientRect(hWnd: v14->m_hWnd, lpRect: &this->m_rectRecentSlider);
      this->m_bIsRecentSliderHorz = this->m_pSlider->IsHorizontal(this: this->m_pSlider);
      this->m_pSlider = nullptr;
    }
    else
    {
      Object[3].__vftable = nullptr;
    }
  }
  return (CPaneContainer *)Object;
}

//------------------------------------------------------------------------------
// Address: 0x103FF936
// Name: public: virtual CPaneContainer::~CPaneContainer(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPaneContainer::~CPaneContainer(CPaneContainer *this)
{
  this->__vftable = (CPaneContainer_vtbl *)&CPaneContainer::`vftable';
  CPaneContainer::CleanUp(this);
  this->m_bDisposed = 1;
  this->m_lstSavedSiblingBarIDsRight.__vftable = (CList<unsigned int,unsigned int>_vtbl *)&CList<unsigned int,unsigned int>::`vftable';
  CList<HWND__ *,HWND__ * &>::RemoveAll(this: (CList<HWND__ *,HWND__ * &> *)&this->m_lstSavedSiblingBarIDsRight);
  this->m_lstSavedSiblingBarIDsLeft.__vftable = (CList<unsigned int,unsigned int>_vtbl *)&CList<unsigned int,unsigned int>::`vftable';
  CList<HWND__ *,HWND__ * &>::RemoveAll(this: (CList<HWND__ *,HWND__ * &> *)&this->m_lstSavedSiblingBarIDsLeft);
}

//------------------------------------------------------------------------------
// Address: 0x103FF985
// Name: public: unsigned long CPaneContainer::Release(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CPaneContainer::Release(CPaneContainer *this)
{
  int result; // eax

  result = --this->m_dwRefCount;
  if ( result <= 0 )
  {
    CPaneContainer::FreeReleasedPaneContainer(this);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FF997
// Name: public: virtual void CPaneContainer::DeletePane(class CDockablePane __near *,enum CPaneContainer::BC_FIND_CRITERIA)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPaneContainer::DeletePane(
        CPaneContainer *this,
        CDockablePane *pBar,
        CPaneContainer::BC_FIND_CRITERIA barType)
{
  CPaneContainer_vtbl *v4; // eax
  CDockablePane *m_pBarLeftTop; // ecx
  CPaneContainer *m_pLeftContainer; // ecx
  CWnd *v7; // eax
  CPaneContainer *m_pParentContainer; // edi
  CPaneDivider *m_pSlider; // ecx
  int v10; // eax
  CPaneContainer_vtbl *v11; // esi
  HWND__ *m_hWnd; // [esp-8h] [ebp-48h]
  tagRECT *v13; // [esp+0h] [ebp-40h]
  int v14; // [esp+0h] [ebp-40h]
  BOOL v15; // [esp+4h] [ebp-3Ch]
  _BYTE v16[4]; // [esp+Ch] [ebp-34h] BYREF
  int nExpandParentContainerOffset; // [esp+10h] [ebp-30h]
  CPaneDivider *pParentSlider; // [esp+14h] [ebp-2Ch]
  void *hdwp; // [esp+18h] [ebp-28h] BYREF
  CRect rectBar; // [esp+1Ch] [ebp-24h] BYREF
  CRect rectContainer; // [esp+2Ch] [ebp-14h] BYREF

  v4 = this->__vftable;
  memset(&rectContainer, 0, sizeof(rectContainer));
  v4->GetWindowRect(this, a2: &rectContainer, a3: 0);
  m_hWnd = pBar->m_hWnd;
  memset(&rectBar, 0, sizeof(rectBar));
  GetWindowRect(hWnd: m_hWnd, lpRect: &rectBar);
  if ( this->m_pSlider != nullptr )
    CPaneContainer::IsPaneDividerHorz(this);
  hdwp = BeginDeferWindowPos(nNumWindows: 10);
  if ( barType != BC_FIND_BY_LEFT_BAR )
  {
    if ( barType != BC_FIND_BY_RIGHT_BAR || pBar != this->m_pBarRightBottom )
      goto LABEL_28;
    m_pBarLeftTop = this->m_pBarLeftTop;
    this->m_pBarRightBottom = nullptr;
    if ( m_pBarLeftTop != nullptr )
    {
LABEL_6:
      ((void (__thiscall *)(CDockablePane *, _BYTE *, int, int, int, int, _DWORD, void **))m_pBarLeftTop->MovePane)(
        a1: m_pBarLeftTop,
        a2: v16,
        a3: rectContainer.left,
        a4: rectContainer.top,
        a5: rectContainer.right,
        a6: rectContainer.bottom,
        a7: 0,
        a8: &hdwp);
      goto LABEL_28;
    }
    m_pLeftContainer = this->m_pLeftContainer;
  }
  else
  {
    if ( pBar != this->m_pBarLeftTop )
      goto LABEL_28;
    m_pBarLeftTop = this->m_pBarRightBottom;
    this->m_pBarLeftTop = nullptr;
    if ( m_pBarLeftTop != nullptr )
      goto LABEL_6;
    m_pLeftContainer = this->m_pRightContainer;
  }
  if ( m_pLeftContainer != nullptr && CPaneContainer::IsEmpty(this: m_pLeftContainer) == 0 )
  {
    v7 = (CWnd *)((int (__thiscall *)(CPaneContainerManager *, CRect *))this->m_pContainerManager->GetDockSiteFrameWnd)(
                   a1: this->m_pContainerManager,
                   a2: &rectContainer);
    CWnd::ScreenToClient(this: v7, lpRect: v13);
    ((void (__thiscall *)(CPaneContainer *, int, int, int, int, void **))this->Resize)(
      a1: this,
      a2: rectContainer.left,
      a3: rectContainer.top,
      a4: rectContainer.right,
      a5: rectContainer.bottom,
      a6: &hdwp);
    goto LABEL_28;
  }
  m_pParentContainer = this->m_pParentContainer;
  if ( m_pParentContainer != nullptr )
  {
    do
    {
      if ( CPaneContainer::IsEmpty(this: m_pParentContainer) == 0 )
        break;
      m_pParentContainer = m_pParentContainer->m_pParentContainer;
    }
    while ( m_pParentContainer != nullptr );
    if ( m_pParentContainer != nullptr )
    {
      m_pSlider = m_pParentContainer->m_pSlider;
      pParentSlider = m_pSlider;
      if ( m_pSlider != nullptr )
      {
        if ( m_pSlider->IsHorizontal(this: m_pSlider) != 0 )
          v10 = rectBar.bottom - rectBar.top;
        else
          v10 = rectBar.right - rectBar.left;
        nExpandParentContainerOffset = pParentSlider->m_nWidth + 2 * v10 + 2;
        if ( CPaneContainer::IsLeftPartEmpty(this: m_pParentContainer, bCheckVisibility: 0) )
        {
          v11 = m_pParentContainer->__vftable;
          v15 = ((int (__thiscall *)(CPaneDivider *, _DWORD, int, void **))pParentSlider->IsHorizontal)(
                  a1: pParentSlider,
                  a2: 0,
                  a3: 1,
                  a4: &hdwp) == 0;
          v14 = -nExpandParentContainerOffset;
        }
        else
        {
          if ( !CPaneContainer::IsRightPartEmpty(this: m_pParentContainer, bCheckVisibility: 0) )
            goto LABEL_28;
          v11 = m_pParentContainer->__vftable;
          v15 = ((int (__thiscall *)(CPaneDivider *, int, int, void **))pParentSlider->IsHorizontal)(
                  a1: pParentSlider,
                  a2: 1,
                  a3: 1,
                  a4: &hdwp) == 0;
          v14 = nExpandParentContainerOffset;
        }
        ((void (__thiscall *)(CPaneContainer *, int, BOOL))v11->StretchPaneContainer)(
          a1: m_pParentContainer,
          a2: v14,
          a3: v15);
      }
    }
  }
LABEL_28:
  EndDeferWindowPos(hWinPosInfo: hdwp);
  if ( this->m_pSlider == nullptr )
  {
    this->m_pBarRightBottom = nullptr;
    this->m_pBarLeftTop = nullptr;
    this->m_pRightContainer = nullptr;
    this->m_pLeftContainer = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103FFB7F
// Name: public: void CPaneContainer::CalculateRecentSize(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPaneContainer::CalculateRecentSize(CPaneContainer *this)
{
  CDockablePane *m_pBarLeftTop; // ecx
  CPaneContainer *m_pLeftContainer; // ecx
  CDockablePane *m_pBarRightBottom; // ecx
  CPaneContainer *m_pRightContainer; // ecx
  BOOL v6; // edi
  CDockablePane *v7; // eax
  CPaneContainer *v8; // ecx
  CPaneContainer *v9; // eax
  CDockablePane *v10; // eax
  CPaneContainer *v11; // ecx
  int bottom; // ecx
  CDockablePane *v13; // ecx
  int m_nLastPercent; // ebx
  CPaneContainer *v15; // ecx
  CDockablePane *v16; // ecx
  int m_nRecentPercent; // ecx
  CPaneContainer *v18; // ecx
  bool v19; // zf
  double v20; // st7
  int v21; // eax
  int right; // ecx
  int v23; // edi
  CDockablePane *v24; // ecx
  int v25; // ebx
  CPaneContainer *v26; // ecx
  CDockablePane *v27; // ecx
  CPaneContainer *v28; // ecx
  CDockablePane *v29; // edi
  CPaneContainer *v30; // ecx
  CDockablePane *v31; // edi
  CPaneContainer *v32; // ecx
  CSize sizeMinRight; // [esp+Ch] [ebp-54h] BYREF
  CSize sizeMinLeft; // [esp+14h] [ebp-4Ch] BYREF
  double dLeftPercent; // [esp+1Ch] [ebp-44h]
  int v36; // [esp+24h] [ebp-3Ch]
  int nPercent; // [esp+28h] [ebp-38h]
  CRect rectRight; // [esp+2Ch] [ebp-34h] BYREF
  CRect rectContainer; // [esp+3Ch] [ebp-24h] BYREF
  CRect rectLeft; // [esp+4Ch] [ebp-14h] BYREF

  memset(&rectContainer, 0, sizeof(rectContainer));
  SetRectEmpty(lprc: &rectContainer);
  nPercent = CPaneContainerManager::IsAutoHideMode(this: this->m_pContainerManager);
  this->GetWindowRect(this, a2: &rectContainer, a3: 0);
  memset(&rectLeft, 0, sizeof(rectLeft));
  SetRectEmpty(lprc: &rectLeft);
  memset(&rectRight, 0, sizeof(rectRight));
  SetRectEmpty(lprc: &rectRight);
  m_pBarLeftTop = this->m_pBarLeftTop;
  sizeMinLeft.cx = 0;
  sizeMinLeft.cy = 0;
  sizeMinRight.cx = 0;
  sizeMinRight.cy = 0;
  if ( m_pBarLeftTop != nullptr && ((CWnd::GetStyle(this: &m_pBarLeftTop->CPane) & 0x10000000) != 0 || nPercent != 0) )
  {
    GetWindowRect(hWnd: this->m_pBarLeftTop->m_hWnd, lpRect: &rectLeft);
    this->m_pBarLeftTop->GetMinSize(this: (CPane *)this->m_pBarLeftTop, a2: &sizeMinLeft);
  }
  m_pLeftContainer = this->m_pLeftContainer;
  if ( m_pLeftContainer != nullptr && (CPaneContainer::IsVisible(this: m_pLeftContainer) != 0 || nPercent != 0) )
  {
    this->m_pLeftContainer->GetWindowRect(this: this->m_pLeftContainer, a2: &rectLeft, a3: 0);
    this->m_pLeftContainer->GetMinSize(this: this->m_pLeftContainer, a2: &sizeMinLeft);
  }
  m_pBarRightBottom = this->m_pBarRightBottom;
  if ( m_pBarRightBottom != nullptr
    && ((CWnd::GetStyle(this: &m_pBarRightBottom->CPane) & 0x10000000) != 0 || nPercent != 0) )
  {
    GetWindowRect(hWnd: this->m_pBarRightBottom->m_hWnd, lpRect: &rectRight);
    this->m_pBarRightBottom->GetMinSize(this: (CPane *)this->m_pBarRightBottom, a2: &sizeMinRight);
  }
  m_pRightContainer = this->m_pRightContainer;
  if ( m_pRightContainer != nullptr && (CPaneContainer::IsVisible(this: m_pRightContainer) != 0 || nPercent != 0) )
  {
    this->m_pRightContainer->GetWindowRect(this: this->m_pRightContainer, a2: &rectRight, a3: 0);
    this->m_pRightContainer->GetMinSize(this: this->m_pRightContainer, a2: &sizeMinRight);
  }
  v6 = nPercent == 0;
  if ( !CPaneContainer::IsLeftPartEmpty(this, bCheckVisibility: v6)
    && CPaneContainer::IsRightPartEmpty(this, bCheckVisibility: v6) )
  {
    v7 = this->m_pBarLeftTop;
    if ( v7 != nullptr )
      v7->m_nLastPercent = 100;
    v8 = this->m_pLeftContainer;
    if ( v8 != nullptr )
    {
      CPaneContainer::CalculateRecentSize(this: v8);
      v9 = this->m_pLeftContainer;
LABEL_29:
      v9->m_nRecentPercent = 100;
      return;
    }
    return;
  }
  if ( !CPaneContainer::IsLeftPartEmpty(this, bCheckVisibility: v6)
    || CPaneContainer::IsRightPartEmpty(this, bCheckVisibility: v6) )
  {
    if ( CPaneContainer::IsLeftPartEmpty(this, bCheckVisibility: v6)
      || CPaneContainer::IsRightPartEmpty(this, bCheckVisibility: v6) )
    {
      return;
    }
    if ( this->m_pSlider == nullptr )
      AfxThrowInvalidArgException();
    if ( CPaneContainer::IsPaneDividerHorz(this) != 0 )
    {
      bottom = rectLeft.bottom;
      nPercent = -1;
      v36 = rectContainer.bottom - rectContainer.top;
      if ( rectRight.bottom - rectRight.top + rectLeft.bottom - rectLeft.top <= rectContainer.bottom - rectContainer.top )
        goto LABEL_51;
      nPercent = 50;
      if ( rectLeft.bottom - rectLeft.top == v36 )
      {
        v13 = this->m_pBarRightBottom;
        if ( v13 != nullptr )
        {
          m_nLastPercent = v13->m_nLastPercent;
        }
        else
        {
          v15 = this->m_pRightContainer;
          if ( v15 != nullptr )
            m_nLastPercent = v15->m_nRecentPercent;
          else
            m_nLastPercent = nPercent;
        }
        bottom = rectLeft.top + rectContainer.bottom - m_nLastPercent * v36 / 100 - rectContainer.top;
        nPercent = 100 - m_nLastPercent;
        goto LABEL_50;
      }
      if ( rectRight.bottom - rectRight.top != v36 )
      {
LABEL_51:
        v19 = nPercent == -1;
        HIDWORD(dLeftPercent) = bottom - rectLeft.top;
        v20 = (double)(bottom - rectLeft.top) / (double)v36;
LABEL_68:
        dLeftPercent = v20 * 100.0;
        if ( !v19 )
          dLeftPercent = (double)nPercent;
        v29 = this->m_pBarLeftTop;
        if ( v29 != nullptr )
          v29->m_nLastPercent = (int)dLeftPercent;
        v30 = this->m_pLeftContainer;
        if ( v30 != nullptr )
        {
          CPaneContainer::CalculateRecentSize(this: v30);
          this->m_pLeftContainer->m_nRecentPercent = (int)dLeftPercent;
        }
        v31 = this->m_pBarRightBottom;
        if ( v31 != nullptr )
          v31->m_nLastPercent = 100 - (int)dLeftPercent;
        v32 = this->m_pRightContainer;
        if ( v32 != nullptr )
        {
          CPaneContainer::CalculateRecentSize(this: v32);
          this->m_pRightContainer->m_nRecentPercent = 100 - (int)dLeftPercent;
        }
        return;
      }
      v16 = this->m_pBarLeftTop;
      if ( v16 != nullptr )
      {
        m_nRecentPercent = v16->m_nLastPercent;
      }
      else
      {
        v18 = this->m_pLeftContainer;
        if ( v18 == nullptr )
        {
LABEL_49:
          bottom = rectLeft.top + nPercent * v36 / 100;
LABEL_50:
          rectLeft.bottom = bottom;
          goto LABEL_51;
        }
        m_nRecentPercent = v18->m_nRecentPercent;
      }
      nPercent = m_nRecentPercent;
      goto LABEL_49;
    }
    v21 = rectContainer.right - rectContainer.left;
    right = rectLeft.right;
    v23 = -1;
    nPercent = -1;
    v36 = rectContainer.right - rectContainer.left;
    if ( rectLeft.right + rectRight.right - rectRight.left - rectLeft.left <= rectContainer.right - rectContainer.left )
      goto LABEL_67;
    if ( rectLeft.right - rectLeft.left == v21 )
    {
      v24 = this->m_pBarRightBottom;
      v25 = 50;
      if ( v24 != nullptr )
      {
        v25 = v24->m_nLastPercent;
      }
      else
      {
        v26 = this->m_pRightContainer;
        if ( v26 != nullptr )
          v25 = v26->m_nRecentPercent;
      }
      right = rectLeft.left + rectContainer.right - v25 * v21 / 100 - rectContainer.left;
      v23 = 100 - v25;
      nPercent = 100 - v25;
      goto LABEL_66;
    }
    if ( rectRight.right - rectRight.left != v21 )
    {
LABEL_67:
      v19 = v23 == -1;
      HIDWORD(dLeftPercent) = right - rectLeft.left;
      v20 = (double)(right - rectLeft.left) / (double)v36;
      goto LABEL_68;
    }
    v27 = this->m_pBarLeftTop;
    v23 = 50;
    nPercent = 50;
    if ( v27 != nullptr )
    {
      v23 = v27->m_nLastPercent;
    }
    else
    {
      v28 = this->m_pLeftContainer;
      if ( v28 == nullptr )
      {
LABEL_65:
        right = rectLeft.left + v23 * v21 / 100;
LABEL_66:
        rectLeft.right = right;
        goto LABEL_67;
      }
      v23 = v28->m_nRecentPercent;
    }
    nPercent = v23;
    goto LABEL_65;
  }
  v10 = this->m_pBarRightBottom;
  if ( v10 != nullptr )
    v10->m_nLastPercent = 100;
  v11 = this->m_pRightContainer;
  if ( v11 != nullptr )
  {
    CPaneContainer::CalculateRecentSize(this: v11);
    v9 = this->m_pRightContainer;
    goto LABEL_29;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103FFF72
// Name: public: virtual void CPaneContainer::Resize(class CRect,void __near * __near &,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPaneContainer::Resize(CPaneContainer *this, CRect rect, void **hdwp, int bRedraw)
{
  int IsAutoHideMode; // eax
  CPaneDivider *m_pSlider; // ecx
  CDockablePane *m_pBarLeftTop; // ecx
  CPaneContainer *m_pLeftContainer; // ecx
  CDockablePane *m_pBarRightBottom; // ecx
  CPaneContainer *m_pRightContainer; // ecx
  BOOL v11; // esi
  CDockablePane *v12; // ecx
  void **v13; // esi
  CPaneContainer *v14; // ebx
  CDockablePane *v15; // ecx
  void **v16; // esi
  int bottom; // ecx
  int v18; // esi
  int m_nLastPercent; // edi
  int v20; // eax
  CDockablePane *v21; // ecx
  CPaneContainer *v22; // ecx
  CDockablePane *v23; // ecx
  CPaneContainer *v24; // ecx
  double v25; // st7
  int v26; // ecx
  double v27; // st5
  double v28; // st6
  int top; // eax
  CPaneDivider *v30; // esi
  int v31; // ecx
  int m_nWidth; // esi
  int v33; // ecx
  HWND Capture; // eax
  CWnd *v35; // eax
  CPaneDivider *v36; // ecx
  HWND Parent; // eax
  CWnd *v38; // eax
  int right; // ecx
  int v40; // edi
  int v41; // esi
  int v42; // eax
  CDockablePane *v43; // edx
  int m_nRecentPercent; // ecx
  CPaneContainer *v45; // edx
  CDockablePane *v46; // ecx
  int v47; // ecx
  CPaneContainer *v48; // ecx
  int v49; // edx
  double v50; // st7
  int v51; // ecx
  double v52; // st5
  double v53; // st6
  int v54; // edi
  int left; // eax
  CPaneDivider *v56; // ecx
  int v57; // ecx
  int v58; // ecx
  int v59; // esi
  HWND v60; // eax
  CWnd *v61; // eax
  CPaneDivider *v62; // ecx
  HWND v63; // eax
  CWnd *v64; // eax
  int v65; // ecx
  CDockablePane *v66; // ecx
  void **v67; // esi
  int v68; // eax
  double v69; // st7
  CPaneContainer *v70; // ecx
  CDockablePane *v71; // ecx
  int v72; // eax
  double v73; // st7
  CPaneContainer *v74; // ecx
  CSize sizeMinRight; // [esp+Ch] [ebp-A8h] BYREF
  CSize sizeMinLeft; // [esp+14h] [ebp-A0h] BYREF
  int nDelta; // [esp+1Ch] [ebp-98h]
  int v78; // [esp+20h] [ebp-94h]
  void **v79; // [esp+24h] [ebp-90h]
  int v80; // [esp+28h] [ebp-8Ch]
  int nPercent; // [esp+2Ch] [ebp-88h]
  CRect rectSlider; // [esp+30h] [ebp-84h] BYREF
  CRect rectFinalSlider; // [esp+40h] [ebp-74h] BYREF
  CRect rectRight; // [esp+50h] [ebp-64h] BYREF
  CRect rectFinalRight; // [esp+60h] [ebp-54h] BYREF
  CRect rectContainer; // [esp+70h] [ebp-44h] BYREF
  tagRECT Rect; // [esp+80h] [ebp-34h] BYREF
  CRect rectLeft; // [esp+90h] [ebp-24h] BYREF
  CRect rectFinalLeft; // [esp+A0h] [ebp-14h] BYREF

  v79 = hdwp;
  v78 = bRedraw;
  memset(&rectContainer, 0, sizeof(rectContainer));
  SetRectEmpty(lprc: &rectContainer);
  memset(&rectSlider, 0, sizeof(rectSlider));
  SetRectEmpty(lprc: &rectSlider);
  IsAutoHideMode = CPaneContainerManager::IsAutoHideMode(this: this->m_pContainerManager);
  m_pSlider = this->m_pSlider;
  nPercent = IsAutoHideMode;
  if ( m_pSlider != nullptr && ((CWnd::GetStyle(this: m_pSlider) & 0x10000000) != 0 || nPercent != 0) )
    GetWindowRect(hWnd: this->m_pSlider->m_hWnd, lpRect: &rectSlider);
  this->GetWindowRect(this, a2: &rectContainer, a3: 0);
  memset(&rectLeft, 0, sizeof(rectLeft));
  SetRectEmpty(lprc: &rectLeft);
  memset(&rectRight, 0, sizeof(rectRight));
  SetRectEmpty(lprc: &rectRight);
  m_pBarLeftTop = this->m_pBarLeftTop;
  sizeMinLeft.cx = 0;
  sizeMinLeft.cy = 0;
  sizeMinRight.cx = 0;
  sizeMinRight.cy = 0;
  if ( m_pBarLeftTop != nullptr && ((CWnd::GetStyle(this: &m_pBarLeftTop->CPane) & 0x10000000) != 0 || nPercent != 0) )
  {
    GetWindowRect(hWnd: this->m_pBarLeftTop->m_hWnd, lpRect: &rectLeft);
    this->m_pBarLeftTop->GetMinSize(this: (CPane *)this->m_pBarLeftTop, a2: &sizeMinLeft);
  }
  m_pLeftContainer = this->m_pLeftContainer;
  if ( m_pLeftContainer != nullptr && (CPaneContainer::IsVisible(this: m_pLeftContainer) != 0 || nPercent != 0) )
  {
    this->m_pLeftContainer->GetWindowRect(this: this->m_pLeftContainer, a2: &rectLeft, a3: 0);
    this->m_pLeftContainer->GetMinSize(this: this->m_pLeftContainer, a2: &sizeMinLeft);
  }
  m_pBarRightBottom = this->m_pBarRightBottom;
  if ( m_pBarRightBottom != nullptr
    && ((CWnd::GetStyle(this: &m_pBarRightBottom->CPane) & 0x10000000) != 0 || nPercent != 0) )
  {
    GetWindowRect(hWnd: this->m_pBarRightBottom->m_hWnd, lpRect: &rectRight);
    this->m_pBarRightBottom->GetMinSize(this: (CPane *)this->m_pBarRightBottom, a2: &sizeMinRight);
  }
  m_pRightContainer = this->m_pRightContainer;
  if ( m_pRightContainer != nullptr && (CPaneContainer::IsVisible(this: m_pRightContainer) != 0 || nPercent != 0) )
  {
    this->m_pRightContainer->GetWindowRect(this: this->m_pRightContainer, a2: &rectRight, a3: 0);
    this->m_pRightContainer->GetMinSize(this: this->m_pRightContainer, a2: &sizeMinRight);
  }
  v11 = nPercent == 0;
  if ( !CPaneContainer::IsLeftPartEmpty(this, bCheckVisibility: v11)
    && CPaneContainer::IsRightPartEmpty(this, bCheckVisibility: v11) )
  {
    v12 = this->m_pBarLeftTop;
    if ( v12 != nullptr )
    {
      if ( rect.right - rect.left < sizeMinLeft.cx && CPane::m_bHandleMinSize != 0 )
        rect.right = sizeMinLeft.cx + rect.left;
      if ( rect.bottom - rect.top < sizeMinLeft.cy && CPane::m_bHandleMinSize != 0 )
        rect.bottom = sizeMinLeft.cy + rect.top;
      v13 = v79;
      *v13 = v12->MoveWindow(this: &v12->CPane, a2: &rect, a3: v78, a4: *v79);
    }
    v14 = this->m_pLeftContainer;
LABEL_43:
    if ( v14 != nullptr )
      ((void (__thiscall *)(CPaneContainer *, int, int, int, int, void **, int))v14->Resize)(
        a1: v14,
        a2: rect.left,
        a3: rect.top,
        a4: rect.right,
        a5: rect.bottom,
        a6: v79,
        a7: v78);
    return;
  }
  if ( CPaneContainer::IsLeftPartEmpty(this, bCheckVisibility: v11)
    && !CPaneContainer::IsRightPartEmpty(this, bCheckVisibility: v11) )
  {
    v15 = this->m_pBarRightBottom;
    if ( v15 != nullptr )
    {
      if ( rect.right - rect.left < sizeMinRight.cx && CPane::m_bHandleMinSize != 0 )
        rect.right = rect.left + sizeMinRight.cx;
      if ( rect.bottom - rect.top < sizeMinRight.cy && CPane::m_bHandleMinSize != 0 )
        rect.bottom = rect.top + sizeMinRight.cy;
      v16 = v79;
      *v16 = v15->MoveWindow(this: &v15->CPane, a2: &rect, a3: v78, a4: *v79);
    }
    v14 = this->m_pRightContainer;
    goto LABEL_43;
  }
  if ( !CPaneContainer::IsLeftPartEmpty(this, bCheckVisibility: v11)
    && !CPaneContainer::IsRightPartEmpty(this, bCheckVisibility: v11) )
  {
    rectFinalLeft = rect;
    rectFinalRight = rect;
    rectFinalSlider = rect;
    if ( this->m_pSlider == nullptr )
      AfxThrowInvalidArgException();
    if ( CPaneContainer::IsPaneDividerHorz(this) != 0 )
    {
      bottom = rectRight.bottom;
      v18 = rectLeft.bottom;
      m_nLastPercent = -1;
      nPercent = -1;
      if ( rectLeft.bottom + rectRight.bottom - rectRight.top - rectLeft.top <= rectContainer.bottom - rectContainer.top )
      {
        if ( !IsRectEmpty(lprc: &rectLeft) && !IsRectEmpty(lprc: &rectRight) )
        {
          v18 = rectLeft.bottom;
          goto LABEL_73;
        }
        v18 = rectLeft.bottom;
        bottom = rectRight.bottom;
      }
      v20 = rectContainer.bottom - rectContainer.top;
      m_nLastPercent = 50;
      nPercent = 50;
      if ( v18 - rectLeft.top == rectContainer.bottom - rectContainer.top )
      {
        v21 = this->m_pBarRightBottom;
        if ( v21 != nullptr )
        {
          m_nLastPercent = v21->m_nLastPercent;
        }
        else
        {
          v22 = this->m_pRightContainer;
          if ( v22 == nullptr )
          {
LABEL_62:
            v18 = rectLeft.top + rectContainer.bottom - m_nLastPercent * v20 / 100 - rectContainer.top;
            m_nLastPercent = 100 - m_nLastPercent;
            rectLeft.bottom = v18;
            nPercent = m_nLastPercent;
LABEL_73:
            v25 = (double)(rectContainer.bottom - rectContainer.top);
            v80 = v18 - rectLeft.top;
            v26 = rect.bottom + rectContainer.top - rectContainer.bottom - rect.top;
            nDelta = v26;
            v27 = (double)(v18 - rectLeft.top) / v25 * 100.0;
            v28 = 100.0;
            *(double *)&Rect.right = v27;
            if ( 100.0 == v27 || 0.0 == v27 )
            {
              v27 = 50.0;
              *(double *)&Rect.right = 50.0;
            }
            if ( CPaneContainer::m_bMaintainPercentage != 0 )
            {
              if ( v26 == 0 )
                goto LABEL_78;
            }
            else
            {
              if ( CPaneContainer::m_bRetainInternalSliderPosition != 0 )
              {
                rectFinalLeft.bottom = v18 + rectFinalLeft.top - rectLeft.top;
                Capture = GetCapture();
                v35 = CWnd::FromHandle(hWnd: Capture);
                v36 = this->m_pSlider;
                if ( v35 == v36 )
                {
                  top = rectFinalLeft.bottom;
                }
                else
                {
                  Rect = rectSlider.tagRECT;
                  Parent = GetParent(hWnd: v36->m_hWnd);
                  v38 = CWnd::FromHandle(hWnd: Parent);
                  CWnd::ScreenToClient(this: v38, lpRect: &Rect);
                  top = Rect.top;
                  rectFinalLeft.bottom = Rect.top;
                }
                v25 = (double)(rectContainer.bottom - rectContainer.top);
                v80 = top - rectFinalLeft.top;
                *(double *)&Rect.right = (double)(top - rectFinalLeft.top) / v25;
                v28 = 100.0;
                goto LABEL_80;
              }
              if ( v26 <= 0 )
              {
                if ( v26 >= 0 )
                {
LABEL_78:
                  top = v18 + rectFinalLeft.top - rectLeft.top;
                  rectFinalLeft.bottom = top;
                  if ( m_nLastPercent != -1 )
                    *(double *)&Rect.right = (double)nPercent;
LABEL_80:
                  v30 = this->m_pSlider;
                  rectFinalSlider.top = top;
                  v31 = top + v30->m_nWidth;
                  rectFinalSlider.bottom = v31;
                  rectFinalRight.top = v31;
                  if ( CPane::m_bHandleMinSize != 0 )
                  {
                    m_nWidth = v30->m_nWidth;
                    v33 = sizeMinRight.cy + v31 - rectFinalRight.bottom;
                    if ( sizeMinLeft.cy + rectFinalLeft.top - top > 0 )
                    {
                      if ( v33 <= 0 )
                      {
                        top = sizeMinLeft.cy + rectFinalLeft.top;
                        rectFinalLeft.bottom = sizeMinLeft.cy + rectFinalLeft.top;
                        rectFinalRight.top = m_nWidth + sizeMinLeft.cy + rectFinalLeft.top;
                        if ( rectFinalRight.bottom - rectFinalRight.top < sizeMinRight.cy )
                          rectFinalRight.bottom = sizeMinRight.cy + m_nWidth + sizeMinLeft.cy + rectFinalLeft.top;
                        goto LABEL_100;
                      }
                      top = rectFinalLeft.top + sizeMinLeft.cy;
                    }
                    else
                    {
                      if ( v33 <= 0 )
                        goto LABEL_100;
                      top -= v33;
                      rectFinalLeft.bottom = top;
                      if ( top - rectFinalLeft.top >= sizeMinLeft.cy )
                      {
LABEL_99:
                        rectFinalRight.top = m_nWidth + top;
                        rectFinalRight.bottom = sizeMinRight.cy + m_nWidth + top;
LABEL_100:
                        rectFinalSlider.top = top;
                        v80 = top - rectFinalLeft.top;
                        rectFinalSlider.bottom = top + m_nWidth;
                        *(double *)&Rect.right = (double)(top - rectFinalLeft.top) / v25 * v28;
                        if ( rectFinalLeft.right - rectFinalLeft.left < sizeMinLeft.cx )
                        {
                          rectFinalLeft.right = sizeMinLeft.cx + rectFinalLeft.left;
                          rectFinalRight.right = sizeMinLeft.cx + rectFinalRight.left;
                        }
                        goto LABEL_155;
                      }
                      top = sizeMinLeft.cy + rectFinalLeft.top;
                    }
                    rectFinalLeft.bottom = top;
                    goto LABEL_99;
                  }
LABEL_155:
                  v66 = this->m_pBarLeftTop;
                  v67 = v79;
                  if ( v66 != nullptr )
                  {
                    v68 = (int)v66->MoveWindow(this: &v66->CPane, a2: &rectFinalLeft, a3: v78, a4: *v79);
                    v69 = *(double *)&Rect.right;
                    *v67 = (void *)v68;
                    this->m_pBarLeftTop->m_nLastPercent = (int)v69;
                  }
                  v70 = this->m_pLeftContainer;
                  if ( v70 != nullptr )
                  {
                    ((void (__thiscall *)(CPaneContainer *, int, int, int, int, void **, int))v70->Resize)(
                      a1: v70,
                      a2: rectFinalLeft.left,
                      a3: rectFinalLeft.top,
                      a4: rectFinalLeft.right,
                      a5: rectFinalLeft.bottom,
                      a6: v79,
                      a7: v78);
                    v67 = v79;
                    this->m_pLeftContainer->m_nRecentPercent = (int)*(double *)&Rect.right;
                  }
                  v71 = this->m_pBarRightBottom;
                  if ( v71 != nullptr )
                  {
                    v72 = (int)v71->MoveWindow(this: &v71->CPane, a2: &rectFinalRight, a3: v78, a4: *v67);
                    v73 = *(double *)&Rect.right;
                    *v67 = (void *)v72;
                    this->m_pBarRightBottom->m_nLastPercent = 100 - (int)v73;
                  }
                  v74 = this->m_pRightContainer;
                  if ( v74 != nullptr )
                  {
                    ((void (__thiscall *)(CPaneContainer *, int, int, int, int, void **, int))v74->Resize)(
                      a1: v74,
                      a2: rectFinalRight.left,
                      a3: rectFinalRight.top,
                      a4: rectFinalRight.right,
                      a5: rectFinalRight.bottom,
                      a6: v79,
                      a7: v78);
                    v67 = v79;
                    this->m_pRightContainer->m_nRecentPercent = 100 - (int)*(double *)&Rect.right;
                  }
                  if ( (CWnd::GetStyle(this: this->m_pSlider) & 0x10000000) != 0 )
                    *v67 = this->m_pSlider->MoveWindow(this: this->m_pSlider, a2: &rectFinalSlider, a3: v78, a4: *v67);
                  return;
                }
              }
              else
              {
                v27 = 100.0 - v27;
              }
            }
            top = v18 + rectFinalLeft.top - (int)(v27 * (double)nDelta / -100.0) - rectLeft.top;
            rectFinalLeft.bottom = top;
            goto LABEL_80;
          }
          m_nLastPercent = v22->m_nRecentPercent;
        }
        if ( m_nLastPercent == 100 || m_nLastPercent == 0 )
          m_nLastPercent = 50;
        goto LABEL_62;
      }
      if ( bottom - rectRight.top != v20 )
        goto LABEL_73;
      v23 = this->m_pBarLeftTop;
      if ( v23 != nullptr )
      {
        m_nLastPercent = v23->m_nLastPercent;
      }
      else
      {
        v24 = this->m_pLeftContainer;
        if ( v24 == nullptr )
        {
LABEL_71:
          v18 = rectLeft.top + m_nLastPercent * v20 / 100;
          rectLeft.bottom = v18;
          goto LABEL_73;
        }
        m_nLastPercent = v24->m_nRecentPercent;
      }
      nPercent = m_nLastPercent;
      if ( m_nLastPercent == 100 || m_nLastPercent == 0 )
      {
        m_nLastPercent = 50;
        nPercent = 50;
      }
      goto LABEL_71;
    }
    right = rectRight.right;
    v40 = rectContainer.right;
    v41 = rectLeft.right;
    nPercent = -1;
    if ( rectLeft.right + rectRight.right - rectRight.left - rectLeft.left <= rectContainer.right - rectContainer.left )
    {
      if ( !IsRectEmpty(lprc: &rectLeft) && !IsRectEmpty(lprc: &rectRight) )
      {
        v40 = rectContainer.right;
        v41 = rectLeft.right;
        goto LABEL_125;
      }
      v40 = rectContainer.right;
      v41 = rectLeft.right;
      right = rectRight.right;
    }
    v42 = v40 - rectContainer.left;
    if ( v41 - rectLeft.left == v40 - rectContainer.left )
    {
      v43 = this->m_pBarRightBottom;
      m_nRecentPercent = 50;
      if ( v43 != nullptr )
      {
        m_nRecentPercent = v43->m_nLastPercent;
      }
      else
      {
        v45 = this->m_pRightContainer;
        if ( v45 == nullptr )
        {
LABEL_114:
          v41 = rectLeft.left + v40 - m_nRecentPercent * v42 / 100 - rectContainer.left;
          rectLeft.right = v41;
          nPercent = 100 - m_nRecentPercent;
LABEL_125:
          v49 = v41 - rectLeft.left;
          v80 = v40 - rectContainer.left;
          v50 = (double)(v40 - rectContainer.left);
          v51 = rect.right + rectContainer.left - v40 - rect.left;
          nDelta = v51;
          v52 = (double)(v41 - rectLeft.left) / v50 * 100.0;
          v53 = 100.0;
          *(double *)&Rect.right = v52;
          if ( 100.0 == v52 || 0.0 == v52 )
          {
            v52 = 50.0;
            *(double *)&Rect.right = 50.0;
          }
          if ( CPaneContainer::m_bMaintainPercentage != 0 )
          {
            if ( v51 == 0 )
              goto LABEL_130;
          }
          else
          {
            if ( CPaneContainer::m_bRetainInternalSliderPosition != 0 )
            {
              rectFinalLeft.right = rectFinalLeft.left + v49;
              v60 = GetCapture();
              v61 = CWnd::FromHandle(hWnd: v60);
              v62 = this->m_pSlider;
              if ( v61 == v62 )
              {
                left = rectFinalLeft.right;
              }
              else
              {
                Rect = rectSlider.tagRECT;
                v63 = GetParent(hWnd: v62->m_hWnd);
                v64 = CWnd::FromHandle(hWnd: v63);
                CWnd::ScreenToClient(this: v64, lpRect: &Rect);
                left = Rect.left;
                rectFinalLeft.right = Rect.left;
              }
              v54 = rectFinalLeft.left;
              v50 = (double)(rectContainer.right - rectContainer.left);
              *(double *)&Rect.right = (double)(left - rectFinalLeft.left) / v50;
              v53 = 100.0;
              goto LABEL_132;
            }
            if ( v51 <= 0 )
            {
              if ( v51 >= 0 )
              {
LABEL_130:
                v54 = rectFinalLeft.left;
                left = v49 + rectFinalLeft.left;
                rectFinalLeft.right = v49 + rectFinalLeft.left;
                if ( nPercent != -1 )
                  *(double *)&Rect.right = (double)nPercent;
LABEL_132:
                v56 = this->m_pSlider;
                rectFinalSlider.left = left;
                v57 = left + v56->m_nWidth;
                rectFinalSlider.right = v57;
                rectFinalRight.left = v57;
                if ( CPane::m_bHandleMinSize == 0 )
                  goto LABEL_155;
                v58 = sizeMinRight.cx + v57 - rectFinalRight.right;
                v59 = this->m_pSlider->m_nWidth;
                if ( sizeMinLeft.cx + v54 - left > 0 )
                {
                  if ( v58 <= 0 )
                  {
                    left = sizeMinLeft.cx + v54;
                    rectFinalLeft.right = sizeMinLeft.cx + v54;
                    rectFinalRight.left = v59 + sizeMinLeft.cx + v54;
                    if ( rectFinalRight.right - rectFinalRight.left < sizeMinRight.cx )
                    {
                      v65 = v59 + left;
LABEL_152:
                      rectFinalRight.right = sizeMinRight.cx + v65;
                    }
LABEL_153:
                    rectFinalSlider.left = left;
                    rectFinalSlider.right = left + v59;
                    *(double *)&Rect.right = (double)(left - v54) / v50 * v53;
                    if ( rectFinalLeft.bottom - rectFinalLeft.top < sizeMinLeft.cy )
                    {
                      rectFinalLeft.bottom = sizeMinLeft.cy + rectFinalLeft.top;
                      rectFinalRight.bottom = sizeMinLeft.cy + rectFinalRight.top;
                    }
                    goto LABEL_155;
                  }
                  left = v54 + sizeMinLeft.cx;
                }
                else
                {
                  if ( v58 <= 0 )
                    goto LABEL_153;
                  left -= v58;
                  rectFinalLeft.right = left;
                  if ( left - v54 >= sizeMinLeft.cx )
                    goto LABEL_151;
                  left = v54 + sizeMinLeft.cx;
                }
                rectFinalLeft.right = left;
LABEL_151:
                v65 = v59 + left;
                rectFinalRight.left = v59 + left;
                goto LABEL_152;
              }
            }
            else
            {
              v52 = 100.0 - v52;
            }
          }
          v54 = rectFinalLeft.left;
          left = rectFinalLeft.left + v41 - (int)(v52 * (double)nDelta / -100.0) - rectLeft.left;
          rectFinalLeft.right = left;
          goto LABEL_132;
        }
        m_nRecentPercent = v45->m_nRecentPercent;
      }
      if ( m_nRecentPercent == 100 || m_nRecentPercent == 0 )
        m_nRecentPercent = 50;
      goto LABEL_114;
    }
    if ( right - rectRight.left != v42 )
      goto LABEL_125;
    v46 = this->m_pBarLeftTop;
    nPercent = 50;
    if ( v46 != nullptr )
    {
      v47 = v46->m_nLastPercent;
    }
    else
    {
      v48 = this->m_pLeftContainer;
      if ( v48 == nullptr )
      {
LABEL_123:
        v41 = rectLeft.left + nPercent * v42 / 100;
        rectLeft.right = v41;
        goto LABEL_125;
      }
      v47 = v48->m_nRecentPercent;
    }
    nPercent = v47;
    if ( v47 == 100 || v47 == 0 )
      nPercent = 50;
    goto LABEL_123;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10400A4F
// Name: protected: void CPaneContainer::SaveTabbedPane(class CArchive __near &,class CDockablePane __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPaneContainer::SaveTabbedPane(CPaneContainer *this, CArchive *ar, CDockablePane *pBar)
{
  CWnd *v3; // esi
  unsigned int Style; // eax

  v3 = (CWnd *)AfxDynamicDownCast(pClass: &CBaseTabbedPane::classCBaseTabbedPane, pObject: &pBar->CPane);
  if ( ((int (__thiscall *)(CWnd *))v3->__vftable[2].put_accValue)(a1: v3) > 0 )
  {
    CArchive::operator<<(this: ar, dw: 0xFFFFFFFF);
    ((void (__thiscall *)(CWnd *, CArchive *))v3->__vftable[2].PostNcDestroy)(a1: v3, a2: ar);
    CArchive::WriteObject(this: ar, pOb: v3);
    Style = CWnd::GetStyle(this: v3);
    CArchive::operator<<(this: ar, dw: Style);
    ((void (__thiscall *)(CWnd *, CArchive *))v3->__vftable[2].DefWindowProcA)(a1: v3, a2: ar);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10400AB4
// Name: public: class CDockablePane __near * CPaneContainer::FindTabbedPane(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDockablePane *__thiscall CPaneContainer::FindTabbedPane(CPaneContainer *this, HWND__ *nID)
{
  CPaneContainer *m_pLeftContainer; // ecx
  CDockablePane *result; // eax

  do
  {
    if ( CList<unsigned int,unsigned int>::Find(
           this: (CList<HWND__ *,HWND__ *> *)&this->m_lstSavedSiblingBarIDsLeft,
           searchValue: nID,
           startAfter: nullptr) != nullptr )
      return this->m_pBarLeftTop;
    if ( CList<unsigned int,unsigned int>::Find(
           this: (CList<HWND__ *,HWND__ *> *)&this->m_lstSavedSiblingBarIDsRight,
           searchValue: nID,
           startAfter: nullptr) != nullptr )
      return this->m_pBarRightBottom;
    m_pLeftContainer = this->m_pLeftContainer;
    if ( m_pLeftContainer != nullptr )
    {
      result = CPaneContainer::FindTabbedPane(this: m_pLeftContainer, (unsigned int)nID);
      if ( result != nullptr )
        return result;
    }
    this = this->m_pRightContainer;
  }
  while ( this != nullptr );
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10411F75
// Name: public: void CDockingPanesRow::GetWindowRect(class CRect __near &)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockingPanesRow::GetWindowRect(CDockingPanesRow *this, CRect *rect)
{
  CDockSite *m_pParentDockBar; // eax
  int m_nRowOffset; // eax

  SetRectEmpty(lprc: rect);
  m_pParentDockBar = this->m_pParentDockBar;
  if ( m_pParentDockBar != nullptr )
  {
    GetWindowRect(hWnd: m_pParentDockBar->m_hWnd, lpRect: rect);
    m_nRowOffset = this->m_nRowOffset;
    if ( (this->m_dwRowAlignment & 0xA000) != 0 )
    {
      rect->top += m_nRowOffset;
      rect->bottom = rect->top + this->m_nRowHeight;
    }
    else
    {
      rect->left += m_nRowOffset;
      rect->right = rect->left + this->m_nRowHeight;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10411FC3
// Name: public: void CDockingPanesRow::GetClientRect(class CRect __near &)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockingPanesRow::GetClientRect(CDockingPanesRow *this, CRect *rect)
{
  int m_nRowOffset; // eax

  CDockingPanesRow::GetWindowRect(this, rect);
  CWnd::ScreenToClient(this: this->m_pParentDockBar, lpRect: rect);
  m_nRowOffset = this->m_nRowOffset;
  if ( (this->m_dwRowAlignment & 0xA000) != 0 )
  {
    rect->top -= m_nRowOffset;
    rect->bottom = rect->top + this->m_nRowHeight;
  }
  else
  {
    rect->left -= m_nRowOffset;
    rect->right = rect->left + this->m_nRowHeight;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10412008
// Name: public: virtual void CDockingPanesRow::UpdateVisibleState(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockingPanesRow::UpdateVisibleState(CDockingPanesRow *this, int bDelay)
{
  HWND Parent; // eax
  CWnd *v4; // eax
  BOOL v5; // eax
  CObList::CNode *m_pNodeHead; // ebx
  BOOL v7; // esi
  CObList::CNode *v8; // eax
  CWnd *data; // ecx
  int v10; // eax
  int bOldVisibleState; // [esp+Ch] [ebp-Ch]
  CBasePane *pNextWnd; // [esp+10h] [ebp-8h]
  int bNewVisibleState; // [esp+14h] [ebp-4h]

  Parent = GetParent(hWnd: this->m_pParentDockBar->m_hWnd);
  v4 = CWnd::FromHandle(hWnd: Parent);
  v5 = IsWindowVisible(hWnd: v4->m_hWnd);
  m_pNodeHead = this->m_lstControlBars.m_pNodeHead;
  v7 = !v5;
  bNewVisibleState = 0;
  bOldVisibleState = this->m_bVisible;
  while ( m_pNodeHead != nullptr )
  {
    v8 = m_pNodeHead;
    data = (CWnd *)m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    pNextWnd = (CBasePane *)v8->data;
    if ( v7
      && (v10 = ((int (__thiscall *)(CWnd *))data->__vftable[1].GetConnectionHook)(a1: data), data = pNextWnd, v10 != 0) )
    {
      bNewVisibleState = pNextWnd->GetRecentVisibleState(this: pNextWnd);
      if ( bNewVisibleState != 0 )
        break;
    }
    else if ( (CWnd::GetStyle(this: data) & 0x10000000) != 0 )
    {
      bNewVisibleState = 1;
      break;
    }
  }
  if ( bOldVisibleState != bNewVisibleState )
    this->ShowDockSiteRow(this, a2: bNewVisibleState, a3: bDelay);
  this->m_bVisible = bNewVisibleState;
}

//------------------------------------------------------------------------------
// Address: 0x104120B4
// Name: public: void CDockingPanesRow::ExpandStretchedPanes(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall CDockingPanesRow::ExpandStretchedPanes(CDockingPanesRow *this@<ecx>, int a2@<edi>)
{
  int v3; // eax
  CObList::CNode *m_pNodeHead; // edi
  CObject *data; // ebx
  int v6; // eax
  void *hdwp; // [esp+8h] [ebp-8h] BYREF
  int nAvailableLen; // [esp+Ch] [ebp-4h]

  if ( this->m_lstControlBars.m_nCount != 0 )
  {
    v3 = ((int (__thiscall *)(CDockingPanesRow *, _DWORD, int))this->GetAvailableLength)(a1: this, a2: 0, a3: a2);
    m_pNodeHead = this->m_lstControlBars.m_pNodeHead;
    nAvailableLen = v3;
    hdwp = nullptr;
    while ( m_pNodeHead != nullptr )
    {
      data = m_pNodeHead->data;
      m_pNodeHead = m_pNodeHead->pNext;
      if ( ((int (__thiscall *)(CObject *))data->__vftable[31].dtr_CObject)(a1: data) != 0
        || this->m_bIgnoreBarVisibility != 0 )
      {
        v6 = ((int (__thiscall *)(CObject *, int, void **))data->__vftable[57].GetRuntimeClass)(
               a1: data,
               a2: nAvailableLen,
               a3: &hdwp);
        nAvailableLen -= v6;
        if ( nAvailableLen <= 0 )
          break;
      }
    }
    this->ArrangePanes(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1041212A
// Name: private: void CDockingPanesRow::ShiftPanes(class CPane __near *,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockingPanesRow::ShiftPanes(CDockingPanesRow *this, CPane *pControlBar, int nOffset, int bForward)
{
  CDockingPanesRow *v4; // edi
  __POSITION *v5; // esi
  CObList::CNode *m_pNodeHead; // eax
  __POSITION *v7; // ecx
  HWND *v8; // ebx
  int v9; // eax
  CPane *data; // [esp+Ch] [ebp-30h]
  __POSITION *pos; // [esp+10h] [ebp-2Ch]
  int nMoveOffset; // [esp+14h] [ebp-28h]
  CRect rectBar; // [esp+18h] [ebp-24h] BYREF
  CRect rectNextBar; // [esp+28h] [ebp-14h] BYREF

  v4 = this;
  data = pControlBar;
  if ( nOffset != 0 )
  {
    if ( pControlBar != nullptr )
    {
      v5 = CPtrList::Find(this: &this->m_lstControlBars, searchValue: pControlBar, startAfter: nullptr);
    }
    else
    {
      if ( bForward != 0 )
        m_pNodeHead = this->m_lstControlBars.m_pNodeHead;
      else
        m_pNodeHead = this->m_lstControlBars.m_pNodeTail;
      if ( m_pNodeHead == nullptr )
        AfxThrowInvalidArgException();
      v5 = (__POSITION *)m_pNodeHead;
      data = (CPane *)m_pNodeHead->data;
    }
    nMoveOffset = nOffset;
    memset(&rectBar, 0, sizeof(rectBar));
    SetRectEmpty(lprc: &rectBar);
    if ( v5 != nullptr )
    {
      while ( 1 )
      {
        if ( bForward != 0 )
          v7 = *(__POSITION **)v5;
        else
          v7 = *(__POSITION **)&v5[4];
        v8 = *(HWND **)&v5[8];
        pos = v7;
        if ( (*((int (**)(void))*v8 + 94))() != 0 || v4->m_bIgnoreBarVisibility != 0 )
        {
          memset(&rectNextBar, 0, sizeof(rectNextBar));
          GetWindowRect(hWnd: v8[8], lpRect: &rectNextBar);
          if ( v8 != (HWND *)data && !IsRectEmpty(lprc: &rectBar) )
          {
            if ( (v4->m_dwRowAlignment & 0xA000) != 0 )
            {
              if ( bForward != 0 )
                v9 = rectNextBar.left - rectBar.right;
              else
                v9 = rectNextBar.right - rectBar.left;
            }
            else if ( bForward != 0 )
            {
              v9 = rectNextBar.top - rectBar.bottom;
            }
            else
            {
              v9 = rectNextBar.bottom - rectBar.top;
            }
            nMoveOffset -= v9;
          }
          if ( nMoveOffset > 0 )
            goto LABEL_31;
          if ( bForward != 0 )
            return;
          if ( nMoveOffset >= 0 )
          {
LABEL_31:
            if ( bForward == 0 )
              return;
          }
          rectBar = rectNextBar;
          if ( (this->m_dwRowAlignment & 0xA000) != 0 )
            OffsetRect(lprc: &rectNextBar, dx: nMoveOffset, dy: 0);
          else
            OffsetRect(lprc: &rectNextBar, dx: 0, dy: nMoveOffset);
          CWnd::ScreenToClient(this: this->m_pParentDockBar, lpRect: &rectNextBar);
          (*((void (__thiscall **)(HWND *, _DWORD, int, int, int, int, int, _DWORD))*v8 + 141))(
            a1: v8,
            a2: 0,
            a3: rectNextBar.left,
            a4: rectNextBar.top,
            a5: rectNextBar.right - rectNextBar.left,
            a6: rectNextBar.bottom - rectNextBar.top,
            a7: 20,
            a8: 0);
          v4 = this;
        }
        if ( pos == nullptr )
          return;
        v5 = pos;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104122D7
// Name: public: void CDockingPanesRow::MovePane(class CPane __near *,class CRect,void __near * __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockingPanesRow::MovePane(
        CDockingPanesRow *this,
        CPane *pControlBar,
        CRect rectTarget,
        void **__formal)
{
  HWND__ *m_hWnd; // [esp-8h] [ebp-28h]
  CRect rectBarWnd; // [esp+Ch] [ebp-14h] BYREF

  m_hWnd = pControlBar->m_hWnd;
  memset(&rectBarWnd, 0, sizeof(rectBarWnd));
  GetWindowRect(hWnd: m_hWnd, lpRect: &rectBarWnd);
  if ( (this->m_dwRowAlignment & 0xA000) != 0 )
  {
    rectBarWnd.left = rectTarget.left;
    rectBarWnd.right = rectTarget.right;
  }
  else
  {
    rectBarWnd.top = rectTarget.top;
    rectBarWnd.bottom = rectTarget.bottom;
  }
  CWnd::ScreenToClient(this: this->m_pParentDockBar, lpRect: &rectBarWnd);
  pControlBar->SetWindowPos(
    this: pControlBar,
    a2: nullptr,
    a3: rectBarWnd.left,
    a4: rectBarWnd.top,
    a5: rectBarWnd.right - rectBarWnd.left,
    a6: rectBarWnd.bottom - rectBarWnd.top,
    a7: 20u,
    a8: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1041236E
// Name: public: void CDockingPanesRow::MovePane(class CPane __near *,int,bool,void __near * __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockingPanesRow::MovePane(
        CDockingPanesRow *this,
        CPane *pControlBar,
        int nOffset,
        bool bForward,
        void **__formal)
{
  int v5; // edi
  HWND__ *m_hWnd; // [esp-8h] [ebp-2Ch]
  CRect rectBarWnd; // [esp+10h] [ebp-14h] BYREF

  v5 = nOffset;
  if ( nOffset != 0 )
  {
    m_hWnd = pControlBar->m_hWnd;
    memset(&rectBarWnd, 0, sizeof(rectBarWnd));
    GetWindowRect(hWnd: m_hWnd, lpRect: &rectBarWnd);
    if ( (this->m_dwRowAlignment & 0xA000) != 0 )
    {
      if ( !bForward )
        v5 = -nOffset;
      OffsetRect(lprc: &rectBarWnd, dx: v5, dy: 0);
    }
    else
    {
      if ( !bForward )
        v5 = -nOffset;
      OffsetRect(lprc: &rectBarWnd, dx: 0, dy: v5);
    }
    CWnd::ScreenToClient(this: this->m_pParentDockBar, lpRect: &rectBarWnd);
    pControlBar->SetWindowPos(
      this: pControlBar,
      a2: nullptr,
      a3: rectBarWnd.left,
      a4: rectBarWnd.top,
      a5: rectBarWnd.right - rectBarWnd.left,
      a6: rectBarWnd.bottom - rectBarWnd.top,
      a7: 20u,
      a8: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10412417
// Name: public: void CDockingPanesRow::MovePane(class CPane __near *,int,void __near * __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockingPanesRow::MovePane(
        CDockingPanesRow *this,
        CPane *pControlBar,
        int nAbsolutOffset,
        void **__formal)
{
  int v5; // eax
  int v6; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-38h]
  CRect rectRow; // [esp+Ch] [ebp-24h] BYREF
  CRect rectBarWnd; // [esp+1Ch] [ebp-14h] BYREF

  m_hWnd = pControlBar->m_hWnd;
  memset(&rectBarWnd, 0, sizeof(rectBarWnd));
  GetWindowRect(hWnd: m_hWnd, lpRect: &rectBarWnd);
  memset(&rectRow, 0, sizeof(rectRow));
  CDockingPanesRow::GetWindowRect(this, rect: &rectRow);
  if ( (this->m_dwRowAlignment & 0xA000) != 0 )
  {
    v5 = rectBarWnd.right - rectBarWnd.left;
    rectBarWnd.left = rectRow.left + nAbsolutOffset;
    rectBarWnd.right = v5 + rectRow.left + nAbsolutOffset;
  }
  else
  {
    v6 = rectBarWnd.bottom - rectBarWnd.top;
    rectBarWnd.top = rectRow.top + nAbsolutOffset;
    rectBarWnd.bottom = v6 + rectRow.top + nAbsolutOffset;
  }
  CWnd::ScreenToClient(this: this->m_pParentDockBar, lpRect: &rectBarWnd);
  pControlBar->SetWindowPos(
    this: pControlBar,
    a2: nullptr,
    a3: rectBarWnd.left,
    a4: rectBarWnd.top,
    a5: rectBarWnd.right - rectBarWnd.left,
    a6: rectBarWnd.bottom - rectBarWnd.top,
    a7: 20u,
    a8: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x104124D2
// Name: public: virtual int CDockingPanesRow::GetVisibleCount(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDockingPanesRow::GetVisibleCount(CDockingPanesRow *this)
{
  CObList::CNode *m_pNodeHead; // esi
  int v3; // ebx
  CObList::CNode *v4; // eax

  m_pNodeHead = this->m_lstControlBars.m_pNodeHead;
  v3 = 0;
  while ( m_pNodeHead != nullptr )
  {
    v4 = m_pNodeHead;
    m_pNodeHead = m_pNodeHead->pNext;
    if ( this->m_bIgnoreBarVisibility != 0
      || ((int (__thiscall *)(CObject *))v4->data->__vftable[31].dtr_CObject)(a1: v4->data) != 0 )
    {
      ++v3;
    }
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1041250E
// Name: private: void CDockingPanesRow::ResolveIntersection(class CPane __near *,bool,void __near * __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockingPanesRow::ResolveIntersection(CDockingPanesRow *this, CPane *pBar, bool bForward, void **hdwp)
{
  __POSITION *v5; // esi
  __POSITION *v6; // eax
  HWND *v7; // edi
  __POSITION *v8; // edi
  __POSITION *v9; // eax
  HWND *v10; // esi
  unsigned int m_dwRowAlignment; // eax
  int v12; // eax
  int v13; // ecx
  __POSITION *posSave; // [esp+Ch] [ebp-40h]
  CPane *pMovedBar; // [esp+14h] [ebp-38h]
  CRect rectRowWnd; // [esp+18h] [ebp-34h] BYREF
  CRect rectMovedBar; // [esp+28h] [ebp-24h] BYREF
  CRect rectBarWnd; // [esp+38h] [ebp-14h] BYREF

  v5 = CPtrList::Find(this: &this->m_lstControlBars, searchValue: pBar, startAfter: nullptr);
  memset(&rectBarWnd, 0, sizeof(rectBarWnd));
  SetRectEmpty(lprc: &rectBarWnd);
  memset(&rectRowWnd, 0, sizeof(rectRowWnd));
  CDockingPanesRow::GetWindowRect(this, rect: &rectRowWnd);
  memset(&rectMovedBar, 0, sizeof(rectMovedBar));
  while ( v5 != nullptr )
  {
    v6 = v5;
    if ( bForward )
      v5 = *(__POSITION **)v5;
    else
      v5 = *(__POSITION **)&v5[4];
    v7 = *(HWND **)&v6[8];
    if ( (*((int (__thiscall **)(HWND *))*v7 + 94))(a1: v7) != 0 || this->m_bIgnoreBarVisibility != 0 )
    {
      GetWindowRect(hWnd: v7[8], lpRect: &rectBarWnd);
      v8 = v5;
      if ( v5 == nullptr )
        return;
      do
      {
        posSave = v8;
        v9 = v8;
        if ( bForward )
        {
          if ( v8 == nullptr )
            goto LABEL_42;
          v8 = *(__POSITION **)v8;
        }
        else
        {
          if ( v8 == nullptr )
LABEL_42:
            AfxThrowInvalidArgException();
          v8 = *(__POSITION **)&v8[4];
        }
        v10 = *(HWND **)&v9[8];
        pMovedBar = (CPane *)v10;
        if ( (*((int (__thiscall **)(HWND *))*v10 + 94))(a1: v10) != 0 )
          break;
        if ( this->m_bIgnoreBarVisibility != 0 )
          goto LABEL_17;
        pMovedBar = nullptr;
      }
      while ( v8 != nullptr );
      v10 = (HWND *)pMovedBar;
LABEL_17:
      if ( v10 == nullptr )
        return;
      GetWindowRect(hWnd: v10[8], lpRect: &rectMovedBar);
      m_dwRowAlignment = this->m_dwRowAlignment;
      if ( bForward )
      {
        if ( (m_dwRowAlignment & 0x2000) == 0 && (m_dwRowAlignment & 0x8000) == 0
          || rectMovedBar.left <= rectBarWnd.right )
        {
          if ( (m_dwRowAlignment & 0x2000) != 0 )
            goto LABEL_26;
          if ( (m_dwRowAlignment & 0x8000) != 0 || rectMovedBar.top <= rectBarWnd.bottom )
          {
            if ( (m_dwRowAlignment & 0x8000) != 0 )
            {
LABEL_26:
              v12 = rectBarWnd.right - rectMovedBar.left;
LABEL_38:
              CDockingPanesRow::MovePane(this, pControlBar: pMovedBar, nOffset: v12, bForward, __formal: hdwp);
              goto LABEL_39;
            }
            v13 = rectBarWnd.bottom - rectMovedBar.top;
            goto LABEL_37;
          }
        }
      }
      else if ( (m_dwRowAlignment & 0x2000) == 0 && (m_dwRowAlignment & 0x8000) == 0
             || rectMovedBar.right >= rectBarWnd.left )
      {
        if ( (m_dwRowAlignment & 0x2000) != 0 )
          goto LABEL_34;
        if ( (m_dwRowAlignment & 0x8000) != 0 || rectMovedBar.bottom >= rectBarWnd.top )
        {
          if ( (m_dwRowAlignment & 0x8000) != 0 )
          {
LABEL_34:
            v12 = rectMovedBar.right - rectBarWnd.left;
            goto LABEL_38;
          }
          v13 = rectMovedBar.bottom - rectBarWnd.top;
LABEL_37:
          v12 = v13;
          goto LABEL_38;
        }
      }
LABEL_39:
      v5 = posSave;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104126E6
// Name: private: int CDockingPanesRow::IsEnoughSpaceToMove(class CPane __near *,bool,int __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDockingPanesRow::IsEnoughSpaceToMove(
        CDockingPanesRow *this,
        CPane *pControlBar,
        bool bForward,
        int *nAllowedOffset)
{
  int *v4; // esi
  CObList::CNode *m_pNodeHead; // eax
  int v7; // eax
  CPane *data; // edi
  bool IsLeftOf; // al
  int v10; // eax
  int v11; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-58h]
  __POSITION *pos; // [esp+Ch] [ebp-44h]
  int nLen; // [esp+18h] [ebp-38h]
  CRect rectRow; // [esp+1Ch] [ebp-34h] BYREF
  CRect rectControlBar; // [esp+2Ch] [ebp-24h] BYREF
  CRect rectBar; // [esp+3Ch] [ebp-14h] BYREF

  v4 = nAllowedOffset;
  m_pNodeHead = this->m_lstControlBars.m_pNodeHead;
  nLen = 0;
  if ( m_pNodeHead != nullptr )
  {
    while ( 1 )
    {
      memset(&rectBar, 0, sizeof(rectBar));
      data = (CPane *)m_pNodeHead->data;
      pos = (__POSITION *)m_pNodeHead->pNext;
      if ( data->IsVisible(this: data) != 0 || this->m_bIgnoreBarVisibility != 0 )
      {
        GetWindowRect(hWnd: data->m_hWnd, lpRect: &rectBar);
        if ( data != pControlBar )
        {
          IsLeftOf = CPane::IsLeftOf(this: pControlBar, rect: rectBar, bWindowRect: true);
          if ( bForward )
          {
            if ( IsLeftOf )
              goto LABEL_11;
          }
          else if ( !IsLeftOf )
          {
LABEL_11:
            v4 = nAllowedOffset;
            goto LABEL_12;
          }
          v4 = nAllowedOffset;
          if ( (this->m_dwRowAlignment & 0xA000) != 0 )
            v10 = rectBar.right - rectBar.left;
          else
            v10 = rectBar.bottom - rectBar.top;
          nLen += v10;
        }
      }
LABEL_12:
      if ( pos == nullptr )
        break;
      m_pNodeHead = (CObList::CNode *)pos;
    }
  }
  m_hWnd = pControlBar->m_hWnd;
  memset(&rectControlBar, 0, sizeof(rectControlBar));
  GetWindowRect(hWnd: m_hWnd, lpRect: &rectControlBar);
  memset(&rectRow, 0, sizeof(rectRow));
  CDockingPanesRow::GetWindowRect(this, rect: &rectRow);
  *v4 = 0;
  if ( (this->m_dwRowAlignment & 0xA000) != 0 )
  {
    if ( bForward )
      v7 = rectRow.right - rectControlBar.right;
    else
      v7 = rectRow.left - rectControlBar.left;
  }
  else if ( bForward )
  {
    v7 = rectRow.bottom - rectControlBar.bottom;
  }
  else
  {
    v7 = rectRow.top - rectControlBar.top;
  }
  *v4 = v7;
  if ( bForward )
    v11 = v7 - nLen;
  else
    v11 = nLen + v7;
  *v4 = v11;
  if ( bForward )
  {
    if ( v11 > 0 )
      return 1;
  }
  else if ( v11 < 0 )
  {
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10412857
// Name: public: void CDockingPanesRow::FixupVirtualRects(bool,class CPane __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockingPanesRow::FixupVirtualRects(
        CDockingPanesRow *this,
        bool bMoveBackToVirtualRect,
        CPane *pBarToExclude)
{
  CDockingPanesRow *v3; // esi
  void *m_pNodeHead; // eax
  __POSITION *v5; // ecx
  CPane *v6; // ebx
  CPane_vtbl *v7; // eax
  void *hdwp; // [esp+Ch] [ebp-30h] BYREF
  CDockingPanesRow *v9; // [esp+10h] [ebp-2Ch]
  __POSITION *pos; // [esp+14h] [ebp-28h]
  CRect rectBarWnd; // [esp+18h] [ebp-24h] BYREF
  CRect rectVirtual; // [esp+28h] [ebp-14h] BYREF

  v3 = this;
  m_pNodeHead = this->m_lstControlBars.m_pNodeHead;
  v9 = this;
  if ( m_pNodeHead != nullptr )
  {
    while ( 1 )
    {
      v5 = *(__POSITION **)m_pNodeHead;
      v6 = *((CPane **)m_pNodeHead + 2);
      v7 = v6->__vftable;
      pos = v5;
      if ( (v7->IsVisible(this: v6) != 0 || v3->m_bIgnoreBarVisibility != 0) && v6 != pBarToExclude )
      {
        memset(&rectBarWnd, 0, sizeof(rectBarWnd));
        GetWindowRect(hWnd: v6->m_hWnd, lpRect: &rectBarWnd);
        if ( bMoveBackToVirtualRect )
        {
          memset(&rectVirtual, 0, sizeof(rectVirtual));
          CPane::GetVirtualRect(this: v6, &rectVirtual);
          if ( !EqualRect(lprc1: &rectVirtual, lprc2: &rectBarWnd) )
          {
            hdwp = BeginDeferWindowPos(nNumWindows: v3->m_lstControlBars.m_nCount);
            CDockingPanesRow::MovePane(this: v9, pControlBar: v6, rectTarget: rectVirtual, __formal: &hdwp);
            EndDeferWindowPos(hWinPosInfo: hdwp);
            v3 = v9;
          }
        }
        else
        {
          CPane::UpdateVirtualRect(this: v6);
        }
      }
      if ( pos == nullptr )
        break;
      m_pNodeHead = pos;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10412954
// Name: public: virtual int CDockingPanesRow::GetAvailableLength(int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDockingPanesRow::GetAvailableLength(CDockingPanesRow *this, int bUseVirtualRect)
{
  CObList::CNode *m_pNodeHead; // edi
  int v4; // eax
  CPane *data; // ebx
  int v6; // eax
  int nTotalBarLength; // [esp+Ch] [ebp-28h]
  CRect rectRow; // [esp+10h] [ebp-24h] BYREF
  CRect rectWnd; // [esp+20h] [ebp-14h] BYREF

  memset(&rectRow, 0, sizeof(rectRow));
  CDockingPanesRow::GetClientRect(this, rect: &rectRow);
  m_pNodeHead = this->m_lstControlBars.m_pNodeHead;
  nTotalBarLength = 0;
  while ( m_pNodeHead != nullptr )
  {
    data = (CPane *)m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    if ( data->IsVisible(this: data) != 0 || this->m_bIgnoreBarVisibility != 0 )
    {
      memset(&rectWnd, 0, sizeof(rectWnd));
      if ( bUseVirtualRect != 0 )
        CPane::GetVirtualRect(this: data, rectVirtual: &rectWnd);
      else
        GetWindowRect(hWnd: data->m_hWnd, lpRect: &rectWnd);
      if ( (this->m_dwRowAlignment & 0xA000) != 0 )
        v6 = rectWnd.right - rectWnd.left;
      else
        v6 = rectWnd.bottom - rectWnd.top;
      nTotalBarLength += v6;
    }
  }
  if ( (this->m_dwRowAlignment & 0xA000) != 0 )
    v4 = rectRow.right - rectRow.left;
  else
    v4 = rectRow.bottom - rectRow.top;
  return v4 - nTotalBarLength;
}

//------------------------------------------------------------------------------
// Address: 0x10412A25
// Name: public: int CDockingPanesRow::GetMaxPaneSize(int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDockingPanesRow::GetMaxPaneSize(CDockingPanesRow *this, int bSkipHiddenBars)
{
  CObList::CNode *m_pNodeHead; // eax
  HWND *data; // esi
  unsigned int m_dwRowAlignment; // ecx
  int v6; // eax
  __POSITION *pos; // [esp+8h] [ebp-1Ch]
  int nMaxSize; // [esp+Ch] [ebp-18h]
  CRect rectWnd; // [esp+10h] [ebp-14h] BYREF

  m_pNodeHead = this->m_lstControlBars.m_pNodeHead;
  nMaxSize = 0;
  if ( m_pNodeHead != nullptr )
  {
    while ( 1 )
    {
      data = (HWND *)m_pNodeHead->data;
      pos = (__POSITION *)m_pNodeHead->pNext;
      if ( (*((int (__thiscall **)(HWND *))*data + 94))(a1: data) != 0
        || bSkipHiddenBars == 0
        || this->m_bIgnoreBarVisibility != 0 )
      {
        memset(&rectWnd, 0, sizeof(rectWnd));
        GetWindowRect(hWnd: data[8], lpRect: &rectWnd);
        m_dwRowAlignment = this->m_dwRowAlignment;
        if ( (m_dwRowAlignment & 0x2000) != 0 || (m_dwRowAlignment & 0x8000) != 0 )
          v6 = rectWnd.bottom - rectWnd.top;
        else
          v6 = rectWnd.right - rectWnd.left;
        if ( nMaxSize <= v6 )
        {
          if ( (this->m_dwRowAlignment & 0x2000) != 0 || (m_dwRowAlignment & 0x8000) != 0 )
            nMaxSize = rectWnd.bottom - rectWnd.top;
          else
            nMaxSize = rectWnd.right - rectWnd.left;
        }
      }
      if ( pos == nullptr )
        break;
      m_pNodeHead = (CObList::CNode *)pos;
    }
    if ( nMaxSize != 0 )
      nMaxSize += this->m_nExtraSpace;
  }
  return nMaxSize;
}

//------------------------------------------------------------------------------
// Address: 0x10412B07
// Name: public: virtual void CDockingPanesRow::GetAvailableSpace(class CRect __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockingPanesRow::GetAvailableSpace(CDockingPanesRow *this, CRect *rect)
{
  CObList::CNode *m_pNodeHead; // edi
  HWND *data; // esi
  CRect rectWnd; // [esp+Ch] [ebp-14h] BYREF

  CDockingPanesRow::GetWindowRect(this, rect);
  m_pNodeHead = this->m_lstControlBars.m_pNodeHead;
  while ( m_pNodeHead != nullptr )
  {
    data = (HWND *)m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    if ( (*((int (__thiscall **)(HWND *))*data + 94))(a1: data) != 0 || this->m_bIgnoreBarVisibility != 0 )
    {
      memset(&rectWnd, 0, sizeof(rectWnd));
      GetWindowRect(hWnd: data[8], lpRect: &rectWnd);
      if ( (this->m_dwRowAlignment & 0xA000) != 0 )
        InflateRect(lprc: rect, dx: rectWnd.left - rectWnd.right, dy: 0);
      else
        InflateRect(lprc: rect, dx: 0, dy: rectWnd.top - rectWnd.bottom);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10412BAB
// Name: public: virtual void CDockingPanesRow::ArrangePanes(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge CDockingPanesRow::ArrangePanes(CDockingPanesRow *this@<ecx>, BOOL a2@<edi>, int nMargin, int nSpacing)
{
  CMFCVisualManager *Instance; // eax
  void *m_pNodeHead; // eax
  __POSITION *v7; // ecx
  HWND *v8; // edi
  HWND v9; // eax
  int v10; // eax
  int v11; // eax
  CDockSite *m_pParentDockBar; // ecx
  _BYTE v14[8]; // [esp+8h] [ebp-44h] BYREF
  int nLen; // [esp+10h] [ebp-3Ch]
  int bIsOverlapped; // [esp+14h] [ebp-38h]
  __POSITION *pos; // [esp+18h] [ebp-34h]
  CPoint ptOffset; // [esp+1Ch] [ebp-30h]
  bool bFistBar; // [esp+27h] [ebp-25h]
  CRect rectRow; // [esp+28h] [ebp-24h] BYREF
  CRect rectBar; // [esp+38h] [ebp-14h] BYREF

  memset(&rectRow, 0, sizeof(rectRow));
  memset(&rectBar, 0, sizeof(rectBar));
  ptOffset.x = 0;
  ptOffset.y = 0;
  CDockingPanesRow::GetWindowRect(this, rect: &rectRow);
  bFistBar = true;
  Instance = CMFCVisualManager::GetInstance();
  bIsOverlapped = Instance->HasOverlappedAutoHideButtons(this: Instance);
  m_pNodeHead = this->m_lstControlBars.m_pNodeHead;
  if ( m_pNodeHead != nullptr )
  {
    while ( 1 )
    {
      v7 = *(__POSITION **)m_pNodeHead;
      v8 = *((HWND **)m_pNodeHead + 2);
      v9 = *v8;
      pos = v7;
      if ( (*((int (__thiscall **)(HWND *))v9 + 94))(a1: v8) == 0 && this->m_bIgnoreBarVisibility == 0 )
        goto LABEL_25;
      GetWindowRect(hWnd: v8[8], lpRect: &rectBar);
      if ( bFistBar )
      {
        if ( (this->m_dwRowAlignment & 0xA000) != 0 )
          ptOffset.x = nMargin + rectRow.left;
        else
          ptOffset.y = nMargin + rectRow.top;
      }
      if ( v8[65] != nullptr )
        goto LABEL_17;
      if ( bFistBar )
        goto LABEL_18;
      v10 = nSpacing + CMFCAutoHideButton::m_nBorderSize;
      if ( (this->m_dwRowAlignment & 0xA000) != 0 )
      {
        ptOffset.x -= v10;
        if ( bIsOverlapped != 0 )
          ptOffset.x += (rectBar.bottom - rectBar.top) / -2;
        goto LABEL_19;
      }
      ptOffset.y -= v10;
      if ( bIsOverlapped != 0 )
        break;
LABEL_19:
      if ( (this->m_dwRowAlignment & 0xA000) != 0 )
      {
        v11 = rectBar.right - rectBar.left;
        rectBar.left = ptOffset.x;
        rectBar.right = v11 + ptOffset.x;
      }
      else
      {
        v11 = rectBar.bottom - rectBar.top;
        rectBar.top = ptOffset.y;
        rectBar.bottom = v11 + ptOffset.y;
      }
      m_pParentDockBar = this->m_pParentDockBar;
      nLen = v11;
      CWnd::ScreenToClient(this: m_pParentDockBar, lpRect: &rectBar);
      (*((void (__thiscall **)(HWND *, _DWORD, int, int, int, int, int, _DWORD, BOOL))*v8 + 141))(
        a1: v8,
        a2: 0,
        a3: rectBar.left,
        a4: rectBar.top,
        a5: rectBar.right - rectBar.left,
        a6: rectBar.bottom - rectBar.top,
        a7: 20,
        a8: 0,
        a9: a2);
      a2 = (this->m_dwRowAlignment & 0xA000) == 0;
      (*((void (__thiscall **)(HWND *, _BYTE *, int))*v8 + 129))(a1: v8, a2: v14, a3: nLen);
      GetWindowRect(hWnd: v8[8], lpRect: &rectBar);
      if ( (this->m_dwRowAlignment & 0xA000) != 0 )
        ptOffset.x += nSpacing + rectBar.right - rectBar.left;
      else
        ptOffset.y += nSpacing + rectBar.bottom - rectBar.top;
LABEL_25:
      if ( pos == nullptr )
        return;
      m_pNodeHead = pos;
    }
    ptOffset.y += (rectBar.right - rectBar.left) / -2;
LABEL_17:
    if ( bFistBar )
    {
LABEL_18:
      bFistBar = false;
      goto LABEL_19;
    }
    goto LABEL_19;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10412D93
// Name: protected: class CPane __near * CDockingPanesRow::FindFirstVisiblePane(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPane *__thiscall CDockingPanesRow::FindFirstVisiblePane(CDockingPanesRow *this, int bForward)
{
  CObList::CNode *m_pNodeHead; // esi
  CObList::CNode *v5; // eax
  CObject *data; // edi

  if ( this->m_lstControlBars.m_nCount == 0 )
    return nullptr;
  if ( bForward != 0 )
    m_pNodeHead = this->m_lstControlBars.m_pNodeHead;
  else
    m_pNodeHead = this->m_lstControlBars.m_pNodeTail;
  do
  {
    if ( m_pNodeHead == nullptr )
      return nullptr;
    v5 = m_pNodeHead;
    if ( bForward != 0 )
      m_pNodeHead = m_pNodeHead->pNext;
    else
      m_pNodeHead = m_pNodeHead->pPrev;
    data = v5->data;
  }
  while ( this->m_bIgnoreBarVisibility == 0
       && ((int (__thiscall *)(CObject *))data->__vftable[31].dtr_CObject)(a1: data) == 0 );
  return (CPane *)data;
}

//------------------------------------------------------------------------------
// Address: 0x10412DFB
// Name: private: int CDockingPanesRow::GetOutOfBoundsOffset(class CPane __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDockingPanesRow::GetOutOfBoundsOffset(CDockingPanesRow *this, CPane *pBar, int bLeftTopBound)
{
  CPane *data; // eax
  CObList::CNode *m_pNodeHead; // eax
  CRect rectRow; // [esp+8h] [ebp-24h] BYREF
  CRect rectBar; // [esp+18h] [ebp-14h] BYREF

  data = pBar;
  memset(&rectBar, 0, sizeof(rectBar));
  memset(&rectRow, 0, sizeof(rectRow));
  if ( pBar == nullptr )
  {
    if ( bLeftTopBound != 0 )
      m_pNodeHead = this->m_lstControlBars.m_pNodeHead;
    else
      m_pNodeHead = this->m_lstControlBars.m_pNodeTail;
    data = (CPane *)m_pNodeHead->data;
  }
  GetWindowRect(hWnd: data->m_hWnd, lpRect: &rectBar);
  CDockingPanesRow::GetWindowRect(this, rect: &rectRow);
  if ( (this->m_dwRowAlignment & 0xA000) != 0 )
  {
    if ( bLeftTopBound != 0 )
      return rectRow.left - rectBar.left;
    else
      return rectBar.right - rectRow.right;
  }
  else if ( bLeftTopBound != 0 )
  {
    return rectRow.top - rectBar.top;
  }
  else
  {
    return rectBar.bottom - rectRow.bottom;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10412E9B
// Name: public: virtual int CDockingPanesRow::IsExclusiveRow(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDockingPanesRow::IsExclusiveRow(CDockingPanesRow *this)
{
  CObList::CNode *m_pNodeHead; // esi
  CObject *data; // ecx

  m_pNodeHead = this->m_lstControlBars.m_pNodeHead;
  do
  {
    if ( m_pNodeHead == nullptr )
      return 0;
    data = m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
  }
  while ( ((int (__thiscall *)(CObject *))data->__vftable[53].dtr_CObject)(a1: data) != 0 );
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10412ECC
// Name: protected: int CDockingPanesRow::CalcLastPaneOffset(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDockingPanesRow::CalcLastPaneOffset(CDockingPanesRow *this)
{
  int result; // eax
  CObject *data; // eax
  CRect rect; // [esp+4h] [ebp-14h] BYREF

  if ( this->m_lstControlBars.m_nCount == 0 )
    return 0;
  data = this->m_lstControlBars.m_pNodeTail->data;
  memset(&rect, 0, sizeof(rect));
  GetWindowRect(hWnd: (HWND)data[8].__vftable, lpRect: &rect);
  CWnd::ScreenToClient(this: this->m_pParentDockBar, lpRect: &rect);
  result = rect.right;
  if ( (this->m_dwRowAlignment & 0xA000) == 0 )
    return rect.bottom;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10412F33
// Name: public: void CDockingPanesRow::RedrawAll(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockingPanesRow::RedrawAll(CDockingPanesRow *this)
{
  CObList::CNode *m_pNodeHead; // esi
  CObject *data; // eax

  m_pNodeHead = this->m_lstControlBars.m_pNodeHead;
  while ( m_pNodeHead != nullptr )
  {
    data = m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    RedrawWindow(hWnd: (HWND)data[8].__vftable, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x401u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10412F64
// Name: public: void CDockingPanesRow::GetGroupFromPane(class CPane __near *,class CObList __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockingPanesRow::GetGroupFromPane(CDockingPanesRow *this, CPane *pBar, CObList *lst)
{
  __POSITION *v4; // eax
  int v5; // ecx
  CObList::CNode *m_pNodeHead; // esi
  CObList::CNode *v7; // eax
  CObject *data; // edi

  v4 = CPtrList::Find(this: &this->m_lstControlBars, searchValue: pBar, startAfter: nullptr);
  while ( v4 != nullptr )
  {
    v5 = *(_DWORD *)&v4[8];
    v4 = *(__POSITION **)&v4[4];
    if ( *(_DWORD *)(v5 + 260) != 0 )
    {
      if ( v4 != nullptr )
        m_pNodeHead = *(CObList::CNode **)v4;
      else
        m_pNodeHead = this->m_lstControlBars.m_pNodeHead;
      if ( m_pNodeHead != nullptr )
      {
        do
        {
          v7 = m_pNodeHead;
          data = m_pNodeHead->data;
          m_pNodeHead = m_pNodeHead->pNext;
          CPtrList::AddTail(this: lst, newElement: v7->data);
        }
        while ( data[66].__vftable == nullptr && m_pNodeHead != nullptr );
      }
      return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10412FD2
// Name: protected: void CDockingPanesRow::BeginTrans(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockingPanesRow::BeginTrans(CDockingPanesRow *this)
{
  CObList::CNode *m_pNodeHead; // esi
  CObject *data; // edi

  m_pNodeHead = this->m_lstControlBars.m_pNodeHead;
  while ( m_pNodeHead != nullptr )
  {
    data = m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    if ( ((int (__thiscall *)(CObject *))data->__vftable[31].dtr_CObject)(a1: data) != 0
      || this->m_bIgnoreBarVisibility != 0 )
    {
      GetWindowRect(hWnd: (HWND)data[8].__vftable, lpRect: (LPRECT)&data[39]);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1041301C
// Name: protected: void CDockingPanesRow::CommitTrans(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockingPanesRow::CommitTrans(CDockingPanesRow *this)
{
  CDockingPanesRow *v1; // esi
  CObList::CNode *m_pNodeHead; // eax
  CObject *data; // ebx
  HWND Parent; // eax
  CWnd *v5; // eax
  __POSITION *pos; // [esp+8h] [ebp-28h]
  CRect rectWnd; // [esp+Ch] [ebp-24h] BYREF
  CRect rect; // [esp+1Ch] [ebp-14h] BYREF

  v1 = this;
  m_pNodeHead = this->m_lstControlBars.m_pNodeHead;
  if ( m_pNodeHead != nullptr )
  {
    while ( 1 )
    {
      data = m_pNodeHead->data;
      pos = (__POSITION *)m_pNodeHead->pNext;
      if ( ((int (__thiscall *)(CObject *))data->__vftable[31].dtr_CObject)(a1: data) != 0
        || v1->m_bIgnoreBarVisibility != 0 )
      {
        rect = *(CRect *)&data[39].__vftable;
        memset(&rectWnd, 0, sizeof(rectWnd));
        GetWindowRect(hWnd: (HWND)data[8].__vftable, lpRect: &rectWnd);
        if ( !EqualRect(lprc1: &rect, lprc2: &rectWnd) )
        {
          Parent = GetParent(hWnd: (HWND)data[8].__vftable);
          v5 = CWnd::FromHandle(hWnd: Parent);
          CWnd::ScreenToClient(this: v5, lpRect: &rect);
          ((void (__thiscall *)(CObject *, _DWORD, int, int, int, int, int, _DWORD))data->__vftable[47].GetRuntimeClass)(
            a1: data,
            a2: 0,
            a3: rect.left,
            a4: rect.top,
            a5: rect.right - rect.left,
            a6: rect.bottom - rect.top,
            a7: 20,
            a8: 0);
        }
      }
      if ( pos == nullptr )
        break;
      m_pNodeHead = (CObList::CNode *)pos;
      v1 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10413103
// Name: protected: int CDockingPanesRow::GetAvailableLengthRect(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDockingPanesRow::GetAvailableLengthRect(CDockingPanesRow *this)
{
  CObList::CNode *m_pNodeHead; // eax
  CObject *data; // esi
  CObject *v4; // esi
  CObject *v5; // esi
  int v6; // eax
  int v7; // eax
  CObject_vtbl *rectWnd; // [esp+8h] [ebp-2Ch]
  CObject_vtbl *rectWnd_4; // [esp+Ch] [ebp-28h]
  __POSITION *pos; // [esp+18h] [ebp-1Ch]
  int nTotalBarLength; // [esp+1Ch] [ebp-18h]
  CRect rectRow; // [esp+20h] [ebp-14h] BYREF

  memset(&rectRow, 0, sizeof(rectRow));
  CDockingPanesRow::GetClientRect(this, rect: &rectRow);
  m_pNodeHead = this->m_lstControlBars.m_pNodeHead;
  nTotalBarLength = 0;
  if ( m_pNodeHead != nullptr )
  {
    while ( 1 )
    {
      data = m_pNodeHead->data;
      pos = (__POSITION *)m_pNodeHead->pNext;
      if ( ((int (__thiscall *)(CObject *))data->__vftable[31].dtr_CObject)(a1: data) != 0
        || this->m_bIgnoreBarVisibility != 0 )
      {
        v4 = data + 39;
        rectWnd = v4->__vftable;
        ++v4;
        rectWnd_4 = v4->__vftable;
        v5 = v4 + 1;
        if ( (this->m_dwRowAlignment & 0xA000) != 0 )
          v6 = (char *)v5->__vftable - (char *)rectWnd;
        else
          v6 = (char *)v5[1].__vftable - (char *)rectWnd_4;
        nTotalBarLength += v6;
      }
      if ( pos == nullptr )
        break;
      m_pNodeHead = (CObList::CNode *)pos;
    }
  }
  if ( (this->m_dwRowAlignment & 0xA000) != 0 )
    v7 = rectRow.right - rectRow.left;
  else
    v7 = rectRow.bottom - rectRow.top;
  return v7 - nTotalBarLength;
}

//------------------------------------------------------------------------------
// Address: 0x104131BB
// Name: protected: int CDockingPanesRow::GetOutOfBoundsOffsetRect(class CPane __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDockingPanesRow::GetOutOfBoundsOffsetRect(CDockingPanesRow *this, CPane *pBar, int bLeftTopBound)
{
  CPane *data; // eax
  CObList::CNode *m_pNodeHead; // eax
  int rectBar; // [esp+Ch] [ebp-24h]
  int rectBar_4; // [esp+10h] [ebp-20h]
  int rectBar_8; // [esp+14h] [ebp-1Ch]
  int rectBar_12; // [esp+18h] [ebp-18h]
  CRect rectRow; // [esp+1Ch] [ebp-14h] BYREF

  data = pBar;
  memset(&rectRow, 0, sizeof(rectRow));
  if ( pBar == nullptr )
  {
    if ( bLeftTopBound != 0 )
      m_pNodeHead = this->m_lstControlBars.m_pNodeHead;
    else
      m_pNodeHead = this->m_lstControlBars.m_pNodeTail;
    data = (CPane *)m_pNodeHead->data;
  }
  rectBar = data->m_rectBar.left;
  rectBar_4 = data->m_rectBar.top;
  rectBar_8 = data->m_rectBar.right;
  rectBar_12 = data->m_rectBar.bottom;
  CDockingPanesRow::GetWindowRect(this, rect: &rectRow);
  if ( (this->m_dwRowAlignment & 0xA000) != 0 )
  {
    if ( bLeftTopBound != 0 )
      return rectRow.left - rectBar;
    else
      return rectBar_8 - rectRow.right;
  }
  else if ( bLeftTopBound != 0 )
  {
    return rectRow.top - rectBar_4;
  }
  else
  {
    return rectBar_12 - rectRow.bottom;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10413253
// Name: protected: void CDockingPanesRow::ShiftPanesRect(class CPane __near *,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockingPanesRow::ShiftPanesRect(CDockingPanesRow *this, CPane *pControlBar, int nOffset, int bForward)
{
  CDockingPanesRow *v4; // edi
  __POSITION *v5; // esi
  CObList::CNode *m_pNodeHead; // eax
  __POSITION *v7; // ecx
  CPane *v8; // ebx
  int v9; // eax
  bool v10; // zf
  CPane *data; // [esp+Ch] [ebp-34h]
  int nMoveOffset; // [esp+14h] [ebp-2Ch]
  __POSITION *pos; // [esp+18h] [ebp-28h]
  CRect rectNextBar; // [esp+1Ch] [ebp-24h] BYREF
  CRect rectBar; // [esp+2Ch] [ebp-14h] BYREF

  v4 = this;
  data = pControlBar;
  if ( nOffset != 0 )
  {
    if ( pControlBar != nullptr )
    {
      v5 = CPtrList::Find(this: &this->m_lstControlBars, searchValue: pControlBar, startAfter: nullptr);
    }
    else
    {
      if ( bForward != 0 )
        m_pNodeHead = this->m_lstControlBars.m_pNodeHead;
      else
        m_pNodeHead = this->m_lstControlBars.m_pNodeTail;
      if ( m_pNodeHead == nullptr )
        AfxThrowInvalidArgException();
      v5 = (__POSITION *)m_pNodeHead;
      data = (CPane *)m_pNodeHead->data;
    }
    nMoveOffset = nOffset;
    memset(&rectBar, 0, sizeof(rectBar));
    SetRectEmpty(lprc: &rectBar);
    if ( v5 != nullptr )
    {
      while ( 1 )
      {
        if ( bForward != 0 )
          v7 = *(__POSITION **)v5;
        else
          v7 = *(__POSITION **)&v5[4];
        v8 = *(CPane **)&v5[8];
        pos = v7;
        if ( ((int (*)(void))v8->IsVisible)() != 0 || v4->m_bIgnoreBarVisibility != 0 )
        {
          rectNextBar = v8->m_rectBar;
          if ( v8 != data && !IsRectEmpty(lprc: &rectBar) )
          {
            if ( (this->m_dwRowAlignment & 0xA000) != 0 )
            {
              if ( bForward != 0 )
                v9 = rectNextBar.left - rectBar.right;
              else
                v9 = rectNextBar.right - rectBar.left;
            }
            else if ( bForward != 0 )
            {
              v9 = rectNextBar.top - rectBar.bottom;
            }
            else
            {
              v9 = rectNextBar.bottom - rectBar.top;
            }
            nMoveOffset -= v9;
          }
          if ( nMoveOffset > 0 )
            goto LABEL_31;
          if ( bForward != 0 )
            return;
          if ( nMoveOffset >= 0 )
          {
LABEL_31:
            if ( bForward == 0 )
              return;
          }
          v10 = (this->m_dwRowAlignment & 0xA000) == 0;
          rectBar = rectNextBar;
          if ( v10 )
            OffsetRect(lprc: &rectNextBar, dx: 0, dy: nMoveOffset);
          else
            OffsetRect(lprc: &rectNextBar, dx: nMoveOffset, dy: 0);
          v8->m_rectBar = rectNextBar;
          v4 = this;
        }
        if ( pos == nullptr )
          return;
        v5 = pos;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104133D1
// Name: protected: void CDockingPanesRow::MovePaneRect(class CPane __near *,int,bool)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockingPanesRow::MovePaneRect(CDockingPanesRow *this, CPane *pControlBar, int nOffset, bool bForward)
{
  int v4; // eax
  bool v5; // zf
  CRect rectBarWnd; // [esp+0h] [ebp-14h] BYREF

  v4 = nOffset;
  if ( nOffset != 0 )
  {
    v5 = (this->m_dwRowAlignment & 0xA000) == 0;
    rectBarWnd = pControlBar->m_rectBar;
    if ( v5 )
    {
      if ( !bForward )
        v4 = -nOffset;
      OffsetRect(lprc: &rectBarWnd, dx: 0, dy: v4);
    }
    else
    {
      if ( !bForward )
        v4 = -nOffset;
      OffsetRect(lprc: &rectBarWnd, dx: v4, dy: 0);
    }
    pControlBar->m_rectBar = rectBarWnd;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10413465
// Name: public: virtual void CDockingPanesRow::AddPane(class CPane __near *,enum AFX_DOCK_METHOD,struct tagRECT const __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockingPanesRow::AddPane(
        CDockingPanesRow *this,
        CPane *pControlBar,
        AFX_DOCK_METHOD __formal,
        const tagRECT *lpRect,
        int bAddLast)
{
  CDockSite *m_pParentDockBar; // eax
  unsigned int m_dwRowAlignment; // eax
  int v8; // edi
  int m_nRowOffset; // ebx
  int v10; // ebx
  int PaneOffset; // eax
  bool v12; // al
  CSize szBarSize; // [esp+Ch] [ebp-44h] BYREF
  CPane *v14; // [esp+14h] [ebp-3Ch]
  int v15; // [esp+18h] [ebp-38h]
  CRect rectOrg; // [esp+1Ch] [ebp-34h] BYREF
  CRect rectDockBar; // [esp+2Ch] [ebp-24h] BYREF
  CRect rectRow; // [esp+3Ch] [ebp-14h] BYREF

  v14 = pControlBar;
  memset(&rectRow, 0, sizeof(rectRow));
  if ( lpRect == nullptr || IsRectEmpty(lprc: lpRect) )
  {
    v10 = 0;
    if ( bAddLast != 0 )
    {
      PaneOffset = CDockingPanesRow::CalcLastPaneOffset(this);
      v10 = PaneOffset;
      if ( PaneOffset > 0 )
        v10 = afxGlobalData.m_nAutoHideToolBarSpacing + PaneOffset;
    }
    CDockingPanesRow::GetClientRect(this, rect: &rectRow);
    m_dwRowAlignment = this->m_dwRowAlignment;
    v15 = m_dwRowAlignment & 0x2000;
    if ( (m_dwRowAlignment & 0x2000) != 0 || (m_dwRowAlignment & 0x8000) != 0 )
    {
      v8 = v10 + rectRow.left;
      m_nRowOffset = this->m_nRowOffset;
      if ( this->m_nExtraAlignment == 1 )
        m_nRowOffset += this->m_nExtraSpace;
    }
    else
    {
      m_nRowOffset = rectRow.top + v10;
      v8 = this->m_nRowOffset;
      if ( this->m_nExtraAlignment == 1 )
        v8 += this->m_nExtraSpace;
    }
  }
  else
  {
    CopyRect(lprcDst: &rectOrg, lprcSrc: lpRect);
    m_pParentDockBar = this->m_pParentDockBar;
    memset(&rectDockBar, 0, sizeof(rectDockBar));
    GetClientRect(hWnd: m_pParentDockBar->m_hWnd, lpRect: &rectDockBar);
    CDockingPanesRow::GetWindowRect(this, rect: &rectRow);
    CWnd::ScreenToClient(this: this->m_pParentDockBar, lpRect: &rectOrg);
    CWnd::ScreenToClient(this: this->m_pParentDockBar, lpRect: &rectRow);
    m_dwRowAlignment = this->m_dwRowAlignment;
    v15 = m_dwRowAlignment & 0x2000;
    if ( (m_dwRowAlignment & 0x2000) != 0 || (m_dwRowAlignment & 0x8000) != 0 )
    {
      v8 = rectOrg.left - rectRow.left;
      m_nRowOffset = rectDockBar.top + this->m_nRowOffset;
    }
    else
    {
      v8 = rectDockBar.left + this->m_nRowOffset;
      m_nRowOffset = rectOrg.top - rectRow.top;
    }
  }
  v12 = v15 != 0 || (m_dwRowAlignment & 0x8000) != 0;
  v14->CalcFixedLayout(this: v14, result: &szBarSize, a3: 0, a4: v12);
  v14->SetWindowPos(
    this: v14,
    a2: nullptr,
    a3: v8,
    a4: m_nRowOffset,
    a5: szBarSize.cx,
    a6: szBarSize.cy,
    a7: 52u,
    a8: nullptr);
  this->OnInsertPane(this, a2: v14);
  CPane::UpdateVirtualRect(this: v14);
}

//------------------------------------------------------------------------------
// Address: 0x104135E6
// Name: public: virtual void CDockingPanesRow::RemovePane(class CPane __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockingPanesRow::RemovePane(CDockingPanesRow *this, CPane *pControlBar)
{
  CPane *v2; // esi
  CPane_vtbl *v4; // eax
  void *m_pNodeHead; // eax
  int MaxPaneSize; // eax
  int v7; // esi
  CPane *v8; // ecx
  CPane_vtbl *v9; // eax
  void *hdwp; // [esp+10h] [ebp-34h] BYREF
  void *__formal; // [esp+14h] [ebp-30h] BYREF
  CPane *v12; // [esp+18h] [ebp-2Ch]
  __POSITION *pos; // [esp+1Ch] [ebp-28h]
  tagRECT Rect; // [esp+20h] [ebp-24h] BYREF
  CRect rectVirtual; // [esp+30h] [ebp-14h] BYREF

  v2 = pControlBar;
  pos = CPtrList::Find(this: &this->m_lstControlBars, searchValue: pControlBar, startAfter: nullptr);
  if ( pos != nullptr )
  {
    v4 = pControlBar->__vftable;
    hdwp = nullptr;
    v4->StretchPaneDeferWndPos(this: pControlBar, a2: 0xFFFF, a3: &hdwp);
    CPtrList::RemoveAt(this: &this->m_lstControlBars, position: pos);
    pControlBar->m_pDockBarRow = nullptr;
    if ( this->m_lstControlBars.m_nCount != 0 )
    {
      m_pNodeHead = this->m_lstControlBars.m_pNodeHead;
      if ( m_pNodeHead != nullptr )
      {
        while ( 1 )
        {
          pos = *(__POSITION **)m_pNodeHead;
          v8 = *((CPane **)m_pNodeHead + 2);
          v9 = v8->__vftable;
          v12 = v8;
          if ( (((int (*)(void))v9->IsVisible)() != 0 || this->m_bIgnoreBarVisibility != 0) && v12 != v2 )
          {
            memset(&Rect, 0, sizeof(Rect));
            GetWindowRect(hWnd: v12->m_hWnd, lpRect: &Rect);
            memset(&rectVirtual, 0, sizeof(rectVirtual));
            CPane::GetVirtualRect(this: v12, &rectVirtual);
            if ( !EqualRect(lprc1: &rectVirtual, lprc2: &Rect) )
            {
              __formal = BeginDeferWindowPos(nNumWindows: this->m_lstControlBars.m_nCount);
              CDockingPanesRow::MovePane(this, pControlBar: v12, rectTarget: rectVirtual, &__formal);
              EndDeferWindowPos(hWinPosInfo: __formal);
              v2 = pControlBar;
            }
          }
          if ( pos == nullptr )
            break;
          m_pNodeHead = pos;
        }
      }
      CDockingPanesRow::ExpandStretchedPanes(this, a2: 0);
      this->UpdateVisibleState(this, a2: 0);
      MaxPaneSize = CDockingPanesRow::GetMaxPaneSize(this, bSkipHiddenBars: 0);
      v7 = MaxPaneSize;
      if ( MaxPaneSize < this->m_nRowHeight )
      {
        CDockSite::ResizeRow(this: this->m_pParentDockBar, pRow: this, nNewSize: MaxPaneSize, bAdjustLayout: 1);
        this->m_nRowHeight = v7;
      }
    }
    else
    {
      CDockSite::RemoveRow(this: this->m_pParentDockBar, pRow: this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10413759
// Name: public: virtual int CDockingPanesRow::ShowPane(class CPane __near *,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDockingPanesRow::ShowPane(CDockingPanesRow *this, CPane *pControlBar, int bShow, int bDelay)
{
  int result; // eax
  CRect rect; // [esp+Ch] [ebp-14h] BYREF

  result = (int)CPtrList::Find(this: &this->m_lstControlBars, searchValue: pControlBar, startAfter: nullptr);
  if ( result != 0 )
  {
    CWnd::ShowWindow(this: pControlBar, nCmdShow: bShow != 0 ? 5 : 0);
    this->UpdateVisibleState(this, a2: bDelay);
    if ( bShow != 0 )
    {
      if ( bDelay != 0 )
        return 1;
      pControlBar->AdjustLayout(this: pControlBar);
      this->ArrangePanes(this, a2: pControlBar);
    }
    else
    {
      CDockingPanesRow::ExpandStretchedPanes(this, a2: (int)pControlBar);
    }
    if ( bDelay == 0 )
    {
      memset(&rect, 0, sizeof(rect));
      CDockingPanesRow::GetClientRect(this, &rect);
      this->m_pParentDockBar->RepositionPanes(this: this->m_pParentDockBar, a2: &rect);
      this->RepositionPanes(this, a2: &rect, a3: -1u, a4: 0, a5: 0);
    }
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10413812
// Name: private: void CDockingPanesRow::MoveTrailingPanes(struct __POSITION __near *,class CPoint,bool,class CPane __near *,void __near * __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockingPanesRow::MoveTrailingPanes(
        CDockingPanesRow *this,
        __POSITION *posStart,
        CPoint ptOffset,
        bool bForward,
        CPane *pBarToSkip,
        void **hdwp)
{
  __POSITION *v6; // eax
  __POSITION *v7; // ecx
  CPane *v8; // ebx
  bool IsLeftOf; // al
  int v10; // esi
  int v11; // eax
  int v12; // esi
  int x; // [esp-4h] [ebp-40h]
  __POSITION *pos; // [esp+Ch] [ebp-30h]
  int nOffsetToMove; // [esp+14h] [ebp-28h]
  CRect rectNextControlBar; // [esp+18h] [ebp-24h] BYREF
  CRect rectNextControlBarVirt; // [esp+28h] [ebp-14h] BYREF

  v6 = posStart;
  memset(&rectNextControlBar, 0, sizeof(rectNextControlBar));
  memset(&rectNextControlBarVirt, 0, sizeof(rectNextControlBarVirt));
  if ( posStart != nullptr )
  {
    while ( 1 )
    {
      if ( bForward )
      {
        if ( v6 == nullptr )
          goto LABEL_32;
        v7 = *(__POSITION **)&v6[4];
      }
      else
      {
        if ( v6 == nullptr )
LABEL_32:
          AfxThrowInvalidArgException();
        v7 = *(__POSITION **)v6;
      }
      v8 = *(CPane **)&v6[8];
      pos = v7;
      if ( v8 != pBarToSkip && (v8->IsVisible(this: v8) != 0 || this->m_bIgnoreBarVisibility != 0) )
      {
        GetWindowRect(hWnd: v8->m_hWnd, lpRect: &rectNextControlBar);
        CPane::GetVirtualRect(this: v8, rectVirtual: &rectNextControlBarVirt);
        if ( !EqualRect(lprc1: &rectNextControlBar, lprc2: &rectNextControlBarVirt) )
          break;
      }
LABEL_30:
      if ( pos == nullptr )
        return;
      v6 = pos;
    }
    nOffsetToMove = 0;
    IsLeftOf = CPane::IsLeftOf(this: v8, rect: rectNextControlBarVirt, bWindowRect: true);
    if ( bForward )
    {
      if ( !IsLeftOf )
      {
        if ( CPane::IsLeftOf(this: v8, rect: rectNextControlBarVirt, bWindowRect: true) )
          goto LABEL_29;
LABEL_22:
        if ( (this->m_dwRowAlignment & 0xA000) != 0 )
        {
          v10 = abs(lnumber: ptOffset.x);
          if ( v10 >= abs(lnumber: rectNextControlBarVirt.left - rectNextControlBar.left) )
          {
            v11 = rectNextControlBarVirt.left - rectNextControlBar.left;
LABEL_27:
            x = v11;
            goto LABEL_28;
          }
          goto LABEL_19;
        }
        v12 = abs(lnumber: ptOffset.y);
        if ( v12 >= abs(lnumber: rectNextControlBarVirt.top - rectNextControlBar.top) )
        {
          v11 = rectNextControlBarVirt.top - rectNextControlBar.top;
          goto LABEL_27;
        }
        goto LABEL_20;
      }
    }
    else if ( IsLeftOf )
    {
      if ( !CPane::IsLeftOf(this: v8, rect: rectNextControlBarVirt, bWindowRect: true) )
      {
LABEL_29:
        CDockingPanesRow::MovePane(this, pControlBar: v8, nOffset: nOffsetToMove, bForward, __formal: hdwp);
        CDockingPanesRow::ResolveIntersection(this, pBar: v8, bForward: !bForward, hdwp);
        goto LABEL_30;
      }
      goto LABEL_22;
    }
    if ( (this->m_dwRowAlignment & 0xA000) != 0 )
    {
LABEL_19:
      x = ptOffset.x;
LABEL_28:
      nOffsetToMove = abs(lnumber: x);
      goto LABEL_29;
    }
LABEL_20:
    x = ptOffset.y;
    goto LABEL_28;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104139E1
// Name: public: virtual void CDockingPanesRow::ArrangePanes(class CPane __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockingPanesRow::ArrangePanes(CDockingPanesRow *this, CPane *pInitialBar)
{
  CPane *data; // edi
  CDockingPanesRow_vtbl *v4; // eax
  __POSITION *v5; // eax
  bool v6; // zf
  CPane *FirstVisiblePane; // edi
  int OutOfBoundsOffset; // eax
  int v9; // edi
  int v10; // eax
  void *m_pNodeTail; // eax
  __POSITION *v12; // ecx
  CPane *v13; // edi
  CPane_vtbl *v14; // eax
  int v15; // edi
  int v16; // eax
  HWND m_hWnd; // [esp-8h] [ebp-4Ch]
  int nRetSize; // [esp+Ch] [ebp-38h]
  CPane *pPrevBar; // [esp+10h] [ebp-34h]
  CPane *pPrevBara; // [esp+10h] [ebp-34h]
  __POSITION *nStretchSize; // [esp+14h] [ebp-30h]
  void *hdwp; // [esp+18h] [ebp-2Ch] BYREF
  __POSITION *pos; // [esp+1Ch] [ebp-28h]
  CRect rectRow; // [esp+20h] [ebp-24h] BYREF
  CRect rectBar; // [esp+30h] [ebp-14h] BYREF

  data = pInitialBar;
  if ( this->m_lstControlBars.m_nCount != 0 )
  {
    memset(&rectRow, 0, sizeof(rectRow));
    CDockingPanesRow::GetClientRect(this, rect: &rectRow);
    if ( !IsRectEmpty(lprc: &rectRow) )
    {
      v4 = this->__vftable;
      hdwp = nullptr;
      v5 = (__POSITION *)v4->GetAvailableLength(this, a2: 0);
      v6 = this->m_lstControlBars.m_nCount == 1;
      pos = v5;
      if ( !v6 )
        goto LABEL_12;
      if ( pInitialBar == nullptr )
        data = (CPane *)this->m_lstControlBars.m_pNodeHead->data;
      if ( (int)v5 < 0 )
      {
        data->StretchPaneDeferWndPos(this: data, a2: (int)v5, a3: &hdwp);
        m_hWnd = data->m_hWnd;
        memset(&rectBar, 0, sizeof(rectBar));
        GetWindowRect(hWnd: m_hWnd, lpRect: &rectBar);
        CWnd::ScreenToClient(this: this->m_pParentDockBar, lpRect: &rectBar);
        if ( (this->m_dwRowAlignment & 0xA000) != 0 )
          OffsetRect(lprc: &rectBar, dx: -rectBar.left, dy: this->m_nRowOffset - rectBar.top);
        else
          OffsetRect(lprc: &rectBar, dx: this->m_nRowOffset - rectBar.left, dy: -rectBar.top);
        data->SetWindowPos(
          this: data,
          a2: nullptr,
          a3: rectBar.left,
          a4: rectBar.top,
          a5: rectBar.right - rectBar.left,
          a6: rectBar.bottom - rectBar.top,
          a7: 20u,
          a8: nullptr);
      }
      else
      {
LABEL_12:
        if ( data != nullptr )
          CDockingPanesRow::ResolveIntersection(this, pBar: data, bForward: false, &hdwp);
        else
          data = (CPane *)this->m_lstControlBars.m_pNodeHead->data;
        CDockingPanesRow::ResolveIntersection(this, pBar: data, bForward: true, &hdwp);
        FirstVisiblePane = CDockingPanesRow::FindFirstVisiblePane(this, bForward: 1);
        OutOfBoundsOffset = CDockingPanesRow::GetOutOfBoundsOffset(this, pBar: FirstVisiblePane, bLeftTopBound: 1);
        if ( OutOfBoundsOffset > 0 )
          CDockingPanesRow::ShiftPanes(this, pControlBar: FirstVisiblePane, nOffset: OutOfBoundsOffset, bForward: 1);
        pPrevBar = CDockingPanesRow::FindFirstVisiblePane(this, bForward: 0);
        v9 = CDockingPanesRow::GetOutOfBoundsOffset(this, pBar: pPrevBar, bLeftTopBound: 0);
        if ( v9 > 0 )
        {
          if ( (int)pos <= 0 )
          {
            nStretchSize = pos;
            v10 = abs(lnumber: (int)pos);
            CDockingPanesRow::ShiftPanes(this, pControlBar: pPrevBar, nOffset: v10 - v9, bForward: 0);
            if ( (int)pos < 0 )
            {
              m_pNodeTail = this->m_lstControlBars.m_pNodeTail;
              if ( m_pNodeTail != nullptr )
              {
                while ( 1 )
                {
                  v12 = *((__POSITION **)m_pNodeTail + 1);
                  v13 = *((CPane **)m_pNodeTail + 2);
                  v14 = v13->__vftable;
                  pos = v12;
                  pPrevBara = v13;
                  if ( v14->IsVisible(this: v13) != 0 || this->m_bIgnoreBarVisibility != 0 )
                  {
                    nRetSize = v13->StretchPaneDeferWndPos(this: v13, a2: (int)nStretchSize, a3: &hdwp);
                    v15 = abs(lnumber: nRetSize);
                    v16 = abs(lnumber: (int)nStretchSize);
                    CDockingPanesRow::MovePane(
                      this,
                      pControlBar: pPrevBara,
                      nOffset: v16 - v15,
                      bForward: false,
                      __formal: &hdwp);
                    if ( (__POSITION *)nRetSize == nStretchSize )
                      return;
                    nStretchSize -= nRetSize;
                  }
                  if ( pos == nullptr )
                    break;
                  m_pNodeTail = pos;
                }
              }
            }
          }
          else
          {
            CDockingPanesRow::ShiftPanes(this, pControlBar: pPrevBar, nOffset: -v9, bForward: 0);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10413C15
// Name: protected: void CDockingPanesRow::ResolveIntersectionRect(class CPane __near *,bool)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockingPanesRow::ResolveIntersectionRect(CDockingPanesRow *this, CPane *pBar, bool bForward)
{
  __POSITION *v4; // ebx
  __POSITION *v5; // eax
  int v6; // edi
  __POSITION *v7; // esi
  __POSITION *v8; // eax
  _DWORD *v9; // edi
  CPane *v10; // eax
  CDockingPanesRow *v11; // ebx
  unsigned int m_dwRowAlignment; // eax
  int v13; // eax
  int v14; // edx
  int rectMovedBar; // [esp+Ch] [ebp-40h]
  int rectMovedBar_4; // [esp+10h] [ebp-3Ch]
  int rectMovedBar_8; // [esp+14h] [ebp-38h]
  int rectMovedBar_12; // [esp+18h] [ebp-34h]
  __POSITION *posSave; // [esp+1Ch] [ebp-30h]
  CPane *pMovedBar; // [esp+24h] [ebp-28h]
  CRect rectRowWnd; // [esp+28h] [ebp-24h] BYREF
  CRect rectBarWnd; // [esp+38h] [ebp-14h] BYREF

  v4 = CPtrList::Find(this: &this->m_lstControlBars, searchValue: pBar, startAfter: nullptr);
  memset(&rectBarWnd, 0, sizeof(rectBarWnd));
  SetRectEmpty(lprc: &rectBarWnd);
  memset(&rectRowWnd, 0, sizeof(rectRowWnd));
  CDockingPanesRow::GetWindowRect(this, rect: &rectRowWnd);
  while ( v4 != nullptr )
  {
    v5 = v4;
    if ( bForward )
      v4 = *(__POSITION **)v4;
    else
      v4 = *(__POSITION **)&v4[4];
    v6 = *(_DWORD *)&v5[8];
    if ( (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 376))(a1: v6) != 0 || this->m_bIgnoreBarVisibility != 0 )
    {
      rectBarWnd = *(CRect *)(v6 + 156);
      v7 = v4;
      if ( v4 == nullptr )
        return;
      do
      {
        posSave = v7;
        v8 = v7;
        if ( bForward )
        {
          if ( v7 == nullptr )
            goto LABEL_43;
          v9 = *(_DWORD **)&v7[8];
          v7 = *(__POSITION **)v7;
          pMovedBar = *(CPane **)&v8[8];
        }
        else
        {
          if ( v7 == nullptr )
LABEL_43:
            AfxThrowInvalidArgException();
          v10 = *(CPane **)&v7[8];
          v7 = *(__POSITION **)&v7[4];
          pMovedBar = v10;
          v9 = &v10->__vftable;
        }
        if ( (*(int (__thiscall **)(_DWORD *))(*v9 + 376))(a1: v9) != 0 )
          break;
        v11 = this;
        if ( this->m_bIgnoreBarVisibility != 0 )
          goto LABEL_17;
      }
      while ( v7 != nullptr );
      v11 = this;
LABEL_17:
      m_dwRowAlignment = v11->m_dwRowAlignment;
      rectMovedBar = v9[39];
      rectMovedBar_4 = v9[40];
      rectMovedBar_8 = v9[41];
      rectMovedBar_12 = v9[42];
      if ( bForward )
      {
        if ( (m_dwRowAlignment & 0x2000) == 0 && (m_dwRowAlignment & 0x8000) == 0 || rectMovedBar <= rectBarWnd.right )
        {
          if ( (m_dwRowAlignment & 0x2000) != 0 )
            goto LABEL_26;
          if ( (m_dwRowAlignment & 0x8000) != 0 || rectMovedBar_4 <= rectBarWnd.bottom )
          {
            if ( (m_dwRowAlignment & 0x2000) != 0 || (m_dwRowAlignment & 0x8000) != 0 )
            {
LABEL_26:
              v13 = rectBarWnd.right - rectMovedBar;
LABEL_39:
              CDockingPanesRow::MovePaneRect(this: v11, pControlBar: pMovedBar, nOffset: v13, bForward);
              goto LABEL_40;
            }
            v14 = rectBarWnd.bottom - rectMovedBar_4;
            goto LABEL_38;
          }
        }
      }
      else if ( (m_dwRowAlignment & 0x2000) == 0 && (m_dwRowAlignment & 0x8000) == 0
             || rectMovedBar_8 >= rectBarWnd.left )
      {
        if ( (m_dwRowAlignment & 0x2000) != 0 )
          goto LABEL_35;
        if ( (m_dwRowAlignment & 0x8000) != 0 || rectMovedBar_12 >= rectBarWnd.top )
        {
          if ( (m_dwRowAlignment & 0x2000) != 0 || (m_dwRowAlignment & 0x8000) != 0 )
          {
LABEL_35:
            v13 = rectMovedBar_8 - rectBarWnd.left;
            goto LABEL_39;
          }
          v14 = rectMovedBar_12 - rectBarWnd.top;
LABEL_38:
          v13 = v14;
          goto LABEL_39;
        }
      }
LABEL_40:
      v4 = posSave;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10413DDC
// Name: protected: int CDockingPanesRow::CheckPanes(class CRect __near &,class CPane __near *,bool,class CPoint,int,void __near * __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDockingPanesRow::CheckPanes(
        CDockingPanesRow *this,
        CRect *rectCurrentBar,
        CPane *pCurrentBar,
        bool bForward,
        CPoint ptOffset,
        int bSwapControlBars,
        void **hdwp)
{
  CDockingPanesRow *v7; // esi
  __POSITION *v8; // eax
  CObList::CNode *m_pNodeHead; // edi
  CPane *data; // ecx
  bool IsLeftOf; // al
  int v12; // eax
  CObList *p_m_lstControlBars; // ecx
  CDockingPanesRow *v14; // esi
  __POSITION *v15; // eax
  __POSITION *v16; // ecx
  CPane *v17; // edi
  unsigned int m_dwRowAlignment; // eax
  int v19; // esi
  int v20; // eax
  __POSITION *posIntersect; // [esp+Ch] [ebp-90h]
  CPane *pNextBar; // [esp+20h] [ebp-7Ch]
  __POSITION *posCurrentBar; // [esp+2Ch] [ebp-70h]
  __POSITION *pos; // [esp+34h] [ebp-68h]
  CRect rectIntersectVirt; // [esp+38h] [ebp-64h] BYREF
  CRect rectVirt; // [esp+48h] [ebp-54h] BYREF
  CRect rectWnd; // [esp+58h] [ebp-44h] BYREF
  CRect rectNextControlBarVirt; // [esp+68h] [ebp-34h] BYREF
  CRect rectIntersect; // [esp+78h] [ebp-24h] BYREF
  CRect rectNextControlBar; // [esp+88h] [ebp-14h] BYREF
  CRect rectNew; // 0:^28.16

  v7 = this;
  if ( this->m_lstControlBars.m_nCount < 2 || this->GetVisibleCount(this) < 2 )
    return 1;
  memset(&rectNextControlBar, 0, sizeof(rectNextControlBar));
  memset(&rectNextControlBarVirt, 0, sizeof(rectNextControlBarVirt));
  memset(&rectIntersect, 0, sizeof(rectIntersect));
  v8 = CPtrList::Find(this: &v7->m_lstControlBars, searchValue: pCurrentBar, startAfter: nullptr);
  m_pNodeHead = v7->m_lstControlBars.m_pNodeHead;
  posCurrentBar = v8;
  if ( m_pNodeHead == nullptr )
  {
LABEL_62:
    CDockingPanesRow::MoveTrailingPanes(
      this: v7,
      posStart: posCurrentBar,
      ptOffset,
      bForward,
      pBarToSkip: pCurrentBar,
      hdwp);
    return 1;
  }
  while ( 1 )
  {
    posIntersect = (__POSITION *)m_pNodeHead;
    data = (CPane *)m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    pNextBar = data;
    if ( (((int (*)(void))data->IsVisible)() != 0 || v7->m_bIgnoreBarVisibility != 0) && pNextBar != pCurrentBar )
    {
      GetWindowRect(hWnd: pNextBar->m_hWnd, lpRect: &rectNextControlBar);
      if ( IntersectRect(lprcDst: &rectIntersect, lprcSrc1: &rectNextControlBar, lprcSrc2: rectCurrentBar) )
        break;
    }
    if ( m_pNodeHead == nullptr )
      goto LABEL_62;
  }
  CPane::GetVirtualRect(this: pNextBar, rectVirtual: &rectNextControlBarVirt);
  memset(&rectIntersectVirt, 0, sizeof(rectIntersectVirt));
  if ( !IntersectRect(lprcDst: &rectIntersectVirt, lprcSrc1: &rectNextControlBarVirt, lprcSrc2: rectCurrentBar)
    || bSwapControlBars == 0 )
  {
LABEL_15:
    if ( (v7->m_dwRowAlignment & 0xA000) != 0 )
      v12 = rectIntersect.right - rectIntersect.left;
    else
      v12 = rectIntersect.bottom - rectIntersect.top;
    CDockingPanesRow::MovePane(this: v7, pControlBar: pNextBar, nOffset: v12, bForward, __formal: hdwp);
    CDockingPanesRow::ResolveIntersection(this: v7, pBar: pNextBar, bForward, hdwp);
    goto LABEL_62;
  }
  IsLeftOf = CPane::IsLeftOf(this: pCurrentBar, rect: rectNextControlBarVirt, bWindowRect: true);
  if ( bForward )
  {
    if ( !IsLeftOf )
    {
LABEL_14:
      v7 = this;
      goto LABEL_15;
    }
  }
  else if ( IsLeftOf )
  {
    goto LABEL_14;
  }
  rectNew = rectNextControlBar;
  if ( (this->m_dwRowAlignment & 0xA000) != 0 )
  {
    if ( bForward )
      rectNew.right = rectCurrentBar->left;
    else
      rectNew.left = rectCurrentBar->right;
    if ( bForward )
      rectNew.left = rectNew.right + rectNextControlBar.left - rectNextControlBar.right;
    else
      rectNew.right = rectNew.left + rectNextControlBar.right - rectNextControlBar.left;
  }
  else
  {
    if ( bForward )
      rectNew.bottom = rectCurrentBar->top;
    else
      rectNew.top = rectCurrentBar->bottom;
    if ( bForward )
      rectNew.top = rectNew.bottom + rectNextControlBar.top - rectNextControlBar.bottom;
    else
      rectNew.bottom = rectNew.top + rectNextControlBar.bottom - rectNextControlBar.top;
  }
  CDockingPanesRow::MovePane(this, pControlBar: pNextBar, rectTarget: rectNew, __formal: hdwp);
  CPtrList::RemoveAt(this: &this->m_lstControlBars, position: posIntersect);
  p_m_lstControlBars = &this->m_lstControlBars;
  if ( bForward )
    CObList::InsertBefore(this: p_m_lstControlBars, position: posCurrentBar, newElement: pNextBar);
  else
    CObList::InsertAfter(this: p_m_lstControlBars, position: posCurrentBar, newElement: pNextBar);
  v14 = this;
  CDockingPanesRow::ResolveIntersection(this, pBar: pNextBar, bForward: !bForward, hdwp);
  memset(&rectWnd, 0, sizeof(rectWnd));
  memset(&rectVirt, 0, sizeof(rectVirt));
  if ( bForward )
  {
    if ( posCurrentBar != nullptr )
    {
      v15 = *(__POSITION **)posCurrentBar;
      goto LABEL_40;
    }
LABEL_17:
    AfxThrowInvalidArgException();
  }
  if ( posCurrentBar == nullptr )
    goto LABEL_17;
  v15 = *(__POSITION **)&posCurrentBar[4];
LABEL_40:
  if ( v15 != nullptr )
  {
    while ( 1 )
    {
      if ( bForward )
        v16 = *(__POSITION **)v15;
      else
        v16 = *(__POSITION **)&v15[4];
      v17 = *(CPane **)&v15[8];
      pos = v16;
      if ( v17->IsVisible(this: v17) != 0 || v14->m_bIgnoreBarVisibility != 0 )
      {
        GetWindowRect(hWnd: v17->m_hWnd, lpRect: &rectWnd);
        CPane::GetVirtualRect(this: v17, rectVirtual: &rectVirt);
        if ( !EqualRect(lprc1: &rectWnd, lprc2: &rectVirt) )
        {
          m_dwRowAlignment = v14->m_dwRowAlignment;
          if ( (m_dwRowAlignment & 0x2000) != 0 || (m_dwRowAlignment & 0x8000) != 0 )
            v19 = rectNew.right - rectNew.left;
          else
            v19 = rectNew.bottom - rectNew.top;
          if ( (m_dwRowAlignment & 0x2000) != 0 || (m_dwRowAlignment & 0x8000) != 0 )
            v20 = abs(lnumber: ptOffset.x);
          else
            v20 = abs(lnumber: ptOffset.y);
          CDockingPanesRow::MovePane(this, pControlBar: v17, nOffset: v19 - v20, bForward: !bForward, __formal: hdwp);
          v14 = this;
        }
      }
      if ( pos == nullptr )
        break;
      v15 = pos;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1041418E
// Name: protected: void CDockingPanesRow::ArrangePanesRect(class CPane __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockingPanesRow::ArrangePanesRect(CDockingPanesRow *this, CPane *pInitialBar)
{
  CPane *data; // edi
  int AvailableLengthRect; // eax
  bool v5; // zf
  CPane *FirstVisiblePane; // edi
  int OutOfBoundsOffsetRect; // eax
  int v8; // edi
  int v9; // eax
  void *m_pNodeTail; // ebx
  CPane *v11; // edi
  CPane_vtbl *v12; // eax
  int v13; // ebx
  int v14; // eax
  void *hdwp; // [esp+Ch] [ebp-24h] BYREF
  __POSITION *pos; // [esp+10h] [ebp-20h]
  int nRetSize; // [esp+14h] [ebp-1Ch]
  int nStretchSize; // [esp+18h] [ebp-18h]
  CRect rectRow; // [esp+1Ch] [ebp-14h] BYREF

  data = pInitialBar;
  if ( this->m_lstControlBars.m_nCount != 0 )
  {
    memset(&rectRow, 0, sizeof(rectRow));
    CDockingPanesRow::GetClientRect(this, rect: &rectRow);
    if ( !IsRectEmpty(lprc: &rectRow) )
    {
      hdwp = nullptr;
      AvailableLengthRect = CDockingPanesRow::GetAvailableLengthRect(this);
      v5 = this->m_lstControlBars.m_nCount == 1;
      nRetSize = AvailableLengthRect;
      if ( !v5 )
        goto LABEL_9;
      if ( pInitialBar == nullptr )
        data = (CPane *)this->m_lstControlBars.m_pNodeHead->data;
      if ( AvailableLengthRect < 0 )
      {
        CDockingPanesRow::StretchPaneRect(this, pBar: data, nStretchSize: AvailableLengthRect);
      }
      else
      {
LABEL_9:
        if ( data != nullptr )
          CDockingPanesRow::ResolveIntersectionRect(this, pBar: data, bForward: false);
        else
          data = (CPane *)this->m_lstControlBars.m_pNodeHead->data;
        CDockingPanesRow::ResolveIntersectionRect(this, pBar: data, bForward: true);
        FirstVisiblePane = CDockingPanesRow::FindFirstVisiblePane(this, bForward: 1);
        OutOfBoundsOffsetRect = CDockingPanesRow::GetOutOfBoundsOffsetRect(
                                  this,
                                  pBar: FirstVisiblePane,
                                  bLeftTopBound: 1);
        if ( OutOfBoundsOffsetRect > 0 )
          CDockingPanesRow::ShiftPanesRect(
            this,
            pControlBar: FirstVisiblePane,
            nOffset: OutOfBoundsOffsetRect,
            bForward: 1);
        pos = (__POSITION *)CDockingPanesRow::FindFirstVisiblePane(this, bForward: 0);
        v8 = CDockingPanesRow::GetOutOfBoundsOffsetRect(this, pBar: (CPane *)pos, bLeftTopBound: 0);
        if ( v8 > 0 )
        {
          if ( nRetSize <= 0 )
          {
            nStretchSize = nRetSize;
            v9 = abs(lnumber: nRetSize);
            CDockingPanesRow::ShiftPanesRect(this, pControlBar: (CPane *)pos, nOffset: v9 - v8, bForward: 0);
            if ( nRetSize < 0 )
            {
              m_pNodeTail = this->m_lstControlBars.m_pNodeTail;
              while ( m_pNodeTail != nullptr )
              {
                v11 = *((CPane **)m_pNodeTail + 2);
                m_pNodeTail = *((void **)m_pNodeTail + 1);
                v12 = v11->__vftable;
                pos = (__POSITION *)m_pNodeTail;
                if ( v12->IsVisible(this: v11) != 0 || this->m_bIgnoreBarVisibility != 0 )
                {
                  nRetSize = v11->StretchPaneDeferWndPos(this: v11, a2: nStretchSize, a3: &hdwp);
                  v13 = abs(lnumber: nRetSize);
                  v14 = abs(lnumber: nStretchSize);
                  CDockingPanesRow::MovePaneRect(this, pControlBar: v11, nOffset: v14 - v13, bForward: false);
                  if ( nRetSize == nStretchSize )
                    return;
                  nStretchSize -= nRetSize;
                  m_pNodeTail = pos;
                }
              }
            }
          }
          else
          {
            CDockingPanesRow::ShiftPanesRect(this, pControlBar: (CPane *)pos, nOffset: -v8, bForward: 0);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1041431F
// Name: public: void CDockingPanesRow::ExpandStretchedPanesRect(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockingPanesRow::ExpandStretchedPanesRect(CDockingPanesRow *this)
{
  int AvailableLengthRect; // eax
  CObList::CNode *m_pNodeHead; // esi
  CPane *data; // ebx
  int nAvailableLen; // [esp+4h] [ebp-4h]

  if ( this->m_lstControlBars.m_nCount != 0 )
  {
    CDockingPanesRow::BeginTrans(this);
    AvailableLengthRect = CDockingPanesRow::GetAvailableLengthRect(this);
    m_pNodeHead = this->m_lstControlBars.m_pNodeHead;
    nAvailableLen = AvailableLengthRect;
    while ( m_pNodeHead != nullptr )
    {
      data = (CPane *)m_pNodeHead->data;
      m_pNodeHead = m_pNodeHead->pNext;
      if ( data->IsVisible(this: data) != 0 || this->m_bIgnoreBarVisibility != 0 )
      {
        nAvailableLen -= CDockingPanesRow::StretchPaneRect(this, pBar: data, nStretchSize: nAvailableLen);
        if ( nAvailableLen <= 0 )
          break;
      }
    }
    CDockingPanesRow::ArrangePanesRect(this, pInitialBar: nullptr);
    CDockingPanesRow::CommitTrans(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10414397
// Name: public: void CDockingPanesRow::MovePane(class CPane __near *,class CPoint,int,void __near * __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockingPanesRow::MovePane(
        CDockingPanesRow *this,
        CPane *pControlBar,
        CPoint ptOffset,
        int bSwapControlBars,
        void **hdwp)
{
  int x; // eax
  int v7; // eax
  int v8; // esi
  HWND__ *m_hWnd; // [esp-8h] [ebp-60h]
  bool bForward; // [esp+10h] [ebp-48h]
  int v11; // [esp+14h] [ebp-44h]
  int nAllowedOffset; // [esp+18h] [ebp-40h] BYREF
  CPoint ptMove; // [esp+1Ch] [ebp-3Ch]
  CRect rectVirualNew; // [esp+24h] [ebp-34h] BYREF
  CRect rectVirtual; // [esp+34h] [ebp-24h] BYREF
  CRect rectBarWnd; // [esp+44h] [ebp-14h] BYREF

  memset(&rectVirtual, 0, sizeof(rectVirtual));
  CPane::GetVirtualRect(this: pControlBar, &rectVirtual);
  m_hWnd = pControlBar->m_hWnd;
  memset(&rectBarWnd, 0, sizeof(rectBarWnd));
  GetWindowRect(hWnd: m_hWnd, lpRect: &rectBarWnd);
  rectVirualNew = rectVirtual;
  OffsetRect(lprc: &rectVirualNew, dx: ptOffset.x, dy: ptOffset.y);
  ptMove.x = 0;
  ptMove.y = 0;
  if ( (this->m_dwRowAlignment & 0xA000) != 0 )
  {
    x = ptOffset.x;
    ptMove.x = ptOffset.x;
  }
  else
  {
    x = ptOffset.y;
    ptMove.y = ptOffset.y;
  }
  nAllowedOffset = x;
  bForward = x >= 0;
  if ( CDockingPanesRow::IsEnoughSpaceToMove(this, pControlBar, bForward: x >= 0, &nAllowedOffset) == 0 )
    return;
  if ( (this->m_dwRowAlignment & 0xA000) == 0 )
    goto LABEL_9;
  v11 = abs(lnumber: ptMove.x);
  if ( abs(lnumber: nAllowedOffset) >= v11 )
  {
    if ( (this->m_dwRowAlignment & 0xA000) != 0 )
      goto LABEL_11;
LABEL_9:
    v7 = abs(lnumber: ptMove.y);
    v8 = nAllowedOffset;
    if ( abs(lnumber: nAllowedOffset) < v7 )
      ptMove.y = v8;
    goto LABEL_11;
  }
  ptMove.x = nAllowedOffset;
LABEL_11:
  OffsetRect(lprc: &rectBarWnd, dx: ptMove.x, dy: ptMove.y);
  if ( CDockingPanesRow::CheckPanes(
         this,
         rectCurrentBar: &rectBarWnd,
         pCurrentBar: pControlBar,
         bForward,
         ptOffset: ptMove,
         bSwapControlBars,
         hdwp) != 0 )
  {
    CWnd::ScreenToClient(this: this->m_pParentDockBar, lpRect: &rectBarWnd);
    pControlBar->SetWindowPos(
      this: pControlBar,
      a2: nullptr,
      a3: rectBarWnd.left,
      a4: rectBarWnd.top,
      a5: rectBarWnd.right - rectBarWnd.left,
      a6: rectBarWnd.bottom - rectBarWnd.top,
      a7: 20u,
      a8: nullptr);
  }
  this->ArrangePanes(this, a2: pControlBar);
}

//------------------------------------------------------------------------------
// Address: 0x10414507
// Name: protected: void CDockingPanesRow::AdjustPaneToRowArea(class CPane __near *,class CRect const __near &,void __near * __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockingPanesRow::AdjustPaneToRowArea(
        CDockingPanesRow *this,
        CPane *pBar,
        const CRect *rectRow,
        void **hdwp)
{
  int right; // eax
  int top; // eax
  int bottom; // eax
  CPoint v8; // [esp-10h] [ebp-30h]
  CPoint v9; // [esp-10h] [ebp-30h]
  CRect rectBarWnd; // [esp+Ch] [ebp-14h] BYREF

  memset(&rectBarWnd, 0, sizeof(rectBarWnd));
  GetWindowRect(hWnd: pBar->m_hWnd, lpRect: &rectBarWnd);
  if ( (this->m_dwRowAlignment & 0xA000) != 0 )
  {
    if ( rectBarWnd.left < rectRow->left )
      CDockingPanesRow::MovePane(
        this,
        pControlBar: pBar,
        ptOffset: (CPoint)(unsigned int)(rectRow->left - rectBarWnd.left),
        bSwapControlBars: 0,
        hdwp);
    right = rectRow->right;
    if ( rectBarWnd.right > right )
      CDockingPanesRow::MovePane(
        this,
        pControlBar: pBar,
        ptOffset: (CPoint)(unsigned int)(right - rectBarWnd.right),
        bSwapControlBars: 0,
        hdwp);
  }
  else
  {
    top = rectRow->top;
    if ( rectBarWnd.top < top )
    {
      v8.y = top - rectBarWnd.top;
      v8.x = 0;
      CDockingPanesRow::MovePane(this, pControlBar: pBar, ptOffset: v8, bSwapControlBars: 0, hdwp);
    }
    bottom = rectRow->bottom;
    if ( rectBarWnd.bottom > bottom )
    {
      v9.y = bottom - rectBarWnd.bottom;
      v9.x = 0;
      CDockingPanesRow::MovePane(this, pControlBar: pBar, ptOffset: v9, bSwapControlBars: 0, hdwp);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104145BE
// Name: public: virtual void CDockingPanesRow::RepositionPanes(class CRect __near &,unsigned int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge CDockingPanesRow::RepositionPanes(
        CDockingPanesRow *this@<ecx>,
        int a2@<edi>,
        CRect *rectNewParentBarArea,
        unsigned int nSide,
        int bExpand,
        int nOffset)
{
  CDockSite *m_pParentDockBar; // ecx
  int v8; // esi
  CDockingPanesRow_vtbl *v9; // eax
  CObject *data; // esi
  CObject_vtbl *v11; // eax
  int v12; // edi
  int OutOfBoundsOffset; // eax
  int v14; // eax
  CObList::CNode *m_pNodeTail; // eax
  int pPrev; // ecx
  CPane *v17; // edi
  CPane_vtbl *v18; // eax
  int v19; // eax
  int v20; // edi
  int v21; // eax
  CObList::CNode *m_pNodeHead; // edi
  CObject *v23; // esi
  CPane *i; // eax
  CPane *v25; // ecx
  CPane *m_pOuterUnknown; // esi
  CPane_vtbl *v27; // eax
  CPane *FirstVisiblePane; // edi
  CPane *v29; // eax
  CObList::CNode *v30; // eax
  int pNext; // ecx
  CPane *v32; // edi
  CPane_vtbl *v33; // eax
  unsigned int m_dwRowAlignment; // edx
  int top; // eax
  int v36; // esi
  int v37; // esi
  int v38; // eax
  int v39; // eax
  int v40; // esi
  char v41; // [esp-Ch] [ebp-70h]
  CPane *nRetSize; // [esp+8h] [ebp-5Ch]
  int nRetSizea; // [esp+8h] [ebp-5Ch]
  bool nRetSizeb; // [esp+8h] [ebp-5Ch]
  void *hdwp; // [esp+Ch] [ebp-58h] BYREF
  CPane *pNextBar; // [esp+10h] [ebp-54h]
  bool bMoveBackward; // [esp+17h] [ebp-4Dh]
  int nActualStretchSize; // [esp+18h] [ebp-4Ch]
  int nSaveOffset; // [esp+1Ch] [ebp-48h] BYREF
  CRect rectNextControlBarVirt; // [esp+20h] [ebp-44h] BYREF
  CRect rectNextControlBar; // [esp+30h] [ebp-34h] BYREF
  CRect rectNewParentWnd; // [esp+40h] [ebp-24h] BYREF
  CRect rectRowWnd; // [esp+50h] [ebp-14h] BYREF

  if ( this->m_lstControlBars.m_nCount == 0 )
    return;
  if ( this->GetVisibleCount(this) == 0 )
    return;
  m_pParentDockBar = this->m_pParentDockBar;
  rectNewParentWnd = *rectNewParentBarArea;
  CWnd::ClientToScreen(this: m_pParentDockBar, lpRect: &rectNewParentWnd);
  memset(&rectRowWnd, 0, sizeof(rectRowWnd));
  CDockingPanesRow::GetWindowRect(this, rect: &rectRowWnd);
  if ( IsRectEmpty(lprc: &rectRowWnd) )
    return;
  if ( (this->m_dwRowAlignment & 0xA000) != 0 )
  {
    v8 = rectRowWnd.left + rectNewParentWnd.right - rectRowWnd.right - rectNewParentWnd.left;
    nSaveOffset = v8;
  }
  else
  {
    nSaveOffset = rectRowWnd.top + rectNewParentWnd.bottom - rectRowWnd.bottom - rectNewParentWnd.top;
    v8 = nSaveOffset;
  }
  v9 = this->__vftable;
  hdwp = nullptr;
  if ( ((int (__thiscall *)(CDockingPanesRow *, int))v9->IsExclusiveRow)(a1: this, a2) != 0 )
  {
    data = this->m_lstControlBars.m_pNodeHead->data;
    v11 = data->__vftable;
    if ( (this->m_dwRowAlignment & 0xA000) != 0 )
      ((void (__thiscall *)(CObject *, _DWORD, int, int, int, int, int))v11[47].GetRuntimeClass)(
        a1: data,
        a2: 0,
        a3: rectRowWnd.left,
        a4: rectRowWnd.top,
        a5: rectNewParentWnd.right - rectNewParentWnd.left,
        a6: rectRowWnd.bottom - rectRowWnd.top,
        a7: 22);
    else
      ((void (__thiscall *)(CObject *, _DWORD, int, int, int, int, int))v11[47].GetRuntimeClass)(
        a1: data,
        a2: 0,
        a3: rectRowWnd.left,
        a4: rectRowWnd.top,
        a5: rectRowWnd.right - rectRowWnd.left,
        a6: rectNewParentWnd.bottom - rectNewParentWnd.top,
        a7: 22);
    RedrawWindow(hWnd: (HWND)data[8].__vftable, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
    return;
  }
  nActualStretchSize = this->GetAvailableLength(this, a2: 1);
  if ( nActualStretchSize >= 0 )
  {
    if ( bExpand != 0 || nActualStretchSize >= abs(lnumber: v8) )
      goto LABEL_45;
LABEL_17:
    if ( nSide == 3 || (LOBYTE(pNextBar) = 0, nSide == 1) )
      LOBYTE(pNextBar) = 1;
    if ( nActualStretchSize >= 0 )
    {
      v12 = 2 * (nSaveOffset >= 0) - 1;
      OutOfBoundsOffset = CDockingPanesRow::GetOutOfBoundsOffset(
                            this,
                            pBar: nullptr,
                            bLeftTopBound: (unsigned __int8)pNextBar);
      v14 = abs(lnumber: OutOfBoundsOffset);
      CDockingPanesRow::ShiftPanes(
        this,
        pControlBar: nullptr,
        nOffset: v12 * (nActualStretchSize - v14),
        bForward: (unsigned __int8)pNextBar);
      v8 = v12 * (abs(lnumber: nSaveOffset) - nActualStretchSize);
    }
    m_pNodeTail = this->m_lstControlBars.m_pNodeTail;
    if ( m_pNodeTail != nullptr )
    {
      while ( 1 )
      {
        pPrev = (int)m_pNodeTail->pPrev;
        v17 = (CPane *)m_pNodeTail->data;
        v18 = v17->__vftable;
        nSaveOffset = pPrev;
        nRetSize = v17;
        if ( v18->IsVisible(this: v17) != 0 || this->m_bIgnoreBarVisibility != 0 )
        {
          v19 = v17->StretchPaneDeferWndPos(this: v17, a2: v8, a3: &hdwp);
          v41 = (char)pNextBar;
          nActualStretchSize = v19;
          v20 = abs(lnumber: v19);
          v21 = abs(lnumber: v8);
          CDockingPanesRow::MovePane(this, pControlBar: nRetSize, nOffset: v21 - v20, bForward: v41, __formal: &hdwp);
          if ( nActualStretchSize == v8 )
            return;
          v8 -= nActualStretchSize;
        }
        if ( nSaveOffset == 0 )
          break;
        m_pNodeTail = (CObList::CNode *)nSaveOffset;
      }
    }
    return;
  }
  if ( bExpand == 0 )
    goto LABEL_17;
  m_pNodeHead = this->m_lstControlBars.m_pNodeHead;
  nActualStretchSize = v8;
  if ( m_pNodeHead != nullptr )
  {
    do
    {
      v23 = m_pNodeHead->data;
      m_pNodeHead = m_pNodeHead->pNext;
      if ( ((int (__thiscall *)(CObject *))v23->__vftable[31].dtr_CObject)(a1: v23) != 0
        || this->m_bIgnoreBarVisibility != 0 )
      {
        nRetSizea = ((int (__thiscall *)(CObject *, int, void **))v23->__vftable[57].GetRuntimeClass)(
                      a1: v23,
                      a2: nActualStretchSize,
                      a3: &hdwp);
        if ( nRetSizea != 0 && m_pNodeHead != nullptr )
        {
          for ( i = (CPane *)m_pNodeHead; ; i = pNextBar )
          {
            v25 = (CPane *)i->__vftable;
            m_pOuterUnknown = (CPane *)i->m_pOuterUnknown;
            v27 = m_pOuterUnknown->__vftable;
            pNextBar = v25;
            if ( v27->IsVisible(this: m_pOuterUnknown) != 0 || this->m_bIgnoreBarVisibility != 0 )
              CDockingPanesRow::MovePane(
                this,
                pControlBar: m_pOuterUnknown,
                nOffset: nRetSizea,
                bForward: true,
                __formal: &hdwp);
            if ( pNextBar == nullptr )
              break;
          }
        }
        nActualStretchSize -= nRetSizea;
        if ( nActualStretchSize <= 0 )
          break;
      }
    }
    while ( m_pNodeHead != nullptr );
    v8 = nSaveOffset;
  }
LABEL_45:
  if ( (this->m_dwRowAlignment & 0xA000) != 0 )
  {
    rectRowWnd.left = rectNewParentWnd.left;
    rectRowWnd.right = rectNewParentWnd.right;
  }
  else
  {
    rectRowWnd.top = rectNewParentWnd.top;
    rectRowWnd.bottom = rectNewParentWnd.bottom;
  }
  FirstVisiblePane = CDockingPanesRow::FindFirstVisiblePane(this, bForward: 1);
  CDockingPanesRow::AdjustPaneToRowArea(this, pBar: FirstVisiblePane, rectRow: &rectRowWnd, &hdwp);
  v29 = CDockingPanesRow::FindFirstVisiblePane(this, bForward: 0);
  if ( FirstVisiblePane != v29 )
    CDockingPanesRow::AdjustPaneToRowArea(this, pBar: v29, rectRow: &rectRowWnd, &hdwp);
  if ( nSide != -1 && bExpand != 0 && v8 + this->GetAvailableLength(this, a2: 1) > 0 )
  {
    v30 = this->m_lstControlBars.m_pNodeHead;
    memset(&rectNextControlBar, 0, sizeof(rectNextControlBar));
    memset(&rectNextControlBarVirt, 0, sizeof(rectNextControlBarVirt));
    if ( v30 != nullptr )
    {
      while ( 1 )
      {
        pNext = (int)v30->pNext;
        v32 = (CPane *)v30->data;
        v33 = v32->__vftable;
        nActualStretchSize = pNext;
        pNextBar = v32;
        if ( v33->IsVisible(this: v32) == 0 && this->m_bIgnoreBarVisibility == 0 )
          goto LABEL_85;
        GetWindowRect(hWnd: v32->m_hWnd, lpRect: &rectNextControlBar);
        CPane::GetVirtualRect(this: v32, rectVirtual: &rectNextControlBarVirt);
        if ( EqualRect(lprc1: &rectNextControlBar, lprc2: &rectNextControlBarVirt) )
          goto LABEL_85;
        m_dwRowAlignment = this->m_dwRowAlignment;
        nSaveOffset = m_dwRowAlignment & 0x2000;
        if ( ((m_dwRowAlignment & 0x2000) != 0 || (m_dwRowAlignment & 0x8000) != 0)
          && rectNextControlBar.left > rectNextControlBarVirt.left )
        {
          top = rectNextControlBarVirt.top;
        }
        else
        {
          top = rectNextControlBarVirt.top;
          if ( nSaveOffset != 0
            || (m_dwRowAlignment & 0x8000) != 0
            || rectNextControlBar.top <= rectNextControlBarVirt.top )
          {
            bMoveBackward = false;
            goto LABEL_66;
          }
        }
        bMoveBackward = true;
LABEL_66:
        v36 = 0;
        if ( (nSaveOffset != 0 || (m_dwRowAlignment & 0x8000) != 0) && (nSide == 1 || nSide == 2) )
        {
          v37 = abs(lnumber: rectNextControlBarVirt.left - rectNextControlBar.left);
          if ( abs(lnumber: nOffset) < v37 )
            goto LABEL_71;
          v39 = rectNextControlBarVirt.left - rectNextControlBar.left;
LABEL_81:
          v38 = abs(lnumber: v39);
          goto LABEL_82;
        }
        if ( nSaveOffset == 0 && (m_dwRowAlignment & 0x8000) == 0 && (nSide == 3 || nSide == 6) )
        {
          v40 = abs(lnumber: top - rectNextControlBar.top);
          if ( abs(lnumber: nOffset) >= v40 )
          {
            v39 = rectNextControlBarVirt.top - rectNextControlBar.top;
            goto LABEL_81;
          }
LABEL_71:
          v38 = abs(lnumber: nOffset);
LABEL_82:
          v36 = v38;
        }
        nRetSizeb = !bMoveBackward;
        nSaveOffset = v36;
        if ( CDockingPanesRow::IsEnoughSpaceToMove(
               this,
               pControlBar: pNextBar,
               bForward: !bMoveBackward,
               nAllowedOffset: &nSaveOffset) != 0 )
          CDockingPanesRow::MovePane(this, pControlBar: pNextBar, nOffset: v36, bForward: nRetSizeb, __formal: &hdwp);
LABEL_85:
        if ( nActualStretchSize == 0 )
          return;
        v30 = (CObList::CNode *)nActualStretchSize;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10414A81
// Name: public: virtual struct CRuntimeClass __near * CMFCToolBarSystemMenuButton::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMFCToolBarSystemMenuButton::GetRuntimeClass(CMFCToolBarSystemMenuButton *this)
{
  return &CMFCToolBarSystemMenuButton::classCMFCToolBarSystemMenuButton;
}

//------------------------------------------------------------------------------
// Address: 0x10414A87
// Name: public: CMFCToolBarSystemMenuButton::CMFCToolBarSystemMenuButton(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCToolBarSystemMenuButton *__thiscall CMFCToolBarSystemMenuButton::CMFCToolBarSystemMenuButton(
        CMFCToolBarSystemMenuButton *this)
{
  CMFCToolBarMenuButton::CMFCToolBarMenuButton(this);
  this->m_hSysMenuIcon = nullptr;
  this->m_hSystemMenu = nullptr;
  this->__vftable = (CMFCToolBarSystemMenuButton_vtbl *)&CMFCToolBarSystemMenuButton::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10414AA9
// Name: public: CMFCToolBarSystemMenuButton::CMFCToolBarSystemMenuButton(struct HMENU__ __near *,struct HICON__ __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCToolBarSystemMenuButton *__thiscall CMFCToolBarSystemMenuButton::CMFCToolBarSystemMenuButton(
        CMFCToolBarSystemMenuButton *this,
        HMENU__ *hSystemMenu,
        HICON__ *hSystemIcon)
{
  CMFCToolBarMenuButton::CMFCToolBarMenuButton(
    this,
    uiID: 0,
    hMenu: hSystemMenu,
    iImage: -1,
    lpszText: nullptr,
    bUserButton: 0);
  this->m_hSystemMenu = hSystemMenu;
  this->m_hSysMenuIcon = hSystemIcon;
  this->__vftable = (CMFCToolBarSystemMenuButton_vtbl *)&CMFCToolBarSystemMenuButton::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10414ADF
// Name: public: virtual CMFCToolBarSystemMenuButton::~CMFCToolBarSystemMenuButton(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarSystemMenuButton::~CMFCToolBarSystemMenuButton(CMFCToolBarSystemMenuButton *this)
{
  this->__vftable = (CMFCToolBarSystemMenuButton_vtbl *)&CMFCToolBarSystemMenuButton::`vftable';
  CMFCToolBarMenuButton::~CMFCToolBarMenuButton(this);
}

//------------------------------------------------------------------------------
// Address: 0x10414AEA
// Name: public: virtual void CMFCToolBarSystemMenuButton::CopyFrom(class CMFCToolBarButton const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarSystemMenuButton::CopyFrom(CMFCToolBarSystemMenuButton *this, const CMFCToolBarButton *s)
{
  CMFCToolBarMenuButton::CopyFrom(this, s);
  this->m_hSysMenuIcon = (HICON__ *)s[2].m_bText;
  this->m_hSystemMenu = (HMENU__ *)s[2].m_bImage;
}

//------------------------------------------------------------------------------
// Address: 0x10414B1A
// Name: public: virtual struct tagSIZE CMFCToolBarSystemMenuButton::OnCalculateSize(class CDC __near *,class CSize const __near &,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDC *__thiscall CMFCToolBarSystemMenuButton::OnCalculateSize(
        CMFCToolBarSystemMenuButton *this,
        CDC *__formal,
        CDC *sizeDefault,
        const CSize *sizeDefaulta,
        int a5)
{
  HDC__ *cy; // esi
  CDC_vtbl *SystemMetrics; // ecx

  cy = (HDC__ *)sizeDefaulta->cy;
  SystemMetrics = (CDC_vtbl *)GetSystemMetrics(nIndex: 54);
  __formal->m_hDC = cy;
  __formal->__vftable = SystemMetrics;
  return __formal;
}

//------------------------------------------------------------------------------
// Address: 0x10414B3D
// Name: public: virtual void CMFCToolBarSystemMenuButton::CreateFromMenu(struct HMENU__ __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarSystemMenuButton::CreateFromMenu(CMFCToolBarSystemMenuButton *this, HMENU__ *hMenu)
{
  this->m_hSystemMenu = hMenu;
}

//------------------------------------------------------------------------------
// Address: 0x10414B4F
// Name: public: virtual void CMFCToolBarSystemMenuButton::OnCancelMode(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarSystemMenuButton::OnCancelMode(CMFCToolBarSystemMenuButton *this)
{
  CMFCPopupMenu *m_pPopupMenu; // eax

  m_pPopupMenu = this->m_pPopupMenu;
  if ( m_pPopupMenu != nullptr && IsWindow(hWnd: m_pPopupMenu->m_hWnd) )
  {
    if ( this->m_pPopupMenu->InCommand(this: this->m_pPopupMenu) != 0 )
      return;
    this->m_pPopupMenu->SaveState(this: this->m_pPopupMenu);
    this->m_pPopupMenu->m_bAutoDestroyParent = 0;
    CMFCPopupMenu::CloseMenu(this: this->m_pPopupMenu, bSetFocusToBar: 0);
  }
  this->m_pPopupMenu = nullptr;
  this->m_bToBeClosed = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10414BB5
// Name: public: static class CObject __near * CMFCToolBarSystemMenuButton::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCToolBarSystemMenuButton *__stdcall CMFCToolBarSystemMenuButton::CreateObject()
{
  CMFCToolBarSystemMenuButton *v0; // ecx
  CMFCToolBarSystemMenuButton *result; // eax

  v0 = (CMFCToolBarSystemMenuButton *)operator new(nSize: 0xF0u);
  result = nullptr;
  if ( v0 != nullptr )
    return CMFCToolBarSystemMenuButton::CMFCToolBarSystemMenuButton(this: v0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10414C0C
// Name: public: virtual void CMFCToolBarSystemMenuButton::OnDraw(class CDC __near *,class CRect const __near &,class CMFCToolBarImages __near *,int,int,int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarSystemMenuButton::OnDraw(
        CMFCToolBarSystemMenuButton *this,
        HDC__ *pDC,
        const CRect *rect,
        CMFCToolBarImages *__formal,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9)
{
  int SystemMetrics; // edi
  int v10; // eax
  int v11; // edi
  int v12; // ebx
  int v13; // eax
  HDC__ *v14; // edx

  if ( this->m_hSysMenuIcon != nullptr )
  {
    SystemMetrics = GetSystemMetrics(nIndex: 55);
    if ( GetSystemMetrics(nIndex: 50) >= SystemMetrics )
      v10 = GetSystemMetrics(nIndex: 55);
    else
      v10 = GetSystemMetrics(nIndex: 50);
    v11 = v10;
    v12 = GetSystemMetrics(nIndex: 54);
    if ( GetSystemMetrics(nIndex: 49) >= v12 )
      v13 = GetSystemMetrics(nIndex: 54);
    else
      v13 = GetSystemMetrics(nIndex: 49);
    v14 = pDC;
    if ( pDC != nullptr )
      v14 = *((HDC__ **)pDC + 1);
    DrawIconEx(
      hdc: v14,
      xLeft: rect->left,
      yTop: (rect->bottom - rect->top - v11) / 2 + rect->top,
      hIcon: this->m_hSysMenuIcon,
      cxWidth: v13,
      cyWidth: v11,
      istepIfAniCur: 0,
      hbrFlickerFreeDraw: nullptr,
      diFlags: 3u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10414C97
// Name: public: virtual void CMFCToolBarSystemMenuButton::OnDblClk(class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarSystemMenuButton::OnDblClk(CMFCToolBarSystemMenuButton *this, CWnd *pWnd)
{
  CFrameWnd *v2; // eax
  CWnd *v3; // esi
  HWND Parent; // eax
  CMDIFrameWnd *v5; // eax
  CMDIChildWnd *v6; // edi
  HMENU SystemMenu; // eax
  CMenu *v8; // ebx
  HMENU m_hMenu; // [esp-18h] [ebp-4Ch]
  tagMENUITEMINFOA menuInfo; // [esp+4h] [ebp-30h] BYREF

  if ( CMFCToolBar::m_bCustomizeMode == 0 )
  {
    if ( pWnd == nullptr )
      AfxThrowInvalidArgException();
    this->OnCancelMode(this);
    v2 = AFXGetParentFrame(pWnd);
    v3 = v2;
    if ( v2 != nullptr && CObject::IsKindOf(this: v2, pClass: &CMiniDockFrameWnd::classCMiniDockFrameWnd) != 0 )
    {
      Parent = GetParent(hWnd: v3->m_hWnd);
      v3 = CWnd::FromHandle(hWnd: Parent);
    }
    v5 = (CMDIFrameWnd *)AfxDynamicDownCast(pClass: &CMDIFrameWnd::classCMDIFrameWnd, pObject: v3);
    if ( v5 != nullptr )
    {
      v6 = CMDIFrameWnd::MDIGetActive(this: v5, pbMaximized: nullptr);
      SystemMenu = GetSystemMenu(hWnd: v6->m_hWnd, bRevert: false);
      v8 = CMenu::FromHandle(hMenu: SystemMenu);
      if ( v8 == nullptr
        || (memset(dst: (unsigned __int8 *)&menuInfo, value: 0, count: sizeof(menuInfo)),
            m_hMenu = v8->m_hMenu,
            menuInfo.cbSize = 48,
            menuInfo.fMask = 1,
            GetMenuItemInfoA(hmenu: m_hMenu, item: 0xF060u, fByPosition: false, lpmii: &menuInfo),
            (menuInfo.fState & 3) == 0) )
      {
        SendMessageA(hWnd: v6->m_hWnd, Msg: 0x112u, wParam: 0xF060u, lParam: 0);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10414D73
// Name: public: virtual struct HMENU__ __near * CMFCToolBarSystemMenuButton::CreateMenu(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HMENU__ *__thiscall CMFCToolBarSystemMenuButton::CreateMenu(CMFCToolBarSystemMenuButton *this)
{
  HMENU__ *result; // eax
  CMenu *v3; // edi
  CMenu *v4; // esi
  UINT MenuItemID; // eax
  UINT v6; // ebx
  HMENU__ *hMenu; // [esp+4h] [ebp-10h]
  int iCount; // [esp+8h] [ebp-Ch]
  char uiState; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  if ( this->m_hSystemMenu == nullptr )
    AfxThrowInvalidArgException();
  result = CMFCToolBarMenuButton::CreateMenu(this);
  hMenu = result;
  if ( result != nullptr )
  {
    v3 = CMenu::FromHandle(hMenu: result);
    v4 = CMenu::FromHandle(hMenu: this->m_hSystemMenu);
    i = 0;
    iCount = GetMenuItemCount(hMenu: v4->m_hMenu);
    if ( iCount > 0 )
    {
      do
      {
        uiState = GetMenuState(hMenu: v4->m_hMenu, uId: i, uFlags: 0x400u);
        MenuItemID = GetMenuItemID(hMenu: v4->m_hMenu, nPos: i);
        v6 = MenuItemID;
        if ( (uiState & 8) != 0 )
          CheckMenuItem(hMenu: v3->m_hMenu, uIDCheckItem: MenuItemID, uCheck: 8u);
        if ( (uiState & 2) != 0 )
          EnableMenuItem(hMenu: v3->m_hMenu, uIDEnableItem: v6, uEnable: 2u);
        if ( (uiState & 1) != 0 )
          EnableMenuItem(hMenu: v3->m_hMenu, uIDEnableItem: v6, uEnable: 1u);
        ++i;
      }
      while ( i < iCount );
    }
    return hMenu;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10414E32
// Name: public: virtual void CMFCToolBarSystemMenuButton::OnAfterCreatePopupMenu(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarSystemMenuButton::OnAfterCreatePopupMenu(CMFCToolBarSystemMenuButton *this)
{
  CMFCPopupMenu *m_pPopupMenu; // eax
  CFrameWnd *TopLevelFrame; // eax
  CWnd *v4; // edi
  HWND Parent; // eax
  CMDIFrameWnd *v6; // eax

  m_pPopupMenu = this->m_pPopupMenu;
  if ( m_pPopupMenu != nullptr && IsWindow(hWnd: m_pPopupMenu->m_hWnd) )
  {
    TopLevelFrame = (CFrameWnd *)g_pTopLevelFrame;
    if ( g_pTopLevelFrame == nullptr )
      TopLevelFrame = CWnd::GetTopLevelFrame(this: this->m_pPopupMenu);
    v4 = TopLevelFrame;
    if ( TopLevelFrame != nullptr
      && CObject::IsKindOf(this: TopLevelFrame, pClass: &CMiniDockFrameWnd::classCMiniDockFrameWnd) != 0 )
    {
      Parent = GetParent(hWnd: v4->m_hWnd);
      v4 = CWnd::FromHandle(hWnd: Parent);
    }
    v6 = (CMDIFrameWnd *)AfxDynamicDownCast(pClass: &CMDIFrameWnd::classCMDIFrameWnd, pObject: v4);
    if ( v6 != nullptr )
      this->m_pPopupMenu->m_pMessageWnd = CMDIFrameWnd::MDIGetActive(this: v6, pbMaximized: nullptr);
  }
}
