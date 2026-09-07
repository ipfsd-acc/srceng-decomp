// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier2/interval.cpp
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1027A960
// Name: struct interval_t ReadInterval(char const __near *)
// Source: json
//------------------------------------------------------------------------------
interval_t __cdecl ReadInterval(char *pString)
{
  const char *v1; // eax
  const char *v2; // eax
  long double v3; // st7
  char tempString[128]; // [esp+0h] [ebp-88h] BYREF
  interval_t tmp; // [esp+80h] [ebp-8h]

  tmp.start = 0.0;
  tmp.range = 0.0;
  V_strncpy(pDest: tempString, pSrc: pString, maxLen: 128);
  v1 = strtok(string: tempString, control: ",");
  if ( v1 != nullptr )
  {
    tmp.start = atof(nptr: v1);
    v2 = strtok(string: nullptr, control: ",");
    if ( v2 != nullptr )
    {
      v3 = atof(nptr: v2);
      tmp.range = v3 - tmp.start;
    }
  }
  return tmp;
}

//------------------------------------------------------------------------------
// Address: 0x1027A9E0
// Name: float RandomInterval(struct interval_t const __near &)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
double __cdecl RandomInterval(const interval_t *interval)
{
  IUniformRandomStream *v1; // ecx
  float range; // xmm0_4
  float start; // [esp+8h] [ebp+8h]

  start = interval->start;
  range = interval->range;
  if ( range == 0.0 )
    return start;
  else
    return _RandomFloat(this: v1, a2: 0.0, a3: range) + start;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1027AAA0
// Name: struct interval_t ReadInterval(char const __near *)
// Source: json
//------------------------------------------------------------------------------
interval_t __cdecl ReadInterval(const char *pString)
{
  const char *v1; // eax
  const char *v2; // eax
  long double v3; // st7
  char tempString[128]; // [esp+0h] [ebp-88h] BYREF
  interval_t tmp; // [esp+80h] [ebp-8h]

  tmp.start = 0.0;
  tmp.range = 0.0;
  V_strncpy(pDest: tempString, pSrc: pString, maxLen: 128);
  v1 = strtok(string: tempString, control: ",");
  if ( v1 != nullptr )
  {
    tmp.start = atof(nptr: v1);
    v2 = strtok(string: nullptr, control: ",");
    if ( v2 != nullptr )
    {
      v3 = atof(nptr: v2);
      tmp.range = v3 - tmp.start;
    }
  }
  return tmp;
}

//------------------------------------------------------------------------------
// Address: 0x1027AB20
// Name: float RandomInterval(struct interval_t const __near &)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
double __cdecl RandomInterval(const interval_t *interval)
{
  IUniformRandomStream *v1; // ecx
  float range; // xmm0_4
  float start; // [esp+8h] [ebp+8h]

  start = interval->start;
  range = interval->range;
  if ( range == 0.0 )
    return start;
  else
    return _RandomFloat(this: v1, a2: 0.0, a3: range) + start;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hlfaceposer (Missing functions)
// ============================================================
namespace hlfaceposer {

//------------------------------------------------------------------------------
// Address: 0x004CD9E0
// Name: struct interval_t ReadInterval(char const __near *)
// Source: json
//------------------------------------------------------------------------------
interval_t __cdecl ReadInterval(char *pString)
{
  const char *v1; // eax
  const char *v2; // eax
  long double v3; // st7
  char tempString[128]; // [esp+0h] [ebp-88h] BYREF
  interval_t tmp; // [esp+80h] [ebp-8h]

  tmp.start = 0.0;
  tmp.range = 0.0;
  V_strncpy(pDest: tempString, pSrc: pString, maxLen: 128);
  v1 = strtok(string: tempString, control: ",");
  if ( v1 != nullptr )
  {
    tmp.start = atof(nptr: v1);
    v2 = strtok(string: nullptr, control: ",");
    if ( v2 != nullptr )
    {
      v3 = atof(nptr: v2);
      tmp.range = v3 - tmp.start;
    }
  }
  return tmp;
}

} // namespace hlfaceposer

// ============================================================
// Overlay from scenemanager (Missing functions)
// ============================================================
namespace scenemanager {

//------------------------------------------------------------------------------
// Address: 0x00432770
// Name: struct interval_t ReadInterval(char const __near *)
// Source: json
//------------------------------------------------------------------------------
interval_t __cdecl ReadInterval(char *pString)
{
  const char *v1; // eax
  const char *v2; // eax
  long double v3; // st7
  char tempString[128]; // [esp+0h] [ebp-88h] BYREF
  interval_t tmp; // [esp+80h] [ebp-8h]

  tmp.start = 0.0;
  tmp.range = 0.0;
  V_strncpy(pDest: tempString, pSrc: pString, maxLen: 128);
  v1 = strtok(string: tempString, control: ",");
  if ( v1 != nullptr )
  {
    tmp.start = atof(nptr: v1);
    v2 = strtok(string: nullptr, control: ",");
    if ( v2 != nullptr )
    {
      v3 = atof(nptr: v2);
      tmp.range = v3 - tmp.start;
    }
  }
  return tmp;
}

} // namespace scenemanager

// ============================================================
// Overlay from SoundEmitterSystem (Missing functions)
// ============================================================
namespace SoundEmitterSystem {

//------------------------------------------------------------------------------
// Address: 0x1000E240
// Name: struct interval_t ReadInterval(char const __near *)
// Source: json
//------------------------------------------------------------------------------
interval_t __cdecl ReadInterval(char *pString)
{
  const char *v1; // eax
  const char *v2; // eax
  long double v3; // st7
  char tempString[128]; // [esp+0h] [ebp-88h] BYREF
  interval_t tmp; // [esp+80h] [ebp-8h]

  tmp.start = 0.0;
  tmp.range = 0.0;
  V_strncpy(pDest: tempString, pSrc: pString, maxLen: 128);
  v1 = strtok(string: tempString, control: ",");
  if ( v1 != nullptr )
  {
    tmp.start = atof(nptr: v1);
    v2 = strtok(string: nullptr, control: ",");
    if ( v2 != nullptr )
    {
      v3 = atof(nptr: v2);
      tmp.range = v3 - tmp.start;
    }
  }
  return tmp;
}

} // namespace SoundEmitterSystem

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x10370420
// Name: struct interval_t ReadInterval(char const __near *)
// Source: json
//------------------------------------------------------------------------------
interval_t __cdecl ReadInterval(char *pString)
{
  const char *v1; // eax
  const char *v2; // eax
  long double v3; // st7
  char tempString[128]; // [esp+0h] [ebp-88h] BYREF
  interval_t tmp; // [esp+80h] [ebp-8h]

  tmp.start = 0.0;
  tmp.range = 0.0;
  V_strncpy(pDest: tempString, pSrc: pString, maxLen: 128);
  v1 = strtok(string: tempString, control: ",");
  if ( v1 != nullptr )
  {
    tmp.start = atof(nptr: v1);
    v2 = strtok(string: nullptr, control: ",");
    if ( v2 != nullptr )
    {
      v3 = atof(nptr: v2);
      tmp.range = v3 - tmp.start;
    }
  }
  return tmp;
}

//------------------------------------------------------------------------------
// Address: 0x103704A0
// Name: float RandomInterval(struct interval_t const __near &)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
double __cdecl RandomInterval(const interval_t *interval)
{
  IUniformRandomStream *v1; // ecx
  float range; // xmm0_4
  float out; // [esp+10h] [ebp+8h]

  out = interval->start;
  range = interval->range;
  if ( range == 0.0 )
    return out;
  else
    return _RandomFloat(this: v1, a2: 0.0, a3: range) + out;
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x1037F120
// Name: struct interval_t ReadInterval(char const __near *)
// Source: json
//------------------------------------------------------------------------------
interval_t __cdecl ReadInterval(char *pString)
{
  const char *v1; // eax
  const char *v2; // eax
  long double v3; // st7
  char tempString[128]; // [esp+0h] [ebp-88h] BYREF
  interval_t tmp; // [esp+80h] [ebp-8h]

  tmp.start = 0.0;
  tmp.range = 0.0;
  V_strncpy(pDest: tempString, pSrc: pString, maxLen: 128);
  v1 = strtok(string: tempString, control: ",");
  if ( v1 != nullptr )
  {
    tmp.start = atof(nptr: v1);
    v2 = strtok(string: nullptr, control: ",");
    if ( v2 != nullptr )
    {
      v3 = atof(nptr: v2);
      tmp.range = v3 - tmp.start;
    }
  }
  return tmp;
}

//------------------------------------------------------------------------------
// Address: 0x1037F1A0
// Name: float RandomInterval(struct interval_t const __near &)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
double __cdecl RandomInterval(const interval_t *interval)
{
  IUniformRandomStream *v1; // ecx
  float range; // xmm0_4
  float out; // [esp+10h] [ebp+8h]

  out = interval->start;
  range = interval->range;
  if ( range == 0.0 )
    return out;
  else
    return _RandomFloat(this: v1, a2: 0.0, a3: range) + out;
}

} // namespace server
