// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/matrixproxy.cpp
// Functions: 6
// ============================================================

#include "game\client\matrixproxy.h"

//------------------------------------------------------------------------------
// Address: 0x1011DCA0
// Name: public: virtual bool CTextureTransformProxy::Init(class IMaterial __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTextureTransformProxy::Init(CTextureTransformProxy *this, IMaterial *pMaterial, KeyValues *pKeyValues)
{
  const char *String; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  bool bFoundVar; // [esp+Fh] [ebp-1h] BYREF

  this->m_pCenterVar = nullptr;
  this->m_pScaleVar = nullptr;
  this->m_pRotateVar = nullptr;
  this->m_pTranslateVar = nullptr;
  String = KeyValues::GetString(this: pKeyValues, keyName: "centerVar", defaultValue: prType);
  if ( String != nullptr && *String != 0 )
    this->m_pCenterVar = pMaterial->FindVar(this: pMaterial, a2: String, a3: &bFoundVar, a4: 0);
  v5 = KeyValues::GetString(this: pKeyValues, keyName: "scaleVar", defaultValue: prType);
  if ( v5 != nullptr && *v5 != 0 )
    this->m_pScaleVar = pMaterial->FindVar(this: pMaterial, a2: v5, a3: &bFoundVar, a4: 0);
  v6 = KeyValues::GetString(this: pKeyValues, keyName: "rotateVar", defaultValue: prType);
  if ( v6 != nullptr && *v6 != 0 )
    this->m_pRotateVar = pMaterial->FindVar(this: pMaterial, a2: v6, a3: &bFoundVar, a4: 0);
  v7 = KeyValues::GetString(this: pKeyValues, keyName: "translateVar", defaultValue: prType);
  if ( v7 != nullptr && *v7 != 0 )
    this->m_pTranslateVar = pMaterial->FindVar(this: pMaterial, a2: v7, a3: &bFoundVar, a4: 0);
  return CResultProxy::Init(this, pMaterial, pKeyValues);
}

//------------------------------------------------------------------------------
// Address: 0x1011DD80
// Name: public: virtual bool CMatrixRotateProxy::Init(class IMaterial __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMatrixRotateProxy::Init(CMatrixRotateProxy *this, IMaterial *pMaterial, KeyValues *pKeyValues)
{
  KeyValues *v3; // ebx
  KeyValues *v5; // ecx
  const char *String; // eax
  char result; // al

  v3 = pKeyValues;
  v5 = pKeyValues;
  this->m_pAxisVar = nullptr;
  String = KeyValues::GetString(this: v5, keyName: "axisVar", defaultValue: prType);
  if ( String != nullptr && *String != 0 )
    this->m_pAxisVar = pMaterial->FindVar(this: pMaterial, a2: String, a3: (char *)&pKeyValues + 3, a4: 0);
  result = CFloatInput::Init(this: &this->m_Angle, pMaterial, pKeyValues: v3, pKeyName: "angle", flDefault: 0.0);
  if ( result != 0 )
    return CResultProxy::Init(this, pMaterial, pKeyValues: v3);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1011DE00
// Name: public: virtual void CTextureTransformProxy::OnBind(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureTransformProxy::OnBind(CTextureTransformProxy *this, void *pC_BaseEntity)
{
  float y; // xmm0_4
  IMaterialVar *m_pCenterVar; // ecx
  float x; // xmm1_4
  IMaterialVar *m_pScaleVar; // ecx
  IMaterialVar *m_pRotateVar; // ecx
  IMaterialVar *m_pTranslateVar; // ecx
  VMatrix temp; // [esp+28h] [ebp-98h] BYREF
  VMatrix mat; // [esp+68h] [ebp-58h] BYREF
  unsigned int angle; // [esp+A8h] [ebp-18h] BYREF
  float angleDegrees; // [esp+ACh] [ebp-14h]
  Vector2D translation; // [esp+B0h] [ebp-10h] BYREF
  Vector2D center; // [esp+B8h] [ebp-8h] BYREF

  y = 0.5;
  m_pCenterVar = this->m_pCenterVar;
  x = 0.5;
  center.x = 0.5;
  center.y = 0.5;
  translation.x = 0.0;
  translation.y = 0.0;
  if ( m_pCenterVar != nullptr )
  {
    m_pCenterVar->GetVecValueInternal(this: m_pCenterVar, a2: &center.x, a3: 2);
    y = center.y;
    x = center.x;
  }
  MatrixBuildTranslation(
    dst: &mat,
    x: COERCE_FLOAT(LODWORD(x) ^ _mask__NegFloat_),
    y: COERCE_FLOAT(LODWORD(y) ^ _mask__NegFloat_),
    z: 0.0);
  m_pScaleVar = this->m_pScaleVar;
  if ( m_pScaleVar != nullptr )
  {
    m_pScaleVar->GetVecValueInternal(this: m_pScaleVar, a2: (float *)&angle, a3: 2);
    MatrixBuildScale(dst: &temp, x: angle, y: LODWORD(angleDegrees), z: 1.0);
    MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
  }
  m_pRotateVar = this->m_pRotateVar;
  if ( m_pRotateVar != nullptr )
  {
    angleDegrees = m_pRotateVar->GetFloatValueInternal(this: m_pRotateVar);
    MatrixBuildRotateZ(dst: &temp, angleDegrees);
    MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
  }
  MatrixBuildTranslation(dst: &temp, x: center.x, y: center.y, z: 0.0);
  MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
  m_pTranslateVar = this->m_pTranslateVar;
  if ( m_pTranslateVar != nullptr )
  {
    m_pTranslateVar->GetVecValueInternal(this: m_pTranslateVar, a2: &translation.x, a3: 2);
    MatrixBuildTranslation(dst: &temp, x: translation.x, y: translation.y, z: 0.0);
    MatrixMultiply(src1: &temp, src2: &mat, dst: &mat);
  }
  this->m_pResult->SetMatrixValue(this: this->m_pResult, a2: &mat);
}

//------------------------------------------------------------------------------
// Address: 0x1011DFD0
// Name: CCTextureTransformProxyFactory
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__cdecl CCTextureTransformProxyFactory()
{
  CResultProxy *v0; // eax
  _DWORD *v1; // esi

  v0 = (CResultProxy *)MemAlloc_Alloc(nSize: 0x1Cu);
  v1 = &v0->__vftable;
  if ( v0 == nullptr )
    return nullptr;
  CResultProxy::CResultProxy(this: v0);
  *v1 = &CTextureTransformProxy::`vftable';
  return (IMaterialProxy *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x1011E000
// Name: public: virtual void CMatrixRotateProxy::OnBind(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatrixRotateProxy::OnBind(CMatrixRotateProxy *this, void *pC_BaseEntity)
{
  IMaterialVar *m_pAxisVar; // ecx
  float angleDegrees; // [esp+8h] [ebp-54h]
  VMatrix mat; // [esp+10h] [ebp-4Ch] BYREF
  Vector axis; // [esp+50h] [ebp-Ch] BYREF

  m_pAxisVar = this->m_pAxisVar;
  axis.x = 0.0;
  axis.y = 0.0;
  axis.z = 1.0;
  if ( m_pAxisVar != nullptr )
  {
    m_pAxisVar->GetVecValueInternal(this: m_pAxisVar, a2: &axis.x, a3: 3);
    if ( VectorNormalize(vec: &axis) < 0.001 )
    {
      axis.x = 0.0;
      axis.y = 0.0;
      axis.z = 1.0;
    }
  }
  angleDegrees = CFloatInput::GetFloat(this: &this->m_Angle);
  MatrixBuildRotationAboutAxis(dst: (matrix3x4_t *)&mat, vAxisOfRot: &axis, angleDegrees);
  this->m_pResult->SetMatrixValue(this: this->m_pResult, a2: &mat);
}

//------------------------------------------------------------------------------
// Address: 0x1011E0A0
// Name: CCMatrixRotateProxyFactory
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__cdecl CCMatrixRotateProxyFactory()
{
  CResultProxy *v0; // eax
  _DWORD *v1; // esi

  v0 = (CResultProxy *)MemAlloc_Alloc(nSize: 0x1Cu);
  v1 = &v0->__vftable;
  if ( v0 == nullptr )
    return nullptr;
  CResultProxy::CResultProxy(this: v0);
  *v1 = &CMatrixRotateProxy::`vftable';
  return (IMaterialProxy *)v1;
}
