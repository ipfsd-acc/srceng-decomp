// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vscript/languages/lua/vlua/vec3.cpp
// Functions: 17
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10022AA0
// Name: class Vector __near * lua_getvec3(struct lua_State __near *,int)
// Source: json
//------------------------------------------------------------------------------
Vector *__usercall lua_getvec3@<eax>(lua_State *pState@<eax>, int i)
{
  lua_TValue *v3; // eax
  int tt; // eax
  const char *v5; // eax
  const char *v6; // eax
  lua_TValue *v7; // eax

  if ( luaL_checkudata(L: pState, ud: i, tname: "Vec3") == nullptr )
  {
    v3 = index2adr(L: pState, idx: i);
    if ( v3 == &luaO_nilobject_ || (tt = v3->tt) == -1 )
      v5 = "no value";
    else
      v5 = luaT_typenames[tt];
    v6 = lua_pushfstring(L: pState, fmt: "%s expected, got %s", "Vec3", v5);
    luaL_argerror(L: pState, extramsg: v6, narg: i);
  }
  v7 = index2adr(L: pState, idx: i);
  if ( v7->tt == 2 )
    return (Vector *)v7->value.b;
  if ( v7->tt == 7 )
    return (Vector *)(v7->value.b + 24);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10022B30
// Name: class Vector lua_getvec3ByValue(struct lua_State __near *,int)
// Source: json
//------------------------------------------------------------------------------
Vector *__cdecl lua_getvec3ByValue(Vector *result, lua_State *pState, int i)
{
  int v3; // esi
  lua_TValue *v4; // eax
  int tt; // ecx
  lua_TValue *v6; // eax
  int v7; // ecx
  double n; // xmm0_8
  float v10; // xmm0_4
  lua_TValue *v11; // eax
  int v12; // eax
  const char *v13; // eax
  const char *v14; // eax
  lua_TValue *v15; // eax
  int b; // ecx
  __int64 v17; // xmm0_8
  float v18; // ecx
  long double v19; // [esp+10h] [ebp-10h] BYREF
  int v20; // [esp+18h] [ebp-8h]

  v3 = i;
  v4 = index2adr(L: pState, idx: i);
  tt = v4->tt;
  if ( tt == 3 || tt == 4 && (v3 = i, luaO_str2d(s: (char *)(v4->value.b + 24), result: &v19)) )
  {
    v6 = index2adr(L: pState, idx: v3);
    v7 = v6->tt;
    if ( v7 != 3 )
    {
      if ( v7 != 4 || !luaO_str2d(s: (char *)(v6->value.b + 24), result: &v19) )
      {
        n = 0.0;
        goto LABEL_9;
      }
      v20 = 3;
      v6 = (lua_TValue *)&v19;
    }
    n = v6->value.n;
LABEL_9:
    v10 = n;
    result->x = v10;
    result->y = v10;
    result->z = v10;
    return result;
  }
  if ( luaL_checkudata(L: pState, ud: v3, tname: "Vec3") == nullptr )
  {
    v11 = index2adr(L: pState, idx: v3);
    if ( v11 == &luaO_nilobject_ || (v12 = v11->tt) == -1 )
      v13 = "no value";
    else
      v13 = luaT_typenames[v12];
    v14 = lua_pushfstring(L: pState, fmt: "%s expected, got %s", "Vec3", v13);
    luaL_argerror(L: pState, extramsg: v14, narg: v3);
  }
  v15 = index2adr(L: pState, idx: v3);
  if ( v15->tt == 2 )
  {
    b = v15->value.b;
  }
  else if ( v15->tt == 7 )
  {
    b = v15->value.b + 24;
  }
  else
  {
    b = 0;
  }
  v17 = *(_QWORD *)b;
  v18 = *(float *)(b + 8);
  *(_QWORD *)&result->x = v17;
  result->z = v18;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10022C70
// Name: lua_allocvec3
// Source: json
//------------------------------------------------------------------------------
lua_TValue *__usercall lua_allocvec3@<eax>(GCObject *pState@<eax>)
{
  CallInfo *ci; // eax
  GCObject *gc; // ebx
  global_State *l_G; // edi
  GCObject *v5; // eax
  unsigned __int8 v6; // dl
  lua_TValue *k; // ecx
  global_State *v8; // edi
  lua_TValue *upvalue; // ebx
  GCObject *v10; // eax
  lua_TValue *v12; // [esp-4h] [ebp-24h]
  lua_TValue key; // [esp+10h] [ebp-10h] BYREF

  if ( *(_DWORD *)(pState->ts.tsv.len + 68) >= *(_DWORD *)(pState->ts.tsv.len + 64) )
    luaC_step(L: pState);
  ci = pState->th.ci;
  if ( ci == pState->th.base_ci )
    gc = pState->th.l_gt.value.gc;
  else
    gc = (GCObject *)ci->func->value.gc->ts.tsv.keyhash;
  l_G = pState->th.l_G;
  v5 = (GCObject *)l_G->frealloc(a1: l_G->ud, a2: nullptr, a3: 0, a4: 36u);
  if ( v5 == nullptr )
    luaD_throw(L: (lua_State *)pState, errcode: 4);
  l_G->totalbytes += 36;
  v6 = *(_BYTE *)(pState->ts.tsv.len + 20);
  v5->ts.tsv.keyhash = (unsigned int)gc;
  v5->ts.tsv.len = 12;
  v5->ts.tsv.hash = 0;
  v5->gch.marked = v6 & 3;
  v5->gch.tt = 7;
  v5->ts.dummy.l = **(_DWORD **)(pState->ts.tsv.len + 112);
  **(_DWORD **)(pState->ts.tsv.len + 112) = v5;
  k = pState->p.k;
  k->value.b = (int)v5;
  k->tt = 7;
  v8 = pState->th.l_G;
  pState->ts.tsv.hash += 16;
  upvalue = v5->cl.c.upvalue;
  v10 = luaS_newlstr(L: (lua_State *)pState, str: "Vec3", l: 4u);
  v12 = pState->p.k;
  key.value.b = (int)v10;
  key.tt = 4;
  luaV_gettable(L: (lua_State *)pState, t: (Node *)&v8->l_registry, &key, val: v12);
  pState->ts.tsv.hash += 16;
  lua_setmetatable(L: (lua_State *)pState, objindex: -2);
  return upvalue;
}

//------------------------------------------------------------------------------
// Address: 0x10022D60
// Name: vec3_new
// Source: json
//------------------------------------------------------------------------------
int __usercall vec3_new@<eax>(double a1@<xmm0>, GCObject *pState)
{
  lua_TValue *v2; // edi
  lua_TValue *array; // eax
  lua_TValue *v4; // eax
  lua_TValue *v5; // eax
  int v7; // xmm0_4

  for ( ; pState->ts.tsv.hash < pState->ts.tsv.keyhash + 48; pState->ts.tsv.hash += 16 )
    *(_DWORD *)(pState->ts.tsv.hash + 8) = 0;
  pState->ts.tsv.hash = pState->ts.tsv.keyhash + 48;
  v2 = lua_allocvec3(pState);
  array = pState->h.array;
  if ( (unsigned int)array >= pState->ts.tsv.hash || array == &luaO_nilobject_ || array->tt <= 0 )
    a1 = 0.0;
  else
    luaL_checknumber(L: (lua_State *)pState, narg: 1);
  *(float *)&a1 = a1;
  v2->value.b = LODWORD(a1);
  v4 = (lua_TValue *)(pState->ts.tsv.keyhash + 16);
  if ( (unsigned int)v4 >= pState->ts.tsv.hash || v4 == &luaO_nilobject_ || *(int *)(pState->ts.tsv.keyhash + 24) <= 0 )
    a1 = 0.0;
  else
    luaL_checknumber(L: (lua_State *)pState, narg: 2);
  *(float *)&a1 = a1;
  *(&v2->value.b + 1) = LODWORD(a1);
  v5 = (lua_TValue *)(pState->ts.tsv.keyhash + 32);
  if ( (unsigned int)v5 >= pState->ts.tsv.hash || v5 == &luaO_nilobject_ || *(int *)(pState->ts.tsv.keyhash + 40) <= 0 )
  {
    *(float *)&v2->tt = 0.0;
    return 1;
  }
  else
  {
    luaL_checknumber(L: (lua_State *)pState, narg: 3);
    *(float *)&v7 = a1;
    v2->tt = v7;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022E60
// Name: vec3_index
// Source: json
//------------------------------------------------------------------------------
int __cdecl vec3_index(GCObject *pState)
{
  lua_TValue *v1; // eax
  int b; // eax
  lua_TValue *v3; // eax
  int v4; // eax
  const char *v5; // eax
  const char *v6; // eax
  Vector *v7; // eax
  float x; // xmm0_4
  lua_TValue *v9; // ecx
  Node *v11; // esi
  GCObject *v12; // eax
  lua_TValue *k; // [esp-4h] [ebp-24h]
  char *s; // [esp+Ch] [ebp-14h]
  lua_TValue key; // [esp+10h] [ebp-10h] BYREF

  v1 = (lua_TValue *)(pState->ts.tsv.keyhash + 16);
  if ( (unsigned int)v1 >= pState->ts.tsv.hash )
    v1 = &luaO_nilobject_;
  if ( v1->tt != 4 )
  {
    if ( luaV_tostring(obj: v1, L: (lua_State *)pState) == 0 )
    {
LABEL_10:
      v3 = (lua_TValue *)(pState->ts.tsv.keyhash + 16);
      if ( (unsigned int)v3 >= pState->ts.tsv.hash
        || v3 == &luaO_nilobject_
        || (v4 = *(_DWORD *)(pState->ts.tsv.keyhash + 24)) == -1 )
      {
        v5 = "no value";
      }
      else
      {
        v5 = luaT_typenames[v4];
      }
      v6 = lua_pushfstring(L: (lua_State *)pState, fmt: "%s expected, got %s", "string", v5);
      luaL_argerror(L: (lua_State *)pState, extramsg: v6, narg: 2);
    }
    if ( *(_DWORD *)(pState->ts.tsv.len + 68) >= *(_DWORD *)(pState->ts.tsv.len + 64) )
      luaC_step(L: pState);
    v1 = (lua_TValue *)(pState->ts.tsv.keyhash + 16);
    if ( (unsigned int)v1 >= pState->ts.tsv.hash )
      v1 = &luaO_nilobject_;
  }
  b = v1->value.b;
  if ( b == -24 )
    goto LABEL_10;
  s = (char *)(b + 24);
  if ( *(_BYTE *)(b + 25) != 0 )
  {
LABEL_22:
    v11 = (Node *)(pState->ts.tsv.len + 96);
    v12 = luaS_newlstr(L: (lua_State *)pState, str: "Vec3", l: 4u);
    k = pState->p.k;
    key.value.b = (int)v12;
    key.tt = 4;
    luaV_gettable(L: (lua_State *)pState, t: v11, &key, val: k);
    pState->ts.tsv.hash += 16;
    lua_pushstring(L: (lua_State *)pState, s);
    *(lua_TValue *)(pState->ts.tsv.hash - 16) = luaH_get(
                                                  t: *(Table **)(pState->ts.tsv.hash - 32),
                                                  key: (const lua_TValue *)(pState->ts.tsv.hash - 16))->i_val;
    return 1;
  }
  else
  {
    v7 = lua_getvec3((lua_State *)pState, i: 1);
    switch ( *s )
    {
      case '1':
      case 'r':
      case 'x':
        x = v7->x;
        break;
      case '2':
      case 'g':
      case 'y':
        x = v7->y;
        break;
      case '3':
      case 'b':
      case 'z':
        x = v7->z;
        break;
      default:
        goto LABEL_22;
    }
    v9 = pState->p.k;
    v9->value.n = x;
    v9->tt = 3;
    pState->ts.tsv.hash += 16;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023040
// Name: vec3_newindex
// Source: json
//------------------------------------------------------------------------------
int __usercall vec3_newindex@<eax>(double a1@<xmm0>, GCObject *pState)
{
  lua_TValue *v2; // eax
  int b; // eax
  lua_TValue *v4; // eax
  int v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  Vector *v8; // esi
  float v9; // xmm0_4
  int result; // eax
  _BYTE *v11; // [esp+Ch] [ebp-4h]

  v2 = (lua_TValue *)(pState->ts.tsv.keyhash + 16);
  if ( (unsigned int)v2 >= pState->ts.tsv.hash )
    v2 = &luaO_nilobject_;
  if ( v2->tt != 4 )
  {
    if ( luaV_tostring(obj: v2, L: (lua_State *)pState) == 0 )
    {
LABEL_10:
      v4 = (lua_TValue *)(pState->ts.tsv.keyhash + 16);
      if ( (unsigned int)v4 >= pState->ts.tsv.hash
        || v4 == &luaO_nilobject_
        || (v5 = *(_DWORD *)(pState->ts.tsv.keyhash + 24)) == -1 )
      {
        v6 = "no value";
      }
      else
      {
        v6 = luaT_typenames[v5];
      }
      v7 = lua_pushfstring(L: (lua_State *)pState, fmt: "%s expected, got %s", "string", v6);
      luaL_argerror(L: (lua_State *)pState, extramsg: v7, narg: 2);
    }
    if ( *(_DWORD *)(pState->ts.tsv.len + 68) >= *(_DWORD *)(pState->ts.tsv.len + 64) )
      luaC_step(L: pState);
    v2 = (lua_TValue *)(pState->ts.tsv.keyhash + 16);
    if ( (unsigned int)v2 >= pState->ts.tsv.hash )
      v2 = &luaO_nilobject_;
  }
  b = v2->value.b;
  if ( b == -24 )
    goto LABEL_10;
  v11 = (_BYTE *)(b + 24);
  if ( *(_BYTE *)(b + 25) != 0 )
    return 1;
  v8 = lua_getvec3((lua_State *)pState, i: 1);
  luaL_checknumber(L: (lua_State *)pState, narg: 3);
  v9 = a1;
  switch ( *v11 )
  {
    case '1':
    case 'r':
    case 'x':
      v8->x = v9;
      result = 1;
      break;
    case '2':
    case 'g':
    case 'y':
      v8->y = v9;
      result = 1;
      break;
    case '3':
    case 'b':
    case 'z':
      v8->z = v9;
      return 1;
    default:
      return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100231C0
// Name: vec3_tostring
// Source: json
//------------------------------------------------------------------------------
int __cdecl vec3_tostring(GCObject *pState)
{
  Vector *v1; // eax
  unsigned int v2; // kr00_4
  lua_TValue *k; // edi
  char s[64]; // [esp+Ch] [ebp-40h] BYREF

  v1 = lua_getvec3((lua_State *)pState, i: 1);
  sprintf(string: s, format: "%s %p", "Vec3", v1);
  v2 = strlen(s);
  if ( *(_DWORD *)(pState->ts.tsv.len + 68) >= *(_DWORD *)(pState->ts.tsv.len + 64) )
    luaC_step(L: pState);
  k = pState->p.k;
  k->value.b = (int)luaS_newlstr(L: (lua_State *)pState, str: s, l: v2);
  k->tt = 4;
  pState->ts.tsv.hash += 16;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10023240
// Name: vec3_add
// Source: json
//------------------------------------------------------------------------------
int __cdecl vec3_add(GCObject *pState)
{
  float *eax1; // eax
  Vector v1; // [esp+4h] [ebp-24h] BYREF
  Vector v2; // [esp+10h] [ebp-18h] BYREF
  Vector vResult; // [esp+1Ch] [ebp-Ch]

  lua_getvec3ByValue(result: &v1, (lua_State *)pState, i: 1);
  lua_getvec3ByValue(result: &v2, (lua_State *)pState, i: 2);
  vResult.x = v2.x + v1.x;
  vResult.y = v2.y + v1.y;
  vResult.z = v2.z + v1.z;
  eax1 = (float *)lua_allocvec3(pState);
  *eax1 = vResult.x;
  eax1[1] = vResult.y;
  eax1[2] = vResult.z;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100232C0
// Name: vec3_subtract
// Source: json
//------------------------------------------------------------------------------
int __cdecl vec3_subtract(GCObject *pState)
{
  float *eax1; // eax
  Vector v2; // [esp+4h] [ebp-24h] BYREF
  Vector v1; // [esp+10h] [ebp-18h] BYREF
  Vector vResult; // [esp+1Ch] [ebp-Ch]

  lua_getvec3ByValue(result: &v1, (lua_State *)pState, i: 1);
  lua_getvec3ByValue(result: &v2, (lua_State *)pState, i: 2);
  vResult.x = v1.x - v2.x;
  vResult.y = v1.y - v2.y;
  vResult.z = v1.z - v2.z;
  eax1 = (float *)lua_allocvec3(pState);
  *eax1 = vResult.x;
  eax1[1] = vResult.y;
  eax1[2] = vResult.z;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10023340
// Name: vec3_multiply
// Source: json
//------------------------------------------------------------------------------
int __cdecl vec3_multiply(GCObject *pState)
{
  float *eax1; // eax
  Vector v1; // [esp+4h] [ebp-24h] BYREF
  Vector v2; // [esp+10h] [ebp-18h] BYREF
  Vector vResult; // [esp+1Ch] [ebp-Ch]

  lua_getvec3ByValue(result: &v1, (lua_State *)pState, i: 1);
  lua_getvec3ByValue(result: &v2, (lua_State *)pState, i: 2);
  vResult.x = v2.x * v1.x;
  vResult.y = v2.y * v1.y;
  vResult.z = v2.z * v1.z;
  eax1 = (float *)lua_allocvec3(pState);
  *eax1 = vResult.x;
  eax1[1] = vResult.y;
  eax1[2] = vResult.z;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100233C0
// Name: vec3_divide
// Source: json
//------------------------------------------------------------------------------
int __cdecl vec3_divide(GCObject *pState)
{
  float *eax1; // eax
  Vector v2; // [esp+4h] [ebp-24h] BYREF
  Vector v1; // [esp+10h] [ebp-18h] BYREF
  Vector vResult; // [esp+1Ch] [ebp-Ch]

  lua_getvec3ByValue(result: &v1, (lua_State *)pState, i: 1);
  lua_getvec3ByValue(result: &v2, (lua_State *)pState, i: 2);
  vResult.x = v1.x / v2.x;
  vResult.y = v1.y / v2.y;
  vResult.z = v1.z / v2.z;
  eax1 = (float *)lua_allocvec3(pState);
  *eax1 = vResult.x;
  eax1[1] = vResult.y;
  eax1[2] = vResult.z;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10023440
// Name: vec3_length
// Source: json
//------------------------------------------------------------------------------
int __cdecl vec3_length(lua_State *pState)
{
  lua_TValue *top; // eax
  __int128 v2; // xmm0
  __int128 v4; // [esp+20h] [ebp-10h] BYREF

  lua_getvec3ByValue(result: (Vector *)&v4, pState, i: 1);
  top = pState->top;
  v2 = 0;
  *(float *)&v2 = fsqrt(
                    (float)((float)(*(float *)&v4 * *(float *)&v4) + (float)(*((float *)&v4 + 1) * *((float *)&v4 + 1)))
                  + (float)(*((float *)&v4 + 2) * *((float *)&v4 + 2)));
  v4 = v2;
  top->value.n = *(float *)&v2;
  top->tt = 3;
  ++pState->top;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100234D0
// Name: vec3_equal
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl vec3_equal(lua_State *pState)
{
  Vector v1; // [esp+4h] [ebp-18h] BYREF
  Vector v2; // [esp+10h] [ebp-Ch] BYREF

  lua_getvec3ByValue(result: &v1, pState, i: 1);
  lua_getvec3ByValue(result: &v2, pState, i: 2);
  return v2.x == v1.x && v2.y == v1.y && v2.z == v1.z;
}

//------------------------------------------------------------------------------
// Address: 0x10023550
// Name: vec3_dot
// Source: json
//------------------------------------------------------------------------------
int __cdecl vec3_dot(lua_State *pState)
{
  lua_TValue *top; // eax
  Vector v2; // [esp+8h] [ebp-18h] BYREF
  Vector v1; // [esp+14h] [ebp-Ch] BYREF

  lua_getvec3ByValue(result: &v1, pState, i: 1);
  lua_getvec3ByValue(result: &v2, pState, i: 2);
  top = pState->top;
  top->value.n = (float)((float)((float)(v2.x * v1.x) + (float)(v1.y * v2.y)) + (float)(v2.z * v1.z));
  top->tt = 3;
  ++pState->top;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100235D0
// Name: vec3_cross
// Source: json
//------------------------------------------------------------------------------
int __cdecl vec3_cross(GCObject *pState)
{
  float *eax1; // eax
  Vector v2; // [esp+4h] [ebp-18h] BYREF
  Vector v1; // [esp+10h] [ebp-Ch] BYREF

  lua_getvec3ByValue(result: &v1, (lua_State *)pState, i: 1);
  lua_getvec3ByValue(result: &v2, (lua_State *)pState, i: 2);
  eax1 = (float *)lua_allocvec3(pState);
  *eax1 = v1.x;
  eax1[1] = v1.y;
  eax1[2] = v1.z;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10023630
// Name: int luaopen_vec3(struct lua_State __near *)
// Source: json
//------------------------------------------------------------------------------
int __usercall luaopen_vec3@<eax>(lua_State *pState@<eax>)
{
  lua_TValue *v3; // [esp-24h] [ebp-3Ch]
  lua_TValue key; // [esp+8h] [ebp-10h] BYREF

  luaL_newmetatable(L: pState, tname: "Vec3");
  luaL_openlib(L: pState, libname: nullptr, l: Registrations);
  lua_pushcclosure(L: pState, fn: (int (__cdecl *)(lua_State *))vec3_new, n: 0);
  key.value.b = (int)luaS_newlstr(L: pState, str: "Vec3", l: 4u);
  v3 = pState->top - 1;
  key.tt = 4;
  luaV_settable(L: pState, t: (Node *)&pState->l_gt, &key, val: v3);
  --pState->top;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100236B0
// Name: void __near * operator new(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl operator new(unsigned int nSize)
{
  return _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: nSize);
}
