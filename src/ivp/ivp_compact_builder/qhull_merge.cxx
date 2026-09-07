// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_compact_builder/qhull_merge.cxx
// Functions: 55
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10067E60
// Name: void qh_appendmergeset(struct facetT __near *,struct facetT __near *,enum mergeType,double __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_appendmergeset(facetT *facet, facetT *neighbor, mergeType mergetype, long double *angle)
{
  int v4; // eax
  void **v5; // eax
  char *v6; // esi
  int v7; // eax

  v4 = *((_DWORD *)facet + 20);
  if ( (v4 & 0x40000000) == 0 && ((v4 & 0x20000000) == 0 || mergetype != MRGdegen) )
  {
    v5 = &qhmem.freelists[qhmem.indextable[24]];
    v6 = (char *)*v5;
    if ( *v5 != nullptr )
    {
      ++qhmem.cntquick;
      *v5 = *(void **)*v5;
    }
    else
    {
      v6 = qh_memalloc(insize: 0x18u);
    }
    *((_DWORD *)v6 + 3) = neighbor;
    *((_DWORD *)v6 + 2) = facet;
    *((_DWORD *)v6 + 4) = mergetype;
    if ( angle != nullptr && qh_qh.ANGLEmerge != 0 )
      *(long double *)v6 = *angle;
    if ( mergetype < MRGdegen )
    {
      qh_setappend(setp: &qh_qh.facet_mergeset, newelem: v6);
      return;
    }
    if ( mergetype == MRGdegen )
    {
      *((_DWORD *)facet + 20) |= 0x20000000u;
      v7 = qh_setlast(set: qh_qh.degen_mergeset);
      if ( v7 != 0 && *(_DWORD *)(v7 + 16) != 6 )
      {
        qh_setaddnth(setp: &qh_qh.degen_mergeset, nth: 0, newelem: v6);
        return;
      }
    }
    else
    {
      *((_DWORD *)facet + 20) |= 0x40000000u;
    }
    qh_setappend(setp: &qh_qh.degen_mergeset, newelem: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10067F50
// Name: struct setT __near * qh_basevertices(struct facetT __near *)
// Source: json
//------------------------------------------------------------------------------
setT *__cdecl qh_basevertices(facetT *samecycle)
{
  setT *v1; // eax
  facetT *v2; // edx
  setT *v3; // ecx
  setelemT v4; // eax
  facetT *i; // ebx
  setT *v6; // eax
  _DWORD *p; // esi
  setelemT *e; // edi
  unsigned int vertex_visit; // ecx
  int v10; // eax
  setT *vertices; // [esp+4h] [ebp-4h] BYREF

  v1 = qh_settemp(setsize: qh_qh.TEMPsize);
  v2 = samecycle;
  v3 = samecycle->vertices;
  vertices = v1;
  v4.p = (void *)v3->e[0];
  *(_DWORD *)(v4.i + 16) = ++qh_qh.vertex_visit;
  for ( i = samecycle->f.replace; i != nullptr; i = i->f.replace )
  {
    if ( (*((_DWORD *)i + 20) & 0x200000) == 0 )
    {
      v6 = i->vertices;
      if ( v6 != nullptr )
      {
        p = v6->e[0].p;
        e = v6->e;
        if ( p != nullptr )
        {
          do
          {
            ++e;
            if ( p[4] != qh_qh.vertex_visit )
            {
              qh_setappend(setp: &vertices, newelem: p);
              vertex_visit = qh_qh.vertex_visit;
              p[5] &= ~0x1000000u;
              p[4] = vertex_visit;
            }
            p = (_DWORD *)e->i;
          }
          while ( e->i != 0 );
          v2 = samecycle;
        }
      }
    }
    if ( i == v2 )
      break;
  }
  if ( qh_qh.IStracing >= 4 )
  {
    v10 = qh_setsize(set: vertices);
    fprintf(str: qh_qh.ferr, format: "qh_basevertices: found %d vertices\n", v10);
  }
  return vertices;
}

//------------------------------------------------------------------------------
// Address: 0x10068020
// Name: unsigned int qh_checkzero(unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl qh_checkzero(unsigned int testall)
{
  facetT *facet_list; // edx
  facetT *v2; // ecx
  facetT *p; // ebx
  setT *neighbors; // eax
  int v5; // edi
  facetT **e; // eax
  facetT *i; // eax
  setelemT v9; // esi
  double v10; // xmm0_8
  setT *vertices; // eax
  setelemT *v12; // eax
  const char *v13; // eax
  double dist; // [esp+14h] [ebp-14h] BYREF
  facetT **neighborp; // [esp+1Ch] [ebp-Ch]
  facetT *horizon; // [esp+20h] [ebp-8h]
  facetT *facet; // [esp+24h] [ebp-4h]

  if ( testall != 0 )
  {
    facet_list = qh_qh.facet_list;
  }
  else
  {
    facet_list = qh_qh.newfacet_list;
    if ( qh_qh.newfacet_list != nullptr )
    {
      for ( i = qh_qh.newfacet_list; i->next != nullptr; i = i->next )
      {
        if ( (*(_DWORD *)(i->neighbors->e[0].i + 80) & 0x1000) == 0
          || (*((_DWORD *)i + 20) & 0x108000) != 0
          || i->normal == nullptr )
        {
          qh_qh.ZEROall_ok = 0;
          if ( qh_qh.IStracing >= 2 )
            fprintf(str: qh_qh.ferr, format: "qh_checkzero: facet f%d needs pre-merging\n", i->id);
          return 0;
        }
      }
    }
    if ( qh_qh.MERGEexact != 0 && qh_qh.ZEROall_ok != 0 )
    {
      if ( qh_qh.IStracing >= 2 )
        fprintf(str: qh_qh.ferr, format: "qh_checkzero: skip convexity check until first pre-merge\n");
      return 1;
    }
  }
  if ( facet_list != nullptr )
  {
    for ( facet = facet_list; facet != nullptr; facet = facet->next )
    {
      v2 = facet;
      p = nullptr;
      if ( facet->next == nullptr )
        break;
      ++qh_qh.vertex_visit;
      neighbors = facet->neighbors;
      v5 = 0;
      horizon = nullptr;
      if ( neighbors != nullptr )
      {
        p = (facetT *)neighbors->e[0].p;
        e = (facetT **)neighbors->e;
        if ( p != nullptr )
        {
          do
          {
            neighborp = e + 1;
            if ( v5 != 0 || testall != 0 )
            {
              v9.p = (void *)v2->vertices->e[v5];
              *(_DWORD *)(v9.i + 16) = qh_qh.vertex_visit;
              ++qh_qhstat.stats[55].i;
              ++v5;
              qh_distplane(point: *(long double **)(v9.i + 8), facet: p, &dist);
              v10 = dist;
              if ( dist >= -qh_qh.DISTround )
              {
                qh_qh.ZEROall_ok = 0;
                if ( qh_qh.MERGEexact == 0 || testall != 0 || dist > qh_qh.DISTround )
                  goto LABELnonconvex;
              }
            }
            else
            {
              horizon = p;
              v5 = 1;
            }
            e = neighborp;
            p = *neighborp;
            v2 = facet;
          }
          while ( *neighborp != nullptr );
        }
      }
      if ( testall == 0 )
      {
        vertices = horizon->vertices;
        if ( vertices != nullptr )
        {
          v9.p = (void *)vertices->e[0];
          v12 = vertices->e;
          if ( v9.i != 0 )
          {
            while ( 1 )
            {
              ++v12;
              if ( *(_DWORD *)(v9.i + 16) != qh_qh.vertex_visit )
                break;
              v9.p = v12->p;
              if ( v12->i == 0 )
                goto LABEL_40;
            }
            ++qh_qhstat.stats[55].i;
            qh_distplane(point: *(long double **)(v9.i + 8), facet: v2, &dist);
            v10 = dist;
            if ( dist >= -qh_qh.DISTround )
            {
              qh_qh.ZEROall_ok = 0;
              if ( qh_qh.MERGEexact == 0 || dist > qh_qh.DISTround )
              {
LABELnonconvex:
                if ( qh_qh.IStracing >= 2 )
                  fprintf(
                    str: qh_qh.ferr,
                    format: "qh_checkzero: facet f%d and f%d are not clearly convex.  v%d dist %.2g\n",
                    facet->id,
                    p->id,
                    *(_DWORD *)(v9.i + 20) & 0xFFFFFF,
                    v10);
                return 0;
              }
            }
          }
        }
      }
LABEL_40:
      ;
    }
  }
  if ( qh_qh.IStracing >= 2 )
  {
    if ( qh_qh.MERGEexact == 0 || (v13 = "not concave, flipped, or duplicate ridged", testall != 0) )
      v13 = "clearly convex";
    fprintf(str: qh_qh.ferr, format: "qh_checkzero: testall %d, facets are %s\n", testall, v13);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100682E0
// Name: qh_compareangle
// Source: json
//------------------------------------------------------------------------------
int __cdecl qh_compareangle(double **p1, double **p2)
{
  if ( **p1 <= **p2 )
    return -1;
  else
    return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10068310
// Name: qh_comparevisit
// Source: json
//------------------------------------------------------------------------------
int __cdecl qh_comparevisit(const void *p1, const void *p2)
{
  return *(_DWORD *)(*(_DWORD *)p1 + 16) - *(_DWORD *)(*(_DWORD *)p2 + 16);
}

//------------------------------------------------------------------------------
// Address: 0x10068330
// Name: void qh_copynonconvex(struct ridgeT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_copynonconvex(ridgeT *atridge)
{
  facetT *top; // esi
  setT *ridges; // eax
  setelemT *e; // edx
  setelemT v4; // eax
  facetT *v5; // ecx
  int v6; // eax

  top = atridge->top;
  ridges = top->ridges;
  if ( ridges != nullptr )
  {
    e = ridges->e;
    v4.p = (void *)ridges->e[0];
    if ( v4.i != 0 )
    {
      while ( 1 )
      {
        v5 = *(facetT **)(v4.i + 4);
        ++e;
        if ( v5 == top )
          v5 = *(facetT **)(v4.i + 8);
        if ( atridge->bottom == v5 && v4.p != atridge )
          break;
        v4.p = e->p;
        if ( e->i == 0 )
          return;
      }
      *(_DWORD *)(v4.i + 12) |= 0x4000000u;
      v6 = *(_DWORD *)(v4.i + 12);
      if ( qh_qh.IStracing >= 4 )
        fprintf(
          str: qh_qh.ferr,
          format: "qh_copynonconvex: moved nonconvex flag from r%d to r%d\n",
          *((_DWORD *)atridge + 3) & 0xFFFFFF,
          v6 & 0xFFFFFF);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100683B0
// Name: void qh_degen_redundant_facet(struct facetT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_degen_redundant_facet(facetT *facet)
{
  setT *neighbors; // eax
  facetT *p; // esi
  facetT **v3; // edi
  unsigned int vertex_visit; // edx
  setT *vertices; // eax
  setelemT *e; // ecx
  setelemT v7; // eax
  setT *v8; // eax
  setelemT *v9; // ecx
  setelemT v10; // eax

  if ( qh_qh.IStracing >= 4 )
    fprintf(str: qh_qh.ferr, format: "qh_degen_redundant_facet: test facet f%d for degen/redundant\n", facet->id);
  neighbors = facet->neighbors;
  if ( neighbors != nullptr && (p = (facetT *)neighbors->e[0].p, v3 = (facetT **)neighbors->e, p != nullptr) )
  {
    vertex_visit = qh_qh.vertex_visit;
    while ( 1 )
    {
      qh_qh.vertex_visit = ++vertex_visit;
      vertices = p->vertices;
      ++v3;
      if ( vertices != nullptr )
      {
        e = vertices->e;
        v7.p = (void *)vertices->e[0];
        if ( v7.i != 0 )
        {
          do
          {
            ++e;
            *(_DWORD *)(v7.i + 16) = vertex_visit;
            v7.p = e->p;
            vertex_visit = qh_qh.vertex_visit;
          }
          while ( e->i != 0 );
        }
      }
      v8 = facet->vertices;
      if ( v8 == nullptr )
        break;
      v9 = v8->e;
      v10.p = (void *)v8->e[0];
      if ( v10.i == 0 )
        break;
      while ( 1 )
      {
        ++v9;
        if ( *(_DWORD *)(v10.i + 16) != vertex_visit )
          break;
        v10.p = v9->p;
        if ( v9->i == 0 )
          goto LABEL_13;
      }
      p = *v3;
      if ( *v3 == nullptr )
        goto LABEL_16;
    }
LABEL_13:
    qh_appendmergeset(facet, neighbor: p, mergetype: MRGredundant, angle: nullptr);
    if ( qh_qh.IStracing >= 2 )
      fprintf(str: qh_qh.ferr, format: "qh_degen_redundant_facet: f%d is contained in f%d.  merge\n", facet->id, p->id);
  }
  else
  {
LABEL_16:
    if ( qh_setsize(set: facet->neighbors) < qh_qh.hull_dim )
    {
      qh_appendmergeset(facet, neighbor: facet, mergetype: MRGdegen, angle: nullptr);
      if ( qh_qh.IStracing >= 2 )
        fprintf(str: qh_qh.ferr, format: "qh_degen_redundant_neighbors: f%d is degenerate.\n", facet->id);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100684E0
// Name: void qh_degen_redundant_neighbors(struct facetT __near *,struct facetT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_degen_redundant_neighbors(facetT *facet, facetT *delfacet)
{
  unsigned int id; // eax
  facetT *v3; // edi
  int v4; // esi
  setT *vertices; // eax
  setelemT *e; // ecx
  setelemT v7; // eax
  setT *neighbors; // eax
  facetT *p; // esi
  facetT **v10; // ebx
  setT *v11; // eax
  setelemT *v12; // ecx
  setelemT v13; // eax
  setT *v14; // ebx
  facetT *v15; // esi
  facetT **v16; // ebx
  int v17; // edi

  if ( qh_qh.IStracing < 4 )
  {
    v3 = facet;
  }
  else
  {
    if ( delfacet != nullptr )
      id = delfacet->id;
    else
      id = -1;
    v3 = facet;
    fprintf(
      str: qh_qh.ferr,
      format: "qh_degen_redundant_neighbors: test neighbors of f%d with delfacet f%d\n",
      facet->id,
      id);
  }
  v4 = qh_setsize(set: v3->neighbors);
  if ( v4 < qh_qh.hull_dim )
  {
    qh_appendmergeset(facet: v3, neighbor: v3, mergetype: MRGdegen, angle: nullptr);
    if ( qh_qh.IStracing >= 2 )
      fprintf(
        str: qh_qh.ferr,
        format: "qh_degen_redundant_neighbors: f%d is degenerate with %d neighbors.\n",
        v3->id,
        v4);
  }
  if ( delfacet == nullptr )
    delfacet = v3;
  ++qh_qh.vertex_visit;
  vertices = v3->vertices;
  if ( vertices != nullptr )
  {
    e = vertices->e;
    v7.p = (void *)vertices->e[0];
    if ( v7.i != 0 )
    {
      do
      {
        ++e;
        *(_DWORD *)(v7.i + 16) = qh_qh.vertex_visit;
        v7.p = e->p;
      }
      while ( e->i != 0 );
    }
  }
  neighbors = delfacet->neighbors;
  if ( neighbors != nullptr )
  {
    p = (facetT *)neighbors->e[0].p;
    v10 = (facetT **)neighbors->e;
    if ( p != nullptr )
    {
      do
      {
        ++v10;
        if ( p != v3 )
        {
          v11 = p->vertices;
          if ( v11 != nullptr && (v12 = v11->e, v13.p = (void *)v11->e[0], v13.i != 0) )
          {
            while ( 1 )
            {
              ++v12;
              if ( *(_DWORD *)(v13.i + 16) != qh_qh.vertex_visit )
                break;
              v13.p = v12->p;
              if ( v12->i == 0 )
                goto LABEL_22;
            }
          }
          else
          {
LABEL_22:
            qh_appendmergeset(facet: p, neighbor: v3, mergetype: MRGredundant, angle: nullptr);
            if ( qh_qh.IStracing >= 2 )
              fprintf(
                str: qh_qh.ferr,
                format: "qh_degen_redundant_neighbors: f%d is contained in f%d.  merge\n",
                p->id,
                v3->id);
          }
        }
        p = *v10;
      }
      while ( *v10 != nullptr );
    }
  }
  v14 = delfacet->neighbors;
  if ( v14 != nullptr )
  {
    v15 = (facetT *)v14->e[0].p;
    v16 = (facetT **)v14->e;
    if ( v15 != nullptr )
    {
      do
      {
        ++v16;
        if ( v15 != v3 )
        {
          v17 = qh_setsize(set: v15->neighbors);
          if ( v17 < qh_qh.hull_dim )
          {
            qh_appendmergeset(facet: v15, neighbor: v15, mergetype: MRGdegen, angle: nullptr);
            if ( qh_qh.IStracing >= 2 )
              fprintf(
                str: qh_qh.ferr,
                format: "qh_degen_redundant_neighbors: f%d is degenerate with %d neighbors.  Neighbor of f%d.\n",
                v15->id,
                v17,
                facet->id);
          }
          v3 = facet;
        }
        v15 = *v16;
      }
      while ( *v16 != nullptr );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100686A0
// Name: void qh_findbest_test(unsigned int,struct facetT __near *,struct facetT __near *,struct facetT __near * __near *,double __near *,double __near *,double __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_findbest_test(
        unsigned int testcentrum,
        facetT *facet,
        facetT *neighbor,
        facetT **bestfacet,
        long double *distp,
        long double *mindistp,
        long double *maxdistp)
{
  double v7; // xmm1_8
  double v8; // xmm0_8
  long double v9; // xmm2_8
  double maxdist; // [esp+4h] [ebp-18h] BYREF
  long double mindist; // [esp+Ch] [ebp-10h] BYREF
  double dist; // [esp+14h] [ebp-8h] BYREF

  if ( testcentrum != 0 )
  {
    ++qh_qhstat.stats[16].i;
    qh_distplane(point: facet->center, facet: neighbor, &dist);
    v7 = 0.0;
    v8 = (double)qh_qh.hull_dim * dist;
    if ( v8 >= 0.0 )
    {
      v7 = (double)qh_qh.hull_dim * dist;
    }
    else
    {
      mindist = (double)qh_qh.hull_dim * dist;
      v8 = -v8;
    }
  }
  else
  {
    dist = qh_getdistance(facet, neighbor, &mindist, &maxdist);
    v8 = dist;
    v7 = maxdist;
  }
  if ( *distp > v8 )
  {
    v9 = mindist;
    *bestfacet = neighbor;
    *mindistp = v9;
    *maxdistp = v7;
    *distp = v8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10068750
// Name: struct facetT __near * qh_findbestneighbor(struct facetT __near *,double __near *,double __near *,double __near *)
// Source: json
//------------------------------------------------------------------------------
facetT *__cdecl qh_findbestneighbor(facetT *facet, long double *distp, long double *mindistp, long double *maxdistp)
{
  unsigned int v4; // ebx
  int v5; // eax
  int v6; // edi
  setT *ridges; // eax
  setelemT *e; // edi
  _DWORD *p; // eax
  facetT *v10; // eax
  setT *neighbors; // eax
  facetT **v12; // edi
  facetT *v13; // eax
  facetT *v14; // edi
  setT *vertices; // [esp+14h] [ebp-18h]
  unsigned int nonconvex; // [esp+24h] [ebp-8h]
  facetT *bestfacet; // [esp+28h] [ebp-4h] BYREF

  v4 = 0;
  vertices = facet->vertices;
  bestfacet = nullptr;
  nonconvex = 1;
  v5 = qh_setsize(set: vertices);
  *distp = 1.797693134862316e308;
  v6 = v5;
  if ( v5 > 2 * qh_qh.hull_dim + 20 )
  {
    v4 = 1;
    ++qh_qhstat.stats[15].i;
    if ( facet->center == nullptr )
      facet->center = qh_getcentrum(facet);
  }
  if ( v6 <= qh_qh.hull_dim + 15 )
    goto LABEL_14;
  ridges = facet->ridges;
  if ( ridges == nullptr )
    goto LABEL_14;
  e = ridges->e;
  p = ridges->e[0].p;
  if ( p == nullptr )
    goto LABEL_14;
  do
  {
    ++e;
    if ( (p[3] & 0x4000000) != 0 )
    {
      if ( (facetT *)p[1] == facet )
        v10 = (facetT *)p[2];
      else
        v10 = (facetT *)p[1];
      qh_findbest_test(testcentrum: v4, facet, neighbor: v10, &bestfacet, distp, mindistp, maxdistp);
    }
    p = (_DWORD *)e->i;
  }
  while ( e->i != 0 );
  if ( bestfacet == nullptr )
  {
LABEL_14:
    neighbors = facet->neighbors;
    nonconvex = 0;
    if ( neighbors == nullptr )
      goto LABEL_18;
    v12 = (facetT **)neighbors->e;
    v13 = (facetT *)neighbors->e[0].p;
    if ( v13 == nullptr )
      goto LABEL_18;
    do
    {
      ++v12;
      qh_findbest_test(testcentrum: v4, facet, neighbor: v13, &bestfacet, distp, mindistp, maxdistp);
      v13 = *v12;
    }
    while ( *v12 != nullptr );
    if ( bestfacet == nullptr )
    {
LABEL_18:
      ivp_message(templat: "qhull internal error (qh_findbestneighbor): no neighbors for f%d\n", facet->id);
      qh_errexit(exitcode: 5, facet, ridge: nullptr);
    }
  }
  v14 = bestfacet;
  if ( v4 != 0 )
    qh_getdistance(facet, neighbor: bestfacet, mindist: mindistp, maxdist: maxdistp);
  if ( qh_qh.IStracing >= 3 )
    fprintf(
      str: qh_qh.ferr,
      format: "qh_findbestneighbor: f%d is best neighbor for f%d testcentrum? %d nonconvex? %d dist %2.2g min %2.2g max %2.2g\n",
      v14->id,
      facet->id,
      v4,
      nonconvex,
      (double)*distp,
      (double)*mindistp,
      (double)*maxdistp);
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x100688F0
// Name: void qh_hashridge(struct setT __near *,int,struct ridgeT __near *,struct vertexT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_hashridge(setT *hashtable, unsigned int hashsize, ridgeT *ridge, vertexT *oldvertex)
{
  unsigned int v4; // eax
  ridgeT *p; // ecx

  v4 = qh_gethash(hashsize, set: ridge->vertices, size: qh_qh.hull_dim - 1, firstindex: 0, skipelem: oldvertex);
  p = (ridgeT *)hashtable->e[v4].p;
  if ( p != nullptr )
  {
    while ( p != ridge )
    {
      if ( ++v4 == hashsize )
        v4 = 0;
      p = (ridgeT *)hashtable->e[v4].p;
      if ( p == nullptr )
        goto LABEL_6;
    }
  }
  else
  {
LABEL_6:
    hashtable->e[v4].i = (int)ridge;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10068940
// Name: struct ridgeT __near * qh_hashridge_find(struct setT __near *,int,struct ridgeT __near *,struct vertexT __near *,struct vertexT __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
ridgeT *__cdecl qh_hashridge_find(
        setT *hashtable,
        unsigned int hashsize,
        ridgeT *ridge,
        vertexT *vertex,
        vertexT *oldvertex,
        int *hashslot)
{
  unsigned int v6; // edi
  ridgeT *i; // esi

  *hashslot = 0;
  ++qh_qhstat.stats[83].i;
  v6 = qh_gethash(hashsize, set: ridge->vertices, size: qh_qh.hull_dim - 1, firstindex: 0, skipelem: vertex);
  for ( i = (ridgeT *)hashtable->e[v6].p; i != nullptr; i = (ridgeT *)hashtable->e[v6].p )
  {
    if ( i == ridge )
    {
      *hashslot = -1;
    }
    else
    {
      ++qh_qhstat.stats[84].i;
      if ( qh_setequal_except(setA: ridge->vertices, skipelemA: vertex, setB: i->vertices, skipelemB: oldvertex) )
        return i;
    }
    if ( ++v6 == hashsize )
      v6 = 0;
  }
  if ( *hashslot == 0 )
    *hashslot = v6;
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100689E0
// Name: void qh_makeridges(struct facetT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_makeridges(facetT *facet)
{
  int v2; // ebx
  setT *neighbors; // eax
  setelemT *e; // ecx
  setelemT v5; // eax
  setT *ridges; // eax
  setelemT *v7; // ecx
  setelemT v8; // eax
  int v9; // eax
  setT *v10; // eax
  setelemT v11; // esi
  int v12; // eax
  ridgeT *v13; // esi
  facetT *v14; // ecx
  int neighbor_n; // [esp+8h] [ebp-8h]
  unsigned int mergeridge; // [esp+Ch] [ebp-4h]
  facetT *neighbor; // [esp+18h] [ebp+8h]

  v2 = 0;
  mergeridge = 0;
  if ( (*((_DWORD *)facet + 20) & 0x1000) != 0 )
  {
    if ( qh_qh.IStracing >= 4 )
      fprintf(str: qh_qh.ferr, format: "qh_makeridges: make ridges for f%d\n", facet->id);
    neighbors = facet->neighbors;
    *((_DWORD *)facet + 20) &= ~0x1000u;
    if ( neighbors != nullptr )
    {
      e = neighbors->e;
      v5.p = (void *)neighbors->e[0];
      if ( v5.i != 0 )
      {
        do
        {
          ++e;
          if ( v5.i == 2 )
            mergeridge = 1;
          else
            *(_DWORD *)(v5.i + 80) &= ~0x2000u;
          v5.p = e->p;
        }
        while ( e->i != 0 );
      }
    }
    ridges = facet->ridges;
    if ( ridges != nullptr )
    {
      v7 = ridges->e;
      v8.p = (void *)ridges->e[0];
      if ( v8.i != 0 )
      {
        do
        {
          ++v7;
          if ( *(facetT **)(v8.i + 4) == facet )
            v9 = *(_DWORD *)(v8.i + 8);
          else
            v9 = *(_DWORD *)(v8.i + 4);
          *(_DWORD *)(v9 + 80) |= 0x2000u;
          v8.p = v7->p;
        }
        while ( v7->i != 0 );
      }
    }
    v10 = facet->neighbors;
    if ( v10 != nullptr )
    {
      v11.p = (void *)v10->e[0];
      neighbor = (facetT *)v11.i;
      v12 = qh_setsize(set: v10);
      neighbor_n = v12;
      if ( v12 > 0 )
      {
        while ( 1 )
        {
          if ( v11.i != 2 && (*(_DWORD *)(v11.i + 80) & 0x2000) == 0 )
          {
            v13 = qh_newridge();
            v13->vertices = qh_setnew_delnthsorted(
                              set: facet->vertices,
                              size: (setT *)qh_qh.hull_dim,
                              nth: v2,
                              prepend: 0);
            if ( (((unsigned __int8)v2 ^ (unsigned __int8)(*((_DWORD *)facet + 20) >> 11)) & 1) != 0 )
            {
              v13->top = facet;
              v13->bottom = neighbor;
            }
            else
            {
              v13->top = neighbor;
              v13->bottom = facet;
            }
            qh_setappend(setp: &facet->ridges, newelem: v13);
            qh_setappend(setp: &neighbor->ridges, newelem: v13);
            v12 = neighbor_n;
          }
          v14 = (facetT *)*(&facet->neighbors[1].maxsize + v2++);
          neighbor = v14;
          if ( v2 >= v12 )
            break;
          v11.i = (int)v14;
        }
      }
    }
    if ( mergeridge != 0 )
    {
      while ( qh_setdel(set: facet->neighbors, oldelem: (void *)2) != nullptr )
        ;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10068B50
// Name: void qh_mark_dupridges(struct facetT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_mark_dupridges(facetT *facetlist)
{
  facetT *v1; // esi
  setT *neighbors; // eax
  setelemT v3; // edi
  setelemT *e; // ebx
  facetT *i; // esi
  int v6; // eax
  setelemT v7; // esi
  setelemT *v8; // edi
  int nummerge; // [esp+0h] [ebp-4h]

  nummerge = 0;
  if ( qh_qh.IStracing >= 4 )
    fprintf(str: qh_qh.ferr, format: "qh_mark_dupridges: identify duplicate ridges\n");
  v1 = facetlist;
  if ( facetlist != nullptr )
  {
    do
    {
      if ( v1->next == nullptr )
        break;
      if ( (*((_DWORD *)v1 + 20) & 0x100000) != 0 )
      {
        neighbors = v1->neighbors;
        if ( neighbors != nullptr )
        {
          v3.p = (void *)neighbors->e[0];
          e = neighbors->e;
          if ( v3.i != 0 )
          {
            do
            {
              ++e;
              if ( v3.i == 2 )
              {
                *((_DWORD *)v1 + 20) |= 0x200000u;
              }
              else if ( (*(_DWORD *)(v3.i + 80) & 0x100000) != 0
                     && qh_setin(set: *(setT **)(v3.i + 60), setelem: v1) == 0 )
              {
                qh_appendmergeset(facet: v1, neighbor: (facetT *)v3.p, mergetype: MRGridge, angle: nullptr);
                *((_DWORD *)v1 + 20) |= 0x600000u;
                ++nummerge;
              }
              v3.p = e->p;
            }
            while ( e->i != 0 );
          }
        }
      }
      v1 = v1->next;
    }
    while ( v1 != nullptr );
    if ( nummerge != 0 )
    {
      for ( i = facetlist; i != nullptr; i = i->next )
      {
        if ( i->next == nullptr )
          break;
        v6 = *((_DWORD *)i + 20);
        if ( (v6 & 0x200000) != 0 && (v6 & 0x400000) == 0 )
          qh_makeridges(facet: i);
      }
      if ( qh_qh.facet_mergeset != nullptr )
      {
        v7.p = (void *)qh_qh.facet_mergeset->e[0];
        v8 = qh_qh.facet_mergeset->e;
        if ( v7.i != 0 )
        {
          do
          {
            ++v8;
            if ( *(_DWORD *)(v7.i + 16) == 5 )
            {
              qh_setappend(setp: (setT **)(*(_DWORD *)(v7.i + 12) + 60), newelem: *(void **)(v7.i + 8));
              qh_makeridges(facet: *(facetT **)(v7.i + 8));
            }
            v7.p = v8->p;
          }
          while ( v8->i != 0 );
        }
      }
      if ( qh_qh.IStracing >= 1 )
        fprintf(str: qh_qh.ferr, format: "qh_mark_dupridges: found %d duplicated ridges\n", nummerge);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10068C90
// Name: void qh_maydropneighbor(struct facetT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_maydropneighbor(facetT *facet)
{
  setT *ridges; // ecx
  setelemT v2; // eax
  setelemT *e; // ecx
  setT *neighbors; // eax
  facetT *p; // esi
  facetT **v6; // ebx
  double angledegen; // [esp+0h] [ebp-8h] BYREF

  ++qh_qh.visit_id;
  angledegen = 5.0;
  if ( qh_qh.IStracing >= 4 )
    fprintf(str: qh_qh.ferr, format: "qh_maydropneighbor: test f%d for no ridges to a neighbor\n", facet->id);
  ridges = facet->ridges;
  if ( ridges != nullptr )
  {
    v2.p = (void *)ridges->e[0];
    e = ridges->e;
    if ( v2.i != 0 )
    {
      do
      {
        *(_DWORD *)(*(_DWORD *)(v2.i + 4) + 72) = qh_qh.visit_id;
        ++e;
        *(_DWORD *)(*(_DWORD *)(v2.i + 8) + 72) = qh_qh.visit_id;
        v2.p = e->p;
      }
      while ( e->i != 0 );
    }
  }
  neighbors = facet->neighbors;
  if ( neighbors != nullptr )
  {
    p = (facetT *)neighbors->e[0].p;
    v6 = (facetT **)neighbors->e;
    if ( p != nullptr )
    {
      do
      {
        ++v6;
        if ( p->visitid != qh_qh.visit_id )
        {
          if ( qh_qh.IStracing != 0 )
            fprintf(
              str: qh_qh.ferr,
              format: "qh_maydropneighbor: facets f%d and f%d are no longer neighbors during p%d\n",
              facet->id,
              p->id,
              qh_qh.furthest_id);
          ++qh_qhstat.stats[68].i;
          qh_setdel(set: facet->neighbors, oldelem: p);
          --v6;
          qh_setdel(set: p->neighbors, oldelem: facet);
          if ( qh_setsize(set: p->neighbors) < qh_qh.hull_dim )
          {
            ++qh_qhstat.stats[67].i;
            qh_appendmergeset(facet: p, neighbor: p, mergetype: MRGdegen, angle: &angledegen);
            if ( qh_qh.IStracing >= 2 )
              fprintf(str: qh_qh.ferr, format: "qh_maydropneighbors: f%d is degenerate.\n", p->id);
          }
        }
        p = *v6;
      }
      while ( *v6 != nullptr );
    }
  }
  if ( qh_setsize(set: facet->neighbors) < qh_qh.hull_dim )
  {
    ++qh_qhstat.stats[67].i;
    qh_appendmergeset(facet, neighbor: facet, mergetype: MRGdegen, angle: &angledegen);
    if ( qh_qh.IStracing >= 2 )
      fprintf(str: qh_qh.ferr, format: "qh_maydropneighbors: f%d is degenerate.\n", facet->id);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10068E30
// Name: void qh_mergecycle_neighbors(struct facetT __near *,struct facetT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_mergecycle_neighbors(facetT *samecycle, facetT *newfacet)
{
  unsigned int v2; // ebx
  facetT *replace; // esi
  facetT *v4; // edi
  setT *neighbors; // eax
  setelemT *e; // ecx
  setelemT v7; // eax
  int v8; // edx
  facetT *i; // ebx
  setT *v10; // eax
  facetT *p; // esi
  facetT **v12; // eax
  unsigned int visitid; // eax
  setT *ridges; // esi
  setelemT v15; // eax
  setelemT *v16; // ecx
  facetT **neighborp; // [esp+Ch] [ebp-10h]
  unsigned int samevisitid; // [esp+10h] [ebp-Ch]
  int delneighbors; // [esp+14h] [ebp-8h]
  int newneighbors; // [esp+18h] [ebp-4h]

  v2 = qh_qh.visit_id + 1;
  qh_qh.visit_id = v2;
  replace = samecycle->f.replace;
  delneighbors = 0;
  newneighbors = 0;
  for ( samevisitid = v2; replace != nullptr; replace = replace->f.replace )
  {
    if ( replace->visitid == v2 || (*((_DWORD *)replace + 20) & 0x400) != 0 )
      qh_infiniteloop(facet: samecycle);
    replace->visitid = v2;
    if ( replace == samecycle )
      break;
  }
  v4 = newfacet;
  newfacet->visitid = ++qh_qh.visit_id;
  if ( qh_qh.IStracing >= 4 )
    fprintf(str: qh_qh.ferr, format: "qh_mergecycle_neighbors: delete shared neighbors from newfacet\n");
  neighbors = newfacet->neighbors;
  if ( neighbors != nullptr )
  {
    e = neighbors->e;
    v7.p = (void *)neighbors->e[0];
    if ( v7.i != 0 )
    {
      v8 = 0;
      do
      {
        ++e;
        if ( *(_DWORD *)(v7.i + 72) == v2 )
        {
          e[-1].i = 0;
          ++v8;
        }
        else
        {
          *(_DWORD *)(v7.i + 72) = qh_qh.visit_id;
        }
        v7.p = e->p;
      }
      while ( e->i != 0 );
      delneighbors = v8;
    }
  }
  qh_setcompact(set: newfacet->neighbors);
  if ( qh_qh.IStracing >= 4 )
    fprintf(str: qh_qh.ferr, format: "qh_mergecycle_neighbors: update neighbors\n");
  for ( i = samecycle->f.replace; i != nullptr; i = i->f.replace )
  {
    v10 = i->neighbors;
    if ( v10 != nullptr )
    {
      p = (facetT *)v10->e[0].p;
      v12 = (facetT **)v10->e;
      if ( p != nullptr )
      {
        do
        {
          neighborp = v12 + 1;
          visitid = p->visitid;
          if ( visitid != samevisitid )
          {
            if ( (*((_DWORD *)p + 20) & 0x1000) != 0 )
            {
              if ( visitid == qh_qh.visit_id )
              {
                qh_makeridges(facet: p);
                qh_setdel(set: p->neighbors, oldelem: i);
              }
              else
              {
                qh_setappend(setp: &v4->neighbors, newelem: p);
                qh_setreplace(set: p->neighbors, oldelem: i, newelem: v4);
                ++newneighbors;
                p->visitid = qh_qh.visit_id;
                ridges = p->ridges;
                if ( ridges != nullptr )
                {
                  v15.p = (void *)ridges->e[0];
                  v16 = ridges->e;
                  if ( v15.i != 0 )
                  {
                    while ( 1 )
                    {
                      ++v16;
                      if ( *(facetT **)(v15.i + 4) == i )
                      {
                        *(_DWORD *)(v15.i + 4) = v4;
                        goto LABEL_37;
                      }
                      if ( *(facetT **)(v15.i + 8) == i )
                        break;
                      v15.p = v16->p;
                      if ( v16->i == 0 )
                        goto LABEL_37;
                    }
                    *(_DWORD *)(v15.i + 8) = v4;
                  }
                }
              }
            }
            else
            {
              qh_setdel(set: p->neighbors, oldelem: i);
              if ( p->visitid != qh_qh.visit_id )
              {
                qh_setappend(setp: &p->neighbors, newelem: newfacet);
                qh_setappend(setp: &newfacet->neighbors, newelem: p);
                ++newneighbors;
                p->visitid = qh_qh.visit_id;
              }
              v4 = newfacet;
            }
          }
LABEL_37:
          v12 = neighborp;
          p = *neighborp;
        }
        while ( *neighborp != nullptr );
      }
    }
    if ( i == samecycle )
      break;
  }
  if ( qh_qh.IStracing >= 2 )
    fprintf(
      str: qh_qh.ferr,
      format: "qh_mergecycle_neighbors: deleted %d neighbors and added %d\n",
      delneighbors,
      newneighbors);
}

//------------------------------------------------------------------------------
// Address: 0x10069060
// Name: void qh_mergecycle_ridges(struct facetT __near *,struct facetT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_mergecycle_ridges(facetT *samecycle, facetT *newfacet)
{
  facetT *v2; // edi
  setT *ridges; // eax
  unsigned int v4; // edx
  setelemT *e; // ecx
  setelemT v6; // eax
  facetT *v7; // ebx
  facetT *replace; // edx
  setT *v9; // eax
  ridgeT *p; // esi
  facetT *top; // eax
  facetT *bottom; // ebx
  facetT *v13; // ecx
  void **v14; // eax
  void **v15; // eax
  setT *v16; // eax
  setelemT v17; // ebx
  int v18; // edi
  int v19; // eax
  ridgeT *v20; // esi
  ridgeT *v21; // [esp-4h] [ebp-24h]
  unsigned int samevisitid; // [esp+Ch] [ebp-14h]
  int numnew; // [esp+10h] [ebp-10h]
  ridgeT **ridgep; // [esp+14h] [ebp-Ch]
  ridgeT **ridgepa; // [esp+14h] [ebp-Ch]
  int numold; // [esp+18h] [ebp-8h]
  facetT *same; // [esp+1Ch] [ebp-4h]

  numold = 0;
  numnew = 0;
  if ( qh_qh.IStracing >= 4 )
    fprintf(str: qh_qh.ferr, format: "qh_mergecycle_ridges: delete shared ridges from newfacet\n");
  v2 = newfacet;
  ridges = newfacet->ridges;
  v4 = qh_qh.visit_id - 1;
  samevisitid = qh_qh.visit_id - 1;
  if ( ridges != nullptr )
  {
    e = ridges->e;
    v6.p = (void *)ridges->e[0];
    if ( v6.i != 0 )
    {
      do
      {
        v7 = *(facetT **)(v6.i + 4);
        ++e;
        if ( v7 == newfacet )
          v7 = *(facetT **)(v6.i + 8);
        if ( v7->visitid == v4 )
          e[-1].i = 0;
        v6.p = e->p;
      }
      while ( e->i != 0 );
    }
  }
  qh_setcompact(set: newfacet->ridges);
  if ( qh_qh.IStracing >= 4 )
    fprintf(str: qh_qh.ferr, format: "qh_mergecycle_ridges: add ridges to newfacet\n");
  replace = samecycle->f.replace;
  same = replace;
  if ( replace != nullptr )
  {
    while ( 1 )
    {
      v9 = replace->ridges;
      if ( v9 != nullptr )
      {
        p = (ridgeT *)v9->e[0].p;
        ridgep = (ridgeT **)v9->e;
        if ( p != nullptr )
          break;
      }
LABEL_31:
      v16 = replace->ridges;
      if ( v16 != nullptr )
      {
        qh_settruncate(set: v16, size: 0);
        replace = same;
      }
      if ( (*((_DWORD *)replace + 20) & 0x1000) != 0 && replace->neighbors != nullptr )
      {
        v17.p = (void *)same->neighbors->e[0];
        v18 = 0;
        v19 = qh_setsize(set: same->neighbors);
        ridgepa = (ridgeT **)v19;
        if ( v19 > 0 )
        {
          do
          {
            if ( *(_DWORD *)(v17.i + 72) != samevisitid && (*(_DWORD *)(v17.i + 80) & 0x1000) != 0 )
            {
              v20 = qh_newridge();
              v20->vertices = qh_setnew_delnthsorted(
                                set: same->vertices,
                                size: (setT *)qh_qh.hull_dim,
                                nth: v18,
                                prepend: 0);
              if ( (((unsigned __int8)v18 ^ (unsigned __int8)(*((_DWORD *)same + 20) >> 11)) & 1) != 0 )
              {
                v20->top = newfacet;
                v20->bottom = (facetT *)v17.p;
              }
              else
              {
                v20->top = (facetT *)v17.p;
                v20->bottom = newfacet;
              }
              qh_setappend(setp: &newfacet->ridges, newelem: v20);
              qh_setappend(setp: (setT **)(v17.i + 56), newelem: v20);
              v19 = (int)ridgepa;
              ++numnew;
            }
            v17.p = (void *)*(&same->neighbors[1].maxsize + v18++);
          }
          while ( v18 < v19 );
        }
        replace = same;
        v2 = newfacet;
      }
      if ( replace == samecycle )
        goto LABEL_46;
      same = replace->f.replace;
      if ( same == nullptr )
        goto LABEL_46;
      replace = replace->f.replace;
    }
    while ( 1 )
    {
      top = p->top;
      ++ridgep;
      if ( top == replace )
      {
        bottom = p->bottom;
        p->top = v2;
      }
      else
      {
        v13 = p->bottom;
        if ( v13 != replace )
        {
          if ( top != v2 && v13 != v2 )
          {
            ivp_message(
              templat: "qhull internal error (qh_mergecycle_ridges): bad ridge r%d\n",
              *((_DWORD *)p + 3) & 0xFFFFFF);
            qh_errexit(exitcode: 5, facet: nullptr, ridge: p);
          }
          v21 = p;
LABEL_29:
          qh_setappend(setp: &v2->ridges, newelem: v21);
          ++numold;
          goto LABEL_30;
        }
        p->bottom = v2;
        bottom = top;
      }
      v21 = p;
      if ( bottom == v2 )
      {
        qh_setfree(setp: &p->vertices);
        ++qhmem.freeshort;
        v14 = &qhmem.freelists[qhmem.indextable[16]];
        ++numold;
        p->vertices = (setT *)*v14;
        *v14 = p;
      }
      else
      {
        if ( bottom->visitid != samevisitid )
          goto LABEL_29;
        qh_setdel(set: bottom->ridges, oldelem: p);
        qh_setfree(setp: &p->vertices);
        ++qhmem.freeshort;
        v15 = &qhmem.freelists[qhmem.indextable[16]];
        ++numold;
        p->vertices = (setT *)*v15;
        *v15 = p;
      }
LABEL_30:
      p = *ridgep;
      replace = same;
      if ( *ridgep == nullptr )
        goto LABEL_31;
    }
  }
LABEL_46:
  if ( qh_qh.IStracing >= 2 )
    fprintf(str: qh_qh.ferr, format: "qh_mergecycle_ridges: found %d old ridges and %d new ones\n", numold, numnew);
}

//------------------------------------------------------------------------------
// Address: 0x10069330
// Name: void qh_mergecycle_vneighbors(struct facetT __near *,struct facetT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_mergecycle_vneighbors(facetT *samecycle, facetT *newfacet)
{
  facetT *v3; // edi
  setT *v4; // eax
  setT *v5; // ecx
  setelemT v6; // esi
  int v7; // eax
  setT **v8; // edi
  int *v9; // ecx
  int v10; // eax
  unsigned int mergeid; // [esp+0h] [ebp-8h]
  setT *vertices; // [esp+4h] [ebp-4h] BYREF
  setelemT *vertexp; // [esp+14h] [ebp+Ch]

  if ( qh_qh.IStracing >= 4 )
    fprintf(str: qh_qh.ferr, format: "qh_mergecycle_vneighbors: update vertex neighbors for newfacet\n");
  v3 = samecycle;
  mergeid = qh_qh.visit_id - 1;
  newfacet->visitid = qh_qh.visit_id - 1;
  v4 = qh_basevertices(samecycle);
  v5 = samecycle->vertices;
  vertices = v4;
  qh_setappend(setp: &vertices, newelem: v5->e[0].p);
  if ( vertices != nullptr )
  {
    v6.p = (void *)vertices->e[0];
    vertexp = vertices->e;
    if ( v6.i != 0 )
    {
      do
      {
        v7 = *(_DWORD *)(v6.i + 12);
        ++vertexp;
        *(_DWORD *)(v6.i + 20) |= 0x4000000u;
        v8 = (setT **)(v6.i + 12);
        if ( v7 != 0 )
        {
          v9 = (int *)(v7 + 4);
          v10 = *(_DWORD *)(v7 + 4);
          if ( v10 != 0 )
          {
            do
            {
              ++v9;
              if ( *(_DWORD *)(v10 + 72) == mergeid )
                *(v9 - 1) = 0;
              v10 = *v9;
            }
            while ( *v9 != 0 );
          }
        }
        qh_setcompact(set: *v8);
        qh_setappend(setp: (setT **)(v6.i + 12), newelem: newfacet);
        if ( (*v8)[1].maxsize == 0 )
        {
          ++qh_qhstat.stats[38].i;
          if ( qh_qh.IStracing >= 2 )
            fprintf(
              str: qh_qh.ferr,
              format: "qh_mergecycle_vneighbors: deleted v%d when merging cycle f%d into f%d\n",
              *(_DWORD *)(v6.i + 20) & 0xFFFFFF,
              samecycle->id,
              newfacet->id);
          qh_setdelsorted(set: newfacet->vertices, oldelem: v6.p);
          *(_DWORD *)(v6.i + 20) |= 0x8000000u;
          qh_setappend(setp: &qh_qh.del_vertices, newelem: v6.p);
        }
        v6.p = vertexp->p;
      }
      while ( vertexp->i != 0 );
      v3 = samecycle;
    }
  }
  qh_settempfree(set: &vertices);
  if ( qh_qh.IStracing >= 3 )
    fprintf(
      str: qh_qh.ferr,
      format: "qh_mergecycle_vneighbors: merged vertices from cycle f%d into f%d\n",
      v3->id,
      newfacet->id);
}

//------------------------------------------------------------------------------
// Address: 0x10069490
// Name: void qh_mergefacet2d(struct facetT __near *,struct facetT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_mergefacet2d(facetT *facet1, facetT *facet2)
{
  setT *vertices; // ecx
  vertexT *p; // eax
  setT *neighbors; // edx
  int maxsize; // edi
  setT *v7; // ecx
  vertexT *v8; // ebx
  setT *v9; // ecx
  facetT *v10; // edx
  facetT *v11; // ecx
  int v12; // eax
  facetT *v13; // ebx
  bool v14; // zf
  setT *v15; // ecx
  vertexT *vertex2A; // [esp+Ch] [ebp-10h]
  facetT *neighbor1B; // [esp+10h] [ebp-Ch]
  facetT *neighbor1A; // [esp+14h] [ebp-8h]
  vertexT *vertex2B; // [esp+18h] [ebp-4h]
  facetT *neighborA; // [esp+28h] [ebp+Ch]

  vertices = facet1->vertices;
  p = (vertexT *)vertices->e[0].p;
  neighbors = facet1->neighbors;
  maxsize = vertices[1].maxsize;
  v7 = facet2->vertices;
  v8 = (vertexT *)v7->e[0].p;
  vertex2B = (vertexT *)v7[1].maxsize;
  neighbor1A = (facetT *)neighbors->e[0].p;
  v9 = facet2->neighbors;
  neighbor1B = (facetT *)neighbors[1].maxsize;
  v10 = (facetT *)v9->e[0].p;
  v11 = (facetT *)v9[1].maxsize;
  vertex2A = v8;
  if ( p == v8 )
  {
    v12 = (int)vertex2B;
    v13 = neighbor1A;
    neighborA = v10;
    goto LABEL_9;
  }
  if ( p == vertex2B )
  {
    v12 = (int)v8;
    v13 = neighbor1A;
  }
  else
  {
    v14 = maxsize == (_DWORD)v8;
    maxsize = (int)p;
    if ( v14 )
    {
      v12 = (int)vertex2B;
      v13 = neighbor1B;
      neighborA = v10;
      goto LABEL_9;
    }
    v12 = (int)v8;
    v13 = neighbor1B;
  }
  neighborA = v11;
LABEL_9:
  v15 = facet2->vertices;
  if ( (*(_DWORD *)(maxsize + 20) & 0xFFFFFFu) <= (*(_DWORD *)(v12 + 20) & 0xFFFFFFu) )
  {
    v15->e[0].i = v12;
    facet2->vertices[1].maxsize = maxsize;
    if ( (vertexT *)v12 == vertex2B )
      *((_DWORD *)facet2 + 20) ^= ((unsigned __int16)*((_DWORD *)facet2 + 20)
                                 ^ (unsigned __int16)~(unsigned __int16)*((_DWORD *)facet2 + 20))
                                & 0x800;
    facet2->neighbors->e[0].i = (int)v13;
    facet2->neighbors[1].maxsize = (int)neighborA;
  }
  else
  {
    v15->e[0].i = maxsize;
    facet2->vertices[1].maxsize = v12;
    if ( (vertexT *)v12 == vertex2A )
      *((_DWORD *)facet2 + 20) ^= ((unsigned __int16)*((_DWORD *)facet2 + 20)
                                 ^ (unsigned __int16)~(unsigned __int16)*((_DWORD *)facet2 + 20))
                                & 0x800;
    facet2->neighbors->e[0].i = (int)neighborA;
    facet2->neighbors[1].maxsize = (int)v13;
  }
  qh_makeridges(facet: v13);
  qh_setreplace(set: v13->neighbors, oldelem: facet1, newelem: facet2);
  if ( qh_qh.IStracing >= 4 )
    fprintf(
      str: qh_qh.ferr,
      format: "qh_mergefacet2d: merged v%d and neighbor f%d of f%d into f%d\n",
      *(_DWORD *)(maxsize + 20) & 0xFFFFFF,
      v13->id,
      facet1->id,
      facet2->id);
}

//------------------------------------------------------------------------------
// Address: 0x100695E0
// Name: void qh_mergeneighbors(struct facetT __near *,struct facetT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_mergeneighbors(facetT *facet1, facetT *facet2)
{
  setT *neighbors; // ecx
  setT **p_neighbors; // edx
  setelemT v6; // eax
  setelemT *e; // ecx
  setT *v8; // eax
  facetT *p; // esi
  char *v10; // eax
  setT *v11; // eax
  facetT **neighborp; // [esp+14h] [ebp+8h]
  facetT *facet2a; // [esp+18h] [ebp+Ch]

  if ( qh_qh.IStracing >= 4 )
    fprintf(str: qh_qh.ferr, format: "qh_mergeneighbors: merge neighbors of f%d and f%d\n", facet1->id, facet2->id);
  ++qh_qh.visit_id;
  neighbors = facet2->neighbors;
  p_neighbors = &facet2->neighbors;
  facet2a = (facetT *)&facet2->neighbors;
  if ( neighbors != nullptr )
  {
    v6.p = (void *)neighbors->e[0];
    e = neighbors->e;
    if ( v6.i != 0 )
    {
      do
      {
        ++e;
        *(_DWORD *)(v6.i + 72) = qh_qh.visit_id;
        v6.p = e->p;
      }
      while ( e->i != 0 );
    }
  }
  v8 = facet1->neighbors;
  if ( v8 != nullptr )
  {
    p = (facetT *)v8->e[0].p;
    v10 = (char *)v8->e;
    if ( p != nullptr )
    {
      while ( 1 )
      {
        neighborp = (facetT **)(v10 + 4);
        if ( p->visitid == qh_qh.visit_id )
        {
          if ( (*((_DWORD *)p + 20) & 0x1000) != 0 )
            qh_makeridges(facet: p);
          v11 = p->neighbors;
          if ( v11->e[0].p == facet1 )
          {
            qh_setdel(set: v11, oldelem: facet2);
            qh_setreplace(set: p->neighbors, oldelem: facet1, newelem: facet2);
          }
          else
          {
            qh_setdel(set: v11, oldelem: facet1);
          }
        }
        else if ( p != facet2 )
        {
          qh_setappend(setp: p_neighbors, newelem: p);
          qh_setreplace(set: p->neighbors, oldelem: facet1, newelem: facet2);
        }
        v10 = (char *)neighborp;
        p = *neighborp;
        if ( *neighborp == nullptr )
          break;
        p_neighbors = &facet2->neighbors;
      }
    }
  }
  qh_setdel(set: facet1->neighbors, oldelem: facet2);
  qh_setdel(set: (setT *)LODWORD(facet2a->furthestdist), oldelem: facet1);
}

//------------------------------------------------------------------------------
// Address: 0x100696E0
// Name: void qh_mergeridges(struct facetT __near *,struct facetT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_mergeridges(facetT *facet1, facetT *facet2)
{
  facetT *v2; // edi
  setT *ridges; // eax
  setelemT v4; // edx
  setelemT *e; // esi
  int v6; // eax
  int v7; // ecx
  int i; // eax
  setT *v9; // eax
  setelemT *v10; // esi
  _DWORD *p; // eax

  v2 = facet2;
  if ( qh_qh.IStracing >= 4 )
    fprintf(str: qh_qh.ferr, format: "qh_mergeridges: merge ridges of f%d and f%d\n", facet1->id, facet2->id);
  ridges = facet2->ridges;
  if ( ridges != nullptr )
  {
    v4.p = (void *)ridges->e[0];
    e = ridges->e;
    if ( v4.i != 0 )
    {
      do
      {
        ++e;
        if ( *(facetT **)(v4.i + 4) == facet1 || *(facetT **)(v4.i + 8) == facet1 )
        {
          v6 = *(_DWORD *)v4.p;
          if ( *(_DWORD *)v4.p != 0 )
          {
            v7 = v6 + 4;
            for ( i = *(_DWORD *)(v6 + 4); i != 0; v7 += 4 )
            {
              *(_DWORD *)(i + 20) |= 0x4000000u;
              i = *(_DWORD *)(v7 + 4);
            }
          }
          qh_delridge(ridge: (setT *)v4.p);
          --e;
        }
        v4.p = e->p;
      }
      while ( e->i != 0 );
      v2 = facet2;
    }
  }
  v9 = facet1->ridges;
  if ( v9 != nullptr )
  {
    v10 = v9->e;
    p = v9->e[0].p;
    if ( p != nullptr )
    {
      do
      {
        ++v10;
        if ( (facetT *)p[1] == facet1 )
          p[1] = v2;
        else
          p[2] = v2;
        qh_setappend(setp: &v2->ridges, newelem: p);
        p = (_DWORD *)v10->i;
      }
      while ( v10->i != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100697A0
// Name: void qh_mergevertex_del(struct vertexT __near *,struct facetT __near *,struct facetT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_mergevertex_del(vertexT *vertex, facetT *facet1, facetT *facet2)
{
  ++qh_qhstat.stats[114].i;
  if ( qh_qh.IStracing >= 2 )
    fprintf(
      str: qh_qh.ferr,
      format: "qh_mergevertex_del: deleted v%d when merging f%d into f%d\n",
      *((_DWORD *)vertex + 5) & 0xFFFFFF,
      facet1->id,
      facet2->id);
  qh_setdelsorted(set: facet2->vertices, oldelem: vertex);
  *((_DWORD *)vertex + 5) |= 0x8000000u;
  qh_setappend(setp: &qh_qh.del_vertices, newelem: vertex);
}

//------------------------------------------------------------------------------
// Address: 0x10069810
// Name: void qh_mergevertex_neighbors(struct facetT __near *,struct facetT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_mergevertex_neighbors(facetT *facet1, facetT *facet2)
{
  vertexT *tracevertex; // ecx
  setT *vertices; // eax
  vertexT **e; // ebx
  vertexT *p; // esi

  if ( qh_qh.IStracing >= 4 )
    fprintf(
      str: qh_qh.ferr,
      format: "qh_mergevertex_neighbors: merge vertex neighbors of f%d and f%d\n",
      facet1->id,
      facet2->id);
  tracevertex = qh_qh.tracevertex;
  if ( qh_qh.tracevertex != nullptr )
  {
    ivp_message(
      templat: "qh_mergevertex_neighbors: of f%d and f%d at furthest p%d f0= %p\n",
      facet1->id,
      facet2->id,
      qh_qh.furthest_id,
      qh_qh.tracevertex->neighbors->e[0].p);
    qh_errprint(string: "TRACE", atfacet: nullptr, otherfacet: nullptr, atridge: nullptr, atvertex: qh_qh.tracevertex);
    tracevertex = qh_qh.tracevertex;
  }
  vertices = facet1->vertices;
  if ( vertices != nullptr )
  {
    e = (vertexT **)vertices->e;
    p = (vertexT *)vertices->e[0].p;
    if ( p != nullptr )
    {
      do
      {
        ++e;
        if ( p->visitid == qh_qh.vertex_visit )
        {
          qh_setdel(set: p->neighbors, oldelem: facet1);
          if ( p->neighbors[1].maxsize == 0 )
            qh_mergevertex_del(vertex: p, facet1, facet2);
        }
        else
        {
          qh_setreplace(set: p->neighbors, oldelem: facet1, newelem: facet2);
        }
        p = *e;
      }
      while ( *e != nullptr );
      tracevertex = qh_qh.tracevertex;
    }
  }
  if ( tracevertex != nullptr )
    qh_errprint(string: "TRACE", atfacet: nullptr, otherfacet: nullptr, atridge: nullptr, atvertex: tracevertex);
}

//------------------------------------------------------------------------------
// Address: 0x10069910
// Name: void qh_mergevertices(struct setT __near *,struct setT __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_mergevertices(setT *vertices1, setT **vertices2)
{
  int v3; // ebx
  int v4; // ebx
  setelemT *e; // esi
  setelemT *v6; // ebx
  _DWORD *p; // edi
  _DWORD *i; // eax
  void *j; // eax
  setT *mergedvertices; // [esp+Ch] [ebp-4h] BYREF
  int newsize; // [esp+18h] [ebp+8h]

  v3 = qh_setsize(set: *vertices2);
  v4 = 1 - qh_qh.hull_dim + qh_setsize(set: vertices1) + v3;
  newsize = v4;
  e = (*vertices2)->e;
  mergedvertices = qh_settemp(setsize: v4);
  if ( vertices1 != nullptr )
  {
    v6 = vertices1->e;
    p = vertices1->e[0].p;
    if ( p != nullptr )
    {
      do
      {
        i = (_DWORD *)e->i;
        ++v6;
        if ( e->i == 0 || (p[5] & 0xFFFFFFu) > (i[5] & 0xFFFFFFu) )
          goto LABEL_11;
        while ( (i[5] & 0xFFFFFFu) > (p[5] & 0xFFFFFFu) )
        {
          qh_setappend(setp: &mergedvertices, newelem: i);
          i = e[1].p;
          ++e;
          if ( i == nullptr )
            goto LABEL_11;
        }
        if ( e->i != 0 && (*(_DWORD *)(e->i + 20) & 0xFFFFFFu) >= (p[5] & 0xFFFFFFu) )
        {
          qh_setappend(setp: &mergedvertices, newelem: e->p);
          ++e;
        }
        else
        {
LABEL_11:
          qh_setappend(setp: &mergedvertices, newelem: p);
        }
        p = (_DWORD *)v6->i;
      }
      while ( v6->i != 0 );
    }
    v4 = newsize;
  }
  for ( j = (void *)e->i; j != nullptr; ++e )
  {
    qh_setappend(setp: &mergedvertices, newelem: j);
    j = e[1].p;
  }
  if ( v4 < qh_setsize(set: mergedvertices) )
  {
    ivp_message(templat: "qhull internal error (qh_mergevertices): facets did not share a ridge\n");
    qh_errexit(exitcode: 5, facet: nullptr, ridge: nullptr);
  }
  qh_setfree(setp: vertices2);
  *vertices2 = mergedvertices;
  qh_settemppop();
}

//------------------------------------------------------------------------------
// Address: 0x10069A70
// Name: struct setT __near * qh_neighbor_intersections(struct vertexT __near *)
// Source: json
//------------------------------------------------------------------------------
setT *__cdecl qh_neighbor_intersections(vertexT *vertex)
{
  vertexT *v1; // edi
  setT *neighbors; // ecx
  setelemT v3; // eax
  setelemT *e; // ecx
  setT *v5; // eax
  setelemT v6; // ecx
  int maxsize; // eax
  setT *v8; // eax
  setT *v10; // eax
  setelemT v11; // edi
  int v12; // esi
  int v13; // ebx
  int v14; // eax
  int v15; // [esp-Ch] [ebp-14h]
  setT *intersect; // [esp+4h] [ebp-4h] BYREF

  v1 = vertex;
  neighbors = vertex->neighbors;
  if ( neighbors != nullptr )
  {
    v3.p = (void *)neighbors->e[0];
    e = neighbors->e;
    if ( v3.i != 0 )
    {
      do
      {
        ++e;
        if ( (*(_DWORD *)(v3.i + 80) & 0x1000) != 0 )
          return nullptr;
        v3.p = e->p;
      }
      while ( e->i != 0 );
    }
  }
  v5 = vertex->neighbors;
  v6.p = (void *)v5->e[0];
  maxsize = v5[1].maxsize;
  ++qh_qhstat.stats[90].i;
  if ( v6.i == 0 )
    return nullptr;
  if ( maxsize != 0 )
    v8 = qh_vertexintersect_new(vertexsetA: *(setT **)(v6.i + 52), vertexsetB: *(setT **)(maxsize + 52));
  else
    v8 = qh_setcopy(set: *(setT **)(v6.i + 52), extra: 0);
  intersect = v8;
  qh_settemppush(set: v8);
  qh_setdelsorted(set: intersect, oldelem: vertex);
  if ( vertex->neighbors == nullptr )
    goto LABEL_18;
  v10 = vertex->neighbors;
  v11.p = (void *)v10->e[0];
  v12 = 0;
  v13 = qh_setsize(set: v10);
  if ( v13 <= 0 )
  {
    v1 = vertex;
LABEL_18:
    if ( qh_qh.IStracing >= 3 )
    {
      v15 = *((_DWORD *)v1 + 5) & 0xFFFFFF;
      v14 = qh_setsize(set: intersect);
      fprintf(
        str: qh_qh.ferr,
        format: "qh_neighbor_intersections: %d vertices in neighbor intersection of v%d\n",
        v14,
        v15);
    }
    return intersect;
  }
  while ( 1 )
  {
    if ( v12 >= 2 )
    {
      ++qh_qhstat.stats[90].i;
      qh_vertexintersect(vertexsetA: &intersect, vertexsetB: *(setT **)(v11.i + 52));
      if ( intersect->e[0].i == 0 )
        break;
    }
    v11.p = (void *)*(&vertex->neighbors[1].maxsize + v12++);
    if ( v12 >= v13 )
    {
      v1 = vertex;
      goto LABEL_18;
    }
  }
  ++qh_qhstat.stats[88].i;
  qh_settempfree(set: &intersect);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10069BB0
// Name: void qh_newvertices(struct setT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_newvertices(setT *vertices)
{
  setelemT v1; // esi
  setelemT *e; // edi

  if ( vertices != nullptr )
  {
    v1.p = (void *)vertices->e[0];
    e = vertices->e;
    if ( v1.i != 0 )
    {
      do
      {
        ++e;
        if ( (*(_DWORD *)(v1.i + 20) & 0x10000000) == 0 )
        {
          qh_removevertex(vertex: (vertexT *)v1.p);
          qh_appendvertex(vertex: (vertexT *)v1.p);
        }
        v1.p = e->p;
      }
      while ( e->i != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10069C00
// Name: unsigned int qh_remove_extravertices(struct facetT __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl qh_remove_extravertices(facetT *facet)
{
  setT *vertices; // eax
  setelemT *e; // ecx
  setelemT v3; // eax
  setT *ridges; // eax
  setelemT *v5; // edx
  int *p; // eax
  int v7; // eax
  int v8; // ecx
  int i; // eax
  setT *v10; // eax
  setelemT v11; // esi
  setelemT *v12; // edi
  unsigned int foundrem; // [esp+Ch] [ebp-4h]

  foundrem = 0;
  if ( qh_qh.IStracing >= 4 )
    fprintf(str: qh_qh.ferr, format: "qh_remove_extravertices: test f%d for extra vertices\n", facet->id);
  vertices = facet->vertices;
  if ( vertices != nullptr )
  {
    e = vertices->e;
    for ( v3.p = (void *)vertices->e[0]; v3.i != 0; ++e )
    {
      *(_DWORD *)(v3.i + 20) &= ~0x1000000u;
      v3.p = e[1].p;
    }
  }
  ridges = facet->ridges;
  if ( ridges != nullptr )
  {
    v5 = ridges->e;
    p = (int *)ridges->e[0].p;
    if ( p != nullptr )
    {
      do
      {
        v7 = *p;
        ++v5;
        if ( v7 != 0 )
        {
          v8 = v7 + 4;
          for ( i = *(_DWORD *)(v7 + 4); i != 0; v8 += 4 )
          {
            *(_DWORD *)(i + 20) |= 0x1000000u;
            i = *(_DWORD *)(v8 + 4);
          }
        }
        p = (int *)v5->i;
      }
      while ( v5->i != 0 );
    }
  }
  v10 = facet->vertices;
  if ( v10 == nullptr )
    return 0;
  v11.p = (void *)v10->e[0];
  v12 = v10->e;
  if ( v11.i == 0 )
    return 0;
  do
  {
    ++v12;
    if ( (*(_BYTE *)(v11.i + 23) & 1) == 0 )
    {
      ++qh_qhstat.stats[152].i;
      foundrem = 1;
      qh_setdelsorted(set: facet->vertices, oldelem: v11.p);
      qh_setdel(set: *(setT **)(v11.i + 12), oldelem: facet);
      if ( qh_setsize(set: *(setT **)(v11.i + 12)) != 0 )
      {
        if ( qh_qh.IStracing >= 3 )
          fprintf(
            str: qh_qh.ferr,
            format: "qh_remove_extravertices: v%d removed from f%d because it's lost all ridges\n",
            *(_DWORD *)(v11.i + 20) & 0xFFFFFF,
            facet->id);
      }
      else
      {
        *(_DWORD *)(v11.i + 20) |= 0x8000000u;
        qh_setappend(setp: &qh_qh.del_vertices, newelem: v11.p);
        ++qh_qhstat.stats[153].i;
        if ( qh_qh.IStracing >= 2 )
          fprintf(
            str: qh_qh.ferr,
            format: "qh_remove_extravertices: v%d deleted because it's lost all ridges\n",
            *(_DWORD *)(v11.i + 20) & 0xFFFFFF);
      }
      --v12;
    }
    v11.p = v12->p;
  }
  while ( v12->i != 0 );
  return foundrem;
}

//------------------------------------------------------------------------------
// Address: 0x10069D90
// Name: void qh_renameridgevertex(struct ridgeT __near *,struct vertexT __near *,struct vertexT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_renameridgevertex(ridgeT *ridge, vertexT *oldvertex, vertexT *newvertex)
{
  int v4; // edi
  setT *vertices; // eax
  setelemT *e; // ecx
  setelemT v7; // eax
  bool v8; // zf
  signed int v9; // eax
  facetT *top; // eax
  int oldnth; // [esp+14h] [ebp+8h]

  v4 = 0;
  oldnth = qh_setindex(set: ridge->vertices, atelem: oldvertex);
  qh_setdelnthsorted(set: ridge->vertices, nth: oldnth);
  vertices = ridge->vertices;
  if ( ridge->vertices != nullptr && (e = vertices->e, v7.p = (void *)vertices->e[0], v7.i != 0) )
  {
    while ( 1 )
    {
      ++e;
      if ( v7.p == newvertex )
        break;
      if ( (*(_DWORD *)(v7.i + 20) & 0xFFFFFFu) >= (*((_DWORD *)newvertex + 5) & 0xFFFFFFu) )
      {
        v7.p = e->p;
        ++v4;
        if ( e->i != 0 )
          continue;
      }
      goto LABEL_6;
    }
    ++qh_qhstat.stats[44].i;
    if ( (*((_DWORD *)ridge + 3) & 0x4000000) != 0 )
      qh_copynonconvex(atridge: ridge);
    qh_delridge((setT *)ridge);
    if ( qh_qh.IStracing >= 2 )
      fprintf(
        str: qh_qh.ferr,
        format: "qh_renameridgevertex: ridge r%d deleted.  It contained both v%d and v%d\n",
        *((_DWORD *)ridge + 3) & 0xFFFFFF,
        *((_DWORD *)oldvertex + 5) & 0xFFFFFF,
        *((_DWORD *)newvertex + 5) & 0xFFFFFF);
  }
  else
  {
LABEL_6:
    qh_setaddnth(setp: &ridge->vertices, nth: v4, newelem: newvertex);
    v9 = abs32(oldnth - v4) & 0x80000001;
    v8 = v9 == 0;
    if ( v9 < 0 )
      v8 = (((_BYTE)v9 - 1) | 0xFFFFFFFE) == -1;
    if ( !v8 )
    {
      if ( qh_qh.IStracing >= 3 )
        fprintf(
          str: qh_qh.ferr,
          format: "qh_renameridgevertex: swapped the top and bottom of ridge r%d\n",
          *((_DWORD *)ridge + 3) & 0xFFFFFF);
      top = ridge->top;
      ridge->top = ridge->bottom;
      ridge->bottom = top;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10069EB0
// Name: void qh_renamevertex(struct vertexT __near *,struct vertexT __near *,struct setT __near *,struct facetT __near *,struct facetT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_renamevertex(vertexT *oldvertex, vertexT *newvertex, setT *ridges, facetT *oldfacet, facetT *neighborA)
{
  ridgeT *p; // eax
  setelemT *e; // edi
  setT *v7; // eax
  facetT *v8; // edi
  facetT **v9; // ebx
  int v10; // eax
  setT *neighbors; // edi
  setelemT v12; // eax
  setelemT *v13; // edi
  unsigned int istrace; // [esp+Ch] [ebp-4h]

  istrace = 0;
  if ( qh_qh.IStracing >= 2
    || (*((_DWORD *)oldvertex + 5) & 0xFFFFFF) == qh_qh.tracevertex_id
    || (*((_DWORD *)newvertex + 5) & 0xFFFFFF) == qh_qh.tracevertex_id )
  {
    istrace = 1;
  }
  if ( ridges != nullptr )
  {
    p = (ridgeT *)ridges->e[0].p;
    e = ridges->e;
    if ( p != nullptr )
    {
      do
      {
        ++e;
        qh_renameridgevertex(ridge: p, oldvertex, newvertex);
        p = (ridgeT *)e->i;
      }
      while ( e->i != 0 );
    }
  }
  if ( oldfacet != nullptr )
  {
    if ( qh_setsize(set: oldvertex->neighbors) == 2 )
    {
      ++qh_qhstat.stats[156].i;
      if ( istrace != 0 )
        ivp_message(
          templat: "qh_renamevertex: renamed v%d to v%d in oldfacet f%d\n",
          *((_DWORD *)oldvertex + 5) & 0xFFFFFF,
          *((_DWORD *)newvertex + 5) & 0xFFFFFF,
          oldfacet->id);
      neighbors = oldvertex->neighbors;
      if ( neighbors != nullptr )
      {
        v12.p = (void *)neighbors->e[0];
        v13 = neighbors->e;
        if ( v12.i != 0 )
        {
          do
          {
            ++v13;
            qh_setdelsorted(set: *(setT **)(v12.i + 52), oldelem: oldvertex);
            v12.p = v13->p;
          }
          while ( v13->i != 0 );
        }
      }
      *((_DWORD *)oldvertex + 5) |= 0x8000000u;
      qh_setappend(setp: &qh_qh.del_vertices, newelem: oldvertex);
    }
    else
    {
      ++qh_qhstat.stats[155].i;
      if ( istrace != 0 || qh_qh.IStracing != 0 )
        ivp_message(
          templat: "qh_renamevertex: renamed pinched v%d to v%d between f%d and f%d\n",
          *((_DWORD *)oldvertex + 5) & 0xFFFFFF,
          *((_DWORD *)newvertex + 5) & 0xFFFFFF,
          oldfacet->id,
          neighborA->id);
      qh_setdelsorted(set: oldfacet->vertices, oldelem: oldvertex);
      qh_setdel(set: oldvertex->neighbors, oldelem: oldfacet);
      qh_remove_extravertices(facet: neighborA);
    }
  }
  else
  {
    ++qh_qhstat.stats[154].i;
    if ( istrace != 0 )
      ivp_message(
        templat: "qh_renamevertex: renamed v%d to v%d in several facets\n",
        *((_DWORD *)oldvertex + 5) & 0xFFFFFF,
        *((_DWORD *)newvertex + 5) & 0xFFFFFF);
    v7 = oldvertex->neighbors;
    if ( v7 != nullptr )
    {
      v8 = (facetT *)v7->e[0].p;
      v9 = (facetT **)v7->e;
      if ( v8 != nullptr )
      {
        do
        {
          ++v9;
          qh_maydropneighbor(facet: v8);
          qh_setdelsorted(set: v8->vertices, oldelem: oldvertex);
          if ( qh_remove_extravertices(facet: v8) != 0 )
            --v9;
          v8 = *v9;
        }
        while ( *v9 != nullptr );
      }
    }
    v10 = *((_DWORD *)oldvertex + 5);
    if ( (v10 & 0x8000000) == 0 )
    {
      *((_DWORD *)oldvertex + 5) = v10 | 0x8000000;
      qh_setappend(setp: &qh_qh.del_vertices, newelem: oldvertex);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006A0A0
// Name: unsigned int qh_test_appendmerge(struct facetT __near *,struct facetT __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl qh_test_appendmerge(facetT *facet, facetT *neighbor)
{
  int v2; // ebx
  long double dist; // [esp+28h] [ebp-20h] BYREF
  long double dist2; // [esp+30h] [ebp-18h] BYREF
  double angle; // [esp+38h] [ebp-10h] BYREF
  unsigned int okangle; // [esp+40h] [ebp-8h]
  unsigned int isconcave; // [esp+44h] [ebp-4h]

  v2 = 0;
  dist2 = -1.797693134862316e308;
  angle = -1.797693134862316e308;
  isconcave = 0;
  okangle = 0;
  if ( qh_qh.SKIPconvex != 0 && qh_qh.POSTmerging == 0 )
    return 0;
  if ( (qh_qh.MERGEexact == 0 || qh_qh.POSTmerging != 0) && qh_qh.cos_max < 8.988465674311579e307 )
  {
    angle = qh_getangle(vect1: facet->normal, vect2: neighbor->normal);
    ++qh_qhstat.stats[7].i;
    if ( angle > qh_qh.cos_max )
    {
      ++qh_qhstat.stats[28].i;
      qh_appendmergeset(facet, neighbor, mergetype: MRGanglecoplanar, &angle);
      if ( qh_qh.IStracing >= 2 )
        fprintf(
          str: qh_qh.ferr,
          format: "qh_test_appendmerge: coplanar angle %4.4g between f%d and f%d\n",
          angle,
          facet->id,
          neighbor->id);
      return 1;
    }
    okangle = 1;
  }
  if ( facet->center == nullptr )
    facet->center = qh_getcentrum(facet);
  ++qh_qhstat.stats[17].i;
  qh_distplane(point: facet->center, facet: neighbor, &dist);
  if ( dist <= qh_qh.centrum_radius )
  {
    if ( dist > -qh_qh.centrum_radius )
      v2 = 1;
    if ( neighbor->center == nullptr )
      neighbor->center = qh_getcentrum(facet: neighbor);
    ++qh_qhstat.stats[17].i;
    qh_distplane(point: neighbor->center, facet, dist: &dist2);
    if ( dist2 <= qh_qh.centrum_radius )
    {
      if ( v2 == 0 && dist2 <= -qh_qh.centrum_radius || qh_qh.MERGEexact != 0 && qh_qh.POSTmerging == 0 )
        return 0;
    }
    else
    {
      isconcave = 1;
    }
  }
  else
  {
    isconcave = 1;
  }
  if ( okangle == 0 && qh_qh.ANGLEmerge != 0 )
  {
    angle = qh_getangle(vect1: facet->normal, vect2: neighbor->normal);
    ++qh_qhstat.stats[7].i;
  }
  if ( isconcave != 0 )
  {
    ++qh_qhstat.stats[24].i;
    if ( qh_qh.ANGLEmerge != 0 )
      angle = angle + 2.0;
    qh_appendmergeset(facet, neighbor, mergetype: MRGconcave, &angle);
    if ( qh_qh.IStracing != 0 )
    {
      fprintf(
        str: qh_qh.ferr,
        format: "qh_test_appendmerge: concave f%d to f%d dist %4.4g and reverse dist %4.4g angle %4.4g during p%d\n",
        facet->id,
        neighbor->id,
        (double)dist,
        (double)dist2,
        angle,
        qh_qh.furthest_id);
      return 1;
    }
  }
  else
  {
    ++qh_qhstat.stats[29].i;
    qh_appendmergeset(facet, neighbor, mergetype: MRGcoplanar, &angle);
    if ( qh_qh.IStracing >= 2 )
      fprintf(
        str: qh_qh.ferr,
        format: "qh_test_appendmerge: coplanar f%d to f%d dist %4.4g, reverse dist %4.4g angle %4.4g\n",
        facet->id,
        neighbor->id,
        (double)dist,
        (double)dist2,
        angle);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1006A3A0
// Name: unsigned int qh_test_vneighbors(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl qh_test_vneighbors()
{
  int v0; // esi
  facetT *newfacet_list; // eax
  facetT *next; // ecx
  facetT *i; // edi
  setT *neighbors; // eax
  setelemT *j; // eax
  setT *vertices; // eax
  setelemT *e; // ebx
  setelemT v8; // eax
  int v9; // eax
  int *v10; // esi
  int v11; // eax
  int nummerges; // [esp+4h] [ebp-4h]

  v0 = 0;
  nummerges = 0;
  if ( qh_qh.IStracing >= 1 )
    fprintf(str: qh_qh.ferr, format: "qh_test_vneighbors: testing vertex neighbors for convexity\n");
  if ( qh_qh.VERTEXneighbors == 0 )
    qh_vertexneighbors();
  newfacet_list = qh_qh.newfacet_list;
  if ( qh_qh.newfacet_list != nullptr )
  {
    while ( 1 )
    {
      next = newfacet_list->next;
      if ( next == nullptr )
        break;
      *((_DWORD *)newfacet_list + 20) &= ~0x2000u;
      newfacet_list = next;
    }
  }
  for ( i = qh_qh.newfacet_list; i != nullptr; i = i->next )
  {
    if ( i->next == nullptr )
      break;
    *((_DWORD *)i + 20) |= 0x2000u;
    i->visitid = qh_qh.visit_id++;
    neighbors = i->neighbors;
    if ( neighbors != nullptr )
    {
      for ( j = neighbors->e; j->i != 0; i->visitid = qh_qh.visit_id )
        ++j;
    }
    vertices = i->vertices;
    if ( vertices != nullptr )
    {
      e = vertices->e;
      v8.p = (void *)vertices->e[0];
      if ( v8.i != 0 )
      {
        do
        {
          v9 = *(_DWORD *)(v8.i + 12);
          ++e;
          if ( v9 != 0 )
          {
            v10 = (int *)(v9 + 4);
            v11 = *(_DWORD *)(v9 + 4);
            if ( v11 != 0 )
            {
              do
              {
                ++v10;
                if ( (*(_DWORD *)(v11 + 80) & 0x2000) == 0
                  && *(_DWORD *)(v11 + 72) != qh_qh.visit_id
                  && qh_test_appendmerge(facet: i, neighbor: (facetT *)v11) != 0 )
                {
                  ++nummerges;
                }
                v11 = *v10;
              }
              while ( *v10 != 0 );
            }
          }
          v8.p = e->p;
        }
        while ( e->i != 0 );
        v0 = nummerges;
      }
    }
  }
  qh_qhstat.stats[173].i += v0;
  if ( qh_qh.IStracing >= 1 )
    fprintf(str: qh_qh.ferr, format: "qh_test_vneighbors: found %d non-convex, vertex neighbors\n", v0);
  return v0 > 0;
}

//------------------------------------------------------------------------------
// Address: 0x1006A4E0
// Name: void qh_tracemerge(struct facetT __near *,struct facetT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_tracemerge(facetT *facet1, facetT *facet2)
{
  vertexT *tracevertex; // eax
  setT *neighbors; // eax
  facetT *p; // eax
  unsigned int waserror; // [esp+4h] [ebp-4h] BYREF

  waserror = 0;
  if ( qh_qh.IStracing >= 4 )
    qh_errprint(string: "MERGED", atfacet: facet2, otherfacet: nullptr, atridge: nullptr, atvertex: nullptr);
  if ( facet2 == qh_qh.tracefacet )
    goto LABEL_6;
  tracevertex = qh_qh.tracevertex;
  if ( qh_qh.tracevertex == nullptr )
    goto LABEL_17;
  if ( (*((_DWORD *)qh_qh.tracevertex + 5) & 0x10000000) != 0 )
  {
LABEL_6:
    ivp_message(
      templat: "qh_tracemerge: trace facet and vertex after merge of f%d and f%d, furthest p%d\n",
      facet1->id,
      facet2->id,
      qh_qh.furthest_id);
    if ( facet2 != qh_qh.tracefacet )
    {
      if ( qh_qh.tracevertex != nullptr && (neighbors = qh_qh.tracevertex->neighbors) != nullptr )
        p = (facetT *)neighbors->e[0].p;
      else
        p = nullptr;
      qh_errprint(
        string: "TRACE",
        atfacet: qh_qh.tracefacet,
        otherfacet: p,
        atridge: nullptr,
        atvertex: qh_qh.tracevertex);
    }
    tracevertex = qh_qh.tracevertex;
  }
  if ( tracevertex != nullptr )
  {
    if ( (*((_DWORD *)tracevertex + 5) & 0x8000000) != 0 )
      ivp_message(templat: "qh_tracemerge: trace vertex deleted at furthest p%d\n", qh_qh.furthest_id);
    else
      qh_checkvertex(vertex: tracevertex);
  }
LABEL_17:
  if ( qh_qh.tracefacet != nullptr )
  {
    qh_checkfacet(facet: qh_qh.tracefacet, newmerge: 1u, waserrorp: &waserror);
    if ( waserror != 0 )
      qh_errexit(exitcode: 5, facet: qh_qh.tracefacet, ridge: nullptr);
  }
  if ( qh_qh.CHECKfrequently != 0 || qh_qh.IStracing >= 4 )
  {
    qh_checkfacet(facet: facet2, newmerge: 1u, waserrorp: &waserror);
    if ( waserror != 0 )
      qh_errexit(exitcode: 5, facet: nullptr, ridge: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006A620
// Name: void qh_tracemerging(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_tracemerging()
{
  tm *v0; // edi
  int v1; // esi
  int v2; // eax
  __int64 timedata; // [esp+1Ch] [ebp-8h] BYREF

  qh_qh.mergereport = qh_qhstat.stats[176].i;
  _time64(timeptr: &timedata);
  v0 = _localtime64(ptime: &timedata);
  v1 = qh_qhstat.stats[176].i + qh_qhstat.stats[36].i - qh_qhstat.stats[37].i;
  v2 = qh_setsize(set: qh_qh.del_vertices);
  ivp_message(
    templat: "\nAt %d:%d:%d & %2.5g CPU secs, qhull has merged %d facets.  The hull\n  contains %d facets and %d vertices.\n",
    v0->tm_hour,
    v0->tm_min,
    v0->tm_sec,
    1.0,
    v1,
    qh_qh.num_facets - qh_qh.num_visible,
    qh_qh.num_vertices - v2);
}

//------------------------------------------------------------------------------
// Address: 0x1006A6B0
// Name: void qh_updatetested(struct facetT __near *,struct facetT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_updatetested(facetT *facet1, facetT *facet2)
{
  setT *ridges; // eax
  setelemT *e; // ecx
  setelemT v4; // eax
  int v5; // eax
  int v6; // ecx
  setT *v7; // esi
  setelemT v8; // eax
  setelemT *i; // ecx

  *((_DWORD *)facet2 + 20) &= ~0x4000000u;
  ridges = facet1->ridges;
  if ( ridges != nullptr )
  {
    e = ridges->e;
    for ( v4.p = (void *)ridges->e[0]; v4.i != 0; ++e )
    {
      *(_DWORD *)(v4.i + 12) &= ~0x2000000u;
      v4.p = e[1].p;
    }
  }
  if ( facet2->center != nullptr )
  {
    v5 = qh_setsize(set: facet2->vertices);
    v6 = *((_DWORD *)facet2 + 20);
    if ( (v6 & 0x8000000) != 0 )
    {
      if ( v5 <= qh_qh.hull_dim + 5 && (v5 == qh_qh.hull_dim || qh_qh.POSTmerging != 0) )
        *((_DWORD *)facet2 + 20) = v6 & 0xF7FFFFFF;
    }
    else if ( v5 > qh_qh.hull_dim + 5 )
    {
      *((_DWORD *)facet2 + 20) = v6 | 0x8000000;
      ++qh_qhstat.stats[193].i;
    }
    if ( (*((_DWORD *)facet2 + 20) & 0x8000000) == 0 )
    {
      qh_memfree(object: (void **)facet2->center, size: qh_qh.normal_size);
      facet2->center = nullptr;
      v7 = facet2->ridges;
      if ( v7 != nullptr )
      {
        v8.p = (void *)v7->e[0];
        for ( i = v7->e; v8.i != 0; ++i )
        {
          *(_DWORD *)(v8.i + 12) &= ~0x2000000u;
          v8.p = i[1].p;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006A790
// Name: void qh_vertexridges_facet(struct vertexT __near *,struct facetT __near *,struct setT __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_vertexridges_facet(vertexT *vertex, facetT *facet, setT **ridges)
{
  setT *v3; // eax
  setT **p; // esi
  setT ***e; // edi
  facetT *v6; // eax

  v3 = facet->ridges;
  if ( v3 != nullptr )
  {
    p = (setT **)v3->e[0].p;
    e = (setT ***)v3->e;
    if ( p != nullptr )
    {
      do
      {
        v6 = (facetT *)p[1];
        ++e;
        if ( v6 == facet )
          v6 = (facetT *)p[2];
        if ( v6->visitid == qh_qh.visit_id && qh_setin(set: *p, setelem: vertex) != 0 )
          qh_setappend(setp: ridges, newelem: p);
        p = *e;
      }
      while ( *e != nullptr );
      facet->visitid = qh_qh.visit_id - 1;
    }
    else
    {
      facet->visitid = qh_qh.visit_id - 1;
    }
  }
  else
  {
    facet->visitid = qh_qh.visit_id - 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006A820
// Name: void qh_willdelete(struct facetT __near *,struct facetT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_willdelete(facetT *facet, facetT *replace)
{
  qh_removefacet(facet);
  qh_prependfacet(facet, facetlist: &qh_qh.visible_list);
  ++qh_qh.num_visible;
  *((_DWORD *)facet + 20) |= 0x400u;
  facet->f.replace = replace;
}

//------------------------------------------------------------------------------
// Address: 0x1006A860
// Name: void qh_getmergeset(struct facetT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_getmergeset(facetT *facetlist)
{
  facetT *i; // edi
  int v2; // eax
  unsigned int visit_id; // edx
  setT *neighbors; // eax
  setelemT *e; // ecx
  setelemT v6; // eax
  setT *ridges; // eax
  _DWORD *p; // esi
  setelemT *v9; // ebx
  int v10; // eax
  int v11; // ecx
  unsigned int v12; // eax
  int v13; // esi

  qh_setsize(set: qh_qh.facet_mergeset);
  if ( qh_qh.IStracing >= 4 )
    fprintf(str: qh_qh.ferr, format: "qh_getmergeset: started.\n");
  ++qh_qh.visit_id;
  for ( i = facetlist; i != nullptr; i = i->next )
  {
    if ( i->next == nullptr )
      break;
    v2 = *((_DWORD *)i + 20);
    if ( (v2 & 0x4000000) == 0 )
    {
      visit_id = qh_qh.visit_id;
      *((_DWORD *)i + 20) = v2 | 0x4000000;
      neighbors = i->neighbors;
      i->visitid = visit_id;
      if ( neighbors != nullptr )
      {
        e = neighbors->e;
        for ( v6.p = (void *)neighbors->e[0]; v6.i != 0; ++e )
        {
          *(_DWORD *)(v6.i + 80) &= ~0x2000u;
          v6.p = e[1].p;
        }
      }
      ridges = i->ridges;
      if ( ridges != nullptr )
      {
        p = ridges->e[0].p;
        v9 = ridges->e;
        if ( p != nullptr )
        {
          do
          {
            v10 = p[3];
            ++v9;
            if ( (v10 & 0x2000000) == 0 || (v10 & 0x4000000) != 0 )
            {
              v11 = p[1];
              if ( (facetT *)v11 == i )
                v11 = p[2];
              if ( (*(_DWORD *)(v11 + 80) & 0x2000) != 0 )
              {
                p[3] = v10 & 0xF9FFFFFF | 0x2000000;
              }
              else if ( *(_DWORD *)(v11 + 72) != qh_qh.visit_id )
              {
                p[3] = v10 & 0xF9FFFFFF | 0x2000000;
                *(_DWORD *)(v11 + 80) |= 0x2000u;
                if ( qh_test_appendmerge(facet: i, neighbor: (facetT *)v11) != 0 )
                  p[3] |= 0x4000000u;
              }
            }
            p = (_DWORD *)v9->i;
          }
          while ( v9->i != 0 );
        }
      }
    }
  }
  v12 = qh_setsize(set: qh_qh.facet_mergeset);
  v13 = v12;
  if ( qh_qh.ANGLEmerge != 0 )
    qsort(
      base: qh_qh.facet_mergeset->e,
      num: v12,
      width: 4u,
      comp: (int (__cdecl *)(const void *, const void *))qh_compareangle);
  else
    qsort(base: qh_qh.facet_mergeset->e, num: v12, width: 4u, comp: qh_comparevisit);
  if ( qh_qh.POSTmerging != 0 )
  {
    qh_qhstat.stats[112].i += v13;
  }
  else
  {
    qh_qhstat.stats[110].i += v13;
    if ( qh_qhstat.stats[111].i < v13 )
      qh_qhstat.stats[111].i = v13;
  }
  if ( qh_qh.IStracing >= 2 )
    fprintf(str: qh_qh.ferr, format: "qh_getmergeset: %d merges found\n", v13);
}

//------------------------------------------------------------------------------
// Address: 0x1006AA10
// Name: void qh_getmergeset_initial(struct facetT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_getmergeset_initial(facetT *facetlist)
{
  facetT *i; // edi
  unsigned int visit_id; // eax
  setT *neighbors; // eax
  facetT *p; // esi
  facetT **e; // ebx
  setT *ridges; // eax
  setelemT *v7; // edx
  _DWORD *v8; // eax
  facetT *v9; // ecx
  setT *v10; // eax
  setelemT *v11; // ecx
  setelemT v12; // eax
  unsigned int v13; // eax
  int v14; // esi

  ++qh_qh.visit_id;
  if ( facetlist != nullptr )
  {
    for ( i = facetlist; i != nullptr; i = i->next )
    {
      if ( i->next == nullptr )
        break;
      visit_id = qh_qh.visit_id;
      *((_DWORD *)i + 20) |= 0x4000000u;
      i->visitid = visit_id;
      neighbors = i->neighbors;
      if ( neighbors != nullptr )
      {
        p = (facetT *)neighbors->e[0].p;
        e = (facetT **)neighbors->e;
        if ( p != nullptr )
        {
          do
          {
            ++e;
            if ( p->visitid != qh_qh.visit_id && qh_test_appendmerge(facet: i, neighbor: p) != 0 )
            {
              ridges = p->ridges;
              if ( ridges != nullptr )
              {
                v7 = ridges->e;
                v8 = ridges->e[0].p;
                if ( v8 != nullptr )
                {
                  while ( 1 )
                  {
                    v9 = (facetT *)v8[1];
                    ++v7;
                    if ( v9 == p )
                      v9 = (facetT *)v8[2];
                    if ( i == v9 )
                      break;
                    v8 = (_DWORD *)v7->i;
                    if ( v7->i == 0 )
                      goto LABEL_16;
                  }
                  v8[3] |= 0x4000000u;
                }
              }
            }
LABEL_16:
            p = *e;
          }
          while ( *e != nullptr );
        }
      }
      v10 = i->ridges;
      if ( v10 != nullptr )
      {
        v11 = v10->e;
        for ( v12.p = (void *)v10->e[0]; v12.i != 0; ++v11 )
        {
          *(_DWORD *)(v12.i + 12) |= 0x2000000u;
          v12.p = v11[1].p;
        }
      }
    }
  }
  v13 = qh_setsize(set: qh_qh.facet_mergeset);
  v14 = v13;
  if ( qh_qh.ANGLEmerge != 0 )
    qsort(
      base: qh_qh.facet_mergeset->e,
      num: v13,
      width: 4u,
      comp: (int (__cdecl *)(const void *, const void *))qh_compareangle);
  else
    qsort(base: qh_qh.facet_mergeset->e, num: v13, width: 4u, comp: qh_comparevisit);
  if ( qh_qh.POSTmerging != 0 )
  {
    qh_qhstat.stats[107].i += v14;
  }
  else
  {
    qh_qhstat.stats[105].i += v14;
    if ( qh_qhstat.stats[106].i < v14 )
      qh_qhstat.stats[106].i = v14;
  }
  if ( qh_qh.IStracing >= 2 )
    fprintf(str: qh_qh.ferr, format: "qh_getmergeset_initial: %d merges found\n", v14);
}

//------------------------------------------------------------------------------
// Address: 0x1006AB80
// Name: void qh_mergecycle_facets(struct facetT __near *,struct facetT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_mergecycle_facets(facetT *samecycle, facetT *newfacet)
{
  facetT *i; // esi
  facetT *replace; // ebx

  if ( qh_qh.IStracing >= 4 )
    fprintf(str: qh_qh.ferr, format: "qh_mergecycle_facets: make newfacet new and samecycle deleted\n");
  qh_removefacet(facet: newfacet);
  qh_appendfacet(facet: newfacet);
  *((_DWORD *)newfacet + 20) = *((_DWORD *)newfacet + 20) & 0xEFFFEDFF | 0x10000200;
  for ( i = samecycle->f.replace; i != nullptr; i = samecycle != i ? replace : nullptr )
  {
    replace = i->f.replace;
    qh_willdelete(facet: i, replace: newfacet);
  }
  if ( newfacet->center != nullptr && qh_setsize(set: newfacet->vertices) <= qh_qh.hull_dim + 5 )
  {
    qh_memfree(object: (void **)newfacet->center, size: qh_qh.normal_size);
    newfacet->center = nullptr;
  }
  if ( qh_qh.IStracing >= 3 )
    fprintf(
      str: qh_qh.ferr,
      format: "qh_mergecycle_facets: merged facets from cycle f%d into f%d\n",
      samecycle->id,
      newfacet->id);
}

//------------------------------------------------------------------------------
// Address: 0x1006AC50
// Name: void qh_mergesimplex(struct facetT __near *,struct facetT __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_mergesimplex(vertexT *facet1, facetT *facet2, ridgeT **mergeapex)
{
  facetT *v3; // ebx
  vertexT *previous; // ecx
  setT *v5; // eax
  setelemT *e; // ecx
  setelemT v7; // eax
  setT *point; // eax
  setelemT *v9; // edx
  int *p; // eax
  facetT *v11; // ecx
  int v12; // eax
  int v13; // ecx
  int i; // eax
  setT *v15; // ecx
  setelemT v16; // eax
  setelemT *v17; // ecx
  setT **p_vertices; // edi
  setelemT v19; // esi
  int v20; // eax
  unsigned int v21; // edx
  unsigned int v22; // ecx
  setT *vertices; // eax
  vertexT *v24; // esi
  vertexT **v25; // edi
  setT *neighbors; // eax
  setelemT *v27; // ecx
  setelemT v28; // eax
  setT *ridges; // eax
  ridgeT *v30; // edi
  facetT *top; // esi
  setT *v32; // eax
  int v33; // eax
  unsigned int issubset; // [esp+Ch] [ebp-8h]
  int vertex_i; // [esp+10h] [ebp-4h]
  vertexT *apex; // [esp+1Ch] [ebp+8h]
  ridgeT **ridgep; // [esp+24h] [ebp+10h]

  issubset = 0;
  vertex_i = -1;
  if ( mergeapex != nullptr )
  {
    if ( (*((_DWORD *)facet2 + 20) & 0x200) == 0 )
      qh_newvertices(vertices: facet2->vertices);
    v3 = (facetT *)facet1;
    previous = facet1[2].previous->previous;
    apex = previous;
    if ( facet2->vertices->e[0].p == previous )
      issubset = 1;
    else
      qh_setaddnth(setp: &facet2->vertices, nth: 0, newelem: previous);
  }
  else
  {
    ++qh_qhstat.stats[113].i;
    v3 = (facetT *)facet1;
    v5 = (setT *)facet1[2].previous;
    if ( v5 != nullptr )
    {
      e = v5->e;
      for ( v7.p = (void *)v5->e[0]; v7.i != 0; ++e )
      {
        *(_DWORD *)(v7.i + 20) &= ~0x1000000u;
        v7.p = e[1].p;
      }
    }
    point = (setT *)facet1[2].point;
    if ( point != nullptr )
    {
      v9 = point->e;
      p = (int *)point->e[0].p;
      if ( p != nullptr )
      {
        while ( 1 )
        {
          v11 = (facetT *)p[1];
          ++v9;
          if ( v11 == (facetT *)facet1 )
            v11 = (facetT *)p[2];
          if ( v11 == facet2 )
            break;
          p = (int *)v9->i;
          if ( v9->i == 0 )
            goto LABEL_20;
        }
        v12 = *p;
        if ( v12 != 0 )
        {
          v13 = v12 + 4;
          for ( i = *(_DWORD *)(v12 + 4); i != 0; v13 += 4 )
          {
            *(_DWORD *)(i + 20) |= 0x5000000u;
            i = *(_DWORD *)(v13 + 4);
          }
        }
      }
    }
LABEL_20:
    v15 = (setT *)facet1[2].previous;
    v16.i = 0;
    if ( v15 != nullptr )
    {
      v16.p = (void *)v15->e[0];
      v17 = v15->e;
      if ( v16.i != 0 )
      {
        do
        {
          ++v17;
          if ( (*(_BYTE *)(v16.i + 23) & 1) == 0 )
            break;
          v16.p = v17->p;
        }
        while ( v17->i != 0 );
      }
    }
    apex = (vertexT *)v16.i;
    if ( qh_qh.IStracing >= 4 )
      fprintf(
        str: qh_qh.ferr,
        format: "qh_mergesimplex: merge apex v%d of f%d into facet f%d\n",
        *(_DWORD *)(v16.i + 20) & 0xFFFFFF,
        v3->id,
        facet2->id);
    p_vertices = &facet2->vertices;
    if ( facet2->vertices != nullptr )
    {
      v19.p = (void *)(*p_vertices)->e[0];
      vertex_i = 0;
      v20 = qh_setsize(set: *p_vertices);
      if ( v20 > 0 )
      {
        v21 = *((_DWORD *)apex + 5) & 0xFFFFFF;
        do
        {
          v22 = *(_DWORD *)(v19.i + 20) & 0xFFFFFF;
          if ( v22 < v21 )
            break;
          if ( v22 == v21 )
          {
            issubset = 1;
            goto LABEL_33;
          }
          v19.p = (void *)*(&(*p_vertices)[1].maxsize + vertex_i++);
        }
        while ( vertex_i < v20 );
      }
    }
    qh_setaddnth(setp: p_vertices, nth: vertex_i, newelem: apex);
LABEL_33:
    if ( (*((_DWORD *)facet2 + 20) & 0x200) != 0 )
    {
      if ( (*((_DWORD *)apex + 5) & 0x10000000) == 0 )
      {
        qh_removevertex(vertex: apex);
        qh_appendvertex(vertex: apex);
      }
    }
    else
    {
      qh_newvertices(vertices: *p_vertices);
    }
  }
  if ( qh_qh.IStracing >= 4 )
    fprintf(str: qh_qh.ferr, format: "qh_mergesimplex: update vertex neighbors of f%d\n", v3->id);
  vertices = v3->vertices;
  if ( vertices != nullptr )
  {
    v24 = (vertexT *)vertices->e[0].p;
    v25 = (vertexT **)vertices->e;
    if ( v24 != nullptr )
    {
      do
      {
        ++v25;
        if ( v24 != apex || issubset != 0 )
        {
          qh_setdel(set: v24->neighbors, oldelem: v3);
          if ( v24->neighbors[1].maxsize == 0 )
            qh_mergevertex_del(vertex: v24, facet1: v3, facet2);
        }
        else
        {
          qh_setreplace(set: v24->neighbors, oldelem: v3, newelem: facet2);
        }
        v24 = *v25;
      }
      while ( *v25 != nullptr );
    }
  }
  if ( qh_qh.IStracing >= 4 )
    fprintf(
      str: qh_qh.ferr,
      format: "qh_mergesimplex: merge ridges and neighbors of f%d into f%d\n",
      v3->id,
      facet2->id);
  ++qh_qh.visit_id;
  neighbors = facet2->neighbors;
  if ( neighbors != nullptr )
  {
    v27 = neighbors->e;
    v28.p = (void *)neighbors->e[0];
    if ( v28.i != 0 )
    {
      do
      {
        ++v27;
        *(_DWORD *)(v28.i + 72) = qh_qh.visit_id;
        v28.p = v27->p;
      }
      while ( v27->i != 0 );
    }
  }
  ridges = v3->ridges;
  if ( ridges != nullptr )
  {
    v30 = (ridgeT *)ridges->e[0].p;
    ridgep = (ridgeT **)ridges->e;
    if ( v30 != nullptr )
    {
      do
      {
        top = v30->top;
        ++ridgep;
        if ( top == v3 )
          top = v30->bottom;
        if ( top == facet2 )
        {
          qh_setdel(set: facet2->ridges, oldelem: v30);
          qh_setfree(setp: &v30->vertices);
          qh_memfree(object: (void **)&v30->vertices, size: 16);
          qh_setdel(set: facet2->neighbors, oldelem: v3);
        }
        else
        {
          qh_setappend(setp: &facet2->ridges, newelem: v30);
          if ( top->visitid == qh_qh.visit_id )
          {
            if ( (*((_DWORD *)top + 20) & 0x1000) != 0 )
              qh_makeridges(facet: top);
            v32 = top->neighbors;
            if ( v32->e[0].p == v3 )
            {
              qh_setdel(set: v32, oldelem: facet2);
              qh_setreplace(set: top->neighbors, oldelem: v3, newelem: facet2);
            }
            else
            {
              qh_setdel(set: v32, oldelem: v3);
            }
          }
          else
          {
            qh_setappend(setp: &facet2->neighbors, newelem: top);
            qh_setreplace(set: top->neighbors, oldelem: v3, newelem: facet2);
            top->visitid = qh_qh.visit_id;
          }
          if ( v30->top == v3 )
            v30->top = facet2;
          else
            v30->bottom = facet2;
        }
        v30 = *ridgep;
      }
      while ( *ridgep != nullptr );
    }
  }
  v3->ridges->e[0].i = 0;
  if ( qh_qh.IStracing >= 3 )
  {
    if ( apex != nullptr )
      v33 = *((_DWORD *)apex + 5) & 0xFFFFFF;
    else
      v33 = -1;
    fprintf(
      str: qh_qh.ferr,
      format: "qh_mergesimplex: merged simplex f%d apex v%d into facet f%d\n",
      v3->id,
      v33,
      facet2->id);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006B040
// Name: struct setT __near * qh_vertexridges(struct vertexT __near *)
// Source: json
//------------------------------------------------------------------------------
setT *__cdecl qh_vertexridges(vertexT *vertex)
{
  setT *v1; // eax
  setT *neighbors; // eax
  setelemT *e; // ecx
  setelemT v4; // eax
  setT *v5; // eax
  facetT **v6; // esi
  facetT *p; // eax
  int v8; // eax
  setT *ridges; // [esp+4h] [ebp-4h] BYREF

  v1 = qh_settemp(setsize: qh_qh.TEMPsize);
  ++qh_qh.visit_id;
  ridges = v1;
  neighbors = vertex->neighbors;
  if ( neighbors != nullptr )
  {
    e = neighbors->e;
    v4.p = (void *)neighbors->e[0];
    if ( v4.i != 0 )
    {
      do
      {
        ++e;
        *(_DWORD *)(v4.i + 72) = qh_qh.visit_id;
        v4.p = e->p;
      }
      while ( e->i != 0 );
    }
  }
  v5 = vertex->neighbors;
  if ( v5 != nullptr )
  {
    v6 = (facetT **)v5->e;
    p = (facetT *)v5->e[0].p;
    if ( p != nullptr )
    {
      do
      {
        if ( *++v6 != nullptr )
          qh_vertexridges_facet(vertex, facet: p, &ridges);
        p = *v6;
      }
      while ( *v6 != nullptr );
    }
  }
  if ( qh_qh.PRINTstatistics != 0 || qh_qh.IStracing != 0 )
  {
    v8 = qh_setsize(set: ridges);
    ++qh_qhstat.stats[184].i;
    qh_qhstat.stats[185].i += v8;
    if ( qh_qhstat.stats[186].i < v8 )
      qh_qhstat.stats[186].i = v8;
    if ( qh_qh.IStracing >= 3 )
      fprintf(
        str: qh_qh.ferr,
        format: "qh_vertexridges: found %d ridges for v%d\n",
        v8,
        *((_DWORD *)vertex + 5) & 0xFFFFFF);
  }
  return ridges;
}

//------------------------------------------------------------------------------
// Address: 0x1006B120
// Name: struct vertexT __near * qh_find_newvertex(struct vertexT __near *,struct setT __near *,struct setT __near *)
// Source: json
//------------------------------------------------------------------------------
vertexT *__cdecl qh_find_newvertex(vertexT *oldvertex, setT *vertices, setT *ridges)
{
  setT *v3; // ebx
  setelemT v4; // eax
  setelemT *e; // esi
  setT *v6; // edi
  setelemT v7; // eax
  setelemT *v8; // esi
  setelemT v9; // eax
  setelemT *v10; // ecx
  int *p; // eax
  setelemT *v12; // edx
  int v13; // eax
  int v14; // ecx
  int i; // eax
  setelemT v16; // eax
  char *v17; // esi
  int v18; // ebx
  vertexT **v20; // edi
  unsigned int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // ebx
  ridgeT *v25; // eax
  setelemT *v26; // esi
  vertexT *v27; // ebx
  setT *v28; // eax
  ridgeT *v29; // esi
  ridgeT **v30; // edi
  int v31; // eax
  int v32; // [esp-4h] [ebp-20h]
  int hash; // [esp+Ch] [ebp-10h] BYREF
  vertexT **vertexp; // [esp+10h] [ebp-Ch]
  setT *newridges; // [esp+14h] [ebp-8h] BYREF
  int hashsize; // [esp+18h] [ebp-4h]

  if ( qh_qh.IStracing < 4 )
  {
    v3 = vertices;
    v6 = ridges;
  }
  else
  {
    ivp_message(templat: "qh_find_newvertex: find new vertex for v%d from ", *((_DWORD *)oldvertex + 5) & 0xFFFFFF);
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
          ivp_message(templat: "v%d ", *(_DWORD *)(v4.i + 20) & 0xFFFFFF);
          v4.p = e->p;
        }
        while ( e->i != 0 );
      }
    }
    v6 = ridges;
    if ( ridges != nullptr )
    {
      v7.p = (void *)ridges->e[0];
      v8 = ridges->e;
      if ( v7.i != 0 )
      {
        do
        {
          ++v8;
          ivp_message(templat: "r%d ", *(_DWORD *)(v7.i + 12) & 0xFFFFFF);
          v7.p = v8->p;
        }
        while ( v8->i != 0 );
      }
    }
    ivp_message(templat: "\n");
  }
  if ( v3 != nullptr )
  {
    v9.p = (void *)v3->e[0];
    v10 = v3->e;
    if ( v9.i != 0 )
    {
      do
      {
        ++v10;
        *(_DWORD *)(v9.i + 16) = 0;
        v9.p = v10->p;
      }
      while ( v10->i != 0 );
    }
  }
  if ( v6 != nullptr )
  {
    p = (int *)v6->e[0].p;
    v12 = v6->e;
    if ( p != nullptr )
    {
      do
      {
        v13 = *p;
        ++v12;
        if ( v13 != 0 )
        {
          v14 = v13 + 4;
          for ( i = *(_DWORD *)(v13 + 4); i != 0; v14 += 4 )
          {
            ++*(_DWORD *)(i + 16);
            i = *(_DWORD *)(v14 + 4);
          }
        }
        p = (int *)v12->i;
      }
      while ( v12->i != 0 );
    }
  }
  if ( v3 != nullptr )
  {
    v16.p = (void *)v3->e[0];
    v17 = (char *)v3->e;
    if ( v16.i != 0 )
    {
      v18 = v17 - (char *)vertices - 8;
      do
      {
        v17 += 4;
        v18 += 4;
        if ( *(_DWORD *)(v16.i + 16) == 0 )
        {
          qh_setdelnth(set: vertices, nth: v18 >> 2);
          v17 -= 4;
          v18 -= 4;
        }
        v16.p = *(void **)v17;
      }
      while ( *(_DWORD *)v17 != 0 );
      v3 = vertices;
      v6 = ridges;
    }
  }
  qh_qh.vertex_visit += qh_setsize(set: v6);
  if ( qh_setsize(set: v3) != 0 )
  {
    v20 = (vertexT **)v3->e;
    v21 = qh_setsize(set: v3);
    qsort(base: v3->e, num: v21, width: 4u, comp: qh_comparevisit);
    if ( qh_qh.PRINTstatistics != 0 )
    {
      v22 = qh_setsize(set: v3);
      ++qh_qhstat.stats[87].i;
      qh_qhstat.stats[91].i += v22;
      if ( qh_qhstat.stats[89].i < v22 )
        qh_qhstat.stats[89].i = v22;
    }
    v23 = qh_setsize(set: ridges);
    v24 = qh_newhashtable(newsize: v23);
    hashsize = v24;
    if ( ridges != nullptr )
    {
      v25 = (ridgeT *)ridges->e[0].p;
      v26 = ridges->e;
      if ( v25 != nullptr )
      {
        do
        {
          ++v26;
          qh_hashridge(hashtable: qh_qh.hash_table, hashsize: v24, ridge: v25, oldvertex);
          v25 = (ridgeT *)v26->i;
        }
        while ( v26->i != 0 );
      }
    }
    v27 = nullptr;
    if ( vertices == nullptr )
      goto LABEL_46;
    v27 = *v20;
    if ( *v20 == nullptr )
      goto LABEL_46;
    while ( 1 )
    {
      vertexp = v20 + 1;
      v28 = qh_vertexridges(vertex: v27);
      v29 = nullptr;
      newridges = v28;
      if ( v28 != nullptr )
      {
        v29 = (ridgeT *)v28->e[0].p;
        v30 = (ridgeT **)v28->e;
        if ( v29 != nullptr )
        {
          while ( 1 )
          {
            ++v30;
            if ( qh_hashridge_find(
                   hashtable: qh_qh.hash_table,
                   hashsize,
                   ridge: v29,
                   vertex: v27,
                   oldvertex,
                   hashslot: &hash) != nullptr )
              break;
            v29 = *v30;
            if ( *v30 == nullptr )
              goto LABEL_44;
          }
          ++qh_qhstat.stats[73].i;
        }
      }
LABEL_44:
      qh_settempfree(set: &newridges);
      if ( v29 == nullptr )
        break;
      v20 = vertexp;
      v27 = *vertexp;
      if ( *vertexp == nullptr )
        goto LABEL_46;
    }
    if ( v27 != nullptr )
    {
      if ( qh_qh.IStracing >= 2 )
      {
        v32 = qh_setsize(set: ridges);
        v31 = qh_setsize(set: vertices);
        fprintf(
          str: qh_qh.ferr,
          format: "qh_find_newvertex: found v%d for old v%d from %d vertices and %d ridges.\n",
          *((_DWORD *)v27 + 5) & 0xFFFFFF,
          *((_DWORD *)oldvertex + 5) & 0xFFFFFF,
          v31,
          v32);
      }
    }
    else
    {
LABEL_46:
      ++qh_qhstat.stats[75].i;
      if ( qh_qh.IStracing != 0 )
        fprintf(
          str: qh_qh.ferr,
          format: "qh_find_newvertex: no vertex for renaming v%d (all duplicated ridges) during p%d\n",
          *((_DWORD *)oldvertex + 5) & 0xFFFFFF,
          qh_qh.furthest_id);
    }
    qh_setfree(setp: &qh_qh.hash_table);
    return v27;
  }
  else
  {
    if ( qh_qh.IStracing >= 4 )
      fprintf(
        str: qh_qh.ferr,
        format: "qh_find_newvertex: vertices not in ridges for v%d\n",
        *((_DWORD *)oldvertex + 5) & 0xFFFFFF);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006B460
// Name: void qh_mergecycle(struct facetT __near *,struct facetT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_mergecycle(facetT *samecycle, facetT *newfacet)
{
  int i; // eax
  int IStracing; // ecx
  facetT *j; // ebx
  int tracerestore; // [esp+Ch] [ebp-8h]
  int traceonce; // [esp+10h] [ebp-4h]
  vertexT *apex; // [esp+20h] [ebp+Ch]

  traceonce = 0;
  tracerestore = 0;
  if ( qh_qh.VERTEXneighbors == 0 )
    qh_vertexneighbors();
  i = ++qh_qhstat.stats[176].i;
  if ( qh_qh.REPORTfreq2 != 0 && qh_qh.POSTmerging != 0 && i > qh_qh.REPORTfreq2 + qh_qh.mergereport )
  {
    qh_tracemerging();
    i = qh_qhstat.stats[176].i;
  }
  if ( qh_qh.TRACEmerge == i )
  {
    qh_qh.IStracing = qh_qh.TRACElevel;
    qhmem.IStracing = qh_qh.TRACElevel;
  }
  if ( qh_qh.IStracing >= 2 )
  {
    fprintf(
      str: qh_qh.ferr,
      format: "qh_mergecycle: merge #%d for facets from cycle f%d into coplanar horizon f%d\n",
      i,
      samecycle->id,
      newfacet->id);
    i = qh_qhstat.stats[176].i;
  }
  if ( newfacet == qh_qh.tracefacet )
  {
    IStracing = qh_qh.IStracing;
    qh_qh.IStracing = 4;
    tracerestore = IStracing;
    ivp_message(
      templat: "qh_mergecycle: ========= trace merge %d of samecycle %d into trace f%d, furthest is p%d\n",
      i,
      samecycle->id,
      newfacet->id,
      qh_qh.furthest_id);
    traceonce = 1;
  }
  if ( qh_qh.IStracing >= 4 )
  {
    ivp_message(templat: "  same cycle:");
    for ( j = samecycle->f.replace; j != nullptr; j = j->f.replace )
    {
      ivp_message(templat: " f%d", j->id);
      if ( j == samecycle )
        break;
    }
    ivp_message(templat: "\n");
    if ( qh_qh.IStracing >= 4 )
      qh_errprint(
        string: "MERGING CYCLE",
        atfacet: samecycle,
        otherfacet: newfacet,
        atridge: nullptr,
        atvertex: nullptr);
  }
  apex = (vertexT *)samecycle->vertices->e[0].p;
  qh_makeridges(facet: newfacet);
  qh_mergecycle_neighbors(samecycle, newfacet);
  qh_mergecycle_ridges(samecycle, newfacet);
  qh_mergecycle_vneighbors(samecycle, newfacet);
  if ( newfacet->vertices->e[0].p != apex )
    qh_setaddnth(setp: &newfacet->vertices, nth: 0, newelem: apex);
  if ( (*((_DWORD *)newfacet + 20) & 0x200) == 0 )
    qh_newvertices(vertices: newfacet->vertices);
  qh_mergecycle_facets(samecycle, newfacet);
  qh_tracemerge(facet1: samecycle, facet2: newfacet);
  if ( traceonce != 0 )
  {
    ivp_message(templat: "qh_mergecycle: end of trace facet\n");
    qh_qh.IStracing = tracerestore;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006B630
// Name: void qh_mergefacet(struct facetT __near *,struct facetT __near *,double __near *,double __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_mergefacet(
        facetT *facet1,
        facetT *facet2,
        long double *mindist,
        long double *maxdist,
        ridgeT **mergeapex)
{
  double v5; // xmm0_8
  double v6; // xmm0_8
  double v7; // xmm1_8
  int v8; // eax
  int v9; // eax
  unsigned int v10; // ecx
  setT *vertices; // eax
  setelemT *e; // ecx
  setelemT v13; // eax
  int v14; // eax
  int tracerestore; // [esp+20h] [ebp-8h]
  unsigned int traceonce; // [esp+24h] [ebp-4h]

  ++qh_qhstat.stats[176].i;
  traceonce = 0;
  tracerestore = 0;
  if ( qh_qh.REPORTfreq2 != 0
    && qh_qh.POSTmerging != 0
    && qh_qhstat.stats[176].i > qh_qh.REPORTfreq2 + qh_qh.mergereport )
  {
    qh_tracemerging();
  }
  if ( qh_qh.build_cnt >= qh_qh.RERUN )
  {
    if ( mindist != nullptr
      && (COERCE_DOUBLE(*(_QWORD *)mindist ^ _mask__NegDouble_) > qh_qh.TRACEdist || *maxdist > qh_qh.TRACEdist) )
    {
      qh_qh.IStracing = qh_qh.TRACElevel;
      *(_QWORD *)&v5 = *(_QWORD *)mindist ^ _mask__NegDouble_;
      tracerestore = 0;
      traceonce = 1;
      if ( *maxdist > v5 )
        v5 = *maxdist;
      ivp_message(
        templat: "qh_mergefacet: ========= trace wide merge #%d (%2.2g) for f%d into f%d, last point was p%d\n",
        qh_qhstat.stats[176].i,
        v5,
        facet1->id,
        facet2->id,
        qh_qh.furthest_id);
    }
    else if ( facet1 == qh_qh.tracefacet || facet2 == qh_qh.tracefacet )
    {
      traceonce = 1;
      tracerestore = qh_qh.IStracing;
      qh_qh.IStracing = 4;
      ivp_message(
        templat: "qh_mergefacet: ========= trace merge #%d involving f%d, furthest is p%d\n",
        qh_qhstat.stats[176].i,
        qh_qh.tracefacet_id,
        qh_qh.furthest_id);
    }
  }
  if ( qh_qh.IStracing >= 2 )
  {
    v6 = -2.0;
    v7 = -2.0;
    if ( mindist != nullptr )
    {
      v6 = *mindist;
      v7 = *maxdist;
    }
    ivp_message(
      templat: "qh_mergefacet: #%d merge f%d into f%d, mindist= %2.2g, maxdist= %2.2g\n",
      qh_qhstat.stats[176].i,
      facet1->id,
      facet2->id,
      v6,
      v7);
  }
  if ( facet1 == facet2 || (*((_DWORD *)facet1 + 20) & 0x400) != 0 || (*((_DWORD *)facet2 + 20) & 0x400) != 0 )
  {
    ivp_message(
      templat: "qhull internal error (qh_mergefacet): either f%d and f%d are the same or one is a visible facet\n",
      facet1->id,
      facet2->id);
    qh_errexit2(exitcode: 5, facet: facet1, otherfacet: facet2);
  }
  if ( qh_qh.num_facets - qh_qh.num_visible <= qh_qh.hull_dim + 1 )
  {
    ivp_message(
      templat: "\n"
      "qhull precision error: Only %d facets remain.  Can not merge another\n"
      "pair.  The convexity constraints may be too strong.  Reduce the\n"
      "magnitude of 'Cn' or increase the magnitude of 'An'.  For example,\n"
      "try 'C-0.001' instead of 'C-0.1' or 'A-0.999' instead of 'A-0.9'.\n",
      qh_qh.hull_dim + 1);
    if ( qh_qh.hull_dim >= 5 && qh_qh.MERGEexact == 0 )
      ivp_message(templat: "Option 'Qx' may avoid this problem.\n");
    qh_errexit(exitcode: 1, facet: nullptr, ridge: nullptr);
  }
  if ( qh_qh.VERTEXneighbors == 0 )
    qh_vertexneighbors();
  qh_makeridges(facet: facet1);
  qh_makeridges(facet: facet2);
  if ( qh_qh.IStracing >= 4 )
    qh_errprint(string: "MERGING", atfacet: facet1, otherfacet: facet2, atridge: nullptr, atvertex: nullptr);
  if ( mindist != nullptr )
  {
    if ( *maxdist > qh_qh.max_outside )
      qh_qh.max_outside = *maxdist;
    if ( *maxdist > qh_qh.max_vertex )
      qh_qh.max_vertex = *maxdist;
    if ( *maxdist > facet2->maxoutside )
      facet2->maxoutside = *maxdist;
    if ( qh_qh.min_vertex > *mindist )
      qh_qh.min_vertex = *mindist;
    v8 = *((_DWORD *)facet2 + 20);
    if ( (v8 & 0x8000000) == 0 && (*maxdist > qh_qh.WIDEfacet || -qh_qh.WIDEfacet > *mindist) )
    {
      *((_DWORD *)facet2 + 20) = v8 | 0x8000000;
      ++qh_qhstat.stats[192].i;
    }
  }
  v9 = *((_DWORD *)facet2 + 20);
  v10 = (*((_DWORD *)facet1 + 20) & 0x1FF) + (v9 & 0x1FF) + 1;
  if ( v10 < 0x1FF )
    *((_DWORD *)facet2 + 20) = v9 ^ ((unsigned __int16)v10 ^ (unsigned __int16)v9) & 0x1FF;
  else
    *((_DWORD *)facet2 + 20) = v9 | 0x1FF;
  *((_DWORD *)facet2 + 20) = *((_DWORD *)facet2 + 20) & 0xEFEFFFFF | 0x10000000;
  qh_updatetested(facet1, facet2);
  if ( qh_qh.hull_dim > 2 && qh_setsize(set: facet1->vertices) == qh_qh.hull_dim )
  {
    qh_mergesimplex((vertexT *)facet1, facet2, mergeapex);
  }
  else
  {
    ++qh_qh.vertex_visit;
    vertices = facet2->vertices;
    if ( vertices != nullptr )
    {
      e = vertices->e;
      v13.p = (void *)vertices->e[0];
      if ( v13.i != 0 )
      {
        do
        {
          ++e;
          *(_DWORD *)(v13.i + 16) = qh_qh.vertex_visit;
          v13.p = e->p;
        }
        while ( e->i != 0 );
      }
    }
    if ( qh_qh.hull_dim == 2 )
    {
      qh_mergefacet2d(facet1, facet2);
    }
    else
    {
      qh_mergeneighbors(facet1, facet2);
      qh_mergevertices(vertices1: facet1->vertices, vertices2: &facet2->vertices);
    }
    qh_mergeridges(facet1, facet2);
    qh_mergevertex_neighbors(facet1, facet2);
    if ( (*((_DWORD *)facet2 + 20) & 0x200) == 0 )
      qh_newvertices(vertices: facet2->vertices);
  }
  if ( mergeapex == nullptr )
    qh_degen_redundant_neighbors(facet: facet2, delfacet: facet1);
  v14 = *((_DWORD *)facet2 + 20);
  if ( (v14 & 0x800000) != 0 || (v14 & 0x200) == 0 )
  {
    ++qh_qhstat.stats[108].i;
  }
  else if ( (*((_DWORD *)facet1 + 20) & 0x200) != 0 )
  {
    ++qh_qhstat.stats[109].i;
  }
  else
  {
    ++qh_qhstat.stats[104].i;
  }
  qh_willdelete(facet: facet1, replace: facet2);
  qh_removefacet(facet: facet2);
  qh_appendfacet(facet: facet2);
  *((_DWORD *)facet2 + 20) = *((_DWORD *)facet2 + 20) & 0xFBFFFDFF | 0x200;
  qh_tracemerge(facet1, facet2);
  if ( traceonce != 0 )
  {
    ivp_message(templat: "qh_mergefacet: end of wide tracing\n");
    qh_qh.IStracing = tracerestore;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006BAB0
// Name: struct vertexT __near * qh_redundant_vertex(struct vertexT __near *)
// Source: json
//------------------------------------------------------------------------------
vertexT *__cdecl qh_redundant_vertex(vertexT *vertex)
{
  vertexT *newvertex; // edi
  setT *vertices; // [esp+8h] [ebp-8h] BYREF
  setT *ridges; // [esp+Ch] [ebp-4h] BYREF

  newvertex = nullptr;
  if ( qh_qh.IStracing >= 3 )
    fprintf(
      str: qh_qh.ferr,
      format: "qh_redundant_vertex: check if v%d can be renamed\n",
      *((_DWORD *)vertex + 5) & 0xFFFFFF);
  vertices = qh_neighbor_intersections(vertex);
  if ( vertices != nullptr )
  {
    ridges = qh_vertexridges(vertex);
    newvertex = qh_find_newvertex(oldvertex: vertex, vertices, ridges);
    if ( newvertex != nullptr )
      qh_renamevertex(oldvertex: vertex, newvertex, ridges, oldfacet: nullptr, neighborA: nullptr);
    qh_settempfree(set: &ridges);
    qh_settempfree(set: &vertices);
  }
  return newvertex;
}

//------------------------------------------------------------------------------
// Address: 0x1006BB40
// Name: struct vertexT __near * qh_rename_sharedvertex(struct vertexT __near *,struct facetT __near *)
// Source: json
//------------------------------------------------------------------------------
vertexT *__cdecl qh_rename_sharedvertex(setT *vertex, facetT *facet)
{
  setT *v2; // esi
  facetT *v3; // edi
  setelemT v4; // eax
  facetT *v5; // ebx
  setT *neighbors; // ecx
  setelemT v8; // eax
  setelemT *e; // ecx
  setelemT v10; // eax
  facetT **v11; // ecx
  facetT *v12; // eax
  int v13; // eax
  vertexT *newvertex; // ebx
  int v15; // [esp-10h] [ebp-20h]
  unsigned int v16; // [esp-Ch] [ebp-1Ch]
  int v17; // [esp-8h] [ebp-18h]
  unsigned int id; // [esp-4h] [ebp-14h]
  setT *vertices; // [esp+Ch] [ebp-4h] BYREF

  v2 = vertex;
  v3 = nullptr;
  if ( qh_setsize(set: (setT *)vertex[1].e[0].p) == 2 )
  {
    v4.p = (void *)v2[1].e[0];
    v3 = *(facetT **)(v4.i + 4);
    v5 = facet;
    if ( v3 == facet )
      v3 = *(facetT **)(v4.i + 8);
  }
  else
  {
    if ( qh_qh.hull_dim == 3 )
      return nullptr;
    ++qh_qh.visit_id;
    v5 = facet;
    neighbors = facet->neighbors;
    if ( neighbors != nullptr )
    {
      v8.p = (void *)neighbors->e[0];
      e = neighbors->e;
      if ( v8.i != 0 )
      {
        do
        {
          ++e;
          *(_DWORD *)(v8.i + 72) = qh_qh.visit_id;
          v8.p = e->p;
        }
        while ( e->i != 0 );
      }
    }
    v10.p = (void *)v2[1].e[0];
    if ( v10.i == 0 )
      goto LABEL_16;
    v11 = (facetT **)(v10.i + 4);
    v12 = *(facetT **)(v10.i + 4);
    if ( v12 == nullptr )
      goto LABEL_16;
    do
    {
      ++v11;
      if ( v12->visitid == qh_qh.visit_id )
      {
        if ( v3 != nullptr )
          return nullptr;
        v3 = v12;
      }
      v12 = *v11;
    }
    while ( *v11 != nullptr );
    if ( v3 == nullptr )
    {
LABEL_16:
      ivp_message(
        templat: "qhull internal error (qh_rename_sharedvertex): v%d's neighbors not in f%d\n",
        v2[2].e[0].i & 0xFFFFFF,
        v5->id);
      qh_errprint(string: "ERRONEOUS", atfacet: v5, otherfacet: nullptr, atridge: nullptr, atvertex: (vertexT *)v2);
      qh_errexit(exitcode: 5, facet: nullptr, ridge: nullptr);
    }
  }
  vertex = qh_settemp(setsize: qh_qh.TEMPsize);
  v3->visitid = ++qh_qh.visit_id;
  qh_vertexridges_facet(vertex: (vertexT *)v2, facet: v5, ridges: &vertex);
  if ( qh_qh.IStracing >= 2 )
  {
    id = v3->id;
    v17 = qh_setsize(set: vertex);
    v16 = v5->id;
    v15 = v2[2].e[0].i & 0xFFFFFF;
    v13 = qh_pointid(point: (long double *)v2[1].maxsize);
    fprintf(
      str: qh_qh.ferr,
      format: "qh_rename_sharedvertex: p%d (v%d) is shared by f%d (%d ridges) and f%d\n",
      v13,
      v15,
      v16,
      v17,
      id);
  }
  ++qh_qhstat.stats[90].i;
  vertices = qh_vertexintersect_new(vertexsetA: v5->vertices, vertexsetB: v3->vertices);
  qh_setdel(set: vertices, oldelem: v2);
  qh_settemppush(set: vertices);
  newvertex = qh_find_newvertex(oldvertex: (vertexT *)v2, vertices, ridges: vertex);
  if ( newvertex != nullptr )
    qh_renamevertex(oldvertex: (vertexT *)v2, newvertex, ridges: vertex, oldfacet: facet, neighborA: v3);
  qh_settempfree(set: &vertices);
  qh_settempfree(set: &vertex);
  return newvertex;
}

//------------------------------------------------------------------------------
// Address: 0x1006BD10
// Name: void qh_forcedmerges(unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_forcedmerges(unsigned int *wasmerge)
{
  int v1; // edi
  setT *v2; // eax
  mergeT *p; // ebx
  char *e; // ecx
  bool v5; // zf
  facetT *facet1; // esi
  facetT *i; // edi
  double v8; // xmm0_8
  setelemT *v9; // esi
  setelemT v10; // eax
  long double mindist2; // [esp+20h] [ebp-40h] BYREF
  long double maxdist2; // [esp+28h] [ebp-38h] BYREF
  long double mindist1; // [esp+30h] [ebp-30h] BYREF
  long double maxdist1; // [esp+38h] [ebp-28h] BYREF
  double dist2; // [esp+40h] [ebp-20h]
  double dist1; // [esp+48h] [ebp-18h]
  mergeT **mergep; // [esp+50h] [ebp-10h]
  int numflip; // [esp+54h] [ebp-Ch]
  int nummerge; // [esp+58h] [ebp-8h]
  setT *othermerges; // [esp+5Ch] [ebp-4h] BYREF

  v1 = 0;
  nummerge = 0;
  numflip = 0;
  if ( qh_qh.TRACEmerge - 1 == qh_qhstat.stats[176].i )
  {
    qh_qh.IStracing = qh_qh.TRACElevel;
    qhmem.IStracing = qh_qh.TRACElevel;
  }
  if ( qh_qh.IStracing >= 4 )
    fprintf(str: qh_qh.ferr, format: "qh_forcedmerges: begin\n");
  othermerges = qh_settemppop();
  qh_qh.facet_mergeset = qh_settemp(setsize: qh_qh.TEMPsize);
  qh_settemppush(set: othermerges);
  v2 = othermerges;
  if ( othermerges != nullptr )
  {
    p = (mergeT *)othermerges->e[0].p;
    e = (char *)othermerges->e;
    if ( p != nullptr )
    {
      do
      {
        v5 = p->type == MRGridge;
        mergep = (mergeT **)(e + 4);
        if ( v5 )
        {
          facet1 = p->facet1;
          for ( i = p->facet2; (*((_DWORD *)facet1 + 20) & 0x400) != 0; facet1 = facet1->f.replace )
            ;
          for ( ; (*((_DWORD *)i + 20) & 0x400) != 0; i = i->f.replace )
            ;
          if ( facet1 != i )
          {
            if ( qh_setin(set: i->neighbors, setelem: facet1) == 0 )
            {
              ivp_message(
                templat: "qhull internal error (qh_forcedmerges): f%d and f%d had a duplicate ridge but as f%d and f%d they are no"
                " longer neighbors\n",
                p->facet1->id,
                p->facet2->id,
                facet1->id,
                i->id);
              qh_errexit2(exitcode: 5, facet: facet1, otherfacet: i);
            }
            if ( qh_qh.TRACEmerge - 1 == qh_qhstat.stats[176].i )
            {
              qh_qh.IStracing = qh_qh.TRACElevel;
              qhmem.IStracing = qh_qh.TRACElevel;
            }
            dist1 = qh_getdistance(facet: facet1, neighbor: i, mindist: &mindist1, maxdist: &maxdist1);
            dist2 = qh_getdistance(facet: i, neighbor: facet1, mindist: &mindist2, maxdist: &maxdist2);
            if ( qh_qh.IStracing != 0 )
              fprintf(
                str: qh_qh.ferr,
                format: "qh_forcedmerges: duplicate ridge between f%d and f%d, dist %2.2g and reverse dist %2.2g during p%d\n",
                facet1->id,
                i->id,
                dist1,
                dist2,
                qh_qh.furthest_id);
            if ( dist2 <= dist1 )
            {
              qh_mergefacet(facet1: i, facet2: facet1, mindist: &mindist2, maxdist: &maxdist2, mergeapex: nullptr);
              v8 = dist2;
              facet1 = i;
            }
            else
            {
              qh_mergefacet(facet1, facet2: i, mindist: &mindist1, maxdist: &maxdist1, mergeapex: nullptr);
              v8 = dist1;
            }
            if ( (*((_DWORD *)facet1 + 20) & 0x8000) != 0 )
            {
              ++qh_qhstat.stats[103].i;
              ++numflip;
            }
            else
            {
              ++nummerge;
            }
            if ( qh_qh.PRINTstatistics != 0 )
            {
              ++qh_qhstat.stats[70].i;
              qh_qhstat.stats[72].r = qh_qhstat.stats[72].r + v8;
              if ( v8 > qh_qhstat.stats[71].r )
                qh_qhstat.stats[71].r = v8;
            }
          }
        }
        e = (char *)mergep;
        p = *mergep;
      }
      while ( *mergep != nullptr );
      v2 = othermerges;
      v1 = nummerge;
    }
    if ( v2 != nullptr )
    {
      v9 = v2->e;
      v10.p = (void *)v2->e[0];
      if ( v10.i != 0 )
      {
        do
        {
          ++v9;
          if ( *(_DWORD *)(v10.i + 16) == 5 )
            qh_memfree(object: (void **)v10.p, size: 24);
          else
            qh_setappend(setp: &qh_qh.facet_mergeset, newelem: v10.p);
          v10.p = v9->p;
        }
        while ( v9->i != 0 );
      }
    }
  }
  qh_settempfree(set: &othermerges);
  if ( v1 != 0 )
    *wasmerge = 1;
  if ( qh_qh.IStracing >= 1 )
    fprintf(
      str: qh_qh.ferr,
      format: "qh_forcedmerges: merged %d facets and %d flipped facets across duplicated ridges\n",
      v1,
      numflip);
}

//------------------------------------------------------------------------------
// Address: 0x1006BFC0
// Name: int qh_merge_degenredundant(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl qh_merge_degenredundant()
{
  void **v0; // eax
  facetT *v1; // edi
  facetT *replace; // esi
  void *v3; // ebx
  int v4; // eax
  int v5; // eax
  int v6; // ebx
  setT *vertices; // eax
  int i; // esi
  int *e; // ebx
  facetT *v10; // eax
  facetT *v11; // esi
  long double mindist; // [esp+14h] [ebp-1Ch] BYREF
  long double maxdist; // [esp+1Ch] [ebp-14h] BYREF
  long double dist; // [esp+24h] [ebp-Ch] BYREF
  int nummerges; // [esp+2Ch] [ebp-4h]

  nummerges = 0;
  v0 = (void **)qh_setdellast(set: qh_qh.degen_mergeset);
  if ( v0 == nullptr )
    return 0;
  do
  {
    v1 = (facetT *)v0[2];
    replace = (facetT *)v0[3];
    v3 = v0[4];
    qh_memfree(object: v0, size: 24);
    v4 = *((_DWORD *)v1 + 20);
    if ( (v4 & 0x400) == 0 )
    {
      *((_DWORD *)v1 + 20) = v4 & 0x9FFFFFFF;
      if ( qh_qh.TRACEmerge - 1 == qh_qhstat.stats[176].i )
      {
        qh_qh.IStracing = qh_qh.TRACElevel;
        qhmem.IStracing = qh_qh.TRACElevel;
      }
      if ( v3 == (void *)7 )
      {
        ++qh_qhstat.stats[120].i;
        for ( ; (*((_DWORD *)replace + 20) & 0x400) != 0; replace = replace->f.replace )
        {
          if ( replace->f.replace == nullptr )
          {
            ivp_message(
              templat: "qhull internal error (qh_merge_degenredunant): f%d redundant but f%d has no replacement\n",
              v1->id,
              replace->id);
            qh_errexit2(exitcode: 5, facet: v1, otherfacet: replace);
          }
        }
        if ( v1 == replace )
        {
          qh_degen_redundant_facet(facet: v1);
        }
        else
        {
          if ( qh_qh.IStracing >= 2 )
            fprintf(
              str: qh_qh.ferr,
              format: "qh_merge_degenredundant: facet f%d is contained in f%d, will merge\n",
              v1->id,
              replace->id);
          qh_mergefacet(facet1: v1, facet2: replace, mindist: nullptr, maxdist: nullptr, mergeapex: nullptr);
          ++nummerges;
        }
      }
      else
      {
        v5 = qh_setsize(set: v1->neighbors);
        v6 = v5;
        if ( v5 != 0 )
        {
          if ( v5 < qh_qh.hull_dim )
          {
            v10 = qh_findbestneighbor(facet: v1, distp: &dist, mindistp: &mindist, maxdistp: &maxdist);
            v11 = v10;
            if ( qh_qh.IStracing >= 2 )
              fprintf(
                str: qh_qh.ferr,
                format: "qh_merge_degenredundant: facet f%d has %d neighbors, merge into f%d dist %2.2g\n",
                v1->id,
                v6,
                v10->id,
                (double)dist);
            qh_mergefacet(facet1: v1, facet2: v11, &mindist, &maxdist, mergeapex: nullptr);
            ++nummerges;
            if ( qh_qh.PRINTstatistics != 0 )
            {
              ++qh_qhstat.stats[39].i;
              qh_qhstat.stats[41].r = qh_qhstat.stats[41].r + dist;
              if ( dist > qh_qhstat.stats[40].r )
                qh_qhstat.stats[40].r = dist;
            }
          }
        }
        else
        {
          ++qh_qhstat.stats[43].i;
          if ( qh_qh.IStracing >= 2 )
            fprintf(str: qh_qh.ferr, format: "qh_merge_degenredundant: facet f%d has no neighbors.  Deleted\n", v1->id);
          qh_willdelete(facet: v1, replace: nullptr);
          vertices = v1->vertices;
          if ( vertices != nullptr )
          {
            i = vertices->e[0].i;
            e = (int *)vertices->e;
            if ( i != 0 )
            {
              do
              {
                ++e;
                qh_setdel(set: *(setT **)(i + 12), oldelem: v1);
                if ( *(_DWORD *)(*(_DWORD *)(i + 12) + 4) == 0 )
                {
                  ++qh_qhstat.stats[42].i;
                  if ( qh_qh.IStracing >= 2 )
                    fprintf(
                      str: qh_qh.ferr,
                      format: "qh_merge_degenredundant: deleted v%d because f%d has no neighbors\n",
                      *(_DWORD *)(i + 20) & 0xFFFFFF,
                      v1->id);
                  *(_DWORD *)(i + 20) |= 0x8000000u;
                  qh_setappend(setp: &qh_qh.del_vertices, newelem: (void *)i);
                }
                i = *e;
              }
              while ( *e != 0 );
            }
          }
          ++nummerges;
        }
      }
    }
    v0 = (void **)qh_setdellast(set: qh_qh.degen_mergeset);
  }
  while ( v0 != nullptr );
  return nummerges;
}

//------------------------------------------------------------------------------
// Address: 0x1006C270
// Name: void qh_merge_nonconvex(struct facetT __near *,struct facetT __near *,enum mergeType)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_merge_nonconvex(facetT *facet1, facetT *facet2, mergeType mergetype)
{
  facetT *v3; // ebx
  facetT *v4; // esi
  facetT *v5; // edi
  facetT *v6; // eax
  double v7; // xmm0_8
  long double mindist2; // [esp+20h] [ebp-30h] BYREF
  long double maxdist2; // [esp+28h] [ebp-28h] BYREF
  double dist2; // [esp+30h] [ebp-20h] BYREF
  double dist; // [esp+38h] [ebp-18h] BYREF
  long double mindist; // [esp+40h] [ebp-10h] BYREF
  long double maxdist; // [esp+48h] [ebp-8h] BYREF
  facetT *bestneighbor; // [esp+58h] [ebp+8h]

  if ( qh_qh.TRACEmerge - 1 == qh_qhstat.stats[176].i )
  {
    qh_qh.IStracing = qh_qh.TRACElevel;
    qhmem.IStracing = qh_qh.TRACElevel;
  }
  v3 = facet1;
  v4 = facet2;
  if ( qh_qh.IStracing >= 3 )
    fprintf(
      str: qh_qh.ferr,
      format: "qh_merge_nonconvex: merge #%d for f%d and f%d type %d\n",
      qh_qhstat.stats[176].i + 1,
      facet1->id,
      facet2->id,
      mergetype);
  if ( (*((_DWORD *)facet1 + 20) & 0x200) != 0 )
  {
    v5 = facet1;
  }
  else
  {
    v5 = facet2;
    v4 = facet1;
    v3 = facet2;
  }
  bestneighbor = qh_findbestneighbor(facet: v5, distp: &dist, mindistp: &mindist, maxdistp: &maxdist);
  v6 = qh_findbestneighbor(facet: v4, distp: &dist2, mindistp: &mindist2, maxdistp: &maxdist2);
  if ( dist2 > dist )
    goto LABEL_9;
  if ( qh_qh.AVOIDold != 0
    && (*((_DWORD *)v4 + 20) & 0x200) == 0
    && (mindist >= -qh_qh.MAXcoplanar && qh_qh.max_outside >= maxdist || dist2 > dist * 1.5) )
  {
    ++qh_qhstat.stats[11].i;
    qh_qhstat.stats[13].r = qh_qhstat.stats[13].r + dist;
    if ( dist > qh_qhstat.stats[12].r )
      qh_qhstat.stats[12].r = dist;
    if ( qh_qh.IStracing >= 2 )
      fprintf(
        str: qh_qh.ferr,
        format: "qh_merge_nonconvex: avoid merging old facet f%d dist %2.2g.  Use f%d dist %2.2g instead\n",
        v4->id,
        dist2,
        v3->id,
        dist2);
LABEL_9:
    qh_mergefacet(facet1: v5, facet2: bestneighbor, &mindist, &maxdist, mergeapex: nullptr);
    v7 = dist;
    goto LABEL_21;
  }
  qh_mergefacet(facet1: v4, facet2: v6, mindist: &mindist2, maxdist: &maxdist2, mergeapex: nullptr);
  v7 = dist2;
LABEL_21:
  if ( qh_qh.PRINTstatistics != 0 )
  {
    if ( mergetype == MRGanglecoplanar )
    {
      ++qh_qhstat.stats[0].i;
      qh_qhstat.stats[2].r = qh_qhstat.stats[2].r + v7;
      if ( v7 > qh_qhstat.stats[1].r )
        qh_qhstat.stats[1].r = v7;
    }
    else if ( mergetype == MRGconcave )
    {
      ++qh_qhstat.stats[20].i;
      qh_qhstat.stats[22].r = qh_qhstat.stats[22].r + v7;
      if ( v7 > qh_qhstat.stats[21].r )
        qh_qhstat.stats[21].r = v7;
    }
    else
    {
      ++qh_qhstat.stats[25].i;
      qh_qhstat.stats[27].r = qh_qhstat.stats[27].r + v7;
      if ( v7 > qh_qhstat.stats[26].r )
        qh_qhstat.stats[26].r = v7;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006C4D0
// Name: void qh_mergecycle_all(struct facetT __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_mergecycle_all(facetT *facetlist, unsigned int *wasmerge)
{
  int v2; // esi
  facetT *v3; // edi
  facetT *next; // ebx
  facetT *replace; // esi
  facetT *p; // edx
  setT *vertices; // eax
  setelemT v8; // esi
  setelemT *e; // ecx
  setelemT v10; // eax
  facetT *i; // ebx
  int v12; // ecx
  int v13; // eax
  facetT *nextsame; // [esp+4h] [ebp-10h]
  facetT *horizon; // [esp+8h] [ebp-Ch]
  int cycles; // [esp+Ch] [ebp-8h]
  int facets; // [esp+10h] [ebp-4h]
  facetT *nextfacet; // [esp+1Ch] [ebp+8h]

  v2 = 0;
  cycles = 0;
  if ( qh_qh.IStracing >= 2 )
    fprintf(str: qh_qh.ferr, format: "qh_mergecycle_all: begin\n");
  v3 = facetlist;
  if ( facetlist != nullptr )
  {
    do
    {
      next = v3->next;
      nextfacet = next;
      if ( next == nullptr )
        break;
      if ( v3->normal == nullptr )
      {
        if ( (*((_BYTE *)v3 + 83) & 1) == 0 )
        {
          ivp_message(templat: "qh_mergecycle_all: f%d without normal\n", v3->id);
          qh_errexit(exitcode: 5, facet: v3, ridge: nullptr);
        }
        replace = v3->f.replace;
        p = (facetT *)v3->neighbors->e[0].p;
        horizon = p;
        if ( replace == v3 )
        {
          ++qh_qhstat.stats[140].i;
          vertices = v3->vertices;
          v8.p = (void *)vertices->e[0];
          e = vertices->e;
          if ( vertices != nullptr )
          {
            v10.p = (void *)vertices->e[0];
            if ( v8.i != 0 )
            {
              do
              {
                ++e;
                if ( v10.i != v8.i )
                  *(_DWORD *)(v10.i + 20) |= 0x4000000u;
                v10.p = e->p;
              }
              while ( e->i != 0 );
            }
          }
          p->f.replace = nullptr;
          qh_mergefacet(facet1: v3, facet2: p, mindist: nullptr, maxdist: nullptr, mergeapex: (ridgeT **)1);
        }
        else
        {
          facets = 0;
          for ( i = v3; replace != nullptr; replace = v3 != replace ? nextsame : nullptr )
          {
            nextsame = replace->f.replace;
            if ( (*((_DWORD *)replace + 20) & 0x2000400) != 0 )
              qh_infiniteloop(facet: replace);
            *((_DWORD *)replace + 20) |= 0x2000000u;
            if ( replace->normal != nullptr )
            {
              i->f.replace = replace->f.replace;
              replace->f.replace = nullptr;
            }
            else
            {
              ++facets;
              i = replace;
            }
          }
          do
          {
            if ( (*((_DWORD *)nextfacet + 20) & 0x2000000) == 0 )
              break;
            nextfacet = nextfacet->next;
          }
          while ( nextfacet != nullptr );
          p->f.replace = nullptr;
          qh_mergecycle(samecycle: v3, newfacet: p);
          v12 = *((_DWORD *)horizon + 20);
          v13 = facets + (v12 & 0x1FF);
          if ( v13 <= 511 )
            *((_DWORD *)horizon + 20) = v12 ^ ((unsigned __int16)v13 ^ (unsigned __int16)v12) & 0x1FF;
          else
            *((_DWORD *)horizon + 20) = v12 | 0x1FF;
          ++qh_qhstat.stats[37].i;
          qh_qhstat.stats[36].i += facets;
          next = nextfacet;
          if ( qh_qhstat.stats[35].i < facets )
            qh_qhstat.stats[35].i = facets;
        }
        ++cycles;
      }
      v3 = next;
    }
    while ( next != nullptr );
    v2 = cycles;
    if ( cycles != 0 )
      *wasmerge = 1;
  }
  if ( qh_qh.IStracing >= 1 )
    fprintf(str: qh_qh.ferr, format: "qh_mergecycle_all: merged %d same cycles or facets into coplanar horizons\n", v2);
}

//------------------------------------------------------------------------------
// Address: 0x1006C6C0
// Name: unsigned int qh_reducevertices(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl qh_reducevertices()
{
  int v0; // ebx
  facetT *i; // esi
  int v3; // eax
  facetT *j; // edi
  int v5; // eax
  setT *vertices; // eax
  setT **e; // esi
  setT *p; // eax
  vertexT *k; // esi
  int v10; // eax
  int numrename; // [esp+4h] [ebp-8h]
  unsigned int degenredun; // [esp+8h] [ebp-4h]

  v0 = 0;
  numrename = 0;
  if ( qh_qh.hull_dim == 2 )
    return 0;
  degenredun = qh_merge_degenredundant() != 0;
LABELrestart_0:
  for ( i = qh_qh.newfacet_list; i != nullptr; i = i->next )
  {
    if ( i->next == nullptr )
      break;
    v3 = *((_DWORD *)i + 20);
    if ( (v3 & 0x10000000) != 0 )
    {
      if ( qh_qh.MERGEvertices == 0 )
        *((_DWORD *)i + 20) = v3 & 0xEFFFFFFF;
      qh_remove_extravertices(facet: i);
    }
  }
  if ( qh_qh.MERGEvertices == 0 )
    return 0;
  for ( j = qh_qh.newfacet_list; j != nullptr; j = j->next )
  {
    if ( j->next == nullptr )
      break;
    v5 = *((_DWORD *)j + 20);
    if ( (v5 & 0x10000000) != 0 )
    {
      *((_DWORD *)j + 20) = v5 & 0xEFFFFFFF;
      vertices = j->vertices;
      if ( vertices != nullptr )
      {
        e = (setT **)vertices->e;
        p = (setT *)vertices->e[0].p;
        if ( p != nullptr )
        {
          do
          {
            ++e;
            if ( (p[2].e[0].i & 0x4000000) != 0 && qh_rename_sharedvertex(vertex: p, facet: j) != nullptr )
            {
              ++v0;
              --e;
            }
            p = *e;
          }
          while ( *e != nullptr );
        }
      }
    }
  }
  for ( k = qh_qh.newvertex_list; k != nullptr && k->next != nullptr; k = k->next )
  {
    v10 = *((_DWORD *)k + 5);
    if ( (v10 & 0x4000000) != 0 && (v10 & 0x8000000) == 0 )
    {
      *((_DWORD *)k + 5) = v10 & 0xFBFFFFFF;
      if ( qh_qh.hull_dim >= 4 && qh_redundant_vertex(vertex: k) != nullptr )
      {
        ++numrename;
        if ( qh_merge_degenredundant() != 0 )
        {
          degenredun = 1;
          goto LABELrestart_0;
        }
      }
    }
  }
  if ( qh_qh.IStracing >= 1 )
    fprintf(
      str: qh_qh.ferr,
      format: "qh_reducevertices: renamed %d shared vertices and %d redundant vertices. Degen? %d\n",
      v0,
      numrename,
      degenredun);
  return degenredun;
}

//------------------------------------------------------------------------------
// Address: 0x1006C830
// Name: void qh_all_merges(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_all_merges(unsigned int othermerge, unsigned int vneighbors)
{
  unsigned int id; // eax
  void **i; // eax
  facetT *v4; // edx
  facetT *v5; // edi
  mergeType v6; // esi
  void **v7; // ecx
  int v8; // eax
  int v9; // ecx
  int v10; // eax
  vertexT *vertex_list; // eax
  vertexT *next; // ecx
  unsigned int wasmerge; // [esp+Ch] [ebp-14h]
  int numcoplanar; // [esp+10h] [ebp-10h]
  int numconcave; // [esp+14h] [ebp-Ch]
  int numdegenredun; // [esp+18h] [ebp-8h]
  int numnewmerges; // [esp+1Ch] [ebp-4h]

  numcoplanar = 0;
  numconcave = 0;
  numdegenredun = 0;
  numnewmerges = 0;
  if ( qh_qh.IStracing >= 2 )
  {
    if ( qh_qh.newfacet_list != nullptr )
      id = qh_qh.newfacet_list->id;
    else
      id = -1;
    fprintf(str: qh_qh.ferr, format: "qh_all_merges: starting to merge facets beginning from f%d\n", id);
  }
  do
  {
    while ( 1 )
    {
      wasmerge = 0;
      while ( qh_setsize(set: qh_qh.facet_mergeset) != 0 )
      {
        for ( i = (void **)qh_setdellast(set: qh_qh.facet_mergeset);
              i != nullptr;
              i = (void **)qh_setdellast(set: qh_qh.facet_mergeset) )
        {
          v4 = (facetT *)i[2];
          v5 = (facetT *)i[3];
          v6 = (mergeType)i[4];
          ++qhmem.freeshort;
          v7 = &qhmem.freelists[qhmem.indextable[24]];
          *i = *v7;
          *v7 = i;
          v8 = *((_DWORD *)v4 + 20);
          if ( (v8 & 0x400) == 0 )
          {
            v9 = *((_DWORD *)v5 + 20);
            if ( (v9 & 0x400) == 0
              && (((v8 & 0x200) == 0 || (v8 & 0x4000000) != 0) && ((v9 & 0x200) == 0 || (v9 & 0x4000000) != 0)
               || qh_qh.MERGEindependent == 0
               || v6 > MRGanglecoplanar) )
            {
              qh_merge_nonconvex(facet1: v4, facet2: v5, mergetype: v6);
              numdegenredun += qh_merge_degenredundant();
              ++numnewmerges;
              wasmerge = 1;
              if ( v6 == MRGconcave )
                ++numconcave;
              else
                ++numcoplanar;
            }
          }
        }
        if ( qh_qh.POSTmerging != 0 && qh_qh.hull_dim <= 5 && numnewmerges > 2 )
        {
          numnewmerges = 0;
          qh_reducevertices();
        }
        qh_getmergeset(facetlist: qh_qh.newfacet_list);
      }
      if ( qh_qh.VERTEXneighbors == 0 )
        break;
      v10 = 0;
      if ( qh_qh.hull_dim >= 4 && qh_qh.POSTmerging != 0 )
      {
        vertex_list = qh_qh.vertex_list;
        if ( qh_qh.vertex_list != nullptr )
        {
          while ( 1 )
          {
            next = vertex_list->next;
            if ( vertex_list->next == nullptr )
              break;
            *((_DWORD *)vertex_list + 5) |= 0x4000000u;
            vertex_list = next;
          }
        }
        v10 = 1;
      }
      if ( (wasmerge != 0 || othermerge != 0)
        && (qh_qh.MERGEexact == 0 || qh_qh.POSTmerging != 0)
        && qh_qh.hull_dim <= 5 )
      {
        othermerge = 0;
        goto LABEL_39;
      }
      if ( v10 == 0 )
        break;
LABEL_39:
      if ( qh_reducevertices() == 0 )
        break;
      qh_getmergeset(facetlist: qh_qh.newfacet_list);
    }
  }
  while ( vneighbors != 0 && qh_test_vneighbors() );
  if ( qh_qh.CHECKfrequently != 0 && qh_qh.MERGEexact == 0 )
  {
    qh_qh.old_randomdist = qh_qh.RANDOMdist;
    qh_qh.RANDOMdist = 0;
    qh_checkconvex(facetlist: qh_qh.newfacet_list, fault: 0);
    qh_qh.RANDOMdist = qh_qh.old_randomdist;
  }
  if ( qh_qh.IStracing >= 1 )
    fprintf(
      str: qh_qh.ferr,
      format: "qh_all_merges: merged %d coplanar facets %d concave facets and %d degen or redundant facets.\n",
      numcoplanar,
      numconcave,
      numdegenredun);
  if ( qh_qh.IStracing >= 4 && qh_qh.num_facets < 50 )
    qh_printlists();
}

//------------------------------------------------------------------------------
// Address: 0x1006CAD0
// Name: void qh_flippedmerges(struct facetT __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_flippedmerges(facetT *facetlist, unsigned int *wasmerge)
{
  int v2; // edi
  facetT *i; // esi
  int v4; // eax
  setT *v5; // ecx
  setelemT v6; // eax
  setelemT *e; // ebx
  int v8; // esi
  facetT *v9; // eax
  facetT *v10; // edi
  setelemT v11; // eax
  setelemT *v12; // esi
  long double mindist; // [esp+18h] [ebp-20h] BYREF
  long double maxdist; // [esp+20h] [ebp-18h] BYREF
  long double dist; // [esp+28h] [ebp-10h] BYREF
  int nummerge; // [esp+30h] [ebp-8h]
  setT *othermerges; // [esp+34h] [ebp-4h] BYREF

  v2 = 0;
  nummerge = 0;
  if ( qh_qh.IStracing >= 4 )
    fprintf(str: qh_qh.ferr, format: "qh_flippedmerges: begin\n");
  for ( i = facetlist; i != nullptr; i = i->next )
  {
    if ( i->next == nullptr )
      break;
    v4 = *((_DWORD *)i + 20);
    if ( (v4 & 0x8000) != 0 && (v4 & 0x400) == 0 )
      qh_appendmergeset(facet: i, neighbor: i, mergetype: MRGflip, angle: nullptr);
  }
  othermerges = qh_settemppop();
  qh_qh.facet_mergeset = qh_settemp(setsize: qh_qh.TEMPsize);
  qh_settemppush(set: othermerges);
  v5 = othermerges;
  if ( othermerges != nullptr )
  {
    v6.p = (void *)othermerges->e[0];
    e = othermerges->e;
    if ( v6.i != 0 )
    {
      do
      {
        v8 = *(_DWORD *)(v6.i + 8);
        ++e;
        if ( *(_DWORD *)(v6.i + 16) == 4 && (*(_DWORD *)(v8 + 80) & 0x400) == 0 )
        {
          if ( qh_qh.TRACEmerge - 1 == qh_qhstat.stats[176].i )
          {
            qh_qh.IStracing = qh_qh.TRACElevel;
            qhmem.IStracing = qh_qh.TRACElevel;
          }
          v9 = qh_findbestneighbor(facet: (facetT *)v8, distp: &dist, mindistp: &mindist, maxdistp: &maxdist);
          v10 = v9;
          if ( qh_qh.IStracing != 0 )
            fprintf(
              str: qh_qh.ferr,
              format: "qh_flippedmerges: merge flipped f%d into f%d dist %2.2g during p%d\n",
              *(_DWORD *)(v8 + 76),
              v9->id,
              (double)dist,
              qh_qh.furthest_id);
          qh_mergefacet(facet1: (facetT *)v8, facet2: v10, &mindist, &maxdist, mergeapex: nullptr);
          ++nummerge;
          if ( qh_qh.PRINTstatistics != 0 )
          {
            ++qh_qhstat.stats[76].i;
            qh_qhstat.stats[78].r = qh_qhstat.stats[78].r + dist;
            if ( dist > qh_qhstat.stats[77].r )
              qh_qhstat.stats[77].r = dist;
          }
          qh_merge_degenredundant();
        }
        v6.p = e->p;
      }
      while ( e->i != 0 );
      v5 = othermerges;
      v2 = nummerge;
    }
    if ( v5 != nullptr )
    {
      v11.p = (void *)v5->e[0];
      v12 = v5->e;
      if ( v11.i != 0 )
      {
        do
        {
          ++v12;
          if ( (*(_DWORD *)(*(_DWORD *)(v11.i + 8) + 80) & 0x400) != 0
            || (*(_DWORD *)(*(_DWORD *)(v11.i + 12) + 80) & 0x400) != 0 )
          {
            qh_memfree(object: (void **)v11.p, size: 24);
          }
          else
          {
            qh_setappend(setp: &qh_qh.facet_mergeset, newelem: v11.p);
          }
          v11.p = v12->p;
        }
        while ( v12->i != 0 );
      }
    }
  }
  qh_settempfree(set: &othermerges);
  if ( v2 != 0 )
    *wasmerge = 1;
  if ( qh_qh.IStracing >= 1 )
    fprintf(str: qh_qh.ferr, format: "qh_flippedmerges: merged %d flipped facets into a good neighbor\n", v2);
}

//------------------------------------------------------------------------------
// Address: 0x1006CCF0
// Name: void qh_premerge(struct vertexT __near *,double,double)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_premerge(vertexT *apex, long double maxcentrum, long double maxangle)
{
  unsigned int id; // eax
  facetT *i; // esi
  unsigned int othermerge; // [esp+18h] [ebp-4h] BYREF

  othermerge = 0;
  if ( qh_qh.ZEROcentrum == 0 || qh_checkzero(testall: 0) == 0 )
  {
    if ( qh_qh.IStracing >= 2 )
    {
      if ( qh_qh.newfacet_list != nullptr )
        id = qh_qh.newfacet_list->id;
      else
        id = -1;
      fprintf(
        str: qh_qh.ferr,
        format: "qh_premerge: premerge centrum %2.2g angle %2.2g for apex v%d facetlist f%d\n",
        (double)maxcentrum,
        (double)maxangle,
        *((_DWORD *)apex + 5) & 0xFFFFFF,
        id);
    }
    if ( qh_qh.IStracing >= 4 && qh_qh.num_facets < 50 )
      qh_printlists();
    qh_qh.centrum_radius = maxcentrum;
    qh_qh.cos_max = maxangle;
    qh_qh.degen_mergeset = qh_settemp(setsize: qh_qh.TEMPsize);
    qh_qh.facet_mergeset = qh_settemp(setsize: qh_qh.TEMPsize);
    if ( qh_qh.hull_dim < 3 )
    {
      qh_mergecycle_all(facetlist: qh_qh.newfacet_list, wasmerge: &othermerge);
    }
    else
    {
      qh_mark_dupridges(facetlist: qh_qh.newfacet_list);
      qh_mergecycle_all(facetlist: qh_qh.newfacet_list, wasmerge: &othermerge);
      qh_forcedmerges(wasmerge: &othermerge);
      for ( i = qh_qh.newfacet_list; i != nullptr; i = i->next )
      {
        if ( i->next == nullptr )
          break;
        if ( (*((_DWORD *)i + 20) & 0x201000) == 0 )
          qh_degen_redundant_neighbors(facet: i, delfacet: nullptr);
      }
      if ( qh_merge_degenredundant() != 0 )
        othermerge = 1;
    }
    qh_flippedmerges(facetlist: qh_qh.newfacet_list, wasmerge: &othermerge);
    if ( qh_qh.MERGEexact == 0 || qh_qhstat.stats[176].i != 0 )
    {
      ++qh_qhstat.stats[150].i;
      qh_qh.POSTmerging = 0;
      qh_getmergeset_initial(facetlist: qh_qh.newfacet_list);
      qh_all_merges(othermerge, vneighbors: 0);
    }
    qh_settempfree(set: &qh_qh.facet_mergeset);
    qh_settempfree(set: &qh_qh.degen_mergeset);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006CEB0
// Name: void qh_postmerge(char const __near *,double,double,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_postmerge(const char *reason, long double maxcentrum, long double maxangle, unsigned int vneighbors)
{
  unsigned int v4; // ebx
  facetT *facet_list; // eax
  int v6; // ecx
  vertexT *vertex_list; // eax
  vertexT *next; // ecx
  vertexT *v9; // ecx

  if ( qh_qh.REPORTfreq != 0 || qh_qh.IStracing != 0 )
  {
    qh_buildtracing(furthest: nullptr, facet: nullptr);
    qh_printsummary(fp: qh_qh.ferr);
    if ( qh_qh.PRINTstatistics != 0 )
      qh_printallstatistics(fp: qh_qh.ferr, string: "reason");
    ivp_message(templat: "\n%s with 'C%.2g' and 'A%.2g'\n", reason, (double)maxcentrum, (double)maxangle);
  }
  v4 = vneighbors;
  if ( qh_qh.IStracing >= 2 )
    fprintf(str: qh_qh.ferr, format: "qh_postmerge: postmerge.  test vneighbors? %d\n", vneighbors);
  qh_qh.centrum_radius = maxcentrum;
  qh_qh.cos_max = maxangle;
  qh_qh.POSTmerging = 1;
  qh_qh.degen_mergeset = qh_settemp(setsize: qh_qh.TEMPsize);
  qh_qh.facet_mergeset = qh_settemp(setsize: qh_qh.TEMPsize);
  facet_list = qh_qh.facet_list;
  if ( qh_qh.visible_list != qh_qh.facet_list )
  {
    qh_qh.NEWfacets = 1;
    qh_qh.newfacet_list = qh_qh.facet_list;
    qh_qh.visible_list = qh_qh.facet_list;
    if ( qh_qh.facet_list != nullptr )
    {
      do
      {
        if ( facet_list->next == nullptr )
          break;
        *((_DWORD *)facet_list + 20) |= 0x200u;
        v6 = *((_DWORD *)facet_list + 20);
        if ( (v6 & 0x1000) == 0 )
          *((_DWORD *)facet_list + 20) = v6 | 0x10000000;
        ++qh_qhstat.stats[149].i;
        facet_list = facet_list->next;
      }
      while ( facet_list != nullptr );
    }
    vertex_list = qh_qh.vertex_list;
    qh_qh.newvertex_list = qh_qh.vertex_list;
    if ( qh_qh.vertex_list != nullptr )
    {
      while ( 1 )
      {
        next = vertex_list->next;
        if ( vertex_list->next == nullptr )
          break;
        *((_DWORD *)vertex_list + 5) |= 0x10000000u;
        vertex_list = next;
      }
      vertex_list = qh_qh.vertex_list;
    }
    if ( qh_qh.VERTEXneighbors != 0 )
    {
      if ( vertex_list != nullptr )
      {
        while ( 1 )
        {
          v9 = vertex_list->next;
          if ( vertex_list->next == nullptr )
            break;
          *((_DWORD *)vertex_list + 5) |= 0x4000000u;
          vertex_list = v9;
        }
      }
      if ( qh_qh.MERGEexact != 0 && qh_qh.hull_dim <= 5 )
        qh_reducevertices();
    }
    if ( qh_qh.PREmerge == 0 && qh_qh.MERGEexact == 0 )
      qh_flippedmerges(facetlist: qh_qh.newfacet_list, wasmerge: (unsigned int *)&maxcentrum + 1);
  }
  qh_getmergeset_initial(facetlist: qh_qh.newfacet_list);
  qh_all_merges(othermerge: 0, vneighbors: v4);
  qh_settempfree(set: &qh_qh.facet_mergeset);
  qh_settempfree(set: &qh_qh.degen_mergeset);
}
