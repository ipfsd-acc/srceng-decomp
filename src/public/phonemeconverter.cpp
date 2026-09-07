// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: public/phonemeconverter.cpp
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x101CBFA0
// Name: unsigned char CodeToByteCode(int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl CodeToByteCode(int code)
{
  int v1; // ecx
  unsigned int v2; // eax

  v1 = 0;
  v2 = 0;
  while ( g_Phonemes[v2].code != code )
  {
    ++v2;
    ++v1;
    if ( v2 >= 54 )
      return 0;
  }
  return g_Phonemes[v1].byteCode;
}

//------------------------------------------------------------------------------
// Address: 0x101CBFE0
// Name: int ByteCodeToCode(unsigned char)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ByteCodeToCode(unsigned __int8 byteCode)
{
  int v1; // ecx
  unsigned int v2; // eax

  v1 = 0;
  v2 = 0;
  while ( g_Phonemes[v2].byteCode != byteCode )
  {
    ++v2;
    ++v1;
    if ( v2 >= 54 )
      return 95;
  }
  return g_Phonemes[v1].code;
}

// ============================================================
// Overlay from dmxedit (Missing functions)
// ============================================================
namespace dmxedit {

//------------------------------------------------------------------------------
// Address: 0x00568970
// Name: int TextToPhonemeIndex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl TextToPhonemeIndex(const char *text)
{
  int v1; // edi
  unsigned int v2; // esi

  v1 = 0;
  v2 = 0;
  while ( _V_stricmp(s1: g_Phonemes[v2].string, s2: text) != 0 )
  {
    ++v2;
    ++v1;
    if ( v2 >= 54 )
      return -1;
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x005689B0
// Name: int CodeForPhonemeByIndex(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CodeForPhonemeByIndex(unsigned int index)
{
  if ( index > 0x35 )
    return 95;
  else
    return g_Phonemes[index].code;
}

//------------------------------------------------------------------------------
// Address: 0x005689D0
// Name: char const __near * DescForPhonemeByIndex(int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl DescForPhonemeByIndex(unsigned int index)
{
  if ( index > 0x35 )
    return nullptr;
  else
    return g_Phonemes[index].desc;
}

} // namespace dmxedit

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x0049CA40
// Name: int NumPhonemes(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl NumPhonemes()
{
  return 54;
}

//------------------------------------------------------------------------------
// Address: 0x0049CA50
// Name: char const __near * NameForPhonemeByIndex(int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl NameForPhonemeByIndex(int index)
{
  return g_Phonemes[index].string;
}

//------------------------------------------------------------------------------
// Address: 0x0049CA70
// Name: int TextToPhonemeIndex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl TextToPhonemeIndex(const char *text)
{
  int v1; // edi
  unsigned int v2; // esi

  v1 = 0;
  v2 = 0;
  while ( _V_stricmp(s1: g_Phonemes[v2].string, s2: text) != 0 )
  {
    ++v2;
    ++v1;
    if ( v2 >= 54 )
      return -1;
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x0049CAB0
// Name: int CodeForPhonemeByIndex(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CodeForPhonemeByIndex(unsigned int index)
{
  if ( index > 0x35 )
    return 95;
  else
    return g_Phonemes[index].code;
}

//------------------------------------------------------------------------------
// Address: 0x0049CAD0
// Name: bool IsStandardPhoneme(int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsStandardPhoneme(unsigned int index)
{
  return index <= 0x35 && g_Phonemes[index].isStandard;
}

//------------------------------------------------------------------------------
// Address: 0x0049CAF0
// Name: char const __near * DescForPhonemeByIndex(int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl DescForPhonemeByIndex(unsigned int index)
{
  if ( index > 0x35 )
    return nullptr;
  else
    return g_Phonemes[index].desc;
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x101CC370
// Name: unsigned char CodeToByteCode(int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl CodeToByteCode(int code)
{
  int v1; // ecx
  unsigned int v2; // eax

  v1 = 0;
  v2 = 0;
  while ( g_Phonemes[v2].code != code )
  {
    ++v2;
    ++v1;
    if ( v2 >= 54 )
      return 0;
  }
  return g_Phonemes[v1].byteCode;
}

//------------------------------------------------------------------------------
// Address: 0x101CC3B0
// Name: int ByteCodeToCode(unsigned char)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ByteCodeToCode(unsigned __int8 byteCode)
{
  int v1; // ecx
  unsigned int v2; // eax

  v1 = 0;
  v2 = 0;
  while ( g_Phonemes[v2].byteCode != byteCode )
  {
    ++v2;
    ++v1;
    if ( v2 >= 54 )
      return 95;
  }
  return g_Phonemes[v1].code;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hlfaceposer (Missing functions)
// ============================================================
namespace hlfaceposer {

//------------------------------------------------------------------------------
// Address: 0x0040BE60
// Name: char const __near * ConvertPhoneme(int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl ConvertPhoneme(int code)
{
  PhonemeMap_t *v1; // ecx
  unsigned int v2; // eax

  v1 = g_Phonemes;
  v2 = 0;
  while ( v1->code != code )
  {
    v2 += 24;
    ++v1;
    if ( v2 >= 0x510 )
    {
      _Warning(a1: "Unrecognized phoneme code %i\n", code);
      return "<sil>";
    }
  }
  return v1->string;
}

//------------------------------------------------------------------------------
// Address: 0x0040BEA0
// Name: int TextToPhoneme(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl TextToPhoneme(const char *text)
{
  PhonemeMap_t *v1; // edi
  unsigned int v2; // esi

  v1 = g_Phonemes;
  v2 = 0;
  while ( _V_stricmp(s1: v1->string, s2: text) != 0 )
  {
    v2 += 24;
    ++v1;
    if ( v2 >= 0x510 )
    {
      _Warning(a1: "Unrecognized phoneme %s\n", text);
      return 95;
    }
  }
  return v1->code;
}

} // namespace hlfaceposer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x104AC910
// Name: int NumPhonemes(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl NumPhonemes()
{
  return 54;
}

//------------------------------------------------------------------------------
// Address: 0x104AC920
// Name: char const __near * NameForPhonemeByIndex(int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl NameForPhonemeByIndex(int index)
{
  return g_Phonemes[index].string;
}

//------------------------------------------------------------------------------
// Address: 0x104AC940
// Name: int TextToPhonemeIndex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl TextToPhonemeIndex(const char *text)
{
  int v1; // edi
  unsigned int v2; // esi

  v1 = 0;
  v2 = 0;
  while ( _V_stricmp(s1: g_Phonemes[v2].string, s2: text) != 0 )
  {
    ++v2;
    ++v1;
    if ( v2 >= 54 )
      return -1;
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x104AC980
// Name: int CodeForPhonemeByIndex(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CodeForPhonemeByIndex(unsigned int index)
{
  if ( index > 0x35 )
    return 95;
  else
    return g_Phonemes[index].code;
}

//------------------------------------------------------------------------------
// Address: 0x104AC9A0
// Name: bool IsStandardPhoneme(int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsStandardPhoneme(unsigned int index)
{
  return index <= 0x35 && g_Phonemes[index].isStandard;
}

//------------------------------------------------------------------------------
// Address: 0x104AC9C0
// Name: char const __near * DescForPhonemeByIndex(int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl DescForPhonemeByIndex(unsigned int index)
{
  if ( index > 0x35 )
    return nullptr;
  else
    return g_Phonemes[index].desc;
}

} // namespace hammer_dll

// ============================================================
// Overlay from makegamedata (Missing functions)
// ============================================================
namespace makegamedata {

//------------------------------------------------------------------------------
// Address: 0x0041E7A0
// Name: unsigned char CodeToByteCode(int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl CodeToByteCode(int code)
{
  int v1; // ecx
  unsigned int v2; // eax

  v1 = 0;
  v2 = 0;
  while ( g_Phonemes[v2].code != code )
  {
    ++v2;
    ++v1;
    if ( v2 >= 54 )
      return 0;
  }
  return g_Phonemes[v1].byteCode;
}

//------------------------------------------------------------------------------
// Address: 0x0041E7E0
// Name: int ByteCodeToCode(unsigned char)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ByteCodeToCode(unsigned __int8 byteCode)
{
  int v1; // ecx
  unsigned int v2; // eax

  v1 = 0;
  v2 = 0;
  while ( g_Phonemes[v2].byteCode != byteCode )
  {
    ++v2;
    ++v1;
    if ( v2 >= 54 )
      return 95;
  }
  return g_Phonemes[v1].code;
}

} // namespace makegamedata

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x00533570
// Name: char const __near * ConvertPhoneme(int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl ConvertPhoneme(int code)
{
  PhonemeMap_t *v1; // ecx
  unsigned int v2; // eax

  v1 = g_Phonemes;
  v2 = 0;
  while ( v1->code != code )
  {
    v2 += 24;
    ++v1;
    if ( v2 >= 0x510 )
    {
      _Warning(a1: "Unrecognized phoneme code %i\n", code);
      return "<sil>";
    }
  }
  return v1->string;
}

//------------------------------------------------------------------------------
// Address: 0x005335B0
// Name: int NumPhonemes(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl NumPhonemes()
{
  return 54;
}

//------------------------------------------------------------------------------
// Address: 0x005335C0
// Name: char const __near * NameForPhonemeByIndex(int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl NameForPhonemeByIndex(int index)
{
  return g_Phonemes[index].string;
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x004A70A0
// Name: int NumPhonemes(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl NumPhonemes()
{
  return 54;
}

//------------------------------------------------------------------------------
// Address: 0x004A70B0
// Name: char const __near * NameForPhonemeByIndex(int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl NameForPhonemeByIndex(int index)
{
  return g_Phonemes[index].string;
}

//------------------------------------------------------------------------------
// Address: 0x004A70D0
// Name: int TextToPhonemeIndex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl TextToPhonemeIndex(const char *text)
{
  int v1; // edi
  unsigned int v2; // esi

  v1 = 0;
  v2 = 0;
  while ( _V_stricmp(s1: g_Phonemes[v2].string, s2: text) != 0 )
  {
    ++v2;
    ++v1;
    if ( v2 >= 54 )
      return -1;
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x004A7110
// Name: int CodeForPhonemeByIndex(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CodeForPhonemeByIndex(unsigned int index)
{
  if ( index > 0x35 )
    return 95;
  else
    return g_Phonemes[index].code;
}

//------------------------------------------------------------------------------
// Address: 0x004A7130
// Name: bool IsStandardPhoneme(int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsStandardPhoneme(unsigned int index)
{
  return index <= 0x35 && g_Phonemes[index].isStandard;
}

//------------------------------------------------------------------------------
// Address: 0x004A7150
// Name: char const __near * DescForPhonemeByIndex(int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl DescForPhonemeByIndex(unsigned int index)
{
  if ( index > 0x35 )
    return nullptr;
  else
    return g_Phonemes[index].desc;
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x00534760
// Name: char const __near * ConvertPhoneme(int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl ConvertPhoneme(int code)
{
  PhonemeMap_t *v1; // ecx
  unsigned int v2; // eax

  v1 = g_Phonemes;
  v2 = 0;
  while ( v1->code != code )
  {
    v2 += 24;
    ++v1;
    if ( v2 >= 0x510 )
    {
      _Warning(a1: "Unrecognized phoneme code %i\n");
      return "<sil>";
    }
  }
  return v1->string;
}

//------------------------------------------------------------------------------
// Address: 0x005347A0
// Name: int NumPhonemes(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl NumPhonemes()
{
  return 54;
}

//------------------------------------------------------------------------------
// Address: 0x005347B0
// Name: char const __near * NameForPhonemeByIndex(int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl NameForPhonemeByIndex(int index)
{
  return g_Phonemes[index].string;
}

} // namespace sfmgen
