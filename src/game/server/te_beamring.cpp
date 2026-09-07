// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/te_beamring.cpp
// Functions: 10
// ============================================================

#include "game\server\te_beamring.h"

//------------------------------------------------------------------------------
// Address: 0x1032D5C0
// Name: public: virtual class ServerClass __near * CTEBeamRing::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CTEBeamRing::GetServerClass(CTEBeamRing *this)
{
  return &g_CTEBeamRing_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x1032D6C0
// Name: public: virtual void CTEBeamRing::Test(class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTEBeamRing::Test(CTEBeamRing *this, const Vector *current_origin, const QAngle *current_angles)
{
  CBroadcastRecipientFilter filter; // [esp+8h] [ebp-20h] BYREF

  if ( this->m_nStartEntity.m_Value != 1 )
    this->m_nStartEntity.m_Value = 1;
  if ( this->m_nEndEntity.m_Value != 0 )
    this->m_nEndEntity.m_Value = 0;
  if ( this->m_nModelIndex.m_Value != g_sModelIndexSmoke )
    this->m_nModelIndex.m_Value = g_sModelIndexSmoke;
  if ( this->m_nStartFrame.m_Value != 0 )
    this->m_nStartFrame.m_Value = 0;
  if ( this->m_nFrameRate.m_Value != 2 )
    this->m_nFrameRate.m_Value = 2;
  if ( this->m_fLife.m_Value != 10.0 )
    this->m_fLife.m_Value = 10.0;
  if ( this->m_fWidth.m_Value != 2.0 )
    this->m_fWidth.m_Value = 2.0;
  if ( this->m_fAmplitude.m_Value != 1.0 )
    this->m_fAmplitude.m_Value = 1.0;
  if ( this->r.m_Value != 255 )
    this->r.m_Value = 255;
  if ( this->g.m_Value != 255 )
    this->g.m_Value = 255;
  if ( this->b.m_Value != 0 )
    this->b.m_Value = 0;
  if ( this->a.m_Value != 127 )
    this->a.m_Value = 127;
  if ( this->m_nSpeed.m_Value != 5 )
    this->m_nSpeed.m_Value = 5;
  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CBroadcastRecipientFilter_vtbl *)&CBroadcastRecipientFilter::`vftable';
  CRecipientFilter::AddAllPlayers(this: &filter);
  ((void (__thiscall *)(CTEBeamRing *, CBroadcastRecipientFilter *, _DWORD))this->Create)(a1: this, a2: &filter, a3: 0);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x1032D7D0
// Name: void TE_BeamRing(class IRecipientFilter __near &,float,int,int,int,int,int,int,float,float,int,float,int,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_BeamRing(
        IRecipientFilter *filter,
        float delay,
        __int16 start,
        __int16 end,
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
  if ( g_TEBeamRing.m_nStartEntity.m_Value != (start & 0xFFF | 0x1000) )
    g_TEBeamRing.m_nStartEntity.m_Value = start & 0xFFF | 0x1000;
  if ( g_TEBeamRing.m_nEndEntity.m_Value != (end & 0xFFF | 0x1000) )
    g_TEBeamRing.m_nEndEntity.m_Value = end & 0xFFF | 0x1000;
  if ( g_TEBeamRing.m_nModelIndex.m_Value != modelindex )
    g_TEBeamRing.m_nModelIndex.m_Value = modelindex;
  if ( g_TEBeamRing.m_nHaloIndex.m_Value != haloindex )
    g_TEBeamRing.m_nHaloIndex.m_Value = haloindex;
  if ( g_TEBeamRing.m_nStartFrame.m_Value != startframe )
    g_TEBeamRing.m_nStartFrame.m_Value = startframe;
  if ( g_TEBeamRing.m_nFrameRate.m_Value != framerate )
    g_TEBeamRing.m_nFrameRate.m_Value = framerate;
  if ( g_TEBeamRing.m_fLife.m_Value != life )
    g_TEBeamRing.m_fLife.m_Value = life;
  if ( g_TEBeamRing.m_fWidth.m_Value != width )
    g_TEBeamRing.m_fWidth.m_Value = width;
  if ( g_TEBeamRing.m_fEndWidth.m_Value != width )
    g_TEBeamRing.m_fEndWidth.m_Value = width;
  if ( g_TEBeamRing.m_nFadeLength.m_Value != 0 )
    g_TEBeamRing.m_nFadeLength.m_Value = 0;
  if ( g_TEBeamRing.m_fAmplitude.m_Value != amplitude )
    g_TEBeamRing.m_fAmplitude.m_Value = amplitude;
  if ( g_TEBeamRing.m_nSpeed.m_Value != speed )
    g_TEBeamRing.m_nSpeed.m_Value = speed;
  if ( g_TEBeamRing.r.m_Value != r )
    g_TEBeamRing.r.m_Value = r;
  if ( g_TEBeamRing.g.m_Value != g )
    g_TEBeamRing.g.m_Value = g;
  if ( g_TEBeamRing.b.m_Value != b )
    g_TEBeamRing.b.m_Value = b;
  if ( g_TEBeamRing.a.m_Value != a )
    g_TEBeamRing.a.m_Value = a;
  if ( g_TEBeamRing.m_nFlags.m_Value != flags )
    g_TEBeamRing.m_nFlags.m_Value = flags;
  CBaseTempEntity::Create(this: &g_TEBeamRing, filter, delay);
}

//------------------------------------------------------------------------------
// Address: 0x10415FF0
// Name: DT_TEBeamRing::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEBeamRing::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_TEBeamRing::g_SendTable);
  return atexit(func: DT_TEBeamRing::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10416010
// Name: DT_TEBeamRing::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEBeamRing::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_TEBeamRing::ignored>();
  DT_TEBeamRing::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10422000
// Name: DT_TEBeamRing::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEBeamRing::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_TEBeamRing::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10416020
// Name: _dynamic_initializer_for__g_TEBeamRing__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TEBeamRing__()
{
  CTEBaseBeam::CTEBaseBeam(this: &g_TEBeamRing, name: "BeamRing");
  g_TEBeamRing.__vftable = (CTEBeamRing_vtbl *)&CTEBeamRing::`vftable';
  if ( g_TEBeamRing.m_nStartEntity.m_Value != 0 )
    g_TEBeamRing.m_nStartEntity.m_Value = 0;
  if ( g_TEBeamRing.m_nEndEntity.m_Value != 0 )
    g_TEBeamRing.m_nEndEntity.m_Value = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_TEBeamRing__);
}

//------------------------------------------------------------------------------
// Address: 0x10416070
// Name: _dynamic_initializer_for__g_CTEBeamRingPoint_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CTEBeamRingPoint_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CTEBeamRingPoint_ClassReg,
           pNetworkName: "CTEBeamRingPoint",
           pTable: &DT_TEBeamRingPoint::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10422010
// Name: _dynamic_atexit_destructor_for__g_TEBeamRing__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TEBeamRing__()
{
  g_TEBeamRing.__vftable = (CTEBeamRing_vtbl *)&CTEBeamRing::`vftable';
  CTEBaseBeam::~CTEBaseBeam(this: &g_TEBeamRing);
}

//------------------------------------------------------------------------------
// Address: 0x10422030
// Name: _ServerClassInit_DT_TEBeamRing::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_TEBeamRing::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_328;
  for ( i = 3; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}
