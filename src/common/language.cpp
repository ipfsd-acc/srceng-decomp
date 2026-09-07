// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: common/language.cpp
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10199610
// Name: enum ELanguage PchLanguageToELanguage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
ELanguage __cdecl PchLanguageToELanguage(const char *pchShortName)
{
  int v2; // edi
  unsigned int v3; // esi

  if ( pchShortName == nullptr )
    return k_Lang_English;
  v2 = 0;
  v3 = 0;
  while ( _V_stricmp(s1: pchShortName, s2: s_LanguageNames[v3].m_pchShortName) != 0 )
  {
    ++v3;
    ++v2;
    if ( v3 >= 19 )
      return k_Lang_English;
  }
  return s_LanguageNames[v2].m_ELanguage;
}

//------------------------------------------------------------------------------
// Address: 0x10199660
// Name: char const __near * GetLanguageShortName(enum ELanguage)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetLanguageShortName(ELanguage eLang)
{
  if ( s_LanguageNames[eLang + 1].m_ELanguage == eLang )
    return s_LanguageNames[eLang + 1].m_pchShortName;
  else
    return s_LanguageNames[0].m_pchShortName;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10199A50
// Name: enum ELanguage PchLanguageToELanguage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
ELanguage __cdecl PchLanguageToELanguage(const char *pchShortName)
{
  int v2; // edi
  unsigned int v3; // esi

  if ( pchShortName == nullptr )
    return k_Lang_English;
  v2 = 0;
  v3 = 0;
  while ( _V_stricmp(s1: pchShortName, s2: s_LanguageNames[v3].m_pchShortName) != 0 )
  {
    ++v3;
    ++v2;
    if ( v3 >= 19 )
      return k_Lang_English;
  }
  return s_LanguageNames[v2].m_ELanguage;
}

//------------------------------------------------------------------------------
// Address: 0x10199AA0
// Name: char const __near * GetLanguageShortName(enum ELanguage)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetLanguageShortName(ELanguage eLang)
{
  if ( s_LanguageNames[eLang + 1].m_ELanguage == eLang )
    return s_LanguageNames[eLang + 1].m_pchShortName;
  else
    return s_LanguageNames[0].m_pchShortName;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from makegamedata (Missing functions)
// ============================================================
namespace makegamedata {

//------------------------------------------------------------------------------
// Address: 0x0041E720
// Name: enum ELanguage PchLanguageToELanguage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
ELanguage __cdecl PchLanguageToELanguage(const char *pchShortName)
{
  int v2; // edi
  unsigned int v3; // esi

  if ( pchShortName == nullptr )
    return k_Lang_English;
  v2 = 0;
  v3 = 0;
  while ( _V_stricmp(s1: pchShortName, s2: s_LanguageNames[v3].m_pchShortName) != 0 )
  {
    ++v3;
    ++v2;
    if ( v3 >= 19 )
      return k_Lang_English;
  }
  return s_LanguageNames[v2].m_ELanguage;
}

//------------------------------------------------------------------------------
// Address: 0x0041E770
// Name: char const __near * GetLanguageShortName(enum ELanguage)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetLanguageShortName(ELanguage eLang)
{
  if ( s_LanguageNames[eLang + 1].m_ELanguage == eLang )
    return s_LanguageNames[eLang + 1].m_pchShortName;
  else
    return s_LanguageNames[0].m_pchShortName;
}

} // namespace makegamedata

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x10201980
// Name: enum ELanguage PchLanguageToELanguage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
ELanguage __cdecl PchLanguageToELanguage(const char *pchShortName)
{
  int v2; // edi
  unsigned int v3; // esi

  if ( pchShortName == nullptr )
    return k_Lang_English;
  v2 = 0;
  v3 = 0;
  while ( _V_stricmp(s1: pchShortName, s2: s_LanguageNames[v3].m_pchShortName) != 0 )
  {
    ++v3;
    ++v2;
    if ( v3 >= 19 )
      return k_Lang_English;
  }
  return s_LanguageNames[v2].m_ELanguage;
}

//------------------------------------------------------------------------------
// Address: 0x102019D0
// Name: char const __near * GetLanguageShortName(enum ELanguage)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetLanguageShortName(ELanguage eLang)
{
  if ( s_LanguageNames[eLang + 1].m_ELanguage == eLang )
    return s_LanguageNames[eLang + 1].m_pchShortName;
  else
    return s_LanguageNames[0].m_pchShortName;
}

//------------------------------------------------------------------------------
// Address: 0x10201A00
// Name: char const __near * GetLanguageVGUILocalization(enum ELanguage)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetLanguageVGUILocalization(ELanguage eLang)
{
  if ( s_LanguageNames[eLang + 1].m_ELanguage == eLang )
    return s_LanguageNames[eLang + 1].m_pchVGUILocalizationName;
  else
    return s_LanguageNames[0].m_pchVGUILocalizationName;
}

} // namespace client
