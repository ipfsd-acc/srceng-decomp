// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vrad/vismat.cpp
// Functions: 13
// ============================================================

#include "utils\vrad\vismat.h"

//------------------------------------------------------------------------------
// Address: 0x1001B0A0
// Name: public: void CTransferMaker::Finish(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTransferMaker::Finish(CTransferMaker *this)
{
  int v2; // edi
  int v3; // ebx
  RayTracingSingleResult *m_pResults; // eax

  RayTracingEnvironment::FinishRayStream(this: &g_RtEnv, s: &this->m_RayStream, cullMode: RTE_CULL_NONE);
  v2 = 0;
  if ( this->m_nTests <= 0 )
  {
    this->m_nTests = 0;
  }
  else
  {
    v3 = 0;
    do
    {
      m_pResults = this->m_pResults;
      if ( m_pResults[v3].HitID == -1 || m_pResults[v3].HitDistance >= m_pResults[v3].ray_length )
        MakeTransfer(
          ndxPatch1: this->m_pShooterPatches[v2],
          ndxPatch2: this->m_pRecieverPatches[v2],
          all_transfers: this->m_AllTransfers);
      ++v2;
      ++v3;
    }
    while ( v2 < this->m_nTests );
    this->m_nTests = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001B110
// Name: struct dleaf_t __near * PointInLeaf(int,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
dleaf_t *__cdecl PointInLeaf(int iNode, const Vector *point)
{
  int v2; // eax
  dnode_t *v3; // esi
  float v4; // xmm0_4
  dleaf_t *result; // eax

  v2 = iNode;
  while ( v2 >= 0 )
  {
    v3 = &dnodes[v2];
    v4 = (float)((float)((float)(*(&dplanes.y + 5 * v3->planenum) * point->y)
                       + (float)(*(&dplanes.x + 5 * v3->planenum) * point->x))
               + (float)(*(&dplanes.z + 5 * v3->planenum) * point->z))
       - *((float *)&dplanes + 5 * v3->planenum + 3);
    if ( v4 <= 0.1 )
    {
      if ( v4 >= -0.1 )
      {
        result = PointInLeaf(iNode: v3->children[0], point);
        if ( result->cluster != -1 )
          return result;
      }
      v2 = v3->children[1];
    }
    else
    {
      v2 = v3->children[0];
    }
  }
  return &dleafs[-v2 - 1];
}

//------------------------------------------------------------------------------
// Address: 0x1001B1C0
// Name: int ClusterFromPoint(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClusterFromPoint(const Vector *point)
{
  return PointInLeaf(iNode: 0, point)->cluster;
}

//------------------------------------------------------------------------------
// Address: 0x1001B1E0
// Name: struct transfer_t __near * BuildVisLeafs_Start(void)
// Source: json
//------------------------------------------------------------------------------
transfer_t *__cdecl BuildVisLeafs_Start()
{
  return (transfer_t *)calloc(count: 1u, size: 0x200000u);
}

//------------------------------------------------------------------------------
// Address: 0x1001B1F0
// Name: void BuildVisLeafs_End(struct transfer_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildVisLeafs_End(transfer_t *transfers)
{
  free(pMem: transfers);
}

//------------------------------------------------------------------------------
// Address: 0x1001B200
// Name: public: CTransferMaker::CTransferMaker(struct transfer_t __near *)
// Source: json
//------------------------------------------------------------------------------
CTransferMaker *__thiscall CTransferMaker::CTransferMaker(CTransferMaker *this, transfer_t *all_transfers)
{
  this->m_nTests = 0;
  *(_QWORD *)this->m_RayStream.n_in_stream = 0;
  *(_QWORD *)&this->m_RayStream.n_in_stream[2] = 0;
  *(_QWORD *)&this->m_RayStream.n_in_stream[4] = 0;
  *(_QWORD *)&this->m_RayStream.n_in_stream[6] = 0;
  this->m_AllTransfers = all_transfers;
  this->m_pResults = (RayTracingSingleResult *)calloc(count: 1u, size: 0x600000u);
  this->m_pShooterPatches = (int *)calloc(count: 1u, size: 0x100000u);
  this->m_pRecieverPatches = (int *)calloc(count: 1u, size: 0x100000u);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1001B270
// Name: void TestPatchToPatch(int,int,int,struct transfer_t __near *,class CTransferMaker __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TestPatchToPatch(
        int ndxPatch1,
        int ndxPatch2,
        int head,
        transfer_t *transfers,
        CTransferMaker *transferMaker,
        int iThread)
{
  int v6; // edx
  CPatch *v8; // esi
  CPatch *v9; // eax
  int child1; // ecx
  float v11; // xmm0_4
  float y; // xmm0_4
  float x; // xmm3_4
  float z; // xmm5_4
  float v15; // xmm4_4
  unsigned int v16; // xmm6_4
  unsigned int v17; // xmm2_4
  float v18; // xmm1_4
  int m_nTests; // eax
  float v20; // xmm1_4
  RayTracingSingleResult *m_pResults; // ecx
  Vector end; // [esp+0h] [ebp-24h] BYREF
  Vector p1; // [esp+Ch] [ebp-18h]
  Vector p2; // [esp+18h] [ebp-Ch] BYREF

  v6 = ndxPatch1;
  if ( ndxPatch1 != -1 )
  {
    while ( ndxPatch2 != -1 )
    {
      v8 = &g_Patches.m_Memory.m_pMemory[ndxPatch2];
      v9 = &g_Patches.m_Memory.m_pMemory[v6];
      child1 = v8->child1;
      if ( child1 == -1
        || (v11 = v9->origin.x - v8->origin.x,
            v8->area <= (float)((float)((float)((float)(v9->origin.y - v8->origin.y)
                                              * (float)(v9->origin.y - v8->origin.y))
                                      + (float)(v11 * v11))
                              + (float)((float)(v9->origin.z - v8->origin.z) * (float)(v9->origin.z - v8->origin.z)))
                      * 0.0625) )
      {
        y = v8->origin.y;
        x = v8->origin.x;
        z = v9->normal.z;
        v15 = v8->origin.z;
        if ( (float)((float)((float)(v9->normal.y * y) + (float)(v9->normal.x * x)) + (float)(z * v15)) > v9->planeDist + 0.01 )
        {
          *(float *)&v16 = v9->origin.x + v9->normal.x;
          *(float *)&v17 = v9->origin.y + v9->normal.y;
          v18 = v9->origin.z;
          m_nTests = transferMaker->m_nTests;
          p1.z = v18 + z;
          p2.x = v8->normal.x + x;
          v20 = v8->normal.y + y;
          p2.z = v8->normal.z + v15;
          end.z = p2.z;
          m_pResults = transferMaker->m_pResults;
          p2.z = p1.z;
          p2.y = v20;
          *(_QWORD *)&p1.x = __PAIR64__(v17, v16);
          *(_QWORD *)&end.x = *(_QWORD *)&p2.x;
          *(_QWORD *)&p2.x = __PAIR64__(v17, v16);
          RayTracingEnvironment::AddToRayStream(
            this: &g_RtEnv,
            s: &transferMaker->m_RayStream,
            start: &p2,
            &end,
            rslt_out: &m_pResults[m_nTests],
            cullMode: RTE_CULL_NONE);
          transferMaker->m_pShooterPatches[transferMaker->m_nTests] = ndxPatch1;
          transferMaker->m_pRecieverPatches[transferMaker->m_nTests++] = ndxPatch2;
        }
        return;
      }
      TestPatchToPatch(ndxPatch1: v6, ndxPatch2: child1, head, transfers, transferMaker, iThread);
      ndxPatch2 = v8->child2;
      v6 = ndxPatch1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001B450
// Name: void TestPatchToFace(unsigned int,int,int,struct transfer_t __near *,class CTransferMaker __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TestPatchToFace(
        unsigned int patchnum,
        int facenum,
        int head,
        transfer_t *transfers,
        CTransferMaker *transferMaker,
        int iThread)
{
  int v6; // ecx
  CPatch *m_pMemory; // edx
  CPatch *v8; // ecx
  int ndxNextParent; // eax
  CPatch *v10; // esi
  unsigned int v11; // edx

  v6 = faceParents.m_Memory.m_pMemory[facenum];
  if ( v6 != -1 && patchnum != -1 )
  {
    m_pMemory = g_Patches.m_Memory.m_pMemory;
    v8 = &g_Patches.m_Memory.m_pMemory[v6];
    if ( v8 != nullptr
      && (float)((float)((float)(g_Patches.m_Memory.m_pMemory[patchnum].origin.y * v8->normal.y)
                       + (float)(g_Patches.m_Memory.m_pMemory[patchnum].origin.x * v8->normal.x))
               + (float)(g_Patches.m_Memory.m_pMemory[patchnum].origin.z * v8->normal.z)) > v8->planeDist + 0.01 )
    {
      while ( 1 )
      {
        ndxNextParent = v8->ndxNextParent;
        v10 = nullptr;
        if ( ndxNextParent != -1 )
          v10 = &m_pMemory[ndxNextParent];
        v11 = (int)((unsigned __int64)(1041204193LL * ((char *)v8 - (char *)m_pMemory)) >> 32) >> 6;
        TestPatchToPatch(ndxPatch1: patchnum, ndxPatch2: v11 + (v11 >> 31), head, transfers, transferMaker, iThread);
        v8 = v10;
        if ( v10 == nullptr )
          break;
        m_pMemory = g_Patches.m_Memory.m_pMemory;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001B540
// Name: void BuildVisRow(int,unsigned char __near *,int,struct transfer_t __near *,class CTransferMaker __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildVisRow(
        unsigned int patchnum,
        unsigned __int8 *pvs,
        int head,
        transfer_t *transfers,
        CTransferMaker *transferMaker,
        int iThread)
{
  unsigned int v6; // esi
  clusterlist_t *m_pMemory; // eax
  int v8; // edx
  int i; // ebx
  dleaf_t *v10; // esi
  int v11; // edi
  int v12; // eax
  CPatch *v13; // ecx
  int m_Size; // edi
  int v15; // esi
  int v16; // eax
  CPatch *v17; // edx
  unsigned __int8 v18[65536]; // [esp+8h] [ebp-20010h] BYREF
  unsigned __int8 dst[65536]; // [esp+10008h] [ebp-10010h] BYREF
  CPatch *v20; // [esp+20008h] [ebp-10h]
  int v21; // [esp+2000Ch] [ebp-Ch]
  unsigned int v22; // [esp+20010h] [ebp-8h]
  int v23; // [esp+20014h] [ebp-4h]

  v6 = numfaces;
  v20 = &g_Patches.m_Memory.m_pMemory[patchnum];
  memset(dst, value: 0, count: numfaces);
  memset(dst: v18, value: 0, count: v6);
  v23 = 0;
  if ( dvis->numclusters > 0 )
  {
    m_pMemory = g_ClusterLeaves.m_Memory.m_pMemory;
    v8 = 0;
    v22 = 0;
    v21 = 0;
    do
    {
      if ( ((unsigned __int8)(1 << (v23 & 7)) & pvs[v23 >> 3]) != 0 )
      {
        for ( i = 0; i < *(int *)((char *)&m_pMemory->leafCount + v8); ++i )
        {
          v10 = &dleafs[(*(int **)((char *)&m_pMemory->leafs.m_Memory.m_pMemory + v8))[i]];
          v11 = 0;
          if ( v10->numleaffaces != 0 )
          {
            do
            {
              v12 = dleaffaces[v11 + v10->firstleafface];
              if ( dst[v12] == 0 )
              {
                v13 = v20;
                dst[v12] = 1;
                if ( v13->faceNumber != v12 )
                  TestPatchToFace(patchnum, facenum: v12, head, transfers, transferMaker, iThread);
              }
              ++v11;
            }
            while ( v11 < v10->numleaffaces );
            m_pMemory = g_ClusterLeaves.m_Memory.m_pMemory;
            v8 = v21;
          }
        }
        m_Size = g_ClusterDispFaces.m_Memory.m_pMemory[v22 / 0x14].dispFaces.m_Size;
        v15 = 0;
        if ( m_Size > 0 )
        {
          do
          {
            v16 = g_ClusterDispFaces.m_Memory.m_pMemory[v22 / 0x14].dispFaces.m_Memory.m_pMemory[v15];
            if ( v18[v16] == 0 )
            {
              v17 = v20;
              v18[v16] = 1;
              if ( v17->faceNumber != v16 )
                TestPatchToFace(patchnum, facenum: v16, head, transfers, transferMaker, iThread);
            }
            ++v15;
          }
          while ( v15 < m_Size );
          m_pMemory = g_ClusterLeaves.m_Memory.m_pMemory;
          v8 = v21;
        }
      }
      v22 += 20;
      v8 += 24;
      ++v23;
      v21 = v8;
    }
    while ( v23 < dvis->numclusters );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001B6E0
// Name: void BuildVisLeafs_Cluster(int,struct transfer_t __near *,int,void (*)(int,int,struct CPatch __near *))
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildVisLeafs_Cluster(
        int a1@<ebp>,
        int threadnum,
        transfer_t *transfers,
        int iCluster,
        void (__cdecl *PatchCB)(int, int, CPatch *))
{
  void *v5; // esp
  int v6; // edi
  CPatch *m_pMemory; // edx
  CPatch *v8; // edi
  int ndxNextClusterChild; // eax
  unsigned int v10; // edx
  unsigned int v11; // esi
  unsigned __int8 v12[8192]; // [esp-23D0h] [ebp-23DCh] BYREF
  CTransferMaker v13; // [esp-3D0h] [ebp-3DCh] BYREF
  CPatch *v14; // [esp-4h] [ebp-10h]
  int v15; // [esp+0h] [ebp-Ch]
  void *v16; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v15 = a1;
  v16 = retaddr;
  v5 = alloca(9176);
  DecompressVis(in: &dvisdata[dvis->bitofs[iCluster][0]], decompressed: v12);
  CTransferMaker::CTransferMaker(this: &v13, all_transfers: transfers);
  v6 = clusterChildren.m_Memory.m_pMemory[iCluster];
  if ( v6 != -1 )
  {
    m_pMemory = g_Patches.m_Memory.m_pMemory;
    v8 = &g_Patches.m_Memory.m_pMemory[v6];
    if ( v8 != nullptr )
    {
      while ( 1 )
      {
        ndxNextClusterChild = v8->ndxNextClusterChild;
        v14 = nullptr;
        if ( ndxNextClusterChild != -1 )
          v14 = &m_pMemory[ndxNextClusterChild];
        v10 = (int)((unsigned __int64)(1041204193LL * ((char *)v8 - (char *)m_pMemory)) >> 32) >> 6;
        v11 = v10 + (v10 >> 31);
        BuildVisRow(patchnum: v11, pvs: v12, head: 0, transfers, transferMaker: &v13, iThread: threadnum);
        CTransferMaker::Finish(this: &v13);
        MakeScales(ndxPatch: v11, all_transfers: transfers);
        if ( PatchCB != nullptr )
          PatchCB(a1: threadnum, a2: v11, a3: v8);
        v8 = v14;
        if ( v14 == nullptr )
          break;
        m_pMemory = g_Patches.m_Memory.m_pMemory;
      }
    }
  }
  free(pMem: v13.m_pResults);
  free(pMem: v13.m_pShooterPatches);
  free(pMem: v13.m_pRecieverPatches);
}

//------------------------------------------------------------------------------
// Address: 0x1001B820
// Name: void BuildVisLeafs(int,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildVisLeafs(int threadnum)
{
  unsigned __int8 *v1; // esi
  int i; // eax
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  v1 = calloc(count: 1u, size: 0x200000u);
  for ( i = GetThreadWork(); i != -1; i = GetThreadWork() )
    BuildVisLeafs_Cluster(a1: (int)&savedregs, threadnum, transfers: (transfer_t *)v1, iCluster: i, PatchCB: nullptr);
  free(pMem: v1);
}

//------------------------------------------------------------------------------
// Address: 0x1001B870
// Name: void BuildVisMatrix(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildVisMatrix()
{
  if ( g_bUseMPI )
  {
    RunMPIBuildVisLeafs();
  }
  else
  {
    printf(format: "%-20s ", "BuildVisLeafs:");
    RunThreadsOn(
      workcnt: dvis->numclusters,
      showpacifier: 1,
      fn: (void (__cdecl *)(int, void *))BuildVisLeafs,
      pUserData: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001B8B0
// Name: void AddDispsToClusterTable(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddDispsToClusterTable()
{
  int m_Size; // esi
  int v1; // edi
  int v2; // eax
  CPatch *v3; // ebx
  int ndxNext; // eax
  int clusterNumber; // eax
  CUtlMemory<S3RGBA,int> *v6; // esi
  int m_pMemory; // ecx
  int v8; // eax
  S3RGBA *v9; // edx
  int m_nAllocationCount; // eax
  S3RGBA *v11; // edi
  S3RGBA *v12; // ecx
  int v13; // eax
  CPatch *pNextPatch; // [esp+8h] [ebp-Ch]
  int v15; // [esp+Ch] [ebp-8h]
  int ndxFace; // [esp+10h] [ebp-4h]

  m_Size = g_ClusterLeaves.m_Size;
  CUtlVector<ClusterDispList_t,CUtlMemory<ClusterDispList_t,int>>::RemoveAll(this: (CUtlVector<CUtlVector<CLightFace *,CUtlMemory<CLightFace *,int> >,CUtlMemory<CUtlVector<CLightFace *,CUtlMemory<CLightFace *,int> >,int> > *)&g_ClusterDispFaces);
  CUtlVector<ClusterDispList_t,CUtlMemory<ClusterDispList_t,int>>::InsertMultipleBefore(
    this: (CUtlVector<CUtlVector<CLightFace *,CUtlMemory<CLightFace *,int> >,CUtlMemory<CUtlVector<CLightFace *,CUtlMemory<CLightFace *,int> >,int> > *)&g_ClusterDispFaces,
    elem: g_ClusterDispFaces.m_Size,
    num: m_Size);
  v1 = 0;
  ndxFace = 0;
  if ( (int)numfaces > 0 )
  {
    v15 = 0;
    do
    {
      if ( g_pFaces[v15].dispinfo != -1 )
      {
        v2 = g_FacePatches.m_Memory.m_pMemory[v1];
        if ( v2 != -1 )
        {
          v3 = &g_Patches.m_Memory.m_pMemory[v2];
          if ( v3 != nullptr )
          {
            do
            {
              ndxNext = v3->ndxNext;
              pNextPatch = nullptr;
              if ( ndxNext != -1 )
                pNextPatch = &g_Patches.m_Memory.m_pMemory[ndxNext];
              clusterNumber = v3->clusterNumber;
              if ( clusterNumber != -1 )
              {
                v6 = (CUtlMemory<S3RGBA,int> *)&g_ClusterDispFaces.m_Memory.m_pMemory[clusterNumber];
                m_pMemory = (int)v6[1].m_pMemory;
                v8 = 0;
                if ( m_pMemory <= 0 )
                  goto LABEL_15;
                v9 = v6->m_pMemory;
                while ( *v9 != v1 )
                {
                  ++v8;
                  ++v9;
                  if ( v8 >= m_pMemory )
                    goto LABEL_15;
                }
                if ( v8 == -1 )
                {
LABEL_15:
                  m_nAllocationCount = v6->m_nAllocationCount;
                  v11 = v6[1].m_pMemory;
                  if ( m_pMemory + 1 > m_nAllocationCount )
                    CUtlMemory<int,int>::Grow(this: v6, num: (int)(&v11->g - m_nAllocationCount));
                  ++v6[1].m_pMemory;
                  v12 = v6->m_pMemory;
                  v13 = (char *)v6[1].m_pMemory - (char *)v11 - 1;
                  v6[1].m_nAllocationCount = (int)v6->m_pMemory;
                  if ( v13 > 0 )
                    _V_memmove(dest: &v12[(_DWORD)v11 + 1], src: &v12[(_DWORD)v11], count: 4 * v13);
                  g_ClusterDispFaces.m_Memory.m_pMemory[v3->clusterNumber].dispFaces.m_Memory.m_pMemory[(_DWORD)v11] = ndxFace;
                  v1 = ndxFace;
                }
              }
              v3 = pNextPatch;
            }
            while ( pNextPatch != nullptr );
          }
        }
      }
      ++v15;
      ndxFace = ++v1;
    }
    while ( v1 < (int)numfaces );
  }
}
