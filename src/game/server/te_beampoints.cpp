// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/te_beampoints.cpp
// Functions: 10
// ============================================================

#include "game\server\te_beampoints.h"

//------------------------------------------------------------------------------
// Address: 0x1032D040
// Name: public: virtual class ServerClass __near * CTEBeamPoints::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CTEBeamPoints::GetServerClass(CTEBeamPoints *this)
{
  return &g_CTEBeamPoints_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x1032D180
// Name: public: virtual void CTEBeamPoints::Test(class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTEBeamPoints::Test(
        CTEBeamPoints *this,
        CNetworkVectorBase<Vector,CTEBeamPoints::NetworkVar_m_vecStartPoint> *current_origin,
        const QAngle *current_angles)
{
  float y; // xmm2_4
  float v5; // xmm0_4
  float x; // xmm0_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  CBroadcastRecipientFilter filter; // [esp+8h] [ebp-38h] BYREF
  Vector right; // [esp+28h] [ebp-18h] BYREF
  Vector forward; // [esp+34h] [ebp-Ch] BYREF

  if ( this->m_nModelIndex.m_Value != g_sModelIndexSmoke )
    this->m_nModelIndex.m_Value = g_sModelIndexSmoke;
  if ( this->m_nStartFrame.m_Value != 0 )
    this->m_nStartFrame.m_Value = 0;
  if ( this->m_nFrameRate.m_Value != 10 )
    this->m_nFrameRate.m_Value = 10;
  if ( this->m_fLife.m_Value != 2.0 )
    this->m_fLife.m_Value = 2.0;
  if ( this->m_fWidth.m_Value != 1.0 )
    this->m_fWidth.m_Value = 1.0;
  if ( this->m_fAmplitude.m_Value != 1.0 )
    this->m_fAmplitude.m_Value = 1.0;
  if ( this->r.m_Value != 0 )
    this->r.m_Value = 0;
  if ( this->g.m_Value != 63 )
    this->g.m_Value = 63;
  if ( this->b.m_Value != 127 )
    this->b.m_Value = 127;
  if ( this->a.m_Value != 150 )
    this->a.m_Value = 150;
  if ( this->m_nSpeed.m_Value != 1 )
    this->m_nSpeed.m_Value = 1;
  if ( current_origin->m_Value.x != this->m_vecStartPoint.m_Value.x
    || current_origin->m_Value.y != this->m_vecStartPoint.m_Value.y
    || current_origin->m_Value.z != this->m_vecStartPoint.m_Value.z )
  {
    this->m_vecStartPoint = *current_origin;
  }
  y = this->m_vecStartPoint.m_Value.y;
  v5 = this->m_vecStartPoint.m_Value.z + 30.0;
  if ( v5 != this->m_vecStartPoint.m_Value.z )
  {
    this->m_vecStartPoint.m_Value.x = this->m_vecStartPoint.m_Value.x;
    this->m_vecStartPoint.m_Value.y = y;
    this->m_vecStartPoint.m_Value.z = v5;
  }
  AngleVectors(angles: current_angles, &forward, &right, up: nullptr);
  forward.z = 0.0;
  VectorNormalize(vec: &forward);
  this->m_vecStartPoint.m_Value.x = (float)(forward.x * 75.0) + this->m_vecStartPoint.m_Value.x;
  this->m_vecStartPoint.m_Value.y = (float)(forward.y * 75.0) + this->m_vecStartPoint.m_Value.y;
  x = right.x;
  this->m_vecStartPoint.m_Value.z = (float)(forward.z * 75.0) + this->m_vecStartPoint.m_Value.z;
  v7 = x * 25.0;
  this->m_vecEndPoint.m_Value.x = v7 + this->m_vecStartPoint.m_Value.x;
  v8 = right.y * 25.0;
  this->m_vecEndPoint.m_Value.y = (float)(right.y * 25.0) + this->m_vecStartPoint.m_Value.y;
  v9 = right.z * 25.0;
  this->m_vecEndPoint.m_Value.z = (float)(right.z * 25.0) + this->m_vecStartPoint.m_Value.z;
  this->m_vecStartPoint.m_Value.x = this->m_vecStartPoint.m_Value.x - v7;
  this->m_vecStartPoint.m_Value.y = this->m_vecStartPoint.m_Value.y - v8;
  this->m_vecStartPoint.m_Value.z = this->m_vecStartPoint.m_Value.z - v9;
  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CBroadcastRecipientFilter_vtbl *)&CBroadcastRecipientFilter::`vftable';
  CRecipientFilter::AddAllPlayers(this: &filter);
  ((void (__thiscall *)(CTEBeamPoints *, CBroadcastRecipientFilter *, _DWORD))this->Create)(
    a1: this,
    a2: &filter,
    a3: 0);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x1032D3D0
// Name: void TE_BeamPoints(class IRecipientFilter __near &,float,class Vector const __near *,class Vector const __near *,int,int,int,int,float,float,float,int,float,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_BeamPoints(
        IRecipientFilter *filter,
        float delay,
        CNetworkVectorBase<Vector,CTEBeamPoints::NetworkVar_m_vecStartPoint> *start,
        CNetworkVectorBase<Vector,CTEBeamPoints::NetworkVar_m_vecEndPoint> *end,
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
  if ( start->m_Value.x != g_TEBeamPoints.m_vecStartPoint.m_Value.x
    || start->m_Value.y != g_TEBeamPoints.m_vecStartPoint.m_Value.y
    || start->m_Value.z != g_TEBeamPoints.m_vecStartPoint.m_Value.z )
  {
    g_TEBeamPoints.m_vecStartPoint = *start;
  }
  if ( end->m_Value.x != g_TEBeamPoints.m_vecEndPoint.m_Value.x
    || end->m_Value.y != g_TEBeamPoints.m_vecEndPoint.m_Value.y
    || end->m_Value.z != g_TEBeamPoints.m_vecEndPoint.m_Value.z )
  {
    g_TEBeamPoints.m_vecEndPoint = *end;
  }
  if ( g_TEBeamPoints.m_nModelIndex.m_Value != modelindex )
    g_TEBeamPoints.m_nModelIndex.m_Value = modelindex;
  if ( g_TEBeamPoints.m_nHaloIndex.m_Value != haloindex )
    g_TEBeamPoints.m_nHaloIndex.m_Value = haloindex;
  if ( g_TEBeamPoints.m_nStartFrame.m_Value != startframe )
    g_TEBeamPoints.m_nStartFrame.m_Value = startframe;
  if ( g_TEBeamPoints.m_nFrameRate.m_Value != framerate )
    g_TEBeamPoints.m_nFrameRate.m_Value = framerate;
  if ( g_TEBeamPoints.m_fLife.m_Value != life )
    g_TEBeamPoints.m_fLife.m_Value = life;
  if ( g_TEBeamPoints.m_fWidth.m_Value != width )
    g_TEBeamPoints.m_fWidth.m_Value = width;
  if ( g_TEBeamPoints.m_fEndWidth.m_Value != endWidth )
    g_TEBeamPoints.m_fEndWidth.m_Value = endWidth;
  if ( g_TEBeamPoints.m_nFadeLength.m_Value != fadeLength )
    g_TEBeamPoints.m_nFadeLength.m_Value = fadeLength;
  if ( g_TEBeamPoints.m_fAmplitude.m_Value != amplitude )
    g_TEBeamPoints.m_fAmplitude.m_Value = amplitude;
  if ( g_TEBeamPoints.m_nSpeed.m_Value != speed )
    g_TEBeamPoints.m_nSpeed.m_Value = speed;
  if ( g_TEBeamPoints.r.m_Value != r )
    g_TEBeamPoints.r.m_Value = r;
  if ( g_TEBeamPoints.g.m_Value != g )
    g_TEBeamPoints.g.m_Value = g;
  if ( g_TEBeamPoints.b.m_Value != b )
    g_TEBeamPoints.b.m_Value = b;
  if ( g_TEBeamPoints.a.m_Value != a )
    g_TEBeamPoints.a.m_Value = a;
  CBaseTempEntity::Create(this: &g_TEBeamPoints, filter, delay);
}

//------------------------------------------------------------------------------
// Address: 0x10415EF0
// Name: DT_TEBeamPoints::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEBeamPoints::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_TEBeamPoints::g_SendTable);
  return atexit(func: DT_TEBeamPoints::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10415F10
// Name: DT_TEBeamPoints::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEBeamPoints::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_TEBeamPoints::ignored>();
  DT_TEBeamPoints::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421FB0
// Name: DT_TEBeamPoints::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEBeamPoints::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_TEBeamPoints::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10415F20
// Name: _dynamic_initializer_for__g_TEBeamPoints__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TEBeamPoints__()
{
  CTEBaseBeam::CTEBaseBeam(this: &g_TEBeamPoints, name: "BeamPoints");
  g_TEBeamPoints.__vftable = (CTEBeamPoints_vtbl *)&CTEBeamPoints::`vftable';
  if ( g_TEBeamPoints.m_vecStartPoint.m_Value.x != 0.0
    || g_TEBeamPoints.m_vecStartPoint.m_Value.y != 0.0
    || g_TEBeamPoints.m_vecStartPoint.m_Value.z != 0.0 )
  {
    g_TEBeamPoints.m_vecStartPoint.m_Value.x = 0.0;
    g_TEBeamPoints.m_vecStartPoint.m_Value.y = 0.0;
    g_TEBeamPoints.m_vecStartPoint.m_Value.z = 0.0;
  }
  if ( g_TEBeamPoints.m_vecEndPoint.m_Value.x != 0.0
    || g_TEBeamPoints.m_vecEndPoint.m_Value.y != 0.0
    || g_TEBeamPoints.m_vecEndPoint.m_Value.z != 0.0 )
  {
    g_TEBeamPoints.m_vecEndPoint.m_Value.x = 0.0;
    g_TEBeamPoints.m_vecEndPoint.m_Value.y = 0.0;
    g_TEBeamPoints.m_vecEndPoint.m_Value.z = 0.0;
  }
  return atexit(func: dynamic_atexit_destructor_for__g_TEBeamPoints__);
}

//------------------------------------------------------------------------------
// Address: 0x10415FD0
// Name: _dynamic_initializer_for__g_CTEBeamRing_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CTEBeamRing_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CTEBeamRing_ClassReg,
           pNetworkName: "CTEBeamRing",
           pTable: &DT_TEBeamRing::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10421FC0
// Name: _dynamic_atexit_destructor_for__g_TEBeamPoints__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TEBeamPoints__()
{
  g_TEBeamPoints.__vftable = (CTEBeamPoints_vtbl *)&CTEBeamPoints::`vftable';
  CTEBaseBeam::~CTEBaseBeam(this: &g_TEBeamPoints);
}

//------------------------------------------------------------------------------
// Address: 0x10421FE0
// Name: _ServerClassInit_DT_TEBeamPoints::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_TEBeamPoints::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_327;
  for ( i = 3; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}
