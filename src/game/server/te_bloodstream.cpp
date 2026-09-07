// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/te_bloodstream.cpp
// Functions: 10
// ============================================================

#include "game\server\te_bloodstream.h"

//------------------------------------------------------------------------------
// Address: 0x1032E770
// Name: public: virtual class ServerClass __near * CTEBloodStream::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CTEBloodStream::GetServerClass(CTEBloodStream *this)
{
  return &g_CTEBloodStream_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x1032E920
// Name: public: virtual void CTEBloodStream::Test(class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTEBloodStream::Test(CTEBloodStream *this, const Vector *current_origin, const QAngle *current_angles)
{
  int v4; // eax
  float y; // xmm0_4
  float z; // xmm0_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  Vector *v10; // ecx
  CBroadcastRecipientFilter filter; // [esp+10h] [ebp-38h] BYREF
  Vector result; // [esp+30h] [ebp-18h] BYREF
  Vector forward; // [esp+3Ch] [ebp-Ch] BYREF

  if ( this->r.m_Value != 247 )
    this->r.m_Value = 247;
  if ( this->g.m_Value != 0 )
    this->g.m_Value = 0;
  if ( this->b.m_Value != 0 )
    this->b.m_Value = 0;
  if ( this->a.m_Value != 255 )
    this->a.m_Value = 255;
  v4 = random->RandomInt(this: random, a2: 50, a3: 150);
  if ( this->m_nAmount.m_Value != v4 )
    this->m_nAmount.m_Value = v4;
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
  v7 = (float)(forward.y * 50.0) + this->m_vecOrigin.m_Value.y;
  v8 = this->m_vecOrigin.m_Value.x + (float)(forward.x * 50.0);
  v9 = this->m_vecOrigin.m_Value.z + (float)(forward.z * 50.0);
  if ( this->m_vecOrigin.m_Value.x != v8 )
    this->m_vecOrigin.m_Value.x = v8;
  if ( this->m_vecOrigin.m_Value.y != v7 )
    this->m_vecOrigin.m_Value.y = v7;
  if ( this->m_vecOrigin.m_Value.z != v9 )
    this->m_vecOrigin.m_Value.z = v9;
  v10 = UTIL_RandomBloodVector(&result);
  if ( v10->x != this->m_vecDirection.m_Value.x
    || v10->y != this->m_vecDirection.m_Value.y
    || v10->z != this->m_vecDirection.m_Value.z )
  {
    this->m_vecDirection.m_Value.x = v10->x;
    this->m_vecDirection.m_Value.y = v10->y;
    this->m_vecDirection.m_Value.z = v10->z;
  }
  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CBroadcastRecipientFilter_vtbl *)&CBroadcastRecipientFilter::`vftable';
  CRecipientFilter::AddAllPlayers(this: &filter);
  ((void (__thiscall *)(CTEBloodStream *, CBroadcastRecipientFilter *, _DWORD))this->Create)(
    a1: this,
    a2: &filter,
    a3: 0);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x1032EAF0
// Name: void TE_BloodStream(class IRecipientFilter __near &,float,class Vector const __near *,class Vector const __near *,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_BloodStream(
        IRecipientFilter *filter,
        float delay,
        const Vector *org,
        CNetworkVectorBase<Vector,CTEBloodStream::NetworkVar_m_vecDirection> *dir,
        int r,
        int g,
        int b,
        int a,
        int amount)
{
  if ( g_TEBloodStream.m_vecOrigin.m_Value.x != org->x )
    g_TEBloodStream.m_vecOrigin.m_Value.x = org->x;
  if ( g_TEBloodStream.m_vecOrigin.m_Value.y != org->y )
    g_TEBloodStream.m_vecOrigin.m_Value.y = org->y;
  if ( g_TEBloodStream.m_vecOrigin.m_Value.z != org->z )
    g_TEBloodStream.m_vecOrigin.m_Value.z = org->z;
  if ( dir->m_Value.x != g_TEBloodStream.m_vecDirection.m_Value.x
    || dir->m_Value.y != g_TEBloodStream.m_vecDirection.m_Value.y
    || dir->m_Value.z != g_TEBloodStream.m_vecDirection.m_Value.z )
  {
    g_TEBloodStream.m_vecDirection = *dir;
  }
  if ( g_TEBloodStream.r.m_Value != r )
    g_TEBloodStream.r.m_Value = r;
  if ( g_TEBloodStream.g.m_Value != g )
    g_TEBloodStream.g.m_Value = g;
  if ( g_TEBloodStream.b.m_Value != b )
    g_TEBloodStream.b.m_Value = b;
  if ( g_TEBloodStream.a.m_Value != a )
    g_TEBloodStream.a.m_Value = a;
  if ( g_TEBloodStream.m_nAmount.m_Value != amount )
    g_TEBloodStream.m_nAmount.m_Value = amount;
  CBaseTempEntity::Create(this: &g_TEBloodStream, filter, delay);
}

//------------------------------------------------------------------------------
// Address: 0x104162A0
// Name: DT_TEBloodStream::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEBloodStream::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_TEBloodStream::g_SendTable);
  return atexit(func: DT_TEBloodStream::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104162C0
// Name: DT_TEBloodStream::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEBloodStream::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_TEBloodStream::ignored>();
  DT_TEBloodStream::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10422140
// Name: DT_TEBloodStream::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEBloodStream::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_TEBloodStream::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x104162D0
// Name: _dynamic_initializer_for__g_TEBloodStream__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TEBloodStream__()
{
  CBaseTempEntity::CBaseTempEntity(this: &g_TEBloodStream, name: "Blood Stream");
  g_TEBloodStream.m_vecOrigin.m_Value.x = 0.0;
  g_TEBloodStream.m_vecOrigin.m_Value.y = 0.0;
  g_TEBloodStream.m_vecOrigin.m_Value.z = 0.0;
  g_TEBloodStream.__vftable = (CTEBloodStream_vtbl *)&CTEBloodStream::`vftable';
  if ( g_TEBloodStream.m_vecDirection.m_Value.x != 0.0
    || g_TEBloodStream.m_vecDirection.m_Value.y != 0.0
    || g_TEBloodStream.m_vecDirection.m_Value.z != 0.0 )
  {
    g_TEBloodStream.m_vecDirection.m_Value.x = 0.0;
    g_TEBloodStream.m_vecDirection.m_Value.y = 0.0;
    g_TEBloodStream.m_vecDirection.m_Value.z = 0.0;
  }
  if ( g_TEBloodStream.r.m_Value != 0 )
    g_TEBloodStream.r.m_Value = 0;
  if ( g_TEBloodStream.g.m_Value != 0 )
    g_TEBloodStream.g.m_Value = 0;
  if ( g_TEBloodStream.b.m_Value != 0 )
    g_TEBloodStream.b.m_Value = 0;
  if ( g_TEBloodStream.a.m_Value != 0 )
    g_TEBloodStream.a.m_Value = 0;
  if ( g_TEBloodStream.m_nAmount.m_Value != 0 )
    g_TEBloodStream.m_nAmount.m_Value = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_TEBloodStream__);
}

//------------------------------------------------------------------------------
// Address: 0x104163A0
// Name: _dynamic_initializer_for__g_CTEBreakModel_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CTEBreakModel_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CTEBreakModel_ClassReg,
           pNetworkName: "CTEBreakModel",
           pTable: &DT_TEBreakModel::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10422150
// Name: _dynamic_atexit_destructor_for__g_TEBloodStream__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TEBloodStream__()
{
  g_TEBloodStream.__vftable = (CTEBloodStream_vtbl *)&CTEBloodStream::`vftable';
  CBaseTempEntity::~CBaseTempEntity(this: &g_TEBloodStream);
}

//------------------------------------------------------------------------------
// Address: 0x10422170
// Name: _ServerClassInit_DT_TEBloodStream::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_TEBloodStream::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_332;
  for ( i = 7; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}
