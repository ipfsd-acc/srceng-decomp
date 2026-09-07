// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/te_bubbles.cpp
// Functions: 10
// ============================================================

#include "game\server\te_bubbles.h"

//------------------------------------------------------------------------------
// Address: 0x1032F580
// Name: public: virtual class ServerClass __near * CTEBubbles::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CTEBubbles::GetServerClass(CTEBubbles *this)
{
  return &g_CTEBubbles_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x1032F780
// Name: public: virtual void CTEBubbles::Test(class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTEBubbles::Test(
        CTEBubbles *this,
        CNetworkVectorBase<Vector,CTEBubbles::NetworkVar_m_vecMins> *current_origin,
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
  if ( this->m_fSpeed.m_Value != 2.0 )
    this->m_fSpeed.m_Value = 2.0;
  if ( this->m_nCount.m_Value != 50 )
    this->m_nCount.m_Value = 50;
  if ( this->m_fHeight.m_Value != 256.0 )
    this->m_fHeight.m_Value = 256.0;
  if ( this->m_nModelIndex.m_Value != g_sModelIndexBubbles )
    this->m_nModelIndex.m_Value = g_sModelIndexBubbles;
  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CBroadcastRecipientFilter_vtbl *)&CBroadcastRecipientFilter::`vftable';
  CRecipientFilter::AddAllPlayers(this: &filter);
  ((void (__thiscall *)(CTEBubbles *, CBroadcastRecipientFilter *, _DWORD))this->Create)(a1: this, a2: &filter, a3: 0);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x1032F920
// Name: void TE_Bubbles(class IRecipientFilter __near &,float,class Vector const __near *,class Vector const __near *,float,int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_Bubbles(
        IRecipientFilter *filter,
        float delay,
        CNetworkVectorBase<Vector,CTEBubbles::NetworkVar_m_vecMins> *mins,
        CNetworkVectorBase<Vector,CTEBubbles::NetworkVar_m_vecMaxs> *maxs,
        float height,
        int modelindex,
        int count,
        float speed)
{
  if ( mins->m_Value.x != g_TEBubbles.m_vecMins.m_Value.x
    || mins->m_Value.y != g_TEBubbles.m_vecMins.m_Value.y
    || mins->m_Value.z != g_TEBubbles.m_vecMins.m_Value.z )
  {
    g_TEBubbles.m_vecMins = *mins;
  }
  if ( maxs->m_Value.x != g_TEBubbles.m_vecMaxs.m_Value.x
    || maxs->m_Value.y != g_TEBubbles.m_vecMaxs.m_Value.y
    || maxs->m_Value.z != g_TEBubbles.m_vecMaxs.m_Value.z )
  {
    g_TEBubbles.m_vecMaxs = *maxs;
  }
  if ( g_TEBubbles.m_fHeight.m_Value != height )
    g_TEBubbles.m_fHeight.m_Value = height;
  if ( g_TEBubbles.m_nModelIndex.m_Value != modelindex )
    g_TEBubbles.m_nModelIndex.m_Value = modelindex;
  if ( g_TEBubbles.m_nCount.m_Value != count )
    g_TEBubbles.m_nCount.m_Value = count;
  if ( g_TEBubbles.m_fSpeed.m_Value != speed )
    g_TEBubbles.m_fSpeed.m_Value = speed;
  CBaseTempEntity::Create(this: &g_TEBubbles, filter, delay);
}

//------------------------------------------------------------------------------
// Address: 0x10416510
// Name: DT_TEBubbles::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEBubbles::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_TEBubbles::g_SendTable);
  return atexit(func: DT_TEBubbles::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10416530
// Name: DT_TEBubbles::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEBubbles::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_TEBubbles::ignored>();
  DT_TEBubbles::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10422230
// Name: DT_TEBubbles::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEBubbles::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_TEBubbles::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10416540
// Name: _dynamic_initializer_for__g_TEBubbles__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TEBubbles__()
{
  CBaseTempEntity::CBaseTempEntity(this: &g_TEBubbles, name: "Bubbles");
  g_TEBubbles.__vftable = (CTEBubbles_vtbl *)&CTEBubbles::`vftable';
  if ( g_TEBubbles.m_vecMins.m_Value.x != 0.0
    || g_TEBubbles.m_vecMins.m_Value.y != 0.0
    || g_TEBubbles.m_vecMins.m_Value.z != 0.0 )
  {
    g_TEBubbles.m_vecMins.m_Value.x = 0.0;
    g_TEBubbles.m_vecMins.m_Value.y = 0.0;
    g_TEBubbles.m_vecMins.m_Value.z = 0.0;
  }
  if ( g_TEBubbles.m_vecMaxs.m_Value.x != 0.0
    || g_TEBubbles.m_vecMaxs.m_Value.y != 0.0
    || g_TEBubbles.m_vecMaxs.m_Value.z != 0.0 )
  {
    g_TEBubbles.m_vecMaxs.m_Value.x = 0.0;
    g_TEBubbles.m_vecMaxs.m_Value.y = 0.0;
    g_TEBubbles.m_vecMaxs.m_Value.z = 0.0;
  }
  if ( g_TEBubbles.m_fHeight.m_Value != 0.0 )
    g_TEBubbles.m_fHeight.m_Value = 0.0;
  if ( g_TEBubbles.m_nModelIndex.m_Value != 0 )
    g_TEBubbles.m_nModelIndex.m_Value = 0;
  if ( g_TEBubbles.m_nCount.m_Value != 0 )
    g_TEBubbles.m_nCount.m_Value = 0;
  if ( g_TEBubbles.m_fSpeed.m_Value != 0.0 )
    g_TEBubbles.m_fSpeed.m_Value = 0.0;
  return atexit(func: dynamic_atexit_destructor_for__g_TEBubbles__);
}

//------------------------------------------------------------------------------
// Address: 0x10416640
// Name: _dynamic_initializer_for__g_CTEBubbleTrail_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CTEBubbleTrail_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CTEBubbleTrail_ClassReg,
           pNetworkName: "CTEBubbleTrail",
           pTable: &DT_TEBubbleTrail::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10422240
// Name: _dynamic_atexit_destructor_for__g_TEBubbles__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TEBubbles__()
{
  g_TEBubbles.__vftable = (CTEBubbles_vtbl *)&CTEBubbles::`vftable';
  CBaseTempEntity::~CBaseTempEntity(this: &g_TEBubbles);
}

//------------------------------------------------------------------------------
// Address: 0x10422260
// Name: _ServerClassInit_DT_TEBubbles::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_TEBubbles::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_335;
  for ( i = 7; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}
