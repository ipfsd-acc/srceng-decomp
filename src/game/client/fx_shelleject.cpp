// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/fx_shelleject.cpp
// Functions: 11
// ============================================================

#include "game\client\fx_shelleject.h"

//------------------------------------------------------------------------------
// Address: 0x100DE3D0
// Name: void ShellEjectCallback(class CEffectData const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShellEjectCallback(const CEffectData *data)
{
  if ( CEffectData::GetRenderable(this: data) != nullptr )
    DevWarning(a1: "Unhandled ShellEject effect\n");
}

//------------------------------------------------------------------------------
// Address: 0x100DE3F0
// Name: void RifleShellEjectCallback(class CEffectData const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RifleShellEjectCallback(const CEffectData *data)
{
  if ( CEffectData::GetRenderable(this: data) != nullptr )
    DevWarning(a1: "Unhandled RifleShellEject effect\n");
}

//------------------------------------------------------------------------------
// Address: 0x100DE410
// Name: void ShotgunShellEjectCallback(class CEffectData const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShotgunShellEjectCallback(const CEffectData *data)
{
  if ( CEffectData::GetRenderable(this: data) != nullptr )
    DevWarning(a1: "Unhandled ShotgunShellEject effect\n");
}

//------------------------------------------------------------------------------
// Address: 0x10415F00
// Name: ShellEjectPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int ShellEjectPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106EF254;
  ShellEjectPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106EF254;
  dword_106EF254 = (int)&ShellEjectPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10415F40
// Name: RifleShellEjectPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int RifleShellEjectPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106EF254;
  RifleShellEjectPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106EF254;
  dword_106EF254 = (int)&RifleShellEjectPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10415F80
// Name: ShotgunShellEjectPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int ShotgunShellEjectPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106EF254;
  ShotgunShellEjectPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106EF254;
  dword_106EF254 = (int)&ShotgunShellEjectPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10415F20
// Name: _dynamic_initializer_for__ClientEffectReg_RifleShellEjectCallback__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CClientEffectRegistration *dynamic_initializer_for__ClientEffectReg_RifleShellEjectCallback__()
{
  return CClientEffectRegistration::CClientEffectRegistration(
           this: &ClientEffectReg_RifleShellEjectCallback,
           pEffectName: "RifleShellEject",
           fn: RifleShellEjectCallback);
}

//------------------------------------------------------------------------------
// Address: 0x10415F60
// Name: _dynamic_initializer_for__ClientEffectReg_ShotgunShellEjectCallback__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CClientEffectRegistration *dynamic_initializer_for__ClientEffectReg_ShotgunShellEjectCallback__()
{
  return CClientEffectRegistration::CClientEffectRegistration(
           this: &ClientEffectReg_ShotgunShellEjectCallback,
           pEffectName: "ShotgunShellEject",
           fn: ShotgunShellEjectCallback);
}

//------------------------------------------------------------------------------
// Address: 0x10415FA0
// Name: _dynamic_initializer_for__r_drawtracers__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_drawtracers__()
{
  ConVar::ConVar(this: &r_drawtracers, pName: "r_drawtracers", pDefaultValue: "1", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_drawtracers__);
}

//------------------------------------------------------------------------------
// Address: 0x10415FD0
// Name: _dynamic_initializer_for__r_drawtracers_firstperson__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_drawtracers_firstperson__()
{
  ConVar::ConVar(this: &r_drawtracers_firstperson, pName: "r_drawtracers_firstperson", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_drawtracers_firstperson__);
}

//------------------------------------------------------------------------------
// Address: 0x10416000
// Name: _dynamic_initializer_for__ClientEffectReg_TracerCallback__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CClientEffectRegistration *dynamic_initializer_for__ClientEffectReg_TracerCallback__()
{
  return CClientEffectRegistration::CClientEffectRegistration(
           this: &ClientEffectReg_TracerCallback,
           pEffectName: "Tracer",
           fn: TracerCallback);
}
