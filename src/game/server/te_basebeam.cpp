// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/te_basebeam.cpp
// Functions: 8
// ============================================================

#include "game\server\te_basebeam.h"

//------------------------------------------------------------------------------
// Address: 0x1032BEB0
// Name: public: virtual CTEBaseBeam::~CTEBaseBeam(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTEBaseBeam::~CTEBaseBeam(CTEBaseBeam *this)
{
  this->__vftable = (CTEBaseBeam_vtbl *)&CTEBaseBeam::`vftable';
  CBaseTempEntity::~CBaseTempEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x1032BEC0
// Name: public: virtual class ServerClass __near * CTEBaseBeam::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CTEBaseBeam::GetServerClass(CTEBaseBeam *this)
{
  return &g_CTEBaseBeam_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x1032C1C0
// Name: public: CTEBaseBeam::CTEBaseBeam(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CTEBaseBeam *__thiscall CTEBaseBeam::CTEBaseBeam(CTEBaseBeam *this, const char *name)
{
  int m_Value; // eax
  int v4; // eax
  int v5; // eax
  CTEBaseBeam *result; // eax

  CBaseTempEntity::CBaseTempEntity(this, name);
  this->__vftable = (CTEBaseBeam_vtbl *)&CTEBaseBeam::`vftable';
  if ( this->m_nModelIndex.m_Value != 0 )
    this->m_nModelIndex.m_Value = 0;
  if ( this->m_nHaloIndex.m_Value != 0 )
    this->m_nHaloIndex.m_Value = 0;
  if ( this->m_nStartFrame.m_Value != 0 )
    this->m_nStartFrame.m_Value = 0;
  if ( this->m_nFrameRate.m_Value != 0 )
    this->m_nFrameRate.m_Value = 0;
  if ( this->m_fLife.m_Value != 0.0 )
    this->m_fLife.m_Value = 0.0;
  if ( this->m_fWidth.m_Value != 0.0 )
    this->m_fWidth.m_Value = 0.0;
  if ( this->m_fEndWidth.m_Value != 0.0 )
    this->m_fEndWidth.m_Value = 0.0;
  if ( this->m_nFadeLength.m_Value != 0 )
    this->m_nFadeLength.m_Value = 0;
  if ( this->m_fAmplitude.m_Value != 0.0 )
    this->m_fAmplitude.m_Value = 0.0;
  if ( this->a.m_Value != 0 )
    this->a.m_Value = 0;
  m_Value = this->a.m_Value;
  if ( this->b.m_Value != m_Value )
    this->b.m_Value = m_Value;
  v4 = this->b.m_Value;
  if ( this->g.m_Value != v4 )
    this->g.m_Value = v4;
  v5 = this->g.m_Value;
  if ( this->r.m_Value != v5 )
    this->r.m_Value = v5;
  if ( this->m_nSpeed.m_Value != 0 )
    this->m_nSpeed.m_Value = 0;
  result = this;
  if ( this->m_nFlags.m_Value != 0 )
    this->m_nFlags.m_Value = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10415BB0
// Name: DT_BaseBeam::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseBeam::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_BaseBeam::g_SendTable);
  return atexit(func: DT_BaseBeam::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10415BD0
// Name: DT_BaseBeam::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseBeam::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_BaseBeam::ignored>();
  DT_BaseBeam::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421E40
// Name: DT_BaseBeam::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_BaseBeam::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_BaseBeam::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10415BE0
// Name: _dynamic_initializer_for__g_CTEBeamEntPoint_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CTEBeamEntPoint_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CTEBeamEntPoint_ClassReg,
           pNetworkName: "CTEBeamEntPoint",
           pTable: &DT_TEBeamEntPoint::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10421E50
// Name: _ServerClassInit_DT_BaseBeam::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_BaseBeam::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_322;
  for ( i = 15; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}
