// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_smoke_trail.cpp
// Functions: 88
// ============================================================

#include "game\client\c_smoke_trail.h"

//------------------------------------------------------------------------------
// Address: 0x100DF1B0
// Name: public: virtual void C_RocketTrail::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_RocketTrail::OnDataChanged(C_ParticleTrail *this, DataUpdateType_t updateType)
{
  int v3; // edi
  CParticleMgr *v4; // eax

  C_BaseEntity::OnDataChanged(this, type: updateType);
  if ( updateType == DATA_UPDATE_CREATED )
  {
    v3 = *(_DWORD *)&this->m_bSimulate;
    v4 = ParticleMgr();
    (*(void (__thiscall **)(bool *, CParticleMgr *, _DWORD))(v3 + 4))(a1: &this->m_bSimulate, a2: v4, a3: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024A140
// Name: public: virtual class ClientClass __near * C_SmokeTrail::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_SmokeTrail::GetClientClass(C_SmokeTrail *this)
{
  return &__g_C_SmokeTrailClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1024A380
// Name: public: virtual void C_SmokeTrail::GetAimEntOrigin(class IClientEntity __near *,class Vector __near *,class QAngle __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SmokeTrail::GetAimEntOrigin(
        C_SmokeTrail *this,
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
// Address: 0x1024A3E0
// Name: public: void C_SmokeTrail::SetEmit(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SmokeTrail::SetEmit(C_SmokeTrail *this, bool bEmit)
{
  this->m_bEmit = bEmit;
}

//------------------------------------------------------------------------------
// Address: 0x1024A3F0
// Name: public: virtual class ClientClass __near * C_RocketTrail::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_RocketTrail::GetClientClass(C_RocketTrail *this)
{
  return &__g_C_RocketTrailClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1024A630
// Name: public: virtual void C_RocketTrail::GetAimEntOrigin(class IClientEntity __near *,class Vector __near *,class QAngle __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_RocketTrail::GetAimEntOrigin(
        C_RocketTrail *this,
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
// Address: 0x1024A690
// Name: public: virtual class ClientClass __near * C_SporeExplosion::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_SporeExplosion::GetClientClass(C_SporeExplosion *this)
{
  return &__g_C_SporeExplosionClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1024A7D0
// Name: public: virtual C_SporeExplosion::~C_SporeExplosion(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SporeExplosion::~C_SporeExplosion(C_SporeExplosion *this)
{
  CParticleMgr *m_pParticleMgr; // ecx

  m_pParticleMgr = this->m_pParticleMgr;
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_SporeExplosion_vtbl *)&C_SporeExplosion::`vftable'{for `IClientUnknown'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_SporeExplosion::`vftable'{for `IClientRenderable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_SporeExplosion::`vftable'{for `IClientNetworkable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_SporeExplosion::`vftable'{for `IClientThinkable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_SporeExplosion::`vftable'{for `C_BaseEntity'};
  this->C_BaseParticleEntity::IParticleEffect::__vftable = (IParticleEffect_vtbl *)&C_SporeExplosion::`vftable'{for `IParticleEffect'};
  this->IPrototypeAppEffect::__vftable = (IPrototypeAppEffect_vtbl *)&C_SporeExplosion::`vftable';
  if ( m_pParticleMgr != nullptr )
    CParticleMgr::RemoveEffect(this: m_pParticleMgr, pEffect: &this->m_ParticleEffect);
  this->IPrototypeAppEffect::__vftable = (IPrototypeAppEffect_vtbl *)&IPrototypeAppEffect::`vftable';
  C_BaseParticleEntity::~C_BaseParticleEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x1024A840
// Name: public: virtual void C_SporeExplosion::Start(class CParticleMgr __near *,class IPrototypeArgAccess __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SporeExplosion::Start(C_SporeExplosion *this, CParticleMgr *pParticleMgr, IPrototypeArgAccess *pArgs)
{
  IParticleEffect *v4; // eax
  CSimpleEmitter *v5; // eax
  CParticleEffect *v6; // edi
  CParticleEffect *v7; // ecx
  VarMapEntry_t *PMaterial; // eax
  int v9; // edx
  const Vector *v10; // eax

  if ( this == (C_SporeExplosion *)2664 )
    v4 = nullptr;
  else
    v4 = (IParticleEffect *)((char *)this - 232);
  if ( CParticleMgr::AddEffect(this: pParticleMgr, pEffect: (CParticleEffectBinding *)((char *)this - 228), pSim: v4) != 0 )
  {
    v5 = (CSimpleEmitter *)MemAlloc_Alloc(nSize: 0x108u);
    v6 = v5;
    if ( v5 != nullptr )
    {
      CSimpleEmitter::CSimpleEmitter(this: v5, pDebugName: "C_SporeExplosion");
      v6->__vftable = (CParticleEffect_vtbl *)&SporeEffect::`vftable';
      v7 = v6;
    }
    else
    {
      v7 = nullptr;
    }
    this->m_VarMap.m_Entries.m_Size = (int)v7;
    if ( v7 != nullptr )
    {
      PMaterial = (VarMapEntry_t *)CParticleEffect::GetPMaterial(this: v7, name: "particle/fire");
      v9 = *((_DWORD *)this - 666);
      this->m_VarMap.m_Entries.m_Memory.m_pMemory = PMaterial;
      v10 = (const Vector *)(*(int (__thiscall **)(char *))(v9 + 40))(a1: (char *)this - 2664);
      CParticleEffect::SetSortOrigin(this: (CParticleEffect *)this->m_VarMap.m_Entries.m_Size, vSortOrigin: v10);
      CSimpleEmitter::SetNearClip(
        this: (CSimpleEmitter *)this->m_VarMap.m_Entries.m_Size,
        nearClipMin: 64.0,
        nearClipMax: 128.0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024A900
// Name: public: virtual void RPGShotDownPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RPGShotDownPrecache::CResourcePrecacher::Cache(
        RPGShotDownPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "Missile.ShotDown",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1024A930
// Name: public: virtual class ClientClass __near * C_SporeTrail::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_SporeTrail::GetClientClass(C_SporeTrail *this)
{
  return &__g_C_SporeTrailClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1024AA80
// Name: public: virtual void C_SporeTrail::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SporeTrail::OnDataChanged(C_SporeTrail *this, DataUpdateType_t updateType)
{
  int v3; // edi
  CParticleMgr *v4; // eax

  C_BaseEntity::OnDataChanged(this, type: updateType);
  if ( updateType == DATA_UPDATE_CREATED )
  {
    v3 = *((_DWORD *)this - 2);
    v4 = ParticleMgr();
    (*(void (__thiscall **)(char *, CParticleMgr *, _DWORD))(v3 + 688))(a1: (char *)this - 8, a2: v4, a3: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024AAB0
// Name: public: virtual void C_SporeTrail::StartRender(class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SporeTrail::StartRender(C_SporeTrail *this, VMatrix *effectMatrix)
{
  const VMatrix *v2; // eax
  VMatrix result; // [esp+4h] [ebp-40h] BYREF

  v2 = VMatrix::operator*(this: effectMatrix, &result, vm: (const VMatrix *)&this->m_hNetworkMoveParent);
  VMatrix::operator=(this: effectMatrix, mOther: v2);
}

//------------------------------------------------------------------------------
// Address: 0x1024AAE0
// Name: public: virtual class ClientClass __near * C_FireTrail::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_FireTrail::GetClientClass(C_FireTrail *this)
{
  return &__g_C_FireTrailClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1024AB90
// Name: public: virtual class ClientClass __near * C_DustTrail::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_DustTrail::GetClientClass(C_DustTrail *this)
{
  return &__g_C_DustTrailClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1024AD90
// Name: public: virtual void PrecacheEffectDusttrailPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PrecacheEffectDusttrailPrecache::CResourcePrecacher::Cache(
        PrecacheEffectDusttrailPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "particle/smokesprites_0001",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1024ADF0
// Name: public: int CParticleEffect::AllocateToolParticleEffectId(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CParticleEffect::AllocateToolParticleEffectId(CParticleEffect *this)
{
  CParticleMgr *v2; // ecx
  int result; // eax

  v2 = ParticleMgr();
  result = v2->m_nToolParticleEffectId;
  v2->m_nToolParticleEffectId = result + 1;
  this->m_nToolParticleEffectId = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1024AE20
// Name: public: virtual void CDustFollower::UpdateVelocity(class SimpleParticle __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDustFollower::UpdateVelocity(CDustFollower *this, SimpleParticle *pParticle, unsigned int timeDelta)
{
  __m128 v3; // xmm0
  double v4; // xmm0_8
  float v5; // xmm2_4
  float v6; // xmm3_4

  v3 = (__m128)timeDelta;
  v3.m128_f32[0] = *(float *)&timeDelta * -2.3104906;
  __libm_sse2_exp(a1: _mm_cvtps_pd(v3));
  *(float *)&v4 = v4;
  v5 = pParticle->m_vecVelocity.y * *(float *)&v4;
  v6 = pParticle->m_vecVelocity.z * *(float *)&v4;
  pParticle->m_vecVelocity.x = pParticle->m_vecVelocity.x * *(float *)&v4;
  pParticle->m_vecVelocity.y = v5;
  pParticle->m_vecVelocity.z = v6;
}

//------------------------------------------------------------------------------
// Address: 0x1024AE70
// Name: public: virtual float CDustFollower::UpdateRoll(class SimpleParticle __near *,float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CDustFollower::UpdateRoll(CDustFollower *this, SimpleParticle *pParticle, unsigned int timeDelta)
{
  __m128 v4; // xmm0
  double result; // st7
  double v6; // xmm0_8
  float pParticlea; // [esp+Ch] [ebp+8h]

  pParticlea = pParticle->m_flRollDelta;
  v4 = (__m128)timeDelta;
  v4.m128_f32[0] = *(float *)&timeDelta * -1.3862944;
  pParticle->m_flRoll = (float)(pParticlea * *(float *)&timeDelta) + pParticle->m_flRoll;
  __libm_sse2_exp(a1: _mm_cvtps_pd(v4));
  result = pParticle->m_flRoll;
  *(float *)&v6 = v6;
  pParticle->m_flRollDelta = *(float *)&v6 * pParticlea;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1024AF30
// Name: public: void C_SmokeTrail::SetSpawnRate(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SmokeTrail::SetSpawnRate(C_SmokeTrail *this, float rate)
{
  this->m_SpawnRate = rate;
  this->m_ParticleSpawn.m_TimeBetweenEvents = 1.0 / rate;
  this->m_ParticleSpawn.m_fNextEvent = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1024AF70
// Name: public: virtual void C_SmokeTrail::Update(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SmokeTrail::Update(C_SmokeTrail *this, float fTimeDelta)
{
  float z; // xmm0_4
  int (__thiscall *v4)(char *); // eax
  float *v5; // eax
  IUniformRandomStream *v6; // ecx
  float v7; // xmm0_4
  float v8; // xmm1_4
  IUniformRandomStream *v9; // ecx
  IUniformRandomStream *v10; // ecx
  CParticleEffect *v11; // esi
  float v12; // xmm1_4
  int (__thiscall *RandomInt)(IUniformRandomStream *, int, int); // edx
  int v14; // eax
  Particle *v15; // eax
  Particle *v16; // esi
  IUniformRandomStream *v17; // ecx
  IUniformRandomStream *v18; // ecx
  float (__thiscall *RandomFloat)(IUniformRandomStream *, float, float); // eax
  double v20; // st7
  Particle *v21; // xmm1_4
  CParticleSubTexture *v22; // xmm2_4
  double v23; // st7
  int m_iHealth; // xmm1_4
  int m_fFlags; // xmm2_4
  int m_nNextThinkTick; // xmm3_4
  float (__thiscall *v27)(IUniformRandomStream *, float, float); // eax
  float v28; // xmm3_4
  float v29; // xmm1_4
  float v30; // xmm0_4
  float v31; // xmm2_4
  double v32; // st7
  float v33; // xmm0_4
  float x; // [esp+4h] [ebp-54h]
  Vector vecForward; // [esp+14h] [ebp-44h] BYREF
  Vector offsetColor; // [esp+20h] [ebp-38h]
  Vector vecOrigin; // [esp+2Ch] [ebp-2Ch]
  Vector offset; // [esp+38h] [ebp-20h] BYREF
  float alpha; // [esp+44h] [ebp-14h]
  float fldt; // [esp+48h] [ebp-10h]
  float v41; // [esp+4Ch] [ebp-Ch]
  float v42; // [esp+50h] [ebp-8h]
  float tempDelta; // [esp+54h] [ebp-4h]

  if ( *(_DWORD *)&this->m_iName[16] != 0 && LOBYTE(this->m_hNetworkMoveParent.m_Index) != 0 )
  {
    z = this->m_vecVelocity.z;
    if ( z == 0.0 || *(float *)(gpGlobals.m_Index + 12) < z )
    {
      tempDelta = fTimeDelta;
      C_BaseEntity::CalcAbsoluteVelocity(this: (C_SmokeTrail *)((char *)this - 2432));
      v4 = *(int (__thiscall **)(char *))(*((_DWORD *)this - 608) + 40);
      LODWORD(v41) = LODWORD(fTimeDelta) ^ _mask__NegFloat_;
      v5 = (float *)v4(a1: (char *)this - 2432);
      vecOrigin.x = (float)(COERCE_FLOAT(LODWORD(fTimeDelta) ^ _mask__NegFloat_) * *((float *)this - 572)) + *v5;
      vecOrigin.y = (float)(*((float *)this - 571) * COERCE_FLOAT(LODWORD(fTimeDelta) ^ _mask__NegFloat_)) + v5[1];
      vecOrigin.z = (float)(*((float *)this - 570) * COERCE_FLOAT(LODWORD(fTimeDelta) ^ _mask__NegFloat_)) + v5[2];
      C_BaseEntity::GetVectors(
        this: (C_SmokeTrail *)((char *)this - 2432),
        pForward: &vecForward,
        pRight: nullptr,
        pUp: nullptr);
      while ( 1 )
      {
        v7 = *(float *)&this->m_iName[8];
        v8 = tempDelta;
        if ( tempDelta < v7 )
          break;
        *(float *)&this->m_iName[8] = *(float *)&this->m_iName[4];
        tempDelta = v8 - v7;
        fldt = fTimeDelta - (float)(v8 - v7);
        x = this->m_vecNetworkOrigin.x;
        v41 = -x;
        v42 = x;
        offset.x = _RandomFloat(this: v6, a2: -x, a3: x);
        offset.y = _RandomFloat(this: v9, a2: v41, a3: v42);
        offset.z = _RandomFloat(this: v10, a2: v41, a3: v42);
        offset.x = offset.x + vecOrigin.x;
        offset.y = offset.y + vecOrigin.y;
        offset.z = offset.z + vecOrigin.z;
        C_BaseEntity::CalcAbsoluteVelocity(this: (C_SmokeTrail *)((char *)this - 2432));
        v11 = *(CParticleEffect **)&this->m_iName[16];
        offset.x = (float)(*((float *)this - 572) * fldt) + offset.x;
        offset.y = (float)(*((float *)this - 571) * fldt) + offset.y;
        v12 = *((float *)this - 570);
        LODWORD(vecForward.z) = &offset;
        offset.z = (float)(v12 * fldt) + offset.z;
        RandomInt = random->RandomInt;
        LODWORD(vecForward.y) = 1;
        vecForward.x = 0.0;
        v14 = ((int (__thiscall *)(IUniformRandomStream *))RandomInt)(a1: random);
        v15 = CParticleEffect::AddParticle(
                this: v11,
                particleSize: 0x3Cu,
                material: *((CParticleSubTexture **)&this->m_hGroundEntity.m_Index + v14),
                origin: (const Vector *)LODWORD(vecForward.x));
        v16 = v15;
        if ( v15 != nullptr )
        {
          v15[1].m_Pos.z = 0.0;
          v15[1].m_Pos.y = this->m_vecVelocity.y;
          *(float *)&v15[1].m_pPrev = _RandomFloat(this: v6, a2: -1.0, a3: 1.0);
          *(float *)&v16[1].m_pNext = _RandomFloat(this: v17, a2: -1.0, a3: 1.0);
          *(float *)&v16[1].m_pSubTexture = _RandomFloat(this: v18, a2: -1.0, a3: 1.0);
          RandomFloat = random->RandomFloat;
          vecOrigin.x = this->m_vecBaseVelocity.y;
          v20 = ((double (__thiscall *)(IUniformRandomStream *, _DWORD))RandomFloat)(
                  a1: random,
                  a2: LODWORD(this->m_vecBaseVelocity.x));
          *(float *)&v16[1].m_pPrev = *(float *)&v16[1].m_pPrev * v20;
          *(float *)&v16[1].m_pNext = *(float *)&v16[1].m_pNext * v20;
          *(float *)&v16[1].m_pSubTexture = v20 * *(float *)&v16[1].m_pSubTexture;
          C_BaseEntity::CalcAbsoluteVelocity(this: (C_SmokeTrail *)((char *)this - 2432));
          *(float *)&v21 = *((float *)this - 571) + *(float *)&v16[1].m_pNext;
          *(float *)&v22 = *((float *)this - 570) + *(float *)&v16[1].m_pSubTexture;
          *(float *)&v16[1].m_pPrev = *(float *)&v16[1].m_pPrev + *((float *)this - 572);
          v16[1].m_pNext = v21;
          v16[1].m_pSubTexture = v22;
          v23 = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))random->RandomFloat)(
                  a1: random,
                  a2: LODWORD(this->m_vecBaseVelocity.z),
                  a3: LODWORD(this->m_angNetworkAngles.x));
          *(float *)&v16[1].m_pPrev = vecForward.x * v23 + *(float *)&v16[1].m_pPrev;
          *(float *)&v16[1].m_pNext = vecForward.y * v23 + *(float *)&v16[1].m_pNext;
          *(float *)&v16[1].m_pSubTexture = v23 * vecForward.z + *(float *)&v16[1].m_pSubTexture;
          m_iHealth = this->m_iHealth;
          m_fFlags = this->m_fFlags;
          m_nNextThinkTick = m_iHealth;
          if ( *(float *)&this->m_nNextThinkTick > *(float *)&m_iHealth )
            m_nNextThinkTick = this->m_nNextThinkTick;
          if ( *(float *)&this->m_fFlags > *(float *)&m_nNextThinkTick )
            m_nNextThinkTick = this->m_fFlags;
          v27 = random->RandomFloat;
          v28 = 1.0 / *(float *)&m_nNextThinkTick;
          offsetColor.x = v28 * *(float *)&this->m_nNextThinkTick;
          offsetColor.y = *(float *)&m_iHealth * v28;
          offsetColor.z = *(float *)&m_fFlags * v28;
          alpha = ((double (__thiscall *)(IUniformRandomStream *, int, int))v27)(
                    a1: random,
                    a2: -1102263091,
                    a3: 1045220557);
          v29 = (float)(offsetColor.y * alpha) + *(float *)&this->m_iHealth;
          v30 = *(float *)&this->m_nNextThinkTick + (float)(offsetColor.x * alpha);
          v31 = *(float *)&this->m_fFlags + (float)(offsetColor.z * alpha);
          if ( v30 >= 0.0 )
          {
            if ( v30 > 1.0 )
              v30 = 1.0;
          }
          else
          {
            v30 = 0.0;
          }
          if ( v29 >= 0.0 )
          {
            if ( v29 > 1.0 )
              v29 = 1.0;
          }
          else
          {
            v29 = 0.0;
          }
          if ( v31 >= 0.0 )
          {
            if ( v31 > 1.0 )
              v31 = 1.0;
          }
          else
          {
            v31 = 0.0;
          }
          LOBYTE(v16[2].m_pPrev) = (int)(float)(v30 * 255.0);
          BYTE1(v16[2].m_pPrev) = (int)(float)(v29 * 255.0);
          BYTE2(v16[2].m_pPrev) = (int)(float)(v31 * 255.0);
          BYTE1(v16[2].m_pNext) = (int)this->m_angNetworkAngles.y;
          BYTE2(v16[2].m_pNext) = (int)this->m_angNetworkAngles.z;
          v32 = ((double (__cdecl *)(_DWORD, _DWORD))random->RandomFloat)(
                  a1: this->m_vecVelocity.x * 0.75,
                  a2: this->m_vecVelocity.x * 1.25);
          alpha = v32;
          if ( v32 >= 0.0 )
          {
            v33 = alpha;
            if ( alpha > 1.0 )
              v33 = 1.0;
          }
          else
          {
            v33 = 0.0;
          }
          *(_WORD *)((char *)&v16[2].m_pPrev + 3) = (unsigned __int8)(int)(float)(v33 * 255.0);
          v16[1].m_Pos.x = (float)random->RandomInt(this: random, a2: 0, a3: 360);
          *(float *)&v16[2].m_pSubTexture = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                              a1: random,
                                              a2: -1082130432,
                                              a3: 1065353216);
        }
      }
      *(float *)&this->m_iName[8] = *(float *)&this->m_iName[8] - tempDelta;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024B530
// Name: public: virtual void SporeEffect::UpdateVelocity(class SimpleParticle __near *,float)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall SporeEffect::UpdateVelocity(SporeEffect *this, SimpleParticle *pParticle, float timeDelta)
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
  speed = VectorNormalize(vec: &pParticle->m_vecVelocity) - timeDelta * 64.0;
  _RandomFloat(this: v4, a2: -0.5, a3: 0.5);
  offset_4 = _RandomFloat(this: v5, a2: -0.5, a3: 0.5);
  v7 = _RandomFloat(this: v6, a2: -0.5, a3: 0.5);
  p_m_vecVelocity->x = offset + p_m_vecVelocity->x;
  p_m_vecVelocity->y = p_m_vecVelocity->y + offset_4;
  p_m_vecVelocity->z = v7 + p_m_vecVelocity->z;
  VectorNormalize(vec: p_m_vecVelocity);
  p_m_vecVelocity->x = speed * p_m_vecVelocity->x;
  p_m_vecVelocity->y = p_m_vecVelocity->y * speed;
  p_m_vecVelocity->z = p_m_vecVelocity->z * speed;
}

//------------------------------------------------------------------------------
// Address: 0x1024B610
// Name: public: virtual class Vector SporeEffect::UpdateColor(class SimpleParticle const __near *)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall SporeEffect::UpdateColor(SporeEffect *this, Vector *result, const SimpleParticle *pParticle)
{
  __m128 m_flLifetime_low; // xmm0
  __m128i v4; // xmm0
  int v5; // edx
  double v7; // xmm0_8
  int v8; // ecx
  float v9; // xmm1_4

  m_flLifetime_low = (__m128)LODWORD(pParticle->m_flLifetime);
  m_flLifetime_low.m128_f32[0] = m_flLifetime_low.m128_f32[0] / pParticle->m_flDieTime;
  v4 = (__m128i)_mm_cvtps_pd(m_flLifetime_low);
  *(double *)v4.m128i_i64 = *(double *)v4.m128i_i64 * 3.141592653589793;
  __libm_sse2_sin(X: v4);
  v5 = pParticle->m_uchColor[1];
  v8 = pParticle->m_uchColor[2];
  v9 = v7 * (float)((float)pParticle->m_uchStartAlpha * 0.0039215689);
  result->x = (float)((float)pParticle->m_uchColor[0] * v9) * 0.0039215689;
  result->y = (float)((float)v5 * v9) * 0.0039215689;
  result->z = (float)((float)v8 * v9) * 0.0039215689;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1024B6B0
// Name: public: C_SporeExplosion::C_SporeExplosion(void)
// Source: json
//------------------------------------------------------------------------------
C_SporeExplosion *__thiscall C_SporeExplosion::C_SporeExplosion(C_SporeExplosion *this)
{
  C_BaseParticleEntity::C_BaseParticleEntity(this);
  this->IPrototypeAppEffect::__vftable = (IPrototypeAppEffect_vtbl *)&IPrototypeAppEffect::`vftable';
  this->m_flParticleLifetime = 5.0;
  this->m_flSpawnRate = 32.0;
  this->m_flStartSize = 32.0;
  this->m_flSpawnRadius = 32.0;
  this->m_pParticleMgr = nullptr;
  this->m_pSporeEffect = nullptr;
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_SporeExplosion_vtbl *)&C_SporeExplosion::`vftable'{for `IClientUnknown'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_SporeExplosion::`vftable'{for `IClientRenderable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_SporeExplosion::`vftable'{for `IClientNetworkable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_SporeExplosion::`vftable'{for `IClientThinkable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_SporeExplosion::`vftable'{for `C_BaseEntity'};
  this->C_BaseParticleEntity::IParticleEffect::__vftable = (IParticleEffect_vtbl *)&C_SporeExplosion::`vftable'{for `IParticleEffect'};
  this->IPrototypeAppEffect::__vftable = (IPrototypeAppEffect_vtbl *)&C_SporeExplosion::`vftable';
  this->m_flEndSize = 64.0;
  this->m_teParticleSpawn.m_TimeBetweenEvents = 0.03125;
  this->m_teParticleSpawn.m_fNextEvent = 0.0;
  *(_WORD *)&this->m_bEmit = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1024B7A0
// Name: public: virtual void C_SporeExplosion::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SporeExplosion::OnDataChanged(C_SporeExplosion *this, DataUpdateType_t updateType)
{
  float v3; // xmm0_4
  int v4; // ebx
  CParticleMgr *v5; // eax
  float v6; // xmm0_4
  float m_TimeBetweenEvents; // eax

  C_BaseEntity::OnDataChanged(this, type: updateType);
  if ( updateType != DATA_UPDATE_CREATED )
  {
    if ( LOBYTE(this->m_flSpawnRadius) != 0 )
    {
      v6 = *((float *)&this->m_bSimulate + 1);
      this->m_flEndSize = v6;
      *(float *)&this->m_bEmit = 1.0 / v6;
      this->m_hMaterial = nullptr;
    }
  }
  else
  {
    v3 = *((float *)&this->m_bSimulate + 1);
    this->m_flEndSize = v3;
    *(float *)&this->m_bEmit = 1.0 / v3;
    this->m_hMaterial = nullptr;
    v4 = *(_DWORD *)&this->m_bSimulate;
    v5 = ParticleMgr();
    (*(void (__thiscall **)(bool *, CParticleMgr *, _DWORD))(v4 + 4))(a1: &this->m_bSimulate, a2: v5, a3: 0);
  }
  m_TimeBetweenEvents = this->m_teParticleSpawn.m_TimeBetweenEvents;
  if ( BYTE1(this->m_flSpawnRadius) != 0 )
    *(_DWORD *)(LODWORD(m_TimeBetweenEvents) + 236) |= 4u;
  else
    *(_DWORD *)(LODWORD(m_TimeBetweenEvents) + 236) &= ~4u;
}

//------------------------------------------------------------------------------
// Address: 0x1024B860
// Name: private: void C_SporeExplosion::AddParticles(void)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __thiscall C_SporeExplosion::AddParticles(C_SporeExplosion *this)
{
  const QAngle *v2; // eax
  IUniformRandomStream *v3; // ecx
  int v4; // ebx
  float m_flSpawnRadius; // xmm1_4
  IUniformRandomStream *v6; // ecx
  IUniformRandomStream *v7; // ecx
  const Vector *v8; // eax
  double v9; // st7
  SporeEffect *m_pSporeEffect; // ecx
  double v11; // st7
  Particle *v12; // eax
  Particle *v13; // esi
  char v14; // al
  char v15; // al
  Particle *v16; // xmm1_4
  CParticleSubTexture *v17; // xmm2_4
  float v18; // xmm0_4
  IUniformRandomStream *v19; // ecx
  IUniformRandomStream *v20; // ecx
  float *v21; // eax
  double v22; // st7
  SporeEffect *v23; // ecx
  Particle *v24; // eax
  Particle *v25; // esi
  int m_flStartSize; // edx
  Particle *v27; // xmm1_4
  CParticleSubTexture *v28; // xmm2_4
  Vector origin; // [esp+14h] [ebp-30h] BYREF
  Vector dir; // [esp+20h] [ebp-24h] BYREF
  Vector offset; // [esp+2Ch] [ebp-18h]
  float v32; // [esp+38h] [ebp-Ch]
  float v33; // [esp+3Ch] [ebp-8h]
  float v34; // [esp+40h] [ebp-4h]

  v2 = this->GetAbsAngles(this);
  AngleVectors(angles: v2, forward: &dir);
  v4 = 0;
  while ( 1 )
  {
    m_flSpawnRadius = this->m_flSpawnRadius;
    LODWORD(v33) = LODWORD(m_flSpawnRadius) ^ _mask__NegFloat_;
    v34 = m_flSpawnRadius;
    offset.x = _RandomFloat(
                 this: v3,
                 a2: COERCE_FLOAT(LODWORD(m_flSpawnRadius) ^ _mask__NegFloat_),
                 a3: m_flSpawnRadius);
    offset.y = _RandomFloat(this: v6, a2: v33, a3: v34);
    offset.z = _RandomFloat(this: v7, a2: v33, a3: v34);
    v8 = this->GetAbsOrigin(this);
    v9 = v8->x + offset.x;
    LODWORD(origin.z) = &origin;
    m_pSporeEffect = this->m_pSporeEffect;
    origin.x = v9;
    v11 = v8->y + offset.y;
    LODWORD(origin.x) = 60;
    origin.y = v11;
    origin.z = v8->z + offset.z;
    v12 = CParticleEffect::AddParticle(
            this: m_pSporeEffect,
            particleSize: 0x3Cu,
            material: (CParticleSubTexture *)LODWORD(origin.y),
            origin: (const Vector *)LODWORD(origin.z));
    v13 = v12;
    if ( v12 == nullptr )
      break;
    LODWORD(origin.z) = 255;
    LODWORD(origin.y) = 128;
    *(_QWORD *)&v12[1].m_Pos.y = 0x40000000;
    v12[1].m_Pos.x = 0.0;
    v12[2].m_pSubTexture = nullptr;
    LOWORD(v12[2].m_pPrev) = -29471;
    BYTE2(v12[2].m_pPrev) = 64;
    v14 = Helper_RandomInt(minVal: SLODWORD(origin.y), maxVal: SLODWORD(origin.z));
    LODWORD(origin.x) = 2;
    HIBYTE(v13[2].m_pPrev) = v14;
    LOBYTE(v13[2].m_pNext) = 0;
    v15 = Helper_RandomInt(minVal: 1, maxVal: SLODWORD(origin.x));
    origin.z = 256.0;
    BYTE1(v13[2].m_pNext) = v15;
    BYTE2(v13[2].m_pNext) = 1;
    v32 = Helper_RandomFloat(minVal: 128.0, maxVal: origin.z);
    ++v4;
    *(float *)&v16 = dir.y * v32;
    *(float *)&v17 = dir.z * v32;
    *(float *)&v13[1].m_pPrev = dir.x * v32;
    v13[1].m_pNext = v16;
    v13[1].m_pSubTexture = v17;
    if ( v4 >= 4 )
    {
      v18 = this->m_flSpawnRadius * 0.5;
      LODWORD(v34) = LODWORD(v18) ^ _mask__NegFloat_;
      v33 = v18;
      offset.x = _RandomFloat(this: v3, a2: COERCE_FLOAT(LODWORD(v18) ^ _mask__NegFloat_), a3: v18);
      offset.y = _RandomFloat(this: v19, a2: v34, a3: v33);
      offset.z = _RandomFloat(this: v20, a2: v34, a3: v33);
      v21 = (float *)((int (__thiscall *)(C_SporeExplosion *, _DWORD))this->GetAbsOrigin)(a1: this, a2: LODWORD(v32));
      origin.x = *v21 + offset.x;
      origin.y = v21[1] + offset.y;
      v22 = v21[2] + offset.z;
      LODWORD(offset.z) = &origin;
      *(float **)&offset.y = g_Mat_DustPuff[1]->m_tCoordMins;
      v23 = this->m_pSporeEffect;
      origin.z = v22;
      v24 = CParticleEffect::AddParticle(this: v23, particleSize: 0x3Cu, material: g_Mat_DustPuff[1], &origin);
      v25 = v24;
      if ( v24 != nullptr )
      {
        v24[1].m_Pos.y = 1.0;
        offset.z = 360.0;
        v24[1].m_Pos.z = 0.0;
        v24[1].m_Pos.x = Helper_RandomFloat(minVal: 0.0, maxVal: offset.z);
        *(float *)&v25[2].m_pSubTexture = Helper_RandomFloat(minVal: -2.0, maxVal: 2.0);
        LODWORD(offset.x) = 64;
        LODWORD(dir.z) = 32;
        LOWORD(v25[2].m_pPrev) = -29471;
        BYTE2(v25[2].m_pPrev) = 64;
        HIBYTE(v25[2].m_pPrev) = Helper_RandomInt(minVal: SLODWORD(dir.z), maxVal: SLODWORD(offset.x));
        LOBYTE(v25[2].m_pNext) = 0;
        m_flStartSize = (int)this->m_flStartSize;
        offset.z = 128.0;
        BYTE1(v25[2].m_pNext) = m_flStartSize;
        BYTE2(v25[2].m_pNext) = (int)this->m_flEndSize;
        v32 = Helper_RandomFloat(minVal: 64.0, maxVal: offset.z);
        *(float *)&v27 = dir.y * v32;
        *(float *)&v28 = dir.z * v32;
        *(float *)&v25[1].m_pPrev = v32 * dir.x;
        v25[1].m_pNext = v27;
        v25[1].m_pSubTexture = v28;
      }
      return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024BB90
// Name: public: virtual void C_SporeExplosion::Update(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SporeExplosion::Update(C_SporeExplosion *this, float fTimeDelta)
{
  float *v3; // edi
  const Vector *v4; // eax
  float v5; // xmm0_4
  float z; // xmm0_4

  if ( LOBYTE(this->m_vecViewOffset.z) == 0 )
    return;
  v3 = (float *)(*(int (__thiscall **)(char *))(*((_DWORD *)this - 608) + 40))(a1: (char *)this - 2432);
  v4 = MainViewOrigin(nSlot: 0);
  v5 = *(float *)&this->m_iTeamNum;
  if ( fsqrt(
         (float)((float)((float)(v4->y - v3[1]) * (float)(v4->y - v3[1]))
               + (float)((float)(v4->z - v3[2]) * (float)(v4->z - v3[2])))
       + (float)((float)(v4->x - *v3) * (float)(v4->x - *v3))) < cl_sporeclipdistance.m_pParent->m_Value.m_fValue )
  {
    if ( v5 != this->m_vecViewOffset.y )
      goto LABEL_6;
  }
  else if ( v5 == this->m_vecViewOffset.y )
  {
    v5 = v5 * 0.5;
LABEL_6:
    this->m_vecVelocity.y = 1.0 / v5;
    this->m_vecViewOffset.y = v5;
  }
  while ( 1 )
  {
    z = this->m_vecVelocity.z;
    if ( fTimeDelta < z )
      break;
    this->m_vecVelocity.z = this->m_vecVelocity.y;
    fTimeDelta = fTimeDelta - z;
    C_SporeExplosion::AddParticles(this: (C_SporeExplosion *)((char *)this - 2432));
  }
  this->m_vecVelocity.z = this->m_vecVelocity.z - fTimeDelta;
}

//------------------------------------------------------------------------------
// Address: 0x1024BCE0
// Name: public: virtual void C_SporeExplosion::SimulateParticles(class CParticleSimulateIterator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SporeExplosion::SimulateParticles(C_SporeExplosion *this, CParticleSimulateIterator *pIterator)
{
  CEffectMaterial *m_pMaterial; // ecx
  Particle *m_pNext; // eax
  bool i; // zf
  float m_flTimeDelta; // xmm0_4
  float v7; // xmm0_4

  m_pMaterial = pIterator->m_pMaterial;
  m_pNext = m_pMaterial->m_Particles.m_pNext;
  for ( i = m_pNext == &m_pMaterial->m_Particles; !i; i = m_pNext == &pIterator->m_pMaterial->m_Particles )
  {
    m_flTimeDelta = pIterator->m_flTimeDelta;
    pIterator->m_pNextParticle = m_pNext->m_pNext;
    v7 = m_flTimeDelta + m_pNext[1].m_Pos.x;
    m_pNext[1].m_Pos.x = v7;
    if ( v7 > *(float *)&this->m_nNextThinkTick )
      CParticleEffectBinding::RemoveParticle(this: pIterator->m_pEffectBinding, pParticle: m_pNext);
    m_pNext = pIterator->m_pNextParticle;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024BD30
// Name: public: C_SporeTrail::C_SporeTrail(void)
// Source: json
//------------------------------------------------------------------------------
C_SporeTrail *__thiscall C_SporeTrail::C_SporeTrail(C_SporeTrail *this)
{
  C_BaseParticleEntity::C_BaseParticleEntity(this);
  this->m_flSpawnRate = 10.0;
  this->m_flParticleLifetime = 5.0;
  this->m_flStartSize = 35.0;
  this->m_flEndSize = 55.0;
  this->m_flSpawnRadius = 2.0;
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_SporeTrail_vtbl *)&C_SporeTrail::`vftable'{for `IClientUnknown'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_SporeTrail::`vftable'{for `IClientRenderable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_SporeTrail::`vftable'{for `IClientNetworkable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_SporeTrail::`vftable'{for `IClientThinkable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_SporeTrail::`vftable'{for `C_BaseEntity'};
  this->C_BaseParticleEntity::IParticleEffect::__vftable = (IParticleEffect_vtbl *)&C_SporeTrail::`vftable'{for `IParticleEffect'};
  this->m_pParticleMgr = nullptr;
  this->m_teParticleSpawn.m_TimeBetweenEvents = 0.2;
  this->m_teParticleSpawn.m_fNextEvent = 0.0;
  this->m_vecEndColor.x = 0.0;
  this->m_vecEndColor.y = 0.0;
  this->m_vecEndColor.z = 0.0;
  this->m_vecPos.x = 0.0;
  this->m_vecPos.y = 0.0;
  this->m_vecPos.z = 0.0;
  this->m_vecLastPos.x = 0.0;
  this->m_vecLastPos.y = 0.0;
  this->m_vecLastPos.z = 0.0;
  this->m_vecVelocityOffset.x = 0.0;
  this->m_vecVelocityOffset.y = 0.0;
  this->m_vecVelocityOffset.z = 0.0;
  this->m_bEmit = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1024BEC0
// Name: public: virtual void C_SporeTrail::Start(class CParticleMgr __near *,class IPrototypeArgAccess __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SporeTrail::Start(C_SporeTrail *this, CParticleMgr *pParticleMgr, IPrototypeArgAccess *pArgs)
{
  IParticleEffect *v4; // eax

  if ( this != nullptr )
    v4 = &this->IParticleEffect;
  else
    v4 = nullptr;
  if ( CParticleMgr::AddEffect(this: pParticleMgr, pEffect: &this->m_ParticleEffect, pSim: v4) != 0 )
  {
    this->m_hMaterial = g_Mat_DustPuff[1];
    this->m_pParticleMgr = pParticleMgr;
    this->m_teParticleSpawn.m_TimeBetweenEvents = 0.015625;
    this->m_teParticleSpawn.m_fNextEvent = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024BF20
// Name: private: void C_SporeTrail::AddParticles(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall C_SporeTrail::AddParticles(C_SporeTrail *this)
{
  IUniformRandomStream *v2; // ecx
  IUniformRandomStream *v3; // ecx
  Particle *v4; // eax
  Particle *v5; // esi
  IUniformRandomStream *v6; // ecx
  IUniformRandomStream *v7; // ecx
  IUniformRandomStream *v8; // ecx
  double v9; // st7
  float offset; // [esp+Ch] [ebp-Ch]
  Particle *offseta; // [esp+Ch] [ebp-Ch]
  float offset_4; // [esp+10h] [ebp-8h]
  float offset_4a; // [esp+10h] [ebp-8h]
  float offset_8; // [esp+14h] [ebp-4h]

  offset = _RandomFloat((IUniformRandomStream *)this, a2: -4.0, a3: 4.0);
  offset_4 = _RandomFloat(this: v2, a2: -4.0, a3: 4.0);
  offset_8 = _RandomFloat(this: v3, a2: -4.0, a3: 4.0);
  v4 = CParticleEffectBinding::AddParticle(
         this: &this->m_ParticleEffect,
         a2: (int)this,
         sizeInBytes: 60,
         hMaterial: this->m_hMaterial);
  v5 = v4;
  if ( v4 != nullptr )
  {
    v4->m_Pos.x = offset;
    v4->m_Pos.y = offset_4;
    v4->m_Pos.z = offset_8;
    v4[1].m_Pos.x = (float)Helper_RandomInt(minVal: 0, maxVal: 360);
    *(float *)&v5[2].m_pSubTexture = Helper_RandomFloat(minVal: -2.0, maxVal: 2.0);
    v5[1].m_Pos.z = 0.0;
    v5[1].m_Pos.y = 0.5;
    LOWORD(v5[2].m_pPrev) = -29471;
    BYTE2(v5[2].m_pPrev) = 64;
    HIBYTE(v5[2].m_pPrev) = Helper_RandomInt(minVal: 64, maxVal: 128);
    LOWORD(v5[2].m_pNext) = 256;
    BYTE2(v5[2].m_pNext) = 1;
    _RandomFloat(this: v6, a2: -8.0, a3: 8.0);
    offset_4a = _RandomFloat(this: v7, a2: -8.0, a3: 8.0);
    v9 = _RandomFloat(this: v8, a2: -8.0, a3: 8.0);
    v5[1].m_pPrev = offseta;
    *(float *)&v5[1].m_pNext = offset_4a;
    *(float *)&v5[1].m_pSubTexture = v9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024C0D0
// Name: public: virtual void C_SporeTrail::Update(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SporeTrail::Update(C_SporeTrail *this, float fTimeDelta)
{
  float x; // xmm0_4

  if ( *(_DWORD *)&this->m_iName[52] != 0 && LOBYTE(this->m_vecBaseVelocity.x) != 0 )
  {
    while ( 1 )
    {
      x = this->m_angNetworkAngles.x;
      if ( fTimeDelta < x )
        break;
      this->m_angNetworkAngles.x = this->m_vecBaseVelocity.z;
      fTimeDelta = fTimeDelta - x;
      C_SporeTrail::AddParticles(this: (C_SporeTrail *)((char *)this - 2432));
    }
    this->m_angNetworkAngles.x = this->m_angNetworkAngles.x - fTimeDelta;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024C140
// Name: public: virtual void C_SporeTrail::SimulateParticles(class CParticleSimulateIterator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SporeTrail::SimulateParticles(C_SporeTrail *this, CParticleSimulateIterator *pIterator)
{
  CEffectMaterial *m_pMaterial; // ecx
  Particle *m_pNext; // eax
  bool i; // zf
  float m_flTimeDelta; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm3_4
  float v8; // xmm0_4
  bool v9; // cf

  if ( LOBYTE(this->m_vecBaseVelocity.x) != 0 )
  {
    m_pMaterial = pIterator->m_pMaterial;
    m_pNext = m_pMaterial->m_Particles.m_pNext;
    for ( i = m_pNext == &m_pMaterial->m_Particles; !i; i = m_pNext == &pIterator->m_pMaterial->m_Particles )
    {
      m_flTimeDelta = pIterator->m_flTimeDelta;
      pIterator->m_pNextParticle = m_pNext->m_pNext;
      v6 = *(float *)&m_pNext[1].m_pNext;
      v7 = *(float *)&m_pNext[1].m_pSubTexture;
      m_pNext->m_Pos.x = (float)(*(float *)&m_pNext[1].m_pPrev * m_flTimeDelta) + m_pNext->m_Pos.x;
      m_pNext->m_Pos.y = m_pNext->m_Pos.y + (float)(v6 * m_flTimeDelta);
      m_pNext->m_Pos.z = m_pNext->m_Pos.z + (float)(v7 * m_flTimeDelta);
      v8 = pIterator->m_flTimeDelta + m_pNext[1].m_Pos.z;
      v9 = v8 < m_pNext[1].m_Pos.y;
      m_pNext[1].m_Pos.z = v8;
      if ( !v9 )
        CParticleEffectBinding::RemoveParticle(this: pIterator->m_pEffectBinding, pParticle: m_pNext);
      m_pNext = pIterator->m_pNextParticle;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024C1E0
// Name: public: virtual void C_SporeTrail::GetAimEntOrigin(class IClientEntity __near *,class Vector __near *,class QAngle __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SporeTrail::GetAimEntOrigin(
        C_SporeTrail *this,
        IClientEntity *pAttachedTo,
        Vector *pAbsOrigin,
        QAngle *pAbsAngles)
{
  C_BaseEntity *v5; // eax
  matrix3x4_t matrix; // [esp+Ch] [ebp-30h] BYREF

  v5 = pAttachedTo->GetBaseEntity(this: pAttachedTo);
  v5->GetAttachment_2(this: &v5->IClientRenderable, a2: 1, a3: pAbsOrigin, a4: pAbsAngles);
  AngleMatrix(angles: pAbsAngles, position: pAbsOrigin, &matrix);
  *(matrix3x4_t *)&this->m_mAttachmentMatrix.m[0][0] = matrix;
  this->m_mAttachmentMatrix.m[3][0] = 0.0;
  this->m_mAttachmentMatrix.m[3][1] = 0.0;
  this->m_mAttachmentMatrix.m[3][2] = 0.0;
  this->m_mAttachmentMatrix.m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x1024C2A0
// Name: public: virtual void C_DustTrail::Update(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_DustTrail::Update(C_DustTrail *this, float fTimeDelta)
{
  float x; // xmm0_4
  int (__thiscall *v4)(char *); // eax
  float *v5; // eax
  IUniformRandomStream *v6; // ecx
  float v7; // xmm0_4
  float v8; // xmm1_4
  IUniformRandomStream *v9; // ecx
  IUniformRandomStream *v10; // ecx
  CParticleEffect *v11; // esi
  float v12; // xmm1_4
  int (__thiscall *RandomInt)(IUniformRandomStream *, int, int); // edx
  int v14; // eax
  Particle *v15; // eax
  Particle *v16; // esi
  IUniformRandomStream *v17; // ecx
  IUniformRandomStream *v18; // ecx
  float (__thiscall *RandomFloat)(IUniformRandomStream *, float, float); // eax
  double v20; // st7
  Particle *v21; // xmm1_4
  CParticleSubTexture *v22; // xmm2_4
  double v23; // st7
  int m_iHealth; // xmm1_4
  int m_fFlags; // xmm2_4
  int m_nNextThinkTick; // xmm3_4
  float (__thiscall *v27)(IUniformRandomStream *, float, float); // eax
  float v28; // xmm3_4
  float v29; // xmm1_4
  float v30; // xmm0_4
  float v31; // xmm2_4
  double v32; // st7
  float v33; // xmm1_4
  float v34; // xmm2_4
  float v35; // xmm0_4
  float z; // xmm3_4
  float y; // [esp+4h] [ebp-54h]
  Vector vecForward; // [esp+14h] [ebp-44h] BYREF
  Vector offsetColor; // [esp+20h] [ebp-38h]
  Vector vecOrigin; // [esp+2Ch] [ebp-2Ch]
  Vector offset; // [esp+38h] [ebp-20h] BYREF
  float alpha; // [esp+44h] [ebp-14h]
  float fldt; // [esp+48h] [ebp-10h]
  float v44; // [esp+4Ch] [ebp-Ch]
  float v45; // [esp+50h] [ebp-8h]
  float tempDelta; // [esp+54h] [ebp-4h]

  if ( *(_DWORD *)&this->m_iName[60] != 0 && LOBYTE(this->m_vecNetworkOrigin.z) != 0 )
  {
    x = this->m_vecVelocity.x;
    if ( x == 0.0 || *(float *)(gpGlobals.m_Index + 12) < x )
    {
      tempDelta = fTimeDelta;
      C_BaseEntity::CalcAbsoluteVelocity(this: (C_DustTrail *)((char *)this - 2432));
      v4 = *(int (__thiscall **)(char *))(*((_DWORD *)this - 608) + 40);
      LODWORD(v44) = LODWORD(fTimeDelta) ^ _mask__NegFloat_;
      v5 = (float *)v4(a1: (char *)this - 2432);
      vecOrigin.x = (float)(COERCE_FLOAT(LODWORD(fTimeDelta) ^ _mask__NegFloat_) * *((float *)this - 572)) + *v5;
      vecOrigin.y = (float)(*((float *)this - 571) * COERCE_FLOAT(LODWORD(fTimeDelta) ^ _mask__NegFloat_)) + v5[1];
      vecOrigin.z = (float)(*((float *)this - 570) * COERCE_FLOAT(LODWORD(fTimeDelta) ^ _mask__NegFloat_)) + v5[2];
      C_BaseEntity::GetVectors(
        this: (C_DustTrail *)((char *)this - 2432),
        pForward: &vecForward,
        pRight: nullptr,
        pUp: nullptr);
      while ( 1 )
      {
        v7 = *(float *)&this->m_iName[52];
        v8 = tempDelta;
        if ( tempDelta < v7 )
          break;
        *(float *)&this->m_iName[52] = *(float *)&this->m_iName[48];
        tempDelta = v8 - v7;
        fldt = fTimeDelta - (float)(v8 - v7);
        y = this->m_angNetworkAngles.y;
        v44 = -y;
        v45 = y;
        offset.x = _RandomFloat(this: v6, a2: -y, a3: y);
        offset.y = _RandomFloat(this: v9, a2: v44, a3: v45);
        offset.z = _RandomFloat(this: v10, a2: v44, a3: v45);
        offset.x = offset.x + vecOrigin.x;
        offset.y = offset.y + vecOrigin.y;
        offset.z = offset.z + vecOrigin.z;
        C_BaseEntity::CalcAbsoluteVelocity(this: (C_DustTrail *)((char *)this - 2432));
        v11 = *(CParticleEffect **)&this->m_iName[60];
        offset.x = (float)(*((float *)this - 572) * fldt) + offset.x;
        offset.y = (float)(*((float *)this - 571) * fldt) + offset.y;
        v12 = *((float *)this - 570);
        LODWORD(vecForward.z) = &offset;
        offset.z = (float)(v12 * fldt) + offset.z;
        RandomInt = random->RandomInt;
        vecForward.y = 0.0;
        vecForward.x = 0.0;
        v14 = ((int (__thiscall *)(IUniformRandomStream *))RandomInt)(a1: random);
        v15 = CParticleEffect::AddParticle(
                this: v11,
                particleSize: 0x3Cu,
                material: *((CParticleSubTexture **)&this->m_flFriction + v14),
                origin: (const Vector *)LODWORD(vecForward.x));
        v16 = v15;
        if ( v15 != nullptr )
        {
          v15[1].m_Pos.z = 0.0;
          v15[1].m_Pos.y = this->m_vecViewOffset.y;
          *(float *)&v15[1].m_pPrev = _RandomFloat(this: v6, a2: -1.0, a3: 1.0);
          *(float *)&v16[1].m_pNext = _RandomFloat(this: v17, a2: -1.0, a3: 1.0);
          *(float *)&v16[1].m_pSubTexture = _RandomFloat(this: v18, a2: -1.0, a3: 1.0);
          RandomFloat = random->RandomFloat;
          vecOrigin.x = this->m_vecVelocity.z;
          v20 = ((double (__thiscall *)(IUniformRandomStream *, _DWORD))RandomFloat)(
                  a1: random,
                  a2: LODWORD(this->m_vecVelocity.y));
          *(float *)&v16[1].m_pPrev = *(float *)&v16[1].m_pPrev * v20;
          *(float *)&v16[1].m_pNext = *(float *)&v16[1].m_pNext * v20;
          *(float *)&v16[1].m_pSubTexture = v20 * *(float *)&v16[1].m_pSubTexture;
          C_BaseEntity::CalcAbsoluteVelocity(this: (C_DustTrail *)((char *)this - 2432));
          *(float *)&v21 = *((float *)this - 571) + *(float *)&v16[1].m_pNext;
          *(float *)&v22 = *((float *)this - 570) + *(float *)&v16[1].m_pSubTexture;
          *(float *)&v16[1].m_pPrev = *(float *)&v16[1].m_pPrev + *((float *)this - 572);
          v16[1].m_pNext = v21;
          v16[1].m_pSubTexture = v22;
          v23 = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))random->RandomFloat)(
                  a1: random,
                  a2: LODWORD(this->m_vecBaseVelocity.x),
                  a3: LODWORD(this->m_vecBaseVelocity.y));
          *(float *)&v16[1].m_pPrev = vecForward.x * v23 + *(float *)&v16[1].m_pPrev;
          *(float *)&v16[1].m_pNext = vecForward.y * v23 + *(float *)&v16[1].m_pNext;
          *(float *)&v16[1].m_pSubTexture = v23 * vecForward.z + *(float *)&v16[1].m_pSubTexture;
          m_iHealth = this->m_iHealth;
          m_fFlags = this->m_fFlags;
          m_nNextThinkTick = m_iHealth;
          if ( *(float *)&this->m_nNextThinkTick > *(float *)&m_iHealth )
            m_nNextThinkTick = this->m_nNextThinkTick;
          if ( *(float *)&this->m_fFlags > *(float *)&m_nNextThinkTick )
            m_nNextThinkTick = this->m_fFlags;
          v27 = random->RandomFloat;
          v28 = 1.0 / *(float *)&m_nNextThinkTick;
          offsetColor.x = v28 * *(float *)&this->m_nNextThinkTick;
          offsetColor.y = *(float *)&m_iHealth * v28;
          offsetColor.z = *(float *)&m_fFlags * v28;
          alpha = ((double (__thiscall *)(IUniformRandomStream *, int, int))v27)(
                    a1: random,
                    a2: -1102263091,
                    a3: 1045220557);
          v29 = (float)(offsetColor.y * alpha) + *(float *)&this->m_iHealth;
          v30 = *(float *)&this->m_nNextThinkTick + (float)(offsetColor.x * alpha);
          v31 = *(float *)&this->m_fFlags + (float)(offsetColor.z * alpha);
          if ( v30 >= 0.0 )
          {
            if ( v30 > 1.0 )
              v30 = 1.0;
          }
          else
          {
            v30 = 0.0;
          }
          if ( v29 >= 0.0 )
          {
            if ( v29 > 1.0 )
              v29 = 1.0;
          }
          else
          {
            v29 = 0.0;
          }
          if ( v31 >= 0.0 )
          {
            if ( v31 > 1.0 )
              v31 = 1.0;
          }
          else
          {
            v31 = 0.0;
          }
          LOBYTE(v16[2].m_pPrev) = (int)(float)(v30 * 255.0);
          BYTE1(v16[2].m_pPrev) = (int)(float)(v29 * 255.0);
          BYTE2(v16[2].m_pPrev) = (int)(float)(v31 * 255.0);
          BYTE1(v16[2].m_pNext) = (int)this->m_vecBaseVelocity.z;
          BYTE2(v16[2].m_pNext) = (int)this->m_angNetworkAngles.x;
          v32 = ((double (__cdecl *)(_DWORD, _DWORD))random->RandomFloat)(
                  a1: this->m_vecViewOffset.x * 0.75,
                  a2: this->m_vecViewOffset.x * 1.25);
          alpha = v32;
          if ( v32 >= 0.0 )
          {
            v33 = alpha;
            if ( alpha > 1.0 )
              v33 = 1.0;
          }
          else
          {
            v33 = 0.0;
          }
          v34 = this->m_vecVelocity.x;
          v35 = v33;
          if ( v34 != 0.0 )
          {
            z = this->m_vecViewOffset.z;
            if ( v34 > z )
              v35 = fsqrt((float)(v34 - *(float *)(gpGlobals.m_Index + 12)) / (float)(v34 - z)) * v33;
          }
          *(_WORD *)((char *)&v16[2].m_pPrev + 3) = (unsigned __int8)(int)(float)(v35 * 255.0);
          v16[1].m_Pos.x = (float)random->RandomInt(this: random, a2: 0, a3: 360);
          *(float *)&v16[2].m_pSubTexture = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                              a1: random,
                                              a2: -1082130432,
                                              a3: 1065353216);
        }
      }
      *(float *)&this->m_iName[52] = *(float *)&this->m_iName[52] - tempDelta;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024C8B0
// Name: public: C_SmokeTrail::C_SmokeTrail(void)
// Source: json
//------------------------------------------------------------------------------
C_SmokeTrail *__thiscall C_SmokeTrail::C_SmokeTrail(C_SmokeTrail *this)
{
  CSimpleEmitter *m_pObj; // ecx

  C_BaseParticleEntity::C_BaseParticleEntity(this);
  this->IPrototypeAppEffect::__vftable = (IPrototypeAppEffect_vtbl *)&IPrototypeAppEffect::`vftable';
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_SmokeTrail_vtbl *)&C_SmokeTrail::`vftable'{for `IClientUnknown'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_SmokeTrail::`vftable'{for `IClientRenderable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_SmokeTrail::`vftable'{for `IClientNetworkable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_SmokeTrail::`vftable'{for `IClientThinkable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_SmokeTrail::`vftable'{for `C_BaseEntity'};
  this->C_BaseParticleEntity::IParticleEffect::__vftable = (IParticleEffect_vtbl *)&C_SmokeTrail::`vftable'{for `IParticleEffect'};
  this->IPrototypeAppEffect::__vftable = (IPrototypeAppEffect_vtbl *)&C_SmokeTrail::`vftable';
  this->m_pSmokeEmitter.m_pObj = nullptr;
  this->m_SpawnRate = 10.0;
  this->m_MaterialHandle[0] = nullptr;
  this->m_MaterialHandle[1] = nullptr;
  this->m_ParticleSpawn.m_TimeBetweenEvents = 0.1;
  this->m_ParticleSpawn.m_fNextEvent = 0.0;
  this->m_StartColor.x = 0.5;
  this->m_StartColor.y = 0.5;
  this->m_StartColor.z = 0.5;
  this->m_EndColor.x = 0.0;
  this->m_EndColor.y = 0.0;
  this->m_EndColor.z = 0.0;
  this->m_MaxSpeed = 4.0;
  this->m_ParticleLifetime = 5.0;
  this->m_StartSize = 35.0;
  this->m_StopEmitTime = 0.0;
  this->m_MinSpeed = 2.0;
  *(_QWORD *)&this->m_MinDirectedSpeed = 0;
  this->m_EndSize = 55.0;
  this->m_SpawnRadius = 2.0;
  this->m_VelocityOffset.x = 0.0;
  this->m_VelocityOffset.y = 0.0;
  this->m_VelocityOffset.z = 0.0;
  this->m_Opacity = 0.5;
  this->m_bEmit = true;
  this->m_nAttachment = -1;
  m_pObj = this->m_pSmokeEmitter.m_pObj;
  if ( m_pObj != nullptr )
  {
    CParticleEffect::Release(this: m_pObj);
    this->m_pSmokeEmitter.m_pObj = nullptr;
  }
  this->m_pParticleMgr = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1024CA60
// Name: public: virtual C_SmokeTrail::~C_SmokeTrail(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SmokeTrail::~C_SmokeTrail(C_SmokeTrail *this)
{
  CSimpleEmitter *m_pObj; // eax
  KeyValues *v3; // eax
  KeyValues *v4; // edi
  CParticleMgr *m_pParticleMgr; // ecx
  CSimpleEmitter *v6; // ecx

  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_SmokeTrail_vtbl *)&C_SmokeTrail::`vftable'{for `IClientUnknown'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_SmokeTrail::`vftable'{for `IClientRenderable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_SmokeTrail::`vftable'{for `IClientNetworkable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_SmokeTrail::`vftable'{for `IClientThinkable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_SmokeTrail::`vftable'{for `C_BaseEntity'};
  this->C_BaseParticleEntity::IParticleEffect::__vftable = (IParticleEffect_vtbl *)&C_SmokeTrail::`vftable'{for `IParticleEffect'};
  this->IPrototypeAppEffect::__vftable = (IPrototypeAppEffect_vtbl *)&C_SmokeTrail::`vftable';
  if ( ToolsEnabled() && clienttools->IsInRecordingMode(this: clienttools) )
  {
    m_pObj = this->m_pSmokeEmitter.m_pObj;
    if ( m_pObj != nullptr && m_pObj->m_nToolParticleEffectId != -1 )
    {
      v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v3 != nullptr )
        v4 = KeyValues::KeyValues(this: v3, setName: "OldParticleSystem_ActivateEmitter");
      else
        v4 = nullptr;
      KeyValues::SetInt(this: v4, keyName: "id", value: this->m_pSmokeEmitter.m_pObj->m_nToolParticleEffectId);
      KeyValues::SetInt(this: v4, keyName: "emitter", value: 0);
      KeyValues::SetInt(this: v4, keyName: "active", value: 0);
      KeyValues::SetFloat(this: v4, keyName: "time", value: *(float *)(gpGlobals.m_Index + 12));
      ToolFramework_PostToolMessage(hEntity: 0, msg: v4);
      KeyValues::deleteThis(this: v4);
    }
  }
  m_pParticleMgr = this->m_pParticleMgr;
  if ( m_pParticleMgr != nullptr )
    CParticleMgr::RemoveEffect(this: m_pParticleMgr, pEffect: &this->m_ParticleEffect);
  v6 = this->m_pSmokeEmitter.m_pObj;
  if ( v6 != nullptr )
    CParticleEffect::Release(this: v6);
  this->IPrototypeAppEffect::__vftable = (IPrototypeAppEffect_vtbl *)&IPrototypeAppEffect::`vftable';
  C_BaseParticleEntity::~C_BaseParticleEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x1024CBA0
// Name: public: virtual void C_SmokeTrail::Start(class CParticleMgr __near *,class IPrototypeArgAccess __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SmokeTrail::Start(C_SmokeTrail *this, CParticleMgr *pParticleMgr, IPrototypeArgAccess *pArgs)
{
  IParticleEffect *v4; // eax
  CSimpleEmitter *v5; // eax
  CParticleEffect *v6; // edi
  CParticleEffect *m_cellbits; // ecx
  CParticleEffect *v8; // edi
  const Vector *v9; // eax
  float v10; // xmm0_4

  if ( this == (C_SmokeTrail *)2664 )
    v4 = nullptr;
  else
    v4 = (IParticleEffect *)((char *)this - 232);
  if ( CParticleMgr::AddEffect(this: pParticleMgr, pEffect: (CParticleEffectBinding *)((char *)this - 228), pSim: v4) != 0 )
  {
    this->m_clrRender = (CNetworkColor32Base<color32_s,C_BaseEntity::NetworkVar_m_clrRender>)pParticleMgr;
    v5 = (CSimpleEmitter *)MemAlloc_Alloc(nSize: 0x108u);
    v6 = v5;
    if ( v5 != nullptr )
    {
      CSimpleEmitter::CSimpleEmitter(this: v5, pDebugName: "smokeTrail");
      v6->__vftable = (CParticleEffect_vtbl *)&CSmokeParticle::`vftable';
    }
    else
    {
      v6 = nullptr;
    }
    if ( v6 != (CParticleEffect *)this->m_cellbits )
    {
      if ( v6 != nullptr )
        CParticleEffect::AddRef(this: v6);
      m_cellbits = (CParticleEffect *)this->m_cellbits;
      if ( m_cellbits != nullptr )
        CParticleEffect::Release(this: m_cellbits);
      this->m_cellbits = (int)v6;
    }
    v8 = (CParticleEffect *)this->m_cellbits;
    if ( v8 != nullptr )
    {
      v9 = (const Vector *)(*(int (__thiscall **)(char *))(*((_DWORD *)this - 666) + 40))(a1: (char *)this - 2664);
      CParticleEffect::SetSortOrigin(this: v8, vSortOrigin: v9);
      CSimpleEmitter::SetNearClip(this: (CSimpleEmitter *)this->m_cellbits, nearClipMin: 64.0, nearClipMax: 128.0);
      v10 = 1.0 / *(float *)&this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientRenderable::__vftable;
      *(_QWORD *)((char *)&this->m_pfnTouch + 12) = *(_QWORD *)g_Mat_DustPuff;
      *(float *)&this->m_EntClientFlags = v10;
      this->model = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024CCA0
// Name: public: virtual void C_SmokeTrail::CleanupToolRecordingState(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SmokeTrail::CleanupToolRecordingState(C_SmokeTrail *this, int msg)
{
  CSimpleEmitter *m_pObj; // edi
  float m_StopEmitTime; // xmm0_4
  int value; // ebx
  KeyValues *v6; // eax
  KeyValues *v7; // edi
  KeyValues *Key; // edi
  KeyValues *v9; // ebx
  KeyValues *v10; // edi
  KeyValues *v11; // ebx
  void *v12; // eax
  float *v13; // eax
  int v14; // eax
  int v15; // eax
  KeyValues *v16; // ebx
  KeyValues *v17; // ebx
  void *v18; // eax
  KeyValues *v19; // ebx
  KeyValues *v20; // ebx
  KeyValues *v21; // eax
  int v22; // xmm1_4
  KeyValues *v23; // ebx
  int v24; // xmm1_4
  double v25; // st7
  KeyValues *v26; // eax
  float v27; // xmm0_4
  KeyValues *v28; // ebx
  int v29; // eax
  int v30; // eax
  KeyValues *v31; // edi
  KeyValues *v32; // esi
  KeyValues *v33; // edi
  KeyValues *Copy; // esi
  KeyValues *v35; // esi
  KeyValues *v36; // eax
  KeyValues *v37; // edi
  KeyValues *pEmitterParent2; // [esp+10h] [ebp-2Ch]
  KeyValues *pEmitter; // [esp+14h] [ebp-28h]
  int nMaxAlpha; // [esp+18h] [ebp-24h] BYREF
  int v41; // [esp+1Ch] [ebp-20h] BYREF
  int v42; // [esp+20h] [ebp-1Ch] BYREF
  int v43; // [esp+24h] [ebp-18h] BYREF
  int minVal; // [esp+28h] [ebp-14h] BYREF
  int maxVal; // [esp+2Ch] [ebp-10h] BYREF
  int val; // [esp+30h] [ebp-Ch] BYREF
  KeyValues *msga; // [esp+34h] [ebp-8h]
  Color c; // [esp+38h] [ebp-4h] BYREF

  if ( ToolsEnabled() )
  {
    CScoreboardScaleform::SetParent((vgui::TreeView *)this, itemIndex: msg);
    if ( clienttools->IsInRecordingMode(this: clienttools) )
    {
      m_pObj = this->m_pSmokeEmitter.m_pObj;
      if ( m_pObj != nullptr )
      {
        c = (Color)C_BaseEntity::GetMoveParent(this);
        if ( c != 0 )
        {
          HIBYTE(msg) = this->m_bEmit
                     && ((m_StopEmitTime = this->m_StopEmitTime) == 0.0
                      || m_StopEmitTime > *(float *)(gpGlobals.m_Index + 12));
          if ( m_pObj->m_nToolParticleEffectId == -1 )
          {
            value = CParticleEffect::AllocateToolParticleEffectId(this: m_pObj);
            v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v6 != nullptr )
            {
              v7 = KeyValues::KeyValues(this: v6, setName: "OldParticleSystem_Create");
              msga = v7;
            }
            else
            {
              msga = nullptr;
              v7 = nullptr;
            }
            KeyValues::SetString(this: v7, keyName: "name", value: "C_SmokeTrail");
            KeyValues::SetInt(this: v7, keyName: "id", value);
            KeyValues::SetFloat(this: v7, keyName: "time", value: *(float *)(gpGlobals.m_Index + 12));
            Key = KeyValues::FindKey(this: v7, keyName: "DmeRandomEmitter", bCreate: true);
            KeyValues::SetInt(this: Key, keyName: "count", value: (int)this->m_SpawnRate);
            KeyValues::SetFloat(this: Key, keyName: "duration", value: -1.0);
            KeyValues::SetInt(this: Key, keyName: "active", value: HIBYTE(msg));
            v9 = KeyValues::FindKey(this: Key, keyName: "emitter1", bCreate: true);
            KeyValues::SetFloat(this: v9, keyName: "randomamount", value: 0.5);
            pEmitterParent2 = KeyValues::FindKey(this: Key, keyName: "emitter2", bCreate: true);
            KeyValues::SetFloat(this: pEmitterParent2, keyName: "randomamount", value: 0.5);
            pEmitter = KeyValues::FindKey(this: v9, keyName: "DmeSpriteEmitter", bCreate: true);
            KeyValues::SetString(this: pEmitter, keyName: "material", value: "particle/particle_smokegrenade");
            v10 = KeyValues::FindKey(this: pEmitter, keyName: "initializers", bCreate: true);
            v11 = KeyValues::FindKey(this: v10, keyName: "DmePositionPointToEntityInitializer", bCreate: true);
            v12 = (void *)(*(int (__thiscall **)(int))(*(_DWORD *)(*(_DWORD *)&c + 8) + 40))(a1: *(_DWORD *)&c + 8);
            KeyValues::SetPtr(this: v11, keyName: "entindex", value: v12);
            KeyValues::SetInt(this: v11, keyName: "attachmentIndex", value: this->m_nAttachment);
            KeyValues::SetFloat(this: v11, keyName: "randomDist", value: this->m_SpawnRadius);
            v13 = (float *)(*(int (__thiscall **)(Color))(**(_DWORD **)&c + 40))(a1: c);
            KeyValues::SetFloat(this: v11, keyName: "startx", value: *v13);
            v14 = (*(int (__thiscall **)(Color))(**(_DWORD **)&c + 40))(a1: c);
            KeyValues::SetFloat(this: v11, keyName: "starty", value: *(float *)(v14 + 4));
            v15 = (*(int (__thiscall **)(Color))(**(_DWORD **)&c + 40))(a1: c);
            KeyValues::SetFloat(this: v11, keyName: "startz", value: *(float *)(v15 + 8));
            v16 = KeyValues::FindKey(this: v10, keyName: "DmeRandomLifetimeInitializer", bCreate: true);
            KeyValues::SetFloat(this: v16, keyName: "minLifetime", value: this->m_ParticleLifetime);
            KeyValues::SetFloat(this: v16, keyName: "maxLifetime", value: this->m_ParticleLifetime);
            v17 = KeyValues::FindKey(this: v10, keyName: "DmeAttachmentVelocityInitializer", bCreate: true);
            v18 = (void *)this->entindex(this: &this->IClientNetworkable);
            KeyValues::SetPtr(this: v17, keyName: "entindex", value: v18);
            KeyValues::SetFloat(this: v17, keyName: "minAttachmentSpeed", value: this->m_MinDirectedSpeed);
            KeyValues::SetFloat(this: v17, keyName: "maxAttachmentSpeed", value: this->m_MaxDirectedSpeed);
            KeyValues::SetFloat(this: v17, keyName: "minRandomSpeed", value: this->m_MinSpeed);
            KeyValues::SetFloat(this: v17, keyName: "maxRandomSpeed", value: this->m_MaxSpeed);
            v19 = KeyValues::FindKey(this: v10, keyName: "DmeRandomRollInitializer", bCreate: true);
            KeyValues::SetFloat(this: v19, keyName: "minRoll", value: 0.0);
            KeyValues::SetFloat(this: v19, keyName: "maxRoll", value: 360.0);
            v20 = KeyValues::FindKey(this: v10, keyName: "DmeRandomRollSpeedInitializer", bCreate: true);
            KeyValues::SetFloat(this: v20, keyName: "minRollSpeed", value: -1.0);
            KeyValues::SetFloat(this: v20, keyName: "maxRollSpeed", value: 1.0);
            v21 = KeyValues::FindKey(this: v10, keyName: "DmeRandomValueColorInitializer", bCreate: true);
            *(float *)&nMaxAlpha = this->m_StartColor.z * 255.0;
            *(float *)&v22 = this->m_StartColor.y * 255.0;
            v41 = 0;
            minVal = 0;
            c = 0;
            v43 = v22;
            v23 = v21;
            *(float *)&v24 = this->m_StartColor.x * 255.0;
            v42 = 255;
            maxVal = 255;
            msg = 255;
            val = v24;
            val = (int)clamp<float,int,int>((float *)&val, minVal: (const int *)&c, maxVal: &msg);
            c._color[0] = val;
            v43 = (int)clamp<float,int,int>(val: (float *)&v43, &minVal, &maxVal);
            c._color[1] = v43;
            v25 = clamp<float,int,int>(val: (float *)&nMaxAlpha, minVal: &v41, maxVal: &v42);
            c._color[3] = -1;
            nMaxAlpha = (int)v25;
            c._color[2] = (int)v25;
            KeyValues::SetColor(this: v23, keyName: "startColor", value: c);
            KeyValues::SetFloat(this: v23, keyName: "minStartValueDelta", value: -0.2);
            KeyValues::SetFloat(this: v23, keyName: "maxStartValueDelta", value: 0.2);
            msg = -16777216;
            KeyValues::SetColor(this: v23, keyName: "endColor", value: (Color)-16777216);
            v26 = KeyValues::FindKey(this: v10, keyName: "DmeRandomAlphaInitializer", bCreate: true);
            v27 = this->m_Opacity * 255.0;
            v28 = v26;
            msg = (int)(float)(v27 * 0.75);
            nMaxAlpha = (int)(float)(v27 * 1.25);
            KeyValues::SetInt(this: v26, keyName: "minStartAlpha", value: 0);
            KeyValues::SetInt(this: v28, keyName: "maxStartAlpha", value: 0);
            v29 = msg;
            if ( msg >= 0 )
            {
              if ( msg > 255 )
                v29 = 255;
            }
            else
            {
              v29 = 0;
            }
            KeyValues::SetInt(this: v28, keyName: "minEndAlpha", value: v29);
            v30 = nMaxAlpha;
            if ( nMaxAlpha >= 0 )
            {
              if ( nMaxAlpha > 255 )
                v30 = 255;
            }
            else
            {
              v30 = 0;
            }
            KeyValues::SetInt(this: v28, keyName: "maxEndAlpha", value: v30);
            v31 = KeyValues::FindKey(this: v10, keyName: "DmeRandomSizeInitializer", bCreate: true);
            KeyValues::SetFloat(this: v31, keyName: "minStartSize", value: this->m_StartSize);
            KeyValues::SetFloat(this: v31, keyName: "maxStartSize", value: this->m_StartSize);
            KeyValues::SetFloat(this: v31, keyName: "minEndSize", value: this->m_EndSize);
            KeyValues::SetFloat(this: v31, keyName: "maxEndSize", value: this->m_EndSize);
            v32 = KeyValues::FindKey(this: pEmitter, keyName: "updaters", bCreate: true);
            KeyValues::FindKey(this: v32, keyName: "DmePositionVelocityUpdater", bCreate: true);
            KeyValues::FindKey(this: v32, keyName: "DmeRollUpdater", bCreate: true);
            v33 = KeyValues::FindKey(this: v32, keyName: "DmeRollSpeedAttenuateUpdater", bCreate: true);
            KeyValues::SetFloat(this: v33, keyName: "attenuation", value: 0.73333335);
            KeyValues::SetFloat(this: v33, keyName: "attenuationTme", value: 0.033333335);
            KeyValues::SetFloat(this: v33, keyName: "minRollSpeed", value: 0.5);
            KeyValues::FindKey(this: v32, keyName: "DmeAlphaSineUpdater", bCreate: true);
            KeyValues::FindKey(this: v32, keyName: "DmeColorUpdater", bCreate: true);
            KeyValues::FindKey(this: v32, keyName: "DmeSizeUpdater", bCreate: true);
            Copy = KeyValues::MakeCopy(this: pEmitter);
            KeyValues::SetString(this: Copy, keyName: "material", value: "particle/particle_noisesphere");
            KeyValues::AddSubKey(this: pEmitterParent2, pSubkey: Copy);
            v35 = msga;
            ToolFramework_PostToolMessage(hEntity: 0, msg: msga);
            KeyValues::deleteThis(this: v35);
          }
          else
          {
            v36 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v36 != nullptr )
              v37 = KeyValues::KeyValues(this: v36, setName: "OldParticleSystem_ActivateEmitter");
            else
              v37 = nullptr;
            KeyValues::SetInt(this: v37, keyName: "id", value: this->m_pSmokeEmitter.m_pObj->m_nToolParticleEffectId);
            KeyValues::SetInt(this: v37, keyName: "emitter", value: 0);
            KeyValues::SetInt(this: v37, keyName: "active", value: HIBYTE(msg));
            KeyValues::SetFloat(this: v37, keyName: "time", value: *(float *)(gpGlobals.m_Index + 12));
            ToolFramework_PostToolMessage(hEntity: 0, msg: v37);
            KeyValues::deleteThis(this: v37);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024D490
// Name: public: C_RocketTrail::C_RocketTrail(void)
// Source: json
//------------------------------------------------------------------------------
C_RocketTrail *__thiscall C_RocketTrail::C_RocketTrail(C_RocketTrail *this)
{
  CSimpleEmitter *m_pObj; // ecx

  C_BaseParticleEntity::C_BaseParticleEntity(this);
  this->IPrototypeAppEffect::__vftable = (IPrototypeAppEffect_vtbl *)&IPrototypeAppEffect::`vftable';
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_RocketTrail_vtbl *)&C_RocketTrail::`vftable'{for `IClientUnknown'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_RocketTrail::`vftable'{for `IClientRenderable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_RocketTrail::`vftable'{for `IClientNetworkable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_RocketTrail::`vftable'{for `IClientThinkable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_RocketTrail::`vftable'{for `C_BaseEntity'};
  this->C_BaseParticleEntity::IParticleEffect::__vftable = (IParticleEffect_vtbl *)&C_RocketTrail::`vftable'{for `IParticleEffect'};
  this->IPrototypeAppEffect::__vftable = (IPrototypeAppEffect_vtbl *)&C_RocketTrail::`vftable';
  this->m_pRocketEmitter.m_pObj = nullptr;
  this->m_SpawnRate = 10.0;
  this->m_MaterialHandle[0] = nullptr;
  this->m_MaterialHandle[1] = nullptr;
  this->m_ParticleSpawn.m_TimeBetweenEvents = 0.1;
  this->m_ParticleSpawn.m_fNextEvent = 0.0;
  this->m_StartColor.x = 0.5;
  this->m_StartColor.y = 0.5;
  this->m_StartColor.z = 0.5;
  this->m_EndColor.x = 0.0;
  this->m_EndColor.y = 0.0;
  this->m_EndColor.z = 0.0;
  this->m_MaxSpeed = 4.0;
  this->m_ParticleLifetime = 5.0;
  this->m_StartSize = 35.0;
  this->m_StopEmitTime = 0.0;
  this->m_MinSpeed = 2.0;
  this->m_EndSize = 55.0;
  this->m_SpawnRadius = 2.0;
  this->m_VelocityOffset.x = 0.0;
  this->m_VelocityOffset.y = 0.0;
  this->m_VelocityOffset.z = 0.0;
  this->m_Opacity = 0.5;
  *(_WORD *)&this->m_bEmit = 1;
  this->m_nAttachment = -1;
  m_pObj = this->m_pRocketEmitter.m_pObj;
  if ( m_pObj != nullptr )
  {
    CParticleEffect::Release(this: m_pObj);
    this->m_pRocketEmitter.m_pObj = nullptr;
  }
  this->m_pParticleMgr = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1024D630
// Name: public: virtual C_RocketTrail::~C_RocketTrail(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_RocketTrail::~C_RocketTrail(C_RocketTrail *this)
{
  CParticleMgr *m_pParticleMgr; // ecx
  CSimpleEmitter *m_pObj; // ecx

  m_pParticleMgr = this->m_pParticleMgr;
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_RocketTrail_vtbl *)&C_RocketTrail::`vftable'{for `IClientUnknown'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_RocketTrail::`vftable'{for `IClientRenderable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_RocketTrail::`vftable'{for `IClientNetworkable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_RocketTrail::`vftable'{for `IClientThinkable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_RocketTrail::`vftable'{for `C_BaseEntity'};
  this->C_BaseParticleEntity::IParticleEffect::__vftable = (IParticleEffect_vtbl *)&C_RocketTrail::`vftable'{for `IParticleEffect'};
  this->IPrototypeAppEffect::__vftable = (IPrototypeAppEffect_vtbl *)&C_RocketTrail::`vftable';
  if ( m_pParticleMgr != nullptr )
    CParticleMgr::RemoveEffect(this: m_pParticleMgr, pEffect: &this->m_ParticleEffect);
  m_pObj = this->m_pRocketEmitter.m_pObj;
  if ( m_pObj != nullptr )
    CParticleEffect::Release(this: m_pObj);
  this->IPrototypeAppEffect::__vftable = (IPrototypeAppEffect_vtbl *)&IPrototypeAppEffect::`vftable';
  C_BaseParticleEntity::~C_BaseParticleEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x1024D6A0
// Name: public: virtual void C_RocketTrail::Start(class CParticleMgr __near *,class IPrototypeArgAccess __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_RocketTrail::Start(C_RocketTrail *this, CParticleMgr *pParticleMgr, IPrototypeArgAccess *pArgs)
{
  IParticleEffect *v4; // eax
  CSimpleEmitter *v5; // eax
  CParticleEffect *v6; // edi
  CParticleEffect *m_cellX; // ecx
  CParticleEffect *v8; // ebx
  const Vector *v9; // eax
  float v10; // xmm0_4
  float *v11; // eax

  if ( this == (C_RocketTrail *)2664 )
    v4 = nullptr;
  else
    v4 = (IParticleEffect *)((char *)this - 232);
  if ( CParticleMgr::AddEffect(this: pParticleMgr, pEffect: (CParticleEffectBinding *)((char *)this - 228), pSim: v4) != 0 )
  {
    this->m_cellwidth = (int)pParticleMgr;
    v5 = (CSimpleEmitter *)MemAlloc_Alloc(nSize: 0x108u);
    v6 = v5;
    if ( v5 != nullptr )
    {
      CSimpleEmitter::CSimpleEmitter(this: v5, pDebugName: "smokeTrail");
      v6->__vftable = (CParticleEffect_vtbl *)&CRocketTrailParticle::`vftable';
    }
    else
    {
      v6 = nullptr;
    }
    if ( v6 != (CParticleEffect *)this->m_cellX )
    {
      if ( v6 != nullptr )
        CParticleEffect::AddRef(this: v6);
      m_cellX = (CParticleEffect *)this->m_cellX;
      if ( m_cellX != nullptr )
        CParticleEffect::Release(this: m_cellX);
      this->m_cellX = (int)v6;
    }
    v8 = (CParticleEffect *)this->m_cellX;
    if ( v8 != nullptr )
    {
      v9 = (const Vector *)(*(int (__thiscall **)(char *))(*((_DWORD *)this - 666) + 40))(a1: (char *)this - 2664);
      CParticleEffect::SetSortOrigin(this: v8, vSortOrigin: v9);
      CSimpleEmitter::SetNearClip(this: (CSimpleEmitter *)this->m_cellX, nearClipMin: 64.0, nearClipMax: 128.0);
      v10 = 1.0 / *(float *)&this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientRenderable::__vftable;
      *(_QWORD *)&this->m_EntClientFlags = *(_QWORD *)g_Mat_DustPuff;
      *(float *)&this->m_clrRender = v10;
      this->m_cellbits = 0;
      v11 = (float *)(*(int (__thiscall **)(char *))(*((_DWORD *)this - 666) + 40))(a1: (char *)this - 2664);
      *((float *)&this->m_pfnTouch + 1) = *v11;
      *((float *)&this->m_pfnTouch + 2) = v11[1];
      *((float *)&this->m_pfnTouch + 3) = v11[2];
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024D7C0
// Name: public: virtual void C_RocketTrail::Update(float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge C_RocketTrail::Update(C_RocketTrail *this@<ecx>, int a2@<ebx>, int a3@<esi>, float fTimeDelta)
{
  CSimpleEmitter *m_pObj; // esi
  const Vector *v6; // eax
  const QAngle *v7; // eax
  float v8; // xmm0_4
  int (__thiscall *v9)(char *); // eax
  float v10; // xmm0_4
  float *v11; // eax
  float v12; // xmm1_4
  float v13; // xmm2_4
  CSimpleEmitter *v14; // esi
  int v15; // eax
  const char *v16; // eax
  CParticleSubTexture *PMaterial; // eax
  Particle *v18; // eax
  Particle *v19; // esi
  double v20; // st7
  char v21; // al
  int v22; // eax
  float v23; // xmm0_4
  int v24; // eax
  float *v25; // eax
  int v26; // eax
  CParticleSubTexture *v27; // xmm0_4
  CParticleEffect *v28; // esi
  float v29; // xmm3_4
  float v30; // xmm1_4
  int v31; // eax
  Particle *v32; // eax
  Particle *v33; // esi
  IUniformRandomStream *v34; // ecx
  IUniformRandomStream *v35; // ecx
  IUniformRandomStream *v36; // ecx
  double v37; // st7
  double v38; // st7
  float v39; // xmm0_4
  float v40; // xmm1_4
  float v41; // xmm2_4
  double v42; // st7
  float v43; // xmm0_4
  CEmberEffect *v44; // esi
  const Vector *v45; // eax
  CParticleEffect *v46; // esi
  int v47; // eax
  const char *v48; // eax
  IUniformRandomStream *v49; // ecx
  IUniformRandomStream *v50; // ecx
  IUniformRandomStream *v51; // ecx
  float *v52; // eax
  float v53; // xmm1_4
  float v54; // xmm2_4
  Particle *v55; // eax
  Particle *v56; // esi
  IUniformRandomStream *v57; // ecx
  IUniformRandomStream *v58; // ecx
  double v59; // st7
  double v60; // st7
  float v61; // xmm0_4
  float z; // xmm1_4
  float y; // xmm2_4
  unsigned int *v64; // eax
  Vector origin; // [esp+6Ch] [ebp-58h] BYREF
  float v67; // [esp+78h] [ebp-4Ch]
  float v68; // [esp+7Ch] [ebp-48h]
  float v69; // [esp+80h] [ebp-44h]
  Vector moveDiff; // [esp+84h] [ebp-40h] BYREF
  Vector offset; // [esp+90h] [ebp-34h]
  Vector forward; // [esp+9Ch] [ebp-28h] BYREF
  CParticleSubTexture *flameMaterial; // [esp+A8h] [ebp-1Ch]
  int alpha; // [esp+ACh] [ebp-18h]
  CSmartPtr<CEmberEffect,CRefCountAccessor> pEmitter; // [esp+B0h] [ebp-14h] BYREF
  int j; // [esp+B4h] [ebp-10h]
  CSmartPtr<CSimpleEmitter,CRefCountAccessor> pSimple; // [esp+B8h] [ebp-Ch] BYREF
  int i; // [esp+BCh] [ebp-8h]

  if ( *(_DWORD *)&this->m_iName[24] != 0 && *(float *)(gpGlobals.m_Index + 16) != 0.0 )
  {
    CSimpleEmitter::Create(result: &pSimple, pDebugName: "MuzzleFlash");
    m_pObj = pSimple.m_pObj;
    v6 = (const Vector *)(*(int (__thiscall **)(char *, int, int))(*((_DWORD *)this - 608) + 40))(
                           a1: (char *)this - 2432,
                           a2: a3,
                           a3: a2);
    CParticleEffect::SetSortOrigin(this: m_pObj, vSortOrigin: v6);
    v7 = (const QAngle *)(*(int (__thiscall **)(char *))(*((_DWORD *)this - 608) + 44))(a1: (char *)this - 2432);
    AngleVectors(angles: v7, &forward);
    forward.x = -forward.x;
    forward.y = -forward.y;
    v8 = *(float *)this->m_iName;
    forward.z = -forward.z;
    *(float *)&alpha = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))random->RandomFloat)(
                         a1: random,
                         a2: v8 - 0.5,
                         a3: v8 + 0.5);
    i = 1;
    j = 11;
    while ( 1 )
    {
      v9 = *(int (__thiscall **)(char *))(*((_DWORD *)this - 608) + 40);
      v10 = (float)((float)i * 2.0) * *(float *)this->m_iName;
      v67 = v10 * forward.x;
      v68 = forward.y * v10;
      v69 = forward.z * v10;
      v11 = (float *)v9(a1: (char *)this - 2432);
      v12 = v11[1] + v68;
      v13 = v11[2] + v69;
      offset.x = *v11 + v67;
      offset.y = v12;
      offset.z = v13;
      v14 = pSimple.m_pObj;
      v15 = ((int (__thiscall *)(IUniformRandomStream *))random->RandomInt)(a1: random);
      v16 = VarArgs(format: "effects/muzzleflash%d", v15);
      PMaterial = CParticleEffect::GetPMaterial(this: v14, name: v16);
      v18 = CParticleEffect::AddParticle(this: v14, particleSize: 0x3Cu, material: PMaterial, origin: (const Vector *)1);
      v19 = v18;
      if ( v18 == nullptr )
        break;
      *(_QWORD *)&v18[1].m_Pos.y = 1008981770;
      v18[1].m_pPrev = nullptr;
      v18[1].m_pNext = nullptr;
      v18[1].m_pSubTexture = nullptr;
      v18[2].m_pPrev = (Particle *)-1;
      LOBYTE(v18[2].m_pNext) = 0x80;
      v20 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
              a1: random,
              a2: 1084227584,
              a3: 1086324736);
      flameMaterial = (CParticleSubTexture *)(int)(v20 * (double)j * 0.11111111 * *(float *)&alpha);
      v21 = (char)flameMaterial;
      BYTE1(v19[2].m_pNext) = (_BYTE)flameMaterial;
      BYTE2(v19[2].m_pNext) = v21;
      v22 = random->RandomInt(this: random, a2: 0, a3: 360);
      ++i;
      v23 = (float)v22;
      v24 = j - 1;
      v19[1].m_Pos.x = v23;
      v19[2].m_pSubTexture = nullptr;
      j = v24;
      if ( v24 <= 3 )
      {
        if ( LOBYTE(this->m_vecNetworkOrigin.z) != 0 )
        {
          v25 = (float *)(*(int (__thiscall **)(char *))(*((_DWORD *)this - 608) + 40))(a1: (char *)this - 2432);
          moveDiff.x = *v25 - *(float *)&this->m_hNetworkMoveParent.m_Index;
          moveDiff.y = v25[1] - *(float *)&this->m_hOwnerEntity.m_Index;
          moveDiff.z = v25[2] - *(float *)&this->m_hGroundEntity.m_Index;
          *(float *)&flameMaterial = VectorNormalize(vec: &moveDiff);
          v26 = (int)(float)(*(float *)&flameMaterial / (float)(this->m_vecBaseVelocity.z * 0.5));
          if ( v26 > 50 )
            v26 = 50;
          *(float *)&v27 = *(float *)&flameMaterial / (float)v26;
          flameMaterial = v27;
          i = 1;
          j = v26 + 1;
          if ( v26 + 1 > 1 )
          {
            while ( 1 )
            {
              v28 = *(CParticleEffect **)&this->m_iName[24];
              v29 = *(float *)&this->m_hOwnerEntity.m_Index + (float)((float)i * (float)(moveDiff.y * *(float *)&v27));
              v30 = *(float *)&this->m_hGroundEntity.m_Index + (float)((float)i * (float)(moveDiff.z * *(float *)&v27));
              offset.x = *(float *)&this->m_hNetworkMoveParent.m_Index
                       + (float)((float)i * (float)(moveDiff.x * *(float *)&v27));
              offset.y = v29;
              offset.z = v30;
              v31 = ((int (__thiscall *)(IUniformRandomStream *))random->RandomInt)(a1: random);
              v32 = CParticleEffect::AddParticle(
                      this: v28,
                      particleSize: 0x3Cu,
                      material: *(CParticleSubTexture **)&this->m_iName[4 * v31 + 4],
                      origin: nullptr);
              v33 = v32;
              if ( v32 != nullptr )
              {
                v32[1].m_Pos.z = 0.0;
                v32[1].m_Pos.y = ((double (__cdecl *)(_DWORD, _DWORD))random->RandomFloat)(
                                   a1: this->m_vecVelocity.y * 0.89999998,
                                   a2: this->m_vecVelocity.y * 1.1)
                               + this->m_vecVelocity.y;
                *(float *)&v33[1].m_pPrev = _RandomFloat(this: v34, a2: -1.0, a3: 1.0);
                *(float *)&v33[1].m_pNext = _RandomFloat(this: v35, a2: -1.0, a3: 1.0);
                *(float *)&v33[1].m_pSubTexture = _RandomFloat(this: v36, a2: -1.0, a3: 1.0);
                v37 = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))random->RandomFloat)(
                        a1: random,
                        a2: LODWORD(this->m_vecBaseVelocity.x),
                        a3: LODWORD(this->m_vecBaseVelocity.y));
                *(float *)&v33[1].m_pPrev = *(float *)&v33[1].m_pPrev * v37;
                *(float *)&v33[1].m_pNext = v37 * *(float *)&v33[1].m_pNext;
                *(float *)&v33[1].m_pSubTexture = v37 * *(float *)&v33[1].m_pSubTexture;
                v38 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                        a1: random,
                        a2: 1061158912,
                        a3: 1067450368);
                *(float *)&alpha = v38;
                v39 = *(float *)&this->m_nNextThinkTick * *(float *)&alpha;
                v40 = 1.0;
                v68 = *(float *)&this->m_iHealth * v38;
                v69 = v38 * *(float *)&this->m_fFlags;
                if ( v39 >= 0.0 )
                {
                  if ( v39 > 1.0 )
                    v39 = 1.0;
                }
                else
                {
                  v39 = 0.0;
                }
                v41 = v68;
                if ( v68 >= 0.0 )
                {
                  if ( v68 > 1.0 )
                    v41 = 1.0;
                }
                else
                {
                  v41 = 0.0;
                }
                if ( v69 >= 0.0 )
                {
                  if ( v69 <= 1.0 )
                    v40 = v69;
                }
                else
                {
                  v40 = 0.0;
                }
                BYTE2(v33[2].m_pPrev) = (int)(float)(v40 * 255.0);
                LOBYTE(v33[2].m_pPrev) = (int)(float)(v39 * 255.0);
                BYTE1(v33[2].m_pPrev) = (int)(float)(v41 * 255.0);
                alpha = (int)(((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                a1: random,
                                a2: 1061158912,
                                a3: 1067450368)
                            * this->m_vecBaseVelocity.z);
                BYTE1(v33[2].m_pNext) = alpha;
                alpha = (int)(((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                a1: random,
                                a2: 1065353216,
                                a3: 1067450368)
                            * this->m_angNetworkAngles.x);
                BYTE2(v33[2].m_pNext) = alpha;
                v42 = ((double (__cdecl *)(_DWORD, _DWORD))random->RandomFloat)(
                        a1: this->m_vecVelocity.x * 0.75,
                        a2: this->m_vecVelocity.x * 1.25);
                *(float *)&alpha = v42;
                if ( v42 <= 1.0 )
                {
                  v43 = *(float *)&alpha;
                  if ( *(float *)&alpha < 0.0 )
                    v43 = 0.0;
                }
                else
                {
                  v43 = 1.0;
                }
                *(_WORD *)((char *)&v33[2].m_pPrev + 3) = (unsigned __int8)(int)(float)(v43 * 255.0);
                v33[1].m_Pos.x = (float)random->RandomInt(this: random, a2: 0, a3: 360);
                *(float *)&v33[2].m_pSubTexture = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                                    a1: random,
                                                    a2: -1056964608,
                                                    a3: 1090519040);
              }
              if ( ++i >= j )
                break;
              v27 = flameMaterial;
            }
          }
        }
        if ( BYTE1(this->m_vecNetworkOrigin.z) != 0 )
        {
          CEmberEffect::Create(result: &pEmitter, pDebugName: "C_RocketTrail::damaged");
          v44 = pEmitter.m_pObj;
          v45 = (const Vector *)(*(int (__thiscall **)(char *))(*((_DWORD *)this - 608) + 40))(a1: (char *)this - 2432);
          CParticleEffect::SetSortOrigin(this: v44, vSortOrigin: v45);
          v46 = *(CParticleEffect **)&this->m_iName[24];
          v47 = random->RandomInt(this: random, a2: 1, a3: 4);
          v48 = VarArgs(format: "sprites/flamelet%d", v47);
          *(float *)&flameMaterial = COERCE_FLOAT(CParticleEffect::GetPMaterial(this: v46, name: v48));
          for ( j = 8; j != 0; --j )
          {
            v67 = _RandomFloat(this: v49, a2: -8.0, a3: 8.0);
            v68 = _RandomFloat(this: v50, a2: -8.0, a3: 8.0);
            v69 = _RandomFloat(this: v51, a2: -8.0, a3: 8.0);
            v52 = (float *)(*(int (__thiscall **)(char *))(*((_DWORD *)this - 608) + 40))(a1: (char *)this - 2432);
            v53 = v52[1] + v68;
            v54 = v52[2] + v69;
            origin.x = *v52 + v67;
            origin.y = v53;
            origin.z = v54;
            v55 = CParticleEffect::AddParticle(
                    this: pEmitter.m_pObj,
                    particleSize: 0x3Cu,
                    material: flameMaterial,
                    &origin);
            v56 = v55;
            if ( v55 != nullptr )
            {
              v55[1].m_Pos.z = 0.0;
              v55[1].m_Pos.y = 0.25;
              *(float *)&v55[1].m_pPrev = _RandomFloat(this: v49, a2: -1.0, a3: 1.0);
              *(float *)&v56[1].m_pNext = _RandomFloat(this: v57, a2: -1.0, a3: 1.0);
              *(float *)&v56[1].m_pSubTexture = _RandomFloat(this: v58, a2: -1.0, a3: 1.0);
              v59 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                      a1: random,
                      a2: 1107296256,
                      a3: 1124073472);
              *(float *)&v56[1].m_pPrev = *(float *)&v56[1].m_pPrev * v59;
              *(float *)&v56[1].m_pNext = *(float *)&v56[1].m_pNext * v59;
              *(float *)&v56[1].m_pSubTexture = v59 * *(float *)&v56[1].m_pSubTexture;
              v60 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                      a1: random,
                      a2: 1061158912,
                      a3: 1067450368);
              *(float *)&alpha = v60;
              v61 = *(float *)&this->m_nNextThinkTick * *(float *)&alpha;
              z = 0.0;
              moveDiff.y = *(float *)&this->m_iHealth * v60;
              moveDiff.z = v60 * *(float *)&this->m_fFlags;
              if ( v61 >= 0.0 )
              {
                if ( v61 > 1.0 )
                  v61 = 1.0;
              }
              else
              {
                v61 = 0.0;
              }
              y = moveDiff.y;
              if ( moveDiff.y >= 0.0 )
              {
                if ( moveDiff.y > 1.0 )
                  y = 1.0;
              }
              else
              {
                y = 0.0;
              }
              if ( moveDiff.z >= 0.0 )
              {
                if ( moveDiff.z <= 1.0 )
                  z = moveDiff.z;
                else
                  z = 1.0;
              }
              BYTE2(v56[2].m_pPrev) = (int)(float)(z * 255.0);
              LOBYTE(v56[2].m_pPrev) = (int)(float)(v61 * 255.0);
              BYTE1(v56[2].m_pPrev) = (int)(float)(y * 255.0);
              *(Particle **)((char *)&v56[2].m_pPrev + 3) = (Particle *)537395455;
              v56[1].m_Pos.x = (float)random->RandomInt(this: random, a2: 0, a3: 360);
              *(float *)&v56[2].m_pSubTexture = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                                  a1: random,
                                                  a2: -1056964608,
                                                  a3: 1090519040);
            }
          }
          if ( pEmitter.m_pObj != nullptr )
            CParticleEffect::Release(this: pEmitter.m_pObj);
        }
        v64 = (unsigned int *)(*(int (__thiscall **)(char *))(*((_DWORD *)this - 608) + 40))(a1: (char *)this - 2432);
        this->m_hNetworkMoveParent.m_Index = *v64;
        this->m_hOwnerEntity.m_Index = v64[1];
        this->m_hGroundEntity.m_Index = v64[2];
        break;
      }
    }
    if ( pSimple.m_pObj != nullptr )
      CParticleEffect::Release(this: pSimple.m_pObj);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024E280
// Name: void RPGShotDownCallback(class CEffectData const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RPGShotDownCallback(const CEffectData *data)
{
  CGlowOverlay *v1; // eax
  CGlowOverlay *v2; // esi
  CLocalPlayerFilter filter; // [esp+10h] [ebp-20h] BYREF

  CLocalPlayerFilter::CLocalPlayerFilter(this: &filter);
  C_BaseEntity::EmitSound(
    &filter,
    iEntIndex: 0,
    soundname: "Missile.ShotDown",
    pOrigin: &data->m_vOrigin,
    soundtime: 0.0,
    duration: nullptr);
  v1 = (CGlowOverlay *)MemAlloc_Alloc(nSize: 0xD8u);
  v2 = v1;
  if ( v1 != nullptr )
  {
    CGlowOverlay::CGlowOverlay(this: v1);
    v2->__vftable = (CGlowOverlay_vtbl *)&CExplosionOverlay::`vftable';
    v2[1].__vftable = nullptr;
    v2->m_vPos = data->m_vOrigin;
    v2->m_nSprites = 1;
    v2[1].m_vPos.x = 1.0;
    v2[1].m_vPos.y = 0.89999998;
    v2[1].m_vPos.z = 0.69999999;
    v2->m_Sprites[0].m_flHorzSize = 0.0099999998;
    v2->m_Sprites[0].m_flVertSize = 0.0049999999;
    CGlowOverlay::Activate(this: v2);
  }
  C_RecipientFilter::~C_RecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x1024E3B0
// Name: public: virtual void C_SporeTrail::RenderParticles(class CParticleRenderIterator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SporeTrail::RenderParticles(C_SporeTrail *this, CParticleRenderIterator *pIterator)
{
  CEffectMaterial *m_pMaterial; // ecx
  Particle *m_pNext; // eax
  Particle *m_pCur; // eax
  float *v6; // ecx
  float y; // xmm1_4
  float x; // xmm2_4
  float z; // xmm3_4
  ParticleDraw *m_pParticleDraw; // edx
  float v11; // xmm5_4
  Vector color; // [esp+10h] [ebp-18h] BYREF
  Vector tPos; // [esp+1Ch] [ebp-Ch] BYREF

  if ( LOBYTE(this->m_vecBaseVelocity.x) != 0 )
  {
    m_pMaterial = pIterator->m_pMaterial;
    pIterator->m_bGotFirst = true;
    m_pNext = m_pMaterial->m_Particles.m_pNext;
    pIterator->m_pCur = m_pNext;
    if ( m_pNext != &m_pMaterial->m_Particles )
    {
      pIterator->m_pParticleDraw->m_pSubTexture = m_pNext->m_pSubTexture;
      m_pCur = pIterator->m_pCur;
      if ( m_pCur != nullptr )
      {
        color.x = 1.0;
        color.y = 1.0;
        color.z = 1.0;
        do
        {
          v6 = *(float **)&this->m_iName[52];
          y = m_pCur->m_Pos.y;
          x = m_pCur->m_Pos.x;
          z = m_pCur->m_Pos.z;
          m_pParticleDraw = pIterator->m_pParticleDraw;
          v11 = v6[30];
          tPos.x = (float)((float)((float)(v6[26] * y) + (float)(v6[25] * x)) + (float)(v6[27] * z)) + v6[28];
          tPos.y = (float)((float)((float)(v6[29] * x) + (float)(v11 * y)) + (float)(v6[31] * z)) + v6[32];
          tPos.z = (float)((float)((float)(v6[33] * x) + (float)(v6[34] * y)) + (float)(v6[35] * z)) + v6[36];
          RenderParticle_ColorSize(pDraw: m_pParticleDraw, pos: &tPos, &color, alpha: 1.0, size: 4.0);
          m_pCur = (Particle *)CParticleRenderIterator::GetNext(this: pIterator, sortKey: tPos.z);
        }
        while ( m_pCur != nullptr );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024E520
// Name: public: C_FireTrail::C_FireTrail(void)
// Source: json
//------------------------------------------------------------------------------
C_FireTrail *__thiscall C_FireTrail::C_FireTrail(C_FireTrail *this)
{
  C_ParticleTrail::C_ParticleTrail(this);
  this->C_ParticleTrail::C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_FireTrail_vtbl *)&C_FireTrail::`vftable'{for `IClientUnknown'};
  this->C_ParticleTrail::C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_FireTrail::`vftable'{for `IClientRenderable'};
  this->C_ParticleTrail::C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_FireTrail::`vftable'{for `IClientNetworkable'};
  this->C_ParticleTrail::C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_FireTrail::`vftable'{for `IClientThinkable'};
  this->C_ParticleTrail::C_BaseParticleEntity::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_FireTrail::`vftable'{for `C_BaseEntity'};
  this->C_ParticleTrail::C_BaseParticleEntity::IParticleEffect::__vftable = (IParticleEffect_vtbl *)&C_FireTrail::`vftable'{for `IParticleEffect'};
  this->C_ParticleTrail::IPrototypeAppEffect::__vftable = (IPrototypeAppEffect_vtbl *)&C_FireTrail::`vftable';
  this->m_pTrailEmitter.m_pObj = nullptr;
  this->m_pSmokeEmitter.m_pObj = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1024E590
// Name: public: virtual C_FireTrail::~C_FireTrail(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_FireTrail::~C_FireTrail(C_FireTrail *this)
{
  CSmokeParticle *m_pObj; // ecx
  CSimpleEmitter *v3; // ecx

  this->C_ParticleTrail::C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_FireTrail_vtbl *)&C_FireTrail::`vftable'{for `IClientUnknown'};
  this->C_ParticleTrail::C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_FireTrail::`vftable'{for `IClientRenderable'};
  this->C_ParticleTrail::C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_FireTrail::`vftable'{for `IClientNetworkable'};
  this->C_ParticleTrail::C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_FireTrail::`vftable'{for `IClientThinkable'};
  this->C_ParticleTrail::C_BaseParticleEntity::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_FireTrail::`vftable'{for `C_BaseEntity'};
  this->C_ParticleTrail::C_BaseParticleEntity::IParticleEffect::__vftable = (IParticleEffect_vtbl *)&C_FireTrail::`vftable'{for `IParticleEffect'};
  this->C_ParticleTrail::IPrototypeAppEffect::__vftable = (IPrototypeAppEffect_vtbl *)&C_FireTrail::`vftable';
  m_pObj = this->m_pSmokeEmitter.m_pObj;
  if ( m_pObj != nullptr )
    CParticleEffect::Release(this: m_pObj);
  v3 = this->m_pTrailEmitter.m_pObj;
  if ( v3 != nullptr )
    CParticleEffect::Release(this: v3);
  C_ParticleTrail::~C_ParticleTrail(this);
}

//------------------------------------------------------------------------------
// Address: 0x1024E5F0
// Name: public: virtual void C_FireTrail::Update(float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge C_FireTrail::Update(C_FireTrail *this@<ecx>, int a2@<ebx>, int a3@<esi>, float fTimeDelta)
{
  int m_nNextThinkTick; // xmm0_4
  CSimpleEmitter *m_pObj; // ebx
  const Vector *v7; // eax
  float *v8; // eax
  IUniformRandomStream *v9; // ecx
  int v10; // eax
  int v11; // ebx
  IUniformRandomStream *v12; // ecx
  IUniformRandomStream *v13; // ecx
  float y; // esi
  float v15; // xmm0_4
  float v16; // xmm1_4
  int v17; // eax
  Particle *v18; // eax
  Particle *v19; // esi
  IUniformRandomStream *v20; // ecx
  IUniformRandomStream *v21; // ecx
  float (__thiscall *RandomFloat)(IUniformRandomStream *, float, float); // eax
  double v23; // st7
  float (__thiscall *v24)(IUniformRandomStream *, float, float); // eax
  IUniformRandomStream *v25; // ecx
  IUniformRandomStream *v26; // ecx
  float *v27; // eax
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // esi
  int (__thiscall *RandomInt)(IUniformRandomStream *, int, int); // eax
  int v32; // eax
  Particle *v33; // eax
  Particle *v34; // esi
  double v35; // st7
  IUniformRandomStream *v36; // ecx
  IUniformRandomStream *v37; // ecx
  IUniformRandomStream *v38; // ecx
  float (__thiscall *v39)(IUniformRandomStream *, float, float); // eax
  double v40; // st7
  double v41; // st6
  double v42; // st6
  unsigned __int8 v43; // al
  float *v44; // eax
  CSimpleEmitter *v45; // ecx
  float v47; // [esp+14h] [ebp-30h]
  float v48; // [esp+14h] [ebp-30h]
  float v49; // [esp+18h] [ebp-2Ch]
  float v50; // [esp+18h] [ebp-2Ch]
  float v51; // [esp+1Ch] [ebp-28h]
  Vector moveDiff; // [esp+20h] [ebp-24h] BYREF
  Vector offset; // [esp+2Ch] [ebp-18h] BYREF
  int i; // [esp+38h] [ebp-Ch]
  CSmartPtr<CSimpleEmitter,CRefCountAccessor> pSimple; // [esp+3Ch] [ebp-8h] BYREF
  float step; // [esp+40h] [ebp-4h]

  if ( LODWORD(this->m_vecVelocity.x) != 0 )
  {
    m_nNextThinkTick = this->m_nNextThinkTick;
    if ( *(float *)&m_nNextThinkTick == 0.0 || *(float *)(gpGlobals.m_Index + 12) < *(float *)&m_nNextThinkTick )
    {
      CSimpleEmitter::Create(result: &pSimple, pDebugName: "FireTrail");
      m_pObj = pSimple.m_pObj;
      v7 = (const Vector *)(*(int (__thiscall **)(char *, int, int))(*((_DWORD *)this - 608) + 40))(
                             a1: (char *)this - 2432,
                             a2: a3,
                             a3: a2);
      CParticleEffect::SetSortOrigin(this: m_pObj, vSortOrigin: v7);
      v8 = (float *)(*(int (__thiscall **)(char *))(*((_DWORD *)this - 608) + 40))(a1: (char *)this - 2432);
      moveDiff.x = *v8 - this->m_vecNetworkOrigin.x;
      moveDiff.y = v8[1] - this->m_vecNetworkOrigin.y;
      moveDiff.z = v8[2] - this->m_vecNetworkOrigin.z;
      step = VectorNormalize(vec: &moveDiff);
      v10 = (int)(float)(step * 0.25);
      if ( v10 >= 1 )
      {
        if ( v10 > 32 )
          v10 = 32;
      }
      else
      {
        v10 = 1;
      }
      v11 = 1;
      step = step / (float)v10;
      for ( i = v10 + 1; v11 < i; ++v11 )
      {
        _RandomFloat(this: v9, a2: -4.0, a3: 4.0);
        v49 = _RandomFloat(this: v12, a2: -4.0, a3: 4.0);
        _RandomFloat(this: v13, a2: -4.0, a3: 4.0);
        y = this->m_vecVelocity.y;
        v15 = (float)(this->m_vecNetworkOrigin.y + (float)((float)(moveDiff.y * step) * (float)v11)) + v49;
        v16 = (float)(this->m_vecNetworkOrigin.z + (float)((float)(moveDiff.z * step) * (float)v11))
            + COERCE_FLOAT(&offset);
        offset.x = (float)(this->m_vecNetworkOrigin.x + (float)((float)(moveDiff.x * step) * (float)v11)) + v47;
        offset.y = v15;
        offset.z = v16;
        v17 = ((int (__thiscall *)(IUniformRandomStream *))random->RandomInt)(a1: random);
        v18 = CParticleEffect::AddParticle(
                this: (CParticleEffect *)LODWORD(y),
                particleSize: 0x3Cu,
                material: *((CParticleSubTexture **)&this->m_vecVelocity.z + v17),
                origin: (const Vector *)2);
        v19 = v18;
        if ( v18 != nullptr )
        {
          v18[1].m_Pos.y = 0.5;
          v18[1].m_Pos.z = 0.0;
          *(float *)&v18[1].m_pPrev = _RandomFloat(this: v9, a2: 0.0, a3: 1.0);
          *(float *)&v19[1].m_pNext = _RandomFloat(this: v20, a2: 0.0, a3: 1.0);
          *(float *)&v19[1].m_pSubTexture = _RandomFloat(this: v21, a2: 0.0, a3: 1.0);
          RandomFloat = random->RandomFloat;
          offset.x = 64.0;
          moveDiff.z = 32.0;
          v23 = ((double (__thiscall *)(IUniformRandomStream *))RandomFloat)(a1: random);
          *(float *)&v19[1].m_pPrev = *(float *)&v19[1].m_pPrev * v23;
          *(float *)&v19[1].m_pNext = *(float *)&v19[1].m_pNext * v23;
          *(float *)&v19[1].m_pSubTexture = v23 * *(float *)&v19[1].m_pSubTexture;
          *(float *)&v19[1].m_pSubTexture = *(float *)&v19[1].m_pSubTexture + 50.0;
          v19[1].m_Pos.x = 0.0;
          *(_WORD *)((char *)&v19[2].m_pNext + 1) = 1040;
          v19[2].m_pPrev = (Particle *)-1;
          LOBYTE(v19[2].m_pNext) = 0;
          v24 = random->RandomFloat;
          moveDiff.y = 16.0;
          moveDiff.x = -16.0;
          *(float *)&v19[2].m_pSubTexture = ((double (__thiscall *)(IUniformRandomStream *))v24)(a1: random);
        }
      }
      v48 = _RandomFloat(this: v9, a2: -4.0, a3: 4.0);
      v50 = _RandomFloat(this: v25, a2: -4.0, a3: 4.0);
      v51 = _RandomFloat(this: v26, a2: -4.0, a3: 4.0);
      v27 = (float *)(*(int (__thiscall **)(char *))(*((_DWORD *)this - 608) + 40))(a1: (char *)this - 2432);
      v28 = v27[1] + v50;
      v29 = v27[2] + v51;
      v30 = this->m_vecVelocity.y;
      offset.x = *v27 + v48;
      offset.y = v28;
      offset.z = v29;
      RandomInt = random->RandomInt;
      LODWORD(offset.y) = 1;
      offset.x = 0.0;
      v32 = ((int (__thiscall *)(IUniformRandomStream *))RandomInt)(a1: random);
      v33 = CParticleEffect::AddParticle(
              this: (CParticleEffect *)LODWORD(v30),
              particleSize: 0x3Cu,
              material: *((CParticleSubTexture **)&this->m_vecVelocity.z + v32),
              origin: (const Vector *)LODWORD(offset.x));
      v34 = v33;
      if ( v33 != nullptr )
      {
        v33[1].m_Pos.z = 0.0;
        v35 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                a1: random,
                a2: 1030121063,
                a3: 1035993088);
        moveDiff.y = 1.0;
        v34[1].m_Pos.y = v35 + 0.75;
        *(float *)&v34[1].m_pPrev = _RandomFloat(this: v36, a2: 0.0, a3: moveDiff.y);
        *(float *)&v34[1].m_pNext = _RandomFloat(this: v37, a2: 0.0, a3: 1.0);
        *(float *)&v34[1].m_pSubTexture = _RandomFloat(this: v38, a2: 0.0, a3: 1.0);
        v39 = random->RandomFloat;
        pSimple.m_pObj = (CSimpleEmitter *)1115684864;
        v40 = ((double (__thiscall *)(IUniformRandomStream *, int))v39)(a1: random, a2: 1107296256);
        v41 = *(float *)&v34[1].m_pPrev * v40;
        offset.z = 100.0;
        *(float *)&v34[1].m_pPrev = v41;
        v42 = *(float *)&v34[1].m_pNext;
        offset.y = 50.0;
        *(float *)&v34[1].m_pNext = v42 * v40;
        *(float *)&v34[1].m_pSubTexture = v40 * *(float *)&v34[1].m_pSubTexture;
        *(float *)&v34[1].m_pSubTexture = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))random->RandomFloat)(
                                            a1: random,
                                            a2: LODWORD(offset.y),
                                            a3: LODWORD(offset.z))
                                        + *(float *)&v34[1].m_pSubTexture;
        LOWORD(v34[2].m_pPrev) = 31359;
        BYTE2(v34[2].m_pPrev) = 102;
        i = (int)(((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                    a1: random,
                    a2: 1061158912,
                    a3: 1067450368)
                * 16.0);
        v43 = i;
        BYTE1(v34[2].m_pNext) = i;
        BYTE2(v34[2].m_pNext) = (int)(float)((float)v43 * 2.5);
        *(_WORD *)((char *)&v34[2].m_pPrev + 3) = 64;
        v34[1].m_Pos.x = (float)random->RandomInt(this: random, a2: 0, a3: 360);
        *(float *)&v34[2].m_pSubTexture = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                            a1: random,
                                            a2: -1048576000,
                                            a3: 1098907648);
      }
      v44 = (float *)(*(int (__thiscall **)(char *))(*((_DWORD *)this - 608) + 40))(a1: (char *)this - 2432);
      v45 = pSimple.m_pObj;
      this->m_vecNetworkOrigin.x = *v44;
      this->m_vecNetworkOrigin.y = v44[1];
      this->m_vecNetworkOrigin.z = v44[2];
      if ( v45 != nullptr )
        CParticleEffect::Release(this: v45);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024EC30
// Name: public: C_DustTrail::C_DustTrail(void)
// Source: json
//------------------------------------------------------------------------------
C_DustTrail *__thiscall C_DustTrail::C_DustTrail(C_DustTrail *this)
{
  double v2; // st7
  CSimpleEmitter *m_pObj; // ecx

  C_BaseParticleEntity::C_BaseParticleEntity(this);
  this->IPrototypeAppEffect::__vftable = (IPrototypeAppEffect_vtbl *)&IPrototypeAppEffect::`vftable';
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_DustTrail_vtbl *)&C_DustTrail::`vftable'{for `IClientUnknown'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_DustTrail::`vftable'{for `IClientRenderable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_DustTrail::`vftable'{for `IClientNetworkable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_DustTrail::`vftable'{for `IClientThinkable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_DustTrail::`vftable'{for `C_BaseEntity'};
  this->C_BaseParticleEntity::IParticleEffect::__vftable = (IParticleEffect_vtbl *)&C_DustTrail::`vftable'{for `IParticleEffect'};
  this->IPrototypeAppEffect::__vftable = (IPrototypeAppEffect_vtbl *)&C_DustTrail::`vftable';
  this->m_pDustEmitter.m_pObj = nullptr;
  *(_QWORD *)this->m_MaterialHandle = 0;
  *(_QWORD *)&this->m_MaterialHandle[2] = 0;
  *(_QWORD *)&this->m_MaterialHandle[4] = 0;
  *(_QWORD *)&this->m_MaterialHandle[6] = 0;
  *(_QWORD *)&this->m_MaterialHandle[8] = 0;
  *(_QWORD *)&this->m_MaterialHandle[10] = 0;
  *(_QWORD *)&this->m_MaterialHandle[12] = 0;
  *(_QWORD *)&this->m_MaterialHandle[14] = 0;
  this->m_SpawnRate = 10.0;
  this->m_ParticleSpawn.m_TimeBetweenEvents = 0.1;
  this->m_ParticleSpawn.m_fNextEvent = 0.0;
  this->m_Color.x = 0.5;
  this->m_Color.y = 0.5;
  this->m_Color.z = 0.5;
  this->m_ParticleLifetime = 5.0;
  v2 = *(float *)(gpGlobals.m_Index + 12);
  this->m_MaxSpeed = 4.0;
  this->m_StartEmitTime = v2;
  this->m_StartSize = 35.0;
  this->m_StopEmitTime = 0.0;
  this->m_MinSpeed = 2.0;
  *(_QWORD *)&this->m_MinDirectedSpeed = 0;
  this->m_EndSize = 55.0;
  this->m_SpawnRadius = 2.0;
  this->m_VelocityOffset.x = 0.0;
  this->m_VelocityOffset.y = 0.0;
  this->m_VelocityOffset.z = 0.0;
  this->m_Opacity = 0.5;
  this->m_bEmit = true;
  m_pObj = this->m_pDustEmitter.m_pObj;
  if ( m_pObj != nullptr )
  {
    CParticleEffect::Release(this: m_pObj);
    this->m_pDustEmitter.m_pObj = nullptr;
  }
  this->m_pParticleMgr = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1024EE00
// Name: public: virtual C_DustTrail::~C_DustTrail(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_DustTrail::~C_DustTrail(C_DustTrail *this)
{
  CSimpleEmitter *m_pObj; // eax
  KeyValues *v3; // eax
  KeyValues *v4; // edi
  CParticleMgr *m_pParticleMgr; // ecx
  CSimpleEmitter *v6; // ecx

  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_DustTrail_vtbl *)&C_DustTrail::`vftable'{for `IClientUnknown'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_DustTrail::`vftable'{for `IClientRenderable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_DustTrail::`vftable'{for `IClientNetworkable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_DustTrail::`vftable'{for `IClientThinkable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_DustTrail::`vftable'{for `C_BaseEntity'};
  this->C_BaseParticleEntity::IParticleEffect::__vftable = (IParticleEffect_vtbl *)&C_DustTrail::`vftable'{for `IParticleEffect'};
  this->IPrototypeAppEffect::__vftable = (IPrototypeAppEffect_vtbl *)&C_DustTrail::`vftable';
  if ( ToolsEnabled() && clienttools->IsInRecordingMode(this: clienttools) )
  {
    m_pObj = this->m_pDustEmitter.m_pObj;
    if ( m_pObj != nullptr && m_pObj->m_nToolParticleEffectId != -1 )
    {
      v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v3 != nullptr )
        v4 = KeyValues::KeyValues(this: v3, setName: "OldParticleSystem_ActivateEmitter");
      else
        v4 = nullptr;
      KeyValues::SetInt(this: v4, keyName: "id", value: this->m_pDustEmitter.m_pObj->m_nToolParticleEffectId);
      KeyValues::SetInt(this: v4, keyName: "emitter", value: 0);
      KeyValues::SetInt(this: v4, keyName: "active", value: 0);
      KeyValues::SetFloat(this: v4, keyName: "time", value: *(float *)(gpGlobals.m_Index + 12));
      ToolFramework_PostToolMessage(hEntity: 0, msg: v4);
      KeyValues::deleteThis(this: v4);
    }
  }
  m_pParticleMgr = this->m_pParticleMgr;
  if ( m_pParticleMgr != nullptr )
    CParticleMgr::RemoveEffect(this: m_pParticleMgr, pEffect: &this->m_ParticleEffect);
  v6 = this->m_pDustEmitter.m_pObj;
  if ( v6 != nullptr )
    CParticleEffect::Release(this: v6);
  this->IPrototypeAppEffect::__vftable = (IPrototypeAppEffect_vtbl *)&IPrototypeAppEffect::`vftable';
  C_BaseParticleEntity::~C_BaseParticleEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x1024EF40
// Name: public: virtual void C_DustTrail::Start(class CParticleMgr __near *,class IPrototypeArgAccess __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_DustTrail::Start(C_DustTrail *this, CParticleMgr *pParticleMgr, IPrototypeArgAccess *pArgs)
{
  IParticleEffect *v4; // eax
  CSimpleEmitter *v5; // eax
  CParticleEffect *v6; // edi
  float x; // ecx
  float v8; // edi
  const Vector *v9; // eax
  __int128 *p_m_pfnTouch; // edi
  int i; // ebx

  if ( this == (C_DustTrail *)2664 )
    v4 = nullptr;
  else
    v4 = (IParticleEffect *)((char *)this - 232);
  if ( CParticleMgr::AddEffect(this: pParticleMgr, pEffect: (CParticleEffectBinding *)((char *)this - 228), pSim: v4) != 0 )
  {
    LODWORD(this->m_vecAbsVelocity.z) = pParticleMgr;
    v5 = (CSimpleEmitter *)MemAlloc_Alloc(nSize: 0x108u);
    v6 = v5;
    if ( v5 != nullptr )
    {
      CSimpleEmitter::CSimpleEmitter(this: v5, pDebugName: "DustTrail");
      v6->__vftable = (CParticleEffect_vtbl *)&CDustFollower::`vftable';
    }
    else
    {
      v6 = nullptr;
    }
    if ( v6 != (CParticleEffect *)LODWORD(this->m_vecAbsOrigin.x) )
    {
      if ( v6 != nullptr )
        CParticleEffect::AddRef(this: v6);
      x = this->m_vecAbsOrigin.x;
      if ( x != 0.0 )
        CParticleEffect::Release(this: (CParticleEffect *)LODWORD(x));
      LODWORD(this->m_vecAbsOrigin.x) = v6;
    }
    v8 = this->m_vecAbsOrigin.x;
    if ( v8 != 0.0 )
    {
      v9 = (const Vector *)(*(int (__thiscall **)(char *))(*((_DWORD *)this - 666) + 40))(a1: (char *)this - 2664);
      CParticleEffect::SetSortOrigin(this: (CParticleEffect *)LODWORD(v8), vSortOrigin: v9);
      CSimpleEmitter::SetNearClip(
        this: (CSimpleEmitter *)LODWORD(this->m_vecAbsOrigin.x),
        nearClipMin: 64.0,
        nearClipMax: 128.0);
      p_m_pfnTouch = &this->m_pfnTouch;
      for ( i = 16; i != 0; --i )
      {
        *(_DWORD *)p_m_pfnTouch = CParticleEffect::GetPMaterial(
                                    this: (CParticleEffect *)LODWORD(this->m_vecAbsOrigin.x),
                                    name: "particle/smokesprites_0001");
        p_m_pfnTouch = (__int128 *)((char *)p_m_pfnTouch + 4);
      }
      this->m_vecAbsVelocity.x = 1.0
                               / *(float *)&this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientRenderable::__vftable;
      this->m_vecAbsVelocity.y = 0.0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024F070
// Name: public: virtual void C_DustTrail::CleanupToolRecordingState(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_DustTrail::CleanupToolRecordingState(C_DustTrail *this, int msg)
{
  CSimpleEmitter *m_pObj; // ebx
  C_BaseEntity *MoveParent; // esi
  float m_StopEmitTime; // xmm0_4
  KeyValues *v6; // eax
  KeyValues *v7; // ebx
  KeyValues *Key; // ebx
  void *v9; // eax
  float *v10; // eax
  int v11; // eax
  int v12; // eax
  float z; // xmm0_4
  KeyValues *v14; // esi
  KeyValues *v15; // esi
  KeyValues *v16; // esi
  KeyValues *v17; // esi
  KeyValues *v18; // eax
  float y; // xmm1_4
  KeyValues *v20; // esi
  float x; // xmm1_4
  double v22; // st7
  KeyValues *v23; // eax
  float v24; // xmm0_4
  int v25; // esi
  int v26; // ecx
  int v27; // eax
  KeyValues *v28; // esi
  int v29; // eax
  KeyValues *v30; // esi
  KeyValues *v31; // esi
  KeyValues *v32; // edi
  KeyValues *v33; // esi
  KeyValues *v34; // eax
  int value; // [esp+0h] [ebp-38h]
  KeyValues *pEmitter; // [esp+10h] [ebp-28h]
  int v37; // [esp+14h] [ebp-24h] BYREF
  int v38; // [esp+18h] [ebp-20h] BYREF
  int v39; // [esp+1Ch] [ebp-1Ch] BYREF
  int v40; // [esp+20h] [ebp-18h] BYREF
  int minVal; // [esp+24h] [ebp-14h] BYREF
  int maxVal; // [esp+28h] [ebp-10h] BYREF
  int val; // [esp+2Ch] [ebp-Ch] BYREF
  KeyValues *msga; // [esp+30h] [ebp-8h]
  int nMaxAlpha; // [esp+34h] [ebp-4h] BYREF

  if ( ToolsEnabled() )
  {
    CScoreboardScaleform::SetParent((vgui::TreeView *)this, itemIndex: msg);
    if ( clienttools->IsInRecordingMode(this: clienttools) )
    {
      m_pObj = this->m_pDustEmitter.m_pObj;
      if ( m_pObj != nullptr )
      {
        MoveParent = C_BaseEntity::GetMoveParent(this);
        if ( MoveParent != nullptr )
        {
          HIBYTE(msg) = this->m_bEmit
                     && ((m_StopEmitTime = this->m_StopEmitTime) == 0.0
                      || m_StopEmitTime > *(float *)(gpGlobals.m_Index + 12));
          if ( m_pObj->m_nToolParticleEffectId == -1 )
          {
            nMaxAlpha = CParticleEffect::AllocateToolParticleEffectId(this: m_pObj);
            v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v6 != nullptr )
            {
              v7 = KeyValues::KeyValues(this: v6, setName: "OldParticleSystem_Create");
              msga = v7;
            }
            else
            {
              msga = nullptr;
              v7 = nullptr;
            }
            KeyValues::SetString(this: v7, keyName: "name", value: "C_DustTrail");
            KeyValues::SetInt(this: v7, keyName: "id", value: nMaxAlpha);
            KeyValues::SetFloat(this: v7, keyName: "time", value: *(float *)(gpGlobals.m_Index + 12));
            pEmitter = KeyValues::FindKey(this: v7, keyName: "DmeSpriteEmitter", bCreate: true);
            KeyValues::SetString(this: pEmitter, keyName: "material", value: "particle/smokesprites_0001");
            KeyValues::SetInt(this: pEmitter, keyName: "count", value: (int)this->m_SpawnRate);
            KeyValues::SetFloat(this: pEmitter, keyName: "duration", value: -1.0);
            KeyValues::SetInt(this: pEmitter, keyName: "active", value: HIBYTE(msg));
            Key = KeyValues::FindKey(this: pEmitter, keyName: "initializers", bCreate: true);
            msg = (int)KeyValues::FindKey(this: Key, keyName: "DmePositionPointToEntityInitializer", bCreate: true);
            v9 = (void *)MoveParent->entindex(this: &MoveParent->IClientNetworkable);
            KeyValues::SetPtr(this: (KeyValues *)msg, keyName: "entindex", value: v9);
            KeyValues::SetInt(this: (KeyValues *)msg, keyName: "attachmentIndex", value: this->m_iParentAttachment);
            KeyValues::SetFloat(this: (KeyValues *)msg, keyName: "randomDist", value: this->m_SpawnRadius);
            v10 = (float *)MoveParent->GetAbsOrigin(this: MoveParent);
            KeyValues::SetFloat(this: (KeyValues *)msg, keyName: "startx", value: *v10);
            v11 = (int)MoveParent->GetAbsOrigin(this: MoveParent);
            KeyValues::SetFloat(this: (KeyValues *)msg, keyName: "starty", value: *(float *)(v11 + 4));
            v12 = (int)MoveParent->GetAbsOrigin(this: MoveParent);
            KeyValues::SetFloat(this: (KeyValues *)msg, keyName: "startz", value: *(float *)(v12 + 8));
            msg = (int)KeyValues::FindKey(this: Key, keyName: "DmeDecayVelocityInitializer", bCreate: true);
            C_BaseEntity::CalcAbsoluteVelocity(this: MoveParent);
            KeyValues::SetFloat(this: (KeyValues *)msg, keyName: "velocityX", value: MoveParent->m_vecAbsVelocity.x);
            C_BaseEntity::CalcAbsoluteVelocity(this: MoveParent);
            KeyValues::SetFloat(this: (KeyValues *)msg, keyName: "velocityY", value: MoveParent->m_vecAbsVelocity.y);
            C_BaseEntity::CalcAbsoluteVelocity(this: MoveParent);
            z = MoveParent->m_vecAbsVelocity.z;
            v14 = (KeyValues *)msg;
            KeyValues::SetFloat(this: (KeyValues *)msg, keyName: "velocityZ", value: z);
            KeyValues::SetFloat(this: v14, keyName: "decayto", value: 0.5);
            KeyValues::SetFloat(this: v14, keyName: "decaytime", value: 0.30000001);
            v15 = KeyValues::FindKey(this: Key, keyName: "DmeRandomLifetimeInitializer", bCreate: true);
            KeyValues::SetFloat(this: v15, keyName: "minLifetime", value: this->m_ParticleLifetime);
            KeyValues::SetFloat(this: v15, keyName: "maxLifetime", value: this->m_ParticleLifetime);
            v16 = KeyValues::FindKey(this: Key, keyName: "DmeRandomRollInitializer", bCreate: true);
            KeyValues::SetFloat(this: v16, keyName: "minRoll", value: 0.0);
            KeyValues::SetFloat(this: v16, keyName: "maxRoll", value: 360.0);
            v17 = KeyValues::FindKey(this: Key, keyName: "DmeRandomRollSpeedInitializer", bCreate: true);
            KeyValues::SetFloat(this: v17, keyName: "minRollSpeed", value: -1.0);
            KeyValues::SetFloat(this: v17, keyName: "maxRollSpeed", value: 1.0);
            v18 = KeyValues::FindKey(this: Key, keyName: "DmeRandomValueColorInitializer", bCreate: true);
            *(float *)&v37 = this->m_Color.z * 255.0;
            y = this->m_Color.y;
            v20 = v18;
            v38 = 0;
            minVal = 0;
            nMaxAlpha = 0;
            v39 = 255;
            maxVal = 255;
            *(float *)&v40 = y * 255.0;
            x = this->m_Color.x;
            msg = 255;
            *(float *)&val = x * 255.0;
            val = (int)clamp<float,int,int>((float *)&val, minVal: &nMaxAlpha, maxVal: &msg);
            LOBYTE(nMaxAlpha) = val;
            v40 = (int)clamp<float,int,int>(val: (float *)&v40, &minVal, &maxVal);
            BYTE1(nMaxAlpha) = v40;
            v22 = clamp<float,int,int>(val: (float *)&v37, minVal: &v38, maxVal: &v39);
            HIBYTE(nMaxAlpha) = -1;
            v37 = (int)v22;
            BYTE2(nMaxAlpha) = (int)v22;
            KeyValues::SetColor(this: v20, keyName: "startColor", value: (Color)nMaxAlpha);
            KeyValues::SetFloat(this: v20, keyName: "minStartValueDelta", value: 0.0);
            KeyValues::SetFloat(this: v20, keyName: "maxStartValueDelta", value: 0.0);
            KeyValues::SetColor(this: v20, keyName: "endColor", value: (Color)nMaxAlpha);
            v23 = KeyValues::FindKey(this: Key, keyName: "DmeRandomAlphaInitializer", bCreate: true);
            v24 = this->m_Opacity * 255.0;
            v25 = (int)(float)(v24 * 0.75);
            msg = (int)v23;
            nMaxAlpha = (int)(float)(v24 * 1.25);
            if ( v25 >= 0 )
            {
              v26 = 255;
              if ( v25 <= 255 )
                v26 = (int)(float)(v24 * 0.75);
            }
            else
            {
              v26 = 0;
            }
            KeyValues::SetInt(this: v23, keyName: "minStartAlpha", value: v26);
            v27 = nMaxAlpha;
            if ( nMaxAlpha >= 0 )
            {
              if ( nMaxAlpha > 255 )
                v27 = 255;
            }
            else
            {
              v27 = 0;
            }
            KeyValues::SetInt(this: (KeyValues *)msg, keyName: "maxStartAlpha", value: v27);
            if ( v25 >= 0 )
            {
              if ( v25 > 255 )
                v25 = 255;
            }
            else
            {
              v25 = 0;
            }
            value = v25;
            v28 = (KeyValues *)msg;
            KeyValues::SetInt(this: (KeyValues *)msg, keyName: "minEndAlpha", value);
            v29 = nMaxAlpha;
            if ( nMaxAlpha >= 0 )
            {
              if ( nMaxAlpha > 255 )
                v29 = 255;
            }
            else
            {
              v29 = 0;
            }
            KeyValues::SetInt(this: v28, keyName: "maxEndAlpha", value: v29);
            v30 = KeyValues::FindKey(this: Key, keyName: "DmeRandomSizeInitializer", bCreate: true);
            KeyValues::SetFloat(this: v30, keyName: "minStartSize", value: this->m_StartSize);
            KeyValues::SetFloat(this: v30, keyName: "maxStartSize", value: this->m_StartSize);
            KeyValues::SetFloat(this: v30, keyName: "minEndSize", value: this->m_EndSize);
            KeyValues::SetFloat(this: v30, keyName: "maxEndSize", value: this->m_EndSize);
            v31 = KeyValues::FindKey(this: pEmitter, keyName: "updaters", bCreate: true);
            KeyValues::FindKey(this: v31, keyName: "DmePositionVelocityDecayUpdater", bCreate: true);
            KeyValues::FindKey(this: v31, keyName: "DmeRollUpdater", bCreate: true);
            v32 = KeyValues::FindKey(this: v31, keyName: "DmeRollSpeedAttenuateUpdater", bCreate: true);
            KeyValues::SetFloat(this: v32, keyName: "attenuation", value: 0.73333335);
            KeyValues::SetFloat(this: v32, keyName: "attenuationTme", value: 0.033333335);
            KeyValues::SetFloat(this: v32, keyName: "minRollSpeed", value: 0.5);
            KeyValues::FindKey(this: v31, keyName: "DmeAlphaSineRampUpdater", bCreate: true);
            KeyValues::FindKey(this: v31, keyName: "DmeColorUpdater", bCreate: true);
            KeyValues::FindKey(this: v31, keyName: "DmeSizeUpdater", bCreate: true);
            v33 = msga;
          }
          else
          {
            v34 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v34 != nullptr )
              v33 = KeyValues::KeyValues(this: v34, setName: "OldParticleSystem_ActivateEmitter");
            else
              v33 = nullptr;
            KeyValues::SetInt(this: v33, keyName: "id", value: this->m_pDustEmitter.m_pObj->m_nToolParticleEffectId);
            KeyValues::SetInt(this: v33, keyName: "emitter", value: 0);
            KeyValues::SetInt(this: v33, keyName: "active", value: HIBYTE(msg));
            KeyValues::SetFloat(this: v33, keyName: "time", value: *(float *)(gpGlobals.m_Index + 12));
          }
          ToolFramework_PostToolMessage(hEntity: 0, msg: v33);
          KeyValues::deleteThis(this: v33);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024F980
// Name: public: virtual void C_FireTrail::Start(class CParticleMgr __near *,class IPrototypeArgAccess __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_FireTrail::Start(C_FireTrail *this, CParticleMgr *pParticleMgr, IPrototypeArgAccess *pArgs)
{
  CSmartPtr<CSimpleEmitter,CRefCountAccessor> *v4; // eax
  CParticleEffect *m_pObj; // edi
  VarMapEntry_t *m_pMemory; // ecx
  VarMapEntry_t *v7; // ebx
  const Vector *v8; // eax
  VarMapEntry_t *PMaterial; // eax
  VarMapEntry_t *v10; // ecx
  CParticleSubTexture *v11; // eax
  VarMapEntry_t *v12; // ecx
  CParticleSubTexture *v13; // eax
  VarMapEntry_t *v14; // ecx
  CParticleSubTexture *v15; // eax
  VarMapEntry_t *v16; // ecx
  CSimpleEmitter *v17; // eax
  CParticleEffect *v18; // ebx
  CParticleEffect *m_nAllocationCount; // ecx
  CParticleEffect *v20; // ebx
  const Vector *v21; // eax
  float *v22; // eax

  C_ParticleTrail::Start(this, pParticleMgr, pArgs);
  v4 = CSimpleEmitter::Create(result: (CSmartPtr<CSimpleEmitter,CRefCountAccessor> *)&pArgs, pDebugName: "FireTrail");
  m_pObj = v4->m_pObj;
  if ( v4->m_pObj != (CSimpleEmitter *)this->m_VarMap.m_Entries.m_Memory.m_pMemory )
  {
    if ( m_pObj != nullptr )
      CParticleEffect::AddRef(this: v4->m_pObj);
    m_pMemory = this->m_VarMap.m_Entries.m_Memory.m_pMemory;
    if ( m_pMemory != nullptr )
      CParticleEffect::Release(this: (CParticleEffect *)m_pMemory);
    this->m_VarMap.m_Entries.m_Memory.m_pMemory = (VarMapEntry_t *)m_pObj;
  }
  if ( pArgs != nullptr )
    CParticleEffect::Release(this: (CParticleEffect *)pArgs);
  v7 = this->m_VarMap.m_Entries.m_Memory.m_pMemory;
  if ( v7 != nullptr )
  {
    v8 = (const Vector *)(*(int (__thiscall **)(char *))(*((_DWORD *)this - 666) + 40))(a1: (char *)this - 2664);
    CParticleEffect::SetSortOrigin(this: (CParticleEffect *)v7, vSortOrigin: v8);
    *(_QWORD *)&this->m_VarMap.m_Entries.m_Memory.m_nGrowSize = *(_QWORD *)g_Mat_DustPuff;
    PMaterial = (VarMapEntry_t *)CParticleEffect::GetPMaterial(
                                   this: (CParticleEffect *)this->m_VarMap.m_Entries.m_Memory.m_pMemory,
                                   name: "sprites/flamelet1");
    v10 = this->m_VarMap.m_Entries.m_Memory.m_pMemory;
    this->m_VarMap.m_Entries.m_pElements = PMaterial;
    v11 = CParticleEffect::GetPMaterial(this: (CParticleEffect *)v10, name: "sprites/flamelet2");
    v12 = this->m_VarMap.m_Entries.m_Memory.m_pMemory;
    this->m_VarMap.m_nInterpolatedEntries = (int)v11;
    v13 = CParticleEffect::GetPMaterial(this: (CParticleEffect *)v12, name: "sprites/flamelet3");
    v14 = this->m_VarMap.m_Entries.m_Memory.m_pMemory;
    LODWORD(this->m_VarMap.m_lastInterpolationTime) = v13;
    v15 = CParticleEffect::GetPMaterial(this: (CParticleEffect *)v14, name: "sprites/flamelet4");
    v16 = this->m_VarMap.m_Entries.m_Memory.m_pMemory;
    *((_DWORD *)&this->m_VarMap + 7) = v15;
    LODWORD(this->m_pfnThink) = CParticleEffect::GetPMaterial(this: (CParticleEffect *)v16, name: "sprites/flamelet5");
    v17 = (CSimpleEmitter *)MemAlloc_Alloc(nSize: 0x108u);
    v18 = v17;
    if ( v17 != nullptr )
    {
      CSimpleEmitter::CSimpleEmitter(this: v17, pDebugName: "FireTrail_Smoke");
      v18->__vftable = (CParticleEffect_vtbl *)&CSmokeParticle::`vftable';
    }
    else
    {
      v18 = nullptr;
    }
    if ( v18 != (CParticleEffect *)this->m_VarMap.m_Entries.m_Memory.m_nAllocationCount )
    {
      if ( v18 != nullptr )
        CParticleEffect::AddRef(this: v18);
      m_nAllocationCount = (CParticleEffect *)this->m_VarMap.m_Entries.m_Memory.m_nAllocationCount;
      if ( m_nAllocationCount != nullptr )
        CParticleEffect::Release(this: m_nAllocationCount);
      this->m_VarMap.m_Entries.m_Memory.m_nAllocationCount = (int)v18;
    }
    v20 = (CParticleEffect *)this->m_VarMap.m_Entries.m_Memory.m_nAllocationCount;
    v21 = (const Vector *)(*(int (__thiscall **)(char *))(*((_DWORD *)this - 666) + 40))(a1: (char *)this - 2664);
    CParticleEffect::SetSortOrigin(this: v20, vSortOrigin: v21);
    CSimpleEmitter::SetNearClip(
      this: (CSimpleEmitter *)this->m_VarMap.m_Entries.m_Memory.m_nAllocationCount,
      nearClipMin: 64.0,
      nearClipMax: 128.0);
    if ( this->m_VarMap.m_Entries.m_Memory.m_nAllocationCount != 0 )
    {
      v22 = (float *)(*(int (__thiscall **)(char *))(*((_DWORD *)this - 666) + 40))(a1: (char *)this - 2664);
      *((float *)&this->m_pfnThink + 1) = *v22;
      *((float *)&this->m_pfnThink + 2) = v22[1];
      *((float *)&this->m_pfnThink + 3) = v22[2];
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1042AC00
// Name: DT_SmokeTrail::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_SmokeTrail::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_SmokeTrail::g_RecvTable);
  return atexit(func: DT_SmokeTrail::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042AC20
// Name: DT_SmokeTrail::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_SmokeTrail::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_SmokeTrail::ignored>();
  DT_SmokeTrail::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042AC50
// Name: DT_RocketTrail::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_RocketTrail::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_RocketTrail::g_RecvTable);
  return atexit(func: DT_RocketTrail::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042AC70
// Name: DT_RocketTrail::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_RocketTrail::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_RocketTrail::ignored>();
  DT_RocketTrail::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042ACA0
// Name: DT_SporeExplosion::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_SporeExplosion::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_SporeExplosion::g_RecvTable);
  return atexit(func: DT_SporeExplosion::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042ACC0
// Name: DT_SporeExplosion::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_SporeExplosion::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_SporeExplosion::ignored>();
  DT_SporeExplosion::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042AD20
// Name: RPGShotDownPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int RPGShotDownPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106EF254;
  RPGShotDownPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106EF254;
  dword_106EF254 = (int)&RPGShotDownPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042AD60
// Name: DT_SporeTrail::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_SporeTrail::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_SporeTrail::g_RecvTable);
  return atexit(func: DT_SporeTrail::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042AD80
// Name: DT_SporeTrail::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_SporeTrail::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_SporeTrail::ignored>();
  DT_SporeTrail::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042ADB0
// Name: DT_FireTrail::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_FireTrail::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_FireTrail::g_RecvTable);
  return atexit(func: DT_FireTrail::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042ADD0
// Name: DT_FireTrail::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_FireTrail::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_FireTrail::ignored>();
  DT_FireTrail::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042AE00
// Name: DT_DustTrail::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_DustTrail::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_DustTrail::g_RecvTable);
  return atexit(func: DT_DustTrail::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042AE20
// Name: DT_DustTrail::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_DustTrail::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_DustTrail::ignored>();
  DT_DustTrail::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042AE30
// Name: PrecacheEffectDusttrailPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *PrecacheEffectDusttrailPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  PrecacheEffectDusttrailPrecache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &PrecacheEffectDusttrailPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436660
// Name: DT_SmokeTrail::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_SmokeTrail::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_SmokeTrail::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10436670
// Name: DT_RocketTrail::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_RocketTrail::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_RocketTrail::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10436680
// Name: DT_SporeExplosion::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_SporeExplosion::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_SporeExplosion::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x104366A0
// Name: DT_SporeTrail::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_SporeTrail::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_SporeTrail::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x104366B0
// Name: DT_FireTrail::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_FireTrail::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_FireTrail::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x104366C0
// Name: DT_DustTrail::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_DustTrail::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_DustTrail::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x1024E230
// Name: _C_SporeExplosion_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_SporeExplosion_CreateObject(int entnum, int serialNum)
{
  C_SporeExplosion *v2; // eax
  C_SporeExplosion *v3; // eax
  C_SporeExplosion *v4; // esi

  v2 = (C_SporeExplosion *)C_BaseEntity::operator new(stAllocateBlock: 0xAA0u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_SporeExplosion::C_SporeExplosion(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1024E360
// Name: _C_SporeTrail_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_SporeTrail_CreateObject(int entnum, int serialNum)
{
  C_SporeTrail *v2; // eax
  C_SporeTrail *v3; // eax
  C_SporeTrail *v4; // esi

  v2 = (C_SporeTrail *)C_BaseEntity::operator new(stAllocateBlock: 0xB00u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_SporeTrail::C_SporeTrail(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1024F800
// Name: _C_SmokeTrail_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_SmokeTrail_CreateObject(int entnum, int serialNum)
{
  C_SmokeTrail *v2; // eax
  C_SmokeTrail *v3; // eax
  C_SmokeTrail *v4; // esi

  v2 = (C_SmokeTrail *)C_BaseEntity::operator new(stAllocateBlock: 0xAE0u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_SmokeTrail::C_SmokeTrail(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1024F880
// Name: _C_RocketTrail_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_RocketTrail_CreateObject(int entnum, int serialNum)
{
  C_RocketTrail *v2; // eax
  C_RocketTrail *v3; // eax
  C_RocketTrail *v4; // esi

  v2 = (C_RocketTrail *)C_BaseEntity::operator new(stAllocateBlock: 0xAE8u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_RocketTrail::C_RocketTrail(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1024F900
// Name: _C_FireTrail_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_FireTrail_CreateObject(int entnum, int serialNum)
{
  C_FireTrail *v2; // eax
  C_FireTrail *v3; // eax
  C_FireTrail *v4; // esi

  v2 = (C_FireTrail *)C_BaseEntity::operator new(stAllocateBlock: 0xAB8u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_FireTrail::C_FireTrail(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1024FB20
// Name: _C_DustTrail_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_DustTrail_CreateObject(int entnum, int serialNum)
{
  C_DustTrail *v2; // eax
  C_DustTrail *v3; // eax
  C_DustTrail *v4; // esi

  v2 = (C_DustTrail *)C_BaseEntity::operator new(stAllocateBlock: 0xB08u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_DustTrail::C_DustTrail(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1042AC30
// Name: _dynamic_initializer_for____g_C_RocketTrailClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_RocketTrailClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_RocketTrailClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_RocketTrailClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042AC80
// Name: _dynamic_initializer_for____g_C_SporeExplosionClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_SporeExplosionClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_SporeExplosionClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_SporeExplosionClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042ACD0
// Name: _dynamic_initializer_for__cl_sporeclipdistance__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_sporeclipdistance__()
{
  ConVar::ConVar(this: &cl_sporeclipdistance, pName: "cl_sporeclipdistance", pDefaultValue: "512", flags: 16392);
  return atexit(func: dynamic_atexit_destructor_for__cl_sporeclipdistance__);
}

//------------------------------------------------------------------------------
// Address: 0x1042AD00
// Name: _dynamic_initializer_for__ClientEffectReg_RPGShotDownCallback__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CClientEffectRegistration *dynamic_initializer_for__ClientEffectReg_RPGShotDownCallback__()
{
  return CClientEffectRegistration::CClientEffectRegistration(
           this: &ClientEffectReg_RPGShotDownCallback,
           pEffectName: "RPGShotDown",
           fn: RPGShotDownCallback);
}

//------------------------------------------------------------------------------
// Address: 0x1042AD40
// Name: _dynamic_initializer_for____g_C_SporeTrailClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_SporeTrailClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_SporeTrailClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_SporeTrailClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042AD90
// Name: _dynamic_initializer_for____g_C_FireTrailClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_FireTrailClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_FireTrailClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_FireTrailClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042ADE0
// Name: _dynamic_initializer_for____g_C_DustTrailClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_DustTrailClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_DustTrailClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_DustTrailClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042AE50
// Name: _dynamic_initializer_for____g_C_SmokeStackClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_SmokeStackClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_SmokeStackClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_SmokeStackClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436690
// Name: _dynamic_atexit_destructor_for__cl_sporeclipdistance__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_sporeclipdistance__()
{
  ConVar::~ConVar(this: &cl_sporeclipdistance);
}
