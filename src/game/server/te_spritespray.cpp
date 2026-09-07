// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/te_spritespray.cpp
// Functions: 11
// ============================================================

#include "game\server\te_spritespray.h"

//------------------------------------------------------------------------------
// Address: 0x103351C0
// Name: public: virtual class ServerClass __near * CTESpriteSpray::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CTESpriteSpray::GetServerClass(CTESpriteSpray *this)
{
  return &g_CTESpriteSpray_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x103353A0
// Name: public: CTESpriteSpray::CTESpriteSpray(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CTESpriteSpray *__thiscall CTESpriteSpray::CTESpriteSpray(CTESpriteSpray *this, const char *name)
{
  CTESpriteSpray *result; // eax

  CBaseTempEntity::CBaseTempEntity(this, name);
  this->__vftable = (CTESpriteSpray_vtbl *)&CTESpriteSpray::`vftable';
  if ( this->m_vecOrigin.m_Value.x != 0.0 || this->m_vecOrigin.m_Value.y != 0.0 || this->m_vecOrigin.m_Value.z != 0.0 )
  {
    this->m_vecOrigin.m_Value.x = 0.0;
    this->m_vecOrigin.m_Value.y = 0.0;
    this->m_vecOrigin.m_Value.z = 0.0;
  }
  if ( this->m_vecDirection.m_Value.x != 0.0
    || this->m_vecDirection.m_Value.y != 0.0
    || this->m_vecDirection.m_Value.z != 0.0 )
  {
    this->m_vecDirection.m_Value.x = 0.0;
    this->m_vecDirection.m_Value.y = 0.0;
    this->m_vecDirection.m_Value.z = 0.0;
  }
  if ( this->m_nModelIndex.m_Value != 0 )
    this->m_nModelIndex.m_Value = 0;
  if ( this->m_fNoise.m_Value != 0.0 )
    this->m_fNoise.m_Value = 0.0;
  if ( this->m_nSpeed.m_Value != 0 )
    this->m_nSpeed.m_Value = 0;
  result = this;
  if ( this->m_nCount.m_Value != 0 )
    this->m_nCount.m_Value = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10335450
// Name: public: virtual void CTESpriteSpray::Test(class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTESpriteSpray::Test(
        CTESpriteSpray *this,
        CNetworkVectorBase<Vector,CTESpriteSpray::NetworkVar_m_vecOrigin> *current_origin,
        const QAngle *current_angles)
{
  float y; // xmm1_4
  float v5; // xmm2_4
  float z; // xmm1_4
  float v7; // xmm0_4
  int (__thiscall *RandomInt)(IUniformRandomStream *, int, int); // eax
  float v9; // xmm0_4
  int (__thiscall *v10)(IUniformRandomStream *, int, int); // eax
  float v11; // xmm0_4
  CBroadcastRecipientFilter filter; // [esp+20h] [ebp-44h] BYREF
  Vector right; // [esp+40h] [ebp-24h] BYREF
  float v14; // [esp+4Ch] [ebp-18h]
  float v15; // [esp+50h] [ebp-14h]
  Vector forward; // [esp+58h] [ebp-Ch] BYREF

  if ( this->m_nModelIndex.m_Value != g_sModelIndexSmoke )
    this->m_nModelIndex.m_Value = g_sModelIndexSmoke;
  if ( this->m_fNoise.m_Value != 0.80000001 )
    this->m_fNoise.m_Value = 0.80000001;
  if ( this->m_nCount.m_Value != 5 )
    this->m_nCount.m_Value = 5;
  if ( this->m_nSpeed.m_Value != 30 )
    this->m_nSpeed.m_Value = 30;
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
  y = right.y;
  this->m_vecOrigin.m_Value.x = this->m_vecOrigin.m_Value.x - (float)(right.x * 25.0);
  v5 = this->m_vecOrigin.m_Value.y - (float)(y * 25.0);
  z = right.z;
  this->m_vecOrigin.m_Value.y = v5;
  this->m_vecOrigin.m_Value.z = this->m_vecOrigin.m_Value.z - (float)(z * 25.0);
  v7 = (float)random->RandomInt(this: random, a2: -100, a3: 100);
  RandomInt = random->RandomInt;
  v14 = v7;
  v9 = (float)RandomInt(this: random, a2: -100, a3: 100);
  v10 = random->RandomInt;
  v15 = v9;
  v11 = (float)v10(this: random, a2: 0, a3: 100);
  if ( v14 != this->m_vecDirection.m_Value.x
    || v15 != this->m_vecDirection.m_Value.y
    || v11 != this->m_vecDirection.m_Value.z )
  {
    this->m_vecDirection.m_Value.x = v14;
    this->m_vecDirection.m_Value.y = v15;
    this->m_vecDirection.m_Value.z = v11;
  }
  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CBroadcastRecipientFilter_vtbl *)&CBroadcastRecipientFilter::`vftable';
  CRecipientFilter::AddAllPlayers(this: &filter);
  ((void (__thiscall *)(CTESpriteSpray *, CBroadcastRecipientFilter *, _DWORD))this->Create)(
    a1: this,
    a2: &filter,
    a3: 0);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x10335670
// Name: void TE_SpriteSpray(class IRecipientFilter __near &,float,class Vector const __near *,class Vector const __near *,int,int,float,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_SpriteSpray(
        IRecipientFilter *filter,
        float delay,
        CNetworkVectorBase<Vector,CTESpriteSpray::NetworkVar_m_vecOrigin> *pos,
        CNetworkVectorBase<Vector,CTESpriteSpray::NetworkVar_m_vecDirection> *dir,
        int modelindex,
        int speed,
        float noise,
        int count)
{
  if ( pos->m_Value.x != g_TESpriteSpray.m_vecOrigin.m_Value.x
    || pos->m_Value.y != g_TESpriteSpray.m_vecOrigin.m_Value.y
    || pos->m_Value.z != g_TESpriteSpray.m_vecOrigin.m_Value.z )
  {
    g_TESpriteSpray.m_vecOrigin = *pos;
  }
  if ( dir->m_Value.x != g_TESpriteSpray.m_vecDirection.m_Value.x
    || dir->m_Value.y != g_TESpriteSpray.m_vecDirection.m_Value.y
    || dir->m_Value.z != g_TESpriteSpray.m_vecDirection.m_Value.z )
  {
    g_TESpriteSpray.m_vecDirection = *dir;
  }
  if ( g_TESpriteSpray.m_nModelIndex.m_Value != modelindex )
    g_TESpriteSpray.m_nModelIndex.m_Value = modelindex;
  if ( g_TESpriteSpray.m_nSpeed.m_Value != speed )
    g_TESpriteSpray.m_nSpeed.m_Value = speed;
  if ( g_TESpriteSpray.m_fNoise.m_Value != noise )
    g_TESpriteSpray.m_fNoise.m_Value = noise;
  if ( g_TESpriteSpray.m_nCount.m_Value != count )
    g_TESpriteSpray.m_nCount.m_Value = count;
  CBaseTempEntity::Create(this: &g_TESpriteSpray, filter, delay);
}

//------------------------------------------------------------------------------
// Address: 0x104179B0
// Name: DT_TESpriteSpray::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TESpriteSpray::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_TESpriteSpray::g_SendTable);
  return atexit(func: DT_TESpriteSpray::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104179D0
// Name: DT_TESpriteSpray::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TESpriteSpray::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_TESpriteSpray::ignored>();
  DT_TESpriteSpray::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104229D0
// Name: DT_TESpriteSpray::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TESpriteSpray::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_TESpriteSpray::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x104179E0
// Name: _dynamic_initializer_for__g_TESpriteSpray__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TESpriteSpray__()
{
  CTESpriteSpray::CTESpriteSpray(this: &g_TESpriteSpray, name: "Sprite Spray");
  return atexit(func: dynamic_atexit_destructor_for__g_TESpriteSpray__);
}

//------------------------------------------------------------------------------
// Address: 0x10417A00
// Name: _dynamic_initializer_for__g_CTEWorldDecal_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CTEWorldDecal_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CTEWorldDecal_ClassReg,
           pNetworkName: "CTEWorldDecal",
           pTable: &DT_TEWorldDecal::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x104229E0
// Name: _dynamic_atexit_destructor_for__g_TESpriteSpray__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TESpriteSpray__()
{
  g_TESpriteSpray.__vftable = (CTESpriteSpray_vtbl *)&CTESpriteSpray::`vftable';
  CBaseTempEntity::~CBaseTempEntity(this: &g_TESpriteSpray);
}

//------------------------------------------------------------------------------
// Address: 0x10422A00
// Name: _ServerClassInit_DT_TESpriteSpray::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_TESpriteSpray::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_360;
  for ( i = 7; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}
