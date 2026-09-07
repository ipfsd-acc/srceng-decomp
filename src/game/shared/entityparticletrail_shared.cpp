// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/entityparticletrail_shared.cpp
// Functions: 6
// ============================================================

#include "game\shared\entityparticletrail_shared.h"

//------------------------------------------------------------------------------
// Address: 0x100D18B0
// Name: public: EntityParticleTrailInfo_t::EntityParticleTrailInfo_t(void)
// Source: json
//------------------------------------------------------------------------------
EntityParticleTrailInfo_t *__thiscall EntityParticleTrailInfo_t::EntityParticleTrailInfo_t(
        EntityParticleTrailInfo_t *this)
{
  float m_Value; // xmm0_4
  CNetworkVarBase<float,EntityParticleTrailInfo_t::NetworkVar_m_flLifetime> *p_m_flLifetime; // edi

  m_Value = this->m_flLifetime.m_Value;
  p_m_flLifetime = &this->m_flLifetime;
  this->__vftable = (EntityParticleTrailInfo_t_vtbl *)&EntityParticleTrailInfo_t::`vftable';
  this->m_strMaterialName = nullptr;
  if ( m_Value != 4.0 )
  {
    this->NetworkStateChanged(this, a2: &this->m_flLifetime);
    p_m_flLifetime->m_Value = 4.0;
  }
  if ( this->m_flStartSize.m_Value != 2.0 )
  {
    this->NetworkStateChanged(this, a2: &this->m_flStartSize);
    this->m_flStartSize.m_Value = 2.0;
  }
  if ( this->m_flEndSize.m_Value != 3.0 )
  {
    this->NetworkStateChanged(this, a2: &this->m_flEndSize);
    this->m_flEndSize.m_Value = 3.0;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10415570
// Name: DT_EntityParticleTrailInfo::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_EntityParticleTrailInfo::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_EntityParticleTrailInfo::g_RecvTable);
  return atexit(func: DT_EntityParticleTrailInfo::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10415590
// Name: DT_EntityParticleTrailInfo::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_EntityParticleTrailInfo::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_EntityParticleTrailInfo::ignored>();
  DT_EntityParticleTrailInfo::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10431530
// Name: DT_EntityParticleTrailInfo::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_EntityParticleTrailInfo::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_EntityParticleTrailInfo::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x104155A0
// Name: _dynamic_initializer_for____g_C_EnvDetailControllerClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_EnvDetailControllerClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_EnvDetailControllerClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_EnvDetailControllerClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104155C0
// Name: _dynamic_initializer_for__g_Cenv_detail_controllerFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Cenv_detail_controllerFoo__()
{
  CClassMap *ClassMap; // eax
  int result; // eax

  ClassMap = GetClassMap();
  result = ((int (__thiscall *)(CClassMap *, const char *, const char *, int, C_EnvDetailController *(__cdecl *)()))ClassMap->Add)(
             a1: ClassMap,
             a2: "env_detail_controller",
             a3: "C_EnvDetailController",
             a4: 2440,
             a5: CC_EnvDetailControllerFactory);
  __g_C_EnvDetailControllerClientClass.m_pMapClassname = "env_detail_controller";
  return result;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10110970
// Name: public: EntityParticleTrailInfo_t::EntityParticleTrailInfo_t(void)
// Source: json
//------------------------------------------------------------------------------
EntityParticleTrailInfo_t *__thiscall EntityParticleTrailInfo_t::EntityParticleTrailInfo_t(
        EntityParticleTrailInfo_t *this)
{
  CNetworkVarBase<float,EntityParticleTrailInfo_t::NetworkVar_m_flLifetime> *p_m_flLifetime; // edi

  p_m_flLifetime = &this->m_flLifetime;
  this->__vftable = (EntityParticleTrailInfo_t_vtbl *)&EntityParticleTrailInfo_t::`vftable';
  this->m_strMaterialName.pszValue = nullptr;
  if ( this->m_flLifetime.m_Value != 4.0 )
  {
    this->NetworkStateChanged(this, a2: &this->m_flLifetime);
    p_m_flLifetime->m_Value = 4.0;
  }
  if ( this->m_flStartSize.m_Value != 2.0 )
  {
    this->NetworkStateChanged(this, a2: &this->m_flStartSize);
    this->m_flStartSize.m_Value = 2.0;
  }
  if ( this->m_flEndSize.m_Value != 3.0 )
  {
    this->NetworkStateChanged(this, a2: &this->m_flEndSize);
    this->m_flEndSize.m_Value = 3.0;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10402500
// Name: EntityParticleTrailInfo_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *EntityParticleTrailInfo_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<EntityParticleTrailInfo_t>();
  EntityParticleTrailInfo_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10402510
// Name: DT_EntityParticleTrailInfo::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_EntityParticleTrailInfo::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_EntityParticleTrailInfo::g_SendTable);
  return atexit(func: DT_EntityParticleTrailInfo::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10402530
// Name: DT_EntityParticleTrailInfo::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_EntityParticleTrailInfo::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_EntityParticleTrailInfo::ignored>();
  DT_EntityParticleTrailInfo::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10406A30
// Name: _dynamic_initializer_for__particle_test_file__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__particle_test_file__()
{
  ConVar::ConVar(
    this: &particle_test_file,
    pName: "particle_test_file",
    pDefaultValue: locale,
    flags: 0x4000,
    pHelpString: "Name of the particle system to dynamically spawn");
  return atexit(func: dynamic_atexit_destructor_for__particle_test_file__);
}

//------------------------------------------------------------------------------
// Address: 0x10406A60
// Name: _dynamic_initializer_for__particle_test_attach_mode__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__particle_test_attach_mode__()
{
  ConVar::ConVar(
    this: &particle_test_attach_mode,
    pName: "particle_test_attach_mode",
    pDefaultValue: "follow_attachment",
    flags: 0x4000,
    pHelpString: "Possible Values: 'start_at_attachment', 'follow_attachment', 'start_at_origin', 'follow_origin'");
  return atexit(func: dynamic_atexit_destructor_for__particle_test_attach_mode__);
}

//------------------------------------------------------------------------------
// Address: 0x10406A90
// Name: _dynamic_initializer_for__particle_test_attach_attachment__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__particle_test_attach_attachment__()
{
  ConVar::ConVar(
    this: &particle_test_attach_attachment,
    pName: "particle_test_attach_attachment",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Attachment index for attachment mode");
  return atexit(func: dynamic_atexit_destructor_for__particle_test_attach_attachment__);
}

//------------------------------------------------------------------------------
// Address: 0x10406AC0
// Name: _dynamic_initializer_for__particle_test_start__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__particle_test_start__()
{
  ConCommand::ConCommand(
    this: &particle_test_start,
    pName: "particle_test_start",
    callback: (void (__cdecl *)())CC_Particle_Test_Start,
    pHelpString: "Dispatches the test particle system with the parameters specified in particle_test_file,\n"
    " particle_test_attach_mode and particle_test_attach_param on the entity the player is looking at.\n"
    "\tArguments:   \t{entity_name} / {class_name} / no argument picks what player is looking at ",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__particle_test_start__);
}

//------------------------------------------------------------------------------
// Address: 0x10406AF0
// Name: _dynamic_initializer_for__particle_test_stop__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__particle_test_stop__()
{
  ConCommand::ConCommand(
    this: &particle_test_stop,
    pName: "particle_test_stop",
    callback: (void (__cdecl *)())CC_Particle_Test_Stop,
    pHelpString: "Stops all particle systems on the selected entities.\n"
    "\tArguments:   \t{entity_name} / {class_name} / no argument picks what player is looking at ",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__particle_test_stop__);
}

//------------------------------------------------------------------------------
// Address: 0x1041ACD0
// Name: DT_EntityParticleTrailInfo::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_EntityParticleTrailInfo::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_EntityParticleTrailInfo::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041C870
// Name: _dynamic_atexit_destructor_for__particle_test_file__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__particle_test_file__()
{
  ConVar::~ConVar(this: &particle_test_file);
}

//------------------------------------------------------------------------------
// Address: 0x1041C880
// Name: _dynamic_atexit_destructor_for__particle_test_attach_mode__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__particle_test_attach_mode__()
{
  ConVar::~ConVar(this: &particle_test_attach_mode);
}

//------------------------------------------------------------------------------
// Address: 0x1041C890
// Name: _dynamic_atexit_destructor_for__particle_test_attach_attachment__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__particle_test_attach_attachment__()
{
  ConVar::~ConVar(this: &particle_test_attach_attachment);
}

//------------------------------------------------------------------------------
// Address: 0x1041C8A0
// Name: _dynamic_atexit_destructor_for__particle_test_start__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__particle_test_start__()
{
  ConCommand::~ConCommand(this: &particle_test_start);
}

//------------------------------------------------------------------------------
// Address: 0x1041C8B0
// Name: _dynamic_atexit_destructor_for__particle_test_stop__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__particle_test_stop__()
{
  ConCommand::~ConCommand(this: &particle_test_stop);
}

//------------------------------------------------------------------------------
// Address: 0x10402540
// Name: _dynamic_initializer_for__env_ambient_light__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_ambient_light__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CEnvAmbientLight> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_ambient_light,
           a3: "env_ambient_light");
}

//------------------------------------------------------------------------------
// Address: 0x10406B20
// Name: _dynamic_initializer_for__g_CParticleSystem_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CParticleSystem_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CParticleSystem_ClassReg,
           pNetworkName: "CParticleSystem",
           pTable: &DT_ParticleSystem::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041ACE0
// Name: _ServerClassInit_DT_EntityParticleTrailInfo::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_EntityParticleTrailInfo::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_46;
  for ( i = 3; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041AD00
// Name: _DataMapInit_EntityParticleTrailInfo_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_EntityParticleTrailInfo_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_156);
}

} // namespace server
