// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/fx_trail.cpp
// Functions: 4
// ============================================================

#include "game\client\fx_trail.h"

//------------------------------------------------------------------------------
// Address: 0x100DF0E0
// Name: public: virtual C_ParticleTrail::~C_ParticleTrail(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_ParticleTrail::~C_ParticleTrail(C_ParticleTrail *this)
{
  CParticleMgr *m_pParticleMgr; // ecx

  m_pParticleMgr = this->m_pParticleMgr;
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_ParticleTrail_vtbl *)&C_ParticleTrail::`vftable'{for `IClientUnknown'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_ParticleTrail::`vftable'{for `IClientRenderable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_ParticleTrail::`vftable'{for `IClientNetworkable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_ParticleTrail::`vftable'{for `IClientThinkable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_ParticleTrail::`vftable'{for `C_BaseEntity'};
  this->C_BaseParticleEntity::IParticleEffect::__vftable = (IParticleEffect_vtbl *)&C_ParticleTrail::`vftable'{for `IParticleEffect'};
  this->IPrototypeAppEffect::__vftable = (IPrototypeAppEffect_vtbl *)&C_ParticleTrail::`vftable';
  if ( m_pParticleMgr != nullptr )
    CParticleMgr::RemoveEffect(this: m_pParticleMgr, pEffect: &this->m_ParticleEffect);
  this->IPrototypeAppEffect::__vftable = (IPrototypeAppEffect_vtbl *)&IPrototypeAppEffect::`vftable';
  C_BaseParticleEntity::~C_BaseParticleEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x100DF150
// Name: public: virtual void C_ParticleTrail::GetAimEntOrigin(class IClientEntity __near *,class Vector __near *,class QAngle __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_ParticleTrail::GetAimEntOrigin(
        C_ParticleTrail *this,
        IClientEntity *pAttachedTo,
        Vector *pAbsOrigin,
        QAngle *pAbsAngles)
{
  C_BaseEntity *v5; // eax
  int m_nAttachment; // edx

  v5 = pAttachedTo->GetBaseEntity(this: pAttachedTo);
  if ( v5 != nullptr && (m_nAttachment = this->m_nAttachment) > 0 )
    v5->GetAttachment_2(this: &v5->IClientRenderable, a2: m_nAttachment, a3: pAbsOrigin, a4: pAbsAngles);
  else
    C_BaseEntity::GetAimEntOrigin(this, pAttachedTo, pOrigin: pAbsOrigin, pAngles: pAbsAngles);
}

//------------------------------------------------------------------------------
// Address: 0x100DF1F0
// Name: public: virtual void C_ParticleTrail::Start(class CParticleMgr __near *,class IPrototypeArgAccess __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_ParticleTrail::Start(C_ParticleTrail *this, CParticleMgr *pParticleMgr, IPrototypeArgAccess *pArgs)
{
  IParticleEffect *v4; // eax

  if ( this == (C_ParticleTrail *)2664 )
    v4 = nullptr;
  else
    v4 = (IParticleEffect *)((char *)this - 232);
  if ( CParticleMgr::AddEffect(this: pParticleMgr, pEffect: (CParticleEffectBinding *)((char *)this - 228), pSim: v4) != 0 )
    this->m_iszScriptId = (const char *)pParticleMgr;
}

//------------------------------------------------------------------------------
// Address: 0x100DF250
// Name: public: C_ParticleTrail::C_ParticleTrail(void)
// Source: json
//------------------------------------------------------------------------------
C_ParticleTrail *__thiscall C_ParticleTrail::C_ParticleTrail(C_ParticleTrail *this)
{
  C_BaseParticleEntity::C_BaseParticleEntity(this);
  this->IPrototypeAppEffect::__vftable = (IPrototypeAppEffect_vtbl *)&IPrototypeAppEffect::`vftable';
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_ParticleTrail_vtbl *)&C_ParticleTrail::`vftable'{for `IClientUnknown'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_ParticleTrail::`vftable'{for `IClientRenderable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_ParticleTrail::`vftable'{for `IClientNetworkable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_ParticleTrail::`vftable'{for `IClientThinkable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_ParticleTrail::`vftable'{for `C_BaseEntity'};
  this->C_BaseParticleEntity::IParticleEffect::__vftable = (IParticleEffect_vtbl *)&C_ParticleTrail::`vftable'{for `IParticleEffect'};
  this->IPrototypeAppEffect::__vftable = (IPrototypeAppEffect_vtbl *)&C_ParticleTrail::`vftable';
  this->m_ParticleSpawn.m_TimeBetweenEvents = -1.0;
  this->m_ParticleSpawn.m_fNextEvent = 0.0;
  return this;
}
