// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vbsp/writebsp.cpp
// Functions: 32
// ============================================================

#include "utils\vbsp\writebsp.h"

//------------------------------------------------------------------------------
// Address: 0x0042D9B0
// Name: bool CaselessStringLessThan(char const __near * const __near &,char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CaselessStringLessThan(const char **lhs, const char **rhs)
{
  if ( *lhs == nullptr )
    return false;
  if ( *rhs != nullptr )
    return _V_stricmp(s1: *lhs, s2: *rhs) < 0;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x0042D9E0
// Name: void EmitPlanes(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EmitPlanes()
{
  CMapFile *v0; // edi
  int v1; // esi
  CMapFile *v2; // eax
  int v3; // edx
  dplane_t *v4; // ecx
  double z; // st7

  v0 = g_MainMap;
  v1 = 0;
  v2 = g_MainMap;
  if ( g_MainMap->nummapplanes > 0 )
  {
    v3 = numplanes;
    do
    {
      dplanes[v3].normal.x = v2->mapplanes[0].normal.x;
      v4 = &dplanes[v3++];
      v4->normal.y = v2->mapplanes[0].normal.y;
      ++v1;
      z = v2->mapplanes[0].normal.z;
      v2 = (CMapFile *)((char *)v2 + 24);
      v4->normal.z = z;
      v4->dist = *(float *)&v2[-1].m_ConnectionPairs;
      v4->type = v2[-1].m_StartMapOverlays;
      numplanes = v3;
    }
    while ( v1 < v0->nummapplanes );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042DA60
// Name: void EmitMarkFace(struct dleaf_t __near *,struct face_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EmitMarkFace(dleaf_t *leaf_p, face_t *f)
{
  int outputnumber; // esi
  int firstleafface; // eax
  int v5; // ecx
  bool v6; // zf

  while ( 1 )
  {
    while ( f->merged != nullptr )
      f = f->merged;
    if ( f->split[0] == nullptr )
      break;
    EmitMarkFace(leaf_p, f: f->split[0]);
    f = f->split[1];
  }
  outputnumber = f->outputnumber;
  if ( outputnumber != -1 )
  {
    if ( outputnumber < 0 || outputnumber >= numfaces )
      _Error(a1: "Bad leafface");
    firstleafface = leaf_p->firstleafface;
    v5 = numleaffaces;
    v6 = firstleafface == numleaffaces;
    if ( firstleafface < numleaffaces )
    {
      do
      {
        if ( dleaffaces[firstleafface] == outputnumber )
          break;
        ++firstleafface;
      }
      while ( firstleafface < numleaffaces );
      v6 = firstleafface == numleaffaces;
    }
    if ( v6 )
    {
      if ( numleaffaces >= 0x10000 )
      {
        _Error(a1: "Too many detail brush faces, max = %d\n", 0x10000);
        v5 = numleaffaces;
      }
      dleaffaces[v5] = outputnumber;
      numleaffaces = v5 + 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042DB10
// Name: void EmitLeaf(struct node_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EmitLeaf(node_t *node)
{
  dleaf_t *v2; // esi
  int v3; // edi
  int firstleafbrush; // ecx
  int v5; // eax
  bool v6; // zf
  __int16 v7; // ax
  portal_t *portals; // edi
  BOOL v9; // eax
  face_t *v10; // ecx
  leafface_t *leaffacelist; // edi
  bspbrush_t *s; // [esp+8h] [ebp+8h]
  int sa; // [esp+8h] [ebp+8h]

  if ( numleafs >= 0x10000 )
    _Error(a1: "Too many BSP leaves, max = %d", 0x10000);
  node->diskId = numleafs;
  v2 = &dleafs[numleafs++];
  if ( nummodels != 0 )
    v2->cluster = -1;
  else
    v2->cluster = node->cluster;
  v3 = numleafbrushes;
  v2->contents = node->contents;
  v2->__s1 = ($7CA033D54BBC683D0ECF5D922201D02D)(node->area & 0x1FF | 0x200);
  v2->mins[0] = (int)node->mins.x;
  v2->mins[1] = (int)node->mins.y;
  v2->mins[2] = (int)node->mins.z;
  v2->maxs[0] = (int)node->maxs.x;
  v2->maxs[1] = (int)node->maxs.y;
  v2->maxs[2] = (int)node->maxs.z;
  v2->firstleafbrush = v3;
  for ( s = node->brushlist; s != nullptr; s = s->next )
  {
    if ( v3 >= 0x10000 )
    {
      _Error(a1: "Too many brushes in one leaf, max = %d", 0x10000);
      v3 = numleafbrushes;
    }
    firstleafbrush = v2->firstleafbrush;
    v5 = ((char *)s->original - (char *)g_MainMap - 1576968) / 48;
    v6 = firstleafbrush == v3;
    if ( firstleafbrush < v3 )
    {
      do
      {
        if ( dleafbrushes[firstleafbrush] == v5 )
          break;
        ++firstleafbrush;
      }
      while ( firstleafbrush < v3 );
      v6 = firstleafbrush == v3;
    }
    if ( v6 )
    {
      dleafbrushes[v3++] = v5;
      numleafbrushes = v3;
    }
  }
  v6 = (v2->contents & 1) == 0;
  v2->numleafbrushes = v3 - v2->firstleafbrush;
  if ( v6 )
  {
    v7 = numleaffaces;
    v2->firstleafface = numleaffaces;
    portals = node->portals;
    if ( portals != nullptr )
    {
      do
      {
        v9 = portals->nodes[1] == node;
        v10 = portals->face[v9];
        sa = v9;
        if ( v10 != nullptr )
        {
          EmitMarkFace(leaf_p: v2, f: v10);
          v9 = sa;
        }
        portals = portals->next[v9];
      }
      while ( portals != nullptr );
      v7 = numleaffaces;
    }
    leaffacelist = node->leaffacelist;
    if ( leaffacelist != nullptr )
    {
      do
      {
        EmitMarkFace(leaf_p: v2, f: leaffacelist->pFace);
        leaffacelist = leaffacelist->pNext;
      }
      while ( leaffacelist != nullptr );
      v7 = numleaffaces;
    }
    v2->numleaffaces = v7 - v2->firstleafface;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042DCD0
// Name: int CreateOrigFace(struct face_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CreateOrigFace(face_t *f)
{
  side_t *originalface; // esi
  int v3; // eax
  dface_t *v4; // edi
  int v5; // eax
  winding_t *v6; // eax
  int v7; // ebx
  winding_t *v8; // ecx
  int v9; // esi
  int v10; // edi
  int Vertexnum; // eax
  winding_t *v12; // edx
  int numpoints; // ecx
  int v14; // eax
  int v15; // edi
  int v16; // esi
  int v17; // edx
  bool v18; // zf
  int v19; // ebx
  winding_t *winding; // [esp-Ch] [ebp-220h]
  int vIndices[128]; // [esp+4h] [ebp-210h]
  int v22; // [esp+204h] [ebp-10h]
  int eIndex[2]; // [esp+208h] [ebp-Ch]
  winding_t *pWinding; // [esp+210h] [ebp-4h]

  if ( f->w == nullptr )
    return -1;
  originalface = f->originalface;
  if ( originalface->winding == nullptr )
    return -1;
  v3 = numorigfaces;
  if ( numorigfaces >= 0x10000 )
  {
    _Error(a1: "Too many faces in map, max = %d", 0x10000);
    v3 = numorigfaces;
  }
  numorigfaces = v3 + 1;
  dorigfaces[v3].origFace = -1;
  v4 = &dorigfaces[v3];
  originalface->next = pOrigFaceSideList[f->planenum];
  v5 = numorigfaces;
  pOrigFaceSideList[f->planenum] = originalface;
  winding = originalface->winding;
  originalface->origIndex = v5 - 1;
  v6 = CopyWinding(w: winding);
  v7 = numsurfedges;
  v8 = v6;
  v4->planenum = originalface->planenum;
  v4->onNode = (originalface->contents & 0x8000000) == 0;
  v4->side = originalface->planenum & 1;
  v4->firstedge = v7;
  v4->numedges = originalface->winding->numpoints;
  v4->texinfo = originalface->texinfo;
  v9 = 0;
  v4->dispinfo = f->dispinfo;
  pWinding = v6;
  if ( v6->numpoints > 0 )
  {
    v10 = 0;
    do
    {
      Vertexnum = GetVertexnum(in: &v8->p[v10]);
      v12 = pWinding;
      vIndices[v9++] = Vertexnum;
      ++v10;
      v8 = v12;
    }
    while ( v9 < v12->numpoints );
    v7 = numsurfedges;
  }
  numpoints = v8->numpoints;
  v14 = 0;
  if ( numpoints > 0 )
  {
    v15 = numedges;
    do
    {
      eIndex[0] = vIndices[v14];
      v22 = v14 + 1;
      v16 = firstmodeledge;
      v17 = vIndices[(v14 + 1) % numpoints];
      eIndex[1] = v17;
      v18 = firstmodeledge == v15;
      if ( firstmodeledge < v15 )
      {
        while ( eIndex[0] != (unsigned __int16)word_4DC75C2[2 * v16]
             || v17 != dedges[v16].v[0]
             || edgefaces[v16][0]->contents != f->contents
             || dword_47487EC[2 * v16] != 0 )
        {
          if ( ++v16 >= v15 )
            goto LABEL_23;
        }
        dword_47487EC[2 * v16] = (int)f;
        if ( v7 >= 512000 )
        {
          _Error(a1: "Too much brush geometry in bsp, numsurfedges == MAX_MAP_SURFEDGES");
          v7 = numsurfedges;
          v15 = numedges;
          v17 = eIndex[1];
        }
        dsurfedges[v7++] = -v16;
        numsurfedges = v7;
LABEL_23:
        v18 = v16 == v15;
      }
      if ( v18 )
      {
        AddEdge(v1: eIndex[0], v2: v17, f);
        v19 = numsurfedges;
        if ( numsurfedges >= 512000 )
        {
          _Error(a1: "Too much brush geometry in bsp, numsurfedges == MAX_MAP_SURFEDGES");
          v19 = numsurfedges;
        }
        v15 = numedges;
        dsurfedges[v19] = numedges - 1;
        v7 = v19 + 1;
        numsurfedges = v7;
      }
      v14 = v22;
      numpoints = pWinding->numpoints;
    }
    while ( v22 < pWinding->numpoints );
  }
  return numorigfaces - 1;
}

//------------------------------------------------------------------------------
// Address: 0x0042DF20
// Name: int FindOrigFace(struct face_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindOrigFace(face_t *f)
{
  side_t *v1; // eax

  if ( bClear == 0 )
  {
    memset(pOrigFaceSideList, 0, sizeof(pOrigFaceSideList));
    bClear = 1;
  }
  v1 = pOrigFaceSideList[f->planenum];
  if ( v1 == nullptr )
    return -1;
  while ( v1 != f->originalface )
  {
    v1 = v1->next;
    if ( v1 == nullptr )
      return -1;
  }
  return v1->origIndex;
}

//------------------------------------------------------------------------------
// Address: 0x0042DF80
// Name: unsigned short BrushIndexFromSide(struct side_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl BrushIndexFromSide(side_t *pSide)
{
  int nummapbrushes; // esi
  side_t *original; // edi
  int result; // eax
  int *i; // ecx
  unsigned int v5; // edx

  nummapbrushes = g_MainMap->nummapbrushes;
  original = pSide;
  if ( pSide->original != nullptr )
    original = pSide->original;
  result = 0;
  if ( nummapbrushes <= 0 )
    return 0xFFFF;
  for ( i = &g_MainMap->mapbrushes[0].numsides; ; i += 12 )
  {
    v5 = i[1];
    if ( (unsigned int)original >= v5 && (unsigned int)original < v5 + 92 * *i )
      break;
    if ( ++result >= nummapbrushes )
      return 0xFFFF;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042DFE0
// Name: void FreeLeafFaces(struct face_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FreeLeafFaces(face_t *pLeafFaceList)
{
  face_t *v1; // eax
  face_t *next; // esi

  v1 = pLeafFaceList;
  if ( pLeafFaceList != nullptr )
  {
    do
    {
      next = v1->next;
      FreeFace(f: v1);
      v1 = next;
    }
    while ( next != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042E010
// Name: void SetModelNumbers(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetModelNumbers()
{
  int v0; // edi
  int v1; // ebx
  entity_t *v2; // esi
  char value[12]; // [esp+8h] [ebp-Ch] BYREF

  v0 = 1;
  v1 = 1;
  if ( num_entities > 1 )
  {
    v2 = &ent;
    do
    {
      if ( v2->numbrushes != 0 )
      {
        if ( IsFuncOccluder(entity_num: v0) )
          sprintf(string: value, format: &defaultValue);
        else
          sprintf(string: value, format: "*%i", v1++);
        SetKeyValue(ent: v2, key: "model", value, bAllowDuplicates: false);
      }
      ++v0;
      ++v2;
    }
    while ( v0 < num_entities );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042E090
// Name: void SetLightStyles(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetLightStyles()
{
  entity_t *v0; // edi
  const char *v1; // esi
  const char *v2; // ebx
  int v3; // eax
  int v4; // esi
  char *v5; // edi
  char *v6; // eax
  char v7; // cl
  const char *v8; // eax
  const char *v9; // esi
  char lighttargets[32][64]; // [esp+0h] [ebp-818h] BYREF
  char value[12]; // [esp+800h] [ebp-18h] BYREF
  int i; // [esp+80Ch] [ebp-Ch]
  entity_t *v13; // [esp+810h] [ebp-8h]
  int stylenum; // [esp+814h] [ebp-4h]

  stylenum = 0;
  i = 1;
  if ( num_entities > 1 )
  {
    v0 = &ent;
    v13 = &ent;
    do
    {
      v1 = ValueForKey(ent: v0, key: "classname");
      if ( V_strncasecmp(s1: v1, s2: "light", n: 5) == 0 && V_strcasecmp(s1: v1, s2: "light_dynamic") != 0 )
      {
        v2 = ValueForKey(ent: v0, key: "targetname");
        if ( *v2 != 0 )
        {
          v3 = stylenum;
          v4 = 0;
          if ( stylenum > 0 )
          {
            v5 = lighttargets[0];
            do
            {
              if ( strcmp(v5, v2) == 0 )
                break;
              ++v4;
              v5 += 64;
            }
            while ( v4 < stylenum );
            v0 = v13;
            v3 = stylenum;
          }
          if ( v4 == v3 )
          {
            if ( v3 == 32 )
              _Error(a1: "Too many switched lights (error at light %s), max = %d", v2, 32);
            v6 = (char *)v2;
            do
            {
              v7 = *v6;
              v6[(_DWORD)lighttargets + (v4 << 6) - (_DWORD)v2] = *v6;
              ++v6;
            }
            while ( v7 != 0 );
            ++stylenum;
          }
          sprintf(string: value, format: "%i", v4 + 32);
          v8 = ValueForKey(ent: v0, key: "style");
          v9 = v8;
          if ( v8 != nullptr && atoi(nptr: v8) != 0 )
            SetKeyValue(ent: v0, key: "defaultstyle", value: v9, bAllowDuplicates: false);
          SetKeyValue(ent: v0, key: "style", value, bAllowDuplicates: false);
        }
      }
      ++v0;
      ++i;
      v13 = v0;
    }
    while ( i < num_entities );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042E210
// Name: void EmitBrushes(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EmitBrushes()
{
  int v0; // eax
  dbrush_t *v1; // ecx
  mapbrush_t *v2; // edi
  int v3; // ebx
  int v4; // esi
  dbrushside_t *v5; // ecx
  __int16 texinfo; // dx
  unsigned int *p_maxs; // eax
  int j; // ebx
  unsigned int dist; // xmm0_4
  int FloatPlane; // eax
  int numsides; // ecx
  int v12; // esi
  int v13; // eax
  side_t *original_sides; // edx
  bool v15; // zf
  Vector normal; // [esp+10h] [ebp-24h] BYREF
  int bnum; // [esp+1Ch] [ebp-18h]
  int v18; // [esp+20h] [ebp-14h]
  unsigned int v19; // [esp+24h] [ebp-10h]
  Vector *p_normal; // [esp+28h] [ebp-Ch]
  dbrush_t *i; // [esp+2Ch] [ebp-8h]
  unsigned int *v22; // [esp+30h] [ebp-4h]

  v0 = 0;
  numbrushsides = 0;
  numbrushes = g_MainMap->nummapbrushes;
  bnum = 0;
  if ( g_MainMap->nummapbrushes > 0 )
  {
    v1 = dbrushes;
    v19 = 0;
    for ( i = dbrushes; ; v1 = i )
    {
      v2 = &g_MainMap->mapbrushes[v19 / 0x30];
      v1->contents = g_MainMap->mapbrushes[v19 / 0x30].contents;
      v1->firstside = v0;
      v3 = 0;
      v1->numsides = v2->numsides;
      if ( v2->numsides > 0 )
      {
        v4 = 0;
        do
        {
          if ( v0 == 0x10000 )
          {
            _Error(a1: "MAX_MAP_BRUSHSIDES");
            v0 = numbrushsides;
          }
          v5 = &dbrushsides[v0++];
          numbrushsides = v0;
          v5->planenum = v2->original_sides[v4].planenum;
          texinfo = v2->original_sides[v4].texinfo;
          v5->texinfo = texinfo;
          if ( texinfo == -1 )
            v5->texinfo = *(_WORD *)((char *)&unk_1391034 + (_DWORD)g_MainMap);
          v5->bevel = v2->original_sides[v4].bevel;
          ++v3;
          v5->thin = v2->original_sides[v4++].thin;
        }
        while ( v3 < v2->numsides );
      }
      p_normal = &normal;
      p_maxs = (unsigned int *)&v2->maxs;
      v22 = (unsigned int *)&v2->maxs;
      v18 = 3;
      for ( j = -1; ; j = -1 )
      {
        while ( 1 )
        {
          normal = vec3_origin;
          p_normal->x = (float)j;
          if ( j == -1 )
            dist = *(p_maxs - 3) ^ _mask__NegFloat_;
          else
            dist = *p_maxs;
          FloatPlane = CMapFile::FindFloatPlane(this: g_MainMap, &normal, dist);
          numsides = v2->numsides;
          v12 = FloatPlane;
          v13 = 0;
          if ( numsides > 0 )
          {
            original_sides = v2->original_sides;
            do
            {
              if ( original_sides->planenum == v12 )
                break;
              ++v13;
              ++original_sides;
            }
            while ( v13 < numsides );
          }
          v15 = v13 == numsides;
          v0 = numbrushsides;
          if ( v15 )
          {
            if ( numbrushsides >= 0x10000 )
            {
              _Error(a1: "MAX_MAP_BRUSHSIDES");
              v0 = numbrushsides;
            }
            dbrushsides[v0].planenum = v12;
            word_52B500A[4 * v0] = word_52B5002[4 * v0];
            ++v0;
            ++i->numsides;
            numbrushsides = v0;
          }
          j += 2;
          if ( j > 1 )
            break;
          p_maxs = v22;
        }
        p_normal = (Vector *)((char *)p_normal + 4);
        ++v22;
        if ( --v18 == 0 )
          break;
        p_maxs = v22;
      }
      v19 += 48;
      ++i;
      if ( ++bnum >= g_MainMap->nummapbrushes )
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042E430
// Name: void BeginBSPFile(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BeginBSPFile()
{
  nummodels = 0;
  numfaces = 0;
  numnodes = 0;
  numbrushsides = 0;
  numleaffaces = 0;
  numleafbrushes = 0;
  numsurfedges = 0;
  numedges = 1;
  numvertexes = 1;
  numleafs = 1;
  dleafs[0].contents = 1;
}

//------------------------------------------------------------------------------
// Address: 0x0042E470
// Name: void EnsurePresenceOfWaterLODControlEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EnsurePresenceOfWaterLODControlEntity()
{
  int v0; // esi
  entity_t *v1; // edi
  const char *v2; // eax
  unsigned __int8 *v3; // esi

  if ( g_bHasWater )
  {
    v0 = 0;
    if ( num_entities <= 0 )
    {
LABEL_6:
      _Warning(a1: "Water found with no water_lod_control entity, creating a default one.\n");
      v3 = (unsigned __int8 *)&entities + 44 * num_entities++;
      memset(dst: v3, value: 0, count: 0x2Cu);
      *((_DWORD *)v3 + 3) = g_MainMap->nummapbrushes;
      *((_DWORD *)v3 + 4) = 0;
      SetKeyValue(ent: (entity_t *)v3, key: "classname", value: "water_lod_control", bAllowDuplicates: false);
      SetKeyValue(ent: (entity_t *)v3, key: "cheapwaterstartdistance", value: "1000", bAllowDuplicates: false);
      SetKeyValue(ent: (entity_t *)v3, key: "cheapwaterenddistance", value: "2000", bAllowDuplicates: false);
    }
    else
    {
      v1 = (entity_t *)&entities;
      while ( 1 )
      {
        v2 = ValueForKey(ent: v1, key: "classname");
        if ( _V_stricmp(s1: v2, s2: "water_lod_control") == 0 )
          break;
        ++v0;
        ++v1;
        if ( v0 >= num_entities )
          goto LABEL_6;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042E540
// Name: void BeginModel(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BeginModel()
{
  int v0; // eax
  int v1; // ecx
  int v2; // edx
  dmodel_t *v3; // ebx
  char *v4; // eax
  int v5; // esi
  int v6; // edi
  int v7; // esi
  int v8; // ebx
  int v9; // esi
  mapbrush_t *v10; // edi
  Vector maxs; // [esp+0h] [ebp-1Ch] BYREF
  Vector mins; // [esp+Ch] [ebp-10h] BYREF
  dmodel_t *mod; // [esp+18h] [ebp-4h]

  v0 = nummodels;
  if ( nummodels == 1024 )
  {
    _Error(a1: "Too many brush models in map, max = %d", 1024);
    v0 = nummodels;
  }
  v1 = numleafs;
  v2 = numedges;
  firstmodelface = numfaces;
  v3 = &dmodels[v0];
  v3->firstface = numfaces;
  v4 = (char *)&entities + 44 * entity_num;
  v5 = *((_DWORD *)v4 + 4);
  v6 = *((_DWORD *)v4 + 3);
  firstmodleaf = v1;
  mod = v3;
  firstmodeledge = v2;
  v7 = v6 + v5;
  ClearBounds(&mins, &maxs);
  if ( v6 < v7 )
  {
    v8 = v6;
    v9 = v7 - v6;
    do
    {
      v10 = &g_MainMap->mapbrushes[v8];
      if ( g_MainMap->mapbrushes[v8].numsides != 0 )
      {
        AddPointToBounds(v: &g_MainMap->mapbrushes[v8].mins, &mins, &maxs);
        AddPointToBounds(v: &v10->maxs, &mins, &maxs);
      }
      ++v8;
      --v9;
    }
    while ( v9 != 0 );
    v3 = mod;
  }
  v3->mins = mins;
  v3->maxs = maxs;
}

//------------------------------------------------------------------------------
// Address: 0x0042E660
// Name: void EndModel(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EndModel()
{
  int v0; // ecx

  v0 = nummodels + 1;
  dmodels[nummodels].numfaces = numfaces - dmodels[nummodels].firstface;
  nummodels = v0;
}

//------------------------------------------------------------------------------
// Address: 0x0042E690
// Name: public: void CUtlMemory<int,int>::ConvertToGrowableMemory(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<int,int>::ConvertToGrowableMemory(CUtlMemory<int,int> *this, int nGrowSize)
{
  int m_nAllocationCount; // eax
  unsigned int v4; // edi
  unsigned __int8 *v5; // ebx

  if ( this->m_nGrowSize < 0 )
  {
    this->m_nGrowSize = nGrowSize;
    m_nAllocationCount = this->m_nAllocationCount;
    if ( m_nAllocationCount != 0 )
    {
      v4 = 4 * m_nAllocationCount;
      v5 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * m_nAllocationCount);
      memcpy(dst: v5, src: (unsigned __int8 *)this->m_pMemory, count: v4);
      this->m_pMemory = (int *)v5;
    }
    else
    {
      this->m_pMemory = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042E880
// Name: AddNodeToBounds
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddNodeToBounds(int node, CUtlVector<int,CUtlMemory<int,int> > *skipAreas, Vector *mins, Vector *maxs)
{
  int j; // esi
  int v5; // esi
  int v6; // edx
  int v7; // eax
  int *v8; // ecx
  unsigned __int16 *v9; // eax
  int v10; // edi
  int v11; // ebx
  dedge_t *v12; // esi
  int v13; // [esp+8h] [ebp-Ch]
  unsigned __int16 *v14; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]
  int *nodea; // [esp+1Ch] [ebp+8h]

  for ( j = node; j >= 0; j = dword_6CAA868[v5] )
  {
    v5 = 8 * j;
    AddNodeToBounds(node: dword_6CAA864[v5], skipAreas, mins, maxs);
  }
  v6 = 32 * (-1 - j);
  v13 = v6;
  if ( (*((_BYTE *)&dleafs[0].contents + v6) & 1) == 0 )
  {
    v7 = skipAreas->m_Size - 1;
    if ( v7 < 0 )
    {
LABEL_8:
      i = 0;
      if ( *(__int16 *)((char *)&word_4BA35D6 + v6) != 0 )
      {
        v9 = &dleaffaces[*(unsigned __int16 *)((char *)&word_4BA35D4 + v6)];
        v14 = v9;
        do
        {
          v10 = *v9;
          if ( (texinfo.m_Memory.m_pMemory[dfaces[v10].texinfo].flags & 0x84) == 0 )
          {
            v11 = 0;
            if ( dfaces[*v9].numedges > 0 )
            {
              nodea = &dsurfedges[dfaces[*v9].firstedge];
              do
              {
                v12 = &dedges[abs32(*nodea)];
                AddPointToBounds(v: &dvertexes + v12->v[0], mins, maxs);
                AddPointToBounds(v: &dvertexes + v12->v[1], mins, maxs);
                ++nodea;
                ++v11;
              }
              while ( v11 < dfaces[v10].numedges );
              v6 = v13;
            }
          }
          v9 = v14 + 1;
          ++i;
          ++v14;
        }
        while ( i < *(unsigned __int16 *)((char *)&word_4BA35D6 + v6) );
      }
    }
    else
    {
      v8 = &skipAreas->m_Memory.m_pMemory[v7];
      while ( (__int16)(*(__int16 *)((char *)&word_4BA35C6 + v6) << 7) >> 7 != *v8 )
      {
        --v8;
        if ( --v7 < 0 )
          goto LABEL_8;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042EA00
// Name: bool IsBoxInsideWorld(int,class CUtlVector<int,class CUtlMemory<int,int>> __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsBoxInsideWorld(
        int node,
        CUtlVector<int,CUtlMemory<int,int> > *skipAreas,
        const Vector *vecMins,
        const Vector *vecMaxs)
{
  int v4; // eax
  dnode_t *v5; // esi
  int v6; // eax
  unsigned int v7; // ecx
  int v9; // eax
  int v10; // edx
  int *i; // ecx

  v4 = node;
  while ( v4 >= 0 )
  {
    v5 = &dnodes[v4];
    v6 = BrushBspBoxOnPlaneSide(mins: vecMins, maxs: vecMaxs, plane: &dplanes[v5->planenum]);
    if ( v6 == 1 )
    {
      v4 = v5->children[0];
    }
    else
    {
      if ( v6 != 2 && IsBoxInsideWorld(node: v5->children[0], skipAreas, vecMins, vecMaxs) )
        return 1;
      v4 = v5->children[1];
    }
  }
  v7 = 16 * (-1 - v4);
  if ( (dleafs[v7 / 0x10].contents & 1) != 0 )
    return 0;
  v9 = skipAreas->m_Size - 1;
  if ( v9 >= 0 )
  {
    v10 = (__int16)(word_4BA35C6[v7] << 7) >> 7;
    for ( i = &skipAreas->m_Memory.m_pMemory[v9]; v10 != *i; --i )
    {
      if ( --v9 < 0 )
        return 1;
    }
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0042EAB0
// Name: void AddDispsToBounds(int,class CUtlVector<int,class CUtlMemory<int,int>> __near &,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddDispsToBounds(
        int nHeadNode,
        CUtlVector<int,CUtlMemory<int,int> > *skipAreas,
        Vector *vecMins,
        Vector *vecMaxs)
{
  int v4; // eax
  int v5; // eax
  dnode_t *v6; // esi
  int v7; // eax
  unsigned int v8; // ecx
  int v9; // eax
  int v10; // edx
  int *v11; // ecx
  Vector vecDispMaxs; // [esp+0h] [ebp-1Ch] BYREF
  Vector vecDispMins; // [esp+Ch] [ebp-10h] BYREF
  int i; // [esp+18h] [ebp-4h]

  v4 = 0;
  for ( i = 0; v4 < g_dispinfo.m_Size; i = v4 )
  {
    ComputeDispInfoBounds(dispinfo: v4, mins: &vecDispMins, maxs: &vecDispMaxs);
    v5 = nHeadNode;
    while ( v5 >= 0 )
    {
      v6 = &dnodes[v5];
      v7 = BrushBspBoxOnPlaneSide(mins: &vecDispMins, maxs: &vecDispMaxs, plane: &dplanes[v6->planenum]);
      if ( v7 == 1 )
      {
        v5 = v6->children[0];
      }
      else
      {
        if ( v7 != 2
          && IsBoxInsideWorld(node: v6->children[0], skipAreas, vecMins: &vecDispMins, vecMaxs: &vecDispMaxs) != 0 )
        {
          goto LABEL_14;
        }
        v5 = v6->children[1];
      }
    }
    v8 = 32 * (-1 - v5);
    if ( (dleafs[v8 / 0x20].contents & 1) == 0 )
    {
      v9 = skipAreas->m_Size - 1;
      if ( v9 < 0 )
      {
LABEL_14:
        AddPointToBounds(v: &vecDispMins, mins: vecMins, maxs: vecMaxs);
        AddPointToBounds(v: &vecDispMaxs, mins: vecMins, maxs: vecMaxs);
      }
      else
      {
        v10 = (__int16)(word_4BA35C6[v8 / 2] << 7) >> 7;
        v11 = &skipAreas->m_Memory.m_pMemory[v9];
        while ( v10 != *v11 )
        {
          --v11;
          if ( --v9 < 0 )
            goto LABEL_14;
        }
      }
    }
    v4 = i + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042EBC0
// Name: void ComputeBoundsNoSkybox(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeBoundsNoSkybox()
{
  int v0; // esi
  entity_t *i; // edi
  entity_t *v2; // esi
  char string[128]; // [esp+4h] [ebp-98h] BYREF
  Vector mins; // [esp+84h] [ebp-18h] BYREF
  Vector maxs; // [esp+90h] [ebp-Ch] BYREF

  ClearBounds(&mins, &maxs);
  AddNodeToBounds(node: nHeadNode, skipAreas: &g_SkyAreas, &mins, &maxs);
  AddDispsToBounds(nHeadNode: nHeadNode, skipAreas: &g_SkyAreas, vecMins: &mins, vecMaxs: &maxs);
  v0 = 0;
  if ( num_entities > 0 )
  {
    for ( i = (entity_t *)&entities; strcmp(ValueForKey(ent: i, key: "classname"), "worldspawn") != 0; ++i )
    {
      if ( ++v0 >= num_entities )
        return;
    }
    sprintf(string, format: "%i %i %i", (int)mins.x, (int)mins.y, (int)mins.z);
    v2 = (entity_t *)((char *)&entities + 44 * v0);
    SetKeyValue(ent: v2, key: "world_mins", value: string, bAllowDuplicates: false);
    sprintf(string, format: "%i %i %i", (int)maxs.x, (int)maxs.y, (int)maxs.z);
    SetKeyValue(ent: v2, key: "world_maxs", value: string, bAllowDuplicates: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042FE50
// Name: void BuildBrushListForFace(class CUtlVectorFixedGrowable<int,64> __near &,struct face_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildBrushListForFace(CUtlVectorFixedGrowable<int,64> *brushList, face_t *pFace)
{
  CUtlVectorFixedGrowable<int,64> *v2; // ebx
  int v3; // ecx
  int m_Size; // eax
  CUtlVector<side_t *,CUtlMemory<side_t *,int> > *pMergedList; // eax
  int v6; // ecx
  unsigned int v7; // esi
  int nummapbrushes; // edi
  int v9; // ecx
  int *p_numsides; // eax
  unsigned int v11; // edx
  unsigned __int16 v12; // ax
  int v13; // esi
  int v14; // ecx
  int v15; // eax
  int *m_pMemory; // edx
  int nAddBrush; // [esp+8h] [ebp-8h] BYREF
  int i; // [esp+Ch] [ebp-4h] BYREF

  v2 = brushList;
  v3 = (unsigned __int16)BrushIndexFromSide(pSide: pFace->originalface);
  m_Size = brushList->m_Size;
  i = v3;
  CUtlVector<int,CUtlMemoryFixedGrowable<int,64,int>>::InsertBefore(this: brushList, elem: m_Size, src: &i);
  pMergedList = pFace->pMergedList;
  if ( pMergedList != nullptr )
  {
    v6 = 0;
    for ( i = 0; v6 < pMergedList->m_Size; i = v6 )
    {
      v7 = (unsigned int)pMergedList->m_Memory.m_pMemory[v6];
      if ( *(_DWORD *)(v7 + 16) != 0 )
        v7 = *(_DWORD *)(v7 + 16);
      nummapbrushes = g_MainMap->nummapbrushes;
      v9 = 0;
      if ( nummapbrushes <= 0 )
      {
LABEL_10:
        v12 = -1;
      }
      else
      {
        p_numsides = &g_MainMap->mapbrushes[0].numsides;
        while ( 1 )
        {
          v11 = p_numsides[1];
          if ( v7 >= v11 )
          {
            v2 = brushList;
            if ( v7 < v11 + 92 * *p_numsides )
              break;
          }
          ++v9;
          p_numsides += 12;
          if ( v9 >= nummapbrushes )
            goto LABEL_10;
        }
        v12 = v9;
      }
      v13 = v12;
      nAddBrush = v12;
      if ( v12 != 0xFFFF )
      {
        v14 = v2->m_Size;
        v15 = 0;
        if ( v14 <= 0 )
        {
LABEL_16:
          CUtlVector<int,CUtlMemoryFixedGrowable<int,64,int>>::InsertBefore(this: v2, elem: v14, src: &nAddBrush);
        }
        else
        {
          m_pMemory = v2->m_Memory.m_pMemory;
          while ( v13 != *m_pMemory )
          {
            ++v15;
            ++m_pMemory;
            if ( v15 >= v14 )
              goto LABEL_16;
          }
        }
      }
      pMergedList = pFace->pMergedList;
      v6 = i + 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042FF50
// Name: void EmitFace(struct face_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EmitFace(int f, unsigned __int8 onNode)
{
  bool v3; // cc
  int v4; // eax
  dface_t *v5; // edi
  int v6; // ebx
  int m_Size; // eax
  int v8; // eax
  int v9; // ecx
  int OrigFace; // eax
  int v11; // edx
  int v12; // eax
  unsigned __int16 m_NumPrims; // cx
  unsigned __int16 v14; // ax
  unsigned __int16 v15; // ax
  int v16; // eax
  int *v17; // ebx
  int v18; // edi
  int v19; // eax
  side_t *v20; // esi
  CUtlVectorFixedGrowable<int,64> brushList; // [esp+4h] [ebp-118h] BYREF
  int nStart; // [esp+124h] [ebp+8h]
  int nStarta; // [esp+124h] [ebp+8h]

  v3 = *(_DWORD *)(f + 52) < 3;
  *(_DWORD *)(f + 44) = -1;
  if ( v3 || *(_DWORD *)(f + 8) != 0 || *(_DWORD *)(f + 12) != 0 || *(_DWORD *)(f + 16) != 0 )
    return;
  if ( SLOBYTE(texinfo.m_Memory.m_pMemory[*(_DWORD *)(f + 24)].flags) < 0 )
  {
    if ( *(_DWORD *)(f + 28) == -1 )
      return;
    _Warning(a1: "NODRAW on terrain surface!\n");
  }
  *(_DWORD *)(f + 44) = numfaces;
  v4 = numfaces;
  if ( numfaces >= 0x10000 )
  {
    _Error(a1: "Too many faces in map, max = %d", 0x10000);
    v4 = numfaces;
  }
  v5 = &dfaces[v4];
  CUtlVector<dfaceid_t,CUtlMemory<dfaceid_t,int>>::AddToTail(this: &dfaceids);
  dfaceids.m_Memory.m_pMemory[numfaces].hammerfaceid = *(_WORD *)(*(_DWORD *)(f + 188) + 40);
  v6 = CUtlVector<char *,CUtlMemory<char *,int>>::AddToTail(this: (CUtlVector<char *,CUtlMemory<char *,int> > *)&dfacebrushlists);
  brushList.m_Memory.m_nMallocGrowSize = 0;
  brushList.m_Size = 0;
  brushList.m_Memory.m_pMemory = brushList.m_Memory.m_pFixedMemory;
  brushList.m_Memory.m_nAllocationCount = 64;
  brushList.m_Memory.m_nGrowSize = -1;
  brushList.m_pElements = brushList.m_Memory.m_pFixedMemory;
  BuildBrushListForFace(&brushList, pFace: (face_t *)f);
  if ( brushList.m_Size == 1 )
  {
    dfacebrushlists.m_Memory.m_pMemory[v6].m_nFaceBrushCount = 1;
    dfacebrushlists.m_Memory.m_pMemory[v6].m_nFaceBrushStart = *(_WORD *)brushList.m_Memory.m_pMemory;
  }
  else
  {
    dfacebrushlists.m_Memory.m_pMemory[v6].m_nFaceBrushCount = brushList.m_Size;
    m_Size = dfacebrushes.m_Size;
    dfacebrushlists.m_Memory.m_pMemory[v6].m_nFaceBrushStart = dfacebrushes.m_Size;
    nStart = m_Size;
    CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertMultipleBefore(
      this: (CUtlVector<CDispTri,CUtlMemory<CDispTri,int> > *)&dfacebrushes,
      elem: dfacebrushes.m_Size,
      num: brushList.m_Size);
    v8 = 0;
    if ( brushList.m_Size > 0 )
    {
      v9 = nStart;
      do
        dfacebrushes.m_Memory.m_pMemory[v9++] = brushList.m_Memory.m_pMemory[v8++];
      while ( v8 < brushList.m_Size );
    }
  }
  ++numfaces;
  v5->planenum = *(_WORD *)(f + 36);
  v5->onNode = onNode;
  v5->side = *(_BYTE *)(f + 36) & 1;
  v5->texinfo = *(_WORD *)(f + 24);
  v5->dispinfo = *(_WORD *)(f + 28);
  v5->smoothingGroups = *(_DWORD *)(f + 200);
  if ( *(_DWORD *)(f + 188) == 0 )
    goto LABEL_19;
  OrigFace = FindOrigFace((face_t *)f);
  if ( OrigFace != -1 )
  {
    if ( OrigFace != -2 )
      goto LABEL_20;
LABEL_19:
    OrigFace = -1;
    goto LABEL_20;
  }
  OrigFace = CreateOrigFace((face_t *)f);
LABEL_20:
  v11 = numfaces;
  v5->origFace = OrigFace;
  v5->surfaceFogVolumeID = -1;
  v12 = numsurfedges;
  dword_4B63494[v11] = *(_DWORD *)(f + 32);
  v5->firstedge = v12;
  v5->numedges = *(_WORD *)(f + 52);
  if ( *(_DWORD *)(f + 48) != 0 )
    v5->area = WindingArea(w: *(winding_t **)(f + 48));
  else
    v5->area = 0.0;
  m_NumPrims = v5->m_NumPrims;
  v5->firstPrimID = *(_WORD *)(f + 192);
  v5->m_NumPrims ^= (*(_WORD *)(f + 196) ^ m_NumPrims) & 0x7FFF;
  v14 = v5->m_NumPrims;
  if ( *(_BYTE *)(*(_DWORD *)(f + 188) + 88) != 0 )
    v15 = v14 & 0x7FFF;
  else
    v15 = v14 | 0x8000;
  v5->m_NumPrims = v15;
  v16 = 0;
  if ( *(int *)(f + 52) > 0 )
  {
    v17 = (int *)(f + 60);
    do
    {
      v18 = v16 + 1;
      nStarta = GetEdge2(v1: *v17, v2: *(_DWORD *)(f + 4 * ((v16 + 1) % *(_DWORD *)(f + 52)) + 60), (face_t *)f);
      if ( numsurfedges >= 512000 )
        _Error(a1: "Too much brush geometry in bsp, numsurfedges == MAX_MAP_SURFEDGES");
      v19 = numsurfedges;
      dsurfedges[numsurfedges] = nStarta;
      numsurfedges = v19 + 1;
      v16 = v18;
      ++v17;
    }
    while ( v18 < *(_DWORD *)(f + 52) );
  }
  v20 = *(side_t **)(f + 188);
  if ( v20 != nullptr )
  {
    if ( v20->aOverlayIds.m_Size > 0 )
      Overlay_AddFaceToLists(iFace: numfaces - 1, pSide: v20);
    if ( v20->aWaterOverlayIds.m_Size > 0 )
      OverlayTransition_AddFaceToLists(iFace: numfaces - 1, pSide: v20);
  }
  CUtlVector<int,CUtlMemoryFixedGrowable<int,64,int>>::~CUtlVector<int,CUtlMemoryFixedGrowable<int,64,int>>(this: &brushList);
}

//------------------------------------------------------------------------------
// Address: 0x00430280
// Name: void EmitLeafFaces(struct face_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EmitLeafFaces(face_t *pLeafFaceList)
{
  face_t *v1; // esi
  bool v2; // cc
  int v3; // eax
  int v4; // edi
  int m_Size; // eax
  dface_t *v6; // edi
  int v7; // ebx
  dfaceid_t *m_pMemory; // ecx
  int v9; // eax
  int v10; // eax
  int v11; // ebx
  int v12; // eax
  int v13; // eax
  int v14; // eax
  face_t *v15; // ecx
  int OrigFace; // eax
  int v17; // ecx
  int v18; // edx
  unsigned __int16 m_NumPrims; // dx
  unsigned __int16 v20; // ax
  unsigned __int16 v21; // ax
  int v22; // eax
  int *vertexnums; // ebx
  int v24; // edi
  int v25; // eax
  side_t *originalface; // edi
  int *v27; // eax
  CUtlVectorFixedGrowable<int,64> brushList; // [esp+4h] [ebp-118h] BYREF
  face_t *pLeafFaceLista; // [esp+124h] [ebp+8h]
  face_t *pLeafFaceListb; // [esp+124h] [ebp+8h]

  v1 = pLeafFaceList;
  if ( pLeafFaceList != nullptr )
  {
    while ( 1 )
    {
      v2 = v1->numpoints < 3;
      v1->outputnumber = -1;
      if ( !v2 && v1->merged == nullptr && v1->split[0] == nullptr && v1->split[1] == nullptr )
      {
        if ( SLOBYTE(texinfo.m_Memory.m_pMemory[v1->texinfo].flags) >= 0 )
          goto LABEL_9;
        if ( v1->dispinfo != -1 )
          break;
      }
LABEL_52:
      v1 = v1->next;
      if ( v1 == nullptr )
        return;
    }
    _Warning(a1: "NODRAW on terrain surface!\n");
LABEL_9:
    v1->outputnumber = numfaces;
    v3 = numfaces;
    if ( numfaces >= 0x10000 )
    {
      _Error(a1: "Too many faces in map, max = %d", 0x10000);
      v3 = numfaces;
    }
    v4 = v3;
    m_Size = dfaceids.m_Size;
    v6 = &dfaces[v4];
    v7 = dfaceids.m_Size;
    if ( dfaceids.m_Size + 1 > dfaceids.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<CFaceMacroTextureInfo,int>::Grow(
        this: (CUtlMemory<unsigned short,int> *)&dfaceids,
        num: dfaceids.m_Size - dfaceids.m_Memory.m_nAllocationCount + 1);
      m_Size = dfaceids.m_Size;
    }
    m_pMemory = dfaceids.m_Memory.m_pMemory;
    dfaceids.m_Size = m_Size + 1;
    v9 = m_Size - v7;
    dfaceids.m_pElements = dfaceids.m_Memory.m_pMemory;
    if ( v9 > 0 )
    {
      _V_memmove(dest: &dfaceids.m_Memory.m_pMemory[v7 + 1], src: &dfaceids.m_Memory.m_pMemory[v7], count: 2 * v9);
      m_pMemory = dfaceids.m_Memory.m_pMemory;
    }
    m_pMemory[numfaces] = (dfaceid_t)v1->originalface->id;
    v10 = dfacebrushlists.m_Size;
    v11 = dfacebrushlists.m_Size;
    if ( dfacebrushlists.m_Size + 1 > dfacebrushlists.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<CClassInput *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&dfacebrushlists,
        num: dfacebrushlists.m_Size - dfacebrushlists.m_Memory.m_nAllocationCount + 1);
      v10 = dfacebrushlists.m_Size;
    }
    dfacebrushlists.m_Size = v10 + 1;
    v12 = v10 - v11;
    dfacebrushlists.m_pElements = dfacebrushlists.m_Memory.m_pMemory;
    if ( v12 > 0 )
      _V_memmove(
        dest: &dfacebrushlists.m_Memory.m_pMemory[v11 + 1],
        src: &dfacebrushlists.m_Memory.m_pMemory[v11],
        count: 4 * v12);
    brushList.m_Memory.m_nMallocGrowSize = 0;
    brushList.m_Size = 0;
    brushList.m_Memory.m_pMemory = brushList.m_Memory.m_pFixedMemory;
    brushList.m_Memory.m_nAllocationCount = 64;
    brushList.m_Memory.m_nGrowSize = -1;
    brushList.m_pElements = brushList.m_Memory.m_pFixedMemory;
    BuildBrushListForFace(&brushList, pFace: v1);
    if ( brushList.m_Size == 1 )
    {
      dfacebrushlists.m_Memory.m_pMemory[v11].m_nFaceBrushCount = 1;
      dfacebrushlists.m_Memory.m_pMemory[v11].m_nFaceBrushStart = *(_WORD *)brushList.m_Memory.m_pMemory;
    }
    else
    {
      dfacebrushlists.m_Memory.m_pMemory[v11].m_nFaceBrushCount = brushList.m_Size;
      v13 = dfacebrushes.m_Size;
      dfacebrushlists.m_Memory.m_pMemory[v11].m_nFaceBrushStart = dfacebrushes.m_Size;
      pLeafFaceLista = (face_t *)v13;
      CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertMultipleBefore(
        this: (CUtlVector<CDispTri,CUtlMemory<CDispTri,int> > *)&dfacebrushes,
        elem: dfacebrushes.m_Size,
        num: brushList.m_Size);
      v14 = 0;
      if ( brushList.m_Size > 0 )
      {
        v15 = (face_t *)(2 * (_DWORD)pLeafFaceLista);
        do
        {
          *(_WORD *)((char *)&v15->id + (unsigned int)dfacebrushes.m_Memory.m_pMemory) = brushList.m_Memory.m_pMemory[v14++];
          v15 = (face_t *)((char *)v15 + 2);
        }
        while ( v14 < brushList.m_Size );
      }
    }
    ++numfaces;
    v6->planenum = v1->planenum;
    v6->onNode = 0;
    v6->side = v1->planenum & 1;
    v6->texinfo = v1->texinfo;
    v6->dispinfo = v1->dispinfo;
    v6->smoothingGroups = v1->smoothingGroups;
    if ( v1->originalface != nullptr )
    {
      OrigFace = FindOrigFace(f: v1);
      if ( OrigFace == -1 )
      {
        OrigFace = CreateOrigFace(f: v1);
LABEL_29:
        v17 = numfaces;
        v6->surfaceFogVolumeID = -1;
        v18 = numsurfedges;
        v6->origFace = OrigFace;
        dword_4B63494[v17] = (int)v1->fogVolumeLeaf;
        v6->firstedge = v18;
        v6->numedges = v1->numpoints;
        if ( v1->w != nullptr )
          v6->area = WindingArea(w: v1->w);
        else
          v6->area = 0.0;
        m_NumPrims = v6->m_NumPrims;
        v6->firstPrimID = v1->firstPrimID;
        v6->m_NumPrims ^= (LOWORD(v1->numPrims) ^ m_NumPrims) & 0x7FFF;
        v20 = v6->m_NumPrims;
        if ( v1->originalface->m_bDynamicShadowsEnabled )
          v21 = v20 & 0x7FFF;
        else
          v21 = v20 | 0x8000;
        v6->m_NumPrims = v21;
        v22 = 0;
        if ( v1->numpoints > 0 )
        {
          vertexnums = v1->vertexnums;
          do
          {
            v24 = v22 + 1;
            pLeafFaceListb = (face_t *)GetEdge2(v1: *vertexnums, v2: v1->vertexnums[(v22 + 1) % v1->numpoints], f: v1);
            if ( numsurfedges >= 512000 )
              _Error(a1: "Too much brush geometry in bsp, numsurfedges == MAX_MAP_SURFEDGES");
            v25 = numsurfedges;
            dsurfedges[numsurfedges] = (int)pLeafFaceListb;
            numsurfedges = v25 + 1;
            v22 = v24;
            ++vertexnums;
          }
          while ( v24 < v1->numpoints );
        }
        originalface = v1->originalface;
        if ( originalface != nullptr )
        {
          if ( originalface->aOverlayIds.m_Size > 0 )
            Overlay_AddFaceToLists(iFace: numfaces - 1, pSide: v1->originalface);
          if ( originalface->aWaterOverlayIds.m_Size > 0 )
            OverlayTransition_AddFaceToLists(iFace: numfaces - 1, pSide: originalface);
        }
        v27 = brushList.m_Memory.m_pMemory;
        brushList.m_Size = 0;
        if ( brushList.m_Memory.m_nGrowSize >= 0 )
        {
          if ( brushList.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: brushList.m_Memory.m_pMemory);
            v27 = nullptr;
            brushList.m_Memory.m_pMemory = nullptr;
          }
          brushList.m_Memory.m_nAllocationCount = 0;
        }
        brushList.m_pElements = v27;
        if ( brushList.m_Memory.m_nGrowSize >= 0 && v27 != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v27);
        goto LABEL_52;
      }
      if ( OrigFace != -2 )
        goto LABEL_29;
    }
    OrigFace = -1;
    goto LABEL_29;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004306B0
// Name: int EmitDrawNode_r(struct node_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl EmitDrawNode_r(node_t *node)
{
  int v2; // esi
  dnode_t *v3; // esi
  unsigned __int16 v4; // ax
  face_t *faces; // ebx
  node_t **children; // edi
  int *v7; // ebx
  int nodea; // [esp+Ch] [ebp+8h]

  if ( node->planenum == -1 )
  {
    EmitLeaf(node);
    return -numleafs;
  }
  else
  {
    if ( numnodes == 0x10000 )
      _Error(a1: "MAX_MAP_NODES");
    node->diskId = numnodes;
    v2 = numnodes++;
    v3 = &dnodes[v2];
    v3->mins[0] = (int)node->mins.x;
    v3->mins[1] = (int)node->mins.y;
    v3->mins[2] = (int)node->mins.z;
    v3->maxs[0] = (int)node->maxs.x;
    v3->maxs[1] = (int)node->maxs.y;
    v3->maxs[2] = (int)node->maxs.z;
    if ( (node->planenum & 1) != 0 )
      _Error(a1: "WriteDrawNodes_r: odd planenum");
    v4 = numfaces;
    v3->planenum = node->planenum;
    v3->firstface = v4;
    v3->area = node->area;
    if ( node->faces != nullptr )
      ++c_facenodes;
    else
      ++c_nofaces;
    faces = node->faces;
    if ( faces != nullptr )
    {
      do
      {
        EmitFace(f: (int)faces, onNode: 1u);
        faces = faces->next;
      }
      while ( faces != nullptr );
      v4 = numfaces;
    }
    children = node->children;
    v3->numfaces = v4 - v3->firstface;
    v7 = v3->children;
    for ( nodea = 2; nodea != 0; --nodea )
    {
      if ( (*children)->planenum == -1 )
      {
        *v7 = -1 - numleafs;
        EmitLeaf(node: *children);
      }
      else
      {
        *v7 = numnodes;
        EmitDrawNode_r(node: *children);
      }
      ++v7;
      ++children;
    }
    return v3 - dnodes;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00430800
// Name: void WriteBSP(struct node_t __near *,struct face_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl WriteBSP(node_t *headnode, face_t *pLeafFaceList)
{
  int v2; // edi
  int v3; // eax
  int v4; // ecx
  mapdispinfo_t *v5; // esi
  int oldorigfaces; // [esp+8h] [ebp-8h]
  int oldfaces; // [esp+Ch] [ebp-4h]

  v2 = 0;
  c_nofaces = 0;
  c_facenodes = 0;
  qprintf(format: "--- WriteBSP ---\n");
  oldfaces = numfaces;
  oldorigfaces = numorigfaces;
  GetEdge2_InitOptimizedList();
  EmitLeafFaces(pLeafFaceList);
  v3 = EmitDrawNode_r(node: headnode);
  v4 = nummodels;
  *(&nHeadNode + 12 * nummodels) = v3;
  if ( v4 == 0 )
  {
    EmitAreaPortals(headnode);
    v4 = nummodels;
  }
  if ( nummapdispinfo > 0 )
  {
    v5 = (mapdispinfo_t *)&mapdispinfo;
    do
    {
      if ( GetDispInfoEntityNum(pDisp: v5) == entity_num )
      {
        EmitFaceVertexes(pListHead: nullptr, f: &v5->face);
        EmitFace(f: (int)v5, onNode: 0);
      }
      ++v2;
      ++v5;
    }
    while ( v2 < nummapdispinfo );
    v4 = nummodels;
  }
  EmitWaterVolumesForBSP(pModel: &dmodels[v4], node: headnode);
  qprintf(format: "%5i nodes with faces\n", c_facenodes);
  qprintf(format: "%5i nodes without faces\n", c_nofaces);
  qprintf(format: "%5i faces\n", numfaces - oldfaces);
  qprintf(format: "%5i original faces\n", numorigfaces - oldorigfaces);
}

//------------------------------------------------------------------------------
// Address: 0x00430920
// Name: void ComapctTexinfoArray(struct texinfomap_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComapctTexinfoArray(texinfomap_t *pMap)
{
  int m_Size; // esi
  texinfo_s *m_pMemory; // edi
  texinfo_s *i; // ebx
  texinfo_s *v4; // eax
  int v5; // edx
  char *v6; // esi
  texinfo_s *v7; // edi
  int v8; // ecx
  texinfo_s *v9; // esi
  int *p_outputIndex; // edi
  int flags; // eax
  int v12; // eax
  CUtlVector<texinfo_s,CUtlMemory<texinfo_s,int> > old; // [esp+Ch] [ebp-1Ch] BYREF
  int firstSky; // [esp+20h] [ebp-8h]
  int first2DSky; // [esp+24h] [ebp-4h]

  m_Size = texinfo.m_Size;
  m_pMemory = texinfo.m_Memory.m_pMemory;
  i = nullptr;
  memset(&old, 0, sizeof(old));
  CUtlVector<texinfo_s,CUtlMemory<texinfo_s,int>>::InsertMultipleBefore(this: &old, elem: 0, num: texinfo.m_Size);
  if ( m_Size > 0 )
  {
    v4 = old.m_Memory.m_pMemory;
    v5 = (char *)m_pMemory - (char *)old.m_Memory.m_pMemory;
    for ( i = (texinfo_s *)m_Size; i != nullptr; i = (texinfo_s *)((char *)i - 1) )
    {
      v6 = (char *)v4 + v5;
      v7 = v4++;
      qmemcpy(v7, v6, sizeof(texinfo_s));
    }
  }
  firstSky = -1;
  first2DSky = -1;
  v8 = 0;
  texinfo.m_Size = 0;
  if ( old.m_Size > (int)i )
  {
    v9 = old.m_Memory.m_pMemory;
    p_outputIndex = &pMap->outputIndex;
    i = (texinfo_s *)old.m_Size;
    while ( 1 )
    {
      if ( *(p_outputIndex - 1) == 0 )
      {
        *p_outputIndex = -1;
        goto LABEL_19;
      }
      flags = v9->flags;
      if ( (flags & 2) != 0 )
        break;
      if ( (flags & 4) == 0 )
      {
        v12 = CUtlVector<texinfo_s,CUtlMemory<texinfo_s,int>>::InsertBefore(this: &texinfo, elem: v8, src: v9);
LABEL_18:
        *p_outputIndex = v12;
        goto LABEL_19;
      }
      if ( firstSky < 0 )
        firstSky = CUtlVector<texinfo_s,CUtlMemory<texinfo_s,int>>::InsertBefore(this: &texinfo, elem: v8, src: v9);
      *p_outputIndex = firstSky;
LABEL_19:
      ++v9;
      p_outputIndex += 2;
      i = (texinfo_s *)((char *)i - 1);
      if ( i == nullptr )
        goto LABEL_20;
      v8 = texinfo.m_Size;
    }
    if ( first2DSky < 0 )
      first2DSky = CUtlVector<texinfo_s,CUtlMemory<texinfo_s,int>>::InsertBefore(this: &texinfo, elem: v8, src: v9);
    v12 = first2DSky;
    goto LABEL_18;
  }
LABEL_20:
  if ( old.m_Memory.m_nGrowSize >= (int)i && old.m_Memory.m_pMemory != i )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: old.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00430BE0
// Name: public: int CUtlMap<char const __near *,int,int>::Insert(char const __near * const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlMap<char const *,int,int>::Insert(CUtlMap<char const *,int,int> *this, const char **key, int insert)
{
  int v4; // eax
  int v5; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *m_pMemory; // ecx
  CUtlMap<char const *,int,int>::Node_t node; // [esp+8h] [ebp-8h] BYREF

  v4 = *(_DWORD *)insert;
  node.key = *key;
  node.elem = v4;
  insert = -1;
  LOBYTE(key) = 0;
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FindInsertionPosition(
    this: &this->m_Tree,
    insert: &node,
    parent: &insert,
    leftchild: (bool *)&key);
  v5 = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::NewNode(this: &this->m_Tree);
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::LinkToParent(
    this: &this->m_Tree,
    i: v5,
    parent: insert,
    isLeft: (bool)key);
  m_pMemory = this->m_Tree.m_Elements.m_pMemory;
  ++this->m_Tree.m_NumElements;
  if ( &m_pMemory[v5] != (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)-16 )
    m_pMemory[v5].m_Data = node;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00430C60
// Name: void CompactTexdataArray(struct texdatamap_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CompactTexdataArray(texdatamap_t *pMap)
{
  int m_Size; // esi
  int *m_pMemory; // edi
  int *v3; // eax
  int v4; // ecx
  int *p_nameStringTableID; // esi
  int *p_outputIndex; // edi
  int *v7; // eax
  int String; // eax
  unsigned int v9; // ecx
  int v10; // edx
  CUtlVector<char,CUtlMemory<char,int> > oldStringData; // [esp+Ch] [ebp-40h] BYREF
  CUtlVector<int,CUtlMemory<int,int> > oldStringTable; // [esp+20h] [ebp-2Ch] BYREF
  CUtlVector<dtexdata_t,CUtlMemory<dtexdata_t,int> > oldTexData; // [esp+34h] [ebp-18h] BYREF
  int i; // [esp+48h] [ebp-4h]

  memset(&oldStringData, 0, sizeof(oldStringData));
  CUtlVector<char,CUtlMemory<char,int>>::CopyArray(
    this: &oldStringData,
    pArray: g_TexDataStringData.m_Memory.m_pMemory,
    size: g_TexDataStringData.m_Size);
  m_Size = g_TexDataStringTable.m_Size;
  m_pMemory = g_TexDataStringTable.m_Memory.m_pMemory;
  g_TexDataStringData.m_Size = 0;
  memset(&oldStringTable, 0, sizeof(oldStringTable));
  CUtlVector<dfacebrushlist_t,CUtlMemory<dfacebrushlist_t,int>>::InsertMultipleBefore(
    this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&oldStringTable,
    elem: 0,
    num: g_TexDataStringTable.m_Size);
  if ( m_Size > 0 )
  {
    v3 = oldStringTable.m_Memory.m_pMemory;
    v4 = (char *)m_pMemory - (char *)oldStringTable.m_Memory.m_pMemory;
    do
    {
      *v3 = *(int *)((char *)v3 + v4);
      ++v3;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
  g_TexDataStringTable.m_Size = 0;
  memset(&oldTexData, 0, sizeof(oldTexData));
  CUtlVector<dtexdata_t,CUtlMemory<dtexdata_t,int>>::CopyArray(this: &oldTexData, pArray: dtexdata, size: numtexdata);
  numtexdata = 0;
  if ( oldTexData.m_Size > 0 )
  {
    p_nameStringTableID = &oldTexData.m_Memory.m_pMemory->nameStringTableID;
    p_outputIndex = &pMap->outputIndex;
    for ( i = oldTexData.m_Size; i != 0; --i )
    {
      if ( *(p_outputIndex - 1) != 0 )
      {
        v7 = oldStringTable.m_Memory.m_pMemory;
        *p_outputIndex = numtexdata;
        String = TexDataStringTable_AddOrFindString(pString: &oldStringData.m_Memory.m_pMemory[v7[*p_nameStringTableID]]);
        v9 = 8 * numtexdata;
        dtexdata[v9 / 8].reflectivity.x = *((float *)p_nameStringTableID - 3);
        flt_731593C[v9] = *((float *)p_nameStringTableID - 2);
        flt_7315940[v9] = *((float *)p_nameStringTableID - 1);
        dword_7315944[v9] = *p_nameStringTableID;
        dword_7315948[v9] = p_nameStringTableID[1];
        dword_731594C[v9] = p_nameStringTableID[2];
        dword_7315950[v9] = p_nameStringTableID[3];
        v10 = p_nameStringTableID[4];
        ++numtexdata;
        dword_7315954[v9] = v10;
        dword_7315944[v9] = String;
      }
      else
      {
        *p_outputIndex = -1;
      }
      p_outputIndex += 2;
      p_nameStringTableID += 8;
    }
  }
  if ( oldTexData.m_Memory.m_nGrowSize >= 0 && oldTexData.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: oldTexData.m_Memory.m_pMemory);
  if ( oldStringTable.m_Memory.m_nGrowSize >= 0 && oldStringTable.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: oldStringTable.m_Memory.m_pMemory);
  if ( oldStringData.m_Memory.m_nGrowSize >= 0 && oldStringData.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: oldStringData.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00430E10
// Name: void CompactTexinfos(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CompactTexinfos()
{
  unsigned __int8 *v0; // esi
  unsigned __int8 *v1; // ebx
  int v2; // ecx
  __int16 *p_texinfo; // edx
  __int16 *v4; // edx
  int v5; // eax
  int *p_texdata; // ecx
  bool v7; // zf
  unsigned __int8 *v8; // eax
  int v9; // ecx
  __int16 *p_nTexInfo; // edx
  int v11; // ecx
  __int16 *p_surfaceTexInfoID; // edx
  int v13; // edx
  dworldlight_t *v14; // eax
  int v15; // ecx
  int v16; // ecx
  __int16 *v17; // edx
  int m_Size; // eax
  int v19; // ecx
  int v20; // edx
  int v21; // ecx
  int v22; // eax
  int v23; // ecx
  __int16 *v24; // eax
  int v25; // ecx
  int j; // eax
  int v27; // ecx
  __int16 *v28; // eax
  int v29; // edx
  __int16 *v30; // eax
  int v31; // edx
  dworldlight_t *v32; // ecx
  int v33; // eax
  int v34; // edx
  __int16 *v35; // eax
  int oldCount; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]
  int ia; // [esp+10h] [ebp-8h]
  int oldTexdataCount; // [esp+14h] [ebp-4h]
  int oldTexdataCounta; // [esp+14h] [ebp-4h]

  _Msg(a1: "Compacting texture/material tables...\n");
  v0 = (unsigned __int8 *)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)texinfo.m_Size >> 29 != 0 ? -1 : 8 * texinfo.m_Size);
  v1 = (unsigned __int8 *)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)numtexdata >> 29 != 0 ? -1 : 8 * numtexdata);
  oldTexdataCount = (int)v1;
  memset(dst: v0, value: 0, count: 8 * texinfo.m_Size);
  memset(dst: v1, value: 0, count: 8 * numtexdata);
  v2 = 0;
  if ( numfaces > 0 )
  {
    p_texinfo = &dfaces[0].texinfo;
    do
    {
      ++*(_DWORD *)&v0[8 * *p_texinfo];
      ++v2;
      p_texinfo += 28;
    }
    while ( v2 < numfaces );
  }
  i = 0;
  if ( numbrushsides > 0 )
  {
    v4 = word_52B500A;
    do
    {
      if ( *(_DWORD *)&v0[8 * *v4] == 0 )
      {
        v5 = 0;
        if ( texinfo.m_Size <= 0 )
        {
LABEL_13:
          LOWORD(v5) = *v4;
        }
        else
        {
          p_texdata = &texinfo.m_Memory.m_pMemory->texdata;
          while ( *(int *)&v0[8 * v5] <= 0
               || *(p_texdata - 1) != texinfo.m_Memory.m_pMemory[*v4].flags
               || g_SurfaceProperties[*p_texdata] != g_SurfaceProperties[texinfo.m_Memory.m_pMemory[*v4].texdata] )
          {
            ++v5;
            p_texdata += 18;
            if ( v5 >= texinfo.m_Size )
              goto LABEL_13;
          }
        }
        v1 = (unsigned __int8 *)oldTexdataCount;
        *v4 = v5;
        v7 = *(_DWORD *)&v0[8 * (__int16)v5] == 0;
        v8 = &v0[8 * (__int16)v5];
        if ( v7 )
          ++*(_DWORD *)v8;
      }
      v4 += 4;
      ++i;
    }
    while ( i < numbrushsides );
  }
  v9 = 0;
  if ( g_nOverlayCount > 0 )
  {
    p_nTexInfo = &g_Overlays[0].nTexInfo;
    do
    {
      ++*(_DWORD *)&v0[8 * *p_nTexInfo];
      ++v9;
      p_nTexInfo += 176;
    }
    while ( v9 < g_nOverlayCount );
  }
  v11 = 0;
  if ( numleafwaterdata > 0 )
  {
    p_surfaceTexInfoID = &dleafwaterdata[0].surfaceTexInfoID;
    do
    {
      if ( *p_surfaceTexInfoID >= 0 )
        ++*(_DWORD *)&v0[8 * *p_surfaceTexInfoID];
      ++v11;
      p_surfaceTexInfoID += 6;
    }
    while ( v11 < numleafwaterdata );
  }
  v13 = 0;
  if ( *pNumworldlights > 0 )
  {
    v14 = dworldlights;
    v15 = 0;
    do
    {
      if ( v14[v15].texinfo >= 0 )
      {
        ++*(_DWORD *)&v0[8 * v14[v15].texinfo];
        v14 = dworldlights;
      }
      ++v13;
      ++v15;
    }
    while ( v13 < *pNumworldlights );
  }
  v16 = 0;
  if ( g_nWaterOverlayCount > 0 )
  {
    v17 = &g_WaterOverlays[0].nTexInfo;
    do
    {
      if ( *v17 >= 0 )
        ++*(_DWORD *)&v0[8 * *v17];
      ++v16;
      v17 += 560;
    }
    while ( v16 < g_nWaterOverlayCount );
  }
  m_Size = texinfo.m_Size;
  v19 = 0;
  if ( texinfo.m_Size > 0 )
  {
    v20 = 0;
    do
    {
      if ( *(int *)&v0[8 * v19] > 0 )
        ++*(_DWORD *)&v1[8 * texinfo.m_Memory.m_pMemory[v20].texdata];
      m_Size = texinfo.m_Size;
      ++v19;
      ++v20;
    }
    while ( v19 < texinfo.m_Size );
  }
  oldCount = m_Size;
  oldTexdataCounta = numtexdata;
  ia = g_TexDataStringData.m_Size;
  ComapctTexinfoArray(pMap: (texinfomap_t *)v0);
  CompactTexdataArray(pMap: (texdatamap_t *)v1);
  v21 = 0;
  if ( texinfo.m_Size > 0 )
  {
    v22 = 0;
    do
    {
      texinfo.m_Memory.m_pMemory[v22].texdata = *(_DWORD *)&v1[8 * texinfo.m_Memory.m_pMemory[v22].texdata + 4];
      ++v21;
      ++v22;
    }
    while ( v21 < texinfo.m_Size );
  }
  v23 = numfaces;
  if ( numfaces > 0 )
  {
    v24 = &dfaces[0].texinfo;
    do
    {
      *v24 = *(_WORD *)&v0[8 * *v24 + 4];
      v24 += 28;
      --v23;
    }
    while ( v23 != 0 );
  }
  v25 = numbrushsides;
  for ( j = 0; j < v25; ++j )
    word_52B500A[4 * j] = *(_WORD *)&v0[8 * word_52B500A[4 * j] + 4];
  v27 = g_nOverlayCount;
  if ( g_nOverlayCount > 0 )
  {
    v28 = &g_Overlays[0].nTexInfo;
    do
    {
      *v28 = *(_WORD *)&v0[8 * *v28 + 4];
      v28 += 176;
      --v27;
    }
    while ( v27 != 0 );
  }
  v29 = numleafwaterdata;
  if ( numleafwaterdata > 0 )
  {
    v30 = &dleafwaterdata[0].surfaceTexInfoID;
    do
    {
      if ( *v30 >= 0 )
        *v30 = *(_WORD *)&v0[8 * *v30 + 4];
      v30 += 6;
      --v29;
    }
    while ( v29 != 0 );
  }
  v31 = 0;
  if ( *pNumworldlights > 0 )
  {
    v32 = dworldlights;
    v33 = 0;
    do
    {
      if ( v32[v33].texinfo >= 0 )
      {
        v32[v33].texinfo = *(_DWORD *)&v0[8 * v32[v33].texinfo + 4];
        v32 = dworldlights;
      }
      ++v31;
      ++v33;
    }
    while ( v31 < *pNumworldlights );
  }
  v34 = g_nWaterOverlayCount;
  if ( g_nWaterOverlayCount > 0 )
  {
    v35 = &g_WaterOverlays[0].nTexInfo;
    do
    {
      if ( *v35 >= 0 )
        *v35 = *(_WORD *)&v0[8 * *v35 + 4];
      v35 += 560;
      --v34;
    }
    while ( v34 != 0 );
  }
  _Msg(a1: "Reduced %d texinfos to %d\n", oldCount, texinfo.m_Size);
  _Msg(a1: "Reduced %d texdatas to %d (%d bytes to %d)\n", oldTexdataCounta, numtexdata, ia, g_TexDataStringData.m_Size);
  free(pMem: v0);
  free(pMem: v1);
}

//------------------------------------------------------------------------------
// Address: 0x004311E0
// Name: public: int CUtlDict<int,int>::Insert(char const __near *,int const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<int,int>::Insert(CUtlDict<int,int> *this, char *pName, const int *element)
{
  const char *v3; // edi
  char *v5; // eax

  v3 = pName;
  if ( pName != nullptr && (v5 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v5, v3);
  else
    v5 = nullptr;
  pName = v5;
  return CUtlMap<char const *,int,int>::Insert(
           this: &this->m_Elements,
           key: (const char **)&pName,
           insert: (int)element);
}

//------------------------------------------------------------------------------
// Address: 0x00431240
// Name: void DiscoverMacroTextures(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DiscoverMacroTextures()
{
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *m_pMemory; // ebx
  int v1; // edi
  __int16 *p_texinfo; // ebx
  int texdata; // eax
  IMaterial *Material; // eax
  const char *MaterialVar; // eax
  char *v6; // esi
  int i; // esi
  CUtlDict<int,int> tempDict; // [esp+Ch] [ebp-30h] BYREF
  CUtlMap<char const *,int,int>::Node_t search; // [esp+30h] [ebp-Ch] BYREF
  int element; // [esp+38h] [ebp-4h] BYREF

  tempDict.m_Elements.m_Tree.m_Root = -1;
  tempDict.m_Elements.m_Tree.m_FirstFree = -1;
  tempDict.m_Elements.m_Tree.m_LastAlloc.index = -1;
  m_pMemory = nullptr;
  memset(&tempDict.m_Elements.m_Tree.m_Elements, 0, sizeof(tempDict.m_Elements.m_Tree.m_Elements));
  tempDict.m_Elements.m_Tree.m_NumElements = 0;
  tempDict.m_Elements.m_Tree.m_pElements = nullptr;
  tempDict.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  g_FaceMacroTextureInfos.m_Size = 0;
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertMultipleBefore(
    this: (CUtlVector<CDispTri,CUtlMemory<CDispTri,int> > *)&g_FaceMacroTextureInfos,
    elem: 0,
    num: numfaces);
  v1 = 0;
  if ( numfaces > 0 )
  {
    p_texinfo = &dfaces[0].texinfo;
    do
    {
      texdata = texinfo.m_Memory.m_pMemory[*p_texinfo].texdata;
      if ( texdata >= 0 )
      {
        Material = FindMaterial(
                     materialName: &g_TexDataStringData.m_Memory.m_pMemory[g_TexDataStringTable.m_Memory.m_pMemory[dword_7315944[8 * texdata]]],
                     pFound: nullptr,
                     bComplain: false);
        MaterialVar = GetMaterialVar(materialHandle: Material, propertyName: "$macro_texture");
        v6 = (char *)MaterialVar;
        if ( MaterialVar != nullptr )
        {
          search.key = MaterialVar;
          if ( CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
                 this: &tempDict.m_Elements.m_Tree,
                 &search) == -1 )
          {
            _Msg(a1: "-- DiscoverMacroTextures: %s\n", v6);
            element = 0;
            CUtlDict<int,int>::Insert(this: &tempDict, pName: v6, &element);
          }
          g_FaceMacroTextureInfos.m_Memory.m_pMemory[v1].m_MacroTextureNameID = TexDataStringTable_AddOrFindString(pString: v6);
        }
        else
        {
          g_FaceMacroTextureInfos.m_Memory.m_pMemory[v1].m_MacroTextureNameID = -1;
        }
      }
      ++v1;
      p_texinfo += 28;
    }
    while ( v1 < numfaces );
    m_pMemory = tempDict.m_Elements.m_Tree.m_Elements.m_pMemory;
  }
  for ( i = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FirstInorder(this: &tempDict.m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::NextInorder(
              this: &tempDict.m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RemoveAll(this: &tempDict.m_Elements.m_Tree);
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RemoveAll(this: &tempDict.m_Elements.m_Tree);
  if ( tempDict.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0
    && tempDict.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tempDict.m_Elements.m_Tree.m_Elements.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004313F0
// Name: void EndBSPFile(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall EndBSPFile(int a1@<ebx>, int a2@<edi>)
{
  char v2; // cf
  unsigned int v3; // ecx
  unsigned __int16 *v4; // edi
  int i; // ecx
  char targetPath[1024]; // [esp+0h] [ebp-400h] BYREF

  EmitBrushes();
  EmitPlanes();
  SaveVertexNormals();
  UpdateAllFaceLightmapExtents();
  EmitDispLMAlphaAndNeighbors();
  Overlay_EmitOverlayFaces();
  OverlayTransition_EmitOverlayFaces();
  EmitPhysCollision(a1: a2);
  if ( numleafs > 0 )
  {
    v2 = numleafs & 1;
    v3 = (unsigned int)numleafs >> 1;
    memset(g_LeafMinDistToWater, 0, 4 * ((unsigned int)numleafs >> 1));
    v4 = &g_LeafMinDistToWater[2 * v3];
    for ( i = v2; i != 0; --i )
      *v4++ = 0;
  }
  EmitStaticProps();
  EmitDetailObjects();
  ComputeBoundsNoSkybox();
  EnsurePresenceOfWaterLODControlEntity();
  UnparseEntities();
  CompactTexinfos();
  DiscoverMacroTextures();
  GetPlatformMapPath(pMapPath: source, pPlatformMapPath: targetPath, dxlevel: 0, maxLength: 1024);
  _Msg(a1: "Writing %s\n", targetPath);
  WriteBSPFile(a1, filename: targetPath);
}
