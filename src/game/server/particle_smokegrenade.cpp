// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/particle_smokegrenade.cpp
// Functions: 13
// ============================================================

#include "game\server\particle_smokegrenade.h"

//------------------------------------------------------------------------------
// Address: 0x10325860
// Name: public: virtual class ServerClass __near * ParticleSmokeGrenade::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall ParticleSmokeGrenade::GetServerClass(ParticleSmokeGrenade *this)
{
  return &g_ParticleSmokeGrenade_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10325870
// Name: private: virtual struct datamap_t __near * ParticleSmokeGrenade::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall ParticleSmokeGrenade::GetDataDescMap(ParticleSmokeGrenade *this)
{
  return &ParticleSmokeGrenade::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x103258B0
// Name: public: virtual void ParticleSmokeGrenade::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ParticleSmokeGrenade::Spawn(ParticleSmokeGrenade *this)
{
  CAI_BaseNPC::OnSetSchedule((vgui::Panel *)this);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
  this->m_creatorPlayer.m_Index = -1;
}

//------------------------------------------------------------------------------
// Address: 0x103258E0
// Name: public: virtual void ParticleSmokeGrenade::Think(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ParticleSmokeGrenade::Think(ParticleSmokeGrenade *this)
{
  float curtime; // xmm0_4

  curtime = gpGlobals->curtime;
  if ( curtime < (float)(this->m_FadeEndTime.m_Value + this->m_flSpawnTime.m_Value) )
    CBaseEntity::SetNextThink(this, thinkTime: curtime + 1.0, szContext: nullptr);
  else
    UTIL_Remove(oldObj: this);
}

//------------------------------------------------------------------------------
// Address: 0x10325AE0
// Name: public: virtual int ParticleSmokeGrenade::UpdateTransmitState(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall ParticleSmokeGrenade::UpdateTransmitState(ParticleSmokeGrenade *this)
{
  if ( (this->m_fEffects.m_Value & 0x20) != 0 )
    return CBaseEntity::SetTransmitState(this, nFlag: 16);
  else
    return CBaseEntity::SetTransmitState(this, nFlag: 8);
}

//------------------------------------------------------------------------------
// Address: 0x10325B00
// Name: public: ParticleSmokeGrenade::ParticleSmokeGrenade(void)
// Source: json
//------------------------------------------------------------------------------
ParticleSmokeGrenade *__thiscall ParticleSmokeGrenade::ParticleSmokeGrenade(ParticleSmokeGrenade *this)
{
  edict_t *m_pPev; // ecx
  edict_t *v3; // ecx
  edict_t *v4; // ecx
  edict_t *v5; // ecx
  edict_t *v6; // ecx
  CGlobalVars *v7; // edi
  ParticleSmokeGrenade *result; // eax
  edict_t *v9; // ecx

  CBaseParticleEntity::CBaseParticleEntity(this);
  this->__vftable = (ParticleSmokeGrenade_vtbl *)&ParticleSmokeGrenade::`vftable';
  this->m_creatorPlayer.m_Index = -1;
  if ( this->m_CurrentStage.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x354u);
    }
    this->m_CurrentStage.m_Value = 0;
  }
  if ( this->m_FadeStartTime.m_Value != 17.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v3 = this->m_Network.m_pPev;
      if ( v3 != nullptr )
        CBaseEdict::StateChanged(this: &v3->CBaseEdict, offset: 0x35Cu);
    }
    this->m_FadeStartTime.m_Value = 17.0;
  }
  if ( this->m_FadeEndTime.m_Value != 22.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v4 = this->m_Network.m_pPev;
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x360u);
    }
    this->m_FadeEndTime.m_Value = 22.0;
  }
  if ( this->m_MinColor.m_Value.x != 0.5 || this->m_MinColor.m_Value.y != 0.5 || this->m_MinColor.m_Value.z != 0.5 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v5 = this->m_Network.m_pPev;
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x364u);
    }
    this->m_MinColor.m_Value.x = 0.5;
    this->m_MinColor.m_Value.y = 0.5;
    this->m_MinColor.m_Value.z = 0.5;
  }
  if ( this->m_MaxColor.m_Value.x != 0.60000002
    || this->m_MaxColor.m_Value.y != 0.60000002
    || this->m_MaxColor.m_Value.z != 0.60000002 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v6 = this->m_Network.m_pPev;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0x370u);
    }
    this->m_MaxColor.m_Value.x = 0.60000002;
    this->m_MaxColor.m_Value.y = 0.60000002;
    this->m_MaxColor.m_Value.z = 0.60000002;
  }
  v7 = gpGlobals;
  result = this;
  if ( this->m_flSpawnTime.m_Value != gpGlobals->curtime )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_flSpawnTime.m_Value = v7->curtime;
    }
    else
    {
      v9 = this->m_Network.m_pPev;
      if ( v9 != nullptr )
        CBaseEdict::StateChanged(this: &v9->CBaseEdict, offset: 0x358u);
      this->m_flSpawnTime.m_Value = v7->curtime;
      return this;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104153E0
// Name: DT_ParticleSmokeGrenade::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_ParticleSmokeGrenade::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_ParticleSmokeGrenade::g_SendTable);
  return atexit(func: DT_ParticleSmokeGrenade::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10415400
// Name: DT_ParticleSmokeGrenade::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_ParticleSmokeGrenade::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_ParticleSmokeGrenade::ignored>();
  DT_ParticleSmokeGrenade::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10415430
// Name: ParticleSmokeGrenade_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *ParticleSmokeGrenade_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<ParticleSmokeGrenade>();
  ParticleSmokeGrenade_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421AC0
// Name: DT_ParticleSmokeGrenade::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_ParticleSmokeGrenade::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_ParticleSmokeGrenade::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10415410
// Name: _dynamic_initializer_for__env_particlesmokegrenade__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_particlesmokegrenade__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<ParticleSmokeGrenade> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_particlesmokegrenade,
           a3: "env_particlesmokegrenade");
}

//------------------------------------------------------------------------------
// Address: 0x10421AD0
// Name: _ServerClassInit_DT_ParticleSmokeGrenade::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_ParticleSmokeGrenade::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_315;
  for ( i = 7; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x10421AF0
// Name: _DataMapInit_ParticleSmokeGrenade__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_ParticleSmokeGrenade__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_504);
}
