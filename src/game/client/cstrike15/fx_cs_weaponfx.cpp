// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/fx_cs_weaponfx.cpp
// Functions: 12
// ============================================================

#include "game\client\cstrike15\fx_cs_weaponfx.h"

//------------------------------------------------------------------------------
// Address: 0x101CC120
// Name: void CStrike_FX_EjectBrass_556_Callback(class CEffectData const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CStrike_FX_EjectBrass_556_Callback()
{
  if ( C_BasePlayer::GetLocalPlayer(nSlot: -1) != nullptr )
    DevWarning(a1: "Unhandled CStrike EjectBrass effect\n");
}

//------------------------------------------------------------------------------
// Address: 0x104237E0
// Name: EjectBrass_9mmPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int EjectBrass_9mmPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106EF254;
  EjectBrass_9mmPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106EF254;
  dword_106EF254 = (int)&EjectBrass_9mmPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10423820
// Name: EjectBrass_12GaugePrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int EjectBrass_12GaugePrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106EF254;
  EjectBrass_12GaugePrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106EF254;
  dword_106EF254 = (int)&EjectBrass_12GaugePrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10423860
// Name: EjectBrass_57Precache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int EjectBrass_57Precache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106EF254;
  EjectBrass_57Precache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106EF254;
  dword_106EF254 = (int)&EjectBrass_57Precache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104238A0
// Name: EjectBrass_556Precache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int EjectBrass_556Precache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106EF254;
  EjectBrass_556Precache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106EF254;
  dword_106EF254 = (int)&EjectBrass_556Precache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104238E0
// Name: EjectBrass_762NatoPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int EjectBrass_762NatoPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106EF254;
  EjectBrass_762NatoPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106EF254;
  dword_106EF254 = (int)&EjectBrass_762NatoPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10423920
// Name: EjectBrass_338MagPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int EjectBrass_338MagPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106EF254;
  EjectBrass_338MagPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106EF254;
  dword_106EF254 = (int)&EjectBrass_338MagPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10423800
// Name: _dynamic_initializer_for__ClientEffectReg_CStrike_FX_EjectBrass_12Gauge_Callback__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CClientEffectRegistration *dynamic_initializer_for__ClientEffectReg_CStrike_FX_EjectBrass_12Gauge_Callback__()
{
  return CClientEffectRegistration::CClientEffectRegistration(
           this: &ClientEffectReg_CStrike_FX_EjectBrass_12Gauge_Callback,
           pEffectName: "EjectBrass_12Gauge",
           fn: (void (__cdecl *)(const CEffectData *))CStrike_FX_EjectBrass_556_Callback);
}

//------------------------------------------------------------------------------
// Address: 0x10423840
// Name: _dynamic_initializer_for__ClientEffectReg_CStrike_FX_EjectBrass_57_Callback__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CClientEffectRegistration *dynamic_initializer_for__ClientEffectReg_CStrike_FX_EjectBrass_57_Callback__()
{
  return CClientEffectRegistration::CClientEffectRegistration(
           this: &ClientEffectReg_CStrike_FX_EjectBrass_57_Callback,
           pEffectName: "EjectBrass_57",
           fn: (void (__cdecl *)(const CEffectData *))CStrike_FX_EjectBrass_556_Callback);
}

//------------------------------------------------------------------------------
// Address: 0x10423880
// Name: _dynamic_initializer_for__ClientEffectReg_CStrike_FX_EjectBrass_556_Callback__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CClientEffectRegistration *dynamic_initializer_for__ClientEffectReg_CStrike_FX_EjectBrass_556_Callback__()
{
  return CClientEffectRegistration::CClientEffectRegistration(
           this: &ClientEffectReg_CStrike_FX_EjectBrass_556_Callback,
           pEffectName: "EjectBrass_556",
           fn: (void (__cdecl *)(const CEffectData *))CStrike_FX_EjectBrass_556_Callback);
}

//------------------------------------------------------------------------------
// Address: 0x104238C0
// Name: _dynamic_initializer_for__ClientEffectReg_CStrike_FX_EjectBrass_762Nato_Callback__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CClientEffectRegistration *dynamic_initializer_for__ClientEffectReg_CStrike_FX_EjectBrass_762Nato_Callback__()
{
  return CClientEffectRegistration::CClientEffectRegistration(
           this: &ClientEffectReg_CStrike_FX_EjectBrass_762Nato_Callback,
           pEffectName: "EjectBrass_762Nato",
           fn: (void (__cdecl *)(const CEffectData *))CStrike_FX_EjectBrass_556_Callback);
}

//------------------------------------------------------------------------------
// Address: 0x10423900
// Name: _dynamic_initializer_for__ClientEffectReg_CStrike_FX_EjectBrass_338Mag_Callback__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CClientEffectRegistration *dynamic_initializer_for__ClientEffectReg_CStrike_FX_EjectBrass_338Mag_Callback__()
{
  return CClientEffectRegistration::CClientEffectRegistration(
           this: &ClientEffectReg_CStrike_FX_EjectBrass_338Mag_Callback,
           pEffectName: "EjectBrass_338Mag",
           fn: (void (__cdecl *)(const CEffectData *))CStrike_FX_EjectBrass_556_Callback);
}
