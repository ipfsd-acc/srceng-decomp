// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vscript/languages/lua/lua-5.1.4/src/lzio.c
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x100229C0
// Name: _luaZ_fill
// Source: json
//------------------------------------------------------------------------------
int __usercall luaZ_fill@<eax>(Zio *z@<esi>, int a2@<ecx>)
{
  const char *v2; // eax
  int v3; // ecx

  v2 = (const char *)((int (__stdcall *)(lua_State *))z->reader)(a1: z->L);
  if ( v2 == nullptr || a2 == 0 )
    return -1;
  z->p = v2;
  z->n = a2 - 1;
  v3 = *(unsigned __int8 *)v2;
  z->p = v2 + 1;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10022A00
// Name: _luaZ_read
// Source: json
//------------------------------------------------------------------------------
unsigned int __usercall luaZ_read@<eax>(Zio *z@<esi>, unsigned __int8 *b, unsigned int n)
{
  unsigned int v3; // edi
  const char *v4; // eax
  unsigned int v5; // ecx
  const char *v6; // eax
  unsigned __int8 *p; // eax
  bool v8; // zf
  int v10; // [esp+8h] [ebp-4h] BYREF

  v3 = n;
  if ( n != 0 )
  {
    while ( 1 )
    {
      if ( z->n == 0 )
      {
        v4 = z->reader(a1: z->L, a2: z->data, a3: &v10);
        if ( v4 == nullptr || v10 == 0 )
          return v3;
        v5 = v10 - 1;
        z->p = v4;
        z->n = v5;
        v6 = v4 + 1;
        z->p = v6;
        z->n = v5 + 1;
        z->p = v6 - 1;
      }
      p = (unsigned __int8 *)z->p;
      if ( *p == -1 )
        return v3;
      if ( v3 > z->n )
        v3 = z->n;
      memcpy(dst: b, src: p, count: v3);
      z->n -= v3;
      z->p += v3;
      v8 = n == v3;
      n -= v3;
      b += v3;
      if ( v8 )
        return 0;
      v3 = n;
    }
  }
  return 0;
}
