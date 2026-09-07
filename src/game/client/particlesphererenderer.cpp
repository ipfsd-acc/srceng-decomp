// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/particlesphererenderer.cpp
// Functions: 61
// ============================================================

#include "game\client\particlesphererenderer.h"

//------------------------------------------------------------------------------
// Address: 0x1026D6F0
// Name: public: void CParticleSphereRenderer::Init(class CParticleMgr __near *,class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSphereRenderer::Init(
        CParticleSphereRenderer *this,
        CParticleMgr *pParticleMgr,
        IMaterial *pMaterial)
{
  IMaterial *v4; // ecx
  IMaterialVar *(__thiscall *FindVar)(IMaterial *, const char *, bool *, bool); // edx
  int v6; // eax

  v4 = pMaterial;
  this->m_pParticleMgr = pParticleMgr;
  FindVar = v4->FindVar;
  HIBYTE(pParticleMgr) = 0;
  v6 = (int)FindVar(this: v4, a2: "$USINGPIXELSHADER", a3: (bool *)&pParticleMgr + 3, a4: false);
  this->m_bUsingPixelShaders = HIBYTE(pParticleMgr) != 0
                            && v6 != 0
                            && (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 108))(a1: v6) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1026D740
// Name: public: void CParticleSphereRenderer::StartRender(class VMatrix __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSphereRenderer::StartRender(CParticleSphereRenderer *this, VMatrix *effectMatrix)
{
  CParticleMgr *m_pParticleMgr; // ecx

  m_pParticleMgr = this->m_pParticleMgr;
  if ( m_pParticleMgr != nullptr )
    CParticleMgr::SetDirectionalLightInfo(this: m_pParticleMgr, info: &this->m_DirectionalLight);
  this->m_iLastTickStartRenderCalled = *(_DWORD *)(gpGlobals.m_Index + 24);
}

//------------------------------------------------------------------------------
// Address: 0x1026D770
// Name: public: CParticleSphereRenderer::CParticleSphereRenderer(void)
// Source: json
//------------------------------------------------------------------------------
CParticleSphereRenderer *__thiscall CParticleSphereRenderer::CParticleSphereRenderer(CParticleSphereRenderer *this)
{
  this->m_vBaseColor.x = 0.0;
  this->m_vBaseColor.y = 0.0;
  this->m_vBaseColor.z = 0.0;
  *(_QWORD *)&this->m_AmbientLight.m_vPos.x = 0;
  *(_QWORD *)&this->m_AmbientLight.m_vPos.z = 0;
  *(_QWORD *)&this->m_AmbientLight.m_vColor.y = 0;
  this->m_AmbientLight.m_flIntensity = 0.0;
  *(_QWORD *)&this->m_DirectionalLight.m_vPos.x = 0;
  *(_QWORD *)&this->m_DirectionalLight.m_vPos.z = 0;
  *(_QWORD *)&this->m_DirectionalLight.m_vColor.y = 0;
  this->m_DirectionalLight.m_flIntensity = 0.0;
  this->m_bUsingPixelShaders = false;
  this->m_iLastTickStartRenderCalled = -1;
  this->m_pParticleMgr = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1041AD20
// Name: _dynamic_initializer_for__particle_simulateoverflow__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__particle_simulateoverflow__()
{
  ConVar::ConVar(
    this: &particle_simulateoverflow,
    pName: "particle_simulateoverflow",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Used for stress-testing particle systems. Randomly denies creation of particles.");
  return atexit(func: dynamic_atexit_destructor_for__particle_simulateoverflow__);
}

//------------------------------------------------------------------------------
// Address: 0x1041AED0
// Name: _dynamic_initializer_for__particle_sim_alt_cores__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__particle_sim_alt_cores__()
{
  ConVar::ConVar(this: &particle_sim_alt_cores, pName: "particle_sim_alt_cores", pDefaultValue: "2", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__particle_sim_alt_cores__);
}

//------------------------------------------------------------------------------
// Address: 0x10433000
// Name: _dynamic_atexit_destructor_for__particle_simulateoverflow__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__particle_simulateoverflow__()
{
  ConVar::~ConVar(this: &particle_simulateoverflow);
}

//------------------------------------------------------------------------------
// Address: 0x10433090
// Name: _dynamic_atexit_destructor_for__particle_sim_alt_cores__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__particle_sim_alt_cores__()
{
  ConVar::~ConVar(this: &particle_sim_alt_cores);
}

//------------------------------------------------------------------------------
// Address: 0x1041AD50
// Name: _dynamic_initializer_for__cl_particles_show_bbox__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_particles_show_bbox__()
{
  ConVar::ConVar(this: &cl_particles_show_bbox, pName: "cl_particles_show_bbox", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__cl_particles_show_bbox__);
}

//------------------------------------------------------------------------------
// Address: 0x1041AD80
// Name: _dynamic_initializer_for__cl_particle_fallback_multiplier__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_particle_fallback_multiplier__()
{
  ConVar::ConVar(
    this: &cl_particle_fallback_multiplier,
    pName: "cl_particle_fallback_multiplier",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Multiplier for falling back to cheaper effects under load.");
  return atexit(func: dynamic_atexit_destructor_for__cl_particle_fallback_multiplier__);
}

//------------------------------------------------------------------------------
// Address: 0x1041ADB0
// Name: _dynamic_initializer_for__cl_particle_fallback_base__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_particle_fallback_base__()
{
  ConVar::ConVar(
    this: &cl_particle_fallback_base,
    pName: "cl_particle_fallback_base",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Base for falling back to cheaper effects under load.");
  return atexit(func: dynamic_atexit_destructor_for__cl_particle_fallback_base__);
}

//------------------------------------------------------------------------------
// Address: 0x1041ADE0
// Name: _dynamic_initializer_for__cl_particle_sim_fallback_threshold_ms__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_particle_sim_fallback_threshold_ms__()
{
  ConVar::ConVar(
    this: &cl_particle_sim_fallback_threshold_ms,
    pName: "cl_particle_sim_fallback_threshold_ms",
    pDefaultValue: "6.0",
    flags: 0,
    pHelpString: "Amount of simulation time that can elapse before new systems start falling back to cheaper versions");
  return atexit(func: dynamic_atexit_destructor_for__cl_particle_sim_fallback_threshold_ms__);
}

//------------------------------------------------------------------------------
// Address: 0x1041AE10
// Name: _dynamic_initializer_for__cl_particle_sim_fallback_base_multiplier__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_particle_sim_fallback_base_multiplier__()
{
  ConVar::ConVar(
    this: &cl_particle_sim_fallback_base_multiplier,
    pName: "cl_particle_sim_fallback_base_multiplier",
    pDefaultValue: "5",
    flags: 0,
    pHelpString: "How aggressive the switch to fallbacks will be depending on how far over the cl_particle_sim_fallback_threshold_ms t"
    "he sim time is.  Higher numbers are more aggressive.");
  return atexit(func: dynamic_atexit_destructor_for__cl_particle_sim_fallback_base_multiplier__);
}

//------------------------------------------------------------------------------
// Address: 0x1041AE40
// Name: _dynamic_initializer_for__r_particle_sim_spike_threshold_ms__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_particle_sim_spike_threshold_ms__()
{
  ConVar::ConVar(
    this: &r_particle_sim_spike_threshold_ms,
    pName: "r_particle_sim_spike_threshold_ms",
    pDefaultValue: "0",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_particle_sim_spike_threshold_ms__);
}

//------------------------------------------------------------------------------
// Address: 0x1041AE70
// Name: _dynamic_initializer_for__r_threaded_particles__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_threaded_particles__()
{
  ConVar::ConVar(this: &r_threaded_particles, pName: "r_threaded_particles", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_threaded_particles__);
}

//------------------------------------------------------------------------------
// Address: 0x1041AEA0
// Name: _dynamic_initializer_for__cl_particle_retire_cost__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_particle_retire_cost__()
{
  ConVar::ConVar(this: &cl_particle_retire_cost, pName: "cl_particle_retire_cost", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__cl_particle_retire_cost__);
}

//------------------------------------------------------------------------------
// Address: 0x1041AF00
// Name: _dynamic_initializer_for__r_particle_timescale__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_particle_timescale__()
{
  ConVar::ConVar(this: &r_particle_timescale, pName: "r_particle_timescale", pDefaultValue: "1.0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_particle_timescale__);
}

//------------------------------------------------------------------------------
// Address: 0x1041AF30
// Name: _dynamic_initializer_for__cl_particle_max_count__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_particle_max_count__()
{
  ConVar::ConVar(this: &cl_particle_max_count, pName: "cl_particle_max_count", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__cl_particle_max_count__);
}

//------------------------------------------------------------------------------
// Address: 0x1041AF60
// Name: _dynamic_initializer_for__cl_particles_dump_effects_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_particles_dump_effects_command__()
{
  ConCommand::ConCommand(
    this: &cl_particles_dump_effects_command,
    pName: "cl_particles_dump_effects",
    callback: cl_particles_dump_effects,
    pHelpString: prType,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cl_particles_dump_effects_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1041AF90
// Name: _dynamic_initializer_for__g_pSimpleSingleton__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_pSimpleSingleton__()
{
  g_pSimpleSingleton[0].m_pObj = nullptr;
  g_pSimpleSingleton[1].m_pObj = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__g_pSimpleSingleton__);
}

//------------------------------------------------------------------------------
// Address: 0x1041AFB0
// Name: _dynamic_initializer_for__g_pEmberSingleton__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_pEmberSingleton__()
{
  g_pEmberSingleton[0].m_pObj = nullptr;
  g_pEmberSingleton[1].m_pObj = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__g_pEmberSingleton__);
}

//------------------------------------------------------------------------------
// Address: 0x1041AFD0
// Name: _dynamic_initializer_for__g_pFireSmokeSingleton__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_pFireSmokeSingleton__()
{
  g_pFireSmokeSingleton[0].m_pObj = nullptr;
  g_pFireSmokeSingleton[1].m_pObj = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__g_pFireSmokeSingleton__);
}

//------------------------------------------------------------------------------
// Address: 0x1041B000
// Name: _dynamic_initializer_for__g_pFireSingleton__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_pFireSingleton__()
{
  g_pFireSingleton[0].m_pObj = nullptr;
  g_pFireSingleton[1].m_pObj = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__g_pFireSingleton__);
}

//------------------------------------------------------------------------------
// Address: 0x1041B020
// Name: _dynamic_initializer_for__g_EZParticleInit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_EZParticleInit__()
{
  CAutoGameSystem::CAutoGameSystem(this: &g_EZParticleInit, name: "CEZParticleInit");
  g_EZParticleInit.__vftable = (CEZParticleInit_vtbl *)&CEZParticleInit::`vftable';
  return atexit(func: dynamic_atexit_destructor_for__g_EZParticleInit__);
}

//------------------------------------------------------------------------------
// Address: 0x1041B050
// Name: _dynamic_initializer_for__cl_particles_show_controlpoints__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_particles_show_controlpoints__()
{
  ConVar::ConVar(
    this: &cl_particles_show_controlpoints,
    pName: "cl_particles_show_controlpoints",
    pDefaultValue: "0",
    flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__cl_particles_show_controlpoints__);
}

//------------------------------------------------------------------------------
// Address: 0x1041B080
// Name: _dynamic_initializer_for__cl_aggregate_particles__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_aggregate_particles__()
{
  ConVar::ConVar(this: &cl_aggregate_particles, pName: "cl_aggregate_particles", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__cl_aggregate_particles__);
}

//------------------------------------------------------------------------------
// Address: 0x1041B0B0
// Name: _dynamic_initializer_for__cl_dump_particle_stats__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_dump_particle_stats__()
{
  ConCommand::ConCommand(
    this: &cl_dump_particle_stats,
    pName: "cl_dump_particle_stats",
    callback: DumpParticleStats_f,
    pHelpString: "dump particle profiling info to particle_profile.csv",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cl_dump_particle_stats__);
}

//------------------------------------------------------------------------------
// Address: 0x1041B0E0
// Name: _dynamic_initializer_for__cl_particles_dumplist_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_particles_dumplist_command__()
{
  ConCommand::ConCommand(
    this: &cl_particles_dumplist_command,
    pName: "cl_particles_dumplist",
    callback: (void (__cdecl *)())cl_particles_dumplist,
    pHelpString: "Dump all new particles, optional name substring.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cl_particles_dumplist_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1041B110
// Name: _dynamic_initializer_for__g_ParticleEffects__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ParticleEffects__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_ParticleEffects__);
}

//------------------------------------------------------------------------------
// Address: 0x1041B120
// Name: _dynamic_initializer_for__g_EffectChecker__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_EffectChecker__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_EffectChecker__);
}

//------------------------------------------------------------------------------
// Address: 0x1041B130
// Name: _dynamic_initializer_for__g_CSimpleEmitter_RegistrationHelper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall dynamic_initializer_for__g_CSimpleEmitter_RegistrationHelper__(const char *a1@<edi>)
{
  CParticleMgr *v1; // eax
  const char *v2; // [esp-8h] [ebp-8h]

  v2 = type_info::name(this: &CSimpleEmitter `RTTI Type Descriptor', __ptype_info_node: &__type_info_root_node);
  v1 = ParticleMgr();
  CParticleMgr::RegisterEffect(
    this: v1,
    a2: a1,
    pEffectType: v2,
    func: (IParticleEffect *(__cdecl *)())CSimpleEmitter_Factory);
}

//------------------------------------------------------------------------------
// Address: 0x1041B160
// Name: _dynamic_initializer_for__g_Precipitations__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Precipitations__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_Precipitations__);
}

//------------------------------------------------------------------------------
// Address: 0x1041B170
// Name: _dynamic_initializer_for__s_ParticleSystemQuery__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ParticleSystemQuery__()
{
  CTSQueue<CFunctor *,0,1>::CTSQueue<CFunctor *,0,1>(this: (CTSQueue<CFunctor *,0,1> *)&s_ParticleSystemQuery.m_ProjectedInfoAdds);
  s_ParticleSystemQuery.m_ActiveProjectedInfos.m_Memory.m_pMemory = nullptr;
  s_ParticleSystemQuery.m_ActiveProjectedInfos.m_Memory.m_nAllocationCount = 0;
  s_ParticleSystemQuery.m_ActiveProjectedInfos.m_Memory.m_nGrowSize = 0;
  s_ParticleSystemQuery.m_ActiveProjectedInfos.m_Size = 0;
  s_ParticleSystemQuery.m_ActiveProjectedInfos.m_pElements = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__s_ParticleSystemQuery__);
}

//------------------------------------------------------------------------------
// Address: 0x1041B1B0
// Name: _dynamic_initializer_for____g_CreateCParticleSystemQueryIParticleSystemQuery_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCParticleSystemQueryIParticleSystemQuery_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCParticleSystemQueryIParticleSystemQuery_reg,
           fn: (void *(__cdecl *)())_CreateCParticleSystemQueryIParticleSystemQuery_interface,
           pName: "VParticleSystemQuery004");
}

//------------------------------------------------------------------------------
// Address: 0x1041B1D0
// Name: _dynamic_initializer_for__s_LightMutex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_LightMutex__()
{
  s_LightMutex.m_ownerID = 0;
  s_LightMutex.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1041B1E0
// Name: _dynamic_initializer_for__s_BoneMutex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_BoneMutex__()
{
  s_BoneMutex.m_ownerID = 0;
  s_BoneMutex.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1041B1F0
// Name: _dynamic_initializer_for__s_PerfVisualBenchmark__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_PerfVisualBenchmark__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_PerfVisualBenchmark__);
}

//------------------------------------------------------------------------------
// Address: 0x10433010
// Name: _dynamic_atexit_destructor_for__cl_particles_show_bbox__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_particles_show_bbox__()
{
  ConVar::~ConVar(this: &cl_particles_show_bbox);
}

//------------------------------------------------------------------------------
// Address: 0x10433020
// Name: _dynamic_atexit_destructor_for__cl_particle_fallback_multiplier__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_particle_fallback_multiplier__()
{
  ConVar::~ConVar(this: &cl_particle_fallback_multiplier);
}

//------------------------------------------------------------------------------
// Address: 0x10433030
// Name: _dynamic_atexit_destructor_for__cl_particle_fallback_base__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_particle_fallback_base__()
{
  ConVar::~ConVar(this: &cl_particle_fallback_base);
}

//------------------------------------------------------------------------------
// Address: 0x10433040
// Name: _dynamic_atexit_destructor_for__cl_particle_sim_fallback_threshold_ms__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_particle_sim_fallback_threshold_ms__()
{
  ConVar::~ConVar(this: &cl_particle_sim_fallback_threshold_ms);
}

//------------------------------------------------------------------------------
// Address: 0x10433050
// Name: _dynamic_atexit_destructor_for__cl_particle_sim_fallback_base_multiplier__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_particle_sim_fallback_base_multiplier__()
{
  ConVar::~ConVar(this: &cl_particle_sim_fallback_base_multiplier);
}

//------------------------------------------------------------------------------
// Address: 0x10433060
// Name: _dynamic_atexit_destructor_for__r_particle_sim_spike_threshold_ms__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_particle_sim_spike_threshold_ms__()
{
  ConVar::~ConVar(this: &r_particle_sim_spike_threshold_ms);
}

//------------------------------------------------------------------------------
// Address: 0x10433070
// Name: _dynamic_atexit_destructor_for__r_threaded_particles__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_threaded_particles__()
{
  ConVar::~ConVar(this: &r_threaded_particles);
}

//------------------------------------------------------------------------------
// Address: 0x10433080
// Name: _dynamic_atexit_destructor_for__cl_particle_retire_cost__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_particle_retire_cost__()
{
  ConVar::~ConVar(this: &cl_particle_retire_cost);
}

//------------------------------------------------------------------------------
// Address: 0x104330A0
// Name: _dynamic_atexit_destructor_for__r_particle_timescale__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_particle_timescale__()
{
  ConVar::~ConVar(this: &r_particle_timescale);
}

//------------------------------------------------------------------------------
// Address: 0x104330B0
// Name: _dynamic_atexit_destructor_for__cl_particle_max_count__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_particle_max_count__()
{
  ConVar::~ConVar(this: &cl_particle_max_count);
}

//------------------------------------------------------------------------------
// Address: 0x104330C0
// Name: _dynamic_atexit_destructor_for__cl_particles_dump_effects_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_particles_dump_effects_command__()
{
  ConCommand::~ConCommand(this: &cl_particles_dump_effects_command);
}

//------------------------------------------------------------------------------
// Address: 0x104330D0
// Name: _ParticleMgr_::_2_::_dynamic_atexit_destructor_for__s_ParticleMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ParticleMgr_::_2_::_dynamic_atexit_destructor_for__s_ParticleMgr__()
{
  CParticleMgr::~CParticleMgr(this: &s_ParticleMgr);
}

//------------------------------------------------------------------------------
// Address: 0x104330E0
// Name: _dynamic_atexit_destructor_for__g_EZParticleInit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_EZParticleInit__()
{
  IGameSystem::~IGameSystem(this: &g_EZParticleInit);
}

//------------------------------------------------------------------------------
// Address: 0x104330F0
// Name: _dynamic_atexit_destructor_for__g_pSimpleSingleton__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_pSimpleSingleton__()
{
  CSmartPtr<CEmberEffect,CRefCountAccessor> *v0; // esi
  int i; // edi
  CParticleEffect *m_pObj; // ecx

  v0 = g_pEmberSingleton;
  for ( i = 1; i >= 0; --i )
  {
    m_pObj = v0[-1].m_pObj;
    --v0;
    if ( m_pObj != nullptr )
      CParticleEffect::Release(this: m_pObj);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10433120
// Name: _dynamic_atexit_destructor_for__g_pEmberSingleton__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_pEmberSingleton__()
{
  CSmartPtr<CFireSmokeEffect,CRefCountAccessor> *v0; // esi
  int i; // edi
  CParticleEffect *m_pObj; // ecx

  v0 = g_pFireSmokeSingleton;
  for ( i = 1; i >= 0; --i )
  {
    m_pObj = v0[-1].m_pObj;
    --v0;
    if ( m_pObj != nullptr )
      CParticleEffect::Release(this: m_pObj);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10433150
// Name: _dynamic_atexit_destructor_for__g_pFireSmokeSingleton__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_pFireSmokeSingleton__()
{
  CSmartPtr<CFireParticle,CRefCountAccessor> *v0; // esi
  int i; // edi
  CParticleEffect *m_pObj; // ecx

  v0 = g_pFireSingleton;
  for ( i = 1; i >= 0; --i )
  {
    m_pObj = v0[-1].m_pObj;
    --v0;
    if ( m_pObj != nullptr )
      CParticleEffect::Release(this: m_pObj);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10433180
// Name: _dynamic_atexit_destructor_for__g_pFireSingleton__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_pFireSingleton__()
{
  CEZParticleInit *v0; // esi
  int i; // edi
  CParticleEffect *m_pszName; // ecx

  v0 = &g_EZParticleInit;
  for ( i = 1; i >= 0; --i )
  {
    m_pszName = (CParticleEffect *)v0[-1].m_pszName;
    v0 = (CEZParticleInit *)((char *)v0 - 4);
    if ( m_pszName != nullptr )
      CParticleEffect::Release(this: m_pszName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104331B0
// Name: _dynamic_atexit_destructor_for__cl_particles_show_controlpoints__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_particles_show_controlpoints__()
{
  ConVar::~ConVar(this: &cl_particles_show_controlpoints);
}

//------------------------------------------------------------------------------
// Address: 0x104331C0
// Name: _dynamic_atexit_destructor_for__cl_aggregate_particles__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_aggregate_particles__()
{
  ConVar::~ConVar(this: &cl_aggregate_particles);
}

//------------------------------------------------------------------------------
// Address: 0x104331D0
// Name: _dynamic_atexit_destructor_for__cl_dump_particle_stats__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_dump_particle_stats__()
{
  ConCommand::~ConCommand(this: &cl_dump_particle_stats);
}

//------------------------------------------------------------------------------
// Address: 0x104331E0
// Name: _dynamic_atexit_destructor_for__cl_particles_dumplist_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_particles_dumplist_command__()
{
  ConCommand::~ConCommand(this: &cl_particles_dumplist_command);
}

//------------------------------------------------------------------------------
// Address: 0x104331F0
// Name: _dynamic_atexit_destructor_for__g_EffectChecker__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_EffectChecker__()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10433200
// Name: _dynamic_atexit_destructor_for__g_ParticleEffects__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ParticleEffects__()
{
  CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::RemoveAll(this: (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)&g_ParticleEffects);
  if ( g_ParticleEffects.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_ParticleEffects.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_ParticleEffects.m_Memory.m_pMemory);
      g_ParticleEffects.m_Memory.m_pMemory = nullptr;
    }
    g_ParticleEffects.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10433250
// Name: _dynamic_atexit_destructor_for__g_Precipitations__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_Precipitations__()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_Precipitations);
}

//------------------------------------------------------------------------------
// Address: 0x10433260
// Name: _dynamic_atexit_destructor_for__s_ParticleSystemQuery__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_ParticleSystemQuery__()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&s_ParticleSystemQuery.m_ActiveProjectedInfos);
  CTSQueue<CFunctor *,0,1>::Purge(this: (CTSQueue<CFunctor *,0,1> *)&s_ParticleSystemQuery.m_ProjectedInfoAdds);
  C_BaseEntity::operator delete(pMem: s_ParticleSystemQuery.m_ProjectedInfoAdds.m_Head.value.pNode);
  CTSListBase::Detach(this: &s_ParticleSystemQuery.m_ProjectedInfoAdds.m_FreeNodes);
}
