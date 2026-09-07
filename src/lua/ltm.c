// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: lua/ltm.c
// Functions: 3
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x004798A0
// Name: void luaT_init(struct lua_State __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaT_init(lua_State *L)
{
  int v1; // esi
  const char *const *i; // eax

  v1 = 47;
  for ( i = &luaT_eventname[-47]; ; i = &luaT_eventname[-47] )
  {
    *(GCObject ***)((char *)&L->l_G->strt.hash + v1 * 4) = (GCObject **)luaS_newlstr(L, str: i[v1], l: strlen(i[v1]));
    (*(_BYTE **)((char *)&L->l_G->strt.hash + v1 * 4))[5] |= 0x20u;
    if ( ++v1 >= 64 )
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00479910
// Name: struct lua_TValue const __near * luaT_gettm(struct Table __near *,enum TMS,union TString __near *)
// Source: json
//------------------------------------------------------------------------------
const lua_TValue *__cdecl luaT_gettm(Table *events, TMS event, TString *ename)
{
  const lua_TValue *result; // eax

  result = luaH_getstr(t: events, key: ename);
  if ( result->tt == 0 )
  {
    events->flags |= 1 << event;
    return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00479940
// Name: struct lua_TValue const __near * luaT_gettmbyobj(struct lua_State __near *,struct lua_TValue const __near *,enum TMS)
// Source: json
//------------------------------------------------------------------------------
const lua_TValue *__cdecl luaT_gettmbyobj(lua_State *L, const lua_TValue *o, TMS event)
{
  Table *v3; // eax

  if ( o->tt == 5 )
  {
    v3 = *(Table **)(o->value.b + 8);
  }
  else if ( o->tt == 7 )
  {
    v3 = *(Table **)(o->value.b + 8);
  }
  else
  {
    v3 = L->l_G->mt[o->tt];
  }
  if ( v3 != nullptr )
    return luaH_getstr(t: v3, key: L->l_G->tmname[event]);
  else
    return &luaO_nilobject_;
}
