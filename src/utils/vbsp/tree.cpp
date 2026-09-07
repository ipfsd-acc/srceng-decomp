// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vbsp/tree.cpp
// Functions: 6
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0042A6F0
// Name: struct node_t __near * NodeForPoint(struct node_t __near *,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
node_t *__cdecl NodeForPoint(node_t *node, Vector *origin)
{
  node_t *result; // eax
  int i; // ecx

  result = node;
  for ( i = node->planenum; i != -1; i = result->planenum )
  {
    if ( (float)((float)((float)((float)(g_MainMap->mapplanes[i].normal.y * origin->y)
                               + (float)(g_MainMap->mapplanes[i].normal.x * origin->x))
                       + (float)(g_MainMap->mapplanes[i].normal.z * origin->z))
               - g_MainMap->mapplanes[i].dist) < 0.0 )
      result = result->children[1];
    else
      result = result->children[0];
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042A770
// Name: void FreeTreePortals_r(struct node_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FreeTreePortals_r(node_t *node)
{
  portal_t *portals; // esi
  portal_t *v2; // edi

  if ( node->planenum != -1 )
  {
    FreeTreePortals_r(node: node->children[0]);
    FreeTreePortals_r(node: node->children[1]);
  }
  portals = node->portals;
  if ( portals != nullptr )
  {
    do
    {
      v2 = portals->next[portals->nodes[1] == node];
      RemovePortalFromNode(portal: portals, l: portals->nodes[portals->nodes[1] != node]);
      FreePortal(p: portals);
      portals = v2;
    }
    while ( v2 != nullptr );
  }
  node->portals = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0042A7E0
// Name: void FreeTree_r(struct node_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FreeTree_r(node_t *node)
{
  face_t *faces; // eax
  face_t *next; // esi

  if ( node->planenum != -1 )
  {
    FreeTree_r(node: node->children[0]);
    FreeTree_r(node: node->children[1]);
  }
  FreeBrushList(brushes: node->brushlist);
  faces = node->faces;
  if ( faces != nullptr )
  {
    do
    {
      next = faces->next;
      FreeFace(f: faces);
      faces = next;
    }
    while ( next != nullptr );
  }
  if ( node->volume != nullptr )
    FreeBrush(brushes: node->volume);
  if ( numthreads == 1 )
    --c_nodes;
  free(pMem: node);
}

//------------------------------------------------------------------------------
// Address: 0x0042A860
// Name: void FreeTree(struct tree_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FreeTree(tree_t *tree)
{
  if ( tree != nullptr )
  {
    FreeTreePortals_r(node: tree->headnode);
    FreeTree_r(node: tree->headnode);
    free(pMem: tree);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042A890
// Name: void PruneNodes_r(struct node_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PruneNodes_r(node_t *node)
{
  bool v1; // zf
  node_t *v2; // edx
  bspbrush_t *brushlist; // eax
  bspbrush_t *next; // ecx

  if ( node->planenum != -1 )
  {
    PruneNodes_r(node: node->children[0]);
    PruneNodes_r(node: node->children[1]);
    if ( (node->children[0]->contents & 1) != 0 && (node->children[1]->contents & 1) != 0 )
    {
      if ( node->faces != nullptr )
        _Error(a1: "node->faces seperating CONTENTS_SOLID");
      if ( node->children[0]->faces != nullptr || node->children[1]->faces != nullptr )
        _Error(a1: "!node->faces with children");
      v1 = node->brushlist == nullptr;
      node->planenum = -1;
      node->contents = 1;
      if ( !v1 )
        _Error(a1: "PruneNodes: node->brushlist");
      v2 = node->children[0];
      node->brushlist = node->children[1]->brushlist;
      brushlist = v2->brushlist;
      if ( brushlist != nullptr )
      {
        do
        {
          next = brushlist->next;
          brushlist->next = node->brushlist;
          node->brushlist = brushlist;
          brushlist = next;
        }
        while ( next != nullptr );
      }
      ++c_pruned;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042A950
// Name: void PruneNodes(struct node_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PruneNodes(node_t *node)
{
  qprintf(format: "--- PruneNodes ---\n");
  c_pruned = 0;
  PruneNodes_r(node);
  qprintf(format: "%5i pruned nodes\n", c_pruned);
}
