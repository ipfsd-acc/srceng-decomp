// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/audio/audio_pch.cpp
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10001030
// Name: char __near * PSkipSoundChars(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl PSkipSoundChars(char *pch)
{
  char *result; // eax
  char v2; // cl

  for ( result = pch; ; ++result )
  {
    v2 = *result;
    if ( *result != 42
      && v2 != 63
      && v2 != 33
      && v2 != 35
      && v2 != 64
      && v2 != 40
      && v2 != 62
      && v2 != 60
      && v2 != 94
      && v2 != 41
      && v2 != 125
      && v2 != 36 )
    {
      break;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001080
// Name: bool TestSoundChar(char const __near *,char)
// Source: json
//------------------------------------------------------------------------------
char __cdecl TestSoundChar(const char *pch, char c)
{
  char v3; // al

  while ( 1 )
  {
    v3 = *pch;
    if ( *pch != 42
      && v3 != 63
      && v3 != 33
      && v3 != 35
      && v3 != 64
      && v3 != 40
      && v3 != 62
      && v3 != 60
      && v3 != 94
      && v3 != 41
      && v3 != 125
      && v3 != 36 )
    {
      return 0;
    }
    if ( v3 == c )
      break;
    ++pch;
  }
  return 1;
}
