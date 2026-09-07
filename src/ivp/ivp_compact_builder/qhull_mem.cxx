// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_compact_builder/qhull_mem.cxx
// Functions: 9
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10055EF0
// Name: qh_intcompare
// Source: json
//------------------------------------------------------------------------------
int __cdecl qh_intcompare(_DWORD *i, _DWORD *j)
{
  return *i - *j;
}

//------------------------------------------------------------------------------
// Address: 0x10055F00
// Name: void __near * qh_memalloc(int)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl qh_memalloc(unsigned int insize)
{
  int v1; // ecx
  char *result; // eax
  int freesize; // esi
  int v4; // ebx
  unsigned int BUFinit; // esi
  void **v6; // eax
  void **v7; // edi
  int v8; // eax
  char *freemem; // ecx
  int v10; // eax
  void *v11; // eax
  const void *v12; // edi

  if ( insize > qhmem.LASTsize )
  {
    if ( qhmem.indextable == nullptr )
    {
      ivp_message(templat: "qhull internal error (qh_memalloc): qhmem has not been initialized.\n");
      qh_errexit(exitcode: 5, facet: nullptr, ridge: nullptr);
    }
    ++qhmem.cntlong;
    ++qhmem.curlong;
    v10 = insize + qhmem.totlong;
    qhmem.totlong = v10;
    if ( qhmem.maxlong < v10 )
      qhmem.maxlong = v10;
    v11 = p_malloc(size: insize);
    v12 = v11;
    if ( v11 == nullptr )
    {
      ivp_message(templat: "qhull error (qh_memalloc): insufficient memory\n");
      qh_errexit(exitcode: 4, facet: nullptr, ridge: nullptr);
    }
    if ( qhmem.IStracing >= 5 )
      ivp_message(templat: "qh_memalloc long: %d bytes at %p\n", insize, v11);
    return (char *)v12;
  }
  else
  {
    v1 = qhmem.indextable[insize];
    result = (char *)qhmem.freelists[v1];
    if ( result != nullptr )
    {
      ++qhmem.cntquick;
      qhmem.freelists[v1] = *(void **)qhmem.freelists[v1];
    }
    else
    {
      freesize = qhmem.freesize;
      v4 = qhmem.sizetable[v1];
      ++qhmem.cntshort;
      if ( v4 <= qhmem.freesize )
      {
        freemem = (char *)qhmem.freemem;
      }
      else
      {
        BUFinit = qhmem.BUFinit;
        if ( qhmem.curbuffer != nullptr )
          BUFinit = qhmem.BUFsize;
        qhmem.totshort += BUFinit;
        v6 = (void **)p_malloc(size: BUFinit);
        v7 = v6;
        if ( v6 == nullptr )
        {
          ivp_message(templat: "qhull error (qh_memalloc): insufficient memory\n");
          qh_errexit(exitcode: 4, facet: nullptr, ridge: nullptr);
        }
        *v6 = qhmem.curbuffer;
        v8 = ~qhmem.ALIGNmask & (qhmem.ALIGNmask + 4);
        qhmem.curbuffer = v7;
        freemem = (char *)v7 + v8;
        freesize = BUFinit - v8;
      }
      qhmem.freesize = freesize - v4;
      qhmem.freemem = &freemem[v4];
      return freemem;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10056070
// Name: void qh_memfree(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_memfree(void **object, int size)
{
  void **v2; // ecx

  if ( object != nullptr )
  {
    if ( size > qhmem.LASTsize )
    {
      ++qhmem.freelong;
      qhmem.totlong -= size;
      free(data: object);
      if ( qhmem.IStracing >= 5 )
        ivp_message(templat: "qh_memfree long: %d bytes at %p\n", size, nullptr);
    }
    else
    {
      ++qhmem.freeshort;
      v2 = &qhmem.freelists[qhmem.indextable[size]];
      *object = *v2;
      *v2 = object;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100560E0
// Name: void qh_memfreeshort(int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_memfreeshort(int *curlong, int *totlong)
{
  _DWORD *curbuffer; // eax
  _DWORD *v3; // esi

  *curlong = qhmem.cntlong - qhmem.freelong;
  *totlong = qhmem.totlong;
  curbuffer = qhmem.curbuffer;
  if ( qhmem.curbuffer != nullptr )
  {
    do
    {
      v3 = (_DWORD *)*curbuffer;
      free(data: curbuffer);
      curbuffer = v3;
    }
    while ( v3 != nullptr );
  }
  qhmem.curbuffer = nullptr;
  if ( qhmem.LASTsize != 0 )
  {
    if ( qhmem.indextable != nullptr )
    {
      free(data: qhmem.indextable);
      qhmem.indextable = nullptr;
    }
    if ( qhmem.freelists != nullptr )
    {
      free(data: qhmem.freelists);
      qhmem.freelists = nullptr;
    }
    if ( qhmem.sizetable != nullptr )
      free(data: qhmem.sizetable);
  }
  memset(dst: (unsigned __int8 *)&qhmem, value: 0, count: sizeof(qhmem));
}

//------------------------------------------------------------------------------
// Address: 0x10056190
// Name: void qh_meminit(struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_meminit(_iobuf *ferr)
{
  memset(dst: (unsigned __int8 *)&qhmem, value: 0, count: sizeof(qhmem));
  qhmem.ferr = ferr;
}

//------------------------------------------------------------------------------
// Address: 0x100561B0
// Name: void qh_meminitbuffers(int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_meminitbuffers(int tracelevel, int alignment, int numsizes, int bufsize, int bufinit)
{
  void **v5; // eax

  qhmem.IStracing = tracelevel;
  qhmem.BUFsize = bufsize;
  qhmem.NUMsizes = numsizes;
  qhmem.BUFinit = bufinit;
  qhmem.ALIGNmask = alignment - 1;
  if ( (~(alignment - 1) & (alignment - 1)) != 0 )
  {
    ivp_message(templat: "qhull internal error (qh_meminit): memory alignment %d is not a power of 2\n", alignment);
    qh_errexit(exitcode: 5, facet: nullptr, ridge: nullptr);
  }
  qhmem.sizetable = (int *)_calloc_crt(nelem: numsizes, size: 4);
  v5 = (void **)_calloc_crt(nelem: numsizes, size: 4);
  qhmem.freelists = v5;
  if ( qhmem.sizetable == nullptr || v5 == nullptr )
  {
    ivp_message(templat: "qhull error (qh_meminit): insufficient memory\n");
    qh_errexit(exitcode: 4, facet: nullptr, ridge: nullptr);
  }
  if ( qhmem.IStracing >= 1 )
    ivp_message(templat: "qh_meminitbuffers: memory initialized with alignment %d\n", alignment);
}

//------------------------------------------------------------------------------
// Address: 0x10056270
// Name: void qh_memsetup(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_memsetup()
{
  int v0; // eax
  int *indextable; // eax
  int v2; // ecx
  int v3; // ecx
  int v4; // edx

  qsort(
    base: qhmem.sizetable,
    num: qhmem.TABLEsize,
    width: 4u,
    comp: (int (__cdecl *)(const void *, const void *))qh_intcompare);
  v0 = qhmem.sizetable[qhmem.TABLEsize - 1];
  qhmem.LASTsize = v0;
  if ( v0 >= qhmem.BUFsize || v0 >= qhmem.BUFinit )
  {
    ivp_message(
      templat: "qhull error (qh_memsetup): largest mem size %d is >= buffer size %d or initial buffer size %d\n",
      v0,
      qhmem.BUFsize,
      qhmem.BUFinit);
    qh_errexit(exitcode: 4, facet: nullptr, ridge: nullptr);
  }
  indextable = (int *)p_malloc(size: 4 * v0 + 4);
  qhmem.indextable = indextable;
  if ( indextable == nullptr )
  {
    ivp_message(templat: "qhull error (qh_memsetup): insufficient memory\n");
    qh_errexit(exitcode: 4, facet: nullptr, ridge: nullptr);
  }
  v2 = qhmem.LASTsize + 1;
  if ( qhmem.LASTsize != -1 )
  {
    do
    {
      --v2;
      indextable[v2] = v2;
      indextable = qhmem.indextable;
    }
    while ( v2 != 0 );
  }
  v3 = 0;
  v4 = 0;
  if ( qhmem.LASTsize >= 0 )
  {
    while ( 1 )
    {
      if ( indextable[v3] > qhmem.sizetable[v4] )
        ++v4;
      indextable[v3++] = v4;
      if ( v3 > qhmem.LASTsize )
        break;
      indextable = qhmem.indextable;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10056360
// Name: void qh_memsize(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_memsize(int size)
{
  int v1; // ecx
  int TABLEsize; // eax

  if ( qhmem.LASTsize != 0 )
  {
    ivp_message(templat: "qhull error (qh_memsize): called after qhmem_setup\n");
    qh_errexit(exitcode: 5, facet: nullptr, ridge: nullptr);
  }
  v1 = ~qhmem.ALIGNmask & (qhmem.ALIGNmask + size);
  TABLEsize = qhmem.TABLEsize;
  if ( qhmem.TABLEsize != 0 )
  {
    while ( qhmem.sizetable[--TABLEsize] != v1 )
    {
      if ( TABLEsize == 0 )
        goto LABEL_6;
    }
  }
  else
  {
LABEL_6:
    if ( qhmem.TABLEsize >= qhmem.NUMsizes )
      ivp_message(templat: "qhull warning (memsize): free list table has room for only %d sizes\n", qhmem.NUMsizes);
    else
      qhmem.sizetable[qhmem.TABLEsize++] = v1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100563E0
// Name: void qh_memstatistics(struct _iobuf __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_memstatistics(_iobuf *fp)
{
  int v1; // esi
  int *sizetable; // edx
  int TABLEsize; // ebx
  _DWORD *v4; // eax
  int i; // ecx
  int j; // esi
  _DWORD *v7; // eax
  int k; // ecx

  v1 = 0;
  if ( fp != nullptr )
  {
    if ( qhmem.TABLEsize > 0 )
    {
      sizetable = qhmem.sizetable;
      TABLEsize = qhmem.TABLEsize;
      do
      {
        v4 = *(_DWORD **)((char *)sizetable + (char *)qhmem.freelists - (char *)qhmem.sizetable);
        for ( i = 0; v4 != nullptr; ++i )
          v4 = (_DWORD *)*v4;
        v1 += i * *sizetable++;
        --TABLEsize;
      }
      while ( TABLEsize != 0 );
    }
    fprintf(
      str: fp,
      format: "\n"
      "memory statistics:\n"
      "%7d quick allocations\n"
      "%7d short allocations\n"
      "%7d long allocations\n"
      "%7d short frees\n"
      "%7d long frees\n"
      "%7d bytes of short memory in use\n"
      "%7d bytes of short memory in freelists\n"
      "%7d bytes of long memory allocated (except for input)\n"
      "%7d bytes of long memory in use (in %d pieces)\n"
      "%7d bytes per memory buffer (initially %d bytes)\n",
      qhmem.cntquick,
      qhmem.cntshort,
      qhmem.cntlong,
      qhmem.freeshort,
      qhmem.freelong,
      qhmem.totshort - qhmem.freesize - v1,
      v1,
      qhmem.maxlong,
      qhmem.totlong,
      qhmem.cntlong - qhmem.freelong,
      qhmem.BUFsize,
      qhmem.BUFinit);
    if ( qhmem.cntlarger != 0 )
    {
      fprintf(
        str: fp,
        format: "%7d calls to qh_setlarger\n%7.2g     average copy size\n",
        qhmem.cntlarger,
        (float)((float)qhmem.totlarger / (float)qhmem.cntlarger));
      fprintf(str: fp, format: "  freelists (bytes->count):");
    }
    for ( j = 0; j < qhmem.TABLEsize; ++j )
    {
      v7 = qhmem.freelists[j];
      for ( k = 0; v7 != nullptr; ++k )
        v7 = (_DWORD *)*v7;
      fprintf(str: fp, format: " %d->%d", qhmem.sizetable[j], k);
    }
    fprintf(str: fp, format: "\n\n");
  }
}
