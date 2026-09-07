// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/te_beamringpoint.cpp
// Functions: 10
// ============================================================

#include "game\server\te_beamringpoint.h"

//------------------------------------------------------------------------------
// Address: 0x1032D950
// Name: public: virtual class ServerClass __near * CTEBeamRingPoint::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CTEBeamRingPoint::GetServerClass(CTEBeamRingPoint *this)
{
  return &g_CTEBeamRingPoint_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x1032DAD0
// Name: public: virtual void CTEBeamRingPoint::Test(class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTEBeamRingPoint::Test(
        CTEBeamRingPoint *this,
        CNetworkVectorBase<Vector,CTEBeamRingPoint::NetworkVar_m_vecCenter> *current_origin,
        const QAngle *current_angles)
{
  CBroadcastRecipientFilter filter; // [esp+8h] [ebp-20h] BYREF

  if ( current_origin->m_Value.x != this->m_vecCenter.m_Value.x
    || current_origin->m_Value.y != this->m_vecCenter.m_Value.y
    || current_origin->m_Value.z != this->m_vecCenter.m_Value.z )
  {
    this->m_vecCenter = *current_origin;
  }
  if ( this->m_flEndRadius.m_Value != 256.0 )
    this->m_flEndRadius.m_Value = 256.0;
  if ( this->m_flStartRadius.m_Value != 16.0 )
    this->m_flStartRadius.m_Value = 16.0;
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
  ((void (__thiscall *)(CTEBeamRingPoint *, CBroadcastRecipientFilter *, _DWORD))this->Create)(
    a1: this,
    a2: &filter,
    a3: 0);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x1032DC40
// Name: void TE_BeamRingPoint(class IRecipientFilter __near &,float,class Vector const __near &,float,float,int,int,int,int,float,float,int,float,int,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_BeamRingPoint(
        IRecipientFilter *filter,
        float delay,
        CNetworkVectorBase<Vector,CTEBeamRingPoint::NetworkVar_m_vecCenter> *center,
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
  if ( center->m_Value.x != g_TEBeamRingPoint.m_vecCenter.m_Value.x
    || center->m_Value.y != g_TEBeamRingPoint.m_vecCenter.m_Value.y
    || center->m_Value.z != g_TEBeamRingPoint.m_vecCenter.m_Value.z )
  {
    g_TEBeamRingPoint.m_vecCenter = *center;
  }
  if ( g_TEBeamRingPoint.m_flStartRadius.m_Value != start_radius )
    g_TEBeamRingPoint.m_flStartRadius.m_Value = start_radius;
  if ( g_TEBeamRingPoint.m_flEndRadius.m_Value != end_radius )
    g_TEBeamRingPoint.m_flEndRadius.m_Value = end_radius;
  if ( g_TEBeamRingPoint.m_nModelIndex.m_Value != modelindex )
    g_TEBeamRingPoint.m_nModelIndex.m_Value = modelindex;
  if ( g_TEBeamRingPoint.m_nHaloIndex.m_Value != haloindex )
    g_TEBeamRingPoint.m_nHaloIndex.m_Value = haloindex;
  if ( g_TEBeamRingPoint.m_nStartFrame.m_Value != startframe )
    g_TEBeamRingPoint.m_nStartFrame.m_Value = startframe;
  if ( g_TEBeamRingPoint.m_nFrameRate.m_Value != framerate )
    g_TEBeamRingPoint.m_nFrameRate.m_Value = framerate;
  if ( g_TEBeamRingPoint.m_fLife.m_Value != life )
    g_TEBeamRingPoint.m_fLife.m_Value = life;
  if ( g_TEBeamRingPoint.m_fWidth.m_Value != width )
    g_TEBeamRingPoint.m_fWidth.m_Value = width;
  if ( g_TEBeamRingPoint.m_fEndWidth.m_Value != width )
    g_TEBeamRingPoint.m_fEndWidth.m_Value = width;
  if ( g_TEBeamRingPoint.m_nFadeLength.m_Value != 0 )
    g_TEBeamRingPoint.m_nFadeLength.m_Value = 0;
  if ( g_TEBeamRingPoint.m_fAmplitude.m_Value != amplitude )
    g_TEBeamRingPoint.m_fAmplitude.m_Value = amplitude;
  if ( g_TEBeamRingPoint.m_nSpeed.m_Value != speed )
    g_TEBeamRingPoint.m_nSpeed.m_Value = speed;
  if ( g_TEBeamRingPoint.r.m_Value != r )
    g_TEBeamRingPoint.r.m_Value = r;
  if ( g_TEBeamRingPoint.g.m_Value != g )
    g_TEBeamRingPoint.g.m_Value = g;
  if ( g_TEBeamRingPoint.b.m_Value != b )
    g_TEBeamRingPoint.b.m_Value = b;
  if ( g_TEBeamRingPoint.a.m_Value != a )
    g_TEBeamRingPoint.a.m_Value = a;
  if ( g_TEBeamRingPoint.m_nFlags.m_Value != flags )
    g_TEBeamRingPoint.m_nFlags.m_Value = flags;
  CBaseTempEntity::Create(this: &g_TEBeamRingPoint, filter, delay);
}

//------------------------------------------------------------------------------
// Address: 0x10416090
// Name: DT_TEBeamRingPoint::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEBeamRingPoint::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_TEBeamRingPoint::g_SendTable);
  return atexit(func: DT_TEBeamRingPoint::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104160B0
// Name: DT_TEBeamRingPoint::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEBeamRingPoint::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_TEBeamRingPoint::ignored>();
  DT_TEBeamRingPoint::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10422050
// Name: DT_TEBeamRingPoint::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEBeamRingPoint::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_TEBeamRingPoint::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x104160C0
// Name: _dynamic_initializer_for__g_TEBeamRingPoint__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TEBeamRingPoint__()
{
  CTEBaseBeam::CTEBaseBeam(this: &g_TEBeamRingPoint, name: "BeamRingPoint");
  g_TEBeamRingPoint.__vftable = (CTEBeamRingPoint_vtbl *)&CTEBeamRingPoint::`vftable';
  if ( g_TEBeamRingPoint.m_vecCenter.m_Value.x != 0.0
    || g_TEBeamRingPoint.m_vecCenter.m_Value.y != 0.0
    || g_TEBeamRingPoint.m_vecCenter.m_Value.z != 0.0 )
  {
    g_TEBeamRingPoint.m_vecCenter.m_Value.x = 0.0;
    g_TEBeamRingPoint.m_vecCenter.m_Value.y = 0.0;
    g_TEBeamRingPoint.m_vecCenter.m_Value.z = 0.0;
  }
  if ( g_TEBeamRingPoint.m_flStartRadius.m_Value != 0.0 )
    g_TEBeamRingPoint.m_flStartRadius.m_Value = 0.0;
  if ( g_TEBeamRingPoint.m_flEndRadius.m_Value != 0.0 )
    g_TEBeamRingPoint.m_flEndRadius.m_Value = 0.0;
  return atexit(func: dynamic_atexit_destructor_for__g_TEBeamRingPoint__);
}

//------------------------------------------------------------------------------
// Address: 0x10416160
// Name: _dynamic_initializer_for__g_CTEBeamSpline_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CTEBeamSpline_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CTEBeamSpline_ClassReg,
           pNetworkName: "CTEBeamSpline",
           pTable: &DT_TEBeamSpline::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10422060
// Name: _dynamic_atexit_destructor_for__g_TEBeamRingPoint__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TEBeamRingPoint__()
{
  g_TEBeamRingPoint.__vftable = (CTEBeamRingPoint_vtbl *)&CTEBeamRingPoint::`vftable';
  CTEBaseBeam::~CTEBaseBeam(this: &g_TEBeamRingPoint);
}

//------------------------------------------------------------------------------
// Address: 0x10422080
// Name: _ServerClassInit_DT_TEBeamRingPoint::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_TEBeamRingPoint::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_329;
  for ( i = 4; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}
