// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: lua/lmem.c
// Functions: 3
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00484A10
// Name: void __near * luaM_toobig(struct lua_State __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn luaM_toobig(lua_State *L)
{
  luaG_runerror(L, fmt: "memory allocation error: block too big");
}

//------------------------------------------------------------------------------
// Address: 0x00484A30
// Name: void __near * luaM_realloc_(struct lua_State __near *,void __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl luaM_realloc_(lua_State *L, void *block, unsigned int osize, unsigned int nsize)
{
  global_State *l_G; // esi
  void *result; // eax

  l_G = L->l_G;
  result = l_G->frealloc(a1: l_G->ud, a2: block, a3: osize, a4: nsize);
  if ( result == nullptr && nsize != 0 )
    luaD_throw(L, errcode: 4);
  l_G->totalbytes += nsize - osize;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00484A80
// Name: void __near * luaM_growaux_(struct lua_State __near *,void __near *,int __near *,unsigned int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl luaM_growaux_(
        lua_State *L,
        void *block,
        int *size,
        unsigned int size_elems,
        int limit,
        const char *errormsg)
{
  int v6; // esi
  int v7; // ecx
  unsigned int v8; // esi
  unsigned int v9; // edi
  global_State *l_G; // ebx
  void *result; // eax

  v6 = limit;
  v7 = *size;
  if ( *size < limit / 2 )
  {
    limit = 2 * v7;
    if ( 2 * v7 >= 4 )
    {
      v6 = 2 * v7;
    }
    else
    {
      limit = 4;
      v6 = 4;
    }
  }
  else if ( v7 >= limit )
  {
    luaG_runerror(L, fmt: errormsg);
  }
  if ( v6 + 1 > 0xFFFFFFFD / size_elems )
    luaG_runerror(L, fmt: "memory allocation error: block too big");
  v8 = size_elems * v6;
  v9 = size_elems * *size;
  l_G = L->l_G;
  result = l_G->frealloc(a1: l_G->ud, a2: block, a3: v9, a4: v8);
  if ( result == nullptr && v8 != 0 )
    luaD_throw(L, errcode: 4);
  l_G->totalbytes += v8 - v9;
  *size = limit;
  return result;
}
