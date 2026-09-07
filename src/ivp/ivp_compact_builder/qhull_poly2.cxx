// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_compact_builder/qhull_poly2.cxx
// Functions: 40
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1004EDA0
// Name: void qh_addhash(void __near *,struct setT __near *,int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_addhash(void *newelem, setT *hashtable, int hashsize, unsigned int hash)
{
  int v4; // eax
  void *p; // ecx

  v4 = hash;
  p = hashtable->e[hash].p;
  if ( p != nullptr )
  {
    while ( p != newelem )
    {
      v4 = v4 + 1 >= hashsize ? 0 : v4 + 1;
      p = hashtable->e[v4].p;
      if ( p == nullptr )
      {
        hashtable->e[v4].i = (int)newelem;
        return;
      }
    }
  }
  else
  {
    hashtable->e[hash].i = (int)newelem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004EDF0
// Name: void qh_checkconvex(struct facetT __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_checkconvex(facetT *facetlist, int fault)
{
  facetT *v2; // esi
  int v3; // eax
  setT *v4; // eax
  facetT *v5; // edi
  facetT **v6; // eax
  int i; // ecx
  int v8; // ebx
  bool v9; // zf
  int v10; // eax
  setT *neighbors; // eax
  facetT *p; // edi
  facetT **e; // eax
  int v14; // [esp-4h] [ebp-3Ch]
  int v15; // [esp-4h] [ebp-3Ch]
  int v16; // [esp-4h] [ebp-3Ch]
  int v17; // [esp+0h] [ebp-38h]
  int v18; // [esp+0h] [ebp-38h]
  double v19; // [esp+0h] [ebp-38h]
  double v20; // [esp+4h] [ebp-34h]
  double v21; // [esp+4h] [ebp-34h]
  int furthest_id; // [esp+8h] [ebp-30h]
  double dist; // [esp+18h] [ebp-20h] BYREF
  int v24; // [esp+20h] [ebp-18h]
  unsigned int tempcentrum; // [esp+24h] [ebp-14h]
  unsigned int allsimplicial; // [esp+28h] [ebp-10h]
  facetT *errfacet2; // [esp+2Ch] [ebp-Ch]
  facetT *errfacet1; // [esp+30h] [ebp-8h]
  unsigned int waserror; // [esp+34h] [ebp-4h]
  facetT **neighborp; // [esp+40h] [ebp+8h]
  facetT **neighborpa; // [esp+40h] [ebp+8h]

  errfacet1 = nullptr;
  errfacet2 = nullptr;
  waserror = 0;
  tempcentrum = 0;
  if ( qh_qh.IStracing >= 1 )
    fprintf(str: qh_qh.ferr, format: "qh_checkconvex: check all ridges are convex\n");
  if ( qh_qh.RERUN == 0 )
  {
    qh_qhstat.stats[23].i = 0;
    qh_qhstat.stats[33].i = 0;
  }
  v2 = facetlist;
  if ( facetlist != nullptr )
  {
    while ( 1 )
    {
      if ( v2->next == nullptr )
        goto LABEL_56;
      v3 = *((_DWORD *)v2 + 20);
      if ( (v3 & 0x8000) != 0 )
      {
        qh_precision(reason: "flipped facet");
        ivp_message(templat: "qhull precision error: f%d is flipped (interior point is outside)\n", v2->id);
        errfacet1 = v2;
        waserror = 1;
        goto LABEL_55;
      }
      if ( qh_qh.MERGING != 0 && (qh_qh.ZEROcentrum == 0 || (v3 & 0x1000) == 0) )
      {
LABEL_35:
        if ( qh_qh.CENTERtype == qh_AScentrum )
        {
          if ( v2->center == nullptr )
            v2->center = qh_getcentrum(facet: v2);
          allsimplicial = (unsigned int)v2->center;
        }
        else
        {
          allsimplicial = (unsigned int)qh_getcentrum(facet: v2);
          tempcentrum = 1;
        }
        neighbors = v2->neighbors;
        if ( neighbors == nullptr || (p = (facetT *)neighbors->e[0].p, e = (facetT **)neighbors->e, p == nullptr) )
        {
LABEL_53:
          if ( tempcentrum != 0 )
            qh_memfree(object: (void *)allsimplicial, size: qh_qh.normal_size);
          goto LABEL_55;
        }
        while ( 2 )
        {
          neighborpa = e + 1;
          if ( qh_qh.ZEROcentrum == 0 || (*((_DWORD *)v2 + 20) & 0x1000) == 0 || (*((_DWORD *)p + 20) & 0x1000) == 0 )
          {
            ++qh_qhstat.stats[49].i;
            qh_distplane(point: (long double *)allsimplicial, facet: p, &dist);
            if ( dist > qh_qh.DISTround )
            {
              ++qh_qhstat.stats[23].i;
              qh_precision(reason: "concave ridge");
              if ( qh_qh.ferr != nullptr )
                ivp_message(
                  templat: "qhull precision error: f%d is concave to f%d.  Centrum of f%d is %6.4g above f%d\n",
                  v2->id,
                  p->id,
                  v2->id,
                  dist,
                  p->id);
              goto LABEL_51;
            }
            if ( dist >= 0.0 )
            {
              ++qh_qhstat.stats[33].i;
              qh_precision(reason: "coplanar ridge");
              if ( qh_qh.ferr != nullptr )
                ivp_message(
                  templat: "qhull precision error: f%d is coplanar or concave to f%d.  Centrum of f%d is %6.4g above f%d\n",
                  v2->id,
                  p->id,
                  v2->id,
                  dist,
                  p->id);
LABEL_51:
              waserror = 1;
              errfacet2 = p;
              errfacet1 = v2;
            }
          }
          e = neighborpa;
          p = *neighborpa;
          if ( *neighborpa == nullptr )
            goto LABEL_53;
          continue;
        }
      }
      v4 = v2->neighbors;
      allsimplicial = 1;
      if ( v4 == nullptr )
        goto LABEL_55;
      v5 = (facetT *)v4->e[0].p;
      v6 = (facetT **)v4->e;
      if ( v5 == nullptr )
        goto LABEL_55;
      for ( i = 0; ; i = v24 )
      {
        v8 = *(int *)((char *)&v2->vertices->e[0].i + i);
        v9 = (*((_DWORD *)v5 + 20) & 0x1000) == 0;
        neighborp = v6 + 1;
        v24 = i + 4;
        if ( v9 )
        {
          allsimplicial = 0;
          goto LABEL_33;
        }
        qh_distplane(point: *(long double **)(v8 + 8), facet: v5, &dist);
        if ( dist > -qh_qh.DISTround )
        {
          if ( fault == 1 )
          {
            qh_precision(reason: "coplanar or concave ridge");
            if ( qh_qh.ferr != nullptr )
              ivp_message(templat: "qhull precision error: initial simplex is not convex. Distance=%.2g\n", dist);
            qh_errexit(exitcode: 2, facet: nullptr, ridge: nullptr);
          }
          if ( dist > qh_qh.DISTround )
          {
            ++qh_qhstat.stats[23].i;
            qh_precision(reason: "concave ridge");
            if ( qh_qh.ferr != nullptr )
            {
              v20 = dist;
              v17 = *(_DWORD *)(v8 + 20) & 0xFFFFFF;
              v14 = qh_pointid(point: *(long double **)(v8 + 8));
              ivp_message(
                templat: "qhull precision error: f%d is concave to f%d, since p%d (v%d) is %6.4g above\n",
                v2->id,
                v5->id,
                v14,
                v17,
                v20);
            }
LABEL_26:
            errfacet1 = v2;
            errfacet2 = v5;
            waserror = 1;
            goto LABEL_33;
          }
          if ( qh_qh.ZEROcentrum != 0 )
          {
            if ( dist > 0.0 )
            {
              ++qh_qhstat.stats[33].i;
              qh_precision(reason: "coplanar ridge");
              if ( qh_qh.ferr != nullptr )
              {
                v21 = dist;
                v18 = *(_DWORD *)(v8 + 20) & 0xFFFFFF;
                v15 = qh_pointid(point: *(long double **)(v8 + 8));
                ivp_message(
                  templat: "qhull precision error: f%d is clearly not convex to f%d, since p%d (v%d) is %6.4g above\n",
                  v2->id,
                  v5->id,
                  v15,
                  v18,
                  v21);
              }
              goto LABEL_26;
            }
          }
          else
          {
            ++qh_qhstat.stats[33].i;
            qh_precision(reason: "coplanar ridge");
            if ( qh_qh.IStracing != 0 )
            {
              furthest_id = qh_qh.furthest_id;
              v19 = dist;
              v16 = *(_DWORD *)(v8 + 20) & 0xFFFFFF;
              v10 = qh_pointid(point: *(long double **)(v8 + 8));
              fprintf(
                str: qh_qh.ferr,
                format: "qhull precision error: f%d may be coplanar to f%d, since p%d (v%d) is within %6.4g during p%d\n",
                v2->id,
                v5->id,
                v10,
                v16,
                v19,
                furthest_id);
            }
          }
        }
LABEL_33:
        v6 = neighborp;
        v5 = *neighborp;
        if ( *neighborp == nullptr )
          break;
      }
      if ( allsimplicial == 0 )
        goto LABEL_35;
LABEL_55:
      v2 = v2->next;
      if ( v2 == nullptr )
      {
LABEL_56:
        if ( waserror != 0 && qh_qh.FORCEoutput == 0 )
          qh_errexit2(exitcode: 3, facet: errfacet1, otherfacet: errfacet2);
        return;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004F240
// Name: void qh_checkflipped_all(struct facetT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_checkflipped_all(facetT *facetlist)
{
  facetT *v1; // esi
  int v2; // edi
  long double dist; // [esp+10h] [ebp-8h] BYREF

  v1 = facetlist;
  v2 = 0;
  if ( facetlist == qh_qh.facet_list )
    qh_qhstat.stats[79].i = 0;
  if ( facetlist != nullptr )
  {
    do
    {
      if ( v1->next == nullptr )
        break;
      if ( v1->normal != nullptr && qh_checkflipped(facet: v1, distp: &dist, allerror: 0) == 0 )
      {
        ivp_message(templat: "qhull precision error: facet f%d is flipped, distance= %6.12g\n", v1->id, (double)dist);
        if ( qh_qh.FORCEoutput == 0 )
        {
          qh_errprint(string: "ERRONEOUS", atfacet: v1, otherfacet: nullptr, atridge: nullptr, atvertex: nullptr);
          v2 = 1;
        }
      }
      v1 = v1->next;
    }
    while ( v1 != nullptr );
    if ( v2 != 0 )
    {
      ivp_message(
        templat: "\n"
        "A flipped facet occurs when its distance to the interior point is\n"
        "greater than %2.2g, the maximum roundoff error.\n",
        -(double)qh_qh.DISTround);
      qh_errexit(exitcode: 3, facet: nullptr, ridge: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004F310
// Name: void qh_checkvertex(struct vertexT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_checkvertex(vertexT *vertex)
{
  setT *neighbors; // eax
  facetT *p; // esi
  setelemT *e; // ebx
  facetT *errfacet; // [esp+Ch] [ebp-8h]
  unsigned int waserror; // [esp+10h] [ebp-4h]

  waserror = 0;
  errfacet = nullptr;
  if ( qh_pointid(point: vertex->point) == -1 )
  {
    ivp_message(templat: "qhull internal error (qh_checkvertex): unknown point id %p\n", vertex->point);
    waserror = 1;
  }
  if ( (*((_DWORD *)vertex + 5) & 0xFFFFFFu) >= qh_qh.vertex_id )
  {
    ivp_message(
      templat: "qhull internal error (qh_checkvertex): unknown vertex id %d\n",
      *((_DWORD *)vertex + 5) & 0xFFFFFF);
    goto LABEL_14;
  }
  if ( waserror != 0 )
    goto LABEL_14;
  if ( (*((_DWORD *)vertex + 5) & 0x8000000) == 0 && qh_setsize(set: vertex->neighbors) != 0 )
  {
    neighbors = vertex->neighbors;
    if ( neighbors != nullptr )
    {
      p = (facetT *)neighbors->e[0].p;
      e = neighbors->e;
      if ( p != nullptr )
      {
        do
        {
          ++e;
          if ( qh_setin(set: p->vertices, setelem: vertex) == 0 )
          {
            ivp_message(
              templat: "qhull internal error (qh_checkvertex): neighbor f%d does not contain v%d\n",
              p->id,
              *((_DWORD *)vertex + 5) & 0xFFFFFF);
            errfacet = p;
            waserror = 1;
          }
          p = (facetT *)e->i;
        }
        while ( e->i != 0 );
        if ( waserror != 0 )
        {
LABEL_14:
          qh_errprint(string: "ERRONEOUS", atfacet: nullptr, otherfacet: nullptr, atridge: nullptr, atvertex: vertex);
          qh_errexit(exitcode: 5, facet: errfacet, ridge: nullptr);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004F410
// Name: void qh_clearcenters(enum qh_CENTER)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_clearcenters(qh_CENTER type)
{
  facetT *i; // esi
  long double *center; // eax

  if ( qh_qh.CENTERtype != type )
  {
    for ( i = qh_qh.facet_list; i != nullptr; i = i->next )
    {
      if ( i->next == nullptr )
        break;
      center = i->center;
      if ( qh_qh.CENTERtype == qh_ASvoronoi )
      {
        if ( center != nullptr )
        {
          qh_memfree(object: center, size: qh_qh.center_size);
LABEL_9:
          i->center = nullptr;
        }
      }
      else if ( center != nullptr )
      {
        qh_memfree(object: center, size: qh_qh.normal_size);
        goto LABEL_9;
      }
    }
    qh_qh.CENTERtype = type;
  }
  if ( qh_qh.IStracing >= 2 )
    fprintf(str: qh_qh.ferr, format: "qh_clearcenters: switched to center type %d\n", type);
}

//------------------------------------------------------------------------------
// Address: 0x1004F4A0
// Name: void qh_delridge(struct ridgeT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_delridge(setT *ridge)
{
  setT **v1; // eax

  qh_setdel(set: *(setT **)(ridge->e[0].i + 56), oldelem: ridge);
  qh_setdel(set: *(setT **)(ridge[1].maxsize + 56), oldelem: ridge);
  qh_setfree(setp: (setT **)ridge);
  ++qhmem.freeshort;
  v1 = (setT **)&qhmem.freelists[qhmem.indextable[16]];
  ridge->maxsize = (int)*v1;
  *v1 = ridge;
}

//------------------------------------------------------------------------------
// Address: 0x1004F4F0
// Name: void qh_delvertex(struct vertexT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_delvertex(vertexT *vertex)
{
  if ( vertex == qh_qh.tracevertex )
    qh_qh.tracevertex = nullptr;
  qh_removevertex(vertex);
  qh_setfree(setp: &vertex->neighbors);
  qh_memfree(object: vertex, size: 24);
}

//------------------------------------------------------------------------------
// Address: 0x1004F530
// Name: void qh_furthestout(struct facetT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_furthestout(facetT *facet)
{
  setT *outsideset; // edi
  long double *p; // esi
  long double **e; // edi
  int v4; // eax
  unsigned int id; // [esp-10h] [ebp-24h]
  long double dist; // [esp+0h] [ebp-14h] BYREF
  long double bestdist; // [esp+8h] [ebp-Ch]
  long double *bestpoint; // [esp+10h] [ebp-4h]

  outsideset = facet->outsideset;
  p = nullptr;
  bestpoint = nullptr;
  bestdist = -1.797693134862316e308;
  if ( outsideset != nullptr )
  {
    p = (long double *)outsideset->e[0].p;
    e = (long double **)outsideset->e;
    if ( p != nullptr )
    {
      do
      {
        ++e;
        qh_distplane(point: p, facet, &dist);
        ++qh_qhstat.stats[19].i;
        if ( dist > bestdist )
        {
          bestpoint = p;
          bestdist = dist;
        }
        p = *e;
      }
      while ( *e != nullptr );
      if ( bestpoint != nullptr )
      {
        qh_setdel(set: facet->outsideset, oldelem: nullptr);
        qh_setappend(setp: &facet->outsideset, newelem: nullptr);
        facet->furthestdist = bestdist;
      }
    }
  }
  *((_DWORD *)facet + 20) &= ~0x20000u;
  if ( qh_qh.IStracing >= 3 )
  {
    id = facet->id;
    v4 = qh_pointid(point: p);
    fprintf(str: qh_qh.ferr, format: "qh_furthestout: p%d is furthest outside point of f%d\n", v4, id);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004F600
// Name: void qh_infiniteloop(struct facetT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn qh_infiniteloop(facetT *facet)
{
  ivp_message(templat: "qhull internal error (qh_infiniteloop): potential infinite loop detected\n");
  qh_errexit(exitcode: 5, facet, ridge: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1004F620
// Name: struct vertexT __near * qh_isvertex(double __near *,struct setT __near *)
// Source: json
//------------------------------------------------------------------------------
vertexT *__cdecl qh_isvertex(long double *point, setT *vertices)
{
  setelemT *e; // ecx
  vertexT *result; // eax

  if ( vertices == nullptr )
    return nullptr;
  e = vertices->e;
  result = (vertexT *)vertices->e[0].p;
  if ( result == nullptr )
    return nullptr;
  while ( 1 )
  {
    ++e;
    if ( result->point == point )
      break;
    result = (vertexT *)e->i;
    if ( e->i == 0 )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004F650
// Name: void qh_matchduplicates(struct facetT __near *,int,int,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_matchduplicates(facetT *atfacet, int atskip, int hashsize, int *hashcount)
{
  int v4; // ebx
  facetT *v5; // edi
  int v6; // esi
  setelemT v7; // esi
  facetT *v8; // eax
  facetT **v9; // ecx
  double v10; // xmm0_8
  facetT *v11; // esi
  facetT *v12; // edi
  int v13; // ecx
  int v14; // edx
  setT *vertices; // [esp+0h] [ebp-70h]
  void *p; // [esp+Ch] [ebp-64h]
  double dist2; // [esp+1Ch] [ebp-54h]
  long double low; // [esp+24h] [ebp-4Ch] BYREF
  long double high; // [esp+2Ch] [ebp-44h] BYREF
  double maxdist; // [esp+34h] [ebp-3Ch]
  long double mindist; // [esp+3Ch] [ebp-34h]
  unsigned int same; // [esp+44h] [ebp-2Ch] BYREF
  int maxskip2; // [esp+48h] [ebp-28h]
  int maxskip; // [esp+4Ch] [ebp-24h]
  int nextskip; // [esp+50h] [ebp-20h]
  facetT *nextfacet; // [esp+54h] [ebp-1Ch]
  int scan; // [esp+58h] [ebp-18h]
  facetT *maxmatch2; // [esp+5Ch] [ebp-14h]
  facetT *maxmatch; // [esp+60h] [ebp-10h]
  int skip; // [esp+64h] [ebp-Ch] BYREF
  int hash; // [esp+68h] [ebp-8h]
  int makematch; // [esp+6Ch] [ebp-4h]

  v4 = atskip;
  v5 = atfacet;
  maxmatch = nullptr;
  maxmatch2 = nullptr;
  nextskip = 0;
  maxskip = 0;
  maxskip2 = 0;
  p = atfacet->vertices->e[atskip].p;
  vertices = atfacet->vertices;
  maxdist = -1.797693134862316e308;
  v6 = qh_gethash(hashsize, set: vertices, size: qh_qh.hull_dim, firstindex: 1, skipelem: p);
  hash = v6;
  if ( qh_qh.IStracing >= 2 )
    fprintf(
      str: qh_qh.ferr,
      format: "qh_matchduplicates: find duplicate matches for f%d skip %d hash %d hashcount %d\n",
      atfacet->id,
      atskip,
      v6,
      *hashcount);
  ++qh_qh.visit_id;
  makematch = 0;
  while ( 1 )
  {
    while ( 1 )
    {
      ++qh_qhstat.stats[82].i;
      v5->visitid = qh_qh.visit_id;
      scan = v6;
      v7.p = (void *)qh_qh.hash_table->e[v6];
      v8 = nullptr;
      nextfacet = nullptr;
      if ( v7.i != 0 )
      {
        do
        {
          if ( (*(_DWORD *)(v7.i + 80) & 0x100000) != 0 && *(_DWORD *)(v7.i + 72) != qh_qh.visit_id )
          {
            ++qh_qhstat.stats[85].i;
            if ( qh_matchvertices(
                   firstindex: (vertexT **)1,
                   verticesA: v5->vertices,
                   skipA: v4,
                   verticesB: *(setT **)(v7.i + 52),
                   skipB: &skip,
                   &same) != 0 )
            {
              v9 = (facetT **)(*(_DWORD *)(v7.i + 60) + 4 * skip + 4);
              if ( *v9 == (facetT *)1 )
              {
                if ( same == (((*(_DWORD *)(v7.i + 80) ^ *((_DWORD *)v5 + 20)) & 0x800) != 0) )
                {
                  if ( makematch != 0 )
                  {
                    if ( v5->neighbors->e[v4].i == 1 )
                    {
                      *v9 = v5;
                      v5->neighbors->e[v4].i = 2;
                      *hashcount -= 2;
                      if ( qh_qh.IStracing >= 4 )
                        fprintf(
                          str: qh_qh.ferr,
                          format: "qh_matchduplicates: duplicate f%d skip %d matched with new f%d skip %d merge\n",
                          *(_DWORD *)(v7.i + 76),
                          skip,
                          v5->id,
                          v4);
                    }
                  }
                  else
                  {
                    mindist = qh_getdistance(facet: (facetT *)v7.p, neighbor: v5, mindist: &low, maxdist: &high);
                    dist2 = qh_getdistance(facet: v5, neighbor: (facetT *)v7.p, mindist: &low, maxdist: &high);
                    if ( mindist <= dist2 )
                      v10 = mindist;
                    else
                      v10 = dist2;
                    if ( v10 > maxdist )
                    {
                      maxdist = v10;
                      maxmatch = (facetT *)v7.i;
                      maxskip = skip;
                      maxmatch2 = v5;
                      maxskip2 = v4;
                    }
                    if ( qh_qh.IStracing >= 3 )
                      fprintf(
                        str: qh_qh.ferr,
                        format: "qh_matchduplicates: duplicate f%d skip %d new f%d skip %d at dist %2.2g, max is now f%d f%d\n",
                        *(_DWORD *)(v7.i + 76),
                        skip,
                        v5->id,
                        v4,
                        v10,
                        maxmatch->id,
                        maxmatch2->id);
                  }
                }
                else
                {
                  nextfacet = (facetT *)v7.i;
                  nextskip = skip;
                }
              }
              else if ( makematch == 0 )
              {
                ivp_message(
                  templat: "qhull internal error (qh_matchduplicates): missing dupridge at f%d skip %d for new f%d skip %d hash %d\n",
                  *(_DWORD *)(v7.i + 76),
                  skip,
                  v5->id,
                  v4,
                  hash);
                qh_errexit2(exitcode: 5, facet: (facetT *)v7.p, otherfacet: v5);
              }
            }
          }
          v7.p = (void *)qh_qh.hash_table->e[scan + 1 >= hashsize ? 0 : scan + 1];
          scan = scan + 1 >= hashsize ? 0 : scan + 1;
        }
        while ( v7.i != 0 );
        v8 = nextfacet;
      }
      v4 = nextskip;
      v5 = v8;
      if ( v8 == nullptr )
        break;
      v6 = hash;
    }
    if ( makematch == 0 )
    {
      v11 = maxmatch;
      if ( maxmatch == nullptr )
      {
        ivp_message(
          templat: "qhull internal error (qh_matchduplicates): no maximum match at duplicate f%d skip %d at hash %d\n",
          atfacet->id,
          atskip,
          hash);
        qh_errexit(exitcode: 5, facet: atfacet, ridge: nullptr);
      }
      v12 = maxmatch2;
      v13 = maxskip;
      v14 = maxskip2;
      maxmatch->neighbors->e[maxskip].i = (int)maxmatch2;
      v12->neighbors->e[v14].i = (int)v11;
      *hashcount -= 2;
      ++qh_qhstat.stats[118].i;
      if ( qh_qh.IStracing != 0 )
        fprintf(
          str: qh_qh.ferr,
          format: "qh_matchduplicates: duplicate f%d skip %d matched with new f%d skip %d keep\n",
          v11->id,
          v13,
          v12->id,
          v14);
      qh_precision(reason: "ridge with multiple neighbors");
      if ( qh_qh.IStracing >= 4 )
        qh_errprint(string: "DUPLICATED/MATCH", atfacet: v11, otherfacet: v12, atridge: nullptr, atvertex: nullptr);
    }
    if ( ++makematch >= 2 )
      break;
    v5 = atfacet;
    v4 = atskip;
    v6 = hash;
    ++qh_qh.visit_id;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004F9B0
// Name: void qh_nearcoplanar(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_nearcoplanar()
{
  facetT *i; // esi
  facetT *facet_list; // edi
  int j; // ebx
  setT *coplanarset; // eax
  long double **e; // esi
  long double *p; // eax
  bool v6; // zf
  long double dist; // [esp+4h] [ebp-10h] BYREF
  long double innerplane; // [esp+Ch] [ebp-8h] BYREF

  if ( qh_qh.KEEPcoplanar != 0 )
  {
    if ( qh_qh.KEEPinside != 0 )
      return;
  }
  else if ( qh_qh.KEEPinside == 0 )
  {
    for ( i = qh_qh.facet_list; i != nullptr; i = i->next )
    {
      if ( i->next == nullptr )
        break;
      if ( i->coplanarset != nullptr )
        qh_setfree(setp: &i->coplanarset);
    }
    return;
  }
  qh_outerinner(facet: nullptr, outerplane: nullptr, &innerplane);
  if ( qh_qh.JOGGLEmax < 8.988465674311579e307 )
    innerplane = innerplane - sqrt((double)qh_qh.hull_dim) * qh_qh.JOGGLEmax;
  facet_list = qh_qh.facet_list;
  for ( j = 0; facet_list != nullptr; facet_list = facet_list->next )
  {
    if ( facet_list->next == nullptr )
      break;
    coplanarset = facet_list->coplanarset;
    if ( coplanarset != nullptr )
    {
      e = (long double **)coplanarset->e;
      p = (long double *)coplanarset->e[0].p;
      if ( p != nullptr )
      {
        do
        {
          ++e;
          ++j;
          qh_distplane(point: p, facet: facet_list, &dist);
          if ( innerplane <= dist )
            v6 = qh_qh.KEEPcoplanar == 0;
          else
            v6 = qh_qh.KEEPinside == 0;
          if ( v6 )
            *(e - 1) = nullptr;
          p = *e;
        }
        while ( *e != nullptr );
      }
      qh_setcompact(set: facet_list->coplanarset);
    }
  }
  qh_qhstat.stats[18].i += j;
}

//------------------------------------------------------------------------------
// Address: 0x1004FAF0
// Name: struct vertexT __near * qh_nearvertex(struct facetT __near *,double __near *,double __near *)
// Source: json
//------------------------------------------------------------------------------
vertexT *__cdecl qh_nearvertex(facetT *facet, long double *point, long double *bestdistp)
{
  int hull_dim; // ebx
  setT *vertices; // edi
  setelemT *e; // edi
  vertexT *i; // esi
  int v7; // ebx
  double dist; // [esp+0h] [ebp-14h]
  double bestdist; // [esp+8h] [ebp-Ch]
  vertexT *bestvertex; // [esp+10h] [ebp-4h]

  hull_dim = qh_qh.hull_dim;
  bestdist = 1.797693134862316e308;
  bestvertex = nullptr;
  if ( qh_qh.DELAUNAY != 0 )
    hull_dim = qh_qh.hull_dim - 1;
  vertices = facet->vertices;
  if ( vertices != nullptr )
  {
    e = vertices->e;
    i = (vertexT *)e->i;
    if ( e->i != 0 )
    {
      v7 = -hull_dim;
      do
      {
        ++e;
        dist = qh_pointdist(point1: i->point, point2: point, dim: v7);
        if ( bestdist > dist )
        {
          bestdist = dist;
          bestvertex = i;
        }
        i = (vertexT *)e->i;
      }
      while ( e->i != 0 );
    }
  }
  *bestdistp = sqrt(bestdist);
  return bestvertex;
}

//------------------------------------------------------------------------------
// Address: 0x1004FB80
// Name: int qh_newhashtable(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl qh_newhashtable(int newsize)
{
  int i; // esi

  for ( i = (2 * newsize + 2) | 1; i % 3 == 0 || i % 5 == 0; i += 2 )
    ;
  qh_qh.hash_table = qh_setnew(setsize: i);
  qh_setzero(set: qh_qh.hash_table, index: 0, size: i);
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x1004FBF0
// Name: struct vertexT __near * qh_newvertex(double __near *)
// Source: json
//------------------------------------------------------------------------------
vertexT *__cdecl qh_newvertex(long double *point)
{
  vertexT *v1; // esi
  int v2; // eax
  int v4; // [esp-4h] [ebp-8h]

  ++qh_qhstat.stats[180].i;
  v1 = (vertexT *)qh_memalloc(insize: 24);
  *(_QWORD *)&v1->next = 0;
  *(_QWORD *)&v1->point = 0;
  *(_QWORD *)&v1->visitid = 0;
  if ( qh_qh.vertex_id == 0xFFFFFF )
  {
    ivp_message(
      templat: "qhull input error: more than %d vertices.  Id field overflows and two vertices\n"
      "may have the same identifier.  Vertices not sorted correctly.\n",
      0xFFFFFF);
    qh_errexit(exitcode: 1, facet: nullptr, ridge: nullptr);
  }
  if ( qh_qh.vertex_id == qh_qh.tracevertex_id )
    qh_qh.tracevertex = v1;
  *((_DWORD *)v1 + 5) ^= (qh_qh.vertex_id++ ^ *((_DWORD *)v1 + 5)) & 0xFFFFFF;
  v1->point = point;
  if ( qh_qh.IStracing >= 4 )
  {
    v4 = *((_DWORD *)v1 + 5) & 0xFFFFFF;
    v2 = qh_pointid(point);
    fprintf(str: qh_qh.ferr, format: "qh_newvertex: vertex p%d (v%d) created\n", v2, v4);
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x1004FCA0
// Name: struct ridgeT __near * qh_nextridge3d(struct ridgeT __near *,struct facetT __near *,struct vertexT __near * __near *)
// Source: json
//------------------------------------------------------------------------------
ridgeT *__cdecl qh_nextridge3d(ridgeT *atridge, facetT *facet, vertexT **vertexp)
{
  setT *ridges; // eax
  ridgeT **e; // esi
  ridgeT *result; // eax
  vertexT *maxsize; // ecx
  int i; // edx
  vertexT *atvertex; // [esp+18h] [ebp+Ch]

  if ( atridge->top == facet )
    atvertex = (vertexT *)atridge->vertices[1].maxsize;
  else
    atvertex = (vertexT *)atridge->vertices->e[0].p;
  ridges = facet->ridges;
  if ( ridges == nullptr )
    return nullptr;
  e = (ridgeT **)ridges->e;
  result = (ridgeT *)ridges->e[0].p;
  if ( result == nullptr )
    return nullptr;
  while ( 1 )
  {
    ++e;
    if ( result != atridge )
    {
      if ( result->top == facet )
      {
        maxsize = (vertexT *)result->vertices[1].maxsize;
        i = result->vertices->e[0].i;
      }
      else
      {
        i = result->vertices[1].maxsize;
        maxsize = (vertexT *)result->vertices->e[0].p;
      }
      if ( (vertexT *)i == atvertex )
        break;
    }
    result = *e;
    if ( *e == nullptr )
      return nullptr;
  }
  if ( vertexp != nullptr )
    *vertexp = maxsize;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004FD20
// Name: void qh_outcoplanar(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_outcoplanar()
{
  facetT *i; // edi
  setT *outsideset; // ebx
  long double *p; // esi
  long double **e; // ebx
  long double dist; // [esp+0h] [ebp-8h] BYREF

  if ( qh_qh.IStracing >= 1 )
    fprintf(str: qh_qh.ferr, format: "qh_outcoplanar: move outsideset to coplanarset for qh NARROWhull\n");
  for ( i = qh_qh.facet_list; i != nullptr; i = i->next )
  {
    if ( i->next == nullptr )
      break;
    outsideset = i->outsideset;
    if ( outsideset != nullptr )
    {
      p = (long double *)outsideset->e[0].p;
      e = (long double **)outsideset->e;
      if ( p != nullptr )
      {
        do
        {
          --qh_qh.num_outside;
          ++e;
          if ( qh_qh.KEEPcoplanar != 0 || qh_qh.KEEPnearinside != 0 )
          {
            qh_distplane(point: p, facet: i, &dist);
            ++qh_qhstat.stats[143].i;
            qh_partitioncoplanar(point: p, facet: i, &dist);
          }
          p = *e;
        }
        while ( *e != nullptr );
      }
    }
    qh_setfree(setp: &i->outsideset);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004FDD0
// Name: double __near * qh_point(int)
// Source: json
//------------------------------------------------------------------------------
long double *__cdecl qh_point(int id)
{
  int v2; // esi

  if ( id < 0 )
    return nullptr;
  if ( id < qh_qh.num_points )
    return &qh_qh.first_point[id * qh_qh.hull_dim];
  v2 = id - qh_qh.num_points;
  if ( v2 >= qh_setsize(set: qh_qh.other_points) )
    return nullptr;
  else
    return (long double *)qh_qh.other_points->e[v2].p;
}

//------------------------------------------------------------------------------
// Address: 0x1004FE20
// Name: void qh_point_add(struct setT __near *,double __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_point_add(setT *set, long double *point, void *elem)
{
  setelemT v3; // esi
  int maxsize; // esi
  int v5; // eax

  v3.p = (void *)set->e[set->maxsize];
  if ( v3.i != 0 )
    maxsize = v3.i - 1;
  else
    maxsize = set->maxsize;
  v5 = qh_pointid(point);
  if ( v5 >= 0 )
  {
    if ( v5 >= maxsize )
    {
      ivp_message(templat: "qhull internal errror (point_add): point p%d is out of bounds (%d)\n", v5, maxsize);
      qh_errexit(exitcode: 5, facet: nullptr, ridge: nullptr);
    }
    set->e[v5].i = (int)elem;
  }
  else
  {
    ivp_message(templat: "qhull internal warning (point_add): unknown point %p id %d\n", point, v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004FE90
// Name: struct setT __near * qh_pointfacet(void)
// Source: json
//------------------------------------------------------------------------------
setT *__cdecl qh_pointfacet()
{
  int v0; // esi
  setT *v1; // ebx
  facetT *facet_list; // esi
  unsigned int vertex_visit; // ecx
  setT *vertices; // eax
  setelemT *e; // edi
  setelemT v6; // eax
  setT *coplanarset; // eax
  long double **v8; // edi
  long double *p; // eax
  setT *outsideset; // eax
  long double **v11; // edi
  long double *v12; // eax

  v0 = qh_qh.num_points + qh_setsize(set: qh_qh.other_points);
  v1 = qh_settemp(setsize: v0);
  qh_setzero(set: v1, index: 0, size: v0);
  facet_list = qh_qh.facet_list;
  vertex_visit = ++qh_qh.vertex_visit;
  if ( qh_qh.facet_list != nullptr )
  {
    while ( facet_list->next != nullptr )
    {
      vertices = facet_list->vertices;
      if ( vertices != nullptr )
      {
        e = vertices->e;
        v6.p = (void *)vertices->e[0];
        if ( v6.i != 0 )
        {
          while ( 1 )
          {
            ++e;
            if ( *(_DWORD *)(v6.i + 16) != vertex_visit )
            {
              *(_DWORD *)(v6.i + 16) = vertex_visit;
              qh_point_add(set: v1, point: *(long double **)(v6.i + 8), elem: facet_list);
            }
            v6.p = e->p;
            if ( e->i == 0 )
              break;
            vertex_visit = qh_qh.vertex_visit;
          }
        }
      }
      coplanarset = facet_list->coplanarset;
      if ( coplanarset != nullptr )
      {
        v8 = (long double **)coplanarset->e;
        p = (long double *)coplanarset->e[0].p;
        if ( p != nullptr )
        {
          do
          {
            ++v8;
            qh_point_add(set: v1, point: p, elem: facet_list);
            p = *v8;
          }
          while ( *v8 != nullptr );
        }
      }
      outsideset = facet_list->outsideset;
      if ( outsideset != nullptr )
      {
        v11 = (long double **)outsideset->e;
        v12 = (long double *)outsideset->e[0].p;
        if ( v12 != nullptr )
        {
          do
          {
            ++v11;
            qh_point_add(set: v1, point: v12, elem: facet_list);
            v12 = *v11;
          }
          while ( *v11 != nullptr );
        }
      }
      facet_list = facet_list->next;
      if ( facet_list == nullptr )
        break;
      vertex_visit = qh_qh.vertex_visit;
    }
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x1004FF90
// Name: struct setT __near * qh_pointvertex(void)
// Source: json
//------------------------------------------------------------------------------
setT *__cdecl qh_pointvertex()
{
  int v0; // esi
  setT *v1; // edi
  vertexT *i; // esi

  v0 = qh_qh.num_points + qh_setsize(set: qh_qh.other_points);
  v1 = qh_settemp(setsize: v0);
  qh_setzero(set: v1, index: 0, size: v0);
  for ( i = qh_qh.vertex_list; i != nullptr; i = i->next )
  {
    if ( i->next == nullptr )
      break;
    qh_point_add(set: v1, point: i->point, elem: i);
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x1004FFF0
// Name: void qh_prependfacet(struct facetT __near *,struct facetT __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_prependfacet(facetT *facet, facetT **facetlist)
{
  facetT *v2; // edi
  facetT *previous; // eax

  v2 = *facetlist;
  if ( qh_qh.IStracing >= 4 )
    fprintf(str: qh_qh.ferr, format: "qh_prependfacet: prepend f%d before f%d\n", facet->id, v2->id);
  previous = v2->previous;
  facet->previous = previous;
  if ( previous != nullptr )
    previous->next = facet;
  v2->previous = facet;
  facet->next = *facetlist;
  if ( qh_qh.facet_list == v2 )
    qh_qh.facet_list = facet;
  if ( qh_qh.facet_next == v2 )
    qh_qh.facet_next = facet;
  *facetlist = facet;
  ++qh_qh.num_facets;
}

//------------------------------------------------------------------------------
// Address: 0x10050070
// Name: void qh_printhashtable(struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_printhashtable(_iobuf *fp)
{
  int v1; // esi
  setelemT v2; // ebx
  int v3; // edi
  int v4; // eax
  int v5; // eax
  int *v6; // edi
  int v7; // eax
  int v8; // edi
  int v9; // edi
  int facet_n; // [esp+4h] [ebp-Ch]
  int facet_i; // [esp+8h] [ebp-8h]
  int neighbor_n; // [esp+Ch] [ebp-4h]

  v1 = 0;
  neighbor_n = 0;
  if ( qh_qh.hash_table != nullptr )
  {
    v2.p = (void *)qh_qh.hash_table->e[0];
    facet_i = 0;
    facet_n = qh_setsize(set: qh_qh.hash_table);
    if ( facet_n > 0 )
    {
      do
      {
        if ( v2.i != 0 )
        {
          if ( *(_DWORD *)(v2.i + 60) != 0 )
          {
            v3 = *(_DWORD *)(*(_DWORD *)(v2.i + 60) + 4);
            v1 = 0;
            v4 = qh_setsize(set: *(setT **)(v2.i + 60));
            neighbor_n = v4;
            if ( v4 > 0 )
            {
              do
              {
                if ( v3 == 0 )
                  break;
                if ( v3 == 2 )
                  break;
                if ( v3 == 1 )
                  break;
                v3 = *(_DWORD *)(*(_DWORD *)(v2.i + 60) + 4 * v1++ + 8);
              }
              while ( v1 < v4 );
            }
          }
          if ( v1 != neighbor_n )
          {
            fprintf(str: fp, format: "hash %d f%d ", facet_i, *(_DWORD *)(v2.i + 76));
            v5 = *(_DWORD *)(v2.i + 52);
            if ( v5 != 0 )
            {
              v6 = (int *)(v5 + 4);
              v7 = *(_DWORD *)(v5 + 4);
              if ( v7 != 0 )
              {
                do
                {
                  ++v6;
                  fprintf(str: fp, format: "v%d ", *(_DWORD *)(v7 + 20) & 0xFFFFFF);
                  v7 = *v6;
                }
                while ( *v6 != 0 );
              }
            }
            fprintf(str: fp, format: "\n neighbors:");
            if ( *(_DWORD *)(v2.i + 60) != 0 )
            {
              v8 = *(_DWORD *)(*(_DWORD *)(v2.i + 60) + 4);
              v1 = 0;
              neighbor_n = qh_setsize(set: *(setT **)(v2.i + 60));
              if ( neighbor_n > 0 )
              {
                do
                {
                  if ( v8 == 2 )
                  {
                    v9 = -3;
                  }
                  else if ( v8 == 1 )
                  {
                    v9 = -2;
                  }
                  else if ( v8 != 0 )
                  {
                    v9 = *(_DWORD *)(v8 + 76);
                  }
                  else
                  {
                    v9 = -1;
                  }
                  fprintf(str: fp, format: " %d", v9);
                  v8 = *(_DWORD *)(*(_DWORD *)(v2.i + 60) + 4 * v1++ + 8);
                }
                while ( v1 < neighbor_n );
              }
            }
            fprintf(str: fp, format: "\n");
          }
        }
        v2.p = (void *)*(&qh_qh.hash_table[1].maxsize + facet_i++);
      }
      while ( facet_i < facet_n );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100501F0
// Name: void qh_printlists(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_printlists()
{
  facetT *i; // esi
  int v1; // ecx
  unsigned int id; // esi
  unsigned int v3; // edx
  unsigned int v4; // eax
  vertexT *j; // esi

  ivp_message(templat: "qh_printlists: facets:");
  for ( i = qh_qh.facet_list; i != nullptr; i = i->next )
  {
    if ( i->next == nullptr )
      break;
    ivp_message(templat: " %d", i->id);
  }
  if ( qh_qh.newvertex_list != nullptr )
    v1 = *((_DWORD *)qh_qh.newvertex_list + 5) & 0xFFFFFF;
  else
    v1 = -1;
  if ( qh_qh.facet_next != nullptr )
    id = qh_qh.facet_next->id;
  else
    id = -1;
  if ( qh_qh.visible_list != nullptr )
    v3 = qh_qh.visible_list->id;
  else
    v3 = -1;
  if ( qh_qh.newfacet_list != nullptr )
    v4 = qh_qh.newfacet_list->id;
  else
    v4 = -1;
  ivp_message(
    templat: "\n  new facets %d visible facets %d next facet for addpoint %d\n  vertices (new %d):",
    v4,
    v3,
    id,
    v1);
  for ( j = qh_qh.vertex_list; j != nullptr; j = j->next )
  {
    if ( j->next == nullptr )
      break;
    ivp_message(templat: " %d", *((_DWORD *)j + 5) & 0xFFFFFF);
  }
  ivp_message(templat: "\n");
}

//------------------------------------------------------------------------------
// Address: 0x100502D0
// Name: void qh_resetlists(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_resetlists(unsigned int stats)
{
  vertexT *newvertex_list; // eax
  int v2; // esi
  int v3; // edx
  vertexT *v4; // ecx
  facetT *newfacet_list; // ecx
  vertexT *next; // ecx
  facetT *v7; // eax
  facetT *v8; // ecx
  facetT *visible_list; // eax
  int v10; // ecx

  newvertex_list = qh_qh.newvertex_list;
  v2 = 0;
  v3 = 0;
  if ( stats != 0 )
  {
    v4 = qh_qh.newvertex_list;
    if ( qh_qh.newvertex_list != nullptr )
    {
      while ( 1 )
      {
        v4 = v4->next;
        if ( v4 == nullptr )
          break;
        ++v3;
      }
    }
    newfacet_list = qh_qh.newfacet_list;
    if ( qh_qh.newfacet_list != nullptr )
    {
      while ( 1 )
      {
        newfacet_list = newfacet_list->next;
        if ( newfacet_list == nullptr )
          break;
        ++v2;
      }
    }
    qh_qhstat.stats[190].i += v3;
    if ( qh_qhstat.stats[191].i < v3 )
      qh_qhstat.stats[191].i = v3;
    qh_qhstat.stats[123].i += v2;
    if ( qh_qhstat.stats[124].i < v2 )
      qh_qhstat.stats[124].i = v2;
  }
  if ( qh_qh.newvertex_list != nullptr )
  {
    while ( 1 )
    {
      next = newvertex_list->next;
      if ( newvertex_list->next == nullptr )
        break;
      *((_DWORD *)newvertex_list + 5) &= ~0x10000000u;
      newvertex_list = next;
    }
  }
  v7 = qh_qh.newfacet_list;
  qh_qh.newvertex_list = nullptr;
  if ( qh_qh.newfacet_list != nullptr )
  {
    while ( 1 )
    {
      v8 = v7->next;
      if ( v8 == nullptr )
        break;
      *((_DWORD *)v7 + 20) &= ~0x200u;
      v7 = v8;
    }
  }
  visible_list = qh_qh.visible_list;
  for ( qh_qh.newfacet_list = nullptr; visible_list != nullptr; visible_list = visible_list->next )
  {
    v10 = *((_DWORD *)visible_list + 20);
    if ( (v10 & 0x400) == 0 )
      break;
    visible_list->f.replace = nullptr;
    *((_DWORD *)visible_list + 20) = v10 & 0xFFFFFBFF;
  }
  qh_qh.visible_list = nullptr;
  qh_qh.num_visible = 0;
  qh_qh.NEWfacets = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100503C0
// Name: struct setT __near * qh_vertexintersect_new(struct setT __near *,struct setT __near *)
// Source: json
//------------------------------------------------------------------------------
setT *__cdecl qh_vertexintersect_new(setT *vertexsetA, setT *vertexsetB)
{
  setT *result; // eax
  _DWORD *p; // ecx
  setelemT *e; // esi
  setelemT *v5; // edi
  _DWORD *i; // eax
  setT *intersection; // [esp+8h] [ebp-4h] BYREF

  result = qh_setnew(setsize: qh_qh.hull_dim - 1);
  p = vertexsetA->e[0].p;
  e = vertexsetA->e;
  v5 = vertexsetB->e;
  intersection = result;
  if ( p != nullptr )
  {
    while ( 1 )
    {
      i = (_DWORD *)v5->i;
      if ( v5->i == 0 )
        return intersection;
      if ( p == i )
      {
        qh_setappend(setp: &intersection, newelem: p);
        ++e;
      }
      else if ( (p[5] & 0xFFFFFFu) > (i[5] & 0xFFFFFFu) )
      {
        ++e;
        goto LABEL_6;
      }
      ++v5;
LABEL_6:
      p = (_DWORD *)e->i;
      if ( e->i == 0 )
        return intersection;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10050440
// Name: void qh_vertexneighbors(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_vertexneighbors()
{
  facetT *facet_list; // ebx
  unsigned int i; // ecx
  setT *vertices; // eax
  setelemT v3; // esi
  setelemT *e; // edi

  if ( qh_qh.VERTEXneighbors == 0 )
  {
    if ( qh_qh.IStracing >= 1 )
      fprintf(str: qh_qh.ferr, format: "qh_vertexneighbors: determing neighboring facets for each vertex\n");
    facet_list = qh_qh.facet_list;
    for ( i = ++qh_qh.vertex_visit; facet_list != nullptr; facet_list = facet_list->next )
    {
      if ( facet_list->next == nullptr )
        break;
      if ( (*((_DWORD *)facet_list + 20) & 0x400) == 0 )
      {
        vertices = facet_list->vertices;
        if ( vertices != nullptr )
        {
          v3.p = (void *)vertices->e[0];
          e = vertices->e;
          if ( v3.i != 0 )
          {
            do
            {
              ++e;
              if ( *(_DWORD *)(v3.i + 16) != i )
              {
                *(_DWORD *)(v3.i + 16) = i;
                *(_DWORD *)(v3.i + 12) = qh_setnew(setsize: qh_qh.hull_dim);
              }
              qh_setappend(setp: (setT **)(v3.i + 12), newelem: facet_list);
              v3.p = e->p;
              i = qh_qh.vertex_visit;
            }
            while ( e->i != 0 );
          }
        }
      }
    }
    qh_qh.VERTEXneighbors = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100504F0
// Name: void qh_check_maxout(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_check_maxout()
{
  setT *v0; // eax
  vertexT *vertex_list; // edi
  setT *neighbors; // eax
  facetT *p; // esi
  facetT **e; // ebx
  int v5; // eax
  setT *v6; // eax
  facetT *v7; // esi
  int v8; // ebx
  long double *v9; // edi
  facetT *v10; // eax
  double v11; // xmm0_8
  int v12; // eax
  int v13; // [esp-4h] [ebp-48h]
  double v14; // [esp+0h] [ebp-44h]
  unsigned int id; // [esp+8h] [ebp-3Ch]
  unsigned int v16; // [esp+8h] [ebp-3Ch]
  double maxoutside; // [esp+18h] [ebp-2Ch]
  double dist; // [esp+20h] [ebp-24h] BYREF
  facetT *facetlist; // [esp+28h] [ebp-1Ch] BYREF
  long double facet_n; // [esp+2Ch] [ebp-18h]
  int numpart; // [esp+34h] [ebp-10h] BYREF
  setT *vertices; // [esp+38h] [ebp-Ch] BYREF
  setT *facets; // [esp+3Ch] [ebp-8h] BYREF
  int notgood; // [esp+40h] [ebp-4h]

  notgood = 0;
  if ( qh_qh.IStracing >= 1 )
    fprintf(str: qh_qh.ferr, format: "qh_check_maxout: check and update maxoutside for each facet.\n");
  facet_n = 0.0;
  maxoutside = 0.0;
  if ( qh_qh.VERTEXneighbors != 0
    && (qh_qh.PRINTsummary != 0
     || qh_qh.KEEPinside != 0
     || qh_qh.KEEPcoplanar != 0
     || qh_qh.TRACElevel != 0
     || qh_qh.PRINTstatistics != 0
     || qh_qh.PRINTout[0] == qh_PRINTsummary
     || qh_qh.PRINTout[0] == qh_PRINTnone) )
  {
    if ( qh_qh.IStracing >= 1 )
      fprintf(str: qh_qh.ferr, format: "qh_check_maxout: determine actual maxoutside and minvertex\n");
    v0 = qh_pointvertex();
    vertex_list = qh_qh.vertex_list;
    for ( vertices = v0; vertex_list != nullptr; vertex_list = vertex_list->next )
    {
      if ( vertex_list->next == nullptr )
        break;
      neighbors = vertex_list->neighbors;
      if ( neighbors != nullptr )
      {
        p = (facetT *)neighbors->e[0].p;
        e = (facetT **)neighbors->e;
        if ( p != nullptr )
        {
          do
          {
            ++qh_qhstat.stats[54].i;
            ++e;
            qh_distplane(point: vertex_list->point, facet: p, &dist);
            if ( facet_n > dist )
              facet_n = dist;
            if ( -dist > qh_qh.TRACEdist
              || dist > qh_qh.TRACEdist
              || p == qh_qh.tracefacet
              || vertex_list == qh_qh.tracevertex )
            {
              id = p->id;
              v14 = dist;
              v13 = *((_DWORD *)vertex_list + 5) & 0xFFFFFF;
              v5 = qh_pointid(point: vertex_list->point);
              ivp_message(templat: "qh_check_maxout: p%d (v%d) is %.2g from f%d\n", v5, v13, v14, id);
            }
            p = *e;
          }
          while ( *e != nullptr );
        }
      }
    }
    if ( qh_qh.MERGING != 0 && qh_qhstat.stats[116].r > qh_qh.min_vertex )
      qh_qhstat.stats[116].r = qh_qh.min_vertex;
    qh_qh.min_vertex = facet_n;
    qh_settempfree(set: &vertices);
  }
  v6 = qh_pointfacet();
  facets = v6;
  if ( v6 != nullptr )
  {
    v7 = (facetT *)v6->e[0].p;
    v8 = 0;
    for ( HIDWORD(facet_n) = qh_setsize(set: v6); v8 < SHIDWORD(facet_n); ++v8 )
    {
      if ( v7 != nullptr )
      {
        v9 = qh_point(id: v8);
        if ( v9 != qh_qh.GOODpointp )
        {
          ++qh_qhstat.stats[174].i;
          v10 = qh_findbest(
                  point: v9,
                  startfacet: v7,
                  bestoutside: 1u,
                  newfacets: 0,
                  noupper: 0,
                  &dist,
                  isoutside: nullptr,
                  &numpart);
          qh_qhstat.stats[18].i += numpart;
          v11 = dist;
          if ( v10 != nullptr && dist > maxoutside )
          {
            if ( qh_qh.ONLYgood == 0
              || (*((_DWORD *)v10 + 20) & 0x40000) != 0
              || (v10 = qh_findgooddist(point: v9, facetA: v10, distp: &dist, &facetlist), v11 = dist, v10 != nullptr)
              && dist > maxoutside )
            {
              maxoutside = v11;
            }
            else
            {
              ++notgood;
            }
          }
          if ( v11 > qh_qh.TRACEdist || v10 != nullptr && v10 == qh_qh.tracefacet )
          {
            v16 = v10->id;
            v12 = qh_pointid(point: v9);
            ivp_message(templat: "qh_check_maxout: p%d is %.2g above f%d\n", v12, v11, v16);
          }
        }
      }
      v7 = (facetT *)*(&facets[1].maxsize + v8);
    }
  }
  qh_settempfree(set: &facets);
  qh_qhstat.stats[93].r = maxoutside - qh_qh.max_outside;
  if ( qh_qh.max_outside > qh_qhstat.stats[94].r )
    qh_qhstat.stats[94].r = qh_qh.max_outside;
  qh_qh.max_outside = maxoutside;
  qh_nearcoplanar();
  qh_qh.maxoutdone = 1;
  if ( qh_qh.IStracing >= 1 )
    fprintf(
      str: qh_qh.ferr,
      format: "qh_check_maxout: maxoutside %2.2g, min_vertex %2.2g, outside of not good %d\n",
      maxoutside,
      (double)qh_qh.min_vertex,
      notgood);
}

//------------------------------------------------------------------------------
// Address: 0x10050860
// Name: void qh_checkfacet(struct facetT __near *,unsigned int,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_checkfacet(facetT *facet, unsigned int newmerge, unsigned int *waserrorp)
{
  bool v4; // zf
  setT *vertices; // eax
  setelemT v6; // edi
  setelemT *e; // ebx
  int v8; // eax
  unsigned int v9; // eax
  int v10; // edi
  int v11; // ebx
  int v12; // eax
  setT *neighbors; // ebx
  setelemT v14; // edi
  setelemT *v15; // ebx
  setT *v16; // eax
  setelemT v17; // edi
  setelemT *v18; // ebx
  setT *ridges; // ebx
  setelemT v20; // edi
  setelemT *v21; // ebx
  setT *v22; // eax
  setelemT v23; // edi
  int v24; // eax
  int v25; // eax
  setT *v26; // edx
  int v27; // eax
  int v28; // ebx
  setT *v29; // eax
  facetT *v30; // edi
  setT *v31; // eax
  setelemT *v32; // ecx
  setelemT v33; // eax
  setT *v34; // edx
  setelemT v35; // eax
  setelemT *v36; // ecx
  setT *v37; // eax
  setelemT v38; // ebx
  int v39; // eax
  facetT *v40; // eax
  int v41; // eax
  int v42; // edi
  int *v43; // ecx
  int v44; // eax
  setelemT v45; // edi
  setelemT *v46; // edx
  int v47; // eax
  facetT *v48; // ebx
  setelemT v49; // ebx
  setelemT *v50; // eax
  setelemT *v51; // eax
  signed int v52; // edi
  setelemT v53; // edi
  int v54; // eax
  setelemT v55; // ebx
  int skipB; // [esp+8h] [ebp-20h]
  int skipBa; // [esp+8h] [ebp-20h]
  unsigned int previousid; // [esp+Ch] [ebp-1Ch]
  setelemT *previousida; // [esp+Ch] [ebp-1Ch]
  unsigned int previousidb; // [esp+Ch] [ebp-1Ch]
  setT *intersection; // [esp+10h] [ebp-18h] BYREF
  int ridge_n; // [esp+14h] [ebp-14h]
  facetT *errother; // [esp+18h] [ebp-10h]
  ridgeT *errridge; // [esp+1Ch] [ebp-Ch]
  facetT *neighbor; // [esp+20h] [ebp-8h]
  unsigned int waserror; // [esp+24h] [ebp-4h]
  int i; // [esp+30h] [ebp+8h]
  facetT **ia; // [esp+30h] [ebp+8h]
  setelemT *ib; // [esp+30h] [ebp+8h]
  int ic; // [esp+30h] [ebp+8h]

  v4 = (*((_DWORD *)facet + 20) & 0x400) == 0;
  errother = nullptr;
  errridge = nullptr;
  previousid = 0x7FFFFFFF;
  waserror = 0;
  if ( !v4 )
  {
    ivp_message(templat: "qhull internal error (qh_checkfacet): facet f%d is on the visible_list\n", facet->id);
    qh_errexit(exitcode: 5, facet, ridge: nullptr);
  }
  if ( facet->normal == nullptr )
  {
    if ( qh_qh.ferr != nullptr )
      ivp_message(templat: "qhull internal error (qh_checkfacet): facet f%d does not have  a normal\n", facet->id);
    waserror = 1;
  }
  qh_setcheck(set: facet->vertices, tname: "vertices for f", id: facet->id);
  qh_setcheck(set: facet->ridges, tname: "ridges for f", id: facet->id);
  qh_setcheck(set: facet->outsideset, tname: "outsideset for f", id: facet->id);
  qh_setcheck(set: facet->coplanarset, tname: "coplanarset for f", id: facet->id);
  qh_setcheck(set: facet->neighbors, tname: "neighbors for f", id: facet->id);
  vertices = facet->vertices;
  if ( vertices != nullptr )
  {
    v6.p = (void *)vertices->e[0];
    e = vertices->e;
    if ( v6.i != 0 )
    {
      while ( 1 )
      {
        v8 = *(_DWORD *)(v6.i + 20);
        ++e;
        if ( (v8 & 0x8000000) != 0 )
        {
          ivp_message(
            templat: "qhull internal error (qh_checkfacet): deleted vertex v%d in f%d\n",
            v8 & 0xFFFFFF,
            facet->id);
          qh_errprint(
            string: "ERRONEOUS",
            atfacet: nullptr,
            otherfacet: nullptr,
            atridge: nullptr,
            atvertex: (vertexT *)v6.p);
          waserror = 1;
        }
        v9 = *(_DWORD *)(v6.i + 20) & 0xFFFFFF;
        if ( v9 >= previousid )
          break;
        v6.p = e->p;
        previousid = v9;
        if ( e->i == 0 )
          goto LABEL_15;
      }
      ivp_message(
        templat: "qhull internal error (qh_checkfacet): vertices of f%d are not in descending id order at v%d\n",
        facet->id,
        *(_DWORD *)(v6.i + 20) & 0xFFFFFF);
      waserror = 1;
    }
  }
LABEL_15:
  v10 = qh_setsize(set: facet->neighbors);
  v11 = qh_setsize(set: facet->vertices);
  i = qh_setsize(set: facet->ridges);
  v12 = *((_DWORD *)facet + 20);
  if ( (v12 & 0x1000) != 0 )
  {
    if ( v11 + v10 != 2 * qh_qh.hull_dim && (v12 & 0x60000000) == 0 )
    {
      ivp_message(
        templat: "qhull internal error (qh_checkfacet): for simplicial facet f%d, #vertices %d + #neighbors %d != 2*qh hull_dim\n",
        facet->id,
        v11,
        v10);
      qh_setprint(fp: qh_qh.ferr, string: str, set: facet->neighbors);
LABEL_33:
      waserror = 1;
    }
  }
  else
  {
    if ( newmerge == 0 && (v11 < qh_qh.hull_dim || v10 < qh_qh.hull_dim) && (v12 & 0x60000000) == 0 )
    {
      ivp_message(
        templat: "qhull internal error (qh_checkfacet): for facet f%d, #vertices %d or #neighbors %d < qh hull_dim\n",
        facet->id,
        v11,
        v10);
      waserror = 1;
    }
    if ( i >= v10 )
    {
      if ( qh_qh.hull_dim == 3 )
      {
        if ( v11 == i || qh_qh.NEWfacets != 0 )
          goto LABEL_34;
      }
      else if ( qh_qh.hull_dim != 2 || i + v11 + v10 == 6 )
      {
        goto LABEL_34;
      }
    }
    if ( (*((_DWORD *)facet + 20) & 0x60000000) == 0 )
    {
      ivp_message(
        templat: "qhull internal error (qh_checkfacet): for facet f%d, #ridges %d < #neighbors %d or (3-d) != #vertices %d or (2-d) not all 2\n",
        facet->id,
        i,
        v10,
        v11);
      goto LABEL_33;
    }
  }
LABEL_34:
  neighbors = facet->neighbors;
  if ( neighbors != nullptr )
  {
    v14.p = (void *)neighbors->e[0];
    v15 = neighbors->e;
    if ( v14.i != 0 )
    {
      do
      {
        ++v15;
        if ( v14.i == 2 || v14.i == 1 )
        {
          ivp_message(
            templat: "qhull internal error (qh_checkfacet): facet f%d still has a MERGE or DUP neighbor\n",
            facet->id);
          qh_errexit(exitcode: 5, facet, ridge: nullptr);
        }
        *(_DWORD *)(v14.i + 80) |= 0x2000u;
        v14.p = v15->p;
      }
      while ( v15->i != 0 );
    }
  }
  v16 = facet->neighbors;
  if ( v16 != nullptr )
  {
    v17.p = (void *)v16->e[0];
    v18 = v16->e;
    if ( v17.i != 0 )
    {
      do
      {
        ++v18;
        if ( qh_setin(set: *(setT **)(v17.i + 60), setelem: facet) == 0 )
        {
          ivp_message(
            templat: "qhull internal error (qh_checkfacet): facet f%d has neighbor f%d, but f%d does not have neighbor f%d\n",
            facet->id,
            *(_DWORD *)(v17.i + 76),
            *(_DWORD *)(v17.i + 76),
            facet->id);
          errother = (facetT *)v17.i;
          waserror = 1;
        }
        if ( (*(_DWORD *)(v17.i + 80) & 0x2000) == 0 )
        {
          ivp_message(
            templat: "qhull internal error (qh_checkfacet): facet f%d has a duplicate neighbor f%d\n",
            facet->id,
            *(_DWORD *)(v17.i + 76));
          errother = (facetT *)v17.i;
          waserror = 1;
        }
        *(_DWORD *)(v17.i + 80) &= ~0x2000u;
        v17.p = v18->p;
      }
      while ( v18->i != 0 );
    }
  }
  ridges = facet->ridges;
  if ( ridges != nullptr )
  {
    v20.p = (void *)ridges->e[0];
    v21 = ridges->e;
    if ( v20.i != 0 )
    {
      do
      {
        ++v21;
        qh_setcheck(set: *(setT **)v20.p, tname: "vertices for r", id: *(_DWORD *)(v20.i + 12) & 0xFFFFFF);
        *(_DWORD *)(v20.i + 12) &= ~0x1000000u;
        v20.p = v21->p;
      }
      while ( v21->i != 0 );
    }
  }
  v22 = facet->ridges;
  if ( v22 != nullptr )
  {
    v23.p = (void *)v22->e[0];
    v24 = (int)v22->e;
    if ( v23.i != 0 )
    {
      do
      {
        ridge_n = v24 + 4;
        v25 = *(_DWORD *)(v23.i + 12);
        if ( (v25 & 0x1000000) != 0 )
        {
          ivp_message(
            templat: "qhull internal error (qh_checkfacet): facet f%d has a duplicate ridge r%d\n",
            facet->id,
            v25 & 0xFFFFFF);
          errridge = (ridgeT *)v23.i;
          waserror = 1;
        }
        v26 = *(setT **)v23.p;
        *(_DWORD *)(v23.i + 12) |= 0x1000000u;
        v27 = qh_setsize(set: v26);
        if ( v27 != qh_qh.hull_dim - 1 )
        {
          ivp_message(
            templat: "qhull internal error (qh_checkfacet): ridge between f%d and f%d has %d vertices\n",
            *(_DWORD *)(*(_DWORD *)(v23.i + 4) + 76),
            *(_DWORD *)(*(_DWORD *)(v23.i + 8) + 76),
            v27);
          errridge = (ridgeT *)v23.i;
          waserror = 1;
        }
        v28 = *(_DWORD *)(v23.i + 4);
        if ( (facetT *)v28 == facet )
          v28 = *(_DWORD *)(v23.i + 8);
        *(_DWORD *)(v28 + 80) |= 0x2000u;
        if ( qh_setin(set: facet->neighbors, setelem: (void *)v28) == 0 )
        {
          ivp_message(
            templat: "qhull internal error (qh_checkfacet): for facet f%d, neighbor f%d of ridge r%d not in facet\n",
            facet->id,
            *(_DWORD *)(v28 + 76),
            *(_DWORD *)(v23.i + 12) & 0xFFFFFF);
          errridge = (ridgeT *)v23.i;
          waserror = 1;
        }
        v24 = ridge_n;
        v23.p = *(void **)ridge_n;
      }
      while ( *(_DWORD *)ridge_n != 0 );
    }
  }
  v29 = facet->neighbors;
  if ( (*((_DWORD *)facet + 20) & 0x1000) != 0 )
  {
    if ( v29 != nullptr )
    {
      v49.p = (void *)v29->e[0];
      v50 = v29->e;
      if ( v49.i != 0 )
      {
        do
        {
          v51 = v50 + 1;
          ib = v51;
          if ( (*(_DWORD *)(v49.i + 80) & 0x1000) != 0 )
          {
            v52 = ((char *)v51 - (char *)facet->neighbors - 8) >> 2;
            skipB = qh_setindex(set: *(setT **)(v49.i + 60), atelem: facet);
            if ( !qh_setequal_skip(setA: facet->vertices, skipA: v52, setB: *(setT **)(v49.i + 52), skipB) )
            {
              ivp_message(
                templat: "qhull internal error (qh_checkfacet): facet f%d skip %d and neighbor f%d skip %d do not match \n",
                facet->id,
                v52,
                *(_DWORD *)(v49.i + 76),
                skipB);
              errother = (facetT *)v49.i;
              waserror = 1;
            }
          }
          v50 = ib;
          v49.p = ib->p;
        }
        while ( ib->i != 0 );
      }
    }
  }
  else if ( v29 != nullptr )
  {
    ia = (facetT **)v29->e;
    for ( neighbor = (facetT *)v29->e[0].p; neighbor != nullptr; neighbor = *ia )
    {
      v30 = neighbor;
      ++ia;
      if ( (*((_DWORD *)neighbor + 20) & 0x2000) == 0 )
      {
        ivp_message(
          templat: "qhull internal error (qh_checkfacet): facet f%d does not have a ridge for neighbor f%d\n",
          facet->id,
          neighbor->id);
        errother = v30;
        waserror = 1;
      }
      intersection = qh_vertexintersect_new(vertexsetA: facet->vertices, vertexsetB: v30->vertices);
      qh_settemppush(set: intersection);
      v31 = facet->vertices;
      if ( v31 != nullptr )
      {
        v32 = v31->e;
        for ( v33.p = (void *)v31->e[0]; v33.i != 0; ++v32 )
        {
          *(_DWORD *)(v33.i + 20) &= 0xFCFFFFFF;
          v33.p = v32[1].p;
        }
      }
      v34 = intersection;
      if ( intersection != nullptr )
      {
        v35.p = (void *)intersection->e[0];
        v36 = intersection->e;
        if ( v35.i != 0 )
        {
          do
          {
            *(_DWORD *)(v35.i + 20) |= 0x1000000u;
            v35.p = v36[1].p;
            ++v36;
          }
          while ( v35.i != 0 );
          v34 = intersection;
        }
      }
      v37 = facet->ridges;
      if ( v37 != nullptr )
      {
        v38.p = (void *)v37->e[0];
        v39 = (int)v37->e;
        if ( v38.i != 0 )
        {
          do
          {
            ridge_n = v39 + 4;
            v40 = *(facetT **)(v38.i + 4);
            if ( v40 == facet )
              v40 = *(facetT **)(v38.i + 8);
            if ( neighbor == v40 )
            {
              v41 = *(_DWORD *)v38.p;
              if ( *(_DWORD *)v38.p != 0 )
              {
                v42 = *(_DWORD *)(v41 + 4);
                v43 = (int *)(v41 + 4);
                if ( v42 != 0 )
                {
                  do
                  {
                    v44 = *(_DWORD *)(v42 + 20);
                    ++v43;
                    if ( (v44 & 0x1000000) == 0 )
                    {
                      ivp_message(
                        templat: "qhull internal error (qh_checkfacet): vertex v%d in r%d not in f%d intersect f%d\n",
                        v44 & 0xFFFFFF,
                        *(_DWORD *)(v38.i + 12) & 0xFFFFFF,
                        facet->id,
                        neighbor->id);
                      qh_errexit(exitcode: 5, facet, ridge: (ridgeT *)v38.p);
                    }
                    *(_DWORD *)(v42 + 20) |= 0x2000000u;
                    v42 = *v43;
                  }
                  while ( *v43 != 0 );
                }
              }
            }
            v39 = ridge_n;
            v38.p = *(void **)ridge_n;
          }
          while ( *(_DWORD *)ridge_n != 0 );
          v34 = intersection;
        }
      }
      if ( newmerge == 0 && v34 != nullptr )
      {
        v45.p = (void *)v34->e[0];
        v46 = v34->e;
        if ( v45.i != 0 )
        {
          do
          {
            v47 = *(_DWORD *)(v45.i + 20);
            previousida = v46 + 1;
            if ( (v47 & 0x2000000) == 0 && (qh_qh.IStracing >= 3 || qh_qh.MERGING == 0) )
            {
              v48 = neighbor;
              ivp_message(
                templat: "qhull precision error (qh_checkfacet): vertex v%d in f%d intersect f%d but\n"
                " not in a ridge.  This is ok under merging.  Last point was p%d\n",
                v47 & 0xFFFFFF,
                facet->id,
                neighbor->id,
                qh_qh.furthest_id);
              if ( qh_qh.FORCEoutput == 0 && qh_qh.MERGING == 0 )
              {
                qh_errprint(
                  string: "ERRONEOUS",
                  atfacet: facet,
                  otherfacet: v48,
                  atridge: nullptr,
                  atvertex: (vertexT *)v45.p);
                if ( qh_qh.MERGING == 0 )
                  qh_errexit(exitcode: 5, facet: nullptr, ridge: nullptr);
              }
            }
            v46 = previousida;
            v45.p = previousida->p;
          }
          while ( previousida->i != 0 );
        }
      }
      qh_settempfree(set: &intersection);
    }
  }
  if ( qh_qh.hull_dim < 5 && (qh_qh.IStracing > 2 || qh_qh.CHECKfrequently != 0) && facet->ridges != nullptr )
  {
    v53.p = (void *)facet->ridges->e[0];
    v54 = qh_setsize(set: facet->ridges);
    ridge_n = v54;
    if ( v54 > 0 )
    {
      neighbor = nullptr;
      previousidb = 1;
      skipBa = v54;
      do
      {
        for ( ic = previousidb; ic < ridge_n; ++ic )
        {
          v55.p = (void *)facet->ridges->e[ic];
          if ( qh_setequal(setA: *(setT **)v53.p, setB: *(setT **)v55.p) != 0 )
          {
            ivp_message(
              templat: "qh_checkfacet: ridges r%d and r%d have the same vertices\n",
              *(_DWORD *)(v53.i + 12) & 0xFFFFFF,
              *(_DWORD *)(v55.i + 12) & 0xFFFFFF);
            errridge = (ridgeT *)v53.i;
            waserror = 1;
          }
        }
        v53.p = *(void **)((char *)&facet->ridges[1].maxsize + (unsigned int)neighbor);
        ++previousidb;
        v4 = skipBa-- == 1;
        neighbor = (facetT *)((char *)neighbor + 4);
      }
      while ( !v4 );
    }
  }
  if ( waserror != 0 )
  {
    qh_errprint(string: "ERRONEOUS", atfacet: facet, otherfacet: errother, atridge: errridge, atvertex: nullptr);
    *waserrorp = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10051060
// Name: void qh_checkpolygon(struct facetT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_checkpolygon(facetT *facetlist)
{
  int v1; // esi
  int v2; // edi
  int v3; // ebx
  facetT *v4; // ecx
  facetT *i; // esi
  vertexT *vertex_list; // eax
  vertexT *next; // ecx
  facetT *j; // ebx
  int v9; // eax
  setT *vertices; // eax
  _DWORD *p; // esi
  setelemT *e; // edi
  int v13; // eax
  vertexT *k; // esi
  facetT *m; // esi
  int v16; // eax
  int v17; // eax
  long double *v18; // [esp-4h] [ebp-28h]
  int numvertices; // [esp+Ch] [ebp-18h]
  int totvertices; // [esp+10h] [ebp-14h]
  int totvneighbors; // [esp+14h] [ebp-10h]
  int numridges; // [esp+18h] [ebp-Ch]
  unsigned int waserror; // [esp+1Ch] [ebp-8h] BYREF
  int numfacets; // [esp+20h] [ebp-4h]

  v1 = 0;
  v2 = 0;
  v3 = 0;
  numfacets = 0;
  numvertices = 0;
  numridges = 0;
  totvneighbors = 0;
  totvertices = 0;
  waserror = 0;
  if ( qh_qh.IStracing >= 1 )
    fprintf(str: qh_qh.ferr, format: "qh_checkpolygon: check all facets from f%d\n", facetlist->id);
  v4 = facetlist;
  if ( facetlist != qh_qh.facet_list || qh_qh.ONLYgood != 0 )
    v2 = 1;
  if ( facetlist != nullptr )
  {
    for ( i = facetlist; i != nullptr; i = i->next )
    {
      if ( i->next == nullptr )
        break;
      if ( i == qh_qh.visible_list )
        v3 = 1;
      if ( (*((_DWORD *)i + 20) & 0x400) == 0 )
      {
        if ( v2 == 0 )
        {
          if ( i == qh_qh.facet_next )
          {
            v2 = 1;
          }
          else if ( qh_setsize(set: i->outsideset) != 0 && (qh_qh.NARROWhull == 0 || qh_qh.CHECKfrequently == 0) )
          {
            ivp_message(
              templat: "qhull internal error (qh_checkpolygon): f%d has outside set before qh facet_next\n",
              i->id);
            qh_errexit(exitcode: 5, facet: i, ridge: nullptr);
          }
        }
        ++numfacets;
        qh_checkfacet(facet: i, newmerge: 0, waserrorp: &waserror);
      }
    }
    v4 = facetlist;
    v1 = numfacets;
  }
  if ( qh_qh.visible_list == nullptr || v3 != 0 )
  {
    if ( v4 == qh_qh.facet_list )
    {
      vertex_list = qh_qh.vertex_list;
      goto LABEL_29;
    }
  }
  else if ( v4 == qh_qh.facet_list )
  {
    ivp_message(
      templat: "qhull internal error (qh_checkpolygon): visible list f%d no longer on facet list\n",
      qh_qh.visible_list->id);
    qh_printlists();
    qh_errexit(exitcode: 5, facet: qh_qh.visible_list, ridge: nullptr);
  }
  vertex_list = v4 != qh_qh.newfacet_list ? nullptr : qh_qh.newvertex_list;
LABEL_29:
  if ( vertex_list != nullptr )
  {
    while ( 1 )
    {
      next = vertex_list->next;
      if ( vertex_list->next == nullptr )
        break;
      *((_DWORD *)vertex_list + 5) &= ~0x1000000u;
      vertex_list->visitid = 0;
      vertex_list = next;
    }
    v4 = facetlist;
  }
  if ( v4 != nullptr )
  {
    for ( j = v4; j != nullptr; j = j->next )
    {
      if ( j->next == nullptr )
        break;
      v9 = *((_DWORD *)j + 20);
      if ( (v9 & 0x400) == 0 )
      {
        numridges += (v9 & 0x1000) != 0 ? qh_qh.hull_dim : qh_setsize(set: j->ridges);
        vertices = j->vertices;
        if ( vertices != nullptr )
        {
          p = vertices->e[0].p;
          e = vertices->e;
          if ( p != nullptr )
          {
            do
            {
              v13 = p[5];
              ++p[4];
              ++e;
              if ( (v13 & 0x1000000) == 0 )
              {
                ++numvertices;
                v18 = (long double *)p[2];
                p[5] = v13 | 0x1000000;
                if ( qh_pointid(point: v18) == -1 )
                {
                  ivp_message(
                    templat: "qhull internal error (qh_checkpolygon): unknown point %p for vertex v%d first_point %p\n",
                    (const void *)p[2],
                    p[5] & 0xFFFFFF,
                    qh_qh.first_point);
                  waserror = 1;
                }
              }
              p = (_DWORD *)e->i;
            }
            while ( e->i != 0 );
          }
        }
      }
    }
    v1 = numfacets;
    v4 = facetlist;
  }
  qh_qh.vertex_visit += v1;
  if ( v4 == qh_qh.facet_list )
  {
    if ( v1 != qh_qh.num_facets - qh_qh.num_visible )
    {
      ivp_message(
        templat: "qhull internal error (qh_checkpolygon): actual number of facets is %d, cumulative facet count is %d\n",
        v1,
        qh_qh.num_facets - qh_qh.num_visible);
      waserror = 1;
    }
    ++qh_qh.vertex_visit;
    if ( qh_qh.VERTEXneighbors != 0 )
    {
      for ( k = qh_qh.vertex_list; k != nullptr; k = k->next )
      {
        if ( k->next == nullptr )
          break;
        qh_setcheck(set: k->neighbors, tname: "neighbors for v", id: *((_DWORD *)k + 5) & 0xFFFFFF);
        if ( (*((_DWORD *)k + 5) & 0x8000000) == 0 )
          totvneighbors += qh_setsize(set: k->neighbors);
      }
      for ( m = facetlist; m != nullptr; totvertices += v16 )
      {
        if ( m->next == nullptr )
          break;
        v16 = qh_setsize(set: m->vertices);
        m = m->next;
      }
      if ( totvneighbors != totvertices )
      {
        ivp_message(
          templat: "qhull internal error (qh_checkpolygon): vertex neighbors inconsistent.  Totvneighbors %d, totvertices %d\n",
          totvneighbors,
          totvertices);
        waserror = 1;
      }
      v1 = numfacets;
    }
    if ( numvertices != qh_qh.num_vertices - qh_setsize(set: qh_qh.del_vertices) )
    {
      v17 = qh_setsize(set: qh_qh.del_vertices);
      ivp_message(
        templat: "qhull internal error (qh_checkpolygon): actual number of vertices is %d, cumulative vertex count is %d\n",
        numvertices,
        qh_qh.num_vertices - v17);
      waserror = 1;
    }
    if ( qh_qh.hull_dim == 2 )
    {
      if ( numvertices == v1 )
        goto LABEL_71;
      ivp_message(templat: "qhull internal error (qh_checkpolygon): #vertices %d != #facets %d\n", numvertices, v1);
      waserror = 1;
    }
    if ( qh_qh.hull_dim == 3 && v1 + numvertices - numridges / 2 != 2 )
    {
      ivp_message(
        templat: "qhull internal error (qh_checkpolygon): #vertices %d + #facets %d - #edges %d != 2\n",
        numvertices,
        v1,
        numridges / 2);
      goto LABEL_72;
    }
  }
LABEL_71:
  if ( waserror != 0 )
LABEL_72:
    qh_errexit(exitcode: 5, facet: nullptr, ridge: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10051450
// Name: void qh_createsimplex(struct setT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_createsimplex(setT *vertices)
{
  int v1; // edi
  setT *v2; // ebx
  facetT *v3; // esi
  vertexT *v4; // ecx
  facetT *newfacet_list; // eax
  facetT *v6; // esi
  int v7; // ecx
  setT *newfacets; // [esp+8h] [ebp-10h] BYREF
  vertexT *vertex; // [esp+Ch] [ebp-Ch]
  vertexT **e; // [esp+10h] [ebp-8h]
  unsigned int toporient; // [esp+14h] [ebp-4h]

  toporient = 1;
  newfacets = qh_settemp(setsize: qh_qh.hull_dim + 1);
  v1 = 0;
  qh_qh.facet_tail = qh_newfacet();
  qh_qh.newfacet_list = qh_qh.facet_tail;
  qh_qh.facet_list = qh_qh.facet_tail;
  qh_qh.num_vertices = 0;
  qh_qh.num_facets = 0;
  qh_qh.vertex_tail = qh_newvertex(point: nullptr);
  qh_qh.newvertex_list = qh_qh.vertex_tail;
  qh_qh.vertex_list = qh_qh.vertex_tail;
  if ( vertices != nullptr )
  {
    vertex = (vertexT *)vertices->e[0].p;
    v2 = (setT *)qh_setsize(set: vertices);
    if ( (int)v2 > 0 )
    {
      e = (vertexT **)vertices->e;
      do
      {
        v3 = qh_newfacet();
        v3->vertices = qh_setnew_delnthsorted(set: vertices, size: v2, nth: v1, prepend: 0);
        *((_DWORD *)v3 + 20) ^= (*((_DWORD *)v3 + 20) ^ (toporient << 11)) & 0x800;
        qh_appendfacet(facet: v3);
        v4 = vertex;
        *((_DWORD *)v3 + 20) |= 0x200u;
        qh_appendvertex(vertex: v4);
        qh_setappend(setp: &newfacets, newelem: v3);
        toporient ^= 1u;
        ++v1;
        vertex = *++e;
      }
      while ( v1 < (int)v2 );
    }
  }
  newfacet_list = qh_qh.newfacet_list;
  v6 = qh_qh.newfacet_list;
  if ( qh_qh.newfacet_list != nullptr )
  {
    while ( v6->next != nullptr )
    {
      if ( newfacet_list != nullptr )
      {
        v7 = 0;
        do
        {
          if ( newfacet_list->next == nullptr )
            break;
          if ( newfacet_list != v6 )
            v6->neighbors->e[v7++].i = (int)newfacet_list;
          newfacet_list = newfacet_list->next;
        }
        while ( newfacet_list != nullptr );
      }
      qh_settruncate(set: v6->neighbors, size: qh_qh.hull_dim);
      v6 = v6->next;
      if ( v6 == nullptr )
        break;
      newfacet_list = qh_qh.newfacet_list;
    }
  }
  qh_settempfree(set: &newfacets);
  if ( qh_qh.IStracing >= 1 )
    fprintf(str: qh_qh.ferr, format: "qh_createsimplex: created simplex\n");
}

//------------------------------------------------------------------------------
// Address: 0x100515C0
// Name: struct setT __near * qh_facet3vertex(struct facetT __near *)
// Source: json
//------------------------------------------------------------------------------
facetT *__cdecl qh_facet3vertex(setT *facet)
{
  facetT *v1; // esi
  int v2; // ebx
  int v3; // edi
  facetT *v4; // eax
  bool v5; // zf
  ridgeT *v7; // edi
  void *maxsize; // [esp-4h] [ebp-1Ch]
  ridgeT *firstridge; // [esp+Ch] [ebp-Ch]
  int cntvertices; // [esp+10h] [ebp-8h]
  vertexT *vertex; // [esp+14h] [ebp-4h] BYREF

  v1 = (facetT *)facet;
  v2 = 0;
  v3 = qh_setsize(set: (setT *)facet[6].e[0].p);
  cntvertices = v3;
  v4 = (facetT *)qh_settemp(setsize: v3);
  v5 = (*((_DWORD *)v1 + 20) & 0x1000) == 0;
  facet = (setT *)v4;
  if ( v5 )
  {
    firstridge = (ridgeT *)v1->ridges->e[0].p;
    v7 = qh_nextridge3d(atridge: firstridge, facet: v1, vertexp: &vertex);
    if ( v7 == nullptr )
      goto LABEL_14;
    while ( 1 )
    {
      qh_setappend(setp: &facet, newelem: vertex);
      if ( ++v2 > cntvertices || v7 == firstridge )
        break;
      v7 = qh_nextridge3d(atridge: v7, facet: v1, vertexp: &vertex);
      if ( v7 == nullptr )
        goto LABEL_14;
    }
    if ( v2 != cntvertices )
    {
LABEL_14:
      ivp_message(
        templat: "qhull internal error (qh_facet3vertex): ridges for facet %d don't match up.  got at least %d\n",
        v1->id,
        v2);
      qh_errexit(exitcode: 5, facet: v1, ridge: v7);
    }
    return (facetT *)facet;
  }
  else
  {
    if ( v3 != 3 )
    {
      ivp_message(
        templat: "qhull internal error (qh_facet3vertex): only %d vertices for simplicial facet f%d\n",
        v3,
        v1->id);
      qh_errexit(exitcode: 5, facet: v1, ridge: nullptr);
    }
    qh_setappend(setp: &facet, newelem: v1->vertices->e[0].p);
    maxsize = (void *)v1->vertices[1].maxsize;
    if ( (*((_DWORD *)v1 + 20) & 0x800) != 0 )
      qh_setappend(setp: &facet, newelem: maxsize);
    else
      qh_setaddnth(setp: &facet, nth: 0, newelem: maxsize);
    qh_setappend(setp: &facet, newelem: v1->vertices[1].e[0].p);
    return (facetT *)facet;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100516F0
// Name: int qh_findgood(struct facetT __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl qh_findgood(facetT *facetlist, int goodhorizon)
{
  facetT *v2; // edi
  int v3; // ebx
  facetT *i; // eax
  facetT *next; // esi
  facetT *j; // edi
  facetT *GOODclosest; // eax
  facetT *v8; // esi
  long double *normal; // eax
  facetT *v10; // ecx
  int result; // eax
  double dist; // [esp+14h] [ebp-1Ch] BYREF
  double angle; // [esp+1Ch] [ebp-14h] BYREF
  double bestangle; // [esp+24h] [ebp-Ch]
  facetT *bestfacet; // [esp+2Ch] [ebp-4h]

  v2 = facetlist;
  v3 = 0;
  bestfacet = nullptr;
  bestangle = 1.797693134862316e308;
  if ( facetlist != nullptr )
  {
    for ( i = facetlist; i->next != nullptr; i = i->next )
    {
      if ( (*((_DWORD *)i + 20) & 0x40000) != 0 )
        ++v3;
    }
  }
  if ( qh_qh.GOODvertex > 0 && qh_qh.MERGING == 0 && facetlist != nullptr )
  {
    while ( 1 )
    {
      next = v2->next;
      if ( next == nullptr )
        break;
      if ( qh_isvertex(point: qh_qh.GOODvertexp, vertices: v2->vertices) == nullptr )
      {
        *((_DWORD *)v2 + 20) &= ~0x40000u;
        --v3;
      }
      v2 = next;
    }
  }
  if ( qh_qh.GOODpoint != 0 && v3 != 0 )
  {
    for ( j = facetlist; j != nullptr; j = j->next )
    {
      if ( j->next == nullptr )
        break;
      if ( (*((_DWORD *)j + 20) & 0x40000) != 0 && j->normal != nullptr )
      {
        ++qh_qhstat.stats[50].i;
        qh_distplane(point: qh_qh.GOODpointp, facet: j, &dist);
        if ( dist > 0.0 != qh_qh.GOODpoint > 0 )
        {
          *((_DWORD *)j + 20) &= ~0x40000u;
          --v3;
        }
      }
    }
  }
  if ( qh_qh.GOODthreshold == 0 )
    goto LABEL_54;
  GOODclosest = qh_qh.GOODclosest;
  if ( v3 == 0 && goodhorizon == 0 && qh_qh.GOODclosest == nullptr )
    goto LABEL_54;
  v8 = facetlist;
  if ( facetlist != nullptr )
  {
    do
    {
      if ( v8->next == nullptr )
        break;
      if ( (*((_DWORD *)v8 + 20) & 0x40000) != 0 )
      {
        normal = v8->normal;
        if ( normal != nullptr && qh_inthresholds(normal, &angle) == 0 )
        {
          *((_DWORD *)v8 + 20) &= ~0x40000u;
          --v3;
          if ( bestangle > angle )
          {
            bestangle = angle;
            bestfacet = v8;
          }
        }
      }
      v8 = v8->next;
    }
    while ( v8 != nullptr );
    GOODclosest = qh_qh.GOODclosest;
  }
  if ( v3 != 0 )
  {
    if ( GOODclosest != nullptr )
    {
      *((_DWORD *)GOODclosest + 20) &= ~0x40000u;
      qh_qh.GOODclosest = nullptr;
    }
    goto LABEL_54;
  }
  if ( goodhorizon != 0 )
  {
    if ( GOODclosest == nullptr )
      goto LABEL_54;
  }
  else if ( GOODclosest == nullptr )
  {
    goto LABEL_45;
  }
  if ( (*((_DWORD *)GOODclosest + 20) & 0x400) != 0 )
  {
    GOODclosest = nullptr;
    qh_qh.GOODclosest = nullptr;
  }
  else
  {
    qh_inthresholds(normal: GOODclosest->normal, &angle);
    GOODclosest = qh_qh.GOODclosest;
    if ( bestangle > angle )
      bestfacet = qh_qh.GOODclosest;
  }
LABEL_45:
  v10 = bestfacet;
  if ( bestfacet != nullptr && bestfacet != GOODclosest )
  {
    if ( GOODclosest != nullptr )
      *((_DWORD *)GOODclosest + 20) &= ~0x40000u;
    qh_qh.GOODclosest = v10;
    *((_DWORD *)v10 + 20) |= 0x40000u;
    if ( qh_qh.IStracing >= 2 )
      fprintf(str: qh_qh.ferr, format: "qh_findgood: f%d is closest (%2.2g) to thresholds\n", v10->id, bestangle);
    return 1;
  }
LABEL_54:
  qh_qhstat.stats[81].i += v3;
  if ( qh_qh.IStracing >= 2 )
    fprintf(str: qh_qh.ferr, format: "qh_findgood: found %d good facets with %d good horizon\n", v3, goodhorizon);
  if ( v3 != 0 )
    return v3;
  if ( qh_qh.GOODvertex <= 0 )
    return v3;
  result = goodhorizon;
  if ( qh_qh.MERGING != 0 )
    return v3;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10051970
// Name: void qh_findgood_all(struct facetT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_findgood_all(facetT *facetlist)
{
  int GOODvertex; // edi
  facetT *v2; // ebx
  int v3; // esi
  facetT *v4; // edx
  facetT *i; // eax
  facetT *j; // edi
  facetT *next; // ebx
  int v8; // esi
  int v9; // edi
  facetT *k; // esi
  int v11; // eax
  unsigned int id; // [esp+4h] [ebp-28h]
  double angle; // [esp+14h] [ebp-18h] BYREF
  double bestangle; // [esp+1Ch] [ebp-10h]
  facetT *bestfacet; // [esp+24h] [ebp-8h]
  int numgood; // [esp+28h] [ebp-4h]

  GOODvertex = qh_qh.GOODvertex;
  v2 = nullptr;
  v3 = 0;
  bestfacet = nullptr;
  bestangle = 1.797693134862316e308;
  numgood = 0;
  if ( qh_qh.GOODvertex != 0 || qh_qh.GOODthreshold != 0 || qh_qh.GOODpoint != 0 || qh_qh.SPLITthresholds != 0 )
  {
    if ( qh_qh.ONLYgood == 0 )
    {
      qh_findgood(facetlist: qh_qh.facet_list, goodhorizon: 0);
      GOODvertex = qh_qh.GOODvertex;
    }
    v4 = facetlist;
    if ( facetlist != nullptr )
    {
      for ( i = facetlist; i->next != nullptr; i = i->next )
      {
        if ( (*((_DWORD *)i + 20) & 0x40000) != 0 )
          ++v3;
      }
      numgood = v3;
    }
    if ( (GOODvertex < 0 || GOODvertex > 0 && qh_qh.MERGING != 0) && facetlist != nullptr )
    {
      for ( j = facetlist; ; j = next )
      {
        next = j->next;
        if ( next == nullptr )
        {
          v2 = bestfacet;
          break;
        }
        v8 = *((_DWORD *)j + 20);
        if ( (v8 & 0x40000) != 0 )
        {
          if ( qh_qh.GOODvertex > 0 != (qh_isvertex(point: qh_qh.GOODvertexp, vertices: j->vertices) != nullptr) )
          {
            if ( --numgood == 0 )
            {
              id = j->id;
              v11 = qh_pointid(point: qh_qh.GOODvertexp);
              ivp_message(
                templat: "qhull warning: good vertex p%d does not match last good facet f%d.  Ignored.\n",
                v11,
                id);
              return;
            }
            *((_DWORD *)j + 20) = v8 & 0xFFFBFFFF;
          }
          v4 = facetlist;
        }
        v3 = numgood;
      }
    }
    v9 = v3;
    if ( qh_qh.SPLITthresholds == 0 )
      goto LABEL_42;
    if ( v4 != nullptr )
    {
      for ( k = v4; k != nullptr; k = k->next )
      {
        if ( k->next == nullptr )
          break;
        if ( (*((_DWORD *)k + 20) & 0x40000) != 0 && qh_inthresholds(normal: k->normal, &angle) == 0 )
        {
          *((_DWORD *)k + 20) &= ~0x40000u;
          --numgood;
          if ( bestangle > angle )
          {
            bestangle = angle;
            bestfacet = k;
          }
        }
      }
      v3 = numgood;
      v2 = bestfacet;
    }
    if ( v3 == 0 && v2 != nullptr )
    {
      *((_DWORD *)v2 + 20) |= 0x40000u;
      if ( qh_qh.IStracing != 0 )
        fprintf(str: qh_qh.ferr, format: "qh_findgood_all: f%d is closest (%2.2g) to thresholds\n", v2->id, bestangle);
    }
    else
    {
LABEL_42:
      qh_qh.num_good = v3;
      if ( qh_qh.IStracing != 0 )
        fprintf(str: qh_qh.ferr, format: "qh_findgood_all: %d good facets remain out of %d facets\n", v3, v9);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10051B70
// Name: void qh_furthestnext(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_furthestnext()
{
  facetT *facet_list; // eax
  double furthestdist; // xmm1_8
  facetT *v2; // esi

  facet_list = qh_qh.facet_list;
  furthestdist = -1.797693134862316e308;
  v2 = nullptr;
  if ( qh_qh.facet_list != nullptr )
  {
    while ( facet_list->next != nullptr )
    {
      if ( facet_list->outsideset != nullptr && facet_list->furthestdist > furthestdist )
      {
        v2 = facet_list;
        furthestdist = facet_list->furthestdist;
      }
      facet_list = facet_list->next;
    }
    if ( v2 != nullptr )
    {
      qh_removefacet(facet: v2);
      qh_prependfacet(facet: v2, facetlist: &qh_qh.facet_next);
      if ( qh_qh.IStracing >= 1 )
        fprintf(str: qh_qh.ferr, format: "qh_furthestnext: made f%d next facet (dist %.2g)\n", v2->id, furthestdist);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10051C10
// Name: void qh_initialhull(struct setT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_initialhull(setT *vertices)
{
  long double *v1; // eax
  facetT *facet_list; // esi
  facetT *v3; // eax
  facetT *next; // edx
  facetT *i; // esi
  facetT *v6; // esi
  facetT *j; // esi
  facetT *v8; // esi
  setT *neighbors; // eax
  setelemT *e; // edi
  setelemT v11; // eax
  int k; // esi
  double diff; // [esp+10h] [ebp-18h] BYREF
  double dist; // [esp+18h] [ebp-10h] BYREF
  double minangle; // [esp+20h] [ebp-8h]

  minangle = 1.797693134862316e308;
  qh_createsimplex(vertices);
  qh_resetlists(stats: 0);
  qh_qh.facet_next = qh_qh.facet_list;
  v1 = qh_getcenter(vertices);
  facet_list = qh_qh.facet_list;
  qh_qh.interior_point = v1;
  qh_setfacetplane(facet: qh_qh.facet_list);
  ++qh_qhstat.stats[138].i;
  qh_distplane(point: qh_qh.interior_point, facet: facet_list, &dist);
  if ( dist > 0.0 )
  {
    v3 = qh_qh.facet_list;
    if ( qh_qh.facet_list != nullptr )
    {
      while ( 1 )
      {
        next = v3->next;
        if ( next == nullptr )
          break;
        *((_DWORD *)v3 + 20) ^= ((unsigned __int16)*((_DWORD *)v3 + 20)
                               ^ (unsigned __int16)~(unsigned __int16)*((_DWORD *)v3 + 20))
                              & 0x800;
        v3 = next;
      }
    }
  }
  for ( i = qh_qh.facet_list; i != nullptr; i = i->next )
  {
    if ( i->next == nullptr )
      break;
    qh_setfacetplane(facet: i);
  }
  v6 = qh_qh.facet_list;
  if ( qh_qh.facet_list != nullptr )
  {
    while ( v6->next != nullptr )
    {
      if ( qh_checkflipped(facet: v6, distp: nullptr, allerror: 1u) == 0 )
      {
        if ( qh_qh.IStracing >= 1 )
          fprintf(str: qh_qh.ferr, format: "qh_initialhull: initial orientation incorrect.  Correct all facets\n");
        *((_DWORD *)v6 + 20) &= ~0x8000u;
        for ( j = qh_qh.facet_list; j != nullptr; j = j->next )
        {
          if ( j->next == nullptr )
            break;
          *((_DWORD *)j + 20) ^= ((unsigned __int16)*((_DWORD *)j + 20)
                                ^ (unsigned __int16)~(unsigned __int16)*((_DWORD *)j + 20))
                               & 0x800;
          qh_orientoutside(facet: j);
        }
        break;
      }
      v6 = v6->next;
      if ( v6 == nullptr )
        break;
    }
  }
  v8 = qh_qh.facet_list;
  if ( qh_qh.facet_list != nullptr )
  {
    do
    {
      if ( v8->next == nullptr )
        break;
      if ( qh_checkflipped(facet: v8, distp: nullptr, allerror: 0) == 0 )
      {
        qh_precision(reason: "initial facet is coplanar with interior point");
        if ( qh_qh.ferr != nullptr )
          ivp_message(templat: "qhull precision error: initial facet %d is coplanar with the interior point\n", v8->id);
        qh_errexit(exitcode: 2, facet: v8, ridge: nullptr);
      }
      neighbors = v8->neighbors;
      if ( neighbors != nullptr )
      {
        e = neighbors->e;
        v11.p = (void *)neighbors->e[0];
        if ( v11.i != 0 )
        {
          do
          {
            ++e;
            diff = qh_getangle(vect1: v8->normal, vect2: (long double *)*(_DWORD *)(v11.i + 24));
            if ( minangle > diff )
              minangle = diff;
            v11.p = e->p;
          }
          while ( e->i != 0 );
        }
      }
      v8 = v8->next;
    }
    while ( v8 != nullptr );
    if ( minangle < -0.98 )
    {
      diff = minangle + 1.0;
      qh_qh.NARROWhull = 1;
      qh_option(option: "_narrow-hull", i: nullptr, r: &diff);
      if ( minangle < -0.9999 && qh_qh.RERUN == 0 && qh_qh.PRINTprecision != 0 )
        ivp_message(
          templat: "qhull precision warning: \n"
          "The initial hull is narrow (the cosine of the minimum angle is %.9g).\n"
          "A coplanar point may lead to a wide facet.  Options 'Qs' (search for best\n"
          "initial hull), 'QbB' (scale to unit box), or 'Qbb' (scale last coordinate)\n"
          "may remove this warning.  Use 'Pp' to ignore this warning.\n"
          "See 'Limitations' in qh-impre.htm.\n",
          minangle);
    }
  }
  qh_qhstat.stats[151].i = qh_qh.hull_dim + 1;
  qh_checkpolygon(facetlist: qh_qh.facet_list);
  qh_checkconvex(facetlist: qh_qh.facet_list, fault: 1);
  if ( qh_qh.IStracing >= 1 )
  {
    ivp_message(templat: "qh_initialhull: simplex constructed, interior point:");
    for ( k = 0; k < qh_qh.hull_dim; ++k )
      ivp_message(templat: " %6.4g", (double)qh_qh.interior_point[k]);
    ivp_message(templat: "\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10051F10
// Name: struct setT __near * qh_initialvertices(int,struct setT __near *,double __near *,int)
// Source: json
//------------------------------------------------------------------------------
setT *__cdecl qh_initialvertices(int dim, setT *maxpoints, long double *points, int numpoints)
{
  int v4; // edi
  setT *v5; // eax
  int v6; // eax
  __m128d v7; // xmm2
  __m128d v8; // xmm0
  __m128d v9; // xmm3
  double v10; // xmm1_8
  long double v11; // xmm1_8
  int v12; // esi
  long double *v13; // eax
  long double *v14; // eax
  long double *v15; // eax
  setT *v16; // eax
  void *p; // edx
  int v18; // eax
  int v19; // eax
  long double *v20; // edi
  int v21; // esi
  int v22; // ebx
  long double *v23; // eax
  long double *v24; // edi
  int v25; // ebx
  long double *v26; // eax
  long double *v27; // edi
  long double *i; // eax
  setelemT *v29; // esi
  vertexT *v30; // eax
  int point_n; // [esp+Ch] [ebp-18h]
  setT *vertices; // [esp+10h] [ebp-14h] BYREF
  setelemT *e; // [esp+14h] [ebp-10h]
  setT *tested; // [esp+18h] [ebp-Ch] BYREF
  unsigned int nearzero; // [esp+1Ch] [ebp-8h] BYREF
  setT *simplex; // [esp+20h] [ebp-4h] BYREF

  v4 = dim + 1;
  nearzero = 0;
  vertices = qh_settemp(setsize: dim + 1);
  v5 = qh_settemp(setsize: dim + 1);
  simplex = v5;
  if ( qh_qh.ALLpoints != 0 )
  {
    qh_maxsimplex(dim, maxpoints: nullptr, points, numpoints, &simplex);
  }
  else if ( qh_qh.RANDOMoutside != 0 )
  {
    if ( qh_setsize(set: v5) != v4 )
    {
      do
      {
        v6 = qh_rand();
        v7.m128d_f64[0] = 4.503599627370496e15;
        v8 = (__m128d)COERCE_UNSIGNED_INT64((double)qh_qh.num_points);
        v8.m128d_f64[0] = v8.m128d_f64[0] * ((double)v6 * 4.656612875245797e-10);
        v9 = _mm_and_pd((__m128d)0x8000000000000000uLL, v8);
        v10 = _mm_cmplt_sd(_mm_xor_pd(v8, v9), v7).m128d_f64[0];
        v11 = v8.m128d_f64[0]
            + COERCE_DOUBLE(*(_QWORD *)&v10 & 0x4330000000000000LL | *(_QWORD *)&v9.m128d_f64[0])
            - COERCE_DOUBLE(*(_QWORD *)&v10 & 0x4330000000000000LL | *(_QWORD *)&v9.m128d_f64[0]);
        v12 = (int)(v11
                  - COERCE_DOUBLE(
                      *(_QWORD *)&_mm_cmpgt_sd((__m128d)COERCE_UNSIGNED_INT64(v11 - v8.m128d_f64[0]), v9).m128d_f64[0]
                    & 0x3FF0000000000000LL));
        v13 = qh_point(id: v12);
        if ( qh_setin(set: simplex, setelem: v13) != 0 )
        {
          do
          {
            v12 = v12 + 1 >= qh_qh.num_points ? 0 : v12 + 1;
            v14 = qh_point(id: v12);
          }
          while ( qh_setin(set: simplex, setelem: v14) != 0 );
        }
        v15 = qh_point(id: v12);
        qh_setappend(setp: &simplex, newelem: v15);
      }
      while ( qh_setsize(set: simplex) != v4 );
    }
  }
  else if ( qh_qh.hull_dim < 8 )
  {
    qh_maxsimplex(dim, maxpoints, points, numpoints, &simplex);
  }
  else
  {
    v16 = qh_settemp(setsize: v4);
    p = maxpoints->e[0].p;
    tested = v16;
    qh_setappend(setp: &simplex, newelem: p);
    qh_setappend(setp: &simplex, newelem: (void *)maxpoints[1].maxsize);
    v18 = dim;
    if ( dim >= 6 )
      v18 = 6;
    qh_maxsimplex(dim: v18, maxpoints, points, numpoints, &simplex);
    v19 = qh_setsize(set: simplex);
    v20 = (long double *)maxpoints->e[0].p;
    v21 = v19;
    v22 = 0;
    point_n = qh_setsize(set: maxpoints);
    if ( point_n > 0 )
    {
      e = maxpoints->e;
      do
      {
        if ( (v22 & 1) != 0 && qh_setin(set: simplex, setelem: v20) == 0 && qh_setin(set: tested, setelem: v20) == 0 )
        {
          qh_detsimplex(apex: v20, points: simplex, dim: v21, &nearzero);
          if ( nearzero != 0 )
          {
            qh_setappend(setp: &tested, newelem: v20);
          }
          else
          {
            qh_setappend(setp: &simplex, newelem: v20);
            if ( ++v21 == dim )
              goto LABEL_29;
          }
        }
        v20 = (long double *)e[1].p;
        ++v22;
        ++e;
      }
      while ( v22 < point_n );
    }
    while ( v21 != dim )
    {
      v23 = (long double *)qh_setdellast(set: maxpoints);
      v24 = v23;
      if ( v23 == nullptr )
        break;
      if ( qh_setin(set: simplex, setelem: v23) == 0 && qh_setin(set: tested, setelem: v24) == 0 )
      {
        qh_detsimplex(apex: v24, points: simplex, dim: v21, &nearzero);
        if ( nearzero != 0 )
        {
          qh_setappend(setp: &tested, newelem: v24);
        }
        else
        {
          qh_setappend(setp: &simplex, newelem: v24);
          ++v21;
        }
      }
    }
LABEL_29:
    v25 = 0;
    while ( v21 != dim )
    {
      v26 = qh_point(id: v25);
      v27 = v26;
      ++v25;
      if ( v26 == nullptr )
        break;
      if ( qh_setin(set: simplex, setelem: v26) == 0 && qh_setin(set: tested, setelem: v27) == 0 )
      {
        qh_detsimplex(apex: v27, points: simplex, dim: v21, &nearzero);
        if ( nearzero == 0 )
        {
          qh_setappend(setp: &simplex, newelem: v27);
          ++v21;
        }
      }
    }
    qh_settempfree(set: &tested);
    qh_maxsimplex(dim, maxpoints, points, numpoints, &simplex);
  }
  if ( simplex != nullptr )
  {
    i = (long double *)simplex->e[0].p;
    v29 = simplex->e;
    if ( i != nullptr )
    {
      do
      {
        ++v29;
        v30 = qh_newvertex(point: i);
        qh_setaddnth(setp: &vertices, nth: 0, newelem: v30);
        i = (long double *)v29->i;
      }
      while ( v29->i != 0 );
    }
  }
  qh_settempfree(set: &simplex);
  return vertices;
}

//------------------------------------------------------------------------------
// Address: 0x100522D0
// Name: struct vertexT __near * qh_makenewfacets(double __near *)
// Source: json
//------------------------------------------------------------------------------
vertexT *__cdecl qh_makenewfacets(long double *point)
{
  facetT *v1; // ebx
  vertexT *v2; // edi
  facetT *i; // esi
  setT *neighbors; // eax
  setelemT *e; // ecx
  setelemT v6; // eax
  int v7; // eax
  facetT *newfacet2; // [esp+Ch] [ebp-8h]
  int numnew; // [esp+10h] [ebp-4h] BYREF

  v1 = nullptr;
  newfacet2 = nullptr;
  numnew = 0;
  qh_qh.newfacet_list = qh_qh.facet_tail;
  qh_qh.newvertex_list = qh_qh.vertex_tail;
  v2 = qh_newvertex(point);
  qh_appendvertex(vertex: v2);
  ++qh_qh.visit_id;
  if ( qh_qh.ONLYgood == 0 )
    qh_qh.NEWfacets = 1;
  for ( i = qh_qh.visible_list; i != nullptr; i = i->next )
  {
    if ( (*((_DWORD *)i + 20) & 0x400) == 0 )
      break;
    neighbors = i->neighbors;
    if ( neighbors != nullptr )
    {
      e = neighbors->e;
      for ( v6.p = (void *)neighbors->e[0]; v6.i != 0; ++e )
      {
        *(_DWORD *)(v6.i + 80) &= ~0x2000u;
        v6.p = e[1].p;
      }
    }
    if ( i->ridges != nullptr )
    {
      i->visitid = qh_qh.visit_id;
      newfacet2 = qh_makenew_nonsimplicial(visible: i, apex: v2, &numnew);
    }
    if ( (*((_DWORD *)i + 20) & 0x1000) != 0 )
      v1 = qh_makenew_simplicial(visible: i, apex: v2, &numnew);
    if ( qh_qh.ONLYgood == 0 )
    {
      if ( newfacet2 != nullptr )
        v1 = newfacet2;
      if ( v1 != nullptr )
        i->f.replace = v1;
      else
        ++qh_qhstat.stats[86].i;
      i->neighbors->e[0].i = 0;
    }
  }
  if ( qh_qh.IStracing >= 1 )
  {
    v7 = qh_pointid(point);
    fprintf(str: qh_qh.ferr, format: "qh_makenewfacets: created %d new facets from point p%d to horizon\n", numnew, v7);
  }
  if ( qh_qh.IStracing >= 4 )
    qh_printfacetlist(facetlist: qh_qh.newfacet_list, facets: nullptr, printall: 1u);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10052420
// Name: void qh_vertexintersect(struct setT __near * __near *,struct setT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_vertexintersect(setT **vertexsetA, setT *vertexsetB)
{
  setT *v2; // edi

  v2 = qh_vertexintersect_new(vertexsetA: *vertexsetA, vertexsetB);
  qh_settempfree(set: vertexsetA);
  *vertexsetA = v2;
  qh_settemppush(set: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10052450
// Name: void qh_initbuild(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_initbuild()
{
  long double *v0; // eax
  int GOODvertex; // eax
  long double *v2; // eax
  int hull_dim; // ecx
  int v4; // eax
  int IStracing; // eax
  long double *GOODvertexp; // esi
  facetT *v7; // esi
  int v8; // eax
  long double dist; // [esp+20h] [ebp-18h] BYREF
  unsigned int isoutside; // [esp+28h] [ebp-10h] BYREF
  int numpart; // [esp+2Ch] [ebp-Ch] BYREF
  setT *maxpoints; // [esp+30h] [ebp-8h] BYREF
  setT *vertices; // [esp+34h] [ebp-4h] BYREF

  qh_qh.furthest_id = -1;
  qh_qh.lastreport = 0;
  qh_qh.ridge_id = 0;
  qh_qh.vertex_id = 0;
  qh_qh.facet_id = 0;
  qh_qh.vertex_visit = 0;
  qh_qh.visit_id = 0;
  qh_qh.maxoutdone = 0;
  if ( qh_qh.GOODpoint <= 0 )
  {
    if ( qh_qh.GOODpoint >= 0 )
      goto LABEL_6;
    v0 = qh_point(id: -1 - qh_qh.GOODpoint);
  }
  else
  {
    v0 = qh_point(id: qh_qh.GOODpoint - 1);
  }
  qh_qh.GOODpointp = v0;
LABEL_6:
  GOODvertex = qh_qh.GOODvertex;
  if ( qh_qh.GOODvertex <= 0 )
  {
    if ( qh_qh.GOODvertex >= 0 )
      goto LABEL_11;
    v2 = qh_point(id: -1 - qh_qh.GOODvertex);
  }
  else
  {
    v2 = qh_point(id: qh_qh.GOODvertex - 1);
  }
  qh_qh.GOODvertexp = v2;
  GOODvertex = qh_qh.GOODvertex;
LABEL_11:
  if ( qh_qh.GOODpoint != 0 )
  {
    if ( qh_qh.GOODpointp < qh_qh.first_point || qh_qh.GOODpointp > qh_point(id: qh_qh.num_points - 1) )
    {
LABEL_18:
      ivp_message(templat: "qhull input error: either QGn or QVn point is > p%d\n", qh_qh.num_points - 1);
      qh_errexit(exitcode: 1, facet: nullptr, ridge: nullptr);
    }
    GOODvertex = qh_qh.GOODvertex;
  }
  if ( GOODvertex != 0
    && (qh_qh.GOODvertexp < qh_qh.first_point || qh_qh.GOODvertexp > qh_point(id: qh_qh.num_points - 1)) )
  {
    goto LABEL_18;
  }
  maxpoints = qh_maxmin(points: qh_qh.first_point, numpoints: qh_qh.num_points, dimension: qh_qh.hull_dim);
  if ( qh_qh.SCALElast != 0 )
    qh_scalelast(
      points: qh_qh.first_point,
      numpoints: qh_qh.num_points,
      dim: qh_qh.hull_dim,
      low: qh_qh.MINlastcoord,
      high: qh_qh.MAXlastcoord,
      newhigh: qh_qh.MAXwidth);
  qh_detroundoff();
  if ( qh_qh.DELAUNAY == 0 )
  {
LABEL_40:
    hull_dim = qh_qh.hull_dim;
    goto LABEL_34;
  }
  hull_dim = qh_qh.hull_dim;
  if ( qh_qh.upper_threshold[qh_qh.hull_dim - 1] > 8.988465674311579e307
    && qh_qh.lower_threshold[qh_qh.hull_dim - 1] < -8.988465674311579e307 )
  {
    v4 = 28;
    while ( qh_qh.PRINTout[--v4] != qh_PRINTgeom
         || qh_qh.DROPdim >= 0
         || qh_qh.GOODthreshold != 0
         || qh_qh.SPLITthresholds != 0 )
    {
      if ( v4 == 0 )
        goto LABEL_32;
    }
    if ( v4 >= 0 )
      goto LABEL_34;
LABEL_32:
    if ( qh_qh.UPPERdelaunay != 0 )
    {
      qh_qh.lower_threshold[qh_qh.hull_dim - 1] = qh_qh.ANGLEround * 2.0;
      hull_dim = qh_qh.hull_dim;
      qh_qh.GOODthreshold = 1;
      goto LABEL_34;
    }
    qh_qh.upper_threshold[qh_qh.hull_dim - 1] = qh_qh.ANGLEround * -2.0;
    if ( qh_qh.GOODthreshold == 0 )
      qh_qh.SPLITthresholds = 1;
    goto LABEL_40;
  }
LABEL_34:
  vertices = qh_initialvertices(dim: hull_dim, maxpoints, points: qh_qh.first_point, numpoints: qh_qh.num_points);
  qh_initialhull(vertices);
  qh_partitionall(vertices, points: qh_qh.first_point, numpoints: qh_qh.num_points);
  if ( qh_qh.PRINToptions1st == 0 )
  {
    if ( qh_qh.TRACElevel == 0 )
    {
      IStracing = qh_qh.IStracing;
      if ( qh_qh.IStracing == 0 )
        goto LABEL_48;
      goto LABEL_46;
    }
    goto LABEL_44;
  }
  if ( qh_qh.TRACElevel != 0 )
  {
LABEL_44:
    IStracing = qh_qh.IStracing;
    if ( qh_qh.IStracing == 0 )
      IStracing = qh_qh.TRACElevel;
    goto LABEL_46;
  }
  IStracing = qh_qh.IStracing;
  if ( qh_qh.IStracing != 0 )
LABEL_46:
    ivp_message(templat: "\nTrace level %d for %s | %s\n", IStracing, qh_qh.rbox_command, qh_qh.qhull_command);
  ivp_message(templat: "Options selected for qhull %s:\n%s\n", qh_version, qh_qh.qhull_options);
LABEL_48:
  qh_resetlists(stats: 0);
  qh_qh.facet_next = qh_qh.facet_list;
  qh_furthestnext();
  if ( qh_qh.PREmerge != 0 )
  {
    qh_qh.cos_max = qh_qh.premerge_cos;
    qh_qh.centrum_radius = qh_qh.premerge_centrum;
  }
  if ( qh_qh.ONLYgood != 0 )
  {
    if ( qh_qh.GOODvertex > 0 && qh_qh.MERGING != 0 )
    {
      ivp_message(
        templat: "qhull input error: 'Qg QVn' (only good vertex) does not work with merging.\n"
        "Use 'QJ' to joggle the input or 'Q0' to turn off merging.\n");
      qh_errexit(exitcode: 1, facet: nullptr, ridge: nullptr);
    }
    if ( qh_qh.GOODthreshold == 0
      && qh_qh.GOODpoint == 0
      && (qh_qh.MERGEexact != 0 || qh_qh.PREmerge != 0 || qh_qh.GOODvertexp == nullptr) )
    {
      ivp_message(
        templat: "qhull input error: 'Qg' (ONLYgood) needs a good threshold ('Pd0D0'), a\n"
        "good point (QGn or QG-n), or a good vertex with 'QJ' or 'Q0' (QVn).\n");
      qh_errexit(exitcode: 1, facet: nullptr, ridge: nullptr);
    }
    if ( qh_qh.GOODvertex > 0 && qh_qh.MERGING == 0 )
    {
      GOODvertexp = qh_qh.GOODvertexp;
      if ( qh_isvertex(point: qh_qh.GOODvertexp, vertices) == nullptr )
      {
        v7 = qh_findbestnew(point: GOODvertexp, startfacet: qh_qh.facet_list, &dist, &isoutside, &numpart);
        qh_qhstat.stats[50].i += numpart;
        if ( isoutside == 0 )
        {
          v8 = qh_pointid(point: qh_qh.GOODvertexp);
          ivp_message(
            templat: "qhull input error: point for QV%d is inside initial simplex.  It can not be made a vertex.\n",
            v8);
          qh_errexit(exitcode: 1, facet: nullptr, ridge: nullptr);
        }
        if ( qh_addpoint(furthest: qh_qh.GOODvertexp, facet: v7, checkdist: 0) == 0 )
        {
          qh_settempfree(set: &vertices);
          qh_settempfree(set: &maxpoints);
          return;
        }
      }
    }
    qh_findgood(facetlist: qh_qh.facet_list, goodhorizon: 0);
  }
  qh_settempfree(set: &vertices);
  qh_settempfree(set: &maxpoints);
  if ( qh_qh.IStracing >= 1 )
    fprintf(str: qh_qh.ferr, format: "qh_initbuild: initial hull created and points partitioned\n");
}
