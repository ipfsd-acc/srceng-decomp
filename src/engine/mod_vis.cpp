// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/mod_vis.cpp
// Functions: 10
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x101A46F0
// Name: SortVisViewClusters
// Source: json
//------------------------------------------------------------------------------
void SortVisViewClusters()
{
  int v0; // esi
  int *p_viewcluster; // ebx
  int v2; // edi
  int v3; // eax
  int *v4; // ecx

  v0 = 1;
  if ( vis.nClusters > 1 )
  {
    p_viewcluster = &vis.rgVisClusters[0].viewcluster;
    do
    {
      v2 = p_viewcluster[5];
      v3 = v0;
      if ( v0 > 0 )
      {
        v4 = p_viewcluster;
        do
        {
          if ( *v4 <= v2 )
            break;
          v4[5] = *v4;
          --v3;
          v4 -= 5;
        }
        while ( v3 > 0 );
      }
      ++v0;
      vis.rgVisClusters[v3].viewcluster = v2;
      p_viewcluster += 5;
    }
    while ( v0 < vis.nClusters );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A4740
// Name: bool Map_AreAnyLeavesVisible(struct worldbrushdata_t const __near &,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl Map_AreAnyLeavesVisible(const worldbrushdata_t *worldbrush, int *leafList, int nLeaves)
{
  int v3; // esi
  int cluster; // eax

  v3 = 0;
  if ( nLeaves <= 0 )
    return 0;
  while ( 1 )
  {
    cluster = worldbrush->leafs[leafList[v3]].cluster;
    if ( cluster != -1 && ((unsigned __int8)(1 << (cluster & 7)) & vis.rgCurrentVis[cluster >> 3]) != 0 )
      break;
    if ( ++v3 >= nLeaves )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101A47A0
// Name: unsigned char __near * Map_VisCurrent(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl Map_VisCurrent()
{
  return vis.rgCurrentVis;
}

//------------------------------------------------------------------------------
// Address: 0x101A47B0
// Name: int Map_VisCurrentCluster(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Map_VisCurrentCluster()
{
  int result; // eax

  result = vis.rgVisClusters[0].viewcluster;
  if ( vis.rgVisClusters[0].viewcluster < 0 && ++visclusterwarningcount <= 5 )
  {
    _ConDMsg(a1: "Map_VisCurrentCluster() < 0!\n");
    return vis.rgVisClusters[0].viewcluster;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A47E0
// Name: bool Map_VisForceFullSky(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Map_VisForceFullSky()
{
  return vis.bForceFullSky;
}

//------------------------------------------------------------------------------
// Address: 0x101A48A0
// Name: VisMark_Cached
// Source: json
//------------------------------------------------------------------------------
void __cdecl VisMark_Cached(const VisCacheEntry *cache)
{
  const worldbrushdata_t *worldbrush; // ecx
  int v2; // eax
  const VisCacheEntry *v3; // edi
  int m_Size; // esi
  unsigned __int16 *m_pMemory; // edx
  int v6; // edi
  bool v7; // zf
  int v8; // edi
  int v9; // esi
  unsigned __int16 *v10; // edx
  int v11; // edi
  int v12; // edi
  unsigned int v13; // [esp+Ch] [ebp-4h]
  const VisCacheEntry *cachea; // [esp+18h] [ebp+8h]

  v2 = r_visframecount;
  v3 = cache;
  m_Size = cache->leaflist.m_Size;
  m_pMemory = cache->leaflist.m_Memory.m_pMemory;
  if ( m_Size >= 8 )
  {
    v13 = (unsigned int)m_Size >> 3;
    m_Size -= 8 * ((unsigned int)m_Size >> 3);
    do
    {
      worldbrush->leafs[*m_pMemory].visframe = v2;
      worldbrush->leafs[m_pMemory[1]].visframe = v2;
      worldbrush->leafs[m_pMemory[2]].visframe = v2;
      worldbrush->leafs[m_pMemory[3]].visframe = v2;
      worldbrush->leafs[m_pMemory[4]].visframe = v2;
      worldbrush->leafs[m_pMemory[5]].visframe = v2;
      worldbrush->leafs[m_pMemory[6]].visframe = v2;
      v6 = m_pMemory[7] << 6;
      m_pMemory += 8;
      v7 = v13-- == 1;
      *(int *)((char *)&worldbrush->leafs->visframe + v6) = v2;
    }
    while ( !v7 );
    v3 = cache;
  }
  if ( m_Size != 0 )
  {
    do
    {
      v8 = *m_pMemory++ << 6;
      --m_Size;
      *(int *)((char *)&worldbrush->leafs->visframe + v8) = v2;
    }
    while ( m_Size != 0 );
    v3 = cache;
  }
  v9 = v3->nodelist.m_Size;
  v10 = v3->nodelist.m_Memory.m_pMemory;
  if ( v9 >= 8 )
  {
    cachea = (const VisCacheEntry *)((unsigned int)v9 >> 3);
    v9 -= 8 * ((unsigned int)v9 >> 3);
    do
    {
      worldbrush->nodes[*v10].visframe = v2;
      worldbrush->nodes[v10[1]].visframe = v2;
      worldbrush->nodes[v10[2]].visframe = v2;
      worldbrush->nodes[v10[3]].visframe = v2;
      worldbrush->nodes[v10[4]].visframe = v2;
      worldbrush->nodes[v10[5]].visframe = v2;
      worldbrush->nodes[v10[6]].visframe = v2;
      v11 = v10[7] << 6;
      v10 += 8;
      v7 = cachea == (const VisCacheEntry *)1;
      cachea = (const VisCacheEntry *)((char *)cachea - 1);
      *(int *)((char *)&worldbrush->nodes->visframe + v11) = v2;
    }
    while ( !v7 );
  }
  for ( ; v9 != 0; *(int *)((char *)&worldbrush->nodes->visframe + v12) = v2 )
  {
    v12 = *v10++ << 6;
    --v9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A4D50
// Name: VisCache_Build
// Source: json
//------------------------------------------------------------------------------
void __usercall VisCache_Build(VisCacheEntry *cache@<eax>, const worldbrushdata_t *worldbrush)
{
  int v3; // eax
  int *p_viewcluster; // ecx
  int *originclusters; // edx
  const worldbrushdata_t *v6; // eax
  CUtlMemory<wchar_t,int> *p_leaflist; // ebx
  int v8; // edi
  wchar_t *m_pMemory; // edi
  int m_nAllocationCount; // eax
  wchar_t *v11; // ecx
  int v12; // eax
  wchar_t *v13; // edi
  int j; // ebx
  int m_Size; // edi
  int v16; // eax
  unsigned __int16 *v17; // ecx
  int v18; // eax
  unsigned __int16 *v19; // edi
  unsigned __int16 v20; // [esp+10h] [ebp-10h]
  int i; // [esp+14h] [ebp-Ch]
  int visframe; // [esp+18h] [ebp-8h]
  int *p_visframe; // [esp+1Ch] [ebp-4h]

  if ( (_S1_17 & 1) == 0 )
  {
    _S1_17 |= 1u;
    counter_8.m_pCounter = CVProfile::FindOrCreateCounter(
                             this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                             a2: "VisCache misses",
                             a3: COUNTER_GROUP_DEFAULT);
    atexit(func: VisCache_Build_::_4_::_dynamic_atexit_destructor_for___counter__);
  }
  ++*counter_8.m_pCounter;
  cache->nClusters = vis.nClusters;
  v3 = 0;
  if ( vis.nClusters > 0 )
  {
    p_viewcluster = &vis.rgVisClusters[0].viewcluster;
    originclusters = cache->originclusters;
    do
    {
      *originclusters = *p_viewcluster;
      ++v3;
      p_viewcluster += 5;
      ++originclusters;
    }
    while ( v3 < vis.nClusters );
  }
  v6 = worldbrush;
  p_leaflist = (CUtlMemory<wchar_t,int> *)&cache->leaflist;
  cache->leaflist.m_Size = 0;
  cache->nodelist.m_Size = 0;
  visframe = r_visframecount;
  i = 0;
  if ( worldbrush->numleafs > 0 )
  {
    p_visframe = &worldbrush->leafs->visframe;
    do
    {
      v8 = *((__int16 *)p_visframe + 22);
      if ( v8 != -1 && ((unsigned __int8)(1 << (v8 & 7)) & vis.rgCurrentVis[v8 >> 3]) != 0 )
      {
        *p_visframe = visframe;
        m_pMemory = p_leaflist[1].m_pMemory;
        m_nAllocationCount = p_leaflist->m_nAllocationCount;
        if ( (int)m_pMemory + 1 > m_nAllocationCount )
          CUtlMemory<wchar_t,int>::Grow(this: p_leaflist, num: (int)m_pMemory - m_nAllocationCount + 1);
        ++p_leaflist[1].m_pMemory;
        v11 = p_leaflist->m_pMemory;
        v12 = (char *)p_leaflist[1].m_pMemory - (char *)m_pMemory - 1;
        p_leaflist[1].m_nAllocationCount = (int)p_leaflist->m_pMemory;
        if ( v12 > 0 )
          _V_memmove(dest: &v11[(_DWORD)m_pMemory + 1], src: &v11[(_DWORD)m_pMemory], count: 2 * v12);
        v13 = &p_leaflist->m_pMemory[(_DWORD)m_pMemory];
        if ( v13 != nullptr )
          *v13 = i;
        for ( j = p_visframe[1]; j != 0; j = *(_DWORD *)(j + 8) )
        {
          if ( *(_DWORD *)(j + 4) == visframe )
            break;
          m_Size = cache->nodelist.m_Size;
          v16 = cache->nodelist.m_Memory.m_nAllocationCount;
          v20 = (signed int)(j - (unsigned int)worldbrush->nodes) >> 6;
          if ( m_Size + 1 > v16 )
            CUtlMemory<wchar_t,int>::Grow(this: (CUtlMemory<wchar_t,int> *)&cache->nodelist, num: m_Size - v16 + 1);
          ++cache->nodelist.m_Size;
          v17 = cache->nodelist.m_Memory.m_pMemory;
          v18 = cache->nodelist.m_Size - m_Size - 1;
          cache->nodelist.m_pElements = v17;
          if ( v18 > 0 )
            _V_memmove(dest: &v17[m_Size + 1], src: &v17[m_Size], count: 2 * v18);
          v19 = &cache->nodelist.m_Memory.m_pMemory[m_Size];
          if ( v19 != nullptr )
            *v19 = v20;
          *(_DWORD *)(j + 4) = visframe;
        }
        v6 = worldbrush;
        p_leaflist = (CUtlMemory<wchar_t,int> *)&cache->leaflist;
      }
      p_visframe += 16;
      ++i;
    }
    while ( i < v6->numleafs );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A50D0
// Name: void Map_VisMark(bool,struct model_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Map_VisMark(bool forcenovis, model_t *worldmodel)
{
  int v2; // eax
  int *p_viewcluster; // edx
  int v4; // edi
  int v5; // edx
  ConVar *m_pParent; // esi
  bool v7; // bl
  int *v8; // ecx
  int v9; // eax
  int v10; // esi
  int *v11; // ebx
  int i; // eax
  int m_Next; // ebx
  UtlLinkedListElem_t<VisCacheEntry,unsigned short> *v14; // esi
  int v15; // eax
  int *v16; // edx
  int *originclusters; // ecx
  unsigned __int16 v18; // ax
  int v19; // esi
  UtlLinkedListElem_t<VisCacheEntry,unsigned short> *v20; // eax
  worldbrushdata_t *pShared; // eax
  int v22; // edx
  int v23; // esi
  worldbrushdata_t *v24; // eax
  int v25; // edx
  int v26; // esi
  unsigned __int8 dest[4]; // [esp+0h] [ebp-2008h] BYREF
  int m_Head; // [esp+2000h] [ebp-8h]
  char v29; // [esp+2007h] [ebp-1h]

  if ( r_lockpvs.m_pParent == nullptr || r_lockpvs.m_pParent->m_Value.m_nValue == 0 )
  {
    SortVisViewClusters();
    v2 = 0;
    v29 = 0;
    if ( vis.nClusters <= 0 )
      goto LABEL_9;
    p_viewcluster = &vis.rgVisClusters[0].viewcluster;
    while ( *p_viewcluster == p_viewcluster[1] )
    {
      ++v2;
      p_viewcluster += 5;
      if ( v2 >= vis.nClusters )
        goto LABEL_9;
    }
    if ( v2 >= vis.nClusters )
    {
LABEL_9:
      if ( !forcenovis && vis.nClusters == vis.oldnClusters )
        return;
    }
    v4 = 1;
    ++r_visframecount;
    v5 = 0;
    vis.oldnClusters = vis.nClusters;
    if ( vis.nClusters > 0 )
    {
      m_pParent = r_portal_use_pvs_optimization.m_pParent;
      v7 = g_bNoClipEnabled;
      v8 = &vis.rgVisClusters[0].viewcluster;
      while ( 1 )
      {
        v9 = *v8;
        v8[1] = *v8;
        if ( v9 == -1 && (m_pParent == nullptr || m_pParent->m_Value.m_nValue == 0 || v7) )
          break;
        ++v5;
        v8 += 5;
        if ( v5 >= vis.nClusters )
          goto LABEL_20;
      }
      v29 = 1;
    }
LABEL_20:
    if ( r_novis.m_pParent != nullptr && r_novis.m_pParent->m_Value.m_nValue != 0 || forcenovis || v29 != 0 )
    {
      pShared = worldmodel->brush.pShared;
      v22 = 0;
      if ( pShared->numleafs > 0 )
      {
        v23 = 0;
        do
        {
          pShared->leafs[v23].visframe = r_visframecount;
          pShared = worldmodel->brush.pShared;
          ++v22;
          ++v23;
        }
        while ( v22 < pShared->numleafs );
      }
      v24 = worldmodel->brush.pShared;
      v25 = 0;
      if ( v24->numnodes > 0 )
      {
        v26 = 0;
        do
        {
          v24->nodes[v26].visframe = r_visframecount;
          v24 = worldmodel->brush.pShared;
          ++v25;
          ++v26;
        }
        while ( v25 < v24->numnodes );
      }
    }
    else
    {
      CM_Vis(dest: vis.rgCurrentVis, destlen: 0x2000, cluster: vis.rgVisClusters[0].viewcluster, visType: 0);
      v10 = (CM_NumClusters() + 31) / 32;
      if ( vis.nClusters > 1 )
      {
        v11 = &vis.rgVisClusters[1].viewcluster;
        do
        {
          CM_Vis(dest, destlen: 0x2000, cluster: *v11, visType: 0);
          for ( i = 0; i < v10; ++i )
            *(_DWORD *)&vis.rgCurrentVis[4 * i] |= *(_DWORD *)&dest[4 * i];
          ++v4;
          v11 += 5;
        }
        while ( v4 < vis.nClusters );
      }
      LOWORD(m_Next) = viscache.m_Head;
      m_Head = viscache.m_Head;
      if ( viscache.m_Head == 0xFFFF )
      {
LABEL_36:
        if ( viscache.m_ElementCount >= 8u )
        {
          CUtlLinkedList<VisCacheEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<VisCacheEntry,unsigned short>,unsigned short>>::LinkAfter(
            this: &viscache,
            after: 0xFFFFu,
            elem: viscache.m_Tail);
        }
        else
        {
          v18 = CUtlLinkedList<VisCacheEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<VisCacheEntry,unsigned short>,unsigned short>>::AllocInternal(
                  this: &viscache,
                  multilist: false);
          v19 = v18;
          if ( v18 != 0xFFFF )
          {
            CUtlLinkedList<VisCacheEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<VisCacheEntry,unsigned short>,unsigned short>>::LinkAfter(
              this: &viscache,
              after: 0xFFFFu,
              elem: v18);
            v20 = &viscache.m_Memory.m_pMemory[v19];
            if ( v20 != nullptr )
            {
              v20->m_Element.leaflist.m_Memory.m_pMemory = nullptr;
              v20->m_Element.leaflist.m_Memory.m_nAllocationCount = 0;
              v20->m_Element.leaflist.m_Memory.m_nGrowSize = 0;
              v20->m_Element.leaflist.m_Size = 0;
              v20->m_Element.leaflist.m_pElements = nullptr;
              v20->m_Element.nodelist.m_Memory.m_pMemory = nullptr;
              v20->m_Element.nodelist.m_Memory.m_nAllocationCount = 0;
              v20->m_Element.nodelist.m_Memory.m_nGrowSize = 0;
              v20->m_Element.nodelist.m_Size = 0;
              v20->m_Element.nodelist.m_pElements = nullptr;
              v20->m_Element.nClusters = 0;
            }
          }
        }
        VisCache_Build(
          cache: &viscache.m_Memory.m_pMemory[viscache.m_Head].m_Element,
          worldbrush: worldmodel->brush.pShared);
      }
      else
      {
        while ( 1 )
        {
          v14 = &viscache.m_Memory.m_pMemory[(unsigned __int16)m_Next];
          if ( v14->m_Element.nClusters == vis.nClusters )
            break;
next_cache_check:
          m_Next = v14->m_Next;
          m_Head = m_Next;
          if ( m_Next == 0xFFFF )
            goto LABEL_36;
        }
        v15 = 0;
        v16 = &vis.rgVisClusters[0].viewcluster;
        originclusters = v14->m_Element.originclusters;
        while ( v15 < v14->m_Element.nClusters )
        {
          if ( *originclusters != *v16 )
            goto next_cache_check;
          LOWORD(m_Next) = m_Head;
          ++v15;
          ++originclusters;
          v16 += 5;
        }
        CUtlLinkedList<VisCacheEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<VisCacheEntry,unsigned short>,unsigned short>>::LinkAfter(
          this: &viscache,
          after: 0xFFFFu,
          elem: m_Next);
        VisMark_Cached(cache: &v14->m_Element);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A53F0
// Name: void Map_VisSetup(struct model_t __near *,int,class Vector const __near * const,bool,unsigned int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Map_VisSetup(
        model_t *worldmodel,
        int visorigincount,
        const Vector *origins,
        bool forcenovis,
        unsigned int *returnFlags)
{
  float *p_z; // esi
  int v7; // ebx
  char v8; // al
  int i; // [esp+Ch] [ebp+Ch]

  vis.nClusters = visorigincount;
  if ( visorigincount >= 32 )
    vis.nClusters = 32;
  *(_WORD *)&vis.bSkyVisible = 0;
  *returnFlags = 0;
  i = 0;
  if ( vis.nClusters > 0 )
  {
    p_z = &vis.rgVisClusters[0].origin.z;
    do
    {
      v7 = CM_PointLeafnum(p: origins);
      v8 = CM_LeafFlags(leafnum: v7);
      if ( (v8 & 5) != 0 )
        vis.bSkyVisible = true;
      if ( (v8 & 2) != 0 )
      {
        vis.bForceFullSky = true;
        *returnFlags |= 1u;
      }
      *((_DWORD *)p_z + 1) = CM_LeafCluster(leafnum: v7);
      *(p_z - 2) = origins->x;
      *(p_z - 1) = origins->y;
      p_z += 5;
      *(p_z - 5) = origins->z;
      ++origins;
      ++i;
    }
    while ( i < vis.nClusters );
  }
  if ( !vis.bSkyVisible )
    vis.bForceFullSky = false;
  Map_VisMark(forcenovis, worldmodel);
}

//------------------------------------------------------------------------------
// Address: 0x101A54C0
// Name: void Map_VisClear(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Map_VisClear()
{
  float *p_y; // eax
  UtlLinkedListElem_t<VisCacheEntry,unsigned short> *v1; // esi
  unsigned __int16 m_Next; // bx
  unsigned __int16 *m_pMemory; // eax
  unsigned __int16 *v4; // eax
  unsigned __int16 m_FirstFree; // ax
  unsigned __int16 m_Head; // [esp+0h] [ebp-4h]

  vis.nClusters = 1;
  vis.oldnClusters = 1;
  p_y = &vis.rgVisClusters[0].origin.y;
  do
  {
    p_y[3] = NAN;
    p_y[1] = 0.0;
    *p_y = 0.0;
    *(p_y - 1) = 0.0;
    p_y[2] = NAN;
    p_y += 5;
  }
  while ( (int)p_y < (int)&vis.rgCurrentVis[4] );
  if ( viscache.m_LastAlloc.index != 0xFFFF )
  {
    m_Head = viscache.m_Head;
    if ( viscache.m_Head != 0xFFFF )
    {
      do
      {
        v1 = &viscache.m_Memory.m_pMemory[m_Head];
        m_Next = v1->m_Next;
        v1->m_Element.nodelist.m_Size = 0;
        if ( v1->m_Element.nodelist.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v1->m_Element.nodelist.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v1->m_Element.nodelist.m_Memory.m_pMemory);
            v1->m_Element.nodelist.m_Memory.m_pMemory = nullptr;
          }
          v1->m_Element.nodelist.m_Memory.m_nAllocationCount = 0;
        }
        m_pMemory = v1->m_Element.nodelist.m_Memory.m_pMemory;
        v1->m_Element.nodelist.m_pElements = m_pMemory;
        if ( v1->m_Element.nodelist.m_Memory.m_nGrowSize >= 0 )
        {
          if ( m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
            v1->m_Element.nodelist.m_Memory.m_pMemory = nullptr;
          }
          v1->m_Element.nodelist.m_Memory.m_nAllocationCount = 0;
        }
        v1->m_Element.leaflist.m_Size = 0;
        if ( v1->m_Element.leaflist.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v1->m_Element.leaflist.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v1->m_Element.leaflist.m_Memory.m_pMemory);
            v1->m_Element.leaflist.m_Memory.m_pMemory = nullptr;
          }
          v1->m_Element.leaflist.m_Memory.m_nAllocationCount = 0;
        }
        v4 = v1->m_Element.leaflist.m_Memory.m_pMemory;
        v1->m_Element.leaflist.m_pElements = v4;
        if ( v1->m_Element.leaflist.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v4 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
            v1->m_Element.leaflist.m_Memory.m_pMemory = nullptr;
          }
          v1->m_Element.leaflist.m_Memory.m_nAllocationCount = 0;
        }
        v1->m_Previous = m_Head;
        m_FirstFree = viscache.m_FirstFree;
        if ( m_Next != 0xFFFF )
          m_FirstFree = m_Next;
        v1->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
      if ( viscache.m_Head != 0xFFFF )
        viscache.m_FirstFree = viscache.m_Head;
    }
    *(_DWORD *)&viscache.m_Head = -1;
    viscache.m_ElementCount = 0;
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x101A4B10
// Name: SortVisViewClusters
// Source: json
//------------------------------------------------------------------------------
void SortVisViewClusters()
{
  int v0; // esi
  int *p_viewcluster; // ebx
  int v2; // edi
  int v3; // eax
  int *v4; // ecx

  v0 = 1;
  if ( vis.nClusters > 1 )
  {
    p_viewcluster = &vis.rgVisClusters[0].viewcluster;
    do
    {
      v2 = p_viewcluster[5];
      v3 = v0;
      if ( v0 > 0 )
      {
        v4 = p_viewcluster;
        do
        {
          if ( *v4 <= v2 )
            break;
          v4[5] = *v4;
          --v3;
          v4 -= 5;
        }
        while ( v3 > 0 );
      }
      ++v0;
      vis.rgVisClusters[v3].viewcluster = v2;
      p_viewcluster += 5;
    }
    while ( v0 < vis.nClusters );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A4B60
// Name: bool Map_AreAnyLeavesVisible(struct worldbrushdata_t const __near &,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl Map_AreAnyLeavesVisible(const worldbrushdata_t *worldbrush, int *leafList, int nLeaves)
{
  int v3; // esi
  int cluster; // eax

  v3 = 0;
  if ( nLeaves <= 0 )
    return 0;
  while ( 1 )
  {
    cluster = worldbrush->leafs[leafList[v3]].cluster;
    if ( cluster != -1 && ((unsigned __int8)(1 << (cluster & 7)) & vis.rgCurrentVis[cluster >> 3]) != 0 )
      break;
    if ( ++v3 >= nLeaves )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101A4BC0
// Name: unsigned char __near * Map_VisCurrent(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl Map_VisCurrent()
{
  return vis.rgCurrentVis;
}

//------------------------------------------------------------------------------
// Address: 0x101A4BD0
// Name: int Map_VisCurrentCluster(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Map_VisCurrentCluster()
{
  int result; // eax

  result = vis.rgVisClusters[0].viewcluster;
  if ( vis.rgVisClusters[0].viewcluster < 0 && ++visclusterwarningcount <= 5 )
  {
    _ConDMsg(a1: "Map_VisCurrentCluster() < 0!\n");
    return vis.rgVisClusters[0].viewcluster;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A4C00
// Name: bool Map_VisForceFullSky(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Map_VisForceFullSky()
{
  return vis.bForceFullSky;
}

//------------------------------------------------------------------------------
// Address: 0x101A4CC0
// Name: VisMark_Cached
// Source: json
//------------------------------------------------------------------------------
void __cdecl VisMark_Cached(const VisCacheEntry *cache)
{
  const worldbrushdata_t *worldbrush; // ecx
  int v2; // eax
  const VisCacheEntry *v3; // edi
  int m_Size; // esi
  unsigned __int16 *m_pMemory; // edx
  int v6; // edi
  bool v7; // zf
  int v8; // edi
  int v9; // esi
  unsigned __int16 *v10; // edx
  int v11; // edi
  int v12; // edi
  unsigned int v13; // [esp+Ch] [ebp-4h]
  const VisCacheEntry *cachea; // [esp+18h] [ebp+8h]

  v2 = r_visframecount;
  v3 = cache;
  m_Size = cache->leaflist.m_Size;
  m_pMemory = cache->leaflist.m_Memory.m_pMemory;
  if ( m_Size >= 8 )
  {
    v13 = (unsigned int)m_Size >> 3;
    m_Size -= 8 * ((unsigned int)m_Size >> 3);
    do
    {
      worldbrush->leafs[*m_pMemory].visframe = v2;
      worldbrush->leafs[m_pMemory[1]].visframe = v2;
      worldbrush->leafs[m_pMemory[2]].visframe = v2;
      worldbrush->leafs[m_pMemory[3]].visframe = v2;
      worldbrush->leafs[m_pMemory[4]].visframe = v2;
      worldbrush->leafs[m_pMemory[5]].visframe = v2;
      worldbrush->leafs[m_pMemory[6]].visframe = v2;
      v6 = m_pMemory[7] << 6;
      m_pMemory += 8;
      v7 = v13-- == 1;
      *(int *)((char *)&worldbrush->leafs->visframe + v6) = v2;
    }
    while ( !v7 );
    v3 = cache;
  }
  if ( m_Size != 0 )
  {
    do
    {
      v8 = *m_pMemory++ << 6;
      --m_Size;
      *(int *)((char *)&worldbrush->leafs->visframe + v8) = v2;
    }
    while ( m_Size != 0 );
    v3 = cache;
  }
  v9 = v3->nodelist.m_Size;
  v10 = v3->nodelist.m_Memory.m_pMemory;
  if ( v9 >= 8 )
  {
    cachea = (const VisCacheEntry *)((unsigned int)v9 >> 3);
    v9 -= 8 * ((unsigned int)v9 >> 3);
    do
    {
      worldbrush->nodes[*v10].visframe = v2;
      worldbrush->nodes[v10[1]].visframe = v2;
      worldbrush->nodes[v10[2]].visframe = v2;
      worldbrush->nodes[v10[3]].visframe = v2;
      worldbrush->nodes[v10[4]].visframe = v2;
      worldbrush->nodes[v10[5]].visframe = v2;
      worldbrush->nodes[v10[6]].visframe = v2;
      v11 = v10[7] << 6;
      v10 += 8;
      v7 = cachea == (const VisCacheEntry *)1;
      cachea = (const VisCacheEntry *)((char *)cachea - 1);
      *(int *)((char *)&worldbrush->nodes->visframe + v11) = v2;
    }
    while ( !v7 );
  }
  for ( ; v9 != 0; *(int *)((char *)&worldbrush->nodes->visframe + v12) = v2 )
  {
    v12 = *v10++ << 6;
    --v9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A5170
// Name: VisCache_Build
// Source: json
//------------------------------------------------------------------------------
void __usercall VisCache_Build(VisCacheEntry *cache@<eax>, const worldbrushdata_t *worldbrush)
{
  int v3; // eax
  int *p_viewcluster; // ecx
  int *originclusters; // edx
  const worldbrushdata_t *v6; // eax
  CUtlMemory<wchar_t,int> *p_leaflist; // ebx
  int v8; // edi
  wchar_t *m_pMemory; // edi
  int m_nAllocationCount; // eax
  wchar_t *v11; // ecx
  int v12; // eax
  wchar_t *v13; // edi
  int j; // ebx
  int m_Size; // edi
  int v16; // eax
  unsigned __int16 *v17; // ecx
  int v18; // eax
  unsigned __int16 *v19; // edi
  unsigned __int16 v20; // [esp+10h] [ebp-10h]
  int i; // [esp+14h] [ebp-Ch]
  int visframe; // [esp+18h] [ebp-8h]
  int *p_visframe; // [esp+1Ch] [ebp-4h]

  if ( (_S1_17 & 1) == 0 )
  {
    _S1_17 |= 1u;
    counter_8.m_pCounter = CVProfile::FindOrCreateCounter(
                             this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                             a2: "VisCache misses",
                             a3: COUNTER_GROUP_DEFAULT);
    atexit(func: VisCache_Build_::_4_::_dynamic_atexit_destructor_for___counter__);
  }
  ++*counter_8.m_pCounter;
  cache->nClusters = vis.nClusters;
  v3 = 0;
  if ( vis.nClusters > 0 )
  {
    p_viewcluster = &vis.rgVisClusters[0].viewcluster;
    originclusters = cache->originclusters;
    do
    {
      *originclusters = *p_viewcluster;
      ++v3;
      p_viewcluster += 5;
      ++originclusters;
    }
    while ( v3 < vis.nClusters );
  }
  v6 = worldbrush;
  p_leaflist = (CUtlMemory<wchar_t,int> *)&cache->leaflist;
  cache->leaflist.m_Size = 0;
  cache->nodelist.m_Size = 0;
  visframe = r_visframecount;
  i = 0;
  if ( worldbrush->numleafs > 0 )
  {
    p_visframe = &worldbrush->leafs->visframe;
    do
    {
      v8 = *((__int16 *)p_visframe + 22);
      if ( v8 != -1 && ((unsigned __int8)(1 << (v8 & 7)) & vis.rgCurrentVis[v8 >> 3]) != 0 )
      {
        *p_visframe = visframe;
        m_pMemory = p_leaflist[1].m_pMemory;
        m_nAllocationCount = p_leaflist->m_nAllocationCount;
        if ( (int)m_pMemory + 1 > m_nAllocationCount )
          CUtlMemory<wchar_t,int>::Grow(this: p_leaflist, num: (int)m_pMemory - m_nAllocationCount + 1);
        ++p_leaflist[1].m_pMemory;
        v11 = p_leaflist->m_pMemory;
        v12 = (char *)p_leaflist[1].m_pMemory - (char *)m_pMemory - 1;
        p_leaflist[1].m_nAllocationCount = (int)p_leaflist->m_pMemory;
        if ( v12 > 0 )
          _V_memmove(dest: &v11[(_DWORD)m_pMemory + 1], src: &v11[(_DWORD)m_pMemory], count: 2 * v12);
        v13 = &p_leaflist->m_pMemory[(_DWORD)m_pMemory];
        if ( v13 != nullptr )
          *v13 = i;
        for ( j = p_visframe[1]; j != 0; j = *(_DWORD *)(j + 8) )
        {
          if ( *(_DWORD *)(j + 4) == visframe )
            break;
          m_Size = cache->nodelist.m_Size;
          v16 = cache->nodelist.m_Memory.m_nAllocationCount;
          v20 = (signed int)(j - (unsigned int)worldbrush->nodes) >> 6;
          if ( m_Size + 1 > v16 )
            CUtlMemory<wchar_t,int>::Grow(this: (CUtlMemory<wchar_t,int> *)&cache->nodelist, num: m_Size - v16 + 1);
          ++cache->nodelist.m_Size;
          v17 = cache->nodelist.m_Memory.m_pMemory;
          v18 = cache->nodelist.m_Size - m_Size - 1;
          cache->nodelist.m_pElements = v17;
          if ( v18 > 0 )
            _V_memmove(dest: &v17[m_Size + 1], src: &v17[m_Size], count: 2 * v18);
          v19 = &cache->nodelist.m_Memory.m_pMemory[m_Size];
          if ( v19 != nullptr )
            *v19 = v20;
          *(_DWORD *)(j + 4) = visframe;
        }
        v6 = worldbrush;
        p_leaflist = (CUtlMemory<wchar_t,int> *)&cache->leaflist;
      }
      p_visframe += 16;
      ++i;
    }
    while ( i < v6->numleafs );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A54F0
// Name: void Map_VisMark(bool,struct model_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Map_VisMark(bool forcenovis, model_t *worldmodel)
{
  int v2; // eax
  int *p_viewcluster; // edx
  int v4; // edi
  int v5; // edx
  ConVar *m_pParent; // esi
  bool v7; // bl
  int *v8; // ecx
  int v9; // eax
  int v10; // esi
  int *v11; // ebx
  int i; // eax
  int m_Next; // ebx
  UtlLinkedListElem_t<VisCacheEntry,unsigned short> *v14; // esi
  int v15; // eax
  int *v16; // edx
  int *originclusters; // ecx
  unsigned __int16 v18; // ax
  int v19; // esi
  UtlLinkedListElem_t<VisCacheEntry,unsigned short> *v20; // eax
  worldbrushdata_t *pShared; // eax
  int v22; // edx
  int v23; // esi
  worldbrushdata_t *v24; // eax
  int v25; // edx
  int v26; // esi
  unsigned __int8 dest[4]; // [esp+0h] [ebp-2008h] BYREF
  int m_Head; // [esp+2000h] [ebp-8h]
  char v29; // [esp+2007h] [ebp-1h]

  if ( r_lockpvs.m_pParent == nullptr || r_lockpvs.m_pParent->m_Value.m_nValue == 0 )
  {
    SortVisViewClusters();
    v2 = 0;
    v29 = 0;
    if ( vis.nClusters <= 0 )
      goto LABEL_9;
    p_viewcluster = &vis.rgVisClusters[0].viewcluster;
    while ( *p_viewcluster == p_viewcluster[1] )
    {
      ++v2;
      p_viewcluster += 5;
      if ( v2 >= vis.nClusters )
        goto LABEL_9;
    }
    if ( v2 >= vis.nClusters )
    {
LABEL_9:
      if ( !forcenovis && vis.nClusters == vis.oldnClusters )
        return;
    }
    v4 = 1;
    ++r_visframecount;
    v5 = 0;
    vis.oldnClusters = vis.nClusters;
    if ( vis.nClusters > 0 )
    {
      m_pParent = r_portal_use_pvs_optimization.m_pParent;
      v7 = g_bNoClipEnabled;
      v8 = &vis.rgVisClusters[0].viewcluster;
      while ( 1 )
      {
        v9 = *v8;
        v8[1] = *v8;
        if ( v9 == -1 && (m_pParent == nullptr || m_pParent->m_Value.m_nValue == 0 || v7) )
          break;
        ++v5;
        v8 += 5;
        if ( v5 >= vis.nClusters )
          goto LABEL_20;
      }
      v29 = 1;
    }
LABEL_20:
    if ( r_novis.m_pParent != nullptr && r_novis.m_pParent->m_Value.m_nValue != 0 || forcenovis || v29 != 0 )
    {
      pShared = worldmodel->brush.pShared;
      v22 = 0;
      if ( pShared->numleafs > 0 )
      {
        v23 = 0;
        do
        {
          pShared->leafs[v23].visframe = r_visframecount;
          pShared = worldmodel->brush.pShared;
          ++v22;
          ++v23;
        }
        while ( v22 < pShared->numleafs );
      }
      v24 = worldmodel->brush.pShared;
      v25 = 0;
      if ( v24->numnodes > 0 )
      {
        v26 = 0;
        do
        {
          v24->nodes[v26].visframe = r_visframecount;
          v24 = worldmodel->brush.pShared;
          ++v25;
          ++v26;
        }
        while ( v25 < v24->numnodes );
      }
    }
    else
    {
      CM_Vis(dest: vis.rgCurrentVis, destlen: 0x2000, cluster: vis.rgVisClusters[0].viewcluster, visType: 0);
      v10 = (CM_NumClusters() + 31) / 32;
      if ( vis.nClusters > 1 )
      {
        v11 = &vis.rgVisClusters[1].viewcluster;
        do
        {
          CM_Vis(dest, destlen: 0x2000, cluster: *v11, visType: 0);
          for ( i = 0; i < v10; ++i )
            *(_DWORD *)&vis.rgCurrentVis[4 * i] |= *(_DWORD *)&dest[4 * i];
          ++v4;
          v11 += 5;
        }
        while ( v4 < vis.nClusters );
      }
      LOWORD(m_Next) = viscache.m_Head;
      m_Head = viscache.m_Head;
      if ( viscache.m_Head == 0xFFFF )
      {
LABEL_36:
        if ( viscache.m_ElementCount >= 8u )
        {
          CUtlLinkedList<VisCacheEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<VisCacheEntry,unsigned short>,unsigned short>>::LinkAfter(
            this: &viscache,
            after: 0xFFFFu,
            elem: viscache.m_Tail);
        }
        else
        {
          v18 = CUtlLinkedList<VisCacheEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<VisCacheEntry,unsigned short>,unsigned short>>::AllocInternal(
                  this: &viscache,
                  multilist: false);
          v19 = v18;
          if ( v18 != 0xFFFF )
          {
            CUtlLinkedList<VisCacheEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<VisCacheEntry,unsigned short>,unsigned short>>::LinkAfter(
              this: &viscache,
              after: 0xFFFFu,
              elem: v18);
            v20 = &viscache.m_Memory.m_pMemory[v19];
            if ( v20 != nullptr )
            {
              v20->m_Element.leaflist.m_Memory.m_pMemory = nullptr;
              v20->m_Element.leaflist.m_Memory.m_nAllocationCount = 0;
              v20->m_Element.leaflist.m_Memory.m_nGrowSize = 0;
              v20->m_Element.leaflist.m_Size = 0;
              v20->m_Element.leaflist.m_pElements = nullptr;
              v20->m_Element.nodelist.m_Memory.m_pMemory = nullptr;
              v20->m_Element.nodelist.m_Memory.m_nAllocationCount = 0;
              v20->m_Element.nodelist.m_Memory.m_nGrowSize = 0;
              v20->m_Element.nodelist.m_Size = 0;
              v20->m_Element.nodelist.m_pElements = nullptr;
              v20->m_Element.nClusters = 0;
            }
          }
        }
        VisCache_Build(
          cache: &viscache.m_Memory.m_pMemory[viscache.m_Head].m_Element,
          worldbrush: worldmodel->brush.pShared);
      }
      else
      {
        while ( 1 )
        {
          v14 = &viscache.m_Memory.m_pMemory[(unsigned __int16)m_Next];
          if ( v14->m_Element.nClusters == vis.nClusters )
            break;
next_cache_check:
          m_Next = v14->m_Next;
          m_Head = m_Next;
          if ( m_Next == 0xFFFF )
            goto LABEL_36;
        }
        v15 = 0;
        v16 = &vis.rgVisClusters[0].viewcluster;
        originclusters = v14->m_Element.originclusters;
        while ( v15 < v14->m_Element.nClusters )
        {
          if ( *originclusters != *v16 )
            goto next_cache_check;
          LOWORD(m_Next) = m_Head;
          ++v15;
          ++originclusters;
          v16 += 5;
        }
        CUtlLinkedList<VisCacheEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<VisCacheEntry,unsigned short>,unsigned short>>::LinkAfter(
          this: &viscache,
          after: 0xFFFFu,
          elem: m_Next);
        VisMark_Cached(cache: &v14->m_Element);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A5810
// Name: void Map_VisSetup(struct model_t __near *,int,class Vector const __near * const,bool,unsigned int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Map_VisSetup(
        model_t *worldmodel,
        int visorigincount,
        const Vector *origins,
        bool forcenovis,
        unsigned int *returnFlags)
{
  float *p_z; // esi
  int v7; // ebx
  char v8; // al
  int i; // [esp+Ch] [ebp+Ch]

  vis.nClusters = visorigincount;
  if ( visorigincount >= 32 )
    vis.nClusters = 32;
  *(_WORD *)&vis.bSkyVisible = 0;
  *returnFlags = 0;
  i = 0;
  if ( vis.nClusters > 0 )
  {
    p_z = &vis.rgVisClusters[0].origin.z;
    do
    {
      v7 = CM_PointLeafnum(p: origins);
      v8 = CM_LeafFlags(leafnum: v7);
      if ( (v8 & 5) != 0 )
        vis.bSkyVisible = true;
      if ( (v8 & 2) != 0 )
      {
        vis.bForceFullSky = true;
        *returnFlags |= 1u;
      }
      *((_DWORD *)p_z + 1) = CM_LeafCluster(leafnum: v7);
      *(p_z - 2) = origins->x;
      *(p_z - 1) = origins->y;
      p_z += 5;
      *(p_z - 5) = origins->z;
      ++origins;
      ++i;
    }
    while ( i < vis.nClusters );
  }
  if ( !vis.bSkyVisible )
    vis.bForceFullSky = false;
  Map_VisMark(forcenovis, worldmodel);
}

//------------------------------------------------------------------------------
// Address: 0x101A58E0
// Name: void Map_VisClear(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Map_VisClear()
{
  float *p_y; // eax
  UtlLinkedListElem_t<VisCacheEntry,unsigned short> *v1; // esi
  unsigned __int16 m_Next; // bx
  unsigned __int16 *m_pMemory; // eax
  unsigned __int16 *v4; // eax
  unsigned __int16 m_FirstFree; // ax
  unsigned __int16 m_Head; // [esp+0h] [ebp-4h]

  vis.nClusters = 1;
  vis.oldnClusters = 1;
  p_y = &vis.rgVisClusters[0].origin.y;
  do
  {
    p_y[3] = NAN;
    p_y[1] = 0.0;
    *p_y = 0.0;
    *(p_y - 1) = 0.0;
    p_y[2] = NAN;
    p_y += 5;
  }
  while ( (int)p_y < (int)&vis.rgCurrentVis[4] );
  if ( viscache.m_LastAlloc.index != 0xFFFF )
  {
    m_Head = viscache.m_Head;
    if ( viscache.m_Head != 0xFFFF )
    {
      do
      {
        v1 = &viscache.m_Memory.m_pMemory[m_Head];
        m_Next = v1->m_Next;
        v1->m_Element.nodelist.m_Size = 0;
        if ( v1->m_Element.nodelist.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v1->m_Element.nodelist.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v1->m_Element.nodelist.m_Memory.m_pMemory);
            v1->m_Element.nodelist.m_Memory.m_pMemory = nullptr;
          }
          v1->m_Element.nodelist.m_Memory.m_nAllocationCount = 0;
        }
        m_pMemory = v1->m_Element.nodelist.m_Memory.m_pMemory;
        v1->m_Element.nodelist.m_pElements = m_pMemory;
        if ( v1->m_Element.nodelist.m_Memory.m_nGrowSize >= 0 )
        {
          if ( m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
            v1->m_Element.nodelist.m_Memory.m_pMemory = nullptr;
          }
          v1->m_Element.nodelist.m_Memory.m_nAllocationCount = 0;
        }
        v1->m_Element.leaflist.m_Size = 0;
        if ( v1->m_Element.leaflist.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v1->m_Element.leaflist.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v1->m_Element.leaflist.m_Memory.m_pMemory);
            v1->m_Element.leaflist.m_Memory.m_pMemory = nullptr;
          }
          v1->m_Element.leaflist.m_Memory.m_nAllocationCount = 0;
        }
        v4 = v1->m_Element.leaflist.m_Memory.m_pMemory;
        v1->m_Element.leaflist.m_pElements = v4;
        if ( v1->m_Element.leaflist.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v4 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
            v1->m_Element.leaflist.m_Memory.m_pMemory = nullptr;
          }
          v1->m_Element.leaflist.m_Memory.m_nAllocationCount = 0;
        }
        v1->m_Previous = m_Head;
        m_FirstFree = viscache.m_FirstFree;
        if ( m_Next != 0xFFFF )
          m_FirstFree = m_Next;
        v1->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
      if ( viscache.m_Head != 0xFFFF )
        viscache.m_FirstFree = viscache.m_Head;
    }
    *(_DWORD *)&viscache.m_Head = -1;
    viscache.m_ElementCount = 0;
  }
}

} // namespace engine_xlsp
