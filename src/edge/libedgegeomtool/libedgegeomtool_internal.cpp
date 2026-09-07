// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: edge/libedgegeomtool/libedgegeomtool_internal.cpp
// Functions: 12
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1000BA70
// Name: DefaultAlloc
// Source: json
//------------------------------------------------------------------------------
void *__cdecl DefaultAlloc(unsigned int allocSize)
{
  return operator new(nSize: allocSize);
}

//------------------------------------------------------------------------------
// Address: 0x1000BA80
// Name: DefaultFree
// Source: json
//------------------------------------------------------------------------------
void __cdecl DefaultFree(void *ptr)
{
  free(pMem: ptr);
}

//------------------------------------------------------------------------------
// Address: 0x1000BA90
// Name: void __near * edgeGeomAllocEx(unsigned int,char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void *__cdecl edgeGeomAllocEx(unsigned int allocSize, const char *a2, unsigned int lineNumber)
{
  return g_edgeGeomAlloc(allocSize, a2, a3: lineNumber);
}

//------------------------------------------------------------------------------
// Address: 0x1000BAA0
// Name: void edgeGeomFreeEx(void __near *,char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall edgeGeomFreeEx(VectorByValue *this)
{
  __asm { jmp     dword ptr g_edgeGeomFree }
}

//------------------------------------------------------------------------------
// Address: 0x1000BAB0
// Name: void _edgeGeomWriteShort(unsigned short,void __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl _edgeGeomWriteShort(unsigned __int16 input, unsigned __int16 *output, bool u16)
{
  unsigned __int16 u16a; // [esp+Ch] [ebp+Ch]

  if ( u16 )
  {
    LOBYTE(u16a) = HIBYTE(input);
    HIBYTE(u16a) = input;
  }
  else
  {
    u16a = input;
  }
  *output = u16a;
}

//------------------------------------------------------------------------------
// Address: 0x1000BAF0
// Name: void _edgeGeomWriteInt(unsigned int,void __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall _edgeGeomWriteInt(
        CUtlRBTree<CUtlMap<unsigned char *,int,unsigned int>::Node_t,unsigned int,CUtlMap<unsigned char *,int,unsigned int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned char *,int,unsigned int>::Node_t,unsigned int>,unsigned int> > *input,
        unsigned int inputa,
        unsigned int *output,
        char u32)
{
  unsigned int u32a; // [esp+Ch] [ebp+Ch]

  if ( u32 != 0 )
  {
    LOBYTE(u32a) = HIBYTE(inputa);
    BYTE1(u32a) = BYTE2(inputa);
    BYTE2(u32a) = BYTE1(inputa);
    HIBYTE(u32a) = inputa;
  }
  else
  {
    u32a = inputa;
  }
  *output = u32a;
}

//------------------------------------------------------------------------------
// Address: 0x1000BB50
// Name: void _edgeGeomWriteFloat(float,void __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall _edgeGeomWriteFloat(
        CUtlRBTree<CUtlMap<unsigned char *,int,unsigned int>::Node_t,unsigned int,CUtlMap<unsigned char *,int,unsigned int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned char *,int,unsigned int>::Node_t,unsigned int>,unsigned int> > *input,
        unsigned int inputa,
        unsigned int *output,
        char u32)
{
  _edgeGeomWriteInt(input, inputa, output, u32);
}

//------------------------------------------------------------------------------
// Address: 0x1000BB70
// Name: int _edgeGeomIsEqualInt(void const __near *,void const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl _edgeGeomIsEqualInt(_DWORD *a1, _DWORD *a2)
{
  return *a1 - *a2;
}

//------------------------------------------------------------------------------
// Address: 0x1000BB80
// Name: unsigned int _edgeGeomSortUniqueArrayInt(int __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl _edgeGeomSortUniqueArrayInt(int *array, unsigned int totalElements)
{
  unsigned int result; // eax
  unsigned int v3; // edx
  int v4; // ecx

  qsort(
    base: array,
    num: totalElements,
    width: 4u,
    comp: (int (__cdecl *)(const void *, const void *))_edgeGeomIsEqualInt);
  result = 0;
  if ( totalElements != 0 )
  {
    v3 = 0;
    result = 1;
    do
    {
      v4 = array[v3];
      if ( array[result - 1] != v4 )
        array[result++] = v4;
      ++v3;
    }
    while ( v3 < totalElements );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000BBD0
// Name: ConvertComponentToFixedPoint
// Source: json
//------------------------------------------------------------------------------
void __thiscall ConvertComponentToFixedPoint(void *fractionalBits)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1000BC50
// Name: unsigned int _edgeGeomConvertToFixedPoint(struct EdgeGeomSpuVertexAttributeDefinition const __near &,float const __near *,float const __near *,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl _edgeGeomConvertToFixedPoint(
        const struct EdgeGeomSpuVertexAttributeDefinition *_What,
        const float *a2,
        const float *a3,
        unsigned __int8 *a4)
{
  unsigned int v4; // edx
  int v5; // edi
  const float *v6; // ebp
  unsigned __int8 *v7; // ebx
  unsigned int *m_fixedPointBitDepthInteger; // esi
  void *v9; // ecx
  unsigned int v10; // esi
  int v11; // edx
  int v12; // eax
  int v13; // eax
  unsigned int v14; // eax
  bool v15; // cf
  int v17; // [esp+18h] [ebp-1Ch]
  int v18; // [esp+1Ch] [ebp-18h]
  unsigned int *v19; // [esp+20h] [ebp-14h]
  std::exception pExceptionObject; // [esp+28h] [ebp-Ch] BYREF

  v4 = 0;
  v5 = 0;
  v17 = 0;
  v18 = 0;
  if ( _What->m_count != 0 )
  {
    v6 = a3;
    v7 = a4;
    m_fixedPointBitDepthInteger = _What->m_fixedPointBitDepthInteger;
    v19 = _What->m_fixedPointBitDepthInteger;
    do
    {
      v9 = (void *)m_fixedPointBitDepthInteger[4];
      v10 = (unsigned int)v9 + *m_fixedPointBitDepthInteger;
      if ( v10 != 0 && (v10 < (unsigned int)v9 || v10 > 0x20) )
      {
        _What = (const struct EdgeGeomSpuVertexAttributeDefinition *)".\\libedgegeomtool_internal.cpp(228)";
        std::exception::exception(this: &pExceptionObject, (const char *const *)&_What);
        _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI1_AVexception_std__);
      }
      if ( v10 >= (unsigned int)v9 )
      {
        ConvertComponentToFixedPoint(fractionalBits: v9);
        v13 = v12 << (32 - v10 - v11);
        v4 = v10 + v11;
        v5 |= v13;
        if ( v4 >= 8 )
        {
          v14 = v4 >> 3;
          v17 += v4 >> 3;
          do
          {
            *v7++ = HIBYTE(v5);
            v5 <<= 8;
            v4 -= 8;
            --v14;
          }
          while ( v14 != 0 );
        }
      }
      m_fixedPointBitDepthInteger = v19 + 1;
      ++v6;
      v15 = ++v18 < _What->m_count;
      ++v19;
    }
    while ( v15 );
    if ( v4 != 0 )
    {
      _What = (const struct EdgeGeomSpuVertexAttributeDefinition *)".\\libedgegeomtool_internal.cpp(243)";
      std::exception::exception(this: &pExceptionObject, (const char *const *)&_What);
      _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI1_AVexception_std__);
    }
  }
  return v17;
}

//------------------------------------------------------------------------------
// Address: 0x1000BD80
// Name: void _edgeGeomFindAttributeMins(float const __near *,unsigned int,struct EdgeGeomSpuVertexFormat const __near &,unsigned short const __near *,enum EdgeGeomAttributeId const __near *,unsigned char,unsigned int const __near *,unsigned int,float __near * __near *,unsigned int __near * __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl _edgeGeomFindAttributeMins(
        const float *a1,
        unsigned int numFloatsPerSourceVertex,
        Color *const vertexFormat,
        ILoggingListener sourceAttributeIds,
        const enum EdgeGeomAttributeId *a5,
        unsigned __int8 numSourceAttributes,
        const unsigned int *a7,
        unsigned int numUniqueVertexes,
        float **a9,
        ILoggingListener *const outFixedPointOffsets,
        unsigned int *outFixedPointOffsetsSize)
{
  Color *v11; // ebp
  Color v12; // ecx
  unsigned int v13; // esi
  Color *v14; // eax
  ILoggingListener *v15; // ecx
  unsigned int *v16; // edx
  std::exception_vtbl *v17; // ebx
  float *v18; // edx
  unsigned int v19; // eax
  unsigned int v20; // ebx
  float *v21; // edi
  Color *v22; // esi
  int v23; // eax
  unsigned __int16 v24; // ax
  unsigned int v25; // ecx
  float *v26; // edx
  double v27; // st7
  ILoggingListener_vtbl *v28; // eax
  float **v29; // edx
  float *v30; // edi
  ILoggingListener_vtbl *v31; // esi
  Color *v32; // ebx
  Color *v33; // edx
  int v34; // ebp
  int v35; // eax
  double v36; // st5
  double v37; // st4
  unsigned int v38; // [esp+8h] [ebp-1Ch]
  float iAttr; // [esp+Ch] [ebp-18h]
  unsigned int iAttra; // [esp+Ch] [ebp-18h]
  const float *v41; // [esp+10h] [ebp-14h]
  unsigned int v42; // [esp+10h] [ebp-14h]
  float *v43; // [esp+14h] [ebp-10h]
  std::exception pExceptionObject; // [esp+18h] [ebp-Ch] BYREF

  v11 = vertexFormat;
  v12 = *vertexFormat;
  v13 = 0;
  if ( *vertexFormat == 0 )
    goto LABEL_7;
  v14 = vertexFormat + 2;
  do
  {
    if ( *v14 == 8 )
      v13 += 4;
    v14 += 12;
    --*(_DWORD *)&v12;
  }
  while ( v12 != 0 );
  if ( v13 != 0 )
  {
    v17 = (std::exception_vtbl *)(4 * v13);
    pExceptionObject.__vftable = (std::exception_vtbl *)(4 * v13);
    v18 = (float *)g_edgeGeomAlloc(allocSize: 4 * v13, a2: ".\\libedgegeomtool_internal.cpp", a3: 0x10Eu);
    v43 = v18;
    *a9 = v18;
    memset32(v18, 2139095039, v13);
    v19 = 0;
    v38 = 0;
    if ( numUniqueVertexes != 0 )
    {
      do
      {
        v20 = 0;
        v21 = v18;
        v41 = &a1[numFloatsPerSourceVertex * a7[v19]];
        if ( *v11 != 0 )
        {
          v22 = v11 + 3;
          do
          {
            if ( *(_DWORD *)&v22[-1] == 8 )
            {
              v23 = 0;
              if ( numSourceAttributes == 0 )
              {
LABEL_15:
                vertexFormat = (Color *const)".\\libedgegeomtool_internal.cpp(301)";
                std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&vertexFormat);
                _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI1_AVexception_std__);
              }
              while ( a5[v23] != *(_DWORD *)&v22[1] )
              {
                if ( ++v23 >= (unsigned int)numSourceAttributes )
                  goto LABEL_15;
              }
              v24 = *((_WORD *)&sourceAttributeIds.Log + v23);
              v25 = 0;
              if ( *v22 != 0 )
              {
                v26 = (float *)&v41[v24];
                do
                {
                  if ( *v26 <= (double)v21[v25] )
                    v27 = *v26;
                  else
                    v27 = v21[v25];
                  iAttr = v27;
                  ++v25;
                  ++v26;
                  v21[v25 - 1] = iAttr;
                }
                while ( v25 < *(_DWORD *)v22 );
              }
              v11 = vertexFormat;
              v21 += 4;
            }
            ++v20;
            v22 += 12;
          }
          while ( v20 < *(_DWORD *)v11 );
          v18 = v43;
          v19 = v38;
        }
        v38 = ++v19;
      }
      while ( v19 < numUniqueVertexes );
      v17 = pExceptionObject.__vftable;
    }
    *outFixedPointOffsetsSize = (unsigned int)v17;
    v28 = (ILoggingListener_vtbl *)g_edgeGeomAlloc(
                                     allocSize: (unsigned int)v17,
                                     a2: ".\\libedgegeomtool_internal.cpp",
                                     a3: 0x139u);
    v29 = a9;
    outFixedPointOffsets->__vftable = v28;
    v30 = *v29;
    v31 = v28;
    v42 = 0;
    if ( *v11 != 0 )
    {
      v32 = v11 + 10;
      do
      {
        if ( *(_DWORD *)&v32[-8] == 8 )
        {
          v33 = v32;
          v34 = 4;
          do
          {
            v35 = 1 << *(_DWORD *)v33;
            ++v31;
            ++v30;
            ++v33;
            *(float *)&pExceptionObject.__vftable = (float)v35;
            v36 = *(float *)&pExceptionObject.__vftable;
            pExceptionObject.__vftable = (std::exception_vtbl *)((unsigned __int16)v38 | 0xC00);
            v37 = v36 * *(v30 - 1) + 0.5;
            *(_QWORD *)&pExceptionObject.__vftable = (__int64)(v36 * 0.0 + 0.5);
            LOBYTE(iAttra) = ((unsigned int)(__int64)v37 - (unsigned int)pExceptionObject.__vftable) >> 24;
            BYTE1(iAttra) = ((unsigned int)(__int64)v37 - (unsigned int)pExceptionObject.__vftable) >> 16;
            --v34;
            BYTE2(iAttra) = (unsigned __int16)((__int64)v37 - LOWORD(pExceptionObject.__vftable)) >> 8;
            HIBYTE(iAttra) = (__int64)v37 - LOBYTE(pExceptionObject.__vftable);
            v31[-1].Log = (void (__thiscall *)(ILoggingListener *, const LoggingContext_t *, const char *))iAttra;
          }
          while ( v34 != 0 );
          v11 = vertexFormat;
        }
        v32 += 12;
        ++v42;
      }
      while ( v42 < *(_DWORD *)v11 );
    }
  }
  else
  {
LABEL_7:
    v15 = outFixedPointOffsets;
    v16 = outFixedPointOffsetsSize;
    *a9 = nullptr;
    v15->__vftable = nullptr;
    *v16 = 0;
  }
}
