// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vscript/languages/lua/lua-5.1.4/src/linit.c
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1000CE40
// Name: _luaL_openlibs
// Source: json
//------------------------------------------------------------------------------
void __usercall luaL_openlibs(GCObject *L@<eax>)
{
  int (__cdecl **p_func)(lua_State *); // edi
  const char *v3; // ebx
  lua_TValue *k; // edi
  unsigned int v5; // [esp+4h] [ebp-8h]
  int (__cdecl **v6)(lua_State *); // [esp+8h] [ebp-4h]

  if ( luaopen_base != nullptr )
  {
    p_func = &lualibs[0].func;
    v6 = &lualibs[0].func;
    do
    {
      lua_pushcclosure((lua_State *)L, fn: *p_func, n: 0);
      v3 = (const char *)*(p_func - 1);
      if ( v3 != nullptr )
      {
        v5 = strlen((const char *)*(p_func - 1));
        if ( *(_DWORD *)(L->ts.tsv.len + 68) >= *(_DWORD *)(L->ts.tsv.len + 64) )
          luaC_step(L);
        k = L->p.k;
        k->value.b = (int)luaS_newlstr((lua_State *)L, str: v3, l: v5);
        k->tt = 4;
        p_func = v6;
      }
      else
      {
        *(_DWORD *)(L->ts.tsv.hash + 8) = 0;
      }
      L->ts.tsv.hash += 16;
      luaD_call((lua_State *)L, func: (lua_TValue *)(L->ts.tsv.hash - 32), nResults: 0);
      p_func += 2;
      v6 = p_func;
    }
    while ( *p_func != nullptr );
  }
}
