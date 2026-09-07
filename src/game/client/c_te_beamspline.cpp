// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_te_beamspline.cpp
// Functions: 9
// ============================================================

#include "game\client\c_te_beamspline.h"

//------------------------------------------------------------------------------
// Address: 0x10255A00
// Name: void TE_BeamSpline(class IRecipientFilter __near &,float,int,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_BeamSpline()
{
  _DevMsg(a1: 1, a2: "Beam spline with %i points invoked\n");
}

//------------------------------------------------------------------------------
// Address: 0x10255A20
// Name: public: virtual void C_TEBeamSpline::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TEBeamSpline::PostDataUpdate(C_TEBeamSpline *this, DataUpdateType_t updateType)
{
  _DevMsg(a1: 1, a2: "Beam spline with %i points received\n");
}

//------------------------------------------------------------------------------
// Address: 0x10255A40
// Name: public: virtual class ClientClass __near * C_TEBeamSpline::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_TEBeamSpline::GetClientClass(C_TEBeamSpline *this)
{
  return &__g_C_TEBeamSplineClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1042B5E0
// Name: DT_TEBeamSpline::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEBeamSpline::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_TEBeamSpline::g_RecvTable);
  return atexit(func: DT_TEBeamSpline::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042B600
// Name: DT_TEBeamSpline::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEBeamSpline::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_TEBeamSpline::ignored>();
  DT_TEBeamSpline::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104368E0
// Name: DT_TEBeamSpline::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEBeamSpline::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_TEBeamSpline::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10255A50
// Name: _C_TEBeamSpline_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_TEBeamSpline_CreateObject()
{
  return &_g_C_TEBeamSpline.IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1042B610
// Name: _dynamic_initializer_for____g_C_TEBloodSprite__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____g_C_TEBloodSprite__()
{
  C_BaseTempEntity::C_BaseTempEntity(this: &_g_C_TEBloodSprite);
  _g_C_TEBloodSprite.C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEBloodSprite_vtbl *)&C_TEBloodSprite::`vftable'{for `IClientUnknown'};
  _g_C_TEBloodSprite.C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEBloodSprite::`vftable'{for `IClientNetworkable'};
  _g_C_TEBloodSprite.m_vecOrigin.x = 0.0;
  _g_C_TEBloodSprite.m_vecOrigin.y = 0.0;
  _g_C_TEBloodSprite.m_vecOrigin.z = 0.0;
  _g_C_TEBloodSprite.m_vecDirection.x = 0.0;
  _g_C_TEBloodSprite.m_vecDirection.y = 0.0;
  _g_C_TEBloodSprite.m_vecDirection.z = 0.0;
  _g_C_TEBloodSprite.a = 0;
  _g_C_TEBloodSprite.b = 0;
  _g_C_TEBloodSprite.g = 0;
  _g_C_TEBloodSprite.r = 0;
  _g_C_TEBloodSprite.m_nSize = 0;
  _g_C_TEBloodSprite.m_nSprayModel = 0;
  _g_C_TEBloodSprite.m_nDropModel = 0;
  return atexit(func: dynamic_atexit_destructor_for____g_C_TEBloodSprite__);
}

//------------------------------------------------------------------------------
// Address: 0x1042B6A0
// Name: _dynamic_initializer_for____g_C_TEBloodSpriteClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_TEBloodSpriteClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_TEBloodSpriteClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_TEBloodSpriteClientClass;
  return result;
}
