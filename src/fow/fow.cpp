// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: fow/fow.cpp
// Functions: 54
// ============================================================

#include "fow\fow.h"

//------------------------------------------------------------------------------
// Address: 0x101F7240
// Name: private: class Vector4D CUtlSphereTree::AddSpheres(class Vector4D const __near &,class Vector4D const __near &)const
// Source: json
//------------------------------------------------------------------------------
Vector4D *__thiscall CUtlSphereTree::AddSpheres(
        CUtlSphereTree *this,
        Vector4D *result,
        const Vector4D *pA,
        const Vector4D *pB)
{
  const Vector4D *v4; // esi
  float v7; // xmm0_4
  float v8; // xmm2_4
  float v9; // xmm3_4
  Vector delta; // [esp+8h] [ebp-10h] BYREF
  float dist; // [esp+14h] [ebp-4h]
  float aRad; // [esp+24h] [ebp+Ch]
  float bRad; // [esp+28h] [ebp+10h]

  v4 = pB;
  aRad = pA->w;
  bRad = pB->w;
  delta.x = pA->x - v4->x;
  delta.y = pA->y - v4->y;
  delta.z = pA->z - v4->z;
  dist = VectorNormalize(vec: &delta);
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(aRad - bRad) & _mask__AbsFloat_) <= dist )
  {
    v7 = (float)((float)(bRad + aRad) + dist) * 0.5;
    v8 = v4->y + (float)(delta.y * (float)(v7 - bRad));
    v9 = v4->z + (float)(delta.z * (float)(v7 - bRad));
    result->x = v4->x + (float)(delta.x * (float)(v7 - bRad));
    result->y = v8;
    result->z = v9;
    result->w = v7;
    return result;
  }
  else
  {
    if ( aRad > bRad )
      v4 = pA;
    *result = *v4;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F7360
// Name: public: void CFoW::SetSize(class Vector __near &,class Vector __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoW::SetSize(
        CFoW *this,
        Vector *vWorldMins,
        Vector *vWorldMaxs,
        int nHorizontalGridSize,
        int nVerticalGridSize)
{
  float v6; // xmm2_4
  float v7; // xmm4_4
  float v8; // xmm2_4
  int m_nGridXUnits; // edi
  float v10; // xmm4_4
  int v11; // edi
  float v12; // xmm0_4
  float **m_pVisibilityGridDegree; // ebx
  unsigned __int8 *v14; // eax
  int v15; // ecx
  char *v16; // eax
  int v17; // edx
  int m_nVerticalGridSize; // eax
  float v19; // xmm1_4
  int v20; // edi
  CFoW_HorizontalSlice *v21; // eax
  CFoW_HorizontalSlice *v22; // eax
  __m128i v23; // xmm1
  int i; // [esp+8h] [ebp+8h]

  this->m_nVerticalGridAllocationSize = 0;
  this->m_nHorizontalGridAllocationSize = 0;
  this->m_vWorldMins = *vWorldMins;
  i = 0;
  this->m_vWorldMaxs = *vWorldMaxs;
  v6 = (float)(this->m_vWorldMaxs.x - this->m_vWorldMins.x) + (float)nHorizontalGridSize;
  v7 = (float)(this->m_vWorldMaxs.y - this->m_vWorldMins.y) + (float)nHorizontalGridSize;
  this->m_nVerticalGridSize = nVerticalGridSize;
  v8 = (float)(v6 - 1.0) / (float)nHorizontalGridSize;
  this->m_nGridXUnits = (int)v8;
  m_nGridXUnits = this->m_nGridXUnits;
  v10 = (float)(v7 - 1.0) / (float)nHorizontalGridSize;
  this->m_nGridYUnits = (int)v10;
  v11 = this->m_nGridYUnits * m_nGridXUnits;
  this->m_vWorldMaxs.x = (float)(nHorizontalGridSize * (int)v8) + this->m_vWorldMins.x;
  v12 = (float)(nHorizontalGridSize * (int)v10) + this->m_vWorldMins.y;
  this->m_nHorizontalGridSize = nHorizontalGridSize;
  this->m_vWorldMaxs.y = v12;
  this->m_nTotalHorizontalUnits = v11;
  if ( this->m_nNumberOfTeams > 0 )
  {
    m_pVisibilityGridDegree = this->m_pVisibilityGridDegree;
    do
    {
      v14 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v11);
      m_pVisibilityGridDegree[4] = (float *)v14;
      memset(dst: v14, value: 0, count: v11);
      this->m_nHorizontalGridAllocationSize += v11;
      *m_pVisibilityGridDegree = (float *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * v11);
      this->m_nHorizontalGridAllocationSize += 4 * v11;
      m_pVisibilityGridDegree[2] = (float *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * v11);
      this->m_nHorizontalGridAllocationSize += 4 * v11;
      v15 = 0;
      if ( this->m_nTotalHorizontalUnits > 0 )
      {
        v16 = (char *)m_pVisibilityGridDegree[2];
        v17 = (char *)*m_pVisibilityGridDegree - v16;
        do
        {
          *(_DWORD *)&v16[v17] = 0;
          *(_DWORD *)v16 = 0;
          ++v15;
          v16 += 4;
        }
        while ( v15 < this->m_nTotalHorizontalUnits );
      }
      ++m_pVisibilityGridDegree;
      ++i;
    }
    while ( i < this->m_nNumberOfTeams );
  }
  m_nVerticalGridSize = this->m_nVerticalGridSize;
  if ( m_nVerticalGridSize > 0 )
  {
    v19 = (float)((float)((float)(this->m_vWorldMaxs.z - this->m_vWorldMins.z) + (float)m_nVerticalGridSize) - 1.0)
        / (float)m_nVerticalGridSize;
    this->m_nGridZUnits = (int)v19;
    this->m_pVerticalLevels = (float *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * (int)v19);
    v20 = 0;
    for ( this->m_pHorizontalSlices = (CFoW_HorizontalSlice **)_g_pMemAlloc->Alloc_2(
                                                                 this: _g_pMemAlloc,
                                                                 a2: 4 * this->m_nGridZUnits); v20 < this->m_nGridZUnits; ++v20 )
    {
      v21 = (CFoW_HorizontalSlice *)operator new(nSize: 0x24u);
      if ( v21 != nullptr )
        v22 = CFoW_HorizontalSlice::CFoW_HorizontalSlice(this: v21);
      else
        v22 = nullptr;
      this->m_pHorizontalSlices[v20] = v22;
      v23 = _mm_cvtsi32_si128(this->m_nVerticalGridSize);
      this->m_nVerticalGridAllocationSize += 36;
      this->m_pVerticalLevels[v20] = (float)((float)((float)v20 + 0.75) * _mm_cvtepi32_ps(v23).m128_f32[0])
                                   + this->m_vWorldMins.z;
    }
    this->m_nVerticalGridAllocationSize += 8 * this->m_nGridZUnits;
  }
  this->m_bInitialized = true;
}

//------------------------------------------------------------------------------
// Address: 0x101F75C0
// Name: public: void CFoW::SetCustomVerticalLevels(float __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoW::SetCustomVerticalLevels(CFoW *this, float *pflHeightLevels, int nCount)
{
  int v4; // edi
  CFoW_HorizontalSlice *v5; // eax
  CFoW_HorizontalSlice *v6; // eax

  this->m_nGridZUnits = nCount;
  this->m_nVerticalGridSize = -1;
  this->m_pVerticalLevels = (float *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * nCount);
  v4 = 0;
  for ( this->m_pHorizontalSlices = (CFoW_HorizontalSlice **)_g_pMemAlloc->Alloc_2(
                                                               this: _g_pMemAlloc,
                                                               a2: 4 * this->m_nGridZUnits); v4 < this->m_nGridZUnits; ++v4 )
  {
    v5 = (CFoW_HorizontalSlice *)operator new(nSize: 0x24u);
    if ( v5 != nullptr )
      v6 = CFoW_HorizontalSlice::CFoW_HorizontalSlice(this: v5);
    else
      v6 = nullptr;
    this->m_pHorizontalSlices[v4] = v6;
    this->m_nVerticalGridAllocationSize += 36;
    this->m_pVerticalLevels[v4] = pflHeightLevels[v4];
  }
  this->m_nVerticalGridAllocationSize += 8 * this->m_nGridZUnits;
}

//------------------------------------------------------------------------------
// Address: 0x101F7660
// Name: public: void CFoW::GetSize(class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoW::GetSize(CFoW *this, Vector *vWorldMins, Vector *vWorldMaxs)
{
  *vWorldMins = this->m_vWorldMins;
  *vWorldMaxs = this->m_vWorldMaxs;
}

//------------------------------------------------------------------------------
// Address: 0x101F7690
// Name: public: void CFoW::GetVerticalGridInfo(int __near &,int __near &,int __near &,float __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoW::GetVerticalGridInfo(
        CFoW *this,
        int *nBottomZ,
        int *nGridSize,
        int *nGridUnits,
        float **pVerticalLevels)
{
  *nBottomZ = (int)this->m_vWorldMins.z;
  *nGridSize = this->m_nVerticalGridSize;
  *nGridUnits = this->m_nGridZUnits;
  *pVerticalLevels = this->m_pVerticalLevels;
}

//------------------------------------------------------------------------------
// Address: 0x101F76C0
// Name: public: void CFoW::AddTriSoupOccluder(class CFoW_LineOccluder __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoW::AddTriSoupOccluder(CFoW *this, CFoW_LineOccluder *pOccluder, int nSliceNum)
{
  CFoW_HorizontalSlice::AddHorizontalOccluder(this: this->m_pHorizontalSlices[nSliceNum], pLineOccluder: pOccluder);
}

//------------------------------------------------------------------------------
// Address: 0x101F76E0
// Name: public: int CFoW::GetHorizontalSlice(float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFoW::GetHorizontalSlice(CFoW *this, float flZPos)
{
  int m_nGridZUnits; // edx
  int result; // eax
  float *i; // ecx

  if ( this->m_nVerticalGridSize == 0 )
    return -1;
  if ( this->m_pHorizontalSlices == nullptr )
    return -1;
  m_nGridZUnits = this->m_nGridZUnits;
  result = 0;
  if ( m_nGridZUnits <= 0 )
    return -1;
  for ( i = this->m_pVerticalLevels; *i <= flZPos; ++i )
  {
    if ( ++result >= m_nGridZUnits )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F7720
// Name: void CalcLocalizedVisibilityThreaded(class CFoW __near *,class CFoW_Viewer __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CalcLocalizedVisibilityThreaded(CFoW *pFoW, CFoW_Viewer *pViewer)
{
  CFoW_Viewer::CalcLocalizedVisibility(this: pViewer, pFoW);
}

//------------------------------------------------------------------------------
// Address: 0x101F7740
// Name: private: void CFoW::PrepVisibility(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoW::PrepVisibility(CFoW *this)
{
  int v1; // eax
  int v2; // ebx
  unsigned __int8 **m_pVisibilityGridFlags; // edi
  unsigned __int8 *v4; // edx
  unsigned __int8 *v5; // esi
  unsigned __int8 v6; // al
  int nSize; // [esp+4h] [ebp-4h]

  v1 = this->m_nGridXUnits * this->m_nGridYUnits;
  v2 = 0;
  nSize = v1;
  if ( this->m_nNumberOfTeams > 0 )
  {
    m_pVisibilityGridFlags = this->m_pVisibilityGridFlags;
    do
    {
      v4 = *m_pVisibilityGridFlags;
      v5 = &(*m_pVisibilityGridFlags)[v1];
      if ( *m_pVisibilityGridFlags < v5 )
      {
        do
        {
          if ( (*v4 & 0x20) != 0 )
          {
            v6 = *v4 & 0xDF;
            *v4 = v6;
            if ( (v6 & 0x40) == 0 )
              *v4 = v6 | 0x40;
          }
          ++v4;
        }
        while ( v4 < v5 );
        v1 = nSize;
      }
      ++v2;
      ++m_pVisibilityGridFlags;
    }
    while ( v2 < this->m_nNumberOfTeams );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F77A0
// Name: private: void CFoW::UpdateVisibleAmounts(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoW::UpdateVisibleAmounts(CFoW *this, float flFrameTime)
{
  float v2; // xmm1_4
  int v3; // esi
  float **m_pVisibilityGridDegree; // ebx
  float *v5; // edx
  float *v6; // eax
  float *v7; // edi
  int v8; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  float v11; // xmm0_4
  int nSize; // [esp+0h] [ebp-4h]
  int i; // [esp+Ch] [ebp+8h]

  v2 = flFrameTime / this->m_flDegreeFadeRate;
  v3 = this->m_nGridXUnits * this->m_nGridYUnits;
  nSize = v3;
  i = 0;
  if ( this->m_nNumberOfTeams > 0 )
  {
    m_pVisibilityGridDegree = this->m_pVisibilityGridDegree;
    do
    {
      v5 = m_pVisibilityGridDegree[4];
      v6 = *m_pVisibilityGridDegree;
      v7 = (float *)((char *)v5 + v3);
      if ( v5 < (float *)((char *)v5 + v3) )
      {
        v8 = (char *)m_pVisibilityGridDegree[2] - (char *)v6;
        do
        {
          if ( (*(_BYTE *)v5 & 0x20) != 0 )
          {
            if ( *v6 < 1.5 )
            {
              v9 = *v6 + v2;
              *v6 = v9;
              if ( v9 > 1.5 )
                *v6 = 1.5;
            }
            *(float *)((char *)v6 + v8) = 0.25;
          }
          else
          {
            v10 = *(float *)((char *)v6 + v8);
            if ( v10 <= 0.0 )
            {
              if ( *v6 > 0.0 )
              {
                v11 = *v6 - v2;
                *v6 = v11;
                if ( v11 < 0.0 )
                  *v6 = 0.0;
              }
            }
            else
            {
              *(float *)((char *)v6 + v8) = v10 - v2;
            }
          }
          v5 = (float *)((char *)v5 + 1);
          ++v6;
        }
        while ( v5 < v7 );
        v3 = nSize;
      }
      ++m_pVisibilityGridDegree;
      ++i;
    }
    while ( i < this->m_nNumberOfTeams );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F7870
// Name: public: void CFoW::CenterCoordToGrid(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoW::CenterCoordToGrid(CFoW *this, Vector *vCoords)
{
  __m128 x_low; // xmm0
  __m128 v3; // xmm2
  __m128 v4; // xmm1
  __m128 v5; // xmm3
  __m128 v6; // xmm1
  __m128 v7; // xmm2
  __m128 y_low; // xmm0
  int v9; // esi
  __m128 v10; // xmm3
  __m128 v11; // xmm1
  __m128 v12; // xmm2

  x_low = (__m128)LODWORD(vCoords->x);
  v3.m128_i32[0] = 1258291200;
  x_low.m128_f32[0] = (float)(x_low.m128_f32[0] - this->m_vWorldMins.x) / (float)this->m_nHorizontalGridSize;
  v4 = _mm_and_ps((__m128)0x80000000, x_low);
  v5.m128_i32[0] = v4.m128_i32[0];
  v3.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(x_low, v4), v3).m128_f32[0]) & 0x4B000000
                 | v4.m128_i32[0];
  v6 = x_low;
  v6.m128_f32[0] = (float)(x_low.m128_f32[0] + v3.m128_f32[0]) - v3.m128_f32[0];
  v7 = v6;
  v7.m128_f32[0] = v6.m128_f32[0] - x_low.m128_f32[0];
  y_low = (__m128)LODWORD(vCoords->y);
  v6.m128_f32[0] = v6.m128_f32[0] - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v7, v5).m128_f32[0]) & 0x3F800000);
  v7.m128_i32[0] = 1258291200;
  v9 = (int)v6.m128_f32[0];
  y_low.m128_f32[0] = (float)(y_low.m128_f32[0] - this->m_vWorldMins.y) / (float)this->m_nHorizontalGridSize;
  v10 = _mm_and_ps((__m128)0x80000000, y_low);
  v7.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(y_low, v10), v7).m128_f32[0]) & 0x4B000000
                 | v10.m128_i32[0];
  v11 = y_low;
  v11.m128_f32[0] = (float)(y_low.m128_f32[0] + v7.m128_f32[0]) - v7.m128_f32[0];
  v12 = v11;
  v12.m128_f32[0] = v11.m128_f32[0] - y_low.m128_f32[0];
  vCoords->x = (float)((float)(v9 * this->m_nHorizontalGridSize) + this->m_vWorldMins.x)
             + (float)((float)this->m_nHorizontalGridSize * 0.5);
  vCoords->y = (float)((float)((int)(float)(v11.m128_f32[0]
                                          - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v12, v10).m128_f32[0]) & 0x3F800000))
                             * this->m_nHorizontalGridSize)
                     + this->m_vWorldMins.y)
             + (float)((float)this->m_nHorizontalGridSize * 0.5);
}

//------------------------------------------------------------------------------
// Address: 0x101F79A0
// Name: public: float CFoW::LookupVisibilityDegree(int,int,int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CFoW::LookupVisibilityDegree(CFoW *this, int nXLoc, int nYLoc, int nTeam)
{
  float m_nHorizontalGridSize; // xmm0_4
  int v5; // edx
  int v6; // esi
  int m_nGridYUnits; // eax
  float v8; // xmm0_4

  m_nHorizontalGridSize = (float)this->m_nHorizontalGridSize;
  v5 = (int)(float)((float)((float)nXLoc - this->m_vWorldMins.x) / m_nHorizontalGridSize);
  v6 = (int)(float)((float)((float)nYLoc - this->m_vWorldMins.y) / m_nHorizontalGridSize);
  if ( v5 >= 0 )
  {
    if ( v5 > this->m_nGridXUnits - 1 )
      v5 = this->m_nGridXUnits - 1;
  }
  else
  {
    v5 = 0;
  }
  m_nGridYUnits = this->m_nGridYUnits;
  if ( v6 >= 0 )
  {
    if ( v6 > m_nGridYUnits - 1 )
      v6 = m_nGridYUnits - 1;
  }
  else
  {
    v6 = 0;
  }
  v8 = this->m_pVisibilityGridDegree[nTeam][v6 + v5 * m_nGridYUnits];
  if ( v8 <= 1.0 )
    return v8;
  else
    return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x101F7A40
// Name: void PrepVisibilityThreaded(class CFoW __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PrepVisibilityThreaded(CFoW *pFoW)
{
  CFoW::PrepVisibility(this: pFoW);
}

//------------------------------------------------------------------------------
// Address: 0x101F7A50
// Name: public: float CFoW::GetLocationVisibilityDegree(unsigned int,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
double __thiscall CFoW::GetLocationVisibilityDegree(
        CFoW *this,
        unsigned int nViewerTeam,
        const Vector *vLocation,
        unsigned int flRadius)
{
  __m128 v4; // xmm0
  const Vector *v5; // edx
  __m128 v6; // xmm2
  __m128 v7; // xmm0
  __m128 v8; // xmm1
  __m128 v9; // xmm3
  __m128 v10; // xmm1
  __m128 v11; // xmm2
  int v12; // eax
  __m128 v13; // xmm0
  __m128 v14; // xmm3
  __m128 v15; // xmm1
  __m128 v16; // xmm2
  int v17; // eax
  float v18; // xmm0_4
  __m128 x_low; // xmm2
  __m128 v21; // xmm6
  __m128 v22; // xmm0
  float m_nHorizontalGridSize; // xmm7_4
  __m128 v24; // xmm4
  __m128 v25; // xmm3
  __m128 y_low; // xmm1
  __m128 v27; // xmm4
  int v28; // esi
  __m128 v29; // xmm0
  __m128 v30; // xmm3
  int v31; // eax
  __m128 v32; // xmm3
  __m128 v33; // xmm0
  __m128 v34; // xmm1
  int v35; // ebx
  __m128 v36; // xmm2
  __m128 v37; // xmm0
  __m128 v38; // xmm1
  int v39; // edi
  float v40; // xmm0_4
  int m_nGridYUnits; // edx
  float v42; // xmm1_4
  int v43; // ebx
  int v44; // edx
  float v45; // xmm1_4
  int v46; // edx
  float v47; // xmm1_4
  int v48; // edx
  float v49; // xmm1_4
  int v50; // edx
  float v51; // xmm1_4
  int v52; // [esp+24h] [ebp-10h]
  int v53; // [esp+2Ch] [ebp-8h]
  int v54; // [esp+30h] [ebp-4h]
  __m128 v55; // [esp+44h] [ebp+10h]
  int v56; // [esp+44h] [ebp+10h]

  v4 = (__m128)flRadius;
  v5 = vLocation;
  if ( *(float *)&flRadius > 1.0 )
  {
    v4.m128_f32[0] = *(float *)&flRadius + 16.0;
    x_low = (__m128)LODWORD(vLocation->x);
    v21 = v4;
    v22 = x_low;
    x_low.m128_f32[0] = x_low.m128_f32[0] + (float)(*(float *)&flRadius + 16.0);
    m_nHorizontalGridSize = (float)this->m_nHorizontalGridSize;
    v22.m128_f32[0] = (float)((float)(v22.m128_f32[0] - (float)(*(float *)&flRadius + 16.0)) - this->m_vWorldMins.x)
                    / m_nHorizontalGridSize;
    v24 = _mm_and_ps((__m128)0x80000000, v22);
    v25 = _mm_xor_ps(v22, v24);
    v55.m128_i32[0] = v24.m128_i32[0];
    v24.m128_i32[0] = 1258291200;
    v25.m128_f32[0] = _mm_cmplt_ss(v25, v24).m128_f32[0];
    v25.m128_f32[0] = (float)(v22.m128_f32[0] + COERCE_FLOAT(v25.m128_i32[0] & 0x4B000000 | v55.m128_i32[0]))
                    - COERCE_FLOAT(v25.m128_i32[0] & 0x4B000000 | v55.m128_i32[0]);
    y_low = (__m128)LODWORD(vLocation->y);
    v24.m128_f32[0] = v25.m128_f32[0] - v22.m128_f32[0];
    y_low.m128_f32[0] = (float)((float)(y_low.m128_f32[0] - v21.m128_f32[0]) - this->m_vWorldMins.y)
                      / m_nHorizontalGridSize;
    v25.m128_f32[0] = v25.m128_f32[0]
                    - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v24, v55).m128_f32[0]) & 0x3F800000);
    v27 = _mm_and_ps((__m128)0x80000000, y_low);
    v28 = (int)v25.m128_f32[0];
    v25.m128_i32[0] = 1258291200;
    v25.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(y_low, v27), v25).m128_f32[0]) & 0x4B000000;
    v29 = y_low;
    v29.m128_f32[0] = (float)(y_low.m128_f32[0] + COERCE_FLOAT(v25.m128_i32[0] | v27.m128_i32[0]))
                    - COERCE_FLOAT(v25.m128_i32[0] | v27.m128_i32[0]);
    v30 = v29;
    v30.m128_f32[0] = v29.m128_f32[0] - y_low.m128_f32[0];
    y_low.m128_i32[0] = 1258291200;
    v31 = (int)(float)(v29.m128_f32[0]
                     - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v30, v27).m128_f32[0]) & 0x3F800000));
    x_low.m128_f32[0] = (float)(x_low.m128_f32[0] - this->m_vWorldMins.x) / m_nHorizontalGridSize;
    v32 = _mm_and_ps((__m128)0x80000000, x_low);
    y_low.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(x_low, v32), y_low).m128_f32[0]) & 0x4B000000
                      | v32.m128_i32[0];
    v33 = x_low;
    v33.m128_f32[0] = (float)(x_low.m128_f32[0] + y_low.m128_f32[0]) - y_low.m128_f32[0];
    v34 = v33;
    v34.m128_f32[0] = v33.m128_f32[0] - x_low.m128_f32[0];
    v53 = v31;
    v35 = (int)(float)(v33.m128_f32[0]
                     - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v34, v32).m128_f32[0]) & 0x3F800000));
    v34.m128_i32[0] = 1258291200;
    v21.m128_f32[0] = (float)((float)(v21.m128_f32[0] + vLocation->y) - this->m_vWorldMins.y) / m_nHorizontalGridSize;
    v36 = _mm_and_ps((__m128)0x80000000, v21);
    v34.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v21, v36), v34).m128_f32[0]) & 0x4B000000
                    | v36.m128_i32[0];
    v37 = v21;
    v37.m128_f32[0] = (float)(v21.m128_f32[0] + v34.m128_f32[0]) - v34.m128_f32[0];
    v38 = v37;
    v38.m128_f32[0] = v37.m128_f32[0] - v21.m128_f32[0];
    v39 = (int)(float)(v37.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v38, v36).m128_u32[0] & 0x3F800000));
    v40 = 0.0;
    v52 = v35;
    v54 = v39;
    v56 = 0;
    if ( v28 <= v35 )
    {
      do
      {
        if ( v28 >= 0 && v28 < this->m_nGridXUnits && v31 <= v39 )
        {
          if ( v39 - v31 + 1 >= 4 )
          {
            do
            {
              if ( v31 >= 0 )
              {
                m_nGridYUnits = this->m_nGridYUnits;
                if ( v31 < m_nGridYUnits )
                {
                  v42 = this->m_pVisibilityGridDegree[nViewerTeam][v31 + v28 * m_nGridYUnits];
                  if ( v42 > 1.0 )
                    v42 = 1.0;
                  ++v56;
                  v40 = v42 + v40;
                }
              }
              v43 = v31 + 2;
              if ( v31 + 1 >= 0 )
              {
                v44 = this->m_nGridYUnits;
                if ( v31 + 1 < v44 )
                {
                  v45 = this->m_pVisibilityGridDegree[nViewerTeam][v31 + 1 + v28 * v44];
                  if ( v45 > 1.0 )
                    v45 = 1.0;
                  ++v56;
                  v40 = v45 + v40;
                }
              }
              if ( v43 >= 0 )
              {
                v46 = this->m_nGridYUnits;
                if ( v43 < v46 )
                {
                  v47 = this->m_pVisibilityGridDegree[nViewerTeam][v31 + 2 + v28 * v46];
                  if ( v47 > 1.0 )
                    v47 = 1.0;
                  ++v56;
                  v40 = v47 + v40;
                }
              }
              if ( v31 + 3 >= 0 )
              {
                v48 = this->m_nGridYUnits;
                if ( v31 + 3 < v48 )
                {
                  v49 = this->m_pVisibilityGridDegree[nViewerTeam][v31 + 3 + v28 * v48];
                  if ( v49 > 1.0 )
                    v49 = 1.0;
                  ++v56;
                  v40 = v49 + v40;
                }
              }
              v31 += 4;
            }
            while ( v31 <= v54 - 3 );
            v39 = v54;
          }
          for ( ; v31 <= v39; ++v31 )
          {
            if ( v31 >= 0 )
            {
              v50 = this->m_nGridYUnits;
              if ( v31 < v50 )
              {
                v51 = this->m_pVisibilityGridDegree[nViewerTeam][v31 + v28 * v50];
                if ( v51 > 1.0 )
                  v51 = 1.0;
                ++v56;
                v40 = v51 + v40;
              }
            }
          }
          v31 = v53;
        }
        ++v28;
      }
      while ( v28 <= v52 );
      if ( v56 > 0 )
        return (float)(v40 / (float)v56);
      v5 = vLocation;
    }
    _Warning(
      a1: "CFoW: GetLocationVisibilityDegree() called with invalid view location of %g, %g, %g\n",
      v5->x,
      v5->y,
      v5->z);
    return 0.0;
  }
  else
  {
    v6.m128_i32[0] = 1258291200;
    v7 = (__m128)LODWORD(vLocation->x);
    v7.m128_f32[0] = (float)(v7.m128_f32[0] - this->m_vWorldMins.x) / (float)this->m_nHorizontalGridSize;
    v8 = _mm_and_ps((__m128)0x80000000, v7);
    v9.m128_i32[0] = v8.m128_i32[0];
    v6.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v7, v8), v6).m128_f32[0]) & 0x4B000000 | v8.m128_i32[0];
    v10 = v7;
    v10.m128_f32[0] = (float)(v7.m128_f32[0] + v6.m128_f32[0]) - v6.m128_f32[0];
    v11 = v10;
    v11.m128_f32[0] = v10.m128_f32[0] - v7.m128_f32[0];
    v10.m128_f32[0] = v10.m128_f32[0]
                    - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v11, v9).m128_f32[0]) & 0x3F800000);
    v11.m128_i32[0] = 1258291200;
    v12 = (int)v10.m128_f32[0] * this->m_nGridYUnits;
    v13 = (__m128)LODWORD(vLocation->y);
    v13.m128_f32[0] = (float)(v13.m128_f32[0] - this->m_vWorldMins.y) / (float)this->m_nHorizontalGridSize;
    v14 = _mm_and_ps((__m128)0x80000000, v13);
    v11.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v13, v14), v11).m128_f32[0]) & 0x4B000000
                    | v14.m128_i32[0];
    v15 = v13;
    v15.m128_f32[0] = (float)(v13.m128_f32[0] + v11.m128_f32[0]) - v11.m128_f32[0];
    v16 = v15;
    v16.m128_f32[0] = v15.m128_f32[0] - v13.m128_f32[0];
    v17 = (int)(float)(v15.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v16, v14).m128_u32[0] & 0x3F800000)) + v12;
    if ( v17 < 0 || v17 >= this->m_nTotalHorizontalUnits )
    {
      _Warning(
        a1: "CFoW: GetLocationVisibilityDegree() called with invalid view location of %g, %g, %g\n",
        vLocation->x,
        vLocation->y,
        vLocation->z);
      return 0.0;
    }
    else
    {
      v18 = this->m_pVisibilityGridDegree[nViewerTeam][v17];
      if ( v18 <= 1.0 )
        return v18;
      else
        return 1.0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F8010
// Name: private: void CUtlSphereTree::FreelistPush(struct CUtlSphereTree::NodeRef __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlSphereTree::FreelistPush(CUtlSphereTree *this, CUtlSphereTree::NodeRef *node)
{
  int nodeIndex; // edx

  if ( this->m_PrevInsertedNode == node->nodeIndex )
    this->m_PrevInsertedNode = -1;
  if ( node->nodeIndex < 0 )
    MEMORY[0] = this->m_FreelistHead;
  else
    LODWORD(node->pNodes->m_Memory.m_pMemory[node->nodeIndex].bounds.x) = this->m_FreelistHead;
  nodeIndex = node->nodeIndex;
  --this->m_NumNodesInTree;
  this->m_FreelistHead = nodeIndex;
}

//------------------------------------------------------------------------------
// Address: 0x101F8060
// Name: private: void CUtlSphereTree::SetNodeChildren(struct CUtlSphereTree::NodeRef __near &,struct CUtlSphereTree::NodeRef const __near &,struct CUtlSphereTree::NodeRef const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlSphereTree::SetNodeChildren(
        CUtlSphereTree *this,
        CUtlSphereTree::NodeRef *node,
        const CUtlSphereTree::NodeRef *childA,
        const CUtlSphereTree::NodeRef *childB)
{
  int nodeIndex; // esi
  CUtlSphereTree::Node *v5; // edx
  int v6; // ecx
  CUtlSphereTree::Node *v7; // eax
  bool v8; // dl
  CUtlSphereTree::Node *v9; // eax
  int v10; // ecx
  CUtlSphereTree::Node *v11; // eax
  int v12; // esi
  CUtlSphereTree::Node *v13; // eax
  int shallowIndex; // eax
  CUtlVector<CUtlSphereTree::Node,CUtlMemory<CUtlSphereTree::Node,int> > *pNodes; // ecx
  const Vector4D *p_bounds; // eax
  int v17; // edx
  int v18; // edx
  const Vector4D *v19; // edx
  Vector4D *v20; // esi
  int v21; // eax
  CUtlSphereTree::Node *v22; // ecx
  int deepIndex; // ecx
  CUtlVector<CUtlSphereTree::Node,CUtlMemory<CUtlSphereTree::Node,int> > *v24; // edx
  int v25; // ecx
  int v26; // eax
  Vector4D result; // [esp+Ch] [ebp-14h] BYREF
  CUtlSphereTree *v28; // [esp+1Ch] [ebp-4h]

  nodeIndex = childA->nodeIndex;
  v28 = this;
  if ( nodeIndex < 0 )
    v5 = nullptr;
  else
    v5 = &childA->pNodes->m_Memory.m_pMemory[nodeIndex];
  v6 = childB->nodeIndex;
  if ( childB->nodeIndex < 0 )
    v7 = nullptr;
  else
    v7 = &childB->pNodes->m_Memory.m_pMemory[v6];
  v8 = v5->maxDepth > v7->maxDepth;
  if ( v8 )
    v6 = nodeIndex;
  if ( node->nodeIndex < 0 )
    v9 = nullptr;
  else
    v9 = &node->pNodes->m_Memory.m_pMemory[node->nodeIndex];
  v9->deepIndex = v6;
  if ( v8 )
    v10 = childB->nodeIndex;
  else
    v10 = childA->nodeIndex;
  if ( node->nodeIndex < 0 )
    v11 = nullptr;
  else
    v11 = &node->pNodes->m_Memory.m_pMemory[node->nodeIndex];
  v11->shallowIndex = v10;
  v12 = node->nodeIndex;
  if ( node->nodeIndex < 0 )
    v13 = nullptr;
  else
    v13 = &node->pNodes->m_Memory.m_pMemory[v12];
  shallowIndex = v13->shallowIndex;
  pNodes = node->pNodes;
  if ( shallowIndex < 0 )
    p_bounds = nullptr;
  else
    p_bounds = &pNodes->m_Memory.m_pMemory[shallowIndex].bounds;
  if ( v12 < 0 )
    v17 = 0;
  else
    v17 = (int)&pNodes->m_Memory.m_pMemory[v12];
  v18 = *(_DWORD *)(v17 + 16);
  if ( v18 < 0 )
    v19 = nullptr;
  else
    v19 = &pNodes->m_Memory.m_pMemory[v18].bounds;
  if ( v12 < 0 )
    v20 = nullptr;
  else
    v20 = &pNodes->m_Memory.m_pMemory[v12].bounds;
  *v20 = *CUtlSphereTree::AddSpheres(this: v28, &result, pA: v19, pB: p_bounds);
  v21 = node->nodeIndex;
  if ( node->nodeIndex < 0 )
    v22 = nullptr;
  else
    v22 = &node->pNodes->m_Memory.m_pMemory[v21];
  deepIndex = v22->deepIndex;
  v24 = node->pNodes;
  if ( deepIndex < 0 )
    v25 = 0;
  else
    v25 = (int)&v24->m_Memory.m_pMemory[deepIndex];
  if ( v21 < 0 )
    v26 = 0;
  else
    v26 = (int)&v24->m_Memory.m_pMemory[v21];
  *(_DWORD *)(v26 + 28) = *(_DWORD *)(v25 + 28) + 1;
  if ( node->nodeIndex < 0 )
    MEMORY[0x18] = 0;
  else
    node->pNodes->m_Memory.m_pMemory[node->nodeIndex].pData = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101F81C0
// Name: private: bool CUtlSphereTree::NodeHasData(struct CUtlSphereTree::NodeRef const __near &,void const __near *,class Vector4D const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CUtlSphereTree::NodeHasData(
        CUtlSphereTree *this,
        const CUtlSphereTree::NodeRef *node,
        const void *pData,
        const Vector4D *bounds)
{
  int nodeIndex; // eax
  CUtlSphereTree::Node *v5; // ecx
  CUtlSphereTree::Node *v6; // ecx
  BOOL result; // eax

  nodeIndex = node->nodeIndex;
  if ( node->nodeIndex < 0 )
    v5 = nullptr;
  else
    v5 = &node->pNodes->m_Memory.m_pMemory[nodeIndex];
  result = false;
  if ( v5->pData == pData )
  {
    v6 = nodeIndex < 0 ? nullptr : &node->pNodes->m_Memory.m_pMemory[nodeIndex];
    if ( bounds->x == v6->bounds.x
      && bounds->y == v6->bounds.y
      && bounds->z == v6->bounds.z
      && bounds->w == v6->bounds.w )
    {
      return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F8250
// Name: private: bool CUtlSphereTree::IsSubtreeBalanced(struct CUtlSphereTree::NodeRef const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlSphereTree::IsSubtreeBalanced(CUtlSphereTree *this, const CUtlSphereTree::NodeRef *node)
{
  int nodeIndex; // ecx
  CUtlSphereTree::Node *v3; // eax
  CUtlSphereTree::Node *v4; // eax
  int deepIndex; // eax
  CUtlVector<CUtlSphereTree::Node,CUtlMemory<CUtlSphereTree::Node,int> > *pNodes; // edx
  int v7; // eax
  int v8; // ecx
  int v9; // ecx
  int v10; // ecx
  bool result; // al

  nodeIndex = node->nodeIndex;
  if ( node->nodeIndex < 0 )
    v3 = nullptr;
  else
    v3 = &node->pNodes->m_Memory.m_pMemory[nodeIndex];
  result = true;
  if ( v3->deepIndex >= 0 )
  {
    v4 = nodeIndex < 0 ? nullptr : &node->pNodes->m_Memory.m_pMemory[nodeIndex];
    deepIndex = v4->deepIndex;
    pNodes = node->pNodes;
    v7 = deepIndex < 0 ? 0 : (int)&pNodes->m_Memory.m_pMemory[deepIndex];
    v8 = nodeIndex < 0 ? 0 : (int)&pNodes->m_Memory.m_pMemory[nodeIndex];
    v9 = *(_DWORD *)(v8 + 20);
    v10 = v9 < 0 ? 0 : (int)&pNodes->m_Memory.m_pMemory[v9];
    if ( *(_DWORD *)(v7 + 28) > *(_DWORD *)(v10 + 28) + 1 )
      return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F82D0
// Name: private: float CUtlSphereTree::ComputePairingCost(struct CUtlSphereTree::NodeRef const __near &,struct CUtlSphereTree::NodeRef const __near &,struct CUtlSphereTree::NodeRef const __near &,struct CUtlSphereTree::NodeRef const __near *)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CUtlSphereTree::ComputePairingCost(
        CUtlSphereTree *this,
        const CUtlSphereTree::NodeRef *pair1A,
        const CUtlSphereTree::NodeRef *pair1B,
        const CUtlSphereTree::NodeRef *pair2A,
        const CUtlSphereTree::NodeRef *pair2B)
{
  CUtlSphereTree::Node *v6; // eax
  CUtlSphereTree::Node *v7; // ecx
  CUtlSphereTree::Node *v8; // edx
  Vector4D *p_outerSphere; // eax
  CUtlSphereTree::Node *v10; // eax
  double w; // st7
  Vector4D pair1Sphere; // [esp+4h] [ebp-30h] BYREF
  Vector4D outerSphere; // [esp+14h] [ebp-20h] BYREF
  Vector4D pair2Sphere; // [esp+24h] [ebp-10h] BYREF

  if ( pair1B->nodeIndex < 0 )
    v6 = nullptr;
  else
    v6 = &pair1B->pNodes->m_Memory.m_pMemory[pair1B->nodeIndex];
  if ( pair1A->nodeIndex < 0 )
    v7 = nullptr;
  else
    v7 = &pair1A->pNodes->m_Memory.m_pMemory[pair1A->nodeIndex];
  CUtlSphereTree::AddSpheres(this, result: &pair1Sphere, pA: &v7->bounds, pB: &v6->bounds);
  if ( pair2B != nullptr )
  {
    if ( pair2B->nodeIndex < 0 )
      v8 = nullptr;
    else
      v8 = &pair2B->pNodes->m_Memory.m_pMemory[pair2B->nodeIndex];
    if ( pair2A->nodeIndex < 0 )
      p_outerSphere = CUtlSphereTree::AddSpheres(this, result: &outerSphere, pA: nullptr, pB: &v8->bounds);
    else
      p_outerSphere = CUtlSphereTree::AddSpheres(
                        this,
                        result: &outerSphere,
                        pA: &pair2A->pNodes->m_Memory.m_pMemory[pair2A->nodeIndex].bounds,
                        pB: &v8->bounds);
  }
  else
  {
    if ( pair2A->nodeIndex < 0 )
      v10 = nullptr;
    else
      v10 = &pair2A->pNodes->m_Memory.m_pMemory[pair2A->nodeIndex];
    outerSphere = v10->bounds;
    p_outerSphere = &outerSphere;
  }
  w = p_outerSphere->w;
  pair2Sphere.x = p_outerSphere->x;
  pair2Sphere.w = w;
  pair2Sphere.y = p_outerSphere->y;
  pair2Sphere.z = p_outerSphere->z;
  CUtlSphereTree::AddSpheres(this, result: &outerSphere, pA: &pair1Sphere, pB: &pair2Sphere);
  return pair1Sphere.w * (pair1Sphere.w * pair1Sphere.w)
       + pair2Sphere.w * (pair2Sphere.w * pair2Sphere.w)
       + outerSphere.w * (outerSphere.w * outerSphere.w);
}

//------------------------------------------------------------------------------
// Address: 0x101F8400
// Name: public: virtual char const __near * CJob::Describe(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CJob::Describe(CJob *this)
{
  return "Job";
}

//------------------------------------------------------------------------------
// Address: 0x101F8410
// Name: private: virtual int CJob::DoAbort(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CJob::DoAbort(CJob *this, bool bDiscard)
{
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x101F84A0
// Name: public: virtual char const __near * CFunctorJob::Describe(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CFunctorJob::Describe(CFunctorJob *this)
{
  return this->m_szDescription;
}

//------------------------------------------------------------------------------
// Address: 0x101F84C0
// Name: public: virtual int CFunctorJob::DoExecute(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFunctorJob::DoExecute(CFunctorJob *this)
{
  this->m_pFunctor.m_pObject->operator()(this: this->m_pFunctor.m_pObject);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101F8510
// Name: public: void CFoW::RemoveTriSoup(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoW::RemoveTriSoup(CFoW *this, int nID)
{
  CFoW_TriSoupCollection **m_pMemory; // eax
  bool v4; // zf
  CFoW_TriSoupCollection **v5; // eax
  CFoW_TriSoupCollection *v6; // edi

  m_pMemory = this->m_TriSoupCollection.m_Memory.m_pMemory;
  v4 = m_pMemory[nID] == nullptr;
  v5 = &m_pMemory[nID];
  if ( !v4 )
  {
    v6 = *v5;
    if ( *v5 != nullptr )
    {
      CFoW_TriSoupCollection::~CFoW_TriSoupCollection(this: *v5);
      operator delete(p: v6);
    }
    this->m_TriSoupCollection.m_Memory.m_pMemory[nID] = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F8560
// Name: public: void CFoW::ClearTriSoup(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoW::ClearTriSoup(CFoW *this, int nID)
{
  int i; // edi
  int j; // edi
  CFoW_TriSoupCollection **m_pMemory; // eax
  bool v6; // zf
  CFoW_TriSoupCollection **v7; // eax

  CFoW_TriSoupCollection::Clear(this: this->m_TriSoupCollection.m_Memory.m_pMemory[nID]);
  for ( i = 0; i < this->m_nGridZUnits; ++i )
    CFoW_HorizontalSlice::Clear(this: this->m_pHorizontalSlices[i]);
  for ( j = 0; j < this->m_TriSoupCollection.m_Size; ++j )
  {
    m_pMemory = this->m_TriSoupCollection.m_Memory.m_pMemory;
    v6 = m_pMemory[j] == nullptr;
    v7 = &m_pMemory[j];
    if ( !v6 )
      CFoW_TriSoupCollection::RepopulateOccluders(this: *v7, pFoW: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F85D0
// Name: public: void CFoW::AddTri(int,class Vector __near &,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoW::AddTri(CFoW *this, int nID, Vector *vPointA, Vector *vPointB, Vector *vPointC)
{
  CFoW_TriSoupCollection::AddTri(
    this: this->m_TriSoupCollection.m_Memory.m_pMemory[nID],
    pFoW: this,
    vPointA,
    vPointB,
    vPointC);
}

//------------------------------------------------------------------------------
// Address: 0x101F8600
// Name: private: void CFoW::MergeViewerVisibility(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoW::MergeViewerVisibility(CFoW *this, int nID)
{
  CFoW_Viewer *v2; // edi
  __m128 x_low; // xmm1
  __m128 v4; // xmm4
  __m128 v5; // xmm0
  __m128 v6; // xmm3
  float m_nHorizontalGridSize; // xmm5_4
  __m128 v8; // xmm2
  __m128 v9; // xmm7
  __m128 v10; // xmm2
  __m128 v11; // xmm3
  int v12; // edx
  __m128 y_low; // xmm2
  __m128 v14; // xmm0
  __m128 v15; // xmm3
  __m128 v16; // xmm3
  __m128 v17; // xmm4
  int v18; // eax
  int m_nGridUnits; // esi
  __m128 v20; // xmm4
  __m128 v21; // xmm0
  __m128 v22; // xmm3
  __m128 v23; // xmm6
  int v24; // ebx
  __m128 v25; // xmm0
  __m128 v26; // xmm1
  unsigned __int8 *v27; // eax
  int m_nGridXUnits; // esi
  int m_nGridYUnits; // ecx
  unsigned __int8 m_nHeightGroup; // bl
  int v31; // esi
  unsigned __int8 v32; // cl
  float m_flRadius; // [esp+8h] [ebp-1Ch]
  int v34; // [esp+8h] [ebp-1Ch]
  int v35; // [esp+Ch] [ebp-18h]
  int v36; // [esp+10h] [ebp-14h]
  int v37; // [esp+14h] [ebp-10h]
  int v38; // [esp+18h] [ebp-Ch]
  int v39; // [esp+18h] [ebp-Ch]
  int v40; // [esp+1Ch] [ebp-8h]
  unsigned __int8 *m_pVisibility; // [esp+20h] [ebp-4h]

  v2 = this->m_Viewers.m_Memory.m_pMemory[nID];
  if ( v2 != nullptr )
  {
    x_low = (__m128)LODWORD(v2->m_vLocation.x);
    v4.m128_i32[0] = 1258291200;
    m_flRadius = v2->m_flRadius;
    v5 = x_low;
    v6.m128_i32[0] = 1258291200;
    m_nHorizontalGridSize = (float)this->m_nHorizontalGridSize;
    v5.m128_f32[0] = (float)((float)(x_low.m128_f32[0] - m_flRadius) - this->m_vWorldMins.x) / m_nHorizontalGridSize;
    v8 = _mm_and_ps((__m128)0x80000000, v5);
    v9.m128_i32[0] = v8.m128_i32[0];
    v6.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v5, v8), v6).m128_f32[0]) & 0x4B000000 | v8.m128_i32[0];
    v10 = v5;
    v10.m128_f32[0] = (float)(v5.m128_f32[0] + v6.m128_f32[0]) - v6.m128_f32[0];
    v11 = v10;
    v11.m128_f32[0] = v10.m128_f32[0] - v5.m128_f32[0];
    v12 = (int)(float)(v10.m128_f32[0]
                     - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v11, v9).m128_f32[0]) & 0x3F800000));
    y_low = (__m128)LODWORD(v2->m_vLocation.y);
    v14 = y_low;
    v14.m128_f32[0] = (float)((float)(y_low.m128_f32[0] - m_flRadius) - this->m_vWorldMins.y) / m_nHorizontalGridSize;
    v15 = _mm_and_ps((__m128)0x80000000, v14);
    v9.m128_i32[0] = v15.m128_i32[0];
    v4.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v14, v15), v4).m128_f32[0]) & 0x4B000000;
    v16 = v14;
    v16.m128_f32[0] = (float)(v14.m128_f32[0] + COERCE_FLOAT(v4.m128_i32[0] | v9.m128_i32[0]))
                    - COERCE_FLOAT(v4.m128_i32[0] | v9.m128_i32[0]);
    v17 = v16;
    v17.m128_f32[0] = v16.m128_f32[0] - v14.m128_f32[0];
    v18 = (int)(float)(v16.m128_f32[0]
                     - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v17, v9).m128_f32[0]) & 0x3F800000));
    v16.m128_i32[0] = 1258291200;
    x_low.m128_f32[0] = (float)((float)(x_low.m128_f32[0] - m_flRadius) - this->m_vWorldMins.x) / m_nHorizontalGridSize;
    m_nGridUnits = v2->m_nGridUnits;
    v20 = _mm_and_ps((__m128)0x80000000, x_low);
    v35 = v18;
    v37 = m_nGridUnits + v18;
    v16.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(x_low, v20), v16).m128_f32[0]) & 0x4B000000
                    | v20.m128_i32[0];
    v21 = x_low;
    v38 = m_nGridUnits + v12;
    m_pVisibility = v2->m_pVisibility;
    v21.m128_f32[0] = (float)(x_low.m128_f32[0] + v16.m128_f32[0]) - v16.m128_f32[0];
    v22 = v21;
    v22.m128_f32[0] = v21.m128_f32[0] - x_low.m128_f32[0];
    x_low.m128_i32[0] = 1258291200;
    y_low.m128_f32[0] = (float)((float)(y_low.m128_f32[0] - m_flRadius) - this->m_vWorldMins.y) / m_nHorizontalGridSize;
    v23 = _mm_and_ps((__m128)0x80000000, y_low);
    x_low.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(y_low, v23), x_low).m128_f32[0]) & 0x4B000000
                      | v23.m128_i32[0];
    v24 = (int)(float)(v21.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v22, v20).m128_u32[0] & 0x3F800000))
        * this->m_nGridYUnits;
    v25 = y_low;
    v25.m128_f32[0] = (float)(y_low.m128_f32[0] + x_low.m128_f32[0]) - x_low.m128_f32[0];
    v26 = v25;
    v26.m128_f32[0] = v25.m128_f32[0] - y_low.m128_f32[0];
    v27 = &this->m_pVisibilityGridFlags[v2->m_nViewerTeam][v24
                                                         + (int)(float)(v25.m128_f32[0]
                                                                      - COERCE_FLOAT(
                                                                          _mm_cmpgt_ss(v26, v23).m128_u32[0]
                                                                        & 0x3F800000))];
    v40 = this->m_nGridYUnits - m_nGridUnits;
    v36 = 0;
    if ( v12 < 0 )
    {
      m_pVisibility -= m_nGridUnits * v12;
      v27 -= v12 * this->m_nGridYUnits;
      v12 = 0;
    }
    m_nGridXUnits = v38;
    if ( v38 > this->m_nGridXUnits )
    {
      m_nGridXUnits = this->m_nGridXUnits;
      v38 = m_nGridXUnits;
    }
    if ( v35 < 0 )
    {
      m_pVisibility -= v35;
      v40 -= v35;
      v27 -= v35;
      v36 = -v35;
      m_nGridXUnits = v38;
      v35 = 0;
    }
    if ( v37 > this->m_nGridYUnits )
    {
      m_nGridYUnits = this->m_nGridYUnits;
      v40 += v37 - m_nGridYUnits;
      v36 += v37 - m_nGridYUnits;
      m_nGridXUnits = v38;
      v37 = m_nGridYUnits;
    }
    m_nHeightGroup = v2->m_nHeightGroup;
    v39 = 0;
    if ( v12 >= m_nGridXUnits )
      goto LABEL_20;
    v34 = m_nGridXUnits - v12;
    do
    {
      if ( v35 < v37 )
      {
        v31 = v37 - v35;
        v39 += v37 - v35;
        do
        {
          *v27 |= *m_pVisibility;
          v32 = *v27;
          if ( (*m_pVisibility & 0x20) != 0 && (unsigned __int8)(v32 & 7) < m_nHeightGroup )
            *v27 = m_nHeightGroup | v32 & 0xF8;
          ++m_pVisibility;
          ++v27;
          --v31;
        }
        while ( v31 != 0 );
      }
      v27 += v40;
      m_pVisibility += v36;
      --v34;
    }
    while ( v34 != 0 );
    if ( v39 == 0 )
LABEL_20:
      _Warning(
        a1: "CFoW: MergeViewerVisibility() Viewer %d has no contribution at location of %g, %g, %g\n",
        nID,
        v2->m_vLocation.x,
        v2->m_vLocation.y,
        v2->m_vLocation.z);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F88F0
// Name: public: virtual void CFunctor1<void (*)(class CFoW __near *),class CFoW __near *,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctor1<void (__cdecl *)(CFoW *),CFoW *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::operator()(
        CFunctor1<void (__cdecl*)(CFoW *),CFoW *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *this)
{
  this->m_pfnProxied(a1: this->m_arg1);
}

//------------------------------------------------------------------------------
// Address: 0x101F8900
// Name: public: virtual void CFunctor2<void (*)(class CFoW __near *,class CFoW_Viewer __near *),class CFoW __near *,class CFoW_Viewer __near *,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctor2<void (__cdecl *)(CFoW *,CFoW_Viewer *),CFoW *,CFoW_Viewer *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::operator()(
        CFunctor2<void (__cdecl*)(CFoW *,CFoW_Viewer *),CFoW *,CFoW_Viewer *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *this)
{
  this->m_pfnProxied(a1: this->m_arg1, a2: this->m_arg2);
}

//------------------------------------------------------------------------------
// Address: 0x101F8CB0
// Name: private: void CUtlSphereTree::RebalanceSubtrees(struct CUtlSphereTree::NodeRef __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlSphereTree::RebalanceSubtrees(CUtlSphereTree *this, CUtlSphereTree::NodeRef *node, bool bInserting)
{
  int nodeIndex; // ecx
  CUtlSphereTree::Node *v4; // eax
  CUtlVector<CUtlSphereTree::Node,CUtlMemory<CUtlSphereTree::Node,int> > *pNodes; // eax
  int v6; // ecx
  int v7; // ecx
  int v8; // edx
  int v9; // edx
  int v10; // ecx
  int v11; // ecx
  int v12; // esi
  int v13; // esi
  int v14; // esi
  int v15; // edi
  int v16; // esi
  int v17; // esi
  int v18; // edx
  int v19; // ecx
  int v20; // edx
  int v21; // ecx
  int v22; // ecx
  int v23; // eax
  int v24; // ebx
  int v25; // eax
  CUtlSphereTree::Node *v26; // edi
  CUtlSphereTree::Node *v27; // esi
  float x; // xmm1_4
  float y; // xmm2_4
  float z; // xmm3_4
  float v31; // xmm0_4
  int v32; // eax
  float *v33; // eax
  float v34; // xmm4_4
  float v35; // xmm5_4
  float *v36; // eax
  float v37; // xmm0_4
  int v38; // esi
  int v39; // edi
  CUtlSphereTree::NodeRef *v40; // ebx
  double v41; // st7
  CUtlSphereTree *v42; // esi
  CUtlSphereTree *v43; // edi
  CUtlSphereTree::NodeRef *v44; // esi
  float v45; // [esp+10h] [ebp-A8h]
  float v46[4]; // [esp+14h] [ebp-A4h] BYREF
  Vector v47; // [esp+24h] [ebp-94h] BYREF
  CUtlSphereTree::NodeRef greatNephews[4]; // [esp+30h] [ebp-88h] BYREF
  float v49; // [esp+50h] [ebp-68h]
  float w; // [esp+54h] [ebp-64h]
  float v51; // [esp+58h] [ebp-60h]
  Vector vec; // [esp+5Ch] [ebp-5Ch] BYREF
  _DWORD v53[3]; // [esp+68h] [ebp-50h] BYREF
  float v54; // [esp+74h] [ebp-44h]
  CUtlSphereTree::NodeRef nephews[2]; // [esp+78h] [ebp-40h] BYREF
  CUtlSphereTree::NodeRef deepChild; // [esp+88h] [ebp-30h] BYREF
  int nephewMask; // [esp+90h] [ebp-28h]
  CUtlSphereTree::NodeRef shallowChild; // [esp+94h] [ebp-24h] BYREF
  CUtlSphereTree *v59; // [esp+9Ch] [ebp-1Ch]
  int v60; // [esp+A0h] [ebp-18h]
  float minCost; // [esp+A4h] [ebp-14h]
  float cost; // [esp+A8h] [ebp-10h]
  int greatNephewMask; // [esp+ACh] [ebp-Ch]
  int bestIndex; // [esp+B0h] [ebp-8h]
  bool nephewBest; // [esp+B7h] [ebp-1h]

  v59 = this;
  if ( !CUtlSphereTree::IsSubtreeBalanced(this, node) )
  {
    nodeIndex = node->nodeIndex;
    if ( node->nodeIndex < 0 )
      v4 = nullptr;
    else
      v4 = &node->pNodes->m_Memory.m_pMemory[nodeIndex];
    shallowChild.nodeIndex = v4->shallowIndex;
    pNodes = node->pNodes;
    shallowChild.pNodes = pNodes;
    if ( nodeIndex < 0 )
      v6 = 0;
    else
      v6 = (int)&pNodes->m_Memory.m_pMemory[nodeIndex];
    v7 = *(_DWORD *)(v6 + 16);
    deepChild.nodeIndex = v7;
    deepChild.pNodes = pNodes;
    if ( v7 < 0 )
      v8 = 0;
    else
      v8 = (int)&pNodes->m_Memory.m_pMemory[v7];
    v9 = *(_DWORD *)(v8 + 20);
    nephews[0].nodeIndex = v9;
    nephews[0].pNodes = pNodes;
    if ( v7 < 0 )
      v10 = 0;
    else
      v10 = (int)&pNodes->m_Memory.m_pMemory[v7];
    v11 = *(_DWORD *)(v10 + 16);
    nephews[1].nodeIndex = v11;
    nephews[1].pNodes = pNodes;
    if ( v9 < 0 )
      v12 = 0;
    else
      v12 = (int)&pNodes->m_Memory.m_pMemory[v9];
    greatNephews[0].nodeIndex = *(_DWORD *)(v12 + 20);
    greatNephews[0].pNodes = pNodes;
    if ( v9 < 0 )
      v13 = 0;
    else
      v13 = (int)&pNodes->m_Memory.m_pMemory[v9];
    greatNephews[1].nodeIndex = *(_DWORD *)(v13 + 16);
    greatNephews[1].pNodes = pNodes;
    if ( v11 < 0 )
      v14 = 0;
    else
      v14 = (int)&pNodes->m_Memory.m_pMemory[v11];
    v15 = *(_DWORD *)(v14 + 20);
    greatNephews[2].nodeIndex = v15;
    greatNephews[2].pNodes = pNodes;
    if ( v11 < 0 )
      v16 = 0;
    else
      v16 = (int)&pNodes->m_Memory.m_pMemory[v11];
    v17 = *(_DWORD *)(v16 + 16);
    greatNephews[3].nodeIndex = v17;
    greatNephews[3].pNodes = pNodes;
    nephewMask = 3;
    greatNephewMask = 15;
    if ( v9 < 0 )
      v18 = 0;
    else
      v18 = (int)&pNodes->m_Memory.m_pMemory[v9];
    if ( v11 < 0 )
      v19 = 0;
    else
      v19 = (int)&pNodes->m_Memory.m_pMemory[v11];
    if ( *(_DWORD *)(v18 + 28) == *(_DWORD *)(v19 + 28) )
    {
      if ( greatNephews[0].nodeIndex < 0 )
        v20 = 0;
      else
        v20 = (int)&pNodes->m_Memory.m_pMemory[greatNephews[0].nodeIndex];
      if ( greatNephews[1].nodeIndex < 0 )
        v21 = 0;
      else
        v21 = (int)&pNodes->m_Memory.m_pMemory[greatNephews[1].nodeIndex];
      if ( *(_DWORD *)(v20 + 28) < *(_DWORD *)(v21 + 28) )
        greatNephewMask = 13;
      if ( v15 < 0 )
        v22 = 0;
      else
        v22 = (int)&pNodes->m_Memory.m_pMemory[v15];
      if ( v17 < 0 )
        v23 = 0;
      else
        v23 = (int)&pNodes->m_Memory.m_pMemory[v17];
      if ( *(_DWORD *)(v22 + 28) < *(_DWORD *)(v23 + 28) )
        greatNephewMask ^= 8u;
    }
    else
    {
      nephewMask = 1;
      greatNephewMask = 12;
    }
    minCost = 3.4028235e38;
    bestIndex = -1;
    nephewBest = true;
    v24 = 0;
    v60 = 1;
    do
    {
      if ( (nephewMask & v60) != 0 )
      {
        v25 = nephews[v24].nodeIndex;
        LODWORD(cost) = &nephews[v24 ^ 1];
        if ( v25 < 0 )
          v26 = nullptr;
        else
          v26 = &nephews[v24].pNodes->m_Memory.m_pMemory[v25];
        if ( shallowChild.nodeIndex < 0 )
          v27 = nullptr;
        else
          v27 = &shallowChild.pNodes->m_Memory.m_pMemory[shallowChild.nodeIndex];
        w = v27->bounds.w;
        v49 = v26->bounds.w;
        vec.x = v27->bounds.x - v26->bounds.x;
        vec.y = v27->bounds.y - v26->bounds.y;
        vec.z = v27->bounds.z - v26->bounds.z;
        v51 = VectorNormalize(&vec);
        if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(w - v49) & _mask__AbsFloat_) <= v51 )
        {
          v31 = (float)((float)(v49 + w) + v51) * 0.5;
          x = v26->bounds.x + (float)(vec.x * (float)(v31 - v49));
          y = v26->bounds.y + (float)(vec.y * (float)(v31 - v49));
          z = v26->bounds.z + (float)(vec.z * (float)(v31 - v49));
        }
        else
        {
          if ( w <= v49 )
            v27 = v26;
          x = v27->bounds.x;
          y = v27->bounds.y;
          z = v27->bounds.z;
          v31 = v27->bounds.w;
        }
        v32 = *(_DWORD *)LODWORD(cost);
        v54 = v31;
        *(float *)&v53[2] = z;
        *(float *)&v53[1] = y;
        *(float *)v53 = x;
        if ( v32 < 0 )
          v33 = nullptr;
        else
          v33 = (float *)(**(_DWORD **)(LODWORD(cost) + 4) + 32 * v32);
        v34 = v33[1];
        v35 = v33[2];
        v45 = v33[3];
        v46[0] = *v33;
        v46[1] = v34;
        v46[2] = v35;
        v46[3] = v45;
        v47.x = x - v46[0];
        v47.y = y - v34;
        v47.z = z - v35;
        cost = VectorNormalize(vec: &v47);
        if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(v54 - v45) & _mask__AbsFloat_) <= cost )
        {
          v37 = (float)((float)(v45 + v54) + cost) * 0.5;
        }
        else
        {
          v36 = (float *)v53;
          if ( v54 <= v45 )
            v36 = v46;
          v37 = v36[3];
        }
        if ( minCost > (float)((float)((float)((float)(v45 * v45) * v45) + (float)((float)(v54 * v54) * v54))
                             + (float)((float)(v37 * v37) * v37)) )
        {
          minCost = (float)((float)((float)(v45 * v45) * v45) + (float)((float)(v54 * v54) * v54))
                  + (float)((float)(v37 * v37) * v37);
          bestIndex = v24;
        }
      }
      ++v24;
      v60 = __ROL4__(v60, 1);
    }
    while ( v24 < 2 );
    v38 = 0;
    v39 = 1;
    v40 = greatNephews;
    do
    {
      if ( (v39 & greatNephewMask) != 0 )
      {
        v41 = CUtlSphereTree::ComputePairingCost(
                this: v59,
                pair1A: &shallowChild,
                pair1B: v40,
                pair2A: &nephews[(v38 ^ 2) >> 1],
                pair2B: &greatNephews[v38 ^ 1]);
        cost = v41;
        if ( minCost > v41 )
        {
          minCost = cost;
          bestIndex = v38;
          nephewBest = false;
        }
      }
      ++v38;
      ++v40;
      v39 = __ROL4__(v39, 1);
    }
    while ( v38 < 4 );
    if ( nephewBest )
    {
      v42 = v59;
      CUtlSphereTree::SetNodeChildren(this: v59, node: &deepChild, childA: &shallowChild, childB: &nephews[bestIndex]);
      CUtlSphereTree::SetNodeChildren(this: v42, node, childA: &deepChild, childB: &nephews[bestIndex ^ 1]);
    }
    else
    {
      v43 = v59;
      v44 = &nephews[bestIndex >> 1];
      CUtlSphereTree::SetNodeChildren(
        this: v59,
        node: &deepChild,
        childA: &nephews[(bestIndex ^ 2) >> 1],
        childB: &greatNephews[bestIndex ^ 1]);
      CUtlSphereTree::SetNodeChildren(this: v43, node: v44, childA: &shallowChild, childB: &greatNephews[bestIndex]);
      CUtlSphereTree::SetNodeChildren(this: v43, node, childA: &deepChild, childB: v44);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F9A40
// Name: private: int CUtlSphereTree::Remove_R(struct CUtlSphereTree::NodeRef __near &,void const __near *,class Vector4D const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSphereTree::Remove_R(
        CUtlSphereTree *this,
        CUtlSphereTree::NodeRef *node,
        const void *pData,
        const Vector4D *bounds)
{
  int nodeIndex; // edx
  CUtlSphereTree::Node *v6; // eax
  CUtlVector<CUtlSphereTree::Node,CUtlMemory<CUtlSphereTree::Node,int> > *pNodes; // ecx
  int v8; // eax
  int v9; // edx
  int v10; // eax
  CUtlSphereTree::NodeRef *p_shallowChild; // esi
  CUtlSphereTree::NodeRef *p_deepChild; // eax
  int v13; // ebx
  int v14; // eax
  int v15; // edx
  float *p_x; // edx
  const Vector4D *v17; // ecx
  int v18; // eax
  int v19; // esi
  CUtlSphereTree::Node *v20; // eax
  int v21; // ecx
  int v22; // eax
  int *v23; // eax
  int v24; // ecx
  int result; // eax
  CUtlSphereTree::Node *v26; // eax
  CUtlVector<CUtlSphereTree::Node,CUtlMemory<CUtlSphereTree::Node,int> > *otherChild_4; // [esp+10h] [ebp-20h]
  CUtlSphereTree::NodeRef deepChild; // [esp+14h] [ebp-1Ch] BYREF
  CUtlSphereTree::NodeRef shallowChild; // [esp+1Ch] [ebp-14h] BYREF
  CUtlVector<CUtlSphereTree::Node,CUtlMemory<CUtlSphereTree::Node,int> > *v30; // [esp+24h] [ebp-Ch]
  int v31; // [esp+28h] [ebp-8h]
  int i; // [esp+2Ch] [ebp-4h]

  nodeIndex = node->nodeIndex;
  v31 = nodeIndex;
  if ( nodeIndex < 0 )
    v6 = nullptr;
  else
    v6 = &node->pNodes->m_Memory.m_pMemory[nodeIndex];
  pNodes = node->pNodes;
  deepChild.nodeIndex = v6->deepIndex;
  v30 = pNodes;
  deepChild.pNodes = pNodes;
  if ( nodeIndex < 0 )
    v8 = 0;
  else
    v8 = (int)&pNodes->m_Memory.m_pMemory[nodeIndex];
  v9 = *(_DWORD *)(v8 + 20);
  v10 = 0;
  shallowChild.nodeIndex = v9;
  shallowChild.pNodes = pNodes;
  i = 0;
  while ( 1 )
  {
    if ( v10 != 0 )
    {
      p_shallowChild = &shallowChild;
      p_deepChild = &deepChild;
    }
    else
    {
      p_shallowChild = &deepChild;
      p_deepChild = &shallowChild;
    }
    v13 = p_deepChild->nodeIndex;
    otherChild_4 = p_deepChild->pNodes;
    v14 = p_shallowChild->nodeIndex;
    v15 = p_shallowChild->nodeIndex < 0 ? 0 : (int)&p_shallowChild->pNodes->m_Memory.m_pMemory[v14];
    if ( *(const void **)(v15 + 24) == pData )
      break;
    v17 = bounds;
LABEL_25:
    v10 = i + 1;
    i = v10;
    if ( v10 >= 2 )
    {
      v19 = -1;
      if ( deepChild.nodeIndex < 0 )
        v20 = nullptr;
      else
        v20 = &deepChild.pNodes->m_Memory.m_pMemory[deepChild.nodeIndex];
      if ( v20->deepIndex >= 0 )
      {
        v19 = CUtlSphereTree::Remove_R(this, node: &deepChild, pData, bounds: v17);
        if ( v19 >= 0 )
        {
LABEL_53:
          CUtlSphereTree::SetNodeChildren(this, node, childA: &deepChild, childB: &shallowChild);
          CUtlSphereTree::RebalanceSubtrees(this, node, bInserting: false);
          return v19;
        }
        v17 = bounds;
      }
      if ( shallowChild.nodeIndex < 0 )
        v26 = nullptr;
      else
        v26 = &shallowChild.pNodes->m_Memory.m_pMemory[shallowChild.nodeIndex];
      if ( v26->deepIndex >= 0 )
        v19 = CUtlSphereTree::Remove_R(this, node: &shallowChild, pData, bounds: v17);
      if ( v19 < 0 )
        return v19;
      goto LABEL_53;
    }
  }
  if ( v14 < 0 )
    p_x = nullptr;
  else
    p_x = &p_shallowChild->pNodes->m_Memory.m_pMemory[v14].bounds.x;
  v17 = bounds;
  if ( bounds->x != *p_x || bounds->y != p_x[1] || bounds->z != p_x[2] || bounds->w != p_x[3] )
    goto LABEL_25;
  if ( v13 < 0 )
    v18 = 0;
  else
    v18 = (int)&otherChild_4->m_Memory.m_pMemory[v13];
  if ( v31 < 0 )
    v21 = 0;
  else
    v21 = (int)&v30->m_Memory.m_pMemory[v31];
  *(float *)v21 = *(float *)v18;
  *(float *)(v21 + 4) = *(float *)(v18 + 4);
  *(float *)(v21 + 8) = *(float *)(v18 + 8);
  *(float *)(v21 + 12) = *(float *)(v18 + 12);
  *(_DWORD *)(v21 + 16) = *(_DWORD *)(v18 + 16);
  *(_DWORD *)(v21 + 20) = *(_DWORD *)(v18 + 20);
  *(_DWORD *)(v21 + 24) = *(_DWORD *)(v18 + 24);
  *(_DWORD *)(v21 + 28) = *(_DWORD *)(v18 + 28);
  v22 = p_shallowChild->nodeIndex;
  if ( this->m_PrevInsertedNode == p_shallowChild->nodeIndex )
    this->m_PrevInsertedNode = -1;
  if ( v22 < 0 )
    v23 = nullptr;
  else
    v23 = (int *)&p_shallowChild->pNodes->m_Memory.m_pMemory[v22];
  *v23 = this->m_FreelistHead;
  v24 = p_shallowChild->nodeIndex;
  --this->m_NumNodesInTree;
  this->m_FreelistHead = v24;
  if ( this->m_PrevInsertedNode == v13 )
    this->m_PrevInsertedNode = -1;
  if ( v13 < 0 )
    MEMORY[0] = v24;
  else
    LODWORD(otherChild_4->m_Memory.m_pMemory[v13].bounds.x) = v24;
  --this->m_NumNodesInTree;
  result = p_shallowChild->nodeIndex;
  this->m_FreelistHead = v13;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F9C80
// Name: public: void CFoW::SolveVisibility(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoW::SolveVisibility(CFoW *this, float flFrameTime)
{
  int v3; // esi
  int i; // edi
  CFoW_Viewer **m_pMemory; // eax
  bool v6; // zf
  CFoW_Viewer **v7; // eax
  CFoW_Viewer *v8; // eax
  void *v9; // esp
  void *v10; // esp
  CThreadEvent **v11; // edi
  CJob *v12; // esi
  CJob_vtbl *v13; // eax
  CJob_vtbl *v14; // edi
  CJob **v15; // ecx
  int v16; // ecx
  CThreadEvent **v17; // edi
  CFoW_Viewer **v18; // eax
  CFoW_Viewer **v19; // eax
  CFoW_Viewer *v20; // eax
  CJob *v21; // esi
  CFoW_Viewer **v22; // edi
  CJob_vtbl *v23; // eax
  CJob_vtbl *v24; // edi
  CJob **v25; // ecx
  int j; // esi
  _BYTE v27[12]; // [esp+4h] [ebp-20h] BYREF
  CThreadEvent **v28; // [esp+10h] [ebp-14h]
  CJob **v29; // [esp+14h] [ebp-10h]
  int v30; // [esp+18h] [ebp-Ch]
  CThreadEvent **v31; // [esp+1Ch] [ebp-8h]
  int v32; // [esp+20h] [ebp-4h]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CFoW::SolveVisibility",
    a3: 0,
    a4: "Unaccounted",
    a5: false,
    a6: 4);
  v3 = 0;
  for ( i = 1; v3 < this->m_Viewers.m_Size; ++v3 )
  {
    m_pMemory = this->m_Viewers.m_Memory.m_pMemory;
    v6 = m_pMemory[v3] == nullptr;
    v7 = &m_pMemory[v3];
    if ( !v6 )
    {
      v8 = *v7;
      if ( v8->m_flRadius > 1.0 )
      {
        if ( v8->m_bDirty )
          ++i;
      }
      else
      {
        _Warning(a1: "CFoW: Viewer %d has invalid radius!\n", v3);
      }
    }
  }
  v9 = alloca(4 * i);
  v29 = (CJob **)v27;
  v10 = alloca(4 * i);
  v11 = (CThreadEvent **)v27;
  v31 = (CThreadEvent **)v27;
  v12 = (CJob *)operator new(nSize: 0x44u);
  if ( v12 != nullptr )
  {
    v13 = (CJob_vtbl *)operator new(nSize: 0x18u);
    if ( v13 != nullptr )
    {
      v13->DoExecute = (int (__thiscall *)(CJob *))1;
      v13->AddRef = (int (__thiscall *)(struct CJob *))&CFunctor1<void (__cdecl *)(CFoW *),CFoW *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
      v13->Describe = (const char *(__thiscall *)(CJob *))&CFunctor1<void (__cdecl *)(CFoW *),CFoW *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
      v13->DoAbort = (int (__thiscall *)(CJob *, bool))PrepVisibilityThreaded;
      v13->DoCleanup = (void (__thiscall *)(CJob *))this;
      v14 = v13;
    }
    else
    {
      v14 = nullptr;
    }
    v12->m_iRefs = 1;
    v12->m_priority = JP_NORMAL;
    v12->CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = (CJob_vtbl *)&CJob::`vftable'{for `IRefCounted'};
    v12->CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v12->m_status = 4;
    v12->m_mutex.m_ownerID = 0;
    v12->m_mutex.m_depth = 0;
    *(_WORD *)&v12->m_flags = -256;
    v12->m_ThreadPoolData = (ThreadPoolData_t__ *)-1;
    v12->m_pThreadPool = nullptr;
    CThreadEvent::CThreadEvent(this: &v12->m_CompleteEvent, a2: true);
    v12->CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = (CJob_vtbl *)&CFunctorJob::`vftable'{for `IRefCounted'};
    v12->CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CFunctorJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v12[1].CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = v14;
    v11 = v31;
    LOBYTE(v12[1].CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable) = 0;
  }
  else
  {
    v12 = nullptr;
  }
  v15 = v29;
  v12->m_flags = 8;
  *v15 = v12;
  _g_pThreadPool->AddJob(this: _g_pThreadPool, a2: v12);
  v16 = 0;
  *v11 = &v12->m_CompleteEvent;
  v30 = 1;
  v32 = 0;
  if ( this->m_Viewers.m_Size > 0 )
  {
    v17 = v11 + 1;
    v28 = v17;
    v29 = (CJob **)((char *)v29 - (int)v31);
    do
    {
      v18 = this->m_Viewers.m_Memory.m_pMemory;
      v6 = v18[v16] == nullptr;
      v19 = &v18[v16];
      if ( !v6 )
      {
        v20 = *v19;
        if ( v20->m_flRadius > 1.0 && v20->m_bDirty )
        {
          v21 = (CJob *)operator new(nSize: 0x44u);
          if ( v21 != nullptr )
          {
            v22 = &this->m_Viewers.m_Memory.m_pMemory[v32];
            v23 = (CJob_vtbl *)operator new(nSize: 0x1Cu);
            if ( v23 != nullptr )
            {
              v23->DoExecute = (int (__thiscall *)(CJob *))1;
              v23->AddRef = (int (__thiscall *)(struct CJob *))&CFunctor2<void (__cdecl *)(CFoW *,CFoW_Viewer *),CFoW *,CFoW_Viewer *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
              v23->Describe = (const char *(__thiscall *)(CJob *))&CFunctor2<void (__cdecl *)(CFoW *,CFoW_Viewer *),CFoW *,CFoW_Viewer *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
              v23->DoAbort = (int (__thiscall *)(CJob *, bool))CalcLocalizedVisibilityThreaded;
              v23->DoCleanup = (void (__thiscall *)(CJob *))this;
              v23[1].AddRef = (int (__thiscall *)(struct CJob *))*v22;
              v24 = v23;
            }
            else
            {
              v24 = nullptr;
            }
            v21->m_iRefs = 1;
            v21->CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = (CJob_vtbl *)&CJob::`vftable'{for `IRefCounted'};
            v21->CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
            v21->m_status = 4;
            v21->m_priority = JP_NORMAL;
            v21->m_mutex.m_ownerID = 0;
            v21->m_mutex.m_depth = 0;
            v21->m_pThreadPool = nullptr;
            *(_WORD *)&v21->m_flags = -256;
            v21->m_ThreadPoolData = (ThreadPoolData_t__ *)-1;
            CThreadEvent::CThreadEvent(this: &v21->m_CompleteEvent, a2: true);
            v21->CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = (CJob_vtbl *)&CFunctorJob::`vftable'{for `IRefCounted'};
            v21->CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CFunctorJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
            v21[1].CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = v24;
            v17 = v28;
            LOBYTE(v21[1].CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable) = 0;
          }
          else
          {
            v21 = nullptr;
          }
          v25 = v29;
          v21->m_flags = 8;
          *(CThreadEvent **)((char *)v17 + (_DWORD)v25) = (CThreadEvent *)v21;
          _g_pThreadPool->AddJob(this: _g_pThreadPool, a2: v21);
          ++v30;
          v16 = v32;
          *v17++ = &v21->m_CompleteEvent;
          v28 = v17;
        }
      }
      v32 = ++v16;
    }
    while ( v16 < this->m_Viewers.m_Size );
    v11 = v31;
  }
  _g_pThreadPool->YieldWait_2(this: _g_pThreadPool, a2: v11, a3: v30, a4: true, a5: -1u);
  for ( j = 0; j < this->m_Viewers.m_Size; ++j )
  {
    if ( this->m_Viewers.m_Memory.m_pMemory[j] != nullptr )
      CFoW::MergeViewerVisibility(this, nID: j);
  }
  CFoW::UpdateVisibleAmounts(this, flFrameTime);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x101FA030
// Name: private: struct CUtlSphereTree::NodeRef CUtlSphereTree::NewNode(void const __near *,class Vector4D const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlSphereTree::NodeRef *__thiscall CUtlSphereTree::NewNode(
        CUtlSphereTree *this,
        CUtlSphereTree::NodeRef *result,
        const void *pData,
        const Vector4D *bounds)
{
  int m_FreelistHead; // eax
  CUtlSphereTree::NodeRef *v6; // eax
  int nodeIndex; // edx
  float w; // xmm0_4
  int v9; // ecx
  CUtlSphereTree::Node *v10; // edx
  CUtlSphereTree::Node *v11; // edx
  CUtlSphereTree::Node *v12; // edx
  CUtlSphereTree::Node *v13; // edx
  float x; // [esp+8h] [ebp-10h]
  float y; // [esp+Ch] [ebp-Ch]
  float z; // [esp+10h] [ebp-8h]
  CUtlSphereTree::NodeRef v18; // 0:^10.8

  m_FreelistHead = this->m_FreelistHead;
  if ( m_FreelistHead < 0 )
  {
    v18.nodeIndex = CUtlVector<CUtlSphereTree::Node,CUtlMemory<CUtlSphereTree::Node,int>>::AddToTail(this: &this->m_Nodes);
    v18.pNodes = &this->m_Nodes;
  }
  else
  {
    v18.nodeIndex = this->m_FreelistHead;
    v18.pNodes = &this->m_Nodes;
    this->m_FreelistHead = LODWORD(this->m_Nodes.m_Memory.m_pMemory[m_FreelistHead].bounds.x);
  }
  v6 = result;
  ++this->m_NumNodesInTree;
  nodeIndex = v18.nodeIndex;
  *result = v18;
  if ( bounds != nullptr )
  {
    x = bounds->x;
    y = bounds->y;
    z = bounds->z;
    w = bounds->w;
  }
  else
  {
    w = 0.0;
    x = 0.0;
    y = 0.0;
    z = 0.0;
  }
  v9 = nodeIndex;
  if ( nodeIndex < 0 )
    v10 = nullptr;
  else
    v10 = &result->pNodes->m_Memory.m_pMemory[nodeIndex];
  v10->bounds.x = x;
  v10->bounds.y = y;
  v10->bounds.z = z;
  v10->bounds.w = w;
  if ( v9 < 0 )
    v11 = nullptr;
  else
    v11 = &result->pNodes->m_Memory.m_pMemory[v9];
  v11->deepIndex = -1;
  if ( v9 < 0 )
    v12 = nullptr;
  else
    v12 = &result->pNodes->m_Memory.m_pMemory[v9];
  v12->shallowIndex = -1;
  if ( v9 < 0 )
    v13 = nullptr;
  else
    v13 = &result->pNodes->m_Memory.m_pMemory[v9];
  v13->pData = pData;
  if ( v9 < 0 )
    MEMORY[0x1C] = 0;
  else
    result->pNodes->m_Memory.m_pMemory[v9].maxDepth = 0;
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x101FA160
// Name: private: struct CUtlSphereTree::NodeRef CUtlSphereTree::CopyNode(struct CUtlSphereTree::NodeRef const __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlSphereTree::NodeRef *__thiscall CUtlSphereTree::CopyNode(
        CUtlSphereTree *this,
        CUtlSphereTree::NodeRef *result,
        const CUtlSphereTree::NodeRef *nodeToCopy)
{
  CUtlSphereTree::Node *v3; // ecx
  CUtlSphereTree::Node *v4; // eax

  CUtlSphereTree::NewNode(this, result, pData: nullptr, bounds: nullptr);
  if ( nodeToCopy->nodeIndex < 0 )
    v3 = nullptr;
  else
    v3 = &nodeToCopy->pNodes->m_Memory.m_pMemory[nodeToCopy->nodeIndex];
  if ( result->nodeIndex < 0 )
    v4 = nullptr;
  else
    v4 = &result->pNodes->m_Memory.m_pMemory[result->nodeIndex];
  v4->bounds.x = v3->bounds.x;
  v4->bounds.y = v3->bounds.y;
  v4->bounds.z = v3->bounds.z;
  v4->bounds.w = v3->bounds.w;
  v4->deepIndex = v3->deepIndex;
  v4->shallowIndex = v3->shallowIndex;
  v4->pData = v3->pData;
  v4->maxDepth = v3->maxDepth;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101FA1D0
// Name: private: void CUtlSphereTree::FindPathToClosestLeaf_R(struct CUtlSphereTree::NodeRef,class Vector const __near &,float,float __near &,class CUtlVector<int,class CUtlMemory<int,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlSphereTree::FindPathToClosestLeaf_R(
        CUtlSphereTree *this,
        CUtlSphereTree::NodeRef node,
        const Vector *pos,
        float nodeDist,
        float *minDist,
        CUtlMemory<vgui::TreeNode *,int> *path)
{
  int nodeIndex; // eax
  float v7; // xmm6_4
  CUtlVector<CUtlSphereTree::Node,CUtlMemory<CUtlSphereTree::Node,int> > *pNodes; // ecx
  CUtlSphereTree::Node *v9; // edx
  CUtlMemory<vgui::TreeNode *,int> *v10; // esi
  CUtlSphereTree::Node *v11; // edx
  int deepIndex; // edx
  CUtlSphereTree::Node *v13; // edx
  float y; // xmm4_4
  float z; // xmm5_4
  float x; // xmm3_4
  CUtlSphereTree::Node *v17; // edx
  int shallowIndex; // edx
  CUtlSphereTree::Node *v19; // edx
  float v20; // xmm0_4
  CUtlSphereTree::Node *v21; // edx
  int v22; // edx
  CUtlSphereTree::Node *v23; // edx
  CUtlSphereTree::Node *v24; // eax
  int v25; // edx
  int v26; // edx
  int v27; // edx
  int v28; // eax
  vgui::TreeNode **m_pMemory; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v31; // ecx
  int v32; // eax
  vgui::TreeNode **v33; // edi
  CUtlSphereTree::NodeRef v34; // [esp-Ch] [ebp-64h]
  CUtlSphereTree::NodeRef v35; // [esp-Ch] [ebp-64h]
  float v36; // [esp+2Ch] [ebp-2Ch]
  float v37; // [esp+44h] [ebp-14h]
  int v38; // [esp+44h] [ebp-14h]

  nodeIndex = node.nodeIndex;
  v7 = *minDist;
  pNodes = node.pNodes;
  v37 = *minDist;
  if ( node.nodeIndex < 0 )
    v9 = nullptr;
  else
    v9 = &node.pNodes->m_Memory.m_pMemory[node.nodeIndex];
  if ( v9->deepIndex >= 0 )
  {
    if ( node.nodeIndex < 0 )
      v11 = nullptr;
    else
      v11 = &node.pNodes->m_Memory.m_pMemory[node.nodeIndex];
    deepIndex = v11->deepIndex;
    if ( deepIndex < 0 )
      v13 = nullptr;
    else
      v13 = &node.pNodes->m_Memory.m_pMemory[deepIndex];
    y = pos->y;
    z = pos->z;
    x = pos->x;
    v36 = fsqrt(
            (float)((float)((float)(v13->bounds.z - z) * (float)(v13->bounds.z - z))
                  + (float)((float)(v13->bounds.y - y) * (float)(v13->bounds.y - y)))
          + (float)((float)(v13->bounds.x - x) * (float)(v13->bounds.x - x)));
    if ( node.nodeIndex < 0 )
      v17 = nullptr;
    else
      v17 = &node.pNodes->m_Memory.m_pMemory[node.nodeIndex];
    shallowIndex = v17->shallowIndex;
    if ( shallowIndex < 0 )
      v19 = nullptr;
    else
      v19 = &node.pNodes->m_Memory.m_pMemory[shallowIndex];
    v20 = fsqrt(
            (float)((float)((float)(v19->bounds.y - y) * (float)(v19->bounds.y - y))
                  + (float)((float)(v19->bounds.z - z) * (float)(v19->bounds.z - z)))
          + (float)((float)(v19->bounds.x - x) * (float)(v19->bounds.x - x)));
    if ( node.nodeIndex < 0 )
      v21 = nullptr;
    else
      v21 = &node.pNodes->m_Memory.m_pMemory[node.nodeIndex];
    v22 = v21->deepIndex;
    if ( v22 < 0 )
      v23 = nullptr;
    else
      v23 = &node.pNodes->m_Memory.m_pMemory[v22];
    v10 = path;
    if ( v7 > (float)(v36 - v23->bounds.w) )
    {
      if ( node.nodeIndex < 0 )
        v24 = nullptr;
      else
        v24 = &node.pNodes->m_Memory.m_pMemory[node.nodeIndex];
      v34.pNodes = node.pNodes;
      v34.nodeIndex = v24->deepIndex;
      CUtlSphereTree::FindPathToClosestLeaf_R(
        this,
        node: v34,
        pos,
        nodeDist: v36,
        minDist,
        (CUtlVector<int,CUtlMemory<int,int> > *)path);
      pNodes = node.pNodes;
      nodeIndex = node.nodeIndex;
    }
    if ( nodeIndex < 0 )
      v25 = 0;
    else
      v25 = (int)&pNodes->m_Memory.m_pMemory[nodeIndex];
    v26 = *(_DWORD *)(v25 + 20);
    if ( v26 < 0 )
      v27 = 0;
    else
      v27 = (int)&pNodes->m_Memory.m_pMemory[v26];
    if ( *minDist > (float)(v20 - *(float *)(v27 + 12)) )
    {
      if ( nodeIndex < 0 )
        v28 = 0;
      else
        v28 = (int)&pNodes->m_Memory.m_pMemory[nodeIndex];
      v35.pNodes = pNodes;
      v35.nodeIndex = *(_DWORD *)(v28 + 20);
      CUtlSphereTree::FindPathToClosestLeaf_R(
        this,
        node: v35,
        pos,
        nodeDist: v20,
        minDist,
        (CUtlVector<int,CUtlMemory<int,int> > *)path);
      nodeIndex = node.nodeIndex;
    }
  }
  else
  {
    if ( nodeDist >= v7 )
      return;
    v10 = path;
    path[1].m_pMemory = nullptr;
    *minDist = nodeDist;
  }
  if ( v37 > *minDist )
  {
    m_pMemory = v10[1].m_pMemory;
    v38 = nodeIndex;
    m_nAllocationCount = v10->m_nAllocationCount;
    if ( (int)m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v10, num: (int)m_pMemory - m_nAllocationCount + 1);
    ++v10[1].m_pMemory;
    v31 = v10->m_pMemory;
    v32 = (char *)v10[1].m_pMemory - (char *)m_pMemory - 1;
    v10[1].m_nAllocationCount = (int)v10->m_pMemory;
    if ( v32 > 0 )
      _V_memmove(dest: &v31[(_DWORD)m_pMemory + 1], src: &v31[(_DWORD)m_pMemory], count: 4 * v32);
    v33 = &v10->m_pMemory[(_DWORD)m_pMemory];
    if ( v33 != nullptr )
      *v33 = (vgui::TreeNode *)v38;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FA430
// Name: public: void CUtlSphereTree::Remove(void const __near *,class Vector4D const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlSphereTree::Remove(CUtlSphereTree *this, const void *pData, const Vector4D *bounds)
{
  int m_NumNodesInTree; // eax
  CUtlSphereTree::NodeRef root; // [esp+4h] [ebp-8h] BYREF

  m_NumNodesInTree = this->m_NumNodesInTree;
  if ( m_NumNodesInTree != 0 )
  {
    root.nodeIndex = 0;
    root.pNodes = &this->m_Nodes;
    if ( m_NumNodesInTree == 1 )
    {
      if ( CUtlSphereTree::NodeHasData(this, node: &root, pData, bounds) )
        CUtlSphereTree::FreelistPush(this, node: &root);
    }
    else
    {
      CUtlSphereTree::Remove_R(this, node: &root, pData, bounds);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FA4A0
// Name: private: void CUtlSphereTree::IntersectWithSphere_R(struct CUtlSphereTree::NodeRef const __near &,class Vector4D const __near &,bool,class CUtlVector<void __near *,class CUtlMemory<void __near *,int>> __near &,int __near &,float)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlSphereTree::IntersectWithSphere_R(
        CUtlSphereTree *this,
        const CUtlSphereTree::NodeRef *node,
        const Vector4D *sphere,
        bool bPartial,
        CUtlVector<void *,CUtlMemory<void *,int> > *result,
        int *count,
        float distSq)
{
  int nodeIndex; // eax
  CUtlSphereTree::Node *v8; // ecx
  CUtlSphereTree::Node *v9; // ecx
  float w; // xmm0_4
  float v11; // xmm1_4
  CUtlSphereTree::Node *v12; // eax
  int m_Size; // edi
  void *pData; // ebx
  int m_nAllocationCount; // eax
  void **m_pMemory; // ecx
  int v17; // eax
  void **v18; // eax
  CUtlSphereTree::Node *v19; // ecx
  int deepIndex; // ecx
  CUtlVector<CUtlSphereTree::Node,CUtlMemory<CUtlSphereTree::Node,int> > *pNodes; // edx
  float *p_x; // ecx
  float v23; // xmm0_4
  int v24; // eax
  int v25; // eax
  int v26; // ecx
  CUtlSphereTree::Node *v27; // eax
  int shallowIndex; // eax
  CUtlVector<CUtlSphereTree::Node,CUtlMemory<CUtlSphereTree::Node,int> > *v29; // edx
  float *v30; // eax
  float v31; // xmm0_4
  int v32; // ecx
  int v33; // eax
  CUtlSphereTree::NodeRef v34; // [esp+10h] [ebp-Ch] BYREF
  CUtlSphereTree *v35; // [esp+18h] [ebp-4h]

  nodeIndex = node->nodeIndex;
  v35 = this;
  if ( nodeIndex < 0 )
    v8 = nullptr;
  else
    v8 = &node->pNodes->m_Memory.m_pMemory[nodeIndex];
  if ( v8->deepIndex >= 0 )
  {
    if ( nodeIndex < 0 )
      v19 = nullptr;
    else
      v19 = &node->pNodes->m_Memory.m_pMemory[nodeIndex];
    deepIndex = v19->deepIndex;
    pNodes = node->pNodes;
    if ( deepIndex < 0 )
      p_x = nullptr;
    else
      p_x = &pNodes->m_Memory.m_pMemory[deepIndex].bounds.x;
    v23 = (float)((float)((float)(sphere->x - *p_x) * (float)(sphere->x - *p_x))
                + (float)((float)(sphere->y - p_x[1]) * (float)(sphere->y - p_x[1])))
        + (float)((float)(sphere->z - p_x[2]) * (float)(sphere->z - p_x[2]));
    if ( (float)((float)(p_x[3] + sphere->w) * (float)(p_x[3] + sphere->w)) >= v23 )
    {
      if ( nodeIndex < 0 )
        v24 = 0;
      else
        v24 = (int)&pNodes->m_Memory.m_pMemory[nodeIndex];
      v25 = *(_DWORD *)(v24 + 16);
      v34.pNodes = node->pNodes;
      v34.nodeIndex = v25;
      CUtlSphereTree::IntersectWithSphere_R(this: v35, node: &v34, sphere, bPartial, result, count, distSq: v23);
    }
    v26 = node->nodeIndex;
    if ( node->nodeIndex < 0 )
      v27 = nullptr;
    else
      v27 = &node->pNodes->m_Memory.m_pMemory[v26];
    shallowIndex = v27->shallowIndex;
    v29 = node->pNodes;
    if ( shallowIndex < 0 )
      v30 = nullptr;
    else
      v30 = &v29->m_Memory.m_pMemory[shallowIndex].bounds.x;
    v31 = (float)((float)((float)(sphere->x - *v30) * (float)(sphere->x - *v30))
                + (float)((float)(sphere->y - v30[1]) * (float)(sphere->y - v30[1])))
        + (float)((float)(sphere->z - v30[2]) * (float)(sphere->z - v30[2]));
    if ( (float)((float)(v30[3] + sphere->w) * (float)(v30[3] + sphere->w)) >= v31 )
    {
      if ( v26 < 0 )
        v32 = 0;
      else
        v32 = (int)&v29->m_Memory.m_pMemory[v26];
      v33 = *(_DWORD *)(v32 + 20);
      v34.pNodes = node->pNodes;
      v34.nodeIndex = v33;
      CUtlSphereTree::IntersectWithSphere_R(this: v35, node: &v34, sphere, bPartial, result, count, distSq: v31);
    }
  }
  else if ( bPartial
         || (nodeIndex < 0 ? (v9 = nullptr) : (v9 = &node->pNodes->m_Memory.m_pMemory[nodeIndex]),
             (w = sphere->w, (v11 = v9->bounds.w) <= w) && distSq <= (float)((float)(w - v11) * (float)(w - v11))) )
  {
    if ( *count > 0 )
    {
      if ( nodeIndex < 0 )
        v12 = nullptr;
      else
        v12 = &node->pNodes->m_Memory.m_pMemory[nodeIndex];
      m_Size = result->m_Size;
      pData = (void *)v12->pData;
      m_nAllocationCount = result->m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CVisGroup *,int>::Grow(
          this: (CUtlMemory<CCullTreeNode *,int> *)result,
          num: m_Size - m_nAllocationCount + 1);
      ++result->m_Size;
      m_pMemory = result->m_Memory.m_pMemory;
      v17 = result->m_Size - m_Size - 1;
      result->m_pElements = result->m_Memory.m_pMemory;
      if ( v17 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v17);
      v18 = &result->m_Memory.m_pMemory[m_Size];
      if ( v18 != nullptr )
        *v18 = pData;
    }
    --*count;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FA6D0
// Name: public: CUtlSphereTree::Cut::Cut(class CUtlSphereTree const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlSphereTree::Cut *__thiscall CUtlSphereTree::Cut::Cut(CUtlSphereTree::Cut *this, const CUtlSphereTree *pTree)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  int *m_pMemory; // ecx
  int v6; // eax
  int *v7; // eax

  this->m_NodeRefs.m_Memory.m_pMemory = nullptr;
  this->m_NodeRefs.m_Memory.m_nAllocationCount = 0;
  this->m_NodeRefs.m_Memory.m_nGrowSize = 0;
  this->m_NodeRefs.m_Size = 0;
  this->m_NodeRefs.m_pElements = nullptr;
  this->m_pTree = pTree;
  if ( pTree->m_NumNodesInTree != 0 )
  {
    m_nAllocationCount = this->m_NodeRefs.m_Memory.m_nAllocationCount;
    m_Size = this->m_NodeRefs.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_NodeRefs,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_NodeRefs.m_Size;
    m_pMemory = this->m_NodeRefs.m_Memory.m_pMemory;
    v6 = this->m_NodeRefs.m_Size - m_Size - 1;
    this->m_NodeRefs.m_pElements = m_pMemory;
    if ( v6 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
    v7 = &this->m_NodeRefs.m_Memory.m_pMemory[m_Size];
    if ( v7 != nullptr )
      *v7 = 0;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101FA750
// Name: public: int CFoW::AddTriSoup(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CFoW::AddTriSoup(CFoW *this)
{
  int m_Size; // edx
  signed int v2; // eax
  CFoW_TriSoupCollection **m_pMemory; // edi
  CUtlMemory<vgui::TreeNode *,int> *p_m_TriSoupCollection; // esi
  unsigned int v5; // ebx
  int v6; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  vgui::TreeNode **v10; // eax
  CFoW_TriSoupCollection *v11; // eax

  m_Size = this->m_TriSoupCollection.m_Size;
  v2 = 0;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = this->m_TriSoupCollection.m_Memory.m_pMemory;
  p_m_TriSoupCollection = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_TriSoupCollection;
  while ( *m_pMemory != nullptr )
  {
    ++v2;
    ++m_pMemory;
    if ( v2 >= m_Size )
      goto LABEL_7;
  }
  v5 = v2;
  if ( v2 == -1 )
  {
LABEL_7:
    v6 = this->m_TriSoupCollection.m_Size;
    m_nAllocationCount = this->m_TriSoupCollection.m_Memory.m_nAllocationCount;
    p_m_TriSoupCollection = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_TriSoupCollection;
    v5 = v6;
    if ( v6 + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_TriSoupCollection, num: v6 - m_nAllocationCount + 1);
    ++p_m_TriSoupCollection[1].m_pMemory;
    v8 = p_m_TriSoupCollection->m_pMemory;
    v9 = (int)p_m_TriSoupCollection[1].m_pMemory - v6 - 1;
    p_m_TriSoupCollection[1].m_nAllocationCount = (int)p_m_TriSoupCollection->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[v6 + 1], src: &v8[v6], count: 4 * v9);
    v10 = &p_m_TriSoupCollection->m_pMemory[v6];
    if ( v10 != nullptr )
      *v10 = nullptr;
  }
  v11 = (CFoW_TriSoupCollection *)operator new(nSize: 0x14u);
  if ( v11 != nullptr )
    p_m_TriSoupCollection->m_pMemory[v5] = (vgui::TreeNode *)CFoW_TriSoupCollection::CFoW_TriSoupCollection(
                                                               this: v11,
                                                               nID: v5);
  else
    p_m_TriSoupCollection->m_pMemory[v5] = nullptr;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x101FA850
// Name: public: void CUtlSphereTree::Insert(void const __near *,class Vector4D const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CUtlSphereTree::Insert(
        CUtlSphereTree *this@<ecx>,
        int a2@<ebp>,
        const void *pData,
        const Vector *bounds)
{
  int m_PrevInsertedNode; // eax
  CUtlSphereTree::Node *v6; // eax
  float v7; // xmm1_4
  __int128 v8; // xmm0
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  CUtlSphereTree::Node *m_pMemory; // eax
  __int128 v13; // xmm0
  vgui::TreeNode *v14; // edx
  CUtlVector<CUtlSphereTree::Node,CUtlMemory<CUtlSphereTree::Node,int> > *p_m_Nodes; // edi
  int *v16; // eax
  int v17; // ecx
  int v18; // eax
  vgui::TreeNode **v19; // eax
  CUtlSphereTree::NodeRef v20; // [esp-Ch] [ebp-74h]
  CUtlMemory<vgui::TreeNode *,int> v21; // [esp+18h] [ebp-50h] BYREF
  int nodeDist; // [esp+24h] [ebp-44h]
  vgui::TreeNode **v23; // [esp+28h] [ebp-40h]
  CUtlSphereTree::NodeRef v24[2]; // [esp+2Ch] [ebp-3Ch] BYREF
  CUtlSphereTree::NodeRef v25; // [esp+40h] [ebp-28h] BYREF
  CUtlVector<int,CUtlMemory<int,int> > path; // [esp+48h] [ebp-20h] BYREF
  int v27; // [esp+5Ch] [ebp-Ch]
  int v28; // [esp+60h] [ebp-8h]
  int root_4; // [esp+68h] [ebp+0h]

  v27 = a2;
  v28 = root_4;
  if ( this->m_NumNodesInTree != 0 )
  {
    m_PrevInsertedNode = this->m_PrevInsertedNode;
    path.m_pElements = (int *)2139095039;
    if ( m_PrevInsertedNode >= 0 )
    {
      v6 = &this->m_Nodes.m_Memory.m_pMemory[m_PrevInsertedNode];
      if ( v6->deepIndex < 0 )
      {
        v7 = v6->bounds.y - bounds->y;
        v8 = 0;
        *(float *)&v8 = fsqrt(
                          (float)((float)((float)(v6->bounds.z - bounds->z) * (float)(v6->bounds.z - bounds->z))
                                + (float)(v7 * v7))
                        + (float)((float)(v6->bounds.x - bounds->x) * (float)(v6->bounds.x - bounds->x)));
        *(_OWORD *)&v24[0].nodeIndex = v8;
        v9 = *(float *)&v8;
        v10 = *(float *)&v8 * 1.1;
        v11 = v9 + 0.001;
        if ( v10 <= v11 )
          *(float *)&path.m_pElements = v11;
        else
          *(float *)&path.m_pElements = v10;
      }
    }
    m_pMemory = this->m_Nodes.m_Memory.m_pMemory;
    memset(&v21, 0, sizeof(v21));
    nodeDist = 0;
    v23 = nullptr;
    v13 = 0;
    *(float *)&v13 = fsqrt(
                       (float)((float)((float)(m_pMemory->bounds.y - bounds->y)
                                     * (float)(m_pMemory->bounds.y - bounds->y))
                             + (float)((float)(m_pMemory->bounds.z - bounds->z)
                                     * (float)(m_pMemory->bounds.z - bounds->z)))
                     + (float)((float)(m_pMemory->bounds.x - bounds->x) * (float)(m_pMemory->bounds.x - bounds->x)));
    *(_OWORD *)&v24[0].nodeIndex = v13;
    v20.pNodes = &this->m_Nodes;
    v20.nodeIndex = 0;
    CUtlSphereTree::FindPathToClosestLeaf_R(
      this,
      node: v20,
      pos: bounds,
      nodeDist: *(float *)&v13,
      minDist: (float *)&path.m_pElements,
      path: &v21);
    v14 = *v21.m_pMemory;
    path.m_Size = (int)&this->m_Nodes;
    path.m_Memory.m_nGrowSize = (int)v14;
    CUtlSphereTree::CopyNode(
      this,
      result: &v24[1],
      nodeToCopy: (const CUtlSphereTree::NodeRef *)&path.m_Memory.m_nGrowSize);
    CUtlSphereTree::NewNode(this, result: (CUtlSphereTree::NodeRef *)&path, pData, (const Vector4D *)bounds);
    CUtlSphereTree::SetNodeChildren(
      this,
      node: (CUtlSphereTree::NodeRef *)&path.m_Memory.m_nGrowSize,
      childA: (const CUtlSphereTree::NodeRef *)&path,
      childB: &v24[1]);
    CUtlSphereTree::RebalanceSubtrees(
      this,
      node: (CUtlSphereTree::NodeRef *)&path.m_Memory.m_nGrowSize,
      bInserting: true);
    this->m_PrevInsertedNode = (int)path.m_Memory.m_pMemory;
    path.m_Size = 1;
    if ( nodeDist > 1 )
    {
      p_m_Nodes = &this->m_Nodes;
      path.m_Memory.m_nAllocationCount = (int)&this->m_Nodes;
      do
      {
        v16 = (int *)v21.m_pMemory[path.m_Size];
        path.m_Memory.m_pMemory = v16;
        if ( (int)v16 < 0 )
          v17 = 0;
        else
          v17 = (int)&p_m_Nodes->m_Memory.m_pMemory[(_DWORD)v16];
        v25.nodeIndex = *(_DWORD *)(v17 + 20);
        v25.pNodes = &this->m_Nodes;
        if ( (int)v16 < 0 )
          v18 = 0;
        else
          v18 = (int)&p_m_Nodes->m_Memory.m_pMemory[(_DWORD)v16];
        v24[1].nodeIndex = *(_DWORD *)(v18 + 16);
        v24[1].pNodes = &this->m_Nodes;
        CUtlSphereTree::SetNodeChildren(this, node: (CUtlSphereTree::NodeRef *)&path, childA: &v24[1], childB: &v25);
        CUtlSphereTree::RebalanceSubtrees(this, node: (CUtlSphereTree::NodeRef *)&path, bInserting: true);
        ++path.m_Size;
      }
      while ( path.m_Size < nodeDist );
    }
    v19 = v21.m_pMemory;
    nodeDist = 0;
    if ( v21.m_nGrowSize >= 0 )
    {
      if ( v21.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v21.m_pMemory);
        v19 = nullptr;
        v21.m_pMemory = nullptr;
      }
      v21.m_nAllocationCount = 0;
    }
    v23 = v19;
    if ( v21.m_nGrowSize >= 0 && v19 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v19);
  }
  else
  {
    CUtlSphereTree::NewNode(this, result: &v24[1], pData, (const Vector4D *)bounds);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FAAB0
// Name: public: int CUtlSphereTree::IntersectWithSphere(class Vector4D const __near &,bool,class CUtlVector<void __near *,class CUtlMemory<void __near *,int>> __near &,int,class CUtlSphereTree::Cut __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSphereTree::IntersectWithSphere(
        CUtlSphereTree *this,
        const Vector4D *sphere,
        bool bPartial,
        CUtlVector<void *,CUtlMemory<void *,int> > *result,
        int maxResults,
        CUtlVector<void *,CUtlMemory<void *,int> > *cut)
{
  int v6; // edi
  CUtlSphereTree::Cut *v8; // edx
  int v10; // eax
  int v11; // ecx
  CUtlSphereTree::Node *v12; // eax
  float v13; // xmm0_4
  int v14; // esi
  CUtlSphereTree::Cut v15; // [esp+10h] [ebp-24h] BYREF
  CUtlSphereTree::NodeRef v16; // [esp+28h] [ebp-Ch] BYREF
  CUtlSphereTree::NodeRef node; // [esp+30h] [ebp-4h] BYREF

  v6 = 0;
  result->m_Size = 0;
  if ( this->m_NumNodesInTree == 0 )
    return 0;
  CUtlSphereTree::Cut::Cut(this: &v15, pTree: this);
  v8 = (CUtlSphereTree::Cut *)cut;
  if ( cut == nullptr )
  {
    cut = (CUtlVector<void *,CUtlMemory<void *,int> > *)&v15;
    v8 = &v15;
  }
  if ( v8->m_pTree != this )
  {
    CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int>>::~CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int>>(this: (CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int> > *)&v15.m_NodeRefs);
    return 0;
  }
  v10 = maxResults;
  if ( maxResults == 0 )
  {
    maxResults = 0x7FFFFFFF;
    v10 = 0x7FFFFFFF;
  }
  node.nodeIndex = v10;
  if ( v8->m_NodeRefs.m_Size > 0 )
  {
    do
    {
      v11 = v8->m_NodeRefs.m_Memory.m_pMemory[v6];
      if ( v11 < 0 )
      {
        v12 = nullptr;
      }
      else
      {
        v8 = (CUtlSphereTree::Cut *)cut;
        v12 = &this->m_Nodes.m_Memory.m_pMemory[v11];
      }
      v13 = (float)((float)((float)(sphere->x - v12->bounds.x) * (float)(sphere->x - v12->bounds.x))
                  + (float)((float)(sphere->y - v12->bounds.y) * (float)(sphere->y - v12->bounds.y)))
          + (float)((float)(sphere->z - v12->bounds.z) * (float)(sphere->z - v12->bounds.z));
      if ( (float)((float)(v12->bounds.w + sphere->w) * (float)(v12->bounds.w + sphere->w)) >= v13 )
      {
        v16.nodeIndex = v11;
        v16.pNodes = &this->m_Nodes;
        CUtlSphereTree::IntersectWithSphere_R(
          this,
          node: &v16,
          sphere,
          bPartial,
          result,
          count: &node.nodeIndex,
          distSq: v13);
        v8 = (CUtlSphereTree::Cut *)cut;
      }
      ++v6;
    }
    while ( v6 < v8->m_NodeRefs.m_Size );
    v10 = maxResults;
  }
  v14 = v10 - node.nodeIndex;
  CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int>>::~CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int>>(this: (CUtlVector<defaultConfigInfo_t,CUtlMemory<defaultConfigInfo_t,int> > *)&v15.m_NodeRefs);
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x101FABD0
// Name: public: void CFoW::RemoveViewer(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoW::RemoveViewer(CFoW *this, int nID)
{
  CFoW_Viewer **m_pMemory; // eax
  bool v4; // zf
  CFoW_Viewer **v5; // eax
  float *v6; // eax
  CFoW_Viewer **v7; // ecx
  float v8; // xmm0_4
  const void **v9; // eax
  CFoW_Viewer **v10; // eax
  CFoW_Viewer *v11; // ebx
  Vector4D bounds; // [esp+8h] [ebp-10h] BYREF

  m_pMemory = this->m_Viewers.m_Memory.m_pMemory;
  v4 = m_pMemory[nID] == nullptr;
  v5 = &m_pMemory[nID];
  if ( !v4 )
  {
    v6 = (float *)*v5;
    v7 = this->m_Viewers.m_Memory.m_pMemory;
    bounds.x = v6[3];
    bounds.y = v6[4];
    v8 = v6[5];
    v9 = (const void **)&v7[nID];
    bounds.z = v8;
    bounds.w = *((float *)*v9 + 2);
    CUtlSphereTree::Remove(this: &this->m_ViewerTree, pData: *v9, &bounds);
    v10 = this->m_Viewers.m_Memory.m_pMemory;
    v11 = v10[nID];
    if ( v11 != nullptr )
    {
      CFoW_Viewer::~CFoW_Viewer(this: v10[nID]);
      operator delete(p: v11);
    }
    this->m_Viewers.m_Memory.m_pMemory[nID] = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FAC60
// Name: public: void CFoW::ObstructOccludersNearViewer(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoW::ObstructOccludersNearViewer(CFoW *this, int nViewerID)
{
  CFoW_Viewer *v3; // esi
  float m_flRadius; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  float x; // xmm3_4
  int v8; // edi
  void **m_pMemory; // eax
  CFoW_RadiusOccluder *FixedPointerArray[400]; // [esp+Ch] [ebp-664h] BYREF
  Vector4D TestSphere; // [esp+64Ch] [ebp-24h] BYREF
  CUtlVector<void *,CUtlMemory<void *,int> > FoundOccluders; // [esp+65Ch] [ebp-14h] BYREF

  v3 = this->m_Viewers.m_Memory.m_pMemory[nViewerID];
  m_flRadius = v3->m_flRadius;
  y = v3->m_vLocation.y;
  z = v3->m_vLocation.z;
  x = v3->m_vLocation.x;
  v8 = 0;
  FoundOccluders.m_Memory.m_pMemory = (void **)FixedPointerArray;
  TestSphere.x = x;
  TestSphere.y = y;
  TestSphere.z = z;
  TestSphere.w = m_flRadius;
  FoundOccluders.m_Memory.m_nAllocationCount = 400;
  FoundOccluders.m_Memory.m_nGrowSize = -1;
  FoundOccluders.m_Size = 0;
  FoundOccluders.m_pElements = (void **)FixedPointerArray;
  CUtlSphereTree::IntersectWithSphere(
    this: &this->m_OccluderTree,
    sphere: &TestSphere,
    bPartial: true,
    result: &FoundOccluders,
    maxResults: 400,
    cut: nullptr);
  if ( FoundOccluders.m_Size > 0 )
  {
    do
      CFoW_RadiusOccluder::ObstructViewerRadius(this: FixedPointerArray[v8++], pFoW: this, pViewer: v3);
    while ( v8 < FoundOccluders.m_Size );
  }
  m_pMemory = FoundOccluders.m_Memory.m_pMemory;
  FoundOccluders.m_Size = 0;
  if ( FoundOccluders.m_Memory.m_nGrowSize >= 0 )
  {
    if ( FoundOccluders.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: FoundOccluders.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      FoundOccluders.m_Memory.m_pMemory = nullptr;
    }
    FoundOccluders.m_Memory.m_nAllocationCount = 0;
  }
  FoundOccluders.m_pElements = m_pMemory;
  if ( FoundOccluders.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x101FAD50
// Name: private: void CFoW::DirtyViewers(class Vector __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoW::DirtyViewers(CFoW *this, Vector *vLocation, float flRadius)
{
  float z; // xmm0_4
  int i; // eax
  CFoW_Viewer *v5; // ecx
  void **m_pMemory; // eax
  CFoW_Viewer *FixedPointerArray[100]; // [esp+0h] [ebp-1B4h] BYREF
  Vector4D TestSphere; // [esp+190h] [ebp-24h] BYREF
  CUtlVector<void *,CUtlMemory<void *,int> > FoundViewers; // [esp+1A0h] [ebp-14h] BYREF

  TestSphere.x = vLocation->x;
  TestSphere.y = vLocation->y;
  z = vLocation->z;
  FoundViewers.m_Memory.m_pMemory = (void **)FixedPointerArray;
  FoundViewers.m_pElements = (void **)FixedPointerArray;
  TestSphere.z = z;
  TestSphere.w = flRadius;
  FoundViewers.m_Memory.m_nAllocationCount = 100;
  FoundViewers.m_Memory.m_nGrowSize = -1;
  FoundViewers.m_Size = 0;
  CUtlSphereTree::IntersectWithSphere(
    this: &this->m_ViewerTree,
    sphere: &TestSphere,
    bPartial: true,
    result: &FoundViewers,
    maxResults: 100,
    cut: nullptr);
  for ( i = 0; i < FoundViewers.m_Size; v5->m_bDirty = true )
    v5 = FixedPointerArray[i++];
  m_pMemory = FoundViewers.m_Memory.m_pMemory;
  FoundViewers.m_Size = 0;
  if ( FoundViewers.m_Memory.m_nGrowSize >= 0 )
  {
    if ( FoundViewers.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: FoundViewers.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      FoundViewers.m_Memory.m_pMemory = nullptr;
    }
    FoundViewers.m_Memory.m_nAllocationCount = 0;
  }
  FoundViewers.m_pElements = m_pMemory;
  if ( FoundViewers.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x101FAE60
// Name: public: void CFoW::ClearState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoW::ClearState(CFoW *this)
{
  void **m_pVisibilityGridFlags; // edi
  void *v3; // eax
  int v4; // eax
  CFoW_HorizontalSlice *v5; // edi
  CUtlSphereTree::Node *m_pMemory; // eax
  float *m_pVerticalLevels; // eax
  int j; // edi
  unsigned int v9; // edi
  int *v10; // eax
  unsigned int i; // [esp+Ch] [ebp-4h]
  unsigned int ia; // [esp+Ch] [ebp-4h]
  unsigned int ib; // [esp+Ch] [ebp-4h]

  m_pVisibilityGridFlags = (void **)this->m_pVisibilityGridFlags;
  for ( i = 2; i != 0; --i )
  {
    if ( *m_pVisibilityGridFlags != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *m_pVisibilityGridFlags);
      v3 = *(m_pVisibilityGridFlags - 4);
      *m_pVisibilityGridFlags = nullptr;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3);
      *(m_pVisibilityGridFlags - 4) = nullptr;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(m_pVisibilityGridFlags - 2));
      *(m_pVisibilityGridFlags - 2) = nullptr;
    }
    ++m_pVisibilityGridFlags;
  }
  if ( this->m_pHorizontalSlices != nullptr )
  {
    v4 = 0;
    for ( ia = 0; v4 < this->m_nGridZUnits; ia = v4 )
    {
      v5 = this->m_pHorizontalSlices[v4];
      if ( v5 != nullptr )
      {
        v5->m_SphereTree.__vftable = (CUtlSphereTree_vtbl *)&CUtlSphereTree::`vftable';
        v5->m_SphereTree.m_Nodes.m_Size = 0;
        if ( v5->m_SphereTree.m_Nodes.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v5->m_SphereTree.m_Nodes.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5->m_SphereTree.m_Nodes.m_Memory.m_pMemory);
            v5->m_SphereTree.m_Nodes.m_Memory.m_pMemory = nullptr;
          }
          v5->m_SphereTree.m_Nodes.m_Memory.m_nAllocationCount = 0;
        }
        m_pMemory = v5->m_SphereTree.m_Nodes.m_Memory.m_pMemory;
        v5->m_SphereTree.m_Nodes.m_pElements = m_pMemory;
        if ( v5->m_SphereTree.m_Nodes.m_Memory.m_nGrowSize >= 0 )
        {
          if ( m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
            v5->m_SphereTree.m_Nodes.m_Memory.m_pMemory = nullptr;
          }
          v5->m_SphereTree.m_Nodes.m_Memory.m_nAllocationCount = 0;
        }
        operator delete(p: v5);
        v4 = ia;
      }
      ++v4;
    }
    operator delete(p: this->m_pHorizontalSlices);
    this->m_pHorizontalSlices = nullptr;
  }
  m_pVerticalLevels = this->m_pVerticalLevels;
  this->m_nGridZUnits = 0;
  if ( m_pVerticalLevels != nullptr )
  {
    operator delete(p: m_pVerticalLevels);
    this->m_pVerticalLevels = nullptr;
  }
  for ( j = 0; j < this->m_Occluders.m_Size; ++j )
    operator delete(p: this->m_Occluders.m_Memory.m_pMemory[j]);
  this->m_Occluders.m_Size = 0;
  if ( this->m_Occluders.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Occluders.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Occluders.m_Memory.m_pMemory);
      this->m_Occluders.m_Memory.m_pMemory = nullptr;
    }
    this->m_Occluders.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Occluders.m_pElements = this->m_Occluders.m_Memory.m_pMemory;
  CUtlVector<CFoW_Viewer *,CUtlMemory<CFoW_Viewer *,int>>::PurgeAndDeleteElements(this: &this->m_Viewers);
  CUtlVector<CFoW_TriSoupCollection *,CUtlMemory<CFoW_TriSoupCollection *,int>>::PurgeAndDeleteElements(this: &this->m_TriSoupCollection);
  v9 = 0;
  for ( ib = 0; v9 < this->m_RadiusTables.m_Tree.m_NumElements; ib = ++v9 )
  {
    if ( (unsigned __int16)v9 < this->m_RadiusTables.m_Tree.m_Elements.m_nAllocationCount
      && (unsigned __int16)v9 <= this->m_RadiusTables.m_Tree.m_LastAlloc.index )
    {
      if ( (`CUtlRBTree<CUtlMap<float,int *,unsigned short>::Node_t,unsigned short,CUtlMap<float,int *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<float,int *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<float,int *,unsigned short>::Node_t,unsigned short,CUtlMap<float,int *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<float,int *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<float,int *,unsigned short>::Node_t,unsigned short,CUtlMap<float,int *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<float,int *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_107C76EC = 0x1FFFF;
      }
      if ( (_WORD)v9 == 0xFFFF )
        v10 = &`CUtlRBTree<CUtlMap<float,int *,unsigned short>::Node_t,unsigned short,CUtlMap<float,int *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<float,int *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v10 = (int *)&this->m_RadiusTables.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v9];
      if ( *(_WORD *)v10 != (_WORD)v9 )
      {
        _g_pMemAlloc->Free_2(
          this: _g_pMemAlloc,
          a2: this->m_RadiusTables.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v9].m_Data.elem);
        v9 = ib;
      }
    }
  }
  CUtlRBTree<CUtlMap<float,int *,unsigned short>::Node_t,unsigned short,CUtlMap<float,int *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<float,int *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_RadiusTables.m_Tree);
  this->m_ViewerTree.m_FreelistHead = -1;
  this->m_ViewerTree.m_NumNodesInTree = 0;
  this->m_ViewerTree.m_PrevInsertedNode = -1;
  this->m_ViewerTree.m_Nodes.m_Size = 0;
  if ( this->m_ViewerTree.m_Nodes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_ViewerTree.m_Nodes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ViewerTree.m_Nodes.m_Memory.m_pMemory);
      this->m_ViewerTree.m_Nodes.m_Memory.m_pMemory = nullptr;
    }
    this->m_ViewerTree.m_Nodes.m_Memory.m_nAllocationCount = 0;
  }
  this->m_ViewerTree.m_Nodes.m_pElements = this->m_ViewerTree.m_Nodes.m_Memory.m_pMemory;
  this->m_OccluderTree.m_FreelistHead = -1;
  this->m_OccluderTree.m_NumNodesInTree = 0;
  this->m_OccluderTree.m_PrevInsertedNode = -1;
  this->m_OccluderTree.m_Nodes.m_Size = 0;
  if ( this->m_OccluderTree.m_Nodes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_OccluderTree.m_Nodes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_OccluderTree.m_Nodes.m_Memory.m_pMemory);
      this->m_OccluderTree.m_Nodes.m_Memory.m_pMemory = nullptr;
    }
    this->m_OccluderTree.m_Nodes.m_Memory.m_nAllocationCount = 0;
  }
  this->m_OccluderTree.m_Nodes.m_pElements = this->m_OccluderTree.m_Nodes.m_Memory.m_pMemory;
  this->m_nVerticalGridAllocationSize = 0;
  this->m_nHorizontalGridAllocationSize = 0;
  this->m_nRadiusTableSize = 0;
  this->m_bInitialized = false;
}

//------------------------------------------------------------------------------
// Address: 0x101FB160
// Name: public: int CFoW::AddViewer(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFoW::AddViewer(CFoW *this, unsigned int nViewerTeam)
{
  int m_Size; // ecx
  int v4; // eax
  CFoW_Viewer **m_pMemory; // edx
  CUtlMemory<vgui::TreeNode *,int> *p_m_Viewers; // esi
  int v7; // ebx
  int m_nAllocationCount; // eax
  int v9; // edi
  vgui::TreeNode **v10; // ecx
  int v11; // eax
  vgui::TreeNode **v12; // edi
  CFoW_Viewer *v13; // eax
  CFoW_Viewer *v14; // eax
  vgui::TreeNode **v15; // edx
  float *v16; // eax
  const void **v17; // ecx
  Vector4D bounds; // [esp+Ch] [ebp-14h] BYREF
  CFoW *v20; // [esp+1Ch] [ebp-4h]
  int savedregs; // [esp+20h] [ebp+0h] BYREF

  m_Size = this->m_Viewers.m_Size;
  v4 = 0;
  v20 = this;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = this->m_Viewers.m_Memory.m_pMemory;
  p_m_Viewers = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Viewers;
  while ( *m_pMemory != nullptr )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= m_Size )
      goto LABEL_7;
  }
  v7 = v4;
  if ( v4 == -1 )
  {
LABEL_7:
    m_nAllocationCount = this->m_Viewers.m_Memory.m_nAllocationCount;
    p_m_Viewers = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Viewers;
    v9 = this->m_Viewers.m_Size;
    v7 = m_Size;
    if ( v9 + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_Viewers, num: v9 - m_nAllocationCount + 1);
    ++p_m_Viewers[1].m_pMemory;
    v10 = p_m_Viewers->m_pMemory;
    v11 = (int)p_m_Viewers[1].m_pMemory - v9 - 1;
    p_m_Viewers[1].m_nAllocationCount = (int)p_m_Viewers->m_pMemory;
    if ( v11 > 0 )
      _V_memmove(dest: &v10[v9 + 1], src: &v10[v9], count: 4 * v11);
    v12 = &p_m_Viewers->m_pMemory[v9];
    if ( v12 != nullptr )
      *v12 = nullptr;
  }
  v13 = (CFoW_Viewer *)operator new(nSize: 0x40u);
  if ( v13 != nullptr )
    v14 = CFoW_Viewer::CFoW_Viewer(this: v13, nID: v7, nViewerTeam);
  else
    v14 = nullptr;
  p_m_Viewers->m_pMemory[v7] = (vgui::TreeNode *)v14;
  v15 = p_m_Viewers->m_pMemory;
  if ( p_m_Viewers->m_pMemory[v7] != nullptr )
  {
    v16 = (float *)v15[v7];
    v17 = (const void **)&v15[v7];
    bounds.x = v16[3];
    bounds.y = v16[4];
    bounds.z = v16[5];
    bounds.w = *((float *)*v17 + 2);
    CUtlSphereTree::Insert(this: &v20->m_ViewerTree, a2: (int)&savedregs, pData: *v17, (const Vector *)&bounds);
  }
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x101FB270
// Name: public: void CFoW::UpdateViewerLocation(int,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoW::UpdateViewerLocation(CFoW *this, int nID, const Vector *vLocation)
{
  CFoW_Viewer **m_pMemory; // eax
  bool v5; // zf
  CFoW_Viewer **v6; // eax
  CFoW_Viewer **v7; // eax
  CFoW_Viewer **v8; // eax
  const void **v9; // ecx
  float *v10; // eax
  Vector4D bounds; // [esp+20h] [ebp-1Ch] BYREF
  Vector pvOldLocation; // [esp+30h] [ebp-Ch] BYREF
  int _3C; // [esp+3Ch] [ebp+0h] BYREF

  m_pMemory = this->m_Viewers.m_Memory.m_pMemory;
  v5 = m_pMemory[nID] == nullptr;
  v6 = &m_pMemory[nID];
  if ( v5 )
  {
    _Warning(
      a1: "CFoW: UpdateViewerLocation( %d, ( %g, %g %g ) ) has missing viewer\n",
      nID,
      vLocation->x,
      vLocation->y,
      vLocation->z);
  }
  else if ( CFoW_Viewer::UpdateLocation(this: *v6, pFoW: this, vLocation, &pvOldLocation) )
  {
    v7 = this->m_Viewers.m_Memory.m_pMemory;
    if ( v7[nID] != nullptr )
    {
      bounds.x = pvOldLocation.x;
      bounds.y = pvOldLocation.y;
      bounds.z = pvOldLocation.z;
      bounds.w = v7[nID]->m_flRadius;
      CUtlSphereTree::Remove(this: &this->m_ViewerTree, pData: v7[nID], &bounds);
    }
    v8 = this->m_Viewers.m_Memory.m_pMemory;
    if ( v8[nID] != nullptr )
    {
      v9 = (const void **)&v8[nID];
      v10 = (float *)*v9;
      bounds.x = *((float *)*v9 + 3);
      bounds.y = v10[4];
      bounds.z = v10[5];
      bounds.w = *((float *)*v9 + 2);
      CUtlSphereTree::Insert(this: &this->m_ViewerTree, a2: (int)&_3C, pData: *v9, (const Vector *)&bounds);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FB390
// Name: public: void CFoW::UpdateViewerSize(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoW::UpdateViewerSize(CFoW *this, int nID, float flRadius)
{
  CFoW_Viewer **m_pMemory; // eax
  bool v5; // zf
  CFoW_Viewer **v6; // eax
  float *v7; // eax
  CFoW_Viewer **v8; // ecx
  float v9; // xmm0_4
  const void **v10; // eax
  CFoW_Viewer **v11; // ecx
  float *p_m_nID; // eax
  const void **v13; // ecx
  Vector4D bounds; // [esp+10h] [ebp-10h] BYREF
  int _20; // [esp+20h] [ebp+0h] BYREF

  m_pMemory = this->m_Viewers.m_Memory.m_pMemory;
  v5 = m_pMemory[nID] == nullptr;
  v6 = &m_pMemory[nID];
  if ( v5 )
  {
    _Warning(a1: "CFoW: UpdateViewerSize( %d, %g ) has missing viewer\n", nID, flRadius);
  }
  else
  {
    v7 = (float *)*v6;
    v8 = this->m_Viewers.m_Memory.m_pMemory;
    bounds.x = v7[3];
    bounds.y = v7[4];
    v9 = v7[5];
    v10 = (const void **)&v8[nID];
    bounds.z = v9;
    bounds.w = *((float *)*v10 + 2);
    CUtlSphereTree::Remove(this: &this->m_ViewerTree, pData: *v10, &bounds);
    CFoW_Viewer::UpdateSize(this: this->m_Viewers.m_Memory.m_pMemory[nID], pFoW: this, flRadius);
    v11 = this->m_Viewers.m_Memory.m_pMemory;
    if ( v11[nID] != nullptr )
    {
      p_m_nID = (float *)&v11[nID]->m_nID;
      v13 = (const void **)&v11[nID];
      bounds.x = p_m_nID[3];
      bounds.y = p_m_nID[4];
      bounds.z = p_m_nID[5];
      bounds.w = *((float *)*v13 + 2);
      CUtlSphereTree::Insert(this: &this->m_ViewerTree, a2: (int)&_20, pData: *v13, (const Vector *)&bounds);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FB480
// Name: public: int CFoW::AddOccluder(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFoW::AddOccluder(CFoW *this, bool nPermanent)
{
  int m_Size; // ecx
  int v4; // eax
  CFoW_RadiusOccluder **m_pMemory; // edx
  CUtlMemory<vgui::TreeNode *,int> *p_m_Occluders; // esi
  int v7; // ebx
  int m_nAllocationCount; // eax
  int v9; // edi
  vgui::TreeNode **v10; // ecx
  int v11; // eax
  vgui::TreeNode **v12; // edi
  CFoW_RadiusOccluder *v13; // eax
  CFoW_RadiusOccluder *v14; // eax
  const void **v15; // ecx
  float *v16; // eax
  Vector4D bounds; // [esp+Ch] [ebp-14h] BYREF
  CFoW *v19; // [esp+1Ch] [ebp-4h]
  int savedregs; // [esp+20h] [ebp+0h] BYREF

  m_Size = this->m_Occluders.m_Size;
  v4 = 0;
  v19 = this;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = this->m_Occluders.m_Memory.m_pMemory;
  p_m_Occluders = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Occluders;
  while ( *m_pMemory != nullptr )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= m_Size )
      goto LABEL_7;
  }
  v7 = v4;
  if ( v4 == -1 )
  {
LABEL_7:
    m_nAllocationCount = this->m_Occluders.m_Memory.m_nAllocationCount;
    p_m_Occluders = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Occluders;
    v9 = this->m_Occluders.m_Size;
    v7 = m_Size;
    if ( v9 + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_Occluders, num: v9 - m_nAllocationCount + 1);
    ++p_m_Occluders[1].m_pMemory;
    v10 = p_m_Occluders->m_pMemory;
    v11 = (int)p_m_Occluders[1].m_pMemory - v9 - 1;
    p_m_Occluders[1].m_nAllocationCount = (int)p_m_Occluders->m_pMemory;
    if ( v11 > 0 )
      _V_memmove(dest: &v10[v9 + 1], src: &v10[v9], count: 4 * v11);
    v12 = &p_m_Occluders->m_pMemory[v9];
    if ( v12 != nullptr )
      *v12 = nullptr;
  }
  v13 = (CFoW_RadiusOccluder *)operator new(nSize: 0x18u);
  if ( v13 != nullptr )
    v14 = CFoW_RadiusOccluder::CFoW_RadiusOccluder(this: v13, nID: v7);
  else
    v14 = nullptr;
  p_m_Occluders->m_pMemory[v7] = (vgui::TreeNode *)v14;
  if ( p_m_Occluders->m_pMemory[v7] != nullptr )
  {
    v15 = (const void **)&p_m_Occluders->m_pMemory[v7];
    v16 = (float *)*v15;
    bounds.x = *((float *)*v15 + 2);
    bounds.y = v16[3];
    bounds.z = v16[4];
    bounds.w = *((float *)*v15 + 1);
    CUtlSphereTree::Insert(this: &v19->m_OccluderTree, a2: (int)&savedregs, pData: *v15, (const Vector *)&bounds);
  }
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x101FB590
// Name: public: void CFoW::RemoveOccluder(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoW::RemoveOccluder(CFoW *this, int nID)
{
  CFoW_RadiusOccluder **m_pMemory; // eax
  const void **v4; // ecx
  float *v5; // eax
  CFoW_RadiusOccluder *v6; // eax
  Vector4D bounds; // [esp+8h] [ebp-10h] BYREF

  m_pMemory = this->m_Occluders.m_Memory.m_pMemory;
  if ( m_pMemory[nID] != nullptr )
  {
    v4 = (const void **)&m_pMemory[nID];
    v5 = (float *)*v4;
    bounds.x = *((float *)*v4 + 2);
    bounds.y = v5[3];
    bounds.z = v5[4];
    bounds.w = *((float *)*v4 + 1);
    CUtlSphereTree::Remove(this: &this->m_OccluderTree, pData: *v4, &bounds);
    v6 = this->m_Occluders.m_Memory.m_pMemory[nID];
    CFoW::DirtyViewers(this, vLocation: &v6->m_vLocation, flRadius: v6->m_flRadius);
    operator delete(p: this->m_Occluders.m_Memory.m_pMemory[nID]);
    this->m_Occluders.m_Memory.m_pMemory[nID] = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FB630
// Name: public: void CFoW::UpdateOccluderLocation(int,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoW::UpdateOccluderLocation(CFoW *this, int nID, Vector *vLocation)
{
  CFoW_RadiusOccluder **m_pMemory; // eax
  const void **v5; // ecx
  float *v6; // eax
  CFoW_RadiusOccluder *v7; // eax
  CFoW_RadiusOccluder **v8; // edx
  float *p_m_nID; // eax
  const void **v10; // ecx
  CFoW_RadiusOccluder *v11; // edi
  Vector4D v12; // [esp+20h] [ebp-10h] BYREF
  int _30; // [esp+30h] [ebp+0h] BYREF

  m_pMemory = this->m_Occluders.m_Memory.m_pMemory;
  if ( m_pMemory[nID] != nullptr )
  {
    v5 = (const void **)&m_pMemory[nID];
    v6 = (float *)*v5;
    v12.x = *((float *)*v5 + 2);
    v12.y = v6[3];
    v12.z = v6[4];
    v12.w = *((float *)*v5 + 1);
    CUtlSphereTree::Remove(this: &this->m_OccluderTree, pData: *v5, bounds: &v12);
    v7 = this->m_Occluders.m_Memory.m_pMemory[nID];
    CFoW::DirtyViewers(this, vLocation: &v7->m_vLocation, flRadius: v7->m_flRadius);
    CFoW_RadiusOccluder::UpdateLocation(this: this->m_Occluders.m_Memory.m_pMemory[nID], vLocation);
    v8 = this->m_Occluders.m_Memory.m_pMemory;
    if ( v8[nID] != nullptr )
    {
      p_m_nID = (float *)&v8[nID]->m_nID;
      v10 = (const void **)&v8[nID];
      v12.x = p_m_nID[2];
      v12.y = p_m_nID[3];
      v12.z = p_m_nID[4];
      v12.w = *((float *)*v10 + 1);
      CUtlSphereTree::Insert(this: &this->m_OccluderTree, a2: (int)&_30, pData: *v10, bounds: (const Vector *)&v12);
    }
    v11 = this->m_Occluders.m_Memory.m_pMemory[nID];
    CFoW::DirtyViewers(this, vLocation: &v11->m_vLocation, flRadius: v11->m_flRadius);
  }
  else
  {
    _Warning(
      a1: "CFoW: UpdateOccluderLocation( %d, ( %g, %g, %g ) ) has missing occluder\n",
      nID,
      vLocation->x,
      vLocation->y,
      vLocation->z);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FB770
// Name: public: void CFoW::UpdateOccluderSize(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoW::UpdateOccluderSize(CFoW *this, int nID, float flRadius)
{
  CFoW_RadiusOccluder **m_pMemory; // eax
  const void **v5; // ecx
  float *v6; // eax
  CFoW_RadiusOccluder *v7; // eax
  float m_flRadius; // xmm0_4
  CFoW_RadiusOccluder **v9; // ecx
  float *p_m_nID; // eax
  const void **v11; // ecx
  Vector4D bounds; // [esp+10h] [ebp-10h] BYREF
  int _20; // [esp+20h] [ebp+0h] BYREF

  m_pMemory = this->m_Occluders.m_Memory.m_pMemory;
  if ( m_pMemory[nID] != nullptr )
  {
    v5 = (const void **)&m_pMemory[nID];
    v6 = (float *)*v5;
    bounds.x = *((float *)*v5 + 2);
    bounds.y = v6[3];
    bounds.z = v6[4];
    bounds.w = *((float *)*v5 + 1);
    CUtlSphereTree::Remove(this: &this->m_OccluderTree, pData: *v5, &bounds);
    v7 = this->m_Occluders.m_Memory.m_pMemory[nID];
    m_flRadius = v7->m_flRadius;
    if ( m_flRadius <= flRadius )
      m_flRadius = flRadius;
    CFoW::DirtyViewers(this, vLocation: &v7->m_vLocation, flRadius: m_flRadius);
    CFoW_RadiusOccluder::UpdateSize(this: this->m_Occluders.m_Memory.m_pMemory[nID], flRadius);
    v9 = this->m_Occluders.m_Memory.m_pMemory;
    if ( v9[nID] != nullptr )
    {
      p_m_nID = (float *)&v9[nID]->m_nID;
      v11 = (const void **)&v9[nID];
      bounds.x = p_m_nID[2];
      bounds.y = p_m_nID[3];
      bounds.z = p_m_nID[4];
      bounds.w = *((float *)*v11 + 1);
      CUtlSphereTree::Insert(this: &this->m_OccluderTree, a2: (int)&_20, pData: *v11, (const Vector *)&bounds);
    }
  }
  else
  {
    _Warning(a1: "CFoW: UpdateOccluderSize( %d, %g ) has missing occluder\n", nID, flRadius);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FB890
// Name: public: CFoW::~CFoW(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFoW::~CFoW(CFoW *this)
{
  CFoW::ClearState(this);
  CUtlRBTree<CUtlMap<float,int *,unsigned short>::Node_t,unsigned short,CUtlMap<float,int *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<float,int *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<float,int *,unsigned short>::Node_t,unsigned short,CUtlMap<float,int *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<float,int *,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &this->m_RadiusTables.m_Tree);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_TriSoupCollection);
  this->m_OccluderTree.__vftable = (CUtlSphereTree_vtbl *)&CUtlSphereTree::`vftable';
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_OccluderTree.m_Nodes);
  this->m_ViewerTree.__vftable = (CUtlSphereTree_vtbl *)&CUtlSphereTree::`vftable';
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_ViewerTree.m_Nodes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_Occluders);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_Viewers);
}

//------------------------------------------------------------------------------
// Address: 0x101FB8F0
// Name: public: int __near * CFoW::FindRadiusTable(float)
// Source: json
//------------------------------------------------------------------------------
int *__thiscall CFoW::FindRadiusTable(CFoW *this, float flRadius)
{
  CUtlMap<float,int *,unsigned short> *p_m_RadiusTables; // edi
  unsigned __int16 v4; // ax
  int v5; // esi
  int v7; // edi
  int m_nHorizontalGridSize; // ecx
  float v9; // xmm0_4
  int v10; // ecx
  int v11; // eax
  int v12; // esi
  int v13; // ecx
  float v14; // xmm1_4
  double v15; // xmm0_8
  float v16; // xmm0_4
  int v17; // eax
  bool v18; // zf
  CUtlRBTree<TWEdgePair_t,unsigned short,bool (__cdecl*)(TWEdgePair_t const &,TWEdgePair_t const &),CUtlMemory<UtlRBTreeNode_t<TWEdgePair_t,unsigned short>,unsigned short> > *v19; // edi
  unsigned __int16 v20; // ax
  unsigned __int16 v21; // dx
  unsigned __int16 v22; // cx
  int v23; // ebx
  _WORD *v24; // eax
  UtlRBTreeNode_t<TWEdgePair_t,unsigned short> *m_pMemory; // eax
  int v26; // edx
  UtlRBTreeNode_t<TWEdgePair_t,unsigned short> *v27; // ecx
  long double v28; // [esp+0h] [ebp-2Ch] BYREF
  int search_4; // [esp+8h] [ebp-24h]
  int nRadiusUnits; // [esp+Ch] [ebp-20h]
  float nx; // [esp+10h] [ebp-1Ch]
  int v32; // [esp+14h] [ebp-18h]
  unsigned __int16 parent[2]; // [esp+18h] [ebp-14h] BYREF
  int xPos; // [esp+1Ch] [ebp-10h]
  int i; // [esp+20h] [ebp-Ch]
  int *pVisibilityData; // [esp+24h] [ebp-8h]
  int *pVisibility; // [esp+28h] [ebp-4h]

  p_m_RadiusTables = &this->m_RadiusTables;
  *((float *)&v28 + 1) = flRadius;
  LODWORD(v28) = &this->m_RadiusTables;
  v4 = CUtlRBTree<CUtlMap<float,int *,unsigned short>::Node_t,unsigned short,CUtlMap<float,int *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<float,int *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_RadiusTables.m_Tree,
         search: (const CUtlMap<float,int *,unsigned short>::Node_t *)((char *)&v28 + 4));
  v5 = v4;
  if ( v4 < p_m_RadiusTables->m_Tree.m_Elements.m_nAllocationCount
    && v4 <= p_m_RadiusTables->m_Tree.m_LastAlloc.index
    && CUtlRBTree<CUtlMap<float,int *,unsigned short>::Node_t,unsigned short,CUtlMap<float,int *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<float,int *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
         this: &p_m_RadiusTables->m_Tree,
         i: v4) != v4 )
  {
    return this->m_RadiusTables.m_Tree.m_Elements.m_pMemory[v5].m_Data.elem;
  }
  v7 = (int)(float)((float)((float)((float)(flRadius * 2.0) + (float)this->m_nHorizontalGridSize) - 1.0)
                  / (float)this->m_nHorizontalGridSize)
     | 1;
  pVisibilityData = (int *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * v7 * v7);
  memset(dst: (unsigned __int8 *)pVisibilityData, value: 0xFFu, count: 4 * v7 * v7);
  m_nHorizontalGridSize = this->m_nHorizontalGridSize;
  v9 = flRadius;
  this->m_nRadiusTableSize += 4 * v7 * v7;
  nRadiusUnits = (int)((v9 * 6.283185307179586 + (double)m_nHorizontalGridSize - 1.0) / (double)m_nHorizontalGridSize);
  v10 = -(m_nHorizontalGridSize * (v7 / 2));
  v11 = v10;
  pVisibility = pVisibilityData;
  v32 = v10;
  xPos = v10;
  if ( v7 > 0 )
  {
    *(_DWORD *)parent = v7;
    while ( 1 )
    {
      v12 = v10;
      v13 = v11 * v11;
      search_4 = v11 * v11;
      for ( i = v7; i != 0; --i )
      {
        v14 = fsqrt((float)(v13 + v12 * v12));
        if ( v14 <= v9 )
        {
          nx = (float)v11 * (float)(1.0 / v14);
          v15 = (float)((float)((float)v12 * (float)(1.0 / v14)) + (float)(nx * 0.0));
          __libm_sse2_acos(x: v28);
          *(float *)&v15 = v15;
          v16 = *(float *)&v15 * 57.29578;
          if ( nx < 0.0 )
            v16 = 360.0 - v16;
          v17 = (int)(float)((float)(v16 * 0.0027777778) * (float)nRadiusUnits);
          v9 = flRadius;
          *pVisibility = v17;
          v11 = xPos;
          v13 = search_4;
        }
        else
        {
          *pVisibility = -1;
        }
        v12 += this->m_nHorizontalGridSize;
        ++pVisibility;
      }
      v11 += this->m_nHorizontalGridSize;
      v18 = (*(_DWORD *)parent)-- == 1;
      xPos = v11;
      if ( v18 )
        break;
      v10 = v32;
    }
  }
  v19 = (CUtlRBTree<TWEdgePair_t,unsigned short,bool (__cdecl*)(TWEdgePair_t const &,TWEdgePair_t const &),CUtlMemory<UtlRBTreeNode_t<TWEdgePair_t,unsigned short>,unsigned short> > *)LODWORD(v28);
  search_4 = (int)pVisibilityData;
  *((float *)&v28 + 1) = v9;
  *(_DWORD *)parent = 0xFFFF;
  HIBYTE(flRadius) = 0;
  CUtlRBTree<CUtlMap<float,int *,unsigned short>::Node_t,unsigned short,CUtlMap<float,int *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<float,int *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
    this: (CUtlRBTree<CUtlMap<float,int *,unsigned short>::Node_t,unsigned short,CUtlMap<float,int *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<float,int *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)LODWORD(v28),
    insert: (const CUtlMap<float,int *,unsigned short>::Node_t *)((char *)&v28 + 4),
    parent,
    leftchild: (bool *)&flRadius + 3);
  v20 = CUtlRBTree<TWEdgePair_t,unsigned short,bool (__cdecl *)(TWEdgePair_t const &,TWEdgePair_t const &),CUtlMemory<UtlRBTreeNode_t<TWEdgePair_t,unsigned short>,unsigned short>>::NewNode(
          this: v19,
          a2: (const char *)v19);
  v21 = parent[0];
  v22 = v20;
  v23 = v20;
  v24 = (_WORD *)(v23 * 16 + *(_DWORD *)(LODWORD(v28) + 4));
  v24[1] = -1;
  *v24 = -1;
  v24[2] = v21;
  v24[3] = 0;
  if ( v21 == 0xFFFF )
  {
    v19->m_Root = v22;
  }
  else
  {
    m_pMemory = v19->m_Elements.m_pMemory;
    v26 = v21;
    if ( HIBYTE(flRadius) != 0 )
      m_pMemory[v26].m_Left = v22;
    else
      m_pMemory[v26].m_Right = v22;
  }
  CUtlRBTree<CUtlMap<float,int *,unsigned short>::Node_t,unsigned short,CUtlMap<float,int *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<float,int *,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
    this: (CUtlRBTree<CUtlMap<float,int *,unsigned short>::Node_t,unsigned short,CUtlMap<float,int *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<float,int *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)v19,
    elem: v22);
  v27 = v19->m_Elements.m_pMemory;
  ++v19->m_NumElements;
  if ( &v27[v23] != (UtlRBTreeNode_t<TWEdgePair_t,unsigned short> *)-8 )
  {
    v27[v23].m_Data.m_pWindow = (vgui::ToolWindow *)HIDWORD(v28);
    v27[v23].m_Data.m_EdgeType = search_4;
  }
  return pVisibilityData;
}
