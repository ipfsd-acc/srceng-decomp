// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/singleplay_gamerules.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10213C40
// Name: void RegenerationForceOnChangeCallback(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RegenerationForceOnChangeCallback(IConVar *pConVar)
{
  const char *pszValue; // eax
  int Index; // eax
  GLOBALESTATE v3; // [esp-4h] [ebp-Ch]
  ConVarRef var; // [esp+0h] [ebp-8h] BYREF

  ConVarRef::ConVarRef(this: &var, pConVar);
  if ( GlobalEntity_GetIndex(pGlobalname: "player_regenerates_health") >= 0 )
  {
    v3 = var.m_pConVarState->m_Value.m_nValue != 0;
    Index = GlobalEntity_GetIndex(pGlobalname: "player_regenerates_health");
    GlobalEntity_SetState(globalIndex: Index, state: v3);
  }
  else
  {
    pszValue = gpGlobals->mapname.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    GlobalEntity_Add(
      pGlobalname: "player_regenerates_health",
      pMapName: pszValue,
      state: (GLOBALESTATE)(var.m_pConVarState->m_Value.m_nValue != 0));
  }
}
