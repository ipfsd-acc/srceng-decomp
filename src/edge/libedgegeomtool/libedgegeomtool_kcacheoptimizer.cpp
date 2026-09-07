// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: edge/libedgegeomtool/libedgegeomtool_kcacheoptimizer.cpp
// Functions: 9
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1000D010
// Name: FindAdjacentTriangles
// Source: json
//------------------------------------------------------------------------------
void __usercall FindAdjacentTriangles(
        const CUtlRBTree<CUtlMap<unsigned char *,int,unsigned int>::Node_t,unsigned int,CUtlMap<unsigned char *,int,unsigned int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned char *,int,unsigned int>::Node_t,unsigned int>,unsigned int> > *context@<esi>,
        int a2@<eax>,
        unsigned int *triangleList)
{
  unsigned int v3; // ebp
  unsigned int v4; // ebx
  unsigned int v5; // edx
  unsigned int i; // eax
  unsigned int j; // ecx
  unsigned int v8; // ebp
  unsigned int v9; // eax
  int m_nAllocationCount; // edx
  unsigned int v11; // ecx
  unsigned int v12; // edx
  _DWORD *v13; // edi
  unsigned int v14; // edx
  bool v15; // cf
  tagIDLDESC numIndexes; // [esp+8h] [ebp-14h] BYREF
  std::exception pExceptionObject; // [esp+10h] [ebp-Ch] BYREF

  v3 = (unsigned int)context->m_LessFunc.m_LessFunc + 2;
  *(_DWORD *)&numIndexes.wIDLFlags = 3 * a2;
  v4 = 12 * a2;
  context->m_Elements.m_nAllocationCount = (int)edgeGeomAllocEx(
                                                  allocSize: 4 * v3,
                                                  a2: ".\\libedgegeomtool_partitioner.cpp",
                                                  lineNumber: 0x1F8u);
  context->m_Elements.m_nGrowSize = (int)edgeGeomAllocEx(
                                           allocSize: v4,
                                           a2: ".\\libedgegeomtool_partitioner.cpp",
                                           lineNumber: 0x1F9u);
  memset(dst: (unsigned __int8 *)context->m_Elements.m_nAllocationCount, value: 0, count: 4 * v3);
  memset(dst: (unsigned __int8 *)context->m_Elements.m_nGrowSize, value: 0xFFu, count: v4);
  v5 = *(_DWORD *)&numIndexes.wIDLFlags;
  for ( i = 0; i < v5; ++i )
    ++*(_DWORD *)(context->m_Elements.m_nAllocationCount + 4 * triangleList[i] + 4);
  for ( j = 1; j < v3; ++j )
    *(_DWORD *)(context->m_Elements.m_nAllocationCount + 4 * j) += *(_DWORD *)(context->m_Elements.m_nAllocationCount
                                                                             + 4 * j
                                                                             - 4);
  v8 = 0;
  if ( v5 != 0 )
  {
    do
    {
      v9 = triangleList[v8];
      m_nAllocationCount = context->m_Elements.m_nAllocationCount;
      v11 = *(_DWORD *)(m_nAllocationCount + 4 * v9);
      v12 = *(_DWORD *)(m_nAllocationCount + 4 * v9 + 4);
      if ( v11 >= v12 )
        goto LABEL_13;
      v13 = (_DWORD *)(context->m_Elements.m_nGrowSize + 4 * v11);
      do
      {
        if ( *v13 == -1 )
          break;
        ++v11;
        ++v13;
      }
      while ( v11 < *(_DWORD *)(context->m_Elements.m_nAllocationCount + 4 * v9 + 4) );
      if ( v11 >= v12 )
      {
LABEL_13:
        *(_DWORD *)&numIndexes.wIDLFlags = ".\\libedgegeomtool_partitioner.cpp(542)";
        std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&numIndexes.wIDLFlags);
        _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI1_AVexception_std__);
      }
      v14 = v8 / 3;
      v15 = ++v8 < *(_DWORD *)&numIndexes.wIDLFlags;
      *(_DWORD *)(context->m_Elements.m_nGrowSize + 4 * v11) = v14;
    }
    while ( v15 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000ED20
// Name: FindAdjacentTriangles_0
// Source: json
//------------------------------------------------------------------------------
void __usercall FindAdjacentTriangles_0(
        int a1@<eax>,
        int a2@<ecx>,
        unsigned __int8 *adjacentFacesPerVertex,
        unsigned __int8 *adjacencyDataStarts,
        tagIDLDESC numVertexes)
{
  unsigned int dwReserved; // ebp
  unsigned __int8 *v6; // edi
  _DWORD *v9; // eax
  _DWORD *v10; // edx
  _DWORD *v11; // ecx
  int *v12; // eax
  char *v13; // ebp
  int v14; // ebx
  int v15; // edx
  int v16; // edi
  unsigned int i; // ecx
  int v18; // eax
  unsigned int j; // eax
  unsigned int k; // esi
  int v21; // eax
  unsigned int v22; // eax
  _DWORD *numIndexes; // [esp+10h] [ebp-14h]
  unsigned int numIndexes_4; // [esp+14h] [ebp-10h]
  std::exception pExceptionObject; // [esp+18h] [ebp-Ch] BYREF

  dwReserved = numVertexes.dwReserved;
  v6 = adjacencyDataStarts;
  memset(dst: adjacencyDataStarts, value: 0, count: 4 * numVertexes.dwReserved);
  memset(dst: adjacentFacesPerVertex, value: 0xFFu, count: 12 * a1);
  numIndexes_4 = 3 * a1;
  v9 = edgeGeomAllocEx(allocSize: 12 * a1, a2: ".\\libedgegeomtool_kcacheoptimizer.cpp", lineNumber: 0x32u);
  v10 = v9;
  numIndexes = v9;
  if ( a1 != 0 )
  {
    v11 = v9;
    v12 = (int *)(a2 + 8);
    v13 = (char *)v10 - a2;
    do
    {
      v14 = *(v12 - 2);
      v15 = *(v12 - 1);
      v16 = *v12;
      if ( v15 == v14 )
        v15 = -1;
      if ( v16 == v14 || v16 == v15 )
        v16 = -1;
      *v11 = v14;
      v11[1] = v15;
      *(_DWORD *)&v13[(_DWORD)v12] = v16;
      v12 += 3;
      v11 += 3;
      --a1;
    }
    while ( a1 != 0 );
    v6 = adjacencyDataStarts;
    dwReserved = numVertexes.dwReserved;
    v10 = numIndexes;
  }
  for ( i = 0; i < numIndexes_4; ++i )
  {
    v18 = v10[i];
    if ( v18 != -1 )
      ++*(_DWORD *)&v6[4 * v18 + 4];
  }
  for ( j = 1; j < dwReserved; ++j )
  {
    i = *(_DWORD *)&v6[4 * j - 4];
    *(_DWORD *)&v6[4 * j] += i;
  }
  for ( k = 0; k < numIndexes_4; ++k )
  {
    v21 = v10[k];
    if ( v21 != -1 )
    {
      i = *(_DWORD *)&v6[4 * v21];
      v22 = *(_DWORD *)&v6[4 * v21 + 4];
      if ( i >= v22 )
        goto LABEL_26;
      do
      {
        if ( *(_DWORD *)&adjacentFacesPerVertex[4 * i] == -1 )
          break;
        ++i;
      }
      while ( i < v22 );
      if ( i >= v22 )
      {
LABEL_26:
        numVertexes.dwReserved = (unsigned int)".\\libedgegeomtool_kcacheoptimizer.cpp(98)";
        std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&numVertexes);
        _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI1_AVexception_std__);
      }
      if ( i >= numIndexes_4 )
      {
        numVertexes.dwReserved = (unsigned int)".\\libedgegeomtool_kcacheoptimizer.cpp(99)";
        std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&numVertexes);
        _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI1_AVexception_std__);
      }
      *(_DWORD *)&adjacentFacesPerVertex[4 * i] = k / 3;
      v10 = numIndexes;
    }
  }
  numVertexes.dwReserved = 105;
  edgeGeomFreeEx(this: (VectorByValue *)i);
}

//------------------------------------------------------------------------------
// Address: 0x1000EEC0
// Name: PushTriangle
// Source: json
//------------------------------------------------------------------------------
double __usercall PushTriangle@<st0>(
        _DWORD *a1@<eax>,
        ILoggingListener *fifoStarta,
        unsigned int fifoMisses,
        int i,
        void (__thiscall **a5)(ILoggingListener *this, const LoggingContext_t *, const char *),
        float kFifoMiss,
        float kLruMiss)
{
  _DWORD *v8; // ebx
  _DWORD *v9; // ebp
  ILoggingListener_vtbl *v10; // edx
  ILoggingListener *v11; // edi
  ILoggingListener_vtbl *v12; // ecx
  bool v13; // cc
  unsigned int v14; // esi
  void (__thiscall *v15)(ILoggingListener *, const LoggingContext_t *, const char *); // ebx
  void (__thiscall *Log)(ILoggingListener *, const LoggingContext_t *, const char *); // edi
  int v17; // edx
  void (__thiscall **v18)(ILoggingListener *, const LoggingContext_t *, const char *); // ebx
  char *hreftype; // esi
  unsigned int v20; // edx
  int v21; // edx
  int v22; // ecx
  int v23; // edx
  char v24; // al
  unsigned int j; // ecx
  _DWORD *v26; // eax
  unsigned int v28; // [esp+10h] [ebp-1Ch]
  void (__thiscall *v29)(ILoggingListener *, const LoggingContext_t *, const char *); // [esp+14h] [ebp-18h]
  tagELEMDESC position; // [esp+1Ch] [ebp-10h] BYREF

  v8 = (_DWORD *)i;
  v9 = (_DWORD *)fifoMisses;
  v10 = *(ILoggingListener_vtbl **)fifoMisses;
  v11 = fifoStarta;
  v12 = fifoStarta->__vftable;
  v13 = fifoStarta->__vftable <= (ILoggingListener_vtbl *)*(_DWORD *)fifoMisses;
  v28 = 0;
  fifoMisses = 0;
  memset(&position.tdesc.vt, 0, 12);
  v14 = 1;
  if ( v13 )
  {
    v29 = *a5;
    v15 = a5[1];
    position.tdesc.hreftype = (unsigned int)a5[2];
    do
    {
      Log = v12->Log;
      if ( v12->Log == v29 )
        *(_DWORD *)&position.tdesc.vt = v14;
      if ( Log == v15 )
        position.idldesc.dwReserved = v14;
      if ( Log == (void (__thiscall *)(ILoggingListener *, const LoggingContext_t *, const char *))position.tdesc.lptdesc )
        *(_DWORD *)&position.paramdesc.wParamFlags = v14;
      ++v12;
      ++v14;
    }
    while ( v12 <= v10 );
    v11 = fifoStarta;
    v8 = (_DWORD *)i;
  }
  *a1 = *v8;
  a1[1] = v8[1];
  a1[2] = v8[2];
  v17 = v8[3];
  v18 = a5;
  hreftype = (char *)((char *)&position.tdesc.vt - (char *)a5);
  a1[3] = v17;
  position.tdesc.hreftype = (unsigned int)hreftype;
  for ( i = 3; i != 0; --i )
  {
    v20 = 0;
    while ( (void (__thiscall *)(ILoggingListener *, const LoggingContext_t *, const char *))a1[v20] != *v18 )
    {
      if ( ++v20 >= 4 )
        goto LABEL_19;
    }
    if ( v20 < 3 )
    {
      qmemcpy(&a1[v20], &a1[v20 + 1], 4 * (3 - v20));
      v11 = fifoStarta;
      hreftype = (char *)position.tdesc.hreftype;
    }
    a1[3] = *v18;
    *(void (__thiscall **)(ILoggingListener *, const LoggingContext_t *, const char *))((char *)v18 + (_DWORD)hreftype) = (void (__thiscall *)(ILoggingListener *, const LoggingContext_t *, const char *))23;
LABEL_19:
    if ( (void (__thiscall *)(ILoggingListener *, const LoggingContext_t *, const char *))a1[3] != *v18 )
    {
      v21 = a1[2];
      ++v28;
      *a1 = a1[1];
      v22 = a1[3];
      a1[1] = v21;
      a1[2] = v22;
      a1[3] = *v18;
    }
    ++v18;
  }
  if ( *(_DWORD *)&position.tdesc.vt < 3u
    || position.idldesc.dwReserved < 3
    || *(_DWORD *)&position.paramdesc.wParamFlags < 3u )
  {
    v23 = (char *)a5 - (char *)&position.tdesc.vt;
    do
    {
      v24 = 0;
      for ( j = 0; j < 3; ++j )
      {
        if ( *((_DWORD *)&position.tdesc.vt + j) <= fifoMisses )
        {
          ++v11->__vftable;
          *v9 += 4;
          v26 = (_DWORD *)*v9;
          ++fifoMisses;
          *v26 = *(_DWORD *)((char *)&position.tdesc.vt + 4 * j + v23);
          v24 = 1;
          *((_DWORD *)&position.tdesc.vt + j) = 23;
        }
      }
    }
    while ( v24 != 0 );
    if ( fifoMisses > 3 )
      goto LABEL_34;
  }
  if ( v28 > 3 )
  {
LABEL_34:
    *(float *)&fifoStarta = COERCE_FLOAT(".\\libedgegeomtool_kcacheoptimizer.cpp(198)");
    std::exception::exception(this: (std::exception *)&position.tdesc.vt, _What: (const char *const *)&fifoStarta);
    _CxxThrowException(pExceptionObject: &position.tdesc.vt, pThrowInfo: &_TI1_AVexception_std__);
  }
  *(float *)&fifoStarta = (double)fifoMisses * kFifoMiss + (double)v28 * kLruMiss;
  return *(float *)&fifoStarta;
}

//------------------------------------------------------------------------------
// Address: 0x1000F0B0
// Name: RotateAndPushTriangle
// Source: json
//------------------------------------------------------------------------------
void __usercall RotateAndPushTriangle(
        int a1@<edi>,
        ILoggingListener *fifoEnd,
        ILoggingListener *fifoEnda,
        int a4,
        unsigned int *destLru,
        float kFifoMiss,
        float kLruMiss)
{
  int v8; // ecx
  int v9; // edx
  int *v10; // esi
  unsigned int *v11; // ebx
  unsigned int i; // ecx
  int v13; // eax
  int *v14; // eax
  int v15; // ecx
  int v16; // edx
  int v17; // eax
  unsigned int *bestTri; // [esp+14h] [ebp-20h]
  int *v19; // [esp+18h] [ebp-1Ch]
  int newTri; // [esp+1Ch] [ebp-18h]
  _DWORD v21[5]; // [esp+20h] [ebp-14h] BYREF

  v8 = *(_DWORD *)(a1 + 4);
  v9 = *(_DWORD *)(a1 + 8);
  v21[0] = *(_DWORD *)a1;
  v21[3] = v21[0];
  v21[1] = v8;
  v21[2] = v9;
  v21[4] = v8;
  v19 = v21;
  bestTri = nullptr;
  v10 = v21;
  for ( newTri = 3; newTri != 0; --newTri )
  {
    v11 = nullptr;
    for ( i = 0; i < 3; ++i )
    {
      v13 = 0;
      while ( *(_DWORD *)(a4 + 4 * v13) != v10[i] )
      {
        if ( (unsigned int)++v13 >= 4 )
          goto LABEL_8;
      }
      v11 = (unsigned int *)((char *)v11 + (3 - i) * (4 - v13));
LABEL_8:
      ;
    }
    if ( v11 <= bestTri )
    {
      v14 = v19;
    }
    else
    {
      v14 = v10;
      v19 = v10;
      bestTri = v11;
    }
    ++v10;
  }
  v15 = *v14;
  v16 = v14[1];
  v17 = v14[2];
  *(_DWORD *)a1 = v15;
  *(_DWORD *)(a1 + 4) = v16;
  *(_DWORD *)(a1 + 8) = v17;
  PushTriangle(
    a1: destLru,
    fifoStarta: fifoEnd,
    fifoMisses: (unsigned int)fifoEnda,
    i: a4,
    a5: (void (__thiscall **)(ILoggingListener *, const LoggingContext_t *, const char *))a1,
    kFifoMiss,
    kLruMiss);
}

//------------------------------------------------------------------------------
// Address: 0x1000F190
// Name: PushFocusVertex
// Source: json
//------------------------------------------------------------------------------
double __usercall PushFocusVertex@<st0>(
        unsigned int a1@<eax>,
        int a2@<ecx>,
        char **head,
        ILoggingListener *tail,
        unsigned int *lru,
        char *triangleIsAvailable,
        int a7,
        ILoggingListener *outTriangles,
        char *kFifoMiss,
        float kLruMiss,
        bool commitChanges)
{
  _DWORD *v13; // eax
  unsigned int *v14; // edx
  unsigned int v15; // ecx
  int v16; // esi
  unsigned int v17; // edi
  unsigned int v18; // ebx
  const _s__RTTIBaseClassDescriptor2 *v19; // ebp
  int v20; // ebp
  int v21; // ebx
  int v22; // esi
  unsigned int *v23; // edx
  int v24; // eax
  const char *v25; // ecx
  int v26; // edx
  int v27; // eax
  std::exception_vtbl *v28; // ecx
  const char *v29; // edx
  int v30; // eax
  unsigned int v31; // esi
  unsigned int v32; // edi
  unsigned int v33; // ebx
  std::exception_vtbl *v34; // edx
  int v35; // eax
  unsigned int *v36; // ecx
  const _s__RTTIBaseClassDescriptor2 *v37; // edx
  unsigned int *triangles; // [esp+18h] [ebp-48h]
  _DWORD *totalCost; // [esp+1Ch] [ebp-44h]
  float bestScore; // [esp+20h] [ebp-40h]
  float v42; // [esp+24h] [ebp-3Ch]
  unsigned int *currentTail; // [esp+28h] [ebp-38h] BYREF
  unsigned int *currentHead; // [esp+2Ch] [ebp-34h] BYREF
  char *_What; // [esp+30h] [ebp-30h] BYREF
  std::exception pExceptionObject; // [esp+34h] [ebp-2Ch] BYREF
  unsigned int fifoStart; // [esp+40h] [ebp-20h] BYREF
  unsigned int v48; // [esp+44h] [ebp-1Ch]
  unsigned int v49; // [esp+48h] [ebp-18h]
  const _s__RTTIBaseClassDescriptor2 *tmpLru; // [esp+4Ch] [ebp-14h]
  unsigned int v51; // [esp+50h] [ebp-10h] BYREF
  unsigned int v52; // [esp+54h] [ebp-Ch]
  unsigned int v53; // [esp+58h] [ebp-8h]
  const _s__RTTIBaseClassDescriptor2 *v54; // [esp+5Ch] [ebp-4h]

  v13 = edgeGeomAllocEx(allocSize: 4 * a1, a2: ".\\libedgegeomtool_kcacheoptimizer.cpp", lineNumber: 0x119u);
  v14 = nullptr;
  v15 = 0;
  totalCost = v13;
  if ( a1 == 0 )
    goto LABEL_6;
  do
  {
    v16 = *(_DWORD *)(a2 + 4 * v15);
    if ( triangleIsAvailable[v16] != 0 )
    {
      v13[(_DWORD)v14] = v16;
      v14 = (unsigned int *)((char *)v14 + 1);
    }
    ++v15;
  }
  while ( v15 < a1 );
  triangles = v14;
  if ( v14 == nullptr )
  {
LABEL_6:
    currentTail = (unsigned int *)".\\libedgegeomtool_kcacheoptimizer.cpp(295)";
    std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&currentTail);
    _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI1_AVexception_std__);
  }
  bestScore = 0.0;
  v17 = lru[1];
  v18 = lru[2];
  v19 = (const _s__RTTIBaseClassDescriptor2 *)lru[3];
  fifoStart = *lru;
  v48 = v17;
  v49 = v18;
  tmpLru = v19;
  currentTail = &v13[(_DWORD)v14 - 1];
  do
  {
    v20 = -1;
    v21 = 0;
    v42 = 3.4028235e38;
    while ( 1 )
    {
      v22 = v13[v21];
      v23 = (unsigned int *)tail->__vftable;
      _What = *head;
      currentHead = v23;
      v24 = a7 + 12 * v22;
      v25 = *(const char **)(v24 + 4);
      pExceptionObject.__vftable = *(std::exception_vtbl **)v24;
      v26 = *(_DWORD *)(v24 + 8);
      pExceptionObject._Mywhat = v25;
      *(_DWORD *)&pExceptionObject._Mydofree = v26;
      RotateAndPushTriangle(
        a1: (int)&pExceptionObject,
        fifoEnd: (ILoggingListener *)&_What,
        fifoEnda: (ILoggingListener *)&currentHead,
        a4: (int)&fifoStart,
        destLru: &v51,
        kFifoMiss: *(float *)&kFifoMiss,
        kLruMiss);
      _What = kFifoMiss;
      if ( v42 > (double)*(float *)&kFifoMiss )
      {
        v42 = *(float *)&_What;
        v20 = v22;
      }
      if ( ++v21 >= (unsigned int)triangles )
        break;
      v13 = totalCost;
    }
    if ( v20 == -1 )
    {
      *(float *)&_What = COERCE_FLOAT(".\\libedgegeomtool_kcacheoptimizer.cpp(333)");
      std::exception::exception(this: &pExceptionObject, (const char *const *)&_What);
      _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI1_AVexception_std__);
    }
    v27 = a7 + 12 * v20;
    v28 = *(std::exception_vtbl **)v27;
    v29 = *(const char **)(v27 + 4);
    v30 = *(_DWORD *)(v27 + 8);
    pExceptionObject.__vftable = v28;
    pExceptionObject._Mywhat = v29;
    *(_DWORD *)&pExceptionObject._Mydofree = v30;
    RotateAndPushTriangle(
      a1: (int)&pExceptionObject,
      fifoEnd: (ILoggingListener *)head,
      fifoEnda: tail,
      a4: (int)&fifoStart,
      destLru: &v51,
      kFifoMiss: *(float *)&kFifoMiss,
      kLruMiss);
    v31 = v51;
    v32 = v52;
    v33 = v53;
    bestScore = *(float *)&kFifoMiss + bestScore;
    fifoStart = v51;
    v48 = v52;
    v49 = v53;
    tmpLru = v54;
    if ( commitChanges )
    {
      v34 = pExceptionObject.__vftable;
      triangleIsAvailable[v20] = 0;
      outTriangles->Log = (void (__thiscall *)(ILoggingListener *, const LoggingContext_t *, const char *))v34;
      ++outTriangles->__vftable;
      outTriangles->Log = (void (__thiscall *)(ILoggingListener *, const LoggingContext_t *, const char *))pExceptionObject._Mywhat;
      ++outTriangles->__vftable;
      outTriangles->Log = *(void (__thiscall **)(ILoggingListener *, const LoggingContext_t *, const char *))&pExceptionObject._Mydofree;
      ++outTriangles->__vftable;
    }
    v35 = 0;
    while ( totalCost[v35] != v20 )
    {
      if ( ++v35 >= (unsigned int)triangles )
      {
        *(float *)&_What = COERCE_FLOAT(".\\libedgegeomtool_kcacheoptimizer.cpp(362)");
        std::exception::exception(this: &pExceptionObject, (const char *const *)&_What);
        _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI1_AVexception_std__);
      }
    }
    v36 = currentTail;
    totalCost[v35] = *currentTail;
    triangles = (unsigned int *)((char *)triangles - 1);
    currentTail = v36 - 1;
    v13 = totalCost;
  }
  while ( triangles != nullptr );
  if ( commitChanges )
  {
    v37 = tmpLru;
    *lru = v31;
    lru[1] = v32;
    lru[2] = v33;
    lru[3] = (unsigned int)v37;
  }
  edgeGeomFreeEx(this: (VectorByValue *)lru);
  return bestScore;
}

//------------------------------------------------------------------------------
// Address: 0x1000F470
// Name: ChooseBestVertex
// Source: json
//------------------------------------------------------------------------------
void __usercall ChooseBestVertex(
        IUnknown *a1@<eax>,
        char *a2@<ebx>,
        IUnknown *result,
        float *a4,
        _DWORD *bestIndex,
        int bestIndex_4,
        int a7,
        unsigned int *fifoStart,
        unsigned int *fifoEnd,
        unsigned int *lru,
        int a11,
        float kFifoMiss,
        float kLruMiss,
        float a14,
        float a15,
        float a16)
{
  int v16; // edi
  IUnknown *v17; // ecx
  double v18; // st7
  double v19; // st6
  IUnknown_vtbl *v20; // esi
  int v21; // edx
  int v22; // ecx
  int v23; // eax
  unsigned int v24; // edi
  unsigned int v25; // eax
  unsigned int v26; // edx
  unsigned int *v27; // eax
  unsigned int i; // ecx
  double v29; // st5
  float v30; // [esp+0h] [ebp-28h]
  float v31; // [esp+4h] [ebp-24h]
  unsigned int *tail; // [esp+18h] [ebp-10h] BYREF
  ILoggingListener v33; // [esp+1Ch] [ebp-Ch] BYREF
  IUnknown *totalCost; // [esp+20h] [ebp-8h]
  float v35; // [esp+24h] [ebp-4h]

  v16 = a7;
  v17 = a1;
  totalCost = a1;
  if ( a1 <= result )
  {
    v18 = kLruMiss;
    v19 = kFifoMiss;
    while ( 1 )
    {
      v20 = v17->__vftable;
      if ( v17->__vftable != (IUnknown_vtbl *)-1 )
      {
        v21 = *(_DWORD *)(v16 + 4 * (_DWORD)v20);
        v22 = bestIndex_4 + 4 * v21;
        v23 = *(_DWORD *)(v16 + 4 * (_DWORD)v20 + 4);
        v24 = 0;
        v25 = v23 - v21;
        v26 = 0;
        if ( v25 != 0 )
        {
          do
          {
            if ( a2[*(_DWORD *)(v22 + 4 * v26)] != 0 )
              ++v24;
            ++v26;
          }
          while ( v26 < v25 );
          if ( v24 != 0 )
          {
            v31 = v18;
            tail = fifoStart;
            v30 = v19;
            v33.__vftable = (ILoggingListener_vtbl *)fifoEnd;
            v35 = PushFocusVertex(
                    a1: v25,
                    a2: v22,
                    head: (char **)&tail,
                    tail: &v33,
                    lru,
                    triangleIsAvailable: a2,
                    a7: a11,
                    outTriangles: nullptr,
                    kFifoMiss: (char *)LODWORD(v30),
                    kLruMiss: v31,
                    commitChanges: false);
            v27 = tail;
            for ( i = 0; v27 <= (unsigned int *)v33.__vftable; ++i )
            {
              if ( (IUnknown_vtbl *)*v27 == v20 )
                break;
              ++v27;
            }
            v19 = kFifoMiss;
            v18 = kLruMiss;
            v35 = v35 * a14 / (kFifoMiss + kLruMiss) - (double)v24 * a15 + (double)i * a16 / 23.0;
            v29 = v35;
            if ( *a4 > (double)v35 )
            {
              *bestIndex = v20;
              *a4 = v29;
            }
          }
        }
      }
      v17 = ++totalCost;
      if ( totalCost > result )
        break;
      v16 = a7;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000F5E0
// Name: void edgeGeomKCacheOptimizer(unsigned int const __near *,unsigned int,void __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __cdecl edgeGeomKCacheOptimizer(
        CLoggingSystem::LoggingState_t *result,
        unsigned int numTriangles,
        void *userData,
        unsigned __int8 *outTriangles)
{
  unsigned int v4; // ebx
  unsigned int v5; // eax
  unsigned int i; // ecx
  unsigned __int8 *v7; // ebp
  _s__RTTIBaseClassDescriptor2 *v8; // edi
  VectorByValue *v9; // ecx
  VectorByValue *v10; // ecx
  VectorByValue *v11; // ecx
  VectorByValue *v12; // ecx
  unsigned int *v13; // ebx
  unsigned int v14; // ebx
  unsigned int *v15; // edx
  int v16; // eax
  unsigned int v17; // esi
  unsigned int v18; // ecx
  unsigned int v19; // eax
  int v20; // edx
  unsigned int v21; // eax
  char *v22; // ecx
  unsigned int v23; // esi
  unsigned int j; // ebx
  int v25; // edx
  int *v26; // edx
  unsigned int v27; // esi
  unsigned int *v28; // ebx
  double v29; // st7
  int v30; // ecx
  char *v31; // edx
  unsigned int v32; // eax
  unsigned int v33; // ecx
  IUnknown *v34; // esi
  unsigned __int8 *v35; // eax
  int v36; // ecx
  unsigned int v37; // eax
  _DWORD *v38; // ecx
  tagIDLDESC v39; // [esp-8h] [ebp-1024h]
  unsigned int bestIndex; // [esp+24h] [ebp-FF8h] BYREF
  unsigned int *tail; // [esp+28h] [ebp-FF4h] BYREF
  unsigned int iVertex; // [esp+2Ch] [ebp-FF0h] BYREF
  unsigned int numIndexesLeft; // [esp+30h] [ebp-FECh] BYREF
  unsigned int *adjacentTrianglesPerVertex; // [esp+34h] [ebp-FE8h]
  char *triangleIsAvailable; // [esp+38h] [ebp-FE4h]
  unsigned int *head; // [esp+3Ch] [ebp-FE0h]
  unsigned int *potentialBlackIndexes; // [esp+40h] [ebp-FDCh] BYREF
  const _s__RTTIBaseClassDescriptor2 *lru; // [esp+44h] [ebp-FD8h]
  std::exception pExceptionObject; // [esp+48h] [ebp-FD4h] BYREF
  unsigned int *nonBlackIndexes; // [esp+54h] [ebp-FC8h] BYREF
  IUnknown *kLruMiss; // [esp+58h] [ebp-FC4h]
  IUnknown *kFifoMiss; // [esp+5Ch] [ebp-FC0h]
  IUnknown *totalCost; // [esp+60h] [ebp-FBCh]
  IUnknown *v54; // [esp+64h] [ebp-FB8h]
  IUnknown *v55; // [esp+68h] [ebp-FB4h]
  IUnknown *v56; // [esp+6Ch] [ebp-FB0h]
  unsigned int *outTris; // [esp+70h] [ebp-FACh]
  ILoggingListener v58; // [esp+74h] [ebp-FA8h] BYREF
  _BYTE fifo[4004]; // [esp+78h] [ebp-FA4h] OVERLAPPED BYREF

  totalCost = *(IUnknown **)userData;
  kFifoMiss = *((IUnknown **)userData + 1);
  v56 = *((IUnknown **)userData + 2);
  v55 = *((IUnknown **)userData + 3);
  outTris = *((unsigned int **)userData + 4);
  memset(dst: outTriangles, value: 0xFFu, count: 12 * numTriangles);
  v4 = 3 * numTriangles;
  v5 = 0;
  for ( i = 0; i < v4; ++i )
  {
    if ( *(&result->m_nPreviousStackEntry + i) > v5 )
      v5 = *(&result->m_nPreviousStackEntry + i);
  }
  potentialBlackIndexes = (unsigned int *)(v5 + 2);
  v7 = (unsigned __int8 *)edgeGeomAllocEx(
                            allocSize: 4 * (v5 + 2),
                            a2: ".\\libedgegeomtool_kcacheoptimizer.cpp",
                            lineNumber: 0x1BAu);
  v39.dwReserved = (unsigned int)potentialBlackIndexes;
  triangleIsAvailable = (char *)edgeGeomAllocEx(
                                  allocSize: 12 * numTriangles,
                                  a2: ".\\libedgegeomtool_kcacheoptimizer.cpp",
                                  lineNumber: 0x1BBu);
  FindAdjacentTriangles_0(
    a1: numTriangles,
    a2: (int)result,
    adjacentFacesPerVertex: (unsigned __int8 *)triangleIsAvailable,
    adjacencyDataStarts: v7,
    numVertexes: v39);
  head = (unsigned int *)edgeGeomAllocEx(
                           allocSize: numTriangles,
                           a2: ".\\libedgegeomtool_kcacheoptimizer.cpp",
                           lineNumber: 0x1C3u);
  memset(dst: (unsigned __int8 *)head, value: 1u, count: numTriangles);
  kLruMiss = (IUnknown *)edgeGeomAllocEx(
                           allocSize: 12 * numTriangles,
                           a2: ".\\libedgegeomtool_kcacheoptimizer.cpp",
                           lineNumber: 0x1CAu);
  memcpy(dst: (unsigned __int8 *)kLruMiss, src: (unsigned __int8 *)result, count: 12 * numTriangles);
  adjacentTrianglesPerVertex = (unsigned int *)_edgeGeomSortUniqueArrayInt(array: (int *)kLruMiss, totalElements: v4);
  v8 = (_s__RTTIBaseClassDescriptor2 *)edgeGeomAllocEx(
                                         allocSize: 12 * numTriangles,
                                         a2: ".\\libedgegeomtool_kcacheoptimizer.cpp",
                                         lineNumber: 0x1CFu);
  lru = v8;
  memset(dst: &fifo[4], value: 0xFFu, count: 0xFA0u);
  v9 = (VectorByValue *)outTriangles;
  *(float *)&v54 = 0.0;
  memset(&pExceptionObject, 255, sizeof(pExceptionObject));
  nonBlackIndexes = (unsigned int *)-1;
  for ( v58.__vftable = (ILoggingListener_vtbl *)outTriangles;
        adjacentTrianglesPerVertex != nullptr;
        v8 = (_s__RTTIBaseClassDescriptor2 *)lru )
  {
    *(float *)&bestIndex = 3.4028235e38;
    v13 = head;
    tail = (unsigned int *)-1;
    ChooseBestVertex(
      a1: (IUnknown *)&pExceptionObject,
      a2: (char *)head,
      result: (IUnknown *)&nonBlackIndexes,
      a4: (float *)&bestIndex,
      bestIndex: &tail,
      bestIndex_4: (int)triangleIsAvailable,
      a7: (int)v7,
      fifoStart: (unsigned int *)&fifo[4],
      fifoEnd: (unsigned int *)&fifo[92],
      lru: (unsigned int *)&pExceptionObject,
      a11: (int)result,
      kFifoMiss: *(float *)&totalCost,
      kLruMiss: *(float *)&kFifoMiss,
      a14: *(float *)&v56,
      a15: *(float *)&v55,
      a16: *(float *)&outTris);
    if ( tail == (unsigned int *)-1 )
    {
      ChooseBestVertex(
        a1: (IUnknown *)&fifo[4],
        a2: (char *)v13,
        result: (IUnknown *)&fifo[92],
        a4: (float *)&bestIndex,
        bestIndex: &tail,
        bestIndex_4: (int)triangleIsAvailable,
        a7: (int)v7,
        fifoStart: (unsigned int *)&fifo[4],
        fifoEnd: (unsigned int *)&fifo[92],
        lru: (unsigned int *)&pExceptionObject,
        a11: (int)result,
        kFifoMiss: *(float *)&totalCost,
        kLruMiss: *(float *)&kFifoMiss,
        a14: *(float *)&v56,
        a15: *(float *)&v55,
        a16: *(float *)&outTris);
      if ( tail == (unsigned int *)-1 )
      {
        v14 = 0;
        *(float *)&bestIndex = NAN;
        numIndexesLeft = 0;
        if ( adjacentTrianglesPerVertex == nullptr )
          goto $LN85;
        do
        {
          v15 = (unsigned int *)kLruMiss[v14].__vftable;
          v16 = *(_DWORD *)&v7[4 * (_DWORD)v15];
          potentialBlackIndexes = (unsigned int *)&triangleIsAvailable[4 * v16];
          v17 = 0;
          v18 = *(_DWORD *)&v7[4 * (_DWORD)v15 + 4] - v16;
          v19 = 0;
          if ( v18 != 0 )
          {
            do
            {
              if ( *((_BYTE *)head + potentialBlackIndexes[v19]) != 0 )
                ++v17;
              ++v19;
            }
            while ( v19 < v18 );
            v14 = numIndexesLeft;
            v8 = (_s__RTTIBaseClassDescriptor2 *)lru;
          }
          if ( v17 < bestIndex )
          {
            if ( v17 == 0 )
            {
              iVertex = (unsigned int)".\\libedgegeomtool_kcacheoptimizer.cpp(512)";
              std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&iVertex);
              _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI1_AVexception_std__);
            }
            bestIndex = v17;
            tail = v15;
          }
          numIndexesLeft = ++v14;
        }
        while ( v14 < (unsigned int)adjacentTrianglesPerVertex );
        if ( tail == (unsigned int *)-1 )
        {
$LN85:
          iVertex = (unsigned int)".\\libedgegeomtool_kcacheoptimizer.cpp(520)";
          std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&iVertex);
          _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI1_AVexception_std__);
        }
      }
    }
    numIndexesLeft = (unsigned int)&fifo[92];
    potentialBlackIndexes = (unsigned int *)&fifo[4];
    v20 = *(_DWORD *)&v7[4 * (_DWORD)tail];
    v21 = *(_DWORD *)&v7[4 * (_DWORD)tail + 4] - v20;
    v22 = &triangleIsAvailable[4 * v20];
    v23 = 0;
    bestIndex = (unsigned int)v22;
    for ( j = 0; j < v21; ++j )
    {
      v25 = *(_DWORD *)&v22[4 * j];
      v8 = (_s__RTTIBaseClassDescriptor2 *)lru;
      if ( *((_BYTE *)head + v25) != 0 )
      {
        v26 = &result->m_nPreviousStackEntry + 3 * v25;
        *((_DWORD *)&lru->pTypeDescriptor + v23) = *v26;
        v27 = v23 + 1;
        *((_DWORD *)&v8->pTypeDescriptor + v27) = v26[1];
        v22 = (char *)bestIndex;
        ++v27;
        *((_DWORD *)&v8->pTypeDescriptor + v27) = v26[2];
        v23 = v27 + 1;
      }
    }
    v28 = head;
    v29 = PushFocusVertex(
            a1: v21,
            a2: (int)v22,
            head: (char **)&potentialBlackIndexes,
            tail: (ILoggingListener *)&numIndexesLeft,
            lru: (unsigned int *)&pExceptionObject,
            triangleIsAvailable: (char *)head,
            a7: (int)result,
            outTriangles: &v58,
            kFifoMiss: (char *)totalCost,
            kLruMiss: *(float *)&kFifoMiss,
            commitChanges: true);
    *(float *)&v54 = v29 + *(float *)&v54;
    iVertex = _edgeGeomSortUniqueArrayInt(array: (int *)v8, totalElements: v23);
    *(float *)&bestIndex = 0.0;
    if ( iVertex != 0 )
    {
      numIndexesLeft = 4 * (_DWORD)adjacentTrianglesPerVertex;
      do
      {
        *(_DWORD *)fifo = *((_DWORD *)&v8->pTypeDescriptor + bestIndex);
        v30 = *(_DWORD *)&v7[4 * *(_DWORD *)fifo];
        v31 = &triangleIsAvailable[4 * v30];
        v32 = *(_DWORD *)&v7[4 * *(_DWORD *)fifo + 4] - v30;
        v33 = 0;
        tail = nullptr;
        if ( v32 == 0 )
          goto LABEL_31;
        do
        {
          if ( *((_BYTE *)v28 + *(_DWORD *)&v31[4 * v33]) != 0 )
            tail = (unsigned int *)((char *)tail + 1);
          ++v33;
        }
        while ( v33 < v32 );
        if ( tail == nullptr )
        {
LABEL_31:
          v34 = kLruMiss;
          v35 = (unsigned __int8 *)bsearch(
                                     key: fifo,
                                     base: kLruMiss,
                                     num: (unsigned int)adjacentTrianglesPerVertex,
                                     width: 4u,
                                     compare: (int (__cdecl *)(const void *, const void *))_edgeGeomIsEqualInt);
          if ( v35 == nullptr )
          {
            iVertex = (unsigned int)".\\libedgegeomtool_kcacheoptimizer.cpp(558)";
            std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&iVertex);
            _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI1_AVexception_std__);
          }
          memmove(dst: v35, src: v35 + 4, count: 4 * ((int)((int)&v34[-1] + numIndexesLeft - (_DWORD)v35) >> 2));
          adjacentTrianglesPerVertex = (unsigned int *)((char *)adjacentTrianglesPerVertex - 1);
          numIndexesLeft -= 4;
        }
        ++bestIndex;
      }
      while ( bestIndex < iVertex );
    }
    v36 = ((char *)potentialBlackIndexes - &fifo[4]) >> 2;
    if ( (unsigned int)(v36 + 23) > 0x3E8 )
    {
      iVertex = (unsigned int)".\\libedgegeomtool_kcacheoptimizer.cpp(566)";
      std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&iVertex);
      _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI1_AVexception_std__);
    }
    v37 = 0;
    v38 = &fifo[4 * v36 + 4];
    do
      *(_DWORD *)&fifo[4 * v37++ + 4] = *v38++;
    while ( v37 < 0x17 );
    memset(&fifo[96], 0xFFu, 0xF44u);
    v9 = nullptr;
  }
  edgeGeomFreeEx(this: v9);
  edgeGeomFreeEx(this: v10);
  edgeGeomFreeEx(this: v11);
  edgeGeomFreeEx(this: (VectorByValue *)triangleIsAvailable);
  edgeGeomFreeEx(this: v12);
}

//------------------------------------------------------------------------------
// Address: 0x1000FBE0
// Name: GetCacheCost
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
double __usercall GetCacheCost@<st0>(
        int a1@<eax>,
        void (__thiscall **a2)(ILoggingListener *this, const LoggingContext_t *, const char *),
        float kFifoMiss,
        float kLruMiss)
{
  int v6; // ecx
  unsigned int v7; // eax
  unsigned int v8; // edx
  _DWORD *v9; // ecx
  float start; // [esp+14h] [ebp-94h]
  const _s__RTTIBaseClassDescriptor2 *lru; // [esp+18h] [ebp-90h] BYREF
  int v13; // [esp+1Ch] [ebp-8Ch] BYREF
  int v14; // [esp+20h] [ebp-88h]
  int v15; // [esp+24h] [ebp-84h]
  const _s__RTTIBaseClassDescriptor2 *tmpLru; // [esp+28h] [ebp-80h]
  int v17; // [esp+2Ch] [ebp-7Ch] BYREF
  int v18; // [esp+30h] [ebp-78h]
  int v19; // [esp+34h] [ebp-74h]
  unsigned int *end; // [esp+38h] [ebp-70h]
  _DWORD *fifo; // [esp+3Ch] [ebp-6Ch] OVERLAPPED BYREF
  _DWORD dst[26]; // [esp+40h] [ebp-68h] BYREF

  memset((unsigned __int8 *)dst, value: 0xFFu, count: sizeof(dst));
  start = 0.0;
  v13 = -1;
  v14 = -1;
  v15 = -1;
  tmpLru = (const _s__RTTIBaseClassDescriptor2 *)-1;
  v17 = -1;
  v18 = -1;
  v19 = -1;
  for ( end = (unsigned int *)-1; a1 != 0; --a1 )
  {
    lru = (const _s__RTTIBaseClassDescriptor2 *)dst;
    fifo = &dst[22];
    start = PushTriangle(
              a1: &v17,
              fifoStarta: (ILoggingListener *)&lru,
              fifoMisses: (unsigned int)&fifo,
              i: (int)&v13,
              a5: a2,
              kFifoMiss,
              kLruMiss)
          + start;
    v14 = v18;
    v15 = v19;
    v13 = v17;
    tmpLru = (const _s__RTTIBaseClassDescriptor2 *)end;
    v6 = ((char *)lru - (char *)dst) >> 2;
    v7 = 0;
    v8 = 26 - v6;
    if ( v6 != 26 )
    {
      v9 = &dst[v6];
      do
        dst[v7++] = *v9++;
      while ( v7 < v8 );
    }
    if ( v8 < 0x1A )
      memset(&dst[v8], 0xFFu, 4 * (26 - v8));
    a2 += 3;
  }
  return start;
}

//------------------------------------------------------------------------------
// Address: 0x1000FD10
// Name: void edgeGeomKCacheOptimizerHillclimber(unsigned int const __near *,unsigned int,void __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl edgeGeomKCacheOptimizerHillclimber(
        CLoggingSystem::LoggingState_t *result,
        void *userData,
        IUnknown *kFifoMiss,
        unsigned __int8 *outTriangleList)
{
  IUnknown_vtbl *v4; // ecx
  IUnknown_vtbl *v5; // edx
  IUnknown_vtbl *v6; // eax
  unsigned int v7; // esi
  bool v8; // bl
  bool v9; // zf
  unsigned int v10; // ecx
  unsigned int v11; // ecx
  tagSAFEARRAY *v12; // ecx
  tagSAFEARRAY *v13; // edx
  float bestK1; // [esp+18h] [ebp-54h]
  float bestK2; // [esp+1Ch] [ebp-50h]
  float bestK3; // [esp+20h] [ebp-4Ch]
  float v17; // [esp+24h] [ebp-48h]
  enum EdgeGeomIndexesFlavor indexesSize; // [esp+28h] [ebp-44h]
  tagSAFEARRAY *indexesTempSize; // [esp+2Ch] [ebp-40h]
  IRecordInfo_vtbl *v20; // [esp+30h] [ebp-3Ch]
  float v21; // [esp+34h] [ebp-38h]
  float v22; // [esp+38h] [ebp-34h]
  float bestScore; // [esp+3Ch] [ebp-30h]
  float measuredSizes; // [esp+40h] [ebp-2Ch]
  IUnknown *currentScore; // [esp+44h] [ebp-28h]
  tagSAFEARRAY *indexesSizes; // [esp+48h] [ebp-24h] BYREF
  IRecordInfo thisIndexTableSizes; // [esp+4Ch] [ebp-20h]
  tagSAFEARRAY *v28[2]; // [esp+50h] [ebp-1Ch] BYREF
  float v29; // [esp+58h] [ebp-14h] BYREF
  float v30; // [esp+5Ch] [ebp-10h]
  float v31; // [esp+60h] [ebp-Ch]
  float v32; // [esp+64h] [ebp-8h]
  float v33; // [esp+68h] [ebp-4h]
  float kFifoMissa; // [esp+78h] [ebp+Ch]

  v4 = kFifoMiss[1].__vftable;
  v6 = kFifoMiss[3].__vftable;
  v7 = 0;
  currentScore = (IUnknown *)kFifoMiss->__vftable;
  indexesSize = (enum EdgeGeomIndexesFlavor)v4;
  v8 = v4 == (IUnknown_vtbl *)2 || v4 == (IUnknown_vtbl *)3;
  v5 = kFifoMiss[2].__vftable;
  bestK1 = (float)(unsigned int)v5;
  v9 = kFifoMiss->__vftable == nullptr;
  kFifoMissa = (double)(unsigned int)v6 * 4.0;
  bestK2 = 1.0;
  bestK3 = 0.25;
  v17 = 0.80000001;
  if ( !v9 )
  {
    v29 = (double)(unsigned int)v6 * 4.0;
    v30 = (float)(unsigned int)v5;
    v31 = 1.0;
    v32 = 0.25;
    v33 = 0.80000001;
    edgeGeomKCacheOptimizer(result, numTriangles: (unsigned int)userData, userData: &v29, outTriangles: outTriangleList);
    if ( v8 )
      _edgeGeomRotateTrianglesForAdjacency(
        triangles: (unsigned int *)outTriangleList,
        numTriangles: (unsigned int)userData);
    measuredSizes = GetCacheCost(
                      a1: (int)userData,
                      a2: (void (__thiscall **)(ILoggingListener *, const LoggingContext_t *, const char *))outTriangleList,
                      kFifoMiss: kFifoMissa,
                      kLruMiss: bestK1);
    indexesTempSize = nullptr;
    v20 = nullptr;
    if ( v8 )
    {
      _edgeGeomMeasureCompressedIndexTable(
        src: outTriangleList,
        numTriangles: (unsigned int)userData,
        a3: indexesSize,
        &indexesSizes);
      indexesTempSize = indexesSizes;
      v20 = thisIndexTableSizes.__vftable;
    }
    for ( ; currentScore != nullptr; currentScore = (IUnknown *)((char *)currentScore - 1) )
    {
      v10 = 279470273 * (unsigned __int64)v7 % 0xFFFFFFFB;
      v21 = (double)(v10 % 0x14) / 20.0 - 0.5 + bestK2;
      v11 = 279470273 * (unsigned __int64)v10 % 0xFFFFFFFB;
      v22 = (double)(v11 % 0x14) / 20.0 - 0.5 + bestK3;
      v7 = 279470273 * (unsigned __int64)v11 % 0xFFFFFFFB;
      indexesSizes = (tagSAFEARRAY *)(v7 % 0x14);
      bestScore = (double)(v7 % 0x14) / 20.0 - 0.5 + v17;
      v31 = v21;
      v32 = v22;
      v33 = bestScore;
      edgeGeomKCacheOptimizer(
        result,
        numTriangles: (unsigned int)userData,
        userData: &v29,
        outTriangles: outTriangleList);
      if ( v8 )
        _edgeGeomRotateTrianglesForAdjacency(
          triangles: (unsigned int *)outTriangleList,
          numTriangles: (unsigned int)userData);
      *(float *)&indexesSizes = GetCacheCost(
                                  a1: (int)userData,
                                  a2: (void (__thiscall **)(ILoggingListener *, const LoggingContext_t *, const char *))outTriangleList,
                                  kFifoMiss: kFifoMissa,
                                  kLruMiss: bestK1);
      v12 = nullptr;
      v13 = nullptr;
      if ( v8 )
      {
        _edgeGeomMeasureCompressedIndexTable(
          src: outTriangleList,
          numTriangles: (unsigned int)userData,
          a3: indexesSize,
          indexesSizes: v28);
        v12 = v28[0];
        v13 = v28[1];
      }
      if ( measuredSizes >= (double)*(float *)&indexesSizes && v12 <= indexesTempSize && v13 <= (tagSAFEARRAY *)v20 )
      {
        bestK2 = v21;
        bestK3 = v22;
        v17 = (double)(v7 % 0x14) / 20.0 - 0.5 + v17;
        measuredSizes = *(float *)&indexesSizes;
      }
    }
  }
  v29 = kFifoMissa;
  v30 = bestK1;
  v31 = bestK2;
  v32 = bestK3;
  v33 = v17;
  edgeGeomKCacheOptimizer(result, numTriangles: (unsigned int)userData, userData: &v29, outTriangles: outTriangleList);
  if ( v8 )
    _edgeGeomRotateTrianglesForAdjacency(
      triangles: (unsigned int *)outTriangleList,
      numTriangles: (unsigned int)userData);
}
