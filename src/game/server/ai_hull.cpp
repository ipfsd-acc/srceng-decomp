// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_hull.cpp
// Functions: 10
// ============================================================

#include "game\server\ai_hull.h"

//------------------------------------------------------------------------------
// Address: 0x10057120
// Name: class Vector const __near & NAI_Hull::Mins(int)
// Source: json
//------------------------------------------------------------------------------
const Vector *__cdecl NAI_Hull::Mins(int id)
{
  return &hull[id]->mins;
}

//------------------------------------------------------------------------------
// Address: 0x10057140
// Name: class Vector const __near & NAI_Hull::Maxs(int)
// Source: json
//------------------------------------------------------------------------------
const Vector *__cdecl NAI_Hull::Maxs(int id)
{
  return &hull[id]->maxs;
}

//------------------------------------------------------------------------------
// Address: 0x10057160
// Name: class Vector const __near & NAI_Hull::SmallMins(int)
// Source: json
//------------------------------------------------------------------------------
const Vector *__cdecl NAI_Hull::SmallMins(int id)
{
  return &hull[id]->smallMins;
}

//------------------------------------------------------------------------------
// Address: 0x10057180
// Name: class Vector const __near & NAI_Hull::SmallMaxs(int)
// Source: json
//------------------------------------------------------------------------------
const Vector *__cdecl NAI_Hull::SmallMaxs(int id)
{
  return &hull[id]->smallMaxs;
}

//------------------------------------------------------------------------------
// Address: 0x100571A0
// Name: float NAI_Hull::Length(int)
// Source: json
//------------------------------------------------------------------------------
double __cdecl NAI_Hull::Length(int id)
{
  return hull[id]->maxs.x - hull[id]->mins.x;
}

//------------------------------------------------------------------------------
// Address: 0x100571C0
// Name: float NAI_Hull::Width(int)
// Source: json
//------------------------------------------------------------------------------
double __cdecl NAI_Hull::Width(int id)
{
  return hull[id]->maxs.y - hull[id]->mins.y;
}

//------------------------------------------------------------------------------
// Address: 0x100571E0
// Name: float NAI_Hull::Height(int)
// Source: json
//------------------------------------------------------------------------------
double __cdecl NAI_Hull::Height(int id)
{
  return hull[id]->maxs.z - hull[id]->mins.z;
}

//------------------------------------------------------------------------------
// Address: 0x10057200
// Name: char const __near * NAI_Hull::Name(int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl NAI_Hull::Name(int id)
{
  return hull[id]->name;
}

//------------------------------------------------------------------------------
// Address: 0x10057220
// Name: unsigned int NAI_Hull::TraceMask(int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl NAI_Hull::TraceMask(int id)
{
  return hull[id]->nAITraceMask;
}

//------------------------------------------------------------------------------
// Address: 0x10057240
// Name: enum Hull_t NAI_Hull::LookupId(char const __near *)
// Source: json
//------------------------------------------------------------------------------
Hull_t __cdecl NAI_Hull::LookupId(const char *szName)
{
  int v2; // esi

  if ( szName == nullptr )
    return HULL_HUMAN;
  v2 = 0;
  while ( _V_stricmp(s1: szName, s2: hull[v2]->name) != 0 )
  {
    if ( ++v2 >= 12 )
      return HULL_HUMAN;
  }
  return v2;
}
