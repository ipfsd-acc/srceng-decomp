// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vmap/writebsp.cpp
// Functions: 47
// ============================================================

#include "utils\vmap\writebsp.h"

//------------------------------------------------------------------------------
// Address: 0x004362F0
// Name: bool StringLessThan(char const __near * const __near &,char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl StringLessThan(const char **lhs, const char **rhs)
{
  int v3; // kr00_4

  if ( *lhs == nullptr )
    return false;
  if ( *rhs == nullptr )
    return true;
  v3 = strcmp(*lhs, *rhs);
  return v3 != 0 && -(v3 < 0) - ((v3 < 0) - 1) < 0;
}

//------------------------------------------------------------------------------
// Address: 0x00436350
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
// Address: 0x00436380
// Name: public: void dface_t::SetDynamicShadowsEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall dface_t::SetDynamicShadowsEnabled(dface_t *this, bool bEnabled)
{
  if ( bEnabled )
    this->m_NumPrims &= ~0x8000u;
  else
    this->m_NumPrims |= 0x8000u;
}

//------------------------------------------------------------------------------
// Address: 0x004363B0
// Name: void EmitPlanes(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EmitPlanes()
{
  int v0; // edx
  int v1; // ebx
  int v2; // esi
  Vector *v3; // ecx
  dplane_t *v4; // eax
  int y_low; // edi
  int v6; // edi
  int v7; // edi
  int v8; // edi
  float *p_z; // ecx
  float *v10; // eax
  _DWORD *v11; // edi
  int v12; // ebx
  int v13; // esi
  _DWORD v14[65536]; // [esp+Ch] [ebp-40000h] BYREF

  v0 = numplanes;
  v1 = nummapplanes;
  v2 = 0;
  v3 = &mapplanes;
  if ( nummapplanes >= 4 )
  {
    v4 = &dplanes[numplanes];
    do
    {
      y_low = LODWORD(v3[1].y);
      v4->normal.x = v3->x;
      v4->normal.y = v3->y;
      v2 += 4;
      v4->normal.z = v3->z;
      v0 += 4;
      v4 += 4;
      v4[-4].dist = v3[1].x;
      v4[-4].type = y_low;
      v6 = LODWORD(v3[3].y);
      v4[-3].normal.x = v3[2].x;
      v3 += 8;
      v4[-3].normal.y = v3[-6].y;
      v4[-3].normal.z = v3[-6].z;
      v4[-3].dist = v3[-5].x;
      v4[-3].type = v6;
      v7 = LODWORD(v3[-3].y);
      v4[-2].normal.x = v3[-4].x;
      v4[-2].normal.y = v3[-4].y;
      v4[-2].normal.z = v3[-4].z;
      v4[-2].dist = v3[-3].x;
      v4[-2].type = v7;
      v8 = LODWORD(v3[-1].y);
      v4[-1].normal.x = v3[-2].x;
      v4[-1].normal.y = v3[-2].y;
      v4[-1].normal.z = v3[-2].z;
      v4[-1].dist = v3[-1].x;
      v4[-1].type = v8;
    }
    while ( v2 < v1 - 3 );
    numplanes = v0;
  }
  if ( v2 < v1 )
  {
    p_z = &v3->z;
    v10 = (float *)((char *)&unk_5FBBA08 + 20 * v0);
    v11 = &v14[v2];
    v12 = v1 - v2;
    do
    {
      v13 = *((_DWORD *)p_z + 2);
      *(v10 - 2) = *(p_z - 2);
      *((_DWORD *)v10 + 2) = v13;
      ++v0;
      *(v10 - 1) = *(p_z - 1);
      ++v11;
      v10 += 5;
      *(v10 - 5) = *p_z;
      p_z += 6;
      --v12;
      *(v10 - 4) = *(p_z - 5);
    }
    while ( v12 != 0 );
    numplanes = v0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004364D0
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
        while ( eIndex[0] != (unsigned __int16)word_374A4EA[2 * v16]
             || v17 != dedges[v16].v[0]
             || edgefaces[v16][0]->contents != f->contents
             || dword_1C68A34[2 * v16] != 0 )
        {
          if ( ++v16 >= v15 )
            goto LABEL_23;
        }
        dword_1C68A34[2 * v16] = (int)f;
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
// Address: 0x00436720
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
// Address: 0x00436780
// Name: int FindOrCreateOrigFace(struct face_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindOrCreateOrigFace(face_t *f)
{
  int result; // eax
  face_t *v2; // edx

  if ( f->originalface == nullptr )
    return -1;
  result = FindOrigFace(f);
  if ( result == -1 )
    return CreateOrigFace(f: v2);
  if ( result == -2 )
    return -1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004367C0
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
// Address: 0x004367F0
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
          sprintf(string: value, format: var);
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
// Address: 0x00436870
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
// Address: 0x004369F0
// Name: void EmitBrushes(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EmitBrushes()
{
  int v0; // eax
  dbrush_t *v1; // edx
  side_t **p_original_sides; // esi
  int v3; // ecx
  int v4; // ebx
  int v5; // edi
  side_t *v6; // esi
  dbrushside_t *v7; // ecx
  __int16 texinfo; // dx
  unsigned int *v9; // esi
  int v10; // ebx
  int i; // edi
  unsigned int dist; // xmm0_4
  int FloatPlane; // eax
  int v14; // ecx
  int v15; // esi
  int v16; // eax
  side_t *v17; // edx
  bool v18; // zf
  Vector normal; // [esp+10h] [ebp-1Ch] BYREF
  int bnum; // [esp+1Ch] [ebp-10h]
  dbrush_t *v21; // [esp+20h] [ebp-Ch]
  unsigned int *v22; // [esp+24h] [ebp-8h]
  side_t **v23; // [esp+28h] [ebp-4h]

  v0 = 0;
  numbrushsides = 0;
  numbrushes = nummapbrushes;
  bnum = 0;
  if ( nummapbrushes > 0 )
  {
    v1 = dbrushes;
    p_original_sides = &mapbrushes[0].original_sides;
    v21 = dbrushes;
    v23 = &mapbrushes[0].original_sides;
    while ( 1 )
    {
      v1->contents = (int)*(p_original_sides - 8);
      v3 = (int)*(p_original_sides - 1);
      v4 = 0;
      v1->firstside = v0;
      v1->numsides = v3;
      if ( v3 > 0 )
      {
        v5 = 0;
        do
        {
          if ( v0 == 0x10000 )
          {
            _Error(a1: "MAX_MAP_BRUSHSIDES");
            v0 = numbrushsides;
          }
          v6 = *p_original_sides;
          v7 = &dbrushsides[v0++];
          numbrushsides = v0;
          v7->planenum = v6[v5].planenum;
          texinfo = v6[v5].texinfo;
          v7->texinfo = texinfo;
          if ( texinfo == -1 )
            v7->texinfo = g_ClipTexinfo;
          v7->bevel = v6[v5].bevel;
          ++v4;
          ++v5;
          p_original_sides = v23;
        }
        while ( v4 < (int)*(v23 - 1) );
      }
      v9 = (unsigned int *)(p_original_sides - 4);
      v10 = 0;
      v22 = v9;
      for ( i = -1; ; i = -1 )
      {
        while ( 1 )
        {
          normal = vec3_origin;
          *(&normal.x + v10) = (float)i;
          if ( i == -1 )
            dist = *(v9 - 3) ^ _mask__NegFloat_;
          else
            dist = *v9;
          FloatPlane = FindFloatPlane(&normal, dist);
          v14 = (int)*(v23 - 1);
          v15 = FloatPlane;
          v16 = 0;
          if ( v14 > 0 )
          {
            v17 = *v23;
            do
            {
              if ( v17->planenum == v15 )
                break;
              ++v16;
              ++v17;
            }
            while ( v16 < v14 );
          }
          v18 = v16 == v14;
          v0 = numbrushsides;
          if ( v18 )
          {
            if ( numbrushsides >= 0x10000 )
            {
              _Error(a1: "MAX_MAP_BRUSHSIDES");
              v0 = numbrushsides;
            }
            dbrushsides[v0].planenum = v15;
            word_3C37F32[4 * v0] = word_3C37F2A[4 * v0];
            ++v0;
            ++v21->numsides;
            numbrushsides = v0;
          }
          i += 2;
          if ( i > 1 )
            break;
          v9 = v22;
        }
        ++v22;
        if ( ++v10 >= 3 )
          break;
        v9 = v22;
      }
      v23 += 12;
      ++v21;
      if ( ++bnum >= nummapbrushes )
        break;
      p_original_sides = v23;
      v1 = v21;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00436BD0
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
// Address: 0x00436C10
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
      *((_DWORD *)v3 + 3) = nummapbrushes;
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
// Address: 0x00436CE0
// Name: GetDisplacementBounds
// Source: json
//------------------------------------------------------------------------------
void __usercall GetDisplacementBounds(CCoreDispInfo *pDisp@<edi>, Vector *mins, Vector *maxs)
{
  Vector *v3; // ebx
  int v4; // esi
  int v5; // ebx

  v3 = maxs;
  ClearBounds(mins, maxs);
  v4 = 0;
  if ( ((1 << pDisp->m_Power) + 1) * ((1 << pDisp->m_Power) + 1) > 0 )
  {
    v5 = 0;
    do
    {
      AddPointToBounds(v: &pDisp->m_pVerts[v5].m_Vert, mins, maxs);
      ++v4;
      ++v5;
    }
    while ( v4 < ((1 << pDisp->m_Power) + 1) * ((1 << pDisp->m_Power) + 1) );
    v3 = maxs;
  }
  mins->x = mins->x - 1.0;
  mins->y = mins->y - 1.0;
  mins->z = mins->z - 1.0;
  v3->x = v3->x + 1.0;
  v3->y = v3->y + 1.0;
  v3->z = v3->z + 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x00436DB0
// Name: int BoxLeafNums(int __near *,int,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl BoxLeafNums(int *pLeafList, int listMax, const Vector *mins, const Vector *maxs)
{
  int v4; // ecx
  int v5; // ebx
  int v6; // edi
  int v7; // eax
  dnode_t *v8; // esi
  char v9; // al
  _DWORD v11[1024]; // [esp+Ch] [ebp-1004h]
  int v12; // [esp+100Ch] [ebp-4h]

  v4 = 0;
  v5 = 0;
  v6 = 1;
  v11[0] = 0;
  while ( 1 )
  {
    v7 = v11[v4];
    v12 = (v4 + 1) % 1024;
    if ( v7 >= 0 )
    {
      v8 = &dnodes[v7];
      v9 = BrushBspBoxOnPlaneSide(mins, maxs, plane: &dplanes[v8->planenum]);
      if ( (v9 & 1) != 0 )
      {
        v11[v6] = v8->children[0];
        v6 = (v6 + 1) % 1024;
      }
      if ( (v9 & 2) != 0 )
      {
        v11[v6] = v8->children[1];
        v6 = (v6 + 1) % 1024;
      }
    }
    else if ( v5 < listMax )
    {
      pLeafList[v5++] = -1 - v7;
    }
    if ( v12 == v6 )
      break;
    v4 = v12;
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00436E80
// Name: void BeginModel(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BeginModel()
{
  int v0; // eax
  int v1; // ecx
  int v2; // edx
  dmodel_t *v3; // edi
  char *v4; // eax
  int v5; // ebx
  int v6; // esi
  int v7; // esi
  Vector *p_mins; // edi
  int v9; // esi
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
  v5 = *((_DWORD *)v4 + 3);
  v6 = *((_DWORD *)v4 + 4);
  firstmodleaf = v1;
  mod = v3;
  firstmodeledge = v2;
  v7 = v5 + v6;
  ClearBounds(&mins, &maxs);
  if ( v5 < v7 )
  {
    p_mins = &mapbrushes[v5].mins;
    v9 = v7 - v5;
    do
    {
      if ( LODWORD(p_mins[2].x) != 0 )
      {
        AddPointToBounds(v: p_mins, &mins, &maxs);
        AddPointToBounds(v: p_mins + 1, &mins, &maxs);
      }
      p_mins += 4;
      --v9;
    }
    while ( v9 != 0 );
    v3 = mod;
  }
  v3->mins = mins;
  v3->maxs = maxs;
}

//------------------------------------------------------------------------------
// Address: 0x00436F90
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
// Address: 0x004370C0
// Name: void EmitMarkFace(struct dleaf_t __near *,struct face_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EmitMarkFace(dleaf_t *leaf_p, face_t *f)
{
  int outputnumber; // edi
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
    if ( SLOBYTE(texinfo.m_Memory.m_pMemory[f->texinfo].flags) < 0 )
      _Error(a1: "NODRAW GOT HERE!\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x004371A0
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
    v5 = s->original - mapbrushes;
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
// Address: 0x00437360
// Name: MarkLeaves_r
// Source: json
//------------------------------------------------------------------------------
void __cdecl MarkLeaves_r(CVarBitVec *leaves, int node)
{
  int i; // esi
  dnode_t *v3; // esi
  unsigned int *v4; // eax

  for ( i = node; i >= 0; i = v3->children[1] )
  {
    v3 = &dnodes[i];
    MarkLeaves_r(leaves, node: v3->children[0]);
  }
  v4 = &leaves->m_pInt[(-1 - i) >> 5];
  *v4 |= 1 << ((-1 - i) & 0x1F);
}

//------------------------------------------------------------------------------
// Address: 0x004373B0
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

  for ( j = node; j >= 0; j = dnodes[v5].children[1] )
  {
    v5 = j;
    AddNodeToBounds(node: dnodes[v5].children[0], skipAreas, mins, maxs);
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
      if ( *(__int16 *)((char *)&word_35264FE + v6) != 0 )
      {
        v9 = &dleaffaces[*(unsigned __int16 *)((char *)&word_35264FC + v6)];
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
        while ( i < *(unsigned __int16 *)((char *)&word_35264FE + v6) );
      }
    }
    else
    {
      v8 = &skipAreas->m_Memory.m_pMemory[v7];
      while ( (__int16)(*(__int16 *)((char *)&word_35264EE + v6) << 7) >> 7 != *v8 )
      {
        --v8;
        if ( --v7 < 0 )
          goto LABEL_8;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00437530
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
    v10 = (__int16)(word_35264EE[v7] << 7) >> 7;
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
// Address: 0x004375E0
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
        v10 = (__int16)(word_35264EE[v8 / 2] << 7) >> 7;
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
// Address: 0x004376F0
// Name: void ComputeBoundsNoSkybox(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeBoundsNoSkybox()
{
  int v0; // esi
  entity_t *i; // edi
  entity_t *v2; // esi
  char string[32]; // [esp+4h] [ebp-38h] BYREF
  Vector maxs; // [esp+24h] [ebp-18h] BYREF
  Vector mins; // [esp+30h] [ebp-Ch] BYREF

  ClearBounds(&mins, &maxs);
  AddNodeToBounds(node: dmodels[0].headnode, skipAreas: &g_SkyAreas, &mins, &maxs);
  AddDispsToBounds(nHeadNode: dmodels[0].headnode, skipAreas: &g_SkyAreas, vecMins: &mins, vecMaxs: &maxs);
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
// Address: 0x00437820
// Name: public: CBitVecT<class CVarBitVecBase<unsigned short>>::CBitVecT<class CVarBitVecBase<unsigned short>>(int)
// Source: json
//------------------------------------------------------------------------------
CBitVecT<CVarBitVecBase<unsigned short> > *__thiscall CBitVecT<CVarBitVecBase<unsigned short>>::CBitVecT<CVarBitVecBase<unsigned short>>(
        CBitVecT<CVarBitVecBase<unsigned short> > *this,
        int numBits)
{
  int v3; // eax
  unsigned int *p_m_iBitStringStorage; // eax
  unsigned __int8 *m_pInt; // eax

  this->m_numBits = numBits;
  v3 = (numBits + 31) / 32;
  this->m_numInts = v3;
  this->m_pInt = nullptr;
  if ( (_WORD)v3 != 0 )
  {
    if ( (unsigned __int16)v3 == 1 )
      p_m_iBitStringStorage = &this->m_iBitStringStorage;
    else
      p_m_iBitStringStorage = (unsigned int *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * (unsigned __int16)v3);
    this->m_pInt = p_m_iBitStringStorage;
  }
  m_pInt = (unsigned __int8 *)this->m_pInt;
  if ( m_pInt != nullptr )
    memset(dst: m_pInt, value: 0, count: 4 * this->m_numInts);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00438BD0
// Name: public: MeshAccumulator_t::MeshAccumulator_t(struct MeshAccumulator_t const __near &)
// Source: json
//------------------------------------------------------------------------------
MeshAccumulator_t *__thiscall MeshAccumulator_t::MeshAccumulator_t(
        MeshAccumulator_t *this,
        const MeshAccumulator_t *Other)
{
  this->m_Vertices.m_Memory.m_pMemory = nullptr;
  this->m_Vertices.m_Memory.m_nAllocationCount = 0;
  this->m_Vertices.m_Memory.m_nGrowSize = 0;
  this->m_Vertices.m_Size = 0;
  this->m_Vertices.m_pElements = nullptr;
  this->m_Indices.m_Memory.m_pMemory = nullptr;
  this->m_Indices.m_Memory.m_nAllocationCount = 0;
  this->m_Indices.m_Memory.m_nGrowSize = 0;
  this->m_Indices.m_Size = 0;
  this->m_Indices.m_pElements = nullptr;
  V_strncpy(pDest: this->m_pVMT, pSrc: Other->m_pVMT, maxLen: 128);
  CUtlVector<BaseWorldVertex_t,CUtlMemory<BaseWorldVertex_t,int>>::InsertMultipleBefore(
    this: &this->m_Vertices,
    elem: this->m_Vertices.m_Size,
    num: Other->m_Vertices.m_Size,
    pToInsert: Other->m_Vertices.m_Memory.m_pMemory);
  CUtlVector<int,CUtlMemory<int,int>>::InsertMultipleBefore(
    this: (CUtlVector<int,CUtlMemory<int,int> > *)&this->m_Indices,
    elem: this->m_Indices.m_Size,
    num: Other->m_Indices.m_Size,
    pToInsert: (const int *)Other->m_Indices.m_Memory.m_pMemory);
  this->m_bNoDraw = Other->m_bNoDraw;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00438D40
// Name: public: void CUtlDict<struct propmaterial_list_t,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<propmaterial_list_t,int>::RemoveAll(CUtlDict<propmaterial_list_t,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,propmaterial_list_t,int>::Node_t,int,CUtlMap<char const *,propmaterial_list_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,propmaterial_list_t,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,propmaterial_list_t,int>::Node_t,int,CUtlMap<char const *,propmaterial_list_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,propmaterial_list_t,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,propmaterial_list_t,int>::Node_t,int,CUtlMap<char const *,propmaterial_list_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,propmaterial_list_t,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x00438D90
// Name: void EmitFace(struct face_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EmitFace(int f, unsigned __int8 onNode)
{
  bool v3; // cc
  int v4; // eax
  dface_t *v5; // edi
  int OrigFace; // eax
  int v7; // edx
  int v8; // eax
  unsigned __int16 m_NumPrims; // cx
  int v10; // eax
  int *v11; // ebx
  int v12; // edi
  int v13; // eax
  side_t *v14; // esi
  int e; // [esp+10h] [ebp+8h]

  v3 = *(_DWORD *)(f + 52) < 3;
  *(_DWORD *)(f + 44) = -1;
  if ( !v3 && *(_DWORD *)(f + 8) == 0 && *(_DWORD *)(f + 12) == 0 && *(_DWORD *)(f + 16) == 0 )
  {
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
    dfaceids.m_Memory.m_pMemory[numfaces++].hammerfaceid = *(_WORD *)(*(_DWORD *)(f + 188) + 48);
    v5->planenum = *(_WORD *)(f + 36);
    v5->onNode = onNode;
    v5->side = *(_BYTE *)(f + 36) & 1;
    v5->texinfo = *(_WORD *)(f + 24);
    v5->dispinfo = *(_WORD *)(f + 28);
    v5->smoothingGroups = *(_DWORD *)(f + 200);
    OrigFace = FindOrCreateOrigFace((face_t *)f);
    v7 = numfaces;
    v5->origFace = OrigFace;
    v8 = numsurfedges;
    v5->surfaceFogVolumeID = -1;
    dword_34E63BC[v7] = *(_DWORD *)(f + 32);
    v5->firstedge = v8;
    v5->numedges = *(_WORD *)(f + 52);
    if ( *(_DWORD *)(f + 48) != 0 )
      v5->area = WindingArea(w: *(winding_t **)(f + 48));
    else
      v5->area = 0.0;
    m_NumPrims = v5->m_NumPrims;
    v5->firstPrimID = *(_WORD *)(f + 192);
    v5->m_NumPrims ^= (*(_WORD *)(f + 196) ^ m_NumPrims) & 0x7FFF;
    dface_t::SetDynamicShadowsEnabled(this: v5, bEnabled: *(_BYTE *)(*(_DWORD *)(f + 188) + 96));
    v10 = 0;
    if ( *(int *)(f + 52) > 0 )
    {
      v11 = (int *)(f + 60);
      do
      {
        v12 = v10 + 1;
        e = GetEdge2(v1: *v11, v2: *(_DWORD *)(f + 4 * ((v10 + 1) % *(_DWORD *)(f + 52)) + 60), (face_t *)f);
        if ( numsurfedges >= 512000 )
          _Error(a1: "Too much brush geometry in bsp, numsurfedges == MAX_MAP_SURFEDGES");
        v13 = numsurfedges;
        dsurfedges[numsurfedges] = e;
        numsurfedges = v13 + 1;
        v10 = v12;
        ++v11;
      }
      while ( v12 < *(_DWORD *)(f + 52) );
    }
    v14 = *(side_t **)(f + 188);
    if ( v14 != nullptr )
    {
      if ( v14->aOverlayIds.m_Size > 0 )
        Overlay_AddFaceToLists(iFace: numfaces - 1, pSide: v14);
      if ( v14->aWaterOverlayIds.m_Size > 0 )
        OverlayTransition_AddFaceToLists(iFace: numfaces - 1, pSide: v14);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00438FB0
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
  int OrigFace; // eax
  int v11; // ecx
  int v12; // edx
  unsigned __int16 m_NumPrims; // dx
  unsigned __int16 v14; // ax
  unsigned __int16 v15; // ax
  int v16; // eax
  int *vertexnums; // ebx
  int v18; // edi
  int v19; // eax
  side_t *originalface; // edi
  face_t *pLeafFaceLista; // [esp+Ch] [ebp+8h]

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
LABEL_36:
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
        this: (CUtlMemory<short,int> *)&dfaceids,
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
    m_pMemory[numfaces++] = (dfaceid_t)v1->originalface->id;
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
LABEL_20:
        v11 = numfaces;
        v6->surfaceFogVolumeID = -1;
        v12 = numsurfedges;
        v6->origFace = OrigFace;
        dword_34E63BC[v11] = (int)v1->fogVolumeLeaf;
        v6->firstedge = v12;
        v6->numedges = v1->numpoints;
        if ( v1->w != nullptr )
          v6->area = WindingArea(w: v1->w);
        else
          v6->area = 0.0;
        m_NumPrims = v6->m_NumPrims;
        v6->firstPrimID = v1->firstPrimID;
        v6->m_NumPrims ^= (LOWORD(v1->numPrims) ^ m_NumPrims) & 0x7FFF;
        v14 = v6->m_NumPrims;
        if ( v1->originalface->m_bDynamicShadowsEnabled )
          v15 = v14 & 0x7FFF;
        else
          v15 = v14 | 0x8000;
        v6->m_NumPrims = v15;
        v16 = 0;
        if ( v1->numpoints > 0 )
        {
          vertexnums = v1->vertexnums;
          do
          {
            v18 = v16 + 1;
            pLeafFaceLista = (face_t *)GetEdge2(v1: *vertexnums, v2: v1->vertexnums[(v16 + 1) % v1->numpoints], f: v1);
            if ( numsurfedges >= 512000 )
              _Error(a1: "Too much brush geometry in bsp, numsurfedges == MAX_MAP_SURFEDGES");
            v19 = numsurfedges;
            dsurfedges[numsurfedges] = (int)pLeafFaceLista;
            numsurfedges = v19 + 1;
            v16 = v18;
            ++vertexnums;
          }
          while ( v18 < v1->numpoints );
        }
        originalface = v1->originalface;
        if ( originalface != nullptr )
        {
          if ( originalface->aOverlayIds.m_Size > 0 )
            Overlay_AddFaceToLists(iFace: numfaces - 1, pSide: v1->originalface);
          if ( originalface->aWaterOverlayIds.m_Size > 0 )
            OverlayTransition_AddFaceToLists(iFace: numfaces - 1, pSide: originalface);
        }
        goto LABEL_36;
      }
      if ( OrigFace != -2 )
        goto LABEL_20;
    }
    OrigFace = -1;
    goto LABEL_20;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00439260
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
// Address: 0x004393B0
// Name: void WriteBSP(struct node_t __near *,struct face_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl WriteBSP(node_t *headnode, face_t *pLeafFaceList)
{
  int v2; // eax
  int v3; // ecx
  int v4; // edi
  mapdispinfo_t *v5; // esi
  int oldorigfaces; // [esp+8h] [ebp-8h]
  int oldfaces; // [esp+Ch] [ebp-4h]

  c_nofaces = 0;
  c_facenodes = 0;
  qprintf(format: "--- WriteBSP ---\n");
  oldfaces = numfaces;
  oldorigfaces = numorigfaces;
  GetEdge2_InitOptimizedList();
  EmitLeafFaces(pLeafFaceList);
  v2 = EmitDrawNode_r(node: headnode);
  v3 = nummodels;
  dmodels[nummodels].headnode = v2;
  if ( v3 == 0 )
    EmitAreaPortals(headnode);
  v4 = 0;
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
      ++v4;
      ++v5;
    }
    while ( v4 < nummapdispinfo );
  }
  qprintf(format: "%5i nodes with faces\n", c_facenodes);
  qprintf(format: "%5i nodes without faces\n", c_nofaces);
  qprintf(format: "%5i faces\n", numfaces - oldfaces);
  qprintf(format: "%5i original faces\n", numorigfaces - oldorigfaces);
}

//------------------------------------------------------------------------------
// Address: 0x004394C0
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
// Address: 0x00439780
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
  v5 = CUtlRBTree<CUtlMap<char const *,enum DmElementHandle_t,int>::Node_t,int,CUtlMap<char const *,enum DmElementHandle_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum DmElementHandle_t,int>::Node_t,int>,int>>::NewNode((CUtlRBTree<CUtlMap<char const *,enum DmElementHandle_t,int>::Node_t,int,CUtlMap<char const *,enum DmElementHandle_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum DmElementHandle_t,int>::Node_t,int>,int> > *)this);
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
// Address: 0x00439930
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
  CUtlVector<bool,CUtlMemory<bool,int>>::CopyArray(
    this: (CUtlVector<bool,CUtlMemory<bool,int> > *)&oldStringData,
    pArray: (const bool *)g_TexDataStringData.m_Memory.m_pMemory,
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
        flt_5C98864[v9] = *((float *)p_nameStringTableID - 2);
        flt_5C98868[v9] = *((float *)p_nameStringTableID - 1);
        dword_5C9886C[v9] = *p_nameStringTableID;
        dword_5C98870[v9] = p_nameStringTableID[1];
        dword_5C98874[v9] = p_nameStringTableID[2];
        dword_5C98878[v9] = p_nameStringTableID[3];
        v10 = p_nameStringTableID[4];
        ++numtexdata;
        dword_5C9887C[v9] = v10;
        dword_5C9886C[v9] = String;
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
// Address: 0x00439AE0
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
  int j; // eax
  int v26; // ecx
  int k; // eax
  int v28; // ecx
  __int16 *v29; // eax
  int v30; // edx
  __int16 *v31; // eax
  int v32; // edx
  dworldlight_t *v33; // ecx
  int v34; // eax
  int v35; // edx
  __int16 *v36; // eax
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
    v4 = word_3C37F32;
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
  for ( j = 0; j < g_CoreDispTexInfos.m_Size; ++j )
    g_CoreDispTexInfos.m_Memory.m_pMemory[j] = *(_DWORD *)&v0[8 * g_CoreDispTexInfos.m_Memory.m_pMemory[j] + 4];
  v26 = numbrushsides;
  for ( k = 0; k < v26; ++k )
    word_3C37F32[4 * k] = *(_WORD *)&v0[8 * word_3C37F32[4 * k] + 4];
  v28 = g_nOverlayCount;
  if ( g_nOverlayCount > 0 )
  {
    v29 = &g_Overlays[0].nTexInfo;
    do
    {
      *v29 = *(_WORD *)&v0[8 * *v29 + 4];
      v29 += 176;
      --v28;
    }
    while ( v28 != 0 );
  }
  v30 = numleafwaterdata;
  if ( numleafwaterdata > 0 )
  {
    v31 = &dleafwaterdata[0].surfaceTexInfoID;
    do
    {
      if ( *v31 >= 0 )
        *v31 = *(_WORD *)&v0[8 * *v31 + 4];
      v31 += 6;
      --v30;
    }
    while ( v30 != 0 );
  }
  v32 = 0;
  if ( *pNumworldlights > 0 )
  {
    v33 = dworldlights;
    v34 = 0;
    do
    {
      if ( v33[v34].texinfo >= 0 )
      {
        v33[v34].texinfo = *(_DWORD *)&v0[8 * v33[v34].texinfo + 4];
        v33 = dworldlights;
      }
      ++v32;
      ++v34;
    }
    while ( v32 < *pNumworldlights );
  }
  v35 = g_nWaterOverlayCount;
  if ( g_nWaterOverlayCount > 0 )
  {
    v36 = &g_WaterOverlays[0].nTexInfo;
    do
    {
      if ( *v36 >= 0 )
        *v36 = *(_WORD *)&v0[8 * *v36 + 4];
      v36 += 560;
      --v35;
    }
    while ( v35 != 0 );
  }
  _Msg(a1: "Reduced %d texinfos to %d\n", oldCount, texinfo.m_Size);
  _Msg(a1: "Reduced %d texdatas to %d (%d bytes to %d)\n", oldTexdataCounta, numtexdata, ia, g_TexDataStringData.m_Size);
  free(pMem: v0);
  free(pMem: v1);
}

//------------------------------------------------------------------------------
// Address: 0x00439EE0
// Name: public: CStaticPropBuilder::~CStaticPropBuilder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStaticPropBuilder::~CStaticPropBuilder(CStaticPropBuilder *this)
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_materialLinearList);
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_instanceList);
  CUtlVector<CModelBatch,CUtlMemory<CModelBatch,int>>::Purge(this: &this->m_batchList);
  if ( this->m_batchList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_batchList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_batchList.m_Memory.m_pMemory);
      this->m_batchList.m_Memory.m_pMemory = nullptr;
    }
    this->m_batchList.m_Memory.m_nAllocationCount = 0;
  }
  CUtlDict<propmaterial_list_t,int>::RemoveAll(this: &this->m_materialList);
  CUtlRBTree<CUtlMap<char const *,propmaterial_list_t,int>::Node_t,int,CUtlMap<char const *,propmaterial_list_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,propmaterial_list_t,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,propmaterial_list_t,int>::Node_t,int,CUtlMap<char const *,propmaterial_list_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,propmaterial_list_t,int>::Node_t,int>,int>>(this: &this->m_materialList.m_Elements.m_Tree);
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>((CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x00439F40
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
// Address: 0x00439FA0
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
                     materialName: &g_TexDataStringData.m_Memory.m_pMemory[g_TexDataStringTable.m_Memory.m_pMemory[dword_5C9886C[8 * texdata]]],
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
// Address: 0x0043A1B0
// Name: void EmitBVH(class CStaticPropList const __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall EmitBVH(int a1@<ebx>, int a2@<edi>, int a3@<esi>, const CStaticPropList *list)
{
  int i; // eax
  unsigned int *v5; // edx
  int v6; // esi
  int v7; // ecx
  int v8; // edi
  unsigned __int8 *p_dst; // eax
  int v10; // eax
  int v11; // ecx
  unsigned __int8 *v12; // eax
  int v13; // ecx
  unsigned __int8 *v14; // eax
  int v15; // ecx
  unsigned int *p_m_iBitStringStorage; // eax
  dnode_t *v17; // esi
  __int16 *v18; // esi
  int v19; // eax
  int v20; // ecx
  int v21; // eax
  int v22; // ecx
  int v23; // ebx
  int v24; // ecx
  const CStaticPropList *v25; // ecx
  staticpropleafref_t *m_pMemory; // eax
  int v27; // edx
  bool v28; // cc
  staticpropleafref_t *v29; // eax
  int v30; // ecx
  unsigned __int8 *v31; // eax
  int v32; // ebx
  staticpropleafref_t *v33; // eax
  int j; // ebx
  int v35; // eax
  int v36; // esi
  const char *String; // esi
  char v38; // bl
  TextureData_t *v39; // edx
  int m_Size; // eax
  int v41; // esi
  int v42; // eax
  MeshAccumulator_t *v43; // esi
  int *v44; // edi
  texinfo_s *v45; // ecx
  int texdata; // edx
  int v47; // eax
  dtexdata_t *v48; // edx
  int v49; // esi
  _DWORD *v50; // eax
  int v51; // edi
  float v52; // xmm3_4
  int v53; // eax
  __m128i v54; // xmm0
  int v55; // edx
  dplane_t *v56; // eax
  float v57; // xmm4_4
  int *v58; // edx
  int *v59; // eax
  int k; // esi
  int v61; // ecx
  int v62; // ecx
  int v63; // ecx
  float v64; // xmm1_4
  float v65; // xmm0_4
  float v66; // xmm2_4
  float v67; // xmm5_4
  float v68; // xmm0_4
  float v69; // xmm5_4
  float v70; // xmm5_4
  float v71; // xmm6_4
  float v72; // xmm0_4
  int v73; // ecx
  int v74; // eax
  CUtlVector<BaseWorldVertex_t,CUtlMemory<BaseWorldVertex_t,int> > *v75; // ebx
  CUtlMemory<S3RGBA,int> *v76; // esi
  int v77; // ecx
  int v78; // eax
  float v79; // xmm0_4
  int *v80; // eax
  TextureData_t *v81; // xmm0_4
  int v82; // eax
  TextureData_t *v83; // xmm0_4
  int *v84; // eax
  TextureData_t *v85; // xmm0_4
  int v86; // eax
  int v87; // ecx
  TextureData_t *v88; // xmm0_4
  int *v89; // eax
  int v90; // eax
  S3RGBA *v91; // edi
  int m_nAllocationCount; // eax
  S3RGBA *v93; // ecx
  int v94; // eax
  int *v95; // edi
  int v96; // eax
  S3RGBA *v97; // edi
  int v98; // eax
  S3RGBA *v99; // ecx
  int v100; // eax
  int *v101; // edi
  int v102; // eax
  S3RGBA *v103; // edi
  int v104; // eax
  S3RGBA *v105; // ecx
  int v106; // eax
  int *v107; // edi
  int indexCount; // ecx
  CUtlMemory<S3RGBA,int> *v109; // esi
  char *v110; // edi
  int v111; // edx
  int v112; // eax
  S3RGBA *v113; // ebx
  int v114; // eax
  S3RGBA *v115; // ecx
  int v116; // eax
  S3RGBA *v117; // ebx
  int v118; // eax
  S3RGBA *v119; // ebx
  int v120; // eax
  S3RGBA *v121; // ecx
  int v122; // eax
  S3RGBA *v123; // ebx
  int v124; // eax
  S3RGBA *v125; // ebx
  int v126; // eax
  S3RGBA *v127; // ecx
  int v128; // eax
  S3RGBA *v129; // ebx
  float v130; // xmm0_4
  CCoreDispInfo *v131; // ebx
  int v132; // ecx
  int v133; // eax
  MeshAccumulator_t *v134; // esi
  int TriCount; // eax
  int m_Power; // ecx
  int v137; // edi
  CoreDispVert_t *m_pVerts; // edx
  int v139; // ecx
  float v140; // xmm1_4
  float z; // xmm0_4
  unsigned __int16 *m_RenderIndices; // ebx
  CUtlMemory<S3RGBA,int> *p_firstIndex; // esi
  S3RGBA *v144; // edi
  int v145; // eax
  int v146; // ebx
  S3RGBA *v147; // ecx
  int v148; // eax
  S3RGBA *v149; // edi
  S3RGBA *v150; // edi
  int v151; // eax
  int v152; // ebx
  S3RGBA *v153; // ecx
  int v154; // eax
  S3RGBA *v155; // edi
  S3RGBA *v156; // edi
  int v157; // eax
  int v158; // ebx
  S3RGBA *v159; // ecx
  int v160; // eax
  S3RGBA *v161; // edi
  int v162; // eax
  int v163; // eax
  CVTFTexture::ResourceMemorySection *v164; // eax
  int v165; // edx
  int v166; // ecx
  int v167; // ebx
  int v168; // edx
  int v169; // esi
  int v170; // eax
  int *v171; // esi
  int MemRequired; // esi
  CVTFTexture::ResourceMemorySection *v173; // eax
  int *v174; // eax
  propinstance_list_t *v175; // eax
  int v176; // esi
  int v177; // ebx
  CModelBatch *v178; // eax
  int *p_m_nGrowSize; // esi
  int v180; // eax
  const char *v181; // esi
  CBVHNodeBuilder *v182; // eax
  int v183; // eax
  unsigned int v187; // [esp-4h] [ebp-1C6Ch]
  int pLeafList[448]; // [esp+0h] [ebp-1C68h] BYREF
  int v189; // [esp+700h] [ebp-1568h] BYREF
  int v190; // [esp+704h] [ebp-1564h]
  float v191; // [esp+708h] [ebp-1560h]
  _DWORD v192[2]; // [esp+70Ch] [ebp-155Ch]
  _DWORD v193[9]; // [esp+714h] [ebp-1554h] BYREF
  char v194; // [esp+738h] [ebp-1530h] BYREF
  CBVHNodeBuilder rootNode; // [esp+1000h] [ebp-C68h] BYREF
  char pOut[260]; // [esp+12F8h] [ebp-970h] BYREF
  char pPageFileName[260]; // [esp+13FCh] [ebp-86Ch] BYREF
  char pszFileName[260]; // [esp+1500h] [ebp-768h] BYREF
  char path[260]; // [esp+1604h] [ebp-664h] BYREF
  char pDest[260]; // [esp+1708h] [ebp-560h] BYREF
  char v201[260]; // [esp+180Ch] [ebp-45Ch] BYREF
  CWorldRendererBuilder v202; // [esp+1910h] [ebp-358h] BYREF
  Vector mins; // [esp+19A0h] [ebp-2C8h] BYREF
  Vector maxs; // [esp+19ACh] [ebp-2BCh] BYREF
  BVHBuilderParams_t params; // [esp+19B8h] [ebp-2B0h] BYREF
  BuilderMaterial_t pMaterialOut; // [esp+1A04h] [ebp-264h] BYREF
  BaseWorldVertex_t v207; // [esp+1AFCh] [ebp-16Ch] BYREF
  float v208; // [esp+1B20h] [ebp-148h]
  float v209; // [esp+1B24h] [ebp-144h]
  float v210; // [esp+1B28h] [ebp-140h]
  float v211; // [esp+1B2Ch] [ebp-13Ch]
  float x; // [esp+1B30h] [ebp-138h]
  float v213; // [esp+1B34h] [ebp-134h]
  float v214; // [esp+1B38h] [ebp-130h]
  float v215; // [esp+1B3Ch] [ebp-12Ch]
  float v216; // [esp+1B40h] [ebp-128h]
  CStaticPropBuilder v217; // [esp+1B44h] [ebp-124h] BYREF
  CBitVecT<CVarBitVecBase<unsigned short> > v218; // [esp+1BB8h] [ebp-B0h] BYREF
  IDirect3D9 *ppd3d9; // [esp+1BC4h] [ebp-A4h] BYREF
  int z_low; // [esp+1BC8h] [ebp-A0h]
  char pDirName[4]; // [esp+1BCCh] [ebp-9Ch] BYREF
  int v222; // [esp+1BD0h] [ebp-98h]
  CUtlVector<MeshAccumulator_t,CUtlMemory<MeshAccumulator_t,int> > v223; // [esp+1BD4h] [ebp-94h] BYREF
  CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > v224; // [esp+1BE8h] [ebp-80h] BYREF
  __int16 v225; // [esp+1BFCh] [ebp-6Ch]
  unsigned __int16 v226; // [esp+1BFEh] [ebp-6Ah]
  unsigned __int8 dst; // [esp+1C00h] [ebp-68h] BYREF
  unsigned __int8 *v228; // [esp+1C04h] [ebp-64h]
  __int16 v229; // [esp+1C08h] [ebp-60h]
  unsigned __int16 v230; // [esp+1C0Ah] [ebp-5Eh]
  unsigned __int8 v231; // [esp+1C0Ch] [ebp-5Ch] BYREF
  unsigned __int8 *v232; // [esp+1C10h] [ebp-58h]
  __int16 v233; // [esp+1C14h] [ebp-54h]
  unsigned __int16 v234; // [esp+1C16h] [ebp-52h]
  unsigned __int8 v235; // [esp+1C18h] [ebp-50h] BYREF
  unsigned __int8 *v236; // [esp+1C1Ch] [ebp-4Ch]
  dprimitive_t *v237; // [esp+1C20h] [ebp-48h]
  IDirect3DDevice9 *ppd3dDevice; // [esp+1C24h] [ebp-44h] BYREF
  CVarBitVec leaves; // [esp+1C28h] [ebp-40h] BYREF
  CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > v240; // [esp+1C34h] [ebp-34h] BYREF
  bool v241; // [esp+1C4Bh] [ebp-1Dh]
  int v242; // [esp+1C4Ch] [ebp-1Ch]
  int m_pVMT; // [esp+1C50h] [ebp-18h]
  CUtlVector<BaseWorldVertex_t,CUtlMemory<BaseWorldVertex_t,int> > *v244; // [esp+1C54h] [ebp-14h]
  int v245; // [esp+1C58h] [ebp-10h]
  CUtlVector<BaseWorldVertex_t,CUtlMemory<BaseWorldVertex_t,int> > *v246; // [esp+1C5Ch] [ebp-Ch]
  int v247; // [esp+1C60h] [ebp-8h]
  int *v248; // [esp+1C64h] [ebp-4h]
  int savedregs; // [esp+1C68h] [ebp+0h] BYREF
  int m; // [esp+1C70h] [ebp+8h]

  CBitVecT<CVarBitVecBase<unsigned short>>::CBitVecT<CVarBitVecBase<unsigned short>>(this: &v218, numBits: numareas);
  if ( v218.m_pInt != nullptr )
    memset(dst: (unsigned __int8 *)v218.m_pInt, value: 0, count: 4 * v218.m_numInts);
  for ( i = 0; i < g_SkyAreas.m_Size; *v5 |= v6 )
  {
    v5 = &v218.m_pInt[g_SkyAreas.m_Memory.m_pMemory[i] >> 5];
    v6 = 1 << (g_SkyAreas.m_Memory.m_pMemory[i++] & 0x1F);
  }
  v225 = numfaces + 1;
  v7 = (numfaces + 32) / 32;
  v8 = 0;
  v226 = v7;
  v228 = nullptr;
  if ( (_WORD)v7 != 0 )
  {
    if ( (unsigned __int16)v7 == 1 )
    {
      p_dst = &dst;
      v228 = &dst;
    }
    else
    {
      p_dst = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * (unsigned __int16)v7);
      v228 = p_dst;
      if ( p_dst == nullptr )
        goto LABEL_12;
      LOWORD(v7) = v226;
    }
    memset(dst: p_dst, value: 0, count: 4 * (unsigned __int16)v7);
    if ( v228 != nullptr )
      memset(dst: v228, value: 0, count: 4 * v226);
  }
LABEL_12:
  v10 = list->props.m_Size + 1;
  v233 = LOWORD(list->props.m_Size) + 1;
  v11 = (v10 + 31) / 32;
  v234 = v11;
  v236 = nullptr;
  if ( (_WORD)v11 != 0 )
  {
    if ( (unsigned __int16)v11 == 1 )
    {
      v12 = &v235;
      v236 = &v235;
    }
    else
    {
      v12 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * (unsigned __int16)v11);
      v236 = v12;
      if ( v12 == nullptr )
        goto LABEL_19;
      LOWORD(v11) = v234;
    }
    memset(dst: v12, value: 0, count: 4 * (unsigned __int16)v11);
    if ( v236 != nullptr )
      memset(dst: v236, value: 0, count: 4 * v234);
  }
LABEL_19:
  v229 = LOWORD(g_CoreDispInfos.m_Size) + 1;
  v13 = (g_CoreDispInfos.m_Size + 32) / 32;
  v230 = v13;
  v232 = nullptr;
  if ( (_WORD)v13 != 0 )
  {
    if ( (unsigned __int16)v13 == 1 )
    {
      v14 = &v231;
      v232 = &v231;
    }
    else
    {
      v14 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * (unsigned __int16)v13);
      v232 = v14;
      if ( v14 == nullptr )
        goto LABEL_26;
      LOWORD(v13) = v230;
    }
    memset(dst: v14, value: 0, count: 4 * (unsigned __int16)v13);
    if ( v232 != nullptr )
      memset(dst: v232, value: 0, count: 4 * v230);
  }
LABEL_26:
  leaves.m_numBits = numleafs + 1;
  v15 = (numleafs + 32) / 32;
  p_m_iBitStringStorage = nullptr;
  leaves.m_numInts = v15;
  leaves.m_pInt = nullptr;
  if ( (_WORD)v15 == 0 )
    goto LABEL_33;
  if ( (unsigned __int16)v15 == 1 )
  {
    p_m_iBitStringStorage = &leaves.m_iBitStringStorage;
    leaves.m_pInt = &leaves.m_iBitStringStorage;
  }
  else
  {
    p_m_iBitStringStorage = (unsigned int *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * (unsigned __int16)v15);
    leaves.m_pInt = p_m_iBitStringStorage;
    if ( p_m_iBitStringStorage == nullptr )
      goto LABEL_33;
    LOWORD(v15) = leaves.m_numInts;
  }
  memset(dst: (unsigned __int8 *)p_m_iBitStringStorage, value: 0, count: 4 * (unsigned __int16)v15);
  p_m_iBitStringStorage = leaves.m_pInt;
  if ( leaves.m_pInt != nullptr )
  {
    memset(dst: (unsigned __int8 *)leaves.m_pInt, value: 0, count: 4 * leaves.m_numInts);
    p_m_iBitStringStorage = leaves.m_pInt;
  }
LABEL_33:
  if ( dmodels[0].headnode >= 0 )
  {
    v17 = &dnodes[dmodels[0].headnode];
    MarkLeaves_r(&leaves, node: v17->children[0]);
    MarkLeaves_r(&leaves, node: v17->children[1]);
  }
  else
  {
    p_m_iBitStringStorage[(-1 - dmodels[0].headnode) >> 5] |= 1 << ((-1 - LOBYTE(dmodels[0].headnode)) & 0x1F);
  }
  ClearBounds(&mins, &maxs);
  if ( numleafs > 0 )
  {
    v18 = (__int16 *)&unk_35264F0;
    do
    {
      if ( ((1 << (v8 & 0x1F)) & leaves.m_pInt[v8 >> 5]) != 0
        && ((1 << (((__int16)(*(v18 - 1) << 7) >> 7) & 0x1F)) & v218.m_pInt[(__int16)(*(v18 - 1) << 7) >> 12]) == 0 )
      {
        v19 = v18[1];
        v20 = v18[2];
        *(float *)&v224.m_Memory.m_nGrowSize = (float)*v18;
        *(float *)&v224.m_Size = (float)v19;
        *(float *)&v224.m_pElements = (float)v20;
        AddPointToBounds(v: (const Vector *)&v224.m_Memory.m_nGrowSize, &mins, &maxs);
        v21 = v18[4];
        v22 = v18[5];
        *(float *)&v224.m_Memory.m_nGrowSize = (float)v18[3];
        *(float *)&v224.m_Size = (float)v21;
        *(float *)&v224.m_pElements = (float)v22;
        AddPointToBounds(v: (const Vector *)&v224.m_Memory.m_nGrowSize, &mins, &maxs);
        v23 = 0;
        if ( v18[7] != 0 )
        {
          do
          {
            v24 = dleaffaces[v23 + (unsigned __int16)v18[6]];
            if ( dfaces[v24].dispinfo < 0 )
            {
              if ( (texinfo.m_Memory.m_pMemory[dfaces[v24].texinfo].flags & 0x44) == 0 )
                *(_DWORD *)&v228[4 * (v24 >> 5)] |= 1 << (v24 & 0x1F);
            }
            else
            {
              _Msg(a1: "hit disp surface unexpectedly\n");
            }
            ++v23;
          }
          while ( v23 < (unsigned __int16)v18[7] );
        }
        v25 = list;
        m_pMemory = list->leafList.m_Memory.m_pMemory;
        v27 = 0;
        v28 = m_pMemory[v8].propCount <= 0;
        v29 = &m_pMemory[v8];
        if ( !v28 )
        {
          do
          {
            v30 = v25->leafProps.m_Memory.m_pMemory[v27 + v29->propStart];
            v31 = &v236[4 * (v30 >> 5)];
            v32 = 1 << (v30 & 0x1F);
            v25 = list;
            ++v27;
            *(_DWORD *)v31 |= v32;
            v33 = list->leafList.m_Memory.m_pMemory;
            v28 = v27 < v33[v8].propCount;
            v29 = &v33[v8];
          }
          while ( v28 );
        }
      }
      ++v8;
      v18 += 16;
    }
    while ( v8 < numleafs );
  }
  for ( j = 0; j < g_CoreDispInfos.m_Size; ++j )
  {
    GetDisplacementBounds(
      pDisp: g_CoreDispInfos.m_Memory.m_pMemory[j],
      mins: (Vector *)&v223.m_Memory.m_nGrowSize,
      maxs: (Vector *)&v224.m_Memory.m_nGrowSize);
    v35 = BoxLeafNums(
            pLeafList,
            listMax: 1024,
            mins: (const Vector *)&v223.m_Memory.m_nGrowSize,
            maxs: (const Vector *)&v224.m_Memory.m_nGrowSize);
    v36 = 0;
    if ( v35 > 0 )
    {
      while ( ((1 << (((__int16)(word_35264EE[16 * pLeafList[v36]] << 7) >> 7) & 0x1F))
             & v218.m_pInt[(__int16)(word_35264EE[16 * pLeafList[v36]] << 7) >> 12]) != 0 )
      {
        if ( ++v36 >= v35 )
          goto LABEL_55;
      }
      *(_DWORD *)&v232[4 * (j >> 5)] |= 1 << (j & 0x1F);
    }
LABEL_55:
    ;
  }
  memset(&v223, 0, sizeof(v223));
  v222 = -1;
  v247 = 0;
  if ( numtexdata > 0 )
  {
    v248 = dword_5C9886C;
    do
    {
      String = TexDataStringTable_GetString(stringID: *v248);
      v38 = 0;
      if ( V_stristr(pStr: String, pSearch: "tools") != nullptr )
      {
        v38 = 1;
      }
      else if ( v222 == -1 )
      {
        v222 = v247;
      }
      v39 = nullptr;
      memset(&pMaterialOut.m_ppTextures[10], 0, 40);
      if ( v38 != 0 )
      {
        pMaterialOut.m_Material.m_szShaderPS[28] = 0;
        LOBYTE(pMaterialOut.m_ppTextures[9]) = 1;
      }
      else
      {
        V_strncpy(pDest: &pMaterialOut.m_Material.m_szShaderPS[28], pSrc: String, maxLen: 128);
        v39 = pMaterialOut.m_ppTextures[15];
        LOBYTE(pMaterialOut.m_ppTextures[9]) = 0;
      }
      m_Size = v223.m_Size;
      v41 = v223.m_Size;
      if ( v223.m_Size + 1 > v223.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<MeshAccumulator_t,int>::Grow(
          this: &v223.m_Memory,
          num: v223.m_Size - v223.m_Memory.m_nAllocationCount + 1);
        v39 = pMaterialOut.m_ppTextures[15];
        m_Size = v223.m_Size;
      }
      v223.m_Size = m_Size + 1;
      v42 = m_Size - v41;
      v223.m_pElements = v223.m_Memory.m_pMemory;
      if ( v42 > 0 )
      {
        _V_memmove(dest: &v223.m_Memory.m_pMemory[v41 + 1], src: &v223.m_Memory.m_pMemory[v41], count: 172 * v42);
        v39 = pMaterialOut.m_ppTextures[15];
      }
      v43 = &v223.m_Memory.m_pMemory[v41];
      if ( v43 != nullptr )
      {
        MeshAccumulator_t::MeshAccumulator_t(
          this: v43,
          Other: (const MeshAccumulator_t *)&pMaterialOut.m_Material.m_szShaderPS[28]);
        v39 = pMaterialOut.m_ppTextures[15];
      }
      pMaterialOut.m_originalMaterialName.m_Storage.m_Memory.m_nGrowSize = 0;
      if ( pMaterialOut.m_originalMaterialName.m_Storage.m_Memory.m_nAllocationCount >= 0 )
      {
        if ( v39 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v39);
          v39 = nullptr;
          pMaterialOut.m_ppTextures[15] = nullptr;
        }
        pMaterialOut.m_originalMaterialName.m_Storage.m_Memory.m_pMemory = nullptr;
      }
      pMaterialOut.m_originalMaterialName.m_Storage.m_nActualLength = (int)v39;
      if ( pMaterialOut.m_originalMaterialName.m_Storage.m_Memory.m_nAllocationCount >= 0 )
      {
        if ( v39 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v39);
          pMaterialOut.m_ppTextures[15] = nullptr;
        }
        pMaterialOut.m_originalMaterialName.m_Storage.m_Memory.m_pMemory = nullptr;
      }
      pMaterialOut.m_ppTextures[13] = nullptr;
      if ( (int)pMaterialOut.m_ppTextures[12] >= 0 )
      {
        if ( pMaterialOut.m_ppTextures[10] != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pMaterialOut.m_ppTextures[10]);
          pMaterialOut.m_ppTextures[10] = nullptr;
        }
        pMaterialOut.m_ppTextures[11] = nullptr;
      }
      pMaterialOut.m_ppTextures[14] = pMaterialOut.m_ppTextures[10];
      if ( (int)pMaterialOut.m_ppTextures[12] >= 0 && pMaterialOut.m_ppTextures[10] != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pMaterialOut.m_ppTextures[10]);
      v248 += 8;
      ++v247;
    }
    while ( v247 < numtexdata );
  }
  _Msg(a1: "Collecting bsp geometry...\n", a2, a3, a1);
  v245 = 0;
  if ( numfaces > 0 )
  {
    v248 = (int *)dfaces;
    do
    {
      if ( ((1 << (v245 & 0x1F)) & *(_DWORD *)&v228[4 * (v245 >> 5)]) != 0 )
      {
        v44 = v248;
        v45 = &texinfo.m_Memory.m_pMemory[*((__int16 *)v248 + 5)];
        texdata = v45->texdata;
        v47 = texdata;
        v48 = &dtexdata[texdata];
        v49 = 63;
        m_pVMT = (int)v223.m_Memory.m_pMemory[v47].m_pVMT;
        v50 = v193;
        do
        {
          *(v50 - 5) = 0;
          *(v50 - 4) = 0;
          *(v50 - 3) = 0;
          *(v50 - 2) = 0;
          *(v50 - 1) = 0;
          *v50 = 0;
          v50[1] = 0;
          v50[2] = 0;
          v50[3] = 0;
          v50 += 9;
          --v49;
        }
        while ( v49 >= 0 );
        v51 = *((__int16 *)v44 + 4);
        if ( v51 > 0 )
        {
          v211 = v45->textureVecsTexelsPerWorldUnits[0][1];
          v214 = v45->textureVecsTexelsPerWorldUnits[0][0];
          v215 = v45->textureVecsTexelsPerWorldUnits[0][2];
          v210 = v45->textureVecsTexelsPerWorldUnits[0][3];
          v52 = 1.0 / (float)v48->width;
          v216 = v45->textureVecsTexelsPerWorldUnits[1][1];
          v208 = v45->textureVecsTexelsPerWorldUnits[1][0];
          v209 = v45->textureVecsTexelsPerWorldUnits[1][2];
          v53 = *(unsigned __int16 *)v248;
          v213 = v45->textureVecsTexelsPerWorldUnits[1][3];
          v54 = _mm_cvtsi32_si128(v48->height);
          v55 = v248[1];
          v56 = &dplanes[v53];
          v57 = 1.0 / _mm_cvtepi32_ps(v54).m128_f32[0];
          x = v56->normal.x;
          v224.m_pElements = (CVTFTexture::ResourceMemorySection *)LODWORD(v56->normal.y);
          z_low = LODWORD(v56->normal.z);
          v58 = &dsurfedges[v55];
          v59 = v193;
          for ( k = v51; k != 0; --k )
          {
            v61 = *v58;
            if ( *v58 >= 0 )
              v62 = dedges[v61].v[0];
            else
              v62 = (unsigned __int16)word_374A4EA[-2 * v61];
            v63 = 3 * v62;
            v64 = *(&dvertexes.y + v63);
            v65 = *(&dvertexes.x + v63);
            v66 = *(&dvertexes.z + v63);
            *((float *)v59 - 5) = v65;
            v67 = v65;
            v68 = v65 * v208;
            v69 = v67 * v214;
            *((float *)v59 - 4) = v64;
            *((float *)v59 - 3) = v66;
            v70 = v69 + (float)(v64 * v211);
            v71 = v66 * v215;
            *((float *)v59 + 2) = (float)((float)((float)(v68 + (float)(v64 * v216)) + (float)(v66 * v209)) + v213)
                                * v57;
            v72 = x;
            *((float *)v59 + 1) = (float)((float)(v70 + v71) + v210) * v52;
            *((float *)v59 - 2) = v72;
            *(v59 - 1) = (int)v224.m_pElements;
            *v59 = z_low;
            ++v58;
            v59 += 9;
          }
        }
        v73 = v248[12] & 0x7FFF;
        v74 = v51 - 2;
        v244 = (CUtlVector<BaseWorldVertex_t,CUtlMemory<BaseWorldVertex_t,int> > *)v73;
        if ( v73 != 0 )
        {
          v246 = nullptr;
          do
          {
            v237 = &g_primitives[(int)v246 + *((unsigned __int16 *)v248 + 25)];
            v247 = 0;
            if ( v237->indexCount != 0 )
            {
              v75 = (CUtlVector<BaseWorldVertex_t,CUtlMemory<BaseWorldVertex_t,int> > *)(m_pVMT + 132);
              v76 = (CUtlMemory<S3RGBA,int> *)(m_pVMT + 152);
              do
              {
                v77 = v247 + v237->firstIndex;
                v78 = g_primindices[v77];
                v77 *= 2;
                v78 *= 9;
                *(_DWORD *)&pMaterialOut.m_Material.m_Binds[13].m_cBindSlot = *(&v189 + v78);
                *(_DWORD *)&pMaterialOut.m_Material.m_Binds[14].m_cBindSampler = *(&v190 + v78);
                pMaterialOut.m_Material.m_flPhongExp = *(float *)&v192[v78 - 1];
                v79 = *(float *)&v192[v78];
                v80 = &v189 + v78;
                pMaterialOut.m_Material.m_flPhongBoost = v79;
                *(_DWORD *)&pMaterialOut.m_Material.m_bAlphaTest = v80[4];
                *(_DWORD *)&pMaterialOut.m_Material.m_bNormalMap = v80[5];
                pMaterialOut.m_nTextures = v80[6];
                pMaterialOut.m_ppTextures[0] = (TextureData_t *)v80[7];
                v81 = (TextureData_t *)v80[8];
                v82 = *(unsigned __int16 *)((char *)&word_584579A + v77);
                pMaterialOut.m_ppTextures[1] = v81;
                v82 *= 9;
                pMaterialOut.m_ppTextures[2] = (TextureData_t *)*(&v189 + v82);
                v83 = (TextureData_t *)*(&v190 + v82);
                v84 = &v189 + v82;
                pMaterialOut.m_ppTextures[3] = v83;
                pMaterialOut.m_ppTextures[4] = (TextureData_t *)v84[2];
                pMaterialOut.m_ppTextures[5] = (TextureData_t *)v84[3];
                pMaterialOut.m_ppTextures[6] = (TextureData_t *)v84[4];
                pMaterialOut.m_ppTextures[7] = (TextureData_t *)v84[5];
                pMaterialOut.m_ppTextures[8] = (TextureData_t *)v84[6];
                pMaterialOut.m_ppTextures[9] = (TextureData_t *)v84[7];
                v85 = (TextureData_t *)v84[8];
                v86 = *(unsigned __int16 *)((char *)&word_584579C + v77);
                v87 = v75->m_Size;
                pMaterialOut.m_ppTextures[10] = v85;
                v86 *= 9;
                v88 = (TextureData_t *)*(&v189 + v86);
                v89 = &v189 + v86;
                pMaterialOut.m_ppTextures[11] = v88;
                pMaterialOut.m_ppTextures[12] = (TextureData_t *)v89[1];
                pMaterialOut.m_ppTextures[13] = (TextureData_t *)v89[2];
                pMaterialOut.m_ppTextures[14] = (TextureData_t *)v89[3];
                pMaterialOut.m_ppTextures[15] = (TextureData_t *)v89[4];
                pMaterialOut.m_originalMaterialName = *(CUtlString *)(v89 + 5);
                v90 = CUtlVector<BaseWorldVertex_t,CUtlMemory<BaseWorldVertex_t,int>>::InsertBefore(
                        this: v75,
                        elem: v87,
                        src: (const BaseWorldVertex_t *)&pMaterialOut.m_Material.m_Binds[13].m_cBindSlot);
                v91 = v76[1].m_pMemory;
                v242 = v90;
                m_nAllocationCount = v76->m_nAllocationCount;
                if ( (int)&v91->g > m_nAllocationCount )
                  CUtlMemory<HemiLightData_t *,int>::Grow(this: v76, num: (int)(&v91->g - m_nAllocationCount));
                ++v76[1].m_pMemory;
                v93 = v76->m_pMemory;
                v94 = (char *)v76[1].m_pMemory - (char *)v91 - 1;
                v76[1].m_nAllocationCount = (int)v76->m_pMemory;
                if ( v94 > 0 )
                  _V_memmove(dest: &v93[(_DWORD)v91 + 1], src: &v93[(_DWORD)v91], count: 4 * v94);
                v95 = (int *)&v76->m_pMemory[(_DWORD)v91];
                if ( v95 != nullptr )
                  *v95 = v242;
                v96 = CUtlVector<BaseWorldVertex_t,CUtlMemory<BaseWorldVertex_t,int>>::InsertBefore(
                        this: v75,
                        elem: v75->m_Size,
                        src: (const BaseWorldVertex_t *)&pMaterialOut.m_ppTextures[2]);
                v97 = v76[1].m_pMemory;
                v242 = v96;
                v98 = v76->m_nAllocationCount;
                if ( (int)&v97->g > v98 )
                  CUtlMemory<HemiLightData_t *,int>::Grow(this: v76, num: (int)(&v97->g - v98));
                ++v76[1].m_pMemory;
                v99 = v76->m_pMemory;
                v100 = (char *)v76[1].m_pMemory - (char *)v97 - 1;
                v76[1].m_nAllocationCount = (int)v76->m_pMemory;
                if ( v100 > 0 )
                  _V_memmove(dest: &v99[(_DWORD)v97 + 1], src: &v99[(_DWORD)v97], count: 4 * v100);
                v101 = (int *)&v76->m_pMemory[(_DWORD)v97];
                if ( v101 != nullptr )
                  *v101 = v242;
                v102 = CUtlVector<BaseWorldVertex_t,CUtlMemory<BaseWorldVertex_t,int>>::InsertBefore(
                         this: v75,
                         elem: v75->m_Size,
                         src: (const BaseWorldVertex_t *)&pMaterialOut.m_ppTextures[11]);
                v103 = v76[1].m_pMemory;
                v242 = v102;
                v104 = v76->m_nAllocationCount;
                if ( (int)&v103->g > v104 )
                  CUtlMemory<HemiLightData_t *,int>::Grow(this: v76, num: (int)(&v103->g - v104));
                ++v76[1].m_pMemory;
                v105 = v76->m_pMemory;
                v106 = (char *)v76[1].m_pMemory - (char *)v103 - 1;
                v76[1].m_nAllocationCount = (int)v76->m_pMemory;
                if ( v106 > 0 )
                  _V_memmove(dest: &v105[(_DWORD)v103 + 1], src: &v105[(_DWORD)v103], count: 4 * v106);
                v107 = (int *)&v76->m_pMemory[(_DWORD)v103];
                if ( v107 != nullptr )
                  *v107 = v242;
                indexCount = v237->indexCount;
                v247 += 3;
              }
              while ( v247 < indexCount );
            }
            v246 = (CUtlVector<BaseWorldVertex_t,CUtlMemory<BaseWorldVertex_t,int> > *)((char *)v246 + 1);
          }
          while ( (int)v246 < (int)v244 );
        }
        else if ( v74 > 0 )
        {
          v246 = (CUtlVector<BaseWorldVertex_t,CUtlMemory<BaseWorldVertex_t,int> > *)(m_pVMT + 132);
          v109 = (CUtlMemory<S3RGBA,int> *)(m_pVMT + 152);
          v110 = &v194;
          for ( m_pVMT = v74; m_pVMT != 0; --m_pVMT )
          {
            *(_DWORD *)&pMaterialOut.m_Material.m_Binds[13].m_cBindSlot = v189;
            *(_DWORD *)&pMaterialOut.m_Material.m_Binds[14].m_cBindSampler = v190;
            pMaterialOut.m_Material.m_flPhongExp = v191;
            LODWORD(pMaterialOut.m_Material.m_flPhongBoost) = v192[0];
            *(_DWORD *)&pMaterialOut.m_Material.m_bAlphaTest = v192[1];
            *(_DWORD *)&pMaterialOut.m_Material.m_bNormalMap = v193[0];
            pMaterialOut.m_nTextures = v193[1];
            pMaterialOut.m_ppTextures[0] = (TextureData_t *)v193[2];
            pMaterialOut.m_ppTextures[1] = (TextureData_t *)v193[3];
            pMaterialOut.m_ppTextures[2] = *((TextureData_t **)v110 - 5);
            pMaterialOut.m_ppTextures[3] = *((TextureData_t **)v110 - 4);
            pMaterialOut.m_ppTextures[4] = *((TextureData_t **)v110 - 3);
            pMaterialOut.m_ppTextures[5] = *((TextureData_t **)v110 - 2);
            pMaterialOut.m_ppTextures[6] = *((TextureData_t **)v110 - 1);
            pMaterialOut.m_ppTextures[7] = *(TextureData_t **)v110;
            v111 = v246->m_Size;
            pMaterialOut.m_ppTextures[8] = *((TextureData_t **)v110 + 1);
            pMaterialOut.m_ppTextures[9] = *((TextureData_t **)v110 + 2);
            pMaterialOut.m_ppTextures[10] = *((TextureData_t **)v110 + 3);
            pMaterialOut.m_ppTextures[11] = *((TextureData_t **)v110 + 4);
            pMaterialOut.m_ppTextures[12] = *((TextureData_t **)v110 + 5);
            pMaterialOut.m_ppTextures[13] = *((TextureData_t **)v110 + 6);
            pMaterialOut.m_ppTextures[14] = *((TextureData_t **)v110 + 7);
            pMaterialOut.m_ppTextures[15] = *((TextureData_t **)v110 + 8);
            pMaterialOut.m_originalMaterialName = *(CUtlString *)(v110 + 36);
            v112 = CUtlVector<BaseWorldVertex_t,CUtlMemory<BaseWorldVertex_t,int>>::InsertBefore(
                     this: v246,
                     elem: v111,
                     src: (const BaseWorldVertex_t *)&pMaterialOut.m_Material.m_Binds[13].m_cBindSlot);
            v113 = v109[1].m_pMemory;
            v244 = (CUtlVector<BaseWorldVertex_t,CUtlMemory<BaseWorldVertex_t,int> > *)v112;
            v114 = v109->m_nAllocationCount;
            if ( (int)&v113->g > v114 )
              CUtlMemory<HemiLightData_t *,int>::Grow(this: v109, num: (int)(&v113->g - v114));
            ++v109[1].m_pMemory;
            v115 = v109->m_pMemory;
            v116 = (char *)v109[1].m_pMemory - (char *)v113 - 1;
            v109[1].m_nAllocationCount = (int)v109->m_pMemory;
            if ( v116 > 0 )
              _V_memmove(dest: &v115[(_DWORD)v113 + 1], src: &v115[(_DWORD)v113], count: 4 * v116);
            v117 = &v109->m_pMemory[(_DWORD)v113];
            if ( v117 != nullptr )
              *v117 = (S3RGBA)v244;
            v118 = CUtlVector<BaseWorldVertex_t,CUtlMemory<BaseWorldVertex_t,int>>::InsertBefore(
                     this: v246,
                     elem: v246->m_Size,
                     src: (const BaseWorldVertex_t *)&pMaterialOut.m_ppTextures[2]);
            v119 = v109[1].m_pMemory;
            v244 = (CUtlVector<BaseWorldVertex_t,CUtlMemory<BaseWorldVertex_t,int> > *)v118;
            v120 = v109->m_nAllocationCount;
            if ( (int)&v119->g > v120 )
              CUtlMemory<HemiLightData_t *,int>::Grow(this: v109, num: (int)(&v119->g - v120));
            ++v109[1].m_pMemory;
            v121 = v109->m_pMemory;
            v122 = (char *)v109[1].m_pMemory - (char *)v119 - 1;
            v109[1].m_nAllocationCount = (int)v109->m_pMemory;
            if ( v122 > 0 )
              _V_memmove(dest: &v121[(_DWORD)v119 + 1], src: &v121[(_DWORD)v119], count: 4 * v122);
            v123 = &v109->m_pMemory[(_DWORD)v119];
            if ( v123 != nullptr )
              *v123 = (S3RGBA)v244;
            v124 = CUtlVector<BaseWorldVertex_t,CUtlMemory<BaseWorldVertex_t,int>>::InsertBefore(
                     this: v246,
                     elem: v246->m_Size,
                     src: (const BaseWorldVertex_t *)&pMaterialOut.m_ppTextures[11]);
            v125 = v109[1].m_pMemory;
            v244 = (CUtlVector<BaseWorldVertex_t,CUtlMemory<BaseWorldVertex_t,int> > *)v124;
            v126 = v109->m_nAllocationCount;
            if ( (int)&v125->g > v126 )
              CUtlMemory<HemiLightData_t *,int>::Grow(this: v109, num: (int)(&v125->g - v126));
            ++v109[1].m_pMemory;
            v127 = v109->m_pMemory;
            v128 = (char *)v109[1].m_pMemory - (char *)v125 - 1;
            v109[1].m_nAllocationCount = (int)v109->m_pMemory;
            if ( v128 > 0 )
              _V_memmove(dest: &v127[(_DWORD)v125 + 1], src: &v127[(_DWORD)v125], count: 4 * v128);
            v129 = &v109->m_pMemory[(_DWORD)v125];
            if ( v129 != nullptr )
              *v129 = (S3RGBA)v244;
            v110 += 36;
          }
        }
      }
      v248 += 14;
      ++v245;
    }
    while ( v245 < numfaces );
  }
  _Msg(a1: "Collecting displacement geometry...\n");
  v244 = (CUtlVector<BaseWorldVertex_t,CUtlMemory<BaseWorldVertex_t,int> > *)texinfo.m_Size;
  z_low = g_CoreDispInfos.m_Size;
  v247 = 0;
  v246 = (CUtlVector<BaseWorldVertex_t,CUtlMemory<BaseWorldVertex_t,int> > *)1;
  if ( g_CoreDispInfos.m_Size > 0 )
  {
    while ( 1 )
    {
      v130 = 0.001;
      if ( ((unsigned int)v246 & *(_DWORD *)&v232[4 * (v247 >> 5)]) != 0 )
        break;
LABEL_174:
      ++v247;
      v246 = (CUtlVector<BaseWorldVertex_t,CUtlMemory<BaseWorldVertex_t,int> > *)__ROL4__(v246, 1);
      if ( v247 >= z_low )
        goto LABEL_175;
    }
    v131 = g_CoreDispInfos.m_Memory.m_pMemory[v247];
    v132 = g_CoreDispTexInfos.m_Memory.m_pMemory[v247];
    v133 = texinfo.m_Memory.m_pMemory[v132].texdata;
    if ( v132 < (int)v244 )
    {
      if ( !v223.m_Memory.m_pMemory[v133].m_bNoDraw )
      {
        v165 = dword_5C98870[8 * v133];
        if ( v165 != 0 )
        {
          v166 = dword_5C98874[8 * v133];
          if ( v166 != 0 )
          {
            *(float *)&v224.m_Size = 1.0 / (float)v165;
            v130 = 1.0 / (float)v166;
            goto LABEL_150;
          }
        }
      }
    }
    else
    {
      printf(format: "Out of range texinfo for disp %d\n", v247);
      v130 = 0.001;
    }
    v133 = v222;
    v224.m_Size = 981668463;
LABEL_150:
    v134 = &v223.m_Memory.m_pMemory[v133];
    *(float *)&v224.m_pElements = v130;
    v237 = (dprimitive_t *)v134;
    TriCount = CCoreDispInfo::GetTriCount(this: v131);
    m_Power = v131->m_Power;
    v242 = TriCount;
    v245 = v134->m_Vertices.m_Size;
    if ( ((1 << m_Power) + 1) * ((1 << m_Power) + 1) > 0 )
    {
      v137 = 0;
      m_pVMT = ((1 << m_Power) + 1) * ((1 << m_Power) + 1);
      do
      {
        m_pVerts = v131->m_pVerts;
        v139 = v134->m_Vertices.m_Size;
        v140 = m_pVerts[v137].m_TexCoord.y * *(float *)&v224.m_pElements;
        v207.m_vPos = m_pVerts[v137].m_Vert;
        v207.m_vTexcoord.x = m_pVerts[v137].m_TexCoord.x * *(float *)&v224.m_Size;
        v207.m_vTexcoord.z = 0.0;
        v207.m_vNormal.x = m_pVerts[v137].m_Normal.x;
        v207.m_vNormal.y = m_pVerts[v137].m_Normal.y;
        z = m_pVerts[v137].m_Normal.z;
        v207.m_vTexcoord.y = v140;
        v207.m_vNormal.z = z;
        CUtlVector<BaseWorldVertex_t,CUtlMemory<BaseWorldVertex_t,int>>::InsertBefore(
          this: &v134->m_Vertices,
          elem: v139,
          src: &v207);
        ++v137;
        --m_pVMT;
      }
      while ( m_pVMT != 0 );
    }
    m_RenderIndices = v131->m_RenderIndices;
    if ( v242 > 0 )
    {
      p_firstIndex = (CUtlMemory<S3RGBA,int> *)&v237[15].firstIndex;
      v248 = (int *)(m_RenderIndices + 2);
      for ( m_pVMT = v242; m_pVMT != 0; --m_pVMT )
      {
        v144 = p_firstIndex[1].m_pMemory;
        v145 = p_firstIndex->m_nAllocationCount;
        v146 = v245 + *((unsigned __int16 *)v248 - 2);
        if ( (int)&v144->g > v145 )
          CUtlMemory<HemiLightData_t *,int>::Grow(this: p_firstIndex, num: (int)(&v144->g - v145));
        ++p_firstIndex[1].m_pMemory;
        v147 = p_firstIndex->m_pMemory;
        v148 = (char *)p_firstIndex[1].m_pMemory - (char *)v144 - 1;
        p_firstIndex[1].m_nAllocationCount = (int)p_firstIndex->m_pMemory;
        if ( v148 > 0 )
          _V_memmove(dest: &v147[(_DWORD)v144 + 1], src: &v147[(_DWORD)v144], count: 4 * v148);
        v149 = &p_firstIndex->m_pMemory[(_DWORD)v144];
        if ( v149 != nullptr )
          *v149 = (S3RGBA)v146;
        v150 = p_firstIndex[1].m_pMemory;
        v151 = p_firstIndex->m_nAllocationCount;
        v152 = v245 + *((unsigned __int16 *)v248 - 1);
        if ( (int)&v150->g > v151 )
          CUtlMemory<HemiLightData_t *,int>::Grow(this: p_firstIndex, num: (int)(&v150->g - v151));
        ++p_firstIndex[1].m_pMemory;
        v153 = p_firstIndex->m_pMemory;
        v154 = (char *)p_firstIndex[1].m_pMemory - (char *)v150 - 1;
        p_firstIndex[1].m_nAllocationCount = (int)p_firstIndex->m_pMemory;
        if ( v154 > 0 )
          _V_memmove(dest: &v153[(_DWORD)v150 + 1], src: &v153[(_DWORD)v150], count: 4 * v154);
        v155 = &p_firstIndex->m_pMemory[(_DWORD)v150];
        if ( v155 != nullptr )
          *v155 = (S3RGBA)v152;
        v156 = p_firstIndex[1].m_pMemory;
        v157 = p_firstIndex->m_nAllocationCount;
        v158 = v245 + *(unsigned __int16 *)v248;
        if ( (int)&v156->g > v157 )
          CUtlMemory<HemiLightData_t *,int>::Grow(this: p_firstIndex, num: (int)(&v156->g - v157));
        ++p_firstIndex[1].m_pMemory;
        v159 = p_firstIndex->m_pMemory;
        v160 = (char *)p_firstIndex[1].m_pMemory - (char *)v156 - 1;
        p_firstIndex[1].m_nAllocationCount = (int)p_firstIndex->m_pMemory;
        if ( v160 > 0 )
          _V_memmove(dest: &v159[(_DWORD)v156 + 1], src: &v159[(_DWORD)v156], count: 4 * v160);
        v161 = &p_firstIndex->m_pMemory[(_DWORD)v156];
        if ( v161 != nullptr )
          *v161 = (S3RGBA)v158;
        v248 = (int *)((char *)v248 + 6);
      }
    }
    goto LABEL_174;
  }
LABEL_175:
  v162 = _CommandLine();
  v241 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v162 + 40))(a1: v162, a2: "-noprops") == 0;
  memset(&v217, 0, 20);
  memset(&v217.m_materialList.m_Elements.m_Tree.m_Elements, 0, sizeof(v217.m_materialList.m_Elements.m_Tree.m_Elements));
  v217.m_materialList.m_Elements.m_Tree.m_Root = -1;
  v217.m_materialList.m_Elements.m_Tree.m_NumElements = 0;
  v217.m_materialList.m_Elements.m_Tree.m_FirstFree = -1;
  v217.m_materialList.m_Elements.m_Tree.m_LastAlloc.index = -1;
  memset(&v217.m_materialList.m_Elements.m_Tree.m_pElements, 0, 64);
  v217.m_materialList.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  memset(&v240, 0, sizeof(v240));
  if ( v241 )
  {
    _Msg(a1: "Collecting prop_static instances...\n");
    v163 = list->props.m_Size;
    if ( v240.m_Memory.m_nAllocationCount < v163 && v240.m_Memory.m_nGrowSize >= 0 )
    {
      v240.m_Memory.m_nAllocationCount = list->props.m_Size;
      v187 = 4 * v163;
      if ( v240.m_Memory.m_pMemory != nullptr )
        v164 = (CVTFTexture::ResourceMemorySection *)_g_pMemAlloc->Realloc_2(
                                                       this: _g_pMemAlloc,
                                                       a2: v240.m_Memory.m_pMemory,
                                                       a3: v187);
      else
        v164 = (CVTFTexture::ResourceMemorySection *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v187);
      v240.m_Memory.m_pMemory = v164;
    }
    v167 = 0;
    v240.m_pElements = v240.m_Memory.m_pMemory;
    if ( list->props.m_Size > 0 )
    {
      v168 = v240.m_Size;
      v245 = 0;
      do
      {
        if ( ((1 << (v167 & 0x1F)) & *(_DWORD *)&v236[4 * (v167 >> 5)]) != 0 )
        {
          v244 = (CUtlVector<BaseWorldVertex_t,CUtlMemory<BaseWorldVertex_t,int> > *)((char *)&list->props.m_Memory.m_pMemory->propIndex
                                                                                    + v245);
          v169 = v168;
          if ( v168 + 1 > v240.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<HemiLightData_t *,int>::Grow(
              this: (CUtlMemory<S3RGBA,int> *)&v240,
              num: v168 - v240.m_Memory.m_nAllocationCount + 1);
            v168 = v240.m_Size;
          }
          v170 = ++v168 - v169 - 1;
          v240.m_Size = v168;
          v240.m_pElements = v240.m_Memory.m_pMemory;
          if ( v170 > 0 )
          {
            _V_memmove(
              dest: &v240.m_Memory.m_pMemory->m_nDataLength + v169,
              src: &v240.m_Memory.m_pMemory->m_nDataAllocSize + v169,
              count: 4 * v170);
            v168 = v240.m_Size;
          }
          v171 = &v240.m_Memory.m_pMemory->m_nDataAllocSize + v169;
          if ( v171 != nullptr )
          {
            *v171 = (int)v244->m_Memory.m_pMemory;
            v168 = v240.m_Size;
          }
        }
        v245 += 32;
        ++v167;
      }
      while ( v167 < list->props.m_Size );
    }
    CStaticPropBuilder::Generate(this: &v217, propList: (CUtlVector<int,CUtlMemory<int,int> > *)&v240);
  }
  _Msg(a1: "Initializing D3D\n");
  params.m_flMinSimplifiedDist = 5000.0;
  params.m_flHorzFOV = 1.5707964;
  params.m_flHalfScreenWidth = 960.0;
  params.m_flMinDrawVolumeSize = 512.0;
  params.m_flGutterSize = 8.0;
  params.m_flMinDistToCamera = 300.0;
  params.m_flUVMapThreshold = 0.30000001;
  params.m_nSizeBytesPerVoxel = (int)&loc_600000;
  params.m_flMinAtlasDist = 1000.0;
  params.m_nAtlasTextureSizeX = 512;
  params.m_nAtlasTextureSizeY = 512;
  params.m_nUniqueTextureSizeX = 1024;
  params.m_nUniqueTextureSizeY = 1024;
  params.m_vWorldUnitsPerTile.x = 10000.0;
  params.m_vWorldUnitsPerTile.y = 10000.0;
  params.m_vWorldUnitsPerTile.z = 1000.0;
  params.m_nMaxTexScaleSlots = 128;
  params.m_bWrapInAtlas = false;
  MemRequired = ImageLoader::GetMemRequired(
                  width: 512,
                  height: 512,
                  depth: 0,
                  imageFormat: IMAGE_FORMAT_DXT1,
                  mipmap: true,
                  pAdjustedHeight: nullptr);
  params.m_nCompressedAtlasSize = (MemRequired
                                 + ImageLoader::GetMemRequired(
                                     width: params.m_nAtlasTextureSizeX,
                                     height: params.m_nAtlasTextureSizeY,
                                     depth: 0,
                                     imageFormat: IMAGE_FORMAT_DXT5,
                                     mipmap: true,
                                     pAdjustedHeight: nullptr))
                                / 2;
  _Msg(a1: "Avg compressed atlas size: %d\n", params.m_nCompressedAtlasSize);
  ppd3d9 = nullptr;
  ppd3dDevice = nullptr;
  if ( CreateQuickD3DDevice(&ppd3d9, &ppd3dDevice) )
  {
    CBVHNodeBuilder::CBVHNodeBuilder(this: &rootNode);
    if ( v223.m_Size > 0 )
    {
      p_m_nGrowSize = &v223.m_Memory.m_pMemory->m_Vertices.m_Memory.m_nGrowSize;
      for ( m = v223.m_Size; m != 0; --m )
      {
        if ( *((_BYTE *)p_m_nGrowSize - 12) == 0 && p_m_nGrowSize[6] >= 3 )
        {
          CUtlString::CUtlString(this: &pMaterialOut.m_originalMaterialName);
          if ( CreateMaterialFromVMT(&pMaterialOut, pVMTName: (char *)p_m_nGrowSize - 140) == 0 )
            _Warning(a1: "Cannot load %s\n", (const char *)p_m_nGrowSize - 140);
          V_strncpy(pDest: pMaterialOut.m_Material.m_szShaderVS, pSrc: "maps\\worldgenericvs", maxLen: 48);
          V_strncpy(pDest: pMaterialOut.m_Material.m_szShaderPS, pSrc: "maps\\worldgenericps", maxLen: 48);
          CUtlString::operator=(this: &pMaterialOut.m_originalMaterialName, src: (const char *)p_m_nGrowSize - 140);
          CBVHNodeBuilder::AddMesh(
            this: &rootNode,
            nVertexLayout: nullptr,
            nIndicesPerFace: 3,
            pVertices: (float *)*(p_m_nGrowSize - 2),
            pIndices: (unsigned int *)p_m_nGrowSize[3],
            nIndices: p_m_nGrowSize[6],
            material: &pMaterialOut,
            bFlipWinding: true);
          p_m_nGrowSize[1] = 0;
          if ( *p_m_nGrowSize >= 0 )
          {
            if ( *(p_m_nGrowSize - 2) != 0 )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)*(p_m_nGrowSize - 2));
              *(p_m_nGrowSize - 2) = 0;
            }
            *(p_m_nGrowSize - 1) = 0;
          }
          p_m_nGrowSize[2] = *(p_m_nGrowSize - 2);
          p_m_nGrowSize[6] = 0;
          if ( p_m_nGrowSize[5] >= 0 )
          {
            if ( p_m_nGrowSize[3] != 0 )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)p_m_nGrowSize[3]);
              p_m_nGrowSize[3] = 0;
            }
            p_m_nGrowSize[4] = 0;
          }
          p_m_nGrowSize[7] = p_m_nGrowSize[3];
          pMaterialOut.m_originalMaterialName.m_Storage.m_nActualLength = 0;
          if ( pMaterialOut.m_originalMaterialName.m_Storage.m_Memory.m_nGrowSize >= 0
            && pMaterialOut.m_originalMaterialName.m_Storage.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(
              this: _g_pMemAlloc,
              a2: pMaterialOut.m_originalMaterialName.m_Storage.m_Memory.m_pMemory);
          }
        }
        p_m_nGrowSize += 43;
      }
    }
    V_GetCurrentDirectory(pOut, maxLen: 260);
    v180 = _CommandLine();
    v181 = (const char *)(*(int (__thiscall **)(int, const char *, const char *))(*(_DWORD *)v180 + 32))(
                           a1: v180,
                           a2: "-outfile",
                           a3: "testscene");
    V_snprintf(pDest, maxLen: 260, pFormat: "maps\\%s.tmp", v181);
    V_snprintf(pDest: pPageFileName, maxLen: 260, pFormat: "maps\\%s.wrf", v181);
    V_snprintf(pDest: pszFileName, maxLen: 260, pFormat: "maps\\%s.whf", v181);
    V_snprintf(pDest: path, maxLen: 260, pFormat: "%s\\%s", pOut, v181);
    V_snprintf(pDest: v201, maxLen: 260, pFormat: "%s\\props", pOut);
    if ( !g_pFullFileSystem->IsDirectory(this: g_pFullFileSystem, a2: path, a3: nullptr) )
      Q_mkdir(path);
    if ( !g_pFullFileSystem->IsDirectory(this: g_pFullFileSystem, a2: v201, a3: nullptr) )
      Q_mkdir(path: v201);
    strcpy(pDirName, "..");
    V_SetCurrentDirectory(pDirName);
    memset(&v207.m_vNormal.y, 0, 20);
    memset(&v224, 0, sizeof(v224));
    if ( v241 )
      CStaticPropBuilder::AddInstances(
        this: &v217,
        &rootNode,
        propList: (CUtlVector<int,CUtlMemory<int,int> > *)&v240,
        bFlipWinding: true);
    CStaticPropBuilder::Cleanup(this: &v217);
    CWorldRendererBuilder::CWorldRendererBuilder(this: &v202, pRootNode: &rootNode);
    v182 = CWorldRendererBuilder::CreateTree(
             this: &v202,
             a2: (int)&savedregs,
             pMapName: v181,
             pTempFileName: pDest,
             pPageFileName,
             pd3dDevice: ppd3dDevice,
             &params,
             pEntities: (entity_t *)&entities,
             nEntities: num_entities);
    _Msg(a1: "Num nodes: %d\n", v182);
    v183 = CWorldRendererBuilder::Serialize(
             this: &v202,
             pMapName: v181,
             pd3dDevice: ppd3dDevice,
             pszFileName,
             pszTempFile: pDest,
             pszPageFile: pPageFileName,
             TreeOrder: (CBVHNodeBuilder *)1,
             &params);
    _Msg(a1: "bvh storage = %d\n", v183);
    ppd3dDevice->Release(this: ppd3dDevice);
    ppd3dDevice = nullptr;
    ppd3d9->Release(this: ppd3d9);
    ppd3d9 = nullptr;
    _Msg(a1: "Serialized %s\n", pszFileName);
    CWorldRendererBuilder::~CWorldRendererBuilder(this: &v202);
    CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: &v224);
    CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v207.m_vNormal.y);
    CBVHNodeBuilder::~CBVHNodeBuilder(this: &rootNode);
    CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: &v240);
    CStaticPropBuilder::~CStaticPropBuilder(this: &v217);
    CUtlVector<MeshAccumulator_t,CUtlMemory<MeshAccumulator_t,int>>::~CUtlVector<MeshAccumulator_t,CUtlMemory<MeshAccumulator_t,int>>(this: &v223);
  }
  else
  {
    _Msg(a1: "Error creating D3D device");
    v173 = v240.m_Memory.m_pMemory;
    v240.m_Size = 0;
    if ( v240.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v240.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v240.m_Memory.m_pMemory);
        v173 = nullptr;
        v240.m_Memory.m_pMemory = nullptr;
      }
      v240.m_Memory.m_nAllocationCount = 0;
    }
    v240.m_pElements = v173;
    if ( v240.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v173 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v173);
        v240.m_Memory.m_pMemory = nullptr;
      }
      v240.m_Memory.m_nAllocationCount = 0;
    }
    v174 = v217.m_materialLinearList.m_Memory.m_pMemory;
    v217.m_materialLinearList.m_Size = 0;
    if ( v217.m_materialLinearList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v217.m_materialLinearList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v217.m_materialLinearList.m_Memory.m_pMemory);
        v174 = nullptr;
        v217.m_materialLinearList.m_Memory.m_pMemory = nullptr;
      }
      v217.m_materialLinearList.m_Memory.m_nAllocationCount = 0;
    }
    v217.m_materialLinearList.m_pElements = v174;
    if ( v217.m_materialLinearList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v174 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v174);
        v217.m_materialLinearList.m_Memory.m_pMemory = nullptr;
      }
      v217.m_materialLinearList.m_Memory.m_nAllocationCount = 0;
    }
    v175 = v217.m_instanceList.m_Memory.m_pMemory;
    v217.m_instanceList.m_Size = 0;
    if ( v217.m_instanceList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v217.m_instanceList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v217.m_instanceList.m_Memory.m_pMemory);
        v175 = nullptr;
        v217.m_instanceList.m_Memory.m_pMemory = nullptr;
      }
      v217.m_instanceList.m_Memory.m_nAllocationCount = 0;
    }
    v217.m_instanceList.m_pElements = v175;
    if ( v217.m_instanceList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v175 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v175);
        v217.m_instanceList.m_Memory.m_pMemory = nullptr;
      }
      v217.m_instanceList.m_Memory.m_nAllocationCount = 0;
    }
    v176 = v217.m_batchList.m_Size - 1;
    if ( v217.m_batchList.m_Size - 1 >= 0 )
    {
      v177 = v176;
      do
      {
        CModelBatch::~CModelBatch(this: &v217.m_batchList.m_Memory.m_pMemory[v177]);
        --v176;
        --v177;
      }
      while ( v176 >= 0 );
    }
    v178 = v217.m_batchList.m_Memory.m_pMemory;
    v217.m_batchList.m_Size = 0;
    if ( v217.m_batchList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v217.m_batchList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v217.m_batchList.m_Memory.m_pMemory);
        v178 = nullptr;
        v217.m_batchList.m_Memory.m_pMemory = nullptr;
      }
      v217.m_batchList.m_Memory.m_nAllocationCount = 0;
    }
    v217.m_batchList.m_pElements = v178;
    if ( v217.m_batchList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v178 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v178);
        v217.m_batchList.m_Memory.m_pMemory = nullptr;
      }
      v217.m_batchList.m_Memory.m_nAllocationCount = 0;
    }
    CUtlDict<propmaterial_list_t,int>::RemoveAll(this: &v217.m_materialList);
    CUtlRBTree<CUtlMap<char const *,propmaterial_list_t,int>::Node_t,int,CUtlMap<char const *,propmaterial_list_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,propmaterial_list_t,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,propmaterial_list_t,int>::Node_t,int,CUtlMap<char const *,propmaterial_list_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,propmaterial_list_t,int>::Node_t,int>,int>>(this: &v217.m_materialList.m_Elements.m_Tree);
    CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v217);
    CUtlVector<MeshAccumulator_t,CUtlMemory<MeshAccumulator_t,int>>::~CUtlVector<MeshAccumulator_t,CUtlMemory<MeshAccumulator_t,int>>(this: &v223);
  }
  if ( leaves.m_numInts > 1u )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: leaves.m_pInt);
  leaves.m_pInt = nullptr;
  if ( v230 > 1u )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v232);
  v232 = nullptr;
  if ( v234 > 1u )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v236);
  v236 = nullptr;
  if ( v226 > 1u )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v228);
  v228 = nullptr;
  if ( v218.m_numInts > 1u )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v218.m_pInt);
}

//------------------------------------------------------------------------------
// Address: 0x0043BF40
// Name: void EndBSPFile(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall EndBSPFile(int a1@<ebx>, int a2@<edi>, int a3@<esi>)
{
  char v3; // cf
  unsigned int v4; // ecx
  unsigned __int16 *v5; // edi
  int i; // ecx
  int v7; // [esp-8h] [ebp-444h]
  char targetPath[1024]; // [esp+0h] [ebp-43Ch] BYREF
  CStaticPropList list; // [esp+400h] [ebp-3Ch] BYREF

  EmitBrushes();
  EmitPlanes();
  SaveVertexNormals();
  UpdateAllFaceLightmapExtents();
  EmitDispLMAlphaAndNeighbors();
  SmoothDispSurfNormals(ppListBase: g_CoreDispInfos.m_Memory.m_pMemory, nListSize: g_CoreDispInfos.m_Size);
  Overlay_EmitOverlayFaces();
  OverlayTransition_EmitOverlayFaces();
  if ( numleafs > 0 )
  {
    v7 = a2;
    v3 = numleafs & 1;
    v4 = (unsigned int)numleafs >> 1;
    memset(g_LeafMinDistToWater, 0, 4 * ((unsigned int)numleafs >> 1));
    v5 = &g_LeafMinDistToWater[2 * v4];
    for ( i = v3; i != 0; --i )
      *v5++ = 0;
    a2 = v7;
  }
  memset(&list, 0, sizeof(list));
  EmitStaticProps(&list);
  EmitDetailObjects();
  ComputeBoundsNoSkybox();
  EnsurePresenceOfWaterLODControlEntity();
  UnparseEntities();
  CompactTexinfos();
  DiscoverMacroTextures();
  V_snprintf(pDest: targetPath, maxLen: 1024, pFormat: "%s.bvh", source);
  _Msg(a1: "Writing %s\n", targetPath);
  EmitBVH(a1, a2, a3, &list);
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&list.leafProps);
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&list.leafList);
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&list);
}

//------------------------------------------------------------------------------
// Address: 0x00457880
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class CDmElementFactoryHelper __near *,int>::Node_t,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum DmElementHandle_t,int>::Node_t,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,enum DmElementHandle_t,int>::Node_t,int> *m_pMemory; // edx
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
        m_nAllocationCount = 2;
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
    v7 = 24 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,enum DmElementHandle_t,int>::Node_t,int> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,enum DmElementHandle_t,int>::Node_t,int> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00514770
// Name: public: void CUtlDict<class CDmElementFactoryHelper __near *,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CDmElementFactoryHelper *,int>::RemoveAll(CUtlDict<CDmElementFactoryHelper *,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int,CUtlMap<char const *,CDmElementFactoryHelper *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int,CUtlMap<char const *,CDmElementFactoryHelper *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int,CUtlMap<char const *,CDmElementFactoryHelper *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x00515480
// Name: public: int CUtlMap<char const __near *,class CDmElementFactoryHelper __near *,int>::Insert(char const __near * const __near &,class CDmElementFactoryHelper __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlMap<char const *,CDmElementFactoryHelper *,int>::Insert(
        CUtlMap<char const *,CDmElementFactoryHelper *,int> *this,
        const char **key,
        int insert)
{
  CDmElementFactoryHelper *v4; // eax
  int v5; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int> *m_pMemory; // ecx
  CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t node; // [esp+8h] [ebp-8h] BYREF

  v4 = *(CDmElementFactoryHelper **)insert;
  node.key = *key;
  node.elem = v4;
  insert = -1;
  LOBYTE(key) = 0;
  CUtlRBTree<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int,CUtlMap<char const *,CDmElementFactoryHelper *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>>::FindInsertionPosition(
    this: &this->m_Tree,
    insert: &node,
    parent: &insert,
    leftchild: (bool *)&key);
  v5 = CUtlRBTree<CUtlMap<char const *,enum DmElementHandle_t,int>::Node_t,int,CUtlMap<char const *,enum DmElementHandle_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum DmElementHandle_t,int>::Node_t,int>,int>>::NewNode((CUtlRBTree<CUtlMap<char const *,enum DmElementHandle_t,int>::Node_t,int,CUtlMap<char const *,enum DmElementHandle_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum DmElementHandle_t,int>::Node_t,int>,int> > *)this);
  CUtlRBTree<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int,CUtlMap<char const *,CDmElementFactoryHelper *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>>::LinkToParent(
    this: &this->m_Tree,
    i: v5,
    parent: insert,
    isLeft: (bool)key);
  m_pMemory = this->m_Tree.m_Elements.m_pMemory;
  ++this->m_Tree.m_NumElements;
  if ( &m_pMemory[v5] != (UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int> *)-16 )
    m_pMemory[v5].m_Data = node;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00516250
// Name: public: int CUtlDict<class CDmElementFactoryHelper __near *,int>::Insert(char const __near *,class CDmElementFactoryHelper __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<CDmElementFactoryHelper *,int>::Insert(
        CUtlDict<CDmElementFactoryHelper *,int> *this,
        char *pName,
        CDmElementFactoryHelper *const *element)
{
  const char *v3; // edi
  char *v5; // eax

  v3 = pName;
  if ( pName != nullptr && (v5 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v5, v3);
  else
    v5 = nullptr;
  pName = v5;
  return CUtlMap<char const *,CDmElementFactoryHelper *,int>::Insert(
           this: &this->m_Elements,
           key: (const char **)&pName,
           insert: (int)element);
}

//------------------------------------------------------------------------------
// Address: 0x0055A990
// Name: public: void CUtlDict<class CDmElement __near *,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CDmElement *,int>::RemoveAll(CUtlDict<CDmElement *,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,CDmElement *,int>::Node_t,int,CUtlMap<char const *,CDmElement *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElement *,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,CDmElement *,int>::Node_t,int,CUtlMap<char const *,CDmElement *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElement *,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,CDmElement *,int>::Node_t,int,CUtlMap<char const *,CDmElement *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElement *,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x0055B620
// Name: public: int CUtlMap<char const __near *,class CDmElement __near *,int>::Insert(char const __near * const __near &,class CDmElement __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlMap<char const *,CDmElement *,int>::Insert(
        CUtlMap<char const *,CDmElement *,int> *this,
        const char **key,
        int insert)
{
  CDmElement *v4; // eax
  int v5; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CDmElement *,int>::Node_t,int> *m_pMemory; // ecx
  CUtlMap<char const *,CDmElement *,int>::Node_t node; // [esp+8h] [ebp-8h] BYREF

  v4 = *(CDmElement **)insert;
  node.key = *key;
  node.elem = v4;
  insert = -1;
  LOBYTE(key) = 0;
  CUtlRBTree<CUtlMap<char const *,CDmElement *,int>::Node_t,int,CUtlMap<char const *,CDmElement *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElement *,int>::Node_t,int>,int>>::FindInsertionPosition(
    this: &this->m_Tree,
    insert: &node,
    parent: &insert,
    leftchild: (bool *)&key);
  v5 = CUtlRBTree<CUtlMap<char const *,enum DmElementHandle_t,int>::Node_t,int,CUtlMap<char const *,enum DmElementHandle_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum DmElementHandle_t,int>::Node_t,int>,int>>::NewNode((CUtlRBTree<CUtlMap<char const *,enum DmElementHandle_t,int>::Node_t,int,CUtlMap<char const *,enum DmElementHandle_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum DmElementHandle_t,int>::Node_t,int>,int> > *)this);
  CUtlRBTree<CUtlMap<char const *,CDmElement *,int>::Node_t,int,CUtlMap<char const *,CDmElement *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElement *,int>::Node_t,int>,int>>::LinkToParent(
    this: &this->m_Tree,
    i: v5,
    parent: insert,
    isLeft: (bool)key);
  m_pMemory = this->m_Tree.m_Elements.m_pMemory;
  ++this->m_Tree.m_NumElements;
  if ( &m_pMemory[v5] != (UtlRBTreeNode_t<CUtlMap<char const *,CDmElement *,int>::Node_t,int> *)-16 )
    m_pMemory[v5].m_Data = node;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x0055C0B0
// Name: public: int CUtlDict<class CDmElement __near *,int>::Insert(char const __near *,class CDmElement __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<CDmElement *,int>::Insert(
        CUtlDict<CDmElement *,int> *this,
        char *pName,
        CDmElement *const *element)
{
  const char *v3; // edi
  char *v5; // eax

  v3 = pName;
  if ( pName != nullptr && (v5 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v5, v3);
  else
    v5 = nullptr;
  pName = v5;
  return CUtlMap<char const *,CDmElement *,int>::Insert(
           this: &this->m_Elements,
           key: (const char **)&pName,
           insert: (int)element);
}
