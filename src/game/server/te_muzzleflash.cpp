// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/te_muzzleflash.cpp
// Functions: 9
// ============================================================

#include "game\server\te_muzzleflash.h"

//------------------------------------------------------------------------------
// Address: 0x10333210
// Name: public: virtual class ServerClass __near * CTEMuzzleFlash::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CTEMuzzleFlash::GetServerClass(CTEMuzzleFlash *this)
{
  return &g_CTEMuzzleFlash_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x103333B0
// Name: void TE_MuzzleFlash(class IRecipientFilter __near &,float,class Vector const __near &,class QAngle const __near &,float,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_MuzzleFlash(
        IRecipientFilter *filter,
        float delay,
        CNetworkVectorBase<Vector,CTEMuzzleFlash::NetworkVar_m_vecOrigin> *start,
        CNetworkVectorBase<QAngle,CTEMuzzleFlash::NetworkVar_m_vecAngles> *angles,
        float scale,
        int type)
{
  if ( start->m_Value.x != g_TEMuzzleFlash.m_vecOrigin.m_Value.x
    || start->m_Value.y != g_TEMuzzleFlash.m_vecOrigin.m_Value.y
    || start->m_Value.z != g_TEMuzzleFlash.m_vecOrigin.m_Value.z )
  {
    g_TEMuzzleFlash.m_vecOrigin = *start;
  }
  if ( angles->m_Value.x != g_TEMuzzleFlash.m_vecAngles.m_Value.x
    || angles->m_Value.y != g_TEMuzzleFlash.m_vecAngles.m_Value.y
    || angles->m_Value.z != g_TEMuzzleFlash.m_vecAngles.m_Value.z )
  {
    g_TEMuzzleFlash.m_vecAngles = *angles;
  }
  if ( g_TEMuzzleFlash.m_flScale.m_Value != scale )
    g_TEMuzzleFlash.m_flScale.m_Value = scale;
  if ( g_TEMuzzleFlash.m_nType.m_Value != type )
    g_TEMuzzleFlash.m_nType.m_Value = type;
  CBaseTempEntity::Create(this: &g_TEMuzzleFlash, filter, delay);
}

//------------------------------------------------------------------------------
// Address: 0x10417270
// Name: DT_TEMuzzleFlash::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEMuzzleFlash::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_TEMuzzleFlash::g_SendTable);
  return atexit(func: DT_TEMuzzleFlash::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10417290
// Name: DT_TEMuzzleFlash::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEMuzzleFlash::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_TEMuzzleFlash::ignored>();
  DT_TEMuzzleFlash::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10422720
// Name: DT_TEMuzzleFlash::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEMuzzleFlash::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_TEMuzzleFlash::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x104172A0
// Name: _dynamic_initializer_for__g_TEMuzzleFlash__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TEMuzzleFlash__()
{
  CBaseTempEntity::CBaseTempEntity(this: &g_TEMuzzleFlash, name: "MuzzleFlash");
  g_TEMuzzleFlash.__vftable = (CTEMuzzleFlash_vtbl *)&CTEMuzzleFlash::`vftable';
  if ( g_TEMuzzleFlash.m_vecOrigin.m_Value.x != 0.0
    || g_TEMuzzleFlash.m_vecOrigin.m_Value.y != 0.0
    || g_TEMuzzleFlash.m_vecOrigin.m_Value.z != 0.0 )
  {
    g_TEMuzzleFlash.m_vecOrigin.m_Value.x = 0.0;
    g_TEMuzzleFlash.m_vecOrigin.m_Value.y = 0.0;
    g_TEMuzzleFlash.m_vecOrigin.m_Value.z = 0.0;
  }
  if ( g_TEMuzzleFlash.m_vecAngles.m_Value.x != 0.0
    || g_TEMuzzleFlash.m_vecAngles.m_Value.y != 0.0
    || g_TEMuzzleFlash.m_vecAngles.m_Value.z != 0.0 )
  {
    g_TEMuzzleFlash.m_vecAngles.m_Value.x = 0.0;
    g_TEMuzzleFlash.m_vecAngles.m_Value.y = 0.0;
    g_TEMuzzleFlash.m_vecAngles.m_Value.z = 0.0;
  }
  if ( g_TEMuzzleFlash.m_flScale.m_Value != 1.0 )
    g_TEMuzzleFlash.m_flScale.m_Value = 1.0;
  if ( g_TEMuzzleFlash.m_nType.m_Value != 0 )
    g_TEMuzzleFlash.m_nType.m_Value = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_TEMuzzleFlash__);
}

//------------------------------------------------------------------------------
// Address: 0x10417380
// Name: _dynamic_initializer_for__g_CTEParticleSystem_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CTEParticleSystem_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CTEParticleSystem_ClassReg,
           pNetworkName: "CTEParticleSystem",
           pTable: &DT_TEParticleSystem::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10422730
// Name: _dynamic_atexit_destructor_for__g_TEMuzzleFlash__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TEMuzzleFlash__()
{
  g_TEMuzzleFlash.__vftable = (CTEMuzzleFlash_vtbl *)&CTEMuzzleFlash::`vftable';
  CBaseTempEntity::~CBaseTempEntity(this: &g_TEMuzzleFlash);
}

//------------------------------------------------------------------------------
// Address: 0x10422750
// Name: _ServerClassInit_DT_TEMuzzleFlash::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_TEMuzzleFlash::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_351;
  for ( i = 5; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}
