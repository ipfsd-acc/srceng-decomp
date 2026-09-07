// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_compact_builder/qhull_poly.cxx
// Functions: 21
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1004D490
// Name: void qh_appendfacet(struct facetT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_appendfacet(facetT *facet)
{
  facetT *facet_tail; // eax
  facetT *previous; // edx

  facet_tail = qh_qh.facet_tail;
  if ( qh_qh.facet_tail == qh_qh.newfacet_list )
    qh_qh.newfacet_list = facet;
  if ( qh_qh.facet_tail == qh_qh.facet_next )
    qh_qh.facet_next = facet;
  facet->previous = qh_qh.facet_tail->previous;
  facet->next = facet_tail;
  previous = facet_tail->previous;
  if ( previous != nullptr )
    previous->next = facet;
  else
    qh_qh.facet_list = facet;
  facet_tail->previous = facet;
  ++qh_qh.num_facets;
  if ( qh_qh.IStracing >= 4 )
    fprintf(str: qh_qh.ferr, format: "qh_appendfacet: append f%d to facet_list\n", facet->id);
}

//------------------------------------------------------------------------------
// Address: 0x1004D500
// Name: void qh_appendvertex(struct vertexT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_appendvertex(vertexT *vertex)
{
  vertexT *vertex_tail; // ecx
  vertexT *previous; // edx

  vertex_tail = qh_qh.vertex_tail;
  if ( qh_qh.vertex_tail == qh_qh.newvertex_list )
    qh_qh.newvertex_list = vertex;
  *((_DWORD *)vertex + 5) |= 0x10000000u;
  vertex->previous = vertex_tail->previous;
  vertex->next = vertex_tail;
  previous = vertex_tail->previous;
  if ( previous != nullptr )
    previous->next = vertex;
  else
    qh_qh.vertex_list = vertex;
  vertex_tail->previous = vertex;
  ++qh_qh.num_vertices;
  if ( qh_qh.IStracing >= 4 )
    fprintf(str: qh_qh.ferr, format: "qh_appendvertex: append v%d to vertex_list\n", *((_DWORD *)vertex + 5) & 0xFFFFFF);
}

//------------------------------------------------------------------------------
// Address: 0x1004D570
// Name: void qh_attachnewfacets(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_attachnewfacets()
{
  facetT *visible_list; // edi
  setT *ridges; // eax
  _DWORD *p; // esi
  setelemT *e; // ebx
  int v4; // eax
  int v5; // ecx
  facetT *i; // edi
  facetT *v7; // ebx
  setT *neighbors; // esi
  setelemT v9; // ebx
  char *v10; // esi
  setT *v11; // esi
  setT **p_neighbors; // ebx
  setelemT v13; // eax
  char *v14; // esi
  setelemT v15; // eax
  facetT *j; // eax
  facetT *visible; // [esp+Ch] [ebp-8h]
  facetT *horizon; // [esp+10h] [ebp-4h]

  qh_qh.NEWfacets = 1;
  if ( qh_qh.IStracing >= 3 )
    fprintf(str: qh_qh.ferr, format: "qh_attachnewfacets: delete interior ridges\n");
  visible_list = qh_qh.visible_list;
  ++qh_qh.visit_id;
  if ( qh_qh.visible_list != nullptr )
  {
    do
    {
      if ( (*((_DWORD *)visible_list + 20) & 0x400) == 0 )
        break;
      ridges = visible_list->ridges;
      visible_list->visitid = qh_qh.visit_id;
      if ( ridges != nullptr )
      {
        p = ridges->e[0].p;
        e = ridges->e;
        if ( p != nullptr )
        {
          do
          {
            v4 = p[1];
            ++e;
            if ( (facetT *)v4 == visible_list )
              v4 = p[2];
            if ( *(_DWORD *)(v4 + 72) == qh_qh.visit_id
              || ((v5 = *(_DWORD *)(v4 + 80)) & 0x400) == 0 && (v5 & 0x1000) != 0 )
            {
              if ( (*(_DWORD *)(v4 + 80) & 0x400) == 0 )
                qh_setdel(set: *(setT **)(v4 + 56), oldelem: p);
              qh_setfree(setp: (setT **)p);
              qh_memfree(object: p, size: 16);
            }
            p = (_DWORD *)e->i;
          }
          while ( e->i != 0 );
        }
        visible_list->ridges->e[0].i = 0;
      }
      visible_list->neighbors->e[0].i = 0;
      visible_list = visible_list->next;
    }
    while ( visible_list != nullptr );
  }
  if ( qh_qh.IStracing >= 1 )
    fprintf(str: qh_qh.ferr, format: "qh_attachnewfacets: attach horizon facets to new facets\n");
  for ( i = qh_qh.newfacet_list; i != nullptr; i = i->next )
  {
    if ( i->next == nullptr )
      break;
    v7 = (facetT *)i->neighbors->e[0].p;
    horizon = v7;
    if ( (*((_DWORD *)v7 + 20) & 0x1000) != 0 )
    {
      neighbors = v7->neighbors;
      visible = nullptr;
      if ( neighbors == nullptr )
        goto LABEL_35;
      v9.p = (void *)neighbors->e[0];
      v10 = (char *)neighbors->e;
      if ( v9.i == 0 )
        goto LABEL_34;
      while ( 1 )
      {
        v10 += 4;
        if ( (*(_DWORD *)(v9.i + 80) & 0x400) != 0 )
        {
          if ( visible != nullptr )
          {
            if ( qh_setequal_skip(
                   setA: i->vertices,
                   skipA: 0,
                   setB: horizon->vertices,
                   skipB: (v10 - (char *)horizon->neighbors - 8) >> 2) )
            {
              visible = (facetT *)v9.i;
LABEL_29:
              if ( visible != nullptr )
              {
                visible->f.replace = i;
                qh_setreplace(set: horizon->neighbors, oldelem: visible, newelem: i);
                goto LABEL_44;
              }
LABEL_34:
              v7 = horizon;
LABEL_35:
              ivp_message(
                templat: "qhull internal error (qh_attachnewfacets): couldn't find visible facet for horizon f%d of newfacet f%d\n",
                v7->id,
                i->id);
              qh_errexit2(exitcode: 5, facet: horizon, otherfacet: i);
            }
          }
          else
          {
            visible = (facetT *)v9.i;
          }
        }
        v9.p = *(void **)v10;
        if ( *(_DWORD *)v10 == 0 )
          goto LABEL_29;
      }
    }
    v11 = v7->neighbors;
    p_neighbors = &v7->neighbors;
    if ( v11 != nullptr )
    {
      v13.p = (void *)v11->e[0];
      v14 = (char *)v11->e;
      if ( v13.i != 0 )
      {
        do
        {
          v14 += 4;
          if ( (*(_DWORD *)(v13.i + 80) & 0x400) != 0 )
          {
            *(_DWORD *)(v13.i + 32) = i;
            qh_setdelnth(set: *p_neighbors, nth: (v14 - (char *)*p_neighbors - 8) >> 2);
            v14 -= 4;
          }
          v13.p = *(void **)v14;
        }
        while ( *(_DWORD *)v14 != 0 );
      }
    }
    qh_setappend(setp: p_neighbors, newelem: i);
    v15.p = (void *)i->ridges->e[0];
    if ( *(facetT **)(v15.i + 4) == horizon )
      *(_DWORD *)(v15.i + 8) = i;
    else
      *(_DWORD *)(v15.i + 4) = i;
LABEL_44:
    ;
  }
  if ( qh_qh.PRINTstatistics != 0 )
  {
    for ( j = qh_qh.visible_list; j != nullptr; j = j->next )
    {
      if ( (*((_DWORD *)j + 20) & 0x400) == 0 )
        break;
      if ( j->f.replace == nullptr )
        ++qh_qhstat.stats[86].i;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004D810
// Name: unsigned int qh_checkflipped(struct facetT __near *,double __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl qh_checkflipped(facetT *facet, long double *distp, unsigned int allerror)
{
  double v3; // xmm0_8
  double dist; // [esp+14h] [ebp-8h] BYREF

  if ( (*((_DWORD *)facet + 20) & 0x8000) == 0 || distp != nullptr )
  {
    ++qh_qhstat.stats[48].i;
    qh_distplane(point: qh_qh.interior_point, facet, &dist);
    v3 = dist;
    if ( distp != nullptr )
      *distp = dist;
    if ( allerror != 0 )
    {
      if ( v3 <= -qh_qh.DISTround )
        return 1;
    }
    else if ( v3 < 0.0 )
    {
      return 1;
    }
    *((_DWORD *)facet + 20) |= 0x8000u;
    ++qh_qhstat.stats[79].i;
    if ( qh_qh.IStracing != 0 )
      fprintf(
        str: qh_qh.ferr,
        format: "qh_checkflipped: facet f%d is flipped, distance= %6.12g during p%d\n",
        facet->id,
        v3,
        qh_qh.furthest_id);
    qh_precision(reason: "flipped facet");
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1004D8E0
// Name: struct setT __near * qh_facetintersect(struct facetT __near *,struct facetT __near *,int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
setT *__cdecl qh_facetintersect(facetT *facetA, facetT *facetB, int *skipA, int *skipB, int prepend)
{
  int hull_dim; // edx
  setT *neighbors; // ecx
  setT *v8; // eax
  facetT *p; // ebx
  facetT **v10; // eax
  facetT *v11; // ebx
  int v12; // eax
  facetT *v13; // eax
  facetT **v14; // ecx
  facetT *v15; // ebx
  setT *v16; // ebx
  int i; // [esp+14h] [ebp+8h]

  hull_dim = qh_qh.hull_dim;
  neighbors = facetB->neighbors;
  v8 = facetA->neighbors;
  i = 0;
  if ( facetB == v8->e[0].p )
  {
    *skipA = 0;
  }
  else if ( facetB == (facetT *)v8[1].maxsize )
  {
    *skipA = 1;
  }
  else
  {
    p = (facetT *)v8[1].e[0].p;
    v10 = (facetT **)&v8[2];
    if ( facetB == p )
    {
      *skipA = 2;
    }
    else
    {
      i = 3;
      if ( qh_qh.hull_dim > 3 )
      {
        while ( 1 )
        {
          v11 = *v10++;
          if ( facetB == v11 )
            break;
          if ( ++i >= qh_qh.hull_dim )
            goto LABEL_12;
        }
        *skipA = i;
      }
    }
  }
LABEL_12:
  if ( facetA == neighbors->e[0].p )
  {
    v12 = 0;
    *skipB = 0;
  }
  else if ( facetA == (facetT *)neighbors[1].maxsize )
  {
    v12 = 0;
    *skipB = 1;
  }
  else
  {
    v13 = (facetT *)neighbors[1].e[0].p;
    v14 = (facetT **)&neighbors[2];
    if ( facetA == v13 )
    {
      v12 = 0;
      *skipB = 2;
    }
    else
    {
      v12 = 3;
      if ( hull_dim > 3 )
      {
        while ( 1 )
        {
          v15 = *v14++;
          if ( facetA == v15 )
            break;
          if ( ++v12 >= hull_dim )
            goto LABEL_23;
        }
        *skipB = v12;
      }
    }
  }
LABEL_23:
  if ( i >= hull_dim || v12 >= hull_dim )
  {
    ivp_message(
      templat: "qhull internal error (qh_facetintersect): f%d or f%d not in others neighbors\n",
      facetA->id,
      facetB->id);
    qh_errexit2(exitcode: 5, facet: facetA, otherfacet: facetB);
  }
  v16 = qh_setnew_delnthsorted(set: facetA->vertices, size: (setT *)qh_qh.hull_dim, nth: *skipA, prepend);
  if ( qh_qh.IStracing >= 4 )
    fprintf(
      str: qh_qh.ferr,
      format: "qh_facetintersect: f%d skip %d matches f%d skip %d\n",
      facetA->id,
      *skipA,
      facetB->id,
      *skipB);
  return v16;
}

//------------------------------------------------------------------------------
// Address: 0x1004DA50
// Name: unsigned int qh_gethash(int,struct setT __near *,int,int,void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl qh_gethash(unsigned int hashsize, setT *set, int size, int firstindex, void *skipelem)
{
  setelemT *v5; // esi
  unsigned int result; // eax
  unsigned int v7; // eax
  int v8; // edi
  unsigned int i; // edx
  unsigned int v10; // ebx
  unsigned int v11; // edx

  v5 = &set->e[firstindex];
  switch ( size - firstindex )
  {
    case 1:
      result = (v5->i - (int)skipelem) % hashsize;
      break;
    case 2:
      result = (set->e[firstindex].i + *(&set[1].maxsize + firstindex) - (int)skipelem) % hashsize;
      break;
    case 3:
      result = (set->e[firstindex].i + *(&set[1].maxsize + firstindex) + set[1].e[firstindex].i - (int)skipelem)
             % hashsize;
      break;
    case 4:
      result = (set->e[firstindex].i
              + *(&set[1].maxsize + firstindex)
              + set[1].e[firstindex].i
              + *(&set[2].maxsize + firstindex)
              - (int)skipelem)
             % hashsize;
      break;
    case 5:
      result = (v5->i + v5[1].i + v5[2].i + v5[3].i + v5[4].i - (int)skipelem) % hashsize;
      break;
    case 6:
      result = (v5->i + v5[1].i + v5[2].i + v5[3].i + v5[4].i + v5[5].i - (int)skipelem) % hashsize;
      break;
    default:
      v7 = 0;
      v8 = 3;
      do
      {
        i = v5->i;
        ++v5;
        if ( (void *)i != skipelem )
        {
          v10 = i >> (32 - v8);
          v11 = i << v8;
          v8 += 3;
          v7 ^= v11 + v10;
          if ( v8 >= 32 )
            v8 -= 32;
        }
      }
      while ( v5->i != 0 );
      result = v7 % hashsize;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004DB60
// Name: void qh_makenewplanes(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_makenewplanes()
{
  facetT *i; // esi

  for ( i = qh_qh.newfacet_list; i != nullptr; i = i->next )
  {
    if ( i->next == nullptr )
      break;
    if ( (*((_BYTE *)i + 83) & 1) == 0 )
      qh_setfacetplane(facet: i);
  }
  if ( qh_qh.JOGGLEmax < 8.988465674311579e307 && qh_qh.min_vertex > -qh_qhstat.stats[127].r )
    qh_qh.min_vertex = -qh_qhstat.stats[127].r;
}

//------------------------------------------------------------------------------
// Address: 0x1004DBD0
// Name: unsigned int qh_matchvertices(int,struct setT __near *,int,struct setT __near *,int __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl qh_matchvertices(
        vertexT **firstindex,
        setT *verticesA,
        int skipA,
        setT *verticesB,
        int *skipB,
        unsigned int *same)
{
  setelemT *v6; // esi
  setelemT *v7; // ecx
  setelemT *v8; // eax
  int v9; // eax
  int v10; // eax
  vertexT **skipAp; // [esp+14h] [ebp+8h]

  v6 = &verticesA->e[(_DWORD)firstindex];
  v7 = nullptr;
  v8 = &verticesB->e[(_DWORD)firstindex];
  skipAp = (vertexT **)&verticesA->e[skipA];
  while ( v6 == (setelemT *)skipAp )
  {
LABEL_7:
    ++v6;
    if ( v6->i == 0 )
    {
      if ( v7 == nullptr )
        v7 = v8 + 1;
      v9 = ((char *)v7 - (char *)verticesB - 8) >> 2;
      *skipB = v9;
      v10 = ((unsigned __int8)skipA ^ (unsigned __int8)~(_BYTE)v9) & 1;
      *same = v10;
      if ( qh_qh.IStracing >= 4 )
        fprintf(
          str: qh_qh.ferr,
          format: "qh_matchvertices: matched by skip %d (v%d) and skip %d (v%d) same? %d\n",
          skipA,
          *((_DWORD *)*skipAp + 5) & 0xFFFFFF,
          *skipB,
          *(_DWORD *)(v7[-1].i + 20) & 0xFFFFFF,
          v10);
      return 1;
    }
  }
  if ( v6->i == v8->i )
  {
LABEL_6:
    ++v8;
    goto LABEL_7;
  }
  while ( 1 )
  {
    ++v8;
    if ( v7 != nullptr )
      return 0;
    v7 = v8;
    if ( v6->i == v8->i )
      goto LABEL_6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004DC90
// Name: struct facetT __near * qh_newfacet(void)
// Source: json
//------------------------------------------------------------------------------
facetT *__cdecl qh_newfacet()
{
  void **v0; // eax
  unsigned __int8 *v1; // esi
  long double MINoutside; // xmm0_8

  v0 = &qhmem.freelists[qhmem.indextable[88]];
  v1 = (unsigned __int8 *)*v0;
  if ( *v0 != nullptr )
  {
    ++qhmem.cntquick;
    *v0 = *(void **)*v0;
  }
  else
  {
    v1 = (unsigned __int8 *)qh_memalloc(insize: 88);
  }
  memset(dst: v1, value: 0, count: 0x58u);
  if ( qh_qh.facet_id == qh_qh.tracefacet_id )
    qh_qh.tracefacet = (facetT *)v1;
  *((_DWORD *)v1 + 19) = qh_qh.facet_id++;
  *((_DWORD *)v1 + 15) = qh_setnew(setsize: qh_qh.hull_dim);
  *(_QWORD *)v1 = 0;
  if ( qh_qh.FORCEoutput != 0 && qh_qh.APPROXhull != 0 )
    MINoutside = qh_qh.MINoutside;
  else
    MINoutside = qh_qh.DISTround;
  *((_DWORD *)v1 + 20) |= 0x41200u;
  *((long double *)v1 + 1) = MINoutside;
  if ( qh_qh.IStracing >= 4 )
    fprintf(str: qh_qh.ferr, format: "qh_newfacet: created facet f%d\n", *((_DWORD *)v1 + 19));
  return (facetT *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x1004DD60
// Name: struct ridgeT __near * qh_newridge(void)
// Source: json
//------------------------------------------------------------------------------
ridgeT *__cdecl qh_newridge()
{
  void **v0; // eax
  _DWORD *v1; // esi

  v0 = &qhmem.freelists[qhmem.indextable[16]];
  v1 = *v0;
  if ( *v0 != nullptr )
  {
    ++qhmem.cntquick;
    *v0 = *(void **)*v0;
  }
  else
  {
    v1 = qh_memalloc(insize: 16);
  }
  *(_QWORD *)v1 = 0;
  *((_QWORD *)v1 + 1) = 0;
  ++qh_qhstat.stats[179].i;
  if ( qh_qh.ridge_id == 0xFFFFFF )
    ivp_message(
      templat: "qhull warning: more than %d ridges.  Id field overflows and two ridges\n"
      "may have the same identifier.  Otherwise output ok.\n",
      0xFFFFFF);
  v1[3] ^= (qh_qh.ridge_id++ ^ v1[3]) & 0xFFFFFF;
  if ( qh_qh.IStracing >= 4 )
    fprintf(str: qh_qh.ferr, format: "qh_newridge: created ridge r%d\n", v1[3] & 0xFFFFFF);
  return (ridgeT *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x1004DE10
// Name: int qh_pointid(double __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl qh_pointid(long double *point)
{
  int v2; // eax

  if ( point == nullptr )
    return -3;
  if ( point == qh_qh.interior_point )
    return -2;
  if ( point >= qh_qh.first_point && point < &qh_qh.first_point[qh_qh.num_points * qh_qh.hull_dim] )
    return (point - qh_qh.first_point) / qh_qh.hull_dim;
  v2 = qh_setindex(set: qh_qh.other_points, atelem: point);
  if ( v2 == -1 )
    return -1;
  else
    return qh_qh.num_points + v2;
}

//------------------------------------------------------------------------------
// Address: 0x1004DE80
// Name: void qh_removefacet(struct facetT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_removefacet(facetT *facet)
{
  facetT *next; // eax
  facetT *previous; // edx

  next = facet->next;
  previous = facet->previous;
  if ( facet == qh_qh.newfacet_list )
    qh_qh.newfacet_list = facet->next;
  if ( facet == qh_qh.facet_next )
    qh_qh.facet_next = next;
  if ( facet == qh_qh.visible_list )
    qh_qh.visible_list = next;
  if ( previous != nullptr )
  {
    previous->next = next;
    next->previous = previous;
  }
  else
  {
    qh_qh.facet_list = next;
    next->previous = nullptr;
  }
  --qh_qh.num_facets;
  if ( qh_qh.IStracing >= 4 )
    fprintf(str: qh_qh.ferr, format: "qh_removefacet: remove f%d from facet_list\n", facet->id);
}

//------------------------------------------------------------------------------
// Address: 0x1004DF00
// Name: void qh_removevertex(struct vertexT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_removevertex(vertexT *vertex)
{
  vertexT *next; // edx
  vertexT *previous; // ecx

  next = vertex->next;
  previous = vertex->previous;
  if ( vertex == qh_qh.newvertex_list )
    qh_qh.newvertex_list = vertex->next;
  if ( previous != nullptr )
  {
    previous->next = next;
    next->previous = previous;
  }
  else
  {
    qh_qh.vertex_list = vertex->next;
    qh_qh.vertex_list->previous = nullptr;
  }
  --qh_qh.num_vertices;
  if ( qh_qh.IStracing >= 4 )
    fprintf(
      str: qh_qh.ferr,
      format: "qh_removevertex: remove v%d from vertex_list\n",
      *((_DWORD *)vertex + 5) & 0xFFFFFF);
}

//------------------------------------------------------------------------------
// Address: 0x1004DF70
// Name: void qh_updatevertices(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_updatevertices()
{
  vertexT *i; // esi
  setT *neighbors; // eax
  setelemT *e; // ecx
  setelemT v3; // eax
  facetT *j; // edi
  setT *vertices; // eax
  setelemT *v6; // esi
  setelemT v7; // eax
  facetT *v8; // ecx
  setT *v9; // eax
  setelemT v10; // esi
  setelemT *v11; // ebx
  int v12; // edx
  setT *v13; // edi
  setelemT v14; // eax
  setelemT *v15; // ecx
  int v16; // eax
  facetT *k; // ebx
  setT *v18; // eax
  setelemT v19; // esi
  setelemT *v20; // edi
  int v21; // eax
  int v22; // eax
  int v23; // [esp-14h] [ebp-18h]
  int v24; // [esp-14h] [ebp-18h]
  unsigned int id; // [esp-10h] [ebp-14h]
  unsigned int v26; // [esp-10h] [ebp-14h]
  facetT *visible; // [esp+0h] [ebp-4h]

  if ( qh_qh.IStracing >= 3 )
    fprintf(str: qh_qh.ferr, format: "qh_updatevertices: delete interior vertices and update vertex->neighbors\n");
  if ( qh_qh.VERTEXneighbors != 0 )
  {
    for ( i = qh_qh.newvertex_list; i != nullptr; i = i->next )
    {
      if ( i->next == nullptr )
        break;
      neighbors = i->neighbors;
      if ( neighbors != nullptr )
      {
        e = neighbors->e;
        v3.p = (void *)neighbors->e[0];
        if ( v3.i != 0 )
        {
          do
          {
            ++e;
            if ( (*(_DWORD *)(v3.i + 80) & 0x400) != 0 )
              e[-1].i = 0;
            v3.p = e->p;
          }
          while ( e->i != 0 );
        }
      }
      qh_setcompact(set: i->neighbors);
    }
    for ( j = qh_qh.newfacet_list; j != nullptr; j = j->next )
    {
      if ( j->next == nullptr )
        break;
      vertices = j->vertices;
      if ( vertices != nullptr )
      {
        v6 = vertices->e;
        v7.p = (void *)vertices->e[0];
        if ( v7.i != 0 )
        {
          do
          {
            ++v6;
            qh_setappend(setp: (setT **)(v7.i + 12), newelem: j);
            v7.p = v6->p;
          }
          while ( v6->i != 0 );
        }
      }
    }
    for ( visible = qh_qh.visible_list; visible != nullptr; visible = v8->next )
    {
      v8 = visible;
      if ( (*((_DWORD *)visible + 20) & 0x400) == 0 )
        break;
      v9 = visible->vertices;
      if ( v9 != nullptr )
      {
        v10.p = (void *)v9->e[0];
        v11 = v9->e;
        if ( v10.i != 0 )
        {
          do
          {
            v12 = *(_DWORD *)(v10.i + 20);
            ++v11;
            if ( (v12 & 0x18000000) == 0 )
            {
              v13 = *(setT **)(v10.i + 12);
              if ( v13 != nullptr && (v14.p = (void *)v13->e[0], v15 = v13->e, v14.i != 0) )
              {
                while ( 1 )
                {
                  ++v15;
                  if ( (*(_DWORD *)(v14.i + 80) & 0x400) == 0 )
                    break;
                  v14.p = v15->p;
                  if ( v15->i == 0 )
                    goto LABEL_27;
                }
                qh_setdel(set: v13, oldelem: visible);
              }
              else
              {
LABEL_27:
                *(_DWORD *)(v10.i + 20) = v12 | 0x8000000;
                qh_setappend(setp: &qh_qh.del_vertices, newelem: v10.p);
                if ( qh_qh.IStracing >= 2 )
                {
                  id = visible->id;
                  v23 = *(_DWORD *)(v10.i + 20) & 0xFFFFFF;
                  v16 = qh_pointid(point: *(long double **)(v10.i + 8));
                  fprintf(str: qh_qh.ferr, format: "qh_updatevertices: delete vertex p%d (v%d) in f%d\n", v16, v23, id);
                }
              }
            }
            v10.p = v11->p;
          }
          while ( v11->i != 0 );
          v8 = visible;
        }
      }
    }
  }
  else
  {
    for ( k = qh_qh.visible_list; k != nullptr; k = k->next )
    {
      if ( (*((_DWORD *)k + 20) & 0x400) == 0 )
        break;
      v18 = k->vertices;
      if ( v18 != nullptr )
      {
        v19.p = (void *)v18->e[0];
        v20 = v18->e;
        if ( v19.i != 0 )
        {
          do
          {
            v21 = *(_DWORD *)(v19.i + 20);
            ++v20;
            if ( (v21 & 0x18000000) == 0 )
            {
              *(_DWORD *)(v19.i + 20) = v21 | 0x8000000;
              qh_setappend(setp: &qh_qh.del_vertices, newelem: v19.p);
              if ( qh_qh.IStracing >= 2 )
              {
                v26 = k->id;
                v24 = *(_DWORD *)(v19.i + 20) & 0xFFFFFF;
                v22 = qh_pointid(point: *(long double **)(v19.i + 8));
                fprintf(str: qh_qh.ferr, format: "qh_updatevertices: delete vertex p%d (v%d) in f%d\n", v22, v24, v26);
              }
            }
            v19.p = v20->p;
          }
          while ( v20->i != 0 );
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004E1E0
// Name: void qh_delfacet(struct facetT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_delfacet(facetT *facet)
{
  void **v1; // eax
  int center_size; // edx
  void **v3; // eax
  void **v4; // eax

  if ( qh_qh.IStracing >= 5 )
    fprintf(str: qh_qh.ferr, format: "qh_delfacet: delete f%d\n", facet->id);
  if ( facet == qh_qh.tracefacet )
    qh_qh.tracefacet = nullptr;
  if ( facet == qh_qh.GOODclosest )
    qh_qh.GOODclosest = nullptr;
  qh_removefacet(facet);
  if ( facet->normal != nullptr )
  {
    ++qhmem.freeshort;
    v1 = &qhmem.freelists[qhmem.indextable[qh_qh.normal_size]];
    *(_DWORD *)facet->normal = *v1;
    *v1 = facet->normal;
  }
  if ( qh_qh.CENTERtype == qh_ASvoronoi )
  {
    if ( facet->center == nullptr )
      goto LABEL_15;
    center_size = qh_qh.center_size;
  }
  else
  {
    if ( facet->center == nullptr )
      goto LABEL_15;
    center_size = qh_qh.normal_size;
  }
  ++qhmem.freeshort;
  v3 = &qhmem.freelists[qhmem.indextable[center_size]];
  *(_DWORD *)facet->center = *v3;
  *v3 = facet->center;
LABEL_15:
  qh_setfree(setp: &facet->neighbors);
  if ( facet->ridges != nullptr )
    qh_setfree(setp: &facet->ridges);
  qh_setfree(setp: &facet->vertices);
  if ( facet->outsideset != nullptr )
    qh_setfree(setp: &facet->outsideset);
  if ( facet->coplanarset != nullptr )
    qh_setfree(setp: &facet->coplanarset);
  ++qhmem.freeshort;
  v4 = &qhmem.freelists[qhmem.indextable[88]];
  LODWORD(facet->furthestdist) = *v4;
  *v4 = facet;
}

//------------------------------------------------------------------------------
// Address: 0x1004E320
// Name: void qh_deletevisible(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_deletevisible()
{
  int v0; // edi
  int v1; // eax
  int v2; // ebx
  facetT *visible_list; // eax
  facetT *next; // esi
  setT *del_vertices; // ecx
  vertexT *p; // eax
  setelemT *e; // esi

  v0 = 0;
  v1 = qh_setsize(set: qh_qh.del_vertices);
  v2 = v1;
  if ( qh_qh.IStracing >= 1 )
    fprintf(
      str: qh_qh.ferr,
      format: "qh_deletevisible: delete %d visible facets and %d vertices\n",
      qh_qh.num_visible,
      v1);
  visible_list = qh_qh.visible_list;
  if ( qh_qh.visible_list != nullptr )
  {
    do
    {
      if ( (*((_DWORD *)visible_list + 20) & 0x400) == 0 )
        break;
      next = visible_list->next;
      ++v0;
      qh_delfacet(facet: visible_list);
      visible_list = next;
    }
    while ( next != nullptr );
  }
  if ( v0 != qh_qh.num_visible )
  {
    ivp_message(
      templat: "qhull internal error (qh_deletevisible): qh num_visible %d is not number of visible facets %d\n",
      qh_qh.num_visible,
      v0);
    qh_errexit(exitcode: 5, facet: nullptr, ridge: nullptr);
  }
  qh_qhstat.stats[188].i += v0;
  qh_qh.num_visible = 0;
  if ( qh_qhstat.stats[189].i < v0 )
    qh_qhstat.stats[189].i = v0;
  qh_qhstat.stats[45].i += v2;
  if ( qh_qhstat.stats[46].i < v2 )
    qh_qhstat.stats[46].i = v2;
  del_vertices = qh_qh.del_vertices;
  if ( qh_qh.del_vertices != nullptr )
  {
    p = (vertexT *)qh_qh.del_vertices->e[0].p;
    e = qh_qh.del_vertices->e;
    if ( p != nullptr )
    {
      do
      {
        ++e;
        qh_delvertex(vertex: p);
        p = (vertexT *)e->i;
      }
      while ( e->i != 0 );
      del_vertices = qh_qh.del_vertices;
    }
  }
  qh_settruncate(set: del_vertices, size: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1004E420
// Name: struct facetT __near * qh_makenewfacet(struct setT __near *,unsigned int,struct facetT __near *)
// Source: json
//------------------------------------------------------------------------------
facetT *__cdecl qh_makenewfacet(setT *vertices, unsigned int toporient, facetT *horizon)
{
  setT *v3; // ebx
  setelemT v4; // esi
  setelemT *e; // edi
  facetT *v6; // esi

  v3 = vertices;
  if ( vertices != nullptr )
  {
    v4.p = (void *)vertices->e[0];
    e = vertices->e;
    if ( v4.i != 0 )
    {
      do
      {
        ++e;
        if ( (*(_DWORD *)(v4.i + 20) & 0x10000000) == 0 )
        {
          qh_removevertex(vertex: (vertexT *)v4.p);
          qh_appendvertex(vertex: (vertexT *)v4.p);
        }
        v4.p = e->p;
      }
      while ( e->i != 0 );
      v3 = vertices;
    }
  }
  v6 = qh_newfacet();
  *((_DWORD *)v6 + 20) ^= (*((_DWORD *)v6 + 20) ^ (toporient << 11)) & 0x800;
  v6->vertices = v3;
  qh_setappend(setp: &v6->neighbors, newelem: horizon);
  qh_appendfacet(facet: v6);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x1004E4A0
// Name: struct facetT __near * qh_makenew_nonsimplicial(struct facetT __near *,struct vertexT __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
facetT *__cdecl qh_makenew_nonsimplicial(facetT *visible, vertexT *apex, int *numnew)
{
  facetT *v3; // ecx
  setT *ridges; // eax
  facetT *v5; // ebx
  ridgeT **e; // eax
  ridgeT *v7; // edi
  facetT *top; // eax
  facetT *bottom; // esi
  void **v10; // eax
  unsigned int v11; // ebx
  facetT *replace; // eax
  int v13; // eax
  facetT *result; // eax
  ridgeT **ridgep; // [esp+4h] [ebp-10h]
  int ridgeid; // [esp+8h] [ebp-Ch]
  unsigned int toporient; // [esp+Ch] [ebp-8h]
  setT *vertices; // [esp+10h] [ebp-4h] BYREF

  v3 = visible;
  ridges = visible->ridges;
  v5 = nullptr;
  if ( ridges != nullptr )
  {
    e = (ridgeT **)ridges->e;
    v7 = *e;
    if ( *e != nullptr )
    {
      do
      {
        ridgep = e + 1;
        ridgeid = *((_DWORD *)v7 + 3) & 0xFFFFFF;
        top = v7->top;
        if ( top == v3 )
          bottom = v7->bottom;
        else
          bottom = v7->top;
        if ( (*((_DWORD *)bottom + 20) & 0x400) != 0 )
        {
          if ( qh_qh.ONLYgood == 0 && bottom->visitid == qh_qh.visit_id )
          {
            qh_setfree(setp: &v7->vertices);
            ++qhmem.freeshort;
            v10 = &qhmem.freelists[qhmem.indextable[16]];
            v7->vertices = (setT *)*v10;
            *v10 = v7;
          }
        }
        else
        {
          v11 = top == v3;
          toporient = v11;
          vertices = qh_setnew(setsize: qh_qh.hull_dim);
          qh_setappend(setp: &vertices, newelem: apex);
          qh_setappend_set(setp: &vertices, setA: v7->vertices);
          v5 = qh_makenewfacet(vertices, toporient: v11, horizon: bottom);
          ++*numnew;
          if ( (*((_DWORD *)bottom + 20) & 0x800000) != 0 )
          {
            *((_DWORD *)v5 + 20) |= 0x1000000u;
            if ( (*((_DWORD *)bottom + 20) & 0x2000) != 0 )
            {
              replace = bottom->f.replace;
              v5->f.replace = replace->f.replace;
              replace->f.replace = v5;
            }
            else
            {
              v5->f.replace = v5;
              bottom->f.replace = v5;
            }
          }
          if ( qh_qh.ONLYgood != 0 )
          {
            if ( (*((_DWORD *)bottom + 20) & 0x1000) == 0 )
              qh_setappend(setp: &v5->ridges, newelem: v7);
          }
          else
          {
            v13 = *((_DWORD *)bottom + 20);
            if ( (v13 & 0x2000) != 0 )
            {
              if ( (v13 & 0x1000) != 0 )
              {
                ivp_message(
                  templat: "qhull internal error (qh_makenew_nonsimplicial): simplicial f%d sharing two ridges with f%d\n",
                  bottom->id,
                  visible->id);
                qh_errexit2(exitcode: 5, facet: bottom, otherfacet: visible);
              }
              qh_setappend(setp: &bottom->neighbors, newelem: v5);
            }
            else
            {
              qh_setreplace(set: bottom->neighbors, oldelem: visible, newelem: v5);
            }
            if ( (*((_DWORD *)bottom + 20) & 0x1000) != 0 )
            {
              qh_setdel(set: bottom->ridges, oldelem: v7);
              qh_setfree(setp: &v7->vertices);
              qh_memfree(object: v7, size: 16);
            }
            else
            {
              qh_setappend(setp: &v5->ridges, newelem: v7);
              if ( toporient != 0 )
                v7->top = v5;
              else
                v7->bottom = v5;
            }
            if ( qh_qh.IStracing >= 4 )
              fprintf(
                str: qh_qh.ferr,
                format: "qh_makenew_nonsimplicial: created facet f%d from v%d and r%d of horizon f%d\n",
                v5->id,
                *((_DWORD *)apex + 5) & 0xFFFFFF,
                ridgeid,
                bottom->id);
          }
        }
        *((_DWORD *)bottom + 20) |= 0x2000u;
        e = ridgep;
        v7 = *ridgep;
        v3 = visible;
      }
      while ( *ridgep != nullptr );
    }
  }
  result = v5;
  if ( qh_qh.ONLYgood == 0 )
    v3->ridges->e[0].i = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004E6D0
// Name: struct facetT __near * qh_makenew_simplicial(struct facetT __near *,struct vertexT __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
facetT *__cdecl qh_makenew_simplicial(facetT *visible, vertexT *apex, int *numnew)
{
  setT *neighbors; // eax
  facetT **e; // eax
  facetT *v5; // esi
  setT *v6; // eax
  char v7; // bl
  char v8; // di
  int v9; // edi
  unsigned int v10; // ebx
  facetT *v11; // eax
  facetT **neighborp; // [esp+0h] [ebp-10h]
  facetT *newfacet; // [esp+4h] [ebp-Ch]
  int visibleskip; // [esp+8h] [ebp-8h] BYREF
  int horizonskip; // [esp+Ch] [ebp-4h] BYREF

  neighbors = visible->neighbors;
  newfacet = nullptr;
  horizonskip = 0;
  visibleskip = 0;
  if ( neighbors == nullptr )
    return nullptr;
  e = (facetT **)neighbors->e;
  v5 = *e;
  if ( *e == nullptr )
    return nullptr;
  do
  {
    neighborp = e + 1;
    if ( (*((_DWORD *)v5 + 20) & 0x2400) == 0 )
    {
      v6 = qh_facetintersect(facetA: v5, facetB: visible, skipA: &horizonskip, skipB: &visibleskip, prepend: 1);
      v7 = horizonskip;
      v8 = horizonskip ^ visibleskip;
      v6->e[0].i = (int)apex;
      v9 = v8 & 1;
      if ( (*((_DWORD *)v5 + 20) & 0x800) == 0 )
        v7 = ~v7;
      v10 = v7 & 1;
      v11 = qh_makenewfacet(vertices: v6, toporient: v10, horizon: v5);
      ++*numnew;
      newfacet = v11;
      if ( (*((_DWORD *)v5 + 20) & 0x800000) != 0 && (qh_qh.PREmerge != 0 || qh_qh.MERGEexact != 0) )
      {
        *((_DWORD *)v11 + 20) |= 0x1000000u;
        v11->f.replace = v11;
      }
      if ( qh_qh.ONLYgood == 0 )
        v5->neighbors->e[horizonskip].i = (int)v11;
      if ( qh_qh.IStracing >= 4 )
        fprintf(
          str: qh_qh.ferr,
          format: "qh_makenew_simplicial: create facet f%d top %d from v%d and horizon f%d skip %d top %d and visible f%d skip %d, flip? %d\n",
          v11->id,
          v10,
          *((_DWORD *)apex + 5) & 0xFFFFFF,
          v5->id,
          horizonskip,
          (*((_DWORD *)v5 + 20) & 0x800) != 0,
          visible->id,
          visibleskip,
          v9);
    }
    e = neighborp;
    v5 = *neighborp;
  }
  while ( *neighborp != nullptr );
  return newfacet;
}

//------------------------------------------------------------------------------
// Address: 0x1004E810
// Name: void qh_matchneighbor(struct facetT __near *,int,int,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_matchneighbor(facetT *newfacet, int newskip, int hashsize, int *hashcount)
{
  unsigned int v5; // ebx
  setT *hash_table; // eax
  setelemT v7; // esi
  int *v8; // eax
  int v9; // ebx
  int v10; // eax
  int v11; // ebx
  unsigned int ismatch; // [esp+Ch] [ebp-Ch]
  unsigned int ismatcha; // [esp+Ch] [ebp-Ch]
  unsigned int same; // [esp+10h] [ebp-8h] BYREF
  int skip; // [esp+14h] [ebp-4h] BYREF
  unsigned int hash; // [esp+20h] [ebp+8h]

  ismatch = 0;
  same = 0;
  skip = 0;
  v5 = qh_gethash(
         hashsize,
         set: newfacet->vertices,
         size: qh_qh.hull_dim,
         firstindex: 1,
         skipelem: newfacet->vertices->e[newskip].p);
  hash = v5;
  if ( qh_qh.IStracing >= 4 )
    fprintf(
      str: qh_qh.ferr,
      format: "qh_matchneighbor: newfacet f%d skip %d hash %d hashcount %d\n",
      newfacet->id,
      newskip,
      v5,
      *hashcount);
  ++qh_qhstat.stats[82].i;
  hash_table = qh_qh.hash_table;
  v7.p = (void *)qh_qh.hash_table->e[v5];
  if ( v7.i != 0 )
  {
    do
    {
      if ( v7.p == newfacet )
      {
        ismatch = 1;
      }
      else
      {
        ++qh_qhstat.stats[85].i;
        if ( qh_matchvertices(
               firstindex: (vertexT **)1,
               verticesA: newfacet->vertices,
               skipA: newskip,
               verticesB: *(setT **)(v7.i + 52),
               skipB: &skip,
               &same) != 0 )
        {
          if ( newfacet->vertices->e[newskip].i == *(_DWORD *)(*(_DWORD *)(v7.i + 52) + 4 * skip + 4) )
          {
            qh_precision(reason: "two facets with the same vertices");
            ivp_message(
              templat: "qhull precision error: Vertex sets are the same for f%d and f%d.  Can not force output.\n",
              *(_DWORD *)(v7.i + 76),
              newfacet->id);
            qh_errexit2(exitcode: 3, facet: (facetT *)v7.p, otherfacet: newfacet);
          }
          v8 = (int *)(*(_DWORD *)(v7.i + 60) + 4 * skip + 4);
          v9 = *v8;
          ismatcha = same == (((*((_DWORD *)newfacet + 20) ^ *(_DWORD *)(v7.i + 80)) & 0x800) != 0);
          if ( same != (((*((_DWORD *)newfacet + 20) ^ *(_DWORD *)(v7.i + 80)) & 0x800) != 0) || v9 != 0 )
          {
            if ( qh_qh.PREmerge == 0 && qh_qh.MERGEexact == 0 )
            {
              qh_precision(reason: "a ridge with more than two neighbors");
              if ( v9 != 0 )
                v10 = *(_DWORD *)(v9 + 76);
              else
                v10 = -1;
              ivp_message(
                templat: "qhull precision error: facets f%d, f%d and f%d meet at a ridge with more than 2 neighbors.  Can not continue.\n",
                *(_DWORD *)(v7.i + 76),
                newfacet->id,
                v10);
              qh_errexit2(exitcode: 3, facet: (facetT *)v7.p, otherfacet: newfacet);
            }
            newfacet->neighbors->e[newskip].i = 1;
            *((_DWORD *)newfacet + 20) |= 0x100000u;
            if ( newfacet->normal == nullptr )
              qh_setfacetplane(facet: newfacet);
            qh_addhash(newelem: newfacet, hashtable: qh_qh.hash_table, hashsize, hash);
            ++*hashcount;
            if ( *(_DWORD *)(v7.i + 24) == 0 )
              qh_setfacetplane(facet: (facetT *)v7.p);
            if ( v9 != 1 )
            {
              *(_DWORD *)(*(_DWORD *)(v7.i + 60) + 4 * skip + 4) = 1;
              *(_DWORD *)(v7.i + 80) |= 0x100000u;
              if ( *(_DWORD *)(v7.i + 24) == 0 )
                qh_setfacetplane(facet: (facetT *)v7.p);
              if ( v9 != 0 )
              {
                *(_DWORD *)(*(_DWORD *)(v9 + 60) + 4 * qh_setindex(set: *(setT **)(v9 + 60), atelem: v7.p) + 4) = 1;
                *(_DWORD *)(v9 + 80) |= 0x100000u;
                if ( *(_DWORD *)(v9 + 24) == 0 )
                  qh_setfacetplane(facet: (facetT *)v9);
                qh_addhash(newelem: (void *)v9, hashtable: qh_qh.hash_table, hashsize, hash);
                *hashcount += 2;
              }
            }
            if ( qh_qh.IStracing >= 4 )
            {
              if ( v9 == 1 )
              {
                v11 = -2;
              }
              else if ( v9 != 0 )
              {
                v11 = *(_DWORD *)(v9 + 76);
              }
              else
              {
                v11 = -1;
              }
              fprintf(
                str: qh_qh.ferr,
                format: "qh_matchneighbor: new f%d skip %d duplicates ridge for f%d skip %d matching f%d ismatch %d at hash %d\n",
                newfacet->id,
                newskip,
                *(_DWORD *)(v7.i + 76),
                skip,
                v11,
                ismatcha,
                hash);
            }
          }
          else
          {
            *v8 = (int)newfacet;
            newfacet->neighbors->e[newskip] = v7;
            --*hashcount;
            if ( qh_qh.IStracing >= 4 )
              fprintf(
                str: qh_qh.ferr,
                format: "qh_matchneighbor: f%d skip %d matched with new f%d skip %d\n",
                *(_DWORD *)(v7.i + 76),
                skip,
                newfacet->id,
                newskip);
          }
          return;
        }
        hash_table = qh_qh.hash_table;
      }
      v5 = (int)(v5 + 1) >= hashsize ? 0 : v5 + 1;
      v7.p = (void *)hash_table->e[v5];
    }
    while ( v7.i != 0 );
    if ( ismatch != 0 )
      goto LABEL_11;
  }
  hash_table->e[v5].i = (int)newfacet;
LABEL_11:
  ++*hashcount;
  if ( qh_qh.IStracing >= 4 )
    fprintf(
      str: qh_qh.ferr,
      format: "qh_matchneighbor: no match for f%d skip %d at hash %d\n",
      newfacet->id,
      newskip,
      hash);
}

//------------------------------------------------------------------------------
// Address: 0x1004EB40
// Name: void qh_matchnewfacets(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_matchnewfacets()
{
  int v0; // ebx
  int hull_dim; // edi
  facetT *i; // esi
  setT *neighbors; // eax
  int v4; // eax
  facetT *newfacet_list; // edi
  int v6; // ebx
  int v7; // eax
  int v8; // esi
  int v9; // eax
  facetT *v10; // edi
  setelemT v11; // ebx
  int v12; // esi
  int v13; // eax
  setT *hash_table; // edx
  setelemT v15; // esi
  int v16; // eax
  setelemT *e; // ecx
  int v18; // eax
  facetT *j; // esi
  int neighbor_n; // [esp+Ch] [ebp-14h]
  int hashsize; // [esp+10h] [ebp-10h]
  int numnew; // [esp+14h] [ebp-Ch]
  int numfree; // [esp+18h] [ebp-8h]
  int hashcount; // [esp+1Ch] [ebp-4h] BYREF

  v0 = 0;
  hull_dim = qh_qh.hull_dim;
  numnew = 0;
  hashcount = 0;
  numfree = 0;
  if ( qh_qh.IStracing >= 1 )
    fprintf(str: qh_qh.ferr, format: "qh_matchnewfacets: match neighbors for new facets.\n");
  for ( i = qh_qh.newfacet_list; i != nullptr; i = i->next )
  {
    if ( i->next == nullptr )
      break;
    neighbors = i->neighbors;
    neighbors->e[neighbors->maxsize].i = hull_dim + 1;
    numnew = ++v0;
    memset(dst: (unsigned __int8 *)&neighbors[1], value: 0, count: 4 * hull_dim);
  }
  qh_newhashtable(newsize: v0 * (qh_qh.hull_dim - 1));
  v4 = qh_setsize(set: qh_qh.hash_table);
  newfacet_list = qh_qh.newfacet_list;
  v6 = v4;
  hashsize = v4;
  if ( qh_qh.newfacet_list != nullptr )
  {
    v7 = qh_qh.hull_dim;
    do
    {
      if ( newfacet_list->next == nullptr )
        break;
      v8 = 1;
      if ( v7 > 1 )
      {
        do
        {
          qh_matchneighbor(newfacet: newfacet_list, newskip: v8, hashsize: v6, &hashcount);
          v7 = qh_qh.hull_dim;
          ++v8;
        }
        while ( v8 < qh_qh.hull_dim );
      }
      newfacet_list = newfacet_list->next;
    }
    while ( newfacet_list != nullptr );
  }
  v9 = hashcount;
  if ( hashcount != 0 )
  {
    v10 = qh_qh.newfacet_list;
    if ( qh_qh.newfacet_list != nullptr )
    {
      do
      {
        if ( v10->next == nullptr )
          break;
        if ( (*((_DWORD *)v10 + 20) & 0x100000) != 0 && v10->neighbors != nullptr )
        {
          v11.p = (void *)v10->neighbors->e[0];
          v12 = 0;
          v13 = qh_setsize(set: v10->neighbors);
          neighbor_n = v13;
          if ( v13 > 0 )
          {
            do
            {
              if ( v11.i == 1 )
              {
                qh_matchduplicates(atfacet: v10, atskip: v12, hashsize, &hashcount);
                v13 = neighbor_n;
              }
              v11.p = (void *)*(&v10->neighbors[1].maxsize + v12++);
            }
            while ( v12 < v13 );
          }
        }
        v10 = v10->next;
      }
      while ( v10 != nullptr );
      v9 = hashcount;
    }
    if ( v9 != 0 )
    {
      ivp_message(templat: "qhull internal error (qh_matchnewfacets): %d neighbors did not match up\n", v9);
      qh_printhashtable(fp: qh_qh.ferr);
      qh_errexit(exitcode: 5, facet: nullptr, ridge: nullptr);
    }
  }
  if ( qh_qh.IStracing >= 2 )
  {
    hash_table = qh_qh.hash_table;
    if ( qh_qh.hash_table != nullptr )
    {
      v15.p = (void *)qh_qh.hash_table->e[0];
      v16 = qh_setsize(set: qh_qh.hash_table);
      hash_table = qh_qh.hash_table;
      if ( v16 > 0 )
      {
        e = qh_qh.hash_table->e;
        do
        {
          if ( v15.i == 0 )
            ++numfree;
          v15.p = e[1].p;
          ++e;
          --v16;
        }
        while ( v16 != 0 );
      }
    }
    v18 = qh_setsize(set: hash_table);
    ivp_message(
      templat: "qh_matchnewfacets: %d new facets, %d unused hash entries .  hashsize %d\n",
      numnew,
      numfree,
      v18);
  }
  qh_setfree(setp: &qh_qh.hash_table);
  if ( qh_qh.PREmerge != 0 || qh_qh.MERGEexact != 0 )
  {
    if ( qh_qh.IStracing >= 4 )
      qh_printfacetlist(facetlist: qh_qh.newfacet_list, facets: nullptr, printall: 1u);
    for ( j = qh_qh.newfacet_list; j != nullptr; j = j->next )
    {
      if ( j->next == nullptr )
        break;
      if ( j->normal != nullptr )
        qh_checkflipped(facet: j, distp: nullptr, allerror: 1u);
    }
  }
  else if ( qh_qh.FORCEoutput != 0 )
  {
    qh_checkflipped_all(facetlist: qh_qh.newfacet_list);
  }
}
