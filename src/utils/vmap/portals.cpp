// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vmap/portals.cpp
// Functions: 40
// ============================================================

#include "utils\vmap\portals.h"

//------------------------------------------------------------------------------
// Address: 0x00429BF0
// Name: int VectorCompare(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl VectorCompare(const Vector *v1, const Vector *v2)
{
  return v2->x == v1->x && v2->y == v1->y && v2->z == v1->z;
}

//------------------------------------------------------------------------------
// Address: 0x00429C40
// Name: void FreePortal(struct portal_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FreePortal(portal_t *p)
{
  if ( p->winding != nullptr )
    FreeWinding(w: p->winding);
  if ( numthreads == 1 )
    --c_active_portals;
  free(pMem: p);
}

//------------------------------------------------------------------------------
// Address: 0x00429C80
// Name: int VisibleContents(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl VisibleContents(int contents)
{
  int result; // eax

  result = 1;
  while ( (result & contents) == 0 )
  {
    result *= 2;
    if ( result > 128 )
      return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00429CB0
// Name: int ClusterContents(struct node_t __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl ClusterContents(node_t *node)
{
  unsigned int result; // eax
  int v2; // ebx
  int v3; // eax
  char v4; // cl

  if ( node->planenum == -1 )
    return node->contents;
  v2 = ClusterContents(node: node->children[0]);
  v3 = ClusterContents(node: node->children[1]);
  v4 = v3;
  result = v2 | v3;
  if ( (v2 & 1) == 0 || (v4 & 1) == 0 )
    result &= ~1u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00429CF0
// Name: int Portal_VisFlood(struct portal_t __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Portal_VisFlood(portal_t *p)
{
  node_t *v2; // edx
  int contents; // edx
  int v4; // edx
  unsigned int v5; // ebx
  unsigned int v6; // eax
  int v7; // ecx
  node_t *v8; // esi
  int v9; // ecx
  unsigned int v10; // ebx
  unsigned int v11; // eax
  int v12; // eax
  int v13; // ecx

  if ( p->onnode == nullptr )
    return false;
  v2 = p->nodes[0];
  if ( v2->planenum == -1 )
  {
    contents = v2->contents;
  }
  else
  {
    v5 = ClusterContents(node: v2->children[0]);
    v6 = ClusterContents(node: *(node_t **)(v4 + 48));
    v7 = v5 | v6;
    if ( (v5 & 1) == 0 || (v6 & 1) == 0 )
      v7 &= ~1u;
    contents = v7;
  }
  v8 = p->nodes[1];
  if ( v8->planenum == -1 )
  {
    v9 = v8->contents;
  }
  else
  {
    v10 = ClusterContents(node: v8->children[0]);
    v11 = ClusterContents(node: v8->children[1]);
    v9 = v10 | v11;
    if ( (v10 & 1) == 0 || (v11 & 1) == 0 )
      v9 &= ~1u;
  }
  v12 = 1;
  while ( ((contents ^ v9) & v12) == 0 )
  {
    v12 *= 2;
    if ( v12 > 128 )
      return true;
  }
  if ( v12 == 0 )
    return true;
  if ( (contents & 0x18000000) != 0 )
    contents = 0;
  if ( (v9 & 0x18000000) != 0 )
    v9 = 0;
  if ( (((unsigned __int8)contents | (unsigned __int8)v9) & 1) != 0 )
    return false;
  v13 = contents ^ v9;
  return v13 == 0 || VisibleContents(contents: v13) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x00429DE0
// Name: void RemovePortalFromNode(struct portal_t __near *,struct node_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RemovePortalFromNode(portal_t *portal, node_t *l)
{
  node_t *v2; // eax
  portal_t **p_portals; // edi
  portal_t *v4; // esi

  v2 = l;
  p_portals = &l->portals;
  while ( 1 )
  {
    v4 = *p_portals;
    if ( *p_portals == nullptr )
    {
      _Error(a1: "RemovePortalFromNode: portal not in leaf");
      v2 = l;
    }
    if ( v4 == portal )
      break;
    if ( v4->nodes[0] == v2 )
    {
      p_portals = v4->next;
    }
    else if ( v4->nodes[1] == v2 )
    {
      p_portals = &v4->next[1];
    }
    else
    {
      _Error(a1: "RemovePortalFromNode: portal not bounding leaf");
      v2 = l;
    }
  }
  if ( portal->nodes[0] == v2 )
  {
    *p_portals = portal->next[0];
    portal->nodes[0] = nullptr;
  }
  else if ( portal->nodes[1] == v2 )
  {
    *p_portals = portal->next[1];
    portal->nodes[1] = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00429E60
// Name: struct bspbrush_t __near * AreaportalBrushForNode(struct node_t __near *)
// Source: json
//------------------------------------------------------------------------------
bspbrush_t *__cdecl AreaportalBrushForNode(node_t *node)
{
  bspbrush_t *result; // eax

  for ( result = node->brushlist; result != nullptr; result = result->next )
  {
    if ( (result->original->contents & 0x8000) != 0 )
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00429E90
// Name: struct winding_t __near * BaseWindingForNode(struct node_t __near *)
// Source: json
//------------------------------------------------------------------------------
winding_t *__cdecl BaseWindingForNode(winding_t *node)
{
  winding_t *v1; // edi
  winding_t *result; // eax
  winding_t *maxpoints; // esi
  Vector *v4; // eax
  float x; // xmm0_4
  Vector normal; // [esp+10h] [ebp-Ch] BYREF

  v1 = node;
  result = BaseWindingForPlane(normal: &mapplanes + 2 * (int)node->p, dist: *(&dist + 6 * (int)node->p));
  maxpoints = (winding_t *)v1->maxpoints;
  for ( node = result; maxpoints != nullptr; maxpoints = (winding_t *)maxpoints->maxpoints )
  {
    if ( result == nullptr )
      break;
    v4 = &mapplanes + 2 * (int)maxpoints->p;
    x = v4[1].x;
    if ( maxpoints[2].next == v1 )
    {
      ChopWindingInPlace(inout: &node, normal: v4, dist: x, epsilon: 0.001);
    }
    else
    {
      normal.x = vec3_origin.x - v4->x;
      normal.y = vec3_origin.y - v4->y;
      normal.z = vec3_origin.z - v4->z;
      ChopWindingInPlace(inout: &node, &normal, dist: COERCE_FLOAT(LODWORD(x) ^ _mask__NegFloat_), epsilon: 0.001);
    }
    result = node;
    v1 = maxpoints;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00429F90
// Name: void CalcNodeBounds(struct node_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CalcNodeBounds(node_t *node)
{
  node_t *v1; // ebx
  portal_t *i; // esi
  int v3; // edi
  winding_t *winding; // eax
  int v5; // ebx
  BOOL s; // [esp+8h] [ebp-4h]

  v1 = node;
  ClearBounds(mins: &node->mins, maxs: &node->maxs);
  for ( i = node->portals; i != nullptr; i = i->next[s] )
  {
    v3 = 0;
    s = i->nodes[1] == v1;
    winding = i->winding;
    if ( winding->numpoints > 0 )
    {
      v5 = 0;
      do
      {
        AddPointToBounds(v: &winding->p[v5], mins: &node->mins, maxs: &node->maxs);
        winding = i->winding;
        ++v3;
        ++v5;
      }
      while ( v3 < winding->numpoints );
      v1 = node;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042A000
// Name: void FloodPortals_r(struct node_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FloodPortals_r(node_t *node, int dist)
{
  node_t *v2; // ecx
  portal_t *portals; // esi
  node_t *v4; // eax
  BOOL v5; // edi
  node_t **v6; // ebx

  v2 = node;
  portals = node->portals;
  node->occupied = dist;
  if ( portals != nullptr )
  {
    while ( 1 )
    {
      v4 = portals->nodes[1];
      v5 = v4 == v2;
      v6 = &portals->nodes[v4 != v2];
      if ( (*v6)->occupied == 0 )
      {
        if ( portals->nodes[0]->planenum != -1 || v4->planenum != -1 )
          _Error(a1: "Portal_EntityFlood: not a leaf");
        if ( (portals->nodes[0]->contents & 1) == 0 && (portals->nodes[1]->contents & 1) == 0 )
          FloodPortals_r(node: *v6, dist: dist + 1);
      }
      portals = portals->next[v5];
      if ( portals == nullptr )
        break;
      v2 = node;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042A090
// Name: void FloodAreaLeak_r(struct node_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FloodAreaLeak_r(node_t *node, int dist)
{
  node_t *v2; // ecx
  portal_t *portals; // esi
  node_t *v4; // eax
  BOOL v5; // edi
  node_t **v6; // ebx
  int contents; // ecx
  int v8; // eax

  v2 = node;
  portals = node->portals;
  node->occupied = dist;
  if ( portals != nullptr )
  {
    while ( 1 )
    {
      v4 = portals->nodes[1];
      v5 = v4 == v2;
      v6 = &portals->nodes[v4 != v2];
      if ( (*v6)->occupied == 0 )
      {
        if ( portals->nodes[0]->planenum != -1 || v4->planenum != -1 )
          _Error(a1: "Portal_EntityFlood: not a leaf");
        contents = portals->nodes[0]->contents;
        if ( (contents & 1) == 0 )
        {
          v8 = portals->nodes[1]->contents;
          if ( (v8 & 1) == 0 && (contents & 0x8000) == 0 && (v8 & 0x8000) == 0 )
            FloodAreaLeak_r(node: *v6, dist: dist + 1);
        }
      }
      portals = portals->next[v5];
      if ( portals == nullptr )
        break;
      v2 = node;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042A140
// Name: void ClearOccupied_r(struct node_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClearOccupied_r(node_t *headnode)
{
  node_t *i; // esi
  node_t *v2; // [esp-4h] [ebp-8h]

  for ( i = headnode; i != nullptr; i = i->children[1] )
  {
    v2 = i->children[0];
    i->occupied = 0;
    ClearOccupied_r(headnode: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042A170
// Name: int PlaceOccupant(struct node_t __near *,class Vector __near &,struct entity_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl PlaceOccupant(node_t *headnode, Vector *origin, entity_t *occupant)
{
  node_t *v3; // ecx
  int *i; // eax

  v3 = headnode;
  for ( i = &headnode->planenum; v3->planenum != -1; i = &v3->planenum )
  {
    if ( (float)((float)((float)((float)(*(&mapplanes.y + 6 * *i) * origin->y)
                               + (float)(*(&mapplanes.x + 6 * *i) * origin->x))
                       + (float)(*(&mapplanes.z + 6 * *i) * origin->z))
               - *((float *)&mapplanes + 6 * *i + 3)) < 0.0 )
      v3 = v3->children[1];
    else
      v3 = v3->children[0];
  }
  if ( v3->contents == 1 )
    return 0;
  v3->occupant = occupant;
  FloodPortals_r(node: v3, dist: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0042A220
// Name: int FloodEntities(struct tree_t __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl FloodEntities(tree_t *tree)
{
  tree_t *v1; // esi
  int v2; // edi
  entity_t *v3; // ebx
  const char *v4; // eax
  float y; // xmm1_4
  float x; // xmm0_4
  int v7; // edi
  float v8; // xmm2_4
  int v9; // esi
  Vector origin; // [esp+8h] [ebp-20h] BYREF
  float v12; // [esp+14h] [ebp-14h]
  float v13; // [esp+18h] [ebp-10h]
  int i; // [esp+1Ch] [ebp-Ch]
  node_t *headnode; // [esp+20h] [ebp-8h]
  int inside; // [esp+24h] [ebp-4h]

  v1 = tree;
  headnode = tree->headnode;
  qprintf(format: "--- FloodEntities ---\n");
  v2 = 0;
  tree->outside_node.occupied = 0;
  inside = 0;
  i = 1;
  if ( num_entities <= 1 )
  {
LABEL_17:
    qprintf(format: "no entities in open -- no filling\n");
    goto LABEL_18;
  }
  v3 = &ent;
  do
  {
    GetVectorForKey(ent: v3, key: "origin", angle: (QAngle *)&origin);
    if ( vec3_origin.x != origin.x || vec3_origin.y != origin.y || vec3_origin.z != origin.z )
    {
      v4 = ValueForKey(ent: v3, key: "classname");
      origin.z = origin.z + 1.0;
      if ( strcmp(v4, "info_player_start") == 0 )
      {
        y = origin.y;
        x = origin.x;
        v7 = -16;
LABEL_8:
        v8 = (float)v7;
        v9 = -16;
        v13 = (float)v7;
        while ( 1 )
        {
          v12 = (float)v9;
          origin.x = v8 + x;
          origin.y = (float)v9 + y;
          if ( PlaceOccupant(headnode, &origin, occupant: v3) != 0 )
            break;
          v8 = v13;
          y = origin.y - v12;
          v9 += 16;
          x = origin.x - v13;
          origin.x = origin.x - v13;
          origin.y = origin.y - v12;
          if ( v9 > 16 )
          {
            v7 += 16;
            if ( v7 <= 16 )
              goto LABEL_8;
            goto LABEL_15;
          }
        }
      }
      else if ( PlaceOccupant(headnode, &origin, occupant: v3) == 0 )
      {
        goto LABEL_15;
      }
      inside = 1;
    }
LABEL_15:
    ++v3;
    ++i;
  }
  while ( i < num_entities );
  v2 = inside;
  v1 = tree;
  if ( inside == 0 )
    goto LABEL_17;
LABEL_18:
  if ( v1->outside_node.occupied != 0 )
    qprintf(format: "entity reached from outside -- no filling\n");
  return v2 != 0 && v1->outside_node.occupied == 0;
}

//------------------------------------------------------------------------------
// Address: 0x0042A410
// Name: void FloodAreas_r(struct node_t __near *,struct portal_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FloodAreas_r(node_t *node, portal_t *pSeeThrough)
{
  bspbrush_t *i; // ecx
  _DWORD *v3; // eax
  int v4; // edi
  int v5; // esi
  portal_t *portals; // esi
  node_t *v7; // eax
  BOOL v8; // edi

  if ( (node->contents & 0x8000) != 0 )
  {
    for ( i = node->brushlist; i != nullptr; i = i->next )
    {
      if ( (i->original->contents & 0x8000) != 0 )
        break;
    }
    v3 = (_DWORD *)(&entities.x + 11 * i->original->entitynum);
    v4 = v3[7];
    if ( v4 != c_areas )
    {
      v5 = v3[8];
      if ( v5 != c_areas )
      {
        if ( v5 != 0 )
        {
          _Warning(
            a1: "WARNING: areaportal entity %i (brush %i) touches > 2 areas\n",
            i->original->entitynum,
            i->original->id);
        }
        else if ( v4 != 0 )
        {
          v3[8] = c_areas;
          v3[10] = pSeeThrough;
        }
        else
        {
          v3[7] = c_areas;
          v3[9] = pSeeThrough;
        }
      }
    }
  }
  else if ( node->area == 0 )
  {
    portals = node->portals;
    for ( node->area = c_areas; portals != nullptr; portals = portals->next[v8] )
    {
      v7 = portals->nodes[1];
      v8 = v7 == node;
      if ( portals->nodes[0]->planenum != -1 || v7->planenum != -1 )
        _Error(a1: "Portal_EntityFlood: not a leaf");
      if ( (portals->nodes[0]->contents & 1) == 0 && (portals->nodes[1]->contents & 1) == 0 )
        FloodAreas_r(node: portals->nodes[!v8], pSeeThrough: portals);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042A520
// Name: void FindAreas_r(struct node_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FindAreas_r(node_t *node)
{
  node_t *i; // esi
  int contents; // eax

  for ( i = node; i->planenum != -1; i = i->children[1] )
    FindAreas_r(node: i->children[0]);
  if ( i->area == 0 )
  {
    contents = i->contents;
    if ( (contents & 1) == 0 && i->occupied != 0 && (contents & 0x8000) == 0 )
    {
      ++c_areas;
      FloodAreas_r(node: i, pSeeThrough: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042A580
// Name: void ReportAreaportalLeak(struct tree_t __near *,struct node_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ReportAreaportalLeak(_iobuf *tree, portal_t *node)
{
  portal_t *dist_low; // esi
  node_t *v4; // eax
  BOOL v5; // edi
  BOOL v6; // edi
  node_t *ptr; // ecx
  node_t *v8; // esi
  int v9; // ecx
  portal_t *v10; // eax
  portal_t *v11; // esi
  int occupied; // edx
  node_t *v13; // [esp-8h] [ebp-10h]
  portal_t *pStart; // [esp+14h] [ebp+Ch]

  dist_low = (portal_t *)LODWORD(node[1].plane.dist);
  if ( dist_low != nullptr )
  {
    while ( 1 )
    {
      v4 = dist_low->nodes[1];
      v5 = v4 == (node_t *)node;
      if ( dist_low->nodes[0]->planenum != -1 || v4->planenum != -1 )
        _Error(a1: "Portal_EntityFlood: not a leaf");
      if ( (dist_low->nodes[0]->contents & 1) == 0
        && (dist_low->nodes[1]->contents & 1) == 0
        && (dist_low->nodes[!v5]->contents & 0x8000) == 0 )
      {
        break;
      }
      dist_low = dist_low->next[v5];
      if ( dist_low == nullptr )
        return;
    }
    pStart = dist_low;
    v6 = dist_low->nodes[0] == (node_t *)node;
    ptr = (node_t *)tree->_ptr;
    v8 = dist_low->nodes[v6];
    if ( tree->_ptr != nullptr )
    {
      v13 = ptr->children[0];
      ptr->occupied = 0;
      ClearOccupied_r(headnode: v13);
      ClearOccupied_r(headnode: *(node_t **)(v9 + 48));
    }
    FloodAreaLeak_r(node: v8, dist: 2);
    v10 = (portal_t *)LODWORD(node[1].plane.dist);
    v11 = nullptr;
    occupied = 0;
    if ( v10 != nullptr )
    {
      do
      {
        if ( v10 != pStart )
        {
          v6 = v10->nodes[1] == (node_t *)node;
          if ( v10->nodes[v10->nodes[1] != (node_t *)node]->occupied > occupied )
          {
            v11 = v10;
            occupied = v10->nodes[v10->nodes[1] != (node_t *)node]->occupied;
          }
        }
        v10 = v10->next[v6];
      }
      while ( v10 != nullptr );
      if ( v11 != nullptr )
        AreaportalLeakFile(
          tree,
          pStartPortal: pStart,
          pEndPortal: v11,
          pStart: v11->nodes[v11->nodes[0] == (node_t *)node]);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042A6A0
// Name: void SetAreaPortalAreas_r(struct tree_t __near *,struct node_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetAreaPortalAreas_r(tree_t *tree, node_t *node)
{
  node_t *i; // esi
  bspbrush_t *v3; // edi
  char *v4; // eax

  for ( i = node; i->planenum != -1; i = i->children[1] )
    SetAreaPortalAreas_r(tree, node: i->children[0]);
  if ( (i->contents & 0x8000) != 0 && i->area == 0 )
  {
    v3 = AreaportalBrushForNode(node: i);
    v4 = (char *)&entities + 44 * v3->original->entitynum;
    i->area = *((_DWORD *)v4 + 7);
    if ( *((_DWORD *)v4 + 8) == 0 )
    {
      ReportAreaportalLeak((_iobuf *)tree, node: (portal_t *)i);
      _Warning(a1: "\nBrush %i: areaportal brush doesn't touch two areas\n", v3->original->id);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042A720
// Name: int FindUniquePoints(class Vector2D const __near *,int,int __near *,int,float)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindUniquePoints(
        const Vector2D *pPoints,
        int nPoints,
        int *indexMap,
        int nMaxIndexMapPoints,
        float flTolerance)
{
  int v5; // ebx
  int v6; // edi
  float v7; // xmm0_4
  int v8; // eax
  float x; // xmm3_4
  float y; // xmm4_4
  int *v11; // ecx
  bool v12; // zf
  int v13; // edx
  float flToleranceSqr; // [esp+18h] [ebp+18h]

  v5 = 0;
  v6 = 0;
  v7 = flTolerance * flTolerance;
  flToleranceSqr = flTolerance * flTolerance;
  if ( nPoints > 0 )
  {
    while ( 1 )
    {
      v8 = 0;
      if ( v6 >= 4 )
        break;
LABEL_9:
      v12 = v8 == v6;
      if ( v8 < v6 )
      {
        do
        {
          v13 = indexMap[v8];
          if ( v7 > (float)((float)((float)(pPoints[v5].x - pPoints[v13].x) * (float)(pPoints[v5].x - pPoints[v13].x))
                          + (float)((float)(pPoints[v5].y - pPoints[v13].y) * (float)(pPoints[v5].y - pPoints[v13].y))) )
            break;
          ++v8;
        }
        while ( v8 < v6 );
LABEL_16:
        v12 = v8 == v6;
      }
      if ( v12 )
      {
        if ( v6 >= nMaxIndexMapPoints )
        {
          _Error(a1: "FindUniquePoints: overflowed unique point list (size %d).", nMaxIndexMapPoints);
          v7 = flToleranceSqr;
        }
        indexMap[v6++] = v5;
      }
      if ( ++v5 >= nPoints )
        return v6;
    }
    x = pPoints[v5].x;
    y = pPoints[v5].y;
    v11 = indexMap + 2;
    while ( v7 <= (float)((float)((float)(x - pPoints[*(v11 - 2)].x) * (float)(x - pPoints[*(v11 - 2)].x))
                        + (float)((float)(y - pPoints[*(v11 - 2)].y) * (float)(y - pPoints[*(v11 - 2)].y))) )
    {
      if ( v7 > (float)((float)((float)(x - pPoints[*(v11 - 1)].x) * (float)(x - pPoints[*(v11 - 1)].x))
                      + (float)((float)(y - pPoints[*(v11 - 1)].y) * (float)(y - pPoints[*(v11 - 1)].y))) )
      {
        ++v8;
        goto LABEL_16;
      }
      if ( v7 > (float)((float)((float)(x - pPoints[*v11].x) * (float)(x - pPoints[*v11].x))
                      + (float)((float)(y - pPoints[*v11].y) * (float)(y - pPoints[*v11].y))) )
      {
        v8 += 2;
        goto LABEL_16;
      }
      if ( v7 > (float)((float)((float)(x - pPoints[v11[1]].x) * (float)(x - pPoints[v11[1]].x))
                      + (float)((float)(y - pPoints[v11[1]].y) * (float)(y - pPoints[v11[1]].y))) )
      {
        v8 += 3;
        goto LABEL_16;
      }
      v8 += 4;
      v11 += 4;
      if ( v8 >= v6 - 3 )
        goto LABEL_9;
    }
    goto LABEL_16;
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x0042A8A0
// Name: int Convex2D(class Vector2D const __near *,int,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
int __usercall Convex2D@<eax>(double a1@<esi:edi>, const Vector2D *pPoints, int nPoints, int *indices, int nMaxIndices)
{
  int result; // eax
  int UniquePoints; // ebx
  float v7; // eax
  float v8; // ecx
  int v9; // edx
  int v10; // eax
  float x; // xmm0_4
  int *v12; // edi
  int v13; // eax
  float v14; // xmm1_4
  float v15; // xmm0_4
  const Vector2D *v16; // ebx
  int v17; // eax
  float v18; // xmm1_4
  int v19; // eax
  float v20; // xmm0_4
  const Vector2D *v21; // ebx
  int v22; // eax
  float v23; // xmm1_4
  int v24; // eax
  float v25; // xmm0_4
  const Vector2D *v26; // ebx
  int v27; // eax
  float v28; // xmm1_4
  int v29; // eax
  float v30; // xmm0_4
  const Vector2D *v31; // edi
  int v32; // eax
  float v33; // xmm1_4
  float v34; // xmm1_4
  int *v35; // eax
  int v36; // ecx
  int v37; // edi
  int v38; // ebx
  float v39; // xmm0_4
  long double v40; // st7
  float v41; // xmm1_4
  float v42; // xmm0_4
  int v43; // eax
  int *v44; // eax
  float y; // xmm1_4
  long double v46; // [esp+4h] [ebp-A38h]
  long double v47; // [esp+Ch] [ebp-A30h] OVERLAPPED
  int indexMap[512]; // [esp+210h] [ebp-82Ch] BYREF
  float flDistToSqr; // [esp+A10h] [ebp-2Ch]
  float v50; // [esp+A14h] [ebp-28h]
  float v51; // [esp+A18h] [ebp-24h]
  float v52; // [esp+A1Ch] [ebp-20h]
  int i; // [esp+A20h] [ebp-1Ch]
  int *v54; // [esp+A24h] [ebp-18h]
  int *v55; // [esp+A28h] [ebp-14h]
  float flAngle; // [esp+A2Ch] [ebp-10h]
  int flEdgeAngle; // [esp+A30h] [ebp-Ch]
  int nIndices; // [esp+A34h] [ebp-8h]
  float flMinAngle; // [esp+A38h] [ebp-4h]
  int nPointsa; // [esp+A48h] [ebp+Ch]

  result = nPoints;
  if ( nPoints != 0 )
  {
    v46 = a1;
    UniquePoints = FindUniquePoints(pPoints, nPoints, indexMap, nMaxIndexMapPoints: 512, flTolerance: 0.1);
    v7 = 0.0;
    LODWORD(v8) = 1;
    nPointsa = UniquePoints;
    flMinAngle = 0.0;
    if ( UniquePoints > 1 )
    {
      if ( UniquePoints - 1 >= 4 )
      {
        v55 = (int *)(12 - (_DWORD)&indexMap[2]);
        v9 = 0;
        flEdgeAngle = 8;
        i = 16 - (_DWORD)&indexMap[2];
        do
        {
          v10 = indexMap[LODWORD(v8)];
          x = pPoints[v10].x;
          v12 = &indexMap[LODWORD(v8) + 1];
          v54 = (int *)&pPoints[v10];
          v13 = *(int *)((char *)indexMap + v9);
          v14 = pPoints[v13].x;
          nIndices = (int)&pPoints[v13];
          if ( v14 > x || x == v14 && *(float *)(nIndices + 4) > *((float *)v54 + 1) )
          {
            flMinAngle = v8;
            v9 = 4 * LODWORD(v8);
          }
          v15 = pPoints[*v12].x;
          v16 = &pPoints[*v12];
          v17 = *(int *)((char *)indexMap + v9);
          v18 = pPoints[v17].x;
          nIndices = (int)&pPoints[v17];
          if ( v18 > v15 || v15 == v18 && *(float *)(nIndices + 4) > v16->y )
          {
            LODWORD(flMinAngle) = LODWORD(v8) + 1;
            v9 = flEdgeAngle;
          }
          v19 = v12[1];
          v20 = pPoints[v19].x;
          v21 = &pPoints[v19];
          v22 = *(int *)((char *)indexMap + v9);
          v23 = pPoints[v22].x;
          nIndices = (int)&pPoints[v22];
          if ( v23 > v20 || v20 == v23 && *(float *)(nIndices + 4) > v21->y )
          {
            LODWORD(flMinAngle) = LODWORD(v8) + 2;
            v9 = (int)v55 + (_DWORD)v12;
          }
          v24 = v12[2];
          v25 = pPoints[v24].x;
          v26 = &pPoints[v24];
          v27 = *(int *)((char *)indexMap + v9);
          v28 = pPoints[v27].x;
          nIndices = (int)&pPoints[v27];
          if ( v28 > v25 || v25 == v28 && *(float *)(nIndices + 4) > v26->y )
          {
            LODWORD(flMinAngle) = LODWORD(v8) + 3;
            v9 = (int)v12 + i;
          }
          flEdgeAngle += 16;
          LODWORD(v8) += 4;
        }
        while ( SLODWORD(v8) < nPointsa - 3 );
        UniquePoints = nPointsa;
        v7 = flMinAngle;
      }
      if ( SLODWORD(v8) < UniquePoints )
      {
        flEdgeAngle = 4 * LODWORD(v7);
        do
        {
          v29 = indexMap[LODWORD(v8)];
          v30 = pPoints[v29].x;
          v31 = &pPoints[v29];
          v32 = *(int *)((char *)indexMap + flEdgeAngle);
          v33 = pPoints[v32].x;
          if ( v33 > v30 || v30 == v33 && pPoints[v32].y > v31->y )
          {
            flMinAngle = v8;
            flEdgeAngle = 4 * LODWORD(v8);
          }
          ++LODWORD(v8);
        }
        while ( SLODWORD(v8) < nPointsa );
        UniquePoints = nPointsa;
        v7 = flMinAngle;
      }
    }
    v34 = 1.0;
    *indices = indexMap[LODWORD(v7)];
    *((_BYTE *)indexMap + LODWORD(v7) + 504) = 1;
    nIndices = 1;
    v35 = indices;
    v54 = indices + 1;
    v55 = indices - 1;
LABEL_32:
    LODWORD(flAngle) = &pPoints[*v35];
    __libm_sse2_atan2(y: v46, x: v47);
    v36 = 0;
    *(float *)&flEdgeAngle = v34;
    v37 = -1;
    flMinAngle = 5000.0;
    i = 0;
    if ( UniquePoints > 0 )
    {
      v52 = *(float *)LODWORD(flAngle);
      v51 = *(float *)(LODWORD(flAngle) + 4);
      while ( 1 )
      {
        v38 = indexMap[v36];
        v39 = pPoints[v38].y - v51;
        flDistToSqr = (float)(v39 * v39) + (float)((float)(pPoints[v38].x - v52) * (float)(pPoints[v38].x - v52));
        if ( flDistToSqr > 0.1 )
        {
          __libm_sse2_atan2(y: v46, x: v47);
          v50 = v39;
          if ( v39 > *(float *)&flEdgeAngle )
          {
            do
              v39 = v39 - 6.283185307179586;
            while ( v39 > *(float *)&flEdgeAngle );
            v50 = v39;
          }
          v40 = fmod(*(float *)&flEdgeAngle - v50, 6.283185482025146);
          flAngle = v40;
          if ( fabs(v40 - flMinAngle) < 0.0000099999997 )
          {
            if ( v37 == *indices )
              goto LABEL_44;
            v41 = v51 - pPoints[v37].y;
            if ( flDistToSqr <= (float)((float)(v41 * v41)
                                      + (float)((float)(v52 - pPoints[v37].x) * (float)(v52 - pPoints[v37].x))) )
              goto LABEL_44;
            v42 = flAngle;
LABEL_43:
            v37 = v38;
            flMinAngle = v42;
            goto LABEL_44;
          }
          v42 = flAngle;
          if ( flMinAngle > flAngle )
            goto LABEL_43;
        }
LABEL_44:
        v36 = i + 1;
        i = v36;
        if ( v36 >= nPointsa )
        {
          if ( v37 != -1 && v37 != *indices && nIndices < nMaxIndices )
          {
            v43 = nIndices;
            UniquePoints = nPointsa;
            *v54 = v37;
            nIndices = v43 + 1;
            v44 = &indices[v43 + 1];
            y = pPoints[*(v44 - 1)].y;
            v54 = v44;
            v35 = v44 - 1;
            v34 = y - pPoints[*++v55].y;
            goto LABEL_32;
          }
          return nIndices;
        }
      }
    }
    return nIndices;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042ACD0
// Name: void SetNodeAreaIndices_R(struct node_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetNodeAreaIndices_R(node_t *node)
{
  int area; // eax

  if ( node->planenum != -1 )
  {
    SetNodeAreaIndices_R(node: node->children[0]);
    SetNodeAreaIndices_R(node: node->children[1]);
    area = node->children[0]->area;
    if ( area == node->children[1]->area )
      node->area = area;
    else
      node->area = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042AD10
// Name: void FloodAreas(struct tree_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FloodAreas(tree_t *tree)
{
  double v1; // st7
  int start; // [esp+8h] [ebp-4h]

  start = (int)_Plat_FloatTime();
  qprintf(format: "--- FloodAreas ---\n");
  _Msg(a1: "Processing areas...");
  FindAreas_r(node: tree->headnode);
  SetAreaPortalAreas_r(tree, node: tree->headnode);
  qprintf(format: "%5i areas\n", c_areas);
  v1 = _Plat_FloatTime() - (double)start;
  _Msg(a1: "done (%d)\n", (int)v1);
}

//------------------------------------------------------------------------------
// Address: 0x0042AD80
// Name: void FillOutside_r(struct node_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FillOutside_r(node_t *node)
{
  node_t *i; // esi

  for ( i = node; i->planenum != -1; i = i->children[1] )
    FillOutside_r(node: i->children[0]);
  if ( i->occupied != 0 )
  {
    ++c_inside;
  }
  else if ( i->contents == 1 )
  {
    ++c_solid;
  }
  else
  {
    ++c_outside;
    i->contents = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042ADE0
// Name: void FillOutside(struct node_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FillOutside(node_t *headnode)
{
  c_outside = 0;
  c_inside = 0;
  c_solid = 0;
  qprintf(format: "--- FillOutside ---\n");
  FillOutside_r(node: headnode);
  qprintf(format: "%5i solid leafs\n", c_solid);
  qprintf(format: "%5i leafs filled\n", c_outside);
  qprintf(format: "%5i inside leafs\n", c_inside);
}

//------------------------------------------------------------------------------
// Address: 0x0042AE40
// Name: protected: virtual void CFmtStrN<256>::InitQuietTruncation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFmtStrN<256>::InitQuietTruncation(CFmtStrN<256> *this)
{
  this->m_bQuietTruncation = true;
}

//------------------------------------------------------------------------------
// Address: 0x0042AE50
// Name: void MakeNodePortal(struct node_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MakeNodePortal(winding_t *node)
{
  winding_t *v1; // edi
  int v2; // ebx
  winding_t *v3; // eax
  Vector *p; // esi
  float y; // xmm0_4
  unsigned __int8 *v6; // esi
  int v7; // eax
  Vector *v8; // eax
  bool v9; // zf
  int numpoints; // ebx
  winding_t *next; // edi
  Vector normal; // [esp+14h] [ebp-10h] BYREF
  float dist; // [esp+20h] [ebp-4h]

  v1 = node;
  dist = 0.0;
  v2 = 0;
  v3 = BaseWindingForNode(node);
  p = v1[5].p;
  node = v3;
  if ( p != nullptr )
  {
    while ( v3 != nullptr )
    {
      if ( (winding_t *)LODWORD(p[2].z) == v1 )
      {
        normal = *(Vector *)&p->y;
        y = p[1].y;
        v2 = 0;
        dist = y;
      }
      else if ( (winding_t *)LODWORD(p[3].x) == v1 )
      {
        normal.x = vec3_origin.x - p->y;
        normal.y = vec3_origin.y - p->z;
        normal.z = vec3_origin.z - p[1].x;
        LODWORD(y) = LODWORD(p[1].y) ^ _mask__NegFloat_;
        v2 = 1;
        dist = y;
      }
      else
      {
        _Error(a1: "CutNodePortals_r: mislinked portal");
        y = dist;
      }
      ChopWindingInPlace(inout: &node, &normal, dist: y, epsilon: 0.1);
      p = *((Vector **)&p[3].y + v2);
      v3 = node;
      if ( p == nullptr )
        goto LABEL_9;
    }
  }
  else
  {
LABEL_9:
    if ( v3 != nullptr )
    {
      if ( WindingIsTiny(w: v3) != 0 )
      {
        ++c_tinyportals;
        FreeWinding(w: node);
      }
      else
      {
        if ( numthreads == 1 )
          ++c_active_portals;
        if ( c_active_portals > c_peak_portals )
          c_peak_portals = c_active_portals;
        v6 = (unsigned __int8 *)MemAlloc_Alloc(nSize: 0x44u);
        memset(dst: v6, value: 0, count: 0x44u);
        v7 = dword_337E520;
        *(_DWORD *)v6 = dword_337E520;
        dword_337E520 = v7 + 1;
        v8 = &mapplanes + 2 * (int)v1->p;
        *((float *)v6 + 1) = v8->x;
        *((float *)v6 + 2) = v8->y;
        *((float *)v6 + 3) = v8->z;
        *((float *)v6 + 4) = v8[1].x;
        *((_DWORD *)v6 + 5) = LODWORD(v8[1].y);
        *((_DWORD *)v6 + 6) = LODWORD(v8[1].z);
        v9 = *((_DWORD *)v6 + 8) == 0;
        *((_DWORD *)v6 + 7) = v1;
        *((_DWORD *)v6 + 12) = node;
        numpoints = v1[3].numpoints;
        next = v1[2].next;
        if ( !v9 || *((_DWORD *)v6 + 9) != 0 )
          _Error(a1: "AddPortalToNode: allready included");
        *((_DWORD *)v6 + 8) = next;
        *((_DWORD *)v6 + 10) = next[5].p;
        next[5].p = (Vector *)v6;
        *((_DWORD *)v6 + 9) = numpoints;
        *((_DWORD *)v6 + 11) = *(_DWORD *)(numpoints + 84);
        *(_DWORD *)(numpoints + 84) = v6;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042B050
// Name: public: struct portal_t __near & portal_t::operator=(struct portal_t const __near &)
// Source: json
//------------------------------------------------------------------------------
portal_t *__thiscall portal_t::operator=(portal_t *this, const portal_t *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0042B0C0
// Name: public: CFmtStrN<256>::CFmtStrN<256>(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
CFmtStrN<256> *CFmtStrN<256>::CFmtStrN<256>(CFmtStrN<256> *this, const char *pszFormat, ...)
{
  CFmtStrN<256> *v2; // esi
  char *m_szBuf; // edi
  bool v4; // zf
  char *v6; // [esp-14h] [ebp-1Ch]
  const char *v7; // [esp-Ch] [ebp-14h]
  va_list params; // [esp+18h] [ebp+10h] BYREF

  va_start(params, pszFormat);
  v2 = this;
  v7 = pszFormat;
  m_szBuf = this->m_szBuf;
  v6 = this->m_szBuf;
  this->__vftable = (CFmtStrN<256>_vtbl *)&CFmtStrN<256>::`vftable';
  v2->m_bQuietTruncation = true;
  HIBYTE(this) = 0;
  V_vsnprintfRet(pDest: v6, maxLen: 255, pFormat: v7, params, pbTruncated: (bool *)&this + 3);
  v4 = HIBYTE(this) == 0;
  v2->m_szBuf[255] = 0;
  if ( !v4 && !v2->m_bQuietTruncation && `CFmtStrN<256>::CFmtStrN<256>'::`4'::scAsserted < 5 )
    ++`CFmtStrN<256>::CFmtStrN<256>'::`4'::scAsserted;
  v2->m_nLength = _V_strlen(str: m_szBuf);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x0042B130
// Name: void MakeHeadnodePortals(struct tree_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MakeHeadnodePortals(tree_t *tree)
{
  float x; // xmm1_4
  node_t *headnode; // ecx
  int v4; // ebx
  float z; // xmm1_4
  int v6; // edi
  unsigned __int8 *v7; // esi
  int v8; // eax
  plane_t *v9; // eax
  double v10; // st7
  winding_t *v11; // eax
  bool v12; // zf
  node_t *v13; // eax
  node_t *v14; // eax
  int v15; // esi
  plane_t *v16; // edi
  portal_t *portals[6]; // [esp+14h] [ebp-C8h]
  plane_t bplanes[6]; // [esp+2Ch] [ebp-B0h] BYREF
  Vector bounds[2]; // [esp+BCh] [ebp-20h]
  node_t *p_outside_node; // [esp+D4h] [ebp-8h]
  node_t *node; // [esp+D8h] [ebp-4h]
  int i; // [esp+E4h] [ebp+8h]

  x = tree->mins.x;
  headnode = tree->headnode;
  memset(bplanes, 0, 12);
  memset(&bplanes[1], 0, 12);
  memset(&bplanes[2], 0, 12);
  memset(&bplanes[3], 0, 12);
  memset(&bplanes[4], 0, 12);
  memset(&bplanes[5], 0, 12);
  bounds[0].x = x - 8.0;
  bounds[1].x = tree->maxs.x + 8.0;
  bounds[0].y = tree->mins.y - 8.0;
  bounds[1].y = tree->maxs.y + 8.0;
  v4 = 0;
  bounds[0].z = tree->mins.z - 8.0;
  z = tree->maxs.z;
  tree->outside_node.planenum = -1;
  tree->outside_node.brushlist = nullptr;
  tree->outside_node.portals = nullptr;
  tree->outside_node.contents = 0;
  node = headnode;
  bounds[1].z = z + 8.0;
  i = 0;
  p_outside_node = &tree->outside_node;
  while ( 1 )
  {
    v6 = v4 + i + 2 * v4;
    if ( numthreads == 1 )
      ++c_active_portals;
    if ( c_active_portals > c_peak_portals )
      c_peak_portals = c_active_portals;
    v7 = (unsigned __int8 *)MemAlloc_Alloc(nSize: 0x44u);
    memset(dst: v7, value: 0, count: 0x44u);
    v8 = dword_337E520;
    *(_DWORD *)v7 = dword_337E520;
    dword_337E520 = v8 + 1;
    v9 = &bplanes[v6];
    *(_QWORD *)&v9->normal.x = 0;
    *(_QWORD *)&v9->normal.z = 0;
    portals[v6] = (portal_t *)v7;
    *(_QWORD *)&v9->type = 0;
    if ( v4 != 0 )
    {
      *((_DWORD *)&v9->normal.x + i) = -1082130432;
      LODWORD(v9->dist) = *((_DWORD *)&bounds[0].x + v6) ^ _mask__NegFloat_;
    }
    else
    {
      v10 = *(&bounds[0].x + i);
      *((_DWORD *)&v9->normal.x + i) = 1065353216;
      v9->dist = v10;
    }
    *((float *)v7 + 1) = v9->normal.x;
    *((float *)v7 + 2) = v9->normal.y;
    *((float *)v7 + 3) = v9->normal.z;
    *((float *)v7 + 4) = v9->dist;
    *((_DWORD *)v7 + 5) = v9->type;
    *((_DWORD *)v7 + 6) = v9->hash_chain;
    v11 = BaseWindingForPlane(normal: &bplanes[v6].normal, dist: v9->dist);
    v12 = *((_DWORD *)v7 + 8) == 0;
    *((_DWORD *)v7 + 12) = v11;
    if ( !v12 || *((_DWORD *)v7 + 9) != 0 )
      _Error(a1: "AddPortalToNode: allready included");
    v13 = node;
    *((_DWORD *)v7 + 8) = node;
    *((_DWORD *)v7 + 10) = v13->portals;
    v13->portals = (portal_t *)v7;
    v14 = p_outside_node;
    *((_DWORD *)v7 + 9) = p_outside_node;
    ++v4;
    *((_DWORD *)v7 + 11) = v14->portals;
    v14->portals = (portal_t *)v7;
    if ( v4 >= 2 )
    {
      v4 = 0;
      if ( ++i >= 3 )
        break;
    }
  }
  do
  {
    v15 = 0;
    v16 = bplanes;
    do
    {
      if ( v15 != v4 )
        ChopWindingInPlace(inout: &portals[v4]->winding, normal: &v16->normal, dist: v16->dist, epsilon: 0.1);
      ++v15;
      ++v16;
    }
    while ( v15 < 6 );
    ++v4;
  }
  while ( v4 < 6 );
}

//------------------------------------------------------------------------------
// Address: 0x0042B3D0
// Name: void SplitNodePortals(struct node_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SplitNodePortals(node_t *node)
{
  node_t *v1; // ecx
  portal_t *portals; // esi
  Vector *v3; // edx
  node_t *v4; // eax
  node_t *v5; // edi
  node_t *v6; // ebx
  winding_t *v7; // eax
  bool v8; // zf
  unsigned __int8 *v9; // edi
  int v10; // eax
  portal_t *next_portal; // [esp+1Ch] [ebp-1Ch]
  plane_t *plane; // [esp+20h] [ebp-18h]
  node_t *f; // [esp+24h] [ebp-14h]
  node_t *b; // [esp+28h] [ebp-10h]
  winding_t *frontwinding; // [esp+2Ch] [ebp-Ch] BYREF
  winding_t *backwinding; // [esp+30h] [ebp-8h] BYREF
  int side; // [esp+34h] [ebp-4h]

  v1 = node;
  portals = node->portals;
  v3 = &mapplanes + 2 * node->planenum;
  v4 = node->children[1];
  v5 = node->children[0];
  side = 0;
  plane = (plane_t *)v3;
  f = v5;
  b = v4;
  if ( portals != nullptr )
  {
    while ( 1 )
    {
      if ( portals->nodes[0] == v1 )
      {
        side = 0;
      }
      else if ( portals->nodes[1] == v1 )
      {
        side = 1;
      }
      else
      {
        _Error(a1: "CutNodePortals_r: mislinked portal");
      }
      next_portal = portals->next[side];
      v6 = portals->nodes[side == 0];
      RemovePortalFromNode(portal: portals, l: portals->nodes[0]);
      RemovePortalFromNode(portal: portals, l: portals->nodes[1]);
      ClipWindingEpsilon(
        in: portals->winding,
        normal: &plane->normal,
        dist: plane->dist,
        epsilon: 0.001,
        front: &frontwinding,
        back: &backwinding);
      if ( frontwinding != nullptr && WindingIsTiny(w: frontwinding) != 0 )
      {
        FreeWinding(w: frontwinding);
        ++c_tinyportals;
        frontwinding = nullptr;
      }
      v7 = backwinding;
      if ( backwinding != nullptr )
      {
        v8 = WindingIsTiny(w: backwinding) == 0;
        v7 = backwinding;
        if ( !v8 )
        {
          FreeWinding(w: backwinding);
          v7 = nullptr;
          ++c_tinyportals;
          backwinding = nullptr;
        }
      }
      if ( frontwinding != nullptr )
      {
        if ( v7 != nullptr )
        {
          if ( numthreads == 1 )
            ++c_active_portals;
          if ( c_active_portals > c_peak_portals )
            c_peak_portals = c_active_portals;
          v9 = (unsigned __int8 *)MemAlloc_Alloc(nSize: 0x44u);
          memset(dst: v9, value: 0, count: 0x44u);
          v10 = dword_337E520;
          *(_DWORD *)v9 = dword_337E520;
          dword_337E520 = v10 + 1;
          portal_t::operator=(this: (portal_t *)v9, __that: portals);
          *((_DWORD *)v9 + 12) = backwinding;
          FreeWinding(w: portals->winding);
          v8 = side == 0;
          portals->winding = frontwinding;
          if ( v8 )
          {
            if ( portals->nodes[0] != nullptr || portals->nodes[1] != nullptr )
              _Error(a1: "AddPortalToNode: allready included");
            portals->nodes[0] = f;
            portals->next[0] = f->portals;
            f->portals = portals;
            portals->nodes[1] = v6;
            portals->next[1] = v6->portals;
            v6->portals = portals;
            if ( *((_DWORD *)v9 + 8) != 0 || *((_DWORD *)v9 + 9) != 0 )
              _Error(a1: "AddPortalToNode: allready included");
            *((_DWORD *)v9 + 8) = b;
            *((_DWORD *)v9 + 10) = b->portals;
            b->portals = (portal_t *)v9;
            *((_DWORD *)v9 + 9) = v6;
            *((_DWORD *)v9 + 11) = v6->portals;
            v6->portals = (portal_t *)v9;
          }
          else
          {
            if ( portals->nodes[0] != nullptr || portals->nodes[1] != nullptr )
              _Error(a1: "AddPortalToNode: allready included");
            portals->nodes[0] = v6;
            portals->next[0] = v6->portals;
            v6->portals = portals;
            portals->nodes[1] = f;
            portals->next[1] = f->portals;
            f->portals = portals;
            if ( *((_DWORD *)v9 + 8) != 0 || *((_DWORD *)v9 + 9) != 0 )
              _Error(a1: "AddPortalToNode: allready included");
            *((_DWORD *)v9 + 8) = v6;
            *((_DWORD *)v9 + 10) = v6->portals;
            v6->portals = (portal_t *)v9;
            *((_DWORD *)v9 + 9) = b;
            *((_DWORD *)v9 + 11) = b->portals;
            b->portals = (portal_t *)v9;
          }
          v5 = f;
        }
        else
        {
          FreeWinding(w: frontwinding);
          if ( side != 0 )
          {
            if ( portals->nodes[0] != nullptr || portals->nodes[1] != nullptr )
              _Error(a1: "AddPortalToNode: allready included");
            portals->nodes[0] = v6;
            portals->next[0] = v6->portals;
            v6->portals = portals;
            portals->nodes[1] = v5;
            portals->next[1] = v5->portals;
            v5->portals = portals;
          }
          else
          {
            if ( portals->nodes[0] != nullptr || portals->nodes[1] != nullptr )
              _Error(a1: "AddPortalToNode: allready included");
            portals->nodes[0] = v5;
            portals->next[0] = v5->portals;
            v5->portals = portals;
            portals->nodes[1] = v6;
            portals->next[1] = v6->portals;
            v6->portals = portals;
          }
        }
      }
      else if ( v7 != nullptr )
      {
        FreeWinding(w: v7);
        if ( side != 0 )
        {
          if ( portals->nodes[0] != nullptr || portals->nodes[1] != nullptr )
            _Error(a1: "AddPortalToNode: allready included");
          portals->nodes[0] = v6;
          portals->next[0] = v6->portals;
          v6->portals = portals;
          portals->nodes[1] = b;
          portals->next[1] = b->portals;
          b->portals = portals;
        }
        else
        {
          if ( portals->nodes[0] != nullptr || portals->nodes[1] != nullptr )
            _Error(a1: "AddPortalToNode: allready included");
          portals->nodes[0] = b;
          portals->next[0] = b->portals;
          b->portals = portals;
          portals->nodes[1] = v6;
          portals->next[1] = v6->portals;
          v6->portals = portals;
        }
      }
      portals = next_portal;
      if ( next_portal == nullptr )
        break;
      v1 = node;
    }
    node->portals = nullptr;
  }
  else
  {
    node->portals = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042B770
// Name: void MakeTreePortals_r(struct node_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MakeTreePortals_r(node_t *node)
{
  int v2; // eax
  Vector *p_maxs; // ecx
  side_t *side; // eax
  const char *String; // esi
  dtexdata_t *TexData; // eax
  Vector *p; // eax
  __int64 v8; // xmm0_8
  float z; // eax
  CFmtStrN<256> *v10; // eax
  CFmtStrN<256> v11; // [esp+24h] [ebp-118h] BYREF
  Vector point; // [esp+130h] [ebp-Ch]

  while ( 1 )
  {
    CalcNodeBounds(node);
    if ( node->mins.x >= node->maxs.x )
      _Warning(a1: "WARNING: node without a volume\n");
    v2 = 0;
    p_maxs = &node->maxs;
    while ( p_maxs[-1].x >= -16392.0 && p_maxs->x <= 16392.0 )
    {
      ++v2;
      p_maxs = (Vector *)((char *)p_maxs + 4);
      if ( v2 >= 3 )
        goto LABEL_11;
    }
    side = node->side;
    String = "<NO BRUSH>";
    if ( side != nullptr )
    {
      TexData = GetTexData(index: texinfo.m_Memory.m_pMemory[side->texinfo].texdata);
      String = TexDataStringTable_GetString(stringID: TexData->nameStringTableID);
    }
    p = node->portals->winding->p;
    v8 = *(_QWORD *)&p->x;
    z = p->z;
    *(_QWORD *)&point.x = v8;
    point.z = z;
    v10 = CFmtStrN<256>::CFmtStrN<256>(this: &v11, pszFormat: "(%f, %f, %f)", *(float *)&v8, *((float *)&v8 + 1), z);
    _Warning(a1: "WARNING: BSP node with unbounded volume (material: %s, near %s)\n", String, v10->m_szBuf);
LABEL_11:
    if ( node->planenum == -1 )
      break;
    MakeNodePortal((winding_t *)node);
    SplitNodePortals(node);
    MakeTreePortals_r(node: node->children[0]);
    node = node->children[1];
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042B8A0
// Name: void MakeTreePortals(struct tree_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MakeTreePortals(tree_t *tree)
{
  MakeHeadnodePortals(tree);
  MakeTreePortals_r(node: tree->headnode);
}

//------------------------------------------------------------------------------
// Address: 0x0042B930
// Name: void FindPortalsLeadingToArea_R(struct node_t __near *,int,int,struct plane_t __near *,class CUtlVector<struct portal_t __near *,class CUtlMemory<struct portal_t __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FindPortalsLeadingToArea_R(
        portal_t *pHeadNode,
        int iSrcArea,
        int iDestArea,
        plane_t *pPlane,
        CUtlVector<portal_t *,CUtlMemory<portal_t *,int> > *portals)
{
  node_t *v5; // ebx
  portal_t *v6; // edx
  node_t *v7; // eax
  node_t *v8; // ecx
  int area; // ecx
  float v10; // xmm5_4
  float v11; // xmm4_4
  float v12; // xmm6_4
  float dist; // xmm0_4
  float v14; // xmm3_4
  int m_Size; // edi
  int m_nAllocationCount; // eax
  portal_t **m_pMemory; // ecx
  int v18; // eax
  portal_t **v19; // edi
  BOOL s; // [esp+Ch] [ebp-8h]
  portal_t *p; // [esp+1Ch] [ebp+8h]

  v5 = (node_t *)pHeadNode;
  if ( LODWORD(pHeadNode->plane.normal.x) != -1 )
  {
    do
    {
      FindPortalsLeadingToArea_R(pHeadNode: v5->children[0], iSrcArea, iDestArea, pPlane, portals);
      v5 = v5->children[1];
    }
    while ( v5->planenum != -1 );
  }
  v6 = v5->portals;
  p = v6;
  if ( v6 != nullptr )
  {
    while ( 1 )
    {
      v7 = v6->nodes[0];
      s = v7 == v5;
      if ( v7->occupied != 0 )
      {
        v8 = v6->nodes[1];
        if ( v8->occupied != 0
          && ((area = v8->area) == iDestArea && v7->area == iSrcArea || v7->area == iDestArea && area == iSrcArea) )
        {
          v11 = *(&mapplanes.y + 6 * v6->onnode->planenum);
          v12 = *(&mapplanes.z + 6 * v6->onnode->planenum);
          if ( COERCE_FLOAT(
                 COERCE_UNSIGNED_INT(
                   1.0
                 - COERCE_FLOAT(
                     COERCE_UNSIGNED_INT(
                       (float)((float)(*(&mapplanes.x + 6 * v6->onnode->planenum) * pPlane->normal.x)
                             + (float)(pPlane->normal.y * v11))
                     + (float)(pPlane->normal.z * v12))
                   & _mask__AbsFloat_))
               & _mask__AbsFloat_) < 0.0099999998 )
          {
            dist = pPlane->dist;
            v14 = *((float *)&mapplanes + 6 * v6->onnode->planenum + 3);
            v10 = *(&mapplanes.x + 6 * v6->onnode->planenum);
            if ( (float)((float)((float)((float)((float)(pPlane->normal.y * dist) - (float)(v11 * v14))
                                       * (float)((float)(pPlane->normal.y * dist) - (float)(v11 * v14)))
                               + (float)((float)((float)(pPlane->normal.x * dist) - (float)(v10 * v14))
                                       * (float)((float)(pPlane->normal.x * dist) - (float)(v10 * v14))))
                       + (float)((float)((float)(dist * pPlane->normal.z) - (float)(v12 * v14))
                               * (float)((float)(dist * pPlane->normal.z) - (float)(v12 * v14)))) < 0.0099999998 )
            {
              m_Size = portals->m_Size;
              m_nAllocationCount = portals->m_Memory.m_nAllocationCount;
              if ( m_Size + 1 > m_nAllocationCount )
              {
                CUtlMemory<HemiLightData_t *,int>::Grow(
                  this: (CUtlMemory<S3RGBA,int> *)portals,
                  num: m_Size - m_nAllocationCount + 1);
                v6 = p;
              }
              ++portals->m_Size;
              m_pMemory = portals->m_Memory.m_pMemory;
              v18 = portals->m_Size - m_Size - 1;
              portals->m_pElements = portals->m_Memory.m_pMemory;
              if ( v18 > 0 )
              {
                _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v18);
                v6 = p;
              }
              v19 = &portals->m_Memory.m_pMemory[m_Size];
              if ( v19 != nullptr )
                *v19 = v6;
            }
          }
        }
      }
      p = v6->next[!s];
      if ( p == nullptr )
        break;
      v6 = v6->next[!s];
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042BB10
// Name: void EmitClipPortalGeometry(struct node_t __near *,struct portal_t __near *,int,struct dareaportal_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EmitClipPortalGeometry(node_t *pHeadNode, portal_t *pPortal, int iSrcArea, dareaportal_t *dp)
{
  double v4; // rdi
  int m_Size; // ebx
  int v6; // eax
  winding_t *winding; // edx
  char *v8; // ecx
  int v9; // eax
  Vector2D *m_pMemory; // ecx
  float *v11; // edx
  float y; // xmm3_4
  float z; // xmm4_4
  int v14; // ebx
  float *p_x; // ebx
  bool v16; // zf
  int v17; // eax
  int v18; // ebx
  int v19; // eax
  int v20; // ecx
  int v21; // ebx
  float *v22; // edx
  int v23; // eax
  double v24; // st7
  int v25; // edx
  double v26; // st7
  int v27; // edx
  double v28; // st7
  int v29; // edx
  double v30; // st7
  int v31; // edx
  double v32; // st7
  int v33; // edx
  double v34; // st7
  int v35; // edx
  Vector *v36; // edi
  double v37; // st7
  float *v38; // edx
  Vector *v39; // ebx
  double v40; // st7
  portal_t **v41; // eax
  int otherarea; // [esp+Ch] [ebp-924h]
  _DWORD v43[3]; // [esp+18h] [ebp-918h]
  int indices[512]; // [esp+24h] [ebp-90Ch] BYREF
  VMatrix mInvTransform; // [esp+824h] [ebp-10Ch] BYREF
  QAngle vAngles; // [esp+864h] [ebp-CCh] BYREF
  VMatrix mTransform; // [esp+870h] [ebp-C0h] BYREF
  Vector vecs[3]; // [esp+8B0h] [ebp-80h] BYREF
  Vector vTest; // [esp+8D4h] [ebp-5Ch]
  CUtlVector<Vector,CUtlMemory<Vector,int> > points; // [esp+8E0h] [ebp-50h] BYREF
  char *v51; // [esp+8F4h] [ebp-3Ch]
  CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > points2D; // [esp+8F8h] [ebp-38h] BYREF
  winding_t *pWinding; // [esp+90Ch] [ebp-24h]
  int i; // [esp+910h] [ebp-20h]
  CUtlVector<portal_t *,CUtlMemory<portal_t *,int> > portals; // [esp+914h] [ebp-1Ch] BYREF
  int v56; // [esp+928h] [ebp-8h]
  int iPortal; // [esp+92Ch] [ebp-4h]

  otherarea = dp->otherarea;
  v4 = 0.0;
  memset(&portals, 0, sizeof(portals));
  FindPortalsLeadingToArea_R((portal_t *)pHeadNode, iSrcArea, iDestArea: otherarea, pPlane: &pPortal->plane, &portals);
  m_Size = 0;
  v6 = 0;
  memset(&points, 0, sizeof(points));
  iPortal = 0;
  if ( portals.m_Size > 0 )
  {
    do
    {
      winding = portals.m_Memory.m_pMemory[v6]->winding;
      pWinding = winding;
      i = 0;
      if ( winding->numpoints > 0 )
      {
        v56 = 0;
        do
        {
          v8 = (char *)winding->p + v56;
          v51 = v8;
          LODWORD(v4) = m_Size;
          if ( m_Size + 1 > points.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>::Grow(
              this: (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)&points,
              num: m_Size - points.m_Memory.m_nAllocationCount + 1);
            m_Size = points.m_Size;
            HIDWORD(v4) = points.m_Memory.m_pMemory;
            v8 = v51;
            winding = pWinding;
          }
          points.m_Size = ++m_Size;
          points.m_pElements = (Vector *)HIDWORD(v4);
          if ( m_Size - LODWORD(v4) - 1 > 0 )
          {
            _V_memmove(
              dest: (void *)(HIDWORD(v4) + 12 * LODWORD(v4) + 12),
              src: (const void *)(HIDWORD(v4) + 12 * LODWORD(v4)),
              count: 12 * (m_Size - LODWORD(v4) - 1));
            v8 = v51;
            winding = pWinding;
          }
          v9 = HIDWORD(v4) + 12 * LODWORD(v4);
          if ( v9 != 0 )
          {
            *(_QWORD *)v9 = *(_QWORD *)v8;
            *(_DWORD *)(v9 + 8) = *((_DWORD *)v8 + 2);
          }
          v56 += 12;
          ++i;
        }
        while ( i < winding->numpoints );
        v6 = iPortal;
        LODWORD(v4) = 0;
      }
      iPortal = ++v6;
    }
    while ( v6 < portals.m_Size );
  }
  VectorAngles(forward: &pPortal->plane.normal, angles: &vAngles);
  AngleVectors(angles: &vAngles, forward: vecs, right: &vecs[1], up: &vecs[2]);
  MatrixSetIdentity(dst: &mTransform);
  *(_QWORD *)&mTransform.m[0][0] = __PAIR64__(LODWORD(vecs[1].x), LODWORD(vecs[0].x));
  *(_QWORD *)&mTransform.m[1][0] = __PAIR64__(LODWORD(vecs[1].y), LODWORD(vecs[0].y));
  *(_QWORD *)&mTransform.m[2][0] = __PAIR64__(LODWORD(vecs[1].z), LODWORD(vecs[0].z));
  mTransform.m[0][2] = vecs[2].x;
  mTransform.m[1][2] = vecs[2].y;
  mTransform.m[2][2] = vecs[2].z;
  VMatrix::Transpose(this: &mTransform, result: &mInvTransform);
  m_pMemory = nullptr;
  memset(&points2D, 0, sizeof(points2D));
  if ( m_Size > 0 )
  {
    v11 = (float *)(HIDWORD(v4) + 8);
    v56 = HIDWORD(v4) + 8;
    iPortal = m_Size;
    do
    {
      y = (float)((float)((float)(mTransform.m[1][0] * *(v11 - 2)) + (float)(mTransform.m[1][1] * *(v11 - 1)))
                + (float)(mTransform.m[1][2] * *v11))
        + mTransform.m[1][3];
      z = (float)((float)((float)(mTransform.m[2][0] * *(v11 - 2)) + (float)(mTransform.m[2][1] * *(v11 - 1)))
                + (float)(mTransform.m[2][2] * *v11))
        + mTransform.m[2][3];
      vTest.y = y;
      vTest.z = z;
      v14 = LODWORD(v4);
      if ( LODWORD(v4) + 1 > points2D.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CacheOptimizedKDNode,int>::Grow(
          this: (CUtlMemory<ResourceEntryInfo,int> *)&points2D,
          num: LODWORD(v4) - points2D.m_Memory.m_nAllocationCount + 1);
        LODWORD(v4) = points2D.m_Size;
        z = vTest.z;
        y = vTest.y;
        v11 = (float *)v56;
        m_pMemory = points2D.m_Memory.m_pMemory;
      }
      points2D.m_Size = ++LODWORD(v4);
      points2D.m_pElements = m_pMemory;
      if ( LODWORD(v4) - v14 - 1 > 0 )
      {
        _V_memmove(dest: &m_pMemory[v14 + 1], src: &m_pMemory[v14], count: 8 * (LODWORD(v4) - v14 - 1));
        z = vTest.z;
        y = vTest.y;
        v11 = (float *)v56;
        m_pMemory = points2D.m_Memory.m_pMemory;
      }
      p_x = &m_pMemory[v14].x;
      if ( p_x != nullptr )
      {
        *p_x = y;
        p_x[1] = z;
      }
      v11 += 3;
      v16 = iPortal-- == 1;
      v56 = (int)v11;
    }
    while ( !v16 );
  }
  v17 = Convex2D(a1: v4, pPoints: m_pMemory, nPoints: SLODWORD(v4), indices, nMaxIndices: 512);
  v18 = v17;
  iPortal = v17;
  dp->m_FirstClipPortalVert = g_nClipPortalVerts;
  dp->m_nClipPortalVerts = v17;
  if ( v17 >= 32 )
    _Warning(a1: "Warning: area portal has %d verts. Could be a vbsp bug.\n", v17);
  if ( dp->m_FirstClipPortalVert + (unsigned int)dp->m_nClipPortalVerts >= 0x1F400 )
    _Error(
      a1: "MAX_MAP_PORTALVERTS (probably a broken areaportal near %.1f %.1f %.1f ",
      pPortal->winding->p->x,
      pPortal->winding->p->y,
      pPortal->winding->p->z);
  v19 = g_nClipPortalVerts;
  v20 = 0;
  if ( v18 >= 4 )
  {
    v21 = v18 - 3;
    do
    {
      v22 = (float *)(HIDWORD(v4) + 12 * indices[v20]);
      g_ClipPortalVerts[v19].x = *v22;
      LODWORD(v4) = &g_ClipPortalVerts[v19];
      v23 = v19 + 1;
      *(float *)(LODWORD(v4) + 4) = v22[1];
      v20 += 4;
      v24 = v22[2];
      v25 = v43[v20];
      *(float *)(LODWORD(v4) + 8) = v24;
      g_nClipPortalVerts = v23;
      v25 *= 3;
      v26 = *(float *)(HIDWORD(v4) + 4 * v25);
      v27 = HIDWORD(v4) + 4 * v25;
      g_ClipPortalVerts[v23].x = v26;
      LODWORD(v4) = &g_ClipPortalVerts[v23++];
      *(float *)(LODWORD(v4) + 4) = *(float *)(v27 + 4);
      v28 = *(float *)(v27 + 8);
      v29 = v43[v20 + 1];
      *(float *)(LODWORD(v4) + 8) = v28;
      g_nClipPortalVerts = v23;
      v29 *= 3;
      v30 = *(float *)(HIDWORD(v4) + 4 * v29);
      v31 = HIDWORD(v4) + 4 * v29;
      g_ClipPortalVerts[v23].x = v30;
      LODWORD(v4) = &g_ClipPortalVerts[v23++];
      *(float *)(LODWORD(v4) + 4) = *(float *)(v31 + 4);
      v32 = *(float *)(v31 + 8);
      v33 = v43[v20 + 2];
      *(float *)(LODWORD(v4) + 8) = v32;
      g_nClipPortalVerts = v23;
      v33 *= 3;
      v34 = *(float *)(HIDWORD(v4) + 4 * v33);
      v35 = HIDWORD(v4) + 4 * v33;
      v36 = &g_ClipPortalVerts[v23];
      v36->x = v34;
      v19 = v23 + 1;
      v36->y = *(float *)(v35 + 4);
      v37 = *(float *)(v35 + 8);
      g_nClipPortalVerts = v19;
      v36->z = v37;
    }
    while ( v20 < v21 );
    v18 = iPortal;
  }
  if ( v20 < v18 )
  {
    do
    {
      v38 = (float *)(HIDWORD(v4) + 12 * indices[v20]);
      v39 = &g_ClipPortalVerts[v19];
      v39->x = *v38;
      ++v19;
      ++v20;
      v39->y = v38[1];
      v40 = v38[2];
      g_nClipPortalVerts = v19;
      v39->z = v40;
    }
    while ( v20 < iPortal );
  }
  if ( points2D.m_Memory.m_nGrowSize >= 0 && points2D.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: points2D.m_Memory.m_pMemory);
  if ( points.m_Memory.m_nGrowSize >= 0 && HIDWORD(v4) != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)HIDWORD(v4));
  v41 = portals.m_Memory.m_pMemory;
  portals.m_Size = 0;
  if ( portals.m_Memory.m_nGrowSize >= 0 )
  {
    if ( portals.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: portals.m_Memory.m_pMemory);
      v41 = nullptr;
      portals.m_Memory.m_pMemory = nullptr;
    }
    portals.m_Memory.m_nAllocationCount = 0;
  }
  portals.m_pElements = v41;
  if ( portals.m_Memory.m_nGrowSize >= 0 && v41 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v41);
}

//------------------------------------------------------------------------------
// Address: 0x0042C050
// Name: void EmitAreaPortals(struct node_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EmitAreaPortals(node_t *headnode)
{
  int v1; // eax
  node_t *v2; // ebx
  int v3; // edx
  int v4; // edi
  bool v5; // cc
  _DWORD *v6; // esi
  portal_t *v7; // ecx
  dareaportal_t *v8; // eax
  int v9; // edi
  int planenum; // edx
  int v11; // ecx
  int area; // eax
  BOOL iSide; // [esp+0h] [ebp-Ch]
  int iSrcArea; // [esp+4h] [ebp-8h]
  int j; // [esp+8h] [ebp-4h]

  v1 = c_areas;
  if ( c_areas > 256 )
  {
    _Error(a1: "Map is split into too many unique areas (max = %d)\nProbably too many areaportals", 256);
    v1 = c_areas;
  }
  v2 = headnode;
  v3 = 1;
  v4 = 1;
  numareas = v1 + 1;
  numareaportals = 1;
  g_nClipPortalVerts = 0;
  for ( iSrcArea = 1; v4 <= v1; iSrcArea = v4 )
  {
    v5 = num_entities <= 0;
    dareas[v4].firstareaportal = v3;
    j = 0;
    if ( !v5 )
    {
      v6 = &unk_5CD496C;
      do
      {
        if ( *(v6 - 1) != 0 && (*v6 == v4 || v6[1] == v4) )
        {
          iSide = *v6 == v4;
          v7 = (portal_t *)v6[2];
          if ( v7->nodes[0]->area == v7->nodes[1]->area )
            v7 = (portal_t *)v6[3];
          if ( v7 != nullptr )
          {
            numareaportals = v3 + 1;
            v8 = &dareaportals[v3];
            v8->m_PortalKey = *((_WORD *)v6 - 2);
            v9 = LOWORD(v6[iSide]);
            v8->otherarea = v9;
            planenum = v7->onnode->planenum;
            v8->planenum = planenum;
            if ( v7->nodes[0]->area == v9 )
              v8->planenum = planenum ^ ((unsigned __int8)planenum ^ (unsigned __int8)~(_BYTE)planenum) & 1;
            v4 = iSrcArea;
            v2 = headnode;
            EmitClipPortalGeometry(pHeadNode: headnode, pPortal: v7, iSrcArea, dp: v8);
            v3 = numareaportals;
          }
          else
          {
            v2 = headnode;
          }
        }
        v6 += 11;
        ++j;
      }
      while ( j < num_entities );
      v1 = c_areas;
    }
    v11 = v3 - dareas[v4++].firstareaportal;
    *(&numfaces + 2 * v4) = v11;
  }
  if ( v2->planenum != -1 )
  {
    SetNodeAreaIndices_R(node: v2->children[0]);
    SetNodeAreaIndices_R(node: v2->children[1]);
    area = v2->children[0]->area;
    if ( area == v2->children[1]->area )
      v2->area = area;
    else
      v2->area = -1;
  }
  qprintf(format: "%5i numareas\n", numareas);
  qprintf(format: "%5i numareaportals\n", numareaportals);
}

//------------------------------------------------------------------------------
// Address: 0x0042C200
// Name: DisplayPortalError
// Source: json
//------------------------------------------------------------------------------
void __usercall DisplayPortalError(portal_t *p@<eax>, int viscontents)
{
  node_t **nodes; // edi
  int *m_pMemory; // ebx
  int m_Size; // esi
  bspbrush_t *brushlist; // edi
  mapbrush_t *original; // edx
  int v8; // eax
  int v9; // edi
  int *v10; // eax
  bool v11; // zf
  char contents[3][1024]; // [esp+24h] [ebp-C30h] BYREF
  Vector center; // [esp+C24h] [ebp-30h] BYREF
  CUtlVector<int,CUtlMemory<int,int> > listed; // [esp+C30h] [ebp-24h] BYREF
  node_t **v15; // [esp+C44h] [ebp-10h]
  mapbrush_t *brush; // [esp+C48h] [ebp-Ch]
  int v17; // [esp+C4Ch] [ebp-8h]
  bspbrush_t *bb; // [esp+C50h] [ebp-4h]

  nodes = p->nodes;
  PrintBrushContentsToString(contents: p->nodes[0]->contents, pOut: contents[0], nMaxChars: 0x400u);
  PrintBrushContentsToString(contents: p->nodes[1]->contents, pOut: contents[1], nMaxChars: 0x400u);
  PrintBrushContentsToString(contents: viscontents, pOut: contents[2], nMaxChars: 0x400u);
  WindingCenter(w: p->winding, &center);
  _Warning(
    a1: "\nFindPortalSide: Couldn't find a good match for which brush to assign to a portal near (%.1f %.1f %.1f)\n",
    center.x,
    center.y,
    center.z);
  _Warning(a1: "Leaf 0 contents: %s\n", contents[0]);
  _Warning(a1: "Leaf 1 contents: %s\n", contents[1]);
  _Warning(a1: "viscontents (node 0 contents ^ node 1 contents): %s\n", contents[2]);
  _Warning(a1: "This means that none of the brushes in leaf 0 or 1 that touches the portal has %s\n", contents[2]);
  _Warning(a1: "Check for a huge brush enclosing the coordinates above that has contents %s\n", contents[2]);
  _Warning(a1: "Candidate brush IDs: ");
  m_pMemory = nullptr;
  m_Size = 0;
  memset(&listed, 0, sizeof(listed));
  v15 = nodes;
  v17 = 2;
  do
  {
    brushlist = (*nodes)->brushlist;
    bb = brushlist;
    if ( brushlist != nullptr )
    {
      while ( 1 )
      {
        original = brushlist->original;
        brush = original;
        if ( (viscontents & original->contents) != 0 )
        {
          v8 = 0;
          if ( m_Size <= 0 )
            goto LABEL_11;
          while ( m_pMemory[v8] != original->brushnum )
          {
            if ( ++v8 >= m_Size )
              goto LABEL_11;
          }
          if ( v8 == -1 )
          {
LABEL_11:
            v9 = m_Size;
            if ( m_Size + 1 > listed.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<HemiLightData_t *,int>::Grow(
                this: (CUtlMemory<S3RGBA,int> *)&listed,
                num: m_Size - listed.m_Memory.m_nAllocationCount + 1);
              m_Size = listed.m_Size;
              m_pMemory = listed.m_Memory.m_pMemory;
              original = brush;
            }
            listed.m_Size = ++m_Size;
            listed.m_pElements = m_pMemory;
            if ( m_Size - v9 - 1 > 0 )
            {
              _V_memmove(dest: &m_pMemory[v9 + 1], src: &m_pMemory[v9], count: 4 * (m_Size - v9 - 1));
              original = brush;
            }
            v10 = &m_pMemory[v9];
            if ( v10 != nullptr )
              *v10 = original->brushnum;
            _Warning(a1: "Brush %d: ", original->id);
            brushlist = bb;
          }
        }
        bb = brushlist->next;
        if ( bb == nullptr )
          break;
        brushlist = bb;
      }
    }
    nodes = v15 + 1;
    v11 = v17-- == 1;
    ++v15;
  }
  while ( !v11 );
  _Warning(a1: "\n\n");
  if ( listed.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x0042C410
// Name: void FindPortalSide(struct portal_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FindPortalSide(portal_t *p)
{
  portal_t *v1; // esi
  node_t **nodes; // ecx
  int v3; // edx
  float v4; // xmm5_4
  mapbrush_t *original; // ecx
  int v6; // ebx
  side_t *original_sides; // edi
  unsigned int v8; // eax
  winding_t *winding; // esi
  float v10; // xmm0_4
  int v11; // edx
  int v12; // eax
  float *v13; // edx
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm4_4
  float *p_x; // edx
  int numsides; // [esp+8h] [ebp-24h]
  mapbrush_t *brush; // [esp+10h] [ebp-1Ch]
  node_t **v21; // [esp+14h] [ebp-18h]
  int j; // [esp+18h] [ebp-14h]
  int bestdist; // [esp+1Ch] [ebp-10h]
  side_t *bestside; // [esp+20h] [ebp-Ch]
  bspbrush_t *bb; // [esp+24h] [ebp-8h]
  int v26; // [esp+28h] [ebp-4h]

  v1 = p;
  nodes = p->nodes;
  v3 = 1;
  while ( ((p->nodes[0]->contents ^ p->nodes[1]->contents) & v3) == 0 )
  {
    v3 *= 2;
    if ( v3 > 128 )
      return;
  }
  v26 = v3;
  if ( v3 != 0 )
  {
    v4 = 1000000.0;
    bestside = nullptr;
    bestdist = 1232348160;
    j = 0;
    v21 = p->nodes;
    do
    {
      for ( bb = (*nodes)->brushlist; bb != nullptr; bb = bb->next )
      {
        original = bb->original;
        brush = original;
        if ( (v3 & original->contents) != 0 )
        {
          v6 = 0;
          numsides = original->numsides;
          if ( numsides > 0 )
          {
            original_sides = original->original_sides;
            while ( 1 )
            {
              if ( original_sides->bevel == 0 && original_sides->texinfo != -1 )
              {
                v8 = original_sides->planenum & 0xFFFFFFFE;
                if ( v8 == p->onnode->planenum )
                {
                  v4 = 0.0;
                  v3 = v26;
                  bestside = &original->original_sides[v6];
                  bestdist = 0;
                  goto gotit;
                }
                winding = v1->winding;
                v10 = 0.0;
                v11 = 3 * v8;
                v12 = 0;
                v13 = &mapplanes.x + 2 * v11;
                if ( winding->numpoints > 0 )
                {
                  v14 = v13[1];
                  v15 = *v13;
                  v16 = v13[2];
                  v17 = v13[3];
                  p_x = &winding->p->x;
                  do
                  {
                    v10 = v10
                        + COERCE_FLOAT(
                            COERCE_UNSIGNED_INT(
                              (float)((float)((float)(p_x[1] * v14) + (float)(*p_x * v15)) + (float)(p_x[2] * v16))
                            - v17)
                          & _mask__AbsFloat_);
                    if ( v10 > v4 )
                      break;
                    ++v12;
                    p_x += 3;
                  }
                  while ( v12 < winding->numpoints );
                }
                if ( v4 > v10 )
                {
                  v4 = v10;
                  bestside = original_sides;
                  bestdist = LODWORD(v10);
                }
              }
              v1 = p;
              ++v6;
              ++original_sides;
              if ( v6 >= numsides )
              {
                v3 = v26;
                break;
              }
              original = brush;
            }
          }
        }
      }
      nodes = v21 + 1;
      ++j;
      ++v21;
    }
    while ( j < 2 );
gotit:
    if ( bestside == nullptr )
    {
      qprintf(format: "WARNING: side not found for portal\n");
      v4 = *(float *)&bestdist;
      v3 = v26;
    }
    if ( (float)(v4 / (float)v1->winding->numpoints) > 2.0 && nWarnCount < 8 )
    {
      DisplayPortalError(p: v1, viscontents: v3);
      if ( ++nWarnCount == 8 )
        _Warning(a1: "*** Suppressing further FindPortalSide errors.... ***\n");
    }
    v1->sidefound = 1;
    v1->side = bestside;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042C620
// Name: void MarkVisibleSides_r(struct node_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MarkVisibleSides_r(node_t *node)
{
  node_t *i; // edi
  portal_t *j; // esi
  BOOL v3; // ebx
  side_t *side; // eax

  for ( i = node; i->planenum != -1; i = i->children[1] )
    MarkVisibleSides_r(node: i->children[0]);
  if ( i->contents != 0 )
  {
    for ( j = i->portals; j != nullptr; j = j->next[!v3] )
    {
      v3 = j->nodes[0] == i;
      if ( j->onnode != nullptr )
      {
        if ( j->sidefound == 0 )
          FindPortalSide(p: j);
        side = j->side;
        if ( side != nullptr )
          side->visible = 1;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042C6A0
// Name: void MarkVisibleSides(struct tree_t __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MarkVisibleSides(tree_t *tree, int startbrush, int endbrush, int detailScreen)
{
  int *p_numsides; // ecx
  int v5; // edx
  int v6; // eax
  node_t *headnode; // ebx
  portal_t *i; // esi
  BOOL v9; // edi
  side_t *side; // eax
  int startbrusha; // [esp+18h] [ebp+Ch]

  qprintf(format: "--- MarkVisibleSides ---\n");
  if ( startbrush < endbrush )
  {
    p_numsides = &mapbrushes[startbrush].numsides;
    startbrusha = endbrush - startbrush;
    do
    {
      if ( detailScreen == 0 || (detailScreen == 1) == ((*(p_numsides - 7) & 0x8000000) != 0) )
      {
        v5 = *p_numsides;
        if ( *p_numsides > 0 )
        {
          v6 = 0;
          do
          {
            *(_DWORD *)(v6 + p_numsides[1] + 28) = 0;
            v6 += 100;
            --v5;
          }
          while ( v5 != 0 );
        }
      }
      p_numsides += 12;
      --startbrusha;
    }
    while ( startbrusha != 0 );
  }
  headnode = tree->headnode;
  if ( tree->headnode->planenum == -1 )
  {
    if ( headnode->contents != 0 )
    {
      for ( i = headnode->portals; i != nullptr; i = i->next[!v9] )
      {
        v9 = i->nodes[0] == headnode;
        if ( i->onnode != nullptr )
        {
          if ( i->sidefound == 0 )
            FindPortalSide(p: i);
          side = i->side;
          if ( side != nullptr )
            side->visible = 1;
        }
      }
    }
  }
  else
  {
    MarkVisibleSides_r(node: headnode->children[0]);
    MarkVisibleSides_r(node: headnode->children[1]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042C790
// Name: void MarkVisibleSides(struct tree_t __near *,struct mapbrush_t __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MarkVisibleSides(tree_t *tree, mapbrush_t **ppBrushes, int nCount)
{
  int i; // esi
  mapbrush_t *v4; // ecx
  int numsides; // edx
  int v6; // eax
  node_t *headnode; // ebx
  portal_t *j; // esi
  BOOL v9; // edi
  side_t *side; // eax

  qprintf(format: "--- MarkVisibleSides ---\n");
  for ( i = 0; i < nCount; ++i )
  {
    v4 = ppBrushes[i];
    numsides = v4->numsides;
    if ( numsides > 0 )
    {
      v6 = 0;
      do
      {
        v4->original_sides[v6++].visible = 0;
        --numsides;
      }
      while ( numsides != 0 );
    }
  }
  headnode = tree->headnode;
  if ( tree->headnode->planenum == -1 )
  {
    if ( headnode->contents != 0 )
    {
      for ( j = headnode->portals; j != nullptr; j = j->next[!v9] )
      {
        v9 = j->nodes[0] == headnode;
        if ( j->onnode != nullptr )
        {
          if ( j->sidefound == 0 )
            FindPortalSide(p: j);
          side = j->side;
          if ( side != nullptr )
            side->visible = 1;
        }
      }
    }
  }
  else
  {
    MarkVisibleSides_r(node: headnode->children[0]);
    MarkVisibleSides_r(node: headnode->children[1]);
  }
}
