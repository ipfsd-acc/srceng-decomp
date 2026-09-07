// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_compact_builder/qhull_qset.cxx
// Functions: 34
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1004C590
// Name: void __near * qh_setdel(struct setT __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl qh_setdel(setT *set, void *oldelem)
{
  void *result; // eax
  setelemT *e; // ecx
  setelemT *v4; // edx
  int v5; // edi
  void **v6; // edx

  if ( set == nullptr )
    return nullptr;
  result = oldelem;
  e = set->e;
  if ( set->e[0].p != oldelem )
  {
    while ( e->i != 0 )
    {
      ++e;
      if ( e->p == oldelem )
        goto LABEL_5;
    }
    return nullptr;
  }
LABEL_5:
  if ( e->i == 0 )
    return nullptr;
  v4 = &set->e[set->maxsize];
  v5 = v4->i--;
  if ( v5 == 0 )
    v4->p = (void *)set->maxsize;
  v6 = (void **)(&set->maxsize + v4->i);
  e->i = (int)*v6;
  *v6 = nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004C5F0
// Name: void __near * qh_setdellast(struct setT __near *)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl qh_setdellast(setT *set)
{
  int maxsize; // edx
  setelemT v2; // esi
  void *result; // eax

  if ( set == nullptr || set->e[0].i == 0 )
    return nullptr;
  maxsize = set->maxsize;
  v2.p = (void *)set->e[set->maxsize];
  if ( v2.i != 0 )
  {
    result = *((void **)set + v2.i - 1);
    *((_DWORD *)set + v2.i - 1) = 0;
    --set->e[maxsize].i;
  }
  else
  {
    result = (void *)*(&set->maxsize + maxsize);
    *(&set->maxsize + maxsize) = 0;
    set->e[maxsize].i = maxsize;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004C640
// Name: void __near * qh_setdelsorted(struct setT __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl qh_setdelsorted(setT *set, void *oldelem)
{
  void *p; // edx
  void *result; // eax
  setelemT *e; // ecx
  setelemT *v5; // esi
  int i; // edx
  setelemT v7; // edx
  setelemT *v8; // ecx

  if ( set == nullptr )
    return nullptr;
  p = set->e[0].p;
  result = oldelem;
  e = set->e;
  if ( p != oldelem )
  {
    while ( p != nullptr )
    {
      p = e[1].p;
      ++e;
      if ( p == oldelem )
        goto LABEL_5;
    }
    return nullptr;
  }
LABEL_5:
  if ( e->i == 0 )
    return nullptr;
  v5 = e + 1;
  do
  {
    i = v5->i;
    e->p = v5->p;
    ++e;
    ++v5;
  }
  while ( i != 0 );
  v7.p = (void *)set->e[set->maxsize];
  v8 = &set->e[set->maxsize];
  v8->i = v7.i - 1;
  if ( v7.i == 0 )
    v8->p = (void *)set->maxsize;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004C6A0
// Name: int qh_setequal(struct setT __near *,struct setT __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl qh_setequal(setT *setA, setT *setB)
{
  setelemT v2; // eax
  int maxsize; // eax
  setelemT v4; // ecx
  int v5; // ecx
  unsigned int v7; // eax
  setelemT *e; // ecx
  setelemT *v9; // esi

  v2.p = (void *)setA->e[setA->maxsize];
  if ( v2.i != 0 )
    maxsize = v2.i - 1;
  else
    maxsize = setA->maxsize;
  v4.p = (void *)setB->e[setB->maxsize];
  if ( v4.i != 0 )
    v5 = v4.i - 1;
  else
    v5 = setB->maxsize;
  if ( maxsize != v5 )
    return 0;
  if ( maxsize != 0 )
  {
    v7 = 4 * maxsize;
    e = setB->e;
    v9 = setA->e;
    if ( v7 >= 4 )
    {
      while ( v9->i == e->i )
      {
        v7 -= 4;
        ++e;
        ++v9;
        if ( v7 < 4 )
          goto LABEL_13;
      }
      return 0;
    }
LABEL_13:
    if ( v7 != 0
      && (LOBYTE(e->p) != LOBYTE(v9->p)
       || v7 > 1 && (BYTE1(e->p) != BYTE1(v9->p) || v7 > 2 && BYTE2(e->i) != BYTE2(v9->i))) )
    {
      return 0;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1004C730
// Name: int qh_setequal_except(struct setT __near *,void __near *,struct setT __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl qh_setequal_except(setT *setA, void *skipelemA, setT *setB, void *skipelemB)
{
  int v5; // esi
  setelemT *e; // edx
  setelemT *i; // eax
  int v8; // ecx
  void *v9; // ecx
  void *v10; // ebx

  v5 = 0;
  e = setA->e;
  for ( i = setB->e; ; ++i )
  {
    if ( e->p == skipelemA )
    {
      ++v5;
      ++e;
    }
    if ( skipelemB != nullptr )
    {
      if ( i->p == skipelemB )
      {
        ++v5;
        ++i;
      }
    }
    else
    {
      v8 = i->i;
      if ( e->i != i->i )
      {
        skipelemB = (void *)i->i;
        ++v5;
        ++i;
        if ( v8 == 0 )
          return false;
      }
    }
    v9 = (void *)e->i;
    if ( e->i == 0 )
      break;
    v10 = (void *)i->i;
    ++e;
    if ( v9 != v10 )
      return false;
  }
  return v5 == 2 && i->i == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1004C7A0
// Name: int qh_setequal_skip(struct setT __near *,int,struct setT __near *,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl qh_setequal_skip(setT *setA, int skipA, setT *setB, int skipB)
{
  setelemT *e; // ecx
  setelemT *i; // eax
  int v6; // edx
  int v7; // ebx

  e = setA->e;
  for ( i = setB->e; ; ++i )
  {
    if ( e == &setA->e[skipA] )
      ++e;
    if ( i == &setB->e[skipB] )
      ++i;
    v6 = e->i;
    if ( e->i == 0 )
      break;
    v7 = i->i;
    ++e;
    if ( v6 != v7 )
      return false;
  }
  return i->i == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1004C800
// Name: void qh_setfree(struct setT __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_setfree(setT **setp)
{
  _DWORD *v1; // ecx
  int v2; // eax
  int *v3; // eax

  v1 = *setp;
  if ( *setp != nullptr )
  {
    v2 = 4 * *v1 + 8;
    if ( v2 > qhmem.LASTsize )
    {
      qh_memfree(object: v1, size: 4 * *v1 + 8);
    }
    else
    {
      ++qhmem.freeshort;
      v3 = (int *)&qhmem.freelists[qhmem.indextable[v2]];
      (*setp)->maxsize = *v3;
      *v3 = (int)*setp;
    }
    *setp = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004C860
// Name: void qh_setfreelong(struct setT __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_setfreelong(setT **setp)
{
  _DWORD *v1; // eax

  v1 = *setp;
  if ( *setp != nullptr && 4 * *v1 + 8 > qhmem.LASTsize )
  {
    qh_memfree(object: v1, size: 4 * *v1 + 8);
    *setp = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004C8A0
// Name: int qh_setin(struct setT __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl qh_setin(setT *set, void *setelem)
{
  setelemT *e; // ecx
  void *p; // eax

  if ( set == nullptr )
    return 0;
  e = set->e;
  p = set->e[0].p;
  if ( p == nullptr )
    return 0;
  while ( 1 )
  {
    ++e;
    if ( p == setelem )
      break;
    p = (void *)e->i;
    if ( e->i == 0 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1004C8D0
// Name: int qh_setindex(struct setT __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl qh_setindex(setT *set, void *atelem)
{
  setelemT v2; // ecx
  int maxsize; // ecx
  int result; // eax
  setelemT *e; // edx
  void *i; // edi

  v2.p = (void *)set->e[set->maxsize];
  if ( v2.i != 0 )
    maxsize = v2.i - 1;
  else
    maxsize = set->maxsize;
  if ( maxsize > set->maxsize )
    return -1;
  e = set->e;
  result = 0;
  if ( maxsize <= 0 )
    return -1;
  while ( 1 )
  {
    i = (void *)e->i;
    ++e;
    if ( i == atelem )
      break;
    if ( ++result >= maxsize )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004C920
// Name: void __near * qh_setlast(struct setT __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl qh_setlast(setT *set)
{
  int *v1; // edx
  int v2; // ecx

  if ( set == nullptr )
    return 0;
  v1 = &set->maxsize + set->maxsize;
  v2 = v1[1];
  if ( v2 == 0 )
    return *v1;
  if ( v2 > 1 )
    return *((_DWORD *)set + v2 - 1);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1004C950
// Name: struct setT __near * qh_setnew(int)
// Source: json
//------------------------------------------------------------------------------
setT *__cdecl qh_setnew(int setsize)
{
  int v1; // edi
  int v2; // esi
  int v3; // ecx
  setT *result; // eax
  void **v5; // ecx
  int v6; // ecx

  v1 = setsize;
  if ( setsize == 0 )
    v1 = 1;
  v2 = 4 * v1 + 8;
  if ( (unsigned int)v2 > qhmem.LASTsize )
  {
    result = (setT *)qh_memalloc(insize: 4 * v1 + 8);
  }
  else
  {
    v3 = qhmem.indextable[v2];
    result = (setT *)qhmem.freelists[v3];
    v5 = &qhmem.freelists[v3];
    if ( result != nullptr )
    {
      ++qhmem.cntquick;
      *v5 = *(void **)*v5;
    }
    else
    {
      result = (setT *)qh_memalloc(insize: 4 * v1 + 8);
    }
    v6 = qhmem.sizetable[qhmem.indextable[v2]];
    if ( v6 > v2 )
      v1 += (unsigned int)(v6 - v2) >> 2;
  }
  result->maxsize = v1;
  result->e[v1].i = 1;
  result->e[0].i = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004C9E0
// Name: void qh_setprint(struct _iobuf __near *,char const __near *,struct setT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_setprint(_iobuf *fp, const char *string, setT *set)
{
  setelemT v3; // esi
  int maxsize; // esi
  setelemT *e; // edi

  if ( fp != nullptr )
  {
    if ( set != nullptr )
    {
      v3.p = (void *)set->e[set->maxsize];
      if ( v3.i != 0 )
        maxsize = v3.i - 1;
      else
        maxsize = set->maxsize;
      fprintf(str: fp, format: "%s set=%p maxsize=%d size=%d elems=", string, set, set->maxsize, maxsize);
      if ( maxsize > set->maxsize )
        maxsize = set->maxsize + 1;
      if ( maxsize > 0 )
      {
        e = set->e;
        do
        {
          fprintf(str: fp, format: " %p", e->p);
          ++e;
          --maxsize;
        }
        while ( maxsize != 0 );
      }
      fprintf(str: fp, format: "\n");
    }
    else
    {
      fprintf(str: fp, format: "%s set is null\n", string);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004CA70
// Name: void qh_setreplace(struct setT __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_setreplace(setT *set, void *oldelem, void *newelem)
{
  setelemT *e; // eax

  e = set->e;
  if ( set->e[0].p != oldelem )
  {
    while ( e->i != 0 )
    {
      ++e;
      if ( e->p == oldelem )
        goto LABEL_4;
    }
LABEL_6:
    ivp_message(templat: "qhull internal error (qh_setreplace): elem %p not found in set\n", oldelem);
    qh_setprint(fp: qhmem.ferr, string: str, set);
    qh_errexit(exitcode: 5, facet: nullptr, ridge: nullptr);
  }
LABEL_4:
  if ( e->i == 0 )
    goto LABEL_6;
  e->i = (int)newelem;
}

//------------------------------------------------------------------------------
// Address: 0x1004CAD0
// Name: int qh_setsize(struct setT __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl qh_setsize(setT *set)
{
  int maxsize; // eax
  setelemT v3; // esi
  int v4; // esi

  if ( set == nullptr )
    return 0;
  maxsize = set->maxsize;
  v3.p = (void *)set->e[set->maxsize];
  if ( v3.i == 0 )
    return set->maxsize;
  v4 = v3.i - 1;
  if ( v4 > maxsize )
  {
    ivp_message(
      templat: "qhull internal error (qh_setsize): current set size %d is greater than maximum size %d\n",
      v4,
      maxsize);
    qh_setprint(fp: qhmem.ferr, string: "set: ", set);
    qh_errexit(exitcode: 5, facet: nullptr, ridge: nullptr);
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1004CB30
// Name: void qh_settempfree_all(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall qh_settempfree_all(setT *this)
{
  setT **v1; // esi
  setT *set; // [esp+0h] [ebp-4h] BYREF

  set = this;
  if ( qhmem.tempstack != nullptr )
  {
    v1 = (setT **)((char *)qhmem.tempstack + 4);
    for ( set = *((setT **)qhmem.tempstack + 1); set != nullptr; set = *v1 )
    {
      ++v1;
      qh_setfree(setp: &set);
    }
  }
  qh_setfree(setp: (setT **)&qhmem.tempstack);
}

//------------------------------------------------------------------------------
// Address: 0x1004CB80
// Name: struct setT __near * qh_settemppop(void)
// Source: json
//------------------------------------------------------------------------------
setT *__cdecl qh_settemppop()
{
  setT *v0; // eax
  setT *v1; // esi
  int v2; // eax
  int v4; // [esp-4h] [ebp-8h]

  v0 = (setT *)qh_setdellast(set: (setT *)qhmem.tempstack);
  v1 = v0;
  if ( v0 == nullptr )
  {
    ivp_message(templat: "qhull internal error (qh_settemppop): pop from empty temporary stack\n");
    qh_errexit(exitcode: 5, facet: nullptr, ridge: nullptr);
  }
  if ( qhmem.IStracing >= 5 )
  {
    v4 = qh_setsize(set: v0);
    v2 = qh_setsize(set: (setT *)qhmem.tempstack);
    ivp_message(templat: "qh_settemppop: depth %d temp set %p of %d elements\n", v2 + 1, v1, v4);
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x1004CBF0
// Name: void qh_settruncate(struct setT __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_settruncate(setT *set, int size)
{
  if ( size < 0 || size > set->maxsize )
  {
    ivp_message(templat: "qhull internal error (qh_settruncate): size %d out of bounds for set:\n", size);
    qh_setprint(fp: qhmem.ferr, string: str, set);
    qh_errexit(exitcode: 5, facet: nullptr, ridge: nullptr);
  }
  set->e[set->maxsize].i = size + 1;
  set->e[size].i = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1004CC50
// Name: void qh_setzero(struct setT __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_setzero(setT *set, int index, int size)
{
  if ( index < 0 || index >= size || size > set->maxsize )
  {
    ivp_message(templat: "qhull internal error (qh_setzero): index %d or size %d out of bounds for set:\n", index, size);
    qh_setprint(fp: qhmem.ferr, string: str, set);
    qh_errexit(exitcode: 5, facet: nullptr, ridge: nullptr);
  }
  set->e[set->maxsize].i = size + 1;
  memset(dst: (unsigned __int8 *)&set->e[index], value: 0, count: 4 * (size - index) + 4);
}

//------------------------------------------------------------------------------
// Address: 0x1004CCC0
// Name: void qh_setcheck(struct setT __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_setcheck(setT *set, const char *tname, int id)
{
  int maxsize; // ecx
  setelemT v4; // eax
  int v5; // eax

  if ( set != nullptr )
  {
    maxsize = set->maxsize;
    v4.p = (void *)set->e[set->maxsize];
    if ( v4.i != 0 )
      v5 = v4.i - 1;
    else
      v5 = set->maxsize;
    if ( v5 > maxsize || maxsize == 0 )
    {
      ivp_message(
        templat: "qhull internal error (qh_setcheck): actual size %d of %s%d is greater than max size %d\n",
        v5,
        tname,
        id,
        set->maxsize);
LABEL_10:
      qh_setprint(fp: qhmem.ferr, string: "ERRONEOUS", set);
      qh_errexit(exitcode: 5, facet: nullptr, ridge: nullptr);
    }
    if ( set->e[v5].i != 0 )
    {
      ivp_message(
        templat: "qhull internal error (qh_setcheck): %s%d (size %d max %d) is not null terminated.\n",
        tname,
        id,
        maxsize,
        v5 - 1);
      goto LABEL_10;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004CD40
// Name: void qh_setcompact(struct setT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_setcompact(setT *set)
{
  setelemT v1; // edx
  int maxsize; // edx
  setelemT *e; // ecx
  setelemT *v4; // eax
  setelemT *v5; // edi
  int i; // edx

  if ( set != nullptr )
  {
    v1.p = (void *)set->e[set->maxsize];
    if ( v1.i != 0 )
      maxsize = v1.i - 1;
    else
      maxsize = set->maxsize;
    e = set->e;
    v4 = set->e;
    v5 = &set->e[maxsize];
    do
    {
      do
      {
        i = e->i;
        v4->p = e->p;
        ++v4;
        ++e;
      }
      while ( i != 0 );
      --v4;
    }
    while ( e <= v5 );
    qh_settruncate(set, size: v4 - set->e);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004CD90
// Name: struct setT __near * qh_setcopy(struct setT __near *,int)
// Source: json
//------------------------------------------------------------------------------
setT *__cdecl qh_setcopy(setT *set, int extra)
{
  int v2; // ecx
  setelemT v3; // esi
  int maxsize; // esi
  setT *v5; // edi

  v2 = extra;
  if ( extra < 0 )
    v2 = 0;
  v3.p = (void *)set->e[set->maxsize];
  if ( v3.i != 0 )
    maxsize = v3.i - 1;
  else
    maxsize = set->maxsize;
  v5 = qh_setnew(setsize: maxsize + v2);
  v5->e[v5->maxsize].i = maxsize + 1;
  memcpy(dst: (unsigned __int8 *)v5->e, src: (unsigned __int8 *)set->e, count: 4 * maxsize + 4);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1004CDF0
// Name: void __near * qh_setdelnth(struct setT __near *,int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl qh_setdelnth(setT *set, int nth)
{
  setelemT *v2; // edi
  int v3; // eax
  void *result; // eax
  setelemT *v5; // ecx

  v2 = &set->e[set->maxsize];
  v3 = v2->i--;
  if ( v3 == 0 )
    v2->p = (void *)set->maxsize;
  if ( nth < 0 || nth >= v2->i )
  {
    ivp_message(templat: "qhull internal error (qh_setaddnth): nth %d is out-of-bounds for set:\n", nth);
    qh_setprint(fp: qhmem.ferr, string: str, set);
    qh_errexit(exitcode: 5, facet: nullptr, ridge: nullptr);
  }
  result = set->e[nth].p;
  v5 = (setelemT *)(&set->maxsize + v2->i);
  set->e[nth] = (setelemT)v5->p;
  v5->i = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004CE60
// Name: void __near * qh_setdelnthsorted(struct setT __near *,int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl qh_setdelnthsorted(setT *set, int nth)
{
  int maxsize; // ebx
  setelemT v3; // eax
  void *result; // eax
  setelemT *v5; // ecx
  void **v6; // esi
  void *v7; // edx
  setelemT v8; // ecx

  maxsize = set->maxsize;
  if ( nth < 0 || (v3.p = (void *)set->e[maxsize], v3.i != 0) && nth >= v3.i - 1 || nth >= maxsize )
  {
    ivp_message(templat: "qhull internal error (qh_setaddnth): nth %d is out-of-bounds for set:\n", nth);
    qh_setprint(fp: qhmem.ferr, string: str, set);
    qh_errexit(exitcode: 5, facet: nullptr, ridge: nullptr);
  }
  result = set->e[nth].p;
  v5 = &set->e[nth];
  v6 = (void **)(&set[1].maxsize + nth);
  do
  {
    v7 = *v6;
    v5->i = (int)*v6;
    ++v5;
    ++v6;
  }
  while ( v7 != nullptr );
  v8.p = (void *)set->e[maxsize];
  set->e[maxsize].i = v8.i - 1;
  if ( v8.i == 0 )
    set->e[maxsize].i = set->maxsize;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004CEE0
// Name: void qh_setlarger(struct setT __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_setlarger(setT **oldsetp)
{
  setT *v1; // ebx
  setelemT v2; // esi
  int maxsize; // esi
  setT *v4; // edi
  setT *v5; // eax
  setT **v6; // ecx

  v1 = *oldsetp;
  if ( *oldsetp != nullptr )
  {
    v2.p = (void *)v1->e[v1->maxsize];
    if ( v2.i != 0 )
      maxsize = v2.i - 1;
    else
      maxsize = v1->maxsize;
    ++qhmem.cntlarger;
    qhmem.totlarger += maxsize + 1;
    v4 = qh_setnew(setsize: 2 * maxsize);
    memcpy(dst: (unsigned __int8 *)v4->e, src: (unsigned __int8 *)v1->e, count: 4 * maxsize + 4);
    v4->e[v4->maxsize].i = maxsize + 1;
    if ( qhmem.tempstack != nullptr )
    {
      v5 = *((setT **)qhmem.tempstack + 1);
      v6 = (setT **)((char *)qhmem.tempstack + 4);
      if ( v5 != nullptr )
      {
        do
        {
          ++v6;
          if ( v5 == v1 )
            *(v6 - 1) = v4;
          v5 = *v6;
        }
        while ( *v6 != nullptr );
      }
    }
    qh_setfree(setp: oldsetp);
    *oldsetp = v4;
  }
  else
  {
    *oldsetp = qh_setnew(setsize: 3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004CFA0
// Name: struct setT __near * qh_setnew_delnthsorted(struct setT __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
setT *__cdecl qh_setnew_delnthsorted(setT *set, setT *size, int nth, int prepend)
{
  setT *result; // eax
  setT *e; // edi
  setelemT *v7; // esi
  unsigned int v8; // ebx
  setelemT *v9; // edi
  setT *newset; // [esp+18h] [ebp+Ch]
  int tailsize; // [esp+1Ch] [ebp+10h]

  tailsize = (int)size - nth - 1;
  if ( tailsize < 0 )
  {
    ivp_message(templat: "qhull internal error (qh_setaddnth): nth %d is out-of-bounds for set:\n", nth);
    qh_setprint(fp: qhmem.ferr, string: str, set);
    qh_errexit(exitcode: 5, facet: nullptr, ridge: nullptr);
  }
  result = qh_setnew(setsize: (int)size + prepend - 1);
  e = (setT *)set->e;
  result->e[result->maxsize].i = (int)size + prepend;
  newset = result;
  v7 = &result->e[prepend];
  switch ( nth )
  {
    case 0:
      break;
    case 1:
      v7->p = (void *)e->maxsize;
      v7 = (setelemT *)(&result[1].maxsize + prepend);
      e = set + 1;
      break;
    case 2:
      v7->p = (void *)e->maxsize;
      *(&result[1].maxsize + prepend) = set[1].maxsize;
      v7 = &result[1].e[prepend];
      e = (setT *)((char *)set + 12);
      break;
    case 3:
      v7->p = (void *)e->maxsize;
      *(setT *)((char *)result + 4 * prepend + 8) = set[1];
      v7 = (setelemT *)(&result[2].maxsize + prepend);
      e = set + 2;
      break;
    case 4:
      v7->p = (void *)e->maxsize;
      *(setT *)((char *)result + 4 * prepend + 8) = set[1];
      *(&result[2].maxsize + prepend) = set[2].maxsize;
      v7 = &result[2].e[prepend];
      e = (setT *)((char *)set + 20);
      break;
    default:
      v8 = 4 * nth;
      memcpy(dst: (unsigned __int8 *)&result->e[prepend], src: (unsigned __int8 *)e, count: v8);
      result = newset;
      v7 = (setelemT *)((char *)v7 + v8);
      e = (setT *)((char *)e + v8);
      break;
  }
  v9 = e->e;
  switch ( tailsize )
  {
    case 0:
      goto $LN7_5;
    case 1:
      v7->p = v9->p;
      v7[1].i = 0;
      break;
    case 2:
      v7->p = v9->p;
      v7[1].p = v9[1].p;
      v7[2].i = 0;
      break;
    case 3:
      v7->p = v9->p;
      v7[1].p = v9[1].p;
      v7[2].p = v9[2].p;
      v7[3].i = 0;
      break;
    case 4:
      v7->p = v9->p;
      v7[1].p = v9[1].p;
      v7[2].p = v9[2].p;
      v7[3].p = v9[3].p;
      v7[4].i = 0;
      break;
    default:
      memcpy(dst: (unsigned __int8 *)v7, src: (unsigned __int8 *)v9, count: 4 * tailsize);
      result = newset;
      v7 += tailsize;
$LN7_5:
      v7->i = 0;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004D150
// Name: void qh_setaddnth(struct setT __near * __near *,int,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_setaddnth(setT **setp, int nth, void *newelem)
{
  setT *v3; // edi
  bool v4; // zf
  setelemT *v5; // edi
  int v6; // esi
  setelemT *v7; // eax
  int v8; // esi
  setelemT *v9; // ecx

  v3 = *setp;
  if ( *setp == nullptr || (v4 = v3->e[v3->maxsize].i == 0, v5 = &v3->e[v3->maxsize], v4) )
  {
    qh_setlarger(oldsetp: setp);
    v5 = &(*setp)->e[(*setp)->maxsize];
  }
  v6 = v5->i - 1;
  if ( nth < 0 || nth > v6 )
  {
    ivp_message(templat: "qhull internal error (qh_setaddnth): nth %d is out-of-bounds for set:\n", nth);
    qh_setprint(fp: qhmem.ferr, string: str, set: *setp);
    qh_errexit(exitcode: 5, facet: nullptr, ridge: nullptr);
  }
  ++v5->i;
  v7 = &(*setp)->e[v6];
  v8 = v6 - nth + 1;
  v9 = v7 + 1;
  if ( v8 != 0 )
  {
    do
    {
      v9->p = v7->p;
      --v9;
      --v7;
      --v8;
    }
    while ( v8 != 0 );
    v9->i = (int)newelem;
  }
  else
  {
    v9->i = (int)newelem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004D1F0
// Name: void qh_setappend(struct setT __near * __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_setappend(setT **setp, void *newelem)
{
  setT *v2; // eax
  setelemT *v3; // ecx
  int *v4; // eax

  if ( newelem != nullptr )
  {
    v2 = *setp;
    if ( *setp == nullptr || (v3 = &v2->e[v2->maxsize])->i == 0 )
    {
      qh_setlarger(oldsetp: setp);
      v2 = *setp;
      v3 = &(*setp)->e[(*setp)->maxsize];
    }
    v4 = &v2->maxsize + v3->i;
    *v4 = (int)newelem;
    ++v3->i;
    v4[1] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004D240
// Name: void qh_setappend_set(struct setT __near * __near *,struct setT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_setappend_set(setT **setp, setT *setA)
{
  setelemT v2; // esi
  int maxsize; // esi
  setT *v4; // eax
  int v5; // ecx
  setelemT v6; // ebx
  int v7; // ebx
  setT *v8; // eax
  setT *oldset; // [esp+0h] [ebp-4h] BYREF

  if ( setA != nullptr )
  {
    v2.p = (void *)setA->e[setA->maxsize];
    if ( v2.i != 0 )
      maxsize = v2.i - 1;
    else
      maxsize = setA->maxsize;
    if ( *setp == nullptr )
      *setp = qh_setnew(setsize: maxsize);
    v4 = *setp;
    v5 = (*setp)->maxsize;
    v6.p = (void *)(*setp)->e[v5];
    oldset = (setT *)&(*setp)->e[v5];
    if ( v6.i != 0 )
      v7 = v6.i - 1;
    else
      v7 = v5;
    if ( v7 + maxsize <= v5 )
    {
      v8 = oldset;
    }
    else
    {
      oldset = v4;
      *setp = qh_setcopy(set: v4, extra: maxsize);
      qh_setfree(setp: &oldset);
      v8 = (setT *)&(*setp)->e[(*setp)->maxsize];
    }
    v8->maxsize = v7 + maxsize + 1;
    if ( maxsize > 0 )
      memcpy(dst: (unsigned __int8 *)&(*setp)->e[v7], src: (unsigned __int8 *)setA->e, count: 4 * maxsize + 4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004D2F0
// Name: void qh_setappend2ndlast(struct setT __near * __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_setappend2ndlast(setT **setp, void *newelem)
{
  setT *v2; // eax
  setelemT *v3; // edx
  int v4; // ecx

  v2 = *setp;
  if ( *setp == nullptr || (v3 = &v2->e[v2->maxsize])->i == 0 )
  {
    qh_setlarger(oldsetp: setp);
    v2 = *setp;
    v3 = &(*setp)->e[(*setp)->maxsize];
  }
  v4 = v3->i++;
  *(&v2->maxsize + v4) = *((_DWORD *)v2 + v4 - 1);
  v2->e[v4].i = 0;
  *((_DWORD *)v2 + v4 - 1) = newelem;
}

//------------------------------------------------------------------------------
// Address: 0x1004D340
// Name: struct setT __near * qh_settemp(int)
// Source: json
//------------------------------------------------------------------------------
setT *__cdecl qh_settemp(int setsize)
{
  setT *v1; // esi
  int v2; // eax

  v1 = qh_setnew(setsize);
  qh_setappend(setp: (setT **)&qhmem.tempstack, newelem: v1);
  if ( qhmem.IStracing >= 5 )
  {
    v2 = qh_setsize(set: (setT *)qhmem.tempstack);
    ivp_message(templat: "qh_settemp: temp set %p of %d elements, depth %d\n", v1, v1->maxsize, v2);
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x1004D390
// Name: void qh_settemppush(struct setT __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_settemppush(setT *set)
{
  int v1; // eax
  int v2; // [esp-4h] [ebp-8h]

  qh_setappend(setp: (setT **)&qhmem.tempstack, newelem: set);
  if ( qhmem.IStracing >= 5 )
  {
    v2 = qh_setsize(set);
    v1 = qh_setsize(set: (setT *)qhmem.tempstack);
    ivp_message(templat: "qh_settemppush: depth %d temp set %p of %d elements\n", v1, set, v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004D3E0
// Name: int qh_setunique(struct setT __near * __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl qh_setunique(setT **set, void *elem)
{
  if ( qh_setin(set: *set, setelem: elem) != 0 )
    return 0;
  qh_setappend(setp: set, newelem: elem);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1004D420
// Name: void qh_settempfree(struct setT __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl qh_settempfree(setT **set)
{
  setT *v1; // eax
  setT *v2; // esi
  int v3; // eax
  int v4; // [esp-10h] [ebp-14h]
  int v5; // [esp-8h] [ebp-Ch]

  if ( *set != nullptr )
  {
    v1 = qh_settemppop();
    v2 = v1;
    if ( v1 != *set )
    {
      qh_settemppush(set: v1);
      v5 = qh_setsize(set: v2);
      v4 = qh_setsize(set: (setT *)qhmem.tempstack) + 1;
      v3 = qh_setsize(set: *set);
      ivp_message(
        templat: "qhull internal error (qh_settempfree): set %p (size %d) was not last temporary allocated (depth %d, set %p, size %d)\n",
        *set,
        v3,
        v4,
        v2,
        v5);
      qh_errexit(exitcode: 5, facet: nullptr, ridge: nullptr);
    }
    qh_setfree(setp: set);
  }
}
