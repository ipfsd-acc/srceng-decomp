// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: edge/libedgegeomtool/libedgegeomtool_makebuffers.cpp
// Functions: 10
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1000C040
// Name: unsigned short _ConvertF32toF16(float)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __cdecl _ConvertF32toF16(float a1)
{
  int v1; // ecx
  int v2; // edx
  int v3; // eax

  v1 = (unsigned __int8)(LODWORD(a1) >> 23) - 112;
  v2 = HIWORD(LODWORD(a1)) & 0x8000;
  if ( (unsigned __int8)(LODWORD(a1) >> 23) > 0x70u )
  {
    if ( v1 <= 30 )
      return v2 | (v1 << 10) | (LODWORD(a1) >> 13) & 0x3FF;
    else
      LOWORD(v3) = v2 | 0x7BFF;
  }
  else
  {
    LOWORD(v3) = 0;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1000C090
// Name: unsigned int edgeGeomGetScratchBufferSizeInQwords(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl edgeGeomGetScratchBufferSizeInQwords(unsigned int a1, unsigned int a2)
{
  return ((a1 + 1) * ((a2 + 7) & 0xFFFFFFF8)) & 0xFFFFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x1000C0B0
// Name: short _ConvertF32toI16(float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall _ConvertF32toI16(const CUtlMap<unsigned char *,int,unsigned int>::Node_t *val, float vala)
{
  double v2; // st7
  double v3; // st7
  float valb; // [esp+Ch] [ebp+4h]

  v2 = vala;
  if ( vala < -32768.0 || v2 > 32767.0 )
  {
    printf(format: "Value (%5.3f) should be in range [-32768..32767].  Conversion will clamp to I16.\n", vala);
    v2 = vala;
  }
  if ( v2 > 32767.0 )
    v2 = 32767.0;
  valb = v2;
  v3 = valb;
  if ( valb < -32768.0 )
    v3 = -32768.0;
  return (int)(float)v3;
}

//------------------------------------------------------------------------------
// Address: 0x1000C130
// Name: short _ConvertF32toI16N(float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall _ConvertF32toI16N(const CUtlMap<unsigned char *,int,unsigned int>::Node_t *val, float vala)
{
  double v2; // st7
  double v3; // st7
  double v4; // st6
  double v5; // st6
  float valb; // [esp+Ch] [ebp+4h]
  float valc; // [esp+Ch] [ebp+4h]

  v2 = vala;
  if ( vala < -1.0 || v2 > 1.0 )
  {
    printf(format: "Value (%5.3f) should be in range [-1..1].  Conversion will clamp to I16N [-32768..32767].\n", vala);
    v2 = vala;
  }
  if ( v2 <= 1.0 )
  {
    v4 = v2;
    v3 = 1.0;
  }
  else
  {
    v3 = 1.0;
    v4 = 1.0;
  }
  valb = v4;
  v5 = valb;
  if ( valb < -1.0 )
    v5 = -1.0;
  valc = v5;
  return (int)((v3 + valc) * 0.5 * 65535.0 - 32768.0);
}

//------------------------------------------------------------------------------
// Address: 0x1000C1C0
// Name: unsigned char _ConvertF32toU8N(float)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl _ConvertF32toU8N(float a1)
{
  double v1; // st7
  double v2; // st7
  float v4; // [esp+10h] [ebp+4h]
  float v5; // [esp+10h] [ebp+4h]

  v1 = a1;
  if ( a1 < 0.0 || v1 > 1.0 )
  {
    printf(format: "Value (%5.3f) should be in range [0..1].  Conversion will clamp to U8N [0..255].\n", a1);
    v1 = a1;
  }
  if ( v1 > 1.0 )
    v1 = 1.0;
  v4 = v1;
  v2 = v4;
  if ( v4 < 0.0 )
    v2 = 0.0;
  v5 = v2;
  return (int)(v5 * 255.0);
}

//------------------------------------------------------------------------------
// Address: 0x1000C250
// Name: unsigned char _ConvertF32toU8(float)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl _ConvertF32toU8(float a1)
{
  double v1; // st7
  double v2; // st7
  double v3; // st7
  float v5; // [esp+10h] [ebp+4h]
  float v6; // [esp+10h] [ebp+4h]

  v1 = a1;
  if ( a1 < 0.0 || v1 > 255.0 )
  {
    printf(format: "Value (%5.3f) should be in range [0..255].  Conversion will clamp to U8.\n", a1);
    v1 = a1;
  }
  v5 = v1 + 0.5;
  v2 = v5;
  if ( v5 > 255.0 )
    v2 = 255.0;
  v6 = v2;
  v3 = v6;
  if ( v6 < 0.0 )
    v3 = 0.0;
  return (int)(float)v3;
}

//------------------------------------------------------------------------------
// Address: 0x1000C2F0
// Name: unsigned int _ConvertF32toX11Y11Z10N(float,float,float)
// Source: json
//------------------------------------------------------------------------------
CUtlRBTree<CUtlMap<unsigned char *,int,unsigned int>::Node_t,unsigned int,CUtlMap<unsigned char *,int,unsigned int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned char *,int,unsigned int>::Node_t,unsigned int>,unsigned int> > *__cdecl _ConvertF32toX11Y11Z10N(
        CUtlRBTree<CUtlMap<unsigned char *,int,unsigned int>::Node_t,unsigned int,CUtlMap<unsigned char *,int,unsigned int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned char *,int,unsigned int>::Node_t,unsigned int>,unsigned int> > *result,
        float y,
        float z)
{
  double v3; // st7
  double v4; // st2
  double v5; // st3
  int v6; // edx
  double v7; // st2
  double v8; // st7
  double v9; // st5
  double v10; // st3
  int v11; // ecx
  double v12; // st7
  double v13; // st7
  float ya; // [esp+18h] [ebp+8h]
  float yb; // [esp+18h] [ebp+8h]
  float ye; // [esp+18h] [ebp+8h]
  float yc; // [esp+18h] [ebp+8h]
  float yf; // [esp+18h] [ebp+8h]
  float yg; // [esp+18h] [ebp+8h]
  float yd; // [esp+18h] [ebp+8h]
  float yh; // [esp+18h] [ebp+8h]

  if ( *(float *)&result < -1.0 || *(float *)&result > 1.0 )
    printf(
      format: "Value (%5.3f) should be in range [-1..1].  Conversion will clamp to X11Y11Z10N.\n",
      *(float *)&result);
  v3 = y;
  if ( y < -1.0 || v3 > 1.0 )
  {
    printf(format: "Value (%5.3f) should be in range [-1..1].  Conversion will clamp to X11Y11Z10N.\n", y);
    v3 = y;
  }
  if ( z < -1.0 || z > 1.0 )
  {
    printf(format: "Value (%5.3f) should be in range [-1..1].  Conversion will clamp to X11Y11Z10N.\n", z);
    v3 = y;
  }
  ya = (*(float *)&result * 2047.0 - 1.0) * 0.5;
  if ( ya >= 1023.0 )
  {
    v5 = 1023.0;
    v4 = 1023.0;
  }
  else
  {
    v4 = ya;
    v5 = 1023.0;
  }
  yb = v4;
  if ( yb <= -1024.0 )
    yb = -1024.0;
  v6 = (__int64)yb & 0x7FF;
  v7 = v3;
  v8 = -1024.0;
  v9 = v5;
  ye = (2047.0 * v7 - 1.0) * 0.5;
  v10 = ye;
  if ( ye >= v9 )
    v10 = 1023.0;
  yc = v10;
  if ( yc > -1024.0 )
    v8 = yc;
  yf = v8;
  v11 = ((__int64)yf & 0x7FF) << 11;
  yg = (v9 * z - 1.0) * 0.5;
  v12 = yg;
  if ( yg >= 511.0 )
    v12 = 511.0;
  yd = v12;
  v13 = -512.0;
  if ( yd > -512.0 )
    v13 = yd;
  yh = v13;
  return (CUtlRBTree<CUtlMap<unsigned char *,int,unsigned int>::Node_t,unsigned int,CUtlMap<unsigned char *,int,unsigned int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned char *,int,unsigned int>::Node_t,unsigned int>,unsigned int> > *)(v6 | v11 | ((__int64)yh << 22));
}

//------------------------------------------------------------------------------
// Address: 0x1000C510
// Name: void edgeGeomMakeIndexBuffer(unsigned int const __near *,unsigned int,enum EdgeGeomIndexesFlavor,unsigned char __near * __near *,unsigned short __near * const)
// Source: json
//------------------------------------------------------------------------------
CLoggingSystem *__cdecl edgeGeomMakeIndexBuffer(
        CLoggingSystem *result,
        unsigned int numTriangles,
        char *a3,
        IUnknown **outIndexBuffer,
        unsigned __int16 *outIndexDmaSizes)
{
  unsigned __int8 *v5; // ebp
  unsigned int v6; // esi
  unsigned __int16 *v7; // edi
  tagSAFEARRAY *v8; // eax
  int v9; // ecx
  CLoggingSystem *v10; // eax
  unsigned __int16 *v11; // edx
  char *_What; // [esp+10h] [ebp-28h] BYREF
  IRecordInfo measuredSizes; // [esp+14h] [ebp-24h] BYREF
  tagSAFEARRAY *indexesSizes; // [esp+18h] [ebp-20h] BYREF
  tagSAFEARRAY *v15; // [esp+1Ch] [ebp-1Ch]
  std::exception pExceptionObject; // [esp+20h] [ebp-18h] BYREF
  std::exception v17; // [esp+2Ch] [ebp-Ch] BYREF

  indexesSizes = nullptr;
  v15 = nullptr;
  switch ( (unsigned int)a3 )
  {
    case 0u:
    case 1u:
      v5 = (unsigned __int8 *)edgeGeomAllocEx(
                                allocSize: (6 * numTriangles + 15) & 0xFFFFFFF0,
                                a2: ".\\libedgegeomtool_makebuffers.cpp",
                                lineNumber: 0xBCu);
      memset(dst: v5, value: 0, count: (6 * numTriangles + 15) & 0xFFFFFFF0);
      v6 = 0;
      *outIndexBuffer = (IUnknown *)v5;
      a3 = (char *)(3 * numTriangles);
      if ( 3 * numTriangles != 0 )
      {
        v7 = (unsigned __int16 *)v5;
        do
        {
          if ( *(&result->m_nChannelCount + v6) >= 0xFFFFu )
          {
            _What = ".\\libedgegeomtool_makebuffers.cpp(193)";
            std::exception::exception(this: &pExceptionObject, (const char *const *)&_What);
            _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI1_AVexception_std__);
          }
          _edgeGeomWriteShort(input: *((_WORD *)&result->m_nChannelCount + 2 * v6++), output: v7++, u16: true);
        }
        while ( v6 < (unsigned int)a3 );
      }
      v8 = (tagSAFEARRAY *)((6 * numTriangles + 15) & 0xFFFFFFF0);
      indexesSizes = v8;
      v15 = v8;
      break;
    case 2u:
    case 3u:
      _edgeGeomCompressIndexes(src: (unsigned __int8 *)result, numTriangles, indexBuffer: outIndexBuffer, &indexesSizes);
      v8 = indexesSizes;
      break;
    default:
      measuredSizes.__vftable = (IRecordInfo_vtbl *)".\\libedgegeomtool_makebuffers.cpp(213)";
      std::exception::exception(this: &v17, _What: (const char *const *)&measuredSizes);
      _CxxThrowException(pExceptionObject: &v17, pThrowInfo: &_TI1_AVexception_std__);
      return v10;
  }
  v9 = 0x4000;
  if ( (unsigned int)v8 <= 0x4000 )
    v9 = (int)v8;
  v10 = (CLoggingSystem *)((char *)v8 - v9);
  if ( (unsigned int)v10 > 0x4000 )
  {
    a3 = ".\\libedgegeomtool_makebuffers.cpp(218)";
    std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&a3);
    _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI1_AVexception_std__);
  }
  v11 = outIndexDmaSizes;
  *outIndexDmaSizes = v9;
  v11[1] = (unsigned __int16)v10;
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x1000C680
// Name: void _edgeGeomConvertAndWriteDataToSpuStream(struct EdgeGeomSpuVertexAttributeDefinition const __near &,float const __near *,unsigned char __near *,float const __near * __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl _edgeGeomConvertAndWriteDataToSpuStream(
        float _What,
        float *a2,
        unsigned __int8 *output,
        const float **a4,
        CUtlRBTree<CUtlMap<unsigned char *,int,unsigned int>::Node_t,unsigned int,CUtlMap<unsigned char *,int,unsigned int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned char *,int,unsigned int>::Node_t,unsigned int>,unsigned int> > *input)
{
  const CUtlMap<unsigned char *,int,unsigned int>::Node_t *v5; // ecx
  float v6; // esi
  unsigned int v7; // edi
  unsigned __int8 *v8; // ebx
  float *v9; // ebp
  unsigned int v10; // edi
  unsigned __int8 *v11; // ebx
  float *v12; // ebp
  unsigned int v13; // edi
  unsigned __int16 *v14; // ebx
  float *v15; // ebp
  unsigned __int16 v16; // ax
  unsigned int v17; // edi
  unsigned __int16 *v18; // ebx
  float *v19; // ebp
  unsigned __int16 v20; // ax
  unsigned int v21; // edi
  unsigned __int16 *v22; // ebx
  float *v23; // ebp
  unsigned __int16 v24; // ax
  unsigned int v25; // ebx
  float *v26; // edi
  int v27; // ebp
  CUtlRBTree<CUtlMap<unsigned char *,int,unsigned int>::Node_t,unsigned int,CUtlMap<unsigned char *,int,unsigned int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned char *,int,unsigned int>::Node_t,unsigned int>,unsigned int> > *v28; // eax
  unsigned int v29; // esi
  unsigned int v30; // ebx
  double v31; // st7
  double v32; // st7
  double v33; // st6
  double v34; // st5
  double v35; // st4
  int v36; // edi
  double v37; // st5
  double v38; // rtt
  double v39; // st7
  double v40; // st6
  double v41; // st4
  double v42; // st7
  int v43; // ecx
  double v44; // st4
  double v45; // st4
  int v46; // esi
  unsigned int v47; // ecx
  unsigned __int8 *v48; // eax
  unsigned int v49; // edx
  const float **v50; // edi
  char v51; // [esp+8h] [ebp-2Ch]
  float v52; // [esp+1Ch] [ebp-18h]
  float v53; // [esp+1Ch] [ebp-18h]
  CUtlRBTree<CUtlMap<unsigned char *,int,unsigned int>::Node_t,unsigned int,CUtlMap<unsigned char *,int,unsigned int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned char *,int,unsigned int>::Node_t,unsigned int>,unsigned int> > *result; // [esp+20h] [ebp-14h]
  float v55; // [esp+20h] [ebp-14h]
  float v56; // [esp+20h] [ebp-14h]
  float v57; // [esp+20h] [ebp-14h]
  float v58; // [esp+24h] [ebp-10h]
  float v59; // [esp+24h] [ebp-10h]
  std::exception pExceptionObject; // [esp+28h] [ebp-Ch] BYREF

  v6 = _What;
  switch ( *(_DWORD *)LODWORD(_What) )
  {
    case 1:
      v17 = 0;
      if ( *(_DWORD *)(LODWORD(_What) + 4) != 0 )
      {
        v18 = (unsigned __int16 *)output;
        v19 = a2;
        do
        {
          v20 = _ConvertF32toI16N(val: v5, vala: v19[v17]);
          _edgeGeomWriteShort(input: v20, output: v18, u16: (bool)input);
          ++v17;
          ++v18;
        }
        while ( v17 < *(_DWORD *)(LODWORD(v6) + 4) );
      }
      return;
    case 2:
      v25 = 0;
      if ( *(_DWORD *)(LODWORD(_What) + 4) != 0 )
      {
        v26 = a2;
        v27 = output - (unsigned __int8 *)a2;
        do
        {
          _edgeGeomWriteFloat(
            input,
            inputa: COERCE_UNSIGNED_INT(*v26),
            output: (unsigned int *)((char *)v26 + v27),
            u32: (char)input);
          ++v25;
          ++v26;
        }
        while ( v25 < *(_DWORD *)(LODWORD(v6) + 4) );
      }
      return;
    case 3:
      v21 = 0;
      if ( *(_DWORD *)(LODWORD(_What) + 4) != 0 )
      {
        v22 = (unsigned __int16 *)output;
        v23 = a2;
        do
        {
          v51 = (char)input;
          v24 = _ConvertF32toF16(a1: v23[v21]);
          _edgeGeomWriteShort(input: v24, output: v22, u16: v51);
          ++v21;
          ++v22;
        }
        while ( v21 < *(_DWORD *)(LODWORD(v6) + 4) );
      }
      return;
    case 4:
      v10 = 0;
      if ( *(_DWORD *)(LODWORD(_What) + 4) != 0 )
      {
        v11 = output;
        v12 = a2;
        do
        {
          v11[v10] = _ConvertF32toU8N(a1: v12[v10]);
          ++v10;
        }
        while ( v10 < *(_DWORD *)(LODWORD(v6) + 4) );
      }
      return;
    case 5:
      v13 = 0;
      if ( *(_DWORD *)(LODWORD(_What) + 4) != 0 )
      {
        v14 = (unsigned __int16 *)output;
        v15 = a2;
        do
        {
          v16 = _ConvertF32toI16(val: v5, vala: v15[v13]);
          _edgeGeomWriteShort(input: v16, output: v14, u16: (bool)input);
          ++v13;
          ++v14;
        }
        while ( v13 < *(_DWORD *)(LODWORD(v6) + 4) );
      }
      return;
    case 6:
      result = *(CUtlRBTree<CUtlMap<unsigned char *,int,unsigned int>::Node_t,unsigned int,CUtlMap<unsigned char *,int,unsigned int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned char *,int,unsigned int>::Node_t,unsigned int>,unsigned int> > **)a2;
      v58 = a2[1];
      _What = a2[2];
      v28 = _ConvertF32toX11Y11Z10N(result, y: v58, z: _What);
      _edgeGeomWriteInt(input, inputa: (unsigned int)v28, (unsigned int *)output, u32: (char)input);
      return;
    case 7:
      v7 = 0;
      if ( *(_DWORD *)(LODWORD(_What) + 4) != 0 )
      {
        v8 = output;
        v9 = a2;
        do
        {
          v8[v7] = _ConvertF32toU8(a1: v9[v7]);
          ++v7;
        }
        while ( v7 < *(_DWORD *)(LODWORD(v6) + 4) );
      }
      return;
    case 8:
      v50 = a4;
      _edgeGeomConvertToFixedPoint(
        _What: (const struct EdgeGeomSpuVertexAttributeDefinition *)LODWORD(_What),
        a2,
        a3: *a4,
        a4: output);
      *v50 += 4;
      return;
    case 9:
      v29 = *(_DWORD *)(LODWORD(_What) + 4);
      if ( v29 != 3 && v29 != 4 )
      {
        _What = COERCE_FLOAT(".\\libedgegeomtool_makebuffers.cpp(296)");
        std::exception::exception(this: &pExceptionObject, (const char *const *)&_What);
        _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI1_AVexception_std__);
      }
      v30 = _S1;
      if ( (_S1 & 1) == 0 )
      {
        v30 = _S1 | 1;
        _S1 |= 1u;
        _What = sqrt(2.0);
        flt_100267F0 = -_What * 0.5;
      }
      if ( (v30 & 2) == 0 )
      {
        _S1 = v30 | 2;
        _What = sqrt(2.0);
        flt_100267EC = _What * 0.5;
      }
      _What = *a2;
      v55 = a2[1];
      v52 = a2[2];
      if ( v29 == 4 )
        v31 = a2[3];
      else
        v31 = 1.0;
      v59 = v31;
      v32 = _What;
      _What = fabs(_What);
      v33 = v55;
      v56 = fabs(v55);
      v34 = _What;
      v35 = v56;
      if ( v56 >= (double)_What || (_What = fabs(v52)) >= v34 )
      {
        if ( v34 < v35 )
        {
          _What = fabs(v52);
          if ( _What < v35 )
          {
            v36 = 1;
            _What = v32;
            v38 = v33;
            v33 = v52;
            v32 = v38;
            goto LABEL_45;
          }
        }
        v37 = v32;
        v32 = v52;
        v36 = 2;
      }
      else
      {
        v36 = 0;
        v37 = v33;
        v33 = v52;
      }
      _What = v37;
LABEL_45:
      v53 = v33;
      v57 = v32;
      v39 = _What;
      v40 = flt_100267F0;
      v41 = flt_100267EC;
      if ( flt_100267F0 < (double)_What )
      {
        if ( v41 > v39 )
        {
          v44 = (v39 - v40) / (v41 - v40);
          v42 = flt_100267EC;
          v43 = (__int64)(v44 * 1024.0);
        }
        else
        {
          v42 = flt_100267EC;
          v43 = 1023;
        }
      }
      else
      {
        v42 = flt_100267EC;
        v43 = 0;
      }
      v45 = v53;
      if ( v53 > v40 )
      {
        if ( v45 < v42 )
          v46 = (__int64)(1024.0 * ((v45 - v40) / (v42 - v40)));
        else
          v46 = 1023;
      }
      else
      {
        v46 = 0;
      }
      v47 = (v57 > 0.0) | (2 * ((v59 > 0.0) | (2 * (v36 | (4 * (v46 | (v43 << 10)))))));
      v48 = output;
      if ( (_BYTE)input != 0 )
      {
        *output = BYTE2(v47);
        v48[1] = BYTE1(v47);
      }
      else
      {
        v49 = v47 >> 8;
        *output = v47;
        v47 >>= 16;
        v48[1] = v49;
      }
      v48[2] = v47;
      return;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000CB50
// Name: void edgeGeomMakeSpuVertexBuffer(float const __near *,unsigned int,unsigned short const __near *,enum EdgeGeomAttributeId const __near *,unsigned char,unsigned int const __near *,unsigned int,struct EdgeGeomSpuVertexFormat const __near &,unsigned char __near * __near *,unsigned short __near * const,unsigned int __near * __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl edgeGeomMakeSpuVertexBuffer(
        float *a1,
        unsigned int numFloatsPerSourceVertex,
        ILoggingListener sourceAttributeIds,
        enum EdgeGeomAttributeId *a4,
        unsigned __int8 numSourceAttributes,
        unsigned int *a6,
        unsigned int numUniqueVertexes,
        Color *a8,
        unsigned __int8 **a9,
        unsigned __int16 *const a10,
        ILoggingListener *outFixedPointOffsets,
        unsigned int *outFixedPointOffsetsSize)
{
  Color *v12; // ebx
  float v13; // eax
  ILoggingListener *v14; // ecx
  unsigned int *v15; // edx
  unsigned __int16 *v16; // eax
  char *v17; // esi
  unsigned __int8 *v18; // eax
  unsigned int v19; // ecx
  Color v20; // eax
  int v21; // edi
  unsigned __int8 *v22; // edi
  unsigned int v23; // ebp
  Color *v24; // esi
  int v25; // eax
  int v26; // eax
  int v27; // ecx
  int v28; // eax
  unsigned int v29; // esi
  unsigned __int16 *v30; // edx
  VectorByValue *v31; // [esp+Ch] [ebp-1Ch]
  float *v32; // [esp+10h] [ebp-18h] BYREF
  const float *v33; // [esp+14h] [ebp-14h]
  char *_What; // [esp+18h] [ebp-10h] BYREF
  std::exception pExceptionObject; // [esp+1Ch] [ebp-Ch] BYREF

  v12 = a8;
  v13 = *(float *)&a8[1];
  if ( v13 == 0.0 )
  {
    v14 = outFixedPointOffsets;
    v15 = outFixedPointOffsetsSize;
    *a9 = nullptr;
    v16 = a10;
    *a10 = 0;
    v16[1] = 0;
    v16[2] = 0;
    v14->__vftable = nullptr;
    *v15 = 0;
  }
  else
  {
    v17 = (char *)((numUniqueVertexes * LODWORD(v13) + 15) & 0xFFFFFFF0);
    _What = v17;
    v18 = (unsigned __int8 *)edgeGeomAllocEx(
                               allocSize: (unsigned int)v17,
                               a2: ".\\libedgegeomtool_makebuffers.cpp",
                               lineNumber: 0x1CFu);
    *a9 = v18;
    memset(dst: v18, value: 0, count: (unsigned int)v17);
    a8 = nullptr;
    _edgeGeomFindAttributeMins(
      a1,
      numFloatsPerSourceVertex,
      vertexFormat: v12,
      sourceAttributeIds,
      a5: a4,
      numSourceAttributes,
      a7: a6,
      numUniqueVertexes,
      a9: (float **)&a8,
      outFixedPointOffsets,
      outFixedPointOffsetsSize);
    v19 = 0;
    v31 = nullptr;
    if ( numUniqueVertexes != 0 )
    {
      v20 = *v12;
      do
      {
        v32 = (float *)a8;
        v21 = v19 * *(_DWORD *)&v12[1];
        v33 = &a1[numFloatsPerSourceVertex * a6[v19]];
        v22 = &(*a9)[v21];
        v23 = 0;
        if ( v20 != 0 )
        {
          v24 = v12 + 3;
          do
          {
            v25 = 0;
            if ( numSourceAttributes == 0 )
            {
LABEL_10:
              _What = ".\\libedgegeomtool_makebuffers.cpp(498)";
              std::exception::exception(this: &pExceptionObject, (const char *const *)&_What);
              _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI1_AVexception_std__);
            }
            while ( a4[v25] != *(_DWORD *)&v24[1] )
            {
              if ( ++v25 >= (unsigned int)numSourceAttributes )
                goto LABEL_10;
            }
            v26 = *((unsigned __int16 *)&sourceAttributeIds.Log + v25);
            if ( v26 + *(_DWORD *)v24 > numFloatsPerSourceVertex )
            {
              _What = ".\\libedgegeomtool_makebuffers.cpp(501)";
              std::exception::exception(this: &pExceptionObject, (const char *const *)&_What);
              _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI1_AVexception_std__);
            }
            _edgeGeomConvertAndWriteDataToSpuStream(
              _What: COERCE_FLOAT(v24 - 1),
              a2: (float *)&v33[v26],
              output: &v22[*(_DWORD *)&v24[2]],
              a4: (const float **)&v32,
              input: (CUtlRBTree<CUtlMap<unsigned char *,int,unsigned int>::Node_t,unsigned int,CUtlMap<unsigned char *,int,unsigned int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned char *,int,unsigned int>::Node_t,unsigned int>,unsigned int> > *)1);
            v20 = *v12;
            ++v23;
            v24 += 12;
          }
          while ( v23 < *(_DWORD *)v12 );
          v17 = _What;
          v19 = (unsigned int)v31;
        }
        v31 = (VectorByValue *)++v19;
      }
      while ( v19 < numUniqueVertexes );
    }
    edgeGeomFreeEx(this: (VectorByValue *)v19);
    v27 = 0x4000;
    if ( (unsigned int)v17 <= 0x4000 )
      v27 = (int)v17;
    v28 = (int)&v17[-v27];
    if ( (unsigned int)&v17[-v27] > 0x4000 )
      v28 = 0x4000;
    v29 = (unsigned int)&v17[-v28 - v27];
    if ( v29 >= 0x4000 )
    {
      _What = ".\\libedgegeomtool_makebuffers.cpp(517)";
      std::exception::exception(this: &pExceptionObject, (const char *const *)&_What);
      _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI1_AVexception_std__);
    }
    v30 = a10;
    a10[2] = v29;
    *v30 = v27;
    v30[1] = v28;
  }
}
