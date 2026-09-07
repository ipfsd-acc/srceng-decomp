// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: meshutils/vertexops.cpp
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00409230
// Name: void CopyVertex(float __near *,float const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CopyVertex(float *pOut, float *pIn, int nFloats)
{
  memcpy(dst: (unsigned __int8 *)pOut, src: (unsigned __int8 *)pIn, count: 4 * nFloats);
}

//------------------------------------------------------------------------------
// Address: 0x00409250
// Name: void LerpVertex(float __near *,float const __near *,float const __near *,float,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LerpVertex(float *pOutput, const float *pLeft, const float *pRight, float flLerp, int nFloats)
{
  int v5; // ecx
  double v6; // st7
  float *v7; // ebp
  int v8; // edx
  float *v9; // ecx
  const float *v10; // eax
  double v11; // st6
  const float *v12; // eax
  int v13; // ecx
  double v14; // st6

  v5 = nFloats;
  v6 = flLerp;
  v7 = pOutput;
  v8 = 0;
  if ( nFloats >= 4 )
  {
    v9 = pOutput + 2;
    v10 = pLeft + 1;
    do
    {
      v11 = pRight[v8] - *(v10 - 1);
      v8 += 4;
      v10 += 4;
      v9 += 4;
      *(v9 - 6) = v11 * v6 + *(v10 - 5);
      *(float *)((char *)v10 + (char *)pOutput - (char *)pLeft - 16) = (*(const float *)((char *)v10
                                                                                       + (char *)pRight
                                                                                       - (char *)pLeft
                                                                                       - 16)
                                                                      - *(v10 - 4))
                                                                     * v6
                                                                     + *(v10 - 4);
      *(v9 - 4) = (*(float *)((char *)v9 + (char *)pRight - (char *)pOutput - 16) - *(v10 - 3)) * v6 + *(v10 - 3);
      *(v9 - 3) = (pRight[v8 - 1] - *(v10 - 2)) * v6 + *(v10 - 2);
    }
    while ( v8 < nFloats - 3 );
    v7 = pOutput;
    v5 = nFloats;
  }
  if ( v8 < v5 )
  {
    v12 = &pLeft[v8];
    v13 = v5 - v8;
    do
    {
      v14 = *(const float *)((char *)v12++ + (char *)pRight - (char *)pLeft);
      --v13;
      *(float *)((char *)v12 + (char *)v7 - (char *)pLeft - 4) = (v14 - *(v12 - 1)) * v6 + *(v12 - 1);
    }
    while ( v13 != 0 );
  }
}

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x00576E40
// Name: void CopyVertex(float __near *,float const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CopyVertex(float *pOut, const float *pIn, int nFloats)
{
  _V_memcpy(dest: pOut, src: pIn, count: 4 * nFloats);
}

//------------------------------------------------------------------------------
// Address: 0x00576E60
// Name: void LerpVertex(float __near *,float const __near *,float const __near *,float,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LerpVertex(float *pOutput, const float *pLeft, const float *pRight, float flLerp, int nFloats)
{
  const float *v5; // ebx
  int v6; // edi
  int v7; // edx
  float *v8; // ecx
  const float *v9; // eax
  float *v10; // eax
  int v11; // edi

  v5 = pLeft;
  v6 = nFloats;
  v7 = 0;
  if ( nFloats >= 4 )
  {
    v8 = pOutput + 2;
    v9 = pLeft + 1;
    v6 = nFloats;
    do
    {
      *(v8 - 2) = (float)((float)(pRight[v7] - *(v9 - 1)) * flLerp) + *(v9 - 1);
      *(float *)((char *)v9 + (char *)pOutput - (char *)pLeft) = (float)((float)(*(const float *)((char *)v9
                                                                                                + (char *)pRight
                                                                                                - (char *)pLeft)
                                                                               - *v9)
                                                                       * flLerp)
                                                               + *v9;
      *v8 = (float)((float)(*(float *)((char *)v8 + (char *)pRight - (char *)pOutput) - v9[1]) * flLerp) + v9[1];
      v8[1] = (float)((float)(pRight[v7 + 3] - v9[2]) * flLerp) + v9[2];
      v7 += 4;
      v9 += 4;
      v8 += 4;
    }
    while ( v7 < nFloats - 3 );
    v5 = pLeft;
  }
  if ( v7 < v6 )
  {
    v10 = (float *)&v5[v7];
    v11 = v6 - v7;
    do
    {
      *(float *)((char *)v10 + (char *)pOutput - (char *)v5) = (float)((float)(*(float *)((char *)v10
                                                                                        + (char *)pRight
                                                                                        - (char *)v5)
                                                                             - *v10)
                                                                     * flLerp)
                                                             + *v10;
      ++v10;
      --v11;
    }
    while ( v11 != 0 );
  }
}

} // namespace vmap
