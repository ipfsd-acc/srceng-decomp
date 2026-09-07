// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/spotlightend.cpp
// Functions: 21
// ============================================================

#include "game\server\spotlightend.h"

//------------------------------------------------------------------------------
// Address: 0x1006C0E0
// Name: public: virtual int CSpotlightEnd::ObjectCaps(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSpotlightEnd::ObjectCaps(CAI_NetworkManager *this)
{
  return CBaseEntity::ObjectCaps(this) & 0x7FFFFF7F | 0x80000000;
}

//------------------------------------------------------------------------------
// Address: 0x10222F80
// Name: public: virtual class ServerClass __near * CSpotlightEnd::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CSpotlightEnd::GetServerClass(CSpotlightEnd *this)
{
  return &g_CSpotlightEnd_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10222F90
// Name: private: virtual struct datamap_t __near * CSpotlightEnd::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CSpotlightEnd::GetDataDescMap(CSpotlightEnd *this)
{
  return &CSpotlightEnd::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102230F0
// Name: public: virtual void CSpotlightEnd::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpotlightEnd::Spawn(CSpotlightEnd *this)
{
  edict_t *m_pPev; // ecx

  this->Precache(this);
  if ( this->m_flLightScale.m_Value != 100.0 )
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
    this->m_flLightScale.m_Value = 100.0;
  }
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  UTIL_SetSize(pEnt: this, vecMin: &vec3_origin, vecMax: &vec3_origin);
  this->m_iEFlags |= 0x80u;
  CBaseEntity::DispatchUpdateTransmitState(this);
}

//------------------------------------------------------------------------------
// Address: 0x104019C0
// Name: _dynamic_initializer_for__light_dynamic__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__light_dynamic__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CDynamicLight> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &light_dynamic,
           a3: "light_dynamic");
}

//------------------------------------------------------------------------------
// Address: 0x10405600
// Name: _dynamic_initializer_for__light__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__light__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CLight> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &light,
           a3: "light");
}

//------------------------------------------------------------------------------
// Address: 0x10405630
// Name: _dynamic_initializer_for__light_spot__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__light_spot__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CLight> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &light_spot,
           a3: "light_spot");
}

//------------------------------------------------------------------------------
// Address: 0x10405650
// Name: _dynamic_initializer_for__light_glspot__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__light_glspot__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CLight> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &light_glspot,
           a3: "light_glspot");
}

//------------------------------------------------------------------------------
// Address: 0x10405670
// Name: _dynamic_initializer_for__light_directional__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__light_directional__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CLight> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &light_directional,
           a3: "light_directional");
}

//------------------------------------------------------------------------------
// Address: 0x10405690
// Name: _dynamic_initializer_for__light_environment__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__light_environment__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CEnvLight> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &light_environment,
           a3: "light_environment");
}

//------------------------------------------------------------------------------
// Address: 0x1040A520
// Name: _dynamic_initializer_for__spotlight_end__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__spotlight_end__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CSpotlightEnd> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &spotlight_end,
           a3: "spotlight_end");
}

//------------------------------------------------------------------------------
// Address: 0x1040A560
// Name: DT_SpotlightEnd::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_SpotlightEnd::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_SpotlightEnd::g_SendTable);
  return atexit(func: DT_SpotlightEnd::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1040A580
// Name: DT_SpotlightEnd::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_SpotlightEnd::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_SpotlightEnd::ignored>();
  DT_SpotlightEnd::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040A590
// Name: CSpotlightEnd_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CSpotlightEnd_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CSpotlightEnd>(__formal: nullptr);
  CSpotlightEnd_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041E150
// Name: DT_SpotlightEnd::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_SpotlightEnd::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_SpotlightEnd::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10223190
// Name: struct datamap_t __near * DataMapInit<class CSpotlightEnd>(class CSpotlightEnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CSpotlightEnd>()
{
  if ( (_S3_120 & 1) == 0 )
  {
    _S3_120 |= 1u;
    nameHolder_399.m_pszBase = "CSpotlightEnd";
    nameHolder_399.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_399.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_399.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_399.m_Names.m_Size = 0;
    nameHolder_399.m_Names.m_pElements = nullptr;
    nameHolder_399.m_nLenBase = 13;
    atexit(func: DataMapInit_CSpotlightEnd__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CSpotlightEnd::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CSpotlightEnd::m_DataMap.dataNumFields = 4;
  CSpotlightEnd::m_DataMap.dataDesc = &dataDesc_379[1];
  return &CSpotlightEnd::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1040A540
// Name: _dynamic_initializer_for__g_CSpotlightEnd_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CSpotlightEnd_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CSpotlightEnd_ClassReg,
           pNetworkName: "CSpotlightEnd",
           pTable: &DT_SpotlightEnd::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1040A5A0
// Name: _dynamic_initializer_for__env_glow__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_glow__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CSprite> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_glow,
           a3: "env_glow");
}

//------------------------------------------------------------------------------
// Address: 0x1040A5C0
// Name: _dynamic_initializer_for__env_sprite_clientside__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_sprite_clientside__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CSprite> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_sprite_clientside,
           a3: "env_sprite_clientside");
}

//------------------------------------------------------------------------------
// Address: 0x1041E160
// Name: _ServerClassInit_DT_SpotlightEnd::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_SpotlightEnd::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_209;
  for ( i = 3; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041E180
// Name: _DataMapInit_CSpotlightEnd__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CSpotlightEnd__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_399);
}
