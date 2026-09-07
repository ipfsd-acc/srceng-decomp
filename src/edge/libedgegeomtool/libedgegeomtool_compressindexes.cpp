// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: edge/libedgegeomtool/libedgegeomtool_compressindexes.cpp
// Functions: 8
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10010050
// Name: FillDeltaBlockBuffer
// Source: json
//------------------------------------------------------------------------------
void __cdecl FillDeltaBlockBuffer(
        unsigned int numFinalIndexes,
        unsigned int a2,
        unsigned __int8 *deltaBlock,
        unsigned int bitsPerIndex,
        unsigned int deltaOffset)
{
  unsigned int v6; // edx
  int v7; // esi
  unsigned int v8; // ebx
  int v9; // edi
  int v10; // eax
  char v11; // cl
  unsigned int v12; // eax
  std::exception pExceptionObject; // [esp+10h] [ebp-Ch] BYREF

  v6 = 0;
  v7 = 0;
  v8 = 0;
  v9 = (1 << bitsPerIndex) - 1;
  if ( a2 != 0 )
  {
    do
    {
      v10 = deltaOffset + *(_DWORD *)(numFinalIndexes + 4 * v8);
      if ( v10 < 0 )
      {
        bitsPerIndex = (unsigned int)".\\libedgegeomtool_compressindexes.cpp(25)";
        std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&bitsPerIndex);
        _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI1_AVexception_std__);
      }
      v11 = 32 - v6 - bitsPerIndex;
      v6 += bitsPerIndex;
      v7 |= (v9 & v10) << v11;
      if ( v6 >= 8 )
      {
        v12 = v6 >> 3;
        do
        {
          *deltaBlock = HIBYTE(v7);
          v6 -= 8;
          ++deltaBlock;
          v7 <<= 8;
          --v12;
        }
        while ( v12 != 0 );
      }
      ++v8;
    }
    while ( v8 < a2 );
    if ( v6 != 0 )
      *deltaBlock = HIBYTE(v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010100
// Name: ConvertIndexesToDeltas
// Source: json
//------------------------------------------------------------------------------
_DWORD *__usercall ConvertIndexesToDeltas@<eax>(
        unsigned int a1@<ebx>,
        int *finalIndexes,
        _DWORD *deltaOffset,
        _DWORD *deltaOffset_4)
{
  _DWORD *v4; // ebp
  int *v5; // esi
  unsigned int v6; // edx
  int v7; // edi
  int *v8; // eax
  int v9; // ecx
  bool v10; // cc
  unsigned int v11; // ecx
  int v12; // edx
  unsigned __int16 *v13; // esi
  int v14; // eax
  unsigned int v15; // eax
  int v17; // [esp+Ch] [ebp-28h]
  tagPARAMDESC previousIndexes; // [esp+10h] [ebp-24h] BYREF

  v4 = deltaOffset;
  v5 = finalIndexes;
  v6 = 0;
  v7 = 0;
  v17 = 0;
  if ( a1 != 0 )
  {
    v8 = finalIndexes;
    do
    {
      if ( v6 >= 8 )
        break;
      v9 = *v8;
      v10 = *v8 < v7;
      *(int *)((char *)v8 + (char *)&previousIndexes.wParamFlags - (char *)finalIndexes) = *v8;
      if ( v10 )
        v7 = v9;
      if ( v9 > v17 )
        v17 = v9;
      v4 = deltaOffset;
      ++v6;
      ++v8;
    }
    while ( v6 < a1 );
  }
  v11 = 8;
  if ( a1 > 8 )
  {
    do
    {
      v12 = v5[v11];
      v13 = &previousIndexes.wParamFlags + 2 * (v11 & 7);
      v14 = v12 - *(_DWORD *)v13;
      if ( v14 < v7 )
        v7 = v12 - *(_DWORD *)v13;
      if ( v14 > v17 )
        v17 = v12 - *(_DWORD *)v13;
      *(_DWORD *)v13 = v12;
      v5 = finalIndexes;
      finalIndexes[v11++] = v14;
    }
    while ( v11 < a1 );
    v4 = deltaOffset;
  }
  v15 = v17 - v7;
  *v4 = 0;
  if ( v17 != v7 && v15 != 0 )
  {
    do
      ++*v4;
    while ( 1 << *v4 <= v15 );
  }
  *deltaOffset_4 = -v7;
  return deltaOffset_4;
}

//------------------------------------------------------------------------------
// Address: 0x100101E0
// Name: FillOneBitBuffer
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __usercall FillOneBitBuffer@<al>(
        _DWORD *a1@<esi>,
        int a2,
        unsigned int numInputIndexes,
        unsigned __int8 *oneBitBuffer,
        int *outIndexes)
{
  unsigned int v5; // ebp
  unsigned int v6; // edi
  int v7; // ebx
  unsigned __int8 result; // al
  unsigned int v9; // edx
  bool v10; // zf
  unsigned int v11; // ecx
  unsigned int v12; // [esp+Ch] [ebp-10h]
  std::exception pExceptionObject; // [esp+10h] [ebp-Ch] BYREF

  v5 = numInputIndexes;
  v6 = 0;
  v7 = 0;
  result = 0;
  v9 = 0;
  v10 = numInputIndexes == 0;
  v12 = 0;
  *a1 = 0;
  if ( !v10 )
  {
    do
    {
      v11 = *(_DWORD *)(a2 + 4 * v9);
      result *= 2;
      ++v7;
      if ( v11 == v6 )
      {
        v12 = ++v6;
      }
      else
      {
        if ( v11 >= v6 )
        {
          numInputIndexes = (unsigned int)".\\libedgegeomtool_compressindexes.cpp(136)";
          std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&numInputIndexes);
          _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI1_AVexception_std__);
        }
        outIndexes[*a1] = v11;
        v5 = numInputIndexes;
        v6 = v12;
        result |= 1u;
        ++*a1;
      }
      if ( v7 == 8 )
      {
        oneBitBuffer[v9 >> 3] = result;
        result = 0;
        v7 = 0;
      }
      ++v9;
    }
    while ( v9 < v5 );
    if ( v7 != 0 )
    {
      result <<= 8 - v7;
      oneBitBuffer[v5 >> 3] = result;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10010290
// Name: FillTwoBitBuffer
// Source: json
//------------------------------------------------------------------------------
_DWORD *__usercall FillTwoBitBuffer@<eax>(
        _DWORD *result@<eax>,
        int a2@<ecx>,
        int a3@<esi>,
        unsigned int numTriangles,
        unsigned __int8 *twoBitBuffer)
{
  unsigned __int8 v5; // dl
  int v6; // ebx
  int v7; // ebp
  int *v8; // ecx
  int v9; // edi
  _DWORD *iTri; // [esp+8h] [ebp-14h]
  unsigned int lastIndexes; // [esp+Ch] [ebp-10h]
  int lastIndexes_4; // [esp+10h] [ebp-Ch]
  int lastIndexes_8; // [esp+14h] [ebp-8h]

  v5 = 0;
  v6 = -1;
  lastIndexes_8 = -1;
  v7 = -1;
  iTri = nullptr;
  *result = 0;
  lastIndexes = 0;
  if ( numTriangles != 0 )
  {
    v8 = (int *)(a2 + 8);
    while ( 1 )
    {
      v9 = *(v8 - 2);
      if ( v6 == v9 && v7 == *(v8 - 1) )
      {
        v5 *= 4;
      }
      else if ( v7 == v9 && lastIndexes_8 == *(v8 - 1) )
      {
        v5 = (4 * v5) | 1;
      }
      else if ( lastIndexes_8 == v9 && v6 == *(v8 - 1) )
      {
        v5 = (4 * v5) | 2;
      }
      else
      {
        *(_DWORD *)(a3 + 4 * (*result)++) = v9;
        v5 = (4 * v5) | 3;
        *(_DWORD *)(a3 + 4 * (*result)++) = *(v8 - 1);
      }
      *(_DWORD *)(a3 + 4 * (*result)++) = *v8;
      iTri = (_DWORD *)((char *)iTri + 2);
      if ( iTri == (_DWORD *)8 )
      {
        twoBitBuffer[lastIndexes >> 2] = v5;
        v5 = 0;
        iTri = nullptr;
      }
      v7 = *v8;
      lastIndexes_4 = *(v8 - 2);
      lastIndexes_8 = *(v8 - 1);
      v8 += 3;
      if ( ++lastIndexes >= numTriangles )
        break;
      v6 = lastIndexes_4;
    }
    result = iTri;
    if ( iTri != nullptr )
    {
      twoBitBuffer[numTriangles >> 2] = v5 << (8 - (_BYTE)iTri);
      return (_DWORD *)(numTriangles >> 2);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100103A0
// Name: void _edgeGeomRotateTrianglesForAdjacency(unsigned int __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl _edgeGeomRotateTrianglesForAdjacency(unsigned int *triangles, unsigned int numTriangles)
{
  int v2; // esi
  int v3; // edi
  int v4; // ebp
  unsigned int *v5; // ebx
  unsigned int v6; // edx
  wchar_t **v7; // ecx
  unsigned int *v8; // eax
  unsigned int i; // edx
  unsigned int v10; // ecx
  unsigned int v11; // eax
  unsigned int v12; // edx
  unsigned int *v13; // ecx
  unsigned int v14; // ebp
  unsigned int *v15; // eax
  unsigned int j; // edi
  unsigned int v17; // edx
  unsigned int v18; // esi
  unsigned int v19; // edx
  unsigned int v20; // eax
  unsigned int iMyRot; // [esp+Ch] [ebp-30h]
  wchar_t **currentIndexes; // [esp+10h] [ebp-2Ch]
  _DWORD v23[4]; // [esp+14h] [ebp-28h] BYREF
  wchar_t **nextIndexes; // [esp+24h] [ebp-18h]
  unsigned int v25; // [esp+28h] [ebp-14h] BYREF
  unsigned int v26; // [esp+2Ch] [ebp-10h]
  unsigned int v27; // [esp+30h] [ebp-Ch]
  unsigned int v28; // [esp+34h] [ebp-8h]
  unsigned int v29; // [esp+38h] [ebp-4h]

  v2 = -1;
  v3 = -1;
  v4 = -1;
  iMyRot = 0;
  if ( numTriangles != 0 )
  {
    v5 = triangles + 1;
    do
    {
      v6 = v5[1];
      v7 = (wchar_t **)*v5;
      v23[0] = *(v5 - 1);
      v23[2] = v6;
      v23[3] = v23[0];
      v23[1] = v7;
      nextIndexes = v7;
      v8 = v23;
      for ( i = 0; i < 3; ++i )
      {
        v10 = *v8;
        if ( v2 == *v8 && v4 == v8[1] || v3 == v10 && v2 == v8[1] || v4 == v10 && v3 == v8[1] )
        {
          v19 = v8[1];
          v20 = v8[2];
          *(v5 - 1) = v10;
LABEL_25:
          v5[1] = v20;
          *v5 = v19;
          goto NOMORE;
        }
        ++v8;
      }
      if ( iMyRot + 1 < numTriangles )
      {
        v11 = v5[2];
        v12 = v5[4];
        v26 = v5[3];
        v29 = v26;
        v25 = v11;
        v27 = v12;
        v28 = v11;
        v13 = v23;
        currentIndexes = nullptr;
        while ( 2 )
        {
          v14 = *v13;
          v15 = &v25;
          for ( j = 0; j < 3; ++j )
          {
            v17 = *v15;
            if ( v14 == *v15 && v13[2] == v15[1]
              || (v18 = v13[1]) == v17 && v14 == v15[1]
              || v13[2] == v17 && v18 == v15[1] )
            {
              v19 = v13[1];
              *(v5 - 1) = v14;
              v20 = v13[2];
              goto LABEL_25;
            }
            ++v15;
          }
          ++v13;
          currentIndexes = (wchar_t **)((char *)currentIndexes + 1);
          if ( (unsigned int)currentIndexes < 3 )
            continue;
          break;
        }
      }
NOMORE:
      v2 = *(v5 - 1);
      v3 = *v5;
      v4 = v5[1];
      v5 += 3;
      ++iMyRot;
    }
    while ( iMyRot < numTriangles );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100104F0
// Name: void _edgeGeomRemapTriangleList(unsigned int __near *,unsigned int,unsigned int,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl _edgeGeomRemapTriangleList(
        unsigned int *triangles,
        unsigned int numTriangles,
        unsigned int largestUniqueIndex,
        unsigned int *outReverseMapping)
{
  unsigned __int8 *v4; // esi
  int v5; // edx
  unsigned int i; // ecx
  unsigned int v7; // eax

  v4 = (unsigned __int8 *)edgeGeomAllocEx(
                            allocSize: 4 * largestUniqueIndex + 4,
                            a2: ".\\libedgegeomtool_compressindexes.cpp",
                            lineNumber: 0x13Bu);
  memset(dst: v4, value: 0xFFu, count: 4 * largestUniqueIndex + 4);
  v5 = 0;
  for ( i = 0; i < 3 * numTriangles; ++i )
  {
    v7 = triangles[i];
    if ( *(_DWORD *)&v4[4 * v7] == -1 )
    {
      *(_DWORD *)&v4[4 * v7] = v5;
      if ( outReverseMapping != nullptr )
        outReverseMapping[v5] = v7;
      ++v5;
    }
    triangles[i] = *(_DWORD *)&v4[4 * v7];
  }
  edgeGeomFreeEx(this: (VectorByValue *)i);
}

//------------------------------------------------------------------------------
// Address: 0x10010580
// Name: void _edgeGeomCompressIndexes(unsigned int const __near *,unsigned int,unsigned char __near * __near *,struct EdgeGeomIndexesSizes __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl _edgeGeomCompressIndexes(
        unsigned __int8 *src,
        unsigned int numTriangles,
        IUnknown **indexBuffer,
        tagSAFEARRAY **indexesSizes)
{
  unsigned int v4; // ebp
  unsigned int *v5; // esi
  unsigned int v6; // ebx
  unsigned int v7; // edi
  unsigned int *v8; // edi
  unsigned int v9; // ebx
  unsigned int v10; // edi
  unsigned __int8 *v11; // esi
  unsigned int v12; // ecx
  tagSAFEARRAY *v13; // eax
  tagSAFEARRAY *v14; // ecx
  tagSAFEARRAY *v15; // edx
  unsigned __int8 *v16; // esi
  unsigned int v17; // ebx
  unsigned __int8 *v18; // edx
  unsigned __int8 *v19; // esi
  VectorByValue *v20; // ecx
  VectorByValue *v21; // ecx
  VectorByValue *v22; // ecx
  VectorByValue *v23; // ecx
  VectorByValue *v24; // ecx
  unsigned int numIndexes; // [esp+10h] [ebp-28h] BYREF
  unsigned int deltaOffset; // [esp+14h] [ebp-24h] BYREF
  unsigned __int8 *oneBitBuffer; // [esp+18h] [ebp-20h] BYREF
  unsigned __int8 *deltaBlock; // [esp+1Ch] [ebp-1Ch]
  unsigned __int8 *twoBitBuffer; // [esp+20h] [ebp-18h] BYREF
  unsigned int count; // [esp+24h] [ebp-14h]
  int *finalIndexes; // [esp+28h] [ebp-10h]
  unsigned int *tmpIndexes; // [esp+2Ch] [ebp-Ch]
  unsigned int *tmpTris; // [esp+30h] [ebp-8h]
  VectorByValue *v34; // [esp+34h] [ebp-4h]

  v34 = (VectorByValue *)edgeGeomAllocEx(
                           allocSize: 12 * numTriangles,
                           a2: ".\\libedgegeomtool_compressindexes.cpp",
                           lineNumber: 0x189u);
  memcpy(dst: (unsigned __int8 *)v34, src, count: 12 * numTriangles);
  _edgeGeomRotateTrianglesForAdjacency(triangles: (unsigned int *)v34, numTriangles);
  v4 = (2 * numTriangles + 7) >> 3;
  finalIndexes = (int *)edgeGeomAllocEx(allocSize: v4, a2: ".\\libedgegeomtool_compressindexes.cpp", lineNumber: 0x191u);
  memset(dst: (unsigned __int8 *)finalIndexes, value: 0, count: v4);
  v5 = (unsigned int *)edgeGeomAllocEx(
                         allocSize: 12 * numTriangles,
                         a2: ".\\libedgegeomtool_compressindexes.cpp",
                         lineNumber: 0x193u);
  tmpTris = v5;
  deltaOffset = 0;
  FillTwoBitBuffer(
    result: &deltaOffset,
    a2: (int)v34,
    a3: (int)v5,
    numTriangles,
    twoBitBuffer: (unsigned __int8 *)finalIndexes);
  v6 = deltaOffset;
  v7 = (deltaOffset + 7) >> 3;
  count = v7;
  deltaBlock = (unsigned __int8 *)edgeGeomAllocEx(
                                    allocSize: v7,
                                    a2: ".\\libedgegeomtool_compressindexes.cpp",
                                    lineNumber: 0x199u);
  memset(dst: deltaBlock, value: 0, count: v7);
  v8 = (unsigned int *)edgeGeomAllocEx(
                         allocSize: 4 * v6,
                         a2: ".\\libedgegeomtool_compressindexes.cpp",
                         lineNumber: 0x19Bu);
  tmpIndexes = v8;
  twoBitBuffer = nullptr;
  FillOneBitBuffer(a1: &twoBitBuffer, a2: (int)v5, numInputIndexes: v6, oneBitBuffer: deltaBlock, outIndexes: (int *)v8);
  numIndexes = 0;
  oneBitBuffer = nullptr;
  v9 = (unsigned int)twoBitBuffer;
  ConvertIndexesToDeltas(
    a1: (unsigned int)twoBitBuffer,
    finalIndexes: (int *)v8,
    deltaOffset: &numIndexes,
    deltaOffset_4: &oneBitBuffer);
  v10 = (v9 * numIndexes + 7) >> 3;
  v11 = (unsigned __int8 *)edgeGeomAllocEx(
                             allocSize: v10,
                             a2: ".\\libedgegeomtool_compressindexes.cpp",
                             lineNumber: 0x1A6u);
  twoBitBuffer = v11;
  memset(dst: v11, value: 0, count: v10);
  FillDeltaBlockBuffer(
    numFinalIndexes: (unsigned int)tmpIndexes,
    a2: v9,
    deltaBlock: v11,
    bitsPerIndex: numIndexes,
    deltaOffset: (unsigned int)oneBitBuffer);
  v12 = count;
  v13 = (tagSAFEARRAY *)((v10 + count + v4 + 23) & 0xFFFFFFF0);
  *indexesSizes = v13;
  v14 = (tagSAFEARRAY *)(((2 * v9 + 63) & 0xFFFFFFC0) + ((v12 + v4 + 23) & 0xFFFFFFF0));
  v15 = (tagSAFEARRAY *)((v4 + ((6 * numTriangles + 15) & 0xFFFFFFF0) + 2 * ((deltaOffset + 15) & 0xFFFFFFF0) + 15)
                       & 0xFFFFFFF0);
  indexesSizes[1] = v13;
  if ( v14 > v13 )
    indexesSizes[1] = v14;
  if ( v15 > indexesSizes[1] )
    indexesSizes[1] = v15;
  v16 = (unsigned __int8 *)edgeGeomAllocEx(
                             allocSize: (unsigned int)v13,
                             a2: ".\\libedgegeomtool_compressindexes.cpp",
                             lineNumber: 0x1C1u);
  memset(dst: v16, value: 0, count: (unsigned int)*indexesSizes);
  *indexBuffer = (IUnknown *)v16;
  _edgeGeomWriteShort(input: v9, output: (unsigned __int16 *)v16, u16: true);
  v16 += 2;
  _edgeGeomWriteShort(input: (unsigned __int16)oneBitBuffer, output: (unsigned __int16 *)v16, u16: true);
  v17 = count;
  v16 += 2;
  _edgeGeomWriteShort(input: count, output: (unsigned __int16 *)v16, u16: true);
  v18 = deltaBlock;
  v16 += 2;
  *v16++ = numIndexes;
  *v16++ = 0;
  memcpy(dst: v16, src: v18, count: v17);
  v19 = &v16[v17];
  memcpy(dst: v19, src: (unsigned __int8 *)finalIndexes, count: v4);
  memcpy(dst: &v19[v4], src: twoBitBuffer, count: v10);
  edgeGeomFreeEx(this: v20);
  edgeGeomFreeEx(this: v21);
  edgeGeomFreeEx(this: v22);
  edgeGeomFreeEx(this: (VectorByValue *)tmpIndexes);
  edgeGeomFreeEx(this: v23);
  edgeGeomFreeEx(this: v24);
}

//------------------------------------------------------------------------------
// Address: 0x10010840
// Name: void _edgeGeomMeasureCompressedIndexTable(unsigned int const __near *,unsigned int,enum EdgeGeomIndexesFlavor,struct EdgeGeomIndexesSizes __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl _edgeGeomMeasureCompressedIndexTable(
        unsigned __int8 *src,
        unsigned int numTriangles,
        enum EdgeGeomIndexesFlavor a3,
        tagSAFEARRAY **indexesSizes)
{
  tagSAFEARRAY **v4; // ecx
  tagSAFEARRAY *v5; // eax
  unsigned __int8 *v6; // esi
  VectorByValue *v7; // ecx
  VectorByValue *v8; // ecx
  char *_What; // [esp+0h] [ebp-10h] BYREF
  std::exception pExceptionObject; // [esp+4h] [ebp-Ch] BYREF

  switch ( a3 )
  {
    case kIndexesU16TriangleListCW:
    case kIndexesU16TriangleListCCW:
      v4 = indexesSizes;
      v5 = (tagSAFEARRAY *)((6 * numTriangles + 15) & 0xFFFFFFF0);
      *indexesSizes = v5;
      v4[1] = v5;
      break;
    case kIndexesCompressedTriangleListCW:
    case kIndexesCompressedTriangleListCCW:
      v6 = (unsigned __int8 *)edgeGeomAllocEx(
                                allocSize: 12 * numTriangles,
                                a2: ".\\libedgegeomtool_compressindexes.cpp",
                                lineNumber: 0x16Au);
      memcpy(dst: v6, src, count: 12 * numTriangles);
      a3 = *(_DWORD *)&v6[4 * _edgeGeomSortUniqueArrayInt(array: (int *)v6, totalElements: 3 * numTriangles) - 4];
      memcpy(dst: v6, src, count: 12 * numTriangles);
      _edgeGeomRemapTriangleList(
        triangles: (unsigned int *)v6,
        numTriangles,
        largestUniqueIndex: a3,
        outReverseMapping: nullptr);
      a3 = kIndexesU16TriangleListCW;
      _edgeGeomCompressIndexes(src: v6, numTriangles, indexBuffer: (IUnknown **)&a3, indexesSizes);
      edgeGeomFreeEx(this: v7);
      edgeGeomFreeEx(this: v8);
      break;
    default:
      _What = ".\\libedgegeomtool_compressindexes.cpp(384)";
      std::exception::exception(this: &pExceptionObject, (const char *const *)&_What);
      _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI1_AVexception_std__);
      return;
  }
}
