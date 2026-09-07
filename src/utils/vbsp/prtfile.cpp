// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vbsp/prtfile.cpp
// Functions: 9
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x004259D0
// Name: float VolumeOfIntersection(struct bspbrush_t __near *,struct node_t __near *)
// Source: json
//------------------------------------------------------------------------------
double __cdecl VolumeOfIntersection(bspbrush_t *pBrushList, node_t *pNode)
{
  bspbrush_t *v2; // esi
  bspbrush_t *v3; // eax
  bspbrush_t *v4; // edi
  float volume; // [esp+0h] [ebp-4h]

  v2 = pBrushList;
  for ( volume = 0.0; v2 != nullptr; v2 = v2->next )
  {
    if ( IsBoxIntersectingBox(boxMin1: &pNode->mins, boxMax1: &pNode->maxs, boxMin2: &v2->mins, boxMax2: &v2->maxs) )
    {
      v3 = IntersectBrush(a: pNode->volume, b: v2);
      v4 = v3;
      if ( v3 != nullptr )
      {
        volume = BrushVolume(brush: v3) + volume;
        FreeBrush(brushes: v4);
      }
    }
  }
  return volume;
}

//------------------------------------------------------------------------------
// Address: 0x00425A50
// Name: void CreateVisPortals_r(struct node_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CreateVisPortals_r(node_t *node)
{
  node_t *i; // esi

  for ( i = node; i->planenum != -1; i = i->children[1] )
  {
    MakeNodePortal(node: (winding_t *)i);
    SplitNodePortals(node: i);
    CreateVisPortals_r(node: i->children[0]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00425A90
// Name: void SaveClusters_r(struct node_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SaveClusters_r(node_t *node)
{
  node_t *i; // esi
  int v2; // eax

  for ( i = node; i->planenum != -1; i = i->children[1] )
    SaveClusters_r(node: i->children[0]);
  v2 = clusterleaf + 1;
  word_4BA35C4[16 * clusterleaf] = i->cluster;
  clusterleaf = v2;
}

//------------------------------------------------------------------------------
// Address: 0x00425AE0
// Name: void WritePortalFile(struct _iobuf __near *,class CUtlVector<struct cluster_portals_t,class CUtlMemory<struct cluster_portals_t,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl WritePortalFile(
        _iobuf *pFile,
        const CUtlVector<cluster_portals_t,CUtlMemory<cluster_portals_t,int> > *list)
{
  const CUtlVector<cluster_portals_t,CUtlMemory<cluster_portals_t,int> > *v2; // ecx
  cluster_portals_t *m_pMemory; // eax
  portal_t *v4; // edi
  winding_t *winding; // ebx
  node_t *v6; // edx
  int v7; // edi
  __m128 v8; // xmm2
  __m128 x_low; // xmm0
  __m128 v10; // xmm3
  __m128 v11; // xmm1
  __m128 v12; // xmm2
  float v13; // xmm1_4
  __m128 v14; // xmm2
  __m128 y_low; // xmm0
  __m128 v16; // xmm3
  __m128 v17; // xmm1
  __m128 v18; // xmm2
  float v19; // xmm1_4
  __m128 v20; // xmm2
  __m128 z_low; // xmm0
  __m128 v22; // xmm3
  __m128 v23; // xmm1
  __m128 v24; // xmm2
  float v25; // xmm1_4
  Vector normal; // [esp+14h] [ebp-20h] BYREF
  float dist; // [esp+20h] [ebp-14h] BYREF
  int clusterIndex; // [esp+24h] [ebp-10h]
  int i; // [esp+28h] [ebp-Ch]
  int j; // [esp+2Ch] [ebp-8h]
  unsigned int v31; // [esp+30h] [ebp-4h]

  v2 = list;
  clusterIndex = 0;
  if ( list->m_Size > 0 )
  {
    v31 = 0;
    do
    {
      m_pMemory = v2->m_Memory.m_pMemory;
      j = 0;
      if ( m_pMemory[v31 / 0x14].portals.m_Size > 0 )
      {
        do
        {
          v4 = m_pMemory[v31 / 0x14].portals.m_Memory.m_pMemory[j];
          winding = v4->winding;
          WindingPlane(w: winding, &normal, &dist);
          v6 = v4->nodes[1];
          if ( (float)((float)((float)(v4->plane.normal.y * normal.y) + (float)(v4->plane.normal.x * normal.x))
                     + (float)(v4->plane.normal.z * normal.z)) >= 0.99 )
            fprintf(str: pFile, format: "%i %i %i ", winding->numpoints, v4->nodes[0]->cluster, v6->cluster);
          else
            fprintf(str: pFile, format: "%i %i %i ", winding->numpoints, v6->cluster, v4->nodes[0]->cluster);
          v7 = 0;
          for ( i = 0; i < winding->numpoints; ++i )
          {
            fprintf(str: pFile, format: "(");
            v8.m128_i32[0] = 1258291200;
            x_low = (__m128)LODWORD(winding->p[v7].x);
            x_low.m128_f32[0] = x_low.m128_f32[0] + 0.5;
            v10 = _mm_and_ps((__m128)0x80000000, x_low);
            v8.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(x_low, v10), v8).m128_f32[0]) & 0x4B000000
                           | v10.m128_i32[0];
            v11 = x_low;
            v11.m128_f32[0] = (float)(x_low.m128_f32[0] + v8.m128_f32[0]) - v8.m128_f32[0];
            v12 = v11;
            v12.m128_f32[0] = v11.m128_f32[0] - x_low.m128_f32[0];
            v13 = v11.m128_f32[0] - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v12, v10).m128_f32[0]) & 0x3F800000);
            if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(winding->p[v7].x - v13) & _mask__AbsFloat_) >= 0.001 )
              fprintf(str: pFile, format: "%f ", winding->p[v7].x);
            else
              fprintf(str: pFile, format: "%i ", (int)v13);
            v14.m128_i32[0] = 1258291200;
            y_low = (__m128)LODWORD(winding->p[v7].y);
            y_low.m128_f32[0] = y_low.m128_f32[0] + 0.5;
            v16 = _mm_and_ps((__m128)0x80000000, y_low);
            v14.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(y_low, v16), v14).m128_f32[0]) & 0x4B000000
                            | v16.m128_i32[0];
            v17 = y_low;
            v17.m128_f32[0] = (float)(y_low.m128_f32[0] + v14.m128_f32[0]) - v14.m128_f32[0];
            v18 = v17;
            v18.m128_f32[0] = v17.m128_f32[0] - y_low.m128_f32[0];
            v19 = v17.m128_f32[0] - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v18, v16).m128_f32[0]) & 0x3F800000);
            if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(winding->p[v7].y - v19) & _mask__AbsFloat_) >= 0.001 )
              fprintf(str: pFile, format: "%f ", winding->p[v7].y);
            else
              fprintf(str: pFile, format: "%i ", (int)v19);
            v20.m128_i32[0] = 1258291200;
            z_low = (__m128)LODWORD(winding->p[v7].z);
            z_low.m128_f32[0] = z_low.m128_f32[0] + 0.5;
            v22 = _mm_and_ps((__m128)0x80000000, z_low);
            v20.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(z_low, v22), v20).m128_f32[0]) & 0x4B000000
                            | v22.m128_i32[0];
            v23 = z_low;
            v23.m128_f32[0] = (float)(z_low.m128_f32[0] + v20.m128_f32[0]) - v20.m128_f32[0];
            v24 = v23;
            v24.m128_f32[0] = v23.m128_f32[0] - z_low.m128_f32[0];
            v25 = v23.m128_f32[0] - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v24, v22).m128_f32[0]) & 0x3F800000);
            if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(winding->p[v7].z - v25) & _mask__AbsFloat_) >= 0.001 )
              fprintf(str: pFile, format: "%f ", winding->p[v7].z);
            else
              fprintf(str: pFile, format: "%i ", (int)v25);
            fprintf(str: pFile, format: ") ");
            ++v7;
          }
          fprintf(str: pFile, format: "\n");
          m_pMemory = list->m_Memory.m_pMemory;
          ++j;
        }
        while ( j < m_pMemory[v31 / 0x14].portals.m_Size );
        v2 = list;
      }
      v31 += 20;
      ++clusterIndex;
    }
    while ( clusterIndex < v2->m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00425E40
// Name: void NumberLeafs(class CUtlVector<struct node_t __near *,class CUtlMemory<struct node_t __near *,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NumberLeafs(const CUtlVector<node_t *,CUtlMemory<node_t *,int> > *leaves)
{
  node_t *v1; // edi
  int v2; // ebx
  int v3; // esi
  int v4; // edi
  viscluster_t *m_pMemory; // ecx
  int v6; // ebx
  int v7; // eax
  float v8; // [esp+0h] [ebp-Ch]
  int i; // [esp+4h] [ebp-8h]
  node_t *node; // [esp+8h] [ebp-4h]

  i = 0;
  if ( leaves->m_Size > 0 )
  {
    while ( 1 )
    {
      v1 = leaves->m_Memory.m_pMemory[i];
      node = v1;
      v2 = -1;
      v8 = BrushVolume(brush: v1->volume) * 0.1;
      v3 = g_VisClusters.m_Size - 1;
      if ( g_VisClusters.m_Size - 1 < 0 )
        goto LABEL_12;
      v4 = v3;
      do
      {
        if ( VolumeOfIntersection(pBrushList: g_VisClusters.m_Memory.m_pMemory[v4].pBrushes, pNode: node) > v8 )
          v2 = v3;
        --v4;
        --v3;
      }
      while ( v3 >= 0 );
      if ( v2 < 0 )
        break;
      m_pMemory = g_VisClusters.m_Memory.m_pMemory;
      v6 = v2;
      if ( g_VisClusters.m_Memory.m_pMemory[v6].clusterIndex < 0 )
      {
        g_VisClusters.m_Memory.m_pMemory[v6].clusterIndex = num_visclusters++;
        m_pMemory = g_VisClusters.m_Memory.m_pMemory;
      }
      ++m_pMemory[v6].leafCount;
      node->cluster = g_VisClusters.m_Memory.m_pMemory[v6].clusterIndex;
LABEL_18:
      if ( ++i >= leaves->m_Size )
        return;
    }
    v1 = node;
LABEL_12:
    if ( g_bSkyVis != 0 || !Is3DSkyboxArea(area: v1->area) )
    {
      v1->cluster = num_visclusters++;
    }
    else
    {
      v7 = g_SkyCluster;
      if ( g_SkyCluster < 0 )
      {
        v7 = num_visclusters;
        g_SkyCluster = num_visclusters++;
      }
      v1->cluster = v7;
    }
    goto LABEL_18;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00425FF0
// Name: void AddVisCluster(struct entity_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddVisCluster(entity_t *pFuncVisCluster)
{
  int firstbrush; // eax
  bspbrush_t *BspBrushList; // eax
  int v3; // [esp-18h] [ebp-40h]
  viscluster_t tmp; // [esp+0h] [ebp-28h] BYREF
  Vector clipMins; // [esp+10h] [ebp-18h] BYREF
  Vector clipMaxs; // [esp+1Ch] [ebp-Ch] BYREF

  firstbrush = pFuncVisCluster->firstbrush;
  v3 = firstbrush + pFuncVisCluster->numbrushes;
  clipMins.z = -16384.0;
  clipMins.y = -16384.0;
  clipMins.x = -16384.0;
  clipMaxs.z = 16384.0;
  clipMaxs.y = 16384.0;
  clipMaxs.x = 16384.0;
  BspBrushList = MakeBspBrushList(
                   startbrush: firstbrush,
                   endbrush: v3,
                   clipmins: &clipMins,
                   clipmaxs: &clipMaxs,
                   detailScreen: 2);
  tmp.pBrushes = ChopBrushes(head: BspBrushList);
  tmp.clusterIndex = -1;
  tmp.leafCount = 0;
  tmp.leafStart = 0;
  CUtlVector<viscluster_t,CUtlMemory<viscluster_t,int>>::InsertBefore(
    this: &g_VisClusters,
    elem: g_VisClusters.m_Size,
    src: &tmp);
  pFuncVisCluster->epairs = nullptr;
  pFuncVisCluster->numbrushes = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00426080
// Name: void BuildVisLeafList_r(struct node_t __near *,class CUtlVector<struct node_t __near *,class CUtlMemory<struct node_t __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildVisLeafList_r(node_t *node, CUtlVector<node_t *,CUtlMemory<node_t *,int> > *leaves)
{
  node_t *i; // edi
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  node_t **m_pMemory; // ecx
  int v6; // eax
  node_t **v7; // ebx
  node_t *v8; // [esp-8h] [ebp-14h]

  for ( i = node; i->planenum != -1; i = i->children[1] )
  {
    v8 = i->children[0];
    i->cluster = -99;
    BuildVisLeafList_r(node: v8, leaves);
  }
  if ( (i->contents & 1) != 0 )
  {
    i->cluster = -1;
  }
  else
  {
    m_Size = leaves->m_Size;
    m_nAllocationCount = leaves->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CClassInput *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)leaves, num: m_Size - m_nAllocationCount + 1);
    ++leaves->m_Size;
    m_pMemory = leaves->m_Memory.m_pMemory;
    v6 = leaves->m_Size - m_Size - 1;
    leaves->m_pElements = leaves->m_Memory.m_pMemory;
    if ( v6 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
    v7 = &leaves->m_Memory.m_pMemory[m_Size];
    if ( v7 != nullptr )
      *v7 = i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004261C0
// Name: int BuildPortalList(class CUtlVector<struct cluster_portals_t,class CUtlMemory<struct cluster_portals_t,int>> __near &,class CUtlVector<struct node_t __near *,class CUtlMemory<struct node_t __near *,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl BuildPortalList(
        CUtlVector<cluster_portals_t,CUtlMemory<cluster_portals_t,int> > *portalList,
        const CUtlVector<node_t *,CUtlMemory<node_t *,int> > *leaves)
{
  const CUtlVector<node_t *,CUtlMemory<node_t *,int> > *v2; // ecx
  int result; // eax
  node_t *v4; // esi
  portal_t *portals; // ebx
  node_t *v6; // eax
  int m_Size; // edi
  CUtlMemory<S3RGBA,int> *v8; // esi
  int m_nAllocationCount; // eax
  S3RGBA *m_pMemory; // ecx
  int v11; // eax
  S3RGBA *v12; // ecx
  portal_t **v13; // eax
  int i; // [esp+0h] [ebp-Ch]
  node_t *node; // [esp+4h] [ebp-8h]
  int portalCount; // [esp+8h] [ebp-4h]

  v2 = leaves;
  result = 0;
  portalCount = 0;
  i = 0;
  if ( leaves->m_Size > 0 )
  {
    do
    {
      v4 = v2->m_Memory.m_pMemory[result];
      portals = v4->portals;
      node = v4;
      if ( portals != nullptr )
      {
        do
        {
          v6 = portals->nodes[0];
          if ( v6 == v4 )
          {
            if ( v6->cluster != portals->nodes[1]->cluster && Portal_VisFlood(p: portals) )
            {
              ++portalCount;
              m_Size = portalList->m_Memory.m_pMemory[v4->cluster].portals.m_Size;
              v8 = (CUtlMemory<S3RGBA,int> *)&portalList->m_Memory.m_pMemory[v4->cluster];
              m_nAllocationCount = v8->m_nAllocationCount;
              if ( m_Size + 1 > m_nAllocationCount )
                CUtlMemory<CClassInput *,int>::Grow(this: v8, num: m_Size - m_nAllocationCount + 1);
              ++v8[1].m_pMemory;
              m_pMemory = v8->m_pMemory;
              v11 = (int)v8[1].m_pMemory - m_Size - 1;
              v8[1].m_nAllocationCount = (int)v8->m_pMemory;
              if ( v11 > 0 )
                _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v11);
              v12 = v8->m_pMemory;
              v4 = node;
              v13 = (portal_t **)&v12[m_Size];
              if ( v13 != nullptr )
                *v13 = portals;
            }
            portals = portals->next[0];
          }
          else
          {
            portals = portals->next[1];
          }
        }
        while ( portals != nullptr );
        v2 = leaves;
        result = i;
      }
      i = ++result;
    }
    while ( result < v2->m_Size );
    return portalCount;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004263B0
// Name: void WritePortalFile(struct tree_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl WritePortalFile(tree_t *tree)
{
  node_t *headnode; // ebx
  int v2; // edi
  _iobuf *v3; // edi
  double v4; // st7
  char filename[1024]; // [esp+Ch] [ebp-42Ch] BYREF
  CUtlVector<node_t *,CUtlMemory<node_t *,int> > leaves; // [esp+40Ch] [ebp-2Ch] BYREF
  int start; // [esp+420h] [ebp-18h]
  CUtlVector<cluster_portals_t,CUtlMemory<cluster_portals_t,int> > portalList; // [esp+424h] [ebp-14h] BYREF

  start = (int)_Plat_FloatTime();
  qprintf(format: "--- WritePortalFile ---\n");
  sprintf(string: filename, format: "%s.prt", source);
  _Msg(a1: "writing %s...", filename);
  headnode = tree->headnode;
  FreeTreePortals_r(node: tree->headnode);
  MakeHeadnodePortals(tree);
  CreateVisPortals_r(node: headnode);
  num_visclusters = 0;
  _Msg(a1: "Building visibility clusters...\n");
  memset(&leaves, 0, sizeof(leaves));
  BuildVisLeafList_r(node: headnode, &leaves);
  NumberLeafs(&leaves);
  v2 = num_visclusters;
  memset(&portalList, 0, sizeof(portalList));
  CUtlVector<cluster_portals_t,CUtlMemory<cluster_portals_t,int>>::RemoveAll(this: (CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *)&portalList);
  CUtlVector<cluster_portals_t,CUtlMemory<cluster_portals_t,int>>::InsertMultipleBefore(
    this: &portalList,
    elem: portalList.m_Size,
    num: v2);
  num_visportals = BuildPortalList(&portalList, &leaves);
  v3 = fopen(file: filename, mode: "w");
  if ( v3 == nullptr )
    _Error(a1: "Error opening %s", filename);
  fprintf(str: v3, format: "%s\n", "PRT1");
  fprintf(str: v3, format: "%i\n", num_visclusters);
  fprintf(str: v3, format: "%i\n", num_visportals);
  qprintf(format: "%5i visclusters\n", num_visclusters);
  qprintf(format: "%5i visportals\n", num_visportals);
  WritePortalFile(pFile: v3, list: &portalList);
  fclose(stream: v3);
  clusterleaf = 1;
  SaveClusters_r(node: headnode);
  v4 = _Plat_FloatTime() - (double)start;
  _Msg(a1: "done (%d)\n", (int)v4);
  CUtlVector<cluster_portals_t,CUtlMemory<cluster_portals_t,int>>::~CUtlVector<cluster_portals_t,CUtlMemory<cluster_portals_t,int>>(this: (CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *)&portalList);
  CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&leaves);
}
