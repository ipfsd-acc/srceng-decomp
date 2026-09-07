// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/teamplayroundbased_gamerules.cpp
// Functions: 169
// ============================================================

#include "game\shared\teamplayroundbased_gamerules.h"

//------------------------------------------------------------------------------
// Address: 0x10038850
// Name: public: virtual bool C_TeamplayRules::PlayerMayCapturePoint(class C_BasePlayer __near *,int,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_TeamplayRules::PlayerMayCapturePoint(
        C_BaseEntity *this,
        matrix3x4a_t *pBoneToWorldOut,
        matrix3x4a_t *nMaxBones,
        int boneMask,
        float currentTime)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101799C0
// Name: public: virtual class ClientClass __near * C_TeamplayRoundBasedRulesProxy::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_TeamplayRoundBasedRulesProxy::GetClientClass(C_TeamplayRoundBasedRulesProxy *this)
{
  return &__g_C_TeamplayRoundBasedRulesProxyClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10179A70
// Name: void RecvProxy_TeamplayRoundBasedRules(class RecvProp const __near *,void __near * __near *,void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_TeamplayRoundBasedRules(const RecvProp *pProp, void **pOut)
{
  *pOut = __RTDynamicCast(
            inptr: g_pGameRules,
            VfDelta: 0,
            SrcType: &C_GameRules `RTTI Type Descriptor',
            TargetType: &C_TeamplayRoundBasedRules `RTTI Type Descriptor',
            isReference: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10179B30
// Name: public: virtual void C_TeamplayRoundBasedRulesProxy::OnPreDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TeamplayRoundBasedRulesProxy::OnPreDataChanged(
        C_TeamplayRoundBasedRulesProxy *this,
        DataUpdateType_t updateType)
{
  void *v2; // eax

  C_BaseEntity::OnPreDataChanged(this, type: updateType);
  v2 = __RTDynamicCast(
         inptr: g_pGameRules,
         VfDelta: 0,
         SrcType: &C_GameRules `RTTI Type Descriptor',
         TargetType: &C_TeamplayRoundBasedRules `RTTI Type Descriptor',
         isReference: 0);
  (*(void (__thiscall **)(void *, DataUpdateType_t))(*(_DWORD *)v2 + 236))(a1: v2, a2: updateType);
}

//------------------------------------------------------------------------------
// Address: 0x10179B70
// Name: public: virtual void C_TeamplayRoundBasedRulesProxy::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TeamplayRoundBasedRulesProxy::OnDataChanged(
        C_TeamplayRoundBasedRulesProxy *this,
        DataUpdateType_t updateType)
{
  void *v2; // eax

  C_BaseEntity::OnDataChanged(this, type: updateType);
  v2 = __RTDynamicCast(
         inptr: g_pGameRules,
         VfDelta: 0,
         SrcType: &C_GameRules `RTTI Type Descriptor',
         TargetType: &C_TeamplayRoundBasedRules `RTTI Type Descriptor',
         isReference: 0);
  (*(void (__thiscall **)(void *, DataUpdateType_t))(*(_DWORD *)v2 + 240))(a1: v2, a2: updateType);
}

//------------------------------------------------------------------------------
// Address: 0x10179BB0
// Name: void RecvProxy_TeamplayRoundState(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_TeamplayRoundState(const CRecvProxyData *pData, float *pStruct)
{
  vgui::PropertyPage *v2; // ecx
  int m_Int; // edi

  m_Int = pData->m_Value.m_Int;
  if ( *((_DWORD *)pStruct + 10) != m_Int )
  {
    C_BaseAnimating::ShutdownBoneSetupThreadPool(this: v2);
    *((_DWORD *)pStruct + 10) = m_Int;
  }
  pStruct[8] = *(float *)(gpGlobals.m_Index + 12);
}

//------------------------------------------------------------------------------
// Address: 0x10179E00
// Name: public: virtual int C_TeamplayRules::GetCaptureValueForPlayer(class C_BasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_TeamplayRules::GetCaptureValueForPlayer(C_TeamplayRules *this, C_BasePlayer *pPlayer)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10179E10
// Name: public: virtual bool C_TeamplayRules::PlayerMayBlockPoint(class C_BasePlayer __near *,int,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_TeamplayRules::PlayerMayBlockPoint(vgui::Frame *this, int *x, int *y, int *wide, int *tall)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10418CC0
// Name: _dynamic_initializer_for__round_start_reset_duck__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__round_start_reset_duck__()
{
  ConVar::ConVar(this: &round_start_reset_duck, pName: "round_start_reset_duck", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__round_start_reset_duck__);
}

//------------------------------------------------------------------------------
// Address: 0x10418CF0
// Name: _dynamic_initializer_for__round_start_reset_speed__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__round_start_reset_speed__()
{
  ConVar::ConVar(this: &round_start_reset_speed, pName: "round_start_reset_speed", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__round_start_reset_speed__);
}

//------------------------------------------------------------------------------
// Address: 0x1041CB70
// Name: DT_TeamplayRoundBasedRules::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TeamplayRoundBasedRules::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_TeamplayRoundBasedRules::g_RecvTable);
  return atexit(func: DT_TeamplayRoundBasedRules::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1041CB90
// Name: DT_TeamplayRoundBasedRules::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TeamplayRoundBasedRules::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_TeamplayRoundBasedRules::ignored>();
  DT_TeamplayRoundBasedRules::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041CBC0
// Name: DT_TeamplayRoundBasedRulesProxy::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TeamplayRoundBasedRulesProxy::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_TeamplayRoundBasedRulesProxy::g_RecvTable);
  return atexit(func: DT_TeamplayRoundBasedRulesProxy::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1041CBE0
// Name: DT_TeamplayRoundBasedRulesProxy::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TeamplayRoundBasedRulesProxy::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_TeamplayRoundBasedRulesProxy::ignored>();
  DT_TeamplayRoundBasedRulesProxy::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104325E0
// Name: _dynamic_atexit_destructor_for__round_start_reset_duck__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__round_start_reset_duck__()
{
  ConVar::~ConVar(this: &round_start_reset_duck);
}

//------------------------------------------------------------------------------
// Address: 0x104325F0
// Name: _dynamic_atexit_destructor_for__round_start_reset_speed__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__round_start_reset_speed__()
{
  ConVar::~ConVar(this: &round_start_reset_speed);
}

//------------------------------------------------------------------------------
// Address: 0x10433C90
// Name: DT_TeamplayRoundBasedRules::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TeamplayRoundBasedRules::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_TeamplayRoundBasedRules::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10433CA0
// Name: DT_TeamplayRoundBasedRulesProxy::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TeamplayRoundBasedRulesProxy::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_TeamplayRoundBasedRulesProxy::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x101799D0
// Name: _C_TeamplayRoundBasedRulesProxy_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_TeamplayRoundBasedRulesProxy_CreateObject(int entnum, int serialNum)
{
  C_GameRulesProxy *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_GameRulesProxy *)C_BaseEntity::operator new(stAllocateBlock: 0x980u);
  v3 = &v2->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_GameRulesProxy::C_GameRulesProxy(this: v2);
  *v3 = &C_TeamplayRoundBasedRulesProxy::`vftable'{for `IClientUnknown'};
  v3[1] = &C_TeamplayRoundBasedRulesProxy::`vftable'{for `IClientRenderable'};
  v3[2] = &C_TeamplayRoundBasedRulesProxy::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_TeamplayRoundBasedRulesProxy::`vftable'{for `IClientThinkable'};
  v3[4] = &C_TeamplayRoundBasedRulesProxy::`vftable';
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10418D20
// Name: _dynamic_initializer_for__in_forceuser__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__in_forceuser__()
{
  ConVar::ConVar(
    this: &in_forceuser,
    pName: "in_forceuser",
    pDefaultValue: "0",
    flags: 16386,
    pHelpString: "Force user input to this split screen player.");
  return atexit(func: dynamic_atexit_destructor_for__in_forceuser__);
}

//------------------------------------------------------------------------------
// Address: 0x10418D50
// Name: _dynamic_initializer_for__ss_mimic__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ss_mimic__()
{
  ConVar::ConVar(
    this: &ss_mimic,
    pName: "ss_mimic",
    pDefaultValue: "0",
    flags: 16386,
    pHelpString: "Split screen users mimic base player's CUserCmds");
  return atexit(func: dynamic_atexit_destructor_for__ss_mimic__);
}

//------------------------------------------------------------------------------
// Address: 0x10418D80
// Name: _dynamic_initializer_for__ss_teleport_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ss_teleport_command__()
{
  ConCommand::ConCommand(
    this: &ss_teleport_command,
    pName: "ss_teleport",
    callback: ss_teleport,
    pHelpString: "Teleport other splitscreen player to my location.",
    flags: 16386,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__ss_teleport_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10418DB0
// Name: _dynamic_initializer_for__in_usekeyboardsampletime__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__in_usekeyboardsampletime__()
{
  ConVar::ConVar(
    this: &in_usekeyboardsampletime,
    pName: "in_usekeyboardsampletime",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Use keyboard sample time smoothing.");
  return atexit(func: dynamic_atexit_destructor_for__in_usekeyboardsampletime__);
}

//------------------------------------------------------------------------------
// Address: 0x10418DE0
// Name: _dynamic_initializer_for__startcommandermousemove__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__startcommandermousemove__()
{
  ConCommand::ConCommand(
    this: &startcommandermousemove,
    pName: "+commandermousemove",
    callback: (void (__cdecl *)())IN_CommanderMouseMoveDown,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__startcommandermousemove__);
}

//------------------------------------------------------------------------------
// Address: 0x10418E10
// Name: _dynamic_initializer_for__endcommandermousemove__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__endcommandermousemove__()
{
  ConCommand::ConCommand(
    this: &endcommandermousemove,
    pName: "-commandermousemove",
    callback: (void (__cdecl *)())IN_CommanderMouseMoveUp,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__endcommandermousemove__);
}

//------------------------------------------------------------------------------
// Address: 0x10418E40
// Name: _dynamic_initializer_for__startmoveup__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__startmoveup__()
{
  ConCommand::ConCommand(
    this: &startmoveup,
    pName: "+moveup",
    callback: (void (__cdecl *)())IN_UpDown,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__startmoveup__);
}

//------------------------------------------------------------------------------
// Address: 0x10418E70
// Name: _dynamic_initializer_for__endmoveup__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__endmoveup__()
{
  ConCommand::ConCommand(
    this: &endmoveup,
    pName: "-moveup",
    callback: (void (__cdecl *)())IN_UpUp,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__endmoveup__);
}

//------------------------------------------------------------------------------
// Address: 0x10418EA0
// Name: _dynamic_initializer_for__startmovedown__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__startmovedown__()
{
  ConCommand::ConCommand(
    this: &startmovedown,
    pName: "+movedown",
    callback: (void (__cdecl *)())IN_DownDown,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__startmovedown__);
}

//------------------------------------------------------------------------------
// Address: 0x10418ED0
// Name: _dynamic_initializer_for__endmovedown__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__endmovedown__()
{
  ConCommand::ConCommand(
    this: &endmovedown,
    pName: "-movedown",
    callback: (void (__cdecl *)())IN_DownUp,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__endmovedown__);
}

//------------------------------------------------------------------------------
// Address: 0x10418F00
// Name: _dynamic_initializer_for__startleft__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__startleft__()
{
  ConCommand::ConCommand(
    this: &startleft,
    pName: "+left",
    callback: (void (__cdecl *)())IN_LeftDown,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__startleft__);
}

//------------------------------------------------------------------------------
// Address: 0x10418F30
// Name: _dynamic_initializer_for__endleft__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__endleft__()
{
  ConCommand::ConCommand(
    this: &endleft,
    pName: "-left",
    callback: (void (__cdecl *)())IN_LeftUp,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__endleft__);
}

//------------------------------------------------------------------------------
// Address: 0x10418F60
// Name: _dynamic_initializer_for__startright__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__startright__()
{
  ConCommand::ConCommand(
    this: &startright,
    pName: "+right",
    callback: (void (__cdecl *)())IN_RightDown,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__startright__);
}

//------------------------------------------------------------------------------
// Address: 0x10418F90
// Name: _dynamic_initializer_for__endright__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__endright__()
{
  ConCommand::ConCommand(
    this: &endright,
    pName: "-right",
    callback: (void (__cdecl *)())IN_RightUp,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__endright__);
}

//------------------------------------------------------------------------------
// Address: 0x10418FC0
// Name: _dynamic_initializer_for__startforward__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__startforward__()
{
  ConCommand::ConCommand(
    this: &startforward,
    pName: "+forward",
    callback: (void (__cdecl *)())IN_ForwardDown,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__startforward__);
}

//------------------------------------------------------------------------------
// Address: 0x10418FF0
// Name: _dynamic_initializer_for__endforward__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__endforward__()
{
  ConCommand::ConCommand(
    this: &endforward,
    pName: "-forward",
    callback: (void (__cdecl *)())IN_ForwardUp,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__endforward__);
}

//------------------------------------------------------------------------------
// Address: 0x10419020
// Name: _dynamic_initializer_for__startback__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__startback__()
{
  ConCommand::ConCommand(
    this: &startback,
    pName: "+back",
    callback: (void (__cdecl *)())IN_BackDown,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__startback__);
}

//------------------------------------------------------------------------------
// Address: 0x10419050
// Name: _dynamic_initializer_for__endback__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__endback__()
{
  ConCommand::ConCommand(
    this: &endback,
    pName: "-back",
    callback: (void (__cdecl *)())IN_BackUp,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__endback__);
}

//------------------------------------------------------------------------------
// Address: 0x10419080
// Name: _dynamic_initializer_for__startlookup__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__startlookup__()
{
  ConCommand::ConCommand(
    this: &startlookup,
    pName: "+lookup",
    callback: (void (__cdecl *)())IN_LookupDown,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__startlookup__);
}

//------------------------------------------------------------------------------
// Address: 0x104190B0
// Name: _dynamic_initializer_for__endlookup__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__endlookup__()
{
  ConCommand::ConCommand(
    this: &endlookup,
    pName: "-lookup",
    callback: (void (__cdecl *)())IN_LookupUp,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__endlookup__);
}

//------------------------------------------------------------------------------
// Address: 0x104190E0
// Name: _dynamic_initializer_for__startlookdown__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__startlookdown__()
{
  ConCommand::ConCommand(
    this: &startlookdown,
    pName: "+lookdown",
    callback: (void (__cdecl *)())IN_LookdownDown,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__startlookdown__);
}

//------------------------------------------------------------------------------
// Address: 0x10419110
// Name: _dynamic_initializer_for__lookdown__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__lookdown__()
{
  ConCommand::ConCommand(
    this: &lookdown,
    pName: "-lookdown",
    callback: (void (__cdecl *)())IN_LookdownUp,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__lookdown__);
}

//------------------------------------------------------------------------------
// Address: 0x10419140
// Name: _dynamic_initializer_for__startstrafe__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__startstrafe__()
{
  ConCommand::ConCommand(
    this: &startstrafe,
    pName: "+strafe",
    callback: (void (__cdecl *)())IN_StrafeDown,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__startstrafe__);
}

//------------------------------------------------------------------------------
// Address: 0x10419170
// Name: _dynamic_initializer_for__endstrafe__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__endstrafe__()
{
  ConCommand::ConCommand(
    this: &endstrafe,
    pName: "-strafe",
    callback: (void (__cdecl *)())IN_StrafeUp,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__endstrafe__);
}

//------------------------------------------------------------------------------
// Address: 0x104191A0
// Name: _dynamic_initializer_for__startmoveleft__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__startmoveleft__()
{
  ConCommand::ConCommand(
    this: &startmoveleft,
    pName: "+moveleft",
    callback: (void (__cdecl *)())IN_MoveleftDown,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__startmoveleft__);
}

//------------------------------------------------------------------------------
// Address: 0x104191D0
// Name: _dynamic_initializer_for__endmoveleft__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__endmoveleft__()
{
  ConCommand::ConCommand(
    this: &endmoveleft,
    pName: "-moveleft",
    callback: (void (__cdecl *)())IN_MoveleftUp,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__endmoveleft__);
}

//------------------------------------------------------------------------------
// Address: 0x10419200
// Name: _dynamic_initializer_for__startmoveright__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__startmoveright__()
{
  ConCommand::ConCommand(
    this: &startmoveright,
    pName: "+moveright",
    callback: (void (__cdecl *)())IN_MoverightDown,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__startmoveright__);
}

//------------------------------------------------------------------------------
// Address: 0x10419230
// Name: _dynamic_initializer_for__endmoveright__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__endmoveright__()
{
  ConCommand::ConCommand(
    this: &endmoveright,
    pName: "-moveright",
    callback: (void (__cdecl *)())IN_MoverightUp,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__endmoveright__);
}

//------------------------------------------------------------------------------
// Address: 0x10419260
// Name: _dynamic_initializer_for__startspeed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__startspeed__()
{
  ConCommand::ConCommand(
    this: &startspeed,
    pName: "+speed",
    callback: (void (__cdecl *)())IN_SpeedDown,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__startspeed__);
}

//------------------------------------------------------------------------------
// Address: 0x10419290
// Name: _dynamic_initializer_for__endspeed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__endspeed__()
{
  ConCommand::ConCommand(
    this: &endspeed,
    pName: "-speed",
    callback: (void (__cdecl *)())IN_SpeedUp,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__endspeed__);
}

//------------------------------------------------------------------------------
// Address: 0x104192C0
// Name: _dynamic_initializer_for__startwalk__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__startwalk__()
{
  ConCommand::ConCommand(
    this: &startwalk,
    pName: "+walk",
    callback: (void (__cdecl *)())IN_WalkDown,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__startwalk__);
}

//------------------------------------------------------------------------------
// Address: 0x104192F0
// Name: _dynamic_initializer_for__endwalk__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__endwalk__()
{
  ConCommand::ConCommand(
    this: &endwalk,
    pName: "-walk",
    callback: (void (__cdecl *)())IN_WalkUp,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__endwalk__);
}

//------------------------------------------------------------------------------
// Address: 0x10419320
// Name: _dynamic_initializer_for__startattack__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__startattack__()
{
  ConCommand::ConCommand(
    this: &startattack,
    pName: "+attack",
    callback: (void (__cdecl *)())IN_AttackDown,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__startattack__);
}

//------------------------------------------------------------------------------
// Address: 0x10419350
// Name: _dynamic_initializer_for__endattack__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__endattack__()
{
  ConCommand::ConCommand(
    this: &endattack,
    pName: "-attack",
    callback: (void (__cdecl *)())IN_AttackUp,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__endattack__);
}

//------------------------------------------------------------------------------
// Address: 0x10419380
// Name: _dynamic_initializer_for__startattack2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__startattack2__()
{
  ConCommand::ConCommand(
    this: &startattack2,
    pName: "+attack2",
    callback: (void (__cdecl *)())IN_Attack2Down,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__startattack2__);
}

//------------------------------------------------------------------------------
// Address: 0x104193B0
// Name: _dynamic_initializer_for__endattack2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__endattack2__()
{
  ConCommand::ConCommand(
    this: &endattack2,
    pName: "-attack2",
    callback: (void (__cdecl *)())IN_Attack2Up,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__endattack2__);
}

//------------------------------------------------------------------------------
// Address: 0x104193E0
// Name: _dynamic_initializer_for__startuse__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__startuse__()
{
  ConCommand::ConCommand(
    this: &startuse,
    pName: "+use",
    callback: (void (__cdecl *)())IN_UseDown,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__startuse__);
}

//------------------------------------------------------------------------------
// Address: 0x10419410
// Name: _dynamic_initializer_for__enduse__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__enduse__()
{
  ConCommand::ConCommand(
    this: &enduse,
    pName: "-use",
    callback: (void (__cdecl *)())IN_UseUp,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__enduse__);
}

//------------------------------------------------------------------------------
// Address: 0x10419440
// Name: _dynamic_initializer_for__startjump__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__startjump__()
{
  ConCommand::ConCommand(
    this: &startjump,
    pName: "+jump",
    callback: (void (__cdecl *)())IN_JumpDown,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__startjump__);
}

//------------------------------------------------------------------------------
// Address: 0x10419470
// Name: _dynamic_initializer_for__endjump__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__endjump__()
{
  ConCommand::ConCommand(
    this: &endjump,
    pName: "-jump",
    callback: (void (__cdecl *)())IN_JumpUp,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__endjump__);
}

//------------------------------------------------------------------------------
// Address: 0x104194A0
// Name: _dynamic_initializer_for__impulse__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__impulse__()
{
  ConCommand::ConCommand(
    this: &impulse,
    pName: "impulse",
    callback: (void (__cdecl *)())IN_Impulse,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__impulse__);
}

//------------------------------------------------------------------------------
// Address: 0x104194D0
// Name: _dynamic_initializer_for__startklook__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__startklook__()
{
  ConCommand::ConCommand(
    this: &startklook,
    pName: "+klook",
    callback: (void (__cdecl *)())IN_KLookDown,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__startklook__);
}

//------------------------------------------------------------------------------
// Address: 0x10419500
// Name: _dynamic_initializer_for__endklook__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__endklook__()
{
  ConCommand::ConCommand(
    this: &endklook,
    pName: "-klook",
    callback: (void (__cdecl *)())IN_KLookUp,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__endklook__);
}

//------------------------------------------------------------------------------
// Address: 0x10419530
// Name: _dynamic_initializer_for__startjlook__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__startjlook__()
{
  ConCommand::ConCommand(
    this: &startjlook,
    pName: "+jlook",
    callback: (void (__cdecl *)())IN_JLookDown,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__startjlook__);
}

//------------------------------------------------------------------------------
// Address: 0x10419560
// Name: _dynamic_initializer_for__endjlook__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__endjlook__()
{
  ConCommand::ConCommand(
    this: &endjlook,
    pName: "-jlook",
    callback: (void (__cdecl *)())IN_JLookUp,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__endjlook__);
}

//------------------------------------------------------------------------------
// Address: 0x10419590
// Name: _dynamic_initializer_for__startduck__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__startduck__()
{
  ConCommand::ConCommand(
    this: &startduck,
    pName: "+duck",
    callback: (void (__cdecl *)())IN_DuckDown,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__startduck__);
}

//------------------------------------------------------------------------------
// Address: 0x104195C0
// Name: _dynamic_initializer_for__endduck__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__endduck__()
{
  ConCommand::ConCommand(
    this: &endduck,
    pName: "-duck",
    callback: (void (__cdecl *)())IN_DuckUp,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__endduck__);
}

//------------------------------------------------------------------------------
// Address: 0x104195F0
// Name: _dynamic_initializer_for__startreload__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__startreload__()
{
  ConCommand::ConCommand(
    this: &startreload,
    pName: "+reload",
    callback: (void (__cdecl *)())IN_ReloadDown,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__startreload__);
}

//------------------------------------------------------------------------------
// Address: 0x10419620
// Name: _dynamic_initializer_for__endreload__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__endreload__()
{
  ConCommand::ConCommand(
    this: &endreload,
    pName: "-reload",
    callback: (void (__cdecl *)())IN_ReloadUp,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__endreload__);
}

//------------------------------------------------------------------------------
// Address: 0x10419650
// Name: _dynamic_initializer_for__startalt1__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__startalt1__()
{
  ConCommand::ConCommand(
    this: &startalt1,
    pName: "+alt1",
    callback: (void (__cdecl *)())IN_Alt1Down,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__startalt1__);
}

//------------------------------------------------------------------------------
// Address: 0x10419680
// Name: _dynamic_initializer_for__endalt1__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__endalt1__()
{
  ConCommand::ConCommand(
    this: &endalt1,
    pName: "-alt1",
    callback: (void (__cdecl *)())IN_Alt1Up,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__endalt1__);
}

//------------------------------------------------------------------------------
// Address: 0x104196B0
// Name: _dynamic_initializer_for__startalt2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__startalt2__()
{
  ConCommand::ConCommand(
    this: &startalt2,
    pName: "+alt2",
    callback: (void (__cdecl *)())IN_Alt2Down,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__startalt2__);
}

//------------------------------------------------------------------------------
// Address: 0x104196E0
// Name: _dynamic_initializer_for__endalt2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__endalt2__()
{
  ConCommand::ConCommand(
    this: &endalt2,
    pName: "-alt2",
    callback: (void (__cdecl *)())IN_Alt2Up,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__endalt2__);
}

//------------------------------------------------------------------------------
// Address: 0x10419710
// Name: _dynamic_initializer_for__startscore__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__startscore__()
{
  ConCommand::ConCommand(
    this: &startscore,
    pName: "+score",
    callback: (void (__cdecl *)())IN_ScoreDown,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__startscore__);
}

//------------------------------------------------------------------------------
// Address: 0x10419740
// Name: _dynamic_initializer_for__endscore__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__endscore__()
{
  ConCommand::ConCommand(
    this: &endscore,
    pName: "-score",
    callback: (void (__cdecl *)())IN_ScoreUp,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__endscore__);
}

//------------------------------------------------------------------------------
// Address: 0x10419770
// Name: _dynamic_initializer_for__startshowscores__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__startshowscores__()
{
  ConCommand::ConCommand(
    this: &startshowscores,
    pName: "+showscores",
    callback: (void (__cdecl *)())IN_ScoreDown,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__startshowscores__);
}

//------------------------------------------------------------------------------
// Address: 0x104197A0
// Name: _dynamic_initializer_for__endshowscores__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__endshowscores__()
{
  ConCommand::ConCommand(
    this: &endshowscores,
    pName: "-showscores",
    callback: (void (__cdecl *)())IN_ScoreUp,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__endshowscores__);
}

//------------------------------------------------------------------------------
// Address: 0x104197D0
// Name: _dynamic_initializer_for__startgraph__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__startgraph__()
{
  ConCommand::ConCommand(
    this: &startgraph,
    pName: "+graph",
    callback: (void (__cdecl *)())IN_GraphDown,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__startgraph__);
}

//------------------------------------------------------------------------------
// Address: 0x10419800
// Name: _dynamic_initializer_for__endgraph__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__endgraph__()
{
  ConCommand::ConCommand(
    this: &endgraph,
    pName: "-graph",
    callback: (void (__cdecl *)())IN_GraphUp,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__endgraph__);
}

//------------------------------------------------------------------------------
// Address: 0x10419830
// Name: _dynamic_initializer_for__startbreak__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__startbreak__()
{
  ConCommand::ConCommand(
    this: &startbreak,
    pName: "+break",
    callback: (void (__cdecl *)())IN_BreakDown,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__startbreak__);
}

//------------------------------------------------------------------------------
// Address: 0x10419860
// Name: _dynamic_initializer_for__endbreak__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__endbreak__()
{
  ConCommand::ConCommand(
    this: &endbreak,
    pName: "-break",
    callback: (void (__cdecl *)())IN_BreakUp,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__endbreak__);
}

//------------------------------------------------------------------------------
// Address: 0x1041CBA0
// Name: _dynamic_initializer_for____g_C_TeamplayRoundBasedRulesProxyClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_TeamplayRoundBasedRulesProxyClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_TeamplayRoundBasedRulesProxyClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_TeamplayRoundBasedRulesProxyClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041CBF0
// Name: _dynamic_initializer_for__mp_capstyle__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_capstyle__()
{
  ConVar::ConVar(
    this: &mp_capstyle,
    pName: "mp_capstyle",
    pDefaultValue: "1",
    flags: 8194,
    pHelpString: "Sets the style of capture points used. 0 = Fixed players required to cap. 1 = More players cap faster, but longer cap times.");
  return atexit(func: dynamic_atexit_destructor_for__mp_capstyle__);
}

//------------------------------------------------------------------------------
// Address: 0x1041CC20
// Name: _dynamic_initializer_for__mp_blockstyle__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_blockstyle__()
{
  ConVar::ConVar(
    this: &mp_blockstyle,
    pName: "mp_blockstyle",
    pDefaultValue: "1",
    flags: 8194,
    pHelpString: "Sets the style of capture point blocking used. 0 = Blocks break captures completely. 1 = Blocks only pause captures.");
  return atexit(func: dynamic_atexit_destructor_for__mp_blockstyle__);
}

//------------------------------------------------------------------------------
// Address: 0x1041CC50
// Name: _dynamic_initializer_for__mp_respawnwavetime__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_respawnwavetime__()
{
  ConVar::ConVar(
    this: &mp_respawnwavetime,
    pName: "mp_respawnwavetime",
    pDefaultValue: "10.0",
    flags: 8448,
    pHelpString: "Time between respawn waves.");
  return atexit(func: dynamic_atexit_destructor_for__mp_respawnwavetime__);
}

//------------------------------------------------------------------------------
// Address: 0x1041CC80
// Name: _dynamic_initializer_for__mp_capdeteriorate_time__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_capdeteriorate_time__()
{
  ConVar::ConVar(
    this: &mp_capdeteriorate_time,
    pName: "mp_capdeteriorate_time",
    pDefaultValue: "90.0",
    flags: 8194,
    pHelpString: "Time it takes for a full capture point to deteriorate.");
  return atexit(func: dynamic_atexit_destructor_for__mp_capdeteriorate_time__);
}

//------------------------------------------------------------------------------
// Address: 0x1041CCB0
// Name: _dynamic_initializer_for__mp_tournament__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_tournament__()
{
  ConVar::ConVar(this: &mp_tournament, pName: "mp_tournament", pDefaultValue: "0", flags: 8448);
  return atexit(func: dynamic_atexit_destructor_for__mp_tournament__);
}

//------------------------------------------------------------------------------
// Address: 0x1041CCE0
// Name: _dynamic_initializer_for__tf_arena_preround_time__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__tf_arena_preround_time__()
{
  ConVar::ConVar(
    this: &tf_arena_preround_time,
    pName: "tf_arena_preround_time",
    pDefaultValue: "10",
    flags: 8448,
    pHelpString: "Length of the Pre-Round time",
    bMin: true,
    fMin: 5.0,
    bMax: true,
    fMax: 15.0);
  return atexit(func: dynamic_atexit_destructor_for__tf_arena_preround_time__);
}

//------------------------------------------------------------------------------
// Address: 0x1041CD30
// Name: _dynamic_initializer_for__tf_arena_round_time__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__tf_arena_round_time__()
{
  ConVar::ConVar(this: &tf_arena_round_time, pName: "tf_arena_round_time", pDefaultValue: "0", flags: 24834);
  return atexit(func: dynamic_atexit_destructor_for__tf_arena_round_time__);
}

//------------------------------------------------------------------------------
// Address: 0x1041CD60
// Name: _dynamic_initializer_for__tf_arena_max_streak__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__tf_arena_max_streak__()
{
  ConVar::ConVar(
    this: &tf_arena_max_streak,
    pName: "tf_arena_max_streak",
    pDefaultValue: "5",
    flags: 8448,
    pHelpString: "Teams will be scrambled if one team reaches this streak");
  return atexit(func: dynamic_atexit_destructor_for__tf_arena_max_streak__);
}

//------------------------------------------------------------------------------
// Address: 0x1041CD90
// Name: _dynamic_initializer_for__mp_teams_unbalance_limit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_teams_unbalance_limit__()
{
  ConVar::ConVar(
    this: &mp_teams_unbalance_limit,
    pName: "mp_teams_unbalance_limit",
    pDefaultValue: "1",
    flags: 8448,
    pHelpString: "Teams are unbalanced when one team has this many more players than the other team. (0 disables check)",
    bMin: true,
    fMin: 0.0,
    bMax: true,
    fMax: 30.0);
  return atexit(func: dynamic_atexit_destructor_for__mp_teams_unbalance_limit__);
}

//------------------------------------------------------------------------------
// Address: 0x1041CDE0
// Name: _dynamic_initializer_for__mp_maxrounds__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_maxrounds__()
{
  ConVar::ConVar(
    this: &mp_maxrounds,
    pName: "mp_maxrounds",
    pDefaultValue: "0",
    flags: 8448,
    pHelpString: "max number of rounds to play before server changes maps",
    bMin: true,
    fMin: 0.0,
    bMax: false,
    fMax: 0.0);
  return atexit(func: dynamic_atexit_destructor_for__mp_maxrounds__);
}

//------------------------------------------------------------------------------
// Address: 0x1041CE20
// Name: _dynamic_initializer_for__mp_winlimit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_winlimit__()
{
  ConVar::ConVar(
    this: &mp_winlimit,
    pName: "mp_winlimit",
    pDefaultValue: "0",
    flags: 8448,
    pHelpString: "Max score one team can reach before server changes maps",
    bMin: true,
    fMin: 0.0,
    bMax: false,
    fMax: 0.0);
  return atexit(func: dynamic_atexit_destructor_for__mp_winlimit__);
}

//------------------------------------------------------------------------------
// Address: 0x1041CE60
// Name: _dynamic_initializer_for__mp_disable_respawn_times__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_disable_respawn_times__()
{
  ConVar::ConVar(this: &mp_disable_respawn_times, pName: "mp_disable_respawn_times", pDefaultValue: "0", flags: 8448);
  return atexit(func: dynamic_atexit_destructor_for__mp_disable_respawn_times__);
}

//------------------------------------------------------------------------------
// Address: 0x1041CE90
// Name: _dynamic_initializer_for__mp_bonusroundtime__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_bonusroundtime__()
{
  ConVar::ConVar(
    this: &mp_bonusroundtime,
    pName: "mp_bonusroundtime",
    pDefaultValue: "15",
    flags: 0x2000,
    pHelpString: "Time after round win until round restarts",
    bMin: true,
    fMin: 5.0,
    bMax: true,
    fMax: 15.0);
  return atexit(func: dynamic_atexit_destructor_for__mp_bonusroundtime__);
}

//------------------------------------------------------------------------------
// Address: 0x1041CEE0
// Name: _dynamic_initializer_for____g_C_HandleTestClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_HandleTestClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_HandleTestClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_HandleTestClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10432600
// Name: _dynamic_atexit_destructor_for__in_forceuser__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__in_forceuser__()
{
  ConVar::~ConVar(this: &in_forceuser);
}

//------------------------------------------------------------------------------
// Address: 0x10432610
// Name: _dynamic_atexit_destructor_for__ss_mimic__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ss_mimic__()
{
  ConVar::~ConVar(this: &ss_mimic);
}

//------------------------------------------------------------------------------
// Address: 0x10432620
// Name: _dynamic_atexit_destructor_for__ss_teleport_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ss_teleport_command__()
{
  ConCommand::~ConCommand(this: &ss_teleport_command);
}

//------------------------------------------------------------------------------
// Address: 0x10432630
// Name: _dynamic_atexit_destructor_for__in_usekeyboardsampletime__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__in_usekeyboardsampletime__()
{
  ConVar::~ConVar(this: &in_usekeyboardsampletime);
}

//------------------------------------------------------------------------------
// Address: 0x10432640
// Name: _dynamic_atexit_destructor_for__startcommandermousemove__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__startcommandermousemove__()
{
  ConCommand::~ConCommand(this: &startcommandermousemove);
}

//------------------------------------------------------------------------------
// Address: 0x10432650
// Name: _dynamic_atexit_destructor_for__endcommandermousemove__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__endcommandermousemove__()
{
  ConCommand::~ConCommand(this: &endcommandermousemove);
}

//------------------------------------------------------------------------------
// Address: 0x10432660
// Name: _dynamic_atexit_destructor_for__startmoveup__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__startmoveup__()
{
  ConCommand::~ConCommand(this: &startmoveup);
}

//------------------------------------------------------------------------------
// Address: 0x10432670
// Name: _dynamic_atexit_destructor_for__endmoveup__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__endmoveup__()
{
  ConCommand::~ConCommand(this: &endmoveup);
}

//------------------------------------------------------------------------------
// Address: 0x10432680
// Name: _dynamic_atexit_destructor_for__startmovedown__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__startmovedown__()
{
  ConCommand::~ConCommand(this: &startmovedown);
}

//------------------------------------------------------------------------------
// Address: 0x10432690
// Name: _dynamic_atexit_destructor_for__endmovedown__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__endmovedown__()
{
  ConCommand::~ConCommand(this: &endmovedown);
}

//------------------------------------------------------------------------------
// Address: 0x104326A0
// Name: _dynamic_atexit_destructor_for__startleft__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__startleft__()
{
  ConCommand::~ConCommand(this: &startleft);
}

//------------------------------------------------------------------------------
// Address: 0x104326B0
// Name: _dynamic_atexit_destructor_for__endleft__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__endleft__()
{
  ConCommand::~ConCommand(this: &endleft);
}

//------------------------------------------------------------------------------
// Address: 0x104326C0
// Name: _dynamic_atexit_destructor_for__startright__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__startright__()
{
  ConCommand::~ConCommand(this: &startright);
}

//------------------------------------------------------------------------------
// Address: 0x104326D0
// Name: _dynamic_atexit_destructor_for__endright__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__endright__()
{
  ConCommand::~ConCommand(this: &endright);
}

//------------------------------------------------------------------------------
// Address: 0x104326E0
// Name: _dynamic_atexit_destructor_for__startforward__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__startforward__()
{
  ConCommand::~ConCommand(this: &startforward);
}

//------------------------------------------------------------------------------
// Address: 0x104326F0
// Name: _dynamic_atexit_destructor_for__endforward__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__endforward__()
{
  ConCommand::~ConCommand(this: &endforward);
}

//------------------------------------------------------------------------------
// Address: 0x10432700
// Name: _dynamic_atexit_destructor_for__startback__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__startback__()
{
  ConCommand::~ConCommand(this: &startback);
}

//------------------------------------------------------------------------------
// Address: 0x10432710
// Name: _dynamic_atexit_destructor_for__endback__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__endback__()
{
  ConCommand::~ConCommand(this: &endback);
}

//------------------------------------------------------------------------------
// Address: 0x10432720
// Name: _dynamic_atexit_destructor_for__startlookup__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__startlookup__()
{
  ConCommand::~ConCommand(this: &startlookup);
}

//------------------------------------------------------------------------------
// Address: 0x10432730
// Name: _dynamic_atexit_destructor_for__endlookup__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__endlookup__()
{
  ConCommand::~ConCommand(this: &endlookup);
}

//------------------------------------------------------------------------------
// Address: 0x10432740
// Name: _dynamic_atexit_destructor_for__startlookdown__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__startlookdown__()
{
  ConCommand::~ConCommand(this: &startlookdown);
}

//------------------------------------------------------------------------------
// Address: 0x10432750
// Name: _dynamic_atexit_destructor_for__lookdown__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__lookdown__()
{
  ConCommand::~ConCommand(this: &lookdown);
}

//------------------------------------------------------------------------------
// Address: 0x10432760
// Name: _dynamic_atexit_destructor_for__startstrafe__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__startstrafe__()
{
  ConCommand::~ConCommand(this: &startstrafe);
}

//------------------------------------------------------------------------------
// Address: 0x10432770
// Name: _dynamic_atexit_destructor_for__endstrafe__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__endstrafe__()
{
  ConCommand::~ConCommand(this: &endstrafe);
}

//------------------------------------------------------------------------------
// Address: 0x10432780
// Name: _dynamic_atexit_destructor_for__startmoveleft__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__startmoveleft__()
{
  ConCommand::~ConCommand(this: &startmoveleft);
}

//------------------------------------------------------------------------------
// Address: 0x10432790
// Name: _dynamic_atexit_destructor_for__endmoveleft__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__endmoveleft__()
{
  ConCommand::~ConCommand(this: &endmoveleft);
}

//------------------------------------------------------------------------------
// Address: 0x104327A0
// Name: _dynamic_atexit_destructor_for__startmoveright__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__startmoveright__()
{
  ConCommand::~ConCommand(this: &startmoveright);
}

//------------------------------------------------------------------------------
// Address: 0x104327B0
// Name: _dynamic_atexit_destructor_for__endmoveright__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__endmoveright__()
{
  ConCommand::~ConCommand(this: &endmoveright);
}

//------------------------------------------------------------------------------
// Address: 0x104327C0
// Name: _dynamic_atexit_destructor_for__startspeed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__startspeed__()
{
  ConCommand::~ConCommand(this: &startspeed);
}

//------------------------------------------------------------------------------
// Address: 0x104327D0
// Name: _dynamic_atexit_destructor_for__endspeed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__endspeed__()
{
  ConCommand::~ConCommand(this: &endspeed);
}

//------------------------------------------------------------------------------
// Address: 0x104327E0
// Name: _dynamic_atexit_destructor_for__startwalk__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__startwalk__()
{
  ConCommand::~ConCommand(this: &startwalk);
}

//------------------------------------------------------------------------------
// Address: 0x104327F0
// Name: _dynamic_atexit_destructor_for__endwalk__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__endwalk__()
{
  ConCommand::~ConCommand(this: &endwalk);
}

//------------------------------------------------------------------------------
// Address: 0x10432800
// Name: _dynamic_atexit_destructor_for__startattack__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__startattack__()
{
  ConCommand::~ConCommand(this: &startattack);
}

//------------------------------------------------------------------------------
// Address: 0x10432810
// Name: _dynamic_atexit_destructor_for__endattack__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__endattack__()
{
  ConCommand::~ConCommand(this: &endattack);
}

//------------------------------------------------------------------------------
// Address: 0x10432820
// Name: _dynamic_atexit_destructor_for__startattack2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__startattack2__()
{
  ConCommand::~ConCommand(this: &startattack2);
}

//------------------------------------------------------------------------------
// Address: 0x10432830
// Name: _dynamic_atexit_destructor_for__endattack2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__endattack2__()
{
  ConCommand::~ConCommand(this: &endattack2);
}

//------------------------------------------------------------------------------
// Address: 0x10432840
// Name: _dynamic_atexit_destructor_for__startuse__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__startuse__()
{
  ConCommand::~ConCommand(this: &startuse);
}

//------------------------------------------------------------------------------
// Address: 0x10432850
// Name: _dynamic_atexit_destructor_for__enduse__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__enduse__()
{
  ConCommand::~ConCommand(this: &enduse);
}

//------------------------------------------------------------------------------
// Address: 0x10432860
// Name: _dynamic_atexit_destructor_for__startjump__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__startjump__()
{
  ConCommand::~ConCommand(this: &startjump);
}

//------------------------------------------------------------------------------
// Address: 0x10432870
// Name: _dynamic_atexit_destructor_for__endjump__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__endjump__()
{
  ConCommand::~ConCommand(this: &endjump);
}

//------------------------------------------------------------------------------
// Address: 0x10432880
// Name: _dynamic_atexit_destructor_for__impulse__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__impulse__()
{
  ConCommand::~ConCommand(this: &impulse);
}

//------------------------------------------------------------------------------
// Address: 0x10432890
// Name: _dynamic_atexit_destructor_for__startklook__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__startklook__()
{
  ConCommand::~ConCommand(this: &startklook);
}

//------------------------------------------------------------------------------
// Address: 0x104328A0
// Name: _dynamic_atexit_destructor_for__endklook__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__endklook__()
{
  ConCommand::~ConCommand(this: &endklook);
}

//------------------------------------------------------------------------------
// Address: 0x104328B0
// Name: _dynamic_atexit_destructor_for__startjlook__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__startjlook__()
{
  ConCommand::~ConCommand(this: &startjlook);
}

//------------------------------------------------------------------------------
// Address: 0x104328C0
// Name: _dynamic_atexit_destructor_for__endjlook__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__endjlook__()
{
  ConCommand::~ConCommand(this: &endjlook);
}

//------------------------------------------------------------------------------
// Address: 0x104328D0
// Name: _dynamic_atexit_destructor_for__startduck__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__startduck__()
{
  ConCommand::~ConCommand(this: &startduck);
}

//------------------------------------------------------------------------------
// Address: 0x104328E0
// Name: _dynamic_atexit_destructor_for__endduck__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__endduck__()
{
  ConCommand::~ConCommand(this: &endduck);
}

//------------------------------------------------------------------------------
// Address: 0x104328F0
// Name: _dynamic_atexit_destructor_for__startreload__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__startreload__()
{
  ConCommand::~ConCommand(this: &startreload);
}

//------------------------------------------------------------------------------
// Address: 0x10432900
// Name: _dynamic_atexit_destructor_for__endreload__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__endreload__()
{
  ConCommand::~ConCommand(this: &endreload);
}

//------------------------------------------------------------------------------
// Address: 0x10432910
// Name: _dynamic_atexit_destructor_for__startalt1__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__startalt1__()
{
  ConCommand::~ConCommand(this: &startalt1);
}

//------------------------------------------------------------------------------
// Address: 0x10432920
// Name: _dynamic_atexit_destructor_for__endalt1__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__endalt1__()
{
  ConCommand::~ConCommand(this: &endalt1);
}

//------------------------------------------------------------------------------
// Address: 0x10432930
// Name: _dynamic_atexit_destructor_for__startalt2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__startalt2__()
{
  ConCommand::~ConCommand(this: &startalt2);
}

//------------------------------------------------------------------------------
// Address: 0x10432940
// Name: _dynamic_atexit_destructor_for__endalt2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__endalt2__()
{
  ConCommand::~ConCommand(this: &endalt2);
}

//------------------------------------------------------------------------------
// Address: 0x10432950
// Name: _dynamic_atexit_destructor_for__startscore__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__startscore__()
{
  ConCommand::~ConCommand(this: &startscore);
}

//------------------------------------------------------------------------------
// Address: 0x10432960
// Name: _dynamic_atexit_destructor_for__endscore__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__endscore__()
{
  ConCommand::~ConCommand(this: &endscore);
}

//------------------------------------------------------------------------------
// Address: 0x10432970
// Name: _dynamic_atexit_destructor_for__startshowscores__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__startshowscores__()
{
  ConCommand::~ConCommand(this: &startshowscores);
}

//------------------------------------------------------------------------------
// Address: 0x10432980
// Name: _dynamic_atexit_destructor_for__endshowscores__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__endshowscores__()
{
  ConCommand::~ConCommand(this: &endshowscores);
}

//------------------------------------------------------------------------------
// Address: 0x10432990
// Name: _dynamic_atexit_destructor_for__startgraph__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__startgraph__()
{
  ConCommand::~ConCommand(this: &startgraph);
}

//------------------------------------------------------------------------------
// Address: 0x104329A0
// Name: _dynamic_atexit_destructor_for__endgraph__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__endgraph__()
{
  ConCommand::~ConCommand(this: &endgraph);
}

//------------------------------------------------------------------------------
// Address: 0x104329B0
// Name: _dynamic_atexit_destructor_for__startbreak__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__startbreak__()
{
  ConCommand::~ConCommand(this: &startbreak);
}

//------------------------------------------------------------------------------
// Address: 0x104329C0
// Name: _dynamic_atexit_destructor_for__endbreak__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__endbreak__()
{
  ConCommand::~ConCommand(this: &endbreak);
}

//------------------------------------------------------------------------------
// Address: 0x10433CB0
// Name: _dynamic_atexit_destructor_for__mp_capstyle__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_capstyle__()
{
  ConVar::~ConVar(this: &mp_capstyle);
}

//------------------------------------------------------------------------------
// Address: 0x10433CC0
// Name: _dynamic_atexit_destructor_for__mp_blockstyle__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_blockstyle__()
{
  ConVar::~ConVar(this: &mp_blockstyle);
}

//------------------------------------------------------------------------------
// Address: 0x10433CD0
// Name: _dynamic_atexit_destructor_for__mp_respawnwavetime__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_respawnwavetime__()
{
  ConVar::~ConVar(this: &mp_respawnwavetime);
}

//------------------------------------------------------------------------------
// Address: 0x10433CE0
// Name: _dynamic_atexit_destructor_for__mp_capdeteriorate_time__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_capdeteriorate_time__()
{
  ConVar::~ConVar(this: &mp_capdeteriorate_time);
}

//------------------------------------------------------------------------------
// Address: 0x10433CF0
// Name: _dynamic_atexit_destructor_for__mp_tournament__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_tournament__()
{
  ConVar::~ConVar(this: &mp_tournament);
}

//------------------------------------------------------------------------------
// Address: 0x10433D00
// Name: _dynamic_atexit_destructor_for__tf_arena_preround_time__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__tf_arena_preround_time__()
{
  ConVar::~ConVar(this: &tf_arena_preround_time);
}

//------------------------------------------------------------------------------
// Address: 0x10433D10
// Name: _dynamic_atexit_destructor_for__tf_arena_round_time__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__tf_arena_round_time__()
{
  ConVar::~ConVar(this: &tf_arena_round_time);
}

//------------------------------------------------------------------------------
// Address: 0x10433D20
// Name: _dynamic_atexit_destructor_for__tf_arena_max_streak__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__tf_arena_max_streak__()
{
  ConVar::~ConVar(this: &tf_arena_max_streak);
}

//------------------------------------------------------------------------------
// Address: 0x10433D30
// Name: _dynamic_atexit_destructor_for__mp_teams_unbalance_limit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_teams_unbalance_limit__()
{
  ConVar::~ConVar(this: &mp_teams_unbalance_limit);
}

//------------------------------------------------------------------------------
// Address: 0x10433D40
// Name: _dynamic_atexit_destructor_for__mp_maxrounds__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_maxrounds__()
{
  ConVar::~ConVar(this: &mp_maxrounds);
}

//------------------------------------------------------------------------------
// Address: 0x10433D50
// Name: _dynamic_atexit_destructor_for__mp_winlimit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_winlimit__()
{
  ConVar::~ConVar(this: &mp_winlimit);
}

//------------------------------------------------------------------------------
// Address: 0x10433D60
// Name: _dynamic_atexit_destructor_for__mp_disable_respawn_times__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_disable_respawn_times__()
{
  ConVar::~ConVar(this: &mp_disable_respawn_times);
}

//------------------------------------------------------------------------------
// Address: 0x10433D70
// Name: _dynamic_atexit_destructor_for__mp_bonusroundtime__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_bonusroundtime__()
{
  ConVar::~ConVar(this: &mp_bonusroundtime);
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10231360
// Name: bool FindInList(char const __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FindInList(const char **pStrings, const char *pToFind)
{
  int v2; // esi
  const char **v3; // eax

  v2 = 0;
  if ( **pStrings == 0 )
    return 0;
  v3 = pStrings;
  while ( _V_stricmp(s1: *v3, s2: pToFind) != 0 )
  {
    v3 = &pStrings[++v2];
    if ( **v3 == 0 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102313B0
// Name: public: void CTeamplayRoundBasedRulesProxy::InputSetStalemateOnTimelimit(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTeamplayRoundBasedRulesProxy::InputSetStalemateOnTimelimit(
        CTeamplayRoundBasedRulesProxy *this,
        inputdata_t *inputdata)
{
  LOBYTE(g_pGameRules[63].__vftable) = inputdata->value.fieldType == FIELD_BOOLEAN && inputdata->value.bVal;
}

//------------------------------------------------------------------------------
// Address: 0x102313F0
// Name: void cc_SwitchTeams(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall cc_SwitchTeams(CGameTrace *a1@<esi>)
{
  char *v1; // eax
  char *v2; // esi

  if ( UTIL_IsCommandIssuedByServerAdmin() )
  {
    v1 = (char *)__RTDynamicCast(
                   inptr: g_pGameRules,
                   VfDelta: 0,
                   SrcType: &CGameRules `RTTI Type Descriptor',
                   TargetType: &CTeamplayRoundBasedRules `RTTI Type Descriptor',
                   isReference: 0);
    v2 = v1;
    if ( v1 != nullptr )
    {
      (*(void (__thiscall **)(char *))(*(_DWORD *)v1 + 632))(a1: v1);
      CCollisionProperty::TestCollision(this: (ConVar *)&mp_restartgame.IConVar, value: 5, fContentsMask: 1u, tr: a1);
      *(_WORD *)(v2 + 577) = 0;
      v2[579] = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10231450
// Name: void cc_ScrambleTeams(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall cc_ScrambleTeams(CGameTrace *a1@<esi>)
{
  char *v1; // eax
  char *v2; // esi

  if ( UTIL_IsCommandIssuedByServerAdmin() )
  {
    v1 = (char *)__RTDynamicCast(
                   inptr: g_pGameRules,
                   VfDelta: 0,
                   SrcType: &CGameRules `RTTI Type Descriptor',
                   TargetType: &CTeamplayRoundBasedRules `RTTI Type Descriptor',
                   isReference: 0);
    v2 = v1;
    if ( v1 != nullptr )
    {
      (*(void (__thiscall **)(char *))(*(_DWORD *)v1 + 644))(a1: v1);
      CCollisionProperty::TestCollision(this: (ConVar *)&mp_restartgame.IConVar, value: 5, fContentsMask: 1u, tr: a1);
      *(_WORD *)(v2 + 577) = 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102314B0
// Name: mp_forcewin
// Source: json
//------------------------------------------------------------------------------
void __cdecl mp_forcewin(const CCommand *args)
{
  void *v1; // esi
  CBasePlayer *v2; // eax
  int TeamNumber; // eax

  if ( UTIL_IsCommandIssuedByServerAdmin() )
  {
    v1 = __RTDynamicCast(
           inptr: g_pGameRules,
           VfDelta: 0,
           SrcType: &CGameRules `RTTI Type Descriptor',
           TargetType: &CTeamplayRoundBasedRules `RTTI Type Descriptor',
           isReference: 0);
    if ( v1 != nullptr )
    {
      if ( args->m_nArgc == 1 )
      {
        v2 = UTIL_PlayerByIndex(playerIndex: 1);
        TeamNumber = CBaseEntity::GetTeamNumber(this: v2);
LABEL_7:
        (*(void (__thiscall **)(void *, int, int, int, _DWORD, _DWORD))(*(_DWORD *)v1 + 624))(
          a1: v1,
          a2: TeamNumber,
          a3: 4 * (TeamNumber == 0) + 1,
          a4: 1,
          a5: 0,
          a6: 0);
        return;
      }
      if ( args->m_nArgc == 2 )
      {
        TeamNumber = atoi(nptr: args->m_ppArgv[1]);
        goto LABEL_7;
      }
      _Msg(a1: "Usage: mp_forcewin <opt: team#>");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10231550
// Name: void CC_CH_TournamentRestart(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_CH_TournamentRestart()
{
  void *v0; // eax

  v0 = __RTDynamicCast(
         inptr: g_pGameRules,
         VfDelta: 0,
         SrcType: &CGameRules `RTTI Type Descriptor',
         TargetType: &CTeamplayRoundBasedRules `RTTI Type Descriptor',
         isReference: 0);
  if ( v0 != nullptr )
    (*(void (__thiscall **)(void *))(*(_DWORD *)v0 + 732))(a1: v0);
}

//------------------------------------------------------------------------------
// Address: 0x10231580
// Name: public: void CTeamplayRoundBasedRules::RespawnPlayers(bool,bool,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTeamplayRoundBasedRules::RespawnPlayers(
        CTeamplayRoundBasedRules *this,
        bool bForceRespawn,
        bool bTeam,
        int iTeam)
{
  int v4; // edi
  CBasePlayer *v6; // eax
  CBasePlayer *v7; // esi

  v4 = 1;
  if ( gpGlobals->maxClients >= 1 )
  {
    while ( 1 )
    {
      v6 = UTIL_PlayerByIndex(playerIndex: v4);
      v7 = v6;
      if ( v6 != nullptr && v6->IsPlayer(this: v6) && (!bTeam || CBaseEntity::GetTeamNumber(this: v7) == iTeam) )
      {
        if ( !v7->IsReadyToPlay(this: v7) )
        {
          if ( v7->ShouldGainInstantSpawn(this: v7) )
            v7->m_bAllowInstantSpawn = true;
          goto LABEL_18;
        }
        if ( bForceRespawn )
          goto LABEL_17;
        if ( !v7->IsAlive(this: v7) )
          break;
      }
LABEL_18:
      if ( ++v4 > gpGlobals->maxClients )
        return;
    }
    if ( this->m_iRoundState.m_Value != GR_STATE_PREROUND )
    {
      if ( bTeam && !this->HasPassedMinRespawnTime(this, a2: v7) )
        goto LABEL_18;
      if ( !v7->IsReadyToSpawn(this: v7) )
      {
        if ( v7->ShouldGainInstantSpawn(this: v7) )
          v7->m_bAllowInstantSpawn = true;
        goto LABEL_18;
      }
    }
LABEL_17:
    v7->ForceRespawn(this: v7);
    goto LABEL_18;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102318E0
// Name: void CC_CH_ForceRespawn(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_CH_ForceRespawn()
{
  CTeamplayRoundBasedRules *v0; // eax

  v0 = (CTeamplayRoundBasedRules *)__RTDynamicCast(
                                     inptr: g_pGameRules,
                                     VfDelta: 0,
                                     SrcType: &CGameRules `RTTI Type Descriptor',
                                     TargetType: &CTeamplayRoundBasedRules `RTTI Type Descriptor',
                                     isReference: 0);
  if ( v0 != nullptr )
    CTeamplayRoundBasedRules::RespawnPlayers(this: v0, bForceRespawn: true, bTeam: false, iTeam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10231910
// Name: void __near * SendProxy_TeamplayRoundBasedRules(class SendProp const __near *,void const __near *,void const __near *,class CSendProxyRecipients __near *,int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl SendProxy_TeamplayRoundBasedRules(
        const SendProp *pProp,
        const void *pStructBase,
        const void *pData,
        CSendProxyRecipients *pRecipients)
{
  void *result; // eax

  result = __RTDynamicCast(
             inptr: g_pGameRules,
             VfDelta: 0,
             SrcType: &CGameRules `RTTI Type Descriptor',
             TargetType: &CTeamplayRoundBasedRules `RTTI Type Descriptor',
             isReference: 0);
  if ( pRecipients != nullptr )
  {
    pRecipients->m_Bits.m_Ints[0] = -1;
    pRecipients->m_Bits.m_Ints[1] = -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040AD80
// Name: DT_TeamplayRoundBasedRules::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TeamplayRoundBasedRules::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_TeamplayRoundBasedRules::g_SendTable);
  return atexit(func: DT_TeamplayRoundBasedRules::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1040ADA0
// Name: DT_TeamplayRoundBasedRules::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TeamplayRoundBasedRules::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_TeamplayRoundBasedRules::ignored>();
  DT_TeamplayRoundBasedRules::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040ADD0
// Name: DT_TeamplayRoundBasedRulesProxy::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TeamplayRoundBasedRulesProxy::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_TeamplayRoundBasedRulesProxy::g_SendTable);
  return atexit(func: DT_TeamplayRoundBasedRulesProxy::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1040ADF0
// Name: DT_TeamplayRoundBasedRulesProxy::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TeamplayRoundBasedRulesProxy::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_TeamplayRoundBasedRulesProxy::ignored>();
  DT_TeamplayRoundBasedRulesProxy::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040AE00
// Name: CTeamplayRoundBasedRulesProxy_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CTeamplayRoundBasedRulesProxy_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CTeamplayRoundBasedRulesProxy>();
  CTeamplayRoundBasedRulesProxy_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041E4B0
// Name: DT_TeamplayRoundBasedRules::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TeamplayRoundBasedRules::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_TeamplayRoundBasedRules::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041E4C0
// Name: DT_TeamplayRoundBasedRulesProxy::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TeamplayRoundBasedRulesProxy::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_TeamplayRoundBasedRulesProxy::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1040ADB0
// Name: _dynamic_initializer_for__g_CTeamplayRoundBasedRulesProxy_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CTeamplayRoundBasedRulesProxy_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CTeamplayRoundBasedRulesProxy_ClassReg,
           pNetworkName: "CTeamplayRoundBasedRulesProxy",
           pTable: &DT_TeamplayRoundBasedRulesProxy::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1040AE10
// Name: _dynamic_initializer_for__mp_capstyle__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_capstyle__()
{
  ConVar::ConVar(
    this: &mp_capstyle,
    pName: "mp_capstyle",
    pDefaultValue: "1",
    flags: 8194,
    pHelpString: "Sets the style of capture points used. 0 = Fixed players required to cap. 1 = More players cap faster, but longer cap times.");
  return atexit(func: dynamic_atexit_destructor_for__mp_capstyle__);
}

//------------------------------------------------------------------------------
// Address: 0x1040AE40
// Name: _dynamic_initializer_for__mp_blockstyle__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_blockstyle__()
{
  ConVar::ConVar(
    this: &mp_blockstyle,
    pName: "mp_blockstyle",
    pDefaultValue: "1",
    flags: 8194,
    pHelpString: "Sets the style of capture point blocking used. 0 = Blocks break captures completely. 1 = Blocks only pause captures.");
  return atexit(func: dynamic_atexit_destructor_for__mp_blockstyle__);
}

//------------------------------------------------------------------------------
// Address: 0x1040AE70
// Name: _dynamic_initializer_for__mp_respawnwavetime__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_respawnwavetime__()
{
  ConVar::ConVar(
    this: &mp_respawnwavetime,
    pName: "mp_respawnwavetime",
    pDefaultValue: "10.0",
    flags: 8448,
    pHelpString: "Time between respawn waves.");
  return atexit(func: dynamic_atexit_destructor_for__mp_respawnwavetime__);
}

//------------------------------------------------------------------------------
// Address: 0x1040AEA0
// Name: _dynamic_initializer_for__mp_capdeteriorate_time__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_capdeteriorate_time__()
{
  ConVar::ConVar(
    this: &mp_capdeteriorate_time,
    pName: "mp_capdeteriorate_time",
    pDefaultValue: "90.0",
    flags: 8194,
    pHelpString: "Time it takes for a full capture point to deteriorate.");
  return atexit(func: dynamic_atexit_destructor_for__mp_capdeteriorate_time__);
}

//------------------------------------------------------------------------------
// Address: 0x1040AED0
// Name: _dynamic_initializer_for__mp_tournament__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_tournament__()
{
  ConVar::ConVar(this: &mp_tournament, pName: "mp_tournament", pDefaultValue: "0", flags: 8448);
  return atexit(func: dynamic_atexit_destructor_for__mp_tournament__);
}

//------------------------------------------------------------------------------
// Address: 0x1040AF00
// Name: _dynamic_initializer_for__tf_arena_preround_time__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__tf_arena_preround_time__()
{
  ConVar::ConVar(
    this: &tf_arena_preround_time,
    pName: "tf_arena_preround_time",
    pDefaultValue: "10",
    flags: 8448,
    pHelpString: "Length of the Pre-Round time",
    bMin: true,
    fMin: 5.0,
    bMax: true,
    fMax: 15.0);
  return atexit(func: dynamic_atexit_destructor_for__tf_arena_preround_time__);
}

//------------------------------------------------------------------------------
// Address: 0x1040AF50
// Name: _dynamic_initializer_for__tf_arena_round_time__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__tf_arena_round_time__()
{
  ConVar::ConVar(this: &tf_arena_round_time, pName: "tf_arena_round_time", pDefaultValue: "0", flags: 24834);
  return atexit(func: dynamic_atexit_destructor_for__tf_arena_round_time__);
}

//------------------------------------------------------------------------------
// Address: 0x1040AF80
// Name: _dynamic_initializer_for__tf_arena_max_streak__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__tf_arena_max_streak__()
{
  ConVar::ConVar(
    this: &tf_arena_max_streak,
    pName: "tf_arena_max_streak",
    pDefaultValue: "5",
    flags: 8448,
    pHelpString: "Teams will be scrambled if one team reaches this streak");
  return atexit(func: dynamic_atexit_destructor_for__tf_arena_max_streak__);
}

//------------------------------------------------------------------------------
// Address: 0x1040AFB0
// Name: _dynamic_initializer_for__mp_teams_unbalance_limit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_teams_unbalance_limit__()
{
  ConVar::ConVar(
    this: &mp_teams_unbalance_limit,
    pName: "mp_teams_unbalance_limit",
    pDefaultValue: "1",
    flags: 8448,
    pHelpString: "Teams are unbalanced when one team has this many more players than the other team. (0 disables check)",
    bMin: true,
    fMin: 0.0,
    bMax: true,
    fMax: 30.0);
  return atexit(func: dynamic_atexit_destructor_for__mp_teams_unbalance_limit__);
}

//------------------------------------------------------------------------------
// Address: 0x1040B000
// Name: _dynamic_initializer_for__mp_maxrounds__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_maxrounds__()
{
  ConVar::ConVar(
    this: &mp_maxrounds,
    pName: "mp_maxrounds",
    pDefaultValue: "0",
    flags: 8448,
    pHelpString: "max number of rounds to play before server changes maps",
    bMin: true,
    fMin: 0.0,
    bMax: false,
    fMax: 0.0);
  return atexit(func: dynamic_atexit_destructor_for__mp_maxrounds__);
}

//------------------------------------------------------------------------------
// Address: 0x1040B040
// Name: _dynamic_initializer_for__mp_winlimit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_winlimit__()
{
  ConVar::ConVar(
    this: &mp_winlimit,
    pName: "mp_winlimit",
    pDefaultValue: "0",
    flags: 8448,
    pHelpString: "Max score one team can reach before server changes maps",
    bMin: true,
    fMin: 0.0,
    bMax: false,
    fMax: 0.0);
  return atexit(func: dynamic_atexit_destructor_for__mp_winlimit__);
}

//------------------------------------------------------------------------------
// Address: 0x1040B080
// Name: _dynamic_initializer_for__mp_disable_respawn_times__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_disable_respawn_times__()
{
  ConVar::ConVar(this: &mp_disable_respawn_times, pName: "mp_disable_respawn_times", pDefaultValue: "0", flags: 8448);
  return atexit(func: dynamic_atexit_destructor_for__mp_disable_respawn_times__);
}

//------------------------------------------------------------------------------
// Address: 0x1040B0B0
// Name: _dynamic_initializer_for__mp_bonusroundtime__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_bonusroundtime__()
{
  ConVar::ConVar(
    this: &mp_bonusroundtime,
    pName: "mp_bonusroundtime",
    pDefaultValue: "15",
    flags: 0x2000,
    pHelpString: "Time after round win until round restarts",
    bMin: true,
    fMin: 5.0,
    bMax: true,
    fMax: 15.0);
  return atexit(func: dynamic_atexit_destructor_for__mp_bonusroundtime__);
}

//------------------------------------------------------------------------------
// Address: 0x1040B100
// Name: _dynamic_initializer_for__mp_showroundtransitions__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_showroundtransitions__()
{
  ConVar::ConVar(
    this: &mp_showroundtransitions,
    pName: "mp_showroundtransitions",
    pDefaultValue: "0",
    flags: 16386,
    pHelpString: "Show gamestate round transitions.");
  return atexit(func: dynamic_atexit_destructor_for__mp_showroundtransitions__);
}

//------------------------------------------------------------------------------
// Address: 0x1040B130
// Name: _dynamic_initializer_for__mp_enableroundwaittime__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_enableroundwaittime__()
{
  ConVar::ConVar(
    this: &mp_enableroundwaittime,
    pName: "mp_enableroundwaittime",
    pDefaultValue: "1",
    flags: 0x2000,
    pHelpString: "Enable timers to wait between rounds.");
  return atexit(func: dynamic_atexit_destructor_for__mp_enableroundwaittime__);
}

//------------------------------------------------------------------------------
// Address: 0x1040B160
// Name: _dynamic_initializer_for__mp_showcleanedupents__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_showcleanedupents__()
{
  ConVar::ConVar(
    this: &mp_showcleanedupents,
    pName: "mp_showcleanedupents",
    pDefaultValue: "0",
    flags: 16386,
    pHelpString: "Show entities that are removed on round respawn.");
  return atexit(func: dynamic_atexit_destructor_for__mp_showcleanedupents__);
}

//------------------------------------------------------------------------------
// Address: 0x1040B190
// Name: _dynamic_initializer_for__mp_restartround__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_restartround__()
{
  ConVar::ConVar(
    this: &mp_restartround,
    pName: "mp_restartround",
    pDefaultValue: "0",
    flags: 4,
    pHelpString: "If non-zero, the current round will restart in the specified number of seconds");
  return atexit(func: dynamic_atexit_destructor_for__mp_restartround__);
}

//------------------------------------------------------------------------------
// Address: 0x1040B1C0
// Name: _dynamic_initializer_for__mp_stalemate_timelimit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_stalemate_timelimit__()
{
  ConVar::ConVar(
    this: &mp_stalemate_timelimit,
    pName: "mp_stalemate_timelimit",
    pDefaultValue: "240",
    flags: 0x2000,
    pHelpString: "Timelimit (in seconds) of the stalemate round.");
  return atexit(func: dynamic_atexit_destructor_for__mp_stalemate_timelimit__);
}

//------------------------------------------------------------------------------
// Address: 0x1040B1F0
// Name: _dynamic_initializer_for__mp_autoteambalance__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_autoteambalance__()
{
  ConVar::ConVar(this: &mp_autoteambalance, pName: "mp_autoteambalance", pDefaultValue: "1", flags: 256);
  return atexit(func: dynamic_atexit_destructor_for__mp_autoteambalance__);
}

//------------------------------------------------------------------------------
// Address: 0x1040B220
// Name: _dynamic_initializer_for__mp_stalemate_enable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_stalemate_enable__()
{
  ConVar::ConVar(
    this: &mp_stalemate_enable,
    pName: "mp_stalemate_enable",
    pDefaultValue: "0",
    flags: 256,
    pHelpString: "Enable/Disable stalemate mode.");
  return atexit(func: dynamic_atexit_destructor_for__mp_stalemate_enable__);
}

//------------------------------------------------------------------------------
// Address: 0x1040B250
// Name: _dynamic_initializer_for__mp_stalemate_at_timelimit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_stalemate_at_timelimit__()
{
  ConVar::ConVar(
    this: &mp_stalemate_at_timelimit,
    pName: "mp_stalemate_at_timelimit",
    pDefaultValue: "0",
    flags: 256,
    pHelpString: "Allow the match to end when mp_timelimit hits instead of waiting for the end of the current round.");
  return atexit(func: dynamic_atexit_destructor_for__mp_stalemate_at_timelimit__);
}

//------------------------------------------------------------------------------
// Address: 0x1040B280
// Name: _dynamic_initializer_for__mp_switchteams__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_switchteams__()
{
  ConCommand::ConCommand(
    this: &mp_switchteams,
    pName: "mp_switchteams",
    callback: (void (__cdecl *)())cc_SwitchTeams,
    pHelpString: "Switch teams and restart the game",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__mp_switchteams__);
}

//------------------------------------------------------------------------------
// Address: 0x1040B2B0
// Name: _dynamic_initializer_for__mp_scrambleteams__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_scrambleteams__()
{
  ConCommand::ConCommand(
    this: &mp_scrambleteams,
    pName: "mp_scrambleteams",
    callback: (void (__cdecl *)())cc_ScrambleTeams,
    pHelpString: "Scramble the teams and restart the game",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__mp_scrambleteams__);
}

//------------------------------------------------------------------------------
// Address: 0x1040B2E0
// Name: _dynamic_initializer_for__mp_forcewin_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_forcewin_command__()
{
  ConCommand::ConCommand(
    this: &mp_forcewin_command,
    pName: "mp_forcewin",
    callback: (void (__cdecl *)())mp_forcewin,
    pHelpString: "Forces team to win",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__mp_forcewin_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1040B310
// Name: _dynamic_initializer_for__mp_forcerespawnplayers__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_forcerespawnplayers__()
{
  ConCommand::ConCommand(
    this: &mp_forcerespawnplayers,
    pName: "mp_forcerespawnplayers",
    callback: CC_CH_ForceRespawn,
    pHelpString: "Force all players to respawn.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__mp_forcerespawnplayers__);
}

//------------------------------------------------------------------------------
// Address: 0x1040B340
// Name: _dynamic_initializer_for__mp_tournament_restart__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_tournament_restart__()
{
  ConCommand::ConCommand(
    this: &mp_tournament_restart,
    pName: "mp_tournament_restart",
    callback: CC_CH_TournamentRestart,
    pHelpString: "Restart Tournament Mode on the current level.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__mp_tournament_restart__);
}

//------------------------------------------------------------------------------
// Address: 0x1041E4D0
// Name: _ServerClassInit_DT_TeamplayRoundBasedRulesProxy::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_TeamplayRoundBasedRulesProxy::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_130;
  for ( i = 2; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041E4F0
// Name: _dynamic_atexit_destructor_for__mp_capstyle__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_capstyle__()
{
  ConVar::~ConVar(this: &mp_capstyle);
}

//------------------------------------------------------------------------------
// Address: 0x1041E500
// Name: _dynamic_atexit_destructor_for__mp_blockstyle__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_blockstyle__()
{
  ConVar::~ConVar(this: &mp_blockstyle);
}

//------------------------------------------------------------------------------
// Address: 0x1041E510
// Name: _dynamic_atexit_destructor_for__mp_respawnwavetime__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_respawnwavetime__()
{
  ConVar::~ConVar(this: &mp_respawnwavetime);
}

//------------------------------------------------------------------------------
// Address: 0x1041E520
// Name: _dynamic_atexit_destructor_for__mp_capdeteriorate_time__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_capdeteriorate_time__()
{
  ConVar::~ConVar(this: &mp_capdeteriorate_time);
}

//------------------------------------------------------------------------------
// Address: 0x1041E530
// Name: _dynamic_atexit_destructor_for__mp_tournament__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_tournament__()
{
  ConVar::~ConVar(this: &mp_tournament);
}

//------------------------------------------------------------------------------
// Address: 0x1041E540
// Name: _dynamic_atexit_destructor_for__tf_arena_preround_time__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__tf_arena_preround_time__()
{
  ConVar::~ConVar(this: &tf_arena_preround_time);
}

//------------------------------------------------------------------------------
// Address: 0x1041E550
// Name: _dynamic_atexit_destructor_for__tf_arena_round_time__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__tf_arena_round_time__()
{
  ConVar::~ConVar(this: &tf_arena_round_time);
}

//------------------------------------------------------------------------------
// Address: 0x1041E560
// Name: _dynamic_atexit_destructor_for__tf_arena_max_streak__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__tf_arena_max_streak__()
{
  ConVar::~ConVar(this: &tf_arena_max_streak);
}

//------------------------------------------------------------------------------
// Address: 0x1041E570
// Name: _dynamic_atexit_destructor_for__mp_teams_unbalance_limit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_teams_unbalance_limit__()
{
  ConVar::~ConVar(this: &mp_teams_unbalance_limit);
}

//------------------------------------------------------------------------------
// Address: 0x1041E580
// Name: _dynamic_atexit_destructor_for__mp_maxrounds__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_maxrounds__()
{
  ConVar::~ConVar(this: &mp_maxrounds);
}

//------------------------------------------------------------------------------
// Address: 0x1041E590
// Name: _dynamic_atexit_destructor_for__mp_winlimit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_winlimit__()
{
  ConVar::~ConVar(this: &mp_winlimit);
}

//------------------------------------------------------------------------------
// Address: 0x1041E5A0
// Name: _dynamic_atexit_destructor_for__mp_disable_respawn_times__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_disable_respawn_times__()
{
  ConVar::~ConVar(this: &mp_disable_respawn_times);
}

//------------------------------------------------------------------------------
// Address: 0x1041E5B0
// Name: _dynamic_atexit_destructor_for__mp_bonusroundtime__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_bonusroundtime__()
{
  ConVar::~ConVar(this: &mp_bonusroundtime);
}

//------------------------------------------------------------------------------
// Address: 0x1041E5C0
// Name: _dynamic_atexit_destructor_for__mp_showroundtransitions__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_showroundtransitions__()
{
  ConVar::~ConVar(this: &mp_showroundtransitions);
}

//------------------------------------------------------------------------------
// Address: 0x1041E5D0
// Name: _dynamic_atexit_destructor_for__mp_enableroundwaittime__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_enableroundwaittime__()
{
  ConVar::~ConVar(this: &mp_enableroundwaittime);
}

//------------------------------------------------------------------------------
// Address: 0x1041E5E0
// Name: _dynamic_atexit_destructor_for__mp_showcleanedupents__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_showcleanedupents__()
{
  ConVar::~ConVar(this: &mp_showcleanedupents);
}

//------------------------------------------------------------------------------
// Address: 0x1041E5F0
// Name: _dynamic_atexit_destructor_for__mp_restartround__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_restartround__()
{
  ConVar::~ConVar(this: &mp_restartround);
}

//------------------------------------------------------------------------------
// Address: 0x1041E600
// Name: _dynamic_atexit_destructor_for__mp_stalemate_timelimit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_stalemate_timelimit__()
{
  ConVar::~ConVar(this: &mp_stalemate_timelimit);
}

//------------------------------------------------------------------------------
// Address: 0x1041E610
// Name: _dynamic_atexit_destructor_for__mp_autoteambalance__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_autoteambalance__()
{
  ConVar::~ConVar(this: &mp_autoteambalance);
}

//------------------------------------------------------------------------------
// Address: 0x1041E620
// Name: _dynamic_atexit_destructor_for__mp_stalemate_enable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_stalemate_enable__()
{
  ConVar::~ConVar(this: &mp_stalemate_enable);
}

//------------------------------------------------------------------------------
// Address: 0x1041E630
// Name: _dynamic_atexit_destructor_for__mp_stalemate_at_timelimit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_stalemate_at_timelimit__()
{
  ConVar::~ConVar(this: &mp_stalemate_at_timelimit);
}

//------------------------------------------------------------------------------
// Address: 0x1041E640
// Name: _dynamic_atexit_destructor_for__mp_switchteams__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_switchteams__()
{
  ConCommand::~ConCommand(this: &mp_switchteams);
}

//------------------------------------------------------------------------------
// Address: 0x1041E650
// Name: _dynamic_atexit_destructor_for__mp_scrambleteams__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_scrambleteams__()
{
  ConCommand::~ConCommand(this: &mp_scrambleteams);
}

//------------------------------------------------------------------------------
// Address: 0x1041E660
// Name: _dynamic_atexit_destructor_for__mp_forcewin_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_forcewin_command__()
{
  ConCommand::~ConCommand(this: &mp_forcewin_command);
}

//------------------------------------------------------------------------------
// Address: 0x1041E670
// Name: _dynamic_atexit_destructor_for__mp_forcerespawnplayers__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_forcerespawnplayers__()
{
  ConCommand::~ConCommand(this: &mp_forcerespawnplayers);
}

//------------------------------------------------------------------------------
// Address: 0x1041E680
// Name: _dynamic_atexit_destructor_for__mp_tournament_restart__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_tournament_restart__()
{
  ConCommand::~ConCommand(this: &mp_tournament_restart);
}

//------------------------------------------------------------------------------
// Address: 0x1041E690
// Name: _ServerClassInit_DT_TeamplayRoundBasedRules::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_TeamplayRoundBasedRules::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_220;
  for ( i = 13; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041E6B0
// Name: _dynamic_atexit_destructor_for__g_hControlPointMasters__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_hControlPointMasters__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_hControlPointMasters);
}

//------------------------------------------------------------------------------
// Address: 0x1041E6C0
// Name: _DataMapInit_CTeamplayRoundBasedRulesProxy__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CTeamplayRoundBasedRulesProxy__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_414);
}

} // namespace server
