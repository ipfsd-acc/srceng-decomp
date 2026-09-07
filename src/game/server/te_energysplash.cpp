// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/te_energysplash.cpp
// Functions: 10
// ============================================================

#include "game\server\te_energysplash.h"

//------------------------------------------------------------------------------
// Address: 0x10331070
// Name: public: virtual class ServerClass __near * CTEEnergySplash::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CTEEnergySplash::GetServerClass(CTEEnergySplash *this)
{
  return &g_CTEEnergySplash_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x103311B0
// Name: public: virtual void CTEEnergySplash::Test(class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTEEnergySplash::Test(
        CTEEnergySplash *this,
        CNetworkVectorBase<Vector,CTEEnergySplash::NetworkVar_m_vecPos> *current_origin,
        const QAngle *current_angles)
{
  CBroadcastRecipientFilter filter; // [esp+Ch] [ebp-2Ch] BYREF
  Vector forward; // [esp+2Ch] [ebp-Ch] BYREF

  if ( current_origin->m_Value.x != this->m_vecPos.m_Value.x
    || current_origin->m_Value.y != this->m_vecPos.m_Value.y
    || current_origin->m_Value.z != this->m_vecPos.m_Value.z )
  {
    this->m_vecPos = *current_origin;
  }
  AngleVectors(angles: current_angles, forward: &this->m_vecDir.m_Value);
  this->m_vecPos.m_Value.z = this->m_vecPos.m_Value.z + 24.0;
  forward.x = this->m_vecDir.m_Value.x;
  forward.y = this->m_vecDir.m_Value.y;
  forward.z = 0.0;
  VectorNormalize(vec: &forward);
  this->m_vecPos.m_Value.x = (float)(forward.x * 100.0) + this->m_vecPos.m_Value.x;
  this->m_vecPos.m_Value.y = (float)(forward.y * 100.0) + this->m_vecPos.m_Value.y;
  this->m_vecPos.m_Value.z = (float)(forward.z * 100.0) + this->m_vecPos.m_Value.z;
  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CBroadcastRecipientFilter_vtbl *)&CBroadcastRecipientFilter::`vftable';
  CRecipientFilter::AddAllPlayers(this: &filter);
  ((void (__thiscall *)(CTEEnergySplash *, CBroadcastRecipientFilter *, _DWORD))this->Create)(
    a1: this,
    a2: &filter,
    a3: 0);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x103312C0
// Name: void TE_EnergySplash(class IRecipientFilter __near &,float,class Vector const __near *,class Vector const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_EnergySplash(
        IRecipientFilter *filter,
        float delay,
        CNetworkVectorBase<Vector,CTEEnergySplash::NetworkVar_m_vecPos> *pos,
        CNetworkVectorBase<Vector,CTEEnergySplash::NetworkVar_m_vecDir> *dir,
        bool bExplosive)
{
  if ( pos->m_Value.x != g_TEEnergySplash.m_vecPos.m_Value.x
    || pos->m_Value.y != g_TEEnergySplash.m_vecPos.m_Value.y
    || pos->m_Value.z != g_TEEnergySplash.m_vecPos.m_Value.z )
  {
    g_TEEnergySplash.m_vecPos = *pos;
  }
  if ( dir->m_Value.x != g_TEEnergySplash.m_vecDir.m_Value.x
    || dir->m_Value.y != g_TEEnergySplash.m_vecDir.m_Value.y
    || dir->m_Value.z != g_TEEnergySplash.m_vecDir.m_Value.z )
  {
    g_TEEnergySplash.m_vecDir = *dir;
  }
  if ( g_TEEnergySplash.m_bExplosive.m_Value != bExplosive )
    g_TEEnergySplash.m_bExplosive.m_Value = bExplosive;
  CBaseTempEntity::Create(this: &g_TEEnergySplash, filter, delay);
}

//------------------------------------------------------------------------------
// Address: 0x10416AA0
// Name: DT_TEEnergySplash::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEEnergySplash::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_TEEnergySplash::g_SendTable);
  return atexit(func: DT_TEEnergySplash::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10416AC0
// Name: DT_TEEnergySplash::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEEnergySplash::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_TEEnergySplash::ignored>();
  DT_TEEnergySplash::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10422410
// Name: DT_TEEnergySplash::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEEnergySplash::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_TEEnergySplash::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10416AD0
// Name: _dynamic_initializer_for__g_TEEnergySplash__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TEEnergySplash__()
{
  CBaseTempEntity::CBaseTempEntity(this: &g_TEEnergySplash, name: "Energy Splash");
  g_TEEnergySplash.__vftable = (CTEEnergySplash_vtbl *)&CTEEnergySplash::`vftable';
  if ( g_TEEnergySplash.m_vecPos.m_Value.x != 0.0
    || g_TEEnergySplash.m_vecPos.m_Value.y != 0.0
    || g_TEEnergySplash.m_vecPos.m_Value.z != 0.0 )
  {
    g_TEEnergySplash.m_vecPos.m_Value.x = 0.0;
    g_TEEnergySplash.m_vecPos.m_Value.y = 0.0;
    g_TEEnergySplash.m_vecPos.m_Value.z = 0.0;
  }
  if ( g_TEEnergySplash.m_vecDir.m_Value.x != 0.0
    || g_TEEnergySplash.m_vecDir.m_Value.y != 0.0
    || g_TEEnergySplash.m_vecDir.m_Value.z != 0.0 )
  {
    g_TEEnergySplash.m_vecDir.m_Value.x = 0.0;
    g_TEEnergySplash.m_vecDir.m_Value.y = 0.0;
    g_TEEnergySplash.m_vecDir.m_Value.z = 0.0;
  }
  if ( g_TEEnergySplash.m_bExplosive.m_Value )
    g_TEEnergySplash.m_bExplosive.m_Value = false;
  return atexit(func: dynamic_atexit_destructor_for__g_TEEnergySplash__);
}

//------------------------------------------------------------------------------
// Address: 0x10416B90
// Name: _dynamic_initializer_for__g_CTEExplosion_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CTEExplosion_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CTEExplosion_ClassReg,
           pNetworkName: "CTEExplosion",
           pTable: &DT_TEExplosion::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10422420
// Name: _dynamic_atexit_destructor_for__g_TEEnergySplash__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TEEnergySplash__()
{
  g_TEEnergySplash.__vftable = (CTEEnergySplash_vtbl *)&CTEEnergySplash::`vftable';
  CBaseTempEntity::~CBaseTempEntity(this: &g_TEEnergySplash);
}

//------------------------------------------------------------------------------
// Address: 0x10422440
// Name: _ServerClassInit_DT_TEEnergySplash::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_TEEnergySplash::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_341;
  for ( i = 3; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}
