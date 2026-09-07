// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_te_clientprojectile.cpp
// Functions: 9
// ============================================================

#include "game\client\c_te_clientprojectile.h"

//------------------------------------------------------------------------------
// Address: 0x102579A0
// Name: void TE_ClientProjectile(class IRecipientFilter __near &,float,class Vector const __near *,class Vector const __near *,int,int,class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_ClientProjectile(
        IRecipientFilter *filter,
        float delay,
        const Vector *vecOrigin,
        const Vector *vecVelocity,
        int modelindex,
        int lifetime,
        C_BaseEntity *pOwner)
{
  tempents->ClientProjectile(
    this: tempents,
    a2: vecOrigin,
    a3: vecVelocity,
    a4: &vec3_origin,
    a5: modelindex,
    a6: lifetime,
    a7: pOwner,
    a8: nullptr,
    a9: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102579D0
// Name: public: virtual class ClientClass __near * C_TEClientProjectile::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_TEClientProjectile::GetClientClass(C_TEClientProjectile *this)
{
  return &__g_C_TEClientProjectileClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10257B10
// Name: public: virtual void C_TEClientProjectile::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TEClientProjectile::PostDataUpdate(C_TEClientProjectile *this, DataUpdateType_t updateType)
{
  unsigned int m_nLifeTime; // edx
  C_BaseEntity *m_pEntity; // eax

  m_nLifeTime = this->m_nLifeTime;
  if ( m_nLifeTime == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_nLifeTime].m_SerialNumber != HIWORD(m_nLifeTime) )
  {
    m_pEntity = nullptr;
  }
  else
  {
    m_pEntity = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_nLifeTime].m_pEntity;
  }
  tempents->ClientProjectile(
    this: tempents,
    a2: (const Vector *)&this->m_pNextDynamic,
    a3: (const Vector *)&this->m_vecOrigin.z,
    a4: &vec3_origin,
    a5: LODWORD(this->m_vecVelocity.z),
    a6: this->m_nModelIndex,
    a7: m_pEntity,
    a8: nullptr,
    a9: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1042BBB0
// Name: DT_TEClientProjectile::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEClientProjectile::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_TEClientProjectile::g_RecvTable);
  return atexit(func: DT_TEClientProjectile::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042BBD0
// Name: DT_TEClientProjectile::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEClientProjectile::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_TEClientProjectile::ignored>();
  DT_TEClientProjectile::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436A30
// Name: DT_TEClientProjectile::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEClientProjectile::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_TEClientProjectile::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x102579E0
// Name: _C_TEClientProjectile_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_TEClientProjectile_CreateObject()
{
  return &_g_C_TEClientProjectile.IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1042BBE0
// Name: _dynamic_initializer_for____g_C_TEDecal__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____g_C_TEDecal__()
{
  C_BaseTempEntity::C_BaseTempEntity(this: &_g_C_TEDecal);
  _g_C_TEDecal.C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEDecal_vtbl *)&C_TEDecal::`vftable'{for `IClientUnknown'};
  _g_C_TEDecal.C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEDecal::`vftable'{for `IClientNetworkable'};
  _g_C_TEDecal.m_vecOrigin.x = 0.0;
  _g_C_TEDecal.m_vecOrigin.y = 0.0;
  _g_C_TEDecal.m_vecOrigin.z = 0.0;
  _g_C_TEDecal.m_vecStart.x = 0.0;
  _g_C_TEDecal.m_vecStart.y = 0.0;
  _g_C_TEDecal.m_vecStart.z = 0.0;
  _g_C_TEDecal.m_nEntity = 0;
  _g_C_TEDecal.m_nIndex = 0;
  _g_C_TEDecal.m_nHitbox = 0;
  return atexit(func: dynamic_atexit_destructor_for____g_C_TEDecal__);
}

//------------------------------------------------------------------------------
// Address: 0x1042BC50
// Name: _dynamic_initializer_for____g_C_TEDecalClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_TEDecalClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_TEDecalClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_TEDecalClientClass;
  return result;
}
