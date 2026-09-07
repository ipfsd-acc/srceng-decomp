// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/te_smoke.cpp
// Functions: 10
// ============================================================

#include "game\server\te_smoke.h"

//------------------------------------------------------------------------------
// Address: 0x10334640
// Name: public: virtual class ServerClass __near * CTESmoke::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CTESmoke::GetServerClass(CTESmoke *this)
{
  return &g_CTESmoke_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x103347C0
// Name: public: virtual void CTESmoke::Test(class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTESmoke::Test(
        CTESmoke *this,
        CNetworkVectorBase<Vector,CTESmoke::NetworkVar_m_vecOrigin> *current_origin,
        const QAngle *current_angles)
{
  CBroadcastRecipientFilter filter; // [esp+8h] [ebp-38h] BYREF
  Vector right; // [esp+28h] [ebp-18h] BYREF
  Vector forward; // [esp+34h] [ebp-Ch] BYREF

  if ( this->m_nModelIndex.m_Value != g_sModelIndexSmoke )
    this->m_nModelIndex.m_Value = g_sModelIndexSmoke;
  if ( this->m_fScale.m_Value != 5.0 )
    this->m_fScale.m_Value = 5.0;
  if ( this->m_nFrameRate.m_Value != 12 )
    this->m_nFrameRate.m_Value = 12;
  if ( current_origin->m_Value.x != this->m_vecOrigin.m_Value.x
    || current_origin->m_Value.y != this->m_vecOrigin.m_Value.y
    || current_origin->m_Value.z != this->m_vecOrigin.m_Value.z )
  {
    this->m_vecOrigin = *current_origin;
  }
  this->m_vecOrigin.m_Value.z = this->m_vecOrigin.m_Value.z + 24.0;
  AngleVectors(angles: current_angles, &forward, &right, up: nullptr);
  forward.z = 0.0;
  VectorNormalize(vec: &forward);
  this->m_vecOrigin.m_Value.x = (float)(forward.x * 50.0) + this->m_vecOrigin.m_Value.x;
  this->m_vecOrigin.m_Value.y = (float)(forward.y * 50.0) + this->m_vecOrigin.m_Value.y;
  this->m_vecOrigin.m_Value.z = (float)(forward.z * 50.0) + this->m_vecOrigin.m_Value.z;
  this->m_vecOrigin.m_Value.x = (float)(right.x * 25.0) + this->m_vecOrigin.m_Value.x;
  this->m_vecOrigin.m_Value.y = (float)(right.y * 25.0) + this->m_vecOrigin.m_Value.y;
  this->m_vecOrigin.m_Value.z = (float)(right.z * 25.0) + this->m_vecOrigin.m_Value.z;
  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CBroadcastRecipientFilter_vtbl *)&CBroadcastRecipientFilter::`vftable';
  CRecipientFilter::AddAllPlayers(this: &filter);
  ((void (__thiscall *)(CTESmoke *, CBroadcastRecipientFilter *, _DWORD))this->Create)(a1: this, a2: &filter, a3: 0);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x10334940
// Name: void TE_Smoke(class IRecipientFilter __near &,float,class Vector const __near *,int,float,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_Smoke(
        IRecipientFilter *filter,
        float delay,
        CNetworkVectorBase<Vector,CTESmoke::NetworkVar_m_vecOrigin> *pos,
        int modelindex,
        float scale,
        int framerate)
{
  if ( pos->m_Value.x != g_TESmoke.m_vecOrigin.m_Value.x
    || pos->m_Value.y != g_TESmoke.m_vecOrigin.m_Value.y
    || pos->m_Value.z != g_TESmoke.m_vecOrigin.m_Value.z )
  {
    g_TESmoke.m_vecOrigin = *pos;
  }
  if ( g_TESmoke.m_nModelIndex.m_Value != modelindex )
    g_TESmoke.m_nModelIndex.m_Value = modelindex;
  if ( g_TESmoke.m_fScale.m_Value != scale )
    g_TESmoke.m_fScale.m_Value = scale;
  if ( g_TESmoke.m_nFrameRate.m_Value != framerate )
    g_TESmoke.m_nFrameRate.m_Value = framerate;
  CBaseTempEntity::Create(this: &g_TESmoke, filter, delay);
}

//------------------------------------------------------------------------------
// Address: 0x10417740
// Name: DT_TESmoke::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TESmoke::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_TESmoke::g_SendTable);
  return atexit(func: DT_TESmoke::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10417760
// Name: DT_TESmoke::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TESmoke::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_TESmoke::ignored>();
  DT_TESmoke::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104228E0
// Name: DT_TESmoke::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TESmoke::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_TESmoke::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10417770
// Name: _dynamic_initializer_for__g_TESmoke__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TESmoke__()
{
  CBaseTempEntity::CBaseTempEntity(this: &g_TESmoke, name: "Smoke");
  g_TESmoke.__vftable = (CTESmoke_vtbl *)&CTESmoke::`vftable';
  if ( g_TESmoke.m_vecOrigin.m_Value.x != 0.0
    || g_TESmoke.m_vecOrigin.m_Value.y != 0.0
    || g_TESmoke.m_vecOrigin.m_Value.z != 0.0 )
  {
    g_TESmoke.m_vecOrigin.m_Value.x = 0.0;
    g_TESmoke.m_vecOrigin.m_Value.y = 0.0;
    g_TESmoke.m_vecOrigin.m_Value.z = 0.0;
  }
  if ( g_TESmoke.m_nModelIndex.m_Value != 0 )
    g_TESmoke.m_nModelIndex.m_Value = 0;
  if ( g_TESmoke.m_fScale.m_Value != 0.0 )
    g_TESmoke.m_fScale.m_Value = 0.0;
  if ( g_TESmoke.m_nFrameRate.m_Value != 0 )
    g_TESmoke.m_nFrameRate.m_Value = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_TESmoke__);
}

//------------------------------------------------------------------------------
// Address: 0x10417810
// Name: _dynamic_initializer_for__g_CTESparks_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CTESparks_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CTESparks_ClassReg,
           pNetworkName: "CTESparks",
           pTable: &DT_TESparks::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x104228F0
// Name: _dynamic_atexit_destructor_for__g_TESmoke__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TESmoke__()
{
  g_TESmoke.__vftable = (CTESmoke_vtbl *)&CTESmoke::`vftable';
  CBaseTempEntity::~CBaseTempEntity(this: &g_TESmoke);
}

//------------------------------------------------------------------------------
// Address: 0x10422910
// Name: _ServerClassInit_DT_TESmoke::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_TESmoke::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_357;
  for ( i = 5; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}
