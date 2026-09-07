// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_basecombatcharacter.cpp
// Functions: 16
// ============================================================

#include "game\client\c_basecombatcharacter.h"

//------------------------------------------------------------------------------
// Address: 0x10036A60
// Name: public: virtual C_BaseCombatCharacter::~C_BaseCombatCharacter(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseCombatCharacter::~C_BaseCombatCharacter(C_BaseCombatCharacter *this)
{
  this->C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_BaseCombatCharacter_vtbl *)&C_BaseCombatCharacter::`vftable'{for `IClientUnknown'};
  this->C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_BaseCombatCharacter::`vftable'{for `IClientRenderable'};
  this->C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_BaseCombatCharacter::`vftable'{for `IClientNetworkable'};
  this->C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_BaseCombatCharacter::`vftable'{for `IClientThinkable'};
  this->C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_BaseCombatCharacter::`vftable';
  C_BaseFlex::~C_BaseFlex(this);
}

//------------------------------------------------------------------------------
// Address: 0x10036A90
// Name: public: virtual void C_BaseCombatCharacter::DoMuzzleFlash(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseCombatCharacter::DoMuzzleFlash(C_BaseCombatCharacter *this)
{
  C_BaseCombatWeapon *v2; // eax

  v2 = this->GetActiveWeapon(this);
  if ( v2 != nullptr )
    v2->DoMuzzleFlash(this: v2);
  else
    C_BaseAnimating::DoMuzzleFlash(this);
}

//------------------------------------------------------------------------------
// Address: 0x10036AC0
// Name: public: virtual class ClientClass __near * C_BaseCombatCharacter::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_BaseCombatCharacter::GetClientClass(C_BaseCombatCharacter *this)
{
  return &__g_C_BaseCombatCharacterClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10036C30
// Name: public: virtual struct datamap_t __near * C_BaseCombatCharacter::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_BaseCombatCharacter::GetPredDescMap(C_BaseCombatCharacter *this)
{
  return &C_BaseCombatCharacter::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x10036C90
// Name: public: C_BaseCombatCharacter::C_BaseCombatCharacter(void)
// Source: json
//------------------------------------------------------------------------------
C_BaseCombatCharacter *__thiscall C_BaseCombatCharacter::C_BaseCombatCharacter(C_BaseCombatCharacter *this)
{
  int *v2; // eax
  int i; // edx

  C_BaseFlex::C_BaseFlex(this);
  this->C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_BaseCombatCharacter_vtbl *)&C_BaseCombatCharacter::`vftable'{for `IClientUnknown'};
  this->C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_BaseCombatCharacter::`vftable'{for `IClientRenderable'};
  this->C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_BaseCombatCharacter::`vftable'{for `IClientNetworkable'};
  this->C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_BaseCombatCharacter::`vftable'{for `IClientThinkable'};
  this->C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_BaseCombatCharacter::`vftable';
  memset(this->m_hMyWeapons, 0xFFu, sizeof(this->m_hMyWeapons));
  this->m_hActiveWeapon.m_Index = -1;
  v2 = &this->m_iAmmo.m_Value[2];
  for ( i = 8; i != 0; --i )
  {
    if ( *(v2 - 2) != 0 )
      *(v2 - 2) = 0;
    if ( *(v2 - 1) != 0 )
      *(v2 - 1) = 0;
    if ( *v2 != 0 )
      *v2 = 0;
    if ( v2[1] != 0 )
      v2[1] = 0;
    v2 += 4;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10410930
// Name: DT_BCCLocalPlayerExclusive::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_BCCLocalPlayerExclusive::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_BCCLocalPlayerExclusive::g_RecvTable);
  return atexit(func: DT_BCCLocalPlayerExclusive::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10410950
// Name: DT_BCCLocalPlayerExclusive::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_BCCLocalPlayerExclusive::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_BCCLocalPlayerExclusive::ignored>();
  DT_BCCLocalPlayerExclusive::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10410960
// Name: DT_BaseCombatCharacter::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseCombatCharacter::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_BaseCombatCharacter::g_RecvTable);
  return atexit(func: DT_BaseCombatCharacter::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10410980
// Name: DT_BaseCombatCharacter::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseCombatCharacter::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_BaseCombatCharacter::ignored>();
  DT_BaseCombatCharacter::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10410990
// Name: C_BaseCombatCharacter_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_BaseCombatCharacter_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_BaseCombatCharacter::m_PredMap.dataNumFields = 4;
  C_BaseCombatCharacter::m_PredMap.dataDesc = (typedescription_t *)&unk_10599BF4;
}

//------------------------------------------------------------------------------
// Address: 0x1042FB90
// Name: DT_BCCLocalPlayerExclusive::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_BCCLocalPlayerExclusive::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_BCCLocalPlayerExclusive::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x1042FBA0
// Name: DT_BaseCombatCharacter::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_BaseCombatCharacter::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_BaseCombatCharacter::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10036D10
// Name: _C_BaseCombatCharacter_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_BaseCombatCharacter_CreateObject(int entnum, int serialNum)
{
  C_BaseCombatCharacter *v2; // eax
  C_BaseCombatCharacter *v3; // eax
  C_BaseCombatCharacter *v4; // esi

  v2 = (C_BaseCombatCharacter *)C_BaseEntity::operator new(stAllocateBlock: 0x1230u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_BaseCombatCharacter::C_BaseCombatCharacter(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x104109B0
// Name: _dynamic_initializer_for__cl_viewmodelsclonedasworld__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_viewmodelsclonedasworld__()
{
  ConVar::ConVar(this: &cl_viewmodelsclonedasworld, pName: "cl_viewmodelsclonedasworld", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__cl_viewmodelsclonedasworld__);
}

//------------------------------------------------------------------------------
// Address: 0x104109E0
// Name: _dynamic_initializer_for____g_C_BaseDoorClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_BaseDoorClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_BaseDoorClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_BaseDoorClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042FBB0
// Name: _dynamic_atexit_destructor_for__cl_viewmodelsclonedasworld__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_viewmodelsclonedasworld__()
{
  ConVar::~ConVar(this: &cl_viewmodelsclonedasworld);
}
