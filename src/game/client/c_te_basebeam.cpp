// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_te_basebeam.cpp
// Functions: 10
// ============================================================

#include "game\client\c_te_basebeam.h"

//------------------------------------------------------------------------------
// Address: 0x102543C0
// Name: public: C_TEBaseBeam::C_TEBaseBeam(void)
// Source: json
//------------------------------------------------------------------------------
C_TEBaseBeam *__thiscall C_TEBaseBeam::C_TEBaseBeam(C_TEBaseBeam *this)
{
  C_BaseTempEntity::C_BaseTempEntity(this);
  this->m_nModelIndex = 0;
  this->m_nHaloIndex = 0;
  this->m_nStartFrame = 0;
  this->m_nFrameRate = 0;
  this->m_nFadeLength = 0;
  this->a = 0;
  this->b = 0;
  this->g = 0;
  this->r = 0;
  this->m_nSpeed = 0;
  this->m_nFlags = 0;
  this->C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEBaseBeam_vtbl *)&C_TEBaseBeam::`vftable'{for `IClientUnknown'};
  this->C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEBaseBeam::`vftable'{for `IClientNetworkable'};
  this->m_fLife = 0.0;
  this->m_fWidth = 0.0;
  this->m_fEndWidth = 0.0;
  this->m_fAmplitude = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10254420
// Name: public: virtual C_TEBaseBeam::~C_TEBaseBeam(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TEBaseBeam::~C_TEBaseBeam(C_TEBaseBeam *this)
{
  this->C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEBaseBeam_vtbl *)&C_TEBaseBeam::`vftable'{for `IClientUnknown'};
  this->C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEBaseBeam::`vftable'{for `IClientNetworkable'};
  C_BaseTempEntity::~C_BaseTempEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x10254440
// Name: public: virtual class ClientClass __near * C_TEBaseBeam::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_TEBaseBeam::GetClientClass(C_TEBaseBeam *this)
{
  return &__g_C_TEBaseBeamClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1042B0F0
// Name: DT_BaseBeam::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseBeam::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_BaseBeam::g_RecvTable);
  return atexit(func: DT_BaseBeam::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042B110
// Name: DT_BaseBeam::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseBeam::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_BaseBeam::ignored>();
  DT_BaseBeam::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436760
// Name: DT_BaseBeam::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_BaseBeam::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_BaseBeam::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10254450
// Name: _C_TEBaseBeam_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_TEBaseBeam_CreateObject(int entnum, int serialNum)
{
  C_BaseTempEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_BaseTempEntity *)MemAlloc_Alloc(nSize: 0x4Cu);
  v3 = &v2->IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_BaseTempEntity::C_BaseTempEntity(this: v2);
  *v3 = &C_TEBaseBeam::`vftable'{for `IClientUnknown'};
  v3[1] = &C_TEBaseBeam::`vftable'{for `IClientNetworkable'};
  v3[4] = 0;
  v3[5] = 0;
  v3[6] = 0;
  v3[7] = 0;
  v3[8] = 0;
  v3[9] = 0;
  v3[10] = 0;
  v3[11] = 0;
  v3[12] = 0;
  v3[16] = 0;
  v3[15] = 0;
  v3[14] = 0;
  v3[13] = 0;
  v3[17] = 0;
  v3[18] = 0;
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 52))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 1);
}

//------------------------------------------------------------------------------
// Address: 0x1042B120
// Name: _dynamic_initializer_for____g_C_TEBeamEntPoint__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____g_C_TEBeamEntPoint__()
{
  C_TEBaseBeam::C_TEBaseBeam(this: &_g_C_TEBeamEntPoint);
  _g_C_TEBeamEntPoint.C_TEBaseBeam::C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEBeamEntPoint_vtbl *)&C_TEBeamEntPoint::`vftable'{for `IClientUnknown'};
  _g_C_TEBeamEntPoint.C_TEBaseBeam::C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEBeamEntPoint::`vftable'{for `IClientNetworkable'};
  _g_C_TEBeamEntPoint.m_nStartEntity = 0;
  _g_C_TEBeamEntPoint.m_vecEndPoint.x = 0.0;
  _g_C_TEBeamEntPoint.m_vecEndPoint.y = 0.0;
  _g_C_TEBeamEntPoint.m_vecEndPoint.z = 0.0;
  return atexit(func: dynamic_atexit_destructor_for____g_C_TEBeamEntPoint__);
}

//------------------------------------------------------------------------------
// Address: 0x1042B170
// Name: _dynamic_initializer_for____g_C_TEBeamEntPointClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_TEBeamEntPointClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_TEBeamEntPointClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_TEBeamEntPointClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436770
// Name: _dynamic_atexit_destructor_for____g_C_TEBeamEntPoint__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____g_C_TEBeamEntPoint__()
{
  _g_C_TEBeamEntPoint.C_TEBaseBeam::C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEBeamEntPoint_vtbl *)&C_TEBeamEntPoint::`vftable'{for `IClientUnknown'};
  _g_C_TEBeamEntPoint.C_TEBaseBeam::C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEBeamEntPoint::`vftable'{for `IClientNetworkable'};
  C_TEBaseBeam::~C_TEBaseBeam(this: &_g_C_TEBeamEntPoint);
}
