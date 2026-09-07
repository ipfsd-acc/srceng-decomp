// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/lightglow.cpp
// Functions: 21
// ============================================================

#include "game\server\lightglow.h"

//------------------------------------------------------------------------------
// Address: 0x101645B0
// Name: public: virtual class ServerClass __near * CLightGlow::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CLightGlow::GetServerClass(CLightGlow *this)
{
  return &g_CLightGlow_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x101645C0
// Name: public: virtual struct datamap_t __near * CLightGlow::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CLightGlow::GetDataDescMap(CLightGlow *this)
{
  return &CLightGlow::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101645D0
// Name: public: virtual void CLightGlow::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLightGlow::Spawn(CLightGlow *this)
{
  CAI_BaseNPC::OnSetSchedule((vgui::Panel *)this);
  this->m_iEFlags |= 0x80u;
  CBaseEntity::DispatchUpdateTransmitState(this);
}

//------------------------------------------------------------------------------
// Address: 0x10164850
// Name: public: CLightGlow::CLightGlow(void)
// Source: json
//------------------------------------------------------------------------------
CLightGlow *__thiscall CLightGlow::CLightGlow(CLightGlow *this)
{
  edict_t *m_pPev; // ecx
  edict_t *v3; // ecx
  edict_t *v4; // ecx
  edict_t *v5; // ecx
  CLightGlow *result; // eax
  edict_t *v7; // ecx

  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->__vftable = (CLightGlow_vtbl *)&CLightGlow::`vftable';
  if ( this->m_nHorizontalSize.m_Value != 0 )
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
    this->m_nHorizontalSize.m_Value = 0;
  }
  if ( this->m_nVerticalSize.m_Value != 0 )
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
    this->m_nVerticalSize.m_Value = 0;
  }
  if ( this->m_nMinDist.m_Value != 0 )
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
    this->m_nMinDist.m_Value = 0;
  }
  if ( this->m_nMaxDist.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v5 = this->m_Network.m_pPev;
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x360u);
    }
    this->m_nMaxDist.m_Value = 0;
  }
  result = this;
  if ( this->m_flGlowProxySize.m_Value != 2.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v7 = this->m_Network.m_pPev;
      if ( v7 != nullptr )
        CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: 0x368u);
    }
    this->m_flGlowProxySize.m_Value = 2.0;
    return this;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10164990
// Name: public: virtual void CLightGlow::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLightGlow::Activate(CLightGlow *this)
{
  int m_Value; // eax
  edict_t *m_pPev; // ecx
  int v4; // eax
  edict_t *v5; // ecx

  CBaseEntity::Activate(this);
  m_Value = this->m_nMaxDist.m_Value;
  if ( m_Value > 0xFFFF )
  {
    _Warning(a1: "env_lightglow maxdist too large (%d should be %d).\n", m_Value, 0xFFFF);
    if ( this->m_nMaxDist.m_Value != 0xFFFF )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x360u);
      }
      this->m_nMaxDist.m_Value = 0xFFFF;
    }
  }
  v4 = this->m_nOuterMaxDist.m_Value;
  if ( v4 > 0xFFFF )
  {
    _Warning(a1: "env_lightglow outermaxdist too large (%d should be %d).\n", v4, 0xFFFF);
    if ( this->m_nOuterMaxDist.m_Value != 0xFFFF )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_nOuterMaxDist.m_Value = 0xFFFF;
      }
      else
      {
        v5 = this->m_Network.m_pPev;
        if ( v5 != nullptr )
          CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x364u);
        this->m_nOuterMaxDist.m_Value = 0xFFFF;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10164A60
// Name: public: void CLightGlow::InputColor(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLightGlow::InputColor(CLightGlow *this, inputdata_t *inputdata)
{
  const char *pszValue; // ebx
  CNetworkColor32Base<color32_s,CBaseEntity::NetworkVar_m_clrRender> *p_m_clrRender; // esi
  edict_t *m_pPev; // ecx

  pszValue = inputdata->value.iszVal.pszValue;
  p_m_clrRender = &this->m_clrRender;
  if ( *(_WORD *)&this->m_clrRender.m_Value.r != (_WORD)pszValue
    || this->m_clrRender.m_Value.b != BYTE2(pszValue)
    || this->m_clrRender.m_Value.a != HIBYTE(pszValue) )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      *p_m_clrRender = (CNetworkColor32Base<color32_s,CBaseEntity::NetworkVar_m_clrRender>)pszValue;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xB8u);
      *p_m_clrRender = (CNetworkColor32Base<color32_s,CBaseEntity::NetworkVar_m_clrRender>)pszValue;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104055A0
// Name: DT_LightGlow::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_LightGlow::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_LightGlow::g_SendTable);
  return atexit(func: DT_LightGlow::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104055C0
// Name: DT_LightGlow::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_LightGlow::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_LightGlow::ignored>();
  DT_LightGlow::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104055F0
// Name: CLightGlow_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CLightGlow_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CLightGlow>();
  CLightGlow_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041C150
// Name: DT_LightGlow::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_LightGlow::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_LightGlow::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x104055D0
// Name: _dynamic_initializer_for__env_lightglow__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_lightglow__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CLightGlow> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_lightglow,
           a3: "env_lightglow");
}

//------------------------------------------------------------------------------
// Address: 0x1041C160
// Name: _ServerClassInit_DT_LightGlow::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_LightGlow::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_140;
  for ( i = 12; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041C180
// Name: _DataMapInit_CLightGlow__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CLightGlow__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_243);
}

//------------------------------------------------------------------------------
// Address: 0x1041C190
// Name: _DataMapInit_CLight__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CLight__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_244);
}

//------------------------------------------------------------------------------
// Address: 0x1041C1A0
// Name: _DataMapInit_CLogicEventListener__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CLogicEventListener__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_245);
}

//------------------------------------------------------------------------------
// Address: 0x1041C1B0
// Name: _DataMapInit_CLogicMeasureMovement__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CLogicMeasureMovement__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_246);
}

//------------------------------------------------------------------------------
// Address: 0x1041C1C0
// Name: _DataMapInit_CLogicNavigation__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CLogicNavigation__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_247);
}

//------------------------------------------------------------------------------
// Address: 0x1041C1D0
// Name: _DataMapInit_CLogicPlayerProxy__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CLogicPlayerProxy__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_248);
}

//------------------------------------------------------------------------------
// Address: 0x1041C1E0
// Name: _DataMapInit_CLogicPlayMovie__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CLogicPlayMovie__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_249);
}

//------------------------------------------------------------------------------
// Address: 0x1041C1F0
// Name: _DataMapInit_CLogicRandomOutputs__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CLogicRandomOutputs__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_250);
}

//------------------------------------------------------------------------------
// Address: 0x1041C200
// Name: _DataMapInit_CLogicAuto__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CLogicAuto__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_251);
}
