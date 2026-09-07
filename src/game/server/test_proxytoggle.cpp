// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/test_proxytoggle.cpp
// Functions: 53
// ============================================================

#include "game\server\test_proxytoggle.h"

//------------------------------------------------------------------------------
// Address: 0x10233330
// Name: public: virtual class ServerClass __near * CTest_ProxyToggle_Networkable::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CTest_ProxyToggle_Networkable::GetServerClass(CTest_ProxyToggle_Networkable *this)
{
  return &g_CTest_ProxyToggle_Networkable_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10233340
// Name: void Test_ProxyToggle_EnableProxy(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Test_ProxyToggle_EnableProxy(const CCommand *args)
{
  const char *v1; // eax
  const char *v2; // [esp+0h] [ebp-4h]

  if ( args->m_nArgc < 2 )
    _Error(this: (ISceneTokenProcessor *)&stru_104C15FC, a2: v2);
  v1 = locale;
  if ( args->m_nArgc > 1 )
    v1 = args->m_ppArgv[1];
  g_bEnableProxy = atoi(nptr: v1) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10233400
// Name: void __near * SendProxy_TestProxyToggle(class SendProp const __near *,void const __near *,void const __near *,class CSendProxyRecipients __near *,int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl SendProxy_TestProxyToggle(
        const SendProp *pProp,
        const void *pStructBase,
        const void *pData,
        CSendProxyRecipients *pRecipients)
{
  if ( g_bEnableProxy )
    return (void *)pData;
  if ( pRecipients != nullptr )
    *pRecipients = 0;
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102334D0
// Name: public: CTest_ProxyToggle_Networkable::CTest_ProxyToggle_Networkable(void)
// Source: json
//------------------------------------------------------------------------------
CTest_ProxyToggle_Networkable *__thiscall CTest_ProxyToggle_Networkable::CTest_ProxyToggle_Networkable(
        CTest_ProxyToggle_Networkable *this)
{
  CTest_ProxyToggle_Networkable *result; // eax
  edict_t *m_pPev; // ecx

  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->__vftable = (CTest_ProxyToggle_Networkable_vtbl *)&CTest_ProxyToggle_Networkable::`vftable';
  result = this;
  if ( this->m_WithProxy.m_Value != 1241 )
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
    this->m_WithProxy.m_Value = 1241;
    result = this;
  }
  g_pTestObj = this;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10233570
// Name: void Test_ProxyToggle_SetValue(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Test_ProxyToggle_SetValue(const CCommand *args)
{
  const char *v1; // eax
  int v2; // eax
  CTest_ProxyToggle_Networkable *v3; // esi
  int v4; // edi
  edict_t *m_pPev; // ecx
  const char *v6; // [esp+0h] [ebp-8h]

  if ( args->m_nArgc >= 2 )
  {
    if ( g_pTestObj == nullptr )
      _Error(this: (ISceneTokenProcessor *)&stru_104C1994, a2: v6);
  }
  else
  {
    _Error(this: (ISceneTokenProcessor *)"Test_ProxyToggle_SetValue: requires value parameter.", a2: v6);
  }
  v1 = locale;
  if ( args->m_nArgc > 1 )
    v1 = args->m_ppArgv[1];
  v2 = atoi(nptr: v1);
  v3 = g_pTestObj;
  v4 = v2;
  if ( g_pTestObj->m_WithProxy.m_Value != v2 )
  {
    if ( g_pTestObj->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&g_pTestObj->m_Network + 76) |= 1u;
      v3->m_WithProxy.m_Value = v2;
    }
    else
    {
      m_pPev = g_pTestObj->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x354u);
      v3->m_WithProxy.m_Value = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103FF4A0
// Name: _dynamic_initializer_for____proxy_SendProxy_SendBaseCombatCharacterLocalDataTable__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
CNonModifiedPointerProxy *dynamic_initializer_for____proxy_SendProxy_SendBaseCombatCharacterLocalDataTable__()
{
  return CNonModifiedPointerProxy::CNonModifiedPointerProxy(
           this: &_proxy_SendProxy_SendBaseCombatCharacterLocalDataTable,
           fn: (void *(__cdecl *)(const SendProp *, const void *, const void *, CSendProxyRecipients *, int))SendProxy_SendBaseCombatCharacterLocalDataTable);
}

//------------------------------------------------------------------------------
// Address: 0x103FF710
// Name: _dynamic_initializer_for____proxy_SendProxy_SendActiveLocalWeaponDataTable__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
CNonModifiedPointerProxy *dynamic_initializer_for____proxy_SendProxy_SendActiveLocalWeaponDataTable__()
{
  return CNonModifiedPointerProxy::CNonModifiedPointerProxy(
           this: &_proxy_SendProxy_SendActiveLocalWeaponDataTable,
           fn: (void *(__cdecl *)(const SendProp *, const void *, const void *, CSendProxyRecipients *, int))SendProxy_SendLocalWeaponDataTable);
}

//------------------------------------------------------------------------------
// Address: 0x103FF720
// Name: _dynamic_initializer_for____proxy_SendProxy_SendLocalWeaponDataTable__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
CNonModifiedPointerProxy *dynamic_initializer_for____proxy_SendProxy_SendLocalWeaponDataTable__()
{
  return CNonModifiedPointerProxy::CNonModifiedPointerProxy(
           this: &_proxy_SendProxy_SendLocalWeaponDataTable,
           fn: (void *(__cdecl *)(const SendProp *, const void *, const void *, CSendProxyRecipients *, int))SendProxy_SendLocalWeaponDataTable);
}

//------------------------------------------------------------------------------
// Address: 0x103FF730
// Name: _dynamic_initializer_for____proxy_SendProxy_SendNonLocalWeaponDataTable__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
CNonModifiedPointerProxy *dynamic_initializer_for____proxy_SendProxy_SendNonLocalWeaponDataTable__()
{
  return CNonModifiedPointerProxy::CNonModifiedPointerProxy(
           this: &_proxy_SendProxy_SendNonLocalWeaponDataTable,
           fn: (void *(__cdecl *)(const SendProp *, const void *, const void *, CSendProxyRecipients *, int))SendProxy_SendNonLocalWeaponDataTable);
}

//------------------------------------------------------------------------------
// Address: 0x103FF860
// Name: _dynamic_initializer_for____proxy_SendProxy_ClientSideAnimation__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
CNonModifiedPointerProxy *dynamic_initializer_for____proxy_SendProxy_ClientSideAnimation__()
{
  return CNonModifiedPointerProxy::CNonModifiedPointerProxy(
           this: &_proxy_SendProxy_ClientSideAnimation,
           fn: (void *(__cdecl *)(const SendProp *, const void *, const void *, CSendProxyRecipients *, int))SendProxy_ClientSideAnimation);
}

//------------------------------------------------------------------------------
// Address: 0x10400260
// Name: _dynamic_initializer_for____proxy_SendProxy_FlexWeights__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
CNonModifiedPointerProxy *dynamic_initializer_for____proxy_SendProxy_FlexWeights__()
{
  return CNonModifiedPointerProxy::CNonModifiedPointerProxy(
           this: &_proxy_SendProxy_FlexWeights,
           fn: (void *(__cdecl *)(const SendProp *, const void *, const void *, CSendProxyRecipients *, int))SendProxy_FlexWeights);
}

//------------------------------------------------------------------------------
// Address: 0x10408070
// Name: _dynamic_initializer_for____proxy_SendProxy_SendLocalDataTable__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
CNonModifiedPointerProxy *dynamic_initializer_for____proxy_SendProxy_SendLocalDataTable__()
{
  return CNonModifiedPointerProxy::CNonModifiedPointerProxy(
           this: &_proxy_SendProxy_SendLocalDataTable,
           fn: SendProxy_SendLocalDataTable);
}

//------------------------------------------------------------------------------
// Address: 0x10408080
// Name: _dynamic_initializer_for____proxy_SendProxy_SendNonLocalDataTable__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
CNonModifiedPointerProxy *dynamic_initializer_for____proxy_SendProxy_SendNonLocalDataTable__()
{
  return CNonModifiedPointerProxy::CNonModifiedPointerProxy(
           this: &_proxy_SendProxy_SendNonLocalDataTable,
           fn: SendProxy_SendNonLocalDataTable);
}

//------------------------------------------------------------------------------
// Address: 0x10409B70
// Name: _dynamic_initializer_for____proxy_SendProxy_OnlyToTeam__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
CNonModifiedPointerProxy *dynamic_initializer_for____proxy_SendProxy_OnlyToTeam__()
{
  return CNonModifiedPointerProxy::CNonModifiedPointerProxy(
           this: &_proxy_SendProxy_OnlyToTeam,
           fn: (void *(__cdecl *)(const SendProp *, const void *, const void *, CSendProxyRecipients *, int))SendProxy_OnlyToTeam);
}

//------------------------------------------------------------------------------
// Address: 0x1040B530
// Name: _dynamic_initializer_for____proxy_SendProxy_TestProxyToggle__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
CNonModifiedPointerProxy *dynamic_initializer_for____proxy_SendProxy_TestProxyToggle__()
{
  return CNonModifiedPointerProxy::CNonModifiedPointerProxy(
           this: &_proxy_SendProxy_TestProxyToggle,
           fn: (void *(__cdecl *)(const SendProp *, const void *, const void *, CSendProxyRecipients *, int))SendProxy_TestProxyToggle);
}

//------------------------------------------------------------------------------
// Address: 0x1040B560
// Name: DT_ProxyToggle_ProxiedData::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_ProxyToggle_ProxiedData::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_ProxyToggle_ProxiedData::g_SendTable);
  return atexit(func: DT_ProxyToggle_ProxiedData::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1040B580
// Name: DT_ProxyToggle_ProxiedData::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_ProxyToggle_ProxiedData::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_ProxyToggle_ProxiedData::ignored>();
  DT_ProxyToggle_ProxiedData::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040B5B0
// Name: DT_ProxyToggle::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_ProxyToggle::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_ProxyToggle::g_SendTable);
  return atexit(func: DT_ProxyToggle::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1040B5D0
// Name: DT_ProxyToggle::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_ProxyToggle::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_ProxyToggle::ignored>();
  DT_ProxyToggle::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10412940
// Name: _dynamic_initializer_for____proxy_SendProxy_SendActiveLocalKnifeDataTable__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
CNonModifiedPointerProxy *dynamic_initializer_for____proxy_SendProxy_SendActiveLocalKnifeDataTable__()
{
  return CNonModifiedPointerProxy::CNonModifiedPointerProxy(
           this: &_proxy_SendProxy_SendActiveLocalKnifeDataTable,
           fn: SendProxy_SendActiveLocalKnifeDataTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041E790
// Name: DT_ProxyToggle_ProxiedData::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_ProxyToggle_ProxiedData::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_ProxyToggle_ProxiedData::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041E7A0
// Name: DT_ProxyToggle::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_ProxyToggle::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_ProxyToggle::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10400270
// Name: _dynamic_initializer_for__g_CBaseFlex_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CBaseFlex_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CBaseFlex_ClassReg,
           pNetworkName: "CBaseFlex",
           pTable: &DT_BaseFlex::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10409B80
// Name: _dynamic_initializer_for__sv_benchmark_numticks__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_benchmark_numticks__()
{
  ConVar::ConVar(
    this: &sv_benchmark_numticks,
    pName: "sv_benchmark_numticks",
    pDefaultValue: "3300",
    flags: 0,
    pHelpString: "If > 0, then it only runs the benchmark for this # of ticks.");
  return atexit(func: dynamic_atexit_destructor_for__sv_benchmark_numticks__);
}

//------------------------------------------------------------------------------
// Address: 0x10409BB0
// Name: _dynamic_initializer_for__sv_benchmark_autovprofrecord__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_benchmark_autovprofrecord__()
{
  ConVar::ConVar(
    this: &sv_benchmark_autovprofrecord,
    pName: "sv_benchmark_autovprofrecord",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "If running a benchmark and this is set, it will record a vprof file over the duration of the benchmark with filename"
    " benchmark.vprof.");
  return atexit(func: dynamic_atexit_destructor_for__sv_benchmark_autovprofrecord__);
}

//------------------------------------------------------------------------------
// Address: 0x10409BE0
// Name: _dynamic_initializer_for__g_ServerBenchmark__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ServerBenchmark__()
{
  void (__thiscall *SetSeed)(struct CUniformRandomStream *, int); // edx

  CUniformRandomStream::CUniformRandomStream(this: &g_ServerBenchmark.m_RandomStream);
  SetSeed = g_ServerBenchmark.m_RandomStream.SetSeed;
  g_ServerBenchmark.m_BenchmarkState = BENCHMARKSTATE_NOT_RUNNING;
  SetSeed(this: &g_ServerBenchmark.m_RandomStream, a2: 1111);
  return atexit(func: dynamic_atexit_destructor_for__g_ServerBenchmark__);
}

//------------------------------------------------------------------------------
// Address: 0x10409C20
// Name: _dynamic_initializer_for__sv_benchmark_force_start_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_benchmark_force_start_command__()
{
  ConCommand::ConCommand(
    this: &sv_benchmark_force_start_command,
    pName: "sv_benchmark_force_start",
    callback: (void (__cdecl *)())sv_benchmark_force_start,
    pHelpString: "Force start the benchmark. This is only for debugging. It's better to set sv_benchmark to 1 and restart the level.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__sv_benchmark_force_start_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10409C50
// Name: _dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___4()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerGameTagsIServerGameTags_reg_4,
           fn: (void *(__cdecl *)())_CreateCServerGameTagsIServerGameTags_interface_4,
           pName: "ServerGameTags001");
}

//------------------------------------------------------------------------------
// Address: 0x1040B590
// Name: _dynamic_initializer_for__g_CTest_ProxyToggle_Networkable_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CTest_ProxyToggle_Networkable_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CTest_ProxyToggle_Networkable_ClassReg,
           pNetworkName: "CTest_ProxyToggle_Networkable",
           pTable: &DT_ProxyToggle::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1040B5E0
// Name: _dynamic_initializer_for__cc_Test_ProxyToggle_EnableProxy__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cc_Test_ProxyToggle_EnableProxy__()
{
  ConCommand::ConCommand(
    this: &cc_Test_ProxyToggle_EnableProxy,
    pName: "Test_ProxyToggle_EnableProxy",
    callback: (void (__cdecl *)())Test_ProxyToggle_EnableProxy,
    pHelpString: nullptr,
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cc_Test_ProxyToggle_EnableProxy__);
}

//------------------------------------------------------------------------------
// Address: 0x1040B610
// Name: _dynamic_initializer_for__cc_Test_ProxyToggle_SetValue__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cc_Test_ProxyToggle_SetValue__()
{
  ConCommand::ConCommand(
    this: &cc_Test_ProxyToggle_SetValue,
    pName: "Test_ProxyToggle_SetValue",
    callback: (void (__cdecl *)())Test_ProxyToggle_SetValue,
    pHelpString: nullptr,
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cc_Test_ProxyToggle_SetValue__);
}

//------------------------------------------------------------------------------
// Address: 0x1040B640
// Name: _dynamic_initializer_for__g_StressEntityRegs__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_StressEntityRegs__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_StressEntityRegs__);
}

//------------------------------------------------------------------------------
// Address: 0x1040B650
// Name: _dynamic_initializer_for__g_StressEntities__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_StressEntities__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_StressEntities__);
}

//------------------------------------------------------------------------------
// Address: 0x1040B660
// Name: _dynamic_initializer_for__cc_Test_InitRandomEntitySpawner__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cc_Test_InitRandomEntitySpawner__()
{
  ConCommand::ConCommand(
    this: &cc_Test_InitRandomEntitySpawner,
    pName: "Test_InitRandomEntitySpawner",
    callback: (void (__cdecl *)())Test_InitRandomEntitySpawner,
    pHelpString: nullptr,
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cc_Test_InitRandomEntitySpawner__);
}

//------------------------------------------------------------------------------
// Address: 0x1040B690
// Name: _dynamic_initializer_for__cc_Test_SpawnRandomEntities__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cc_Test_SpawnRandomEntities__()
{
  ConCommand::ConCommand(
    this: &cc_Test_SpawnRandomEntities,
    pName: "Test_SpawnRandomEntities",
    callback: (void (__cdecl *)())Test_SpawnRandomEntities,
    pHelpString: nullptr,
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cc_Test_SpawnRandomEntities__);
}

//------------------------------------------------------------------------------
// Address: 0x1040B6C0
// Name: _dynamic_initializer_for__cc_Test_RandomizeInPVS__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cc_Test_RandomizeInPVS__()
{
  ConCommand::ConCommand(
    this: &cc_Test_RandomizeInPVS,
    pName: "Test_RandomizeInPVS",
    callback: (void (__cdecl *)())Test_RandomizeInPVS,
    pHelpString: nullptr,
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cc_Test_RandomizeInPVS__);
}

//------------------------------------------------------------------------------
// Address: 0x1040B6F0
// Name: _dynamic_initializer_for__cc_Test_RemoveAllRandomEntities__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cc_Test_RemoveAllRandomEntities__()
{
  ConCommand::ConCommand(
    this: &cc_Test_RemoveAllRandomEntities,
    pName: "Test_RemoveAllRandomEntities",
    callback: Test_RemoveAllRandomEntities,
    pHelpString: nullptr,
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cc_Test_RemoveAllRandomEntities__);
}

//------------------------------------------------------------------------------
// Address: 0x1040B720
// Name: _dynamic_initializer_for__cc_Test_CreateEntity__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cc_Test_CreateEntity__()
{
  ConCommand::ConCommand(
    this: &cc_Test_CreateEntity,
    pName: "Test_CreateEntity",
    callback: (void (__cdecl *)())Test_CreateEntity,
    pHelpString: nullptr,
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cc_Test_CreateEntity__);
}

//------------------------------------------------------------------------------
// Address: 0x1040B750
// Name: _dynamic_initializer_for__cc_Test_RandomPlayerPosition__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cc_Test_RandomPlayerPosition__()
{
  ConCommand::ConCommand(
    this: &cc_Test_RandomPlayerPosition,
    pName: "Test_RandomPlayerPosition",
    callback: Test_RandomPlayerPosition,
    pHelpString: nullptr,
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cc_Test_RandomPlayerPosition__);
}

//------------------------------------------------------------------------------
// Address: 0x1040B780
// Name: _dynamic_initializer_for__g_CTestTraceline_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CTestTraceline_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CTestTraceline_ClassReg,
           pNetworkName: "CTestTraceline",
           pTable: &DT_TestTraceline::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10412950
// Name: _dynamic_initializer_for__g_CKnife_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CKnife_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CKnife_ClassReg,
           pNetworkName: "CKnife",
           pTable: &DT_WeaponKnife::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041E7B0
// Name: _ServerClassInit_DT_ProxyToggle::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_ProxyToggle::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_132;
  for ( i = 2; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041E7D0
// Name: _dynamic_atexit_destructor_for__cc_Test_ProxyToggle_EnableProxy__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cc_Test_ProxyToggle_EnableProxy__()
{
  ConCommand::~ConCommand(this: &cc_Test_ProxyToggle_EnableProxy);
}

//------------------------------------------------------------------------------
// Address: 0x1041E7E0
// Name: _dynamic_atexit_destructor_for__cc_Test_ProxyToggle_SetValue__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cc_Test_ProxyToggle_SetValue__()
{
  ConCommand::~ConCommand(this: &cc_Test_ProxyToggle_SetValue);
}

//------------------------------------------------------------------------------
// Address: 0x1041E7F0
// Name: _ServerClassInit_DT_ProxyToggle_ProxiedData::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_ProxyToggle_ProxiedData::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_224;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041E810
// Name: _dynamic_atexit_destructor_for__cc_Test_InitRandomEntitySpawner__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cc_Test_InitRandomEntitySpawner__()
{
  ConCommand::~ConCommand(this: &cc_Test_InitRandomEntitySpawner);
}

//------------------------------------------------------------------------------
// Address: 0x1041E820
// Name: _dynamic_atexit_destructor_for__cc_Test_SpawnRandomEntities__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cc_Test_SpawnRandomEntities__()
{
  ConCommand::~ConCommand(this: &cc_Test_SpawnRandomEntities);
}

//------------------------------------------------------------------------------
// Address: 0x1041E830
// Name: _dynamic_atexit_destructor_for__cc_Test_RandomizeInPVS__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cc_Test_RandomizeInPVS__()
{
  ConCommand::~ConCommand(this: &cc_Test_RandomizeInPVS);
}

//------------------------------------------------------------------------------
// Address: 0x1041E840
// Name: _dynamic_atexit_destructor_for__cc_Test_RemoveAllRandomEntities__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cc_Test_RemoveAllRandomEntities__()
{
  ConCommand::~ConCommand(this: &cc_Test_RemoveAllRandomEntities);
}

//------------------------------------------------------------------------------
// Address: 0x1041E850
// Name: _dynamic_atexit_destructor_for__g_StressEntityRegs__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_StressEntityRegs__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_StressEntityRegs);
}

//------------------------------------------------------------------------------
// Address: 0x1041E860
// Name: _dynamic_atexit_destructor_for__g_StressEntities__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_StressEntities__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_StressEntities);
}

//------------------------------------------------------------------------------
// Address: 0x1041E870
// Name: _dynamic_atexit_destructor_for__cc_Test_CreateEntity__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cc_Test_CreateEntity__()
{
  ConCommand::~ConCommand(this: &cc_Test_CreateEntity);
}

//------------------------------------------------------------------------------
// Address: 0x1041E880
// Name: _dynamic_atexit_destructor_for__cc_Test_RandomPlayerPosition__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cc_Test_RandomPlayerPosition__()
{
  ConCommand::~ConCommand(this: &cc_Test_RandomPlayerPosition);
}
