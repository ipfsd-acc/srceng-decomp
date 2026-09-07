// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: lua/lundump.c
// Functions: 9
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00489210
// Name: LoadInt
// Source: json
//------------------------------------------------------------------------------
int __usercall LoadInt@<eax>(LoadState *S@<esi>, int a2@<ecx>)
{
  int result; // eax
  int x; // [esp+0h] [ebp-4h] BYREF

  x = a2;
  if ( luaZ_read(z: S->Z, b: (unsigned __int8 *)&x, n: 4u) != 0 )
  {
    luaO_pushfstring(L: (lua_TValue *)S->L, fmt: "%s: %s in precompiled chunk", S->name, "unexpected end");
    luaD_throw(L: S->L, errcode: 3);
  }
  result = x;
  if ( x < 0 )
  {
    luaO_pushfstring(L: (lua_TValue *)S->L, fmt: "%s: %s in precompiled chunk", S->name, "bad integer");
    luaD_throw(L: S->L, errcode: 3);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00489280
// Name: LoadString
// Source: json
//------------------------------------------------------------------------------
GCObject *__usercall LoadString@<eax>(LoadState *S@<esi>, unsigned int a2@<ecx>)
{
  GCObject *result; // eax
  unsigned __int8 *v3; // edi
  unsigned int size; // [esp+0h] [ebp-4h] BYREF

  size = a2;
  if ( luaZ_read(z: S->Z, b: (unsigned __int8 *)&size, n: 4u) != 0 )
  {
    luaO_pushfstring(L: (lua_TValue *)S->L, fmt: "%s: %s in precompiled chunk", S->name, "unexpected end");
    luaD_throw(L: S->L, errcode: 3);
  }
  result = (GCObject *)size;
  if ( size != 0 )
  {
    v3 = (unsigned __int8 *)luaZ_openspace(L: S->L, buff: S->b, n: size);
    if ( luaZ_read(z: S->Z, b: v3, n: size) != 0 )
    {
      luaO_pushfstring(L: (lua_TValue *)S->L, fmt: "%s: %s in precompiled chunk", S->name, "unexpected end");
      luaD_throw(L: S->L, errcode: 3);
    }
    return luaS_newlstr(L: S->L, str: (char *)v3, l: size - 1);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00489330
// Name: LoadCode
// Source: json
//------------------------------------------------------------------------------
void __usercall LoadCode(LoadState *S@<eax>, int a2@<ecx>, Proto *f)
{
  int Int; // edi
  unsigned int *v5; // eax

  Int = LoadInt(S, a2);
  if ( (unsigned int)(Int + 1) > 0x3FFFFFFF )
    luaM_toobig(L: S->L);
  v5 = (unsigned int *)luaM_realloc_(L: S->L, block: nullptr, osize: 0, nsize: 4 * Int);
  f->code = v5;
  f->sizecode = Int;
  if ( luaZ_read(z: S->Z, b: (unsigned __int8 *)v5, n: 4 * Int) != 0 )
  {
    luaO_pushfstring(L: (lua_TValue *)S->L, fmt: "%s: %s in precompiled chunk", S->name, "unexpected end");
    luaD_throw(L: S->L, errcode: 3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004893C0
// Name: LoadConstants
// Source: json
//------------------------------------------------------------------------------
void __usercall LoadConstants(LoadState *S@<eax>, int a2@<ecx>, Proto *f)
{
  int Int; // edi
  int v5; // eax
  int i; // ecx
  lua_TValue *v7; // edi
  unsigned int v8; // ecx
  int v9; // edi
  int v10; // eax
  int k; // ebx
  long double v12; // [esp+Ch] [ebp-14h] BYREF
  int j; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v14; // [esp+18h] [ebp-8h]
  char v15; // [esp+1Eh] [ebp-2h] BYREF
  unsigned __int8 b; // [esp+1Fh] [ebp-1h] BYREF

  Int = LoadInt(S, a2);
  if ( (unsigned int)(Int + 1) > 0xFFFFFFF )
    luaM_toobig(L: S->L);
  f->k = (lua_TValue *)luaM_realloc_(L: S->L, block: nullptr, osize: 0, nsize: 16 * Int);
  f->sizek = Int;
  if ( Int > 0 )
  {
    v5 = 0;
    for ( i = Int; i != 0; --i )
      f->k[v5++].tt = 0;
    v14 = 0;
    for ( j = Int; j != 0; --j )
    {
      v7 = &f->k[v14 / 0x10];
      if ( luaZ_read(z: S->Z, &b, n: 1u) != 0 )
      {
        luaO_pushfstring(L: (lua_TValue *)S->L, fmt: "%s: %s in precompiled chunk", S->name, "unexpected end");
        luaD_throw(L: S->L, errcode: 3);
      }
      switch ( b )
      {
        case 0u:
          v7->tt = 0;
          break;
        case 1u:
          if ( luaZ_read(z: S->Z, b: (unsigned __int8 *)&v15, n: 1u) != 0 )
          {
            luaO_pushfstring(L: (lua_TValue *)S->L, fmt: "%s: %s in precompiled chunk", S->name, "unexpected end");
            luaD_throw(L: S->L, errcode: 3);
          }
          v7->value.b = v15;
          v7->tt = 1;
          break;
        case 3u:
          if ( luaZ_read(z: S->Z, b: (unsigned __int8 *)&v12, n: 8u) != 0 )
          {
            luaO_pushfstring(L: (lua_TValue *)S->L, fmt: "%s: %s in precompiled chunk", S->name, "unexpected end");
            luaD_throw(L: S->L, errcode: 3);
          }
          v7->value.n = v12;
          v7->tt = 3;
          break;
        case 4u:
          v7->value.b = (int)LoadString(S, a2: v8);
          v7->tt = 4;
          break;
        default:
          luaO_pushfstring(L: (lua_TValue *)S->L, fmt: "%s: %s in precompiled chunk", S->name, "bad constant");
          luaD_throw(L: S->L, errcode: 3);
      }
      v14 += 16;
    }
  }
  if ( luaZ_read(z: S->Z, b: (unsigned __int8 *)&j, n: 4u) != 0 )
  {
    luaO_pushfstring(L: (lua_TValue *)S->L, fmt: "%s: %s in precompiled chunk", S->name, "unexpected end");
    luaD_throw(L: S->L, errcode: 3);
  }
  v9 = j;
  if ( j < 0 )
  {
    luaO_pushfstring(L: (lua_TValue *)S->L, fmt: "%s: %s in precompiled chunk", S->name, "bad integer");
    luaD_throw(L: S->L, errcode: 3);
  }
  if ( (unsigned int)(j + 1) > 0x3FFFFFFF )
    luaM_toobig(L: S->L);
  f->p = (Proto **)luaM_realloc_(L: S->L, block: nullptr, osize: 0, nsize: 4 * j);
  v10 = 0;
  for ( f->sizep = v9; v10 < v9; ++v10 )
    f->p[v10] = nullptr;
  for ( k = 0; k < v9; ++k )
    f->p[k] = LoadFunction(S, p: f->source);
}

//------------------------------------------------------------------------------
// Address: 0x00489660
// Name: LoadDebug
// Source: json
//------------------------------------------------------------------------------
void __usercall LoadDebug(LoadState *S@<eax>, Proto *f@<edi>, int a3@<ecx>)
{
  int Int; // ebx
  int *v5; // eax
  unsigned int v6; // eax
  int v7; // ecx
  int v8; // ebx
  int v9; // eax
  unsigned int j; // ecx
  int v11; // ebx
  bool v12; // zf
  int v13; // ebx
  TString **v14; // eax
  TString **upvalues; // ecx
  int v16; // eax
  GCObject *String; // eax
  int v18; // ecx
  int i; // [esp+8h] [ebp-10h] BYREF
  int v20; // [esp+Ch] [ebp-Ch]
  int v21; // [esp+10h] [ebp-8h] BYREF
  int b; // [esp+14h] [ebp-4h] BYREF

  Int = LoadInt(S, a2: a3);
  if ( (unsigned int)(Int + 1) > 0x3FFFFFFF )
    luaM_toobig(L: S->L);
  v5 = (int *)luaM_realloc_(L: S->L, block: nullptr, osize: 0, nsize: 4 * Int);
  f->lineinfo = v5;
  f->sizelineinfo = Int;
  v6 = luaZ_read(z: S->Z, b: (unsigned __int8 *)v5, n: 4 * Int);
  if ( v6 != 0 )
  {
    luaO_pushfstring(L: (lua_TValue *)S->L, fmt: "%s: %s in precompiled chunk", S->name, "unexpected end");
    luaD_throw(L: S->L, errcode: 3);
  }
  v8 = LoadInt(S, a2: v7);
  if ( (unsigned int)(v8 + 1) > 0x15555555 )
    luaM_toobig(L: S->L);
  f->locvars = (LocVar *)luaM_realloc_(L: S->L, block: nullptr, osize: 0, nsize: 12 * v8);
  f->sizelocvars = v8;
  if ( v8 > 0 )
  {
    v9 = 0;
    for ( j = v8; j != 0; --j )
      f->locvars[v9++].varname = nullptr;
    v20 = 0;
    i = v8;
    do
    {
      v11 = v20;
      *(TString **)((char *)&f->locvars->varname + v20) = (TString *)LoadString(S, a2: j);
      if ( luaZ_read(z: S->Z, (unsigned __int8 *)&b, n: 4u) != 0 )
      {
        luaO_pushfstring(L: (lua_TValue *)S->L, fmt: "%s: %s in precompiled chunk", S->name, "unexpected end");
        luaD_throw(L: S->L, errcode: 3);
      }
      if ( b < 0 )
      {
        luaO_pushfstring(L: (lua_TValue *)S->L, fmt: "%s: %s in precompiled chunk", S->name, "bad integer");
        luaD_throw(L: S->L, errcode: 3);
      }
      *(int *)((char *)&f->locvars->startpc + v11) = b;
      if ( luaZ_read(z: S->Z, b: (unsigned __int8 *)&v21, n: 4u) != 0 )
      {
        luaO_pushfstring(L: (lua_TValue *)S->L, fmt: "%s: %s in precompiled chunk", S->name, "unexpected end");
        luaD_throw(L: S->L, errcode: 3);
      }
      if ( v21 < 0 )
      {
        luaO_pushfstring(L: (lua_TValue *)S->L, fmt: "%s: %s in precompiled chunk", S->name, "bad integer");
        luaD_throw(L: S->L, errcode: 3);
      }
      *(int *)((char *)&f->locvars->endpc + v11) = v21;
      v12 = i-- == 1;
      v20 = v11 + 12;
    }
    while ( !v12 );
  }
  if ( luaZ_read(z: S->Z, b: (unsigned __int8 *)&i, n: 4u) != 0 )
  {
    luaO_pushfstring(L: (lua_TValue *)S->L, fmt: "%s: %s in precompiled chunk", S->name, "unexpected end");
    luaD_throw(L: S->L, errcode: 3);
  }
  v13 = i;
  if ( i < 0 )
  {
    luaO_pushfstring(L: (lua_TValue *)S->L, fmt: "%s: %s in precompiled chunk", S->name, "bad integer");
    luaD_throw(L: S->L, errcode: 3);
  }
  if ( (unsigned int)(i + 1) > 0x3FFFFFFF )
    luaM_toobig(L: S->L);
  v14 = (TString **)luaM_realloc_(L: S->L, block: nullptr, osize: 0, nsize: 4 * i);
  f->upvalues = v14;
  v16 = 0;
  for ( f->sizeupvalues = v13; v16 < v13; ++v16 )
  {
    upvalues = f->upvalues;
    upvalues[v16] = nullptr;
  }
  i = 0;
  if ( v13 > 0 )
  {
    do
    {
      String = LoadString(S, a2: (unsigned int)upvalues);
      v18 = i;
      f->upvalues[i] = (TString *)String;
      upvalues = (TString **)(v18 + 1);
      i = (int)upvalues;
    }
    while ( (int)upvalues < v13 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00489920
// Name: LoadFunction
// Source: json
//------------------------------------------------------------------------------
Proto *__cdecl LoadFunction(LoadState *S, TString *p)
{
  LoadState *v2; // esi
  GCObject *v3; // eax
  unsigned int L; // ecx
  Proto *v5; // edi
  _DWORD *p_b; // eax
  GCObject *String; // eax
  int v8; // ecx
  int v9; // ecx
  int v10; // ecx
  int v11; // ecx
  int v12; // ecx

  v2 = S;
  v3 = luaF_newproto(L: S->L);
  L = (unsigned int)v2->L;
  v5 = (Proto *)v3;
  p_b = &v2->L->top->value.b;
  *p_b = v5;
  p_b[2] = 9;
  if ( (char *)v2->L->stack_last - (char *)v2->L->top <= 16 )
    luaD_growstack(L: v2->L, n: 1);
  ++v2->L->top;
  String = LoadString(S: v2, a2: L);
  v5->source = (TString *)String;
  if ( String == nullptr )
    v5->source = p;
  v5->linedefined = LoadInt(S: v2, a2: v8);
  v5->lastlinedefined = LoadInt(S: v2, a2: v9);
  if ( luaZ_read(z: v2->Z, b: (unsigned __int8 *)&S + 3, n: 1u) != 0 )
  {
    luaO_pushfstring(L: (lua_TValue *)v2->L, fmt: "%s: %s in precompiled chunk", v2->name, "unexpected end");
    luaD_throw(L: v2->L, errcode: 3);
  }
  v5->nups = HIBYTE(S);
  if ( luaZ_read(z: v2->Z, b: (unsigned __int8 *)&S + 3, n: 1u) != 0 )
  {
    luaO_pushfstring(L: (lua_TValue *)v2->L, fmt: "%s: %s in precompiled chunk", v2->name, "unexpected end");
    luaD_throw(L: v2->L, errcode: 3);
  }
  v5->numparams = HIBYTE(S);
  if ( luaZ_read(z: v2->Z, b: (unsigned __int8 *)&S + 3, n: 1u) != 0 )
  {
    luaO_pushfstring(L: (lua_TValue *)v2->L, fmt: "%s: %s in precompiled chunk", v2->name, "unexpected end");
    luaD_throw(L: v2->L, errcode: 3);
  }
  v5->is_vararg = HIBYTE(S);
  if ( luaZ_read(z: v2->Z, b: (unsigned __int8 *)&S + 3, n: 1u) != 0 )
  {
    luaO_pushfstring(L: (lua_TValue *)v2->L, fmt: "%s: %s in precompiled chunk", v2->name, "unexpected end");
    luaD_throw(L: v2->L, errcode: 3);
  }
  v5->maxstacksize = HIBYTE(S);
  LoadCode(S: v2, a2: v10, f: v5);
  LoadConstants(S: v2, a2: v11, f: v5);
  LoadDebug(S: v2, f: v5, a3: v12);
  if ( !luaG_checkcode(pt: v5) )
  {
    luaO_pushfstring(L: (lua_TValue *)v2->L, fmt: "%s: %s in precompiled chunk", v2->name, "bad code");
    luaD_throw(L: v2->L, errcode: 3);
  }
  --v2->L->top;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00489AE0
// Name: void luaU_header(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaU_header(char *h)
{
  strcpy(h, "\x1BLuaQ");
  *((_WORD *)h + 3) = 1025;
  *((_WORD *)h + 4) = 1028;
  *((_WORD *)h + 5) = 8;
}

//------------------------------------------------------------------------------
// Address: 0x00489B10
// Name: LoadHeader
// Source: json
//------------------------------------------------------------------------------
void __usercall LoadHeader(LoadState *S@<esi>)
{
  unsigned int v1; // eax
  int v2; // ecx
  Zio *Z; // [esp-Ch] [ebp-24h]
  unsigned __int8 b[12]; // [esp+0h] [ebp-18h] BYREF
  char h[12]; // [esp+Ch] [ebp-Ch]

  Z = S->Z;
  *(_DWORD *)h = 1635077147;
  *(_DWORD *)&h[4] = 67174481;
  *(_DWORD *)&h[8] = 525316;
  if ( luaZ_read(z: Z, b, n: 0xCu) != 0 )
  {
    luaO_pushfstring(L: (lua_TValue *)S->L, fmt: "%s: %s in precompiled chunk", S->name, "unexpected end");
    luaD_throw(L: S->L, errcode: 3);
  }
  v1 = 12;
  v2 = 0;
  do
  {
    if ( *(_DWORD *)&h[v2] != *(_DWORD *)&b[v2] )
    {
      luaO_pushfstring(L: (lua_TValue *)S->L, fmt: "%s: %s in precompiled chunk", S->name, "bad header");
      luaD_throw(L: S->L, errcode: 3);
    }
    v1 -= 4;
    v2 += 4;
  }
  while ( v1 >= 4 );
}

//------------------------------------------------------------------------------
// Address: 0x00489BB0
// Name: struct Proto __near * luaU_undump(struct lua_State __near *,struct Zio __near *,struct Mbuffer __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
Proto *__cdecl luaU_undump(lua_State *L, Zio *Z, Mbuffer *buff, const char *name)
{
  const char *v4; // ecx
  char v5; // al
  GCObject *v6; // eax
  LoadState S; // [esp+0h] [ebp-10h] BYREF

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
