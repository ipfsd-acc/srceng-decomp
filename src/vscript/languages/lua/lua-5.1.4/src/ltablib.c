// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vscript/languages/lua/lua-5.1.4/src/ltablib.c
// Functions: 15
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1001E030
// Name: foreachi
// Source: json
//------------------------------------------------------------------------------
int __cdecl foreachi(lua_State *L)
{
  lua_TValue *base; // eax
  lua_TValue *top; // ecx
  int tt; // eax
  const char *v4; // eax
  const char *v5; // eax
  lua_TValue *v6; // esi
  lua_TValue *v7; // ecx
  lua_TValue *v8; // eax
  int v9; // eax
  const char *v10; // eax
  const char *v11; // eax
  int v12; // eax
  lua_TValue *v13; // ecx
  lua_TValue *v14; // edx
  lua_TValue *v15; // ecx
  lua_TValue *v16; // edi
  lua_TValue *v17; // ecx
  Node *v18; // eax
  lua_TValue *v19; // eax
  int i; // [esp+Ch] [ebp-8h]
  int v22; // [esp+10h] [ebp-4h]

  base = L->base;
  top = L->top;
  if ( base >= top )
    goto LABEL_7;
  if ( base == &luaO_nilobject_ || base->tt != 5 )
  {
    if ( base < top && base != &luaO_nilobject_ )
    {
      tt = base->tt;
      if ( tt != -1 )
      {
        v4 = luaT_typenames[tt];
LABEL_9:
        v5 = lua_pushfstring(L, fmt: "%s expected, got %s", "table", v4);
        luaL_argerror(L, extramsg: v5, narg: 1);
      }
    }
LABEL_7:
    v4 = "no value";
    goto LABEL_9;
  }
  v6 = L->base;
  if ( v6 >= L->top )
    v6 = &luaO_nilobject_;
  switch ( v6->tt )
  {
    case 3:
      if ( luaV_tostring(L, obj: v6) != 0 )
        v22 = *(_DWORD *)(v6->value.b + 16);
      else
        v22 = 0;
      break;
    case 4:
      v22 = *(_DWORD *)(v6->value.b + 16);
      break;
    case 5:
      v22 = luaH_getn(t: (Table *)v6->value.gc);
      break;
    case 7:
      v22 = *(_DWORD *)(v6->value.b + 16);
      break;
    default:
      v22 = 0;
      break;
  }
  v7 = L->top;
  v8 = L->base + 1;
  if ( v8 >= v7 )
    goto LABEL_26;
  if ( v8 == &luaO_nilobject_ || L->base[1].tt != 6 )
  {
    if ( v8 < v7 && v8 != &luaO_nilobject_ )
    {
      v9 = L->base[1].tt;
      if ( v9 != -1 )
      {
        v10 = luaT_typenames[v9];
LABEL_28:
        v11 = lua_pushfstring(L, fmt: "%s expected, got %s", "function", v10);
        luaL_argerror(L, extramsg: v11, narg: 2);
      }
    }
LABEL_26:
    v10 = "no value";
    goto LABEL_28;
  }
  v12 = 1;
  i = 1;
  if ( v22 < 1 )
    return 0;
  while ( 1 )
  {
    v13 = L->top;
    v14 = L->base + 1;
    if ( v14 >= v13 )
      v14 = &luaO_nilobject_;
    v13->value.b = v14->value.b;
    *(&v13->value.b + 1) = *(&v14->value.b + 1);
    v13->tt = v14->tt;
    v15 = ++L->top;
    v15->tt = 3;
    v15->value.n = (double)v12;
    v16 = ++L->top;
    v17 = L->base;
    if ( v17 >= v16 )
      v17 = &luaO_nilobject_;
    v18 = luaH_getnum(t: (Table *)v17->value.gc, key: v12);
    v16->value = v18->i_val.value;
    v16->tt = v18->i_val.tt;
    luaD_call(L, func: ++L->top - 3, nResults: 1);
    v19 = L->top - 1;
    if ( v19 == &luaO_nilobject_ || v19->tt != 0 )
      break;
    L->top = v19;
    v12 = i + 1;
    i = v12;
    if ( v12 > v22 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1001E240
// Name: foreach
// Source: json
//------------------------------------------------------------------------------
int __cdecl foreach(lua_State *L)
{
  lua_TValue *base; // eax
  lua_TValue *top; // ecx
  int tt; // eax
  const char *v4; // eax
  const char *v5; // eax
  lua_TValue *v6; // ecx
  lua_TValue *v7; // eax
  int v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  lua_TValue *v11; // eax
  lua_TValue *v12; // ecx
  lua_TValue *v13; // ecx
  lua_TValue *v14; // eax
  lua_TValue *v15; // ecx
  lua_TValue *v16; // ecx

  base = L->base;
  top = L->top;
  if ( base >= top )
    goto LABEL_7;
  if ( base == &luaO_nilobject_ || base->tt != 5 )
  {
    if ( base < top && base != &luaO_nilobject_ )
    {
      tt = base->tt;
      if ( tt != -1 )
      {
        v4 = luaT_typenames[tt];
LABEL_9:
        v5 = lua_pushfstring(L, fmt: "%s expected, got %s", "table", v4);
        luaL_argerror(L, extramsg: v5, narg: 1);
      }
    }
LABEL_7:
    v4 = "no value";
    goto LABEL_9;
  }
  v6 = L->top;
  v7 = L->base + 1;
  if ( v7 >= v6 )
    goto LABEL_16;
  if ( v7 == &luaO_nilobject_ || L->base[1].tt != 6 )
  {
    if ( v7 < v6 && v7 != &luaO_nilobject_ )
    {
      v8 = L->base[1].tt;
      if ( v8 != -1 )
      {
        v9 = luaT_typenames[v8];
LABEL_18:
        v10 = lua_pushfstring(L, fmt: "%s expected, got %s", "function", v9);
        luaL_argerror(L, extramsg: v10, narg: 2);
      }
    }
LABEL_16:
    v9 = "no value";
    goto LABEL_18;
  }
  L->top->tt = 0;
  for ( ++L->top; ; L->top = v16 - 2 )
  {
    v11 = L->base;
    v12 = L->top;
    if ( v11 >= v12 )
      v11 = &luaO_nilobject_;
    if ( luaH_next(L, t: (Table *)v11->value.gc, key: (TKey *)&v12[-1]) == 0 )
    {
      --L->top;
      return 0;
    }
    v13 = L->base;
    v14 = ++L->top;
    v15 = v13 + 1;
    if ( v15 >= v14 )
      v15 = &luaO_nilobject_;
    v14->value.b = v15->value.b;
    *(&v14->value.b + 1) = *(&v15->value.b + 1);
    v14->tt = v15->tt;
    ++L->top;
    *L->top = L->top[-3];
    ++L->top;
    *L->top = L->top[-3];
    luaD_call(L, func: ++L->top - 3, nResults: 1);
    v16 = L->top;
    if ( &v16[-1] == &luaO_nilobject_ || v16[-1].tt != 0 )
      break;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1001E3E0
// Name: maxn
// Source: json
//------------------------------------------------------------------------------
int __cdecl maxn(lua_State *L)
{
  lua_TValue *base; // eax
  lua_TValue *top; // ecx
  int tt; // eax
  const char *v4; // eax
  const char *v5; // eax
  lua_TValue *v6; // eax
  lua_TValue *v7; // ecx
  lua_TValue *v8; // eax
  lua_TValue *v9; // eax
  int v10; // ecx
  double n; // xmm0_8
  lua_TValue *v12; // eax
  double max; // [esp+4h] [ebp-20h]
  long double v15; // [esp+Ch] [ebp-18h] BYREF
  long double v16; // [esp+14h] [ebp-10h] BYREF
  int v17; // [esp+1Ch] [ebp-8h]

  base = L->base;
  top = L->top;
  max = 0.0;
  if ( base >= top )
    goto LABEL_7;
  if ( base == &luaO_nilobject_ || base->tt != 5 )
  {
    if ( base < top && base != &luaO_nilobject_ )
    {
      tt = base->tt;
      if ( tt != -1 )
      {
        v4 = luaT_typenames[tt];
LABEL_9:
        v5 = lua_pushfstring(L, fmt: "%s expected, got %s", "table", v4);
        luaL_argerror(L, extramsg: v5, narg: 1);
      }
    }
LABEL_7:
    v4 = "no value";
    goto LABEL_9;
  }
  L->top->tt = 0;
  ++L->top;
  while ( 1 )
  {
    v6 = L->base;
    v7 = L->top;
    if ( v6 >= v7 )
      v6 = &luaO_nilobject_;
    if ( luaH_next(L, t: (Table *)v6->value.gc, key: (TKey *)&v7[-1]) == 0 )
      break;
    v8 = L->top;
    L->top = v8;
    v9 = v8 - 1;
    if ( v9 != &luaO_nilobject_ && v9->tt == 3 )
    {
      v10 = v9->tt;
      if ( v10 != 3 )
      {
        if ( v10 != 4 || !luaO_str2d(s: (char *)(v9->value.b + 24), result: &v15) )
        {
          n = 0.0;
          goto LABEL_21;
        }
        v16 = v15;
        v17 = 3;
        v9 = (lua_TValue *)&v16;
      }
      n = v9->value.n;
LABEL_21:
      if ( n > max )
        max = n;
    }
  }
  v12 = --L->top;
  v12->value.n = max;
  v12->tt = 3;
  ++L->top;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1001E510
// Name: getn
// Source: json
//------------------------------------------------------------------------------
int __cdecl getn(lua_State *L)
{
  lua_TValue *base; // eax
  lua_TValue *top; // ecx
  int tt; // eax
  const char *v4; // eax
  const char *v5; // eax
  lua_TValue *v6; // esi
  int v7; // eax
  lua_TValue *v8; // ecx

  base = L->base;
  top = L->top;
  if ( base >= top )
    goto LABEL_7;
  if ( base == &luaO_nilobject_ || base->tt != 5 )
  {
    if ( base < top && base != &luaO_nilobject_ )
    {
      tt = base->tt;
      if ( tt != -1 )
      {
        v4 = luaT_typenames[tt];
LABEL_9:
        v5 = lua_pushfstring(L, fmt: "%s expected, got %s", "table", v4);
        luaL_argerror(L, extramsg: v5, narg: 1);
      }
    }
LABEL_7:
    v4 = "no value";
    goto LABEL_9;
  }
  v6 = L->base;
  if ( v6 >= L->top )
    v6 = &luaO_nilobject_;
  switch ( v6->tt )
  {
    case 3:
      if ( luaV_tostring(L, obj: v6) == 0 )
        goto LABEL_18;
      v7 = *(_DWORD *)(v6->value.b + 16);
      break;
    case 4:
      v7 = *(_DWORD *)(v6->value.b + 16);
      break;
    case 5:
      v7 = luaH_getn(t: (Table *)v6->value.gc);
      break;
    case 7:
      v7 = *(_DWORD *)(v6->value.b + 16);
      break;
    default:
LABEL_18:
      v7 = 0;
      break;
  }
  v8 = L->top;
  v8->value.n = (double)v7;
  v8->tt = 3;
  ++L->top;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1001E600
// Name: setn
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn setn(lua_State *L)
{
  lua_TValue *base; // eax
  lua_TValue *top; // ecx
  int tt; // eax
  const char *v4; // eax
  const char *v5; // eax

  base = L->base;
  top = L->top;
  if ( base >= top )
    goto LABEL_7;
  if ( base != &luaO_nilobject_ && base->tt == 5 )
    luaL_error(L, fmt: "'setn' is obsolete");
  if ( base >= top || base == &luaO_nilobject_ || (tt = base->tt) == -1 )
LABEL_7:
    v4 = "no value";
  else
    v4 = luaT_typenames[tt];
  v5 = lua_pushfstring(L, fmt: "%s expected, got %s", "table", v4);
  luaL_argerror(L, extramsg: v5, narg: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1001E6A0
// Name: tinsert
// Source: json
//------------------------------------------------------------------------------
int __cdecl tinsert(lua_State *L)
{
  lua_TValue *base; // eax
  lua_TValue *top; // ecx
  int tt; // eax
  const char *v5; // eax
  const char *v6; // eax
  lua_TValue *v7; // esi
  int v8; // eax
  int v9; // esi
  int v10; // eax
  lua_TValue *v11; // ecx
  lua_TValue *v12; // edi
  Node *v13; // eax
  lua_TValue *v14; // esi
  Node *v15; // eax
  lua_TValue *v16; // eax
  GCObject *b; // eax
  global_State *l_G; // ecx
  lua_TValue *v19; // esi
  Node *v20; // eax
  lua_TValue *v21; // eax
  GCObject *v22; // eax
  global_State *v23; // ecx
  int v25; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]
  lua_TValue *v27; // [esp+14h] [ebp-4h]
  int pos; // [esp+20h] [ebp+8h]
  lua_TValue *posa; // [esp+20h] [ebp+8h]

  base = L->base;
  top = L->top;
  if ( base >= top )
    goto LABEL_7;
  if ( base == &luaO_nilobject_ || base->tt != 5 )
  {
    if ( base < top && base != &luaO_nilobject_ )
    {
      tt = base->tt;
      if ( tt != -1 )
      {
        v5 = luaT_typenames[tt];
LABEL_9:
        v6 = lua_pushfstring(L, fmt: "%s expected, got %s", "table", v5);
        luaL_argerror(L, extramsg: v6, narg: 1);
      }
    }
LABEL_7:
    v5 = "no value";
    goto LABEL_9;
  }
  v7 = L->base;
  if ( v7 >= L->top )
    v7 = &luaO_nilobject_;
  switch ( v7->tt )
  {
    case 3:
      if ( luaV_tostring(L, obj: v7) == 0 )
        goto LABEL_18;
      v8 = *(_DWORD *)(v7->value.b + 16);
      break;
    case 4:
      v8 = *(_DWORD *)(v7->value.b + 16);
      break;
    case 5:
      v8 = luaH_getn(t: (Table *)v7->value.gc);
      break;
    case 7:
      v8 = *(_DWORD *)(v7->value.b + 16);
      break;
    default:
LABEL_18:
      v8 = 0;
      break;
  }
  v9 = v8 + 1;
  if ( L->top - L->base == 2 )
  {
    pos = v8 + 1;
LABEL_36:
    v10 = pos;
    goto LABEL_37;
  }
  if ( L->top - L->base != 3 )
    luaL_error(L, fmt: "wrong number of arguments to 'insert'");
  v10 = luaL_checkinteger(L, narg: 2);
  if ( v10 > v9 )
    v9 = v10;
  pos = v10;
  i = v9;
  if ( v9 > v10 )
  {
    do
    {
      v11 = L->base;
      v12 = L->top;
      if ( v11 >= v12 )
        v11 = &luaO_nilobject_;
      v25 = i - 1;
      v13 = luaH_getnum(t: (Table *)v11->value.gc, key: i - 1);
      v12->value = v13->i_val.value;
      v12->tt = v13->i_val.tt;
      v14 = ++L->top;
      v27 = &luaO_nilobject_;
      if ( L->base < v14 )
        v27 = L->base;
      v15 = luaH_setnum(t: v27->value.gc, key: i, L);
      v15->i_val.value = v14[-1].value;
      v15->i_val.tt = v14[-1].tt;
      v16 = L->top;
      if ( v16[-1].tt >= 4 && (*(_BYTE *)(v16[-1].value.b + 5) & 3) != 0 )
      {
        b = (GCObject *)v27->value.b;
        if ( (*(_BYTE *)(v27->value.b + 5) & 4) != 0 )
        {
          l_G = L->l_G;
          b->gch.marked &= ~4u;
          b->cl.c.upvalue[0].value.b = (int)l_G->grayagain;
          l_G->grayagain = b;
        }
      }
      --L->top;
      --i;
    }
    while ( v25 > pos );
    goto LABEL_36;
  }
LABEL_37:
  v19 = L->top;
  posa = &luaO_nilobject_;
  if ( L->base < v19 )
    posa = L->base;
  v20 = luaH_setnum(t: posa->value.gc, key: v10, L);
  v20->i_val.value = v19[-1].value;
  v20->i_val.tt = v19[-1].tt;
  v21 = L->top;
  if ( v21[-1].tt >= 4 && (*(_BYTE *)(v21[-1].value.b + 5) & 3) != 0 )
  {
    v22 = (GCObject *)posa->value.b;
    if ( (*(_BYTE *)(posa->value.b + 5) & 4) != 0 )
    {
      v23 = L->l_G;
      v22->gch.marked &= ~4u;
      v22->cl.c.upvalue[0].value.b = (int)v23->grayagain;
      v23->grayagain = v22;
    }
  }
  --L->top;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001E8E0
// Name: tremove
// Source: json
//------------------------------------------------------------------------------
int __cdecl tremove(lua_State *L)
{
  lua_TValue *base; // eax
  lua_TValue *top; // ecx
  int tt; // eax
  const char *v4; // eax
  const char *v5; // eax
  lua_TValue *v6; // esi
  lua_TValue *v7; // eax
  int v8; // edi
  lua_TValue *v9; // ecx
  lua_TValue *v10; // ecx
  lua_TValue *v11; // esi
  Node *v12; // eax
  lua_TValue *v13; // eax
  GCObject *b; // eax
  global_State *l_G; // ecx
  lua_TValue *v16; // esi
  Node *v17; // eax
  lua_TValue *v18; // eax
  GCObject *v19; // eax
  global_State *v20; // ecx
  int v22; // [esp+Ch] [ebp-Ch]
  lua_TValue *v23; // [esp+10h] [ebp-8h]
  lua_TValue *v24; // [esp+10h] [ebp-8h]
  int key; // [esp+14h] [ebp-4h]

  base = L->base;
  top = L->top;
  if ( base >= top )
    goto LABEL_7;
  if ( base == &luaO_nilobject_ || base->tt != 5 )
  {
    if ( base < top && base != &luaO_nilobject_ )
    {
      tt = base->tt;
      if ( tt != -1 )
      {
        v4 = luaT_typenames[tt];
LABEL_9:
        v5 = lua_pushfstring(L, fmt: "%s expected, got %s", "table", v4);
        luaL_argerror(L, extramsg: v5, narg: 1);
      }
    }
LABEL_7:
    v4 = "no value";
    goto LABEL_9;
  }
  v6 = L->base;
  if ( v6 >= L->top )
    v6 = &luaO_nilobject_;
  switch ( v6->tt )
  {
    case 3:
      if ( luaV_tostring(L, obj: v6) != 0 )
        key = *(_DWORD *)(v6->value.b + 16);
      else
        key = 0;
      break;
    case 4:
      key = *(_DWORD *)(v6->value.b + 16);
      break;
    case 5:
      key = luaH_getn(t: (Table *)v6->value.gc);
      break;
    case 7:
      key = *(_DWORD *)(v6->value.b + 16);
      break;
    default:
      key = 0;
      break;
  }
  v7 = L->base + 1;
  if ( v7 >= L->top || v7 == &luaO_nilobject_ || L->base[1].tt <= 0 )
    v8 = key;
  else
    v8 = luaL_checkinteger(L, narg: 2);
  if ( v8 < 1 || v8 > key )
    return 0;
  v9 = L->base;
  if ( v9 >= L->top )
    v9 = &luaO_nilobject_;
  *L->top++ = luaH_getnum(t: (Table *)v9->value.gc, key: v8)->i_val;
  if ( v8 < key )
  {
    do
    {
      v10 = L->base;
      if ( v10 >= L->top )
        v10 = &luaO_nilobject_;
      v22 = v8 + 1;
      *L->top++ = luaH_getnum(t: (Table *)v10->value.gc, key: v8 + 1)->i_val;
      v11 = L->top;
      v23 = &luaO_nilobject_;
      if ( L->base < v11 )
        v23 = L->base;
      v12 = luaH_setnum(t: v23->value.gc, key: v8, L);
      v12->i_val.value = v11[-1].value;
      v12->i_val.tt = v11[-1].tt;
      v13 = L->top;
      if ( v13[-1].tt >= 4 && (*(_BYTE *)(v13[-1].value.b + 5) & 3) != 0 )
      {
        b = (GCObject *)v23->value.b;
        if ( (*(_BYTE *)(v23->value.b + 5) & 4) != 0 )
        {
          l_G = L->l_G;
          b->gch.marked &= ~4u;
          b->cl.c.upvalue[0].value.b = (int)l_G->grayagain;
          l_G->grayagain = b;
        }
      }
      ++v8;
      --L->top;
    }
    while ( v22 < key );
  }
  L->top->tt = 0;
  v16 = ++L->top;
  v24 = &luaO_nilobject_;
  if ( L->base < v16 )
    v24 = L->base;
  v17 = luaH_setnum(t: v24->value.gc, key, L);
  v17->i_val.value = v16[-1].value;
  v17->i_val.tt = v16[-1].tt;
  v18 = L->top;
  if ( v18[-1].tt >= 4 && (*(_BYTE *)(v18[-1].value.b + 5) & 3) != 0 )
  {
    v19 = (GCObject *)v24->value.b;
    if ( (*(_BYTE *)(v24->value.b + 5) & 4) != 0 )
    {
      v20 = L->l_G;
      v19->gch.marked &= ~4u;
      v19->cl.c.upvalue[0].value.b = (int)v20->grayagain;
      v20->grayagain = v19;
    }
  }
  --L->top;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1001EB60
// Name: addfield
// Source: json
//------------------------------------------------------------------------------
void __cdecl addfield(lua_State *L, luaL_Buffer *b, int i)
{
  lua_TValue *top; // edi
  lua_TValue *base; // ecx
  Node *v5; // eax
  lua_TValue *v6; // eax
  int tt; // ecx
  const char *v8; // eax

  top = L->top;
  base = &luaO_nilobject_;
  if ( L->base < top )
    base = L->base;
  v5 = luaH_getnum(t: (Table *)base->value.gc, key: i);
  top->value = v5->i_val.value;
  top->tt = v5->i_val.tt;
  v6 = L->top++;
  if ( v6 == &luaO_nilobject_ )
    goto LABEL_8;
  tt = v6->tt;
  if ( tt != 4 && tt != 3 )
  {
    if ( v6 != &luaO_nilobject_ && tt != -1 )
    {
      v8 = luaT_typenames[tt];
LABEL_10:
      luaL_error(L, fmt: "invalid value (%s) at index %d in table for 'concat'", v8, i);
    }
LABEL_8:
    v8 = "no value";
    goto LABEL_10;
  }
  luaL_addvalue(B: b);
}

//------------------------------------------------------------------------------
// Address: 0x1001EBF0
// Name: tconcat
// Source: json
//------------------------------------------------------------------------------
int __cdecl tconcat(GCObject *L)
{
  lua_TValue *v2; // eax
  lua_TValue *array; // eax
  lua_TValue *k; // ecx
  int tt; // eax
  const char *v6; // eax
  const char *v7; // eax
  lua_TValue *v8; // eax
  int v9; // edi
  lua_TValue *v10; // esi
  lua_TValue *v11; // ecx
  int v12; // eax
  GCObject *v13; // eax
  char *buffer; // ecx
  bool v15; // zf
  unsigned int v16; // ebx
  lua_State *v17; // esi
  _DWORD *p_b; // edi
  int lvl; // edi
  lua_State *v20; // esi
  _DWORD *hash; // edi
  unsigned int *p_hash; // esi
  luaL_Buffer b; // [esp+Ch] [ebp-214h] BYREF
  unsigned int lsep; // [esp+218h] [ebp-8h] BYREF
  const char *sep; // [esp+21Ch] [ebp-4h]
  int last; // [esp+228h] [ebp+8h]

  v2 = (lua_TValue *)(L->ts.tsv.keyhash + 16);
  if ( (unsigned int)v2 >= L->ts.tsv.hash || v2 == &luaO_nilobject_ || *(int *)(L->ts.tsv.keyhash + 24) <= 0 )
  {
    lsep = 0;
    sep = Ptr;
  }
  else
  {
    sep = luaL_checklstring((lua_State *)L, len: &lsep, narg: 2);
  }
  array = L->h.array;
  k = L->p.k;
  if ( array >= k )
    goto LABEL_12;
  if ( array == &luaO_nilobject_ || array->tt != 5 )
  {
    if ( array < k && array != &luaO_nilobject_ )
    {
      tt = array->tt;
      if ( tt != -1 )
      {
        v6 = luaT_typenames[tt];
LABEL_14:
        v7 = lua_pushfstring((lua_State *)L, fmt: "%s expected, got %s", "table", v6);
        luaL_argerror((lua_State *)L, extramsg: v7, narg: 1);
      }
    }
LABEL_12:
    v6 = "no value";
    goto LABEL_14;
  }
  v8 = (lua_TValue *)(L->ts.tsv.keyhash + 32);
  if ( (unsigned int)v8 >= L->ts.tsv.hash || v8 == &luaO_nilobject_ || *(int *)(L->ts.tsv.keyhash + 40) <= 0 )
    v9 = 1;
  else
    v9 = luaL_checkinteger((lua_State *)L, narg: 3);
  v10 = L->h.array;
  v11 = L->p.k;
  if ( &v10[3] >= v11 || &v10[3] == &luaO_nilobject_ || v10[3].tt <= 0 )
  {
    if ( v10 >= v11 )
      v10 = &luaO_nilobject_;
    switch ( v10->tt )
    {
      case 3:
        if ( luaV_tostring((lua_State *)L, obj: v10) == 0 )
          goto LABEL_31;
        v12 = *(_DWORD *)(v10->value.b + 16);
        break;
      case 4:
        v12 = *(_DWORD *)(v10->value.b + 16);
        break;
      case 5:
        v12 = luaH_getn(t: (Table *)v10->value.gc);
        break;
      case 7:
        v12 = *(_DWORD *)(v10->value.b + 16);
        break;
      default:
LABEL_31:
        v12 = 0;
        break;
    }
  }
  else
  {
    v12 = luaL_checkinteger((lua_State *)L, narg: 4);
  }
  last = v12;
  v13 = L;
  buffer = b.buffer;
  b.L = (lua_State *)L;
  b.p = b.buffer;
  b.lvl = 0;
  v15 = v9 == last;
  if ( v9 < last )
  {
    do
    {
      addfield((lua_State *)L, &b, i: v9);
      luaL_addlstring(B: &b, s: sep, l: lsep);
      v15 = ++v9 == last;
    }
    while ( v9 < last );
    v13 = (GCObject *)b.L;
    buffer = b.p;
  }
  if ( v15 )
  {
    addfield((lua_State *)L, &b, i: v9);
    v13 = (GCObject *)b.L;
    buffer = b.p;
  }
  v16 = buffer - b.buffer;
  if ( buffer == b.buffer )
  {
    lvl = b.lvl;
  }
  else
  {
    v17 = (lua_State *)v13;
    if ( *(_DWORD *)(v13->ts.tsv.len + 68) >= *(_DWORD *)(v13->ts.tsv.len + 64) )
      luaC_step(L: v13);
    p_b = &v17->top->value.b;
    *p_b = luaS_newlstr(L: v17, str: b.buffer, l: v16);
    p_b[2] = 4;
    ++v17->top;
    v13 = (GCObject *)b.L;
    lvl = b.lvl + 1;
    b.p = b.buffer;
    ++b.lvl;
  }
  v20 = (lua_State *)v13;
  if ( lvl < 2 )
  {
    if ( lvl == 0 )
    {
      hash = (_DWORD *)v13->ts.tsv.hash;
      p_hash = &v13->ts.tsv.hash;
      *hash = luaS_newlstr(L: (lua_State *)v13, str: (char *)Ptr, l: 0);
      hash[2] = 4;
      *p_hash += 16;
    }
    return 1;
  }
  else
  {
    if ( *(_DWORD *)(v13->ts.tsv.len + 68) >= *(_DWORD *)(v13->ts.tsv.len + 64) )
      luaC_step(L: v13);
    luaV_concat(L: v20, total: lvl, last: v20->top - v20->base - 1);
    v20->top = (lua_TValue *)((char *)v20->top + 16 - 16 * lvl);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001EEA0
// Name: set2
// Source: json
//------------------------------------------------------------------------------
void __usercall set2(lua_State *L@<esi>, int i@<ecx>, int j)
{
  lua_TValue *top; // ebx
  Node *v4; // eax
  lua_TValue *v5; // eax
  GCObject *b; // eax
  global_State *l_G; // ecx
  lua_TValue *v8; // ebx
  Node *v9; // eax
  lua_TValue *v10; // eax
  GCObject *v11; // eax
  global_State *v12; // ecx
  lua_TValue *base; // [esp+8h] [ebp-4h]
  lua_TValue *v14; // [esp+8h] [ebp-4h]

  top = L->top;
  base = &luaO_nilobject_;
  if ( L->base < top )
    base = L->base;
  v4 = luaH_setnum(t: base->value.gc, key: i, L);
  v4->i_val.value = top[-1].value;
  v4->i_val.tt = top[-1].tt;
  v5 = L->top;
  if ( v5[-1].tt >= 4 && (*(_BYTE *)(v5[-1].value.b + 5) & 3) != 0 )
  {
    b = (GCObject *)base->value.b;
    if ( (*(_BYTE *)(base->value.b + 5) & 4) != 0 )
    {
      l_G = L->l_G;
      b->gch.marked &= ~4u;
      b->cl.c.upvalue[0].value.b = (int)l_G->grayagain;
      l_G->grayagain = b;
    }
  }
  v8 = --L->top;
  v14 = &luaO_nilobject_;
  if ( L->base < v8 )
    v14 = L->base;
  v9 = luaH_setnum(t: v14->value.gc, key: j, L);
  v9->i_val.value = v8[-1].value;
  v9->i_val.tt = v8[-1].tt;
  v10 = L->top;
  if ( v10[-1].tt >= 4 && (*(_BYTE *)(v10[-1].value.b + 5) & 3) != 0 )
  {
    v11 = (GCObject *)v14->value.b;
    if ( (*(_BYTE *)(v14->value.b + 5) & 4) != 0 )
    {
      v12 = L->l_G;
      v11->gch.marked &= ~4u;
      v11->cl.c.upvalue[0].value.b = (int)v12->grayagain;
      v12->grayagain = v11;
    }
  }
  --L->top;
}

//------------------------------------------------------------------------------
// Address: 0x1001EF80
// Name: sort_comp
// Source: json
//------------------------------------------------------------------------------
int __usercall sort_comp@<eax>(lua_State *L@<esi>, int a@<eax>, int b)
{
  lua_TValue *top; // ecx
  lua_TValue *v4; // edx
  lua_TValue *v5; // ecx
  int tt; // eax
  lua_TValue *v7; // ecx
  lua_TValue *v9; // edi
  lua_TValue *v10; // eax

  top = L->top;
  v4 = L->base + 1;
  if ( v4 >= top )
    goto LABEL_5;
  if ( v4 == &luaO_nilobject_ || L->base[1].tt != 0 )
  {
    if ( v4 < top )
    {
LABEL_6:
      top->value.b = v4->value.b;
      *(&top->value.b + 1) = *(&v4->value.b + 1);
      top->tt = v4->tt;
      ++L->top;
      *L->top++ = *index2adr(L, idx: a - 1);
      *L->top++ = *index2adr(L, idx: b - 2);
      luaD_call(L, func: L->top - 3, nResults: 1);
      v5 = L->top;
      tt = v5[-1].tt;
      v7 = v5 - 1;
      if ( tt != 0 && (tt != 1 || v7->value.b != 0) )
      {
        L->top = v7;
        return 1;
      }
      else
      {
        L->top = v7;
        return 0;
      }
    }
LABEL_5:
    v4 = &luaO_nilobject_;
    goto LABEL_6;
  }
  v9 = index2adr(L, idx: a);
  v10 = index2adr(L, idx: b);
  if ( v9 == &luaO_nilobject_ || v10 == &luaO_nilobject_ )
    return 0;
  else
    return luaV_lessthan(L, l: v9, r: v10);
}

//------------------------------------------------------------------------------
// Address: 0x1001F090
// Name: auxsort
// Source: json
//------------------------------------------------------------------------------
void __cdecl auxsort(lua_State *L, int l, int u)
{
  lua_TValue *base; // ecx
  lua_TValue *top; // ebx
  Node *v5; // eax
  lua_TValue *v6; // ebx
  lua_TValue *v7; // ecx
  Node *v8; // eax
  lua_TValue *v9; // ecx
  lua_TValue *v10; // ebx
  Node *v11; // eax
  lua_TValue *v12; // ebx
  lua_TValue *v13; // ecx
  Node *v14; // eax
  lua_TValue *v15; // ebx
  lua_TValue *v16; // ecx
  Node *v17; // eax
  lua_TValue *v18; // ecx
  lua_TValue *v19; // ebx
  Node *v20; // eax
  lua_TValue *v21; // ebx
  lua_TValue *v22; // ecx
  Node *v23; // eax
  lua_TValue *v24; // ecx
  lua_TValue *v25; // ebx
  Node *v26; // eax
  lua_TValue *v27; // ecx
  lua_TValue *v28; // ebx
  Node *v29; // eax
  lua_TValue *v30; // ecx
  lua_TValue *v31; // eax
  Table **v32; // ecx
  int v33; // esi
  int v34; // eax
  int v35; // ebx
  int i; // [esp+10h] [ebp-8h]
  int ia; // [esp+10h] [ebp-8h]
  int j; // [esp+14h] [ebp-4h]

  if ( l < u )
  {
    do
    {
      base = L->base;
      top = L->top;
      if ( base >= top )
        base = &luaO_nilobject_;
      v5 = luaH_getnum(t: (Table *)base->value.gc, key: l);
      top->value = v5->i_val.value;
      top->tt = v5->i_val.tt;
      v6 = ++L->top;
      v7 = &luaO_nilobject_;
      if ( L->base < v6 )
        v7 = L->base;
      v8 = luaH_getnum(t: (Table *)v7->value.gc, key: u);
      v6->value = v8->i_val.value;
      v6->tt = v8->i_val.tt;
      ++L->top;
      if ( sort_comp(L, a: -1, b: -2) != 0 )
        set2(L, i: l, j: u);
      else
        L->top -= 2;
      if ( u - l == 1 )
        break;
      v9 = L->base;
      v10 = L->top;
      i = (u + l) / 2;
      if ( v9 >= v10 )
        v9 = &luaO_nilobject_;
      v11 = luaH_getnum(t: (Table *)v9->value.gc, key: (u + l) / 2);
      v10->value = v11->i_val.value;
      v10->tt = v11->i_val.tt;
      v12 = ++L->top;
      v13 = &luaO_nilobject_;
      if ( L->base < v12 )
        v13 = L->base;
      v14 = luaH_getnum(t: (Table *)v13->value.gc, key: l);
      v12->value = v14->i_val.value;
      v12->tt = v14->i_val.tt;
      ++L->top;
      if ( sort_comp(L, a: -2, b: -1) != 0 )
      {
        set2(L, i, j: l);
      }
      else
      {
        v15 = --L->top;
        v16 = L->base;
        if ( v16 >= v15 )
          v16 = &luaO_nilobject_;
        v17 = luaH_getnum(t: (Table *)v16->value.gc, key: u);
        v15->value = v17->i_val.value;
        v15->tt = v17->i_val.tt;
        ++L->top;
        if ( sort_comp(L, a: -1, b: -2) != 0 )
          set2(L, i, j: u);
        else
          L->top -= 2;
      }
      if ( u - l == 2 )
        break;
      v18 = L->base;
      v19 = L->top;
      if ( v18 >= v19 )
        v18 = &luaO_nilobject_;
      v20 = luaH_getnum(t: (Table *)v18->value.gc, key: i);
      v19->value = v20->i_val.value;
      v19->tt = v20->i_val.tt;
      ++L->top;
      *L->top = L->top[-1];
      v21 = ++L->top;
      v22 = &luaO_nilobject_;
      if ( L->base < v21 )
        v22 = L->base;
      v23 = luaH_getnum(t: (Table *)v22->value.gc, key: u - 1);
      v21->value = v23->i_val.value;
      v21->tt = v23->i_val.tt;
      ++L->top;
      set2(L, i, j: u - 1);
      ia = l;
      for ( j = u - 1; ; set2(L, i: ia, j) )
      {
        while ( 1 )
        {
          v24 = L->base;
          v25 = L->top;
          ++ia;
          if ( v24 >= v25 )
            v24 = &luaO_nilobject_;
          v26 = luaH_getnum(t: (Table *)v24->value.gc, key: ia);
          v25->value = v26->i_val.value;
          v25->tt = v26->i_val.tt;
          ++L->top;
          if ( sort_comp(L, a: -1, b: -2) == 0 )
            break;
          if ( ia > u )
            luaL_error(L, fmt: "invalid order function for sorting");
          --L->top;
        }
        while ( 1 )
        {
          v27 = L->base;
          v28 = L->top;
          --j;
          if ( v27 >= v28 )
            v27 = &luaO_nilobject_;
          v29 = luaH_getnum(t: (Table *)v27->value.gc, key: j);
          v28->value = v29->i_val.value;
          v28->tt = v29->i_val.tt;
          ++L->top;
          if ( sort_comp(L, a: -3, b: -1) == 0 )
            break;
          if ( j < l )
            luaL_error(L, fmt: "invalid order function for sorting");
          --L->top;
        }
        if ( j < ia )
          break;
      }
      v30 = L->base;
      L->top -= 3;
      if ( v30 >= L->top )
        v30 = &luaO_nilobject_;
      *L->top = luaH_getnum(t: (Table *)v30->value.gc, key: u - 1)->i_val;
      v31 = L->base;
      ++L->top;
      v32 = (Table **)&luaO_nilobject_;
      if ( v31 < L->top )
        v32 = (Table **)v31;
      *L->top++ = luaH_getnum(t: *v32, key: ia)->i_val;
      set2(L, i: u - 1, j: ia);
      v33 = u;
      v34 = l;
      if ( ia - l >= u - ia )
      {
        v34 = ia + 1;
        v35 = u;
        u = ia - 1;
        v33 = ia - 1;
      }
      else
      {
        v35 = ia - 1;
        l = ia - 1 + 2;
      }
      auxsort(L, l: v34, u: v35);
    }
    while ( l < v33 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001F470
// Name: sort
// Source: json
//------------------------------------------------------------------------------
int __cdecl sort(lua_State *L)
{
  lua_TValue *base; // eax
  lua_TValue *top; // ecx
  int tt; // eax
  const char *v4; // eax
  const char *v5; // eax
  lua_TValue *v6; // esi
  int stacksize; // eax
  int v8; // eax
  CallInfo *ci; // ecx
  lua_TValue *v10; // eax
  lua_TValue *v11; // ecx
  lua_TValue *v12; // eax
  int v13; // eax
  const char *v14; // eax
  const char *v15; // eax
  int u; // [esp+Ch] [ebp-4h]

  base = L->base;
  top = L->top;
  if ( base >= top )
    goto LABEL_7;
  if ( base == &luaO_nilobject_ || base->tt != 5 )
  {
    if ( base < top && base != &luaO_nilobject_ )
    {
      tt = base->tt;
      if ( tt != -1 )
      {
        v4 = luaT_typenames[tt];
LABEL_9:
        v5 = lua_pushfstring(L, fmt: "%s expected, got %s", "table", v4);
        luaL_argerror(L, extramsg: v5, narg: 1);
      }
    }
LABEL_7:
    v4 = "no value";
    goto LABEL_9;
  }
  v6 = L->base;
  if ( v6 >= L->top )
    v6 = &luaO_nilobject_;
  switch ( v6->tt )
  {
    case 3:
      if ( luaV_tostring(L, obj: v6) != 0 )
        u = *(_DWORD *)(v6->value.b + 16);
      else
        u = 0;
      break;
    case 4:
      u = *(_DWORD *)(v6->value.b + 16);
      break;
    case 5:
      u = luaH_getn(t: (Table *)v6->value.gc);
      break;
    case 7:
      u = *(_DWORD *)(v6->value.b + 16);
      break;
    default:
      u = 0;
      break;
  }
  if ( L->top - L->base + 40 > 8000 )
    luaL_error(L, fmt: "stack overflow (%s)", Ptr);
  if ( (char *)L->stack_last - (char *)L->top <= 640 )
  {
    stacksize = L->stacksize;
    if ( stacksize < 40 )
      v8 = stacksize + 40;
    else
      v8 = 2 * stacksize;
    luaD_reallocstack(L, newsize: v8);
  }
  ci = L->ci;
  v10 = L->top + 40;
  if ( ci->top < v10 )
    ci->top = v10;
  v11 = L->top;
  v12 = L->base + 1;
  if ( v12 < v11 && v12 != &luaO_nilobject_ && L->base[1].tt > 0 )
  {
    if ( v12 >= v11 )
      goto LABEL_38;
    if ( v12 == &luaO_nilobject_ || L->base[1].tt != 6 )
    {
      if ( v12 < v11 && v12 != &luaO_nilobject_ )
      {
        v13 = L->base[1].tt;
        if ( v13 != -1 )
        {
          v14 = luaT_typenames[v13];
LABEL_40:
          v15 = lua_pushfstring(L, fmt: "%s expected, got %s", "function", v14);
          luaL_argerror(L, extramsg: v15, narg: 2);
        }
      }
LABEL_38:
      v14 = "no value";
      goto LABEL_40;
    }
  }
  for ( ; L->top < L->base + 2; ++L->top )
    L->top->tt = 0;
  L->top = L->base + 2;
  auxsort(L, l: 1, u);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001F670
// Name: table_keyopts
// Source: json
//------------------------------------------------------------------------------
int __cdecl table_keyopts(lua_State *L)
{
  lua_TValue *base; // eax
  lua_TValue *top; // ecx
  int tt; // eax
  const char *v4; // eax
  const char *v5; // eax
  lua_TValue *v6; // edi
  lua_TValue *v7; // ebx
  lua_TValue *v8; // eax
  int b; // edx
  lua_TValue *v10; // eax
  lua_TValue *v11; // eax
  int v13; // ecx
  BOOL v14; // ecx
  char v15; // al

  base = L->base;
  top = L->top;
  if ( base >= top )
    goto LABEL_7;
  if ( base == &luaO_nilobject_ || base->tt != 5 )
  {
    if ( base < top && base != &luaO_nilobject_ )
    {
      tt = base->tt;
      if ( tt != -1 )
      {
        v4 = luaT_typenames[tt];
LABEL_9:
        v5 = lua_pushfstring(L, fmt: "%s expected, got %s", "table", v4);
        luaL_argerror(L, extramsg: v5, narg: 1);
      }
    }
LABEL_7:
    v4 = "no value";
    goto LABEL_9;
  }
  v6 = L->top;
  v7 = L->base;
  v8 = &luaO_nilobject_;
  if ( v7 < v6 )
    v8 = L->base;
  switch ( v8->tt )
  {
    case 2:
    case 7:
      v10 = &luaO_nilobject_;
      if ( v7 < v6 )
        v10 = L->base;
      if ( v10->tt == 2 )
      {
        b = v10->value.b;
      }
      else if ( v10->tt == 7 )
      {
        b = v10->value.b + 24;
      }
      else
      {
        b = 0;
      }
      break;
    case 5:
    case 6:
    case 8:
      b = v8->value.b;
      break;
    default:
      b = 0;
      break;
  }
  v11 = v7 + 1;
  if ( &v7[1] >= v6 || v11 == &luaO_nilobject_ || v7[1].tt <= 0 )
  {
    v6->value.b = (*(_BYTE *)(b + 6) & 0x40) == 0;
    v6->tt = 1;
    ++L->top;
    return 1;
  }
  else
  {
    if ( v11 >= v6 )
      v11 = &luaO_nilobject_;
    v13 = v11->tt;
    v14 = v13 != 0 && (v13 != 1 || v11->value.b != 0);
    v15 = *(_BYTE *)(b + 6);
    if ( v15 >= 0 )
      luaL_error(L, fmt: "cannot change key options after a table has been modified");
    *(_BYTE *)(b + 6) = v15 ^ (v15 ^ (!v14 << 6)) & 0x40;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001F7D0
// Name: _luaopen_table
// Source: json
//------------------------------------------------------------------------------
int __cdecl luaopen_table(lua_State *L)
{
  luaL_openlib(L, libname: "table", l: tab_funcs);
  return 1;
}
