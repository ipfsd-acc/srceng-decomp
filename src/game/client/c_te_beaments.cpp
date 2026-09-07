// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_te_beaments.cpp
// Functions: 10
// ============================================================

#include "game\client\c_te_beaments.h"

//------------------------------------------------------------------------------
// Address: 0x102549D0
// Name: void TE_BeamEnts(class IRecipientFilter __near &,float,int,int,int,int,int,int,float,float,float,int,float,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_BeamEnts(
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

  v18 = (float)framerate * 0.1;
  v19 = (float)speed * 0.1;
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
    a19: -1);
}

//------------------------------------------------------------------------------
// Address: 0x10254AC0
// Name: public: virtual void C_TEBeamEnts::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TEBeamEnts::PostDataUpdate(C_TEBeamEnts *this, DataUpdateType_t updateType)
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
    a19: -1);
}

//------------------------------------------------------------------------------
// Address: 0x10254BB0
// Name: public: virtual class ClientClass __near * C_TEBeamEnts::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_TEBeamEnts::GetClientClass(C_TEBeamEnts *this)
{
  return &__g_C_TEBeamEntsClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1042B220
// Name: DT_TEBeamEnts::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEBeamEnts::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_TEBeamEnts::g_RecvTable);
  return atexit(func: DT_TEBeamEnts::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042B240
// Name: DT_TEBeamEnts::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEBeamEnts::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_TEBeamEnts::ignored>();
  DT_TEBeamEnts::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104367C0
// Name: DT_TEBeamEnts::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEBeamEnts::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_TEBeamEnts::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10254BC0
// Name: _C_TEBeamEnts_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_TEBeamEnts_CreateObject()
{
  return &_g_C_TEBeamEnts.IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1042B250
// Name: _dynamic_initializer_for____g_C_TEBeamFollow__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____g_C_TEBeamFollow__()
{
  C_TEBaseBeam::C_TEBaseBeam(this: &_g_C_TEBeamFollow);
  _g_C_TEBeamFollow.C_TEBaseBeam::C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEBeamFollow_vtbl *)&C_TEBeamFollow::`vftable'{for `IClientUnknown'};
  _g_C_TEBeamFollow.C_TEBaseBeam::C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEBeamFollow::`vftable'{for `IClientNetworkable'};
  _g_C_TEBeamFollow.m_iEntIndex = 0;
  return atexit(func: dynamic_atexit_destructor_for____g_C_TEBeamFollow__);
}

//------------------------------------------------------------------------------
// Address: 0x1042B290
// Name: _dynamic_initializer_for____g_C_TEBeamFollowClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_TEBeamFollowClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_TEBeamFollowClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_TEBeamFollowClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104367D0
// Name: _dynamic_atexit_destructor_for____g_C_TEBeamFollow__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____g_C_TEBeamFollow__()
{
  _g_C_TEBeamFollow.C_TEBaseBeam::C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEBeamFollow_vtbl *)&C_TEBeamFollow::`vftable'{for `IClientUnknown'};
  _g_C_TEBeamFollow.C_TEBaseBeam::C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEBeamFollow::`vftable'{for `IClientNetworkable'};
  C_TEBaseBeam::~C_TEBaseBeam(this: &_g_C_TEBeamFollow);
}
