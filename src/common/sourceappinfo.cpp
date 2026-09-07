// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: common/sourceappinfo.cpp
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x101D81B0
// Name: char const __near * GetAppModName(enum ESourceApp)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetAppModName(ESourceApp eSourceApp)
{
  if ( s_SteamAppInfo[eSourceApp].m_ESourceApp == eSourceApp )
    return s_SteamAppInfo[eSourceApp].m_pchModName;
  else
    return s_SteamAppInfo[0].m_pchModName;
}

//------------------------------------------------------------------------------
// Address: 0x101D81E0
// Name: int const GetAppSteamAppId(enum ESourceApp)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetAppSteamAppId(ESourceApp eSourceApp)
{
  if ( s_SteamAppInfo[eSourceApp].m_ESourceApp == eSourceApp )
    return s_SteamAppInfo[eSourceApp].m_nSteamAppId;
  else
    return s_SteamAppInfo[0].m_nSteamAppId;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x101D8530
// Name: char const __near * GetAppModName(enum ESourceApp)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetAppModName(ESourceApp eSourceApp)
{
  if ( s_SteamAppInfo[eSourceApp].m_ESourceApp == eSourceApp )
    return s_SteamAppInfo[eSourceApp].m_pchModName;
  else
    return s_SteamAppInfo[0].m_pchModName;
}

//------------------------------------------------------------------------------
// Address: 0x101D8560
// Name: int const GetAppSteamAppId(enum ESourceApp)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetAppSteamAppId(ESourceApp eSourceApp)
{
  if ( s_SteamAppInfo[eSourceApp].m_ESourceApp == eSourceApp )
    return s_SteamAppInfo[eSourceApp].m_nSteamAppId;
  else
    return s_SteamAppInfo[0].m_nSteamAppId;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x100A5C10
// Name: int const GetAppSteamAppId(enum ESourceApp)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetAppSteamAppId(ESourceApp eSourceApp)
{
  if ( s_SteamAppInfo[eSourceApp].m_ESourceApp == eSourceApp )
    return s_SteamAppInfo[eSourceApp].m_nSteamAppId;
  else
    return s_SteamAppInfo[0].m_nSteamAppId;
}

} // namespace hammer_dll
