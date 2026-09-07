// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/te_dynamiclight.cpp
// Functions: 11
// ============================================================

#include "game\server\te_dynamiclight.h"

//------------------------------------------------------------------------------
// Address: 0x10330890
// Name: public: virtual class ServerClass __near * CTEDynamicLight::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CTEDynamicLight::GetServerClass(CTEDynamicLight *this)
{
  return &g_CTEDynamicLight_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10330AD0
// Name: public: CTEDynamicLight::CTEDynamicLight(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CTEDynamicLight *__thiscall CTEDynamicLight::CTEDynamicLight(CTEDynamicLight *this, const char *name)
{
  CTEDynamicLight *result; // eax

  CBaseTempEntity::CBaseTempEntity(this, name);
  this->__vftable = (CTEDynamicLight_vtbl *)&CTEDynamicLight::`vftable';
  if ( this->m_vecOrigin.m_Value.x != 0.0 || this->m_vecOrigin.m_Value.y != 0.0 || this->m_vecOrigin.m_Value.z != 0.0 )
  {
    this->m_vecOrigin.m_Value.x = 0.0;
    this->m_vecOrigin.m_Value.y = 0.0;
    this->m_vecOrigin.m_Value.z = 0.0;
  }
  if ( this->r.m_Value != 0 )
    this->r.m_Value = 0;
  if ( this->g.m_Value != 0 )
    this->g.m_Value = 0;
  if ( this->b.m_Value != 0 )
    this->b.m_Value = 0;
  if ( this->exponent.m_Value != 0 )
    this->exponent.m_Value = 0;
  if ( this->m_fRadius.m_Value != 0.0 )
    this->m_fRadius.m_Value = 0.0;
  if ( this->m_fTime.m_Value != 0.0 )
    this->m_fTime.m_Value = 0.0;
  result = this;
  if ( this->m_fDecay.m_Value != 0.0 )
    this->m_fDecay.m_Value = 0.0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10330B80
// Name: public: virtual void CTEDynamicLight::Test(class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTEDynamicLight::Test(
        CTEDynamicLight *this,
        CNetworkVectorBase<Vector,CTEDynamicLight::NetworkVar_m_vecOrigin> *current_origin,
        const QAngle *current_angles)
{
  CBroadcastRecipientFilter filter; // [esp+8h] [ebp-2Ch] BYREF
  Vector forward; // [esp+28h] [ebp-Ch] BYREF

  if ( this->r.m_Value != 255 )
    this->r.m_Value = 255;
  if ( this->g.m_Value != 255 )
    this->g.m_Value = 255;
  if ( this->b.m_Value != 63 )
    this->b.m_Value = 63;
  if ( current_origin->m_Value.x != this->m_vecOrigin.m_Value.x
    || current_origin->m_Value.y != this->m_vecOrigin.m_Value.y
    || current_origin->m_Value.z != this->m_vecOrigin.m_Value.z )
  {
    this->m_vecOrigin = *current_origin;
  }
  if ( this->m_fRadius.m_Value != 200.0 )
    this->m_fRadius.m_Value = 200.0;
  if ( this->m_fTime.m_Value != 2.0 )
    this->m_fTime.m_Value = 2.0;
  if ( this->m_fDecay.m_Value != 0.0 )
    this->m_fDecay.m_Value = 0.0;
  this->m_vecOrigin.m_Value.z = this->m_vecOrigin.m_Value.z + 24.0;
  AngleVectors(angles: current_angles, &forward);
  forward.z = 0.0;
  VectorNormalize(vec: &forward);
  this->m_vecOrigin.m_Value.x = (float)(forward.x * 50.0) + this->m_vecOrigin.m_Value.x;
  this->m_vecOrigin.m_Value.y = (float)(forward.y * 50.0) + this->m_vecOrigin.m_Value.y;
  this->m_vecOrigin.m_Value.z = (float)(forward.z * 50.0) + this->m_vecOrigin.m_Value.z;
  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CBroadcastRecipientFilter_vtbl *)&CBroadcastRecipientFilter::`vftable';
  CRecipientFilter::AddAllPlayers(this: &filter);
  ((void (__thiscall *)(CTEDynamicLight *, CBroadcastRecipientFilter *, _DWORD))this->Create)(
    a1: this,
    a2: &filter,
    a3: 0);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x10330CF0
// Name: void TE_DynamicLight(class IRecipientFilter __near &,float,class Vector const __near *,int,int,int,int,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_DynamicLight(
        IRecipientFilter *filter,
        float delay,
        CNetworkVectorBase<Vector,CTEDynamicLight::NetworkVar_m_vecOrigin> *org,
        int r,
        int g,
        int b,
        int exponent,
        float radius,
        float time,
        float decay)
{
  if ( org->m_Value.x != g_TEDynamicLight.m_vecOrigin.m_Value.x
    || org->m_Value.y != g_TEDynamicLight.m_vecOrigin.m_Value.y
    || org->m_Value.z != g_TEDynamicLight.m_vecOrigin.m_Value.z )
  {
    g_TEDynamicLight.m_vecOrigin = *org;
  }
  if ( g_TEDynamicLight.r.m_Value != r )
    g_TEDynamicLight.r.m_Value = r;
  if ( g_TEDynamicLight.g.m_Value != g )
    g_TEDynamicLight.g.m_Value = g;
  if ( g_TEDynamicLight.b.m_Value != b )
    g_TEDynamicLight.b.m_Value = b;
  if ( g_TEDynamicLight.exponent.m_Value != exponent )
    g_TEDynamicLight.exponent.m_Value = exponent;
  if ( g_TEDynamicLight.m_fRadius.m_Value != radius )
    g_TEDynamicLight.m_fRadius.m_Value = radius;
  if ( g_TEDynamicLight.m_fTime.m_Value != time )
    g_TEDynamicLight.m_fTime.m_Value = time;
  if ( g_TEDynamicLight.m_fDecay.m_Value != decay )
    g_TEDynamicLight.m_fDecay.m_Value = decay;
  CBaseTempEntity::Create(this: &g_TEDynamicLight, filter, delay);
}

//------------------------------------------------------------------------------
// Address: 0x10416900
// Name: DT_TEDynamicLight::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEDynamicLight::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_TEDynamicLight::g_SendTable);
  return atexit(func: DT_TEDynamicLight::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10416920
// Name: DT_TEDynamicLight::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEDynamicLight::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_TEDynamicLight::ignored>();
  DT_TEDynamicLight::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10422370
// Name: DT_TEDynamicLight::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEDynamicLight::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_TEDynamicLight::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10416930
// Name: _dynamic_initializer_for__g_TEDynamicLight__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TEDynamicLight__()
{
  CTEDynamicLight::CTEDynamicLight(this: &g_TEDynamicLight, name: "Dynamic Light");
  return atexit(func: dynamic_atexit_destructor_for__g_TEDynamicLight__);
}

//------------------------------------------------------------------------------
// Address: 0x10416950
// Name: _dynamic_initializer_for__g_CTEEffectDispatch_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CTEEffectDispatch_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CTEEffectDispatch_ClassReg,
           pNetworkName: "CTEEffectDispatch",
           pTable: &DT_TEEffectDispatch::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10422380
// Name: _dynamic_atexit_destructor_for__g_TEDynamicLight__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TEDynamicLight__()
{
  g_TEDynamicLight.__vftable = (CTEDynamicLight_vtbl *)&CTEDynamicLight::`vftable';
  CBaseTempEntity::~CBaseTempEntity(this: &g_TEDynamicLight);
}

//------------------------------------------------------------------------------
// Address: 0x104223A0
// Name: _ServerClassInit_DT_TEDynamicLight::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_TEDynamicLight::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_339;
  for ( i = 9; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}
