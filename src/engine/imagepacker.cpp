// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/imagepacker.cpp
// Functions: 3
// ============================================================

#include "engine\imagepacker.h"

//------------------------------------------------------------------------------
// Address: 0x10197F00
// Name: public: bool CImagePacker::Reset(int,int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImagePacker::Reset(CImagePacker *this, int nSortId, int maxLightmapWidth, int maxLightmapHeight)
{
  int v4; // eax
  int *m_pLightmapWavefront; // edx

  this->m_MaxLightmapHeight = maxLightmapHeight;
  this->m_MaxBlockHeight = maxLightmapHeight + 1;
  this->m_nSortID = nSortId;
  v4 = 0;
  this->m_MaxBlockWidth = maxLightmapWidth + 1;
  this->m_MaxLightmapWidth = maxLightmapWidth;
  this->m_AreaUsed = 0;
  this->m_MinimumHeight = -1;
  if ( maxLightmapWidth > 0 )
  {
    m_pLightmapWavefront = this->m_pLightmapWavefront;
    do
    {
      *m_pLightmapWavefront = -1;
      ++v4;
      ++m_pLightmapWavefront;
    }
    while ( v4 < this->m_MaxLightmapWidth );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10197F60
// Name: public: bool CImagePacker::AddBlock(int,int,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImagePacker::AddBlock(CImagePacker *this, int width, int height, int *returnX, int *returnY)
{
  int v5; // ebx
  int m_MaxLightmapWidth; // eax
  int m_MaxLightmapHeight; // edx
  int v10; // edi
  int v11; // ecx
  bool v12; // sf
  int v13; // eax
  int v14; // eax
  int v15; // edx
  int v16; // edi
  int v17; // eax
  int *v18; // ebx
  int v19; // eax
  int lastX; // [esp+8h] [ebp-14h]
  int bestX; // [esp+Ch] [ebp-10h]
  int v22; // [esp+10h] [ebp-Ch]
  int v23; // [esp+14h] [ebp-8h]
  int outerMinY; // [esp+18h] [ebp-4h]

  v5 = width;
  if ( width >= this->m_MaxBlockWidth && height >= this->m_MaxBlockHeight )
    return 0;
  m_MaxLightmapWidth = this->m_MaxLightmapWidth;
  m_MaxLightmapHeight = this->m_MaxLightmapHeight;
  v10 = -1;
  v11 = 0;
  v13 = m_MaxLightmapWidth - width;
  v12 = v13 < 0;
  lastX = v13;
  bestX = -1;
  outerMinY = m_MaxLightmapHeight;
  v14 = -2;
  if ( v12 )
    goto LABEL_18;
  do
  {
    if ( this->m_pLightmapWavefront[v11] == v14 )
    {
      ++v11;
    }
    else
    {
      v15 = 0;
      v16 = v11 + v5;
      v23 = -1;
      v22 = 0;
      v17 = v11;
      if ( v11 < v11 + v5 )
      {
        v18 = &this->m_pLightmapWavefront[v11];
        do
        {
          if ( *v18 >= v23 )
          {
            v23 = *v18;
            v22 = v17;
          }
          ++v17;
          ++v18;
        }
        while ( v17 < v16 );
        v5 = width;
        v15 = v22;
      }
      v14 = this->m_pLightmapWavefront[v15];
      if ( outerMinY > v14 )
      {
        outerMinY = this->m_pLightmapWavefront[v15];
        bestX = v11;
      }
      v10 = bestX;
      v11 = v15 + 1;
    }
  }
  while ( v11 <= lastX );
  if ( v10 == -1 )
  {
LABEL_18:
    if ( v5 <= this->m_MaxBlockWidth && height <= this->m_MaxBlockHeight )
    {
      this->m_MaxBlockWidth = v5;
      this->m_MaxBlockHeight = height;
    }
    return 0;
  }
  else
  {
    *returnX = v10;
    *returnY = outerMinY + 1;
    v19 = height + outerMinY + 1;
    if ( v19 < this->m_MaxLightmapHeight - 1 )
    {
      if ( v19 > this->m_MinimumHeight )
        this->m_MinimumHeight = v19;
      if ( v10 < v10 + v5 )
        memset32(&this->m_pLightmapWavefront[v10], height + outerMinY, v5);
      this->m_AreaUsed += height * v5;
      return 1;
    }
    else
    {
      if ( v5 <= this->m_MaxBlockWidth && height <= this->m_MaxBlockHeight )
      {
        this->m_MaxBlockWidth = v5;
        this->m_MaxBlockHeight = height;
      }
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101980B0
// Name: public: void CImagePacker::GetMinimumDimensions(int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImagePacker::GetMinimumDimensions(CImagePacker *this, int *pReturnWidth, int *pReturnHeight)
{
  *pReturnWidth = CeilPow2(in: this->m_MaxLightmapWidth);
  *pReturnHeight = CeilPow2(in: this->m_MinimumHeight);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10198330
// Name: public: bool CImagePacker::Reset(int,int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImagePacker::Reset(CImagePacker *this, int nSortId, int maxLightmapWidth, int maxLightmapHeight)
{
  int v4; // eax
  int *m_pLightmapWavefront; // edx

  this->m_MaxLightmapHeight = maxLightmapHeight;
  this->m_MaxBlockHeight = maxLightmapHeight + 1;
  this->m_nSortID = nSortId;
  v4 = 0;
  this->m_MaxBlockWidth = maxLightmapWidth + 1;
  this->m_MaxLightmapWidth = maxLightmapWidth;
  this->m_AreaUsed = 0;
  this->m_MinimumHeight = -1;
  if ( maxLightmapWidth > 0 )
  {
    m_pLightmapWavefront = this->m_pLightmapWavefront;
    do
    {
      *m_pLightmapWavefront = -1;
      ++v4;
      ++m_pLightmapWavefront;
    }
    while ( v4 < this->m_MaxLightmapWidth );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10198390
// Name: public: bool CImagePacker::AddBlock(int,int,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CImagePacker::AddBlock(CImagePacker *this, int width, int height, int *returnX, int *returnY)
{
  int v5; // ebx
  int m_MaxLightmapWidth; // eax
  int m_MaxLightmapHeight; // edx
  int v10; // edi
  int v11; // ecx
  bool v12; // sf
  int v13; // eax
  int v14; // eax
  int v15; // edx
  int v16; // edi
  int v17; // eax
  int *v18; // ebx
  int v19; // eax
  int lastX; // [esp+8h] [ebp-14h]
  int bestX; // [esp+Ch] [ebp-10h]
  int v22; // [esp+10h] [ebp-Ch]
  int v23; // [esp+14h] [ebp-8h]
  int outerMinY; // [esp+18h] [ebp-4h]

  v5 = width;
  if ( width >= this->m_MaxBlockWidth && height >= this->m_MaxBlockHeight )
    return 0;
  m_MaxLightmapWidth = this->m_MaxLightmapWidth;
  m_MaxLightmapHeight = this->m_MaxLightmapHeight;
  v10 = -1;
  v11 = 0;
  v13 = m_MaxLightmapWidth - width;
  v12 = v13 < 0;
  lastX = v13;
  bestX = -1;
  outerMinY = m_MaxLightmapHeight;
  v14 = -2;
  if ( v12 )
    goto LABEL_18;
  do
  {
    if ( this->m_pLightmapWavefront[v11] == v14 )
    {
      ++v11;
    }
    else
    {
      v15 = 0;
      v16 = v11 + v5;
      v23 = -1;
      v22 = 0;
      v17 = v11;
      if ( v11 < v11 + v5 )
      {
        v18 = &this->m_pLightmapWavefront[v11];
        do
        {
          if ( *v18 >= v23 )
          {
            v23 = *v18;
            v22 = v17;
          }
          ++v17;
          ++v18;
        }
        while ( v17 < v16 );
        v5 = width;
        v15 = v22;
      }
      v14 = this->m_pLightmapWavefront[v15];
      if ( outerMinY > v14 )
      {
        outerMinY = this->m_pLightmapWavefront[v15];
        bestX = v11;
      }
      v10 = bestX;
      v11 = v15 + 1;
    }
  }
  while ( v11 <= lastX );
  if ( v10 == -1 )
  {
LABEL_18:
    if ( v5 <= this->m_MaxBlockWidth && height <= this->m_MaxBlockHeight )
    {
      this->m_MaxBlockWidth = v5;
      this->m_MaxBlockHeight = height;
    }
    return 0;
  }
  else
  {
    *returnX = v10;
    *returnY = outerMinY + 1;
    v19 = height + outerMinY + 1;
    if ( v19 < this->m_MaxLightmapHeight - 1 )
    {
      if ( v19 > this->m_MinimumHeight )
        this->m_MinimumHeight = v19;
      if ( v10 < v10 + v5 )
        memset32(&this->m_pLightmapWavefront[v10], height + outerMinY, v5);
      this->m_AreaUsed += height * v5;
      return 1;
    }
    else
    {
      if ( v5 <= this->m_MaxBlockWidth && height <= this->m_MaxBlockHeight )
      {
        this->m_MaxBlockWidth = v5;
        this->m_MaxBlockHeight = height;
      }
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101984E0
// Name: public: void CImagePacker::GetMinimumDimensions(int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CImagePacker::GetMinimumDimensions(CImagePacker *this, int *pReturnWidth, int *pReturnHeight)
{
  *pReturnWidth = CeilPow2(in: this->m_MaxLightmapWidth);
  *pReturnHeight = CeilPow2(in: this->m_MinimumHeight);
}

} // namespace engine_xlsp
