// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/te_sprite.cpp
// Functions: 11
// ============================================================

#include "game\server\te_sprite.h"

//------------------------------------------------------------------------------
// Address: 0x10334DE0
// Name: public: virtual void CTESprite::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CTESprite::Precache(CTESprite *this@<ecx>, bool (__cdecl *a2)(const char *)@<edi>)
{
  CBaseEntity::PrecacheModel(a1: a2, name: "sprites/gunsmoke.vmt", bPreload: true);
}

//------------------------------------------------------------------------------
// Address: 0x10334DF0
// Name: public: virtual class ServerClass __near * CTESprite::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CTESprite::GetServerClass(CTESprite *this)
{
  return &g_CTESprite_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10334F70
// Name: public: virtual void CTESprite::Test(class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CTESprite::Test(
        CTESprite *this@<ecx>,
        bool (__cdecl *a2)(const char *)@<edi>,
        const Vector *current_origin,
        const QAngle *current_angles)
{
  int v5; // eax
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm1_4
  CBroadcastRecipientFilter filter; // [esp+8h] [ebp-38h] BYREF
  Vector right; // [esp+28h] [ebp-18h] BYREF
  Vector forward; // [esp+34h] [ebp-Ch] BYREF

  v5 = CBaseEntity::PrecacheModel(a1: a2, name: "sprites/gunsmoke.vmt", bPreload: true);
  if ( this->m_nModelIndex.m_Value != v5 )
    this->m_nModelIndex.m_Value = v5;
  if ( this->m_fScale.m_Value != 0.80000001 )
    this->m_fScale.m_Value = 0.80000001;
  if ( this->m_nBrightness.m_Value != 200 )
    this->m_nBrightness.m_Value = 200;
  if ( current_origin->x != this->m_vecOrigin.m_Value.x
    || current_origin->y != this->m_vecOrigin.m_Value.y
    || current_origin->z != this->m_vecOrigin.m_Value.z )
  {
    this->m_vecOrigin.m_Value = *current_origin;
  }
  this->m_vecOrigin.m_Value.z = this->m_vecOrigin.m_Value.z + 24.0;
  AngleVectors(angles: current_angles, &forward, &right, up: nullptr);
  forward.z = 0.0;
  VectorNormalize(vec: &forward);
  this->m_vecOrigin.m_Value.x = (float)(forward.x * 50.0) + this->m_vecOrigin.m_Value.x;
  this->m_vecOrigin.m_Value.y = (float)(forward.y * 50.0) + this->m_vecOrigin.m_Value.y;
  this->m_vecOrigin.m_Value.z = (float)(forward.z * 50.0) + this->m_vecOrigin.m_Value.z;
  v6 = right.y * 25.0;
  this->m_vecOrigin.m_Value.x = this->m_vecOrigin.m_Value.x - (float)(right.x * 25.0);
  v7 = this->m_vecOrigin.m_Value.y - v6;
  v8 = right.z * 25.0;
  this->m_vecOrigin.m_Value.y = v7;
  this->m_vecOrigin.m_Value.z = this->m_vecOrigin.m_Value.z - v8;
  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CBroadcastRecipientFilter_vtbl *)&CBroadcastRecipientFilter::`vftable';
  CRecipientFilter::AddAllPlayers(this: &filter);
  ((void (__thiscall *)(CTESprite *, CBroadcastRecipientFilter *, _DWORD))this->Create)(a1: this, a2: &filter, a3: 0);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x10335100
// Name: void TE_Sprite(class IRecipientFilter __near &,float,class Vector const __near *,int,float,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_Sprite(
        IRecipientFilter *filter,
        float delay,
        CNetworkVectorBase<Vector,CTESprite::NetworkVar_m_vecOrigin> *pos,
        int modelindex,
        float size,
        int brightness)
{
  if ( pos->m_Value.x != g_TESprite.m_vecOrigin.m_Value.x
    || pos->m_Value.y != g_TESprite.m_vecOrigin.m_Value.y
    || pos->m_Value.z != g_TESprite.m_vecOrigin.m_Value.z )
  {
    g_TESprite.m_vecOrigin = *pos;
  }
  if ( g_TESprite.m_nModelIndex.m_Value != modelindex )
    g_TESprite.m_nModelIndex.m_Value = modelindex;
  if ( g_TESprite.m_fScale.m_Value != size )
    g_TESprite.m_fScale.m_Value = size;
  if ( g_TESprite.m_nBrightness.m_Value != brightness )
    g_TESprite.m_nBrightness.m_Value = brightness;
  CBaseTempEntity::Create(this: &g_TESprite, filter, delay);
}

//------------------------------------------------------------------------------
// Address: 0x104178C0
// Name: DT_TESprite::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TESprite::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_TESprite::g_SendTable);
  return atexit(func: DT_TESprite::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104178E0
// Name: DT_TESprite::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TESprite::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_TESprite::ignored>();
  DT_TESprite::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10422980
// Name: DT_TESprite::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TESprite::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_TESprite::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x104178F0
// Name: _dynamic_initializer_for__g_TESprite__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TESprite__()
{
  CBaseTempEntity::CBaseTempEntity(this: &g_TESprite, name: "Sprite");
  g_TESprite.__vftable = (CTESprite_vtbl *)&CTESprite::`vftable';
  if ( g_TESprite.m_vecOrigin.m_Value.x != 0.0
    || g_TESprite.m_vecOrigin.m_Value.y != 0.0
    || g_TESprite.m_vecOrigin.m_Value.z != 0.0 )
  {
    g_TESprite.m_vecOrigin.m_Value.x = 0.0;
    g_TESprite.m_vecOrigin.m_Value.y = 0.0;
    g_TESprite.m_vecOrigin.m_Value.z = 0.0;
  }
  if ( g_TESprite.m_nModelIndex.m_Value != 0 )
    g_TESprite.m_nModelIndex.m_Value = 0;
  if ( g_TESprite.m_fScale.m_Value != 0.0 )
    g_TESprite.m_fScale.m_Value = 0.0;
  if ( g_TESprite.m_nBrightness.m_Value != 0 )
    g_TESprite.m_nBrightness.m_Value = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_TESprite__);
}

//------------------------------------------------------------------------------
// Address: 0x10417990
// Name: _dynamic_initializer_for__g_CTESpriteSpray_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CTESpriteSpray_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CTESpriteSpray_ClassReg,
           pNetworkName: "CTESpriteSpray",
           pTable: &DT_TESpriteSpray::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10422990
// Name: _dynamic_atexit_destructor_for__g_TESprite__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TESprite__()
{
  g_TESprite.__vftable = (CTESprite_vtbl *)&CTESprite::`vftable';
  CBaseTempEntity::~CBaseTempEntity(this: &g_TESprite);
}

//------------------------------------------------------------------------------
// Address: 0x104229B0
// Name: _ServerClassInit_DT_TESprite::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_TESprite::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_359;
  for ( i = 5; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}
