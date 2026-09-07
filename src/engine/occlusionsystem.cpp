// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/occlusionsystem.cpp
// Functions: 49
// ============================================================

#include "engine\occlusionsystem.h"

//------------------------------------------------------------------------------
// Address: 0x1003FD10
// Name: protected: static int CUtlSortVector<class CSortedCacheFile,class CSortedCacheFile>::CompareHelper(void __near *,class CSortedCacheFile const __near *,class CSortedCacheFile const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CUtlSortVector<CSortedCacheFile,CSortedCacheFile>::CompareHelper(
        void *context,
        const CSortedCacheFile *lhs,
        const CSortedCacheFile *rhs)
{
  char s1[512]; // [esp+8h] [ebp-400h] BYREF
  char s2[512]; // [esp+208h] [ebp-200h] BYREF

  g_pFullFileSystem->String(this: g_pFullFileSystem, a2: (void *const *)lhs, a3: s1, a4: 512);
  g_pFullFileSystem->String(this: g_pFullFileSystem, a2: (void *const *)rhs, a3: s2, a4: 512);
  if ( _V_stricmp(s1, s2) < 0 )
    return -1;
  g_pFullFileSystem->String(this: g_pFullFileSystem, a2: (void *const *)rhs, a3: s2, a4: 512);
  g_pFullFileSystem->String(this: g_pFullFileSystem, a2: (void *const *)lhs, a3: s1, a4: 512);
  return _V_stricmp(s1: s2, s2: s1) < 0;
}

//------------------------------------------------------------------------------
// Address: 0x100C4980
// Name: protected: static int CUtlSortVector<int,class SurfaceLessFunc>::CompareHelper(void __near *,int const __near *,int const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CUtlSortVector<int,SurfaceLessFunc>::CompareHelper(_DWORD *context, const int *lhs, const int *rhs)
{
  int v3; // ecx
  int v4; // edx

  v3 = 32 * *lhs;
  v4 = 32 * *rhs;
  if ( *(_DWORD *)(v3 + *context + 28) >= *(_DWORD *)(v4 + *context + 28) )
    return *(_DWORD *)(v4 + *context + 28) < *(_DWORD *)(v3 + *context + 28);
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x100DB2B0
// Name: protected: static int CUtlSortVector<struct robject_t,class CRobjectLess>::CompareHelper(void __near *,struct robject_t const __near *,struct robject_t const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CUtlSortVector<robject_t,CRobjectLess>::CompareHelper(
        float **context,
        const robject_t *lhs,
        const robject_t *rhs)
{
  float *v3; // esi
  CRobjectLess *v4; // edi

  v3 = *context;
  v4 = (CRobjectLess *)context[1];
  if ( CRobjectLess::Less(this: v4, lhs, rhs, pContext: *context) )
    return -1;
  else
    return CRobjectLess::Less(this: v4, lhs: rhs, rhs: lhs, pContext: v3);
}

//------------------------------------------------------------------------------
// Address: 0x100ED730
// Name: public: int CUtlSortVector<struct modelsize_t,class CModelsize_Less>::FindLessOrEqual(struct modelsize_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<modelsize_t,CModelsize_Less>::FindLessOrEqual(
        CUtlSortVector<modelsize_t,CModelsize_Less> *this,
        const modelsize_t *src)
{
  int v3; // esi
  int v4; // ecx
  modelsize_t *m_pMemory; // ebx
  int size; // edi
  int result; // eax
  int v8; // edx

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1\\utlsortvector.h",
         277,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1\\utlsortvector.h",
                            a2: 277,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1\\utlsortvector.h",
      a2: 277);
  }
  v3 = 0;
  v4 = this->m_Size - 1;
  if ( v4 >= 0 )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    size = src->size;
    do
    {
      result = (v4 + v3) >> 1;
      v8 = m_pMemory[result].size;
      if ( size <= v8 )
      {
        if ( size >= v8 )
          return result;
        v4 = result - 1;
      }
      else
      {
        v3 = result + 1;
      }
    }
    while ( v3 <= v4 );
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x100EF3F0
// Name: public: int CUtlSortVector<struct modelsize_t,class CModelsize_Less>::Insert(struct modelsize_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<modelsize_t,CModelsize_Less>::Insert(
        CUtlSortVector<modelsize_t,CModelsize_Less> *this,
        const modelsize_t *src)
{
  int LessOrEqual; // eax
  int m_nAllocationCount; // ecx
  int v5; // edi
  int m_Size; // eax
  modelsize_t *m_pMemory; // ecx
  int v8; // eax
  modelsize_t *v9; // eax

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1\\utlsortvector.h",
         150,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1\\utlsortvector.h",
                            a2: 150,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1\\utlsortvector.h",
      a2: 150);
  }
  LessOrEqual = CUtlSortVector<modelsize_t,CModelsize_Less>::FindLessOrEqual(this, src);
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  v5 = LessOrEqual + 1;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CAsyncWavDataCache::DeadBufferEntry_t,int>::Grow(
      (CUtlMemory<ResourceEntryInfo,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size - v5 - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[v5 + 1], src: &m_pMemory[v5], count: 8 * v8);
  v9 = &this->m_Memory.m_pMemory[v5];
  if ( v9 != nullptr )
    *v9 = *src;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x100F1690
// Name: public: struct cplane_t __near & cplane_t::operator=(struct cplane_t const __near &)
// Source: json
//------------------------------------------------------------------------------
cplane_t *__thiscall cplane_t::operator=(cplane_t *this, const cplane_t *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100F16D0
// Name: private: static int CEdgeList::SurfCompare(void const __near *,void const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CEdgeList::SurfCompare(_DWORD *elem1, _DWORD *elem2)
{
  float m_flArea; // xmm0_4
  float v3; // xmm1_4

  m_flArea = CEdgeList::s_pSortSurfaces[*elem1].m_flArea;
  v3 = CEdgeList::s_pSortSurfaces[*elem2].m_flArea;
  if ( m_flArea <= v3 )
    return v3 > m_flArea;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x100F1710
// Name: private: float CEdgeList::LocateEdgeCrossingDiscontinuity(float,float,int __near &,struct CEdgeList::Edge_t __near * __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CEdgeList::LocateEdgeCrossingDiscontinuity(
        CEdgeList *this,
        float flNextY,
        float flPrevY,
        int *nCount,
        CEdgeList::Edge_t **ppInfo)
{
  float v5; // xmm2_4
  CEdgeList::Edge_t *m_pNextActiveEdge; // edx
  CEdgeList::Edge_t *p_m_EndTerminal; // ebx
  float y; // xmm0_4
  float m_flDxDy; // xmm4_4
  float *p_x; // ecx
  float v12; // xmm3_4
  float v13; // xmm2_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm1_4
  float flCurrY; // [esp+10h] [ebp+10h]

  v5 = -3.4028235e38;
  *nCount = 0;
  m_pNextActiveEdge = this->m_StartTerminal.m_pNextActiveEdge;
  p_m_EndTerminal = &this->m_EndTerminal;
  for ( flCurrY = flNextY; m_pNextActiveEdge != p_m_EndTerminal; v5 = v12 )
  {
    y = m_pNextActiveEdge->m_vecPosition.y;
    m_flDxDy = m_pNextActiveEdge->m_flDxDy;
    p_x = &m_pNextActiveEdge->m_pPrevActiveEdge->m_vecPosition.x;
    v12 = (float)((float)(flCurrY - y) * m_flDxDy) + m_pNextActiveEdge->m_vecPosition.x;
    if ( v12 <= v5 )
    {
      v13 = p_x[6];
      if ( m_flDxDy < v13
        && (m_pNextActiveEdge->m_vecPositionEnd.x != p_x[3]
         || m_pNextActiveEdge->m_vecPositionEnd.y != p_x[4]
         || m_pNextActiveEdge->m_vecPositionEnd.z != p_x[5]) )
      {
        v14 = p_x[1];
        v15 = (float)(1.0 / (float)(m_pNextActiveEdge->m_flDxDy - v13))
            * (float)((float)(m_pNextActiveEdge->m_flDxDy * (float)(y - v14))
                    - (float)(m_pNextActiveEdge->m_vecPosition.x - *p_x));
        v16 = v14 + v15;
        if ( v16 < flNextY )
        {
          if ( flPrevY > v16 )
            v16 = flPrevY;
          if ( flCurrY != v16 )
          {
            flCurrY = v16;
            *nCount = 0;
          }
          v12 = (float)(p_x[6] * v15) + *p_x;
          ppInfo[(*nCount)++] = m_pNextActiveEdge;
        }
      }
    }
    m_pNextActiveEdge = m_pNextActiveEdge->m_pNextActiveEdge;
  }
  return flCurrY;
}

//------------------------------------------------------------------------------
// Address: 0x100F1860
// Name: private: void CEdgeList::ReorderActiveEdgeList(int,struct CEdgeList::Edge_t __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEdgeList::ReorderActiveEdgeList(CEdgeList *this, int nCount, CEdgeList::Edge_t **ppCrossings)
{
  int v3; // edi
  CEdgeList *v4; // eax
  CEdgeList::Edge_t *v5; // ebx
  CEdgeList::Edge_t *m_pPrevActiveEdge; // esi
  CEdgeList::Edge_t *v7; // edx
  CEdgeList::Edge_t *i; // edx
  float m_flX; // xmm0_4
  CEdgeList::Edge_t *j; // esi
  CEdgeList::Edge_t *m_pNextActiveEdge; // edx
  CEdgeList::Edge_t *p_m_EndTerminal; // ecx
  CEdgeList::Edge_t *v13; // esi
  CEdgeList::Edge_t *v14; // ebx
  CEdgeList::Edge_t *k; // eax
  float v16; // xmm0_4
  CEdgeList::Edge_t *v17; // esi

  v3 = 0;
  v4 = this;
  if ( nCount > 0 )
  {
    do
    {
      v5 = ppCrossings[v3];
      m_pPrevActiveEdge = v5->m_pPrevActiveEdge;
      v7 = m_pPrevActiveEdge->m_pPrevActiveEdge;
      ++v3;
      for ( ; v7->m_flX == m_pPrevActiveEdge->m_flX; v7 = v7->m_pPrevActiveEdge )
        m_pPrevActiveEdge = v7;
      for ( i = v5->m_pNextActiveEdge; ; i = i->m_pNextActiveEdge )
      {
        while ( v3 < nCount && i == ppCrossings[v3] )
        {
          v5 = i;
          i = i->m_pNextActiveEdge;
          ++v3;
        }
        if ( v5->m_flX != i->m_flX )
          break;
      }
      m_flX = m_pPrevActiveEdge->m_flX;
      for ( j = m_pPrevActiveEdge->m_pNextActiveEdge; j != i; j = j->m_pNextActiveEdge )
        j->m_flX = m_flX;
    }
    while ( v3 < nCount );
    v4 = this;
  }
  m_pNextActiveEdge = v4->m_StartTerminal.m_pNextActiveEdge;
  p_m_EndTerminal = &v4->m_EndTerminal;
  if ( m_pNextActiveEdge != &v4->m_EndTerminal )
  {
    do
    {
      v13 = m_pNextActiveEdge->m_pPrevActiveEdge;
      v14 = m_pNextActiveEdge->m_pNextActiveEdge;
      if ( v13->m_flX == m_pNextActiveEdge->m_flX )
      {
        v13->m_pNextActiveEdge = v14;
        m_pNextActiveEdge->m_pNextActiveEdge->m_pPrevActiveEdge = m_pNextActiveEdge->m_pPrevActiveEdge;
        for ( k = v13; k != &this->m_StartTerminal; k = k->m_pPrevActiveEdge )
        {
          v16 = k->m_flX - m_pNextActiveEdge->m_flX;
          if ( v16 <= 0.0 && (v16 < 0.0 || k->m_flDxDy <= m_pNextActiveEdge->m_flDxDy) )
            break;
        }
        v17 = k->m_pNextActiveEdge;
        m_pNextActiveEdge->m_pNextActiveEdge = v17;
        m_pNextActiveEdge->m_pPrevActiveEdge = k;
        v17->m_pPrevActiveEdge = m_pNextActiveEdge;
        k->m_pNextActiveEdge = m_pNextActiveEdge;
      }
      m_pNextActiveEdge = v14;
    }
    while ( v14 != p_m_EndTerminal );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F19A0
// Name: class IOcclusionSystem __near * OcclusionSystem(void)
// Source: json
//------------------------------------------------------------------------------
COcclusionSystem *__cdecl OcclusionSystem()
{
  return &g_OcclusionSystem;
}

//------------------------------------------------------------------------------
// Address: 0x100F19B0
// Name: public: virtual void COcclusionSystem::SetOcclusionParameters(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COcclusionSystem::SetOcclusionParameters(
        COcclusionSystem *this,
        float flMaxOccludeeArea,
        float flMinOccluderArea)
{
  float v3; // xmm0_4
  float v4; // xmm0_4

  v3 = flMaxOccludeeArea;
  if ( flMaxOccludeeArea == 0.0 )
    v3 = 5.0;
  this->m_flMaxOccludeeArea = v3 * 0.0099999998;
  v4 = flMinOccluderArea;
  if ( flMinOccluderArea == 0.0 )
    v4 = 5.0;
  this->m_flMinOccluderArea = v4;
}

//------------------------------------------------------------------------------
// Address: 0x100F1A00
// Name: public: virtual float COcclusionSystem::MinOccluderArea(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall COcclusionSystem::MinOccluderArea(COcclusionSystem *this)
{
  return this->m_flMinOccluderArea;
}

//------------------------------------------------------------------------------
// Address: 0x100F1A10
// Name: private: int COcclusionSystem::ClipPolygonToNearPlane(class Vector __near * __near *,int,class Vector __near * __near *,bool __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall COcclusionSystem::ClipPolygonToNearPlane(
        COcclusionSystem *this,
        Vector **ppVertices,
        int nVertexCount,
        Vector **ppOutVerts,
        bool *pClipped)
{
  Vector *v6; // esi
  int v7; // ebx
  bool v8; // cl
  Vector *v9; // edx
  Vector *v10; // edi
  float y; // xmm0_4
  float x; // xmm1_4
  float z; // xmm2_4
  const Vector *v14; // eax
  float v15; // xmm4_4
  double v16; // st7
  float v17; // xmm1_4
  float v18; // xmm0_4
  float v19; // xmm2_4
  Vector *v20; // ecx
  float v21; // xmm1_4
  float v22; // eax
  float v23; // xmm1_4
  float v24; // xmm0_4
  float v25; // xmm2_4
  float v26; // xmm1_4
  float v27; // eax
  const Vector *v28; // [esp-14h] [ebp-48h]
  float v29; // [esp-10h] [ebp-44h]
  float v30; // [esp-10h] [ebp-44h]
  Vector dist; // [esp+0h] [ebp-34h] BYREF
  Vector v32; // [esp+Ch] [ebp-28h] BYREF
  float v33; // [esp+18h] [ebp-1Ch]
  Vector dir; // [esp+1Ch] [ebp-18h]
  int v35; // [esp+28h] [ebp-Ch]
  Vector *v36; // [esp+2Ch] [ebp-8h]
  char v37; // [esp+32h] [ebp-2h]
  char v38; // [esp+33h] [ebp-1h]

  *pClipped = false;
  LODWORD(dir.y) = this;
  if ( nVertexCount < 3 )
    return 0;
  v6 = ppVertices[nVertexCount - 1];
  v7 = 0;
  v8 = (float)((float)((float)(v6->y * this->m_NearClipPlane.normal.y) + (float)(this->m_NearClipPlane.normal.x * v6->x))
             + (float)(v6->z * this->m_NearClipPlane.normal.z)) >= this->m_NearClipPlane.dist;
  v38 = v8;
  v35 = 0;
  v9 = s_TempVertMemory;
  do
  {
    v10 = ppVertices[v35];
    y = v10->y;
    x = v10->x;
    z = v10->z;
    v14 = (const Vector *)(LODWORD(dir.y) + 164);
    v15 = (float)((float)(*(float *)(LODWORD(dir.y) + 164) * v10->x) + (float)(*(float *)(LODWORD(dir.y) + 168) * y))
        + (float)(*(float *)(LODWORD(dir.y) + 172) * z);
    dir.z = *(float *)(LODWORD(dir.y) + 176);
    if ( v15 < dir.z )
    {
      v37 = 0;
      if ( !v8 )
        goto LABEL_11;
      v23 = x - v6->x;
      v24 = y - v6->y;
      v25 = z - v6->z;
      v30 = dir.z;
      v28 = (const Vector *)(LODWORD(dir.y) + 164);
      ppOutVerts[v7] = v9;
      v36 = v9 + 1;
      LODWORD(dir.x) = ppOutVerts[v7];
      dist.x = v23;
      dist.y = v24;
      dist.z = v25;
      v33 = IntersectRayWithPlane(org: v6, dir: &dist, normal: v28, dist: v30);
      v26 = v33;
      v27 = dir.x;
      v9 = v36;
      *(float *)LODWORD(dir.x) = (float)((float)(v10->x - v6->x) * v33) + v6->x;
      *(float *)(LODWORD(v27) + 4) = (float)((float)(v10->y - v6->y) * v26) + v6->y;
      *(float *)(LODWORD(v27) + 8) = (float)((float)(v10->z - v6->z) * v26) + v6->z;
      *pClipped = true;
    }
    else
    {
      v37 = 1;
      if ( v38 == 0 )
      {
        v16 = dir.z;
        v17 = x - v6->x;
        v18 = y - v6->y;
        v19 = z - v6->z;
        ppOutVerts[v7] = v9;
        v20 = ppOutVerts[v7];
        v29 = v16;
        v36 = v9 + 1;
        v33 = *(float *)&v20;
        v32.x = v17;
        v32.y = v18;
        v32.z = v19;
        dir.x = IntersectRayWithPlane(org: v6, dir: &v32, normal: v14, dist: v29);
        v21 = dir.x;
        v22 = v33;
        v9 = v36;
        *(float *)LODWORD(v33) = (float)((float)(v10->x - v6->x) * dir.x) + v6->x;
        *(float *)(LODWORD(v22) + 4) = (float)((float)(v10->y - v6->y) * v21) + v6->y;
        *(float *)(LODWORD(v22) + 8) = (float)((float)(v10->z - v6->z) * v21) + v6->z;
        ++v7;
        *pClipped = true;
      }
      ppOutVerts[v7] = v10;
    }
    ++v7;
LABEL_11:
    v8 = v37;
    v6 = v10;
    v38 = v37;
    ++v35;
  }
  while ( v35 < nVertexCount );
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x100F1C80
// Name: private: int COcclusionSystem::ClipPolygonToAxisAlignedPlane(class Vector __near * __near *,int,struct COcclusionSystem::AxisAlignedPlane_t const __near &,class Vector __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall COcclusionSystem::ClipPolygonToAxisAlignedPlane(
        COcclusionSystem *this,
        Vector **ppVertices,
        int nVertexCount,
        const COcclusionSystem::AxisAlignedPlane_t *plane,
        Vector **ppOutVerts)
{
  Vector *v5; // edi
  const COcclusionSystem::AxisAlignedPlane_t *v6; // eax
  int v7; // ebx
  bool v8; // cl
  Vector *v9; // esi
  int v10; // ecx
  int v11; // ecx
  Vector *v13; // [esp+8h] [ebp-18h]
  float v14; // [esp+8h] [ebp-18h]
  float v15; // [esp+Ch] [ebp-14h]
  Vector *v16; // [esp+Ch] [ebp-14h]
  float m_flSign; // [esp+10h] [ebp-10h]
  float m_flDist; // [esp+14h] [ebp-Ch]
  int v19; // [esp+18h] [ebp-8h]
  char v20; // [esp+1Fh] [ebp-1h]

  v5 = ppVertices[nVertexCount - 1];
  v6 = plane;
  v7 = 0;
  v8 = (float)(*(&v5->x + plane->m_nAxis) * plane->m_flSign) >= plane->m_flDist;
  v19 = 0;
  if ( nVertexCount > 0 )
  {
    while ( 1 )
    {
      v9 = ppVertices[v19];
      m_flSign = v6->m_flSign;
      m_flDist = v6->m_flDist;
      if ( (float)(*(&v9->x + v6->m_nAxis) * m_flSign) >= m_flDist )
        break;
      v20 = 0;
      if ( v8 )
      {
        v11 = s_nTempVertCount++;
        ppOutVerts[v7] = &s_TempVertMemory[v11];
        v16 = &s_TempVertMemory[v11];
        v14 = IntersectRayWithAAPlane(
                vecStart: v5,
                vecEnd: v9,
                nAxis: v6->m_nAxis,
                flSign: v6->m_flSign,
                flDist: v6->m_flDist);
        v16->x = (float)((float)(v9->x - v5->x) * v14) + v5->x;
        v16->y = (float)((float)(v9->y - v5->y) * v14) + v5->y;
        v16->z = (float)((float)(v9->z - v5->z) * v14) + v5->z;
        v6 = plane;
LABEL_8:
        ++v7;
      }
      v8 = v20;
      v5 = v9;
      if ( ++v19 >= nVertexCount )
        return v7;
    }
    v20 = 1;
    if ( !v8 )
    {
      v10 = s_nTempVertCount++;
      ppOutVerts[v7] = &s_TempVertMemory[v10];
      v13 = &s_TempVertMemory[v10];
      v15 = IntersectRayWithAAPlane(vecStart: v5, vecEnd: v9, nAxis: v6->m_nAxis, flSign: m_flSign, flDist: m_flDist);
      v13->x = (float)((float)(v9->x - v5->x) * v15) + v5->x;
      v13->y = (float)((float)(v9->y - v5->y) * v15) + v5->y;
      v13->z = (float)((float)(v9->z - v5->z) * v15) + v5->z;
      v6 = plane;
      ++v7;
    }
    ppOutVerts[v7] = v9;
    goto LABEL_8;
  }
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x100F1E60
// Name: public: virtual void COcclusionSystem::ActivateOccluder(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COcclusionSystem::ActivateOccluder(COcclusionSystem *this, int nOccluderIndex, bool bActive)
{
  doccluderdata_t *v3; // eax

  if ( nOccluderIndex < host_state.worldbrush->numoccluders && nOccluderIndex >= 0 )
  {
    v3 = &host_state.worldbrush->occluders[nOccluderIndex];
    if ( bActive )
      v3->flags &= ~1u;
    else
      v3->flags |= 1u;
    this->m_bEdgeListDirty = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F1EA0
// Name: public: virtual void COcclusionSystem::SetView(class Vector const __near &,float,class VMatrix const __near &,class VMatrix const __near &,class VPlane const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COcclusionSystem::SetView(
        COcclusionSystem *this,
        const Vector *vecCameraPos,
        float flFOV,
        const VMatrix *worldToCamera,
        const VMatrix *cameraToProjection,
        const VPlane *nearClipPlane)
{
  double m_Dist; // st7
  float v8; // xmm0_4
  long double v9; // st7
  int m_nTests; // eax

  this->m_vecCameraPosition = *vecCameraPos;
  VMatrix::operator=(this: &this->m_WorldToCamera, mOther: worldToCamera);
  this->m_flXProjScale = -(float)(cameraToProjection->m[2][3] / cameraToProjection->m[0][0]);
  this->m_flYProjScale = -(float)(cameraToProjection->m[2][3] / cameraToProjection->m[1][1]);
  this->m_flProjDistScale = -cameraToProjection->m[2][3];
  this->m_flProjDistOffset = -cameraToProjection->m[2][2];
  MatrixMultiply(src1: cameraToProjection, src2: worldToCamera, dst: &this->m_WorldToProjection);
  this->m_NearClipPlane.normal.x = nearClipPlane->m_Normal.x;
  this->m_NearClipPlane.normal.y = nearClipPlane->m_Normal.y;
  this->m_NearClipPlane.normal.z = nearClipPlane->m_Normal.z;
  m_Dist = nearClipPlane->m_Dist;
  this->m_NearClipPlane.type = 3;
  this->m_NearClipPlane.dist = m_Dist;
  this->m_bEdgeListDirty = true;
  LODWORD(v8) = COERCE_UNSIGNED_INT(
                  (float)((float)((float)(this->m_NearClipPlane.normal.y * vecCameraPos->y)
                                + (float)(vecCameraPos->x * this->m_NearClipPlane.normal.x))
                        + (float)(this->m_NearClipPlane.normal.z * vecCameraPos->z))
                - this->m_NearClipPlane.dist)
              ^ _mask__NegFloat_;
  this->m_flNearPlaneDist = v8;
  v9 = this->m_flNearPlaneDist / (tan(flFOV * 0.5 * 3.141592653589793 * 0.005555555555555556) * v8);
  this->m_flFOVFactor = v9 * v9;
  if ( r_occlusionspew.m_pParent != nullptr && r_occlusionspew.m_pParent->m_Value.m_nValue != 0 )
  {
    m_nTests = this->m_nTests;
    if ( m_nTests != 0 )
    {
      _Msg(a1: "Occl %.2f (%d/%d)\n", (double)this->m_nOccluded / (double)m_nTests * 100.0, this->m_nOccluded, m_nTests);
      this->m_nTests = 0;
      this->m_nOccluded = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F2040
// Name: public: bool WingedEdgeLessFunc::Less(int const __near &,int const __near &,void __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall WingedEdgeLessFunc::Less(WingedEdgeLessFunc *this, Vector *src1, Vector *src2, float *pCtx)
{
  EdgeInfo_t *v4; // eax
  int m_nMinVert; // edi
  int v6; // ebx
  EdgeInfo_t *v7; // ecx
  float y; // xmm4_4
  float v9; // xmm5_4
  float x; // xmm0_4
  float v12; // xmm1_4
  int v13; // eax
  int v14; // ecx
  Vector *pV1; // [esp+14h] [ebp+8h]
  Vector *pV2; // [esp+18h] [ebp+Ch]

  v4 = &s_pEdges[LODWORD(src1->x)];
  m_nMinVert = v4->m_nMinVert;
  v6 = s_pEdges[LODWORD(src2->x)].m_nMinVert;
  v7 = &s_pEdges[LODWORD(src2->x)];
  pV1 = (Vector *)&pCtx[3 * v4->m_nVert[m_nMinVert]];
  pV2 = (Vector *)&pCtx[3 * v7->m_nVert[v6]];
  y = pV1->y;
  v9 = pV2->y;
  if ( v9 > y )
    return true;
  if ( y > v9 )
    return false;
  x = pV1->x;
  v12 = pV2->x;
  if ( pV2->x > pV1->x )
    return true;
  if ( x > v12 )
    return false;
  v13 = 3 * v4->m_nVert[-m_nMinVert + 1];
  v14 = 3 * v7->m_nVert[-v6 + 1];
  return (float)((float)(pCtx[v14] - v12) * (float)(pCtx[v13 + 1] - y)) >= (float)((float)(pCtx[v14 + 1] - v9)
                                                                                 * (float)(pCtx[v13] - x));
}

//------------------------------------------------------------------------------
// Address: 0x100F2130
// Name: public: int CUtlSortVector<int,class WingedEdgeLessFunc>::FindLessOrEqual(int const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<int,WingedEdgeLessFunc>::FindLessOrEqual(
        CUtlSortVector<int,WingedEdgeLessFunc> *this,
        Vector *src)
{
  int v3; // edi
  int v4; // esi
  int *m_pMemory; // [esp+Ch] [ebp-Ch]
  float *pCtx; // [esp+10h] [ebp-8h]
  int start; // [esp+14h] [ebp-4h]

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1\\utlsortvector.h",
         277,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1\\utlsortvector.h",
                            a2: 277,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1\\utlsortvector.h",
      a2: 277);
  }
  v3 = this->m_Size - 1;
  start = 0;
  if ( v3 < 0 )
    return v3;
  pCtx = (float *)this->m_pLessContext;
  m_pMemory = this->m_Memory.m_pMemory;
  while ( 1 )
  {
    v4 = (v3 + start) >> 1;
    if ( !WingedEdgeLessFunc::Less(
            this: (WingedEdgeLessFunc *)&src + 3,
            src1: (Vector *)&m_pMemory[v4],
            src2: src,
            pCtx) )
      break;
    start = v4 + 1;
LABEL_13:
    if ( start > v3 )
      return v3;
  }
  if ( WingedEdgeLessFunc::Less(this: (WingedEdgeLessFunc *)&src + 3, src1: src, src2: (Vector *)&m_pMemory[v4], pCtx) )
  {
    v3 = v4 - 1;
    goto LABEL_13;
  }
  return (v3 + start) >> 1;
}

//------------------------------------------------------------------------------
// Address: 0x100F2220
// Name: private: bool CWingedEdgeList::AdvanceActiveEdgeList(float)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CWingedEdgeList::AdvanceActiveEdgeList(CWingedEdgeList *this, float flCurrY)
{
  CWingedEdgeList *m_pNextActiveEdge; // eax
  float y; // xmm0_4
  CWingedEdgeList *v4; // edx
  int m_Size; // esi
  int m_nCurrentEdgeIndex; // eax
  CWingedEdgeList::WingedEdge_t *v8; // eax
  float v9; // xmm0_4
  CWingedEdgeList *i; // edx
  float v11; // xmm0_4
  CWingedEdgeList::WingedEdge_t *v12; // ebx
  int v13; // eax
  float v14; // xmm0_4

  m_pNextActiveEdge = (CWingedEdgeList *)this->m_StartTerminal.m_pNextActiveEdge;
  this->m_flNextDiscontinuity = 3.4028235e38;
  if ( m_pNextActiveEdge != (CWingedEdgeList *)&this->m_EndTerminal )
  {
    do
    {
      y = m_pNextActiveEdge->m_StartTerminal.m_vecPositionEnd.y;
      v4 = (CWingedEdgeList *)m_pNextActiveEdge->m_StartTerminal.m_pNextActiveEdge;
      if ( flCurrY < y )
      {
        m_pNextActiveEdge->m_StartTerminal.m_flX = (float)((float)(flCurrY
                                                                 - m_pNextActiveEdge->m_StartTerminal.m_vecPosition.y)
                                                         * m_pNextActiveEdge->m_StartTerminal.m_flDxDy)
                                                 + m_pNextActiveEdge->m_StartTerminal.m_vecPosition.x;
        if ( this->m_flNextDiscontinuity > y )
          this->m_flNextDiscontinuity = y;
      }
      else
      {
        m_pNextActiveEdge->m_StartTerminal.m_pPrevActiveEdge->m_pNextActiveEdge = &v4->m_StartTerminal;
        m_pNextActiveEdge->m_StartTerminal.m_pNextActiveEdge->m_pPrevActiveEdge = m_pNextActiveEdge->m_StartTerminal.m_pPrevActiveEdge;
      }
      m_pNextActiveEdge = v4;
    }
    while ( v4 != (CWingedEdgeList *)&this->m_EndTerminal );
  }
  m_Size = this->m_WingedEdges.m_Size;
  m_nCurrentEdgeIndex = this->m_nCurrentEdgeIndex;
  if ( m_nCurrentEdgeIndex == m_Size )
    return this->m_flNextDiscontinuity != 3.4028235e38;
  v8 = &this->m_WingedEdges.m_Memory.m_pMemory[m_nCurrentEdgeIndex];
  if ( flCurrY < v8->m_vecPosition.y )
  {
LABEL_21:
    v14 = v8->m_vecPosition.y;
    if ( this->m_flNextDiscontinuity > v14 )
      this->m_flNextDiscontinuity = v14;
  }
  else
  {
    while ( 1 )
    {
      v9 = v8->m_vecPositionEnd.y;
      if ( v9 > flCurrY )
      {
        v8->m_flX = (float)((float)(flCurrY - v8->m_vecPosition.y) * v8->m_flDxDy) + v8->m_vecPosition.x;
        if ( this->m_flNextDiscontinuity > v9 )
          this->m_flNextDiscontinuity = v9;
        for ( i = (CWingedEdgeList *)this->m_EndTerminal.m_pPrevActiveEdge;
              i != this;
              i = (CWingedEdgeList *)i->m_StartTerminal.m_pPrevActiveEdge )
        {
          v11 = i->m_StartTerminal.m_flX - v8->m_flX;
          if ( v11 <= 0.0 && (v11 < 0.0 || i->m_StartTerminal.m_flDxDy <= v8->m_flDxDy) )
            break;
        }
        v12 = i->m_StartTerminal.m_pNextActiveEdge;
        v8->m_pNextActiveEdge = v12;
        v8->m_pPrevActiveEdge = &i->m_StartTerminal;
        v12->m_pPrevActiveEdge = v8;
        i->m_StartTerminal.m_pNextActiveEdge = v8;
      }
      v13 = ++this->m_nCurrentEdgeIndex;
      if ( v13 == m_Size )
        break;
      v8 = &this->m_WingedEdges.m_Memory.m_pMemory[v13];
      if ( flCurrY < v8->m_vecPosition.y )
        goto LABEL_21;
    }
  }
  return this->m_flNextDiscontinuity != 3.4028235e38;
}

//------------------------------------------------------------------------------
// Address: 0x100F23A0
// Name: private: bool CWingedEdgeList::IsOccludingActiveEdgeList(class CWingedEdgeList __near &,float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWingedEdgeList::IsOccludingActiveEdgeList(CWingedEdgeList *this, CWingedEdgeList *testList, float y)
{
  CWingedEdgeList *v3; // ebx
  CWingedEdgeList *m_pNextActiveEdge; // eax
  CWingedEdgeList *v6; // edi
  float m_flX; // xmm0_4
  CWingedEdgeList *m_pPrevActiveEdge; // eax
  CWingedEdgeList::WingedEdge_t *i; // eax
  __int16 m_nEnterSurfID; // dx
  CWingedEdgeList::Surface_t *p_m_BackSurface; // edx
  __int16 m_nLeaveSurfID; // si
  CWingedEdgeList::Surface_t *v13; // esi
  float v14; // xmm1_4
  float v15; // xmm2_4
  CWingedEdgeList::WingedEdge_t **p_m_pNextActiveEdge; // edi
  CWingedEdgeList::WingedEdge_t *v17; // edi
  __int16 v18; // ax
  float v19; // xmm0_4
  __int16 v20; // ax
  __int16 v21; // ax
  CWingedEdgeList::WingedEdge_t *pOccluderEdge; // [esp+4h] [ebp-4h]

  v3 = testList;
  m_pNextActiveEdge = (CWingedEdgeList *)testList->m_StartTerminal.m_pNextActiveEdge;
  if ( m_pNextActiveEdge->m_StartTerminal.m_flX >= 1.0 )
    return 1;
  for ( ;
        m_pNextActiveEdge->m_StartTerminal.m_flX <= -1.0;
        m_pNextActiveEdge = (CWingedEdgeList *)m_pNextActiveEdge->m_StartTerminal.m_pNextActiveEdge )
  {
    ;
  }
  v6 = m_pNextActiveEdge;
  if ( m_pNextActiveEdge == (CWingedEdgeList *)&testList->m_EndTerminal )
    return 1;
  m_flX = m_pNextActiveEdge->m_StartTerminal.m_flX;
  m_pPrevActiveEdge = (CWingedEdgeList *)m_pNextActiveEdge->m_StartTerminal.m_pPrevActiveEdge;
  if ( m_pPrevActiveEdge != testList )
  {
    v6 = m_pPrevActiveEdge;
    m_flX = -1.0;
  }
  for ( i = this->m_StartTerminal.m_pNextActiveEdge; m_flX >= i->m_flX; i = i->m_pNextActiveEdge )
    ;
  m_nEnterSurfID = v6->m_StartTerminal.m_nEnterSurfID;
  pOccluderEdge = i;
  if ( m_nEnterSurfID < 0 )
    p_m_BackSurface = &this->m_BackSurface;
  else
    p_m_BackSurface = &testList->m_Surfaces.m_Memory.m_pMemory[m_nEnterSurfID];
  m_nLeaveSurfID = i->m_nLeaveSurfID;
  if ( m_nLeaveSurfID < 0 )
  {
    v13 = &this->m_BackSurface;
  }
  else
  {
    v13 = &this->m_Surfaces.m_Memory.m_pMemory[m_nLeaveSurfID];
    v3 = testList;
  }
  v14 = i->m_flX;
  v15 = v6->m_StartTerminal.m_pNextActiveEdge->m_flX;
  p_m_pNextActiveEdge = &v6->m_StartTerminal.m_pNextActiveEdge;
  if ( (float)((float)(v13->m_Plane.dist - (float)(m_flX * v13->m_Plane.normal.x)) - (float)(v13->m_Plane.normal.y * y)) > (float)((float)(p_m_BackSurface->m_Plane.dist - (float)(p_m_BackSurface->m_Plane.normal.x * m_flX)) - (float)(p_m_BackSurface->m_Plane.normal.y * y)) )
    return 0;
  while ( v15 != 3.4028235e38 )
  {
    if ( v14 != 3.4028235e38 )
    {
      if ( v14 < v15 )
      {
        pOccluderEdge = pOccluderEdge->m_pNextActiveEdge;
        v21 = pOccluderEdge->m_nLeaveSurfID;
        v19 = v14;
        v13 = v21 < 0 ? &this->m_BackSurface : &this->m_Surfaces.m_Memory.m_pMemory[v21];
        v14 = pOccluderEdge->m_flX;
      }
      else
      {
        v17 = *p_m_pNextActiveEdge;
        v18 = v17->m_nEnterSurfID;
        v19 = v15;
        if ( v18 < 0 )
        {
          v20 = v17->m_nLeaveSurfID;
          if ( v20 < 0 )
          {
            v15 = v17->m_pNextActiveEdge->m_flX;
            p_m_pNextActiveEdge = &v17->m_pNextActiveEdge;
            p_m_BackSurface = &this->m_BackSurface;
          }
          else
          {
            p_m_pNextActiveEdge = &v17->m_pNextActiveEdge;
            p_m_BackSurface = &v3->m_Surfaces.m_Memory.m_pMemory[v20];
            v15 = (*p_m_pNextActiveEdge)->m_flX;
          }
        }
        else
        {
          p_m_pNextActiveEdge = &v17->m_pNextActiveEdge;
          p_m_BackSurface = &v3->m_Surfaces.m_Memory.m_pMemory[v18];
          v15 = (*p_m_pNextActiveEdge)->m_flX;
        }
      }
      if ( (float)((float)(v13->m_Plane.dist - (float)(v19 * v13->m_Plane.normal.x)) - (float)(v13->m_Plane.normal.y * y)) <= (float)((float)(p_m_BackSurface->m_Plane.dist - (float)(p_m_BackSurface->m_Plane.normal.x * v19)) - (float)(p_m_BackSurface->m_Plane.normal.y * y)) )
        continue;
    }
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100F25B0
// Name: public: bool CWingedEdgeList::IsOccludingEdgeList(class CWingedEdgeList __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWingedEdgeList::IsOccludingEdgeList(CWingedEdgeList *this, CWingedEdgeList *testList)
{
  CWingedEdgeList::WingedEdge_t *m_pMemory; // ecx
  float y; // xmm0_4
  float v6; // xmm0_4
  float v7; // xmm7_4
  CWingedEdgeList *v8; // ecx
  CWingedEdgeList *v9; // ecx
  char result; // al
  float m_flNextDiscontinuity; // [esp+10h] [ebp+8h]
  float v12; // [esp+10h] [ebp+8h]

  if ( testList->m_WingedEdges.m_Size == 0 )
    return 1;
  m_pMemory = testList->m_WingedEdges.m_Memory.m_pMemory;
  testList->m_nCurrentEdgeIndex = 0;
  y = m_pMemory->m_vecPosition.y;
  testList->m_flNextDiscontinuity = y;
  if ( y <= -1.0 )
    y = -1.0;
  testList->m_flNextDiscontinuity = y;
  testList->m_EndTerminal.m_pPrevActiveEdge = &testList->m_StartTerminal;
  testList->m_StartTerminal.m_pNextActiveEdge = &testList->m_EndTerminal;
  this->m_nCurrentEdgeIndex = 0;
  v6 = this->m_WingedEdges.m_Memory.m_pMemory->m_vecPosition.y;
  this->m_flNextDiscontinuity = v6;
  if ( v6 <= -1.0 )
    v6 = -1.0;
  this->m_flNextDiscontinuity = v6;
  this->m_StartTerminal.m_pNextActiveEdge = &this->m_EndTerminal;
  this->m_EndTerminal.m_pPrevActiveEdge = &this->m_StartTerminal;
  m_flNextDiscontinuity = testList->m_flNextDiscontinuity;
  v7 = m_flNextDiscontinuity;
  if ( v6 > m_flNextDiscontinuity )
    return 0;
  if ( m_flNextDiscontinuity >= 1.0 )
    return 1;
  CWingedEdgeList::AdvanceActiveEdgeList(this: testList, flCurrY: m_flNextDiscontinuity);
  CWingedEdgeList::AdvanceActiveEdgeList(this, flCurrY: m_flNextDiscontinuity);
  if ( CWingedEdgeList::IsOccludingActiveEdgeList(this: v8, testList, y: m_flNextDiscontinuity) != 0 )
  {
    while ( v7 < 1.0 )
    {
      v7 = this->m_flNextDiscontinuity;
      if ( v7 > testList->m_flNextDiscontinuity )
        v7 = testList->m_flNextDiscontinuity;
      v12 = v7;
      if ( v7 > 1.0 )
      {
        v7 = 1.0;
        v12 = 1.0;
      }
      if ( !CWingedEdgeList::AdvanceActiveEdgeList(this: testList, flCurrY: v12) )
        break;
      if ( !CWingedEdgeList::AdvanceActiveEdgeList(this, flCurrY: v12) )
        return 0;
      result = CWingedEdgeList::IsOccludingActiveEdgeList(this: v9, testList, y: v12);
      if ( result == 0 )
        return result;
    }
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100F26E0
// Name: private: void CEdgeList::IntroduceSingleActiveEdge(struct CEdgeList::Edge_t const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEdgeList::IntroduceSingleActiveEdge(CEdgeList *this, const CEdgeList::Edge_t *pEdge, float flCurrY)
{
  CEdgeList::Surface_t *v3; // edx
  CEdgeList::Surface_t *m_pNextSurface; // eax
  double v5; // st7
  float y; // xmm1_4
  CEdgeList::Surface_t *i; // ecx
  double v8; // st4
  double v9; // st7
  double v10; // rt1
  double v11; // st4
  float pEdgea; // [esp+Ch] [ebp+8h]

  v3 = &this->m_Surfaces.m_Memory.m_pMemory[pEdge->m_nSurfID];
  m_pNextSurface = v3->m_pNextSurface;
  if ( m_pNextSurface == nullptr )
  {
    v5 = -0.000001;
    y = v3->m_Plane.normal.y;
    pEdgea = (float)(v3->m_Plane.dist - (float)(pEdge->m_flX * v3->m_Plane.normal.x)) - (float)(y * flCurrY);
    v3->m_flOOz = pEdgea;
    for ( i = this->m_StartSurfTerminal.m_pNextSurface; ; i = i->m_pNextSurface )
    {
      v8 = v5;
      v9 = i->m_flOOz - pEdgea;
      if ( v8 >= v9 )
      {
        v5 = v8;
      }
      else
      {
        v10 = v8;
        v11 = v9;
        v5 = v10;
        if ( v11 >= 0.000001 || i->m_Plane.normal.y < y )
        {
          v3->m_pNextSurface = i;
          v3->m_pPrevSurface = i->m_pPrevSurface;
          i->m_pPrevSurface = v3;
          v3->m_pPrevSurface->m_pNextSurface = v3;
          return;
        }
      }
    }
  }
  m_pNextSurface->m_pPrevSurface = v3->m_pPrevSurface;
  v3->m_pPrevSurface->m_pNextSurface = v3->m_pNextSurface;
  v3->m_pNextSurface = nullptr;
  v3->m_pPrevSurface = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100F27B0
// Name: private: void CEdgeList::IntroduceNewActiveEdges(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEdgeList::IntroduceNewActiveEdges(CEdgeList *this, float y)
{
  int m_nCurrentEdgeIndex; // eax
  int m_Size; // edi
  CEdgeList::Edge_t *v4; // eax
  float v5; // xmm0_4
  CEdgeList::Edge_t *i; // edx
  float v7; // xmm0_4
  CEdgeList::Edge_t *m_pNextActiveEdge; // esi
  int v9; // eax
  float v10; // xmm0_4

  m_nCurrentEdgeIndex = this->m_nCurrentEdgeIndex;
  m_Size = this->m_SortIndices.m_Size;
  if ( m_nCurrentEdgeIndex != m_Size )
  {
    v4 = &this->m_Edges.m_Memory.m_pMemory[this->m_SortIndices.m_Memory.m_pMemory[m_nCurrentEdgeIndex]];
    if ( y < v4->m_vecPosition.y )
    {
LABEL_14:
      v10 = v4->m_vecPosition.y;
      if ( this->m_flNextDiscontinuity > v10 )
        this->m_flNextDiscontinuity = v10;
    }
    else
    {
      while ( 1 )
      {
        v5 = v4->m_vecPositionEnd.y;
        if ( v5 > y )
        {
          v4->m_flX = (float)((float)(y - v4->m_vecPosition.y) * v4->m_flDxDy) + v4->m_vecPosition.x;
          if ( this->m_flNextDiscontinuity > v5 )
            this->m_flNextDiscontinuity = v5;
          for ( i = this->m_EndTerminal.m_pPrevActiveEdge; i != &this->m_StartTerminal; i = i->m_pPrevActiveEdge )
          {
            v7 = i->m_flX - v4->m_flX;
            if ( v7 <= 0.0 && (v7 < 0.0 || i->m_flDxDy <= v4->m_flDxDy) )
              break;
          }
          m_pNextActiveEdge = i->m_pNextActiveEdge;
          v4->m_pNextActiveEdge = m_pNextActiveEdge;
          v4->m_pPrevActiveEdge = i;
          m_pNextActiveEdge->m_pPrevActiveEdge = v4;
          i->m_pNextActiveEdge = v4;
        }
        v9 = ++this->m_nCurrentEdgeIndex;
        if ( v9 == m_Size )
          break;
        v4 = &this->m_Edges.m_Memory.m_pMemory[this->m_SortIndices.m_Memory.m_pMemory[v9]];
        if ( y < v4->m_vecPosition.y )
          goto LABEL_14;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F28C0
// Name: public: int CUtlSortVector<unsigned short,class CEdgeList::EdgeLess>::FindLessOrEqual(unsigned short const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<unsigned short,CEdgeList::EdgeLess>::FindLessOrEqual(
        CUtlSortVector<unsigned short,CEdgeList::EdgeLess> *this,
        const unsigned __int16 *src)
{
  int v3; // edi
  int *m_pLessContext; // eax
  unsigned __int16 *m_pMemory; // ebx
  int v6; // edx
  float v7; // xmm1_4
  int result; // eax
  float v9; // xmm0_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  int v12; // edx
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  int *v17; // [esp+Ch] [ebp-8h]
  int start; // [esp+10h] [ebp-4h]

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1\\utlsortvector.h",
         277,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1\\utlsortvector.h",
                            a2: 277,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1\\utlsortvector.h",
      a2: 277);
  }
  v3 = this->m_Size - 1;
  start = 0;
  if ( v3 >= 0 )
  {
    m_pLessContext = (int *)this->m_pLessContext;
    m_pMemory = this->m_Memory.m_pMemory;
    v17 = m_pLessContext;
    do
    {
      v6 = *v17;
      v7 = *(float *)(*v17 + 48 * *src + 4);
      result = (v3 + start) >> 1;
      v9 = *(float *)(*v17 + 48 * m_pMemory[result] + 4);
      if ( v7 <= v9
        && (v9 > v7
         || (v10 = *(float *)(v6 + 48 * m_pMemory[result]), (v11 = *(float *)(v6 + 48 * *src)) <= v10)
         && (v10 > v11 || *(float *)(v6 + 48 * *src + 24) < *(float *)(v6 + 48 * m_pMemory[result] + 24))) )
      {
        v12 = *v17;
        v13 = *(float *)(*v17 + 48 * *src + 4);
        v14 = *(float *)(*v17 + 48 * m_pMemory[result] + 4);
        if ( v14 <= v13 )
        {
          if ( v13 > v14 )
            return result;
          v15 = *(float *)(v12 + 48 * *src);
          v16 = *(float *)(v12 + 48 * m_pMemory[result]);
          if ( v16 <= v15
            && (v15 > v16 || *(float *)(v12 + 48 * m_pMemory[result] + 24) < *(float *)(v12 + 48 * *src + 24)) )
          {
            return result;
          }
        }
        v3 = result - 1;
      }
      else
      {
        start = result + 1;
      }
    }
    while ( start <= v3 );
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100F2A00
// Name: void VisualizeQueuedEdges(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall VisualizeQueuedEdges(int a1@<ebx>, int a2@<edi>, int a3@<esi>)
{
  int v3; // edi
  IMesh *v4; // esi
  int v5; // ebx
  int v6; // ebx
  int v7; // esi
  float *v8; // esi
  float *m_pCurrPosition; // eax
  float *v10; // ecx
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+0h] [ebp-1F0h] BYREF
  IMesh *pMesh; // [esp+1E8h] [ebp-8h]
  int i; // [esp+1ECh] [ebp-4h]

  if ( g_EdgeVisualization.m_Size != 0 )
  {
    v3 = ((int (__thiscall *)(IMaterialSystem *, int, int, int))materials->GetRenderContext)(
           a1: materials,
           a2,
           a3,
           a4: a1);
    if ( v3 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 8))(a1: v3);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v3 + 80))(a1: v3, a2: 10);
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 84))(a1: v3);
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 124))(a1: v3);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v3 + 80))(a1: v3, a2: 0);
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 84))(a1: v3);
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 124))(a1: v3);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v3 + 80))(a1: v3, a2: 1);
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 84))(a1: v3);
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 124))(a1: v3);
    (*(void (__thiscall **)(int, IMaterial *, _DWORD))(*(_DWORD *)v3 + 36))(
      a1: v3,
      a2: g_pMaterialWireframeVertexColorIgnoreZ,
      a3: 0);
    v4 = (IMesh *)(*(int (__thiscall **)(int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v3 + 228))(
                    a1: v3,
                    a2: 1,
                    a3: 0,
                    a4: 0,
                    a5: 0);
    pMesh = v4;
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v4;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_LINES;
    v5 = 2 * g_EdgeVisualization.m_Size;
    v4->SetPrimitiveType(this: v4, a2: MATERIAL_LINES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: v5, a3: v5, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v4->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = v5;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v4, nMaxVertexCount: v5, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    v6 = g_EdgeVisualization.m_Size - 1;
    if ( g_EdgeVisualization.m_Size - 1 >= 0 )
    {
      v7 = 28 * v6;
      for ( i = 28 * v6; ; v7 = i )
      {
        v8 = (float *)((char *)g_EdgeVisualization.m_Memory.m_pMemory + v7);
        m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = *v8;
        m_pCurrPosition[1] = v8[1];
        m_pCurrPosition[2] = v8[2];
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = *((unsigned __int8 *)v8 + 26)
                                                            | ((*((unsigned __int8 *)v8 + 25)
                                                              | ((*((unsigned __int8 *)v8 + 24)
                                                                | (*((unsigned __int8 *)v8 + 27) << 8)) << 8)) << 8);
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        v10 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v8[3];
        v10[1] = v8[4];
        v10[2] = v8[5];
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = *((unsigned __int8 *)v8 + 26)
                                                            | ((*((unsigned __int8 *)v8 + 25)
                                                              | ((*((unsigned __int8 *)v8 + 24)
                                                                | (*((unsigned __int8 *)v8 + 27) << 8)) << 8)) << 8);
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        i -= 28;
        if ( --v6 < 0 )
          break;
      }
      v4 = pMesh;
    }
    if ( meshBuilder.m_bGenerateIndices )
    {
      switch ( meshBuilder.m_Type )
      {
        case MATERIAL_LINE_STRIP:
          m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
          break;
        case MATERIAL_LINE_LOOP:
          m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
        case MATERIAL_POLYGON:
          m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
          break;
        case MATERIAL_QUADS:
          m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
          break;
        case MATERIAL_INSTANCED_QUADS:
          m_nVertexCount = 0;
          break;
        default:
          m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
      }
      CIndexBuilder::GenerateIndices(
        this: &meshBuilder.m_IndexBuilder,
        primitiveType: meshBuilder.m_Type,
        nIndexCount: m_nVertexCount);
    }
    meshBuilder.m_pMesh->UnlockMesh(
      this: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
      a4: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    v4->Draw_2(this: v4, a2: -1, a3: 0);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v3 + 80))(a1: v3, a2: 10);
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 88))(a1: v3);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v3 + 80))(a1: v3, a2: 0);
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 88))(a1: v3);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v3 + 80))(a1: v3, a2: 1);
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 88))(a1: v3);
    g_EdgeVisualization.m_Size = 0;
    CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 12))(a1: v3);
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 4))(a1: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F2D70
// Name: public: virtual void COcclusionSystem::DrawDebugOverlays(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall COcclusionSystem::DrawDebugOverlays(COcclusionSystem *this)
{
  VisualizeQueuedEdges();
}

//------------------------------------------------------------------------------
// Address: 0x100F2D80
// Name: public: int CUtlSortVector<unsigned short,class CEdgeList::EdgeLess>::Insert(unsigned short const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<unsigned short,CEdgeList::EdgeLess>::Insert(
        CUtlSortVector<unsigned short,CEdgeList::EdgeLess> *this,
        const unsigned __int16 *src)
{
  int LessOrEqual; // eax
  int m_nAllocationCount; // ecx
  int v5; // edi
  int m_Size; // eax
  unsigned __int16 *m_pMemory; // ecx
  int v8; // eax
  unsigned __int16 *v9; // eax

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1\\utlsortvector.h",
         150,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1\\utlsortvector.h",
                            a2: 150,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1\\utlsortvector.h",
      a2: 150);
  }
  LessOrEqual = CUtlSortVector<unsigned short,CEdgeList::EdgeLess>::FindLessOrEqual(this, src);
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  v5 = LessOrEqual + 1;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<wchar_t,int>::Grow((CUtlMemory<wchar_t,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size - v5 - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[v5 + 1], src: &m_pMemory[v5], count: 2 * v8);
  v9 = &this->m_Memory.m_pMemory[v5];
  if ( v9 != nullptr )
    *v9 = *src;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x100F2E50
// Name: public: int CUtlSortVector<int,class WingedEdgeLessFunc>::Insert(int const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<int,WingedEdgeLessFunc>::Insert(
        CUtlSortVector<int,WingedEdgeLessFunc> *this,
        Vector *src)
{
  int LessOrEqual; // eax
  int m_nAllocationCount; // ecx
  int v5; // edi
  int m_Size; // eax
  int *m_pMemory; // ecx
  int v8; // eax
  int *v9; // eax

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1\\utlsortvector.h",
         150,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1\\utlsortvector.h",
                            a2: 150,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1\\utlsortvector.h",
      a2: 150);
  }
  LessOrEqual = CUtlSortVector<int,WingedEdgeLessFunc>::FindLessOrEqual(this, src);
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  v5 = LessOrEqual + 1;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<INetMessage *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size - v5 - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[v5 + 1], src: &m_pMemory[v5], count: 4 * v8);
  v9 = &this->m_Memory.m_pMemory[v5];
  if ( v9 != nullptr )
    *v9 = LODWORD(src->x);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x100F2FB0
// Name: public: CWingedEdgeList::CWingedEdgeList(void)
// Source: json
//------------------------------------------------------------------------------
CWingedEdgeList *__thiscall CWingedEdgeList::CWingedEdgeList(CWingedEdgeList *this)
{
  CWingedEdgeList::WingedEdge_t *v2; // eax

  this->m_WingedEdges.m_Memory.m_pMemory = nullptr;
  this->m_WingedEdges.m_Memory.m_nAllocationCount = 64;
  this->m_WingedEdges.m_Memory.m_nGrowSize = 0;
  v2 = (CWingedEdgeList::WingedEdge_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 3072);
  this->m_WingedEdges.m_Memory.m_pMemory = v2;
  this->m_WingedEdges.m_pElements = v2;
  this->m_WingedEdges.m_Size = 0;
  this->m_Surfaces.m_Memory.m_pMemory = nullptr;
  this->m_Surfaces.m_Memory.m_nAllocationCount = 0;
  this->m_Surfaces.m_Memory.m_nGrowSize = 0;
  this->m_Surfaces.m_Size = 0;
  this->m_Surfaces.m_pElements = nullptr;
  this->m_StartTerminal.m_vecPosition.x = -3.4028235e38;
  this->m_StartTerminal.m_vecPosition.y = -3.4028235e38;
  this->m_StartTerminal.m_vecPosition.z = -3.4028235e38;
  this->m_StartTerminal.m_vecPositionEnd.x = -3.4028235e38;
  this->m_StartTerminal.m_vecPositionEnd.z = -3.4028235e38;
  this->m_StartTerminal.m_vecPositionEnd.y = 3.4028235e38;
  this->m_StartTerminal.m_pPrevActiveEdge = nullptr;
  this->m_StartTerminal.m_pNextActiveEdge = nullptr;
  this->m_StartTerminal.m_flX = -3.4028235e38;
  this->m_StartTerminal.m_flDxDy = 0.0;
  this->m_StartTerminal.m_flOODy = 0.0;
  this->m_StartTerminal.m_nLeaveSurfID = -1;
  this->m_StartTerminal.m_nEnterSurfID = -1;
  this->m_EndTerminal.m_vecPosition.y = -3.4028235e38;
  this->m_EndTerminal.m_vecPosition.z = -3.4028235e38;
  this->m_EndTerminal.m_vecPosition.x = 3.4028235e38;
  this->m_EndTerminal.m_vecPositionEnd.z = -3.4028235e38;
  this->m_EndTerminal.m_vecPositionEnd.x = 3.4028235e38;
  this->m_EndTerminal.m_vecPositionEnd.y = 3.4028235e38;
  this->m_EndTerminal.m_nLeaveSurfID = -1;
  this->m_EndTerminal.m_pPrevActiveEdge = nullptr;
  this->m_EndTerminal.m_pNextActiveEdge = nullptr;
  this->m_EndTerminal.m_flDxDy = 0.0;
  this->m_EndTerminal.m_flOODy = 0.0;
  this->m_EndTerminal.m_flX = 3.4028235e38;
  this->m_EndTerminal.m_nEnterSurfID = -1;
  this->m_BackSurface.m_Plane.normal.x = 0.0;
  this->m_BackSurface.m_Plane.normal.y = 0.0;
  this->m_BackSurface.m_Plane.normal.z = 1.0;
  this->m_BackSurface.m_Plane.dist = 3.4028235e38;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100F30C0
// Name: public: COcclusionSystem::~COcclusionSystem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COcclusionSystem::~COcclusionSystem(COcclusionSystem *this)
{
  this->__vftable = (COcclusionSystem_vtbl *)&COcclusionSystem::`vftable';
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_ClippedVerts);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_WingedEdgeList.m_Surfaces);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_WingedEdgeList.m_WingedEdges);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_EdgeList.m_SurfaceSort);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_EdgeList.m_Surfaces);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_EdgeList.m_SortIndices);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_EdgeList.m_OrigSortIndices);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_EdgeList);
}

//------------------------------------------------------------------------------
// Address: 0x100F3190
// Name: public: int CWingedEdgeList::AddEdge(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWingedEdgeList::AddEdge(CWingedEdgeList *this)
{
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::AnimationController::AnimCommand_t,int> *p_m_WingedEdges; // esi
  int m_Size; // edi
  vgui::AnimationController::AnimCommand_t *m_pMemory; // ecx
  int v5; // eax
  int v6; // eax

  m_nAllocationCount = this->m_WingedEdges.m_Memory.m_nAllocationCount;
  p_m_WingedEdges = (CUtlMemory<vgui::AnimationController::AnimCommand_t,int> *)&this->m_WingedEdges;
  m_Size = this->m_WingedEdges.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CWingedEdgeList::WingedEdge_t,int>::Grow(this: p_m_WingedEdges, num: m_Size - m_nAllocationCount + 1);
  ++p_m_WingedEdges[1].m_pMemory;
  m_pMemory = p_m_WingedEdges->m_pMemory;
  v5 = (int)p_m_WingedEdges[1].m_pMemory - m_Size - 1;
  p_m_WingedEdges[1].m_nAllocationCount = (int)p_m_WingedEdges->m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 48 * v5);
  v6 = (int)&p_m_WingedEdges->m_pMemory[m_Size];
  *(_DWORD *)(v6 + 40) = 0;
  *(_DWORD *)(v6 + 44) = 0;
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x100F3200
// Name: public: int CWingedEdgeList::AddSurface(struct cplane_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWingedEdgeList::AddSurface(CWingedEdgeList *this, const cplane_t *plane)
{
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *p_m_Surfaces; // esi
  int m_Size; // edi
  vgui::CTreeViewListControl::CColumnInfo *m_pMemory; // ecx
  int v6; // eax

  m_nAllocationCount = this->m_Surfaces.m_Memory.m_nAllocationCount;
  p_m_Surfaces = (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)&this->m_Surfaces;
  m_Size = this->m_Surfaces.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<void *,int>,int>::Grow(this: p_m_Surfaces, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Surfaces[1].m_pMemory;
  m_pMemory = p_m_Surfaces->m_pMemory;
  v6 = (int)p_m_Surfaces[1].m_pMemory - m_Size - 1;
  p_m_Surfaces[1].m_nAllocationCount = (int)p_m_Surfaces->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 20 * v6);
  p_m_Surfaces->m_pMemory[m_Size] = (vgui::CTreeViewListControl::CColumnInfo)*plane;
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x100F32A0
// Name: public: void CWingedEdgeList::QueueVisualization(unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWingedEdgeList::QueueVisualization(CWingedEdgeList *this, unsigned __int8 *pColor)
{
  int inserted; // eax
  int v4; // edx
  int v5; // esi
  int v7; // eax
  int v8; // esi
  CWingedEdgeList::WingedEdge_t *m_pMemory; // ecx
  EdgeVisualizationInfo_t *v10; // edx
  float *p_x; // ecx
  EdgeVisualizationInfo_t *v12; // edx
  CWingedEdgeList::WingedEdge_t *v13; // edx
  EdgeVisualizationInfo_t *v14; // ecx
  float *v15; // edx
  int v16; // ecx
  CWingedEdgeList::WingedEdge_t *v17; // ecx
  double x; // st7
  float *v19; // edx
  EdgeVisualizationInfo_t *v20; // ecx
  int v21; // ecx
  CWingedEdgeList::WingedEdge_t *v22; // ecx
  double v23; // st7
  float *v24; // ecx
  EdgeVisualizationInfo_t *v25; // edx
  int v26; // edx
  bool v27; // zf
  int v28; // ecx
  int v29; // esi
  CWingedEdgeList::WingedEdge_t *v30; // eax
  double v31; // st7
  float *v32; // eax
  EdgeVisualizationInfo_t *v33; // ecx
  EdgeVisualizationInfo_t *v34; // ecx
  int nFirst; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]
  int ia; // [esp+8h] [ebp-4h]
  unsigned __int8 *pColora; // [esp+14h] [ebp+8h]
  unsigned __int8 *pColorb; // [esp+14h] [ebp+8h]

  if ( r_visocclusion.m_pParent != nullptr && r_visocclusion.m_pParent->m_Value.m_nValue != 0 )
  {
    inserted = CUtlVector<EdgeVisualizationInfo_t,CUtlMemory<EdgeVisualizationInfo_t,int>>::InsertMultipleBefore(
                 this: &g_EdgeVisualization,
                 elem: g_EdgeVisualization.m_Size,
                 num: this->m_WingedEdges.m_Size);
    v4 = this->m_WingedEdges.m_Size - 1;
    v5 = inserted;
    nFirst = inserted;
    if ( v4 >= 0 )
    {
      i = this->m_WingedEdges.m_Size;
      if ( i >= 4 )
      {
        pColora = (unsigned __int8 *)((unsigned int)i >> 2);
        v7 = v4;
        v8 = v4 + v5;
        ia = v4 - 4 * ((unsigned int)i >> 2);
        do
        {
          m_pMemory = this->m_WingedEdges.m_Memory.m_pMemory;
          v10 = g_EdgeVisualization.m_Memory.m_pMemory;
          g_EdgeVisualization.m_Memory.m_pMemory[v8].m_vecPoint[0].x = m_pMemory[v7].m_vecPosition.x;
          p_x = &m_pMemory[v7].m_vecPosition.x;
          v12 = &v10[v8];
          v12->m_vecPoint[0].y = p_x[1];
          v12->m_vecPoint[0].z = p_x[2];
          v12->m_vecPoint[1].x = p_x[3];
          v12->m_vecPoint[1].y = p_x[4];
          v12->m_vecPoint[1].z = p_x[5];
          *(_DWORD *)v12->m_pColor = *(_DWORD *)pColor;
          v13 = this->m_WingedEdges.m_Memory.m_pMemory;
          v14 = g_EdgeVisualization.m_Memory.m_pMemory;
          g_EdgeVisualization.m_Memory.m_pMemory[v8 - 1].m_vecPoint[0].x = v13[v7 - 1].m_vecPosition.x;
          v15 = &v13[v7 - 1].m_vecPosition.x;
          v16 = (int)&v14[v8 - 1];
          *(float *)(v16 + 4) = v15[1];
          *(float *)(v16 + 8) = v15[2];
          *(float *)(v16 + 12) = v15[3];
          *(float *)(v16 + 16) = v15[4];
          *(float *)(v16 + 20) = v15[5];
          *(_DWORD *)(v16 + 24) = *(_DWORD *)pColor;
          v17 = this->m_WingedEdges.m_Memory.m_pMemory;
          x = v17[v7 - 2].m_vecPosition.x;
          v19 = &v17[v7 - 2].m_vecPosition.x;
          v20 = g_EdgeVisualization.m_Memory.m_pMemory;
          g_EdgeVisualization.m_Memory.m_pMemory[v8 - 2].m_vecPoint[0].x = x;
          v21 = (int)&v20[v8 - 2];
          *(float *)(v21 + 4) = v19[1];
          *(float *)(v21 + 8) = v19[2];
          *(float *)(v21 + 12) = v19[3];
          *(float *)(v21 + 16) = v19[4];
          *(float *)(v21 + 20) = v19[5];
          *(_DWORD *)(v21 + 24) = *(_DWORD *)pColor;
          v22 = this->m_WingedEdges.m_Memory.m_pMemory;
          v23 = v22[v7 - 3].m_vecPosition.x;
          v24 = &v22[v7 - 3].m_vecPosition.x;
          v25 = g_EdgeVisualization.m_Memory.m_pMemory;
          g_EdgeVisualization.m_Memory.m_pMemory[v8 - 3].m_vecPoint[0].x = v23;
          v26 = (int)&v25[v8 - 3];
          *(float *)(v26 + 4) = v24[1];
          v8 -= 4;
          v7 -= 4;
          v27 = pColora-- == (unsigned __int8 *)1;
          *(float *)(v26 + 8) = v24[2];
          *(float *)(v26 + 12) = v24[3];
          *(float *)(v26 + 16) = v24[4];
          *(float *)(v26 + 20) = v24[5];
          *(_DWORD *)(v26 + 24) = *(_DWORD *)pColor;
        }
        while ( !v27 );
        v4 = ia;
        v5 = nFirst;
      }
      if ( v4 >= 0 )
      {
        v28 = 48 * v4;
        pColorb = (unsigned __int8 *)(48 * v4);
        v29 = v4 + v5;
        do
        {
          v30 = this->m_WingedEdges.m_Memory.m_pMemory;
          v31 = *(float *)((char *)&v30->m_vecPosition.x + v28);
          v32 = (float *)((char *)&v30->m_vecPosition.x + v28);
          v33 = g_EdgeVisualization.m_Memory.m_pMemory;
          g_EdgeVisualization.m_Memory.m_pMemory[v29].m_vecPoint[0].x = v31;
          v34 = &v33[v29];
          v34->m_vecPoint[0].y = v32[1];
          --v29;
          v34->m_vecPoint[0].z = v32[2];
          v34->m_vecPoint[1].x = v32[3];
          v34->m_vecPoint[1].y = v32[4];
          v34->m_vecPoint[1].z = v32[5];
          *(_DWORD *)v34->m_pColor = *(_DWORD *)pColor;
          v28 = (int)(pColorb - 48);
          --v4;
          pColorb -= 48;
        }
        while ( v4 >= 0 );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F34A0
// Name: public: CEdgeList::CEdgeList(void)
// Source: json
//------------------------------------------------------------------------------
CEdgeList *__thiscall CEdgeList::CEdgeList(CEdgeList *this)
{
  CEdgeList::Edge_t *v2; // eax
  unsigned __int16 *v3; // eax

  this->m_Edges.m_Memory.m_pMemory = nullptr;
  this->m_Edges.m_Memory.m_nAllocationCount = 32;
  this->m_Edges.m_Memory.m_nGrowSize = 0;
  v2 = (CEdgeList::Edge_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 1536);
  this->m_Edges.m_Memory.m_pMemory = v2;
  this->m_Edges.m_pElements = v2;
  this->m_Edges.m_Size = 0;
  this->m_OrigSortIndices.m_Memory.m_pMemory = nullptr;
  this->m_OrigSortIndices.m_Memory.m_nAllocationCount = 32;
  this->m_OrigSortIndices.m_Memory.m_nGrowSize = 0;
  v3 = (unsigned __int16 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 64);
  this->m_OrigSortIndices.m_Memory.m_pMemory = v3;
  this->m_OrigSortIndices.m_pElements = v3;
  this->m_OrigSortIndices.m_Size = 0;
  this->m_OrigSortIndices.m_bNeedsSort = false;
  this->m_SortIndices.m_Memory.m_pMemory = nullptr;
  this->m_SortIndices.m_Memory.m_nAllocationCount = 0;
  this->m_SortIndices.m_Memory.m_nGrowSize = 0;
  this->m_SortIndices.m_Size = 0;
  this->m_SortIndices.m_pElements = nullptr;
  this->m_Surfaces.m_Memory.m_pMemory = nullptr;
  this->m_Surfaces.m_Memory.m_nAllocationCount = 0;
  this->m_Surfaces.m_Memory.m_nGrowSize = 0;
  this->m_Surfaces.m_Size = 0;
  this->m_Surfaces.m_pElements = nullptr;
  this->m_SurfaceSort.m_Memory.m_pMemory = nullptr;
  this->m_SurfaceSort.m_Memory.m_nAllocationCount = 0;
  this->m_SurfaceSort.m_Memory.m_nGrowSize = 0;
  this->m_SurfaceSort.m_Size = 0;
  this->m_SurfaceSort.m_pElements = nullptr;
  this->m_OrigSortIndices.m_pLessContext = this;
  this->m_StartTerminal.m_vecPosition.x = -3.4028235e38;
  this->m_StartTerminal.m_vecPosition.y = -3.4028235e38;
  this->m_StartTerminal.m_vecPosition.z = -3.4028235e38;
  this->m_StartTerminal.m_vecPositionEnd.x = -3.4028235e38;
  this->m_StartTerminal.m_vecPositionEnd.y = 3.4028235e38;
  this->m_StartTerminal.m_vecPositionEnd.z = -3.4028235e38;
  this->m_StartTerminal.m_pPrevActiveEdge = nullptr;
  this->m_StartTerminal.m_pNextActiveEdge = nullptr;
  this->m_StartTerminal.m_flDxDy = 0.0;
  this->m_StartTerminal.m_flOODy = 0.0;
  this->m_StartTerminal.m_flX = -3.4028235e38;
  this->m_StartTerminal.m_nSurfID = -1;
  this->m_EndTerminal.m_vecPosition.x = 3.4028235e38;
  this->m_EndTerminal.m_vecPosition.y = -3.4028235e38;
  this->m_EndTerminal.m_vecPosition.z = -3.4028235e38;
  this->m_EndTerminal.m_vecPositionEnd.x = 3.4028235e38;
  this->m_EndTerminal.m_vecPositionEnd.y = 3.4028235e38;
  this->m_EndTerminal.m_vecPositionEnd.z = -3.4028235e38;
  this->m_EndTerminal.m_nSurfID = -1;
  this->m_EndTerminal.m_pPrevActiveEdge = nullptr;
  this->m_EndTerminal.m_pNextActiveEdge = nullptr;
  this->m_EndTerminal.m_flDxDy = 0.0;
  this->m_EndTerminal.m_flOODy = 0.0;
  this->m_EndTerminal.m_flX = 3.4028235e38;
  this->m_StartSurfTerminal.m_flOOz = -3.4028235e38;
  this->m_StartSurfTerminal.m_Plane.normal.x = 0.0;
  this->m_StartSurfTerminal.m_Plane.normal.y = 0.0;
  this->m_StartSurfTerminal.m_Plane.normal.z = 1.0;
  this->m_StartSurfTerminal.m_Plane.dist = -3.4028235e38;
  this->m_StartSurfTerminal.m_nSurfID = -1;
  this->m_StartSurfTerminal.m_pNextSurface = nullptr;
  this->m_StartSurfTerminal.m_pPrevSurface = nullptr;
  this->m_EndSurfTerminal.m_flOOz = 3.4028235e38;
  this->m_EndSurfTerminal.m_Plane.normal.x = 0.0;
  this->m_EndSurfTerminal.m_Plane.normal.y = 0.0;
  this->m_EndSurfTerminal.m_Plane.normal.z = 1.0;
  this->m_EndSurfTerminal.m_nSurfID = -1;
  this->m_EndSurfTerminal.m_pNextSurface = nullptr;
  this->m_EndSurfTerminal.m_pPrevSurface = nullptr;
  this->m_EndSurfTerminal.m_Plane.dist = 3.4028235e38;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100F3670
// Name: public: int CEdgeList::AddSurface(struct cplane_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEdgeList::AddSurface(CEdgeList *this, const cplane_t *plane)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CEdgeList::Surface_t *m_pMemory; // ecx
  int v6; // eax
  CEdgeList::Surface_t *v7; // eax
  CUtlMemory<S3RGBA,int> *p_m_SurfaceSort; // esi
  int v9; // ebx
  int v10; // eax
  S3RGBA *v11; // ecx
  int v12; // eax
  int *v13; // ebx
  int result; // eax

  m_nAllocationCount = this->m_Surfaces.m_Memory.m_nAllocationCount;
  m_Size = this->m_Surfaces.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CEdgeList::Surface_t,int>::Grow(this: &this->m_Surfaces.m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Surfaces.m_Size;
  m_pMemory = this->m_Surfaces.m_Memory.m_pMemory;
  v6 = this->m_Surfaces.m_Size - m_Size - 1;
  this->m_Surfaces.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 40 * v6);
  v7 = &this->m_Surfaces.m_Memory.m_pMemory[m_Size];
  v7->m_flOOz = 0.0;
  v7->m_Plane = *plane;
  p_m_SurfaceSort = (CUtlMemory<S3RGBA,int> *)&this->m_SurfaceSort;
  v7->m_pNextSurface = nullptr;
  v7->m_pPrevSurface = nullptr;
  v7->m_nSurfID = m_Size;
  v9 = this->m_SurfaceSort.m_Size;
  v10 = p_m_SurfaceSort->m_nAllocationCount;
  if ( v9 + 1 > v10 )
    CUtlMemory<INetMessage *,int>::Grow(this: p_m_SurfaceSort, num: v9 - v10 + 1);
  ++p_m_SurfaceSort[1].m_pMemory;
  v11 = p_m_SurfaceSort->m_pMemory;
  v12 = (int)p_m_SurfaceSort[1].m_pMemory - v9 - 1;
  p_m_SurfaceSort[1].m_nAllocationCount = (int)p_m_SurfaceSort->m_pMemory;
  if ( v12 > 0 )
    _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
  v13 = (int *)&p_m_SurfaceSort->m_pMemory[v9];
  result = m_Size;
  if ( v13 != nullptr )
    *v13 = m_Size;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F3790
// Name: public: void CEdgeList::AddEdge(class Vector __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEdgeList::AddEdge(CEdgeList *this, float ppEdgeVertices, int nSurfID)
{
  unsigned int v4; // ecx
  Vector *v5; // esi
  Vector *v6; // edi
  int v7; // eax
  int v8; // edx
  CEdgeList::Edge_t *v9; // ecx

  v4 = 4
     * (*(float *)(*(_DWORD *)LODWORD(ppEdgeVertices) + 4) >= *(float *)(*(_DWORD *)(LODWORD(ppEdgeVertices) + 4) + 4));
  v5 = *(Vector **)(v4 + LODWORD(ppEdgeVertices));
  v6 = *(Vector **)(LODWORD(ppEdgeVertices) - v4 + 4);
  ppEdgeVertices = v6->y - v5->y;
  if ( ppEdgeVertices != 0.0 )
  {
    v7 = CUtlVector<CEdgeList::Edge_t,CUtlMemory<CEdgeList::Edge_t,int>>::AddToTail(this: &this->m_Edges);
    v8 = nSurfID;
    v9 = &this->m_Edges.m_Memory.m_pMemory[v7];
    v9->m_flOODy = 1.0 / ppEdgeVertices;
    LODWORD(ppEdgeVertices) = (unsigned __int16)v7;
    v9->m_vecPosition.x = v5->x;
    v9->m_vecPosition.y = v5->y;
    v9->m_vecPosition.z = v5->z;
    v9->m_vecPositionEnd.x = v6->x;
    v9->m_vecPositionEnd.y = v6->y;
    v9->m_vecPositionEnd.z = v6->z;
    v9->m_nSurfID = v8;
    v9->m_flDxDy = (float)(v6->x - v5->x) * v9->m_flOODy;
    v9->m_pPrevActiveEdge = nullptr;
    v9->m_pNextActiveEdge = nullptr;
    CUtlSortVector<unsigned short,CEdgeList::EdgeLess>::Insert(
      this: &this->m_OrigSortIndices,
      src: (const unsigned __int16 *)&ppEdgeVertices);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F3860
// Name: public: void CEdgeList::CullSmallOccluders(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEdgeList::CullSmallOccluders(CEdgeList *this)
{
  CEdgeList *v1; // edi
  int m_Size; // esi
  void *v3; // esp
  int v4; // xmm0_4
  int v5; // edx
  CEdgeList::Surface_t *v6; // esi
  int *v7; // eax
  _DWORD *v8; // eax
  int v9; // ecx
  int v10; // ecx
  CEdgeList::Surface_t *v11; // ecx
  int v12; // eax
  int v13; // eax
  CUtlMemory<wchar_t,int> *p_m_SortIndices; // esi
  IMemAlloc_vtbl *v15; // edx
  int v16; // eax
  int v17; // ecx
  CEdgeList::Edge_t *v18; // edx
  wchar_t *v19; // edi
  int m_nAllocationCount; // eax
  wchar_t *v21; // ecx
  int v22; // eax
  wchar_t *v23; // edi
  int *m_pMemory; // [esp-10h] [ebp-34h]
  int v25; // [esp-4h] [ebp-28h]
  unsigned __int8 v26[12]; // [esp+0h] [ebp-24h] BYREF
  int nEdgeIndex; // [esp+Ch] [ebp-18h]
  int i; // [esp+10h] [ebp-14h]
  CEdgeList::Surface_t *v29; // [esp+14h] [ebp-10h]
  int nEdgeCount; // [esp+18h] [ebp-Ch]
  CEdgeList *v31; // [esp+1Ch] [ebp-8h]
  int nMinSurfaces; // [esp+20h] [ebp-4h]

  v1 = this;
  m_Size = this->m_Surfaces.m_Size;
  CEdgeList::s_pSortSurfaces = this->m_Surfaces.m_Memory.m_pMemory;
  m_pMemory = this->m_SurfaceSort.m_Memory.m_pMemory;
  v31 = this;
  nEdgeIndex = m_Size;
  qsort(
    base: m_pMemory,
    num: m_Size,
    width: 4u,
    comp: (int (__cdecl *)(const void *, const void *))CEdgeList::SurfCompare);
  if ( r_occludermincount.m_pParent != nullptr )
    nMinSurfaces = r_occludermincount.m_pParent->m_Value.m_nValue;
  else
    nMinSurfaces = 0;
  *(float *)&i = r_occluderminarea.m_pParent->m_Value.m_fValue * 0.02;
  if ( *(float *)&i == 0.0 )
    *(float *)&i = ((double (__thiscall *)(COcclusionSystem *))g_OcclusionSystem.MinOccluderArea)(a1: &g_OcclusionSystem)
                 * 0.02;
  v3 = alloca(m_Size);
  memset(dst: v26, value: 0, count: m_Size);
  v4 = i;
  v5 = 0;
  if ( m_Size < 4 )
  {
LABEL_20:
    if ( v5 < m_Size )
    {
      v11 = v1->m_Surfaces.m_Memory.m_pMemory;
      i = (int)&v1->m_SurfaceSort.m_Memory.m_pMemory[v5];
      do
      {
        v12 = *(_DWORD *)i;
        if ( *(float *)&v4 > v11[*(_DWORD *)i].m_flArea && v5 >= nMinSurfaces )
          break;
        i += 4;
        ++v5;
        v26[v12] = 1;
      }
      while ( v5 < m_Size );
LABEL_25:
      v1 = v31;
    }
  }
  else
  {
    v6 = v1->m_Surfaces.m_Memory.m_pMemory;
    v7 = v1->m_SurfaceSort.m_Memory.m_pMemory;
    v29 = v6;
    nEdgeCount = 2;
    v8 = v7 + 2;
    while ( *(float *)&v4 <= v6[*(v8 - 2)].m_flArea || v5 < nMinSurfaces )
    {
      v26[*(v8 - 2)] = 1;
      v9 = *(v8 - 1);
      if ( *(float *)&v4 > v6[v9].m_flArea )
      {
        if ( nEdgeCount - 1 >= nMinSurfaces )
          goto LABEL_25;
        v6 = v29;
      }
      v26[v9] = 1;
      if ( *(float *)&v4 > v6[*v8].m_flArea )
      {
        if ( nEdgeCount >= nMinSurfaces )
          goto LABEL_25;
        v6 = v29;
      }
      v26[*v8] = 1;
      v10 = v8[1];
      if ( *(float *)&v4 > v6[v10].m_flArea && nEdgeCount + 1 >= nMinSurfaces )
        goto LABEL_25;
      m_Size = nEdgeIndex;
      nEdgeCount += 4;
      v1 = v31;
      v26[v10] = 1;
      v5 += 4;
      v8 += 4;
      if ( v5 >= m_Size - 3 )
        goto LABEL_20;
      v6 = v29;
    }
  }
  v13 = v1->m_OrigSortIndices.m_Size;
  p_m_SortIndices = (CUtlMemory<wchar_t,int> *)&v1->m_SortIndices;
  v1->m_SortIndices.m_Size = 0;
  nEdgeCount = v13;
  if ( v1->m_SortIndices.m_Memory.m_nAllocationCount < v13 && v1->m_SortIndices.m_Memory.m_nGrowSize >= 0 )
  {
    v1->m_SortIndices.m_Memory.m_nAllocationCount = v13;
    v15 = _g_pMemAlloc->__vftable;
    v25 = 2 * v13;
    if ( p_m_SortIndices->m_pMemory != nullptr )
      v16 = ((int (__stdcall *)(wchar_t *, int))v15->Realloc_2)(a1: p_m_SortIndices->m_pMemory, a2: v25);
    else
      v16 = ((int (__stdcall *)(int))v15->Alloc_2)(a1: v25);
    p_m_SortIndices->m_pMemory = (wchar_t *)v16;
    v13 = nEdgeCount;
  }
  v1->m_SortIndices.m_pElements = v1->m_SortIndices.m_Memory.m_pMemory;
  v17 = 0;
  for ( *(float *)&i = 0.0; v17 < v13; i = v17 )
  {
    v18 = v1->m_Edges.m_Memory.m_pMemory;
    nEdgeIndex = v1->m_OrigSortIndices.m_Memory.m_pMemory[v17];
    if ( v26[v18[nEdgeIndex].m_nSurfID] != 0 )
    {
      v19 = p_m_SortIndices[1].m_pMemory;
      m_nAllocationCount = p_m_SortIndices->m_nAllocationCount;
      if ( (int)v19 + 1 > m_nAllocationCount )
        CUtlMemory<wchar_t,int>::Grow(this: p_m_SortIndices, num: (int)v19 - m_nAllocationCount + 1);
      ++p_m_SortIndices[1].m_pMemory;
      v21 = p_m_SortIndices->m_pMemory;
      v22 = (char *)p_m_SortIndices[1].m_pMemory - (char *)v19 - 1;
      p_m_SortIndices[1].m_nAllocationCount = (int)p_m_SortIndices->m_pMemory;
      if ( v22 > 0 )
        _V_memmove(dest: &v21[(_DWORD)v19 + 1], src: &v21[(_DWORD)v19], count: 2 * v22);
      v23 = &p_m_SortIndices->m_pMemory[(_DWORD)v19];
      v13 = nEdgeCount;
      if ( v23 != nullptr )
        *v23 = nEdgeIndex;
      v1 = v31;
    }
    v17 = i + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F3AE0
// Name: private: void CEdgeList::ReduceActiveEdgeList(class CWingedEdgeList __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEdgeList::ReduceActiveEdgeList(
        CEdgeList *this,
        CWingedEdgeList *wingedEdgeList,
        float flMinY,
        float flMaxY)
{
  CEdgeList::Edge_t *m_pNextActiveEdge; // esi
  float m_flX; // xmm1_4
  int v7; // ebx
  float v8; // xmm3_4
  float v9; // xmm4_4
  float v10; // xmm0_4
  CEdgeList::Surface_t *i; // eax
  CEdgeList::Edge_t *v12; // ecx
  int m_nSurfID; // eax
  int v14; // edx
  __int16 *p_m_nWingedEdge; // eax
  CWingedEdgeList::WingedEdge_t *v16; // ecx
  const CEdgeList::Edge_t *m_pEdge; // eax
  float v18; // xmm2_4
  int v19; // eax
  CEdgeList::ReduceInfo_t *v20; // ecx
  int v21; // eax
  CWingedEdgeList::WingedEdge_t *m_pMemory; // ecx
  int v23; // ebx
  float *p_x; // ecx
  float v25; // xmm1_4
  float v26; // xmm1_4
  __int16 v27; // dx
  CWingedEdgeList::WingedEdge_t *v28; // eax
  bool v29; // zf
  float *v30; // ebx
  int m_nNewReduceCount; // eax
  CEdgeList::ReduceInfo_t *v32; // ecx
  float v33; // [esp+14h] [ebp-18h]
  __int16 *flPrevX; // [esp+18h] [ebp-14h]
  int v35; // [esp+1Ch] [ebp-10h]
  int nEnterSurfID; // [esp+20h] [ebp-Ch]
  int pNextEdge; // [esp+24h] [ebp-8h]
  int nEdgeSurfID; // [esp+28h] [ebp-4h]

  m_pNextActiveEdge = this->m_StartTerminal.m_pNextActiveEdge;
  m_flX = m_pNextActiveEdge->m_flX;
  v7 = -1;
  nEdgeSurfID = -1;
  if ( m_pNextActiveEdge == &this->m_EndTerminal )
    return;
  v8 = flMaxY;
  v9 = flMinY;
  do
  {
    v10 = m_pNextActiveEdge->m_flX;
    if ( v10 != m_flX )
    {
      for ( i = this->m_StartSurfTerminal.m_pNextSurface; i != &this->m_EndSurfTerminal; i = i->m_pNextSurface )
        i->m_flOOz = (float)(i->m_Plane.dist - (float)(i->m_Plane.normal.x * v10)) - (float)(i->m_Plane.normal.y * v9);
    }
    CEdgeList::IntroduceSingleActiveEdge(this, pEdge: m_pNextActiveEdge, flCurrY: flMinY);
    m_flX = m_pNextActiveEdge->m_flX;
    v12 = m_pNextActiveEdge->m_pNextActiveEdge;
    v33 = m_flX;
    nEnterSurfID = (int)v12;
    if ( m_flX == v12->m_flX && m_pNextActiveEdge->m_flDxDy == v12->m_flDxDy )
      goto LABEL_30;
    m_nSurfID = this->m_StartSurfTerminal.m_pNextSurface->m_nSurfID;
    v35 = m_nSurfID;
    if ( v7 == m_nSurfID )
      goto LABEL_30;
    pNextEdge = this->m_StartSurfTerminal.m_pNextSurface->m_nSurfID;
    if ( m_nSurfID == -1 )
      pNextEdge = v7;
    v14 = this->m_nPrevReduceCount - 1;
    if ( v14 < 0 )
    {
LABEL_23:
      v21 = CWingedEdgeList::AddEdge(this: wingedEdgeList);
      m_pMemory = wingedEdgeList->m_WingedEdges.m_Memory.m_pMemory;
      v9 = flMinY;
      v8 = flMaxY;
      v23 = v21;
      m_pMemory[v23].m_nLeaveSurfID = nEdgeSurfID;
      m_pMemory[v23].m_nEnterSurfID = v35;
      m_pMemory[v23].m_flDxDy = m_pNextActiveEdge->m_flDxDy;
      p_x = &m_pMemory[v21].m_vecPosition.x;
      v25 = (float)((float)((float)(flMinY - m_pNextActiveEdge->m_vecPosition.y) * m_pNextActiveEdge->m_flOODy)
                  * (float)(m_pNextActiveEdge->m_vecPositionEnd.x - m_pNextActiveEdge->m_vecPosition.x))
          + m_pNextActiveEdge->m_vecPosition.x;
      *p_x = v25;
      p_x[1] = flMinY;
      p_x[2] = (float)(this->m_Surfaces.m_Memory.m_pMemory[pNextEdge].m_Plane.dist
                     - (float)(this->m_Surfaces.m_Memory.m_pMemory[pNextEdge].m_Plane.normal.x * v25))
             - (float)(this->m_Surfaces.m_Memory.m_pMemory[pNextEdge].m_Plane.normal.y * flMinY);
      v26 = (float)((float)((float)(flMaxY - m_pNextActiveEdge->m_vecPosition.y) * m_pNextActiveEdge->m_flOODy)
                  * (float)(m_pNextActiveEdge->m_vecPositionEnd.x - m_pNextActiveEdge->m_vecPosition.x))
          + m_pNextActiveEdge->m_vecPosition.x;
      p_x[3] = v26;
      p_x[4] = flMaxY;
      v27 = v21;
      p_x[5] = (float)(this->m_Surfaces.m_Memory.m_pMemory[pNextEdge].m_Plane.dist
                     - (float)(this->m_Surfaces.m_Memory.m_pMemory[pNextEdge].m_Plane.normal.x * v26))
             - (float)(this->m_Surfaces.m_Memory.m_pMemory[pNextEdge].m_Plane.normal.y * flMaxY);
      if ( v21 != 0 )
      {
        v28 = wingedEdgeList->m_WingedEdges.m_Memory.m_pMemory;
        v29 = p_x[1] == v28[v23 - 1].m_vecPosition.y;
        v30 = &v28[v23 - 1].m_vecPosition.x;
        if ( v29 && *v30 > *p_x )
          *p_x = *v30;
      }
      m_flX = v33;
      if ( m_pNextActiveEdge->m_vecPositionEnd.y > flMaxY )
      {
        m_nNewReduceCount = this->m_nNewReduceCount;
        v32 = &this->m_pNewReduceInfo[m_nNewReduceCount];
        this->m_nNewReduceCount = m_nNewReduceCount + 1;
        v32->m_pEdge = m_pNextActiveEdge;
        v32->m_nWingedEdge = v27;
      }
      goto LABEL_29;
    }
    p_m_nWingedEdge = &this->m_pPrevReduceInfo[v14].m_nWingedEdge;
    flPrevX = p_m_nWingedEdge;
    while ( 1 )
    {
      v16 = &wingedEdgeList->m_WingedEdges.m_Memory.m_pMemory[*p_m_nWingedEdge];
      if ( v16->m_nLeaveSurfID == v7 )
        break;
LABEL_18:
      p_m_nWingedEdge = flPrevX - 4;
      --v14;
      flPrevX -= 4;
      if ( v14 < 0 )
        goto LABEL_23;
    }
    if ( v16->m_nEnterSurfID != v35
      || v16->m_flDxDy != m_pNextActiveEdge->m_flDxDy
      || fabs(v16->m_vecPositionEnd.x - m_pNextActiveEdge->m_flX) >= 0.001 )
    {
      v7 = nEdgeSurfID;
      goto LABEL_18;
    }
    m_pEdge = this->m_pPrevReduceInfo[v14].m_pEdge;
    v18 = (float)((float)((float)(v8 - m_pEdge->m_vecPosition.y) * m_pEdge->m_flOODy)
                * (float)(m_pEdge->m_vecPositionEnd.x - m_pEdge->m_vecPosition.x))
        + m_pEdge->m_vecPosition.x;
    v16->m_vecPositionEnd.x = v18;
    v16->m_vecPositionEnd.y = v8;
    v16->m_vecPositionEnd.z = (float)(this->m_Surfaces.m_Memory.m_pMemory[pNextEdge].m_Plane.dist
                                    - (float)(v18 * this->m_Surfaces.m_Memory.m_pMemory[pNextEdge].m_Plane.normal.x))
                            - (float)(this->m_Surfaces.m_Memory.m_pMemory[pNextEdge].m_Plane.normal.y * v8);
    if ( m_pNextActiveEdge->m_vecPositionEnd.y > v8 )
    {
      v19 = this->m_nNewReduceCount;
      v20 = &this->m_pNewReduceInfo[v19];
      this->m_nNewReduceCount = v19 + 1;
      v20->m_pEdge = this->m_pPrevReduceInfo[v14].m_pEdge;
      v20->m_nWingedEdge = this->m_pPrevReduceInfo[v14].m_nWingedEdge;
    }
LABEL_29:
    v12 = (CEdgeList::Edge_t *)nEnterSurfID;
    nEdgeSurfID = v35;
    v7 = v35;
LABEL_30:
    m_pNextActiveEdge = v12;
  }
  while ( v12 != &this->m_EndTerminal );
}

//------------------------------------------------------------------------------
// Address: 0x100F3E50
// Name: public: void CEdgeList::ReduceActiveList(class CWingedEdgeList __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEdgeList::ReduceActiveList(CEdgeList *this, CWingedEdgeList *newEdgeList)
{
  CEdgeList::ReduceInfo_t *m_Size; // eax
  int v4; // ebx
  int v5; // edi
  void *v6; // esp
  void *v7; // esp
  unsigned __int16 *m_pMemory; // ecx
  int v9; // ebx
  CEdgeList::Edge_t *p_m_EndTerminal; // edi
  double v11; // st7
  double m_flNextDiscontinuity; // st7
  double EdgeCrossingDiscontinuity; // st6
  int m_nNewReduceCount; // ecx
  CEdgeList::ReduceInfo_t *v15; // eax
  CEdgeList::Edge_t *m_pNextActiveEdge; // eax
  CEdgeList::ReduceInfo_t *v17; // xmm2_4
  float v18; // xmm1_4
  float v19; // xmm3_4
  CEdgeList::Edge_t *v20; // ecx
  float v21; // xmm0_4
  int m_nCurrentEdgeIndex; // eax
  float v23; // xmm0_4
  float v24; // [esp-Ch] [ebp-134h]
  float v25; // [esp-8h] [ebp-130h]
  float v26; // [esp-4h] [ebp-12Ch]
  float v27; // [esp-4h] [ebp-12Ch]
  float v28; // [esp+0h] [ebp-128h] BYREF
  CEdgeList::Edge_t *y[4]; // [esp+Ch] [ebp-11Ch] BYREF
  CEdgeList::Edge_t *pEdgeCrossings[64]; // [esp+1Ch] [ebp-10Ch] BYREF
  CEdgeList::ReduceInfo_t *pBuf[2]; // [esp+11Ch] [ebp-Ch]
  float flPrevY; // [esp+124h] [ebp-4h]

  m_Size = (CEdgeList::ReduceInfo_t *)this->m_SortIndices.m_Size;
  pBuf[0] = m_Size;
  if ( m_Size != nullptr )
  {
    v4 = this->m_Surfaces.m_Size;
    if ( v4 > 0 )
    {
      v5 = 0;
      do
      {
        CWingedEdgeList::AddSurface(this: newEdgeList, plane: &this->m_Surfaces.m_Memory.m_pMemory[v5++].m_Plane);
        --v4;
      }
      while ( v4 != 0 );
      m_Size = pBuf[0];
    }
    v6 = alloca(8 * (_DWORD)m_Size);
    pEdgeCrossings[60] = (CEdgeList::Edge_t *)&v28;
    v7 = alloca(8 * (_DWORD)m_Size);
    m_pMemory = this->m_SortIndices.m_Memory.m_pMemory;
    v9 = 0;
    this->m_nNewReduceCount = 0;
    this->m_nPrevReduceCount = 0;
    this->m_nCurrentEdgeIndex = 0;
    p_m_EndTerminal = &this->m_EndTerminal;
    v11 = this->m_Edges.m_Memory.m_pMemory[*m_pMemory].m_vecPosition.y;
    this->m_StartTerminal.m_pNextActiveEdge = &this->m_EndTerminal;
    this->m_flNextDiscontinuity = v11;
    this->m_EndTerminal.m_pPrevActiveEdge = &this->m_StartTerminal;
    this->m_pCurrentActiveEdge = &this->m_EndTerminal;
    this->m_flLastX = this->m_EndTerminal.m_flX;
    pEdgeCrossings[61] = (CEdgeList::Edge_t *)&v28;
    m_flNextDiscontinuity = this->m_flNextDiscontinuity;
    this->m_StartSurfTerminal.m_pNextSurface = &this->m_EndSurfTerminal;
    this->m_EndSurfTerminal.m_pPrevSurface = &this->m_StartSurfTerminal;
    if ( m_flNextDiscontinuity <= -1.0 )
      m_flNextDiscontinuity = -1.0;
    v26 = m_flNextDiscontinuity;
    this->m_flNextDiscontinuity = 3.4028235e38;
    CEdgeList::IntroduceNewActiveEdges(this, y: v26);
    pEdgeCrossings[63] = nullptr;
    HIBYTE(flPrevY) = 0;
    while ( 1 )
    {
      v24 = m_flNextDiscontinuity;
      EdgeCrossingDiscontinuity = CEdgeList::LocateEdgeCrossingDiscontinuity(
                                    this,
                                    flNextY: this->m_flNextDiscontinuity,
                                    flPrevY: v24,
                                    nCount: (int *)&pEdgeCrossings[63],
                                    ppInfo: y);
      *(float *)&pBuf[1] = EdgeCrossingDiscontinuity;
      m_nNewReduceCount = this->m_nNewReduceCount;
      v15 = (CEdgeList::ReduceInfo_t *)pEdgeCrossings[v9 + 60];
      this->m_pNewReduceInfo = (CEdgeList::ReduceInfo_t *)pEdgeCrossings[-v9 + 61];
      this->m_pPrevReduceInfo = v15;
      this->m_nPrevReduceCount = m_nNewReduceCount;
      this->m_nNewReduceCount = 0;
      if ( EdgeCrossingDiscontinuity >= 1.001 )
      {
        pBuf[1] = (CEdgeList::ReduceInfo_t *)1065361605;
        EdgeCrossingDiscontinuity = 1.001;
        HIBYTE(flPrevY) = 1;
      }
      v27 = EdgeCrossingDiscontinuity;
      v25 = m_flNextDiscontinuity;
      CEdgeList::ReduceActiveEdgeList(this, wingedEdgeList: newEdgeList, flMinY: v25, flMaxY: v27);
      m_pNextActiveEdge = this->m_StartTerminal.m_pNextActiveEdge;
      v17 = pBuf[1];
      v18 = -3.4028235e38;
      pEdgeCrossings[62] = (CEdgeList::Edge_t *)pBuf[1];
      this->m_flNextDiscontinuity = 3.4028235e38;
      if ( m_pNextActiveEdge != p_m_EndTerminal )
      {
        do
        {
          v19 = m_pNextActiveEdge->m_vecPositionEnd.y;
          v20 = m_pNextActiveEdge->m_pNextActiveEdge;
          if ( *(float *)&v17 < v19 )
          {
            v21 = (float)((float)(*(float *)&v17 - m_pNextActiveEdge->m_vecPosition.y) * m_pNextActiveEdge->m_flDxDy)
                + m_pNextActiveEdge->m_vecPosition.x;
            m_pNextActiveEdge->m_flX = v21;
            if ( v18 <= v21 )
              v18 = v21;
            else
              m_pNextActiveEdge->m_flX = v18;
            if ( this->m_flNextDiscontinuity > v19 )
              this->m_flNextDiscontinuity = v19;
          }
          else
          {
            m_pNextActiveEdge->m_pPrevActiveEdge->m_pNextActiveEdge = v20;
            m_pNextActiveEdge->m_pNextActiveEdge->m_pPrevActiveEdge = m_pNextActiveEdge->m_pPrevActiveEdge;
          }
          m_pNextActiveEdge = v20;
        }
        while ( v20 != p_m_EndTerminal );
      }
      if ( pEdgeCrossings[63] != nullptr )
      {
        CEdgeList::ReorderActiveEdgeList(this, nCount: (int)pEdgeCrossings[63], ppCrossings: y);
        m_nCurrentEdgeIndex = this->m_nCurrentEdgeIndex;
        if ( m_nCurrentEdgeIndex < (int)pBuf[0] )
        {
          v23 = this->m_Edges.m_Memory.m_pMemory[this->m_SortIndices.m_Memory.m_pMemory[m_nCurrentEdgeIndex]].m_vecPosition.y;
          if ( this->m_flNextDiscontinuity > v23 )
            this->m_flNextDiscontinuity = v23;
        }
      }
      else
      {
        CEdgeList::IntroduceNewActiveEdges(this, y: *(float *)&pBuf[1]);
        if ( this->m_flNextDiscontinuity == 3.4028235e38 )
          return;
      }
      v9 = 1 - v9;
      if ( HIBYTE(flPrevY) != 0 )
        break;
      m_flNextDiscontinuity = *(float *)&pEdgeCrossings[62];
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F4110
// Name: public: COcclusionSystem::COcclusionSystem(void)
// Source: json
//------------------------------------------------------------------------------
COcclusionSystem *__thiscall COcclusionSystem::COcclusionSystem(COcclusionSystem *this)
{
  Vector *v2; // eax

  this->__vftable = (COcclusionSystem_vtbl *)&COcclusionSystem::`vftable';
  CEdgeList::CEdgeList(this: &this->m_EdgeList);
  CWingedEdgeList::CWingedEdgeList(this: &this->m_WingedEdgeList);
  this->m_ClippedVerts.m_Memory.m_pMemory = nullptr;
  this->m_ClippedVerts.m_Memory.m_nAllocationCount = 64;
  this->m_ClippedVerts.m_Memory.m_nGrowSize = 0;
  v2 = (Vector *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 768);
  this->m_ClippedVerts.m_Memory.m_pMemory = v2;
  this->m_ClippedVerts.m_Size = 0;
  this->m_ClippedVerts.m_pElements = v2;
  this->m_bEdgeListDirty = false;
  this->m_nTests = 0;
  this->m_nOccluded = 0;
  this->m_flMinOccluderArea = 5.0;
  this->m_flMaxOccludeeArea = 5.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100F41A0
// Name: private: void COcclusionSystem::StitchClippedVertices(class Vector __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COcclusionSystem::StitchClippedVertices(COcclusionSystem *this, Vector *pVertices, int nCount)
{
  long double v4; // st7
  int v6; // ecx
  Vector *m_pMemory; // edi
  float *p_x; // edx
  float *v9; // eax

  if ( nCount > 0 )
  {
    v4 = 0.001;
    do
    {
      if ( fabs(pVertices->z) <= 0.001 )
      {
        v6 = this->m_ClippedVerts.m_Size - 1;
        if ( v6 < 0 )
        {
LABEL_10:
          CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
            this: &this->m_ClippedVerts,
            elem: this->m_ClippedVerts.m_Size,
            src: pVertices);
          v4 = 0.001;
        }
        else
        {
          m_pMemory = this->m_ClippedVerts.m_Memory.m_pMemory;
          p_x = &m_pMemory[v6].x;
          while ( fabs(pVertices->x - *p_x) > v4 || fabs(pVertices->y - p_x[1]) > v4 || v4 < fabs(pVertices->z - p_x[2]) )
          {
            p_x -= 3;
            if ( --v6 < 0 )
              goto LABEL_10;
          }
          v9 = &m_pMemory[v6].x;
          pVertices->x = *v9;
          pVertices->y = v9[1];
          pVertices->z = v9[2];
        }
      }
      ++pVertices;
      --nCount;
    }
    while ( nCount != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F4270
// Name: private: void COcclusionSystem::AddPolygonToEdgeList(class CEdgeList __near &,class Vector __near * __near *,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COcclusionSystem::AddPolygonToEdgeList(
        COcclusionSystem *this,
        CEdgeList *edgeList,
        Vector **ppPolygon,
        int nCount,
        int nSurfID,
        bool bClipped)
{
  int v6; // ebx
  void *v7; // esp
  void *v8; // esp
  Vector **m_flDist_low; // esi
  void *v10; // esp
  float *v11; // esi
  int v12; // eax
  Vector **v13; // ebx
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // esi
  int v19; // edx
  float v20; // xmm4_4
  float y; // xmm0_4
  float x; // xmm1_4
  unsigned int v23; // ecx
  COcclusionSystem::AxisAlignedPlane_t *p_plane; // eax
  float v25; // xmm2_4
  float v26; // xmm2_4
  float v27; // xmm2_4
  float v28; // xmm2_4
  float v29; // xmm0_4
  int v30; // esi
  Vector *v31; // eax
  int v32; // edi
  Vector *v33; // ebx
  Vector *v34[2]; // [esp+0h] [ebp-24h] BYREF
  int v35; // [esp+8h] [ebp-1Ch] BYREF
  COcclusionSystem::AxisAlignedPlane_t plane; // [esp+Ch] [ebp-18h] BYREF
  int v37; // [esp+18h] [ebp-Ch]
  Vector *pVecProjectedVertex; // [esp+1Ch] [ebp-8h]
  COcclusionSystem *v39; // [esp+20h] [ebp-4h]
  int nLastClipVert; // [esp+30h] [ebp+Ch]
  int nLastClipVerta; // [esp+30h] [ebp+Ch]
  Vector *bClippeda; // [esp+3Ch] [ebp+18h]

  v6 = nCount;
  v39 = this;
  v7 = alloca(16 * nCount);
  v8 = alloca(16 * nCount);
  m_flDist_low = v34;
  LODWORD(plane.m_flDist) = v34;
  v10 = alloca(12 * nCount);
  pVecProjectedVertex = (Vector *)v34;
  if ( nCount > 0 )
  {
    v11 = (float *)&v35;
    v12 = (char *)ppPolygon - (char *)v34;
    v13 = v34;
    v37 = (char *)ppPolygon - (char *)v34;
    nLastClipVert = nCount;
    while ( 1 )
    {
      Vector3DMultiplyPositionProjective(
        src1: &v39->m_WorldToProjection,
        src2: *(Vector **)((char *)v13 + v12),
        dst: (Vector *)(v11 - 2));
      *v11 = (float)(*v11 > 0.0) * *v11;
      *v13 = (Vector *)(v11 - 2);
      v11 += 3;
      ++v13;
      if ( --nLastClipVert == 0 )
        break;
      v12 = v37;
    }
    m_flDist_low = (Vector **)LODWORD(plane.m_flDist);
    v6 = nCount;
  }
  plane.m_nAxis = 0;
  s_nTempVertCount = 0;
  plane.m_flDist = -1.0;
  plane.m_flSign = -1.0;
  v14 = COcclusionSystem::ClipPolygonToAxisAlignedPlane(
          this: v39,
          ppVertices: v34,
          nVertexCount: v6,
          &plane,
          ppOutVerts: m_flDist_low);
  if ( v14 >= 3 )
  {
    plane.m_flSign = 1.0;
    v15 = COcclusionSystem::ClipPolygonToAxisAlignedPlane(
            this: v39,
            ppVertices: m_flDist_low,
            nVertexCount: v14,
            &plane,
            ppOutVerts: v34);
    if ( v15 >= 3 )
    {
      plane.m_nAxis = 1;
      v16 = COcclusionSystem::ClipPolygonToAxisAlignedPlane(
              this: v39,
              ppVertices: v34,
              nVertexCount: v15,
              &plane,
              ppOutVerts: m_flDist_low);
      if ( v16 >= 3 )
      {
        plane.m_flSign = -1.0;
        v17 = COcclusionSystem::ClipPolygonToAxisAlignedPlane(
                this: v39,
                ppVertices: m_flDist_low,
                nVertexCount: v16,
                &plane,
                ppOutVerts: v34);
        if ( v17 >= 3 )
        {
          v18 = v17 - 1;
          v19 = 1;
          v20 = 0.0;
          nLastClipVerta = v17 - 1;
          if ( v17 - 2 >= 4 )
          {
            y = v34[0]->y;
            x = v34[0]->x;
            v23 = ((unsigned int)(v17 - 6) >> 2) + 1;
            p_plane = &plane;
            v19 = 4 * v23 + 1;
            do
            {
              v25 = (float)((float)(*(float *)(LODWORD(p_plane[-1].m_flDist) + 4) - y)
                          * (float)(*(float *)LODWORD(p_plane[-1].m_flSign) - x))
                  - (float)((float)(*(float *)(LODWORD(p_plane[-1].m_flSign) + 4) - y)
                          * (float)(*(float *)LODWORD(p_plane[-1].m_flDist) - x));
              if ( v25 < 0.0 )
                v20 = v20 - v25;
              v26 = (float)((float)(*(float *)(p_plane->m_nAxis + 4) - y)
                          * (float)(*(float *)LODWORD(p_plane[-1].m_flDist) - x))
                  - (float)((float)(*(float *)(LODWORD(p_plane[-1].m_flDist) + 4) - y)
                          * (float)(*(float *)p_plane->m_nAxis - x));
              if ( v26 < 0.0 )
                v20 = v20 - v26;
              v27 = (float)((float)(*(float *)(LODWORD(p_plane->m_flSign) + 4) - y)
                          * (float)(*(float *)p_plane->m_nAxis - x))
                  - (float)((float)(*(float *)(p_plane->m_nAxis + 4) - y)
                          * (float)(*(float *)LODWORD(p_plane->m_flSign) - x));
              if ( v27 < 0.0 )
                v20 = v20 - v27;
              v28 = (float)((float)(*(float *)(LODWORD(p_plane->m_flDist) + 4) - y)
                          * (float)(*(float *)LODWORD(p_plane->m_flSign) - x))
                  - (float)((float)(*(float *)(LODWORD(p_plane->m_flSign) + 4) - y)
                          * (float)(*(float *)LODWORD(p_plane->m_flDist) - x));
              if ( v28 < 0.0 )
                v20 = v20 - v28;
              p_plane = (COcclusionSystem::AxisAlignedPlane_t *)((char *)p_plane + 16);
              --v23;
            }
            while ( v23 != 0 );
            v6 = nCount;
            v18 = nLastClipVerta;
          }
          for ( ; v19 < v18; ++v19 )
          {
            v29 = (float)((float)(v34[v19 + 1]->y - v34[0]->y) * (float)(v34[v19]->x - v34[0]->x))
                - (float)((float)(v34[v19]->y - v34[0]->y) * (float)(v34[v19 + 1]->x - v34[0]->x));
            if ( v29 < 0.0 )
              v20 = v20 - v29;
          }
          edgeList->m_Surfaces.m_Memory.m_pMemory[nSurfID].m_flArea = v20;
          if ( bClipped )
            COcclusionSystem::StitchClippedVertices(this: v39, pVertices: pVecProjectedVertex, nCount: v6);
          v30 = v6 - 1;
          v31 = &pVecProjectedVertex[v6 - 1];
          v32 = 0;
          bClippeda = v31;
          LODWORD(plane.m_flDist) = v31;
          if ( v6 - 1 > 0 )
          {
            v33 = pVecProjectedVertex;
            do
            {
              *((_DWORD *)&plane.m_flSign + (v32 & 1)) = v33;
              CEdgeList::AddEdge(
                this: edgeList,
                ppEdgeVertices: COERCE_FLOAT((COcclusionSystem::AxisAlignedPlane_t *)&plane.m_flSign),
                nSurfID);
              ++v32;
              ++v33;
            }
            while ( v32 < v30 );
            v31 = bClippeda;
          }
          *((_DWORD *)&plane.m_flSign + (v30 & 1)) = v31;
          CEdgeList::AddEdge(
            this: edgeList,
            ppEdgeVertices: COERCE_FLOAT((COcclusionSystem::AxisAlignedPlane_t *)&plane.m_flSign),
            nSurfID);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F45F0
// Name: private: void COcclusionSystem::RecomputeOccluderEdgeList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COcclusionSystem::RecomputeOccluderEdgeList(COcclusionSystem *this)
{
  int v2; // eax
  int v3; // eax
  CEdgeList *p_m_EdgeList; // edi
  doccluderdata_t *occluders; // ebx
  int *occludervertindices; // edx
  int v7; // eax
  int *p_area; // ebx
  int v9; // ebx
  CClientState *BaseLocalClient; // eax
  char v11; // cl
  int v12; // edx
  int v13; // ecx
  int v14; // eax
  int v15; // edx
  doccluderpolydata_t *occluderpolys; // eax
  int v17; // edi
  int *v18; // eax
  const cplane_t *v19; // ebx
  float v20; // xmm0_4
  float dist; // xmm1_4
  void *v22; // esp
  void *v23; // esp
  int v24; // eax
  int *v25; // edx
  int v26; // edi
  float v27; // xmm0_4
  CEdgeList *v28; // ebx
  int v29; // eax
  bool v30; // zf
  CWingedEdgeList *v31; // esi
  _BYTE v32[12]; // [esp+0h] [ebp-68h] BYREF
  cplane_t projectionSpacePlane; // [esp+Ch] [ebp-5Ch] BYREF
  cplane_t cameraSpacePlane; // [esp+20h] [ebp-48h] BYREF
  CWingedEdgeList *newEdgeList; // [esp+34h] [ebp-34h]
  BOOL bClipped; // [esp+38h] [ebp-30h] BYREF
  const cplane_t *surfPlane; // [esp+3Ch] [ebp-2Ch]
  mvertex_t *pVertices; // [esp+40h] [ebp-28h]
  int nFirstVertexIndex; // [esp+44h] [ebp-24h]
  int *pIndices; // [esp+48h] [ebp-20h]
  int i; // [esp+4Ch] [ebp-1Ch]
  CEdgeList *edgeList; // [esp+50h] [ebp-18h]
  int v43; // [esp+54h] [ebp-14h]
  int v44; // [esp+58h] [ebp-10h]
  Vector **ppClipVerts; // [esp+5Ch] [ebp-Ch]
  Vector **ppSurfVerts; // [esp+60h] [ebp-8h]
  unsigned __int8 color[4]; // [esp+64h] [ebp-4h] BYREF

  if ( this->m_bEdgeListDirty )
  {
    if ( GetBaseLocalClient()->m_bAreaBitsValid
      || (v2 = _CommandLine(),
          (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 40))(a1: v2, a2: "-buildcubemaps") == 0)
      && (v3 = _CommandLine(),
          (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v3 + 40))(a1: v3, a2: "-buildmodelforworld") == 0) )
    {
      this->m_bEdgeListDirty = false;
      this->m_EdgeList.m_Edges.m_Size = 0;
      this->m_EdgeList.m_SortIndices.m_Size = 0;
      p_m_EdgeList = &this->m_EdgeList;
      this->m_EdgeList.m_OrigSortIndices.m_Size = 0;
      this->m_EdgeList.m_Surfaces.m_Size = 0;
      this->m_EdgeList.m_SurfaceSort.m_Size = 0;
      this->m_WingedEdgeList.m_WingedEdges.m_Size = 0;
      this->m_WingedEdgeList.m_Surfaces.m_Size = 0;
      this->m_ClippedVerts.m_Size = 0;
      newEdgeList = &this->m_WingedEdgeList;
      occluders = host_state.worldbrush->occluders;
      pVertices = host_state.worldbrush->vertexes;
      occludervertindices = host_state.worldbrush->occludervertindices;
      v7 = host_state.worldbrush->numoccluders - 1;
      edgeList = &this->m_EdgeList;
      pIndices = occludervertindices;
      i = v7;
      if ( v7 >= 0 )
      {
        p_area = &occluders[v7].area;
        *(_DWORD *)color = p_area;
        do
        {
          if ( (*(_BYTE *)(p_area - 9) & 1) == 0 )
          {
            if ( GetBaseLocalClient() == (CClientState *)-19052
              || (v9 = *p_area,
                  BaseLocalClient = GetBaseLocalClient(),
                  v11 = v9 & 7,
                  v12 = v9 >> 3,
                  p_area = *(int **)color,
                  ((unsigned __int8)(1 << v11) & BaseLocalClient->m_chAreaBits[v12]) != 0) )
            {
              v13 = *(p_area - 7);
              v14 = *(p_area - 8);
              if ( v13 > 0 )
              {
                v15 = 12 * v14;
                v44 = 12 * v14;
                v43 = v13;
                do
                {
                  occluderpolys = host_state.worldbrush->occluderpolys;
                  v17 = *(int *)((char *)&occluderpolys->vertexcount + v15);
                  v18 = (int *)((char *)&occluderpolys->firstvertexindex + v15);
                  v19 = &host_state.worldbrush->planes[v18[2]];
                  v20 = (float)((float)(v19->normal.y * this->m_vecCameraPosition.y)
                              + (float)(this->m_vecCameraPosition.x * v19->normal.x))
                      + (float)(v19->normal.z * this->m_vecCameraPosition.z);
                  dist = v19->dist;
                  nFirstVertexIndex = *v18;
                  surfPlane = v19;
                  if ( dist < v20 )
                  {
                    v22 = alloca(4 * v17);
                    ppSurfVerts = (Vector **)v32;
                    v23 = alloca(8 * v17);
                    v24 = 0;
                    ppClipVerts = (Vector **)v32;
                    if ( v17 > 0 )
                    {
                      v25 = &pIndices[nFirstVertexIndex];
                      do
                        ppSurfVerts[v24++] = &pVertices[*v25++].position;
                      while ( v24 < v17 );
                      v19 = surfPlane;
                    }
                    v26 = COcclusionSystem::ClipPolygonToNearPlane(
                            this,
                            ppVertices: ppSurfVerts,
                            nVertexCount: v17,
                            ppOutVerts: ppClipVerts,
                            pClipped: (bool *)&bClipped);
                    if ( v26 >= 3 )
                    {
                      MatrixTransformPlane(src: &this->m_WorldToCamera, inPlane: v19, outPlane: &cameraSpacePlane);
                      v27 = 0.0;
                      if ( cameraSpacePlane.dist != 0.0 )
                        v27 = 1.0 / cameraSpacePlane.dist;
                      v28 = edgeList;
                      projectionSpacePlane.normal.x = (float)(cameraSpacePlane.normal.x * v27) * this->m_flXProjScale;
                      projectionSpacePlane.normal.y = (float)(v27 * cameraSpacePlane.normal.y) * this->m_flYProjScale;
                      projectionSpacePlane.normal.z = 1.0;
                      projectionSpacePlane.dist = (float)((float)(cameraSpacePlane.normal.z * v27)
                                                        * this->m_flProjDistScale)
                                                + this->m_flProjDistOffset;
                      v29 = CEdgeList::AddSurface(this: edgeList, plane: &projectionSpacePlane);
                      COcclusionSystem::AddPolygonToEdgeList(
                        this,
                        edgeList: v28,
                        ppPolygon: ppClipVerts,
                        nCount: v26,
                        nSurfID: v29,
                        bClipped);
                    }
                  }
                  v15 = v44 + 12;
                  v30 = v43-- == 1;
                  v44 += 12;
                }
                while ( !v30 );
                p_m_EdgeList = edgeList;
                p_area = *(int **)color;
              }
            }
          }
          p_area -= 10;
          --i;
          *(_DWORD *)color = p_area;
        }
        while ( i >= 0 );
      }
      CEdgeList::CullSmallOccluders(this: p_m_EdgeList);
      v31 = newEdgeList;
      CEdgeList::ReduceActiveList(this: p_m_EdgeList, newEdgeList);
      *(_DWORD *)color = -1;
      CWingedEdgeList::QueueVisualization(this: v31, pColor: color);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F48F0
// Name: public: virtual bool COcclusionSystem::IsOccluded(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall COcclusionSystem::IsOccluded(
        COcclusionSystem *this,
        const Vector *vecAbsMins,
        const Vector *vecAbsMaxs)
{
  DWORD CurrentThreadId; // ecx
  float v7; // xmm0_4
  float v8; // xmm4_4
  float v9; // xmm5_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float m_flMaxOccludeeArea; // xmm1_4
  float x; // xmm0_4
  float v14; // xmm2_4
  int v15; // ecx
  float *p_z; // eax
  Vector4D *v17; // edx
  Vector4D *v18; // edi
  float v19; // xmm1_4
  float v20; // xmm1_4
  float v21; // xmm1_4
  float y; // xmm2_4
  float z; // xmm3_4
  float v24; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm2_4
  float v29; // xmm1_4
  float v30; // xmm2_4
  float v31; // xmm3_4
  float v32; // xmm2_4
  int v33; // ebx
  int *v34; // edi
  int v35; // ecx
  int v36; // eax
  float v37; // xmm0_4
  float v38; // xmm4_4
  float v39; // xmm3_4
  float v40; // xmm1_4
  float v41; // xmm0_4
  float v42; // xmm2_4
  float v43; // xmm1_4
  float v44; // xmm4_4
  int v45; // eax
  int v46; // edi
  int *m_pMemory; // edi
  int v48; // eax
  int v49; // eax
  int m_nMinVert; // ecx
  int v51; // edi
  EdgeInfo_t *v52; // edx
  int v53; // eax
  char *v54; // edx
  int v55; // ecx
  float v56; // xmm0_4
  Vector *v57; // ebx
  Vector *v58; // edi
  int m_Size; // ecx
  int v60; // eax
  CWingedEdgeList::WingedEdge_t *v61; // edx
  int v62; // ecx
  CWingedEdgeList::WingedEdge_t *v63; // eax
  __int16 v64; // dx
  bool IsOccludingEdgeList; // bl
  int m_nGrowSize; // esi
  Vector4D vecProjVert[8]; // [esp+8h] [ebp-1ECh] BYREF
  int pEdgeSort[12]; // [esp+88h] [ebp-16Ch] BYREF
  Vector pVecProjectedVertex[8]; // [esp+B8h] [ebp-13Ch] BYREF
  int pSurfInd[6]; // [esp+118h] [ebp-DCh]
  cplane_t cameraSpacePlane; // [esp+130h] [ebp-C4h]
  cplane_t projectionSpacePlane; // [esp+144h] [ebp-B0h] BYREF
  Vector4D vecDeltaProj[3]; // [esp+158h] [ebp-9Ch] BYREF
  Vector vecDelta[2]; // [esp+188h] [ebp-6Ch]
  float pSign[2]; // [esp+1A0h] [ebp-54h]
  const Vector *pCornerVert[2]; // [esp+1A8h] [ebp-4Ch]
  Vector4D vecAbsMins4D; // [esp+1B0h] [ebp-44h] BYREF
  Vector vecSize; // [esp+1C0h] [ebp-34h]
  int nLeaveSurfID; // [esp+1CCh] [ebp-28h]
  int nEnterSurfID; // [esp+1D0h] [ebp-24h]
  CUtlSortVector<int,WingedEdgeLessFunc> edgeSort; // [esp+1D4h] [ebp-20h] BYREF
  int i; // [esp+1F0h] [ebp-4h] BYREF
  Vector *vecAbsMinsa; // [esp+1FCh] [ebp+8h]
  const Vector *vecAbsMinsb; // [esp+1FCh] [ebp+8h]

  if ( r_occlusion.m_pParent == nullptr || r_occlusion.m_pParent->m_Value.m_nValue == 0 )
    return false;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "COcclusionSystem::IsOccluded",
    a3: 0,
    a4: "Occlusion",
    a5: false,
    a6: 4);
  if ( (_S2_7 & 1) == 0 )
  {
    _S2_7 |= 1u;
    mutex.m_ownerID = 0;
    mutex.m_depth = 0;
  }
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != mutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++mutex.m_depth;
  }
  COcclusionSystem::RecomputeOccluderEdgeList(this);
  if ( this->m_WingedEdgeList.m_WingedEdges.m_Size != 0 )
  {
    v7 = (float)((float)(this->m_NearClipPlane.normal.y
                       * (float)((float)((float)(vecAbsMaxs->y + vecAbsMins->y) * 0.5) - this->m_vecCameraPosition.y))
               + (float)(this->m_NearClipPlane.normal.x
                       * (float)((float)((float)(vecAbsMaxs->x + vecAbsMins->x) * 0.5) - this->m_vecCameraPosition.x)))
       + (float)(this->m_NearClipPlane.normal.z
               * (float)((float)((float)(vecAbsMaxs->z + vecAbsMins->z) * 0.5) - this->m_vecCameraPosition.z));
    if ( v7 > 0.0 )
    {
      v8 = vecAbsMaxs->y - vecAbsMins->y;
      v9 = vecAbsMaxs->z - vecAbsMins->z;
      v10 = this->m_flNearPlaneDist + v7;
      vecSize.x = vecAbsMaxs->x - vecAbsMins->x;
      vecSize.z = v9;
      v11 = (float)((float)((float)((float)((float)(v8 * v8) + (float)(vecSize.x * vecSize.x)) + (float)(v9 * v9)) * 0.25)
                  * this->m_flFOVFactor)
          / (float)(v10 * v10);
      m_flMaxOccludeeArea = r_occludeemaxarea.m_pParent->m_Value.m_fValue * 0.0099999998;
      vecSize.y = v8;
      if ( m_flMaxOccludeeArea == 0.0 )
        m_flMaxOccludeeArea = this->m_flMaxOccludeeArea;
      if ( v11 >= m_flMaxOccludeeArea )
      {
LABEL_27:
        if ( --mutex.m_depth == 0 )
          _InterlockedExchange((volatile __int32 *)&mutex, 0);
LABEL_29:
        CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
        return false;
      }
      s_WingedTestEdgeList.m_WingedEdges.m_Size = 0;
      s_WingedTestEdgeList.m_Surfaces.m_Size = 0;
      x = vecAbsMins->x;
      pCornerVert[1] = vecAbsMaxs;
      vecAbsMins4D.x = x;
      vecAbsMins4D.y = vecAbsMins->y;
      vecAbsMins4D.z = vecAbsMins->z;
      pCornerVert[0] = vecAbsMins;
      vecAbsMins4D.w = 1.0;
      Vector4DMultiply(src1: &this->m_WorldToProjection, src2: &vecAbsMins4D, dst: vecProjVert);
      if ( vecProjVert[0].w > 0.0 )
      {
        vecDeltaProj[0].x = vecSize.x * this->m_WorldToProjection.m[0][0];
        vecDeltaProj[0].y = this->m_WorldToProjection.m[1][0] * vecSize.x;
        vecDeltaProj[0].z = this->m_WorldToProjection.m[2][0] * vecSize.x;
        vecDeltaProj[0].w = this->m_WorldToProjection.m[3][0] * vecSize.x;
        vecDeltaProj[1].x = this->m_WorldToProjection.m[0][1] * vecSize.y;
        vecDeltaProj[1].y = this->m_WorldToProjection.m[1][1] * vecSize.y;
        vecDeltaProj[1].z = this->m_WorldToProjection.m[2][1] * vecSize.y;
        vecDeltaProj[1].w = this->m_WorldToProjection.m[3][1] * vecSize.y;
        vecDeltaProj[2].x = this->m_WorldToProjection.m[0][2] * vecSize.z;
        vecDeltaProj[2].y = this->m_WorldToProjection.m[1][2] * vecSize.z;
        vecDeltaProj[2].z = this->m_WorldToProjection.m[2][2] * vecSize.z;
        v14 = this->m_WorldToProjection.m[3][2] * vecSize.z;
        pVecProjectedVertex[0].x = vecProjVert[0].x * (float)(1.0 / vecProjVert[0].w);
        pVecProjectedVertex[0].y = vecProjVert[0].y * (float)(1.0 / vecProjVert[0].w);
        vecDeltaProj[2].w = v14;
        pVecProjectedVertex[0].z = vecProjVert[0].z * (float)(1.0 / vecProjVert[0].w);
        if ( pVecProjectedVertex[0].z > 0.0 )
        {
          v15 = 1;
          vecAbsMinsa = (Vector *)&pVecProjectedVertex[1].z;
          i = 1;
          p_z = &vecProjVert[1].z;
          do
          {
            v17 = &vecDeltaProj[s_pDeltaIndices[v15]];
            v18 = &vecProjVert[s_pSourceIndices[v15]];
            *(p_z - 2) = v17->x + v18->x;
            *(p_z - 1) = v17->y + v18->y;
            *p_z = v17->z + v18->z;
            v19 = v17->w + v18->w;
            p_z[1] = v19;
            if ( v19 <= 0.0
              || (vecAbsMinsa[-1].y = (float)(1.0 / v19) * *(p_z - 2),
                  vecAbsMinsa[-1].z = *(p_z - 1) * (float)(1.0 / v19),
                  v20 = *p_z * (float)(1.0 / v19),
                  vecAbsMinsa->x = v20,
                  v20 <= 0.0) )
            {
              i = v15;
              goto LABEL_27;
            }
            ++v15;
            p_z += 4;
            ++vecAbsMinsa;
          }
          while ( v15 < 8 );
          v21 = vecAbsMins->x;
          y = vecAbsMins->y;
          z = vecAbsMins->z;
          pSign[0] = -1.0;
          v24 = this->m_vecCameraPosition.x;
          v25 = v21 - v24;
          v26 = v24 - vecAbsMaxs->x;
          vecDelta[0].x = v25;
          v27 = this->m_vecCameraPosition.y;
          v28 = y - v27;
          v29 = v27 - vecAbsMaxs->y;
          vecDelta[0].y = v28;
          v30 = this->m_vecCameraPosition.z;
          v31 = z - v30;
          v32 = v30 - vecAbsMaxs->z;
          ++this->m_nTests;
          i = v15;
          pSign[1] = 1.0;
          vecDelta[0].z = v31;
          vecDelta[1].x = v26;
          vecDelta[1].y = v29;
          vecDelta[1].z = v32;
          v33 = 0;
          v34 = &s_pFaceEdges[0][2];
          do
          {
            v35 = v33 & 1;
            v36 = v33 >> 1;
            if ( *(&vecDelta[0].x + 2 * v35 + v35 + (v33 >> 1)) > 0.0 )
            {
              v37 = pSign[v35];
              v38 = this->m_WorldToCamera.m[1][v36] * v37;
              v39 = this->m_WorldToCamera.m[0][v36] * v37;
              v40 = this->m_WorldToCamera.m[2][v36] * v37;
              v41 = (float)((float)((float)(this->m_WorldToCamera.m[1][3] * v38)
                                  + (float)(this->m_WorldToCamera.m[0][3] * v39))
                          + (float)(this->m_WorldToCamera.m[2][3] * v40))
                  + (float)((float)((float)((float)(v38 * v38) + (float)(v39 * v39)) + (float)(v40 * v40))
                          * (float)(*(&pCornerVert[v35]->x + v36) * v37));
              cameraSpacePlane.normal.x = v39;
              cameraSpacePlane.normal.y = v38;
              cameraSpacePlane.normal.z = v40;
              cameraSpacePlane.dist = v41;
              if ( v41 == 0.0 )
                v42 = 0.0;
              else
                v42 = 1.0 / v41;
              v43 = (float)((float)(v40 * v42) * this->m_flProjDistScale) + this->m_flProjDistOffset;
              v44 = (float)(v38 * v42) * this->m_flYProjScale;
              projectionSpacePlane.normal.x = (float)(v39 * v42) * this->m_flXProjScale;
              projectionSpacePlane.normal.y = v44;
              projectionSpacePlane.normal.z = 1.0;
              projectionSpacePlane.dist = v43;
              pSurfInd[v33] = CWingedEdgeList::AddSurface(this: &s_WingedTestEdgeList, plane: &projectionSpacePlane);
              s_pEdges[*(v34 - 2)].m_nTestCount = this->m_nTests;
              v45 = *v34;
              s_pEdges[*(v34 - 1)].m_nTestCount = this->m_nTests;
              s_pEdges[v45].m_nTestCount = this->m_nTests;
              s_pEdges[v34[1]].m_nTestCount = this->m_nTests;
            }
            else
            {
              pSurfInd[v33] = -1;
            }
            v34 += 4;
            ++v33;
          }
          while ( (int)v34 < (int)&vec4_invalid_9 );
          v46 = 0;
          edgeSort.m_Memory.m_pMemory = pEdgeSort;
          edgeSort.m_Memory.m_nAllocationCount = 12;
          edgeSort.m_Memory.m_nGrowSize = -1;
          edgeSort.m_Size = 0;
          edgeSort.m_pElements = pEdgeSort;
          edgeSort.m_bNeedsSort = false;
          edgeSort.m_pLessContext = pVecProjectedVertex;
          i = 0;
          do
          {
            if ( s_pEdges[v46].m_nTestCount == this->m_nTests )
            {
              s_pEdges[v46].m_nMinVert = pVecProjectedVertex[s_pEdges[v46].m_nVert[0]].y >= pVecProjectedVertex[s_pEdges[v46].m_nVert[1]].y;
              CUtlSortVector<int,WingedEdgeLessFunc>::Insert(this: &edgeSort, src: &i);
            }
            i = ++v46;
          }
          while ( v46 < 12 );
          m_pMemory = edgeSort.m_Memory.m_pMemory;
          v48 = 0;
          for ( i = 0; v48 < edgeSort.m_Size; i = v48 )
          {
            v49 = m_pMemory[v48];
            m_nMinVert = s_pEdges[v49].m_nMinVert;
            v51 = s_pEdges[v49].m_nVert[m_nMinVert];
            v52 = &s_pEdges[v49];
            v53 = v52->m_nFace[m_nMinVert];
            v54 = (char *)v52 - m_nMinVert;
            v55 = pSurfInd[v53];
            v56 = pVecProjectedVertex[(unsigned __int8)v54[1]].y - pVecProjectedVertex[v51].y;
            v57 = &pVecProjectedVertex[(unsigned __int8)v54[1]];
            v58 = &pVecProjectedVertex[v51];
            nEnterSurfID = pSurfInd[(unsigned __int8)v54[3]];
            nLeaveSurfID = v55;
            if ( v56 != 0.0 )
            {
              m_Size = s_WingedTestEdgeList.m_WingedEdges.m_Size;
              v60 = s_WingedTestEdgeList.m_WingedEdges.m_Size;
              vecAbsMinsb = (const Vector *)s_WingedTestEdgeList.m_WingedEdges.m_Size;
              if ( s_WingedTestEdgeList.m_WingedEdges.m_Size + 1 > s_WingedTestEdgeList.m_WingedEdges.m_Memory.m_nAllocationCount )
              {
                CUtlMemory<CWingedEdgeList::WingedEdge_t,int>::Grow(
                  this: (CUtlMemory<vgui::AnimationController::AnimCommand_t,int> *)&s_WingedTestEdgeList.m_WingedEdges,
                  num: s_WingedTestEdgeList.m_WingedEdges.m_Size
                - s_WingedTestEdgeList.m_WingedEdges.m_Memory.m_nAllocationCount
                + 1);
                m_Size = s_WingedTestEdgeList.m_WingedEdges.m_Size;
                v60 = (int)vecAbsMinsb;
              }
              v61 = s_WingedTestEdgeList.m_WingedEdges.m_Memory.m_pMemory;
              s_WingedTestEdgeList.m_WingedEdges.m_Size = m_Size + 1;
              v62 = m_Size - v60;
              s_WingedTestEdgeList.m_WingedEdges.m_pElements = s_WingedTestEdgeList.m_WingedEdges.m_Memory.m_pMemory;
              if ( v62 > 0 )
              {
                _V_memmove(
                  dest: &s_WingedTestEdgeList.m_WingedEdges.m_Memory.m_pMemory[v60 + 1],
                  src: &s_WingedTestEdgeList.m_WingedEdges.m_Memory.m_pMemory[v60],
                  count: 48 * v62);
                v61 = s_WingedTestEdgeList.m_WingedEdges.m_Memory.m_pMemory;
                v60 = (int)vecAbsMinsb;
              }
              v63 = &v61[v60];
              v64 = nLeaveSurfID;
              v63->m_nEnterSurfID = nEnterSurfID;
              v63->m_nLeaveSurfID = v64;
              v63->m_flOODy = 1.0 / v56;
              v63->m_vecPosition.x = v58->x;
              v63->m_vecPosition.y = v58->y;
              v63->m_vecPosition.z = v58->z;
              v63->m_vecPositionEnd.x = v57->x;
              v63->m_vecPositionEnd.y = v57->y;
              v63->m_vecPositionEnd.z = v57->z;
              v63->m_pPrevActiveEdge = nullptr;
              v63->m_pNextActiveEdge = nullptr;
              v63->m_flDxDy = (float)(v57->x - v58->x) * v63->m_flOODy;
            }
            m_pMemory = edgeSort.m_Memory.m_pMemory;
            v48 = i + 1;
          }
          IsOccludingEdgeList = CWingedEdgeList::IsOccludingEdgeList(
                                  this: &this->m_WingedEdgeList,
                                  testList: &s_WingedTestEdgeList);
          if ( IsOccludingEdgeList )
            ++this->m_nOccluded;
          CWingedEdgeList::QueueVisualization(
            this: &s_WingedTestEdgeList,
            pColor: s_VisualizationColor[IsOccludingEdgeList]);
          m_nGrowSize = edgeSort.m_Memory.m_nGrowSize;
          edgeSort.m_Size = 0;
          if ( edgeSort.m_Memory.m_nGrowSize >= 0 )
          {
            if ( m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
              m_pMemory = nullptr;
              edgeSort.m_Memory.m_pMemory = nullptr;
            }
            edgeSort.m_Memory.m_nAllocationCount = 0;
          }
          edgeSort.m_pElements = m_pMemory;
          if ( m_nGrowSize >= 0 )
          {
            if ( m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
              edgeSort.m_Memory.m_pMemory = nullptr;
            }
            edgeSort.m_Memory.m_nAllocationCount = 0;
          }
          if ( --mutex.m_depth == 0 )
            _InterlockedExchange((volatile __int32 *)&mutex, 0);
          CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
          return IsOccludingEdgeList;
        }
      }
    }
  }
  if ( --mutex.m_depth == 0 )
  {
    _InterlockedExchange((volatile __int32 *)&mutex, 0);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return false;
  }
  goto LABEL_29;
}

//------------------------------------------------------------------------------
// Address: 0x101172D0
// Name: public: void CUtlMemory<struct CEdgeList::Surface_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CEdgeList::Surface_t,int>::Grow(CUtlMemory<CEdgeList::Surface_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CEdgeList::Surface_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 40 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CEdgeList::Surface_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CEdgeList::Surface_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10248360
// Name: protected: static int CUtlSortVector<class CDmxAttribute __near *,class CDmxAttributeLess>::CompareHelper(void __near *,class CDmxAttribute __near * const __near *,class CDmxAttribute __near * const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::CompareHelper(
        void *context,
        CDmxAttribute *const *lhs,
        CDmxAttribute *const *rhs)
{
  int v3; // ecx
  int v4; // esi
  int result; // eax
  int lhsa; // [esp+14h] [ebp+Ch]
  int rhsa; // [esp+18h] [ebp+10h]
  int rhsb; // [esp+18h] [ebp+10h]

  v3 = (int)*rhs;
  v4 = (int)*lhs;
  result = -1;
  if ( *lhs != nullptr )
    rhsa = *(_DWORD *)(v4 + 4);
  else
    rhsa = -1;
  if ( v3 != 0 )
    lhsa = *(_DWORD *)(v3 + 4);
  else
    lhsa = -1;
  if ( rhsa >= lhsa )
  {
    if ( v3 != 0 )
      rhsb = *(_DWORD *)(v3 + 4);
    else
      rhsb = -1;
    if ( v4 != 0 )
      return rhsb < *(_DWORD *)(v4 + 4);
    else
      return rhsb < -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10248560
// Name: public: int CUtlSortVector<class CDmxAttribute __near *,class CDmxAttributeLess>::Find(class CDmxAttribute __near * const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::Find(
        CUtlSortVector<CDmxAttribute *,CDmxAttributeLess> *this,
        CDmxAttribute *const **src)
{
  int v3; // ebx
  int v4; // ecx
  CDmxAttribute **m_pMemory; // eax
  CDmxAttribute *const *v6; // esi
  int result; // eax
  CDmxAttribute *v8; // edx
  int *v9; // edi
  int *v10; // esi
  int *v11; // esi
  int *v12; // ecx
  int v13; // [esp+Ch] [ebp-24h] BYREF
  CUtlSymbolLarge::<unnamed_type_u> v14; // [esp+10h] [ebp-20h] BYREF
  int v15; // [esp+14h] [ebp-1Ch] BYREF
  int v16; // [esp+18h] [ebp-18h] BYREF
  int v17; // [esp+1Ch] [ebp-14h] BYREF
  int v18; // [esp+20h] [ebp-10h] BYREF
  int v19; // [esp+24h] [ebp-Ch] BYREF
  CUtlSymbolLarge::<unnamed_type_u> v20; // [esp+28h] [ebp-8h] BYREF
  CDmxAttribute **v21; // [esp+2Ch] [ebp-4h]
  CDmxAttribute *const *srca; // [esp+38h] [ebp+8h]

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/utlsortvector.h",
         215,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1/utlsortvector.h",
                            a2: 215,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/utlsortvector.h",
      a2: 215);
  }
  v3 = 0;
  v4 = this->m_Size - 1;
  if ( v4 >= 0 )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = *src;
    v21 = m_pMemory;
    for ( srca = v6; ; v6 = srca )
    {
      result = (v4 + v3) >> 1;
      v8 = v21[result];
      if ( v8 != nullptr )
      {
        v20.m_Id = (int)v8->m_Name.u;
        v9 = (int *)&v20;
      }
      else
      {
        v19 = -1;
        v9 = &v19;
      }
      if ( v6 != nullptr )
      {
        v18 = *((_DWORD *)v6 + 1);
        v10 = &v18;
      }
      else
      {
        v17 = -1;
        v10 = &v17;
      }
      if ( *v9 >= *v10 )
      {
        if ( srca != nullptr )
        {
          v16 = *((_DWORD *)srca + 1);
          v11 = &v16;
        }
        else
        {
          v15 = -1;
          v11 = &v15;
        }
        if ( v8 != nullptr )
        {
          v14.m_Id = (int)v8->m_Name.u;
          v12 = (int *)&v14;
        }
        else
        {
          v13 = -1;
          v12 = &v13;
        }
        if ( *v11 >= *v12 )
          return result;
        v4 = result - 1;
      }
      else
      {
        v3 = result + 1;
      }
      if ( v3 > v4 )
        return -1;
    }
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x102487B0
// Name: public: int CUtlSortVector<class CDmxAttribute __near *,class CDmxAttributeLess>::InsertNoSort(class CDmxAttribute __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::InsertNoSort(
        CUtlSortVector<CDmxAttribute *,CDmxAttributeLess> *this,
        CDmxAttribute **src)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmxAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmxAttribute **v7; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  this->m_bNeedsSort = true;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<INetMessage *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &this->m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = *src;
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10296AD0
// Name: public: void CUtlMemory<struct CWingedEdgeList::WingedEdge_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CWingedEdgeList::WingedEdge_t,int>::Grow(
        CUtlMemory<vgui::AnimationController::AnimCommand_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  vgui::AnimationController::AnimCommand_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 48 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (vgui::AnimationController::AnimCommand_t *)_g_pMemAlloc->Realloc_2(
                                                                      this: _g_pMemAlloc,
                                                                      a2: m_pMemory,
                                                                      a3: v7);
    else
      this->m_pMemory = (vgui::AnimationController::AnimCommand_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1003F9C0
// Name: protected: static int CUtlSortVector<class CSortedCacheFile,class CSortedCacheFile>::CompareHelper(void __near *,class CSortedCacheFile const __near *,class CSortedCacheFile const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CUtlSortVector<CSortedCacheFile,CSortedCacheFile>::CompareHelper(
        void *context,
        const CSortedCacheFile *lhs,
        const CSortedCacheFile *rhs)
{
  char s1[512]; // [esp+8h] [ebp-400h] BYREF
  char s2[512]; // [esp+208h] [ebp-200h] BYREF

  g_pFullFileSystem->String(this: g_pFullFileSystem, a2: (void *const *)lhs, a3: s1, a4: 512);
  g_pFullFileSystem->String(this: g_pFullFileSystem, a2: (void *const *)rhs, a3: s2, a4: 512);
  if ( _V_stricmp(s1, s2) < 0 )
    return -1;
  g_pFullFileSystem->String(this: g_pFullFileSystem, a2: (void *const *)rhs, a3: s2, a4: 512);
  g_pFullFileSystem->String(this: g_pFullFileSystem, a2: (void *const *)lhs, a3: s1, a4: 512);
  return _V_stricmp(s1: s2, s2: s1) < 0;
}

//------------------------------------------------------------------------------
// Address: 0x100C45B0
// Name: protected: static int CUtlSortVector<int,class SurfaceLessFunc>::CompareHelper(void __near *,int const __near *,int const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CUtlSortVector<int,SurfaceLessFunc>::CompareHelper(_DWORD *context, const int *lhs, const int *rhs)
{
  int v3; // ecx
  int v4; // edx

  v3 = 32 * *lhs;
  v4 = 32 * *rhs;
  if ( *(_DWORD *)(v3 + *context + 28) >= *(_DWORD *)(v4 + *context + 28) )
    return *(_DWORD *)(v4 + *context + 28) < *(_DWORD *)(v3 + *context + 28);
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x100DAEA0
// Name: protected: static int CUtlSortVector<struct robject_t,class CRobjectLess>::CompareHelper(void __near *,struct robject_t const __near *,struct robject_t const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CUtlSortVector<robject_t,CRobjectLess>::CompareHelper(
        void **context,
        const robject_t *lhs,
        const robject_t *rhs)
{
  void *v3; // esi
  CRobjectLess *v4; // edi

  v3 = *context;
  v4 = (CRobjectLess *)context[1];
  if ( CRobjectLess::Less(this: v4, lhs, rhs, pContext: *context) )
    return -1;
  else
    return CRobjectLess::Less(this: v4, lhs: rhs, rhs: lhs, pContext: v3);
}

//------------------------------------------------------------------------------
// Address: 0x100ED5F0
// Name: public: int CUtlSortVector<struct modelsize_t,class CModelsize_Less>::FindLessOrEqual(struct modelsize_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<modelsize_t,CModelsize_Less>::FindLessOrEqual(
        CUtlSortVector<modelsize_t,CModelsize_Less> *this,
        const modelsize_t *src)
{
  int v3; // esi
  int v4; // ecx
  modelsize_t *m_pMemory; // ebx
  int size; // edi
  int result; // eax
  int v8; // edx

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1\\utlsortvector.h",
         277,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1\\utlsortvector.h",
                            a2: 277,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1\\utlsortvector.h",
      a2: 277);
  }
  v3 = 0;
  v4 = this->m_Size - 1;
  if ( v4 >= 0 )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    size = src->size;
    do
    {
      result = (v4 + v3) >> 1;
      v8 = m_pMemory[result].size;
      if ( size <= v8 )
      {
        if ( size >= v8 )
          return result;
        v4 = result - 1;
      }
      else
      {
        v3 = result + 1;
      }
    }
    while ( v3 <= v4 );
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x100EF2B0
// Name: public: int CUtlSortVector<struct modelsize_t,class CModelsize_Less>::Insert(struct modelsize_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<modelsize_t,CModelsize_Less>::Insert(
        CUtlSortVector<modelsize_t,CModelsize_Less> *this,
        const modelsize_t *src)
{
  int LessOrEqual; // eax
  int m_nAllocationCount; // ecx
  int v5; // edi
  int m_Size; // eax
  modelsize_t *m_pMemory; // ecx
  int v8; // eax
  modelsize_t *v9; // eax

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1\\utlsortvector.h",
         150,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1\\utlsortvector.h",
                            a2: 150,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1\\utlsortvector.h",
      a2: 150);
  }
  LessOrEqual = CUtlSortVector<modelsize_t,CModelsize_Less>::FindLessOrEqual(this, src);
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  v5 = LessOrEqual + 1;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CAsyncWavDataCache::DeadBufferEntry_t,int>::Grow(
      (CUtlMemory<ResourceEntryInfo,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size - v5 - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[v5 + 1], src: &m_pMemory[v5], count: 8 * v8);
  v9 = &this->m_Memory.m_pMemory[v5];
  if ( v9 != nullptr )
    *v9 = *src;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x100F1550
// Name: public: struct cplane_t __near & cplane_t::operator=(struct cplane_t const __near &)
// Source: json
//------------------------------------------------------------------------------
cplane_t *__thiscall cplane_t::operator=(cplane_t *this, const cplane_t *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100F1590
// Name: private: static int CEdgeList::SurfCompare(void const __near *,void const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CEdgeList::SurfCompare(_DWORD *elem1, _DWORD *elem2)
{
  float m_flArea; // xmm0_4
  float v3; // xmm1_4

  m_flArea = CEdgeList::s_pSortSurfaces[*elem1].m_flArea;
  v3 = CEdgeList::s_pSortSurfaces[*elem2].m_flArea;
  if ( m_flArea <= v3 )
    return v3 > m_flArea;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x100F15D0
// Name: private: float CEdgeList::LocateEdgeCrossingDiscontinuity(float,float,int __near &,struct CEdgeList::Edge_t __near * __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CEdgeList::LocateEdgeCrossingDiscontinuity(
        CEdgeList *this,
        float flNextY,
        float flPrevY,
        int *nCount,
        CEdgeList::Edge_t **ppInfo)
{
  float v5; // xmm2_4
  CEdgeList::Edge_t *m_pNextActiveEdge; // edx
  CEdgeList::Edge_t *p_m_EndTerminal; // ebx
  float y; // xmm0_4
  float m_flDxDy; // xmm4_4
  float *p_x; // ecx
  float v12; // xmm3_4
  float v13; // xmm2_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm1_4
  float flCurrY; // [esp+10h] [ebp+10h]

  v5 = -3.4028235e38;
  *nCount = 0;
  m_pNextActiveEdge = this->m_StartTerminal.m_pNextActiveEdge;
  p_m_EndTerminal = &this->m_EndTerminal;
  for ( flCurrY = flNextY; m_pNextActiveEdge != p_m_EndTerminal; v5 = v12 )
  {
    y = m_pNextActiveEdge->m_vecPosition.y;
    m_flDxDy = m_pNextActiveEdge->m_flDxDy;
    p_x = &m_pNextActiveEdge->m_pPrevActiveEdge->m_vecPosition.x;
    v12 = (float)((float)(flCurrY - y) * m_flDxDy) + m_pNextActiveEdge->m_vecPosition.x;
    if ( v12 <= v5 )
    {
      v13 = p_x[6];
      if ( m_flDxDy < v13
        && (m_pNextActiveEdge->m_vecPositionEnd.x != p_x[3]
         || m_pNextActiveEdge->m_vecPositionEnd.y != p_x[4]
         || m_pNextActiveEdge->m_vecPositionEnd.z != p_x[5]) )
      {
        v14 = p_x[1];
        v15 = (float)(1.0 / (float)(m_pNextActiveEdge->m_flDxDy - v13))
            * (float)((float)(m_pNextActiveEdge->m_flDxDy * (float)(y - v14))
                    - (float)(m_pNextActiveEdge->m_vecPosition.x - *p_x));
        v16 = v14 + v15;
        if ( v16 < flNextY )
        {
          if ( flPrevY > v16 )
            v16 = flPrevY;
          if ( flCurrY != v16 )
          {
            flCurrY = v16;
            *nCount = 0;
          }
          v12 = (float)(p_x[6] * v15) + *p_x;
          ppInfo[(*nCount)++] = m_pNextActiveEdge;
        }
      }
    }
    m_pNextActiveEdge = m_pNextActiveEdge->m_pNextActiveEdge;
  }
  return flCurrY;
}

//------------------------------------------------------------------------------
// Address: 0x100F1720
// Name: private: void CEdgeList::ReorderActiveEdgeList(int,struct CEdgeList::Edge_t __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEdgeList::ReorderActiveEdgeList(CEdgeList *this, int nCount, CEdgeList::Edge_t **ppCrossings)
{
  int v3; // edi
  CEdgeList *v4; // eax
  CEdgeList::Edge_t *v5; // ebx
  CEdgeList::Edge_t *m_pPrevActiveEdge; // esi
  CEdgeList::Edge_t *v7; // edx
  CEdgeList::Edge_t *i; // edx
  float m_flX; // xmm0_4
  CEdgeList::Edge_t *j; // esi
  CEdgeList::Edge_t *m_pNextActiveEdge; // edx
  CEdgeList::Edge_t *p_m_EndTerminal; // ecx
  CEdgeList::Edge_t *v13; // esi
  CEdgeList::Edge_t *v14; // ebx
  CEdgeList::Edge_t *k; // eax
  float v16; // xmm0_4
  CEdgeList::Edge_t *v17; // esi

  v3 = 0;
  v4 = this;
  if ( nCount > 0 )
  {
    do
    {
      v5 = ppCrossings[v3];
      m_pPrevActiveEdge = v5->m_pPrevActiveEdge;
      v7 = m_pPrevActiveEdge->m_pPrevActiveEdge;
      ++v3;
      for ( ; v7->m_flX == m_pPrevActiveEdge->m_flX; v7 = v7->m_pPrevActiveEdge )
        m_pPrevActiveEdge = v7;
      for ( i = v5->m_pNextActiveEdge; ; i = i->m_pNextActiveEdge )
      {
        while ( v3 < nCount && i == ppCrossings[v3] )
        {
          v5 = i;
          i = i->m_pNextActiveEdge;
          ++v3;
        }
        if ( v5->m_flX != i->m_flX )
          break;
      }
      m_flX = m_pPrevActiveEdge->m_flX;
      for ( j = m_pPrevActiveEdge->m_pNextActiveEdge; j != i; j = j->m_pNextActiveEdge )
        j->m_flX = m_flX;
    }
    while ( v3 < nCount );
    v4 = this;
  }
  m_pNextActiveEdge = v4->m_StartTerminal.m_pNextActiveEdge;
  p_m_EndTerminal = &v4->m_EndTerminal;
  if ( m_pNextActiveEdge != &v4->m_EndTerminal )
  {
    do
    {
      v13 = m_pNextActiveEdge->m_pPrevActiveEdge;
      v14 = m_pNextActiveEdge->m_pNextActiveEdge;
      if ( v13->m_flX == m_pNextActiveEdge->m_flX )
      {
        v13->m_pNextActiveEdge = v14;
        m_pNextActiveEdge->m_pNextActiveEdge->m_pPrevActiveEdge = m_pNextActiveEdge->m_pPrevActiveEdge;
        for ( k = v13; k != &this->m_StartTerminal; k = k->m_pPrevActiveEdge )
        {
          v16 = k->m_flX - m_pNextActiveEdge->m_flX;
          if ( v16 <= 0.0 && (v16 < 0.0 || k->m_flDxDy <= m_pNextActiveEdge->m_flDxDy) )
            break;
        }
        v17 = k->m_pNextActiveEdge;
        m_pNextActiveEdge->m_pNextActiveEdge = v17;
        m_pNextActiveEdge->m_pPrevActiveEdge = k;
        v17->m_pPrevActiveEdge = m_pNextActiveEdge;
        k->m_pNextActiveEdge = m_pNextActiveEdge;
      }
      m_pNextActiveEdge = v14;
    }
    while ( v14 != p_m_EndTerminal );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F1870
// Name: public: virtual void COcclusionSystem::SetOcclusionParameters(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COcclusionSystem::SetOcclusionParameters(
        COcclusionSystem *this,
        float flMaxOccludeeArea,
        float flMinOccluderArea)
{
  float v3; // xmm0_4
  float v4; // xmm0_4

  v3 = flMaxOccludeeArea;
  if ( flMaxOccludeeArea == 0.0 )
    v3 = 5.0;
  this->m_flMaxOccludeeArea = v3 * 0.0099999998;
  v4 = flMinOccluderArea;
  if ( flMinOccluderArea == 0.0 )
    v4 = 5.0;
  this->m_flMinOccluderArea = v4;
}

//------------------------------------------------------------------------------
// Address: 0x100F18C0
// Name: public: virtual float COcclusionSystem::MinOccluderArea(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall COcclusionSystem::MinOccluderArea(COcclusionSystem *this)
{
  return this->m_flMinOccluderArea;
}

//------------------------------------------------------------------------------
// Address: 0x100F18D0
// Name: private: int COcclusionSystem::ClipPolygonToNearPlane(class Vector __near * __near *,int,class Vector __near * __near *,bool __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall COcclusionSystem::ClipPolygonToNearPlane(
        COcclusionSystem *this,
        Vector **ppVertices,
        int nVertexCount,
        Vector **ppOutVerts,
        bool *pClipped)
{
  Vector *v6; // esi
  int v7; // ebx
  bool v8; // cl
  Vector *v9; // edx
  Vector *v10; // edi
  float y; // xmm0_4
  float x; // xmm1_4
  float z; // xmm2_4
  const Vector *p_normal; // eax
  float v15; // xmm4_4
  double v16; // st7
  float v17; // xmm1_4
  float v18; // xmm0_4
  float v19; // xmm2_4
  Vector *v20; // ecx
  float v21; // xmm1_4
  float v22; // eax
  float v23; // xmm1_4
  float v24; // xmm0_4
  float v25; // xmm2_4
  float v26; // xmm1_4
  float v27; // eax
  const Vector *v28; // [esp-4h] [ebp-48h]
  float dist; // [esp+0h] [ebp-44h]
  float dista; // [esp+0h] [ebp-44h]
  Vector v31; // [esp+10h] [ebp-34h] BYREF
  Vector dir; // [esp+1Ch] [ebp-28h] BYREF
  float v33; // [esp+28h] [ebp-1Ch]
  float v34; // [esp+2Ch] [ebp-18h]
  COcclusionSystem *v35; // [esp+30h] [ebp-14h]
  float v36; // [esp+34h] [ebp-10h]
  int i; // [esp+38h] [ebp-Ch]
  Vector *v38; // [esp+3Ch] [ebp-8h]
  bool bEndInside; // [esp+42h] [ebp-2h]
  bool bStartInside; // [esp+43h] [ebp-1h]

  *pClipped = false;
  v35 = this;
  if ( nVertexCount < 3 )
    return 0;
  v6 = ppVertices[nVertexCount - 1];
  v7 = 0;
  v8 = (float)((float)((float)(v6->y * this->m_NearClipPlane.normal.y) + (float)(this->m_NearClipPlane.normal.x * v6->x))
             + (float)(v6->z * this->m_NearClipPlane.normal.z)) >= this->m_NearClipPlane.dist;
  bStartInside = v8;
  i = 0;
  v9 = s_TempVertMemory;
  do
  {
    v10 = ppVertices[i];
    y = v10->y;
    x = v10->x;
    z = v10->z;
    p_normal = &v35->m_NearClipPlane.normal;
    v15 = (float)((float)(v35->m_NearClipPlane.normal.x * v10->x) + (float)(v35->m_NearClipPlane.normal.y * y))
        + (float)(v35->m_NearClipPlane.normal.z * z);
    v36 = v35->m_NearClipPlane.dist;
    if ( v15 < v36 )
    {
      bEndInside = false;
      if ( !v8 )
        goto LABEL_11;
      v23 = x - v6->x;
      v24 = y - v6->y;
      v25 = z - v6->z;
      dista = v36;
      v28 = &v35->m_NearClipPlane.normal;
      ppOutVerts[v7] = v9;
      v38 = v9 + 1;
      v34 = *(float *)&ppOutVerts[v7];
      v31.x = v23;
      v31.y = v24;
      v31.z = v25;
      v33 = IntersectRayWithPlane(org: v6, dir: &v31, normal: v28, dist: dista);
      v26 = v33;
      v27 = v34;
      v9 = v38;
      *(float *)LODWORD(v34) = (float)((float)(v10->x - v6->x) * v33) + v6->x;
      *(float *)(LODWORD(v27) + 4) = (float)((float)(v10->y - v6->y) * v26) + v6->y;
      *(float *)(LODWORD(v27) + 8) = (float)((float)(v10->z - v6->z) * v26) + v6->z;
      *pClipped = true;
    }
    else
    {
      bEndInside = true;
      if ( !bStartInside )
      {
        v16 = v36;
        v17 = x - v6->x;
        v18 = y - v6->y;
        v19 = z - v6->z;
        ppOutVerts[v7] = v9;
        v20 = ppOutVerts[v7];
        dist = v16;
        v38 = v9 + 1;
        v33 = *(float *)&v20;
        dir.x = v17;
        dir.y = v18;
        dir.z = v19;
        v34 = IntersectRayWithPlane(org: v6, &dir, normal: p_normal, dist);
        v21 = v34;
        v22 = v33;
        v9 = v38;
        *(float *)LODWORD(v33) = (float)((float)(v10->x - v6->x) * v34) + v6->x;
        *(float *)(LODWORD(v22) + 4) = (float)((float)(v10->y - v6->y) * v21) + v6->y;
        *(float *)(LODWORD(v22) + 8) = (float)((float)(v10->z - v6->z) * v21) + v6->z;
        ++v7;
        *pClipped = true;
      }
      ppOutVerts[v7] = v10;
    }
    ++v7;
LABEL_11:
    v8 = bEndInside;
    v6 = v10;
    bStartInside = bEndInside;
    ++i;
  }
  while ( i < nVertexCount );
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x100F1B40
// Name: private: int COcclusionSystem::ClipPolygonToAxisAlignedPlane(class Vector __near * __near *,int,struct COcclusionSystem::AxisAlignedPlane_t const __near &,class Vector __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall COcclusionSystem::ClipPolygonToAxisAlignedPlane(
        COcclusionSystem *this,
        Vector **ppVertices,
        int nVertexCount,
        const COcclusionSystem::AxisAlignedPlane_t *plane,
        Vector **ppOutVerts)
{
  Vector *v5; // edi
  const COcclusionSystem::AxisAlignedPlane_t *v6; // eax
  int v7; // ebx
  bool v8; // cl
  Vector *v9; // esi
  int v10; // ecx
  int v11; // ecx
  Vector *v13; // [esp+14h] [ebp-18h]
  float v14; // [esp+14h] [ebp-18h]
  float v15; // [esp+18h] [ebp-14h]
  Vector *v16; // [esp+18h] [ebp-14h]
  float flSign; // [esp+1Ch] [ebp-10h]
  float flDist; // [esp+20h] [ebp-Ch]
  int i; // [esp+24h] [ebp-8h]
  bool bEndInside; // [esp+2Bh] [ebp-1h]

  v5 = ppVertices[nVertexCount - 1];
  v6 = plane;
  v7 = 0;
  v8 = (float)(*(&v5->x + plane->m_nAxis) * plane->m_flSign) >= plane->m_flDist;
  i = 0;
  if ( nVertexCount > 0 )
  {
    while ( 1 )
    {
      v9 = ppVertices[i];
      flSign = v6->m_flSign;
      flDist = v6->m_flDist;
      if ( (float)(*(&v9->x + v6->m_nAxis) * flSign) >= flDist )
        break;
      bEndInside = false;
      if ( v8 )
      {
        v11 = s_nTempVertCount++;
        ppOutVerts[v7] = &s_TempVertMemory[v11];
        v16 = &s_TempVertMemory[v11];
        v14 = IntersectRayWithAAPlane(
                vecStart: v5,
                vecEnd: v9,
                nAxis: v6->m_nAxis,
                flSign: v6->m_flSign,
                flDist: v6->m_flDist);
        v16->x = (float)((float)(v9->x - v5->x) * v14) + v5->x;
        v16->y = (float)((float)(v9->y - v5->y) * v14) + v5->y;
        v16->z = (float)((float)(v9->z - v5->z) * v14) + v5->z;
        v6 = plane;
LABEL_8:
        ++v7;
      }
      v8 = bEndInside;
      v5 = v9;
      if ( ++i >= nVertexCount )
        return v7;
    }
    bEndInside = true;
    if ( !v8 )
    {
      v10 = s_nTempVertCount++;
      ppOutVerts[v7] = &s_TempVertMemory[v10];
      v13 = &s_TempVertMemory[v10];
      v15 = IntersectRayWithAAPlane(vecStart: v5, vecEnd: v9, nAxis: v6->m_nAxis, flSign, flDist);
      v13->x = (float)((float)(v9->x - v5->x) * v15) + v5->x;
      v13->y = (float)((float)(v9->y - v5->y) * v15) + v5->y;
      v13->z = (float)((float)(v9->z - v5->z) * v15) + v5->z;
      v6 = plane;
      ++v7;
    }
    ppOutVerts[v7] = v9;
    goto LABEL_8;
  }
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x100F1D20
// Name: public: virtual void COcclusionSystem::ActivateOccluder(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COcclusionSystem::ActivateOccluder(COcclusionSystem *this, int nOccluderIndex, bool bActive)
{
  doccluderdata_t *v3; // eax

  if ( nOccluderIndex < host_state.worldbrush->numoccluders && nOccluderIndex >= 0 )
  {
    v3 = &host_state.worldbrush->occluders[nOccluderIndex];
    if ( bActive )
      v3->flags &= ~1u;
    else
      v3->flags |= 1u;
    this->m_bEdgeListDirty = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F1D60
// Name: public: virtual void COcclusionSystem::SetView(class Vector const __near &,float,class VMatrix const __near &,class VMatrix const __near &,class VPlane const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COcclusionSystem::SetView(
        COcclusionSystem *this,
        const Vector *vecCameraPos,
        float flFOV,
        const VMatrix *worldToCamera,
        const VMatrix *cameraToProjection,
        const VPlane *nearClipPlane)
{
  double m_Dist; // st7
  float v8; // xmm0_4
  long double v9; // st7
  int m_nTests; // eax

  this->m_vecCameraPosition = *vecCameraPos;
  VMatrix::operator=(this: &this->m_WorldToCamera, mOther: worldToCamera);
  this->m_flXProjScale = -(float)(cameraToProjection->m[2][3] / cameraToProjection->m[0][0]);
  this->m_flYProjScale = -(float)(cameraToProjection->m[2][3] / cameraToProjection->m[1][1]);
  this->m_flProjDistScale = -cameraToProjection->m[2][3];
  this->m_flProjDistOffset = -cameraToProjection->m[2][2];
  MatrixMultiply(src1: cameraToProjection, src2: worldToCamera, dst: &this->m_WorldToProjection);
  this->m_NearClipPlane.normal.x = nearClipPlane->m_Normal.x;
  this->m_NearClipPlane.normal.y = nearClipPlane->m_Normal.y;
  this->m_NearClipPlane.normal.z = nearClipPlane->m_Normal.z;
  m_Dist = nearClipPlane->m_Dist;
  this->m_NearClipPlane.type = 3;
  this->m_NearClipPlane.dist = m_Dist;
  this->m_bEdgeListDirty = true;
  LODWORD(v8) = COERCE_UNSIGNED_INT(
                  (float)((float)((float)(this->m_NearClipPlane.normal.y * vecCameraPos->y)
                                + (float)(vecCameraPos->x * this->m_NearClipPlane.normal.x))
                        + (float)(this->m_NearClipPlane.normal.z * vecCameraPos->z))
                - this->m_NearClipPlane.dist)
              ^ _mask__NegFloat_;
  this->m_flNearPlaneDist = v8;
  v9 = this->m_flNearPlaneDist / (tan(flFOV * 0.5 * 3.141592653589793 * 0.005555555555555556) * v8);
  this->m_flFOVFactor = v9 * v9;
  if ( r_occlusionspew.m_pParent != nullptr && r_occlusionspew.m_pParent->m_Value.m_nValue != 0 )
  {
    m_nTests = this->m_nTests;
    if ( m_nTests != 0 )
    {
      _Msg(a1: "Occl %.2f (%d/%d)\n", (double)this->m_nOccluded / (double)m_nTests * 100.0, this->m_nOccluded, m_nTests);
      this->m_nTests = 0;
      this->m_nOccluded = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F1F00
// Name: public: bool WingedEdgeLessFunc::Less(int const __near &,int const __near &,void __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall WingedEdgeLessFunc::Less(WingedEdgeLessFunc *this, Vector *src1, Vector *src2, float *pCtx)
{
  EdgeInfo_t *v4; // eax
  int m_nMinVert; // edi
  int v6; // ebx
  EdgeInfo_t *v7; // ecx
  float y; // xmm4_4
  float v9; // xmm5_4
  float x; // xmm0_4
  float v12; // xmm1_4
  int v13; // eax
  int v14; // ecx
  Vector *pV1; // [esp+14h] [ebp+8h]
  Vector *pV2; // [esp+18h] [ebp+Ch]

  v4 = &s_pEdges[LODWORD(src1->x)];
  m_nMinVert = v4->m_nMinVert;
  v6 = s_pEdges[LODWORD(src2->x)].m_nMinVert;
  v7 = &s_pEdges[LODWORD(src2->x)];
  pV1 = (Vector *)&pCtx[3 * v4->m_nVert[m_nMinVert]];
  pV2 = (Vector *)&pCtx[3 * v7->m_nVert[v6]];
  y = pV1->y;
  v9 = pV2->y;
  if ( v9 > y )
    return true;
  if ( y > v9 )
    return false;
  x = pV1->x;
  v12 = pV2->x;
  if ( pV2->x > pV1->x )
    return true;
  if ( x > v12 )
    return false;
  v13 = 3 * v4->m_nVert[-m_nMinVert + 1];
  v14 = 3 * v7->m_nVert[-v6 + 1];
  return (float)((float)(pCtx[v14] - v12) * (float)(pCtx[v13 + 1] - y)) >= (float)((float)(pCtx[v14 + 1] - v9)
                                                                                 * (float)(pCtx[v13] - x));
}

//------------------------------------------------------------------------------
// Address: 0x100F1FF0
// Name: public: int CUtlSortVector<int,class WingedEdgeLessFunc>::FindLessOrEqual(int const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<int,WingedEdgeLessFunc>::FindLessOrEqual(
        CUtlSortVector<int,WingedEdgeLessFunc> *this,
        Vector *src)
{
  int v3; // edi
  int v4; // esi
  int *m_pMemory; // [esp+Ch] [ebp-Ch]
  float *pCtx; // [esp+10h] [ebp-8h]
  int start; // [esp+14h] [ebp-4h]

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1\\utlsortvector.h",
         277,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1\\utlsortvector.h",
                            a2: 277,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1\\utlsortvector.h",
      a2: 277);
  }
  v3 = this->m_Size - 1;
  start = 0;
  if ( v3 < 0 )
    return v3;
  pCtx = (float *)this->m_pLessContext;
  m_pMemory = this->m_Memory.m_pMemory;
  while ( 1 )
  {
    v4 = (v3 + start) >> 1;
    if ( !WingedEdgeLessFunc::Less(
            this: (WingedEdgeLessFunc *)&src + 3,
            src1: (Vector *)&m_pMemory[v4],
            src2: src,
            pCtx) )
      break;
    start = v4 + 1;
LABEL_13:
    if ( start > v3 )
      return v3;
  }
  if ( WingedEdgeLessFunc::Less(this: (WingedEdgeLessFunc *)&src + 3, src1: src, src2: (Vector *)&m_pMemory[v4], pCtx) )
  {
    v3 = v4 - 1;
    goto LABEL_13;
  }
  return (v3 + start) >> 1;
}

//------------------------------------------------------------------------------
// Address: 0x100F2190
// Name: public: void CUtlMemory<struct CWingedEdgeList::WingedEdge_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CWingedEdgeList::WingedEdge_t,int>::Grow(
        CUtlMemory<vgui::AnimationController::AnimCommand_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  vgui::AnimationController::AnimCommand_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 48 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (vgui::AnimationController::AnimCommand_t *)_g_pMemAlloc->Realloc_2(
                                                                      this: _g_pMemAlloc,
                                                                      a2: m_pMemory,
                                                                      a3: v7);
    else
      this->m_pMemory = (vgui::AnimationController::AnimCommand_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F2230
// Name: private: bool CWingedEdgeList::AdvanceActiveEdgeList(float)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CWingedEdgeList::AdvanceActiveEdgeList(CWingedEdgeList *this, float flCurrY)
{
  CWingedEdgeList *m_pNextActiveEdge; // eax
  float y; // xmm0_4
  CWingedEdgeList *v4; // edx
  int m_Size; // esi
  int m_nCurrentEdgeIndex; // eax
  CWingedEdgeList::WingedEdge_t *v8; // eax
  float v9; // xmm0_4
  CWingedEdgeList *i; // edx
  float v11; // xmm0_4
  CWingedEdgeList::WingedEdge_t *v12; // ebx
  int v13; // eax
  float v14; // xmm0_4

  m_pNextActiveEdge = (CWingedEdgeList *)this->m_StartTerminal.m_pNextActiveEdge;
  this->m_flNextDiscontinuity = 3.4028235e38;
  if ( m_pNextActiveEdge != (CWingedEdgeList *)&this->m_EndTerminal )
  {
    do
    {
      y = m_pNextActiveEdge->m_StartTerminal.m_vecPositionEnd.y;
      v4 = (CWingedEdgeList *)m_pNextActiveEdge->m_StartTerminal.m_pNextActiveEdge;
      if ( flCurrY < y )
      {
        m_pNextActiveEdge->m_StartTerminal.m_flX = (float)((float)(flCurrY
                                                                 - m_pNextActiveEdge->m_StartTerminal.m_vecPosition.y)
                                                         * m_pNextActiveEdge->m_StartTerminal.m_flDxDy)
                                                 + m_pNextActiveEdge->m_StartTerminal.m_vecPosition.x;
        if ( this->m_flNextDiscontinuity > y )
          this->m_flNextDiscontinuity = y;
      }
      else
      {
        m_pNextActiveEdge->m_StartTerminal.m_pPrevActiveEdge->m_pNextActiveEdge = &v4->m_StartTerminal;
        m_pNextActiveEdge->m_StartTerminal.m_pNextActiveEdge->m_pPrevActiveEdge = m_pNextActiveEdge->m_StartTerminal.m_pPrevActiveEdge;
      }
      m_pNextActiveEdge = v4;
    }
    while ( v4 != (CWingedEdgeList *)&this->m_EndTerminal );
  }
  m_Size = this->m_WingedEdges.m_Size;
  m_nCurrentEdgeIndex = this->m_nCurrentEdgeIndex;
  if ( m_nCurrentEdgeIndex == m_Size )
    return this->m_flNextDiscontinuity != 3.4028235e38;
  v8 = &this->m_WingedEdges.m_Memory.m_pMemory[m_nCurrentEdgeIndex];
  if ( flCurrY < v8->m_vecPosition.y )
  {
LABEL_21:
    v14 = v8->m_vecPosition.y;
    if ( this->m_flNextDiscontinuity > v14 )
      this->m_flNextDiscontinuity = v14;
  }
  else
  {
    while ( 1 )
    {
      v9 = v8->m_vecPositionEnd.y;
      if ( v9 > flCurrY )
      {
        v8->m_flX = (float)((float)(flCurrY - v8->m_vecPosition.y) * v8->m_flDxDy) + v8->m_vecPosition.x;
        if ( this->m_flNextDiscontinuity > v9 )
          this->m_flNextDiscontinuity = v9;
        for ( i = (CWingedEdgeList *)this->m_EndTerminal.m_pPrevActiveEdge;
              i != this;
              i = (CWingedEdgeList *)i->m_StartTerminal.m_pPrevActiveEdge )
        {
          v11 = i->m_StartTerminal.m_flX - v8->m_flX;
          if ( v11 <= 0.0 && (v11 < 0.0 || i->m_StartTerminal.m_flDxDy <= v8->m_flDxDy) )
            break;
        }
        v12 = i->m_StartTerminal.m_pNextActiveEdge;
        v8->m_pNextActiveEdge = v12;
        v8->m_pPrevActiveEdge = &i->m_StartTerminal;
        v12->m_pPrevActiveEdge = v8;
        i->m_StartTerminal.m_pNextActiveEdge = v8;
      }
      v13 = ++this->m_nCurrentEdgeIndex;
      if ( v13 == m_Size )
        break;
      v8 = &this->m_WingedEdges.m_Memory.m_pMemory[v13];
      if ( flCurrY < v8->m_vecPosition.y )
        goto LABEL_21;
    }
  }
  return this->m_flNextDiscontinuity != 3.4028235e38;
}

//------------------------------------------------------------------------------
// Address: 0x100F23B0
// Name: private: bool CWingedEdgeList::IsOccludingActiveEdgeList(class CWingedEdgeList __near &,float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWingedEdgeList::IsOccludingActiveEdgeList(CWingedEdgeList *this, CWingedEdgeList *testList, float y)
{
  CWingedEdgeList *v3; // ebx
  CWingedEdgeList *m_pNextActiveEdge; // eax
  CWingedEdgeList *v6; // edi
  float m_flX; // xmm0_4
  CWingedEdgeList *m_pPrevActiveEdge; // eax
  CWingedEdgeList::WingedEdge_t *i; // eax
  __int16 m_nEnterSurfID; // dx
  CWingedEdgeList::Surface_t *p_m_BackSurface; // edx
  __int16 m_nLeaveSurfID; // si
  CWingedEdgeList::Surface_t *v13; // esi
  float v14; // xmm1_4
  float v15; // xmm2_4
  CWingedEdgeList::WingedEdge_t **p_m_pNextActiveEdge; // edi
  CWingedEdgeList::WingedEdge_t *v17; // edi
  __int16 v18; // ax
  float v19; // xmm0_4
  __int16 v20; // ax
  __int16 v21; // ax
  CWingedEdgeList::WingedEdge_t *pOccluderEdge; // [esp+4h] [ebp-4h]

  v3 = testList;
  m_pNextActiveEdge = (CWingedEdgeList *)testList->m_StartTerminal.m_pNextActiveEdge;
  if ( m_pNextActiveEdge->m_StartTerminal.m_flX >= 1.0 )
    return 1;
  for ( ;
        m_pNextActiveEdge->m_StartTerminal.m_flX <= -1.0;
        m_pNextActiveEdge = (CWingedEdgeList *)m_pNextActiveEdge->m_StartTerminal.m_pNextActiveEdge )
  {
    ;
  }
  v6 = m_pNextActiveEdge;
  if ( m_pNextActiveEdge == (CWingedEdgeList *)&testList->m_EndTerminal )
    return 1;
  m_flX = m_pNextActiveEdge->m_StartTerminal.m_flX;
  m_pPrevActiveEdge = (CWingedEdgeList *)m_pNextActiveEdge->m_StartTerminal.m_pPrevActiveEdge;
  if ( m_pPrevActiveEdge != testList )
  {
    v6 = m_pPrevActiveEdge;
    m_flX = -1.0;
  }
  for ( i = this->m_StartTerminal.m_pNextActiveEdge; m_flX >= i->m_flX; i = i->m_pNextActiveEdge )
    ;
  m_nEnterSurfID = v6->m_StartTerminal.m_nEnterSurfID;
  pOccluderEdge = i;
  if ( m_nEnterSurfID < 0 )
    p_m_BackSurface = &this->m_BackSurface;
  else
    p_m_BackSurface = &testList->m_Surfaces.m_Memory.m_pMemory[m_nEnterSurfID];
  m_nLeaveSurfID = i->m_nLeaveSurfID;
  if ( m_nLeaveSurfID < 0 )
  {
    v13 = &this->m_BackSurface;
  }
  else
  {
    v13 = &this->m_Surfaces.m_Memory.m_pMemory[m_nLeaveSurfID];
    v3 = testList;
  }
  v14 = i->m_flX;
  v15 = v6->m_StartTerminal.m_pNextActiveEdge->m_flX;
  p_m_pNextActiveEdge = &v6->m_StartTerminal.m_pNextActiveEdge;
  if ( (float)((float)(v13->m_Plane.dist - (float)(m_flX * v13->m_Plane.normal.x)) - (float)(v13->m_Plane.normal.y * y)) > (float)((float)(p_m_BackSurface->m_Plane.dist - (float)(p_m_BackSurface->m_Plane.normal.x * m_flX)) - (float)(p_m_BackSurface->m_Plane.normal.y * y)) )
    return 0;
  while ( v15 != 3.4028235e38 )
  {
    if ( v14 != 3.4028235e38 )
    {
      if ( v14 < v15 )
      {
        pOccluderEdge = pOccluderEdge->m_pNextActiveEdge;
        v21 = pOccluderEdge->m_nLeaveSurfID;
        v19 = v14;
        v13 = v21 < 0 ? &this->m_BackSurface : &this->m_Surfaces.m_Memory.m_pMemory[v21];
        v14 = pOccluderEdge->m_flX;
      }
      else
      {
        v17 = *p_m_pNextActiveEdge;
        v18 = v17->m_nEnterSurfID;
        v19 = v15;
        if ( v18 < 0 )
        {
          v20 = v17->m_nLeaveSurfID;
          if ( v20 < 0 )
          {
            v15 = v17->m_pNextActiveEdge->m_flX;
            p_m_pNextActiveEdge = &v17->m_pNextActiveEdge;
            p_m_BackSurface = &this->m_BackSurface;
          }
          else
          {
            p_m_pNextActiveEdge = &v17->m_pNextActiveEdge;
            p_m_BackSurface = &v3->m_Surfaces.m_Memory.m_pMemory[v20];
            v15 = (*p_m_pNextActiveEdge)->m_flX;
          }
        }
        else
        {
          p_m_pNextActiveEdge = &v17->m_pNextActiveEdge;
          p_m_BackSurface = &v3->m_Surfaces.m_Memory.m_pMemory[v18];
          v15 = (*p_m_pNextActiveEdge)->m_flX;
        }
      }
      if ( (float)((float)(v13->m_Plane.dist - (float)(v19 * v13->m_Plane.normal.x)) - (float)(v13->m_Plane.normal.y * y)) <= (float)((float)(p_m_BackSurface->m_Plane.dist - (float)(p_m_BackSurface->m_Plane.normal.x * v19)) - (float)(p_m_BackSurface->m_Plane.normal.y * y)) )
        continue;
    }
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100F25C0
// Name: public: bool CWingedEdgeList::IsOccludingEdgeList(class CWingedEdgeList __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWingedEdgeList::IsOccludingEdgeList(CWingedEdgeList *this, CWingedEdgeList *testList)
{
  CWingedEdgeList::WingedEdge_t *m_pMemory; // ecx
  float y; // xmm0_4
  float v6; // xmm0_4
  float m_flNextDiscontinuity; // xmm7_4
  CWingedEdgeList *v8; // ecx
  CWingedEdgeList *v9; // ecx
  char result; // al
  float flCurrentY; // [esp+14h] [ebp+8h]
  float flCurrentYa; // [esp+14h] [ebp+8h]

  if ( testList->m_WingedEdges.m_Size == 0 )
    return 1;
  m_pMemory = testList->m_WingedEdges.m_Memory.m_pMemory;
  testList->m_nCurrentEdgeIndex = 0;
  y = m_pMemory->m_vecPosition.y;
  testList->m_flNextDiscontinuity = y;
  if ( y <= -1.0 )
    y = -1.0;
  testList->m_flNextDiscontinuity = y;
  testList->m_EndTerminal.m_pPrevActiveEdge = &testList->m_StartTerminal;
  testList->m_StartTerminal.m_pNextActiveEdge = &testList->m_EndTerminal;
  this->m_nCurrentEdgeIndex = 0;
  v6 = this->m_WingedEdges.m_Memory.m_pMemory->m_vecPosition.y;
  this->m_flNextDiscontinuity = v6;
  if ( v6 <= -1.0 )
    v6 = -1.0;
  this->m_flNextDiscontinuity = v6;
  this->m_StartTerminal.m_pNextActiveEdge = &this->m_EndTerminal;
  this->m_EndTerminal.m_pPrevActiveEdge = &this->m_StartTerminal;
  flCurrentY = testList->m_flNextDiscontinuity;
  m_flNextDiscontinuity = flCurrentY;
  if ( v6 > flCurrentY )
    return 0;
  if ( flCurrentY >= 1.0 )
    return 1;
  CWingedEdgeList::AdvanceActiveEdgeList(this: testList, flCurrY: flCurrentY);
  CWingedEdgeList::AdvanceActiveEdgeList(this, flCurrY: flCurrentY);
  if ( CWingedEdgeList::IsOccludingActiveEdgeList(this: v8, testList, y: flCurrentY) != 0 )
  {
    while ( m_flNextDiscontinuity < 1.0 )
    {
      m_flNextDiscontinuity = this->m_flNextDiscontinuity;
      if ( m_flNextDiscontinuity > testList->m_flNextDiscontinuity )
        m_flNextDiscontinuity = testList->m_flNextDiscontinuity;
      flCurrentYa = m_flNextDiscontinuity;
      if ( m_flNextDiscontinuity > 1.0 )
      {
        m_flNextDiscontinuity = 1.0;
        flCurrentYa = 1.0;
      }
      if ( !CWingedEdgeList::AdvanceActiveEdgeList(this: testList, flCurrY: flCurrentYa) )
        break;
      if ( !CWingedEdgeList::AdvanceActiveEdgeList(this, flCurrY: flCurrentYa) )
        return 0;
      result = CWingedEdgeList::IsOccludingActiveEdgeList(this: v9, testList, y: flCurrentYa);
      if ( result == 0 )
        return result;
    }
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100F26F0
// Name: private: void CEdgeList::IntroduceSingleActiveEdge(struct CEdgeList::Edge_t const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEdgeList::IntroduceSingleActiveEdge(CEdgeList *this, const CEdgeList::Edge_t *pEdge, float flCurrY)
{
  CEdgeList::Surface_t *v3; // edx
  CEdgeList::Surface_t *m_pNextSurface; // eax
  double v5; // st7
  float y; // xmm1_4
  CEdgeList::Surface_t *i; // ecx
  double v8; // st4
  double v9; // st7
  double v10; // rt1
  double v11; // st4
  float pEdgea; // [esp+Ch] [ebp+8h]

  v3 = &this->m_Surfaces.m_Memory.m_pMemory[pEdge->m_nSurfID];
  m_pNextSurface = v3->m_pNextSurface;
  if ( m_pNextSurface == nullptr )
  {
    v5 = -0.000001;
    y = v3->m_Plane.normal.y;
    pEdgea = (float)(v3->m_Plane.dist - (float)(pEdge->m_flX * v3->m_Plane.normal.x)) - (float)(y * flCurrY);
    v3->m_flOOz = pEdgea;
    for ( i = this->m_StartSurfTerminal.m_pNextSurface; ; i = i->m_pNextSurface )
    {
      v8 = v5;
      v9 = i->m_flOOz - pEdgea;
      if ( v8 >= v9 )
      {
        v5 = v8;
      }
      else
      {
        v10 = v8;
        v11 = v9;
        v5 = v10;
        if ( v11 >= 0.000001 || i->m_Plane.normal.y < y )
        {
          v3->m_pNextSurface = i;
          v3->m_pPrevSurface = i->m_pPrevSurface;
          i->m_pPrevSurface = v3;
          v3->m_pPrevSurface->m_pNextSurface = v3;
          return;
        }
      }
    }
  }
  m_pNextSurface->m_pPrevSurface = v3->m_pPrevSurface;
  v3->m_pPrevSurface->m_pNextSurface = v3->m_pNextSurface;
  v3->m_pNextSurface = nullptr;
  v3->m_pPrevSurface = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100F27C0
// Name: private: void CEdgeList::IntroduceNewActiveEdges(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEdgeList::IntroduceNewActiveEdges(CEdgeList *this, float y)
{
  int m_nCurrentEdgeIndex; // eax
  int m_Size; // edi
  CEdgeList::Edge_t *v4; // eax
  float v5; // xmm0_4
  CEdgeList::Edge_t *i; // edx
  float v7; // xmm0_4
  CEdgeList::Edge_t *m_pNextActiveEdge; // esi
  int v9; // eax
  float v10; // xmm0_4

  m_nCurrentEdgeIndex = this->m_nCurrentEdgeIndex;
  m_Size = this->m_SortIndices.m_Size;
  if ( m_nCurrentEdgeIndex != m_Size )
  {
    v4 = &this->m_Edges.m_Memory.m_pMemory[this->m_SortIndices.m_Memory.m_pMemory[m_nCurrentEdgeIndex]];
    if ( y < v4->m_vecPosition.y )
    {
LABEL_14:
      v10 = v4->m_vecPosition.y;
      if ( this->m_flNextDiscontinuity > v10 )
        this->m_flNextDiscontinuity = v10;
    }
    else
    {
      while ( 1 )
      {
        v5 = v4->m_vecPositionEnd.y;
        if ( v5 > y )
        {
          v4->m_flX = (float)((float)(y - v4->m_vecPosition.y) * v4->m_flDxDy) + v4->m_vecPosition.x;
          if ( this->m_flNextDiscontinuity > v5 )
            this->m_flNextDiscontinuity = v5;
          for ( i = this->m_EndTerminal.m_pPrevActiveEdge; i != &this->m_StartTerminal; i = i->m_pPrevActiveEdge )
          {
            v7 = i->m_flX - v4->m_flX;
            if ( v7 <= 0.0 && (v7 < 0.0 || i->m_flDxDy <= v4->m_flDxDy) )
              break;
          }
          m_pNextActiveEdge = i->m_pNextActiveEdge;
          v4->m_pNextActiveEdge = m_pNextActiveEdge;
          v4->m_pPrevActiveEdge = i;
          m_pNextActiveEdge->m_pPrevActiveEdge = v4;
          i->m_pNextActiveEdge = v4;
        }
        v9 = ++this->m_nCurrentEdgeIndex;
        if ( v9 == m_Size )
          break;
        v4 = &this->m_Edges.m_Memory.m_pMemory[this->m_SortIndices.m_Memory.m_pMemory[v9]];
        if ( y < v4->m_vecPosition.y )
          goto LABEL_14;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F28D0
// Name: public: int CUtlSortVector<unsigned short,class CEdgeList::EdgeLess>::FindLessOrEqual(unsigned short const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<unsigned short,CEdgeList::EdgeLess>::FindLessOrEqual(
        CUtlSortVector<unsigned short,CEdgeList::EdgeLess> *this,
        const unsigned __int16 *src)
{
  int v3; // edi
  int *m_pLessContext; // eax
  unsigned __int16 *m_pMemory; // ebx
  int v6; // edx
  float v7; // xmm1_4
  int result; // eax
  float v9; // xmm0_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  int v12; // edx
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  int *v17; // [esp+Ch] [ebp-8h]
  int start; // [esp+10h] [ebp-4h]

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1\\utlsortvector.h",
         277,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1\\utlsortvector.h",
                            a2: 277,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1\\utlsortvector.h",
      a2: 277);
  }
  v3 = this->m_Size - 1;
  start = 0;
  if ( v3 >= 0 )
  {
    m_pLessContext = (int *)this->m_pLessContext;
    m_pMemory = this->m_Memory.m_pMemory;
    v17 = m_pLessContext;
    do
    {
      v6 = *v17;
      v7 = *(float *)(*v17 + 48 * *src + 4);
      result = (v3 + start) >> 1;
      v9 = *(float *)(*v17 + 48 * m_pMemory[result] + 4);
      if ( v7 <= v9
        && (v9 > v7
         || (v10 = *(float *)(v6 + 48 * m_pMemory[result]), (v11 = *(float *)(v6 + 48 * *src)) <= v10)
         && (v10 > v11 || *(float *)(v6 + 48 * *src + 24) < *(float *)(v6 + 48 * m_pMemory[result] + 24))) )
      {
        v12 = *v17;
        v13 = *(float *)(*v17 + 48 * *src + 4);
        v14 = *(float *)(*v17 + 48 * m_pMemory[result] + 4);
        if ( v14 <= v13 )
        {
          if ( v13 > v14 )
            return result;
          v15 = *(float *)(v12 + 48 * *src);
          v16 = *(float *)(v12 + 48 * m_pMemory[result]);
          if ( v16 <= v15
            && (v15 > v16 || *(float *)(v12 + 48 * m_pMemory[result] + 24) < *(float *)(v12 + 48 * *src + 24)) )
          {
            return result;
          }
        }
        v3 = result - 1;
      }
      else
      {
        start = result + 1;
      }
    }
    while ( start <= v3 );
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100F2A10
// Name: void VisualizeQueuedEdges(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall VisualizeQueuedEdges(int a1@<ebx>, int a2@<edi>, int a3@<esi>)
{
  int v3; // edi
  IMesh *v4; // esi
  int v5; // ebx
  int v6; // ebx
  int v7; // esi
  float *v8; // esi
  float *m_pCurrPosition; // eax
  float *v10; // ecx
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+0h] [ebp-1F0h] BYREF
  IMesh *pMesh; // [esp+1E8h] [ebp-8h]
  int i; // [esp+1ECh] [ebp-4h]

  if ( g_EdgeVisualization.m_Size != 0 )
  {
    v3 = ((int (__thiscall *)(IMaterialSystem *, int, int, int))materials->GetRenderContext)(
           a1: materials,
           a2,
           a3,
           a4: a1);
    if ( v3 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 8))(a1: v3);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v3 + 80))(a1: v3, a2: 10);
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 84))(a1: v3);
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 124))(a1: v3);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v3 + 80))(a1: v3, a2: 0);
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 84))(a1: v3);
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 124))(a1: v3);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v3 + 80))(a1: v3, a2: 1);
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 84))(a1: v3);
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 124))(a1: v3);
    (*(void (__thiscall **)(int, IMaterial *, _DWORD))(*(_DWORD *)v3 + 36))(
      a1: v3,
      a2: g_pMaterialWireframeVertexColorIgnoreZ,
      a3: 0);
    v4 = (IMesh *)(*(int (__thiscall **)(int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v3 + 228))(
                    a1: v3,
                    a2: 1,
                    a3: 0,
                    a4: 0,
                    a5: 0);
    pMesh = v4;
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v4;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_LINES;
    v5 = 2 * g_EdgeVisualization.m_Size;
    v4->SetPrimitiveType(this: v4, a2: MATERIAL_LINES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: v5, a3: v5, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v4->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = v5;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v4, nMaxVertexCount: v5, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    v6 = g_EdgeVisualization.m_Size - 1;
    if ( g_EdgeVisualization.m_Size - 1 >= 0 )
    {
      v7 = 28 * v6;
      for ( i = 28 * v6; ; v7 = i )
      {
        v8 = (float *)((char *)g_EdgeVisualization.m_Memory.m_pMemory + v7);
        m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = *v8;
        m_pCurrPosition[1] = v8[1];
        m_pCurrPosition[2] = v8[2];
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = *((unsigned __int8 *)v8 + 26)
                                                            | ((*((unsigned __int8 *)v8 + 25)
                                                              | ((*((unsigned __int8 *)v8 + 24)
                                                                | (*((unsigned __int8 *)v8 + 27) << 8)) << 8)) << 8);
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        v10 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v8[3];
        v10[1] = v8[4];
        v10[2] = v8[5];
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = *((unsigned __int8 *)v8 + 26)
                                                            | ((*((unsigned __int8 *)v8 + 25)
                                                              | ((*((unsigned __int8 *)v8 + 24)
                                                                | (*((unsigned __int8 *)v8 + 27) << 8)) << 8)) << 8);
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        i -= 28;
        if ( --v6 < 0 )
          break;
      }
      v4 = pMesh;
    }
    if ( meshBuilder.m_bGenerateIndices )
    {
      switch ( meshBuilder.m_Type )
      {
        case MATERIAL_LINE_STRIP:
          m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
          break;
        case MATERIAL_LINE_LOOP:
          m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
        case MATERIAL_POLYGON:
          m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
          break;
        case MATERIAL_QUADS:
          m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
          break;
        case MATERIAL_INSTANCED_QUADS:
          m_nVertexCount = 0;
          break;
        default:
          m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
      }
      CIndexBuilder::GenerateIndices(
        this: &meshBuilder.m_IndexBuilder,
        primitiveType: meshBuilder.m_Type,
        nIndexCount: m_nVertexCount);
    }
    meshBuilder.m_pMesh->UnlockMesh(
      this: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
      a4: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    v4->Draw_2(this: v4, a2: -1, a3: 0);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v3 + 80))(a1: v3, a2: 10);
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 88))(a1: v3);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v3 + 80))(a1: v3, a2: 0);
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 88))(a1: v3);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v3 + 80))(a1: v3, a2: 1);
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 88))(a1: v3);
    g_EdgeVisualization.m_Size = 0;
    CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 12))(a1: v3);
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 4))(a1: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F2D90
// Name: public: int CUtlSortVector<unsigned short,class CEdgeList::EdgeLess>::Insert(unsigned short const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<unsigned short,CEdgeList::EdgeLess>::Insert(
        CUtlSortVector<unsigned short,CEdgeList::EdgeLess> *this,
        const unsigned __int16 *src)
{
  int LessOrEqual; // eax
  int m_nAllocationCount; // ecx
  int v5; // edi
  int m_Size; // eax
  unsigned __int16 *m_pMemory; // ecx
  int v8; // eax
  unsigned __int16 *v9; // eax

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1\\utlsortvector.h",
         150,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1\\utlsortvector.h",
                            a2: 150,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1\\utlsortvector.h",
      a2: 150);
  }
  LessOrEqual = CUtlSortVector<unsigned short,CEdgeList::EdgeLess>::FindLessOrEqual(this, src);
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  v5 = LessOrEqual + 1;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<wchar_t,int>::Grow((CUtlMemory<wchar_t,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size - v5 - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[v5 + 1], src: &m_pMemory[v5], count: 2 * v8);
  v9 = &this->m_Memory.m_pMemory[v5];
  if ( v9 != nullptr )
    *v9 = *src;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x100F2E60
// Name: public: int CUtlSortVector<int,class WingedEdgeLessFunc>::Insert(int const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<int,WingedEdgeLessFunc>::Insert(
        CUtlSortVector<int,WingedEdgeLessFunc> *this,
        Vector *src)
{
  int LessOrEqual; // eax
  int m_nAllocationCount; // ecx
  int v5; // edi
  int m_Size; // eax
  int *m_pMemory; // ecx
  int v8; // eax
  int *v9; // eax

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1\\utlsortvector.h",
         150,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1\\utlsortvector.h",
                            a2: 150,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1\\utlsortvector.h",
      a2: 150);
  }
  LessOrEqual = CUtlSortVector<int,WingedEdgeLessFunc>::FindLessOrEqual(this, src);
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  v5 = LessOrEqual + 1;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<INetMessage *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size - v5 - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[v5 + 1], src: &m_pMemory[v5], count: 4 * v8);
  v9 = &this->m_Memory.m_pMemory[v5];
  if ( v9 != nullptr )
    *v9 = LODWORD(src->x);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x100F2FC0
// Name: public: CWingedEdgeList::CWingedEdgeList(void)
// Source: json
//------------------------------------------------------------------------------
CWingedEdgeList *__thiscall CWingedEdgeList::CWingedEdgeList(CWingedEdgeList *this)
{
  CWingedEdgeList::WingedEdge_t *v2; // eax

  this->m_WingedEdges.m_Memory.m_pMemory = nullptr;
  this->m_WingedEdges.m_Memory.m_nAllocationCount = 64;
  this->m_WingedEdges.m_Memory.m_nGrowSize = 0;
  v2 = (CWingedEdgeList::WingedEdge_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 3072);
  this->m_WingedEdges.m_Memory.m_pMemory = v2;
  this->m_WingedEdges.m_pElements = v2;
  this->m_WingedEdges.m_Size = 0;
  this->m_Surfaces.m_Memory.m_pMemory = nullptr;
  this->m_Surfaces.m_Memory.m_nAllocationCount = 0;
  this->m_Surfaces.m_Memory.m_nGrowSize = 0;
  this->m_Surfaces.m_Size = 0;
  this->m_Surfaces.m_pElements = nullptr;
  this->m_StartTerminal.m_vecPosition.x = -3.4028235e38;
  this->m_StartTerminal.m_vecPosition.y = -3.4028235e38;
  this->m_StartTerminal.m_vecPosition.z = -3.4028235e38;
  this->m_StartTerminal.m_vecPositionEnd.x = -3.4028235e38;
  this->m_StartTerminal.m_vecPositionEnd.z = -3.4028235e38;
  this->m_StartTerminal.m_vecPositionEnd.y = 3.4028235e38;
  this->m_StartTerminal.m_pPrevActiveEdge = nullptr;
  this->m_StartTerminal.m_pNextActiveEdge = nullptr;
  this->m_StartTerminal.m_flX = -3.4028235e38;
  this->m_StartTerminal.m_flDxDy = 0.0;
  this->m_StartTerminal.m_flOODy = 0.0;
  this->m_StartTerminal.m_nLeaveSurfID = -1;
  this->m_StartTerminal.m_nEnterSurfID = -1;
  this->m_EndTerminal.m_vecPosition.y = -3.4028235e38;
  this->m_EndTerminal.m_vecPosition.z = -3.4028235e38;
  this->m_EndTerminal.m_vecPosition.x = 3.4028235e38;
  this->m_EndTerminal.m_vecPositionEnd.z = -3.4028235e38;
  this->m_EndTerminal.m_vecPositionEnd.x = 3.4028235e38;
  this->m_EndTerminal.m_vecPositionEnd.y = 3.4028235e38;
  this->m_EndTerminal.m_nLeaveSurfID = -1;
  this->m_EndTerminal.m_pPrevActiveEdge = nullptr;
  this->m_EndTerminal.m_pNextActiveEdge = nullptr;
  this->m_EndTerminal.m_flDxDy = 0.0;
  this->m_EndTerminal.m_flOODy = 0.0;
  this->m_EndTerminal.m_flX = 3.4028235e38;
  this->m_EndTerminal.m_nEnterSurfID = -1;
  this->m_BackSurface.m_Plane.normal.x = 0.0;
  this->m_BackSurface.m_Plane.normal.y = 0.0;
  this->m_BackSurface.m_Plane.normal.z = 1.0;
  this->m_BackSurface.m_Plane.dist = 3.4028235e38;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100F30D0
// Name: public: COcclusionSystem::~COcclusionSystem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COcclusionSystem::~COcclusionSystem(COcclusionSystem *this)
{
  this->__vftable = (COcclusionSystem_vtbl *)&COcclusionSystem::`vftable';
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_ClippedVerts);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_WingedEdgeList.m_Surfaces);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_WingedEdgeList.m_WingedEdges);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_EdgeList.m_SurfaceSort);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_EdgeList.m_Surfaces);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_EdgeList.m_SortIndices);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_EdgeList.m_OrigSortIndices);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_EdgeList);
}

//------------------------------------------------------------------------------
// Address: 0x100F31A0
// Name: public: int CWingedEdgeList::AddEdge(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWingedEdgeList::AddEdge(CWingedEdgeList *this)
{
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::AnimationController::AnimCommand_t,int> *p_m_WingedEdges; // esi
  int m_Size; // edi
  vgui::AnimationController::AnimCommand_t *m_pMemory; // ecx
  int v5; // eax
  int v6; // eax

  m_nAllocationCount = this->m_WingedEdges.m_Memory.m_nAllocationCount;
  p_m_WingedEdges = (CUtlMemory<vgui::AnimationController::AnimCommand_t,int> *)&this->m_WingedEdges;
  m_Size = this->m_WingedEdges.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CWingedEdgeList::WingedEdge_t,int>::Grow(this: p_m_WingedEdges, num: m_Size - m_nAllocationCount + 1);
  ++p_m_WingedEdges[1].m_pMemory;
  m_pMemory = p_m_WingedEdges->m_pMemory;
  v5 = (int)p_m_WingedEdges[1].m_pMemory - m_Size - 1;
  p_m_WingedEdges[1].m_nAllocationCount = (int)p_m_WingedEdges->m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 48 * v5);
  v6 = (int)&p_m_WingedEdges->m_pMemory[m_Size];
  *(_DWORD *)(v6 + 40) = 0;
  *(_DWORD *)(v6 + 44) = 0;
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x100F3210
// Name: public: int CWingedEdgeList::AddSurface(struct cplane_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWingedEdgeList::AddSurface(CWingedEdgeList *this, const cplane_t *plane)
{
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *p_m_Surfaces; // esi
  int m_Size; // edi
  vgui::CTreeViewListControl::CColumnInfo *m_pMemory; // ecx
  int v6; // eax

  m_nAllocationCount = this->m_Surfaces.m_Memory.m_nAllocationCount;
  p_m_Surfaces = (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)&this->m_Surfaces;
  m_Size = this->m_Surfaces.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<void *,int>,int>::Grow(this: p_m_Surfaces, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Surfaces[1].m_pMemory;
  m_pMemory = p_m_Surfaces->m_pMemory;
  v6 = (int)p_m_Surfaces[1].m_pMemory - m_Size - 1;
  p_m_Surfaces[1].m_nAllocationCount = (int)p_m_Surfaces->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 20 * v6);
  p_m_Surfaces->m_pMemory[m_Size] = (vgui::CTreeViewListControl::CColumnInfo)*plane;
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x100F32B0
// Name: public: void CWingedEdgeList::QueueVisualization(unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWingedEdgeList::QueueVisualization(CWingedEdgeList *this, unsigned __int8 *pColor)
{
  int inserted; // eax
  int v4; // edx
  int v5; // esi
  int v7; // eax
  int v8; // esi
  CWingedEdgeList::WingedEdge_t *m_pMemory; // ecx
  EdgeVisualizationInfo_t *v10; // edx
  float *p_x; // ecx
  EdgeVisualizationInfo_t *v12; // edx
  CWingedEdgeList::WingedEdge_t *v13; // edx
  EdgeVisualizationInfo_t *v14; // ecx
  float *v15; // edx
  int v16; // ecx
  CWingedEdgeList::WingedEdge_t *v17; // ecx
  double x; // st7
  float *v19; // edx
  EdgeVisualizationInfo_t *v20; // ecx
  int v21; // ecx
  CWingedEdgeList::WingedEdge_t *v22; // ecx
  double v23; // st7
  float *v24; // ecx
  EdgeVisualizationInfo_t *v25; // edx
  int v26; // edx
  bool v27; // zf
  int v28; // ecx
  int v29; // esi
  CWingedEdgeList::WingedEdge_t *v30; // eax
  double v31; // st7
  float *v32; // eax
  EdgeVisualizationInfo_t *v33; // ecx
  EdgeVisualizationInfo_t *v34; // ecx
  int nFirst; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]
  int ia; // [esp+8h] [ebp-4h]
  unsigned __int8 *pColora; // [esp+14h] [ebp+8h]
  unsigned __int8 *pColorb; // [esp+14h] [ebp+8h]

  if ( r_visocclusion.m_pParent != nullptr && r_visocclusion.m_pParent->m_Value.m_nValue != 0 )
  {
    inserted = CUtlVector<EdgeVisualizationInfo_t,CUtlMemory<EdgeVisualizationInfo_t,int>>::InsertMultipleBefore(
                 this: &g_EdgeVisualization,
                 elem: g_EdgeVisualization.m_Size,
                 num: this->m_WingedEdges.m_Size);
    v4 = this->m_WingedEdges.m_Size - 1;
    v5 = inserted;
    nFirst = inserted;
    if ( v4 >= 0 )
    {
      i = this->m_WingedEdges.m_Size;
      if ( i >= 4 )
      {
        pColora = (unsigned __int8 *)((unsigned int)i >> 2);
        v7 = v4;
        v8 = v4 + v5;
        ia = v4 - 4 * ((unsigned int)i >> 2);
        do
        {
          m_pMemory = this->m_WingedEdges.m_Memory.m_pMemory;
          v10 = g_EdgeVisualization.m_Memory.m_pMemory;
          g_EdgeVisualization.m_Memory.m_pMemory[v8].m_vecPoint[0].x = m_pMemory[v7].m_vecPosition.x;
          p_x = &m_pMemory[v7].m_vecPosition.x;
          v12 = &v10[v8];
          v12->m_vecPoint[0].y = p_x[1];
          v12->m_vecPoint[0].z = p_x[2];
          v12->m_vecPoint[1].x = p_x[3];
          v12->m_vecPoint[1].y = p_x[4];
          v12->m_vecPoint[1].z = p_x[5];
          *(_DWORD *)v12->m_pColor = *(_DWORD *)pColor;
          v13 = this->m_WingedEdges.m_Memory.m_pMemory;
          v14 = g_EdgeVisualization.m_Memory.m_pMemory;
          g_EdgeVisualization.m_Memory.m_pMemory[v8 - 1].m_vecPoint[0].x = v13[v7 - 1].m_vecPosition.x;
          v15 = &v13[v7 - 1].m_vecPosition.x;
          v16 = (int)&v14[v8 - 1];
          *(float *)(v16 + 4) = v15[1];
          *(float *)(v16 + 8) = v15[2];
          *(float *)(v16 + 12) = v15[3];
          *(float *)(v16 + 16) = v15[4];
          *(float *)(v16 + 20) = v15[5];
          *(_DWORD *)(v16 + 24) = *(_DWORD *)pColor;
          v17 = this->m_WingedEdges.m_Memory.m_pMemory;
          x = v17[v7 - 2].m_vecPosition.x;
          v19 = &v17[v7 - 2].m_vecPosition.x;
          v20 = g_EdgeVisualization.m_Memory.m_pMemory;
          g_EdgeVisualization.m_Memory.m_pMemory[v8 - 2].m_vecPoint[0].x = x;
          v21 = (int)&v20[v8 - 2];
          *(float *)(v21 + 4) = v19[1];
          *(float *)(v21 + 8) = v19[2];
          *(float *)(v21 + 12) = v19[3];
          *(float *)(v21 + 16) = v19[4];
          *(float *)(v21 + 20) = v19[5];
          *(_DWORD *)(v21 + 24) = *(_DWORD *)pColor;
          v22 = this->m_WingedEdges.m_Memory.m_pMemory;
          v23 = v22[v7 - 3].m_vecPosition.x;
          v24 = &v22[v7 - 3].m_vecPosition.x;
          v25 = g_EdgeVisualization.m_Memory.m_pMemory;
          g_EdgeVisualization.m_Memory.m_pMemory[v8 - 3].m_vecPoint[0].x = v23;
          v26 = (int)&v25[v8 - 3];
          *(float *)(v26 + 4) = v24[1];
          v8 -= 4;
          v7 -= 4;
          v27 = pColora-- == (unsigned __int8 *)1;
          *(float *)(v26 + 8) = v24[2];
          *(float *)(v26 + 12) = v24[3];
          *(float *)(v26 + 16) = v24[4];
          *(float *)(v26 + 20) = v24[5];
          *(_DWORD *)(v26 + 24) = *(_DWORD *)pColor;
        }
        while ( !v27 );
        v4 = ia;
        v5 = nFirst;
      }
      if ( v4 >= 0 )
      {
        v28 = 48 * v4;
        pColorb = (unsigned __int8 *)(48 * v4);
        v29 = v4 + v5;
        do
        {
          v30 = this->m_WingedEdges.m_Memory.m_pMemory;
          v31 = *(float *)((char *)&v30->m_vecPosition.x + v28);
          v32 = (float *)((char *)&v30->m_vecPosition.x + v28);
          v33 = g_EdgeVisualization.m_Memory.m_pMemory;
          g_EdgeVisualization.m_Memory.m_pMemory[v29].m_vecPoint[0].x = v31;
          v34 = &v33[v29];
          v34->m_vecPoint[0].y = v32[1];
          --v29;
          v34->m_vecPoint[0].z = v32[2];
          v34->m_vecPoint[1].x = v32[3];
          v34->m_vecPoint[1].y = v32[4];
          v34->m_vecPoint[1].z = v32[5];
          *(_DWORD *)v34->m_pColor = *(_DWORD *)pColor;
          v28 = (int)(pColorb - 48);
          --v4;
          pColorb -= 48;
        }
        while ( v4 >= 0 );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F34B0
// Name: public: CEdgeList::CEdgeList(void)
// Source: json
//------------------------------------------------------------------------------
CEdgeList *__thiscall CEdgeList::CEdgeList(CEdgeList *this)
{
  CEdgeList::Edge_t *v2; // eax
  unsigned __int16 *v3; // eax

  this->m_Edges.m_Memory.m_pMemory = nullptr;
  this->m_Edges.m_Memory.m_nAllocationCount = 32;
  this->m_Edges.m_Memory.m_nGrowSize = 0;
  v2 = (CEdgeList::Edge_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 1536);
  this->m_Edges.m_Memory.m_pMemory = v2;
  this->m_Edges.m_pElements = v2;
  this->m_Edges.m_Size = 0;
  this->m_OrigSortIndices.m_Memory.m_pMemory = nullptr;
  this->m_OrigSortIndices.m_Memory.m_nAllocationCount = 32;
  this->m_OrigSortIndices.m_Memory.m_nGrowSize = 0;
  v3 = (unsigned __int16 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 64);
  this->m_OrigSortIndices.m_Memory.m_pMemory = v3;
  this->m_OrigSortIndices.m_pElements = v3;
  this->m_OrigSortIndices.m_Size = 0;
  this->m_OrigSortIndices.m_bNeedsSort = false;
  this->m_SortIndices.m_Memory.m_pMemory = nullptr;
  this->m_SortIndices.m_Memory.m_nAllocationCount = 0;
  this->m_SortIndices.m_Memory.m_nGrowSize = 0;
  this->m_SortIndices.m_Size = 0;
  this->m_SortIndices.m_pElements = nullptr;
  this->m_Surfaces.m_Memory.m_pMemory = nullptr;
  this->m_Surfaces.m_Memory.m_nAllocationCount = 0;
  this->m_Surfaces.m_Memory.m_nGrowSize = 0;
  this->m_Surfaces.m_Size = 0;
  this->m_Surfaces.m_pElements = nullptr;
  this->m_SurfaceSort.m_Memory.m_pMemory = nullptr;
  this->m_SurfaceSort.m_Memory.m_nAllocationCount = 0;
  this->m_SurfaceSort.m_Memory.m_nGrowSize = 0;
  this->m_SurfaceSort.m_Size = 0;
  this->m_SurfaceSort.m_pElements = nullptr;
  this->m_OrigSortIndices.m_pLessContext = this;
  this->m_StartTerminal.m_vecPosition.x = -3.4028235e38;
  this->m_StartTerminal.m_vecPosition.y = -3.4028235e38;
  this->m_StartTerminal.m_vecPosition.z = -3.4028235e38;
  this->m_StartTerminal.m_vecPositionEnd.x = -3.4028235e38;
  this->m_StartTerminal.m_vecPositionEnd.y = 3.4028235e38;
  this->m_StartTerminal.m_vecPositionEnd.z = -3.4028235e38;
  this->m_StartTerminal.m_pPrevActiveEdge = nullptr;
  this->m_StartTerminal.m_pNextActiveEdge = nullptr;
  this->m_StartTerminal.m_flDxDy = 0.0;
  this->m_StartTerminal.m_flOODy = 0.0;
  this->m_StartTerminal.m_flX = -3.4028235e38;
  this->m_StartTerminal.m_nSurfID = -1;
  this->m_EndTerminal.m_vecPosition.x = 3.4028235e38;
  this->m_EndTerminal.m_vecPosition.y = -3.4028235e38;
  this->m_EndTerminal.m_vecPosition.z = -3.4028235e38;
  this->m_EndTerminal.m_vecPositionEnd.x = 3.4028235e38;
  this->m_EndTerminal.m_vecPositionEnd.y = 3.4028235e38;
  this->m_EndTerminal.m_vecPositionEnd.z = -3.4028235e38;
  this->m_EndTerminal.m_nSurfID = -1;
  this->m_EndTerminal.m_pPrevActiveEdge = nullptr;
  this->m_EndTerminal.m_pNextActiveEdge = nullptr;
  this->m_EndTerminal.m_flDxDy = 0.0;
  this->m_EndTerminal.m_flOODy = 0.0;
  this->m_EndTerminal.m_flX = 3.4028235e38;
  this->m_StartSurfTerminal.m_flOOz = -3.4028235e38;
  this->m_StartSurfTerminal.m_Plane.normal.x = 0.0;
  this->m_StartSurfTerminal.m_Plane.normal.y = 0.0;
  this->m_StartSurfTerminal.m_Plane.normal.z = 1.0;
  this->m_StartSurfTerminal.m_Plane.dist = -3.4028235e38;
  this->m_StartSurfTerminal.m_nSurfID = -1;
  this->m_StartSurfTerminal.m_pNextSurface = nullptr;
  this->m_StartSurfTerminal.m_pPrevSurface = nullptr;
  this->m_EndSurfTerminal.m_flOOz = 3.4028235e38;
  this->m_EndSurfTerminal.m_Plane.normal.x = 0.0;
  this->m_EndSurfTerminal.m_Plane.normal.y = 0.0;
  this->m_EndSurfTerminal.m_Plane.normal.z = 1.0;
  this->m_EndSurfTerminal.m_nSurfID = -1;
  this->m_EndSurfTerminal.m_pNextSurface = nullptr;
  this->m_EndSurfTerminal.m_pPrevSurface = nullptr;
  this->m_EndSurfTerminal.m_Plane.dist = 3.4028235e38;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100F3680
// Name: public: int CEdgeList::AddSurface(struct cplane_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEdgeList::AddSurface(CEdgeList *this, const cplane_t *plane)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CEdgeList::Surface_t *m_pMemory; // ecx
  int v6; // eax
  CEdgeList::Surface_t *v7; // eax
  CUtlMemory<S3RGBA,int> *p_m_SurfaceSort; // esi
  int v9; // ebx
  int v10; // eax
  S3RGBA *v11; // ecx
  int v12; // eax
  int *v13; // ebx
  int result; // eax

  m_nAllocationCount = this->m_Surfaces.m_Memory.m_nAllocationCount;
  m_Size = this->m_Surfaces.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CEdgeList::Surface_t,int>::Grow(this: &this->m_Surfaces.m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Surfaces.m_Size;
  m_pMemory = this->m_Surfaces.m_Memory.m_pMemory;
  v6 = this->m_Surfaces.m_Size - m_Size - 1;
  this->m_Surfaces.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 40 * v6);
  v7 = &this->m_Surfaces.m_Memory.m_pMemory[m_Size];
  v7->m_flOOz = 0.0;
  v7->m_Plane = *plane;
  p_m_SurfaceSort = (CUtlMemory<S3RGBA,int> *)&this->m_SurfaceSort;
  v7->m_pNextSurface = nullptr;
  v7->m_pPrevSurface = nullptr;
  v7->m_nSurfID = m_Size;
  v9 = this->m_SurfaceSort.m_Size;
  v10 = p_m_SurfaceSort->m_nAllocationCount;
  if ( v9 + 1 > v10 )
    CUtlMemory<INetMessage *,int>::Grow(this: p_m_SurfaceSort, num: v9 - v10 + 1);
  ++p_m_SurfaceSort[1].m_pMemory;
  v11 = p_m_SurfaceSort->m_pMemory;
  v12 = (int)p_m_SurfaceSort[1].m_pMemory - v9 - 1;
  p_m_SurfaceSort[1].m_nAllocationCount = (int)p_m_SurfaceSort->m_pMemory;
  if ( v12 > 0 )
    _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
  v13 = (int *)&p_m_SurfaceSort->m_pMemory[v9];
  result = m_Size;
  if ( v13 != nullptr )
    *v13 = m_Size;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F37A0
// Name: public: void CEdgeList::AddEdge(class Vector __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEdgeList::AddEdge(CEdgeList *this, float ppEdgeVertices, int nSurfID)
{
  unsigned int v4; // ecx
  Vector *v5; // esi
  Vector *v6; // edi
  int v7; // eax
  int v8; // edx
  CEdgeList::Edge_t *v9; // ecx

  v4 = 4
     * (*(float *)(*(_DWORD *)LODWORD(ppEdgeVertices) + 4) >= *(float *)(*(_DWORD *)(LODWORD(ppEdgeVertices) + 4) + 4));
  v5 = *(Vector **)(v4 + LODWORD(ppEdgeVertices));
  v6 = *(Vector **)(LODWORD(ppEdgeVertices) - v4 + 4);
  ppEdgeVertices = v6->y - v5->y;
  if ( ppEdgeVertices != 0.0 )
  {
    v7 = CUtlVector<CEdgeList::Edge_t,CUtlMemory<CEdgeList::Edge_t,int>>::AddToTail(this: &this->m_Edges);
    v8 = nSurfID;
    v9 = &this->m_Edges.m_Memory.m_pMemory[v7];
    v9->m_flOODy = 1.0 / ppEdgeVertices;
    LODWORD(ppEdgeVertices) = (unsigned __int16)v7;
    v9->m_vecPosition.x = v5->x;
    v9->m_vecPosition.y = v5->y;
    v9->m_vecPosition.z = v5->z;
    v9->m_vecPositionEnd.x = v6->x;
    v9->m_vecPositionEnd.y = v6->y;
    v9->m_vecPositionEnd.z = v6->z;
    v9->m_nSurfID = v8;
    v9->m_flDxDy = (float)(v6->x - v5->x) * v9->m_flOODy;
    v9->m_pPrevActiveEdge = nullptr;
    v9->m_pNextActiveEdge = nullptr;
    CUtlSortVector<unsigned short,CEdgeList::EdgeLess>::Insert(
      this: &this->m_OrigSortIndices,
      src: (const unsigned __int16 *)&ppEdgeVertices);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F3870
// Name: public: void CEdgeList::CullSmallOccluders(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEdgeList::CullSmallOccluders(CEdgeList *this)
{
  CEdgeList *v1; // edi
  int m_Size; // esi
  void *v3; // esp
  int v4; // xmm0_4
  int v5; // edx
  CEdgeList::Surface_t *v6; // esi
  int *v7; // eax
  _DWORD *v8; // eax
  int v9; // ecx
  int v10; // ecx
  CEdgeList::Surface_t *v11; // ecx
  int v12; // eax
  int v13; // eax
  CUtlMemory<wchar_t,int> *p_m_SortIndices; // esi
  IMemAlloc_vtbl *v15; // edx
  int v16; // eax
  int v17; // ecx
  CEdgeList::Edge_t *v18; // edx
  wchar_t *v19; // edi
  int m_nAllocationCount; // eax
  wchar_t *v21; // ecx
  int v22; // eax
  wchar_t *v23; // edi
  int *m_pMemory; // [esp-10h] [ebp-34h]
  int v25; // [esp-4h] [ebp-28h]
  unsigned __int8 v26[12]; // [esp+0h] [ebp-24h] BYREF
  int nEdgeIndex; // [esp+Ch] [ebp-18h]
  int i; // [esp+10h] [ebp-14h]
  CEdgeList::Surface_t *v29; // [esp+14h] [ebp-10h]
  int nEdgeCount; // [esp+18h] [ebp-Ch]
  CEdgeList *v31; // [esp+1Ch] [ebp-8h]
  int nMinSurfaces; // [esp+20h] [ebp-4h]

  v1 = this;
  m_Size = this->m_Surfaces.m_Size;
  CEdgeList::s_pSortSurfaces = this->m_Surfaces.m_Memory.m_pMemory;
  m_pMemory = this->m_SurfaceSort.m_Memory.m_pMemory;
  v31 = this;
  nEdgeIndex = m_Size;
  qsort(
    base: m_pMemory,
    num: m_Size,
    width: 4u,
    comp: (int (__cdecl *)(const void *, const void *))CEdgeList::SurfCompare);
  if ( r_occludermincount.m_pParent != nullptr )
    nMinSurfaces = r_occludermincount.m_pParent->m_Value.m_nValue;
  else
    nMinSurfaces = 0;
  *(float *)&i = r_occluderminarea.m_pParent->m_Value.m_fValue * 0.02;
  if ( *(float *)&i == 0.0 )
    *(float *)&i = ((double (__thiscall *)(COcclusionSystem *))g_OcclusionSystem.MinOccluderArea)(a1: &g_OcclusionSystem)
                 * 0.02;
  v3 = alloca(m_Size);
  memset(dst: v26, value: 0, count: m_Size);
  v4 = i;
  v5 = 0;
  if ( m_Size < 4 )
  {
LABEL_20:
    if ( v5 < m_Size )
    {
      v11 = v1->m_Surfaces.m_Memory.m_pMemory;
      i = (int)&v1->m_SurfaceSort.m_Memory.m_pMemory[v5];
      do
      {
        v12 = *(_DWORD *)i;
        if ( *(float *)&v4 > v11[*(_DWORD *)i].m_flArea && v5 >= nMinSurfaces )
          break;
        i += 4;
        ++v5;
        v26[v12] = 1;
      }
      while ( v5 < m_Size );
LABEL_25:
      v1 = v31;
    }
  }
  else
  {
    v6 = v1->m_Surfaces.m_Memory.m_pMemory;
    v7 = v1->m_SurfaceSort.m_Memory.m_pMemory;
    v29 = v6;
    nEdgeCount = 2;
    v8 = v7 + 2;
    while ( *(float *)&v4 <= v6[*(v8 - 2)].m_flArea || v5 < nMinSurfaces )
    {
      v26[*(v8 - 2)] = 1;
      v9 = *(v8 - 1);
      if ( *(float *)&v4 > v6[v9].m_flArea )
      {
        if ( nEdgeCount - 1 >= nMinSurfaces )
          goto LABEL_25;
        v6 = v29;
      }
      v26[v9] = 1;
      if ( *(float *)&v4 > v6[*v8].m_flArea )
      {
        if ( nEdgeCount >= nMinSurfaces )
          goto LABEL_25;
        v6 = v29;
      }
      v26[*v8] = 1;
      v10 = v8[1];
      if ( *(float *)&v4 > v6[v10].m_flArea && nEdgeCount + 1 >= nMinSurfaces )
        goto LABEL_25;
      m_Size = nEdgeIndex;
      nEdgeCount += 4;
      v1 = v31;
      v26[v10] = 1;
      v5 += 4;
      v8 += 4;
      if ( v5 >= m_Size - 3 )
        goto LABEL_20;
      v6 = v29;
    }
  }
  v13 = v1->m_OrigSortIndices.m_Size;
  p_m_SortIndices = (CUtlMemory<wchar_t,int> *)&v1->m_SortIndices;
  v1->m_SortIndices.m_Size = 0;
  nEdgeCount = v13;
  if ( v1->m_SortIndices.m_Memory.m_nAllocationCount < v13 && v1->m_SortIndices.m_Memory.m_nGrowSize >= 0 )
  {
    v1->m_SortIndices.m_Memory.m_nAllocationCount = v13;
    v15 = _g_pMemAlloc->__vftable;
    v25 = 2 * v13;
    if ( p_m_SortIndices->m_pMemory != nullptr )
      v16 = ((int (__stdcall *)(wchar_t *, int))v15->Realloc_2)(a1: p_m_SortIndices->m_pMemory, a2: v25);
    else
      v16 = ((int (__stdcall *)(int))v15->Alloc_2)(a1: v25);
    p_m_SortIndices->m_pMemory = (wchar_t *)v16;
    v13 = nEdgeCount;
  }
  v1->m_SortIndices.m_pElements = v1->m_SortIndices.m_Memory.m_pMemory;
  v17 = 0;
  for ( *(float *)&i = 0.0; v17 < v13; i = v17 )
  {
    v18 = v1->m_Edges.m_Memory.m_pMemory;
    nEdgeIndex = v1->m_OrigSortIndices.m_Memory.m_pMemory[v17];
    if ( v26[v18[nEdgeIndex].m_nSurfID] != 0 )
    {
      v19 = p_m_SortIndices[1].m_pMemory;
      m_nAllocationCount = p_m_SortIndices->m_nAllocationCount;
      if ( (int)v19 + 1 > m_nAllocationCount )
        CUtlMemory<wchar_t,int>::Grow(this: p_m_SortIndices, num: (int)v19 - m_nAllocationCount + 1);
      ++p_m_SortIndices[1].m_pMemory;
      v21 = p_m_SortIndices->m_pMemory;
      v22 = (char *)p_m_SortIndices[1].m_pMemory - (char *)v19 - 1;
      p_m_SortIndices[1].m_nAllocationCount = (int)p_m_SortIndices->m_pMemory;
      if ( v22 > 0 )
        _V_memmove(dest: &v21[(_DWORD)v19 + 1], src: &v21[(_DWORD)v19], count: 2 * v22);
      v23 = &p_m_SortIndices->m_pMemory[(_DWORD)v19];
      v13 = nEdgeCount;
      if ( v23 != nullptr )
        *v23 = nEdgeIndex;
      v1 = v31;
    }
    v17 = i + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F3AF0
// Name: private: void CEdgeList::ReduceActiveEdgeList(class CWingedEdgeList __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEdgeList::ReduceActiveEdgeList(
        CEdgeList *this,
        CWingedEdgeList *wingedEdgeList,
        float flMinY,
        float flMaxY)
{
  CEdgeList::Edge_t *m_pNextActiveEdge; // esi
  float m_flX; // xmm1_4
  int v7; // ebx
  float v8; // xmm3_4
  float v9; // xmm4_4
  float v10; // xmm0_4
  CEdgeList::Surface_t *i; // eax
  CEdgeList::Edge_t *v12; // ecx
  int m_nSurfID; // eax
  int v14; // edx
  __int16 *p_m_nWingedEdge; // eax
  CWingedEdgeList::WingedEdge_t *v16; // ecx
  const CEdgeList::Edge_t *m_pEdge; // eax
  float v18; // xmm2_4
  int v19; // eax
  CEdgeList::ReduceInfo_t *v20; // ecx
  int v21; // eax
  CWingedEdgeList::WingedEdge_t *m_pMemory; // ecx
  int v23; // ebx
  float *p_x; // ecx
  float v25; // xmm1_4
  float v26; // xmm1_4
  __int16 v27; // dx
  CWingedEdgeList::WingedEdge_t *v28; // eax
  bool v29; // zf
  float *v30; // ebx
  int m_nNewReduceCount; // eax
  CEdgeList::ReduceInfo_t *v32; // ecx
  float flPrevX; // [esp+18h] [ebp-18h]
  __int16 *v34; // [esp+1Ch] [ebp-14h]
  int nEnterSurfID; // [esp+20h] [ebp-10h]
  const CEdgeList::Edge_t *pNextEdge; // [esp+24h] [ebp-Ch]
  int nEdgeSurfID; // [esp+28h] [ebp-8h]
  int nLeaveSurfID; // [esp+2Ch] [ebp-4h]

  m_pNextActiveEdge = this->m_StartTerminal.m_pNextActiveEdge;
  m_flX = m_pNextActiveEdge->m_flX;
  v7 = -1;
  nLeaveSurfID = -1;
  if ( m_pNextActiveEdge == &this->m_EndTerminal )
    return;
  v8 = flMaxY;
  v9 = flMinY;
  do
  {
    v10 = m_pNextActiveEdge->m_flX;
    if ( v10 != m_flX )
    {
      for ( i = this->m_StartSurfTerminal.m_pNextSurface; i != &this->m_EndSurfTerminal; i = i->m_pNextSurface )
        i->m_flOOz = (float)(i->m_Plane.dist - (float)(i->m_Plane.normal.x * v10)) - (float)(i->m_Plane.normal.y * v9);
    }
    CEdgeList::IntroduceSingleActiveEdge(this, pEdge: m_pNextActiveEdge, flCurrY: flMinY);
    m_flX = m_pNextActiveEdge->m_flX;
    v12 = m_pNextActiveEdge->m_pNextActiveEdge;
    flPrevX = m_flX;
    pNextEdge = v12;
    if ( m_flX == v12->m_flX && m_pNextActiveEdge->m_flDxDy == v12->m_flDxDy )
      goto LABEL_30;
    m_nSurfID = this->m_StartSurfTerminal.m_pNextSurface->m_nSurfID;
    nEnterSurfID = m_nSurfID;
    if ( v7 == m_nSurfID )
      goto LABEL_30;
    nEdgeSurfID = this->m_StartSurfTerminal.m_pNextSurface->m_nSurfID;
    if ( m_nSurfID == -1 )
      nEdgeSurfID = v7;
    v14 = this->m_nPrevReduceCount - 1;
    if ( v14 < 0 )
    {
LABEL_23:
      v21 = CWingedEdgeList::AddEdge(this: wingedEdgeList);
      m_pMemory = wingedEdgeList->m_WingedEdges.m_Memory.m_pMemory;
      v9 = flMinY;
      v8 = flMaxY;
      v23 = v21;
      m_pMemory[v23].m_nLeaveSurfID = nLeaveSurfID;
      m_pMemory[v23].m_nEnterSurfID = nEnterSurfID;
      m_pMemory[v23].m_flDxDy = m_pNextActiveEdge->m_flDxDy;
      p_x = &m_pMemory[v21].m_vecPosition.x;
      v25 = (float)((float)((float)(flMinY - m_pNextActiveEdge->m_vecPosition.y) * m_pNextActiveEdge->m_flOODy)
                  * (float)(m_pNextActiveEdge->m_vecPositionEnd.x - m_pNextActiveEdge->m_vecPosition.x))
          + m_pNextActiveEdge->m_vecPosition.x;
      *p_x = v25;
      p_x[1] = flMinY;
      p_x[2] = (float)(this->m_Surfaces.m_Memory.m_pMemory[nEdgeSurfID].m_Plane.dist
                     - (float)(this->m_Surfaces.m_Memory.m_pMemory[nEdgeSurfID].m_Plane.normal.x * v25))
             - (float)(this->m_Surfaces.m_Memory.m_pMemory[nEdgeSurfID].m_Plane.normal.y * flMinY);
      v26 = (float)((float)((float)(flMaxY - m_pNextActiveEdge->m_vecPosition.y) * m_pNextActiveEdge->m_flOODy)
                  * (float)(m_pNextActiveEdge->m_vecPositionEnd.x - m_pNextActiveEdge->m_vecPosition.x))
          + m_pNextActiveEdge->m_vecPosition.x;
      p_x[3] = v26;
      p_x[4] = flMaxY;
      v27 = v21;
      p_x[5] = (float)(this->m_Surfaces.m_Memory.m_pMemory[nEdgeSurfID].m_Plane.dist
                     - (float)(this->m_Surfaces.m_Memory.m_pMemory[nEdgeSurfID].m_Plane.normal.x * v26))
             - (float)(this->m_Surfaces.m_Memory.m_pMemory[nEdgeSurfID].m_Plane.normal.y * flMaxY);
      if ( v21 != 0 )
      {
        v28 = wingedEdgeList->m_WingedEdges.m_Memory.m_pMemory;
        v29 = p_x[1] == v28[v23 - 1].m_vecPosition.y;
        v30 = &v28[v23 - 1].m_vecPosition.x;
        if ( v29 && *v30 > *p_x )
          *p_x = *v30;
      }
      m_flX = flPrevX;
      if ( m_pNextActiveEdge->m_vecPositionEnd.y > flMaxY )
      {
        m_nNewReduceCount = this->m_nNewReduceCount;
        v32 = &this->m_pNewReduceInfo[m_nNewReduceCount];
        this->m_nNewReduceCount = m_nNewReduceCount + 1;
        v32->m_pEdge = m_pNextActiveEdge;
        v32->m_nWingedEdge = v27;
      }
      goto LABEL_29;
    }
    p_m_nWingedEdge = &this->m_pPrevReduceInfo[v14].m_nWingedEdge;
    v34 = p_m_nWingedEdge;
    while ( 1 )
    {
      v16 = &wingedEdgeList->m_WingedEdges.m_Memory.m_pMemory[*p_m_nWingedEdge];
      if ( v16->m_nLeaveSurfID == v7 )
        break;
LABEL_18:
      p_m_nWingedEdge = v34 - 4;
      --v14;
      v34 -= 4;
      if ( v14 < 0 )
        goto LABEL_23;
    }
    if ( v16->m_nEnterSurfID != nEnterSurfID
      || v16->m_flDxDy != m_pNextActiveEdge->m_flDxDy
      || fabs(v16->m_vecPositionEnd.x - m_pNextActiveEdge->m_flX) >= 0.001 )
    {
      v7 = nLeaveSurfID;
      goto LABEL_18;
    }
    m_pEdge = this->m_pPrevReduceInfo[v14].m_pEdge;
    v18 = (float)((float)((float)(v8 - m_pEdge->m_vecPosition.y) * m_pEdge->m_flOODy)
                * (float)(m_pEdge->m_vecPositionEnd.x - m_pEdge->m_vecPosition.x))
        + m_pEdge->m_vecPosition.x;
    v16->m_vecPositionEnd.x = v18;
    v16->m_vecPositionEnd.y = v8;
    v16->m_vecPositionEnd.z = (float)(this->m_Surfaces.m_Memory.m_pMemory[nEdgeSurfID].m_Plane.dist
                                    - (float)(v18 * this->m_Surfaces.m_Memory.m_pMemory[nEdgeSurfID].m_Plane.normal.x))
                            - (float)(this->m_Surfaces.m_Memory.m_pMemory[nEdgeSurfID].m_Plane.normal.y * v8);
    if ( m_pNextActiveEdge->m_vecPositionEnd.y > v8 )
    {
      v19 = this->m_nNewReduceCount;
      v20 = &this->m_pNewReduceInfo[v19];
      this->m_nNewReduceCount = v19 + 1;
      v20->m_pEdge = this->m_pPrevReduceInfo[v14].m_pEdge;
      v20->m_nWingedEdge = this->m_pPrevReduceInfo[v14].m_nWingedEdge;
    }
LABEL_29:
    v12 = (CEdgeList::Edge_t *)pNextEdge;
    nLeaveSurfID = nEnterSurfID;
    v7 = nEnterSurfID;
LABEL_30:
    m_pNextActiveEdge = v12;
  }
  while ( v12 != &this->m_EndTerminal );
}

//------------------------------------------------------------------------------
// Address: 0x100F3E60
// Name: public: void CEdgeList::ReduceActiveList(class CWingedEdgeList __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEdgeList::ReduceActiveList(CEdgeList *this, CWingedEdgeList *newEdgeList)
{
  int m_Size; // eax
  int v4; // ebx
  int v5; // edi
  void *v6; // esp
  void *v7; // esp
  unsigned __int16 *m_pMemory; // ecx
  int v9; // ebx
  CEdgeList::Edge_t *p_m_EndTerminal; // edi
  double v11; // st7
  double m_flNextDiscontinuity; // st7
  double v13; // st6
  int m_nNewReduceCount; // ecx
  CEdgeList::ReduceInfo_t *v15; // eax
  CEdgeList::Edge_t *m_pNextActiveEdge; // eax
  float v17; // xmm2_4
  float v18; // xmm1_4
  float v19; // xmm3_4
  CEdgeList::Edge_t *v20; // ecx
  float v21; // xmm0_4
  int m_nCurrentEdgeIndex; // eax
  float v23; // xmm0_4
  float v24; // [esp+4h] [ebp-134h]
  float flMinY; // [esp+8h] [ebp-130h]
  float y; // [esp+Ch] [ebp-12Ch]
  float ya; // [esp+Ch] [ebp-12Ch]
  _BYTE v28[12]; // [esp+10h] [ebp-128h] BYREF
  CEdgeList::Edge_t *pEdgeCrossings[64]; // [esp+1Ch] [ebp-11Ch] BYREF
  CEdgeList::ReduceInfo_t *pBuf[2]; // [esp+11Ch] [ebp-1Ch]
  float flPrevY; // [esp+124h] [ebp-14h]
  int nEdgeCrossingCount; // [esp+128h] [ebp-10h] BYREF
  int nEdgeCount; // [esp+12Ch] [ebp-Ch]
  float flNextY; // [esp+130h] [ebp-8h]
  bool bDone; // [esp+137h] [ebp-1h]

  m_Size = this->m_SortIndices.m_Size;
  nEdgeCount = m_Size;
  if ( m_Size != 0 )
  {
    v4 = this->m_Surfaces.m_Size;
    if ( v4 > 0 )
    {
      v5 = 0;
      do
      {
        CWingedEdgeList::AddSurface(this: newEdgeList, plane: &this->m_Surfaces.m_Memory.m_pMemory[v5++].m_Plane);
        --v4;
      }
      while ( v4 != 0 );
      m_Size = nEdgeCount;
    }
    v6 = alloca(8 * m_Size);
    pBuf[0] = (CEdgeList::ReduceInfo_t *)v28;
    v7 = alloca(8 * m_Size);
    m_pMemory = this->m_SortIndices.m_Memory.m_pMemory;
    v9 = 0;
    this->m_nNewReduceCount = 0;
    this->m_nPrevReduceCount = 0;
    this->m_nCurrentEdgeIndex = 0;
    p_m_EndTerminal = &this->m_EndTerminal;
    v11 = this->m_Edges.m_Memory.m_pMemory[*m_pMemory].m_vecPosition.y;
    this->m_StartTerminal.m_pNextActiveEdge = &this->m_EndTerminal;
    this->m_flNextDiscontinuity = v11;
    this->m_EndTerminal.m_pPrevActiveEdge = &this->m_StartTerminal;
    this->m_pCurrentActiveEdge = &this->m_EndTerminal;
    this->m_flLastX = this->m_EndTerminal.m_flX;
    pBuf[1] = (CEdgeList::ReduceInfo_t *)v28;
    m_flNextDiscontinuity = this->m_flNextDiscontinuity;
    this->m_StartSurfTerminal.m_pNextSurface = &this->m_EndSurfTerminal;
    this->m_EndSurfTerminal.m_pPrevSurface = &this->m_StartSurfTerminal;
    if ( m_flNextDiscontinuity <= -1.0 )
      m_flNextDiscontinuity = -1.0;
    y = m_flNextDiscontinuity;
    this->m_flNextDiscontinuity = 3.4028235e38;
    CEdgeList::IntroduceNewActiveEdges(this, y);
    nEdgeCrossingCount = 0;
    bDone = false;
    while ( 1 )
    {
      v24 = m_flNextDiscontinuity;
      v13 = CEdgeList::LocateEdgeCrossingDiscontinuity(
              this,
              flNextY: this->m_flNextDiscontinuity,
              flPrevY: v24,
              nCount: &nEdgeCrossingCount,
              ppInfo: pEdgeCrossings);
      flNextY = v13;
      m_nNewReduceCount = this->m_nNewReduceCount;
      v15 = pBuf[v9];
      this->m_pNewReduceInfo = pBuf[-v9 + 1];
      this->m_pPrevReduceInfo = v15;
      this->m_nPrevReduceCount = m_nNewReduceCount;
      this->m_nNewReduceCount = 0;
      if ( v13 >= 1.001 )
      {
        flNextY = 1.001;
        v13 = 1.001;
        bDone = true;
      }
      ya = v13;
      flMinY = m_flNextDiscontinuity;
      CEdgeList::ReduceActiveEdgeList(this, wingedEdgeList: newEdgeList, flMinY, flMaxY: ya);
      m_pNextActiveEdge = this->m_StartTerminal.m_pNextActiveEdge;
      v17 = flNextY;
      v18 = -3.4028235e38;
      flPrevY = flNextY;
      this->m_flNextDiscontinuity = 3.4028235e38;
      if ( m_pNextActiveEdge != p_m_EndTerminal )
      {
        do
        {
          v19 = m_pNextActiveEdge->m_vecPositionEnd.y;
          v20 = m_pNextActiveEdge->m_pNextActiveEdge;
          if ( v17 < v19 )
          {
            v21 = (float)((float)(v17 - m_pNextActiveEdge->m_vecPosition.y) * m_pNextActiveEdge->m_flDxDy)
                + m_pNextActiveEdge->m_vecPosition.x;
            m_pNextActiveEdge->m_flX = v21;
            if ( v18 <= v21 )
              v18 = v21;
            else
              m_pNextActiveEdge->m_flX = v18;
            if ( this->m_flNextDiscontinuity > v19 )
              this->m_flNextDiscontinuity = v19;
          }
          else
          {
            m_pNextActiveEdge->m_pPrevActiveEdge->m_pNextActiveEdge = v20;
            m_pNextActiveEdge->m_pNextActiveEdge->m_pPrevActiveEdge = m_pNextActiveEdge->m_pPrevActiveEdge;
          }
          m_pNextActiveEdge = v20;
        }
        while ( v20 != p_m_EndTerminal );
      }
      if ( nEdgeCrossingCount != 0 )
      {
        CEdgeList::ReorderActiveEdgeList(this, nCount: nEdgeCrossingCount, ppCrossings: pEdgeCrossings);
        m_nCurrentEdgeIndex = this->m_nCurrentEdgeIndex;
        if ( m_nCurrentEdgeIndex < nEdgeCount )
        {
          v23 = this->m_Edges.m_Memory.m_pMemory[this->m_SortIndices.m_Memory.m_pMemory[m_nCurrentEdgeIndex]].m_vecPosition.y;
          if ( this->m_flNextDiscontinuity > v23 )
            this->m_flNextDiscontinuity = v23;
        }
      }
      else
      {
        CEdgeList::IntroduceNewActiveEdges(this, y: flNextY);
        if ( this->m_flNextDiscontinuity == 3.4028235e38 )
          return;
      }
      v9 = 1 - v9;
      if ( bDone )
        break;
      m_flNextDiscontinuity = flPrevY;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F4120
// Name: public: COcclusionSystem::COcclusionSystem(void)
// Source: json
//------------------------------------------------------------------------------
COcclusionSystem *__thiscall COcclusionSystem::COcclusionSystem(COcclusionSystem *this)
{
  Vector *v2; // eax

  this->__vftable = (COcclusionSystem_vtbl *)&COcclusionSystem::`vftable';
  CEdgeList::CEdgeList(this: &this->m_EdgeList);
  CWingedEdgeList::CWingedEdgeList(this: &this->m_WingedEdgeList);
  this->m_ClippedVerts.m_Memory.m_pMemory = nullptr;
  this->m_ClippedVerts.m_Memory.m_nAllocationCount = 64;
  this->m_ClippedVerts.m_Memory.m_nGrowSize = 0;
  v2 = (Vector *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 768);
  this->m_ClippedVerts.m_Memory.m_pMemory = v2;
  this->m_ClippedVerts.m_Size = 0;
  this->m_ClippedVerts.m_pElements = v2;
  this->m_bEdgeListDirty = false;
  this->m_nTests = 0;
  this->m_nOccluded = 0;
  this->m_flMinOccluderArea = 5.0;
  this->m_flMaxOccludeeArea = 5.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100F41B0
// Name: private: void COcclusionSystem::StitchClippedVertices(class Vector __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COcclusionSystem::StitchClippedVertices(COcclusionSystem *this, Vector *pVertices, int nCount)
{
  long double v4; // st7
  int v6; // ecx
  Vector *m_pMemory; // edi
  float *p_x; // edx
  float *v9; // eax

  if ( nCount > 0 )
  {
    v4 = 0.001;
    do
    {
      if ( fabs(pVertices->z) <= 0.001 )
      {
        v6 = this->m_ClippedVerts.m_Size - 1;
        if ( v6 < 0 )
        {
LABEL_10:
          CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
            this: &this->m_ClippedVerts,
            elem: this->m_ClippedVerts.m_Size,
            src: pVertices);
          v4 = 0.001;
        }
        else
        {
          m_pMemory = this->m_ClippedVerts.m_Memory.m_pMemory;
          p_x = &m_pMemory[v6].x;
          while ( fabs(pVertices->x - *p_x) > v4 || fabs(pVertices->y - p_x[1]) > v4 || v4 < fabs(pVertices->z - p_x[2]) )
          {
            p_x -= 3;
            if ( --v6 < 0 )
              goto LABEL_10;
          }
          v9 = &m_pMemory[v6].x;
          pVertices->x = *v9;
          pVertices->y = v9[1];
          pVertices->z = v9[2];
        }
      }
      ++pVertices;
      --nCount;
    }
    while ( nCount != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F4280
// Name: private: void COcclusionSystem::AddPolygonToEdgeList(class CEdgeList __near &,class Vector __near * __near *,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COcclusionSystem::AddPolygonToEdgeList(
        COcclusionSystem *this,
        CEdgeList *edgeList,
        Vector **ppPolygon,
        int nCount,
        int nSurfID,
        bool bClipped)
{
  int v6; // ebx
  void *v7; // esp
  void *v8; // esp
  Vector **m_flDist_low; // esi
  void *v10; // esp
  float *v11; // esi
  int v12; // eax
  Vector **v13; // ebx
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // esi
  int v19; // edx
  float v20; // xmm4_4
  float y; // xmm0_4
  float x; // xmm1_4
  unsigned int v23; // ecx
  COcclusionSystem::AxisAlignedPlane_t *p_plane; // eax
  float v25; // xmm2_4
  float v26; // xmm2_4
  float v27; // xmm2_4
  float v28; // xmm2_4
  float v29; // xmm0_4
  int v30; // esi
  Vector *v31; // eax
  int v32; // edi
  Vector *v33; // ebx
  Vector *v34[2]; // [esp+0h] [ebp-24h] BYREF
  int v35; // [esp+8h] [ebp-1Ch] BYREF
  COcclusionSystem::AxisAlignedPlane_t plane; // [esp+Ch] [ebp-18h] BYREF
  int v37; // [esp+18h] [ebp-Ch]
  Vector *pVecProjectedVertex; // [esp+1Ch] [ebp-8h]
  COcclusionSystem *v39; // [esp+20h] [ebp-4h]
  int nLastClipVert; // [esp+30h] [ebp+Ch]
  int nLastClipVerta; // [esp+30h] [ebp+Ch]
  Vector *bClippeda; // [esp+3Ch] [ebp+18h]

  v6 = nCount;
  v39 = this;
  v7 = alloca(16 * nCount);
  v8 = alloca(16 * nCount);
  m_flDist_low = v34;
  LODWORD(plane.m_flDist) = v34;
  v10 = alloca(12 * nCount);
  pVecProjectedVertex = (Vector *)v34;
  if ( nCount > 0 )
  {
    v11 = (float *)&v35;
    v12 = (char *)ppPolygon - (char *)v34;
    v13 = v34;
    v37 = (char *)ppPolygon - (char *)v34;
    nLastClipVert = nCount;
    while ( 1 )
    {
      Vector3DMultiplyPositionProjective(
        src1: &v39->m_WorldToProjection,
        src2: *(Vector **)((char *)v13 + v12),
        dst: (Vector *)(v11 - 2));
      *v11 = (float)(*v11 > 0.0) * *v11;
      *v13 = (Vector *)(v11 - 2);
      v11 += 3;
      ++v13;
      if ( --nLastClipVert == 0 )
        break;
      v12 = v37;
    }
    m_flDist_low = (Vector **)LODWORD(plane.m_flDist);
    v6 = nCount;
  }
  plane.m_nAxis = 0;
  s_nTempVertCount = 0;
  plane.m_flDist = -1.0;
  plane.m_flSign = -1.0;
  v14 = COcclusionSystem::ClipPolygonToAxisAlignedPlane(
          this: v39,
          ppVertices: v34,
          nVertexCount: v6,
          &plane,
          ppOutVerts: m_flDist_low);
  if ( v14 >= 3 )
  {
    plane.m_flSign = 1.0;
    v15 = COcclusionSystem::ClipPolygonToAxisAlignedPlane(
            this: v39,
            ppVertices: m_flDist_low,
            nVertexCount: v14,
            &plane,
            ppOutVerts: v34);
    if ( v15 >= 3 )
    {
      plane.m_nAxis = 1;
      v16 = COcclusionSystem::ClipPolygonToAxisAlignedPlane(
              this: v39,
              ppVertices: v34,
              nVertexCount: v15,
              &plane,
              ppOutVerts: m_flDist_low);
      if ( v16 >= 3 )
      {
        plane.m_flSign = -1.0;
        v17 = COcclusionSystem::ClipPolygonToAxisAlignedPlane(
                this: v39,
                ppVertices: m_flDist_low,
                nVertexCount: v16,
                &plane,
                ppOutVerts: v34);
        if ( v17 >= 3 )
        {
          v18 = v17 - 1;
          v19 = 1;
          v20 = 0.0;
          nLastClipVerta = v17 - 1;
          if ( v17 - 2 >= 4 )
          {
            y = v34[0]->y;
            x = v34[0]->x;
            v23 = ((unsigned int)(v17 - 6) >> 2) + 1;
            p_plane = &plane;
            v19 = 4 * v23 + 1;
            do
            {
              v25 = (float)((float)(*(float *)(LODWORD(p_plane[-1].m_flDist) + 4) - y)
                          * (float)(*(float *)LODWORD(p_plane[-1].m_flSign) - x))
                  - (float)((float)(*(float *)(LODWORD(p_plane[-1].m_flSign) + 4) - y)
                          * (float)(*(float *)LODWORD(p_plane[-1].m_flDist) - x));
              if ( v25 < 0.0 )
                v20 = v20 - v25;
              v26 = (float)((float)(*(float *)(p_plane->m_nAxis + 4) - y)
                          * (float)(*(float *)LODWORD(p_plane[-1].m_flDist) - x))
                  - (float)((float)(*(float *)(LODWORD(p_plane[-1].m_flDist) + 4) - y)
                          * (float)(*(float *)p_plane->m_nAxis - x));
              if ( v26 < 0.0 )
                v20 = v20 - v26;
              v27 = (float)((float)(*(float *)(LODWORD(p_plane->m_flSign) + 4) - y)
                          * (float)(*(float *)p_plane->m_nAxis - x))
                  - (float)((float)(*(float *)(p_plane->m_nAxis + 4) - y)
                          * (float)(*(float *)LODWORD(p_plane->m_flSign) - x));
              if ( v27 < 0.0 )
                v20 = v20 - v27;
              v28 = (float)((float)(*(float *)(LODWORD(p_plane->m_flDist) + 4) - y)
                          * (float)(*(float *)LODWORD(p_plane->m_flSign) - x))
                  - (float)((float)(*(float *)(LODWORD(p_plane->m_flSign) + 4) - y)
                          * (float)(*(float *)LODWORD(p_plane->m_flDist) - x));
              if ( v28 < 0.0 )
                v20 = v20 - v28;
              p_plane = (COcclusionSystem::AxisAlignedPlane_t *)((char *)p_plane + 16);
              --v23;
            }
            while ( v23 != 0 );
            v6 = nCount;
            v18 = nLastClipVerta;
          }
          for ( ; v19 < v18; ++v19 )
          {
            v29 = (float)((float)(v34[v19 + 1]->y - v34[0]->y) * (float)(v34[v19]->x - v34[0]->x))
                - (float)((float)(v34[v19]->y - v34[0]->y) * (float)(v34[v19 + 1]->x - v34[0]->x));
            if ( v29 < 0.0 )
              v20 = v20 - v29;
          }
          edgeList->m_Surfaces.m_Memory.m_pMemory[nSurfID].m_flArea = v20;
          if ( bClipped )
            COcclusionSystem::StitchClippedVertices(this: v39, pVertices: pVecProjectedVertex, nCount: v6);
          v30 = v6 - 1;
          v31 = &pVecProjectedVertex[v6 - 1];
          v32 = 0;
          bClippeda = v31;
          LODWORD(plane.m_flDist) = v31;
          if ( v6 - 1 > 0 )
          {
            v33 = pVecProjectedVertex;
            do
            {
              *((_DWORD *)&plane.m_flSign + (v32 & 1)) = v33;
              CEdgeList::AddEdge(
                this: edgeList,
                ppEdgeVertices: COERCE_FLOAT((COcclusionSystem::AxisAlignedPlane_t *)&plane.m_flSign),
                nSurfID);
              ++v32;
              ++v33;
            }
            while ( v32 < v30 );
            v31 = bClippeda;
          }
          *((_DWORD *)&plane.m_flSign + (v30 & 1)) = v31;
          CEdgeList::AddEdge(
            this: edgeList,
            ppEdgeVertices: COERCE_FLOAT((COcclusionSystem::AxisAlignedPlane_t *)&plane.m_flSign),
            nSurfID);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F4600
// Name: private: void COcclusionSystem::RecomputeOccluderEdgeList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COcclusionSystem::RecomputeOccluderEdgeList(COcclusionSystem *this)
{
  int v2; // eax
  int v3; // eax
  CEdgeList *p_m_EdgeList; // edi
  doccluderdata_t *occluders; // ebx
  int *occludervertindices; // edx
  int v7; // eax
  int *p_area; // ebx
  int v9; // ebx
  CClientState *BaseLocalClient; // eax
  char v11; // cl
  int v12; // edx
  int v13; // ecx
  int v14; // eax
  int v15; // edx
  doccluderpolydata_t *occluderpolys; // eax
  int v17; // edi
  int *v18; // eax
  const cplane_t *v19; // ebx
  float v20; // xmm0_4
  float dist; // xmm1_4
  void *v22; // esp
  void *v23; // esp
  int v24; // eax
  int *v25; // edx
  int v26; // edi
  float v27; // xmm0_4
  CEdgeList *v28; // ebx
  int v29; // eax
  bool v30; // zf
  CWingedEdgeList *v31; // esi
  _BYTE v32[12]; // [esp+0h] [ebp-68h] BYREF
  cplane_t projectionSpacePlane; // [esp+Ch] [ebp-5Ch] BYREF
  cplane_t cameraSpacePlane; // [esp+20h] [ebp-48h] BYREF
  CWingedEdgeList *newEdgeList; // [esp+34h] [ebp-34h]
  BOOL bClipped; // [esp+38h] [ebp-30h] BYREF
  const cplane_t *surfPlane; // [esp+3Ch] [ebp-2Ch]
  mvertex_t *pVertices; // [esp+40h] [ebp-28h]
  int nFirstVertexIndex; // [esp+44h] [ebp-24h]
  int *pIndices; // [esp+48h] [ebp-20h]
  int i; // [esp+4Ch] [ebp-1Ch]
  CEdgeList *edgeList; // [esp+50h] [ebp-18h]
  int v43; // [esp+54h] [ebp-14h]
  int v44; // [esp+58h] [ebp-10h]
  Vector **ppClipVerts; // [esp+5Ch] [ebp-Ch]
  Vector **ppSurfVerts; // [esp+60h] [ebp-8h]
  unsigned __int8 color[4]; // [esp+64h] [ebp-4h] BYREF

  if ( this->m_bEdgeListDirty )
  {
    if ( GetBaseLocalClient()->m_bAreaBitsValid
      || (v2 = _CommandLine(),
          (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 40))(a1: v2, a2: "-buildcubemaps") == 0)
      && (v3 = _CommandLine(),
          (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v3 + 40))(a1: v3, a2: "-buildmodelforworld") == 0) )
    {
      this->m_bEdgeListDirty = false;
      this->m_EdgeList.m_Edges.m_Size = 0;
      this->m_EdgeList.m_SortIndices.m_Size = 0;
      p_m_EdgeList = &this->m_EdgeList;
      this->m_EdgeList.m_OrigSortIndices.m_Size = 0;
      this->m_EdgeList.m_Surfaces.m_Size = 0;
      this->m_EdgeList.m_SurfaceSort.m_Size = 0;
      this->m_WingedEdgeList.m_WingedEdges.m_Size = 0;
      this->m_WingedEdgeList.m_Surfaces.m_Size = 0;
      this->m_ClippedVerts.m_Size = 0;
      newEdgeList = &this->m_WingedEdgeList;
      occluders = host_state.worldbrush->occluders;
      pVertices = host_state.worldbrush->vertexes;
      occludervertindices = host_state.worldbrush->occludervertindices;
      v7 = host_state.worldbrush->numoccluders - 1;
      edgeList = &this->m_EdgeList;
      pIndices = occludervertindices;
      i = v7;
      if ( v7 >= 0 )
      {
        p_area = &occluders[v7].area;
        *(_DWORD *)color = p_area;
        do
        {
          if ( (*(_BYTE *)(p_area - 9) & 1) == 0 )
          {
            if ( GetBaseLocalClient() == (CClientState *)-19052
              || (v9 = *p_area,
                  BaseLocalClient = GetBaseLocalClient(),
                  v11 = v9 & 7,
                  v12 = v9 >> 3,
                  p_area = *(int **)color,
                  ((unsigned __int8)(1 << v11) & BaseLocalClient->m_chAreaBits[v12]) != 0) )
            {
              v13 = *(p_area - 7);
              v14 = *(p_area - 8);
              if ( v13 > 0 )
              {
                v15 = 12 * v14;
                v44 = 12 * v14;
                v43 = v13;
                do
                {
                  occluderpolys = host_state.worldbrush->occluderpolys;
                  v17 = *(int *)((char *)&occluderpolys->vertexcount + v15);
                  v18 = (int *)((char *)&occluderpolys->firstvertexindex + v15);
                  v19 = &host_state.worldbrush->planes[v18[2]];
                  v20 = (float)((float)(v19->normal.y * this->m_vecCameraPosition.y)
                              + (float)(this->m_vecCameraPosition.x * v19->normal.x))
                      + (float)(v19->normal.z * this->m_vecCameraPosition.z);
                  dist = v19->dist;
                  nFirstVertexIndex = *v18;
                  surfPlane = v19;
                  if ( dist < v20 )
                  {
                    v22 = alloca(4 * v17);
                    ppSurfVerts = (Vector **)v32;
                    v23 = alloca(8 * v17);
                    v24 = 0;
                    ppClipVerts = (Vector **)v32;
                    if ( v17 > 0 )
                    {
                      v25 = &pIndices[nFirstVertexIndex];
                      do
                        ppSurfVerts[v24++] = &pVertices[*v25++].position;
                      while ( v24 < v17 );
                      v19 = surfPlane;
                    }
                    v26 = COcclusionSystem::ClipPolygonToNearPlane(
                            this,
                            ppVertices: ppSurfVerts,
                            nVertexCount: v17,
                            ppOutVerts: ppClipVerts,
                            pClipped: (bool *)&bClipped);
                    if ( v26 >= 3 )
                    {
                      MatrixTransformPlane(src: &this->m_WorldToCamera, inPlane: v19, outPlane: &cameraSpacePlane);
                      v27 = 0.0;
                      if ( cameraSpacePlane.dist != 0.0 )
                        v27 = 1.0 / cameraSpacePlane.dist;
                      v28 = edgeList;
                      projectionSpacePlane.normal.x = (float)(cameraSpacePlane.normal.x * v27) * this->m_flXProjScale;
                      projectionSpacePlane.normal.y = (float)(v27 * cameraSpacePlane.normal.y) * this->m_flYProjScale;
                      projectionSpacePlane.normal.z = 1.0;
                      projectionSpacePlane.dist = (float)((float)(cameraSpacePlane.normal.z * v27)
                                                        * this->m_flProjDistScale)
                                                + this->m_flProjDistOffset;
                      v29 = CEdgeList::AddSurface(this: edgeList, plane: &projectionSpacePlane);
                      COcclusionSystem::AddPolygonToEdgeList(
                        this,
                        edgeList: v28,
                        ppPolygon: ppClipVerts,
                        nCount: v26,
                        nSurfID: v29,
                        bClipped);
                    }
                  }
                  v15 = v44 + 12;
                  v30 = v43-- == 1;
                  v44 += 12;
                }
                while ( !v30 );
                p_m_EdgeList = edgeList;
                p_area = *(int **)color;
              }
            }
          }
          p_area -= 10;
          --i;
          *(_DWORD *)color = p_area;
        }
        while ( i >= 0 );
      }
      CEdgeList::CullSmallOccluders(this: p_m_EdgeList);
      v31 = newEdgeList;
      CEdgeList::ReduceActiveList(this: p_m_EdgeList, newEdgeList);
      *(_DWORD *)color = -1;
      CWingedEdgeList::QueueVisualization(this: v31, pColor: color);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F4900
// Name: public: virtual bool COcclusionSystem::IsOccluded(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall COcclusionSystem::IsOccluded(
        COcclusionSystem *this,
        const Vector *vecAbsMins,
        const Vector *vecAbsMaxs)
{
  DWORD CurrentThreadId; // ecx
  float v7; // xmm0_4
  float v8; // xmm4_4
  float v9; // xmm5_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float m_flMaxOccludeeArea; // xmm1_4
  float x; // xmm0_4
  float v14; // xmm2_4
  int v15; // ecx
  float *p_z; // eax
  Vector4D *v17; // edx
  Vector4D *v18; // edi
  float v19; // xmm1_4
  float v20; // xmm1_4
  float v21; // xmm1_4
  float y; // xmm2_4
  float z; // xmm3_4
  float v24; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm2_4
  float v29; // xmm1_4
  float v30; // xmm2_4
  float v31; // xmm3_4
  float v32; // xmm2_4
  int v33; // ebx
  int *v34; // edi
  int v35; // ecx
  int v36; // eax
  float v37; // xmm0_4
  float v38; // xmm4_4
  float v39; // xmm3_4
  float v40; // xmm1_4
  float v41; // xmm0_4
  float v42; // xmm2_4
  float v43; // xmm1_4
  float v44; // xmm4_4
  int v45; // eax
  int v46; // edi
  int *m_pMemory; // edi
  int v48; // eax
  int v49; // eax
  int m_nMinVert; // ecx
  int v51; // edi
  EdgeInfo_t *v52; // edx
  int v53; // eax
  char *v54; // edx
  int v55; // ecx
  float v56; // xmm0_4
  Vector *v57; // ebx
  Vector *v58; // edi
  int m_Size; // ecx
  int v60; // eax
  CWingedEdgeList::WingedEdge_t *v61; // edx
  int v62; // ecx
  CWingedEdgeList::WingedEdge_t *v63; // eax
  __int16 v64; // dx
  unsigned __int8 IsOccludingEdgeList; // bl
  int m_nGrowSize; // esi
  Vector4D vecProjVert[8]; // [esp+8h] [ebp-1ECh] BYREF
  int pEdgeSort[12]; // [esp+88h] [ebp-16Ch] BYREF
  Vector pVecProjectedVertex[8]; // [esp+B8h] [ebp-13Ch] BYREF
  int pSurfInd[6]; // [esp+118h] [ebp-DCh]
  cplane_t cameraSpacePlane; // [esp+130h] [ebp-C4h]
  cplane_t projectionSpacePlane; // [esp+144h] [ebp-B0h] BYREF
  Vector4D vecDeltaProj[3]; // [esp+158h] [ebp-9Ch] BYREF
  Vector vecDelta[2]; // [esp+188h] [ebp-6Ch]
  float pSign[2]; // [esp+1A0h] [ebp-54h]
  const Vector *pCornerVert[2]; // [esp+1A8h] [ebp-4Ch]
  Vector4D vecAbsMins4D; // [esp+1B0h] [ebp-44h] BYREF
  Vector vecSize; // [esp+1C0h] [ebp-34h]
  int nLeaveSurfID; // [esp+1CCh] [ebp-28h]
  int nEnterSurfID; // [esp+1D0h] [ebp-24h]
  CUtlSortVector<int,WingedEdgeLessFunc> edgeSort; // [esp+1D4h] [ebp-20h] BYREF
  int i; // [esp+1F0h] [ebp-4h] BYREF
  Vector *vecAbsMinsa; // [esp+1FCh] [ebp+8h]
  const Vector *vecAbsMinsb; // [esp+1FCh] [ebp+8h]

  if ( r_occlusion.m_pParent == nullptr || r_occlusion.m_pParent->m_Value.m_nValue == 0 )
    return 0;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "COcclusionSystem::IsOccluded",
    a3: 0,
    a4: "Occlusion",
    a5: false,
    a6: 4);
  if ( (_S2_7 & 1) == 0 )
  {
    _S2_7 |= 1u;
    mutex.m_ownerID = 0;
    mutex.m_depth = 0;
  }
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != mutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++mutex.m_depth;
  }
  COcclusionSystem::RecomputeOccluderEdgeList(this);
  if ( this->m_WingedEdgeList.m_WingedEdges.m_Size != 0 )
  {
    v7 = (float)((float)(this->m_NearClipPlane.normal.y
                       * (float)((float)((float)(vecAbsMaxs->y + vecAbsMins->y) * 0.5) - this->m_vecCameraPosition.y))
               + (float)(this->m_NearClipPlane.normal.x
                       * (float)((float)((float)(vecAbsMaxs->x + vecAbsMins->x) * 0.5) - this->m_vecCameraPosition.x)))
       + (float)(this->m_NearClipPlane.normal.z
               * (float)((float)((float)(vecAbsMaxs->z + vecAbsMins->z) * 0.5) - this->m_vecCameraPosition.z));
    if ( v7 > 0.0 )
    {
      v8 = vecAbsMaxs->y - vecAbsMins->y;
      v9 = vecAbsMaxs->z - vecAbsMins->z;
      v10 = this->m_flNearPlaneDist + v7;
      vecSize.x = vecAbsMaxs->x - vecAbsMins->x;
      vecSize.z = v9;
      v11 = (float)((float)((float)((float)((float)(v8 * v8) + (float)(vecSize.x * vecSize.x)) + (float)(v9 * v9)) * 0.25)
                  * this->m_flFOVFactor)
          / (float)(v10 * v10);
      m_flMaxOccludeeArea = r_occludeemaxarea.m_pParent->m_Value.m_fValue * 0.0099999998;
      vecSize.y = v8;
      if ( m_flMaxOccludeeArea == 0.0 )
        m_flMaxOccludeeArea = this->m_flMaxOccludeeArea;
      if ( v11 >= m_flMaxOccludeeArea )
      {
LABEL_27:
        if ( --mutex.m_depth == 0 )
          _InterlockedExchange((volatile __int32 *)&mutex, 0);
LABEL_29:
        CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
        return 0;
      }
      s_WingedTestEdgeList.m_WingedEdges.m_Size = 0;
      s_WingedTestEdgeList.m_Surfaces.m_Size = 0;
      x = vecAbsMins->x;
      pCornerVert[1] = vecAbsMaxs;
      vecAbsMins4D.x = x;
      vecAbsMins4D.y = vecAbsMins->y;
      vecAbsMins4D.z = vecAbsMins->z;
      pCornerVert[0] = vecAbsMins;
      vecAbsMins4D.w = 1.0;
      Vector4DMultiply(src1: &this->m_WorldToProjection, src2: &vecAbsMins4D, dst: vecProjVert);
      if ( vecProjVert[0].w > 0.0 )
      {
        vecDeltaProj[0].x = vecSize.x * this->m_WorldToProjection.m[0][0];
        vecDeltaProj[0].y = this->m_WorldToProjection.m[1][0] * vecSize.x;
        vecDeltaProj[0].z = this->m_WorldToProjection.m[2][0] * vecSize.x;
        vecDeltaProj[0].w = this->m_WorldToProjection.m[3][0] * vecSize.x;
        vecDeltaProj[1].x = this->m_WorldToProjection.m[0][1] * vecSize.y;
        vecDeltaProj[1].y = this->m_WorldToProjection.m[1][1] * vecSize.y;
        vecDeltaProj[1].z = this->m_WorldToProjection.m[2][1] * vecSize.y;
        vecDeltaProj[1].w = this->m_WorldToProjection.m[3][1] * vecSize.y;
        vecDeltaProj[2].x = this->m_WorldToProjection.m[0][2] * vecSize.z;
        vecDeltaProj[2].y = this->m_WorldToProjection.m[1][2] * vecSize.z;
        vecDeltaProj[2].z = this->m_WorldToProjection.m[2][2] * vecSize.z;
        v14 = this->m_WorldToProjection.m[3][2] * vecSize.z;
        pVecProjectedVertex[0].x = vecProjVert[0].x * (float)(1.0 / vecProjVert[0].w);
        pVecProjectedVertex[0].y = vecProjVert[0].y * (float)(1.0 / vecProjVert[0].w);
        vecDeltaProj[2].w = v14;
        pVecProjectedVertex[0].z = vecProjVert[0].z * (float)(1.0 / vecProjVert[0].w);
        if ( pVecProjectedVertex[0].z > 0.0 )
        {
          v15 = 1;
          vecAbsMinsa = (Vector *)&pVecProjectedVertex[1].z;
          i = 1;
          p_z = &vecProjVert[1].z;
          do
          {
            v17 = &vecDeltaProj[s_pDeltaIndices[v15]];
            v18 = &vecProjVert[s_pSourceIndices[v15]];
            *(p_z - 2) = v17->x + v18->x;
            *(p_z - 1) = v17->y + v18->y;
            *p_z = v17->z + v18->z;
            v19 = v17->w + v18->w;
            p_z[1] = v19;
            if ( v19 <= 0.0
              || (vecAbsMinsa[-1].y = (float)(1.0 / v19) * *(p_z - 2),
                  vecAbsMinsa[-1].z = *(p_z - 1) * (float)(1.0 / v19),
                  v20 = *p_z * (float)(1.0 / v19),
                  vecAbsMinsa->x = v20,
                  v20 <= 0.0) )
            {
              i = v15;
              goto LABEL_27;
            }
            ++v15;
            p_z += 4;
            ++vecAbsMinsa;
          }
          while ( v15 < 8 );
          v21 = vecAbsMins->x;
          y = vecAbsMins->y;
          z = vecAbsMins->z;
          pSign[0] = -1.0;
          v24 = this->m_vecCameraPosition.x;
          v25 = v21 - v24;
          v26 = v24 - vecAbsMaxs->x;
          vecDelta[0].x = v25;
          v27 = this->m_vecCameraPosition.y;
          v28 = y - v27;
          v29 = v27 - vecAbsMaxs->y;
          vecDelta[0].y = v28;
          v30 = this->m_vecCameraPosition.z;
          v31 = z - v30;
          v32 = v30 - vecAbsMaxs->z;
          ++this->m_nTests;
          i = v15;
          pSign[1] = 1.0;
          vecDelta[0].z = v31;
          vecDelta[1].x = v26;
          vecDelta[1].y = v29;
          vecDelta[1].z = v32;
          v33 = 0;
          v34 = &s_pFaceEdges[0][2];
          do
          {
            v35 = v33 & 1;
            v36 = v33 >> 1;
            if ( *(&vecDelta[0].x + 2 * v35 + v35 + (v33 >> 1)) > 0.0 )
            {
              v37 = pSign[v35];
              v38 = this->m_WorldToCamera.m[1][v36] * v37;
              v39 = this->m_WorldToCamera.m[0][v36] * v37;
              v40 = this->m_WorldToCamera.m[2][v36] * v37;
              v41 = (float)((float)((float)(this->m_WorldToCamera.m[1][3] * v38)
                                  + (float)(this->m_WorldToCamera.m[0][3] * v39))
                          + (float)(this->m_WorldToCamera.m[2][3] * v40))
                  + (float)((float)((float)((float)(v38 * v38) + (float)(v39 * v39)) + (float)(v40 * v40))
                          * (float)(*(&pCornerVert[v35]->x + v36) * v37));
              cameraSpacePlane.normal.x = v39;
              cameraSpacePlane.normal.y = v38;
              cameraSpacePlane.normal.z = v40;
              cameraSpacePlane.dist = v41;
              if ( v41 == 0.0 )
                v42 = 0.0;
              else
                v42 = 1.0 / v41;
              v43 = (float)((float)(v40 * v42) * this->m_flProjDistScale) + this->m_flProjDistOffset;
              v44 = (float)(v38 * v42) * this->m_flYProjScale;
              projectionSpacePlane.normal.x = (float)(v39 * v42) * this->m_flXProjScale;
              projectionSpacePlane.normal.y = v44;
              projectionSpacePlane.normal.z = 1.0;
              projectionSpacePlane.dist = v43;
              pSurfInd[v33] = CWingedEdgeList::AddSurface(this: &s_WingedTestEdgeList, plane: &projectionSpacePlane);
              s_pEdges[*(v34 - 2)].m_nTestCount = this->m_nTests;
              v45 = *v34;
              s_pEdges[*(v34 - 1)].m_nTestCount = this->m_nTests;
              s_pEdges[v45].m_nTestCount = this->m_nTests;
              s_pEdges[v34[1]].m_nTestCount = this->m_nTests;
            }
            else
            {
              pSurfInd[v33] = -1;
            }
            v34 += 4;
            ++v33;
          }
          while ( (int)v34 < (int)&vec4_invalid_9 );
          v46 = 0;
          edgeSort.m_Memory.m_pMemory = pEdgeSort;
          edgeSort.m_Memory.m_nAllocationCount = 12;
          edgeSort.m_Memory.m_nGrowSize = -1;
          edgeSort.m_Size = 0;
          edgeSort.m_pElements = pEdgeSort;
          edgeSort.m_bNeedsSort = false;
          edgeSort.m_pLessContext = pVecProjectedVertex;
          i = 0;
          do
          {
            if ( s_pEdges[v46].m_nTestCount == this->m_nTests )
            {
              s_pEdges[v46].m_nMinVert = pVecProjectedVertex[s_pEdges[v46].m_nVert[0]].y >= pVecProjectedVertex[s_pEdges[v46].m_nVert[1]].y;
              CUtlSortVector<int,WingedEdgeLessFunc>::Insert(this: &edgeSort, src: (Vector *)&i);
            }
            i = ++v46;
          }
          while ( v46 < 12 );
          m_pMemory = edgeSort.m_Memory.m_pMemory;
          v48 = 0;
          for ( i = 0; v48 < edgeSort.m_Size; i = v48 )
          {
            v49 = m_pMemory[v48];
            m_nMinVert = s_pEdges[v49].m_nMinVert;
            v51 = s_pEdges[v49].m_nVert[m_nMinVert];
            v52 = &s_pEdges[v49];
            v53 = v52->m_nFace[m_nMinVert];
            v54 = (char *)v52 - m_nMinVert;
            v55 = pSurfInd[v53];
            v56 = pVecProjectedVertex[(unsigned __int8)v54[1]].y - pVecProjectedVertex[v51].y;
            v57 = &pVecProjectedVertex[(unsigned __int8)v54[1]];
            v58 = &pVecProjectedVertex[v51];
            nEnterSurfID = pSurfInd[(unsigned __int8)v54[3]];
            nLeaveSurfID = v55;
            if ( v56 != 0.0 )
            {
              m_Size = s_WingedTestEdgeList.m_WingedEdges.m_Size;
              v60 = s_WingedTestEdgeList.m_WingedEdges.m_Size;
              vecAbsMinsb = (const Vector *)s_WingedTestEdgeList.m_WingedEdges.m_Size;
              if ( s_WingedTestEdgeList.m_WingedEdges.m_Size + 1 > s_WingedTestEdgeList.m_WingedEdges.m_Memory.m_nAllocationCount )
              {
                CUtlMemory<CWingedEdgeList::WingedEdge_t,int>::Grow(
                  this: (CUtlMemory<vgui::AnimationController::AnimCommand_t,int> *)&s_WingedTestEdgeList.m_WingedEdges,
                  num: s_WingedTestEdgeList.m_WingedEdges.m_Size
                - s_WingedTestEdgeList.m_WingedEdges.m_Memory.m_nAllocationCount
                + 1);
                m_Size = s_WingedTestEdgeList.m_WingedEdges.m_Size;
                v60 = (int)vecAbsMinsb;
              }
              v61 = s_WingedTestEdgeList.m_WingedEdges.m_Memory.m_pMemory;
              s_WingedTestEdgeList.m_WingedEdges.m_Size = m_Size + 1;
              v62 = m_Size - v60;
              s_WingedTestEdgeList.m_WingedEdges.m_pElements = s_WingedTestEdgeList.m_WingedEdges.m_Memory.m_pMemory;
              if ( v62 > 0 )
              {
                _V_memmove(
                  dest: &s_WingedTestEdgeList.m_WingedEdges.m_Memory.m_pMemory[v60 + 1],
                  src: &s_WingedTestEdgeList.m_WingedEdges.m_Memory.m_pMemory[v60],
                  count: 48 * v62);
                v61 = s_WingedTestEdgeList.m_WingedEdges.m_Memory.m_pMemory;
                v60 = (int)vecAbsMinsb;
              }
              v63 = &v61[v60];
              v64 = nLeaveSurfID;
              v63->m_nEnterSurfID = nEnterSurfID;
              v63->m_nLeaveSurfID = v64;
              v63->m_flOODy = 1.0 / v56;
              v63->m_vecPosition.x = v58->x;
              v63->m_vecPosition.y = v58->y;
              v63->m_vecPosition.z = v58->z;
              v63->m_vecPositionEnd.x = v57->x;
              v63->m_vecPositionEnd.y = v57->y;
              v63->m_vecPositionEnd.z = v57->z;
              v63->m_pPrevActiveEdge = nullptr;
              v63->m_pNextActiveEdge = nullptr;
              v63->m_flDxDy = (float)(v57->x - v58->x) * v63->m_flOODy;
            }
            m_pMemory = edgeSort.m_Memory.m_pMemory;
            v48 = i + 1;
          }
          IsOccludingEdgeList = CWingedEdgeList::IsOccludingEdgeList(
                                  this: &this->m_WingedEdgeList,
                                  testList: &s_WingedTestEdgeList);
          if ( IsOccludingEdgeList != 0 )
            ++this->m_nOccluded;
          CWingedEdgeList::QueueVisualization(
            this: &s_WingedTestEdgeList,
            pColor: s_VisualizationColor[IsOccludingEdgeList]);
          m_nGrowSize = edgeSort.m_Memory.m_nGrowSize;
          edgeSort.m_Size = 0;
          if ( edgeSort.m_Memory.m_nGrowSize >= 0 )
          {
            if ( m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
              m_pMemory = nullptr;
              edgeSort.m_Memory.m_pMemory = nullptr;
            }
            edgeSort.m_Memory.m_nAllocationCount = 0;
          }
          edgeSort.m_pElements = m_pMemory;
          if ( m_nGrowSize >= 0 )
          {
            if ( m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
              edgeSort.m_Memory.m_pMemory = nullptr;
            }
            edgeSort.m_Memory.m_nAllocationCount = 0;
          }
          if ( --mutex.m_depth == 0 )
            _InterlockedExchange((volatile __int32 *)&mutex, 0);
          CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
          return IsOccludingEdgeList;
        }
      }
    }
  }
  if ( --mutex.m_depth == 0 )
  {
    _InterlockedExchange((volatile __int32 *)&mutex, 0);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 0;
  }
  goto LABEL_29;
}

//------------------------------------------------------------------------------
// Address: 0x1020F200
// Name: public: void CUtlMemory<struct CEdgeList::Surface_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CEdgeList::Surface_t,int>::Grow(CUtlMemory<CEdgeList::Surface_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CEdgeList::Surface_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 40 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CEdgeList::Surface_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CEdgeList::Surface_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102484C0
// Name: protected: static int CUtlSortVector<class CDmxAttribute __near *,class CDmxAttributeLess>::CompareHelper(void __near *,class CDmxAttribute __near * const __near *,class CDmxAttribute __near * const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::CompareHelper(
        void *context,
        CDmxAttribute *const *lhs,
        CDmxAttribute *const *rhs)
{
  int v3; // ecx
  int v4; // esi
  int result; // eax
  int lhsa; // [esp+14h] [ebp+Ch]
  int rhsa; // [esp+18h] [ebp+10h]
  int rhsb; // [esp+18h] [ebp+10h]

  v3 = (int)*rhs;
  v4 = (int)*lhs;
  result = -1;
  if ( *lhs != nullptr )
    rhsa = *(_DWORD *)(v4 + 4);
  else
    rhsa = -1;
  if ( v3 != 0 )
    lhsa = *(_DWORD *)(v3 + 4);
  else
    lhsa = -1;
  if ( rhsa >= lhsa )
  {
    if ( v3 != 0 )
      rhsb = *(_DWORD *)(v3 + 4);
    else
      rhsb = -1;
    if ( v4 != 0 )
      return rhsb < *(_DWORD *)(v4 + 4);
    else
      return rhsb < -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102486C0
// Name: public: int CUtlSortVector<class CDmxAttribute __near *,class CDmxAttributeLess>::Find(class CDmxAttribute __near * const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::Find(
        CUtlSortVector<CDmxAttribute *,CDmxAttributeLess> *this,
        CDmxAttribute *const **src)
{
  int v3; // ebx
  int v4; // ecx
  CDmxAttribute **m_pMemory; // eax
  CDmxAttribute *const *v6; // esi
  int result; // eax
  CDmxAttribute *v8; // edx
  int *v9; // edi
  int *v10; // esi
  int *v11; // esi
  int *v12; // ecx
  int v13; // [esp+Ch] [ebp-24h] BYREF
  CUtlSymbolLarge::<unnamed_type_u> v14; // [esp+10h] [ebp-20h] BYREF
  int v15; // [esp+14h] [ebp-1Ch] BYREF
  int v16; // [esp+18h] [ebp-18h] BYREF
  int v17; // [esp+1Ch] [ebp-14h] BYREF
  int v18; // [esp+20h] [ebp-10h] BYREF
  int v19; // [esp+24h] [ebp-Ch] BYREF
  CUtlSymbolLarge::<unnamed_type_u> v20; // [esp+28h] [ebp-8h] BYREF
  CDmxAttribute **v21; // [esp+2Ch] [ebp-4h]
  CDmxAttribute *const *srca; // [esp+38h] [ebp+8h]

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/utlsortvector.h",
         215,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1/utlsortvector.h",
                            a2: 215,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/utlsortvector.h",
      a2: 215);
  }
  v3 = 0;
  v4 = this->m_Size - 1;
  if ( v4 >= 0 )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = *src;
    v21 = m_pMemory;
    for ( srca = v6; ; v6 = srca )
    {
      result = (v4 + v3) >> 1;
      v8 = v21[result];
      if ( v8 != nullptr )
      {
        v20.m_Id = (int)v8->m_Name.u;
        v9 = (int *)&v20;
      }
      else
      {
        v19 = -1;
        v9 = &v19;
      }
      if ( v6 != nullptr )
      {
        v18 = *((_DWORD *)v6 + 1);
        v10 = &v18;
      }
      else
      {
        v17 = -1;
        v10 = &v17;
      }
      if ( *v9 >= *v10 )
      {
        if ( srca != nullptr )
        {
          v16 = *((_DWORD *)srca + 1);
          v11 = &v16;
        }
        else
        {
          v15 = -1;
          v11 = &v15;
        }
        if ( v8 != nullptr )
        {
          v14.m_Id = (int)v8->m_Name.u;
          v12 = (int *)&v14;
        }
        else
        {
          v13 = -1;
          v12 = &v13;
        }
        if ( *v11 >= *v12 )
          return result;
        v4 = result - 1;
      }
      else
      {
        v3 = result + 1;
      }
      if ( v3 > v4 )
        return -1;
    }
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10248910
// Name: public: int CUtlSortVector<class CDmxAttribute __near *,class CDmxAttributeLess>::InsertNoSort(class CDmxAttribute __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::InsertNoSort(
        CUtlSortVector<CDmxAttribute *,CDmxAttributeLess> *this,
        CDmxAttribute **src)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmxAttribute **m_pMemory; // ecx
  int v6; // eax
  CDmxAttribute **v7; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  this->m_bNeedsSort = true;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<INetMessage *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &this->m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = *src;
  return m_Size;
}

} // namespace engine_xlsp
