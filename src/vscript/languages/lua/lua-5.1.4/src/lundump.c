// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vscript/languages/lua/lua-5.1.4/src/lundump.c
// Functions: 8
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1001F980
// Name: error
// Source: json
//------------------------------------------------------------------------------
void __usercall __noreturn error(LoadState *S@<esi>)
{
  const char *v2; // [esp+0h] [ebp-8h]

  luaO_pushfstring(L: S->L, fmt: "%s: %s in precompiled chunk", S->name, v2);
  luaD_throw(L: S->L, errcode: 3);
}

//------------------------------------------------------------------------------
// Address: 0x1001F9B0
// Name: LoadString
// Source: json
//------------------------------------------------------------------------------
GCObject *__cdecl LoadString(LoadState *S)
{
  unsigned int v1; // esi
  Mbuffer *b; // ebx
  unsigned int buffsize; // eax
  lua_State *v5; // edx
  unsigned int v6; // edi
  global_State *l_G; // esi
  int v8; // eax
  char *buffer; // ebx
  unsigned int size; // [esp+Ch] [ebp-Ch] BYREF
  lua_State *L; // [esp+10h] [ebp-8h]
  unsigned int v12; // [esp+14h] [ebp-4h]

  if ( luaZ_read(z: S->Z, b: &size, n: 4u) != 0 )
    error(S);
  v1 = size;
  if ( size == 0 )
    return nullptr;
  b = S->b;
  buffsize = b->buffsize;
  v5 = S->L;
  v6 = size;
  L = S->L;
  v12 = buffsize;
  if ( size > buffsize )
  {
    if ( size < 0x20 )
      v6 = 32;
    if ( v6 + 1 > 0xFFFFFFFD )
      luaG_runerror(L: v5, fmt: "memory allocation error: block too big");
    l_G = v5->l_G;
    v8 = (int)l_G->frealloc(a1: l_G->ud, a2: b->buffer, a3: buffsize, a4: v6);
    if ( v8 == 0 )
      luaD_throw(L, errcode: 4);
    l_G->totalbytes += v6 - v12;
    v1 = size;
    b->buffer = (char *)v8;
    b->buffsize = v6;
  }
  buffer = b->buffer;
  if ( luaZ_read(z: S->Z, b: buffer, n: v1) != 0 )
    error(S);
  return luaS_newlstr(L: S->L, str: buffer, l: size - 1);
}

//------------------------------------------------------------------------------
// Address: 0x1001FAB0
// Name: LoadCode
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadCode(LoadState *S, Proto *f)
{
  int v2; // edi
  global_State *l_G; // esi
  void *ud; // edx
  unsigned int *v5; // eax
  int v6; // esi
  int b; // [esp+10h] [ebp-8h] BYREF
  lua_State *L; // [esp+14h] [ebp-4h]

  if ( luaZ_read(z: S->Z, &b, n: 4u) != 0 )
    error(S);
  if ( b < 0 )
    error(S);
  if ( (unsigned int)(b + 1) > 0x3FFFFFFF )
    luaG_runerror(L: S->L, fmt: "memory allocation error: block too big");
  v2 = 4 * b;
  l_G = S->L->l_G;
  ud = l_G->ud;
  L = S->L;
  v5 = (unsigned int *)l_G->frealloc(a1: ud, a2: nullptr, a3: 0, a4: 4 * b);
  if ( v5 == nullptr && v2 != 0 )
    luaD_throw(L, errcode: 4);
  l_G->totalbytes += v2;
  v6 = b;
  f->code = v5;
  f->sizecode = v6;
  if ( luaZ_read(z: S->Z, b: v5, n: 4 * v6) != 0 )
    error(S);
}

//------------------------------------------------------------------------------
// Address: 0x1001FB90
// Name: LoadConstants
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadConstants(LoadState *S, Proto *f)
{
  int v2; // esi
  int v3; // edi
  lua_TValue *v4; // eax
  LoadState *v5; // edi
  int v6; // esi
  int v7; // eax
  int j; // ecx
  lua_TValue *v9; // edi
  bool v10; // zf
  int v11; // esi
  int v12; // edi
  Proto **v13; // eax
  int v14; // eax
  int k; // edi
  int v16; // [esp-4h] [ebp-2Ch]
  char v17; // [esp+12h] [ebp-16h] BYREF
  char v18; // [esp+13h] [ebp-15h] BYREF
  unsigned int v19; // [esp+14h] [ebp-14h]
  int b; // [esp+18h] [ebp-10h] BYREF
  int i; // [esp+1Ch] [ebp-Ch] BYREF
  long double v22; // [esp+20h] [ebp-8h] BYREF

  if ( luaZ_read(z: S->Z, &b, n: 4u) != 0 )
    error(S);
  if ( b < 0 )
    error(S);
  if ( (unsigned int)(b + 1) > 0xFFFFFFF )
    luaG_runerror(L: S->L, fmt: "memory allocation error: block too big");
  v2 = 16 * b;
  i = (int)S->L;
  v3 = *(_DWORD *)(i + 16);
  v4 = (lua_TValue *)(*(int (__cdecl **)(_DWORD, _DWORD, _DWORD, int))(v3 + 12))(
                       a1: *(_DWORD *)(v3 + 16),
                       a2: 0,
                       a3: 0,
                       a4: 16 * b);
  if ( v4 == nullptr && v2 != 0 )
    luaD_throw(L: (lua_State *)i, errcode: 4);
  *(_DWORD *)(v3 + 68) += v2;
  v5 = S;
  v6 = b;
  f->k = v4;
  f->sizek = v6;
  if ( v6 > 0 )
  {
    v7 = 0;
    for ( j = v6; j != 0; --j )
      f->k[v7++].tt = 0;
  }
  i = 0;
  if ( v6 > 0 )
  {
    v19 = 0;
    do
    {
      v9 = &f->k[v19 / 0x10];
      if ( luaZ_read(z: S->Z, b: &v17, n: 1u) != 0 )
        error(S);
      switch ( v17 )
      {
        case 0:
          v9->tt = 0;
          break;
        case 1:
          if ( luaZ_read(z: S->Z, b: &v18, n: 1u) != 0 )
            error(S);
          v10 = v18 == 0;
          v9->tt = 1;
          v9->value.b = !v10;
          break;
        case 3:
          if ( luaZ_read(z: S->Z, b: &v22, n: 8u) != 0 )
            error(S);
          v9->value.n = v22;
          v9->tt = 3;
          break;
        case 4:
          v9->value.b = (int)LoadString(S);
          v9->tt = 4;
          break;
        default:
          error(S);
      }
      v19 += 16;
      ++i;
    }
    while ( i < b );
    v5 = S;
  }
  if ( luaZ_read(z: v5->Z, b: &i, n: 4u) != 0 )
    error(S: v5);
  v11 = i;
  if ( i < 0 )
    error(S: v5);
  if ( (unsigned int)(i + 1) > 0x3FFFFFFF )
    luaG_runerror(L: v5->L, fmt: "memory allocation error: block too big");
  v16 = 4 * i;
  i = (int)v5->L;
  v12 = *(_DWORD *)(i + 16);
  v13 = (Proto **)(*(int (__cdecl **)(_DWORD, _DWORD, _DWORD, int))(v12 + 12))(
                    a1: *(_DWORD *)(v12 + 16),
                    a2: 0,
                    a3: 0,
                    a4: v16);
  if ( v13 == nullptr && 4 * v11 != 0 )
    luaD_throw(L: (lua_State *)i, errcode: 4);
  *(_DWORD *)(v12 + 68) += 4 * v11;
  f->p = v13;
  v14 = 0;
  for ( f->sizep = v11; v14 < v11; ++v14 )
    f->p[v14] = nullptr;
  for ( k = 0; k < v11; ++k )
    f->p[k] = LoadFunction(S, p: f->source);
}

//------------------------------------------------------------------------------
// Address: 0x1001FE60
// Name: LoadDebug
// Source: json
//------------------------------------------------------------------------------
void __usercall LoadDebug(Proto *f@<edi>, LoadState *S)
{
  LoadState *v2; // ebx
  global_State *l_G; // esi
  void *(__cdecl *frealloc)(void *, void *, unsigned int, unsigned int); // eax
  int *v5; // eax
  int v6; // esi
  int v7; // esi
  int v8; // eax
  int (__cdecl *v9)(int, _DWORD, _DWORD, int); // edx
  LocVar *v10; // eax
  int v11; // esi
  int v12; // eax
  int j; // ecx
  int v14; // ebx
  int v15; // esi
  global_State *v16; // ebx
  TString **v17; // eax
  int v18; // eax
  int k; // ebx
  void *ud; // [esp-10h] [ebp-28h]
  int v21; // [esp-10h] [ebp-28h]
  unsigned int v22; // [esp-4h] [ebp-1Ch]
  int v23; // [esp-4h] [ebp-1Ch]
  int b; // [esp+8h] [ebp-10h] BYREF
  int i; // [esp+Ch] [ebp-Ch]
  int v26; // [esp+10h] [ebp-8h] BYREF
  lua_State *L; // [esp+14h] [ebp-4h] BYREF

  v2 = S;
  if ( luaZ_read(z: S->Z, &b, n: 4u) != 0 )
    error(S);
  if ( b < 0 )
    error(S);
  if ( (unsigned int)(b + 1) > 0x3FFFFFFF )
    luaG_runerror(L: S->L, fmt: "memory allocation error: block too big");
  l_G = S->L->l_G;
  frealloc = l_G->frealloc;
  ud = l_G->ud;
  i = (int)S->L;
  v5 = (int *)frealloc(a1: ud, a2: nullptr, a3: 0, a4: 4 * b);
  if ( v5 == nullptr && 4 * b != 0 )
    luaD_throw(L: (lua_State *)i, errcode: 4);
  l_G->totalbytes += 4 * b;
  v6 = b;
  v22 = 4 * b;
  f->lineinfo = v5;
  f->sizelineinfo = v6;
  if ( luaZ_read(z: S->Z, b: v5, n: v22) != 0 )
    error(S);
  if ( luaZ_read(z: S->Z, &b, n: 4u) != 0 )
    error(S);
  if ( b < 0 )
    error(S);
  if ( (unsigned int)(b + 1) > 0x15555555 )
    luaG_runerror(L: S->L, fmt: "memory allocation error: block too big");
  v7 = 12 * b;
  i = (int)S->L;
  v8 = *(_DWORD *)(i + 16);
  v9 = *(int (__cdecl **)(int, _DWORD, _DWORD, int))(v8 + 12);
  v21 = *(_DWORD *)(v8 + 16);
  v26 = v8;
  v10 = (LocVar *)v9(a1: v21, a2: 0, a3: 0, a4: 12 * b);
  if ( v10 == nullptr && v7 != 0 )
    luaD_throw(L: (lua_State *)i, errcode: 4);
  *(_DWORD *)(v26 + 68) += v7;
  v11 = b;
  f->locvars = v10;
  f->sizelocvars = v11;
  if ( v11 > 0 )
  {
    v12 = 0;
    for ( j = v11; j != 0; --j )
      f->locvars[v12++].varname = nullptr;
  }
  i = 0;
  if ( v11 > 0 )
  {
    v14 = 0;
    do
    {
      f->locvars[v14].varname = (TString *)LoadString(S);
      if ( luaZ_read(z: S->Z, b: &v26, n: 4u) != 0 )
        error(S);
      if ( v26 < 0 )
        error(S);
      f->locvars[v14].startpc = v26;
      if ( luaZ_read(z: S->Z, b: &L, n: 4u) != 0 )
        error(S);
      if ( (int)L < 0 )
        error(S);
      f->locvars[v14++].endpc = (int)L;
      ++i;
    }
    while ( i < b );
    v2 = S;
  }
  if ( luaZ_read(z: v2->Z, b: &L, n: 4u) != 0 )
    error(S: v2);
  v15 = (int)L;
  if ( (int)L < 0 )
    error(S: v2);
  if ( (unsigned int)&L->next + 1 > 0x3FFFFFFF )
    luaG_runerror(L: v2->L, fmt: "memory allocation error: block too big");
  v23 = 4 * (_DWORD)L;
  L = v2->L;
  v16 = L->l_G;
  v17 = (TString **)v16->frealloc(a1: v16->ud, a2: nullptr, a3: 0, a4: v23);
  if ( v17 == nullptr && 4 * v15 != 0 )
    luaD_throw(L, errcode: 4);
  v16->totalbytes += 4 * v15;
  f->upvalues = v17;
  v18 = 0;
  for ( f->sizeupvalues = v15; v18 < v15; ++v18 )
    f->upvalues[v18] = nullptr;
  for ( k = 0; k < v15; ++k )
    f->upvalues[k] = (TString *)LoadString(S);
}

//------------------------------------------------------------------------------
// Address: 0x10020190
// Name: LoadFunction
// Source: json
//------------------------------------------------------------------------------
Proto *__cdecl LoadFunction(LoadState *S, TString *p)
{
  lua_State *v2; // eax
  global_State *l_G; // esi
  int v4; // edi
  global_State *v5; // eax
  LoadState *v6; // esi
  unsigned __int8 currentwhite; // dl
  lua_TValue *top; // eax
  int stacksize; // eax
  int v10; // eax
  GCObject *String; // eax
  char b; // [esp+13h] [ebp-5h] BYREF
  lua_State *L; // [esp+14h] [ebp-4h] BYREF

  v2 = S->L;
  if ( ++v2->nCcalls > 0xC8u )
    error(S);
  L = S->L;
  l_G = L->l_G;
  v4 = (int)l_G->frealloc(a1: l_G->ud, a2: nullptr, a3: 0, a4: 76u);
  if ( v4 == 0 )
    luaD_throw(L, errcode: 4);
  l_G->totalbytes += 76;
  v5 = L->l_G;
  v6 = S;
  *(_DWORD *)v4 = v5->rootgc;
  currentwhite = v5->currentwhite;
  v5->rootgc = (GCObject *)v4;
  *(_DWORD *)(v4 + 8) = 0;
  *(_DWORD *)(v4 + 40) = 0;
  *(_DWORD *)(v4 + 16) = 0;
  *(_DWORD *)(v4 + 52) = 0;
  *(_DWORD *)(v4 + 12) = 0;
  *(_DWORD *)(v4 + 44) = 0;
  *(_DWORD *)(v4 + 48) = 0;
  *(_DWORD *)(v4 + 36) = 0;
  *(_DWORD *)(v4 + 28) = 0;
  *(_DWORD *)(v4 + 72) = 0;
  *(_DWORD *)(v4 + 20) = 0;
  *(_DWORD *)(v4 + 56) = 0;
  *(_DWORD *)(v4 + 24) = 0;
  *(_DWORD *)(v4 + 60) = 0;
  *(_DWORD *)(v4 + 64) = 0;
  *(_DWORD *)(v4 + 32) = 0;
  *(_BYTE *)(v4 + 5) = currentwhite & 3;
  *(_BYTE *)(v4 + 4) = 9;
  top = S->L->top;
  top->value.b = v4;
  top->tt = 9;
  if ( (char *)v6->L->stack_last - (char *)v6->L->top <= 16 )
  {
    stacksize = S->L->stacksize;
    if ( stacksize < 1 )
      v10 = stacksize + 1;
    else
      v10 = 2 * stacksize;
    luaD_reallocstack(L: S->L, newsize: v10);
    v6 = S;
  }
  ++v6->L->top;
  String = LoadString(S: v6);
  *(_DWORD *)(v4 + 32) = String;
  if ( String == nullptr )
    *(_DWORD *)(v4 + 32) = p;
  if ( luaZ_read(z: v6->Z, b: &L, n: 4u) != 0 )
    error(S);
  if ( (int)L < 0 )
    error(S);
  *(_DWORD *)(v4 + 60) = L;
  if ( luaZ_read(z: S->Z, b: &L, n: 4u) != 0 )
    error(S);
  if ( (int)L < 0 )
    error(S);
  *(_DWORD *)(v4 + 64) = L;
  if ( luaZ_read(z: S->Z, &b, n: 1u) != 0 )
    error(S);
  *(_BYTE *)(v4 + 72) = b;
  if ( luaZ_read(z: S->Z, &b, n: 1u) != 0 )
    error(S);
  *(_BYTE *)(v4 + 73) = b;
  if ( luaZ_read(z: S->Z, &b, n: 1u) != 0 )
    error(S);
  *(_BYTE *)(v4 + 74) = b;
  if ( luaZ_read(z: S->Z, &b, n: 1u) != 0 )
    error(S);
  *(_BYTE *)(v4 + 75) = b;
  LoadCode(S, f: (Proto *)v4);
  LoadConstants(S, f: (Proto *)v4);
  LoadDebug(f: (Proto *)v4, S);
  if ( symbexec(pt: (const Proto *)v4, lastpc: *(_DWORD *)(v4 + 44), reg: 255) == 0 )
    error(S);
  --S->L->top;
  --S->L->nCcalls;
  return (Proto *)v4;
}

//------------------------------------------------------------------------------
// Address: 0x10020400
// Name: LoadHeader
// Source: json
//------------------------------------------------------------------------------
void __usercall LoadHeader(LoadState *S@<edi>)
{
  Zio *Z; // esi
  unsigned int v2; // eax
  int v3; // ecx
  _DWORD b[3]; // [esp+8h] [ebp-18h] BYREF
  char h[12]; // [esp+14h] [ebp-Ch]

  Z = S->Z;
  *(_DWORD *)h = 1635077147;
  *(_DWORD *)&h[4] = 67174481;
  *(_DWORD *)&h[8] = 525316;
  if ( luaZ_read(z: Z, b, n: 0xCu) != 0 )
    error(S);
  v2 = 12;
  v3 = 0;
  do
  {
    if ( *(_DWORD *)&h[v3 * 4] != b[v3] )
      error(S);
    v2 -= 4;
    ++v3;
  }
  while ( v2 >= 4 );
}

//------------------------------------------------------------------------------
// Address: 0x10020470
// Name: _luaU_undump
// Source: json
//------------------------------------------------------------------------------
Proto *__cdecl luaU_undump(lua_State *L, Zio *Z, Mbuffer *buff, const char *name)
{
  const char *v4; // ecx
  char v5; // al
  GCObject *v6; // eax
  LoadState S; // [esp+8h] [ebp-10h] BYREF

  v4 = name;
  v5 = *name;
  if ( *name == 64 || v5 == 61 )
  {
    v4 = name + 1;
  }
  else if ( v5 == 27 )
  {
    S.name = "binary string";
LABEL_7:
    S.L = L;
    S.Z = Z;
    S.b = buff;
    LoadHeader(&S);
    v6 = luaS_newlstr(L, str: "=?", l: 2u);
    return LoadFunction(&S, p: (TString *)v6);
  }
  S.name = v4;
  goto LABEL_7;
}
