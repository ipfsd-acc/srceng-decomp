// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/te_beamlaser.cpp
// Functions: 11
// ============================================================

#include "game\server\te_beamlaser.h"

//------------------------------------------------------------------------------
// Address: 0x1032CCD0
// Name: public: virtual class ServerClass __near * CTEBeamLaser::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CTEBeamLaser::GetServerClass(CTEBeamLaser *this)
{
  return &g_CTEBeamLaser_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x1032CED0
// Name: void TE_BeamLaser(class IRecipientFilter __near &,float,int,int,int,int,int,int,float,float,float,int,float,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_BeamLaser(
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
  if ( g_TEBeamLaser.m_nStartEntity.m_Value != (start & 0xFFF | 0x1000) )
    g_TEBeamLaser.m_nStartEntity.m_Value = start & 0xFFF | 0x1000;
  if ( g_TEBeamLaser.m_nEndEntity.m_Value != (end & 0xFFF | 0x1000) )
    g_TEBeamLaser.m_nEndEntity.m_Value = end & 0xFFF | 0x1000;
  if ( g_TEBeamLaser.m_nModelIndex.m_Value != modelindex )
    g_TEBeamLaser.m_nModelIndex.m_Value = modelindex;
  if ( g_TEBeamLaser.m_nHaloIndex.m_Value != haloindex )
    g_TEBeamLaser.m_nHaloIndex.m_Value = haloindex;
  if ( g_TEBeamLaser.m_nStartFrame.m_Value != startframe )
    g_TEBeamLaser.m_nStartFrame.m_Value = startframe;
  if ( g_TEBeamLaser.m_nFrameRate.m_Value != framerate )
    g_TEBeamLaser.m_nFrameRate.m_Value = framerate;
  if ( g_TEBeamLaser.m_fLife.m_Value != life )
    g_TEBeamLaser.m_fLife.m_Value = life;
  if ( g_TEBeamLaser.m_fWidth.m_Value != width )
    g_TEBeamLaser.m_fWidth.m_Value = width;
  if ( g_TEBeamLaser.m_fEndWidth.m_Value != endWidth )
    g_TEBeamLaser.m_fEndWidth.m_Value = endWidth;
  if ( g_TEBeamLaser.m_nFadeLength.m_Value != fadeLength )
    g_TEBeamLaser.m_nFadeLength.m_Value = fadeLength;
  if ( g_TEBeamLaser.m_fAmplitude.m_Value != amplitude )
    g_TEBeamLaser.m_fAmplitude.m_Value = amplitude;
  if ( g_TEBeamLaser.m_nSpeed.m_Value != speed )
    g_TEBeamLaser.m_nSpeed.m_Value = speed;
  if ( g_TEBeamLaser.r.m_Value != r )
    g_TEBeamLaser.r.m_Value = r;
  if ( g_TEBeamLaser.g.m_Value != g )
    g_TEBeamLaser.g.m_Value = g;
  if ( g_TEBeamLaser.b.m_Value != b )
    g_TEBeamLaser.b.m_Value = b;
  if ( g_TEBeamLaser.a.m_Value != a )
    g_TEBeamLaser.a.m_Value = a;
  CBaseTempEntity::Create(this: &g_TEBeamLaser, filter, delay);
}

//------------------------------------------------------------------------------
// Address: 0x104007F0
// Name: _dynamic_initializer_for__beam__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__beam__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CBeam> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &beam,
           a3: "beam");
}

//------------------------------------------------------------------------------
// Address: 0x10400850
// Name: _dynamic_initializer_for__beam_spotlight__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__beam_spotlight__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CBeamSpotlight> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &beam_spotlight,
           a3: "beam_spotlight");
}

//------------------------------------------------------------------------------
// Address: 0x10415E50
// Name: DT_TEBeamLaser::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEBeamLaser::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_TEBeamLaser::g_SendTable);
  return atexit(func: DT_TEBeamLaser::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10415E70
// Name: DT_TEBeamLaser::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEBeamLaser::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_TEBeamLaser::ignored>();
  DT_TEBeamLaser::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421F60
// Name: DT_TEBeamLaser::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEBeamLaser::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_TEBeamLaser::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10415E80
// Name: _dynamic_initializer_for__g_TEBeamLaser__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TEBeamLaser__()
{
  CTEBaseBeam::CTEBaseBeam(this: &g_TEBeamLaser, name: "BeamLaser");
  g_TEBeamLaser.__vftable = (CTEBeamLaser_vtbl *)&CTEBeamLaser::`vftable';
  if ( g_TEBeamLaser.m_nStartEntity.m_Value != 0 )
    g_TEBeamLaser.m_nStartEntity.m_Value = 0;
  if ( g_TEBeamLaser.m_nEndEntity.m_Value != 0 )
    g_TEBeamLaser.m_nEndEntity.m_Value = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_TEBeamLaser__);
}

//------------------------------------------------------------------------------
// Address: 0x10415ED0
// Name: _dynamic_initializer_for__g_CTEBeamPoints_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CTEBeamPoints_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CTEBeamPoints_ClassReg,
           pNetworkName: "CTEBeamPoints",
           pTable: &DT_TEBeamPoints::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10421F70
// Name: _dynamic_atexit_destructor_for__g_TEBeamLaser__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TEBeamLaser__()
{
  g_TEBeamLaser.__vftable = (CTEBeamLaser_vtbl *)&CTEBeamLaser::`vftable';
  CTEBaseBeam::~CTEBaseBeam(this: &g_TEBeamLaser);
}

//------------------------------------------------------------------------------
// Address: 0x10421F90
// Name: _ServerClassInit_DT_TEBeamLaser::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_TEBeamLaser::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_326;
  for ( i = 3; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}
