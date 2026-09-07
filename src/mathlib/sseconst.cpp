// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mathlib/sseconst.cpp
// Functions: 2
// ============================================================

#include "mathlib\sseconst.h"

//------------------------------------------------------------------------------
// Address: 0x10204EA0
// Name: public: static union __m128 FourVectors::CalcClosestPointToLineTSIMD(class FourVectors const __near &,class FourVectors const __near &,class FourVectors const __near &,class FourVectors __near &)
// Source: json
//------------------------------------------------------------------------------
__m128 __cdecl FourVectors::CalcClosestPointToLineTSIMD(
        const FourVectors *result,
        const FourVectors *P,
        const FourVectors *vLineA,
        const FourVectors *vLineB)
{
  __m128 x; // xmm1
  __m128 v5; // xmm2
  __m128 v6; // xmm1
  __m128 y; // xmm3

  vLineB->x = vLineA->x;
  x = vLineB->x;
  vLineB->y = vLineA->y;
  vLineB->z = vLineA->z;
  vLineB->x = _mm_sub_ps(x, P->x);
  v5 = vLineB->x;
  vLineB->y = _mm_sub_ps(vLineB->y, P->y);
  v6 = _mm_sub_ps(vLineB->z, P->z);
  y = vLineB->y;
  vLineB->z = v6;
  return _mm_div_ps(
           _mm_sub_ps(
             _mm_add_ps(_mm_add_ps(_mm_mul_ps(result->y, y), _mm_mul_ps(result->x, v5)), _mm_mul_ps(result->z, v6)),
             _mm_add_ps(_mm_add_ps(_mm_mul_ps(y, P->y), _mm_mul_ps(P->x, v5)), _mm_mul_ps(P->z, v6))),
           _mm_add_ps(_mm_add_ps(_mm_mul_ps(y, y), _mm_mul_ps(v5, v5)), _mm_mul_ps(v6, v6)));
}

//------------------------------------------------------------------------------
// Address: 0x10204F40
// Name: public: static void FourVectors::CalcClosestPointOnLineSIMD(class FourVectors const __near &,class FourVectors const __near &,class FourVectors const __near &,class FourVectors __near &,union __m128 __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall FourVectors::CalcClosestPointOnLineSIMD(
        int a1@<ebp>,
        const FourVectors *P,
        const FourVectors *vLineA,
        const FourVectors *vLineB,
        FourVectors *vClosest,
        __m128 *outT)
{
  __m128 *v6; // edx
  __m128 v7; // xmm0
  __m128 v8; // xmm1
  __m128 v9; // xmm2
  __m128 v10; // xmm3
  _BYTE v11[56]; // [esp-Ch] [ebp-3Ch] OVERLAPPED BYREF
  _UNKNOWN *retaddr; // [esp+30h] [ebp+0h]

  *(_DWORD *)&v11[48] = a1;
  *(_DWORD *)&v11[52] = retaddr;
  v7 = FourVectors::CalcClosestPointToLineTSIMD(result: P, P: vLineA, vLineA: vLineB, vLineB: (const FourVectors *)v11);
  if ( outT != nullptr )
    *outT = v7;
  v8 = _mm_mul_ps(*(__m128 *)v11, v7);
  v9 = _mm_mul_ps(*(__m128 *)&v11[16], v7);
  v10 = _mm_mul_ps(*(__m128 *)&v11[32], v7);
  vClosest->x = v8;
  vClosest->y = v9;
  vClosest->z = v10;
  vClosest->x = _mm_add_ps(*v6, v8);
  vClosest->y = _mm_add_ps(v6[1], v9);
  vClosest->z = _mm_add_ps(v6[2], v10);
}

// ============================================================
// Overlay from vphysics (Missing functions)
// ============================================================
namespace vphysics {

//------------------------------------------------------------------------------
// Address: 0x100AB2F0
// Name: public: static void FourVectors::RotateManyBy(class FourVectors restrict __near *,unsigned int,struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FourVectors::RotateManyBy(
        FourVectors *pVectors,
        unsigned int numVectors,
        const matrix3x4_t *rotationMatrix)
{
  __m128 v3; // xmm0
  __m128 v4; // xmm1
  __m128 v5; // xmm2
  __m128 v6; // xmm6
  __m128 v7; // xmm7
  __m128 v8; // xmm5
  __m128 v9; // xmm3
  __m128 *p_z; // ecx
  unsigned int v11; // edx
  __m128 v12; // xmm2
  __m128 v13; // xmm4
  __m128 v14; // xmm5
  __m128 v15; // xmm3
  __m128 v16; // xmm0
  __m128 v17; // xmm6
  __m128 v18; // [esp-Ch] [ebp-9Ch]
  __m128 matSplat22_4; // [esp+4h] [ebp-8Ch]
  __m128 matSplat21_4; // [esp+14h] [ebp-7Ch]
  __m128 matSplat12_4; // [esp+24h] [ebp-6Ch]
  __m128 matSplat00_4; // [esp+34h] [ebp-5Ch]
  __m128 matSplat11_4; // [esp+44h] [ebp-4Ch]
  __m128 matSplat10_4; // [esp+54h] [ebp-3Ch]
  __m128 matSplat02_4; // [esp+64h] [ebp-2Ch]
  __m128 matSplat01_4; // [esp+74h] [ebp-1Ch]

  if ( numVectors != 0 )
  {
    v3 = *(__m128 *)&rotationMatrix->m_flMatVal[0][0];
    v4 = *(__m128 *)&rotationMatrix->m_flMatVal[1][0];
    v5 = *(__m128 *)&rotationMatrix->m_flMatVal[2][0];
    v6 = _mm_shuffle_ps(v3, v3, 0);
    v7 = _mm_shuffle_ps(v3, v3, 85);
    matSplat10_4 = _mm_shuffle_ps(v3, v3, 170);
    matSplat00_4 = _mm_shuffle_ps(v4, v4, 85);
    v8 = _mm_shuffle_ps(v4, v4, 0);
    v9 = _mm_shuffle_ps(v5, v5, 85);
    matSplat12_4 = v6;
    matSplat02_4 = v7;
    matSplat11_4 = v8;
    matSplat21_4 = _mm_shuffle_ps(v4, v4, 170);
    matSplat01_4 = _mm_shuffle_ps(v5, v5, 0);
    matSplat22_4 = v9;
    v18 = _mm_shuffle_ps(v5, v5, 170);
    if ( pVectors < &pVectors[numVectors] )
    {
      p_z = &pVectors->z;
      v11 = (48 * numVectors - 1) / 0x30 + 1;
      while ( 1 )
      {
        v12 = *p_z;
        v13 = _mm_mul_ps(p_z[-2], v8);
        v14 = _mm_mul_ps(p_z[-1], v9);
        v15 = _mm_mul_ps(p_z[-2], matSplat01_4);
        v16 = _mm_mul_ps(p_z[-2], v6);
        v17 = p_z[-1];
        p_z[-2] = _mm_add_ps(_mm_add_ps(v16, _mm_mul_ps(v17, v7)), _mm_mul_ps(*p_z, matSplat10_4));
        p_z[-1] = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v17, matSplat00_4), v13), _mm_mul_ps(v12, matSplat21_4));
        *p_z = _mm_add_ps(_mm_mul_ps(v12, v18), _mm_add_ps(v15, v14));
        p_z += 3;
        if ( --v11 == 0 )
          break;
        v7 = matSplat02_4;
        v6 = matSplat12_4;
        v8 = matSplat11_4;
        v9 = matSplat22_4;
      }
    }
  }
}

} // namespace vphysics

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x102CA640
// Name: public: static union __m128 FourVectors::CalcClosestPointToLineTSIMD(class FourVectors const __near &,class FourVectors const __near &,class FourVectors const __near &,class FourVectors __near &)
// Source: json
//------------------------------------------------------------------------------
__m128 __cdecl FourVectors::CalcClosestPointToLineTSIMD(
        const FourVectors *result,
        const FourVectors *P,
        const FourVectors *vLineA,
        const FourVectors *vLineB)
{
  __m128 x; // xmm1
  __m128 v5; // xmm2
  __m128 v6; // xmm1
  __m128 y; // xmm3

  vLineB->x = vLineA->x;
  x = vLineB->x;
  vLineB->y = vLineA->y;
  vLineB->z = vLineA->z;
  vLineB->x = _mm_sub_ps(x, P->x);
  v5 = vLineB->x;
  vLineB->y = _mm_sub_ps(vLineB->y, P->y);
  v6 = _mm_sub_ps(vLineB->z, P->z);
  y = vLineB->y;
  vLineB->z = v6;
  return _mm_div_ps(
           _mm_sub_ps(
             _mm_add_ps(_mm_add_ps(_mm_mul_ps(result->y, y), _mm_mul_ps(result->x, v5)), _mm_mul_ps(result->z, v6)),
             _mm_add_ps(_mm_add_ps(_mm_mul_ps(y, P->y), _mm_mul_ps(P->x, v5)), _mm_mul_ps(P->z, v6))),
           _mm_add_ps(_mm_add_ps(_mm_mul_ps(y, y), _mm_mul_ps(v5, v5)), _mm_mul_ps(v6, v6)));
}

//------------------------------------------------------------------------------
// Address: 0x102CA6E0
// Name: public: static void FourVectors::CalcClosestPointOnLineSIMD(class FourVectors const __near &,class FourVectors const __near &,class FourVectors const __near &,class FourVectors __near &,union __m128 __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall FourVectors::CalcClosestPointOnLineSIMD(
        int a1@<ebp>,
        const FourVectors *P,
        const FourVectors *vLineA,
        const FourVectors *vLineB,
        FourVectors *vClosest,
        __m128 *outT)
{
  __m128 *v6; // edx
  __m128 v7; // xmm0
  __m128 v8; // xmm1
  __m128 v9; // xmm2
  __m128 v10; // xmm3
  _BYTE v11[56]; // [esp-Ch] [ebp-3Ch] OVERLAPPED BYREF
  _UNKNOWN *retaddr; // [esp+30h] [ebp+0h]

  *(_DWORD *)&v11[48] = a1;
  *(_DWORD *)&v11[52] = retaddr;
  v7 = FourVectors::CalcClosestPointToLineTSIMD(result: P, P: vLineA, vLineA: vLineB, vLineB: (const FourVectors *)v11);
  if ( outT != nullptr )
    *outT = v7;
  v8 = _mm_mul_ps(*(__m128 *)v11, v7);
  v9 = _mm_mul_ps(*(__m128 *)&v11[16], v7);
  v10 = _mm_mul_ps(*(__m128 *)&v11[32], v7);
  vClosest->x = v8;
  vClosest->y = v9;
  vClosest->z = v10;
  vClosest->x = _mm_add_ps(*v6, v8);
  vClosest->y = _mm_add_ps(v6[1], v9);
  vClosest->z = _mm_add_ps(v6[2], v10);
}

} // namespace client
