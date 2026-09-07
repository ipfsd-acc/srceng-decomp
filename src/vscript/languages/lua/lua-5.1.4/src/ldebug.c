// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vscript/languages/lua/lua-5.1.4/src/ldebug.c
// Functions: 19
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10008B90
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
// Address: 0x10008BE0
// Name: _lua_getstack
// Source: json
//------------------------------------------------------------------------------
int __usercall lua_getstack@<eax>(lua_State *L@<edx>, int level@<ecx>, lua_Debug *ar@<edi>)
{
  CallInfo *ci; // eax
  bool v4; // zf
  CallInfo *base_ci; // edx
  unsigned int v6; // edx

  ci = L->ci;
  v4 = level == 0;
  if ( level > 0 )
  {
    do
    {
      if ( ci <= L->base_ci )
        break;
      --level;
      if ( ci->func->value.gc->ts.tsv.reserved == 0 )
        level -= ci->tailcalls;
      --ci;
    }
    while ( level > 0 );
    v4 = level == 0;
  }
  if ( v4 )
  {
    base_ci = L->base_ci;
    if ( ci > base_ci )
    {
      v6 = (int)((unsigned __int64)(715827883LL * ((char *)ci - (char *)base_ci)) >> 32) >> 2;
      ar->i_ci = v6 + (v6 >> 31);
      return 1;
    }
  }
  else if ( level < 0 )
  {
    ar->i_ci = 0;
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10008C50
// Name: findlocal
// Source: json
//------------------------------------------------------------------------------
const char *__usercall findlocal@<eax>(CallInfo *ci@<edi>, lua_State *L, int n)
{
  lua_TValue *func; // eax
  int v4; // esi
  int v5; // edx
  int v6; // ebx
  int v7; // eax
  int v8; // ecx
  int *v9; // esi
  const char *result; // eax
  lua_TValue *top; // eax
  int v12; // [esp+8h] [ebp-4h]

  func = ci->func;
  if ( func->tt == 6 && *(_BYTE *)(func->value.b + 6) == 0 )
  {
    v4 = *(_DWORD *)(func->value.b + 16);
    if ( v4 != 0 )
    {
      if ( ci == L->ci )
        ci->savedpc = L->savedpc;
      v5 = *(_DWORD *)(v4 + 56);
      v6 = n;
      v7 = (((int)ci->savedpc - *(_DWORD *)(*(_DWORD *)(func->value.b + 16) + 12)) >> 2) - 1;
      v8 = 0;
      if ( v5 > 0 )
      {
        v12 = *(_DWORD *)(v4 + 24);
        v9 = (int *)(v12 + 8);
        while ( *(v9 - 1) <= v7 )
        {
          if ( v7 < *v9 && --v6 == 0 )
          {
            result = (const char *)(*(_DWORD *)(v12 + 12 * v8) + 24);
            if ( *(_DWORD *)(v12 + 12 * v8) != -24 )
              return result;
            break;
          }
          ++v8;
          v9 += 3;
          if ( v8 >= v5 )
            break;
        }
      }
    }
  }
  if ( ci == L->ci )
    top = L->top;
  else
    top = ci[1].func;
  if ( top - ci->base < n || n <= 0 )
    return nullptr;
  else
    return "(*temporary)";
}

//------------------------------------------------------------------------------
// Address: 0x10008D00
// Name: funcinfo
// Source: json
//------------------------------------------------------------------------------
void __usercall funcinfo(lua_Debug *ar@<ecx>, Closure *cl@<eax>)
{
  bool v2; // zf
  const char *v3; // eax

  if ( cl->c.isC != 0 )
  {
    ar->linedefined = -1;
    ar->lastlinedefined = -1;
    ar->source = "=[C]";
    ar->what = "C";
    luaO_chunkid(out: ar->short_src, source: ar->source, bufflen: 0x3Cu);
  }
  else
  {
    ar->source = (const char *)(*((_DWORD *)cl->c.f + 8) + 24);
    ar->linedefined = *((_DWORD *)cl->c.f + 15);
    v2 = ar->linedefined == 0;
    ar->lastlinedefined = *((_DWORD *)cl->c.f + 16);
    v3 = "main";
    if ( !v2 )
      v3 = "Lua";
    ar->what = v3;
    luaO_chunkid(out: ar->short_src, source: ar->source, bufflen: 0x3Cu);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008D80
// Name: collectvalidlines
// Source: json
//------------------------------------------------------------------------------
void __usercall collectvalidlines(lua_State *L@<edi>, Closure *f)
{
  Table *v2; // esi
  int (__cdecl *v3)(lua_State *); // eax
  int v4; // ebx
  lua_TValue *v5; // eax
  lua_TValue *top; // eax
  int stacksize; // eax
  int i; // [esp+8h] [ebp-18h]
  int *lineinfo; // [esp+Ch] [ebp-14h]
  lua_TValue key; // [esp+10h] [ebp-10h] BYREF

  if ( f == nullptr || f->c.isC != 0 )
  {
    L->top->tt = 0;
  }
  else
  {
    v2 = luaH_new(L, narray: 0, nhash: 0);
    v3 = f->c.f;
    lineinfo = *((int **)v3 + 5);
    i = 0;
    if ( *((int *)v3 + 12) > 0 )
    {
      do
      {
        v4 = lineinfo[i];
        v5 = (lua_TValue *)luaH_getnum(t: v2, key: v4);
        if ( v5 == &luaO_nilobject_ )
        {
          key.value.n = (double)v4;
          key.tt = 3;
          v5 = newkey(L, t: v2, &key);
        }
        v5->value.b = 1;
        v5->tt = 1;
        ++i;
      }
      while ( i < *((_DWORD *)f->c.f + 12) );
    }
    top = L->top;
    top->value.b = (int)v2;
    top->tt = 5;
  }
  if ( (char *)L->stack_last - (char *)L->top <= 16 )
  {
    stacksize = L->stacksize;
    if ( stacksize >= 1 )
    {
      luaD_reallocstack(L, newsize: 2 * stacksize);
      ++L->top;
      return;
    }
    luaD_reallocstack(L, newsize: stacksize + 1);
  }
  ++L->top;
}

//------------------------------------------------------------------------------
// Address: 0x10008E80
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
              ar->namewhat = Ptr;
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
    ar->namewhat = Ptr;
    ar->name = Ptr;
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
// Address: 0x10008FD0
// Name: _lua_getinfo
// Source: json
//------------------------------------------------------------------------------
int __usercall lua_getinfo@<eax>(lua_State *L@<ecx>, lua_Debug *ar@<eax>, char *what)
{
  const char *v3; // edx
  Closure *gc; // ebx
  CallInfo *v6; // ecx
  lua_TValue *top; // eax
  int i_ci; // eax
  int v10; // esi
  int v11; // eax
  lua_TValue *v12; // eax
  int stacksize; // eax
  int v14; // eax
  int v15; // eax

  v3 = what;
  gc = nullptr;
  v6 = nullptr;
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
      v6 = &L->base_ci[i_ci];
      gc = (Closure *)v6->func->value.gc;
    }
  }
  v10 = auxgetinfo(ar, L, what: v3, f: gc, ci: v6);
  strchr(string: (unsigned __int8 *)what, chr: 0x66u);
  if ( v11 != 0 )
  {
    if ( gc != nullptr )
    {
      v12 = L->top;
      v12->value.b = (int)gc;
      v12->tt = 6;
    }
    else
    {
      L->top->tt = 0;
    }
    if ( (char *)L->stack_last - (char *)L->top <= 16 )
    {
      stacksize = L->stacksize;
      if ( stacksize < 1 )
        v14 = stacksize + 1;
      else
        v14 = 2 * stacksize;
      luaD_reallocstack(L, newsize: v14);
    }
    ++L->top;
  }
  strchr(string: (unsigned __int8 *)what, chr: 0x4Cu);
  if ( v15 != 0 )
    collectvalidlines(L, f: gc);
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x100090A0
// Name: precheck
// Source: json
//------------------------------------------------------------------------------
BOOL __usercall precheck@<eax>(const Proto *pt@<eax>)
{
  unsigned __int8 maxstacksize; // dl
  unsigned __int8 is_vararg; // cl
  int sizelineinfo; // edx
  int sizecode; // ecx
  BOOL result; // eax

  maxstacksize = pt->maxstacksize;
  result = false;
  if ( maxstacksize <= 0xFAu )
  {
    is_vararg = pt->is_vararg;
    if ( pt->numparams + (is_vararg & 1u) <= maxstacksize
      && ((is_vararg & 4) == 0 || (is_vararg & 1) != 0)
      && pt->sizeupvalues <= pt->nups )
    {
      sizelineinfo = pt->sizelineinfo;
      sizecode = pt->sizecode;
      if ( (sizelineinfo == sizecode || sizelineinfo == 0) && sizecode > 0 && (pt->code[sizecode - 1] & 0x3F) == 0x1E )
        return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10009100
// Name: _luaG_checkopenop
// Source: json
//------------------------------------------------------------------------------
BOOL __usercall luaG_checkopenop@<eax>(unsigned int i@<eax>)
{
  unsigned int v1; // ecx

  v1 = i & 0x3F;
  return v1 >= 0x1C && ((i & 0x3F) <= 0x1E || v1 == 34) && (i & 0xFF800000) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10009130
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
// Address: 0x10009190
// Name: symbexec
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl symbexec(const Proto *pt, int lastpc, int reg)
{
  const Proto *v3; // esi
  unsigned int result; // eax
  unsigned int v5; // eax
  int v6; // esi
  int v7; // ebx
  unsigned __int8 v8; // dl
  unsigned int v9; // edi
  int v10; // eax
  int v11; // edx
  int v12; // eax
  unsigned int *v13; // ecx
  int v14; // eax
  const Proto *v15; // edi
  int v16; // eax
  int v17; // eax
  char v18; // al
  int v19; // ecx
  bool v20; // cc
  int v21; // ebx
  int v22; // eax
  int v23; // esi
  int nups; // esi
  int v25; // edi
  unsigned int *v26; // ecx
  int v27; // eax
  unsigned __int8 is_vararg; // al
  OpCode op; // [esp+4h] [ebp-1Ch]
  int j; // [esp+8h] [ebp-18h]
  int sizecode; // [esp+Ch] [ebp-14h]
  int last; // [esp+10h] [ebp-10h]
  unsigned int *code; // [esp+14h] [ebp-Ch]
  int c; // [esp+18h] [ebp-8h]
  int pc; // [esp+1Ch] [ebp-4h]

  v3 = pt;
  sizecode = pt->sizecode;
  last = sizecode - 1;
  result = precheck(pt);
  if ( result != 0 )
  {
    pc = 0;
    if ( lastpc <= 0 )
      return v3->code[last];
    code = pt->code;
    while ( 2 )
    {
      v5 = code[pc];
      v6 = 0;
      v7 = (unsigned __int8)(v5 >> 6);
      op = v5 & 0x3F;
      c = 0;
      if ( (unsigned int)op >= (OP_CLOSURE|OP_LOADBOOL) || v7 >= pt->maxstacksize )
        return 0;
      v8 = luaP_opmodes[op];
      v9 = v8;
      if ( (v8 & 3) != 0 )
      {
        if ( (luaP_opmodes[op] & 3) == 1 )
        {
          v14 = v5 >> 14;
          v6 = v14;
          if ( (v8 & 0x30) == 0x30 )
          {
            v15 = pt;
            if ( v14 >= pt->sizek )
              return 0;
            v11 = pc;
            goto LABEL_26;
          }
        }
        else if ( (luaP_opmodes[op] & 3) == 2 )
        {
          v10 = (v5 >> 14) - 0x1FFFF;
          v6 = v10;
          if ( (v8 & 0x30) == 0x20 )
          {
            v11 = pc;
            v12 = v10 + pc + 1;
            if ( v12 < 0 || v12 >= sizecode )
              return 0;
            if ( v12 > 0 )
            {
              j = 0;
              v13 = &code[v12 - 1];
              do
              {
                if ( (*(_BYTE *)v13 & 0x3F) != 0x22 )
                  break;
                if ( (*v13 & 0x7FC000) != 0 )
                  break;
                --v13;
                ++j;
              }
              while ( j < v12 );
              v11 = pc;
              if ( (j & 1) != 0 )
                return 0;
            }
            goto LABEL_25;
          }
        }
      }
      else
      {
        c = (v5 >> 14) & 0x1FF;
        v6 = v5 >> 23;
        LOBYTE(v16) = checkArgMode(r: v5 >> 23, pt, mode: (OpArgMask)((v8 >> 4) & 3));
        if ( v16 == 0 )
          return 0;
        LOBYTE(v17) = checkArgMode(r: c, pt, mode: (OpArgMask)((v9 >> 2) & 3));
        if ( v17 == 0 )
          return 0;
      }
      v11 = pc;
LABEL_25:
      v15 = pt;
LABEL_26:
      v18 = luaP_opmodes[op];
      v19 = reg;
      if ( (v18 & 0x40) != 0 && v7 == reg )
        last = v11;
      if ( v18 >= 0 )
      {
LABEL_33:
        switch ( op )
        {
          case OP_LOADBOOL:
            if ( c == 1 && (v11 + 2 >= sizecode || (code[v11 + 1] & 0x3F) == 0x22 && (code[v11 + 1] & 0x7FC000) == 0) )
              return 0;
            goto LABEL_89;
          case OP_LOADNIL:
            if ( v7 <= v19 && v19 <= v6 )
              last = v11;
            goto LABEL_89;
          case OP_GETUPVAL:
          case OP_SETUPVAL:
            v20 = v6 < v15->nups;
            goto LABEL_88;
          case OP_GETGLOBAL:
          case OP_SETGLOBAL:
            if ( v15->k[v6].tt != 4 )
              return 0;
            goto LABEL_89;
          case OP_SELF:
            v21 = v7 + 1;
            if ( v21 >= v15->maxstacksize )
              return 0;
            if ( v19 == v21 )
              last = v11;
            goto LABEL_89;
          case OP_CONCAT:
            v20 = v6 < c;
            goto LABEL_88;
          case OP_JMP:
            goto $LN35;
          case OP_CALL:
          case OP_TAILCALL:
            if ( v6 != 0 && v6 + v7 - 1 >= v15->maxstacksize )
              return 0;
            if ( c != 0 )
            {
              if ( c != 1 && c - 1 + v7 - 1 >= v15->maxstacksize )
                return 0;
            }
            else
            {
              if ( !luaG_checkopenop(i: code[v11 + 1]) )
                return 0;
              v19 = reg;
            }
            if ( v19 >= v7 )
              last = v11;
LABEL_89:
            pc = v11 + 1;
            if ( v11 + 1 < lastpc )
              continue;
            v3 = pt;
            break;
          case OP_RETURN:
            v23 = v6 - 1;
            if ( v23 > 0 )
              goto LABEL_87;
            goto LABEL_89;
          case OP_FORLOOP:
          case OP_FORPREP:
            if ( v7 + 3 >= v15->maxstacksize )
              return 0;
$LN35:
            v22 = v6 + v11 + 1;
            if ( v19 != 255 && v11 < v22 && v22 <= lastpc )
              v11 += v6;
            goto LABEL_89;
          case OP_TFORLOOP:
            if ( c < 1 || c + v7 + 2 >= v15->maxstacksize )
              return 0;
            if ( v19 >= v7 + 2 )
              last = v11;
            goto LABEL_89;
          case OP_SETLIST:
            if ( v6 > 0 && v7 + v6 >= v15->maxstacksize )
              return 0;
            if ( c != 0 )
              goto LABEL_89;
            v20 = ++v11 < sizecode - 1;
LABEL_88:
            if ( v20 )
              goto LABEL_89;
            return 0;
          case OP_CLOSURE:
            if ( v6 >= v15->sizep )
              return 0;
            nups = v15->p[v6]->nups;
            if ( nups + v11 >= sizecode )
              return 0;
            v25 = 1;
            if ( nups >= 1 )
            {
              v26 = &code[v11 + 1];
              do
              {
                v27 = *v26 & 0x3F;
                if ( v27 != 4 && v27 != 0 )
                  return 0;
                ++v25;
                ++v26;
              }
              while ( v25 <= nups );
              v19 = reg;
            }
            if ( v19 != 255 )
              v11 += nups;
            goto LABEL_89;
          case OP_VARARG:
            is_vararg = v15->is_vararg;
            if ( (is_vararg & 2) == 0 )
              return 0;
            if ( (is_vararg & 4) != 0 )
              return 0;
            v23 = v6 - 1;
            if ( v23 == -1 && !luaG_checkopenop(i: code[v11 + 1]) )
              return 0;
LABEL_87:
            v20 = v23 + v7 - 1 < v15->maxstacksize;
            goto LABEL_88;
          default:
            goto LABEL_89;
        }
        return v3->code[last];
      }
      break;
    }
    if ( v11 + 2 < sizecode && (code[v11 + 1] & 0x3F) == 0x16 )
    {
      v19 = reg;
      goto LABEL_33;
    }
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10009600
// Name: kname
// Source: json
//------------------------------------------------------------------------------
const char *__usercall kname@<eax>(Proto *p@<ecx>, int c@<eax>)
{
  lua_TValue *k; // edx
  unsigned int v3; // eax

  if ( (c & 0x100) != 0 && (k = p->k, v3 = c & 0xFFFFFEFF, k[v3].tt == 4) )
    return (const char *)(k[v3].value.b + 24);
  else
    return "?";
}

//------------------------------------------------------------------------------
// Address: 0x10009630
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
        *name = (const char *)(v8->k[v11 >> 14].value.b + 24);
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
// Address: 0x100097B0
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
// Address: 0x10009850
// Name: _luaG_typeerror
// Source: json
//------------------------------------------------------------------------------
void __usercall __noreturn luaG_typeerror(lua_State *L@<esi>, const lua_TValue *o@<ecx>, const char *op)
{
  CallInfo *ci; // edx
  const char *v4; // ebx
  const lua_TValue *base; // eax
  lua_TValue *top; // edi
  const char *v7; // eax
  const char *name; // [esp+8h] [ebp-4h] BYREF

  ci = L->ci;
  v4 = luaT_typenames[o->tt];
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
      luaG_runerror(L, fmt: "attempt to %s %s '%s' (a %s value)", op, v7, name, v4);
  }
LABEL_4:
  luaG_runerror(L, fmt: "attempt to %s a %s value", op, v4);
}

//------------------------------------------------------------------------------
// Address: 0x100098D0
// Name: _luaG_ordererror
// Source: json
//------------------------------------------------------------------------------
void __usercall __noreturn luaG_ordererror(lua_State *L@<esi>, const lua_TValue *p1@<eax>, const lua_TValue *p2@<edx>)
{
  const char *v3; // eax
  const char *v4; // ecx

  v3 = luaT_typenames[p1->tt];
  v4 = luaT_typenames[p2->tt];
  if ( v3[2] == v4[2] )
    luaG_runerror(L, fmt: "attempt to compare two %s values", v3);
  luaG_runerror(L, fmt: "attempt to compare %s with %s", v3, v4);
}

//------------------------------------------------------------------------------
// Address: 0x10009920
// Name: addinfo
// Source: json
//------------------------------------------------------------------------------
void __usercall addinfo(lua_State *L@<edi>, const char *msg)
{
  CallInfo *ci; // edx
  int *func; // ecx
  const unsigned int *savedpc; // eax
  int v5; // edx
  int v6; // eax
  int v7; // esi
  int v8; // edx
  int v9; // ecx
  int v10; // eax
  char buff[60]; // [esp+8h] [ebp-3Ch] BYREF

  ci = L->ci;
  func = (int *)ci->func;
  if ( func[2] == 6 && *(_BYTE *)(*func + 6) == 0 )
  {
    if ( func[2] == 6
      && *(_BYTE *)(*func + 6) == 0
      && (savedpc = L->savedpc,
          ci->savedpc = savedpc,
          v5 = *(_DWORD *)(*func + 16),
          (v6 = (((int)savedpc - *(_DWORD *)(v5 + 12)) >> 2) - 1) >= 0) )
    {
      v8 = *(_DWORD *)(v5 + 20);
      if ( v8 != 0 )
        v7 = *(_DWORD *)(v8 + 4 * v6);
      else
        v7 = 0;
    }
    else
    {
      v7 = -1;
    }
    if ( func[2] != 6 || *(_BYTE *)((v9 = *func) + 6) != 0 )
      v10 = 0;
    else
      v10 = *(_DWORD *)(v9 + 16);
    luaO_chunkid(out: buff, source: (const char *)(*(_DWORD *)(v10 + 32) + 24), bufflen: 0x3Cu);
    luaO_pushfstring(L, fmt: "%s:%d: %s", buff, v7, msg);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100099C0
// Name: _luaG_errormsg
// Source: json
//------------------------------------------------------------------------------
void __usercall __noreturn luaG_errormsg(lua_State *L@<eax>)
{
  int errfunc; // eax
  int *v3; // edi
  lua_TValue *top; // eax
  lua_TValue *v5; // eax
  int stacksize; // eax
  int v7; // eax

  errfunc = L->errfunc;
  if ( errfunc != 0 )
  {
    v3 = (int *)((char *)L->stack + errfunc);
    if ( v3[2] != 6 )
      luaD_throw(L, errcode: 5);
    top = L->top;
    top->value.b = top[-1].value.b;
    *(&top->value.b + 1) = *(&top[-1].value.b + 1);
    top->tt = top[-1].tt;
    v5 = L->top;
    v5[-1].value.b = *v3;
    *(&v5[-1].value.b + 1) = v3[1];
    v5[-1].tt = v3[2];
    if ( (char *)L->stack_last - (char *)L->top <= 16 )
    {
      stacksize = L->stacksize;
      if ( stacksize < 1 )
        v7 = stacksize + 1;
      else
        v7 = 2 * stacksize;
      luaD_reallocstack(L, newsize: v7);
    }
    luaD_call(L, func: ++L->top - 2, nResults: 1);
  }
  luaD_throw(L, errcode: 2);
}

//------------------------------------------------------------------------------
// Address: 0x10009A60
// Name: _luaG_runerror
// Source: json
//------------------------------------------------------------------------------
void __noreturn luaG_runerror(lua_State *L, const char *fmt, ...)
{
  const char *v2; // eax
  va_list argp; // [esp+18h] [ebp+10h] BYREF

  va_start(argp, fmt);
  v2 = luaO_pushvfstring(L, fmt, argp);
  addinfo(L, msg: v2);
  luaG_errormsg(L);
}
