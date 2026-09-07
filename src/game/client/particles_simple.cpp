// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/particles_simple.cpp
// Functions: 34
// ============================================================

#include "game\client\particles_simple.h"

//------------------------------------------------------------------------------
// Address: 0x10136E30
// Name: public: virtual void CSimpleEmitter::SimulateParticles(class CParticleSimulateIterator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleEmitter::SimulateParticles(CLocalSpaceEmitter *this, CParticleSimulateIterator *pIterator)
{
  CEffectMaterial *m_pMaterial; // eax
  Particle *m_pNext; // esi
  float v6; // xmm2_4
  float v7; // xmm3_4
  float timeDelta; // [esp+20h] [ebp+8h]

  m_pMaterial = pIterator->m_pMaterial;
  m_pNext = m_pMaterial->m_Particles.m_pNext;
  timeDelta = pIterator->m_flTimeDelta;
  if ( m_pNext != &m_pMaterial->m_Particles )
  {
    for ( pIterator->m_pNextParticle = m_pNext->m_pNext; ; pIterator->m_pNextParticle = m_pNext->m_pNext )
    {
      ((void (__thiscall *)(CLocalSpaceEmitter *, Particle *, _DWORD))this->UpdateVelocity)(
        a1: this,
        a2: m_pNext,
        a3: LODWORD(timeDelta));
      v6 = *(float *)&m_pNext[1].m_pNext;
      v7 = *(float *)&m_pNext[1].m_pSubTexture;
      m_pNext->m_Pos.x = (float)(*(float *)&m_pNext[1].m_pPrev * timeDelta) + m_pNext->m_Pos.x;
      m_pNext->m_Pos.y = m_pNext->m_Pos.y + (float)(v6 * timeDelta);
      m_pNext->m_Pos.z = m_pNext->m_Pos.z + (float)(v7 * timeDelta);
      m_pNext[1].m_Pos.z = m_pNext[1].m_Pos.z + timeDelta;
      ((void (__thiscall *)(CLocalSpaceEmitter *, Particle *, _DWORD))this->UpdateRoll)(
        a1: this,
        a2: m_pNext,
        a3: LODWORD(timeDelta));
      if ( m_pNext[1].m_Pos.z >= m_pNext[1].m_Pos.y )
        CParticleEffectBinding::RemoveParticle(this: pIterator->m_pEffectBinding, pParticle: m_pNext);
      m_pNext = pIterator->m_pNextParticle;
      if ( m_pNext == &pIterator->m_pMaterial->m_Particles )
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10139080
// Name: public: void CParticleEffect::SetDynamicallyAllocated(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleEffect::SetDynamicallyAllocated(CParticleEffect *this, bool bDynamic)
{
  if ( bDynamic )
    this->m_Flags |= 2u;
  else
    this->m_Flags &= ~2u;
}

//------------------------------------------------------------------------------
// Address: 0x101390A0
// Name: private: void CParticleEffect::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleEffect::AddRef(CParticleEffect *this)
{
  ++this->m_RefCount;
}

//------------------------------------------------------------------------------
// Address: 0x101390B0
// Name: public: virtual class Vector const __near & CParticleEffect::GetSortOrigin(void)
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CParticleEffect::GetSortOrigin(CParticleEffect *this)
{
  return &this->m_vSortOrigin;
}

//------------------------------------------------------------------------------
// Address: 0x101390D0
// Name: public: virtual void CParticleEffect::NotifyRemove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleEffect::NotifyRemove(CParticleEffect *this)
{
  if ( (this->m_Flags & 2) != 0 )
    ((void (__thiscall *)(CParticleEffect *, int))this->dtr_IParticleEffect)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x101390F0
// Name: public: virtual void CParticleEffect::SetParticleCullRadius(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleEffect::SetParticleCullRadius(CParticleEffect *this, float radius)
{
  CParticleEffectBinding::SetParticleCullRadius(this: &this->m_ParticleEffect, flMaxParticleRadius: radius);
}

//------------------------------------------------------------------------------
// Address: 0x10139110
// Name: public: class CParticleSubTexture __near * CParticleEffect::GetPMaterial(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CParticleSubTexture *__thiscall CParticleEffect::GetPMaterial(CParticleEffect *this, const char *name)
{
  return CParticleEffectBinding::FindOrAddMaterial(this: &this->m_ParticleEffect, pMaterialName: name);
}

//------------------------------------------------------------------------------
// Address: 0x10139120
// Name: public: void CSimpleEmitter::SetNearClip(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleEmitter::SetNearClip(CSimpleEmitter *this, float nearClipMin, float nearClipMax)
{
  this->m_flNearClipMin = nearClipMin;
  this->m_flNearClipMax = nearClipMax;
}

//------------------------------------------------------------------------------
// Address: 0x10139150
// Name: protected: virtual float CSimpleEmitter::UpdateAlpha(class SimpleParticle const __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CSimpleEmitter::UpdateAlpha(CSimpleEmitter *this, const SimpleParticle *pParticle)
{
  double m_uchStartAlpha; // st7

  m_uchStartAlpha = (double)pParticle->m_uchStartAlpha;
  return m_uchStartAlpha * 0.0039215689
       + pParticle->m_flLifetime
       / pParticle->m_flDieTime
       * (0.0039215689 * (double)pParticle->m_uchEndAlpha - m_uchStartAlpha * 0.0039215689);
}

//------------------------------------------------------------------------------
// Address: 0x10139190
// Name: protected: virtual float CSimpleEmitter::UpdateScale(class SimpleParticle const __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CSimpleEmitter::UpdateScale(CSimpleEmitter *this, const SimpleParticle *pParticle)
{
  double m_uchStartSize; // st7

  m_uchStartSize = (double)pParticle->m_uchStartSize;
  return m_uchStartSize
       + pParticle->m_flLifetime / pParticle->m_flDieTime * ((double)pParticle->m_uchEndSize - m_uchStartSize);
}

//------------------------------------------------------------------------------
// Address: 0x101391C0
// Name: protected: virtual float CSimpleEmitter::UpdateRoll(class SimpleParticle __near *,float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CSimpleEmitter::UpdateRoll(CSimpleEmitter *this, SimpleParticle *pParticle, float timeDelta)
{
  float pParticlea; // [esp+8h] [ebp+8h]

  pParticlea = (float)(pParticle->m_flRollDelta * timeDelta) + pParticle->m_flRoll;
  pParticle->m_flRoll = pParticlea;
  return pParticlea;
}

//------------------------------------------------------------------------------
// Address: 0x101391F0
// Name: public: void CSimpleEmitter::SetDrawBeforeViewModel(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleEmitter::SetDrawBeforeViewModel(CSimpleEmitter *this, bool state)
{
  CParticleEffectBinding::SetDrawBeforeViewModel(this: &this->m_ParticleEffect, bDraw: state);
}

//------------------------------------------------------------------------------
// Address: 0x10139210
// Name: public: void CSimpleEmitter::SetShouldDrawForSplitScreenUser(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleEmitter::SetShouldDrawForSplitScreenUser(CSimpleEmitter *this, int nSlot)
{
  this->m_nSplitScreenPlayerSlot = nSlot;
}

//------------------------------------------------------------------------------
// Address: 0x10139220
// Name: protected: CParticleEffect::CParticleEffect(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CParticleEffect *__thiscall CParticleEffect::CParticleEffect(CParticleEffect *this, const char *pName)
{
  CParticleEffectBinding *p_m_ParticleEffect; // edi
  CParticleMgr *v4; // eax

  p_m_ParticleEffect = &this->m_ParticleEffect;
  this->__vftable = (CParticleEffect_vtbl *)&CParticleEffect::`vftable';
  CParticleEffectBinding::CParticleEffectBinding(this: &this->m_ParticleEffect);
  this->m_pDebugName = pName;
  this->m_vSortOrigin.x = 0.0;
  this->m_vSortOrigin.y = 0.0;
  this->m_vSortOrigin.z = 0.0;
  this->m_Flags = 2;
  this->m_nToolParticleEffectId = -1;
  this->m_RefCount = 0;
  this->m_bSimulate = true;
  v4 = ParticleMgr();
  CParticleMgr::AddEffect(this: v4, pEffect: p_m_ParticleEffect, pSim: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101392A0
// Name: protected: virtual CParticleEffect::~CParticleEffect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleEffect::~CParticleEffect(CParticleEffect *this)
{
  KeyValues *v2; // edi
  bool v3; // zf
  KeyValues *v4; // eax

  v2 = nullptr;
  v3 = this->m_nToolParticleEffectId == -1;
  this->__vftable = (CParticleEffect_vtbl *)&CParticleEffect::`vftable';
  this->m_Flags = 0;
  if ( !v3 && clienttools->IsInRecordingMode(this: clienttools) )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v2 = KeyValues::KeyValues(this: v4, setName: "OldParticleSystem_Destroy");
    KeyValues::SetInt(this: v2, keyName: "id", value: this->m_nToolParticleEffectId);
    KeyValues::SetFloat(this: v2, keyName: "time", value: *(float *)(gpGlobals.m_Index + 12));
    ToolFramework_PostToolMessage(hEntity: 0, msg: v2);
    this->m_nToolParticleEffectId = -1;
  }
  CParticleEffectBinding::~CParticleEffectBinding(this: &this->m_ParticleEffect);
  this->__vftable = (CParticleEffect_vtbl *)&IParticleEffect::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10139350
// Name: public: struct Particle __near * CParticleEffect::AddParticle(unsigned int,class CParticleSubTexture __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
Particle *__thiscall CParticleEffect::AddParticle(
        CParticleEffect *this,
        unsigned int particleSize,
        CParticleSubTexture *material,
        const Vector *origin)
{
  Particle *result; // eax

  result = CParticleEffectBinding::AddParticle(
             this: &this->m_ParticleEffect,
             sizeInBytes: particleSize,
             hMaterial: material);
  if ( result != nullptr )
    result->m_Pos = *origin;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10139390
// Name: protected: CSimpleEmitter::CSimpleEmitter(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSimpleEmitter *__thiscall CSimpleEmitter::CSimpleEmitter(CSimpleEmitter *this, const char *pDebugName)
{
  CParticleEffect::CParticleEffect(this, pName: pDebugName);
  this->m_flNearClipMin = 16.0;
  this->__vftable = (CSimpleEmitter_vtbl *)&CSimpleEmitter::`vftable';
  this->m_flNearClipMax = 64.0;
  this->m_nSplitScreenPlayerSlot = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101393E0
// Name: protected: virtual CSimpleEmitter::~CSimpleEmitter(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleEmitter::~CSimpleEmitter(CSimpleEmitter *this)
{
  this->__vftable = (CSimpleEmitter_vtbl *)&CSimpleEmitter::`vftable';
  CParticleEffect::~CParticleEffect(this);
}

//------------------------------------------------------------------------------
// Address: 0x101393F0
// Name: public: class SimpleParticle __near * CSimpleEmitter::AddSimpleParticle(class CParticleSubTexture __near *,class Vector const __near &,float,unsigned char)
// Source: json
//------------------------------------------------------------------------------
SimpleParticle *__userpurge CSimpleEmitter::AddSimpleParticle@<eax>(
        CSimpleEmitter *this@<ecx>,
        int a2@<esi>,
        CParticleSubTexture *hMaterial,
        const Vector *vOrigin,
        float flDieTime,
        unsigned __int8 uchSize)
{
  SimpleParticle *result; // eax

  result = (SimpleParticle *)CParticleEffectBinding::AddParticle(
                               this: &this->m_ParticleEffect,
                               a2,
                               sizeInBytes: 60,
                               hMaterial);
  if ( result == nullptr )
    return nullptr;
  result->m_Pos = *vOrigin;
  result->m_Pos = *vOrigin;
  result->m_vecVelocity.x = 0.0;
  result->m_vecVelocity.y = 0.0;
  result->m_vecVelocity.z = 0.0;
  result->m_flRoll = 0.0;
  result->m_flRollDelta = 0.0;
  result->m_flLifetime = 0.0;
  result->m_flDieTime = flDieTime;
  result->m_uchColor[0] = 0;
  *(_DWORD *)&result->m_uchColor[1] = -65536;
  result->m_uchEndSize = uchSize;
  result->m_uchStartSize = uchSize;
  result->m_iFlags = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10139480
// Name: protected: virtual void CSimpleEmitter::UpdateVelocity(class SimpleParticle __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleEmitter::UpdateVelocity(CSimpleEmitter *this, SimpleParticle *pParticle, float timeDelta)
{
  float x; // xmm2_4
  float v4; // xmm1_4
  float v5; // xmm2_4
  bool v6; // cc
  float v7; // xmm4_4
  float y; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  bool v11; // cc
  float v12; // xmm2_4
  Vector vecWind; // [esp+Ch] [ebp-Ch] BYREF

  if ( (pParticle->m_iFlags & 1) == 0 )
    return;
  GetWindspeedAtTime(flTime: *(float *)(gpGlobals.m_Index + 12), vecVelocity: &vecWind);
  x = pParticle->m_vecVelocity.x;
  v4 = vecWind.x;
  if ( vecWind.x > x )
  {
    v5 = (float)(timeDelta * 50.0) + pParticle->m_vecVelocity.x;
    pParticle->m_vecVelocity.x = v5;
    v6 = v5 <= v4;
    goto LABEL_6;
  }
  if ( x > vecWind.x )
  {
    v7 = pParticle->m_vecVelocity.x - (float)(timeDelta * 50.0);
    pParticle->m_vecVelocity.x = v7;
    v6 = v4 <= v7;
LABEL_6:
    if ( !v6 )
      pParticle->m_vecVelocity.x = v4;
  }
  y = pParticle->m_vecVelocity.y;
  v9 = vecWind.y;
  if ( vecWind.y <= y )
  {
    if ( y <= vecWind.y )
      return;
    v12 = pParticle->m_vecVelocity.y - (float)(timeDelta * 50.0);
    pParticle->m_vecVelocity.y = v12;
    v11 = v9 <= v12;
  }
  else
  {
    v10 = (float)(timeDelta * 50.0) + y;
    pParticle->m_vecVelocity.y = v10;
    v11 = v10 <= v9;
  }
  if ( !v11 )
    pParticle->m_vecVelocity.y = v9;
}

//------------------------------------------------------------------------------
// Address: 0x10139550
// Name: protected: virtual class Vector CSimpleEmitter::UpdateColor(class SimpleParticle const __near *)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CSimpleEmitter::UpdateColor(CFireParticle *this, Vector *result, const SimpleParticle *pParticle)
{
  if ( (_S5_108 & 1) == 0 )
    _S5_108 |= 1u;
  cColor.x = (float)pParticle->m_uchColor[0] * 0.0039215689;
  cColor.y = (float)pParticle->m_uchColor[1] * 0.0039215689;
  cColor.z = (float)pParticle->m_uchColor[2] * 0.0039215689;
  *result = cColor;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101395E0
// Name: public: virtual void CEmberEffect::UpdateVelocity(class SimpleParticle __near *,float)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CEmberEffect::UpdateVelocity(CEmberEffect *this, SimpleParticle *pParticle, float timeDelta)
{
  Vector *p_m_vecVelocity; // esi
  IUniformRandomStream *v4; // ecx
  IUniformRandomStream *v5; // ecx
  IUniformRandomStream *v6; // ecx
  double v7; // st7
  float offset; // [esp+Ch] [ebp-Ch]
  float offset_4; // [esp+10h] [ebp-8h]
  float speed; // [esp+20h] [ebp+8h]

  p_m_vecVelocity = &pParticle->m_vecVelocity;
  speed = VectorNormalize(vec: &pParticle->m_vecVelocity) - timeDelta * 12.0;
  _RandomFloat(this: v4, a2: -0.125, a3: 0.125);
  offset_4 = _RandomFloat(this: v5, a2: -0.125, a3: 0.125);
  v7 = _RandomFloat(this: v6, a2: -0.125, a3: 0.125);
  p_m_vecVelocity->x = offset + p_m_vecVelocity->x;
  p_m_vecVelocity->y = p_m_vecVelocity->y + offset_4;
  p_m_vecVelocity->z = v7 + p_m_vecVelocity->z;
  VectorNormalize(vec: p_m_vecVelocity);
  p_m_vecVelocity->x = speed * p_m_vecVelocity->x;
  p_m_vecVelocity->y = p_m_vecVelocity->y * speed;
  p_m_vecVelocity->z = p_m_vecVelocity->z * speed;
}

//------------------------------------------------------------------------------
// Address: 0x101396C0
// Name: private: void CParticleEffect::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleEffect::Release(CParticleEffect *this)
{
  bool v1; // zf
  CParticleEffectBinding *p_m_ParticleEffect; // esi

  v1 = this->m_RefCount-- == 1;
  if ( v1 && (this->m_Flags & 2) != 0 )
  {
    p_m_ParticleEffect = &this->m_ParticleEffect;
    if ( CParticleEffectBinding::GetNumActiveParticles(this: &this->m_ParticleEffect) == 0 )
      p_m_ParticleEffect->m_Flags |= 1u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101396F0
// Name: public: virtual void CParticleEffect::NotifyDestroyParticle(struct Particle __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleEffect::NotifyDestroyParticle(CParticleEffect *this, Particle *pParticle)
{
  int m_Flags; // eax

  if ( CParticleEffectBinding::GetNumActiveParticles(this: &this->m_ParticleEffect) == 0 && this->m_RefCount == 0 )
  {
    m_Flags = this->m_Flags;
    if ( (m_Flags & 2) != 0 && (m_Flags & 4) == 0 )
      this->m_ParticleEffect.m_Flags |= 1u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10139730
// Name: public: void CParticleEffect::SetSortOrigin(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleEffect::SetSortOrigin(CParticleEffect *this, const Vector *vSortOrigin)
{
  if ( (this->m_ParticleEffect.m_Flags & 8) != 0 )
  {
    if ( CParticleEffectBinding::EnlargeBBoxToContain(this: &this->m_ParticleEffect, pt: vSortOrigin) )
      this->m_vSortOrigin = *vSortOrigin;
  }
  else
  {
    this->m_vSortOrigin = *vSortOrigin;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101397D0
// Name: public: virtual void CSimpleEmitter::RenderParticles(class CParticleRenderIterator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleEmitter::RenderParticles(CSimpleEmitter *this, CParticleRenderIterator *pIterator)
{
  int m_nSplitScreenPlayerSlot; // eax
  CEffectMaterial *m_pMaterial; // ecx
  Particle *m_pNext; // eax
  Particle *i; // esi
  CParticleMgr *v8; // eax
  float y; // xmm1_4
  float x; // xmm2_4
  float z; // xmm3_4
  float v12; // xmm4_4
  float v13; // xmm0_4
  float m_flNearClipMin; // xmm2_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  float m_flNearClipMax; // xmm1_4
  float v19; // xmm0_4
  float (__thiscall *UpdateScale)(CSimpleEmitter *, const SimpleParticle *); // eax
  float v21; // xmm0_4
  const Vector *v22; // eax
  float angle; // [esp+10h] [ebp-30h]
  float anglea; // [esp+10h] [ebp-30h]
  float alpha[3]; // [esp+20h] [ebp-20h] BYREF
  Vector tPos; // [esp+2Ch] [ebp-14h] BYREF
  float sortKey; // [esp+38h] [ebp-8h]
  ParticleDraw *pDraw; // [esp+3Ch] [ebp-4h]
  CParticleRenderIterator *pIteratora; // [esp+48h] [ebp+8h]

  m_nSplitScreenPlayerSlot = this->m_nSplitScreenPlayerSlot;
  if ( m_nSplitScreenPlayerSlot == -1 || m_nSplitScreenPlayerSlot == 0 )
  {
    m_pMaterial = pIterator->m_pMaterial;
    pIterator->m_bGotFirst = true;
    m_pNext = m_pMaterial->m_Particles.m_pNext;
    pIterator->m_pCur = m_pNext;
    if ( m_pNext != &m_pMaterial->m_Particles )
    {
      pIterator->m_pParticleDraw->m_pSubTexture = m_pNext->m_pSubTexture;
      for ( i = pIterator->m_pCur; i != nullptr; i = (Particle *)CParticleRenderIterator::GetNext(
                                                                   this: pIterator,
                                                                   sortKey) )
      {
        v8 = ParticleMgr();
        y = i->m_Pos.y;
        x = i->m_Pos.x;
        z = i->m_Pos.z;
        v12 = v8->m_mModelView.m[1][1];
        tPos.x = (float)((float)((float)(v8->m_mModelView.m[0][1] * y) + (float)(v8->m_mModelView.m[0][0] * x))
                       + (float)(v8->m_mModelView.m[0][2] * z))
               + v8->m_mModelView.m[0][3];
        tPos.y = (float)((float)((float)(v8->m_mModelView.m[1][0] * x) + (float)(v12 * y))
                       + (float)(v8->m_mModelView.m[1][2] * z))
               + v8->m_mModelView.m[1][3];
        v13 = (float)(v8->m_mModelView.m[2][0] * x) + (float)(v8->m_mModelView.m[2][1] * y);
        m_flNearClipMin = this->m_flNearClipMin;
        v15 = (float)(v13 + (float)(v8->m_mModelView.m[2][2] * z)) + v8->m_mModelView.m[2][3];
        v16 = (float)(int)v15;
        tPos.z = v15;
        LODWORD(v17) = LODWORD(v15) ^ _mask__NegFloat_;
        sortKey = v16;
        m_flNearClipMax = this->m_flNearClipMax;
        if ( v17 <= m_flNearClipMax )
        {
          if ( v17 <= m_flNearClipMin )
            v19 = 0.0;
          else
            v19 = (float)(v17 - m_flNearClipMin) / (float)(m_flNearClipMax - m_flNearClipMin);
        }
        else
        {
          v19 = 1.0;
        }
        UpdateScale = this->UpdateScale;
        *(float *)&pIteratora = v19;
        v21 = i[1].m_Pos.x;
        pDraw = pIterator->m_pParticleDraw;
        angle = ((double (__thiscall *)(CSimpleEmitter *, Particle *, _DWORD))UpdateScale)(
                  a1: this,
                  a2: i,
                  a3: LODWORD(v21));
        anglea = ((double (__thiscall *)(CSimpleEmitter *, Particle *, _DWORD))this->UpdateAlpha)(
                   a1: this,
                   a2: i,
                   a3: LODWORD(angle))
               * *(float *)&pIteratora;
        v22 = (const Vector *)((int (__thiscall *)(CSimpleEmitter *))this->UpdateColor)(a1: this);
        RenderParticle_ColorSizeAngle(
          pDraw,
          pos: &tPos,
          color: v22,
          alpha: COERCE_FLOAT(alpha),
          size: *(float *)&i,
          angle: anglea);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10139B60
// Name: class IParticleEffect __near * CSimpleEmitter_Factory(void)
// Source: json
//------------------------------------------------------------------------------
CParticleEffect *__cdecl CSimpleEmitter_Factory()
{
  CParticleEffect *v0; // eax
  CParticleEffect *v1; // esi
  bool v2; // zf
  CParticleEffect *result; // eax

  v0 = (CParticleEffect *)MemAlloc_Alloc(nSize: 0x108u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CParticleEffect::CParticleEffect(this: v0, pName: "CSimpleEmitter");
    v1[1].__vftable = (CParticleEffect_vtbl *)1098907648;
    v1->__vftable = (CParticleEffect_vtbl *)&CSimpleEmitter::`vftable';
    v1[1].m_pDebugName = (const char *)1115684864;
    v1[1].m_ParticleEffect.__vftable = (CParticleEffectBinding_vtbl *)-1;
  }
  else
  {
    v1 = nullptr;
  }
  ++v1->m_RefCount;
  v1->m_Flags |= 2u;
  v2 = v1->m_RefCount-- == 1;
  if ( !v2 || (v1->m_Flags & 2) == 0 )
    return v1;
  v2 = CParticleEffectBinding::GetNumActiveParticles(this: &v1->m_ParticleEffect) == 0;
  result = v1;
  if ( v2 )
    v1->m_ParticleEffect.m_Flags |= 1u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1023EEB0
// Name: public: virtual class Vector CEmberEffect::UpdateColor(class SimpleParticle const __near *)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CEmberEffect::UpdateColor(CEmberEffect *this, Vector *result, const SimpleParticle *pParticle)
{
  int v3; // edx
  int v4; // ecx
  float v6; // xmm0_4

  v3 = pParticle->m_uchColor[1];
  v4 = pParticle->m_uchColor[2];
  v6 = 1.0 - (float)(pParticle->m_flLifetime / pParticle->m_flDieTime);
  result->x = (float)((float)pParticle->m_uchColor[0] * v6) * 0.0039215689;
  result->y = (float)((float)v3 * v6) * 0.0039215689;
  result->z = (float)((float)v4 * v6) * 0.0039215689;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1024A110
// Name: public: virtual float CFireSmokeEffect::UpdateAlpha(class SimpleParticle const __near *)
// Source: json
//------------------------------------------------------------------------------
long double __thiscall CFireSmokeEffect::UpdateAlpha(CFireSmokeEffect *this, const SimpleParticle *pParticle)
{
  return sin(pParticle->m_flLifetime / pParticle->m_flDieTime * 3.141592653589793)
       * ((double)pParticle->m_uchStartAlpha
        * 0.0039215689);
}

//------------------------------------------------------------------------------
// Address: 0x101399A0
// Name: public: static class CSmartPtr<class CSimpleEmitter,class CRefCountAccessor> CSimpleEmitter::Create(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSmartPtr<CSimpleEmitter,CRefCountAccessor> *__cdecl CSimpleEmitter::Create(
        CSmartPtr<CSimpleEmitter,CRefCountAccessor> *result,
        const char *pDebugName)
{
  CSimpleEmitter *v2; // esi

  v2 = (CSimpleEmitter *)MemAlloc_Alloc(nSize: 0x108u);
  if ( v2 != nullptr )
  {
    CParticleEffect::CParticleEffect(this: v2, pName: pDebugName);
    v2->m_flNearClipMin = 16.0;
    v2->__vftable = (CSimpleEmitter_vtbl *)&CSimpleEmitter::`vftable';
    v2->m_flNearClipMax = 64.0;
    v2->m_nSplitScreenPlayerSlot = -1;
  }
  else
  {
    v2 = nullptr;
  }
  v2->m_Flags |= 2u;
  ++v2->m_RefCount;
  result->m_pObj = v2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10139A10
// Name: public: static class CSmartPtr<class CEmberEffect,class CRefCountAccessor> CEmberEffect::Create(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSmartPtr<CEmberEffect,CRefCountAccessor> *__cdecl CEmberEffect::Create(
        CSmartPtr<CEmberEffect,CRefCountAccessor> *result,
        const char *pDebugName)
{
  CEmberEffect *v2; // esi

  v2 = (CEmberEffect *)MemAlloc_Alloc(nSize: 0x108u);
  if ( v2 != nullptr )
  {
    CParticleEffect::CParticleEffect(this: v2, pName: pDebugName);
    v2->m_flNearClipMin = 16.0;
    v2->m_flNearClipMax = 64.0;
    v2->m_nSplitScreenPlayerSlot = -1;
    v2->__vftable = (CEmberEffect_vtbl *)&CEmberEffect::`vftable';
  }
  else
  {
    v2 = nullptr;
  }
  v2->m_Flags |= 2u;
  ++v2->m_RefCount;
  result->m_pObj = v2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10139A80
// Name: public: static class CSmartPtr<class CFireSmokeEffect,class CRefCountAccessor> CFireSmokeEffect::Create(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSmartPtr<CFireSmokeEffect,CRefCountAccessor> *__cdecl CFireSmokeEffect::Create(
        CSmartPtr<CFireSmokeEffect,CRefCountAccessor> *result,
        const char *pDebugName)
{
  CFireSmokeEffect *v2; // esi

  v2 = (CFireSmokeEffect *)MemAlloc_Alloc(nSize: 0x118u);
  if ( v2 != nullptr )
  {
    CParticleEffect::CParticleEffect(this: v2, pName: pDebugName);
    v2->m_flNearClipMin = 16.0;
    v2->m_flNearClipMax = 64.0;
    v2->m_nSplitScreenPlayerSlot = -1;
    v2->__vftable = (CFireSmokeEffect_vtbl *)&CFireSmokeEffect::`vftable';
  }
  else
  {
    v2 = nullptr;
  }
  v2->m_Flags |= 2u;
  ++v2->m_RefCount;
  result->m_pObj = v2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10139AF0
// Name: public: static class CSmartPtr<class CFireParticle,class CRefCountAccessor> CFireParticle::Create(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSmartPtr<CFireParticle,CRefCountAccessor> *__cdecl CFireParticle::Create(
        CSmartPtr<CFireParticle,CRefCountAccessor> *result,
        const char *pDebugName)
{
  CFireParticle *v2; // esi

  v2 = (CFireParticle *)MemAlloc_Alloc(nSize: 0x108u);
  if ( v2 != nullptr )
  {
    CParticleEffect::CParticleEffect(this: v2, pName: pDebugName);
    v2->m_flNearClipMin = 16.0;
    v2->m_flNearClipMax = 64.0;
    v2->m_nSplitScreenPlayerSlot = -1;
    v2->__vftable = (CFireParticle_vtbl *)&CFireParticle::`vftable';
  }
  else
  {
    v2 = nullptr;
  }
  v2->m_Flags |= 2u;
  ++v2->m_RefCount;
  result->m_pObj = v2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10139C00
// Name: __CreateCParticleSystemQueryIParticleSystemQuery_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CParticleSystemQuery *__cdecl _CreateCParticleSystemQueryIParticleSystemQuery_interface()
{
  return &s_ParticleSystemQuery;
}
