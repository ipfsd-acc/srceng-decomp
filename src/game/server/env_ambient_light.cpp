// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/env_ambient_light.cpp
// Functions: 15
// ============================================================

#include "game\server\env_ambient_light.h"

//------------------------------------------------------------------------------
// Address: 0x10110A90
// Name: public: virtual struct datamap_t __near * CEnvAmbientLight::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CEnvAmbientLight::GetDataDescMap(CEnvAmbientLight *this)
{
  return &CEnvAmbientLight::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10110AA0
// Name: public: virtual class ServerClass __near * CEnvAmbientLight::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CEnvAmbientLight::GetServerClass(CEnvAmbientLight *this)
{
  return &g_CEnvAmbientLight_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10110B70
// Name: public: virtual void CEnvAmbientLight::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvAmbientLight::Spawn(CEnvAmbientLight *this)
{
  float v2; // xmm0_4
  edict_t *m_pPev; // ecx
  float v4; // xmm0_4
  edict_t *v5; // ecx
  float v6; // xmm0_4
  edict_t *v7; // ecx

  CSpatialEntity::Spawn(this);
  v2 = (float)this->m_Color.r * 0.0039215689;
  if ( this->m_vecColor.m_Value.x != v2 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x388u);
    }
    this->m_vecColor.m_Value.x = v2;
  }
  v4 = (float)this->m_Color.g * 0.0039215689;
  if ( this->m_vecColor.m_Value.y != v4 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v5 = this->m_Network.m_pPev;
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x388u);
    }
    this->m_vecColor.m_Value.y = v4;
  }
  v6 = (float)this->m_Color.b * 0.0039215689;
  if ( this->m_vecColor.m_Value.z != v6 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_vecColor.m_Value.z = v6;
    }
    else
    {
      v7 = this->m_Network.m_pPev;
      if ( v7 != nullptr )
        CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: 0x388u);
      this->m_vecColor.m_Value.z = v6;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10110CB0
// Name: public: void CEnvAmbientLight::InputSetColor(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvAmbientLight::InputSetColor(CEnvAmbientLight *this, inputdata_t *inputdata)
{
  const char *pszValue; // eax
  float v4; // xmm0_4
  edict_t *m_pPev; // ecx
  float v6; // xmm0_4
  edict_t *v7; // ecx
  float v8; // xmm0_4
  edict_t *v9; // ecx

  pszValue = inputdata->value.iszVal.pszValue;
  this->m_Color = (color32_s)pszValue;
  v4 = (float)(unsigned __int8)pszValue * 0.0039215689;
  if ( this->m_vecColor.m_Value.x != v4 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x388u);
    }
    this->m_vecColor.m_Value.x = v4;
  }
  v6 = (float)this->m_Color.g * 0.0039215689;
  if ( this->m_vecColor.m_Value.y != v6 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v7 = this->m_Network.m_pPev;
      if ( v7 != nullptr )
        CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: 0x388u);
    }
    this->m_vecColor.m_Value.y = v6;
  }
  v8 = (float)this->m_Color.b * 0.0039215689;
  if ( this->m_vecColor.m_Value.z != v8 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_vecColor.m_Value.z = v8;
    }
    else
    {
      v9 = this->m_Network.m_pPev;
      if ( v9 != nullptr )
        CBaseEdict::StateChanged(this: &v9->CBaseEdict, offset: 0x388u);
      this->m_vecColor.m_Value.z = v8;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10402560
// Name: CEnvAmbientLight_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CEnvAmbientLight_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CEnvAmbientLight>(__formal: nullptr);
  CEnvAmbientLight_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10402590
// Name: DT_EnvAmbientLight::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_EnvAmbientLight::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_EnvAmbientLight::g_SendTable);
  return atexit(func: DT_EnvAmbientLight::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104025B0
// Name: DT_EnvAmbientLight::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_EnvAmbientLight::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_EnvAmbientLight::ignored>();
  DT_EnvAmbientLight::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041AD10
// Name: DT_EnvAmbientLight::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_EnvAmbientLight::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_EnvAmbientLight::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10110DF0
// Name: struct datamap_t __near * DataMapInit<class CEnvAmbientLight>(class CEnvAmbientLight __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CEnvAmbientLight>()
{
  if ( (_S2_79 & 1) == 0 )
  {
    _S2_79 |= 1u;
    nameHolder_157.m_pszBase = "CEnvAmbientLight";
    nameHolder_157.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_157.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_157.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_157.m_Names.m_Size = 0;
    nameHolder_157.m_Names.m_pElements = nullptr;
    nameHolder_157.m_nLenBase = 16;
    atexit(func: DataMapInit_CEnvAmbientLight__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CEnvAmbientLight::m_DataMap.baseMap = &CSpatialEntity::m_DataMap;
  CEnvAmbientLight::m_DataMap.dataNumFields = 3;
  CEnvAmbientLight::m_DataMap.dataDesc = &dataDesc_149[1];
  return &CEnvAmbientLight::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10402570
// Name: _dynamic_initializer_for__g_CEnvAmbientLight_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CEnvAmbientLight_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CEnvAmbientLight_ClassReg,
           pNetworkName: "CEnvAmbientLight",
           pTable: &DT_EnvAmbientLight::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041AD20
// Name: _ServerClassInit_DT_EnvAmbientLight::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_EnvAmbientLight::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_47;
  for ( i = 2; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041AD40
// Name: _DataMapInit_CEnvAmbientLight__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CEnvAmbientLight__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_157);
}

//------------------------------------------------------------------------------
// Address: 0x1041AD50
// Name: _dynamic_atexit_destructor_for__dbghist_addline__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__dbghist_addline__()
{
  ConCommand::~ConCommand(this: &dbghist_addline);
}

//------------------------------------------------------------------------------
// Address: 0x1041AD60
// Name: _dynamic_atexit_destructor_for__dbghist_dump__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__dbghist_dump__()
{
  ConCommand::~ConCommand(this: &dbghist_dump);
}

//------------------------------------------------------------------------------
// Address: 0x1041AD70
// Name: _DataMapInit_CDebugHistory__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CDebugHistory__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_158);
}
