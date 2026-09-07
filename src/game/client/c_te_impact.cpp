// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_te_impact.cpp
// Functions: 8
// ============================================================

#include "game\client\c_te_impact.h"

//------------------------------------------------------------------------------
// Address: 0x1025B3F0
// Name: public: virtual class ClientClass __near * C_TEImpact::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_TEImpact::GetClientClass(C_TEImpact *this)
{
  return &__g_C_TEImpactClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1042C4A0
// Name: DT_TEImpact::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEImpact::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_TEImpact::g_RecvTable);
  return atexit(func: DT_TEImpact::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042C4C0
// Name: DT_TEImpact::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEImpact::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_TEImpact::ignored>();
  DT_TEImpact::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436C40
// Name: DT_TEImpact::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEImpact::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_TEImpact::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x1025B400
// Name: _C_TEImpact_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_TEImpact_CreateObject()
{
  return &_g_C_TEImpact.IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1042C4D0
// Name: _dynamic_initializer_for____g_C_TEKillPlayerAttachments__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____g_C_TEKillPlayerAttachments__()
{
  C_BaseTempEntity::C_BaseTempEntity(this: &_g_C_TEKillPlayerAttachments);
  _g_C_TEKillPlayerAttachments.C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEKillPlayerAttachments_vtbl *)&C_TEKillPlayerAttachments::`vftable'{for `IClientUnknown'};
  _g_C_TEKillPlayerAttachments.C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEKillPlayerAttachments::`vftable'{for `IClientNetworkable'};
  _g_C_TEKillPlayerAttachments.m_nPlayer = 0;
  return atexit(func: dynamic_atexit_destructor_for____g_C_TEKillPlayerAttachments__);
}

//------------------------------------------------------------------------------
// Address: 0x1042C510
// Name: _dynamic_initializer_for____g_C_TEKillPlayerAttachmentsClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_TEKillPlayerAttachmentsClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_TEKillPlayerAttachmentsClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_TEKillPlayerAttachmentsClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436C50
// Name: _dynamic_atexit_destructor_for____g_C_TEKillPlayerAttachments__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____g_C_TEKillPlayerAttachments__()
{
  _g_C_TEKillPlayerAttachments.C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEKillPlayerAttachments_vtbl *)&C_TEKillPlayerAttachments::`vftable'{for `IClientUnknown'};
  _g_C_TEKillPlayerAttachments.C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEKillPlayerAttachments::`vftable'{for `IClientNetworkable'};
  C_BaseTempEntity::~C_BaseTempEntity(this: &_g_C_TEKillPlayerAttachments);
}
