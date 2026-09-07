// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_te_beamlaser.cpp
// Functions: 10
// ============================================================

#include "game\client\c_te_beamlaser.h"

//------------------------------------------------------------------------------
// Address: 0x10254EA0
// Name: void TE_BeamLaser(class IRecipientFilter __near &,float,int,int,int,int,int,int,float,float,float,int,float,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_BeamLaser(
        IRecipientFilter *filter,
        float delay,
        int start,
        int end,
        int modelindex,
        int haloindex,
        int startframe,
        int framerate,
        float life,
        float width,
        float endWidth,
        int fadeLength,
        float amplitude,
        int r,
        int g,
        int b,
        int a,
        int speed)
{
  float v18; // xmm1_4
  float v19; // xmm0_4

  v18 = (double)framerate * 0.1;
  v19 = (double)speed * 0.1;
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))beams->CreateBeamEnts)(
    a1: beams,
    a2: start,
    a3: end,
    a4: modelindex,
    a5: haloindex,
    a6: 0,
    a7: LODWORD(life),
    a8: LODWORD(width),
    a9: LODWORD(endWidth),
    a10: (float)fadeLength,
    a11: LODWORD(amplitude),
    a12: (float)a,
    a13: LODWORD(v19),
    a14: startframe,
    a15: LODWORD(v18),
    a16: (float)r,
    a17: (float)g,
    a18: (float)b,
    a19: 8);
}

//------------------------------------------------------------------------------
// Address: 0x10254F80
// Name: public: virtual void C_TEBeamLaser::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TEBeamLaser::PostDataUpdate(C_TEBeamLaser *this, DataUpdateType_t updateType)
{
  float v2; // xmm1_4
  float v3; // xmm0_4

  v2 = (double)this->m_nStartFrame * 0.1;
  v3 = (double)this->a * 0.1;
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))beams->CreateBeamEnts)(
    a1: beams,
    a2: this->m_nFlags,
    a3: this->m_nStartEntity,
    a4: this->m_pNextDynamic,
    a5: this->m_nModelIndex,
    a6: 0,
    a7: this->m_nFrameRate,
    a8: LODWORD(this->m_fLife),
    a9: LODWORD(this->m_fWidth),
    a10: (float)SLODWORD(this->m_fEndWidth),
    a11: this->m_nFadeLength,
    a12: (float)this->b,
    a13: LODWORD(v3),
    a14: this->m_nHaloIndex,
    a15: LODWORD(v2),
    a16: (float)SLODWORD(this->m_fAmplitude),
    a17: (float)this->r,
    a18: (float)this->g,
    a19: 8);
}

//------------------------------------------------------------------------------
// Address: 0x10255070
// Name: public: virtual class ClientClass __near * C_TEBeamLaser::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_TEBeamLaser::GetClientClass(C_TEBeamLaser *this)
{
  return &__g_C_TEBeamLaserClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1042B340
// Name: DT_TEBeamLaser::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEBeamLaser::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_TEBeamLaser::g_RecvTable);
  return atexit(func: DT_TEBeamLaser::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042B360
// Name: DT_TEBeamLaser::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEBeamLaser::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_TEBeamLaser::ignored>();
  DT_TEBeamLaser::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436820
// Name: DT_TEBeamLaser::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEBeamLaser::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_TEBeamLaser::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10255080
// Name: _C_TEBeamLaser_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_TEBeamLaser_CreateObject()
{
  return &_g_C_TEBeamLaser.IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1042B370
// Name: _dynamic_initializer_for____g_C_TEBeamPoints__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____g_C_TEBeamPoints__()
{
  C_TEBaseBeam::C_TEBaseBeam(this: &_g_C_TEBeamPoints);
  _g_C_TEBeamPoints.C_TEBaseBeam::C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEBeamPoints_vtbl *)&C_TEBeamPoints::`vftable'{for `IClientUnknown'};
  _g_C_TEBeamPoints.C_TEBaseBeam::C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEBeamPoints::`vftable'{for `IClientNetworkable'};
  _g_C_TEBeamPoints.m_vecStartPoint.x = 0.0;
  _g_C_TEBeamPoints.m_vecStartPoint.y = 0.0;
  _g_C_TEBeamPoints.m_vecStartPoint.z = 0.0;
  _g_C_TEBeamPoints.m_vecEndPoint.x = 0.0;
  _g_C_TEBeamPoints.m_vecEndPoint.y = 0.0;
  _g_C_TEBeamPoints.m_vecEndPoint.z = 0.0;
  return atexit(func: dynamic_atexit_destructor_for____g_C_TEBeamPoints__);
}

//------------------------------------------------------------------------------
// Address: 0x1042B3D0
// Name: _dynamic_initializer_for____g_C_TEBeamPointsClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_TEBeamPointsClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_TEBeamPointsClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_TEBeamPointsClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436830
// Name: _dynamic_atexit_destructor_for____g_C_TEBeamPoints__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____g_C_TEBeamPoints__()
{
  _g_C_TEBeamPoints.C_TEBaseBeam::C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEBeamPoints_vtbl *)&C_TEBeamPoints::`vftable'{for `IClientUnknown'};
  _g_C_TEBeamPoints.C_TEBaseBeam::C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEBeamPoints::`vftable'{for `IClientNetworkable'};
  C_TEBaseBeam::~C_TEBaseBeam(this: &_g_C_TEBeamPoints);
}
