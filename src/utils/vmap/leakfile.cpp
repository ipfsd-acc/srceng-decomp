// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vmap/leakfile.cpp
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00422F60
// Name: void LeakFile(struct tree_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LeakFile(tree_t *tree)
{
  _iobuf *v1; // ebx
  node_t *p_outside_node; // esi
  portal_t *portals; // eax
  node_t *v4; // edi
  BOOL v5; // ebx
  node_t *v6; // ecx
  int occupied; // edx
  int v8; // ecx
  const char *v9; // esi
  char filename[1024]; // [esp+24h] [ebp-424h] BYREF
  Vector mid; // [esp+424h] [ebp-24h] BYREF
  _iobuf *linefile; // [esp+430h] [ebp-18h]
  Vector origin; // [esp+434h] [ebp-14h] BYREF
  int next; // [esp+440h] [ebp-8h]
  portal_t *nextportal; // [esp+444h] [ebp-4h]
  int count; // [esp+450h] [ebp+8h]

  if ( tree->outside_node.occupied != 0 )
  {
    tree->leaked = true;
    qprintf(format: "--- LeakFile ---\n");
    sprintf(string: filename, format: "%s.lin", source);
    v1 = fopen(file: filename, mode: "w");
    linefile = v1;
    if ( v1 == nullptr )
      _Error(a1: "Couldn't open %s\n", filename);
    p_outside_node = &tree->outside_node;
    count = 0;
    if ( p_outside_node->occupied > 1 )
    {
      do
      {
        next = p_outside_node->occupied;
        portals = p_outside_node->portals;
        v4 = nullptr;
        nextportal = nullptr;
        if ( portals != nullptr )
        {
          do
          {
            v5 = portals->nodes[0] == p_outside_node;
            v6 = portals->nodes[v5];
            occupied = v6->occupied;
            if ( occupied != 0 && occupied < next )
            {
              v4 = portals->nodes[v5];
              v8 = v6->occupied;
              nextportal = portals;
              next = v8;
            }
            portals = portals->next[!v5];
          }
          while ( portals != nullptr );
          v1 = linefile;
        }
        p_outside_node = v4;
        WindingCenter(w: nextportal->winding, center: &mid);
        fprintf(str: v1, format: "%f %f %f\n", mid.x, mid.y, mid.z);
        ++count;
      }
      while ( v4->occupied > 1 );
    }
    GetVectorForKey(ent: p_outside_node->occupant, key: "origin", angle: (QAngle *)&origin);
    fprintf(str: v1, format: "%f %f %f\n", origin.x, origin.y, origin.z);
    qprintf(format: "%5i point linefile\n", count + 1);
    fclose(stream: v1);
    v9 = ValueForKey(ent: p_outside_node->occupant, key: "classname");
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_GENERAL, a2: 0) != 0 )
      LoggingSystem_Log(
        a1: LOG_GENERAL,
        a2: LS_MESSAGE,
        a3: (struct Color)-16776961,
        a4: "Entity %s (%.2f %.2f %.2f) leaked!\n",
        v9,
        origin.x,
        origin.y,
        origin.z);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00423160
// Name: void AreaportalLeakFile(struct tree_t __near *,struct portal_t __near *,struct portal_t __near *,struct node_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AreaportalLeakFile(_iobuf *tree, portal_t *pStartPortal, portal_t *pEndPortal, node_t *pStart)
{
  _iobuf *v4; // ebx
  winding_t *winding; // edx
  node_t *v6; // esi
  float v7; // xmm1_4
  float v8; // xmm0_4
  node_t *v9; // edi
  portal_t *portals; // eax
  BOOL v11; // ebx
  node_t *v12; // ecx
  int occupied; // edx
  int v14; // ecx
  float v15; // xmm1_4
  float v16; // xmm0_4
  int v17; // esi
  char filename[1024]; // [esp+24h] [ebp-418h] BYREF
  int next; // [esp+424h] [ebp-18h]
  portal_t *nextportal; // [esp+428h] [ebp-14h]
  int count; // [esp+42Ch] [ebp-10h]
  Vector mid; // [esp+430h] [ebp-Ch] BYREF
  _iobuf *linefile; // [esp+444h] [ebp+8h]

  if ( LOBYTE(tree[3]._bufsiz) == 0 )
  {
    LOBYTE(tree[3]._bufsiz) = 1;
    qprintf(format: "--- LeakFile ---\n");
    sprintf(string: filename, format: "%s.lin", source);
    v4 = fopen(file: filename, mode: "w");
    linefile = v4;
    if ( v4 == nullptr )
      _Error(a1: "Couldn't open %s\n", filename);
    winding = pEndPortal->winding;
    count = 2;
    WindingCenter(w: winding, center: &mid);
    fprintf(str: v4, format: "%f %f %f\n", mid.x, mid.y, mid.z);
    v6 = pStart;
    v7 = (float)(pStart->mins.y + pStart->maxs.y) * 0.5;
    v8 = (float)(pStart->mins.x + pStart->maxs.x) * 0.5;
    mid.z = (float)(pStart->mins.z + pStart->maxs.z) * 0.5;
    mid.y = v7;
    mid.x = v8;
    fprintf(str: v4, format: "%f %f %f\n", v8, v7, mid.z);
    if ( pStart->occupied >= 1 )
    {
      while ( 1 )
      {
        v9 = nullptr;
        next = v6->occupied;
        portals = v6->portals;
        nextportal = nullptr;
        if ( portals == nullptr )
          break;
        do
        {
          v11 = portals->nodes[0] == v6;
          v12 = portals->nodes[v11];
          occupied = v12->occupied;
          if ( occupied != 0 && occupied < next )
          {
            v9 = portals->nodes[v11];
            v14 = v12->occupied;
            nextportal = portals;
            next = v14;
          }
          portals = portals->next[!v11];
        }
        while ( portals != nullptr );
        if ( v9 == nullptr
          || (v6 = v9,
              WindingCenter(w: nextportal->winding, center: &mid),
              fprintf(str: linefile, format: "%f %f %f\n", mid.x, mid.y, mid.z),
              ++count,
              v9->occupied < 1) )
        {
          v4 = linefile;
          break;
        }
        v4 = linefile;
      }
    }
    v15 = (float)(v6->mins.y + v6->maxs.y) * 0.5;
    v16 = (float)(v6->maxs.x + v6->mins.x) * 0.5;
    mid.z = (float)(v6->mins.z + v6->maxs.z) * 0.5;
    mid.y = v15;
    mid.x = v16;
    fprintf(str: v4, format: "%f %f %f\n", v16, v15, mid.z);
    v17 = count;
    WindingCenter(w: pStartPortal->winding, center: &mid);
    fprintf(str: v4, format: "%f %f %f\n", mid.x, mid.y, mid.z);
    qprintf(format: "%5i point linefile\n", v17 + 2);
    fclose(stream: v4);
    _Warning(a1: "Wrote %s\n", filename);
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_GENERAL, a2: 0) != 0 )
      LoggingSystem_Log(
        a1: LOG_GENERAL,
        a2: LS_MESSAGE,
        a3: (struct Color)-16776961,
        a4: "Areaportal leak ! File: %s ",
        filename);
  }
}
