// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_compact_builder/qhull_geom2.cxx
// Functions: 42
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10048F70
// Name: double __near * qh_copypoints(double __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
long double *__cdecl qh_copypoints(long double *points, int numpoints, int dimension)
{
  unsigned __int8 *v3; // eax
  unsigned __int8 *v4; // edi

  v3 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 8 * dimension * numpoints);
  v4 = v3;
  if ( v3 == nullptr )
  {
    fprintf(str: qh_qh.ferr, format: "qhull error: insufficient memory to copy %d points\n", numpoints);
    qh_errexit(exitcode: 4, facet: nullptr, ridge: nullptr);
  }
  memcpy(dst: v3, src: (unsigned __int8 *)points, count: 8 * dimension * numpoints);
  return (long double *)v4;
}

//------------------------------------------------------------------------------
// Address: 0x10048FD0
// Name: void qh_crossproduct(int,double __near * const,double __near * const,double __near * const)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_crossproduct(int dim, long double *vecA, long double *vecB, long double *vecC)
{
  if ( dim == 3 )
  {
    *vecC = vecB[2] * vecA[1] - vecB[1] * vecA[2];
    *((_QWORD *)vecC + 1) = COERCE_UNSIGNED_INT64(vecB[2] * *vecA - *vecB * vecA[2]) ^ _mask__NegDouble_;
    vecC[2] = *vecA * vecB[1] - vecA[1] * *vecB;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10049040
// Name: double qh_determinant(double __near * __near *,int,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
long double __cdecl qh_determinant(long double **rows, int dim, unsigned int *nearzero)
{
  long double result; // st7
  long double *v4; // ecx
  long double *v5; // eax
  double v6; // xmm0_8
  int i; // eax
  double det; // [esp+0h] [ebp-Ch]
  unsigned int sign; // [esp+8h] [ebp-4h] BYREF

  sign = 0;
  *nearzero = 0;
  if ( dim < 2 )
  {
    ivp_message(templat: "qhull internal error (qh_determinate): only implemented for dimension >= 2\n");
    qh_errexit(exitcode: 5, facet: nullptr, ridge: nullptr);
  }
  if ( dim == 2 )
  {
    result = rows[1][1] * **rows - (*rows)[1] * *rows[1];
    if ( *((double *)qh_qh.NEARzero + 1) > COERCE_DOUBLE(*(_QWORD *)&result & _mask__AbsDouble_) )
      *nearzero = 1;
  }
  else
  {
    if ( dim == 3 )
    {
      v4 = rows[1];
      v5 = rows[2];
      det = (v4[1] * v5[2] - v5[1] * v4[2]) * **rows
          - ((*rows)[1] * v5[2] - (*rows)[2] * v5[1]) * *v4
          + ((*rows)[1] * v4[2] - (*rows)[2] * v4[1]) * *v5;
      if ( *((double *)qh_qh.NEARzero + 2) > COERCE_DOUBLE(*(_QWORD *)&det & _mask__AbsDouble_) )
      {
        *nearzero = 1;
        return det;
      }
    }
    else
    {
      qh_gausselim(rows, numrow: dim, numcol: dim, &sign, nearzero);
      v6 = 1.0;
      for ( i = dim; i != 0; --i )
        v6 = v6 * rows[i - 1][i - 1];
      det = v6;
      if ( sign != 0 )
        return -v6;
    }
    return det;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100491D0
// Name: double qh_detsimplex(double __near *,struct setT __near *,int,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
long double __cdecl qh_detsimplex(long double *apex, setT *points, int dim, unsigned int *nearzero)
{
  long double *gm_matrix; // edx
  long double **gm_row; // esi
  int v7; // edi
  double *p; // eax
  int v9; // ecx
  char *v10; // esi
  long double result; // st7
  int v12; // eax
  unsigned int v13; // [esp+10h] [ebp-18h]
  long double **rows_4; // [esp+24h] [ebp-4h]
  long double **pointp; // [esp+34h] [ebp+Ch]

  ++qh_qhstat.stats[47].i;
  gm_matrix = qh_qh.gm_matrix;
  gm_row = qh_qh.gm_row;
  v7 = 0;
  rows_4 = qh_qh.gm_row;
  if ( points != nullptr && (pointp = (long double **)points->e, (p = (double *)points->e[0].p) != nullptr) )
  {
    while ( 1 )
    {
      ++pointp;
      if ( v7 == dim )
        break;
      gm_row[v7++] = gm_matrix;
      v9 = dim;
      if ( dim != 0 )
      {
        v10 = (char *)((char *)apex - (char *)p);
        do
        {
          *gm_matrix++ = *p - *(double *)((char *)p + (_DWORD)v10);
          ++p;
          --v9;
        }
        while ( v9 != 0 );
        gm_row = rows_4;
      }
      p = *pointp;
      if ( *pointp == nullptr )
        goto LABEL_9;
    }
  }
  else
  {
LABEL_9:
    if ( v7 < dim )
    {
      ivp_message(templat: "qhull internal error (qh_detsimplex): #points %d < dimension %d\n", v7, dim);
      qh_errexit(exitcode: 5, facet: nullptr, ridge: nullptr);
    }
  }
  result = qh_determinant(rows: gm_row, dim, nearzero);
  if ( qh_qh.IStracing >= 2 )
  {
    v13 = *nearzero;
    v12 = qh_pointid(point: apex);
    fprintf(
      str: qh_qh.ferr,
      format: "qh_detsimplex: det=%2.2g for point p%d, dim %d, nearzero? %d\n",
      (double)result,
      v12,
      dim,
      v13);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100492C0
// Name: double qh_distnorm(int,double __near *,double __near *,double __near *)
// Source: json
//------------------------------------------------------------------------------
double __cdecl qh_distnorm(int dim, long double *point, long double *normal, long double *offsetp)
{
  double v4; // xmm0_8
  int v5; // ecx
  double *v6; // eax
  double v7; // xmm1_8
  double dist; // [esp+0h] [ebp-8h]

  v4 = *offsetp;
  v5 = dim;
  v6 = normal;
  for ( dist = *offsetp; v5 != 0; dist = v4 )
  {
    v7 = *(double *)((char *)v6 + (char *)point - (char *)normal) * *v6;
    ++v6;
    --v5;
    v4 = v4 + v7;
  }
  return dist;
}

//------------------------------------------------------------------------------
// Address: 0x10049300
// Name: double qh_distround(int,double,double)
// Source: json
//------------------------------------------------------------------------------
double __cdecl qh_distround(int dimension, long double maxabs, double maxsumabs)
{
  double v3; // xmm1_8
  double v4; // xmm0_8

  v3 = sqrt((double)dimension) * maxabs;
  if ( v3 > maxsumabs )
    v3 = maxsumabs;
  v4 = ((double)dimension * v3 * 1.01 + maxabs) * 2.220446049250313e-16;
  if ( qh_qh.IStracing >= 4 )
    fprintf(
      str: qh_qh.ferr,
      format: "qh_distround: %2.2g maxabs %2.2g maxsumabs %2.2g maxdistsum %2.2g\n",
      v4,
      (double)maxabs,
      maxsumabs,
      v3);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10049380
// Name: double qh_divzero(double,double,double,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
long double __cdecl qh_divzero(double numer, long double denom, double mindenom1, unsigned int *zerodiv)
{
  if ( mindenom1 <= numer || numer <= COERCE_DOUBLE(*(_QWORD *)&mindenom1 ^ _mask__NegDouble_) )
  {
    if ( denom / numer <= mindenom1 && COERCE_DOUBLE(*(_QWORD *)&mindenom1 ^ _mask__NegDouble_) <= denom / numer )
    {
      *zerodiv = 1;
      return 0.0;
    }
  }
  else if ( COERCE_DOUBLE(*(_QWORD *)&denom & _mask__AbsDouble_) <= COERCE_DOUBLE(*(_QWORD *)&numer & _mask__AbsDouble_) )
  {
    *zerodiv = 1;
    return 0.0;
  }
  *zerodiv = 0;
  return numer / denom;
}

//------------------------------------------------------------------------------
// Address: 0x10049410
// Name: double qh_facetarea_simplex(int,double __near *,struct setT __near *,struct vertexT __near *,unsigned int,double __near *,double __near *)
// Source: json
//------------------------------------------------------------------------------
double __cdecl qh_facetarea_simplex(
        int dim,
        long double *apex,
        setT *vertices,
        vertexT *notvertex,
        unsigned int toporient,
        long double *normal,
        long double *offset)
{
  int v7; // esi
  long double *gm_matrix; // edi
  setelemT *e; // ecx
  vertexT *p; // eax
  double *point; // ecx
  double *v12; // eax
  int v13; // eax
  char *v14; // edx
  double v15; // xmm0_8
  int i; // edx
  long double v17; // xmm2_8
  int v18; // edx
  double *v19; // eax
  int v20; // ecx
  long double **v21; // eax
  int v22; // edx
  _DWORD *v23; // eax
  unsigned int v24; // ecx
  int v25; // esi
  long double *v26; // ecx
  int v28; // eax
  char *v29; // ecx
  long double v30; // st7
  double v31; // xmm0_8
  int v32; // eax
  unsigned int v33; // [esp+10h] [ebp-20h]
  unsigned int nearzero; // [esp+20h] [ebp-10h] BYREF
  long double vertexp; // [esp+24h] [ebp-Ch]
  long double **rows; // [esp+2Ch] [ebp-4h]

  rows = qh_qh.gm_row;
  v7 = 0;
  gm_matrix = qh_qh.gm_matrix;
  if ( vertices != nullptr )
  {
    e = vertices->e;
    p = (vertexT *)vertices->e[0].p;
    if ( p != nullptr )
    {
      do
      {
        HIDWORD(vertexp) = e + 1;
        if ( p != notvertex )
        {
          rows[v7] = gm_matrix;
          point = p->point;
          ++v7;
          v12 = point;
          if ( notvertex != nullptr )
          {
            v13 = dim;
            if ( dim != 0 )
            {
              v14 = (char *)((char *)apex - (char *)gm_matrix);
              do
              {
                *gm_matrix = *point - *(double *)((char *)gm_matrix + (_DWORD)v14);
                ++gm_matrix;
                ++point;
                --v13;
              }
              while ( v13 != 0 );
            }
          }
          else
          {
            v15 = *offset;
            for ( i = dim; i != 0; v15 = v15 + v17 )
            {
              v17 = *(double *)((char *)v12 + (char *)normal - (char *)point) * *v12;
              ++v12;
              --i;
            }
            if ( COERCE_DOUBLE(*(_QWORD *)&qh_qh.WIDEfacet ^ _mask__NegDouble_) > v15 )
            {
              ++qh_qhstat.stats[128].i;
              return 0.0;
            }
            v18 = dim;
            if ( dim != 0 )
            {
              v19 = apex;
              v20 = (char *)point - (char *)gm_matrix;
              do
              {
                *gm_matrix = *(long double *)((char *)gm_matrix + v20)
                           - *(double *)((char *)v19 + (char *)normal - (char *)apex) * v15
                           - *v19;
                ++gm_matrix;
                ++v19;
                --v18;
              }
              while ( v18 != 0 );
            }
          }
        }
        e = (setelemT *)HIDWORD(vertexp);
        p = *(vertexT **)HIDWORD(vertexp);
      }
      while ( *(_DWORD *)HIDWORD(vertexp) != 0 );
    }
  }
  if ( v7 != dim - 1 )
  {
    ivp_message(templat: "qhull internal error (qh_facetarea_simplex): #points %d != dim %d -1\n", v7, dim);
    qh_errexit(exitcode: 5, facet: nullptr, ridge: nullptr);
  }
  v21 = rows;
  rows[v7] = gm_matrix;
  if ( qh_qh.DELAUNAY != 0 )
  {
    v22 = 0;
    if ( dim - 1 >= 4 )
    {
      v23 = v21 + 2;
      v24 = ((unsigned int)(dim - 5) >> 2) + 1;
      v22 = 4 * v24;
      do
      {
        *(_QWORD *)(*(v23 - 2) + 8 * dim - 8) = 0;
        *(_QWORD *)(*(v23 - 1) + 8 * dim - 8) = 0;
        *(_QWORD *)(*v23 + 8 * dim - 8) = 0;
        v25 = v23[1];
        v23 += 4;
        --v24;
        *(_QWORD *)(v25 + 8 * dim - 8) = 0;
      }
      while ( v24 != 0 );
    }
    for ( ; v22 < dim - 1; v26[dim - 1] = 0.0 )
      v26 = rows[v22++];
    if ( dim != 0 )
      memset(gm_matrix, 0, 8 * dim);
    rows[dim - 1][dim - 1] = -1.0;
  }
  else
  {
    v28 = dim;
    if ( dim != 0 )
    {
      v29 = (char *)((char *)normal - (char *)gm_matrix);
      do
      {
        v30 = *(double *)((char *)gm_matrix++ + (_DWORD)v29);
        --v28;
        *(gm_matrix - 1) = v30;
      }
      while ( v28 != 0 );
    }
  }
  ++qh_qhstat.stats[47].i;
  vertexp = qh_determinant(rows, dim, &nearzero);
  v31 = vertexp;
  if ( toporient != 0 )
    v31 = -vertexp;
  vertexp = qh_qh.AREAfactor * v31;
  if ( qh_qh.IStracing >= 4 )
  {
    v33 = nearzero;
    v32 = qh_pointid(point: apex);
    fprintf(
      str: qh_qh.ferr,
      format: "qh_facetarea_simplex: area=%2.2g for point p%d, toporient %d, nearzero? %d\n",
      (double)vertexp,
      v32,
      toporient,
      v33);
  }
  return vertexp;
}

//------------------------------------------------------------------------------
// Address: 0x100496A0
// Name: unsigned int qh_findbestsharp(double __near *,struct facetT __near * __near *,double __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl qh_findbestsharp(long double *point, facetT **bestfacet, long double *bestdist, int *numpart)
{
  _DWORD *v4; // edi
  facetT *newfacet_list; // eax
  facetT *v6; // esi
  int i; // eax
  double v8; // xmm1_8
  int hull_dim; // eax
  int v10; // edx
  double v11; // xmm1_8
  long double dist; // [esp+4h] [ebp-Ch] BYREF
  unsigned int issharp; // [esp+Ch] [ebp-4h]

  issharp = 0;
  v4 = qh_memalloc(insize: 4 * qh_qh.hull_dim);
  newfacet_list = qh_qh.newfacet_list;
  if ( qh_qh.newfacet_list != nullptr )
  {
    v6 = qh_qh.newfacet_list;
    while ( v6->next != nullptr )
    {
      if ( v6 == newfacet_list )
      {
        for ( i = qh_qh.hull_dim; i != 0; v4[i] = v8 > 0.0 )
          v8 = v6->normal[--i];
      }
      else if ( issharp == 0 )
      {
        hull_dim = qh_qh.hull_dim;
        if ( qh_qh.hull_dim != 0 )
        {
          v10 = (int)&v6->normal[qh_qh.hull_dim];
          while ( 1 )
          {
            v11 = *(double *)(v10 - 8);
            v10 -= 8;
            if ( v4[--hull_dim] != v11 > 0.0 )
              break;
            if ( hull_dim == 0 )
              goto LABEL_16;
          }
          issharp = 1;
        }
      }
LABEL_16:
      if ( v6->visitid != qh_qh.visit_id )
      {
        qh_distplane(point, facet: v6, &dist);
        ++*numpart;
        if ( dist > *bestdist && ((*((_BYTE *)v6 + 82) & 1) == 0 || dist > qh_qh.MINoutside) )
        {
          *bestdist = dist;
          *bestfacet = v6;
        }
      }
      v6 = v6->next;
      if ( v6 == nullptr )
        break;
      newfacet_list = qh_qh.newfacet_list;
    }
  }
  qh_memfree(object: v4, size: 4 * qh_qh.hull_dim);
  return issharp;
}

//------------------------------------------------------------------------------
// Address: 0x100497F0
// Name: struct facetT __near * qh_findgooddist(double __near *,struct facetT __near *,double __near *,struct facetT __near * __near *)
// Source: json
//------------------------------------------------------------------------------
facetT *__cdecl qh_findgooddist(long double *point, facetT *facetA, long double *distp, facetT **facetlist)
{
  bool v5; // zf
  facetT *v6; // ecx
  setT *neighbors; // eax
  setelemT v8; // esi
  setelemT *e; // edi
  facetT *v10; // esi
  double v11; // xmm0_8
  int v12; // eax
  int v14; // eax
  unsigned int id; // [esp+8h] [ebp-24h]
  unsigned int v16; // [esp+8h] [ebp-24h]
  double dist; // [esp+14h] [ebp-18h] BYREF
  long double bestdist; // [esp+1Ch] [ebp-10h] BYREF
  facetT *bestfacet; // [esp+24h] [ebp-8h]
  unsigned int goodseen; // [esp+28h] [ebp-4h]
  facetT *facet; // [esp+38h] [ebp+Ch]

  v5 = (*((_DWORD *)facetA + 20) & 0x40000) == 0;
  bestdist = -1.797693134862316e308;
  bestfacet = nullptr;
  goodseen = 0;
  if ( !v5 )
  {
    ++qh_qhstat.stats[18].i;
    qh_distplane(point, facet: facetA, dist: &bestdist);
    bestfacet = facetA;
    goodseen = 1;
  }
  qh_removefacet(facet: facetA);
  qh_appendfacet(facet: facetA);
  *facetlist = facetA;
  facetA->visitid = ++qh_qh.visit_id;
  if ( *facetlist != nullptr )
  {
    facet = *facetlist;
    do
    {
      v6 = facet;
      if ( facet->next == nullptr )
        break;
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
            if ( *(_DWORD *)(v8.i + 72) != qh_qh.visit_id )
            {
              v5 = goodseen == 0;
              *(_DWORD *)(v8.i + 72) = qh_qh.visit_id;
              if ( v5 || (*(_DWORD *)(v8.i + 80) & 0x40000) != 0 )
              {
                ++qh_qhstat.stats[18].i;
                qh_distplane(point, facet: (facetT *)v8.p, &dist);
                if ( dist > 0.0 )
                {
                  qh_removefacet(facet: (facetT *)v8.p);
                  qh_appendfacet(facet: (facetT *)v8.p);
                  if ( (*(_DWORD *)(v8.i + 80) & 0x40000) != 0 )
                  {
                    goodseen = 1;
                    if ( dist > bestdist )
                    {
                      bestdist = dist;
                      bestfacet = (facetT *)v8.i;
                    }
                  }
                }
              }
            }
            v8.p = e->p;
          }
          while ( e->i != 0 );
          v6 = facet;
        }
      }
      facet = v6->next;
    }
    while ( facet != nullptr );
  }
  v10 = bestfacet;
  if ( bestfacet != nullptr )
  {
    v11 = bestdist;
    *distp = bestdist;
    if ( qh_qh.IStracing >= 2 )
    {
      id = v10->id;
      v12 = qh_pointid(point);
      fprintf(str: qh_qh.ferr, format: "qh_findgooddist: p%d is %2.2g above good facet f%d\n", v12, v11, id);
    }
    return v10;
  }
  else
  {
    if ( qh_qh.IStracing >= 4 )
    {
      v16 = facetA->id;
      v14 = qh_pointid(point);
      fprintf(str: qh_qh.ferr, format: "qh_findgooddist: no good facet for p%d above f%d\n", v14, v16);
    }
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100499C0
// Name: unsigned int qh_gram_schmidt(int,double __near * __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl qh_gram_schmidt(int dim, long double **row)
{
  int v3; // ebx
  double *v4; // ecx
  double v5; // xmm0_8
  int i; // eax
  double v7; // xmm1_8
  double v8; // xmm0_8
  int v9; // eax
  double v10; // xmm1_8
  double v11; // xmm0_8
  int j; // edi
  double *v13; // eax
  double v14; // xmm0_8
  int k; // edx
  double v16; // xmm1_8
  int m; // edx
  double v18; // xmm1_8
  double v19; // xmm4_8
  double **dima; // [esp+14h] [ebp+8h]

  if ( dim <= 0 )
    return 1;
  v3 = 1;
  for ( dima = row; ; ++dima )
  {
    v4 = *dima;
    v5 = 0.0;
    for ( i = dim; i != 0; v5 = v7 * v7 + v5 )
    {
      v7 = *v4++;
      --i;
    }
    v8 = sqrt(v5);
    if ( qh_qhstat.stats[115].r > v8 )
      qh_qhstat.stats[115].r = v8;
    if ( v8 == 0.0 )
      break;
    v9 = dim;
    if ( dim != 0 )
    {
      v10 = 1.0 / v8;
      do
      {
        v11 = *--v4;
        --v9;
        *v4 = v11 * v10;
      }
      while ( v9 != 0 );
    }
    for ( j = v3; j < dim; ++j )
    {
      v13 = row[j];
      v14 = 0.0;
      for ( k = dim; k != 0; v14 = v16 + v14 )
      {
        v16 = *v4++ * *v13++;
        --k;
      }
      for ( m = dim; m != 0; *v13 = v19 - v18 * v14 )
      {
        v18 = *(v4 - 1);
        v19 = *--v13;
        --v4;
        --m;
      }
    }
    if ( v3++ >= dim )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10049AF0
// Name: unsigned int qh_inthresholds(double __near *,double __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl qh_inthresholds(long double *normal, long double *angle)
{
  unsigned int result; // eax
  int i; // edx
  double v4; // xmm0_8
  double v5; // xmm1_8
  double v6; // xmm0_8
  double v7; // xmm1_8

  result = 1;
  if ( angle != nullptr )
    *angle = 0.0;
  for ( i = 0; i < qh_qh.hull_dim; ++i )
  {
    v4 = qh_qh.lower_threshold[i];
    if ( v4 > -8.988465674311579e307 )
    {
      v5 = normal[i];
      if ( v4 > v5 )
        result = 0;
      if ( angle != nullptr )
        *angle = COERCE_DOUBLE(COERCE_UNSIGNED_INT64(v4 - v5) & _mask__AbsDouble_) + *angle;
    }
    v6 = qh_qh.upper_threshold[i];
    if ( v6 < 8.988465674311579e307 )
    {
      v7 = normal[i];
      if ( v7 > v6 )
        result = 0;
      if ( angle != nullptr )
        *angle = COERCE_DOUBLE(COERCE_UNSIGNED_INT64(v6 - v7) & _mask__AbsDouble_) + *angle;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10049BB0
// Name: double __near * qh_maxabsval(double __near *,int)
// Source: json
//------------------------------------------------------------------------------
long double *__cdecl qh_maxabsval(long double *normal, int dim)
{
  int v2; // edx
  double v3; // xmm1_8
  long double *result; // eax
  double v6; // xmm0_8

  v2 = dim;
  v3 = -1.797693134862316e308;
  for ( result = nullptr; v2 != 0; ++normal )
  {
    v6 = *normal;
    --v2;
    if ( *normal < 0.0 )
      *(_QWORD *)&v6 ^= _mask__NegDouble_;
    if ( v6 > v3 )
    {
      v3 = v6;
      result = normal;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10049C00
// Name: double qh_maxouter(void)
// Source: json
//------------------------------------------------------------------------------
double __cdecl qh_maxouter()
{
  double max_outside; // xmm1_8
  double v1; // xmm0_8

  if ( qh_qh.DISTround <= qh_qh.max_outside )
    max_outside = qh_qh.max_outside;
  else
    max_outside = qh_qh.DISTround;
  v1 = qh_qh.DISTround + max_outside;
  if ( qh_qh.IStracing >= 4 )
    fprintf(
      str: qh_qh.ferr,
      format: "qh_maxouter: max distance from facet to outer plane is %2.2g max_outside is %2.2g\n",
      v1,
      (double)qh_qh.max_outside);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x10049C60
// Name: void qh_maxsimplex(int,struct setT __near *,double __near *,int,struct setT __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_maxsimplex(int dim, setT *maxpoints, long double *points, int numpoints, setT **simplex)
{
  void *v5; // edi
  void *v6; // ebx
  int v7; // esi
  double *p; // eax
  setelemT *e; // ecx
  double v10; // xmm1_8
  double v11; // xmm2_8
  long double *v12; // eax
  long double *v13; // ecx
  double v14; // xmm1_8
  double v15; // xmm2_8
  int v16; // eax
  long double *v17; // ebx
  long double *i; // esi
  setelemT *v19; // edi
  int v20; // eax
  long double *v21; // esi
  long double *v22; // edi
  int v23; // eax
  int v24; // [esp-4h] [ebp-34h]
  double mincoord; // [esp+14h] [ebp-1Ch]
  double mincoorda; // [esp+14h] [ebp-1Ch]
  double maxcoord; // [esp+1Ch] [ebp-14h]
  unsigned int maxnearzero; // [esp+24h] [ebp-Ch]
  unsigned int nearzero; // [esp+28h] [ebp-8h] BYREF
  int k; // [esp+2Ch] [ebp-4h]
  int dima; // [esp+38h] [ebp+8h]

  v5 = nullptr;
  v6 = nullptr;
  maxnearzero = 0;
  v7 = qh_setsize(set: *simplex);
  if ( v7 < 2 )
  {
    if ( qh_setsize(set: maxpoints) < 2 )
    {
      v12 = points;
      v13 = &points[numpoints * qh_qh.hull_dim];
      if ( points < v13 )
      {
        v14 = 1.797693134862316e308;
        v15 = -1.797693134862316e308;
        do
        {
          if ( v12 != qh_qh.GOODpointp )
          {
            if ( *v12 > v15 )
            {
              v15 = *v12;
              v5 = v12;
            }
            if ( v14 > *v12 )
            {
              v14 = *v12;
              v6 = v12;
            }
          }
          v12 += qh_qh.hull_dim;
        }
        while ( v12 < v13 );
      }
    }
    else if ( maxpoints != nullptr )
    {
      p = (double *)maxpoints->e[0].p;
      e = maxpoints->e;
      if ( p != nullptr )
      {
        v10 = 1.797693134862316e308;
        v11 = -1.797693134862316e308;
        do
        {
          ++e;
          if ( *p > v11 )
          {
            v11 = *p;
            v5 = p;
          }
          if ( v10 > *p )
          {
            v10 = *p;
            v6 = p;
          }
          p = (double *)e->i;
        }
        while ( e->i != 0 );
      }
    }
    qh_setunique(set: simplex, elem: v6);
    if ( qh_setsize(set: *simplex) < 2 )
      qh_setunique(set: simplex, elem: v5);
    v7 = qh_setsize(set: *simplex);
    if ( v7 < 2 )
    {
      qh_precision(reason: "input has same x coordinate");
      if ( qh_qhstat.stats[172].i > qh_qh.hull_dim + 1 )
      {
        if ( qh_qh.ferr != nullptr )
        {
          v16 = qh_setsize(set: maxpoints);
          ivp_message(
            templat: "qhull precision error (qh_maxsimplex for voronoi_center):\n%d points with the same x coordinate.\n",
            numpoints + v16);
        }
        qh_errexit(exitcode: 3, facet: nullptr, ridge: nullptr);
      }
      if ( qh_qh.ferr != nullptr )
        ivp_message(
          templat: "qhull input error: input is less than %d-dimensional since it has the same x coordinate\n",
          qh_qh.hull_dim);
      qh_errexit(exitcode: 1, facet: nullptr, ridge: nullptr);
    }
  }
  k = v7;
  dima = dim + 1;
  if ( v7 < dima )
  {
    do
    {
      v17 = nullptr;
      maxcoord = -1.797693134862316e308;
      if ( maxpoints == nullptr )
        goto LABEL_39;
      i = (long double *)maxpoints->e[0].p;
      v19 = maxpoints->e;
      if ( i == nullptr )
        goto LABEL_39;
      do
      {
        ++v19;
        if ( qh_setin(set: *simplex, setelem: i) == 0 )
        {
          mincoord = fabs(qh_detsimplex(apex: i, points: *simplex, dim: k, &nearzero));
          if ( mincoord > maxcoord )
          {
            maxcoord = mincoord;
            v17 = i;
            maxnearzero = nearzero;
          }
        }
        i = (long double *)v19->i;
      }
      while ( v19->i != 0 );
      if ( v17 == nullptr || maxnearzero != 0 )
      {
LABEL_39:
        ++qh_qhstat.stats[171].i;
        if ( v17 != nullptr )
        {
          if ( qh_qh.IStracing != 0 )
          {
            v20 = qh_pointid(point: v17);
            fprintf(
              str: qh_qh.ferr,
              format: "qh_maxsimplex: searching all points for %d-th initial vertex, better than p%d det %2.2g\n",
              k + 1,
              v20,
              maxcoord);
          }
        }
        else if ( qh_qh.IStracing != 0 )
        {
          fprintf(str: qh_qh.ferr, format: "qh_maxsimplex: searching all points for %d-th initial vertex.\n", k + 1);
        }
        v21 = points;
        v22 = &points[numpoints * qh_qh.hull_dim];
        if ( points < v22 )
        {
          do
          {
            if ( v21 != qh_qh.GOODpointp && qh_setin(set: *simplex, setelem: v21) == 0 )
            {
              mincoorda = fabs(qh_detsimplex(apex: v21, points: *simplex, dim: k, &nearzero));
              if ( mincoorda > maxcoord )
              {
                maxcoord = mincoorda;
                v17 = v21;
                maxnearzero = nearzero;
              }
            }
            v21 += qh_qh.hull_dim;
          }
          while ( v21 < v22 );
        }
      }
      if ( v17 == nullptr )
      {
        ivp_message(templat: "qhull internal error (qh_maxsimplex): not enough points available\n");
        qh_errexit(exitcode: 5, facet: nullptr, ridge: nullptr);
      }
      qh_setappend(setp: simplex, newelem: v17);
      if ( qh_qh.IStracing >= 1 )
      {
        v24 = k + 1;
        v23 = qh_pointid(point: v17);
        fprintf(
          str: qh_qh.ferr,
          format: "qh_maxsimplex: selected point p%d for %d`th initial vertex, det=%2.2g\n",
          v23,
          v24,
          maxcoord);
      }
      ++k;
    }
    while ( k < dima );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10049FF0
// Name: unsigned int qh_orientoutside(struct facetT __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl qh_orientoutside(facetT *facet)
{
  int i; // ecx
  double dist; // [esp+4h] [ebp-8h] BYREF

  qh_distplane(point: qh_qh.interior_point, facet, &dist);
  if ( dist <= 0.0 )
    return 0;
  for ( i = qh_qh.hull_dim; i != 0; *(_QWORD *)&facet->normal[i] ^= _mask__NegDouble_ )
    --i;
  *(_QWORD *)&facet->offset ^= _mask__NegDouble_;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1004A070
// Name: void qh_outerinner(struct facetT __near *,double __near *,double __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_outerinner(facetT *facet, long double *outerplane, long double *innerplane)
{
  setT *vertices; // eax
  double min_vertex; // xmm0_8
  setelemT *e; // esi
  setelemT v6; // eax
  double dist; // [esp+Ch] [ebp-10h] BYREF
  double mindist; // [esp+14h] [ebp-8h]

  if ( outerplane != nullptr )
  {
    *outerplane = facet != nullptr && qh_qh.maxoutdone != 0 ? facet->maxoutside + qh_qh.DISTround : qh_maxouter();
    if ( qh_qh.JOGGLEmax < 8.988465674311579e307 )
      *outerplane = sqrt((double)qh_qh.hull_dim) * qh_qh.JOGGLEmax + *outerplane;
  }
  if ( innerplane != nullptr )
  {
    if ( facet != nullptr )
    {
      vertices = facet->vertices;
      min_vertex = 1.797693134862316e308;
      mindist = 1.797693134862316e308;
      if ( vertices != nullptr )
      {
        e = vertices->e;
        v6.p = (void *)vertices->e[0];
        if ( v6.i != 0 )
        {
          do
          {
            ++qh_qhstat.stats[51].i;
            ++e;
            qh_distplane(point: *(long double **)(v6.i + 8), facet, &dist);
            min_vertex = mindist;
            if ( mindist > dist )
            {
              min_vertex = dist;
              mindist = dist;
            }
            v6.p = e->p;
          }
          while ( e->i != 0 );
        }
      }
    }
    else
    {
      min_vertex = qh_qh.min_vertex;
    }
    *innerplane = min_vertex - qh_qh.DISTround;
    if ( qh_qh.JOGGLEmax < 8.988465674311579e307 )
      *innerplane = *innerplane - sqrt((double)qh_qh.hull_dim) * qh_qh.JOGGLEmax;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004A1A0
// Name: double qh_pointdist(double __near *,double __near *,int)
// Source: json
//------------------------------------------------------------------------------
double __cdecl qh_pointdist(long double *point1, long double *point2, int dim)
{
  double v3; // xmm1_8
  unsigned int v4; // eax
  double *v5; // ecx
  double v6; // xmm0_8
  double result; // st7
  double dist; // [esp+0h] [ebp-8h]

  v3 = 0.0;
  v4 = abs32(dim);
  dist = 0.0;
  if ( v4 != 0 )
  {
    v5 = point2;
    do
    {
      v6 = *(double *)((char *)v5 + (char *)point1 - (char *)point2) - *v5;
      ++v5;
      --v4;
      v3 = v3 + v6 * v6;
    }
    while ( v4 != 0 );
    dist = v3;
  }
  result = dist;
  if ( dim > 0 )
    return sqrt(dist);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004A1F0
// Name: void qh_printmatrix(struct _iobuf __near *,char const __near *,double __near * __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_printmatrix(_iobuf *fp, const char *string, long double **rows, int numrow, int numcol)
{
  int v5; // edi
  long double *v6; // esi
  double v7; // [esp+0h] [ebp-18h]
  int i; // [esp+14h] [ebp-4h]

  fprintf(str: fp, format: "%s\n", string);
  for ( i = 0; i < numrow; ++i )
  {
    v5 = numcol;
    v6 = rows[i];
    if ( numcol > 0 )
    {
      do
      {
        v7 = *v6++;
        fprintf(str: fp, format: "%6.3g ", v7);
        --v5;
      }
      while ( v5 != 0 );
    }
    fprintf(str: fp, format: "\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004A280
// Name: void qh_printpoints(struct _iobuf __near *,char const __near *,struct setT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_printpoints(_iobuf *fp, const char *string, setT *points)
{
  setelemT *e; // esi
  long double *p; // eax
  int v5; // eax
  setelemT *v6; // esi
  long double *i; // eax
  int v8; // eax

  if ( string != nullptr )
  {
    fprintf(str: fp, format: "%s", string);
    if ( points != nullptr )
    {
      e = points->e;
      p = (long double *)points->e[0].p;
      if ( p != nullptr )
      {
        do
        {
          ++e;
          v5 = qh_pointid(point: p);
          fprintf(str: fp, format: " p%d", v5);
          p = (long double *)e->i;
        }
        while ( e->i != 0 );
      }
    }
  }
  else if ( points != nullptr )
  {
    v6 = points->e;
    i = (long double *)points->e[0].p;
    if ( i != nullptr )
    {
      do
      {
        ++v6;
        v8 = qh_pointid(point: i);
        fprintf(str: fp, format: " %d", v8);
        i = (long double *)v6->i;
      }
      while ( v6->i != 0 );
    }
  }
  fprintf(str: fp, format: "\n");
}

//------------------------------------------------------------------------------
// Address: 0x1004A320
// Name: void qh_projectpoints(signed char __near *,int,double __near *,int,int,double __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_projectpoints(
        char *project,
        int n,
        long double *points,
        int numpoints,
        int dim,
        long double *newpoints,
        int newdim)
{
  int v7; // ecx
  int v8; // ebx
  int v9; // edi
  int v10; // edx
  int v11; // esi
  int v12; // eax
  int v13; // ebx
  int v14; // ecx
  int v15; // ecx
  char v18; // al
  double *v19; // edx
  double *v20; // eax
  int v21; // ecx
  double v22; // st7
  int j; // [esp+10h] [ebp-8h]
  int oldk; // [esp+14h] [ebp-4h]

  v7 = dim;
  v8 = n;
  v9 = 0;
  v10 = 0;
  v11 = 0;
  v12 = 0;
  oldk = 0;
  if ( n >= 2 )
  {
    do
    {
      v10 += project[v12];
      v13 = project[v12 + 1];
      v12 += 2;
      v11 += v13;
    }
    while ( v12 < n - 1 );
    v8 = n;
    v9 = 0;
  }
  if ( v12 < v8 )
    v7 = dim + project[v12];
  v14 = v10 + v11 + v7;
  if ( v14 != newdim )
  {
    ivp_message(
      templat: "qhull internal error (qh_projectpoints): newdim %d should be %d after projection\n",
      newdim,
      v14);
    qh_errexit(exitcode: 5, facet: nullptr, ridge: nullptr);
  }
  v15 = 0;
  j = 0;
  if ( v8 > 0 )
  {
    while ( 1 )
    {
      v18 = project[v15];
      if ( v18 == -1 )
        break;
      v19 = newpoints++;
      if ( v18 != 1 )
      {
        ++v9;
        v20 = points;
        oldk = v9;
        ++points;
        goto LABEL_15;
      }
      if ( v9 < dim )
      {
        v20 = points;
LABEL_15:
        v21 = numpoints;
        if ( numpoints != 0 )
        {
          do
          {
            v22 = *v20;
            v20 += dim;
            *v19 = v22;
            v19 += newdim;
            --v21;
          }
          while ( v21 != 0 );
          v9 = oldk;
        }
LABEL_18:
        if ( v9 >= dim )
          goto LABEL_21;
        v15 = j;
      }
      j = ++v15;
      if ( v15 >= n )
        goto LABEL_21;
    }
    oldk = ++v9;
    ++points;
    goto LABEL_18;
  }
LABEL_21:
  if ( qh_qh.IStracing >= 1 )
    fprintf(
      str: qh_qh.ferr,
      format: "qh_projectpoints: projected %d points from dim %d to dim %d\n",
      numpoints,
      dim,
      newdim);
}

//------------------------------------------------------------------------------
// Address: 0x1004A450
// Name: int qh_rand(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl qh_rand()
{
  int result; // eax

  result = 16807 * qh_rand_seed - 0x7FFFFFFF * (qh_rand_seed / 127773);
  if ( result <= 0 )
    result += 0x7FFFFFFF;
  qh_rand_seed = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004A490
// Name: void qh_srand(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_srand(int seed)
{
  if ( seed >= 1 )
  {
    qh_rand_seed = 2147483646;
    if ( seed != 0x7FFFFFFF )
      qh_rand_seed = seed;
  }
  else
  {
    qh_rand_seed = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004A4C0
// Name: double qh_randomfactor(void)
// Source: json
//------------------------------------------------------------------------------
long double __cdecl qh_randomfactor()
{
  return (double)qh_rand() * qh_qh.RANDOMa + qh_qh.RANDOMb;
}

//------------------------------------------------------------------------------
// Address: 0x1004A4E0
// Name: void qh_randommatrix(double __near *,int,double __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_randommatrix(long double *buffer, long double *dim, long double **rows)
{
  int v5; // edi
  long double *buffera; // [esp+14h] [ebp+8h]

  v5 = (int)dim;
  if ( (int)dim > 0 )
  {
    buffera = dim;
    while ( 1 )
    {
      *rows++ = buffer;
      do
      {
        *buffer++ = (double)qh_rand() * 2.0 * 4.656612875245797e-10 - 1.0;
        --v5;
      }
      while ( v5 != 0 );
      buffera = (long double *)((char *)buffera - 1);
      if ( buffera == nullptr )
        break;
      v5 = (int)dim;
    }
  }
  *rows = buffer;
}

//------------------------------------------------------------------------------
// Address: 0x1004A550
// Name: void qh_rotatepoints(double __near *,int,int,double __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_rotatepoints(long double *points, int numpoints, int dim, long double **row)
{
  double *v4; // esi
  int v5; // ecx
  double *v6; // ebx
  int v7; // edx
  double v8; // xmm0_8
  int i; // eax
  double v10; // xmm2_8
  int v11; // eax
  int v12; // ecx
  double v13; // st7
  int j; // [esp+8h] [ebp-4h]
  long double *numpointsa; // [esp+18h] [ebp+Ch]

  v4 = nullptr;
  if ( qh_qh.IStracing >= 1 )
    qh_printmatrix(fp: qh_qh.ferr, string: "qh_rotatepoints: rotate points by", rows: row, numrow: dim, numcol: dim);
  v5 = numpoints;
  if ( numpoints != 0 )
  {
    numpointsa = row[dim];
    do
    {
      v6 = numpointsa;
      v7 = 0;
      for ( j = v5 - 1; v7 < dim; ++v6 )
      {
        v4 = points;
        v8 = 0.0;
        for ( i = dim; i != 0; --i )
        {
          v10 = *(double *)((char *)v4 + (char *)row[v7] - (char *)points) * *v4;
          ++v4;
          v8 = v8 + v10;
        }
        *v6 = v8;
        ++v7;
      }
      v11 = dim;
      if ( dim != 0 )
      {
        v12 = (char *)v6 - (char *)v4;
        do
        {
          v13 = *(double *)((char *)v4-- + v12 - 8);
          --v11;
          *v4 = v13;
        }
        while ( v11 != 0 );
      }
      v5 = j;
      points += dim;
    }
    while ( j != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004A630
// Name: void qh_scalelast(double __near *,int,int,double,double,double)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_scalelast(long double *points, int numpoints, int dim, double low, double high, double newhigh)
{
  double numer; // xmm6_8
  double v7; // xmm7_8
  double v8; // xmm4_8
  double v9; // xmm5_8
  int v10; // ecx
  double v11; // xmm4_8
  double *i; // eax
  double scale; // [esp+20h] [ebp-Ch]
  unsigned int nearzero; // [esp+28h] [ebp-4h] BYREF

  numer = newhigh;
  v7 = high;
  v8 = low;
  nearzero = 0;
  if ( qh_qh.IStracing >= 4 )
  {
    fprintf(
      str: qh_qh.ferr,
      format: "qh_scalelast: scale last coordinate from [%2.2g, %2.2g] to [0,%2.2g]\n",
      low,
      high,
      newhigh);
    numer = newhigh;
    v7 = high;
    v8 = low;
  }
  v9 = v7 - v8;
  qh_qh.last_low = v8;
  qh_qh.last_high = v7;
  qh_qh.last_newhigh = numer;
  scale = qh_divzero(numer, denom: v7 - v8, mindenom1: qh_qh.MINdenom_1, zerodiv: &nearzero);
  if ( nearzero != 0 )
  {
    ivp_message(
      templat: "qhull input error: last coordinate's new bounds [0, %2.2g] too wide for\n"
      "existing bounds [%2.2g, %2.2g] with width %2.2g\n",
      numer,
      v8,
      v7,
      v9);
    qh_errexit(exitcode: 1, facet: nullptr, ridge: nullptr);
  }
  v10 = numpoints;
  v11 = -(v8 * numer / v9);
  for ( i = &points[dim - 1]; v10 != 0; --v10 )
  {
    *i = *i * scale + v11;
    i += dim;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004A770
// Name: void qh_scalepoints(double __near *,int,int,double __near *,double __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_scalepoints(long double *points, int numpoints, int dim, long double *newlows, long double *newhighs)
{
  int v5; // esi
  int v6; // edx
  int v7; // ecx
  long double *v8; // ebx
  double v9; // xmm4_8
  double v10; // xmm5_8
  double v11; // xmm1_8
  double v12; // xmm7_8
  int v13; // ecx
  double *i; // eax
  double v15; // xmm0_8
  double v16; // xmm6_8
  double *v17; // eax
  int j; // ecx
  double *v19; // eax
  double v20; // xmm1_8
  double v21; // xmm2_8
  int v22; // ecx
  double scale; // [esp+48h] [ebp-34h]
  double low; // [esp+68h] [ebp-14h]
  unsigned int nearzero; // [esp+78h] [ebp-4h] BYREF

  v5 = 0;
  nearzero = 0;
  if ( dim > 0 )
  {
    v6 = (char *)newhighs - (char *)newlows;
    v7 = (char *)newlows - (char *)points;
    v8 = points;
    while ( 1 )
    {
      v9 = *(long double *)((char *)v8 + v7);
      v10 = *(long double *)((char *)v8 + v7 + v6);
      if ( v10 <= 8.988465674311579e307 || v9 >= -8.988465674311579e307 )
      {
        v11 = 1.797693134862316e308;
        v12 = -1.797693134862316e308;
        low = 1.797693134862316e308;
        v13 = numpoints;
        for ( i = v8; v13 != 0; i += dim )
        {
          --v13;
          if ( v11 > *i )
          {
            low = *i;
            v11 = *i;
          }
          if ( *i > v12 )
            v12 = *i;
        }
        if ( v10 > 8.988465674311579e307 )
          v10 = v12;
        if ( v9 < -8.988465674311579e307 )
          v9 = v11;
        if ( qh_qh.DELAUNAY != 0 && v5 == dim - 1 && v9 > v10 )
        {
          ivp_message(
            templat: "qhull input error: 'Qb%d' or 'QB%d' inverts paraboloid since high bound %.2g < low bound %.2g\n",
            v5,
            v5,
            v10,
            v9);
          qh_errexit(exitcode: 1, facet: nullptr, ridge: nullptr);
        }
        scale = qh_divzero(numer: v10 - v9, denom: v12 - v11, mindenom1: qh_qh.MINdenom_1, zerodiv: &nearzero);
        if ( nearzero != 0 )
        {
          ivp_message(
            templat: "qhull input error: %d'th dimension's new bounds [%2.2g, %2.2g] too wide for\n"
            "existing bounds [%2.2g, %2.2g]\n",
            v5,
            v9,
            v10,
            low,
            v12);
          qh_errexit(exitcode: 1, facet: nullptr, ridge: nullptr);
        }
        v15 = (v12 * v9 - low * v10) / (v12 - v11);
        v16 = scale;
        v17 = v8;
        for ( j = numpoints; j != 0; --j )
        {
          *v17 = *v17 * scale + v15;
          v17 += dim;
        }
        v19 = v8;
        if ( v10 <= v9 )
        {
          v20 = v10;
          v21 = v9;
        }
        else
        {
          v20 = v9;
          v21 = v10;
        }
        v22 = numpoints;
        if ( numpoints != 0 )
        {
          do
          {
            --v22;
            if ( *v19 > v21 )
              *v19 = v21;
            if ( v20 > *v19 )
              *v19 = v20;
            v19 += dim;
          }
          while ( v22 != 0 );
          v16 = scale;
        }
        if ( qh_qh.IStracing != 0 )
          fprintf(
            str: qh_qh.ferr,
            format: "qh_scalepoints: scaled %d'th coordinate [%2.2g, %2.2g] to [%.2g, %.2g] for %d points by %2.2g and shifted %2.2g\n",
            v5,
            low,
            v12,
            v9,
            v10,
            numpoints,
            v16,
            v15);
      }
      ++v5;
      ++v8;
      if ( v5 >= dim )
        break;
      v6 = (char *)newhighs - (char *)newlows;
      v7 = (char *)newlows - (char *)points;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004AA40
// Name: void qh_setdelaunay(int,int,double __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_setdelaunay(int dim, int count, long double *points)
{
  double *v3; // eax
  int i; // esi
  double v5; // xmm0_8
  int v6; // ecx
  double *v7; // eax
  double v8; // xmm0_8
  double v9; // xmm1_8

  if ( qh_qh.IStracing != 0 )
    fprintf(
      str: qh_qh.ferr,
      format: "qh_setdelaunay: project %d points to paraboloid for Delaunay triangulation\n",
      count);
  v3 = points;
  if ( count > 0 )
  {
    for ( i = count; i != 0; --i )
    {
      v5 = *v3;
      v6 = dim - 2;
      v7 = v3 + 1;
      v8 = v5 * v5;
      if ( dim != 2 )
      {
        do
        {
          v9 = *v7++;
          --v6;
          v8 = v8 + v9 * v9;
        }
        while ( v6 != 0 );
      }
      *v7 = v8;
      v3 = v7 + 1;
    }
  }
  if ( qh_qh.last_low < 8.988465674311579e307 )
    qh_scalelast(points, numpoints: count, dim, low: qh_qh.last_low, high: qh_qh.last_high, newhigh: qh_qh.last_newhigh);
}

//------------------------------------------------------------------------------
// Address: 0x1004AAF0
// Name: unsigned int qh_sethalfspace(int,double __near *,double __near * __near *,double __near *,double __near *,double __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl qh_sethalfspace(
        int dim,
        long double *coords,
        long double **nextp,
        long double *normal,
        long double *offset,
        long double *feasible)
{
  double v6; // xmm4_8
  double *v7; // eax
  long double *v8; // esi
  int v9; // edi
  int v10; // ecx
  double v11; // xmm0_8
  double v12; // xmm0_8
  int v13; // ecx
  int v14; // eax
  long double *i; // esi
  int v17; // ebx
  int v18; // eax
  long double denom; // xmm4_8
  double *v20; // ebx
  int j; // esi
  double v22; // [esp+14h] [ebp-20h]
  double dist; // [esp+28h] [ebp-Ch]
  unsigned int zerodiv; // [esp+30h] [ebp-4h] BYREF
  int dima; // [esp+3Ch] [ebp+8h]
  long double *normp; // [esp+48h] [ebp+14h]

  v6 = *offset;
  v7 = normal;
  v8 = coords;
  v9 = dim;
  zerodiv = 0;
  dist = v6;
  v10 = dim;
  if ( dim != 0 )
  {
    do
    {
      v11 = *(double *)((char *)v7 + (char *)feasible - (char *)normal) * *v7;
      ++v7;
      --v10;
      v12 = v11 + v6;
      v6 = v12;
    }
    while ( v10 != 0 );
    v7 = normal;
    dist = v12;
  }
  if ( v6 <= 0.0 )
  {
    if ( COERCE_DOUBLE(*(_QWORD *)&qh_qh.MINdenom ^ _mask__NegDouble_) > v6 )
    {
      v13 = dim;
      if ( dim != 0 )
      {
        v14 = (char *)v7 - (char *)coords;
        do
        {
          *v8 = *(long double *)((char *)v8 + v14) * (-1.0 / v6);
          ++v8;
          --v13;
        }
        while ( v13 != 0 );
      }
      goto LABEL_9;
    }
    v17 = dim;
    if ( dim == 0 )
    {
LABEL_9:
      *nextp = v8;
      if ( qh_qh.IStracing >= 4 )
      {
        ivp_message(templat: "qh_sethalfspace: halfspace at offset %6.2g to point: ", (double)*offset);
        for ( i = coords; v9 != 0; --v9 )
        {
          v22 = *i++;
          ivp_message(templat: " %6.2g", v22);
        }
        ivp_message(templat: "\n");
      }
      return 1;
    }
    v18 = (char *)v7 - (char *)coords;
    *(_QWORD *)&denom = *(_QWORD *)&v6 ^ _mask__NegDouble_;
    for ( dima = v18; ; v18 = dima )
    {
      --v17;
      *v8 = qh_divzero(numer: *(long double *)((char *)v8 + v18), denom, mindenom1: qh_qh.MINdenom_1, &zerodiv);
      ++v8;
      if ( zerodiv != 0 )
        break;
      if ( v17 == 0 )
        goto LABEL_9;
    }
    v7 = normal;
  }
  v20 = feasible;
  normp = v7;
  fprintf(
    str: qh_qh.ferr,
    format: "qhull input error: feasible point is not clearly inside halfspace\nfeasible point: ");
  for ( j = v9; j != 0; --j )
    ivp_message(templat: "%6.16g ", *v20++);
  ivp_message(templat: "\n     halfspace: ");
  for ( ; v9 != 0; ++normp )
  {
    ivp_message(templat: "%6.16g ", (double)*normp);
    --v9;
  }
  ivp_message(templat: "\n     at offset: ");
  ivp_message(templat: "%6.16g ", (double)*offset);
  ivp_message(templat: " and distance: ");
  ivp_message(templat: "%6.16g ", dist);
  ivp_message(templat: "\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1004AD30
// Name: double __near * qh_sethalfspace_all(int,int,double __near *,double __near *)
// Source: json
//------------------------------------------------------------------------------
long double *__usercall qh_sethalfspace_all@<eax>(
        int a1@<edi>,
        long double *dim,
        int count,
        long double *halfspaces,
        long double *feasible)
{
  int v5; // esi
  int v6; // ebx
  long double *v7; // edi
  long double *v8; // eax
  int v9; // esi
  long double *v10; // edi
  long double *newpoints; // [esp+0h] [ebp-4h]

  if ( qh_qh.IStracing != 0 )
    fprintf(str: qh_qh.ferr, format: "qh_sethalfspace_all: compute dual for halfspace intersection\n");
  v5 = count;
  v6 = (int)dim - 1;
  v7 = (long double *)((int (__thiscall *)(IMemAlloc *, int, int))_g_pMemAlloc->Alloc_2)(
                        a1: _g_pMemAlloc,
                        a2: 8 * count * ((_DWORD)dim - 1),
                        a3: a1);
  newpoints = v7;
  if ( v7 == nullptr )
  {
    fprintf(str: qh_qh.ferr, format: "qhull error: insufficient memory to compute dual of %d halfspaces\n", v5);
    qh_errexit(exitcode: 4, facet: nullptr, ridge: nullptr);
  }
  v8 = halfspaces;
  v9 = 0;
  dim = v7;
  if ( count <= 0 )
    return v7;
  do
  {
    v10 = &v8[v6];
    if ( qh_sethalfspace(dim: v6, coords: dim, nextp: &dim, normal: v8, offset: v10, feasible) == 0 )
    {
      ivp_message(templat: "The halfspace was at index %d\n", v9);
      qh_errexit(exitcode: 1, facet: nullptr, ridge: nullptr);
    }
    ++v9;
    v8 = v10 + 1;
  }
  while ( v9 < count );
  return newpoints;
}

//------------------------------------------------------------------------------
// Address: 0x1004AE00
// Name: double __near * qh_voronoi_center(int,struct setT __near *)
// Source: json
//------------------------------------------------------------------------------
long double *__cdecl qh_voronoi_center(int dim, setT *points)
{
  int v2; // eax
  int v3; // esi
  long double *p; // ebx
  long double *gm_matrix; // edi
  int v6; // ecx
  setelemT v7; // eax
  setelemT *e; // edx
  int v9; // ecx
  int v10; // edi
  double v11; // xmm1_8
  unsigned int v12; // esi
  long double **v13; // eax
  long double v14; // xmm0_8
  double v15; // xmm1_8
  double v16; // xmm0_8
  int v17; // eax
  bool v18; // zf
  int v19; // ebx
  long double *v20; // ecx
  long double *v21; // edi
  int v22; // edx
  int j; // eax
  long double *v24; // eax
  setelemT *v25; // esi
  long double v26; // st7
  int v27; // ecx
  unsigned int v28; // eax
  long double *v29; // esi
  setelemT *v30; // edi
  int v31; // eax
  double mindenom1_4; // [esp+14h] [ebp-40h]
  int v34; // [esp+18h] [ebp-3Ch]
  long double det; // [esp+28h] [ebp-2Ch]
  double factor; // [esp+30h] [ebp-24h]
  unsigned int nearzero; // [esp+38h] [ebp-1Ch] BYREF
  long double *sum2row; // [esp+3Ch] [ebp-18h]
  unsigned int infinite; // [esp+40h] [ebp-14h] BYREF
  long double *point0; // [esp+44h] [ebp-10h]
  int i; // [esp+48h] [ebp-Ch]
  long double *center; // [esp+4Ch] [ebp-8h] BYREF
  setT *simplex; // [esp+50h] [ebp-4h] BYREF

  center = (long double *)qh_memalloc(insize: qh_qh.center_size);
  v2 = qh_setsize(set: points);
  v3 = dim;
  if ( v2 == dim + 1 )
  {
    simplex = points;
  }
  else
  {
    v34 = dim + 1;
    if ( v2 < dim + 1 )
    {
      ivp_message(
        templat: "qhull internal error (qh_voronoi_center):\n  need at least %d points to construct a Voronoi center\n",
        v34);
      qh_errexit(exitcode: 5, facet: nullptr, ridge: nullptr);
    }
    simplex = qh_settemp(setsize: v34);
    qh_maxsimplex(dim, maxpoints: points, points: nullptr, numpoints: 0, &simplex);
  }
  p = (long double *)simplex->e[0].p;
  gm_matrix = qh_qh.gm_matrix;
  v6 = 0;
  point0 = p;
  i = (int)qh_qh.gm_matrix;
  if ( dim > 0 )
  {
    do
    {
      qh_qh.gm_row[v6] = gm_matrix;
      if ( simplex != nullptr )
      {
        v7.p = (void *)simplex->e[0];
        e = simplex->e;
        if ( v7.i != 0 )
        {
          do
          {
            ++e;
            if ( v7.p != p )
              *gm_matrix++ = *(double *)(v7.i + 8 * v6) - p[v6];
            v7.p = e->p;
          }
          while ( e->i != 0 );
        }
      }
      ++v6;
    }
    while ( v6 < dim );
    i = (int)gm_matrix;
  }
  sum2row = gm_matrix;
  if ( dim > 0 )
  {
    v9 = 0;
    infinite = dim;
    do
    {
      v10 = 0;
      v11 = 0.0;
      if ( v3 >= 4 )
      {
        v12 = ((unsigned int)(v3 - 4) >> 2) + 1;
        v13 = qh_qh.gm_row + 2;
        v10 = 4 * v12;
        do
        {
          v14 = (*v13)[v9] * (*v13)[v9]
              + (*(v13 - 1))[v9] * (*(v13 - 1))[v9]
              + (*(v13 - 2))[v9] * (*(v13 - 2))[v9]
              + v11;
          v15 = v13[1][v9];
          v13 += 4;
          --v12;
          v11 = v15 * v15 + v14;
        }
        while ( v12 != 0 );
        v3 = dim;
      }
      for ( ; v10 < v3; v11 = v16 * v16 + v11 )
        v16 = qh_qh.gm_row[v10++][v9];
      v17 = i;
      *(double *)i = v11;
      ++v9;
      v18 = infinite-- == 1;
      i = v17 + 8;
    }
    while ( !v18 );
    p = point0;
  }
  det = qh_determinant(rows: qh_qh.gm_row, dim: v3, &nearzero);
  factor = qh_divzero(numer: 0.5, denom: det, mindenom1: qh_qh.MINdenom, zerodiv: &infinite);
  if ( infinite != 0 )
  {
    for ( ; v3 != 0; center[v3] = -10.101 )
      --v3;
    if ( qh_qh.IStracing != 0 )
      qh_printpoints(fp: qh_qh.ferr, string: "qh_voronoi_center: at infinity for ", points: simplex);
  }
  else
  {
    i = 0;
    if ( v3 > 0 )
    {
      infinite = (unsigned int)center;
      v19 = (char *)p - (char *)center;
      do
      {
        v20 = qh_qh.gm_matrix;
        v21 = sum2row;
        v22 = 0;
        do
        {
          qh_qh.gm_row[v22] = v20;
          if ( v22 == i )
          {
            for ( j = v3; j != 0; --j )
              *v20++ = *v21++;
          }
          else
          {
            if ( simplex != nullptr )
            {
              v24 = (long double *)simplex->e[0].p;
              v25 = simplex->e;
              if ( v24 != nullptr )
              {
                do
                {
                  ++v25;
                  if ( v24 != point0 )
                    *v20++ = v24[v22] - point0[v22];
                  v24 = (long double *)v25->i;
                }
                while ( v25->i != 0 );
              }
            }
            v3 = dim;
          }
          ++v22;
        }
        while ( v22 < v3 );
        v26 = qh_determinant(rows: qh_qh.gm_row, dim: v3, &nearzero);
        v27 = i + 1;
        v28 = infinite + 8;
        *(long double *)infinite = v26 * factor + *(double *)(v19 + infinite);
        i = v27;
        infinite = v28;
      }
      while ( v27 < v3 );
    }
    if ( qh_qh.IStracing >= 3 )
    {
      ivp_message(templat: "qh_voronoi_center: det %2.2g factor %2.2g ", (double)det, factor);
      qh_printmatrix(fp: qh_qh.ferr, string: "center:", rows: &center, numrow: 1, numcol: v3);
      if ( qh_qh.IStracing >= 5 )
      {
        qh_printpoints(fp: qh_qh.ferr, string: "points", points: simplex);
        if ( simplex != nullptr )
        {
          v29 = (long double *)simplex->e[0].p;
          v30 = simplex->e;
          if ( v29 != nullptr )
          {
            do
            {
              ++v30;
              mindenom1_4 = qh_pointdist(point1: v29, point2: center, dim);
              v31 = qh_pointid(point: v29);
              ivp_message(templat: "p%d dist %.2g, ", v31, mindenom1_4);
              v29 = (long double *)v30->i;
            }
            while ( v30->i != 0 );
          }
        }
        ivp_message(templat: "\n");
      }
    }
  }
  if ( simplex != points )
    qh_settempfree(set: &simplex);
  return center;
}

//------------------------------------------------------------------------------
// Address: 0x1004B1B0
// Name: double qh_detjoggle(double __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
double __cdecl qh_detjoggle(long double *points, int numpoints, int dimension)
{
  int v3; // edx
  __m128d v4; // xmm4
  __m128d maxabs; // xmm3
  double maxsumabs; // xmm5_8
  __m128d v7; // xmm0
  __m128d v8; // xmm1
  long double *v9; // ecx
  long double *i; // eax
  double v11; // xmm2_8
  __m128d v12; // xmm2
  __m128d v13; // xmm1
  double result; // st7
  double maxwidth; // [esp+14h] [ebp-10h]
  double joggle; // [esp+1Ch] [ebp-8h]

  v3 = 0;
  v4 = 0;
  maxabs = (__m128d)0xFFEFFFFFFFFFFFFFuLL;
  maxsumabs = 0.0;
  maxwidth = 0.0;
  if ( dimension > 0 )
  {
    do
    {
      if ( qh_qh.SCALElast != 0 && v3 == dimension - 1 )
      {
        v7 = v4;
      }
      else if ( qh_qh.DELAUNAY != 0 && v3 == dimension - 1 )
      {
        v7.m128d_f64[1] = maxabs.m128d_f64[1];
        v7.m128d_f64[0] = maxabs.m128d_f64[0] * 2.0 * maxabs.m128d_f64[0];
      }
      else
      {
        v8 = (__m128d)0x7FEFFFFFFFFFFFFFuLL;
        v9 = &points[numpoints * qh_qh.hull_dim];
        v7 = (__m128d)0xFFEFFFFFFFFFFFFFuLL;
        for ( i = points; i < v9; i += qh_qh.hull_dim )
        {
          v11 = i[v3];
          if ( v11 > v7.m128d_f64[0] )
            v7 = (__m128d)*(unsigned __int64 *)&i[v3];
          if ( v8.m128d_f64[0] > v11 )
            v8 = (__m128d)*(unsigned __int64 *)&i[v3];
        }
        v12.m128d_f64[1] = v7.m128d_f64[1];
        if ( v7.m128d_f64[0] - v8.m128d_f64[0] > v4.m128d_f64[0] )
        {
          v12.m128d_f64[0] = v7.m128d_f64[0] - v8.m128d_f64[0];
          v4 = v12;
        }
        v13 = _mm_xor_pd(v8, (__m128d)(unsigned __int64)_mask__NegDouble_);
        if ( v13.m128d_f64[0] > v7.m128d_f64[0] )
          v7 = v13;
      }
      maxsumabs = v7.m128d_f64[0] + maxsumabs;
      if ( v7.m128d_f64[0] > maxabs.m128d_f64[0] )
        maxabs = v7;
      ++v3;
    }
    while ( v3 < dimension );
    maxwidth = v4.m128d_f64[0];
  }
  result = qh_distround(dimension: qh_qh.hull_dim, maxabs: maxabs.m128d_f64[0], maxsumabs) * 30000.0;
  joggle = result;
  if ( result < 6.661338147750939e-12 )
  {
    joggle = 6.661338147750939e-12;
    result = 6.661338147750939e-12;
  }
  if ( qh_qh.IStracing >= 2 )
  {
    fprintf(str: qh_qh.ferr, format: "qh_detjoggle: joggle=%2.2g maxwidth=%2.2g\n", joggle, maxwidth);
    return joggle;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004B350
// Name: void qh_detroundoff(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_detroundoff()
{
  unsigned int RANDOMdist; // eax
  double ANGLEround; // xmm0_8
  double DISTround; // xmm3_8
  double premerge_centrum; // xmm5_8
  double premerge_cos; // xmm0_8
  double hull_dim; // xmm1_8
  double ONEmerge; // xmm0_8
  double v7; // xmm1_8
  double JOGGLEmax; // xmm2_8
  double v9; // xmm0_8
  double v10; // xmm1_8
  double MINvisible; // xmm0_8
  double MAXcoplanar; // xmm1_8
  double v13; // xmm0_8
  double MINoutside; // xmm2_8
  double v15; // xmm1_8
  double v16; // xmm0_8

  qh_option(option: "_max-width", i: nullptr, r: &qh_qh.MAXwidth);
  if ( qh_qh.SETroundoff == 0 )
  {
    qh_qh.DISTround = qh_distround(dimension: qh_qh.hull_dim, maxabs: qh_qh.MAXabs_coord, maxsumabs: qh_qh.MAXsumcoord);
    if ( qh_qh.RANDOMdist != 0 )
      qh_qh.DISTround = qh_qh.RANDOMfactor * qh_qh.MAXabs_coord + qh_qh.DISTround;
    qh_option(option: "Error-roundoff", i: nullptr, r: &qh_qh.DISTround);
  }
  RANDOMdist = qh_qh.RANDOMdist;
  qh_qh.MINdenom = qh_qh.MAXabs_coord * 2.225073858507201e-308;
  ANGLEround = (double)qh_qh.hull_dim * 1.01 * 2.220446049250313e-16;
  qh_qh.MINdenom_1 = 2.225073858507201e-308;
  qh_qh.MINdenom_1_2 = sqrt((double)qh_qh.hull_dim * 2.225073858507201e-308);
  qh_qh.MINdenom_2 = qh_qh.MINdenom_1_2 * qh_qh.MAXabs_coord;
  qh_qh.ANGLEround = ANGLEround;
  if ( qh_qh.RANDOMdist != 0 )
  {
    ANGLEround = ANGLEround + qh_qh.RANDOMfactor;
    qh_qh.ANGLEround = ANGLEround;
  }
  if ( qh_qh.premerge_cos < 8.988465674311579e307 )
  {
    qh_qh.premerge_cos = qh_qh.premerge_cos - ANGLEround;
    if ( qh_qh.RANDOMdist != 0 )
    {
      qh_option(option: "Angle-premerge-with-random", i: nullptr, r: &qh_qh.premerge_cos);
      ANGLEround = qh_qh.ANGLEround;
      RANDOMdist = qh_qh.RANDOMdist;
    }
  }
  if ( qh_qh.postmerge_cos < 8.988465674311579e307 )
  {
    qh_qh.postmerge_cos = qh_qh.postmerge_cos - ANGLEround;
    if ( RANDOMdist != 0 )
    {
      qh_option(option: "Angle-postmerge-with-random", i: nullptr, r: &qh_qh.postmerge_cos);
      RANDOMdist = qh_qh.RANDOMdist;
    }
  }
  DISTround = qh_qh.DISTround;
  premerge_centrum = qh_qh.DISTround * 2.0 + qh_qh.premerge_centrum;
  qh_qh.premerge_centrum = premerge_centrum;
  qh_qh.postmerge_centrum = qh_qh.DISTround * 2.0 + qh_qh.postmerge_centrum;
  if ( RANDOMdist != 0 )
  {
    if ( qh_qh.MERGEexact != 0 || qh_qh.PREmerge != 0 )
    {
      qh_option(option: "Centrum-premerge-with-random", i: nullptr, r: &qh_qh.premerge_centrum);
      DISTround = qh_qh.DISTround;
      RANDOMdist = qh_qh.RANDOMdist;
      premerge_centrum = qh_qh.premerge_centrum;
    }
    if ( RANDOMdist != 0 && qh_qh.POSTmerge != 0 )
    {
      qh_option(option: "Centrum-postmerge-with-random", i: nullptr, r: &qh_qh.postmerge_centrum);
      DISTround = qh_qh.DISTround;
      premerge_centrum = qh_qh.premerge_centrum;
    }
  }
  premerge_cos = 1.0;
  if ( qh_qh.premerge_cos < 1.0 )
    premerge_cos = qh_qh.premerge_cos;
  if ( premerge_cos > qh_qh.postmerge_cos )
    premerge_cos = qh_qh.postmerge_cos;
  hull_dim = (double)qh_qh.hull_dim;
  ONEmerge = sqrt(1.0 - premerge_cos * premerge_cos) * (sqrt((double)qh_qh.hull_dim) * qh_qh.MAXwidth) + DISTround;
  qh_qh.ONEmerge = ONEmerge;
  if ( (double)qh_qh.hull_dim * premerge_centrum + DISTround > ONEmerge )
  {
    ONEmerge = hull_dim * premerge_centrum + DISTround;
    qh_qh.ONEmerge = ONEmerge;
  }
  v7 = hull_dim * qh_qh.postmerge_centrum + DISTround;
  if ( v7 > ONEmerge )
  {
    ONEmerge = v7;
    qh_qh.ONEmerge = v7;
  }
  if ( qh_qh.MERGING != 0 )
  {
    qh_option(option: "_one-merge", i: nullptr, r: &qh_qh.ONEmerge);
    ONEmerge = qh_qh.ONEmerge;
    DISTround = qh_qh.DISTround;
    premerge_centrum = qh_qh.premerge_centrum;
  }
  JOGGLEmax = qh_qh.JOGGLEmax;
  v9 = ONEmerge * 5.0;
  qh_qh.NEARinside = v9;
  if ( qh_qh.JOGGLEmax < 8.988465674311579e307 && (qh_qh.KEEPcoplanar != 0 || qh_qh.KEEPinside != 0) )
  {
    v10 = (sqrt((double)qh_qh.hull_dim) * qh_qh.JOGGLEmax + DISTround) * 2.0;
    qh_qh.KEEPnearinside = 1;
    if ( v10 > v9 )
      qh_qh.NEARinside = v10;
  }
  else if ( qh_qh.KEEPnearinside == 0 )
  {
    goto LABEL_37;
  }
  qh_option(option: "_near-inside", i: nullptr, r: &qh_qh.NEARinside);
  JOGGLEmax = qh_qh.JOGGLEmax;
  DISTround = qh_qh.DISTround;
  premerge_centrum = qh_qh.premerge_centrum;
LABEL_37:
  if ( DISTround > JOGGLEmax )
  {
    ivp_message(
      templat: "qhull error: the joggle for 'QJn', %.2g, is below roundoff for distance computations, %.2g\n",
      JOGGLEmax,
      DISTround);
    qh_errexit(exitcode: 1, facet: nullptr, ridge: nullptr);
  }
  MINvisible = qh_qh.MINvisible;
  if ( qh_qh.MINvisible > 8.988465674311579e307 )
  {
    if ( qh_qh.MERGING != 0 )
    {
      if ( qh_qh.hull_dim > 3 )
        premerge_centrum = premerge_centrum * 3.0;
      DISTround = premerge_centrum;
    }
    qh_qh.MINvisible = DISTround;
    if ( qh_qh.APPROXhull != 0 && DISTround > qh_qh.MINoutside )
      qh_qh.MINvisible = qh_qh.MINoutside;
    qh_option(option: "Visible-distance", i: nullptr, r: &qh_qh.MINvisible);
    MINvisible = qh_qh.MINvisible;
  }
  MAXcoplanar = qh_qh.MAXcoplanar;
  if ( qh_qh.MAXcoplanar > 8.988465674311579e307 )
  {
    qh_qh.MAXcoplanar = MINvisible;
    qh_option(option: "U-coplanar-distance", i: nullptr, r: &qh_qh.MAXcoplanar);
    MINvisible = qh_qh.MINvisible;
    MAXcoplanar = qh_qh.MAXcoplanar;
  }
  if ( qh_qh.APPROXhull == 0 )
  {
    v13 = MINvisible * 2.0;
    qh_qh.MINoutside = v13;
    if ( qh_qh.premerge_cos < 8.988465674311579e307 && (1.0 - qh_qh.premerge_cos) * qh_qh.MAXabs_coord > v13 )
      qh_qh.MINoutside = (1.0 - qh_qh.premerge_cos) * qh_qh.MAXabs_coord;
    qh_option(option: "Width-outside", i: nullptr, r: &qh_qh.MINoutside);
    MINvisible = qh_qh.MINvisible;
    MAXcoplanar = qh_qh.MAXcoplanar;
  }
  MINoutside = qh_qh.MINoutside;
  v15 = MAXcoplanar * 6.0;
  qh_qh.WIDEfacet = qh_qh.MINoutside;
  if ( v15 > qh_qh.MINoutside )
  {
    MINoutside = v15;
    qh_qh.WIDEfacet = v15;
  }
  v16 = MINvisible * 6.0;
  if ( v16 > MINoutside )
    qh_qh.WIDEfacet = v16;
  qh_option(option: "_wide-facet", i: nullptr, r: &qh_qh.WIDEfacet);
  if ( qh_qh.MINvisible > qh_qh.MINoutside + 6.661338147750939e-16 && qh_qh.BESToutside == 0 && qh_qh.FORCEoutput == 0 )
    ivp_message(
      templat: "qhull input warning: minimum visibility V%.2g is greater than \n"
      "minimum outside W%.2g.  Flipped facets are likely.\n",
      (double)qh_qh.MINvisible,
      (double)qh_qh.MINoutside);
  qh_qh.max_vertex = qh_qh.DISTround;
  qh_qh.min_vertex = -qh_qh.DISTround;
}

//------------------------------------------------------------------------------
// Address: 0x1004B960
// Name: double qh_facetarea(struct facetT __near *)
// Source: json
//------------------------------------------------------------------------------
double __cdecl qh_facetarea(facetT *facet)
{
  setT *ridges; // edi
  setelemT v3; // eax
  setelemT *e; // edi
  double v5; // st7
  double area; // [esp+10h] [ebp-8h]
  long double *centrum; // [esp+20h] [ebp+8h]

  area = 0.0;
  if ( (*((_DWORD *)facet + 20) & 0x1000) != 0 )
  {
    area = qh_facetarea_simplex(
             dim: qh_qh.hull_dim,
             apex: (long double *)*(_DWORD *)(facet->vertices->e[0].i + 8),
             vertices: facet->vertices,
             notvertex: (vertexT *)facet->vertices->e[0].p,
             toporient: (*((_DWORD *)facet + 20) & 0x800) != 0,
             normal: facet->normal,
             offset: &facet->offset);
  }
  else
  {
    if ( qh_qh.CENTERtype == qh_AScentrum )
      centrum = facet->center;
    else
      centrum = qh_getcentrum(facet);
    ridges = facet->ridges;
    if ( ridges != nullptr )
    {
      v3.p = (void *)ridges->e[0];
      e = ridges->e;
      if ( v3.i != 0 )
      {
        do
        {
          ++e;
          v5 = qh_facetarea_simplex(
                 dim: qh_qh.hull_dim,
                 apex: centrum,
                 vertices: (setT *)*(_DWORD *)v3.p,
                 notvertex: nullptr,
                 toporient: *(_DWORD *)(v3.i + 4) == (_DWORD)facet,
                 normal: facet->normal,
                 offset: &facet->offset);
          v3.p = e->p;
          area = v5 + area;
        }
        while ( e->i != 0 );
      }
    }
    if ( qh_qh.CENTERtype != qh_AScentrum )
      qh_memfree(object: centrum, size: qh_qh.normal_size);
  }
  if ( (*((_BYTE *)facet + 82) & 1) != 0 && qh_qh.DELAUNAY != 0 )
    area = -area;
  if ( qh_qh.IStracing >= 4 )
    fprintf(str: qh_qh.ferr, format: "qh_facetarea: f%d area %2.2g\n", facet->id, area);
  return area;
}

//------------------------------------------------------------------------------
// Address: 0x1004BA90
// Name: double __near * qh_facetcenter(struct setT __near *)
// Source: json
//------------------------------------------------------------------------------
long double *__cdecl qh_facetcenter(setT *vertices)
{
  setT *v1; // esi
  int v2; // eax
  setelemT v3; // eax
  setelemT *e; // esi
  long double *v5; // esi

  v1 = vertices;
  v2 = qh_setsize(set: vertices);
  vertices = qh_settemp(setsize: v2);
  if ( v1 != nullptr )
  {
    v3.p = (void *)v1->e[0];
    e = v1->e;
    if ( v3.i != 0 )
    {
      do
      {
        ++e;
        qh_setappend(setp: &vertices, newelem: *(void **)(v3.i + 8));
        v3.p = e->p;
      }
      while ( e->i != 0 );
    }
  }
  v5 = qh_voronoi_center(dim: qh_qh.hull_dim - 1, points: vertices);
  qh_settempfree(set: &vertices);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1004BB00
// Name: void qh_getarea(struct facetT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_getarea(facetT *facetlist)
{
  facetT *v1; // esi
  double v2; // st7
  double v3; // xmm0_8
  long double dist; // [esp+0h] [ebp-10h] BYREF
  double area; // [esp+8h] [ebp-8h]

  if ( qh_qh.REPORTfreq != 0 )
  {
    ivp_message(templat: "computing area of each facet and volume of the convex hull\n");
  }
  else if ( qh_qh.IStracing >= 1 )
  {
    fprintf(str: qh_qh.ferr, format: "qh_getarea: computing volume and area for each facet\n");
  }
  v1 = facetlist;
  qh_qh.totvol = 0.0;
  for ( qh_qh.totarea = 0.0; v1 != nullptr; v1 = v1->next )
  {
    if ( v1->next == nullptr )
      break;
    if ( v1->normal != nullptr && ((*((_BYTE *)v1 + 82) & 1) == 0 || qh_qh.ATinfinity == 0) )
    {
      v2 = qh_facetarea(facet: v1);
      area = v2;
      *((_DWORD *)v1 + 20) |= 0x80000u;
      v1->f.area = v2;
      v3 = area;
      if ( qh_qh.DELAUNAY != 0 )
      {
        if ( ((*((_DWORD *)v1 + 20) & 0x10000) != 0) == qh_qh.UPPERdelaunay )
          qh_qh.totarea = qh_qh.totarea + area;
      }
      else
      {
        qh_qh.totarea = qh_qh.totarea + area;
        qh_distplane(point: qh_qh.interior_point, facet: v1, &dist);
        v3 = area;
        qh_qh.totvol = qh_qh.totvol - dist * area / (double)qh_qh.hull_dim;
      }
      if ( qh_qh.PRINTstatistics != 0 )
      {
        qh_qhstat.stats[8].r = qh_qhstat.stats[8].r + v3;
        if ( v3 > qh_qhstat.stats[9].r )
          qh_qhstat.stats[9].r = v3;
        if ( qh_qhstat.stats[10].r > v3 )
          qh_qhstat.stats[10].r = v3;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004BC90
// Name: void qh_joggleinput(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall qh_joggleinput(void *this)
{
  double JOGGLEmax; // xmm1_8
  double v2; // xmm0_8
  long double *input_points; // ebx
  int v4; // esi
  double v5; // xmm1_8
  long double *first_point; // edi
  double i; // xmm2_8
  int seed; // [esp+Ch] [ebp-4h] BYREF

  seed = (int)this;
  if ( qh_qh.input_points != nullptr )
  {
    if ( qh_qh.RERUN == 0 && qh_qh.build_cnt > 2 )
    {
      JOGGLEmax = qh_qh.JOGGLEmax;
      if ( qh_qh.MAXwidth * 0.01 > qh_qh.JOGGLEmax )
      {
        qh_qh.JOGGLEmax = qh_qh.JOGGLEmax * 10.0;
        if ( JOGGLEmax * 10.0 > qh_qh.MAXwidth * 0.01 )
          qh_qh.JOGGLEmax = qh_qh.MAXwidth * 0.01;
      }
    }
    qh_option(option: "QJoggle", i: nullptr, r: &qh_qh.JOGGLEmax);
  }
  else
  {
    qh_qh.input_points = qh_qh.first_point;
    qh_qh.input_malloc = qh_qh.POINTSmalloc;
    qh_qh.first_point = (long double *)_g_pMemAlloc->Alloc_2(
                                         this: _g_pMemAlloc,
                                         a2: 8 * qh_qh.num_points * qh_qh.hull_dim);
    if ( qh_qh.first_point == nullptr )
    {
      fprintf(str: qh_qh.ferr, format: "qhull error: insufficient memory to joggle %d points\n", qh_qh.num_points);
      qh_errexit(exitcode: 4, facet: nullptr, ridge: nullptr);
    }
    qh_qh.POINTSmalloc = 1;
    if ( qh_qh.JOGGLEmax == 0.0 )
    {
      qh_qh.JOGGLEmax = qh_detjoggle(points: qh_qh.input_points, numpoints: qh_qh.num_points, dimension: qh_qh.hull_dim);
      qh_option(option: "QJoggle", i: nullptr, r: &qh_qh.JOGGLEmax);
    }
  }
  if ( qh_qh.build_cnt > 1 )
  {
    v2 = qh_qh.MAXwidth * 0.25;
    if ( qh_qh.MAXwidth * 0.25 < 0.1 )
      v2 = 0.1;
    if ( qh_qh.JOGGLEmax > v2 )
    {
      ivp_message(
        templat: "qhull error: the current joggle for 'QJn', %.2g, is too large for the width\n"
        "of the input.  If possible, recompile Qhull with higher-precision reals.\n",
        (double)qh_qh.JOGGLEmax);
      qh_errexit(exitcode: 5, facet: nullptr, ridge: nullptr);
    }
  }
  seed = qh_rand();
  qh_option(option: "_joggle-seed", i: &seed, r: nullptr);
  if ( qh_qh.IStracing != 0 )
    fprintf(
      str: qh_qh.ferr,
      format: "qh_joggleinput: joggle input by %2.2g with seed %d\n",
      (double)qh_qh.JOGGLEmax,
      seed);
  input_points = qh_qh.input_points;
  v4 = qh_qh.num_points * qh_qh.hull_dim;
  v5 = qh_qh.JOGGLEmax * 2.0 * 4.656612877414201e-10;
  first_point = qh_qh.first_point;
  for ( i = -qh_qh.JOGGLEmax; v4 != 0; --v4 )
    *first_point++ = (double)qh_rand() * v5 + i + *input_points++;
  if ( qh_qh.DELAUNAY != 0 )
  {
    qh_qh.last_newhigh = 1.797693134862316e308;
    qh_qh.last_high = 1.797693134862316e308;
    qh_qh.last_low = 1.797693134862316e308;
    qh_setdelaunay(dim: qh_qh.hull_dim, count: qh_qh.num_points, points: qh_qh.first_point);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004BF30
// Name: struct setT __near * qh_maxmin(double __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
setT *__cdecl qh_maxmin(long double *points, int numpoints, int dimension)
{
  int v3; // esi
  int v4; // edi
  setT *result; // eax
  long double *v6; // eax
  long double *v7; // ecx
  long double *v8; // edi
  double *v9; // ebx
  double v10; // xmm0_8
  double MAXwidth; // xmm0_8
  double v12; // xmm1_8
  double v13; // xmm2_8
  double v14; // xmm1_8
  long double *minimum; // [esp+0h] [ebp-8h]
  setT *set; // [esp+4h] [ebp-4h] BYREF

  v3 = 0;
  qh_qh.max_outside = 0.0;
  qh_qh.MAXabs_coord = 0.0;
  qh_qh.MAXwidth = -1.797693134862316e308;
  qh_qh.MAXsumcoord = 0.0;
  qh_qh.min_vertex = 0.0;
  qh_qh.WAScoplanar = 0;
  if ( qh_qh.ZEROcentrum != 0 )
    qh_qh.ZEROall_ok = 1;
  v4 = dimension;
  result = qh_settemp(setsize: 2 * dimension);
  set = result;
  if ( dimension > 0 )
  {
    do
    {
      v6 = points;
      if ( points == qh_qh.GOODpointp )
      {
        v7 = &points[v4];
        minimum = v7;
      }
      else
      {
        v7 = points;
        minimum = points;
      }
      v8 = &points[numpoints * qh_qh.hull_dim];
      v9 = minimum;
      if ( points < v8 )
      {
        do
        {
          if ( v6 != qh_qh.GOODpointp )
          {
            v10 = v6[v3];
            if ( v10 <= v7[v3] )
            {
              if ( v9[v3] > v10 )
                v9 = v6;
            }
            else
            {
              v7 = v6;
            }
          }
          v6 += qh_qh.hull_dim;
        }
        while ( v6 < v8 );
      }
      v4 = dimension;
      if ( v3 == dimension - 1 )
      {
        qh_qh.MINlastcoord = v9[v3];
        qh_qh.MAXlastcoord = v7[v3];
      }
      if ( qh_qh.SCALElast != 0 && v3 == dimension - 1 )
      {
        MAXwidth = qh_qh.MAXwidth;
      }
      else
      {
        v12 = v7[v3];
        *(_QWORD *)&MAXwidth = *(_QWORD *)&v9[v3] ^ _mask__NegDouble_;
        if ( MAXwidth <= v12 )
          MAXwidth = v7[v3];
        if ( qh_qh.GOODpointp != nullptr )
        {
          v13 = qh_qh.GOODpointp[v3];
          if ( COERCE_DOUBLE(*(_QWORD *)&v13 ^ _mask__NegDouble_) > v13 )
            *(_QWORD *)&v13 ^= _mask__NegDouble_;
          if ( v13 > MAXwidth )
            MAXwidth = v13;
        }
        v14 = v12 - v9[v3];
        if ( v14 > qh_qh.MAXwidth )
          qh_qh.MAXwidth = v14;
      }
      if ( MAXwidth > qh_qh.MAXabs_coord )
        qh_qh.MAXabs_coord = MAXwidth;
      qh_qh.MAXsumcoord = qh_qh.MAXsumcoord + MAXwidth;
      qh_setappend(setp: &set, newelem: v7);
      qh_setappend(setp: &set, newelem: v9);
      qh_qh.NEARzero[v3++] = qh_qh.MAXsumcoord * 80.0 * 2.220446049250313e-16;
    }
    while ( v3 < dimension );
    result = set;
  }
  if ( qh_qh.IStracing >= 1 )
  {
    qh_printpoints(fp: qh_qh.ferr, string: "qh_maxmin: found the max and min points (by dim):", points: result);
    return set;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004C140
// Name: void qh_projectinput(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_projectinput()
{
  int input_dim; // edi
  unsigned int v1; // ebx
  unsigned __int8 *v2; // esi
  int i; // ecx
  int v4; // ebx
  long double *v5; // eax
  long double *v6; // ebx
  int v7; // edi
  int v8; // eax
  double *v9; // ecx
  long double *v10; // edx
  int num_points; // esi
  double v12; // xmm2_8
  int v13; // eax
  double v14; // xmm1_8
  double v15; // xmm0_8
  int v16; // eax
  int newnum; // [esp+8h] [ebp-4h]

  input_dim = qh_qh.input_dim;
  v1 = qh_qh.input_dim + 1;
  newnum = qh_qh.num_points;
  v2 = (unsigned __int8 *)qh_memalloc(insize: qh_qh.input_dim + 1);
  memset(dst: v2, value: 0, count: v1);
  for ( i = 0; i < qh_qh.input_dim; ++i )
  {
    if ( qh_qh.lower_bound[i] == 0.0 && qh_qh.upper_bound[i] == 0.0 )
    {
      v2[i] = -1;
      --input_dim;
    }
  }
  if ( qh_qh.DELAUNAY != 0 && (v2[i] = 1, ++input_dim, qh_qh.ATinfinity != 0) )
    v4 = newnum + 1;
  else
    v4 = newnum;
  if ( input_dim != qh_qh.hull_dim )
  {
    fprintf(
      str: qh_qh.ferr,
      format: "qhull internal error (qh_projectinput): dimension after projection %d != hull_dim %d\n",
      input_dim,
      qh_qh.hull_dim);
    qh_errexit(exitcode: 5, facet: nullptr, ridge: nullptr);
  }
  v5 = (long double *)p_malloc(size: 8 * input_dim * v4);
  v6 = v5;
  if ( v5 == nullptr )
  {
    fprintf(str: qh_qh.ferr, format: "qhull error: insufficient memory to project %d points\n", qh_qh.num_points);
    qh_errexit(exitcode: 4, facet: nullptr, ridge: nullptr);
  }
  qh_projectpoints(
    project: (char *)v2,
    n: qh_qh.input_dim + 1,
    points: qh_qh.first_point,
    numpoints: qh_qh.num_points,
    dim: qh_qh.input_dim,
    newpoints: v5,
    newdim: input_dim);
  if ( qh_qh.IStracing >= 1 )
    fprintf(str: qh_qh.ferr, format: "qh_projectinput: updating lower and upper_bound\n");
  v7 = input_dim + 1;
  qh_projectpoints(
    project: (char *)v2,
    n: qh_qh.input_dim + 1,
    points: qh_qh.lower_bound,
    numpoints: 1,
    dim: qh_qh.input_dim + 1,
    newpoints: qh_qh.lower_bound,
    newdim: v7);
  qh_projectpoints(
    project: (char *)v2,
    n: qh_qh.input_dim + 1,
    points: qh_qh.upper_bound,
    numpoints: 1,
    dim: qh_qh.input_dim + 1,
    newpoints: qh_qh.upper_bound,
    newdim: v7);
  qh_memfree(object: v2, size: qh_qh.input_dim + 1);
  if ( qh_qh.POINTSmalloc != 0 && qh_qh.first_point != nullptr )
    free(data: qh_qh.first_point);
  qh_qh.first_point = v6;
  qh_qh.POINTSmalloc = 1;
  if ( qh_qh.DELAUNAY != 0 )
  {
    if ( qh_qh.ATinfinity != 0 )
    {
      v8 = qh_qh.hull_dim - 1;
      v9 = v6;
      v10 = &v6[qh_qh.num_points * qh_qh.hull_dim];
      if ( qh_qh.hull_dim != 1 )
      {
        do
          v10[--v8] = 0.0;
        while ( v8 != 0 );
      }
      num_points = qh_qh.num_points;
      v12 = 0.0;
      while ( num_points != 0 )
      {
        --num_points;
        v13 = qh_qh.hull_dim - 1;
        v14 = 0.0;
        if ( qh_qh.hull_dim != 1 )
        {
          do
          {
            v15 = *v9;
            --v13;
            ++v9;
            v14 = v14 + v15 * v15;
            v10[v13] = v15 + v10[v13];
          }
          while ( v13 != 0 );
        }
        *v9++ = v14;
        if ( v14 > v12 )
          v12 = v14;
      }
      v16 = qh_qh.hull_dim - 1;
      if ( qh_qh.hull_dim != 1 )
      {
        do
        {
          *v9 = *v9 / (double)qh_qh.num_points;
          ++v9;
          --v16;
        }
        while ( v16 != 0 );
      }
      *v9 = v12 * 1.1;
      ++qh_qh.num_points;
      if ( qh_qh.IStracing != 0 )
        fprintf(str: qh_qh.ferr, format: "qh_projectinput: projected points to paraboloid for Delaunay\n");
    }
    else
    {
      qh_setdelaunay(dim: qh_qh.hull_dim, count: qh_qh.num_points, points: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004C420
// Name: void qh_rotateinput(double __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_rotateinput(long double **rows)
{
  if ( qh_qh.POINTSmalloc == 0 )
  {
    qh_qh.first_point = qh_copypoints(points: qh_qh.first_point, numpoints: qh_qh.num_points, dimension: qh_qh.hull_dim);
    qh_qh.POINTSmalloc = 1;
  }
  qh_rotatepoints(points: qh_qh.first_point, numpoints: qh_qh.num_points, dim: qh_qh.hull_dim, row: rows);
}

//------------------------------------------------------------------------------
// Address: 0x1004C480
// Name: void qh_scaleinput(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_scaleinput()
{
  if ( qh_qh.POINTSmalloc == 0 )
  {
    qh_qh.first_point = qh_copypoints(points: qh_qh.first_point, numpoints: qh_qh.num_points, dimension: qh_qh.hull_dim);
    qh_qh.POINTSmalloc = 1;
  }
  qh_scalepoints(
    points: qh_qh.first_point,
    numpoints: qh_qh.num_points,
    dim: qh_qh.hull_dim,
    newlows: qh_qh.lower_bound,
    newhighs: qh_qh.upper_bound);
}
