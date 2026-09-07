// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/mp_shareddefs.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10175A80
// Name: int GetMPConceptIndexFromString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetMPConceptIndexFromString(const char *pszConcept)
{
  int v1; // esi

  v1 = 0;
  while ( _V_stricmp(s1: pszConcept, s2: g_pszMPConcepts[v1]) != 0 )
  {
    if ( (unsigned int)++v1 >= 0x3F )
      return -1;
  }
  return v1;
}
