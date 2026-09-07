// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_te_killplayerattachments.cpp
// Functions: 10
// ============================================================

#include "game\client\c_te_killplayerattachments.h"

//------------------------------------------------------------------------------
// Address: 0x1025B510
// Name: public: virtual void C_TEKillPlayerAttachments::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TEKillPlayerAttachments::PostDataUpdate(C_TEKillPlayerAttachments *this, DataUpdateType_t updateType)
{
  tempents->KillAttachedTents(this: tempents, a2: (int)this->m_pNextDynamic);
}

//------------------------------------------------------------------------------
// Address: 0x1025B530
// Name: void TE_KillPlayerAttachments(class IRecipientFilter __near &,float,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_KillPlayerAttachments(IRecipientFilter *filter, float delay, int player)
{
  tempents->KillAttachedTents(this: tempents, a2: player);
}

//------------------------------------------------------------------------------
// Address: 0x1025B550
// Name: public: virtual class ClientClass __near * C_TEKillPlayerAttachments::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_TEKillPlayerAttachments::GetClientClass(C_TEKillPlayerAttachments *this)
{
  return &__g_C_TEKillPlayerAttachmentsClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1042C530
// Name: DT_TEKillPlayerAttachments::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEKillPlayerAttachments::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_TEKillPlayerAttachments::g_RecvTable);
  return atexit(func: DT_TEKillPlayerAttachments::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042C550
// Name: DT_TEKillPlayerAttachments::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEKillPlayerAttachments::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_TEKillPlayerAttachments::ignored>();
  DT_TEKillPlayerAttachments::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436C70
// Name: DT_TEKillPlayerAttachments::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEKillPlayerAttachments::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_TEKillPlayerAttachments::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x1025B560
// Name: _C_TEKillPlayerAttachments_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_TEKillPlayerAttachments_CreateObject()
{
  return &_g_C_TEKillPlayerAttachments.IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1042C560
// Name: _dynamic_initializer_for____g_C_TELargeFunnel__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____g_C_TELargeFunnel__()
{
  C_TEParticleSystem::C_TEParticleSystem(this: &_g_C_TELargeFunnel);
  _g_C_TELargeFunnel.C_TEParticleSystem::C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TELargeFunnel_vtbl *)&C_TELargeFunnel::`vftable'{for `IClientUnknown'};
  _g_C_TELargeFunnel.C_TEParticleSystem::C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TELargeFunnel::`vftable'{for `IClientNetworkable'};
  _g_C_TELargeFunnel.m_nModelIndex = 0;
  _g_C_TELargeFunnel.m_nReversed = 0;
  return atexit(func: dynamic_atexit_destructor_for____g_C_TELargeFunnel__);
}

//------------------------------------------------------------------------------
// Address: 0x1042C5A0
// Name: _dynamic_initializer_for____g_C_TELargeFunnelClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_TELargeFunnelClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_TELargeFunnelClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_TELargeFunnelClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436C80
// Name: _dynamic_atexit_destructor_for____g_C_TELargeFunnel__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____g_C_TELargeFunnel__()
{
  _g_C_TELargeFunnel.C_TEParticleSystem::C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TELargeFunnel_vtbl *)&C_TELargeFunnel::`vftable'{for `IClientUnknown'};
  _g_C_TELargeFunnel.C_TEParticleSystem::C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TELargeFunnel::`vftable'{for `IClientNetworkable'};
  C_BaseTempEntity::~C_BaseTempEntity(this: &_g_C_TELargeFunnel);
}
