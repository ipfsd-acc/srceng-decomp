// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vmpi/vmpi_browser_helpers.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00405CA0
// Name: void FormatTimeString(unsigned long,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FormatTimeString(unsigned int nInputSeconds, char *timeStr, int outLen)
{
  unsigned int v3; // esi
  unsigned int v4; // edx
  unsigned int v5; // esi
  unsigned int v6; // [esp-4h] [ebp-Ch]

  v3 = nInputSeconds / 0x3C / 0x3C;
  v4 = v3 / 0x18;
  v5 = v3 % 0x18;
  if ( v4 != 0 )
  {
    if ( v5 != 0 )
    {
      V_snprintf(pDest: timeStr, maxLen: outLen, pFormat: "%dd %dh %dm", v4, v5, nInputSeconds / 0x3C % 0x3C);
      return;
    }
  }
  else if ( v5 != 0 )
  {
    V_snprintf(pDest: timeStr, maxLen: outLen, pFormat: "%dh %dm", v5, nInputSeconds / 0x3C % 0x3C);
    return;
  }
  v6 = nInputSeconds % 0x3C;
  if ( nInputSeconds / 0x3C % 0x3C != 0 )
    V_snprintf(pDest: timeStr, maxLen: outLen, pFormat: "%dm %ds", nInputSeconds / 0x3C % 0x3C, v6);
  else
    V_snprintf(pDest: timeStr, maxLen: outLen, pFormat: "%d seconds", v6);
}
