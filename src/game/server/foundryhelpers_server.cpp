// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/foundryhelpers_server.cpp
// Functions: 38
// ============================================================

#include "game\server\foundryhelpers_server.h"

//------------------------------------------------------------------------------
// Address: 0x1012D0D0
// Name: public: virtual class ServerClass __near * CTEFoundryHelpers::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CTEFoundryHelpers::GetServerClass(CTEFoundryHelpers *this)
{
  return &g_CTEFoundryHelpers_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x1012D0E0
// Name: foundry_sync_hammer_view
// Source: json
//------------------------------------------------------------------------------
void __cdecl foundry_sync_hammer_view()
{
  CBasePlayer *ListenServerHost; // esi
  Vector vPos; // [esp+0h] [ebp-18h] BYREF
  QAngle vAngles; // [esp+Ch] [ebp-Ch] BYREF

  if ( serverfoundry != nullptr )
  {
    ListenServerHost = UTIL_GetListenServerHost();
    if ( ListenServerHost != nullptr )
    {
      ListenServerHost->EyePosition(this: ListenServerHost, result: &vPos);
      vAngles = ListenServerHost->pl.v_angle;
      serverfoundry->MoveHammerViewTo(this: serverfoundry, a2: &vPos, a3: &vAngles);
    }
  }
  else
  {
    _Warning(a1: "Not in Foundry mode.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012D150
// Name: foundry_engine_get_mouse_control
// Source: json
//------------------------------------------------------------------------------
void __cdecl foundry_engine_get_mouse_control()
{
  if ( serverfoundry != nullptr )
  {
    if ( UTIL_GetListenServerHost() != nullptr )
      serverfoundry->EngineGetMouseControl(this: serverfoundry);
  }
  else
  {
    _Warning(a1: "Not in Foundry mode.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012D180
// Name: foundry_engine_release_mouse_control
// Source: json
//------------------------------------------------------------------------------
void __cdecl foundry_engine_release_mouse_control()
{
  if ( serverfoundry != nullptr )
  {
    if ( UTIL_GetListenServerHost() != nullptr )
      serverfoundry->EngineReleaseMouseControl(this: serverfoundry);
  }
  else
  {
    _Warning(a1: "Not in Foundry mode.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012D250
// Name: void FoundryHelpers_ClearEntityHighlightEffects(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FoundryHelpers_ClearEntityHighlightEffects()
{
  CBroadcastRecipientFilter filter; // [esp+4h] [ebp-20h] BYREF

  if ( g_TEFoundryHelpers.m_iEntity.m_Value != -1 )
    g_TEFoundryHelpers.m_iEntity.m_Value = -1;
  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CBroadcastRecipientFilter_vtbl *)&CBroadcastRecipientFilter::`vftable';
  CRecipientFilter::AddAllPlayers(this: &filter);
  CBaseTempEntity::Create(this: &g_TEFoundryHelpers, &filter, delay: 0.0);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x1012D2A0
// Name: void GetCrosshairOrNamedEntities(class CCommand const __near &,class CUtlVector<class CBaseEntity __near *,class CUtlMemory<class CBaseEntity __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetCrosshairOrNamedEntities(
        const CCommand *args,
        CUtlVector<CBaseEntity *,CUtlMemory<CBaseEntity *,int> > *entities)
{
  CBasePlayer *CommandClient; // esi
  Vector *(__thiscall *EyePosition)(CBaseEntity *, Vector *); // edx
  float *v4; // eax
  Vector *(__thiscall *v5)(CBaseEntity *, Vector *); // edx
  const Vector *v6; // eax
  int v7; // edi
  int v8; // eax
  CBaseEntity **v9; // ecx
  int v10; // eax
  CBaseEntity **v11; // edi
  const char *v12; // eax
  CBasePlayer *i; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CBaseEntity **m_pMemory; // ecx
  int v17; // eax
  CBaseEntity **v18; // edi
  const char *v19; // eax
  CGameTrace tr; // [esp+8h] [ebp-90h] BYREF
  Vector vecAbsEnd; // [esp+5Ch] [ebp-3Ch] BYREF
  Vector v22; // [esp+68h] [ebp-30h] BYREF
  Vector forward; // [esp+74h] [ebp-24h] BYREF
  unsigned int mask[3]; // [esp+80h] [ebp-18h] BYREF
  float v25; // [esp+8Ch] [ebp-Ch]
  float v26; // [esp+90h] [ebp-8h]
  float v27; // [esp+94h] [ebp-4h]
  IHandleEntity savedregs; // [esp+98h] [ebp+0h] BYREF

  if ( args->m_nArgc >= 2 )
  {
    v12 = CCommand::operator[](this: args, nIndex: 1);
    for ( i = CGlobalEntityList::FindEntityGeneric(
                this: &gEntList,
                pStartEntity: nullptr,
                szName: v12,
                pSearchingEntity: nullptr,
                pActivator: nullptr,
                pCaller: nullptr);
          i != nullptr;
          i = CGlobalEntityList::FindEntityGeneric(
                this: &gEntList,
                pStartEntity: i,
                szName: v19,
                pSearchingEntity: nullptr,
                pActivator: nullptr,
                pCaller: nullptr) )
    {
      m_Size = entities->m_Size;
      m_nAllocationCount = entities->m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CNavLadder *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)entities,
          num: m_Size - m_nAllocationCount + 1);
      ++entities->m_Size;
      m_pMemory = entities->m_Memory.m_pMemory;
      v17 = entities->m_Size - m_Size - 1;
      entities->m_pElements = entities->m_Memory.m_pMemory;
      if ( v17 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v17);
      v18 = &entities->m_Memory.m_pMemory[m_Size];
      if ( v18 != nullptr )
        *v18 = i;
      v19 = CCommand::operator[](this: args, nIndex: 1);
    }
  }
  else
  {
    CommandClient = UTIL_GetCommandClient();
    CBasePlayer::EyeVectors(this: CommandClient, pForward: &forward, pRight: nullptr, pUp: nullptr);
    EyePosition = CommandClient->EyePosition;
    v25 = forward.x * 16384.0;
    v26 = forward.y * 16384.0;
    v27 = forward.z * 16384.0;
    v4 = (float *)EyePosition(this: CommandClient, result: &v22);
    v5 = CommandClient->EyePosition;
    *(float *)mask = *v4 + v25;
    *(float *)&mask[1] = v4[1] + v26;
    *(float *)&mask[2] = v4[2] + v27;
    v6 = (const Vector *)((int (__thiscall *)(CBasePlayer *))v5)(a1: CommandClient);
    UTIL_TraceLine(
      a1: &savedregs,
      a2: (int)CommandClient,
      vecAbsStart: v6,
      &vecAbsEnd,
      (unsigned int)mask,
      ignore: (const IHandleEntity *)0x600400B,
      collisionGroup: (int)CommandClient,
      ptr: nullptr);
    if ( (tr.fraction < 1.0 || tr.allsolid || tr.startsolid) && !CGameTrace::DidHitWorld(this: &tr) )
    {
      v7 = entities->m_Size;
      v8 = entities->m_Memory.m_nAllocationCount;
      if ( v7 + 1 > v8 )
        CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)entities, num: v7 - v8 + 1);
      ++entities->m_Size;
      v9 = entities->m_Memory.m_pMemory;
      v10 = entities->m_Size - v7 - 1;
      entities->m_pElements = entities->m_Memory.m_pMemory;
      if ( v10 > 0 )
        _V_memmove(dest: &v9[v7 + 1], src: &v9[v7], count: 4 * v10);
      v11 = &entities->m_Memory.m_pMemory[v7];
      if ( v11 != nullptr )
        *v11 = tr.m_pEnt;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012D4A0
// Name: foundry_update_entity
// Source: json
//------------------------------------------------------------------------------
void __cdecl foundry_update_entity(const CCommand *args)
{
  int v1; // edi
  int m_Size; // ebx
  CBaseEntity *v3; // esi
  CUtlVector<CBaseEntity *,CUtlMemory<CBaseEntity *,int> > entities; // [esp+4h] [ebp-14h] BYREF
  int savedregs; // [esp+18h] [ebp+0h] BYREF

  v1 = 0;
  if ( serverfoundry != nullptr )
  {
    if ( UTIL_GetListenServerHost() != nullptr )
    {
      memset(&entities, 0, sizeof(entities));
      GetCrosshairOrNamedEntities(args, &entities);
      m_Size = entities.m_Size;
      if ( entities.m_Size > 0 )
      {
        do
        {
          v3 = entities.m_Memory.m_pMemory[v1];
          if ( (v3->m_iEFlags & 0x800) != 0 )
            CBaseEntity::CalcAbsolutePosition(this: entities.m_Memory.m_pMemory[v1], a2: (int)&savedregs);
          if ( (v3->m_iEFlags & 0x800) != 0 )
            CBaseEntity::CalcAbsolutePosition(this: v3, a2: (int)&savedregs);
          serverfoundry->MoveEntityTo(
            this: serverfoundry,
            a2: v3->m_iHammerID,
            a3: &v3->m_vecAbsOrigin,
            a4: &v3->m_angAbsRotation);
          ++v1;
        }
        while ( v1 < m_Size );
      }
      if ( entities.m_Memory.m_nGrowSize >= 0 && entities.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: entities.m_Memory.m_pMemory);
    }
  }
  else
  {
    _Warning(a1: "Not in Foundry mode.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012D580
// Name: foundry_select_entity
// Source: json
//------------------------------------------------------------------------------
void __cdecl foundry_select_entity(const CCommand *args)
{
  IServerFoundry *m_Size; // esi
  int *m_pMemory; // ebx
  int m_nAllocationCount; // ecx
  int v4; // eax
  IServerFoundry *v5; // edi
  int *v6; // edi
  CBasePlayer *ListenServerHost; // eax
  CBasePlayer *v8; // edi
  CUtlVector<CBaseEntity *,CUtlMemory<CBaseEntity *,int> > entities; // [esp+Ch] [ebp-48h] BYREF
  CUtlVector<int,CUtlMemory<int,int> > hammerIDs; // [esp+20h] [ebp-34h] BYREF
  Vector vPos; // [esp+34h] [ebp-20h] BYREF
  QAngle vAngles; // [esp+40h] [ebp-14h] BYREF
  int m_iHammerID; // [esp+4Ch] [ebp-8h]
  int i; // [esp+50h] [ebp-4h]

  m_Size = nullptr;
  memset(&entities, 0, sizeof(entities));
  GetCrosshairOrNamedEntities(args, &entities);
  m_pMemory = nullptr;
  m_nAllocationCount = 0;
  v4 = 0;
  memset(&hammerIDs, 0, sizeof(hammerIDs));
  i = 0;
  if ( entities.m_Size <= 0 )
    goto LABEL_12;
  while ( 1 )
  {
    m_iHammerID = entities.m_Memory.m_pMemory[v4]->m_iHammerID;
    v5 = m_Size;
    if ( (int)&m_Size->__vftable + 1 > m_nAllocationCount )
    {
      CUtlMemory<CNavLadder *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&hammerIDs,
        num: (int)&m_Size->__vftable - m_nAllocationCount + 1);
      m_Size = (IServerFoundry *)hammerIDs.m_Size;
      m_pMemory = hammerIDs.m_Memory.m_pMemory;
    }
    m_Size = (IServerFoundry *)((char *)m_Size + 1);
    hammerIDs.m_Size = (int)m_Size;
    hammerIDs.m_pElements = m_pMemory;
    if ( (char *)m_Size - (char *)v5 - 1 > 0 )
      _V_memmove(
        dest: &m_pMemory[(_DWORD)v5 + 1],
        src: &m_pMemory[(_DWORD)v5],
        count: 4 * ((char *)m_Size - (char *)v5 - 1));
    v6 = &m_pMemory[(_DWORD)v5];
    if ( v6 != nullptr )
      *v6 = m_iHammerID;
    v4 = i + 1;
    i = v4;
    if ( v4 >= entities.m_Size )
      break;
    m_nAllocationCount = hammerIDs.m_Memory.m_nAllocationCount;
  }
  if ( m_Size != nullptr )
  {
    serverfoundry->SelectEntities(this: serverfoundry, a2: m_pMemory, a3: (int)m_Size);
    m_Size = nullptr;
  }
  else
  {
LABEL_12:
    if ( serverfoundry == m_Size )
    {
      _Warning(a1: "Not in Foundry mode.\n");
LABEL_15:
      CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&hammerIDs);
      CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&entities);
      return;
    }
    ListenServerHost = UTIL_GetListenServerHost();
    v8 = ListenServerHost;
    if ( ListenServerHost == (CBasePlayer *)m_Size )
      goto LABEL_15;
    ListenServerHost->EyePosition(this: ListenServerHost, result: &vPos);
    vAngles = v8->pl.v_angle;
    serverfoundry->SelectionClickInCenterOfView(this: serverfoundry, a2: &vPos, a3: &vAngles);
  }
  if ( hammerIDs.m_Memory.m_nGrowSize >= (int)m_Size && m_pMemory != (int *)m_Size )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  if ( entities.m_Memory.m_nGrowSize >= (int)m_Size && (IServerFoundry *)entities.m_Memory.m_pMemory != m_Size )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: entities.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10403770
// Name: DT_TEFoundryHelpers::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEFoundryHelpers::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_TEFoundryHelpers::g_SendTable);
  return atexit(func: DT_TEFoundryHelpers::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10403790
// Name: DT_TEFoundryHelpers::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEFoundryHelpers::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_TEFoundryHelpers::ignored>();
  DT_TEFoundryHelpers::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104037D0
// Name: _dynamic_initializer_for__foundry_update_entity_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__foundry_update_entity_command__()
{
  ConCommand::ConCommand(
    this: &foundry_update_entity_command,
    pName: "foundry_update_entity",
    callback: (void (__cdecl *)())foundry_update_entity,
    pHelpString: "Updates the entity's position/angles when in edit mode",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__foundry_update_entity_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10403800
// Name: _dynamic_initializer_for__foundry_sync_hammer_view_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__foundry_sync_hammer_view_command__()
{
  ConCommand::ConCommand(
    this: &foundry_sync_hammer_view_command,
    pName: "foundry_sync_hammer_view",
    callback: foundry_sync_hammer_view,
    pHelpString: "Move Hammer's 3D view to the same position as the engine's 3D view.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__foundry_sync_hammer_view_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10403830
// Name: _dynamic_initializer_for__foundry_engine_get_mouse_control_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__foundry_engine_get_mouse_control_command__()
{
  ConCommand::ConCommand(
    this: &foundry_engine_get_mouse_control_command,
    pName: "foundry_engine_get_mouse_control",
    callback: foundry_engine_get_mouse_control,
    pHelpString: "Give the engine control of the mouse.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__foundry_engine_get_mouse_control_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10403860
// Name: _dynamic_initializer_for__foundry_engine_release_mouse_control_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__foundry_engine_release_mouse_control_command__()
{
  ConCommand::ConCommand(
    this: &foundry_engine_release_mouse_control_command,
    pName: "foundry_engine_release_mouse_control",
    callback: foundry_engine_release_mouse_control,
    pHelpString: "Give the control of the mouse back to Hammer.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__foundry_engine_release_mouse_control_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10403890
// Name: _dynamic_initializer_for__foundry_select_entity_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__foundry_select_entity_command__()
{
  ConCommand::ConCommand(
    this: &foundry_select_entity_command,
    pName: "foundry_select_entity",
    callback: (void (__cdecl *)())foundry_select_entity,
    pHelpString: "Select the entity under the crosshair or select entities with the specified name.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__foundry_select_entity_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1041B4E0
// Name: DT_TEFoundryHelpers::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEFoundryHelpers::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_TEFoundryHelpers::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041B500
// Name: _dynamic_atexit_destructor_for__foundry_update_entity_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__foundry_update_entity_command__()
{
  ConCommand::~ConCommand(this: &foundry_update_entity_command);
}

//------------------------------------------------------------------------------
// Address: 0x1041B510
// Name: _dynamic_atexit_destructor_for__foundry_sync_hammer_view_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__foundry_sync_hammer_view_command__()
{
  ConCommand::~ConCommand(this: &foundry_sync_hammer_view_command);
}

//------------------------------------------------------------------------------
// Address: 0x1041B520
// Name: _dynamic_atexit_destructor_for__foundry_engine_get_mouse_control_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__foundry_engine_get_mouse_control_command__()
{
  ConCommand::~ConCommand(this: &foundry_engine_get_mouse_control_command);
}

//------------------------------------------------------------------------------
// Address: 0x1041B530
// Name: _dynamic_atexit_destructor_for__foundry_engine_release_mouse_control_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__foundry_engine_release_mouse_control_command__()
{
  ConCommand::~ConCommand(this: &foundry_engine_release_mouse_control_command);
}

//------------------------------------------------------------------------------
// Address: 0x1041B540
// Name: _dynamic_atexit_destructor_for__foundry_select_entity_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__foundry_select_entity_command__()
{
  ConCommand::~ConCommand(this: &foundry_select_entity_command);
}

//------------------------------------------------------------------------------
// Address: 0x104037A0
// Name: _dynamic_initializer_for__g_TEFoundryHelpers__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TEFoundryHelpers__()
{
  CBaseTempEntity::CBaseTempEntity(this: &g_TEFoundryHelpers, name: "FoundryHelpers");
  g_TEFoundryHelpers.__vftable = (CTEFoundryHelpers_vtbl *)&CTEFoundryHelpers::`vftable';
  return atexit(func: dynamic_atexit_destructor_for__g_TEFoundryHelpers__);
}

//------------------------------------------------------------------------------
// Address: 0x104038C0
// Name: _dynamic_initializer_for__r_vehicleBrakeRate__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_vehicleBrakeRate__()
{
  ConVar::ConVar(this: &r_vehicleBrakeRate, pName: "r_vehicleBrakeRate", pDefaultValue: "1.5", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_vehicleBrakeRate__);
}

//------------------------------------------------------------------------------
// Address: 0x104038F0
// Name: _dynamic_initializer_for__xbox_throttlebias__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__xbox_throttlebias__()
{
  ConVar::ConVar(this: &xbox_throttlebias, pName: "xbox_throttlebias", pDefaultValue: "100", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__xbox_throttlebias__);
}

//------------------------------------------------------------------------------
// Address: 0x10403920
// Name: _dynamic_initializer_for__xbox_throttlespoof__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__xbox_throttlespoof__()
{
  ConVar::ConVar(this: &xbox_throttlespoof, pName: "xbox_throttlespoof", pDefaultValue: "200", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__xbox_throttlespoof__);
}

//------------------------------------------------------------------------------
// Address: 0x10403950
// Name: _dynamic_initializer_for__xbox_autothrottle__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__xbox_autothrottle__()
{
  ConVar::ConVar(this: &xbox_autothrottle, pName: "xbox_autothrottle", pDefaultValue: "1", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__xbox_autothrottle__);
}

//------------------------------------------------------------------------------
// Address: 0x10403980
// Name: _dynamic_initializer_for__xbox_steering_deadzone__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__xbox_steering_deadzone__()
{
  ConVar::ConVar(this: &xbox_steering_deadzone, pName: "xbox_steering_deadzone", pDefaultValue: "0.0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__xbox_steering_deadzone__);
}

//------------------------------------------------------------------------------
// Address: 0x1041B4F0
// Name: _dynamic_atexit_destructor_for__g_TEFoundryHelpers__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TEFoundryHelpers__()
{
  CBaseTempEntity::~CBaseTempEntity(this: &g_TEFoundryHelpers);
}

//------------------------------------------------------------------------------
// Address: 0x1041B550
// Name: _ServerClassInit_DT_TEFoundryHelpers::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_TEFoundryHelpers::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_109;
  for ( i = 2; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041B570
// Name: _dynamic_atexit_destructor_for__r_vehicleBrakeRate__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_vehicleBrakeRate__()
{
  ConVar::~ConVar(this: &r_vehicleBrakeRate);
}

//------------------------------------------------------------------------------
// Address: 0x1041B580
// Name: _dynamic_atexit_destructor_for__xbox_throttlebias__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__xbox_throttlebias__()
{
  ConVar::~ConVar(this: &xbox_throttlebias);
}

//------------------------------------------------------------------------------
// Address: 0x1041B590
// Name: _dynamic_atexit_destructor_for__xbox_throttlespoof__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__xbox_throttlespoof__()
{
  ConVar::~ConVar(this: &xbox_throttlespoof);
}

//------------------------------------------------------------------------------
// Address: 0x1041B5A0
// Name: _dynamic_atexit_destructor_for__xbox_autothrottle__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__xbox_autothrottle__()
{
  ConVar::~ConVar(this: &xbox_autothrottle);
}

//------------------------------------------------------------------------------
// Address: 0x1041B5B0
// Name: _dynamic_atexit_destructor_for__xbox_steering_deadzone__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__xbox_steering_deadzone__()
{
  ConVar::~ConVar(this: &xbox_steering_deadzone);
}

//------------------------------------------------------------------------------
// Address: 0x1041B5C0
// Name: _DataMapInit_CFourWheelVehiclePhysics__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CFourWheelVehiclePhysics__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_207);
}

//------------------------------------------------------------------------------
// Address: 0x1041B5D0
// Name: _DataMapInit_CAreaPortal__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CAreaPortal__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_208);
}

//------------------------------------------------------------------------------
// Address: 0x1041B5E0
// Name: _dynamic_atexit_destructor_for__g_AreaPortals__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_AreaPortals__()
{
  CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<CBaseCombatWeapon *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBaseCombatWeapon *,unsigned short>,unsigned short> > *)&g_AreaPortals);
  if ( g_AreaPortals.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_AreaPortals.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_AreaPortals.m_Memory.m_pMemory);
      g_AreaPortals.m_Memory.m_pMemory = nullptr;
    }
    g_AreaPortals.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1041B630
// Name: _DataMapInit_CFuncAreaPortalBase__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CFuncAreaPortalBase__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_209);
}
