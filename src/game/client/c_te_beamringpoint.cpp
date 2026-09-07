// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_te_beamringpoint.cpp
// Functions: 10
// ============================================================

#include "game\client\c_te_beamringpoint.h"

//------------------------------------------------------------------------------
// Address: 0x102556F0
// Name: void TE_BeamRingPoint(class IRecipientFilter __near &,float,class Vector const __near &,float,float,int,int,int,int,float,float,int,float,int,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_BeamRingPoint(
        IRecipientFilter *filter,
        float delay,
        const Vector *center,
        float start_radius,
        float end_radius,
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
  float v19; // xmm1_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // [esp+34h] [ebp-14h]

  v19 = (double)framerate * 0.1;
  v22 = v19;
  v20 = (double)speed * 0.1;
  v21 = (double)spread * 0.1;
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))beams->CreateBeamRingPoint)(
    a1: beams,
    a2: center,
    a3: LODWORD(start_radius),
    a4: LODWORD(end_radius),
    a5: modelindex,
    a6: haloindex,
    a7: 0,
    a8: LODWORD(life),
    a9: LODWORD(width),
    a10: LODWORD(v21),
    a11: 0,
    a12: LODWORD(amplitude),
    a13: (float)a,
    a14: LODWORD(v20),
    a15: startframe,
    a16: LODWORD(v22),
    a17: (float)r,
    a18: (float)g,
    a19: (float)b,
    a20: flags);
}

//------------------------------------------------------------------------------
// Address: 0x102557F0
// Name: public: virtual void C_TEBeamRingPoint::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TEBeamRingPoint::PostDataUpdate(C_TEBeamRingPoint *this, DataUpdateType_t updateType)
{
  float v2; // xmm1_4
  float v3; // xmm0_4

  v2 = (double)this->m_nStartFrame * 0.1;
  v3 = (double)this->a * 0.1;
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))beams->CreateBeamRingPoint)(
    a1: beams,
    a2: &this->m_nFlags,
    a3: LODWORD(this->m_vecCenter.z),
    a4: LODWORD(this->m_flStartRadius),
    a5: this->m_pNextDynamic,
    a6: this->m_nModelIndex,
    a7: 0,
    a8: this->m_nFrameRate,
    a9: LODWORD(this->m_fLife),
    a10: LODWORD(this->m_fWidth),
    a11: (float)SLODWORD(this->m_fEndWidth),
    a12: this->m_nFadeLength,
    a13: (float)this->b,
    a14: LODWORD(v3),
    a15: this->m_nHaloIndex,
    a16: LODWORD(v2),
    a17: (float)SLODWORD(this->m_fAmplitude),
    a18: (float)this->r,
    a19: (float)this->g,
    a20: this->m_nSpeed);
}

//------------------------------------------------------------------------------
// Address: 0x102558F0
// Name: public: virtual class ClientClass __near * C_TEBeamRingPoint::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_TEBeamRingPoint::GetClientClass(C_TEBeamRingPoint *this)
{
  return &__g_C_TEBeamRingPointClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1042B530
// Name: DT_TEBeamRingPoint::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEBeamRingPoint::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_TEBeamRingPoint::g_RecvTable);
  return atexit(func: DT_TEBeamRingPoint::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042B550
// Name: DT_TEBeamRingPoint::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEBeamRingPoint::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_TEBeamRingPoint::ignored>();
  DT_TEBeamRingPoint::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104368B0
// Name: DT_TEBeamRingPoint::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEBeamRingPoint::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_TEBeamRingPoint::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10255900
// Name: _C_TEBeamRingPoint_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_TEBeamRingPoint_CreateObject()
{
  return &_g_C_TEBeamRingPoint.IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1042B560
// Name: _dynamic_initializer_for____g_C_TEBeamSpline__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____g_C_TEBeamSpline__()
{
  float *p_z; // eax

  C_BaseTempEntity::C_BaseTempEntity(this: &_g_C_TEBeamSpline);
  _g_C_TEBeamSpline.C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEBeamSpline_vtbl *)&C_TEBeamSpline::`vftable'{for `IClientUnknown'};
  _g_C_TEBeamSpline.C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEBeamSpline::`vftable'{for `IClientNetworkable'};
  p_z = &_g_C_TEBeamSpline.m_vecPoints[0].z;
  do
  {
    *(p_z - 2) = 0.0;
    *(p_z - 1) = 0.0;
    *p_z = 0.0;
    p_z += 3;
  }
  while ( (int)p_z < (int)&DT_TEBeamSpline::g_RecvTable.m_nProps );
  _g_C_TEBeamSpline.m_nPoints = 0;
  return atexit(func: dynamic_atexit_destructor_for____g_C_TEBeamSpline__);
}

//------------------------------------------------------------------------------
// Address: 0x1042B5C0
// Name: _dynamic_initializer_for____g_C_TEBeamSplineClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_TEBeamSplineClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_TEBeamSplineClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_TEBeamSplineClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104368C0
// Name: _dynamic_atexit_destructor_for____g_C_TEBeamSpline__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____g_C_TEBeamSpline__()
{
  _g_C_TEBeamSpline.C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEBeamSpline_vtbl *)&C_TEBeamSpline::`vftable'{for `IClientUnknown'};
  _g_C_TEBeamSpline.C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEBeamSpline::`vftable'{for `IClientNetworkable'};
  C_BaseTempEntity::~C_BaseTempEntity(this: &_g_C_TEBeamSpline);
}
