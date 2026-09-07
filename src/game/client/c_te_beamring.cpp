// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_te_beamring.cpp
// Functions: 10
// ============================================================

#include "game\client\c_te_beamring.h"

//------------------------------------------------------------------------------
// Address: 0x10255420
// Name: void TE_BeamRing(class IRecipientFilter __near &,float,int,int,int,int,int,int,float,float,int,float,int,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_BeamRing(
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
        int spread,
        float amplitude,
        int r,
        int g,
        int b,
        int a,
        int speed,
        int flags)
{
  float v18; // xmm1_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  float v21; // [esp+24h] [ebp-14h]

  v18 = (double)framerate * 0.1;
  v21 = v18;
  v19 = (double)speed * 0.1;
  v20 = (double)spread * 0.1;
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))beams->CreateBeamRing)(
    a1: beams,
    a2: start,
    a3: end,
    a4: modelindex,
    a5: haloindex,
    a6: 0,
    a7: LODWORD(life),
    a8: LODWORD(width),
    a9: LODWORD(v20),
    a10: 0,
    a11: LODWORD(amplitude),
    a12: (float)a,
    a13: LODWORD(v19),
    a14: startframe,
    a15: LODWORD(v21),
    a16: (float)r,
    a17: (float)g,
    a18: (float)b,
    a19: flags);
}

//------------------------------------------------------------------------------
// Address: 0x10255510
// Name: public: virtual void C_TEBeamRing::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TEBeamRing::PostDataUpdate(C_TEBeamRing *this, DataUpdateType_t updateType)
{
  float v2; // xmm1_4
  float v3; // xmm0_4

  v2 = (double)this->m_nStartFrame * 0.1;
  v3 = (double)this->a * 0.1;
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))beams->CreateBeamRing)(
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
    a19: this->m_nSpeed);
}

//------------------------------------------------------------------------------
// Address: 0x10255600
// Name: public: virtual class ClientClass __near * C_TEBeamRing::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_TEBeamRing::GetClientClass(C_TEBeamRing *this)
{
  return &__g_C_TEBeamRingClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1042B480
// Name: DT_TEBeamRing::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEBeamRing::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_TEBeamRing::g_RecvTable);
  return atexit(func: DT_TEBeamRing::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042B4A0
// Name: DT_TEBeamRing::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEBeamRing::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_TEBeamRing::ignored>();
  DT_TEBeamRing::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436880
// Name: DT_TEBeamRing::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEBeamRing::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_TEBeamRing::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10255610
// Name: _C_TEBeamRing_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_TEBeamRing_CreateObject()
{
  return &_g_C_TEBeamRing.IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1042B4B0
// Name: _dynamic_initializer_for____g_C_TEBeamRingPoint__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____g_C_TEBeamRingPoint__()
{
  C_TEBaseBeam::C_TEBaseBeam(this: &_g_C_TEBeamRingPoint);
  _g_C_TEBeamRingPoint.C_TEBaseBeam::C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEBeamRingPoint_vtbl *)&C_TEBeamRingPoint::`vftable'{for `IClientUnknown'};
  _g_C_TEBeamRingPoint.C_TEBaseBeam::C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEBeamRingPoint::`vftable'{for `IClientNetworkable'};
  _g_C_TEBeamRingPoint.m_vecCenter.x = 0.0;
  _g_C_TEBeamRingPoint.m_vecCenter.y = 0.0;
  _g_C_TEBeamRingPoint.m_vecCenter.z = 0.0;
  _g_C_TEBeamRingPoint.m_flStartRadius = 0.0;
  _g_C_TEBeamRingPoint.m_flEndRadius = 0.0;
  return atexit(func: dynamic_atexit_destructor_for____g_C_TEBeamRingPoint__);
}

//------------------------------------------------------------------------------
// Address: 0x1042B510
// Name: _dynamic_initializer_for____g_C_TEBeamRingPointClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_TEBeamRingPointClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_TEBeamRingPointClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_TEBeamRingPointClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436890
// Name: _dynamic_atexit_destructor_for____g_C_TEBeamRingPoint__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____g_C_TEBeamRingPoint__()
{
  _g_C_TEBeamRingPoint.C_TEBaseBeam::C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEBeamRingPoint_vtbl *)&C_TEBeamRingPoint::`vftable'{for `IClientUnknown'};
  _g_C_TEBeamRingPoint.C_TEBaseBeam::C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEBeamRingPoint::`vftable'{for `IClientNetworkable'};
  C_TEBaseBeam::~C_TEBaseBeam(this: &_g_C_TEBeamRingPoint);
}
