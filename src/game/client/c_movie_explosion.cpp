// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_movie_explosion.cpp
// Functions: 12
// ============================================================

#include "game\client\c_movie_explosion.h"

//------------------------------------------------------------------------------
// Address: 0x10245AC0
// Name: public: virtual class ClientClass __near * C_MovieExplosion::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_MovieExplosion::GetClientClass(C_MovieExplosion *this)
{
  return &__g_C_MovieExplosionClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10245B40
// Name: public: virtual C_MovieExplosion::~C_MovieExplosion(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_MovieExplosion::~C_MovieExplosion(C_MovieExplosion *this)
{
  CParticleMgr *m_pParticleMgr; // ecx

  m_pParticleMgr = this->m_pParticleMgr;
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_MovieExplosion_vtbl *)&C_MovieExplosion::`vftable'{for `IClientUnknown'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_MovieExplosion::`vftable'{for `IClientRenderable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_MovieExplosion::`vftable'{for `IClientNetworkable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_MovieExplosion::`vftable'{for `IClientThinkable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_MovieExplosion::`vftable'{for `C_BaseEntity'};
  this->C_BaseParticleEntity::IParticleEffect::__vftable = (IParticleEffect_vtbl *)&C_MovieExplosion::`vftable'{for `IParticleEffect'};
  this->IPrototypeAppEffect::__vftable = (IPrototypeAppEffect_vtbl *)&C_MovieExplosion::`vftable';
  if ( m_pParticleMgr != nullptr )
    CParticleMgr::RemoveEffect(this: m_pParticleMgr, pEffect: &this->m_ParticleEffect);
  this->IPrototypeAppEffect::__vftable = (IPrototypeAppEffect_vtbl *)&IPrototypeAppEffect::`vftable';
  C_BaseParticleEntity::~C_BaseParticleEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x10245C00
// Name: public: virtual void C_MovieExplosion::Start(class CParticleMgr __near *,class IPrototypeArgAccess __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall C_MovieExplosion::Start(C_MovieExplosion *this, CParticleMgr *pParticleMgr, IPrototypeArgAccess *pArgs)
{
  IParticleEffect *v4; // eax
  IUniformRandomStream *v5; // ecx
  HSCRIPT__ **p_m_hScriptInstance; // esi
  IUniformRandomStream *v7; // ecx
  IUniformRandomStream *v8; // ecx
  float *v9; // eax
  bool v10; // zf
  float v11; // [esp+14h] [ebp-10h]
  float v12; // [esp+18h] [ebp-Ch]
  float v13; // [esp+1Ch] [ebp-8h]
  int v14; // [esp+20h] [ebp-4h]

  if ( this == (C_MovieExplosion *)2664 )
    v4 = nullptr;
  else
    v4 = (IParticleEffect *)((char *)this - 232);
  if ( CParticleMgr::AddEffect(this: pParticleMgr, pEffect: (CParticleEffectBinding *)((char *)this - 228), pSim: v4) != 0 )
  {
    p_m_hScriptInstance = &this->m_hScriptInstance;
    v14 = 50;
    do
    {
      v11 = _RandomFloat(this: v5, a2: -1.0, a3: 1.0);
      v12 = _RandomFloat(this: v7, a2: -1.0, a3: 1.0);
      v13 = _RandomFloat(this: v8, a2: -1.0, a3: 1.0);
      *((float *)p_m_hScriptInstance - 2) = v11 * 200.0;
      *((float *)p_m_hScriptInstance - 1) = v12 * 200.0;
      *(float *)p_m_hScriptInstance = v13 * 200.0;
      v9 = (float *)(*(int (__thiscall **)(char *, _DWORD))(*((_DWORD *)this - 666) + 40))(
                      a1: (char *)this - 2664,
                      a2: LODWORD(v13));
      *(p_m_hScriptInstance - 5) = *(HSCRIPT__ **)v9;
      *(p_m_hScriptInstance - 4) = *((HSCRIPT__ **)v9 + 1);
      p_m_hScriptInstance += 9;
      v10 = v14-- == 1;
      *(p_m_hScriptInstance - 12) = *((HSCRIPT__ **)v9 + 2);
      *(p_m_hScriptInstance - 8) = nullptr;
      *(p_m_hScriptInstance - 7) = (HSCRIPT__ *)1032358025;
      *(p_m_hScriptInstance - 6) = nullptr;
    }
    while ( !v10 );
    this->m_pIntermediateData_FirstPredicted[19] = nullptr;
    this->m_pIntermediateData_FirstPredicted[21] = (unsigned __int8 *)CParticleEffectBinding::FindOrAddMaterial(
                                                                        this: (CParticleEffectBinding *)((char *)this - 228),
                                                                        pMaterialName: "particle/particle_sphere");
    this->m_pIntermediateData_FirstPredicted[20] = (unsigned __int8 *)pParticleMgr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10245D60
// Name: public: virtual void C_MovieExplosion::Update(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_MovieExplosion::Update(C_MovieExplosion *this, unsigned int fTimeDelta)
{
  __m128 v3; // xmm0
  double v4; // xmm0_8
  Vector *p_m_vecViewOffset; // esi
  float v6; // xmm3_4
  float v7; // xmm1_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float j; // xmm0_4
  float y; // xmm1_4
  Particle *v12; // eax
  IUniformRandomStream *v13; // ecx
  float *v14; // edi
  IUniformRandomStream *v15; // ecx
  IUniformRandomStream *v16; // ecx
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // [esp+14h] [ebp-14h]
  float v20; // [esp+18h] [ebp-10h]
  float v21; // [esp+1Ch] [ebp-Ch]
  int i; // [esp+20h] [ebp-8h]
  float tempDelta; // [esp+24h] [ebp-4h]

  if ( this->m_pIntermediateData_FirstPredicted[78] != nullptr )
  {
    v3 = (__m128)fTimeDelta;
    v3.m128_f32[0] = *(float *)&fTimeDelta + *(float *)&this->m_pIntermediateData_FirstPredicted[77];
    this->m_pIntermediateData_FirstPredicted[77] = (unsigned __int8 *)v3.m128_i32[0];
    if ( v3.m128_f32[0] <= 3.0 )
    {
      v3.m128_f32[0] = (float)(v3.m128_f32[0] * 3.1415901) * 0.33333334;
      __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd(v3));
      *(float *)&v4 = v4;
      this->m_pIntermediateData_FirstPredicted[80] = (unsigned __int8 *)LODWORD(v4);
      p_m_vecViewOffset = &this->m_vecViewOffset;
      for ( i = 50; i != 0; --i )
      {
        v6 = p_m_vecViewOffset[-2].z + (float)(*(float *)&fTimeDelta * p_m_vecViewOffset[-1].z);
        v7 = p_m_vecViewOffset[-1].y + (float)(p_m_vecViewOffset->y * *(float *)&fTimeDelta);
        p_m_vecViewOffset[-1].x = (float)(*(float *)&fTimeDelta * p_m_vecViewOffset->x) + p_m_vecViewOffset[-1].x;
        p_m_vecViewOffset[-1].y = v7;
        p_m_vecViewOffset[-2].z = v6;
        v8 = p_m_vecViewOffset->x * 0.89999998;
        v9 = p_m_vecViewOffset->y * 0.89999998;
        p_m_vecViewOffset[-1].z = p_m_vecViewOffset[-1].z * 0.89999998;
        p_m_vecViewOffset->x = v8;
        p_m_vecViewOffset->y = v9;
        for ( j = *(float *)&fTimeDelta; ; j = tempDelta )
        {
          y = p_m_vecViewOffset[1].y;
          if ( j < y )
            break;
          p_m_vecViewOffset[1].y = p_m_vecViewOffset[1].x;
          tempDelta = j - y;
          v12 = CParticleEffectBinding::AddParticle(
                  this: (CParticleEffectBinding *)&this->IClientRenderable,
                  a2: (int)p_m_vecViewOffset,
                  sizeInBytes: 48,
                  hMaterial: (CParticleSubTexture *)this->m_pIntermediateData_FirstPredicted[79]);
          v14 = (float *)v12;
          if ( v12 != nullptr )
          {
            v12->m_Pos.x = p_m_vecViewOffset[-2].z;
            v12->m_Pos.y = p_m_vecViewOffset[-1].x;
            v12->m_Pos.z = p_m_vecViewOffset[-1].y;
            _RandomFloat(this: v13, a2: -20.0, a3: 20.0);
            v20 = _RandomFloat(this: v15, a2: -20.0, a3: 20.0);
            v21 = _RandomFloat(this: v16, a2: -20.0, a3: 20.0);
            v17 = (float)(p_m_vecViewOffset->x * 0.2) + v20;
            v18 = (float)(p_m_vecViewOffset->y * 0.2) + v21;
            v14[6] = (float)(p_m_vecViewOffset[-1].z * 0.2) + v19;
            v14[7] = v17;
            v14[8] = v18;
          }
        }
        p_m_vecViewOffset[1].y = p_m_vecViewOffset[1].y - j;
        p_m_vecViewOffset += 3;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10245F80
// Name: public: virtual void C_MovieExplosion::SimulateParticles(class CParticleSimulateIterator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_MovieExplosion::SimulateParticles(C_MovieExplosion *this, CParticleSimulateIterator *pIterator)
{
  CEffectMaterial *m_pMaterial; // ecx
  Particle *m_pNext; // eax
  bool i; // zf
  float m_flTimeDelta; // xmm0_4
  float v6; // xmm0_4
  float v7; // xmm2_4
  float v8; // xmm0_4
  float v9; // xmm1_4

  m_pMaterial = pIterator->m_pMaterial;
  m_pNext = m_pMaterial->m_Particles.m_pNext;
  for ( i = m_pNext == &m_pMaterial->m_Particles; !i; i = m_pNext == &pIterator->m_pMaterial->m_Particles )
  {
    m_flTimeDelta = pIterator->m_flTimeDelta;
    pIterator->m_pNextParticle = m_pNext->m_pNext;
    v6 = m_flTimeDelta + m_pNext[1].m_Pos.x;
    m_pNext[1].m_Pos.x = v6;
    if ( v6 <= 1.0 )
    {
      v7 = pIterator->m_flTimeDelta;
      v8 = (float)(*(float *)&m_pNext[1].m_pNext * v7) + m_pNext->m_Pos.y;
      v9 = (float)(*(float *)&m_pNext[1].m_pSubTexture * v7) + m_pNext->m_Pos.z;
      m_pNext->m_Pos.x = m_pNext->m_Pos.x + (float)(v7 * *(float *)&m_pNext[1].m_pPrev);
      m_pNext->m_Pos.y = v8;
      m_pNext->m_Pos.z = v9;
    }
    else
    {
      CParticleEffectBinding::RemoveParticle(this: pIterator->m_pEffectBinding, pParticle: m_pNext);
    }
    m_pNext = pIterator->m_pNextParticle;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10246030
// Name: public: C_MovieExplosion::C_MovieExplosion(void)
// Source: json
//------------------------------------------------------------------------------
C_MovieExplosion *__thiscall C_MovieExplosion::C_MovieExplosion(C_MovieExplosion *this)
{
  int v2; // ecx
  TimedEvent *p_m_ParticleSpawn; // eax

  C_BaseParticleEntity::C_BaseParticleEntity(this);
  this->IPrototypeAppEffect::__vftable = (IPrototypeAppEffect_vtbl *)&IPrototypeAppEffect::`vftable';
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_MovieExplosion_vtbl *)&C_MovieExplosion::`vftable'{for `IClientUnknown'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_MovieExplosion::`vftable'{for `IClientRenderable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_MovieExplosion::`vftable'{for `IClientNetworkable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_MovieExplosion::`vftable'{for `IClientThinkable'};
  this->C_BaseParticleEntity::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_MovieExplosion::`vftable'{for `C_BaseEntity'};
  this->C_BaseParticleEntity::IParticleEffect::__vftable = (IParticleEffect_vtbl *)&C_MovieExplosion::`vftable'{for `IParticleEffect'};
  this->IPrototypeAppEffect::__vftable = (IPrototypeAppEffect_vtbl *)&C_MovieExplosion::`vftable';
  v2 = 49;
  p_m_ParticleSpawn = &this->m_Emitters[0].m_ParticleSpawn;
  do
  {
    p_m_ParticleSpawn->m_TimeBetweenEvents = -1.0;
    p_m_ParticleSpawn->m_fNextEvent = 0.0;
    p_m_ParticleSpawn = (TimedEvent *)((char *)p_m_ParticleSpawn + 36);
    --v2;
  }
  while ( v2 >= 0 );
  this->m_pParticleMgr = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102460B0
// Name: public: virtual void C_MovieExplosion::RenderParticles(class CParticleRenderIterator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_MovieExplosion::RenderParticles(C_MovieExplosion *this, CParticleRenderIterator *pIterator)
{
  CEffectMaterial *m_pMaterial; // ecx
  Particle *m_pNext; // eax
  Particle *m_pCur; // eax
  float *v6; // ecx
  float x; // xmm2_4
  float y; // xmm1_4
  float z; // xmm3_4
  float v10; // xmm4_4
  __m128i v11; // xmm0
  ParticleDraw *m_pParticleDraw; // edx
  double v13; // xmm0_8
  float v14; // xmm1_4
  float alpha; // [esp+0h] [ebp-28h]
  Vector color; // [esp+10h] [ebp-18h] BYREF
  Vector tPos; // [esp+1Ch] [ebp-Ch] BYREF

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
      color.z = 0.0;
      do
      {
        v6 = (float *)this->m_pIntermediateData_FirstPredicted[78];
        x = m_pCur->m_Pos.x;
        y = m_pCur->m_Pos.y;
        z = m_pCur->m_Pos.z;
        v10 = v6[30];
        tPos.x = (float)((float)((float)(v6[26] * y) + (float)(x * v6[25])) + (float)(v6[27] * z)) + v6[28];
        tPos.y = (float)((float)((float)(v6[29] * x) + (float)(v10 * y)) + (float)(v6[31] * z)) + v6[32];
        tPos.z = (float)((float)((float)(v6[33] * x) + (float)(v6[34] * y)) + (float)(v6[35] * z)) + v6[36];
        v11 = (__m128i)_mm_cvtps_pd((__m128)LODWORD(m_pCur[1].m_Pos.x));
        *(double *)v11.m128i_i64 = *(double *)v11.m128i_i64 * 3.14159;
        __libm_sse2_sin(X: v11);
        m_pParticleDraw = pIterator->m_pParticleDraw;
        v14 = v13;
        color.x = v14;
        color.y = v14 * 0.5;
        alpha = *(float *)&this->m_pIntermediateData_FirstPredicted[80] * v13;
        RenderParticle_ColorSize(pDraw: m_pParticleDraw, pos: &tPos, &color, alpha, size: 10.0);
        m_pCur = (Particle *)CParticleRenderIterator::GetNext(this: pIterator, sortKey: tPos.z);
      }
      while ( m_pCur != nullptr );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1042AA60
// Name: DT_MovieExplosion::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_MovieExplosion::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_MovieExplosion::g_RecvTable);
  return atexit(func: DT_MovieExplosion::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042AA80
// Name: DT_MovieExplosion::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_MovieExplosion::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_MovieExplosion::ignored>();
  DT_MovieExplosion::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104365F0
// Name: DT_MovieExplosion::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_MovieExplosion::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_MovieExplosion::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10246240
// Name: _C_MovieExplosion_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_MovieExplosion_CreateObject(int entnum, int serialNum)
{
  C_MovieExplosion *v2; // eax
  C_MovieExplosion *v3; // eax
  C_MovieExplosion *v4; // esi

  v2 = (C_MovieExplosion *)C_BaseEntity::operator new(stAllocateBlock: 0x1188u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_MovieExplosion::C_MovieExplosion(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1042AA90
// Name: _dynamic_initializer_for____g_C_ParticleFireClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_ParticleFireClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_ParticleFireClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_ParticleFireClientClass;
  return result;
}
