// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: lua/lzio.c
// Functions: 5
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0047D060
// Name: int luaZ_fill(struct Zio __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaZ_fill(Zio *z)
{
  Zio *v1; // esi
  const char *v2; // eax
  Zio *v3; // ecx
  int v4; // ecx

  v1 = z;
  v2 = z->reader(a1: z->L, a2: z->data, a3: &z);
  if ( v2 == nullptr )
    return -1;
  v3 = z;
  if ( z == nullptr )
    return -1;
  v1->p = v2;
  v1->n = (unsigned int)&v3[-1].L + 3;
  v4 = *(unsigned __int8 *)v2;
  v1->p = v2 + 1;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0047D0A0
// Name: int luaZ_lookahead(struct Zio __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaZ_lookahead(Zio *z)
{
  Zio *v1; // esi
  const char *v2; // eax
  char *v3; // ecx
  const char *v4; // eax

  v1 = z;
  if ( z->n == 0 )
  {
    v2 = z->reader(a1: z->L, a2: z->data, a3: &z);
    if ( v2 == nullptr || z == nullptr )
      return -1;
    v3 = (char *)&z[-1].L + 3;
    v1->p = v2;
    v1->n = (unsigned int)v3;
    v4 = v2 + 1;
    v1->p = v4;
    v1->n = (unsigned int)(v3 + 1);
    v1->p = v4 - 1;
  }
  return *(unsigned __int8 *)v1->p;
}

//------------------------------------------------------------------------------
// Address: 0x0047D100
// Name: void luaZ_init(struct lua_State __near *,struct Zio __near *,char const __near * (*)(struct lua_State __near *,void __near *,unsigned int __near *),void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaZ_init(
        lua_State *L,
        Zio *z,
        const char *(__cdecl *reader)(lua_State *, void *, unsigned int *),
        void *data)
{
  z->L = L;
  z->reader = reader;
  z->data = data;
  z->n = 0;
  z->p = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0047D130
// Name: unsigned int luaZ_read(struct Zio __near *,void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl luaZ_read(Zio *z, unsigned __int8 *b, unsigned int n)
{
  unsigned int v3; // ebx
  const char *v4; // eax
  unsigned int v5; // ecx
  const char *v6; // eax
  unsigned __int8 *p; // eax
  unsigned int v8; // edi

  v3 = n;
  if ( n == 0 )
    return 0;
  while ( 1 )
  {
    if ( z->n == 0 )
    {
      v4 = z->reader(a1: z->L, a2: z->data, a3: &n);
      if ( v4 == nullptr || n == 0 )
        break;
      v5 = n - 1;
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
    v8 = z->n;
    if ( v3 <= z->n )
      v8 = v3;
    memcpy(dst: b, src: p, count: v8);
    z->n -= v8;
    z->p += v8;
    b += v8;
    v3 -= v8;
    if ( v3 == 0 )
      return 0;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x0047D1C0
// Name: char __near * luaZ_openspace(struct lua_State __near *,struct Mbuffer __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl luaZ_openspace(lua_State *L, Mbuffer *buff, unsigned int n)
{
  unsigned int v3; // esi
  unsigned int buffsize; // eax
  char *result; // eax

  v3 = n;
  buffsize = buff->buffsize;
  if ( n <= buffsize )
    return buff->buffer;
  if ( n < 0x20 )
    v3 = 32;
  if ( v3 + 1 > 0xFFFFFFFD )
    luaM_toobig(L);
  result = (char *)luaM_realloc_(L, block: buff->buffer, osize: buffsize, nsize: v3);
  buff->buffsize = v3;
  buff->buffer = result;
  return result;
}
