// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_compact_builder/qhull_user.cxx
// Functions: 4
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10056540
// Name: int qh_new_qhull(int,int,double __near *,unsigned int,char __near *,struct _iobuf __near *,struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl qh_new_qhull(
        long double *dim,
        int numpoints,
        long double *points,
        unsigned int ismalloc,
        char *qhull_cmd,
        _iobuf *outfile,
        _iobuf *errfile)
{
  unsigned int v7; // ebx
  int result; // eax
  long double *v9; // esi
  long double *v10; // edi

  if ( firstcall != 0 )
  {
    qh_meminit(ferr: errfile);
    firstcall = 0;
  }
  if ( strncmp(first: qhull_cmd, last: "qhull ", count: 6u) != 0 )
  {
    ivp_message(templat: "qh_new_qhull: start qhull_cmd argument with \"qhull \"\n");
    exit(code: 1);
  }
  qh_initqhull_start(infile: nullptr, outfile, errfile);
  v7 = 1;
  if ( qh_qh.IStracing >= 1 )
    fprintf(
      str: qh_qh.ferr,
      format: "qh_new_qhull: build new Qhull for %d %d-d points with %s\n",
      numpoints,
      dim,
      qhull_cmd);
  result = _setjmp3(a1: qh_qh.errexit, a2: 0);
  if ( result == 0 )
  {
    qh_qh.NOerrexit = 0;
    qh_initflags(command: qhull_cmd);
    if ( qh_qh.DELAUNAY != 0 )
      qh_qh.PROJECTdelaunay = 1;
    if ( qh_qh.HALFspace != 0 )
    {
      v9 = (long double *)((char *)dim - 1);
      qh_setfeasible(dim: (int)dim - 1);
      v10 = qh_sethalfspace_all(a1: (int)dim, dim, count: numpoints, halfspaces: points, feasible: qh_qh.feasible_point);
      if ( ismalloc != 0 && points != nullptr )
        free(data: points);
    }
    else
    {
      v9 = dim;
      v10 = points;
      v7 = ismalloc;
    }
    qh_init_B(points: v10, numpoints, dim: (int)v9, ismalloc: v7);
    qh_qhull();
    result = 0;
  }
  qh_qh.NOerrexit = 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10056690
// Name: void qh_errprint(char const __near *,struct facetT __near *,struct facetT __near *,struct ridgeT __near *,struct vertexT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_errprint(const char *string, facetT *atfacet, facetT *otherfacet, ridgeT *atridge, vertexT *atvertex)
{
  facetT *v5; // edi
  facetT *v6; // ebx
  facetT *top; // eax
  facetT *bottom; // eax
  int *PRINTout; // esi

  if ( qh_qh.ferr != nullptr )
  {
    v5 = atfacet;
    if ( atfacet != nullptr )
    {
      ivp_message(templat: "%s FACET:\n", string);
      qh_printfacet(fp: qh_qh.ferr, facet: atfacet);
    }
    v6 = otherfacet;
    if ( otherfacet != nullptr && qh_qh.ferr != nullptr )
    {
      ivp_message(templat: "%s OTHER FACET:\n", string);
      qh_printfacet(fp: qh_qh.ferr, facet: otherfacet);
    }
    if ( atridge != nullptr )
    {
      ivp_message(templat: "%s RIDGE:\n", string);
      qh_printridge(fp: qh_qh.ferr, ridge: atridge);
      top = atridge->top;
      if ( top != nullptr && top != atfacet && top != otherfacet )
        qh_printfacet(fp: qh_qh.ferr, facet: atridge->top);
      bottom = atridge->bottom;
      if ( bottom != nullptr && bottom != atfacet && bottom != otherfacet )
        qh_printfacet(fp: qh_qh.ferr, facet: atridge->bottom);
      if ( atfacet == nullptr )
        v5 = atridge->top;
      if ( otherfacet == nullptr )
      {
        v6 = atridge->top;
        if ( v6 == v5 )
          v6 = atridge->bottom;
      }
    }
    if ( atvertex != nullptr )
    {
      ivp_message(templat: "%s VERTEX:\n", string);
      qh_printvertex(fp: qh_qh.ferr, vertex: atvertex);
    }
    if ( qh_qh.fout != nullptr
      && qh_qh.FORCEoutput != 0
      && v5 != nullptr
      && qh_qh.QHULLfinished == 0
      && qh_qh.IStracing == 0 )
    {
      ivp_message(templat: "ERRONEOUS and NEIGHBORING FACETS to output\n");
      PRINTout = (int *)qh_qh.PRINTout;
      do
        qh_printneighborhood(fp: qh_qh.fout, format: *PRINTout++, facetA: v5, facetB: v6, printall: 0);
      while ( (int)PRINTout < (int)&qh_qh.PRINTridges );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10056800
// Name: void qh_printfacetlist(struct facetT __near *,struct setT __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_printfacetlist(facetT *facetlist, setT *facets, unsigned int printall)
{
  facetT *v3; // esi
  facetT *p; // eax
  setelemT *e; // esi

  v3 = facetlist;
  qh_printbegin(fp: qh_qh.ferr, format: 5, facetlist, facets, printall);
  if ( facetlist != nullptr )
  {
    do
    {
      if ( v3->next == nullptr )
        break;
      qh_printafacet(fp: qh_qh.ferr, format: 5, facet: v3, printall);
      v3 = v3->next;
    }
    while ( v3 != nullptr );
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
        qh_printafacet(fp: qh_qh.ferr, format: 5, facet: p, printall);
        p = (facetT *)e->i;
      }
      while ( e->i != 0 );
    }
  }
  qh_printend(fp: qh_qh.ferr, format: 5, facetlist, facets, printall);
}

//------------------------------------------------------------------------------
// Address: 0x10056890
// Name: void qh_errexit(int,struct facetT __near *,struct ridgeT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn qh_errexit(int exitcode, facetT *facet, ridgeT *ridge)
{
  int v3; // esi

  if ( qh_qh.ferr != nullptr )
  {
    if ( qh_qh.ERREXITcalled != 0 )
    {
      ivp_message(templat: "\nqhull error while processing previous error.  Exit program\n");
      exit(code: 1);
    }
    qh_qh.ERREXITcalled = 1;
    if ( qh_qh.QHULLfinished == 0 )
      qh_qh.hulltime = 1 - qh_qh.hulltime;
    qh_errprint(string: "ERRONEOUS", atfacet: facet, otherfacet: nullptr, atridge: ridge, atvertex: nullptr);
    ivp_message(templat: "\nWhile executing: %s | %s\n", qh_qh.rbox_command, qh_qh.qhull_command);
    ivp_message(templat: "Options selected for %s:\n%s\n", qh_version, qh_qh.qhull_options);
    if ( qh_qh.furthest_id >= 0 )
    {
      ivp_message(templat: "Last point added to hull was p%d.", qh_qh.furthest_id);
      if ( qh_qhstat.stats[176].i != 0 )
        ivp_message(templat: "  Last merge was #%d.", qh_qhstat.stats[176].i);
      if ( qh_qh.QHULLfinished != 0 )
      {
        ivp_message(templat: "\nQhull has finished constructing the hull.");
      }
      else if ( qh_qh.POSTmerging != 0 )
      {
        ivp_message(templat: "\nQhull has started post-merging.");
      }
      ivp_message(templat: "\n");
    }
    v3 = exitcode;
    if ( qh_qh.FORCEoutput == 0 || qh_qh.QHULLfinished == 0 && (facet != nullptr || ridge != nullptr) )
    {
      if ( exitcode != 2 && qh_qhstat.stats[172].i > qh_qh.hull_dim + 1 )
      {
        ivp_message(templat: "\nAt error exit:\n");
        qh_printsummary(fp: qh_qh.ferr);
        if ( qh_qh.PRINTstatistics != 0 )
        {
          qh_collectstatistics();
          qh_printstatistics(fp: qh_qh.ferr, string: "at error exit");
          qh_memstatistics(fp: qh_qh.ferr);
        }
      }
      if ( qh_qh.PRINTprecision != 0 )
        qh_printstats(fp: qh_qh.ferr, index: qh_qhstat.precision, nextindex: nullptr);
    }
    else
    {
      qh_produce_output();
    }
    if ( exitcode != 0 )
    {
      if ( exitcode == 2 )
      {
        qh_printhelp_singular(fp: qh_qh.ferr);
      }
      else if ( exitcode == 3 && qh_qh.PREmerge == 0 )
      {
        qh_printhelp_degenerate(fp: qh_qh.ferr);
      }
    }
    else
    {
      v3 = 5;
    }
    if ( qh_qh.NOerrexit != 0 )
    {
      ivp_message(templat: "qhull error while ending program.  Exit program\n");
      exit(code: 1);
    }
  }
  else
  {
    v3 = exitcode;
  }
  qh_qh.NOerrexit = 1;
  longjmp(Buf: qh_qh.errexit, Value: v3);
}
