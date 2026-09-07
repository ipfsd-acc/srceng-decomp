// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_env_particlescript.cpp
// Functions: 20
// ============================================================

#include "game\client\c_env_particlescript.h"

//------------------------------------------------------------------------------
// Address: 0x10017820
// Name: public: virtual int C_EnvParticleScript::DrawModel(int,struct RenderableInstance_t const __near &)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall C_EnvParticleScript::DrawModel(C_BaseGrenade *this, int pointContents, surfacedata_t *pdata)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10067B80
// Name: public: virtual class ClientClass __near * C_EnvParticleScript::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_EnvParticleScript::GetClientClass(C_EnvParticleScript *this)
{
  return &__g_C_EnvParticleScriptClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10067C20
// Name: private: void C_EnvParticleScript::DestroyAllParticles(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_EnvParticleScript::DestroyAllParticles(C_EnvParticleScript *this, const char *pAttachmentName)
{
  int NumActiveParticles; // edi
  void *v4; // esp
  int ActiveParticleList; // eax
  int i; // ecx
  Particle *v7; // edx
  Particle *v8[3]; // [esp+0h] [ebp-Ch] BYREF
  int nAttachment; // [esp+14h] [ebp+8h]

  nAttachment = this->LookupAttachment(this: &this->IClientRenderable, a2: pAttachmentName);
  if ( nAttachment > 0 )
  {
    NumActiveParticles = CParticleEffectBinding::GetNumActiveParticles(this: &this->m_ParticleEffect);
    v4 = alloca(4 * NumActiveParticles);
    ActiveParticleList = CParticleEffectBinding::GetActiveParticleList(
                           this: &this->m_ParticleEffect,
                           nCount: NumActiveParticles,
                           ppParticleList: v8);
    for ( i = 0; i < ActiveParticleList; ++i )
    {
      v7 = v8[i];
      if ( v7[1].m_pPrev == (Particle *)nAttachment )
        v7[1].m_pPrev = (Particle *)-1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10067CA0
// Name: private: void C_EnvParticleScript::DestroyAllParticles(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_EnvParticleScript::DestroyAllParticles(C_EnvParticleScript *this)
{
  CParticleEffectBinding *p_m_ParticleEffect; // edi
  int NumActiveParticles; // ebx
  void *v3; // esp
  int ActiveParticleList; // eax
  int i; // ecx
  Particle *v6; // edi
  Particle *v7[3]; // [esp+0h] [ebp-Ch] BYREF

  p_m_ParticleEffect = &this->m_ParticleEffect;
  NumActiveParticles = CParticleEffectBinding::GetNumActiveParticles(this: &this->m_ParticleEffect);
  v3 = alloca(4 * NumActiveParticles);
  ActiveParticleList = CParticleEffectBinding::GetActiveParticleList(
                         this: p_m_ParticleEffect,
                         nCount: NumActiveParticles,
                         ppParticleList: v7);
  for ( i = 0; i < ActiveParticleList; v6[1].m_pPrev = (Particle *)-1 )
    v6 = v7[i++];
}

//------------------------------------------------------------------------------
// Address: 0x10067CF0
// Name: public: virtual class Vector const __near & C_EnvParticleScript::GetSortOrigin(void)
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall C_EnvParticleScript::GetSortOrigin(C_EnvParticleScript *this)
{
  return (*(const Vector *(__thiscall **)(char *))(*((_DWORD *)this - 814) + 40))(a1: (char *)this - 3256);
}

//------------------------------------------------------------------------------
// Address: 0x10067D10
// Name: public: C_EnvParticleScript::C_EnvParticleScript(void)
// Source: json
//------------------------------------------------------------------------------
C_EnvParticleScript *__thiscall C_EnvParticleScript::C_EnvParticleScript(C_EnvParticleScript *this)
{
  C_BaseAnimating::C_BaseAnimating(this);
  this->IParticleEffect::__vftable = (IParticleEffect_vtbl *)&IParticleEffect::`vftable';
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_EnvParticleScript_vtbl *)&C_EnvParticleScript::`vftable'{for `IClientUnknown'};
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_EnvParticleScript::`vftable'{for `IClientRenderable'};
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_EnvParticleScript::`vftable'{for `IClientNetworkable'};
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_EnvParticleScript::`vftable'{for `IClientThinkable'};
  this->C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_EnvParticleScript::`vftable'{for `C_BaseAnimating'};
  this->IParticleEffect::__vftable = (IParticleEffect_vtbl *)&C_EnvParticleScript::`vftable'{for `IParticleEffect'};
  CParticleEffectBinding::CParticleEffectBinding(this: &this->m_ParticleEffect);
  this->m_flMaxParticleSize = 0.0;
  this->m_bSimulate = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10067D70
// Name: public: virtual bool C_EnvParticleScript::ShouldSimulate(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_EnvParticleScript::ShouldSimulate(C_EnvParticleScript *this)
{
  return this->m_fEffects;
}

//------------------------------------------------------------------------------
// Address: 0x10067D80
// Name: public: virtual void C_EnvParticleScript::SetShouldSimulate(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_EnvParticleScript::SetShouldSimulate(C_EnvParticleScript *this, bool bSim)
{
  LOBYTE(this->m_fEffects) = bSim;
}

//------------------------------------------------------------------------------
// Address: 0x10067DA0
// Name: public: virtual void C_EnvParticleScript::OnPreDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_EnvParticleScript::OnPreDataChanged(C_EnvParticleScript *this, DataUpdateType_t updateType)
{
  C_BaseAnimating::OnPreDataChanged(this, updateType);
  *(float *)&this->m_ParticleEffect.m_UpdateBBoxCounter = this->m_vecPreRagdollMaxs.z;
}

//------------------------------------------------------------------------------
// Address: 0x10067DC0
// Name: public: virtual void C_EnvParticleScript::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_EnvParticleScript::OnDataChanged(C_EnvParticleScript *this, DataUpdateType_t updateType)
{
  float *p_z; // eax
  CParticleMgr *v4; // eax
  IClientLeafSystem_vtbl *v5; // edi
  unsigned __int16 *v6; // eax
  IParticleEffect *v7; // [esp-4h] [ebp-Ch]

  C_BaseAnimating::OnDataChanged(this, updateType);
  if ( updateType == DATA_UPDATE_CREATED )
  {
    if ( this == (C_EnvParticleScript *)8 )
      p_z = nullptr;
    else
      p_z = &this->m_vecRenderOriginOverride.z;
    v7 = (IParticleEffect *)p_z;
    v4 = ParticleMgr();
    CParticleMgr::AddEffect(
      this: v4,
      pEffect: (CParticleEffectBinding *)(&this->m_vecRenderOriginOverride + 1),
      pSim: v7);
    v5 = g_pClientLeafSystem->IClientLeafSystemEngine::__vftable;
    v6 = (unsigned __int16 *)(*(int (__thiscall **)(char *))(*((_DWORD *)this - 1) + 28))(a1: (char *)this - 4);
    v5->EnableRendering(this: g_pClientLeafSystem, a2: *v6, a3: false);
  }
  if ( *(_DWORD *)&this->m_ParticleEffect.m_UpdateBBoxCounter != LODWORD(this->m_vecPreRagdollMaxs.z) )
    C_EnvParticleScript::DestroyAllParticles(this: (C_EnvParticleScript *)((char *)this - 8));
}

//------------------------------------------------------------------------------
// Address: 0x10067E40
// Name: private: void C_EnvParticleScript::CreateParticle(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_EnvParticleScript::CreateParticle(
        C_EnvParticleScript *this,
        const char *pAttachmentName,
        IMaterialVar *pSpriteName)
{
  CParticleSubTexture *v4; // ebx
  Particle *v5; // esi
  CParticleMgr *v6; // eax
  IMaterial *v7; // eax
  IMaterialVar *v8; // eax
  float flMaxParticleRadius; // xmm0_4
  int v10; // eax
  Vector *p_m_Pos; // esi
  const Vector *v12; // eax
  float m_flSequenceScale; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  const Vector *v16; // eax
  QAngle vecAngles; // [esp+14h] [ebp-10h] BYREF
  int nAttachment; // [esp+20h] [ebp-4h]

  nAttachment = this->LookupAttachment(this: &this->IClientRenderable, a2: pAttachmentName);
  if ( nAttachment > 0 )
  {
    v4 = CParticleEffectBinding::FindOrAddMaterial(
           this: &this->m_ParticleEffect,
           pMaterialName: (const char *)pSpriteName);
    v5 = CParticleEffectBinding::AddParticle(this: &this->m_ParticleEffect, sizeInBytes: 32, hMaterial: v4);
    if ( v5 != nullptr )
    {
      HIBYTE(pAttachmentName) = 0;
      pSpriteName = nullptr;
      v6 = ParticleMgr();
      v7 = CParticleMgr::PMaterialToIMaterial(this: v6, hMaterial: v4);
      if ( v7 != nullptr )
        v8 = v7->FindVar(this: v7, a2: "$spritesize", a3: (bool *)&pAttachmentName + 3, a4: false);
      else
        v8 = pSpriteName;
      if ( HIBYTE(pAttachmentName) != 0 )
        *(float *)&v5[1].m_pNext = v8->GetFloatValueInternal(this: v8);
      else
        v5[1].m_pNext = (Particle *)1120403456;
      flMaxParticleRadius = *(float *)&v5[1].m_pNext;
      if ( flMaxParticleRadius > this->m_flMaxParticleSize )
      {
        this->m_flMaxParticleSize = flMaxParticleRadius;
        CParticleEffectBinding::SetParticleCullRadius(this: &this->m_ParticleEffect, flMaxParticleRadius);
      }
      v10 = nAttachment;
      v5[1].m_pPrev = (Particle *)nAttachment;
      p_m_Pos = &v5->m_Pos;
      this->GetAttachment_2(this: &this->IClientRenderable, a2: v10, a3: p_m_Pos, a4: &vecAngles);
      if ( this->m_flSequenceScale != 1.0 )
      {
        v12 = this->GetAbsOrigin(this);
        p_m_Pos->x = p_m_Pos->x - v12->x;
        p_m_Pos->y = p_m_Pos->y - v12->y;
        p_m_Pos->z = p_m_Pos->z - v12->z;
        m_flSequenceScale = this->m_flSequenceScale;
        p_m_Pos->x = p_m_Pos->x * m_flSequenceScale;
        v14 = m_flSequenceScale * p_m_Pos->y;
        v15 = m_flSequenceScale * p_m_Pos->z;
        p_m_Pos->y = v14;
        p_m_Pos->z = v15;
        v16 = this->GetAbsOrigin(this);
        p_m_Pos->x = p_m_Pos->x + v16->x;
        p_m_Pos->y = v16->y + p_m_Pos->y;
        p_m_Pos->z = v16->z + p_m_Pos->z;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10067FE0
// Name: public: virtual void C_EnvParticleScript::FireEvent(class Vector const __near &,class QAngle const __near &,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_EnvParticleScript::FireEvent(
        C_EnvParticleScript *this,
        const Vector *origin,
        const QAngle *angles,
        int event,
        const char *options)
{
  char pAttachmentName[256]; // [esp+4h] [ebp-200h] BYREF
  char pSpriteName[256]; // [esp+104h] [ebp-100h] BYREF

  if ( event == 6002 )
  {
    if ( sscanf(string: options, format: "%255s %255s", pAttachmentName, pSpriteName) == 2 )
      C_EnvParticleScript::CreateParticle(this, pAttachmentName, (IMaterialVar *)pSpriteName);
  }
  else if ( event == 6003 )
  {
    if ( sscanf(string: options, format: "%255s", pSpriteName) == 1 )
      C_EnvParticleScript::DestroyAllParticles(this, pAttachmentName: pSpriteName);
  }
  else
  {
    C_BaseAnimating::FireEvent(this, origin, angles, event, options);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10068090
// Name: public: virtual void C_EnvParticleScript::SimulateParticles(class CParticleSimulateIterator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_EnvParticleScript::SimulateParticles(C_EnvParticleScript *this, CParticleSimulateIterator *pIterator)
{
  CParticleSimulateIterator *v2; // edi
  CEffectMaterial *m_pMaterial; // eax
  Particle *m_pNext; // esi
  Particle *m_pPrev; // eax
  float *p_x; // esi
  float *v8; // eax
  float v9; // xmm0_4
  float *v10; // eax
  QAngle vecAngles; // [esp+Ch] [ebp-Ch] BYREF

  v2 = pIterator;
  m_pMaterial = pIterator->m_pMaterial;
  m_pNext = m_pMaterial->m_Particles.m_pNext;
  if ( m_pNext != &m_pMaterial->m_Particles )
  {
    pIterator->m_pNextParticle = m_pNext->m_pNext;
    while ( 1 )
    {
      m_pPrev = m_pNext[1].m_pPrev;
      if ( m_pPrev == (Particle *)-1 )
      {
        CParticleEffectBinding::RemoveParticle(this: v2->m_pEffectBinding, pParticle: m_pNext);
      }
      else
      {
        p_x = &m_pNext->m_Pos.x;
        (*(void (__thiscall **)(char *, Particle *, float *, QAngle *))(*((_DWORD *)this - 813) + 140))(
          a1: (char *)this - 3252,
          a2: m_pPrev,
          a3: p_x,
          a4: &vecAngles);
        if ( *(float *)&this->m_nWaterType != 1.0 )
        {
          v8 = (float *)(*(int (__thiscall **)(char *))(*((_DWORD *)this - 814) + 40))(a1: (char *)this - 3256);
          *p_x = *p_x - *v8;
          p_x[1] = p_x[1] - v8[1];
          p_x[2] = p_x[2] - v8[2];
          v9 = *(float *)&this->m_nWaterType;
          *p_x = v9 * *p_x;
          p_x[1] = p_x[1] * v9;
          p_x[2] = p_x[2] * v9;
          v10 = (float *)(*(int (__thiscall **)(char *))(*((_DWORD *)this - 814) + 40))(a1: (char *)this - 3256);
          *p_x = *v10 + *p_x;
          p_x[1] = v10[1] + p_x[1];
          p_x[2] = v10[2] + p_x[2];
        }
        v2 = pIterator;
      }
      m_pNext = v2->m_pNextParticle;
      if ( m_pNext == &v2->m_pMaterial->m_Particles )
        break;
      v2->m_pNextParticle = m_pNext->m_pNext;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100681D0
// Name: class IParticleEffect __near * C_EnvParticleScript_Factory(void)
// Source: json
//------------------------------------------------------------------------------
IParticleEffect *__cdecl C_EnvParticleScript_Factory()
{
  C_EnvParticleScript *v0; // eax
  C_EnvParticleScript *v1; // eax

  v0 = (C_EnvParticleScript *)C_BaseEntity::operator new(stAllocateBlock: 0xDA8u);
  if ( v0 != nullptr && (v1 = C_EnvParticleScript::C_EnvParticleScript(this: v0)) != nullptr )
    return &v1->IParticleEffect;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10068290
// Name: public: virtual void C_EnvParticleScript::RenderParticles(class CParticleRenderIterator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_EnvParticleScript::RenderParticles(C_EnvParticleScript *this, CParticleRenderIterator *pIterator)
{
  CEffectMaterial *m_pMaterial; // ecx
  Particle *m_pNext; // eax
  Particle *m_pCur; // esi
  CParticleMgr *v5; // eax
  float y; // xmm1_4
  float x; // xmm2_4
  float z; // xmm3_4
  ParticleDraw *m_pParticleDraw; // edx
  float v10; // xmm4_4
  Vector color; // [esp+10h] [ebp-18h] BYREF
  Vector vecRenderPos; // [esp+1Ch] [ebp-Ch] BYREF

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
        v5 = ParticleMgr();
        y = m_pCur->m_Pos.y;
        x = m_pCur->m_Pos.x;
        z = m_pCur->m_Pos.z;
        m_pParticleDraw = pIterator->m_pParticleDraw;
        v10 = v5->m_mModelView.m[1][1];
        vecRenderPos.x = (float)((float)((float)(v5->m_mModelView.m[0][1] * y) + (float)(v5->m_mModelView.m[0][0] * x))
                               + (float)(v5->m_mModelView.m[0][2] * z))
                       + v5->m_mModelView.m[0][3];
        vecRenderPos.y = (float)((float)((float)(v5->m_mModelView.m[1][0] * x) + (float)(v10 * y))
                               + (float)(v5->m_mModelView.m[1][2] * z))
                       + v5->m_mModelView.m[1][3];
        vecRenderPos.z = (float)((float)((float)(v5->m_mModelView.m[2][0] * x) + (float)(v5->m_mModelView.m[2][1] * y))
                               + (float)(v5->m_mModelView.m[2][2] * z))
                       + v5->m_mModelView.m[2][3];
        RenderParticle_ColorSize(
          pDraw: m_pParticleDraw,
          pos: &vecRenderPos,
          &color,
          alpha: 1.0,
          size: *(const float *)&m_pCur[1].m_pNext);
        m_pCur = (Particle *)CParticleRenderIterator::GetNext(this: pIterator, sortKey: vecRenderPos.z);
      }
      while ( m_pCur != nullptr );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10411CE0
// Name: DT_EnvParticleScript::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_EnvParticleScript::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_EnvParticleScript::g_RecvTable);
  return atexit(func: DT_EnvParticleScript::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10411D00
// Name: DT_EnvParticleScript::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_EnvParticleScript::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_EnvParticleScript::ignored>();
  DT_EnvParticleScript::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430210
// Name: DT_EnvParticleScript::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_EnvParticleScript::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_EnvParticleScript::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10068200
// Name: _C_EnvParticleScript_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_EnvParticleScript_CreateObject(int entnum, int serialNum)
{
  C_EnvParticleScript *v2; // eax
  C_EnvParticleScript *v3; // eax
  C_EnvParticleScript *v4; // esi

  v2 = (C_EnvParticleScript *)C_BaseEntity::operator new(stAllocateBlock: 0xDA8u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_EnvParticleScript::C_EnvParticleScript(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x10411D10
// Name: _dynamic_initializer_for____g_C_EnvProjectedTextureClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_EnvProjectedTextureClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_EnvProjectedTextureClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_EnvProjectedTextureClientClass;
  return result;
}
