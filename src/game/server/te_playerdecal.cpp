// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/te_playerdecal.cpp
// Functions: 10
// ============================================================

#include "game\server\te_playerdecal.h"

//------------------------------------------------------------------------------
// Address: 0x10333AF0
// Name: public: virtual class ServerClass __near * CTEPlayerDecal::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CTEPlayerDecal::GetServerClass(CTEPlayerDecal *this)
{
  return &g_CTEPlayerDecal_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10333C40
// Name: public: virtual void CTEPlayerDecal::Test(class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTEPlayerDecal::Test(CTEPlayerDecal *this, const Vector *current_origin, const QAngle *current_angles)
{
  CNetworkVectorBase<Vector,CTEPlayerDecal::NetworkVar_m_vecOrigin> *p_m_vecOrigin; // esi
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  float v8; // xmm4_4
  float v9; // xmm1_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  CGameTrace tr; // [esp+Ch] [ebp-8Ch] BYREF
  CBroadcastRecipientFilter filter; // [esp+60h] [ebp-38h] BYREF
  Vector vecEnd; // [esp+80h] [ebp-18h] BYREF
  Vector forward; // [esp+8Ch] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+98h] [ebp+0h] BYREF

  if ( this->m_nPlayer.m_Value != 1 )
    this->m_nPlayer.m_Value = 1;
  if ( this->m_nEntity.m_Value != 0 )
    this->m_nEntity.m_Value = 0;
  p_m_vecOrigin = &this->m_vecOrigin;
  if ( current_origin->x != this->m_vecOrigin.m_Value.x
    || current_origin->y != this->m_vecOrigin.m_Value.y
    || current_origin->z != this->m_vecOrigin.m_Value.z )
  {
    p_m_vecOrigin->m_Value.x = current_origin->x;
    this->m_vecOrigin.m_Value.y = current_origin->y;
    this->m_vecOrigin.m_Value.z = current_origin->z;
  }
  this->m_vecOrigin.m_Value.z = this->m_vecOrigin.m_Value.z + 24.0;
  AngleVectors(angles: current_angles, &forward);
  forward.z = 0.0;
  VectorNormalize(vec: &forward);
  x = forward.x;
  p_m_vecOrigin->m_Value.x = (float)(forward.x * 50.0) + p_m_vecOrigin->m_Value.x;
  y = forward.y;
  this->m_vecOrigin.m_Value.y = (float)(forward.y * 50.0) + this->m_vecOrigin.m_Value.y;
  z = forward.z;
  v8 = (float)(forward.z * 50.0) + this->m_vecOrigin.m_Value.z;
  this->m_vecOrigin.m_Value.z = v8;
  v9 = (float)(y * 1024.0) + this->m_vecOrigin.m_Value.y;
  vecEnd.x = (float)(x * 1024.0) + p_m_vecOrigin->m_Value.x;
  vecEnd.y = v9;
  vecEnd.z = (float)(z * 1024.0) + v8;
  UTIL_TraceLine(
    a1: &savedregs,
    a2: (int)p_m_vecOrigin,
    vecAbsStart: &this->m_vecOrigin.m_Value,
    vecAbsEnd: &vecEnd,
    mask: 0x400Bu,
    ignore: nullptr,
    collisionGroup: 0,
    ptr: &tr);
  v10 = tr.endpos.z;
  v11 = tr.endpos.y;
  if ( tr.endpos.x != p_m_vecOrigin->m_Value.x
    || tr.endpos.y != this->m_vecOrigin.m_Value.y
    || tr.endpos.z != this->m_vecOrigin.m_Value.z )
  {
    p_m_vecOrigin->m_Value.x = tr.endpos.x;
    this->m_vecOrigin.m_Value.y = v11;
    this->m_vecOrigin.m_Value.z = v10;
  }
  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CBroadcastRecipientFilter_vtbl *)&CBroadcastRecipientFilter::`vftable';
  CRecipientFilter::AddAllPlayers(this: &filter);
  ((void (__thiscall *)(CTEPlayerDecal *, CBroadcastRecipientFilter *, _DWORD))this->Create)(
    a1: this,
    a2: &filter,
    a3: 0);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x10333DF0
// Name: void TE_PlayerDecal(class IRecipientFilter __near &,float,class Vector const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_PlayerDecal(
        IRecipientFilter *filter,
        float delay,
        CNetworkVectorBase<Vector,CTEPlayerDecal::NetworkVar_m_vecOrigin> *pos,
        int player,
        int entity)
{
  if ( pos->m_Value.x != g_TEPlayerDecal.m_vecOrigin.m_Value.x
    || pos->m_Value.y != g_TEPlayerDecal.m_vecOrigin.m_Value.y
    || pos->m_Value.z != g_TEPlayerDecal.m_vecOrigin.m_Value.z )
  {
    g_TEPlayerDecal.m_vecOrigin = *pos;
  }
  if ( g_TEPlayerDecal.m_nPlayer.m_Value != player )
    g_TEPlayerDecal.m_nPlayer.m_Value = player;
  if ( g_TEPlayerDecal.m_nEntity.m_Value != entity )
    g_TEPlayerDecal.m_nEntity.m_Value = entity;
  CBaseTempEntity::Create(this: &g_TEPlayerDecal, filter, delay);
}

//------------------------------------------------------------------------------
// Address: 0x10417460
// Name: DT_TEPlayerDecal::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEPlayerDecal::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_TEPlayerDecal::g_SendTable);
  return atexit(func: DT_TEPlayerDecal::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10417480
// Name: DT_TEPlayerDecal::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEPlayerDecal::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_TEPlayerDecal::ignored>();
  DT_TEPlayerDecal::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104227F0
// Name: DT_TEPlayerDecal::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEPlayerDecal::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_TEPlayerDecal::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10417490
// Name: _dynamic_initializer_for__g_TEPlayerDecal__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TEPlayerDecal__()
{
  CBaseTempEntity::CBaseTempEntity(this: &g_TEPlayerDecal, name: "Player Decal");
  g_TEPlayerDecal.__vftable = (CTEPlayerDecal_vtbl *)&CTEPlayerDecal::`vftable';
  if ( g_TEPlayerDecal.m_nPlayer.m_Value != 0 )
    g_TEPlayerDecal.m_nPlayer.m_Value = 0;
  if ( g_TEPlayerDecal.m_vecOrigin.m_Value.x != 0.0
    || g_TEPlayerDecal.m_vecOrigin.m_Value.y != 0.0
    || g_TEPlayerDecal.m_vecOrigin.m_Value.z != 0.0 )
  {
    g_TEPlayerDecal.m_vecOrigin.m_Value.x = 0.0;
    g_TEPlayerDecal.m_vecOrigin.m_Value.y = 0.0;
    g_TEPlayerDecal.m_vecOrigin.m_Value.z = 0.0;
  }
  if ( g_TEPlayerDecal.m_nEntity.m_Value != 0 )
    g_TEPlayerDecal.m_nEntity.m_Value = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_TEPlayerDecal__);
}

//------------------------------------------------------------------------------
// Address: 0x10417520
// Name: _dynamic_initializer_for__g_CTEProjectedDecal_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CTEProjectedDecal_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CTEProjectedDecal_ClassReg,
           pNetworkName: "CTEProjectedDecal",
           pTable: &DT_TEProjectedDecal::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10422800
// Name: _dynamic_atexit_destructor_for__g_TEPlayerDecal__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TEPlayerDecal__()
{
  g_TEPlayerDecal.__vftable = (CTEPlayerDecal_vtbl *)&CTEPlayerDecal::`vftable';
  CBaseTempEntity::~CBaseTempEntity(this: &g_TEPlayerDecal);
}

//------------------------------------------------------------------------------
// Address: 0x10422820
// Name: _ServerClassInit_DT_TEPlayerDecal::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_TEPlayerDecal::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_354;
  for ( i = 4; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}
