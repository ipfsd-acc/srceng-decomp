// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vbsp/vbsp.cpp
// Functions: 19
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0042AD20
// Name: struct node_t __near * BlockTree(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
node_t *__cdecl BlockTree(int xl, int yl, int xh, int yh)
{
  node_t *result; // eax
  node_t *v5; // esi
  node_t *v6; // eax
  Vector normal; // [esp+10h] [ebp-Ch] BYREF

  if ( xl == xh && yl == yh )
  {
    result = *(&ppBlockNodes[0x8000 / g_nBlockSize / 2 + 1]
             + (0x8000 / g_nBlockSize + 2) * (0x8000 / g_nBlockSize / 2 + yl + 1)
             + xl);
    if ( result == nullptr )
    {
      result = AllocNode();
      result->planenum = -1;
      result->contents = 0;
    }
  }
  else
  {
    v5 = AllocNode();
    if ( xh - xl <= yh - yl )
    {
      normal.x = 0.0;
      normal.z = 0.0;
      normal.y = 1.0;
      v5->planenum = CMapFile::FindFloatPlane(
                       this: g_MainMap,
                       &normal,
                       dist: COERCE_UNSIGNED_INT((float)(((yh - yl) / 2 + yl + 1) * g_nBlockSize)));
      v5->children[0] = BlockTree(xl, yl: (yh - yl) / 2 + yl + 1, xh, yh);
      v6 = BlockTree(xl, yl, xh, yh: (yh - yl) / 2 + yl);
    }
    else
    {
      normal.x = 1.0;
      normal.y = 0.0;
      normal.z = 0.0;
      v5->planenum = CMapFile::FindFloatPlane(
                       this: g_MainMap,
                       &normal,
                       dist: COERCE_UNSIGNED_INT((float)(((xh - xl) / 2 + xl + 1) * g_nBlockSize)));
      v5->children[0] = BlockTree(xl: (xh - xl) / 2 + xl + 1, yl, xh, yh);
      v6 = BlockTree(xl, yl, xh: (xh - xl) / 2 + xl, yh);
    }
    v5->children[1] = v6;
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042AE90
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
  node_t *v8; // ecx
  Vector mins; // [esp+Ch] [ebp-18h] BYREF
  Vector maxs; // [esp+18h] [ebp-Ch] BYREF

  v2 = block_xh - block_xl + 1;
  v3 = blocknum % v2;
  v4 = blocknum / v2 + block_yl;
  v5 = v3 + block_xl;
  qprintf(format: "############### block %2i,%2i ###############\n", v3 + block_xl, v4);
  mins.x = (float)(v5 * g_nBlockSize);
  mins.y = (float)(v4 * g_nBlockSize);
  mins.z = -16384.0;
  maxs.x = (float)(g_nBlockSize * (v5 + 1));
  maxs.y = (float)(g_nBlockSize * (v4 + 1));
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
    *(&ppBlockNodes[0x8000 / g_nBlockSize / 2 + 1]
    + (0x8000 / g_nBlockSize + 2) * (0x8000 / g_nBlockSize / 2 + v4 + 1)
    + v5) = BrushBSP(brushlist: v7, &mins, &maxs)->headnode;
  }
  else
  {
    v8 = AllocNode();
    v8->planenum = -1;
    v8->contents = 1;
    *(&ppBlockNodes[0x8000 / g_nBlockSize / 2 + 1]
    + (0x8000 / g_nBlockSize + 2) * (0x8000 / g_nBlockSize / 2 + v4 + 1)
    + v5) = v8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042B000
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
// Address: 0x0042B110
// Name: bool IsFuncOccluder(int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsFuncOccluder(int entity_num)
{
  return strcmp("func_occluder", ValueForKey(ent: (entity_t *)&entities + entity_num, key: "classname")) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x0042B170
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
// Address: 0x0042B370
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
// Address: 0x0042B550
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
// Address: 0x0042B5A0
// Name: void MarkNoDynamicShadowSides(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MarkNoDynamicShadowSides()
{
  CMapFile *v0; // eax
  int v1; // ecx
  int v2; // edx
  int i; // edi
  int v4; // esi
  int v5; // edx
  int v6; // ecx

  v0 = g_MainMap;
  v1 = 0;
  if ( g_MainMap->nummapbrushsides > 0 )
  {
    v2 = 0;
    do
    {
      v0->brushsides[v2].m_bDynamicShadowsEnabled = true;
      v0 = g_MainMap;
      ++v1;
      ++v2;
    }
    while ( v1 < g_MainMap->nummapbrushsides );
  }
  for ( i = 0; i < g_NoDynamicShadowSides.m_Size; ++i )
  {
    v4 = g_NoDynamicShadowSides.m_Memory.m_pMemory[i];
    v5 = 0;
    if ( v0->nummapbrushsides > 0 )
    {
      v6 = 0;
      do
      {
        if ( v0->brushsides[v6].id == v4 )
        {
          v0->brushsides[v6].m_bDynamicShadowsEnabled = false;
          v0 = g_MainMap;
        }
        ++v5;
        ++v6;
      }
      while ( v5 < v0->nummapbrushsides );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042B630
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
// Address: 0x0042B660
// Name: void AddDefaultStringtableDictionaries(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddDefaultStringtableDictionaries()
{
  CZip *PakFile; // eax
  CZip *v1; // eax
  unsigned __int8 *m_pMemory; // [esp-Ch] [ebp-144h]
  unsigned __int8 *v3; // [esp-Ch] [ebp-144h]
  int m_Put; // [esp-8h] [ebp-140h]
  int v5; // [esp-8h] [ebp-140h]
  char reslistsPath[260]; // [esp+4h] [ebp-134h] BYREF
  CUtlBuffer buf; // [esp+108h] [ebp-30h] BYREF

  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
  V_snprintf(pDest: reslistsPath, maxLen: 260, pFormat: "%s%s/%s.dict", gamedir, "reslists", mapbase);
  if ( g_pFileSystem->ReadFile(this: g_pFileSystem, a2: reslistsPath, a3: nullptr, a4: &buf, a5: 0, a6: 0, a7: nullptr) )
  {
    m_Put = buf.m_Put;
    m_pMemory = buf.m_Memory.m_pMemory;
    PakFile = GetPakFile();
    AddBufferToPak(
      pak: PakFile,
      pRelativeName: "stringtable_dictionary_fallback.dct",
      data: m_pMemory,
      length: m_Put,
      bTextMode: false);
  }
  memset(&buf.m_Get, 0, 9);
  buf.m_nOffset = 0;
  buf.m_nMaxPut = -1;
  CUtlBuffer::AddNullTermination(this: &buf, nPut: 0);
  V_snprintf(pDest: reslistsPath, maxLen: 260, pFormat: "%s%s/%s.dict", gamedir, "reslists_xbox", mapbase);
  if ( g_pFileSystem->ReadFile(this: g_pFileSystem, a2: reslistsPath, a3: nullptr, a4: &buf, a5: 0, a6: 0, a7: nullptr) )
  {
    v5 = buf.m_Put;
    v3 = buf.m_Memory.m_pMemory;
    v1 = GetPakFile();
    AddBufferToPak(
      pak: v1,
      pRelativeName: "stringtable_dictionary_fallback_xbox.dct",
      data: v3,
      length: v5,
      bTextMode: false);
  }
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x0042B780
// Name: ClipOccluderBrushes
// Source: json
//------------------------------------------------------------------------------
tree_t *__cdecl ClipOccluderBrushes()
{
  mapbrush_t **v0; // esi
  int v1; // eax
  int m_Size; // edi
  bool v3; // zf
  int v4; // eax
  char *v5; // ecx
  int v6; // edx
  int v7; // ecx
  int v8; // ebx
  int v9; // esi
  mapbrush_t **m_pMemory; // ecx
  mapbrush_t **v11; // eax
  bspbrush_t *BspBrushList; // eax
  tree_t *v14; // esi
  mapbrush_t **v15; // edi
  int v16; // [esp-14h] [ebp-50h]
  CUtlVector<mapbrush_t *,CUtlMemory<mapbrush_t *,int> > mapBrushes; // [esp+8h] [ebp-34h] BYREF
  Vector mins; // [esp+1Ch] [ebp-20h] BYREF
  Vector maxs; // [esp+28h] [ebp-14h] BYREF
  mapbrush_t *v20; // [esp+34h] [ebp-8h]
  int v21; // [esp+38h] [ebp-4h]

  mapBrushes.m_Memory.m_nAllocationCount = 1024;
  mapBrushes.m_Memory.m_nGrowSize = 1024;
  v0 = (mapbrush_t **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4096);
  v1 = 0;
  m_Size = 0;
  entity_num = 0;
  mapBrushes.m_Memory.m_pMemory = v0;
  mapBrushes.m_Size = 0;
  mapBrushes.m_pElements = v0;
  if ( *(int *)((char *)&unk_12E1024 + (_DWORD)g_MainMap) <= 0 )
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
        v8 = v6;
        v21 = v7 - v6;
        do
        {
          v20 = &g_MainMap->mapbrushes[v8];
          v9 = m_Size;
          if ( m_Size + 1 > mapBrushes.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<CClassInput *,int>::Grow(
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
            *v11 = v20;
          ++v8;
          --v21;
        }
        while ( v21 != 0 );
        v4 = entity_num;
        v0 = mapBrushes.m_Memory.m_pMemory;
      }
    }
    v1 = v4 + 1;
    entity_num = v1;
  }
  while ( v1 < *(_DWORD *)((char *)&unk_12E1024 + (_DWORD)g_MainMap) );
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
    v16 = m_Size;
    v15 = mapBrushes.m_Memory.m_pMemory;
    MarkVisibleSides(tree: v14, ppBrushes: mapBrushes.m_Memory.m_pMemory, nCount: v16);
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
// Address: 0x0042B9B0
// Name: GenerateOccluderSideList
// Source: json
//------------------------------------------------------------------------------
void __usercall GenerateOccluderSideList(int nEntity@<eax>, CUtlMemory<S3RGBA,int> *occluderSides@<esi>)
{
  char *v2; // eax
  int v3; // ecx
  int v4; // eax
  int v5; // edx
  CMapFile *v6; // eax
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  side_t *v9; // ebx
  side_t **v10; // ecx
  int v11; // eax
  side_t **v12; // edi
  bool v13; // zf
  int *v14; // [esp+0h] [ebp-18h]
  _DWORD *v15; // [esp+4h] [ebp-14h]
  int v16; // [esp+8h] [ebp-10h]
  int v17; // [esp+Ch] [ebp-Ch]
  int j; // [esp+10h] [ebp-8h]
  int v19; // [esp+14h] [ebp-4h]

  v2 = (char *)&entities + 44 * nEntity;
  v3 = *((_DWORD *)v2 + 3);
  v4 = v3 + *((_DWORD *)v2 + 4);
  if ( v3 < v4 )
  {
    v5 = 48 * v3;
    v16 = v4 - v3;
    v6 = g_MainMap;
    v17 = 48 * v3;
    do
    {
      j = 0;
      v14 = (int *)((char *)&v6->mapbrushes[0].numsides + v5);
      if ( *v14 > 0 )
      {
        v15 = (side_t **)((char *)&v6->mapbrushes[0].original_sides + v5);
        v19 = 0;
        do
        {
          m_pMemory = (int)occluderSides[1].m_pMemory;
          m_nAllocationCount = occluderSides->m_nAllocationCount;
          v9 = (side_t *)(v19 + *v15);
          if ( m_pMemory + 1 > m_nAllocationCount )
            CUtlMemory<CClassInput *,int>::Grow(this: occluderSides, num: m_pMemory - m_nAllocationCount + 1);
          ++occluderSides[1].m_pMemory;
          v10 = (side_t **)occluderSides->m_pMemory;
          v11 = (int)occluderSides[1].m_pMemory - m_pMemory - 1;
          occluderSides[1].m_nAllocationCount = (int)occluderSides->m_pMemory;
          if ( v11 > 0 )
            _V_memmove(dest: &v10[m_pMemory + 1], src: &v10[m_pMemory], count: 4 * v11);
          v12 = (side_t **)&occluderSides->m_pMemory[m_pMemory];
          if ( v12 != nullptr )
            *v12 = v9;
          v19 += 92;
          ++j;
        }
        while ( j < *v14 );
        v6 = g_MainMap;
        v5 = v17;
      }
      v5 += 48;
      v13 = v16-- == 1;
      v17 = v5;
    }
    while ( !v13 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042BA90
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
            CUtlMemory<CClassInput *,int>::Grow(
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
// Address: 0x0042BB30
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
  if ( *(int *)((char *)&unk_12E1024 + (_DWORD)g_MainMap) > 0 )
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
          CUtlMemory<CClassInput *,int>::Grow(this: areas, num: m_pMemory - m_nAllocationCount + 1);
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
    while ( i < *(_DWORD *)((char *)&unk_12E1024 + (_DWORD)g_MainMap) );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042BC70
// Name: void ProcessWorldModel(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall ProcessWorldModel(int a1@<edi>, int a2@<esi>)
{
  char *v2; // eax
  int v3; // ecx
  int v4; // eax
  __m128 x_low; // xmm2
  __m128 v6; // xmm3
  __m128 v7; // xmm1
  __m128 v8; // xmm0
  __m128 v9; // xmm1
  __m128 v10; // xmm2
  int v11; // edi
  __m128 v12; // xmm3
  __m128 v13; // xmm1
  __m128 v14; // xmm0
  __m128 v15; // xmm1
  int v16; // ebx
  __m128 y_low; // xmm2
  __m128 v18; // xmm3
  __m128 v19; // xmm1
  __m128 v20; // xmm0
  __m128 v21; // xmm1
  __m128 v22; // xmm2
  int v23; // esi
  __m128 v24; // xmm3
  __m128 v25; // xmm1
  __m128 v26; // xmm0
  __m128 v27; // xmm1
  int v28; // eax
  int v29; // eax
  tree_t *v30; // esi
  double v31; // st7
  face_t *v32; // edi
  face_t *fixed; // edi
  double v34; // st7
  int v35; // [esp-Ch] [ebp-14h]
  int v36; // [esp-8h] [ebp-10h]
  int leaked; // [esp+0h] [ebp-8h]
  int start; // [esp+4h] [ebp-4h]
  int startb; // [esp+4h] [ebp-4h]
  int starta; // [esp+4h] [ebp-4h]

  v2 = (char *)&entities + 44 * entity_num;
  v3 = *((_DWORD *)v2 + 3);
  v4 = v3 + *((_DWORD *)v2 + 4);
  brush_start = v3;
  brush_end = v4;
  leaked = 0;
  if ( ppBlockNodes == nullptr )
  {
    ppBlockNodes = (node_t **)MemAlloc_Alloc(
                                nSize: (unsigned __int64)(unsigned int)((0x8000 / g_nBlockSize + 2)
                                                               * (0x8000 / g_nBlockSize + 2)) >> 30 != 0
                              ? -1
                              : 4 * (0x8000 / g_nBlockSize + 2) * (0x8000 / g_nBlockSize + 2));
    _V_memset(dest: ppBlockNodes, fill: 0, count: 4 * (0x8000 / g_nBlockSize + 2) * (0x8000 / g_nBlockSize + 2));
  }
  x_low = (__m128)LODWORD(g_MainMap->map_maxs.x);
  if ( (float)(g_nBlockSize * block_xh) > x_low.m128_f32[0] )
  {
    x_low.m128_f32[0] = x_low.m128_f32[0] / (float)g_nBlockSize;
    v6 = _mm_and_ps((__m128)0x80000000, x_low);
    v7.m128_i32[0] = 1258291200;
    v7.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(x_low, v6), v7).m128_f32[0]) & 0x4B000000
                   | v6.m128_i32[0];
    v8 = x_low;
    v8.m128_f32[0] = (float)(x_low.m128_f32[0] + v7.m128_f32[0]) - v7.m128_f32[0];
    v9 = v8;
    v9.m128_f32[0] = v8.m128_f32[0] - x_low.m128_f32[0];
    block_xh = (int)(float)(v8.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v9, v6).m128_u32[0] & 0x3F800000));
  }
  v10 = (__m128)LODWORD(g_MainMap->map_mins.x);
  v36 = a2;
  v35 = a1;
  v11 = block_xl;
  if ( v10.m128_f32[0] > (float)(g_nBlockSize * (block_xl + 1)) )
  {
    v10.m128_f32[0] = v10.m128_f32[0] / (float)g_nBlockSize;
    v12 = _mm_and_ps((__m128)0x80000000, v10);
    v13.m128_i32[0] = 1258291200;
    v13.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v10, v12), v13).m128_f32[0]) & 0x4B000000
                    | v12.m128_i32[0];
    v14 = v10;
    v14.m128_f32[0] = (float)(v10.m128_f32[0] + v13.m128_f32[0]) - v13.m128_f32[0];
    v15 = v14;
    v15.m128_f32[0] = v14.m128_f32[0] - v10.m128_f32[0];
    v11 = (int)(float)(v14.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v15, v12).m128_u32[0] & 0x3F800000));
    block_xl = v11;
  }
  v16 = block_yh;
  y_low = (__m128)LODWORD(g_MainMap->map_maxs.y);
  if ( (float)(g_nBlockSize * block_yh) > y_low.m128_f32[0] )
  {
    y_low.m128_f32[0] = y_low.m128_f32[0] / (float)g_nBlockSize;
    v18 = _mm_and_ps((__m128)0x80000000, y_low);
    v19.m128_i32[0] = 1258291200;
    v19.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(y_low, v18), v19).m128_f32[0]) & 0x4B000000
                    | v18.m128_i32[0];
    v20 = y_low;
    v20.m128_f32[0] = (float)(y_low.m128_f32[0] + v19.m128_f32[0]) - v19.m128_f32[0];
    v21 = v20;
    v21.m128_f32[0] = v20.m128_f32[0] - y_low.m128_f32[0];
    v16 = (int)(float)(v20.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v21, v18).m128_u32[0] & 0x3F800000));
    block_yh = v16;
  }
  v22 = (__m128)LODWORD(g_MainMap->map_mins.y);
  v23 = block_yl;
  if ( v22.m128_f32[0] > (float)(g_nBlockSize * (block_yl + 1)) )
  {
    v22.m128_f32[0] = v22.m128_f32[0] / (float)g_nBlockSize;
    v24 = _mm_and_ps((__m128)0x80000000, v22);
    v25.m128_i32[0] = 1258291200;
    v25.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v22, v24), v25).m128_f32[0]) & 0x4B000000
                    | v24.m128_i32[0];
    v26 = v22;
    v26.m128_f32[0] = (float)(v22.m128_f32[0] + v25.m128_f32[0]) - v25.m128_f32[0];
    v27 = v26;
    v27.m128_f32[0] = v26.m128_f32[0] - v22.m128_f32[0];
    v23 = (int)(float)(v26.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v27, v24).m128_u32[0] & 0x3F800000));
    block_yl = v23;
  }
  v28 = -32768 / g_nBlockSize / 2;
  if ( v11 < v28 )
    block_xl = -32768 / g_nBlockSize / 2;
  if ( v23 < v28 )
    block_yl = -32768 / g_nBlockSize / 2;
  v29 = 0x8000 / g_nBlockSize / 2 - 1;
  if ( block_xh > v29 )
    block_xh = 0x8000 / g_nBlockSize / 2 - 1;
  if ( v16 > v29 )
    block_yh = 0x8000 / g_nBlockSize / 2 - 1;
  for ( start = 0; start <= 1; ++start )
  {
    qprintf(format: "--------------------------------------------\n");
    if ( verbose == 0 )
      printf(format: "%-20s ", "ProcessBlock_Thread:");
    RunThreadsOnIndividual(
      workcnt: (block_xh - block_xl + 1) * (block_yh - block_yl + 1),
      showpacifier: verbose == 0,
      func: ProcessBlock_Thread);
    qprintf(format: "--------------------------------------------\n");
    v30 = AllocTree();
    v30->headnode = BlockTree(xl: block_xl - 1, yl: block_yl - 1, xh: block_xh + 1, yh: block_yh + 1);
    v30->mins.x = (float)(g_nBlockSize * block_xl);
    v30->mins.y = (float)(g_nBlockSize * block_yl);
    v30->mins.z = g_MainMap->map_mins.z - 8.0;
    v30->maxs.x = (float)(g_nBlockSize * (block_xh + 1));
    v30->maxs.y = (float)(g_nBlockSize * (block_yh + 1));
    v30->maxs.z = g_MainMap->map_maxs.z + 8.0;
    MakeTreePortals(tree: v30);
    if ( FloodEntities(tree: v30) )
    {
      FillOutside(headnode: v30->headnode);
    }
    else
    {
      _Warning(a1: "**** leaked ****\n", v35, v36);
      leaked = 1;
      LeakFile(tree: v30);
      if ( leaktest != 0 )
      {
        _Warning(a1: "--- MAP LEAKED ---\n");
        exit(code: 0);
      }
    }
    MarkVisibleSides(tree: v30, startbrush: brush_start, endbrush: brush_end, detailScreen: 2);
    if ( noopt != 0 || leaked != 0 )
      break;
    if ( start == 0 )
      FreeTree(tree: v30);
  }
  FloodAreas(tree: v30);
  RemoveAreaPortalBrushes_R(node: v30->headnode);
  startb = (int)_Plat_FloatTime();
  _Msg(a1: "Building Faces...");
  MakeFaces(node: v30->headnode);
  v31 = _Plat_FloatTime() - (double)startb;
  _Msg(a1: "done (%d)\n", (int)v31);
  if ( glview != 0 )
    WriteGLView(tree: v30, source: source);
  AssignOccluderAreas(pTree: v30);
  Compute3DSkyboxAreas(areas: (CUtlMemory<S3RGBA,int> *)&g_SkyAreas, headnode: v30->headnode);
  v32 = nullptr;
  if ( nodetail == 0 )
    v32 = MergeDetailTree(worldtree: v30, brush_start: brush_start, brush_end: brush_end);
  starta = (int)_Plat_FloatTime();
  _Msg(a1: "FixTjuncs...\n");
  fixed = FixTjuncs(headnode: v30->headnode, pLeafFaceList: v32);
  if ( noprune == 0 )
  {
    _Msg(a1: "PruneNodes...\n");
    PruneNodes(node: v30->headnode);
  }
  _Msg(a1: "WriteBSP...\n");
  WriteBSP(headnode: v30->headnode, pLeafFaceList: fixed);
  v34 = _Plat_FloatTime() - (double)starta;
  _Msg(a1: "done (%d)\n", (int)v34);
  if ( leaked == 0 )
    WritePortalFile(tree: v30);
  FreeTree(tree: v30);
  FreeLeafFaces(pLeafFaceList: fixed);
}

//------------------------------------------------------------------------------
// Address: 0x0042C220
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
          CUtlMemory<Cordon_t,int>::Grow(
            this: (CUtlMemory<Cordon_t,int> *)&g_OccluderData,
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
          CUtlMemory<CClassInput *,int>::Grow(
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
                  CUtlMemory<CVTFTexture::ResourceMemorySection,int>::Grow(
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
                      CUtlMemory<CClassInput *,int>::Grow(
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
        *((_DWORD *)&unk_7351A38 + 11 * entity_num) = 0;
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
// Address: 0x0042C6A0
// Name: void ProcessModels(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall ProcessModels(int a1@<ebp>, int a2@<edi>, int a3@<esi>)
{
  int v3; // eax
  CMapDataFilesMgr *MapDataFilesMgr; // eax

  BeginBSPFile();
  MarkNoDynamicShadowSides();
  EmitInitialDispInfos(a1);
  EmitOccluderBrushes();
  v3 = 0;
  for ( entity_num = 0; v3 < num_entities; entity_num = v3 )
  {
    if ( *((_DWORD *)&unk_7351A38 + 11 * v3) != 0 )
    {
      qprintf(format: "############### model %i ###############\n", nummodels);
      BeginModel();
      if ( entity_num != 0 )
        ProcessSubModel();
      else
        ProcessWorldModel(a1: a2, a2: a3);
      EndModel();
      if ( verboseentities == 0 )
        verbose = 0;
    }
    v3 = entity_num + 1;
  }
  MapDataFilesMgr = GetMapDataFilesMgr();
  MapDataFilesMgr->AddAllRegisteredFilesToPak(this: MapDataFilesMgr);
  Cubemap_CreateDefaultCubemaps();
  EndBSPFile();
}

//------------------------------------------------------------------------------
// Address: 0x0042C740
// Name: int RunVBSP(int,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl RunVBSP(int argc, char **argv)
{
  void (__thiscall ***v2)(_DWORD, int, char **); // eax
  const char *v3; // eax
  int v4; // esi
  int v5; // eax
  long double v6; // st7
  int v7; // eax
  long double v8; // st7
  int v9; // edi
  int v10; // esi
  char **v11; // ebx
  int j; // esi
  char *v13; // eax
  char *v14; // edx
  char v15; // cl
  CZip *PakFile; // eax
  CZip *v17; // eax
  char path[1024]; // [esp+34h] [ebp-C10h] BYREF
  char str[512]; // [esp+434h] [ebp-810h] BYREF
  char logFile[512]; // [esp+634h] [ebp-610h] BYREF
  char platformBSPFileName[1024]; // [esp+834h] [ebp-410h] BYREF
  double i; // [esp+C34h] [ebp-10h]
  double start; // [esp+C3Ch] [ebp-8h]
  int savedregs; // [esp+C44h] [ebp+0h] BYREF

  v2 = (void (__thiscall ***)(_DWORD, int, char **))_CommandLine();
  (**v2)(a1: v2, a2: argc, a3: argv);
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
  v3 = ExpandArg(path: argv[argc - 1]);
  V_StripExtension(in: v3, out: source, outSize: 1024);
  V_FileBase(in: source, out: mapbase, maxlen: 64);
  strlwr(string: mapbase);
  LoadCmdLineFromFile(&argc, &argv, keyname: mapbase, appname: "vbsp");
  _Msg(a1: "Valve Software - vbsp.exe (%s)\n", "Jul 15 2011");
  HIDWORD(i) = 1;
  if ( argc <= 1 )
    goto LABEL_96;
  HIDWORD(start) = 16;
  while ( 1 )
  {
    v4 = HIDWORD(i);
    if ( _V_stricmp(s1: argv[HIDWORD(i)], s2: "-threads") != 0 )
      break;
    v5 = atoi(nptr: argv[HIDWORD(i) + 1]);
    HIDWORD(start) += 4;
    numthreads = v5;
    ++HIDWORD(i);
LABEL_103:
    HIDWORD(start) += 4;
    ++HIDWORD(i);
    if ( SHIDWORD(i) >= argc )
      goto LABEL_96;
  }
  if ( _V_stricmp(s1: argv[HIDWORD(i)], s2: "-glview") == 0 )
  {
    glview = 1;
    goto LABEL_103;
  }
  if ( _V_stricmp(s1: argv[HIDWORD(i)], s2: "-v") == 0 || _V_stricmp(s1: argv[HIDWORD(i)], s2: "-verbose") == 0 )
  {
    _Msg(a1: "verbose = true\n");
    verbose = 1;
    goto LABEL_103;
  }
  if ( _V_stricmp(s1: argv[HIDWORD(i)], s2: "-noweld") == 0 )
  {
    _Msg(a1: "noweld = true\n");
    noweld = 1;
    goto LABEL_103;
  }
  if ( _V_stricmp(s1: argv[HIDWORD(i)], s2: "-nocsg") == 0 )
  {
    _Msg(a1: "nocsg = true\n");
    nocsg = 1;
    goto LABEL_103;
  }
  if ( _V_stricmp(s1: argv[HIDWORD(i)], s2: "-noshare") == 0 )
  {
    _Msg(a1: "noshare = true\n");
    noshare = 1;
    goto LABEL_103;
  }
  if ( _V_stricmp(s1: argv[HIDWORD(i)], s2: "-notjunc") == 0 )
  {
    _Msg(a1: "notjunc = true\n");
    notjunc = 1;
    goto LABEL_103;
  }
  if ( _V_stricmp(s1: argv[HIDWORD(i)], s2: "-nowater") == 0 )
  {
    _Msg(a1: "nowater = true\n");
    nowater = 1;
    goto LABEL_103;
  }
  if ( _V_stricmp(s1: argv[HIDWORD(i)], s2: "-noopt") == 0 )
  {
    _Msg(a1: "noopt = true\n");
    noopt = 1;
    goto LABEL_103;
  }
  if ( _V_stricmp(s1: argv[HIDWORD(i)], s2: "-noprune") == 0 )
  {
    _Msg(a1: "noprune = true\n");
    noprune = 1;
    goto LABEL_103;
  }
  if ( _V_stricmp(s1: argv[HIDWORD(i)], s2: "-nomerge") == 0 )
  {
    _Msg(a1: "nomerge = true\n");
    nomerge = 1;
    goto LABEL_103;
  }
  if ( _V_stricmp(s1: argv[HIDWORD(i)], s2: "-nomergewater") == 0 )
  {
    _Msg(a1: "nomergewater = true\n");
    nomergewater = 1;
    goto LABEL_103;
  }
  if ( _V_stricmp(s1: argv[HIDWORD(i)], s2: "-nosubdiv") == 0 )
  {
    _Msg(a1: "nosubdiv = true\n");
    nosubdiv = 1;
    goto LABEL_103;
  }
  if ( _V_stricmp(s1: argv[HIDWORD(i)], s2: "-nodetail") == 0 )
  {
    _Msg(a1: "nodetail = true\n");
    nodetail = 1;
    goto LABEL_103;
  }
  if ( _V_stricmp(s1: argv[HIDWORD(i)], s2: "-fulldetail") == 0 )
  {
    _Msg(a1: "fulldetail = true\n");
    fulldetail = 1;
    goto LABEL_103;
  }
  if ( _V_stricmp(s1: argv[HIDWORD(i)], s2: "-alldetail") == 0 )
  {
    g_bConvertStructureToDetail = true;
    goto LABEL_103;
  }
  if ( _V_stricmp(s1: argv[HIDWORD(i)], s2: "-onlyents") == 0 )
  {
    _Msg(a1: "onlyents = true\n");
    onlyents = 1;
    goto LABEL_103;
  }
  if ( _V_stricmp(s1: argv[HIDWORD(i)], s2: "-onlyprops") == 0 )
  {
    _Msg(a1: "onlyprops = true\n");
    onlyprops = true;
    goto LABEL_103;
  }
  if ( _V_stricmp(s1: argv[HIDWORD(i)], s2: "-micro") == 0 )
  {
    v6 = atof(nptr: argv[HIDWORD(i) + 1]);
    microvolume = v6;
    _Msg(a1: "microvolume = %f\n", (double)v6);
    HIDWORD(start) += 4;
    ++HIDWORD(i);
    goto LABEL_103;
  }
  if ( _V_stricmp(s1: argv[HIDWORD(i)], s2: "-leaktest") == 0 )
  {
    _Msg(a1: "leaktest = true\n");
    leaktest = 1;
    goto LABEL_103;
  }
  if ( _V_stricmp(s1: argv[HIDWORD(i)], s2: "-verboseentities") == 0 )
  {
    _Msg(a1: "verboseentities = true\n");
    verboseentities = 1;
    goto LABEL_103;
  }
  if ( _V_stricmp(s1: argv[HIDWORD(i)], s2: "-snapaxial") == 0 )
  {
    _Msg(a1: "snap axial = true\n");
    g_snapAxialPlanes = true;
    goto LABEL_103;
  }
  if ( _V_stricmp(s1: argv[HIDWORD(i)], s2: "-block") == 0 )
  {
    block_xh = atoi(nptr: argv[HIDWORD(i) + 1]);
    block_xl = block_xh;
    block_yh = atoi(nptr: argv[HIDWORD(i) + 2]);
    block_yl = block_yh;
    _Msg(a1: "block: %i,%i\n", block_xl, block_yh);
    HIDWORD(start) += 8;
    HIDWORD(i) += 2;
    goto LABEL_103;
  }
  if ( _V_stricmp(s1: argv[HIDWORD(i)], s2: "-blocks") == 0 )
  {
    block_xl = atoi(nptr: argv[HIDWORD(i) + 1]);
    block_yl = atoi(nptr: argv[HIDWORD(i) + 2]);
    block_xh = atoi(nptr: *(char **)((char *)argv + HIDWORD(start)));
    block_yh = atoi(nptr: argv[HIDWORD(i) + 4]);
    _Msg(a1: "blocks: %i,%i to %i,%i\n", block_xl, block_yl, block_xh, block_yh);
    HIDWORD(i) += 4;
    HIDWORD(start) += 16;
    goto LABEL_103;
  }
  if ( _V_stricmp(s1: argv[HIDWORD(i)], s2: "-blocksize") == 0 )
  {
    v7 = atoi(nptr: argv[HIDWORD(i) + 1]);
    HIDWORD(start) += 4;
    g_nBlockSize = v7;
    ++HIDWORD(i);
    goto LABEL_103;
  }
  if ( _V_stricmp(s1: argv[HIDWORD(i)], s2: "-dumpcollide") == 0 )
  {
    _Msg(a1: "Dumping collision models to collideXXX.txt\n");
    dumpcollide = 1;
    goto LABEL_103;
  }
  if ( _V_stricmp(s1: argv[HIDWORD(i)], s2: "-dumpstaticprop") == 0 )
  {
    _Msg(a1: "Dumping static props to staticpropXXX.txt\n");
    g_DumpStaticProps = 1;
    goto LABEL_103;
  }
  if ( _V_stricmp(s1: argv[HIDWORD(i)], s2: "-forceskyvis") == 0 )
  {
    _Msg(a1: "Enabled vis in 3d skybox\n");
    g_bSkyVis = 1;
    goto LABEL_103;
  }
  if ( _V_stricmp(s1: argv[HIDWORD(i)], s2: "-tmpout") == 0 )
  {
    strcpy(outbase, "/tmp");
    goto LABEL_103;
  }
  if ( _V_stricmp(s1: argv[HIDWORD(i)], s2: "-luxelscale") == 0 )
  {
    g_luxelScale = atof(nptr: argv[HIDWORD(i) + 1]);
LABEL_63:
    HIDWORD(start) += 4;
    HIDWORD(i) = v4 + 1;
    goto LABEL_103;
  }
  if ( strcmp(argv[HIDWORD(i)], "-minluxelscale") == 0 )
  {
    v8 = atof(nptr: argv[HIDWORD(i) + 1]);
    g_minLuxelScale = v8;
    if ( v8 < 1.0 )
      g_minLuxelScale = 1.0;
    ++HIDWORD(i);
    HIDWORD(start) += 4;
    goto LABEL_103;
  }
  if ( _V_stricmp(s1: argv[HIDWORD(i)], s2: "-bumpall") == 0 )
  {
    g_BumpAll = true;
    goto LABEL_103;
  }
  v4 = HIDWORD(i);
  if ( _V_stricmp(s1: argv[HIDWORD(i)], s2: "-low") == 0 )
  {
    g_bLowPriority = 1;
    goto LABEL_103;
  }
  if ( _V_stricmp(s1: argv[HIDWORD(i)], s2: "-lightifmissing") == 0 )
  {
    g_bLightIfMissing = true;
    goto LABEL_103;
  }
  if ( _V_stricmp(s1: argv[HIDWORD(i)], s2: "-NoVConfig") == 0
    || _V_stricmp(s1: argv[HIDWORD(i)], s2: "-allowdebug") == 0
    || _V_stricmp(s1: argv[HIDWORD(i)], s2: "-steam") == 0 )
  {
    goto LABEL_103;
  }
  if ( _V_stricmp(s1: argv[HIDWORD(i)], s2: "-vproject") == 0 || _V_stricmp(s1: argv[HIDWORD(i)], s2: "-game") == 0 )
    goto LABEL_63;
  if ( _V_stricmp(s1: argv[HIDWORD(i)], s2: "-keepstalezip") == 0 )
  {
    g_bKeepStaleZip = true;
    goto LABEL_103;
  }
  if ( _V_stricmp(s1: argv[HIDWORD(i)], s2: "-xbox") == 0 )
  {
    g_NodrawTriggers = true;
    g_DisableWaterLighting = true;
    goto LABEL_103;
  }
  if ( _V_stricmp(s1: argv[HIDWORD(i)], s2: "-allowdetailcracks") == 0 )
  {
    g_bAllowDetailCracks = true;
    goto LABEL_103;
  }
  if ( _V_stricmp(s1: argv[HIDWORD(i)], s2: "-novirtualmesh") == 0 )
  {
    g_bNoVirtualMesh = true;
    goto LABEL_103;
  }
  if ( _V_stricmp(s1: argv[HIDWORD(i)], s2: "-replacematerials") == 0 )
  {
    g_ReplaceMaterials = true;
    goto LABEL_103;
  }
  if ( _V_stricmp(s1: argv[HIDWORD(i)], s2: "-nodrawtriggers") == 0 )
  {
    g_NodrawTriggers = true;
    goto LABEL_103;
  }
  if ( _V_stricmp(s1: argv[HIDWORD(i)], s2: "-FullMinidumps") == 0 )
  {
    EnableFullMinidumps(bFull: true);
    goto LABEL_103;
  }
  if ( _V_stricmp(s1: argv[HIDWORD(i)], s2: "-tempcontent") == 0 )
    goto LABEL_103;
  if ( *argv[HIDWORD(i)] == 45 )
  {
    _Warning(a1: "VBSP: Unknown option \"%s\"\n\n", argv[HIDWORD(i)]);
    HIDWORD(i) = 100000;
  }
LABEL_96:
  v9 = argc;
  v10 = HIDWORD(i);
  if ( HIDWORD(i) != argc - 1 )
  {
    v11 = argv;
    _Warning(a1: "Command line: ");
    for ( j = 0; j < v9; ++j )
      _Warning(a1: "\"%s\" ", v11[j]);
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
      "  -onlyprops  : Only update the static props and detail props.\n"
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
    {
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
        "  -alldetail   : Convert all structural brushes to detail brushes, except\n"
        "                 func_brush entities whose names begin with structure_.\n");
      _Warning(
        a1: "  -leaktest    : Stop processing the map if a leak is detected. Whether or not\n"
        "                 this flag is set, a leak file will be written out at\n"
        "                 <vmf filename>.lin, and it can be imported into Hammer.\n"
        "  -bumpall     : Force all surfaces to be bump mapped.\n"
        "  -snapaxial   : Snap axial planes to integer coordinates.\n"
        "  -block # #      : Control the grid size mins that vbsp chops the level on.\n"
        "  -blocks # # # # : Enter the mins and maxs for the grid size vbsp uses.\n"
        "  -blocksize #    : Control the size of each grid square that vbsp chops the level on.  Default is 1024.  -dumps"
        "taticprops: Dump static props to staticprop*.txt\n"
        "  -dumpcollide    : Write files with collision info.\n"
        "  -forceskyvis\t   : Enable vis calculations in 3d skybox leaves\n"
        "  -luxelscale #   : Scale all lightmaps by this amount (default: 1.0).\n"
        "  -minluxelscale #: No luxel scale will be lower than this amount (default: 1.0).\n"
        "  -lightifmissing : Force lightmaps to be generated for all surfaces even if\n"
        "                    they don't need lightmaps.\n"
        "  -keepstalezip   : Keep the BSP's zip files intact but regenerate everything\n"
        "                    else.\n"
        "  -virtualdispphysics : Use virtual (not precomputed) displacement collision\n"
        "\t\t\t\t\t\t models\n"
        "  -xbox\t\t: Enable mandatory xbox options\n"
        "  -x360\t\t: Generate Xbox360 version of vsp\n"
        "  -nox360\t\t: Disable generation Xbox360 version of vsp (default)\n"
        "  -replacematerials : Substitute materials according to materialsub.txt in\n"
        "\t\t\t\t\t   content\\maps\n"
        "  -FullMinidumps\t: Write large minidumps on crash.\n");
    }
    DeleteCmdLine(argc, argv);
    CmdLib_Cleanup();
    exit(code: 1);
  }
  start = _Plat_FloatTime();
  if ( g_bLowPriority != 0 )
    SetLowPriority();
  ThreadSetDefault();
  numthreads = 1;
  _snprintf(string: logFile, count: 0x200u, format: "%s.log", source);
  CCmdLibFileLoggingListener::Open(this: &g_CmdLibFileLoggingListener, pFilename: logFile);
  PhysicsDLLPath(pPathname: "vphysics.dll");
  LoadSurfaceProperties(a1: (int)_Msg);
  sprintf(string: materialPath, format: "%smaterials", gamedir);
  CmdLib_GetFileSystemFactory();
  InitMaterialSystem(a1: 0, a2: v10);
  _Msg(a1: "materialPath: %s\n", materialPath);
  sprintf(string: path, format: "%s.prt", source);
  remove(path);
  sprintf(string: path, format: "%s.lin", source);
  remove(path);
  v13 = ExpandArg(path: argv[v10]);
  v14 = (char *)(name - v13);
  do
  {
    v15 = *v13;
    v14[(_DWORD)v13] = *v13;
    ++v13;
  }
  while ( v15 != 0 );
  if ( V_GetFileExtension(path: name) == nullptr )
  {
    V_SetExtension(path: name, extension: ".vmm", pathStringLength: 1024);
    if ( FileExists(filename: name) == 0 )
      V_SetExtension(path: name, extension: ".vmf", pathStringLength: 1024);
  }
  GetPlatformMapPath(pMapPath: source, pPlatformMapPath: platformBSPFileName, dxlevel: 0, maxLength: 1024);
  if ( g_ReplaceMaterials )
    LoadMaterialReplacementKeys(gamedir: gamedir, mapname: mapbase);
  if ( onlyents != 0 )
  {
    LoadBSPFile(filename: platformBSPFileName);
    num_entities = 0;
    g_nCubemapSamples = 0;
    PakFile = GetPakFile();
    AddBufferToPak(pak: PakFile, pRelativeName: "stale.txt", data: "stale", length: 6, bTextMode: false);
    LoadMapFile(pszFileName: name);
    SetModelNumbers();
    SetLightStyles();
    EmitStaticProps();
    ComputeBoundsNoSkybox();
    EnsurePresenceOfWaterLODControlEntity();
    FixupOnlyEntsOccluderEntities();
    UnparseEntities();
    WriteBSPFile(a1: (int)_Msg, filename: platformBSPFileName);
  }
  else if ( onlyprops )
  {
    LoadBSPFile(filename: platformBSPFileName);
    LoadMapFile(pszFileName: name);
    SetModelNumbers();
    SetLightStyles();
    EmitStaticProps();
    LoadEmitDetailObjectDictionary();
    EmitDetailObjects();
    WriteBSPFile(a1: (int)_Msg, filename: platformBSPFileName);
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
    Cubemap_FixupBrushSidesMaterials();
    Cubemap_AttachDefaultCubemapToSpecularSides();
    Cubemap_AddUnreferencedCubemaps();
    SetModelNumbers();
    SetLightStyles();
    LoadEmitDetailObjectDictionary();
    AddDefaultStringtableDictionaries();
    ProcessModels(a1: (int)&savedregs, a2: 0, a3: v10);
  }
  i = _Plat_FloatTime();
  GetHourMinuteSecondsString(nInputSeconds: (int)(i - start), pOut: str, outLen: 512);
  _Msg(a1: "%s elapsed\n", str);
  DeleteCmdLine(argc, argv);
  ReleasePakFileLumps();
  DeleteMaterialReplacementKeys();
  ShutdownMaterialSystem();
  CmdLib_Cleanup();
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0042D520
// Name: _main
// Source: json
//------------------------------------------------------------------------------
int __cdecl main(int argc, const char **argv, const char **envp)
{
  SetupDefaultToolsMinidumpHandler();
  return RunVBSP(argc, (char **)argv);
}
