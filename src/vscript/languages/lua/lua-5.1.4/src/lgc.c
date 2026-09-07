// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vscript/languages/lua/lua-5.1.4/src/lgc.c
// Functions: 24
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1000B650
// Name: reallymarkobject
// Source: json
//------------------------------------------------------------------------------
void __cdecl reallymarkobject(global_State *g, GCObject *o)
{
  GCObject *keyhash; // esi
  int tt; // eax
  unsigned int v4; // eax
  GCObject *gclist; // eax
  unsigned int hash; // eax
  GCObject *v7; // eax

  keyhash = o;
  tt = o->gch.tt;
  o->gch.marked &= 0xFCu;
  v4 = tt - 4;
  while ( 2 )
  {
    switch ( v4 )
    {
      case 1u:
        keyhash->cl.c.upvalue[0].value.b = (int)g->gray;
        g->gray = keyhash;
        break;
      case 2u:
        keyhash->ts.tsv.hash = (unsigned int)g->gray;
        g->gray = keyhash;
        break;
      case 3u:
        gclist = keyhash->cl.c.gclist;
        keyhash->gch.marked |= 4u;
        if ( gclist != nullptr && (gclist->gch.marked & 3) != 0 )
          reallymarkobject(g, o: gclist);
        keyhash = (GCObject *)keyhash->ts.tsv.keyhash;
        if ( (keyhash->gch.marked & 3) != 0 )
        {
          keyhash->gch.marked &= 0xFCu;
          v4 = keyhash->gch.tt - 4;
          if ( v4 <= 6 )
            continue;
        }
        break;
      case 4u:
        keyhash->th.gclist = g->gray;
        g->gray = keyhash;
        break;
      case 5u:
        keyhash->p.gclist = g->gray;
        g->gray = keyhash;
        break;
      case 6u:
        hash = keyhash->ts.tsv.hash;
        if ( *(int *)(hash + 8) >= 4 )
        {
          v7 = *(GCObject **)hash;
          if ( (v7->gch.marked & 3) != 0 )
            reallymarkobject(g, o: v7);
        }
        if ( keyhash->cl.c.gclist == (GCObject *)&keyhash->th.l_G )
          keyhash->gch.marked |= 4u;
        break;
      default:
        return;
    }
    break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B730
// Name: marktmu
// Source: json
//------------------------------------------------------------------------------
void __usercall marktmu(global_State *g@<edi>)
{
  GCObject *tmudata; // esi
  int tt; // ecx
  GCObject *gclist; // ecx
  unsigned int hash; // eax
  GCObject *v5; // eax

  tmudata = g->tmudata;
  if ( tmudata != nullptr )
  {
    do
    {
      tmudata = (GCObject *)tmudata->ts.dummy.l;
      tt = tmudata->gch.tt;
      tmudata->gch.marked &= 0xF8u;
      switch ( tt )
      {
        case 5:
          tmudata->cl.c.upvalue[0].value.b = (int)g->gray;
          goto LABEL_17;
        case 6:
          tmudata->ts.tsv.hash = (unsigned int)g->gray;
          goto LABEL_17;
        case 7:
          gclist = tmudata->cl.c.gclist;
          tmudata->gch.marked |= 4u;
          if ( gclist != nullptr && (gclist->gch.marked & 3) != 0 )
            reallymarkobject(g, o: gclist);
          if ( (*(_BYTE *)(tmudata->ts.tsv.keyhash + 5) & 3) != 0 )
            reallymarkobject(g, o: (GCObject *)tmudata->ts.tsv.keyhash);
          break;
        case 8:
          tmudata->th.gclist = g->gray;
          goto LABEL_17;
        case 9:
          tmudata->p.gclist = g->gray;
LABEL_17:
          g->gray = tmudata;
          break;
        case 10:
          hash = tmudata->ts.tsv.hash;
          if ( *(int *)(hash + 8) >= 4 )
          {
            v5 = *(GCObject **)hash;
            if ( (v5->gch.marked & 3) != 0 )
              reallymarkobject(g, o: v5);
          }
          if ( tmudata->cl.c.gclist == (GCObject *)&tmudata->th.l_G )
            tmudata->gch.marked |= 4u;
          break;
        default:
          break;
      }
    }
    while ( tmudata != g->tmudata );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B810
// Name: _luaC_separateudata
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl luaC_separateudata(lua_State *L, int all)
{
  lua_State *mainthread; // ebx
  GCObject *next; // esi
  unsigned __int8 marked; // al
  Table *metatable; // edi
  unsigned int len; // eax
  int v7; // edx
  int *tmudata; // eax
  global_State *g; // [esp+8h] [ebp-8h]
  unsigned int deadmem; // [esp+Ch] [ebp-4h]

  mainthread = L->l_G->mainthread;
  next = mainthread->next;
  g = L->l_G;
  deadmem = 0;
  if ( mainthread->next != nullptr )
  {
    while ( 1 )
    {
      marked = next->gch.marked;
      if ( ((marked & 3) != 0 || all != 0) && (marked & 8) == 0 )
      {
        metatable = next->u.uv.metatable;
        if ( metatable != nullptr && (metatable->flags & 4) == 0 )
        {
          if ( luaH_getstr(t: metatable, key: L->l_G->tmname[2])->tt != 0 )
          {
            len = next->ts.tsv.len;
            next->gch.marked |= 8u;
            v7 = deadmem + len + 24;
            mainthread->next = (GCObject *)next->ts.dummy.l;
            tmudata = (int *)g->tmudata;
            deadmem = v7;
            if ( tmudata != nullptr )
            {
              next->ts.dummy.l = *tmudata;
              g->tmudata->gch.next = next;
            }
            else
            {
              next->ts.dummy.l = (int)next;
            }
            g->tmudata = next;
            goto LABEL_15;
          }
          metatable->flags |= 4u;
        }
        next->gch.marked |= 8u;
        mainthread = (lua_State *)next;
      }
      else
      {
        mainthread = (lua_State *)next;
      }
LABEL_15:
      next = mainthread->next;
      if ( mainthread->next == nullptr )
        return deadmem;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000B8D0
// Name: traversetable
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl traversetable(global_State *g, GCObject *h)
{
  GCObject *gclist; // eax
  global_State *v4; // edi
  Table *metatable; // esi
  int *v6; // esi
  const lua_TValue *v7; // eax
  int v8; // eax
  int v9; // eax
  BOOL v10; // eax
  int sizearray; // edi
  int v13; // esi
  lua_TValue *array; // eax
  GCObject *gc; // eax
  int v16; // edi
  int v17; // ecx
  GCObject **v18; // esi
  GCObject *v19; // esi
  int v20; // [esp+Ch] [ebp-8h]
  int weakvalue; // [esp+10h] [ebp-4h]
  BOOL weakkey; // [esp+20h] [ebp+Ch]

  gclist = h->cl.c.gclist;
  weakkey = false;
  weakvalue = 0;
  if ( gclist != nullptr && (gclist->gch.marked & 3) != 0 )
  {
    v4 = g;
    reallymarkobject(g, o: gclist);
  }
  else
  {
    v4 = g;
  }
  metatable = h->u.uv.metatable;
  if ( metatable != nullptr )
  {
    if ( (metatable->flags & 8) != 0 )
    {
      v6 = nullptr;
    }
    else
    {
      v7 = luaH_getstr(t: metatable, key: v4->tmname[3]);
      if ( v7->tt != 0 )
      {
        v6 = (int *)v7;
      }
      else
      {
        metatable->flags |= 8u;
        v6 = nullptr;
      }
    }
    if ( v6 != nullptr && v6[2] == 4 )
    {
      strchr(string: (unsigned __int8 *)(*v6 + 24), chr: 0x6Bu);
      weakkey = v8 != 0;
      strchr(string: (unsigned __int8 *)(*v6 + 24), chr: 0x76u);
      v10 = v9 != 0;
      weakvalue = v10;
      if ( weakkey || v10 )
      {
        h->gch.marked = h->gch.marked & 0xE7 | (8 * (weakkey | (2 * v10)));
        h->cl.c.upvalue[0].value.b = (int)v4->weak;
        v4->weak = h;
        if ( weakkey )
        {
          if ( v10 )
            return true;
        }
        else if ( v10 )
        {
          goto LABEL_25;
        }
      }
    }
  }
  sizearray = h->h.sizearray;
  if ( sizearray != 0 )
  {
    v13 = sizearray;
    do
    {
      array = h->h.array;
      --v13;
      --sizearray;
      if ( array[v13].tt >= 4 )
      {
        gc = array[v13].value.gc;
        if ( (gc->gch.marked & 3) != 0 )
          reallymarkobject(g, o: gc);
      }
    }
    while ( sizearray != 0 );
  }
LABEL_25:
  v16 = 1 << h->cl.c.nupvalues;
  if ( v16 != 0 )
  {
    v17 = 32 * v16;
    do
    {
      v17 -= 32;
      v18 = (GCObject **)(v17 + h->ts.tsv.len);
      --v16;
      v20 = v17;
      if ( v18[2] != nullptr )
      {
        if ( !weakkey && (int)v18[6] >= 4 && (v18[4]->gch.marked & 3) != 0 )
        {
          reallymarkobject(g, o: v18[4]);
          v17 = v20;
        }
        if ( weakvalue == 0 && (int)v18[2] >= 4 )
        {
          v19 = *v18;
          if ( (v19->gch.marked & 3) != 0 )
          {
            reallymarkobject(g, o: v19);
            v17 = v20;
          }
        }
      }
      else if ( (int)v18[6] >= 4 )
      {
        v18[6] = (GCObject *)11;
      }
    }
    while ( v16 != 0 );
  }
  return weakkey || weakvalue != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000BA90
// Name: traverseproto
// Source: json
//------------------------------------------------------------------------------
void __usercall traverseproto(Proto *f@<esi>, global_State *g)
{
  int v2; // edi
  int v3; // ebx
  lua_TValue *k; // eax
  GCObject *gc; // eax
  int i; // eax
  TString **upvalues; // edx
  int j; // edi
  GCObject **v9; // eax
  GCObject *v10; // eax
  int v11; // edi
  int v12; // eax
  LocVar *locvars; // ecx

  if ( f->source != nullptr )
    f->source->tsv.marked &= 0xFCu;
  v2 = 0;
  if ( f->sizek > 0 )
  {
    v3 = 0;
    do
    {
      k = f->k;
      if ( k[v3].tt >= 4 )
      {
        gc = k[v3].value.gc;
        if ( (gc->gch.marked & 3) != 0 )
          reallymarkobject(g, o: gc);
      }
      ++v2;
      ++v3;
    }
    while ( v2 < f->sizek );
  }
  for ( i = 0; i < f->sizeupvalues; ++i )
  {
    upvalues = f->upvalues;
    if ( upvalues[i] != nullptr )
      upvalues[i]->tsv.marked &= 0xFCu;
  }
  for ( j = 0; j < f->sizep; ++j )
  {
    v9 = (GCObject **)&f->p[j];
    if ( *v9 != nullptr )
    {
      v10 = *v9;
      if ( (v10->gch.marked & 3) != 0 )
        reallymarkobject(g, o: v10);
    }
  }
  v11 = 0;
  if ( f->sizelocvars > 0 )
  {
    v12 = 0;
    do
    {
      locvars = f->locvars;
      if ( locvars[v12].varname != nullptr )
        locvars[v12].varname->tsv.marked &= 0xFCu;
      ++v11;
      ++v12;
    }
    while ( v11 < f->sizelocvars );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000BB60
// Name: traverseclosure
// Source: json
//------------------------------------------------------------------------------
void __cdecl traverseclosure(global_State *g, Closure *cl)
{
  int v2; // edi
  lua_TValue *upvalue; // esi
  int v4; // edi
  UpVal **upvals; // esi
  GCObject *v6; // esi
  int tt; // ecx
  GCObject *gclist; // ecx
  GCObject *keyhash; // esi
  unsigned int hash; // eax
  GCObject *v11; // eax
  UpVal **v12; // [esp+Ch] [ebp-4h]

  if ( (cl->c.env->marked & 3) != 0 )
    reallymarkobject(g, o: (GCObject *)cl->c.env);
  if ( cl->c.isC != 0 )
  {
    v2 = 0;
    if ( cl->c.nupvalues != 0 )
    {
      upvalue = cl->c.upvalue;
      do
      {
        if ( upvalue->tt >= 4 && (*(_BYTE *)(upvalue->value.b + 5) & 3) != 0 )
          reallymarkobject(g, o: upvalue->value.gc);
        ++v2;
        ++upvalue;
      }
      while ( v2 < cl->c.nupvalues );
    }
  }
  else
  {
    if ( (*((_BYTE *)cl->c.f + 5) & 3) != 0 )
      reallymarkobject(g, o: (GCObject *)cl->c.f);
    v4 = 0;
    if ( cl->c.nupvalues != 0 )
    {
      upvals = cl->l.upvals;
      v12 = cl->l.upvals;
      do
      {
        v6 = (GCObject *)*upvals;
        if ( (v6->gch.marked & 3) != 0 )
        {
          tt = v6->gch.tt;
          v6->gch.marked &= 0xFCu;
          switch ( tt )
          {
            case 5:
              v6->cl.c.upvalue[0].value.b = (int)g->gray;
              goto LABEL_31;
            case 6:
              v6->ts.tsv.hash = (unsigned int)g->gray;
              goto LABEL_31;
            case 7:
              gclist = v6->cl.c.gclist;
              v6->gch.marked |= 4u;
              if ( gclist != nullptr && (gclist->gch.marked & 3) != 0 )
                reallymarkobject(g, o: gclist);
              keyhash = (GCObject *)v6->ts.tsv.keyhash;
              if ( (keyhash->gch.marked & 3) != 0 )
                reallymarkobject(g, o: keyhash);
              break;
            case 8:
              v6->th.gclist = g->gray;
              goto LABEL_31;
            case 9:
              v6->p.gclist = g->gray;
LABEL_31:
              g->gray = v6;
              break;
            case 10:
              hash = v6->ts.tsv.hash;
              if ( *(int *)(hash + 8) >= 4 )
              {
                v11 = *(GCObject **)hash;
                if ( (v11->gch.marked & 3) != 0 )
                  reallymarkobject(g, o: v11);
              }
              if ( v6->cl.c.gclist == (GCObject *)&v6->th.l_G )
                v6->gch.marked |= 4u;
              break;
            default:
              break;
          }
        }
        ++v4;
        upvals = ++v12;
      }
      while ( v4 < cl->c.nupvalues );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000BCE0
// Name: traversestack
// Source: json
//------------------------------------------------------------------------------
void __usercall traversestack(lua_State *l@<esi>, global_State *g)
{
  CallInfo *base_ci; // eax
  lua_TValue *i; // ebx
  lua_TValue *j; // edi
  int size_ci; // edi
  signed int v6; // ebx
  int stacksize; // ecx
  global_State *l_G; // ebx
  int v9; // edi
  lua_TValue *v10; // eax
  int v11; // [esp+Ch] [ebp-Ch]
  int v12; // [esp+10h] [ebp-8h]
  lua_TValue *oldstack; // [esp+14h] [ebp-4h]

  if ( l->l_gt.tt >= 4 && (*(_BYTE *)(l->l_gt.value.b + 5) & 3) != 0 )
    reallymarkobject(g, o: l->l_gt.value.gc);
  base_ci = l->base_ci;
  for ( i = l->top; base_ci <= l->ci; ++base_ci )
  {
    if ( i < base_ci->top )
      i = base_ci->top;
  }
  for ( j = l->stack; j < l->top; ++j )
  {
    if ( j->tt >= 4 && (*(_BYTE *)(j->value.b + 5) & 3) != 0 )
      reallymarkobject(g, o: j->value.gc);
  }
  for ( ; j <= i; ++j )
    j->tt = 0;
  size_ci = l->size_ci;
  v6 = i - l->stack;
  if ( size_ci <= 20000 )
  {
    if ( 4 * (l->ci - l->base_ci) < size_ci && size_ci > 16 )
      luaD_reallocCI(L: l, newsize: size_ci / 2);
    stacksize = l->stacksize;
    if ( 4 * v6 < stacksize && stacksize > 90 )
    {
      v12 = stacksize / 2;
      oldstack = l->stack;
      if ( (unsigned int)(stacksize / 2 + 7) > 0xFFFFFFF )
        luaG_runerror(L: l, fmt: "memory allocation error: block too big");
      l_G = l->l_G;
      v9 = 16 * (stacksize / 2 + 6);
      v11 = 16 * stacksize;
      v10 = (lua_TValue *)l_G->frealloc(a1: l_G->ud, a2: l->stack, a3: 16 * stacksize, a4: v9);
      if ( v10 == nullptr && v9 != 0 )
        luaD_throw(L: l, errcode: 4);
      l_G->totalbytes += v9 - v11;
      l->stacksize = v12 + 6;
      l->stack = v10;
      l->stack_last = &v10[v12];
      correctstack(L: l, oldstack);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000BE60
// Name: propagatemark
// Source: json
//------------------------------------------------------------------------------
int __usercall propagatemark@<eax>(global_State *g@<eax>)
{
  GCObject *gray; // esi
  int tt; // ecx
  int result; // eax
  int nupvalues; // eax
  GCObject *grayagain; // ecx

  gray = g->gray;
  tt = gray->gch.tt;
  gray->gch.marked |= 4u;
  switch ( tt )
  {
    case 5:
      g->gray = gray->cl.c.upvalue[0].value.gc;
      if ( traversetable(g, h: gray) )
        gray->gch.marked &= ~4u;
      result = 16 * (gray->h.sizearray + 2 * (1 << gray->cl.c.nupvalues) + 2);
      break;
    case 6:
      g->gray = gray->cl.c.gclist;
      traverseclosure(g, cl: (Closure *)gray);
      nupvalues = gray->cl.c.nupvalues;
      if ( gray->ts.tsv.reserved != 0 )
        result = 16 * nupvalues + 24;
      else
        result = 4 * nupvalues + 20;
      break;
    case 8:
      grayagain = g->grayagain;
      g->gray = gray->th.gclist;
      gray->th.gclist = grayagain;
      g->grayagain = gray;
      gray->gch.marked &= ~4u;
      traversestack(l: (lua_State *)gray, g);
      result = 16 * gray->p.sizecode + 8 * (3 * gray->p.sizelineinfo + 15);
      break;
    case 9:
      g->gray = gray->p.gclist;
      traverseproto(f: (Proto *)gray, g);
      result = 4
             * (gray->p.sizeupvalues
              + gray->p.sizecode
              + gray->p.sizelineinfo
              + gray->p.sizep
              + 3 * gray->p.sizelocvars
              + 4 * gray->p.sizek)
             + 76;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000BF50
// Name: propagateall
// Source: json
//------------------------------------------------------------------------------
unsigned int __usercall propagateall@<eax>(global_State *g@<edi>)
{
  unsigned int result; // eax
  GCObject *gray; // esi
  int tt; // eax
  int v4; // eax
  int nupvalues; // eax
  GCObject *grayagain; // eax
  unsigned int m; // [esp+Ch] [ebp-4h]

  result = 0;
  m = 0;
  if ( g->gray != nullptr )
  {
    do
    {
      gray = g->gray;
      tt = gray->gch.tt;
      gray->gch.marked |= 4u;
      switch ( tt )
      {
        case 5:
          g->gray = gray->cl.c.upvalue[0].value.gc;
          if ( traversetable(g, h: gray) )
            gray->gch.marked &= ~4u;
          v4 = 16 * (gray->h.sizearray + 2 * (1 << gray->cl.c.nupvalues) + 2);
          break;
        case 6:
          g->gray = gray->cl.c.gclist;
          traverseclosure(g, cl: (Closure *)gray);
          nupvalues = gray->cl.c.nupvalues;
          if ( gray->ts.tsv.reserved != 0 )
            v4 = 16 * nupvalues + 24;
          else
            v4 = 4 * nupvalues + 20;
          break;
        case 8:
          grayagain = g->grayagain;
          g->gray = gray->th.gclist;
          gray->th.gclist = grayagain;
          g->grayagain = gray;
          gray->gch.marked &= ~4u;
          traversestack(l: (lua_State *)gray, g);
          v4 = 16 * gray->p.sizecode + 8 * (3 * gray->p.sizelineinfo + 15);
          break;
        case 9:
          g->gray = gray->p.gclist;
          traverseproto(f: (Proto *)gray, g);
          v4 = 4
             * (gray->p.sizeupvalues
              + gray->p.sizecode
              + gray->p.sizelineinfo
              + gray->p.sizep
              + 3 * gray->p.sizelocvars
              + 4 * gray->p.sizek)
             + 76;
          break;
        default:
          v4 = 0;
          break;
      }
      m += v4;
    }
    while ( g->gray != nullptr );
    return m;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000C080
// Name: cleartable
// Source: json
//------------------------------------------------------------------------------
void __cdecl cleartable(GCObject *l)
{
  GCObject *gc; // ebx
  int sizearray; // edi
  int v3; // esi
  unsigned int keyhash; // eax
  int v5; // ecx
  _DWORD *v6; // eax
  char v7; // dl
  int v8; // esi
  int v9; // edi
  _DWORD *v10; // eax
  int v11; // ecx
  bool v12; // zf
  int v13; // ecx
  int v14; // ecx
  char v15; // dl
  bool v16; // cc

  gc = l;
  if ( l != nullptr )
  {
    while ( 1 )
    {
      sizearray = gc->h.sizearray;
      if ( (gc->gch.marked & 0x10) != 0 && sizearray != 0 )
      {
        v3 = 16 * sizearray;
        do
        {
          keyhash = gc->ts.tsv.keyhash;
          v3 -= 16;
          v5 = *(_DWORD *)(keyhash + v3 + 8);
          v6 = (_DWORD *)(v3 + keyhash);
          --sizearray;
          if ( v5 >= 4 )
          {
            if ( v5 == 4 )
            {
              *(_BYTE *)(*v6 + 5) &= 0xFCu;
            }
            else
            {
              v7 = *(_BYTE *)(*v6 + 5);
              if ( (v7 & 3) != 0 || v5 == 7 && (v7 & 8) != 0 )
                v6[2] = 0;
            }
          }
        }
        while ( sizearray != 0 );
      }
      v8 = 1 << gc->cl.c.nupvalues;
      if ( v8 != 0 )
        break;
LABEL_29:
      gc = gc->cl.c.upvalue[0].value.gc;
      if ( gc == nullptr )
        return;
    }
    v9 = 32 * v8;
    while ( 1 )
    {
      v9 -= 32;
      v10 = (_DWORD *)(v9 + gc->ts.tsv.len);
      --v8;
      if ( v10[2] != 0 )
      {
        v11 = v10[6];
        v12 = v11 == 4;
        if ( v11 >= 4 )
        {
          v13 = v10[4];
          if ( v12 )
          {
            *(_BYTE *)(v13 + 5) &= 0xFCu;
          }
          else if ( (*(_BYTE *)(v13 + 5) & 3) != 0 )
          {
            goto LABEL_26;
          }
        }
        v14 = v10[2];
        if ( v14 >= 4 )
        {
          if ( v14 != 4 )
          {
            v15 = *(_BYTE *)(*v10 + 5);
            if ( (v15 & 3) == 0 && (v14 != 7 || (v15 & 8) == 0) )
              goto LABEL_28;
LABEL_26:
            v16 = v10[6] < 4;
            v10[2] = 0;
            if ( !v16 )
              v10[6] = 11;
            goto LABEL_28;
          }
          *(_BYTE *)(*v10 + 5) &= 0xFCu;
        }
      }
LABEL_28:
      if ( v8 == 0 )
        goto LABEL_29;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C170
// Name: freeobj
// Source: json
//------------------------------------------------------------------------------
void __usercall freeobj(lua_State *L@<ecx>, GCObject *o@<eax>)
{
  int nupvalues; // edi
  int v3; // edi
  global_State *v4; // esi
  global_State *l_G; // edi
  unsigned int v6; // esi
  global_State *v7; // edi
  unsigned int v8; // esi

  switch ( o->gch.tt )
  {
    case 4u:
      --L->l_G->strt.nuse;
      l_G = L->l_G;
      v6 = o->ts.tsv.len + 25;
      l_G->frealloc(a1: l_G->ud, a2: o, a3: v6, a4: 0);
      l_G->totalbytes -= v6;
      break;
    case 5u:
      luaH_free(L, t: (Table *)o);
      break;
    case 6u:
      nupvalues = o->cl.c.nupvalues;
      if ( o->ts.tsv.reserved != 0 )
        v3 = 16 * nupvalues + 24;
      else
        v3 = 4 * nupvalues + 20;
      v4 = L->l_G;
      v4->frealloc(a1: v4->ud, a2: o, a3: v3, a4: 0);
      v4->totalbytes -= v3;
      break;
    case 7u:
      v7 = L->l_G;
      v8 = o->ts.tsv.len + 24;
      v7->frealloc(a1: v7->ud, a2: o, a3: v8, a4: 0);
      v7->totalbytes -= v8;
      break;
    case 8u:
      luaE_freethread(L, L1: (lua_State *)o);
      break;
    case 9u:
      luaF_freeproto(L, f: (Proto *)o);
      break;
    case 0xAu:
      luaF_freeupval(uv: (UpVal *)o, L);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C270
// Name: sweeplist
// Source: json
//------------------------------------------------------------------------------
GCObject *__cdecl sweeplist(lua_State *L, GCObject *p, unsigned int count)
{
  GCObject *result; // eax
  lua_State *v4; // ebx
  global_State *l_G; // ecx
  GCObject *v6; // esi
  int v7; // edi
  unsigned int v8; // edx
  unsigned __int8 marked; // al
  int nupvalues; // eax
  int v11; // eax
  global_State *v12; // edi
  int *p_b; // eax
  global_State *v14; // edi
  global_State *v15; // ebx
  int v16; // edi
  int v17; // [esp+Ch] [ebp-Ch]
  global_State *g; // [esp+10h] [ebp-8h]
  int deadmask; // [esp+14h] [ebp-4h]

  result = p;
  v4 = L;
  l_G = L->l_G;
  v6 = (GCObject *)p->ts.dummy.l;
  v7 = l_G->currentwhite ^ 3;
  g = l_G;
  deadmask = v7;
  if ( p->ts.dummy.l != 0 )
  {
    while ( 1 )
    {
      v8 = count--;
      if ( v8 == 0 )
        return p;
      if ( v6->gch.tt == 8 )
      {
        sweeplist(L: v4, p: &v6->th.openupval, count: 0xFFFFFFFD);
        l_G = g;
      }
      marked = v6->gch.marked;
      if ( ((marked ^ 3) & v7) != 0 )
      {
        v6->gch.marked = l_G->currentwhite & 3 | marked & 0xF8;
        p = v6;
      }
      else
      {
        p->ts.dummy.l = v6->ts.dummy.l;
        if ( v6 == l_G->rootgc )
          l_G->rootgc = (GCObject *)v6->ts.dummy.l;
        switch ( v6->gch.tt )
        {
          case 4u:
            --v4->l_G->strt.nuse;
            v15 = v4->l_G;
            v16 = v6->ts.tsv.len + 25;
            v15->frealloc(a1: v15->ud, a2: v6, a3: v16, a4: 0);
            goto LABEL_24;
          case 5u:
            luaH_free(L: v4, t: (Table *)v6);
            break;
          case 6u:
            nupvalues = v6->cl.c.nupvalues;
            if ( v6->ts.tsv.reserved != 0 )
            {
              v11 = 16 * nupvalues + 24;
              v17 = v11;
            }
            else
            {
              v17 = 4 * nupvalues + 20;
              v11 = v17;
            }
            v12 = v4->l_G;
            v12->frealloc(a1: v12->ud, a2: v6, a3: v11, a4: 0);
            v12->totalbytes -= v17;
            break;
          case 7u:
            v15 = v4->l_G;
            v16 = v6->ts.tsv.len + 24;
            v15->frealloc(a1: v15->ud, a2: v6, a3: v16, a4: 0);
LABEL_24:
            v15->totalbytes -= v16;
            v4 = L;
            break;
          case 8u:
            luaE_freethread(L: v4, L1: (lua_State *)v6);
            break;
          case 9u:
            luaF_freeproto(L: v4, f: (Proto *)v6);
            break;
          case 0xAu:
            p_b = &v6->uv.u.value.value.b;
            if ( v6->cl.c.gclist != (GCObject *)&v6->th.l_G )
            {
              v6->cl.l.upvals[0]->u.value.value.b = *p_b;
              *(_DWORD *)(*p_b + 20) = v6->cl.l.upvals[0];
            }
            v14 = v4->l_G;
            v14->frealloc(a1: v14->ud, a2: v6, a3: 32u, a4: 0);
            v14->totalbytes -= 32;
            break;
          default:
            break;
        }
      }
      v6 = (GCObject *)p->ts.dummy.l;
      if ( p->ts.dummy.l == 0 )
        return p;
      v7 = deadmask;
      l_G = g;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000C430
// Name: checkSizes
// Source: json
//------------------------------------------------------------------------------
void __cdecl checkSizes(lua_State *L)
{
  global_State *l_G; // ebx
  int size; // ecx
  unsigned int buffsize; // ecx
  unsigned int v4; // edi
  global_State *v5; // esi
  int v6; // eax
  unsigned int v7; // [esp+Ch] [ebp-4h]

  l_G = L->l_G;
  size = l_G->strt.size;
  if ( l_G->strt.nuse < size / 4 && size > 64 )
    luaS_resize(L, newsize: size / 2);
  buffsize = l_G->buff.buffsize;
  v7 = buffsize;
  if ( buffsize > 0x40 )
  {
    v4 = buffsize >> 1;
    if ( (buffsize >> 1) + 1 > 0xFFFFFFFD )
      luaG_runerror(L, fmt: "memory allocation error: block too big");
    v5 = L->l_G;
    v6 = (int)v5->frealloc(a1: v5->ud, a2: l_G->buff.buffer, a3: buffsize, a4: buffsize >> 1);
    if ( v6 == 0 && v4 != 0 )
      luaD_throw(L, errcode: 4);
    v5->totalbytes += v4 - v7;
    l_G->buff.buffer = (char *)v6;
    l_G->buff.buffsize = v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C4E0
// Name: GCTM
// Source: json
//------------------------------------------------------------------------------
void __usercall GCTM(lua_State *L@<esi>)
{
  global_State *l_G; // edi
  int *tmudata; // eax
  GCObject *v3; // ebx
  Table *metatable; // eax
  lua_TValue *v5; // ecx
  const lua_TValue *v6; // eax
  unsigned __int8 allowhook; // dl
  unsigned int GCthreshold; // eax
  lua_TValue *top; // eax
  unsigned int oldt; // [esp+8h] [ebp-8h]
  unsigned int oldta; // [esp+8h] [ebp-8h]
  unsigned __int8 oldah; // [esp+Fh] [ebp-1h]

  l_G = L->l_G;
  tmudata = (int *)l_G->tmudata;
  v3 = (GCObject *)*tmudata;
  if ( (int *)*tmudata == tmudata )
    l_G->tmudata = nullptr;
  else
    *tmudata = v3->ts.dummy.l;
  v3->ts.dummy.l = (int)l_G->mainthread->next;
  l_G->mainthread->next = v3;
  metatable = v3->u.uv.metatable;
  v3->gch.marked = v3->gch.marked & 0xF8 | l_G->currentwhite & 3;
  oldt = (unsigned int)metatable;
  if ( metatable != nullptr )
  {
    if ( (metatable->flags & 4) != 0 )
    {
      v5 = nullptr;
    }
    else
    {
      v6 = luaH_getstr(t: metatable, key: L->l_G->tmname[2]);
      if ( v6->tt != 0 )
      {
        v5 = (lua_TValue *)v6;
      }
      else
      {
        *(_BYTE *)(oldt + 6) |= 4u;
        v5 = nullptr;
      }
    }
    if ( v5 != nullptr )
    {
      allowhook = L->allowhook;
      GCthreshold = l_G->GCthreshold;
      L->allowhook = 0;
      oldah = allowhook;
      l_G->GCthreshold = 2 * l_G->totalbytes;
      oldta = GCthreshold;
      *L->top = *v5;
      top = L->top;
      top[1].value.b = (int)v3;
      top[1].tt = 7;
      L->top += 2;
      luaD_call(L, func: L->top - 2, nResults: 0);
      L->allowhook = oldah;
      l_G->GCthreshold = oldta;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C5D0
// Name: _luaC_callGCTM
// Source: json
//------------------------------------------------------------------------------
void __usercall luaC_callGCTM(lua_State *L@<esi>)
{
  global_State *l_G; // edi
  int *tmudata; // eax
  GCObject *v3; // ebx
  Table *metatable; // eax
  lua_TValue *v5; // ecx
  const lua_TValue *v6; // eax
  unsigned int GCthreshold; // eax
  unsigned __int8 allowhook; // dl
  lua_TValue *top; // eax
  lua_TValue *v10; // eax
  lua_TValue *v11; // ebx
  unsigned __int16 nCcalls; // ax
  unsigned __int8 v13; // [esp+Bh] [ebp-5h]
  Table *v14; // [esp+Ch] [ebp-4h]
  unsigned int v15; // [esp+Ch] [ebp-4h]

  while ( L->l_G->tmudata != nullptr )
  {
    l_G = L->l_G;
    tmudata = (int *)l_G->tmudata;
    v3 = (GCObject *)*tmudata;
    if ( (int *)*tmudata == tmudata )
      l_G->tmudata = nullptr;
    else
      *tmudata = v3->ts.dummy.l;
    v3->ts.dummy.l = (int)l_G->mainthread->next;
    l_G->mainthread->next = v3;
    metatable = v3->u.uv.metatable;
    v3->gch.marked = v3->gch.marked & 0xF8 | l_G->currentwhite & 3;
    v14 = metatable;
    if ( metatable != nullptr )
    {
      if ( (metatable->flags & 4) != 0 )
      {
        v5 = nullptr;
      }
      else
      {
        v6 = luaH_getstr(t: metatable, key: L->l_G->tmname[2]);
        if ( v6->tt != 0 )
        {
          v5 = (lua_TValue *)v6;
        }
        else
        {
          v14->flags |= 4u;
          v5 = nullptr;
        }
      }
      if ( v5 != nullptr )
      {
        GCthreshold = l_G->GCthreshold;
        allowhook = L->allowhook;
        L->allowhook = 0;
        v13 = allowhook;
        l_G->GCthreshold = 2 * l_G->totalbytes;
        v15 = GCthreshold;
        *L->top = *v5;
        top = L->top;
        top[1].value.b = (int)v3;
        top[1].tt = 7;
        L->top += 2;
        v10 = L->top;
        ++L->nCcalls;
        v11 = v10 - 2;
        nCcalls = L->nCcalls;
        if ( nCcalls >= 0xC8u )
        {
          if ( nCcalls == 200 )
            luaG_runerror(L, fmt: "C stack overflow");
          if ( nCcalls >= 0xE1u )
            luaD_throw(L, errcode: 5);
        }
        if ( luaD_precall(L, func: v11, nresults: 0) == 0 )
          luaV_execute(L, nexeccalls: 1);
        --L->nCcalls;
        if ( L->l_G->totalbytes >= L->l_G->GCthreshold )
          luaC_step(L);
        L->allowhook = v13;
        l_G->GCthreshold = v15;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C740
// Name: _luaC_freeall
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaC_freeall(lua_State *L)
{
  lua_State *v1; // ebx
  global_State *v2; // esi
  int v3; // ecx
  GCObject **hash; // edx
  global_State *l_G; // ebx
  GCObject *v6; // esi
  GCObject **p_next; // edi
  int v8; // eax
  unsigned __int8 marked; // al
  int i; // [esp+10h] [ebp-10h]
  global_State *g; // [esp+14h] [ebp-Ch]
  int v12; // [esp+18h] [ebp-8h]
  int v13; // [esp+1Ch] [ebp-4h]

  v1 = L;
  g = L->l_G;
  v2 = g;
  g->currentwhite = 67;
  sweeplist(L, p: (GCObject *)&g->rootgc, count: 0xFFFFFFFD);
  v3 = 0;
  i = 0;
  if ( g->strt.size > 0 )
  {
    while ( 1 )
    {
      hash = v2->strt.hash;
      l_G = v1->l_G;
      v6 = v2->strt.hash[v3];
      p_next = &hash[v3];
      v8 = -3;
      v13 = l_G->currentwhite ^ 3;
      if ( v6 != nullptr )
      {
        while ( 1 )
        {
          v12 = v8 - 1;
          if ( v8 == 0 )
            break;
          if ( v6->gch.tt == 8 )
            sweeplist(L, p: (GCObject *)&v6->th.openupval, count: 0xFFFFFFFD);
          marked = v6->gch.marked;
          if ( ((marked ^ 3) & v13) != 0 )
          {
            v6->gch.marked = marked & 0xF8 | l_G->currentwhite & 3;
            p_next = &v6->gch.next;
          }
          else
          {
            *p_next = (GCObject *)v6->ts.dummy.l;
            if ( v6 == l_G->rootgc )
              l_G->rootgc = (GCObject *)v6->ts.dummy.l;
            freeobj(L, o: v6);
          }
          v6 = *p_next;
          if ( *p_next == nullptr )
            break;
          v8 = v12;
        }
      }
      v3 = i + 1;
      i = v3;
      if ( v3 >= g->strt.size )
        break;
      v1 = L;
      v2 = g;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C830
// Name: markmt
// Source: json
//------------------------------------------------------------------------------
void __usercall markmt(global_State *g@<edi>)
{
  Table **mt; // ebx
  GCObject *v2; // esi
  int tt; // ecx
  GCObject *gclist; // ecx
  GCObject *keyhash; // esi
  unsigned int hash; // eax
  GCObject *v7; // eax
  int i; // [esp+8h] [ebp-4h]

  mt = g->mt;
  for ( i = 9; i != 0; --i )
  {
    v2 = (GCObject *)*mt;
    if ( *mt != nullptr && (v2->gch.marked & 3) != 0 )
    {
      tt = v2->gch.tt;
      v2->gch.marked &= 0xFCu;
      switch ( tt )
      {
        case 5:
          v2->cl.c.upvalue[0].value.b = (int)g->gray;
          goto LABEL_19;
        case 6:
          v2->ts.tsv.hash = (unsigned int)g->gray;
          goto LABEL_19;
        case 7:
          gclist = v2->cl.c.gclist;
          v2->gch.marked |= 4u;
          if ( gclist != nullptr && (gclist->gch.marked & 3) != 0 )
            reallymarkobject(g, o: gclist);
          keyhash = (GCObject *)v2->ts.tsv.keyhash;
          if ( (keyhash->gch.marked & 3) != 0 )
            reallymarkobject(g, o: keyhash);
          break;
        case 8:
          v2->th.gclist = g->gray;
          goto LABEL_19;
        case 9:
          v2->p.gclist = g->gray;
LABEL_19:
          g->gray = v2;
          break;
        case 10:
          hash = v2->ts.tsv.hash;
          if ( *(int *)(hash + 8) >= 4 )
          {
            v7 = *(GCObject **)hash;
            if ( (v7->gch.marked & 3) != 0 )
              reallymarkobject(g, o: v7);
          }
          if ( v2->cl.c.gclist == (GCObject *)&v2->th.l_G )
            v2->gch.marked |= 4u;
          break;
        default:
          break;
      }
    }
    ++mt;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C920
// Name: markroot
// Source: json
//------------------------------------------------------------------------------
void __usercall markroot(lua_State *L@<esi>)
{
  global_State *l_G; // edi
  lua_State *mainthread; // eax
  GCObject *gc; // eax
  global_State *v4; // eax
  GCObject *v5; // eax

  l_G = L->l_G;
  l_G->gray = nullptr;
  l_G->grayagain = nullptr;
  l_G->weak = nullptr;
  if ( (l_G->mainthread->marked & 3) != 0 )
    reallymarkobject(g: l_G, o: (GCObject *)l_G->mainthread);
  mainthread = l_G->mainthread;
  if ( mainthread->l_gt.tt >= 4 )
  {
    gc = mainthread->l_gt.value.gc;
    if ( (gc->gch.marked & 3) != 0 )
      reallymarkobject(g: l_G, o: gc);
  }
  v4 = L->l_G;
  if ( v4->l_registry.tt >= 4 )
  {
    v5 = v4->l_registry.value.gc;
    if ( (v5->gch.marked & 3) != 0 )
      reallymarkobject(g: l_G, o: v5);
  }
  markmt(g: l_G);
  l_G->gcstate = 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000C990
// Name: remarkupvals
// Source: json
//------------------------------------------------------------------------------
void __usercall remarkupvals(global_State *g@<edi>)
{
  UpVal *i; // esi
  lua_TValue *v; // eax
  GCObject *b; // eax

  for ( i = g->uvhead.u.l.next; i != &g->uvhead; i = i->u.l.next )
  {
    if ( (i->marked & 7) == 0 )
    {
      v = i->v;
      if ( v->tt >= 4 )
      {
        b = (GCObject *)v->value.b;
        if ( (b->gch.marked & 3) != 0 )
          reallymarkobject(g, o: b);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C9D0
// Name: atomic
// Source: json
//------------------------------------------------------------------------------
void __cdecl atomic(GCObject *L)
{
  global_State *l_G; // edi
  GCObject *next; // esi
  unsigned __int8 marked; // al
  Table *metatable; // ebx
  unsigned int len; // ecx
  int *tmudata; // eax
  int v7; // esi
  unsigned int totalbytes; // eax
  global_State *v9; // [esp+10h] [ebp-Ch]
  int v10; // [esp+14h] [ebp-8h]
  lua_State *mainthread; // [esp+18h] [ebp-4h]

  l_G = L->th.l_G;
  remarkupvals(g: l_G);
  propagateall(g: l_G);
  l_G->gray = l_G->weak;
  l_G->weak = nullptr;
  if ( (L->gch.marked & 3) != 0 )
    reallymarkobject(g: l_G, o: L);
  markmt(g: l_G);
  propagateall(g: l_G);
  l_G->gray = l_G->grayagain;
  l_G->grayagain = nullptr;
  propagateall(g: l_G);
  v9 = L->th.l_G;
  next = v9->mainthread->next;
  v10 = 0;
  mainthread = v9->mainthread;
  if ( next != nullptr )
  {
    do
    {
      marked = next->gch.marked;
      if ( (marked & 3) != 0 && (marked & 8) == 0 )
      {
        metatable = next->u.uv.metatable;
        if ( metatable != nullptr && (metatable->flags & 4) == 0 )
        {
          if ( luaH_getstr(t: metatable, key: *(TString **)(L->ts.tsv.len + 196))->tt != 0 )
          {
            len = next->ts.tsv.len;
            next->gch.marked |= 8u;
            mainthread->next = (GCObject *)next->ts.dummy.l;
            v10 += len + 24;
            tmudata = (int *)v9->tmudata;
            if ( tmudata != nullptr )
            {
              next->ts.dummy.l = *tmudata;
              v9->tmudata->gch.next = next;
            }
            else
            {
              next->ts.dummy.l = (int)next;
            }
            v9->tmudata = next;
            goto LABEL_16;
          }
          metatable->flags |= 4u;
        }
        next->gch.marked |= 8u;
        mainthread = (lua_State *)next;
      }
      else
      {
        mainthread = (lua_State *)next;
      }
LABEL_16:
      next = mainthread->next;
    }
    while ( mainthread->next != nullptr );
  }
  marktmu(g: l_G);
  v7 = v10 + propagateall(g: l_G);
  cleartable(l: l_G->weak);
  totalbytes = l_G->totalbytes;
  l_G->currentwhite ^= 3u;
  l_G->sweepstrgc = 0;
  l_G->sweepgc = &l_G->rootgc;
  l_G->gcstate = 2;
  l_G->estimate = totalbytes - v7;
}

//------------------------------------------------------------------------------
// Address: 0x1000CB00
// Name: singlestep
// Source: json
//------------------------------------------------------------------------------
int __usercall singlestep@<eax>(GCObject *L@<eax>)
{
  global_State *l_G; // edi
  int result; // eax
  int sweepstrgc; // eax
  unsigned int totalbytes; // ebx
  unsigned int v6; // ebx
  GCObject *v7; // eax
  unsigned int estimate; // eax
  GCObject *v9; // [esp-8h] [ebp-14h]

  l_G = L->th.l_G;
  switch ( l_G->gcstate )
  {
    case 0u:
      markroot((lua_State *)L);
      result = 0;
      break;
    case 1u:
      if ( l_G->gray != nullptr )
      {
        result = propagatemark(g: l_G);
      }
      else
      {
        atomic(L);
        result = 0;
      }
      break;
    case 2u:
      sweepstrgc = l_G->sweepstrgc;
      totalbytes = l_G->totalbytes;
      v9 = (GCObject *)&l_G->strt.hash[sweepstrgc];
      l_G->sweepstrgc = sweepstrgc + 1;
      sweeplist((lua_State *)L, p: v9, count: 0xFFFFFFFD);
      if ( l_G->sweepstrgc >= l_G->strt.size )
        l_G->gcstate = 3;
      l_G->estimate += l_G->totalbytes - totalbytes;
      result = 10;
      break;
    case 3u:
      v6 = l_G->totalbytes;
      v7 = sweeplist((lua_State *)L, p: (GCObject *)l_G->sweepgc, count: 0x28u);
      l_G->sweepgc = &v7->gch.next;
      if ( v7->ts.dummy.l == 0 )
      {
        checkSizes((lua_State *)L);
        l_G->gcstate = 4;
      }
      l_G->estimate += l_G->totalbytes - v6;
      result = 400;
      break;
    case 4u:
      if ( l_G->tmudata == nullptr )
      {
        l_G->gcstate = 0;
        l_G->gcdept = 0;
        goto LABEL_17;
      }
      GCTM((lua_State *)L);
      estimate = l_G->estimate;
      if ( estimate > 0x64 )
        l_G->estimate = estimate - 100;
      result = 100;
      break;
    default:
LABEL_17:
      result = 0;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000CC00
// Name: _luaC_step
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaC_step(GCObject *L)
{
  global_State *l_G; // ebx
  global_State *v2; // edi
  int v3; // eax
  unsigned int gcdept; // eax
  int sweepstrgc; // eax
  unsigned int v6; // ebx
  unsigned int v7; // ebx
  GCObject *v8; // eax
  unsigned int estimate; // eax
  unsigned int totalbytes; // ecx
  GCObject *v11; // [esp-8h] [ebp-20h]
  int lim; // [esp+10h] [ebp-8h]
  global_State *g; // [esp+14h] [ebp-4h]

  l_G = L->th.l_G;
  g = l_G;
  lim = 10 * l_G->gcstepmul;
  if ( lim == 0 )
    lim = 2147483646;
  l_G->gcdept += l_G->totalbytes - l_G->GCthreshold;
  while ( 2 )
  {
    v2 = L->th.l_G;
    switch ( v2->gcstate )
    {
      case 0u:
        markroot((lua_State *)L);
        goto LABEL_6;
      case 1u:
        if ( v2->gray != nullptr )
        {
          v3 = propagatemark(g: L->th.l_G);
        }
        else
        {
          atomic(L);
LABEL_6:
          v3 = 0;
        }
LABEL_7:
        lim -= v3;
        if ( l_G->gcstate == 0 )
          goto LABEL_27;
        if ( lim > 0 )
          continue;
        if ( l_G->gcstate != 0 )
        {
          gcdept = l_G->gcdept;
          if ( gcdept >= 0x400 )
          {
            totalbytes = l_G->totalbytes;
            l_G->gcdept = gcdept - 1024;
            l_G->GCthreshold = totalbytes;
          }
          else
          {
            l_G->GCthreshold = l_G->totalbytes + 1024;
          }
        }
        else
        {
LABEL_27:
          l_G->GCthreshold = l_G->gcpause * (l_G->estimate / 0x64);
        }
        return;
      case 2u:
        sweepstrgc = v2->sweepstrgc;
        v6 = v2->totalbytes;
        v11 = (GCObject *)&v2->strt.hash[sweepstrgc];
        v2->sweepstrgc = sweepstrgc + 1;
        sweeplist((lua_State *)L, p: v11, count: 0xFFFFFFFD);
        if ( v2->sweepstrgc >= v2->strt.size )
          v2->gcstate = 3;
        v2->estimate += v2->totalbytes - v6;
        l_G = g;
        v3 = 10;
        goto LABEL_7;
      case 3u:
        v7 = v2->totalbytes;
        v8 = sweeplist((lua_State *)L, p: (GCObject *)v2->sweepgc, count: 0x28u);
        v2->sweepgc = &v8->gch.next;
        if ( v8->ts.dummy.l == 0 )
        {
          checkSizes((lua_State *)L);
          v2->gcstate = 4;
        }
        v2->estimate += v2->totalbytes - v7;
        l_G = g;
        v3 = 400;
        goto LABEL_7;
      case 4u:
        v3 = 0;
        if ( v2->tmudata != nullptr )
        {
          GCTM((lua_State *)L);
          estimate = v2->estimate;
          if ( estimate > 0x64 )
            v2->estimate = estimate - 100;
          v3 = 100;
        }
        else
        {
          v2->gcstate = 0;
          v2->gcdept = 0;
        }
        goto LABEL_7;
      default:
        goto LABEL_6;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000CDA0
// Name: _luaC_fullgc
// Source: json
//------------------------------------------------------------------------------
void __usercall luaC_fullgc(GCObject *L@<eax>)
{
  global_State *l_G; // edi

  l_G = L->th.l_G;
  if ( l_G->gcstate <= 1u )
  {
    l_G->sweepstrgc = 0;
    l_G->sweepgc = &l_G->rootgc;
    l_G->gray = nullptr;
    l_G->grayagain = nullptr;
    l_G->weak = nullptr;
    l_G->gcstate = 2;
  }
  while ( l_G->gcstate != 4 )
    singlestep(L);
  markroot((lua_State *)L);
  while ( l_G->gcstate != 0 )
    singlestep(L);
  l_G->GCthreshold = l_G->gcpause * (l_G->estimate / 0x64);
}

//------------------------------------------------------------------------------
// Address: 0x1000CE10
// Name: _luaC_barrierf
// Source: json
//------------------------------------------------------------------------------
void __usercall luaC_barrierf(lua_State *L@<eax>, GCObject *o@<ecx>, GCObject *v)
{
  global_State *l_G; // eax

  l_G = L->l_G;
  if ( l_G->gcstate == 1 )
    reallymarkobject(g: l_G, o: v);
  else
    o->gch.marked = o->gch.marked & 0xF8 | l_G->currentwhite & 3;
}
