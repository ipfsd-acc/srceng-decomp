// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/weapon_proficiency.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10266D00
// Name: char const __near * GetWeaponProficiencyName(enum WeaponProficiency_t)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl GetWeaponProficiencyName(WeaponProficiency_t proficiency)
{
  if ( (unsigned int)proficiency > WEAPON_PROFICIENCY_PERFECT )
    return "<<Invalid>>";
  else
    return g_ProficiencyNames[proficiency];
}
