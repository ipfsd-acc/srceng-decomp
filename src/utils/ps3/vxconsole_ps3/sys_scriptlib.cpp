// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/ps3/vxconsole_ps3/sys_scriptlib.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00412800
// Name: void Sys_StripQuotesFromToken(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_StripQuotesFromToken(char *pToken)
{
  int v1; // esi

  v1 = strlen(pToken);
  if ( v1 >= 2 && *pToken == 34 )
  {
    memcpy(dst: (unsigned __int8 *)pToken, src: (unsigned __int8 *)pToken + 1, count: v1 - 1);
    pToken[v1 - 2] = 0;
  }
}
