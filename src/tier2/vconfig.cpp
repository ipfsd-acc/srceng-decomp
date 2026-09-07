// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier2/vconfig.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00410780
// Name: bool GetVConfigRegistrySetting(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl GetVConfigRegistrySetting(const char *pName, char *pReturn, unsigned int size)
{
  unsigned int dwSize; // [esp+4h] [ebp-8h] BYREF
  unsigned int cbData; // [esp+8h] [ebp-4h] BYREF

  if ( RegOpenKeyExA(
         hKey: HKEY_CURRENT_USER,
         lpSubKey: "SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Environment",
         ulOptions: 0,
         samDesired: 1u,
         phkResult: (PHKEY)&dwSize) != 0 )
    return 0;
  cbData = size;
  if ( RegQueryValueExA(
         hKey: (HKEY)dwSize,
         lpValueName: pName,
         lpReserved: nullptr,
         lpType: nullptr,
         lpData: (LPBYTE)pReturn,
         lpcbData: &cbData) != 0 )
    return 0;
  RegCloseKey(hKey: (HKEY)dwSize);
  return 1;
}
