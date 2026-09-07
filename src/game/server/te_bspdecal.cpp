// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/te_bspdecal.cpp
// Functions: 10
// ============================================================

#include "game\server\te_bspdecal.h"

//------------------------------------------------------------------------------
// Address: 0x1032F1F0
// Name: public: virtual class ServerClass __near * CTEBSPDecal::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CTEBSPDecal::GetServerClass(CTEBSPDecal *this)
{
  return &g_CTEBSPDecal_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x1032F330
// Name: public: virtual void CTEBSPDecal::Test(class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTEBSPDecal::Test(CTEBSPDecal *this, const Vector *current_origin, const QAngle *current_angles)
{
  CNetworkVectorBase<Vector,CTEBSPDecal::NetworkVar_m_vecOrigin> *p_m_vecOrigin; // esi
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

  if ( this->m_nEntity.m_Value != 0 )
    this->m_nEntity.m_Value = 0;
  if ( this->m_nIndex.m_Value != 0 )
    this->m_nIndex.m_Value = 0;
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
  ((void (__thiscall *)(CTEBSPDecal *, CBroadcastRecipientFilter *, _DWORD))this->Create)(a1: this, a2: &filter, a3: 0);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x1032F4E0
// Name: void TE_BSPDecal(class IRecipientFilter __near &,float,class Vector const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_BSPDecal(
        IRecipientFilter *filter,
        float delay,
        CNetworkVectorBase<Vector,CTEBSPDecal::NetworkVar_m_vecOrigin> *pos,
        int entity,
        int index)
{
  if ( pos->m_Value.x != g_TEBSPDecal.m_vecOrigin.m_Value.x
    || pos->m_Value.y != g_TEBSPDecal.m_vecOrigin.m_Value.y
    || pos->m_Value.z != g_TEBSPDecal.m_vecOrigin.m_Value.z )
  {
    g_TEBSPDecal.m_vecOrigin = *pos;
  }
  if ( g_TEBSPDecal.m_nEntity.m_Value != entity )
    g_TEBSPDecal.m_nEntity.m_Value = entity;
  if ( g_TEBSPDecal.m_nIndex.m_Value != index )
    g_TEBSPDecal.m_nIndex.m_Value = index;
  CBaseTempEntity::Create(this: &g_TEBSPDecal, filter, delay);
}

//------------------------------------------------------------------------------
// Address: 0x10416430
// Name: DT_TEBSPDecal::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEBSPDecal::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_TEBSPDecal::g_SendTable);
  return atexit(func: DT_TEBSPDecal::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10416450
// Name: DT_TEBSPDecal::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEBSPDecal::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_TEBSPDecal::ignored>();
  DT_TEBSPDecal::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104221E0
// Name: DT_TEBSPDecal::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEBSPDecal::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_TEBSPDecal::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10416460
// Name: _dynamic_initializer_for__g_TEBSPDecal__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TEBSPDecal__()
{
  CBaseTempEntity::CBaseTempEntity(this: &g_TEBSPDecal, name: "BSP Decal");
  g_TEBSPDecal.__vftable = (CTEBSPDecal_vtbl *)&CTEBSPDecal::`vftable';
  if ( g_TEBSPDecal.m_vecOrigin.m_Value.x != 0.0
    || g_TEBSPDecal.m_vecOrigin.m_Value.y != 0.0
    || g_TEBSPDecal.m_vecOrigin.m_Value.z != 0.0 )
  {
    g_TEBSPDecal.m_vecOrigin.m_Value.x = 0.0;
    g_TEBSPDecal.m_vecOrigin.m_Value.y = 0.0;
    g_TEBSPDecal.m_vecOrigin.m_Value.z = 0.0;
  }
  if ( g_TEBSPDecal.m_nEntity.m_Value != 0 )
    g_TEBSPDecal.m_nEntity.m_Value = 0;
  if ( g_TEBSPDecal.m_nIndex.m_Value != 0 )
    g_TEBSPDecal.m_nIndex.m_Value = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_TEBSPDecal__);
}

//------------------------------------------------------------------------------
// Address: 0x104164F0
// Name: _dynamic_initializer_for__g_CTEBubbles_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CTEBubbles_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CTEBubbles_ClassReg,
           pNetworkName: "CTEBubbles",
           pTable: &DT_TEBubbles::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x104221F0
// Name: _dynamic_atexit_destructor_for__g_TEBSPDecal__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TEBSPDecal__()
{
  g_TEBSPDecal.__vftable = (CTEBSPDecal_vtbl *)&CTEBSPDecal::`vftable';
  CBaseTempEntity::~CBaseTempEntity(this: &g_TEBSPDecal);
}

//------------------------------------------------------------------------------
// Address: 0x10422210
// Name: _ServerClassInit_DT_TEBSPDecal::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_TEBSPDecal::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_334;
  for ( i = 4; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}
