// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/te_beamentpoint.cpp
// Functions: 10
// ============================================================

#include "game\server\te_beamentpoint.h"

//------------------------------------------------------------------------------
// Address: 0x1032C290
// Name: public: virtual class ServerClass __near * CTEBeamEntPoint::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CTEBeamEntPoint::GetServerClass(CTEBeamEntPoint *this)
{
  return &g_CTEBeamEntPoint_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x1032C410
// Name: public: virtual void CTEBeamEntPoint::Test(class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTEBeamEntPoint::Test(
        CTEBeamEntPoint *this,
        CNetworkVectorBase<Vector,CTEBeamEntPoint::NetworkVar_m_vecEndPoint> *current_origin,
        const QAngle *current_angles)
{
  float y; // xmm2_4
  float v5; // xmm0_4
  CBroadcastRecipientFilter filter; // [esp+8h] [ebp-38h] BYREF
  Vector right; // [esp+28h] [ebp-18h] BYREF
  Vector forward; // [esp+34h] [ebp-Ch] BYREF

  if ( this->m_nStartEntity.m_Value != 1 )
    this->m_nStartEntity.m_Value = 1;
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
  if ( current_origin->m_Value.x != this->m_vecEndPoint.m_Value.x
    || current_origin->m_Value.y != this->m_vecEndPoint.m_Value.y
    || current_origin->m_Value.z != this->m_vecEndPoint.m_Value.z )
  {
    this->m_vecEndPoint = *current_origin;
  }
  y = this->m_vecEndPoint.m_Value.y;
  v5 = this->m_vecEndPoint.m_Value.z + 24.0;
  if ( v5 != this->m_vecEndPoint.m_Value.z )
  {
    this->m_vecEndPoint.m_Value.x = this->m_vecEndPoint.m_Value.x;
    this->m_vecEndPoint.m_Value.y = y;
    this->m_vecEndPoint.m_Value.z = v5;
  }
  AngleVectors(angles: current_angles, &forward, &right, up: nullptr);
  forward.z = 0.0;
  VectorNormalize(vec: &forward);
  this->m_vecEndPoint.m_Value.x = (float)(forward.x * 50.0) + this->m_vecEndPoint.m_Value.x;
  this->m_vecEndPoint.m_Value.y = (float)(forward.y * 50.0) + this->m_vecEndPoint.m_Value.y;
  this->m_vecEndPoint.m_Value.z = (float)(forward.z * 50.0) + this->m_vecEndPoint.m_Value.z;
  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CBroadcastRecipientFilter_vtbl *)&CBroadcastRecipientFilter::`vftable';
  CRecipientFilter::AddAllPlayers(this: &filter);
  ((void (__thiscall *)(CTEBeamEntPoint *, CBroadcastRecipientFilter *, _DWORD))this->Create)(
    a1: this,
    a2: &filter,
    a3: 0);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x1032C600
// Name: void TE_BeamEntPoint(class IRecipientFilter __near &,float,int,class Vector const __near *,int,class Vector const __near *,int,int,int,int,float,float,float,int,float,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_BeamEntPoint(
        IRecipientFilter *filter,
        float delay,
        int nStartEntity,
        CNetworkVectorBase<Vector,CTEBeamEntPoint::NetworkVar_m_vecStartPoint> *start,
        int nEndEntity,
        CNetworkVectorBase<Vector,CTEBeamEntPoint::NetworkVar_m_vecEndPoint> *end,
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
  int v20; // eax
  int v21; // eax
  CNetworkVectorBase<Vector,CTEBeamEntPoint::NetworkVar_m_vecStartPoint> *v22; // ecx
  CNetworkVectorBase<Vector,CTEBeamEntPoint::NetworkVar_m_vecEndPoint> *v23; // ecx

  if ( nStartEntity <= 0 )
    v20 = 0;
  else
    v20 = nStartEntity & 0xFFF | 0x1000;
  if ( g_TEBeamEntPoint.m_nStartEntity.m_Value != v20 )
    g_TEBeamEntPoint.m_nStartEntity.m_Value = v20;
  if ( nEndEntity <= 0 )
    v21 = 0;
  else
    v21 = nEndEntity & 0xFFF | 0x1000;
  if ( g_TEBeamEntPoint.m_nEndEntity.m_Value != v21 )
    g_TEBeamEntPoint.m_nEndEntity.m_Value = v21;
  v22 = start;
  if ( start == nullptr )
    v22 = (CNetworkVectorBase<Vector,CTEBeamEntPoint::NetworkVar_m_vecStartPoint> *)&vec3_origin;
  if ( v22->m_Value.x != g_TEBeamEntPoint.m_vecStartPoint.m_Value.x
    || v22->m_Value.y != g_TEBeamEntPoint.m_vecStartPoint.m_Value.y
    || v22->m_Value.z != g_TEBeamEntPoint.m_vecStartPoint.m_Value.z )
  {
    g_TEBeamEntPoint.m_vecStartPoint = *v22;
  }
  v23 = end;
  if ( end == nullptr )
    v23 = (CNetworkVectorBase<Vector,CTEBeamEntPoint::NetworkVar_m_vecEndPoint> *)&vec3_origin;
  if ( v23->m_Value.x != g_TEBeamEntPoint.m_vecEndPoint.m_Value.x
    || v23->m_Value.y != g_TEBeamEntPoint.m_vecEndPoint.m_Value.y
    || v23->m_Value.z != g_TEBeamEntPoint.m_vecEndPoint.m_Value.z )
  {
    g_TEBeamEntPoint.m_vecEndPoint = *v23;
  }
  if ( g_TEBeamEntPoint.m_nModelIndex.m_Value != modelindex )
    g_TEBeamEntPoint.m_nModelIndex.m_Value = modelindex;
  if ( g_TEBeamEntPoint.m_nHaloIndex.m_Value != haloindex )
    g_TEBeamEntPoint.m_nHaloIndex.m_Value = haloindex;
  if ( g_TEBeamEntPoint.m_nStartFrame.m_Value != startframe )
    g_TEBeamEntPoint.m_nStartFrame.m_Value = startframe;
  if ( g_TEBeamEntPoint.m_nFrameRate.m_Value != framerate )
    g_TEBeamEntPoint.m_nFrameRate.m_Value = framerate;
  if ( g_TEBeamEntPoint.m_fLife.m_Value != life )
    g_TEBeamEntPoint.m_fLife.m_Value = life;
  if ( g_TEBeamEntPoint.m_fWidth.m_Value != width )
    g_TEBeamEntPoint.m_fWidth.m_Value = width;
  if ( g_TEBeamEntPoint.m_fEndWidth.m_Value != endWidth )
    g_TEBeamEntPoint.m_fEndWidth.m_Value = endWidth;
  if ( g_TEBeamEntPoint.m_nFadeLength.m_Value != fadeLength )
    g_TEBeamEntPoint.m_nFadeLength.m_Value = fadeLength;
  if ( g_TEBeamEntPoint.m_fAmplitude.m_Value != amplitude )
    g_TEBeamEntPoint.m_fAmplitude.m_Value = amplitude;
  if ( g_TEBeamEntPoint.m_nSpeed.m_Value != speed )
    g_TEBeamEntPoint.m_nSpeed.m_Value = speed;
  if ( g_TEBeamEntPoint.r.m_Value != r )
    g_TEBeamEntPoint.r.m_Value = r;
  if ( g_TEBeamEntPoint.g.m_Value != g )
    g_TEBeamEntPoint.g.m_Value = g;
  if ( g_TEBeamEntPoint.b.m_Value != b )
    g_TEBeamEntPoint.b.m_Value = b;
  if ( g_TEBeamEntPoint.a.m_Value != a )
    g_TEBeamEntPoint.a.m_Value = a;
  CBaseTempEntity::Create(this: &g_TEBeamEntPoint, filter, delay);
}

//------------------------------------------------------------------------------
// Address: 0x10415C00
// Name: DT_TEBeamEntPoint::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEBeamEntPoint::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_TEBeamEntPoint::g_SendTable);
  return atexit(func: DT_TEBeamEntPoint::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10415C20
// Name: DT_TEBeamEntPoint::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEBeamEntPoint::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_TEBeamEntPoint::ignored>();
  DT_TEBeamEntPoint::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421E70
// Name: DT_TEBeamEntPoint::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEBeamEntPoint::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_TEBeamEntPoint::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10415C30
// Name: _dynamic_initializer_for__g_TEBeamEntPoint__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TEBeamEntPoint__()
{
  CTEBaseBeam::CTEBaseBeam(this: &g_TEBeamEntPoint, name: "BeamEntPoint");
  g_TEBeamEntPoint.__vftable = (CTEBeamEntPoint_vtbl *)&CTEBeamEntPoint::`vftable';
  if ( g_TEBeamEntPoint.m_nStartEntity.m_Value != 0 )
    g_TEBeamEntPoint.m_nStartEntity.m_Value = 0;
  if ( g_TEBeamEntPoint.m_nEndEntity.m_Value != 0 )
    g_TEBeamEntPoint.m_nEndEntity.m_Value = 0;
  if ( g_TEBeamEntPoint.m_vecStartPoint.m_Value.x != 0.0
    || g_TEBeamEntPoint.m_vecStartPoint.m_Value.y != 0.0
    || g_TEBeamEntPoint.m_vecStartPoint.m_Value.z != 0.0 )
  {
    g_TEBeamEntPoint.m_vecStartPoint.m_Value.x = 0.0;
    g_TEBeamEntPoint.m_vecStartPoint.m_Value.y = 0.0;
    g_TEBeamEntPoint.m_vecStartPoint.m_Value.z = 0.0;
  }
  if ( g_TEBeamEntPoint.m_vecEndPoint.m_Value.x != 0.0
    || g_TEBeamEntPoint.m_vecEndPoint.m_Value.y != 0.0
    || g_TEBeamEntPoint.m_vecEndPoint.m_Value.z != 0.0 )
  {
    g_TEBeamEntPoint.m_vecEndPoint.m_Value.x = 0.0;
    g_TEBeamEntPoint.m_vecEndPoint.m_Value.y = 0.0;
    g_TEBeamEntPoint.m_vecEndPoint.m_Value.z = 0.0;
  }
  return atexit(func: dynamic_atexit_destructor_for__g_TEBeamEntPoint__);
}

//------------------------------------------------------------------------------
// Address: 0x10415D00
// Name: _dynamic_initializer_for__g_CTEBeamEnts_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CTEBeamEnts_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CTEBeamEnts_ClassReg,
           pNetworkName: "CTEBeamEnts",
           pTable: &DT_TEBeamEnts::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10421E80
// Name: _dynamic_atexit_destructor_for__g_TEBeamEntPoint__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TEBeamEntPoint__()
{
  g_TEBeamEntPoint.__vftable = (CTEBeamEntPoint_vtbl *)&CTEBeamEntPoint::`vftable';
  CTEBaseBeam::~CTEBaseBeam(this: &g_TEBeamEntPoint);
}

//------------------------------------------------------------------------------
// Address: 0x10421EA0
// Name: _ServerClassInit_DT_TEBeamEntPoint::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_TEBeamEntPoint::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_323;
  for ( i = 5; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}
