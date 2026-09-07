// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/testtraceline.cpp
// Functions: 42
// ============================================================

#include "game\server\testtraceline.h"

//------------------------------------------------------------------------------
// Address: 0x10233BC0
// Name: public: virtual class ServerClass __near * CTestTraceline::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CTestTraceline::GetServerClass(CTestTraceline *this)
{
  return &g_CTestTraceline_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10233BD0
// Name: public: virtual struct datamap_t __near * CTestTraceline::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CTestTraceline::GetDataDescMap(CTestTraceline *this)
{
  return &CTestTraceline::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10233DA0
// Name: private: void CTestTraceline::Spin(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTestTraceline::Spin(CTestTraceline *this)
{
  CGlobalVars *v2; // edi
  float z; // eax
  double v4; // xmm0_8
  QAngle angles; // [esp+Ch] [ebp-Ch] BYREF

  if ( (_S4_61 & 1) == 0 )
  {
    _S4_61 |= 1u;
    ConVar::ConVar(this: &traceline_spin, pName: "traceline_spin", pDefaultValue: "1", flags: 0);
    atexit(func: CTestTraceline::Spin_::_2_::_dynamic_atexit_destructor_for__traceline_spin__);
  }
  if ( traceline_spin.m_pParent != nullptr && traceline_spin.m_pParent->m_Value.m_nValue != 0 )
  {
    v2 = gpGlobals;
    __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(gpGlobals->curtime)));
    z = this->m_angRotation.m_Value.z;
    angles.y = this->m_angRotation.m_Value.y;
    *(float *)&v4 = v4;
    angles.z = z;
    angles.x = (float)((float)((float)((float)(*(float *)&v4 * *(float *)&v4) * *(float *)&v4) + 1.0) + 1.0) * 90.0;
    angles.y = v2->curtime * 10.0;
    CBaseEntity::SetLocalAngles(this, &angles);
  }
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10233FC0
// Name: public: virtual void CTestTraceline::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTestTraceline::Spawn(CTestTraceline *this)
{
  edict_t *m_pPev; // ecx

  CNetworkColor32Base<color32_s,CBaseEntity::NetworkVar_m_clrRender>::Init(
    this: &this->m_clrRender,
    rVal: 0xFFu,
    gVal: 0xFFu,
    bVal: 0xFFu);
  if ( this->m_clrRender.m_Value.a != 0xFF )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xB8u);
    }
    this->m_clrRender.m_Value.a = -1;
  }
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CTestTraceline::Spin,
    thinkTime: 0.0,
    szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x104047F0
// Name: _dynamic_initializer_for__trace_report__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__trace_report__()
{
  ConVar::ConVar(this: &trace_report, pName: "trace_report", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__trace_report__);
}

//------------------------------------------------------------------------------
// Address: 0x1040B7A0
// Name: DT_TestTraceline::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TestTraceline::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_TestTraceline::g_SendTable);
  return atexit(func: DT_TestTraceline::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1040B7C0
// Name: DT_TestTraceline::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TestTraceline::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_TestTraceline::ignored>();
  DT_TestTraceline::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040B7F0
// Name: CTestTraceline_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CTestTraceline_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CTestTraceline>();
  CTestTraceline_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041BB70
// Name: _dynamic_atexit_destructor_for__trace_report__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__trace_report__()
{
  ConVar::~ConVar(this: &trace_report);
}

//------------------------------------------------------------------------------
// Address: 0x1041E890
// Name: DT_TestTraceline::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TestTraceline::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_TestTraceline::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041E8A0
// Name: _CTestTraceline::Spin_::_2_::_dynamic_atexit_destructor_for__traceline_spin__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CTestTraceline::Spin_::_2_::_dynamic_atexit_destructor_for__traceline_spin__()
{
  ConVar::~ConVar(this: &traceline_spin);
}

//------------------------------------------------------------------------------
// Address: 0x10404820
// Name: _dynamic_initializer_for__motdfile__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__motdfile__()
{
  ConVar::ConVar(
    this: &motdfile,
    pName: "motdfile",
    pDefaultValue: "motd.txt",
    flags: 0x80000,
    pHelpString: "The MOTD file to load.",
    callback: (void (__cdecl *)(IConVar *, const char *, float))ValidateMOTDFilename);
  return atexit(func: dynamic_atexit_destructor_for__motdfile__);
}

//------------------------------------------------------------------------------
// Address: 0x10404850
// Name: _dynamic_initializer_for__hostfile__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__hostfile__()
{
  ConVar::ConVar(
    this: &hostfile,
    pName: "hostfile",
    pDefaultValue: "host.txt",
    flags: 0x80000,
    pHelpString: "The HOST file to load.",
    callback: (void (__cdecl *)(IConVar *, const char *, float))ValidateMOTDFilename);
  return atexit(func: dynamic_atexit_destructor_for__hostfile__);
}

//------------------------------------------------------------------------------
// Address: 0x10404880
// Name: _dynamic_initializer_for__sv_unlockedchapters__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_unlockedchapters__()
{
  ConVar::ConVar(this: &sv_unlockedchapters, pName: "sv_unlockedchapters", pDefaultValue: "1", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__sv_unlockedchapters__);
}

//------------------------------------------------------------------------------
// Address: 0x104048B0
// Name: _dynamic_initializer_for____g_CServerGameEnts_singleton__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____g_CServerGameEnts_singleton__()
{
  return atexit(func: dynamic_atexit_destructor_for____g_CServerGameEnts_singleton__);
}

//------------------------------------------------------------------------------
// Address: 0x104048C0
// Name: _dynamic_initializer_for____g_CreateCServerGameEntsIServerGameEnts_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerGameEntsIServerGameEnts_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerGameEntsIServerGameEnts_reg,
           fn: (void *(__cdecl *)())_CreateCServerGameEntsIServerGameEnts_interface,
           pName: "ServerGameEnts001");
}

//------------------------------------------------------------------------------
// Address: 0x104048E0
// Name: _dynamic_initializer_for____g_CreateCServerGameClientsIServerGameClients_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerGameClientsIServerGameClients_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerGameClientsIServerGameClients_reg,
           fn: (void *(__cdecl *)())_CreateCServerGameClientsIServerGameClients_interface,
           pName: "ServerGameClients004");
}

//------------------------------------------------------------------------------
// Address: 0x10404900
// Name: _dynamic_initializer_for____g_CServerDLLSharedAppSystems_singleton__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____g_CServerDLLSharedAppSystems_singleton__()
{
  AI_NamespaceAddInfo_t src; // [esp+0h] [ebp-8h] BYREF

  src.pszName = "soundemittersystem";
  src.localId = (int)"VSoundEmitter003";
  CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>::InsertBefore(
    this: (CUtlVector<AI_NamespaceAddInfo_t,CUtlMemory<AI_NamespaceAddInfo_t,int> > *)&_g_CServerDLLSharedAppSystems_singleton.m_Systems,
    elem: 0,
    &src);
  src.pszName = "scenefilecache";
  src.localId = (int)"SceneFileCache002";
  CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>::InsertBefore(
    this: (CUtlVector<AI_NamespaceAddInfo_t,CUtlMemory<AI_NamespaceAddInfo_t,int> > *)&_g_CServerDLLSharedAppSystems_singleton.m_Systems,
    elem: _g_CServerDLLSharedAppSystems_singleton.m_Systems.m_Size,
    &src);
  return atexit(func: dynamic_atexit_destructor_for____g_CServerDLLSharedAppSystems_singleton__);
}

//------------------------------------------------------------------------------
// Address: 0x10404960
// Name: _dynamic_initializer_for____g_CreateCServerDLLSharedAppSystemsIServerDLLSharedAppSystems_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerDLLSharedAppSystemsIServerDLLSharedAppSystems_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerDLLSharedAppSystemsIServerDLLSharedAppSystems_reg,
           fn: (void *(__cdecl *)())_CreateCServerDLLSharedAppSystemsIServerDLLSharedAppSystems_interface,
           pName: "VServerDllSharedAppSystems001");
}

//------------------------------------------------------------------------------
// Address: 0x10404980
// Name: _dynamic_initializer_for__dispcoll_drawplane__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__dispcoll_drawplane__()
{
  ConVar::ConVar(this: &dispcoll_drawplane, pName: "dispcoll_drawplane", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__dispcoll_drawplane__);
}

//------------------------------------------------------------------------------
// Address: 0x104049B0
// Name: _dynamic_initializer_for__s_TraceFilter__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CTraceFilterSkipTwoEntities *dynamic_initializer_for__s_TraceFilter__()
{
  CTraceFilterSkipTwoEntities *v0; // esi
  int i; // edi
  CTraceFilterSkipTwoEntities *result; // eax

  v0 = &s_TraceFilter;
  for ( i = 7; i >= 0; --i )
  {
    result = CTraceFilterSkipTwoEntities::CTraceFilterSkipTwoEntities(
               this: v0,
               passentity: nullptr,
               passentity2: nullptr,
               collisionGroup: 0);
    v0->__vftable = (CTraceFilterSkipTwoEntities_vtbl *)&CTraceFilterSkipTwoEntitiesAndCheckTeamMask::`vftable';
    ++v0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104049E0
// Name: _dynamic_initializer_for__sv_ladder_dampen__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_ladder_dampen__()
{
  ConVar::ConVar(
    this: &sv_ladder_dampen,
    pName: "sv_ladder_dampen",
    pDefaultValue: "0.2",
    flags: 0x2000,
    pHelpString: "Amount to dampen perpendicular movement on a ladder",
    bMin: true,
    fMin: 0.0,
    bMax: true,
    fMax: 1.0);
  return atexit(func: dynamic_atexit_destructor_for__sv_ladder_dampen__);
}

//------------------------------------------------------------------------------
// Address: 0x10404A30
// Name: _dynamic_initializer_for__sv_ladder_angle__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_ladder_angle__()
{
  ConVar::ConVar(
    this: &sv_ladder_angle,
    pName: "sv_ladder_angle",
    pDefaultValue: "-0.707",
    flags: 0x2000,
    pHelpString: "Cos of angle of incidence to ladder perpendicular for applying ladder_dampen",
    bMin: true,
    fMin: -1.0,
    bMax: true,
    fMax: 1.0);
  return atexit(func: dynamic_atexit_destructor_for__sv_ladder_angle__);
}

//------------------------------------------------------------------------------
// Address: 0x10404A80
// Name: _dynamic_initializer_for__sv_optimizedmovement__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_optimizedmovement__()
{
  ConVar::ConVar(this: &sv_optimizedmovement, pName: "sv_optimizedmovement", pDefaultValue: "1", flags: 8194);
  return atexit(func: dynamic_atexit_destructor_for__sv_optimizedmovement__);
}

//------------------------------------------------------------------------------
// Address: 0x10404AB0
// Name: _dynamic_initializer_for__g_Language__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Language__()
{
  ConVar::ConVar(this: &g_Language, pName: "g_Language", pDefaultValue: "0", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__g_Language__);
}

//------------------------------------------------------------------------------
// Address: 0x10404AE0
// Name: _dynamic_initializer_for__sk_autoaim_mode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sk_autoaim_mode__()
{
  ConVar::ConVar(this: &sk_autoaim_mode, pName: "sk_autoaim_mode", pDefaultValue: "1", flags: 8320);
  return atexit(func: dynamic_atexit_destructor_for__sk_autoaim_mode__);
}

//------------------------------------------------------------------------------
// Address: 0x10404B10
// Name: _dynamic_initializer_for__g_CGameRulesProxy_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CGameRulesProxy_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CGameRulesProxy_ClassReg,
           pNetworkName: "CGameRulesProxy",
           pTable: &DT_GameRulesProxy::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041BB80
// Name: _dynamic_atexit_destructor_for__motdfile__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__motdfile__()
{
  ConVar::~ConVar(this: &motdfile);
}

//------------------------------------------------------------------------------
// Address: 0x1041BB90
// Name: _dynamic_atexit_destructor_for__hostfile__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__hostfile__()
{
  ConVar::~ConVar(this: &hostfile);
}

//------------------------------------------------------------------------------
// Address: 0x1041BBA0
// Name: _dynamic_atexit_destructor_for__sv_unlockedchapters__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_unlockedchapters__()
{
  ConVar::~ConVar(this: &sv_unlockedchapters);
}

//------------------------------------------------------------------------------
// Address: 0x1041BBB0
// Name: _dynamic_atexit_destructor_for____g_CServerGameEnts_singleton__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____g_CServerGameEnts_singleton__()
{
  _g_CServerGameEnts_singleton.__vftable = (CServerGameEnts_vtbl *)&IServerGameEnts::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1041BBC0
// Name: _dynamic_atexit_destructor_for__g_MapEntityRefs__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_MapEntityRefs__()
{
  CUtlLinkedList<CRagdollEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRagdollEntry,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<CEnvWindShared::WindVariationEvent_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared::WindVariationEvent_t,unsigned short>,unsigned short> > *)&g_MapEntityRefs);
  if ( g_MapEntityRefs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_MapEntityRefs.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_MapEntityRefs.m_Memory.m_pMemory);
      g_MapEntityRefs.m_Memory.m_pMemory = nullptr;
    }
    g_MapEntityRefs.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1041BC10
// Name: _dynamic_atexit_destructor_for__g_RestoredEntities__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_RestoredEntities__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_RestoredEntities);
}

//------------------------------------------------------------------------------
// Address: 0x1041BC20
// Name: _dynamic_atexit_destructor_for____g_CServerDLLSharedAppSystems_singleton__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____g_CServerDLLSharedAppSystems_singleton__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&_g_CServerDLLSharedAppSystems_singleton.m_Systems);
}

//------------------------------------------------------------------------------
// Address: 0x1041BC30
// Name: _dynamic_atexit_destructor_for__g_NetworkPropertyEventMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_NetworkPropertyEventMgr__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_NetworkPropertyEventMgr);
}

//------------------------------------------------------------------------------
// Address: 0x1041BC40
// Name: _dynamic_atexit_destructor_for__dispcoll_drawplane__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__dispcoll_drawplane__()
{
  ConVar::~ConVar(this: &dispcoll_drawplane);
}

//------------------------------------------------------------------------------
// Address: 0x1041BC50
// Name: _dynamic_atexit_destructor_for__sv_ladder_dampen__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_ladder_dampen__()
{
  ConVar::~ConVar(this: &sv_ladder_dampen);
}

//------------------------------------------------------------------------------
// Address: 0x1041BC60
// Name: _dynamic_atexit_destructor_for__sv_ladder_angle__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_ladder_angle__()
{
  ConVar::~ConVar(this: &sv_ladder_angle);
}

//------------------------------------------------------------------------------
// Address: 0x1041BC70
// Name: _dynamic_atexit_destructor_for__sv_optimizedmovement__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_optimizedmovement__()
{
  ConVar::~ConVar(this: &sv_optimizedmovement);
}

//------------------------------------------------------------------------------
// Address: 0x1041E8B0
// Name: _ServerClassInit_DT_TestTraceline::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_TestTraceline::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_225;
  for ( i = 6; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041E8D0
// Name: _DataMapInit_CTestTraceline__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CTestTraceline__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_417);
}

//------------------------------------------------------------------------------
// Address: 0x1041E8E0
// Name: _CTextStat::GetTextStatsList_::_2_::_dynamic_atexit_destructor_for__theList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl CTextStat::GetTextStatsList_::_2_::_dynamic_atexit_destructor_for__theList__()
{
  *(_DWORD *)(dword_10657DA4 + 4) = dword_10657DA8;
  *(_DWORD *)dword_10657DA8 = dword_10657DA4;
  dword_10657DA8 = (int)&dword_10657DA4;
  dword_10657DA4 = (int)&dword_10657DA4;
  dword_10657DAC = 0;
}
