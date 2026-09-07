// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/te_beaments.cpp
// Functions: 10
// ============================================================

#include "game\server\te_beaments.h"

//------------------------------------------------------------------------------
// Address: 0x1032C840
// Name: public: virtual class ServerClass __near * CTEBeamEnts::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CTEBeamEnts::GetServerClass(CTEBeamEnts *this)
{
  return &g_CTEBeamEnts_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x1032C940
// Name: void TE_BeamEnts(class IRecipientFilter __near &,float,int,int,int,int,int,int,float,float,float,int,float,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_BeamEnts(
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
        float endWidth,
        int fadeLength,
        float amplitude,
        int r,
        int g,
        int b,
        int a,
        int speed)
{
  if ( g_TEBeamEnts.m_nStartEntity.m_Value != (start & 0xFFF | 0x1000) )
    g_TEBeamEnts.m_nStartEntity.m_Value = start & 0xFFF | 0x1000;
  if ( g_TEBeamEnts.m_nEndEntity.m_Value != (end & 0xFFF | 0x1000) )
    g_TEBeamEnts.m_nEndEntity.m_Value = end & 0xFFF | 0x1000;
  if ( g_TEBeamEnts.m_nModelIndex.m_Value != modelindex )
    g_TEBeamEnts.m_nModelIndex.m_Value = modelindex;
  if ( g_TEBeamEnts.m_nHaloIndex.m_Value != haloindex )
    g_TEBeamEnts.m_nHaloIndex.m_Value = haloindex;
  if ( g_TEBeamEnts.m_nStartFrame.m_Value != startframe )
    g_TEBeamEnts.m_nStartFrame.m_Value = startframe;
  if ( g_TEBeamEnts.m_nFrameRate.m_Value != framerate )
    g_TEBeamEnts.m_nFrameRate.m_Value = framerate;
  if ( g_TEBeamEnts.m_fLife.m_Value != life )
    g_TEBeamEnts.m_fLife.m_Value = life;
  if ( g_TEBeamEnts.m_fWidth.m_Value != width )
    g_TEBeamEnts.m_fWidth.m_Value = width;
  if ( g_TEBeamEnts.m_fEndWidth.m_Value != endWidth )
    g_TEBeamEnts.m_fEndWidth.m_Value = endWidth;
  if ( g_TEBeamEnts.m_nFadeLength.m_Value != fadeLength )
    g_TEBeamEnts.m_nFadeLength.m_Value = fadeLength;
  if ( g_TEBeamEnts.m_fAmplitude.m_Value != amplitude )
    g_TEBeamEnts.m_fAmplitude.m_Value = amplitude;
  if ( g_TEBeamEnts.m_nSpeed.m_Value != speed )
    g_TEBeamEnts.m_nSpeed.m_Value = speed;
  if ( g_TEBeamEnts.r.m_Value != r )
    g_TEBeamEnts.r.m_Value = r;
  if ( g_TEBeamEnts.g.m_Value != g )
    g_TEBeamEnts.g.m_Value = g;
  if ( g_TEBeamEnts.b.m_Value != b )
    g_TEBeamEnts.b.m_Value = b;
  if ( g_TEBeamEnts.a.m_Value != a )
    g_TEBeamEnts.a.m_Value = a;
  CBaseTempEntity::Create(this: &g_TEBeamEnts, filter, delay);
}

//------------------------------------------------------------------------------
// Address: 0x1032CDD0
// Name: public: virtual void CTEBeamEnts::Test(class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTEBeamEnts::Test(CTEBeamEnts *this, const Vector *current_origin, const QAngle *current_angles)
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
  if ( this->m_nFrameRate.m_Value != 10 )
    this->m_nFrameRate.m_Value = 10;
  if ( this->m_fLife.m_Value != 2.0 )
    this->m_fLife.m_Value = 2.0;
  if ( this->m_fWidth.m_Value != 1.0 )
    this->m_fWidth.m_Value = 1.0;
  if ( this->m_fAmplitude.m_Value != 1.0 )
    this->m_fAmplitude.m_Value = 1.0;
  if ( this->r.m_Value != 127 )
    this->r.m_Value = 127;
  if ( this->g.m_Value != 63 )
    this->g.m_Value = 63;
  if ( this->b.m_Value != 0 )
    this->b.m_Value = 0;
  if ( this->a.m_Value != 150 )
    this->a.m_Value = 150;
  if ( this->m_nSpeed.m_Value != 1 )
    this->m_nSpeed.m_Value = 1;
  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CBroadcastRecipientFilter_vtbl *)&CBroadcastRecipientFilter::`vftable';
  CRecipientFilter::AddAllPlayers(this: &filter);
  ((void (__thiscall *)(CTEBeamEnts *, CBroadcastRecipientFilter *, _DWORD))this->Create)(a1: this, a2: &filter, a3: 0);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x10415D20
// Name: DT_TEBeamEnts::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEBeamEnts::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_TEBeamEnts::g_SendTable);
  return atexit(func: DT_TEBeamEnts::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10415D40
// Name: DT_TEBeamEnts::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEBeamEnts::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_TEBeamEnts::ignored>();
  DT_TEBeamEnts::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421EC0
// Name: DT_TEBeamEnts::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEBeamEnts::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_TEBeamEnts::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10415D50
// Name: _dynamic_initializer_for__g_TEBeamEnts__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TEBeamEnts__()
{
  CTEBaseBeam::CTEBaseBeam(this: &g_TEBeamEnts, name: "BeamEnts");
  g_TEBeamEnts.__vftable = (CTEBeamEnts_vtbl *)&CTEBeamEnts::`vftable';
  if ( g_TEBeamEnts.m_nStartEntity.m_Value != 0 )
    g_TEBeamEnts.m_nStartEntity.m_Value = 0;
  if ( g_TEBeamEnts.m_nEndEntity.m_Value != 0 )
    g_TEBeamEnts.m_nEndEntity.m_Value = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_TEBeamEnts__);
}

//------------------------------------------------------------------------------
// Address: 0x10415DA0
// Name: _dynamic_initializer_for__g_CTEBeamFollow_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CTEBeamFollow_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CTEBeamFollow_ClassReg,
           pNetworkName: "CTEBeamFollow",
           pTable: &DT_TEBeamFollow::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10421ED0
// Name: _dynamic_atexit_destructor_for__g_TEBeamEnts__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TEBeamEnts__()
{
  g_TEBeamEnts.__vftable = (CTEBeamEnts_vtbl *)&CTEBeamEnts::`vftable';
  CTEBaseBeam::~CTEBaseBeam(this: &g_TEBeamEnts);
}

//------------------------------------------------------------------------------
// Address: 0x10421EF0
// Name: _ServerClassInit_DT_TEBeamEnts::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_TEBeamEnts::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_324;
  for ( i = 3; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}
