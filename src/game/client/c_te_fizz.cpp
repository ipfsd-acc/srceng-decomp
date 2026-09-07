// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_te_fizz.cpp
// Functions: 9
// ============================================================

#include "game\client\c_te_fizz.h"

//------------------------------------------------------------------------------
// Address: 0x10259BE0
// Name: void TE_Fizz(class IRecipientFilter __near &,float,class C_BaseEntity const __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_Fizz(IRecipientFilter *filter, float delay, C_BaseEntity *ed, int modelindex, int density, int current)
{
  if ( ed != nullptr )
    tempents->FizzEffect(this: tempents, a2: ed, a3: modelindex, a4: density, a5: current);
}

//------------------------------------------------------------------------------
// Address: 0x10259C10
// Name: public: virtual class ClientClass __near * C_TEFizz::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_TEFizz::GetClientClass(C_TEFizz *this)
{
  return &__g_C_TEFizzClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10259D30
// Name: public: virtual void C_TEFizz::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TEFizz::PostDataUpdate(C_TEFizz *this, DataUpdateType_t updateType)
{
  C_BaseEntity *BaseEntity; // eax

  BaseEntity = CClientEntityList::GetBaseEntity(
                 this: (CClientEntityList *)cl_entitylist.m_Index,
                 entnum: (int)this->m_pNextDynamic);
  if ( BaseEntity != nullptr )
    tempents->FizzEffect(
      this: tempents,
      a2: BaseEntity,
      a3: this->m_nEntity,
      a4: this->m_nModelIndex,
      a5: this->m_nDensity);
}

//------------------------------------------------------------------------------
// Address: 0x1042C0E0
// Name: DT_TEFizz::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEFizz::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_TEFizz::g_RecvTable);
  return atexit(func: DT_TEFizz::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042C100
// Name: DT_TEFizz::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEFizz::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_TEFizz::ignored>();
  DT_TEFizz::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436B70
// Name: DT_TEFizz::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEFizz::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_TEFizz::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10259C20
// Name: _C_TEFizz_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_TEFizz_CreateObject()
{
  return &_g_C_TEFizz.IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1042C110
// Name: _dynamic_initializer_for____g_C_TEFootprintDecal__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____g_C_TEFootprintDecal__()
{
  C_BaseTempEntity::C_BaseTempEntity(this: &_g_C_TEFootprintDecal);
  _g_C_TEFootprintDecal.C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEFootprintDecal_vtbl *)&C_TEFootprintDecal::`vftable'{for `IClientUnknown'};
  _g_C_TEFootprintDecal.C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEFootprintDecal::`vftable'{for `IClientNetworkable'};
  _g_C_TEFootprintDecal.m_vecOrigin.x = 0.0;
  _g_C_TEFootprintDecal.m_vecOrigin.y = 0.0;
  _g_C_TEFootprintDecal.m_vecOrigin.z = 0.0;
  _g_C_TEFootprintDecal.m_vecStart.x = 0.0;
  _g_C_TEFootprintDecal.m_vecStart.y = 0.0;
  _g_C_TEFootprintDecal.m_vecStart.z = 0.0;
  _g_C_TEFootprintDecal.m_nEntity = 0;
  _g_C_TEFootprintDecal.m_nIndex = 0;
  _g_C_TEFootprintDecal.m_chMaterialType = 67;
  return atexit(func: dynamic_atexit_destructor_for____g_C_TEFootprintDecal__);
}

//------------------------------------------------------------------------------
// Address: 0x1042C180
// Name: _dynamic_initializer_for____g_C_TEFootprintDecalClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_TEFootprintDecalClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_TEFootprintDecalClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_TEFootprintDecalClientClass;
  return result;
}
