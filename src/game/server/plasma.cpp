// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/plasma.cpp
// Functions: 14
// ============================================================

#include "game\server\plasma.h"

//------------------------------------------------------------------------------
// Address: 0x10325DE0
// Name: public: virtual class ServerClass __near * CPlasma::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CPlasma::GetServerClass(CPlasma *this)
{
  return &g_CPlasma_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10325DF0
// Name: public: virtual struct datamap_t __near * CPlasma::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPlasma::GetDataDescMap(CPlasma *this)
{
  return &CPlasma::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10325E00
// Name: public: virtual void CPlasma::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CPlasma::Precache(CPlasma *this@<ecx>, bool (__cdecl *a2)(const char *)@<edi>)
{
  CBaseEntity::PrecacheModel(a1: a2, name: "sprites/plasma1.vmt", bPreload: true);
  CBaseEntity::PrecacheModel(a1: a2, name: "sprites/fire_floor.vmt", bPreload: true);
}

//------------------------------------------------------------------------------
// Address: 0x10325FE0
// Name: public: CPlasma::CPlasma(void)
// Source: json
//------------------------------------------------------------------------------
CPlasma *__thiscall CPlasma::CPlasma(CPlasma *this)
{
  edict_t *m_pPev; // ecx
  edict_t *v3; // ecx
  edict_t *v4; // ecx
  int v5; // ebx
  edict_t *v6; // ecx
  int v7; // ebx
  edict_t *v8; // ecx
  int v9; // ebx
  CPlasma *result; // eax
  edict_t *v11; // ecx

  CBaseFire::CBaseFire(this);
  this->__vftable = (CPlasma_vtbl *)&CPlasma::`vftable';
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
  v5 = CBaseEntity::PrecacheModel(a1: (bool (__cdecl *)(const char *))this, name: "sprites/plasma1.vmt", bPreload: true);
  if ( this->m_nPlasmaModelIndex.m_Value != v5 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v6 = this->m_Network.m_pPev;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0x364u);
    }
    this->m_nPlasmaModelIndex.m_Value = v5;
  }
  v7 = CBaseEntity::PrecacheModel(a1: (bool (__cdecl *)(const char *))this, name: "sprites/plasma1.vmt", bPreload: true);
  if ( this->m_nPlasmaModelIndex2.m_Value != v7 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v8 = this->m_Network.m_pPev;
      if ( v8 != nullptr )
        CBaseEdict::StateChanged(this: &v8->CBaseEdict, offset: 0x368u);
    }
    this->m_nPlasmaModelIndex2.m_Value = v7;
  }
  v9 = CBaseEntity::PrecacheModel(
         a1: (bool (__cdecl *)(const char *))this,
         name: "sprites/fire_floor.vmt",
         bPreload: true);
  result = this;
  if ( this->m_nGlowModelIndex.m_Value != v9 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_nGlowModelIndex.m_Value = v9;
    }
    else
    {
      v11 = this->m_Network.m_pPev;
      if ( v11 != nullptr )
        CBaseEdict::StateChanged(this: &v11->CBaseEdict, offset: 0x36Cu);
      this->m_nGlowModelIndex.m_Value = v9;
      return this;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10326180
// Name: public: void CPlasma::EnableSmoke(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlasma::EnableSmoke(CFireSmoke *this, int state)
{
  CNetworkVarBase<int,CBaseFire::NetworkVar_m_nFlags> *p_m_nFlags; // esi
  int m_Value; // edi
  unsigned int v4; // edi
  edict_t *m_pPev; // ecx

  p_m_nFlags = &this->m_nFlags;
  m_Value = this->m_nFlags.m_Value;
  if ( state != 0 )
    v4 = m_Value | 2;
  else
    v4 = m_Value & 0xFFFFFFFD;
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
// Address: 0x10415440
// Name: _dynamic_initializer_for___plasma__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for___plasma__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CPlasma> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &plasma,
           a3: "_plasma");
}

//------------------------------------------------------------------------------
// Address: 0x10415480
// Name: DT_Plasma::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_Plasma::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_Plasma::g_SendTable);
  return atexit(func: DT_Plasma::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104154A0
// Name: DT_Plasma::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_Plasma::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_Plasma::ignored>();
  DT_Plasma::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104154B0
// Name: CPlasma_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPlasma_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPlasma>();
  CPlasma_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421B00
// Name: DT_Plasma::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_Plasma::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_Plasma::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10415460
// Name: _dynamic_initializer_for__g_CPlasma_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CPlasma_ClassReg__()
{
  return ServerClass::ServerClass(this: &g_CPlasma_ClassReg, pNetworkName: "CPlasma", pTable: &DT_Plasma::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x104154C0
// Name: _dynamic_initializer_for__g_SmokeTrail_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_SmokeTrail_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_SmokeTrail_ClassReg,
           pNetworkName: "SmokeTrail",
           pTable: &DT_SmokeTrail::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10421B10
// Name: _ServerClassInit_DT_Plasma::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_Plasma::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_316;
  for ( i = 7; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x10421B30
// Name: _DataMapInit_CPlasma__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPlasma__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_505);
}
