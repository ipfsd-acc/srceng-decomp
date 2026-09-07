// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/particle_proxies.cpp
// Functions: 7
// ============================================================

#include "game\client\particle_proxies.h"

//------------------------------------------------------------------------------
// Address: 0x1012F560
// Name: public: virtual bool ParticleSphereProxy::Init(class IMaterial __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall ParticleSphereProxy::Init(ParticleSphereProxy *this, IMaterial *pMaterial, KeyValues *pKeyValues)
{
  this->m_pLightPosition = pMaterial->FindVar(this: pMaterial, a2: "$light_position", a3: 0, a4: 0);
  this->m_pLightColor = pMaterial->FindVar(this: pMaterial, a2: "$light_color", a3: 0, a4: 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1012F5B0
// Name: public: virtual void ParticleSphereProxy::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ParticleSphereProxy::Release(ParticleSphereProxy *this)
{
  if ( this != nullptr )
    ((void (__thiscall *)(ParticleSphereProxy *, int))this->dtr_IMaterialProxy)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1012F5F0
// Name: public: virtual class IMaterial __near * ParticleSphereProxy::GetMaterial(void)
// Source: json
//------------------------------------------------------------------------------
IMaterial *__thiscall ParticleSphereProxy::GetMaterial(ParticleSphereProxy *this)
{
  IMaterialVar *m_pLightPosition; // [esp+0h] [ebp-Ch]

  if ( this->m_pLightPosition != nullptr )
    m_pLightPosition = this->m_pLightPosition;
  else
    m_pLightPosition = this->m_pLightColor;
  if ( m_pLightPosition != nullptr )
    return m_pLightPosition->GetOwningMaterial(this: m_pLightPosition);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1012F640
// Name: public: class Vector VMatrix::operator*(class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall VMatrix::operator*(VMatrix *this, Vector *result, const Vector *vVec)
{
  float x; // xmm1_4
  float y; // xmm0_4
  float z; // xmm2_4
  float v7; // xmm4_4

  x = vVec->x;
  y = vVec->y;
  z = vVec->z;
  v7 = this->m[1][1];
  result->x = (float)((float)((float)(this->m[0][1] * y) + (float)(vVec->x * this->m[0][0])) + (float)(this->m[0][2] * z))
            + this->m[0][3];
  result->y = (float)((float)((float)(this->m[1][0] * x) + (float)(v7 * y)) + (float)(this->m[1][2] * z))
            + this->m[1][3];
  result->z = (float)((float)((float)(this->m[2][0] * x) + (float)(this->m[2][1] * y)) + (float)(this->m[2][2] * z))
            + this->m[2][3];
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1012F720
// Name: CParticleSphereProxyFactory
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__cdecl CParticleSphereProxyFactory()
{
  _DWORD *v2; // [esp+4h] [ebp-4h]

  v2 = MemAlloc_Alloc(nSize: 0xCu);
  if ( v2 == nullptr )
    return nullptr;
  *v2 = &IMaterialProxy::`vftable';
  *v2 = &ParticleSphereProxy::`vftable';
  return (IMaterialProxy *)v2;
}

//------------------------------------------------------------------------------
// Address: 0x1012F770
// Name: public: virtual void ParticleSphereProxy::OnBind(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ParticleSphereProxy::OnBind(ParticleSphereProxy *this, CParticleMgr *pvParticleMgr)
{
  VMatrix *ModelView; // eax
  CChoreoActor *v3; // eax
  CChoreoActor *v4; // eax
  Vector vTotalColor; // [esp+28h] [ebp-38h] BYREF
  CParticleLightInfo info; // [esp+34h] [ebp-2Ch] BYREF
  CParticleMgr *pMgr; // [esp+50h] [ebp-10h]
  Vector vTransformedPos; // [esp+54h] [ebp-Ch] BYREF

  if ( pvParticleMgr != nullptr )
  {
    pMgr = pvParticleMgr;
    C_BasePlayer::ActivePlayerCombatCharacter(this: (CChoreoActor *)&info);
    C_BasePlayer::ActivePlayerCombatCharacter(this: (CChoreoActor *)&info.m_vColor);
    CParticleMgr::GetDirectionalLightInfo(this: pMgr, &info);
    ModelView = CParticleMgr::GetModelView(this: pMgr);
    VMatrix::operator*(this: ModelView, result: &vTransformedPos, vVec: &info.m_vPos);
    if ( this->m_pLightPosition != nullptr )
    {
      v3 = C_BasePlayer::ActivePlayerCombatCharacter(this: (CChoreoActor *)&vTransformedPos);
      this->m_pLightPosition->SetVecValue_4(this: this->m_pLightPosition, a2: (const float *)v3, a3: 3);
    }
    if ( this->m_pLightColor != nullptr )
    {
      Vector::operator*(this: &info.m_vColor, result: &vTotalColor, fl: info.m_flIntensity);
      v4 = C_BasePlayer::ActivePlayerCombatCharacter(this: (CChoreoActor *)&vTotalColor);
      this->m_pLightColor->SetVecValue_4(this: this->m_pLightColor, a2: (const float *)v4, a3: 3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C86D0
// Name: public: class VMatrix VMatrix::operator*(class VMatrix const __near &)const
// Source: json
//------------------------------------------------------------------------------
VMatrix *__thiscall VMatrix::operator*(VMatrix *this, VMatrix *result, const VMatrix *vm)
{
  int v3; // edx

  VMatrix::MatrixMul(this, vm, out: result);
  return (VMatrix *)v3;
}
