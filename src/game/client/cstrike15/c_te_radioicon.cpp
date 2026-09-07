// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/c_te_radioicon.cpp
// Functions: 8
// ============================================================

#include "game\client\cstrike15\c_te_radioicon.h"

//------------------------------------------------------------------------------
// Address: 0x101BFE30
// Name: public: virtual class ClientClass __near * C_TERadioIcon::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_TERadioIcon::GetClientClass(C_TERadioIcon *this)
{
  return &__g_C_TERadioIconClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x101BFF00
// Name: public: virtual void C_TERadioIcon::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TERadioIcon::PostDataUpdate(C_TERadioIcon *this, DataUpdateType_t updateType)
{
  C_BaseEntity *BaseEntity; // eax
  CRadioStatus *v4; // eax
  C_BaseTempEntity *m_pNextDynamic; // [esp-4h] [ebp-Ch]

  BaseEntity = CClientEntityList::GetBaseEntity(
                 this: (CClientEntityList *)cl_entitylist.m_Index,
                 entnum: (int)this->m_pNextDynamic);
  if ( BaseEntity != nullptr && !BaseEntity->IsDormant(this: &BaseEntity->IClientNetworkable) )
  {
    m_pNextDynamic = this->m_pNextDynamic;
    v4 = RadioManager();
    CRadioStatus::UpdateRadioStatus(this: v4, entindex: (int)m_pNextDynamic, duration: 1.5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10422430
// Name: DT_TERadioIcon::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TERadioIcon::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_TERadioIcon::g_RecvTable);
  return atexit(func: DT_TERadioIcon::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10422450
// Name: DT_TERadioIcon::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TERadioIcon::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_TERadioIcon::ignored>();
  DT_TERadioIcon::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10435360
// Name: DT_TERadioIcon::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TERadioIcon::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_TERadioIcon::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x101BFE40
// Name: _C_TERadioIcon_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_TERadioIcon_CreateObject()
{
  return &_g_C_TERadioIcon.IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x10422460
// Name: _dynamic_initializer_for____g_C_TEFireBullets__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____g_C_TEFireBullets__()
{
  C_BaseTempEntity::C_BaseTempEntity(this: &_g_C_TEFireBullets);
  _g_C_TEFireBullets.C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEFireBullets_vtbl *)&C_TEFireBullets::`vftable'{for `IClientUnknown'};
  _g_C_TEFireBullets.C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEFireBullets::`vftable'{for `IClientNetworkable'};
  return atexit(func: dynamic_atexit_destructor_for____g_C_TEFireBullets__);
}

//------------------------------------------------------------------------------
// Address: 0x10422490
// Name: _dynamic_initializer_for____g_C_TEFireBulletsClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_TEFireBulletsClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_TEFireBulletsClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_TEFireBulletsClientClass;
  return result;
}
