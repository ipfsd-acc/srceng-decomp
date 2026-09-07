// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_te_particlesystem.cpp
// Functions: 12
// ============================================================

#include "game\client\c_te_particlesystem.h"

//------------------------------------------------------------------------------
// Address: 0x102631C0
// Name: public: virtual class ClientClass __near * C_TEParticleSystem::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_TEParticleSystem::GetClientClass(C_TEParticleSystem *this)
{
  return &__g_C_TEParticleSystemClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x102631D0
// Name: public: struct StandardParticle_t __near * CTEParticleRenderer::AddParticle(void)
// Source: json
//------------------------------------------------------------------------------
StandardParticle_t *__thiscall CTEParticleRenderer::AddParticle(CTEParticleRenderer *this)
{
  StandardParticle_t *result; // eax

  if ( this->m_MaterialHandle == nullptr )
    this->m_MaterialHandle = CParticleEffectBinding::FindOrAddMaterial(
                               this: &this->m_ParticleEffect,
                               pMaterialName: "particle/particledefault");
  result = (StandardParticle_t *)CParticleEffect::AddParticle(
                                   this,
                                   particleSize: 0x30u,
                                   material: this->m_MaterialHandle,
                                   origin: &this->m_vSortOrigin);
  if ( result != nullptr )
    result->m_EffectDataWord = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102632E0
// Name: public: C_TEParticleSystem::C_TEParticleSystem(void)
// Source: json
//------------------------------------------------------------------------------
C_TEParticleSystem *__thiscall C_TEParticleSystem::C_TEParticleSystem(C_TEParticleSystem *this)
{
  C_BaseTempEntity::C_BaseTempEntity(this);
  this->C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEParticleSystem_vtbl *)&C_TEParticleSystem::`vftable'{for `IClientUnknown'};
  this->C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEParticleSystem::`vftable'{for `IClientNetworkable'};
  this->m_vecOrigin.x = 0.0;
  this->m_vecOrigin.y = 0.0;
  this->m_vecOrigin.z = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10263340
// Name: public: virtual void CTEParticleRenderer::SimulateParticles(class CParticleSimulateIterator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTEParticleRenderer::SimulateParticles(CTEParticleRenderer *this, CParticleSimulateIterator *pIterator)
{
  CEffectMaterial *m_pMaterial; // eax
  Particle *m_pNext; // esi
  float v4; // xmm0_4
  float m_flTimeDelta; // xmm0_4
  float v6; // xmm3_4
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm5_4
  unsigned int v10; // eax
  unsigned int v11; // eax
  float v12; // xmm2_4
  float v13; // xmm3_4
  unsigned int v14; // eax
  unsigned int v15; // eax
  int v16; // ecx
  int v17; // edx
  int v18; // eax
  Particle *v19; // xmm2_4
  Particle *v20; // xmm3_4
  float v21; // xmm4_4
  float v22; // xmm5_4
  unsigned int v23; // eax
  unsigned int v24; // eax
  float v25; // xmm3_4
  int v26; // edx
  int v27; // eax
  float v28; // xmm4_4
  float v29; // xmm3_4
  unsigned int v30; // eax
  unsigned int v31; // eax
  __m128i v32; // xmm2
  __m128i v33; // xmm4
  float v34; // xmm1_4
  float v35; // xmm2_4

  m_pMaterial = pIterator->m_pMaterial;
  m_pNext = m_pMaterial->m_Particles.m_pNext;
  if ( m_pNext != &m_pMaterial->m_Particles )
  {
    for ( pIterator->m_pNextParticle = m_pNext->m_pNext; ; pIterator->m_pNextParticle = m_pNext->m_pNext )
    {
      v4 = m_pNext[1].m_Pos.x - pIterator->m_flTimeDelta;
      m_pNext[1].m_Pos.x = v4;
      if ( v4 >= 0.0 )
      {
        m_flTimeDelta = pIterator->m_flTimeDelta;
        v7 = m_flTimeDelta * 10.0;
        v8 = (float)(sv_gravity.m_pParent->m_Value.m_fValue * m_flTimeDelta) * 0.050000001;
        v9 = m_flTimeDelta * 4.0;
        switch ( LOBYTE(m_pNext[1].m_Pos.y) )
        {
          case 1:
            *(float *)&m_pNext[1].m_pSubTexture = *(float *)&m_pNext[1].m_pSubTexture - (float)(v8 * 20.0);
            break;
          case 2:
            *(float *)&m_pNext[1].m_pSubTexture = v8;
            break;
          case 3:
            HIWORD(m_pNext[1].m_Pos.y) += (int)(float)((float)(m_flTimeDelta * 5.0) * 1024.0);
            v10 = HIWORD(m_pNext[1].m_Pos.y) >> 10;
            if ( v10 < 6 )
            {
              v11 = 3 * v10;
              v12 = (float)dword_105B8854[v11];
              v13 = (float)dword_105B8858[v11];
              LOBYTE(m_pNext[1].m_Pos.z) = (int)(float)((float)((float)ramp3[v11 / 3][0] * 0.0039215689) * 255.89999);
              BYTE1(m_pNext[1].m_Pos.z) = (int)(float)((float)(v12 * 0.0039215689) * 255.89999);
              BYTE2(m_pNext[1].m_Pos.z) = (int)(float)((float)(v13 * 0.0039215689) * 255.89999);
            }
            else
            {
              m_pNext[1].m_Pos.x = -1.0;
            }
            *(float *)&m_pNext[1].m_pSubTexture = *(float *)&m_pNext[1].m_pSubTexture + v8;
            break;
          case 4:
            HIWORD(m_pNext[1].m_Pos.y) += (int)(float)(v7 * 1024.0);
            v14 = HIWORD(m_pNext[1].m_Pos.y) >> 10;
            if ( v14 < 8 )
            {
              v15 = 3 * v14;
              v16 = (int)(float)((float)((float)ramp1[v15 / 3][0] * 0.0039215689) * 255.89999);
              v17 = (int)(float)((float)((float)dword_105B8794[v15] * 0.0039215689) * 255.89999);
              v18 = (int)(float)((float)((float)dword_105B8798[v15] * 0.0039215689) * 255.89999);
              LOBYTE(m_pNext[1].m_Pos.z) = v16;
              BYTE1(m_pNext[1].m_Pos.z) = v17;
              BYTE2(m_pNext[1].m_Pos.z) = v18;
            }
            else
            {
              m_pNext[1].m_Pos.x = -1.0;
            }
            *(float *)&v19 = (float)(*(float *)&m_pNext[1].m_pPrev * v9) + *(float *)&m_pNext[1].m_pPrev;
            *(float *)&v20 = (float)(*(float *)&m_pNext[1].m_pNext * v9) + *(float *)&m_pNext[1].m_pNext;
            v21 = *(float *)&m_pNext[1].m_pSubTexture * v9;
            v22 = *(float *)&m_pNext[1].m_pSubTexture;
            m_pNext[1].m_pPrev = v19;
            m_pNext[1].m_pNext = v20;
            *(float *)&m_pNext[1].m_pSubTexture = (float)(v21 + v22) - v8;
            break;
          case 5:
            v6 = m_flTimeDelta * 15.0;
            HIWORD(m_pNext[1].m_Pos.y) += (int)(float)(v6 * 1024.0);
            v23 = HIWORD(m_pNext[1].m_Pos.y) >> 10;
            if ( v23 < 8 )
            {
              v24 = 3 * v23;
              v25 = (float)((float)dword_105B87F8[v24] * 0.0039215689) * 255.89999;
              v26 = (int)(float)((float)((float)ramp2[v24 / 3][0] * 0.0039215689) * 255.89999);
              v27 = (int)(float)((float)((float)dword_105B87F4[v24] * 0.0039215689) * 255.89999);
              LOBYTE(m_pNext[1].m_Pos.z) = v26;
              BYTE1(m_pNext[1].m_Pos.z) = v27;
              BYTE2(m_pNext[1].m_Pos.z) = (int)v25;
            }
            else
            {
              m_pNext[1].m_Pos.x = -1.0;
            }
            v28 = *(float *)&m_pNext[1].m_pSubTexture;
            v29 = *(float *)&m_pNext[1].m_pNext;
            *(float *)&m_pNext[1].m_pPrev = *(float *)&m_pNext[1].m_pPrev
                                          - (float)(*(float *)&m_pNext[1].m_pPrev * m_flTimeDelta);
            *(float *)&m_pNext[1].m_pNext = v29 - (float)(v29 * m_flTimeDelta);
            *(float *)&m_pNext[1].m_pSubTexture = (float)(v28 - (float)(v28 * m_flTimeDelta)) - v8;
            break;
          case 6:
          case 7:
            HIWORD(m_pNext[1].m_Pos.y) += (int)(float)(v7 * 1024.0);
            v30 = HIWORD(m_pNext[1].m_Pos.y) >> 10;
            if ( v30 >= 9 )
            {
              v30 = 0;
              HIWORD(m_pNext[1].m_Pos.y) = 0;
            }
            v31 = 3 * v30;
            v32 = _mm_cvtsi32_si128(dword_105B889C[v31]);
            v33 = _mm_cvtsi32_si128(gSparkRamp[v31 / 3][0]);
            BYTE2(m_pNext[1].m_Pos.z) = (int)(float)((float)((float)dword_105B88A0[v31] * 0.0039215689) * 255.89999);
            LOBYTE(m_pNext[1].m_Pos.z) = (int)(float)((float)(_mm_cvtepi32_ps(v33).m128_f32[0] * 0.0039215689)
                                                    * 255.89999);
            BYTE1(m_pNext[1].m_Pos.z) = (int)(float)((float)(_mm_cvtepi32_ps(v32).m128_f32[0] * 0.0039215689) * 255.89999);
            *(float *)&m_pNext[1].m_pPrev = *(float *)&m_pNext[1].m_pPrev
                                          - (float)((float)(*(float *)&m_pNext[1].m_pPrev * 0.5) * m_flTimeDelta);
            *(float *)&m_pNext[1].m_pNext = *(float *)&m_pNext[1].m_pNext
                                          - (float)((float)(*(float *)&m_pNext[1].m_pNext * 0.5) * m_flTimeDelta);
            *(float *)&m_pNext[1].m_pSubTexture = *(float *)&m_pNext[1].m_pSubTexture - (float)(v8 * 5.0);
            if ( random->RandomInt(this: random, a2: 0, a3: 3) != 0 )
            {
              LOBYTE(m_pNext[1].m_Pos.y) = 6;
              HIBYTE(m_pNext[1].m_Pos.z) = 0;
            }
            else
            {
              LOBYTE(m_pNext[1].m_Pos.y) = 7;
              HIBYTE(m_pNext[1].m_Pos.z) = -52;
            }
            break;
          case 8:
            *(float *)&m_pNext[1].m_pSubTexture = *(float *)&m_pNext[1].m_pSubTexture - (float)(v8 * 4.0);
            break;
          case 9:
            *(float *)&m_pNext[1].m_pSubTexture = *(float *)&m_pNext[1].m_pSubTexture - (float)(v8 * 8.0);
            break;
          default:
            break;
        }
        v34 = (float)(*(float *)&m_pNext[1].m_pNext * m_flTimeDelta) + m_pNext->m_Pos.y;
        v35 = (float)(*(float *)&m_pNext[1].m_pSubTexture * m_flTimeDelta) + m_pNext->m_Pos.z;
        m_pNext->m_Pos.x = m_pNext->m_Pos.x + (float)(*(float *)&m_pNext[1].m_pPrev * m_flTimeDelta);
        m_pNext->m_Pos.y = v34;
        m_pNext->m_Pos.z = v35;
      }
      else
      {
        CParticleEffectBinding::RemoveParticle(this: pIterator->m_pEffectBinding, pParticle: m_pNext);
      }
      m_pNext = pIterator->m_pNextParticle;
      if ( m_pNext == &pIterator->m_pMaterial->m_Particles )
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102638A0
// Name: public: virtual void CTEParticleRenderer::RenderParticles(class CParticleRenderIterator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTEParticleRenderer::RenderParticles(CTEParticleRenderer *this, CParticleRenderIterator *pIterator)
{
  CEffectMaterial *m_pMaterial; // ecx
  Particle *m_pNext; // eax
  Particle *i; // esi
  CParticleMgr *v6; // eax
  float y; // xmm1_4
  float x; // xmm2_4
  float z; // xmm3_4
  int v10; // ecx
  int v11; // edx
  float v12; // xmm4_4
  float v13; // xmm0_4
  float z_low; // xmm1_4
  int z_high; // eax
  Vector vColor; // [esp+14h] [ebp-18h] BYREF
  Vector tPos; // [esp+20h] [ebp-Ch] BYREF

  m_pMaterial = pIterator->m_pMaterial;
  pIterator->m_bGotFirst = true;
  m_pNext = m_pMaterial->m_Particles.m_pNext;
  pIterator->m_pCur = m_pNext;
  if ( m_pNext != &m_pMaterial->m_Particles )
  {
    pIterator->m_pParticleDraw->m_pSubTexture = m_pNext->m_pSubTexture;
    for ( i = pIterator->m_pCur;
          i != nullptr;
          i = (Particle *)CParticleRenderIterator::GetNext(this: pIterator, sortKey: tPos.z) )
    {
      v6 = ParticleMgr();
      y = i->m_Pos.y;
      x = i->m_Pos.x;
      z = i->m_Pos.z;
      v10 = BYTE1(i[1].m_Pos.z);
      v11 = BYTE2(i[1].m_Pos.z);
      v12 = v6->m_mModelView.m[1][1] * y;
      tPos.x = (float)((float)((float)(v6->m_mModelView.m[0][1] * y) + (float)(v6->m_mModelView.m[0][0] * x))
                     + (float)(v6->m_mModelView.m[0][2] * z))
             + v6->m_mModelView.m[0][3];
      tPos.y = (float)((float)((float)(v6->m_mModelView.m[1][0] * x) + v12) + (float)(v6->m_mModelView.m[1][2] * z))
             + v6->m_mModelView.m[1][3];
      v13 = (float)((float)((float)(v6->m_mModelView.m[2][0] * x) + (float)(v6->m_mModelView.m[2][1] * y))
                  + (float)(v6->m_mModelView.m[2][2] * z))
          + v6->m_mModelView.m[2][3];
      z_low = (float)LOBYTE(i[1].m_Pos.z);
      z_high = HIBYTE(i[1].m_Pos.z);
      tPos.z = v13;
      vColor.x = z_low * 0.0039077764;
      vColor.y = (float)v10 * 0.0039077764;
      vColor.z = (float)v11 * 0.0039077764;
      RenderParticle_ColorSize(
        pDraw: pIterator->m_pParticleDraw,
        pos: &tPos,
        color: &vColor,
        alpha: (float)z_high * 0.0039077764,
        size: this->m_ParticleSize);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1042C7E0
// Name: DT_TEParticleSystem::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEParticleSystem::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_TEParticleSystem::g_RecvTable);
  return atexit(func: DT_TEParticleSystem::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042C800
// Name: DT_TEParticleSystem::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEParticleSystem::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_TEParticleSystem::ignored>();
  DT_TEParticleSystem::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436D60
// Name: DT_TEParticleSystem::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEParticleSystem::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_TEParticleSystem::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10263840
// Name: _C_TEParticleSystem_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_TEParticleSystem_CreateObject(int entnum, int serialNum)
{
  C_BaseTempEntity *v2; // eax
  _DWORD *v3; // esi
  void (__thiscall *v4)(_DWORD *, int, int); // eax

  v2 = (C_BaseTempEntity *)MemAlloc_Alloc(nSize: 0x1Cu);
  v3 = &v2->IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_BaseTempEntity::C_BaseTempEntity(this: v2);
  *v3 = &C_TEParticleSystem::`vftable'{for `IClientUnknown'};
  v3[1] = &C_TEParticleSystem::`vftable'{for `IClientNetworkable'};
  v4 = *(void (__thiscall **)(_DWORD *, int, int))(*v3 + 52);
  v3[4] = 0;
  v3[5] = 0;
  v3[6] = 0;
  v4(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 1);
}

//------------------------------------------------------------------------------
// Address: 0x10263A30
// Name: public: static class CSmartPtr<class CTEParticleRenderer,class CRefCountAccessor> CTEParticleRenderer::Create(char const __near *,class Vector const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSmartPtr<CTEParticleRenderer,CRefCountAccessor> *__cdecl CTEParticleRenderer::Create(
        CSmartPtr<CTEParticleRenderer,CRefCountAccessor> *result,
        const char *pDebugName,
        const Vector *vOrigin)
{
  CTEParticleRenderer *v3; // esi

  v3 = (CTEParticleRenderer *)MemAlloc_Alloc(nSize: 0x108u);
  if ( v3 != nullptr )
  {
    CParticleEffect::CParticleEffect(this: v3, pName: pDebugName);
    v3->__vftable = (CTEParticleRenderer_vtbl *)&CTEParticleRenderer::`vftable';
    *(_QWORD *)&v3->m_ParticleSize = 1069547520;
    CParticleEffect::SetDynamicallyAllocated(this: v3, bDynamic: true);
    CParticleEffect::SetSortOrigin(this: v3, vSortOrigin: vOrigin);
  }
  else
  {
    v3 = nullptr;
  }
  result->m_pObj = nullptr;
  if ( v3 != nullptr )
  {
    CParticleEffect::AddRef(this: v3);
    if ( result->m_pObj != nullptr )
      CParticleEffect::Release(this: result->m_pObj);
    result->m_pObj = v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042C810
// Name: _dynamic_initializer_for____g_C_TEPhysicsProp__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____g_C_TEPhysicsProp__()
{
  C_BaseTempEntity::C_BaseTempEntity(this: &_g_C_TEPhysicsProp);
  _g_C_TEPhysicsProp.m_nModelIndex = 0;
  _g_C_TEPhysicsProp.m_nSkin = 0;
  _g_C_TEPhysicsProp.m_nFlags = 0;
  _g_C_TEPhysicsProp.m_nEffects = 0;
  _g_C_TEPhysicsProp.C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEPhysicsProp_vtbl *)&C_TEPhysicsProp::`vftable'{for `IClientUnknown'};
  _g_C_TEPhysicsProp.C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEPhysicsProp::`vftable'{for `IClientNetworkable'};
  _g_C_TEPhysicsProp.m_vecOrigin.x = 0.0;
  _g_C_TEPhysicsProp.m_vecOrigin.y = 0.0;
  _g_C_TEPhysicsProp.m_vecOrigin.z = 0.0;
  _g_C_TEPhysicsProp.m_angRotation.x = 0.0;
  _g_C_TEPhysicsProp.m_angRotation.y = 0.0;
  _g_C_TEPhysicsProp.m_angRotation.z = 0.0;
  _g_C_TEPhysicsProp.m_vecVelocity.x = 0.0;
  _g_C_TEPhysicsProp.m_vecVelocity.y = 0.0;
  _g_C_TEPhysicsProp.m_vecVelocity.z = 0.0;
  _g_C_TEPhysicsProp.m_clrRender = (color32_s)-1;
  return atexit(func: dynamic_atexit_destructor_for____g_C_TEPhysicsProp__);
}

//------------------------------------------------------------------------------
// Address: 0x1042C8C0
// Name: _dynamic_initializer_for____g_C_TEPhysicsPropClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_TEPhysicsPropClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_TEPhysicsPropClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_TEPhysicsPropClientClass;
  return result;
}
