// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vvis/vvis.cpp
// Functions: 21
// ============================================================

#include "utils\vvis\vvis.h"

//------------------------------------------------------------------------------
// Address: 0x100149D0
// Name: int PComp(void const __near *,void const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl PComp(const void *a, const void *b)
{
  int v2; // eax
  int v3; // ecx

  v2 = *(_DWORD *)(*(_DWORD *)a + 56);
  v3 = *(_DWORD *)(*(_DWORD *)b + 56);
  if ( v2 == v3 )
    return 0;
  else
    return 2 * (v2 >= v3) - 1;
}

//------------------------------------------------------------------------------
// Address: 0x10014A00
// Name: void SortPortals(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SortPortals()
{
  signed int v0; // edx
  signed int v1; // eax
  portal_t *v2; // ecx

  v0 = 2 * g_numportals;
  v1 = 0;
  if ( 2 * g_numportals > 0 )
  {
    v2 = portals;
    do
      sorted_portals[v1++] = v2++;
    while ( v1 < v0 );
  }
  if ( !nosort )
    qsort(base: sorted_portals, num: v0, width: 4u, comp: PComp);
}

//------------------------------------------------------------------------------
// Address: 0x10014A50
// Name: int LeafVectorFromPortalVector(unsigned char __near *,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl LeafVectorFromPortalVector(unsigned __int8 *portalbits, unsigned __int8 *leafbits)
{
  int v2; // esi
  int v3; // edi

  memset(dst: leafbits, value: 0, count: leafbytes);
  v2 = 0;
  if ( 2 * g_numportals > 0 )
  {
    v3 = 0;
    do
    {
      if ( ((unsigned __int8)(1 << (v2 & 7)) & portalbits[v2 >> 3]) != 0 )
        leafbits[portals[v3].leaf >> 3] |= 1 << (portals[v3].leaf & 7);
      ++v2;
      ++v3;
    }
    while ( v2 < 2 * g_numportals );
  }
  return CountBits(bits: leafbits, numbits: portalclusters);
}

//------------------------------------------------------------------------------
// Address: 0x10014AE0
// Name: CompressAndCrosscheckClusterVis
// Source: json
//------------------------------------------------------------------------------
int __cdecl CompressAndCrosscheckClusterVis(int clusternum)
{
  int v1; // ebx
  unsigned __int8 *v2; // edi
  int v3; // eax
  unsigned __int8 *v4; // esi
  unsigned int v5; // esi
  unsigned __int8 *v6; // edi
  unsigned __int8 dest[8192]; // [esp+Ch] [ebp-200Ch] BYREF
  int v9; // [esp+200Ch] [ebp-Ch]
  unsigned __int8 *i; // [esp+2010h] [ebp-8h]
  int v11; // [esp+2014h] [ebp-4h]

  v1 = clusternum;
  v2 = &uncompressedvis[clusternum * leafbytes];
  v3 = 0;
  v11 = 0;
  for ( i = v2; v3 < portalclusters; ++v3 )
  {
    if ( v3 != v1 )
    {
      v4 = &v2[v3 >> 3];
      v9 = v3 & 7;
      if ( ((unsigned __int8)(1 << (v3 & 7)) & *v4) != 0 )
      {
        v2 = i;
        if ( ((unsigned __int8)(1 << (clusternum & 7)) & uncompressedvis[v3 * leafbytes + (clusternum >> 3)]) == 0 )
        {
          *v4 &= ~(1 << v9);
          ++v11;
        }
      }
    }
    v1 = clusternum;
  }
  v5 = CompressVis(vis: v2, dest);
  v6 = vismap_p;
  vismap_p += v5;
  if ( vismap_p > vismap_end )
    _Error(a1: "Vismap expansion overflow");
  dvis->bitofs[v1][0] = v6 - vismap;
  memcpy(dst: v6, src: dest, count: v5);
  DecompressVis(in: &vismap[dvis->bitofs[v1][0]], decompressed: dest);
  return v11;
}

//------------------------------------------------------------------------------
// Address: 0x10014C00
// Name: void CalcPortalVis(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CalcPortalVis()
{
  int v0; // ecx
  int v1; // eax

  if ( fastvis )
  {
    v0 = 0;
    if ( 2 * g_numportals > 0 )
    {
      v1 = 0;
      do
      {
        portals[v1].portalvis = portals[v1].portalflood;
        portals[v1].status = stat_done;
        ++v0;
        ++v1;
      }
      while ( v0 < 2 * g_numportals );
    }
  }
  else if ( g_bUseMPI )
  {
    RunMPIPortalFlow();
  }
  else
  {
    printf(format: "%-20s ", "PortalFlow:");
    RunThreadsOnIndividual(workcnt: 2 * g_numportals, showpacifier: 1, func: PortalFlow);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014C90
// Name: void SetPortalSphere(struct portal_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetPortalSphere(portal_t *p)
{
  portal_t *v1; // ecx
  float x; // xmm1_4
  float y; // xmm2_4
  float z; // xmm3_4
  winding_t *winding; // edi
  int numpoints; // esi
  int v7; // edx
  unsigned int v8; // ecx
  float *p_z; // eax
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm3_4
  float v18; // xmm0_4
  float v19; // xmm3_4
  float *v20; // eax
  int v21; // ecx
  float v22; // xmm5_4
  float v23; // xmm0_4
  float v24; // xmm3_4
  float v25; // xmm4_4
  float v26; // xmm5_4
  float v27; // xmm6_4
  float *v28; // eax
  float v29; // xmm0_4

  v1 = p;
  x = vec3_origin.x;
  y = vec3_origin.y;
  z = vec3_origin.z;
  winding = p->winding;
  numpoints = winding->numpoints;
  v7 = 0;
  if ( numpoints >= 4 )
  {
    v8 = ((unsigned int)(numpoints - 4) >> 2) + 1;
    p_z = &winding->points[0].z;
    v7 = 4 * v8;
    do
    {
      v10 = *(p_z - 2) + x;
      v11 = *(p_z - 1) + y;
      v12 = *p_z + z;
      v13 = p_z[1] + v10;
      v14 = p_z[2] + v11;
      v15 = p_z[3] + v12;
      v16 = p_z[4] + v13;
      v17 = p_z[5] + v14;
      v18 = p_z[6] + v15;
      x = p_z[7] + v16;
      y = p_z[8] + v17;
      v19 = p_z[9];
      p_z += 12;
      --v8;
      z = v19 + v18;
    }
    while ( v8 != 0 );
    v1 = p;
  }
  if ( v7 < numpoints )
  {
    v20 = &winding->points[v7].z;
    v21 = numpoints - v7;
    do
    {
      x = x + *(v20 - 2);
      y = y + *(v20 - 1);
      z = z + *v20;
      v20 += 3;
      --v21;
    }
    while ( v21 != 0 );
    v1 = p;
  }
  v22 = 1.0 / (float)numpoints;
  v23 = v22 * z;
  v24 = 0.0;
  v25 = v22 * x;
  v26 = v22 * y;
  v27 = v23;
  if ( numpoints > 0 )
  {
    v28 = &winding->points[0].z;
    do
    {
      v29 = fsqrt(
              (float)((float)((float)(*(v28 - 1) - v26) * (float)(*(v28 - 1) - v26))
                    + (float)((float)(*v28 - v27) * (float)(*v28 - v27)))
            + (float)((float)(*(v28 - 2) - v25) * (float)(*(v28 - 2) - v25)));
      if ( v29 > v24 )
        v24 = v29;
      v28 += 3;
      --numpoints;
    }
    while ( numpoints != 0 );
  }
  v1->origin.x = v25;
  v1->origin.y = v26;
  v1->origin.z = v27;
  v1->radius = v24;
}

//------------------------------------------------------------------------------
// Address: 0x10014E40
// Name: void CalcPAS(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CalcPAS()
{
  int v0; // ebx
  unsigned __int8 *v1; // esi
  int v2; // eax
  int v3; // edx
  int v4; // ecx
  int v5; // edi
  int v6; // esi
  int v7; // eax
  int v8; // ecx
  int v9; // eax
  char v10; // cl
  int v11; // esi
  unsigned int v12; // edi
  unsigned __int8 *v13; // esi
  int v14; // ebx
  unsigned __int8 dest[8192]; // [esp+0h] [ebp-4018h] BYREF
  unsigned __int8 dst[4]; // [esp+2000h] [ebp-2018h] BYREF
  unsigned __int8 *v17; // [esp+4000h] [ebp-18h]
  int v18; // [esp+4004h] [ebp-14h]
  int v19; // [esp+4008h] [ebp-10h]
  int v20; // [esp+400Ch] [ebp-Ch]
  int v21; // [esp+4010h] [ebp-8h]
  int v22; // [esp+4014h] [ebp-4h]

  _Msg(a1: "Building PAS...\n");
  v22 = 0;
  v21 = 0;
  if ( portalclusters > 0 )
  {
    do
    {
      v0 = leafbytes;
      v1 = &uncompressedvis[v21 * leafbytes];
      v17 = v1;
      memcpy(dst, src: v1, count: leafbytes);
      v2 = 0;
      v20 = 0;
      if ( v0 > 0 )
      {
        v3 = leaflongs;
        do
        {
          v4 = v1[v2];
          v18 = v4;
          if ( v4 != 0 )
          {
            v5 = 0;
            v19 = 1;
            while ( 1 )
            {
              if ( (v4 & v19) != 0 )
              {
                v6 = v5 + 8 * v2;
                if ( v6 >= portalclusters )
                {
                  _Error(a1: "Bad bit in PVS");
                  v3 = leaflongs;
                  v0 = leafbytes;
                }
                v7 = 0;
                if ( v3 > 0 )
                {
                  v8 = &uncompressedvis[v6 * v0] - dst;
                  do
                  {
                    *(_DWORD *)&dst[4 * v7] |= *(_DWORD *)&dst[4 * v7 + v8];
                    ++v7;
                  }
                  while ( v7 < v3 );
                }
              }
              v2 = v20;
              ++v5;
              v19 = __ROL4__(v19, 1);
              if ( v5 >= 8 )
                break;
              v4 = v18;
            }
            v1 = v17;
          }
          v20 = ++v2;
        }
        while ( v2 < v0 );
      }
      v9 = 0;
      v10 = 1;
      if ( portalclusters > 0 )
      {
        v11 = v22;
        do
        {
          if ( ((unsigned __int8)v10 & dst[v9 >> 3]) != 0 )
            ++v11;
          ++v9;
          v10 = __ROL1__(v10, 1);
        }
        while ( v9 < portalclusters );
        v22 = v11;
      }
      v12 = CompressVis(vis: dst, dest);
      v13 = vismap_p;
      vismap_p += v12;
      if ( vismap_p > vismap_end )
        _Error(a1: "Vismap expansion overflow");
      v14 = v21;
      dvis->bitofs[v21][1] = v13 - vismap;
      memcpy(dst: v13, src: dest, count: v12);
      v21 = v14 + 1;
    }
    while ( v14 + 1 < portalclusters );
  }
  _Msg(a1: "Average clusters audible: %i\n", v22 / portalclusters);
}

//------------------------------------------------------------------------------
// Address: 0x10015010
// Name: GetBoundsForFace
// Source: json
//------------------------------------------------------------------------------
void __usercall GetBoundsForFace(int faceID@<eax>, Vector *faceMin, Vector *faceMax)
{
  int v4; // edi
  int numedges; // edx
  int firstedge; // esi
  dface_t *v7; // edi
  int v8; // ecx
  const Vector *v9; // ebx

  ClearBounds(mins: faceMin, maxs: faceMax);
  v4 = faceID;
  numedges = dfaces[faceID].numedges;
  firstedge = dfaces[faceID].firstedge;
  v7 = &dfaces[v4];
  if ( firstedge < firstedge + numedges )
  {
    do
    {
      v8 = dsurfedges[firstedge];
      if ( v8 < 0 )
        v8 = -v8;
      v9 = &dvertexes + (unsigned __int16)word_102AF25A[2 * v8];
      AddPointToBounds(v: &dvertexes + dedges[v8].v[0], mins: faceMin, maxs: faceMax);
      AddPointToBounds(v: v9, mins: faceMin, maxs: faceMax);
      ++firstedge;
    }
    while ( firstedge < v7->firstedge + v7->numedges );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100150C0
// Name: float DetermineVisRadius(void)
// Source: json
//------------------------------------------------------------------------------
double __cdecl DetermineVisRadius()
{
  int v0; // esi
  entity_t *i; // edi
  const char *v2; // eax
  double result; // st7

  v0 = 0;
  if ( num_entities <= 0 )
    return -1.0;
  for ( i = entities; ; ++i )
  {
    v2 = ValueForKey(ent: i, key: "classname");
    if ( _V_stricmp(s1: v2, s2: "env_fog_controller") == 0 )
      break;
    if ( ++v0 >= num_entities )
      return -1.0;
  }
  result = FloatForKey(ent: &entities[v0], key: "farz");
  if ( result == 0.0 )
    return -1.0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10015160
// Name: int ParseCommandLine(int,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ParseCommandLine(int argc, char **argv)
{
  int v2; // esi
  const char *v3; // edi

  v2 = 1;
  if ( argc > 1 )
  {
    while ( 1 )
    {
      if ( _V_stricmp(s1: argv[v2], s2: "-threads") != 0 )
      {
        if ( _V_stricmp(s1: argv[v2], s2: "-fast") == 0 )
        {
          _Msg(a1: "fastvis = true\n");
          fastvis = true;
          goto LABEL_36;
        }
        if ( _V_stricmp(s1: argv[v2], s2: "-v") == 0 || _V_stricmp(s1: argv[v2], s2: "-verbose") == 0 )
        {
          _Msg(a1: "verbose = true\n");
          verbose = 1;
          goto LABEL_36;
        }
        if ( _V_stricmp(s1: argv[v2], s2: "-radius_override") == 0 )
        {
          g_bUseRadius = true;
          g_VisRadius = atof(nptr: argv[++v2]);
          _Msg(a1: "Vis Radius = %4.2f\n", (double)g_VisRadius);
          g_VisRadius = g_VisRadius * g_VisRadius;
          goto LABEL_36;
        }
        if ( _V_stricmp(s1: argv[v2], s2: "-trace") == 0 )
        {
          g_TraceClusterStart = atoi(nptr: argv[v2 + 1]);
          g_TraceClusterStop = atoi(nptr: argv[v2 + 2]);
          v2 += 2;
          _Msg(a1: "Tracing vis from cluster %d to %d\n", g_TraceClusterStart, g_TraceClusterStop);
          goto LABEL_36;
        }
        if ( _V_stricmp(s1: argv[v2], s2: "-nosort") == 0 )
        {
          _Msg(a1: "nosort = true\n");
          nosort = true;
          goto LABEL_36;
        }
        if ( _V_stricmp(s1: argv[v2], s2: "-tmpin") == 0 )
        {
          strcpy(inbase, "/tmp");
          goto LABEL_36;
        }
        if ( _V_stricmp(s1: argv[v2], s2: "-low") == 0 )
        {
          g_bLowPriority = true;
          goto LABEL_36;
        }
        if ( _V_stricmp(s1: argv[v2], s2: "-FullMinidumps") == 0 )
        {
          EnableFullMinidumps(bFull: true);
          goto LABEL_36;
        }
        if ( _V_stricmp(s1: argv[v2], s2: "-NoVConfig") == 0 )
          goto LABEL_36;
        if ( _V_stricmp(s1: argv[v2], s2: "-vproject") != 0 && _V_stricmp(s1: argv[v2], s2: "-game") != 0 )
        {
          if ( _V_stricmp(s1: argv[v2], s2: "-allowdebug") != 0 && _V_stricmp(s1: argv[v2], s2: "-steam") != 0 )
          {
            if ( V_strncasecmp(s1: argv[v2], s2: "-mpi", n: 4) != 0
              && V_strncasecmp(s1: argv[v2 - 1], s2: "-mpi", n: 4) != 0 )
            {
              if ( _V_stricmp(s1: argv[v2], s2: "-tempcontent") != 0 )
              {
                v3 = argv[v2];
                if ( *v3 == 45 )
                {
                  _Warning(a1: "VBSP: Unknown option \"%s\"\n\n", v3);
                  return 100000;
                }
                return v2;
              }
            }
            else
            {
              if ( _V_stricmp(s1: argv[v2], s2: "-mpi") == 0 )
                g_bUseMPI = true;
              if ( v2 == argc - 1 )
                return v2;
            }
          }
          goto LABEL_36;
        }
      }
      else
      {
        numthreads = atoi(nptr: argv[v2 + 1]);
      }
      ++v2;
LABEL_36:
      if ( ++v2 >= argc )
        return v2;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10015480
// Name: void PrintCommandLine(int,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PrintCommandLine(int argc, char **argv)
{
  int i; // esi

  _Warning(a1: "Command line: ");
  for ( i = 0; i < argc; ++i )
    _Warning(a1: "\"%s\" ", argv[i]);
  _Warning(a1: "\n\n");
}

//------------------------------------------------------------------------------
// Address: 0x100154E0
// Name: void ClusterMerge(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClusterMerge(int clusternum)
{
  leaf_t *v1; // ebx
  int i; // edi
  portal_t *v3; // esi
  int v4; // eax
  int v5; // ecx
  int v6; // esi
  unsigned __int8 dst[4]; // [esp+Ch] [ebp-6000h] BYREF
  unsigned __int8 leafbits[8192]; // [esp+400Ch] [ebp-2000h] BYREF

  memset(dst, value: 0, count: portalbytes);
  v1 = &leafs[clusternum];
  for ( i = 0; i < v1->portals.m_Size; dst[(v3 - portals) >> 3] |= 1 << ((v3 - portals) & 7) )
  {
    v3 = v1->portals.m_Memory.m_pMemory[i];
    if ( v3->status != stat_done )
      _Error(a1: "portal not done %d %d %d\n", i, v3, portals);
    v4 = 0;
    if ( portallongs > 0 )
    {
      v5 = v3->portalvis - dst;
      do
      {
        *(_DWORD *)&dst[4 * v4] |= *(_DWORD *)&dst[4 * v4 + v5];
        ++v4;
      }
      while ( v4 < portallongs );
    }
    ++i;
  }
  v6 = LeafVectorFromPortalVector(portalbits: dst, leafbits) + 1;
  leafbits[clusternum >> 3] |= 1 << (clusternum & 7);
  memcpy(dst: &uncompressedvis[clusternum * leafbytes], src: leafbits, count: leafbytes);
  qprintf(format: "cluster %4i : %4i visible\n", clusternum, v6);
  totalvis += v6;
}

//------------------------------------------------------------------------------
// Address: 0x10015620
// Name: void CalcVisTrace(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CalcVisTrace()
{
  leaf_t *v0; // ecx
  int m_Size; // edx
  int v2; // eax

  printf(format: "%-20s ", "BasePortalVis:");
  RunThreadsOnIndividual(workcnt: 2 * g_numportals, showpacifier: 1, func: BasePortalVis);
  v0 = &leafs[g_TraceClusterStart];
  m_Size = v0->portals.m_Size;
  v2 = 0;
  for ( g_numportals = m_Size; v2 < m_Size; ++v2 )
    sorted_portals[v2] = v0->portals.m_Memory.m_pMemory[v2];
  printf(format: "%-20s ", "PortalFlow:");
  RunThreadsOnIndividual(workcnt: g_numportals, showpacifier: 1, func: PortalFlow);
}

//------------------------------------------------------------------------------
// Address: 0x100156B0
// Name: void CalcVis(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CalcVis()
{
  int v0; // eax
  int i; // esi
  int v2; // edi
  int v3; // esi
  int v4; // eax
  double v5; // [esp-10h] [ebp-10h]

  if ( g_bUseMPI )
  {
    RunMPIBasePortalVis();
  }
  else
  {
    printf(format: "%-20s ", "BasePortalVis:");
    RunThreadsOnIndividual(workcnt: 2 * g_numportals, showpacifier: 1, func: BasePortalVis);
  }
  SortPortals();
  CalcPortalVis();
  v0 = portalclusters;
  for ( i = 0; i < portalclusters; ++i )
  {
    ClusterMerge(clusternum: i);
    v0 = portalclusters;
  }
  v2 = 0;
  v3 = 0;
  if ( v0 > 0 )
  {
    do
    {
      v4 = CompressAndCrosscheckClusterVis(clusternum: v3++);
      v2 += v4;
    }
    while ( v3 < portalclusters );
  }
  HIDWORD(v5) = 100 * v2 / totalvis;
  LODWORD(v5) = totalvis;
  _Msg(a1: "Optimized: %d visible clusters (%.2f%%)\n", v2, v5);
  _Msg(a1: "Total clusters visible: %i\n", totalvis);
  _Msg(a1: "Average clusters visible: %i\n", totalvis / portalclusters);
}

//------------------------------------------------------------------------------
// Address: 0x10015780
// Name: CalcDistanceFromLeafToWater
// Source: json
//------------------------------------------------------------------------------
int __usercall CalcDistanceFromLeafToWater@<eax>(int leafNum@<ecx>, int a2@<ebp>)
{
  int result; // eax
  void *v3; // esp
  int v4; // esi
  int v5; // edi
  int v6; // ecx
  int v7; // edx
  int v8; // eax
  float v9; // xmm1_4
  int v10; // ecx
  float v11; // xmm1_4
  int v12; // edx
  float v13; // xmm1_4
  int v14; // ecx
  clusterlist_t *m_pMemory; // esi
  int v16; // edx
  int v17; // ecx
  unsigned int v18; // edi
  int v19; // eax
  unsigned __int16 *v20; // esi
  int v21; // eax
  __int16 texinfo; // cx
  float v23; // xmm1_4
  int i; // eax
  float v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm1_4
  float v28; // xmm0_4
  __int128 v29; // xmm0
  int v30; // ecx
  _QWORD v31[1026]; // [esp-2070h] [ebp-207Ch] BYREF
  Vector v32; // [esp-58h] [ebp-64h] BYREF
  Vector v33; // [esp-4Ch] [ebp-58h] BYREF
  Vector v34; // [esp-40h] [ebp-4Ch] BYREF
  float v35; // [esp-34h] [ebp-40h]
  float v36; // [esp-30h] [ebp-3Ch]
  float v37; // [esp-2Ch] [ebp-38h]
  Vector v38; // [esp-28h] [ebp-34h] BYREF
  float v39; // [esp-1Ch] [ebp-28h]
  int v40; // [esp-18h] [ebp-24h]
  int v41; // [esp-14h] [ebp-20h]
  int v42; // [esp-10h] [ebp-1Ch]
  float v43; // [esp-Ch] [ebp-18h]
  int v44; // [esp-8h] [ebp-14h]
  int v45; // [esp-4h] [ebp-10h]
  int v46; // [esp+0h] [ebp-Ch]
  void *v47; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v46 = a2;
  v47 = retaddr;
  result = 8312;
  v3 = alloca(8312);
  v4 = 16 * leafNum;
  if ( (dleafs[leafNum].contents & 0x100) != 0 || word_1008B274[16 * leafNum] != -1 )
  {
    v5 = word_1008B25C[16 * leafNum];
    v40 = v5;
    if ( v5 >= 0 )
    {
      DecompressVis(in: &dvisdata[dvis->bitofs[v5][0]], decompressed: (unsigned __int8 *)v31);
      v6 = word_1008B262[v4];
      v7 = word_1008B264[v4];
      v8 = word_1008B266[v4];
      v34.x = (float)word_1008B260[v4];
      v9 = (float)v6;
      v10 = word_1008B268[v4];
      v34.y = v9;
      v11 = (float)v7;
      v12 = word_1008B26A[v4];
      v34.z = v11;
      v13 = (float)v8;
      result = (int)dvis;
      v38.x = v13;
      v38.y = (float)v10;
      v14 = 0;
      v38.z = (float)v12;
      v43 = 65535.0;
      v45 = 0;
      if ( dvis->numclusters > 0 )
      {
        m_pMemory = g_ClusterLeaves.m_Memory.m_pMemory;
        v16 = 0;
        v44 = 0;
        do
        {
          if ( v14 != v5 )
          {
            if ( ((unsigned __int8)(1 << (v14 & 7)) & *((_BYTE *)v31 + (v45 >> 3))) != 0 )
            {
              v17 = 0;
              v41 = 0;
              if ( *(int *)((char *)&m_pMemory->leafCount + v16) > 0 )
              {
                do
                {
                  v18 = 32 * (*(int **)((char *)&m_pMemory->leafs.m_Memory.m_pMemory + v16))[v17];
                  if ( (dleafs[v18 / 0x20].contents & 0x100) != 0 || word_1008B274[v18 / 2] != -1 )
                  {
                    v19 = (unsigned __int16)word_1008B26C[v18 / 2];
                    v42 = 0;
                    if ( word_1008B26E[v18 / 2] != 0 )
                    {
                      v20 = &dleaffaces[v19];
                      do
                      {
                        v21 = *v20;
                        texinfo = dfaces[v21].texinfo;
                        if ( texinfo != -1 && (::texinfo.m_Memory.m_pMemory[texinfo].flags & 8) != 0 )
                        {
                          GetBoundsForFace(faceID: v21, faceMin: &v33, faceMax: &v32);
                          if ( IsBoxIntersectingBox(boxMin1: &v34, boxMax1: &v38, boxMin2: &v33, boxMax2: &v32) )
                          {
                            v23 = 0.0;
                          }
                          else
                          {
                            for ( i = 0; i < 12; i += 4 )
                            {
                              v25 = *(float *)((char *)&v34.x + i);
                              v26 = *(float *)((char *)&v32.x + i);
                              if ( v26 < v25 || *(float *)((char *)&v38.x + i) < *(float *)((char *)&v33.x + i) )
                              {
                                v27 = v25 - v26;
                                v28 = *(float *)((char *)&v33.x + i) - *(float *)((char *)&v38.x + i);
                                if ( v27 > v28 )
                                  v28 = v27;
                                *(float *)((char *)&v35 + i) = v28;
                              }
                              else
                              {
                                *(float *)((char *)&v35 + i) = 0.0;
                              }
                            }
                            v39 = v35 * v35;
                            v29 = 0;
                            *(float *)&v29 = fsqrt((float)((float)(v35 * v35) + (float)(v36 * v36)) + (float)(v37 * v37));
                            *(_OWORD *)&v31[1024] = v29;
                            v23 = *(float *)&v29;
                          }
                          if ( v43 > v23 )
                            v43 = v23;
                        }
                        v30 = (unsigned __int16)word_1008B26E[v18 / 2];
                        ++v20;
                        ++v42;
                      }
                      while ( v42 < v30 );
                      m_pMemory = g_ClusterLeaves.m_Memory.m_pMemory;
                      v17 = v41;
                    }
                    v16 = v44;
                  }
                  v41 = ++v17;
                }
                while ( v17 < *(int *)((char *)&m_pMemory->leafCount + v16) );
                v5 = v40;
              }
            }
            v14 = v45;
          }
          result = (int)dvis;
          ++v14;
          v16 += 24;
          v45 = v14;
          v44 = v16;
        }
        while ( v14 < dvis->numclusters );
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10015A90
// Name: CalcVisibleFogVolumes
// Source: json
//------------------------------------------------------------------------------
void CalcVisibleFogVolumes()
{
  int v0; // esi
  unsigned int v1; // ecx
  unsigned __int16 *v2; // edi
  int v3; // ecx
  dleaf_t *v4; // edx
  dleaf_t *v5; // esi
  int contents; // eax
  int cluster; // ebx
  int v8; // edi
  clusterlist_t *m_pMemory; // esi
  int i; // edx
  unsigned int v11; // eax
  int v12; // ecx
  unsigned __int8 decompressed[8192]; // [esp+Ch] [ebp-2008h] BYREF
  int v14; // [esp+200Ch] [ebp-8h]
  dleaf_t *v15; // [esp+2010h] [ebp-4h]

  v0 = numleafs;
  if ( numleafs > 0 )
  {
    v1 = (unsigned int)numleafs >> 1;
    memset(g_LeafMinDistToWater, 0xFFu, 4 * ((unsigned int)numleafs >> 1));
    v2 = &g_LeafMinDistToWater[2 * v1];
    v3 = v0 & 1;
    v4 = dleafs;
    while ( v3 != 0 )
    {
      *v2++ = -1;
      --v3;
    }
    do
    {
      v4->contents &= ~0x100u;
      ++v4;
      --v0;
    }
    while ( v0 != 0 );
  }
  v14 = 0;
  if ( numleafs > 0 )
  {
    v5 = dleafs;
    v15 = dleafs;
    do
    {
      contents = v5->contents;
      if ( (v5->contents & 0x100) == 0 && (contents & 1) == 0 && v5->leafWaterDataID != -1 && (contents & 0x10) == 0 )
      {
        cluster = v5->cluster;
        if ( cluster >= 0 )
        {
          DecompressVis(in: &dvisdata[dvis->bitofs[cluster][0]], decompressed);
          v8 = 0;
          if ( dvis->numclusters > 0 )
          {
            m_pMemory = g_ClusterLeaves.m_Memory.m_pMemory;
            do
            {
              if ( v8 != cluster && ((unsigned __int8)(1 << (v8 & 7)) & decompressed[v8 >> 3]) != 0 )
              {
                for ( i = 0; i < m_pMemory->leafCount; ++i )
                {
                  v11 = 16 * m_pMemory->leafs.m_Memory.m_pMemory[i];
                  v12 = dleafs[v11 / 0x10].contents;
                  if ( (v12 & 1) == 0 && word_1008B274[v11] == -1 )
                    dleafs[v11 / 0x10].contents = v12 | 0x100;
                }
              }
              ++v8;
              ++m_pMemory;
            }
            while ( v8 < dvis->numclusters );
            v5 = v15;
          }
        }
      }
      ++v5;
      ++v14;
      v15 = v5;
    }
    while ( v14 < numleafs );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015BF0
// Name: void LoadPortals(char __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __cdecl LoadPortals(char *name)
{
  char *v1; // edi
  void *v2; // esi
  unsigned int (__thiscall *Size_2)(IBaseFileSystem *, void *); // edx
  int v4; // eax
  int v5; // esi
  unsigned int v6; // ebx
  void *v7; // esi
  _iobuf *v8; // esi
  _iobuf *v9; // esi
  const char *v10; // edi
  void (*v11)(const char *, ...); // ebx
  int v12; // ecx
  unsigned int v13; // esi
  unsigned int v14; // esi
  int v15; // esi
  portal_t *v16; // edi
  int v17; // esi
  int v18; // eax
  int v19; // esi
  char *v20; // esi
  float *v21; // ebx
  char *v22; // eax
  float v23; // xmm0_4
  float v24; // xmm0_4
  float v25; // xmm3_4
  float v26; // xmm1_4
  float v27; // xmm0_4
  float v28; // xmm2_4
  float v29; // xmm4_4
  float v30; // xmm5_4
  leaf_t *v31; // ebx
  void *v32; // ecx
  int m_nAllocationCount; // eax
  portal_t **m_pMemory; // edx
  int v35; // eax
  portal_t **v36; // ecx
  int v37; // eax
  leaf_t *v38; // ebx
  void *v39; // ecx
  portal_t *v40; // edi
  portal_t **v41; // edx
  int v42; // eax
  portal_t **v43; // ecx
  int v44; // ebx
  unsigned __int8 *v45; // ebx
  int v46; // edx
  int v47; // ebx
  float *p_x; // ecx
  float *v49; // eax
  unsigned int v50; // [esp-8h] [ebp-2ACh]
  char tempPath[260]; // [esp+Ch] [ebp-298h] BYREF
  char tempFile[260]; // [esp+110h] [ebp-194h] BYREF
  char magic[80]; // [esp+214h] [ebp-90h] BYREF
  _BYTE v54[24]; // [esp+264h] [ebp-40h] OVERLAPPED BYREF
  plane_t plane; // [esp+27Ch] [ebp-28h] BYREF
  int leafnums[2]; // [esp+28Ch] [ebp-18h] BYREF
  int i; // [esp+294h] [ebp-10h]
  int numpoints; // [esp+298h] [ebp-Ch] BYREF
  _iobuf *f; // [esp+29Ch] [ebp-8h]
  void *hFile; // [esp+2A0h] [ebp-4h]

  if ( g_bUseMPI )
  {
    if ( GetTempPathA(nBufferLength: 0x104u, lpBuffer: tempPath) == 0 )
      _Error(a1: "LoadPortals: GetTempPath failed.\n");
    v1 = nullptr;
    if ( GetTempFileNameA(lpPathName: tempPath, lpPrefixString: "vvis_portal_", uUnique: 0, lpTempFileName: tempFile) == 0 )
      _Error(a1: "LoadPortals: GetTempFileName failed.\n");
    v2 = g_pFileSystem->Open(this: g_pFileSystem, a2: name, a3: "r", a4: 0);
    hFile = v2;
    if ( v2 == nullptr )
      _Error(a1: "LoadPortals( %s ): couldn't get file from master.\n", name);
    Size_2 = g_pFileSystem->Size_2;
    memset(&v54[4], 0, 12);
    *(_DWORD *)&v54[20] = 0;
    v4 = Size_2(this: g_pFileSystem, a2: v2);
    v5 = v4;
    v6 = 0;
    *(_DWORD *)&v54[16] = 0;
    if ( v4 != 0 )
    {
      if ( v4 > 0 )
      {
        CUtlMemory<char,int>::Grow(this: (CUtlMemory<unsigned char,int> *)&v54[4], num: v4);
        v6 = *(_DWORD *)&v54[16];
        v1 = *(char **)&v54[4];
      }
      v6 += v5;
      *(_DWORD *)&v54[16] = v6;
      *(_DWORD *)&v54[20] = v1;
      if ( (int)(v6 - v5) > 0 && v5 > 0 )
        _V_memmove(dest: &v1[v5], src: v1, count: v6 - v5);
    }
    v7 = hFile;
    g_pFileSystem->Read(this: g_pFileSystem, a2: v1, a3: v6, a4: hFile);
    g_pFileSystem->Close(this: g_pFileSystem, a2: v7);
    v8 = fopen(file: tempFile, mode: "wt");
    fwrite(buffer: v1, size: 1u, count: v6, stream: v8);
    fclose(stream: v8);
    v9 = fopen(file: tempFile, mode: "rSTD");
    f = v9;
    CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&v54[4]);
    v10 = name;
  }
  else
  {
    v10 = name;
    f = fopen(file: name, mode: "r");
    v9 = f;
  }
  v11 = (void (*)(const char *, ...))_Error;
  if ( v9 == nullptr )
    _Error(a1: "LoadPortals: couldn't read %s\n", v10);
  if ( fscanf(stream: v9, format: "%79s\n%i\n%i\n", magic, &portalclusters, &g_numportals) != 3 )
    _Error(a1: "LoadPortals %s: failed to read header", v10);
  if ( _V_stricmp(s1: magic, s2: "PRT1") != 0 )
    _Error(a1: "LoadPortals %s: not a portal file", v10);
  _Msg(a1: "%4i portalclusters\n", portalclusters);
  _Msg(a1: "%4i numportals\n", g_numportals);
  v12 = g_numportals;
  if ( 2 * g_numportals >= 0x10000 )
  {
    _Error(a1: "The map overflows the max portal count (%d of max %d)!\n", g_numportals, 0x8000);
    v12 = g_numportals;
  }
  leafbytes = ((portalclusters + 63) >> 3) & 0xFFFFFFF8;
  leaflongs = leafbytes >> 2;
  portalbytes = ((2 * v12 + 63) >> 3) & 0xFFFFFFF8;
  v13 = 120 * v12;
  portallongs = portalbytes >> 2;
  portals = (portal_t *)malloc(size: 120 * v12);
  memset(dst: (unsigned __int8 *)portals, value: 0, count: v13);
  v14 = 20 * portalclusters;
  leafs = (leaf_t *)malloc(size: 20 * portalclusters);
  memset(dst: (unsigned __int8 *)leafs, value: 0, count: v14);
  v15 = portalclusters;
  originalvismapsize = portalclusters * leafbytes;
  uncompressedvis = (unsigned __int8 *)malloc(size: portalclusters * leafbytes);
  vismap = dvisdata;
  dvis->numclusters = v15;
  v16 = portals;
  v17 = 0;
  vismap_p = (unsigned __int8 *)dvis->bitofs[portalclusters];
  vismap_end = vismap + 0x1000000;
  i = 0;
  if ( g_numportals > 0 )
  {
    while ( 1 )
    {
      if ( fscanf(stream: f, format: "%i %i %i ", &numpoints, leafnums, &leafnums[1]) != 3 )
        v11(a1: "LoadPortals: reading portal %i", v17);
      v18 = numpoints;
      if ( numpoints > 64 )
      {
        v11(a1: "LoadPortals: portal %i has too many points", v17);
        v18 = numpoints;
      }
      if ( leafnums[0] > (unsigned int)portalclusters || leafnums[1] > (unsigned int)portalclusters )
      {
        v11(a1: "LoadPortals: reading portal %i", v17);
        v18 = numpoints;
      }
      v19 = v18;
      if ( v18 > 64 )
        v11(a1: "NewWinding: %i points, max %d", v18, 64);
      v50 = 12 * v19 + 8;
      v20 = (char *)malloc(size: v50);
      memset(dst: (unsigned __int8 *)v20, value: 0, count: v50);
      v16->winding = (winding_t *)v20;
      *(_DWORD *)v20 = 1;
      *((_DWORD *)v20 + 1) = numpoints;
      hFile = nullptr;
      if ( numpoints > 0 )
      {
        v21 = (float *)(v20 + 12);
        do
        {
          if ( fscanf(stream: f, format: "(%lf %lf %lf ) ", v54, &v54[8], &v54[16]) != 3 )
            _Error(a1: "LoadPortals: reading portal %i", i);
          v22 = (char *)hFile;
          v23 = *(double *)v54;
          *(v21 - 1) = v23;
          v24 = *(double *)&v54[8];
          *v21 = v24;
          v21[1] = *(double *)&v54[16];
          v21 += 3;
          hFile = v22 + 1;
        }
        while ( (int)(v22 + 1) < numpoints );
      }
      fscanf(stream: f, format: "\n");
      v25 = *((float *)v20 + 3) - *((float *)v20 + 6);
      v26 = *((float *)v20 + 4) - *((float *)v20 + 7);
      v27 = *((float *)v20 + 9) - *((float *)v20 + 6);
      v28 = *((float *)v20 + 10) - *((float *)v20 + 7);
      v29 = *((float *)v20 + 8) - *((float *)v20 + 5);
      v30 = *((float *)v20 + 2) - *((float *)v20 + 5);
      plane.normal.x = (float)(v25 * v28) - (float)(v26 * v27);
      plane.normal.y = (float)(v26 * v29) - (float)(v28 * v30);
      plane.normal.z = (float)(v27 * v30) - (float)(v25 * v29);
      VectorNormalize(vec: &plane.normal);
      v31 = &leafs[leafnums[0]];
      plane.dist = (float)((float)(*((float *)v20 + 3) * plane.normal.y) + (float)(plane.normal.x * *((float *)v20 + 2)))
                 + (float)(*((float *)v20 + 4) * plane.normal.z);
      m_nAllocationCount = v31->portals.m_Memory.m_nAllocationCount;
      hFile = (void *)v31->portals.m_Size;
      v32 = hFile;
      if ( (int)hFile + 1 > m_nAllocationCount )
      {
        CUtlMemory<int,int>::Grow(
          this: (CUtlMemory<CTCPPacket *,int> *)&leafs[leafnums[0]],
          num: (int)hFile - m_nAllocationCount + 1);
        v32 = hFile;
      }
      ++v31->portals.m_Size;
      m_pMemory = v31->portals.m_Memory.m_pMemory;
      v35 = v31->portals.m_Size - (_DWORD)v32 - 1;
      v31->portals.m_pElements = v31->portals.m_Memory.m_pMemory;
      if ( v35 > 0 )
      {
        _V_memmove(dest: &m_pMemory[(_DWORD)v32 + 1], src: &m_pMemory[(_DWORD)v32], count: 4 * v35);
        v32 = hFile;
      }
      v36 = &v31->portals.m_Memory.m_pMemory[(_DWORD)v32];
      if ( v36 != nullptr )
        *v36 = v16;
      v16->winding = (winding_t *)v20;
      v16->plane.normal.x = vec3_origin.x - plane.normal.x;
      v16->plane.normal.y = vec3_origin.y - plane.normal.y;
      v16->plane.normal.z = vec3_origin.z - plane.normal.z;
      LODWORD(v16->plane.dist) = LODWORD(plane.dist) ^ _mask__NegFloat_;
      v16->leaf = leafnums[1];
      SetPortalSphere(p: v16);
      v37 = leafs[leafnums[1]].portals.m_Memory.m_nAllocationCount;
      v38 = &leafs[leafnums[1]];
      v40 = v16 + 1;
      hFile = (void *)v38->portals.m_Size;
      v39 = hFile;
      if ( (int)hFile + 1 > v37 )
      {
        CUtlMemory<int,int>::Grow(this: (CUtlMemory<CTCPPacket *,int> *)&leafs[leafnums[1]], num: (int)hFile - v37 + 1);
        v39 = hFile;
      }
      ++v38->portals.m_Size;
      v41 = v38->portals.m_Memory.m_pMemory;
      v42 = v38->portals.m_Size - (_DWORD)v39 - 1;
      v38->portals.m_pElements = v38->portals.m_Memory.m_pMemory;
      if ( v42 > 0 )
      {
        _V_memmove(dest: &v41[(_DWORD)v39 + 1], src: &v41[(_DWORD)v39], count: 4 * v42);
        v39 = hFile;
      }
      v43 = &v38->portals.m_Memory.m_pMemory[(_DWORD)v39];
      if ( v43 != nullptr )
        *v43 = v40;
      v44 = *((_DWORD *)v20 + 1);
      if ( v44 > 64 )
        _Error(a1: "NewWinding: %i points, max %d", v44, 64);
      hFile = (void *)(12 * v44 + 8);
      v45 = (unsigned __int8 *)malloc(size: (unsigned int)hFile);
      memset(dst: v45, value: 0, count: (unsigned int)hFile);
      v40->winding = (winding_t *)v45;
      v46 = 0;
      *((_DWORD *)v45 + 1) = *((_DWORD *)v20 + 1);
      if ( *((int *)v20 + 1) > 0 )
      {
        v47 = 0;
        do
        {
          p_x = &v40->winding->points[v47].x;
          v49 = (float *)&v20[12 * (*((_DWORD *)v20 + 1) - v46) - 4];
          *p_x = *v49;
          ++v46;
          ++v47;
          p_x[1] = v49[1];
          p_x[2] = v49[2];
        }
        while ( v46 < *((_DWORD *)v20 + 1) );
      }
      v40->plane = plane;
      v40->leaf = leafnums[0];
      SetPortalSphere(p: v40);
      v16 = v40 + 1;
      if ( ++i >= g_numportals )
        break;
      v17 = i;
      v11 = (void (*)(const char *, ...))_Error;
    }
  }
  fclose(stream: f);
}

//------------------------------------------------------------------------------
// Address: 0x100162F0
// Name: int RunVVis(int,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __usercall RunVVis@<eax>(long double a1@<xmm0>, int argc, char **argv)
{
  int v3; // esi
  char *v4; // eax
  char *v5; // edx
  char v6; // cl
  double v7; // st7
  int v8; // ecx
  _WORD *v9; // eax
  int v10; // eax
  char v11; // cl
  char *v12; // eax
  char v13; // cl
  int i; // esi
  char string[512]; // [esp+Ch] [ebp-1010h] BYREF
  char pOut[512]; // [esp+20Ch] [ebp-E10h] BYREF
  char pPlatformMapPath[1023]; // [esp+40Ch] [ebp-C10h] BYREF
  char v19; // [esp+80Bh] [ebp-811h] BYREF
  char in[1024]; // [esp+80Ch] [ebp-810h] BYREF
  char out[1024]; // [esp+C0Ch] [ebp-410h] BYREF
  double v22; // [esp+100Ch] [ebp-10h]
  double v23; // [esp+1014h] [ebp-8h]
  int savedregs; // [esp+101Ch] [ebp+0h] BYREF

  _Msg(a1: "Valve Software - vvis.exe (%s)\n", "Jul 15 2011");
  verbose = 0;
  V_StripExtension(in: argv[argc - 1], out, outSize: 1024);
  CmdLib_InitFileSystem(pFilename: argv[argc - 1], maxMemoryUsage: 0);
  V_FileBase(in: out, out, maxlen: 1024);
  LoadCmdLineFromFile(&argc, &argv, keyname: out, appname: "vvis");
  v3 = ParseCommandLine(argc, argv);
  v4 = ExpandPath(path: out);
  v5 = (char *)(out - v4);
  do
  {
    v6 = *v4;
    v4[(_DWORD)v5] = *v4;
    ++v4;
  }
  while ( v6 != 0 );
  if ( v3 != argc - 1 )
  {
    PrintCommandLine(argc, argv);
    _Warning(
      a1: "usage  : vvis [options...] bspfile\n"
      "example: vvis -fast c:\\hl2\\hl2\\maps\\test\n"
      "\n"
      "Common options:\n"
      "\n"
      "  -v (or -verbose): Turn on verbose output (also shows more command\n"
      "  -fast           : Only do first quick pass on vis calculations.\n"
      "  -mpi            : Use VMPI to distribute computations.\n"
      "  -low            : Run as an idle-priority process.\n"
      "                    env_fog_controller specifies one.\n"
      "\n"
      "  -vproject <directory> : Override the VPROJECT environment variable.\n"
      "  -game <directory>     : Same as -vproject.\n"
      "\n"
      "Other options:\n"
      "  -novconfig      : Don't bring up graphical UI on vproject errors.\n"
      "  -radius_override: Force a vis radius, regardless of whether an\n"
      "  -mpi_pw <pw>    : Use a password to choose a specific set of VMPI workers.\n"
      "  -threads        : Control the number of threads vbsp uses (defaults to the #\n"
      "                    or processors on your machine).\n"
      "  -nosort         : Don't sort portals (sorting is an optimization).\n"
      "  -tmpin          : Make portals come from \\tmp\\<mapname>.\n"
      "  -tmpout         : Make portals come from \\tmp\\<mapname>.\n"
      "  -trace <start cluster> <end cluster> : Writes a linefile that traces the vis from one cluster to another for deb"
      "ugging map vis.\n"
      "  -FullMinidumps  : Write large minidumps on crash.\n"
      "  -x360\t\t   : Generate Xbox360 version of vsp\n"
      "  -nox360\t\t   : Disable generation Xbox360 version of vsp (default)\n"
      "\n");
    DeleteCmdLine(argc, argv);
    _Plat_ExitProcess(a1: 1);
  }
  v22 = _Plat_FloatTime();
  if ( !g_bUseMPI )
  {
    _snprintf(string, count: 0x200u, format: "%s.log", out);
    CCmdLibFileLoggingListener::Open(this: &g_CmdLibFileLoggingListener, pFilename: string);
  }
  if ( g_bLowPriority )
    SetLowPriority();
  ThreadSetDefault();
  GetPlatformMapPath(pMapPath: out, pPlatformMapPath, dxlevel: 0, maxLength: 1024);
  _Msg(a1: "reading %s\n", pPlatformMapPath);
  LoadBSPFile(filename: pPlatformMapPath);
  if ( numnodes == 0 || numfaces == 0 )
    _Error(a1: "Empty map");
  ParseEntities();
  if ( !g_bUseRadius )
  {
    v7 = DetermineVisRadius();
    *((float *)&v23 + 1) = v7;
    if ( v7 <= 0.0 )
    {
      if ( !g_bUseRadius )
        goto LABEL_19;
    }
    else
    {
      a1 = (float)(*((float *)&v23 + 1) * *((float *)&v23 + 1));
      g_bUseRadius = true;
      g_VisRadius = a1;
    }
  }
  v8 = numleafs;
  if ( numleafs > 0 )
  {
    v9 = &unk_1008B25E;
    do
    {
      *v9 |= 0x400u;
      v9 += 16;
      --v8;
    }
    while ( v8 != 0 );
  }
LABEL_19:
  if ( inbase[0] != 0 )
  {
    sprintf(string: in, format: "%s%s", inbase, argv[v3]);
    V_StripExtension(in, out: in, outSize: 1024);
  }
  else
  {
    v10 = 0;
    do
    {
      v11 = out[v10];
      in[v10++] = v11;
    }
    while ( v11 != 0 );
  }
  v12 = &v19;
  do
    v13 = *++v12;
  while ( v13 != 0 );
  strcpy(v12, ".prt");
  _Msg(a1: "reading %s\n", in);
  LoadPortals(name: in);
  if ( g_TraceClusterStart >= 0 )
  {
    if ( g_TraceClusterStart >= portalclusters || g_TraceClusterStop < 0 || g_TraceClusterStop >= portalclusters )
      _Error(
        a1: "Invalid cluster trace: %d to %d, valid range is 0 to %d\n",
        g_TraceClusterStart,
        g_TraceClusterStop,
        portalclusters - 1);
    if ( g_bUseMPI )
      _Warning(a1: "Can't compile trace in MPI mode\n");
    CalcVisTrace();
    WritePortalTrace(source: out);
  }
  else
  {
    CalcVis();
    CalcPAS();
    BuildClusterTable();
    CalcVisibleFogVolumes();
    for ( i = 0; i < numleafs; ++i )
    {
      CalcDistanceFromLeafToWater(leafNum: i, a2: (int)&savedregs);
      g_LeafMinDistToWater[i] = (int)*(float *)&a1;
    }
    visdatasize = vismap_p - dvisdata;
    _Msg(a1: "visdatasize:%i  compressed from %i\n", vismap_p - dvisdata, 2 * originalvismapsize);
    _Msg(a1: "writing %s\n", pPlatformMapPath);
    WriteBSPFile(a1: (int)_Error, filename: pPlatformMapPath);
  }
  v23 = _Plat_FloatTime();
  GetHourMinuteSecondsString(nInputSeconds: (int)(v23 - v22), pOut, outLen: 512);
  _Msg(a1: "%s elapsed\n", pOut);
  ReleasePakFileLumps();
  DeleteCmdLine(argc, argv);
  CmdLib_Cleanup();
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100166C0
// Name: _main
// Source: json
//------------------------------------------------------------------------------
int __cdecl main(int argc, char **argv)
{
  void (__thiscall ***v2)(_DWORD, int, char **); // eax

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
  InstallAllocationFunctions();
  InstallSpewFunction();
  VVIS_SetupMPI(&argc, &argv);
  if ( !g_bUseMPI || g_bMPIMaster )
  {
    SetupDefaultToolsMinidumpHandler();
    return RunVVis(a1: COERCE_LONG_DOUBLE(1074580685), argc, argv);
  }
  else
  {
    SetupToolsMinidumpHandler(fn: VMPI_ExceptionFilter);
    return RunVVis(a1: COERCE_LONG_DOUBLE(1074580685), argc, argv);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10016770
// Name: public: virtual int CVVisDLL::main(int,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVVisDLL::main(CVVisDLL *this, int argc, char **argv)
{
  return main(argc, argv);
}

//------------------------------------------------------------------------------
// Address: 0x100154D0
// Name: __CreateCVVisDLLILaunchableDLL_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVVisDLL *__cdecl _CreateCVVisDLLILaunchableDLL_interface()
{
  return &_g_CVVisDLL_singleton;
}
