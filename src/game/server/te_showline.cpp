// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/te_showline.cpp
// Functions: 10
// ============================================================

#include "game\server\te_showline.h"

//------------------------------------------------------------------------------
// Address: 0x10334270
// Name: public: virtual class ServerClass __near * CTEShowLine::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CTEShowLine::GetServerClass(CTEShowLine *this)
{
  return &g_CTEShowLine_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10334370
// Name: public: virtual void CTEShowLine::Test(class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTEShowLine::Test(CTEShowLine *this, const Vector *current_origin, const QAngle *current_angles)
{
  float y; // xmm0_4
  float z; // xmm0_4
  float x; // xmm2_4
  float v7; // xmm3_4
  float v8; // xmm4_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm6_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  CBroadcastRecipientFilter filter; // [esp+8h] [ebp-38h] BYREF
  Vector right; // [esp+28h] [ebp-18h] BYREF
  Vector forward; // [esp+34h] [ebp-Ch] BYREF

  if ( this->m_vecOrigin.m_Value.x != current_origin->x )
    this->m_vecOrigin.m_Value.x = current_origin->x;
  y = current_origin->y;
  if ( this->m_vecOrigin.m_Value.y != y )
    this->m_vecOrigin.m_Value.y = y;
  z = current_origin->z;
  if ( this->m_vecOrigin.m_Value.z != z )
    this->m_vecOrigin.m_Value.z = z;
  this->m_vecOrigin.m_Value.z = this->m_vecOrigin.m_Value.z + 24.0;
  AngleVectors(angles: current_angles, &forward, &right, up: nullptr);
  forward.z = 0.0;
  VectorNormalize(vec: &forward);
  x = right.x;
  v7 = right.y;
  v8 = right.z;
  this->m_vecEnd.m_Value.x = (float)(forward.x * 100.0) + this->m_vecOrigin.m_Value.x;
  this->m_vecEnd.m_Value.y = (float)(forward.y * 100.0) + this->m_vecOrigin.m_Value.y;
  this->m_vecEnd.m_Value.z = (float)(forward.z * 100.0) + this->m_vecOrigin.m_Value.z;
  v9 = (float)(x * -128.0) + this->m_vecEnd.m_Value.x;
  v10 = (float)(v8 * -128.0) + this->m_vecEnd.m_Value.z;
  v11 = this->m_vecEnd.m_Value.y + (float)(v7 * -128.0);
  if ( this->m_vecOrigin.m_Value.x != v9 )
    this->m_vecOrigin.m_Value.x = v9;
  if ( this->m_vecOrigin.m_Value.y != v11 )
    this->m_vecOrigin.m_Value.y = v11;
  if ( this->m_vecOrigin.m_Value.z != v10 )
    this->m_vecOrigin.m_Value.z = v10;
  v12 = this->m_vecEnd.m_Value.x + (float)(x * 128.0);
  v13 = this->m_vecEnd.m_Value.y + (float)(v7 * 128.0);
  v14 = this->m_vecEnd.m_Value.z + (float)(v8 * 128.0);
  if ( v12 != this->m_vecEnd.m_Value.x || v13 != this->m_vecEnd.m_Value.y || v14 != this->m_vecEnd.m_Value.z )
  {
    this->m_vecEnd.m_Value.x = v12;
    this->m_vecEnd.m_Value.y = v13;
    this->m_vecEnd.m_Value.z = v14;
  }
  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CBroadcastRecipientFilter_vtbl *)&CBroadcastRecipientFilter::`vftable';
  CRecipientFilter::AddAllPlayers(this: &filter);
  ((void (__thiscall *)(CTEShowLine *, CBroadcastRecipientFilter *, _DWORD))this->Create)(a1: this, a2: &filter, a3: 0);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x10334560
// Name: void TE_ShowLine(class IRecipientFilter __near &,float,class Vector const __near *,class Vector const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_ShowLine(
        IRecipientFilter *filter,
        float delay,
        const Vector *start,
        CNetworkVectorBase<Vector,CTEShowLine::NetworkVar_m_vecEnd> *end)
{
  if ( g_TEShowLine.m_vecOrigin.m_Value.x != start->x )
    g_TEShowLine.m_vecOrigin.m_Value.x = start->x;
  if ( g_TEShowLine.m_vecOrigin.m_Value.y != start->y )
    g_TEShowLine.m_vecOrigin.m_Value.y = start->y;
  if ( g_TEShowLine.m_vecOrigin.m_Value.z != start->z )
    g_TEShowLine.m_vecOrigin.m_Value.z = start->z;
  if ( end->m_Value.x != g_TEShowLine.m_vecEnd.m_Value.x
    || end->m_Value.y != g_TEShowLine.m_vecEnd.m_Value.y
    || end->m_Value.z != g_TEShowLine.m_vecEnd.m_Value.z )
  {
    g_TEShowLine.m_vecEnd = *end;
  }
  CBaseTempEntity::Create(this: &g_TEShowLine, filter, delay);
}

//------------------------------------------------------------------------------
// Address: 0x10417670
// Name: DT_TEShowLine::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEShowLine::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_TEShowLine::g_SendTable);
  return atexit(func: DT_TEShowLine::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10417690
// Name: DT_TEShowLine::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEShowLine::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_TEShowLine::ignored>();
  DT_TEShowLine::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10422890
// Name: DT_TEShowLine::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEShowLine::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_TEShowLine::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x104176A0
// Name: _dynamic_initializer_for__g_TEShowLine__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TEShowLine__()
{
  CBaseTempEntity::CBaseTempEntity(this: &g_TEShowLine, name: "Show Line");
  g_TEShowLine.m_vecOrigin.m_Value.x = 0.0;
  g_TEShowLine.m_vecOrigin.m_Value.y = 0.0;
  g_TEShowLine.m_vecOrigin.m_Value.z = 0.0;
  g_TEShowLine.__vftable = (CTEShowLine_vtbl *)&CTEShowLine::`vftable';
  if ( g_TEShowLine.m_vecEnd.m_Value.x != 0.0
    || g_TEShowLine.m_vecEnd.m_Value.y != 0.0
    || g_TEShowLine.m_vecEnd.m_Value.z != 0.0 )
  {
    g_TEShowLine.m_vecEnd.m_Value.x = 0.0;
    g_TEShowLine.m_vecEnd.m_Value.y = 0.0;
    g_TEShowLine.m_vecEnd.m_Value.z = 0.0;
  }
  return atexit(func: dynamic_atexit_destructor_for__g_TEShowLine__);
}

//------------------------------------------------------------------------------
// Address: 0x10417720
// Name: _dynamic_initializer_for__g_CTESmoke_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CTESmoke_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CTESmoke_ClassReg,
           pNetworkName: "CTESmoke",
           pTable: &DT_TESmoke::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x104228A0
// Name: _dynamic_atexit_destructor_for__g_TEShowLine__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TEShowLine__()
{
  g_TEShowLine.__vftable = (CTEShowLine_vtbl *)&CTEShowLine::`vftable';
  CBaseTempEntity::~CBaseTempEntity(this: &g_TEShowLine);
}

//------------------------------------------------------------------------------
// Address: 0x104228C0
// Name: _ServerClassInit_DT_TEShowLine::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_TEShowLine::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_356;
  for ( i = 2; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}
