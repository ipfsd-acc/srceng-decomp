// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: bitmap/floatbitmap2.cpp
// Functions: 1
// ============================================================

#include "bitmap\floatbitmap2.h"

//------------------------------------------------------------------------------
// Address: 0x10221B30
// Name: public: void FloatBitMap_t::CompressTo8Bits(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::CompressTo8Bits(FloatBitMap_t *this, float overbright)
{
  float v3; // xmm2_4
  int i; // ecx
  int j; // eax
  unsigned int v6; // edx
  unsigned __int8 *v7; // edi
  float v8; // xmm0_4
  unsigned int v9; // edx
  unsigned __int8 *v10; // edi
  float v11; // xmm0_4
  unsigned int v12; // edx
  unsigned __int8 *v13; // edi
  float v14; // xmm0_4
  int k; // ebx
  int m; // edi
  float v17; // xmm1_4
  unsigned __int8 *v18; // edx
  unsigned int v19; // eax
  float v20; // xmm0_4
  float v21; // xmm4_4
  unsigned __int8 *v22; // edx
  unsigned int v23; // eax
  double v24; // xmm0_8
  float v25; // xmm0_4
  float v26; // xmm1_4
  int v27; // edx
  int m_nColumns; // ecx
  int v29; // eax
  unsigned int v30; // ecx
  FloatBitMap_t v31; // [esp+8h] [ebp-334h] BYREF
  double v32; // [esp+32Ch] [ebp-10h]
  double v33; // [esp+334h] [ebp-8h]
  int var10_4; // [esp+33Ch] [ebp+0h] BYREF

  FloatBitMap_t::FloatBitMap_t(
    this: &v31,
    nWidth: (unsigned __int8 *)this->m_nColumns,
    nHeight: (unsigned __int8 *)this->m_nRows,
    nDepth: 1,
    nAttributeMask: 15);
  v3 = overbright;
  for ( i = 0; i < this->m_nRows; ++i )
  {
    for ( j = 0; j < this->m_nColumns; *(float *)&v13[v12] = v14 )
    {
      v6 = i * this->m_nRowStrideInBytes[0] + j * this->m_nStrideInBytes[0];
      v7 = this->m_pAttributePtrs[0];
      v8 = *(float *)&v7[v6];
      if ( v8 > overbright )
        v8 = overbright;
      *(float *)&v7[v6] = v8;
      v9 = i * this->m_nRowStrideInBytes[1] + j * this->m_nStrideInBytes[1];
      v10 = this->m_pAttributePtrs[1];
      v11 = *(float *)&v10[v9];
      if ( v11 > overbright )
        v11 = overbright;
      *(float *)&v10[v9] = v11;
      v12 = i * this->m_nRowStrideInBytes[2] + j * this->m_nStrideInBytes[2];
      v13 = this->m_pAttributePtrs[2];
      v14 = *(float *)&v13[v12];
      if ( v14 > overbright )
        v14 = overbright;
      ++j;
    }
  }
  for ( k = 0; k < this->m_nRows; ++k )
  {
    for ( m = 0; m < this->m_nColumns; ++m )
    {
      v17 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      v18 = this->m_pAttributePtrs[1];
      v19 = k * this->m_nRowStrideInBytes[1] + m * this->m_nStrideInBytes[1];
      v20 = *(float *)&v18[v19];
      if ( v17 <= v20 )
        v21 = *(float *)&v18[v19];
      else
        v21 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      v22 = this->m_pAttributePtrs[2];
      v23 = k * this->m_nRowStrideInBytes[2] + m * this->m_nStrideInBytes[2];
      if ( v21 <= *(float *)&v22[v23] )
      {
        v20 = *(float *)&v22[v23];
      }
      else if ( v17 > v20 )
      {
        v20 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      }
      if ( v20 == 0.0 )
      {
        *(_DWORD *)&v31.m_pAttributePtrs[0][k * v31.m_nRowStrideInBytes[0] + m * v31.m_nStrideInBytes[0]] = 0;
        *(_DWORD *)&v31.m_pAttributePtrs[1][m * v31.m_nStrideInBytes[1] + k * v31.m_nRowStrideInBytes[1]] = 0;
        *(_DWORD *)&v31.m_pAttributePtrs[2][m * v31.m_nStrideInBytes[2] + k * v31.m_nRowStrideInBytes[2]] = 0;
        *(_DWORD *)&v31.m_pAttributePtrs[3][m * v31.m_nStrideInBytes[3] + k * v31.m_nRowStrideInBytes[3]] = 0;
      }
      else
      {
        v32 = (float)(1.0 / v3 * v20) * 255.0;
        if ( ceil(X: v32) <= 255.0 )
        {
          v33 = ceil(X: v32);
          v24 = v33;
        }
        else
        {
          v24 = 255.0;
        }
        v3 = overbright;
        v25 = (float)(int)v24;
        *(float *)&v31.m_pAttributePtrs[3][m * v31.m_nStrideInBytes[3] + k * v31.m_nRowStrideInBytes[3]] = v25;
        v26 = overbright * 0.00392156862745098 * (double)(int)v25;
        *(float *)&v31.m_pAttributePtrs[0][k * v31.m_nRowStrideInBytes[0] + m * v31.m_nStrideInBytes[0]] = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]] * (float)(1.0 / v26);
        *(float *)&v31.m_pAttributePtrs[1][m * v31.m_nStrideInBytes[1] + k * v31.m_nRowStrideInBytes[1]] = *(float *)&this->m_pAttributePtrs[1][k * this->m_nRowStrideInBytes[1] + m * this->m_nStrideInBytes[1]] * (float)(1.0 / v26);
        *(float *)&v31.m_pAttributePtrs[2][m * v31.m_nStrideInBytes[2] + k * v31.m_nRowStrideInBytes[2]] = *(float *)&this->m_pAttributePtrs[2][k * this->m_nRowStrideInBytes[2] + m * this->m_nStrideInBytes[2]] * (float)(1.0 / v26);
      }
    }
  }
  CSOAContainer::CopyAttrFrom(
    this,
    a2: (unsigned int)&var10_4,
    other: (CFunctor_vtbl *)&v31,
    nDestAttributeIndex: 0,
    nSrcAttributeIndex: (CFunctor_vtbl *)0xFFFFFFFF);
  CSOAContainer::CopyAttrFrom(
    this,
    a2: (unsigned int)&var10_4,
    other: (CFunctor_vtbl *)&v31,
    nDestAttributeIndex: 1u,
    nSrcAttributeIndex: (CFunctor_vtbl *)0xFFFFFFFF);
  CSOAContainer::CopyAttrFrom(
    this,
    a2: (unsigned int)&var10_4,
    other: (CFunctor_vtbl *)&v31,
    nDestAttributeIndex: 2u,
    nSrcAttributeIndex: (CFunctor_vtbl *)0xFFFFFFFF);
  CSOAContainer::CopyAttrFrom(
    this,
    a2: (unsigned int)&var10_4,
    other: (CFunctor_vtbl *)&v31,
    nDestAttributeIndex: 3u,
    nSrcAttributeIndex: (CFunctor_vtbl *)0xFFFFFFFF);
  v27 = 0;
  if ( this->m_nRows > 0 )
  {
    m_nColumns = this->m_nColumns;
    do
    {
      v29 = 0;
      if ( m_nColumns > 0 )
      {
        do
        {
          v30 = v27 * this->m_nRowStrideInBytes[3] + v29 * this->m_nStrideInBytes[3];
          *(float *)&this->m_pAttributePtrs[3][v30] = *(float *)&this->m_pAttributePtrs[3][v30] * 0.00392156862745098;
          m_nColumns = this->m_nColumns;
          ++v29;
        }
        while ( v29 < this->m_nColumns );
      }
      ++v27;
    }
    while ( v27 < this->m_nRows );
  }
  CSOAContainer::~CSOAContainer(this: &v31);
}

// ============================================================
// Overlay from MaterialSystem (Missing functions)
// ============================================================
namespace MaterialSystem {

//------------------------------------------------------------------------------
// Address: 0x10231DB0
// Name: public: void FloatBitMap_t::CompressTo8Bits(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::CompressTo8Bits(FloatBitMap_t *this, float overbright)
{
  float v3; // xmm2_4
  int i; // ecx
  int j; // eax
  unsigned int v6; // edx
  unsigned __int8 *v7; // edi
  float v8; // xmm0_4
  unsigned int v9; // edx
  unsigned __int8 *v10; // edi
  float v11; // xmm0_4
  unsigned int v12; // edx
  unsigned __int8 *v13; // edi
  float v14; // xmm0_4
  int k; // ebx
  int m; // edi
  float v17; // xmm1_4
  unsigned __int8 *v18; // edx
  unsigned int v19; // eax
  float v20; // xmm0_4
  float v21; // xmm4_4
  unsigned __int8 *v22; // edx
  unsigned int v23; // eax
  double v24; // xmm0_8
  float v25; // xmm0_4
  float v26; // xmm1_4
  int v27; // edx
  int m_nColumns; // ecx
  int v29; // eax
  unsigned int v30; // ecx
  FloatBitMap_t TmpFBM; // [esp+14h] [ebp-334h] BYREF
  double X; // [esp+338h] [ebp-10h]
  double v33; // [esp+340h] [ebp-8h]

  FloatBitMap_t::FloatBitMap_t(
    this: &TmpFBM,
    nWidth: this->m_nColumns,
    nHeight: this->m_nRows,
    nDepth: 1,
    nAttributeMask: 15);
  v3 = overbright;
  for ( i = 0; i < this->m_nRows; ++i )
  {
    for ( j = 0; j < this->m_nColumns; *(float *)&v13[v12] = v14 )
    {
      v6 = i * this->m_nRowStrideInBytes[0] + j * this->m_nStrideInBytes[0];
      v7 = this->m_pAttributePtrs[0];
      v8 = *(float *)&v7[v6];
      if ( v8 > overbright )
        v8 = overbright;
      *(float *)&v7[v6] = v8;
      v9 = i * this->m_nRowStrideInBytes[1] + j * this->m_nStrideInBytes[1];
      v10 = this->m_pAttributePtrs[1];
      v11 = *(float *)&v10[v9];
      if ( v11 > overbright )
        v11 = overbright;
      *(float *)&v10[v9] = v11;
      v12 = i * this->m_nRowStrideInBytes[2] + j * this->m_nStrideInBytes[2];
      v13 = this->m_pAttributePtrs[2];
      v14 = *(float *)&v13[v12];
      if ( v14 > overbright )
        v14 = overbright;
      ++j;
    }
  }
  for ( k = 0; k < this->m_nRows; ++k )
  {
    for ( m = 0; m < this->m_nColumns; ++m )
    {
      v17 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      v18 = this->m_pAttributePtrs[1];
      v19 = k * this->m_nRowStrideInBytes[1] + m * this->m_nStrideInBytes[1];
      v20 = *(float *)&v18[v19];
      if ( v17 <= v20 )
        v21 = *(float *)&v18[v19];
      else
        v21 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      v22 = this->m_pAttributePtrs[2];
      v23 = k * this->m_nRowStrideInBytes[2] + m * this->m_nStrideInBytes[2];
      if ( v21 <= *(float *)&v22[v23] )
      {
        v20 = *(float *)&v22[v23];
      }
      else if ( v17 > v20 )
      {
        v20 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      }
      if ( v20 == 0.0 )
      {
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[0][k * TmpFBM.m_nRowStrideInBytes[0] + m * TmpFBM.m_nStrideInBytes[0]] = 0;
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[1][m * TmpFBM.m_nStrideInBytes[1] + k * TmpFBM.m_nRowStrideInBytes[1]] = 0;
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[2][m * TmpFBM.m_nStrideInBytes[2] + k * TmpFBM.m_nRowStrideInBytes[2]] = 0;
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[3][m * TmpFBM.m_nStrideInBytes[3] + k * TmpFBM.m_nRowStrideInBytes[3]] = 0;
      }
      else
      {
        X = (float)(1.0 / v3 * v20) * 255.0;
        if ( ceil(X) <= 255.0 )
        {
          v33 = ceil(X);
          v24 = v33;
        }
        else
        {
          v24 = 255.0;
        }
        v3 = overbright;
        v25 = (float)(int)v24;
        *(float *)&TmpFBM.m_pAttributePtrs[3][m * TmpFBM.m_nStrideInBytes[3] + k * TmpFBM.m_nRowStrideInBytes[3]] = v25;
        v26 = overbright * 0.00392156862745098 * (double)(int)v25;
        *(float *)&TmpFBM.m_pAttributePtrs[0][k * TmpFBM.m_nRowStrideInBytes[0] + m * TmpFBM.m_nStrideInBytes[0]] = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]] * (float)(1.0 / v26);
        *(float *)&TmpFBM.m_pAttributePtrs[1][m * TmpFBM.m_nStrideInBytes[1] + k * TmpFBM.m_nRowStrideInBytes[1]] = *(float *)&this->m_pAttributePtrs[1][k * this->m_nRowStrideInBytes[1] + m * this->m_nStrideInBytes[1]] * (float)(1.0 / v26);
        *(float *)&TmpFBM.m_pAttributePtrs[2][m * TmpFBM.m_nStrideInBytes[2] + k * TmpFBM.m_nRowStrideInBytes[2]] = *(float *)&this->m_pAttributePtrs[2][k * this->m_nRowStrideInBytes[2] + m * this->m_nStrideInBytes[2]] * (float)(1.0 / v26);
      }
    }
  }
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 0, nSrcAttributeIndex: -1);
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 1, nSrcAttributeIndex: -1);
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 2, nSrcAttributeIndex: -1);
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 3, nSrcAttributeIndex: -1);
  v27 = 0;
  if ( this->m_nRows > 0 )
  {
    m_nColumns = this->m_nColumns;
    do
    {
      v29 = 0;
      if ( m_nColumns > 0 )
      {
        do
        {
          v30 = v27 * this->m_nRowStrideInBytes[3] + v29 * this->m_nStrideInBytes[3];
          *(float *)&this->m_pAttributePtrs[3][v30] = *(float *)&this->m_pAttributePtrs[3][v30] * 0.00392156862745098;
          m_nColumns = this->m_nColumns;
          ++v29;
        }
        while ( v29 < this->m_nColumns );
      }
      ++v27;
    }
    while ( v27 < this->m_nRows );
  }
  CSOAContainer::~CSOAContainer(this: &TmpFBM);
}

} // namespace MaterialSystem

// ============================================================
// Overlay from Dist2alpha (Missing functions)
// ============================================================
namespace Dist2alpha {

//------------------------------------------------------------------------------
// Address: 0x00410810
// Name: public: void FloatBitMap_t::CompressTo8Bits(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::CompressTo8Bits(FloatBitMap_t *this, float overbright)
{
  float v3; // xmm2_4
  int i; // ecx
  int j; // eax
  unsigned int v6; // edx
  unsigned __int8 *v7; // edi
  float v8; // xmm0_4
  unsigned int v9; // edx
  unsigned __int8 *v10; // edi
  float v11; // xmm0_4
  unsigned int v12; // edx
  unsigned __int8 *v13; // edi
  float v14; // xmm0_4
  int k; // ebx
  int m; // edi
  float v17; // xmm1_4
  unsigned __int8 *v18; // edx
  unsigned int v19; // eax
  float v20; // xmm0_4
  float v21; // xmm4_4
  unsigned __int8 *v22; // edx
  unsigned int v23; // eax
  double v24; // xmm0_8
  float v25; // xmm0_4
  float v26; // xmm1_4
  int v27; // edx
  int m_nColumns; // ecx
  int v29; // eax
  unsigned int v30; // ecx
  FloatBitMap_t TmpFBM; // [esp+14h] [ebp-334h] BYREF
  double X; // [esp+338h] [ebp-10h]
  double v33; // [esp+340h] [ebp-8h]

  FloatBitMap_t::FloatBitMap_t(
    this: &TmpFBM,
    nWidth: this->m_nColumns,
    nHeight: this->m_nRows,
    nDepth: 1,
    nAttributeMask: 15);
  v3 = overbright;
  for ( i = 0; i < this->m_nRows; ++i )
  {
    for ( j = 0; j < this->m_nColumns; *(float *)&v13[v12] = v14 )
    {
      v6 = i * this->m_nRowStrideInBytes[0] + j * this->m_nStrideInBytes[0];
      v7 = this->m_pAttributePtrs[0];
      v8 = *(float *)&v7[v6];
      if ( v8 > overbright )
        v8 = overbright;
      *(float *)&v7[v6] = v8;
      v9 = i * this->m_nRowStrideInBytes[1] + j * this->m_nStrideInBytes[1];
      v10 = this->m_pAttributePtrs[1];
      v11 = *(float *)&v10[v9];
      if ( v11 > overbright )
        v11 = overbright;
      *(float *)&v10[v9] = v11;
      v12 = i * this->m_nRowStrideInBytes[2] + j * this->m_nStrideInBytes[2];
      v13 = this->m_pAttributePtrs[2];
      v14 = *(float *)&v13[v12];
      if ( v14 > overbright )
        v14 = overbright;
      ++j;
    }
  }
  for ( k = 0; k < this->m_nRows; ++k )
  {
    for ( m = 0; m < this->m_nColumns; ++m )
    {
      v17 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      v18 = this->m_pAttributePtrs[1];
      v19 = k * this->m_nRowStrideInBytes[1] + m * this->m_nStrideInBytes[1];
      v20 = *(float *)&v18[v19];
      if ( v17 <= v20 )
        v21 = *(float *)&v18[v19];
      else
        v21 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      v22 = this->m_pAttributePtrs[2];
      v23 = k * this->m_nRowStrideInBytes[2] + m * this->m_nStrideInBytes[2];
      if ( v21 <= *(float *)&v22[v23] )
      {
        v20 = *(float *)&v22[v23];
      }
      else if ( v17 > v20 )
      {
        v20 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      }
      if ( v20 == 0.0 )
      {
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[0][k * TmpFBM.m_nRowStrideInBytes[0] + m * TmpFBM.m_nStrideInBytes[0]] = 0;
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[1][m * TmpFBM.m_nStrideInBytes[1] + k * TmpFBM.m_nRowStrideInBytes[1]] = 0;
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[2][m * TmpFBM.m_nStrideInBytes[2] + k * TmpFBM.m_nRowStrideInBytes[2]] = 0;
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[3][m * TmpFBM.m_nStrideInBytes[3] + k * TmpFBM.m_nRowStrideInBytes[3]] = 0;
      }
      else
      {
        X = (float)(1.0 / v3 * v20) * 255.0;
        if ( ceil(X) <= 255.0 )
        {
          v33 = ceil(X);
          v24 = v33;
        }
        else
        {
          v24 = 255.0;
        }
        v3 = overbright;
        v25 = (float)(int)v24;
        *(float *)&TmpFBM.m_pAttributePtrs[3][m * TmpFBM.m_nStrideInBytes[3] + k * TmpFBM.m_nRowStrideInBytes[3]] = v25;
        v26 = overbright * 0.00392156862745098 * (double)(int)v25;
        *(float *)&TmpFBM.m_pAttributePtrs[0][k * TmpFBM.m_nRowStrideInBytes[0] + m * TmpFBM.m_nStrideInBytes[0]] = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]] * (float)(1.0 / v26);
        *(float *)&TmpFBM.m_pAttributePtrs[1][m * TmpFBM.m_nStrideInBytes[1] + k * TmpFBM.m_nRowStrideInBytes[1]] = *(float *)&this->m_pAttributePtrs[1][k * this->m_nRowStrideInBytes[1] + m * this->m_nStrideInBytes[1]] * (float)(1.0 / v26);
        *(float *)&TmpFBM.m_pAttributePtrs[2][m * TmpFBM.m_nStrideInBytes[2] + k * TmpFBM.m_nRowStrideInBytes[2]] = *(float *)&this->m_pAttributePtrs[2][k * this->m_nRowStrideInBytes[2] + m * this->m_nStrideInBytes[2]] * (float)(1.0 / v26);
      }
    }
  }
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 0, nSrcAttributeIndex: -1);
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 1, nSrcAttributeIndex: -1);
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 2, nSrcAttributeIndex: -1);
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 3, nSrcAttributeIndex: -1);
  v27 = 0;
  if ( this->m_nRows > 0 )
  {
    m_nColumns = this->m_nColumns;
    do
    {
      v29 = 0;
      if ( m_nColumns > 0 )
      {
        do
        {
          v30 = v27 * this->m_nRowStrideInBytes[3] + v29 * this->m_nStrideInBytes[3];
          *(float *)&this->m_pAttributePtrs[3][v30] = *(float *)&this->m_pAttributePtrs[3][v30] * 0.00392156862745098;
          m_nColumns = this->m_nColumns;
          ++v29;
        }
        while ( v29 < this->m_nColumns );
      }
      ++v27;
    }
    while ( v27 < this->m_nRows );
  }
  CSOAContainer::~CSOAContainer(this: &TmpFBM);
}

//------------------------------------------------------------------------------
// Address: 0x00410CC0
// Name: bool SupportsSSE2(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
bool __cdecl SupportsSSE2()
{
  return IsProcessorFeaturePresent(ProcessorFeature: 0xAu);
}

//------------------------------------------------------------------------------
// Address: 0x00411000
// Name: unsigned long CalcBufferSize(enum _CodecType,unsigned long,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl CalcBufferSize(int a1, int a2, int a3)
{
  int v3; // eax
  unsigned int result; // eax

  switch ( a1 )
  {
    case 2:
    case 11:
      v3 = 1;
      goto LABEL_4;
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 12:
    case 13:
    case 14:
      v3 = 2;
LABEL_4:
      result = (4 * 4 * ((unsigned int)(a3 + 3) >> 2) * 4 * ((unsigned int)(a2 + 3) >> 2) * v3) >> 3;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00411070
// Name: unsigned char DeriveB(unsigned char,unsigned char)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 __cdecl DeriveB(unsigned __int8 a1, unsigned __int8 a2)
{
  double v2; // st6
  double v3; // st7
  float v5; // [esp+0h] [ebp-4h]
  float v6; // [esp+8h] [ebp+4h]
  float v7; // [esp+8h] [ebp+4h]
  float v8; // [esp+8h] [ebp+4h]
  float v9; // [esp+8h] [ebp+4h]
  float v10; // [esp+8h] [ebp+4h]
  float v11; // [esp+8h] [ebp+4h]
  float v12; // [esp+8h] [ebp+4h]
  float v13; // [esp+8h] [ebp+4h]
  float v14; // [esp+8h] [ebp+4h]
  float v15; // [esp+8h] [ebp+4h]

  v6 = (double)a1 / 255.0;
  v7 = v6 * 2.0;
  v5 = v7 - 1.0;
  v8 = (double)a2 / 255.0;
  v9 = 2.0 * v8;
  v10 = v9 - 1.0;
  v2 = v10 * v10 + v5 * v5;
  if ( v2 >= 1.0 )
    v2 = 1.0;
  v11 = v2;
  v12 = 1.0 - v11;
  v13 = sqrt(v12);
  v14 = v13 * 127.0;
  v15 = v14 + 128.0;
  if ( v15 < 255.0 )
  {
    v3 = 0.0;
    if ( v15 > 0.0 )
      return (int)v15;
  }
  else
  {
    v3 = 255.0;
  }
  return (int)(float)v3;
}

//------------------------------------------------------------------------------
// Address: 0x00411180
// Name: float DeriveB(float,float)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl DeriveB(float a1, float a2)
{
  double v2; // st6
  float v4; // [esp+0h] [ebp-4h]
  float v5; // [esp+8h] [ebp+4h]
  float v6; // [esp+8h] [ebp+4h]
  float v7; // [esp+8h] [ebp+4h]
  float v8; // [esp+8h] [ebp+4h]
  float v9; // [esp+8h] [ebp+4h]
  float v10; // [esp+8h] [ebp+4h]
  float v11; // [esp+8h] [ebp+4h]

  v5 = a1 * 2.0;
  v4 = v5 - 1.0;
  v6 = 2.0 * a2;
  v7 = v6 - 1.0;
  v2 = v7 * v7 + v4 * v4;
  if ( v2 >= 1.0 )
    v2 = 1.0;
  v8 = v2;
  v9 = 1.0 - v8;
  v10 = sqrt(v9);
  v11 = v10 + 1.0;
  return (float)(v11 * 0.5);
}

//------------------------------------------------------------------------------
// Address: 0x00411240
// Name: public: half::half(float)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
half *__thiscall half::half(half *this, int a2)
{
  if ( *(float *)&a2 == 0.0 )
  {
    *(_WORD *)this = 0;
    return this;
  }
  else
  {
    if ( *((_WORD *)&half::_eLut + ((unsigned int)a2 >> 23)) != 0 )
      *(_WORD *)this = *((_WORD *)&half::_eLut + ((unsigned int)a2 >> 23)) + (((a2 & 0x7FFFFFu) + 4096) >> 13);
    else
      *(_WORD *)this = half::convert(a1: a2);
    return this;
  }
}

} // namespace Dist2alpha

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x004DB3A0
// Name: public: void FloatBitMap_t::CompressTo8Bits(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::CompressTo8Bits(FloatBitMap_t *this, float overbright)
{
  float v3; // xmm2_4
  int i; // ecx
  int j; // eax
  unsigned int v6; // edx
  unsigned __int8 *v7; // edi
  float v8; // xmm0_4
  unsigned int v9; // edx
  unsigned __int8 *v10; // edi
  float v11; // xmm0_4
  unsigned int v12; // edx
  unsigned __int8 *v13; // edi
  float v14; // xmm0_4
  int k; // ebx
  int m; // edi
  float v17; // xmm1_4
  unsigned __int8 *v18; // edx
  unsigned int v19; // eax
  float v20; // xmm0_4
  float v21; // xmm4_4
  unsigned __int8 *v22; // edx
  unsigned int v23; // eax
  double v24; // xmm0_8
  float v25; // xmm0_4
  float v26; // xmm1_4
  int v27; // edx
  int m_nColumns; // ecx
  int v29; // eax
  unsigned int v30; // ecx
  FloatBitMap_t TmpFBM; // [esp+14h] [ebp-334h] BYREF
  double X; // [esp+338h] [ebp-10h]
  double v33; // [esp+340h] [ebp-8h]

  FloatBitMap_t::FloatBitMap_t(
    this: &TmpFBM,
    nWidth: this->m_nColumns,
    nHeight: this->m_nRows,
    nDepth: 1,
    nAttributeMask: 15);
  v3 = overbright;
  for ( i = 0; i < this->m_nRows; ++i )
  {
    for ( j = 0; j < this->m_nColumns; *(float *)&v13[v12] = v14 )
    {
      v6 = i * this->m_nRowStrideInBytes[0] + j * this->m_nStrideInBytes[0];
      v7 = this->m_pAttributePtrs[0];
      v8 = *(float *)&v7[v6];
      if ( v8 > overbright )
        v8 = overbright;
      *(float *)&v7[v6] = v8;
      v9 = i * this->m_nRowStrideInBytes[1] + j * this->m_nStrideInBytes[1];
      v10 = this->m_pAttributePtrs[1];
      v11 = *(float *)&v10[v9];
      if ( v11 > overbright )
        v11 = overbright;
      *(float *)&v10[v9] = v11;
      v12 = i * this->m_nRowStrideInBytes[2] + j * this->m_nStrideInBytes[2];
      v13 = this->m_pAttributePtrs[2];
      v14 = *(float *)&v13[v12];
      if ( v14 > overbright )
        v14 = overbright;
      ++j;
    }
  }
  for ( k = 0; k < this->m_nRows; ++k )
  {
    for ( m = 0; m < this->m_nColumns; ++m )
    {
      v17 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      v18 = this->m_pAttributePtrs[1];
      v19 = k * this->m_nRowStrideInBytes[1] + m * this->m_nStrideInBytes[1];
      v20 = *(float *)&v18[v19];
      if ( v17 <= v20 )
        v21 = *(float *)&v18[v19];
      else
        v21 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      v22 = this->m_pAttributePtrs[2];
      v23 = k * this->m_nRowStrideInBytes[2] + m * this->m_nStrideInBytes[2];
      if ( v21 <= *(float *)&v22[v23] )
      {
        v20 = *(float *)&v22[v23];
      }
      else if ( v17 > v20 )
      {
        v20 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      }
      if ( v20 == 0.0 )
      {
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[0][k * TmpFBM.m_nRowStrideInBytes[0] + m * TmpFBM.m_nStrideInBytes[0]] = 0;
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[1][m * TmpFBM.m_nStrideInBytes[1] + k * TmpFBM.m_nRowStrideInBytes[1]] = 0;
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[2][m * TmpFBM.m_nStrideInBytes[2] + k * TmpFBM.m_nRowStrideInBytes[2]] = 0;
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[3][m * TmpFBM.m_nStrideInBytes[3] + k * TmpFBM.m_nRowStrideInBytes[3]] = 0;
      }
      else
      {
        X = (float)(1.0 / v3 * v20) * 255.0;
        if ( ceil(X) <= 255.0 )
        {
          v33 = ceil(X);
          v24 = v33;
        }
        else
        {
          v24 = 255.0;
        }
        v3 = overbright;
        v25 = (float)(int)v24;
        *(float *)&TmpFBM.m_pAttributePtrs[3][m * TmpFBM.m_nStrideInBytes[3] + k * TmpFBM.m_nRowStrideInBytes[3]] = v25;
        v26 = overbright * 0.00392156862745098 * (double)(int)v25;
        *(float *)&TmpFBM.m_pAttributePtrs[0][k * TmpFBM.m_nRowStrideInBytes[0] + m * TmpFBM.m_nStrideInBytes[0]] = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]] * (float)(1.0 / v26);
        *(float *)&TmpFBM.m_pAttributePtrs[1][m * TmpFBM.m_nStrideInBytes[1] + k * TmpFBM.m_nRowStrideInBytes[1]] = *(float *)&this->m_pAttributePtrs[1][k * this->m_nRowStrideInBytes[1] + m * this->m_nStrideInBytes[1]] * (float)(1.0 / v26);
        *(float *)&TmpFBM.m_pAttributePtrs[2][m * TmpFBM.m_nStrideInBytes[2] + k * TmpFBM.m_nRowStrideInBytes[2]] = *(float *)&this->m_pAttributePtrs[2][k * this->m_nRowStrideInBytes[2] + m * this->m_nStrideInBytes[2]] * (float)(1.0 / v26);
      }
    }
  }
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 0, nSrcAttributeIndex: -1);
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 1, nSrcAttributeIndex: -1);
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 2, nSrcAttributeIndex: -1);
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 3, nSrcAttributeIndex: -1);
  v27 = 0;
  if ( this->m_nRows > 0 )
  {
    m_nColumns = this->m_nColumns;
    do
    {
      v29 = 0;
      if ( m_nColumns > 0 )
      {
        do
        {
          v30 = v27 * this->m_nRowStrideInBytes[3] + v29 * this->m_nStrideInBytes[3];
          *(float *)&this->m_pAttributePtrs[3][v30] = *(float *)&this->m_pAttributePtrs[3][v30] * 0.00392156862745098;
          m_nColumns = this->m_nColumns;
          ++v29;
        }
        while ( v29 < this->m_nColumns );
      }
      ++v27;
    }
    while ( v27 < this->m_nRows );
  }
  CSOAContainer::~CSOAContainer(this: &TmpFBM);
}

//------------------------------------------------------------------------------
// Address: 0x004DB850
// Name: bool SupportsSSE2(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
bool __cdecl SupportsSSE2()
{
  return IsProcessorFeaturePresent(ProcessorFeature: 0xAu);
}

//------------------------------------------------------------------------------
// Address: 0x004DBB90
// Name: unsigned long CalcBufferSize(enum _CodecType,unsigned long,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl CalcBufferSize(int a1, int a2, int a3)
{
  int v3; // eax
  unsigned int result; // eax

  switch ( a1 )
  {
    case 2:
    case 11:
      v3 = 1;
      goto LABEL_4;
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 12:
    case 13:
    case 14:
      v3 = 2;
LABEL_4:
      result = (4 * 4 * ((unsigned int)(a3 + 3) >> 2) * 4 * ((unsigned int)(a2 + 3) >> 2) * v3) >> 3;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004DBC00
// Name: unsigned char DeriveB(unsigned char,unsigned char)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 __cdecl DeriveB(unsigned __int8 a1, unsigned __int8 a2)
{
  double v2; // st6
  double v3; // st7
  float v5; // [esp+0h] [ebp-4h]
  float v6; // [esp+8h] [ebp+4h]
  float v7; // [esp+8h] [ebp+4h]
  float v8; // [esp+8h] [ebp+4h]
  float v9; // [esp+8h] [ebp+4h]
  float v10; // [esp+8h] [ebp+4h]
  float v11; // [esp+8h] [ebp+4h]
  float v12; // [esp+8h] [ebp+4h]
  float v13; // [esp+8h] [ebp+4h]
  float v14; // [esp+8h] [ebp+4h]
  float v15; // [esp+8h] [ebp+4h]

  v6 = (double)a1 / 255.0;
  v7 = v6 * 2.0;
  v5 = v7 - 1.0;
  v8 = (double)a2 / 255.0;
  v9 = 2.0 * v8;
  v10 = v9 - 1.0;
  v2 = v10 * v10 + v5 * v5;
  if ( v2 >= 1.0 )
    v2 = 1.0;
  v11 = v2;
  v12 = 1.0 - v11;
  v13 = sqrt(v12);
  v14 = v13 * 127.0;
  v15 = v14 + 128.0;
  if ( v15 < 255.0 )
  {
    v3 = 0.0;
    if ( v15 > 0.0 )
      return (int)v15;
  }
  else
  {
    v3 = 255.0;
  }
  return (int)(float)v3;
}

//------------------------------------------------------------------------------
// Address: 0x004DBD10
// Name: float DeriveB(float,float)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl DeriveB(float a1, float a2)
{
  double v2; // st6
  float v4; // [esp+0h] [ebp-4h]
  float v5; // [esp+8h] [ebp+4h]
  float v6; // [esp+8h] [ebp+4h]
  float v7; // [esp+8h] [ebp+4h]
  float v8; // [esp+8h] [ebp+4h]
  float v9; // [esp+8h] [ebp+4h]
  float v10; // [esp+8h] [ebp+4h]
  float v11; // [esp+8h] [ebp+4h]

  v5 = a1 * 2.0;
  v4 = v5 - 1.0;
  v6 = 2.0 * a2;
  v7 = v6 - 1.0;
  v2 = v7 * v7 + v4 * v4;
  if ( v2 >= 1.0 )
    v2 = 1.0;
  v8 = v2;
  v9 = 1.0 - v8;
  v10 = sqrt(v9);
  v11 = v10 + 1.0;
  return (float)(v11 * 0.5);
}

//------------------------------------------------------------------------------
// Address: 0x004DBDC0
// Name: public: half::half(float)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
half *__thiscall half::half(half *this, int a2)
{
  if ( *(float *)&a2 == 0.0 )
  {
    *(_WORD *)this = 0;
    return this;
  }
  else
  {
    if ( *((_WORD *)&half::_eLut + ((unsigned int)a2 >> 23)) != 0 )
      *(_WORD *)this = *((_WORD *)&half::_eLut + ((unsigned int)a2 >> 23)) + (((a2 & 0x7FFFFFu) + 4096) >> 13);
    else
      *(_WORD *)this = half::convert(a1: a2);
    return this;
  }
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10221D00
// Name: public: void FloatBitMap_t::CompressTo8Bits(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::CompressTo8Bits(FloatBitMap_t *this, float overbright)
{
  float v3; // xmm2_4
  int i; // ecx
  int j; // eax
  unsigned int v6; // edx
  unsigned __int8 *v7; // edi
  float v8; // xmm0_4
  unsigned int v9; // edx
  unsigned __int8 *v10; // edi
  float v11; // xmm0_4
  unsigned int v12; // edx
  unsigned __int8 *v13; // edi
  float v14; // xmm0_4
  int k; // ebx
  int m; // edi
  float v17; // xmm1_4
  unsigned __int8 *v18; // edx
  unsigned int v19; // eax
  float v20; // xmm0_4
  float v21; // xmm4_4
  unsigned __int8 *v22; // edx
  unsigned int v23; // eax
  double v24; // xmm0_8
  float v25; // xmm0_4
  float v26; // xmm1_4
  int v27; // edx
  int m_nColumns; // ecx
  int v29; // eax
  unsigned int v30; // ecx
  FloatBitMap_t v31; // [esp+8h] [ebp-334h] BYREF
  double v32; // [esp+32Ch] [ebp-10h]
  double v33; // [esp+334h] [ebp-8h]

  FloatBitMap_t::FloatBitMap_t(
    this: &v31,
    nWidth: this->m_nColumns,
    nHeight: this->m_nRows,
    nDepth: 1,
    nAttributeMask: 15);
  v3 = overbright;
  for ( i = 0; i < this->m_nRows; ++i )
  {
    for ( j = 0; j < this->m_nColumns; *(float *)&v13[v12] = v14 )
    {
      v6 = i * this->m_nRowStrideInBytes[0] + j * this->m_nStrideInBytes[0];
      v7 = this->m_pAttributePtrs[0];
      v8 = *(float *)&v7[v6];
      if ( v8 > overbright )
        v8 = overbright;
      *(float *)&v7[v6] = v8;
      v9 = i * this->m_nRowStrideInBytes[1] + j * this->m_nStrideInBytes[1];
      v10 = this->m_pAttributePtrs[1];
      v11 = *(float *)&v10[v9];
      if ( v11 > overbright )
        v11 = overbright;
      *(float *)&v10[v9] = v11;
      v12 = i * this->m_nRowStrideInBytes[2] + j * this->m_nStrideInBytes[2];
      v13 = this->m_pAttributePtrs[2];
      v14 = *(float *)&v13[v12];
      if ( v14 > overbright )
        v14 = overbright;
      ++j;
    }
  }
  for ( k = 0; k < this->m_nRows; ++k )
  {
    for ( m = 0; m < this->m_nColumns; ++m )
    {
      v17 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      v18 = this->m_pAttributePtrs[1];
      v19 = k * this->m_nRowStrideInBytes[1] + m * this->m_nStrideInBytes[1];
      v20 = *(float *)&v18[v19];
      if ( v17 <= v20 )
        v21 = *(float *)&v18[v19];
      else
        v21 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      v22 = this->m_pAttributePtrs[2];
      v23 = k * this->m_nRowStrideInBytes[2] + m * this->m_nStrideInBytes[2];
      if ( v21 <= *(float *)&v22[v23] )
      {
        v20 = *(float *)&v22[v23];
      }
      else if ( v17 > v20 )
      {
        v20 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      }
      if ( v20 == 0.0 )
      {
        *(_DWORD *)&v31.m_pAttributePtrs[0][k * v31.m_nRowStrideInBytes[0] + m * v31.m_nStrideInBytes[0]] = 0;
        *(_DWORD *)&v31.m_pAttributePtrs[1][m * v31.m_nStrideInBytes[1] + k * v31.m_nRowStrideInBytes[1]] = 0;
        *(_DWORD *)&v31.m_pAttributePtrs[2][m * v31.m_nStrideInBytes[2] + k * v31.m_nRowStrideInBytes[2]] = 0;
        *(_DWORD *)&v31.m_pAttributePtrs[3][m * v31.m_nStrideInBytes[3] + k * v31.m_nRowStrideInBytes[3]] = 0;
      }
      else
      {
        v32 = (float)(1.0 / v3 * v20) * 255.0;
        if ( ceil(X: v32) <= 255.0 )
        {
          v33 = ceil(X: v32);
          v24 = v33;
        }
        else
        {
          v24 = 255.0;
        }
        v3 = overbright;
        v25 = (float)(int)v24;
        *(float *)&v31.m_pAttributePtrs[3][m * v31.m_nStrideInBytes[3] + k * v31.m_nRowStrideInBytes[3]] = v25;
        v26 = overbright * 0.00392156862745098 * (double)(int)v25;
        *(float *)&v31.m_pAttributePtrs[0][k * v31.m_nRowStrideInBytes[0] + m * v31.m_nStrideInBytes[0]] = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]] * (float)(1.0 / v26);
        *(float *)&v31.m_pAttributePtrs[1][m * v31.m_nStrideInBytes[1] + k * v31.m_nRowStrideInBytes[1]] = *(float *)&this->m_pAttributePtrs[1][k * this->m_nRowStrideInBytes[1] + m * this->m_nStrideInBytes[1]] * (float)(1.0 / v26);
        *(float *)&v31.m_pAttributePtrs[2][m * v31.m_nStrideInBytes[2] + k * v31.m_nRowStrideInBytes[2]] = *(float *)&this->m_pAttributePtrs[2][k * this->m_nRowStrideInBytes[2] + m * this->m_nStrideInBytes[2]] * (float)(1.0 / v26);
      }
    }
  }
  CSOAContainer::CopyAttrFrom(this, other: &v31, nDestAttributeIndex: 0, nSrcAttributeIndex: -1);
  CSOAContainer::CopyAttrFrom(this, other: &v31, nDestAttributeIndex: 1, nSrcAttributeIndex: -1);
  CSOAContainer::CopyAttrFrom(this, other: &v31, nDestAttributeIndex: 2, nSrcAttributeIndex: -1);
  CSOAContainer::CopyAttrFrom(this, other: &v31, nDestAttributeIndex: 3, nSrcAttributeIndex: -1);
  v27 = 0;
  if ( this->m_nRows > 0 )
  {
    m_nColumns = this->m_nColumns;
    do
    {
      v29 = 0;
      if ( m_nColumns > 0 )
      {
        do
        {
          v30 = v27 * this->m_nRowStrideInBytes[3] + v29 * this->m_nStrideInBytes[3];
          *(float *)&this->m_pAttributePtrs[3][v30] = *(float *)&this->m_pAttributePtrs[3][v30] * 0.00392156862745098;
          m_nColumns = this->m_nColumns;
          ++v29;
        }
        while ( v29 < this->m_nColumns );
      }
      ++v27;
    }
    while ( v27 < this->m_nRows );
  }
  CSOAContainer::~CSOAContainer(this: &v31);
}

} // namespace engine_xlsp

// ============================================================
// Overlay from height2normal (Missing functions)
// ============================================================
namespace height2normal {

//------------------------------------------------------------------------------
// Address: 0x0040A9C0
// Name: public: void FloatBitMap_t::CompressTo8Bits(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::CompressTo8Bits(FloatBitMap_t *this, float overbright)
{
  float v3; // xmm2_4
  int i; // ecx
  int j; // eax
  unsigned int v6; // edx
  unsigned __int8 *v7; // edi
  float v8; // xmm0_4
  unsigned int v9; // edx
  unsigned __int8 *v10; // edi
  float v11; // xmm0_4
  unsigned int v12; // edx
  unsigned __int8 *v13; // edi
  float v14; // xmm0_4
  int k; // ebx
  int m; // edi
  float v17; // xmm1_4
  unsigned __int8 *v18; // edx
  unsigned int v19; // eax
  float v20; // xmm0_4
  float v21; // xmm4_4
  unsigned __int8 *v22; // edx
  unsigned int v23; // eax
  double v24; // xmm0_8
  float v25; // xmm0_4
  float v26; // xmm1_4
  int v27; // edx
  int m_nColumns; // ecx
  int v29; // eax
  unsigned int v30; // ecx
  FloatBitMap_t TmpFBM; // [esp+14h] [ebp-334h] BYREF
  double X; // [esp+338h] [ebp-10h]
  double v33; // [esp+340h] [ebp-8h]

  FloatBitMap_t::FloatBitMap_t(
    this: &TmpFBM,
    nWidth: this->m_nColumns,
    nHeight: this->m_nRows,
    nDepth: 1,
    nAttributeMask: 15);
  v3 = overbright;
  for ( i = 0; i < this->m_nRows; ++i )
  {
    for ( j = 0; j < this->m_nColumns; *(float *)&v13[v12] = v14 )
    {
      v6 = i * this->m_nRowStrideInBytes[0] + j * this->m_nStrideInBytes[0];
      v7 = this->m_pAttributePtrs[0];
      v8 = *(float *)&v7[v6];
      if ( v8 > overbright )
        v8 = overbright;
      *(float *)&v7[v6] = v8;
      v9 = i * this->m_nRowStrideInBytes[1] + j * this->m_nStrideInBytes[1];
      v10 = this->m_pAttributePtrs[1];
      v11 = *(float *)&v10[v9];
      if ( v11 > overbright )
        v11 = overbright;
      *(float *)&v10[v9] = v11;
      v12 = i * this->m_nRowStrideInBytes[2] + j * this->m_nStrideInBytes[2];
      v13 = this->m_pAttributePtrs[2];
      v14 = *(float *)&v13[v12];
      if ( v14 > overbright )
        v14 = overbright;
      ++j;
    }
  }
  for ( k = 0; k < this->m_nRows; ++k )
  {
    for ( m = 0; m < this->m_nColumns; ++m )
    {
      v17 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      v18 = this->m_pAttributePtrs[1];
      v19 = k * this->m_nRowStrideInBytes[1] + m * this->m_nStrideInBytes[1];
      v20 = *(float *)&v18[v19];
      if ( v17 <= v20 )
        v21 = *(float *)&v18[v19];
      else
        v21 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      v22 = this->m_pAttributePtrs[2];
      v23 = k * this->m_nRowStrideInBytes[2] + m * this->m_nStrideInBytes[2];
      if ( v21 <= *(float *)&v22[v23] )
      {
        v20 = *(float *)&v22[v23];
      }
      else if ( v17 > v20 )
      {
        v20 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      }
      if ( v20 == 0.0 )
      {
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[0][k * TmpFBM.m_nRowStrideInBytes[0] + m * TmpFBM.m_nStrideInBytes[0]] = 0;
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[1][m * TmpFBM.m_nStrideInBytes[1] + k * TmpFBM.m_nRowStrideInBytes[1]] = 0;
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[2][m * TmpFBM.m_nStrideInBytes[2] + k * TmpFBM.m_nRowStrideInBytes[2]] = 0;
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[3][m * TmpFBM.m_nStrideInBytes[3] + k * TmpFBM.m_nRowStrideInBytes[3]] = 0;
      }
      else
      {
        X = (float)(1.0 / v3 * v20) * 255.0;
        if ( ceil(X) <= 255.0 )
        {
          v33 = ceil(X);
          v24 = v33;
        }
        else
        {
          v24 = 255.0;
        }
        v3 = overbright;
        v25 = (float)(int)v24;
        *(float *)&TmpFBM.m_pAttributePtrs[3][m * TmpFBM.m_nStrideInBytes[3] + k * TmpFBM.m_nRowStrideInBytes[3]] = v25;
        v26 = overbright * 0.00392156862745098 * (double)(int)v25;
        *(float *)&TmpFBM.m_pAttributePtrs[0][k * TmpFBM.m_nRowStrideInBytes[0] + m * TmpFBM.m_nStrideInBytes[0]] = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]] * (float)(1.0 / v26);
        *(float *)&TmpFBM.m_pAttributePtrs[1][m * TmpFBM.m_nStrideInBytes[1] + k * TmpFBM.m_nRowStrideInBytes[1]] = *(float *)&this->m_pAttributePtrs[1][k * this->m_nRowStrideInBytes[1] + m * this->m_nStrideInBytes[1]] * (float)(1.0 / v26);
        *(float *)&TmpFBM.m_pAttributePtrs[2][m * TmpFBM.m_nStrideInBytes[2] + k * TmpFBM.m_nRowStrideInBytes[2]] = *(float *)&this->m_pAttributePtrs[2][k * this->m_nRowStrideInBytes[2] + m * this->m_nStrideInBytes[2]] * (float)(1.0 / v26);
      }
    }
  }
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 0, nSrcAttributeIndex: -1);
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 1, nSrcAttributeIndex: -1);
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 2, nSrcAttributeIndex: -1);
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 3, nSrcAttributeIndex: -1);
  v27 = 0;
  if ( this->m_nRows > 0 )
  {
    m_nColumns = this->m_nColumns;
    do
    {
      v29 = 0;
      if ( m_nColumns > 0 )
      {
        do
        {
          v30 = v27 * this->m_nRowStrideInBytes[3] + v29 * this->m_nStrideInBytes[3];
          *(float *)&this->m_pAttributePtrs[3][v30] = *(float *)&this->m_pAttributePtrs[3][v30] * 0.00392156862745098;
          m_nColumns = this->m_nColumns;
          ++v29;
        }
        while ( v29 < this->m_nColumns );
      }
      ++v27;
    }
    while ( v27 < this->m_nRows );
  }
  CSOAContainer::~CSOAContainer(this: &TmpFBM);
}

} // namespace height2normal

// ============================================================
// Overlay from height2ssbump (Missing functions)
// ============================================================
namespace height2ssbump {

//------------------------------------------------------------------------------
// Address: 0x00411F30
// Name: public: void FloatBitMap_t::CompressTo8Bits(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::CompressTo8Bits(FloatBitMap_t *this, float overbright)
{
  float v3; // xmm2_4
  int i; // ecx
  int j; // eax
  unsigned int v6; // edx
  unsigned __int8 *v7; // edi
  float v8; // xmm0_4
  unsigned int v9; // edx
  unsigned __int8 *v10; // edi
  float v11; // xmm0_4
  unsigned int v12; // edx
  unsigned __int8 *v13; // edi
  float v14; // xmm0_4
  int k; // ebx
  int m; // edi
  float v17; // xmm1_4
  unsigned __int8 *v18; // edx
  unsigned int v19; // eax
  float v20; // xmm0_4
  float v21; // xmm4_4
  unsigned __int8 *v22; // edx
  unsigned int v23; // eax
  double v24; // xmm0_8
  float v25; // xmm0_4
  float v26; // xmm1_4
  int v27; // edx
  int m_nColumns; // ecx
  int v29; // eax
  unsigned int v30; // ecx
  FloatBitMap_t TmpFBM; // [esp+14h] [ebp-334h] BYREF
  double X; // [esp+338h] [ebp-10h]
  double v33; // [esp+340h] [ebp-8h]

  FloatBitMap_t::FloatBitMap_t(
    this: &TmpFBM,
    nWidth: this->m_nColumns,
    nHeight: this->m_nRows,
    nDepth: 1,
    nAttributeMask: 15);
  v3 = overbright;
  for ( i = 0; i < this->m_nRows; ++i )
  {
    for ( j = 0; j < this->m_nColumns; *(float *)&v13[v12] = v14 )
    {
      v6 = i * this->m_nRowStrideInBytes[0] + j * this->m_nStrideInBytes[0];
      v7 = this->m_pAttributePtrs[0];
      v8 = *(float *)&v7[v6];
      if ( v8 > overbright )
        v8 = overbright;
      *(float *)&v7[v6] = v8;
      v9 = i * this->m_nRowStrideInBytes[1] + j * this->m_nStrideInBytes[1];
      v10 = this->m_pAttributePtrs[1];
      v11 = *(float *)&v10[v9];
      if ( v11 > overbright )
        v11 = overbright;
      *(float *)&v10[v9] = v11;
      v12 = i * this->m_nRowStrideInBytes[2] + j * this->m_nStrideInBytes[2];
      v13 = this->m_pAttributePtrs[2];
      v14 = *(float *)&v13[v12];
      if ( v14 > overbright )
        v14 = overbright;
      ++j;
    }
  }
  for ( k = 0; k < this->m_nRows; ++k )
  {
    for ( m = 0; m < this->m_nColumns; ++m )
    {
      v17 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      v18 = this->m_pAttributePtrs[1];
      v19 = k * this->m_nRowStrideInBytes[1] + m * this->m_nStrideInBytes[1];
      v20 = *(float *)&v18[v19];
      if ( v17 <= v20 )
        v21 = *(float *)&v18[v19];
      else
        v21 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      v22 = this->m_pAttributePtrs[2];
      v23 = k * this->m_nRowStrideInBytes[2] + m * this->m_nStrideInBytes[2];
      if ( v21 <= *(float *)&v22[v23] )
      {
        v20 = *(float *)&v22[v23];
      }
      else if ( v17 > v20 )
      {
        v20 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      }
      if ( v20 == 0.0 )
      {
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[0][k * TmpFBM.m_nRowStrideInBytes[0] + m * TmpFBM.m_nStrideInBytes[0]] = 0;
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[1][m * TmpFBM.m_nStrideInBytes[1] + k * TmpFBM.m_nRowStrideInBytes[1]] = 0;
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[2][m * TmpFBM.m_nStrideInBytes[2] + k * TmpFBM.m_nRowStrideInBytes[2]] = 0;
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[3][m * TmpFBM.m_nStrideInBytes[3] + k * TmpFBM.m_nRowStrideInBytes[3]] = 0;
      }
      else
      {
        X = (float)(1.0 / v3 * v20) * 255.0;
        if ( ceil(X) <= 255.0 )
        {
          v33 = ceil(X);
          v24 = v33;
        }
        else
        {
          v24 = 255.0;
        }
        v3 = overbright;
        v25 = (float)(int)v24;
        *(float *)&TmpFBM.m_pAttributePtrs[3][m * TmpFBM.m_nStrideInBytes[3] + k * TmpFBM.m_nRowStrideInBytes[3]] = v25;
        v26 = overbright * 0.00392156862745098 * (double)(int)v25;
        *(float *)&TmpFBM.m_pAttributePtrs[0][k * TmpFBM.m_nRowStrideInBytes[0] + m * TmpFBM.m_nStrideInBytes[0]] = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]] * (float)(1.0 / v26);
        *(float *)&TmpFBM.m_pAttributePtrs[1][m * TmpFBM.m_nStrideInBytes[1] + k * TmpFBM.m_nRowStrideInBytes[1]] = *(float *)&this->m_pAttributePtrs[1][k * this->m_nRowStrideInBytes[1] + m * this->m_nStrideInBytes[1]] * (float)(1.0 / v26);
        *(float *)&TmpFBM.m_pAttributePtrs[2][m * TmpFBM.m_nStrideInBytes[2] + k * TmpFBM.m_nRowStrideInBytes[2]] = *(float *)&this->m_pAttributePtrs[2][k * this->m_nRowStrideInBytes[2] + m * this->m_nStrideInBytes[2]] * (float)(1.0 / v26);
      }
    }
  }
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 0, nSrcAttributeIndex: -1);
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 1, nSrcAttributeIndex: -1);
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 2, nSrcAttributeIndex: -1);
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 3, nSrcAttributeIndex: -1);
  v27 = 0;
  if ( this->m_nRows > 0 )
  {
    m_nColumns = this->m_nColumns;
    do
    {
      v29 = 0;
      if ( m_nColumns > 0 )
      {
        do
        {
          v30 = v27 * this->m_nRowStrideInBytes[3] + v29 * this->m_nStrideInBytes[3];
          *(float *)&this->m_pAttributePtrs[3][v30] = *(float *)&this->m_pAttributePtrs[3][v30] * 0.00392156862745098;
          m_nColumns = this->m_nColumns;
          ++v29;
        }
        while ( v29 < this->m_nColumns );
      }
      ++v27;
    }
    while ( v27 < this->m_nRows );
  }
  CSOAContainer::~CSOAContainer(this: &TmpFBM);
}

//------------------------------------------------------------------------------
// Address: 0x004123E0
// Name: bool SupportsSSE2(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
bool __cdecl SupportsSSE2()
{
  return IsProcessorFeaturePresent(ProcessorFeature: 0xAu);
}

//------------------------------------------------------------------------------
// Address: 0x00412720
// Name: unsigned long CalcBufferSize(enum _CodecType,unsigned long,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl CalcBufferSize(int a1, int a2, int a3)
{
  int v3; // eax
  unsigned int result; // eax

  switch ( a1 )
  {
    case 2:
    case 11:
      v3 = 1;
      goto LABEL_4;
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 12:
    case 13:
    case 14:
      v3 = 2;
LABEL_4:
      result = (4 * 4 * ((unsigned int)(a3 + 3) >> 2) * 4 * ((unsigned int)(a2 + 3) >> 2) * v3) >> 3;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00412790
// Name: unsigned char DeriveB(unsigned char,unsigned char)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 __cdecl DeriveB(unsigned __int8 a1, unsigned __int8 a2)
{
  double v2; // st6
  double v3; // st7
  float v5; // [esp+0h] [ebp-4h]
  float v6; // [esp+8h] [ebp+4h]
  float v7; // [esp+8h] [ebp+4h]
  float v8; // [esp+8h] [ebp+4h]
  float v9; // [esp+8h] [ebp+4h]
  float v10; // [esp+8h] [ebp+4h]
  float v11; // [esp+8h] [ebp+4h]
  float v12; // [esp+8h] [ebp+4h]
  float v13; // [esp+8h] [ebp+4h]
  float v14; // [esp+8h] [ebp+4h]
  float v15; // [esp+8h] [ebp+4h]

  v6 = (double)a1 / 255.0;
  v7 = v6 * 2.0;
  v5 = v7 - 1.0;
  v8 = (double)a2 / 255.0;
  v9 = 2.0 * v8;
  v10 = v9 - 1.0;
  v2 = v10 * v10 + v5 * v5;
  if ( v2 >= 1.0 )
    v2 = 1.0;
  v11 = v2;
  v12 = 1.0 - v11;
  v13 = sqrt(v12);
  v14 = v13 * 127.0;
  v15 = v14 + 128.0;
  if ( v15 < 255.0 )
  {
    v3 = 0.0;
    if ( v15 > 0.0 )
      return (int)v15;
  }
  else
  {
    v3 = 255.0;
  }
  return (int)(float)v3;
}

//------------------------------------------------------------------------------
// Address: 0x004128A0
// Name: float DeriveB(float,float)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl DeriveB(float a1, float a2)
{
  double v2; // st6
  float v4; // [esp+0h] [ebp-4h]
  float v5; // [esp+8h] [ebp+4h]
  float v6; // [esp+8h] [ebp+4h]
  float v7; // [esp+8h] [ebp+4h]
  float v8; // [esp+8h] [ebp+4h]
  float v9; // [esp+8h] [ebp+4h]
  float v10; // [esp+8h] [ebp+4h]
  float v11; // [esp+8h] [ebp+4h]

  v5 = a1 * 2.0;
  v4 = v5 - 1.0;
  v6 = 2.0 * a2;
  v7 = v6 - 1.0;
  v2 = v7 * v7 + v4 * v4;
  if ( v2 >= 1.0 )
    v2 = 1.0;
  v8 = v2;
  v9 = 1.0 - v8;
  v10 = sqrt(v9);
  v11 = v10 + 1.0;
  return (float)(v11 * 0.5);
}

//------------------------------------------------------------------------------
// Address: 0x00412970
// Name: public: half::half(float)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
half *__thiscall half::half(half *this, int a2)
{
  if ( *(float *)&a2 == 0.0 )
  {
    *(_WORD *)this = 0;
    return this;
  }
  else
  {
    if ( *((_WORD *)&half::_eLut + ((unsigned int)a2 >> 23)) != 0 )
      *(_WORD *)this = *((_WORD *)&half::_eLut + ((unsigned int)a2 >> 23)) + (((a2 & 0x7FFFFFu) + 4096) >> 13);
    else
      *(_WORD *)this = half::convert(a1: a2);
    return this;
  }
}

} // namespace height2ssbump

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x10179C40
// Name: public: void FloatBitMap_t::CompressTo8Bits(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::CompressTo8Bits(FloatBitMap_t *this, float overbright)
{
  float v3; // xmm2_4
  int i; // ecx
  int j; // eax
  unsigned int v6; // edx
  unsigned __int8 *v7; // edi
  float v8; // xmm0_4
  unsigned int v9; // edx
  unsigned __int8 *v10; // edi
  float v11; // xmm0_4
  unsigned int v12; // edx
  unsigned __int8 *v13; // edi
  float v14; // xmm0_4
  int k; // ebx
  int m; // edi
  float v17; // xmm1_4
  unsigned __int8 *v18; // edx
  unsigned int v19; // eax
  float v20; // xmm0_4
  float v21; // xmm4_4
  unsigned __int8 *v22; // edx
  unsigned int v23; // eax
  double v24; // xmm0_8
  float v25; // xmm0_4
  float v26; // xmm1_4
  int v27; // edx
  int m_nColumns; // ecx
  int v29; // eax
  unsigned int v30; // ecx
  FloatBitMap_t v31; // [esp+8h] [ebp-334h] BYREF
  double v32; // [esp+32Ch] [ebp-10h]
  double v33; // [esp+334h] [ebp-8h]

  FloatBitMap_t::FloatBitMap_t(
    this: &v31,
    nWidth: this->m_nColumns,
    nHeight: this->m_nRows,
    nDepth: 1,
    nAttributeMask: 15);
  v3 = overbright;
  for ( i = 0; i < this->m_nRows; ++i )
  {
    for ( j = 0; j < this->m_nColumns; *(float *)&v13[v12] = v14 )
    {
      v6 = i * this->m_nRowStrideInBytes[0] + j * this->m_nStrideInBytes[0];
      v7 = this->m_pAttributePtrs[0];
      v8 = *(float *)&v7[v6];
      if ( v8 > overbright )
        v8 = overbright;
      *(float *)&v7[v6] = v8;
      v9 = i * this->m_nRowStrideInBytes[1] + j * this->m_nStrideInBytes[1];
      v10 = this->m_pAttributePtrs[1];
      v11 = *(float *)&v10[v9];
      if ( v11 > overbright )
        v11 = overbright;
      *(float *)&v10[v9] = v11;
      v12 = i * this->m_nRowStrideInBytes[2] + j * this->m_nStrideInBytes[2];
      v13 = this->m_pAttributePtrs[2];
      v14 = *(float *)&v13[v12];
      if ( v14 > overbright )
        v14 = overbright;
      ++j;
    }
  }
  for ( k = 0; k < this->m_nRows; ++k )
  {
    for ( m = 0; m < this->m_nColumns; ++m )
    {
      v17 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      v18 = this->m_pAttributePtrs[1];
      v19 = k * this->m_nRowStrideInBytes[1] + m * this->m_nStrideInBytes[1];
      v20 = *(float *)&v18[v19];
      if ( v17 <= v20 )
        v21 = *(float *)&v18[v19];
      else
        v21 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      v22 = this->m_pAttributePtrs[2];
      v23 = k * this->m_nRowStrideInBytes[2] + m * this->m_nStrideInBytes[2];
      if ( v21 <= *(float *)&v22[v23] )
      {
        v20 = *(float *)&v22[v23];
      }
      else if ( v17 > v20 )
      {
        v20 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      }
      if ( v20 == 0.0 )
      {
        *(_DWORD *)&v31.m_pAttributePtrs[0][k * v31.m_nRowStrideInBytes[0] + m * v31.m_nStrideInBytes[0]] = 0;
        *(_DWORD *)&v31.m_pAttributePtrs[1][m * v31.m_nStrideInBytes[1] + k * v31.m_nRowStrideInBytes[1]] = 0;
        *(_DWORD *)&v31.m_pAttributePtrs[2][m * v31.m_nStrideInBytes[2] + k * v31.m_nRowStrideInBytes[2]] = 0;
        *(_DWORD *)&v31.m_pAttributePtrs[3][m * v31.m_nStrideInBytes[3] + k * v31.m_nRowStrideInBytes[3]] = 0;
      }
      else
      {
        v32 = (float)(1.0 / v3 * v20) * 255.0;
        if ( ceil(X: v32) <= 255.0 )
        {
          v33 = ceil(X: v32);
          v24 = v33;
        }
        else
        {
          v24 = 255.0;
        }
        v3 = overbright;
        v25 = (float)(int)v24;
        *(float *)&v31.m_pAttributePtrs[3][m * v31.m_nStrideInBytes[3] + k * v31.m_nRowStrideInBytes[3]] = v25;
        v26 = overbright * 0.00392156862745098 * (double)(int)v25;
        *(float *)&v31.m_pAttributePtrs[0][k * v31.m_nRowStrideInBytes[0] + m * v31.m_nStrideInBytes[0]] = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]] * (float)(1.0 / v26);
        *(float *)&v31.m_pAttributePtrs[1][m * v31.m_nStrideInBytes[1] + k * v31.m_nRowStrideInBytes[1]] = *(float *)&this->m_pAttributePtrs[1][k * this->m_nRowStrideInBytes[1] + m * this->m_nStrideInBytes[1]] * (float)(1.0 / v26);
        *(float *)&v31.m_pAttributePtrs[2][m * v31.m_nStrideInBytes[2] + k * v31.m_nRowStrideInBytes[2]] = *(float *)&this->m_pAttributePtrs[2][k * this->m_nRowStrideInBytes[2] + m * this->m_nStrideInBytes[2]] * (float)(1.0 / v26);
      }
    }
  }
  CSOAContainer::CopyAttrFrom(this, other: &v31, nDestAttributeIndex: 0, nSrcAttributeIndex: -1);
  CSOAContainer::CopyAttrFrom(this, other: &v31, nDestAttributeIndex: 1, nSrcAttributeIndex: -1);
  CSOAContainer::CopyAttrFrom(this, other: &v31, nDestAttributeIndex: 2, nSrcAttributeIndex: -1);
  CSOAContainer::CopyAttrFrom(this, other: &v31, nDestAttributeIndex: 3, nSrcAttributeIndex: -1);
  v27 = 0;
  if ( this->m_nRows > 0 )
  {
    m_nColumns = this->m_nColumns;
    do
    {
      v29 = 0;
      if ( m_nColumns > 0 )
      {
        do
        {
          v30 = v27 * this->m_nRowStrideInBytes[3] + v29 * this->m_nStrideInBytes[3];
          *(float *)&this->m_pAttributePtrs[3][v30] = *(float *)&this->m_pAttributePtrs[3][v30] * 0.00392156862745098;
          m_nColumns = this->m_nColumns;
          ++v29;
        }
        while ( v29 < this->m_nColumns );
      }
      ++v27;
    }
    while ( v27 < this->m_nRows );
  }
  CSOAContainer::~CSOAContainer(this: &v31);
}

//------------------------------------------------------------------------------
// Address: 0x1017A0F0
// Name: bool SupportsSSE2(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
bool __cdecl SupportsSSE2()
{
  return IsProcessorFeaturePresent(ProcessorFeature: 0xAu);
}

//------------------------------------------------------------------------------
// Address: 0x1017A430
// Name: unsigned long CalcBufferSize(enum _CodecType,unsigned long,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl CalcBufferSize(int a1, int a2, int a3)
{
  int v3; // eax
  unsigned int result; // eax

  switch ( a1 )
  {
    case 2:
    case 11:
      v3 = 1;
      goto LABEL_4;
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 12:
    case 13:
    case 14:
      v3 = 2;
LABEL_4:
      result = (4 * 4 * ((unsigned int)(a3 + 3) >> 2) * 4 * ((unsigned int)(a2 + 3) >> 2) * v3) >> 3;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017A4A0
// Name: unsigned char DeriveB(unsigned char,unsigned char)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 __cdecl DeriveB(unsigned __int8 a1, unsigned __int8 a2)
{
  double v2; // st6
  double v3; // st7
  float v5; // [esp-4h] [ebp-4h]
  float v6; // [esp+4h] [ebp+4h]
  float v7; // [esp+4h] [ebp+4h]
  float v8; // [esp+4h] [ebp+4h]
  float v9; // [esp+4h] [ebp+4h]
  float v10; // [esp+4h] [ebp+4h]
  float v11; // [esp+4h] [ebp+4h]
  float v12; // [esp+4h] [ebp+4h]
  float v13; // [esp+4h] [ebp+4h]
  float v14; // [esp+4h] [ebp+4h]
  float v15; // [esp+4h] [ebp+4h]

  v6 = (double)a1 / 255.0;
  v7 = v6 * 2.0;
  v5 = v7 - 1.0;
  v8 = (double)a2 / 255.0;
  v9 = 2.0 * v8;
  v10 = v9 - 1.0;
  v2 = v10 * v10 + v5 * v5;
  if ( v2 >= 1.0 )
    v2 = 1.0;
  v11 = v2;
  v12 = 1.0 - v11;
  v13 = sqrt(v12);
  v14 = v13 * 127.0;
  v15 = v14 + 128.0;
  if ( v15 < 255.0 )
  {
    v3 = 0.0;
    if ( v15 > 0.0 )
      return (int)v15;
  }
  else
  {
    v3 = 255.0;
  }
  return (int)(float)v3;
}

//------------------------------------------------------------------------------
// Address: 0x1017A5B0
// Name: float DeriveB(float,float)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl DeriveB(float a1, float a2)
{
  double v2; // st6
  float v4; // [esp-4h] [ebp-4h]
  float v5; // [esp+4h] [ebp+4h]
  float v6; // [esp+4h] [ebp+4h]
  float v7; // [esp+4h] [ebp+4h]
  float v8; // [esp+4h] [ebp+4h]
  float v9; // [esp+4h] [ebp+4h]
  float v10; // [esp+4h] [ebp+4h]
  float v11; // [esp+4h] [ebp+4h]

  v5 = a1 * 2.0;
  v4 = v5 - 1.0;
  v6 = 2.0 * a2;
  v7 = v6 - 1.0;
  v2 = v7 * v7 + v4 * v4;
  if ( v2 >= 1.0 )
    v2 = 1.0;
  v8 = v2;
  v9 = 1.0 - v8;
  v10 = sqrt(v9);
  v11 = v10 + 1.0;
  return (float)(v11 * 0.5);
}

//------------------------------------------------------------------------------
// Address: 0x1017A660
// Name: public: half::half(float)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
half *__thiscall half::half(half *this, int a2)
{
  if ( *(float *)&a2 == 0.0 )
  {
    *(_WORD *)this = 0;
    return this;
  }
  else
  {
    if ( *((_WORD *)&half::_eLut + ((unsigned int)a2 >> 23)) != 0 )
      *(_WORD *)this = *((_WORD *)&half::_eLut + ((unsigned int)a2 >> 23)) + (((a2 & 0x7FFFFFu) + 4096) >> 13);
    else
      *(_WORD *)this = half::convert(a1: a2);
    return this;
  }
}

} // namespace hammer_dll

// ============================================================
// Overlay from makegamedata (Missing functions)
// ============================================================
namespace makegamedata {

//------------------------------------------------------------------------------
// Address: 0x00567A50
// Name: public: void FloatBitMap_t::CompressTo8Bits(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::CompressTo8Bits(FloatBitMap_t *this, float overbright)
{
  float v3; // xmm2_4
  int i; // ecx
  int j; // eax
  unsigned int v6; // edx
  unsigned __int8 *v7; // edi
  float v8; // xmm0_4
  unsigned int v9; // edx
  unsigned __int8 *v10; // edi
  float v11; // xmm0_4
  unsigned int v12; // edx
  unsigned __int8 *v13; // edi
  float v14; // xmm0_4
  int k; // ebx
  int m; // edi
  float v17; // xmm1_4
  unsigned __int8 *v18; // edx
  unsigned int v19; // eax
  float v20; // xmm0_4
  float v21; // xmm4_4
  unsigned __int8 *v22; // edx
  unsigned int v23; // eax
  double v24; // xmm0_8
  float v25; // xmm0_4
  float v26; // xmm1_4
  int v27; // edx
  int m_nColumns; // ecx
  int v29; // eax
  unsigned int v30; // ecx
  FloatBitMap_t TmpFBM; // [esp+14h] [ebp-334h] BYREF
  double X; // [esp+338h] [ebp-10h]
  double v33; // [esp+340h] [ebp-8h]

  FloatBitMap_t::FloatBitMap_t(
    this: &TmpFBM,
    nWidth: this->m_nColumns,
    nHeight: this->m_nRows,
    nDepth: 1,
    nAttributeMask: 15);
  v3 = overbright;
  for ( i = 0; i < this->m_nRows; ++i )
  {
    for ( j = 0; j < this->m_nColumns; *(float *)&v13[v12] = v14 )
    {
      v6 = i * this->m_nRowStrideInBytes[0] + j * this->m_nStrideInBytes[0];
      v7 = this->m_pAttributePtrs[0];
      v8 = *(float *)&v7[v6];
      if ( v8 > overbright )
        v8 = overbright;
      *(float *)&v7[v6] = v8;
      v9 = i * this->m_nRowStrideInBytes[1] + j * this->m_nStrideInBytes[1];
      v10 = this->m_pAttributePtrs[1];
      v11 = *(float *)&v10[v9];
      if ( v11 > overbright )
        v11 = overbright;
      *(float *)&v10[v9] = v11;
      v12 = i * this->m_nRowStrideInBytes[2] + j * this->m_nStrideInBytes[2];
      v13 = this->m_pAttributePtrs[2];
      v14 = *(float *)&v13[v12];
      if ( v14 > overbright )
        v14 = overbright;
      ++j;
    }
  }
  for ( k = 0; k < this->m_nRows; ++k )
  {
    for ( m = 0; m < this->m_nColumns; ++m )
    {
      v17 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      v18 = this->m_pAttributePtrs[1];
      v19 = k * this->m_nRowStrideInBytes[1] + m * this->m_nStrideInBytes[1];
      v20 = *(float *)&v18[v19];
      if ( v17 <= v20 )
        v21 = *(float *)&v18[v19];
      else
        v21 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      v22 = this->m_pAttributePtrs[2];
      v23 = k * this->m_nRowStrideInBytes[2] + m * this->m_nStrideInBytes[2];
      if ( v21 <= *(float *)&v22[v23] )
      {
        v20 = *(float *)&v22[v23];
      }
      else if ( v17 > v20 )
      {
        v20 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      }
      if ( v20 == 0.0 )
      {
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[0][k * TmpFBM.m_nRowStrideInBytes[0] + m * TmpFBM.m_nStrideInBytes[0]] = 0;
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[1][m * TmpFBM.m_nStrideInBytes[1] + k * TmpFBM.m_nRowStrideInBytes[1]] = 0;
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[2][m * TmpFBM.m_nStrideInBytes[2] + k * TmpFBM.m_nRowStrideInBytes[2]] = 0;
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[3][m * TmpFBM.m_nStrideInBytes[3] + k * TmpFBM.m_nRowStrideInBytes[3]] = 0;
      }
      else
      {
        X = (float)(1.0 / v3 * v20) * 255.0;
        if ( ceil(X) <= 255.0 )
        {
          v33 = ceil(X);
          v24 = v33;
        }
        else
        {
          v24 = 255.0;
        }
        v3 = overbright;
        v25 = (float)(int)v24;
        *(float *)&TmpFBM.m_pAttributePtrs[3][m * TmpFBM.m_nStrideInBytes[3] + k * TmpFBM.m_nRowStrideInBytes[3]] = v25;
        v26 = overbright * 0.00392156862745098 * (double)(int)v25;
        *(float *)&TmpFBM.m_pAttributePtrs[0][k * TmpFBM.m_nRowStrideInBytes[0] + m * TmpFBM.m_nStrideInBytes[0]] = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]] * (float)(1.0 / v26);
        *(float *)&TmpFBM.m_pAttributePtrs[1][m * TmpFBM.m_nStrideInBytes[1] + k * TmpFBM.m_nRowStrideInBytes[1]] = *(float *)&this->m_pAttributePtrs[1][k * this->m_nRowStrideInBytes[1] + m * this->m_nStrideInBytes[1]] * (float)(1.0 / v26);
        *(float *)&TmpFBM.m_pAttributePtrs[2][m * TmpFBM.m_nStrideInBytes[2] + k * TmpFBM.m_nRowStrideInBytes[2]] = *(float *)&this->m_pAttributePtrs[2][k * this->m_nRowStrideInBytes[2] + m * this->m_nStrideInBytes[2]] * (float)(1.0 / v26);
      }
    }
  }
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 0, nSrcAttributeIndex: -1);
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 1, nSrcAttributeIndex: -1);
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 2, nSrcAttributeIndex: -1);
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 3, nSrcAttributeIndex: -1);
  v27 = 0;
  if ( this->m_nRows > 0 )
  {
    m_nColumns = this->m_nColumns;
    do
    {
      v29 = 0;
      if ( m_nColumns > 0 )
      {
        do
        {
          v30 = v27 * this->m_nRowStrideInBytes[3] + v29 * this->m_nStrideInBytes[3];
          *(float *)&this->m_pAttributePtrs[3][v30] = *(float *)&this->m_pAttributePtrs[3][v30] * 0.00392156862745098;
          m_nColumns = this->m_nColumns;
          ++v29;
        }
        while ( v29 < this->m_nColumns );
      }
      ++v27;
    }
    while ( v27 < this->m_nRows );
  }
  CSOAContainer::~CSOAContainer(this: &TmpFBM);
}

//------------------------------------------------------------------------------
// Address: 0x00567F00
// Name: bool SupportsSSE2(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
bool __cdecl SupportsSSE2()
{
  return IsProcessorFeaturePresent(ProcessorFeature: 0xAu);
}

//------------------------------------------------------------------------------
// Address: 0x00568240
// Name: unsigned long CalcBufferSize(enum _CodecType,unsigned long,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl CalcBufferSize(int a1, int a2, int a3)
{
  int v3; // eax
  unsigned int result; // eax

  switch ( a1 )
  {
    case 2:
    case 11:
      v3 = 1;
      goto LABEL_4;
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 12:
    case 13:
    case 14:
      v3 = 2;
LABEL_4:
      result = (4 * 4 * ((unsigned int)(a3 + 3) >> 2) * 4 * ((unsigned int)(a2 + 3) >> 2) * v3) >> 3;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005682B0
// Name: unsigned char DeriveB(unsigned char,unsigned char)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 __cdecl DeriveB(unsigned __int8 a1, unsigned __int8 a2)
{
  double v2; // st6
  double v3; // st7
  float v5; // [esp+0h] [ebp-4h]
  float v6; // [esp+8h] [ebp+4h]
  float v7; // [esp+8h] [ebp+4h]
  float v8; // [esp+8h] [ebp+4h]
  float v9; // [esp+8h] [ebp+4h]
  float v10; // [esp+8h] [ebp+4h]
  float v11; // [esp+8h] [ebp+4h]
  float v12; // [esp+8h] [ebp+4h]
  float v13; // [esp+8h] [ebp+4h]
  float v14; // [esp+8h] [ebp+4h]
  float v15; // [esp+8h] [ebp+4h]

  v6 = (double)a1 / 255.0;
  v7 = v6 * 2.0;
  v5 = v7 - 1.0;
  v8 = (double)a2 / 255.0;
  v9 = 2.0 * v8;
  v10 = v9 - 1.0;
  v2 = v10 * v10 + v5 * v5;
  if ( v2 >= 1.0 )
    v2 = 1.0;
  v11 = v2;
  v12 = 1.0 - v11;
  v13 = sqrt(v12);
  v14 = v13 * 127.0;
  v15 = v14 + 128.0;
  if ( v15 < 255.0 )
  {
    v3 = 0.0;
    if ( v15 > 0.0 )
      return (int)v15;
  }
  else
  {
    v3 = 255.0;
  }
  return (int)(float)v3;
}

//------------------------------------------------------------------------------
// Address: 0x005683C0
// Name: float DeriveB(float,float)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl DeriveB(float a1, float a2)
{
  double v2; // st6
  float v4; // [esp+0h] [ebp-4h]
  float v5; // [esp+8h] [ebp+4h]
  float v6; // [esp+8h] [ebp+4h]
  float v7; // [esp+8h] [ebp+4h]
  float v8; // [esp+8h] [ebp+4h]
  float v9; // [esp+8h] [ebp+4h]
  float v10; // [esp+8h] [ebp+4h]
  float v11; // [esp+8h] [ebp+4h]

  v5 = a1 * 2.0;
  v4 = v5 - 1.0;
  v6 = 2.0 * a2;
  v7 = v6 - 1.0;
  v2 = v7 * v7 + v4 * v4;
  if ( v2 >= 1.0 )
    v2 = 1.0;
  v8 = v2;
  v9 = 1.0 - v8;
  v10 = sqrt(v9);
  v11 = v10 + 1.0;
  return (float)(v11 * 0.5);
}

} // namespace makegamedata

// ============================================================
// Overlay from mksheet (Missing functions)
// ============================================================
namespace mksheet {

//------------------------------------------------------------------------------
// Address: 0x004756C0
// Name: public: void FloatBitMap_t::CompressTo8Bits(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::CompressTo8Bits(FloatBitMap_t *this, float overbright)
{
  float v3; // xmm2_4
  int i; // ecx
  int j; // eax
  unsigned int v6; // edx
  unsigned __int8 *v7; // edi
  float v8; // xmm0_4
  unsigned int v9; // edx
  unsigned __int8 *v10; // edi
  float v11; // xmm0_4
  unsigned int v12; // edx
  unsigned __int8 *v13; // edi
  float v14; // xmm0_4
  int k; // ebx
  int m; // edi
  float v17; // xmm1_4
  unsigned __int8 *v18; // edx
  unsigned int v19; // eax
  float v20; // xmm0_4
  float v21; // xmm4_4
  unsigned __int8 *v22; // edx
  unsigned int v23; // eax
  double v24; // xmm0_8
  float v25; // xmm0_4
  float v26; // xmm1_4
  int v27; // edx
  int m_nColumns; // ecx
  int v29; // eax
  unsigned int v30; // ecx
  FloatBitMap_t TmpFBM; // [esp+14h] [ebp-334h] BYREF
  double X; // [esp+338h] [ebp-10h]
  double v33; // [esp+340h] [ebp-8h]
  int savedregs; // [esp+348h] [ebp+0h] BYREF

  FloatBitMap_t::FloatBitMap_t(
    this: &TmpFBM,
    nWidth: this->m_nColumns,
    nHeight: this->m_nRows,
    nDepth: 1,
    nAttributeMask: 15);
  v3 = overbright;
  for ( i = 0; i < this->m_nRows; ++i )
  {
    for ( j = 0; j < this->m_nColumns; *(float *)&v13[v12] = v14 )
    {
      v6 = i * this->m_nRowStrideInBytes[0] + j * this->m_nStrideInBytes[0];
      v7 = this->m_pAttributePtrs[0];
      v8 = *(float *)&v7[v6];
      if ( v8 > overbright )
        v8 = overbright;
      *(float *)&v7[v6] = v8;
      v9 = i * this->m_nRowStrideInBytes[1] + j * this->m_nStrideInBytes[1];
      v10 = this->m_pAttributePtrs[1];
      v11 = *(float *)&v10[v9];
      if ( v11 > overbright )
        v11 = overbright;
      *(float *)&v10[v9] = v11;
      v12 = i * this->m_nRowStrideInBytes[2] + j * this->m_nStrideInBytes[2];
      v13 = this->m_pAttributePtrs[2];
      v14 = *(float *)&v13[v12];
      if ( v14 > overbright )
        v14 = overbright;
      ++j;
    }
  }
  for ( k = 0; k < this->m_nRows; ++k )
  {
    for ( m = 0; m < this->m_nColumns; ++m )
    {
      v17 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      v18 = this->m_pAttributePtrs[1];
      v19 = k * this->m_nRowStrideInBytes[1] + m * this->m_nStrideInBytes[1];
      v20 = *(float *)&v18[v19];
      if ( v17 <= v20 )
        v21 = *(float *)&v18[v19];
      else
        v21 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      v22 = this->m_pAttributePtrs[2];
      v23 = k * this->m_nRowStrideInBytes[2] + m * this->m_nStrideInBytes[2];
      if ( v21 <= *(float *)&v22[v23] )
      {
        v20 = *(float *)&v22[v23];
      }
      else if ( v17 > v20 )
      {
        v20 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      }
      if ( v20 == 0.0 )
      {
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[0][k * TmpFBM.m_nRowStrideInBytes[0] + m * TmpFBM.m_nStrideInBytes[0]] = 0;
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[1][m * TmpFBM.m_nStrideInBytes[1] + k * TmpFBM.m_nRowStrideInBytes[1]] = 0;
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[2][m * TmpFBM.m_nStrideInBytes[2] + k * TmpFBM.m_nRowStrideInBytes[2]] = 0;
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[3][m * TmpFBM.m_nStrideInBytes[3] + k * TmpFBM.m_nRowStrideInBytes[3]] = 0;
      }
      else
      {
        X = (float)(1.0 / v3 * v20) * 255.0;
        if ( ceil(X) <= 255.0 )
        {
          v33 = ceil(X);
          v24 = v33;
        }
        else
        {
          v24 = 255.0;
        }
        v3 = overbright;
        v25 = (float)(int)v24;
        *(float *)&TmpFBM.m_pAttributePtrs[3][m * TmpFBM.m_nStrideInBytes[3] + k * TmpFBM.m_nRowStrideInBytes[3]] = v25;
        v26 = overbright * 0.00392156862745098 * (double)(int)v25;
        *(float *)&TmpFBM.m_pAttributePtrs[0][k * TmpFBM.m_nRowStrideInBytes[0] + m * TmpFBM.m_nStrideInBytes[0]] = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]] * (float)(1.0 / v26);
        *(float *)&TmpFBM.m_pAttributePtrs[1][m * TmpFBM.m_nStrideInBytes[1] + k * TmpFBM.m_nRowStrideInBytes[1]] = *(float *)&this->m_pAttributePtrs[1][k * this->m_nRowStrideInBytes[1] + m * this->m_nStrideInBytes[1]] * (float)(1.0 / v26);
        *(float *)&TmpFBM.m_pAttributePtrs[2][m * TmpFBM.m_nStrideInBytes[2] + k * TmpFBM.m_nRowStrideInBytes[2]] = *(float *)&this->m_pAttributePtrs[2][k * this->m_nRowStrideInBytes[2] + m * this->m_nStrideInBytes[2]] * (float)(1.0 / v26);
      }
    }
  }
  CSOAContainer::CopyAttrFrom(
    this,
    a2: (unsigned int)&savedregs,
    other: (CFunctor_vtbl *)&TmpFBM,
    nDestAttributeIndex: 0,
    nSrcAttributeIndex: (CFunctor_vtbl *)0xFFFFFFFF);
  CSOAContainer::CopyAttrFrom(
    this,
    a2: (unsigned int)&savedregs,
    other: (CFunctor_vtbl *)&TmpFBM,
    nDestAttributeIndex: 1u,
    nSrcAttributeIndex: (CFunctor_vtbl *)0xFFFFFFFF);
  CSOAContainer::CopyAttrFrom(
    this,
    a2: (unsigned int)&savedregs,
    other: (CFunctor_vtbl *)&TmpFBM,
    nDestAttributeIndex: 2u,
    nSrcAttributeIndex: (CFunctor_vtbl *)0xFFFFFFFF);
  CSOAContainer::CopyAttrFrom(
    this,
    a2: (unsigned int)&savedregs,
    other: (CFunctor_vtbl *)&TmpFBM,
    nDestAttributeIndex: 3u,
    nSrcAttributeIndex: (CFunctor_vtbl *)0xFFFFFFFF);
  v27 = 0;
  if ( this->m_nRows > 0 )
  {
    m_nColumns = this->m_nColumns;
    do
    {
      v29 = 0;
      if ( m_nColumns > 0 )
      {
        do
        {
          v30 = v27 * this->m_nRowStrideInBytes[3] + v29 * this->m_nStrideInBytes[3];
          *(float *)&this->m_pAttributePtrs[3][v30] = *(float *)&this->m_pAttributePtrs[3][v30] * 0.00392156862745098;
          m_nColumns = this->m_nColumns;
          ++v29;
        }
        while ( v29 < this->m_nColumns );
      }
      ++v27;
    }
    while ( v27 < this->m_nRows );
  }
  CSOAContainer::~CSOAContainer(this: &TmpFBM);
}

//------------------------------------------------------------------------------
// Address: 0x00475B70
// Name: bool SupportsSSE2(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
bool __cdecl SupportsSSE2()
{
  return IsProcessorFeaturePresent(ProcessorFeature: 0xAu);
}

//------------------------------------------------------------------------------
// Address: 0x00475EB0
// Name: unsigned long CalcBufferSize(enum _CodecType,unsigned long,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl CalcBufferSize(int a1, int a2, int a3)
{
  int v3; // eax
  unsigned int result; // eax

  switch ( a1 )
  {
    case 2:
    case 11:
      v3 = 1;
      goto LABEL_4;
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 12:
    case 13:
    case 14:
      v3 = 2;
LABEL_4:
      result = (4 * 4 * ((unsigned int)(a3 + 3) >> 2) * 4 * ((unsigned int)(a2 + 3) >> 2) * v3) >> 3;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00475F20
// Name: unsigned char DeriveB(unsigned char,unsigned char)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 __cdecl DeriveB(unsigned __int8 a1, unsigned __int8 a2)
{
  double v2; // st6
  double v3; // st7
  float v5; // [esp+0h] [ebp-4h]
  float v6; // [esp+8h] [ebp+4h]
  float v7; // [esp+8h] [ebp+4h]
  float v8; // [esp+8h] [ebp+4h]
  float v9; // [esp+8h] [ebp+4h]
  float v10; // [esp+8h] [ebp+4h]
  float v11; // [esp+8h] [ebp+4h]
  float v12; // [esp+8h] [ebp+4h]
  float v13; // [esp+8h] [ebp+4h]
  float v14; // [esp+8h] [ebp+4h]
  float v15; // [esp+8h] [ebp+4h]

  v6 = (double)a1 / 255.0;
  v7 = v6 * 2.0;
  v5 = v7 - 1.0;
  v8 = (double)a2 / 255.0;
  v9 = 2.0 * v8;
  v10 = v9 - 1.0;
  v2 = v10 * v10 + v5 * v5;
  if ( v2 >= 1.0 )
    v2 = 1.0;
  v11 = v2;
  v12 = 1.0 - v11;
  v13 = sqrt(v12);
  v14 = v13 * 127.0;
  v15 = v14 + 128.0;
  if ( v15 < 255.0 )
  {
    v3 = 0.0;
    if ( v15 > 0.0 )
      return (int)v15;
  }
  else
  {
    v3 = 255.0;
  }
  return (int)(float)v3;
}

//------------------------------------------------------------------------------
// Address: 0x00476030
// Name: float DeriveB(float,float)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl DeriveB(float a1, float a2)
{
  double v2; // st6
  float v4; // [esp+0h] [ebp-4h]
  float v5; // [esp+8h] [ebp+4h]
  float v6; // [esp+8h] [ebp+4h]
  float v7; // [esp+8h] [ebp+4h]
  float v8; // [esp+8h] [ebp+4h]
  float v9; // [esp+8h] [ebp+4h]
  float v10; // [esp+8h] [ebp+4h]
  float v11; // [esp+8h] [ebp+4h]

  v5 = a1 * 2.0;
  v4 = v5 - 1.0;
  v6 = 2.0 * a2;
  v7 = v6 - 1.0;
  v2 = v7 * v7 + v4 * v4;
  if ( v2 >= 1.0 )
    v2 = 1.0;
  v8 = v2;
  v9 = 1.0 - v8;
  v10 = sqrt(v9);
  v11 = v10 + 1.0;
  return (float)(v11 * 0.5);
}

//------------------------------------------------------------------------------
// Address: 0x004760E0
// Name: public: half::half(float)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
half *__thiscall half::half(half *this, int a2)
{
  if ( *(float *)&a2 == 0.0 )
  {
    *(_WORD *)this = 0;
    return this;
  }
  else
  {
    if ( *((_WORD *)&half::_eLut + ((unsigned int)a2 >> 23)) != 0 )
      *(_WORD *)this = *((_WORD *)&half::_eLut + ((unsigned int)a2 >> 23)) + (((a2 & 0x7FFFFFu) + 4096) >> 13);
    else
      *(_WORD *)this = half::convert(a1: a2);
    return this;
  }
}

} // namespace mksheet

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x004EFD20
// Name: public: void FloatBitMap_t::CompressTo8Bits(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::CompressTo8Bits(FloatBitMap_t *this, float overbright)
{
  float v3; // xmm2_4
  int i; // ecx
  int j; // eax
  unsigned int v6; // edx
  unsigned __int8 *v7; // edi
  float v8; // xmm0_4
  unsigned int v9; // edx
  unsigned __int8 *v10; // edi
  float v11; // xmm0_4
  unsigned int v12; // edx
  unsigned __int8 *v13; // edi
  float v14; // xmm0_4
  int k; // ebx
  int m; // edi
  float v17; // xmm1_4
  unsigned __int8 *v18; // edx
  unsigned int v19; // eax
  float v20; // xmm0_4
  float v21; // xmm4_4
  unsigned __int8 *v22; // edx
  unsigned int v23; // eax
  double v24; // xmm0_8
  float v25; // xmm0_4
  float v26; // xmm1_4
  int v27; // edx
  int m_nColumns; // ecx
  int v29; // eax
  unsigned int v30; // ecx
  FloatBitMap_t TmpFBM; // [esp+14h] [ebp-334h] BYREF
  double X; // [esp+338h] [ebp-10h]
  double v33; // [esp+340h] [ebp-8h]

  FloatBitMap_t::FloatBitMap_t(
    this: &TmpFBM,
    nWidth: this->m_nColumns,
    nHeight: this->m_nRows,
    nDepth: 1,
    nAttributeMask: 15);
  v3 = overbright;
  for ( i = 0; i < this->m_nRows; ++i )
  {
    for ( j = 0; j < this->m_nColumns; *(float *)&v13[v12] = v14 )
    {
      v6 = i * this->m_nRowStrideInBytes[0] + j * this->m_nStrideInBytes[0];
      v7 = this->m_pAttributePtrs[0];
      v8 = *(float *)&v7[v6];
      if ( v8 > overbright )
        v8 = overbright;
      *(float *)&v7[v6] = v8;
      v9 = i * this->m_nRowStrideInBytes[1] + j * this->m_nStrideInBytes[1];
      v10 = this->m_pAttributePtrs[1];
      v11 = *(float *)&v10[v9];
      if ( v11 > overbright )
        v11 = overbright;
      *(float *)&v10[v9] = v11;
      v12 = i * this->m_nRowStrideInBytes[2] + j * this->m_nStrideInBytes[2];
      v13 = this->m_pAttributePtrs[2];
      v14 = *(float *)&v13[v12];
      if ( v14 > overbright )
        v14 = overbright;
      ++j;
    }
  }
  for ( k = 0; k < this->m_nRows; ++k )
  {
    for ( m = 0; m < this->m_nColumns; ++m )
    {
      v17 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      v18 = this->m_pAttributePtrs[1];
      v19 = k * this->m_nRowStrideInBytes[1] + m * this->m_nStrideInBytes[1];
      v20 = *(float *)&v18[v19];
      if ( v17 <= v20 )
        v21 = *(float *)&v18[v19];
      else
        v21 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      v22 = this->m_pAttributePtrs[2];
      v23 = k * this->m_nRowStrideInBytes[2] + m * this->m_nStrideInBytes[2];
      if ( v21 <= *(float *)&v22[v23] )
      {
        v20 = *(float *)&v22[v23];
      }
      else if ( v17 > v20 )
      {
        v20 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      }
      if ( v20 == 0.0 )
      {
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[0][k * TmpFBM.m_nRowStrideInBytes[0] + m * TmpFBM.m_nStrideInBytes[0]] = 0;
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[1][m * TmpFBM.m_nStrideInBytes[1] + k * TmpFBM.m_nRowStrideInBytes[1]] = 0;
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[2][m * TmpFBM.m_nStrideInBytes[2] + k * TmpFBM.m_nRowStrideInBytes[2]] = 0;
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[3][m * TmpFBM.m_nStrideInBytes[3] + k * TmpFBM.m_nRowStrideInBytes[3]] = 0;
      }
      else
      {
        X = (float)(1.0 / v3 * v20) * 255.0;
        if ( ceil(X) <= 255.0 )
        {
          v33 = ceil(X);
          v24 = v33;
        }
        else
        {
          v24 = 255.0;
        }
        v3 = overbright;
        v25 = (float)(int)v24;
        *(float *)&TmpFBM.m_pAttributePtrs[3][m * TmpFBM.m_nStrideInBytes[3] + k * TmpFBM.m_nRowStrideInBytes[3]] = v25;
        v26 = overbright * 0.00392156862745098 * (double)(int)v25;
        *(float *)&TmpFBM.m_pAttributePtrs[0][k * TmpFBM.m_nRowStrideInBytes[0] + m * TmpFBM.m_nStrideInBytes[0]] = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]] * (float)(1.0 / v26);
        *(float *)&TmpFBM.m_pAttributePtrs[1][m * TmpFBM.m_nStrideInBytes[1] + k * TmpFBM.m_nRowStrideInBytes[1]] = *(float *)&this->m_pAttributePtrs[1][k * this->m_nRowStrideInBytes[1] + m * this->m_nStrideInBytes[1]] * (float)(1.0 / v26);
        *(float *)&TmpFBM.m_pAttributePtrs[2][m * TmpFBM.m_nStrideInBytes[2] + k * TmpFBM.m_nRowStrideInBytes[2]] = *(float *)&this->m_pAttributePtrs[2][k * this->m_nRowStrideInBytes[2] + m * this->m_nStrideInBytes[2]] * (float)(1.0 / v26);
      }
    }
  }
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 0, nSrcAttributeIndex: -1);
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 1, nSrcAttributeIndex: -1);
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 2, nSrcAttributeIndex: -1);
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 3, nSrcAttributeIndex: -1);
  v27 = 0;
  if ( this->m_nRows > 0 )
  {
    m_nColumns = this->m_nColumns;
    do
    {
      v29 = 0;
      if ( m_nColumns > 0 )
      {
        do
        {
          v30 = v27 * this->m_nRowStrideInBytes[3] + v29 * this->m_nStrideInBytes[3];
          *(float *)&this->m_pAttributePtrs[3][v30] = *(float *)&this->m_pAttributePtrs[3][v30] * 0.00392156862745098;
          m_nColumns = this->m_nColumns;
          ++v29;
        }
        while ( v29 < this->m_nColumns );
      }
      ++v27;
    }
    while ( v27 < this->m_nRows );
  }
  CSOAContainer::~CSOAContainer(this: &TmpFBM);
}

//------------------------------------------------------------------------------
// Address: 0x004F01D0
// Name: bool SupportsSSE2(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
bool __cdecl SupportsSSE2()
{
  return IsProcessorFeaturePresent(ProcessorFeature: 0xAu);
}

//------------------------------------------------------------------------------
// Address: 0x004F0510
// Name: unsigned long CalcBufferSize(enum _CodecType,unsigned long,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl CalcBufferSize(int a1, int a2, int a3)
{
  int v3; // eax
  unsigned int result; // eax

  switch ( a1 )
  {
    case 2:
    case 11:
      v3 = 1;
      goto LABEL_4;
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 12:
    case 13:
    case 14:
      v3 = 2;
LABEL_4:
      result = (4 * 4 * ((unsigned int)(a3 + 3) >> 2) * 4 * ((unsigned int)(a2 + 3) >> 2) * v3) >> 3;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004F0580
// Name: unsigned char DeriveB(unsigned char,unsigned char)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 __cdecl DeriveB(unsigned __int8 a1, unsigned __int8 a2)
{
  double v2; // st6
  double v3; // st7
  float v5; // [esp+0h] [ebp-4h]
  float v6; // [esp+8h] [ebp+4h]
  float v7; // [esp+8h] [ebp+4h]
  float v8; // [esp+8h] [ebp+4h]
  float v9; // [esp+8h] [ebp+4h]
  float v10; // [esp+8h] [ebp+4h]
  float v11; // [esp+8h] [ebp+4h]
  float v12; // [esp+8h] [ebp+4h]
  float v13; // [esp+8h] [ebp+4h]
  float v14; // [esp+8h] [ebp+4h]
  float v15; // [esp+8h] [ebp+4h]

  v6 = (double)a1 / 255.0;
  v7 = v6 * 2.0;
  v5 = v7 - 1.0;
  v8 = (double)a2 / 255.0;
  v9 = 2.0 * v8;
  v10 = v9 - 1.0;
  v2 = v10 * v10 + v5 * v5;
  if ( v2 >= 1.0 )
    v2 = 1.0;
  v11 = v2;
  v12 = 1.0 - v11;
  v13 = sqrt(v12);
  v14 = v13 * 127.0;
  v15 = v14 + 128.0;
  if ( v15 < 255.0 )
  {
    v3 = 0.0;
    if ( v15 > 0.0 )
      return (int)v15;
  }
  else
  {
    v3 = 255.0;
  }
  return (int)(float)v3;
}

//------------------------------------------------------------------------------
// Address: 0x004F0690
// Name: float DeriveB(float,float)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl DeriveB(float a1, float a2)
{
  double v2; // st6
  float v4; // [esp+0h] [ebp-4h]
  float v5; // [esp+8h] [ebp+4h]
  float v6; // [esp+8h] [ebp+4h]
  float v7; // [esp+8h] [ebp+4h]
  float v8; // [esp+8h] [ebp+4h]
  float v9; // [esp+8h] [ebp+4h]
  float v10; // [esp+8h] [ebp+4h]
  float v11; // [esp+8h] [ebp+4h]

  v5 = a1 * 2.0;
  v4 = v5 - 1.0;
  v6 = 2.0 * a2;
  v7 = v6 - 1.0;
  v2 = v7 * v7 + v4 * v4;
  if ( v2 >= 1.0 )
    v2 = 1.0;
  v8 = v2;
  v9 = 1.0 - v8;
  v10 = sqrt(v9);
  v11 = v10 + 1.0;
  return (float)(v11 * 0.5);
}

//------------------------------------------------------------------------------
// Address: 0x004F0740
// Name: public: half::half(float)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
half *__thiscall half::half(half *this, int a2)
{
  if ( *(float *)&a2 == 0.0 )
  {
    *(_WORD *)this = 0;
    return this;
  }
  else
  {
    if ( *((_WORD *)&half::_eLut + ((unsigned int)a2 >> 23)) != 0 )
      *(_WORD *)this = *((_WORD *)&half::_eLut + ((unsigned int)a2 >> 23)) + (((a2 & 0x7FFFFFu) + 4096) >> 13);
    else
      *(_WORD *)this = half::convert(a1: a2);
    return this;
  }
}

} // namespace sceneviewer

// ============================================================
// Overlay from tgadiff (Missing functions)
// ============================================================
namespace tgadiff {

//------------------------------------------------------------------------------
// Address: 0x0040A4E0
// Name: public: void FloatBitMap_t::CompressTo8Bits(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::CompressTo8Bits(FloatBitMap_t *this, float overbright)
{
  float v3; // xmm2_4
  int i; // ecx
  int j; // eax
  unsigned int v6; // edx
  unsigned __int8 *v7; // edi
  float v8; // xmm0_4
  unsigned int v9; // edx
  unsigned __int8 *v10; // edi
  float v11; // xmm0_4
  unsigned int v12; // edx
  unsigned __int8 *v13; // edi
  float v14; // xmm0_4
  int k; // ebx
  int m; // edi
  float v17; // xmm1_4
  unsigned __int8 *v18; // edx
  unsigned int v19; // eax
  float v20; // xmm0_4
  float v21; // xmm4_4
  unsigned __int8 *v22; // edx
  unsigned int v23; // eax
  double v24; // xmm0_8
  float v25; // xmm0_4
  float v26; // xmm1_4
  int v27; // edx
  int m_nColumns; // ecx
  int v29; // eax
  unsigned int v30; // ecx
  FloatBitMap_t TmpFBM; // [esp+14h] [ebp-334h] BYREF
  double X; // [esp+338h] [ebp-10h]
  double v33; // [esp+340h] [ebp-8h]

  FloatBitMap_t::FloatBitMap_t(
    this: &TmpFBM,
    nWidth: this->m_nColumns,
    nHeight: this->m_nRows,
    nDepth: 1,
    nAttributeMask: 15);
  v3 = overbright;
  for ( i = 0; i < this->m_nRows; ++i )
  {
    for ( j = 0; j < this->m_nColumns; *(float *)&v13[v12] = v14 )
    {
      v6 = i * this->m_nRowStrideInBytes[0] + j * this->m_nStrideInBytes[0];
      v7 = this->m_pAttributePtrs[0];
      v8 = *(float *)&v7[v6];
      if ( v8 > overbright )
        v8 = overbright;
      *(float *)&v7[v6] = v8;
      v9 = i * this->m_nRowStrideInBytes[1] + j * this->m_nStrideInBytes[1];
      v10 = this->m_pAttributePtrs[1];
      v11 = *(float *)&v10[v9];
      if ( v11 > overbright )
        v11 = overbright;
      *(float *)&v10[v9] = v11;
      v12 = i * this->m_nRowStrideInBytes[2] + j * this->m_nStrideInBytes[2];
      v13 = this->m_pAttributePtrs[2];
      v14 = *(float *)&v13[v12];
      if ( v14 > overbright )
        v14 = overbright;
      ++j;
    }
  }
  for ( k = 0; k < this->m_nRows; ++k )
  {
    for ( m = 0; m < this->m_nColumns; ++m )
    {
      v17 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      v18 = this->m_pAttributePtrs[1];
      v19 = k * this->m_nRowStrideInBytes[1] + m * this->m_nStrideInBytes[1];
      v20 = *(float *)&v18[v19];
      if ( v17 <= v20 )
        v21 = *(float *)&v18[v19];
      else
        v21 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      v22 = this->m_pAttributePtrs[2];
      v23 = k * this->m_nRowStrideInBytes[2] + m * this->m_nStrideInBytes[2];
      if ( v21 <= *(float *)&v22[v23] )
      {
        v20 = *(float *)&v22[v23];
      }
      else if ( v17 > v20 )
      {
        v20 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      }
      if ( v20 == 0.0 )
      {
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[0][k * TmpFBM.m_nRowStrideInBytes[0] + m * TmpFBM.m_nStrideInBytes[0]] = 0;
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[1][m * TmpFBM.m_nStrideInBytes[1] + k * TmpFBM.m_nRowStrideInBytes[1]] = 0;
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[2][m * TmpFBM.m_nStrideInBytes[2] + k * TmpFBM.m_nRowStrideInBytes[2]] = 0;
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[3][m * TmpFBM.m_nStrideInBytes[3] + k * TmpFBM.m_nRowStrideInBytes[3]] = 0;
      }
      else
      {
        X = (float)(1.0 / v3 * v20) * 255.0;
        if ( ceil(X) <= 255.0 )
        {
          v33 = ceil(X);
          v24 = v33;
        }
        else
        {
          v24 = 255.0;
        }
        v3 = overbright;
        v25 = (float)(int)v24;
        *(float *)&TmpFBM.m_pAttributePtrs[3][m * TmpFBM.m_nStrideInBytes[3] + k * TmpFBM.m_nRowStrideInBytes[3]] = v25;
        v26 = overbright * 0.00392156862745098 * (double)(int)v25;
        *(float *)&TmpFBM.m_pAttributePtrs[0][k * TmpFBM.m_nRowStrideInBytes[0] + m * TmpFBM.m_nStrideInBytes[0]] = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]] * (float)(1.0 / v26);
        *(float *)&TmpFBM.m_pAttributePtrs[1][m * TmpFBM.m_nStrideInBytes[1] + k * TmpFBM.m_nRowStrideInBytes[1]] = *(float *)&this->m_pAttributePtrs[1][k * this->m_nRowStrideInBytes[1] + m * this->m_nStrideInBytes[1]] * (float)(1.0 / v26);
        *(float *)&TmpFBM.m_pAttributePtrs[2][m * TmpFBM.m_nStrideInBytes[2] + k * TmpFBM.m_nRowStrideInBytes[2]] = *(float *)&this->m_pAttributePtrs[2][k * this->m_nRowStrideInBytes[2] + m * this->m_nStrideInBytes[2]] * (float)(1.0 / v26);
      }
    }
  }
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 0, nSrcAttributeIndex: -1);
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 1, nSrcAttributeIndex: -1);
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 2, nSrcAttributeIndex: -1);
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 3, nSrcAttributeIndex: -1);
  v27 = 0;
  if ( this->m_nRows > 0 )
  {
    m_nColumns = this->m_nColumns;
    do
    {
      v29 = 0;
      if ( m_nColumns > 0 )
      {
        do
        {
          v30 = v27 * this->m_nRowStrideInBytes[3] + v29 * this->m_nStrideInBytes[3];
          *(float *)&this->m_pAttributePtrs[3][v30] = *(float *)&this->m_pAttributePtrs[3][v30] * 0.00392156862745098;
          m_nColumns = this->m_nColumns;
          ++v29;
        }
        while ( v29 < this->m_nColumns );
      }
      ++v27;
    }
    while ( v27 < this->m_nRows );
  }
  CSOAContainer::~CSOAContainer(this: &TmpFBM);
}

} // namespace tgadiff

// ============================================================
// Overlay from tgamse (Missing functions)
// ============================================================
namespace tgamse {

//------------------------------------------------------------------------------
// Address: 0x0040A110
// Name: public: void FloatBitMap_t::CompressTo8Bits(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::CompressTo8Bits(FloatBitMap_t *this, float overbright)
{
  float v3; // xmm2_4
  int i; // ecx
  int j; // eax
  unsigned int v6; // edx
  unsigned __int8 *v7; // edi
  float v8; // xmm0_4
  unsigned int v9; // edx
  unsigned __int8 *v10; // edi
  float v11; // xmm0_4
  unsigned int v12; // edx
  unsigned __int8 *v13; // edi
  float v14; // xmm0_4
  int k; // ebx
  int m; // edi
  float v17; // xmm1_4
  unsigned __int8 *v18; // edx
  unsigned int v19; // eax
  float v20; // xmm0_4
  float v21; // xmm4_4
  unsigned __int8 *v22; // edx
  unsigned int v23; // eax
  double v24; // xmm0_8
  float v25; // xmm0_4
  float v26; // xmm1_4
  int v27; // edx
  int m_nColumns; // ecx
  int v29; // eax
  unsigned int v30; // ecx
  FloatBitMap_t TmpFBM; // [esp+14h] [ebp-334h] BYREF
  double X; // [esp+338h] [ebp-10h]
  double v33; // [esp+340h] [ebp-8h]

  FloatBitMap_t::FloatBitMap_t(
    this: &TmpFBM,
    nWidth: this->m_nColumns,
    nHeight: this->m_nRows,
    nDepth: 1,
    nAttributeMask: 15);
  v3 = overbright;
  for ( i = 0; i < this->m_nRows; ++i )
  {
    for ( j = 0; j < this->m_nColumns; *(float *)&v13[v12] = v14 )
    {
      v6 = i * this->m_nRowStrideInBytes[0] + j * this->m_nStrideInBytes[0];
      v7 = this->m_pAttributePtrs[0];
      v8 = *(float *)&v7[v6];
      if ( v8 > overbright )
        v8 = overbright;
      *(float *)&v7[v6] = v8;
      v9 = i * this->m_nRowStrideInBytes[1] + j * this->m_nStrideInBytes[1];
      v10 = this->m_pAttributePtrs[1];
      v11 = *(float *)&v10[v9];
      if ( v11 > overbright )
        v11 = overbright;
      *(float *)&v10[v9] = v11;
      v12 = i * this->m_nRowStrideInBytes[2] + j * this->m_nStrideInBytes[2];
      v13 = this->m_pAttributePtrs[2];
      v14 = *(float *)&v13[v12];
      if ( v14 > overbright )
        v14 = overbright;
      ++j;
    }
  }
  for ( k = 0; k < this->m_nRows; ++k )
  {
    for ( m = 0; m < this->m_nColumns; ++m )
    {
      v17 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      v18 = this->m_pAttributePtrs[1];
      v19 = k * this->m_nRowStrideInBytes[1] + m * this->m_nStrideInBytes[1];
      v20 = *(float *)&v18[v19];
      if ( v17 <= v20 )
        v21 = *(float *)&v18[v19];
      else
        v21 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      v22 = this->m_pAttributePtrs[2];
      v23 = k * this->m_nRowStrideInBytes[2] + m * this->m_nStrideInBytes[2];
      if ( v21 <= *(float *)&v22[v23] )
      {
        v20 = *(float *)&v22[v23];
      }
      else if ( v17 > v20 )
      {
        v20 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      }
      if ( v20 == 0.0 )
      {
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[0][k * TmpFBM.m_nRowStrideInBytes[0] + m * TmpFBM.m_nStrideInBytes[0]] = 0;
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[1][m * TmpFBM.m_nStrideInBytes[1] + k * TmpFBM.m_nRowStrideInBytes[1]] = 0;
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[2][m * TmpFBM.m_nStrideInBytes[2] + k * TmpFBM.m_nRowStrideInBytes[2]] = 0;
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[3][m * TmpFBM.m_nStrideInBytes[3] + k * TmpFBM.m_nRowStrideInBytes[3]] = 0;
      }
      else
      {
        X = (float)(1.0 / v3 * v20) * 255.0;
        if ( ceil(X) <= 255.0 )
        {
          v33 = ceil(X);
          v24 = v33;
        }
        else
        {
          v24 = 255.0;
        }
        v3 = overbright;
        v25 = (float)(int)v24;
        *(float *)&TmpFBM.m_pAttributePtrs[3][m * TmpFBM.m_nStrideInBytes[3] + k * TmpFBM.m_nRowStrideInBytes[3]] = v25;
        v26 = overbright * 0.00392156862745098 * (double)(int)v25;
        *(float *)&TmpFBM.m_pAttributePtrs[0][k * TmpFBM.m_nRowStrideInBytes[0] + m * TmpFBM.m_nStrideInBytes[0]] = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]] * (float)(1.0 / v26);
        *(float *)&TmpFBM.m_pAttributePtrs[1][m * TmpFBM.m_nStrideInBytes[1] + k * TmpFBM.m_nRowStrideInBytes[1]] = *(float *)&this->m_pAttributePtrs[1][k * this->m_nRowStrideInBytes[1] + m * this->m_nStrideInBytes[1]] * (float)(1.0 / v26);
        *(float *)&TmpFBM.m_pAttributePtrs[2][m * TmpFBM.m_nStrideInBytes[2] + k * TmpFBM.m_nRowStrideInBytes[2]] = *(float *)&this->m_pAttributePtrs[2][k * this->m_nRowStrideInBytes[2] + m * this->m_nStrideInBytes[2]] * (float)(1.0 / v26);
      }
    }
  }
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 0, nSrcAttributeIndex: -1);
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 1, nSrcAttributeIndex: -1);
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 2, nSrcAttributeIndex: -1);
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 3, nSrcAttributeIndex: -1);
  v27 = 0;
  if ( this->m_nRows > 0 )
  {
    m_nColumns = this->m_nColumns;
    do
    {
      v29 = 0;
      if ( m_nColumns > 0 )
      {
        do
        {
          v30 = v27 * this->m_nRowStrideInBytes[3] + v29 * this->m_nStrideInBytes[3];
          *(float *)&this->m_pAttributePtrs[3][v30] = *(float *)&this->m_pAttributePtrs[3][v30] * 0.00392156862745098;
          m_nColumns = this->m_nColumns;
          ++v29;
        }
        while ( v29 < this->m_nColumns );
      }
      ++v27;
    }
    while ( v27 < this->m_nRows );
  }
  CSOAContainer::~CSOAContainer(this: &TmpFBM);
}

} // namespace tgamse

// ============================================================
// Overlay from vbsp (Missing functions)
// ============================================================
namespace vbsp {

//------------------------------------------------------------------------------
// Address: 0x00488910
// Name: public: void FloatBitMap_t::CompressTo8Bits(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::CompressTo8Bits(FloatBitMap_t *this, float overbright)
{
  float v3; // xmm2_4
  int i; // ecx
  int j; // eax
  unsigned int v6; // edx
  unsigned __int8 *v7; // edi
  float v8; // xmm0_4
  unsigned int v9; // edx
  unsigned __int8 *v10; // edi
  float v11; // xmm0_4
  unsigned int v12; // edx
  unsigned __int8 *v13; // edi
  float v14; // xmm0_4
  int k; // ebx
  int m; // edi
  float v17; // xmm1_4
  unsigned __int8 *v18; // edx
  unsigned int v19; // eax
  float v20; // xmm0_4
  float v21; // xmm4_4
  unsigned __int8 *v22; // edx
  unsigned int v23; // eax
  double v24; // xmm0_8
  float v25; // xmm0_4
  float v26; // xmm1_4
  int v27; // edx
  int m_nColumns; // ecx
  int v29; // eax
  unsigned int v30; // ecx
  FloatBitMap_t TmpFBM; // [esp+14h] [ebp-334h] BYREF
  double X; // [esp+338h] [ebp-10h]
  double v33; // [esp+340h] [ebp-8h]

  FloatBitMap_t::FloatBitMap_t(
    this: &TmpFBM,
    nWidth: this->m_nColumns,
    nHeight: this->m_nRows,
    nDepth: 1,
    nAttributeMask: 15);
  v3 = overbright;
  for ( i = 0; i < this->m_nRows; ++i )
  {
    for ( j = 0; j < this->m_nColumns; *(float *)&v13[v12] = v14 )
    {
      v6 = i * this->m_nRowStrideInBytes[0] + j * this->m_nStrideInBytes[0];
      v7 = this->m_pAttributePtrs[0];
      v8 = *(float *)&v7[v6];
      if ( v8 > overbright )
        v8 = overbright;
      *(float *)&v7[v6] = v8;
      v9 = i * this->m_nRowStrideInBytes[1] + j * this->m_nStrideInBytes[1];
      v10 = this->m_pAttributePtrs[1];
      v11 = *(float *)&v10[v9];
      if ( v11 > overbright )
        v11 = overbright;
      *(float *)&v10[v9] = v11;
      v12 = i * this->m_nRowStrideInBytes[2] + j * this->m_nStrideInBytes[2];
      v13 = this->m_pAttributePtrs[2];
      v14 = *(float *)&v13[v12];
      if ( v14 > overbright )
        v14 = overbright;
      ++j;
    }
  }
  for ( k = 0; k < this->m_nRows; ++k )
  {
    for ( m = 0; m < this->m_nColumns; ++m )
    {
      v17 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      v18 = this->m_pAttributePtrs[1];
      v19 = k * this->m_nRowStrideInBytes[1] + m * this->m_nStrideInBytes[1];
      v20 = *(float *)&v18[v19];
      if ( v17 <= v20 )
        v21 = *(float *)&v18[v19];
      else
        v21 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      v22 = this->m_pAttributePtrs[2];
      v23 = k * this->m_nRowStrideInBytes[2] + m * this->m_nStrideInBytes[2];
      if ( v21 <= *(float *)&v22[v23] )
      {
        v20 = *(float *)&v22[v23];
      }
      else if ( v17 > v20 )
      {
        v20 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      }
      if ( v20 == 0.0 )
      {
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[0][k * TmpFBM.m_nRowStrideInBytes[0] + m * TmpFBM.m_nStrideInBytes[0]] = 0;
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[1][m * TmpFBM.m_nStrideInBytes[1] + k * TmpFBM.m_nRowStrideInBytes[1]] = 0;
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[2][m * TmpFBM.m_nStrideInBytes[2] + k * TmpFBM.m_nRowStrideInBytes[2]] = 0;
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[3][m * TmpFBM.m_nStrideInBytes[3] + k * TmpFBM.m_nRowStrideInBytes[3]] = 0;
      }
      else
      {
        X = (float)(1.0 / v3 * v20) * 255.0;
        if ( ceil(X) <= 255.0 )
        {
          v33 = ceil(X);
          v24 = v33;
        }
        else
        {
          v24 = 255.0;
        }
        v3 = overbright;
        v25 = (float)(int)v24;
        *(float *)&TmpFBM.m_pAttributePtrs[3][m * TmpFBM.m_nStrideInBytes[3] + k * TmpFBM.m_nRowStrideInBytes[3]] = v25;
        v26 = overbright * 0.00392156862745098 * (double)(int)v25;
        *(float *)&TmpFBM.m_pAttributePtrs[0][k * TmpFBM.m_nRowStrideInBytes[0] + m * TmpFBM.m_nStrideInBytes[0]] = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]] * (float)(1.0 / v26);
        *(float *)&TmpFBM.m_pAttributePtrs[1][m * TmpFBM.m_nStrideInBytes[1] + k * TmpFBM.m_nRowStrideInBytes[1]] = *(float *)&this->m_pAttributePtrs[1][k * this->m_nRowStrideInBytes[1] + m * this->m_nStrideInBytes[1]] * (float)(1.0 / v26);
        *(float *)&TmpFBM.m_pAttributePtrs[2][m * TmpFBM.m_nStrideInBytes[2] + k * TmpFBM.m_nRowStrideInBytes[2]] = *(float *)&this->m_pAttributePtrs[2][k * this->m_nRowStrideInBytes[2] + m * this->m_nStrideInBytes[2]] * (float)(1.0 / v26);
      }
    }
  }
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 0, nSrcAttributeIndex: -1);
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 1, nSrcAttributeIndex: -1);
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 2, nSrcAttributeIndex: -1);
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 3, nSrcAttributeIndex: -1);
  v27 = 0;
  if ( this->m_nRows > 0 )
  {
    m_nColumns = this->m_nColumns;
    do
    {
      v29 = 0;
      if ( m_nColumns > 0 )
      {
        do
        {
          v30 = v27 * this->m_nRowStrideInBytes[3] + v29 * this->m_nStrideInBytes[3];
          *(float *)&this->m_pAttributePtrs[3][v30] = *(float *)&this->m_pAttributePtrs[3][v30] * 0.00392156862745098;
          m_nColumns = this->m_nColumns;
          ++v29;
        }
        while ( v29 < this->m_nColumns );
      }
      ++v27;
    }
    while ( v27 < this->m_nRows );
  }
  CSOAContainer::~CSOAContainer(this: &TmpFBM);
}

//------------------------------------------------------------------------------
// Address: 0x00488DC0
// Name: bool SupportsSSE2(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
bool __cdecl SupportsSSE2()
{
  return IsProcessorFeaturePresent(ProcessorFeature: 0xAu);
}

//------------------------------------------------------------------------------
// Address: 0x00489100
// Name: unsigned long CalcBufferSize(enum _CodecType,unsigned long,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl CalcBufferSize(int a1, int a2, int a3)
{
  int v3; // eax
  unsigned int result; // eax

  switch ( a1 )
  {
    case 2:
    case 11:
      v3 = 1;
      goto LABEL_4;
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 12:
    case 13:
    case 14:
      v3 = 2;
LABEL_4:
      result = (4 * 4 * ((unsigned int)(a3 + 3) >> 2) * 4 * ((unsigned int)(a2 + 3) >> 2) * v3) >> 3;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00489170
// Name: unsigned char DeriveB(unsigned char,unsigned char)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 __cdecl DeriveB(unsigned __int8 a1, unsigned __int8 a2)
{
  double v2; // st6
  double v3; // st7
  float v5; // [esp+0h] [ebp-4h]
  float v6; // [esp+8h] [ebp+4h]
  float v7; // [esp+8h] [ebp+4h]
  float v8; // [esp+8h] [ebp+4h]
  float v9; // [esp+8h] [ebp+4h]
  float v10; // [esp+8h] [ebp+4h]
  float v11; // [esp+8h] [ebp+4h]
  float v12; // [esp+8h] [ebp+4h]
  float v13; // [esp+8h] [ebp+4h]
  float v14; // [esp+8h] [ebp+4h]
  float v15; // [esp+8h] [ebp+4h]

  v6 = (double)a1 / 255.0;
  v7 = v6 * 2.0;
  v5 = v7 - 1.0;
  v8 = (double)a2 / 255.0;
  v9 = 2.0 * v8;
  v10 = v9 - 1.0;
  v2 = v10 * v10 + v5 * v5;
  if ( v2 >= 1.0 )
    v2 = 1.0;
  v11 = v2;
  v12 = 1.0 - v11;
  v13 = sqrt(v12);
  v14 = v13 * 127.0;
  v15 = v14 + 128.0;
  if ( v15 < 255.0 )
  {
    v3 = 0.0;
    if ( v15 > 0.0 )
      return (int)v15;
  }
  else
  {
    v3 = 255.0;
  }
  return (int)(float)v3;
}

//------------------------------------------------------------------------------
// Address: 0x00489280
// Name: float DeriveB(float,float)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl DeriveB(float a1, float a2)
{
  double v2; // st6
  float v4; // [esp+0h] [ebp-4h]
  float v5; // [esp+8h] [ebp+4h]
  float v6; // [esp+8h] [ebp+4h]
  float v7; // [esp+8h] [ebp+4h]
  float v8; // [esp+8h] [ebp+4h]
  float v9; // [esp+8h] [ebp+4h]
  float v10; // [esp+8h] [ebp+4h]
  float v11; // [esp+8h] [ebp+4h]

  v5 = a1 * 2.0;
  v4 = v5 - 1.0;
  v6 = 2.0 * a2;
  v7 = v6 - 1.0;
  v2 = v7 * v7 + v4 * v4;
  if ( v2 >= 1.0 )
    v2 = 1.0;
  v8 = v2;
  v9 = 1.0 - v8;
  v10 = sqrt(v9);
  v11 = v10 + 1.0;
  return (float)(v11 * 0.5);
}

//------------------------------------------------------------------------------
// Address: 0x00489340
// Name: public: half::half(float)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
half *__thiscall half::half(half *this, int a2)
{
  if ( *(float *)&a2 == 0.0 )
  {
    *(_WORD *)this = 0;
    return this;
  }
  else
  {
    if ( *((_WORD *)&half::_eLut + ((unsigned int)a2 >> 23)) != 0 )
      *(_WORD *)this = *((_WORD *)&half::_eLut + ((unsigned int)a2 >> 23)) + (((a2 & 0x7FFFFFu) + 4096) >> 13);
    else
      *(_WORD *)this = half::convert(a1: a2);
    return this;
  }
}

} // namespace vbsp

// ============================================================
// Overlay from vguimatsurface (Missing functions)
// ============================================================
namespace vguimatsurface {

//------------------------------------------------------------------------------
// Address: 0x10021960
// Name: public: void FloatBitMap_t::CompressTo8Bits(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::CompressTo8Bits(FloatBitMap_t *this, float overbright)
{
  float v3; // xmm2_4
  int i; // ecx
  int j; // eax
  unsigned int v6; // edx
  unsigned __int8 *v7; // edi
  float v8; // xmm0_4
  unsigned int v9; // edx
  unsigned __int8 *v10; // edi
  float v11; // xmm0_4
  unsigned int v12; // edx
  unsigned __int8 *v13; // edi
  float v14; // xmm0_4
  int k; // ebx
  int m; // edi
  float v17; // xmm1_4
  unsigned __int8 *v18; // edx
  unsigned int v19; // eax
  float v20; // xmm0_4
  float v21; // xmm4_4
  unsigned __int8 *v22; // edx
  unsigned int v23; // eax
  double v24; // xmm0_8
  float v25; // xmm0_4
  float v26; // xmm1_4
  int v27; // edx
  int m_nColumns; // ecx
  int v29; // eax
  unsigned int v30; // ecx
  FloatBitMap_t TmpFBM; // [esp+14h] [ebp-334h] BYREF
  double X; // [esp+338h] [ebp-10h]
  double v33; // [esp+340h] [ebp-8h]

  FloatBitMap_t::FloatBitMap_t(
    this: &TmpFBM,
    nWidth: this->m_nColumns,
    nHeight: this->m_nRows,
    nDepth: 1,
    nAttributeMask: 15);
  v3 = overbright;
  for ( i = 0; i < this->m_nRows; ++i )
  {
    for ( j = 0; j < this->m_nColumns; *(float *)&v13[v12] = v14 )
    {
      v6 = i * this->m_nRowStrideInBytes[0] + j * this->m_nStrideInBytes[0];
      v7 = this->m_pAttributePtrs[0];
      v8 = *(float *)&v7[v6];
      if ( v8 > overbright )
        v8 = overbright;
      *(float *)&v7[v6] = v8;
      v9 = i * this->m_nRowStrideInBytes[1] + j * this->m_nStrideInBytes[1];
      v10 = this->m_pAttributePtrs[1];
      v11 = *(float *)&v10[v9];
      if ( v11 > overbright )
        v11 = overbright;
      *(float *)&v10[v9] = v11;
      v12 = i * this->m_nRowStrideInBytes[2] + j * this->m_nStrideInBytes[2];
      v13 = this->m_pAttributePtrs[2];
      v14 = *(float *)&v13[v12];
      if ( v14 > overbright )
        v14 = overbright;
      ++j;
    }
  }
  for ( k = 0; k < this->m_nRows; ++k )
  {
    for ( m = 0; m < this->m_nColumns; ++m )
    {
      v17 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      v18 = this->m_pAttributePtrs[1];
      v19 = k * this->m_nRowStrideInBytes[1] + m * this->m_nStrideInBytes[1];
      v20 = *(float *)&v18[v19];
      if ( v17 <= v20 )
        v21 = *(float *)&v18[v19];
      else
        v21 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      v22 = this->m_pAttributePtrs[2];
      v23 = k * this->m_nRowStrideInBytes[2] + m * this->m_nStrideInBytes[2];
      if ( v21 <= *(float *)&v22[v23] )
      {
        v20 = *(float *)&v22[v23];
      }
      else if ( v17 > v20 )
      {
        v20 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      }
      if ( v20 == 0.0 )
      {
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[0][k * TmpFBM.m_nRowStrideInBytes[0] + m * TmpFBM.m_nStrideInBytes[0]] = 0;
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[1][m * TmpFBM.m_nStrideInBytes[1] + k * TmpFBM.m_nRowStrideInBytes[1]] = 0;
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[2][m * TmpFBM.m_nStrideInBytes[2] + k * TmpFBM.m_nRowStrideInBytes[2]] = 0;
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[3][m * TmpFBM.m_nStrideInBytes[3] + k * TmpFBM.m_nRowStrideInBytes[3]] = 0;
      }
      else
      {
        X = (float)(1.0 / v3 * v20) * 255.0;
        if ( ceil(X) <= 255.0 )
        {
          v33 = ceil(X);
          v24 = v33;
        }
        else
        {
          v24 = 255.0;
        }
        v3 = overbright;
        v25 = (float)(int)v24;
        *(float *)&TmpFBM.m_pAttributePtrs[3][m * TmpFBM.m_nStrideInBytes[3] + k * TmpFBM.m_nRowStrideInBytes[3]] = v25;
        v26 = overbright * 0.00392156862745098 * (double)(int)v25;
        *(float *)&TmpFBM.m_pAttributePtrs[0][k * TmpFBM.m_nRowStrideInBytes[0] + m * TmpFBM.m_nStrideInBytes[0]] = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]] * (float)(1.0 / v26);
        *(float *)&TmpFBM.m_pAttributePtrs[1][m * TmpFBM.m_nStrideInBytes[1] + k * TmpFBM.m_nRowStrideInBytes[1]] = *(float *)&this->m_pAttributePtrs[1][k * this->m_nRowStrideInBytes[1] + m * this->m_nStrideInBytes[1]] * (float)(1.0 / v26);
        *(float *)&TmpFBM.m_pAttributePtrs[2][m * TmpFBM.m_nStrideInBytes[2] + k * TmpFBM.m_nRowStrideInBytes[2]] = *(float *)&this->m_pAttributePtrs[2][k * this->m_nRowStrideInBytes[2] + m * this->m_nStrideInBytes[2]] * (float)(1.0 / v26);
      }
    }
  }
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 0, nSrcAttributeIndex: -1);
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 1, nSrcAttributeIndex: -1);
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 2, nSrcAttributeIndex: -1);
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 3, nSrcAttributeIndex: -1);
  v27 = 0;
  if ( this->m_nRows > 0 )
  {
    m_nColumns = this->m_nColumns;
    do
    {
      v29 = 0;
      if ( m_nColumns > 0 )
      {
        do
        {
          v30 = v27 * this->m_nRowStrideInBytes[3] + v29 * this->m_nStrideInBytes[3];
          *(float *)&this->m_pAttributePtrs[3][v30] = *(float *)&this->m_pAttributePtrs[3][v30] * 0.00392156862745098;
          m_nColumns = this->m_nColumns;
          ++v29;
        }
        while ( v29 < this->m_nColumns );
      }
      ++v27;
    }
    while ( v27 < this->m_nRows );
  }
  CSOAContainer::~CSOAContainer(this: &TmpFBM);
}

//------------------------------------------------------------------------------
// Address: 0x10021E10
// Name: bool SupportsSSE2(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
bool __cdecl SupportsSSE2()
{
  return IsProcessorFeaturePresent(ProcessorFeature: 0xAu);
}

//------------------------------------------------------------------------------
// Address: 0x10022150
// Name: unsigned long CalcBufferSize(enum _CodecType,unsigned long,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl CalcBufferSize(int a1, int a2, int a3)
{
  int v3; // eax
  unsigned int result; // eax

  switch ( a1 )
  {
    case 2:
    case 11:
      v3 = 1;
      goto LABEL_4;
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 12:
    case 13:
    case 14:
      v3 = 2;
LABEL_4:
      result = (4 * 4 * ((unsigned int)(a3 + 3) >> 2) * 4 * ((unsigned int)(a2 + 3) >> 2) * v3) >> 3;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100221C0
// Name: unsigned char DeriveB(unsigned char,unsigned char)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 __cdecl DeriveB(unsigned __int8 a1, unsigned __int8 a2)
{
  double v2; // st6
  double v3; // st7
  float v5; // [esp+0h] [ebp-4h]
  float v6; // [esp+8h] [ebp+4h]
  float v7; // [esp+8h] [ebp+4h]
  float v8; // [esp+8h] [ebp+4h]
  float v9; // [esp+8h] [ebp+4h]
  float v10; // [esp+8h] [ebp+4h]
  float v11; // [esp+8h] [ebp+4h]
  float v12; // [esp+8h] [ebp+4h]
  float v13; // [esp+8h] [ebp+4h]
  float v14; // [esp+8h] [ebp+4h]
  float v15; // [esp+8h] [ebp+4h]

  v6 = (double)a1 / 255.0;
  v7 = v6 * 2.0;
  v5 = v7 - 1.0;
  v8 = (double)a2 / 255.0;
  v9 = 2.0 * v8;
  v10 = v9 - 1.0;
  v2 = v10 * v10 + v5 * v5;
  if ( v2 >= 1.0 )
    v2 = 1.0;
  v11 = v2;
  v12 = 1.0 - v11;
  v13 = sqrt(v12);
  v14 = v13 * 127.0;
  v15 = v14 + 128.0;
  if ( v15 < 255.0 )
  {
    v3 = 0.0;
    if ( v15 > 0.0 )
      return (int)v15;
  }
  else
  {
    v3 = 255.0;
  }
  return (int)(float)v3;
}

//------------------------------------------------------------------------------
// Address: 0x100222D0
// Name: float DeriveB(float,float)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl DeriveB(float a1, float a2)
{
  double v2; // st6
  float v4; // [esp+0h] [ebp-4h]
  float v5; // [esp+8h] [ebp+4h]
  float v6; // [esp+8h] [ebp+4h]
  float v7; // [esp+8h] [ebp+4h]
  float v8; // [esp+8h] [ebp+4h]
  float v9; // [esp+8h] [ebp+4h]
  float v10; // [esp+8h] [ebp+4h]
  float v11; // [esp+8h] [ebp+4h]

  v5 = a1 * 2.0;
  v4 = v5 - 1.0;
  v6 = 2.0 * a2;
  v7 = v6 - 1.0;
  v2 = v7 * v7 + v4 * v4;
  if ( v2 >= 1.0 )
    v2 = 1.0;
  v8 = v2;
  v9 = 1.0 - v8;
  v10 = sqrt(v9);
  v11 = v10 + 1.0;
  return (float)(v11 * 0.5);
}

//------------------------------------------------------------------------------
// Address: 0x10022380
// Name: public: half::half(float)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
half *__thiscall half::half(half *this, int a2)
{
  if ( *(float *)&a2 == 0.0 )
  {
    *(_WORD *)this = 0;
    return this;
  }
  else
  {
    if ( *((_WORD *)&half::_eLut + ((unsigned int)a2 >> 23)) != 0 )
      *(_WORD *)this = *((_WORD *)&half::_eLut + ((unsigned int)a2 >> 23)) + (((a2 & 0x7FFFFFu) + 4096) >> 13);
    else
      *(_WORD *)this = half::convert(a1: a2);
    return this;
  }
}

} // namespace vguimatsurface

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x004419F0
// Name: public: void FloatBitMap_t::CompressTo8Bits(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::CompressTo8Bits(FloatBitMap_t *this, float overbright)
{
  float v3; // xmm2_4
  int i; // ecx
  int j; // eax
  unsigned int v6; // edx
  unsigned __int8 *v7; // edi
  float v8; // xmm0_4
  float *v9; // edx
  unsigned int v10; // edx
  unsigned __int8 *v11; // edi
  float v12; // xmm0_4
  float *v13; // edx
  unsigned int v14; // edx
  unsigned __int8 *v15; // edi
  float v16; // xmm0_4
  float *v17; // edx
  int k; // ebx
  int m; // edi
  float v20; // xmm0_4
  unsigned __int8 *v21; // edx
  unsigned int v22; // eax
  float v23; // xmm1_4
  float v24; // xmm4_4
  unsigned __int8 *v25; // edx
  unsigned int v26; // eax
  double v27; // xmm0_8
  float v28; // xmm0_4
  float v29; // xmm1_4
  int v30; // edx
  int m_nColumns; // ecx
  int v32; // eax
  unsigned int v33; // ecx
  double X; // [esp+50h] [ebp-338h]
  FloatBitMap_t TmpFBM; // [esp+60h] [ebp-328h] BYREF

  FloatBitMap_t::FloatBitMap_t(
    this: &TmpFBM,
    nWidth: this->m_nColumns,
    nHeight: this->m_nRows,
    nDepth: 1,
    nAttributeMask: 15);
  v3 = overbright;
  for ( i = 0; i < this->m_nRows; ++i )
  {
    for ( j = 0; j < this->m_nColumns; *v17 = v16 )
    {
      v6 = i * this->m_nRowStrideInBytes[0] + j * this->m_nStrideInBytes[0];
      v7 = this->m_pAttributePtrs[0];
      v8 = *(float *)&v7[v6];
      v9 = (float *)&v7[v6];
      if ( v8 > overbright )
        v8 = overbright;
      *v9 = v8;
      v10 = i * this->m_nRowStrideInBytes[1] + j * this->m_nStrideInBytes[1];
      v11 = this->m_pAttributePtrs[1];
      v12 = *(float *)&v11[v10];
      v13 = (float *)&v11[v10];
      if ( v12 > overbright )
        v12 = overbright;
      *v13 = v12;
      v14 = i * this->m_nRowStrideInBytes[2] + j * this->m_nStrideInBytes[2];
      v15 = this->m_pAttributePtrs[2];
      v16 = *(float *)&v15[v14];
      v17 = (float *)&v15[v14];
      if ( v16 > overbright )
        v16 = overbright;
      ++j;
    }
  }
  for ( k = 0; k < this->m_nRows; ++k )
  {
    for ( m = 0; m < this->m_nColumns; ++m )
    {
      v20 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      v21 = this->m_pAttributePtrs[1];
      v22 = k * this->m_nRowStrideInBytes[1] + m * this->m_nStrideInBytes[1];
      v23 = *(float *)&v21[v22];
      if ( v20 <= v23 )
        v24 = *(float *)&v21[v22];
      else
        v24 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      v25 = this->m_pAttributePtrs[2];
      v26 = k * this->m_nRowStrideInBytes[2] + m * this->m_nStrideInBytes[2];
      if ( v24 <= *(float *)&v25[v26] )
      {
        v23 = *(float *)&v25[v26];
      }
      else if ( v20 > v23 )
      {
        v23 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      }
      if ( v23 == 0.0 )
      {
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[0][k * TmpFBM.m_nRowStrideInBytes[0] + m * TmpFBM.m_nStrideInBytes[0]] = 0;
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[1][m * TmpFBM.m_nStrideInBytes[1] + k * TmpFBM.m_nRowStrideInBytes[1]] = 0;
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[2][m * TmpFBM.m_nStrideInBytes[2] + k * TmpFBM.m_nRowStrideInBytes[2]] = 0;
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[3][m * TmpFBM.m_nStrideInBytes[3] + k * TmpFBM.m_nRowStrideInBytes[3]] = 0;
      }
      else
      {
        X = (float)((float)(1.0 / v3) * v23) * 255.0;
        if ( ceil(X) <= 255.0 )
          v27 = ceil(X);
        else
          v27 = 255.0;
        v3 = overbright;
        v28 = (float)(int)v27;
        *(float *)&TmpFBM.m_pAttributePtrs[3][m * TmpFBM.m_nStrideInBytes[3] + k * TmpFBM.m_nRowStrideInBytes[3]] = v28;
        v29 = overbright * 0.00392156862745098 * (double)(int)v28;
        *(float *)&TmpFBM.m_pAttributePtrs[0][k * TmpFBM.m_nRowStrideInBytes[0] + m * TmpFBM.m_nStrideInBytes[0]] = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]] * (float)(1.0 / v29);
        *(float *)&TmpFBM.m_pAttributePtrs[1][m * TmpFBM.m_nStrideInBytes[1] + k * TmpFBM.m_nRowStrideInBytes[1]] = *(float *)&this->m_pAttributePtrs[1][k * this->m_nRowStrideInBytes[1] + m * this->m_nStrideInBytes[1]] * (float)(1.0 / v29);
        *(float *)&TmpFBM.m_pAttributePtrs[2][m * TmpFBM.m_nStrideInBytes[2] + k * TmpFBM.m_nRowStrideInBytes[2]] = *(float *)&this->m_pAttributePtrs[2][k * this->m_nRowStrideInBytes[2] + m * this->m_nStrideInBytes[2]] * (float)(1.0 / v29);
      }
    }
  }
  CSOAContainer::CopyAttrFrom(
    this,
    other: (CFunctor_vtbl *)&TmpFBM,
    nDestAttributeIndex: 0,
    nSrcAttributeIndex: (CFunctor_vtbl *)0xFFFFFFFF);
  CSOAContainer::CopyAttrFrom(
    this,
    other: (CFunctor_vtbl *)&TmpFBM,
    nDestAttributeIndex: 1u,
    nSrcAttributeIndex: (CFunctor_vtbl *)0xFFFFFFFF);
  CSOAContainer::CopyAttrFrom(
    this,
    other: (CFunctor_vtbl *)&TmpFBM,
    nDestAttributeIndex: 2u,
    nSrcAttributeIndex: (CFunctor_vtbl *)0xFFFFFFFF);
  CSOAContainer::CopyAttrFrom(
    this,
    other: (CFunctor_vtbl *)&TmpFBM,
    nDestAttributeIndex: 3u,
    nSrcAttributeIndex: (CFunctor_vtbl *)0xFFFFFFFF);
  v30 = 0;
  if ( this->m_nRows > 0 )
  {
    m_nColumns = this->m_nColumns;
    do
    {
      v32 = 0;
      if ( m_nColumns > 0 )
      {
        do
        {
          v33 = v30 * this->m_nRowStrideInBytes[3] + v32 * this->m_nStrideInBytes[3];
          *(float *)&this->m_pAttributePtrs[3][v33] = *(float *)&this->m_pAttributePtrs[3][v33] * 0.00392156862745098;
          m_nColumns = this->m_nColumns;
          ++v32;
        }
        while ( v32 < this->m_nColumns );
      }
      ++v30;
    }
    while ( v30 < this->m_nRows );
  }
  CSOAContainer::~CSOAContainer(this: &TmpFBM);
}

//------------------------------------------------------------------------------
// Address: 0x00441E90
// Name: bool SupportsSSE2(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
bool __cdecl SupportsSSE2()
{
  return IsProcessorFeaturePresent(ProcessorFeature: 0xAu);
}

//------------------------------------------------------------------------------
// Address: 0x004421D0
// Name: unsigned long CalcBufferSize(enum _CodecType,unsigned long,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl CalcBufferSize(int a1, int a2, int a3)
{
  int v3; // eax
  unsigned int result; // eax

  switch ( a1 )
  {
    case 2:
    case 11:
      v3 = 1;
      goto LABEL_4;
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 12:
    case 13:
    case 14:
      v3 = 2;
LABEL_4:
      result = (4 * 4 * ((unsigned int)(a3 + 3) >> 2) * 4 * ((unsigned int)(a2 + 3) >> 2) * v3) >> 3;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00442240
// Name: unsigned char DeriveB(unsigned char,unsigned char)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 __cdecl DeriveB(unsigned __int8 a1, unsigned __int8 a2)
{
  double v2; // st6
  double v3; // st7
  float v5; // [esp+0h] [ebp-4h]
  float v6; // [esp+8h] [ebp+4h]
  float v7; // [esp+8h] [ebp+4h]
  float v8; // [esp+8h] [ebp+4h]
  float v9; // [esp+8h] [ebp+4h]
  float v10; // [esp+8h] [ebp+4h]
  float v11; // [esp+8h] [ebp+4h]
  float v12; // [esp+8h] [ebp+4h]
  float v13; // [esp+8h] [ebp+4h]
  float v14; // [esp+8h] [ebp+4h]
  float v15; // [esp+8h] [ebp+4h]

  v6 = (double)a1 / 255.0;
  v7 = v6 * 2.0;
  v5 = v7 - 1.0;
  v8 = (double)a2 / 255.0;
  v9 = 2.0 * v8;
  v10 = v9 - 1.0;
  v2 = v10 * v10 + v5 * v5;
  if ( v2 >= 1.0 )
    v2 = 1.0;
  v11 = v2;
  v12 = 1.0 - v11;
  v13 = sqrt(v12);
  v14 = v13 * 127.0;
  v15 = v14 + 128.0;
  if ( v15 < 255.0 )
  {
    v3 = 0.0;
    if ( v15 > 0.0 )
      return (int)v15;
  }
  else
  {
    v3 = 255.0;
  }
  return (int)(float)v3;
}

//------------------------------------------------------------------------------
// Address: 0x00442350
// Name: float DeriveB(float,float)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl DeriveB(float a1, float a2)
{
  double v2; // st6
  float v4; // [esp+0h] [ebp-4h]
  float v5; // [esp+8h] [ebp+4h]
  float v6; // [esp+8h] [ebp+4h]
  float v7; // [esp+8h] [ebp+4h]
  float v8; // [esp+8h] [ebp+4h]
  float v9; // [esp+8h] [ebp+4h]
  float v10; // [esp+8h] [ebp+4h]
  float v11; // [esp+8h] [ebp+4h]

  v5 = a1 * 2.0;
  v4 = v5 - 1.0;
  v6 = 2.0 * a2;
  v7 = v6 - 1.0;
  v2 = v7 * v7 + v4 * v4;
  if ( v2 >= 1.0 )
    v2 = 1.0;
  v8 = v2;
  v9 = 1.0 - v8;
  v10 = sqrt(v9);
  v11 = v10 + 1.0;
  return (float)(v11 * 0.5);
}

//------------------------------------------------------------------------------
// Address: 0x00442400
// Name: public: half::half(float)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
half *__thiscall half::half(half *this, int a2)
{
  if ( *(float *)&a2 == 0.0 )
  {
    *(_WORD *)this = 0;
    return this;
  }
  else
  {
    if ( *((_WORD *)&half::_eLut + ((unsigned int)a2 >> 23)) != 0 )
      *(_WORD *)this = *((_WORD *)&half::_eLut + ((unsigned int)a2 >> 23)) + (((a2 & 0x7FFFFFu) + 4096) >> 13);
    else
      *(_WORD *)this = half::convert(a1: a2);
    return this;
  }
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x0068AA40
// Name: public: void FloatBitMap_t::CompressTo8Bits(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::CompressTo8Bits(FloatBitMap_t *this, float overbright)
{
  float v3; // xmm2_4
  int i; // ecx
  int j; // eax
  unsigned int v6; // edx
  unsigned __int8 *v7; // edi
  float v8; // xmm0_4
  unsigned int v9; // edx
  unsigned __int8 *v10; // edi
  float v11; // xmm0_4
  unsigned int v12; // edx
  unsigned __int8 *v13; // edi
  float v14; // xmm0_4
  int k; // ebx
  int m; // edi
  float v17; // xmm1_4
  unsigned __int8 *v18; // edx
  unsigned int v19; // eax
  float v20; // xmm0_4
  float v21; // xmm4_4
  unsigned __int8 *v22; // edx
  unsigned int v23; // eax
  double v24; // xmm0_8
  float v25; // xmm0_4
  float v26; // xmm1_4
  int v27; // edx
  int m_nColumns; // ecx
  int v29; // eax
  unsigned int v30; // ecx
  FloatBitMap_t TmpFBM; // [esp+14h] [ebp-334h] BYREF
  double X; // [esp+338h] [ebp-10h]
  double v33; // [esp+340h] [ebp-8h]
  int savedregs; // [esp+348h] [ebp+0h] BYREF

  FloatBitMap_t::FloatBitMap_t(
    this: &TmpFBM,
    nWidth: (unsigned __int8 *)this->m_nColumns,
    nHeight: (unsigned __int8 *)this->m_nRows,
    nDepth: 1,
    nAttributeMask: 15);
  v3 = overbright;
  for ( i = 0; i < this->m_nRows; ++i )
  {
    for ( j = 0; j < this->m_nColumns; *(float *)&v13[v12] = v14 )
    {
      v6 = i * this->m_nRowStrideInBytes[0] + j * this->m_nStrideInBytes[0];
      v7 = this->m_pAttributePtrs[0];
      v8 = *(float *)&v7[v6];
      if ( v8 > overbright )
        v8 = overbright;
      *(float *)&v7[v6] = v8;
      v9 = i * this->m_nRowStrideInBytes[1] + j * this->m_nStrideInBytes[1];
      v10 = this->m_pAttributePtrs[1];
      v11 = *(float *)&v10[v9];
      if ( v11 > overbright )
        v11 = overbright;
      *(float *)&v10[v9] = v11;
      v12 = i * this->m_nRowStrideInBytes[2] + j * this->m_nStrideInBytes[2];
      v13 = this->m_pAttributePtrs[2];
      v14 = *(float *)&v13[v12];
      if ( v14 > overbright )
        v14 = overbright;
      ++j;
    }
  }
  for ( k = 0; k < this->m_nRows; ++k )
  {
    for ( m = 0; m < this->m_nColumns; ++m )
    {
      v17 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      v18 = this->m_pAttributePtrs[1];
      v19 = k * this->m_nRowStrideInBytes[1] + m * this->m_nStrideInBytes[1];
      v20 = *(float *)&v18[v19];
      if ( v17 <= v20 )
        v21 = *(float *)&v18[v19];
      else
        v21 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      v22 = this->m_pAttributePtrs[2];
      v23 = k * this->m_nRowStrideInBytes[2] + m * this->m_nStrideInBytes[2];
      if ( v21 <= *(float *)&v22[v23] )
      {
        v20 = *(float *)&v22[v23];
      }
      else if ( v17 > v20 )
      {
        v20 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      }
      if ( v20 == 0.0 )
      {
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[0][k * TmpFBM.m_nRowStrideInBytes[0] + m * TmpFBM.m_nStrideInBytes[0]] = 0;
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[1][m * TmpFBM.m_nStrideInBytes[1] + k * TmpFBM.m_nRowStrideInBytes[1]] = 0;
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[2][m * TmpFBM.m_nStrideInBytes[2] + k * TmpFBM.m_nRowStrideInBytes[2]] = 0;
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[3][m * TmpFBM.m_nStrideInBytes[3] + k * TmpFBM.m_nRowStrideInBytes[3]] = 0;
      }
      else
      {
        X = (float)(1.0 / v3 * v20) * 255.0;
        if ( ceil(X) <= 255.0 )
        {
          v33 = ceil(X);
          v24 = v33;
        }
        else
        {
          v24 = 255.0;
        }
        v3 = overbright;
        v25 = (float)(int)v24;
        *(float *)&TmpFBM.m_pAttributePtrs[3][m * TmpFBM.m_nStrideInBytes[3] + k * TmpFBM.m_nRowStrideInBytes[3]] = v25;
        v26 = overbright * 0.00392156862745098 * (double)(int)v25;
        *(float *)&TmpFBM.m_pAttributePtrs[0][k * TmpFBM.m_nRowStrideInBytes[0] + m * TmpFBM.m_nStrideInBytes[0]] = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]] * (float)(1.0 / v26);
        *(float *)&TmpFBM.m_pAttributePtrs[1][m * TmpFBM.m_nStrideInBytes[1] + k * TmpFBM.m_nRowStrideInBytes[1]] = *(float *)&this->m_pAttributePtrs[1][k * this->m_nRowStrideInBytes[1] + m * this->m_nStrideInBytes[1]] * (float)(1.0 / v26);
        *(float *)&TmpFBM.m_pAttributePtrs[2][m * TmpFBM.m_nStrideInBytes[2] + k * TmpFBM.m_nRowStrideInBytes[2]] = *(float *)&this->m_pAttributePtrs[2][k * this->m_nRowStrideInBytes[2] + m * this->m_nStrideInBytes[2]] * (float)(1.0 / v26);
      }
    }
  }
  CSOAContainer::CopyAttrFrom(
    this,
    a2: (unsigned int)&savedregs,
    other: (CFunctor_vtbl *)&TmpFBM,
    nDestAttributeIndex: 0,
    nSrcAttributeIndex: (CFunctor_vtbl *)0xFFFFFFFF);
  CSOAContainer::CopyAttrFrom(
    this,
    a2: (unsigned int)&savedregs,
    other: (CFunctor_vtbl *)&TmpFBM,
    nDestAttributeIndex: 1u,
    nSrcAttributeIndex: (CFunctor_vtbl *)0xFFFFFFFF);
  CSOAContainer::CopyAttrFrom(
    this,
    a2: (unsigned int)&savedregs,
    other: (CFunctor_vtbl *)&TmpFBM,
    nDestAttributeIndex: 2u,
    nSrcAttributeIndex: (CFunctor_vtbl *)0xFFFFFFFF);
  CSOAContainer::CopyAttrFrom(
    this,
    a2: (unsigned int)&savedregs,
    other: (CFunctor_vtbl *)&TmpFBM,
    nDestAttributeIndex: 3u,
    nSrcAttributeIndex: (CFunctor_vtbl *)0xFFFFFFFF);
  v27 = 0;
  if ( this->m_nRows > 0 )
  {
    m_nColumns = this->m_nColumns;
    do
    {
      v29 = 0;
      if ( m_nColumns > 0 )
      {
        do
        {
          v30 = v27 * this->m_nRowStrideInBytes[3] + v29 * this->m_nStrideInBytes[3];
          *(float *)&this->m_pAttributePtrs[3][v30] = *(float *)&this->m_pAttributePtrs[3][v30] * 0.00392156862745098;
          m_nColumns = this->m_nColumns;
          ++v29;
        }
        while ( v29 < this->m_nColumns );
      }
      ++v27;
    }
    while ( v27 < this->m_nRows );
  }
  CSOAContainer::~CSOAContainer(this: &TmpFBM);
}

//------------------------------------------------------------------------------
// Address: 0x0068AEF0
// Name: bool SupportsSSE2(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
bool __cdecl SupportsSSE2()
{
  return IsProcessorFeaturePresent(ProcessorFeature: 0xAu);
}

//------------------------------------------------------------------------------
// Address: 0x0068B230
// Name: unsigned long CalcBufferSize(enum _CodecType,unsigned long,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl CalcBufferSize(int a1, int a2, int a3)
{
  int v3; // eax
  unsigned int result; // eax

  switch ( a1 )
  {
    case 2:
    case 11:
      v3 = 1;
      goto LABEL_4;
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 12:
    case 13:
    case 14:
      v3 = 2;
LABEL_4:
      result = (4 * 4 * ((unsigned int)(a3 + 3) >> 2) * 4 * ((unsigned int)(a2 + 3) >> 2) * v3) >> 3;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0068B2A0
// Name: unsigned char DeriveB(unsigned char,unsigned char)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 __cdecl DeriveB(unsigned __int8 a1, unsigned __int8 a2)
{
  double v2; // st6
  double v3; // st7
  float v5; // [esp+0h] [ebp-4h]
  float v6; // [esp+8h] [ebp+4h]
  float v7; // [esp+8h] [ebp+4h]
  float v8; // [esp+8h] [ebp+4h]
  float v9; // [esp+8h] [ebp+4h]
  float v10; // [esp+8h] [ebp+4h]
  float v11; // [esp+8h] [ebp+4h]
  float v12; // [esp+8h] [ebp+4h]
  float v13; // [esp+8h] [ebp+4h]
  float v14; // [esp+8h] [ebp+4h]
  float v15; // [esp+8h] [ebp+4h]

  v6 = (double)a1 / 255.0;
  v7 = v6 * 2.0;
  v5 = v7 - 1.0;
  v8 = (double)a2 / 255.0;
  v9 = 2.0 * v8;
  v10 = v9 - 1.0;
  v2 = v10 * v10 + v5 * v5;
  if ( v2 >= 1.0 )
    v2 = 1.0;
  v11 = v2;
  v12 = 1.0 - v11;
  v13 = sqrt(v12);
  v14 = v13 * 127.0;
  v15 = v14 + 128.0;
  if ( v15 < 255.0 )
  {
    v3 = 0.0;
    if ( v15 > 0.0 )
      return (int)v15;
  }
  else
  {
    v3 = 255.0;
  }
  return (int)(float)v3;
}

//------------------------------------------------------------------------------
// Address: 0x0068B3B0
// Name: float DeriveB(float,float)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl DeriveB(float a1, float a2)
{
  double v2; // st6
  float v4; // [esp+0h] [ebp-4h]
  float v5; // [esp+8h] [ebp+4h]
  float v6; // [esp+8h] [ebp+4h]
  float v7; // [esp+8h] [ebp+4h]
  float v8; // [esp+8h] [ebp+4h]
  float v9; // [esp+8h] [ebp+4h]
  float v10; // [esp+8h] [ebp+4h]
  float v11; // [esp+8h] [ebp+4h]

  v5 = a1 * 2.0;
  v4 = v5 - 1.0;
  v6 = 2.0 * a2;
  v7 = v6 - 1.0;
  v2 = v7 * v7 + v4 * v4;
  if ( v2 >= 1.0 )
    v2 = 1.0;
  v8 = v2;
  v9 = 1.0 - v8;
  v10 = sqrt(v9);
  v11 = v10 + 1.0;
  return (float)(v11 * 0.5);
}

//------------------------------------------------------------------------------
// Address: 0x0068B460
// Name: public: half::half(float)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
half *__thiscall half::half(half *this, int a2)
{
  if ( *(float *)&a2 == 0.0 )
  {
    *(_WORD *)this = 0;
    return this;
  }
  else
  {
    if ( *((_WORD *)&half::_eLut + ((unsigned int)a2 >> 23)) != 0 )
      *(_WORD *)this = *((_WORD *)&half::_eLut + ((unsigned int)a2 >> 23)) + (((a2 & 0x7FFFFFu) + 4096) >> 13);
    else
      *(_WORD *)this = half::convert(a1: a2);
    return this;
  }
}

} // namespace vmap

// ============================================================
// Overlay from vrad_dll (Missing functions)
// ============================================================
namespace vrad_dll {

//------------------------------------------------------------------------------
// Address: 0x10056620
// Name: public: void FloatBitMap_t::CompressTo8Bits(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::CompressTo8Bits(FloatBitMap_t *this, float overbright)
{
  float v3; // xmm2_4
  int i; // ecx
  int j; // eax
  unsigned int v6; // edx
  unsigned __int8 *v7; // edi
  float v8; // xmm0_4
  unsigned int v9; // edx
  unsigned __int8 *v10; // edi
  float v11; // xmm0_4
  unsigned int v12; // edx
  unsigned __int8 *v13; // edi
  float v14; // xmm0_4
  int k; // ebx
  int m; // edi
  float v17; // xmm1_4
  unsigned __int8 *v18; // edx
  unsigned int v19; // eax
  float v20; // xmm0_4
  float v21; // xmm4_4
  unsigned __int8 *v22; // edx
  unsigned int v23; // eax
  double v24; // xmm0_8
  float v25; // xmm0_4
  float v26; // xmm1_4
  int v27; // edx
  int m_nColumns; // ecx
  int v29; // eax
  unsigned int v30; // ecx
  FloatBitMap_t TmpFBM; // [esp+14h] [ebp-334h] BYREF
  double X; // [esp+338h] [ebp-10h]
  double v33; // [esp+340h] [ebp-8h]

  FloatBitMap_t::FloatBitMap_t(
    this: &TmpFBM,
    nWidth: this->m_nColumns,
    nHeight: this->m_nRows,
    nDepth: 1,
    nAttributeMask: 15);
  v3 = overbright;
  for ( i = 0; i < this->m_nRows; ++i )
  {
    for ( j = 0; j < this->m_nColumns; *(float *)&v13[v12] = v14 )
    {
      v6 = i * this->m_nRowStrideInBytes[0] + j * this->m_nStrideInBytes[0];
      v7 = this->m_pAttributePtrs[0];
      v8 = *(float *)&v7[v6];
      if ( v8 > overbright )
        v8 = overbright;
      *(float *)&v7[v6] = v8;
      v9 = i * this->m_nRowStrideInBytes[1] + j * this->m_nStrideInBytes[1];
      v10 = this->m_pAttributePtrs[1];
      v11 = *(float *)&v10[v9];
      if ( v11 > overbright )
        v11 = overbright;
      *(float *)&v10[v9] = v11;
      v12 = i * this->m_nRowStrideInBytes[2] + j * this->m_nStrideInBytes[2];
      v13 = this->m_pAttributePtrs[2];
      v14 = *(float *)&v13[v12];
      if ( v14 > overbright )
        v14 = overbright;
      ++j;
    }
  }
  for ( k = 0; k < this->m_nRows; ++k )
  {
    for ( m = 0; m < this->m_nColumns; ++m )
    {
      v17 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      v18 = this->m_pAttributePtrs[1];
      v19 = k * this->m_nRowStrideInBytes[1] + m * this->m_nStrideInBytes[1];
      v20 = *(float *)&v18[v19];
      if ( v17 <= v20 )
        v21 = *(float *)&v18[v19];
      else
        v21 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      v22 = this->m_pAttributePtrs[2];
      v23 = k * this->m_nRowStrideInBytes[2] + m * this->m_nStrideInBytes[2];
      if ( v21 <= *(float *)&v22[v23] )
      {
        v20 = *(float *)&v22[v23];
      }
      else if ( v17 > v20 )
      {
        v20 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      }
      if ( v20 == 0.0 )
      {
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[0][k * TmpFBM.m_nRowStrideInBytes[0] + m * TmpFBM.m_nStrideInBytes[0]] = 0;
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[1][m * TmpFBM.m_nStrideInBytes[1] + k * TmpFBM.m_nRowStrideInBytes[1]] = 0;
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[2][m * TmpFBM.m_nStrideInBytes[2] + k * TmpFBM.m_nRowStrideInBytes[2]] = 0;
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[3][m * TmpFBM.m_nStrideInBytes[3] + k * TmpFBM.m_nRowStrideInBytes[3]] = 0;
      }
      else
      {
        X = (float)(1.0 / v3 * v20) * 255.0;
        if ( ceil(X) <= 255.0 )
        {
          v33 = ceil(X);
          v24 = v33;
        }
        else
        {
          v24 = 255.0;
        }
        v3 = overbright;
        v25 = (float)(int)v24;
        *(float *)&TmpFBM.m_pAttributePtrs[3][m * TmpFBM.m_nStrideInBytes[3] + k * TmpFBM.m_nRowStrideInBytes[3]] = v25;
        v26 = overbright * 0.00392156862745098 * (double)(int)v25;
        *(float *)&TmpFBM.m_pAttributePtrs[0][k * TmpFBM.m_nRowStrideInBytes[0] + m * TmpFBM.m_nStrideInBytes[0]] = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]] * (float)(1.0 / v26);
        *(float *)&TmpFBM.m_pAttributePtrs[1][m * TmpFBM.m_nStrideInBytes[1] + k * TmpFBM.m_nRowStrideInBytes[1]] = *(float *)&this->m_pAttributePtrs[1][k * this->m_nRowStrideInBytes[1] + m * this->m_nStrideInBytes[1]] * (float)(1.0 / v26);
        *(float *)&TmpFBM.m_pAttributePtrs[2][m * TmpFBM.m_nStrideInBytes[2] + k * TmpFBM.m_nRowStrideInBytes[2]] = *(float *)&this->m_pAttributePtrs[2][k * this->m_nRowStrideInBytes[2] + m * this->m_nStrideInBytes[2]] * (float)(1.0 / v26);
      }
    }
  }
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 0, nSrcAttributeIndex: -1);
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 1, nSrcAttributeIndex: -1);
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 2, nSrcAttributeIndex: -1);
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 3, nSrcAttributeIndex: -1);
  v27 = 0;
  if ( this->m_nRows > 0 )
  {
    m_nColumns = this->m_nColumns;
    do
    {
      v29 = 0;
      if ( m_nColumns > 0 )
      {
        do
        {
          v30 = v27 * this->m_nRowStrideInBytes[3] + v29 * this->m_nStrideInBytes[3];
          *(float *)&this->m_pAttributePtrs[3][v30] = *(float *)&this->m_pAttributePtrs[3][v30] * 0.00392156862745098;
          m_nColumns = this->m_nColumns;
          ++v29;
        }
        while ( v29 < this->m_nColumns );
      }
      ++v27;
    }
    while ( v27 < this->m_nRows );
  }
  CSOAContainer::~CSOAContainer(this: &TmpFBM);
}

//------------------------------------------------------------------------------
// Address: 0x10056AD0
// Name: bool SupportsSSE2(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
bool __cdecl SupportsSSE2()
{
  return IsProcessorFeaturePresent(ProcessorFeature: 0xAu);
}

//------------------------------------------------------------------------------
// Address: 0x10056E10
// Name: unsigned long CalcBufferSize(enum _CodecType,unsigned long,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl CalcBufferSize(int a1, int a2, int a3)
{
  int v3; // eax
  unsigned int result; // eax

  switch ( a1 )
  {
    case 2:
    case 11:
      v3 = 1;
      goto LABEL_4;
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 12:
    case 13:
    case 14:
      v3 = 2;
LABEL_4:
      result = (4 * 4 * ((unsigned int)(a3 + 3) >> 2) * 4 * ((unsigned int)(a2 + 3) >> 2) * v3) >> 3;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10056E80
// Name: unsigned char DeriveB(unsigned char,unsigned char)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 __cdecl DeriveB(unsigned __int8 a1, unsigned __int8 a2)
{
  double v2; // st6
  double v3; // st7
  float v5; // [esp+0h] [ebp-4h]
  float v6; // [esp+8h] [ebp+4h]
  float v7; // [esp+8h] [ebp+4h]
  float v8; // [esp+8h] [ebp+4h]
  float v9; // [esp+8h] [ebp+4h]
  float v10; // [esp+8h] [ebp+4h]
  float v11; // [esp+8h] [ebp+4h]
  float v12; // [esp+8h] [ebp+4h]
  float v13; // [esp+8h] [ebp+4h]
  float v14; // [esp+8h] [ebp+4h]
  float v15; // [esp+8h] [ebp+4h]

  v6 = (double)a1 / 255.0;
  v7 = v6 * 2.0;
  v5 = v7 - 1.0;
  v8 = (double)a2 / 255.0;
  v9 = 2.0 * v8;
  v10 = v9 - 1.0;
  v2 = v10 * v10 + v5 * v5;
  if ( v2 >= 1.0 )
    v2 = 1.0;
  v11 = v2;
  v12 = 1.0 - v11;
  v13 = sqrt(v12);
  v14 = v13 * 127.0;
  v15 = v14 + 128.0;
  if ( v15 < 255.0 )
  {
    v3 = 0.0;
    if ( v15 > 0.0 )
      return (int)v15;
  }
  else
  {
    v3 = 255.0;
  }
  return (int)(float)v3;
}

//------------------------------------------------------------------------------
// Address: 0x10056F90
// Name: float DeriveB(float,float)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl DeriveB(float a1, float a2)
{
  double v2; // st6
  float v4; // [esp+0h] [ebp-4h]
  float v5; // [esp+8h] [ebp+4h]
  float v6; // [esp+8h] [ebp+4h]
  float v7; // [esp+8h] [ebp+4h]
  float v8; // [esp+8h] [ebp+4h]
  float v9; // [esp+8h] [ebp+4h]
  float v10; // [esp+8h] [ebp+4h]
  float v11; // [esp+8h] [ebp+4h]

  v5 = a1 * 2.0;
  v4 = v5 - 1.0;
  v6 = 2.0 * a2;
  v7 = v6 - 1.0;
  v2 = v7 * v7 + v4 * v4;
  if ( v2 >= 1.0 )
    v2 = 1.0;
  v8 = v2;
  v9 = 1.0 - v8;
  v10 = sqrt(v9);
  v11 = v10 + 1.0;
  return (float)(v11 * 0.5);
}

} // namespace vrad_dll

// ============================================================
// Overlay from vtex_dll (Missing functions)
// ============================================================
namespace vtex_dll {

//------------------------------------------------------------------------------
// Address: 0x1001CE30
// Name: public: void FloatBitMap_t::CompressTo8Bits(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::CompressTo8Bits(FloatBitMap_t *this, float overbright)
{
  float v3; // xmm2_4
  int i; // ecx
  int j; // eax
  unsigned int v6; // edx
  unsigned __int8 *v7; // edi
  float v8; // xmm0_4
  unsigned int v9; // edx
  unsigned __int8 *v10; // edi
  float v11; // xmm0_4
  unsigned int v12; // edx
  unsigned __int8 *v13; // edi
  float v14; // xmm0_4
  int k; // ebx
  int m; // edi
  float v17; // xmm1_4
  unsigned __int8 *v18; // edx
  unsigned int v19; // eax
  float v20; // xmm0_4
  float v21; // xmm4_4
  unsigned __int8 *v22; // edx
  unsigned int v23; // eax
  double v24; // xmm0_8
  float v25; // xmm0_4
  float v26; // xmm1_4
  int v27; // edx
  int m_nColumns; // ecx
  int v29; // eax
  unsigned int v30; // ecx
  FloatBitMap_t TmpFBM; // [esp+14h] [ebp-334h] BYREF
  double X; // [esp+338h] [ebp-10h]
  double v33; // [esp+340h] [ebp-8h]
  int savedregs; // [esp+348h] [ebp+0h] BYREF

  FloatBitMap_t::FloatBitMap_t(
    this: &TmpFBM,
    nWidth: this->m_nColumns,
    nHeight: this->m_nRows,
    nDepth: 1,
    nAttributeMask: 15);
  v3 = overbright;
  for ( i = 0; i < this->m_nRows; ++i )
  {
    for ( j = 0; j < this->m_nColumns; *(float *)&v13[v12] = v14 )
    {
      v6 = i * this->m_nRowStrideInBytes[0] + j * this->m_nStrideInBytes[0];
      v7 = this->m_pAttributePtrs[0];
      v8 = *(float *)&v7[v6];
      if ( v8 > overbright )
        v8 = overbright;
      *(float *)&v7[v6] = v8;
      v9 = i * this->m_nRowStrideInBytes[1] + j * this->m_nStrideInBytes[1];
      v10 = this->m_pAttributePtrs[1];
      v11 = *(float *)&v10[v9];
      if ( v11 > overbright )
        v11 = overbright;
      *(float *)&v10[v9] = v11;
      v12 = i * this->m_nRowStrideInBytes[2] + j * this->m_nStrideInBytes[2];
      v13 = this->m_pAttributePtrs[2];
      v14 = *(float *)&v13[v12];
      if ( v14 > overbright )
        v14 = overbright;
      ++j;
    }
  }
  for ( k = 0; k < this->m_nRows; ++k )
  {
    for ( m = 0; m < this->m_nColumns; ++m )
    {
      v17 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      v18 = this->m_pAttributePtrs[1];
      v19 = k * this->m_nRowStrideInBytes[1] + m * this->m_nStrideInBytes[1];
      v20 = *(float *)&v18[v19];
      if ( v17 <= v20 )
        v21 = *(float *)&v18[v19];
      else
        v21 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      v22 = this->m_pAttributePtrs[2];
      v23 = k * this->m_nRowStrideInBytes[2] + m * this->m_nStrideInBytes[2];
      if ( v21 <= *(float *)&v22[v23] )
      {
        v20 = *(float *)&v22[v23];
      }
      else if ( v17 > v20 )
      {
        v20 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      }
      if ( v20 == 0.0 )
      {
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[0][k * TmpFBM.m_nRowStrideInBytes[0] + m * TmpFBM.m_nStrideInBytes[0]] = 0;
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[1][m * TmpFBM.m_nStrideInBytes[1] + k * TmpFBM.m_nRowStrideInBytes[1]] = 0;
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[2][m * TmpFBM.m_nStrideInBytes[2] + k * TmpFBM.m_nRowStrideInBytes[2]] = 0;
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[3][m * TmpFBM.m_nStrideInBytes[3] + k * TmpFBM.m_nRowStrideInBytes[3]] = 0;
      }
      else
      {
        X = (float)(1.0 / v3 * v20) * 255.0;
        if ( ceil(X) <= 255.0 )
        {
          v33 = ceil(X);
          v24 = v33;
        }
        else
        {
          v24 = 255.0;
        }
        v3 = overbright;
        v25 = (float)(int)v24;
        *(float *)&TmpFBM.m_pAttributePtrs[3][m * TmpFBM.m_nStrideInBytes[3] + k * TmpFBM.m_nRowStrideInBytes[3]] = v25;
        v26 = overbright * 0.00392156862745098 * (double)(int)v25;
        *(float *)&TmpFBM.m_pAttributePtrs[0][k * TmpFBM.m_nRowStrideInBytes[0] + m * TmpFBM.m_nStrideInBytes[0]] = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]] * (float)(1.0 / v26);
        *(float *)&TmpFBM.m_pAttributePtrs[1][m * TmpFBM.m_nStrideInBytes[1] + k * TmpFBM.m_nRowStrideInBytes[1]] = *(float *)&this->m_pAttributePtrs[1][k * this->m_nRowStrideInBytes[1] + m * this->m_nStrideInBytes[1]] * (float)(1.0 / v26);
        *(float *)&TmpFBM.m_pAttributePtrs[2][m * TmpFBM.m_nStrideInBytes[2] + k * TmpFBM.m_nRowStrideInBytes[2]] = *(float *)&this->m_pAttributePtrs[2][k * this->m_nRowStrideInBytes[2] + m * this->m_nStrideInBytes[2]] * (float)(1.0 / v26);
      }
    }
  }
  CSOAContainer::CopyAttrFrom(
    this,
    a2: (unsigned int)&savedregs,
    other: (CFunctor_vtbl *)&TmpFBM,
    nDestAttributeIndex: 0,
    nSrcAttributeIndex: (CFunctor_vtbl *)0xFFFFFFFF);
  CSOAContainer::CopyAttrFrom(
    this,
    a2: (unsigned int)&savedregs,
    other: (CFunctor_vtbl *)&TmpFBM,
    nDestAttributeIndex: 1u,
    nSrcAttributeIndex: (CFunctor_vtbl *)0xFFFFFFFF);
  CSOAContainer::CopyAttrFrom(
    this,
    a2: (unsigned int)&savedregs,
    other: (CFunctor_vtbl *)&TmpFBM,
    nDestAttributeIndex: 2u,
    nSrcAttributeIndex: (CFunctor_vtbl *)0xFFFFFFFF);
  CSOAContainer::CopyAttrFrom(
    this,
    a2: (unsigned int)&savedregs,
    other: (CFunctor_vtbl *)&TmpFBM,
    nDestAttributeIndex: 3u,
    nSrcAttributeIndex: (CFunctor_vtbl *)0xFFFFFFFF);
  v27 = 0;
  if ( this->m_nRows > 0 )
  {
    m_nColumns = this->m_nColumns;
    do
    {
      v29 = 0;
      if ( m_nColumns > 0 )
      {
        do
        {
          v30 = v27 * this->m_nRowStrideInBytes[3] + v29 * this->m_nStrideInBytes[3];
          *(float *)&this->m_pAttributePtrs[3][v30] = *(float *)&this->m_pAttributePtrs[3][v30] * 0.00392156862745098;
          m_nColumns = this->m_nColumns;
          ++v29;
        }
        while ( v29 < this->m_nColumns );
      }
      ++v27;
    }
    while ( v27 < this->m_nRows );
  }
  CSOAContainer::~CSOAContainer(this: &TmpFBM);
}

//------------------------------------------------------------------------------
// Address: 0x1001D2E0
// Name: bool SupportsSSE2(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
bool __cdecl SupportsSSE2()
{
  return IsProcessorFeaturePresent(ProcessorFeature: 0xAu);
}

//------------------------------------------------------------------------------
// Address: 0x1001D620
// Name: unsigned long CalcBufferSize(enum _CodecType,unsigned long,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl CalcBufferSize(int a1, int a2, int a3)
{
  int v3; // eax
  unsigned int result; // eax

  switch ( a1 )
  {
    case 2:
    case 11:
      v3 = 1;
      goto LABEL_4;
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 12:
    case 13:
    case 14:
      v3 = 2;
LABEL_4:
      result = (4 * 4 * ((unsigned int)(a3 + 3) >> 2) * 4 * ((unsigned int)(a2 + 3) >> 2) * v3) >> 3;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001D690
// Name: unsigned char DeriveB(unsigned char,unsigned char)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 __cdecl DeriveB(unsigned __int8 a1, unsigned __int8 a2)
{
  double v2; // st6
  double v3; // st7
  float v5; // [esp+0h] [ebp-4h]
  float v6; // [esp+8h] [ebp+4h]
  float v7; // [esp+8h] [ebp+4h]
  float v8; // [esp+8h] [ebp+4h]
  float v9; // [esp+8h] [ebp+4h]
  float v10; // [esp+8h] [ebp+4h]
  float v11; // [esp+8h] [ebp+4h]
  float v12; // [esp+8h] [ebp+4h]
  float v13; // [esp+8h] [ebp+4h]
  float v14; // [esp+8h] [ebp+4h]
  float v15; // [esp+8h] [ebp+4h]

  v6 = (double)a1 / 255.0;
  v7 = v6 * 2.0;
  v5 = v7 - 1.0;
  v8 = (double)a2 / 255.0;
  v9 = 2.0 * v8;
  v10 = v9 - 1.0;
  v2 = v10 * v10 + v5 * v5;
  if ( v2 >= 1.0 )
    v2 = 1.0;
  v11 = v2;
  v12 = 1.0 - v11;
  v13 = sqrt(v12);
  v14 = v13 * 127.0;
  v15 = v14 + 128.0;
  if ( v15 < 255.0 )
  {
    v3 = 0.0;
    if ( v15 > 0.0 )
      return (int)v15;
  }
  else
  {
    v3 = 255.0;
  }
  return (int)(float)v3;
}

//------------------------------------------------------------------------------
// Address: 0x1001D7A0
// Name: float DeriveB(float,float)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl DeriveB(float a1, float a2)
{
  double v2; // st6
  float v4; // [esp+0h] [ebp-4h]
  float v5; // [esp+8h] [ebp+4h]
  float v6; // [esp+8h] [ebp+4h]
  float v7; // [esp+8h] [ebp+4h]
  float v8; // [esp+8h] [ebp+4h]
  float v9; // [esp+8h] [ebp+4h]
  float v10; // [esp+8h] [ebp+4h]
  float v11; // [esp+8h] [ebp+4h]

  v5 = a1 * 2.0;
  v4 = v5 - 1.0;
  v6 = 2.0 * a2;
  v7 = v6 - 1.0;
  v2 = v7 * v7 + v4 * v4;
  if ( v2 >= 1.0 )
    v2 = 1.0;
  v8 = v2;
  v9 = 1.0 - v8;
  v10 = sqrt(v9);
  v11 = v10 + 1.0;
  return (float)(v11 * 0.5);
}

//------------------------------------------------------------------------------
// Address: 0x1001D850
// Name: public: half::half(float)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
half *__thiscall half::half(half *this, int a2)
{
  if ( *(float *)&a2 == 0.0 )
  {
    *(_WORD *)this = 0;
    return this;
  }
  else
  {
    if ( *((_WORD *)&half::_eLut + ((unsigned int)a2 >> 23)) != 0 )
      *(_WORD *)this = *((_WORD *)&half::_eLut + ((unsigned int)a2 >> 23)) + (((a2 & 0x7FFFFFu) + 4096) >> 13);
    else
      *(_WORD *)this = half::convert(a1: a2);
    return this;
  }
}

} // namespace vtex_dll

// ============================================================
// Overlay from vtf2tga (Missing functions)
// ============================================================
namespace vtf2tga {

//------------------------------------------------------------------------------
// Address: 0x0040A640
// Name: public: void FloatBitMap_t::CompressTo8Bits(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::CompressTo8Bits(FloatBitMap_t *this, float overbright)
{
  float v3; // xmm2_4
  int i; // ecx
  int j; // eax
  unsigned int v6; // edx
  unsigned __int8 *v7; // edi
  float v8; // xmm0_4
  unsigned int v9; // edx
  unsigned __int8 *v10; // edi
  float v11; // xmm0_4
  unsigned int v12; // edx
  unsigned __int8 *v13; // edi
  float v14; // xmm0_4
  int k; // ebx
  int m; // edi
  float v17; // xmm1_4
  unsigned __int8 *v18; // edx
  unsigned int v19; // eax
  float v20; // xmm0_4
  float v21; // xmm4_4
  unsigned __int8 *v22; // edx
  unsigned int v23; // eax
  double v24; // xmm0_8
  float v25; // xmm0_4
  float v26; // xmm1_4
  int v27; // edx
  int m_nColumns; // ecx
  int v29; // eax
  unsigned int v30; // ecx
  FloatBitMap_t TmpFBM; // [esp+14h] [ebp-334h] BYREF
  double X; // [esp+338h] [ebp-10h]
  double v33; // [esp+340h] [ebp-8h]

  FloatBitMap_t::FloatBitMap_t(
    this: &TmpFBM,
    nWidth: this->m_nColumns,
    nHeight: this->m_nRows,
    nDepth: 1,
    nAttributeMask: 15);
  v3 = overbright;
  for ( i = 0; i < this->m_nRows; ++i )
  {
    for ( j = 0; j < this->m_nColumns; *(float *)&v13[v12] = v14 )
    {
      v6 = i * this->m_nRowStrideInBytes[0] + j * this->m_nStrideInBytes[0];
      v7 = this->m_pAttributePtrs[0];
      v8 = *(float *)&v7[v6];
      if ( v8 > overbright )
        v8 = overbright;
      *(float *)&v7[v6] = v8;
      v9 = i * this->m_nRowStrideInBytes[1] + j * this->m_nStrideInBytes[1];
      v10 = this->m_pAttributePtrs[1];
      v11 = *(float *)&v10[v9];
      if ( v11 > overbright )
        v11 = overbright;
      *(float *)&v10[v9] = v11;
      v12 = i * this->m_nRowStrideInBytes[2] + j * this->m_nStrideInBytes[2];
      v13 = this->m_pAttributePtrs[2];
      v14 = *(float *)&v13[v12];
      if ( v14 > overbright )
        v14 = overbright;
      ++j;
    }
  }
  for ( k = 0; k < this->m_nRows; ++k )
  {
    for ( m = 0; m < this->m_nColumns; ++m )
    {
      v17 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      v18 = this->m_pAttributePtrs[1];
      v19 = k * this->m_nRowStrideInBytes[1] + m * this->m_nStrideInBytes[1];
      v20 = *(float *)&v18[v19];
      if ( v17 <= v20 )
        v21 = *(float *)&v18[v19];
      else
        v21 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      v22 = this->m_pAttributePtrs[2];
      v23 = k * this->m_nRowStrideInBytes[2] + m * this->m_nStrideInBytes[2];
      if ( v21 <= *(float *)&v22[v23] )
      {
        v20 = *(float *)&v22[v23];
      }
      else if ( v17 > v20 )
      {
        v20 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      }
      if ( v20 == 0.0 )
      {
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[0][k * TmpFBM.m_nRowStrideInBytes[0] + m * TmpFBM.m_nStrideInBytes[0]] = 0;
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[1][m * TmpFBM.m_nStrideInBytes[1] + k * TmpFBM.m_nRowStrideInBytes[1]] = 0;
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[2][m * TmpFBM.m_nStrideInBytes[2] + k * TmpFBM.m_nRowStrideInBytes[2]] = 0;
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[3][m * TmpFBM.m_nStrideInBytes[3] + k * TmpFBM.m_nRowStrideInBytes[3]] = 0;
      }
      else
      {
        X = (float)(1.0 / v3 * v20) * 255.0;
        if ( ceil(X) <= 255.0 )
        {
          v33 = ceil(X);
          v24 = v33;
        }
        else
        {
          v24 = 255.0;
        }
        v3 = overbright;
        v25 = (float)(int)v24;
        *(float *)&TmpFBM.m_pAttributePtrs[3][m * TmpFBM.m_nStrideInBytes[3] + k * TmpFBM.m_nRowStrideInBytes[3]] = v25;
        v26 = overbright * 0.00392156862745098 * (double)(int)v25;
        *(float *)&TmpFBM.m_pAttributePtrs[0][k * TmpFBM.m_nRowStrideInBytes[0] + m * TmpFBM.m_nStrideInBytes[0]] = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]] * (float)(1.0 / v26);
        *(float *)&TmpFBM.m_pAttributePtrs[1][m * TmpFBM.m_nStrideInBytes[1] + k * TmpFBM.m_nRowStrideInBytes[1]] = *(float *)&this->m_pAttributePtrs[1][k * this->m_nRowStrideInBytes[1] + m * this->m_nStrideInBytes[1]] * (float)(1.0 / v26);
        *(float *)&TmpFBM.m_pAttributePtrs[2][m * TmpFBM.m_nStrideInBytes[2] + k * TmpFBM.m_nRowStrideInBytes[2]] = *(float *)&this->m_pAttributePtrs[2][k * this->m_nRowStrideInBytes[2] + m * this->m_nStrideInBytes[2]] * (float)(1.0 / v26);
      }
    }
  }
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 0, nSrcAttributeIndex: -1);
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 1, nSrcAttributeIndex: -1);
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 2, nSrcAttributeIndex: -1);
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 3, nSrcAttributeIndex: -1);
  v27 = 0;
  if ( this->m_nRows > 0 )
  {
    m_nColumns = this->m_nColumns;
    do
    {
      v29 = 0;
      if ( m_nColumns > 0 )
      {
        do
        {
          v30 = v27 * this->m_nRowStrideInBytes[3] + v29 * this->m_nStrideInBytes[3];
          *(float *)&this->m_pAttributePtrs[3][v30] = *(float *)&this->m_pAttributePtrs[3][v30] * 0.00392156862745098;
          m_nColumns = this->m_nColumns;
          ++v29;
        }
        while ( v29 < this->m_nColumns );
      }
      ++v27;
    }
    while ( v27 < this->m_nRows );
  }
  CSOAContainer::~CSOAContainer(this: &TmpFBM);
}

//------------------------------------------------------------------------------
// Address: 0x0040AAF0
// Name: bool SupportsSSE2(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
bool __cdecl SupportsSSE2()
{
  return IsProcessorFeaturePresent(ProcessorFeature: 0xAu);
}

//------------------------------------------------------------------------------
// Address: 0x0040AE30
// Name: unsigned long CalcBufferSize(enum _CodecType,unsigned long,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl CalcBufferSize(int a1, int a2, int a3)
{
  int v3; // eax
  unsigned int result; // eax

  switch ( a1 )
  {
    case 2:
    case 11:
      v3 = 1;
      goto LABEL_4;
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 12:
    case 13:
    case 14:
      v3 = 2;
LABEL_4:
      result = (4 * 4 * ((unsigned int)(a3 + 3) >> 2) * 4 * ((unsigned int)(a2 + 3) >> 2) * v3) >> 3;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040AEA0
// Name: unsigned char DeriveB(unsigned char,unsigned char)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 __cdecl DeriveB(unsigned __int8 a1, unsigned __int8 a2)
{
  double v2; // st6
  double v3; // st7
  float v5; // [esp+0h] [ebp-4h]
  float v6; // [esp+8h] [ebp+4h]
  float v7; // [esp+8h] [ebp+4h]
  float v8; // [esp+8h] [ebp+4h]
  float v9; // [esp+8h] [ebp+4h]
  float v10; // [esp+8h] [ebp+4h]
  float v11; // [esp+8h] [ebp+4h]
  float v12; // [esp+8h] [ebp+4h]
  float v13; // [esp+8h] [ebp+4h]
  float v14; // [esp+8h] [ebp+4h]
  float v15; // [esp+8h] [ebp+4h]

  v6 = (double)a1 / 255.0;
  v7 = v6 * 2.0;
  v5 = v7 - 1.0;
  v8 = (double)a2 / 255.0;
  v9 = 2.0 * v8;
  v10 = v9 - 1.0;
  v2 = v10 * v10 + v5 * v5;
  if ( v2 >= 1.0 )
    v2 = 1.0;
  v11 = v2;
  v12 = 1.0 - v11;
  v13 = sqrt(v12);
  v14 = v13 * 127.0;
  v15 = v14 + 128.0;
  if ( v15 < 255.0 )
  {
    v3 = 0.0;
    if ( v15 > 0.0 )
      return (int)v15;
  }
  else
  {
    v3 = 255.0;
  }
  return (int)(float)v3;
}

//------------------------------------------------------------------------------
// Address: 0x0040AFB0
// Name: float DeriveB(float,float)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl DeriveB(float a1, float a2)
{
  double v2; // st6
  float v4; // [esp+0h] [ebp-4h]
  float v5; // [esp+8h] [ebp+4h]
  float v6; // [esp+8h] [ebp+4h]
  float v7; // [esp+8h] [ebp+4h]
  float v8; // [esp+8h] [ebp+4h]
  float v9; // [esp+8h] [ebp+4h]
  float v10; // [esp+8h] [ebp+4h]
  float v11; // [esp+8h] [ebp+4h]

  v5 = a1 * 2.0;
  v4 = v5 - 1.0;
  v6 = 2.0 * a2;
  v7 = v6 - 1.0;
  v2 = v7 * v7 + v4 * v4;
  if ( v2 >= 1.0 )
    v2 = 1.0;
  v8 = v2;
  v9 = 1.0 - v8;
  v10 = sqrt(v9);
  v11 = v10 + 1.0;
  return (float)(v11 * 0.5);
}

//------------------------------------------------------------------------------
// Address: 0x0040B070
// Name: public: half::half(float)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
half *__thiscall half::half(half *this, int a2)
{
  if ( *(float *)&a2 == 0.0 )
  {
    *(_WORD *)this = 0;
    return this;
  }
  else
  {
    if ( *((_WORD *)&half::_eLut + ((unsigned int)a2 >> 23)) != 0 )
      *(_WORD *)this = *((_WORD *)&half::_eLut + ((unsigned int)a2 >> 23)) + (((a2 & 0x7FFFFFu) + 4096) >> 13);
    else
      *(_WORD *)this = half::convert(a1: a2);
    return this;
  }
}

} // namespace vtf2tga

// ============================================================
// Overlay from vtfdiff (Missing functions)
// ============================================================
namespace vtfdiff {

//------------------------------------------------------------------------------
// Address: 0x00424340
// Name: public: void FloatBitMap_t::CompressTo8Bits(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::CompressTo8Bits(FloatBitMap_t *this, float overbright)
{
  float v3; // xmm2_4
  int i; // ecx
  int j; // eax
  unsigned int v6; // edx
  unsigned __int8 *v7; // edi
  float v8; // xmm0_4
  unsigned int v9; // edx
  unsigned __int8 *v10; // edi
  float v11; // xmm0_4
  unsigned int v12; // edx
  unsigned __int8 *v13; // edi
  float v14; // xmm0_4
  int k; // ebx
  int m; // edi
  float v17; // xmm1_4
  unsigned __int8 *v18; // edx
  unsigned int v19; // eax
  float v20; // xmm0_4
  float v21; // xmm4_4
  unsigned __int8 *v22; // edx
  unsigned int v23; // eax
  double v24; // xmm0_8
  float v25; // xmm0_4
  float v26; // xmm1_4
  int v27; // edx
  int m_nColumns; // ecx
  int v29; // eax
  unsigned int v30; // ecx
  FloatBitMap_t TmpFBM; // [esp+14h] [ebp-334h] BYREF
  double X; // [esp+338h] [ebp-10h]
  double v33; // [esp+340h] [ebp-8h]

  FloatBitMap_t::FloatBitMap_t(
    this: &TmpFBM,
    nWidth: this->m_nColumns,
    nHeight: this->m_nRows,
    nDepth: 1,
    nAttributeMask: 15);
  v3 = overbright;
  for ( i = 0; i < this->m_nRows; ++i )
  {
    for ( j = 0; j < this->m_nColumns; *(float *)&v13[v12] = v14 )
    {
      v6 = i * this->m_nRowStrideInBytes[0] + j * this->m_nStrideInBytes[0];
      v7 = this->m_pAttributePtrs[0];
      v8 = *(float *)&v7[v6];
      if ( v8 > overbright )
        v8 = overbright;
      *(float *)&v7[v6] = v8;
      v9 = i * this->m_nRowStrideInBytes[1] + j * this->m_nStrideInBytes[1];
      v10 = this->m_pAttributePtrs[1];
      v11 = *(float *)&v10[v9];
      if ( v11 > overbright )
        v11 = overbright;
      *(float *)&v10[v9] = v11;
      v12 = i * this->m_nRowStrideInBytes[2] + j * this->m_nStrideInBytes[2];
      v13 = this->m_pAttributePtrs[2];
      v14 = *(float *)&v13[v12];
      if ( v14 > overbright )
        v14 = overbright;
      ++j;
    }
  }
  for ( k = 0; k < this->m_nRows; ++k )
  {
    for ( m = 0; m < this->m_nColumns; ++m )
    {
      v17 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      v18 = this->m_pAttributePtrs[1];
      v19 = k * this->m_nRowStrideInBytes[1] + m * this->m_nStrideInBytes[1];
      v20 = *(float *)&v18[v19];
      if ( v17 <= v20 )
        v21 = *(float *)&v18[v19];
      else
        v21 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      v22 = this->m_pAttributePtrs[2];
      v23 = k * this->m_nRowStrideInBytes[2] + m * this->m_nStrideInBytes[2];
      if ( v21 <= *(float *)&v22[v23] )
      {
        v20 = *(float *)&v22[v23];
      }
      else if ( v17 > v20 )
      {
        v20 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      }
      if ( v20 == 0.0 )
      {
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[0][k * TmpFBM.m_nRowStrideInBytes[0] + m * TmpFBM.m_nStrideInBytes[0]] = 0;
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[1][m * TmpFBM.m_nStrideInBytes[1] + k * TmpFBM.m_nRowStrideInBytes[1]] = 0;
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[2][m * TmpFBM.m_nStrideInBytes[2] + k * TmpFBM.m_nRowStrideInBytes[2]] = 0;
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[3][m * TmpFBM.m_nStrideInBytes[3] + k * TmpFBM.m_nRowStrideInBytes[3]] = 0;
      }
      else
      {
        X = (float)(1.0 / v3 * v20) * 255.0;
        if ( ceil(X) <= 255.0 )
        {
          v33 = ceil(X);
          v24 = v33;
        }
        else
        {
          v24 = 255.0;
        }
        v3 = overbright;
        v25 = (float)(int)v24;
        *(float *)&TmpFBM.m_pAttributePtrs[3][m * TmpFBM.m_nStrideInBytes[3] + k * TmpFBM.m_nRowStrideInBytes[3]] = v25;
        v26 = overbright * 0.00392156862745098 * (double)(int)v25;
        *(float *)&TmpFBM.m_pAttributePtrs[0][k * TmpFBM.m_nRowStrideInBytes[0] + m * TmpFBM.m_nStrideInBytes[0]] = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]] * (float)(1.0 / v26);
        *(float *)&TmpFBM.m_pAttributePtrs[1][m * TmpFBM.m_nStrideInBytes[1] + k * TmpFBM.m_nRowStrideInBytes[1]] = *(float *)&this->m_pAttributePtrs[1][k * this->m_nRowStrideInBytes[1] + m * this->m_nStrideInBytes[1]] * (float)(1.0 / v26);
        *(float *)&TmpFBM.m_pAttributePtrs[2][m * TmpFBM.m_nStrideInBytes[2] + k * TmpFBM.m_nRowStrideInBytes[2]] = *(float *)&this->m_pAttributePtrs[2][k * this->m_nRowStrideInBytes[2] + m * this->m_nStrideInBytes[2]] * (float)(1.0 / v26);
      }
    }
  }
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 0, nSrcAttributeIndex: -1);
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 1, nSrcAttributeIndex: -1);
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 2, nSrcAttributeIndex: -1);
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 3, nSrcAttributeIndex: -1);
  v27 = 0;
  if ( this->m_nRows > 0 )
  {
    m_nColumns = this->m_nColumns;
    do
    {
      v29 = 0;
      if ( m_nColumns > 0 )
      {
        do
        {
          v30 = v27 * this->m_nRowStrideInBytes[3] + v29 * this->m_nStrideInBytes[3];
          *(float *)&this->m_pAttributePtrs[3][v30] = *(float *)&this->m_pAttributePtrs[3][v30] * 0.00392156862745098;
          m_nColumns = this->m_nColumns;
          ++v29;
        }
        while ( v29 < this->m_nColumns );
      }
      ++v27;
    }
    while ( v27 < this->m_nRows );
  }
  CSOAContainer::~CSOAContainer(this: &TmpFBM);
}

//------------------------------------------------------------------------------
// Address: 0x004247F0
// Name: bool SupportsSSE2(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
bool __cdecl SupportsSSE2()
{
  return IsProcessorFeaturePresent(ProcessorFeature: 0xAu);
}

//------------------------------------------------------------------------------
// Address: 0x00424B30
// Name: unsigned long CalcBufferSize(enum _CodecType,unsigned long,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl CalcBufferSize(int a1, int a2, int a3)
{
  int v3; // eax
  unsigned int result; // eax

  switch ( a1 )
  {
    case 2:
    case 11:
      v3 = 1;
      goto LABEL_4;
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 12:
    case 13:
    case 14:
      v3 = 2;
LABEL_4:
      result = (4 * 4 * ((unsigned int)(a3 + 3) >> 2) * 4 * ((unsigned int)(a2 + 3) >> 2) * v3) >> 3;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00424BA0
// Name: unsigned char DeriveB(unsigned char,unsigned char)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 __cdecl DeriveB(unsigned __int8 a1, unsigned __int8 a2)
{
  double v2; // st6
  double v3; // st7
  float v5; // [esp+0h] [ebp-4h]
  float v6; // [esp+8h] [ebp+4h]
  float v7; // [esp+8h] [ebp+4h]
  float v8; // [esp+8h] [ebp+4h]
  float v9; // [esp+8h] [ebp+4h]
  float v10; // [esp+8h] [ebp+4h]
  float v11; // [esp+8h] [ebp+4h]
  float v12; // [esp+8h] [ebp+4h]
  float v13; // [esp+8h] [ebp+4h]
  float v14; // [esp+8h] [ebp+4h]
  float v15; // [esp+8h] [ebp+4h]

  v6 = (double)a1 / 255.0;
  v7 = v6 * 2.0;
  v5 = v7 - 1.0;
  v8 = (double)a2 / 255.0;
  v9 = 2.0 * v8;
  v10 = v9 - 1.0;
  v2 = v10 * v10 + v5 * v5;
  if ( v2 >= 1.0 )
    v2 = 1.0;
  v11 = v2;
  v12 = 1.0 - v11;
  v13 = sqrt(v12);
  v14 = v13 * 127.0;
  v15 = v14 + 128.0;
  if ( v15 < 255.0 )
  {
    v3 = 0.0;
    if ( v15 > 0.0 )
      return (int)v15;
  }
  else
  {
    v3 = 255.0;
  }
  return (int)(float)v3;
}

//------------------------------------------------------------------------------
// Address: 0x00424CB0
// Name: float DeriveB(float,float)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl DeriveB(float a1, float a2)
{
  double v2; // st6
  float v4; // [esp+0h] [ebp-4h]
  float v5; // [esp+8h] [ebp+4h]
  float v6; // [esp+8h] [ebp+4h]
  float v7; // [esp+8h] [ebp+4h]
  float v8; // [esp+8h] [ebp+4h]
  float v9; // [esp+8h] [ebp+4h]
  float v10; // [esp+8h] [ebp+4h]
  float v11; // [esp+8h] [ebp+4h]

  v5 = a1 * 2.0;
  v4 = v5 - 1.0;
  v6 = 2.0 * a2;
  v7 = v6 - 1.0;
  v2 = v7 * v7 + v4 * v4;
  if ( v2 >= 1.0 )
    v2 = 1.0;
  v8 = v2;
  v9 = 1.0 - v8;
  v10 = sqrt(v9);
  v11 = v10 + 1.0;
  return (float)(v11 * 0.5);
}

//------------------------------------------------------------------------------
// Address: 0x00424D70
// Name: public: half::half(float)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
half *__thiscall half::half(half *this, int a2)
{
  if ( *(float *)&a2 == 0.0 )
  {
    *(_WORD *)this = 0;
    return this;
  }
  else
  {
    if ( *((_WORD *)&half::_eLut + ((unsigned int)a2 >> 23)) != 0 )
      *(_WORD *)this = *((_WORD *)&half::_eLut + ((unsigned int)a2 >> 23)) + (((a2 & 0x7FFFFFu) + 4096) >> 13);
    else
      *(_WORD *)this = half::convert(a1: a2);
    return this;
  }
}

} // namespace vtfdiff

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x10287F80
// Name: public: void FloatBitMap_t::CompressTo8Bits(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::CompressTo8Bits(FloatBitMap_t *this, float overbright)
{
  float v3; // xmm2_4
  int i; // ecx
  int j; // eax
  unsigned int v6; // edx
  unsigned __int8 *v7; // edi
  float v8; // xmm0_4
  unsigned int v9; // edx
  unsigned __int8 *v10; // edi
  float v11; // xmm0_4
  unsigned int v12; // edx
  unsigned __int8 *v13; // edi
  float v14; // xmm0_4
  int k; // ebx
  int m; // edi
  float v17; // xmm1_4
  unsigned __int8 *v18; // edx
  unsigned int v19; // eax
  float v20; // xmm0_4
  float v21; // xmm4_4
  unsigned __int8 *v22; // edx
  unsigned int v23; // eax
  double v24; // xmm0_8
  float v25; // xmm0_4
  float v26; // xmm1_4
  int v27; // edx
  int m_nColumns; // ecx
  int v29; // eax
  unsigned int v30; // ecx
  FloatBitMap_t TmpFBM; // [esp+14h] [ebp-334h] BYREF
  double X; // [esp+338h] [ebp-10h]
  double v33; // [esp+340h] [ebp-8h]

  FloatBitMap_t::FloatBitMap_t(
    this: &TmpFBM,
    nWidth: this->m_nColumns,
    nHeight: this->m_nRows,
    nDepth: 1,
    nAttributeMask: 15);
  v3 = overbright;
  for ( i = 0; i < this->m_nRows; ++i )
  {
    for ( j = 0; j < this->m_nColumns; *(float *)&v13[v12] = v14 )
    {
      v6 = i * this->m_nRowStrideInBytes[0] + j * this->m_nStrideInBytes[0];
      v7 = this->m_pAttributePtrs[0];
      v8 = *(float *)&v7[v6];
      if ( v8 > overbright )
        v8 = overbright;
      *(float *)&v7[v6] = v8;
      v9 = i * this->m_nRowStrideInBytes[1] + j * this->m_nStrideInBytes[1];
      v10 = this->m_pAttributePtrs[1];
      v11 = *(float *)&v10[v9];
      if ( v11 > overbright )
        v11 = overbright;
      *(float *)&v10[v9] = v11;
      v12 = i * this->m_nRowStrideInBytes[2] + j * this->m_nStrideInBytes[2];
      v13 = this->m_pAttributePtrs[2];
      v14 = *(float *)&v13[v12];
      if ( v14 > overbright )
        v14 = overbright;
      ++j;
    }
  }
  for ( k = 0; k < this->m_nRows; ++k )
  {
    for ( m = 0; m < this->m_nColumns; ++m )
    {
      v17 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      v18 = this->m_pAttributePtrs[1];
      v19 = k * this->m_nRowStrideInBytes[1] + m * this->m_nStrideInBytes[1];
      v20 = *(float *)&v18[v19];
      if ( v17 <= v20 )
        v21 = *(float *)&v18[v19];
      else
        v21 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      v22 = this->m_pAttributePtrs[2];
      v23 = k * this->m_nRowStrideInBytes[2] + m * this->m_nStrideInBytes[2];
      if ( v21 <= *(float *)&v22[v23] )
      {
        v20 = *(float *)&v22[v23];
      }
      else if ( v17 > v20 )
      {
        v20 = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]];
      }
      if ( v20 == 0.0 )
      {
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[0][k * TmpFBM.m_nRowStrideInBytes[0] + m * TmpFBM.m_nStrideInBytes[0]] = 0;
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[1][m * TmpFBM.m_nStrideInBytes[1] + k * TmpFBM.m_nRowStrideInBytes[1]] = 0;
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[2][m * TmpFBM.m_nStrideInBytes[2] + k * TmpFBM.m_nRowStrideInBytes[2]] = 0;
        *(_DWORD *)&TmpFBM.m_pAttributePtrs[3][m * TmpFBM.m_nStrideInBytes[3] + k * TmpFBM.m_nRowStrideInBytes[3]] = 0;
      }
      else
      {
        X = (float)(1.0 / v3 * v20) * 255.0;
        if ( ceil(X) <= 255.0 )
        {
          v33 = ceil(X);
          v24 = v33;
        }
        else
        {
          v24 = 255.0;
        }
        v3 = overbright;
        v25 = (float)(int)v24;
        *(float *)&TmpFBM.m_pAttributePtrs[3][m * TmpFBM.m_nStrideInBytes[3] + k * TmpFBM.m_nRowStrideInBytes[3]] = v25;
        v26 = overbright * 0.00392156862745098 * (double)(int)v25;
        *(float *)&TmpFBM.m_pAttributePtrs[0][k * TmpFBM.m_nRowStrideInBytes[0] + m * TmpFBM.m_nStrideInBytes[0]] = *(float *)&this->m_pAttributePtrs[0][k * this->m_nRowStrideInBytes[0] + m * this->m_nStrideInBytes[0]] * (float)(1.0 / v26);
        *(float *)&TmpFBM.m_pAttributePtrs[1][m * TmpFBM.m_nStrideInBytes[1] + k * TmpFBM.m_nRowStrideInBytes[1]] = *(float *)&this->m_pAttributePtrs[1][k * this->m_nRowStrideInBytes[1] + m * this->m_nStrideInBytes[1]] * (float)(1.0 / v26);
        *(float *)&TmpFBM.m_pAttributePtrs[2][m * TmpFBM.m_nStrideInBytes[2] + k * TmpFBM.m_nRowStrideInBytes[2]] = *(float *)&this->m_pAttributePtrs[2][k * this->m_nRowStrideInBytes[2] + m * this->m_nStrideInBytes[2]] * (float)(1.0 / v26);
      }
    }
  }
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 0, nSrcAttributeIndex: -1);
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 1, nSrcAttributeIndex: -1);
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 2, nSrcAttributeIndex: -1);
  CSOAContainer::CopyAttrFrom(this, other: &TmpFBM, nDestAttributeIndex: 3, nSrcAttributeIndex: -1);
  v27 = 0;
  if ( this->m_nRows > 0 )
  {
    m_nColumns = this->m_nColumns;
    do
    {
      v29 = 0;
      if ( m_nColumns > 0 )
      {
        do
        {
          v30 = v27 * this->m_nRowStrideInBytes[3] + v29 * this->m_nStrideInBytes[3];
          *(float *)&this->m_pAttributePtrs[3][v30] = *(float *)&this->m_pAttributePtrs[3][v30] * 0.00392156862745098;
          m_nColumns = this->m_nColumns;
          ++v29;
        }
        while ( v29 < this->m_nColumns );
      }
      ++v27;
    }
    while ( v27 < this->m_nRows );
  }
  CSOAContainer::~CSOAContainer(this: &TmpFBM);
}

//------------------------------------------------------------------------------
// Address: 0x10288430
// Name: bool SupportsSSE2(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
bool __cdecl SupportsSSE2()
{
  return IsProcessorFeaturePresent(ProcessorFeature: 0xAu);
}

//------------------------------------------------------------------------------
// Address: 0x10288770
// Name: unsigned long CalcBufferSize(enum _CodecType,unsigned long,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl CalcBufferSize(int a1, int a2, int a3)
{
  int v3; // eax
  unsigned int result; // eax

  switch ( a1 )
  {
    case 2:
    case 11:
      v3 = 1;
      goto LABEL_4;
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 12:
    case 13:
    case 14:
      v3 = 2;
LABEL_4:
      result = (4 * 4 * ((unsigned int)(a3 + 3) >> 2) * 4 * ((unsigned int)(a2 + 3) >> 2) * v3) >> 3;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102887E0
// Name: unsigned char DeriveB(unsigned char,unsigned char)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 __cdecl DeriveB(unsigned __int8 a1, unsigned __int8 a2)
{
  double v2; // st6
  double v3; // st7
  float v5; // [esp+0h] [ebp-4h]
  float v6; // [esp+8h] [ebp+4h]
  float v7; // [esp+8h] [ebp+4h]
  float v8; // [esp+8h] [ebp+4h]
  float v9; // [esp+8h] [ebp+4h]
  float v10; // [esp+8h] [ebp+4h]
  float v11; // [esp+8h] [ebp+4h]
  float v12; // [esp+8h] [ebp+4h]
  float v13; // [esp+8h] [ebp+4h]
  float v14; // [esp+8h] [ebp+4h]
  float v15; // [esp+8h] [ebp+4h]

  v6 = (double)a1 / 255.0;
  v7 = v6 * 2.0;
  v5 = v7 - 1.0;
  v8 = (double)a2 / 255.0;
  v9 = 2.0 * v8;
  v10 = v9 - 1.0;
  v2 = v10 * v10 + v5 * v5;
  if ( v2 >= 1.0 )
    v2 = 1.0;
  v11 = v2;
  v12 = 1.0 - v11;
  v13 = sqrt(v12);
  v14 = v13 * 127.0;
  v15 = v14 + 128.0;
  if ( v15 < 255.0 )
  {
    v3 = 0.0;
    if ( v15 > 0.0 )
      return (int)v15;
  }
  else
  {
    v3 = 255.0;
  }
  return (int)(float)v3;
}

//------------------------------------------------------------------------------
// Address: 0x102888F0
// Name: float DeriveB(float,float)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl DeriveB(float a1, float a2)
{
  double v2; // st6
  float v4; // [esp+0h] [ebp-4h]
  float v5; // [esp+8h] [ebp+4h]
  float v6; // [esp+8h] [ebp+4h]
  float v7; // [esp+8h] [ebp+4h]
  float v8; // [esp+8h] [ebp+4h]
  float v9; // [esp+8h] [ebp+4h]
  float v10; // [esp+8h] [ebp+4h]
  float v11; // [esp+8h] [ebp+4h]

  v5 = a1 * 2.0;
  v4 = v5 - 1.0;
  v6 = 2.0 * a2;
  v7 = v6 - 1.0;
  v2 = v7 * v7 + v4 * v4;
  if ( v2 >= 1.0 )
    v2 = 1.0;
  v8 = v2;
  v9 = 1.0 - v8;
  v10 = sqrt(v9);
  v11 = v10 + 1.0;
  return (float)(v11 * 0.5);
}

//------------------------------------------------------------------------------
// Address: 0x102889A0
// Name: public: half::half(float)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
half *__thiscall half::half(half *this, int a2)
{
  if ( *(float *)&a2 == 0.0 )
  {
    *(_WORD *)this = 0;
    return this;
  }
  else
  {
    if ( *((_WORD *)&half::_eLut + ((unsigned int)a2 >> 23)) != 0 )
      *(_WORD *)this = *((_WORD *)&half::_eLut + ((unsigned int)a2 >> 23)) + (((a2 & 0x7FFFFFu) + 4096) >> 13);
    else
      *(_WORD *)this = half::convert(a1: a2);
    return this;
  }
}

} // namespace client
