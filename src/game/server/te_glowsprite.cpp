// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/te_glowsprite.cpp
// Functions: 10
// ============================================================

#include "game\server\te_glowsprite.h"

//------------------------------------------------------------------------------
// Address: 0x103327F0
// Name: public: virtual class ServerClass __near * CTEGlowSprite::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CTEGlowSprite::GetServerClass(CTEGlowSprite *this)
{
  return &g_CTEGlowSprite_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x103329B0
// Name: public: virtual void CTEGlowSprite::Test(class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTEGlowSprite::Test(
        CTEGlowSprite *this,
        CNetworkVectorBase<Vector,CTEGlowSprite::NetworkVar_m_vecOrigin> *current_origin,
        const QAngle *current_angles)
{
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  CBroadcastRecipientFilter filter; // [esp+8h] [ebp-38h] BYREF
  Vector right; // [esp+28h] [ebp-18h] BYREF
  Vector forward; // [esp+34h] [ebp-Ch] BYREF

  if ( this->m_nModelIndex.m_Value != g_sModelIndexSmoke )
    this->m_nModelIndex.m_Value = g_sModelIndexSmoke;
  if ( this->m_fScale.m_Value != 0.80000001 )
    this->m_fScale.m_Value = 0.80000001;
  if ( this->m_nBrightness.m_Value != 200 )
    this->m_nBrightness.m_Value = 200;
  if ( this->m_fLife.m_Value != 2.0 )
    this->m_fLife.m_Value = 2.0;
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
  v4 = right.y * 25.0;
  this->m_vecOrigin.m_Value.x = this->m_vecOrigin.m_Value.x - (float)(right.x * 25.0);
  v5 = this->m_vecOrigin.m_Value.y - v4;
  v6 = right.z * 25.0;
  this->m_vecOrigin.m_Value.y = v5;
  this->m_vecOrigin.m_Value.z = this->m_vecOrigin.m_Value.z - v6;
  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CBroadcastRecipientFilter_vtbl *)&CBroadcastRecipientFilter::`vftable';
  CRecipientFilter::AddAllPlayers(this: &filter);
  ((void (__thiscall *)(CTEGlowSprite *, CBroadcastRecipientFilter *, _DWORD))this->Create)(
    a1: this,
    a2: &filter,
    a3: 0);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x10332B50
// Name: void TE_GlowSprite(class IRecipientFilter __near &,float,class Vector const __near *,int,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_GlowSprite(
        IRecipientFilter *filter,
        float delay,
        CNetworkVectorBase<Vector,CTEGlowSprite::NetworkVar_m_vecOrigin> *pos,
        int modelindex,
        float life,
        float size,
        int brightness)
{
  if ( pos->m_Value.x != g_TEGlowSprite.m_vecOrigin.m_Value.x
    || pos->m_Value.y != g_TEGlowSprite.m_vecOrigin.m_Value.y
    || pos->m_Value.z != g_TEGlowSprite.m_vecOrigin.m_Value.z )
  {
    g_TEGlowSprite.m_vecOrigin = *pos;
  }
  if ( g_TEGlowSprite.m_nModelIndex.m_Value != modelindex )
    g_TEGlowSprite.m_nModelIndex.m_Value = modelindex;
  if ( g_TEGlowSprite.m_fLife.m_Value != life )
    g_TEGlowSprite.m_fLife.m_Value = life;
  if ( g_TEGlowSprite.m_fScale.m_Value != size )
    g_TEGlowSprite.m_fScale.m_Value = size;
  if ( g_TEGlowSprite.m_nBrightness.m_Value != brightness )
    g_TEGlowSprite.m_nBrightness.m_Value = brightness;
  CBaseTempEntity::Create(this: &g_TEGlowSprite, filter, delay);
}

//------------------------------------------------------------------------------
// Address: 0x10416F20
// Name: DT_TEGlowSprite::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEGlowSprite::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_TEGlowSprite::g_SendTable);
  return atexit(func: DT_TEGlowSprite::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10416F40
// Name: DT_TEGlowSprite::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEGlowSprite::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_TEGlowSprite::ignored>();
  DT_TEGlowSprite::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104225E0
// Name: DT_TEGlowSprite::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEGlowSprite::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_TEGlowSprite::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10416F50
// Name: _dynamic_initializer_for__g_TEGlowSprite__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TEGlowSprite__()
{
  CBaseTempEntity::CBaseTempEntity(this: &g_TEGlowSprite, name: "GlowSprite");
  g_TEGlowSprite.__vftable = (CTEGlowSprite_vtbl *)&CTEGlowSprite::`vftable';
  if ( g_TEGlowSprite.m_vecOrigin.m_Value.x != 0.0
    || g_TEGlowSprite.m_vecOrigin.m_Value.y != 0.0
    || g_TEGlowSprite.m_vecOrigin.m_Value.z != 0.0 )
  {
    g_TEGlowSprite.m_vecOrigin.m_Value.x = 0.0;
    g_TEGlowSprite.m_vecOrigin.m_Value.y = 0.0;
    g_TEGlowSprite.m_vecOrigin.m_Value.z = 0.0;
  }
  if ( g_TEGlowSprite.m_nModelIndex.m_Value != 0 )
    g_TEGlowSprite.m_nModelIndex.m_Value = 0;
  if ( g_TEGlowSprite.m_fScale.m_Value != 0.0 )
    g_TEGlowSprite.m_fScale.m_Value = 0.0;
  if ( g_TEGlowSprite.m_fLife.m_Value != 0.0 )
    g_TEGlowSprite.m_fLife.m_Value = 0.0;
  if ( g_TEGlowSprite.m_nBrightness.m_Value != 0 )
    g_TEGlowSprite.m_nBrightness.m_Value = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_TEGlowSprite__);
}

//------------------------------------------------------------------------------
// Address: 0x10417010
// Name: _dynamic_initializer_for__g_CTEImpact_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CTEImpact_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CTEImpact_ClassReg,
           pNetworkName: "CTEImpact",
           pTable: &DT_TEImpact::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x104225F0
// Name: _dynamic_atexit_destructor_for__g_TEGlowSprite__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TEGlowSprite__()
{
  g_TEGlowSprite.__vftable = (CTEGlowSprite_vtbl *)&CTEGlowSprite::`vftable';
  CBaseTempEntity::~CBaseTempEntity(this: &g_TEGlowSprite);
}

//------------------------------------------------------------------------------
// Address: 0x10422610
// Name: _ServerClassInit_DT_TEGlowSprite::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_TEGlowSprite::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_347;
  for ( i = 6; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}
