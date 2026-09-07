// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_compact_builder/qhull_geom.cxx
// Functions: 15
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x100595F0
// Name: void qh_backnormal(double __near * __near *,int,int,unsigned int,double __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_backnormal(
        long double **rows,
        int numrow,
        int numcol,
        unsigned int sign,
        long double *normal,
        unsigned int *nearzero)
{
  long double *v6; // esi
  __int64 v7; // xmm0_8
  __int64 *v8; // esi
  int v9; // edi
  int v10; // ebx
  long double **v11; // edx
  int v12; // ecx
  int v13; // edi
  double *v14; // eax
  double *v15; // ecx
  int v16; // edi
  unsigned int v17; // edx
  double v18; // xmm0_8
  double v19; // xmm0_8
  double v20; // xmm0_8
  double v21; // xmm1_8
  int v22; // ecx
  int v23; // edx
  double v24; // xmm0_8
  double numer; // xmm0_8
  __int64 v26; // xmm0_8
  long double *v27; // edi
  long double denom; // [esp+8h] [ebp-3Ch]
  long double *v29; // [esp+28h] [ebp-1Ch]
  double *v30; // [esp+2Ch] [ebp-18h]
  int v31; // [esp+30h] [ebp-14h]
  long double **v32; // [esp+34h] [ebp-10h]
  int zerocol; // [esp+38h] [ebp-Ch]
  unsigned int waszero; // [esp+3Ch] [ebp-8h] BYREF
  int j; // [esp+40h] [ebp-4h]
  int numrowa; // [esp+50h] [ebp+Ch]
  long double *normala; // [esp+5Ch] [ebp+18h]

  v6 = &normal[numcol];
  zerocol = -1;
  v29 = v6;
  if ( sign != 0 )
    v7 = 0xBFF0000000000000uLL;
  else
    v7 = 0x3FF0000000000000LL;
  *((_QWORD *)v6 - 1) = v7;
  v8 = (__int64 *)(v6 - 2);
  if ( numrow == 0 )
    return;
  normala = (long double *)(v8 + 2);
  v9 = 8 * numrow;
  v10 = numrow + 1;
  v11 = &rows[numrow];
  v12 = numcol - numrow - 1;
  while ( 1 )
  {
    v13 = v9 - 8;
    --v10;
    v30 = (long double *)((char *)*(v11 - 1) + v13);
    v14 = v30 + 1;
    numrowa = v12 + 1;
    v31 = v13;
    v32 = v11 - 1;
    *v8 = 0;
    v15 = (double *)(v8 + 1);
    v16 = v10;
    j = v10;
    if ( v10 < numcol )
    {
      if ( numrowa >= 4 )
      {
        v17 = ((unsigned int)(numcol - v10 - 4) >> 2) + 1;
        v16 = v10 + 4 * v17;
        j = v16;
        do
        {
          v18 = *(double *)v8 - *v15 * *v14;
          *(double *)v8 = v18;
          v19 = v18 - v15[1] * v14[1];
          *(double *)v8 = v19;
          v20 = v19 - v15[2] * v14[2];
          *(double *)v8 = v20;
          v21 = v15[3] * v14[3];
          v14 += 4;
          v15 += 4;
          --v17;
          *(double *)v8 = v20 - v21;
        }
        while ( v17 != 0 );
      }
      if ( v16 < numcol )
      {
        v22 = (char *)v15 - (char *)v14;
        v23 = numcol - j;
        do
        {
          v24 = *(double *)((char *)v14 + v22) * *v14;
          ++v14;
          --v23;
          *(double *)v8 = *(double *)v8 - v24;
        }
        while ( v23 != 0 );
      }
    }
    if ( COERCE_DOUBLE(*(_QWORD *)v30 & _mask__AbsDouble_) > qh_qh.MINdenom_2 )
    {
      *(double *)v8 = *(double *)v8 / *v30;
LABEL_16:
      --v8;
      --normala;
      goto LABEL_17;
    }
    denom = *v30;
    numer = *(double *)v8;
    waszero = 0;
    *(long double *)v8 = qh_divzero(numer, denom, mindenom1: qh_qh.MINdenom_1_2, zerodiv: &waszero);
    if ( waszero == 0 )
      goto LABEL_16;
    zerocol = v10 - 1;
    if ( sign != 0 )
      v26 = 0xBFF0000000000000uLL;
    else
      v26 = 0x3FF0000000000000LL;
    v27 = normala - 1;
    *v8-- = v26;
    normala = v27;
    if ( v27 < v29 )
      memset(v27, 0, 4 * (((((unsigned int)((char *)v29 - (char *)v27 - 1) >> 2) & 0xFFFFFFFE) + 2) & 0x3FFFFFFE));
LABEL_17:
    if ( v10 == 1 )
      break;
    v12 = numrowa;
    v9 = v31;
    v11 = v32;
  }
  if ( zerocol != -1 )
  {
    ++qh_qhstat.stats[14].i;
    *nearzero = 1;
    if ( qh_qh.IStracing >= 4 )
      fprintf(str: qh_qh.ferr, format: "qh_backnormal: zero diagonal at column %d.\n", -1);
    qh_precision(reason: "zero diagonal on back substitution");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10059840
// Name: void qh_distplane(double __near *,struct facetT __near *,double __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_distplane(long double *point, facetT *facet, long double *dist)
{
  long double *normal; // eax
  long double *v4; // edi
  int hull_dim; // ecx
  char *v6; // edx
  long double v7; // xmm0_8
  int v8; // eax
  unsigned int id; // [esp+4h] [ebp-10h]

  normal = facet->normal;
  switch ( qh_qh.hull_dim )
  {
    case 2:
      v4 = dist;
      *dist = *normal * *point + facet->offset + normal[1] * point[1];
      break;
    case 3:
      v4 = dist;
      *dist = *normal * *point + facet->offset + normal[1] * point[1] + normal[2] * point[2];
      break;
    case 4:
      v4 = dist;
      *dist = *normal * *point + facet->offset + normal[1] * point[1] + normal[2] * point[2] + normal[3] * point[3];
      break;
    case 5:
      v4 = dist;
      *dist = *normal * *point
            + facet->offset
            + normal[1] * point[1]
            + normal[2] * point[2]
            + normal[3] * point[3]
            + normal[4] * point[4];
      break;
    case 6:
      v4 = dist;
      *dist = *normal * *point
            + facet->offset
            + normal[1] * point[1]
            + normal[2] * point[2]
            + normal[3] * point[3]
            + normal[4] * point[4]
            + normal[5] * point[5];
      break;
    case 7:
      v4 = dist;
      *dist = *normal * *point
            + facet->offset
            + normal[1] * point[1]
            + normal[2] * point[2]
            + normal[3] * point[3]
            + normal[4] * point[4]
            + normal[5] * point[5]
            + normal[6] * point[6];
      break;
    case 8:
      v4 = dist;
      *dist = *normal * *point
            + facet->offset
            + normal[1] * point[1]
            + normal[2] * point[2]
            + normal[3] * point[3]
            + normal[4] * point[4]
            + normal[5] * point[5]
            + normal[6] * point[6]
            + normal[7] * point[7];
      break;
    default:
      v4 = dist;
      *dist = facet->offset;
      hull_dim = qh_qh.hull_dim;
      if ( qh_qh.hull_dim != 0 )
      {
        v6 = (char *)((char *)point - (char *)normal);
        do
        {
          v7 = *(double *)((char *)normal + (_DWORD)v6) * *normal + *dist;
          ++normal;
          --hull_dim;
          *dist = v7;
        }
        while ( hull_dim != 0 );
      }
      break;
  }
  ++qh_qhstat.stats[52].i;
  if ( qh_qh.RANDOMdist != 0 )
    *v4 = ((double)qh_rand() * 2.0 * 4.656612877414201e-10 - 1.0) * qh_qh.RANDOMfactor * qh_qh.MAXabs_coord + *v4;
  if ( qh_qh.IStracing >= 4 )
  {
    ivp_message(templat: "qh_distplane: ");
    ivp_message(templat: "%6.16g ", (double)*v4);
    id = facet->id;
    v8 = qh_pointid(point);
    ivp_message(templat: "from p%d to f%d\n", v8, id);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10059B80
// Name: struct facetT __near * qh_findbest(double __near *,struct facetT __near *,unsigned int,unsigned int,unsigned int,double __near *,unsigned int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
facetT *__cdecl qh_findbest(
        long double *point,
        facetT *startfacet,
        unsigned int bestoutside,
        unsigned int newfacets,
        unsigned int noupper,
        long double *dist,
        unsigned int *isoutside,
        int *numpart)
{
  unsigned int v8; // edx
  BOOL v9; // esi
  unsigned int v10; // ebx
  facetT *v11; // esi
  int v12; // eax
  double v13; // xmm0_8
  double MINvisible; // xmm3_8
  double DISTround; // xmm2_8
  double v16; // xmm1_8
  double MAXcoplanar; // xmm0_8
  double v18; // xmm0_8
  double v19; // xmm2_8
  setT *neighbors; // eax
  unsigned int v21; // eax
  double v22; // xmm0_8
  int v23; // edx
  setelemT v25; // esi
  double v26; // xmm1_8
  double mincutoff; // [esp+24h] [ebp-44h]
  double searchdist; // [esp+2Ch] [ebp-3Ch]
  double cutoff; // [esp+34h] [ebp-34h]
  long double bestdist; // [esp+3Ch] [ebp-2Ch] BYREF
  int oldtrace; // [esp+44h] [ebp-24h]
  unsigned int testhorizon; // [esp+48h] [ebp-20h]
  unsigned int newbest; // [esp+4Ch] [ebp-1Ch]
  facetT **neighborp; // [esp+50h] [ebp-18h]
  int searchsize; // [esp+54h] [ebp-14h]
  unsigned int ispartition; // [esp+58h] [ebp-10h]
  facetT *facet; // [esp+5Ch] [ebp-Ch]
  unsigned int ischeckmax; // [esp+60h] [ebp-8h]
  facetT *bestfacet; // [esp+64h] [ebp-4h] BYREF

  oldtrace = qh_qh.IStracing;
  bestdist = -8.988465674311579e307;
  bestfacet = nullptr;
  searchsize = 0;
  if ( bestoutside == 0 || newfacets != 0 || isoutside != nullptr )
  {
    ischeckmax = 0;
    if ( newfacets != 0 && isoutside != nullptr )
    {
      v8 = 1;
      goto LABEL_6;
    }
  }
  else
  {
    ischeckmax = 1;
  }
  v8 = 0;
LABEL_6:
  ispartition = v8;
  v9 = newfacets == 0 && isoutside != nullptr;
  v10 = v8 != 0 && (bestoutside != 0 || qh_qh.APPROXhull != 0 || qh_qh.MERGING != 0);
  testhorizon = v10;
  if ( ischeckmax == 0 && v8 == 0 && !v9 )
  {
    ivp_message(templat: "qhull internal error (qh_findbest): unknown combination of arguments\n");
    qh_errexit(exitcode: 5, facet: startfacet, ridge: nullptr);
  }
  if ( qh_qh.TRACElevel != 0 && qh_qh.TRACEpoint >= 0 && qh_qh.TRACEpoint == qh_pointid(point) )
  {
    qh_qh.IStracing = qh_qh.TRACElevel;
    ivp_message(
      templat: "qh_findbest: point p%d starting at f%d bestoutside? %d newfacets %d\n",
      qh_qh.TRACEpoint,
      startfacet->id,
      bestoutside,
      newfacets);
    fprintf(
      str: qh_qh.ferr,
      format: "  ischeckmax %d ispartition %d isfindfacet %d testhorizon %d\n",
      ischeckmax,
      ispartition,
      v9,
      v10);
    ivp_message(templat: "  Last point added to hull was p%d.", qh_qh.furthest_id);
    fprintf(str: qh_qh.ferr, format: "  Last merge was #%d.\n", qh_qhstat.stats[176].i);
  }
  if ( isoutside != nullptr )
    *isoutside = 1;
  v11 = startfacet;
  if ( (*((_DWORD *)startfacet + 20) & 0x8000) != 0 )
    goto LABEL_40;
  *numpart = 1;
  qh_distplane(point, facet: startfacet, dist);
  v12 = *((_DWORD *)startfacet + 20);
  if ( (v12 & 0x10000) != 0 && (noupper != 0 || *dist < qh_qh.MINoutside)
    || (v13 = *dist, bestdist = *dist, bestfacet = startfacet, bestoutside != 0)
    || v13 < qh_qh.MINoutside )
  {
    if ( ischeckmax != 0 && (qh_qh.ONLYgood == 0 || (v12 & 0x40000) != 0) && *dist > startfacet->maxoutside )
      startfacet->maxoutside = *dist;
LABEL_40:
    MINvisible = qh_qh.MINvisible;
    if ( ispartition != 0 )
    {
      DISTround = qh_qh.DISTround;
      v16 = qh_qh.DISTround * 2.0;
    }
    else
    {
      if ( qh_qh.MAXcoplanar <= qh_qh.MINvisible )
        MAXcoplanar = qh_qh.MINvisible;
      else
        MAXcoplanar = qh_qh.MAXcoplanar;
      DISTround = qh_qh.DISTround;
      v16 = qh_qh.DISTround * 2.0 + qh_qh.max_outside + MAXcoplanar;
    }
    v18 = bestdist - v16;
    searchdist = v16;
    cutoff = bestdist - v16;
    mincutoff = 0.0;
    if ( ischeckmax != 0 )
    {
      if ( qh_qh.MAXcoplanar > qh_qh.MINvisible )
        MINvisible = qh_qh.MAXcoplanar;
      v19 = -(DISTround - MINvisible);
      mincutoff = v19;
      if ( v18 > v19 )
      {
        v18 = v19;
        cutoff = v19;
      }
    }
    facet = startfacet;
    while ( 2 )
    {
      v11->visitid = ++qh_qh.visit_id;
      while ( 1 )
      {
LABELrestart:
        newbest = 0;
        if ( qh_qh.IStracing >= 4 )
          fprintf(
            str: qh_qh.ferr,
            format: "qh_findbest: neighbors of f%d, bestdist %2.2g cutoff %2.2g searchdist %2.2g\n",
            facet->id,
            (double)bestdist,
            v18,
            v16);
        neighbors = facet->neighbors;
        if ( neighbors != nullptr )
          break;
LABEL_89:
        if ( searchsize == 0 || (facet = (facetT *)qh_setdellast(set: qh_qh.searchset)) == nullptr )
        {
          if ( ischeckmax != 0 )
            goto LABEL_110;
          if ( bestfacet == nullptr )
          {
            ivp_message(
              templat: "qh_findbest: point p%d starting at f%d bestoutside? %d newfacets %d\n",
              qh_qh.TRACEpoint,
              startfacet->id,
              bestoutside,
              newfacets);
            fprintf(
              str: qh_qh.ferr,
              format: "\n"
              "qh_findbest: all neighbors of facet %d are flipped or upper Delaunay.\n"
              "Please report this error to qhull_bug@geom.umn.edu with the input and all of the output.\n",
              startfacet->id);
            qh_qh.FORCEoutput = 1;
            qh_errexit(exitcode: 5, facet: startfacet, ridge: nullptr);
          }
          if ( ispartition != 0
            && qh_qh.findbest_notsharp == 0
            && COERCE_DOUBLE(*(_QWORD *)&qh_qh.DISTround ^ _mask__NegDouble_) > bestdist )
          {
            if ( qh_findbestsharp(point, &bestfacet, &bestdist, numpart) != 0 )
              qh_qh.findbestnew = 1;
            else
              qh_qh.findbest_notsharp = 1;
          }
          if ( testhorizon == 0 )
          {
LABEL_110:
            v26 = bestdist;
          }
          else
          {
            v25.p = (void *)bestfacet->neighbors->e[0];
            if ( qh_qh.IStracing >= 4 )
              fprintf(str: qh_qh.ferr, format: "qh_findbest: horizon facet f%d\n", *(_DWORD *)(v25.i + 76));
            ++*numpart;
            qh_distplane(point, facet: (facetT *)v25.p, dist);
            v26 = bestdist;
            if ( *dist > bestdist && ((*(_BYTE *)(v25.i + 82) & 1) == 0 || noupper == 0 && *dist >= qh_qh.MINoutside) )
            {
              v26 = *dist;
              bestfacet = (facetT *)v25.i;
            }
          }
          *dist = v26;
          if ( isoutside != nullptr && qh_qh.MINoutside > v26 )
            *isoutside = 0;
          goto LABELreturn_best;
        }
        v18 = cutoff;
        v16 = searchdist;
      }
      neighborp = (facetT **)neighbors->e;
      while ( 1 )
      {
        do
        {
          while ( 1 )
          {
            do
            {
              v11 = *neighborp++;
              if ( v11 == nullptr )
                goto LABEL_89;
            }
            while ( ispartition != 0 && (*((_DWORD *)v11 + 20) & 0x200) == 0 );
            if ( (*((_DWORD *)v11 + 20) & 0x8000) == 0 )
              break;
LABEL_84:
            v23 = searchsize++;
            if ( v23 != 0 )
            {
              qh_setappend(setp: &qh_qh.searchset, newelem: v11);
            }
            else
            {
              qh_qh.searchset->e[0].i = (int)v11;
              qh_settruncate(set: qh_qh.searchset, size: 1);
            }
          }
        }
        while ( v11->visitid == qh_qh.visit_id );
        v11->visitid = qh_qh.visit_id;
        ++*numpart;
        qh_distplane(point, facet: v11, dist);
        if ( bestoutside == 0 && *dist >= qh_qh.MINoutside && (noupper == 0 || (*((_BYTE *)facet + 82) & 1) == 0) )
        {
          qh_qh.IStracing = oldtrace;
          bestfacet = v11;
          return v11;
        }
        v21 = ischeckmax;
        if ( ischeckmax != 0
          && (qh_qh.ONLYgood == 0 || (*((_DWORD *)v11 + 20) & 0x40000) != 0)
          && *dist > v11->maxoutside )
        {
          break;
        }
        if ( bestfacet == nullptr || cutoff <= *dist )
          goto LABEL_73;
      }
      v11->maxoutside = *dist;
LABEL_73:
      v22 = *dist;
      if ( *dist > bestdist
        && ((*((_BYTE *)v11 + 82) & 1) == 0 || bestoutside != 0 && noupper == 0 && v22 >= qh_qh.MINoutside) )
      {
        bestfacet = v11;
        if ( v21 != 0 )
        {
          bestdist = v22;
          cutoff = v22 - searchdist;
          if ( v22 - searchdist > mincutoff )
            cutoff = mincutoff;
        }
        else
        {
          v16 = searchdist;
          if ( v22 > searchdist + bestdist )
          {
            bestdist = *dist;
            v18 = bestdist - searchdist;
            cutoff = bestdist - searchdist;
            searchsize = 0;
            facet = v11;
            if ( newbest == 0 )
              goto LABELrestart;
            continue;
          }
          bestdist = v22;
          cutoff = v22 - searchdist;
        }
        newbest = 1;
      }
      goto LABEL_84;
    }
  }
LABELreturn_best:
  qh_qh.IStracing = oldtrace;
  return bestfacet;
}

//------------------------------------------------------------------------------
// Address: 0x1005A1B0
// Name: struct facetT __near * qh_findbestnew(double __near *,struct facetT __near *,double __near *,unsigned int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
facetT *__cdecl qh_findbestnew(
        long double *point,
        facetT *startfacet,
        long double *dist,
        unsigned int *isoutside,
        int *numpart)
{
  facetT *newfacet_list; // esi
  unsigned int *v6; // edi
  double MINoutside; // xmm0_8
  double v9; // xmm0_8
  facetT *v11; // eax
  setT *neighbors; // eax
  setelemT v13; // esi
  setelemT *e; // edi
  double v15; // xmm0_8
  double bestdist2; // [esp+14h] [ebp-24h]
  double bestdist; // [esp+1Ch] [ebp-1Ch]
  double distoutside; // [esp+24h] [ebp-14h]
  int oldtrace; // [esp+2Ch] [ebp-Ch]
  facetT *bestfacet2; // [esp+30h] [ebp-8h]
  facetT *bestfacet; // [esp+34h] [ebp-4h]
  int i; // [esp+50h] [ebp+18h]

  newfacet_list = startfacet;
  bestdist = -1.797693134862316e308;
  bestdist2 = -1.797693134862316e308;
  bestfacet = nullptr;
  bestfacet2 = nullptr;
  oldtrace = qh_qh.IStracing;
  if ( startfacet == nullptr )
  {
    if ( qh_qh.MERGING != 0 )
      fprintf(
        str: qh_qh.ferr,
        format: "qhull precision error (qh_findbestnew): merging has formed and deleted an independent cycle of facets.  Can not continue.\n");
    else
      fprintf(
        str: qh_qh.ferr,
        format: "qhull internal error (qh_findbestnew): no new facets for point p%d\n",
        qh_qh.furthest_id);
    qh_errexit(exitcode: 5, facet: nullptr, ridge: nullptr);
  }
  if ( qh_qh.BESToutside != 0 || (v6 = isoutside, isoutside == nullptr) )
  {
    MINoutside = 1.797693134862316e308;
    v6 = isoutside;
  }
  else
  {
    MINoutside = qh_qh.MINoutside;
    if ( qh_qh.MERGING != 0 )
    {
      MINoutside = qh_qh.MINoutside * 4.0;
      if ( qh_qh.max_outside * 2.0 > qh_qh.MINoutside * 4.0 )
      {
        distoutside = qh_qh.max_outside * 2.0;
        goto LABEL_13;
      }
    }
  }
  distoutside = MINoutside;
LABEL_13:
  if ( qh_qh.TRACElevel != 0 && qh_qh.TRACEpoint >= 0 && qh_qh.TRACEpoint == qh_pointid(point) )
  {
    qh_qh.IStracing = qh_qh.TRACElevel;
    fprintf(
      str: qh_qh.ferr,
      format: "qh_findbestnew: point p%d facet f%d. Stop if dist > %2.2g\n",
      qh_qh.TRACEpoint,
      startfacet->id,
      distoutside);
    fprintf(str: qh_qh.ferr, format: "  Last point added to hull was p%d.", qh_qh.furthest_id);
    fprintf(str: qh_qh.ferr, format: "  Last merge was #%d.\n", qh_qhstat.stats[176].i);
  }
  if ( v6 != nullptr )
    *v6 = 1;
  *numpart = 0;
  for ( i = 0; i < 2; ++i )
  {
    if ( newfacet_list != nullptr )
    {
      while ( newfacet_list->next != nullptr && (newfacet_list != startfacet || i == 0) )
      {
        qh_distplane(point, facet: newfacet_list, dist);
        ++*numpart;
        v9 = *dist;
        if ( (*((_BYTE *)newfacet_list + 82) & 1) != 0 )
        {
          if ( v9 > bestdist2 )
          {
            bestdist2 = *dist;
            bestfacet2 = newfacet_list;
            if ( v9 >= distoutside )
            {
              qh_qh.IStracing = oldtrace;
              return newfacet_list;
            }
          }
        }
        else if ( v9 > bestdist )
        {
          bestdist = *dist;
          bestfacet = newfacet_list;
          if ( v9 >= distoutside )
            goto LABELreturn_bestnew;
        }
        newfacet_list = newfacet_list->next;
        if ( newfacet_list == nullptr )
          break;
      }
    }
    newfacet_list = qh_qh.newfacet_list;
  }
  v11 = bestfacet;
  if ( bestfacet == nullptr )
    v11 = bestfacet2;
  neighbors = v11->neighbors;
  if ( neighbors != nullptr )
  {
    v13.p = (void *)neighbors->e[0];
    e = neighbors->e;
    if ( v13.i != 0 )
    {
      do
      {
        ++e;
        if ( (*(_DWORD *)(v13.i + 80) & 0x200) == 0 )
        {
          qh_distplane(point, facet: (facetT *)v13.p, dist);
          ++*numpart;
          if ( (*(_BYTE *)(v13.i + 82) & 1) != 0 )
          {
            if ( *dist > bestdist2 )
            {
              bestdist2 = *dist;
              bestfacet2 = (facetT *)v13.i;
            }
          }
          else if ( *dist > bestdist )
          {
            bestdist = *dist;
            bestfacet = (facetT *)v13.i;
          }
        }
        v13.p = e->p;
      }
      while ( e->i != 0 );
    }
  }
  if ( bestfacet != nullptr )
  {
    if ( isoutside == nullptr || (v15 = bestdist2, bestdist2 < qh_qh.MINoutside) || bestdist2 <= bestdist )
    {
      *dist = bestdist;
      goto LABEL_50;
    }
  }
  else
  {
    v15 = bestdist2;
  }
  *dist = v15;
  bestfacet = bestfacet2;
LABEL_50:
  if ( isoutside != nullptr && qh_qh.MINoutside > *dist )
    *isoutside = 0;
LABELreturn_bestnew:
  qh_qh.IStracing = oldtrace;
  return bestfacet;
}

//------------------------------------------------------------------------------
// Address: 0x1005A4A0
// Name: void qh_gausselim(double __near * __near *,int,int,unsigned int __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_gausselim(long double **rows, int numrow, int numcol, unsigned int *sign, unsigned int *nearzero)
{
  int v5; // eax
  int v6; // esi
  double v7; // xmm2_8
  __int64 v8; // xmm3_8
  int v9; // ebx
  long double **v10; // ecx
  double v11; // xmm0_8
  int v12; // edi
  int v13; // eax
  long double **v14; // edx
  double v15; // xmm0_8
  double v16; // xmm0_8
  double v17; // xmm0_8
  double v18; // xmm0_8
  int v19; // edx
  double v20; // xmm0_8
  long double *v21; // eax
  long double *v22; // esi
  double v23; // xmm0_8
  char *v24; // esi
  double v25; // xmm1_8
  long double *v26; // eax
  double v27; // xmm0_8
  int v28; // ecx
  double *v29; // eax
  double *v30; // edx
  double i; // xmm0_8
  double pivot_abs; // [esp+1Ch] [ebp-1Ch]
  int v33; // [esp+28h] [ebp-10h]
  int v34; // [esp+2Ch] [ebp-Ch]
  int v35; // [esp+30h] [ebp-8h]
  int pivoti; // [esp+34h] [ebp-4h]

  *nearzero = 0;
  v5 = numrow;
  v6 = 0;
  v7 = 0.0;
  if ( numrow > 0 )
  {
    v8 = _mask__NegDouble_;
    v9 = 0;
    v33 = 0;
    v35 = numcol - 1;
    while ( 1 )
    {
      v10 = rows;
      v11 = *(long double *)((char *)rows[v6] + v9);
      if ( v11 < 0.0 )
        *(_QWORD *)&v11 ^= v8;
      v12 = v6 + 1;
      v7 = v11;
      pivot_abs = v11;
      pivoti = v6;
      v34 = v6 + 1;
      v13 = v6 + 1;
      if ( v6 + 1 < numrow )
      {
        if ( v35 + numrow - numcol >= 4 )
        {
          v14 = &rows[v6 + 3];
          do
          {
            v15 = *(long double *)((char *)*(v14 - 2) + v9);
            if ( v15 < 0.0 )
              *(_QWORD *)&v15 ^= v8;
            if ( v15 > v7 )
            {
              v7 = v15;
              pivoti = v13;
            }
            v16 = *(long double *)((char *)*(v14 - 1) + v9);
            if ( v16 < 0.0 )
              *(_QWORD *)&v16 ^= v8;
            if ( v16 > v7 )
            {
              v7 = v16;
              pivoti = v13 + 1;
            }
            v17 = *(long double *)((char *)*v14 + v9);
            if ( v17 < 0.0 )
              *(_QWORD *)&v17 ^= v8;
            if ( v17 > v7 )
            {
              v7 = v17;
              pivoti = v13 + 2;
            }
            v18 = *(long double *)((char *)v14[1] + v9);
            if ( v18 < 0.0 )
              *(_QWORD *)&v18 ^= v8;
            if ( v18 > v7 )
            {
              v7 = v18;
              pivoti = v13 + 3;
            }
            v13 += 4;
            v14 += 4;
          }
          while ( v13 < numrow - 3 );
          pivot_abs = v7;
        }
        v19 = pivoti;
        if ( v13 < numrow )
        {
          do
          {
            v20 = *(long double *)((char *)rows[v13] + v9);
            if ( v20 < 0.0 )
              *(_QWORD *)&v20 ^= v8;
            if ( v20 > v7 )
            {
              v7 = v20;
              v19 = v13;
            }
            ++v13;
          }
          while ( v13 < numrow );
          pivot_abs = v7;
        }
        if ( v19 != v6 )
        {
          v21 = rows[v19];
          rows[v19] = rows[v6];
          rows[v6] = v21;
          *sign ^= 1u;
        }
        v12 = v6 + 1;
      }
      if ( *(double *)((char *)qh_qh.NEARzero + v9) >= v7 )
      {
        *nearzero = 1;
        if ( v7 == 0.0 )
          break;
      }
      v22 = rows[v6];
      v23 = *(long double *)((char *)v22 + v9);
      v24 = (char *)v22 + v9;
      if ( v12 < numrow )
      {
        v25 = 1.0 / v23;
        while ( 1 )
        {
          v26 = v10[v12];
          v27 = *(long double *)((char *)v26 + v9);
          v28 = v35;
          v29 = (long double *)((char *)v26 + v9 + 8);
          v30 = (double *)(v24 + 8);
          for ( i = v27 * v25; v28 != 0; --v28 )
          {
            *v29 = *v29 - i * *v30++;
            ++v29;
          }
          v9 = v33;
          if ( ++v12 >= numrow )
            break;
          v10 = rows;
        }
        v12 = v34;
        goto LABEL_48;
      }
LABELnextcol:
      --v35;
      v6 = v12;
      v9 += 8;
      v33 = v9;
      if ( v12 >= numrow )
      {
        v5 = numrow;
        goto LABEL_52;
      }
    }
    if ( qh_qh.IStracing >= 4 )
    {
      ivp_message(templat: "qh_gausselim: 0 pivot at column %d. (%2.2g < %2.2g)\n", v6, v7, (double)qh_qh.DISTround);
      qh_printmatrix(fp: qh_qh.ferr, string: "Matrix:", rows, numrow, numcol);
    }
    ++qh_qhstat.stats[80].i;
    qh_precision(reason: "zero pivot for Gaussian elimination");
    v8 = _mask__NegDouble_;
    v7 = pivot_abs;
LABEL_48:
    v10 = rows;
    goto LABELnextcol;
  }
  v10 = rows;
LABEL_52:
  if ( qh_qhstat.stats[115].r > v7 )
    qh_qhstat.stats[115].r = v7;
  if ( qh_qh.IStracing >= 5 )
    qh_printmatrix(fp: qh_qh.ferr, string: "qh_gausselem: result", rows: v10, numrow: v5, numcol);
}

//------------------------------------------------------------------------------
// Address: 0x1005A780
// Name: double qh_getangle(double __near *,double __near *)
// Source: json
//------------------------------------------------------------------------------
double __cdecl qh_getangle(long double *vect1, long double *vect2)
{
  int hull_dim; // ecx
  double v3; // xmm0_8
  double *v4; // eax
  double v5; // xmm1_8
  double angle; // [esp+8h] [ebp-8h]

  hull_dim = qh_qh.hull_dim;
  v3 = 0.0;
  angle = 0.0;
  if ( qh_qh.hull_dim != 0 )
  {
    v4 = vect2;
    do
    {
      v5 = *(double *)((char *)v4 + (char *)vect1 - (char *)vect2) * *v4;
      ++v4;
      --hull_dim;
      v3 = v3 + v5;
    }
    while ( hull_dim != 0 );
    angle = v3;
  }
  if ( qh_qh.RANDOMdist != 0 )
  {
    v3 = ((double)qh_rand() * 2.0 * 4.656612877414201e-10 - 1.0) * qh_qh.RANDOMfactor + angle;
    angle = v3;
  }
  if ( qh_qh.IStracing >= 4 )
    fprintf(str: qh_qh.ferr, format: "qh_getangle: %2.2g\n", v3);
  return angle;
}

//------------------------------------------------------------------------------
// Address: 0x1005A830
// Name: double __near * qh_getcenter(struct setT __near *)
// Source: json
//------------------------------------------------------------------------------
long double *__cdecl qh_getcenter(setT *vertices)
{
  int v1; // eax
  int v2; // esi
  long double *result; // eax
  int v4; // edi
  double v5; // xmm0_8
  long double *v6; // edx
  setelemT v7; // ecx
  setelemT *i; // esi
  double v9; // xmm2_8

  v1 = qh_setsize(set: vertices);
  v2 = v1;
  if ( v1 < 2 )
  {
    ivp_message(templat: "qhull internal error (qh_getcenter): not defined for %d points\n", v1);
    qh_errexit(exitcode: 5, facet: nullptr, ridge: nullptr);
  }
  result = (long double *)qh_memalloc(insize: qh_qh.normal_size);
  v4 = 0;
  if ( qh_qh.hull_dim > 0 )
  {
    v5 = 1.0 / (double)v2;
    v6 = result;
    do
    {
      *v6 = 0.0;
      if ( vertices != nullptr )
      {
        v7.p = (void *)vertices->e[0];
        for ( i = vertices->e; v7.i != 0; *v6 = v9 + *v6 )
        {
          v9 = *(double *)(*(_DWORD *)(v7.i + 8) + 8 * v4);
          v7.p = i[1].p;
          ++i;
        }
      }
      *v6 = v5 * *v6;
      ++v4;
      ++v6;
    }
    while ( v4 < qh_qh.hull_dim );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1005A8E0
// Name: double qh_getdistance(struct facetT __near *,struct facetT __near *,double __near *,double __near *)
// Source: json
//------------------------------------------------------------------------------
double __cdecl qh_getdistance(facetT *facet, facetT *neighbor, long double *mindist, long double *maxdist)
{
  double v4; // xmm0_8
  setT *vertices; // eax
  setelemT *e; // ecx
  setelemT v7; // eax
  setT *v8; // eax
  setelemT *v9; // ecx
  setelemT v10; // eax
  setT *v11; // eax
  double v12; // xmm1_8
  setelemT *v13; // esi
  setelemT v14; // eax
  double dist; // [esp+0h] [ebp-18h] BYREF
  double mind; // [esp+8h] [ebp-10h]
  double maxd; // [esp+10h] [ebp-8h]

  v4 = 0.0;
  vertices = facet->vertices;
  dist = 0.0;
  if ( vertices != nullptr )
  {
    e = vertices->e;
    for ( v7.p = (void *)vertices->e[0]; v7.i != 0; ++e )
    {
      *(_DWORD *)(v7.i + 20) &= ~0x1000000u;
      v7.p = e[1].p;
    }
  }
  v8 = neighbor->vertices;
  if ( v8 != nullptr )
  {
    v9 = v8->e;
    for ( v10.p = (void *)v8->e[0]; v10.i != 0; ++v9 )
    {
      *(_DWORD *)(v10.i + 20) |= 0x1000000u;
      v10.p = v9[1].p;
    }
  }
  v11 = facet->vertices;
  v12 = 0.0;
  mind = 0.0;
  maxd = 0.0;
  if ( v11 != nullptr )
  {
    v13 = v11->e;
    v14.p = (void *)v11->e[0];
    if ( v14.i != 0 )
    {
      do
      {
        ++v13;
        if ( (*(_BYTE *)(v14.i + 23) & 1) == 0 )
        {
          ++qh_qhstat.stats[16].i;
          qh_distplane(point: *(long double **)(v14.i + 8), facet: neighbor, &dist);
          v4 = mind;
          if ( mind <= dist )
          {
            if ( dist > maxd )
              maxd = dist;
          }
          else
          {
            v4 = dist;
            mind = dist;
          }
        }
        v14.p = v13->p;
      }
      while ( v13->i != 0 );
      v12 = maxd;
    }
  }
  *mindist = v4;
  *maxdist = v12;
  mind = -v4;
  if ( v12 <= -v4 )
    return mind;
  else
    return maxd;
}

//------------------------------------------------------------------------------
// Address: 0x1005A9F0
// Name: void qh_normalize2(double __near *,int,unsigned int,double __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_normalize2(
        long double *normal,
        int dim,
        unsigned int toporient,
        long double *minnorm,
        unsigned int *ismin)
{
  int v6; // edi
  double denom; // xmm0_8
  int v8; // eax
  double v9; // xmm0_8
  double *v10; // ecx
  double v11; // xmm1_8
  double v12; // xmm1_8
  double v13; // xmm1_8
  int v14; // ecx
  double *v15; // eax
  double v16; // xmm0_8
  double *v17; // ebx
  double *v18; // edx
  __int64 v19; // xmm0_8
  double temp; // [esp+28h] [ebp-10h]
  double norm; // [esp+30h] [ebp-8h]
  int k; // [esp+40h] [ebp+8h]

  v6 = dim;
  denom = 0.0;
  norm = 0.0;
  switch ( dim )
  {
    case 2:
      denom = sqrt(normal[1] * normal[1] + *normal * *normal);
      break;
    case 3:
      denom = sqrt(normal[1] * normal[1] + *normal * *normal + normal[2] * normal[2]);
      break;
    case 4:
      denom = sqrt(normal[1] * normal[1] + *normal * *normal + normal[2] * normal[2] + normal[3] * normal[3]);
      break;
    default:
      if ( dim <= 4 )
        goto LABEL_12;
      v8 = dim - 4;
      v9 = normal[1] * normal[1] + *normal * *normal + normal[2] * normal[2] + normal[3] * normal[3];
      v10 = normal + 4;
      do
      {
        v11 = *v10++;
        --v8;
        v12 = v11 * v11 + v9;
        v9 = v12;
      }
      while ( v8 != 0 );
      denom = sqrt(v12);
      break;
  }
  norm = denom;
LABEL_12:
  if ( minnorm != nullptr )
    *ismin = *minnorm > denom;
  if ( qh_qhstat.stats[115].r > denom )
    qh_qhstat.stats[115].r = denom;
  if ( denom <= qh_qh.MINdenom )
  {
    if ( denom == 0.0 )
    {
      v16 = sqrt(1.0 / (double)v6);
      if ( v6 != 0 )
      {
        *normal = v16;
        qmemcpy(normal + 1, normal, 4 * ((unsigned int)(8 * v6 - 5) >> 2));
      }
    }
    else
    {
      if ( toporient == 0 )
      {
        denom = -denom;
        norm = denom;
      }
      k = v6;
      v17 = normal;
      if ( v6 != 0 )
      {
        while ( 1 )
        {
          --k;
          temp = qh_divzero(numer: *v17, denom, mindenom1: qh_qh.MINdenom_1, zerodiv: (unsigned int *)&dim);
          if ( dim != 0 )
            break;
          *v17++ = temp;
          if ( k == 0 )
            return;
          denom = norm;
        }
        v18 = qh_maxabsval(normal, dim: v6);
        if ( *v18 * norm < 0.0 )
          v19 = 0xBFF0000000000000uLL;
        else
          v19 = 0x3FF0000000000000LL;
        memset(normal, 0, 8 * v6);
        *(_QWORD *)v18 = v19;
        ++qh_qhstat.stats[119].i;
        if ( qh_qh.IStracing != 0 )
          fprintf(str: qh_qh.ferr, format: "qh_normalize: norm=%2.2g too small during p%d\n", norm, qh_qh.furthest_id);
      }
    }
  }
  else
  {
    if ( toporient == 0 )
      denom = -denom;
    v13 = 1.0 / denom;
    *normal = *normal * (1.0 / denom);
    normal[1] = normal[1] * (1.0 / denom);
    if ( v6 != 2 )
    {
      if ( v6 == 3 )
      {
        normal[2] = v13 * normal[2];
      }
      else if ( v6 == 4 )
      {
        normal[2] = v13 * normal[2];
        normal[3] = v13 * normal[3];
      }
      else if ( v6 > 4 )
      {
        normal[2] = v13 * normal[2];
        v14 = v6 - 4;
        normal[3] = v13 * normal[3];
        v15 = normal + 4;
        do
        {
          *v15 = *v15 * v13;
          ++v15;
          --v14;
        }
        while ( v14 != 0 );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005AD40
// Name: double __near * qh_projectpoint(double __near *,struct facetT __near *,double)
// Source: json
//------------------------------------------------------------------------------
long double *__cdecl qh_projectpoint(long double *point, facetT *facet, long double dist)
{
  void **v3; // ecx
  long double *result; // eax
  int hull_dim; // edx
  long double *v6; // ecx
  int v7; // edi

  v3 = &qhmem.freelists[qhmem.indextable[qh_qh.normal_size]];
  result = (long double *)*v3;
  if ( *v3 != nullptr )
  {
    ++qhmem.cntquick;
    *v3 = *(void **)*v3;
  }
  else
  {
    result = (long double *)qh_memalloc(insize: qh_qh.normal_size);
  }
  hull_dim = qh_qh.hull_dim;
  v6 = result;
  if ( qh_qh.hull_dim != 0 )
  {
    v7 = (char *)facet->normal - (char *)result;
    do
    {
      *v6 = *(long double *)((char *)v6 + (char *)point - (char *)result) - *(long double *)((char *)v6 + v7) * dist;
      ++v6;
      --hull_dim;
    }
    while ( hull_dim != 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1005ADC0
// Name: void qh_sethyperplane_det(int,double __near * __near *,double __near *,unsigned int,double __near *,double __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_sethyperplane_det(
        int dim,
        long double **rows,
        long double *point0,
        unsigned int toporient,
        long double *normal,
        long double *offset,
        unsigned int *nearzero)
{
  long double *v7; // eax
  double *v8; // ecx
  double *v9; // ecx
  long double *v10; // eax
  long double *v11; // edx
  double v12; // xmm0_8
  int v13; // edx
  long double *v14; // ecx
  double v15; // xmm1_8
  double *v16; // eax
  long double *v17; // ecx
  long double *v18; // edx
  long double *v19; // esi
  double v20; // xmm1_8
  double v21; // xmm6_8
  double v22; // xmm3_8
  double v23; // xmm1_8
  double v24; // xmm6_8
  double v25; // xmm6_8
  double v26; // xmm5_8
  double v27; // xmm7_8
  double v28; // xmm6_8
  double v29; // xmm5_8
  double v30; // xmm7_8
  double v31; // xmm0_8
  int v32; // edx
  long double *v33; // ecx
  double v34; // xmm1_8

  switch ( dim )
  {
    case 2:
      v7 = rows[1];
      v8 = *rows;
      *normal = v7[1] - (*rows)[1];
      normal[1] = *v8 - *v7;
      qh_normalize2(normal, dim: 2, toporient, minnorm: nullptr, ismin: nullptr);
      *offset = -(point0[1] * normal[1] + *point0 * *normal);
      *nearzero = 0;
      return;
    case 3:
      v9 = *rows;
      v10 = rows[1];
      v11 = rows[2];
      *normal = (v11[1] - (*rows)[1]) * (v10[2] - (*rows)[2]) - (v10[1] - (*rows)[1]) * (v11[2] - (*rows)[2]);
      normal[1] = (*v10 - *v9) * (v11[2] - v9[2]) - (*v11 - *v9) * (v10[2] - v9[2]);
      normal[2] = (*v11 - *v9) * (v10[1] - v9[1]) - (*v10 - *v9) * (v11[1] - v9[1]);
      qh_normalize2(normal, dim: 3, toporient, minnorm: nullptr, ismin: nullptr);
      *(_QWORD *)&v12 = COERCE_UNSIGNED_INT64(point0[1] * normal[1] + *point0 * *normal + point0[2] * normal[2])
                      ^ _mask__NegDouble_;
      *offset = v12;
      v13 = 3;
      while ( 1 )
      {
        v14 = rows[--v13];
        if ( v14 != point0 )
        {
          v15 = v14[1] * normal[1] + *normal * *v14 + v14[2] * normal[2] + v12;
          if ( v15 > qh_qh.DISTround || COERCE_DOUBLE(*(_QWORD *)&qh_qh.DISTround ^ _mask__NegDouble_) > v15 )
            break;
        }
        if ( v13 == 0 )
          goto LABEL_17;
      }
      break;
    case 4:
      v16 = *rows;
      v17 = rows[3];
      v18 = rows[1];
      v19 = rows[2];
      v20 = (*rows)[2];
      v21 = (*rows)[3];
      v22 = v18[2];
      *(_QWORD *)normal = COERCE_UNSIGNED_INT64(
                            ((v22 - v20) * (v17[3] - v21) - (v17[2] - v20) * (v18[3] - v21)) * (v19[1] - v16[1])
                          - ((v19[2] - v20) * (v17[3] - v21) - (v19[3] - v21) * (v17[2] - v20)) * (v18[1] - (*rows)[1])
                          + ((v19[2] - v20) * (v18[3] - v21) - (v19[3] - v21) * (v22 - v20)) * (v17[1] - v16[1]))
                        ^ _mask__NegDouble_;
      v23 = v16[2];
      v24 = v16[3];
      normal[1] = ((v18[2] - v23) * (v17[3] - v24) - (v17[2] - v23) * (v18[3] - v24)) * (*v19 - *v16)
                - ((v19[2] - v23) * (v17[3] - v24) - (v19[3] - v24) * (v17[2] - v23)) * (*v18 - *v16)
                + ((v19[2] - v23) * (v18[3] - v24) - (v19[3] - v24) * (v18[2] - v23)) * (*v17 - *v16);
      v25 = v16[1];
      v26 = v16[3];
      v27 = *v16;
      *((_QWORD *)normal + 2) = COERCE_UNSIGNED_INT64(
                                  ((v18[1] - v25) * (v17[3] - v26) - (v17[1] - v25) * (v18[3] - v26)) * (*v19 - v27)
                                - ((v19[1] - v25) * (v17[3] - v26) - (v17[1] - v25) * (v19[3] - v26)) * (*v18 - v27)
                                + ((v19[1] - v25) * (v18[3] - v26) - (v18[1] - v25) * (v19[3] - v26)) * (*v17 - v27))
                              ^ _mask__NegDouble_;
      v28 = v16[1];
      v29 = v16[2];
      v30 = *v16;
      normal[3] = ((v18[1] - v28) * (v17[2] - v29) - (v17[1] - v28) * (v18[2] - v29)) * (*v19 - v30)
                - ((v19[1] - v28) * (v17[2] - v29) - (v17[1] - v28) * (v19[2] - v29)) * (*v18 - v30)
                + ((v19[1] - v28) * (v18[2] - v29) - (v18[1] - v28) * (v19[2] - v29)) * (*v17 - v30);
      qh_normalize2(normal, dim: 4, toporient, minnorm: nullptr, ismin: nullptr);
      *(_QWORD *)&v31 = COERCE_UNSIGNED_INT64(point0[1] * normal[1] + *point0 * *normal + point0[2] * normal[2] + point0[3] * normal[3])
                      ^ _mask__NegDouble_;
      *offset = v31;
      v32 = 4;
      while ( 1 )
      {
        v33 = rows[--v32];
        if ( v33 != point0 )
        {
          v34 = v33[1] * normal[1] + *normal * *v33 + v33[2] * normal[2] + v33[3] * normal[3] + v31;
          if ( v34 > qh_qh.DISTround || COERCE_DOUBLE(*(_QWORD *)&qh_qh.DISTround ^ _mask__NegDouble_) > v34 )
            break;
        }
        if ( v32 == 0 )
          goto LABEL_17;
      }
      break;
    default:
LABEL_17:
      if ( *nearzero == 0 )
        return;
      goto LABEL_18;
  }
  *nearzero = 1;
LABEL_18:
  ++qh_qhstat.stats[117].i;
  if ( qh_qh.IStracing != 0 )
    fprintf(str: qh_qh.ferr, format: "qh_sethyperplane_det: degenerate norm during p%d.\n", qh_qh.furthest_id);
  ++qh_qhstat.stats[119].i;
}

//------------------------------------------------------------------------------
// Address: 0x1005B3A0
// Name: void qh_sethyperplane_gauss(int,double __near * __near *,double __near *,unsigned int,double __near *,double __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_sethyperplane_gauss(
        int dim,
        long double **rows,
        long double *point0,
        unsigned int toporient,
        long double *normal,
        long double *offset,
        unsigned int *nearzero)
{
  int v7; // edi
  int v8; // eax
  long double *v9; // ecx
  long double *v10; // esi
  double *v11; // edx
  long double v12; // xmm0_8
  int v13; // ecx
  long double *v14; // esi
  double *v15; // eax
  int v16; // esi
  double v17; // xmm0_8
  unsigned int nearzero2; // [esp+Ch] [ebp-4h] BYREF

  v7 = dim - 1;
  nearzero2 = 0;
  qh_gausselim(rows, numrow: dim - 1, numcol: dim, sign: &toporient, nearzero);
  v8 = dim - 1;
  if ( dim != 1 )
  {
    do
    {
      v9 = rows[--v8];
      if ( v9[v8] < 0.0 )
        toporient ^= 1u;
    }
    while ( v8 != 0 );
  }
  if ( *nearzero != 0 )
  {
    ++qh_qhstat.stats[119].i;
    if ( qh_qh.IStracing != 0 )
      fprintf(
        str: qh_qh.ferr,
        format: "qh_sethyperplane_gauss: nearly singular or axis parallel hyperplane during p%d.\n",
        qh_qh.furthest_id);
    v10 = normal;
    qh_backnormal(rows, numrow: v7, numcol: dim, sign: toporient, normal, nearzero: &nearzero2);
  }
  else
  {
    v10 = normal;
    qh_backnormal(rows, numrow: v7, numcol: dim, sign: toporient, normal, nearzero: &nearzero2);
    if ( nearzero2 == 0 )
      goto LABEL_14;
    ++qh_qhstat.stats[119].i;
    if ( qh_qh.IStracing != 0 )
      fprintf(
        str: qh_qh.ferr,
        format: "qh_sethyperplane_gauss: singular or axis parallel hyperplane at normalization during p%d.\n",
        qh_qh.furthest_id);
  }
  if ( nearzero2 != 0 )
    *nearzero = 1;
LABEL_14:
  qh_normalize2(normal: v10, dim, toporient: 1u, minnorm: nullptr, ismin: nullptr);
  v11 = offset;
  v12 = -(*point0 * *v10);
  v13 = dim - 1;
  v14 = v10 + 1;
  v15 = point0 + 1;
  *offset = v12;
  if ( dim != 1 )
  {
    v16 = (char *)v14 - (char *)v15;
    do
    {
      v17 = *(double *)((char *)v15 + v16) * *v15;
      ++v15;
      --v13;
      *v11 = *v11 - v17;
    }
    while ( v13 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005B500
// Name: double __near * qh_getcentrum(struct facetT __near *)
// Source: json
//------------------------------------------------------------------------------
long double *__cdecl qh_getcentrum(facetT *facet)
{
  setT *vertices; // eax
  long double *v2; // eax
  long double *v3; // edi
  long double *v4; // ebx
  int v5; // eax
  double v7; // [esp+0h] [ebp-1Ch]
  double dist; // [esp+14h] [ebp-8h] BYREF

  vertices = facet->vertices;
  dist = 0.0;
  v2 = qh_getcenter(vertices);
  ++qh_qhstat.stats[17].i;
  v3 = v2;
  qh_distplane(point: v2, facet, &dist);
  v4 = qh_projectpoint(point: v3, facet, dist);
  qh_memfree(object: (void **)v3, size: qh_qh.normal_size);
  if ( qh_qh.IStracing >= 4 )
  {
    v7 = dist;
    v5 = qh_setsize(set: facet->vertices);
    fprintf(str: qh_qh.ferr, format: "qh_getcentrum: for f%d, %d vertices dist= %2.2g\n", facet->id, v5, v7);
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1005B5A0
// Name: void qh_normalize(double __near *,int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_normalize(long double *normal, int dim, unsigned int toporient)
{
  qh_normalize2(normal, dim, toporient, minnorm: nullptr, ismin: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1005B5C0
// Name: void qh_setfacetplane(struct facetT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_setfacetplane(facetT *facet)
{
  unsigned int normal_size; // edx
  facetT *v2; // edi
  long double *v3; // eax
  long double **v4; // eax
  long double *v5; // ecx
  int IStracing; // edx
  setT *vertices; // edx
  long double *gm_matrix; // ebx
  vertexT *p; // eax
  vertexT **e; // edx
  int v11; // ecx
  int hull_dim; // esi
  double *point; // edi
  long double v14; // st7
  setT *v15; // ecx
  setelemT v16; // eax
  setelemT *v17; // ecx
  int v18; // edx
  setT *v19; // ecx
  long double *v20; // eax
  int v21; // esi
  vertexT **v22; // ebx
  vertexT *v23; // ecx
  double *v24; // edx
  int v25; // ecx
  char *v26; // ebx
  int v27; // eax
  long double *v28; // ebx
  int v29; // esi
  long double v30; // st7
  double v31; // xmm1_8
  setT *v32; // eax
  setelemT v33; // esi
  setelemT *v34; // ebx
  double v35; // xmm0_8
  bool v36; // cc
  int v37; // eax
  int j; // esi
  int v39; // [esp-4h] [ebp-38h]
  unsigned int v40; // [esp+8h] [ebp-2Ch]
  unsigned int id; // [esp+Ch] [ebp-28h]
  int furthest_id; // [esp+Ch] [ebp-28h]
  double dist; // [esp+1Ch] [ebp-18h] BYREF
  int oldtrace; // [esp+24h] [ebp-10h]
  vertexT **vertexp; // [esp+28h] [ebp-Ch]
  unsigned int nearzero; // [esp+2Ch] [ebp-8h] BYREF
  long double *point0; // [esp+30h] [ebp-4h]
  int i; // [esp+3Ch] [ebp+8h]

  normal_size = qh_qh.normal_size;
  v2 = facet;
  v3 = *(long double **)(facet->vertices->e[0].i + 8);
  ++qh_qhstat.stats[172].i;
  oldtrace = 0;
  point0 = v3;
  nearzero = 0;
  if ( facet->normal == nullptr )
  {
    v4 = (long double **)&qhmem.freelists[qhmem.indextable[qh_qh.normal_size]];
    v5 = *v4;
    facet->normal = *v4;
    if ( v5 != nullptr )
    {
      ++qhmem.cntquick;
      *v4 = *(long double **)*v4;
    }
    else
    {
      facet->normal = (long double *)qh_memalloc(insize: normal_size);
    }
  }
  if ( facet == qh_qh.tracefacet )
  {
    IStracing = qh_qh.IStracing;
    qh_qh.IStracing = 5;
    id = facet->id;
    oldtrace = IStracing;
    ivp_message(templat: "qh_setfacetplane: facet f%d created.\n", id);
    ivp_message(templat: "  Last point added to hull was p%d.", qh_qh.furthest_id);
    if ( qh_qhstat.stats[176].i != 0 )
      fprintf(str: qh_qh.ferr, format: "  Last merge was #%d.", qh_qhstat.stats[176].i);
    ivp_message(templat: "\n\nCurrent summary is:\n");
    qh_printsummary(fp: qh_qh.ferr);
  }
  if ( qh_qh.hull_dim > 4 )
    goto LABEL_25;
  if ( qh_qh.RANDOMdist != 0 )
  {
    vertices = facet->vertices;
    gm_matrix = qh_qh.gm_matrix;
    if ( vertices != nullptr )
    {
      p = (vertexT *)vertices->e[0].p;
      e = (vertexT **)vertices->e;
      if ( p != nullptr )
      {
        v11 = 0;
        do
        {
          *(long double **)((char *)qh_qh.gm_row + v11) = gm_matrix;
          hull_dim = qh_qh.hull_dim;
          point = p->point;
          ++e;
          v11 += 4;
          vertexp = e;
          HIDWORD(dist) = v11;
          if ( qh_qh.hull_dim != 0 )
          {
            do
            {
              v14 = qh_randomfactor() * *point;
              ++gm_matrix;
              ++point;
              --hull_dim;
              *(gm_matrix - 1) = v14;
            }
            while ( hull_dim != 0 );
            v11 = HIDWORD(dist);
            e = vertexp;
          }
          p = *e;
        }
        while ( *e != nullptr );
        v2 = facet;
      }
    }
  }
  else
  {
    v15 = facet->vertices;
    if ( v15 != nullptr )
    {
      v16.p = (void *)v15->e[0];
      v17 = v15->e;
      if ( v16.i != 0 )
      {
        v18 = 0;
        do
        {
          ++v17;
          qh_qh.gm_row[v18] = *(long double **)(v16.i + 8);
          v16.p = v17->p;
          ++v18;
        }
        while ( v17->i != 0 );
      }
    }
  }
  qh_sethyperplane_det(
    dim: qh_qh.hull_dim,
    rows: qh_qh.gm_row,
    point0,
    toporient: (*((_DWORD *)v2 + 20) & 0x800) != 0,
    normal: v2->normal,
    offset: &v2->offset,
    &nearzero);
  if ( qh_qh.hull_dim > 4 || nearzero != 0 )
  {
LABEL_25:
    v19 = v2->vertices;
    v20 = qh_qh.gm_matrix;
    v21 = 0;
    if ( v19 != nullptr )
    {
      v22 = (vertexT **)v19->e;
      v23 = (vertexT *)v19->e[0].p;
      if ( v23 != nullptr )
      {
        do
        {
          vertexp = ++v22;
          if ( v23->point != point0 )
          {
            qh_qh.gm_row[v21] = v20;
            v24 = v23->point;
            v25 = qh_qh.hull_dim;
            ++v21;
            if ( qh_qh.hull_dim != 0 )
            {
              v26 = (char *)((char *)point0 - (char *)v20);
              do
              {
                *v20 = *v24 - *(double *)((char *)v20 + (_DWORD)v26);
                ++v20;
                ++v24;
                --v25;
              }
              while ( v25 != 0 );
              v22 = vertexp;
            }
          }
          v23 = *v22;
        }
        while ( *v22 != nullptr );
      }
    }
    qh_qh.gm_row[v21] = v20;
    if ( qh_qh.RANDOMdist != 0 )
    {
      v27 = qh_qh.hull_dim - 1;
      v28 = qh_qh.gm_matrix;
      if ( qh_qh.hull_dim != 1 )
      {
        do
        {
          v29 = qh_qh.hull_dim;
          i = --v27;
          if ( qh_qh.hull_dim != 0 )
          {
            do
            {
              v30 = qh_randomfactor() * *v28++;
              --v29;
              *(v28 - 1) = v30;
            }
            while ( v29 != 0 );
            v27 = i;
          }
        }
        while ( v27 != 0 );
      }
    }
    qh_sethyperplane_gauss(
      dim: qh_qh.hull_dim,
      rows: qh_qh.gm_row,
      point0,
      toporient: (*((_DWORD *)v2 + 20) & 0x800) != 0,
      normal: v2->normal,
      offset: &v2->offset,
      &nearzero);
    if ( nearzero != 0 && qh_orientoutside(facet: v2) != 0 && qh_qh.IStracing != 0 )
      fprintf(
        str: qh_qh.ferr,
        format: "qh_setfacetplane: flipped orientation after testing interior_point during p%d\n",
        qh_qh.furthest_id);
  }
  *((_DWORD *)v2 + 20) &= ~0x10000u;
  if ( qh_qh.DELAUNAY != 0 )
  {
    v31 = v2->normal[qh_qh.hull_dim - 1];
    if ( qh_qh.UPPERdelaunay != 0 )
    {
      if ( v31 >= qh_qh.ANGLEround * 2.0 )
        goto LABEL_48;
    }
    else if ( v31 > qh_qh.ANGLEround * -2.0 )
    {
LABEL_48:
      *((_DWORD *)v2 + 20) |= 0x10000u;
    }
  }
  if ( qh_qh.PRINTstatistics != 0
    || qh_qh.IStracing != 0
    || qh_qh.TRACElevel != 0
    || qh_qh.JOGGLEmax < 1.797693134862316e308 )
  {
    qh_qh.old_randomdist = qh_qh.RANDOMdist;
    qh_qh.RANDOMdist = 0;
    v32 = v2->vertices;
    if ( v32 != nullptr )
    {
      v33.p = (void *)v32->e[0];
      v34 = v32->e;
      if ( v33.i != 0 )
      {
        do
        {
          ++v34;
          if ( *(long double **)(v33.i + 8) != point0 )
          {
            ++qh_qhstat.stats[53].i;
            qh_distplane(point: *(long double **)(v33.i + 8), facet: v2, &dist);
            *(_QWORD *)&v35 = *(_QWORD *)&dist & _mask__AbsDouble_;
            ++qh_qhstat.stats[125].i;
            dist = v35;
            qh_qhstat.stats[126].r = qh_qhstat.stats[126].r + v35;
            if ( v35 <= qh_qhstat.stats[127].r )
            {
              v36 = -v35 <= qh_qh.TRACEdist;
LABEL_60:
              if ( !v36 )
              {
                furthest_id = qh_qh.furthest_id;
                v40 = v2->id;
                v39 = *(_DWORD *)(v33.i + 20) & 0xFFFFFF;
                v37 = qh_pointid(point: *(long double **)(v33.i + 8));
                ivp_message(
                  templat: "qh_setfacetplane: ====== vertex p%d (v%d) increases max_outside to %2.2g for new facet f%d last p%d\n",
                  v37,
                  v39,
                  v35,
                  v40,
                  furthest_id);
                qh_errprint(string: "DISTANT", atfacet: v2, otherfacet: nullptr, atridge: nullptr, atvertex: nullptr);
              }
              goto LABEL_62;
            }
            qh_qhstat.stats[127].r = v35;
            if ( v35 > qh_qh.max_outside )
            {
              v36 = v35 <= qh_qh.TRACEdist;
              qh_qh.max_outside = v35;
              goto LABEL_60;
            }
          }
LABEL_62:
          v33.p = v34->p;
        }
        while ( v34->i != 0 );
      }
    }
    qh_qh.RANDOMdist = qh_qh.old_randomdist;
    if ( qh_qh.IStracing >= 3 )
    {
      ivp_message(templat: "qh_setfacetplane: f%d offset %2.2g normal: ", v2->id, (double)v2->offset);
      for ( j = 0; j < qh_qh.hull_dim; ++j )
        ivp_message(templat: "%2.2g ", (double)v2->normal[j]);
      ivp_message(templat: "\n");
    }
  }
  if ( v2 == qh_qh.tracefacet )
    qh_qh.IStracing = oldtrace;
}
