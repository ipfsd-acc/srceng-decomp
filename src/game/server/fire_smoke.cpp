// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/fire_smoke.cpp
// Functions: 45
// ============================================================

#include "game\server\fire_smoke.h"

//------------------------------------------------------------------------------
// Address: 0x101273F0
// Name: public: virtual struct datamap_t __near * CBaseFire::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CBaseFire::GetDataDescMap(CBaseFire *this)
{
  return &CBaseFire::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10127400
// Name: public: virtual CBaseFire::~CBaseFire(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseFire::~CBaseFire(CBaseFire *this)
{
  this->__vftable = (CBaseFire_vtbl *)&CBaseFire::`vftable';
  CBaseEntity::~CBaseEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x10127410
// Name: public: virtual class ServerClass __near * CFireSmoke::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CFireSmoke::GetServerClass(CFireSmoke *this)
{
  return &g_CFireSmoke_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10127420
// Name: public: virtual struct datamap_t __near * CFireSmoke::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CFireSmoke::GetDataDescMap(CFireSmoke *this)
{
  return &CFireSmoke::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101275E0
// Name: public: CBaseFire::CBaseFire(void)
// Source: json
//------------------------------------------------------------------------------
CBaseFire *__thiscall CBaseFire::CBaseFire(CBaseFire *this)
{
  edict_t *m_pPev; // ecx
  edict_t *v3; // ecx
  edict_t *v4; // ecx
  CBaseFire *result; // eax
  edict_t *v6; // ecx

  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->__vftable = (CBaseFire_vtbl *)&CBaseFire::`vftable';
  if ( this->m_flStartScale.m_Value != 0.0 )
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
    this->m_flStartScale.m_Value = 0.0;
  }
  if ( this->m_flScale.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v3 = this->m_Network.m_pPev;
      if ( v3 != nullptr )
        CBaseEdict::StateChanged(this: &v3->CBaseEdict, offset: 0x358u);
    }
    this->m_flScale.m_Value = 0.0;
  }
  if ( this->m_flScaleTime.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v4 = this->m_Network.m_pPev;
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x35Cu);
    }
    this->m_flScaleTime.m_Value = 0.0;
  }
  result = this;
  if ( this->m_nFlags.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_nFlags.m_Value = 0;
    }
    else
    {
      v6 = this->m_Network.m_pPev;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0x360u);
      this->m_nFlags.m_Value = 0;
      return this;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10127700
// Name: public: virtual void CBaseFire::Scale(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseFire::Scale(CBaseFire *this, float size, float time)
{
  edict_t *m_pPev; // ecx
  edict_t *v5; // ecx

  if ( this->m_flScale.m_Value != size )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x358u);
    }
    this->m_flScale.m_Value = size;
  }
  if ( this->m_flScaleTime.m_Value != time )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_flScaleTime.m_Value = time;
    }
    else
    {
      v5 = this->m_Network.m_pPev;
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x35Cu);
      this->m_flScaleTime.m_Value = time;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101277B0
// Name: public: virtual void CBaseFire::Scale(float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseFire::Scale(CBaseFire *this, float start, float size, float time)
{
  edict_t *m_pPev; // ecx
  edict_t *v6; // ecx
  edict_t *v7; // ecx

  if ( this->m_flStartScale.m_Value != start )
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
    this->m_flStartScale.m_Value = start;
  }
  if ( this->m_flScale.m_Value != size )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v6 = this->m_Network.m_pPev;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0x358u);
    }
    this->m_flScale.m_Value = size;
  }
  if ( this->m_flScaleTime.m_Value != time )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_flScaleTime.m_Value = time;
    }
    else
    {
      v7 = this->m_Network.m_pPev;
      if ( v7 != nullptr )
        CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: 0x35Cu);
      this->m_flScaleTime.m_Value = time;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101278A0
// Name: public: virtual void CBaseFire::Enable(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseFire::Enable(CBaseFire *this, int state)
{
  CNetworkVarBase<int,CBaseFire::NetworkVar_m_nFlags> *p_m_nFlags; // edi
  int v3; // esi
  edict_t *m_pPev; // ecx
  CNetworkVarBase<int,CBaseFire::NetworkVar_m_nFlags> *v5; // esi
  unsigned int v6; // edi
  edict_t *v7; // ecx

  if ( state != 0 )
  {
    p_m_nFlags = &this->m_nFlags;
    v3 = this->m_nFlags.m_Value | 1;
    if ( this->m_nFlags.m_Value != v3 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        p_m_nFlags->m_Value = v3;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x360u);
        p_m_nFlags->m_Value = v3;
      }
    }
  }
  else
  {
    v5 = &this->m_nFlags;
    v6 = this->m_nFlags.m_Value & 0xFFFFFFFE;
    if ( this->m_nFlags.m_Value != v6 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        v5->m_Value = v6;
      }
      else
      {
        v7 = this->m_Network.m_pPev;
        if ( v7 != nullptr )
          CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: 0x360u);
        v5->m_Value = v6;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10127940
// Name: public: CFireSmoke::CFireSmoke(void)
// Source: json
//------------------------------------------------------------------------------
CFireSmoke *__thiscall CFireSmoke::CFireSmoke(CFireSmoke *this)
{
  edict_t *m_pPev; // ecx
  edict_t *v3; // ecx
  edict_t *v4; // ecx

  CBaseFire::CBaseFire(this);
  this->__vftable = (CFireSmoke_vtbl *)&CFireSmoke::`vftable';
  if ( this->m_flScale.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x358u);
    }
    this->m_flScale.m_Value = 0.0;
  }
  if ( this->m_flScaleTime.m_Value != 0.0 )
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
    this->m_flScaleTime.m_Value = 0.0;
  }
  if ( this->m_nFlags.m_Value != 0 )
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
    this->m_nFlags.m_Value = 0;
  }
  this->m_iEFlags |= 0x80u;
  CBaseEntity::DispatchUpdateTransmitState(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10127A50
// Name: public: void CFireSmoke::EnableGlow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFireSmoke::EnableGlow(CFireSmoke *this, int state)
{
  CNetworkVarBase<int,CBaseFire::NetworkVar_m_nFlags> *p_m_nFlags; // esi
  int m_Value; // edi
  unsigned int v4; // edi
  edict_t *m_pPev; // ecx

  p_m_nFlags = &this->m_nFlags;
  m_Value = this->m_nFlags.m_Value;
  if ( state != 0 )
    v4 = m_Value | 8;
  else
    v4 = m_Value & 0xFFFFFFF7;
  if ( this->m_nFlags.m_Value != v4 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_nFlags->m_Value = v4;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x360u);
      p_m_nFlags->m_Value = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10127AB0
// Name: public: void CFireSmoke::EnableVisibleFromAbove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFireSmoke::EnableVisibleFromAbove(CFireSmoke *this, int state)
{
  CNetworkVarBase<int,CBaseFire::NetworkVar_m_nFlags> *p_m_nFlags; // esi
  int m_Value; // edi
  unsigned int v4; // edi
  edict_t *m_pPev; // ecx

  p_m_nFlags = &this->m_nFlags;
  m_Value = this->m_nFlags.m_Value;
  if ( state != 0 )
    v4 = m_Value | 0x10;
  else
    v4 = m_Value & 0xFFFFFFEF;
  if ( this->m_nFlags.m_Value != v4 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_nFlags->m_Value = v4;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x360u);
      p_m_nFlags->m_Value = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104031D0
// Name: _dynamic_initializer_for__fire_maxabsorb__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__fire_maxabsorb__()
{
  ConVar::ConVar(this: &fire_maxabsorb, pName: "fire_maxabsorb", pDefaultValue: "50", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__fire_maxabsorb__);
}

//------------------------------------------------------------------------------
// Address: 0x10403200
// Name: _dynamic_initializer_for__fire_absorbrate__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__fire_absorbrate__()
{
  ConVar::ConVar(this: &fire_absorbrate, pName: "fire_absorbrate", pDefaultValue: "3", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__fire_absorbrate__);
}

//------------------------------------------------------------------------------
// Address: 0x10403230
// Name: _dynamic_initializer_for__fire_extscale__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__fire_extscale__()
{
  ConVar::ConVar(this: &fire_extscale, pName: "fire_extscale", pDefaultValue: "12", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__fire_extscale__);
}

//------------------------------------------------------------------------------
// Address: 0x10403260
// Name: _dynamic_initializer_for__fire_extabsorb__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__fire_extabsorb__()
{
  ConVar::ConVar(this: &fire_extabsorb, pName: "fire_extabsorb", pDefaultValue: "5", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__fire_extabsorb__);
}

//------------------------------------------------------------------------------
// Address: 0x10403290
// Name: _dynamic_initializer_for__fire_heatscale__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__fire_heatscale__()
{
  ConVar::ConVar(this: &fire_heatscale, pName: "fire_heatscale", pDefaultValue: "1.0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__fire_heatscale__);
}

//------------------------------------------------------------------------------
// Address: 0x104032C0
// Name: _dynamic_initializer_for__fire_incomingheatscale__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__fire_incomingheatscale__()
{
  ConVar::ConVar(this: &fire_incomingheatscale, pName: "fire_incomingheatscale", pDefaultValue: "0.1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__fire_incomingheatscale__);
}

//------------------------------------------------------------------------------
// Address: 0x104032F0
// Name: _dynamic_initializer_for__fire_dmgscale__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__fire_dmgscale__()
{
  ConVar::ConVar(this: &fire_dmgscale, pName: "fire_dmgscale", pDefaultValue: "0.1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__fire_dmgscale__);
}

//------------------------------------------------------------------------------
// Address: 0x10403320
// Name: _dynamic_initializer_for__fire_dmgbase__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__fire_dmgbase__()
{
  ConVar::ConVar(this: &fire_dmgbase, pName: "fire_dmgbase", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__fire_dmgbase__);
}

//------------------------------------------------------------------------------
// Address: 0x10403350
// Name: _dynamic_initializer_for__fire_growthrate__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__fire_growthrate__()
{
  ConVar::ConVar(this: &fire_growthrate, pName: "fire_growthrate", pDefaultValue: "1.0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__fire_growthrate__);
}

//------------------------------------------------------------------------------
// Address: 0x10403380
// Name: _dynamic_initializer_for__fire_dmginterval__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__fire_dmginterval__()
{
  ConVar::ConVar(this: &fire_dmginterval, pName: "fire_dmginterval", pDefaultValue: "1.0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__fire_dmginterval__);
}

//------------------------------------------------------------------------------
// Address: 0x10403440
// Name: CBaseFire_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CBaseFire_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CBaseFire>();
  CBaseFire_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10403490
// Name: DT_FireSmoke::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_FireSmoke::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_FireSmoke::g_SendTable);
  return atexit(func: DT_FireSmoke::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104034B0
// Name: DT_FireSmoke::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_FireSmoke::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_FireSmoke::ignored>();
  DT_FireSmoke::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104034C0
// Name: CFireSmoke_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CFireSmoke_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CFireSmoke>();
  CFireSmoke_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104116A0
// Name: _dynamic_initializer_for__fire_cracker_blast__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__fire_cracker_blast__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CFireCrackerBlast> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &fire_cracker_blast,
           a3: "fire_cracker_blast");
}

//------------------------------------------------------------------------------
// Address: 0x1041B260
// Name: _dynamic_atexit_destructor_for__fire_maxabsorb__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fire_maxabsorb__()
{
  ConVar::~ConVar(this: &fire_maxabsorb);
}

//------------------------------------------------------------------------------
// Address: 0x1041B270
// Name: _dynamic_atexit_destructor_for__fire_absorbrate__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fire_absorbrate__()
{
  ConVar::~ConVar(this: &fire_absorbrate);
}

//------------------------------------------------------------------------------
// Address: 0x1041B280
// Name: _dynamic_atexit_destructor_for__fire_extscale__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fire_extscale__()
{
  ConVar::~ConVar(this: &fire_extscale);
}

//------------------------------------------------------------------------------
// Address: 0x1041B290
// Name: _dynamic_atexit_destructor_for__fire_extabsorb__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fire_extabsorb__()
{
  ConVar::~ConVar(this: &fire_extabsorb);
}

//------------------------------------------------------------------------------
// Address: 0x1041B2A0
// Name: _dynamic_atexit_destructor_for__fire_heatscale__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fire_heatscale__()
{
  ConVar::~ConVar(this: &fire_heatscale);
}

//------------------------------------------------------------------------------
// Address: 0x1041B2B0
// Name: _dynamic_atexit_destructor_for__fire_incomingheatscale__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fire_incomingheatscale__()
{
  ConVar::~ConVar(this: &fire_incomingheatscale);
}

//------------------------------------------------------------------------------
// Address: 0x1041B2C0
// Name: _dynamic_atexit_destructor_for__fire_dmgscale__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fire_dmgscale__()
{
  ConVar::~ConVar(this: &fire_dmgscale);
}

//------------------------------------------------------------------------------
// Address: 0x1041B2D0
// Name: _dynamic_atexit_destructor_for__fire_dmgbase__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fire_dmgbase__()
{
  ConVar::~ConVar(this: &fire_dmgbase);
}

//------------------------------------------------------------------------------
// Address: 0x1041B2E0
// Name: _dynamic_atexit_destructor_for__fire_growthrate__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fire_growthrate__()
{
  ConVar::~ConVar(this: &fire_growthrate);
}

//------------------------------------------------------------------------------
// Address: 0x1041B2F0
// Name: _dynamic_atexit_destructor_for__fire_dmginterval__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fire_dmginterval__()
{
  ConVar::~ConVar(this: &fire_dmginterval);
}

//------------------------------------------------------------------------------
// Address: 0x1041B330
// Name: DT_FireSmoke::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_FireSmoke::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_FireSmoke::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10403450
// Name: _dynamic_initializer_for___firesmoke__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for___firesmoke__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CFireSmoke> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &firesmoke,
           a3: "_firesmoke");
}

//------------------------------------------------------------------------------
// Address: 0x10403470
// Name: _dynamic_initializer_for__g_CFireSmoke_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CFireSmoke_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CFireSmoke_ClassReg,
           pNetworkName: "CFireSmoke",
           pTable: &DT_FireSmoke::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041B300
// Name: _DataMapInit_CFire__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CFire__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_198);
}

//------------------------------------------------------------------------------
// Address: 0x1041B310
// Name: _DataMapInit_CEnvFireSource__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CEnvFireSource__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_196);
}

//------------------------------------------------------------------------------
// Address: 0x1041B320
// Name: _DataMapInit_CEnvFireSensor__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CEnvFireSensor__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_197);
}

//------------------------------------------------------------------------------
// Address: 0x1041B340
// Name: _ServerClassInit_DT_FireSmoke::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_FireSmoke::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_58;
  for ( i = 7; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041B360
// Name: _DataMapInit_CBaseFire__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CBaseFire__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_199);
}

//------------------------------------------------------------------------------
// Address: 0x1041B370
// Name: _DataMapInit_CFireSmoke__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CFireSmoke__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_200);
}
