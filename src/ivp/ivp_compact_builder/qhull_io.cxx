// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_compact_builder/qhull_io.cxx
// Functions: 65
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10060EA0
// Name: qh_compare_facetarea
// Source: json
//------------------------------------------------------------------------------
int __cdecl qh_compare_facetarea(const void *p1, int *p2)
{
  int v2; // ecx
  double v4; // xmm0_8
  double v5; // xmm1_8

  v2 = *p2;
  if ( (*(_DWORD *)(*(_DWORD *)p1 + 80) & 0x80000) == 0 )
    return -1;
  if ( (*(_DWORD *)(v2 + 80) & 0x80000) == 0 )
    return 1;
  v4 = *(double *)(*(_DWORD *)p1 + 32);
  v5 = *(double *)(v2 + 32);
  if ( v4 > v5 )
    return 1;
  if ( v4 == v5 )
    return 0;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10060EF0
// Name: qh_compare_facetmerge
// Source: json
//------------------------------------------------------------------------------
int __cdecl qh_compare_facetmerge(const void *p1, const void *p2)
{
  return (*(_DWORD *)(*(_DWORD *)p1 + 80) & 0x1FF) - (*(_DWORD *)(*(_DWORD *)p2 + 80) & 0x1FF);
}

//------------------------------------------------------------------------------
// Address: 0x10060F20
// Name: qh_compare_facetvisit
// Source: json
//------------------------------------------------------------------------------
int __cdecl qh_compare_facetvisit(const void *p1, int *p2)
{
  int v2; // eax
  int v3; // edx
  int v4; // ecx

  v2 = *(_DWORD *)(*(_DWORD *)p1 + 72);
  v3 = *p2;
  if ( v2 == 0 )
    v2 = -*(_DWORD *)(*(_DWORD *)p1 + 76);
  v4 = *(_DWORD *)(v3 + 72);
  if ( v4 == 0 )
    v4 = -*(_DWORD *)(v3 + 76);
  return v2 - v4;
}

//------------------------------------------------------------------------------
// Address: 0x10060F50
// Name: double __near * qh_detvnorm(struct vertexT __near *,struct vertexT __near *,struct setT __near *,double __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
long double *__cdecl qh_detvnorm(vertexT *vertex, int vertexA, setT *centers, long double *offsetp)
{
  long double *v4; // ebx
  int v5; // eax
  long double *v7; // edx
  double *v8; // ecx
  int v9; // edi
  unsigned int v10; // edx
  double *v11; // eax
  int v12; // edi
  double v13; // xmm1_8
  int v14; // edi
  int v15; // edx
  double *v16; // ecx
  char *v17; // edi
  setelemT v18; // edi
  setelemT *e; // eax
  setT *v20; // eax
  long double *v21; // edx
  long double *gm_matrix; // edi
  setelemT *v23; // ecx
  long double *p; // eax
  long double *v25; // ecx
  int v26; // eax
  int v27; // ecx
  long double *v28; // eax
  int v29; // ecx
  long double *v30; // eax
  double v31; // st7
  double v32; // xmm0_8
  int v33; // eax
  long double *v34; // edx
  double *v35; // ecx
  int v36; // edi
  unsigned int v37; // edx
  double *v38; // eax
  char *v39; // edi
  double v40; // xmm0_8
  int v41; // edi
  double v42; // xmm0_8
  int v43; // edi
  double *v44; // ecx
  int v45; // esi
  double v46; // xmm0_8
  setT *v47; // eax
  int v48; // ebx
  int v49; // esi
  long double *v50; // ecx
  setelemT v51; // ebx
  double v52; // xmm0_8
  double zero; // [esp+18h] [ebp-50h] BYREF
  long double offset; // [esp+20h] [ebp-48h] BYREF
  double v56; // [esp+28h] [ebp-40h] OVERLAPPED
  long double *midpoint; // [esp+30h] [ebp-38h]
  long double *point0; // [esp+34h] [ebp-34h]
  unsigned int nearzero; // [esp+38h] [ebp-30h] BYREF
  double v60; // [esp+3Ch] [ebp-2Ch] OVERLAPPED
  int v61; // [esp+44h] [ebp-24h]
  int v62; // [esp+48h] [ebp-20h]
  int v63; // [esp+4Ch] [ebp-1Ch]
  unsigned int unbounded; // [esp+50h] [ebp-18h]
  int numcenters; // [esp+54h] [ebp-14h]
  setT *points; // [esp+58h] [ebp-10h] BYREF
  setT *simplex; // [esp+5Ch] [ebp-Ch] BYREF
  long double *point; // [esp+60h] [ebp-8h] BYREF
  int dim; // [esp+64h] [ebp-4h]
  int i; // [esp+74h] [ebp+Ch]
  int ia; // [esp+74h] [ebp+Ch]
  int ib; // [esp+74h] [ebp+Ch]
  int ic; // [esp+74h] [ebp+Ch]
  char *id; // [esp+74h] [ebp+Ch]
  int ie; // [esp+74h] [ebp+Ch]

  simplex = nullptr;
  points = qh_settemp(setsize: qh_qh.TEMPsize);
  v4 = &qh_qh.gm_matrix[qh_qh.hull_dim * qh_qh.hull_dim];
  v5 = 0;
  nearzero = 0;
  unbounded = 0;
  numcenters = 0;
  zero = 0.0;
  dim = qh_qh.hull_dim - 1;
  midpoint = v4;
  if ( qh_qh.hull_dim - 1 >= 4 )
  {
    v7 = vertex->point;
    v8 = v7 + 3;
    i = (char *)v7 - (char *)v4;
    v62 = 8 - (_DWORD)v4;
    v61 = 16 - (_DWORD)v4;
    v9 = -8 - (_DWORD)v4;
    v10 = ((unsigned int)(dim - 4) >> 2) + 1;
    v11 = v4 + 1;
    v63 = -8 - (_DWORD)v4;
    HIDWORD(v60) = 4 * v10;
    while ( 1 )
    {
      *(v11 - 1) = (*(double *)((char *)v11 + v9 + *(_DWORD *)(vertexA + 8)) + *(v8 - 3)) * 0.5;
      v12 = v62;
      *v11 = (*(double *)((char *)v11 + i) + *(double *)((char *)v11 + v63 + *(_DWORD *)(vertexA + 8) + 8)) * 0.5;
      v13 = *(double *)((char *)v11 + v12 + *(_DWORD *)(vertexA + 8)) + *(v8 - 1);
      v14 = v61;
      v11[1] = v13 * 0.5;
      v11[2] = (*(double *)((char *)v11 + v14 + *(_DWORD *)(vertexA + 8)) + *v8) * 0.5;
      v11 += 4;
      v8 += 4;
      if ( --v10 == 0 )
        break;
      v9 = v63;
    }
    v4 = midpoint;
    v5 = HIDWORD(v60);
  }
  v15 = dim;
  if ( v5 < dim )
  {
    v16 = &v4[v5];
    v17 = (char *)((char *)vertex->point - (char *)v4);
    do
    {
      v15 = dim;
      *v16 = (*(double *)(*(_DWORD *)(vertexA + 8) + 8 * v5++) + *(double *)&v17[(_DWORD)v16]) * 0.5;
      ++v16;
    }
    while ( v5 < v15 );
  }
  if ( centers != nullptr )
  {
    v18.p = (void *)centers->e[0];
    e = centers->e;
    if ( v18.i != 0 )
    {
      do
      {
        ++numcenters;
        ia = (int)++e;
        if ( *(_DWORD *)(v18.i + 72) != 0 )
        {
          if ( *(_DWORD *)(v18.i + 40) == 0 )
            *(_DWORD *)(v18.i + 40) = qh_facetcenter(vertices: *(setT **)(v18.i + 52));
          qh_setappend(setp: &points, newelem: *(void **)(v18.i + 40));
          e = (setelemT *)ia;
        }
        else
        {
          unbounded = 1;
        }
        v18.p = e->p;
      }
      while ( e->i != 0 );
      v15 = dim;
    }
  }
  if ( numcenters <= v15 )
  {
    if ( numcenters != v15 )
    {
      ivp_message(templat: "qh_detvnorm: too few points (%d) to compute separating plane\n", numcenters);
      qh_errexit(exitcode: 5, facet: nullptr, ridge: nullptr);
    }
    if ( unbounded != 0 )
      qh_setappend(setp: &points, newelem: v4);
    simplex = points;
  }
  else
  {
    v20 = qh_settemp(setsize: qh_qh.TEMPsize);
    v21 = vertex->point;
    simplex = v20;
    qh_setappend(setp: &simplex, newelem: v21);
    if ( unbounded != 0 )
      qh_setappend(setp: &simplex, newelem: v4);
    qh_maxsimplex(dim, maxpoints: points, points: nullptr, numpoints: 0, &simplex);
    qh_setdelnth(set: simplex, nth: 0);
  }
  gm_matrix = qh_qh.gm_matrix;
  point0 = (long double *)simplex->e[0].p;
  v23 = simplex->e;
  point = nullptr;
  p = (long double *)simplex->e[0].p;
  ib = 0;
  HIDWORD(v56) = qh_qh.gm_matrix;
  point = p;
  if ( p != nullptr )
  {
    do
    {
      HIDWORD(v56) = v23 + 1;
      if ( qh_qh.IStracing >= 4 )
      {
        qh_printmatrix(
          fp: qh_qh.ferr,
          string: "qh_detvnorm: Voronoi vertex or midpoint",
          rows: &point,
          numrow: 1,
          numcol: dim);
        p = point;
      }
      v25 = point0;
      if ( p != point0 )
      {
        qh_qh.gm_row[ib++] = gm_matrix;
        v26 = dim;
        if ( dim != 0 )
        {
          v27 = (char *)v25 - (char *)gm_matrix;
          do
          {
            *gm_matrix = *point++ - *(long double *)((char *)gm_matrix + v27);
            ++gm_matrix;
            --v26;
          }
          while ( v26 != 0 );
        }
      }
      v23 = (setelemT *)HIDWORD(v56);
      p = *(long double **)HIDWORD(v56);
      point = p;
    }
    while ( p != nullptr );
    HIDWORD(v56) = gm_matrix;
  }
  qh_qh.gm_row[ib] = gm_matrix;
  qh_sethyperplane_gauss(dim, rows: qh_qh.gm_row, point0, toporient: 1u, normal: gm_matrix, &offset, &nearzero);
  v28 = *(long double **)(vertexA + 8);
  if ( qh_qh.GOODvertexp != v28 )
    v28 = vertex->point;
  ++qh_qhstat.stats[51].i;
  if ( qh_distnorm(dim, point: v28, normal: gm_matrix, offsetp: &offset) > 0.0 )
  {
    v29 = dim;
    *(_QWORD *)&offset ^= _mask__NegDouble_;
    v30 = gm_matrix;
    if ( dim != 0 )
    {
      do
      {
        *(_QWORD *)v30++ ^= _mask__NegDouble_;
        --v29;
      }
      while ( v29 != 0 );
    }
  }
  if ( qh_qh.VERIFYoutput == 0 && qh_qh.PRINTstatistics == 0 )
    goto LABEL_85;
  point0 = (long double *)qh_pointid(point: vertex->point);
  numcenters = qh_pointid(point: *(long double **)(vertexA + 8));
  if ( unbounded == 0 )
  {
    ++qh_qhstat.stats[53].i;
    v31 = qh_distnorm(dim, point: v4, normal: gm_matrix, offsetp: &offset);
    v60 = v31;
    v32 = v31;
    if ( v31 < 0.0 )
      *(_QWORD *)&v32 = *(_QWORD *)&v31 ^ _mask__NegDouble_;
    ++qh_qhstat.stats[165].i;
    if ( v32 > qh_qhstat.stats[167].r )
      qh_qhstat.stats[167].r = v32;
    qh_qhstat.stats[166].r = qh_qhstat.stats[166].r + v32;
    if ( qh_qh.IStracing >= 4 )
      fprintf(str: qh_qh.ferr, format: "qh_detvnorm: points %d %d midpoint dist %2.2g\n", point0, numcenters, v32);
    v33 = 0;
    if ( dim >= 4 )
    {
      v34 = vertex->point;
      v35 = v34 + 3;
      ic = (char *)v34 - (char *)v4;
      v62 = 8 - (_DWORD)v4;
      v61 = 16 - (_DWORD)v4;
      v36 = -8 - (_DWORD)v4;
      v37 = ((unsigned int)(dim - 4) >> 2) + 1;
      v38 = v4 + 1;
      v63 = -8 - (_DWORD)v4;
      HIDWORD(v60) = 4 * v37;
      while ( 1 )
      {
        v39 = (char *)v38 + v36;
        *(v38 - 1) = *(double *)&v39[*(_DWORD *)(vertexA + 8)] - *(v35 - 3);
        v40 = *(double *)&v39[*(_DWORD *)(vertexA + 8) + 8] - *(double *)((char *)v38 + ic);
        v41 = v62;
        *v38 = v40;
        v42 = *(double *)((char *)v38 + v41 + *(_DWORD *)(vertexA + 8)) - *(v35 - 1);
        v43 = v61;
        v38[1] = v42;
        v38[2] = *(double *)((char *)v38 + v43 + *(_DWORD *)(vertexA + 8)) - *v35;
        v38 += 4;
        v35 += 4;
        if ( --v37 == 0 )
          break;
        v36 = v63;
      }
      v4 = midpoint;
      v33 = HIDWORD(v60);
      gm_matrix = (long double *)HIDWORD(v56);
    }
    if ( v33 < dim )
    {
      v44 = &v4[v33];
      id = (char *)((char *)vertex->point - (char *)v4);
      do
      {
        *v44 = *(double *)(*(_DWORD *)(vertexA + 8) + 8 * v33++) - *(double *)&id[(_DWORD)v44];
        ++v44;
      }
      while ( v33 < dim );
    }
    v45 = dim;
    qh_normalize(normal: v4, dim, toporient: 0);
    v56 = qh_distnorm(dim: v45, point: v4, normal: gm_matrix, offsetp: &zero);
    if ( v56 >= 0.0 )
      v46 = v56 - 1.0;
    else
      v46 = v56 + 1.0;
    v56 = v46;
    if ( v46 < 0.0 )
    {
      v46 = 0.0;
      v56 = 0.0;
    }
    if ( qh_qh.IStracing >= 4 )
    {
      fprintf(
        str: qh_qh.ferr,
        format: "qh_detvnorm: points %d %d angle %2.2g nearzero %d\n",
        point0,
        numcenters,
        v46,
        nearzero);
      v46 = v56;
    }
    if ( nearzero != 0 )
    {
      ++qh_qhstat.stats[162].i;
      if ( v46 > qh_qhstat.stats[164].r )
        qh_qhstat.stats[164].r = v46;
      qh_qhstat.stats[163].r = qh_qhstat.stats[163].r + v46;
    }
    else
    {
      ++qh_qhstat.stats[168].i;
      if ( v46 > qh_qhstat.stats[170].r )
        qh_qhstat.stats[170].r = v46;
      qh_qhstat.stats[169].r = qh_qhstat.stats[169].r + v46;
    }
  }
  v47 = points;
  if ( simplex != points )
  {
    v48 = 0;
    point = nullptr;
    if ( points != nullptr )
    {
      v49 = 0;
      point = (long double *)points->e[0].p;
      ie = qh_setsize(set: points);
      if ( ie > 0 )
      {
        v50 = point;
        do
        {
          if ( qh_setin(set: simplex, setelem: v50) == 0 )
          {
            v51.p = (void *)centers->e[v48];
            ++qh_qhstat.stats[53].i;
            v60 = qh_distnorm(dim, point, normal: gm_matrix, offsetp: &offset);
            v52 = v60;
            if ( v60 < 0.0 )
              v52 = -v60;
            ++qh_qhstat.stats[159].i;
            if ( v52 > qh_qhstat.stats[161].r )
              qh_qhstat.stats[161].r = v52;
            qh_qhstat.stats[160].r = qh_qhstat.stats[160].r + v52;
            if ( qh_qh.IStracing >= 4 )
              fprintf(
                str: qh_qh.ferr,
                format: "qh_detvnorm: points %d %d Voronoi vertex %d dist %2.2g\n",
                point0,
                numcenters,
                *(_DWORD *)(v51.i + 72),
                v52);
          }
          v47 = points;
          v48 = ++v49;
          v50 = (long double *)points->e[v49].p;
          point = v50;
        }
        while ( v49 < ie );
        goto LABEL_86;
      }
LABEL_85:
      v47 = points;
    }
  }
LABEL_86:
  *offsetp = offset;
  if ( simplex != v47 )
    qh_settempfree(set: &simplex);
  qh_settempfree(set: &points);
  return gm_matrix;
}

//------------------------------------------------------------------------------
// Address: 0x100616C0
// Name: struct setT __near * qh_detvridge(struct vertexT __near *)
// Source: json
//------------------------------------------------------------------------------
setT *__cdecl qh_detvridge(vertexT *vertex)
{
  setT *neighbors; // eax
  int v2; // edi
  setelemT *e; // esi
  _DWORD *p; // eax
  unsigned int v5; // eax
  setT *centers; // [esp+4h] [ebp-4h] BYREF

  centers = qh_settemp(setsize: qh_qh.TEMPsize);
  neighbors = vertex->neighbors;
  v2 = 1;
  if ( neighbors != nullptr )
  {
    e = neighbors->e;
    p = neighbors->e[0].p;
    if ( p != nullptr )
    {
      do
      {
        ++e;
        if ( (p[20] & 0x2000) != 0 )
        {
          if ( p[18] != 0 )
          {
            qh_setappend(setp: &centers, newelem: p);
          }
          else if ( v2 != 0 )
          {
            v2 = 0;
            qh_setappend(setp: &centers, newelem: p);
          }
        }
        p = (_DWORD *)e->i;
      }
      while ( e->i != 0 );
    }
  }
  v5 = qh_setsize(set: centers);
  qsort(base: centers->e, num: v5, width: 4u, comp: (int (__cdecl *)(const void *, const void *))qh_compare_facetvisit);
  return centers;
}

//------------------------------------------------------------------------------
// Address: 0x10061750
// Name: struct setT __near * qh_detvridge3(struct vertexT __near *,struct vertexT __near *)
// Source: json
//------------------------------------------------------------------------------
setT *__cdecl qh_detvridge3(vertexT *atvertex, vertexT *vertex)
{
  setT *neighbors; // eax
  setelemT *e; // ecx
  setelemT v4; // eax
  setT *v5; // eax
  _DWORD *p; // esi
  setelemT *v7; // eax
  _DWORD *v8; // edi
  int v9; // eax
  _DWORD **v10; // edi
  setT *v11; // eax
  setelemT v12; // esi
  setelemT *v13; // edi
  _iobuf *v14; // eax
  setT *v15; // eax
  setelemT *v16; // ecx
  setelemT v17; // eax
  int v19; // [esp-14h] [ebp-1Ch]
  int v20; // [esp-10h] [ebp-18h]
  unsigned int firstinf; // [esp+0h] [ebp-8h]
  setT *centers; // [esp+4h] [ebp-4h] BYREF

  centers = qh_settemp(setsize: qh_qh.TEMPsize);
  neighbors = atvertex->neighbors;
  firstinf = 1;
  if ( neighbors != nullptr )
  {
    e = neighbors->e;
    for ( v4.p = (void *)neighbors->e[0]; v4.i != 0; ++e )
    {
      *(_DWORD *)(v4.i + 80) &= ~0x4000u;
      v4.p = e[1].p;
    }
  }
  v5 = vertex->neighbors;
  if ( v5 != nullptr )
  {
    p = v5->e[0].p;
    v7 = v5->e;
    if ( p != nullptr )
    {
      while ( 1 )
      {
        ++v7;
        if ( (p[20] & 0x4000) == 0 )
          break;
        p = (_DWORD *)v7->i;
        if ( v7->i == 0 )
          goto LABEL_22;
      }
      v8 = p;
      do
      {
        p[20] |= 0x4000u;
        if ( (p[20] & 0x2000) != 0 )
        {
          if ( p[18] != 0 )
          {
            qh_setappend(setp: &centers, newelem: p);
          }
          else if ( firstinf != 0 )
          {
            firstinf = 0;
            qh_setappend(setp: &centers, newelem: p);
          }
        }
        v9 = v8[15];
        p = nullptr;
        if ( v9 != 0 )
        {
          p = *(_DWORD **)(v9 + 4);
          v10 = (_DWORD **)(v9 + 4);
          if ( p != nullptr )
          {
            do
            {
              ++v10;
              if ( (p[20] & 0x4000) == 0 )
              {
                if ( qh_setin(set: vertex->neighbors, setelem: p) != 0 )
                  break;
                p[20] |= 0x4000u;
              }
              p = *v10;
            }
            while ( *v10 != nullptr );
          }
        }
        v8 = p;
      }
      while ( p != nullptr );
    }
  }
LABEL_22:
  if ( qh_qh.CHECKfrequently != 0 )
  {
    v11 = vertex->neighbors;
    if ( v11 != nullptr )
    {
      v12.p = (void *)v11->e[0];
      v13 = v11->e;
      if ( v12.i != 0 )
      {
        do
        {
          ++v13;
          if ( (*(_DWORD *)(v12.i + 80) & 0x4000) == 0 )
          {
            v20 = *(_DWORD *)(v12.i + 76);
            v19 = qh_pointid(point: vertex->point);
            v14 = __iob_func();
            fprintf(
              str: v14 + 2,
              format: "qh_detvridge3: neigbors of vertex p%d are not connected at facet %d\n",
              v19,
              v20);
            qh_errexit(exitcode: 5, facet: (facetT *)v12.p, ridge: nullptr);
          }
          v12.p = v13->p;
        }
        while ( v13->i != 0 );
      }
    }
  }
  v15 = atvertex->neighbors;
  if ( v15 != nullptr )
  {
    v16 = v15->e;
    for ( v17.p = (void *)v15->e[0]; v17.i != 0; ++v16 )
    {
      *(_DWORD *)(v17.i + 80) |= 0x4000u;
      v17.p = v16[1].p;
    }
  }
  return centers;
}

//------------------------------------------------------------------------------
// Address: 0x100618D0
// Name: int qh_eachvoronoi(struct _iobuf __near *,void (*)(struct _iobuf __near *,struct vertexT __near *,struct vertexT __near *,struct setT __near *,unsigned int),struct vertexT __near *,unsigned int,enum qh_RIDGE,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl qh_eachvoronoi(
        _iobuf *fp,
        void (__cdecl *printvridge)(_iobuf *, vertexT *, vertexT *, setT *, unsigned int),
        vertexT *atvertex,
        setT *visitall,
        qh_RIDGE innerouter,
        unsigned int inorder)
{
  unsigned int num_facets; // esi
  vertexT *v7; // edi
  int v8; // ebx
  vertexT *vertex_list; // eax
  vertexT *next; // ecx
  setT *neighbors; // eax
  setelemT *e; // ecx
  setelemT v13; // eax
  setT *v14; // eax
  setelemT *v15; // ecx
  setelemT v16; // eax
  int v17; // eax
  vertexT *v18; // esi
  vertexT **v19; // eax
  setT *v20; // eax
  int v21; // edi
  int v22; // edx
  setelemT *v23; // ecx
  setelemT v24; // eax
  unsigned int v25; // ebx
  int v26; // eax
  setT *v27; // eax
  setT *v28; // eax
  setelemT *v29; // ecx
  setelemT v30; // eax
  int v32; // [esp-4h] [ebp-1Ch]
  facetT **neighborp; // [esp+Ch] [ebp-Ch]
  vertexT **vertexp; // [esp+10h] [ebp-8h]
  int totridges; // [esp+14h] [ebp-4h]

  ++qh_qh.vertex_visit;
  num_facets = qh_qh.num_facets;
  v7 = atvertex;
  *((_DWORD *)atvertex + 5) |= 0x1000000u;
  v8 = 0;
  totridges = 0;
  if ( visitall != nullptr )
  {
    vertex_list = qh_qh.vertex_list;
    if ( qh_qh.vertex_list != nullptr )
    {
      while ( 1 )
      {
        next = vertex_list->next;
        if ( vertex_list->next == nullptr )
          break;
        *((_DWORD *)vertex_list + 5) &= ~0x1000000u;
        vertex_list = next;
      }
    }
  }
  neighbors = atvertex->neighbors;
  if ( neighbors != nullptr )
  {
    e = neighbors->e;
    v13.p = (void *)neighbors->e[0];
    if ( v13.i != 0 )
    {
      do
      {
        ++e;
        if ( *(_DWORD *)(v13.i + 72) < num_facets )
          *(_DWORD *)(v13.i + 80) |= 0x2000u;
        v13.p = e->p;
      }
      while ( e->i != 0 );
    }
  }
  v14 = atvertex->neighbors;
  if ( v14 != nullptr )
  {
    v15 = v14->e;
    v16.p = (void *)v14->e[0];
    if ( v16.i != 0 )
    {
      while ( 1 )
      {
        neighborp = (facetT **)++v15;
        if ( (*(_DWORD *)(v16.i + 80) & 0x2000) != 0 )
        {
          v17 = *(_DWORD *)(v16.i + 52);
          if ( v17 != 0 )
          {
            v18 = *(vertexT **)(v17 + 4);
            v19 = (vertexT **)(v17 + 4);
            if ( v18 != nullptr )
              break;
          }
        }
LABEL_40:
        v16.p = v15->p;
        if ( v15->i == 0 )
          goto LABEL_41;
      }
      while ( 1 )
      {
        vertexp = v19 + 1;
        if ( v18->visitid == qh_qh.vertex_visit || (*((_BYTE *)v18 + 23) & 1) != 0 )
          goto LABEL_38;
        v18->visitid = qh_qh.vertex_visit;
        v20 = v18->neighbors;
        v21 = 0;
        v22 = 1;
        if ( v20 != nullptr )
        {
          v23 = v20->e;
          v24.p = (void *)v20->e[0];
          if ( v24.i != 0 )
          {
            do
            {
              ++v23;
              if ( (*(_DWORD *)(v24.i + 80) & 0x2000) != 0 )
              {
                if ( *(_DWORD *)(v24.i + 72) != 0 )
                {
                  ++v21;
                }
                else if ( v22 != 0 )
                {
                  ++v21;
                  v22 = 0;
                }
              }
              v24.p = v23->p;
            }
            while ( v23->i != 0 );
          }
        }
        if ( v21 < qh_qh.hull_dim - 1 )
          goto LABEL_38;
        if ( v22 != 0 )
        {
          if ( innerouter != qh_RIDGEouter )
          {
            v25 = 0;
LABEL_30:
            ++totridges;
            if ( qh_qh.IStracing >= 4 )
            {
              v32 = qh_pointid(point: v18->point);
              v26 = qh_pointid(point: atvertex->point);
              fprintf(
                str: qh_qh.ferr,
                format: "qh_eachvoronoi: Voronoi ridge of %d vertices between sites %d and %d\n",
                v21,
                v26,
                v32);
            }
            if ( printvridge != nullptr )
            {
              if ( inorder != 0 && qh_qh.hull_dim == 4 )
                v27 = qh_detvridge3(atvertex, vertex: v18);
              else
                v27 = qh_detvridge(vertex: v18);
              visitall = v27;
              printvridge(a1: fp, a2: atvertex, a3: v18, a4: v27, a5: v25);
              qh_settempfree(set: &visitall);
            }
          }
        }
        else
        {
          v25 = 1;
          if ( innerouter != qh_RIDGEinner )
            goto LABEL_30;
        }
LABEL_38:
        v19 = vertexp;
        v18 = *vertexp;
        if ( *vertexp == nullptr )
        {
          v15 = (setelemT *)neighborp;
          v7 = atvertex;
          v8 = totridges;
          goto LABEL_40;
        }
      }
    }
  }
LABEL_41:
  v28 = v7->neighbors;
  if ( v28 != nullptr )
  {
    v29 = v28->e;
    for ( v30.p = (void *)v28->e[0]; v30.i != 0; ++v29 )
    {
      *(_DWORD *)(v30.i + 80) &= ~0x2000u;
      v30.p = v29[1].p;
    }
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x10061AF0
// Name: void qh_facet2point(struct facetT __near *,double __near * __near *,double __near * __near *,double __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_facet2point(facetT *facet, long double **point0, long double **point1, long double *mindist)
{
  setT *vertices; // eax
  int i; // edi
  int maxsize; // ebx
  long double *v7; // eax
  long double v8; // xmm0_8
  long double v9; // [esp+0h] [ebp-1Ch]
  long double dist; // [esp+14h] [ebp-8h] BYREF

  vertices = facet->vertices;
  if ( (*((_DWORD *)facet + 20) & 0x800) != 0 )
  {
    i = vertices->e[0].i;
    maxsize = vertices[1].maxsize;
  }
  else
  {
    maxsize = vertices->e[0].i;
    i = vertices[1].maxsize;
  }
  qh_qhstat.stats[51].i += 2;
  qh_distplane(point: *(long double **)(i + 8), facet, &dist);
  v7 = *(long double **)(i + 8);
  v9 = dist;
  *mindist = dist;
  *point0 = qh_projectpoint(point: v7, facet, dist: v9);
  qh_distplane(point: *(long double **)(maxsize + 8), facet, &dist);
  v8 = dist;
  if ( *mindist > dist )
    *mindist = dist;
  *point1 = qh_projectpoint(point: *(long double **)(maxsize + 8), facet, dist: v8);
}

//------------------------------------------------------------------------------
// Address: 0x10061BA0
// Name: void qh_geomplanes(struct facetT __near *,double __near *,double __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_geomplanes(facetT *facet, long double *outerplane, long double *innerplane)
{
  double PRINTradius; // xmm0_8

  if ( qh_qh.MERGING != 0 || qh_qh.JOGGLEmax < 8.988465674311579e307 )
  {
    qh_outerinner(facet, outerplane, innerplane);
    PRINTradius = qh_qh.PRINTradius;
    if ( qh_qh.JOGGLEmax < 8.988465674311579e307 )
      PRINTradius = qh_qh.PRINTradius - sqrt((double)qh_qh.hull_dim) * qh_qh.JOGGLEmax;
    *outerplane = *outerplane + PRINTradius;
    *innerplane = *innerplane - PRINTradius;
    if ( qh_qh.PRINTcoplanar != 0 || qh_qh.PRINTspheres != 0 )
    {
      *outerplane = qh_qh.MAXabs_coord * 0.002 + *outerplane;
      *innerplane = *innerplane - qh_qh.MAXabs_coord * 0.002;
    }
  }
  else
  {
    *outerplane = 0.0;
    *innerplane = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10061C80
// Name: void qh_markkeep(struct facetT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_markkeep(facetT *facetlist)
{
  facetT *i; // esi
  int v2; // eax
  unsigned int v3; // esi
  unsigned int v4; // edx
  setT *v5; // edi
  setelemT v6; // eax
  setelemT *e; // ecx
  int v8; // esi
  setelemT v9; // eax
  setelemT *v10; // ecx
  setelemT v11; // eax
  setelemT *v12; // edx
  int v13; // ecx
  facetT *v14; // eax
  int v15; // edx
  setT *facets; // [esp+8h] [ebp-4h] BYREF

  facets = qh_settemp(setsize: qh_qh.num_facets);
  if ( qh_qh.IStracing >= 2 )
    fprintf(
      str: qh_qh.ferr,
      format: "qh_markkeep: only keep %d largest and/or %d most merged facets and/or min area %.2g\n",
      qh_qh.KEEParea,
      qh_qh.KEEPmerge,
      (double)qh_qh.KEEPminArea);
  for ( i = facetlist; i != nullptr; i = i->next )
  {
    if ( i->next == nullptr )
      break;
    v2 = *((_DWORD *)i + 20);
    if ( (v2 & 0x400) == 0 && (v2 & 0x40000) != 0 )
      qh_setappend(setp: &facets, newelem: i);
  }
  v3 = qh_setsize(set: facets);
  if ( qh_qh.KEEParea == 0 )
    goto LABEL_15;
  qsort(base: facets->e, num: v3, width: 4u, comp: (int (__cdecl *)(const void *, const void *))qh_compare_facetarea);
  v4 = v3 - qh_qh.KEEParea;
  if ( (int)(v3 - qh_qh.KEEParea) <= 0 )
    goto LABEL_15;
  v5 = facets;
  if ( facets != nullptr )
  {
    v6.p = (void *)facets->e[0];
    e = facets->e;
    if ( v6.i != 0 )
    {
      do
      {
        *(_DWORD *)(v6.i + 80) &= ~0x40000u;
        ++e;
        if ( --v4 == 0 )
          break;
        v6.p = e->p;
      }
      while ( e->i != 0 );
LABEL_15:
      v5 = facets;
    }
  }
  if ( qh_qh.KEEPmerge != 0 )
  {
    qsort(base: v5->e, num: v3, width: 4u, comp: qh_compare_facetmerge);
    v8 = v3 - qh_qh.KEEPmerge;
    if ( v8 <= 0 )
    {
LABEL_22:
      v5 = facets;
      goto LABEL_23;
    }
    v5 = facets;
    if ( facets != nullptr )
    {
      v9.p = (void *)facets->e[0];
      v10 = facets->e;
      if ( v9.i != 0 )
      {
        do
        {
          *(_DWORD *)(v9.i + 80) &= ~0x40000u;
          ++v10;
          if ( --v8 == 0 )
            break;
          v9.p = v10->p;
        }
        while ( v10->i != 0 );
        goto LABEL_22;
      }
    }
  }
LABEL_23:
  if ( qh_qh.KEEPminArea < 8.988465674311579e307 && v5 != nullptr )
  {
    v11.p = (void *)v5->e[0];
    v12 = v5->e;
    if ( v11.i != 0 )
    {
      do
      {
        v13 = *(_DWORD *)(v11.i + 80);
        ++v12;
        if ( (v13 & 0x80000) == 0 || qh_qh.KEEPminArea > *(double *)(v11.i + 32) )
          *(_DWORD *)(v11.i + 80) = v13 & 0xFFFBFFFF;
        v11.p = v12->p;
      }
      while ( v12->i != 0 );
    }
  }
  qh_settempfree(set: &facets);
  v14 = facetlist;
  v15 = 0;
  if ( facetlist != nullptr )
  {
    while ( v14->next != nullptr )
    {
      if ( (*((_DWORD *)v14 + 20) & 0x40000) != 0 )
        ++v15;
      v14 = v14->next;
    }
  }
  qh_qh.num_good = v15;
}

//------------------------------------------------------------------------------
// Address: 0x10061E50
// Name: void qh_order_vertexneighbors(struct vertexT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_order_vertexneighbors(vertexT *vertex)
{
  setT **p_neighbors; // esi
  int v2; // eax
  setT *v3; // eax
  facetT *v4; // ebx
  setT *v5; // esi
  void **p_p; // edi
  facetT *p; // esi
  setT *neighbors; // [esp-14h] [ebp-18h]
  setT *newset; // [esp+0h] [ebp-4h] BYREF

  if ( qh_qh.IStracing >= 4 )
    fprintf(
      str: qh_qh.ferr,
      format: "qh_order_vertexneighbors: order neighbors of v%d for 3-d\n",
      *((_DWORD *)vertex + 5) & 0xFFFFFF);
  p_neighbors = &vertex->neighbors;
  v2 = qh_setsize(set: vertex->neighbors);
  v3 = qh_settemp(setsize: v2);
  neighbors = vertex->neighbors;
  newset = v3;
  v4 = (facetT *)qh_setdellast(set: neighbors);
  qh_setappend(setp: &newset, newelem: v4);
  for ( ; qh_setsize(set: vertex->neighbors) != 0; p_neighbors = &vertex->neighbors )
  {
    v5 = *p_neighbors;
    if ( v5 != nullptr )
    {
      p_p = &v5->e[0].p;
      p = (facetT *)v5->e[0].p;
      if ( p != nullptr )
      {
        while ( 1 )
        {
          ++p_p;
          if ( qh_setin(set: v4->neighbors, setelem: p) != 0 )
            break;
          p = (facetT *)*p_p;
          if ( *p_p == nullptr )
            goto LABEL_10;
        }
        qh_setdel(set: vertex->neighbors, oldelem: p);
        qh_setappend(setp: &newset, newelem: p);
        v4 = p;
        if ( p != nullptr )
          continue;
      }
    }
LABEL_10:
    ivp_message(
      templat: "qhull internal error (qh_order_vertexneighbors): no neighbor of v%d for f%d\n",
      *((_DWORD *)vertex + 5) & 0xFFFFFF,
      v4->id);
    qh_errexit(exitcode: 5, facet: v4, ridge: nullptr);
  }
  qh_setfree(setp: p_neighbors);
  qh_settemppop();
  *p_neighbors = newset;
}

//------------------------------------------------------------------------------
// Address: 0x10061F70
// Name: void qh_printcenter(struct _iobuf __near *,int,char const __near *,struct facetT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_printcenter(_iobuf *fp, int format, const char *string, facetT *facet)
{
  _iobuf *v4; // esi
  qh_CENTER CENTERtype; // ecx
  int hull_dim; // ebx
  int v7; // edi
  int i; // esi
  int j; // esi

  v4 = fp;
  if ( fp == nullptr )
    return;
  CENTERtype = qh_qh.CENTERtype;
  if ( qh_qh.CENTERtype != qh_ASvoronoi && qh_qh.CENTERtype != qh_AScentrum )
    return;
  if ( string != nullptr )
  {
    fprintf(str: fp, format: string, facet->id);
    CENTERtype = qh_qh.CENTERtype;
  }
  hull_dim = qh_qh.hull_dim;
  if ( CENTERtype == qh_ASvoronoi )
  {
    hull_dim = qh_qh.hull_dim - 1;
    if ( facet->normal != nullptr && (*((_BYTE *)facet + 82) & 1) != 0 && qh_qh.ATinfinity != 0 )
    {
      if ( hull_dim > 0 )
      {
        v7 = qh_qh.hull_dim - 1;
        do
        {
          fprintf(str: fp, format: "%6.16g ", -10.101);
          --v7;
        }
        while ( v7 != 0 );
      }
      goto LABEL_27;
    }
    if ( facet->center == nullptr )
      facet->center = qh_facetcenter(vertices: facet->vertices);
    for ( i = 0; i < hull_dim; ++i )
      fprintf(str: fp, format: "%6.16g ", (double)facet->center[i]);
  }
  else
  {
    if ( format == 24 && qh_qh.DELAUNAY != 0 )
      hull_dim = qh_qh.hull_dim - 1;
    if ( facet->center == nullptr )
      facet->center = qh_getcentrum(facet);
    for ( j = 0; j < hull_dim; ++j )
      fprintf(str: fp, format: "%6.16g ", (double)facet->center[j]);
  }
  v4 = fp;
LABEL_27:
  if ( format == 7 && hull_dim == 2 )
    fprintf(str: v4, format: " 0\n");
  else
    fprintf(str: v4, format: "\n");
}

//------------------------------------------------------------------------------
// Address: 0x100620E0
// Name: void qh_printfacet2geom_points(struct _iobuf __near *,double __near *,double __near *,struct facetT __near *,double,double __near * const)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_printfacet2geom_points(
        _iobuf *fp,
        long double *point1,
        long double *point2,
        facetT *facet,
        long double offset,
        long double *color)
{
  long double *v6; // esi
  long double *v7; // edi

  v6 = point1;
  v7 = point2;
  if ( fp != nullptr )
  {
    fprintf(str: fp, format: "VECT 1 2 1 2 1 # f%d\n", facet->id);
    if ( offset != 0.0 )
    {
      v6 = qh_projectpoint(point: point1, facet, dist: -offset);
      v7 = qh_projectpoint(point: point2, facet, dist: -offset);
    }
    fprintf(
      str: fp,
      format: "%8.4g %8.4g %8.4g\n%8.4g %8.4g %8.4g\n",
      (double)*v6,
      (double)v6[1],
      0.0,
      (double)*v7,
      (double)v7[1],
      0.0);
    if ( offset != 0.0 )
    {
      qh_memfree(object: (void **)v6, size: qh_qh.normal_size);
      qh_memfree(object: (void **)v7, size: qh_qh.normal_size);
    }
    fprintf(str: fp, format: "%8.4g %8.4g %8.4g 1.0\n", (double)*color, (double)color[1], (double)color[2]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10062220
// Name: void qh_printfacet2math(struct _iobuf __near *,struct facetT __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_printfacet2math(_iobuf *fp, facetT *facet, int notfirst)
{
  long double *v3; // esi
  long double *v4; // edi
  double mindist; // [esp+2Ch] [ebp-10h] BYREF
  long double *point0; // [esp+34h] [ebp-8h] BYREF
  long double *point1; // [esp+38h] [ebp-4h] BYREF

  point0 = nullptr;
  point1 = nullptr;
  mindist = 0.0;
  if ( fp != nullptr )
  {
    qh_facet2point(facet, &point0, &point1, &mindist);
    if ( notfirst != 0 )
      fprintf(str: fp, format: ",");
    v3 = point1;
    v4 = point0;
    fprintf(
      str: fp,
      format: "Line[{{%16.8f, %16.8f}, {%16.8f, %16.8f}}]\n",
      (double)*point0,
      (double)point0[1],
      (double)*point1,
      (double)point1[1]);
    qh_memfree(object: (void **)v3, size: qh_qh.normal_size);
    qh_memfree(object: (void **)v4, size: qh_qh.normal_size);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100622D0
// Name: void qh_printfacet3geom_points(struct _iobuf __near *,struct setT __near *,struct facetT __near *,double,double __near * const)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_printfacet3geom_points(_iobuf *fp, setT *points, facetT *facet, long double offset, long double *color)
{
  int v6; // ebx
  long double *p; // eax
  setelemT *e; // esi
  long double *v9; // eax
  void **v10; // ebx
  int i; // esi
  int j; // esi
  int n; // [esp+2Ch] [ebp-8h]
  setT *printpoints; // [esp+30h] [ebp-4h] BYREF
  long double **pointp; // [esp+3Ch] [ebp+8h]

  v6 = qh_setsize(set: points);
  n = v6;
  if ( fp != nullptr )
  {
    fprintf(str: fp, format: "{ OFF %d 1 1 # f%d\n", v6, facet->id);
    if ( offset == 0.0 )
    {
      printpoints = points;
    }
    else
    {
      printpoints = qh_settemp(setsize: v6);
      if ( points != nullptr )
      {
        p = (long double *)points->e[0].p;
        e = points->e;
        if ( p != nullptr )
        {
          do
          {
            ++e;
            v9 = qh_projectpoint(point: p, facet, dist: -offset);
            qh_setappend(setp: &printpoints, newelem: v9);
            p = (long double *)e->i;
          }
          while ( e->i != 0 );
        }
      }
    }
    if ( printpoints != nullptr )
    {
      v10 = (void **)printpoints->e[0].p;
      pointp = (long double **)printpoints->e;
      if ( v10 != nullptr )
      {
        do
        {
          ++pointp;
          for ( i = 0; i < qh_qh.hull_dim; ++i )
          {
            if ( i == qh_qh.DROPdim )
              fprintf(str: fp, format: "0 ");
            else
              fprintf(str: fp, format: "%8.4g ", *(double *)&v10[2 * i]);
          }
          if ( printpoints != points )
            qh_memfree(object: v10, size: qh_qh.normal_size);
          fprintf(str: fp, format: "\n");
          v10 = (void **)*pointp;
        }
        while ( *pointp != nullptr );
      }
      v6 = n;
    }
    if ( printpoints != points )
      qh_settempfree(set: &printpoints);
    fprintf(str: fp, format: "%d ", v6);
    for ( j = 0; j < v6; ++j )
      fprintf(str: fp, format: "%d ", j);
    fprintf(str: fp, format: "%8.4g %8.4g %8.4g 1.0 }\n", (double)*color, (double)color[1], (double)color[2]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100624A0
// Name: void qh_printfacet3math(struct _iobuf __near *,struct facetT __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_printfacet3math(_iobuf *fp, facetT *facet, int notfirst)
{
  _iobuf *v3; // edi
  int v4; // eax
  setelemT v5; // esi
  setelemT *e; // edi
  long double *v7; // eax
  setT *v8; // eax
  double *p; // esi
  setelemT *v10; // ebx
  void ***v11; // esi
  void **v12; // eax
  long double dist; // [esp+24h] [ebp-14h] BYREF
  setT *vertices; // [esp+2Ch] [ebp-Ch] BYREF
  unsigned int firstpoint; // [esp+30h] [ebp-8h]
  setT *points; // [esp+34h] [ebp-4h] BYREF

  v3 = fp;
  firstpoint = 1;
  if ( fp != nullptr )
  {
    if ( notfirst != 0 )
      fprintf(str: fp, format: ",\n");
    vertices = (setT *)qh_facet3vertex((setT *)facet);
    v4 = qh_setsize(set: vertices);
    points = qh_settemp(setsize: v4);
    if ( vertices != nullptr )
    {
      v5.p = (void *)vertices->e[0];
      e = vertices->e;
      if ( v5.i != 0 )
      {
        do
        {
          ++qh_qhstat.stats[51].i;
          ++e;
          qh_distplane(point: *(long double **)(v5.i + 8), facet, &dist);
          v7 = qh_projectpoint(point: *(long double **)(v5.i + 8), facet, dist);
          qh_setappend(setp: &points, newelem: v7);
          v5.p = e->p;
        }
        while ( e->i != 0 );
      }
      v3 = fp;
    }
    fprintf(str: v3, format: "Polygon[{");
    v8 = points;
    if ( points != nullptr )
    {
      p = (double *)points->e[0].p;
      v10 = points->e;
      if ( p != nullptr )
      {
        do
        {
          ++v10;
          if ( firstpoint != 0 )
            firstpoint = 0;
          else
            fprintf(str: v3, format: ",\n");
          fprintf(str: v3, format: "{%16.8f, %16.8f, %16.8f}", *p, p[1], p[2]);
          p = (double *)v10->i;
        }
        while ( v10->i != 0 );
        v8 = points;
      }
      if ( v8 != nullptr )
      {
        v11 = (void ***)v8->e;
        v12 = (void **)v8->e[0].p;
        if ( v12 != nullptr )
        {
          do
          {
            ++v11;
            qh_memfree(object: v12, size: qh_qh.normal_size);
            v12 = *v11;
          }
          while ( *v11 != nullptr );
        }
      }
    }
    qh_settempfree(set: &points);
    qh_settempfree(set: &vertices);
    fprintf(str: v3, format: "}]");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10062610
// Name: void qh_printfacet3vertex(struct _iobuf __near *,struct facetT __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_printfacet3vertex(setT *fp, facetT *facet, int format)
{
  _iobuf *v3; // edi
  _iobuf *v4; // eax
  int v5; // eax
  int *p_cnt; // esi
  int cnt; // eax
  int v8; // eax

  v3 = (_iobuf *)fp;
  if ( fp != nullptr )
  {
    v4 = (_iobuf *)qh_facet3vertex((setT *)facet);
    fp = (setT *)v4;
    if ( format == 16 )
    {
      v5 = qh_setsize(set: (setT *)v4);
      fprintf(str: v3, format: "%d ", v5);
      v4 = (_iobuf *)fp;
    }
    if ( v4 != nullptr )
    {
      p_cnt = &v4->_cnt;
      cnt = v4->_cnt;
      if ( cnt != 0 )
      {
        do
        {
          ++p_cnt;
          v8 = qh_pointid(point: *(long double **)(cnt + 8));
          fprintf(str: v3, format: "%d ", v8);
          cnt = *p_cnt;
        }
        while ( *p_cnt != 0 );
      }
    }
    fprintf(str: v3, format: "\n");
    qh_settempfree(set: &fp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100626A0
// Name: void qh_printfacetNvertex_nonsimplicial(struct _iobuf __near *,struct facetT __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_printfacetNvertex_nonsimplicial(ridgeT **fp, facetT *facet, int id, int format)
{
  facetT *v5; // esi
  setT *ridges; // eax
  ridgeT **e; // eax
  ridgeT *v8; // edi
  setT *vertices; // edi
  setelemT v10; // eax
  setelemT *v11; // esi
  int v12; // eax
  setT *v13; // eax
  setelemT *v14; // esi
  int maxsize; // eax
  int v16; // eax
  ridgeT **ridgep; // [esp+Ch] [ebp+8h]

  if ( fp != nullptr )
  {
    v5 = facet;
    if ( (*((_DWORD *)facet + 20) & 0x400) == 0 || qh_qh.NEWfacets == 0 )
    {
      ridges = facet->ridges;
      if ( ridges != nullptr )
      {
        e = (ridgeT **)ridges->e;
        v8 = *e;
        if ( *e != nullptr )
        {
          while ( 1 )
          {
            ridgep = e + 1;
            if ( format == 24 )
              fprintf(str: (_iobuf *)fp, format: "%d ", qh_qh.hull_dim);
            fprintf(str: (_iobuf *)fp, format: "%d ", id);
            if ( v8->top == v5 )
            {
              vertices = v8->vertices;
              if ( vertices != nullptr )
              {
                v10.p = (void *)vertices->e[0];
                v11 = vertices->e;
                if ( v10.i != 0 )
                {
                  do
                  {
                    ++v11;
                    v12 = qh_pointid(point: *(long double **)(v10.i + 8));
                    fprintf(str: (_iobuf *)fp, format: "%d ", v12);
                    v10.p = v11->p;
                  }
                  while ( v11->i != 0 );
                }
              }
            }
            else
            {
              v13 = v8->vertices;
              if ( v8->vertices != nullptr )
              {
                v14 = (setelemT *)&v13[1];
                maxsize = v13[1].maxsize;
                if ( maxsize != 0 )
                {
                  do
                  {
                    v16 = qh_pointid(point: *(long double **)(maxsize + 8));
                    fprintf(str: (_iobuf *)fp, format: "%d ", v16);
                    if ( v14 == v8->vertices->e )
                    {
                      v14 += 2;
                    }
                    else if ( v14 == (setelemT *)&v8->vertices[1] )
                    {
                      --v14;
                    }
                    else
                    {
                      ++v14;
                    }
                    maxsize = v14->i;
                  }
                  while ( v14->i != 0 );
                }
              }
            }
            fprintf(str: (_iobuf *)fp, format: "\n");
            e = ridgep;
            v8 = *ridgep;
            if ( *ridgep == nullptr )
              break;
            v5 = facet;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100627C0
// Name: void qh_printfacetNvertex_simplicial(struct _iobuf __near *,struct facetT __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_printfacetNvertex_simplicial(_iobuf *fp, facetT *facet, int format)
{
  int v3; // eax
  int v4; // eax
  setT *v5; // eax
  setT *v6; // esi
  int maxsize; // eax
  int v8; // eax
  setT *v9; // eax
  setT *vertices; // eax
  setelemT *e; // esi
  setelemT v12; // eax
  int v13; // eax

  if ( fp != nullptr )
  {
    if ( format == 16 || format == 24 )
    {
      v3 = qh_setsize(set: facet->vertices);
      fprintf(str: fp, format: "%d ", v3);
    }
    v4 = *((_DWORD *)facet + 20);
    if ( (v4 & 0x800) != 0 || qh_qh.hull_dim > 2 && (v4 & 0x1000) == 0 )
    {
      vertices = facet->vertices;
      if ( vertices != nullptr )
      {
        e = vertices->e;
        v12.p = (void *)vertices->e[0];
        if ( v12.i != 0 )
        {
          do
          {
            ++e;
            v13 = qh_pointid(point: *(long double **)(v12.i + 8));
            fprintf(str: fp, format: "%d ", v13);
            v12.p = e->p;
          }
          while ( e->i != 0 );
        }
      }
    }
    else
    {
      v5 = facet->vertices;
      if ( v5 != nullptr )
      {
        v6 = v5 + 1;
        maxsize = v5[1].maxsize;
        if ( maxsize != 0 )
        {
          do
          {
            v8 = qh_pointid(point: *(long double **)(maxsize + 8));
            fprintf(str: fp, format: "%d ", v8);
            v9 = facet->vertices;
            if ( v6 == (setT *)v9->e )
            {
              ++v6;
            }
            else if ( v6 == &v9[1] )
            {
              v6 = (setT *)((char *)v6 - 4);
            }
            else
            {
              v6 = (setT *)((char *)v6 + 4);
            }
            maxsize = v6->maxsize;
          }
          while ( v6->maxsize != 0 );
        }
      }
    }
    fprintf(str: fp, format: "\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100628D0
// Name: void qh_printhelp_degenerate(struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_printhelp_degenerate(_iobuf *fp)
{
  if ( qh_qh.MERGEexact != 0 || qh_qh.PREmerge != 0 || qh_qh.JOGGLEmax < 8.988465674311579e307 )
  {
    fprintf(
      str: fp,
      format: "\n"
      "A Qhull error has occurred.  Qhull should have corrected the above\n"
      "precision error.  Please send the input and all of the output to\n"
      "qhull_bug@geom.umn.edu\n");
  }
  else
  {
    fprintf(
      str: fp,
      format: "\n"
      "Precision problems were detected during construction of the convex hull.\n"
      "This occurs because convex hull algorithms assume that calculations are\n"
      "exact, but floating-point arithmetic has roundoff errors.\n"
      "\n"
      "To correct for precision problems, do not use 'Q0'.  By default, Qhull\n"
      "selects 'C-0' or 'Qx' and merges non-convex facets.  With option 'QJ',\n"
      "Qhull joggles the input to prevent precision problems.  See \"Imprecision\n"
      "in Qhull\" (qh-impre.htm).\n"
      "\n"
      "If you use 'Q0', the output may include\n"
      "coplanar ridges, concave ridges, and flipped facets.  In 4-d and higher,\n"
      "Qhull may produce a ridge with four neighbors or two facets with the same \n"
      "vertices.  Qhull reports these events when they occur.  It stops when a\n"
      "concave ridge, flipped facet, or duplicate facet occurs.\n");
    if ( qh_qh.DELAUNAY != 0 )
    {
      if ( qh_qh.SCALElast == 0 && qh_qh.MAXabs_coord > 10000.0 )
        fprintf(
          str: fp,
          format: "\n"
          "When computing the Delaunay triangulation of coordinates > 1.0,\n"
          "  - use 'Qbb' to scale the last coordinate to [0,m] (max previous coordinate)\n");
      if ( qh_qh.DELAUNAY != 0 && qh_qh.ATinfinity == 0 )
        fprintf(
          str: fp,
          format: "When computing the Delaunay triangulation:\n"
          "  - use 'Qz' to add a point at-infinity.  This reduces precision problems.\n");
    }
    fprintf(
      str: fp,
      format: "\n"
      "If you need triangular output:\n"
      "  - use option 'QJ' to joggle the input points and remove precision errors\n"
      "  - or use option 'Ft' instead of 'Q0'.  It triangulates non-simplicial\n"
      "    facets with added points.\n"
      "\n"
      "If you must use 'Q0',\n"
      "try one or more of the following options.  They can not guarantee an output.\n"
      "  - use 'QbB' to scale the input to a cube.\n"
      "  - use 'Po' to produce output and prevent partitioning for flipped facets\n"
      "  - use 'V0' to set min. distance to visible facet as 0 instead of roundoff\n"
      "  - use 'En' to specify a maximum roundoff error less than %2.2g.\n"
      "  - options 'Qf', 'Qbb', and 'QR0' may also help\n",
      (double)qh_qh.DISTround);
    fprintf(
      str: fp,
      format: "\n"
      "To guarantee simplicial output:\n"
      "  - use option 'QJ' to joggle the input points and remove precision errors\n"
      "  - use option 'Ft' to triangulate the output by adding points\n"
      "  - use exact arithmetic (see \"Imprecision in Qhull\", qh-impre.htm)\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100629B0
// Name: void qh_printpointid(struct _iobuf __near *,char const __near *,int,double __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_printpointid(_iobuf *fp, const char *string, int dim, long double *point, int id)
{
  long double *v5; // edi
  int i; // esi
  double v7; // xmm0_8

  if ( fp != nullptr )
  {
    v5 = point;
    if ( point != nullptr )
    {
      if ( string != nullptr )
      {
        fputs(string, stream: fp);
        if ( id != -1 )
          fprintf(str: fp, format: " p%d: ", id);
      }
      for ( i = dim; i != 0; --i )
      {
        v7 = *v5++;
        if ( string != nullptr )
          fprintf(str: fp, format: " %8.4g", v7);
        else
          fprintf(str: fp, format: "%6.16g ", v7);
      }
      fprintf(str: fp, format: "\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10062A40
// Name: int qh_printvdiagram2(struct _iobuf __near *,void (*)(struct _iobuf __near *,struct vertexT __near *,struct vertexT __near *,struct setT __near *,unsigned int),struct setT __near *,enum qh_RIDGE,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl qh_printvdiagram2(
        _iobuf *fp,
        void (__cdecl *printvridge)(_iobuf *, vertexT *, vertexT *, setT *, unsigned int),
        setT *vertices,
        qh_RIDGE innerouter,
        unsigned int inorder)
{
  vertexT *vertex_list; // eax
  vertexT *next; // ecx
  vertexT *p; // esi
  setelemT *e; // edi
  int v9; // eax
  int totcount; // [esp+4h] [ebp-4h]
  setT *verticesa; // [esp+18h] [ebp+10h]

  vertex_list = qh_qh.vertex_list;
  totcount = 0;
  if ( qh_qh.vertex_list != nullptr )
  {
    while ( 1 )
    {
      next = vertex_list->next;
      if ( vertex_list->next == nullptr )
        break;
      *((_DWORD *)vertex_list + 5) &= ~0x1000000u;
      vertex_list = next;
    }
  }
  if ( vertices == nullptr )
    return 0;
  p = (vertexT *)vertices->e[0].p;
  e = vertices->e;
  v9 = qh_setsize(set: vertices);
  if ( v9 <= 0 )
    return 0;
  for ( verticesa = (setT *)v9; verticesa != nullptr; verticesa = (setT *)((char *)verticesa - 1) )
  {
    if ( p != nullptr )
      totcount += qh_eachvoronoi(fp, printvridge, atvertex: p, visitall: nullptr, innerouter, inorder);
    p = (vertexT *)e[1].p;
    ++e;
  }
  return totcount;
}

//------------------------------------------------------------------------------
// Address: 0x10062AE0
// Name: void qh_printvertex(struct _iobuf __near *,struct vertexT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_printvertex(_iobuf *fp, vertexT *vertex)
{
  vertexT *v2; // ebx
  int v3; // eax
  long double *point; // edi
  int i; // ebx
  setT *neighbors; // edi
  setelemT v7; // eax
  setelemT *e; // edi
  double v9; // [esp+0h] [ebp-14h]
  int v10; // [esp+4h] [ebp-10h]

  if ( fp != nullptr )
  {
    v2 = vertex;
    if ( vertex != nullptr )
    {
      v10 = *((_DWORD *)vertex + 5) & 0xFFFFFF;
      v3 = qh_pointid(point: vertex->point);
      fprintf(str: fp, format: "- p%d (v%d):", v3, v10);
      point = vertex->point;
      if ( point != nullptr )
      {
        for ( i = qh_qh.hull_dim; i != 0; --i )
        {
          v9 = *point++;
          fprintf(str: fp, format: " %5.2g", v9);
        }
        v2 = vertex;
      }
      if ( (*((_DWORD *)v2 + 5) & 0x8000000) != 0 )
        fprintf(str: fp, format: " deleted");
      if ( (*((_DWORD *)v2 + 5) & 0x4000000) != 0 )
        fprintf(str: fp, format: " ridgedeleted");
      fprintf(str: fp, format: "\n");
      if ( v2->neighbors != nullptr )
      {
        fprintf(str: fp, format: "  neighbors:");
        neighbors = v2->neighbors;
        if ( neighbors != nullptr )
        {
          v7.p = (void *)neighbors->e[0];
          e = neighbors->e;
          if ( v7.i != 0 )
          {
            do
            {
              ++e;
              fprintf(str: fp, format: " f%d", *(_DWORD *)(v7.i + 76));
              v7.p = e->p;
            }
            while ( e->i != 0 );
          }
        }
        fprintf(str: fp, format: "\n");
      }
    }
    else
    {
      fprintf(str: fp, format: "  NULLvertex\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10062C00
// Name: void qh_printvertices(struct _iobuf __near *,char const __near *,struct setT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_printvertices(_iobuf *fp, const char *string, setT *vertices)
{
  setelemT *e; // esi
  setelemT v4; // eax
  int v5; // eax
  int v6; // [esp-8h] [ebp-Ch]

  if ( fp != nullptr )
  {
    fputs(string, stream: fp);
    if ( vertices != nullptr )
    {
      e = vertices->e;
      v4.p = (void *)vertices->e[0];
      if ( v4.i != 0 )
      {
        do
        {
          v6 = *(_DWORD *)(v4.i + 20) & 0xFFFFFF;
          ++e;
          v5 = qh_pointid(point: *(long double **)(v4.i + 8));
          fprintf(str: fp, format: " p%d (v%d)", v5, v6);
          v4.p = e->p;
        }
        while ( e->i != 0 );
      }
    }
    fprintf(str: fp, format: "\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10062C70
// Name: void qh_printvnorm(struct _iobuf __near *,struct vertexT __near *,struct vertexT __near *,struct setT __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_printvnorm(_iobuf *fp, vertexT *vertex, vertexT *vertexA, setT *centers)
{
  long double *v4; // ebx
  int v5; // eax
  int i; // esi
  int v7; // [esp+4h] [ebp-18h]
  long double offset; // [esp+14h] [ebp-8h] BYREF

  if ( fp != nullptr )
  {
    v4 = qh_detvnorm(vertex, (int)vertexA, centers, offsetp: &offset);
    v7 = qh_pointid(point: vertexA->point);
    v5 = qh_pointid(point: vertex->point);
    fprintf(str: fp, format: "%d %d %d ", qh_qh.hull_dim + 2, v5, v7);
    for ( i = 0; i < qh_qh.hull_dim - 1; ++i )
      fprintf(str: fp, format: "%6.16g ", (double)v4[i]);
    fprintf(str: fp, format: "%6.16g ", (double)offset);
    fprintf(str: fp, format: "\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10062D40
// Name: void qh_printvridge(struct _iobuf __near *,struct vertexT __near *,struct vertexT __near *,struct setT __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_printvridge(_iobuf *fp, vertexT *vertex, vertexT *vertexA, setT *centers)
{
  int v4; // eax
  setelemT v5; // eax
  setelemT *e; // esi
  int v7; // [esp-Ch] [ebp-10h]
  int v8; // [esp-8h] [ebp-Ch]

  if ( fp != nullptr )
  {
    v8 = qh_pointid(point: vertexA->point);
    v7 = qh_pointid(point: vertex->point);
    v4 = qh_setsize(set: centers);
    fprintf(str: fp, format: "%d %d %d", v4 + 2, v7, v8);
    if ( centers != nullptr )
    {
      v5.p = (void *)centers->e[0];
      e = centers->e;
      if ( v5.i != 0 )
      {
        do
        {
          ++e;
          fprintf(str: fp, format: " %d", *(_DWORD *)(v5.i + 72));
          v5.p = e->p;
        }
        while ( e->i != 0 );
      }
    }
    fprintf(str: fp, format: "\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10062DD0
// Name: void qh_projectdim3(double __near *,double __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_projectdim3(long double *source, long double *destination)
{
  int hull_dim; // edi
  int v3; // ecx
  int v4; // eax

  hull_dim = qh_qh.hull_dim;
  v3 = 0;
  v4 = 0;
  if ( qh_qh.hull_dim <= 0 )
  {
LABEL_8:
    memset(&destination[v4], 0, 4 * ((2 * (3 - v4)) & 0x3FFFFFFE));
    return;
  }
  do
  {
    if ( hull_dim == 4 )
    {
      if ( v3 == qh_qh.DROPdim )
        goto LABEL_6;
    }
    else if ( v3 == qh_qh.DROPdim )
    {
      destination[v4] = 0.0;
      goto LABEL_5;
    }
    destination[v4] = source[v3];
LABEL_5:
    ++v4;
LABEL_6:
    hull_dim = qh_qh.hull_dim;
    ++v3;
  }
  while ( v3 < qh_qh.hull_dim );
  if ( v4 < 3 )
    goto LABEL_8;
}

//------------------------------------------------------------------------------
// Address: 0x10062E40
// Name: void qh_setfeasible(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_setfeasible(int dim)
{
  int v1; // esi
  long double *v2; // eax
  double *v3; // edi
  char *v4; // eax
  int v5; // esi
  double value; // [esp+Ch] [ebp-Ch]
  char *s; // [esp+14h] [ebp-4h] BYREF

  v1 = 0;
  s = qh_qh.feasible_string;
  if ( qh_qh.feasible_string == nullptr )
  {
    ivp_message(
      templat: "qhull input error: halfspace intersection needs a feasible point.\n"
      "Either prepend the input with 1 point or use 'Hn,n,n'.  See manual.\n");
    qh_errexit(exitcode: 1, facet: nullptr, ridge: nullptr);
  }
  v2 = (long double *)p_malloc(size: 8 * dim);
  qh_qh.feasible_point = v2;
  if ( v2 == nullptr )
  {
    ivp_message(templat: "qhull error: insufficient memory for 'Hn,n,n'\n");
    qh_errexit(exitcode: 4, facet: nullptr, ridge: nullptr);
  }
  v3 = v2;
  v4 = s;
  if ( *s != 0 )
  {
    while ( 1 )
    {
      value = qh_strtod(s: v4, endp: &s);
      if ( ++v1 > dim )
        break;
      *v3++ = value;
      if ( *s != 0 )
      {
        v4 = s + 1;
        s = v4;
        if ( *v4 != 0 )
          continue;
      }
      goto LABEL_11;
    }
    ivp_message(
      templat: "qhull input warning: more coordinates for 'H%s' than dimension %d\n",
      qh_qh.feasible_string,
      dim);
  }
LABEL_11:
  v5 = v1 + 1;
  if ( v5 <= dim )
    memset(v3, 0, 4 * ((2 * (dim - v5) + 2) & 0x3FFFFFFE));
}

//------------------------------------------------------------------------------
// Address: 0x10062F20
// Name: unsigned int qh_skipfacet(struct facetT __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl qh_skipfacet(facetT *facet)
{
  setT *neighbors; // eax
  setelemT *e; // ecx
  setelemT v4; // eax
  long double *normal; // eax

  if ( qh_qh.PRINTneighbors == 0 )
  {
    if ( qh_qh.PRINTgood != 0 )
      return (*((_DWORD *)facet + 20) & 0x40000) == 0;
    normal = facet->normal;
    if ( normal != nullptr )
      return qh_inthresholds(normal, angle: nullptr) == 0;
    return true;
  }
  if ( (*((_DWORD *)facet + 20) & 0x40000) != 0 )
    return qh_qh.PRINTgood == 0;
  neighbors = facet->neighbors;
  if ( neighbors == nullptr )
    return true;
  e = neighbors->e;
  v4.p = (void *)neighbors->e[0];
  if ( v4.i == 0 )
    return true;
  while ( 1 )
  {
    ++e;
    if ( (*(_DWORD *)(v4.i + 80) & 0x40000) != 0 )
      break;
    v4.p = e->p;
    if ( e->i == 0 )
      return true;
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10062FB0
// Name: void qh_countfacets(struct facetT __near *,struct setT __near *,unsigned int,int __near *,int __near *,int __near *,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_countfacets(
        facetT *facetlist,
        setT *facets,
        unsigned int printall,
        int *numfacetsp,
        int *numsimplicialp,
        int *totneighborsp,
        int *numridgesp,
        int *numcoplanarsp)
{
  facetT *v8; // esi
  int v9; // edi
  setelemT v10; // esi
  setelemT *e; // ebx
  setT *v12; // esi
  setT *v13; // [esp-8h] [ebp-20h]
  setT *neighbors; // [esp-4h] [ebp-1Ch]
  int numcoplanars; // [esp+8h] [ebp-10h]
  int numridges; // [esp+Ch] [ebp-Ch]
  int totneighbors; // [esp+10h] [ebp-8h]
  int numsimplicial; // [esp+14h] [ebp-4h]

  v8 = facetlist;
  v9 = 0;
  numsimplicial = 0;
  numridges = 0;
  totneighbors = 0;
  for ( numcoplanars = 0; v8 != nullptr; v8 = v8->next )
  {
    if ( v8->next == nullptr )
      break;
    if ( (*((_DWORD *)v8 + 20) & 0x400) != 0 && qh_qh.NEWfacets != 0 || printall == 0 && qh_skipfacet(facet: v8) )
    {
      v8->visitid = 0;
    }
    else
    {
      ++v9;
      neighbors = v8->neighbors;
      v8->visitid = v9;
      totneighbors += qh_setsize(set: neighbors);
      if ( (*((_DWORD *)v8 + 20) & 0x1000) != 0 )
        ++numsimplicial;
      else
        numridges += qh_setsize(set: v8->ridges);
      if ( v8->coplanarset != nullptr )
        numcoplanars += qh_setsize(set: v8->coplanarset);
    }
  }
  if ( facets != nullptr )
  {
    v10.p = (void *)facets->e[0];
    e = facets->e;
    if ( v10.i != 0 )
    {
      do
      {
        ++e;
        if ( (*(_DWORD *)(v10.i + 80) & 0x400) != 0 && qh_qh.NEWfacets != 0
          || printall == 0 && qh_skipfacet(facet: (facetT *)v10.p) )
        {
          *(_DWORD *)(v10.i + 72) = 0;
        }
        else
        {
          ++v9;
          v13 = *(setT **)(v10.i + 60);
          *(_DWORD *)(v10.i + 72) = v9;
          totneighbors += qh_setsize(set: v13);
          if ( (*(_DWORD *)(v10.i + 80) & 0x1000) != 0 )
            ++numsimplicial;
          else
            numridges += qh_setsize(set: *(setT **)(v10.i + 56));
          v12 = *(setT **)(v10.i + 68);
          if ( v12 != nullptr )
            numcoplanars += qh_setsize(set: v12);
        }
        v10.p = e->p;
      }
      while ( e->i != 0 );
    }
  }
  qh_qh.visit_id += v9 + 1;
  *numfacetsp = v9;
  *numsimplicialp = numsimplicial;
  *totneighborsp = totneighbors;
  *numridgesp = numridges;
  *numcoplanarsp = numcoplanars;
}

//------------------------------------------------------------------------------
// Address: 0x10063130
// Name: struct setT __near * qh_facetvertices(struct facetT __near *,struct setT __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
facetT *__cdecl qh_facetvertices(setT *facetlist, setT *facets, unsigned int allfacets)
{
  setT *v3; // ebx
  facetT *v4; // esi
  facetT *result; // eax
  vertexT *vertex_list; // esi
  facetT *i; // edi
  setT *vertices; // eax
  setelemT *e; // esi
  _DWORD *p; // eax
  facetT *v11; // esi
  facetT **v12; // edi
  setT *v13; // esi
  _DWORD *v14; // eax
  setelemT *v15; // esi

  ++qh_qh.vertex_visit;
  v3 = facets;
  v4 = (facetT *)facetlist;
  if ( facetlist == (setT *)qh_qh.facet_list && allfacets != 0 && facets == nullptr )
  {
    result = (facetT *)qh_settemp(setsize: qh_qh.num_vertices);
    vertex_list = qh_qh.vertex_list;
    facetlist = (setT *)result;
    if ( qh_qh.vertex_list == nullptr )
      return result;
    while ( vertex_list->next != nullptr )
    {
      vertex_list->visitid = qh_qh.vertex_visit;
      qh_setappend(setp: &facetlist, newelem: vertex_list);
      vertex_list = vertex_list->next;
      if ( vertex_list == nullptr )
        return (facetT *)facetlist;
    }
  }
  else
  {
    facetlist = qh_settemp(setsize: qh_qh.TEMPsize);
    if ( v4 != nullptr )
    {
      for ( i = v4; i != nullptr; i = i->next )
      {
        if ( i->next == nullptr )
          break;
        if ( allfacets != 0 || !qh_skipfacet(facet: i) )
        {
          vertices = i->vertices;
          if ( vertices != nullptr )
          {
            e = vertices->e;
            p = vertices->e[0].p;
            if ( p != nullptr )
            {
              do
              {
                ++e;
                if ( p[4] != qh_qh.vertex_visit )
                {
                  p[4] = qh_qh.vertex_visit;
                  qh_setappend(setp: &facetlist, newelem: p);
                }
                p = (_DWORD *)e->i;
              }
              while ( e->i != 0 );
            }
          }
        }
      }
    }
    if ( v3 != nullptr )
    {
      v11 = (facetT *)v3->e[0].p;
      v12 = (facetT **)v3->e;
      if ( v11 != nullptr )
      {
        do
        {
          ++v12;
          if ( allfacets != 0 || !qh_skipfacet(facet: v11) )
          {
            v13 = v11->vertices;
            if ( v13 != nullptr )
            {
              v14 = v13->e[0].p;
              v15 = v13->e;
              if ( v14 != nullptr )
              {
                do
                {
                  ++v15;
                  if ( v14[4] != qh_qh.vertex_visit )
                  {
                    v14[4] = qh_qh.vertex_visit;
                    qh_setappend(setp: &facetlist, newelem: v14);
                  }
                  v14 = (_DWORD *)v15->i;
                }
                while ( v15->i != 0 );
              }
            }
          }
          v11 = *v12;
        }
        while ( *v12 != nullptr );
      }
    }
  }
  return (facetT *)facetlist;
}

//------------------------------------------------------------------------------
// Address: 0x10063290
// Name: struct setT __near * qh_markvoronoi(struct facetT __near *,struct setT __near *,unsigned int,unsigned int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
setT *__cdecl qh_markvoronoi(
        facetT *facetlist,
        setT *facets,
        unsigned int printall,
        unsigned int *islowerp,
        int *numcentersp)
{
  setT *v5; // eax
  facetT *v6; // edi
  setelemT v7; // edi
  setelemT *e; // esi
  facetT *facet_list; // eax
  facetT *next; // ecx
  facetT *v11; // esi
  int i; // ebx
  facetT *p; // esi
  setelemT *v14; // edi
  setT *vertices; // [esp+8h] [ebp-8h]
  unsigned int islower; // [esp+Ch] [ebp-4h]

  ++qh_qh.printoutnum;
  islower = 0;
  qh_clearcenters(type: qh_ASvoronoi);
  qh_vertexneighbors();
  v5 = qh_pointvertex();
  vertices = v5;
  if ( qh_qh.ATinfinity != 0 )
    *(&v5->maxsize + qh_qh.num_points) = 0;
  if ( ++qh_qh.visit_id < qh_qh.num_facets )
    qh_qh.visit_id = qh_qh.num_facets;
  v6 = facetlist;
  if ( facetlist != nullptr )
  {
    while ( v6->next != nullptr )
    {
      if ( (printall != 0 || !qh_skipfacet(facet: v6)) && (*((_BYTE *)v6 + 82) & 1) == 0 )
      {
        islower = 1;
        break;
      }
      v6 = v6->next;
      if ( v6 == nullptr )
        break;
    }
  }
  if ( facets != nullptr )
  {
    v7.p = (void *)facets->e[0];
    e = facets->e;
    if ( v7.i != 0 )
    {
      while ( 1 )
      {
        ++e;
        if ( (printall != 0 || !qh_skipfacet(facet: (facetT *)v7.p)) && (*(_BYTE *)(v7.i + 82) & 1) == 0 )
          break;
        v7.p = e->p;
        if ( e->i == 0 )
          goto LABEL_21;
      }
      islower = 1;
    }
  }
LABEL_21:
  facet_list = qh_qh.facet_list;
  if ( qh_qh.facet_list != nullptr )
  {
    while ( 1 )
    {
      next = facet_list->next;
      if ( next == nullptr )
        break;
      if ( facet_list->normal != nullptr && (*((_WORD *)facet_list + 41) & 1) == islower )
        facet_list->visitid = 0;
      else
        facet_list->visitid = qh_qh.visit_id;
      *((_DWORD *)facet_list + 20) = *((_DWORD *)facet_list + 20) & 0xFFFF9FFF | 0x4000;
      facet_list = next;
    }
  }
  v11 = facetlist;
  for ( i = 1; v11 != nullptr; v11 = v11->next )
  {
    if ( v11->next == nullptr )
      break;
    if ( printall != 0 || !qh_skipfacet(facet: v11) )
      v11->visitid = i++;
  }
  if ( facets != nullptr )
  {
    p = (facetT *)facets->e[0].p;
    v14 = facets->e;
    if ( p != nullptr )
    {
      do
      {
        ++v14;
        if ( printall != 0 || !qh_skipfacet(facet: p) )
          p->visitid = i++;
        p = (facetT *)v14->i;
      }
      while ( v14->i != 0 );
    }
  }
  *islowerp = islower;
  *numcentersp = i;
  if ( qh_qh.IStracing >= 2 )
    fprintf(str: qh_qh.ferr, format: "qh_markvoronoi: islower %d numcenters %d\n", islower, i);
  return vertices;
}

//------------------------------------------------------------------------------
// Address: 0x10063440
// Name: void qh_printend4geom(struct _iobuf __near *,struct facetT __near *,int __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_printend4geom(_iobuf *fp, facetT *facet, int *nump, unsigned int printall)
{
  int v4; // ebx
  int v5; // ecx
  long double *normal; // eax
  double v7; // xmm2_8
  double v8; // xmm1_8
  double v9; // xmm0_8
  setT *neighbors; // eax
  setelemT *e; // ecx
  setelemT v12; // eax
  int v13; // esi
  setT *ridges; // eax
  facetT *p; // eax
  int v16; // esi
  facetT *furthestdist_high; // ecx
  double color; // [esp+30h] [ebp-1Ch]
  double color_8; // [esp+38h] [ebp-14h]
  double color_16; // [esp+40h] [ebp-Ch]
  facetT **neighborp; // [esp+48h] [ebp-4h]
  facetT **neighborpa; // [esp+48h] [ebp-4h]

  v4 = *nump;
  if ( fp == nullptr || printall == 0 && qh_skipfacet(facet) )
    return;
  if ( qh_qh.PRINTnoplanes != 0 )
    return;
  v5 = *((_DWORD *)facet + 20);
  if ( (v5 & 0x400) != 0 && qh_qh.NEWfacets != 0 )
    return;
  if ( facet->normal == nullptr )
    return;
  normal = facet->normal;
  v7 = (*normal + 1.0) * 0.5;
  color = v7;
  if ( v7 >= -1.0 )
  {
    if ( v7 <= 1.0 )
      goto LABEL_13;
    v7 = 1.0;
  }
  else
  {
    v7 = -1.0;
  }
  color = v7;
LABEL_13:
  v8 = (normal[1] + 1.0) * 0.5;
  color_8 = v8;
  if ( v8 >= -1.0 )
  {
    if ( v8 <= 1.0 )
      goto LABEL_18;
    v8 = 1.0;
  }
  else
  {
    v8 = -1.0;
  }
  color_8 = v8;
LABEL_18:
  v9 = (normal[2] + 1.0) * 0.5;
  color_16 = v9;
  if ( v9 >= -1.0 )
  {
    if ( v9 <= 1.0 )
      goto LABEL_23;
    v9 = 1.0;
  }
  else
  {
    v9 = -1.0;
  }
  color_16 = v9;
LABEL_23:
  facet->visitid = qh_qh.visit_id;
  if ( (v5 & 0x1000) == 0 )
  {
    ridges = facet->ridges;
    if ( ridges != nullptr )
    {
      neighborpa = (facetT **)ridges->e;
      p = (facetT *)ridges->e[0].p;
      if ( p != nullptr )
      {
        v16 = 3 * v4 + 1;
        do
        {
          furthestdist_high = (facetT *)HIDWORD(p->furthestdist);
          ++neighborpa;
          if ( furthestdist_high == facet )
            furthestdist_high = (facetT *)LODWORD(p->maxoutside);
          if ( furthestdist_high->visitid != qh_qh.visit_id )
          {
            fprintf(
              str: fp,
              format: "3 %d %d %d %8.4g %8.4g %8.4g 1 #r%d f%d f%d\n",
              v16 - 1,
              v16,
              v16 + 1,
              v7,
              v8,
              v9,
              HIDWORD(p->maxoutside) & 0xFFFFFF,
              facet->id,
              furthestdist_high->id);
            v7 = color;
            v9 = color_16;
            v8 = color_8;
            ++v4;
            v16 += 3;
          }
          p = *neighborpa;
        }
        while ( *neighborpa != nullptr );
      }
    }
    goto LABEL_39;
  }
  neighbors = facet->neighbors;
  if ( neighbors == nullptr || (e = neighbors->e, v12.p = (void *)neighbors->e[0], v12.i == 0) )
  {
LABEL_39:
    *nump = v4;
    return;
  }
  v13 = 3 * v4 + 1;
  do
  {
    neighborp = (facetT **)++e;
    if ( *(_DWORD *)(v12.i + 72) != qh_qh.visit_id )
    {
      fprintf(
        str: fp,
        format: "3 %d %d %d %8.4g %8.4g %8.4g 1 # f%d f%d\n",
        v13 - 1,
        v13,
        v13 + 1,
        v7,
        v8,
        v9,
        facet->id,
        *(_DWORD *)(v12.i + 76));
      v7 = color;
      v9 = color_16;
      v8 = color_8;
      e = (setelemT *)neighborp;
      ++v4;
      v13 += 3;
    }
    v12.p = e->p;
  }
  while ( e->i != 0 );
  *nump = v4;
}

//------------------------------------------------------------------------------
// Address: 0x10063680
// Name: void qh_printextremes(struct _iobuf __near *,struct facetT __near *,struct setT __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_printextremes(_iobuf *fp, facetT *facetlist, setT *facets, unsigned int printall)
{
  int v4; // ebx
  int v5; // esi
  setT *v6; // eax
  setelemT v7; // esi
  setelemT *e; // edi
  int v9; // eax
  setelemT v10; // edi
  int v11; // esi
  int v12; // ebx
  setT *vertices; // [esp+Ch] [ebp-8h] BYREF
  setT *points; // [esp+10h] [ebp-4h] BYREF

  v4 = 0;
  v5 = qh_qh.num_points + qh_setsize(set: qh_qh.other_points);
  points = qh_settemp(setsize: v5);
  qh_setzero(set: points, index: 0, size: v5);
  v6 = (setT *)qh_facetvertices((setT *)facetlist, facets, allfacets: printall);
  vertices = v6;
  if ( v6 != nullptr )
  {
    v7.p = (void *)v6->e[0];
    e = v6->e;
    if ( v7.i != 0 )
    {
      do
      {
        ++e;
        v9 = qh_pointid(point: *(long double **)(v7.i + 8));
        if ( v9 >= 0 )
        {
          points->e[v9].i = *(_DWORD *)(v7.i + 8);
          ++v4;
        }
        v7.p = e->p;
      }
      while ( e->i != 0 );
    }
  }
  qh_settempfree(set: &vertices);
  fprintf(str: fp, format: "%d\n", v4);
  if ( points != nullptr )
  {
    v10.p = (void *)points->e[0];
    v11 = 0;
    v12 = qh_setsize(set: points);
    if ( v12 > 0 )
    {
      do
      {
        if ( v10.i != 0 )
          fprintf(str: fp, format: "%d\n", v11);
        v10.p = (void *)*(&points[1].maxsize + v11++);
      }
      while ( v11 < v12 );
    }
  }
  qh_settempfree(set: &points);
}

//------------------------------------------------------------------------------
// Address: 0x10063770
// Name: void qh_printextremes_2d(struct _iobuf __near *,struct facetT __near *,struct setT __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_printextremes_2d(_iobuf *fp, facetT *facetlist, setT *facets, unsigned int printall)
{
  int v4; // eax
  facetT *v5; // esi
  unsigned int vertex_visit; // ecx
  setT *v7; // eax
  int i; // ebx
  vertexT *maxsize; // edx
  facetT *p; // edi
  int v11; // eax
  vertexT *v12; // eax
  int v13; // eax
  long double *v14; // [esp-10h] [ebp-28h]
  int numsimplicial; // [esp+0h] [ebp-18h] BYREF
  int totneighbors; // [esp+4h] [ebp-14h] BYREF
  int numridges; // [esp+8h] [ebp-10h] BYREF
  setT *vertices; // [esp+Ch] [ebp-Ch] BYREF
  vertexT *vertexB; // [esp+10h] [ebp-8h] BYREF
  facetT *startfacet; // [esp+14h] [ebp-4h] BYREF

  if ( fp != nullptr )
  {
    qh_countfacets(
      facetlist,
      facets,
      printall,
      numfacetsp: (int *)&vertexB,
      numsimplicialp: &numsimplicial,
      totneighborsp: &totneighbors,
      numridgesp: &numridges,
      numcoplanarsp: (int *)&startfacet);
    vertices = (setT *)qh_facetvertices((setT *)facetlist, facets, allfacets: printall);
    v4 = qh_setsize(set: vertices);
    fprintf(str: fp, format: "%d\n", v4);
    qh_settempfree(set: &vertices);
    if ( vertexB != nullptr )
    {
      if ( facetlist != nullptr )
        startfacet = facetlist;
      else
        startfacet = (facetT *)facets->e[0].p;
      v5 = startfacet;
      vertex_visit = qh_qh.vertex_visit + 1;
      ++qh_qh.visit_id;
      ++qh_qh.vertex_visit;
      while ( 1 )
      {
        v7 = v5->vertices;
        if ( (*((_DWORD *)v5 + 20) & 0x800) != 0 )
        {
          i = v7->e[0].i;
          maxsize = (vertexT *)v7[1].maxsize;
          p = (facetT *)v5->neighbors->e[0].p;
        }
        else
        {
          i = v7[1].maxsize;
          maxsize = (vertexT *)v7->e[0].p;
          p = (facetT *)v5->neighbors[1].maxsize;
        }
        vertexB = maxsize;
        if ( v5->visitid == qh_qh.visit_id )
        {
          ivp_message(templat: "qh_printextremes_2d: loop in facet list.  facet %d nextfacet %d\n", v5->id, p->id);
          qh_errexit2(exitcode: 5, facet: v5, otherfacet: p);
        }
        if ( v5->visitid != 0 )
        {
          if ( *(_DWORD *)(i + 16) != vertex_visit )
          {
            v14 = *(long double **)(i + 8);
            *(_DWORD *)(i + 16) = vertex_visit;
            v11 = qh_pointid(point: v14);
            fprintf(str: fp, format: "%d\n", v11);
            vertex_visit = qh_qh.vertex_visit;
          }
          v12 = vertexB;
          if ( vertexB->visitid != vertex_visit )
          {
            vertexB->visitid = vertex_visit;
            v13 = qh_pointid(point: v12->point);
            fprintf(str: fp, format: "%d\n", v13);
          }
        }
        v5->visitid = qh_qh.visit_id;
        v5 = p;
        if ( p == nullptr || p == startfacet )
          break;
        vertex_visit = qh_qh.vertex_visit;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100638F0
// Name: void qh_printextremes_d(struct _iobuf __near *,struct facetT __near *,struct setT __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_printextremes_d(_iobuf *fp, facetT *facetlist, setT *facets, unsigned int printall)
{
  setelemT v4; // edx
  setelemT *e; // ebx
  int v6; // eax
  int v7; // edi
  int v8; // esi
  int *v9; // ecx
  int v10; // eax
  setelemT *v11; // esi
  setelemT v12; // eax
  int v13; // eax
  setT *vertices; // [esp+8h] [ebp-8h] BYREF
  int numpoints; // [esp+Ch] [ebp-4h]

  numpoints = 0;
  vertices = (setT *)qh_facetvertices((setT *)facetlist, facets, allfacets: printall);
  qh_vertexneighbors();
  if ( vertices != nullptr )
  {
    v4.p = (void *)vertices->e[0];
    e = vertices->e;
    if ( v4.i != 0 )
    {
      do
      {
        v6 = *(_DWORD *)(v4.i + 12);
        ++e;
        v7 = 0;
        v8 = 0;
        if ( v6 == 0 )
          goto LABEL_12;
        v9 = (int *)(v6 + 4);
        v10 = *(_DWORD *)(v6 + 4);
        if ( v10 == 0 )
          goto LABEL_12;
        do
        {
          ++v9;
          if ( (*(_BYTE *)(v10 + 82) & 1) != 0 )
            v8 = 1;
          else
            v7 = 1;
          v10 = *v9;
        }
        while ( *v9 != 0 );
        if ( v8 != 0 && v7 != 0 )
        {
          *(_DWORD *)(v4.i + 20) |= 0x1000000u;
          ++numpoints;
        }
        else
        {
LABEL_12:
          *(_DWORD *)(v4.i + 20) &= ~0x1000000u;
        }
        v4.p = e->p;
      }
      while ( e->i != 0 );
    }
  }
  fprintf(str: fp, format: "%d\n", numpoints);
  if ( vertices != nullptr )
  {
    v11 = vertices->e;
    v12.p = (void *)vertices->e[0];
    if ( v12.i != 0 )
    {
      do
      {
        ++v11;
        if ( (*(_BYTE *)(v12.i + 23) & 1) != 0 )
        {
          v13 = qh_pointid(point: *(long double **)(v12.i + 8));
          fprintf(str: fp, format: "%d\n", v13);
        }
        v12.p = v11->p;
      }
      while ( v11->i != 0 );
    }
  }
  qh_settempfree(set: &vertices);
}

//------------------------------------------------------------------------------
// Address: 0x100639F0
// Name: void qh_printfacet2geom(struct _iobuf __near *,struct facetT __near *,double __near * const)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_printfacet2geom(_iobuf *fp, facetT *facet, long double *color)
{
  long double *v3; // ebx
  int i; // eax
  long double mindist; // [esp+18h] [ebp-20h] BYREF
  long double innerplane; // [esp+20h] [ebp-18h] BYREF
  long double outerplane; // [esp+28h] [ebp-10h] BYREF
  long double *point1; // [esp+30h] [ebp-8h] BYREF
  long double *point0; // [esp+34h] [ebp-4h] BYREF

  qh_facet2point(facet, &point0, &point1, &mindist);
  qh_geomplanes(facet, &outerplane, &innerplane);
  v3 = point1;
  if ( qh_qh.PRINTouter != 0 )
  {
LABEL_4:
    qh_printfacet2geom_points(fp, point1: point0, point2: point1, facet, offset: outerplane, color);
    goto LABEL_5;
  }
  if ( qh_qh.PRINTnoplanes == 0 )
  {
    if ( qh_qh.PRINTinner != 0 )
    {
LABEL_9:
      for ( i = 3; i != 0; color[i] = 1.0 - color[i] )
        --i;
      qh_printfacet2geom_points(fp, point1: point0, point2: v3, facet, offset: innerplane, color);
      goto LABEL_12;
    }
    goto LABEL_4;
  }
LABEL_5:
  if ( qh_qh.PRINTinner != 0
    || qh_qh.PRINTnoplanes == 0 && qh_qh.PRINTouter == 0 && outerplane - innerplane > qh_qh.MAXabs_coord * 2.0 * 0.002 )
  {
    goto LABEL_9;
  }
LABEL_12:
  qh_memfree(object: (void **)v3, size: qh_qh.normal_size);
  qh_memfree(object: (void **)point0, size: qh_qh.normal_size);
}

//------------------------------------------------------------------------------
// Address: 0x10063B10
// Name: void qh_printhyperplaneintersection(struct _iobuf __near *,struct facetT __near *,struct facetT __near *,struct setT __near *,double __near * const)
// Source: json
//------------------------------------------------------------------------------
void __usercall qh_printhyperplaneintersection(
        int a1@<ebx>,
        int a2@<esi>,
        _iobuf *fp,
        facetT *facet1,
        facetT *facet2,
        setT *vertices,
        long double *color)
{
  facetT *v7; // ebx
  long double *normal; // ecx
  facetT *v9; // edi
  int v10; // eax
  vertexT *v11; // esi
  long double *point; // edx
  double v13; // xmm0_8
  double v14; // xmm1_8
  int hull_dim; // ecx
  long double *v16; // edx
  char *v17; // esi
  char *v18; // edi
  double *v19; // eax
  double v20; // xmm2_8
  double v21; // xmm3_8
  int mindenom1_4; // [esp+18h] [ebp-7Ch]
  int mindenom1_4a; // [esp+18h] [ebp-7Ch]
  int v24; // [esp+24h] [ebp-70h]
  int v25; // [esp+28h] [ebp-6Ch]
  long double p[4]; // [esp+2Ch] [ebp-68h] BYREF
  long double t; // [esp+4Ch] [ebp-48h]
  long double s; // [esp+54h] [ebp-40h]
  long double dist2; // [esp+5Ch] [ebp-38h] BYREF
  double costheta; // [esp+64h] [ebp-30h]
  long double dist1; // [esp+6Ch] [ebp-28h] BYREF
  long double denominator; // [esp+74h] [ebp-20h]
  double mindenom; // [esp+7Ch] [ebp-18h]
  vertexT *vertex; // [esp+84h] [ebp-10h]
  unsigned int nearzero2; // [esp+88h] [ebp-Ch] BYREF
  unsigned int nearzero1; // [esp+8Ch] [ebp-8h] BYREF
  vertexT **vertexp; // [esp+90h] [ebp-4h]

  if ( fp != nullptr )
  {
    v25 = a1;
    v7 = facet1;
    normal = facet1->normal;
    v24 = a2;
    v9 = facet2;
    costheta = qh_getangle(vect1: normal, vect2: facet2->normal);
    denominator = 1.0 - costheta * costheta;
    v10 = qh_setsize(set: vertices);
    if ( qh_qh.hull_dim == 3 )
    {
      fprintf(str: fp, format: "VECT 1 %d 1 %d 1 ", v10, v10);
    }
    else if ( qh_qh.hull_dim == 4 && qh_qh.DROPdim >= 0 )
    {
      fprintf(str: fp, format: "OFF 3 1 1 ");
    }
    else
    {
      ++qh_qh.printoutvar;
    }
    fprintf(str: fp, format: "# intersect f%d f%d\n", facet1->id, facet2->id);
    mindenom = 1.0 / (qh_qh.MAXabs_coord * 10.0);
    if ( vertices != nullptr )
    {
      vertexp = (vertexT **)vertices->e;
      v11 = (vertexT *)vertices->e[0].p;
      for ( vertex = v11; v11 != nullptr; vertex = v11 )
      {
        qh_qhstat.stats[51].i += 2;
        point = v11->point;
        ++vertexp;
        qh_distplane(point, facet: v7, dist: &dist1);
        qh_distplane(point: v11->point, facet: v9, dist: &dist2);
        s = qh_divzero(numer: dist2 * costheta - dist1, denom: denominator, mindenom1: mindenom, zerodiv: &nearzero1);
        t = qh_divzero(numer: dist1 * costheta - dist2, denom: denominator, mindenom1: mindenom, zerodiv: &nearzero2);
        if ( nearzero1 != 0 || nearzero2 != 0 )
        {
          v13 = 0.0;
          v14 = 0.0;
        }
        else
        {
          v13 = s;
          v14 = t;
        }
        hull_dim = qh_qh.hull_dim;
        if ( qh_qh.hull_dim != 0 )
        {
          v16 = v11->point;
          v17 = (char *)((char *)v7->normal - (char *)v16);
          v18 = (char *)((char *)v9->normal - (char *)v16);
          v19 = &v16[qh_qh.hull_dim];
          do
          {
            v20 = *(double *)((char *)v19 + (_DWORD)v17 - 8);
            v21 = *(double *)((char *)v19-- + (_DWORD)v18 - 8);
            --hull_dim;
            *(double *)((char *)v19 + (char *)p - (char *)v16) = v20 * v13 + *v19 + v21 * v14;
          }
          while ( hull_dim != 0 );
          v9 = facet2;
          v7 = facet1;
          v11 = vertex;
        }
        if ( qh_qh.PRINTdim > 3 )
        {
          fprintf(str: fp, format: "%8.4g %8.4g %8.4g %8.4g # ", (double)p[0], (double)p[1], (double)p[2], (double)p[3]);
        }
        else
        {
          qh_projectdim3(source: p, destination: p);
          fprintf(str: fp, format: "%8.4g %8.4g %8.4g # ", (double)p[0], (double)p[1], (double)p[2]);
        }
        if ( nearzero1 + nearzero2 != 0 )
        {
          mindenom1_4 = qh_pointid(point: v11->point);
          fprintf(str: fp, format: "p%d (coplanar facets)\n", mindenom1_4);
        }
        else
        {
          mindenom1_4a = qh_pointid(point: v11->point);
          fprintf(str: fp, format: "projected p%d\n", mindenom1_4a);
        }
        v11 = *vertexp;
      }
    }
    if ( qh_qh.hull_dim == 3 )
    {
      fprintf(str: fp, format: "%8.4g %8.4g %8.4g 1.0\n", (double)*color, (double)color[1], (double)color[2]);
    }
    else if ( qh_qh.hull_dim == 4 && qh_qh.DROPdim >= 0 )
    {
      fprintf(str: fp, format: "3 0 1 2 %8.4g %8.4g %8.4g 1.0\n", (double)*color, (double)color[1], (double)color[2]);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10063E60
// Name: void qh_printline3geom(struct _iobuf __near *,double __near *,double __near *,double __near * const)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_printline3geom(_iobuf *fp, long double *pointA, long double *pointB, long double *color)
{
  int i; // esi
  int v5; // eax
  int j; // esi
  int v7; // eax
  long double pA[4]; // [esp+24h] [ebp-40h] BYREF
  long double pB[4]; // [esp+44h] [ebp-20h] BYREF

  if ( fp != nullptr )
  {
    qh_projectdim3(source: pointA, destination: pA);
    qh_projectdim3(source: pointB, destination: pB);
    if ( COERCE_DOUBLE(COERCE_UNSIGNED_INT64(pA[0] - pB[0]) & _mask__AbsDouble_) > 0.001
      || COERCE_DOUBLE(COERCE_UNSIGNED_INT64(pA[1] - pB[1]) & _mask__AbsDouble_) > 0.001
      || COERCE_DOUBLE(COERCE_UNSIGNED_INT64(pA[2] - pB[2]) & _mask__AbsDouble_) > 0.001 )
    {
      fprintf(str: fp, format: "VECT 1 2 1 2 1\n");
      for ( i = 0; i < 3; ++i )
        fprintf(str: fp, format: "%8.4g ", (double)pB[i]);
      v5 = qh_pointid(point: pointB);
      fprintf(str: fp, format: " # p%d\n", v5);
    }
    else
    {
      fprintf(str: fp, format: "VECT 1 1 1 1 1\n");
    }
    for ( j = 0; j < 3; ++j )
      fprintf(str: fp, format: "%8.4g ", (double)pA[j]);
    v7 = qh_pointid(point: pointA);
    fprintf(str: fp, format: " # p%d\n", v7);
    fprintf(str: fp, format: "%8.4g %8.4g %8.4g 1\n", (double)*color, (double)color[1], (double)color[2]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10063FB0
// Name: void qh_printpoint(struct _iobuf __near *,char const __near *,double __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_printpoint(_iobuf *fp, const char *string, long double *point)
{
  int v3; // eax

  v3 = qh_pointid(point);
  qh_printpointid(fp, string, dim: qh_qh.hull_dim, point, id: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10063FE0
// Name: void qh_printpoint3(struct _iobuf __near *,double __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_printpoint3(_iobuf *fp, long double *point)
{
  int i; // esi
  int v3; // eax
  long double p[4]; // [esp+14h] [ebp-20h] BYREF

  qh_projectdim3(source: point, destination: p);
  for ( i = 0; i < 3; ++i )
    fprintf(str: fp, format: "%8.4g ", (double)p[i]);
  v3 = qh_pointid(point);
  fprintf(str: fp, format: " # p%d\n", v3);
}

//------------------------------------------------------------------------------
// Address: 0x10064040
// Name: void qh_printpoints_out(struct _iobuf __near *,struct facetT __near *,struct setT __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_printpoints_out(_iobuf *fp, facetT *facetlist, setT *facets, unsigned int printall)
{
  int v4; // esi
  facetT *v5; // ebx
  setT *v6; // eax
  setelemT v7; // esi
  setelemT *e; // edi
  int v9; // eax
  setT *coplanarset; // eax
  long double *p; // esi
  long double **v12; // edi
  int v13; // eax
  facetT *i; // esi
  setelemT *v15; // ebx
  setT *v16; // esi
  long double **v17; // edi
  long double *v18; // esi
  int v19; // eax
  setelemT v20; // esi
  int v21; // eax
  int v22; // edx
  setelemT *v23; // ecx
  long double *v24; // edi
  int v25; // esi
  int v26; // ebx
  setT *vertices; // [esp+Ch] [ebp-Ch] BYREF
  int numpoints; // [esp+10h] [ebp-8h]
  setT *points; // [esp+14h] [ebp-4h] BYREF

  v4 = qh_qh.num_points + qh_setsize(set: qh_qh.other_points);
  numpoints = 0;
  points = qh_settemp(setsize: v4);
  qh_setzero(set: points, index: 0, size: v4);
  v5 = facetlist;
  v6 = (setT *)qh_facetvertices((setT *)facetlist, facets, allfacets: printall);
  vertices = v6;
  if ( v6 != nullptr )
  {
    v7.p = (void *)v6->e[0];
    e = v6->e;
    if ( v7.i != 0 )
    {
      do
      {
        ++e;
        v9 = qh_pointid(point: *(long double **)(v7.i + 8));
        if ( v9 >= 0 )
          points->e[v9].i = *(_DWORD *)(v7.i + 8);
        v7.p = e->p;
      }
      while ( e->i != 0 );
    }
  }
  if ( qh_qh.KEEPinside != 0 || qh_qh.KEEPcoplanar != 0 || qh_qh.KEEPnearinside != 0 )
  {
    if ( facetlist != nullptr )
    {
      do
      {
        if ( v5->next == nullptr )
          break;
        if ( printall != 0 || !qh_skipfacet(facet: v5) )
        {
          coplanarset = v5->coplanarset;
          if ( coplanarset != nullptr )
          {
            p = (long double *)coplanarset->e[0].p;
            v12 = (long double **)coplanarset->e;
            if ( p != nullptr )
            {
              do
              {
                ++v12;
                v13 = qh_pointid(point: p);
                if ( v13 >= 0 )
                  points->e[v13].i = (int)p;
                p = *v12;
              }
              while ( *v12 != nullptr );
            }
          }
        }
        v5 = v5->next;
      }
      while ( v5 != nullptr );
    }
    if ( facets != nullptr )
    {
      i = (facetT *)facets->e[0].p;
      v15 = facets->e;
      if ( i != nullptr )
      {
        do
        {
          ++v15;
          if ( printall != 0 || !qh_skipfacet(facet: i) )
          {
            v16 = i->coplanarset;
            if ( v16 != nullptr )
            {
              v17 = (long double **)v16->e;
              v18 = (long double *)v16->e[0].p;
              if ( v18 != nullptr )
              {
                do
                {
                  ++v17;
                  v19 = qh_pointid(point: v18);
                  if ( v19 >= 0 )
                    points->e[v19].i = (int)v18;
                  v18 = *v17;
                }
                while ( *v17 != nullptr );
              }
            }
          }
          i = (facetT *)v15->i;
        }
        while ( v15->i != 0 );
      }
    }
  }
  qh_settempfree(set: &vertices);
  if ( points != nullptr && (v20.p = (void *)points->e[0], (v21 = qh_setsize(set: points)) > 0) )
  {
    v22 = numpoints;
    v23 = points->e;
    do
    {
      if ( v20.i != 0 )
        ++v22;
      v20.p = v23[1].p;
      ++v23;
      --v21;
    }
    while ( v21 != 0 );
  }
  else
  {
    v22 = numpoints;
  }
  if ( qh_qh.CDDoutput != 0 )
    fprintf(
      str: fp,
      format: "%s | %s\nbegin\n%d %d real\n",
      qh_qh.rbox_command,
      qh_qh.qhull_command,
      v22,
      qh_qh.hull_dim + 1);
  else
    fprintf(str: fp, format: "%d\n%d\n", qh_qh.hull_dim, v22);
  if ( points != nullptr )
  {
    v24 = (long double *)points->e[0].p;
    v25 = 0;
    v26 = qh_setsize(set: points);
    if ( v26 > 0 )
    {
      do
      {
        if ( v24 != nullptr )
        {
          if ( qh_qh.CDDoutput != 0 )
            fprintf(str: fp, format: "1 ");
          qh_printpoint(fp, string: nullptr, point: v24);
        }
        v24 = (long double *)*(&points[1].maxsize + v25++);
      }
      while ( v25 < v26 );
    }
  }
  if ( qh_qh.CDDoutput != 0 )
    fprintf(str: fp, format: "end\n");
  qh_settempfree(set: &points);
}

//------------------------------------------------------------------------------
// Address: 0x100642A0
// Name: void qh_printpointvect(struct _iobuf __near *,double __near *,double __near *,double __near *,double,double __near * const)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_printpointvect(
        _iobuf *fp,
        long double *point,
        long double *normal,
        long double *center,
        long double radius,
        long double *color)
{
  int hull_dim; // eax
  int v8; // ebx
  int v9; // ecx
  int v10; // esi
  long double v11; // st7
  int v12; // ecx
  double *v13; // eax
  double v14; // xmm1_8
  long double pointA[4]; // [esp+8h] [ebp-40h] BYREF
  long double diff[4]; // [esp+28h] [ebp-20h] BYREF
  long double *centera; // [esp+5Ch] [ebp+14h]

  hull_dim = qh_qh.hull_dim;
  if ( qh_qh.hull_dim != 0 )
  {
    v8 = (char *)normal - (char *)center;
    v9 = (char *)point - (char *)center;
    centera = (long double *)((char *)normal - (char *)center);
    v10 = (char *)center - (char *)diff;
    do
    {
      --hull_dim;
      if ( center != nullptr )
      {
        diff[hull_dim] = *(long double *)((char *)&diff[hull_dim] + v10 + v9)
                       - *(long double *)((char *)&diff[hull_dim] + v10);
      }
      else if ( normal != nullptr )
      {
        v11 = *(long double *)((char *)&diff[hull_dim] + v10 + v8);
        v8 = (int)centera;
        diff[hull_dim] = v11;
      }
      else
      {
        diff[hull_dim] = 0.0;
      }
    }
    while ( hull_dim != 0 );
  }
  if ( center != nullptr )
    qh_normalize2(normal: diff, dim: qh_qh.hull_dim, toporient: 1u, minnorm: nullptr, ismin: nullptr);
  v12 = qh_qh.hull_dim;
  if ( qh_qh.hull_dim != 0 )
  {
    v13 = &point[qh_qh.hull_dim];
    do
    {
      v14 = *(double *)((char *)v13-- + (char *)diff - (char *)point - 8);
      --v12;
      *(double *)((char *)v13 + (char *)pointA - (char *)point) = v14 * radius + *v13;
    }
    while ( v12 != 0 );
  }
  qh_printline3geom(fp, pointA: point, pointB: pointA, color);
}

//------------------------------------------------------------------------------
// Address: 0x10064390
// Name: void qh_printpointvect2(struct _iobuf __near *,double __near *,double __near *,double __near *,double)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_printpointvect2(
        _iobuf *fp,
        long double *point,
        long double *normal,
        long double *center,
        long double radius)
{
  long double yellow[3]; // [esp+18h] [ebp-30h] BYREF
  long double red[3]; // [esp+30h] [ebp-18h] BYREF

  red[0] = 1.0;
  yellow[0] = 1.0;
  yellow[1] = 1.0;
  memset(&red[1], 0, 16);
  yellow[2] = 0.0;
  qh_printpointvect(fp, point, normal, center, radius, color: red);
  qh_printpointvect(fp, point, normal, center, radius: -radius, color: yellow);
}

//------------------------------------------------------------------------------
// Address: 0x10064420
// Name: void qh_printridge(struct _iobuf __near *,struct ridgeT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_printridge(_iobuf *fp, ridgeT *ridge)
{
  facetT *top; // eax
  facetT *bottom; // esi

  if ( fp != nullptr )
  {
    fprintf(str: fp, format: "     - r%d", *((_DWORD *)ridge + 3) & 0xFFFFFF);
    if ( (*((_DWORD *)ridge + 3) & 0x2000000) != 0 )
      fprintf(str: fp, format: " tested");
    if ( (*((_DWORD *)ridge + 3) & 0x4000000) != 0 )
      fprintf(str: fp, format: " nonconvex");
    fprintf(str: fp, format: "\n");
    qh_printvertices(fp, string: "           vertices:", vertices: ridge->vertices);
    top = ridge->top;
    if ( top != nullptr )
    {
      bottom = ridge->bottom;
      if ( bottom != nullptr )
        fprintf(str: fp, format: "           between f%d and f%d\n", top->id, bottom->id);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100644C0
// Name: void qh_printspheres(struct _iobuf __near *,struct setT __near *,double)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_printspheres(_iobuf *fp, setT *vertices, long double radius)
{
  setelemT *e; // ebx
  setelemT v4; // esi

  if ( fp != nullptr )
  {
    ++qh_qh.printoutnum;
    fprintf(
      str: fp,
      format: "{appearance {-edge -normal normscale 0} {\n"
      "INST geom {define vsphere OFF\n"
      "18 32 48\n"
      "\n"
      "0 0 1\n"
      "1 0 0\n"
      "0 1 0\n"
      "-1 0 0\n"
      "0 -1 0\n"
      "0 0 -1\n"
      "0.707107 0 0.707107\n"
      "0 -0.707107 0.707107\n"
      "0.707107 -0.707107 0\n"
      "-0.707107 0 0.707107\n"
      "-0.707107 -0.707107 0\n"
      "0 0.707107 0.707107\n"
      "-0.707107 0.707107 0\n"
      "0.707107 0.707107 0\n"
      "0.707107 0 -0.707107\n"
      "0 0.707107 -0.707107\n"
      "-0.707107 0 -0.707107\n"
      "0 -0.707107 -0.707107\n"
      "\n"
      "3 0 6 11\n"
      "3 0 7 6\t\n"
      "3 0 9 7\t\n"
      "3 0 11 9\n"
      "3 1 6 8\t\n"
      "3 1 8 14\n"
      "3 1 13 6\n"
      "3 1 14 13\n"
      "3 2 11 13\n"
      "3 2 12 11\n"
      "3 2 13 15\n"
      "3 2 15 12\n"
      "3 3 9 12\n"
      "3 3 10 9\n"
      "3 3 12 16\n"
      "3 3 16 10\n"
      "3 4 7 10\n"
      "3 4 8 7\n"
      "3 4 10 17\n"
      "3 4 17 8\n"
      "3 5 14 17\n"
      "3 5 15 14\n"
      "3 5 16 15\n"
      "3 5 17 16\n"
      "3 6 13 11\n"
      "3 7 8 6\n"
      "3 9 10 7\n"
      "3 11 12 9\n"
      "3 14 8 17\n"
      "3 15 13 14\n"
      "3 16 12 15\n"
      "3 17 10 16\n"
      "} transforms { TLIST\n");
    if ( vertices != nullptr )
    {
      e = vertices->e;
      v4.p = (void *)vertices->e[0];
      if ( v4.i != 0 )
      {
        do
        {
          ++e;
          fprintf(
            str: fp,
            format: "%8.4g 0 0 0 # v%d\n 0 %8.4g 0 0\n0 0 %8.4g 0\n",
            (double)radius,
            *(_DWORD *)(v4.i + 20) & 0xFFFFFF,
            (double)radius,
            (double)radius);
          qh_printpoint3(fp, point: *(long double **)(v4.i + 8));
          fprintf(str: fp, format: "1\n");
          v4.p = e->p;
        }
        while ( e->i != 0 );
      }
    }
    fprintf(str: fp, format: "}}}\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10064560
// Name: void qh_printvdiagram(struct _iobuf __near *,int,struct facetT __near *,struct setT __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_printvdiagram(setT *fp, int format, facetT *facetlist, setT *facets, unsigned int printall)
{
  _iobuf *v5; // ebx
  qh_RIDGE v6; // esi
  void (__cdecl *v7)(_iobuf *, vertexT *, vertexT *, setT *); // edi
  int v8; // eax
  unsigned int islower; // [esp+Ch] [ebp-8h] BYREF
  int numcenters; // [esp+10h] [ebp-4h] BYREF

  v5 = (_iobuf *)fp;
  v6 = qh_RIDGEall;
  if ( fp != nullptr )
  {
    switch ( format )
    {
      case 25:
        v7 = qh_printvridge;
        break;
      case 9:
        v6 = qh_RIDGEinner;
        v7 = qh_printvnorm;
        break;
      case 12:
        v6 = qh_RIDGEouter;
        v7 = qh_printvnorm;
        break;
      default:
        ivp_message(templat: "qh_printvdiagram: unknown print format %d.\n", format);
        qh_errexit(exitcode: 1, facet: nullptr, ridge: nullptr);
    }
    fp = qh_markvoronoi(facetlist, facets, printall, islowerp: &islower, numcentersp: &numcenters);
    v8 = qh_printvdiagram2(fp: nullptr, printvridge: nullptr, vertices: fp, innerouter: v6, inorder: 0);
    fprintf(str: v5, format: "%d\n", v8);
    qh_printvdiagram2(
      fp: v5,
      printvridge: (void (__cdecl *)(_iobuf *, vertexT *, vertexT *, setT *, unsigned int))v7,
      vertices: fp,
      innerouter: v6,
      inorder: 1u);
    qh_settempfree(set: &fp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10064620
// Name: void qh_printvertexlist(struct _iobuf __near *,char const __near *,struct facetT __near *,struct setT __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_printvertexlist(_iobuf *fp, const char *string, facetT *facetlist, setT *facets, unsigned int printall)
{
  setelemT *e; // esi
  vertexT *p; // eax
  setT *vertices; // [esp+4h] [ebp-4h] BYREF

  vertices = (setT *)qh_facetvertices((setT *)facetlist, facets, allfacets: printall);
  fputs(string, stream: fp);
  if ( vertices != nullptr )
  {
    e = vertices->e;
    p = (vertexT *)vertices->e[0].p;
    if ( p != nullptr )
    {
      do
      {
        ++e;
        qh_printvertex(fp, vertex: p);
        p = (vertexT *)e->i;
      }
      while ( e->i != 0 );
    }
  }
  qh_settempfree(set: &vertices);
}

//------------------------------------------------------------------------------
// Address: 0x10064690
// Name: void qh_printvneighbors(struct _iobuf __near *,struct facetT __near *,struct setT __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_printvneighbors(_iobuf *fp, facetT *facetlist, setT *facets, unsigned int printall)
{
  int v4; // esi
  setT *v5; // edi
  long double **p; // eax
  setelemT *e; // esi
  facetT *i; // edi
  setT *coplanarset; // eax
  long double **v10; // esi
  long double *v11; // eax
  setelemT *v12; // ebx
  _DWORD *v13; // edi
  int v14; // eax
  long double **v15; // esi
  long double *v16; // eax
  vertexT *v17; // esi
  int v18; // edi
  int v19; // ebx
  int v20; // eax
  unsigned int v21; // edi
  setT *neighbors; // esi
  setelemT v23; // eax
  setelemT *v24; // esi
  int v25; // ecx
  int v26; // eax
  setelemT v27; // eax
  int v28; // ecx
  int v29; // eax
  int numfacets; // [esp+4h] [ebp-20h] BYREF
  int numsimplicial; // [esp+8h] [ebp-1Ch] BYREF
  int totneighbors; // [esp+Ch] [ebp-18h] BYREF
  int vertex_n; // [esp+10h] [ebp-14h] BYREF
  setT *vertices; // [esp+14h] [ebp-10h] BYREF
  int numridges; // [esp+18h] [ebp-Ch] BYREF
  setT *vertex_points; // [esp+1Ch] [ebp-8h] BYREF
  setT *coplanar_points; // [esp+20h] [ebp-4h] BYREF

  v4 = qh_qh.num_points + qh_setsize(set: qh_qh.other_points);
  if ( fp != nullptr )
  {
    qh_countfacets(
      facetlist,
      facets,
      printall,
      numfacetsp: &numfacets,
      numsimplicialp: &numsimplicial,
      totneighborsp: &totneighbors,
      numridgesp: &numridges,
      numcoplanarsp: &vertex_n);
    fprintf(str: fp, format: "%d\n", v4);
    qh_vertexneighbors();
    v5 = facets;
    vertices = (setT *)qh_facetvertices((setT *)facetlist, facets, allfacets: printall);
    vertex_points = qh_settemp(setsize: v4);
    coplanar_points = qh_settemp(setsize: v4);
    qh_setzero(set: vertex_points, index: 0, size: v4);
    qh_setzero(set: coplanar_points, index: 0, size: v4);
    if ( vertices != nullptr )
    {
      p = (long double **)vertices->e[0].p;
      e = vertices->e;
      if ( p != nullptr )
      {
        do
        {
          ++e;
          qh_point_add(set: vertex_points, point: p[2], elem: p);
          p = (long double **)e->i;
        }
        while ( e->i != 0 );
      }
    }
    if ( facetlist != nullptr )
    {
      for ( i = facetlist; i != nullptr; i = i->next )
      {
        if ( i->next == nullptr )
          break;
        coplanarset = i->coplanarset;
        if ( coplanarset != nullptr )
        {
          v10 = (long double **)coplanarset->e;
          v11 = (long double *)coplanarset->e[0].p;
          if ( v11 != nullptr )
          {
            do
            {
              ++v10;
              qh_point_add(set: coplanar_points, point: v11, elem: i);
              v11 = *v10;
            }
            while ( *v10 != nullptr );
          }
        }
      }
      v5 = facets;
    }
    if ( v5 != nullptr )
    {
      v12 = v5->e;
      v13 = v5->e[0].p;
      if ( v13 != nullptr )
      {
        do
        {
          v14 = v13[17];
          ++v12;
          if ( v14 != 0 )
          {
            v15 = (long double **)(v14 + 4);
            v16 = *(long double **)(v14 + 4);
            if ( v16 != nullptr )
            {
              do
              {
                ++v15;
                qh_point_add(set: coplanar_points, point: v16, elem: v13);
                v16 = *v15;
              }
              while ( *v15 != nullptr );
            }
          }
          v13 = (_DWORD *)v12->i;
        }
        while ( v12->i != 0 );
      }
    }
    if ( vertex_points != nullptr )
    {
      v17 = (vertexT *)vertex_points->e[0].p;
      v18 = 0;
      numridges = 0;
      v19 = qh_setsize(set: vertex_points);
      vertex_n = v19;
      if ( v19 > 0 )
      {
        v20 = 0;
        do
        {
          if ( v17 != nullptr )
          {
            v21 = qh_setsize(set: v17->neighbors);
            fprintf(str: fp, format: "%d", v21);
            if ( qh_qh.hull_dim == 3 )
            {
              qh_order_vertexneighbors(vertex: v17);
            }
            else if ( qh_qh.hull_dim >= 4 )
            {
              qsort(
                base: v17->neighbors->e,
                num: v21,
                width: 4u,
                comp: (int (__cdecl *)(const void *, const void *))qh_compare_facetvisit);
            }
            neighbors = v17->neighbors;
            if ( neighbors != nullptr )
            {
              v23.p = (void *)neighbors->e[0];
              v24 = neighbors->e;
              if ( v23.i != 0 )
              {
                do
                {
                  v25 = *(_DWORD *)(v23.i + 72);
                  ++v24;
                  if ( v25 != 0 )
                    v26 = v25 - 1;
                  else
                    v26 = -*(_DWORD *)(v23.i + 76);
                  fprintf(str: fp, format: " %d", v26);
                  v23.p = v24->p;
                }
                while ( v24->i != 0 );
              }
            }
            fprintf(str: fp, format: "\n");
            v18 = numridges;
            v19 = vertex_n;
          }
          else
          {
            v27.p = (void *)coplanar_points->e[v20];
            if ( v27.i != 0 )
            {
              v28 = *(_DWORD *)(v27.i + 72);
              if ( v28 != 0 )
                v29 = v28 - 1;
              else
                v29 = -*(_DWORD *)(v27.i + 76);
              fprintf(str: fp, format: "1 %d\n", v29);
            }
            else
            {
              fprintf(str: fp, format: "0\n");
            }
          }
          v20 = ++v18;
          v17 = (vertexT *)vertex_points->e[v18].p;
          numridges = v18;
        }
        while ( v18 < v19 );
      }
    }
    qh_settempfree(set: &coplanar_points);
    qh_settempfree(set: &vertex_points);
    qh_settempfree(set: &vertices);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10064930
// Name: void qh_printvoronoi(struct _iobuf __near *,int,struct facetT __near *,struct setT __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_printvoronoi(_iobuf *fp, int format, facetT *facetlist, setT *facets, unsigned int printall)
{
  _iobuf *v5; // esi
  setT *v6; // eax
  setelemT v7; // edi
  int v8; // ecx
  int v9; // esi
  int v10; // ebx
  int *v11; // edx
  int v12; // ecx
  unsigned int v13; // ecx
  unsigned int v14; // edx
  int v15; // edi
  int v16; // eax
  int v17; // edi
  facetT *v18; // esi
  int i; // ebx
  unsigned int visitid; // eax
  facetT *p; // esi
  setelemT *e; // edi
  unsigned int v23; // eax
  setelemT v24; // edi
  _iobuf *v25; // ebx
  int v26; // esi
  unsigned int v27; // eax
  int v28; // eax
  int *v29; // ecx
  int v30; // eax
  unsigned int v31; // eax
  int v32; // eax
  int *v33; // esi
  int v34; // eax
  unsigned int v35; // eax
  int v36; // eax
  int *v37; // esi
  int v38; // eax
  unsigned int v39; // eax
  int numcenters; // [esp+18h] [ebp-1Ch] BYREF
  unsigned int islower; // [esp+1Ch] [ebp-18h] BYREF
  int vertex_n; // [esp+20h] [ebp-14h]
  int numvertices; // [esp+24h] [ebp-10h]
  setT *vertices; // [esp+28h] [ebp-Ch] BYREF
  unsigned int numfacets; // [esp+2Ch] [ebp-8h]
  int vertex_i; // [esp+30h] [ebp-4h]
  int numinf; // [esp+3Ch] [ebp+8h]

  v5 = fp;
  numvertices = 0;
  if ( fp != nullptr )
  {
    numfacets = qh_qh.num_facets;
    v6 = qh_markvoronoi(facetlist, facets, printall, islowerp: &islower, numcentersp: &numcenters);
    vertices = v6;
    if ( v6 != nullptr )
    {
      v7.p = (void *)v6->e[0];
      vertex_i = 0;
      vertex_n = qh_setsize(set: v6);
      v6 = vertices;
      if ( vertex_n > 0 )
      {
        islower = 0;
        do
        {
          if ( v7.i != 0 )
          {
            v8 = *(_DWORD *)(v7.i + 12);
            ++numvertices;
            v9 = 0;
            v10 = 0;
            if ( v8 != 0 )
            {
              v11 = (int *)(v8 + 4);
              v12 = *(_DWORD *)(v8 + 4);
              if ( v12 != 0 )
              {
                do
                {
                  v13 = *(_DWORD *)(v12 + 72);
                  ++v11;
                  if ( v13 != 0 )
                  {
                    if ( v13 < numfacets )
                      ++v10;
                  }
                  else
                  {
                    v9 = 1;
                  }
                  v12 = *v11;
                }
                while ( *v11 != 0 );
                if ( v9 != 0 && v10 == 0 )
                {
                  --numvertices;
                  *(int *)((char *)&v6->e[0].i + islower) = 0;
                  v6 = vertices;
                }
              }
            }
          }
          v14 = vertex_i + 1;
          v7.p = (void *)v6->e[v14];
          ++vertex_i;
          islower = v14 * 4;
        }
        while ( vertex_i < vertex_n );
        v5 = fp;
      }
    }
    if ( format == 7 )
    {
      fprintf(
        str: v5,
        format: "{appearance {+edge -face} OFF %d %d 1 # Voronoi centers and cells\n",
        numcenters,
        numvertices);
      v15 = qh_qh.hull_dim - 1;
      if ( qh_qh.hull_dim != 1 )
      {
        do
        {
          fprintf(str: fp, format: "%6.16g ", 0.0);
          --v15;
        }
        while ( v15 != 0 );
      }
      fprintf(str: fp, format: " 0 # infinity not used\n");
    }
    else
    {
      v16 = qh_setsize(set: v6);
      fprintf(str: v5, format: "%d\n%d %d 1\n", qh_qh.hull_dim - 1, numcenters, v16);
      v17 = qh_qh.hull_dim - 1;
      if ( qh_qh.hull_dim != 1 )
      {
        do
        {
          fprintf(str: fp, format: "%6.16g ", -10.101);
          --v17;
        }
        while ( v17 != 0 );
      }
      fprintf(str: fp, format: "\n");
    }
    v18 = facetlist;
    for ( i = 1; v18 != nullptr; v18 = v18->next )
    {
      if ( v18->next == nullptr )
        break;
      visitid = v18->visitid;
      if ( visitid != 0 && visitid < numfacets )
      {
        if ( format == 7 )
          fprintf(str: fp, format: "# %d f%d\n", i++, v18->id);
        qh_printcenter(fp, format, string: nullptr, facet: v18);
      }
    }
    if ( facets != nullptr )
    {
      p = (facetT *)facets->e[0].p;
      e = facets->e;
      if ( p != nullptr )
      {
        do
        {
          v23 = p->visitid;
          ++e;
          if ( v23 != 0 && v23 < numfacets )
          {
            if ( format == 7 )
              fprintf(str: fp, format: "# %d f%d\n", i++, p->id);
            qh_printcenter(fp, format, string: nullptr, facet: p);
          }
          p = (facetT *)e->i;
        }
        while ( e->i != 0 );
      }
    }
    if ( vertices != nullptr
      && (v24.p = (void *)vertices->e[0], vertex_i = 0, (vertex_n = qh_setsize(set: vertices)) > 0) )
    {
      v25 = fp;
      do
      {
        v26 = 0;
        numinf = 0;
        if ( v24.i != 0 )
        {
          if ( qh_qh.hull_dim == 3 )
          {
            qh_order_vertexneighbors(vertex: (vertexT *)v24.p);
          }
          else if ( qh_qh.hull_dim >= 4 )
          {
            v27 = qh_setsize(set: *(setT **)(v24.i + 12));
            qsort(
              base: (void *)(*(_DWORD *)(v24.i + 12) + 4),
              num: v27,
              width: 4u,
              comp: (int (__cdecl *)(const void *, const void *))qh_compare_facetvisit);
          }
          v28 = *(_DWORD *)(v24.i + 12);
          if ( v28 != 0 )
          {
            v29 = (int *)(v28 + 4);
            v30 = *(_DWORD *)(v28 + 4);
            if ( v30 != 0 )
            {
              do
              {
                v31 = *(_DWORD *)(v30 + 72);
                ++v29;
                if ( v31 != 0 )
                {
                  if ( v31 < numfacets )
                    ++v26;
                }
                else
                {
                  numinf = 1;
                }
                v30 = *v29;
              }
              while ( *v29 != 0 );
            }
          }
        }
        if ( format == 7 )
        {
          if ( v24.i != 0 )
          {
            fprintf(str: v25, format: "%d", v26);
            v32 = *(_DWORD *)(v24.i + 12);
            if ( v32 != 0 )
            {
              v33 = (int *)(v32 + 4);
              v34 = *(_DWORD *)(v32 + 4);
              if ( v34 != 0 )
              {
                do
                {
                  v35 = *(_DWORD *)(v34 + 72);
                  ++v33;
                  if ( v35 != 0 && v35 < numfacets )
                    fprintf(str: v25, format: " %d", v35);
                  v34 = *v33;
                }
                while ( *v33 != 0 );
              }
            }
            fprintf(str: v25, format: " # p%d (v%d)\n", vertex_i, *(_DWORD *)(v24.i + 20) & 0xFFFFFF);
          }
          else
          {
            fprintf(str: v25, format: " # p%d is coplanar or isolated\n", vertex_i);
          }
        }
        else
        {
          if ( numinf != 0 )
            ++v26;
          fprintf(str: v25, format: "%d", v26);
          if ( v24.i != 0 )
          {
            v36 = *(_DWORD *)(v24.i + 12);
            if ( v36 != 0 )
            {
              v37 = (int *)(v36 + 4);
              v38 = *(_DWORD *)(v36 + 4);
              if ( v38 != 0 )
              {
                do
                {
                  v39 = *(_DWORD *)(v38 + 72);
                  ++v37;
                  if ( v39 != 0 )
                  {
                    if ( v39 < numfacets )
                      fprintf(str: v25, format: " %d", v39);
                  }
                  else if ( numinf != 0 )
                  {
                    numinf = 0;
                    fprintf(str: v25, format: " %d", 0);
                  }
                  v38 = *v37;
                }
                while ( *v37 != 0 );
              }
            }
          }
          fprintf(str: v25, format: "\n");
        }
        v24.p = (void *)*(&vertices[1].maxsize + vertex_i++);
      }
      while ( vertex_i < vertex_n );
    }
    else
    {
      v25 = fp;
    }
    if ( format == 7 )
      fprintf(str: v25, format: "}\n");
    qh_settempfree(set: &vertices);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10064D50
// Name: void qh_printcentrum(struct _iobuf __near *,struct facetT __near *,double)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_printcentrum(_iobuf *fp, facetT *facet, long double radius)
{
  _iobuf *v3; // ebx
  long double *center; // esi
  long double *v5; // edx
  long double *v6; // eax
  int hull_dim; // ecx
  int v8; // edx
  long double *v9; // eax
  long double v10; // xmm0_8
  long double yaxis[4]; // [esp+24h] [ebp-94h] BYREF
  long double green[3]; // [esp+44h] [ebp-74h] BYREF
  long double xaxis[4]; // [esp+5Ch] [ebp-5Ch] BYREF
  long double dist; // [esp+7Ch] [ebp-3Ch] BYREF
  long double normal[4]; // [esp+84h] [ebp-34h] BYREF
  char *v16; // [esp+A4h] [ebp-14h]
  char *v17; // [esp+A8h] [ebp-10h]
  long double *projpt; // [esp+ACh] [ebp-Ch]
  unsigned int tempcentrum; // [esp+B0h] [ebp-8h]
  vertexT *apex; // [esp+B4h] [ebp-4h]

  v3 = fp;
  tempcentrum = 0;
  green[0] = 0.0;
  green[1] = 1.0;
  green[2] = 0.0;
  if ( fp != nullptr )
  {
    if ( qh_qh.CENTERtype == qh_AScentrum )
    {
      if ( facet->center == nullptr )
        facet->center = qh_getcentrum(facet);
      center = facet->center;
    }
    else
    {
      center = qh_getcentrum(facet);
      tempcentrum = 1;
    }
    fprintf(str: fp, format: "{appearance {-normal -edge normscale 0} ");
    if ( qh_qh.firstcentrum != 0 )
    {
      qh_qh.firstcentrum = 0;
      fprintf(
        str: fp,
        format: "{INST geom { define centrum CQUAD  # f%d\n"
        "-0.3 -0.3 0.0001     0 0 1 1\n"
        " 0.3 -0.3 0.0001     0 0 1 1\n"
        " 0.3  0.3 0.0001     0 0 1 1\n"
        "-0.3  0.3 0.0001     0 0 1 1 } transform { \n",
        facet->id);
    }
    else
    {
      fprintf(str: fp, format: "{INST geom { : centrum } transform { # f%d\n", facet->id);
    }
    v5 = *(long double **)(facet->vertices->e[0].i + 8);
    apex = (vertexT *)facet->vertices->e[0].p;
    qh_distplane(point: v5, facet, &dist);
    v6 = qh_projectpoint(point: apex->point, facet, dist);
    hull_dim = qh_qh.hull_dim;
    projpt = v6;
    if ( qh_qh.hull_dim != 0 )
    {
      apex = (vertexT *)((char *)xaxis - (char *)center);
      v17 = (char *)((char *)facet->normal - (char *)center);
      v8 = (char *)v6 - (char *)center;
      v9 = &center[qh_qh.hull_dim];
      v16 = (char *)((char *)normal - (char *)center);
      do
      {
        v10 = *(long double *)((char *)v9 + v8 - 8) - *(v9 - 1);
        --v9;
        --hull_dim;
        *(long double *)((char *)v9 + (_DWORD)apex) = v10;
        *(double *)((char *)v9 + (_DWORD)v16) = *(double *)((char *)v9 + (_DWORD)v17);
      }
      while ( hull_dim != 0 );
      v3 = fp;
      hull_dim = qh_qh.hull_dim;
    }
    if ( hull_dim == 2 )
    {
      xaxis[2] = 0.0;
      normal[2] = 0.0;
    }
    else if ( hull_dim == 4 )
    {
      qh_projectdim3(source: xaxis, destination: xaxis);
      qh_projectdim3(source: normal, destination: normal);
      qh_normalize2(normal, dim: qh_qh.PRINTdim, toporient: 1u, minnorm: nullptr, ismin: nullptr);
    }
    qh_crossproduct(dim: 3, vecA: xaxis, vecB: normal, vecC: yaxis);
    fprintf(str: v3, format: "%8.4g %8.4g %8.4g 0\n", (double)xaxis[0], (double)xaxis[1], (double)xaxis[2]);
    fprintf(str: v3, format: "%8.4g %8.4g %8.4g 0\n", (double)yaxis[0], (double)yaxis[1], (double)yaxis[2]);
    fprintf(str: v3, format: "%8.4g %8.4g %8.4g 0\n", (double)normal[0], (double)normal[1], (double)normal[2]);
    qh_printpoint3(fp: v3, point: center);
    fprintf(str: v3, format: "1 }}}\n");
    qh_memfree(object: (void **)projpt, size: qh_qh.normal_size);
    qh_printpointvect(fp: v3, point: center, normal: facet->normal, center: nullptr, radius, color: green);
    if ( tempcentrum != 0 )
      qh_memfree(object: (void **)center, size: qh_qh.normal_size);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10064FF0
// Name: void qh_printend(struct _iobuf __near *,int,struct facetT __near *,struct setT __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_printend(_iobuf *fp, int format, facetT *facetlist, setT *facets, unsigned int printall)
{
  _iobuf *v5; // ebx
  facetT *v6; // esi
  unsigned int v7; // edi
  facetT *p; // eax
  setelemT *e; // esi

  v5 = fp;
  if ( fp != nullptr )
  {
    if ( qh_qh.printoutnum == 0 )
      ivp_message(templat: "qhull warning: no facets printed\n");
    switch ( format )
    {
      case 7:
        if ( qh_qh.hull_dim != 4 || qh_qh.DROPdim >= 0 || qh_qh.PRINTnoplanes != 0 )
          goto $LN16_1;
        ++qh_qh.visit_id;
        v6 = facetlist;
        v7 = printall;
        for ( fp = nullptr; v6 != nullptr; v6 = v6->next )
        {
          if ( v6->next == nullptr )
            break;
          qh_printend4geom(fp: v5, facet: v6, nump: (int *)&fp, printall: v7);
        }
        if ( facets != nullptr )
        {
          p = (facetT *)facets->e[0].p;
          e = facets->e;
          if ( p != nullptr )
          {
            do
            {
              ++e;
              qh_printend4geom(fp: v5, facet: p, nump: (int *)&fp, printall: v7);
              p = (facetT *)e->i;
            }
            while ( e->i != 0 );
          }
        }
        if ( fp != (_iobuf *)qh_qh.ridgeoutnum || qh_qh.printoutvar != qh_qh.ridgeoutnum )
        {
          ivp_message(
            templat: "qhull internal error (qh_printend): number of ridges %d != number printed %d and at end %d\n",
            qh_qh.ridgeoutnum,
            qh_qh.printoutvar,
            fp);
          qh_errexit(exitcode: 5, facet: nullptr, ridge: nullptr);
        }
        return;
      case 9:
      case 11:
      case 12:
      case 20:
        if ( qh_qh.CDDoutput != 0 )
          fprintf(str: v5, format: "end\n");
        break;
      case 14:
$LN16_1:
        fprintf(str: v5, format: "}\n");
        break;
      default:
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10065140
// Name: void qh_printfacet3geom_nonsimplicial(struct _iobuf __near *,struct facetT __near *,double __near * const)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_printfacet3geom_nonsimplicial(_iobuf *fp, facetT *facet, long double *color)
{
  int v3; // eax
  setT *v4; // eax
  setelemT v5; // esi
  setelemT *e; // ebx
  long double *v7; // eax
  int i; // ecx
  void ***v9; // esi
  void **p; // eax
  setT *ridges; // eax
  int v12; // esi
  setelemT *v13; // ebx
  facetT *v14; // eax
  long double green[3]; // [esp+18h] [ebp-50h] BYREF
  long double black[3]; // [esp+30h] [ebp-38h] BYREF
  long double dist; // [esp+48h] [ebp-20h] BYREF
  long double innerplane; // [esp+50h] [ebp-18h] BYREF
  long double outerplane; // [esp+58h] [ebp-10h] BYREF
  setT *vertices; // [esp+60h] [ebp-8h] BYREF
  setT *projectedpoints; // [esp+64h] [ebp-4h] BYREF

  memset(black, 0, sizeof(black));
  green[0] = 0.0;
  green[1] = 1.0;
  green[2] = 0.0;
  qh_geomplanes(facet, &outerplane, &innerplane);
  vertices = (setT *)qh_facet3vertex((setT *)facet);
  v3 = qh_setsize(set: vertices);
  v4 = qh_settemp(setsize: v3);
  projectedpoints = v4;
  if ( vertices != nullptr )
  {
    v5.p = (void *)vertices->e[0];
    e = vertices->e;
    if ( v5.i != 0 )
    {
      do
      {
        ++qh_qhstat.stats[51].i;
        ++e;
        qh_distplane(point: *(long double **)(v5.i + 8), facet, &dist);
        v7 = qh_projectpoint(point: *(long double **)(v5.i + 8), facet, dist);
        qh_setappend(setp: &projectedpoints, newelem: v7);
        v5.p = e->p;
      }
      while ( e->i != 0 );
      v4 = projectedpoints;
    }
  }
  if ( qh_qh.PRINTouter != 0 )
  {
LABEL_8:
    qh_printfacet3geom_points(fp, points: v4, facet, offset: outerplane, color);
    v4 = projectedpoints;
    goto LABEL_9;
  }
  if ( qh_qh.PRINTnoplanes == 0 )
  {
    if ( qh_qh.PRINTinner != 0 )
    {
LABEL_13:
      for ( i = 3; i != 0; color[i] = 1.0 - color[i] )
        --i;
      qh_printfacet3geom_points(fp, points: v4, facet, offset: innerplane, color);
      v4 = projectedpoints;
      goto LABEL_16;
    }
    goto LABEL_8;
  }
LABEL_9:
  if ( qh_qh.PRINTinner != 0
    || qh_qh.PRINTnoplanes == 0 && qh_qh.PRINTouter == 0 && outerplane - innerplane > qh_qh.MAXabs_coord * 2.0 * 0.002 )
  {
    goto LABEL_13;
  }
LABEL_16:
  if ( v4 != nullptr )
  {
    v9 = (void ***)v4->e;
    p = (void **)v4->e[0].p;
    if ( p != nullptr )
    {
      do
      {
        ++v9;
        qh_memfree(object: p, size: qh_qh.normal_size);
        p = *v9;
      }
      while ( *v9 != nullptr );
    }
  }
  qh_settempfree(set: &projectedpoints);
  qh_settempfree(set: &vertices);
  if ( (qh_qh.DOintersections != 0 || qh_qh.PRINTridges != 0)
    && ((*((_DWORD *)facet + 20) & 0x400) == 0 || qh_qh.NEWfacets == 0) )
  {
    ridges = facet->ridges;
    facet->visitid = qh_qh.visit_id;
    if ( ridges != nullptr )
    {
      v12 = ridges->e[0].i;
      v13 = ridges->e;
      if ( v12 != 0 )
      {
        do
        {
          v14 = *(facetT **)(v12 + 4);
          ++v13;
          if ( v14 == facet )
            v14 = *(facetT **)(v12 + 8);
          if ( v14->visitid != qh_qh.visit_id )
          {
            if ( qh_qh.DOintersections != 0 )
              qh_printhyperplaneintersection(
                a1: (int)v13,
                a2: v12,
                fp,
                facet1: facet,
                facet2: v14,
                vertices: *(setT **)v12,
                color: black);
            if ( qh_qh.PRINTridges != 0 )
              qh_printline3geom(
                fp,
                pointA: *(long double **)(*(_DWORD *)(*(_DWORD *)v12 + 4) + 8),
                pointB: *(long double **)(*(_DWORD *)(*(_DWORD *)v12 + 8) + 8),
                color: green);
          }
          v12 = v13->i;
        }
        while ( v13->i != 0 );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100653A0
// Name: void qh_printfacet3geom_simplicial(struct _iobuf __near *,struct facetT __near *,double __near * const)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_printfacet3geom_simplicial(_iobuf *fp, facetT *facet, long double *color)
{
  setelemT v3; // eax
  setelemT *e; // esi
  int i; // eax
  setT *neighbors; // edi
  facetT *p; // esi
  facetT **v8; // edi
  setT *v9; // eax
  __int64 offset; // [esp+0h] [ebp-5Ch]
  long double green[3]; // [esp+14h] [ebp-48h] BYREF
  long double black[3]; // [esp+2Ch] [ebp-30h] BYREF
  long double innerplane; // [esp+44h] [ebp-18h] BYREF
  long double outerplane; // [esp+4Ch] [ebp-10h] BYREF
  setT *points; // [esp+54h] [ebp-8h] BYREF
  setT *vertices; // [esp+58h] [ebp-4h] BYREF

  memset(black, 0, sizeof(black));
  green[0] = 0.0;
  green[1] = 1.0;
  green[2] = 0.0;
  qh_geomplanes(facet, &outerplane, &innerplane);
  vertices = (setT *)qh_facet3vertex((setT *)facet);
  points = qh_settemp(setsize: qh_qh.TEMPsize);
  if ( vertices != nullptr )
  {
    v3.p = (void *)vertices->e[0];
    e = vertices->e;
    if ( v3.i != 0 )
    {
      do
      {
        ++e;
        qh_setappend(setp: &points, newelem: *(void **)(v3.i + 8));
        v3.p = e->p;
      }
      while ( e->i != 0 );
    }
  }
  if ( qh_qh.PRINTouter != 0 )
    goto LABEL_7;
  if ( qh_qh.PRINTnoplanes != 0 )
  {
LABEL_8:
    if ( qh_qh.PRINTinner == 0
      && (qh_qh.PRINTnoplanes != 0
       || qh_qh.PRINTouter != 0
       || outerplane - innerplane <= qh_qh.MAXabs_coord * 2.0 * 0.002) )
    {
      goto LABEL_15;
    }
    goto LABEL_12;
  }
  if ( qh_qh.PRINTinner == 0 )
  {
LABEL_7:
    qh_printfacet3geom_points(fp, points, facet, offset: outerplane, color);
    goto LABEL_8;
  }
LABEL_12:
  for ( i = 3; i != 0; color[i] = 1.0 - color[i] )
    --i;
  qh_printfacet3geom_points(fp, points, facet, offset: innerplane, color);
LABEL_15:
  qh_settempfree(set: &points);
  qh_settempfree(set: &vertices);
  if ( (qh_qh.DOintersections != 0 || qh_qh.PRINTridges != 0)
    && ((*((_DWORD *)facet + 20) & 0x400) == 0 || qh_qh.NEWfacets == 0) )
  {
    neighbors = facet->neighbors;
    facet->visitid = qh_qh.visit_id;
    if ( neighbors != nullptr )
    {
      p = (facetT *)neighbors->e[0].p;
      v8 = (facetT **)neighbors->e;
      if ( p != nullptr )
      {
        do
        {
          ++v8;
          if ( p->visitid != qh_qh.visit_id )
          {
            offset = (unsigned int)(((char *)v8 - (char *)facet->neighbors - 8) >> 2);
            v9 = qh_setnew_delnthsorted(
                   set: facet->vertices,
                   size: (setT *)qh_qh.hull_dim,
                   nth: offset,
                   prepend: SHIDWORD(offset));
            vertices = v9;
            if ( qh_qh.DOintersections != 0 )
            {
              qh_printhyperplaneintersection(
                a1: (int)facet,
                a2: (int)p,
                fp,
                facet1: facet,
                facet2: p,
                vertices: v9,
                color: black);
              v9 = vertices;
            }
            if ( qh_qh.PRINTridges != 0 )
              qh_printline3geom(
                fp,
                pointA: *(long double **)(v9->e[0].i + 8),
                pointB: *(long double **)(v9[1].maxsize + 8),
                color: green);
            qh_setfree(setp: &vertices);
          }
          p = *v8;
        }
        while ( *v8 != nullptr );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100655F0
// Name: void qh_printfacet4geom_nonsimplicial(struct _iobuf __near *,struct facetT __near *,double __near * const)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_printfacet4geom_nonsimplicial(vertexT **fp, facetT *facet, long double *color)
{
  facetT *v4; // edi
  setT *ridges; // eax
  ridgeT **e; // eax
  ridgeT *v7; // esi
  facetT *top; // eax
  setT *vertices; // esi
  vertexT *p; // esi
  long double *v11; // eax
  int v12; // esi
  void **i; // edi
  long double dist; // [esp+24h] [ebp-Ch] BYREF
  ridgeT **ridgep; // [esp+2Ch] [ebp-4h]
  vertexT **vertexp; // [esp+38h] [ebp+8h]

  if ( fp != nullptr )
  {
    v4 = facet;
    facet->visitid = qh_qh.visit_id;
    if ( qh_qh.PRINTnoplanes == 0 && ((*((_DWORD *)facet + 20) & 0x400) == 0 || qh_qh.NEWfacets == 0) )
    {
      ridges = facet->ridges;
      if ( ridges != nullptr )
      {
        e = (ridgeT **)ridges->e;
        v7 = *e;
        if ( *e != nullptr )
        {
          do
          {
            ridgep = e + 1;
            top = v7->top;
            if ( top == v4 )
              top = v7->bottom;
            if ( top->visitid != qh_qh.visit_id
              && (qh_qh.PRINTtransparent == 0 || (*((_DWORD *)top + 20) & 0x40000) != 0) )
            {
              if ( qh_qh.DOintersections != 0 )
              {
                qh_printhyperplaneintersection(
                  a1: (int)fp,
                  a2: (int)v7,
                  (_iobuf *)fp,
                  facet1: v4,
                  facet2: top,
                  vertices: v7->vertices,
                  color);
              }
              else
              {
                if ( qh_qh.DROPdim < 0 )
                {
                  ++qh_qh.printoutvar;
                  fprintf(
                    str: (_iobuf *)fp,
                    format: "# r%d between f%d f%d\n",
                    *((_DWORD *)v7 + 3) & 0xFFFFFF,
                    v4->id,
                    top->id);
                }
                else
                {
                  fprintf(str: (_iobuf *)fp, format: "OFF 3 1 1 # f%d\n", v4->id);
                }
                vertices = v7->vertices;
                if ( vertices != nullptr )
                {
                  vertexp = (vertexT **)vertices->e;
                  p = (vertexT *)vertices->e[0].p;
                  if ( p != nullptr )
                  {
                    do
                    {
                      ++qh_qhstat.stats[51].i;
                      ++vertexp;
                      qh_distplane(point: p->point, facet: v4, &dist);
                      v11 = qh_projectpoint(point: p->point, facet: v4, dist);
                      v12 = 0;
                      for ( i = (void **)v11; v12 < qh_qh.hull_dim; ++v12 )
                      {
                        if ( v12 != qh_qh.DROPdim )
                          fprintf(str: (_iobuf *)fp, format: "%8.4g ", *(double *)&i[2 * v12]);
                      }
                      fprintf(str: (_iobuf *)fp, format: "\n");
                      qh_memfree(object: i, size: qh_qh.normal_size);
                      p = *vertexp;
                      v4 = facet;
                    }
                    while ( *vertexp != nullptr );
                  }
                }
                if ( qh_qh.DROPdim >= 0 )
                  fprintf(
                    str: (_iobuf *)fp,
                    format: "3 0 1 2 %8.4g %8.4g %8.4g\n",
                    (double)*color,
                    (double)color[1],
                    (double)color[2]);
              }
            }
            e = ridgep;
            v7 = *ridgep;
          }
          while ( *ridgep != nullptr );
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100657F0
// Name: void qh_printfacet4geom_simplicial(struct _iobuf __near *,struct facetT __near *,double __near * const)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_printfacet4geom_simplicial(vertexT **fp, facetT *facet, long double *color)
{
  facetT *v4; // edi
  setT *neighbors; // eax
  int *e; // eax
  int i; // esi
  setT *v8; // eax
  setelemT v9; // edi
  int j; // esi
  __int64 v11; // [esp+10h] [ebp-1Ch]
  facetT **neighborp; // [esp+24h] [ebp-8h]
  setT *vertices; // [esp+28h] [ebp-4h] BYREF
  vertexT **vertexp; // [esp+34h] [ebp+8h]

  if ( fp != nullptr )
  {
    v4 = facet;
    facet->visitid = qh_qh.visit_id;
    if ( qh_qh.PRINTnoplanes == 0 && ((*((_DWORD *)facet + 20) & 0x400) == 0 || qh_qh.NEWfacets == 0) )
    {
      neighbors = facet->neighbors;
      if ( neighbors != nullptr )
      {
        e = (int *)neighbors->e;
        for ( i = *e; *e != 0; i = *e )
        {
          neighborp = (facetT **)++e;
          if ( *(_DWORD *)(i + 72) != qh_qh.visit_id
            && (qh_qh.PRINTtransparent == 0 || (*(_DWORD *)(i + 80) & 0x40000) != 0) )
          {
            v11 = (unsigned int)(((char *)e - (char *)v4->neighbors - 8) >> 2);
            v8 = qh_setnew_delnthsorted(
                   set: v4->vertices,
                   size: (setT *)qh_qh.hull_dim,
                   nth: v11,
                   prepend: SHIDWORD(v11));
            vertices = v8;
            if ( qh_qh.DOintersections != 0 )
            {
              qh_printhyperplaneintersection(
                a1: (int)fp,
                a2: i,
                (_iobuf *)fp,
                facet1: v4,
                facet2: (facetT *)i,
                vertices: v8,
                color);
            }
            else
            {
              if ( qh_qh.DROPdim < 0 )
              {
                ++qh_qh.printoutvar;
                fprintf(str: (_iobuf *)fp, format: "# ridge between f%d f%d\n", v4->id, *(_DWORD *)(i + 76));
              }
              else
              {
                fprintf(str: (_iobuf *)fp, format: "OFF 3 1 1 # ridge between f%d f%d\n", v4->id, *(_DWORD *)(i + 76));
              }
              if ( vertices != nullptr )
              {
                v9.p = (void *)vertices->e[0];
                vertexp = (vertexT **)vertices->e;
                if ( v9.i != 0 )
                {
                  do
                  {
                    ++vertexp;
                    for ( j = 0; j < qh_qh.hull_dim; ++j )
                    {
                      if ( j != qh_qh.DROPdim )
                        fprintf(str: (_iobuf *)fp, format: "%8.4g ", *(double *)(*(_DWORD *)(v9.i + 8) + 8 * j));
                    }
                    fprintf(str: (_iobuf *)fp, format: "\n");
                    v9.i = (int)*vertexp;
                  }
                  while ( *vertexp != nullptr );
                }
                v4 = facet;
              }
              if ( qh_qh.DROPdim >= 0 )
                fprintf(
                  str: (_iobuf *)fp,
                  format: "3 0 1 2 %8.4g %8.4g %8.4g\n",
                  (double)*color,
                  (double)color[1],
                  (double)color[2]);
            }
            qh_setfree(setp: &vertices);
            e = (int *)neighborp;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100659C0
// Name: void qh_printfacetheader(struct _iobuf __near *,struct facetT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_printfacetheader(_iobuf *fp, facetT *facet)
{
  int v3; // eax
  int v4; // eax
  facetT *v5; // ecx
  facetT *replace; // eax
  setT *outsideset; // eax
  long double *v8; // ebx
  int v9; // eax
  setT *v10; // eax
  long double **e; // ebx
  long double *p; // eax
  int v13; // eax
  setT *coplanarset; // eax
  long double *v15; // ebx
  int v16; // eax
  setT *v17; // eax
  long double **v18; // ebx
  long double *v19; // eax
  int v20; // eax
  setT *neighbors; // esi
  setelemT v22; // eax
  setelemT *v23; // esi
  long double dist; // [esp+14h] [ebp-8h] BYREF
  long double *furthest; // [esp+24h] [ebp+8h]

  if ( fp != nullptr )
  {
    if ( facet == (facetT *)2 )
    {
      fprintf(str: fp, format: " MERGEridge\n");
    }
    else if ( facet == (facetT *)1 )
    {
      fprintf(str: fp, format: " DUPLICATEridge\n");
    }
    else if ( facet != nullptr )
    {
      qh_qh.old_randomdist = qh_qh.RANDOMdist;
      qh_qh.RANDOMdist = 0;
      fprintf(str: fp, format: "- f%d\n", facet->id);
      fprintf(str: fp, format: "    - flags:");
      if ( (*((_DWORD *)facet + 20) & 0x800) != 0 )
        fprintf(str: fp, format: " top");
      else
        fprintf(str: fp, format: " bottom");
      if ( (*((_DWORD *)facet + 20) & 0x1000) != 0 )
        fprintf(str: fp, format: " simplicial");
      if ( (*((_BYTE *)facet + 82) & 1) != 0 )
        fprintf(str: fp, format: " upperDelaunay");
      if ( (*((_DWORD *)facet + 20) & 0x400) != 0 )
        fprintf(str: fp, format: " visible");
      if ( (*((_DWORD *)facet + 20) & 0x200) != 0 )
        fprintf(str: fp, format: " new");
      if ( (*((_DWORD *)facet + 20) & 0x4000000) != 0 )
        fprintf(str: fp, format: " tested");
      if ( (*((_DWORD *)facet + 20) & 0x40000) == 0 )
        fprintf(str: fp, format: " notG");
      if ( (*((_DWORD *)facet + 20) & 0x2000) != 0 )
        fprintf(str: fp, format: " seen");
      if ( (*((_DWORD *)facet + 20) & 0x800000) != 0 )
        fprintf(str: fp, format: " coplanar");
      if ( (*((_BYTE *)facet + 83) & 1) != 0 )
        fprintf(str: fp, format: " mergehorizon");
      if ( (*((_DWORD *)facet + 20) & 0x8000000) != 0 )
        fprintf(str: fp, format: " keepcentrum");
      if ( (*((_DWORD *)facet + 20) & 0x100000) != 0 )
        fprintf(str: fp, format: " dupridge");
      v3 = *((_DWORD *)facet + 20);
      if ( (v3 & 0x200000) != 0 && (v3 & 0x400000) == 0 )
        fprintf(str: fp, format: " mergeridge1");
      if ( (*((_DWORD *)facet + 20) & 0x400000) != 0 )
        fprintf(str: fp, format: " mergeridge2");
      if ( (*((_DWORD *)facet + 20) & 0x10000000) != 0 )
        fprintf(str: fp, format: " newmerge");
      if ( (*((_DWORD *)facet + 20) & 0x8000) != 0 )
        fprintf(str: fp, format: " flipped");
      if ( (*((_DWORD *)facet + 20) & 0x20000) != 0 )
        fprintf(str: fp, format: " notfurthest");
      if ( (*((_DWORD *)facet + 20) & 0x20000000) != 0 )
        fprintf(str: fp, format: " degenerate");
      if ( (*((_DWORD *)facet + 20) & 0x40000000) != 0 )
        fprintf(str: fp, format: " redundant");
      fprintf(str: fp, format: "\n");
      v4 = *((_DWORD *)facet + 20);
      if ( (v4 & 0x80000) != 0 )
      {
        fprintf(str: fp, format: "    - area: %2.2g\n", (double)facet->f.area);
      }
      else if ( qh_qh.NEWfacets != 0 && (v4 & 0x400) != 0 && (v5 = facet->f.replace) != nullptr )
      {
        fprintf(str: fp, format: "    - replacement: f%d\n", v5->id);
      }
      else
      {
        replace = facet->f.replace;
        if ( (*((_DWORD *)facet + 20) & 0x200) != 0 )
        {
          if ( replace != nullptr && replace != facet )
            fprintf(str: fp, format: "    - shares same visible/horizon as f%d\n", replace->id);
        }
        else if ( replace != nullptr )
        {
          fprintf(str: fp, format: "    - was horizon to f%d\n", replace->id);
        }
      }
      if ( (*((_DWORD *)facet + 20) & 0x1FF) != 0 )
        fprintf(str: fp, format: "    - merges: %d\n", *((_DWORD *)facet + 20) & 0x1FF);
      qh_printpointid(fp, string: "    - normal: ", dim: qh_qh.hull_dim, point: facet->normal, id: -1);
      fprintf(str: fp, format: "    - offset: %10.7g\n", (double)facet->offset);
      if ( qh_qh.CENTERtype == qh_ASvoronoi || facet->center != nullptr )
        qh_printcenter(fp, format: 5, string: "    - center: ", facet);
      if ( facet->maxoutside > qh_qh.DISTround )
        fprintf(str: fp, format: "    - maxoutside: %10.7g\n", (double)facet->maxoutside);
      outsideset = facet->outsideset;
      if ( outsideset != nullptr && outsideset->e[0].i != 0 )
      {
        v8 = (long double *)qh_setlast(set: outsideset);
        if ( qh_setsize(set: facet->outsideset) >= 6 )
        {
          if ( qh_setsize(set: facet->outsideset) >= 21 )
          {
            v13 = qh_setsize(set: facet->outsideset);
            fprintf(str: fp, format: "    - outside set:  %d points.", v13);
            qh_printpoint(fp, string: "  Furthest", point: v8);
          }
          else
          {
            qh_printpoints(fp, string: "    - outside set:", points: facet->outsideset);
          }
        }
        else
        {
          v9 = qh_pointid(point: v8);
          fprintf(str: fp, format: "    - outside set (furthest p%d):\n", v9);
          v10 = facet->outsideset;
          if ( v10 != nullptr )
          {
            e = (long double **)v10->e;
            p = (long double *)v10->e[0].p;
            if ( p != nullptr )
            {
              do
              {
                ++e;
                qh_printpoint(fp, string: "     ", point: p);
                p = *e;
              }
              while ( *e != nullptr );
            }
          }
        }
        fprintf(str: fp, format: "    - furthest distance= %2.2g\n", (double)facet->furthestdist);
      }
      coplanarset = facet->coplanarset;
      if ( coplanarset != nullptr && coplanarset->e[0].i != 0 )
      {
        v15 = (long double *)qh_setlast(set: facet->coplanarset);
        furthest = v15;
        if ( qh_setsize(set: facet->coplanarset) >= 6 )
        {
          if ( qh_setsize(set: facet->coplanarset) >= 21 )
          {
            v20 = qh_setsize(set: facet->coplanarset);
            fprintf(str: fp, format: "    - coplanar set:  %d points.", v20);
            qh_printpoint(fp, string: "  Furthest", point: v15);
          }
          else
          {
            qh_printpoints(fp, string: "    - coplanar set:", points: facet->coplanarset);
          }
        }
        else
        {
          v16 = qh_pointid(point: v15);
          fprintf(str: fp, format: "    - coplanar set (furthest p%d):\n", v16);
          v17 = facet->coplanarset;
          if ( v17 != nullptr )
          {
            v18 = (long double **)v17->e;
            v19 = (long double *)v17->e[0].p;
            if ( v19 != nullptr )
            {
              do
              {
                ++v18;
                qh_printpoint(fp, string: "     ", point: v19);
                v19 = *v18;
              }
              while ( *v18 != nullptr );
            }
          }
        }
        ++qh_qhstat.stats[51].i;
        qh_distplane(point: furthest, facet, &dist);
        fprintf(str: fp, format: "      furthest distance= %2.2g\n", (double)dist);
      }
      qh_printvertices(fp, string: "    - vertices:", vertices: facet->vertices);
      fprintf(str: fp, format: "    - neighboring facets: ");
      neighbors = facet->neighbors;
      if ( neighbors != nullptr )
      {
        v22.p = (void *)neighbors->e[0];
        v23 = neighbors->e;
        if ( v22.i != 0 )
        {
          do
          {
            ++v23;
            if ( v22.i == 2 )
            {
              fprintf(str: fp, format: " MERGE");
            }
            else if ( v22.i == 1 )
            {
              fprintf(str: fp, format: " DUP");
            }
            else
            {
              fprintf(str: fp, format: " f%d", *(_DWORD *)(v22.i + 76));
            }
            v22.p = v23->p;
          }
          while ( v23->i != 0 );
        }
      }
      fprintf(str: fp, format: "\n");
      qh_qh.RANDOMdist = qh_qh.old_randomdist;
    }
    else
    {
      fprintf(str: fp, format: " NULLfacet\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10065F80
// Name: void qh_printfacetridges(struct _iobuf __near *,struct facetT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_printfacetridges(_iobuf *fp, facetT *facet)
{
  setT *ridges; // eax
  setelemT *e; // esi
  setelemT v5; // eax
  setT *v6; // eax
  setelemT *v7; // ecx
  setelemT v8; // eax
  ridgeT *i; // esi
  int v10; // eax
  setT *neighbors; // eax
  facetT **v12; // ecx
  setT *v13; // eax
  setelemT *v14; // esi
  setelemT v15; // eax
  facetT *v16; // ecx
  setT *v17; // eax
  setelemT *v18; // esi
  setelemT v19; // eax
  setT *v20; // edi
  setelemT v21; // eax
  setelemT *v22; // esi
  facetT **neighborp; // [esp+4h] [ebp-8h]
  int numridges; // [esp+8h] [ebp-4h]
  facetT *neighbor; // [esp+14h] [ebp+8h]

  numridges = 0;
  if ( fp != nullptr )
  {
    if ( (*((_DWORD *)facet + 20) & 0x400) != 0 && qh_qh.NEWfacets != 0 )
    {
      fprintf(str: fp, format: "    - ridges (ids may be garbage):");
      ridges = facet->ridges;
      if ( ridges != nullptr )
      {
        e = ridges->e;
        v5.p = (void *)ridges->e[0];
        if ( v5.i != 0 )
        {
          do
          {
            ++e;
            fprintf(str: fp, format: " r%d", *(_DWORD *)(v5.i + 12) & 0xFFFFFF);
            v5.p = e->p;
          }
          while ( e->i != 0 );
        }
      }
      fprintf(str: fp, format: "\n");
    }
    else
    {
      fprintf(str: fp, format: "    - ridges:\n");
      v6 = facet->ridges;
      if ( v6 != nullptr )
      {
        v7 = v6->e;
        for ( v8.p = (void *)v6->e[0]; v8.i != 0; ++v7 )
        {
          *(_DWORD *)(v8.i + 12) &= ~0x1000000u;
          v8.p = v7[1].p;
        }
      }
      if ( qh_qh.hull_dim == 3 )
      {
        for ( i = (ridgeT *)facet->ridges->e[0].p; i != nullptr; i = qh_nextridge3d(atridge: i, facet, vertexp: nullptr) )
        {
          v10 = *((_DWORD *)i + 3);
          if ( (v10 & 0x1000000) != 0 )
            break;
          *((_DWORD *)i + 3) = v10 | 0x1000000;
          qh_printridge(fp, ridge: i);
          ++numridges;
        }
      }
      else
      {
        neighbors = facet->neighbors;
        if ( neighbors != nullptr )
        {
          v12 = (facetT **)neighbors->e;
          neighbor = (facetT *)neighbors->e[0].p;
          if ( neighbor != nullptr )
          {
            do
            {
              v13 = facet->ridges;
              neighborp = ++v12;
              if ( v13 != nullptr )
              {
                v14 = v13->e;
                v15.p = (void *)v13->e[0];
                if ( v15.i != 0 )
                {
                  do
                  {
                    v16 = *(facetT **)(v15.i + 4);
                    ++v14;
                    if ( v16 == facet )
                      v16 = *(facetT **)(v15.i + 8);
                    if ( v16 == neighbor )
                    {
                      *(_DWORD *)(v15.i + 12) |= 0x1000000u;
                      qh_printridge(fp, ridge: (ridgeT *)v15.p);
                      ++numridges;
                    }
                    v15.p = v14->p;
                  }
                  while ( v14->i != 0 );
                  v12 = neighborp;
                }
              }
              neighbor = *v12;
            }
            while ( *v12 != nullptr );
          }
        }
      }
      if ( numridges != qh_setsize(set: facet->ridges) )
      {
        fprintf(str: fp, format: "     - all ridges:");
        v17 = facet->ridges;
        if ( v17 != nullptr )
        {
          v18 = v17->e;
          v19.p = (void *)v17->e[0];
          if ( v19.i != 0 )
          {
            do
            {
              ++v18;
              fprintf(str: fp, format: " r%d", *(_DWORD *)(v19.i + 12) & 0xFFFFFF);
              v19.p = v18->p;
            }
            while ( v18->i != 0 );
          }
        }
        fprintf(str: fp, format: "\n");
      }
      v20 = facet->ridges;
      if ( v20 != nullptr )
      {
        v21.p = (void *)v20->e[0];
        v22 = v20->e;
        if ( v21.i != 0 )
        {
          do
          {
            ++v22;
            if ( (*(_BYTE *)(v21.i + 15) & 1) == 0 )
              qh_printridge(fp, ridge: (ridgeT *)v21.p);
            v21.p = v22->p;
          }
          while ( v22->i != 0 );
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10066190
// Name: void qh_printhelp_singular(struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_printhelp_singular(_iobuf *fp)
{
  facetT *i; // ebx
  setT *vertices; // eax
  setelemT *e; // esi
  setelemT v4; // eax
  int v5; // eax
  int hull_dim; // edx
  int j; // esi
  int num_points; // eax
  double v9; // xmm1_8
  double v10; // xmm2_8
  double *v11; // ecx
  int v12; // edx
  long double dist; // [esp+24h] [ebp-8h] BYREF

  if ( fp != nullptr )
  {
    fprintf(
      str: fp,
      format: "\n"
      "The input to qhull appears to be less than %d dimensional, or a\n"
      "computation has overflowed.\n"
      "\n"
      "Qhull could not construct a clearly convex simplex from points:\n",
      qh_qh.hull_dim);
    qh_printvertexlist(fp, string: str, facetlist: qh_qh.facet_list, facets: nullptr, printall: 1u);
    fprintf(
      str: fp,
      format: "\n"
      "The center point is coplanar with a facet, or a vertex is coplanar\n"
      "with a neighboring facet.  The maximum round off error for\n"
      "computing distances is %2.2g.  The center point, facets and distances\n"
      "to the center point are as follows:\n"
      "\n",
      (double)qh_qh.DISTround);
    qh_printpointid(fp, string: "center point", dim: qh_qh.hull_dim, point: qh_qh.interior_point, id: -1);
    fprintf(str: fp, format: "\n");
    for ( i = qh_qh.facet_list; i != nullptr; i = i->next )
    {
      if ( i->next == nullptr )
        break;
      fprintf(str: fp, format: "facet");
      vertices = i->vertices;
      if ( vertices != nullptr )
      {
        e = vertices->e;
        v4.p = (void *)vertices->e[0];
        if ( v4.i != 0 )
        {
          do
          {
            ++e;
            v5 = qh_pointid(point: *(long double **)(v4.i + 8));
            fprintf(str: fp, format: " p%d", v5);
            v4.p = e->p;
          }
          while ( e->i != 0 );
        }
      }
      ++qh_qhstat.stats[51].i;
      qh_distplane(point: qh_qh.interior_point, facet: i, &dist);
      fprintf(str: fp, format: " distance= %4.2g\n", (double)dist);
    }
    if ( qh_qh.HALFspace != 0 )
      fprintf(
        str: fp,
        format: "\nThese points are the dual of the given halfspaces.  They indicate that\nthe intersection is degenerate.\n");
    fprintf(
      str: fp,
      format: "\n"
      "These points either have a maximum or minimum x-coordinate, or\n"
      "they maximize the determinant for k coordinates.  Trial points\n"
      "are first selected from points that maximize a coordinate.\n");
    if ( qh_qh.hull_dim >= 8 )
      fprintf(
        str: fp,
        format: "\n"
        "Because of the high dimension, the min x-coordinate and max-coordinate\n"
        "points are used if the determinant is non-zero.  Option 'Qs' will\n"
        "do a better, though much slower, job.  Instead of 'Qs', you can change\n"
        "the points by randomly rotating the input with 'QR0'.\n");
    fprintf(str: fp, format: "\nThe min and max coordinates for each dimension are:\n");
    hull_dim = qh_qh.hull_dim;
    for ( j = 0; j < qh_qh.hull_dim; ++j )
    {
      num_points = qh_qh.num_points;
      v9 = 1.797693134862316e308;
      v10 = -2.225073858507201e-308;
      v11 = &qh_qh.first_point[j];
      if ( qh_qh.num_points != 0 )
      {
        v12 = 8 * hull_dim;
        do
        {
          --num_points;
          if ( *v11 > v10 )
            v10 = *v11;
          if ( v9 > *v11 )
            v9 = *v11;
          v11 = (double *)((char *)v11 + v12);
        }
        while ( num_points != 0 );
      }
      fprintf(str: fp, format: "  %d:  %8.4g  %8.4g  difference= %4.4g\n", j, v9, v10, v10 - v9);
      hull_dim = qh_qh.hull_dim;
    }
    fprintf(
      str: fp,
      format: "\n"
      "If the input should be full dimensional, you have several options that\n"
      "may determine an initial simplex:\n"
      "  - use 'QJ'  to joggle the input and make it full dimensional\n"
      "  - use 'QbB' to scale the points to the unit cube\n"
      "  - use 'QR0' to randomly rotate the input for different maximum points\n"
      "  - use 'Qs'  to search all points for the initial simplex\n"
      "  - use 'En'  to specify a maximum roundoff error less than %2.2g.\n"
      "  - trace execution with 'T3' to see the determinant for each point.\n",
      (double)qh_qh.DISTround);
    fprintf(
      str: fp,
      format: "\n"
      "If the input is lower dimensional:\n"
      "  - use 'QJ' to joggle the input and make it full dimensional\n"
      "  - use 'Qbk:0Bk:0' to delete coordinate k from the input.  You should\n"
      "    pick the coordinate with the least range.  The hull will have the\n"
      "    correct topology.\n"
      "  - determine the flat containing the points, rotate the points\n"
      "    into a coordinate plane, and delete the other coordinates.\n"
      "  - add one or more points to make the input full dimensional.\n");
    if ( qh_qh.DELAUNAY != 0 && qh_qh.ATinfinity == 0 )
      fprintf(
        str: fp,
        format: "\n"
        "\n"
        "This is a Delaunay triangulation and the input is co-circular or co-spherical:\n"
        "  - use 'Qz' to add a point \"at infinity\" (i.e., above the paraboloid)\n"
        "  - or use 'QJ' to joggle the input and avoid co-circular data\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100663E0
// Name: void qh_printbegin(struct _iobuf __near *,int,struct facetT __near *,struct setT __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_printbegin(_iobuf *fp, int format, facetT *facetlist, setT *facets, unsigned int printall)
{
  _iobuf *v5; // ebx
  unsigned int v6; // esi
  facetT *v7; // edi
  int hull_dim; // ecx
  facetT *p; // eax
  setelemT *e; // edi
  int v11; // esi
  int v12; // edi
  int v13; // edi
  long double *first_point; // edi
  long double *v15; // esi
  setelemT *v16; // edi
  long double *i; // eax
  double v18; // xmm0_8
  double premerge_centrum; // xmm1_8
  double v20; // xmm1_8
  double MINvisible; // xmm1_8
  double premerge_cos; // xmm2_8
  facetT *v23; // esi
  setT *v24; // eax
  setelemT *v25; // edi
  setelemT v26; // eax
  setT *coplanarset; // eax
  long double **v28; // edi
  long double *v29; // eax
  setT *outsideset; // eax
  long double **v31; // edi
  long double *v32; // eax
  facetT *ptr; // esi
  setelemT *v34; // eax
  setT *v35; // eax
  long double **v36; // edi
  long double *v37; // eax
  setT *v38; // eax
  long double **v39; // edi
  long double *v40; // eax
  int v41; // edi
  int v42; // ecx
  long double *v43; // esi
  long double *v44; // ebx
  long double *v45; // eax
  setelemT *v46; // esi
  facetT *j; // esi
  int v48; // [esp-4h] [ebp-2Ch]
  _iobuf *radius; // [esp+0h] [ebp-28h]
  int radius_4; // [esp+4h] [ebp-24h]
  int numcoplanars; // [esp+14h] [ebp-14h] BYREF
  int totneighbors; // [esp+18h] [ebp-10h] BYREF
  int numridges; // [esp+1Ch] [ebp-Ch] BYREF
  int numsimplicial; // [esp+20h] [ebp-8h] BYREF
  setT *vertices; // [esp+24h] [ebp-4h] BYREF

  v5 = fp;
  if ( fp != nullptr )
  {
    v6 = printall;
    v7 = facetlist;
    qh_qh.printoutnum = 0;
    qh_countfacets(
      facetlist,
      facets,
      printall,
      numfacetsp: (int *)&fp,
      numsimplicialp: &numsimplicial,
      totneighborsp: &totneighbors,
      numridgesp: &numridges,
      numcoplanarsp: &numcoplanars);
    hull_dim = qh_qh.hull_dim;
    switch ( format )
    {
      case 0:
        return;
      case 1:
      case 3:
      case 8:
      case 10:
      case 15:
      case 25:
        goto $LN143;
      case 4:
        if ( qh_qh.CENTERtype == qh_ASnone )
          qh_clearcenters(type: qh_AScentrum);
        goto $LN140;
      case 5:
      case 6:
        if ( v7 != nullptr )
          qh_printvertexlist(fp: v5, string: "Vertices and facets:\n", facetlist: v7, facets, printall: v6);
        return;
      case 7:
        if ( qh_qh.hull_dim > 4 || qh_qh.VORONOI != 0 && qh_qh.hull_dim > 3 )
          goto LABELnoformat;
        if ( qh_qh.hull_dim == 2 )
        {
          if ( qh_qh.PRINTridges == 0 && qh_qh.DOintersections == 0 )
            goto LABEL_22;
          ivp_message(templat: "qhull warning: output for ridges and intersections not implemented in 2-d\n");
          hull_dim = qh_qh.hull_dim;
        }
        if ( hull_dim == 4 )
        {
          if ( qh_qh.PRINTinner == 0 && qh_qh.PRINTouter == 0 )
          {
            if ( qh_qh.PRINTdim != 4 )
              goto LABEL_28;
            if ( qh_qh.PRINTcentrums == 0 )
              goto LABEL_23;
          }
          ivp_message(templat: "qhull warning: output for outer/inner planes and centrums not implemented in 4-d\n");
        }
LABEL_22:
        if ( qh_qh.PRINTdim == 4 )
        {
LABEL_23:
          if ( qh_qh.PRINTspheres != 0 )
          {
            ivp_message(templat: "qhull warning: output for vertices not implemented in 4-d\n");
            if ( qh_qh.PRINTdim != 4 )
              goto LABEL_28;
          }
          if ( qh_qh.DOintersections == 0 || qh_qh.PRINTnoplanes == 0 )
            goto LABEL_33;
          ivp_message(templat: "qhull warning: 'Gnh' generates no output in 4-d\n");
        }
LABEL_28:
        switch ( qh_qh.PRINTdim )
        {
          case 2:
            fprintf(
              str: v5,
              format: "{appearance {linewidth 3} LIST # %s | %s\n",
              qh_qh.rbox_command,
              qh_qh.qhull_command);
            break;
          case 3:
            fprintf(
              str: v5,
              format: "{appearance {+edge -evert linewidth 2} LIST # %s | %s\n",
              qh_qh.rbox_command,
              qh_qh.qhull_command);
            break;
          case 4:
LABEL_33:
            ++qh_qh.visit_id;
            for ( fp = nullptr; v7 != nullptr; v7 = v7->next )
            {
              if ( v7->next == nullptr )
                break;
              qh_printend4geom(fp: nullptr, facet: v7, nump: (int *)&fp, printall: v6);
            }
            if ( facets != nullptr )
            {
              p = (facetT *)facets->e[0].p;
              e = facets->e;
              if ( p != nullptr )
              {
                do
                {
                  ++e;
                  qh_printend4geom(fp: nullptr, facet: p, nump: (int *)&fp, printall: v6);
                  p = (facetT *)e->i;
                }
                while ( e->i != 0 );
              }
            }
            qh_qh.ridgeoutnum = (int)fp;
            qh_qh.printoutvar = 0;
            fprintf(str: v5, format: "LIST # %s | %s\n", qh_qh.rbox_command, qh_qh.qhull_command);
            break;
          default:
            break;
        }
        if ( qh_qh.PRINTdots != 0 )
        {
          ++qh_qh.printoutnum;
          v11 = qh_qh.num_points + qh_setsize(set: qh_qh.other_points);
          if ( qh_qh.DELAUNAY != 0 && qh_qh.ATinfinity != 0 )
            --v11;
          if ( qh_qh.PRINTdim == 4 )
            fprintf(str: v5, format: "4VECT %d %d 1\n", v11, v11);
          else
            fprintf(str: v5, format: "VECT %d %d 1\n", v11, v11);
          v12 = v11;
          while ( v12 != 0 )
          {
            if ( --v12 % 20 == 0 )
              fprintf(str: v5, format: "\n");
            fprintf(str: v5, format: "1 ");
          }
          fprintf(str: v5, format: "# 1 point per line\n1 ");
          v13 = v11 - 1;
          if ( v11 != 1 )
          {
            do
            {
              if ( --v13 % 20 == 0 )
                fprintf(str: v5, format: "\n");
              fprintf(str: v5, format: "0 ");
            }
            while ( v13 != 0 );
          }
          fprintf(str: v5, format: "# 1 color for all\n");
          first_point = qh_qh.first_point;
          v15 = &qh_qh.first_point[qh_qh.hull_dim * qh_qh.num_points];
          if ( qh_qh.first_point < v15 )
          {
            do
            {
              if ( qh_qh.DELAUNAY == 0
                || qh_qh.ATinfinity == 0
                || qh_pointid(point: first_point) != qh_qh.num_points - 1 )
              {
                if ( qh_qh.PRINTdim == 4 )
                  qh_printpoint(fp: v5, string: nullptr, point: first_point);
                else
                  qh_printpoint3(fp: v5, point: first_point);
              }
              first_point += qh_qh.hull_dim;
            }
            while ( first_point < v15 );
          }
          if ( qh_qh.other_points != nullptr )
          {
            v16 = qh_qh.other_points->e;
            i = (long double *)qh_qh.other_points->e[0].p;
            if ( i != nullptr )
            {
              do
              {
                ++v16;
                if ( qh_qh.PRINTdim == 4 )
                  qh_printpoint(fp: v5, string: nullptr, point: i);
                else
                  qh_printpoint3(fp: v5, point: i);
                i = (long double *)v16->i;
              }
              while ( v16->i != 0 );
            }
          }
          fprintf(str: v5, format: "0 1 1 1  # color of points\n");
        }
        if ( qh_qh.PRINTdim == 4 && qh_qh.PRINTnoplanes == 0 )
          fprintf(str: v5, format: "4OFF %d %d 1\n", 3 * qh_qh.ridgeoutnum, qh_qh.ridgeoutnum);
        v18 = qh_qh.DISTround * 2.0;
        qh_qh.PRINTcradius = qh_qh.DISTround * 2.0;
        if ( qh_qh.PREmerge != 0 )
        {
          premerge_centrum = qh_qh.premerge_centrum;
        }
        else
        {
          if ( qh_qh.POSTmerge == 0 )
            goto LABEL_79;
          premerge_centrum = qh_qh.postmerge_centrum;
        }
        v20 = premerge_centrum + qh_qh.DISTround;
        if ( v20 > v18 )
        {
          v18 = v20;
          qh_qh.PRINTcradius = v20;
        }
LABEL_79:
        MINvisible = v18;
        qh_qh.PRINTradius = v18;
        if ( qh_qh.PRINTcoplanar + qh_qh.PRINTspheres != 0 && qh_qh.MAXabs_coord * 0.02 > v18 )
        {
          MINvisible = qh_qh.MAXabs_coord * 0.02;
          qh_qh.PRINTradius = qh_qh.MAXabs_coord * 0.02;
        }
        premerge_cos = qh_qh.premerge_cos;
        if ( qh_qh.premerge_cos < 8.988465674311579e307
          || qh_qh.PREmerge == 0
          && qh_qh.POSTmerge != 0
          && (premerge_cos = qh_qh.postmerge_cos, qh_qh.postmerge_cos < 8.988465674311579e307) )
        {
          if ( (1.0 - premerge_cos) * qh_qh.MAXabs_coord > MINvisible )
          {
            MINvisible = (1.0 - premerge_cos) * qh_qh.MAXabs_coord;
            qh_qh.PRINTradius = MINvisible;
          }
        }
        if ( qh_qh.MINvisible > MINvisible )
        {
          MINvisible = qh_qh.MINvisible;
          qh_qh.PRINTradius = qh_qh.MINvisible;
        }
        if ( qh_qh.JOGGLEmax < 8.988465674311579e307 )
          qh_qh.PRINTradius = sqrt((double)qh_qh.hull_dim) * qh_qh.JOGGLEmax + MINvisible;
        if ( qh_qh.PRINTdim != 4 && (qh_qh.PRINTcoplanar != 0 || qh_qh.PRINTspheres != 0 || qh_qh.PRINTcentrums != 0) )
        {
          v23 = facetlist;
          v24 = (setT *)qh_facetvertices((setT *)facetlist, facets, allfacets: printall);
          vertices = v24;
          if ( qh_qh.PRINTspheres != 0 && qh_qh.PRINTdim <= 3 )
          {
            qh_printspheres(fp: v5, vertices: v24, radius: qh_qh.PRINTradius);
            v24 = vertices;
          }
          if ( qh_qh.PRINTcoplanar != 0 || qh_qh.PRINTcentrums != 0 )
          {
            qh_qh.firstcentrum = 1;
            if ( qh_qh.PRINTcoplanar != 0 && qh_qh.PRINTspheres == 0 && v24 != nullptr )
            {
              v25 = v24->e;
              v26.p = (void *)v24->e[0];
              if ( v26.i != 0 )
              {
                do
                {
                  ++v25;
                  qh_printpointvect2(
                    fp: v5,
                    point: *(long double **)(v26.i + 8),
                    normal: nullptr,
                    center: qh_qh.interior_point,
                    radius: qh_qh.PRINTradius);
                  v26.p = v25->p;
                }
                while ( v25->i != 0 );
              }
            }
            for ( ; v23 != nullptr; v23 = v23->next )
            {
              if ( v23->next == nullptr )
                break;
              if ( (printall != 0 || !qh_skipfacet(facet: v23)) && v23->normal != nullptr )
              {
                if ( qh_qh.PRINTcentrums != 0 && qh_qh.PRINTdim <= 3 )
                  qh_printcentrum(fp: v5, facet: v23, radius: qh_qh.PRINTcradius);
                if ( qh_qh.PRINTcoplanar != 0 )
                {
                  coplanarset = v23->coplanarset;
                  if ( coplanarset != nullptr )
                  {
                    v28 = (long double **)coplanarset->e;
                    v29 = (long double *)coplanarset->e[0].p;
                    if ( v29 != nullptr )
                    {
                      do
                      {
                        ++v28;
                        qh_printpointvect2(
                          fp: v5,
                          point: v29,
                          normal: v23->normal,
                          center: nullptr,
                          radius: qh_qh.PRINTradius);
                        v29 = *v28;
                      }
                      while ( *v28 != nullptr );
                    }
                  }
                  outsideset = v23->outsideset;
                  if ( outsideset != nullptr )
                  {
                    v31 = (long double **)outsideset->e;
                    v32 = (long double *)outsideset->e[0].p;
                    if ( v32 != nullptr )
                    {
                      do
                      {
                        ++v31;
                        qh_printpointvect2(
                          fp: v5,
                          point: v32,
                          normal: v23->normal,
                          center: nullptr,
                          radius: qh_qh.PRINTradius);
                        v32 = *v31;
                      }
                      while ( *v31 != nullptr );
                    }
                  }
                }
              }
            }
            if ( facets != nullptr )
            {
              ptr = (facetT *)facets->e[0].p;
              v34 = facets->e;
              if ( ptr != nullptr )
              {
                do
                {
                  fp = (_iobuf *)&v34[1];
                  if ( (printall != 0 || !qh_skipfacet(facet: ptr)) && ptr->normal != nullptr )
                  {
                    if ( qh_qh.PRINTcentrums != 0 && qh_qh.PRINTdim <= 3 )
                      qh_printcentrum(fp: v5, facet: ptr, radius: qh_qh.PRINTcradius);
                    if ( qh_qh.PRINTcoplanar != 0 )
                    {
                      v35 = ptr->coplanarset;
                      if ( v35 != nullptr )
                      {
                        v36 = (long double **)v35->e;
                        v37 = (long double *)v35->e[0].p;
                        if ( v37 != nullptr )
                        {
                          do
                          {
                            ++v36;
                            qh_printpointvect2(
                              fp: v5,
                              point: v37,
                              normal: ptr->normal,
                              center: nullptr,
                              radius: qh_qh.PRINTradius);
                            v37 = *v36;
                          }
                          while ( *v36 != nullptr );
                        }
                      }
                      v38 = ptr->outsideset;
                      if ( v38 != nullptr )
                      {
                        v39 = (long double **)v38->e;
                        v40 = (long double *)v38->e[0].p;
                        if ( v40 != nullptr )
                        {
                          do
                          {
                            ++v39;
                            qh_printpointvect2(
                              fp: v5,
                              point: v40,
                              normal: ptr->normal,
                              center: nullptr,
                              radius: qh_qh.PRINTradius);
                            v40 = *v39;
                          }
                          while ( *v39 != nullptr );
                        }
                      }
                    }
                  }
                  v34 = (setelemT *)fp;
                  ptr = (facetT *)fp->_ptr;
                }
                while ( fp->_ptr != nullptr );
              }
            }
          }
          qh_settempfree(set: &vertices);
        }
        ++qh_qh.visit_id;
        break;
      case 9:
      case 11:
      case 12:
        if ( qh_qh.CDDoutput != 0 )
          fprintf(
            str: v5,
            format: "%s | %s\nbegin\n    %d %d real\n",
            qh_qh.rbox_command,
            qh_qh.qhull_command,
            fp,
            qh_qh.hull_dim + 1);
        else
          fprintf(str: v5, format: "%d\n%d\n", qh_qh.hull_dim + 1, fp);
        return;
      case 13:
        if ( qh_qh.VORONOI != 0 )
          ivp_message(templat: "qhull warning: writing Delaunay.  Use 'p' or 'o' for Voronoi centers\n");
        qh_qh.printoutvar = qh_qh.vertex_id;
        if ( qh_qh.hull_dim <= 3 )
$LN143:
          fprintf(str: v5, format: "%d\n", fp);
        else
          fprintf(str: v5, format: "%d\n", numridges + numsimplicial);
        return;
      case 14:
        if ( qh_qh.hull_dim > 3 )
          goto LABELnoformat;
        if ( qh_qh.VORONOI != 0 )
          ivp_message(templat: "qhull warning: output is the Delaunay triangulation\n");
        fprintf(str: v5, format: "{\n");
        qh_qh.printoutvar = 0;
        return;
      case 16:
      case 24:
        if ( qh_qh.VORONOI != 0 )
          goto LABELnoformat;
        v41 = qh_qh.hull_dim;
        if ( format == 16 || qh_qh.hull_dim == 2 )
        {
          radius_4 = totneighbors / 2;
          radius = fp;
          v48 = qh_qh.num_points + qh_setsize(set: qh_qh.other_points);
          fprintf(str: v5, format: "%d\n%d %d %d\n", v41, v48, radius, radius_4);
        }
        else
        {
          v42 = qh_qh.num_points + qh_setsize(set: qh_qh.other_points);
          qh_qh.printoutvar = v42;
          if ( qh_qh.DELAUNAY != 0 )
            --v41;
          fprintf(
            str: v5,
            format: "%d\n%d %d %d\n",
            v41,
            (char *)fp + v42 - numsimplicial,
            numsimplicial + numridges,
            totneighbors / 2);
        }
        v43 = qh_qh.first_point;
        v44 = &qh_qh.first_point[qh_qh.hull_dim * qh_qh.num_points];
        if ( qh_qh.first_point < v44 )
        {
          do
          {
            qh_printpointid(fp: qh_qh.fout, string: nullptr, dim: v41, point: v43, id: -1);
            v43 += qh_qh.hull_dim;
          }
          while ( v43 < v44 );
        }
        if ( qh_qh.other_points != nullptr )
        {
          v45 = (long double *)qh_qh.other_points->e[0].p;
          v46 = qh_qh.other_points->e;
          if ( v45 != nullptr )
          {
            do
            {
              ++v46;
              qh_printpointid(fp: qh_qh.fout, string: nullptr, dim: v41, point: v45, id: -1);
              v45 = (long double *)v46->i;
            }
            while ( v46->i != 0 );
          }
        }
        if ( format == 24 && qh_qh.hull_dim > 2 )
        {
          for ( j = qh_qh.facet_list; j != nullptr; j = j->next )
          {
            if ( j->next == nullptr )
              break;
            if ( (*((_DWORD *)j + 20) & 0x1000) == 0 && j->visitid != 0 )
              qh_printcenter(fp: qh_qh.fout, format: 24, string: nullptr, facet: j);
          }
        }
        return;
      case 18:
$LN140:
        fprintf(str: v5, format: "%d\n%d\n", qh_qh.hull_dim, fp);
        return;
      case 19:
        fprintf(str: v5, format: "%d\n", numcoplanars);
        return;
      case 20:
        if ( qh_qh.VORONOI == 0 )
          goto LABELnoformat;
        if ( qh_qh.CDDoutput != 0 )
          fprintf(
            str: v5,
            format: "%s | %s\nbegin\n%d %d real\n",
            qh_qh.rbox_command,
            qh_qh.qhull_command,
            fp,
            qh_qh.hull_dim);
        else
          fprintf(str: v5, format: "%d\n%d\n", qh_qh.hull_dim - 1, fp);
        return;
      default:
LABELnoformat:
        ivp_message(
          templat: "qhull internal error (qh_printbegin): can not use this format for dimension %d\n",
          qh_qh.hull_dim);
        qh_errexit(exitcode: 5, facet: nullptr, ridge: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10066F90
// Name: void qh_printfacet(struct _iobuf __near *,struct facetT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_printfacet(_iobuf *fp, facetT *facet)
{
  qh_printfacetheader(fp, facet);
  if ( facet->ridges != nullptr )
    qh_printfacetridges(fp, facet);
}

//------------------------------------------------------------------------------
// Address: 0x10066FC0
// Name: void qh_printafacet(struct _iobuf __near *,int,struct facetT __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_printafacet(_iobuf *fp, int format, facetT *facet, unsigned int printall)
{
  int v5; // eax
  setT *coplanarset; // esi
  long double *p; // eax
  long double **e; // esi
  int v9; // eax
  long double *normal; // ecx
  int hull_dim; // edi
  int v12; // eax
  int v13; // ecx
  long double v14; // xmm0_8
  double offset; // xmm0_8
  bool v16; // zf
  int v17; // edi
  int v18; // eax
  setT *neighbors; // esi
  setelemT v20; // eax
  setelemT *v21; // esi
  int v22; // ecx
  int v23; // eax
  char *v24; // eax
  long double *v25; // ecx
  double *v26; // edi
  int v27; // eax
  bool v28; // cc
  long double *feasible_point; // ecx
  double *v30; // edx
  void **v31; // esi
  double numer; // xmm0_8
  long double v33; // st7
  long double *v34; // eax
  int i; // esi
  setT *v36; // eax
  long double *v37; // edi
  vertexT *v38; // eax
  int v39; // eax
  int v40; // eax
  setT *vertices; // esi
  setelemT v42; // eax
  setelemT *v43; // esi
  int v44; // eax
  int v45; // [esp+14h] [ebp-60h]
  int v46; // [esp+18h] [ebp-5Ch]
  long double color[4]; // [esp+28h] [ebp-4Ch] BYREF
  long double dist; // [esp+48h] [ebp-2Ch] BYREF
  long double outerplane; // [esp+50h] [ebp-24h] BYREF
  long double innerplane; // [esp+58h] [ebp-1Ch] BYREF
  unsigned int zerodiv; // [esp+60h] [ebp-14h] BYREF
  double point; // [esp+64h] [ebp-10h]
  int k; // [esp+6Ch] [ebp-8h]
  long double *feasiblep; // [esp+70h] [ebp-4h]
  long double **pointp; // [esp+7Ch] [ebp+8h]
  long double **pointpa; // [esp+7Ch] [ebp+8h]

  if ( fp != nullptr
    && (printall != 0 || !qh_skipfacet(facet))
    && ((*((_DWORD *)facet + 20) & 0x400) == 0 || qh_qh.NEWfacets == 0 || format == 5) )
  {
    ++qh_qh.printoutnum;
    switch ( format )
    {
      case 1:
        if ( (*((_DWORD *)facet + 20) & 0x80000) != 0 )
        {
          fprintf(str: fp, format: "%6.16g ", (double)facet->f.area);
          fprintf(str: fp, format: "\n");
        }
        else
        {
          fprintf(str: fp, format: "0\n");
        }
        return;
      case 3:
        v5 = qh_setsize(set: facet->coplanarset);
        fprintf(str: fp, format: "%d", v5);
        coplanarset = facet->coplanarset;
        if ( coplanarset != nullptr )
        {
          p = (long double *)coplanarset->e[0].p;
          e = (long double **)coplanarset->e;
          if ( p != nullptr )
          {
            do
            {
              ++e;
              v9 = qh_pointid(point: p);
              fprintf(str: fp, format: " %d", v9);
              p = *e;
            }
            while ( *e != nullptr );
          }
        }
        goto LABEL_94;
      case 4:
        goto $LN5_7;
      case 5:
        qh_printfacet(fp, facet);
        return;
      case 6:
        qh_printfacetheader(fp, facet);
        return;
      case 7:
        normal = facet->normal;
        if ( normal != nullptr )
        {
          hull_dim = qh_qh.hull_dim;
          v12 = qh_qh.hull_dim;
          if ( qh_qh.hull_dim != 0 )
          {
            v13 = (char *)normal - (char *)color;
            do
            {
              v14 = (*(long double *)((char *)&color[--v12] + v13) + 1.0) * 0.5;
              color[v12] = v14;
              if ( v14 < -1.0 )
                color[v12] = -1.0;
              if ( color[v12] > 1.0 )
                color[v12] = 1.0;
            }
            while ( v12 != 0 );
          }
          qh_projectdim3(source: color, destination: color);
          if ( qh_qh.PRINTdim != hull_dim )
          {
            qh_normalize2(normal: color, dim: 3, toporient: 1u, minnorm: nullptr, ismin: nullptr);
            hull_dim = qh_qh.hull_dim;
          }
          if ( hull_dim > 2 )
          {
            if ( hull_dim == 3 )
            {
              if ( (*((_DWORD *)facet + 20) & 0x1000) != 0 )
                qh_printfacet3geom_simplicial(fp, facet, color);
              else
                qh_printfacet3geom_nonsimplicial(fp, facet, color);
            }
            else if ( (*((_DWORD *)facet + 20) & 0x1000) != 0 )
            {
              qh_printfacet4geom_simplicial((vertexT **)fp, facet, color);
            }
            else
            {
              qh_printfacet4geom_nonsimplicial((vertexT **)fp, facet, color);
            }
          }
          else
          {
            qh_printfacet2geom(fp, facet, color);
          }
        }
        return;
      case 8:
        fprintf(str: fp, format: "%d\n", facet->id);
        return;
      case 9:
        qh_outerinner(facet, outerplane: nullptr, &innerplane);
        offset = facet->offset - innerplane;
        goto LABEL_49;
      case 10:
        v18 = qh_setsize(set: facet->neighbors);
        fprintf(str: fp, format: "%d", v18);
        neighbors = facet->neighbors;
        if ( neighbors != nullptr )
        {
          v20.p = (void *)neighbors->e[0];
          v21 = neighbors->e;
          if ( v20.i != 0 )
          {
            do
            {
              v22 = *(_DWORD *)(v20.i + 72);
              ++v21;
              if ( v22 != 0 )
                v23 = v22 - 1;
              else
                v23 = -*(_DWORD *)(v20.i + 76);
              fprintf(str: fp, format: " %d", v23);
              v20.p = v21->p;
            }
            while ( v21->i != 0 );
          }
        }
        goto LABEL_94;
      case 11:
        offset = facet->offset;
        goto LABEL_49;
      case 12:
        qh_outerinner(facet, &outerplane, innerplane: nullptr);
        offset = facet->offset - outerplane;
LABEL_49:
        v16 = facet->normal == nullptr;
        point = offset;
        if ( v16 )
        {
          fprintf(str: fp, format: "no normal for facet f%d\n", facet->id);
          return;
        }
        if ( qh_qh.CDDoutput != 0 )
        {
          fprintf(str: fp, format: "%6.16g ", -offset);
          offset = point;
        }
        v17 = 0;
        if ( qh_qh.hull_dim > 0 )
        {
          do
            fprintf(str: fp, format: "%6.16g ", (double)facet->normal[v17++]);
          while ( v17 < qh_qh.hull_dim );
          offset = point;
        }
        if ( qh_qh.CDDoutput == 0 )
          fprintf(str: fp, format: "%6.16g ", offset);
        goto LABEL_94;
      case 13:
      case 16:
      case 24:
        if ( qh_qh.hull_dim != 3 || format == 24 )
        {
          if ( (*((_DWORD *)facet + 20) & 0x1000) != 0 || qh_qh.hull_dim == 2 || format == 16 )
          {
            qh_printfacetNvertex_simplicial(fp, facet, format);
          }
          else
          {
            v45 = qh_qh.printoutvar++;
            qh_printfacetNvertex_nonsimplicial((ridgeT **)fp, facet, id: v45, format);
          }
        }
        else
        {
          qh_printfacet3vertex((setT *)fp, facet, format);
        }
        return;
      case 14:
        v46 = qh_qh.printoutvar++;
        if ( qh_qh.hull_dim == 2 )
          qh_printfacet2math(fp, facet, notfirst: v46);
        else
          qh_printfacet3math(fp, facet, notfirst: v46);
        return;
      case 15:
        fprintf(str: fp, format: "%d\n", *((_DWORD *)facet + 20) & 0x1FF);
        return;
      case 18:
        if ( qh_qh.feasible_point == nullptr )
        {
          fprintf(str: fp, format: "qhull input error (qh_printafacet): option 'Fp' needs qh feasible_point\n");
          qh_errexit(exitcode: 1, facet: nullptr, ridge: nullptr);
        }
        if ( facet->offset > 0.0 )
          goto LABELprintinfinite;
        v24 = qh_memalloc(insize: qh_qh.normal_size);
        v25 = facet->normal;
        v26 = (double *)v24;
        v27 = qh_qh.hull_dim;
        v28 = -qh_qh.MINdenom <= facet->offset;
        HIDWORD(point) = v26;
        pointp = (long double **)v25;
        feasiblep = qh_qh.feasible_point;
        if ( !v28 )
        {
          if ( qh_qh.hull_dim != 0 )
          {
            feasible_point = qh_qh.feasible_point;
            v30 = (double *)pointp;
            do
            {
              *v26++ = -1.0 / facet->offset * *v30++ + *feasible_point++;
              --v27;
            }
            while ( v27 != 0 );
          }
          goto LABEL_75;
        }
        k = qh_qh.hull_dim;
        if ( qh_qh.hull_dim == 0 )
        {
LABEL_75:
          v31 = (void **)HIDWORD(point);
          qh_printpoint(fp, string: nullptr, point: (long double *)HIDWORD(point));
          qh_memfree(object: v31, size: qh_qh.normal_size);
          return;
        }
        while ( 1 )
        {
          numer = *(double *)pointp;
          --k;
          v33 = qh_divzero(numer, denom: facet->offset, mindenom1: qh_qh.MINdenom_1, &zerodiv);
          pointp += 2;
          v34 = feasiblep + 1;
          *v26++ = v33 + *feasiblep;
          feasiblep = v34;
          if ( zerodiv != 0 )
            break;
          if ( k == 0 )
            goto LABEL_75;
        }
        qh_memfree(object: (void **)HIDWORD(point), size: qh_qh.normal_size);
LABELprintinfinite:
        for ( i = qh_qh.hull_dim; i != 0; --i )
          fprintf(str: fp, format: "%6.16g ", -10.101);
LABEL_94:
        fprintf(str: fp, format: "\n");
        break;
      case 19:
        v36 = facet->coplanarset;
        if ( v36 != nullptr )
        {
          v37 = (long double *)v36->e[0].p;
          pointpa = (long double **)v36->e;
          if ( v37 != nullptr )
          {
            do
            {
              ++pointpa;
              v38 = qh_nearvertex(facet, point: v37, bestdistp: &dist);
              HIDWORD(point) = qh_pointid(point: v38->point);
              v39 = qh_pointid(point: v37);
              fprintf(str: fp, format: "%d %d %d %6.16g \n", HIDWORD(point), v39, facet->id, (double)dist);
              v37 = *pointpa;
            }
            while ( *pointpa != nullptr );
          }
        }
        return;
      case 20:
        if ( qh_qh.CDDoutput != 0 )
          fprintf(str: fp, format: "1 ");
$LN5_7:
        qh_printcenter(fp, format, string: nullptr, facet);
        return;
      case 25:
        v40 = qh_setsize(set: facet->vertices);
        fprintf(str: fp, format: "%d", v40);
        vertices = facet->vertices;
        if ( vertices != nullptr )
        {
          v42.p = (void *)vertices->e[0];
          v43 = vertices->e;
          if ( v42.i != 0 )
          {
            do
            {
              ++v43;
              v44 = qh_pointid(point: *(long double **)(v42.i + 8));
              fprintf(str: fp, format: " %d", v44);
              v42.p = v43->p;
            }
            while ( v43->i != 0 );
          }
        }
        goto LABEL_94;
      default:
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10067710
// Name: void qh_printfacets(struct _iobuf __near *,int,struct facetT __near *,struct setT __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_printfacets(setT *fp, int format, facetT *facetlist, setT *facets, unsigned int printall)
{
  _iobuf *v5; // esi
  int v6; // edi
  long double *v7; // edi
  unsigned int v8; // edi
  setT *v9; // ebx
  _iobuf *v10; // eax
  int v11; // eax
  unsigned int v12; // edi
  setT *v13; // ebx
  facetT *v14; // ebx
  facetT *p; // eax
  setelemT *e; // ebx
  int num_vertices; // [esp-4h] [ebp-44h]
  int v18; // [esp+0h] [ebp-40h]
  int v19; // [esp+4h] [ebp-3Ch]
  unsigned __int64 v20; // [esp+8h] [ebp-38h]
  long double outerplane; // [esp+1Ch] [ebp-24h] BYREF
  long double innerplane; // [esp+24h] [ebp-1Ch] BYREF
  int numsimplicial; // [esp+2Ch] [ebp-14h] BYREF
  int totneighbors; // [esp+30h] [ebp-10h] BYREF
  int numridges; // [esp+34h] [ebp-Ch] BYREF
  int numfacets; // [esp+38h] [ebp-8h] BYREF
  int numcoplanars; // [esp+3Ch] [ebp-4h] BYREF

  v5 = (_iobuf *)fp;
  if ( fp == nullptr )
    return;
  v6 = format;
  qh_qh.old_randomdist = qh_qh.RANDOMdist;
  qh_qh.RANDOMdist = 0;
  if ( qh_qh.CDDoutput != 0 && (format == 4 || format == 18 || format == 16) )
    ivp_message(templat: "qhull warning: CDD format is not available for centrums, halfspace\nintersections, and OFF file format.\n");
  if ( v6 == 0 )
    goto LABEL_46;
  if ( v6 == 2 )
  {
    fp = (setT *)qh_facetvertices((setT *)facetlist, facets, allfacets: printall);
    v7 = qh_getcenter(vertices: fp);
    fprintf(str: v5, format: "%d 1\n", qh_qh.hull_dim);
    qh_printpointid(fp: v5, string: nullptr, dim: qh_qh.hull_dim, point: v7, id: -1);
    qh_memfree(object: (void **)v7, size: qh_qh.normal_size);
    qh_settempfree(set: &fp);
    qh_qh.RANDOMdist = qh_qh.old_randomdist;
    return;
  }
  if ( v6 != 27 )
  {
    switch ( v6 )
    {
      case 17:
        fprintf(str: v5, format: "Options selected for qhull %s:\n%s\n", qh_version, qh_qh.qhull_options);
        qh_qh.RANDOMdist = qh_qh.old_randomdist;
        return;
      case 20:
        if ( qh_qh.VORONOI == 0 )
        {
          qh_printpoints_out(fp: v5, facetlist, facets, printall);
          qh_qh.RANDOMdist = qh_qh.old_randomdist;
          return;
        }
LABEL_39:
        v14 = facetlist;
        qh_printbegin(fp: v5, format: v6, facetlist, facets, printall);
        for ( ; v14 != nullptr; v14 = v14->next )
        {
          if ( v14->next == nullptr )
            break;
          qh_printafacet(fp: v5, format: v6, facet: v14, printall);
        }
        if ( facets != nullptr )
        {
          p = (facetT *)facets->e[0].p;
          e = facets->e;
          if ( p != nullptr )
          {
            do
            {
              ++e;
              qh_printafacet(fp: v5, format: v6, facet: p, printall);
              p = (facetT *)e->i;
            }
            while ( e->i != 0 );
          }
        }
        qh_printend(fp: v5, format: v6, facetlist, facets, printall);
        goto LABEL_46;
      case 21:
        fprintf(str: v5, format: "%s | %s\n", qh_qh.rbox_command, qh_qh.qhull_command);
        qh_qh.RANDOMdist = qh_qh.old_randomdist;
        return;
      case 22:
        fprintf(str: v5, format: "0\n2 ");
        fprintf(str: v5, format: "%6.16g ", (double)qh_qh.totarea);
        fprintf(str: v5, format: "%6.16g ", (double)qh_qh.totvol);
        fprintf(str: v5, format: "\n");
        qh_qh.RANDOMdist = qh_qh.old_randomdist;
        return;
      case 23:
        v8 = printall;
        v9 = facets;
        qh_countfacets(
          facetlist,
          facets,
          printall,
          numfacetsp: &numfacets,
          numsimplicialp: &numsimplicial,
          totneighborsp: &totneighbors,
          numridgesp: &numridges,
          numcoplanarsp: &numcoplanars);
        v10 = (_iobuf *)qh_facetvertices((setT *)facetlist, facets: v9, allfacets: v8);
        v20 = __PAIR64__(numcoplanars, numfacets);
        fp = (setT *)v10;
        v19 = qh_setsize(set: (setT *)v10);
        v18 = qh_qh.num_facets - qh_qh.num_visible;
        num_vertices = qh_qh.num_vertices;
        v11 = qh_setsize(set: qh_qh.other_points);
        fprintf(
          str: v5,
          format: "7 %d %d %d %d %d %d %d\n2 ",
          qh_qh.hull_dim,
          qh_qh.num_points + v11,
          num_vertices,
          v18,
          v19,
          (_DWORD)v20,
          HIDWORD(v20));
        qh_settempfree(set: &fp);
        qh_outerinner(facet: nullptr, &outerplane, &innerplane);
        fprintf(str: v5, format: "%6.16g %6.16g\n", (double)outerplane, (double)innerplane);
        qh_qh.RANDOMdist = qh_qh.old_randomdist;
        return;
      case 26:
        qh_printvneighbors(fp: v5, facetlist, facets, printall);
        qh_qh.RANDOMdist = qh_qh.old_randomdist;
        return;
      default:
        break;
    }
    if ( qh_qh.VORONOI == 0 )
      goto LABEL_39;
    switch ( v6 )
    {
      case 16:
        qh_printvoronoi(fp: v5, format: 16, facetlist, facets, printall);
        break;
      case 7:
        v12 = printall;
        v13 = facets;
        qh_printbegin(fp: v5, format: 7, facetlist, facets, printall);
        qh_printvoronoi(fp: v5, format: 7, facetlist, facets: v13, printall: v12);
        qh_printend(fp: v5, format: 7, facetlist, facets: v13, printall: v12);
        qh_qh.RANDOMdist = qh_qh.old_randomdist;
        return;
      case 25:
      case 9:
      case 12:
        qh_printvdiagram(fp: (setT *)v5, format: v6, facetlist, facets, printall);
        break;
      default:
        goto LABEL_39;
    }
LABEL_46:
    qh_qh.RANDOMdist = qh_qh.old_randomdist;
    return;
  }
  if ( qh_qh.DELAUNAY != 0 )
  {
    qh_printextremes_d(fp: v5, facetlist, facets, printall);
    qh_qh.RANDOMdist = qh_qh.old_randomdist;
  }
  else
  {
    if ( qh_qh.hull_dim == 2 )
      qh_printextremes_2d(fp: v5, facetlist, facets, printall);
    else
      qh_printextremes(fp: v5, facetlist, facets, printall);
    qh_qh.RANDOMdist = qh_qh.old_randomdist;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10067B80
// Name: void qh_printneighborhood(struct _iobuf __near *,int,struct facetT __near *,struct facetT __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_printneighborhood(_iobuf *fp, int format, facetT *facetA, facetT *facetB, unsigned int printall)
{
  facetT *v5; // ebx
  int v6; // eax
  unsigned int visit_id; // eax
  setT *neighbors; // ecx
  facetT *p; // esi
  facetT **e; // edi
  setT *facets; // [esp+0h] [ebp-4h] BYREF

  if ( format != 0 )
  {
    qh_findgood_all(facetlist: qh_qh.facet_list);
    v5 = facetA;
    if ( facetA == facetB )
      facetB = nullptr;
    v6 = qh_setsize(set: facetA->neighbors);
    facets = qh_settemp(setsize: 2 * v6 + 2);
    visit_id = ++qh_qh.visit_id;
    do
    {
      if ( v5->visitid != visit_id )
      {
        v5->visitid = visit_id;
        qh_setappend(setp: &facets, newelem: v5);
        visit_id = qh_qh.visit_id;
      }
      neighbors = v5->neighbors;
      if ( neighbors != nullptr )
      {
        p = (facetT *)neighbors->e[0].p;
        e = (facetT **)neighbors->e;
        if ( p != nullptr )
        {
          do
          {
            ++e;
            if ( p->visitid != visit_id )
            {
              p->visitid = visit_id;
              if ( printall != 0 || !qh_skipfacet(facet: p) )
                qh_setappend(setp: &facets, newelem: p);
              visit_id = qh_qh.visit_id;
            }
            p = *e;
          }
          while ( *e != nullptr );
        }
      }
      v5 = v5 != facetA ? nullptr : facetB;
    }
    while ( v5 != nullptr );
    qh_printfacets((setT *)fp, format, facetlist: nullptr, facets, printall);
    qh_settempfree(set: &facets);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10067C70
// Name: void qh_produce_output(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_produce_output()
{
  int v0; // edi
  int *PRINTout; // esi
  int v2; // eax

  v0 = qh_setsize(set: (setT *)qhmem.tempstack);
  if ( qh_qh.VORONOI != 0 )
  {
    qh_clearcenters(type: qh_ASvoronoi);
    qh_vertexneighbors();
  }
  if ( qh_qh.GETarea != 0 )
    qh_getarea(facetlist: qh_qh.facet_list);
  qh_findgood_all(facetlist: qh_qh.facet_list);
  if ( qh_qh.KEEParea != 0 || qh_qh.KEEPmerge != 0 || qh_qh.KEEPminArea < 8.988465674311579e307 )
    qh_markkeep(facetlist: qh_qh.facet_list);
  if ( qh_qh.PRINTsummary != 0 )
  {
    qh_printsummary(fp: qh_qh.ferr);
  }
  else if ( qh_qh.PRINTout[0] == qh_PRINTnone )
  {
    qh_printsummary(fp: qh_qh.fout);
  }
  PRINTout = (int *)qh_qh.PRINTout;
  do
    qh_printfacets(
      fp: (setT *)qh_qh.fout,
      format: *PRINTout++,
      facetlist: qh_qh.facet_list,
      facets: nullptr,
      printall: 0);
  while ( (int)PRINTout < (int)&qh_qh.PRINTridges );
  qh_allstatistics();
  if ( qh_qh.PRINTprecision != 0 && qh_qh.MERGING == 0 && (qh_qh.JOGGLEmax > 8.988465674311579e307 || qh_qh.RERUN != 0) )
    qh_printstats(fp: qh_qh.ferr, index: qh_qhstat.precision, nextindex: nullptr);
  if ( qh_qh.VERIFYoutput != 0 && (qh_qhstat.stats[159].i > 0 || qh_qhstat.stats[165].i > 0) )
    qh_printstats(fp: qh_qh.ferr, index: qh_qhstat.vridges, nextindex: nullptr);
  if ( qh_qh.PRINTstatistics != 0 )
  {
    qh_collectstatistics();
    qh_printstatistics(fp: qh_qh.ferr, string: str);
    qh_memstatistics(fp: qh_qh.ferr);
    ivp_message(
      templat: "    size in bytes: hashentry %d merge %d ridge %d vertex %d facet %d\n"
      "         normal %d ridge vertices %d facet vertices or neighbors %d\n",
      12,
      24,
      16,
      24,
      88,
      qh_qh.normal_size,
      4 * qh_qh.hull_dim + 4,
      4 * qh_qh.hull_dim + 8);
  }
  if ( qh_setsize(set: (setT *)qhmem.tempstack) != v0 )
  {
    v2 = qh_setsize(set: (setT *)qhmem.tempstack);
    ivp_message(templat: "qhull internal error (qh_produce_output): temporary sets not empty (%d)\n", v2);
    qh_errexit(exitcode: 5, facet: nullptr, ridge: nullptr);
  }
}
