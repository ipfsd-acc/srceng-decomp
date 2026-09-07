// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_te_beamfollow.cpp
// Functions: 10
// ============================================================

#include "game\client\c_te_beamfollow.h"

//------------------------------------------------------------------------------
// Address: 0x10254CA0
// Name: public: virtual void C_TEBeamFollow::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TEBeamFollow::PostDataUpdate(C_TEBeamFollow *this, DataUpdateType_t updateType)
{
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))beams->CreateBeamFollow)(
    a1: beams,
    a2: this->m_nFlags,
    a3: this->m_pNextDynamic,
    a4: this->m_nModelIndex,
    a5: 0,
    a6: this->m_nFrameRate,
    a7: LODWORD(this->m_fLife),
    a8: LODWORD(this->m_fWidth),
    a9: (float)SLODWORD(this->m_fEndWidth),
    a10: (float)SLODWORD(this->m_fAmplitude),
    a11: (float)this->r,
    a12: (float)this->g,
    a13: (float)this->b);
}

//------------------------------------------------------------------------------
// Address: 0x10254D40
// Name: public: virtual class ClientClass __near * C_TEBeamFollow::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_TEBeamFollow::GetClientClass(C_TEBeamFollow *this)
{
  return &__g_C_TEBeamFollowClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10254DE0
// Name: void TE_BeamFollow(class IRecipientFilter __near &,float,int,int,int,float,float,float,float,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_BeamFollow(
        IRecipientFilter *filter,
        float delay,
        int iEntIndex,
        int modelIndex,
        int haloIndex,
        float life,
        float width,
        float endWidth,
        float fadeLength,
        float r,
        float g,
        float b,
        float a)
{
  ((void (__thiscall *)(IViewRenderBeams *, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))beams->CreateBeamFollow)(
    a1: beams,
    a2: iEntIndex,
    a3: modelIndex,
    a4: haloIndex,
    a5: 0,
    a6: LODWORD(life),
    a7: LODWORD(width),
    a8: LODWORD(endWidth),
    a9: LODWORD(fadeLength),
    a10: LODWORD(r),
    a11: LODWORD(g),
    a12: LODWORD(b),
    a13: LODWORD(a));
}

//------------------------------------------------------------------------------
// Address: 0x1042B2B0
// Name: DT_TEBeamFollow::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEBeamFollow::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_TEBeamFollow::g_RecvTable);
  return atexit(func: DT_TEBeamFollow::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042B2D0
// Name: DT_TEBeamFollow::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEBeamFollow::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_TEBeamFollow::ignored>();
  DT_TEBeamFollow::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104367F0
// Name: DT_TEBeamFollow::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEBeamFollow::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_TEBeamFollow::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10254D50
// Name: _C_TEBeamFollow_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_TEBeamFollow_CreateObject()
{
  return &_g_C_TEBeamFollow.IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1042B2E0
// Name: _dynamic_initializer_for____g_C_TEBeamLaser__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____g_C_TEBeamLaser__()
{
  C_TEBaseBeam::C_TEBaseBeam(this: &_g_C_TEBeamLaser);
  _g_C_TEBeamLaser.C_TEBaseBeam::C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEBeamLaser_vtbl *)&C_TEBeamLaser::`vftable'{for `IClientUnknown'};
  _g_C_TEBeamLaser.C_TEBaseBeam::C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEBeamLaser::`vftable'{for `IClientNetworkable'};
  _g_C_TEBeamLaser.m_nStartEntity = 0;
  _g_C_TEBeamLaser.m_nEndEntity = 0;
  return atexit(func: dynamic_atexit_destructor_for____g_C_TEBeamLaser__);
}

//------------------------------------------------------------------------------
// Address: 0x1042B320
// Name: _dynamic_initializer_for____g_C_TEBeamLaserClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_TEBeamLaserClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_TEBeamLaserClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_TEBeamLaserClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436800
// Name: _dynamic_atexit_destructor_for____g_C_TEBeamLaser__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____g_C_TEBeamLaser__()
{
  _g_C_TEBeamLaser.C_TEBaseBeam::C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEBeamLaser_vtbl *)&C_TEBeamLaser::`vftable'{for `IClientUnknown'};
  _g_C_TEBeamLaser.C_TEBaseBeam::C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEBeamLaser::`vftable'{for `IClientNetworkable'};
  C_TEBaseBeam::~C_TEBaseBeam(this: &_g_C_TEBeamLaser);
}
