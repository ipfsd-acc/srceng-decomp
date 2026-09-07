// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/sprite_perfmonitor.cpp
// Functions: 16
// ============================================================

#include "game\server\sprite_perfmonitor.h"

//------------------------------------------------------------------------------
// Address: 0x1013D2C0
// Name: public: void CParticlePerformanceMonitor::InputTurnOnDisplay(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticlePerformanceMonitor::InputTurnOnDisplay(CFuncOccluder *this, inputdata_t *inputdata)
{
  CNetworkVarBase<bool,CFuncOccluder::NetworkVar_m_bActive> *p_m_bActive; // esi
  edict_t *m_pPev; // ecx

  p_m_bActive = &this->m_bActive;
  if ( !this->m_bActive.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_bActive->m_Value = true;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x354u);
      p_m_bActive->m_Value = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10224BE0
// Name: public: virtual struct datamap_t __near * CParticlePerformanceMonitor::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CParticlePerformanceMonitor::GetDataDescMap(CParticlePerformanceMonitor *this)
{
  return &CParticlePerformanceMonitor::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10224BF0
// Name: public: virtual class ServerClass __near * CParticlePerformanceMonitor::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CParticlePerformanceMonitor::GetServerClass(CParticlePerformanceMonitor *this)
{
  return &g_CParticlePerformanceMonitor_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10224D10
// Name: public: virtual void CParticlePerformanceMonitor::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticlePerformanceMonitor::Spawn(CParticlePerformanceMonitor *this)
{
  edict_t *m_pPev; // ecx
  edict_t *v3; // ecx

  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  if ( this->m_bDisplayPerf.m_Value )
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
    this->m_bDisplayPerf.m_Value = false;
  }
  if ( this->m_bMeasurePerf.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_bMeasurePerf.m_Value = false;
    }
    else
    {
      v3 = this->m_Network.m_pPev;
      if ( v3 != nullptr )
        CBaseEdict::StateChanged(this: &v3->CBaseEdict, offset: 0x355u);
      this->m_bMeasurePerf.m_Value = false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10224DF0
// Name: public: void CParticlePerformanceMonitor::InputStartMeasuring(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticlePerformanceMonitor::InputStartMeasuring(
        CParticlePerformanceMonitor *this,
        inputdata_t *inputdata)
{
  CNetworkVarBase<bool,CParticlePerformanceMonitor::NetworkVar_m_bMeasurePerf> *p_m_bMeasurePerf; // esi
  edict_t *m_pPev; // ecx

  p_m_bMeasurePerf = &this->m_bMeasurePerf;
  if ( !this->m_bMeasurePerf.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_bMeasurePerf->m_Value = true;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x355u);
      p_m_bMeasurePerf->m_Value = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10224E40
// Name: public: void CParticlePerformanceMonitor::InputStopMeasuring(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticlePerformanceMonitor::InputStopMeasuring(
        CParticlePerformanceMonitor *this,
        inputdata_t *inputdata)
{
  CNetworkVarBase<bool,CParticlePerformanceMonitor::NetworkVar_m_bMeasurePerf> *p_m_bMeasurePerf; // esi
  edict_t *m_pPev; // ecx

  p_m_bMeasurePerf = &this->m_bMeasurePerf;
  if ( this->m_bMeasurePerf.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_bMeasurePerf->m_Value = false;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x355u);
      p_m_bMeasurePerf->m_Value = false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1040A6F0
// Name: CParticlePerformanceMonitor_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CParticlePerformanceMonitor_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CParticlePerformanceMonitor>(__formal: nullptr);
  CParticlePerformanceMonitor_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040A720
// Name: DT_ParticlePerformanceMonitor::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_ParticlePerformanceMonitor::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_ParticlePerformanceMonitor::g_SendTable);
  return atexit(func: DT_ParticlePerformanceMonitor::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1040A740
// Name: DT_ParticlePerformanceMonitor::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_ParticlePerformanceMonitor::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_ParticlePerformanceMonitor::ignored>();
  DT_ParticlePerformanceMonitor::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041E200
// Name: DT_ParticlePerformanceMonitor::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_ParticlePerformanceMonitor::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_ParticlePerformanceMonitor::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10224E90
// Name: struct datamap_t __near * DataMapInit<class CParticlePerformanceMonitor>(class CParticlePerformanceMonitor __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CParticlePerformanceMonitor>()
{
  if ( (_S2_211 & 1) == 0 )
  {
    _S2_211 |= 1u;
    nameHolder_401.m_pszBase = "CParticlePerformanceMonitor";
    nameHolder_401.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_401.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_401.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_401.m_Names.m_Size = 0;
    nameHolder_401.m_Names.m_pElements = nullptr;
    nameHolder_401.m_nLenBase = 27;
    atexit(func: DataMapInit_CParticlePerformanceMonitor__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CParticlePerformanceMonitor::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CParticlePerformanceMonitor::m_DataMap.dataNumFields = 6;
  CParticlePerformanceMonitor::m_DataMap.dataDesc = &dataDesc_381[1];
  return &CParticlePerformanceMonitor::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10224F10
// Name: __CreateCServerGameTagsIServerGameTags_interface_5
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerGameTags *__cdecl _CreateCServerGameTagsIServerGameTags_interface_5()
{
  return &_g_CServerGameTags_singleton_5;
}

//------------------------------------------------------------------------------
// Address: 0x1040A700
// Name: _dynamic_initializer_for__g_CParticlePerformanceMonitor_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CParticlePerformanceMonitor_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CParticlePerformanceMonitor_ClassReg,
           pNetworkName: "CParticlePerformanceMonitor",
           pTable: &DT_ParticlePerformanceMonitor::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1040A750
// Name: _dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___5
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___5()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerGameTagsIServerGameTags_reg_5,
           fn: (void *(__cdecl *)())_CreateCServerGameTagsIServerGameTags_interface_5,
           pName: "ServerGameTags001");
}

//------------------------------------------------------------------------------
// Address: 0x1041E210
// Name: _ServerClassInit_DT_ParticlePerformanceMonitor::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_ParticlePerformanceMonitor::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_122;
  for ( i = 3; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041E230
// Name: _DataMapInit_CParticlePerformanceMonitor__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CParticlePerformanceMonitor__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_401);
}
