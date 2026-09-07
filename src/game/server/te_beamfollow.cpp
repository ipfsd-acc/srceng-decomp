// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/te_beamfollow.cpp
// Functions: 10
// ============================================================

#include "game\server\te_beamfollow.h"

//------------------------------------------------------------------------------
// Address: 0x1032CAB0
// Name: public: virtual class ServerClass __near * CTEBeamFollow::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CTEBeamFollow::GetServerClass(CTEBeamFollow *this)
{
  return &g_CTEBeamFollow_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x1032CB90
// Name: public: virtual void CTEBeamFollow::Test(class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTEBeamFollow::Test(CTEBeamFollow *this, const Vector *current_origin, const Vector *current_angles)
{
  if ( this->m_iEntIndex.m_Value != 1 )
    this->m_iEntIndex.m_Value = 1;
}

//------------------------------------------------------------------------------
// Address: 0x1032CBA0
// Name: void TE_BeamFollow(class IRecipientFilter __near &,float,int,int,int,float,float,float,float,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_BeamFollow(
        IRecipientFilter *filter,
        float delay,
        __int16 iEntIndex,
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
  if ( g_TEBeamFollow.m_iEntIndex.m_Value != (iEntIndex & 0xFFF | 0x1000) )
    g_TEBeamFollow.m_iEntIndex.m_Value = iEntIndex & 0xFFF | 0x1000;
  if ( g_TEBeamFollow.m_nModelIndex.m_Value != modelIndex )
    g_TEBeamFollow.m_nModelIndex.m_Value = modelIndex;
  if ( g_TEBeamFollow.m_nHaloIndex.m_Value != haloIndex )
    g_TEBeamFollow.m_nHaloIndex.m_Value = haloIndex;
  if ( g_TEBeamFollow.m_nStartFrame.m_Value != 0 )
    g_TEBeamFollow.m_nStartFrame.m_Value = 0;
  if ( g_TEBeamFollow.m_nFrameRate.m_Value != 0 )
    g_TEBeamFollow.m_nFrameRate.m_Value = 0;
  if ( g_TEBeamFollow.m_fLife.m_Value != life )
    g_TEBeamFollow.m_fLife.m_Value = life;
  if ( g_TEBeamFollow.m_fWidth.m_Value != width )
    g_TEBeamFollow.m_fWidth.m_Value = width;
  if ( g_TEBeamFollow.m_fEndWidth.m_Value != endWidth )
    g_TEBeamFollow.m_fEndWidth.m_Value = endWidth;
  if ( g_TEBeamFollow.m_nFadeLength.m_Value != (int)fadeLength )
    g_TEBeamFollow.m_nFadeLength.m_Value = (int)fadeLength;
  if ( g_TEBeamFollow.r.m_Value != (int)r )
    g_TEBeamFollow.r.m_Value = (int)r;
  if ( g_TEBeamFollow.g.m_Value != (int)g )
    g_TEBeamFollow.g.m_Value = (int)g;
  if ( g_TEBeamFollow.b.m_Value != (int)b )
    g_TEBeamFollow.b.m_Value = (int)b;
  if ( g_TEBeamFollow.a.m_Value != (int)a )
    g_TEBeamFollow.a.m_Value = (int)a;
  CBaseTempEntity::Create(this: &g_TEBeamFollow, filter, delay);
}

//------------------------------------------------------------------------------
// Address: 0x10415DC0
// Name: DT_TEBeamFollow::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEBeamFollow::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_TEBeamFollow::g_SendTable);
  return atexit(func: DT_TEBeamFollow::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10415DE0
// Name: DT_TEBeamFollow::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEBeamFollow::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_TEBeamFollow::ignored>();
  DT_TEBeamFollow::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421F10
// Name: DT_TEBeamFollow::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEBeamFollow::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_TEBeamFollow::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10415DF0
// Name: _dynamic_initializer_for__g_TEBeamFollow__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TEBeamFollow__()
{
  CTEBaseBeam::CTEBaseBeam(this: &g_TEBeamFollow, name: "BeamFollow");
  g_TEBeamFollow.__vftable = (CTEBeamFollow_vtbl *)&CTEBeamFollow::`vftable';
  if ( g_TEBeamFollow.m_iEntIndex.m_Value != -1 )
    g_TEBeamFollow.m_iEntIndex.m_Value = -1;
  return atexit(func: dynamic_atexit_destructor_for__g_TEBeamFollow__);
}

//------------------------------------------------------------------------------
// Address: 0x10415E30
// Name: _dynamic_initializer_for__g_CTEBeamLaser_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CTEBeamLaser_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CTEBeamLaser_ClassReg,
           pNetworkName: "CTEBeamLaser",
           pTable: &DT_TEBeamLaser::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10421F20
// Name: _dynamic_atexit_destructor_for__g_TEBeamFollow__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TEBeamFollow__()
{
  g_TEBeamFollow.__vftable = (CTEBeamFollow_vtbl *)&CTEBeamFollow::`vftable';
  CTEBaseBeam::~CTEBaseBeam(this: &g_TEBeamFollow);
}

//------------------------------------------------------------------------------
// Address: 0x10421F40
// Name: _ServerClassInit_DT_TEBeamFollow::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_TEBeamFollow::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_325;
  for ( i = 2; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}
