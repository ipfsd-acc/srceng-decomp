// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_te_beampoints.cpp
// Functions: 10
// ============================================================

#include "game\client\c_te_beampoints.h"

//------------------------------------------------------------------------------
// Address: 0x10255160
// Name: void TE_BeamPoints(class IRecipientFilter __near &,float,class Vector const __near *,class Vector const __near *,int,int,int,int,float,float,float,int,float,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_BeamPoints(
        IRecipientFilter *filter,
        float delay,
        const Vector *start,
        const Vector *end,
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

  v18 = (float)framerate * 0.1;
  v19 = (double)speed * 0.1;
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))beams->CreateBeamPoints)(
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
    a18: (float)b);
}

//------------------------------------------------------------------------------
// Address: 0x10255250
// Name: public: virtual void C_TEBeamPoints::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TEBeamPoints::PostDataUpdate(C_TEBeamPoints *this, DataUpdateType_t updateType)
{
  float v2; // xmm1_4
  float v3; // xmm0_4

  v2 = (double)this->m_nStartFrame * 0.1;
  v3 = (double)this->a * 0.1;
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))beams->CreateBeamPoints)(
    a1: beams,
    a2: &this->m_nFlags,
    a3: &this->m_vecStartPoint.z,
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
    a18: (float)this->g);
}

//------------------------------------------------------------------------------
// Address: 0x10255330
// Name: public: virtual class ClientClass __near * C_TEBeamPoints::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_TEBeamPoints::GetClientClass(C_TEBeamPoints *this)
{
  return &__g_C_TEBeamPointsClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1042B3F0
// Name: DT_TEBeamPoints::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEBeamPoints::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_TEBeamPoints::g_RecvTable);
  return atexit(func: DT_TEBeamPoints::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042B410
// Name: DT_TEBeamPoints::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEBeamPoints::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_TEBeamPoints::ignored>();
  DT_TEBeamPoints::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436850
// Name: DT_TEBeamPoints::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEBeamPoints::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_TEBeamPoints::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10255340
// Name: _C_TEBeamPoints_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_TEBeamPoints_CreateObject()
{
  return &_g_C_TEBeamPoints.IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1042B420
// Name: _dynamic_initializer_for____g_C_TEBeamRing__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____g_C_TEBeamRing__()
{
  C_TEBaseBeam::C_TEBaseBeam(this: &_g_C_TEBeamRing);
  _g_C_TEBeamRing.C_TEBaseBeam::C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEBeamRing_vtbl *)&C_TEBeamRing::`vftable'{for `IClientUnknown'};
  _g_C_TEBeamRing.C_TEBaseBeam::C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEBeamRing::`vftable'{for `IClientNetworkable'};
  _g_C_TEBeamRing.m_nStartEntity = 0;
  _g_C_TEBeamRing.m_nEndEntity = 0;
  return atexit(func: dynamic_atexit_destructor_for____g_C_TEBeamRing__);
}

//------------------------------------------------------------------------------
// Address: 0x1042B460
// Name: _dynamic_initializer_for____g_C_TEBeamRingClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_TEBeamRingClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_TEBeamRingClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_TEBeamRingClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436860
// Name: _dynamic_atexit_destructor_for____g_C_TEBeamRing__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____g_C_TEBeamRing__()
{
  _g_C_TEBeamRing.C_TEBaseBeam::C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEBeamRing_vtbl *)&C_TEBeamRing::`vftable'{for `IClientUnknown'};
  _g_C_TEBeamRing.C_TEBaseBeam::C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEBeamRing::`vftable'{for `IClientNetworkable'};
  C_TEBaseBeam::~C_TEBaseBeam(this: &_g_C_TEBeamRing);
}
