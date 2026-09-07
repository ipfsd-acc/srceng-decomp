// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: lua/lgc.c
// Functions: 26
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00478280
// Name: reallymarkobject
// Source: json
//------------------------------------------------------------------------------
void __cdecl reallymarkobject(global_State *g, GCObject *o)
{
  GCObject *len; // esi
  int tt; // eax
  unsigned int v4; // eax
  GCObject *gclist; // eax
  unsigned int hash; // eax
  GCObject *v7; // eax

  len = o;
  tt = o->gch.tt;
  o->gch.marked &= 0xFCu;
  v4 = tt - 4;
  while ( 2 )
  {
    switch ( v4 )
    {
      case 1u:
        len->cl.c.upvalue[0].value.b = (int)g->gray;
        g->gray = len;
        break;
      case 2u:
        len->ts.tsv.hash = (unsigned int)g->gray;
        g->gray = len;
        break;
      case 3u:
        gclist = len->cl.c.gclist;
        len->gch.marked |= 4u;
        if ( gclist != nullptr && (gclist->gch.marked & 3) != 0 )
          reallymarkobject(g, o: gclist);
        len = (GCObject *)len->ts.tsv.len;
        if ( (len->gch.marked & 3) != 0 )
        {
          len->gch.marked &= 0xFCu;
          v4 = len->gch.tt - 4;
          if ( v4 <= 6 )
            continue;
        }
        break;
      case 4u:
        len->th.gclist = g->gray;
        g->gray = len;
        break;
      case 5u:
        len->p.gclist = g->gray;
        g->gray = len;
        break;
      case 6u:
        hash = len->ts.tsv.hash;
        if ( *(int *)(hash + 8) >= 4 )
        {
          v7 = *(GCObject **)hash;
          if ( (v7->gch.marked & 3) != 0 )
            reallymarkobject(g, o: v7);
        }
        if ( len->cl.c.gclist == (GCObject *)&len->th.l_G )
          len->gch.marked |= 4u;
        break;
      default:
        return;
    }
    break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00478360
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
          if ( (*(_BYTE *)(tmudata->ts.tsv.len + 5) & 3) != 0 )
            reallymarkobject(g, o: (GCObject *)tmudata->ts.tsv.len);
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
// Address: 0x00478440
// Name: unsigned int luaC_separateudata(struct lua_State __near *,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl luaC_separateudata(lua_State *L, int all)
{
  global_State *l_G; // ebx
  lua_State *mainthread; // edi
  GCObject *next; // esi
  unsigned int result; // eax
  unsigned __int8 marked; // al
  Table *metatable; // eax
  unsigned int len; // edx
  int *tmudata; // eax
  unsigned int deadmem; // [esp+Ch] [ebp-4h]

  l_G = L->l_G;
  mainthread = l_G->mainthread;
  next = mainthread->next;
  result = 0;
  deadmem = 0;
  if ( mainthread->next != nullptr )
  {
    do
    {
      marked = next->gch.marked;
      if ( ((marked & 3) != 0 || all != 0) && (marked & 8) == 0 )
      {
        metatable = next->u.uv.metatable;
        if ( metatable != nullptr
          && (metatable->flags & 4) == 0
          && luaT_gettm(events: metatable, event: TM_GC, ename: L->l_G->tmname[2]) != nullptr )
        {
          len = next->u.uv.len;
          next->gch.marked |= 8u;
          mainthread->next = (GCObject *)next->ts.dummy.l;
          tmudata = (int *)l_G->tmudata;
          deadmem += len + 24;
          if ( tmudata != nullptr )
          {
            next->ts.dummy.l = *tmudata;
            l_G->tmudata->gch.next = next;
          }
          else
          {
            next->ts.dummy.l = (int)next;
          }
          l_G->tmudata = next;
        }
        else
        {
          next->gch.marked |= 8u;
          mainthread = (lua_State *)next;
        }
      }
      else
      {
        mainthread = (lua_State *)next;
      }
      next = mainthread->next;
    }
    while ( mainthread->next != nullptr );
    return deadmem;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004784F0
// Name: traversetable
// Source: json
//------------------------------------------------------------------------------
BOOL __usercall traversetable@<eax>(GCObject *h@<edi>, global_State *g)
{
  GCObject *gclist; // eax
  Table *metatable; // eax
  const lua_TValue *v4; // eax
  const lua_TValue *v5; // esi
  int v6; // eax
  BOOL v7; // ebx
  int v8; // eax
  BOOL v9; // eax
  int sizearray; // ebx
  int v12; // esi
  lua_TValue *array; // eax
  GCObject *gc; // eax
  int v15; // ebx
  int v16; // ecx
  GCObject **v17; // esi
  GCObject *v18; // esi
  int v19; // [esp+8h] [ebp-Ch]
  int weakvalue; // [esp+Ch] [ebp-8h]
  int weakkey; // [esp+10h] [ebp-4h]

  gclist = h->cl.c.gclist;
  weakkey = 0;
  weakvalue = 0;
  if ( gclist != nullptr && (gclist->gch.marked & 3) != 0 )
    reallymarkobject(g, o: gclist);
  metatable = h->u.uv.metatable;
  if ( metatable != nullptr && (metatable->flags & 8) == 0 )
  {
    v4 = luaT_gettm(events: metatable, event: TM_MODE, ename: g->tmname[3]);
    v5 = v4;
    if ( v4 != nullptr && v4->tt == 4 )
    {
      strchr(string: (unsigned __int8 *)(v4->value.b + 16), chr: 0x6Bu);
      v7 = v6 != 0;
      weakkey = v7;
      strchr(string: (unsigned __int8 *)(v5->value.b + 16), chr: 0x76u);
      v9 = v8 != 0;
      weakvalue = v9;
      if ( v7 || v9 )
      {
        h->gch.marked = h->gch.marked & 0xE7 | (8 * (v7 | (2 * v9)));
        h->cl.c.upvalue[0].value.b = (int)g->weak;
        g->weak = h;
        if ( v7 )
        {
          if ( v9 )
            return true;
        }
        else if ( v9 )
        {
          goto LABEL_20;
        }
      }
    }
  }
  sizearray = h->h.sizearray;
  if ( sizearray != 0 )
  {
    v12 = sizearray;
    do
    {
      array = h->h.array;
      --v12;
      --sizearray;
      if ( array[v12].tt >= 4 )
      {
        gc = array[v12].value.gc;
        if ( (gc->gch.marked & 3) != 0 )
          reallymarkobject(g, o: gc);
      }
    }
    while ( sizearray != 0 );
  }
LABEL_20:
  v15 = 1 << h->cl.c.nupvalues;
  if ( v15 != 0 )
  {
    v16 = 32 * v15;
    do
    {
      v16 -= 32;
      v17 = (GCObject **)(v16 + h->u.uv.len);
      --v15;
      v19 = v16;
      if ( v17[2] != nullptr )
      {
        if ( weakkey == 0 && (int)v17[6] >= 4 && (v17[4]->gch.marked & 3) != 0 )
        {
          reallymarkobject(g, o: v17[4]);
          v16 = v19;
        }
        if ( weakvalue == 0 && (int)v17[2] >= 4 )
        {
          v18 = *v17;
          if ( (v18->gch.marked & 3) != 0 )
          {
            reallymarkobject(g, o: v18);
            v16 = v19;
          }
        }
      }
      else if ( (int)v17[6] >= 4 )
      {
        v17[6] = (GCObject *)11;
      }
    }
    while ( v15 != 0 );
  }
  return weakkey != 0 || weakvalue != 0;
}

//------------------------------------------------------------------------------
// Address: 0x004786A0
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
// Address: 0x00478770
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
  GCObject *len; // esi
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
              len = (GCObject *)v6->ts.tsv.len;
              if ( (len->gch.marked & 3) != 0 )
                reallymarkobject(g, o: len);
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
// Address: 0x004788F0
// Name: traversestack
// Source: json
//------------------------------------------------------------------------------
void __usercall traversestack(lua_State *l@<edi>, global_State *g)
{
  CallInfo *base_ci; // eax
  CallInfo *ci; // esi
  lua_TValue *i; // ebx
  lua_TValue *j; // esi
  int size_ci; // esi
  signed int v7; // ebx
  int stacksize; // eax

  if ( l->l_gt.tt >= 4 && (*(_BYTE *)(l->l_gt.value.b + 5) & 3) != 0 )
    reallymarkobject(g, o: l->l_gt.value.gc);
  base_ci = l->base_ci;
  ci = l->ci;
  for ( i = l->top; base_ci <= ci; ++base_ci )
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
  v7 = i - l->stack;
  if ( size_ci <= 20000 )
  {
    if ( 4 * (l->ci - l->base_ci) < size_ci && size_ci > 16 )
      luaD_reallocCI(L: l, newsize: size_ci / 2);
    stacksize = l->stacksize;
    if ( 4 * v7 < stacksize && stacksize > 90 )
      luaD_reallocstack(L: l, newsize: stacksize / 2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004789E0
// Name: propagatemark
// Source: json
//------------------------------------------------------------------------------
int __usercall propagatemark@<eax>(global_State *g@<eax>)
{
  GCObject *gray; // edi
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
      if ( traversetable(h: gray, g) )
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
// Address: 0x00478AE0
// Name: propagateall
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl propagateall(global_State *g)
{
  unsigned int result; // eax
  GCObject *gray; // edi
  int tt; // eax
  int v5; // eax
  int nupvalues; // eax
  GCObject *grayagain; // eax
  unsigned int m; // [esp+Ch] [ebp+8h]

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
          if ( traversetable(h: gray, g) )
            gray->gch.marked &= ~4u;
          v5 = 16 * (gray->h.sizearray + 2 * (1 << gray->cl.c.nupvalues) + 2);
          break;
        case 6:
          g->gray = gray->cl.c.gclist;
          traverseclosure(g, cl: (Closure *)gray);
          nupvalues = gray->cl.c.nupvalues;
          if ( gray->ts.tsv.reserved != 0 )
            v5 = 16 * nupvalues + 24;
          else
            v5 = 4 * nupvalues + 20;
          break;
        case 8:
          grayagain = g->grayagain;
          g->gray = gray->th.gclist;
          gray->th.gclist = grayagain;
          g->grayagain = gray;
          gray->gch.marked &= ~4u;
          traversestack(l: (lua_State *)gray, g);
          v5 = 16 * gray->p.sizecode + 8 * (3 * gray->p.sizelineinfo + 15);
          break;
        case 9:
          g->gray = gray->p.gclist;
          traverseproto(f: (Proto *)gray, g);
          v5 = 4
             * (gray->p.sizeupvalues
              + gray->p.sizecode
              + gray->p.sizelineinfo
              + gray->p.sizep
              + 3 * gray->p.sizelocvars
              + 4 * gray->p.sizek)
             + 76;
          break;
        default:
          v5 = 0;
          break;
      }
      m += v5;
    }
    while ( g->gray != nullptr );
    return m;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00478C10
// Name: cleartable
// Source: json
//------------------------------------------------------------------------------
void __cdecl cleartable(GCObject *l)
{
  GCObject *gc; // ebx
  int sizearray; // edi
  int v3; // esi
  unsigned int len; // eax
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
          len = gc->ts.tsv.len;
          v3 -= 16;
          v5 = *(_DWORD *)(len + v3 + 8);
          v6 = (_DWORD *)(v3 + len);
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
      v10 = (_DWORD *)(v9 + gc->u.uv.len);
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
// Address: 0x00478D00
// Name: sweeplist
// Source: json
//------------------------------------------------------------------------------
GCObject **__cdecl sweeplist(lua_State *L, GCObject **p, unsigned int count)
{
  GCObject **p_next; // ebx
  Table *v4; // esi
  unsigned int v6; // ecx
  unsigned __int8 marked; // al
  int deadmask; // [esp+Ch] [ebp-4h]
  global_State *g; // [esp+18h] [ebp+8h]

  p_next = p;
  v4 = (Table *)*p;
  g = L->l_G;
  for ( deadmask = g->currentwhite ^ 3; *p_next != nullptr; v4 = (Table *)*p_next )
  {
    v6 = count--;
    if ( v6 == 0 )
      break;
    if ( v4->tt == 8 )
      sweeplist(L, p: (GCObject **)&v4[3].metatable, count: 0xFFFFFFFD);
    marked = v4->marked;
    if ( ((marked ^ 3) & deadmask) != 0 )
    {
      v4->marked = marked & 0xF8 | g->currentwhite & 3;
      p_next = &v4->next;
    }
    else
    {
      *p_next = v4->next;
      if ( v4 == (Table *)g->rootgc )
        g->rootgc = v4->next;
      switch ( v4->tt )
      {
        case 4u:
          --L->l_G->strt.nuse;
          luaM_realloc_(L, block: v4, osize: (unsigned int)&v4->array[1].value.gc + 1, nsize: 0);
          break;
        case 5u:
          luaH_free(L, t: v4);
          break;
        case 6u:
          luaF_freeclosure(L, c: (Closure *)v4);
          break;
        case 7u:
          luaM_realloc_(L, block: v4, osize: (unsigned int)&v4->node->i_key.nk.tt, nsize: 0);
          break;
        case 8u:
          luaE_freethread(L, L1: (lua_State *)v4);
          break;
        case 9u:
          luaF_freeproto(L, f: (Proto *)v4);
          break;
        case 0xAu:
          luaF_freeupval(L, uv: (UpVal *)v4);
          break;
        default:
          continue;
      }
    }
  }
  return p_next;
}

//------------------------------------------------------------------------------
// Address: 0x00478E30
// Name: checkSizes
// Source: json
//------------------------------------------------------------------------------
void __cdecl checkSizes(lua_State *L)
{
  global_State *l_G; // esi
  int size; // ecx
  unsigned int buffsize; // eax
  unsigned int v4; // edi
  char *v5; // eax

  l_G = L->l_G;
  size = l_G->strt.size;
  if ( l_G->strt.nuse < size / 4 && size > 64 )
    luaS_resize(L, newsize: size / 2);
  buffsize = l_G->buff.buffsize;
  if ( buffsize > 0x40 )
  {
    v4 = buffsize >> 1;
    if ( (buffsize >> 1) + 1 > 0xFFFFFFFD )
      luaM_toobig(L);
    v5 = (char *)luaM_realloc_(L, block: l_G->buff.buffer, osize: buffsize, nsize: buffsize >> 1);
    l_G->buff.buffsize = v4;
    l_G->buff.buffer = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00478EB0
// Name: GCTM
// Source: json
//------------------------------------------------------------------------------
void __usercall GCTM(lua_State *L@<esi>)
{
  global_State *l_G; // edi
  int *tmudata; // eax
  GCObject *v3; // ebx
  Table *metatable; // eax
  lua_TValue *v5; // eax
  unsigned __int8 allowhook; // cl
  unsigned int GCthreshold; // edx
  lua_TValue *top; // eax
  unsigned int oldt; // [esp+8h] [ebp-8h]
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
  if ( metatable != nullptr && (metatable->flags & 4) == 0 )
  {
    v5 = (lua_TValue *)luaT_gettm(events: metatable, event: TM_GC, ename: L->l_G->tmname[2]);
    if ( v5 != nullptr )
    {
      allowhook = L->allowhook;
      GCthreshold = l_G->GCthreshold;
      L->allowhook = 0;
      oldah = allowhook;
      l_G->GCthreshold = 2 * l_G->totalbytes;
      oldt = GCthreshold;
      *L->top = *v5;
      top = L->top;
      top[1].value.b = (int)v3;
      top[1].tt = 7;
      L->top += 2;
      luaD_call(L, func: L->top - 2, nResults: 0);
      L->allowhook = oldah;
      l_G->GCthreshold = oldt;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00478F80
// Name: void luaC_callGCTM(struct lua_State __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaC_callGCTM(lua_State *L)
{
  global_State *l_G; // edi
  int *tmudata; // eax
  GCObject *v4; // ebx
  Table *metatable; // eax
  const lua_TValue *v6; // eax
  unsigned __int8 allowhook; // cl
  unsigned int GCthreshold; // edx
  lua_TValue *top; // ecx
  lua_TValue *v10; // eax
  unsigned int v11; // [esp+4h] [ebp-4h]
  unsigned __int8 L_3; // [esp+13h] [ebp+Bh]

  while ( L->l_G->tmudata != nullptr )
  {
    l_G = L->l_G;
    tmudata = (int *)l_G->tmudata;
    v4 = (GCObject *)*tmudata;
    if ( (int *)*tmudata == tmudata )
      l_G->tmudata = nullptr;
    else
      *tmudata = v4->ts.dummy.l;
    v4->ts.dummy.l = (int)l_G->mainthread->next;
    l_G->mainthread->next = v4;
    metatable = v4->u.uv.metatable;
    v4->gch.marked = v4->gch.marked & 0xF8 | l_G->currentwhite & 3;
    if ( metatable != nullptr && (metatable->flags & 4) == 0 )
    {
      v6 = luaT_gettm(events: metatable, event: TM_GC, ename: L->l_G->tmname[2]);
      if ( v6 != nullptr )
      {
        allowhook = L->allowhook;
        GCthreshold = l_G->GCthreshold;
        L->allowhook = 0;
        L_3 = allowhook;
        l_G->GCthreshold = 2 * l_G->totalbytes;
        top = L->top;
        v11 = GCthreshold;
        top->value.b = v6->value.b;
        *(&top->value.b + 1) = *(&v6->value.b + 1);
        top->tt = v6->tt;
        v10 = L->top;
        v10[1].value.b = (int)v4;
        v10[1].tt = 7;
        L->top += 2;
        luaD_call(L, func: L->top - 2, nResults: 0);
        L->allowhook = L_3;
        l_G->GCthreshold = v11;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00479070
// Name: void luaC_freeall(struct lua_State __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaC_freeall(lua_State *L)
{
  global_State *l_G; // esi
  int v3; // eax
  GCObject **hash; // edx
  Table *next; // esi
  Table *v6; // ebx
  int v7; // ecx
  unsigned __int8 marked; // al
  int v9; // [esp+8h] [ebp-10h]
  int v10; // [esp+Ch] [ebp-Ch]
  global_State *g; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]
  lua_State *La; // [esp+20h] [ebp+8h]

  l_G = L->l_G;
  g = l_G;
  l_G->currentwhite = 67;
  sweeplist(L, p: &l_G->rootgc, count: 0xFFFFFFFD);
  v3 = 0;
  i = 0;
  if ( l_G->strt.size > 0 )
  {
    while ( 1 )
    {
      hash = l_G->strt.hash;
      next = (Table *)l_G->strt.hash[v3];
      v6 = (Table *)&hash[v3];
      La = (lua_State *)L->l_G;
      v7 = -3;
      v9 = LOBYTE(La->ci) ^ 3;
      if ( next != nullptr )
      {
        while ( 1 )
        {
          v10 = v7 - 1;
          if ( v7 == 0 )
            break;
          if ( next->tt == 8 )
            sweeplist(L, p: (GCObject **)&next[3].metatable, count: 0xFFFFFFFD);
          marked = next->marked;
          if ( ((marked ^ 3) & v9) != 0 )
          {
            next->marked = marked & 0xF8 | (int)La->ci & 3;
            v6 = next;
          }
          else
          {
            v6->next = next->next;
            if ( next == (Table *)La->stack_last )
              La->stack_last = (lua_TValue *)next->next;
            switch ( next->tt )
            {
              case 4u:
                --L->l_G->strt.nuse;
                luaM_realloc_(L, block: next, osize: (unsigned int)&next->array[1].value.gc + 1, nsize: 0);
                break;
              case 5u:
                luaH_free(L, t: next);
                break;
              case 6u:
                luaF_freeclosure(L, c: (Closure *)next);
                break;
              case 7u:
                luaM_realloc_(L, block: next, osize: (unsigned int)&next->node->i_key.nk.tt, nsize: 0);
                break;
              case 8u:
                luaE_freethread(L, L1: (lua_State *)next);
                break;
              case 9u:
                luaF_freeproto(L, f: (Proto *)next);
                break;
              case 0xAu:
                luaF_freeupval(L, uv: (UpVal *)next);
                break;
              default:
                break;
            }
          }
          next = (Table *)v6->next;
          if ( v6->next == nullptr )
            break;
          v7 = v10;
        }
      }
      v3 = i + 1;
      i = v3;
      if ( v3 >= g->strt.size )
        break;
      l_G = g;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004791E0
// Name: markmt
// Source: json
//------------------------------------------------------------------------------
void __usercall markmt(global_State *g@<edi>)
{
  Table **mt; // ebx
  GCObject *v2; // esi
  int tt; // ecx
  GCObject *gclist; // ecx
  GCObject *len; // esi
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
          len = (GCObject *)v2->ts.tsv.len;
          if ( (len->gch.marked & 3) != 0 )
            reallymarkobject(g, o: len);
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
// Address: 0x004792D0
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
// Address: 0x00479340
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
// Address: 0x00479380
// Name: atomic
// Source: json
//------------------------------------------------------------------------------
void __cdecl atomic(GCObject *L)
{
  global_State *l_G; // edi
  lua_State *v2; // ebx
  GCObject *i; // esi
  unsigned __int8 marked; // al
  Table *metatable; // eax
  unsigned int len; // eax
  int v7; // edx
  int *tmudata; // eax
  unsigned int v9; // esi
  unsigned int totalbytes; // eax
  global_State *v11; // [esp+Ch] [ebp-8h]
  int v12; // [esp+10h] [ebp-4h]

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
  v12 = 0;
  v2 = *(lua_State **)(L->u.uv.len + 112);
  v11 = L->th.l_G;
  for ( i = v2->next; v2->next != nullptr; i = v2->next )
  {
    marked = i->gch.marked;
    if ( (marked & 3) != 0 && (marked & 8) == 0 )
    {
      metatable = i->u.uv.metatable;
      if ( metatable != nullptr
        && (metatable->flags & 4) == 0
        && luaT_gettm(events: metatable, event: TM_GC, ename: *(TString **)(L->u.uv.len + 196)) != nullptr )
      {
        len = i->u.uv.len;
        i->gch.marked |= 8u;
        v7 = v12 + len + 24;
        v2->next = (GCObject *)i->ts.dummy.l;
        tmudata = (int *)v11->tmudata;
        v12 = v7;
        if ( tmudata != nullptr )
        {
          i->ts.dummy.l = *tmudata;
          v11->tmudata->gch.next = i;
        }
        else
        {
          i->ts.dummy.l = (int)i;
        }
        v11->tmudata = i;
      }
      else
      {
        i->gch.marked |= 8u;
        v2 = (lua_State *)i;
      }
    }
    else
    {
      v2 = (lua_State *)i;
    }
  }
  marktmu(g: l_G);
  v9 = v12 + propagateall(g: l_G);
  cleartable(l: l_G->weak);
  totalbytes = l_G->totalbytes;
  l_G->currentwhite ^= 3u;
  l_G->sweepstrgc = 0;
  l_G->sweepgc = &l_G->rootgc;
  l_G->gcstate = 2;
  l_G->estimate = totalbytes - v9;
}

//------------------------------------------------------------------------------
// Address: 0x004794A0
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
  GCObject **v7; // eax
  unsigned int estimate; // eax
  GCObject **v9; // [esp-8h] [ebp-14h]

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
      v9 = &l_G->strt.hash[sweepstrgc];
      l_G->sweepstrgc = sweepstrgc + 1;
      sweeplist((lua_State *)L, p: v9, count: 0xFFFFFFFD);
      if ( l_G->sweepstrgc >= l_G->strt.size )
        l_G->gcstate = 3;
      l_G->estimate += l_G->totalbytes - totalbytes;
      result = 10;
      break;
    case 3u:
      v6 = l_G->totalbytes;
      v7 = sweeplist((lua_State *)L, p: l_G->sweepgc, count: 0x28u);
      l_G->sweepgc = v7;
      if ( *v7 == nullptr )
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
// Address: 0x004795A0
// Name: void luaC_step(struct lua_State __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaC_step(GCObject *L)
{
  global_State *l_G; // ebx
  global_State *v3; // edi
  int v4; // eax
  bool v5; // zf
  unsigned int gcdept; // eax
  int sweepstrgc; // eax
  unsigned int v8; // ebx
  unsigned int v9; // ebx
  GCObject **v10; // eax
  unsigned int estimate; // eax
  unsigned int totalbytes; // ecx
  GCObject **v13; // [esp-Ch] [ebp-18h]
  global_State *g; // [esp+8h] [ebp-4h]
  int lim; // [esp+14h] [ebp+8h]

  l_G = L->th.l_G;
  g = l_G;
  lim = 10 * l_G->gcstepmul;
  if ( lim == 0 )
    lim = 2147483646;
  l_G->gcdept += l_G->totalbytes - l_G->GCthreshold;
  while ( 2 )
  {
    v3 = L->th.l_G;
    switch ( v3->gcstate )
    {
      case 0u:
        markroot((lua_State *)L);
        goto LABEL_6;
      case 1u:
        if ( v3->gray != nullptr )
        {
          v4 = propagatemark(g: L->th.l_G);
        }
        else
        {
          atomic(L);
LABEL_6:
          v4 = 0;
        }
LABEL_7:
        lim -= v4;
        v5 = l_G->gcstate == 0;
        if ( l_G->gcstate != 0 )
        {
          if ( lim > 0 )
            continue;
          v5 = l_G->gcstate == 0;
        }
        if ( v5 )
        {
          l_G->GCthreshold = l_G->gcpause * (l_G->estimate / 0x64);
        }
        else
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
        return;
      case 2u:
        sweepstrgc = v3->sweepstrgc;
        v8 = v3->totalbytes;
        v13 = &v3->strt.hash[sweepstrgc];
        v3->sweepstrgc = sweepstrgc + 1;
        sweeplist((lua_State *)L, p: v13, count: 0xFFFFFFFD);
        if ( v3->sweepstrgc >= v3->strt.size )
          v3->gcstate = 3;
        v3->estimate += v3->totalbytes - v8;
        l_G = g;
        v4 = 10;
        goto LABEL_7;
      case 3u:
        v9 = v3->totalbytes;
        v10 = sweeplist((lua_State *)L, p: v3->sweepgc, count: 0x28u);
        v3->sweepgc = v10;
        if ( *v10 == nullptr )
        {
          checkSizes((lua_State *)L);
          v3->gcstate = 4;
        }
        v3->estimate += v3->totalbytes - v9;
        l_G = g;
        v4 = 400;
        goto LABEL_7;
      case 4u:
        v4 = 0;
        if ( v3->tmudata != nullptr )
        {
          GCTM((lua_State *)L);
          estimate = v3->estimate;
          if ( estimate > 0x64 )
            v3->estimate = estimate - 100;
          v4 = 100;
        }
        else
        {
          v3->gcstate = 0;
          v3->gcdept = 0;
        }
        goto LABEL_7;
      default:
        goto LABEL_6;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00479730
// Name: void luaC_fullgc(struct lua_State __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaC_fullgc(GCObject *L)
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
// Address: 0x004797A0
// Name: void luaC_barrierf(struct lua_State __near *,union GCObject __near *,union GCObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaC_barrierf(lua_State *L, GCObject *o, GCObject *v)
{
  global_State *l_G; // eax

  l_G = L->l_G;
  if ( l_G->gcstate == 1 )
    reallymarkobject(g: l_G, o: v);
  else
    o->gch.marked = o->gch.marked & 0xF8 | l_G->currentwhite & 3;
}

//------------------------------------------------------------------------------
// Address: 0x004797E0
// Name: void luaC_barrierback(struct lua_State __near *,struct Table __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaC_barrierback(lua_State *L, GCObject *t)
{
  global_State *l_G; // ecx

  l_G = L->l_G;
  t->gch.marked &= ~4u;
  t->cl.c.upvalue[0].value.b = (int)l_G->grayagain;
  l_G->grayagain = t;
}

//------------------------------------------------------------------------------
// Address: 0x00479800
// Name: void luaC_link(struct lua_State __near *,union GCObject __near *,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaC_link(lua_State *L, GCObject *o, unsigned __int8 tt)
{
  global_State *l_G; // eax

  l_G = L->l_G;
  o->ts.dummy.l = (int)l_G->rootgc;
  l_G->rootgc = o;
  o->gch.marked = l_G->currentwhite & 3;
  o->gch.tt = tt;
}

//------------------------------------------------------------------------------
// Address: 0x00479830
// Name: void luaC_linkupval(struct lua_State __near *,struct UpVal __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl luaC_linkupval(lua_State *L, GCObject *uv)
{
  global_State *l_G; // esi
  unsigned __int8 marked; // cl
  lua_TValue *k; // edx
  unsigned __int8 v5; // cl
  GCObject *b; // edx

  l_G = L->l_G;
  uv->ts.dummy.l = (int)l_G->rootgc;
  l_G->rootgc = uv;
  marked = uv->gch.marked;
  if ( (marked & 7) == 0 )
  {
    if ( l_G->gcstate == 1 )
    {
      k = uv->p.k;
      v5 = marked | 4;
      uv->gch.marked = v5;
      if ( k->tt >= 4 )
      {
        b = (GCObject *)k->value.b;
        if ( (b->gch.marked & 3) != 0 && (v5 & 4) != 0 )
          luaC_barrierf(L, o: uv, v: b);
      }
    }
    else
    {
      uv->gch.marked = marked & 0xF8 | l_G->currentwhite & 3;
    }
  }
}
