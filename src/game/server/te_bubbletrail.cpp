// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/te_bubbletrail.cpp
// Functions: 10
// ============================================================

#include "game\server\te_bubbletrail.h"

//------------------------------------------------------------------------------
// Address: 0x1032FA50
// Name: public: virtual class ServerClass __near * CTEBubbleTrail::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CTEBubbleTrail::GetServerClass(CTEBubbleTrail *this)
{
  return &g_CTEBubbleTrail_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x1032FC50
// Name: public: virtual void CTEBubbleTrail::Test(class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTEBubbleTrail::Test(
        CTEBubbleTrail *this,
        CNetworkVectorBase<Vector,CTEBubbleTrail::NetworkVar_m_vecMins> *current_origin,
        const QAngle *current_angles)
{
  float v4; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  CBroadcastRecipientFilter filter; // [esp+8h] [ebp-2Ch] BYREF
  Vector forward; // [esp+28h] [ebp-Ch] BYREF

  if ( current_origin->m_Value.x != this->m_vecMins.m_Value.x
    || current_origin->m_Value.y != this->m_vecMins.m_Value.y
    || current_origin->m_Value.z != this->m_vecMins.m_Value.z )
  {
    this->m_vecMins = *current_origin;
  }
  this->m_vecMins.m_Value.z = this->m_vecMins.m_Value.z + 24.0;
  AngleVectors(angles: current_angles, &forward);
  forward.z = 0.0;
  VectorNormalize(vec: &forward);
  this->m_vecMins.m_Value.x = (float)(forward.x * 100.0) + this->m_vecMins.m_Value.x;
  this->m_vecMins.m_Value.y = (float)(forward.y * 100.0) + this->m_vecMins.m_Value.y;
  this->m_vecMins.m_Value.z = (float)(forward.z * 100.0) + this->m_vecMins.m_Value.z;
  v4 = this->m_vecMins.m_Value.x + 256.0;
  v5 = this->m_vecMins.m_Value.y + 256.0;
  v6 = this->m_vecMins.m_Value.z + 256.0;
  if ( v4 != this->m_vecMaxs.m_Value.x || v5 != this->m_vecMaxs.m_Value.y || v6 != this->m_vecMaxs.m_Value.z )
  {
    this->m_vecMaxs.m_Value.x = v4;
    this->m_vecMaxs.m_Value.y = v5;
    this->m_vecMaxs.m_Value.z = v6;
  }
  if ( this->m_fSpeed.m_Value != 8.0 )
    this->m_fSpeed.m_Value = 8.0;
  if ( this->m_nCount.m_Value != 20 )
    this->m_nCount.m_Value = 20;
  if ( this->m_flWaterZ.m_Value != 0.0 )
    this->m_flWaterZ.m_Value = 0.0;
  if ( this->m_nModelIndex.m_Value != g_sModelIndexBubbles )
    this->m_nModelIndex.m_Value = g_sModelIndexBubbles;
  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CBroadcastRecipientFilter_vtbl *)&CBroadcastRecipientFilter::`vftable';
  CRecipientFilter::AddAllPlayers(this: &filter);
  ((void (__thiscall *)(CTEBubbleTrail *, CBroadcastRecipientFilter *, _DWORD))this->Create)(
    a1: this,
    a2: &filter,
    a3: 0);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x1032FDF0
// Name: void TE_BubbleTrail(class IRecipientFilter __near &,float,class Vector const __near *,class Vector const __near *,float,int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_BubbleTrail(
        IRecipientFilter *filter,
        float delay,
        CNetworkVectorBase<Vector,CTEBubbleTrail::NetworkVar_m_vecMins> *mins,
        CNetworkVectorBase<Vector,CTEBubbleTrail::NetworkVar_m_vecMaxs> *maxs,
        float flWaterZ,
        int modelindex,
        int count,
        float speed)
{
  int v8; // eax

  if ( mins->m_Value.x != g_TEBubbleTrail.m_vecMins.m_Value.x
    || mins->m_Value.y != g_TEBubbleTrail.m_vecMins.m_Value.y
    || mins->m_Value.z != g_TEBubbleTrail.m_vecMins.m_Value.z )
  {
    g_TEBubbleTrail.m_vecMins = *mins;
  }
  if ( maxs->m_Value.x != g_TEBubbleTrail.m_vecMaxs.m_Value.x
    || maxs->m_Value.y != g_TEBubbleTrail.m_vecMaxs.m_Value.y
    || maxs->m_Value.z != g_TEBubbleTrail.m_vecMaxs.m_Value.z )
  {
    g_TEBubbleTrail.m_vecMaxs = *maxs;
  }
  if ( g_TEBubbleTrail.m_flWaterZ.m_Value != flWaterZ )
    g_TEBubbleTrail.m_flWaterZ.m_Value = flWaterZ;
  if ( g_TEBubbleTrail.m_nModelIndex.m_Value != modelindex )
    g_TEBubbleTrail.m_nModelIndex.m_Value = modelindex;
  v8 = count;
  if ( count >= 255 )
    v8 = 255;
  if ( g_TEBubbleTrail.m_nCount.m_Value != v8 )
    g_TEBubbleTrail.m_nCount.m_Value = v8;
  if ( g_TEBubbleTrail.m_fSpeed.m_Value != speed )
    g_TEBubbleTrail.m_fSpeed.m_Value = speed;
  CBaseTempEntity::Create(this: &g_TEBubbleTrail, filter, delay);
}

//------------------------------------------------------------------------------
// Address: 0x10416660
// Name: DT_TEBubbleTrail::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEBubbleTrail::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_TEBubbleTrail::g_SendTable);
  return atexit(func: DT_TEBubbleTrail::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10416680
// Name: DT_TEBubbleTrail::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEBubbleTrail::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_TEBubbleTrail::ignored>();
  DT_TEBubbleTrail::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10422280
// Name: DT_TEBubbleTrail::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEBubbleTrail::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_TEBubbleTrail::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10416690
// Name: _dynamic_initializer_for__g_TEBubbleTrail__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TEBubbleTrail__()
{
  CBaseTempEntity::CBaseTempEntity(this: &g_TEBubbleTrail, name: "Bubble Trail");
  g_TEBubbleTrail.__vftable = (CTEBubbleTrail_vtbl *)&CTEBubbleTrail::`vftable';
  if ( g_TEBubbleTrail.m_vecMins.m_Value.x != 0.0
    || g_TEBubbleTrail.m_vecMins.m_Value.y != 0.0
    || g_TEBubbleTrail.m_vecMins.m_Value.z != 0.0 )
  {
    g_TEBubbleTrail.m_vecMins.m_Value.x = 0.0;
    g_TEBubbleTrail.m_vecMins.m_Value.y = 0.0;
    g_TEBubbleTrail.m_vecMins.m_Value.z = 0.0;
  }
  if ( g_TEBubbleTrail.m_vecMaxs.m_Value.x != 0.0
    || g_TEBubbleTrail.m_vecMaxs.m_Value.y != 0.0
    || g_TEBubbleTrail.m_vecMaxs.m_Value.z != 0.0 )
  {
    g_TEBubbleTrail.m_vecMaxs.m_Value.x = 0.0;
    g_TEBubbleTrail.m_vecMaxs.m_Value.y = 0.0;
    g_TEBubbleTrail.m_vecMaxs.m_Value.z = 0.0;
  }
  if ( g_TEBubbleTrail.m_flWaterZ.m_Value != 0.0 )
    g_TEBubbleTrail.m_flWaterZ.m_Value = 0.0;
  if ( g_TEBubbleTrail.m_nModelIndex.m_Value != 0 )
    g_TEBubbleTrail.m_nModelIndex.m_Value = 0;
  if ( g_TEBubbleTrail.m_nCount.m_Value != 0 )
    g_TEBubbleTrail.m_nCount.m_Value = 0;
  if ( g_TEBubbleTrail.m_fSpeed.m_Value != 0.0 )
    g_TEBubbleTrail.m_fSpeed.m_Value = 0.0;
  return atexit(func: dynamic_atexit_destructor_for__g_TEBubbleTrail__);
}

//------------------------------------------------------------------------------
// Address: 0x10416790
// Name: _dynamic_initializer_for__g_CTEClientProjectile_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CTEClientProjectile_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CTEClientProjectile_ClassReg,
           pNetworkName: "CTEClientProjectile",
           pTable: &DT_TEClientProjectile::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10422290
// Name: _dynamic_atexit_destructor_for__g_TEBubbleTrail__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TEBubbleTrail__()
{
  g_TEBubbleTrail.__vftable = (CTEBubbleTrail_vtbl *)&CTEBubbleTrail::`vftable';
  CBaseTempEntity::~CBaseTempEntity(this: &g_TEBubbleTrail);
}

//------------------------------------------------------------------------------
// Address: 0x104222B0
// Name: _ServerClassInit_DT_TEBubbleTrail::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_TEBubbleTrail::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_336;
  for ( i = 7; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}
