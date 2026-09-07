// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/cs_vehicle_jeep.cpp
// Functions: 12
// ============================================================

#include "game\server\cstrike15\cs_vehicle_jeep.h"

//------------------------------------------------------------------------------
// Address: 0x102982A0
// Name: private: void CPropJeep::InputStartRemoveTauCannon(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropJeep::InputStartRemoveTauCannon(CPropJeep *this, inputdata_t *inputdata)
{
  CGlobalVars *v2; // edi
  edict_t *m_pPev; // ecx
  edict_t *v5; // ecx
  edict_t *v6; // ecx
  int v7; // eax

  v2 = gpGlobals;
  if ( this->m_flAnimTime.m_Value != gpGlobals->curtime )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x64u);
    }
    this->m_flAnimTime.m_Value = v2->curtime;
  }
  if ( this->m_flPlaybackRate.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v5 = this->m_Network.m_pPev;
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x37Cu);
    }
    this->m_flPlaybackRate.m_Value = 0.0;
  }
  if ( this->m_flCycle.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v6 = this->m_Network.m_pPev;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0x3ACu);
    }
    this->m_flCycle.m_Value = 0.0;
  }
  v7 = CBaseAnimating::LookupSequence(this, label: "tau_levitate");
  CBaseAnimating::ResetSequence(this, nSequence: v7);
  this->m_bGunHasBeenCutOff = true;
}

//------------------------------------------------------------------------------
// Address: 0x10298390
// Name: private: void CPropJeep::InputFinishRemoveTauCannon(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPropJeep::InputFinishRemoveTauCannon(CPropJeep *this, inputdata_t *inputdata)
{
  edict_t *m_pPev; // ecx

  CBaseAnimating::SetBodygroup(this, iGroup: 1, iValue: 0);
  if ( this->m_bHasGun.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_bHasGun.m_Value = false;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x6B1u);
      this->m_bHasGun.m_Value = false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1040F4D0
// Name: JeepWaterData_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *JeepWaterData_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<JeepWaterData_t>();
  JeepWaterData_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040F4E0
// Name: CPropJeep_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPropJeep_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPropJeep>();
  CPropJeep_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040F510
// Name: DT_PropJeep::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_PropJeep::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_PropJeep::g_SendTable);
  return atexit(func: DT_PropJeep::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1040F530
// Name: DT_PropJeep::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_PropJeep::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_PropJeep::ignored>();
  DT_PropJeep::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041FE80
// Name: DT_PropJeep::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_PropJeep::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_PropJeep::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1040F4F0
// Name: _dynamic_initializer_for__g_CPropJeep_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CPropJeep_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CPropJeep_ClassReg,
           pNetworkName: "CPropJeep",
           pTable: &DT_PropJeep::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1040F540
// Name: _dynamic_initializer_for__g_EquipmentInfo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
FileWeaponInfo_t *dynamic_initializer_for__g_EquipmentInfo__()
{
  FileWeaponInfo_t *v0; // esi
  int i; // edi
  FileWeaponInfo_t *result; // eax

  v0 = &g_EquipmentInfo;
  for ( i = 2; i >= 0; --i )
  {
    result = FileWeaponInfo_t::FileWeaponInfo_t(this: v0);
    v0->__vftable = (FileWeaponInfo_t_vtbl *)&CCSWeaponInfo::`vftable';
    v0[1].__vftable = (FileWeaponInfo_t_vtbl *)1065353216;
    v0[1].szPrintName[59] = 0;
    v0 = (FileWeaponInfo_t *)((char *)v0 + 2840);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041FE90
// Name: _ServerClassInit_DT_PropJeep::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_PropJeep::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S4_69;
  for ( i = 2; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041FEB0
// Name: _DataMapInit_JeepWaterData_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_JeepWaterData_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_475);
}

//------------------------------------------------------------------------------
// Address: 0x1041FEC0
// Name: _DataMapInit_CPropJeep__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPropJeep__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_476);
}
