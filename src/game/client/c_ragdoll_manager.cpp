// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_ragdoll_manager.cpp
// Functions: 5
// ============================================================

#include "game\client\c_ragdoll_manager.h"

//------------------------------------------------------------------------------
// Address: 0x10081D80
// Name: public: virtual class ClientClass __near * C_RagdollManager::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_RagdollManager::GetClientClass(C_RagdollManager *this)
{
  return &__g_C_RagdollManagerClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10081E60
// Name: public: virtual void C_RagdollManager::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_RagdollManager::OnDataChanged(C_RagdollManager *this, DataUpdateType_t updateType)
{
  C_BaseEntity::OnDataChanged(this, type: updateType);
  s_RagdollLRU.m_iMaxRagdolls = *(_DWORD *)&this->m_bIsBlurred;
}

//------------------------------------------------------------------------------
// Address: 0x104131A0
// Name: DT_RagdollManager::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_RagdollManager::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_RagdollManager::g_RecvTable);
  return atexit(func: DT_RagdollManager::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104131C0
// Name: DT_RagdollManager::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_RagdollManager::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_RagdollManager::ignored>();
  DT_RagdollManager::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430900
// Name: DT_RagdollManager::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_RagdollManager::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_RagdollManager::g_RecvTable);
}
