// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/sceneentity_shared.cpp
// Functions: 30
// ============================================================

#include "game\shared\sceneentity_shared.h"

//------------------------------------------------------------------------------
// Address: 0x10099FD0
// Name: public: void CSceneTokenProcessor::SetBuffer(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneTokenProcessor::SetBuffer(CTraceFilterSimple *this, const IHandleEntity *pPassEntity)
{
  this->m_pPassEnt = pPassEntity;
}

//------------------------------------------------------------------------------
// Address: 0x100BFA40
// Name: public: virtual char const __near * CSceneTokenProcessor::CurrentToken(void)
// Source: json
//------------------------------------------------------------------------------
CNetworkVectorBase<Vector,CCollisionProperty::NetworkVar_m_vecMins> *__thiscall CSceneTokenProcessor::CurrentToken(
        CCollisionProperty *this)
{
  return &this->m_vecMins;
}

//------------------------------------------------------------------------------
// Address: 0x10169700
// Name: public: virtual bool CSceneTokenProcessor::GetToken(bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSceneTokenProcessor::GetToken(CSceneTokenProcessor *this, bool crossline)
{
  this->m_pBuffer = engine->ParseFile(this: engine, a2: this->m_pBuffer, a3: this->m_szToken, a4: 1024);
  return (strlen(this->m_szToken) & 0x80000000) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10169750
// Name: public: virtual bool CSceneTokenProcessor::TokenAvailable(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSceneTokenProcessor::TokenAvailable(CSceneTokenProcessor *this)
{
  const char *m_pBuffer; // ecx
  char v2; // al
  char v3; // al

  m_pBuffer = this->m_pBuffer;
  v2 = *m_pBuffer;
  if ( *m_pBuffer > 32 )
  {
LABEL_5:
    v3 = *m_pBuffer;
    if ( *m_pBuffer != 59 && v3 != 35 && (v3 != 47 || m_pBuffer[1] != 47) )
      return 1;
  }
  else
  {
    while ( v2 != 10 )
    {
      v2 = *++m_pBuffer;
      if ( v2 == 0 )
        break;
      if ( v2 > 32 )
        goto LABEL_5;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10169790
// Name: public: virtual void CSceneTokenProcessor::Error(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CSceneTokenProcessor::Error(CSceneTokenProcessor *this, const char *fmt, ...)
{
  char string[2048]; // [esp+0h] [ebp-800h] BYREF
  va_list params; // [esp+810h] [ebp+10h] BYREF

  va_start(params, fmt);
  V_vsnprintf(pDest: string, maxLen: 0x800u, pFormat: fmt, params);
  _Warning(a1: "%s", string);
}

//------------------------------------------------------------------------------
// Address: 0x101697D0
// Name: void Scene_Printf(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void Scene_Printf(char *pFormat, ...)
{
  int m_nValue; // eax
  char pDest[8192]; // [esp+14h] [ebp-2000h] BYREF
  va_list params; // [esp+2020h] [ebp+Ch] BYREF

  va_start(params, pFormat);
  if ( scene_print.m_pParent != nullptr )
  {
    m_nValue = scene_print.m_pParent->m_Value.m_nValue;
    if ( m_nValue != 0 && (m_nValue < 2 || m_nValue == 3) )
    {
      V_vsnprintf(pDest, maxLen: 0x2000, pFormat, params);
      _Msg(
        a1: "%8.3f[%d] %s:  %s",
        *(float *)(gpGlobals.m_Index + 12),
        *(_DWORD *)(gpGlobals.m_Index + 24),
        "cl",
        pDest);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10413720
// Name: _dynamic_initializer_for__scene_vcdautosave__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__scene_vcdautosave__()
{
  ConVar::ConVar(
    this: &scene_vcdautosave,
    pName: "scene_vcdautosave",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Create a savegame before VCD playback");
  return atexit(func: dynamic_atexit_destructor_for__scene_vcdautosave__);
}

//------------------------------------------------------------------------------
// Address: 0x1041C260
// Name: _dynamic_initializer_for__scene_print__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__scene_print__()
{
  ConVar::ConVar(
    this: &scene_print,
    pName: "scene_print",
    pDefaultValue: "0",
    flags: 0x2000,
    pHelpString: "When playing back a scene, print timing and event info to console.");
  return atexit(func: dynamic_atexit_destructor_for__scene_print__);
}

//------------------------------------------------------------------------------
// Address: 0x1041C290
// Name: _dynamic_initializer_for__scene_clientflex__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__scene_clientflex__()
{
  ConVar::ConVar(
    this: &scene_clientflex,
    pName: "scene_clientflex",
    pDefaultValue: "1",
    flags: 0x2000,
    pHelpString: "Do client side flex animation.");
  return atexit(func: dynamic_atexit_destructor_for__scene_clientflex__);
}

//------------------------------------------------------------------------------
// Address: 0x10430AE0
// Name: _dynamic_atexit_destructor_for__scene_vcdautosave__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__scene_vcdautosave__()
{
  ConVar::~ConVar(this: &scene_vcdautosave);
}

//------------------------------------------------------------------------------
// Address: 0x10433940
// Name: _dynamic_atexit_destructor_for__scene_print__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__scene_print__()
{
  ConVar::~ConVar(this: &scene_print);
}

//------------------------------------------------------------------------------
// Address: 0x10433950
// Name: _dynamic_atexit_destructor_for__scene_clientflex__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__scene_clientflex__()
{
  ConVar::~ConVar(this: &scene_clientflex);
}

//------------------------------------------------------------------------------
// Address: 0x10413750
// Name: _dynamic_initializer_for____g_C_ShadowControlClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_ShadowControlClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_ShadowControlClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_ShadowControlClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041C2C0
// Name: _dynamic_initializer_for__exampleeffect_effect__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__exampleeffect_effect__()
{
  CMaterialReference::CMaterialReference(
    this: &exampleeffect_effect.m_Material,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  exampleeffect_effect.m_bEnable = false;
  return atexit(func: dynamic_atexit_destructor_for__exampleeffect_effect__);
}

//------------------------------------------------------------------------------
// Address: 0x1041C2F0
// Name: _dynamic_initializer_for__exampleeffect_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CScreenSpaceEffectRegistration *dynamic_initializer_for__exampleeffect_reg__()
{
  CScreenSpaceEffectRegistration *result; // eax

  result = CScreenSpaceEffectRegistration::s_pHead;
  exampleeffect_reg.m_pNext = CScreenSpaceEffectRegistration::s_pHead;
  CScreenSpaceEffectRegistration::s_pHead = &exampleeffect_reg;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10433960
// Name: _dynamic_atexit_destructor_for__exampleeffect_effect__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__exampleeffect_effect__()
{
  exampleeffect_effect.__vftable = (CExampleEffect_vtbl *)&CExampleEffect::`vftable';
  CMaterialReference::~CMaterialReference(this: &exampleeffect_effect.m_Material);
}

//------------------------------------------------------------------------------
// Address: 0x10433980
// Name: _DataMapInit_CSimpleSimTimer__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CSimpleSimTimer__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_19);
}

//------------------------------------------------------------------------------
// Address: 0x10433990
// Name: _DataMapInit_CSimTimer__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CSimTimer__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_20);
}

//------------------------------------------------------------------------------
// Address: 0x104339A0
// Name: _DataMapInit_CRandSimTimer__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CRandSimTimer__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_21);
}

//------------------------------------------------------------------------------
// Address: 0x104339B0
// Name: _DataMapInit_CStopwatchBase__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CStopwatchBase__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_22);
}

//------------------------------------------------------------------------------
// Address: 0x104339C0
// Name: _DataMapInit_CStopwatch__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CStopwatch__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_23);
}

//------------------------------------------------------------------------------
// Address: 0x104339D0
// Name: _DataMapInit_CRandStopwatch__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CRandStopwatch__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_24);
}

//------------------------------------------------------------------------------
// Address: 0x104339E0
// Name: _dynamic_atexit_destructor_for__sv_soundemitter_version__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_soundemitter_version__()
{
  ConVar::~ConVar(this: &sv_soundemitter_version);
}

//------------------------------------------------------------------------------
// Address: 0x104339F0
// Name: _dynamic_atexit_destructor_for__snd_prevent_ss_duplicates__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__snd_prevent_ss_duplicates__()
{
  ConVar::~ConVar(this: &snd_prevent_ss_duplicates);
}

//------------------------------------------------------------------------------
// Address: 0x10433A00
// Name: _dynamic_atexit_destructor_for__snd_sos_show_client_xmit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__snd_sos_show_client_xmit__()
{
  ConVar::~ConVar(this: &snd_sos_show_client_xmit);
}

//------------------------------------------------------------------------------
// Address: 0x10433A10
// Name: _dynamic_atexit_destructor_for__sv_soundemitter_trace__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_soundemitter_trace__()
{
  ConVar::~ConVar(this: &sv_soundemitter_trace);
}

//------------------------------------------------------------------------------
// Address: 0x10433A20
// Name: _dynamic_atexit_destructor_for__cc_showmissing__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cc_showmissing__()
{
  ConVar::~ConVar(this: &cc_showmissing);
}

//------------------------------------------------------------------------------
// Address: 0x10433A30
// Name: _WaveTrace_::_5_::_dynamic_atexit_destructor_for__s_WaveTrace__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl WaveTrace_::_5_::_dynamic_atexit_destructor_for__s_WaveTrace__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &s_WaveTrace);
}

//------------------------------------------------------------------------------
// Address: 0x10433A40
// Name: _dynamic_atexit_destructor_for__g_SoundEmitterSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_SoundEmitterSystem__()
{
  IGameSystem::~IGameSystem(this: &g_SoundEmitterSystem);
}

//------------------------------------------------------------------------------
// Address: 0x10433A50
// Name: _dynamic_atexit_destructor_for__cl_soundemitter_flush_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_soundemitter_flush_command__()
{
  ConCommand::~ConCommand(this: &cl_soundemitter_flush_command);
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x100EE250
// Name: public: virtual char const __near * CSceneTokenProcessor::CurrentToken(void)
// Source: json
//------------------------------------------------------------------------------
CNetworkVectorBase<Vector,CCollisionProperty::NetworkVar_m_vecMins> *__thiscall CSceneTokenProcessor::CurrentToken(
        CCollisionProperty *this)
{
  return &this->m_vecMins;
}

//------------------------------------------------------------------------------
// Address: 0x1020C0E0
// Name: public: virtual bool CSceneTokenProcessor::GetToken(bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSceneTokenProcessor::GetToken(CSceneTokenProcessor *this, bool crossline)
{
  this->m_pBuffer = engine->ParseFile(this: engine, a2: this->m_pBuffer, a3: this->m_szToken, a4: 1024);
  return (strlen(this->m_szToken) & 0x80000000) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1020C130
// Name: public: virtual bool CSceneTokenProcessor::TokenAvailable(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSceneTokenProcessor::TokenAvailable(CSceneTokenProcessor *this)
{
  const char *m_pBuffer; // ecx
  char v2; // al
  char v3; // al

  m_pBuffer = this->m_pBuffer;
  v2 = *m_pBuffer;
  if ( *m_pBuffer > 32 )
  {
LABEL_5:
    v3 = *m_pBuffer;
    if ( *m_pBuffer != 59 && v3 != 35 && (v3 != 47 || m_pBuffer[1] != 47) )
      return 1;
  }
  else
  {
    while ( v2 != 10 )
    {
      v2 = *++m_pBuffer;
      if ( v2 == 0 )
        break;
      if ( v2 > 32 )
        goto LABEL_5;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1020C170
// Name: public: virtual void CSceneTokenProcessor::Error(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CSceneTokenProcessor::Error(CSceneTokenProcessor *this, const char *fmt, ...)
{
  char string[2048]; // [esp+0h] [ebp-800h] BYREF
  va_list params; // [esp+810h] [ebp+10h] BYREF

  va_start(params, fmt);
  V_vsnprintf(pDest: string, maxLen: 2048, pFormat: fmt, params);
  _Warning(a1: "%s", string);
}

//------------------------------------------------------------------------------
// Address: 0x1020C1B0
// Name: public: void CSceneTokenProcessor::SetBuffer(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneTokenProcessor::SetBuffer(CAI_Component *this, CAI_BaseNPC *pOuter)
{
  this->m_pOuter = pOuter;
}

//------------------------------------------------------------------------------
// Address: 0x1020C1C0
// Name: void Scene_Printf(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void Scene_Printf(char *pFormat, ...)
{
  int m_nValue; // eax
  char pDest[8192]; // [esp+14h] [ebp-2000h] BYREF
  va_list params; // [esp+2020h] [ebp+Ch] BYREF

  va_start(params, pFormat);
  if ( scene_print.m_pParent != nullptr )
  {
    m_nValue = scene_print.m_pParent->m_Value.m_nValue;
    if ( m_nValue != 0 && m_nValue <= 2 )
    {
      V_vsnprintf(pDest, maxLen: 0x2000, pFormat, params);
      _Msg(a1: "%8.3f[%d] %s:  %s", gpGlobals->curtime, gpGlobals->tickcount, "sv", pDest);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103FA8D0
// Name: _dynamic_initializer_for__scene_showfaceto__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__scene_showfaceto__()
{
  ConVar::ConVar(
    this: &scene_showfaceto,
    pName: "scene_showfaceto",
    pDefaultValue: "0",
    flags: 128,
    pHelpString: "When playing back, show the directions of faceto events.");
  return atexit(func: dynamic_atexit_destructor_for__scene_showfaceto__);
}

//------------------------------------------------------------------------------
// Address: 0x103FA920
// Name: _dynamic_initializer_for__scene_clamplookat__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__scene_clamplookat__()
{
  ConVar::ConVar(
    this: &scene_clamplookat,
    pName: "scene_clamplookat",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Clamp head turns to a MAX of 20 degrees per think.");
  return atexit(func: dynamic_atexit_destructor_for__scene_clamplookat__);
}

//------------------------------------------------------------------------------
// Address: 0x103FBAB0
// Name: _dynamic_initializer_for__scene_flatturn__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__scene_flatturn__()
{
  ConVar::ConVar(this: &scene_flatturn, pName: "scene_flatturn", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__scene_flatturn__);
}

//------------------------------------------------------------------------------
// Address: 0x104001D0
// Name: _dynamic_initializer_for__scene_showlook__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__scene_showlook__()
{
  ConVar::ConVar(
    this: &scene_showlook,
    pName: "scene_showlook",
    pDefaultValue: "0",
    flags: 128,
    pHelpString: "When playing back, show the directions of look events.");
  return atexit(func: dynamic_atexit_destructor_for__scene_showlook__);
}

//------------------------------------------------------------------------------
// Address: 0x10400200
// Name: _dynamic_initializer_for__scene_showmoveto__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__scene_showmoveto__()
{
  ConVar::ConVar(
    this: &scene_showmoveto,
    pName: "scene_showmoveto",
    pDefaultValue: "0",
    flags: 128,
    pHelpString: "When moving, show the end location.");
  return atexit(func: dynamic_atexit_destructor_for__scene_showmoveto__);
}

//------------------------------------------------------------------------------
// Address: 0x10400230
// Name: _dynamic_initializer_for__scene_showunlock__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__scene_showunlock__()
{
  ConVar::ConVar(
    this: &scene_showunlock,
    pName: "scene_showunlock",
    pDefaultValue: "0",
    flags: 128,
    pHelpString: "Show when a vcd is playing but normal AI is running.");
  return atexit(func: dynamic_atexit_destructor_for__scene_showunlock__);
}

//------------------------------------------------------------------------------
// Address: 0x10402060
// Name: _dynamic_initializer_for__entity_blocker__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__entity_blocker__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CEntityBlocker> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &entity_blocker,
           a3: "entity_blocker");
}

//------------------------------------------------------------------------------
// Address: 0x10409710
// Name: _dynamic_initializer_for__scene_forcecombined__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__scene_forcecombined__()
{
  ConVar::ConVar(
    this: &scene_forcecombined,
    pName: "scene_forcecombined",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "When playing back, force use of combined .wav files even in english.");
  return atexit(func: dynamic_atexit_destructor_for__scene_forcecombined__);
}

//------------------------------------------------------------------------------
// Address: 0x10409740
// Name: _dynamic_initializer_for__scene_maxcaptionradius__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__scene_maxcaptionradius__()
{
  ConVar::ConVar(
    this: &scene_maxcaptionradius,
    pName: "scene_maxcaptionradius",
    pDefaultValue: "1200",
    flags: 0,
    pHelpString: "Only show closed captions if recipient is within this many units of speaking actor (0==disabled).");
  return atexit(func: dynamic_atexit_destructor_for__scene_maxcaptionradius__);
}

//------------------------------------------------------------------------------
// Address: 0x10409770
// Name: _dynamic_initializer_for__scene_clientplayback__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__scene_clientplayback__()
{
  ConVar::ConVar(
    this: &scene_clientplayback,
    pName: "scene_clientplayback",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Play all vcds on the clients.");
  return atexit(func: dynamic_atexit_destructor_for__scene_clientplayback__);
}

//------------------------------------------------------------------------------
// Address: 0x10409880
// Name: _dynamic_initializer_for__scene_async_prefetch_spew__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__scene_async_prefetch_spew__()
{
  ConVar::ConVar(
    this: &scene_async_prefetch_spew,
    pName: "scene_async_prefetch_spew",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Display async .ani file loading info.");
  return atexit(func: dynamic_atexit_destructor_for__scene_async_prefetch_spew__);
}

//------------------------------------------------------------------------------
// Address: 0x104098E0
// Name: _dynamic_initializer_for__scene_playvcd_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__scene_playvcd_command__()
{
  ConCommand::ConCommand(
    this: &scene_playvcd_command,
    pName: "scene_playvcd",
    callback: (void (__cdecl *)())scene_playvcd,
    pHelpString: "Play the given VCD as an instanced scripted scene.",
    flags: 0x4000,
    completionFunc: SceneNameAutocomplete);
  return atexit(func: dynamic_atexit_destructor_for__scene_playvcd_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10409970
// Name: _dynamic_initializer_for__scene_manager__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__scene_manager__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CSceneManager> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &scene_manager,
           a3: "scene_manager");
}

//------------------------------------------------------------------------------
// Address: 0x104099F0
// Name: _dynamic_initializer_for__scene_flush_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__scene_flush_command__()
{
  ConCommand::ConCommand(
    this: &scene_flush_command,
    pName: "scene_flush",
    callback: scene_flush,
    pHelpString: "Flush all .vcds from the cache and reload from disk.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__scene_flush_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10409A20
// Name: _dynamic_initializer_for__scene_print__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__scene_print__()
{
  ConVar::ConVar(
    this: &scene_print,
    pName: "scene_print",
    pDefaultValue: "0",
    flags: 0x2000,
    pHelpString: "When playing back a scene, print timing and event info to console.");
  return atexit(func: dynamic_atexit_destructor_for__scene_print__);
}

//------------------------------------------------------------------------------
// Address: 0x10409A50
// Name: _dynamic_initializer_for__scene_clientflex__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__scene_clientflex__()
{
  ConVar::ConVar(
    this: &scene_clientflex,
    pName: "scene_clientflex",
    pDefaultValue: "1",
    flags: 0x2000,
    pHelpString: "Do client side flex animation.");
  return atexit(func: dynamic_atexit_destructor_for__scene_clientflex__);
}

//------------------------------------------------------------------------------
// Address: 0x104188A0
// Name: _dynamic_atexit_destructor_for__scene_showfaceto__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__scene_showfaceto__()
{
  ConVar::~ConVar(this: &scene_showfaceto);
}

//------------------------------------------------------------------------------
// Address: 0x104188B0
// Name: _dynamic_atexit_destructor_for__scene_clamplookat__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__scene_clamplookat__()
{
  ConVar::~ConVar(this: &scene_clamplookat);
}

//------------------------------------------------------------------------------
// Address: 0x10418F30
// Name: _dynamic_atexit_destructor_for__scene_flatturn__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__scene_flatturn__()
{
  ConVar::~ConVar(this: &scene_flatturn);
}

//------------------------------------------------------------------------------
// Address: 0x10419DB0
// Name: _dynamic_atexit_destructor_for__scene_showlook__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__scene_showlook__()
{
  ConVar::~ConVar(this: &scene_showlook);
}

//------------------------------------------------------------------------------
// Address: 0x10419DC0
// Name: _dynamic_atexit_destructor_for__scene_showmoveto__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__scene_showmoveto__()
{
  ConVar::~ConVar(this: &scene_showmoveto);
}

//------------------------------------------------------------------------------
// Address: 0x10419DD0
// Name: _dynamic_atexit_destructor_for__scene_showunlock__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__scene_showunlock__()
{
  ConVar::~ConVar(this: &scene_showunlock);
}

//------------------------------------------------------------------------------
// Address: 0x1041DB80
// Name: _dynamic_atexit_destructor_for__scene_forcecombined__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__scene_forcecombined__()
{
  ConVar::~ConVar(this: &scene_forcecombined);
}

//------------------------------------------------------------------------------
// Address: 0x1041DB90
// Name: _dynamic_atexit_destructor_for__scene_maxcaptionradius__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__scene_maxcaptionradius__()
{
  ConVar::~ConVar(this: &scene_maxcaptionradius);
}

//------------------------------------------------------------------------------
// Address: 0x1041DBA0
// Name: _dynamic_atexit_destructor_for__scene_clientplayback__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__scene_clientplayback__()
{
  ConVar::~ConVar(this: &scene_clientplayback);
}

//------------------------------------------------------------------------------
// Address: 0x1041DBC0
// Name: _dynamic_atexit_destructor_for__scene_async_prefetch_spew__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__scene_async_prefetch_spew__()
{
  ConVar::~ConVar(this: &scene_async_prefetch_spew);
}

//------------------------------------------------------------------------------
// Address: 0x1041DBE0
// Name: _dynamic_atexit_destructor_for__scene_playvcd_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__scene_playvcd_command__()
{
  ConCommand::~ConCommand(this: &scene_playvcd_command);
}

//------------------------------------------------------------------------------
// Address: 0x1041DC00
// Name: _dynamic_atexit_destructor_for__scene_flush_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__scene_flush_command__()
{
  ConCommand::~ConCommand(this: &scene_flush_command);
}

//------------------------------------------------------------------------------
// Address: 0x1041DCA0
// Name: _dynamic_atexit_destructor_for__scene_print__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__scene_print__()
{
  ConVar::~ConVar(this: &scene_print);
}

//------------------------------------------------------------------------------
// Address: 0x1041DCB0
// Name: _dynamic_atexit_destructor_for__scene_clientflex__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__scene_clientflex__()
{
  ConVar::~ConVar(this: &scene_clientflex);
}

//------------------------------------------------------------------------------
// Address: 0x103FA950
// Name: _dynamic_initializer_for__rr_remarkable_world_entities_replay_limit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__rr_remarkable_world_entities_replay_limit__()
{
  ConVar::ConVar(
    this: &rr_remarkable_world_entities_replay_limit,
    pName: "rr_remarkable_world_entities_replay_limit",
    pDefaultValue: "1",
    flags: 0x4000,
    pHelpString: "TLK_REMARKs will be dispatched no more than this many times for any given info_remarkable");
  return atexit(func: dynamic_atexit_destructor_for__rr_remarkable_world_entities_replay_limit__);
}

//------------------------------------------------------------------------------
// Address: 0x103FA980
// Name: _dynamic_initializer_for__rr_remarkables_enabled__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__rr_remarkables_enabled__()
{
  ConVar::ConVar(
    this: &rr_remarkables_enabled,
    pName: "rr_remarkables_enabled",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "If 1, polling for info_remarkables and issuances of TLK_REMARK is enabled.");
  return atexit(func: dynamic_atexit_destructor_for__rr_remarkables_enabled__);
}

//------------------------------------------------------------------------------
// Address: 0x103FA9B0
// Name: _dynamic_initializer_for__rr_remarkable_max_distance__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__rr_remarkable_max_distance__()
{
  ConVar::ConVar(
    this: &rr_remarkable_max_distance,
    pName: "rr_remarkable_max_distance",
    pDefaultValue: "1200",
    flags: 0x4000,
    pHelpString: "AIs will not even consider remarkarbles that are more than this many units away.");
  return atexit(func: dynamic_atexit_destructor_for__rr_remarkable_max_distance__);
}

//------------------------------------------------------------------------------
// Address: 0x103FA9E0
// Name: _dynamic_initializer_for__ai_no_select_box__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_no_select_box__()
{
  ConVar::ConVar(this: &ai_no_select_box, pName: "ai_no_select_box", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_no_select_box__);
}

//------------------------------------------------------------------------------
// Address: 0x103FAA10
// Name: _dynamic_initializer_for__ai_show_think_tolerance__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_show_think_tolerance__()
{
  ConVar::ConVar(this: &ai_show_think_tolerance, pName: "ai_show_think_tolerance", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_show_think_tolerance__);
}

//------------------------------------------------------------------------------
// Address: 0x103FAA40
// Name: _dynamic_initializer_for__ai_debug_think_ticks__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_debug_think_ticks__()
{
  ConVar::ConVar(this: &ai_debug_think_ticks, pName: "ai_debug_think_ticks", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_debug_think_ticks__);
}

//------------------------------------------------------------------------------
// Address: 0x103FAA70
// Name: _dynamic_initializer_for__ai_debug_doors__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_debug_doors__()
{
  ConVar::ConVar(this: &ai_debug_doors, pName: "ai_debug_doors", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_debug_doors__);
}

//------------------------------------------------------------------------------
// Address: 0x103FAAA0
// Name: _dynamic_initializer_for__ai_debug_enemies__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_debug_enemies__()
{
  ConVar::ConVar(this: &ai_debug_enemies, pName: "ai_debug_enemies", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_debug_enemies__);
}

//------------------------------------------------------------------------------
// Address: 0x103FAAD0
// Name: _dynamic_initializer_for__ai_rebalance_thinks__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_rebalance_thinks__()
{
  ConVar::ConVar(this: &ai_rebalance_thinks, pName: "ai_rebalance_thinks", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_rebalance_thinks__);
}

//------------------------------------------------------------------------------
// Address: 0x103FAB00
// Name: _dynamic_initializer_for__ai_use_efficiency__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_use_efficiency__()
{
  ConVar::ConVar(this: &ai_use_efficiency, pName: "ai_use_efficiency", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_use_efficiency__);
}

//------------------------------------------------------------------------------
// Address: 0x103FAB30
// Name: _dynamic_initializer_for__ai_use_frame_think_limits__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_use_frame_think_limits__()
{
  ConVar::ConVar(this: &ai_use_frame_think_limits, pName: "ai_use_frame_think_limits", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_use_frame_think_limits__);
}

//------------------------------------------------------------------------------
// Address: 0x103FAB60
// Name: _dynamic_initializer_for__ai_default_efficient__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_default_efficient__()
{
  ConVar::ConVar(this: &ai_default_efficient, pName: "ai_default_efficient", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_default_efficient__);
}

//------------------------------------------------------------------------------
// Address: 0x103FAB90
// Name: _dynamic_initializer_for__ai_efficiency_override__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_efficiency_override__()
{
  ConVar::ConVar(this: &ai_efficiency_override, pName: "ai_efficiency_override", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_efficiency_override__);
}

//------------------------------------------------------------------------------
// Address: 0x103FABC0
// Name: _dynamic_initializer_for__ai_debug_efficiency__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_debug_efficiency__()
{
  ConVar::ConVar(this: &ai_debug_efficiency, pName: "ai_debug_efficiency", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_debug_efficiency__);
}

//------------------------------------------------------------------------------
// Address: 0x103FABF0
// Name: _dynamic_initializer_for__ai_debug_dyninteractions__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_debug_dyninteractions__()
{
  ConVar::ConVar(
    this: &ai_debug_dyninteractions,
    pName: "ai_debug_dyninteractions",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Debug the NPC dynamic interaction system.");
  return atexit(func: dynamic_atexit_destructor_for__ai_debug_dyninteractions__);
}

//------------------------------------------------------------------------------
// Address: 0x103FAC20
// Name: _dynamic_initializer_for__ai_frametime_limit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_frametime_limit__()
{
  ConVar::ConVar(
    this: &ai_frametime_limit,
    pName: "ai_frametime_limit",
    pDefaultValue: "50",
    flags: 0,
    pHelpString: "frametime limit for min efficiency AIE_NORMAL (in sec's).");
  return atexit(func: dynamic_atexit_destructor_for__ai_frametime_limit__);
}

//------------------------------------------------------------------------------
// Address: 0x103FAC50
// Name: _dynamic_initializer_for__ai_use_think_optimizations__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_use_think_optimizations__()
{
  ConVar::ConVar(this: &ai_use_think_optimizations, pName: "ai_use_think_optimizations", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_use_think_optimizations__);
}

//------------------------------------------------------------------------------
// Address: 0x103FAC80
// Name: _dynamic_initializer_for__ai_test_moveprobe_ignoresmall__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_test_moveprobe_ignoresmall__()
{
  ConVar::ConVar(
    this: &ai_test_moveprobe_ignoresmall,
    pName: "ai_test_moveprobe_ignoresmall",
    pDefaultValue: "0",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_test_moveprobe_ignoresmall__);
}

//------------------------------------------------------------------------------
// Address: 0x103FACB0
// Name: _dynamic_initializer_for__sk_npc_head__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sk_npc_head__()
{
  ConVar::ConVar(this: &sk_npc_head, pName: "sk_npc_head", pDefaultValue: "2", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__sk_npc_head__);
}

//------------------------------------------------------------------------------
// Address: 0x103FACE0
// Name: _dynamic_initializer_for__sk_npc_chest__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sk_npc_chest__()
{
  ConVar::ConVar(this: &sk_npc_chest, pName: "sk_npc_chest", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__sk_npc_chest__);
}

//------------------------------------------------------------------------------
// Address: 0x103FAD10
// Name: _dynamic_initializer_for__sk_npc_stomach__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sk_npc_stomach__()
{
  ConVar::ConVar(this: &sk_npc_stomach, pName: "sk_npc_stomach", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__sk_npc_stomach__);
}

//------------------------------------------------------------------------------
// Address: 0x103FAD40
// Name: _dynamic_initializer_for__sk_npc_arm__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sk_npc_arm__()
{
  ConVar::ConVar(this: &sk_npc_arm, pName: "sk_npc_arm", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__sk_npc_arm__);
}

//------------------------------------------------------------------------------
// Address: 0x103FAD70
// Name: _dynamic_initializer_for__sk_npc_leg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sk_npc_leg__()
{
  ConVar::ConVar(this: &sk_npc_leg, pName: "sk_npc_leg", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__sk_npc_leg__);
}

//------------------------------------------------------------------------------
// Address: 0x103FADA0
// Name: _dynamic_initializer_for__showhitlocation__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__showhitlocation__()
{
  ConVar::ConVar(this: &showhitlocation, pName: "showhitlocation", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__showhitlocation__);
}

//------------------------------------------------------------------------------
// Address: 0x103FADD0
// Name: _dynamic_initializer_for__ai_debug_squads__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_debug_squads__()
{
  ConVar::ConVar(this: &ai_debug_squads, pName: "ai_debug_squads", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_debug_squads__);
}

//------------------------------------------------------------------------------
// Address: 0x103FAE00
// Name: _dynamic_initializer_for__ai_debug_loners__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_debug_loners__()
{
  ConVar::ConVar(this: &ai_debug_loners, pName: "ai_debug_loners", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_debug_loners__);
}

//------------------------------------------------------------------------------
// Address: 0x103FAE30
// Name: _dynamic_initializer_for__ai_lead_time__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_lead_time__()
{
  ConVar::ConVar(this: &ai_lead_time, pName: "ai_lead_time", pDefaultValue: "0.0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_lead_time__);
}

//------------------------------------------------------------------------------
// Address: 0x103FAE60
// Name: _dynamic_initializer_for__ai_shot_stats__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_shot_stats__()
{
  ConVar::ConVar(this: &ai_shot_stats, pName: "ai_shot_stats", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_shot_stats__);
}

//------------------------------------------------------------------------------
// Address: 0x103FAE90
// Name: _dynamic_initializer_for__ai_shot_stats_term__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_shot_stats_term__()
{
  ConVar::ConVar(this: &ai_shot_stats_term, pName: "ai_shot_stats_term", pDefaultValue: "1000", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_shot_stats_term__);
}

//------------------------------------------------------------------------------
// Address: 0x103FAEC0
// Name: _dynamic_initializer_for__ai_shot_bias__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_shot_bias__()
{
  ConVar::ConVar(this: &ai_shot_bias, pName: "ai_shot_bias", pDefaultValue: "1.0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_shot_bias__);
}

//------------------------------------------------------------------------------
// Address: 0x103FAEF0
// Name: _dynamic_initializer_for__ai_spread_defocused_cone_multiplier__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_spread_defocused_cone_multiplier__()
{
  ConVar::ConVar(
    this: &ai_spread_defocused_cone_multiplier,
    pName: "ai_spread_defocused_cone_multiplier",
    pDefaultValue: "3.0",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_spread_defocused_cone_multiplier__);
}

//------------------------------------------------------------------------------
// Address: 0x103FAF20
// Name: _dynamic_initializer_for__ai_spread_cone_focus_time__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_spread_cone_focus_time__()
{
  ConVar::ConVar(this: &ai_spread_cone_focus_time, pName: "ai_spread_cone_focus_time", pDefaultValue: "0.6", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_spread_cone_focus_time__);
}

//------------------------------------------------------------------------------
// Address: 0x103FAF50
// Name: _dynamic_initializer_for__ai_spread_pattern_focus_time__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_spread_pattern_focus_time__()
{
  ConVar::ConVar(
    this: &ai_spread_pattern_focus_time,
    pName: "ai_spread_pattern_focus_time",
    pDefaultValue: "0.8",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_spread_pattern_focus_time__);
}

//------------------------------------------------------------------------------
// Address: 0x103FAF80
// Name: _dynamic_initializer_for__ai_reaction_delay_idle__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_reaction_delay_idle__()
{
  ConVar::ConVar(this: &ai_reaction_delay_idle, pName: "ai_reaction_delay_idle", pDefaultValue: "0.3", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_reaction_delay_idle__);
}

//------------------------------------------------------------------------------
// Address: 0x103FAFB0
// Name: _dynamic_initializer_for__ai_reaction_delay_alert__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_reaction_delay_alert__()
{
  ConVar::ConVar(this: &ai_reaction_delay_alert, pName: "ai_reaction_delay_alert", pDefaultValue: "0.1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_reaction_delay_alert__);
}

//------------------------------------------------------------------------------
// Address: 0x103FAFE0
// Name: _dynamic_initializer_for__ai_strong_optimizations__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_strong_optimizations__()
{
  ConVar::ConVar(this: &ai_strong_optimizations, pName: "ai_strong_optimizations", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_strong_optimizations__);
}

//------------------------------------------------------------------------------
// Address: 0x103FB010
// Name: _dynamic_initializer_for__g_AI_Manager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_AI_Manager__()
{
  g_AI_Manager.m_AIs.m_Memory.m_pMemory = (CAI_BaseNPC **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 1024);
  g_AI_Manager.m_AIs.m_pElements = g_AI_Manager.m_AIs.m_Memory.m_pMemory;
  return atexit(func: dynamic_atexit_destructor_for__g_AI_Manager__);
}

//------------------------------------------------------------------------------
// Address: 0x103FB040
// Name: _dynamic_initializer_for__CAI_BaseNPC::gm_ClassScheduleIdSpace__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CAI_LocalIdSpace *dynamic_initializer_for__CAI_BaseNPC::gm_ClassScheduleIdSpace__()
{
  CAI_LocalIdSpace::CAI_LocalIdSpace(this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ScheduleIds, fIsRoot: true);
  CAI_LocalIdSpace::CAI_LocalIdSpace(this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_TaskIds, fIsRoot: true);
  return CAI_LocalIdSpace::CAI_LocalIdSpace(this: &CAI_BaseNPC::gm_ClassScheduleIdSpace.m_ConditionIds, fIsRoot: true);
}

//------------------------------------------------------------------------------
// Address: 0x103FB070
// Name: _dynamic_initializer_for__CAI_BaseNPC::gm_SchedulingSymbols__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__CAI_BaseNPC::gm_SchedulingSymbols__()
{
  CAI_GlobalNamespace::CAI_GlobalNamespace(this: &CAI_BaseNPC::gm_SchedulingSymbols.m_ScheduleNamespace);
  CAI_GlobalNamespace::CAI_GlobalNamespace(this: &CAI_BaseNPC::gm_SchedulingSymbols.m_TaskNamespace);
  CAI_GlobalNamespace::CAI_GlobalNamespace(this: &CAI_BaseNPC::gm_SchedulingSymbols.m_ConditionNamespace);
  return atexit(func: dynamic_atexit_destructor_for__CAI_BaseNPC::gm_SchedulingSymbols__);
}

//------------------------------------------------------------------------------
// Address: 0x103FB0A0
// Name: _dynamic_initializer_for__CAI_BaseNPC::gm_SquadSlotIdSpace__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CAI_LocalIdSpace *dynamic_initializer_for__CAI_BaseNPC::gm_SquadSlotIdSpace__()
{
  return CAI_LocalIdSpace::CAI_LocalIdSpace(this: &CAI_BaseNPC::gm_SquadSlotIdSpace, fIsRoot: true);
}

//------------------------------------------------------------------------------
// Address: 0x103FB0B0
// Name: _dynamic_initializer_for__g_PostFrameNavigationHook__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_PostFrameNavigationHook__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_PostFrameNavigationHook__);
}

//------------------------------------------------------------------------------
// Address: 0x103FB0C0
// Name: _dynamic_initializer_for__ai_block_damage__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_block_damage__()
{
  ConVar::ConVar(this: &ai_block_damage, pName: "ai_block_damage", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_block_damage__);
}

//------------------------------------------------------------------------------
// Address: 0x103FB0F0
// Name: _dynamic_initializer_for__ai_debug_avoidancebounds__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_debug_avoidancebounds__()
{
  ConVar::ConVar(this: &ai_debug_avoidancebounds, pName: "ai_debug_avoidancebounds", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_debug_avoidancebounds__);
}

//------------------------------------------------------------------------------
// Address: 0x103FB120
// Name: _dynamic_initializer_for__ai_auto_contact_solver__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_auto_contact_solver__()
{
  ConVar::ConVar(this: &ai_auto_contact_solver, pName: "ai_auto_contact_solver", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_auto_contact_solver__);
}

//------------------------------------------------------------------------------
// Address: 0x103FB150
// Name: _dynamic_initializer_for__ai_report_task_timings_on_limit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_report_task_timings_on_limit__()
{
  ConVar::ConVar(
    this: &ai_report_task_timings_on_limit,
    pName: "ai_report_task_timings_on_limit",
    pDefaultValue: "0",
    flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__ai_report_task_timings_on_limit__);
}

//------------------------------------------------------------------------------
// Address: 0x103FB180
// Name: _dynamic_initializer_for__ai_think_limit_label__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_think_limit_label__()
{
  ConVar::ConVar(this: &ai_think_limit_label, pName: "ai_think_limit_label", pDefaultValue: "0", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__ai_think_limit_label__);
}

//------------------------------------------------------------------------------
// Address: 0x104098B0
// Name: _dynamic_initializer_for__instanced_scripted_scene__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__instanced_scripted_scene__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CInstancedSceneEntity> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &instanced_scripted_scene,
           a3: "instanced_scripted_scene");
}

//------------------------------------------------------------------------------
// Address: 0x10409910
// Name: _dynamic_initializer_for__g_ScenePrecacheSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ScenePrecacheSystem__()
{
  CAutoGameSystem::CAutoGameSystem(this: &g_ScenePrecacheSystem, name: "CScenePrecacheSystem");
  g_ScenePrecacheSystem.__vftable = (CScenePrecacheSystem_vtbl *)&CScenePrecacheSystem::`vftable';
  g_ScenePrecacheSystem.m_RepeatCounts.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const int *, const int *))CKeyBindingsMgr::KeyBindingContextHandleLessFunc;
  g_ScenePrecacheSystem.m_RepeatCounts.m_Tree.m_Elements.m_pMemory = nullptr;
  g_ScenePrecacheSystem.m_RepeatCounts.m_Tree.m_Elements.m_nAllocationCount = 0;
  g_ScenePrecacheSystem.m_RepeatCounts.m_Tree.m_Elements.m_nGrowSize = 0;
  *(_DWORD *)&g_ScenePrecacheSystem.m_RepeatCounts.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&g_ScenePrecacheSystem.m_RepeatCounts.m_Tree.m_FirstFree = -1;
  g_ScenePrecacheSystem.m_RepeatCounts.m_Tree.m_pElements = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__g_ScenePrecacheSystem__);
}

//------------------------------------------------------------------------------
// Address: 0x10409A80
// Name: _dynamic_initializer_for__ai_task_pre_script__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_task_pre_script__()
{
  ConVar::ConVar(this: &ai_task_pre_script, pName: "ai_task_pre_script", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_task_pre_script__);
}

//------------------------------------------------------------------------------
// Address: 0x104188C0
// Name: _dynamic_atexit_destructor_for__rr_remarkable_world_entities_replay_limit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__rr_remarkable_world_entities_replay_limit__()
{
  ConVar::~ConVar(this: &rr_remarkable_world_entities_replay_limit);
}

//------------------------------------------------------------------------------
// Address: 0x104188D0
// Name: _dynamic_atexit_destructor_for__rr_remarkables_enabled__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__rr_remarkables_enabled__()
{
  ConVar::~ConVar(this: &rr_remarkables_enabled);
}

//------------------------------------------------------------------------------
// Address: 0x104188E0
// Name: _dynamic_atexit_destructor_for__rr_remarkable_max_distance__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__rr_remarkable_max_distance__()
{
  ConVar::~ConVar(this: &rr_remarkable_max_distance);
}

//------------------------------------------------------------------------------
// Address: 0x104188F0
// Name: _DataMapInit_CAI_BaseActor__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_BaseActor__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_3);
}

//------------------------------------------------------------------------------
// Address: 0x10418900
// Name: _DataMapInit_CAI_InterestTarget_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_InterestTarget_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_4);
}

//------------------------------------------------------------------------------
// Address: 0x10418910
// Name: _dynamic_atexit_destructor_for__ai_no_select_box__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_no_select_box__()
{
  ConVar::~ConVar(this: &ai_no_select_box);
}

//------------------------------------------------------------------------------
// Address: 0x10418920
// Name: _dynamic_atexit_destructor_for__ai_show_think_tolerance__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_show_think_tolerance__()
{
  ConVar::~ConVar(this: &ai_show_think_tolerance);
}

//------------------------------------------------------------------------------
// Address: 0x10418930
// Name: _dynamic_atexit_destructor_for__ai_debug_think_ticks__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_debug_think_ticks__()
{
  ConVar::~ConVar(this: &ai_debug_think_ticks);
}

//------------------------------------------------------------------------------
// Address: 0x10418940
// Name: _dynamic_atexit_destructor_for__ai_debug_doors__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_debug_doors__()
{
  ConVar::~ConVar(this: &ai_debug_doors);
}

//------------------------------------------------------------------------------
// Address: 0x10418950
// Name: _dynamic_atexit_destructor_for__ai_debug_enemies__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_debug_enemies__()
{
  ConVar::~ConVar(this: &ai_debug_enemies);
}

//------------------------------------------------------------------------------
// Address: 0x10418960
// Name: _dynamic_atexit_destructor_for__ai_rebalance_thinks__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_rebalance_thinks__()
{
  ConVar::~ConVar(this: &ai_rebalance_thinks);
}

//------------------------------------------------------------------------------
// Address: 0x10418970
// Name: _dynamic_atexit_destructor_for__ai_use_efficiency__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_use_efficiency__()
{
  ConVar::~ConVar(this: &ai_use_efficiency);
}

//------------------------------------------------------------------------------
// Address: 0x10418980
// Name: _dynamic_atexit_destructor_for__ai_use_frame_think_limits__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_use_frame_think_limits__()
{
  ConVar::~ConVar(this: &ai_use_frame_think_limits);
}

//------------------------------------------------------------------------------
// Address: 0x10418990
// Name: _dynamic_atexit_destructor_for__ai_default_efficient__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_default_efficient__()
{
  ConVar::~ConVar(this: &ai_default_efficient);
}

//------------------------------------------------------------------------------
// Address: 0x104189A0
// Name: _dynamic_atexit_destructor_for__ai_efficiency_override__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_efficiency_override__()
{
  ConVar::~ConVar(this: &ai_efficiency_override);
}

//------------------------------------------------------------------------------
// Address: 0x104189B0
// Name: _dynamic_atexit_destructor_for__ai_debug_efficiency__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_debug_efficiency__()
{
  ConVar::~ConVar(this: &ai_debug_efficiency);
}

//------------------------------------------------------------------------------
// Address: 0x104189C0
// Name: _dynamic_atexit_destructor_for__ai_debug_dyninteractions__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_debug_dyninteractions__()
{
  ConVar::~ConVar(this: &ai_debug_dyninteractions);
}

//------------------------------------------------------------------------------
// Address: 0x104189D0
// Name: _dynamic_atexit_destructor_for__ai_frametime_limit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_frametime_limit__()
{
  ConVar::~ConVar(this: &ai_frametime_limit);
}

//------------------------------------------------------------------------------
// Address: 0x104189E0
// Name: _dynamic_atexit_destructor_for__ai_use_think_optimizations__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_use_think_optimizations__()
{
  ConVar::~ConVar(this: &ai_use_think_optimizations);
}

//------------------------------------------------------------------------------
// Address: 0x104189F0
// Name: _dynamic_atexit_destructor_for__ai_test_moveprobe_ignoresmall__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_test_moveprobe_ignoresmall__()
{
  ConVar::~ConVar(this: &ai_test_moveprobe_ignoresmall);
}

//------------------------------------------------------------------------------
// Address: 0x10418A00
// Name: _dynamic_atexit_destructor_for__sk_npc_head__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sk_npc_head__()
{
  ConVar::~ConVar(this: &sk_npc_head);
}

//------------------------------------------------------------------------------
// Address: 0x10418A10
// Name: _dynamic_atexit_destructor_for__sk_npc_chest__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sk_npc_chest__()
{
  ConVar::~ConVar(this: &sk_npc_chest);
}

//------------------------------------------------------------------------------
// Address: 0x10418A20
// Name: _dynamic_atexit_destructor_for__sk_npc_stomach__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sk_npc_stomach__()
{
  ConVar::~ConVar(this: &sk_npc_stomach);
}

//------------------------------------------------------------------------------
// Address: 0x10418A30
// Name: _dynamic_atexit_destructor_for__sk_npc_arm__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sk_npc_arm__()
{
  ConVar::~ConVar(this: &sk_npc_arm);
}

//------------------------------------------------------------------------------
// Address: 0x10418A40
// Name: _dynamic_atexit_destructor_for__sk_npc_leg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sk_npc_leg__()
{
  ConVar::~ConVar(this: &sk_npc_leg);
}

//------------------------------------------------------------------------------
// Address: 0x10418A50
// Name: _dynamic_atexit_destructor_for__showhitlocation__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__showhitlocation__()
{
  ConVar::~ConVar(this: &showhitlocation);
}

//------------------------------------------------------------------------------
// Address: 0x10418A60
// Name: _dynamic_atexit_destructor_for__ai_debug_squads__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_debug_squads__()
{
  ConVar::~ConVar(this: &ai_debug_squads);
}

//------------------------------------------------------------------------------
// Address: 0x10418A70
// Name: _dynamic_atexit_destructor_for__ai_debug_loners__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_debug_loners__()
{
  ConVar::~ConVar(this: &ai_debug_loners);
}

//------------------------------------------------------------------------------
// Address: 0x10418A80
// Name: _dynamic_atexit_destructor_for__ai_lead_time__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_lead_time__()
{
  ConVar::~ConVar(this: &ai_lead_time);
}

//------------------------------------------------------------------------------
// Address: 0x10418A90
// Name: _dynamic_atexit_destructor_for__ai_shot_stats__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_shot_stats__()
{
  ConVar::~ConVar(this: &ai_shot_stats);
}

//------------------------------------------------------------------------------
// Address: 0x10418AA0
// Name: _dynamic_atexit_destructor_for__ai_shot_stats_term__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_shot_stats_term__()
{
  ConVar::~ConVar(this: &ai_shot_stats_term);
}

//------------------------------------------------------------------------------
// Address: 0x10418AB0
// Name: _dynamic_atexit_destructor_for__ai_shot_bias__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_shot_bias__()
{
  ConVar::~ConVar(this: &ai_shot_bias);
}

//------------------------------------------------------------------------------
// Address: 0x10418AC0
// Name: _dynamic_atexit_destructor_for__ai_spread_defocused_cone_multiplier__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_spread_defocused_cone_multiplier__()
{
  ConVar::~ConVar(this: &ai_spread_defocused_cone_multiplier);
}

//------------------------------------------------------------------------------
// Address: 0x10418AD0
// Name: _dynamic_atexit_destructor_for__ai_spread_cone_focus_time__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_spread_cone_focus_time__()
{
  ConVar::~ConVar(this: &ai_spread_cone_focus_time);
}

//------------------------------------------------------------------------------
// Address: 0x10418AE0
// Name: _dynamic_atexit_destructor_for__ai_spread_pattern_focus_time__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_spread_pattern_focus_time__()
{
  ConVar::~ConVar(this: &ai_spread_pattern_focus_time);
}

//------------------------------------------------------------------------------
// Address: 0x10418AF0
// Name: _dynamic_atexit_destructor_for__ai_reaction_delay_idle__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_reaction_delay_idle__()
{
  ConVar::~ConVar(this: &ai_reaction_delay_idle);
}

//------------------------------------------------------------------------------
// Address: 0x10418B00
// Name: _dynamic_atexit_destructor_for__ai_reaction_delay_alert__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_reaction_delay_alert__()
{
  ConVar::~ConVar(this: &ai_reaction_delay_alert);
}

//------------------------------------------------------------------------------
// Address: 0x10418B10
// Name: _dynamic_atexit_destructor_for__ai_strong_optimizations__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_strong_optimizations__()
{
  ConVar::~ConVar(this: &ai_strong_optimizations);
}

//------------------------------------------------------------------------------
// Address: 0x10418B20
// Name: _dynamic_atexit_destructor_for__ai_block_damage__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_block_damage__()
{
  ConVar::~ConVar(this: &ai_block_damage);
}

//------------------------------------------------------------------------------
// Address: 0x10418B30
// Name: _dynamic_atexit_destructor_for__ai_debug_avoidancebounds__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_debug_avoidancebounds__()
{
  ConVar::~ConVar(this: &ai_debug_avoidancebounds);
}

//------------------------------------------------------------------------------
// Address: 0x10418B40
// Name: _dynamic_atexit_destructor_for__ai_auto_contact_solver__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_auto_contact_solver__()
{
  ConVar::~ConVar(this: &ai_auto_contact_solver);
}

//------------------------------------------------------------------------------
// Address: 0x10418B50
// Name: _dynamic_atexit_destructor_for__ai_report_task_timings_on_limit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_report_task_timings_on_limit__()
{
  ConVar::~ConVar(this: &ai_report_task_timings_on_limit);
}

//------------------------------------------------------------------------------
// Address: 0x10418B60
// Name: _dynamic_atexit_destructor_for__ai_think_limit_label__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_think_limit_label__()
{
  ConVar::~ConVar(this: &ai_think_limit_label);
}

//------------------------------------------------------------------------------
// Address: 0x10418F40
// Name: _DataMapInit_CAI_BlendedMotor__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_BlendedMotor__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_37);
}

//------------------------------------------------------------------------------
// Address: 0x10418F50
// Name: _DataMapInit_ResponseRules::ResponseParams__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_ResponseRules::ResponseParams__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_38);
}

//------------------------------------------------------------------------------
// Address: 0x10418F60
// Name: _DataMapInit_ResponseRules::CRR_Response__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_ResponseRules::CRR_Response__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_39);
}

//------------------------------------------------------------------------------
// Address: 0x10418F70
// Name: _dynamic_atexit_destructor_for__g_AISystemHook__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_AISystemHook__()
{
  IGameSystem::~IGameSystem(this: &g_AISystemHook);
}

//------------------------------------------------------------------------------
// Address: 0x10418F80
// Name: _dynamic_atexit_destructor_for__ai_radial_max_link_dist__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_radial_max_link_dist__()
{
  ConVar::~ConVar(this: &ai_radial_max_link_dist);
}

//------------------------------------------------------------------------------
// Address: 0x10418F90
// Name: _DataMapInit_CAI_DynamicLinkController__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_DynamicLinkController__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_40);
}

//------------------------------------------------------------------------------
// Address: 0x10418FA0
// Name: _DataMapInit_CAI_DynamicLink__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_DynamicLink__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_41);
}

//------------------------------------------------------------------------------
// Address: 0x10418FB0
// Name: _DataMapInit_CAI_RadialLinkController__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_RadialLinkController__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_42);
}

//------------------------------------------------------------------------------
// Address: 0x1041DBD0
// Name: _MissingSceneWarning_::_2_::_dynamic_atexit_destructor_for__missing__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl MissingSceneWarning_::_2_::_dynamic_atexit_destructor_for__missing__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &missing);
}

//------------------------------------------------------------------------------
// Address: 0x1041DBF0
// Name: _dynamic_atexit_destructor_for__ListRecentNPCSpeechCmd__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ListRecentNPCSpeechCmd__()
{
  ConCommand::~ConCommand(this: &ListRecentNPCSpeechCmd);
}

//------------------------------------------------------------------------------
// Address: 0x1041DC10
// Name: _ServerClassInit_DT_SceneEntity::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_SceneEntity::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S4_51;
  for ( i = 6; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041DC30
// Name: _DataMapInit_CInstancedSceneEntity__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CInstancedSceneEntity__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_368);
}

//------------------------------------------------------------------------------
// Address: 0x1041DC40
// Name: _DataMapInit_CSceneListManager__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CSceneListManager__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_369);
}

//------------------------------------------------------------------------------
// Address: 0x1041DC50
// Name: _DataMapInit_CSceneManager__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CSceneManager__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_370);
}

//------------------------------------------------------------------------------
// Address: 0x1041DC60
// Name: _DataMapInit_CSceneEntity__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CSceneEntity__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_371);
}

//------------------------------------------------------------------------------
// Address: 0x1041DC70
// Name: _dynamic_atexit_destructor_for__g_ScenePrecacheSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ScenePrecacheSystem__()
{
  CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &g_ScenePrecacheSystem.m_RepeatCounts.m_Tree);
  IGameSystem::~IGameSystem(this: &g_ScenePrecacheSystem);
}

//------------------------------------------------------------------------------
// Address: 0x1041DC90
// Name: _dynamic_atexit_destructor_for__g_CSceneEntity_ScriptDesc__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CSceneEntity_ScriptDesc__()
{
  CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::~CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>(this: &g_CSceneEntity_ScriptDesc.m_FunctionBindings);
}

//------------------------------------------------------------------------------
// Address: 0x1041DCC0
// Name: _dynamic_atexit_destructor_for__ai_task_pre_script__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_task_pre_script__()
{
  ConVar::~ConVar(this: &ai_task_pre_script);
}

//------------------------------------------------------------------------------
// Address: 0x1041DCD0
// Name: _DataMapInit_CAI_ScriptedSequence__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_ScriptedSequence__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_374);
}

//------------------------------------------------------------------------------
// Address: 0x1041DCE0
// Name: _DataMapInit_CAI_ScriptedSchedule__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_ScriptedSchedule__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_372);
}

//------------------------------------------------------------------------------
// Address: 0x1041DCF0
// Name: _DataMapInit_CAI_ScriptedSentence__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAI_ScriptedSentence__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_373);
}

//------------------------------------------------------------------------------
// Address: 0x1041DD00
// Name: _DataMapInit_CScriptedTarget__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CScriptedTarget__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_375);
}

//------------------------------------------------------------------------------
// Address: 0x1041DD10
// Name: _dynamic_atexit_destructor_for__sv_benchmark_numticks__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_benchmark_numticks__()
{
  ConVar::~ConVar(this: &sv_benchmark_numticks);
}

//------------------------------------------------------------------------------
// Address: 0x1041DD20
// Name: _dynamic_atexit_destructor_for__sv_benchmark_autovprofrecord__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_benchmark_autovprofrecord__()
{
  ConVar::~ConVar(this: &sv_benchmark_autovprofrecord);
}

//------------------------------------------------------------------------------
// Address: 0x1041DD30
// Name: _dynamic_atexit_destructor_for__sv_benchmark_force_start_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_benchmark_force_start_command__()
{
  ConCommand::~ConCommand(this: &sv_benchmark_force_start_command);
}

//------------------------------------------------------------------------------
// Address: 0x1041DD40
// Name: _dynamic_atexit_destructor_for__g_ServerBenchmark__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ServerBenchmark__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_ServerBenchmark.m_PhysicsModelNames);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_ServerBenchmark.m_PhysicsObjects);
}

//------------------------------------------------------------------------------
// Address: 0x1041DD60
// Name: _DataMapInit_CServerNetworkProperty__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CServerNetworkProperty__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_376);
}

} // namespace server
