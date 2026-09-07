// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/te_explosion.cpp
// Functions: 11
// ============================================================

#include "game\server\te_explosion.h"

//------------------------------------------------------------------------------
// Address: 0x103313B0
// Name: public: virtual class ServerClass __near * CTEExplosion::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CTEExplosion::GetServerClass(CTEExplosion *this)
{
  return &g_CTEExplosion_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x103315B0
// Name: public: CTEExplosion::CTEExplosion(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CTEExplosion *__thiscall CTEExplosion::CTEExplosion(CTEExplosion *this, const char *name)
{
  CTEExplosion *result; // eax

  CBaseTempEntity::CBaseTempEntity(this, name);
  this->m_vecOrigin.m_Value.x = 0.0;
  this->m_vecOrigin.m_Value.y = 0.0;
  this->m_vecOrigin.m_Value.z = 0.0;
  this->__vftable = (CTEExplosion_vtbl *)&CTEExplosion::`vftable';
  if ( this->m_nModelIndex.m_Value != 0 )
    this->m_nModelIndex.m_Value = 0;
  if ( this->m_fScale.m_Value != 0.0 )
    this->m_fScale.m_Value = 0.0;
  if ( this->m_nFrameRate.m_Value != 0 )
    this->m_nFrameRate.m_Value = 0;
  if ( this->m_nFlags.m_Value != 0 )
    this->m_nFlags.m_Value = 0;
  if ( this->m_vecNormal.m_Value.x != 0.0 || this->m_vecNormal.m_Value.y != 0.0 || this->m_vecNormal.m_Value.z != 0.0 )
  {
    this->m_vecNormal.m_Value.x = 0.0;
    this->m_vecNormal.m_Value.y = 0.0;
    this->m_vecNormal.m_Value.z = 0.0;
  }
  if ( this->m_chMaterialType.m_Value != 67 )
    this->m_chMaterialType.m_Value = 67;
  if ( this->m_nRadius.m_Value != 0 )
    this->m_nRadius.m_Value = 0;
  result = this;
  if ( this->m_nMagnitude.m_Value != 0 )
    this->m_nMagnitude.m_Value = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10331660
// Name: public: virtual void CTEExplosion::Test(class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTEExplosion::Test(CTEExplosion *this, const Vector *current_origin, const QAngle *current_angles)
{
  float y; // xmm0_4
  float z; // xmm0_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm3_4
  CBroadcastRecipientFilter filter; // [esp+8h] [ebp-2Ch] BYREF
  Vector forward; // [esp+28h] [ebp-Ch] BYREF

  if ( this->m_nModelIndex.m_Value != g_sModelIndexFireball )
    this->m_nModelIndex.m_Value = g_sModelIndexFireball;
  if ( this->m_fScale.m_Value != 0.5 )
    this->m_fScale.m_Value = 0.5;
  if ( this->m_nFrameRate.m_Value != 15 )
    this->m_nFrameRate.m_Value = 15;
  if ( this->m_nFlags.m_Value != 0 )
    this->m_nFlags.m_Value = 0;
  if ( this->m_vecOrigin.m_Value.x != current_origin->x )
    this->m_vecOrigin.m_Value.x = current_origin->x;
  y = current_origin->y;
  if ( this->m_vecOrigin.m_Value.y != y )
    this->m_vecOrigin.m_Value.y = y;
  z = current_origin->z;
  if ( this->m_vecOrigin.m_Value.z != z )
    this->m_vecOrigin.m_Value.z = z;
  this->m_vecOrigin.m_Value.z = this->m_vecOrigin.m_Value.z + 24.0;
  AngleVectors(angles: current_angles, &forward);
  forward.z = 0.0;
  VectorNormalize(vec: &forward);
  v6 = (float)(forward.x * 50.0) + this->m_vecOrigin.m_Value.x;
  v7 = (float)(forward.z * 50.0) + this->m_vecOrigin.m_Value.z;
  v8 = this->m_vecOrigin.m_Value.y + (float)(forward.y * 50.0);
  if ( this->m_vecOrigin.m_Value.x != v6 )
    this->m_vecOrigin.m_Value.x = v6;
  if ( this->m_vecOrigin.m_Value.y != v8 )
    this->m_vecOrigin.m_Value.y = v8;
  if ( this->m_vecOrigin.m_Value.z != v7 )
    this->m_vecOrigin.m_Value.z = v7;
  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CBroadcastRecipientFilter_vtbl *)&CBroadcastRecipientFilter::`vftable';
  CRecipientFilter::AddAllPlayers(this: &filter);
  ((void (__thiscall *)(CTEExplosion *, CBroadcastRecipientFilter *, _DWORD))this->Create)(a1: this, a2: &filter, a3: 0);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x103317E0
// Name: void TE_Explosion(class IRecipientFilter __near &,float,class Vector const __near *,int,float,int,int,int,int,class Vector const __near *,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_Explosion(
        IRecipientFilter *filter,
        float delay,
        const Vector *pPos,
        int modelindex,
        float scale,
        int framerate,
        int flags,
        int radius,
        int magnitude,
        CNetworkVectorBase<Vector,CTEExplosion::NetworkVar_m_vecNormal> *pNormal,
        unsigned __int8 materialType)
{
  CNetworkVectorBase<Vector,CTEExplosion::NetworkVar_m_vecNormal> *v11; // ecx
  _DWORD v12[3]; // [esp+4h] [ebp-Ch] BYREF

  if ( g_TEExplosion.m_vecOrigin.m_Value.x != pPos->x )
    g_TEExplosion.m_vecOrigin.m_Value.x = pPos->x;
  if ( g_TEExplosion.m_vecOrigin.m_Value.y != pPos->y )
    g_TEExplosion.m_vecOrigin.m_Value.y = pPos->y;
  if ( g_TEExplosion.m_vecOrigin.m_Value.z != pPos->z )
    g_TEExplosion.m_vecOrigin.m_Value.z = pPos->z;
  if ( g_TEExplosion.m_nModelIndex.m_Value != modelindex )
    g_TEExplosion.m_nModelIndex.m_Value = modelindex;
  if ( g_TEExplosion.m_fScale.m_Value != scale )
    g_TEExplosion.m_fScale.m_Value = scale;
  if ( g_TEExplosion.m_nFrameRate.m_Value != framerate )
    g_TEExplosion.m_nFrameRate.m_Value = framerate;
  if ( g_TEExplosion.m_nFlags.m_Value != flags )
    g_TEExplosion.m_nFlags.m_Value = flags;
  if ( g_TEExplosion.m_nRadius.m_Value != radius )
    g_TEExplosion.m_nRadius.m_Value = radius;
  if ( g_TEExplosion.m_nMagnitude.m_Value != magnitude )
    g_TEExplosion.m_nMagnitude.m_Value = magnitude;
  v11 = pNormal;
  if ( pNormal == nullptr )
  {
    v12[0] = 0;
    v12[1] = 0;
    v12[2] = 1065353216;
    v11 = (CNetworkVectorBase<Vector,CTEExplosion::NetworkVar_m_vecNormal> *)v12;
  }
  if ( v11->m_Value.x != g_TEExplosion.m_vecNormal.m_Value.x
    || v11->m_Value.y != g_TEExplosion.m_vecNormal.m_Value.y
    || v11->m_Value.z != g_TEExplosion.m_vecNormal.m_Value.z )
  {
    g_TEExplosion.m_vecNormal = *v11;
  }
  if ( g_TEExplosion.m_chMaterialType.m_Value != materialType )
    g_TEExplosion.m_chMaterialType.m_Value = materialType;
  CBaseTempEntity::Create(this: &g_TEExplosion, filter, delay);
}

//------------------------------------------------------------------------------
// Address: 0x10416BB0
// Name: DT_TEExplosion::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEExplosion::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_TEExplosion::g_SendTable);
  return atexit(func: DT_TEExplosion::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10416BD0
// Name: DT_TEExplosion::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEExplosion::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_TEExplosion::ignored>();
  DT_TEExplosion::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10422460
// Name: DT_TEExplosion::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEExplosion::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_TEExplosion::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10416BE0
// Name: _dynamic_initializer_for__g_TEExplosion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TEExplosion__()
{
  CTEExplosion::CTEExplosion(this: &g_TEExplosion, name: "Explosion");
  return atexit(func: dynamic_atexit_destructor_for__g_TEExplosion__);
}

//------------------------------------------------------------------------------
// Address: 0x10416C00
// Name: _dynamic_initializer_for__g_CTEFizz_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CTEFizz_ClassReg__()
{
  return ServerClass::ServerClass(this: &g_CTEFizz_ClassReg, pNetworkName: "CTEFizz", pTable: &DT_TEFizz::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10422470
// Name: _dynamic_atexit_destructor_for__g_TEExplosion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TEExplosion__()
{
  g_TEExplosion.__vftable = (CTEExplosion_vtbl *)&CTEExplosion::`vftable';
  CBaseTempEntity::~CBaseTempEntity(this: &g_TEExplosion);
}

//------------------------------------------------------------------------------
// Address: 0x10422490
// Name: _ServerClassInit_DT_TEExplosion::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_TEExplosion::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_342;
  for ( i = 9; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}
