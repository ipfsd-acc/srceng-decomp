// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: meshutils/atlas.cpp
// Functions: 3
// ============================================================

#include "meshutils\atlas.h"

//------------------------------------------------------------------------------
// Address: 0x00576F70
// Name: int SortAtlasCharts(struct AtlasChart_t __near * const __near *,struct AtlasChart_t __near * const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl SortAtlasCharts(AtlasChart_t *const *pOne, AtlasChart_t *const *pTwo)
{
  float y; // xmm0_4
  int v3; // ecx
  float v4; // xmm0_4

  y = **(float **)pOne;
  if ( y <= (*pOne)->m_vMaxTextureSize.y )
    y = (*pOne)->m_vMaxTextureSize.y;
  v3 = (int)y;
  v4 = **(float **)pTwo;
  if ( v4 <= (*pTwo)->m_vMaxTextureSize.y )
    v4 = (*pTwo)->m_vMaxTextureSize.y;
  if ( v3 >= (int)v4 )
    return v3 > (int)v4;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00576FC0
// Name: public: class CPackNode __near * CPackNode::InsertChart(struct AtlasChart_t __near *)
// Source: json
//------------------------------------------------------------------------------
CPackNode *__thiscall CPackNode::InsertChart(CPackNode *this, AtlasChart_t *pChart)
{
  int v3; // edi
  double v4; // st7
  int v5; // eax
  int width; // ecx
  int height; // edx
  CPackNode *v8; // eax
  float m_flTotalH; // xmm1_4
  CPackNode *v10; // eax
  float v11; // xmm1_4
  CPackNode *result; // eax
  float v13; // xmm0_4
  __int64 rect1; // [esp+14h] [ebp-24h]
  unsigned __int64 rect1_8; // [esp+1Ch] [ebp-1Ch]
  __int64 rect0; // [esp+24h] [ebp-14h]
  __int64 rect0_8; // [esp+2Ch] [ebp-Ch]

  while ( 1 )
  {
    v3 = (int)ceil(X: pChart->m_vMaxTextureSize.x);
    v4 = ceil(X: pChart->m_vMaxTextureSize.y);
    v5 = (int)v4;
    if ( this->m_child[0] != nullptr && this->m_child[1] != nullptr )
      break;
    if ( this->m_pChart != nullptr )
      return nullptr;
    width = this->m_rect.width;
    height = this->m_rect.height;
    if ( width < v3 || height < v5 )
      return nullptr;
    if ( width == v3 && height == v5 )
    {
      v13 = (float)this->m_rect.x / this->m_flTotalW;
      this->m_pChart = pChart;
      pChart->m_vAtlasMin.x = v13;
      this->m_pChart->m_vAtlasMin.y = (float)this->m_rect.y / this->m_flTotalH;
      this->m_pChart->m_vAtlasMax.x = (float)(this->m_rect.x + this->m_rect.width) / this->m_flTotalW;
      this->m_pChart->m_vAtlasMax.y = (float)(this->m_rect.y + this->m_rect.height) / this->m_flTotalH;
      return this;
    }
    rect0 = *(_QWORD *)&this->m_rect.x;
    if ( width - v3 <= height - v5 )
    {
      LODWORD(rect0_8) = this->m_rect.width;
      HIDWORD(rect0_8) = (int)v4;
      LODWORD(rect1) = this->m_rect.x;
      HIDWORD(rect1) = v5 + HIDWORD(rect0);
      height -= v5;
    }
    else
    {
      LODWORD(rect0_8) = v3;
      HIDWORD(rect0_8) = this->m_rect.height;
      LODWORD(rect1) = v3 + rect0;
      width -= v3;
      HIDWORD(rect1) = this->m_rect.y;
    }
    rect1_8 = __PAIR64__(height, width);
    v8 = (CPackNode *)MemAlloc_Alloc(nSize: 0x24u);
    if ( v8 != nullptr )
    {
      m_flTotalH = this->m_flTotalH;
      v8->m_flTotalW = this->m_flTotalW;
      *(_QWORD *)&v8->m_rect.x = rect0;
      v8->m_pChart = nullptr;
      v8->m_flTotalH = m_flTotalH;
      v8->m_child[0] = nullptr;
      v8->m_child[1] = nullptr;
      *(_QWORD *)&v8->m_rect.width = rect0_8;
    }
    else
    {
      v8 = nullptr;
    }
    this->m_child[0] = v8;
    v10 = (CPackNode *)MemAlloc_Alloc(nSize: 0x24u);
    if ( v10 != nullptr )
    {
      v11 = this->m_flTotalH;
      v10->m_flTotalW = this->m_flTotalW;
      *(_QWORD *)&v10->m_rect.x = rect1;
      v10->m_pChart = nullptr;
      v10->m_flTotalH = v11;
      v10->m_child[0] = nullptr;
      v10->m_child[1] = nullptr;
      *(_QWORD *)&v10->m_rect.width = rect1_8;
      this->m_child[1] = v10;
    }
    else
    {
      this->m_child[1] = nullptr;
    }
    this = this->m_child[0];
  }
  result = CPackNode::InsertChart(this: this->m_child[0], pChart);
  if ( result == nullptr )
    return CPackNode::InsertChart(this: this->m_child[1], pChart);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00577240
// Name: int PackChartsIntoAtlas(struct AtlasChart_t __near *,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl PackChartsIntoAtlas(
        AtlasChart_t *pCharts,
        int nCharts,
        int nAtlasTextureSizeX,
        int nAtlasTextureSizeY,
        int nAtlasGrow)
{
  int v5; // eax
  bool *m_pMemory; // edi
  AtlasChart_t **v8; // edx
  __int64 v9; // rdi
  CPackNode *m_pRootNode; // eax
  __int64 v11; // xmm0_8
  int i; // ebx
  AtlasChart_t *v13; // esi
  bool v14; // zf
  CPackNode *v15; // ecx
  CUtlVector<AtlasChart_t *,CUtlMemory<AtlasChart_t *,int> > chartVector; // [esp+Ch] [ebp-50h] BYREF
  CUtlVector<bool,CUtlMemory<bool,int> > chartUsed; // [esp+20h] [ebp-3Ch] BYREF
  __int64 v19; // [esp+34h] [ebp-28h]
  __int64 v20; // [esp+3Ch] [ebp-20h]
  CAtlasPacker m_packer; // [esp+44h] [ebp-18h]
  int v22; // [esp+50h] [ebp-Ch]
  int nAttempt; // [esp+54h] [ebp-8h]
  bool bTryGrow; // [esp+5Bh] [ebp-1h]
  char bHaveAtlas_3; // [esp+6Bh] [ebp+Fh]
  int nUnatlased; // [esp+6Ch] [ebp+10h]
  int nAtlasTextureSizeYa; // [esp+70h] [ebp+14h]

  memset(&chartVector, 0, sizeof(chartVector));
  memset(&chartUsed, 0, sizeof(chartUsed));
  if ( nCharts > 0 )
  {
    CUtlVector<dfacebrushlist_t,CUtlMemory<dfacebrushlist_t,int>>::InsertMultipleBefore(
      this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&chartVector,
      elem: 0,
      num: nCharts);
    CUtlMemory<bool,int>::Grow(this: &chartUsed.m_Memory, num: nCharts);
    if ( chartUsed.m_Size > 0 )
      _V_memmove(
        dest: &chartUsed.m_Memory.m_pMemory[nCharts],
        src: chartUsed.m_Memory.m_pMemory,
        count: chartUsed.m_Size);
  }
  v5 = 0;
  if ( nCharts > 0 )
  {
    m_pMemory = chartUsed.m_Memory.m_pMemory;
    v8 = chartVector.m_Memory.m_pMemory;
    do
    {
      v8[v5] = pCharts;
      m_pMemory[v5++] = false;
      ++pCharts;
    }
    while ( v5 < nCharts );
  }
  CUtlVector<AtlasChart_t *,CUtlMemory<AtlasChart_t *,int>>::Sort(this: &chartVector, pfnCompare: SortAtlasCharts);
  LODWORD(v9) = nAtlasTextureSizeX;
  bTryGrow = nAtlasGrow > 0;
  v22 = nCharts - 1;
  HIDWORD(v9) = nAtlasTextureSizeY - nAtlasTextureSizeX;
  nAttempt = 0;
  nUnatlased = 0;
  v19 = 0;
  for ( nAtlasTextureSizeYa = HIDWORD(v9); ; HIDWORD(v9) = nAtlasTextureSizeYa )
  {
    _Msg(a1: "Atlas Attempt: %d\n", nAttempt);
    LODWORD(v9) = nAtlasGrow + v9;
    HIDWORD(v9) += v9;
    bHaveAtlas_3 = 1;
    v20 = v9;
    m_pRootNode = (CPackNode *)MemAlloc_Alloc(nSize: 0x24u);
    if ( m_pRootNode != nullptr )
    {
      m_pRootNode->m_flTotalW = (float)(int)v9;
      m_pRootNode->m_flTotalH = (float)SHIDWORD(v9);
      *(_QWORD *)&m_pRootNode->m_rect.x = v19;
      v11 = v20;
      m_pRootNode->m_pChart = nullptr;
      m_pRootNode->m_child[0] = nullptr;
      m_pRootNode->m_child[1] = nullptr;
      *(_QWORD *)&m_pRootNode->m_rect.width = v11;
      m_packer.m_pRootNode = m_pRootNode;
    }
    else
    {
      m_packer.m_pRootNode = nullptr;
      m_pRootNode = nullptr;
    }
    for ( i = v22; i >= 0; --i )
    {
      v13 = chartVector.m_Memory.m_pMemory[i];
      if ( !v13->m_bAtlased )
      {
        if ( m_pRootNode == nullptr
          || (v14 = CPackNode::InsertChart(this: m_pRootNode, pChart: chartVector.m_Memory.m_pMemory[i]) == nullptr,
              m_pRootNode = m_packer.m_pRootNode,
              v14) )
        {
          if ( bTryGrow )
          {
            ++nAttempt;
            bHaveAtlas_3 = 0;
            break;
          }
          ++nUnatlased;
        }
        else
        {
          v13->m_bAtlased = true;
        }
      }
    }
    if ( m_pRootNode != nullptr )
    {
      if ( m_pRootNode->m_child[0] != nullptr )
      {
        CPackNode::`scalar deleting destructor'(this: m_pRootNode->m_child[0], a2: 1u);
        m_pRootNode = m_packer.m_pRootNode;
      }
      v15 = m_pRootNode->m_child[1];
      if ( v15 != nullptr )
      {
        CPackNode::`scalar deleting destructor'(this: v15, a2: 1u);
        m_pRootNode = m_packer.m_pRootNode;
      }
      free(pMem: m_pRootNode);
    }
    if ( bHaveAtlas_3 != 0 )
      break;
  }
  if ( chartUsed.m_Memory.m_nGrowSize >= 0 && chartUsed.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: chartUsed.m_Memory.m_pMemory);
  if ( chartVector.m_Memory.m_nGrowSize >= 0 && chartVector.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: chartVector.m_Memory.m_pMemory);
  return nUnatlased;
}
