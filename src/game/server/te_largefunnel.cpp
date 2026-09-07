// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/te_largefunnel.cpp
// Functions: 15
// ============================================================

#include "game\server\te_largefunnel.h"

//------------------------------------------------------------------------------
// Address: 0x10332F00
// Name: public: virtual class ServerClass __near * CTELargeFunnel::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CTELargeFunnel::GetServerClass(CTELargeFunnel *this)
{
  return &g_CTELargeFunnel_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10333000
// Name: public: virtual void CTELargeFunnel::Test(class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTELargeFunnel::Test(CTELargeFunnel *this, const Vector *current_origin, const QAngle *current_angles)
{
  float y; // xmm0_4
  float z; // xmm0_4
  CBroadcastRecipientFilter filter; // [esp+8h] [ebp-38h] BYREF
  Vector right; // [esp+28h] [ebp-18h] BYREF
  Vector forward; // [esp+34h] [ebp-Ch] BYREF

  if ( this->m_nModelIndex.m_Value != g_sModelIndexSmoke )
    this->m_nModelIndex.m_Value = g_sModelIndexSmoke;
  if ( this->m_nReversed.m_Value != 0 )
    this->m_nReversed.m_Value = 0;
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
  this->m_vecOrigin.m_Value.x = (float)(forward.x * 50.0) + this->m_vecOrigin.m_Value.x;
  this->m_vecOrigin.m_Value.y = (float)(forward.y * 50.0) + this->m_vecOrigin.m_Value.y;
  this->m_vecOrigin.m_Value.z = (float)(forward.z * 50.0) + this->m_vecOrigin.m_Value.z;
  this->m_vecOrigin.m_Value.x = (float)(right.x * 25.0) + this->m_vecOrigin.m_Value.x;
  this->m_vecOrigin.m_Value.y = (float)(right.y * 25.0) + this->m_vecOrigin.m_Value.y;
  this->m_vecOrigin.m_Value.z = (float)(right.z * 25.0) + this->m_vecOrigin.m_Value.z;
  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CBroadcastRecipientFilter_vtbl *)&CBroadcastRecipientFilter::`vftable';
  CRecipientFilter::AddAllPlayers(this: &filter);
  ((void (__thiscall *)(CTELargeFunnel *, CBroadcastRecipientFilter *, _DWORD))this->Create)(
    a1: this,
    a2: &filter,
    a3: 0);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x10333170
// Name: void TE_LargeFunnel(class IRecipientFilter __near &,float,class Vector const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_LargeFunnel(IRecipientFilter *filter, float delay, const Vector *pos, int modelindex, int reversed)
{
  if ( g_TELargeFunnel.m_vecOrigin.m_Value.x != pos->x )
    g_TELargeFunnel.m_vecOrigin.m_Value.x = pos->x;
  if ( g_TELargeFunnel.m_vecOrigin.m_Value.y != pos->y )
    g_TELargeFunnel.m_vecOrigin.m_Value.y = pos->y;
  if ( g_TELargeFunnel.m_vecOrigin.m_Value.z != pos->z )
    g_TELargeFunnel.m_vecOrigin.m_Value.z = pos->z;
  if ( g_TELargeFunnel.m_nModelIndex.m_Value != modelindex )
    g_TELargeFunnel.m_nModelIndex.m_Value = modelindex;
  if ( g_TELargeFunnel.m_nReversed.m_Value != reversed )
    g_TELargeFunnel.m_nReversed.m_Value = reversed;
  CBaseTempEntity::Create(this: &g_TELargeFunnel, filter, delay);
}

//------------------------------------------------------------------------------
// Address: 0x103FC290
// Name: _dynamic_initializer_for__Large_Hull__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__Large_Hull__()
{
  *(_QWORD *)&Large_Hull.mins.x = 0xC2200000C2200000uLL;
  *(_QWORD *)&Large_Hull.maxs.x = 0x4220000042200000LL;
  Large_Hull.mins.z = 0.0;
  *(_QWORD *)&Large_Hull.smallMins.x = 0xC2200000C2200000uLL;
  Large_Hull.maxs.z = 100.0;
  Large_Hull.smallMins.z = 0.0;
  *(_QWORD *)&Large_Hull.smallMaxs.x = 0x4220000042200000LL;
  Large_Hull.smallMaxs.z = 100.0;
  return 1120403456;
}

//------------------------------------------------------------------------------
// Address: 0x103FC350
// Name: _dynamic_initializer_for__Large_Centered_Hull__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__Large_Centered_Hull__()
{
  *(_QWORD *)&Large_Centered_Hull.mins.x = 0xC2180000C2180000uLL;
  *(_QWORD *)&Large_Centered_Hull.maxs.x = 0x4218000042180000LL;
  Large_Centered_Hull.mins.z = -38.0;
  *(_QWORD *)&Large_Centered_Hull.smallMins.x = 0xC1F00000C1F00000uLL;
  Large_Centered_Hull.maxs.z = 38.0;
  Large_Centered_Hull.smallMins.z = -30.0;
  *(_QWORD *)&Large_Centered_Hull.smallMaxs.x = 0x41F0000041F00000LL;
  Large_Centered_Hull.smallMaxs.z = 30.0;
  return 1106247680;
}

//------------------------------------------------------------------------------
// Address: 0x104171C0
// Name: DT_TELargeFunnel::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TELargeFunnel::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_TELargeFunnel::g_SendTable);
  return atexit(func: DT_TELargeFunnel::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104171E0
// Name: DT_TELargeFunnel::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TELargeFunnel::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_TELargeFunnel::ignored>();
  DT_TELargeFunnel::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104226D0
// Name: DT_TELargeFunnel::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TELargeFunnel::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_TELargeFunnel::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x103FC410
// Name: _dynamic_initializer_for__Medium_Tall_Hull__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__Medium_Tall_Hull__()
{
  *(_QWORD *)&Medium_Tall_Hull.mins.x = 0xC1900000C1900000uLL;
  *(_QWORD *)&Medium_Tall_Hull.maxs.x = 0x4190000041900000LL;
  Medium_Tall_Hull.mins.z = 0.0;
  *(_QWORD *)&Medium_Tall_Hull.smallMins.x = 0xC1400000C1400000uLL;
  Medium_Tall_Hull.maxs.z = 100.0;
  Medium_Tall_Hull.smallMins.z = 0.0;
  *(_QWORD *)&Medium_Tall_Hull.smallMaxs.x = 0x4140000041400000LL;
  Medium_Tall_Hull.smallMaxs.z = 100.0;
  return 1120403456;
}

//------------------------------------------------------------------------------
// Address: 0x103FC4E0
// Name: _dynamic_initializer_for__Tiny_Fluid_Hull__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__Tiny_Fluid_Hull__()
{
  *(_QWORD *)&Tiny_Fluid_Hull.mins.x = 0xC0D00000C0D00000uLL;
  *(_QWORD *)&Tiny_Fluid_Hull.maxs.x = 0x40D0000040D00000LL;
  Tiny_Fluid_Hull.mins.z = 0.0;
  *(_QWORD *)&Tiny_Fluid_Hull.smallMins.x = 0xC0D00000C0D00000uLL;
  Tiny_Fluid_Hull.maxs.z = 13.0;
  Tiny_Fluid_Hull.smallMins.z = 0.0;
  *(_QWORD *)&Tiny_Fluid_Hull.smallMaxs.x = 0x40D0000040D00000LL;
  Tiny_Fluid_Hull.smallMaxs.z = 13.0;
  return 1095761920;
}

//------------------------------------------------------------------------------
// Address: 0x103FC5A0
// Name: _dynamic_initializer_for__MediumBig_Hull__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__MediumBig_Hull__()
{
  *(_QWORD *)&MediumBig_Hull.mins.x = 0xC1880000C1880000uLL;
  *(_QWORD *)&MediumBig_Hull.maxs.x = 0x4188000041880000LL;
  MediumBig_Hull.mins.z = 0.0;
  *(_QWORD *)&MediumBig_Hull.smallMins.x = 0xC1700000C1700000uLL;
  MediumBig_Hull.maxs.z = 69.0;
  MediumBig_Hull.smallMins.z = 0.0;
  *(_QWORD *)&MediumBig_Hull.smallMaxs.x = 0x4170000041700000LL;
  MediumBig_Hull.smallMaxs.z = 69.0;
  return 1116340224;
}

//------------------------------------------------------------------------------
// Address: 0x104171F0
// Name: _dynamic_initializer_for__g_TELargeFunnel__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TELargeFunnel__()
{
  CBaseTempEntity::CBaseTempEntity(this: &g_TELargeFunnel, name: "Large Funnel");
  g_TELargeFunnel.m_vecOrigin.m_Value.x = 0.0;
  g_TELargeFunnel.m_vecOrigin.m_Value.y = 0.0;
  g_TELargeFunnel.m_vecOrigin.m_Value.z = 0.0;
  g_TELargeFunnel.__vftable = (CTELargeFunnel_vtbl *)&CTELargeFunnel::`vftable';
  if ( g_TELargeFunnel.m_nModelIndex.m_Value != 0 )
    g_TELargeFunnel.m_nModelIndex.m_Value = 0;
  if ( g_TELargeFunnel.m_nReversed.m_Value != 0 )
    g_TELargeFunnel.m_nReversed.m_Value = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_TELargeFunnel__);
}

//------------------------------------------------------------------------------
// Address: 0x10417250
// Name: _dynamic_initializer_for__g_CTEMuzzleFlash_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CTEMuzzleFlash_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CTEMuzzleFlash_ClassReg,
           pNetworkName: "CTEMuzzleFlash",
           pTable: &DT_TEMuzzleFlash::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x104226E0
// Name: _dynamic_atexit_destructor_for__g_TELargeFunnel__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TELargeFunnel__()
{
  g_TELargeFunnel.__vftable = (CTELargeFunnel_vtbl *)&CTELargeFunnel::`vftable';
  CBaseTempEntity::~CBaseTempEntity(this: &g_TELargeFunnel);
}

//------------------------------------------------------------------------------
// Address: 0x10422700
// Name: _ServerClassInit_DT_TELargeFunnel::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_TELargeFunnel::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_350;
  for ( i = 3; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}
