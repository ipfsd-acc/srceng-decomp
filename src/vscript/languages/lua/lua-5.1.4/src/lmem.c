// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vscript/languages/lua/lua-5.1.4/src/lmem.c
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x100115A0
// Name: _luaM_growaux_
// Source: json
//------------------------------------------------------------------------------
void *__usercall luaM_growaux_@<eax>(
        int limit@<eax>,
        lua_State *L,
        void *block,
        int *size,
        unsigned int size_elems,
        const char *errormsg)
{
  int v6; // ecx
  unsigned int v7; // esi
  unsigned int v8; // edi
  global_State *l_G; // ebx
  void *result; // eax
  int newsize; // [esp+Ch] [ebp-4h]

  v6 = *size;
  if ( *size < limit / 2 )
  {
    newsize = 2 * v6;
    if ( 2 * v6 < 4 )
      newsize = 4;
  }
  else
  {
    if ( v6 >= limit )
      luaG_runerror(L, fmt: errormsg);
    newsize = limit;
  }
  if ( newsize + 1 > 0xFFFFFFFD / size_elems )
    luaG_runerror(L, fmt: "memory allocation error: block too big");
  v7 = size_elems * newsize;
  v8 = size_elems * *size;
  l_G = L->l_G;
  result = l_G->frealloc(a1: l_G->ud, a2: block, a3: v8, a4: size_elems * newsize);
  if ( result == nullptr && v7 != 0 )
    luaD_throw(L, errcode: 4);
  l_G->totalbytes += v7 - v8;
  *size = newsize;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10011670
// Name: _luaM_realloc_
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
