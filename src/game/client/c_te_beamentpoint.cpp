// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_te_beamentpoint.cpp
// Functions: 10
// ============================================================

#include "game\client\c_te_beamentpoint.h"

//------------------------------------------------------------------------------
// Address: 0x102546D0
// Name: void TE_BeamEntPoint(class IRecipientFilter __near &,float,int,class Vector const __near *,int,class Vector const __near *,int,int,int,int,float,float,float,int,float,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_BeamEntPoint(
        IRecipientFilter *filter,
        float delay,
        int nStartEntity,
        const Vector *pStart,
        int nEndEntity,
        const Vector *pEnd,
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
  float v20; // xmm0_4

  v20 = (float)speed * 0.1;
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))beams->CreateBeamEntPoint)(
    a1: beams,
    a2: nStartEntity,
    a3: pStart,
    a4: nEndEntity,
    a5: pEnd,
    a6: modelindex,
    a7: haloindex,
    a8: 0,
    a9: LODWORD(life),
    a10: LODWORD(width),
    a11: LODWORD(endWidth),
    a12: (float)fadeLength,
    a13: LODWORD(amplitude),
    a14: (float)a,
    a15: LODWORD(v20),
    a16: startframe,
    a17: (float)framerate * 0.1,
    a18: (float)r,
    a19: (float)g,
    a20: (float)b);
}

//------------------------------------------------------------------------------
// Address: 0x102547C0
// Name: public: virtual void C_TEBeamEntPoint::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TEBeamEntPoint::PostDataUpdate(C_TEBeamEntPoint *this, DataUpdateType_t updateType)
{
  float v2; // xmm1_4
  float v3; // xmm0_4

  v2 = (double)this->m_nStartFrame * 0.1;
  v3 = (double)this->a * 0.1;
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))beams->CreateBeamEntPoint)(
    a1: beams,
    a2: this->m_nFlags,
    a3: &this->m_nEndEntity,
    a4: this->m_nStartEntity,
    a5: &this->m_vecStartPoint.z,
    a6: this->m_pNextDynamic,
    a7: this->m_nModelIndex,
    a8: 0,
    a9: this->m_nFrameRate,
    a10: LODWORD(this->m_fLife),
    a11: LODWORD(this->m_fWidth),
    a12: (float)SLODWORD(this->m_fEndWidth),
    a13: this->m_nFadeLength,
    a14: (float)this->b,
    a15: LODWORD(v3),
    a16: this->m_nHaloIndex,
    a17: LODWORD(v2),
    a18: (float)SLODWORD(this->m_fAmplitude),
    a19: (float)this->r,
    a20: (float)this->g);
}

//------------------------------------------------------------------------------
// Address: 0x102548B0
// Name: public: virtual class ClientClass __near * C_TEBeamEntPoint::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_TEBeamEntPoint::GetClientClass(C_TEBeamEntPoint *this)
{
  return &__g_C_TEBeamEntPointClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1042B190
// Name: DT_TEBeamEntPoint::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEBeamEntPoint::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_TEBeamEntPoint::g_RecvTable);
  return atexit(func: DT_TEBeamEntPoint::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042B1B0
// Name: DT_TEBeamEntPoint::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEBeamEntPoint::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_TEBeamEntPoint::ignored>();
  DT_TEBeamEntPoint::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436790
// Name: DT_TEBeamEntPoint::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEBeamEntPoint::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_TEBeamEntPoint::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x102548C0
// Name: _C_TEBeamEntPoint_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_TEBeamEntPoint_CreateObject()
{
  return &_g_C_TEBeamEntPoint.IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1042B1C0
// Name: _dynamic_initializer_for____g_C_TEBeamEnts__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____g_C_TEBeamEnts__()
{
  C_TEBaseBeam::C_TEBaseBeam(this: &_g_C_TEBeamEnts);
  _g_C_TEBeamEnts.C_TEBaseBeam::C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEBeamEnts_vtbl *)&C_TEBeamEnts::`vftable'{for `IClientUnknown'};
  _g_C_TEBeamEnts.C_TEBaseBeam::C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEBeamEnts::`vftable'{for `IClientNetworkable'};
  _g_C_TEBeamEnts.m_nStartEntity = 0;
  _g_C_TEBeamEnts.m_nEndEntity = 0;
  return atexit(func: dynamic_atexit_destructor_for____g_C_TEBeamEnts__);
}

//------------------------------------------------------------------------------
// Address: 0x1042B200
// Name: _dynamic_initializer_for____g_C_TEBeamEntsClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_TEBeamEntsClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_TEBeamEntsClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_TEBeamEntsClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104367A0
// Name: _dynamic_atexit_destructor_for____g_C_TEBeamEnts__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____g_C_TEBeamEnts__()
{
  _g_C_TEBeamEnts.C_TEBaseBeam::C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEBeamEnts_vtbl *)&C_TEBeamEnts::`vftable'{for `IClientUnknown'};
  _g_C_TEBeamEnts.C_TEBaseBeam::C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEBeamEnts::`vftable'{for `IClientNetworkable'};
  C_TEBaseBeam::~C_TEBaseBeam(this: &_g_C_TEBeamEnts);
}
