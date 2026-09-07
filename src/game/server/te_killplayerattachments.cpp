// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/te_killplayerattachments.cpp
// Functions: 12
// ============================================================

#include "game\server\te_killplayerattachments.h"

//------------------------------------------------------------------------------
// Address: 0x10332D90
// Name: public: virtual class ServerClass __near * CTEKillPlayerAttachments::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CTEKillPlayerAttachments::GetServerClass(CTEKillPlayerAttachments *this)
{
  return &g_CTEKillPlayerAttachments_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10332E70
// Name: public: virtual void CTEKillPlayerAttachments::Test(class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTEKillPlayerAttachments::Test(
        CTEKillPlayerAttachments *this,
        const Vector *current_origin,
        const QAngle *current_angles)
{
  CBroadcastRecipientFilter filter; // [esp+8h] [ebp-20h] BYREF

  if ( this->m_nPlayer.m_Value != 1 )
    this->m_nPlayer.m_Value = 1;
  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CBroadcastRecipientFilter_vtbl *)&CBroadcastRecipientFilter::`vftable';
  CRecipientFilter::AddAllPlayers(this: &filter);
  ((void (__thiscall *)(CTEKillPlayerAttachments *, CBroadcastRecipientFilter *, _DWORD))this->Create)(
    a1: this,
    a2: &filter,
    a3: 0);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x10332ED0
// Name: void TE_KillPlayerAttachments(class IRecipientFilter __near &,float,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_KillPlayerAttachments(IRecipientFilter *filter, float delay, int player)
{
  if ( g_TEKillPlayerAttachments.m_nPlayer.m_Value != player )
    g_TEKillPlayerAttachments.m_nPlayer.m_Value = player;
  CBaseTempEntity::Create(this: &g_TEKillPlayerAttachments, filter, delay);
}

//------------------------------------------------------------------------------
// Address: 0x10400E50
// Name: _dynamic_initializer_for__kill_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__kill_command__()
{
  ConCommand::ConCommand(
    this: &kill_command,
    pName: "kill",
    callback: (void (__cdecl *)())kill,
    pHelpString: "Kills the player with generic damage",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__kill_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10417130
// Name: DT_TEKillPlayerAttachments::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEKillPlayerAttachments::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_TEKillPlayerAttachments::g_SendTable);
  return atexit(func: DT_TEKillPlayerAttachments::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10417150
// Name: DT_TEKillPlayerAttachments::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEKillPlayerAttachments::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_TEKillPlayerAttachments::ignored>();
  DT_TEKillPlayerAttachments::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041A290
// Name: _dynamic_atexit_destructor_for__kill_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__kill_command__()
{
  ConCommand::~ConCommand(this: &kill_command);
}

//------------------------------------------------------------------------------
// Address: 0x10422680
// Name: DT_TEKillPlayerAttachments::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEKillPlayerAttachments::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_TEKillPlayerAttachments::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10417160
// Name: _dynamic_initializer_for__g_TEKillPlayerAttachments__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TEKillPlayerAttachments__()
{
  CBaseTempEntity::CBaseTempEntity(this: &g_TEKillPlayerAttachments, name: "KillPlayerAttachments");
  g_TEKillPlayerAttachments.__vftable = (CTEKillPlayerAttachments_vtbl *)&CTEKillPlayerAttachments::`vftable';
  if ( g_TEKillPlayerAttachments.m_nPlayer.m_Value != 0 )
    g_TEKillPlayerAttachments.m_nPlayer.m_Value = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_TEKillPlayerAttachments__);
}

//------------------------------------------------------------------------------
// Address: 0x104171A0
// Name: _dynamic_initializer_for__g_CTELargeFunnel_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CTELargeFunnel_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CTELargeFunnel_ClassReg,
           pNetworkName: "CTELargeFunnel",
           pTable: &DT_TELargeFunnel::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10422690
// Name: _dynamic_atexit_destructor_for__g_TEKillPlayerAttachments__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TEKillPlayerAttachments__()
{
  g_TEKillPlayerAttachments.__vftable = (CTEKillPlayerAttachments_vtbl *)&CTEKillPlayerAttachments::`vftable';
  CBaseTempEntity::~CBaseTempEntity(this: &g_TEKillPlayerAttachments);
}

//------------------------------------------------------------------------------
// Address: 0x104226B0
// Name: _ServerClassInit_DT_TEKillPlayerAttachments::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_TEKillPlayerAttachments::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_349;
  for ( i = 2; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}
