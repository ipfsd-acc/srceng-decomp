// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/func_occluder.cpp
// Functions: 12
// ============================================================

#include "game\server\func_occluder.h"

//------------------------------------------------------------------------------
// Address: 0x1013D120
// Name: public: virtual class ServerClass __near * CFuncOccluder::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CFuncOccluder::GetServerClass(CFuncOccluder *this)
{
  return &g_CFuncOccluder_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x1013D130
// Name: public: virtual struct datamap_t __near * CFuncOccluder::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CFuncOccluder::GetDataDescMap(CFuncOccluder *this)
{
  return &CFuncOccluder::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1013D1E0
// Name: public: CFuncOccluder::CFuncOccluder(void)
// Source: json
//------------------------------------------------------------------------------
CFuncOccluder *__thiscall CFuncOccluder::CFuncOccluder(CFuncOccluder *this)
{
  CFuncOccluder *result; // eax
  edict_t *m_pPev; // ecx

  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->__vftable = (CFuncOccluder_vtbl *)&CFuncOccluder::`vftable';
  result = this;
  if ( !this->m_bActive.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_bActive.m_Value = true;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x354u);
      this->m_bActive.m_Value = true;
      return this;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1013D240
// Name: public: virtual void CFuncOccluder::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncOccluder::Spawn(CFuncOccluder *this)
{
  const char *v2; // eax
  _BYTE v3[4]; // [esp+8h] [ebp-4h] BYREF

  this->Precache(this);
  if ( this->m_takedamage.m_Value != 0 )
  {
    this->NetworkStateChanged_m_takedamage(this, a2: &this->m_takedamage);
    this->m_takedamage.m_Value = 0;
  }
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  v2 = *(const char **)((int (__thiscall *)(CFuncOccluder *, _BYTE *))this->GetModelName)(a1: this, a2: v3);
  if ( v2 == nullptr )
    v2 = locale;
  this->SetModel(this, a2: v2);
}

//------------------------------------------------------------------------------
// Address: 0x1013D310
// Name: public: void CFuncOccluder::InputToggle(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncOccluder::InputToggle(CFuncOccluder *this, inputdata_t *inputdata)
{
  CNetworkVarBase<bool,CFuncOccluder::NetworkVar_m_bActive> *p_m_bActive; // esi
  bool v3; // bl
  edict_t *m_pPev; // ecx

  p_m_bActive = &this->m_bActive;
  v3 = !this->m_bActive.m_Value;
  if ( this->m_bActive.m_Value != v3 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_bActive->m_Value = v3;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x354u);
      p_m_bActive->m_Value = v3;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10224DA0
// Name: public: void CFuncOccluder::InputDeactivate(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFuncOccluder::InputDeactivate(CFuncOccluder *this, inputdata_t *inputdata)
{
  CNetworkVarBase<bool,CFuncOccluder::NetworkVar_m_bActive> *p_m_bActive; // esi
  edict_t *m_pPev; // ecx

  p_m_bActive = &this->m_bActive;
  if ( this->m_bActive.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_bActive->m_Value = false;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x354u);
      p_m_bActive->m_Value = false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10404150
// Name: DT_FuncOccluder::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_FuncOccluder::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_FuncOccluder::g_SendTable);
  return atexit(func: DT_FuncOccluder::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10404170
// Name: DT_FuncOccluder::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_FuncOccluder::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_FuncOccluder::ignored>();
  DT_FuncOccluder::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10404180
// Name: CFuncOccluder_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CFuncOccluder_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CFuncOccluder>();
  CFuncOccluder_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041B900
// Name: DT_FuncOccluder::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_FuncOccluder::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_FuncOccluder::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041B910
// Name: _ServerClassInit_DT_FuncOccluder::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_FuncOccluder::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_122;
  for ( i = 2; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041B930
// Name: _DataMapInit_CFuncOccluder__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CFuncOccluder__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_221);
}
