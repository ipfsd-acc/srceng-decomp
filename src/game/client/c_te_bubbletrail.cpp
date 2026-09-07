// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_te_bubbletrail.cpp
// Functions: 10
// ============================================================

#include "game\client\c_te_bubbletrail.h"

//------------------------------------------------------------------------------
// Address: 0x102577C0
// Name: void TE_BubbleTrail(class IRecipientFilter __near &,float,class Vector const __near *,class Vector const __near *,float,int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_BubbleTrail(
        IRecipientFilter *filter,
        float delay,
        const Vector *mins,
        const Vector *maxs,
        float flWaterZ,
        int modelindex,
        int count,
        float speed)
{
  ((void (__stdcall *)(const Vector *, const Vector *, _DWORD, int, int, _DWORD))tempents->BubbleTrail)(
    a1: mins,
    a2: maxs,
    a3: LODWORD(flWaterZ),
    a4: modelindex,
    a5: count,
    a6: LODWORD(speed));
}

//------------------------------------------------------------------------------
// Address: 0x10257800
// Name: public: virtual void C_TEBubbleTrail::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TEBubbleTrail::PostDataUpdate(C_TEBubbleTrail *this, DataUpdateType_t updateType)
{
  ((void (__thiscall *)(ITempEnts *, C_BaseTempEntity **, float *, _DWORD, _DWORD, int, int))tempents->BubbleTrail)(
    a1: tempents,
    a2: &this->m_pNextDynamic,
    a3: &this->m_vecMins.z,
    a4: LODWORD(this->m_vecMaxs.z),
    a5: LODWORD(this->m_flWaterZ),
    a6: this->m_nModelIndex,
    a7: this->m_nCount);
}

//------------------------------------------------------------------------------
// Address: 0x10257840
// Name: public: virtual class ClientClass __near * C_TEBubbleTrail::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_TEBubbleTrail::GetClientClass(C_TEBubbleTrail *this)
{
  return &__g_C_TEBubbleTrailClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1042BAE0
// Name: DT_TEBubbleTrail::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEBubbleTrail::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_TEBubbleTrail::g_RecvTable);
  return atexit(func: DT_TEBubbleTrail::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042BB00
// Name: DT_TEBubbleTrail::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEBubbleTrail::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_TEBubbleTrail::ignored>();
  DT_TEBubbleTrail::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436A00
// Name: DT_TEBubbleTrail::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEBubbleTrail::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_TEBubbleTrail::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10257850
// Name: _C_TEBubbleTrail_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_TEBubbleTrail_CreateObject()
{
  return &_g_C_TEBubbleTrail.IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1042BB10
// Name: _dynamic_initializer_for____g_C_TEClientProjectile__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____g_C_TEClientProjectile__()
{
  C_BaseTempEntity::C_BaseTempEntity(this: &_g_C_TEClientProjectile);
  _g_C_TEClientProjectile.C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEClientProjectile_vtbl *)&C_TEClientProjectile::`vftable'{for `IClientUnknown'};
  _g_C_TEClientProjectile.C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEClientProjectile::`vftable'{for `IClientNetworkable'};
  _g_C_TEClientProjectile.m_vecOrigin.x = 0.0;
  _g_C_TEClientProjectile.m_vecOrigin.y = 0.0;
  _g_C_TEClientProjectile.m_vecOrigin.z = 0.0;
  _g_C_TEClientProjectile.m_vecVelocity.x = 0.0;
  _g_C_TEClientProjectile.m_vecVelocity.y = 0.0;
  _g_C_TEClientProjectile.m_vecVelocity.z = 0.0;
  _g_C_TEClientProjectile.m_nModelIndex = 0;
  _g_C_TEClientProjectile.m_nLifeTime = 0;
  _g_C_TEClientProjectile.m_hOwner.m_Index = -1;
  return atexit(func: dynamic_atexit_destructor_for____g_C_TEClientProjectile__);
}

//------------------------------------------------------------------------------
// Address: 0x1042BB90
// Name: _dynamic_initializer_for____g_C_TEClientProjectileClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_TEClientProjectileClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_TEClientProjectileClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_TEClientProjectileClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436A10
// Name: _dynamic_atexit_destructor_for____g_C_TEClientProjectile__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____g_C_TEClientProjectile__()
{
  _g_C_TEClientProjectile.C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEClientProjectile_vtbl *)&C_TEClientProjectile::`vftable'{for `IClientUnknown'};
  _g_C_TEClientProjectile.C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEClientProjectile::`vftable'{for `IClientNetworkable'};
  C_BaseTempEntity::~C_BaseTempEntity(this: &_g_C_TEClientProjectile);
}
