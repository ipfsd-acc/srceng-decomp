// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/infernoshared.cpp
// Functions: 2
// ============================================================

#include "game\shared\cstrike15\infernoshared.h"

//------------------------------------------------------------------------------
// Address: 0x101D0200
// Name: public: virtual char const __near * C_Inferno::GetParticleEffectName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall C_Inferno::GetParticleEffectName(C_Inferno *this)
{
  return "molotov_groundfire";
}

//------------------------------------------------------------------------------
// Address: 0x101D0210
// Name: public: virtual char const __near * C_FireCrackerBlast::GetParticleEffectName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall C_FireCrackerBlast::GetParticleEffectName(C_FireCrackerBlast *this)
{
  return "firework_crate_ground_effect";
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x102DB280
// Name: public: virtual char const __near * CInferno::GetParticleEffectName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CInferno::GetParticleEffectName(CInferno *this)
{
  return "molotov_groundfire";
}

//------------------------------------------------------------------------------
// Address: 0x102DB290
// Name: public: virtual char const __near * CInferno::GetImpactParticleEffectName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CInferno::GetImpactParticleEffectName(CInferno *this)
{
  return "molotov_explosion";
}

//------------------------------------------------------------------------------
// Address: 0x102DB2A0
// Name: public: virtual char const __near * CFireCrackerBlast::GetParticleEffectName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CFireCrackerBlast::GetParticleEffectName(CFireCrackerBlast *this)
{
  return "firework_crate_ground_effect";
}

//------------------------------------------------------------------------------
// Address: 0x102DB2B0
// Name: public: virtual char const __near * CFireCrackerBlast::GetImpactParticleEffectName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CFireCrackerBlast::GetImpactParticleEffectName(CFireCrackerBlast *this)
{
  return "firework_crate_explosion_01";
}

//------------------------------------------------------------------------------
// Address: 0x102DB2C0
// Name: __CreateCServerGameTagsIServerGameTags_interface_51
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerGameTags *__cdecl _CreateCServerGameTagsIServerGameTags_interface_51()
{
  return &_g_CServerGameTags_singleton_51;
}

} // namespace server
