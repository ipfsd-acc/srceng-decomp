// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/te_projecteddecal.cpp
// Functions: 10
// ============================================================

#include "game\server\te_projecteddecal.h"

//------------------------------------------------------------------------------
// Address: 0x10333E90
// Name: public: virtual class ServerClass __near * CTEProjectedDecal::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CTEProjectedDecal::GetServerClass(CTEProjectedDecal *this)
{
  return &g_CTEProjectedDecal_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10334010
// Name: public: virtual void CTEProjectedDecal::Test(class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CTEProjectedDecal::Test(
        CTEProjectedDecal *this@<ecx>,
        int a2@<esi>,
        CNetworkVectorBase<Vector,CTEProjectedDecal::NetworkVar_m_vecOrigin> *current_origin,
        CNetworkVectorBase<QAngle,CTEProjectedDecal::NetworkVar_m_angRotation> *current_angles)
{
  CBroadcastRecipientFilter filter; // [esp+8h] [ebp-2Ch] BYREF
  Vector forward; // [esp+28h] [ebp-Ch] BYREF

  if ( this->m_flDistance.m_Value != 1024.0 )
    this->m_flDistance.m_Value = 1024.0;
  if ( this->m_nIndex.m_Value != 0 )
    this->m_nIndex.m_Value = 0;
  if ( current_origin->m_Value.x != this->m_vecOrigin.m_Value.x
    || current_origin->m_Value.y != this->m_vecOrigin.m_Value.y
    || current_origin->m_Value.z != this->m_vecOrigin.m_Value.z )
  {
    this->m_vecOrigin = *current_origin;
  }
  if ( current_angles->m_Value.x != this->m_angRotation.m_Value.x
    || current_angles->m_Value.y != this->m_angRotation.m_Value.y
    || current_angles->m_Value.z != this->m_angRotation.m_Value.z )
  {
    this->m_angRotation = *current_angles;
  }
  this->m_vecOrigin.m_Value.z = this->m_vecOrigin.m_Value.z + 24.0;
  AngleVectors(angles: &current_angles->m_Value, &forward);
  forward.z = 0.0;
  VectorNormalize(vec: &forward);
  this->m_vecOrigin.m_Value.x = (float)(forward.x * 24.0) + this->m_vecOrigin.m_Value.x;
  this->m_vecOrigin.m_Value.y = (float)(forward.y * 24.0) + this->m_vecOrigin.m_Value.y;
  this->m_vecOrigin.m_Value.z = (float)(forward.z * 24.0) + this->m_vecOrigin.m_Value.z;
  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CBroadcastRecipientFilter_vtbl *)&CBroadcastRecipientFilter::`vftable';
  CRecipientFilter::AddAllPlayers(this: &filter);
  ((void (__thiscall *)(CTEProjectedDecal *, CBroadcastRecipientFilter *, _DWORD, int))this->Create)(
    a1: this,
    a2: &filter,
    a3: 0,
    a4: a2);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x10334170
// Name: void TE_ProjectDecal(class IRecipientFilter __near &,float,class Vector const __near *,class QAngle const __near *,float,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_ProjectDecal(
        IRecipientFilter *filter,
        float delay,
        CNetworkVectorBase<Vector,CTEProjectedDecal::NetworkVar_m_vecOrigin> *pos,
        CNetworkVectorBase<QAngle,CTEProjectedDecal::NetworkVar_m_angRotation> *angles,
        float distance,
        int index)
{
  if ( pos->m_Value.x != g_TEProjectedDecal.m_vecOrigin.m_Value.x
    || pos->m_Value.y != g_TEProjectedDecal.m_vecOrigin.m_Value.y
    || pos->m_Value.z != g_TEProjectedDecal.m_vecOrigin.m_Value.z )
  {
    g_TEProjectedDecal.m_vecOrigin = *pos;
  }
  if ( angles->m_Value.x != g_TEProjectedDecal.m_angRotation.m_Value.x
    || angles->m_Value.y != g_TEProjectedDecal.m_angRotation.m_Value.y
    || angles->m_Value.z != g_TEProjectedDecal.m_angRotation.m_Value.z )
  {
    g_TEProjectedDecal.m_angRotation = *angles;
  }
  if ( g_TEProjectedDecal.m_flDistance.m_Value != distance )
    g_TEProjectedDecal.m_flDistance.m_Value = distance;
  if ( g_TEProjectedDecal.m_nIndex.m_Value != index )
    g_TEProjectedDecal.m_nIndex.m_Value = index;
  CBaseTempEntity::Create(this: &g_TEProjectedDecal, filter, delay);
}

//------------------------------------------------------------------------------
// Address: 0x10417540
// Name: DT_TEProjectedDecal::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEProjectedDecal::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_TEProjectedDecal::g_SendTable);
  return atexit(func: DT_TEProjectedDecal::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10417560
// Name: DT_TEProjectedDecal::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEProjectedDecal::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_TEProjectedDecal::ignored>();
  DT_TEProjectedDecal::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10422840
// Name: DT_TEProjectedDecal::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEProjectedDecal::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_TEProjectedDecal::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10417570
// Name: _dynamic_initializer_for__g_TEProjectedDecal__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TEProjectedDecal__()
{
  CBaseTempEntity::CBaseTempEntity(this: &g_TEProjectedDecal, name: "Projected Decal");
  g_TEProjectedDecal.__vftable = (CTEProjectedDecal_vtbl *)&CTEProjectedDecal::`vftable';
  if ( g_TEProjectedDecal.m_vecOrigin.m_Value.x != 0.0
    || g_TEProjectedDecal.m_vecOrigin.m_Value.y != 0.0
    || g_TEProjectedDecal.m_vecOrigin.m_Value.z != 0.0 )
  {
    g_TEProjectedDecal.m_vecOrigin.m_Value.x = 0.0;
    g_TEProjectedDecal.m_vecOrigin.m_Value.y = 0.0;
    g_TEProjectedDecal.m_vecOrigin.m_Value.z = 0.0;
  }
  if ( g_TEProjectedDecal.m_angRotation.m_Value.x != 0.0
    || g_TEProjectedDecal.m_angRotation.m_Value.y != 0.0
    || g_TEProjectedDecal.m_angRotation.m_Value.z != 0.0 )
  {
    g_TEProjectedDecal.m_angRotation.m_Value.x = 0.0;
    g_TEProjectedDecal.m_angRotation.m_Value.y = 0.0;
    g_TEProjectedDecal.m_angRotation.m_Value.z = 0.0;
  }
  if ( g_TEProjectedDecal.m_flDistance.m_Value != 64.0 )
    g_TEProjectedDecal.m_flDistance.m_Value = 64.0;
  if ( g_TEProjectedDecal.m_nIndex.m_Value != 0 )
    g_TEProjectedDecal.m_nIndex.m_Value = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_TEProjectedDecal__);
}

//------------------------------------------------------------------------------
// Address: 0x10417650
// Name: _dynamic_initializer_for__g_CTEShowLine_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CTEShowLine_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CTEShowLine_ClassReg,
           pNetworkName: "CTEShowLine",
           pTable: &DT_TEShowLine::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10422850
// Name: _dynamic_atexit_destructor_for__g_TEProjectedDecal__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TEProjectedDecal__()
{
  g_TEProjectedDecal.__vftable = (CTEProjectedDecal_vtbl *)&CTEProjectedDecal::`vftable';
  CBaseTempEntity::~CBaseTempEntity(this: &g_TEProjectedDecal);
}

//------------------------------------------------------------------------------
// Address: 0x10422870
// Name: _ServerClassInit_DT_TEProjectedDecal::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_TEProjectedDecal::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_355;
  for ( i = 5; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}
