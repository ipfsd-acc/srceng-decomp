// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_compact_builder/qhull.cxx
// Functions: 14
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1005EA00
// Name: void qh_buildtracing(double __near *,struct facetT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_buildtracing(long double *furthest, facetT *facet)
{
  tm *v2; // eax
  int v3; // ebx
  tm *v4; // edi
  int v5; // esi
  unsigned int id; // ebx
  unsigned int v7; // esi
  facetT *facet_list; // eax
  facetT *next; // ecx
  vertexT *vertex_list; // eax
  vertexT *v11; // ecx
  __int64 timedata; // [esp+3Ch] [ebp-18h] BYREF
  double dist; // [esp+44h] [ebp-10h] BYREF
  int furthestid; // [esp+4Ch] [ebp-8h]
  float cpu; // [esp+50h] [ebp-4h]

  dist = 0.0;
  qh_qh.old_randomdist = qh_qh.RANDOMdist;
  qh_qh.RANDOMdist = 0;
  if ( furthest != nullptr )
  {
    v3 = qh_pointid(point: furthest);
    furthestid = v3;
    if ( qh_qh.TRACEpoint == v3 )
    {
      qh_qh.IStracing = qh_qh.TRACElevel;
      qhmem.IStracing = qh_qh.TRACElevel;
    }
    if ( qh_qh.REPORTfreq != 0 && qh_qh.facet_id - 1 > qh_qh.REPORTfreq + qh_qh.lastreport )
    {
      qh_qh.lastreport = qh_qh.facet_id - 1;
      _time64(timeptr: &timedata);
      v4 = _localtime64(ptime: &timedata);
      cpu = (float)(1 - qh_qh.hulltime);
      v5 = qh_qhstat.stats[176].i + qh_qhstat.stats[36].i - qh_qhstat.stats[37].i;
      ++qh_qhstat.stats[51].i;
      qh_distplane(point: furthest, facet, &dist);
      if ( facet != nullptr )
        id = facet->id;
      else
        id = -1;
      ivp_message(
        templat: "\n"
        "At %02d:%02d:%02d & %2.5g CPU secs, qhull has created %d facets and merged %d.\n"
        " The current hull contains %d facets and %d vertices.  There are %d\n"
        " outside points.  Next is point p%d (v%d), %2.2g above f%d.\n",
        v4->tm_hour,
        v4->tm_min,
        v4->tm_sec,
        cpu,
        qh_qh.facet_id - 1,
        v5,
        qh_qh.num_facets,
        qh_qh.num_vertices,
        (_DWORD)((unsigned __int64)(*(_QWORD *)&qh_qh.num_vertices + 0x100000000LL) >> 32),
        furthestid,
        qh_qh.vertex_id,
        dist,
        id);
      v3 = furthestid;
    }
    else if ( qh_qh.IStracing >= 1 )
    {
      cpu = (float)(1 - qh_qh.hulltime);
      qh_distplane(point: furthest, facet, &dist);
      if ( facet != nullptr )
        v7 = facet->id;
      else
        v7 = -1;
      ivp_message(
        templat: "qh_addpoint: add p%d (v%d) to hull of %d facets (%2.2g above f%d) and %d outside at %4.4g CPU secs.  Previous was p%d.\n",
        v3,
        qh_qh.vertex_id,
        qh_qh.num_facets,
        dist,
        v7,
        qh_qh.num_outside + 1,
        cpu,
        qh_qh.furthest_id);
    }
    if ( qh_qh.visit_id > 0x7FFFFFFF )
    {
      facet_list = qh_qh.facet_list;
      qh_qh.visit_id = 0;
      if ( qh_qh.facet_list != nullptr )
      {
        while ( 1 )
        {
          next = facet_list->next;
          if ( next == nullptr )
            break;
          facet_list->visitid = qh_qh.visit_id;
          facet_list = next;
        }
      }
    }
    if ( qh_qh.vertex_visit > 0x7FFFFFFF )
    {
      vertex_list = qh_qh.vertex_list;
      qh_qh.vertex_visit = 0;
      if ( qh_qh.vertex_list != nullptr )
      {
        while ( 1 )
        {
          v11 = vertex_list->next;
          if ( vertex_list->next == nullptr )
            break;
          vertex_list->visitid = qh_qh.vertex_visit;
          vertex_list = v11;
        }
      }
    }
    qh_qh.furthest_id = v3;
    qh_qh.RANDOMdist = qh_qh.old_randomdist;
  }
  else
  {
    _time64(timeptr: &timedata);
    v2 = _localtime64(ptime: &timedata);
    ivp_message(
      templat: "\n"
      "At %02d:%02d:%02d & %2.5g CPU secs, qhull has created %d facets and merged %d.\n"
      " The current hull contains %d facets and %d vertices.  Last point was p%d\n",
      v2->tm_hour,
      v2->tm_min,
      v2->tm_sec,
      (double)(1 - qh_qh.hulltime),
      qh_qh.facet_id - 1,
      qh_qhstat.stats[176].i + qh_qhstat.stats[36].i - qh_qhstat.stats[37].i,
      qh_qh.num_facets,
      qh_qh.num_vertices,
      qh_qh.furthest_id);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005ECE0
// Name: void qh_errexit2(int,struct facetT __near *,struct facetT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn qh_errexit2(int exitcode, facetT *facet, facetT *otherfacet)
{
  qh_errprint(string: "ERRONEOUS", atfacet: facet, otherfacet, atridge: nullptr, atvertex: nullptr);
  qh_errexit(exitcode, facet: nullptr, ridge: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1005ED10
// Name: double __near * qh_nextfurthest(struct facetT __near * __near *)
// Source: json
//------------------------------------------------------------------------------
long double *__cdecl qh_nextfurthest(facetT **visible)
{
  facetT *facet_next; // esi
  setT *outsideset; // ecx
  setelemT v3; // eax
  int maxsize; // eax
  facetT *previous; // esi
  long double *result; // eax
  int v7; // edi
  facetT *i; // esi
  int v9; // eax
  __m128d v10; // xmm2
  facetT *v11; // esi
  double v12; // xmm4_8
  __m128d v13; // xmm0
  __m128d v14; // xmm3
  double v15; // xmm1_8
  long double v16; // xmm1_8
  int v17; // edi
  setT *v18; // edx
  setelemT v19; // eax
  int v20; // eax
  double randr; // [esp+14h] [ebp-8h]

  facet_next = qh_qh.facet_next;
  if ( qh_qh.facet_next == qh_qh.facet_tail )
    return nullptr;
  while ( 1 )
  {
    outsideset = facet_next->outsideset;
    if ( outsideset == nullptr )
    {
      qh_qh.facet_next = facet_next->next;
      goto LABEL_20;
    }
    v3.p = (void *)outsideset->e[outsideset->maxsize];
    if ( v3.i != 0 )
      maxsize = v3.i - 1;
    else
      maxsize = outsideset->maxsize;
    if ( maxsize == 0 )
    {
      qh_setfree(setp: &facet_next->outsideset);
      qh_qh.facet_next = facet_next->next;
      goto LABEL_20;
    }
    if ( qh_qh.NARROWhull != 0 )
    {
      if ( (*((_DWORD *)facet_next + 20) & 0x20000) != 0 )
        qh_furthestout(facet: facet_next);
      qh_setlast(set: facet_next->outsideset);
      if ( qh_qh.MINoutside > facet_next->furthestdist )
      {
        qh_qh.facet_next = facet_next->next;
        goto LABEL_20;
      }
    }
    if ( qh_qh.RANDOMoutside != 0 )
    {
      v7 = 0;
      if ( qh_qh.NARROWhull != 0 )
      {
        for ( i = qh_qh.facet_list; i != nullptr; i = i->next )
        {
          if ( i->next == nullptr || i == qh_qh.facet_next )
            break;
          if ( i->outsideset != nullptr )
            v7 += qh_setsize(set: i->outsideset);
        }
      }
      v9 = qh_rand();
      v10.m128d_f64[0] = 4.503599627370496e15;
      v11 = qh_qh.facet_next;
      v12 = (double)v9 * 4.656612875245797e-10;
      v13 = 0;
      v13.m128d_f64[0] = (double)(qh_qh.num_outside - v7) * v12;
      v14 = _mm_and_pd((__m128d)0x8000000000000000uLL, v13);
      v15 = _mm_cmplt_sd(_mm_xor_pd(v13, v14), v10).m128d_f64[0];
      v16 = v13.m128d_f64[0]
          + COERCE_DOUBLE(*(_QWORD *)&v15 & 0x4330000000000000LL | *(_QWORD *)&v14.m128d_f64[0])
          - COERCE_DOUBLE(*(_QWORD *)&v15 & 0x4330000000000000LL | *(_QWORD *)&v14.m128d_f64[0]);
      randr = v12;
      v17 = (int)(v16
                - COERCE_DOUBLE(
                    *(_QWORD *)&_mm_cmpgt_sd((__m128d)COERCE_UNSIGNED_INT64(v16 - v13.m128d_f64[0]), v14).m128d_f64[0]
                  & 0x3FF0000000000000LL));
      if ( qh_qh.facet_next == nullptr )
      {
LABEL_40:
        ivp_message(
          templat: "qhull internal error (qh_nextfurthest): num_outside %d is too low\n"
          "by at least %d, or a random real %g >= 1.0\n",
          qh_qh.num_outside,
          v17 + 1,
          v12);
        qh_errexit(exitcode: 5, facet: nullptr, ridge: nullptr);
      }
      while ( 1 )
      {
        if ( v11->next == nullptr )
          goto LABEL_40;
        v18 = v11->outsideset;
        if ( v18 != nullptr )
        {
          v19.p = (void *)v18->e[v18->maxsize];
          if ( v19.i != 0 )
            v20 = v19.i - 1;
          else
            v20 = v18->maxsize;
          if ( v20 != 0 )
          {
            if ( v20 > v17 )
            {
              *visible = v11;
              return (long double *)qh_setdelnth(set: v11->outsideset, nth: v17);
            }
            v17 -= v20;
          }
          else
          {
            qh_setfree(setp: &v11->outsideset);
            v12 = randr;
          }
        }
        v11 = v11->next;
        if ( v11 == nullptr )
          goto LABEL_40;
      }
    }
    if ( qh_qh.VIRTUALmemory == 0 )
      break;
    previous = qh_qh.facet_tail->previous;
    result = (long double *)qh_setdellast(set: previous->outsideset);
    if ( result != nullptr )
    {
      *visible = previous;
      return result;
    }
    if ( previous->outsideset != nullptr )
      qh_setfree(setp: &previous->outsideset);
    qh_removefacet(facet: previous);
    qh_prependfacet(facet: previous, facetlist: &qh_qh.facet_list);
LABEL_20:
    facet_next = qh_qh.facet_next;
    if ( qh_qh.facet_next == qh_qh.facet_tail )
      return nullptr;
  }
  if ( qh_qh.PICKfurthest != 0 )
  {
    qh_furthestnext();
    facet_next = qh_qh.facet_next;
  }
  *visible = facet_next;
  return (long double *)qh_setdellast(set: facet_next->outsideset);
}

//------------------------------------------------------------------------------
// Address: 0x1005EFC0
// Name: void qh_partitioncoplanar(double __near *,struct facetT __near *,double __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_partitioncoplanar(long double *point, facetT *facet, long double *dist)
{
  facetT *v3; // eax
  double v4; // xmm0_8
  facetT *v5; // esi
  double v6; // xmm1_8
  long double *v7; // eax
  int v8; // eax
  int v9; // eax
  unsigned int v10; // [esp+4h] [ebp-2Ch]
  unsigned int id; // [esp+8h] [ebp-28h]
  int furthest_id; // [esp+Ch] [ebp-24h]
  double dist2; // [esp+1Ch] [ebp-14h] BYREF
  double bestdist; // [esp+24h] [ebp-Ch] BYREF
  int numpart; // [esp+2Ch] [ebp-4h] BYREF

  numpart = 0;
  qh_qh.WAScoplanar = 1;
  if ( dist != nullptr )
  {
    v4 = *dist;
    v5 = facet;
    bestdist = *dist;
  }
  else
  {
    if ( qh_qh.findbestnew != 0 )
      v3 = qh_findbestnew(point, startfacet: facet, dist: &bestdist, isoutside: nullptr, &numpart);
    else
      v3 = qh_findbest(
             point,
             startfacet: facet,
             bestoutside: 1u,
             newfacets: 0,
             noupper: 0,
             dist: &bestdist,
             isoutside: (unsigned int *)&dist,
             &numpart);
    ++qh_qhstat.stats[177].i;
    qh_qhstat.stats[141].i += numpart;
    v4 = bestdist;
    v5 = v3;
    if ( qh_qh.KEEPinside == 0 )
    {
      v6 = qh_qh.KEEPnearinside != 0 ? qh_qh.NEARinside : qh_qh.MAXcoplanar;
      if ( -v6 > bestdist )
      {
        ++qh_qhstat.stats[31].i;
        return;
      }
    }
  }
  if ( qh_qh.KEEPinside + qh_qh.KEEPnearinside + qh_qh.KEEPcoplanar != 0 )
  {
    v7 = (long double *)qh_setlast(set: v5->coplanarset);
    if ( v7 != nullptr )
    {
      ++qh_qhstat.stats[19].i;
      qh_distplane(point: v7, facet: v5, dist: &dist2);
      if ( bestdist <= dist2 )
      {
        qh_setappend2ndlast(setp: &v5->coplanarset, newelem: point);
        goto LABEL_20;
      }
    }
    qh_setappend(setp: &v5->coplanarset, newelem: point);
    v4 = bestdist;
  }
  if ( v4 > qh_qh.max_outside )
  {
    qh_qh.max_outside = v4;
    if ( v4 <= qh_qh.TRACEdist )
      goto LABEL_21;
    furthest_id = qh_qh.furthest_id;
    id = v5->id;
    v8 = qh_pointid(point);
    ivp_message(
      templat: "qh_partitioncoplanar: ====== p%d increases max_outside to %2.2g of f%d last p%d\n",
      v8,
      v4,
      id,
      furthest_id);
    qh_errprint(string: "DISTANT", atfacet: v5, otherfacet: nullptr, atridge: nullptr, atvertex: nullptr);
LABEL_20:
    v4 = bestdist;
  }
LABEL_21:
  if ( qh_qh.IStracing >= 4 )
  {
    v10 = v5->id;
    v9 = qh_pointid(point);
    fprintf(
      str: qh_qh.ferr,
      format: "qh_partitioncoplanar: point p%d is coplanar with facet f%d (or inside) dist %2.2g\n",
      v9,
      v10,
      v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005F180
// Name: void qh_precision(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_precision(const char *reason)
{
  if ( qh_qh.ALLOWrestart != 0
    && qh_qh.PREmerge == 0
    && qh_qh.MERGEexact == 0
    && qh_qh.JOGGLEmax < 8.988465674311579e307 )
  {
    if ( qh_qh.IStracing != 0 )
      fprintf(str: qh_qh.ferr, format: "qh_precision: qhull restart because of %s\n", reason);
    longjmp(Buf: qh_qh.restartexit, Value: 3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005F1E0
// Name: void qh_printsummary(struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_printsummary(_iobuf *fp)
{
  int v2; // ebx
  int v3; // eax
  facetT *facet_list; // edi
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  double DISTround; // xmm0_8
  const char *v12; // eax
  const char *v13; // eax
  double v14; // xmm0_8
  double innerplane; // [esp+Ch] [ebp-18h] BYREF
  long double outerplane; // [esp+14h] [ebp-10h] BYREF
  int id; // [esp+1Ch] [ebp-8h]
  int numcoplanars; // [esp+20h] [ebp-4h]
  int numvertices; // [esp+2Ch] [ebp+8h]

  numcoplanars = 0;
  if ( fp != nullptr )
  {
    v2 = qh_qh.num_points + qh_setsize(set: qh_qh.other_points);
    numvertices = qh_qh.num_vertices - qh_setsize(set: qh_qh.del_vertices);
    v3 = qh_pointid(point: qh_qh.GOODpointp);
    facet_list = qh_qh.facet_list;
    for ( id = v3; facet_list != nullptr; facet_list = facet_list->next )
    {
      if ( facet_list->next == nullptr )
        break;
      if ( facet_list->coplanarset != nullptr )
        numcoplanars += qh_setsize(set: facet_list->coplanarset);
    }
    if ( id >= 0 && qh_qh.STOPcone - 1 != id && -1 - qh_qh.STOPpoint != id )
      --v2;
    if ( qh_qh.STOPcone != 0 || qh_qh.STOPpoint != 0 )
      fprintf(str: fp, format: "\nAt a premature exit due to 'TVn', 'TCn', or precision error.");
    if ( qh_qh.VORONOI != 0 )
    {
      if ( qh_qh.UPPERdelaunay != 0 )
        fprintf(
          str: fp,
          format: "\nFurthest-site Voronoi vertices by the convex hull of %d points in %d-d:\n\n",
          v2,
          qh_qh.hull_dim);
      else
        fprintf(str: fp, format: "\nVoronoi diagram by the convex hull of %d points in %d-d:\n\n", v2, qh_qh.hull_dim);
      v5 = " and at-infinity";
      if ( qh_qh.ATinfinity == 0 )
        v5 = str;
      fprintf(str: fp, format: "  Number of Voronoi regions%s: %d\n", v5, numvertices);
      if ( numcoplanars != 0 )
      {
        fprintf(str: fp, format: "  Number of nearly incident points: %d\n", numcoplanars);
      }
      else if ( v2 > numvertices )
      {
        fprintf(str: fp, format: "  Total number of nearly incident points: %d\n", v2 - numvertices);
      }
      fprintf(str: fp, format: "  Number of Voronoi vertices: %d\n", qh_qh.num_good);
      fprintf(str: fp, format: "  Number of facets in hull: %d\n", qh_qh.num_facets - qh_qh.num_visible);
    }
    else if ( qh_qh.DELAUNAY != 0 )
    {
      if ( qh_qh.UPPERdelaunay != 0 )
        fprintf(
          str: fp,
          format: "\nFurthest-site Delaunay triangulation by the convex hull of %d points in %d-d:\n\n",
          v2,
          qh_qh.hull_dim);
      else
        fprintf(
          str: fp,
          format: "\nDelaunay triangulation by the convex hull of %d points in %d-d:\n\n",
          v2,
          qh_qh.hull_dim);
      v6 = " and at-infinity";
      if ( qh_qh.ATinfinity == 0 )
        v6 = str;
      fprintf(str: fp, format: "  Number of input sites%s: %d\n", v6, numvertices);
      if ( numcoplanars != 0 )
      {
        fprintf(str: fp, format: "  Number of nearly incident points: %d\n", numcoplanars);
      }
      else if ( v2 > numvertices )
      {
        fprintf(str: fp, format: "  Total number of nearly incident points: %d\n", v2 - numvertices);
      }
      fprintf(str: fp, format: "  Number of Delaunay facets: %d\n", qh_qh.num_good);
      fprintf(str: fp, format: "  Number of facets in hull: %d\n", qh_qh.num_facets - qh_qh.num_visible);
    }
    else if ( qh_qh.HALFspace != 0 )
    {
      fprintf(
        str: fp,
        format: "\nHalfspace intersection by the convex hull of %d points in %d-d:\n\n",
        v2,
        qh_qh.hull_dim);
      fprintf(str: fp, format: "  Number of nonredundant halfspaces: %d\n", numvertices);
      if ( numcoplanars != 0 )
      {
        if ( qh_qh.KEEPinside != 0 )
        {
          if ( qh_qh.KEEPcoplanar != 0 )
            v7 = "similar and redundant";
          else
            v7 = "redundant";
        }
        else
        {
          v7 = "similar";
        }
        fprintf(str: fp, format: "  Number of %s halfspaces: %d\n", v7, numcoplanars);
      }
      fprintf(str: fp, format: "  Number of intersection points: %d\n", qh_qh.num_facets - qh_qh.num_visible);
      if ( qh_qh.num_good != 0 )
        fprintf(str: fp, format: "  Number of 'good' intersections: %d\n", qh_qh.num_good);
    }
    else
    {
      fprintf(str: fp, format: "\nConvex hull of %d points in %d-d:\n\n", v2, qh_qh.hull_dim);
      fprintf(str: fp, format: "  Number of vertices: %d\n", numvertices);
      if ( numcoplanars != 0 )
      {
        if ( qh_qh.KEEPinside != 0 )
        {
          if ( qh_qh.KEEPcoplanar != 0 )
            v8 = "coplanar and interior";
          else
            v8 = "interior";
        }
        else
        {
          v8 = "coplanar";
        }
        fprintf(str: fp, format: "  Number of %s points: %d\n", v8, numcoplanars);
      }
      fprintf(str: fp, format: "  Number of facets: %d\n", qh_qh.num_facets - qh_qh.num_visible);
      if ( qh_qh.num_good != 0 )
        fprintf(str: fp, format: "  Number of 'good' facets: %d\n", qh_qh.num_good);
    }
    fprintf(str: fp, format: "\nStatistics for: %s | %s", qh_qh.rbox_command, qh_qh.qhull_command);
    if ( qh_qh.ROTATErandom == 0x80000000 )
      fprintf(str: fp, format: "\n\n");
    else
      fprintf(str: fp, format: " QR%d\n\n", qh_qh.ROTATErandom);
    fprintf(str: fp, format: "  Number of points processed: %d\n", qh_qhstat.stats[151].i);
    fprintf(str: fp, format: "  Number of hyperplanes created: %d\n", qh_qhstat.stats[172].i);
    fprintf(
      str: fp,
      format: "  Number of distance tests for qhull: %d\n",
      qh_qhstat.stats[143].i + qh_qhstat.stats[144].i + qh_qhstat.stats[138].i + qh_qhstat.stats[141].i);
    if ( qh_qhstat.stats[176].i + qh_qhstat.stats[36].i - qh_qhstat.stats[37].i != 0 )
    {
      fprintf(
        str: fp,
        format: "  Number of merged facets: %d\n",
        qh_qhstat.stats[176].i + qh_qhstat.stats[36].i - qh_qhstat.stats[37].i);
      fprintf(
        str: fp,
        format: "  Number of distance tests for merging: %d\n",
        qh_qhstat.stats[16].i
      + qh_qhstat.stats[17].i
      + qh_qhstat.stats[49].i
      + qh_qhstat.stats[48].i
      + qh_qhstat.stats[55].i);
    }
    if ( qh_qh.RANDOMoutside == 0 && qh_qh.QHULLfinished != 0 )
    {
      qh_qhstat.stats[34].r = (double)qh_qh.hulltime;
      fprintf(str: fp, format: "  CPU seconds to compute hull (after input): %2.4g\n", (double)qh_qhstat.stats[34].r);
    }
    if ( qh_qh.RERUN != 0 )
    {
      if ( qh_qh.PREmerge == 0 && qh_qh.MERGEexact == 0 )
        fprintf(
          str: fp,
          format: "  Percentage of runs with precision errors: %4.1f\n",
          (double)qh_qhstat.stats[157].i * 100.0 / (double)qh_qh.build_cnt);
    }
    else if ( qh_qh.JOGGLEmax < 8.988465674311579e307 )
    {
      if ( qh_qhstat.stats[157].i != 0 )
        fprintf(
          str: fp,
          format: "  After %d retries, input joggled by: %2.2g\n",
          qh_qhstat.stats[157].i,
          (double)qh_qh.JOGGLEmax);
      else
        fprintf(str: fp, format: "  Input joggled by: %2.2g\n", (double)qh_qh.JOGGLEmax);
    }
    if ( qh_qh.totarea != 0.0 )
    {
      v9 = "Approximate";
      if ( qh_qhstat.stats[176].i == 0 )
        v9 = "Total";
      fprintf(str: fp, format: "  %s facet area:   %2.8g\n", v9, (double)qh_qh.totarea);
    }
    if ( qh_qh.totvol != 0.0 )
    {
      v10 = "Approximate";
      if ( qh_qhstat.stats[176].i == 0 )
        v10 = "Total";
      fprintf(str: fp, format: "  %s volume:       %2.8g\n", v10, (double)qh_qh.totvol);
    }
    if ( qh_qh.MERGING != 0 )
    {
      qh_outerinner(facet: nullptr, &outerplane, &innerplane);
      DISTround = qh_qh.DISTround;
      if ( outerplane > qh_qh.DISTround * 2.0 )
      {
        v12 = str;
        if ( qh_qh.QHULLfinished == 0 )
          v12 = "merged ";
        fprintf(str: fp, format: "  Maximum distance of %spoint above facet: %2.2g", v12, (double)outerplane);
        if ( outerplane / (qh_qh.ONEmerge + qh_qh.DISTround) <= 0.05
          || qh_qh.ONEmerge <= qh_qh.MINoutside
          || qh_qh.JOGGLEmax <= 8.988465674311579e307 )
        {
          fprintf(str: fp, format: "\n");
        }
        else
        {
          fprintf(str: fp, format: " (%.1fx)\n", (double)(outerplane / (qh_qh.ONEmerge + qh_qh.DISTround)));
        }
        DISTround = qh_qh.DISTround;
      }
      if ( DISTround * -2.0 > innerplane )
      {
        v13 = str;
        if ( qh_qh.QHULLfinished == 0 )
          v13 = "merged ";
        fprintf(str: fp, format: "  Maximum distance of %svertex below facet: %2.2g", v13, innerplane);
        v14 = -(innerplane / (qh_qh.ONEmerge + qh_qh.DISTround));
        if ( v14 > 0.05 && qh_qh.JOGGLEmax > 8.988465674311579e307 )
        {
          fprintf(str: fp, format: " (%.1fx)\n", v14);
          fprintf(str: fp, format: "\n");
          return;
        }
        fprintf(str: fp, format: "\n");
      }
    }
    fprintf(str: fp, format: "\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005F910
// Name: void qh_findhorizon(double __near *,struct facetT __near *,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_findhorizon(long double *point, facetT *facet, int *goodvisible, int *goodhorizon)
{
  int v4; // eax
  facetT *v5; // ecx
  setT *neighbors; // eax
  setelemT v7; // esi
  setelemT *e; // ebx
  double v9; // xmm0_8
  int v10; // eax
  int v11; // eax
  int v12; // [esp-4h] [ebp-30h]
  double MINvisible; // [esp+8h] [ebp-24h]
  unsigned int id; // [esp+Ch] [ebp-20h]
  double dist; // [esp+1Ch] [ebp-10h] BYREF
  int coplanar; // [esp+24h] [ebp-8h]
  int numhorizon; // [esp+28h] [ebp-4h]
  facetT *visible; // [esp+38h] [ebp+Ch]

  numhorizon = 0;
  coplanar = 0;
  if ( qh_qh.IStracing >= 1 )
  {
    id = facet->id;
    v4 = qh_pointid(point);
    fprintf(str: qh_qh.ferr, format: "qh_findhorizon: find horizon for point p%d facet f%d\n", v4, id);
  }
  *goodhorizon = 0;
  *goodvisible = 0;
  ++qh_qhstat.stats[181].i;
  qh_removefacet(facet);
  qh_appendfacet(facet);
  qh_qh.num_visible = 1;
  if ( (*((_DWORD *)facet + 20) & 0x40000) != 0 )
    ++*goodvisible;
  qh_qh.visible_list = facet;
  *((_DWORD *)facet + 20) |= 0x400u;
  facet->f.replace = nullptr;
  if ( qh_qh.IStracing >= 4 )
    qh_errprint(string: "visible", atfacet: facet, otherfacet: nullptr, atridge: nullptr, atvertex: nullptr);
  ++qh_qh.visit_id;
  visible = qh_qh.visible_list;
  if ( qh_qh.visible_list == nullptr )
    goto LABEL_39;
  do
  {
    v5 = visible;
    if ( (*((_DWORD *)visible + 20) & 0x400) == 0 )
      break;
    neighbors = visible->neighbors;
    visible->visitid = qh_qh.visit_id;
    if ( neighbors != nullptr )
    {
      v7.p = (void *)neighbors->e[0];
      e = neighbors->e;
      if ( v7.i != 0 )
      {
        do
        {
          ++e;
          if ( *(_DWORD *)(v7.i + 72) != qh_qh.visit_id )
          {
            *(_DWORD *)(v7.i + 72) = qh_qh.visit_id;
            ++qh_qhstat.stats[138].i;
            qh_distplane(point, facet: (facetT *)v7.p, &dist);
            if ( dist <= qh_qh.MINvisible )
            {
              if ( dist <= -qh_qh.MAXcoplanar )
              {
                *(_DWORD *)(v7.i + 80) &= ~0x800000u;
              }
              else
              {
                *(_DWORD *)(v7.i + 80) |= 0x800000u;
                ++qh_qhstat.stats[30].i;
                qh_precision(reason: "coplanar horizon");
                ++coplanar;
                v9 = dist;
                if ( qh_qh.MERGING != 0 )
                {
                  if ( dist <= 0.0 )
                  {
                    if ( qh_qh.min_vertex > dist )
                      qh_qh.min_vertex = dist;
                  }
                  else
                  {
                    if ( dist > qh_qh.max_outside )
                      qh_qh.max_outside = dist;
                    if ( dist > qh_qh.max_vertex )
                      qh_qh.max_vertex = dist;
                    if ( dist > *(double *)(v7.i + 8) )
                    {
                      *(double *)(v7.i + 8) = dist;
                      v9 = dist;
                    }
                  }
                }
                if ( qh_qh.IStracing >= 2 )
                {
                  MINvisible = qh_qh.MINvisible;
                  v12 = *(_DWORD *)(v7.i + 76);
                  v10 = qh_pointid(point);
                  fprintf(
                    str: qh_qh.ferr,
                    format: "qh_findhorizon: point p%d is coplanar to horizon f%d, dist=%2.7g < qh MINvisible (%2.7g)\n",
                    v10,
                    v12,
                    v9,
                    MINvisible);
                }
              }
              ++qh_qhstat.stats[175].i;
              ++numhorizon;
              if ( (*(_DWORD *)(v7.i + 80) & 0x40000) != 0 )
                ++*goodhorizon;
              if ( qh_qh.IStracing >= 4 )
                qh_errprint(
                  string: "horizon",
                  atfacet: (facetT *)v7.p,
                  otherfacet: nullptr,
                  atridge: nullptr,
                  atvertex: nullptr);
            }
            else
            {
              ++qh_qhstat.stats[181].i;
              qh_removefacet(facet: (facetT *)v7.p);
              qh_appendfacet(facet: (facetT *)v7.p);
              *(_DWORD *)(v7.i + 80) |= 0x400u;
              *(_DWORD *)(v7.i + 32) = 0;
              ++qh_qh.num_visible;
              if ( (*(_DWORD *)(v7.i + 80) & 0x40000) != 0 )
                ++*goodvisible;
              if ( qh_qh.IStracing >= 4 )
                qh_errprint(
                  string: "visible",
                  atfacet: (facetT *)v7.p,
                  otherfacet: nullptr,
                  atridge: nullptr,
                  atvertex: nullptr);
            }
          }
          v7.p = e->p;
        }
        while ( e->i != 0 );
        v5 = visible;
      }
    }
    visible = v5->next;
  }
  while ( visible != nullptr );
  if ( numhorizon == 0 )
  {
LABEL_39:
    qh_precision(reason: "empty horizon");
    v11 = qh_pointid(point);
    fprintf(
      str: qh_qh.ferr,
      format: "qhull precision error (qh_findhorizon): empty horizon\nPoint p%d was above all facets.\n",
      v11);
    qh_printfacetlist(facetlist: qh_qh.facet_list, facets: nullptr, printall: 1u);
    qh_errexit(exitcode: 3, facet: nullptr, ridge: nullptr);
  }
  if ( qh_qh.IStracing >= 1 )
    fprintf(
      str: qh_qh.ferr,
      format: "qh_findhorizon: %d horizon facets (good %d), %d visible (good %d), %d coplanar\n",
      numhorizon,
      *goodhorizon,
      qh_qh.num_visible,
      *goodvisible,
      coplanar);
  if ( qh_qh.IStracing >= 4 && qh_qh.num_facets < 50 )
    qh_printlists();
}

//------------------------------------------------------------------------------
// Address: 0x1005FC60
// Name: void qh_partitionpoint(double __near *,struct facetT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_partitionpoint(long double *point, facetT *facet)
{
  facetT *v2; // eax
  __int64 v3; // xmm1_8
  double v4; // xmm0_8
  facetT *v5; // edi
  long double NEARinside; // xmm2_8
  int v7; // eax
  int v8; // eax
  unsigned int v9; // [esp-4h] [ebp-28h]
  setT **p_outsideset; // [esp+0h] [ebp-24h]
  unsigned int id; // [esp+4h] [ebp-20h]
  double bestdist; // [esp+14h] [ebp-10h] BYREF
  int numpart; // [esp+1Ch] [ebp-8h] BYREF
  unsigned int isoutside; // [esp+20h] [ebp-4h] BYREF

  if ( qh_qh.findbestnew != 0 )
    v2 = qh_findbestnew(point, startfacet: facet, dist: &bestdist, &isoutside, &numpart);
  else
    v2 = qh_findbest(
           point,
           startfacet: facet,
           bestoutside: qh_qh.BESToutside,
           newfacets: 1u,
           noupper: 0,
           dist: &bestdist,
           &isoutside,
           &numpart);
  ++qh_qhstat.stats[178].i;
  v3 = _mask__NegDouble_;
  v4 = bestdist;
  v5 = v2;
  qh_qhstat.stats[143].i += numpart;
  if ( qh_qh.NARROWhull == 0 )
  {
LABEL_14:
    NEARinside = qh_qh.NEARinside;
    goto LABEL_15;
  }
  if ( qh_qh.DELAUNAY != 0
    && isoutside == 0
    && bestdist >= COERCE_DOUBLE(*(_QWORD *)&qh_qh.MAXcoplanar ^ _mask__NegDouble_) )
  {
    qh_precision(reason: "nearly incident point (narrow hull)");
    v4 = bestdist;
    v3 = _mask__NegDouble_;
  }
  if ( qh_qh.KEEPnearinside == 0 )
  {
    if ( v4 >= COERCE_DOUBLE(*(_QWORD *)&qh_qh.MAXcoplanar ^ v3) )
    {
      isoutside = 1;
      goto LABEL_16;
    }
    goto LABEL_14;
  }
  NEARinside = qh_qh.NEARinside;
  if ( v4 >= COERCE_DOUBLE(*(_QWORD *)&qh_qh.NEARinside ^ v3) )
  {
    isoutside = 1;
LABEL_16:
    if ( v5->outsideset != nullptr && qh_setlast(set: v5->outsideset) != 0 )
    {
      p_outsideset = &v5->outsideset;
      if ( bestdist <= v5->furthestdist )
      {
        qh_setappend2ndlast(setp: p_outsideset, newelem: point);
        goto LABEL_24;
      }
      qh_setappend(setp: p_outsideset, newelem: point);
    }
    else
    {
      qh_setappend(setp: &v5->outsideset, newelem: point);
      if ( (*((_DWORD *)v5 + 20) & 0x200) == 0 )
      {
        qh_removefacet(facet: v5);
        qh_appendfacet(facet: v5);
      }
    }
    v5->furthestdist = bestdist;
LABEL_24:
    ++qh_qh.num_outside;
    if ( qh_qh.IStracing >= 4 )
    {
      id = v5->id;
      v7 = qh_pointid(point);
      fprintf(str: qh_qh.ferr, format: "qh_partitionpoint: point p%d is outside facet f%d\n", v7, id);
    }
    return;
  }
LABEL_15:
  if ( isoutside != 0 )
    goto LABEL_16;
  if ( v4 < COERCE_DOUBLE(*(_QWORD *)&qh_qh.MAXcoplanar ^ v3) )
  {
    if ( qh_qh.KEEPnearinside != 0 && v4 > COERCE_DOUBLE(*(_QWORD *)&NEARinside ^ v3) )
    {
      ++qh_qhstat.stats[145].i;
LABEL_38:
      qh_partitioncoplanar(point, facet: v5, dist: &bestdist);
      return;
    }
    ++qh_qhstat.stats[142].i;
    if ( qh_qh.IStracing >= 4 )
    {
      v9 = v5->id;
      v8 = qh_pointid(point);
      fprintf(
        str: qh_qh.ferr,
        format: "qh_partitionpoint: point p%d is inside all facets, closest to f%d dist %2.2g\n",
        v8,
        v9,
        v4);
    }
    if ( qh_qh.KEEPinside != 0 )
      goto LABEL_38;
  }
  else
  {
    ++qh_qhstat.stats[32].i;
    if ( qh_qh.DELAUNAY != 0 )
    {
      qh_precision(reason: "nearly incident point");
      v4 = bestdist;
    }
    if ( qh_qh.KEEPnearinside + qh_qh.KEEPcoplanar != 0 || v4 > qh_qh.max_outside )
      goto LABEL_38;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005FEE0
// Name: void qh_partitionvisible(unsigned int,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_partitionvisible(unsigned int allpoints, int *numoutside)
{
  facetT *i; // ebx
  facetT *replace; // edi
  unsigned int v4; // esi
  unsigned int v5; // ecx
  int v6; // eax
  setT *outsideset; // eax
  long double **e; // esi
  long double *p; // eax
  setT *coplanarset; // eax
  long double **v11; // esi
  long double *v12; // eax
  setelemT *v13; // esi
  setelemT v14; // eax
  long double *v15; // eax
  int coplanar; // [esp+0h] [ebp-4h]

  coplanar = 0;
  if ( qh_qh.ONLYmax != 0 && qh_qh.max_vertex > qh_qh.MINoutside )
    qh_qh.MINoutside = qh_qh.max_vertex;
  *numoutside = 0;
  for ( i = qh_qh.visible_list; i != nullptr; i = i->next )
  {
    if ( (*((_DWORD *)i + 20) & 0x400) == 0 )
      break;
    if ( i->outsideset != nullptr || i->coplanarset != nullptr )
    {
      replace = i->f.replace;
      v4 = 0;
      if ( replace != nullptr )
      {
        while ( (*((_DWORD *)replace + 20) & 0x400) != 0 )
        {
          replace = replace->f.replace;
          v5 = v4++;
          if ( v5 > qh_qh.facet_id )
            qh_infiniteloop(facet: i);
          if ( replace == nullptr )
            goto LABEL_13;
        }
      }
      else
      {
LABEL_13:
        replace = qh_qh.newfacet_list;
      }
      if ( i->outsideset != nullptr )
      {
        v6 = qh_setsize(set: i->outsideset);
        *numoutside += v6;
        qh_qh.num_outside -= v6;
        outsideset = i->outsideset;
        if ( outsideset != nullptr )
        {
          e = (long double **)outsideset->e;
          p = (long double *)outsideset->e[0].p;
          if ( p != nullptr )
          {
            do
            {
              ++e;
              qh_partitionpoint(point: p, facet: replace);
              p = *e;
            }
            while ( *e != nullptr );
          }
        }
      }
      if ( i->coplanarset != nullptr && qh_qh.KEEPcoplanar + qh_qh.KEEPinside + qh_qh.KEEPnearinside != 0 )
      {
        coplanar += qh_setsize(set: i->coplanarset);
        coplanarset = i->coplanarset;
        if ( coplanarset != nullptr )
        {
          v11 = (long double **)coplanarset->e;
          v12 = (long double *)coplanarset->e[0].p;
          if ( v12 != nullptr )
          {
            do
            {
              ++v11;
              if ( allpoints != 0 )
                qh_partitionpoint(point: v12, facet: replace);
              else
                qh_partitioncoplanar(point: v12, facet: replace, dist: nullptr);
              v12 = *v11;
            }
            while ( *v11 != nullptr );
          }
        }
      }
    }
  }
  if ( qh_qh.del_vertices != nullptr )
  {
    v13 = qh_qh.del_vertices->e;
    v14.p = (void *)qh_qh.del_vertices->e[0];
    if ( v14.i != 0 )
    {
      do
      {
        v15 = *(long double **)(v14.i + 8);
        ++v13;
        if ( v15 != nullptr )
        {
          if ( allpoints != 0 )
            qh_partitionpoint(point: v15, facet: qh_qh.newfacet_list);
          else
            qh_partitioncoplanar(point: v15, facet: qh_qh.newfacet_list, dist: nullptr);
        }
        v14.p = v13->p;
      }
      while ( v13->i != 0 );
    }
  }
  if ( qh_qh.IStracing >= 1 )
    fprintf(
      str: qh_qh.ferr,
      format: "qh_partitionvisible: partitioned %d points from outsidesets and %d points from coplanarsets\n",
      *numoutside,
      coplanar);
}

//------------------------------------------------------------------------------
// Address: 0x100600B0
// Name: unsigned int qh_addpoint(double __near *,struct facetT __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl qh_addpoint(long double *furthest, facetT *facet, vertexT *checkdist)
{
  facetT *v3; // esi
  unsigned int facet_id; // edi
  unsigned int v6; // ebx
  double v7; // xmm0_8
  facetT *i; // edi
  double v9; // xmm0_8
  facetT *newfacet_list; // eax
  int v11; // eax
  double newbalance; // [esp+1Ch] [ebp-20h]
  long double dist; // [esp+2Ch] [ebp-10h] BYREF
  int numpart; // [esp+34h] [ebp-8h] BYREF
  unsigned int isoutside; // [esp+38h] [ebp-4h] BYREF

  isoutside = 0;
  qh_qh.maxoutdone = 0;
  if ( qh_pointid(point: furthest) == -1 )
    qh_setappend(setp: &qh_qh.other_points, newelem: furthest);
  v3 = facet;
  if ( facet == nullptr )
  {
    ivp_message(templat: "qh_addpoint: NULL facet.  Use qh_findbestfacet\n");
    qh_errexit(exitcode: 5, facet: nullptr, ridge: nullptr);
  }
  if ( checkdist != nullptr )
  {
    v3 = qh_findbest(
           point: furthest,
           startfacet: facet,
           bestoutside: 0,
           newfacets: 0,
           noupper: 0,
           &dist,
           &isoutside,
           &numpart);
    qh_qhstat.stats[143].i += numpart;
    if ( isoutside == 0 )
    {
      ++qh_qhstat.stats[131].i;
      *((_DWORD *)v3 + 20) |= 0x20000u;
      qh_partitioncoplanar(point: furthest, facet: v3, &dist);
      return 1;
    }
  }
  qh_buildtracing(furthest, facet: v3);
  if ( qh_qh.STOPpoint < 0 && qh_qh.furthest_id == -1 - qh_qh.STOPpoint )
    goto LABEL_10;
  qh_findhorizon(point: furthest, facet: v3, goodvisible: (int *)&checkdist, goodhorizon: (int *)&facet);
  if ( qh_qh.ONLYgood != 0 && (vertexT *)((char *)checkdist + (_DWORD)facet) == nullptr && qh_qh.GOODclosest == nullptr )
  {
    ++qh_qhstat.stats[129].i;
    *((_DWORD *)v3 + 20) |= 0x20000u;
    qh_resetlists(stats: 0);
    return 1;
  }
  ++qh_qhstat.stats[151].i;
  facet_id = qh_qh.facet_id;
  checkdist = qh_makenewfacets(point: furthest);
  qh_makenewplanes();
  v6 = qh_qh.facet_id - facet_id;
  v7 = (double)(int)(qh_qh.facet_id - facet_id)
     - (double)(qh_qh.num_facets - qh_qh.num_visible) * (double)qh_qh.hull_dim / (double)qh_qh.num_vertices;
  newbalance = v7;
  qh_qhstat.stats[121].r = qh_qhstat.stats[121].r + v7;
  qh_qhstat.stats[122].r = v7 * v7 + qh_qhstat.stats[122].r;
  if ( qh_qh.ONLYgood != 0 )
  {
    if ( qh_findgood(facetlist: qh_qh.newfacet_list, goodhorizon: (int)facet) == 0 && qh_qh.GOODclosest == nullptr )
    {
      for ( i = qh_qh.newfacet_list; i != nullptr; i = i->next )
      {
        if ( i->next == nullptr )
          break;
        qh_delfacet(facet: i);
      }
      qh_delvertex(vertex: checkdist);
      qh_resetlists(stats: 1u);
      ++qh_qhstat.stats[130].i;
      *((_DWORD *)v3 + 20) |= 0x20000u;
      return 1;
    }
    if ( qh_qh.ONLYgood != 0 )
      qh_attachnewfacets();
  }
  qh_matchnewfacets();
  qh_updatevertices();
  if ( qh_qh.STOPcone != 0 && qh_qh.furthest_id == qh_qh.STOPcone - 1 )
  {
LABEL_10:
    *((_DWORD *)v3 + 20) |= 0x20000u;
    return 0;
  }
  if ( qh_qh.PREmerge != 0 || qh_qh.MERGEexact != 0 )
  {
    qh_premerge(apex: checkdist, maxcentrum: qh_qh.premerge_centrum, maxangle: qh_qh.premerge_cos);
    if ( qh_qhstat.stats[176].i <= 50 )
    {
      newfacet_list = qh_qh.newfacet_list;
      if ( qh_qh.newfacet_list != nullptr )
      {
        while ( newfacet_list->next != nullptr )
        {
          if ( (*((_DWORD *)newfacet_list + 20) & 0x1000) == 0 )
            goto LABEL_30;
          newfacet_list = newfacet_list->next;
        }
      }
      goto LABEL_31;
    }
    goto LABEL_30;
  }
  if ( qh_qh.BESToutside != 0 )
LABEL_30:
    qh_qh.findbestnew = 1;
LABEL_31:
  qh_partitionvisible(allpoints: 0, numoutside: (int *)&facet);
  ++qh_qhstat.stats[146].i;
  v9 = (double)(int)facet
     - (double)(qh_qh.num_points - qh_qh.num_vertices) * (double)qh_qh.hull_dim / (double)qh_qh.num_vertices;
  qh_qh.findbestnew = 0;
  qh_qh.findbest_notsharp = 0;
  qh_qhstat.stats[147].r = qh_qhstat.stats[147].r + v9;
  qh_qhstat.stats[148].r = v9 * v9 + qh_qhstat.stats[148].r;
  qh_deletevisible();
  if ( qh_qhstat.stats[96].i < qh_qh.num_vertices )
    qh_qhstat.stats[96].i = qh_qh.num_vertices;
  qh_qh.NEWfacets = 0;
  if ( qh_qh.IStracing >= 4 )
    qh_printfacetlist(facetlist: qh_qh.newfacet_list, facets: nullptr, printall: 1u);
  if ( qh_qh.CHECKfrequently != 0 )
  {
    if ( qh_qh.num_facets >= 50 )
      qh_checkpolygon(facetlist: qh_qh.newfacet_list);
    else
      qh_checkpolygon(facetlist: qh_qh.facet_list);
  }
  if ( qh_qh.STOPpoint > 0 && qh_qh.furthest_id == qh_qh.STOPpoint - 1 )
    return 0;
  qh_resetlists(stats: 1u);
  if ( qh_qh.IStracing >= 2 )
  {
    v11 = qh_pointid(point: furthest);
    fprintf(
      str: qh_qh.ferr,
      format: "qh_addpoint: added p%d new facets %d new balance %2.2g point balance %2.2g\n",
      v11,
      v6,
      newbalance,
      v9);
  }
  if ( qh_qh.hull_dim > 3 && qh_qh.TRACEpoint == qh_pointid(point: furthest) )
  {
    qh_qh.IStracing = 0;
    qhmem.IStracing = 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10060520
// Name: void qh_buildhull(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_buildhull()
{
  facetT *facet_list; // esi
  vertexT *vertex_list; // esi
  int v2; // eax
  int v3; // eax
  bool v4; // sf
  long double *i; // esi
  facetT *facet; // [esp+8h] [ebp-4h] BYREF

  if ( qh_qh.IStracing >= 1 )
    fprintf(str: qh_qh.ferr, format: "qh_buildhull: start build hull\n");
  facet_list = qh_qh.facet_list;
  for ( facet = qh_qh.facet_list; facet_list != nullptr; facet = facet_list )
  {
    if ( facet_list->next == nullptr )
      break;
    if ( (*((_DWORD *)facet_list + 20) & 0x600) != 0 )
    {
      ivp_message(
        templat: "qhull internal error (qh_buildhull): visible or new facet f%d in facet list\n",
        facet_list->id);
      qh_errexit(exitcode: 5, facet: facet_list, ridge: nullptr);
    }
    facet_list = facet_list->next;
  }
  vertex_list = qh_qh.vertex_list;
  if ( qh_qh.vertex_list != nullptr )
  {
    while ( vertex_list->next != nullptr )
    {
      v2 = *((_DWORD *)vertex_list + 5);
      if ( (v2 & 0x10000000) != 0 )
      {
        ivp_message(templat: "qhull internal error (qh_buildhull): new vertex f%d in vertex list\n", v2 & 0xFFFFFF);
        qh_errprint(string: "ERRONEOUS", atfacet: nullptr, otherfacet: nullptr, atridge: nullptr, atvertex: vertex_list);
        qh_errexit(exitcode: 5, facet: nullptr, ridge: nullptr);
      }
      v3 = qh_pointid(point: vertex_list->point);
      v4 = qh_qh.STOPpoint < 0;
      if ( qh_qh.STOPpoint > 0 )
      {
        if ( v3 == qh_qh.STOPpoint - 1 )
          goto LABEL_31;
        v4 = qh_qh.STOPpoint < 0;
      }
      if ( v4 && v3 == -1 - qh_qh.STOPpoint || qh_qh.STOPcone > 0 && v3 == qh_qh.STOPcone - 1 )
      {
LABEL_31:
        if ( qh_qh.IStracing >= 1 )
          fprintf(str: qh_qh.ferr, format: "qh_buildhull: stop point or cone P%d in initial hull\n", v3);
        return;
      }
      vertex_list = vertex_list->next;
      if ( vertex_list == nullptr )
        break;
    }
  }
  qh_qh.facet_next = qh_qh.facet_list;
  for ( i = qh_nextfurthest(visible: &facet); i != nullptr; i = qh_nextfurthest(visible: &facet) )
  {
    --qh_qh.num_outside;
    if ( qh_addpoint(furthest: i, facet, checkdist: (vertexT *)qh_qh.ONLYmax) == 0 )
      break;
  }
  if ( qh_qh.NARROWhull != 0 )
    qh_outcoplanar();
  if ( qh_qh.num_outside != 0 && i == nullptr )
  {
    ivp_message(
      templat: "qhull internal error (qh_buildhull): %d outside points were never processed.\n",
      qh_qh.num_outside);
    qh_errexit(exitcode: 5, facet: nullptr, ridge: nullptr);
  }
  if ( qh_qh.IStracing >= 1 )
    fprintf(str: qh_qh.ferr, format: "qh_buildhull: completed the hull construction\n");
}

//------------------------------------------------------------------------------
// Address: 0x10060700
// Name: void qh_partitionall(struct setT __near *,double __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_partitionall(setT *vertices, long double *points, facetT *numpoints)
{
  setT *v3; // eax
  long double *v5; // edi
  setelemT *e; // esi
  facetT *v7; // edx
  setelemT v8; // eax
  setelemT *v9; // esi
  int v10; // eax
  int v11; // eax
  int v12; // eax
  double MINoutside; // xmm0_8
  facetT *facet_list; // esi
  int num_facets; // ecx
  facetT *v16; // eax
  setT **p_outsideset; // ebx
  long double *p; // esi
  long double *v19; // ebx
  int v20; // esi
  int v21; // edi
  double dist; // [esp+0h] [ebp-24h] BYREF
  long double distoutside; // [esp+8h] [ebp-1Ch]
  long double bestdist; // [esp+10h] [ebp-14h]
  int point_n; // [esp+18h] [ebp-Ch]
  int remaining; // [esp+1Ch] [ebp-8h]
  setT *pointset; // [esp+20h] [ebp-4h] BYREF
  int point_i; // [esp+2Ch] [ebp+8h]
  int point_end; // [esp+30h] [ebp+Ch]
  facetT *facet; // [esp+34h] [ebp+10h]

  bestdist = -1.797693134862316e308;
  if ( qh_qh.IStracing >= 1 )
    fprintf(str: qh_qh.ferr, format: "qh_partitionall: partition all points into outside sets\n");
  v3 = qh_settemp(setsize: (int)numpoints);
  v5 = nullptr;
  pointset = v3;
  qh_qh.num_outside = 0;
  e = v3->e;
  v7 = numpoints;
  if ( numpoints != nullptr )
  {
    do
    {
      e->i = (int)points;
      v7 = (facetT *)((char *)v7 - 1);
      ++e;
      points += qh_qh.hull_dim;
    }
    while ( v7 != nullptr );
    v3 = pointset;
  }
  qh_settruncate(set: v3, size: (int)numpoints);
  if ( vertices != nullptr )
  {
    v8.p = (void *)vertices->e[0];
    v9 = vertices->e;
    if ( v8.i != 0 )
    {
      do
      {
        ++v9;
        v10 = qh_pointid(point: *(long double **)(v8.i + 8));
        if ( v10 >= 0 )
          pointset->e[v10].i = 0;
        v8.p = v9->p;
      }
      while ( v9->i != 0 );
    }
  }
  v11 = qh_pointid(point: qh_qh.GOODpointp);
  if ( v11 >= 0 && qh_qh.STOPcone - 1 != v11 && -1 - qh_qh.STOPpoint != v11 )
    pointset->e[v11].i = 0;
  if ( qh_qh.GOODvertexp != nullptr && qh_qh.ONLYgood != 0 && qh_qh.MERGING == 0 )
  {
    v12 = qh_pointid(point: qh_qh.GOODvertexp);
    if ( v12 >= 0 )
      pointset->e[v12].i = 0;
  }
  if ( qh_qh.BESToutside != 0 )
    goto LABEL_49;
  MINoutside = qh_qh.MINoutside;
  if ( qh_qh.MERGING != 0 && (MINoutside = qh_qh.MINoutside * 4.0, qh_qh.max_outside * 2.0 > qh_qh.MINoutside * 4.0) )
    distoutside = qh_qh.max_outside * 2.0;
  else
    distoutside = MINoutside;
  facet_list = qh_qh.facet_list;
  num_facets = qh_qh.num_facets;
  qh_qhstat.stats[178].i = qh_qh.num_points - qh_qh.hull_dim - 1;
  v16 = numpoints;
  facet = qh_qh.facet_list;
  if ( qh_qh.facet_list == nullptr )
  {
LABEL_46:
    if ( qh_qh.MERGING != 0 || qh_qh.KEEPcoplanar != 0 || qh_qh.KEEPinside != 0 )
      goto LABEL_49;
    goto LABEL_55;
  }
  while ( facet_list->next != nullptr )
  {
    remaining = num_facets - 1;
    p_outsideset = &facet_list->outsideset;
    facet_list->outsideset = qh_setnew(setsize: (int)v16 / num_facets + 100);
    point_end = 0;
    if ( pointset != nullptr )
    {
      p = (long double *)pointset->e[0].p;
      point_i = 0;
      point_n = qh_setsize(set: pointset);
      if ( point_n > 0 )
      {
        do
        {
          if ( p != nullptr )
          {
            ++qh_qhstat.stats[144].i;
            qh_distplane(point: p, facet, &dist);
            if ( distoutside <= dist )
            {
              ++qh_qh.num_outside;
              if ( v5 != nullptr )
              {
                if ( dist <= bestdist )
                {
                  qh_setappend(setp: p_outsideset, newelem: p);
                }
                else
                {
                  qh_setappend(setp: p_outsideset, newelem: v5);
                  v5 = p;
                  bestdist = dist;
                }
              }
              else
              {
                v5 = p;
                bestdist = dist;
              }
            }
            else
            {
              pointset->e[point_end++].i = (int)p;
            }
          }
          p = (long double *)*(&pointset[1].maxsize + point_i++);
        }
        while ( point_i < point_n );
        if ( v5 != nullptr )
        {
          qh_setappend(setp: p_outsideset, newelem: v5);
          facet->furthestdist = bestdist;
          facet_list = facet;
          goto LABEL_44;
        }
      }
      facet_list = facet;
    }
    qh_setfree(setp: p_outsideset);
LABEL_44:
    qh_settruncate(set: pointset, size: point_end);
    v5 = nullptr;
    facet = facet_list->next;
    if ( facet == nullptr )
      break;
    v16 = (facetT *)point_end;
    facet_list = facet_list->next;
    num_facets = remaining;
  }
  if ( qh_qh.BESToutside == 0 )
    goto LABEL_46;
LABEL_49:
  qh_qh.findbestnew = 1;
  if ( pointset != nullptr )
  {
    v19 = (long double *)pointset->e[0].p;
    v20 = 0;
    v21 = qh_setsize(set: pointset);
    if ( v21 > 0 )
    {
      do
      {
        if ( v19 != nullptr )
          qh_partitionpoint(point: v19, facet: qh_qh.facet_list);
        v19 = (long double *)*(&pointset[1].maxsize + v20++);
      }
      while ( v20 < v21 );
    }
  }
  qh_qh.findbestnew = 0;
LABEL_55:
  qh_qhstat.stats[144].i += qh_qhstat.stats[143].i;
  qh_qhstat.stats[143].i = 0;
  qh_settempfree(set: &pointset);
  if ( qh_qh.IStracing >= 4 )
    qh_printfacetlist(facetlist: qh_qh.facet_list, facets: nullptr, printall: 1u);
}

//------------------------------------------------------------------------------
// Address: 0x10060A60
// Name: void qh_build_withrestart(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_build_withrestart()
{
  int v0; // eax
  int TRACElastrun; // eax

  qh_qh.ALLOWrestart = 1;
  while ( 1 )
  {
    v0 = _setjmp3(a1: qh_qh.restartexit, a2: 0);
    if ( v0 != 0 )
    {
      ++qh_qhstat.stats[157].i;
      if ( qh_qh.JOGGLEmax > qh_qhstat.stats[158].r )
        qh_qhstat.stats[158].r = qh_qh.JOGGLEmax;
      qh_qh.ERREXITcalled = 0;
      qh_qh.STOPcone = 1;
    }
    if ( qh_qh.RERUN == 0 && qh_qh.JOGGLEmax < 8.988465674311579e307 )
      break;
    if ( qh_qh.build_cnt != 0 && qh_qh.build_cnt >= qh_qh.RERUN )
      goto LABEL_12;
LABEL_15:
    qh_qh.STOPcone = 0;
    qh_freebuild(allmem: 1u);
    ++qh_qh.build_cnt;
    if ( qh_qh.qhull_optionsiz != 0 )
    {
      qh_qh.qhull_options[qh_qh.qhull_optionsiz] = 0;
      qh_qh.qhull_optionlen = 80;
    }
    else
    {
      qh_qh.qhull_optionsiz = p_strlen(s: qh_qh.qhull_options);
    }
    qh_option(option: "_run", i: &qh_qh.build_cnt, r: nullptr);
    if ( qh_qh.build_cnt == qh_qh.RERUN )
    {
      TRACElastrun = qh_qh.TRACElastrun;
      qh_qh.IStracing = qh_qh.TRACElastrun;
      if ( qh_qh.TRACEpoint != -1 || qh_qh.TRACEdist < 8.988465674311579e307 || qh_qh.TRACEmerge != 0 )
      {
        qh_qh.TRACElevel = qh_qh.TRACElastrun;
        if ( qh_qh.TRACElastrun == 0 )
          qh_qh.TRACElevel = 3;
        TRACElastrun = 0;
        qh_qh.IStracing = 0;
      }
      qhmem.IStracing = TRACElastrun;
    }
    if ( qh_qh.JOGGLEmax < 8.988465674311579e307 )
      qh_joggleinput(this: (void *)qh_qh.build_cnt);
    qh_initbuild();
    qh_buildhull();
    if ( qh_qh.JOGGLEmax < 8.988465674311579e307 && qh_qh.MERGING == 0 )
      qh_checkconvex(facetlist: qh_qh.facet_list, fault: 0);
  }
  if ( qh_qh.build_cnt > 100 )
  {
    fprintf(
      str: qh_qh.ferr,
      format: "\n"
      "qhull precision error: %d attempts to construct a convex hull\n"
      "        with joggled input.  Increase joggle above 'QJ%2.2g'\n"
      "\tor modify qh_JOGGLE... parameters in user.h\n",
      qh_qh.build_cnt,
      (double)qh_qh.JOGGLEmax);
    qh_errexit(exitcode: 5, facet: nullptr, ridge: nullptr);
  }
  if ( qh_qh.build_cnt == 0 || v0 != 0 )
    goto LABEL_15;
LABEL_12:
  qh_qh.ALLOWrestart = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10060C30
// Name: void qh_qhull(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_qhull()
{
  unsigned int TESTvneighbors; // eax
  int v1; // eax
  int numoutside; // [esp+18h] [ebp-4h] BYREF

  numoutside = 0;
  qh_qh.hulltime = 1;
  if ( qh_qh.RERUN != 0 || qh_qh.JOGGLEmax < 8.988465674311579e307 )
  {
    qh_build_withrestart();
  }
  else
  {
    qh_initbuild();
    qh_buildhull();
  }
  if ( qh_qh.STOPpoint != 0 || qh_qh.STOPcone != 0 )
    goto LABEL_32;
  TESTvneighbors = qh_qh.TESTvneighbors;
  if ( qh_qh.ZEROall_ok != 0 )
  {
    if ( qh_qh.TESTvneighbors == 0 && qh_qh.MERGEexact != 0 )
    {
      qh_checkzero(testall: 1u);
      TESTvneighbors = qh_qh.TESTvneighbors;
    }
    if ( qh_qh.ZEROall_ok != 0 && TESTvneighbors == 0 && qh_qh.WAScoplanar == 0 )
    {
      if ( qh_qh.IStracing >= 2 )
        fprintf(
          str: qh_qh.ferr,
          format: "qh_qhull: all facets are clearly convex and no coplanar points.  Post-merging and check of maxout not needed.\n");
      goto LABEL_32;
    }
  }
  if ( qh_qh.MERGEexact != 0 || qh_qh.hull_dim > 5 && qh_qh.PREmerge != 0 )
  {
    qh_postmerge(
      reason: "First post-merge",
      maxcentrum: qh_qh.premerge_centrum,
      maxangle: qh_qh.premerge_cos,
      vneighbors: qh_qh.POSTmerge == 0 ? TESTvneighbors : 0);
LABEL_23:
    if ( qh_qh.POSTmerge != 0 )
    {
      TESTvneighbors = qh_qh.TESTvneighbors;
      goto LABEL_25;
    }
    goto LABEL_26;
  }
  if ( qh_qh.POSTmerge != 0 )
  {
LABEL_25:
    qh_postmerge(
      reason: "For post-merging",
      maxcentrum: qh_qh.postmerge_centrum,
      maxangle: qh_qh.postmerge_cos,
      vneighbors: TESTvneighbors);
    goto LABEL_26;
  }
  if ( TESTvneighbors != 0 )
  {
    qh_postmerge(
      reason: "For testing vertex neighbors",
      maxcentrum: qh_qh.premerge_centrum,
      maxangle: qh_qh.premerge_cos,
      vneighbors: 1u);
    goto LABEL_23;
  }
LABEL_26:
  if ( qh_qh.visible_list == qh_qh.facet_list )
  {
    qh_qh.findbestnew = 1;
    qh_partitionvisible(allpoints: 0, &numoutside);
    qh_qh.findbestnew = 0;
    qh_deletevisible();
    qh_resetlists(stats: 0);
  }
  if ( qh_qh.DOcheckmax != 0 )
  {
    if ( qh_qh.REPORTfreq != 0 )
    {
      qh_buildtracing(furthest: nullptr, facet: nullptr);
      ivp_message(templat: "\nTesting all coplanar points.\n");
    }
    qh_check_maxout();
  }
LABEL_32:
  if ( qh_qh.KEEPnearinside != 0 && qh_qh.maxoutdone == 0 )
    qh_nearcoplanar();
  if ( qh_setsize(set: (setT *)qhmem.tempstack) != 0 )
  {
    v1 = qh_setsize(set: (setT *)qhmem.tempstack);
    ivp_message(templat: "qhull internal error (qh_qhull): temporary sets not empty (%d)\n", v1);
    qh_errexit(exitcode: 5, facet: nullptr, ridge: nullptr);
  }
  qh_qh.QHULLfinished = 1;
  qh_qh.hulltime = 1 - qh_qh.hulltime;
  if ( qh_qh.IStracing >= 1 )
    fprintf(str: qh_qh.ferr, format: "qh_qhull: algorithm completed\n");
}
