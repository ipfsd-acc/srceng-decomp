// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: missionchooser/asw_system.cpp
// Functions: 4
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x100093D0
// Name: bool ASW_System_GetCurrentTimeAndDate(int __near *,int __near *,int __near *,int __near *,int __near *,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ASW_System_GetCurrentTimeAndDate(
        int *year,
        int *month,
        int *dayOfWeek,
        int *day,
        int *hour,
        int *minute,
        int *second)
{
  tm timeinfo; // [esp+0h] [ebp-24h] BYREF

  _Plat_GetLocalTime(a1: &timeinfo);
  if ( year != nullptr )
    *year = timeinfo.tm_year;
  if ( month != nullptr )
    *month = timeinfo.tm_mon;
  if ( dayOfWeek != nullptr )
    *dayOfWeek = timeinfo.tm_wday;
  if ( day != nullptr )
    *day = timeinfo.tm_mday;
  if ( hour != nullptr )
    *hour = timeinfo.tm_hour;
  if ( minute != nullptr )
    *minute = timeinfo.tm_min;
  if ( second != nullptr )
    *second = timeinfo.tm_sec;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10009440
// Name: char const __near * Sys_FindFirst(int __near &,char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl Sys_FindFirst(int *searchhandle, const char *path, char *basename, int namelength)
{
  const char *v4; // esi

  if ( *searchhandle != -1 )
  {
    _Msg(a1: "Sys_FindFirst without close");
    g_pFullFileSystem->FindClose(this: g_pFullFileSystem, a2: *searchhandle);
  }
  v4 = g_pFullFileSystem->FindFirst(this: g_pFullFileSystem, a2: path, a3: searchhandle);
  if ( basename != nullptr && v4 != nullptr )
    V_FileBase(in: v4, out: basename, maxlen: namelength);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x100094A0
// Name: char const __near * Sys_FindNext(int __near &,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl Sys_FindNext(int *searchhandle, char *basename, int namelength)
{
  const char *v3; // esi

  v3 = g_pFullFileSystem->FindNext(this: g_pFullFileSystem, a2: *searchhandle);
  if ( basename != nullptr && v3 != nullptr )
    V_FileBase(in: v3, out: basename, maxlen: namelength);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100094E0
// Name: void Sys_FindClose(int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_FindClose(int *searchhandle)
{
  if ( *searchhandle != -1 )
  {
    g_pFullFileSystem->FindClose(this: g_pFullFileSystem, a2: *searchhandle);
    *searchhandle = -1;
  }
}
