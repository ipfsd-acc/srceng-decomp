// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vmap/vmap.cpp
// Functions: 19
// ============================================================

#include "utils\vmap\vmap.h"

//------------------------------------------------------------------------------
// Address: 0x00433900
// Name: struct node_t __near * BlockTree(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
node_t *__cdecl BlockTree(int xl, int yl, int xh, int yh)
{
  node_t *result; // eax
  node_t *v6; // esi
  node_t *v7; // eax
  Vector normal; // [esp+10h] [ebp-Ch] BYREF
  int mid; // [esp+24h] [ebp+8h]

  if ( xl == xh && yl == yh )
  {
    result = *(&block_nodes[xl][514 * g_MapBlocks.xOffset] + yl + g_MapBlocks.yOffset);
    if ( result == nullptr )
    {
      result = AllocNode();
      result->planenum = -1;
      result->contents = 0;
    }
  }
  else
  {
    v6 = AllocNode();
    if ( xh - xl <= yh - yl )
    {
      normal.x = 0.0;
      normal.z = 0.0;
      mid = (yh - yl) / 2 + yl + 1;
      normal.y = 1.0;
      v6->planenum = FindFloatPlane(&normal, dist: COERCE_UNSIGNED_INT((float)(mid * g_MapBlocks.blockSize)));
      v6->children[0] = BlockTree(xl, yl: mid, xh, yh);
      v7 = BlockTree(xl, yl, xh, yh: mid - 1);
    }
    else
    {
      normal.x = 1.0;
      normal.y = 0.0;
      normal.z = 0.0;
      v6->planenum = FindFloatPlane(
                       &normal,
                       dist: COERCE_UNSIGNED_INT((float)(((xh - xl) / 2 + xl + 1) * g_MapBlocks.blockSize)));
      v6->children[0] = BlockTree(xl: (xh - xl) / 2 + xl + 1, yl, xh, yh);
      v7 = BlockTree(xl, yl, xh: (xh - xl) / 2 + xl, yh);
    }
    v6->children[1] = v7;
    return v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00433A60
// Name: void ProcessBlock_Thread(int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ProcessBlock_Thread(int threadnum, int blocknum)
{
  int v2; // esi
  int v3; // edx
  int v4; // esi
  int v5; // edi
  bspbrush_t *BspBrushList; // eax
  bspbrush_t *v7; // ebx
  node_t *v8; // eax
  Vector mins; // [esp+Ch] [ebp-18h] BYREF
  Vector maxs; // [esp+18h] [ebp-Ch] BYREF

  v2 = g_MapBlocks.xEnd - g_MapBlocks.xStart + 1;
  v3 = blocknum % v2;
  v4 = blocknum / v2 + g_MapBlocks.yStart;
  v5 = v3 + g_MapBlocks.xStart;
  qprintf(format: "############### block %2i,%2i ###############\n", v3 + g_MapBlocks.xStart, v4);
  mins.x = (float)(v5 * g_MapBlocks.blockSize);
  mins.y = (float)(v4 * g_MapBlocks.blockSize);
  mins.z = -16384.0;
  maxs.x = (float)(g_MapBlocks.blockSize * (v5 + 1));
  maxs.y = (float)(g_MapBlocks.blockSize * (v4 + 1));
  maxs.z = 16384.0;
  BspBrushList = MakeBspBrushList(
                   startbrush: brush_start,
                   endbrush: brush_end,
                   clipmins: &mins,
                   clipmaxs: &maxs,
                   detailScreen: 2);
  v7 = BspBrushList;
  if ( BspBrushList != nullptr )
  {
    FixupAreaportalWaterBrushes(pList: BspBrushList);
    if ( nocsg == 0 )
      v7 = ChopBrushes(head: v7);
    *((_DWORD *)&block_nodes[v5][514 * g_MapBlocks.xOffset] + v4 + g_MapBlocks.yOffset) = BrushBSP(
                                                                                            brushlist: v7,
                                                                                            &mins,
                                                                                            &maxs)->headnode;
  }
  else
  {
    v8 = AllocNode();
    v8->planenum = -1;
    v8->contents = 1;
    *((_DWORD *)&block_nodes[v5][514 * g_MapBlocks.xOffset] + v4 + g_MapBlocks.yOffset) = v8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00433BB0
// Name: void ProcessSubModel(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ProcessSubModel()
{
  entity_t *v0; // esi
  int firstbrush; // eax
  int v2; // ebx
  bspbrush_t *BspBrushList; // eax
  tree_t *v4; // edi
  const char *v5; // eax
  Vector mins; // [esp+0h] [ebp-20h] BYREF
  Vector maxs; // [esp+Ch] [ebp-14h] BYREF
  int start; // [esp+18h] [ebp-8h]
  const char *pClassName; // [esp+1Ch] [ebp-4h]

  v0 = (entity_t *)((char *)&entities + 44 * entity_num);
  firstbrush = v0->firstbrush;
  v2 = firstbrush + v0->numbrushes;
  mins.z = -16384.0;
  mins.y = -16384.0;
  mins.x = -16384.0;
  start = firstbrush;
  maxs.z = 16384.0;
  maxs.y = 16384.0;
  maxs.x = 16384.0;
  BspBrushList = MakeBspBrushList(
                   startbrush: firstbrush,
                   endbrush: v2,
                   clipmins: &mins,
                   clipmaxs: &maxs,
                   detailScreen: 0);
  if ( nocsg == 0 )
    BspBrushList = ChopBrushes(head: BspBrushList);
  v4 = BrushBSP(brushlist: BspBrushList, &mins, &maxs);
  if ( v4->headnode->planenum == -1 )
  {
    pClassName = ValueForKey(ent: v0, key: "classname");
    v5 = ValueForKey(ent: v0, key: "targetname");
    _Error(a1: "bmodel %d has no head node (class '%s', targetname '%s')", entity_num, pClassName, v5);
  }
  MakeTreePortals(tree: v4);
  MarkVisibleSides(tree: v4, startbrush: start, endbrush: v2, detailScreen: 0);
  MakeFaces(node: v4->headnode);
  FixTjuncs(headnode: v4->headnode, pLeafFaceList: nullptr);
  WriteBSP(headnode: v4->headnode, pLeafFaceList: nullptr);
  FreeTree(tree: v4);
}

//------------------------------------------------------------------------------
// Address: 0x00433CC0
// Name: bool IsFuncOccluder(int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsFuncOccluder(int entity_num)
{
  return strcmp("func_occluder", ValueForKey(ent: (entity_t *)&entities + entity_num, key: "classname")) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x00433D20
// Name: void FixupOnlyEntsOccluderEntities(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FixupOnlyEntsOccluderEntities()
{
  int v0; // eax
  int v1; // esi
  char str[64]; // [esp+4h] [ebp-40h] BYREF

  v0 = 1;
  v1 = 0;
  for ( entity_num = 1; v0 < num_entities; entity_num = v0 )
  {
    if ( strcmp("func_occluder", ValueForKey(ent: (entity_t *)&entities + v0, key: "classname")) == 0 )
    {
      sprintf(string: str, format: "%i", v1);
      SetKeyValue(ent: (entity_t *)&entities + entity_num, key: "occludernumber", value: str, bAllowDuplicates: false);
      ++v1;
    }
    v0 = entity_num + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00433DE0
// Name: public: void blockparams_t::SetBlockSize(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall blockparams_t::SetBlockSize(blockparams_t *this, int blockSizeIn)
{
  int v2; // eax
  int v4; // ecx
  int v5; // eax
  int v6; // edx

  v2 = blockSizeIn;
  if ( blockSizeIn >= 64 )
  {
    if ( blockSizeIn > 4096 )
      v2 = 4096;
  }
  else
  {
    v2 = 64;
  }
  this->blockSize = v2;
  _Msg(a1: "Setting block size to %d\n", v2);
  v4 = 0x8000 / this->blockSize / -2;
  v5 = 0x8000 / this->blockSize / 2;
  v6 = v5++ - 1;
  this->xStart = v4;
  this->xEnd = v6;
  this->yStart = v4;
  this->yEnd = v6;
  this->xOffset = v5;
  this->yOffset = v5;
  this->blockMin = v4;
  this->blockMax = v6;
}

//------------------------------------------------------------------------------
// Address: 0x00433EF0
// Name: void AssignAreaToOccluder(int,struct tree_t __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AssignAreaToOccluder(int nOccluder, tree_t *pTree, bool bCrossAreaPortals)
{
  doccluderdata_t *m_pMemory; // edi
  int v4; // ebx
  int firstpoly; // ecx
  doccluderpolydata_t *v6; // eax
  int v7; // edx
  node_t *v8; // edi
  int area; // eax
  int v10; // ecx
  const char *v11; // eax
  portal_t *portals; // esi
  BOOL v13; // edi
  node_t *v14; // eax
  int v15; // eax
  int v16; // ecx
  const char *v17; // eax
  int *v18; // [esp+8h] [ebp-18h]
  node_t *pNode; // [esp+Ch] [ebp-14h]
  int v20; // [esp+10h] [ebp-10h]
  int j; // [esp+14h] [ebp-Ch]
  int k; // [esp+18h] [ebp-8h]
  int nEntityNum; // [esp+1Ch] [ebp-4h]
  int nOccludera; // [esp+28h] [ebp+8h]

  m_pMemory = g_OccluderData.m_Memory.m_pMemory;
  v4 = nOccluder;
  firstpoly = g_OccluderData.m_Memory.m_pMemory[nOccluder].firstpoly;
  nEntityNum = g_OccluderInfo.m_Memory.m_pMemory[nOccluder].m_nOccluderEntityIndex;
  j = 0;
  if ( g_OccluderData.m_Memory.m_pMemory[nOccluder].polycount > 0 )
  {
    v6 = g_OccluderPolyData.m_Memory.m_pMemory;
    v7 = 12 * firstpoly;
    v20 = 12 * firstpoly;
    do
    {
      k = 0;
      v18 = (int *)((char *)&v6->vertexcount + v7);
      if ( *v18 > 0 )
      {
        nOccludera = *(int *)((char *)&v6->firstvertexindex + v7);
        do
        {
          v8 = NodeForPoint(
                 node: pTree->headnode,
                 origin: &dvertexes + g_OccluderVertexIndices.m_Memory.m_pMemory[nOccludera]);
          area = g_OccluderData.m_Memory.m_pMemory[v4].area;
          v10 = v8->area;
          pNode = v8;
          if ( area > 0 )
          {
            if ( v10 != 0 && area != v10 )
            {
              v11 = ValueForKey(ent: (entity_t *)&entities + nEntityNum, key: "targetname");
              if ( v11 == nullptr )
                v11 = "<no name>";
              _Warning(a1: "Occluder \"%s\" straddles multiple areas. This is invalid!\n", v11);
            }
          }
          else
          {
            g_OccluderData.m_Memory.m_pMemory[v4].area = v10;
          }
          portals = v8->portals;
          if ( portals != nullptr )
          {
            while ( 1 )
            {
              v13 = portals->nodes[0] == v8;
              if ( portals->onnode != nullptr && (bCrossAreaPortals || (portals->nodes[v13]->contents & 0x8000) == 0) )
              {
                v14 = portals->nodes[v13];
                if ( v14 != nullptr )
                  v15 = v14->area;
                else
                  v15 = 0;
                v16 = g_OccluderData.m_Memory.m_pMemory[v4].area;
                if ( v16 > 0 )
                {
                  if ( v15 != 0 && v16 != v15 )
                  {
                    v17 = ValueForKey(ent: (entity_t *)&entities + nEntityNum, key: "targetname");
                    if ( v17 == nullptr )
                      v17 = "<no name>";
                    _Warning(a1: "Occluder \"%s\" straddles multiple areas. This is invalid!\n", v17);
                  }
                }
                else
                {
                  g_OccluderData.m_Memory.m_pMemory[v4].area = v15;
                }
              }
              portals = portals->next[!v13];
              if ( portals == nullptr )
                break;
              v8 = pNode;
            }
          }
          ++nOccludera;
          ++k;
        }
        while ( k < *v18 );
        v6 = g_OccluderPolyData.m_Memory.m_pMemory;
        v7 = v20;
        m_pMemory = g_OccluderData.m_Memory.m_pMemory;
      }
      v7 += 12;
      ++j;
      v20 = v7;
    }
    while ( j < m_pMemory[v4].polycount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004340D0
// Name: void AssignOccluderAreas(struct tree_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AssignOccluderAreas(tree_t *pTree)
{
  int v1; // esi
  int v2; // edi

  v1 = 0;
  if ( g_OccluderData.m_Size > 0 )
  {
    v2 = 0;
    do
    {
      AssignAreaToOccluder(nOccluder: v1, pTree, bCrossAreaPortals: false);
      if ( g_OccluderData.m_Memory.m_pMemory[v2].area <= 0 )
        AssignAreaToOccluder(nOccluder: v1, pTree, bCrossAreaPortals: true);
      ++v1;
      ++v2;
    }
    while ( v1 < g_OccluderData.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00434120
// Name: void MarkNoDynamicShadowSides(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MarkNoDynamicShadowSides()
{
  int v0; // edi
  bool *p_m_bDynamicShadowsEnabled; // eax
  int v2; // ecx
  int v3; // edx
  int *m_pMemory; // ebx
  int v5; // esi
  bool *v6; // eax
  int i; // ecx

  v0 = nummapbrushsides;
  if ( nummapbrushsides > 0 )
  {
    p_m_bDynamicShadowsEnabled = &brushsides[0].m_bDynamicShadowsEnabled;
    v2 = nummapbrushsides;
    do
    {
      *p_m_bDynamicShadowsEnabled = true;
      p_m_bDynamicShadowsEnabled += 100;
      --v2;
    }
    while ( v2 != 0 );
  }
  v3 = 0;
  if ( g_NoDynamicShadowSides.m_Size > 0 )
  {
    m_pMemory = g_NoDynamicShadowSides.m_Memory.m_pMemory;
    do
    {
      v5 = m_pMemory[v3];
      if ( v0 > 0 )
      {
        v6 = &brushsides[0].m_bDynamicShadowsEnabled;
        for ( i = v0; i != 0; --i )
        {
          if ( *((_DWORD *)v6 - 12) == v5 )
            *v6 = false;
          v6 += 100;
        }
      }
      ++v3;
    }
    while ( v3 < g_NoDynamicShadowSides.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00434180
// Name: bool Is3DSkyboxArea(int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl Is3DSkyboxArea(int area)
{
  int v1; // eax

  v1 = g_SkyAreas.m_Size - 1;
  if ( g_SkyAreas.m_Size - 1 < 0 )
    return 0;
  while ( g_SkyAreas.m_Memory.m_pMemory[v1] != area )
  {
    if ( --v1 < 0 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004341B0
// Name: ClipOccluderBrushes
// Source: json
//------------------------------------------------------------------------------
tree_t *__cdecl ClipOccluderBrushes()
{
  mapbrush_t **v0; // esi
  int v1; // eax
  int m_Size; // ebx
  bool v3; // zf
  int v4; // eax
  char *v5; // ecx
  int v6; // edx
  int v7; // ecx
  mapbrush_t *v8; // edi
  int v9; // esi
  mapbrush_t **m_pMemory; // ecx
  mapbrush_t **v11; // eax
  bspbrush_t *BspBrushList; // eax
  tree_t *v14; // esi
  mapbrush_t **v15; // edi
  CUtlVector<mapbrush_t *,CUtlMemory<mapbrush_t *,int> > mapBrushes; // [esp+Ch] [ebp-30h] BYREF
  Vector mins; // [esp+20h] [ebp-1Ch] BYREF
  Vector maxs; // [esp+2Ch] [ebp-10h] BYREF
  int v19; // [esp+38h] [ebp-4h]

  mapBrushes.m_Memory.m_nAllocationCount = 1024;
  mapBrushes.m_Memory.m_nGrowSize = 1024;
  v0 = (mapbrush_t **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4096);
  v1 = 0;
  m_Size = 0;
  mapBrushes.m_Memory.m_pMemory = v0;
  mapBrushes.m_Size = 0;
  mapBrushes.m_pElements = v0;
  entity_num = 0;
  if ( num_entities <= 0 )
    goto LABEL_15;
  do
  {
    v3 = strcmp("func_occluder", ValueForKey(ent: (entity_t *)&entities + v1, key: "classname")) == 0;
    v4 = entity_num;
    if ( v3 )
    {
      v5 = (char *)&entities + 44 * entity_num;
      v6 = *((_DWORD *)v5 + 3);
      v7 = v6 + *((_DWORD *)v5 + 4);
      if ( v6 < v7 )
      {
        v8 = &mapbrushes[v6];
        v19 = v7 - v6;
        do
        {
          v9 = m_Size;
          if ( m_Size + 1 > mapBrushes.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<HemiLightData_t *,int>::Grow(
              this: (CUtlMemory<S3RGBA,int> *)&mapBrushes,
              num: m_Size - mapBrushes.m_Memory.m_nAllocationCount + 1);
            m_Size = mapBrushes.m_Size;
          }
          m_pMemory = mapBrushes.m_Memory.m_pMemory;
          mapBrushes.m_Size = ++m_Size;
          mapBrushes.m_pElements = mapBrushes.m_Memory.m_pMemory;
          if ( m_Size - v9 - 1 > 0 )
          {
            _V_memmove(
              dest: &mapBrushes.m_Memory.m_pMemory[v9 + 1],
              src: &mapBrushes.m_Memory.m_pMemory[v9],
              count: 4 * (m_Size - v9 - 1));
            m_pMemory = mapBrushes.m_Memory.m_pMemory;
          }
          v11 = &m_pMemory[v9];
          if ( v11 != nullptr )
            *v11 = v8;
          ++v8;
          --v19;
        }
        while ( v19 != 0 );
        v4 = entity_num;
        v0 = mapBrushes.m_Memory.m_pMemory;
      }
    }
    v1 = v4 + 1;
    entity_num = v1;
  }
  while ( v1 < num_entities );
  if ( m_Size != 0 )
  {
    mins.z = -16384.0;
    mins.y = -16384.0;
    mins.x = -16384.0;
    maxs.z = 16384.0;
    maxs.y = 16384.0;
    maxs.x = 16384.0;
    BspBrushList = MakeBspBrushList(pBrushes: v0, nBrushCount: m_Size, clipmins: &mins, clipmaxs: &maxs);
    if ( nocsg == 0 )
      BspBrushList = ChopBrushes(head: BspBrushList);
    v14 = BrushBSP(brushlist: BspBrushList, &mins, &maxs);
    MakeTreePortals(tree: v14);
    v15 = mapBrushes.m_Memory.m_pMemory;
    MarkVisibleSides(tree: v14, ppBrushes: mapBrushes.m_Memory.m_pMemory, nCount: m_Size);
    MakeFaces(node: v14->headnode);
    FixTjuncs(headnode: v14->headnode, pLeafFaceList: nullptr);
    if ( mapBrushes.m_Memory.m_nGrowSize >= 0 && v15 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v15);
    return v14;
  }
  else
  {
LABEL_15:
    if ( mapBrushes.m_Memory.m_nGrowSize >= 0 && v0 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v0);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004343D0
// Name: GenerateOccluderSideList
// Source: json
//------------------------------------------------------------------------------
void __usercall GenerateOccluderSideList(int nEntity@<eax>, CUtlMemory<S3RGBA,int> *occluderSides@<esi>)
{
  char *v2; // eax
  int v3; // ecx
  int v4; // eax
  int *p_numsides; // edx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  side_t *v8; // ebx
  side_t **v9; // ecx
  int v10; // eax
  side_t **v11; // edi
  bool v12; // zf
  int v13; // [esp+0h] [ebp-10h]
  int j; // [esp+4h] [ebp-Ch]
  int *v15; // [esp+8h] [ebp-8h]
  int v16; // [esp+Ch] [ebp-4h]

  v2 = (char *)&entities + 44 * nEntity;
  v3 = *((_DWORD *)v2 + 3);
  v4 = v3 + *((_DWORD *)v2 + 4);
  if ( v3 < v4 )
  {
    p_numsides = &mapbrushes[v3].numsides;
    v15 = p_numsides;
    v13 = v4 - v3;
    do
    {
      j = 0;
      if ( *p_numsides > 0 )
      {
        v16 = 0;
        do
        {
          m_pMemory = (int)occluderSides[1].m_pMemory;
          m_nAllocationCount = occluderSides->m_nAllocationCount;
          v8 = (side_t *)(v16 + p_numsides[1]);
          if ( m_pMemory + 1 > m_nAllocationCount )
          {
            CUtlMemory<HemiLightData_t *,int>::Grow(this: occluderSides, num: m_pMemory - m_nAllocationCount + 1);
            p_numsides = v15;
          }
          ++occluderSides[1].m_pMemory;
          v9 = (side_t **)occluderSides->m_pMemory;
          v10 = (int)occluderSides[1].m_pMemory - m_pMemory - 1;
          occluderSides[1].m_nAllocationCount = (int)occluderSides->m_pMemory;
          if ( v10 > 0 )
          {
            _V_memmove(dest: &v9[m_pMemory + 1], src: &v9[m_pMemory], count: 4 * v10);
            p_numsides = v15;
          }
          v11 = (side_t **)&occluderSides->m_pMemory[m_pMemory];
          if ( v11 != nullptr )
            *v11 = v8;
          v16 += 100;
          ++j;
        }
        while ( j < *p_numsides );
      }
      p_numsides += 12;
      v12 = v13-- == 1;
      v15 = p_numsides;
    }
    while ( !v12 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00434490
// Name: GenerateOccluderFaceList
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateOccluderFaceList(
        node_t *pOccluderNode,
        CUtlVector<face_t *,CUtlMemory<face_t *,int> > *occluderFaces)
{
  node_t *v2; // edi
  face_t *faces; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  face_t **m_pMemory; // ecx
  int v7; // eax
  face_t **v8; // eax

  v2 = pOccluderNode;
  if ( pOccluderNode->planenum != -1 )
  {
    while ( 1 )
    {
      faces = v2->faces;
      if ( faces != nullptr )
      {
        do
        {
          m_Size = occluderFaces->m_Size;
          m_nAllocationCount = occluderFaces->m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<HemiLightData_t *,int>::Grow(
              this: (CUtlMemory<S3RGBA,int> *)occluderFaces,
              num: m_Size - m_nAllocationCount + 1);
          ++occluderFaces->m_Size;
          m_pMemory = occluderFaces->m_Memory.m_pMemory;
          v7 = occluderFaces->m_Size - m_Size - 1;
          occluderFaces->m_pElements = occluderFaces->m_Memory.m_pMemory;
          if ( v7 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
          v8 = &occluderFaces->m_Memory.m_pMemory[m_Size];
          if ( v8 != nullptr )
            *v8 = faces;
          faces = faces->next;
        }
        while ( faces != nullptr );
        v2 = pOccluderNode;
      }
      GenerateOccluderFaceList(pOccluderNode: v2->children[0], occluderFaces);
      pOccluderNode = v2->children[1];
      if ( pOccluderNode->planenum == -1 )
        break;
      v2 = v2->children[1];
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00434530
// Name: Compute3DSkyboxAreas
// Source: json
//------------------------------------------------------------------------------
void __usercall Compute3DSkyboxAreas(CUtlMemory<S3RGBA,int> *areas@<edi>, node_t *headnode)
{
  entity_t *v2; // esi
  node_t *v3; // ebx
  int m_pMemory; // esi
  int m_nAllocationCount; // eax
  int *v6; // ecx
  int v7; // eax
  int *v8; // eax
  int i; // [esp+20h] [ebp-8h]
  Vector *p_origin; // [esp+24h] [ebp-4h]

  i = 0;
  if ( num_entities > 0 )
  {
    v2 = (entity_t *)&entities;
    p_origin = &entities;
    do
    {
      if ( strcmp(ValueForKey(ent: v2, key: "classname"), "sky_camera") == 0 )
      {
        v3 = PointInLeaf(node: headnode, point: &v2->origin);
        if ( (v3->contents & 1) != 0 )
          _Error(
            a1: "Error! Entity sky_camera in solid volume! at %.1f %.1f %.1f\n",
            v2->origin.x,
            v2->origin.y,
            v2->origin.z);
        m_pMemory = (int)areas[1].m_pMemory;
        m_nAllocationCount = areas->m_nAllocationCount;
        if ( m_pMemory + 1 > m_nAllocationCount )
          CUtlMemory<HemiLightData_t *,int>::Grow(this: areas, num: m_pMemory - m_nAllocationCount + 1);
        ++areas[1].m_pMemory;
        v6 = (int *)areas->m_pMemory;
        v7 = (int)areas[1].m_pMemory - m_pMemory - 1;
        areas[1].m_nAllocationCount = (int)areas->m_pMemory;
        if ( v7 > 0 )
          _V_memmove(dest: &v6[m_pMemory + 1], src: &v6[m_pMemory], count: 4 * v7);
        v8 = (int *)&areas->m_pMemory[m_pMemory];
        v2 = (entity_t *)p_origin;
        if ( v8 != nullptr )
          *v8 = v3->area;
      }
      ++v2;
      ++i;
      p_origin = &v2->origin;
    }
    while ( i < num_entities );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00434660
// Name: void ProcessWorldModel(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall ProcessWorldModel(int a1@<ebx>, int a2@<edi>)
{
  __m128 x_low; // xmm2
  char *v3; // eax
  int v4; // ecx
  int xEnd; // esi
  __m128 v6; // xmm3
  __m128 v7; // xmm1
  __m128 v8; // xmm0
  __m128 v9; // xmm1
  int xStart; // edx
  __m128 v11; // xmm2
  __m128 v12; // xmm3
  __m128 v13; // xmm1
  __m128 v14; // xmm0
  __m128 v15; // xmm1
  int yEnd; // edi
  __m128 y_low; // xmm2
  __m128 v18; // xmm3
  __m128 v19; // xmm1
  __m128 v20; // xmm0
  __m128 v21; // xmm1
  int yStart; // ecx
  __m128 v23; // xmm2
  __m128 v24; // xmm3
  __m128 v25; // xmm1
  __m128 v26; // xmm0
  __m128 v27; // xmm1
  tree_t *v28; // esi
  double v29; // st7
  face_t *v30; // edi
  face_t *fixed; // edi
  double v32; // st7
  int v33; // [esp-Ch] [ebp-14h]
  int v34; // [esp-8h] [ebp-10h]
  int leaked; // [esp+0h] [ebp-8h]
  int start; // [esp+4h] [ebp-4h]
  int startb; // [esp+4h] [ebp-4h]
  int starta; // [esp+4h] [ebp-4h]

  x_low = (__m128)LODWORD(map_maxs.x);
  v3 = (char *)&entities + 44 * entity_num;
  v4 = *((_DWORD *)v3 + 3);
  brush_end = v4 + *((_DWORD *)v3 + 4);
  xEnd = g_MapBlocks.xEnd;
  brush_start = v4;
  v34 = a2;
  leaked = 0;
  if ( (float)(g_MapBlocks.xEnd * g_MapBlocks.blockSize) > map_maxs.x )
  {
    x_low.m128_f32[0] = map_maxs.x / (float)g_MapBlocks.blockSize;
    v6 = _mm_and_ps((__m128)0x80000000, x_low);
    v7.m128_i32[0] = 1258291200;
    v7.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(x_low, v6), v7).m128_f32[0]) & 0x4B000000
                   | v6.m128_i32[0];
    v8 = x_low;
    v8.m128_f32[0] = (float)(x_low.m128_f32[0] + v7.m128_f32[0]) - v7.m128_f32[0];
    v9 = v8;
    v9.m128_f32[0] = v8.m128_f32[0] - x_low.m128_f32[0];
    xEnd = (int)(float)(v8.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v9, v6).m128_u32[0] & 0x3F800000));
    g_MapBlocks.xEnd = xEnd;
  }
  xStart = g_MapBlocks.xStart;
  v11 = (__m128)LODWORD(map_mins.x);
  if ( map_mins.x > (float)(g_MapBlocks.blockSize * (g_MapBlocks.xStart + 1)) )
  {
    v11.m128_f32[0] = map_mins.x / (float)g_MapBlocks.blockSize;
    v12 = _mm_and_ps((__m128)0x80000000, v11);
    v13.m128_i32[0] = 1258291200;
    v13.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v11, v12), v13).m128_f32[0]) & 0x4B000000
                    | v12.m128_i32[0];
    v14 = v11;
    v14.m128_f32[0] = (float)(v11.m128_f32[0] + v13.m128_f32[0]) - v13.m128_f32[0];
    v15 = v14;
    v15.m128_f32[0] = v14.m128_f32[0] - v11.m128_f32[0];
    xStart = (int)(float)(v14.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v15, v12).m128_u32[0] & 0x3F800000));
    g_MapBlocks.xStart = xStart;
  }
  yEnd = g_MapBlocks.yEnd;
  y_low = (__m128)LODWORD(map_maxs.y);
  if ( (float)(g_MapBlocks.blockSize * g_MapBlocks.yEnd) > map_maxs.y )
  {
    y_low.m128_f32[0] = map_maxs.y / (float)g_MapBlocks.blockSize;
    v18 = _mm_and_ps((__m128)0x80000000, y_low);
    v19.m128_i32[0] = 1258291200;
    v19.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(y_low, v18), v19).m128_f32[0]) & 0x4B000000
                    | v18.m128_i32[0];
    v20 = y_low;
    v20.m128_f32[0] = (float)(y_low.m128_f32[0] + v19.m128_f32[0]) - v19.m128_f32[0];
    v21 = v20;
    v21.m128_f32[0] = v20.m128_f32[0] - y_low.m128_f32[0];
    yEnd = (int)(float)(v20.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v21, v18).m128_u32[0] & 0x3F800000));
    g_MapBlocks.yEnd = yEnd;
  }
  yStart = g_MapBlocks.yStart;
  v23 = (__m128)LODWORD(map_mins.y);
  v33 = a1;
  if ( map_mins.y > (float)(g_MapBlocks.blockSize * (g_MapBlocks.yStart + 1)) )
  {
    v23.m128_f32[0] = map_mins.y / (float)g_MapBlocks.blockSize;
    v24 = _mm_and_ps((__m128)0x80000000, v23);
    v25.m128_i32[0] = 1258291200;
    v25.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v23, v24), v25).m128_f32[0]) & 0x4B000000
                    | v24.m128_i32[0];
    v26 = v23;
    v26.m128_f32[0] = (float)(v23.m128_f32[0] + v25.m128_f32[0]) - v25.m128_f32[0];
    v27 = v26;
    v27.m128_f32[0] = v26.m128_f32[0] - v23.m128_f32[0];
    yStart = (int)(float)(v26.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v27, v24).m128_u32[0] & 0x3F800000));
    g_MapBlocks.yStart = yStart;
  }
  if ( xStart < g_MapBlocks.blockMin )
    g_MapBlocks.xStart = g_MapBlocks.blockMin;
  if ( yStart < g_MapBlocks.blockMin )
    g_MapBlocks.yStart = g_MapBlocks.blockMin;
  if ( xEnd > g_MapBlocks.blockMax )
    g_MapBlocks.xEnd = g_MapBlocks.blockMax;
  if ( yEnd > g_MapBlocks.blockMax )
    g_MapBlocks.yEnd = g_MapBlocks.blockMax;
  for ( start = 0; start <= 1; ++start )
  {
    qprintf(format: "--------------------------------------------\n");
    if ( verbose == 0 )
      printf(format: "%-20s ", "ProcessBlock_Thread:");
    RunThreadsOnIndividual(
      workcnt: (g_MapBlocks.xEnd - g_MapBlocks.xStart + 1) * (g_MapBlocks.yEnd - g_MapBlocks.yStart + 1),
      showpacifier: verbose == 0,
      func: ProcessBlock_Thread);
    qprintf(format: "--------------------------------------------\n");
    v28 = AllocTree();
    v28->headnode = BlockTree(
                      xl: g_MapBlocks.xStart - 1,
                      yl: g_MapBlocks.yStart - 1,
                      xh: g_MapBlocks.xEnd + 1,
                      yh: g_MapBlocks.yEnd + 1);
    v28->mins.x = (float)(g_MapBlocks.blockSize * g_MapBlocks.xStart);
    v28->mins.y = (float)(g_MapBlocks.blockSize * g_MapBlocks.yStart);
    v28->mins.z = map_mins.z - 8.0;
    v28->maxs.x = (float)(g_MapBlocks.blockSize * (g_MapBlocks.xEnd + 1));
    v28->maxs.y = (float)(g_MapBlocks.blockSize * (g_MapBlocks.yEnd + 1));
    v28->maxs.z = map_maxs.z + 8.0;
    MakeTreePortals(tree: v28);
    if ( FloodEntities(tree: v28) )
    {
      FillOutside(headnode: v28->headnode);
    }
    else
    {
      _Warning(a1: "**** leaked ****\n", v33, v34);
      leaked = 1;
      LeakFile(tree: v28);
      if ( leaktest != 0 )
      {
        _Warning(a1: "--- MAP LEAKED ---\n");
        exit(code: 0);
      }
    }
    MarkVisibleSides(tree: v28, startbrush: brush_start, endbrush: brush_end, detailScreen: 2);
    if ( noopt != 0 || leaked != 0 )
      break;
    if ( start == 0 )
      FreeTree(tree: v28);
  }
  FloodAreas(tree: v28);
  RemoveAreaPortalBrushes_R(node: v28->headnode);
  startb = (int)_Plat_FloatTime();
  _Msg(a1: "Building Faces...");
  MakeFaces(node: v28->headnode);
  v29 = _Plat_FloatTime() - (double)startb;
  _Msg(a1: "done (%d)\n", (int)v29);
  if ( glview != 0 )
    WriteGLView(tree: v28, source: source);
  AssignOccluderAreas(pTree: v28);
  Compute3DSkyboxAreas(areas: (CUtlMemory<S3RGBA,int> *)&g_SkyAreas, headnode: v28->headnode);
  v30 = nullptr;
  if ( nodetail == 0 )
    v30 = MergeDetailTree(worldtree: v28, brush_start: brush_start, brush_end: brush_end);
  starta = (int)_Plat_FloatTime();
  _Msg(a1: "FixTjuncs...\n");
  fixed = FixTjuncs(headnode: v28->headnode, pLeafFaceList: v30);
  if ( noprune == 0 )
  {
    _Msg(a1: "PruneNodes...\n");
    PruneNodes(node: v28->headnode);
  }
  _Msg(a1: "WriteBSP...\n");
  WriteBSP(headnode: v28->headnode, pLeafFaceList: fixed);
  v32 = _Plat_FloatTime() - (double)starta;
  _Msg(a1: "done (%d)\n", (int)v32);
  if ( leaked == 0 )
    WritePortalFile(tree: v28);
  FreeTree(tree: v28);
  FreeLeafFaces(pLeafFaceList: fixed);
}

//------------------------------------------------------------------------------
// Address: 0x00434B90
// Name: EmitOccluderBrushes
// Source: json
//------------------------------------------------------------------------------
tree_t *EmitOccluderBrushes()
{
  tree_t *result; // eax
  tree_t *v1; // ebx
  void *(__thiscall *Alloc_2)(IMemAlloc *, unsigned int); // eax
  side_t **v3; // esi
  int v4; // eax
  int m_Size; // eax
  int v6; // esi
  doccluderdata_t *m_pMemory; // ebx
  int v8; // eax
  doccluderdata_t *v9; // ebx
  int v10; // eax
  int v11; // esi
  OccluderInfo_t *v12; // ecx
  int v13; // eax
  int v14; // eax
  face_t *v15; // edi
  int flags; // eax
  int v17; // eax
  int v18; // eax
  int v19; // esi
  doccluderpolydata_t *v20; // ecx
  int v21; // eax
  doccluderpolydata_t *v22; // eax
  bool v23; // cc
  int *vertexnums; // ebx
  int v25; // eax
  int v26; // esi
  int *v27; // ecx
  int v28; // eax
  int *v29; // ecx
  const Vector *v30; // esi
  int v31; // eax
  node_t *headnode; // [esp-Ch] [ebp-8Ch]
  char str[64]; // [esp+8h] [ebp-78h] BYREF
  CUtlVector<side_t *,CUtlMemory<side_t *,int> > sideList; // [esp+48h] [ebp-38h] BYREF
  CUtlVector<face_t *,CUtlMemory<face_t *,int> > faceList; // [esp+5Ch] [ebp-24h] BYREF
  tree_t *pOccluderTree; // [esp+70h] [ebp-10h]
  int i; // [esp+74h] [ebp-Ch]
  int k; // [esp+78h] [ebp-8h]
  doccluderdata_t *occluderData; // [esp+7Ch] [ebp-4h]

  g_OccluderData.m_Size = 0;
  g_OccluderPolyData.m_Size = 0;
  g_OccluderVertexIndices.m_Size = 0;
  result = ClipOccluderBrushes();
  v1 = result;
  pOccluderTree = result;
  if ( result != nullptr )
  {
    faceList.m_Memory.m_pMemory = nullptr;
    faceList.m_Memory.m_nAllocationCount = 1024;
    faceList.m_Memory.m_nGrowSize = 1024;
    faceList.m_Memory.m_pMemory = (face_t **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4096);
    faceList.m_pElements = faceList.m_Memory.m_pMemory;
    faceList.m_Size = 0;
    Alloc_2 = _g_pMemAlloc->Alloc_2;
    sideList.m_Memory.m_nAllocationCount = 1024;
    sideList.m_Memory.m_nGrowSize = 1024;
    v3 = (side_t **)Alloc_2(this: _g_pMemAlloc, a2: 4096u);
    headnode = v1->headnode;
    sideList.m_Memory.m_pMemory = v3;
    sideList.m_Size = 0;
    sideList.m_pElements = v3;
    GenerateOccluderFaceList(pOccluderNode: headnode, occluderFaces: &faceList);
    v4 = 1;
    for ( entity_num = 1; v4 < num_entities; entity_num = v4 )
    {
      if ( strcmp("func_occluder", ValueForKey(ent: (entity_t *)&entities + v4, key: "classname")) == 0 )
      {
        m_Size = g_OccluderData.m_Size;
        v6 = g_OccluderData.m_Size;
        if ( g_OccluderData.m_Size + 1 > g_OccluderData.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<CQuadricError,int>::Grow(
            this: (CUtlMemory<CDmeCombinationOperator::DominatorInfo_t,int> *)&g_OccluderData,
            num: g_OccluderData.m_Size - g_OccluderData.m_Memory.m_nAllocationCount + 1);
          m_Size = g_OccluderData.m_Size;
        }
        m_pMemory = g_OccluderData.m_Memory.m_pMemory;
        g_OccluderData.m_Size = m_Size + 1;
        v8 = m_Size - v6;
        g_OccluderData.m_pElements = g_OccluderData.m_Memory.m_pMemory;
        if ( v8 > 0 )
        {
          _V_memmove(
            dest: &g_OccluderData.m_Memory.m_pMemory[v6 + 1],
            src: &g_OccluderData.m_Memory.m_pMemory[v6],
            count: 40 * v8);
          m_pMemory = g_OccluderData.m_Memory.m_pMemory;
        }
        v9 = &m_pMemory[v6];
        v9->firstpoly = g_OccluderPolyData.m_Size;
        v9->mins.x = 3.4028235e38;
        v9->mins.y = 3.4028235e38;
        v9->mins.z = 3.4028235e38;
        v9->maxs.x = -3.4028235e38;
        v9->maxs.y = -3.4028235e38;
        v9->maxs.z = -3.4028235e38;
        occluderData = v9;
        v9->flags = 0;
        v9->area = -1;
        sprintf(string: str, format: "%i", v6);
        SetKeyValue(ent: (entity_t *)&entities + entity_num, key: "occludernumber", value: str, bAllowDuplicates: false);
        v10 = g_OccluderInfo.m_Size;
        v11 = g_OccluderInfo.m_Size;
        if ( g_OccluderInfo.m_Size + 1 > g_OccluderInfo.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<HemiLightData_t *,int>::Grow(
            this: (CUtlMemory<S3RGBA,int> *)&g_OccluderInfo,
            num: g_OccluderInfo.m_Size - g_OccluderInfo.m_Memory.m_nAllocationCount + 1);
          v10 = g_OccluderInfo.m_Size;
        }
        v12 = g_OccluderInfo.m_Memory.m_pMemory;
        g_OccluderInfo.m_Size = v10 + 1;
        v13 = v10 - v11;
        g_OccluderInfo.m_pElements = g_OccluderInfo.m_Memory.m_pMemory;
        if ( v13 > 0 )
        {
          _V_memmove(
            dest: &g_OccluderInfo.m_Memory.m_pMemory[v11 + 1],
            src: &g_OccluderInfo.m_Memory.m_pMemory[v11],
            count: 4 * v13);
          v12 = g_OccluderInfo.m_Memory.m_pMemory;
        }
        v12[v11].m_nOccluderEntityIndex = entity_num;
        sideList.m_Size = 0;
        GenerateOccluderSideList(nEntity: entity_num, occluderSides: (CUtlMemory<S3RGBA,int> *)&sideList);
        v14 = faceList.m_Size - 1;
        for ( i = faceList.m_Size - 1; i >= 0; --i )
        {
          v15 = faceList.m_Memory.m_pMemory[v14];
          flags = texinfo.m_Memory.m_pMemory[v15->texinfo].flags;
          if ( (flags & 0x80u) == 0 || (flags & 0x40) != 0 )
          {
            v17 = sideList.m_Size;
            while ( --v17 >= 0 )
            {
              if ( sideList.m_Memory.m_pMemory[v17] == v15->originalface && v15->numpoints >= 3 )
              {
                v18 = g_OccluderPolyData.m_Size;
                v19 = g_OccluderPolyData.m_Size;
                if ( g_OccluderPolyData.m_Size + 1 > g_OccluderPolyData.m_Memory.m_nAllocationCount )
                {
                  CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>::Grow(
                    this: (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)&g_OccluderPolyData,
                    num: g_OccluderPolyData.m_Size - g_OccluderPolyData.m_Memory.m_nAllocationCount + 1);
                  v18 = g_OccluderPolyData.m_Size;
                }
                v20 = g_OccluderPolyData.m_Memory.m_pMemory;
                g_OccluderPolyData.m_Size = v18 + 1;
                v21 = v18 - v19;
                g_OccluderPolyData.m_pElements = g_OccluderPolyData.m_Memory.m_pMemory;
                if ( v21 > 0 )
                {
                  _V_memmove(
                    dest: &g_OccluderPolyData.m_Memory.m_pMemory[v19 + 1],
                    src: &g_OccluderPolyData.m_Memory.m_pMemory[v19],
                    count: 12 * v21);
                  v20 = g_OccluderPolyData.m_Memory.m_pMemory;
                }
                v22 = &v20[v19];
                v22->planenum = v15->planenum;
                v22->vertexcount = v15->numpoints;
                v22->firstvertexindex = g_OccluderVertexIndices.m_Size;
                v23 = v15->numpoints <= 0;
                k = 0;
                if ( !v23 )
                {
                  vertexnums = v15->vertexnums;
                  do
                  {
                    v25 = g_OccluderVertexIndices.m_Size;
                    v26 = g_OccluderVertexIndices.m_Size;
                    if ( g_OccluderVertexIndices.m_Size + 1 > g_OccluderVertexIndices.m_Memory.m_nAllocationCount )
                    {
                      CUtlMemory<HemiLightData_t *,int>::Grow(
                        this: (CUtlMemory<S3RGBA,int> *)&g_OccluderVertexIndices,
                        num: g_OccluderVertexIndices.m_Size - g_OccluderVertexIndices.m_Memory.m_nAllocationCount + 1);
                      v25 = g_OccluderVertexIndices.m_Size;
                    }
                    v27 = g_OccluderVertexIndices.m_Memory.m_pMemory;
                    g_OccluderVertexIndices.m_Size = v25 + 1;
                    v28 = v25 - v26;
                    g_OccluderVertexIndices.m_pElements = g_OccluderVertexIndices.m_Memory.m_pMemory;
                    if ( v28 > 0 )
                    {
                      _V_memmove(
                        dest: &g_OccluderVertexIndices.m_Memory.m_pMemory[v26 + 1],
                        src: &g_OccluderVertexIndices.m_Memory.m_pMemory[v26],
                        count: 4 * v28);
                      v27 = g_OccluderVertexIndices.m_Memory.m_pMemory;
                    }
                    v29 = &v27[v26];
                    if ( v29 != nullptr )
                      *v29 = *vertexnums;
                    v30 = &dvertexes + *vertexnums;
                    VectorMin(a: &occluderData->mins, b: v30, result: &occluderData->mins);
                    VectorMax(a: &occluderData->maxs, b: v30, result: &occluderData->maxs);
                    ++vertexnums;
                    ++k;
                  }
                  while ( k < v15->numpoints );
                  v9 = occluderData;
                }
                break;
              }
            }
          }
          v14 = i - 1;
        }
        v3 = sideList.m_Memory.m_pMemory;
        v9->polycount = g_OccluderPolyData.m_Size - v9->firstpoly;
        v31 = entity_num;
        v1 = pOccluderTree;
        *((_DWORD *)&unk_5CD4960 + 11 * entity_num) = 0;
      }
      else
      {
        v31 = entity_num;
      }
      v4 = v31 + 1;
    }
    FreeTree(tree: v1);
    if ( sideList.m_Memory.m_nGrowSize >= 0 && v3 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3);
    result = (tree_t *)faceList.m_Memory.m_pMemory;
    faceList.m_Size = 0;
    if ( faceList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( faceList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: faceList.m_Memory.m_pMemory);
        result = nullptr;
        faceList.m_Memory.m_pMemory = nullptr;
      }
      faceList.m_Memory.m_nAllocationCount = 0;
    }
    faceList.m_pElements = (face_t **)result;
    if ( faceList.m_Memory.m_nGrowSize >= 0 && result != nullptr )
      return (tree_t *)((int (__thiscall *)(IMemAlloc *, tree_t *))_g_pMemAlloc->Free_2)(a1: _g_pMemAlloc, a2: result);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00435010
// Name: void ProcessModels(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall ProcessModels(int a1@<ebx>, int a2@<ebp>, int a3@<edi>)
{
  int v3; // eax
  CMapDataFilesMgr *MapDataFilesMgr; // eax

  BeginBSPFile();
  MarkNoDynamicShadowSides();
  EmitInitialDispInfos(a1: a2);
  EmitOccluderBrushes();
  v3 = 0;
  for ( entity_num = 0; v3 < num_entities; entity_num = v3 )
  {
    if ( *((_DWORD *)&unk_5CD4960 + 11 * v3) != 0 )
    {
      qprintf(format: "############### model %i ###############\n", nummodels);
      BeginModel();
      if ( entity_num != 0 )
        ProcessSubModel();
      else
        ProcessWorldModel(a1, a2: a3);
      EndModel();
      if ( verboseentities == 0 )
        verbose = 0;
    }
    v3 = entity_num + 1;
  }
  MapDataFilesMgr = GetMapDataFilesMgr();
  MapDataFilesMgr->AddAllRegisteredFilesToPak(this: MapDataFilesMgr);
  EndBSPFile();
}

//------------------------------------------------------------------------------
// Address: 0x004350B0
// Name: int RunVBSP(int,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __usercall RunVBSP@<eax>(const char *a1@<edi>, int argc, char **argv)
{
  void (__thiscall ***v3)(_DWORD, int, char **); // eax
  const char *v4; // eax
  void (*v5)(const char *, ...); // ebx
  int v6; // esi
  int v7; // eax
  long double v8; // st7
  long double v9; // st7
  int v10; // ebx
  int i; // edi
  void *(__cdecl *FileSystemFactory)(const char *, int *); // edi
  char *v13; // eax
  char *v14; // edx
  char v15; // cl
  IZip *PakFile; // eax
  IZip *v17; // eax
  char path[1024]; // [esp+34h] [ebp-C10h] BYREF
  char str[512]; // [esp+434h] [ebp-810h] BYREF
  char logFile[512]; // [esp+634h] [ebp-610h] BYREF
  char platformBSPFileName[1024]; // [esp+834h] [ebp-410h] BYREF
  double start; // [esp+C34h] [ebp-10h]
  double end; // [esp+C3Ch] [ebp-8h]
  int savedregs; // [esp+C44h] [ebp+0h] BYREF

  v3 = (void (__thiscall ***)(_DWORD, int, char **))_CommandLine();
  (**v3)(a1: v3, a2: argc, a3: argv);
  MathLib_Init(
    gamma: 2.2,
    texGamma: 2.2,
    brightness: 0.0,
    overbright: 2,
    bAllow3DNow: false,
    bAllowSSE: false,
    bAllowSSE2: false,
    bAllowMMX: false);
  InstallSpewFunction();
  _LoggingSystem_SetChannelSpewLevelByTag(a1: "Developer", a2: 0);
  CmdLib_InitFileSystem(pFilename: argv[argc - 1], maxMemoryUsage: 0);
  v4 = ExpandArg(path: argv[argc - 1]);
  V_StripExtension(in: v4, out: source, outSize: 1024);
  V_FileBase(in: source, out: mapbase, maxlen: 64);
  strlwr(string: mapbase);
  LoadCmdLineFromFile(&argc, &argv, keyname: mapbase, appname: "vbsp");
  v5 = (void (*)(const char *, ...))_Msg;
  _Msg(a1: "Valve Software - vbsp.exe (%s)\n", "Apr  8 2011");
  v6 = 1;
  if ( argc <= 1 )
    goto LABEL_100;
  HIDWORD(end) = 16;
  while ( _V_stricmp(s1: argv[v6], s2: "-threads") == 0 )
  {
    v7 = atoi(nptr: argv[++v6]);
    HIDWORD(end) += 4;
    numthreads = v7;
LABEL_96:
    HIDWORD(end) += 4;
    if ( ++v6 >= argc )
      goto LABEL_100;
  }
  if ( _V_stricmp(s1: argv[v6], s2: "-glview") == 0 )
  {
    glview = 1;
    goto LABEL_96;
  }
  if ( _V_stricmp(s1: argv[v6], s2: "-v") == 0 || _V_stricmp(s1: argv[v6], s2: "-verbose") == 0 )
  {
    _Msg(a1: "verbose = true\n");
    verbose = 1;
    goto LABEL_96;
  }
  if ( _V_stricmp(s1: argv[v6], s2: "-noweld") == 0 )
  {
    _Msg(a1: "noweld = true\n");
    noweld = 1;
    goto LABEL_96;
  }
  if ( _V_stricmp(s1: argv[v6], s2: "-nocsg") == 0 )
  {
    _Msg(a1: "nocsg = true\n");
    nocsg = 1;
    goto LABEL_96;
  }
  if ( _V_stricmp(s1: argv[v6], s2: "-noshare") == 0 )
  {
    _Msg(a1: "noshare = true\n");
    noshare = 1;
    goto LABEL_96;
  }
  if ( _V_stricmp(s1: argv[v6], s2: "-notjunc") == 0 )
  {
    _Msg(a1: "notjunc = true\n");
    notjunc = 1;
    goto LABEL_96;
  }
  if ( _V_stricmp(s1: argv[v6], s2: "-nowater") == 0 )
  {
    _Msg(a1: "nowater = true\n");
    nowater = 1;
    goto LABEL_96;
  }
  if ( _V_stricmp(s1: argv[v6], s2: "-noopt") == 0 )
  {
    _Msg(a1: "noopt = true\n");
    noopt = 1;
    goto LABEL_96;
  }
  if ( _V_stricmp(s1: argv[v6], s2: "-noprune") == 0 )
  {
    _Msg(a1: "noprune = true\n");
    noprune = 1;
    goto LABEL_96;
  }
  if ( _V_stricmp(s1: argv[v6], s2: "-nomerge") == 0 )
  {
    _Msg(a1: "nomerge = true\n");
    nomerge = 1;
    goto LABEL_96;
  }
  if ( _V_stricmp(s1: argv[v6], s2: "-nomergewater") == 0 )
  {
    _Msg(a1: "nomergewater = true\n");
    nomergewater = 1;
    goto LABEL_96;
  }
  if ( _V_stricmp(s1: argv[v6], s2: "-nosubdiv") == 0 )
  {
    _Msg(a1: "nosubdiv = true\n");
    nosubdiv = 1;
    goto LABEL_96;
  }
  if ( _V_stricmp(s1: argv[v6], s2: "-nodetail") == 0 )
  {
    _Msg(a1: "nodetail = true\n");
    nodetail = 1;
    goto LABEL_96;
  }
  if ( _V_stricmp(s1: argv[v6], s2: "-fulldetail") == 0 )
  {
    _Msg(a1: "fulldetail = true\n");
    fulldetail = 1;
    goto LABEL_96;
  }
  if ( _V_stricmp(s1: argv[v6], s2: "-onlyents") == 0 )
  {
    _Msg(a1: "onlyents = true\n");
    onlyents = 1;
    goto LABEL_96;
  }
  if ( _V_stricmp(s1: argv[v6], s2: "-micro") == 0 )
  {
    v8 = atof(nptr: argv[v6 + 1]);
    microvolume = v8;
    _Msg(a1: "microvolume = %f\n", (double)v8);
    ++v6;
    HIDWORD(end) += 4;
    goto LABEL_96;
  }
  if ( _V_stricmp(s1: argv[v6], s2: "-leaktest") == 0 )
  {
    _Msg(a1: "leaktest = true\n");
    leaktest = 1;
    goto LABEL_96;
  }
  if ( _V_stricmp(s1: argv[v6], s2: "-verboseentities") == 0 )
  {
    _Msg(a1: "verboseentities = true\n");
    verboseentities = 1;
    goto LABEL_96;
  }
  if ( _V_stricmp(s1: argv[v6], s2: "-snapaxial") == 0 )
  {
    _Msg(a1: "snap axial = true\n");
    g_snapAxialPlanes = true;
    goto LABEL_96;
  }
  if ( _V_stricmp(s1: argv[v6], s2: "-gridsize") == 0 )
  {
    g_GridSize = atoi(nptr: argv[v6 + 1]);
    blockparams_t::SetBlockSize(this: &g_MapBlocks, blockSizeIn: g_GridSize);
    ++v6;
    HIDWORD(end) += 4;
    goto LABEL_96;
  }
  if ( _V_stricmp(s1: argv[v6], s2: "-block") == 0 )
  {
    g_MapBlocks.xEnd = atoi(nptr: argv[v6 + 1]);
    g_MapBlocks.xStart = g_MapBlocks.xEnd;
    g_MapBlocks.yEnd = atoi(nptr: argv[v6 + 2]);
    g_MapBlocks.yStart = g_MapBlocks.yEnd;
    _Msg(a1: "block: %i,%i\n", g_MapBlocks.xStart, g_MapBlocks.yEnd);
    v6 += 2;
    HIDWORD(end) += 8;
    goto LABEL_96;
  }
  if ( _V_stricmp(s1: argv[v6], s2: "-blocks") == 0 )
  {
    g_MapBlocks.xStart = atoi(nptr: argv[v6 + 1]);
    g_MapBlocks.yStart = atoi(nptr: argv[v6 + 2]);
    g_MapBlocks.xEnd = atoi(nptr: *(char **)((char *)argv + HIDWORD(end)));
    g_MapBlocks.yEnd = atoi(nptr: argv[v6 + 4]);
    _Msg(a1: "blocks: %i,%i to %i,%i\n", g_MapBlocks.xStart, g_MapBlocks.yStart, g_MapBlocks.xEnd, g_MapBlocks.yEnd);
    v6 += 4;
    a1 = (const char *)(HIDWORD(end) + 16);
    HIDWORD(end) += 16;
    goto LABEL_96;
  }
  if ( _V_stricmp(s1: argv[v6], s2: "-dumpcollide") == 0 )
  {
    _Msg(a1: "Dumping collision models to collideXXX.txt\n");
    dumpcollide = 1;
    goto LABEL_96;
  }
  if ( _V_stricmp(s1: argv[v6], s2: "-dumpstaticprop") == 0 )
  {
    _Msg(a1: "Dumping static props to staticpropXXX.txt\n");
    g_DumpStaticProps = 1;
    goto LABEL_96;
  }
  if ( _V_stricmp(s1: argv[v6], s2: "-forceskyvis") == 0 )
  {
    _Msg(a1: "Enabled vis in 3d skybox\n");
    g_bSkyVis = 1;
    goto LABEL_96;
  }
  if ( _V_stricmp(s1: argv[v6], s2: "-tmpout") == 0 )
  {
    strcpy(outbase, "/tmp");
    goto LABEL_96;
  }
  if ( _V_stricmp(s1: argv[v6], s2: "-luxelscale") == 0 )
  {
    g_luxelScale = atof(nptr: argv[++v6]);
    HIDWORD(end) += 4;
    goto LABEL_96;
  }
  a1 = argv[v6];
  if ( strcmp(a1, "-minluxelscale") == 0 )
  {
    v9 = atof(nptr: argv[v6 + 1]);
    g_minLuxelScale = v9;
    if ( v9 < 1.0 )
      g_minLuxelScale = 1.0;
    ++v6;
    HIDWORD(end) += 4;
    goto LABEL_96;
  }
  if ( _V_stricmp(s1: a1, s2: "-dxlevel") == 0 )
  {
    g_nDXLevel = atoi(nptr: argv[v6 + 1]);
    _Msg(a1: "DXLevel = %d\n", g_nDXLevel);
    ++v6;
    HIDWORD(end) += 4;
    goto LABEL_96;
  }
  if ( _V_stricmp(s1: argv[v6], s2: "-bumpall") == 0 )
  {
    g_BumpAll = true;
    goto LABEL_96;
  }
  if ( _V_stricmp(s1: argv[v6], s2: "-low") == 0 )
  {
    g_bLowPriority = 1;
    goto LABEL_96;
  }
  if ( _V_stricmp(s1: argv[v6], s2: "-lightifmissing") == 0 )
  {
    g_bLightIfMissing = true;
    goto LABEL_96;
  }
  if ( _V_stricmp(s1: argv[v6], s2: "-NoVConfig") == 0
    || _V_stricmp(s1: argv[v6], s2: "-allowdebug") == 0
    || _V_stricmp(s1: argv[v6], s2: "-steam") == 0 )
  {
    goto LABEL_96;
  }
  if ( _V_stricmp(s1: argv[v6], s2: "-vproject") == 0 || _V_stricmp(s1: argv[v6], s2: "-game") == 0 )
    goto LABEL_94;
  if ( _V_stricmp(s1: argv[v6], s2: "-keepstalezip") == 0 )
  {
    g_bKeepStaleZip = true;
    goto LABEL_96;
  }
  if ( _V_stricmp(s1: argv[v6], s2: "-xbox") == 0 )
  {
    g_NodrawTriggers = true;
    g_DisableWaterLighting = true;
    goto LABEL_96;
  }
  if ( _V_stricmp(s1: argv[v6], s2: "-allowdetailcracks") == 0 )
  {
    g_bAllowDetailCracks = true;
    goto LABEL_96;
  }
  if ( _V_stricmp(s1: argv[v6], s2: "-novirtualmesh") == 0 )
  {
    g_bNoVirtualMesh = true;
    goto LABEL_96;
  }
  if ( _V_stricmp(s1: argv[v6], s2: "-replacematerials") == 0 )
  {
    g_ReplaceMaterials = true;
    goto LABEL_96;
  }
  if ( _V_stricmp(s1: argv[v6], s2: "-nodrawtriggers") == 0 )
  {
    g_NodrawTriggers = true;
    goto LABEL_96;
  }
  if ( _V_stricmp(s1: argv[v6], s2: "-FullMinidumps") == 0 )
  {
    EnableFullMinidumps(bFull: true);
    goto LABEL_96;
  }
  if ( _V_stricmp(s1: argv[v6], s2: "-noprops") == 0 )
    goto LABEL_96;
  if ( _V_stricmp(s1: argv[v6], s2: "-outfile") == 0 )
  {
    ++v6;
    HIDWORD(end) += 4;
    goto LABEL_96;
  }
  if ( _V_stricmp(s1: argv[v6], s2: "-bouncescale") == 0 )
  {
LABEL_94:
    ++v6;
    HIDWORD(end) += 4;
    goto LABEL_96;
  }
  if ( *argv[v6] == 45 )
  {
    _Warning(a1: "VBSP: Unknown option \"%s\"\n\n", argv[v6]);
    v6 = 100000;
  }
LABEL_100:
  if ( v6 != argc - 1 )
  {
    HIDWORD(end) = argv;
    v10 = argc;
    _Warning(a1: "Command line: ");
    for ( i = 0; i < v10; ++i )
      _Warning(a1: "\"%s\" ", *(const char **)(HIDWORD(end) + 4 * i));
    a1 = (const char *)_Warning;
    _Warning(a1: "\n\n");
    _Warning(
      a1: "usage  : vbsp [options...] mapfile\n"
      "example: vbsp -onlyents c:\\hl2\\hl2\\maps\\test\n"
      "\n"
      "Common options (use -v to see all options):\n"
      "\n"
      "  -v (or -verbose): Turn on verbose output (also shows more command\n"
      "                    line options).\n"
      "\n"
      "  -onlyents   : This option causes vbsp only import the entities from the .vmf\n"
      "                file. -onlyents won't reimport brush models.\n"
      "  -glview     : Writes .gl files in the current directory that can be viewed\n"
      "                with glview.exe. If you use -tmpout, it will write the files\n"
      "                into the \\tmp folder.\n"
      "  -nodetail   : Get rid of all detail geometry. The geometry left over is\n"
      "                what affects visibility.\n"
      "  -nowater    : Get rid of water brushes.\n"
      "  -low        : Run as an idle-priority process.\n"
      "\n"
      "  -vproject <directory> : Override the VPROJECT environment variable.\n"
      "  -game <directory>     : Same as -vproject.\n"
      "\n");
    if ( verbose != 0 )
      _Warning(
        a1: "Other options  :\n"
        "  -novconfig   : Don't bring up graphical UI on vproject errors.\n"
        "  -threads     : Control the number of threads vbsp uses (defaults to the # of\n"
        "                 processors on your machine).\n"
        "  -verboseentities: If -v is on, this disables verbose output for submodels.\n"
        "  -noweld      : Don't join face vertices together.\n"
        "  -nocsg       : Don't chop out intersecting brush areas.\n"
        "  -noshare     : Emit unique face edges instead of sharing them.\n"
        "  -notjunc     : Don't fixup t-junctions.\n"
        "  -noopt       : By default, vbsp removes the 'outer shell' of the map, which\n"
        "                 are all the faces you can't see because you can never get\n"
        "                 outside the map. -noopt disables this behaviour.\n"
        "  -noprune     : Don't prune neighboring solid nodes.\n"
        "  -nomerge     : Don't merge together chopped faces on nodes.\n"
        "  -nomergewater: Don't merge together chopped faces on water.\n"
        "  -nosubdiv    : Don't subdivide faces for lightmapping.\n"
        "  -micro <#>   : vbsp will warn when brushes are output with a volume less\n"
        "                 than this number (default: 1.0).\n"
        "  -fulldetail  : Mark all detail geometry as normal geometry (so all detail\n"
        "                 geometry will affect visibility).\n"
        "  -leaktest    : Stop processing the map if a leak is detected. Whether or not\n"
        "                 this flag is set, a leak file will be written out at\n"
        "                 <vmf filename>.lin, and it can be imported into Hammer.\n"
        "  -bumpall     : Force all surfaces to be bump mapped.\n"
        "  -snapaxial   : Snap axial planes to integer coordinates.\n"
        "  -block # #      : Control the grid size mins that vbsp chops the level on.\n"
        "  -blocks # # # # : Enter the mins and maxs for the grid size vbsp uses.\n"
        "  -dumpstaticprops: Dump static props to staticprop*.txt\n"
        "  -dumpcollide    : Write files with collision info.\n"
        "  -forceskyvis\t   : Enable vis calculations in 3d skybox leaves\n"
        "  -luxelscale #   : Scale all lightmaps by this amount (default: 1.0).\n"
        "  -minluxelscale #: No luxel scale will be lower than this amount (default: 1.0).\n"
        "  -lightifmissing : Force lightmaps to be generated for all surfaces even if\n"
        "                    they don't need lightmaps.\n"
        "  -keepstalezip   : Keep the BSP's zip files intact but regenerate everything\n"
        "                    else.\n"
        "  -virtualdispphysics : Use virtual (not precomputed) displacement collision models\n"
        "  -xbox           : Enable mandatory xbox options\n"
        "  -x360\t\t   : Generate Xbox360 version of vsp\n"
        "  -nox360\t\t   : Disable generation Xbox360 version of vsp (default)\n"
        "  -replacematerials : Substitute materials according to materialsub.txt in content\\maps\n"
        "  -FullMinidumps  : Write large minidumps on crash.\n");
    DeleteCmdLine(argc, argv);
    CmdLib_Cleanup();
    _Plat_ExitProcess(a1: 1);
    v5 = (void (*)(const char *, ...))_Msg;
  }
  start = _Plat_FloatTime();
  if ( g_bLowPriority != 0 )
    SetLowPriority();
  if ( g_nDXLevel != 0 && g_nDXLevel < 80 )
    g_BumpAll = false;
  if ( g_luxelScale == 1.0 && g_nDXLevel == 70 )
    g_luxelScale = 4.0;
  ThreadSetDefault();
  numthreads = 1;
  _snprintf(string: logFile, count: 0x200u, format: "%s.log", source);
  CCmdLibFileLoggingListener::Open(this: &g_CmdLibFileLoggingListener, pFilename: logFile);
  PhysicsDLLPath(pPathname: "vphysics.dll");
  LoadSurfaceProperties(a1: (int)v5);
  sprintf(string: materialPath, format: "%smaterials", gamedir);
  CmdLib_GetFileSystemFactory();
  InitMaterialSystem((int)a1, a2: v6);
  v5(a1: "materialPath: %s\n", materialPath);
  FileSystemFactory = CmdLib_GetFileSystemFactory();
  if ( g_pDataModel->Connect(this: g_pDataModel, a2: FileSystemFactory) != 0
    && g_pDmElementFramework->Connect(this: g_pDmElementFramework, a2: FileSystemFactory) != 0
    && g_pDmSerializers->Connect(this: g_pDmSerializers, a2: FileSystemFactory) != 0
    && g_pDataModel->Init(this: g_pDataModel) == INIT_OK
    && g_pDmElementFramework->Init(this: g_pDmElementFramework) == INIT_OK )
  {
    g_pDmSerializers->Init(this: g_pDmSerializers);
  }
  sprintf(string: path, format: "%s.prt", source);
  remove(path);
  sprintf(string: path, format: "%s.lin", source);
  remove(path);
  v13 = ExpandArg(path: argv[v6]);
  v14 = (char *)(name - v13);
  do
  {
    v15 = *v13;
    v14[(_DWORD)v13] = *v13;
    ++v13;
  }
  while ( v15 != 0 );
  V_DefaultExtension(path: name, extension: ".vmf", pathStringLength: 1024);
  GetPlatformMapPath(pMapPath: source, pPlatformMapPath: platformBSPFileName, dxlevel: g_nDXLevel, maxLength: 1024);
  if ( g_ReplaceMaterials )
    LoadMaterialReplacementKeys(gamedir: gamedir, mapname: mapbase);
  if ( onlyents != 0 )
  {
    LoadBSPFile(filename: platformBSPFileName);
    num_entities = 0;
    PakFile = GetPakFile();
    AddBufferToPak(pak: PakFile, pRelativeName: "stale.txt", data: "stale", length: 6, bTextMode: false);
    LoadMapFile(pszFileName: name);
    SetModelNumbers();
    SetLightStyles();
    ComputeBoundsNoSkybox();
    EnsurePresenceOfWaterLODControlEntity();
    FixupOnlyEntsOccluderEntities();
    UnparseEntities();
    WriteBSPFile(filename: platformBSPFileName, pUnused: nullptr);
  }
  else
  {
    if ( g_bKeepStaleZip && FileExists(filename: platformBSPFileName) != 0 )
    {
      LoadBSPFile_FileSystemOnly(filename: platformBSPFileName);
      v17 = GetPakFile();
      AddBufferToPak(pak: v17, pRelativeName: "stale.txt", data: "stale", length: 6, bTextMode: false);
    }
    LoadMapFile(pszFileName: name);
    WorldVertexTransitionFixup();
    SetModelNumbers();
    SetLightStyles();
    LoadEmitDetailObjectDictionary();
    ProcessModels(a1: (int)v5, a2: (int)&savedregs, a3: (int)FileSystemFactory);
  }
  end = _Plat_FloatTime();
  GetHourMinuteSecondsString(nInputSeconds: (int)(end - start), pOut: str, outLen: 512);
  v5(a1: "%s elapsed\n", str);
  DeleteCmdLine(argc, argv);
  ReleasePakFileLumps();
  DeleteMaterialReplacementKeys();
  ShutdownMaterialSystem();
  CmdLib_Cleanup();
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00435EB0
// Name: _main
// Source: json
//------------------------------------------------------------------------------
int __cdecl main(int argc, const char **argv, const char **envp)
{
  const char *v3; // edi

  SetupDefaultToolsMinidumpHandler();
  return RunVBSP(a1: v3, argc, (char **)argv);
}
