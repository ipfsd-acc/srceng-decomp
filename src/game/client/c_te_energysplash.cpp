// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_te_energysplash.cpp
// Functions: 9
// ============================================================

#include "game\client\c_te_energysplash.h"

//------------------------------------------------------------------------------
// Address: 0x10258F80
// Name: public: virtual void C_TEEnergySplash::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TEEnergySplash::PostDataUpdate(C_TEEnergySplash *this, DataUpdateType_t updateType)
{
  g_pEffects->EnergySplash(
    this: g_pEffects,
    a2: (const Vector *)&this->m_pNextDynamic,
    a3: (const Vector *)&this->m_vecPos.z,
    a4: LOBYTE(this->m_vecDir.z));
}

//------------------------------------------------------------------------------
// Address: 0x10258FB0
// Name: void TE_EnergySplash(class IRecipientFilter __near &,float,class Vector const __near *,class Vector const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_EnergySplash(
        IRecipientFilter *filter,
        float delay,
        const Vector *pos,
        const Vector *dir,
        BOOL bExplosive)
{
  g_pEffects->EnergySplash(this: g_pEffects, a2: pos, a3: dir, a4: bExplosive);
}

//------------------------------------------------------------------------------
// Address: 0x10258FD0
// Name: public: virtual class ClientClass __near * C_TEEnergySplash::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_TEEnergySplash::GetClientClass(C_TEEnergySplash *this)
{
  return &__g_C_TEEnergySplashClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1042BF80
// Name: DT_TEEnergySplash::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEEnergySplash::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_TEEnergySplash::g_RecvTable);
  return atexit(func: DT_TEEnergySplash::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042BFA0
// Name: DT_TEEnergySplash::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEEnergySplash::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_TEEnergySplash::ignored>();
  DT_TEEnergySplash::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436B10
// Name: DT_TEEnergySplash::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEEnergySplash::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_TEEnergySplash::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10258FE0
// Name: _C_TEEnergySplash_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_TEEnergySplash_CreateObject()
{
  return &_g_C_TEEnergySplash.IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1042BFB0
// Name: _dynamic_initializer_for____g_C_TEExplosion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____g_C_TEExplosion__()
{
  C_TEParticleSystem::C_TEParticleSystem(this: &_g_C_TEExplosion);
  _g_C_TEExplosion.C_TEParticleSystem::C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEExplosion_vtbl *)&C_TEExplosion::`vftable'{for `IClientUnknown'};
  _g_C_TEExplosion.C_TEParticleSystem::C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEExplosion::`vftable'{for `IClientNetworkable'};
  _g_C_TEExplosion.m_bShouldAffectRagdolls = true;
  _g_C_TEExplosion.m_nModelIndex = 0;
  _g_C_TEExplosion.m_fScale = 0.0;
  _g_C_TEExplosion.m_nFrameRate = 0;
  _g_C_TEExplosion.m_nFlags = 0;
  _g_C_TEExplosion.m_vecNormal.x = 0.0;
  _g_C_TEExplosion.m_vecNormal.y = 0.0;
  _g_C_TEExplosion.m_vecNormal.z = 0.0;
  _g_C_TEExplosion.m_chMaterialType = 67;
  _g_C_TEExplosion.m_nRadius = 0;
  _g_C_TEExplosion.m_nMagnitude = 0;
  _g_C_TEExplosion.m_pParticleMgr = nullptr;
  _g_C_TEExplosion.m_MaterialHandle = nullptr;
  return atexit(func: dynamic_atexit_destructor_for____g_C_TEExplosion__);
}

//------------------------------------------------------------------------------
// Address: 0x1042C030
// Name: _dynamic_initializer_for____g_C_TEExplosionClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_TEExplosionClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_TEExplosionClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_TEExplosionClientClass;
  return result;
}
