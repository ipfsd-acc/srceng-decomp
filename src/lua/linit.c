// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: lua/linit.c
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x004768A0
// Name: void luaL_openlibs(struct lua_State __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaL_openlibs(lua_State *L)
{
  int (__cdecl *func)(lua_State *); // eax
  const luaL_Reg *i; // esi

  func = luaopen_base;
  for ( i = lualibs; func != nullptr; ++i )
  {
    lua_pushcclosure(L, fn: func, n: 0);
    lua_pushstring(L, s: i->name);
    lua_call(L, nargs: 1, nresults: 0);
    func = i[1].func;
  }
}
