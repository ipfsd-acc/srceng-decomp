// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: edge/libedgegeomtool/libedgegeomtool_partitioner.cpp
// Functions: 10
// ============================================================

#include "edge\libedgegeomtool\libedgegeomtool_partitioner.h"

//------------------------------------------------------------------------------
// Address: 0x1000CDA0
// Name: void edgeGeomComputeTriangleCentroids(float const __near *,unsigned int,unsigned short,unsigned int const __near *,unsigned int,float __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl edgeGeomComputeTriangleCentroids(
        const float *a1,
        unsigned int numFloatsPerVertex,
        unsigned __int16 positionAttributeIndex,
        const unsigned int *a4,
        unsigned int numTriangles,
        float **a6)
{
  float *v6; // eax
  double v7; // st7
  double v8; // st6
  const unsigned int *v9; // ebp
  float *v10; // ecx
  char *v11; // ebx
  double v12; // rt0
  double v13; // rt1
  double v14; // st6
  double v15; // st7
  int v16; // edx
  int v17; // edx
  int v18; // edx
  bool v19; // zf

  if ( numTriangles != 0 )
  {
    v6 = (float *)edgeGeomAllocEx(
                    allocSize: 12 * numTriangles,
                    a2: ".\\libedgegeomtool_partitioner.cpp",
                    lineNumber: 0xE1u);
    *a6 = v6;
    v7 = 0.0;
    v8 = 0.3333333432674408;
    v9 = a4;
    v10 = v6 + 2;
    v11 = (char *)((char *)a4 - (char *)v6);
    while ( 1 )
    {
      v13 = v8;
      v14 = v7;
      v15 = v13;
      v9 += 3;
      *(v10 - 2) = v14;
      v10 += 3;
      *(v10 - 4) = v14;
      *(v10 - 3) = v14;
      v16 = positionAttributeIndex + numFloatsPerVertex * *(v9 - 3);
      *(v10 - 5) = a1[v16] * v13 + *(v10 - 5);
      *(v10 - 4) = a1[v16 + 1] * v13 + *(v10 - 4);
      *(v10 - 3) = a1[v16 + 2] * v13 + *(v10 - 3);
      v17 = positionAttributeIndex + numFloatsPerVertex * *(_DWORD *)&v11[(_DWORD)v10 - 16];
      *(v10 - 5) = a1[v17] * v13 + *(v10 - 5);
      *(v10 - 4) = a1[v17 + 1] * v13 + *(v10 - 4);
      *(v10 - 3) = a1[v17 + 2] * v13 + *(v10 - 3);
      v18 = positionAttributeIndex + numFloatsPerVertex * *(_DWORD *)&v11[(_DWORD)v10 - 12];
      v19 = numTriangles-- == 1;
      *(v10 - 5) = a1[v18] * v13 + *(v10 - 5);
      *(v10 - 4) = a1[v18 + 1] * v13 + *(v10 - 4);
      *(v10 - 3) = a1[v18 + 2] * v13 + *(v10 - 3);
      if ( v19 )
        break;
      v12 = v14;
      v8 = v15;
      v7 = v12;
    }
  }
  else
  {
    *a6 = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000CEB0
// Name: unsigned int edgeGeomGetCommandBufferHoleSize(unsigned int,unsigned int,void (*)(struct cell::Gcm::CellGcmContext __near *))
// Source: json
//------------------------------------------------------------------------------
CLoggingSystem::LoggingChannel_t *__cdecl edgeGeomGetCommandBufferHoleSize(
        CLoggingSystem::LoggingChannel_t *result,
        unsigned int numIndexes,
        const CLoggingSystem::LoggingChannel_t *customHoleSizeCallback)
{
  CLoggingSystem::LoggingChannel_t *v3; // eax
  int v4; // ebx
  int v5; // esi
  unsigned int v6; // edi
  int v7; // esi
  unsigned int v8; // ecx
  unsigned int v9; // ecx
  unsigned int v10; // eax
  unsigned int v11; // ecx
  CLoggingSystem::LoggingChannel_t *v12; // eax
  std::exception pExceptionObject; // [esp+8h] [ebp-1Ch] BYREF
  _DWORD v14[2]; // [esp+14h] [ebp-10h] BYREF
  unsigned int v15; // [esp+1Ch] [ebp-8h]

  v3 = result;
  v4 = 0;
  v5 = 0;
  v14[1] = 0;
  for ( v14[0] = 0; v3 != nullptr; v3 = (CLoggingSystem::LoggingChannel_t *)((char *)v3 - 1) )
    v5 += 16;
  v6 = numIndexes;
  v7 = v5 + 76;
  if ( numIndexes > 1 )
  {
    v7 += 8;
    v6 = numIndexes - 1;
  }
  if ( v6 > 0x7FF00 )
  {
    v8 = (v6 - 524033) / 0x7FF00 + 1;
    do
    {
      v7 += 0x2000;
      v6 -= 524032;
      --v8;
    }
    while ( v8 != 0 );
  }
  v9 = v7 + 4 * ((v6 + 255) >> 8) + 12;
  v15 = v9;
  if ( customHoleSizeCallback != nullptr )
  {
    ((void (__cdecl *)(_DWORD *))customHoleSizeCallback)(a1: v14);
    v9 = v15;
    v4 = v14[0];
  }
  v10 = (v9 - v4 + 127) >> 7;
  v11 = v9 + 4 * v10;
  v15 = v11;
  if ( (v11 - v4 + 127) >> 7 != v10 )
  {
    v11 += 4;
    v15 = v11;
  }
  v12 = (CLoggingSystem::LoggingChannel_t *)((v11 - v4 + 15) & 0xFFFFFFF0);
  if ( (unsigned int)v12 >= 0x1000 )
  {
    result = (CLoggingSystem::LoggingChannel_t *)".\\libedgegeomtool_partitioner.cpp(383)";
    std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&result);
    _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI1_AVexception_std__);
  }
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x1000CFB0
// Name: FindHighestMatrixIndex
// Source: json
//------------------------------------------------------------------------------
int __fastcall FindHighestMatrixIndex(int a1, int a2, int a3)
{
  int result; // eax
  unsigned int i; // edi

  result = -1;
  if ( a2 != 0 )
  {
    for ( i = 0; i < 3 * a1; ++i )
    {
      if ( *(_DWORD *)(a2 + 16 * *(_DWORD *)(a3 + 4 * i)) > result )
        result = *(_DWORD *)(a2 + 16 * *(_DWORD *)(a3 + 4 * i));
      if ( *(_DWORD *)(a2 + 16 * *(_DWORD *)(a3 + 4 * i) + 4) > result )
        result = *(_DWORD *)(a2 + 16 * *(_DWORD *)(a3 + 4 * i) + 4);
      if ( *(_DWORD *)(a2 + 16 * *(_DWORD *)(a3 + 4 * i) + 8) > result )
        result = *(_DWORD *)(a2 + 16 * *(_DWORD *)(a3 + 4 * i) + 8);
      if ( *(_DWORD *)(a2 + 16 * *(_DWORD *)(a3 + 4 * i) + 12) > result )
        result = *(_DWORD *)(a2 + 16 * *(_DWORD *)(a3 + 4 * i) + 12);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000D140
// Name: FindFirstAvailableTriangle
// Source: json
//------------------------------------------------------------------------------
unsigned int __usercall FindFirstAvailableTriangle@<eax>(int a1@<eax>, signed int result, int a3)
{
  int v3; // ecx
  unsigned int v5; // eax
  int v6; // ebx
  unsigned int v7; // ebp
  unsigned int v8; // edx
  int v9; // edi
  _BYTE *v10; // esi
  float *v11; // ecx
  float *v12; // ecx
  int v13; // edi
  _BYTE *v14; // esi
  float *v15; // ecx
  float *v16; // ecx
  int minDistanceSq; // [esp+4h] [ebp-20h]
  float deltaY; // [esp+8h] [ebp-1Ch]
  float deltaX; // [esp+Ch] [ebp-18h]
  float deltaXa; // [esp+Ch] [ebp-18h]
  float deltaXb; // [esp+Ch] [ebp-18h]
  float deltaXc; // [esp+Ch] [ebp-18h]
  float deltaXd; // [esp+Ch] [ebp-18h]
  float distanceSq; // [esp+10h] [ebp-14h]
  float distanceSqa; // [esp+10h] [ebp-14h]
  float distanceSqb; // [esp+10h] [ebp-14h]
  float distanceSqc; // [esp+10h] [ebp-14h]
  float distanceSqd; // [esp+10h] [ebp-14h]
  float v29; // [esp+14h] [ebp-10h]
  float v30; // [esp+14h] [ebp-10h]
  float v31; // [esp+14h] [ebp-10h]
  float v32; // [esp+14h] [ebp-10h]
  float v33; // [esp+14h] [ebp-10h]
  float v34; // [esp+14h] [ebp-10h]
  float v35; // [esp+14h] [ebp-10h]
  float v36; // [esp+14h] [ebp-10h]
  float v37; // [esp+14h] [ebp-10h]
  float v38; // [esp+14h] [ebp-10h]
  float v39; // [esp+18h] [ebp-Ch]
  float v40; // [esp+1Ch] [ebp-8h]
  float v41; // [esp+20h] [ebp-4h]

  v3 = a3;
  minDistanceSq = -1;
  if ( a3 != 0 )
  {
    v7 = result;
    v8 = 0;
    if ( *(_DWORD *)(a1 + 28) != 0 )
    {
      deltaY = 3.4028235e38;
      if ( result >= 4 )
      {
        v13 = 2;
        v14 = (_BYTE *)(*(_DWORD *)(a1 + 16) + 2);
        v15 = (float *)(a3 + 8);
        do
        {
          if ( *(v14 - 2) != 0 )
          {
            distanceSq = *(v15 - 2) - *(float *)(a1 + 56);
            deltaX = *(v15 - 1) - *(float *)(a1 + 60);
            v29 = *v15 - *(float *)(a1 + 64);
            v30 = deltaX * deltaX + distanceSq * distanceSq + v29 * v29;
            if ( deltaY > (double)v30 )
            {
              deltaY = v30;
              minDistanceSq = v8;
            }
          }
          if ( *(v14 - 1) != 0 )
          {
            distanceSqa = v15[1] - *(float *)(a1 + 56);
            deltaXa = v15[2] - *(float *)(a1 + 60);
            v31 = v15[3] - *(float *)(a1 + 64);
            v32 = deltaXa * deltaXa + distanceSqa * distanceSqa + v31 * v31;
            if ( deltaY > (double)v32 )
            {
              deltaY = v32;
              minDistanceSq = v13 - 1;
            }
          }
          if ( *v14 != 0 )
          {
            distanceSqb = v15[4] - *(float *)(a1 + 56);
            deltaXb = v15[5] - *(float *)(a1 + 60);
            v33 = v15[6] - *(float *)(a1 + 64);
            v34 = deltaXb * deltaXb + distanceSqb * distanceSqb + v33 * v33;
            if ( deltaY > (double)v34 )
            {
              deltaY = v34;
              minDistanceSq = v13;
            }
          }
          if ( v14[1] != 0 )
          {
            distanceSqc = v15[7] - *(float *)(a1 + 56);
            deltaXc = v15[8] - *(float *)(a1 + 60);
            v35 = v15[9] - *(float *)(a1 + 64);
            v36 = deltaXc * deltaXc + distanceSqc * distanceSqc + v35 * v35;
            if ( deltaY > (double)v36 )
            {
              deltaY = v36;
              minDistanceSq = v13 + 1;
            }
          }
          v8 += 4;
          v13 += 4;
          v14 += 4;
          v15 += 12;
        }
        while ( v8 < result - 3 );
        v7 = result;
        v3 = a3;
      }
      if ( v8 < v7 )
      {
        v16 = (float *)(v3 + 12 * v8 + 8);
        do
        {
          if ( *(_BYTE *)(*(_DWORD *)(a1 + 16) + v8) != 0 )
          {
            distanceSqd = *(v16 - 2) - *(float *)(a1 + 56);
            deltaXd = *(v16 - 1) - *(float *)(a1 + 60);
            v37 = *v16 - *(float *)(a1 + 64);
            v38 = deltaXd * deltaXd + distanceSqd * distanceSqd + v37 * v37;
            if ( deltaY > (double)v38 )
            {
              deltaY = v38;
              minDistanceSq = v8;
            }
          }
          ++v8;
          v16 += 3;
        }
        while ( v8 < result );
      }
    }
    else
    {
      v39 = 3.4028235e38;
      v40 = 3.4028235e38;
      v41 = 3.4028235e38;
      if ( result >= 4 )
      {
        v9 = 2;
        v10 = (_BYTE *)(*(_DWORD *)(a1 + 16) + 2);
        v11 = (float *)(a3 + 8);
        do
        {
          if ( *(v10 - 2) != 0 && v39 > (double)*(v11 - 2) && v40 > (double)*(v11 - 1) && v41 > (double)*v11 )
          {
            minDistanceSq = v8;
            v39 = *(v11 - 2);
            v40 = *(v11 - 1);
            v41 = *v11;
          }
          if ( *(v10 - 1) != 0 && v39 > (double)v11[1] && v40 > (double)v11[2] && v41 > (double)v11[3] )
          {
            v39 = v11[1];
            minDistanceSq = v9 - 1;
            v40 = v11[2];
            v41 = v11[3];
          }
          if ( *v10 != 0 && v39 > (double)v11[4] && v40 > (double)v11[5] && v41 > (double)v11[6] )
          {
            minDistanceSq = v9;
            v39 = v11[4];
            v40 = v11[5];
            v41 = v11[6];
          }
          if ( v10[1] != 0 && v39 > (double)v11[7] && v40 > (double)v11[8] && v41 > (double)v11[9] )
          {
            v39 = v11[7];
            minDistanceSq = v9 + 1;
            v40 = v11[8];
            v41 = v11[9];
          }
          v8 += 4;
          v9 += 4;
          v10 += 4;
          v11 += 12;
        }
        while ( v8 < result - 3 );
        v7 = result;
        v3 = a3;
      }
      if ( v8 < v7 )
      {
        v12 = (float *)(v3 + 12 * v8 + 8);
        do
        {
          if ( *(_BYTE *)(*(_DWORD *)(a1 + 16) + v8) != 0
            && v39 > (double)*(v12 - 2)
            && v40 > (double)*(v12 - 1)
            && v41 > (double)*v12 )
          {
            minDistanceSq = v8;
            v39 = *(v12 - 2);
            v40 = *(v12 - 1);
            v41 = *v12;
          }
          ++v8;
          v12 += 3;
        }
        while ( v8 < result );
        return minDistanceSq;
      }
    }
    return minDistanceSq;
  }
  v5 = 0;
  if ( result == 0 )
    return minDistanceSq;
  v6 = *(_DWORD *)(a1 + 16);
  while ( *(_BYTE *)(v6 + v5) == 0 )
  {
    if ( ++v5 >= result )
      return -1;
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1000D5E0
// Name: AssignTriangleToPartition
// Source: json
//------------------------------------------------------------------------------
void __usercall AssignTriangleToPartition(
        unsigned int context@<esi>,
        int a2@<eax>,
        unsigned int numMatricesAdded,
        _is_ctype_compatible matricesPerVertex,
        unsigned int numBlendedVertexes,
        int a6)
{
  unsigned int v6; // ebp
  unsigned int v8; // eax
  int v9; // edi
  int v10; // eax
  float *v11; // eax
  double v12; // st6
  double v13; // st6
  _DWORD *v14; // ecx
  _DWORD *v15; // eax
  int v16; // eax
  unsigned int v17; // ecx
  _DWORD *v18; // ebp
  unsigned int v19; // eax
  unsigned int v20; // edx
  _DWORD *v21; // ecx
  int v22; // edx
  int v23; // eax
  const void *is_clike; // eax
  unsigned int v25; // edx
  _DWORD *v26; // ebp
  unsigned int v27; // eax
  unsigned int v28; // edx
  _DWORD *v29; // ecx
  int v30; // edx
  int v31; // ecx
  unsigned int iVertex; // [esp+8h] [ebp-18h]
  unsigned int iVertexa; // [esp+8h] [ebp-18h]
  float newTrianglea; // [esp+Ch] [ebp-14h]
  unsigned int *newTriangle; // [esp+Ch] [ebp-14h]
  _DWORD *v36; // [esp+10h] [ebp-10h]
  std::exception pExceptionObject; // [esp+14h] [ebp-Ch] BYREF

  v6 = numMatricesAdded;
  if ( *(_BYTE *)(*(_DWORD *)(context + 16) + numMatricesAdded) != 1 )
  {
    *(float *)&numMatricesAdded = COERCE_FLOAT(".\\libedgegeomtool_partitioner.cpp(618)");
    std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&numMatricesAdded);
    _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI1_AVexception_std__);
  }
  v8 = *(_DWORD *)(context + 88);
  if ( v8 >= *(_DWORD *)(context + 84) )
  {
    *(float *)&numMatricesAdded = COERCE_FLOAT(".\\libedgegeomtool_partitioner.cpp(621)");
    std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&numMatricesAdded);
    _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI1_AVexception_std__);
  }
  v9 = *(_DWORD *)(context + 80) + 84 * v8;
  *(_DWORD *)(context + 88) = v8 + 1;
  memset(dst: (unsigned __int8 *)v9, value: 0, count: 0x54u);
  v10 = a6;
  *(_DWORD *)v9 = v6;
  *(float *)(v9 + 4) = *(float *)(context + 56);
  *(float *)(v9 + 8) = *(float *)(context + 60);
  *(float *)(v9 + 12) = *(float *)(context + 64);
  if ( v10 != 0 )
  {
    *(float *)&numMatricesAdded = (float)*(unsigned int *)(context + 28);
    v11 = (float *)(v10 + 12 * v6);
    v12 = *(float *)&numMatricesAdded + 1.0;
    newTrianglea = *(float *)&numMatricesAdded / v12;
    *(float *)&numMatricesAdded = 1.0 / v12;
    v13 = *(float *)&numMatricesAdded;
    *(float *)(context + 56) = *(float *)(context + 56) * newTrianglea + *v11 * *(float *)&numMatricesAdded;
    *(float *)(context + 60) = v11[1] * v13 + *(float *)(context + 60) * newTrianglea;
    *(float *)(context + 64) = newTrianglea * *(float *)(context + 64) + v13 * v11[2];
  }
  v14 = (_DWORD *)(*(_DWORD *)(context + 44) + 12 * *(_DWORD *)(context + 28));
  v15 = (_DWORD *)(a2 + 12 * v6);
  *v14 = *v15;
  v14[1] = v15[1];
  v14[2] = v15[2];
  ++*(_DWORD *)(context + 28);
  --*(_DWORD *)(context + 24);
  v36 = v14;
  v16 = 3 * v6;
  *(_BYTE *)(*(_DWORD *)(context + 16) + v6) = 0;
  v17 = 3 * v6 + 3;
  *(float *)&numMatricesAdded = 0.0;
  if ( 3 * v6 < v17 )
  {
    v18 = (_DWORD *)(a2 + 12 * v6);
    iVertex = v17 - v16;
    do
    {
      if ( bsearch(
             key: v18,
             base: *(const void **)(context + 48),
             num: *(_DWORD *)(context + 32),
             width: 4u,
             compare: (int (__cdecl *)(const void *, const void *))_edgeGeomIsEqualInt) == nullptr )
      {
        v19 = *(_DWORD *)(context + 32);
        v20 = v19 + numMatricesAdded;
        if ( v19 >= v19 + numMatricesAdded )
        {
LABEL_14:
          *(_DWORD *)(*(_DWORD *)(context + 48) + 4 * v20) = *v18;
          v22 = *(unsigned __int16 *)(v9 + 76);
          v23 = *v18;
          ++numMatricesAdded;
          *(_DWORD *)(v9 + 4 * v22 + 16) = v23;
          is_clike = (const void *)matricesPerVertex.is_clike;
          ++*(_WORD *)(v9 + 76);
          if ( is_clike != nullptr
            && bsearch(
                 key: v18,
                 base: is_clike,
                 num: numBlendedVertexes,
                 width: 4u,
                 compare: (int (__cdecl *)(const void *, const void *))_edgeGeomIsEqualInt) != nullptr )
          {
            ++*(_DWORD *)(context + 40);
            ++*(_WORD *)(v9 + 78);
          }
        }
        else
        {
          v21 = (_DWORD *)(*(_DWORD *)(context + 48) + 4 * v19);
          while ( *v21 != *v18 )
          {
            ++v19;
            ++v21;
            if ( v19 >= numMatricesAdded + *(_DWORD *)(context + 32) )
              goto LABEL_14;
          }
        }
      }
      ++v18;
      --iVertex;
    }
    while ( iVertex != 0 );
    if ( *(float *)&numMatricesAdded != 0.0 )
    {
      *(_DWORD *)(context + 32) += numMatricesAdded;
      qsort(
        base: *(void **)(context + 48),
        num: *(_DWORD *)(context + 32),
        width: 4u,
        comp: (int (__cdecl *)(const void *, const void *))_edgeGeomIsEqualInt);
    }
  }
  v25 = 0;
  if ( *(_DWORD *)(context + 52) != 0 )
  {
    *(float *)&numMatricesAdded = 0.0;
    newTriangle = nullptr;
    do
    {
      if ( 4 * v36[v25] < (unsigned int)(4 * v36[v25] + 4) )
      {
        v26 = (_DWORD *)(matricesPerVertex.id + 16 * v36[v25]);
        for ( iVertexa = 4; iVertexa != 0; --iVertexa )
        {
          if ( *v26 != -1
            && bsearch(
                 key: v26,
                 base: *(const void **)(context + 52),
                 num: *(_DWORD *)(context + 36),
                 width: 4u,
                 compare: (int (__cdecl *)(const void *, const void *))_edgeGeomIsEqualInt) == nullptr )
          {
            v27 = *(_DWORD *)(context + 36);
            v28 = v27 + numMatricesAdded;
            if ( v27 >= v27 + numMatricesAdded )
            {
LABEL_30:
              *(_DWORD *)(*(_DWORD *)(context + 52) + 4 * v28) = *v26;
              v30 = *(unsigned __int16 *)(v9 + 80);
              v31 = *v26;
              ++numMatricesAdded;
              *(_DWORD *)(v9 + 4 * v30 + 28) = v31;
              ++*(_WORD *)(v9 + 80);
            }
            else
            {
              v29 = (_DWORD *)(*(_DWORD *)(context + 52) + 4 * v27);
              while ( *v29 != *v26 )
              {
                ++v27;
                ++v29;
                if ( v27 >= numMatricesAdded + *(_DWORD *)(context + 36) )
                  goto LABEL_30;
              }
            }
          }
          ++v26;
        }
        v25 = (unsigned int)newTriangle;
      }
      newTriangle = (unsigned int *)++v25;
    }
    while ( v25 < 3 );
    if ( *(float *)&numMatricesAdded != 0.0 )
    {
      *(_DWORD *)(context + 36) += numMatricesAdded;
      qsort(
        base: *(void **)(context + 52),
        num: *(_DWORD *)(context + 36),
        width: 4u,
        comp: (int (__cdecl *)(const void *, const void *))_edgeGeomIsEqualInt);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D900
// Name: RemoveLastTriangleFromPartition
// Source: json
//------------------------------------------------------------------------------
void __usercall RemoveLastTriangleFromPartition(
        const CUtlMap<unsigned char *,int,unsigned int>::CKeyLess *context@<esi>)
{
  bool (__cdecl *m_LessFunc)(unsigned __int8 *const *, unsigned __int8 *const *); // edi
  bool (__cdecl *v2)(unsigned __int8 *const *, unsigned __int8 *const *); // eax
  bool (__cdecl *v3)(unsigned __int8 *const *, unsigned __int8 *const *); // edi
  char *v4; // edi
  double v5; // st7
  unsigned __int16 v6; // ax
  char *v7; // eax
  char *v8; // ebx
  int v9; // edx
  bool v10; // zf
  unsigned int v11; // ecx
  _DWORD *v12; // ebx
  bool (__cdecl *v13)(unsigned __int8 *const *, unsigned __int8 *const *); // eax
  int v14; // ebp
  bool (__cdecl *v15)(unsigned __int8 *const *, unsigned __int8 *const *); // eax
  bool (__cdecl *v16)(unsigned __int8 *const *, unsigned __int8 *const *); // ecx
  unsigned __int16 v17; // cx
  char *v18; // eax
  char *v19; // ebx
  int v20; // edx
  bool v21; // zf
  unsigned int v22; // ecx
  _DWORD *v23; // ebx
  bool (__cdecl *v24)(unsigned __int8 *const *, unsigned __int8 *const *); // eax
  int v25; // ebp
  char *_What; // [esp+4h] [ebp-18h] BYREF
  CMemoryMovingTracker::Item findMe; // [esp+8h] [ebp-14h] BYREF
  char v28; // [esp+14h] [ebp-8h]
  char v29; // [esp+15h] [ebp-7h]
  char v30; // [esp+16h] [ebp-6h]
  char v31; // [esp+17h] [ebp-5h]

  m_LessFunc = context[22].m_LessFunc;
  if ( m_LessFunc != nullptr )
  {
    v2 = context[4].m_LessFunc;
    v3 = (bool (__cdecl *)(unsigned __int8 *const *, unsigned __int8 *const *))((char *)m_LessFunc - 1);
    context[22].m_LessFunc = v3;
    v4 = (char *)context[20].m_LessFunc + 84 * (_DWORD)v3;
    if ( *((_BYTE *)v2 + *(_DWORD *)v4) != 0 )
    {
      _What = ".\\libedgegeomtool_partitioner.cpp(765)";
      std::exception::exception(this: (std::exception *)&findMe.ptr, (const char *const *)&_What);
      _CxxThrowException(pExceptionObject: &findMe.ptr, pThrowInfo: &_TI1_AVexception_std__);
    }
    context[14].m_LessFunc = *(bool (__cdecl **)(unsigned __int8 *const *, unsigned __int8 *const *))(v4 + 4);
    context[15].m_LessFunc = *(bool (__cdecl **)(unsigned __int8 *const *, unsigned __int8 *const *))(v4 + 8);
    v5 = *((float *)v4 + 3);
    --context[7].m_LessFunc;
    ++context[6].m_LessFunc;
    *(float *)&context[16].m_LessFunc = v5;
    *((_BYTE *)v2 + *(_DWORD *)v4) = 1;
    v6 = *((_WORD *)v4 + 38);
    if ( v6 != 0 )
    {
      qsort(base: v4 + 16, num: v6, width: 4u, comp: (int (__cdecl *)(const void *, const void *))_edgeGeomIsEqualInt);
      v7 = (char *)*((unsigned __int16 *)v4 + 38);
      v8 = v7;
      _What = v7;
      if ( (unsigned int)v7 > 3 )
      {
        _What = ".\\libedgegeomtool_partitioner.cpp(791)";
        std::exception::exception(this: (std::exception *)&findMe.ptr, (const char *const *)&_What);
        _CxxThrowException(pExceptionObject: &findMe.ptr, pThrowInfo: &_TI1_AVexception_std__);
      }
      v9 = 0;
      v10 = context[8].m_LessFunc == nullptr;
      LOWORD(findMe.idx) = 257;
      BYTE2(findMe.idx) = 1;
      if ( v10 )
      {
LABEL_17:
        v10 = v8 == nullptr;
      }
      else
      {
        while ( 1 )
        {
          v10 = v8 == nullptr;
          if ( v8 == nullptr )
            break;
          v11 = 0;
          if ( v7 != nullptr )
          {
            v12 = v4 + 16;
            do
            {
              if ( *((_BYTE *)&findMe.idx + v11) != 0 )
              {
                v13 = context[12].m_LessFunc;
                if ( *((_DWORD *)v13 + v9) == *v12 )
                {
                  v14 = *((_DWORD *)v13 + (int)context[8].m_LessFunc - v11 - 1);
                  --_What;
                  *((_DWORD *)v13 + v9) = v14;
                  *((_BYTE *)&findMe.idx + v11) = 0;
                }
              }
              v7 = (char *)*((unsigned __int16 *)v4 + 38);
              ++v11;
              ++v12;
            }
            while ( v11 < (unsigned int)v7 );
            v8 = _What;
          }
          if ( (char *)++v9 >= (char *)context[8].m_LessFunc )
            goto LABEL_17;
        }
      }
      if ( !v10 )
      {
        _What = ".\\libedgegeomtool_partitioner.cpp(805)";
        std::exception::exception(this: (std::exception *)&findMe.ptr, (const char *const *)&_What);
        _CxxThrowException(pExceptionObject: &findMe.ptr, pThrowInfo: &_TI1_AVexception_std__);
      }
      context[8].m_LessFunc = (bool (__cdecl *)(unsigned __int8 *const *, unsigned __int8 *const *))((char *)context[8].m_LessFunc - *((unsigned __int16 *)v4 + 38));
      v15 = context[8].m_LessFunc;
      v16 = context[12].m_LessFunc;
      context[10].m_LessFunc = (bool (__cdecl *)(unsigned __int8 *const *, unsigned __int8 *const *))((char *)context[10].m_LessFunc - *((unsigned __int16 *)v4 + 39));
      qsort(
        base: v16,
        num: (unsigned int)v15,
        width: 4u,
        comp: (int (__cdecl *)(const void *, const void *))_edgeGeomIsEqualInt);
    }
    v17 = *((_WORD *)v4 + 40);
    if ( v17 != 0 )
    {
      qsort(base: v4 + 28, num: v17, width: 4u, comp: (int (__cdecl *)(const void *, const void *))_edgeGeomIsEqualInt);
      v18 = (char *)*((unsigned __int16 *)v4 + 40);
      v19 = v18;
      _What = v18;
      if ( (unsigned int)v18 > 0xC )
      {
        _What = ".\\libedgegeomtool_partitioner.cpp(821)";
        std::exception::exception(this: (std::exception *)&findMe.ptr, (const char *const *)&_What);
        _CxxThrowException(pExceptionObject: &findMe.ptr, pThrowInfo: &_TI1_AVexception_std__);
      }
      v20 = 0;
      v10 = context[9].m_LessFunc == nullptr;
      findMe.ptr = (unsigned __int8 *)16843009;
      findMe.len = 16843009;
      v28 = 1;
      v29 = 1;
      v30 = 1;
      v31 = 1;
      if ( v10 )
      {
LABEL_34:
        v21 = v19 == nullptr;
      }
      else
      {
        while ( 1 )
        {
          v21 = v19 == nullptr;
          if ( v19 == nullptr )
            break;
          v22 = 0;
          if ( v18 != nullptr )
          {
            v23 = v4 + 28;
            do
            {
              if ( *((_BYTE *)&findMe.ptr + v22) != 0 )
              {
                v24 = context[13].m_LessFunc;
                if ( *((_DWORD *)v24 + v20) == *v23 )
                {
                  v25 = *((_DWORD *)v24 + (int)context[9].m_LessFunc - v22 - 1);
                  --_What;
                  *((_DWORD *)v24 + v20) = v25;
                  *((_BYTE *)&findMe.ptr + v22) = 0;
                }
              }
              v18 = (char *)*((unsigned __int16 *)v4 + 40);
              ++v22;
              ++v23;
            }
            while ( v22 < (unsigned int)v18 );
            v19 = _What;
          }
          if ( (char *)++v20 >= (char *)context[9].m_LessFunc )
            goto LABEL_34;
        }
      }
      if ( !v21 )
      {
        _What = ".\\libedgegeomtool_partitioner.cpp(835)";
        std::exception::exception(this: (std::exception *)&findMe.ptr, (const char *const *)&_What);
        _CxxThrowException(pExceptionObject: &findMe.ptr, pThrowInfo: &_TI1_AVexception_std__);
      }
      context[9].m_LessFunc = (bool (__cdecl *)(unsigned __int8 *const *, unsigned __int8 *const *))((char *)context[9].m_LessFunc - *((unsigned __int16 *)v4 + 40));
      qsort(
        base: context[13].m_LessFunc,
        num: (unsigned int)context[9].m_LessFunc,
        width: 4u,
        comp: (int (__cdecl *)(const void *, const void *))_edgeGeomIsEqualInt);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000DBE0
// Name: RemapAllTriangleLists
// Source: json
//------------------------------------------------------------------------------
void __usercall RemapAllTriangleLists(unsigned int *dataOut@<esi>)
{
  int v1; // edi
  _DWORD *v2; // eax
  unsigned int v3; // edx
  unsigned int *v4; // ebp
  unsigned int v5; // edi
  unsigned __int8 *v6; // ebx
  unsigned int v7; // edi
  unsigned int v8; // eax
  unsigned int v9; // eax
  int v10; // ecx
  unsigned __int8 *v11; // ebx
  VectorByValue *v12; // ecx
  unsigned int v13; // edi
  int v14; // ebx
  int v15; // ebp
  int v16; // [esp+Ch] [ebp-18h]
  unsigned int v17; // [esp+Ch] [ebp-18h]
  unsigned int *originalOrderLookup; // [esp+10h] [ebp-14h]
  unsigned int *numUniqueVertexesPerPartition; // [esp+14h] [ebp-10h]
  unsigned int *sortedUniqueIndexesPerPartition; // [esp+18h] [ebp-Ch]
  unsigned int *originalOrderLookupPerPartition; // [esp+1Ch] [ebp-8h]
  unsigned __int8 *v22; // [esp+20h] [ebp-4h]

  v1 = 0;
  if ( *dataOut != 0 )
  {
    v2 = (_DWORD *)dataOut[1];
    v3 = *dataOut;
    do
    {
      v1 += *v2++;
      --v3;
    }
    while ( v3 != 0 );
  }
  v4 = (unsigned int *)edgeGeomAllocEx(
                         allocSize: 4 * *dataOut,
                         a2: ".\\libedgegeomtool_partitioner.cpp",
                         lineNumber: 0x4B2u);
  v5 = 12 * v1;
  sortedUniqueIndexesPerPartition = v4;
  v6 = (unsigned __int8 *)edgeGeomAllocEx(allocSize: v5, a2: ".\\libedgegeomtool_partitioner.cpp", lineNumber: 0x4B3u);
  originalOrderLookupPerPartition = (unsigned int *)v6;
  memcpy(dst: v6, src: (unsigned __int8 *)dataOut[2], count: v5);
  v7 = 0;
  v16 = 0;
  if ( *dataOut != 0 )
  {
    v8 = dataOut[1];
    do
    {
      v9 = _edgeGeomSortUniqueArrayInt(array: (int *)v6, totalElements: 3 * *(_DWORD *)(v8 + 4 * v7));
      v16 += v9;
      v4[v7] = v9;
      v8 = dataOut[1];
      v10 = *(_DWORD *)(v8 + 4 * v7++);
      v6 += 12 * v10;
    }
    while ( v7 < *dataOut );
  }
  v11 = (unsigned __int8 *)edgeGeomAllocEx(
                             allocSize: 4 * v16,
                             a2: ".\\libedgegeomtool_partitioner.cpp",
                             lineNumber: 0x4C3u);
  v22 = v11;
  memset(dst: v11, value: 0xFFu, count: 4 * v16);
  v13 = 0;
  originalOrderLookup = originalOrderLookupPerPartition;
  numUniqueVertexesPerPartition = (unsigned int *)v11;
  v17 = dataOut[2];
  if ( *dataOut != 0 )
  {
    do
    {
      v14 = *(_DWORD *)(dataOut[1] + 4 * v13);
      v15 = 4 * v4[v13];
      _edgeGeomRemapTriangleList();
      numUniqueVertexesPerPartition = (unsigned int *)((char *)numUniqueVertexesPerPartition + v15);
      v4 = sortedUniqueIndexesPerPartition;
      v17 += 12 * v14;
      originalOrderLookup += 3 * v14;
      ++v13;
    }
    while ( v13 < *dataOut );
    v11 = v22;
  }
  edgeGeomFreeEx(this: v12);
  dataOut[4] = (unsigned int)v4;
  dataOut[3] = (unsigned int)v11;
}

//------------------------------------------------------------------------------
// Address: 0x1000DD40
// Name: ScoreTriangle
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
double __usercall ScoreTriangle@<st0>(
        int a1@<edi>,
        int a2@<esi>,
        unsigned int result,
        unsigned int *actualBytesUsed,
        bool exactCalc)
{
  signed int *v5; // eax
  unsigned int v6; // ebp
  int v7; // edx
  char v8; // cl
  int v9; // ebx
  const void *v10; // eax
  const void *v11; // eax
  unsigned int i; // ebx
  float v13; // eax
  bool v14; // zf
  unsigned int v15; // eax
  unsigned int v16; // ebx
  unsigned __int8 *v17; // ebp
  unsigned int v18; // ecx
  double v19; // st7
  char *v20; // ecx
  int v21; // edx
  unsigned int v22; // ebx
  unsigned __int8 *v23; // ebp
  void (__cdecl *v24)(_DWORD, unsigned int, _DWORD, unsigned __int8 *); // eax
  unsigned int v25; // ebx
  VectorByValue *v26; // ecx
  double v27; // st6
  int v28; // eax
  int v29; // eax
  IUnknown *v30; // edx
  int v31; // ebp
  unsigned int v32; // ebx
  IUnknown *v33; // eax
  int (__cdecl *v34)(std::exception *); // eax
  const char *v35; // edx
  int v36; // eax
  int v37; // eax
  char *v38; // ebp
  char *v39; // ebp
  unsigned int v40; // eax
  unsigned int v41; // ebx
  unsigned int v42; // ebp
  CLoggingSystem::LoggingChannel_t *CommandBufferHoleSize; // eax
  unsigned int v44; // eax
  double v45; // st6
  double v46; // st7
  double v47; // st5
  double v48; // st3
  double v49; // rt1
  unsigned int v50; // [esp-Ch] [ebp-8Ch]
  int minMatrix; // [esp+8h] [ebp-78h]
  int minMatrixa; // [esp+8h] [ebp-78h]
  signed int newNumTriangles; // [esp+Ch] [ebp-74h]
  unsigned int newNumTrianglesa; // [esp+Ch] [ebp-74h]
  unsigned int numMatricesToUpload; // [esp+10h] [ebp-70h]
  unsigned int biggestGap; // [esp+14h] [ebp-6Ch]
  unsigned int userIoBufferUsed; // [esp+18h] [ebp-68h] BYREF
  IUnknown *ioBufferScore; // [esp+1Ch] [ebp-64h]
  double v59; // [esp+20h] [ebp-60h]
  float key; // [esp+28h] [ebp-58h] BYREF
  VectorByValue *v61; // [esp+2Ch] [ebp-54h]
  __int64 _What; // [esp+34h] [ebp-4Ch] OVERLAPPED BYREF
  float v63; // [esp+3Ch] [ebp-44h]
  std::exception pExceptionObject; // [esp+40h] [ebp-40h] BYREF
  CMemoryMovingTracker *newMatrices; // [esp+4Ch] [ebp-34h]
  int src[12]; // [esp+50h] [ebp-30h] BYREF

  v5 = *(signed int **)(a2 + 52);
  v6 = 0;
  if ( v5 != nullptr && (v7 = *(_DWORD *)(a2 + 36)) != 0 )
  {
    v8 = 1;
    newNumTriangles = *v5;
    minMatrix = v5[v7 - 1];
  }
  else
  {
    v8 = 0;
    newNumTriangles = 0x7FFFFFFF;
    minMatrix = 0;
  }
  ioBufferScore = nullptr;
  numMatricesToUpload = *(_DWORD *)(a2 + 28) + (result != -1);
  if ( v8 != 0 )
    biggestGap = minMatrix - newNumTriangles + 1;
  else
    biggestGap = 0;
  if ( result != -1 )
  {
    v9 = 12 * result;
    LODWORD(v59) = 12 * result;
    LODWORD(_What) = 3;
    do
    {
      v10 = *(const void **)(a2 + 48);
      v50 = *(_DWORD *)(a2 + 32);
      userIoBufferUsed = *(_DWORD *)(v9 + *(_DWORD *)(a1 + 4));
      if ( bsearch(
             key: &userIoBufferUsed,
             base: v10,
             num: v50,
             width: 4u,
             compare: (int (__cdecl *)(const void *, const void *))_edgeGeomIsEqualInt) == nullptr )
      {
        v11 = *(const void **)(a1 + 64);
        ioBufferScore = (IUnknown *)((char *)ioBufferScore + 1);
        if ( v11 != nullptr )
          bsearch(
            key: &userIoBufferUsed,
            base: v11,
            num: *(_DWORD *)(a1 + 68),
            width: 4u,
            compare: (int (__cdecl *)(const void *, const void *))_edgeGeomIsEqualInt);
        if ( *(_DWORD *)(a2 + 52) != 0 )
        {
          for ( i = 0; i < 4; ++i )
          {
            key = *(float *)(*(_DWORD *)(a1 + 56) + 4 * (i + 4 * userIoBufferUsed));
            if ( key != NAN
              && bsearch(
                   &key,
                   base: *(const void **)(a2 + 52),
                   num: *(_DWORD *)(a2 + 36),
                   width: 4u,
                   compare: (int (__cdecl *)(const void *, const void *))_edgeGeomIsEqualInt) == nullptr )
            {
              v13 = key;
              *(float *)&src[v6++] = key;
              if ( newNumTriangles > SLODWORD(v13) )
                newNumTriangles = LODWORD(v13);
              if ( minMatrix < SLODWORD(v13) )
                minMatrix = LODWORD(v13);
            }
          }
          v9 = LODWORD(v59);
        }
      }
      v9 += 4;
      v14 = (_DWORD)_What == 1;
      LODWORD(_What) = _What - 1;
      LODWORD(v59) = v9;
    }
    while ( !v14 );
    if ( v6 != 0 )
    {
      biggestGap = minMatrix - newNumTriangles + 1;
      if ( biggestGap > 0x100 )
      {
        v15 = _edgeGeomSortUniqueArrayInt(array: src, totalElements: v6);
        v16 = v15 + *(_DWORD *)(a2 + 36);
        LODWORD(_What) = v15;
        v17 = (unsigned __int8 *)edgeGeomAllocEx(
                                   allocSize: 4 * v16,
                                   a2: ".\\libedgegeomtool_partitioner.cpp",
                                   lineNumber: 0x394u);
        memcpy(dst: v17, src: *(unsigned __int8 **)(a2 + 52), count: 4 * *(_DWORD *)(a2 + 36));
        memcpy(dst: &v17[4 * *(_DWORD *)(a2 + 36)], (unsigned __int8 *)src, count: 4 * _What);
        qsort(base: v17, num: v16, width: 4u, comp: (int (__cdecl *)(const void *, const void *))_edgeGeomIsEqualInt);
        v18 = 1;
        for ( userIoBufferUsed = 0; v18 < v16; ++v18 )
        {
          if ( *(_DWORD *)&v17[4 * v18] - *(_DWORD *)&v17[4 * v18 - 4] - 1 > (int)userIoBufferUsed )
            userIoBufferUsed = *(_DWORD *)&v17[4 * v18] - *(_DWORD *)&v17[4 * v18 - 4] - 1;
        }
        edgeGeomFreeEx(this: (VectorByValue *)v18);
        biggestGap = minMatrix - userIoBufferUsed - newNumTriangles + 1;
        if ( biggestGap > 0x100 )
          return 3.4028235e38;
      }
    }
  }
  v20 = (char *)ioBufferScore + *(_DWORD *)(a2 + 32);
  v21 = *(_DWORD *)(a1 + 32);
  v22 = (unsigned int)(v20 + 7) & 0xFFFFFFF8;
  newNumTrianglesa = v22;
  LODWORD(v63) = (6 * numMatricesToUpload + 15) & 0xFFFFFFF0;
  switch ( v21 )
  {
    case 0:
    case 1:
      userIoBufferUsed = (6 * numMatricesToUpload + 15) & 0xFFFFFFF0;
      LODWORD(v59) = 0;
      break;
    case 2:
    case 3:
      if ( exactCalc )
      {
        if ( result != -1 )
        {
          *(_DWORD *)(*(_DWORD *)(a2 + 44) + 12 * *(_DWORD *)(a2 + 28)) = *(_DWORD *)(12 * result + *(_DWORD *)(a1 + 4));
          *(_DWORD *)(*(_DWORD *)(a2 + 44) + 12 * *(_DWORD *)(a2 + 28) + 4) = *(_DWORD *)(12 * result
                                                                                        + *(_DWORD *)(a1 + 4)
                                                                                        + 4);
          *(_DWORD *)(*(_DWORD *)(a2 + 44) + 12 * *(_DWORD *)(a2 + 28) + 8) = *(_DWORD *)(12 * result
                                                                                        + *(_DWORD *)(a1 + 4)
                                                                                        + 8);
        }
        v23 = (unsigned __int8 *)edgeGeomAllocEx(
                                   allocSize: 12 * numMatricesToUpload,
                                   a2: ".\\libedgegeomtool_partitioner.cpp",
                                   lineNumber: 0x3D6u);
        v24 = *(void (__cdecl **)(_DWORD, unsigned int, _DWORD, unsigned __int8 *))(a1 + 40);
        if ( v24 != nullptr )
        {
          v25 = numMatricesToUpload;
          v24(a1: *(_DWORD *)(a2 + 44), a2: numMatricesToUpload, a3: *(_DWORD *)(a1 + 44), a4: v23);
        }
        else
        {
          memcpy(dst: v23, src: *(unsigned __int8 **)(a2 + 44), count: 12 * numMatricesToUpload);
          v25 = numMatricesToUpload;
        }
        _edgeGeomMeasureCompressedIndexTable(
          src: v23,
          numTriangles: v25,
          a3: *(enum EdgeGeomIndexesFlavor *)(a1 + 32),
          indexesSizes: (tagSAFEARRAY **)&key);
        v26 = v61;
        userIoBufferUsed = LODWORD(key);
        LODWORD(v59) = v61;
        *(float *)(a2 + 68) = key;
        *(_DWORD *)(a2 + 72) = v26;
        *(_DWORD *)(a2 + 76) = v25;
        edgeGeomFreeEx(this: v26);
        v22 = newNumTrianglesa;
      }
      else
      {
        LODWORD(_What) = numMatricesToUpload - *(_DWORD *)(a2 + 76);
        key = (float)(unsigned int)_What;
        *(float *)&_What = log((double)(unsigned int)v20);
        v59 = *(float *)&_What * 1.5;
        *(float *)&_What = log(2.0);
        *(float *)&_What = v59 / *(float *)&_What + 5.0;
        *(float *)&_What = *(float *)&_What * key;
        v27 = *(float *)&_What;
        LODWORD(_What) = (unsigned __int16)minMatrix | 0xC00;
        v28 = *(_DWORD *)(a2 + 68);
        _What = (__int64)((v27 + 7.0) * -0.125);
        userIoBufferUsed = v28 - _What;
        LODWORD(_What) = (unsigned __int16)minMatrix | 0xC00;
        v29 = *(_DWORD *)(a2 + 72);
        _What = (__int64)(key * -12.25);
        LODWORD(v59) = v29 - _What;
      }
      break;
    default:
      LODWORD(_What) = ".\\libedgegeomtool_partitioner.cpp(1031)";
      std::exception::exception(this: &pExceptionObject, (const char *const *)&_What);
      _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI1_AVexception_std__);
      return v19;
  }
  v30 = *(IUnknown **)(a1 + 8);
  v31 = 16 * ((_DWORD)&v30->__vftable + 1);
  v14 = *(_DWORD *)(a2 + 40) == 0;
  LODWORD(key) = 8 * *(_DWORD *)(a1 + 12) + 16;
  if ( v14 )
  {
    minMatrixa = 0;
    v32 = 0;
  }
  else
  {
    if ( newNumTrianglesa > 0x800 )
      return 3.4028235e38;
    v32 = v31
        + 16 * ((_DWORD)&v30->__vftable + 2)
        + ((v22 * *(_DWORD *)(a1 + 60) + 15) & 0xFFFFFFF0)
        + ((2 * (newNumTrianglesa >> 1) + 17) & 0xFFFFFFF0);
    minMatrixa = v32;
  }
  v33 = *(IUnknown **)(a1 + 12);
  ioBufferScore = v30;
  if ( v30 <= v33 )
    ioBufferScore = v33;
  LODWORD(_What) = 16 * edgeGeomGetScratchBufferSizeInQwords(a1: (unsigned int)ioBufferScore, a2: newNumTrianglesa);
  if ( (unsigned int)&ioBufferScore->__vftable + 1 > 0x10 )
  {
    LODWORD(_What) = ".\\libedgegeomtool_partitioner.cpp(1073)";
    std::exception::exception(this: (std::exception *)&key, (const char *const *)&_What);
    _CxxThrowException(pExceptionObject: &key, pThrowInfo: &_TI1_AVexception_std__);
  }
  v34 = *(int (__cdecl **)(std::exception *))(a1 + 48);
  ioBufferScore = nullptr;
  if ( v34 != nullptr )
  {
    v35 = *(const char **)(a2 + 32);
    pExceptionObject.__vftable = *(std::exception_vtbl **)(a2 + 28);
    *(_DWORD *)&pExceptionObject._Mydofree = *(_DWORD *)(a2 + 36);
    pExceptionObject._Mywhat = v35;
    newMatrices = *(CMemoryMovingTracker **)(a2 + 40);
    ioBufferScore = (IUnknown *)v34(a1: &pExceptionObject);
  }
  v36 = *(_DWORD *)(a1 + 28);
  if ( v36 == 4 || v36 == 5 || v36 == 6 )
    v37 = 1;
  else
    v37 = 2 * *(_DWORD *)(a2 + 20);
  v38 = (char *)&ioBufferScore[48] + LODWORD(key) + v31;
  if ( biggestGap != 0 )
    v38 += newNumTrianglesa * v37 + biggestGap * (*(_DWORD *)(a1 + 36) != 0 ? 64 : 48) + 127;
  v39 = &v38[16 * *(_DWORD *)(a1 + 8)];
  v40 = ((newNumTrianglesa * *(_DWORD *)(a1 + 16) + 15) & 0xFFFFFFF0)
      + ((newNumTrianglesa * *(_DWORD *)(a1 + 20) + 15) & 0xFFFFFFF0);
  if ( v40 <= v32 )
    v40 = v32;
  v41 = (unsigned int)&v39[v40 + 127 + userIoBufferUsed] & 0xFFFFFF80;
  v42 = (LODWORD(key) + LODWORD(v59) + 127) & 0xFFFFFF80;
  CommandBufferHoleSize = edgeGeomGetCommandBufferHoleSize(
                            result: *(CLoggingSystem::LoggingChannel_t **)(a1 + 12),
                            numIndexes: 3 * numMatricesToUpload,
                            customHoleSizeCallback: *(const CLoggingSystem::LoggingChannel_t **)(a1 + 72));
  v44 = (int)&CommandBufferHoleSize[5].m_Name[(_DWORD)ioBufferScore
                                            + 11
                                            + LODWORD(key)
                                            + LODWORD(v63)
                                            + ((newNumTrianglesa * *(_DWORD *)(a1 + 24) + 15) & 0xFFFFFFF0)]
      & 0xFFFFFF80;
  if ( v44 <= v41 )
    v44 = v41;
  if ( v44 > v42 )
    v42 = v44;
  *actualBytesUsed = v42;
  *(float *)&v59 = (double)v42 / 49152.0;
  v63 = (double)userIoBufferUsed * 0.000030517578125;
  key = (double)(unsigned int)minMatrixa * 0.00006103515625;
  *(float *)&_What = (double)((unsigned int)_What + v42) / 116736.0;
  v45 = v63;
  v46 = key;
  if ( key < (double)v63 )
    key = v63;
  v47 = *(float *)&_What;
  if ( *(float *)&_What < (double)*(float *)&v59 )
    *(float *)&_What = *(float *)&v59;
  v48 = *(float *)&_What;
  if ( key >= (double)*(float *)&_What )
    v48 = key;
  *(float *)&_What = v48;
  if ( *(float *)&_What > 1.0 )
    return *(float *)&_What;
  v49 = *(float *)&_What;
  *(float *)(a2 + 92) = *(float *)&v59;
  *(float *)(a2 + 96) = v47;
  *(float *)(a2 + 104) = v45;
  *(float *)(a2 + 100) = v46;
  return v49;
}

//------------------------------------------------------------------------------
// Address: 0x1000E4E0
// Name: FinalizePartition
// Source: json
//------------------------------------------------------------------------------
void __usercall FinalizePartition(int a1@<eax>, _DWORD *a2@<ecx>, _DWORD *a3@<ebx>)
{
  char v5; // al
  unsigned int finalTriangleScore; // [esp+Ch] [ebp-14h] BYREF
  char *_What; // [esp+10h] [ebp-10h] BYREF
  std::exception pExceptionObject; // [esp+14h] [ebp-Ch] BYREF

  finalTriangleScore = 0;
  while ( 1 )
  {
    *(float *)&_What = ScoreTriangle(
                         a1: (int)a2,
                         a2: a1,
                         result: 0xFFFFFFFF,
                         actualBytesUsed: &finalTriangleScore,
                         exactCalc: true);
    ++g_exactScoreCount;
    ++g_regularScoreCount;
    if ( *(float *)&_What <= 1.0 )
      break;
    RemoveLastTriangleFromPartition(context: (const CUtlMap<unsigned char *,int,unsigned int>::CKeyLess *)a1);
    if ( v5 == 0 )
    {
      *(float *)&_What = COERCE_FLOAT(".\\libedgegeomtool_partitioner.cpp(1167)");
      std::exception::exception(this: &pExceptionObject, (const char *const *)&_What);
      _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI1_AVexception_std__);
    }
  }
  *(_DWORD *)(a3[1] + 4 * *a3) = *(_DWORD *)(a1 + 28);
  *(_DWORD *)(a3[5] + 4 * (*a3)++) = finalTriangleScore;
  memcpy(
    dst: (unsigned __int8 *)(a3[2] + 12 * (*a2 - *(_DWORD *)(a1 + 24) - *(_DWORD *)(a1 + 28))),
    src: *(unsigned __int8 **)(a1 + 44),
    count: 12 * *(_DWORD *)(a1 + 28));
}

//------------------------------------------------------------------------------
// Address: 0x1000E5D0
// Name: void edgeGeomPartitioner(struct EdgeGeomPartitionerInput const __near &,struct EdgeGeomPartitionerOutput __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __cdecl edgeGeomPartitioner(_LARGE_INTEGER *dataOut, struct EdgeGeomPartitionerOutput *mask)
{
  struct EdgeGeomPartitionerOutput *v2; // ebp
  unsigned int LowPart; // esi
  int HighPart; // ebx
  unsigned int v5; // edx
  unsigned int v6; // eax
  unsigned int v7; // ecx
  unsigned int v8; // edx
  unsigned __int8 *v9; // eax
  unsigned int v10; // eax
  bool v11; // zf
  unsigned int FirstAvailableTriangle; // ebx
  unsigned int v13; // ecx
  int v14; // eax
  unsigned int v15; // ebx
  unsigned int v16; // ebp
  float *v17; // eax
  unsigned int v18; // eax
  IUnknown *v19; // ebx
  double v20; // st7
  VectorByValue *v21; // ecx
  VectorByValue *v22; // ecx
  VectorByValue *v23; // ecx
  VectorByValue *v24; // ecx
  unsigned int v25; // ebp
  unsigned __int8 *v26; // ebx
  VectorByValue *v27; // ecx
  bool v28; // cf
  unsigned int v29; // [esp-20h] [ebp-C8h]
  _is_ctype_compatible v30; // [esp-18h] [ebp-C0h]
  _is_ctype_compatible v31; // [esp-18h] [ebp-C0h]
  int v32; // [esp-Ch] [ebp-B4h]
  unsigned int iPartition; // [esp+8h] [ebp-A0h] BYREF
  unsigned int *currentTriangles; // [esp+Ch] [ebp-9Ch]
  IUnknown *deltaY; // [esp+10h] [ebp-98h]
  unsigned int iVertex; // [esp+14h] [ebp-94h] BYREF
  float bestDistanceSq; // [esp+18h] [ebp-90h] BYREF
  unsigned int v38; // [esp+1Ch] [ebp-8Ch]
  std::exception pExceptionObject; // [esp+20h] [ebp-88h] BYREF
  unsigned __int8 dst[108]; // [esp+2Ch] [ebp-7Ch] OVERLAPPED BYREF
  float triangleScore; // [esp+98h] [ebp-10h]
  IUnknown *deltaZ; // [esp+9Ch] [ebp-Ch]
  unsigned int newctrl; // [esp+A0h] [ebp-8h]
  float v44; // [esp+A4h] [ebp-4h]

  newctrl = _controlfp(newctrl: 0, mask: 0);
  _controlfp(newctrl: 0x20000u, mask: 0x30000u);
  if ( dataOut->LowPart != 0 )
  {
    memset(dst, value: 0, count: sizeof(dst));
    v2 = mask;
    mask->m_numPartitions = 0;
    mask->m_numTrianglesPerPartition = (unsigned int *)edgeGeomAllocEx(
                                                         allocSize: 4 * dataOut->LowPart,
                                                         a2: ".\\libedgegeomtool_partitioner.cpp",
                                                         lineNumber: 0x4F6u);
    mask->m_triangleListOut = (unsigned int *)edgeGeomAllocEx(
                                                allocSize: 12 * dataOut->LowPart,
                                                a2: ".\\libedgegeomtool_partitioner.cpp",
                                                lineNumber: 0x4F7u);
    mask->m_ioBufferSizePerPartition = (unsigned int *)edgeGeomAllocEx(
                                                         allocSize: 4 * dataOut->LowPart,
                                                         a2: ".\\libedgegeomtool_partitioner.cpp",
                                                         lineNumber: 0x4F8u);
    LowPart = dataOut->LowPart;
    HighPart = dataOut->HighPart;
    v5 = 3 * dataOut->LowPart;
    v6 = 0;
    v7 = 0;
    if ( v5 != 0 )
    {
      do
      {
        if ( *(_DWORD *)(HighPart + 4 * v7) > v6 )
          v6 = *(_DWORD *)(HighPart + 4 * v7);
        ++v7;
      }
      while ( v7 < v5 );
      v2 = mask;
    }
    v8 = dataOut[7].LowPart;
    v32 = dataOut->HighPart;
    *(_DWORD *)dst = v6;
    *(_DWORD *)&dst[4] = FindHighestMatrixIndex(a1: LowPart, a2: v8, a3: v32);
    FindAdjacentTriangles(context: (const CUtlRBTree<CUtlMap<unsigned char *,int,unsigned int>::Node_t,unsigned int,CUtlMap<unsigned char *,int,unsigned int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned char *,int,unsigned int>::Node_t,unsigned int>,unsigned int> > *)dst);
    v9 = (unsigned __int8 *)edgeGeomAllocEx(
                              allocSize: dataOut->LowPart,
                              a2: ".\\libedgegeomtool_partitioner.cpp",
                              lineNumber: 0x502u);
    v29 = dataOut->LowPart;
    *(_DWORD *)&dst[16] = v9;
    memset(dst: v9, value: 1u, count: v29);
    *(_DWORD *)&dst[44] = edgeGeomAllocEx(
                            allocSize: 12 * dataOut->LowPart,
                            a2: ".\\libedgegeomtool_partitioner.cpp",
                            lineNumber: 0x508u);
    *(_DWORD *)&dst[48] = edgeGeomAllocEx(
                            allocSize: 4 * *(_DWORD *)dst + 4,
                            a2: ".\\libedgegeomtool_partitioner.cpp",
                            lineNumber: 0x509u);
    if ( *(_DWORD *)&dst[4] == -1 )
      *(_DWORD *)&dst[52] = 0;
    else
      *(_DWORD *)&dst[52] = edgeGeomAllocEx(
                              allocSize: 4 * *(_DWORD *)&dst[4] + 4,
                              a2: ".\\libedgegeomtool_partitioner.cpp",
                              lineNumber: 0x50Au);
    *(_DWORD *)&dst[84] = 10000;
    *(_DWORD *)&dst[80] = edgeGeomAllocEx(
                            allocSize: 0xCD140u,
                            a2: ".\\libedgegeomtool_partitioner.cpp",
                            lineNumber: 0x50Fu);
    v10 = dataOut->LowPart;
    v11 = dataOut->LowPart == 0;
    *(_DWORD *)&dst[88] = 0;
    *(_DWORD *)&dst[20] = 4;
    *(_DWORD *)&dst[24] = v10;
    g_exactScoreCount = 0;
    g_regularScoreCount = 0;
    if ( !v11 )
    {
      do
      {
        if ( *(_DWORD *)&dst[28] == 0 )
        {
          FirstAvailableTriangle = FindFirstAvailableTriangle(
                                     a1: (int)dst,
                                     result: dataOut->LowPart,
                                     a3: dataOut[6].HighPart);
          if ( FirstAvailableTriangle == -1 )
          {
            *(float *)&iPartition = COERCE_FLOAT(".\\libedgegeomtool_partitioner.cpp(1326)");
            std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&iPartition);
            _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI1_AVexception_std__);
          }
          bestDistanceSq = 0.0;
          bestDistanceSq = ScoreTriangle(
                             a1: (int)dataOut,
                             a2: (int)dst,
                             result: FirstAvailableTriangle,
                             actualBytesUsed: (unsigned int *)&bestDistanceSq,
                             exactCalc: false);
          ++g_regularScoreCount;
          if ( bestDistanceSq > 1.0 )
          {
            printf(
              format: "SERIOUS ERROR: one-triangle partition won't fit in SPU local store! Contact the Playstation Edge developers!\n");
            *(float *)&iPartition = COERCE_FLOAT(".\\libedgegeomtool_partitioner.cpp(1336)");
            std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&iPartition);
            _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI1_AVexception_std__);
          }
          v30.is_clike = dataOut[8].LowPart;
          v30.id = dataOut[7].LowPart;
          AssignTriangleToPartition(
            context: (unsigned int)dst,
            a2: dataOut->HighPart,
            numMatricesAdded: FirstAvailableTriangle,
            matricesPerVertex: v30,
            numBlendedVertexes: dataOut[8].HighPart,
            a6: dataOut[6].HighPart);
        }
        v13 = 0;
        *(float *)&currentTriangles = 3.4028235e38;
        *(float *)&v38 = 3.4028235e38;
        deltaY = (IUnknown *)-1;
        for ( bestDistanceSq = 0.0; v13 < *(_DWORD *)&dst[32]; bestDistanceSq = *(float *)&v13 )
        {
          v14 = *(_DWORD *)(*(_DWORD *)&dst[48] + 4 * v13);
          v15 = *(_DWORD *)(*(_DWORD *)&dst[8] + 4 * v14);
          if ( v15 < *(_DWORD *)(*(_DWORD *)&dst[8] + 4 * v14 + 4) )
          {
            iPartition = 4 * v14 + 4;
            do
            {
              v16 = *(_DWORD *)(*(_DWORD *)&dst[12] + 4 * v15);
              if ( *(_BYTE *)(*(_DWORD *)&dst[16] + v16) != 0 )
              {
                *(float *)&iVertex = 0.0;
                *(float *)&deltaZ = ScoreTriangle(
                                      a1: (int)dataOut,
                                      a2: (int)dst,
                                      result: v16,
                                      actualBytesUsed: &iVertex,
                                      exactCalc: false);
                ++g_regularScoreCount;
                *(float *)&iVertex = 3.4028235e38;
                if ( dataOut[6].HighPart != 0 )
                {
                  v17 = (float *)(dataOut[6].HighPart + 12 * v16);
                  triangleScore = *v17 - *(float *)&dst[56];
                  *(float *)&iVertex = v17[1] - *(float *)&dst[60];
                  v44 = v17[2] - *(float *)&dst[64];
                  *(float *)&iVertex = *(float *)&iVertex * *(float *)&iVertex
                                     + triangleScore * triangleScore
                                     + v44 * v44;
                }
                if ( *(float *)&currentTriangles >= (double)*(float *)&deltaZ
                  && (*(float *)&deltaZ != *(float *)&currentTriangles || *(float *)&v38 > (double)*(float *)&iVertex) )
                {
                  deltaY = (IUnknown *)v16;
                  currentTriangles = (unsigned int *)deltaZ;
                  v38 = iVertex;
                }
              }
              ++v15;
            }
            while ( v15 < *(_DWORD *)(iPartition + *(_DWORD *)&dst[8]) );
            v2 = mask;
            v13 = LODWORD(bestDistanceSq);
          }
          ++v13;
        }
        if ( *(_DWORD *)&dst[24] != 0 && deltaY == (IUnknown *)-1 )
        {
          v18 = FindFirstAvailableTriangle(a1: (int)dst, result: dataOut->LowPart, a3: dataOut[6].HighPart);
          v19 = (IUnknown *)v18;
          if ( v18 == -1 )
          {
            *(float *)&iPartition = COERCE_FLOAT(".\\libedgegeomtool_partitioner.cpp(1395)");
            std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&iPartition);
            _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI1_AVexception_std__);
          }
          *(float *)&iPartition = 0.0;
          *(float *)&iPartition = ScoreTriangle(
                                    a1: (int)dataOut,
                                    a2: (int)dst,
                                    result: v18,
                                    actualBytesUsed: &iPartition,
                                    exactCalc: false);
          ++g_regularScoreCount;
          if ( *(float *)&currentTriangles > (double)*(float *)&iPartition )
          {
            currentTriangles = (unsigned int *)iPartition;
            deltaY = v19;
          }
        }
        v20 = 1.0;
        if ( *(float *)&currentTriangles > 1.0 && deltaY != (IUnknown *)-1 )
        {
          *(float *)&iPartition = 0.0;
          *(float *)&iPartition = ScoreTriangle(
                                    a1: (int)dataOut,
                                    a2: (int)dst,
                                    result: (unsigned int)deltaY,
                                    actualBytesUsed: &iPartition,
                                    exactCalc: true);
          v20 = 1.0;
          if ( *(float *)&iPartition <= 1.0 )
          {
            currentTriangles = (unsigned int *)iPartition;
            *(_DWORD *)&dst[88] = 0;
          }
          ++g_exactScoreCount;
          ++g_regularScoreCount;
        }
        if ( v20 < *(float *)&currentTriangles )
        {
          if ( *(_DWORD *)&dst[28] == 0 && *(_DWORD *)&dst[24] != 0 )
          {
            printf(
              format: "SERIOUS ERROR: %d triangles could not be assigned to any partition!  Contact the Playstation Edge developers!\n",
              *(_DWORD *)&dst[24]);
            *(float *)&iPartition = COERCE_FLOAT(".\\libedgegeomtool_partitioner.cpp(1454)");
            std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&iPartition);
            _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI1_AVexception_std__);
          }
          FinalizePartition(a1: (int)dst, a2: dataOut, a3: v2);
          memset(&dst[28], 0, 16);
          memset(&dst[68], 0, 12);
          *(_DWORD *)&dst[88] = 0;
        }
        else
        {
          v31.is_clike = dataOut[8].LowPart;
          v31.id = dataOut[7].LowPart;
          AssignTriangleToPartition(
            context: (unsigned int)dst,
            a2: dataOut->HighPart,
            numMatricesAdded: (unsigned int)deltaY,
            matricesPerVertex: v31,
            numBlendedVertexes: dataOut[8].HighPart,
            a6: dataOut[6].HighPart);
        }
      }
      while ( *(_DWORD *)&dst[24] != 0 );
    }
    if ( *(_DWORD *)&dst[28] != 0 )
      FinalizePartition(a1: (int)dst, a2: dataOut, a3: v2);
    edgeGeomFreeEx(this: *(VectorByValue **)&dst[8]);
    edgeGeomFreeEx(this: v21);
    edgeGeomFreeEx(this: v22);
    edgeGeomFreeEx(this: *(VectorByValue **)&dst[44]);
    edgeGeomFreeEx(this: v23);
    edgeGeomFreeEx(this: v24);
    edgeGeomFreeEx(this: *(VectorByValue **)&dst[80]);
    if ( dataOut[5].LowPart != 0 )
    {
      v11 = v2->m_numPartitions == 0;
      deltaY = (IUnknown *)v2->m_triangleListOut;
      *(float *)&currentTriangles = 0.0;
      if ( !v11 )
      {
        do
        {
          v25 = v2->m_numTrianglesPerPartition[(_DWORD)currentTriangles];
          v26 = (unsigned __int8 *)edgeGeomAllocEx(
                                     allocSize: 12 * v25,
                                     a2: ".\\libedgegeomtool_partitioner.cpp",
                                     lineNumber: 0x5DFu);
          memcpy(dst: v26, src: (unsigned __int8 *)deltaY, count: 12 * v25);
          ((void (__cdecl *)(unsigned __int8 *, unsigned int, int, IUnknown *))dataOut[5].LowPart)(
            a1: v26,
            a2: v25,
            a3: dataOut[5].HighPart,
            a4: deltaY);
          edgeGeomFreeEx(this: v27);
          deltaY += 3 * v25;
          v28 = (unsigned int)currentTriangles + 1 < mask->m_numPartitions;
          currentTriangles = (unsigned int *)((char *)currentTriangles + 1);
          v2 = mask;
        }
        while ( v28 );
      }
    }
    RemapAllTriangleLists(dataOut: &v2->m_numPartitions);
    _controlfp(newctrl, mask: 0xFFFFFFFF);
  }
  else
  {
    mask->m_numTrianglesPerPartition = nullptr;
    mask->m_numPartitions = 0;
    mask->m_triangleListOut = nullptr;
    mask->m_ioBufferSizePerPartition = nullptr;
  }
}
