// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_compact_builder/qhull_global.cxx
// Functions: 15
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x100528F0
// Name: bool V_isspace(int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl V_isspace(int c)
{
  return c >= 9 && (c <= 13 || c == 32);
}

//------------------------------------------------------------------------------
// Address: 0x10052910
// Name: void qh_appendprint(enum qh_PRINT)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_appendprint(qh_PRINT format)
{
  int i; // eax
  qh_PRINT v2; // ecx

  for ( i = 0; i < 28; ++i )
  {
    v2 = qh_qh.PRINTout[i];
    if ( v2 == format )
      break;
    if ( v2 == qh_PRINTnone )
    {
      qh_qh.PRINTout[i] = format;
      return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10052940
// Name: void qh_freebuffers(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_freebuffers()
{
  if ( qh_qh.IStracing >= 5 )
    fprintf(str: qh_qh.ferr, format: "qh_freebuffers: freeing up global memory buffers\n");
  qh_memfree(object: qh_qh.NEARzero, size: 8 * qh_qh.hull_dim);
  qh_memfree(object: qh_qh.lower_threshold, size: 8 * qh_qh.input_dim + 8);
  qh_memfree(object: qh_qh.upper_threshold, size: 8 * qh_qh.input_dim + 8);
  qh_memfree(object: qh_qh.lower_bound, size: 8 * qh_qh.input_dim + 8);
  qh_memfree(object: qh_qh.upper_bound, size: 8 * qh_qh.input_dim + 8);
  qh_memfree(object: qh_qh.gm_matrix, size: 8 * qh_qh.hull_dim * (qh_qh.hull_dim + 1));
  qh_memfree(object: qh_qh.gm_row, size: 4 * qh_qh.hull_dim + 4);
  qh_qh.upper_threshold = nullptr;
  qh_qh.lower_threshold = nullptr;
  qh_qh.NEARzero = nullptr;
  qh_qh.upper_bound = nullptr;
  qh_qh.lower_bound = nullptr;
  qh_qh.gm_matrix = nullptr;
  qh_qh.gm_row = nullptr;
  qh_setfree(setp: &qh_qh.other_points);
  qh_setfree(setp: &qh_qh.del_vertices);
  qh_setfree(setp: &qh_qh.searchset);
  if ( qh_qh.line != nullptr )
  {
    free(data: qh_qh.line);
    qh_qh.line = nullptr;
  }
  if ( qh_qh.half_space != nullptr )
  {
    free(data: qh_qh.half_space);
    qh_qh.half_space = nullptr;
  }
  if ( qh_qh.temp_malloc != nullptr )
  {
    free(data: qh_qh.temp_malloc);
    qh_qh.temp_malloc = nullptr;
  }
  if ( qh_qh.feasible_point != nullptr )
  {
    free(data: qh_qh.feasible_point);
    qh_qh.feasible_point = nullptr;
  }
  if ( qh_qh.feasible_string != nullptr )
    free(data: qh_qh.feasible_string);
  qh_qh.feasible_string = nullptr;
  qh_qh.line = nullptr;
  qh_qh.temp_malloc = nullptr;
  qh_qh.feasible_point = nullptr;
  qh_qh.half_space = nullptr;
  if ( qh_qh.first_point != nullptr && qh_qh.POINTSmalloc != 0 )
  {
    free(data: qh_qh.first_point);
    qh_qh.first_point = nullptr;
  }
  if ( qh_qh.input_points != nullptr && qh_qh.input_malloc != 0 )
  {
    free(data: qh_qh.input_points);
    qh_qh.input_points = nullptr;
  }
  if ( qh_qh.IStracing >= 5 )
    fprintf(str: qh_qh.ferr, format: "qh_freebuffers: finished\n");
}

//------------------------------------------------------------------------------
// Address: 0x10052B50
// Name: void qh_freebuild(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_freebuild(unsigned int allmem)
{
  vertexT *i; // eax
  vertexT *j; // esi
  facetT *k; // edx
  setT *ridges; // ecx
  setelemT v5; // eax
  setelemT *m; // ecx
  facetT *n; // esi
  setT *v8; // eax
  setelemT *e; // edx
  _DWORD *p; // eax
  int v11; // ecx
  facetT *ii; // ebx
  setT *v13; // eax
  setelemT v14; // esi
  setelemT *v15; // edi
  int v16; // eax
  facetT *jj; // esi
  setT *v18; // ecx
  setelemT *v19; // esi
  void *v20; // eax

  if ( qh_qh.IStracing >= 1 )
    fprintf(str: qh_qh.ferr, format: "qh_freebuild: free memory from qh_inithull and qh_buildhull\n");
  if ( qh_qh.del_vertices != nullptr )
    qh_settruncate(set: qh_qh.del_vertices, size: 0);
  if ( allmem != 0 )
  {
    qh_clearcenters(type: qh_ASnone);
    for ( i = qh_qh.vertex_list; qh_qh.vertex_list != nullptr; i = qh_qh.vertex_list )
    {
      if ( i->next != nullptr )
      {
        qh_delvertex(vertex: i);
      }
      else
      {
        qh_memfree(object: i, size: 24);
        qh_qh.vertex_list = nullptr;
        qh_qh.newvertex_list = nullptr;
      }
    }
  }
  else if ( qh_qh.VERTEXneighbors != 0 )
  {
    for ( j = qh_qh.vertex_list; j != nullptr; j = j->next )
    {
      if ( j->next == nullptr )
        break;
      qh_setfreelong(setp: &j->neighbors);
    }
  }
  qh_qh.VERTEXneighbors = 0;
  qh_qh.GOODclosest = nullptr;
  if ( allmem != 0 )
  {
    for ( k = qh_qh.facet_list; k != nullptr; k = k->next )
    {
      if ( k->next == nullptr )
        break;
      ridges = k->ridges;
      if ( ridges != nullptr )
      {
        v5.p = (void *)ridges->e[0];
        for ( m = ridges->e; v5.i != 0; ++m )
        {
          *(_DWORD *)(v5.i + 12) &= ~0x1000000u;
          v5.p = m[1].p;
        }
      }
    }
    for ( n = qh_qh.facet_list; n != nullptr; n = n->next )
    {
      if ( n->next == nullptr )
        break;
      if ( (*((_DWORD *)n + 20) & 0x400) != 0 )
      {
        v8 = n->ridges;
        if ( v8 != nullptr )
        {
          e = v8->e;
          p = v8->e[0].p;
          if ( p != nullptr )
          {
            do
            {
              v11 = p[1];
              ++e;
              if ( (facetT *)v11 == n )
                v11 = p[2];
              if ( (*(_DWORD *)(v11 + 80) & 0x400) == 0 )
                p[3] |= 0x1000000u;
              p = (_DWORD *)e->i;
            }
            while ( e->i != 0 );
          }
        }
      }
    }
    for ( ii = qh_qh.facet_list; qh_qh.facet_list != nullptr; ii = qh_qh.facet_list )
    {
      v13 = ii->ridges;
      if ( v13 != nullptr )
      {
        v14.p = (void *)v13->e[0];
        v15 = v13->e;
        if ( v14.i != 0 )
        {
          do
          {
            v16 = *(_DWORD *)(v14.i + 12);
            ++v15;
            if ( (v16 & 0x1000000) != 0 )
            {
              qh_setfree(setp: (setT **)v14.p);
              qh_memfree(object: v14.p, size: 16);
            }
            else
            {
              *(_DWORD *)(v14.i + 12) = v16 | 0x1000000;
            }
            v14.p = v15->p;
          }
          while ( v15->i != 0 );
        }
      }
      qh_setfree(setp: &ii->outsideset);
      qh_setfree(setp: &ii->coplanarset);
      qh_setfree(setp: &ii->neighbors);
      qh_setfree(setp: &ii->ridges);
      qh_setfree(setp: &ii->vertices);
      if ( ii->next != nullptr )
      {
        qh_delfacet(facet: ii);
      }
      else
      {
        qh_memfree(object: ii, size: 88);
        qh_qh.facet_list = nullptr;
        qh_qh.newfacet_list = nullptr;
        qh_qh.visible_list = nullptr;
      }
    }
  }
  else
  {
    for ( jj = qh_qh.facet_list; jj != nullptr; jj = jj->next )
    {
      if ( jj->next == nullptr )
        break;
      qh_setfreelong(setp: &jj->outsideset);
      qh_setfreelong(setp: &jj->coplanarset);
      if ( (*((_DWORD *)jj + 20) & 0x1000) == 0 )
      {
        qh_setfreelong(setp: &jj->neighbors);
        qh_setfreelong(setp: &jj->ridges);
        qh_setfreelong(setp: &jj->vertices);
      }
    }
  }
  qh_setfree(setp: &qh_qh.hash_table);
  qh_memfree(object: qh_qh.interior_point, size: qh_qh.normal_size);
  qh_qh.interior_point = nullptr;
  if ( qh_qh.facet_mergeset != nullptr )
  {
    v19 = qh_qh.facet_mergeset->e;
    v20 = qh_qh.facet_mergeset->e[0].p;
    if ( v20 != nullptr )
    {
      do
      {
        ++v19;
        qh_memfree(object: v20, size: 24);
        v20 = (void *)v19->i;
      }
      while ( v19->i != 0 );
    }
  }
  qh_qh.facet_mergeset = nullptr;
  qh_qh.degen_mergeset = nullptr;
  qh_settempfree_all(this: v18);
}

//------------------------------------------------------------------------------
// Address: 0x10052E20
// Name: void qh_freeqhull(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_freeqhull(unsigned int allmem)
{
  CDataManagerBase *v1; // ecx

  if ( qh_qh.IStracing >= 1 )
    fprintf(str: qh_qh.ferr, format: "qh_freeqhull: free global memory\n");
  qh_qh.NOerrexit = 1;
  qh_freebuild(allmem);
  qh_freebuffers();
  CEmptyCollisionListener::PostSimulationFrame(this: v1);
  memset(dst: (unsigned __int8 *)&qh_qh, value: 0, count: sizeof(qh_qh));
  qh_qh.NOerrexit = 1;
}

//------------------------------------------------------------------------------
// Address: 0x10052E80
// Name: void qh_initqhull_buffers(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_initqhull_buffers()
{
  signed int v0; // eax
  int v1; // eax

  v0 = (unsigned int)(qhmem.LASTsize - 8) >> 2;
  qh_qh.TEMPsize = v0;
  if ( v0 == 0 || v0 > qhmem.LASTsize )
  {
    v0 = 8;
    qh_qh.TEMPsize = 8;
  }
  qh_qh.other_points = qh_setnew(setsize: v0);
  qh_qh.del_vertices = qh_setnew(setsize: qh_qh.TEMPsize);
  qh_qh.searchset = qh_setnew(setsize: qh_qh.TEMPsize);
  qh_qh.NEARzero = (long double *)qh_memalloc(insize: 8 * qh_qh.hull_dim);
  qh_qh.lower_threshold = (long double *)qh_memalloc(insize: 8 * qh_qh.input_dim + 8);
  qh_qh.upper_threshold = (long double *)qh_memalloc(insize: 8 * qh_qh.input_dim + 8);
  qh_qh.lower_bound = (long double *)qh_memalloc(insize: 8 * qh_qh.input_dim + 8);
  qh_qh.upper_bound = (long double *)qh_memalloc(insize: 8 * qh_qh.input_dim + 8);
  v1 = qh_qh.input_dim + 1;
  if ( qh_qh.input_dim != -1 )
  {
    do
    {
      qh_qh.lower_threshold[--v1] = -1.797693134862316e308;
      qh_qh.upper_threshold[v1] = 1.797693134862316e308;
      qh_qh.lower_bound[v1] = -1.797693134862316e308;
      qh_qh.upper_bound[v1] = 1.797693134862316e308;
    }
    while ( v1 != 0 );
  }
  qh_qh.gm_matrix = (long double *)qh_memalloc(insize: 8 * qh_qh.hull_dim * (qh_qh.hull_dim + 1));
  qh_qh.gm_row = (long double **)qh_memalloc(insize: 4 * qh_qh.hull_dim + 4);
}

//------------------------------------------------------------------------------
// Address: 0x10052FD0
// Name: void qh_initqhull_mem(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_initqhull_mem()
{
  int v0; // esi
  CDataManagerBase *v1; // ecx

  qh_meminitbuffers(tracelevel: qh_qh.IStracing, alignment: 8, numsizes: 18, bufsize: 0x10000, bufinit: 0x20000);
  qh_memsize(size: 24);
  if ( qh_qh.MERGING != 0 )
  {
    qh_memsize(size: 16);
    qh_memsize(size: 24);
  }
  qh_memsize(size: 88);
  qh_memsize(size: 12);
  v0 = 4 * qh_qh.hull_dim + 4;
  qh_memsize(size: v0);
  qh_memsize(size: qh_qh.normal_size);
  qh_memsize(size: v0 + 4);
  CEmptyCollisionListener::PostSimulationFrame(this: v1);
  qh_memsetup();
}

//------------------------------------------------------------------------------
// Address: 0x10053060
// Name: void qh_initqhull_start(struct _iobuf __near *,struct _iobuf __near *,struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_initqhull_start(_iobuf *infile, _iobuf *outfile, _iobuf *errfile)
{
  memset(dst: (unsigned __int8 *)&qh_qh, value: 0, count: sizeof(qh_qh));
  strcat(qh_qh.qhull, "qhull");
  qh_initstatistics();
  qh_qh.ferr = errfile;
  qh_qh.ANGLEmerge = 1;
  qh_qh.DROPdim = -1;
  qh_qh.fin = infile;
  qh_qh.fout = outfile;
  qh_qh.furthest_id = -1;
  qh_qh.JOGGLEmax = 1.797693134862316e308;
  qh_qh.KEEPminArea = 1.797693134862316e308;
  qh_qh.last_low = 1.797693134862316e308;
  qh_qh.last_high = 1.797693134862316e308;
  qh_qh.last_newhigh = 1.797693134862316e308;
  qh_qh.max_outside = 0.0;
  qh_qh.max_vertex = 0.0;
  qh_qh.MAXabs_coord = 0.0;
  qh_qh.MAXsumcoord = 0.0;
  qh_qh.MAXwidth = -1.797693134862316e308;
  qh_qh.MERGEindependent = 1;
  qh_qh.MINdenom_1 = 0.0;
  qh_qh.MINoutside = 0.0;
  qh_qh.MINvisible = 1.797693134862316e308;
  qh_qh.MAXcoplanar = 1.797693134862316e308;
  qh_qh.outside_err = 1.797693134862316e308;
  qh_qh.premerge_centrum = 0.0;
  qh_qh.premerge_cos = 1.797693134862316e308;
  qh_qh.PRINTprecision = 1;
  qh_qh.PRINTradius = 0.0;
  qh_qh.postmerge_cos = 1.797693134862316e308;
  qh_qh.postmerge_centrum = 0.0;
  qh_qh.ROTATErandom = 0x80000000;
  qh_qh.MERGEvertices = 1;
  qh_qh.totarea = 0.0;
  qh_qh.totvol = 0.0;
  qh_qh.TRACEdist = 1.797693134862316e308;
  qh_qh.TRACEpoint = -1;
  qh_qh.tracefacet_id = -1;
  qh_qh.tracevertex_id = -1;
  qh_srand(seed: 1);
}

//------------------------------------------------------------------------------
// Address: 0x100531E0
// Name: void qh_option(char const __near *,int __near *,double __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_option(const char *option, int *i, long double *r)
{
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // esi
  double v7; // [esp+0h] [ebp-D0h]
  int v8; // [esp+4h] [ebp-CCh]
  char buf[200]; // [esp+8h] [ebp-C8h] BYREF

  sprintf(string: buf, format: "  %s", option);
  if ( i != nullptr )
  {
    v8 = *i;
    v3 = p_strlen(s: buf);
    sprintf(string: &buf[v3], format: " %d", v8);
  }
  if ( r != nullptr )
  {
    v7 = *r;
    v4 = p_strlen(s: buf);
    sprintf(string: &buf[v4], format: " %2.2g", v7);
  }
  v5 = p_strlen(s: buf);
  qh_qh.qhull_optionlen += v5;
  v6 = 511 - v5;
  if ( 511 - v5 < 0 )
    v6 = 0;
  if ( qh_qh.qhull_optionlen >= 80 && v6 > 0 )
  {
    qh_qh.qhull_optionlen = v5;
    strncat(Destination: qh_qh.qhull_options, Source: "\n", Count: v6--);
  }
  strncat(Destination: qh_qh.qhull_options, Source: buf, Count: v6);
}

//------------------------------------------------------------------------------
// Address: 0x100532D0
// Name: double qh_strtod(char const __near *,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
long double __cdecl qh_strtod(char *s, char **endp)
{
  long double result; // st7
  char *v3; // eax

  result = strtod(nptr: s, endptr: endp);
  if ( s < *endp )
  {
    v3 = *endp - 1;
    if ( *v3 == 32 )
      *endp = v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10053300
// Name: int qh_strtol(char const __near *,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl qh_strtol(char *s, char **endp)
{
  int result; // eax
  char *v3; // ecx

  result = strtol(nptr: s, endptr: endp, ibase: 10);
  if ( s < *endp )
  {
    v3 = *endp - 1;
    if ( *v3 == 32 )
      *endp = v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10053330
// Name: void qh_initflags(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_initflags(char *command)
{
  char *v1; // esi
  char v2; // al
  char v3; // al
  char v4; // al
  char *v5; // esi
  char *i; // eax
  char v7; // dl
  char *v8; // eax
  char v9; // al
  char v10; // al
  char v11; // al
  char *v12; // ecx
  char v13; // al
  char v14; // al
  char *v15; // ecx
  char v16; // bl
  bool v17; // zf
  char v18; // al
  char v19; // al
  char *v20; // ecx
  char v21; // bl
  int v22; // esi
  char *v23; // eax
  int v24; // ecx
  char v25; // cl
  signed int v26; // eax
  int v27; // eax
  signed int v28; // esi
  char v29; // al
  char v30; // al
  char v31; // al
  char *v32; // edi
  unsigned int v33; // esi
  char v34; // al
  char *v35; // esi
  char *v36; // edi
  char v37; // bl
  signed int v38; // eax
  char v39; // al
  char v40; // al
  char *v41; // ecx
  char v42; // al
  int v43; // [esp-Ch] [ebp-220h]
  char filename[500]; // [esp+4h] [ebp-210h] BYREF
  char *prev_s; // [esp+1F8h] [ebp-1Ch]
  unsigned int isgeom; // [esp+1FCh] [ebp-18h]
  long double r; // [esp+200h] [ebp-14h] BYREF
  int lastproject; // [esp+208h] [ebp-Ch]
  char *t; // [esp+20Ch] [ebp-8h] BYREF
  unsigned int isquote; // [esp+210h] [ebp-4h] BYREF

  v1 = command;
  isgeom = 0;
  if ( command != qh_qh.qhull_command )
  {
    qh_qh.qhull_command[0] = 0;
    strncat(Destination: qh_qh.qhull_command, Source: command, Count: 0x100u);
    v1 = command;
  }
  v2 = *v1;
  if ( *v1 != 0 )
  {
    while ( v2 < 9 || v2 > 13 && v2 != 32 )
    {
      command = ++v1;
      v2 = *v1;
      if ( *v1 == 0 )
        return;
    }
    v3 = *v1;
    if ( *v1 != 0 )
    {
      while ( 1 )
      {
        do
        {
          if ( v3 < 9 || v3 > 13 && v3 != 32 )
            break;
          command = ++v1;
          v3 = *v1;
        }
        while ( *v1 != 0 );
        if ( *v1 == 45 )
          command = ++v1;
        v4 = *v1;
        if ( *v1 == 0 )
          break;
        prev_s = v1;
        v5 = v1 + 1;
        command = v5;
        switch ( v4 )
        {
          case 'A':
            if ( isdigit(c: *v5) == 0 && *command != 46 )
            {
              if ( *command != 45 )
              {
                fprintf(
                  str: qh_qh.ferr,
                  format: "qhull warning: no maximum cosine angle given for option 'An'.  Ignored.\n");
                goto LABEL_332;
              }
LABEL_34:
              qh_qh.premerge_cos = -qh_strtod(s: command, endp: &command);
              qh_option(option: "Angle-premerge-", i: nullptr, r: &qh_qh.premerge_cos);
              qh_qh.PREmerge = 1;
              qh_qh.MERGING = 1;
              goto LABEL_332;
            }
            if ( *command == 45 )
              goto LABEL_34;
            qh_qh.postmerge_cos = qh_strtod(s: command, endp: &command);
            qh_option(option: "Angle-postmerge", i: nullptr, r: &qh_qh.postmerge_cos);
            qh_qh.POSTmerge = 1;
            qh_qh.MERGING = 1;
            goto LABEL_332;
          case 'C':
            if ( isdigit(c: *v5) == 0 && *command != 46 )
            {
              if ( *command != 45 )
              {
                fprintf(str: qh_qh.ferr, format: "qhull warning: no centrum radius given for option 'Cn'.  Ignored.\n");
                goto LABEL_332;
              }
LABEL_41:
              qh_qh.premerge_centrum = -qh_strtod(s: command, endp: &command);
              qh_option(option: "Centrum-premerge-", i: nullptr, r: &qh_qh.premerge_centrum);
              qh_qh.PREmerge = 1;
              qh_qh.MERGING = 1;
              goto LABEL_332;
            }
            if ( *command == 45 )
              goto LABEL_41;
            qh_qh.postmerge_centrum = qh_strtod(s: command, endp: &command);
            qh_option(option: "Centrum-postmerge", i: nullptr, r: &qh_qh.postmerge_centrum);
            qh_qh.POSTmerge = 1;
            qh_qh.MERGING = 1;
LABEL_332:
            if ( command - 1 != prev_s )
              goto LABEL_343;
            v40 = *command;
            if ( *command == 0 )
              goto LABEL_344;
            if ( v40 < 9 || v40 > 13 && v40 != 32 )
            {
              ivp_message(
                templat: "qhull warning: missing space after flag %c (%x); reserved for menu. Skipped.\n",
                *prev_s,
                *prev_s);
              v41 = command;
              v42 = *command;
              if ( *command == 0 )
                goto LABEL_344;
              while ( v42 < 9 || v42 > 13 && v42 != 32 )
              {
                command = ++v41;
                v42 = *v41;
                if ( *v41 == 0 )
                  goto LABEL_344;
              }
            }
LABEL_343:
            v3 = *command;
            if ( *command == 0 )
              goto LABEL_344;
            v1 = command;
            break;
          case 'E':
            if ( *v5 == 45 )
            {
              fprintf(
                str: qh_qh.ferr,
                format: "qhull warning: negative maximum roundoff given for option 'An'.  Ignored.\n");
            }
            else if ( isdigit(c: *v5) != 0 )
            {
              qh_qh.DISTround = qh_strtod(s: command, endp: &command);
              qh_option(option: "Distance-roundoff", i: nullptr, r: &qh_qh.DISTround);
              qh_qh.SETroundoff = 1;
            }
            else
            {
              fprintf(str: qh_qh.ferr, format: "qhull warning: no maximum roundoff given for option 'En'.  Ignored.\n");
            }
            goto LABEL_332;
          case 'F':
            v9 = *v5;
            if ( *v5 == 0 )
              goto LABEL_332;
LABEL_79:
            if ( v9 >= 9 && (v9 <= 13 || v9 == 32) )
              goto LABEL_332;
            ++command;
            switch ( v9 )
            {
              case 'A':
                qh_option(option: "FArea-total", i: nullptr, r: nullptr);
                qh_qh.GETarea = 1;
                goto LABEL_113;
              case 'C':
                qh_option(option: "FCentrums", i: nullptr, r: nullptr);
                qh_appendprint(format: qh_PRINTcentrums);
                goto LABEL_113;
              case 'D':
                qh_option(option: "FD-cdd-out", i: nullptr, r: nullptr);
                qh_qh.CDDoutput = 1;
                goto LABEL_113;
              case 'F':
                qh_option(option: "FFacets-xridge", i: nullptr, r: nullptr);
                qh_appendprint(format: qh_PRINTfacets_xridge);
                goto LABEL_113;
              case 'I':
                qh_option(option: "FIds", i: nullptr, r: nullptr);
                qh_appendprint(format: qh_PRINTids);
                goto LABEL_113;
              case 'N':
                qh_option(option: "FNeighbors-vertex", i: nullptr, r: nullptr);
                qh_appendprint(format: qh_PRINTvneighbors);
                goto LABEL_113;
              case 'O':
                if ( qh_qh.PRINToptions1st != 0 )
                {
                  qh_option(option: "FOptions", i: nullptr, r: nullptr);
                  qh_appendprint(format: qh_PRINToptions);
                }
                else
                {
                  qh_qh.PRINToptions1st = 1;
                }
                goto LABEL_113;
              case 'P':
                qh_option(option: "FPoint-nearest", i: nullptr, r: nullptr);
                qh_appendprint(format: qh_PRINTpointnearest);
                goto LABEL_113;
              case 'Q':
                qh_option(option: "FQhull", i: nullptr, r: nullptr);
                qh_appendprint(format: qh_PRINTqhull);
                goto LABEL_113;
              case 'S':
                qh_option(option: "FSize", i: nullptr, r: nullptr);
                qh_appendprint(format: qh_PRINTsize);
                qh_qh.GETarea = 1;
                goto LABEL_113;
              case 'V':
                qh_option(option: "FVertex-average", i: nullptr, r: nullptr);
                qh_appendprint(format: qh_PRINTaverage);
                goto LABEL_113;
              case 'a':
                qh_option(option: "Farea", i: nullptr, r: nullptr);
                qh_appendprint(format: qh_PRINTarea);
                qh_qh.GETarea = 1;
                goto LABEL_113;
              case 'c':
                qh_option(option: "Fcoplanars", i: nullptr, r: nullptr);
                qh_appendprint(format: qh_PRINTcoplanars);
                goto LABEL_113;
              case 'd':
                qh_option(option: "Fd-cdd-in", i: nullptr, r: nullptr);
                qh_qh.CDDinput = 1;
                goto LABEL_113;
              case 'i':
                qh_option(option: "Finner", i: nullptr, r: nullptr);
                qh_appendprint(format: qh_PRINTinner);
                goto LABEL_113;
              case 'm':
                qh_option(option: "Fmerges", i: nullptr, r: nullptr);
                qh_appendprint(format: qh_PRINTmerges);
                goto LABEL_113;
              case 'n':
                qh_option(option: "Fneighbors", i: nullptr, r: nullptr);
                qh_appendprint(format: qh_PRINTneighbors);
                goto LABEL_113;
              case 'o':
                qh_option(option: "Fouter", i: nullptr, r: nullptr);
                qh_appendprint(format: qh_PRINTouter);
                goto LABEL_113;
              case 'p':
                qh_option(option: "Fpoint-intersect", i: nullptr, r: nullptr);
                qh_appendprint(format: qh_PRINTpointintersect);
                goto LABEL_113;
              case 's':
                qh_option(option: "Fsummary", i: nullptr, r: nullptr);
                qh_appendprint(format: qh_PRINTsummary);
                goto LABEL_113;
              case 't':
                qh_option(option: "Ftriangles", i: nullptr, r: nullptr);
                qh_appendprint(format: qh_PRINTtriangles);
                goto LABEL_113;
              case 'v':
                qh_appendprint(format: qh_PRINTvertices);
                goto LABEL_113;
              case 'x':
                qh_option(option: "Fxtremes", i: nullptr, r: nullptr);
                qh_appendprint(format: qh_PRINTextremes);
                goto LABEL_113;
              default:
                ivp_message(templat: "qhull warning: unknown 'F' output option %c, rest ignored\n", *--command);
                break;
            }
            while ( 1 )
            {
              v10 = *++command;
              if ( *command == 0 )
                goto LABEL_332;
              if ( v10 >= 9 && (v10 <= 13 || v10 == 32) )
              {
LABEL_113:
                v9 = *command;
                if ( *command != 0 )
                  goto LABEL_79;
                goto LABEL_332;
              }
            }
          case 'G':
            isgeom = 1;
            qh_appendprint(format: qh_PRINTgeom);
            v11 = *v5;
            if ( *v5 == 0 )
              goto LABEL_332;
LABEL_116:
            if ( v11 >= 9 && (v11 <= 13 || v11 == 32) )
              goto LABEL_332;
            v12 = ++command;
            switch ( v11 )
            {
              case 'D':
                if ( isdigit(c: *v12) != 0 )
                {
                  if ( qh_qh.DROPdim >= 0 )
                    ivp_message(
                      templat: "qhull warning: can only drop one dimension.  Previous 'GD%d' ignored\n",
                      qh_qh.DROPdim);
                  qh_qh.DROPdim = qh_strtol(s: command, endp: &command);
                  qh_option(option: "GDrop-dim", i: &qh_qh.DROPdim, r: nullptr);
                }
                else
                {
                  ivp_message(templat: "qhull input error: missing dimension for option 'GDn'\n");
                }
                goto LABEL_140;
              case 'a':
                qh_option(option: "Gall-points", i: nullptr, r: nullptr);
                qh_qh.PRINTdots = 1;
                goto LABEL_140;
              case 'c':
                qh_option(option: "Gcentrums", i: nullptr, r: nullptr);
                qh_qh.PRINTcentrums = 1;
                goto LABEL_140;
              case 'h':
                qh_option(option: "Gintersections", i: nullptr, r: nullptr);
                qh_qh.DOintersections = 1;
                goto LABEL_140;
              case 'i':
                qh_option(option: "Ginner", i: nullptr, r: nullptr);
                qh_qh.PRINTinner = 1;
                goto LABEL_140;
              case 'n':
                qh_option(option: "Gno-planes", i: nullptr, r: nullptr);
                qh_qh.PRINTnoplanes = 1;
                goto LABEL_140;
              case 'o':
                qh_option(option: "Gouter", i: nullptr, r: nullptr);
                qh_qh.PRINTouter = 1;
                goto LABEL_140;
              case 'p':
                qh_option(option: "Gpoints", i: nullptr, r: nullptr);
                qh_qh.PRINTcoplanar = 1;
                goto LABEL_140;
              case 'r':
                qh_option(option: "Gridges", i: nullptr, r: nullptr);
                qh_qh.PRINTridges = 1;
                goto LABEL_140;
              case 't':
                qh_option(option: "Gtransparent", i: nullptr, r: nullptr);
                qh_qh.PRINTtransparent = 1;
                goto LABEL_140;
              case 'v':
                qh_option(option: "Gvertices", i: nullptr, r: nullptr);
                qh_qh.PRINTspheres = 1;
                goto LABEL_140;
              default:
                command = v12 - 1;
                ivp_message(templat: "qhull warning: unknown 'G' print option %c, rest ignored\n", *(v12 - 1));
                break;
            }
            while ( 1 )
            {
              v13 = *++command;
              if ( *command == 0 )
                goto LABEL_332;
              if ( v13 >= 9 && (v13 <= 13 || v13 == 32) )
              {
LABEL_140:
                v11 = *command;
                if ( *command != 0 )
                  goto LABEL_116;
                goto LABEL_332;
              }
            }
          case 'H':
            qh_qh.HALFspace = 1;
            qh_strtod(s: v5, endp: &t);
            for ( i = t; t > command; i = t )
            {
              v7 = *i;
              if ( *i != 0 && (v7 < 9 || v7 > 13 && v7 != 32) )
              {
                if ( v7 == 44 )
                {
                  t = ++i;
                }
                else
                {
                  ivp_message(templat: "qhull warning: origin for Halfspace intersection should be 'Hn,n,n,...'\n");
                  i = t;
                }
              }
              command = i;
              qh_strtod(s: i, endp: &t);
            }
            if ( v5 >= i )
            {
              qh_option(option: "Halfspace", i: nullptr, r: nullptr);
            }
            else
            {
              v8 = _calloc_crt(nelem: i - v5 + 1, size: 1);
              qh_qh.feasible_string = v8;
              if ( v8 == nullptr )
              {
                fprintf(str: qh_qh.ferr, format: "qhull error: insufficient memory for 'Hn,n,n'\n");
                qh_errexit(exitcode: 4, facet: nullptr, ridge: nullptr);
              }
              strncpy(dest: (unsigned __int8 *)v8, source: (unsigned __int8 *)v5, count: t - v5);
              qh_option(option: "Halfspace-about", i: nullptr, r: nullptr);
              qh_option(option: qh_qh.feasible_string, i: nullptr, r: nullptr);
            }
            goto LABEL_332;
          case 'P':
            v14 = *v5;
            if ( *v5 == 0 )
              goto LABEL_332;
LABEL_143:
            if ( v14 >= 9 && (v14 <= 13 || v14 == 32) )
              goto LABEL_332;
            v15 = ++command;
            switch ( v14 )
            {
              case 'A':
                if ( isdigit(c: *v15) != 0 )
                {
                  qh_qh.KEEParea = qh_strtol(s: command, endp: &command);
                  qh_option(option: "PArea-keep", i: &qh_qh.KEEParea, r: nullptr);
                  qh_qh.GETarea = 1;
                }
                else
                {
                  ivp_message(templat: "qhull input error: missing facet count for keep area option 'PAn'\n");
                }
                goto LABEL_170;
              case 'D':
              case 'd':
                v16 = *(command - 1);
                isquote = qh_strtol(s: command, endp: &command);
                v17 = *command == 58;
                r = 0.0;
                if ( v17 )
                {
                  ++command;
                  r = qh_strtod(s: command, endp: &command);
                }
                if ( v16 == 100 )
                  qh_option(option: "Pdrop-facets-dim-less", i: (int *)&isquote, &r);
                else
                  qh_option(option: "PDrop-facets-dim-more", i: (int *)&isquote, &r);
                goto LABEL_170;
              case 'F':
                if ( isdigit(c: *v15) != 0 )
                {
                  qh_qh.KEEPminArea = qh_strtod(s: command, endp: &command);
                  qh_option(option: "PFacet-area-keep", i: nullptr, r: &qh_qh.KEEPminArea);
                  qh_qh.GETarea = 1;
                }
                else
                {
                  ivp_message(templat: "qhull input error: missing facet area for option 'PFn'\n");
                }
                goto LABEL_170;
              case 'G':
                qh_option(option: "PGood-facet-neighbors", i: nullptr, r: nullptr);
                qh_qh.PRINTneighbors = 1;
                goto LABEL_170;
              case 'M':
                if ( isdigit(c: *v15) != 0 )
                {
                  qh_qh.KEEPmerge = qh_strtol(s: command, endp: &command);
                  qh_option(option: "PMerge-keep", i: &qh_qh.KEEPmerge, r: nullptr);
                }
                else
                {
                  ivp_message(templat: "qhull input error: missing merge count for option 'PMn'\n");
                }
                goto LABEL_170;
              case 'g':
                qh_option(option: "Pgood-facets", i: nullptr, r: nullptr);
                qh_qh.PRINTgood = 1;
                goto LABEL_170;
              case 'o':
                qh_option(option: "Poutput-forced", i: nullptr, r: nullptr);
                qh_qh.FORCEoutput = 1;
                goto LABEL_170;
              case 'p':
                qh_option(option: "Pprecision-ignore", i: nullptr, r: nullptr);
                qh_qh.PRINTprecision = 0;
                goto LABEL_170;
              default:
                command = v15 - 1;
                ivp_message(templat: "qhull warning: unknown 'P' print option %c, rest ignored\n", *(v15 - 1));
                break;
            }
            while ( 1 )
            {
              v18 = *++command;
              if ( *command == 0 )
                goto LABEL_332;
              if ( v18 >= 9 && (v18 <= 13 || v18 == 32) )
              {
LABEL_170:
                v14 = *command;
                if ( *command != 0 )
                  goto LABEL_143;
                goto LABEL_332;
              }
            }
          case 'Q':
            v19 = *v5;
            lastproject = -1;
            if ( v19 == 0 )
              goto LABEL_332;
LABEL_173:
            if ( v19 >= 9 && (v19 <= 13 || v19 == 32) )
              goto LABEL_332;
            v20 = ++command;
            switch ( v19 )
            {
              case '0':
                qh_option(option: "Q0-no-premerge", i: nullptr, r: nullptr);
                qh_qh.NOpremerge = 1;
                goto LABEL_262;
              case '1':
                qh_option(option: "Q1-no-angle-sort", i: nullptr, r: nullptr);
                qh_qh.ANGLEmerge = 0;
                goto LABEL_222;
              case '2':
                qh_option(option: "Q2-no-merge-independent", i: nullptr, r: nullptr);
                qh_qh.MERGEindependent = 0;
                goto LABEL_222;
              case '3':
                qh_option(option: "Q3-no-merge-vertices", i: nullptr, r: nullptr);
                qh_qh.MERGEvertices = 0;
LABEL_222:
                if ( isdigit(c: *command) != 0 )
                {
                  v43 = *command++;
                  ivp_message(
                    templat: "qhull warning: can not follow '1', '2', or '3' with a digit.  '%c' skipped.\n",
                    v43);
                }
                goto LABEL_262;
              case '4':
                qh_option(option: "Q4-avoid-old-into-new", i: nullptr, r: nullptr);
                qh_qh.AVOIDold = 1;
                goto LABEL_262;
              case '5':
                qh_option(option: "Q5-no-check-outer", i: nullptr, r: nullptr);
                qh_qh.SKIPcheckmax = 1;
                goto LABEL_262;
              case '6':
                qh_option(option: "Q6-no-concave-merge", i: nullptr, r: nullptr);
                qh_qh.SKIPconvex = 1;
                goto LABEL_262;
              case '7':
                qh_option(option: "Q7-no-breadth-first", i: nullptr, r: nullptr);
                qh_qh.VIRTUALmemory = 1;
                goto LABEL_262;
              case '8':
                qh_option(option: "Q8-no-near-inside", i: nullptr, r: nullptr);
                qh_qh.NOnearinside = 1;
                goto LABEL_262;
              case '9':
                qh_option(option: "Q9-pick-furthest", i: nullptr, r: nullptr);
                qh_qh.PICKfurthest = 1;
                goto LABEL_262;
              case 'B':
              case 'b':
                v21 = *(v20 - 1);
                if ( v21 == 98 )
                {
                  if ( *command == 66 )
                  {
                    ++command;
                    r = 0.5;
                    qh_qh.SCALEinput = 1;
                    qh_option(option: "QbBound-unit-box", i: nullptr, &r);
                    goto LABEL_262;
                  }
                  if ( *command == 98 )
                  {
                    ++command;
                    qh_qh.SCALElast = 1;
                    qh_option(option: "Qbbound-last", i: nullptr, r: nullptr);
                    goto LABEL_262;
                  }
                }
                v22 = qh_strtol(s: command, endp: &command);
                v17 = *command == 58;
                isquote = v22;
                r = 0.0;
                if ( !v17 )
                  goto LABEL_194;
                ++command;
                r = qh_strtod(s: command, endp: &command);
                if ( r != 0.0 )
                  goto LABEL_194;
                v23 = command;
                t = command;
                if ( *command == 0 )
                  goto LABEL_194;
                while ( 2 )
                {
                  v24 = *v23;
                  if ( v24 >= 9 && (v24 <= 13 || v24 == 32) )
                  {
LABEL_194:
                    if ( lastproject == v22 && r == 0.0 )
                    {
                      lastproject = -1;
                    }
                    else
                    {
                      qh_qh.SCALEinput = 1;
                      if ( v21 == 98 )
                      {
                        if ( r == 0.0 )
                          r = -0.5;
                        qh_option(option: "Qbound-dim-low", i: (int *)&isquote, &r);
                      }
                      else
                      {
                        if ( r == 0.0 )
                          r = 0.5;
                        qh_option(option: "QBound-dim-high", i: (int *)&isquote, &r);
                      }
                    }
                    goto LABEL_262;
                  }
                  t = v23 + 1;
                  if ( toupper(c: v24) != 66 || v22 != qh_strtol(s: t, endp: &t) )
                    goto LABEL_192;
                  v25 = *t;
                  v23 = ++t;
                  if ( v25 != 58 )
                    goto LABEL_193;
                  if ( qh_strtod(s: v23, endp: &t) != 0.0 )
                  {
LABEL_192:
                    v23 = t;
LABEL_193:
                    if ( *v23 == 0 )
                      goto LABEL_194;
                    continue;
                  }
                  break;
                }
                ++qh_qh.PROJECTinput;
                if ( qh_qh.IStracing >= 2 )
                  fprintf(str: qh_qh.ferr, format: "qh_initflags: project dimension %d\n", v22);
                qh_option(option: "Qb-project-dim", i: (int *)&isquote, r: nullptr);
                lastproject = v22;
                goto LABEL_262;
              case 'G':
                v26 = qh_strtol(s: v20, endp: &t);
                isquote = v26;
                if ( qh_qh.GOODpoint != 0 )
                {
                  ivp_message(templat: "qhull warning: good point already defined for option 'QGn'.  Ignored\n");
                  command = t;
                }
                else if ( command == t )
                {
                  ivp_message(templat: "qhull warning: missing good point id for option 'QGn'.  Ignored\n");
                  command = t;
                }
                else if ( v26 < 0 || *command == 45 )
                {
                  qh_qh.GOODpoint = v26 - 1;
                  qh_option(option: "QGood-if-dont-see-point", i: (int *)&isquote, r: nullptr);
                  command = t;
                }
                else
                {
                  qh_qh.GOODpoint = v26 + 1;
                  qh_option(option: "QGood-if-see-point", i: (int *)&isquote, r: nullptr);
                  command = t;
                }
                goto LABEL_262;
              case 'J':
                if ( isdigit(c: *v20) != 0 || *command == 45 )
                {
                  qh_qh.JOGGLEmax = qh_strtod(s: command, endp: &command);
                  qh_option(option: "QJoggle", i: nullptr, r: &qh_qh.JOGGLEmax);
                }
                else
                {
                  qh_qh.JOGGLEmax = 0.0;
                }
                goto LABEL_262;
              case 'R':
                if ( isdigit(c: *v20) != 0 || *command == 45 )
                {
                  v27 = qh_strtol(s: command, endp: &command);
                  isquote = v27;
                  qh_qh.ROTATErandom = v27;
                  if ( v27 <= 0 )
                  {
                    if ( v27 < -1 )
                      qh_option(option: "QRandom-seed", i: (int *)&isquote, r: nullptr);
                  }
                  else
                  {
                    qh_option(option: "QRotate-id", i: (int *)&isquote, r: nullptr);
                  }
                }
                else
                {
                  ivp_message(templat: "qhull warning: missing random seed for option 'QRn'.  Ignored\n");
                }
                goto LABEL_262;
              case 'V':
                v28 = qh_strtol(s: command, endp: &t);
                isquote = v28;
                if ( qh_qh.GOODvertex != 0 )
                {
                  ivp_message(templat: "qhull warning: good vertex already defined for option 'QVn'.  Ignored\n");
                  command = t;
                }
                else if ( command == t )
                {
                  ivp_message(templat: "qhull warning: no good point id given for option 'QVn'.  Ignored\n");
                  command = t;
                }
                else
                {
                  if ( v28 >= 0 )
                  {
                    qh_option(option: "QV-good-facets-point", i: (int *)&isquote, r: nullptr);
                    qh_qh.GOODvertex = v28 + 1;
                  }
                  else
                  {
                    qh_qh.GOODvertex = v28 - 1;
                    qh_option(option: "QV-good-facets-not-point", i: (int *)&isquote, r: nullptr);
                  }
                  command = t;
                }
                goto LABEL_262;
              case 'c':
                qh_option(option: "Qcoplanar-keep", i: nullptr, r: nullptr);
                qh_qh.KEEPcoplanar = 1;
                goto LABEL_262;
              case 'f':
                qh_option(option: "Qfurthest-outside", i: nullptr, r: nullptr);
                qh_qh.BESToutside = 1;
                goto LABEL_262;
              case 'g':
                qh_option(option: "Qgood-facets-only", i: nullptr, r: nullptr);
                qh_qh.ONLYgood = 1;
                goto LABEL_262;
              case 'i':
                qh_option(option: "Qinterior-keep", i: nullptr, r: nullptr);
                qh_qh.KEEPinside = 1;
                goto LABEL_262;
              case 'm':
                qh_option(option: "Qmax-outside-only", i: nullptr, r: nullptr);
                qh_qh.ONLYmax = 1;
                goto LABEL_262;
              case 'r':
                qh_option(option: "Qrandom-outside", i: nullptr, r: nullptr);
                qh_qh.RANDOMoutside = 1;
                goto LABEL_262;
              case 's':
                qh_option(option: "Qsearch-initial-simplex", i: nullptr, r: nullptr);
                qh_qh.ALLpoints = 1;
                goto LABEL_262;
              case 'u':
                qh_option(option: "QupperDelaunay", i: nullptr, r: nullptr);
                qh_qh.UPPERdelaunay = 1;
                goto LABEL_262;
              case 'v':
                qh_option(option: "Qvertex-neighbors-convex", i: nullptr, r: nullptr);
                qh_qh.TESTvneighbors = 1;
                goto LABEL_262;
              case 'x':
                qh_option(option: "Qxact-merge", i: nullptr, r: nullptr);
                qh_qh.MERGEexact = 1;
                qh_qh.MERGING = 1;
                goto LABEL_262;
              case 'z':
                qh_option(option: "Qz-infinity-point", i: nullptr, r: nullptr);
                qh_qh.ATinfinity = 1;
                goto LABEL_262;
              default:
                command = v20 - 1;
                ivp_message(templat: "qhull warning: unknown 'Q' qhull option %c, rest ignored\n", *(v20 - 1));
                break;
            }
            while ( 1 )
            {
              v29 = *++command;
              if ( *command == 0 )
                goto LABEL_332;
              if ( v29 >= 9 && (v29 <= 13 || v29 == 32) )
              {
LABEL_262:
                v19 = *command;
                if ( *command != 0 )
                  goto LABEL_173;
                goto LABEL_332;
              }
            }
          case 'R':
            if ( isdigit(c: *v5) != 0 )
            {
              qh_qh.RANDOMfactor = qh_strtod(s: command, endp: &command);
              qh_option(option: "Random_perturb", i: nullptr, r: &qh_qh.RANDOMfactor);
              qh_qh.RANDOMdist = 1;
            }
            else
            {
              fprintf(str: qh_qh.ferr, format: "qhull warning: missing random perturbation for option 'Rn'.  Ignored\n");
            }
            goto LABEL_332;
          case 'T':
            v30 = *v5;
            if ( *v5 == 0 )
              goto LABEL_332;
            do
            {
              if ( v30 >= 9 && (v30 <= 13 || v30 == 32) )
                break;
              if ( isdigit(c: v30) != 0 || (v31 = *command, *command == 45) )
              {
                qh_qh.IStracing = qh_strtol(s: command, endp: &command);
              }
              else
              {
                v32 = ++command;
                switch ( v31 )
                {
                  case 'C':
                    if ( isdigit(c: *v32) != 0 )
                    {
                      v33 = qh_strtol(s: command, endp: &command);
                      isquote = v33;
                      qh_option(option: "TCone-stop", i: (int *)&isquote, r: nullptr);
                      qh_qh.STOPcone = v33 + 1;
                    }
                    else
                    {
                      ivp_message(templat: "qhull warning: missing point id for cone for trace option 'TCn'.  Ignored\n");
                    }
                    break;
                  case 'F':
                    if ( isdigit(c: *v32) != 0 )
                    {
                      qh_qh.REPORTfreq = qh_strtol(s: command, endp: &command);
                      qh_option(option: "TFacet-log", i: &qh_qh.REPORTfreq, r: nullptr);
                      qh_qh.REPORTfreq2 = qh_qh.REPORTfreq / 2;
                    }
                    else
                    {
                      ivp_message(templat: "qhull warning: missing frequency count for trace option 'TFn'.  Ignored\n");
                    }
                    break;
                  case 'M':
                    if ( isdigit(c: *v32) != 0 )
                    {
                      qh_qh.TRACEmerge = qh_strtol(s: command, endp: &command);
                      qh_option(option: "Trace-merge", i: &qh_qh.TRACEmerge, r: nullptr);
                    }
                    else
                    {
                      ivp_message(templat: "qhull warning: missing merge id for trace option 'TMn'.  Ignored\n");
                    }
                    break;
                  case 'O':
                    if ( *v32 != 32 || (v34 = v32[1], v35 = v32 + 1, v34 == 34) || V_isspace(c: v34) )
                    {
                      command = v32 + 1;
                      ivp_message(
                        templat: "qhull warning: option 'TO' mistyped.\n"
                        "Use 'TO', one space, file name, and space or end-of-line.\n"
                        "The file name may be enclosed in single quotes.\n"
                        "Do not use double quotes.  Option 'FO' ignored.\n");
                      break;
                    }
                    command = v32 + 1;
                    v17 = *v35 == 39;
                    v36 = filename;
                    isquote = 0;
                    if ( v17 )
                    {
                      ++v35;
                      isquote = 1;
                      command = v35;
                    }
                    if ( *v35 == 0 )
                      goto LABEL_295;
                    lastproject = 0;
                    while ( 2 )
                    {
                      if ( lastproject >= 498 )
                      {
                        ivp_message(templat: "qhull error: filename for 'TO' too long.\n");
                        qh_errexit(exitcode: 1, facet: nullptr, ridge: nullptr);
                      }
                      v37 = *v35;
                      if ( isquote == 0 )
                      {
                        if ( V_isspace(c: v37) )
                          goto LABEL_295;
LABEL_298:
                        ++lastproject;
                        ++v35;
                        *v36++ = v37;
                        command = v35;
                        if ( *v35 == 0 )
                          goto LABEL_295;
                        continue;
                      }
                      break;
                    }
                    if ( v37 != 39 )
                      goto LABEL_298;
                    command = v35 + 1;
                    isquote = 0;
LABEL_295:
                    v17 = isquote == 0;
                    *v36 = 0;
                    if ( v17 )
                    {
                      if ( freopen(filename, mode: "w", str: nullptr) == nullptr )
                      {
                        ivp_message(templat: "qhull error: could not open file \"%s\".", filename);
                        qh_errexit(exitcode: 1, facet: nullptr, ridge: nullptr);
                      }
                      qh_option(option: "TOutput-file", i: nullptr, r: nullptr);
                      qh_option(option: filename, i: nullptr, r: nullptr);
                    }
                    else
                    {
                      ivp_message(templat: "qhull error: missing end quote for option 'TO'.  Rest of line ignored.\n");
                    }
                    break;
                  case 'P':
                    if ( isdigit(c: *v32) != 0 )
                    {
                      qh_qh.TRACEpoint = qh_strtol(s: command, endp: &command);
                      qh_option(option: "Trace-point", i: &qh_qh.TRACEpoint, r: nullptr);
                    }
                    else
                    {
                      ivp_message(templat: "qhull warning: missing point id for trace option 'TPn'.  Ignored\n");
                    }
                    break;
                  case 'R':
                    if ( isdigit(c: *v32) != 0 )
                    {
                      qh_qh.RERUN = qh_strtol(s: command, endp: &command);
                      qh_option(option: "TRerun", i: &qh_qh.RERUN, r: nullptr);
                    }
                    else
                    {
                      ivp_message(templat: "qhull warning: missing rerun count for trace option 'TRn'.  Ignored\n");
                    }
                    break;
                  case 'V':
                    v38 = qh_strtol(s: v32, endp: &t);
                    isquote = v38;
                    if ( command == t )
                    {
                      ivp_message(templat: "qhull warning: missing furthest point id for trace option 'TVn'.  Ignored\n");
                      command = t;
                    }
                    else
                    {
                      if ( v38 >= 0 )
                      {
                        qh_qh.STOPpoint = v38 + 1;
                        qh_option(option: "TV-stop-after-point", i: (int *)&isquote, r: nullptr);
                      }
                      else
                      {
                        qh_qh.STOPpoint = v38 - 1;
                        qh_option(option: "TV-stop-before-point", i: (int *)&isquote, r: nullptr);
                      }
                      command = t;
                    }
                    break;
                  case 'W':
                    if ( isdigit(c: *v32) != 0 )
                    {
                      qh_qh.TRACEdist = qh_strtod(s: command, endp: &command);
                      qh_option(option: "TWide-trace", i: nullptr, r: &qh_qh.TRACEdist);
                    }
                    else
                    {
                      ivp_message(templat: "qhull warning: missing max width for trace option 'TWn'.  Ignored\n");
                    }
                    break;
                  case 'c':
                    qh_option(option: "Tcheck-frequently", i: nullptr, r: nullptr);
                    qh_qh.CHECKfrequently = 1;
                    break;
                  case 's':
                    qh_option(option: "Tstatistics", i: nullptr, r: nullptr);
                    qh_qh.PRINTstatistics = 1;
                    break;
                  case 'v':
                    qh_option(option: "Tverify", i: nullptr, r: nullptr);
                    qh_qh.VERIFYoutput = 1;
                    break;
                  case 'z':
                    if ( qh_qh.fout != nullptr )
                    {
                      qh_option(option: "Tz-stdout", i: nullptr, r: nullptr);
                      qh_qh.ferr = qh_qh.fout;
                      qhmem.ferr = qh_qh.fout;
                    }
                    else
                    {
                      ivp_message(templat: "qhull warning: output file undefined (stdout).  Option 'Tz' ignored.\n");
                    }
                    break;
                  default:
                    command = v32 - 1;
                    ivp_message(templat: "qhull warning: unknown 'T' trace option %c, rest ignored\n", *(v32 - 1));
                    while ( 1 )
                    {
                      v39 = *++command;
                      if ( *command == 0 )
                        goto LABEL_332;
                      if ( v39 >= 9 && (v39 <= 13 || v39 == 32) )
                        goto LABEL_329;
                    }
                }
              }
LABEL_329:
              v30 = *command;
            }
            while ( *command != 0 );
            goto LABEL_332;
          case 'U':
            if ( isdigit(c: *v5) != 0 || *command == 45 )
            {
              qh_qh.MAXcoplanar = qh_strtod(s: command, endp: &command);
              qh_option(option: "U-coplanar", i: nullptr, r: &qh_qh.MAXcoplanar);
            }
            else
            {
              fprintf(str: qh_qh.ferr, format: "qhull warning: missing coplanar distance for option 'Un'.  Ignored\n");
            }
            goto LABEL_332;
          case 'V':
            if ( isdigit(c: *v5) != 0 || *command == 45 )
            {
              qh_qh.MINvisible = qh_strtod(s: command, endp: &command);
              qh_option(option: "Visible", i: nullptr, r: &qh_qh.MINvisible);
            }
            else
            {
              fprintf(str: qh_qh.ferr, format: "qhull warning: missing visible distance for option 'Vn'.  Ignored\n");
            }
            goto LABEL_332;
          case 'W':
            if ( *v5 == 45 )
            {
              fprintf(str: qh_qh.ferr, format: "qhull warning: negative outside width for option 'Wn'.  Ignored.\n");
            }
            else if ( isdigit(c: *v5) != 0 )
            {
              qh_qh.MINoutside = qh_strtod(s: command, endp: &command);
              qh_option(option: "W-outside", i: nullptr, r: &qh_qh.MINoutside);
              qh_qh.APPROXhull = 1;
            }
            else
            {
              fprintf(str: qh_qh.ferr, format: "qhull warning: missing outside width for option 'Wn'.  Ignored\n");
            }
            goto LABEL_332;
          case 'd':
            qh_option(option: "delaunay", i: nullptr, r: nullptr);
            qh_qh.DELAUNAY = 1;
            goto LABEL_332;
          case 'f':
            qh_option(option: "facets", i: nullptr, r: nullptr);
            qh_appendprint(format: qh_PRINTfacets);
            goto LABEL_332;
          case 'i':
            qh_option(option: "incidence", i: nullptr, r: nullptr);
            qh_appendprint(format: qh_PRINTincidences);
            goto LABEL_332;
          case 'm':
            qh_option(option: "mathematica", i: nullptr, r: nullptr);
            qh_appendprint(format: qh_PRINTmathematica);
            goto LABEL_332;
          case 'n':
            qh_option(option: "normals", i: nullptr, r: nullptr);
            qh_appendprint(format: qh_PRINTnormals);
            goto LABEL_332;
          case 'o':
            qh_option(option: "offFile", i: nullptr, r: nullptr);
            qh_appendprint(format: qh_PRINToff);
            goto LABEL_332;
          case 'p':
            qh_option(option: "points", i: nullptr, r: nullptr);
            qh_appendprint(format: qh_PRINTpoints);
            goto LABEL_332;
          case 's':
            qh_option(option: "summary", i: nullptr, r: nullptr);
            qh_qh.PRINTsummary = 1;
            goto LABEL_332;
          case 'v':
            qh_option(option: "voronoi", i: nullptr, r: nullptr);
            qh_qh.VORONOI = 1;
            qh_qh.DELAUNAY = 1;
            goto LABEL_332;
          default:
            ivp_message(templat: "qhull warning: unknown flag %c (%x)\n", *(v5 - 1), *(v5 - 1));
            goto LABEL_332;
        }
      }
LABEL_344:
      if ( isgeom != 0 && qh_qh.FORCEoutput == 0 && qh_qh.PRINTout[1] != qh_PRINTnone )
        ivp_message(templat: "qhull warning: additional output formats are not compatible with Geomview\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100550E0
// Name: void qh_initqhull_globals(double __near *,int,int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_initqhull_globals(long double *points, int numpoints, int dim, int ismalloc)
{
  unsigned int MERGING; // eax
  int v5; // eax
  double i; // xmm0_8
  double v7; // xmm2_8
  int IStracing; // edx
  int v9; // ebx
  int ROTATErandom; // eax
  unsigned int v11; // eax
  int v12; // esi
  int v13; // edi
  int v14; // esi
  int v15; // eax
  unsigned int v16; // edi
  qhT *p_PRINTridges; // ebx
  int v18; // eax
  unsigned int VORONOI; // ecx
  int hull_dim; // eax
  __int64 timedata; // [esp+24h] [ebp-20h] BYREF
  double randr; // [esp+2Ch] [ebp-18h]
  unsigned int printcoplanar; // [esp+34h] [ebp-10h]
  unsigned int printmath; // [esp+38h] [ebp-Ch]
  int extra; // [esp+3Ch] [ebp-8h]
  unsigned int printgeom; // [esp+40h] [ebp-4h]

  extra = 0;
  printgeom = 0;
  printmath = 0;
  printcoplanar = 0;
  if ( qh_qh.IStracing != 0 )
    fprintf(str: qh_qh.ferr, format: "qh_initqhull_globals: for %s | %s\n", qh_qh.rbox_command, qh_qh.qhull_command);
  qh_qh.POINTSmalloc = ismalloc;
  qh_qh.first_point = points;
  qh_qh.num_points = numpoints;
  qh_qh.input_dim = dim;
  qh_qh.hull_dim = dim;
  if ( qh_qh.NOpremerge == 0 && qh_qh.MERGEexact == 0 && qh_qh.PREmerge == 0 && qh_qh.JOGGLEmax > 8.988465674311579e307 )
  {
    qh_qh.MERGING = 1;
    if ( dim > 4 )
    {
      qh_qh.MERGEexact = 1;
      qh_option(option: "_merge-exact", i: nullptr, r: nullptr);
    }
    else
    {
      qh_qh.PREmerge = 1;
      qh_option(option: "_pre-merge", i: nullptr, r: nullptr);
    }
  }
  if ( qh_qh.JOGGLEmax < 8.988465674311579e307 && qh_qh.DELAUNAY != 0 && qh_qh.SCALEinput == 0 && qh_qh.SCALElast == 0 )
  {
    qh_qh.SCALElast = 1;
    qh_option(option: "Qbbound-last-qj", i: nullptr, r: nullptr);
  }
  if ( qh_qh.MERGING != 0
    && qh_qh.POSTmerge == 0
    && qh_qh.premerge_cos > 8.988465674311579e307
    && qh_qh.premerge_centrum == 0.0 )
  {
    qh_qh.ZEROcentrum = 1;
    qh_qh.ZEROall_ok = 1;
    qh_option(option: "_zero-centrum", i: nullptr, r: nullptr);
  }
  if ( qh_qh.KEEParea == 0 && qh_qh.KEEPminArea >= 8.988465674311579e307 && qh_qh.KEEPmerge == 0 && qh_qh.DELAUNAY == 0 )
    goto LABEL_36;
  if ( qh_qh.PRINTgood == 0 && qh_qh.PRINTneighbors == 0 )
  {
    qh_qh.PRINTgood = 1;
    qh_option(option: "Pgood", i: nullptr, r: nullptr);
  }
  if ( qh_qh.DELAUNAY == 0 )
    goto LABEL_36;
  if ( qh_qh.KEEPcoplanar != 0 && qh_qh.KEEPinside == 0 )
  {
    qh_qh.KEEPinside = 1;
    qh_option(option: "Qinterior-keep", i: nullptr, r: nullptr);
  }
  if ( qh_qh.DELAUNAY == 0 )
    goto LABEL_36;
  if ( qh_qh.HALFspace != 0 )
  {
    ivp_message(templat: "qhull input error: can not use Delaunay ('d') or Voronoi ('v') with halfspace intersection ('H')\n");
    qh_errexit(exitcode: 1, facet: nullptr, ridge: nullptr);
  }
  if ( qh_qh.DELAUNAY != 0 )
  {
    if ( qh_qh.UPPERdelaunay != 0 && qh_qh.ATinfinity != 0 )
    {
      ivp_message(templat: "qhull input error: can not use infinity-point ('Qz') with upper-Delaunay ('Qu')\n");
      qh_errexit(exitcode: 1, facet: nullptr, ridge: nullptr);
    }
  }
  else
  {
LABEL_36:
    if ( qh_qh.UPPERdelaunay != 0 || qh_qh.ATinfinity != 0 )
    {
      ivp_message(templat: "qhull input error: use upper-Delaunay ('Qu') or infinity-point ('Qz') with Delaunay ('d') or Voronoi ('v')\n");
      qh_errexit(exitcode: 1, facet: nullptr, ridge: nullptr);
    }
  }
  if ( qh_qh.SCALElast != 0 && qh_qh.DELAUNAY == 0 )
    ivp_message(templat: "qhull input warning: option 'Qbb' (scale-last-coordinate) is normally used with 'd' or 'v'\n");
  if ( qh_qh.FORCEoutput != 0 || qh_qh.SKIPcheckmax != 0 )
  {
    MERGING = qh_qh.MERGING;
    goto LABEL_54;
  }
  MERGING = qh_qh.MERGING;
  if ( qh_qh.MERGING == 0 )
  {
LABEL_54:
    qh_qh.DOcheckmax = 0;
LABEL_50:
    qh_qh.KEEPnearinside = 0;
    goto LABEL_51;
  }
  qh_qh.DOcheckmax = 1;
  if ( qh_qh.KEEPinside != 0 && qh_qh.KEEPcoplanar != 0 )
    goto LABEL_50;
  qh_qh.KEEPnearinside = 1;
  if ( qh_qh.NOnearinside != 0 )
    goto LABEL_50;
LABEL_51:
  if ( MERGING != 0 )
  {
    qh_qh.CENTERtype = qh_AScentrum;
  }
  else if ( qh_qh.VORONOI != 0 )
  {
    qh_qh.CENTERtype = qh_ASvoronoi;
  }
  if ( qh_qh.TESTvneighbors != 0 && MERGING == 0 )
  {
    fprintf(str: qh_qh.ferr, format: "qhull input error: test vertex neighbors ('Qv') needs a merge option\n");
    qh_errexit(exitcode: 1, facet: nullptr, ridge: nullptr);
  }
  if ( qh_qh.PROJECTinput != 0 || qh_qh.DELAUNAY != 0 && qh_qh.PROJECTdelaunay != 0 )
  {
    qh_qh.hull_dim -= qh_qh.PROJECTinput;
    if ( qh_qh.DELAUNAY != 0 )
    {
      ++qh_qh.hull_dim;
      extra = 1;
    }
  }
  if ( qh_qh.hull_dim <= 1 )
  {
    fprintf(str: qh_qh.ferr, format: "qhull error: dimension %d must be > 1\n", qh_qh.hull_dim);
    qh_errexit(exitcode: 1, facet: nullptr, ridge: nullptr);
  }
  v5 = 2;
  for ( i = 1.0; v5 < qh_qh.hull_dim; i = i * v7 )
    v7 = (double)v5++;
  IStracing = qh_qh.IStracing;
  qh_qh.AREAfactor = 1.0 / i;
  if ( qh_qh.IStracing >= 2 )
  {
    fprintf(
      str: qh_qh.ferr,
      format: "qh_initqhull_globals: initialize globals.  dim %d numpoints %d malloc? %d projected %d to hull_dim %d\n",
      dim,
      numpoints,
      ismalloc,
      qh_qh.PROJECTinput,
      qh_qh.hull_dim);
    IStracing = qh_qh.IStracing;
  }
  qh_qh.normal_size = 8 * qh_qh.hull_dim;
  qh_qh.center_size = 8 * qh_qh.hull_dim - 8;
  v9 = qh_qh.hull_dim + 1;
  if ( qh_qh.hull_dim > 6 )
  {
    qh_qh.MERGEvertices = 0;
    qh_option(option: "Q3-no-merge-vertices-dim-high", i: nullptr, r: nullptr);
    IStracing = qh_qh.IStracing;
  }
  if ( qh_qh.GOODpoint != 0 )
    ++v9;
  if ( qh_qh.RERUN <= 1 )
  {
    if ( qh_qh.TRACEpoint == -1 && qh_qh.TRACEdist >= 8.988465674311579e307 && qh_qh.TRACEmerge == 0 )
      goto LABEL_84;
    qh_qh.TRACElevel = IStracing;
    if ( IStracing == 0 )
      qh_qh.TRACElevel = 3;
  }
  else
  {
    qh_qh.TRACElastrun = IStracing;
    if ( IStracing == -1 )
      goto LABEL_84;
  }
  qh_qh.IStracing = 0;
LABEL_84:
  ROTATErandom = qh_qh.ROTATErandom;
  if ( qh_qh.ROTATErandom == 0 || qh_qh.ROTATErandom == -1 )
  {
    v11 = _time64(timeptr: &timedata);
    v12 = v11;
    ismalloc = v11;
    if ( qh_qh.ROTATErandom == -1 )
    {
      v12 = -v11;
      ismalloc = -v11;
      qh_option(option: "QRandom-seed", i: &ismalloc, r: nullptr);
    }
    else
    {
      qh_option(option: "QRotate-random", i: &ismalloc, r: nullptr);
    }
    ROTATErandom = v12;
    qh_qh.ROTATErandom = v12;
  }
  v13 = ROTATErandom;
  if ( ROTATErandom == 0x80000000 )
  {
    v13 = 1;
  }
  else if ( ROTATErandom < 0 )
  {
    v13 = -ROTATErandom;
  }
  qh_srand(seed: v13);
  randr = 0.0;
  v14 = 1000;
  do
  {
    --v14;
    v15 = qh_rand();
    randr = (double)v15 + randr;
    if ( (double)v15 > 2147483646.0 )
    {
      ivp_message(
        templat: "qhull configuration error (qh_RANDOMmax in user.h):\n   random integer %d > qh_RANDOMmax (%.8g)\n",
        v15,
        2147483646.0);
      qh_errexit(exitcode: 1, facet: nullptr, ridge: nullptr);
    }
  }
  while ( v14 != 0 );
  qh_srand(seed: v13);
  if ( randr * 0.001 < 214748364.6 || randr * 0.001 > 1.073741823e10 )
    ivp_message(
      templat: "qhull configuration warning (qh_RANDOMmax in user.h):\n"
      "   average of 1000 random integers (%.2g) is much different than expected (%.2g).\n"
      "   Is qh_RANDOMmax (%f) wrong?\n",
      randr * 0.001,
      1073741823.0,
      2147483646.0);
  qh_qh.RANDOMa = qh_qh.RANDOMfactor * 2.0 * 4.656612877414201e-10;
  qh_qh.RANDOMb = 1.0 - qh_qh.RANDOMfactor;
  if ( numpoints + extra < v9 )
  {
    _DevMsg(
      a1: 2,
      a2: "qhull input error: not enough points (%d) to construct initial simplex (need %d)\n",
      numpoints,
      v9);
    qh_errexit(exitcode: 1, facet: nullptr, ridge: nullptr);
  }
  if ( qh_qh.PRINTtransparent != 0 )
  {
    if ( qh_qh.hull_dim != 4 || qh_qh.DELAUNAY == 0 || qh_qh.VORONOI != 0 || qh_qh.DROPdim >= 0 )
    {
      fprintf(
        str: qh_qh.ferr,
        format: "qhull input error: transparent Delaunay ('Gt') needs 3-d Delaunay ('d') w/o 'GDn'\n");
      qh_errexit(exitcode: 1, facet: nullptr, ridge: nullptr);
    }
    qh_qh.DROPdim = 3;
    qh_qh.PRINTridges = 1;
  }
  v16 = printcoplanar;
  p_PRINTridges = (qhT *)&qh_qh.PRINTridges;
  do
  {
    v18 = *((_DWORD *)&p_PRINTridges[-1].searchset + 1);
    p_PRINTridges = (qhT *)((char *)p_PRINTridges - 4);
    switch ( v18 )
    {
      case 7:
        printgeom = 1;
        break;
      case 14:
        printmath = 1;
        break;
      case 3:
        v16 = 1;
        break;
      case 19:
        v16 = 1;
        break;
      default:
        if ( v18 == 18 && qh_qh.HALFspace == 0 )
        {
          ivp_message(templat: "qhull input error: option 'Fp' is only used for \nhalfspace intersection ('Hn,n,n').\n");
          goto LABEL_130;
        }
        if ( v18 == 24 )
        {
          if ( qh_qh.HALFspace != 0 || (VORONOI = qh_qh.VORONOI, qh_qh.VORONOI != 0) )
          {
            ivp_message(templat: "qhull input error: option 'Ft' is not available for Voronoi vertices or halfspace intersection\n");
            goto LABEL_130;
          }
        }
        else
        {
          VORONOI = qh_qh.VORONOI;
        }
        if ( v18 == 4 && VORONOI != 0 )
        {
          ivp_message(templat: "qhull input error: option 'Fc' is not available for Voronoi vertices ('v')\n");
LABEL_130:
          qh_errexit(exitcode: 1, facet: nullptr, ridge: nullptr);
        }
        if ( v18 == 25 )
        {
          if ( VORONOI != 0 )
            qh_option(option: "Fvoronoi", i: nullptr, r: nullptr);
          else
            qh_option(option: "Fvertices", i: nullptr, r: nullptr);
        }
        break;
    }
  }
  while ( p_PRINTridges != (qhT *)qh_qh.PRINTout );
  if ( qh_qh.KEEPcoplanar == 0
    && qh_qh.KEEPinside == 0
    && qh_qh.ONLYgood == 0
    && (qh_qh.PRINTcoplanar != 0 && qh_qh.PRINTspheres != 0 || v16 != 0) )
  {
    ivp_message(templat: "qhull input warning: options 'Fc', 'FP', and 'Gp' need option 'Qc' or 'Qi' to record coplanar/inside points\n");
  }
  hull_dim = qh_qh.hull_dim;
  if ( printmath != 0 && (qh_qh.hull_dim > 3 || qh_qh.VORONOI != 0 || qh_qh.HALFspace != 0) )
  {
    ivp_message(
      templat: "qhull input error: Mathematica output is only available for 2-d and 3-d convex hulls and Delaunay triangulations\n");
    qh_errexit(exitcode: 1, facet: nullptr, ridge: nullptr);
  }
  if ( printgeom != 0 )
  {
    if ( qh_qh.hull_dim > 4 )
    {
      ivp_message(templat: "qhull input error: Geomview output is only available for 2-d, 3-d and 4-d\n");
      qh_errexit(exitcode: 1, facet: nullptr, ridge: nullptr);
    }
    if ( qh_qh.PRINTnoplanes != 0
      && qh_qh.PRINTridges
       + qh_qh.PRINTcoplanar
       + qh_qh.PRINTspheres
       + qh_qh.PRINTcentrums
       + qh_qh.PRINTdots
       + qh_qh.DOintersections == 0 )
    {
      ivp_message(templat: "qhull input error: no output specified for Geomview\n");
      qh_errexit(exitcode: 1, facet: nullptr, ridge: nullptr);
    }
    if ( qh_qh.VORONOI != 0 && (qh_qh.hull_dim > 3 || qh_qh.DROPdim >= 0) )
    {
      ivp_message(templat: "qhull input error: Geomview output for Voronoi diagrams only for 2-d\n");
      qh_errexit(exitcode: 1, facet: nullptr, ridge: nullptr);
    }
    if ( qh_qh.hull_dim == 4
      && qh_qh.DROPdim == -1
      && (qh_qh.PRINTcoplanar != 0 || qh_qh.PRINTspheres != 0 || qh_qh.PRINTcentrums != 0) )
    {
      ivp_message(
        templat: "qhull input warning: coplanars, vertices, and centrums output not\n"
        "available for 4-d output (ignored).  Could use 'GDn' instead.\n");
      hull_dim = qh_qh.hull_dim;
      qh_qh.PRINTcentrums = 0;
      qh_qh.PRINTspheres = 0;
      qh_qh.PRINTcoplanar = 0;
    }
  }
  qh_qh.PRINTdim = hull_dim;
  if ( qh_qh.DROPdim < 0 )
  {
    if ( qh_qh.VORONOI != 0 )
    {
      qh_qh.DROPdim = hull_dim - 1;
      qh_qh.PRINTdim = hull_dim - 1;
    }
  }
  else if ( qh_qh.DROPdim >= hull_dim )
  {
    qh_qh.DROPdim = -1;
  }
  else
  {
    qh_qh.PRINTdim = hull_dim - 1;
    if ( printgeom == 0 || hull_dim < 3 )
      ivp_message(
        templat: "qhull input warning: drop dimension 'GD%d' is only available for 3-d/4-d Geomview\n",
        qh_qh.DROPdim);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100559C0
// Name: void qh_initthresholds(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_initthresholds(char *command)
{
  char *v1; // ecx
  char v2; // al
  char v3; // bl
  int v4; // edi
  long double v5; // xmm0_8
  char v6; // al
  char v7; // bl
  int v8; // esi
  int v9; // eax
  int v10; // edi
  long double v11; // xmm0_8
  int v12; // eax
  int hull_dim; // ecx
  double *v14; // eax
  double v15; // xmm2_8
  int maxdim; // [esp+20h] [ebp-4h]

  v1 = command;
  maxdim = qh_qh.input_dim;
  if ( qh_qh.DELAUNAY != 0 && (qh_qh.PROJECTdelaunay != 0 || qh_qh.PROJECTinput != 0) )
    maxdim = qh_qh.input_dim + 1;
  if ( *command == 0 )
    goto LABEL_65;
  do
  {
    if ( *v1 == 45 )
      command = ++v1;
    v2 = *v1;
    if ( *v1 != 80 )
    {
      if ( v2 != 81 )
      {
        if ( v2 != 0 )
        {
          do
          {
            if ( v2 >= 9 && (v2 <= 13 || v2 == 32) )
              break;
            command = ++v1;
            v2 = *v1;
          }
          while ( *v1 != 0 );
        }
        goto LABEL_60;
      }
      command = ++v1;
      v6 = *v1;
      if ( *v1 == 0 )
        goto LABEL_60;
      while ( 1 )
      {
        v7 = v6;
        v8 = v6;
        command = ++v1;
        if ( v6 >= 9 && (v6 <= 13 || v6 == 32) )
          goto LABEL_60;
        if ( v6 == 98 )
        {
          if ( *v1 == 66 )
          {
            v9 = maxdim;
            for ( command = v1 + 1; v9 != 0; qh_qh.upper_bound[v9] = 0.5 )
              qh_qh.lower_bound[--v9] = -0.5;
            goto LABEL_53;
          }
          if ( *v1 == 98 )
          {
            command = v1 + 1;
            goto LABEL_53;
          }
        }
        else if ( v6 != 66 )
        {
          goto LABEL_53;
        }
        if ( isdigit(c: *v1) != 0 )
        {
          v10 = qh_strtol(s: command, endp: &command);
          if ( v10 < maxdim )
          {
            if ( *command == 58 )
            {
              ++command;
              v11 = qh_strtod(s: command, endp: &command);
              goto LABEL_50;
            }
            if ( v7 != 98 )
            {
              v11 = 0.5;
LABEL_50:
              if ( v7 == 98 )
                qh_qh.lower_bound[v10] = v11;
              else
                qh_qh.upper_bound[v10] = v11;
              goto LABEL_53;
            }
            qh_qh.lower_bound[v10] = -0.5;
          }
          else
          {
            fprintf(
              str: qh_qh.ferr,
              format: "qhull warning: dimension %d for Qhull option %c is >= %d.  Ignored\n",
              v10,
              v8,
              maxdim);
          }
        }
        else
        {
          fprintf(str: qh_qh.ferr, format: "qhull warning: no dimension given for Qhull option %c.  Ignored\n", v8);
        }
LABEL_53:
        v1 = command;
        v6 = *command;
        if ( *command == 0 )
          goto LABEL_60;
      }
    }
    command = ++v1;
    v3 = *v1;
    if ( *v1 != 0 )
    {
      do
      {
        command = ++v1;
        if ( v3 >= 9 && (v3 <= 13 || v3 == 32) )
          break;
        if ( v3 == 100 || v3 == 68 )
        {
          if ( isdigit(c: *v1) != 0 )
          {
            v4 = qh_strtol(s: command, endp: &command);
            if ( v4 < qh_qh.hull_dim )
            {
              if ( *command != 58 )
              {
                v5 = 0.0;
LABEL_23:
                if ( v3 == 100 )
                  qh_qh.lower_threshold[v4] = v5;
                else
                  qh_qh.upper_threshold[v4] = v5;
                goto LABEL_26;
              }
              ++command;
              v5 = qh_strtod(s: command, endp: &command);
              if ( fabs(v5) <= 1.0 )
                goto LABEL_23;
              fprintf(
                str: qh_qh.ferr,
                format: "qhull warning: value %2.4g for Print option %c is > +1 or < -1.  Ignored\n",
                (double)v5,
                v3);
            }
            else
            {
              fprintf(
                str: qh_qh.ferr,
                format: "qhull warning: dimension %d for Print option '%c' is >= %d.  Ignored\n",
                v4,
                v3,
                qh_qh.hull_dim);
            }
          }
          else
          {
            fprintf(
              str: qh_qh.ferr,
              format: "qhull warning: no dimension given for Print option '%c' at: %s.  Ignored\n",
              v3,
              command - 1);
          }
        }
LABEL_26:
        v1 = command;
        v3 = *command;
      }
      while ( *command != 0 );
    }
LABEL_60:
    while ( 1 )
    {
      v12 = *v1;
      if ( v12 < 9 || v12 > 13 && v12 != 32 )
        break;
      command = ++v1;
    }
  }
  while ( *v1 != 0 );
LABEL_65:
  hull_dim = qh_qh.hull_dim;
  if ( qh_qh.hull_dim == 0 )
    return;
  v14 = &qh_qh.upper_threshold[qh_qh.hull_dim];
  while ( 1 )
  {
    v15 = *(double *)((char *)v14-- + (char *)qh_qh.lower_threshold - (char *)qh_qh.upper_threshold - 8);
    --hull_dim;
    if ( v15 <= -8.988465674311579e307 )
    {
      if ( *v14 < 8.988465674311579e307 )
        qh_qh.GOODthreshold = 1;
      goto LABEL_73;
    }
    qh_qh.GOODthreshold = 1;
    if ( *v14 < 8.988465674311579e307 )
      break;
LABEL_73:
    if ( hull_dim == 0 )
      return;
  }
  qh_qh.SPLITthresholds = 1;
  qh_qh.GOODthreshold = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10055D50
// Name: void qh_init_B(double __near *,int,int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_init_B(long double *points, int numpoints, int dim, unsigned int ismalloc)
{
  int v4; // eax
  int v5; // ecx
  int v6; // edx

  qh_initqhull_globals(points, numpoints, dim, ismalloc);
  if ( qhmem.LASTsize == 0 )
    qh_initqhull_mem();
  qh_initqhull_buffers();
  qh_initthresholds(command: qh_qh.qhull_command);
  if ( qh_qh.PROJECTinput != 0 || qh_qh.DELAUNAY != 0 && qh_qh.PROJECTdelaunay != 0 )
    qh_projectinput();
  if ( qh_qh.SCALEinput != 0 )
    qh_scaleinput();
  if ( qh_qh.ROTATErandom >= 0 )
  {
    qh_randommatrix(buffer: qh_qh.gm_matrix, dim: (long double *)qh_qh.hull_dim, rows: qh_qh.gm_row);
    if ( qh_qh.DELAUNAY != 0 )
    {
      v4 = qh_qh.hull_dim - 1;
      v5 = 0;
      if ( qh_qh.hull_dim - 1 >= 4 )
      {
        v6 = qh_qh.hull_dim - 4;
        do
        {
          qh_qh.gm_row[v5][v4] = 0.0;
          qh_qh.gm_row[v4][v5] = 0.0;
          qh_qh.gm_row[v5 + 1][v4] = 0.0;
          qh_qh.gm_row[v4][v5 + 1] = 0.0;
          qh_qh.gm_row[v5 + 2][v4] = 0.0;
          qh_qh.gm_row[v4][v5 + 2] = 0.0;
          qh_qh.gm_row[v5 + 3][v4] = 0.0;
          qh_qh.gm_row[v4][v5 + 3] = 0.0;
          v5 += 4;
        }
        while ( v5 < v6 );
      }
      for ( ; v5 < v4; ++v5 )
      {
        qh_qh.gm_row[v5][v4] = 0.0;
        qh_qh.gm_row[v4][v5] = 0.0;
      }
      qh_qh.gm_row[v4][v4] = 1.0;
    }
    qh_gram_schmidt(dim: qh_qh.hull_dim, row: qh_qh.gm_row);
    qh_rotateinput(rows: qh_qh.gm_row);
  }
}
