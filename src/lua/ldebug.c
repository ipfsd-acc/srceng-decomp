// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: lua/ldebug.c
// Functions: 27
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00474860
// Name: currentline
// Source: json
//------------------------------------------------------------------------------
int __usercall currentline@<eax>(lua_State *L@<edx>, CallInfo *ci@<eax>)
{
  lua_TValue *func; // ecx
  int v3; // ecx
  int v4; // eax
  int v6; // ecx

  func = ci->func;
  if ( func->tt != 6 || *(_BYTE *)(func->value.b + 6) != 0 )
    return -1;
  if ( ci == L->ci )
    ci->savedpc = L->savedpc;
  v3 = *(_DWORD *)(func->value.b + 16);
  v4 = (((int)ci->savedpc - *(_DWORD *)(v3 + 12)) >> 2) - 1;
  if ( v4 < 0 )
    return -1;
  v6 = *(_DWORD *)(v3 + 20);
  if ( v6 != 0 )
    return *(_DWORD *)(v6 + 4 * v4);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004748B0
// Name: int lua_sethook(struct lua_State __near *,void (*)(struct lua_State __near *,struct lua_Debug __near *),int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lua_sethook(lua_State *L, void (__cdecl *func)(lua_State *, lua_Debug *), int mask, int count)
{
  void (__cdecl *v4)(lua_State *, lua_Debug *); // edx
  unsigned __int8 v5; // cl

  v4 = func;
  if ( func == nullptr || (v5 = mask, mask == 0) )
  {
    v5 = 0;
    v4 = nullptr;
  }
  L->hook = v4;
  L->basehookcount = count;
  L->hookcount = count;
  L->hookmask = v5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004748E0
// Name: void (*lua_gethook(struct lua_State __near *))(struct lua_State __near *,struct lua_Debug __near *)
// Source: json
//------------------------------------------------------------------------------
void (__cdecl *__cdecl lua_gethook(lua_State *L))(lua_State *, lua_Debug *)
{
  return L->hook;
}

//------------------------------------------------------------------------------
// Address: 0x004748F0
// Name: int lua_gethookmask(struct lua_State __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lua_gethookmask(lua_State *L)
{
  return L->hookmask;
}

//------------------------------------------------------------------------------
// Address: 0x00474900
// Name: int lua_gethookcount(struct lua_State __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lua_gethookcount(lua_State *L)
{
  return L->basehookcount;
}

//------------------------------------------------------------------------------
// Address: 0x00474910
// Name: int lua_getstack(struct lua_State __near *,int,struct lua_Debug __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lua_getstack(lua_State *L, int level, lua_Debug *ar)
{
  int v3; // ecx
  CallInfo *ci; // eax
  bool v5; // zf
  CallInfo *base_ci; // edx
  unsigned int v7; // edx

  v3 = level;
  ci = L->ci;
  v5 = level == 0;
  if ( level > 0 )
  {
    do
    {
      if ( ci <= L->base_ci )
        break;
      --v3;
      if ( ci->func->value.gc->ts.tsv.reserved == 0 )
        v3 -= ci->tailcalls;
      --ci;
    }
    while ( v3 > 0 );
    v5 = v3 == 0;
  }
  if ( v5 )
  {
    base_ci = L->base_ci;
    if ( ci > base_ci )
    {
      v7 = (int)((unsigned __int64)(715827883LL * ((char *)ci - (char *)base_ci)) >> 32) >> 2;
      ar->i_ci = v7 + (v7 >> 31);
      return 1;
    }
  }
  else if ( v3 < 0 )
  {
    ar->i_ci = 0;
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00474990
// Name: findlocal
// Source: json
//------------------------------------------------------------------------------
const char *__usercall findlocal@<eax>(CallInfo *ci@<esi>, int n@<edi>, lua_State *L)
{
  lua_TValue *func; // eax
  const Proto *v4; // ecx
  const char *result; // eax
  lua_TValue *top; // eax

  func = ci->func;
  if ( func->tt != 6 )
    goto LABEL_7;
  if ( *(_BYTE *)(func->value.b + 6) != 0 )
    goto LABEL_7;
  v4 = *(const Proto **)(func->value.b + 16);
  if ( v4 == nullptr )
    goto LABEL_7;
  if ( ci == L->ci )
    ci->savedpc = L->savedpc;
  result = luaF_getlocalname(
             f: v4,
             local_number: n,
             pc: (((int)ci->savedpc - *(_DWORD *)(*(_DWORD *)(func->value.b + 16) + 12)) >> 2) - 1);
  if ( result == nullptr )
  {
LABEL_7:
    if ( ci == L->ci )
      top = L->top;
    else
      top = ci[1].func;
    if ( top - ci->base < n || n <= 0 )
      return nullptr;
    else
      return "(*temporary)";
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00474A00
// Name: char const __near * lua_getlocal(struct lua_State __near *,struct lua_Debug const __near *,int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl lua_getlocal(lua_State *L, CallInfo *ar, int n)
{
  const char *result; // eax
  const char *v4; // esi
  CallInfo *ci; // [esp+18h] [ebp+Ch]

  ci = &L->base_ci[(int)ar[4].base];
  result = findlocal(ci, n, L);
  v4 = result;
  if ( result != nullptr )
  {
    luaA_pushobject(L, o: &ci->base[n - 1]);
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00474A50
// Name: char const __near * lua_setlocal(struct lua_State __near *,struct lua_Debug const __near *,int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl lua_setlocal(lua_State *L, const lua_Debug *ar, int n)
{
  CallInfo *v3; // esi
  const char *result; // eax

  v3 = &L->base_ci[ar->i_ci];
  result = findlocal(ci: v3, n, L);
  if ( result != nullptr )
    v3->base[n - 1] = L->top[-1];
  --L->top;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00474AA0
// Name: funcinfo
// Source: json
//------------------------------------------------------------------------------
void __usercall funcinfo(lua_Debug *ar@<eax>, Closure *cl@<ecx>)
{
  const char *source; // ecx
  bool v3; // zf
  const char *v4; // ecx

  if ( cl->c.isC != 0 )
  {
    ar->source = "=[C]";
    ar->linedefined = -1;
    ar->lastlinedefined = -1;
    source = ar->source;
    ar->what = "C";
    luaO_chunkid(out: ar->short_src, source, bufflen: 0x3Cu);
  }
  else
  {
    ar->source = (const char *)(*((_DWORD *)cl->c.f + 8) + 16);
    ar->linedefined = *((_DWORD *)cl->c.f + 15);
    v3 = ar->linedefined == 0;
    ar->lastlinedefined = *((_DWORD *)cl->c.f + 16);
    v4 = "main";
    if ( !v3 )
      v4 = "Lua";
    ar->what = v4;
    luaO_chunkid(out: ar->short_src, source: ar->source, bufflen: 0x3Cu);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00474B20
// Name: collectvalidlines
// Source: json
//------------------------------------------------------------------------------
void __usercall collectvalidlines(lua_State *L@<edi>, Table *f)
{
  int v3; // esi
  int (__cdecl *node)(lua_State *); // eax
  lua_TValue *v5; // eax
  lua_TValue *top; // eax
  int *lineinfo; // [esp+8h] [ebp-4h]
  Table *t; // [esp+14h] [ebp+8h]

  v3 = 0;
  if ( f == nullptr || f->flags != 0 )
  {
    L->top->tt = 0;
  }
  else
  {
    t = luaH_new(L, narray: 0, nhash: 0);
    node = (int (__cdecl *)(lua_State *))f->node;
    lineinfo = *((int **)node + 5);
    if ( *((int *)node + 12) > 0 )
    {
      do
      {
        v5 = luaH_setnum(L, t, key: lineinfo[v3]);
        v5->value.b = 1;
        v5->tt = 1;
        ++v3;
      }
      while ( v3 < f->node[1].i_key.nk.value.b );
    }
    top = L->top;
    top->value.b = (int)t;
    top->tt = 5;
  }
  if ( (char *)L->stack_last - (char *)L->top <= 16 )
    luaD_growstack(L, n: 1);
  ++L->top;
}

//------------------------------------------------------------------------------
// Address: 0x00474BC0
// Name: int luaG_checkopenop(unsigned int)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl luaG_checkopenop(unsigned int i)
{
  unsigned int v1; // ecx

  v1 = i & 0x3F;
  return v1 >= 0x1C && ((i & 0x3F) <= 0x1E || v1 == 34) && (i & 0xFF800000) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x00474BF0
// Name: checkArgMode
// Source: json
//------------------------------------------------------------------------------
char __fastcall checkArgMode(int r, const Proto *pt, OpArgMask mode)
{
  int v3; // eax

  if ( mode == OpArgN )
  {
    if ( r != 0 )
      goto LABEL_10;
    goto LABEL_12;
  }
  if ( mode == OpArgR )
  {
    if ( r >= pt->maxstacksize )
    {
LABEL_10:
      LOBYTE(v3) = 0;
      return v3;
    }
LABEL_12:
    LOBYTE(v3) = 1;
    return v3;
  }
  v3 = mode - 3;
  if ( mode != OpArgK )
    goto LABEL_12;
  if ( (r & 0x100) != 0 )
    LOBYTE(v3) = (int)(r & 0xFFFFFEFF) < pt->sizek;
  else
    v3 = r < pt->maxstacksize;
  if ( v3 != 0 )
    goto LABEL_12;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00474C50
// Name: symbexec
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl symbexec(const Proto *pt, int lastpc, int reg)
{
  int sizecode; // ecx
  unsigned __int8 maxstacksize; // dl
  int sizelineinfo; // esi
  unsigned int *code; // eax
  unsigned int v8; // eax
  unsigned int v9; // ecx
  int v10; // esi
  int v11; // ebx
  unsigned int v12; // edi
  int v13; // eax
  int v14; // eax
  int v15; // edi
  char v16; // al
  int v17; // edx
  int v18; // eax
  int v19; // eax
  bool v20; // cc
  int v21; // ebx
  int v22; // eax
  int v23; // edi
  int v24; // esi
  int v25; // ecx
  unsigned int *v26; // edx
  int v27; // eax
  unsigned __int8 is_vararg; // al
  int v29; // esi
  int nups; // [esp+4h] [ebp-24h]
  OpCode op; // [esp+8h] [ebp-20h]
  int v32; // [esp+Ch] [ebp-1Ch]
  int last; // [esp+10h] [ebp-18h]
  unsigned int *v34; // [esp+14h] [ebp-14h]
  int v35; // [esp+18h] [ebp-10h]
  int c; // [esp+1Ch] [ebp-Ch]
  int pc; // [esp+20h] [ebp-8h]
  unsigned __int8 v38; // [esp+26h] [ebp-2h]

  sizecode = pt->sizecode;
  last = sizecode - 1;
  maxstacksize = pt->maxstacksize;
  v32 = sizecode;
  v38 = maxstacksize;
  if ( maxstacksize > 0xFAu )
    return 0;
  nups = pt->nups;
  if ( pt->sizeupvalues > nups )
    return 0;
  sizelineinfo = pt->sizelineinfo;
  if ( sizelineinfo != sizecode && sizelineinfo != 0 )
    return 0;
  code = pt->code;
  v34 = code;
  if ( (code[sizecode - 1] & 0x3F) != 0x1E )
    return 0;
  pc = 0;
  if ( lastpc <= 0 )
    return code[last];
  while ( 2 )
  {
    v8 = v34[pc];
    v9 = v8 & 0x3F;
    v10 = 0;
    v11 = (unsigned __int8)(v8 >> 6);
    op = v9;
    c = 0;
    if ( v9 >= 0x26 )
      return 0;
    v35 = maxstacksize;
    if ( v11 >= maxstacksize )
      return 0;
    v12 = luaP_opmodes[v9];
    switch ( luaP_opmodes[v9] & 3 )
    {
      case 0:
        v10 = v8 >> 23;
        c = (v8 >> 14) & 0x1FF;
        LOBYTE(v18) = checkArgMode(r: v8 >> 23, pt, mode: (OpArgMask)((v12 >> 4) & 3));
        if ( v18 == 0 )
          return 0;
        LOBYTE(v19) = checkArgMode(r: c, pt, mode: (OpArgMask)((v12 >> 2) & 3));
        if ( v19 == 0 )
          return 0;
        v9 = op;
        goto LABEL_21;
      case 1:
        v10 = v8 >> 14;
        if ( (luaP_opmodes[v9] & 0x30) == 0x30 && v10 >= pt->sizek )
          return 0;
        goto LABEL_21;
      case 2:
        v13 = (v8 >> 14) - 0x1FFFF;
        v10 = v13;
        if ( (luaP_opmodes[v9] & 0x30) == 0x20 )
        {
          v14 = v13 + pc + 1;
          if ( v14 < 0 || v14 >= v32 || v14 > 0 && (v34[v14 - 1] & 0x3F) == 0x22 && (v34[v14 - 1] & 0x7FC000) == 0 )
            return 0;
        }
LABEL_21:
        v15 = c;
        goto LABEL_22;
      default:
        break;
    }
    v15 = 0;
LABEL_22:
    v16 = luaP_opmodes[v9];
    v17 = pc;
    if ( (v16 & 0x40) != 0 && v11 == reg )
      last = pc;
    if ( v16 < 0 )
    {
      if ( pc + 2 >= v32 || (v34[pc + 1] & 0x3F) != 0x16 )
        return 0;
      v17 = pc;
    }
    switch ( v9 )
    {
      case 2u:
        if ( v15 == 0 )
          goto LABEL_87;
        v20 = v17 + 2 < v32;
        goto LABEL_86;
      case 3u:
        if ( v11 <= reg && reg <= v10 )
          last = v17;
        goto LABEL_87;
      case 4u:
      case 8u:
        v20 = v10 < nups;
        goto LABEL_86;
      case 5u:
      case 7u:
        if ( pt->k[v10].tt != 4 )
          return 0;
        goto LABEL_87;
      case 0xBu:
        v21 = v11 + 1;
        if ( v21 >= v35 )
          return 0;
        if ( reg == v21 )
          last = v17;
        goto LABEL_87;
      case 0x15u:
        v20 = v10 < v15;
        goto LABEL_86;
      case 0x16u:
        goto $LN33_0;
      case 0x1Cu:
      case 0x1Du:
        if ( v10 != 0 && v10 + v11 - 1 >= v35 )
          return 0;
        v23 = v15 - 1;
        if ( v23 == -1 )
        {
          if ( !luaG_checkopenop(i: v34[v17 + 1]) )
            return 0;
        }
        else if ( v23 != 0 && v23 + v11 - 1 >= v35 )
        {
          return 0;
        }
        if ( reg >= v11 )
          last = v17;
LABEL_87:
        pc = v17 + 1;
        if ( v17 + 1 < lastpc )
        {
          maxstacksize = v38;
          continue;
        }
        return v34[last];
      case 0x1Eu:
        v24 = v10 - 1;
        if ( v24 <= 0 )
          goto LABEL_87;
        v20 = v24 + v11 - 1 < v35;
        goto LABEL_86;
      case 0x1Fu:
      case 0x20u:
        if ( v11 + 3 >= v35 )
          return 0;
$LN33_0:
        v22 = v10 + v17 + 1;
        if ( reg != 255 && v17 < v22 && v22 <= lastpc )
          v17 += v10;
        goto LABEL_87;
      case 0x21u:
        if ( v15 < 1 || v15 + v11 + 2 >= v35 )
          return 0;
        if ( reg >= v11 + 2 )
          last = v17;
        goto LABEL_87;
      case 0x22u:
        if ( v10 > 0 && v11 + v10 >= v35 )
          return 0;
        if ( v15 == 0 )
          ++v17;
        goto LABEL_87;
      case 0x24u:
        if ( v10 >= pt->sizep )
          return 0;
        v25 = pt->p[v10]->nups;
        if ( v25 + v17 >= v32 )
          return 0;
        if ( pt->p[v10]->nups == 0 )
          goto LABEL_87;
        v26 = &v34[v25 + v17];
        do
        {
          v27 = *v26 & 0x3F;
          if ( v27 != 4 && v27 != 0 )
            return 0;
          --v25;
          --v26;
        }
        while ( v25 > 0 );
        v17 = pc;
        goto LABEL_87;
      case 0x25u:
        is_vararg = pt->is_vararg;
        if ( (is_vararg & 2) == 0 )
          return 0;
        if ( (is_vararg & 4) != 0 )
          return 0;
        v29 = v10 - 1;
        if ( v29 == -1 && !luaG_checkopenop(i: v34[v17 + 1]) )
          return 0;
        v20 = v29 + v11 - 1 < v35;
LABEL_86:
        if ( v20 )
          goto LABEL_87;
        return 0;
      default:
        goto LABEL_87;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00475090
// Name: int luaG_checkcode(struct Proto const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl luaG_checkcode(const Proto *pt)
{
  return symbexec(pt, lastpc: pt->sizecode, reg: 255) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x004750B0
// Name: kname
// Source: json
//------------------------------------------------------------------------------
const char *__usercall kname@<eax>(Proto *p@<ecx>, int c@<eax>)
{
  lua_TValue *k; // edx
  unsigned int v3; // eax

  if ( (c & 0x100) != 0 && (k = p->k, v3 = c & 0xFFFFFEFF, k[v3].tt == 4) )
    return (const char *)(k[v3].value.b + 16);
  else
    return "?";
}

//------------------------------------------------------------------------------
// Address: 0x004750E0
// Name: getobjname
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl getobjname(lua_State *L, CallInfo *ci, unsigned int stackpos, const char **name)
{
  CallInfo *v4; // edx
  int *func; // eax
  Proto *v8; // edi
  int v9; // esi
  const char *v10; // eax
  unsigned int v11; // eax
  TString **upvalues; // edi

  v4 = ci;
  if ( ci->func->tt != 6 )
    return nullptr;
  while ( 1 )
  {
    func = (int *)v4->func;
    if ( *(_BYTE *)(*func + 6) != 0 )
      return nullptr;
    v8 = *(Proto **)(*func + 16);
    if ( func[2] == 6 )
    {
      if ( v4 == L->ci )
        v4->savedpc = L->savedpc;
      v9 = (((int)v4->savedpc - *(_DWORD *)(*(_DWORD *)(*func + 16) + 12)) >> 2) - 1;
    }
    else
    {
      v9 = -1;
    }
    v10 = luaF_getlocalname(f: v8, local_number: stackpos + 1, pc: v9);
    *name = v10;
    if ( v10 != nullptr )
      break;
    v11 = symbexec(pt: v8, lastpc: v9, reg: stackpos);
    switch ( v11 & 0x3F )
    {
      case 0u:
        if ( v11 >> 23 >= (unsigned __int8)(v11 >> 6) )
          return nullptr;
        stackpos = v11 >> 23;
        if ( ci->func->tt != 6 )
          return nullptr;
        v4 = ci;
        break;
      case 4u:
        upvalues = v8->upvalues;
        if ( upvalues != nullptr )
          *name = (const char *)&upvalues[v11 >> 23][1];
        else
          *name = "?";
        return "upvalue";
      case 5u:
        *name = (const char *)(v8->k[v11 >> 14].value.b + 16);
        return "global";
      case 6u:
        *name = kname(p: v8, c: (v11 >> 14) & 0x1FF);
        return "field";
      case 0xBu:
        *name = kname(p: v8, c: (v11 >> 14) & 0x1FF);
        return "method";
      default:
        return nullptr;
    }
  }
  return "local";
}

//------------------------------------------------------------------------------
// Address: 0x00475260
// Name: getfuncname
// Source: json
//------------------------------------------------------------------------------
const char *__usercall getfuncname@<eax>(lua_State *L@<edi>, CallInfo *ci@<ecx>, const char **name)
{
  lua_TValue *func; // eax
  lua_TValue *v4; // eax
  lua_TValue *v5; // edx
  CallInfo *v6; // ecx
  int v7; // eax
  unsigned int v8; // eax
  int v9; // edx

  func = ci->func;
  if ( func->tt == 6 && *(_BYTE *)(func->value.b + 6) == 0 && ci->tailcalls > 0 )
    return nullptr;
  v4 = ci[-1].func;
  if ( v4->tt != 6 || *(_BYTE *)(v4->value.b + 6) != 0 )
    return nullptr;
  v5 = ci[-1].func;
  v6 = ci - 1;
  if ( v5->tt != 6 || *(_BYTE *)(v5->value.b + 6) != 0 )
  {
    v7 = -1;
  }
  else
  {
    if ( v6 == L->ci )
      v6->savedpc = L->savedpc;
    v7 = (((int)v6->savedpc - *(_DWORD *)(*(_DWORD *)(v5->value.b + 16) + 12)) >> 2) - 1;
  }
  v8 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v5->value.b + 16) + 12) + 4 * v7);
  v9 = v8 & 0x3F;
  if ( v9 == 28 || v9 == 29 || v9 == 33 )
    return getobjname(L, ci: v6, stackpos: (unsigned __int8)(v8 >> 6), name);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00475300
// Name: addinfo
// Source: json
//------------------------------------------------------------------------------
void __usercall addinfo(lua_State *L@<edi>, const char *msg)
{
  CallInfo *ci; // esi
  int *func; // eax
  int v4; // eax
  int *v5; // esi
  int v6; // ebx
  int v7; // esi
  int v8; // eax
  char buff[60]; // [esp+4h] [ebp-3Ch] BYREF

  ci = L->ci;
  func = (int *)ci->func;
  if ( func[2] == 6 && *(_BYTE *)(*func + 6) == 0 )
  {
    v4 = currentline(L, ci);
    v5 = (int *)ci->func;
    v6 = v4;
    if ( v5[2] != 6 || *(_BYTE *)((v7 = *v5) + 6) != 0 )
      v8 = 0;
    else
      v8 = *(_DWORD *)(v7 + 16);
    luaO_chunkid(out: buff, source: (const char *)(*(_DWORD *)(v8 + 32) + 16), bufflen: 0x3Cu);
    luaO_pushfstring(L, fmt: "%s:%d: %s", buff, v6, msg);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00475370
// Name: void luaG_errormsg(struct lua_State __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn luaG_errormsg(lua_State *L)
{
  int errfunc; // eax
  lua_TValue *v2; // edi

  errfunc = L->errfunc;
  if ( errfunc != 0 )
  {
    v2 = (lua_TValue *)((char *)L->stack + errfunc);
    if ( v2->tt != 6 )
      luaD_throw(L, errcode: 5);
    *L->top = L->top[-1];
    L->top[-1] = *v2;
    if ( (char *)L->stack_last - (char *)L->top <= 16 )
      luaD_growstack(L, n: 1);
    luaD_call(L, func: ++L->top - 2, nResults: 1);
  }
  luaD_throw(L, errcode: 2);
}

//------------------------------------------------------------------------------
// Address: 0x00475400
// Name: void luaG_runerror(struct lua_State __near *,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void __noreturn luaG_runerror(lua_State *L, const char *fmt, ...)
{
  const char *v2; // eax
  va_list argp; // [esp+14h] [ebp+10h] BYREF

  va_start(argp, fmt);
  v2 = luaO_pushvfstring(L, fmt, argp);
  addinfo(L, msg: v2);
  luaG_errormsg(L);
}

//------------------------------------------------------------------------------
// Address: 0x00475430
// Name: auxgetinfo
// Source: json
//------------------------------------------------------------------------------
int __usercall auxgetinfo@<eax>(lua_Debug *ar@<esi>, lua_State *L, const char *what, Closure *f, CallInfo *ci)
{
  Closure *v5; // ecx
  char v7; // al
  const char *v8; // eax
  int status; // [esp+8h] [ebp-4h]

  v5 = f;
  status = 1;
  if ( f != nullptr )
  {
    v7 = *what;
    if ( *what != 0 )
    {
      while ( 1 )
      {
        switch ( v7 )
        {
          case 'L':
          case 'f':
            break;
          case 'S':
            funcinfo(ar, cl: v5);
            break;
          case 'l':
            if ( ci != nullptr )
              ar->currentline = currentline(L, ci);
            else
              ar->currentline = -1;
            break;
          case 'n':
            if ( ci != nullptr )
              v8 = getfuncname(L, ci, name: &ar->name);
            else
              v8 = nullptr;
            ar->namewhat = v8;
            if ( v8 == nullptr )
            {
              ar->namewhat = var;
              ar->name = nullptr;
            }
            break;
          case 'u':
            ar->nups = v5->c.nupvalues;
            break;
          default:
            status = 0;
            break;
        }
        v7 = *++what;
        if ( *what == 0 )
          break;
        v5 = f;
      }
    }
    return status;
  }
  else
  {
    ar->namewhat = var;
    ar->name = var;
    ar->currentline = -1;
    ar->linedefined = -1;
    ar->lastlinedefined = -1;
    ar->what = "tail";
    ar->source = "=(tail call)";
    luaO_chunkid(out: ar->short_src, source: "=(tail call)", bufflen: 0x3Cu);
    ar->nups = 0;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00475580
// Name: int lua_getinfo(struct lua_State __near *,char const __near *,struct lua_Debug __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl lua_getinfo(lua_State *L, char *what, lua_Debug *ar)
{
  const char *v3; // edx
  Closure *gc; // ebx
  CallInfo *v5; // ecx
  lua_TValue *top; // eax
  int i_ci; // eax
  int v8; // esi
  int v9; // eax
  lua_TValue *v10; // eax
  int v11; // eax

  v3 = what;
  gc = nullptr;
  v5 = nullptr;
  if ( *what == 62 )
  {
    top = L->top;
    gc = (Closure *)top[-1].value.gc;
    v3 = ++what;
    L->top = top - 1;
  }
  else
  {
    i_ci = ar->i_ci;
    if ( i_ci != 0 )
    {
      v5 = &L->base_ci[i_ci];
      gc = (Closure *)v5->func->value.gc;
    }
  }
  v8 = auxgetinfo(ar, L, what: v3, f: gc, ci: v5);
  strchr(string: (unsigned __int8 *)what, chr: 0x66u);
  if ( v9 != 0 )
  {
    if ( gc != nullptr )
    {
      v10 = L->top;
      v10->value.b = (int)gc;
      v10->tt = 6;
    }
    else
    {
      L->top->tt = 0;
    }
    if ( (char *)L->stack_last - (char *)L->top <= 16 )
      luaD_growstack(L, n: 1);
    ++L->top;
  }
  strchr(string: (unsigned __int8 *)what, chr: 0x4Cu);
  if ( v11 != 0 )
    collectvalidlines(L, f: (Table *)gc);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x00475630
// Name: void luaG_typeerror(struct lua_State __near *,struct lua_TValue const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn luaG_typeerror(lua_State *L, const lua_TValue *o, const char *op)
{
  const char *v3; // ebx
  CallInfo *ci; // edx
  const lua_TValue *base; // eax
  lua_TValue *top; // esi
  const char *v7; // eax
  const char *name; // [esp+Ch] [ebp-4h] BYREF

  v3 = luaT_typenames[o->tt];
  ci = L->ci;
  name = nullptr;
  base = ci->base;
  top = ci->top;
  if ( ci->base < top )
  {
    while ( o != base )
    {
      if ( ++base >= top )
        goto LABEL_4;
    }
    v7 = getobjname(L, ci, stackpos: o - L->base, &name);
    if ( v7 != nullptr )
      luaG_runerror(L, fmt: "attempt to %s %s '%s' (a %s value)", op, v7, name, v3);
  }
LABEL_4:
  luaG_runerror(L, fmt: "attempt to %s a %s value", op, v3);
}

//------------------------------------------------------------------------------
// Address: 0x004756C0
// Name: void luaG_concaterror(struct lua_State __near *,struct lua_TValue __near *,struct lua_TValue __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn luaG_concaterror(lua_State *L, lua_TValue *p1, lua_TValue *p2)
{
  const lua_TValue *v3; // eax

  v3 = p1;
  if ( p1->tt == 4 )
    v3 = p2;
  luaG_typeerror(L, o: v3, op: "concatenate");
}

//------------------------------------------------------------------------------
// Address: 0x004756F0
// Name: void luaG_aritherror(struct lua_State __near *,struct lua_TValue const __near *,struct lua_TValue const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn luaG_aritherror(lua_State *L, const lua_TValue *p1, const lua_TValue *p2)
{
  bool v3; // zf
  const lua_TValue *v4; // eax
  lua_TValue temp; // [esp+4h] [ebp-10h] BYREF

  v3 = luaV_tonumber(obj: p1, n: &temp) == nullptr;
  v4 = p1;
  if ( !v3 )
    v4 = p2;
  luaG_typeerror(L, o: v4, op: "perform arithmetic on");
}

//------------------------------------------------------------------------------
// Address: 0x00475730
// Name: int luaG_ordererror(struct lua_State __near *,struct lua_TValue const __near *,struct lua_TValue const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn luaG_ordererror(lua_State *L, const lua_TValue *p1, const lua_TValue *p2)
{
  const char *v3; // eax

  v3 = luaT_typenames[p1->tt];
  if ( v3[2] == *((_BYTE *)luaT_typenames[p2->tt] + 2) )
    luaG_runerror(L, fmt: "attempt to compare two %s values", v3);
  luaG_runerror(L, fmt: "attempt to compare %s with %s", v3, luaT_typenames[p2->tt]);
}
