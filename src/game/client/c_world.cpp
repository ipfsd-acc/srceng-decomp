// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_world.cpp
// Functions: 89
// ============================================================

#include "game\client\c_world.h"

//------------------------------------------------------------------------------
// Address: 0x10090B10
// Name: public: virtual void C_World::PreDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_World::PreDataUpdate(C_Team *this, DataUpdateType_t updateType)
{
  C_BaseEntity::PreDataUpdate(this, updateType);
}

//------------------------------------------------------------------------------
// Address: 0x100979E0
// Name: void ClientWorldFactoryShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClientWorldFactoryShutdown()
{
  if ( g_pClientWorld != nullptr )
    ((void (__thiscall *)(C_World *, int))g_pClientWorld->dtr_IHandleEntity)(a1: g_pClientWorld, a2: 1);
  g_pClientWorld = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10097A00
// Name: ClientWorldFactory
// Source: json
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl ClientWorldFactory(int entnum, int serialNum)
{
  g_pClientWorld->Init(this: g_pClientWorld, a2: entnum, a3: serialNum);
  if ( g_pClientWorld != nullptr )
    return &g_pClientWorld->IClientNetworkable;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10097A30
// Name: public: virtual class ClientClass __near * C_World::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_World::GetClientClass(C_World *this)
{
  return &__g_C_WorldClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10097BF0
// Name: public: virtual bool C_World::Init(int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_World::Init(C_World *this, int entnum, int iSerialNum)
{
  this->m_flWaveHeight = 0.0;
  return C_BaseEntity::Init(this, entnum, iSerialNum);
}

//------------------------------------------------------------------------------
// Address: 0x10097C10
// Name: public: virtual void C_World::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_World::Release(C_World *this)
{
  C_BaseEntity::Term(this: (C_World *)((char *)this - 8));
}

//------------------------------------------------------------------------------
// Address: 0x10097C20
// Name: public: virtual void C_World::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_World::OnDataChanged(C_World *this, DataUpdateType_t updateType)
{
  CViewEffects *ViewEffects; // eax
  ScreenFade_t v4; // [esp+24h] [ebp-14h] BYREF
  OcclusionParams_t params; // [esp+30h] [ebp-8h] BYREF

  C_BaseEntity::OnDataChanged(this, type: updateType);
  if ( updateType == DATA_UPDATE_CREATED )
  {
    modemanager->SwitchMode(this: modemanager, a2: false, a3: true);
    if ( LOBYTE(this->m_WorldMaxs.y) != 0 )
    {
      *(_DWORD *)&v4.r = -16777216;
      *(_DWORD *)&v4.duration = 33556992;
      v4.fadeFlags = 17;
      ViewEffects = GetViewEffects();
      ViewEffects->Fade(this: ViewEffects, a2: &v4);
    }
    params = *(OcclusionParams_t *)&this->m_WorldMaxs.z;
    engine->SetOcclusionParameters(this: engine, a2: &params);
    ((void (__thiscall *)(IVModelInfoClient *, _DWORD, _DWORD))modelinfo->SetLevelScreenFadeRange)(
      a1: modelinfo,
      a2: LODWORD(this->m_flMaxOccludeeArea),
      a3: LODWORD(this->m_flMinOccluderArea));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10097D00
// Name: public: virtual void WeaponSpritesPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall WeaponSpritesPrecache::CResourcePrecacher::Cache(
        WeaponSpritesPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MODEL,
    a3: "sprites/zerogxplode.vmt",
    a4: bPrecache,
    a5: hResourceList,
    a6: &g_sModelIndexFireball);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MODEL,
    a3: "sprites/WXplo1.vmt",
    a4: bPrecache,
    a5: hResourceList,
    a6: &g_sModelIndexWExplosion);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MODEL,
    a3: "sprites/steam1.vmt",
    a4: bPrecache,
    a5: hResourceList,
    a6: &g_sModelIndexSmoke);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MODEL,
    a3: "sprites/bubble.vmt",
    a4: bPrecache,
    a5: hResourceList,
    a6: &g_sModelIndexBubbles);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MODEL,
    a3: "sprites/bloodspray.vmt",
    a4: bPrecache,
    a5: hResourceList,
    a6: &g_sModelIndexBloodSpray);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MODEL,
    a3: "sprites/blood.vmt",
    a4: bPrecache,
    a5: hResourceList,
    a6: &g_sModelIndexBloodDrop);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MODEL,
    a3: "sprites/laserbeam.vmt",
    a4: bPrecache,
    a5: hResourceList,
    a6: &g_sModelIndexLaser);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MODEL,
    a3: "sprites/laserdot.vmt",
    a4: bPrecache,
    a5: hResourceList,
    a6: &g_sModelIndexLaserDot);
}

//------------------------------------------------------------------------------
// Address: 0x10097DD0
// Name: public: virtual void C_World::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_World::Precache(C_World *this)
{
  const unsigned __int8 *v1; // eax

  v1 = g_pGameRules->GetEncryptionKey(this: g_pGameRules);
  PrecacheFileWeaponInfoDatabase(filesystem: filesystem, pICEKey: v1);
}

//------------------------------------------------------------------------------
// Address: 0x10097DF0
// Name: public: virtual void C_World::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_World::Spawn(C_World *this)
{
  this->Precache(this);
}

//------------------------------------------------------------------------------
// Address: 0x10097E00
// Name: class C_World __near * GetClientWorldEntity(void)
// Source: json
//------------------------------------------------------------------------------
C_World *__cdecl GetClientWorldEntity()
{
  return g_pClientWorld;
}

//------------------------------------------------------------------------------
// Address: 0x10097E70
// Name: void ClientWorldFactoryInit(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClientWorldFactoryInit()
{
  C_BaseEntity *v0; // eax
  C_World *v1; // esi

  v0 = (C_BaseEntity *)C_BaseEntity::operator new(stAllocateBlock: 0xAB8u);
  v1 = (C_World *)v0;
  if ( v0 != nullptr )
  {
    C_BaseEntity::C_BaseEntity(this: v0);
    v1->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_World_vtbl *)&C_World::`vftable'{for `IClientUnknown'};
    v1->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_World::`vftable'{for `IClientRenderable'};
    v1->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_World::`vftable'{for `IClientNetworkable'};
    v1->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_World::`vftable'{for `IClientThinkable'};
    v1->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_World::`vftable';
    g_pClientWorld = v1;
  }
  else
  {
    g_pClientWorld = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10414190
// Name: DT_World::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_World::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_World::g_RecvTable);
  return atexit(func: DT_World::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104141B0
// Name: DT_World::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_World::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_World::ignored>();
  DT_World::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104141C0
// Name: WeaponSpritesPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *WeaponSpritesPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  WeaponSpritesPrecache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &WeaponSpritesPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430DA0
// Name: DT_World::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_World::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_World::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x104141E0
// Name: _dynamic_initializer_for__g_CCamoFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CCamoFoo__()
{
  CMaterialProxyDict *MaterialProxyDict; // eax

  MaterialProxyDict = GetMaterialProxyDict();
  return ((int (__thiscall *)(CMaterialProxyDict *, const char *, IMaterialProxy_vtbl *(__cdecl *)()))MaterialProxyDict->Add)(
           a1: MaterialProxyDict,
           a2: "Camo",
           a3: CCCamoMaterialProxyFactory);
}

//------------------------------------------------------------------------------
// Address: 0x10414200
// Name: _dynamic_initializer_for__cl_predict_var__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_predict_var__()
{
  ConVar::ConVar(
    this: &cl_predict_var,
    pName: "cl_predict",
    pDefaultValue: "1.0",
    flags: 512,
    pHelpString: "Perform client side prediction.");
  cl_predict_var.ConVar_ServerBounded::ConVar::ConCommandBase::__vftable = (CBoundedCvar_Predict_vtbl *)&CBoundedCvar_Predict::`vftable'{for `ConCommandBase'};
  cl_predict_var.ConVar_ServerBounded::ConVar::IConVar::__vftable = (IConVar_vtbl *)&CBoundedCvar_Predict::`vftable'{for `IConVar'};
  return atexit(func: dynamic_atexit_destructor_for__cl_predict_var__);
}

//------------------------------------------------------------------------------
// Address: 0x10414240
// Name: _dynamic_initializer_for__cl_interp_ratio_var__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_interp_ratio_var__()
{
  ConVar::ConVar(
    this: &cl_interp_ratio_var,
    pName: "cl_interp_ratio",
    pDefaultValue: "2.0",
    flags: 512,
    pHelpString: "Sets the interpolation amount (final amount is cl_interp_ratio / cl_updaterate).");
  cl_interp_ratio_var.ConVar_ServerBounded::ConVar::ConCommandBase::__vftable = (CBoundedCvar_InterpRatio_vtbl *)&CBoundedCvar_InterpRatio::`vftable'{for `ConCommandBase'};
  cl_interp_ratio_var.ConVar_ServerBounded::ConVar::IConVar::__vftable = (IConVar_vtbl *)&CBoundedCvar_InterpRatio::`vftable'{for `IConVar'};
  return atexit(func: dynamic_atexit_destructor_for__cl_interp_ratio_var__);
}

//------------------------------------------------------------------------------
// Address: 0x10414280
// Name: _dynamic_initializer_for__cl_interp_var__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_interp_var__()
{
  ConVar::ConVar(
    this: &cl_interp_var,
    pName: "cl_interp",
    pDefaultValue: "0.1",
    flags: 512,
    pHelpString: "Sets the interpolation amount (bounded on low side by server interp ratio settings).",
    bMin: true,
    fMin: 0.0,
    bMax: true,
    fMax: 0.5);
  cl_interp_var.ConVar_ServerBounded::ConVar::ConCommandBase::__vftable = (CBoundedCvar_Interp_vtbl *)&CBoundedCvar_Interp::`vftable'{for `ConCommandBase'};
  cl_interp_var.ConVar_ServerBounded::ConVar::IConVar::__vftable = (IConVar_vtbl *)&CBoundedCvar_Interp::`vftable'{for `IConVar'};
  return atexit(func: dynamic_atexit_destructor_for__cl_interp_var__);
}

//------------------------------------------------------------------------------
// Address: 0x104142E0
// Name: _dynamic_initializer_for__s_GaussianRandomStream__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CGaussianRandomStream *dynamic_initializer_for__s_GaussianRandomStream__()
{
  return CGaussianRandomStream::CGaussianRandomStream(this: &s_GaussianRandomStream, a2: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x104142F0
// Name: _dynamic_initializer_for__LOG_VJOBS__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__LOG_VJOBS__()
{
  int result; // eax

  result = ((int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))_LoggingSystem_RegisterLoggingChannel)(
             a1: "VJOBS",
             a2: 0,
             a3: 0,
             a4: 0,
             a5: UNSPECIFIED_LOGGING_COLOR_0);
  LOG_VJOBS = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10414310
// Name: _dynamic_initializer_for__g_DataChangedEvents__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_DataChangedEvents__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_DataChangedEvents__);
}

//------------------------------------------------------------------------------
// Address: 0x10414320
// Name: _dynamic_initializer_for__s_CV_ShowParticleCounts__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_CV_ShowParticleCounts__()
{
  ConVar::ConVar(
    this: &s_CV_ShowParticleCounts,
    pName: "showparticlecounts",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Display number of particles drawn per frame");
  return atexit(func: dynamic_atexit_destructor_for__s_CV_ShowParticleCounts__);
}

//------------------------------------------------------------------------------
// Address: 0x10414350
// Name: _dynamic_initializer_for__s_cl_team__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_cl_team__()
{
  ConVar::ConVar(
    this: &s_cl_team,
    pName: "cl_team",
    pDefaultValue: "default",
    flags: 640,
    pHelpString: "Default team when joining a game");
  return atexit(func: dynamic_atexit_destructor_for__s_cl_team__);
}

//------------------------------------------------------------------------------
// Address: 0x10414380
// Name: _dynamic_initializer_for__s_cl_class__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_cl_class__()
{
  ConVar::ConVar(
    this: &s_cl_class,
    pName: "cl_class",
    pDefaultValue: "default",
    flags: 640,
    pHelpString: "Default class when joining a game");
  return atexit(func: dynamic_atexit_destructor_for__s_cl_class__);
}

//------------------------------------------------------------------------------
// Address: 0x104143B0
// Name: _dynamic_initializer_for__g_Hacks__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Hacks__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_Hacks__);
}

//------------------------------------------------------------------------------
// Address: 0x104143C0
// Name: _dynamic_initializer_for__cl_dumpsplithacks_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_dumpsplithacks_command__()
{
  ConCommand::ConCommand(
    this: &cl_dumpsplithacks_command,
    pName: "cl_dumpsplithacks",
    callback: cl_dumpsplithacks,
    pHelpString: "Dump split screen workarounds.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cl_dumpsplithacks_command__);
}

//------------------------------------------------------------------------------
// Address: 0x104143F0
// Name: _dynamic_initializer_for____g_CGameClientExports_singleton__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____g_CGameClientExports_singleton__()
{
  return atexit(func: dynamic_atexit_destructor_for____g_CGameClientExports_singleton__);
}

//------------------------------------------------------------------------------
// Address: 0x10414400
// Name: _dynamic_initializer_for____g_CreateCGameClientExportsIGameClientExports_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCGameClientExportsIGameClientExports_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCGameClientExportsIGameClientExports_reg,
           fn: (void *(__cdecl *)())_CreateCGameClientExportsIGameClientExports_interface,
           pName: "GameClientExports001");
}

//------------------------------------------------------------------------------
// Address: 0x10414420
// Name: _dynamic_initializer_for____g_CClientDLLSharedAppSystems_singleton__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____g_CClientDLLSharedAppSystems_singleton__()
{
  vgui::PropertySheet::Page_t src; // [esp+0h] [ebp-8h] BYREF

  src.page = (vgui::Panel *)"soundemittersystem";
  *(_DWORD *)&src.contextMenu = "VSoundEmitter003";
  CUtlVector<vgui::AnimationController::RanEvent_t,CUtlMemory<vgui::AnimationController::RanEvent_t,int>>::InsertBefore(
    this: (CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *)&_g_CClientDLLSharedAppSystems_singleton.m_Systems,
    elem: 0,
    &src);
  src.page = (vgui::Panel *)"scenefilecache";
  *(_DWORD *)&src.contextMenu = "SceneFileCache002";
  CUtlVector<vgui::AnimationController::RanEvent_t,CUtlMemory<vgui::AnimationController::RanEvent_t,int>>::InsertBefore(
    this: (CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *)&_g_CClientDLLSharedAppSystems_singleton.m_Systems,
    elem: _g_CClientDLLSharedAppSystems_singleton.m_Systems.m_Size,
    &src);
  return atexit(func: dynamic_atexit_destructor_for____g_CClientDLLSharedAppSystems_singleton__);
}

//------------------------------------------------------------------------------
// Address: 0x10414480
// Name: _dynamic_initializer_for____g_CreateCClientDLLSharedAppSystemsIClientDLLSharedAppSystems_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCClientDLLSharedAppSystemsIClientDLLSharedAppSystems_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCClientDLLSharedAppSystemsIClientDLLSharedAppSystems_reg,
           fn: (void *(__cdecl *)())_CreateCClientDLLSharedAppSystemsIClientDLLSharedAppSystems_interface,
           pName: "VClientDllSharedAppSystems001");
}

//------------------------------------------------------------------------------
// Address: 0x104144A0
// Name: _dynamic_initializer_for__g_VoiceStatusHelper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_VoiceStatusHelper__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_VoiceStatusHelper__);
}

//------------------------------------------------------------------------------
// Address: 0x104144B0
// Name: _dynamic_initializer_for__cl_ShowBoneSetupEnts__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_ShowBoneSetupEnts__()
{
  ConVar::ConVar(
    this: &cl_ShowBoneSetupEnts,
    pName: "cl_ShowBoneSetupEnts",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Show which entities are having their bones setup each frame.");
  return atexit(func: dynamic_atexit_destructor_for__cl_ShowBoneSetupEnts__);
}

//------------------------------------------------------------------------------
// Address: 0x104144E0
// Name: _dynamic_initializer_for__g_BoneSetupEnts__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_BoneSetupEnts__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_BoneSetupEnts__);
}

//------------------------------------------------------------------------------
// Address: 0x104144F0
// Name: _dynamic_initializer_for__gHLClient__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__gHLClient__()
{
  CUtlSymbolTable::CUtlSymbolTable(this: &gHLClient.m_CachedMovies, growSize: 0, initSize: 16, caseInsensitive: false);
  g_bLevelInitialized = false;
  gHLClient.m_pHudCloseCaption = nullptr;
  if ( gHLClient.m_CachedMaterials.m_LessFunc == nullptr )
    gHLClient.m_CachedMaterials.m_LessFunc = (bool (__cdecl *)(IMaterial *const *, IMaterial *const *))CDefOps<C_BaseEntity *>::LessFunc;
  return atexit(func: dynamic_atexit_destructor_for__gHLClient__);
}

//------------------------------------------------------------------------------
// Address: 0x10414530
// Name: _dynamic_initializer_for____g_CreateCHLClientIBaseClientDLL_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCHLClientIBaseClientDLL_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCHLClientIBaseClientDLL_reg,
           fn: (void *(__cdecl *)())_CreateCHLClientIBaseClientDLL_interface,
           pName: "VClient016");
}

//------------------------------------------------------------------------------
// Address: 0x10414550
// Name: _dynamic_initializer_for__cl_threaded_init__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_threaded_init__()
{
  ConVar::ConVar(this: &cl_threaded_init, pName: "cl_threaded_init", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__cl_threaded_init__);
}

//------------------------------------------------------------------------------
// Address: 0x10414580
// Name: _dynamic_initializer_for__cpu_level__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cpu_level__()
{
  ConVar::ConVar(
    this: &cpu_level,
    pName: "cpu_level",
    pDefaultValue: "2",
    flags: 0,
    pHelpString: "CPU Level - Default: High",
    callback: (void (__cdecl *)(IConVar *, const char *, float))OnGPUMemLevelChanged);
  return atexit(func: dynamic_atexit_destructor_for__cpu_level__);
}

//------------------------------------------------------------------------------
// Address: 0x104145B0
// Name: _dynamic_initializer_for__gpu_level__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__gpu_level__()
{
  ConVar::ConVar(
    this: &gpu_level,
    pName: "gpu_level",
    pDefaultValue: "3",
    flags: 0,
    pHelpString: "GPU Level - Default: High",
    callback: (void (__cdecl *)(IConVar *, const char *, float))OnGPUMemLevelChanged);
  return atexit(func: dynamic_atexit_destructor_for__gpu_level__);
}

//------------------------------------------------------------------------------
// Address: 0x104145E0
// Name: _dynamic_initializer_for__mem_level__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mem_level__()
{
  ConVar::ConVar(
    this: &mem_level,
    pName: "mem_level",
    pDefaultValue: "2",
    flags: 0,
    pHelpString: "Memory Level - Default: High",
    callback: (void (__cdecl *)(IConVar *, const char *, float))OnGPUMemLevelChanged);
  return atexit(func: dynamic_atexit_destructor_for__mem_level__);
}

//------------------------------------------------------------------------------
// Address: 0x10414610
// Name: _dynamic_initializer_for__gpu_mem_level__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__gpu_mem_level__()
{
  ConVar::ConVar(
    this: &gpu_mem_level,
    pName: "gpu_mem_level",
    pDefaultValue: "2",
    flags: 0,
    pHelpString: "Memory Level - Default: High",
    callback: (void (__cdecl *)(IConVar *, const char *, float))OnGPUMemLevelChanged);
  return atexit(func: dynamic_atexit_destructor_for__gpu_mem_level__);
}

//------------------------------------------------------------------------------
// Address: 0x10414640
// Name: _dynamic_initializer_for__cl_disable_splitscreen_cpu_level_cfgs_in_pip__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_disable_splitscreen_cpu_level_cfgs_in_pip__()
{
  ConVar::ConVar(
    this: &cl_disable_splitscreen_cpu_level_cfgs_in_pip,
    pName: "cl_disable_splitscreen_cpu_level_cfgs_in_pip",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: prType);
  return atexit(func: dynamic_atexit_destructor_for__cl_disable_splitscreen_cpu_level_cfgs_in_pip__);
}

//------------------------------------------------------------------------------
// Address: 0x10414670
// Name: _dynamic_initializer_for__g_RestoredEntities__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_RestoredEntities__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_RestoredEntities__);
}

//------------------------------------------------------------------------------
// Address: 0x10414680
// Name: _dynamic_initializer_for__g_KeyBindingListenerMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_KeyBindingListenerMgr__()
{
  CKeyBindingListenerMgr::CKeyBindingListenerMgr(this: &g_KeyBindingListenerMgr);
  return atexit(func: dynamic_atexit_destructor_for__g_KeyBindingListenerMgr__);
}

//------------------------------------------------------------------------------
// Address: 0x104146A0
// Name: _dynamic_initializer_for____g_CreateCClientMaterialSystemIClientMaterialSystem_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCClientMaterialSystemIClientMaterialSystem_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCClientMaterialSystemIClientMaterialSystem_reg,
           fn: (void *(__cdecl *)())_CreateCClientMaterialSystemIClientMaterialSystem_interface,
           pName: "VCLIENTMATERIALSYSTEM001");
}

//------------------------------------------------------------------------------
// Address: 0x104146C0
// Name: _dynamic_initializer_for__mat_stub__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_stub__()
{
  ConVar::ConVar(this: &mat_stub, pName: "mat_stub", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_stub__);
}

//------------------------------------------------------------------------------
// Address: 0x104146F0
// Name: _dynamic_initializer_for__g_ClientThinkList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ClientThinkList__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_ClientThinkList__);
}

//------------------------------------------------------------------------------
// Address: 0x10414700
// Name: _dynamic_initializer_for__report_clientthinklist__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__report_clientthinklist__()
{
  ConVar::ConVar(
    this: &report_clientthinklist,
    pName: "report_clientthinklist",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "List all clientside entities thinking and time - will report and turn itself off.");
  return atexit(func: dynamic_atexit_destructor_for__report_clientthinklist__);
}

//------------------------------------------------------------------------------
// Address: 0x10414730
// Name: _dynamic_initializer_for__s_EntityList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EntityList__()
{
  CClientEntityList::CClientEntityList(this: &s_EntityList);
  return atexit(func: dynamic_atexit_destructor_for__s_EntityList__);
}

//------------------------------------------------------------------------------
// Address: 0x10414750
// Name: _dynamic_initializer_for____g_CreateCClientEntityListIClientEntityList_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCClientEntityListIClientEntityList_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCClientEntityListIClientEntityList_reg,
           fn: (void *(__cdecl *)())_CreateCClientEntityListIClientEntityList_interface,
           pName: "VClientEntityList003");
}

//------------------------------------------------------------------------------
// Address: 0x10414770
// Name: _dynamic_initializer_for__cl_drawleaf__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_drawleaf__()
{
  ConVar::ConVar(this: &cl_drawleaf, pName: "cl_drawleaf", pDefaultValue: "-1", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__cl_drawleaf__);
}

//------------------------------------------------------------------------------
// Address: 0x104147A0
// Name: _dynamic_initializer_for__r_PortalTestEnts__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_PortalTestEnts__()
{
  ConVar::ConVar(
    this: &r_PortalTestEnts,
    pName: "r_PortalTestEnts",
    pDefaultValue: "1",
    flags: 0x4000,
    pHelpString: "Clip entities against portal frustums.");
  return atexit(func: dynamic_atexit_destructor_for__r_PortalTestEnts__);
}

//------------------------------------------------------------------------------
// Address: 0x104147D0
// Name: _dynamic_initializer_for__r_portalsopenall__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_portalsopenall__()
{
  ConVar::ConVar(
    this: &r_portalsopenall,
    pName: "r_portalsopenall",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Open all portals");
  return atexit(func: dynamic_atexit_destructor_for__r_portalsopenall__);
}

//------------------------------------------------------------------------------
// Address: 0x10414800
// Name: _dynamic_initializer_for__r_shadows_on_renderables_enable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_shadows_on_renderables_enable__()
{
  ConVar::ConVar(
    this: &r_shadows_on_renderables_enable,
    pName: "r_shadows_on_renderables_enable",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Support casting RTT shadows onto other renderables");
  return atexit(func: dynamic_atexit_destructor_for__r_shadows_on_renderables_enable__);
}

//------------------------------------------------------------------------------
// Address: 0x10414830
// Name: _dynamic_initializer_for__cl_leafsystemvis__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_leafsystemvis__()
{
  ConVar::ConVar(this: &cl_leafsystemvis, pName: "cl_leafsystemvis", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__cl_leafsystemvis__);
}

//------------------------------------------------------------------------------
// Address: 0x10430DB0
// Name: _dynamic_atexit_destructor_for__cl_predict_var__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_predict_var__()
{
  ConVar::~ConVar(this: &cl_predict_var);
}

//------------------------------------------------------------------------------
// Address: 0x10430DC0
// Name: _dynamic_atexit_destructor_for__cl_interp_ratio_var__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_interp_ratio_var__()
{
  ConVar::~ConVar(this: &cl_interp_ratio_var);
}

//------------------------------------------------------------------------------
// Address: 0x10430DD0
// Name: _dynamic_atexit_destructor_for__cl_interp_var__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_interp_var__()
{
  ConVar::~ConVar(this: &cl_interp_var);
}

//------------------------------------------------------------------------------
// Address: 0x10430DE0
// Name: _dynamic_atexit_destructor_for__s_CV_ShowParticleCounts__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_CV_ShowParticleCounts__()
{
  ConVar::~ConVar(this: &s_CV_ShowParticleCounts);
}

//------------------------------------------------------------------------------
// Address: 0x10430DF0
// Name: _dynamic_atexit_destructor_for__s_cl_team__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_cl_team__()
{
  ConVar::~ConVar(this: &s_cl_team);
}

//------------------------------------------------------------------------------
// Address: 0x10430E00
// Name: _dynamic_atexit_destructor_for__s_cl_class__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_cl_class__()
{
  ConVar::~ConVar(this: &s_cl_class);
}

//------------------------------------------------------------------------------
// Address: 0x10430E10
// Name: _dynamic_atexit_destructor_for__cl_dumpsplithacks_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_dumpsplithacks_command__()
{
  ConCommand::~ConCommand(this: &cl_dumpsplithacks_command);
}

//------------------------------------------------------------------------------
// Address: 0x10430E20
// Name: _dynamic_atexit_destructor_for__cl_ShowBoneSetupEnts__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_ShowBoneSetupEnts__()
{
  ConVar::~ConVar(this: &cl_ShowBoneSetupEnts);
}

//------------------------------------------------------------------------------
// Address: 0x10430E30
// Name: _dynamic_atexit_destructor_for__cl_threaded_init__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_threaded_init__()
{
  ConVar::~ConVar(this: &cl_threaded_init);
}

//------------------------------------------------------------------------------
// Address: 0x10430E40
// Name: _dynamic_atexit_destructor_for__cpu_level__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cpu_level__()
{
  ConVar::~ConVar(this: &cpu_level);
}

//------------------------------------------------------------------------------
// Address: 0x10430E50
// Name: _dynamic_atexit_destructor_for__gpu_level__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__gpu_level__()
{
  ConVar::~ConVar(this: &gpu_level);
}

//------------------------------------------------------------------------------
// Address: 0x10430E60
// Name: _dynamic_atexit_destructor_for__mem_level__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mem_level__()
{
  ConVar::~ConVar(this: &mem_level);
}

//------------------------------------------------------------------------------
// Address: 0x10430E70
// Name: _dynamic_atexit_destructor_for__gpu_mem_level__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__gpu_mem_level__()
{
  ConVar::~ConVar(this: &gpu_mem_level);
}

//------------------------------------------------------------------------------
// Address: 0x10430E80
// Name: _dynamic_atexit_destructor_for__cl_disable_splitscreen_cpu_level_cfgs_in_pip__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_disable_splitscreen_cpu_level_cfgs_in_pip__()
{
  ConVar::~ConVar(this: &cl_disable_splitscreen_cpu_level_cfgs_in_pip);
}

//------------------------------------------------------------------------------
// Address: 0x10430E90
// Name: _dynamic_atexit_destructor_for__g_VoiceStatusHelper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_VoiceStatusHelper__()
{
  g_VoiceStatusHelper.__vftable = (CHLVoiceStatusHelper_vtbl *)&IVoiceStatusHelper::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10430EA0
// Name: _dynamic_atexit_destructor_for____g_CGameClientExports_singleton__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____g_CGameClientExports_singleton__()
{
  _g_CGameClientExports_singleton.__vftable = (CGameClientExports_vtbl *)&IBaseInterface::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10430EB0
// Name: _dynamic_atexit_destructor_for__g_DataChangedEvents__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DataChangedEvents__()
{
  CUtlLinkedList<CRopeManager::RopeQueuedRenderCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRopeManager::RopeQueuedRenderCache_t,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<CRopeManager::RopeQueuedRenderCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRopeManager::RopeQueuedRenderCache_t,unsigned short>,unsigned short> > *)&g_DataChangedEvents);
  if ( g_DataChangedEvents.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_DataChangedEvents.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_DataChangedEvents.m_Memory.m_pMemory);
      g_DataChangedEvents.m_Memory.m_pMemory = nullptr;
    }
    g_DataChangedEvents.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10430F00
// Name: _dynamic_atexit_destructor_for__g_RestoredEntities__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_RestoredEntities__()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_RestoredEntities);
}

//------------------------------------------------------------------------------
// Address: 0x10430F10
// Name: _dynamic_atexit_destructor_for____g_CClientDLLSharedAppSystems_singleton__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____g_CClientDLLSharedAppSystems_singleton__()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&_g_CClientDLLSharedAppSystems_singleton.m_Systems);
}

//------------------------------------------------------------------------------
// Address: 0x10430F20
// Name: _dynamic_atexit_destructor_for__g_Hacks__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_Hacks__()
{
  CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>::~CUtlRBTree<char const *,int,bool (__cdecl *)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>>(this: &g_Hacks);
}

//------------------------------------------------------------------------------
// Address: 0x10430F30
// Name: _dynamic_atexit_destructor_for__gHLClient__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__gHLClient__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &gHLClient.m_CachedMovies);
  CUtlRBTree<IMaterial *,unsigned short,bool (__cdecl *)(IMaterial * const &,IMaterial * const &),CUtlMemory<UtlRBTreeNode_t<IMaterial *,unsigned short>,unsigned short>>::~CUtlRBTree<IMaterial *,unsigned short,bool (__cdecl *)(IMaterial * const &,IMaterial * const &),CUtlMemory<UtlRBTreeNode_t<IMaterial *,unsigned short>,unsigned short>>(this: &gHLClient.m_CachedMaterials);
}

//------------------------------------------------------------------------------
// Address: 0x10430F50
// Name: _dynamic_atexit_destructor_for__g_BoneSetupEnts__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_BoneSetupEnts__()
{
  CUtlRBTree<CBoneSetupEnt,unsigned short,bool (__cdecl *)(CBoneSetupEnt const &,CBoneSetupEnt const &),CUtlMemory<UtlRBTreeNode_t<CBoneSetupEnt,unsigned short>,unsigned short>>::~CUtlRBTree<CBoneSetupEnt,unsigned short,bool (__cdecl *)(CBoneSetupEnt const &,CBoneSetupEnt const &),CUtlMemory<UtlRBTreeNode_t<CBoneSetupEnt,unsigned short>,unsigned short>>(this: &g_BoneSetupEnts);
}

//------------------------------------------------------------------------------
// Address: 0x10430F60
// Name: _dynamic_atexit_destructor_for__g_KeyBindingListenerMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_KeyBindingListenerMgr__()
{
  CKeyBindingListenerMgr::~CKeyBindingListenerMgr(this: &g_KeyBindingListenerMgr);
}

//------------------------------------------------------------------------------
// Address: 0x10430F70
// Name: _dynamic_atexit_destructor_for__mat_stub__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_stub__()
{
  ConVar::~ConVar(this: &mat_stub);
}

//------------------------------------------------------------------------------
// Address: 0x10430F80
// Name: _GetClassMap_::_2_::_dynamic_atexit_destructor_for__g_Classmap__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl GetClassMap_::_2_::_dynamic_atexit_destructor_for__g_Classmap__()
{
  CUtlDict<classentry_t,unsigned short>::RemoveAll(this: &g_Classmap.m_ClassDict);
  CUtlRBTree<CUtlMap<char const *,classentry_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,classentry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,classentry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,classentry_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,classentry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,classentry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &g_Classmap.m_ClassDict.m_Elements.m_Tree);
  g_Classmap.__vftable = (CClassMap_vtbl *)&IClassMap::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10430FA0
// Name: _dynamic_atexit_destructor_for__report_clientthinklist__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__report_clientthinklist__()
{
  ConVar::~ConVar(this: &report_clientthinklist);
}

//------------------------------------------------------------------------------
// Address: 0x10430FB0
// Name: _dynamic_atexit_destructor_for__g_ClientThinkList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ClientThinkList__()
{
  g_ClientThinkList.__vftable = (CClientThinkList_vtbl *)&CClientThinkList::`vftable';
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_ClientThinkList.m_aChangeList);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_ClientThinkList.m_aDeleteList);
  CUtlLinkedList<CClientThinkList::ThinkEntry_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientThinkList::ThinkEntry_t,unsigned short>,unsigned short>>::RemoveAll(this: &g_ClientThinkList.m_ThinkEntries);
  if ( g_ClientThinkList.m_ThinkEntries.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_ClientThinkList.m_ThinkEntries.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_ClientThinkList.m_ThinkEntries.m_Memory.m_pMemory);
      g_ClientThinkList.m_ThinkEntries.m_Memory.m_pMemory = nullptr;
    }
    g_ClientThinkList.m_ThinkEntries.m_Memory.m_nAllocationCount = 0;
  }
  IGameSystemPerFrame::~IGameSystemPerFrame(this: &g_ClientThinkList);
}

//------------------------------------------------------------------------------
// Address: 0x10431020
// Name: _dynamic_atexit_destructor_for__s_EntityList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EntityList__()
{
  CClientEntityList::~CClientEntityList(this: &s_EntityList);
}

//------------------------------------------------------------------------------
// Address: 0x10431030
// Name: _dynamic_atexit_destructor_for__cl_drawleaf__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_drawleaf__()
{
  ConVar::~ConVar(this: &cl_drawleaf);
}

//------------------------------------------------------------------------------
// Address: 0x10431040
// Name: _dynamic_atexit_destructor_for__r_PortalTestEnts__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_PortalTestEnts__()
{
  ConVar::~ConVar(this: &r_PortalTestEnts);
}

//------------------------------------------------------------------------------
// Address: 0x10431050
// Name: _dynamic_atexit_destructor_for__r_portalsopenall__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_portalsopenall__()
{
  ConVar::~ConVar(this: &r_portalsopenall);
}

//------------------------------------------------------------------------------
// Address: 0x10431060
// Name: _dynamic_atexit_destructor_for__r_shadows_on_renderables_enable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_shadows_on_renderables_enable__()
{
  ConVar::~ConVar(this: &r_shadows_on_renderables_enable);
}

//------------------------------------------------------------------------------
// Address: 0x10431070
// Name: _dynamic_atexit_destructor_for__cl_leafsystemvis__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_leafsystemvis__()
{
  ConVar::~ConVar(this: &cl_leafsystemvis);
}
