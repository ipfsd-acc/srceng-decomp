// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/te_decal.cpp
// Functions: 10
// ============================================================

#include "game\server\te_decal.h"

//------------------------------------------------------------------------------
// Address: 0x10330430
// Name: public: virtual class ServerClass __near * CTEDecal::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CTEDecal::GetServerClass(CTEDecal *this)
{
  return &g_CTEDecal_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x103305D0
// Name: public: virtual void CTEDecal::Test(class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTEDecal::Test(CTEDecal *this, const Vector *current_origin, const QAngle *current_angles)
{
  CNetworkVectorBase<Vector,CTEDecal::NetworkVar_m_vecOrigin> *p_m_vecOrigin; // esi
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
  ((void (__thiscall *)(CTEDecal *, CBroadcastRecipientFilter *, _DWORD))this->Create)(a1: this, a2: &filter, a3: 0);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x10330780
// Name: void TE_Decal(class IRecipientFilter __near &,float,class Vector const __near *,class Vector const __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_Decal(
        IRecipientFilter *filter,
        float delay,
        CNetworkVectorBase<Vector,CTEDecal::NetworkVar_m_vecOrigin> *pos,
        CNetworkVectorBase<Vector,CTEDecal::NetworkVar_m_vecStart> *start,
        int entity,
        int hitbox,
        int index)
{
  if ( pos->m_Value.x != g_TEDecal.m_vecOrigin.m_Value.x
    || pos->m_Value.y != g_TEDecal.m_vecOrigin.m_Value.y
    || pos->m_Value.z != g_TEDecal.m_vecOrigin.m_Value.z )
  {
    g_TEDecal.m_vecOrigin = *pos;
  }
  if ( start->m_Value.x != g_TEDecal.m_vecStart.m_Value.x
    || start->m_Value.y != g_TEDecal.m_vecStart.m_Value.y
    || start->m_Value.z != g_TEDecal.m_vecStart.m_Value.z )
  {
    g_TEDecal.m_vecStart = *start;
  }
  if ( g_TEDecal.m_nEntity.m_Value != entity )
    g_TEDecal.m_nEntity.m_Value = entity;
  if ( g_TEDecal.m_nHitbox.m_Value != hitbox )
    g_TEDecal.m_nHitbox.m_Value = hitbox;
  if ( g_TEDecal.m_nIndex.m_Value != index )
    g_TEDecal.m_nIndex.m_Value = index;
  CBaseTempEntity::Create(this: &g_TEDecal, filter, delay);
}

//------------------------------------------------------------------------------
// Address: 0x10416820
// Name: DT_TEDecal::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEDecal::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_TEDecal::g_SendTable);
  return atexit(func: DT_TEDecal::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10416840
// Name: DT_TEDecal::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEDecal::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_TEDecal::ignored>();
  DT_TEDecal::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10422320
// Name: DT_TEDecal::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEDecal::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_TEDecal::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10416850
// Name: _dynamic_initializer_for__g_TEDecal__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TEDecal__()
{
  CBaseTempEntity::CBaseTempEntity(this: &g_TEDecal, name: "Entity Decal");
  g_TEDecal.__vftable = (CTEDecal_vtbl *)&CTEDecal::`vftable';
  if ( g_TEDecal.m_vecOrigin.m_Value.x != 0.0
    || g_TEDecal.m_vecOrigin.m_Value.y != 0.0
    || g_TEDecal.m_vecOrigin.m_Value.z != 0.0 )
  {
    g_TEDecal.m_vecOrigin.m_Value.x = 0.0;
    g_TEDecal.m_vecOrigin.m_Value.y = 0.0;
    g_TEDecal.m_vecOrigin.m_Value.z = 0.0;
  }
  if ( g_TEDecal.m_nEntity.m_Value != 0 )
    g_TEDecal.m_nEntity.m_Value = 0;
  if ( g_TEDecal.m_nIndex.m_Value != 0 )
    g_TEDecal.m_nIndex.m_Value = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_TEDecal__);
}

//------------------------------------------------------------------------------
// Address: 0x104168E0
// Name: _dynamic_initializer_for__g_CTEDynamicLight_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CTEDynamicLight_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CTEDynamicLight_ClassReg,
           pNetworkName: "CTEDynamicLight",
           pTable: &DT_TEDynamicLight::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10422330
// Name: _dynamic_atexit_destructor_for__g_TEDecal__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TEDecal__()
{
  g_TEDecal.__vftable = (CTEDecal_vtbl *)&CTEDecal::`vftable';
  CBaseTempEntity::~CBaseTempEntity(this: &g_TEDecal);
}

//------------------------------------------------------------------------------
// Address: 0x10422350
// Name: _ServerClassInit_DT_TEDecal::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_TEDecal::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_338;
  for ( i = 6; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}
