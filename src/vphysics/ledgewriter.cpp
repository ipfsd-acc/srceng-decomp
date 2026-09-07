// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vphysics/ledgewriter.cpp
// Functions: 11
// ============================================================

#include "vphysics\ledgewriter.h"

//------------------------------------------------------------------------------
// Address: 0x10001AF0
// Name: public: struct packedtriangle_t const __near * virtualmeshhull_t::GetPackedTriangles(int)const
// Source: json
//------------------------------------------------------------------------------
const packedtriangle_t *__thiscall virtualmeshhull_t::GetPackedTriangles(virtualmeshhull_t *this, int hullIndex)
{
  virtualmeshhull_t *v2; // eax
  const unsigned __int8 *v3; // ecx
  int v4; // edx
  int v5; // esi
  int v6; // edi
  int v7; // ebx
  unsigned __int8 *v8; // eax
  unsigned int v9; // edx
  int v10; // ecx
  int i; // [esp+Ch] [ebp-Ch]
  const unsigned __int8 *pStart; // [esp+10h] [ebp-8h]
  virtualmeshhull_t *v14; // [esp+14h] [ebp-4h]

  v2 = this;
  v3 = (const unsigned __int8 *)this + 4 * this->hullCount + this->hullCount + 4;
  v4 = hullIndex;
  v5 = 0;
  v6 = 0;
  v7 = 0;
  v14 = v2;
  pStart = v3;
  if ( hullIndex >= 2 )
  {
    v8 = &v2[1].pad[1];
    v9 = ((unsigned int)(hullIndex - 2) >> 1) + 1;
    i = 2 * v9;
    do
    {
      v5 += 2 * (*v8 + 2 * *(v8 - 2));
      v10 = v8[5] + 2 * v8[3];
      v8 += 10;
      --v9;
      v6 += 2 * v10;
    }
    while ( v9 != 0 );
    v2 = v14;
    v4 = hullIndex;
    v3 = pStart;
    v7 = i;
  }
  if ( v7 < v4 )
    v3 += 4 * *(&v2[v7 + 1].hullCount + v7) + 2 * v2[v7 + 1].pad[v7 + 1];
  return (const packedtriangle_t *)&v3[v6 + v5];
}

//------------------------------------------------------------------------------
// Address: 0x10001B90
// Name: MaxLedgeVertIndex
// Source: json
//------------------------------------------------------------------------------
int __fastcall MaxLedgeVertIndex(int a1, const IVP_Compact_Ledge *pLedge)
{
  int n_triangles; // ecx
  int result; // eax
  _DWORD *v4; // edx
  int i; // esi

  n_triangles = pLedge->n_triangles;
  result = -1;
  if ( n_triangles > 0 )
  {
    v4 = (_DWORD *)&pLedge[1] + 2;
    for ( i = n_triangles; i != 0; --i )
    {
      if ( result <= (unsigned __int16)*(v4 - 1) )
        result = (unsigned __int16)*(v4 - 1);
      if ( result <= (unsigned __int16)*v4 )
        result = (unsigned __int16)*v4;
      if ( result <= (unsigned __int16)v4[1] )
        result = (unsigned __int16)v4[1];
      v4 += 4;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001BE0
// Name: public: static void CVPhysicsVirtualMeshWriter::InitTwoSidedTriangleLege(struct triangleledge_t __near *,class IVP_Compact_Poly_Point const __near *,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CVPhysicsVirtualMeshWriter::InitTwoSidedTriangleLege(
        triangleledge_t *pOut,
        const IVP_Compact_Poly_Point *pPoints,
        __int16 v0,
        __int16 v1,
        __int16 v2,
        char materialIndex)
{
  int v6; // ecx

  pOut->ledge.c_point_offset = (char *)pPoints - (char *)pOut;
  *((_DWORD *)&pOut->ledge + 2) = *((_DWORD *)&pOut->ledge + 2) & 0xF0 | 0x304;
  v6 = (materialIndex & 0x7F) << 24;
  pOut->ledge.n_triangles = 2;
  *(_DWORD *)pOut->faces = v6 | *(_DWORD *)pOut->faces & 0x80FFF000;
  *(_WORD *)pOut->faces[0].c_three_edges = v0;
  *(_WORD *)&pOut->faces[0].c_three_edges[1] = v1;
  *(_WORD *)&pOut->faces[0].c_three_edges[2] = v2;
  pOut->faces[0].c_three_edges[0] = (IVP_Compact_Edge)(*(_DWORD *)pOut->faces[0].c_three_edges & 0x8000FFFF | 0x60000);
  pOut->faces[0].c_three_edges[1] = (IVP_Compact_Edge)(*(_DWORD *)&pOut->faces[0].c_three_edges[1] & 0x8000FFFF | 0x40000);
  pOut->faces[0].c_three_edges[2] = (IVP_Compact_Edge)(*(_DWORD *)&pOut->faces[0].c_three_edges[2] & 0x8000FFFF | 0x20000);
  *(_DWORD *)&pOut->faces[1] = v6 | *(_DWORD *)&pOut->faces[1] & 0x80FFF001 | 1;
  *(_WORD *)pOut->faces[1].c_three_edges = v0;
  *(_WORD *)&pOut->faces[1].c_three_edges[1] = v2;
  *(_WORD *)&pOut->faces[1].c_three_edges[2] = v1;
  pOut->faces[1].c_three_edges[0] = (IVP_Compact_Edge)(*(_DWORD *)pOut->faces[1].c_three_edges & 0x8000FFFF | 0x7FFE0000);
  pOut->faces[1].c_three_edges[1] = (IVP_Compact_Edge)(*(_DWORD *)&pOut->faces[1].c_three_edges[1] & 0x8000FFFF
                                                     | 0x7FFC0000);
  pOut->faces[1].c_three_edges[2] = (IVP_Compact_Edge)(*(_DWORD *)&pOut->faces[1].c_three_edges[2] & 0x8000FFFF
                                                     | 0x7FFA0000);
  *(_DWORD *)pOut->faces = *(_DWORD *)pOut->faces & 0xFF000FFF | 0x1000;
  *(_DWORD *)&pOut->faces[1] &= 0xFF000FFF;
}

//------------------------------------------------------------------------------
// Address: 0x10001CE0
// Name: public: static void CVPhysicsVirtualMeshWriter::DestroyPackedHull(struct virtualmeshhull_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CVPhysicsVirtualMeshWriter::DestroyPackedHull(virtualmeshhull_t *pHull)
{
  free(data: pHull);
}

//------------------------------------------------------------------------------
// Address: 0x10001CF0
// Name: public: static unsigned int CVPhysicsVirtualMeshWriter::UnpackLedgeListFromHull(unsigned char __near *,struct virtualmeshhull_t __near *,class IVP_Compact_Poly_Point __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl CVPhysicsVirtualMeshWriter::UnpackLedgeListFromHull(
        unsigned __int8 *pOut,
        virtualmeshhull_t *pHull,
        IVP_Compact_Poly_Point *pPoints)
{
  virtualmeshhull_t *v3; // ecx
  unsigned int result; // eax
  virtualmeshhull_t *v5; // ebx
  IVP_Compact_Ledge *v6; // esi
  const packedtriangle_t *PackedTriangles; // edx
  unsigned int v8; // eax
  int v9; // edi
  int v10; // ecx
  int hullCount; // ecx
  const packedtriangle_t *v12; // edi
  int v13; // eax
  IVP_Compact_Ledge *v14; // edx
  const packedtriangle_t *p_e1; // esi
  int e0; // ecx
  int e1; // eax
  int v18; // ecx
  $D94D6EC998D8AC7437E59ECF9B271F0E *v19; // eax
  int v20; // esi
  __int16 v21; // cx
  int v22; // ecx
  bool v23; // sf
  bool v24; // of
  int *v25; // esi
  int v26; // ecx
  __int16 v27; // cx
  int v28; // edi
  int v29; // ecx
  int v30; // edx
  int v31; // ecx
  int v32; // ecx
  int v33; // edx
  _DWORD v34[255]; // [esp+0h] [ebp-434h] BYREF
  _DWORD v35[3]; // [esp+3FCh] [ebp-38h]
  IVP_Compact_Ledge *pHullLedge; // [esp+408h] [ebp-2Ch]
  int v37; // [esp+40Ch] [ebp-28h]
  int v38; // [esp+410h] [ebp-24h]
  const packedtriangle_t *v39; // [esp+414h] [ebp-20h]
  int v40; // [esp+418h] [ebp-1Ch]
  int *p_c_point_offset; // [esp+41Ch] [ebp-18h]
  int v42; // [esp+420h] [ebp-14h]
  int v43; // [esp+424h] [ebp-10h]
  int i; // [esp+428h] [ebp-Ch]
  unsigned int memOffset; // [esp+42Ch] [ebp-8h]
  const packedtriangle_t *v46; // [esp+430h] [ebp-4h]

  v3 = pHull;
  result = 0;
  memOffset = 0;
  i = 0;
  if ( pHull->hullCount != 0 )
  {
    v5 = pHull + 1;
    do
    {
      v6 = (IVP_Compact_Ledge *)&pOut[result];
      pHullLedge = (IVP_Compact_Ledge *)&pOut[result];
      PackedTriangles = virtualmeshhull_t::GetPackedTriangles(this: v3, hullIndex: i);
      v6->c_point_offset = (char *)pPoints - (char *)v6;
      v8 = *((_DWORD *)v6 + 2) & 0xFFFFFFF3 | 4;
      *((_DWORD *)v6 + 2) = v8;
      v9 = (unsigned __int8)v8 | ((16 * (v5->hullCount + 1)) >> 4 << 8);
      *((_DWORD *)v6 + 2) = v9;
      v6->n_triangles = v5->hullCount;
      v38 = -(int)v6;
      *((_DWORD *)v6 + 2) = v9 & 0xFFFFFFFC | 1;
      v6->ledgetree_node_offset = -(int)v6;
      v10 = v5->pad[1];
      v46 = PackedTriangles;
      if ( v10 != 0 )
        memset(v34, 0xFFu, 4 * v10);
      hullCount = v5->hullCount;
      v12 = &PackedTriangles[hullCount];
      v37 = v5[1].hullCount;
      LOWORD(v13) = 0;
      v39 = v12;
      v14 = v6 + 1;
      v42 = 0;
      if ( hullCount != 0 )
      {
        p_e1 = (const packedtriangle_t *)&v46->e1;
        v46 = (const packedtriangle_t *)((char *)v46 + 1);
        while ( 1 )
        {
          v14->c_point_offset ^= ((unsigned __int16)v13 ^ (unsigned __int16)v14->c_point_offset) & 0xFFF;
          v14->c_point_offset &= 0x80FFFFFF;
          v14->c_point_offset = v14->c_point_offset & 0x7FFFFFFF | ((v42 < v5->pad[0]) << 31);
          v14->c_point_offset ^= (v14->c_point_offset ^ (p_e1->e2 << 12)) & 0xFFF000;
          e0 = p_e1->e0;
          v35[0] = p_e1[-1].opposite;
          e1 = p_e1->e1;
          v35[1] = e0;
          v18 = 0;
          v35[2] = e1;
          v40 = 0;
          v19 = &v14->___u1;
          while ( 1 )
          {
            v20 = v35[v18];
            p_c_point_offset = &v34[v20];
            v43 = *p_c_point_offset;
            if ( v43 >= 0 )
            {
              v27 = v37 + *(&v12->e1 + 2 * v20);
              v28 = v43;
              LOWORD(v19->ledgetree_node_offset) = v27;
              v29 = v5->pad[2];
              p_c_point_offset = &v14->c_point_offset;
              v30 = v19->ledgetree_node_offset & 0x7FFFFFFF | ((v20 < v29) << 31);
              v31 = ((int)&v19[-4] + v38) >> 2;
              v19->ledgetree_node_offset = v30;
              v19->ledgetree_node_offset ^= (v30 ^ ((v28 - v31) << 16)) & 0x7FFF0000;
              v14 = (IVP_Compact_Ledge *)p_c_point_offset;
              v19[(2 * v19->ledgetree_node_offset) >> 17].ledgetree_node_offset ^= (v19[(2 * v19->ledgetree_node_offset) >> 17].ledgetree_node_offset
                                                                                  ^ ((v31 - v28) << 16))
                                                                                 & 0x7FFF0000;
            }
            else
            {
              v21 = v37 + *(&v12->e0 + 2 * v20);
              v43 = (int)v14;
              LOWORD(v19->ledgetree_node_offset) = v21;
              v22 = v5->pad[2];
              v24 = __OFSUB__(v20, v22);
              v23 = v20 - v22 < 0;
              v25 = p_c_point_offset;
              v26 = ((int)&v19[-4] + v38) >> 2;
              v19->ledgetree_node_offset = v19->ledgetree_node_offset & 0x7FFFFFFF | ((v23 ^ v24) << 31);
              v14 = (IVP_Compact_Ledge *)v43;
              *v25 = v26;
            }
            v18 = v40 + 1;
            ++v19;
            v40 = v18;
            if ( v18 >= 3 )
              break;
            v12 = v39;
          }
          v32 = v5->hullCount;
          v13 = v42 + 1;
          p_e1 = v46 + 1;
          ++v14;
          v42 = v13;
          ++v46;
          if ( v13 >= v32 )
            break;
          v12 = v39;
        }
        v6 = pHullLedge;
      }
      v3 = pHull;
      memOffset += 16 * (*((_DWORD *)v6 + 2) >> 8);
      v33 = pHull->hullCount;
      v5 = (virtualmeshhull_t *)((char *)v5 + 5);
      ++i;
      result = memOffset;
    }
    while ( i < v33 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001F30
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
// Address: 0x10002020
// Name: BuildVertMap
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildVertMap(vertmap_t *out@<esi>, int a2@<ecx>, int a3, int a4, const IVP_Compact_Ledge *a5)
{
  int v5; // eax
  int m_Size; // ecx
  int v7; // eax
  int i; // eax
  char *v9; // edx
  $D94D6EC998D8AC7437E59ECF9B271F0E *v10; // edi
  int ledgetree_node_offset; // eax
  int *v12; // edi
  float v13; // xmm4_4
  int v14; // eax
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm3_4
  int v18; // eax
  int v19; // ecx
  float v20; // xmm1_4
  float v21; // xmm6_4
  float *v22; // edx
  float v23; // xmm0_4
  int minRef; // eax
  int maxRef; // eax
  bool v26; // zf
  char *v27; // [esp-Ch] [ebp-20h]
  $D94D6EC998D8AC7437E59ECF9B271F0E *v28; // [esp-8h] [ebp-1Ch]
  int v29; // [esp-4h] [ebp-18h]
  int pVertList; // [esp+0h] [ebp-14h]
  $D94D6EC998D8AC7437E59ECF9B271F0E *v31; // [esp+4h] [ebp-10h]

  v5 = MaxLedgeVertIndex(a1: a2, pLedge: a5);
  m_Size = out->map.m_Size;
  v7 = v5 + 1;
  if ( m_Size < v7 )
    CUtlVector<IPhysicsObject *,CUtlMemory<IPhysicsObject *,int>>::InsertMultipleBefore(
      this: &out->map,
      elem: m_Size,
      num: v7 - m_Size);
  for ( i = 0; i < out->map.m_Size; ++i )
    out->map.m_Memory.m_pMemory[i] = -1;
  out->maxRef = 0;
  out->minRef = a4;
  v29 = 0;
  v9 = (char *)a5 + a5->c_point_offset;
  v27 = v9;
  if ( a5->n_triangles > 0 )
  {
    v10 = &a5[1].___u1;
    v28 = &a5[1].___u1;
    do
    {
      v31 = v10;
      pVertList = 3;
      do
      {
        ledgetree_node_offset = (unsigned __int16)v10->ledgetree_node_offset;
        v12 = &out->map.m_Memory.m_pMemory[ledgetree_node_offset];
        if ( *v12 < 0 )
        {
          v13 = 1.0e24;
          v14 = 2 * ledgetree_node_offset;
          v15 = *(float *)&v9[8 * v14];
          v16 = *(float *)&v9[8 * v14 + 8];
          LODWORD(v17) = COERCE_UNSIGNED_INT(g_PhysicsUnits.unitScaleMetersInv * *(float *)&v9[8 * v14 + 4])
                       ^ _mask__NegFloat_;
          v18 = 0;
          v19 = -1;
          v20 = v16 * g_PhysicsUnits.unitScaleMetersInv;
          v21 = v15 * g_PhysicsUnits.unitScaleMetersInv;
          if ( a4 > 0 )
          {
            v22 = (float *)(a3 + 8);
            do
            {
              v23 = fsqrt(
                      (float)((float)((float)(v20 - *(v22 - 1)) * (float)(v20 - *(v22 - 1)))
                            + (float)((float)(v17 - *v22) * (float)(v17 - *v22)))
                    + (float)((float)(v21 - *(v22 - 2)) * (float)(v21 - *(v22 - 2))));
              if ( v13 > v23 )
              {
                v13 = v23;
                v19 = v18;
              }
              ++v18;
              v22 += 3;
            }
            while ( v18 < a4 );
            v9 = v27;
          }
          *v12 = v19;
          minRef = out->minRef;
          if ( minRef >= v19 )
            minRef = v19;
          out->minRef = minRef;
          maxRef = out->maxRef;
          if ( maxRef <= v19 )
            maxRef = v19;
          out->maxRef = maxRef;
        }
        v10 = v31 + 1;
        v26 = pVertList-- == 1;
        ++v31;
      }
      while ( !v26 );
      v10 = v28 + 4;
      ++v29;
      v28 += 4;
    }
    while ( v29 < a5->n_triangles );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100021B0
// Name: void PackLedgeIntoBuffer(struct packedhull_t __near *,class CUtlBuffer __near &,class IVP_Compact_Ledge const __near *,struct virtualmeshlist_t const __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __cdecl PackLedgeIntoBuffer(
        packedhull_t *pHull,
        CUtlBuffer *buf,
        const IVP_Compact_Ledge *pLedge,
        const virtualmeshlist_t *list)
{
  const IVP_Compact_Ledge *v4; // ebx
  int vertexCount; // ecx
  Vector *pVerts; // edx
  int v7; // esi
  int m_Size; // eax
  int v9; // esi
  int v10; // eax
  int *v11; // eax
  int n_triangles; // ecx
  int v13; // ecx
  int v14; // esi
  int v15; // eax
  int *v16; // eax
  int v17; // edx
  int *m_pMemory; // ecx
  $D94D6EC998D8AC7437E59ECF9B271F0E *v19; // edi
  int v20; // eax
  int v21; // esi
  int v22; // eax
  int *v23; // eax
  int v24; // edx
  int *v25; // edx
  $D94D6EC998D8AC7437E59ECF9B271F0E *v26; // ecx
  int v27; // esi
  int v28; // edi
  int v29; // ebx
  int v30; // eax
  int v31; // eax
  int *v32; // eax
  bool v33; // zf
  int v34; // ecx
  int v35; // esi
  int *v36; // edi
  int v37; // eax
  int *v38; // esi
  int v39; // edi
  packedhull_t *v40; // ecx
  int *v41; // eax
  unsigned __int8 baseVert; // dl
  int v43; // ecx
  vertmap_t vertMap; // [esp+8h] [ebp-7Ch] BYREF
  CUtlVector<int,CUtlMemory<int,int> > triangleMap; // [esp+24h] [ebp-60h] BYREF
  CUtlVector<int,CUtlMemory<int,int> > edgeMap; // [esp+38h] [ebp-4Ch] BYREF
  CUtlVector<int,CUtlMemory<int,int> > edgeList; // [esp+4Ch] [ebp-38h] BYREF
  CUtlVector<int,CUtlMemory<int,int> > triangleList; // [esp+60h] [ebp-24h] BYREF
  int i; // [esp+74h] [ebp-10h]
  int v50; // [esp+78h] [ebp-Ch]
  int v51; // [esp+7Ch] [ebp-8h]
  int edge; // [esp+80h] [ebp-4h] OVERLAPPED BYREF

  v4 = pLedge;
  if ( pLedge != nullptr )
  {
    vertexCount = list->vertexCount;
    pVerts = list->pVerts;
    memset(&triangleList, 0, sizeof(triangleList));
    memset(&triangleMap, 0, sizeof(triangleMap));
    memset(&edgeList, 0, sizeof(edgeList));
    memset(&edgeMap, 0, sizeof(edgeMap));
    memset(&vertMap, 0, 20);
    BuildVertMap(out: &vertMap, a2: vertexCount, a3: (int)pVerts, a4: vertexCount, a5: pLedge);
    pHull->baseVert = vertMap.minRef;
    if ( pLedge->n_triangles > 0 )
      CUtlVector<IPhysicsObject *,CUtlMemory<IPhysicsObject *,int>>::InsertMultipleBefore(
        this: &triangleMap,
        elem: 0,
        num: pLedge->n_triangles);
    if ( triangleMap.m_Size > 0 )
      memset(triangleMap.m_Memory.m_pMemory, 0xFFu, 4 * triangleMap.m_Size);
    v7 = 4 * pLedge->n_triangles;
    if ( v7 > 0 )
    {
      CUtlMemory<CPredictedPhysicsObject *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&edgeMap,
        num: 4 * pLedge->n_triangles);
      edgeMap.m_Size += v7;
      if ( edgeMap.m_Size - v7 > 0 )
        _V_memmove(
          dest: &edgeMap.m_Memory.m_pMemory[v7],
          src: edgeMap.m_Memory.m_pMemory,
          count: 4 * (edgeMap.m_Size - v7));
    }
    if ( edgeMap.m_Size > 0 )
      memset(edgeMap.m_Memory.m_pMemory, 0xFFu, 4 * edgeMap.m_Size);
    edge = 0;
    if ( pLedge->n_triangles > 0 )
    {
      v51 = (int)&pLedge[1];
      do
      {
        if ( *(int *)v51 < 0 )
        {
          m_Size = triangleList.m_Size;
          v9 = triangleList.m_Size;
          if ( triangleList.m_Size + 1 > triangleList.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<CPredictedPhysicsObject *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&triangleList,
              num: triangleList.m_Size - triangleList.m_Memory.m_nAllocationCount + 1);
            m_Size = triangleList.m_Size;
          }
          triangleList.m_Size = m_Size + 1;
          v10 = m_Size - v9;
          triangleList.m_pElements = triangleList.m_Memory.m_pMemory;
          if ( v10 > 0 )
            _V_memmove(
              dest: &triangleList.m_Memory.m_pMemory[v9 + 1],
              src: &triangleList.m_Memory.m_pMemory[v9],
              count: 4 * v10);
          v11 = &triangleList.m_Memory.m_pMemory[v9];
          if ( v11 != nullptr )
            *v11 = edge;
          triangleMap.m_Memory.m_pMemory[edge] = v9;
        }
        n_triangles = pLedge->n_triangles;
        v51 += 16;
        ++edge;
      }
      while ( edge < n_triangles );
    }
    v13 = triangleList.m_Size;
    pHull->vtriCount = triangleList.m_Size;
    edge = 0;
    if ( pLedge->n_triangles > 0 )
    {
      v51 = (int)&pLedge[1];
      do
      {
        if ( *(int *)v51 >= 0 )
        {
          v14 = v13;
          if ( v13 + 1 > triangleList.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<CPredictedPhysicsObject *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&triangleList,
              num: v13 - triangleList.m_Memory.m_nAllocationCount + 1);
            v13 = triangleList.m_Size;
          }
          ++v13;
          triangleList.m_pElements = triangleList.m_Memory.m_pMemory;
          v15 = v13 - v14 - 1;
          triangleList.m_Size = v13;
          if ( v15 > 0 )
          {
            _V_memmove(
              dest: &triangleList.m_Memory.m_pMemory[v14 + 1],
              src: &triangleList.m_Memory.m_pMemory[v14],
              count: 4 * v15);
            v13 = triangleList.m_Size;
          }
          v16 = &triangleList.m_Memory.m_pMemory[v14];
          if ( v16 != nullptr )
            *v16 = edge;
          triangleMap.m_Memory.m_pMemory[edge] = v14;
        }
        v17 = pLedge->n_triangles;
        v51 += 16;
        ++edge;
      }
      while ( edge < v17 );
    }
    v51 = 0;
    if ( pLedge->n_triangles > 0 )
    {
      m_pMemory = edgeMap.m_Memory.m_pMemory;
      edge = -16 - (_DWORD)pLedge;
      do
      {
        v19 = &pLedge[triangleList.m_Memory.m_pMemory[v51] + 1].___u1;
        for ( i = 3; i != 0; --i )
        {
          if ( v19->ledgetree_node_offset < 0
            && m_pMemory[((int)v19 + 4 * ((2 * v19->ledgetree_node_offset) >> 17) - 16 - (int)pLedge) >> 2] < 0 )
          {
            v50 = ((int)v19 + edge) >> 2;
            v20 = edgeList.m_Size;
            v21 = edgeList.m_Size;
            if ( edgeList.m_Size + 1 > edgeList.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<CPredictedPhysicsObject *,int>::Grow(
                this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&edgeList,
                num: edgeList.m_Size - edgeList.m_Memory.m_nAllocationCount + 1);
              v20 = edgeList.m_Size;
            }
            edgeList.m_Size = v20 + 1;
            v22 = v20 - v21;
            edgeList.m_pElements = edgeList.m_Memory.m_pMemory;
            if ( v22 > 0 )
              _V_memmove(
                dest: &edgeList.m_Memory.m_pMemory[v21 + 1],
                src: &edgeList.m_Memory.m_pMemory[v21],
                count: 4 * v22);
            v23 = &edgeList.m_Memory.m_pMemory[v21];
            if ( v23 != nullptr )
              *v23 = v50;
            m_pMemory = edgeMap.m_Memory.m_pMemory;
            edgeMap.m_Memory.m_pMemory[v50] = v21;
          }
          ++v19;
        }
        v24 = pLedge->n_triangles;
        ++v51;
      }
      while ( v51 < v24 );
    }
    pHull->vedgeCount = edgeList.m_Size;
    v51 = 0;
    if ( pLedge->n_triangles > 0 )
    {
      edge = -16 - (_DWORD)pLedge;
      do
      {
        v25 = edgeMap.m_Memory.m_pMemory;
        v26 = &v4[triangleList.m_Memory.m_pMemory[v51] + 1].___u1;
        i = (int)v26;
        v50 = 3;
        do
        {
          v27 = ((int)v26 + edge) >> 2;
          v28 = ((int)v26 + 4 * ((2 * v26->ledgetree_node_offset) >> 17) - 16 - (int)v4) >> 2;
          if ( v26->ledgetree_node_offset >= 0 && v25[v28] < 0 )
          {
            v29 = edgeList.m_Size;
            v30 = edgeList.m_Size;
            if ( edgeList.m_Size + 1 > edgeList.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<CPredictedPhysicsObject *,int>::Grow(
                this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&edgeList,
                num: edgeList.m_Size - edgeList.m_Memory.m_nAllocationCount + 1);
              v30 = edgeList.m_Size;
            }
            edgeList.m_Size = v30 + 1;
            v31 = v30 - v29;
            edgeList.m_pElements = edgeList.m_Memory.m_pMemory;
            if ( v31 > 0 )
              _V_memmove(
                dest: &edgeList.m_Memory.m_pMemory[v29 + 1],
                src: &edgeList.m_Memory.m_pMemory[v29],
                count: 4 * v31);
            v32 = &edgeList.m_Memory.m_pMemory[v29];
            if ( v32 != nullptr )
              *v32 = v27;
            v25 = edgeMap.m_Memory.m_pMemory;
            edgeMap.m_Memory.m_pMemory[v27] = v29;
            v26 = ($D94D6EC998D8AC7437E59ECF9B271F0E *)i;
            v4 = pLedge;
          }
          if ( v25[v27] < 0 )
            v25[v27] = v25[v28];
          ++v26;
          v33 = v50-- == 1;
          i = (int)v26;
        }
        while ( !v33 );
        v34 = v4->n_triangles;
        ++v51;
      }
      while ( v51 < v34 );
    }
    v35 = 0;
    if ( pHull->triangleCount != 0 )
    {
      v36 = edgeMap.m_Memory.m_pMemory;
      do
      {
        v37 = 16 * (triangleList.m_Memory.m_pMemory[v35] + 1);
        HIBYTE(edge) = triangleMap.m_Memory.m_pMemory[((unsigned int)v4[v37 / 0x10u].c_point_offset >> 12) & 0xFFF];
        LOBYTE(edge) = v36[(v37 - 12) >> 2];
        BYTE1(edge) = v36[(v37 - 8) >> 2];
        BYTE2(edge) = v36[(v37 - 4) >> 2];
        CUtlBuffer::Put(this: buf, pMem: &edge, size: 4);
        ++v35;
      }
      while ( v35 < pHull->triangleCount );
    }
    v38 = vertMap.map.m_Memory.m_pMemory;
    v39 = 0;
    if ( pHull->edgeCount != 0 )
    {
      v40 = pHull;
      do
      {
        v41 = &pLedge[1].c_point_offset + edgeList.m_Memory.m_pMemory[v39];
        baseVert = v40->baseVert;
        v43 = *(int *)((char *)v41
                     + *(int *)((char *)IVP_Compact_Edge::next_table
                              + (((_BYTE)pLedge + 4 * LOBYTE(edgeList.m_Memory.m_pMemory[v39]) + 16) & 0xC)));
        LOBYTE(v41) = v38[(unsigned __int16)*v41];
        BYTE1(edge) = v38[(unsigned __int16)v43] - baseVert;
        LOBYTE(edge) = (_BYTE)v41 - baseVert;
        CUtlBuffer::Put(this: buf, pMem: &edge, size: 2);
        v40 = pHull;
        ++v39;
      }
      while ( v39 < pHull->edgeCount );
    }
    if ( vertMap.map.m_Memory.m_nGrowSize >= 0 && v38 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v38);
    if ( edgeMap.m_Memory.m_nGrowSize >= 0 && edgeMap.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: edgeMap.m_Memory.m_pMemory);
    if ( edgeList.m_Memory.m_nGrowSize >= 0 && edgeList.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: edgeList.m_Memory.m_pMemory);
    if ( triangleMap.m_Memory.m_nGrowSize >= 0 && triangleMap.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: triangleMap.m_Memory.m_pMemory);
    if ( triangleList.m_Memory.m_nGrowSize >= 0 && triangleList.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: triangleList.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002740
// Name: public: static bool CVPhysicsVirtualMeshWriter::LedgeCanBePacked(class IVP_Compact_Ledge const __near *,struct virtualmeshlist_t const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CVPhysicsVirtualMeshWriter::LedgeCanBePacked(
        const IVP_Compact_Ledge *pLedge,
        const virtualmeshlist_t *list)
{
  vertmap_t vertMap; // [esp+0h] [ebp-1Ch] BYREF

  if ( 3 * pLedge->n_triangles > 512 )
    return 0;
  memset(&vertMap, 0, 20);
  BuildVertMap(out: &vertMap, a2: list->vertexCount, a3: (int)list->pVerts, a4: list->vertexCount, a5: pLedge);
  if ( vertMap.maxRef - vertMap.minRef > 255 )
  {
    CUtlVector<IPhysicsObject *,CUtlMemory<IPhysicsObject *,int>>::~CUtlVector<IPhysicsObject *,CUtlMemory<IPhysicsObject *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&vertMap);
    return 0;
  }
  CUtlVector<IPhysicsObject *,CUtlMemory<IPhysicsObject *,int>>::~CUtlVector<IPhysicsObject *,CUtlMemory<IPhysicsObject *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&vertMap);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100027B0
// Name: public: static struct virtualmeshhull_t __near * CVPhysicsVirtualMeshWriter::CreatePackedHullFromLedges(struct virtualmeshlist_t const __near &,class IVP_Compact_Ledge const __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
virtualmeshhull_t *__cdecl CVPhysicsVirtualMeshWriter::CreatePackedHullFromLedges(
        const virtualmeshlist_t *list,
        const IVP_Compact_Ledge **pLedges,
        int ledgeCount)
{
  int v4; // eax
  int v5; // esi
  int v6; // ecx
  int n_triangles; // eax
  int v8; // edx
  int v9; // esi
  int v10; // eax
  const IVP_Compact_Ledge **v11; // esi
  const IVP_Compact_Ledge *v12; // edx
  int i; // esi
  packedhull_t *pHulls[16]; // [esp+Ch] [ebp-88h] BYREF
  CUtlBuffer buf; // [esp+4Ch] [ebp-48h] BYREF
  int v17; // [esp+7Ch] [ebp-18h]
  int edgeCount; // [esp+80h] [ebp-14h]
  int v19; // [esp+84h] [ebp-10h]
  packedhull_t hull; // [esp+88h] [ebp-Ch] BYREF
  virtualmeshhull_t tmp; // [esp+90h] [ebp-4h] BYREF
  unsigned __int8 *pBuf; // [esp+A4h] [ebp+10h]

  v4 = 0;
  v5 = 0;
  v6 = 0;
  *(_DWORD *)&hull.triangleCount = 0;
  v17 = 0;
  v19 = 0;
  tmp = 0;
  edgeCount = 0;
  if ( ledgeCount >= 2 )
  {
    do
    {
      n_triangles = pLedges[v6]->n_triangles;
      v19 += n_triangles;
      *(_DWORD *)&hull.triangleCount += 3 * n_triangles / 2;
      v8 = pLedges[v6 + 1]->n_triangles;
      v5 += v8;
      v17 += 3 * v8 / 2;
      v6 += 2;
    }
    while ( v6 < ledgeCount - 1 );
    v4 = edgeCount;
  }
  if ( v6 < ledgeCount )
  {
    tmp = (virtualmeshhull_t)pLedges[v6]->n_triangles;
    v4 = 3 * *(_DWORD *)&tmp / 2;
  }
  v9 = 5 * ledgeCount + 2 * (v4 + *(_DWORD *)&hull.triangleCount + v17 + 2 * (*(_DWORD *)&tmp + v19 + v5) + 2);
  pBuf = (unsigned __int8 *)p_malloc(size: v9);
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
  CUtlBuffer::SetExternalBuffer(this: &buf, pMemory: pBuf, nSize: v9, nInitialPut: 0, nFlags: 0);
  _V_memset(dest: &tmp, fill: 0, count: 4);
  tmp.hullCount = ledgeCount;
  CUtlBuffer::Put(this: &buf, pMem: &tmp, size: 4);
  if ( ledgeCount > 0 )
  {
    v10 = (char *)pHulls - (char *)pLedges;
    v11 = pLedges;
    edgeCount = (char *)pHulls - (char *)pLedges;
    tmp = (virtualmeshhull_t)ledgeCount;
    while ( 1 )
    {
      v12 = *v11;
      *(const IVP_Compact_Ledge **)((char *)v11 + v10) = (const IVP_Compact_Ledge *)&buf.m_Memory.m_pMemory[buf.m_Put - buf.m_nOffset];
      hull.triangleCount = v12->n_triangles;
      hull.edgeCount = 3 * hull.triangleCount / 2;
      CUtlBuffer::Put(this: &buf, pMem: &hull, size: 5);
      ++v11;
      if ( --*(_DWORD *)&tmp == 0 )
        break;
      v10 = edgeCount;
    }
  }
  for ( i = 0; i < ledgeCount; ++i )
    PackLedgeIntoBuffer(
      pHull: pHulls[i],
      &buf,
      pLedge: *(const IVP_Compact_Ledge **)((char *)&pHulls[i] + (char *)pLedges - (char *)pHulls),
      list);
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  return (virtualmeshhull_t *)pBuf;
}

//------------------------------------------------------------------------------
// Address: 0x10002950
// Name: public: static class IVP_Compact_Ledge __near * CVPhysicsVirtualMeshWriter::ConvertPolyhedronToLedge(class CPolyhedron const __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Compact_Ledge *__cdecl CVPhysicsVirtualMeshWriter::ConvertPolyhedronToLedge(const CPolyhedron *pPoly)
{
  int v2; // eax
  int v3; // ecx
  int v4; // edx
  int v5; // eax
  int v6; // ebx
  int v7; // eax
  int v8; // ecx
  int v9; // eax
  int v10; // edi
  float v11; // xmm0_4
  Polyhedron_IndexedPolygon_t *pPolygons; // edx
  float v13; // xmm1_4
  Polyhedron_IndexedPolygon_t *v14; // edx
  float v15; // xmm1_4
  Polyhedron_IndexedPolygon_t *v16; // edx
  float v17; // xmm1_4
  Polyhedron_IndexedPolygon_t *v18; // edx
  float v19; // xmm1_4
  int v20; // edx
  Polyhedron_IndexedPolygon_t *v21; // eax
  float v22; // xmm1_4
  int v23; // eax
  int v24; // ebx
  unsigned __int8 *v25; // edi
  IVP_Compact_Poly_Point *v26; // eax
  int v27; // ecx
  int v28; // edx
  float *v29; // eax
  Vector *pVertices; // ecx
  float y; // xmm2_4
  Vector *v32; // ecx
  float v33; // xmm2_4
  Vector *v34; // ecx
  float v35; // xmm2_4
  Vector *v36; // ecx
  float v37; // xmm2_4
  int v38; // edx
  int v39; // eax
  Vector *v40; // ecx
  float v41; // xmm2_4
  int v42; // ecx
  unsigned __int16 *v43; // eax
  int v44; // ecx
  int v45; // eax
  int v46; // edx
  Polyhedron_IndexedLineReference_t *pIndices; // ecx
  Polyhedron_IndexedLineReference_t *v48; // edx
  int iEndPointIndex; // ecx
  int v50; // eax
  int v51; // ecx
  int v52; // ebx
  int v53; // ebx
  int v54; // ecx
  int v55; // ebx
  int v56; // ecx
  _DWORD *v57; // ebx
  unsigned __int16 *v58; // edx
  IVP_Compact_Poly_Point *v59; // ebx
  Polyhedron_IndexedLine_t *pLines; // ecx
  int v61; // ebx
  int v62; // ebx
  int v63; // ecx
  int v64; // ebx
  int v65; // ecx
  int v66; // ecx
  int v67; // ebx
  int v68; // edx
  int *m_pMemory; // eax
  int *v70; // eax
  int *v71; // eax
  int iPolygonCount; // [esp-4h] [ebp-37Ch]
  int v74; // [esp-4h] [ebp-37Ch]
  int iLineCount; // [esp-4h] [ebp-37Ch]
  CUtlVectorFixedGrowable<int,64> polyTriangleStart; // [esp+Ch] [ebp-36Ch] BYREF
  CUtlVectorFixedGrowable<int,64> polyOpposite; // [esp+124h] [ebp-254h] BYREF
  CUtlVectorFixedGrowable<int,64> edgeIndex; // [esp+23Ch] [ebp-13Ch] BYREF
  int nPointIndex0; // [esp+354h] [ebp-24h]
  unsigned __int8 *pMem; // [esp+358h] [ebp-20h]
  IVP_Compact_Poly_Point *pPoints; // [esp+35Ch] [ebp-1Ch]
  int nSharedEdgeIndex; // [esp+360h] [ebp-18h]
  int nPointIndex1; // [esp+364h] [ebp-14h]
  unsigned int v84; // [esp+368h] [ebp-10h]
  int nPolyTris; // [esp+36Ch] [ebp-Ch]
  int j; // [esp+370h] [ebp-8h]
  int nTriangleCount; // [esp+374h] [ebp-4h]
  int i; // [esp+380h] [ebp+8h]
  int ia; // [esp+380h] [ebp+8h]
  int ib; // [esp+380h] [ebp+8h]
  int ic; // [esp+380h] [ebp+8h]

  polyTriangleStart.m_Memory.m_pMemory = polyTriangleStart.m_Memory.m_pFixedMemory;
  polyTriangleStart.m_pElements = polyTriangleStart.m_Memory.m_pFixedMemory;
  polyOpposite.m_Memory.m_pMemory = polyOpposite.m_Memory.m_pFixedMemory;
  polyTriangleStart.m_Memory.m_nAllocationCount = 64;
  polyOpposite.m_Memory.m_nAllocationCount = 64;
  edgeIndex.m_Memory.m_nAllocationCount = 64;
  edgeIndex.m_pElements = edgeIndex.m_Memory.m_pFixedMemory;
  iPolygonCount = pPoly->iPolygonCount;
  polyOpposite.m_pElements = polyOpposite.m_Memory.m_pFixedMemory;
  polyTriangleStart.m_Memory.m_nGrowSize = -1;
  polyTriangleStart.m_Memory.m_nMallocGrowSize = 0;
  polyOpposite.m_Memory.m_nGrowSize = -1;
  polyOpposite.m_Memory.m_nMallocGrowSize = 0;
  polyOpposite.m_Size = 0;
  edgeIndex.m_Memory.m_pMemory = edgeIndex.m_Memory.m_pFixedMemory;
  edgeIndex.m_Memory.m_nGrowSize = -1;
  edgeIndex.m_Memory.m_nMallocGrowSize = 0;
  edgeIndex.m_Size = 0;
  polyTriangleStart.m_Size = 0;
  CUtlVector<int,CUtlMemoryFixedGrowable<int,64,int>>::InsertMultipleBefore(
    this: &polyTriangleStart,
    elem: 0,
    num: iPolygonCount);
  v74 = pPoly->iPolygonCount;
  polyOpposite.m_Size = 0;
  CUtlVector<int,CUtlMemoryFixedGrowable<int,64,int>>::InsertMultipleBefore(this: &polyOpposite, elem: 0, num: v74);
  iLineCount = pPoly->iLineCount;
  edgeIndex.m_Size = 0;
  CUtlVector<int,CUtlMemoryFixedGrowable<int,64,int>>::InsertMultipleBefore(this: &edgeIndex, elem: 0, num: iLineCount);
  v2 = 0;
  if ( pPoly->iLineCount != 0 )
  {
    do
      edgeIndex.m_Memory.m_pMemory[v2++] = -1;
    while ( v2 < pPoly->iLineCount );
  }
  v3 = 0;
  v4 = 0;
  v5 = 0;
  nTriangleCount = 0;
  if ( pPoly->iPolygonCount != 0 )
  {
    do
    {
      polyTriangleStart.m_Memory.m_pMemory[v5] = v3;
      polyOpposite.m_Memory.m_pMemory[v5] = -1;
      v3 = v3 + pPoly->pPolygons[v4].iIndexCount - 2;
      ++v5;
      ++v4;
    }
    while ( v5 < pPoly->iPolygonCount );
    nTriangleCount = v3;
  }
  v6 = pPoly->iPolygonCount;
  v7 = 0;
  i = 0;
  v84 = v6;
  if ( v6 > 0 )
  {
    v8 = 0;
    do
    {
      if ( polyOpposite.m_Memory.m_pMemory[v7] == -1 )
      {
        v9 = 0;
        v10 = 0;
        v11 = -2.0;
        nPolyTris = 0;
        if ( v6 >= 4 )
        {
          j = 2;
          do
          {
            if ( i != v10 )
            {
              pPolygons = pPoly->pPolygons;
              v13 = -(float)((float)((float)(pPolygons[v8].polyNormal.y * pPolygons[v9].polyNormal.y)
                                   + (float)(pPolygons[v9].polyNormal.x * pPolygons[v8].polyNormal.x))
                           + (float)(pPolygons[v8].polyNormal.z * pPolygons[v9].polyNormal.z));
              if ( v13 > v11 )
              {
                nPolyTris = v10;
                v11 = v13;
              }
            }
            if ( i != j - 1 )
            {
              v14 = pPoly->pPolygons;
              v15 = -(float)((float)((float)(v14[v8].polyNormal.y * v14[v9 + 1].polyNormal.y)
                                   + (float)(v14[v9 + 1].polyNormal.x * v14[v8].polyNormal.x))
                           + (float)(v14[v8].polyNormal.z * v14[v9 + 1].polyNormal.z));
              if ( v15 > v11 )
              {
                nPolyTris = j - 1;
                v11 = v15;
              }
            }
            if ( i != j )
            {
              v16 = pPoly->pPolygons;
              v17 = -(float)((float)((float)(v16[v8].polyNormal.y * v16[v9 + 2].polyNormal.y)
                                   + (float)(v16[v9 + 2].polyNormal.x * v16[v8].polyNormal.x))
                           + (float)(v16[v8].polyNormal.z * v16[v9 + 2].polyNormal.z));
              if ( v17 > v11 )
              {
                nPolyTris = j;
                v11 = v17;
              }
            }
            if ( i != j + 1 )
            {
              v18 = pPoly->pPolygons;
              v19 = -(float)((float)((float)(v18[v8].polyNormal.y * v18[v9 + 3].polyNormal.y)
                                   + (float)(v18[v9 + 3].polyNormal.x * v18[v8].polyNormal.x))
                           + (float)(v18[v8].polyNormal.z * v18[v9 + 3].polyNormal.z));
              if ( v19 > v11 )
              {
                nPolyTris = j + 1;
                v11 = v19;
              }
            }
            v6 = v84;
            j += 4;
            v10 += 4;
            v9 += 4;
          }
          while ( v10 < (int)(v84 - 3) );
        }
        if ( v10 < v6 )
        {
          v20 = v10;
          do
          {
            if ( i != v10 )
            {
              v21 = pPoly->pPolygons;
              v22 = -(float)((float)((float)(v21[v8].polyNormal.y * v21[v20].polyNormal.y)
                                   + (float)(v21[v20].polyNormal.x * v21[v8].polyNormal.x))
                           + (float)(v21[v8].polyNormal.z * v21[v20].polyNormal.z));
              if ( v22 > v11 )
              {
                nPolyTris = v10;
                v11 = v22;
              }
            }
            ++v10;
            ++v20;
          }
          while ( v10 < v6 );
        }
        v23 = nPolyTris;
        polyOpposite.m_Memory.m_pMemory[i] = nPolyTris;
        polyOpposite.m_Memory.m_pMemory[v23] = i;
        v7 = i;
      }
      v6 = pPoly->iPolygonCount;
      ++v7;
      ++v8;
      i = v7;
      v84 = v6;
    }
    while ( v7 < v6 );
  }
  ia = pPoly->iVertexCount;
  v24 = 16 * (ia + nTriangleCount + 1);
  v25 = (unsigned __int8 *)ivp_malloc_aligned(size: v24, alignment: 16);
  pMem = v25;
  memset(dst: v25, value: 0, count: v24);
  v26 = (IVP_Compact_Poly_Point *)&v25[16 * nTriangleCount + 16];
  v27 = 0;
  pPoints = v26;
  if ( ia >= 4 )
  {
    v84 = ((unsigned int)(ia - 4) >> 2) + 1;
    v28 = 0;
    v29 = &v26[1].k[2];
    nSharedEdgeIndex = 4 * v84;
    do
    {
      pVertices = pPoly->pVertices;
      y = pVertices[v28].y;
      *(v29 - 6) = pVertices[v28].x * g_PhysicsUnits.unitScaleMeters;
      *(v29 - 5) = -(float)(pVertices[v28].z * g_PhysicsUnits.unitScaleMeters);
      *(v29 - 4) = y * g_PhysicsUnits.unitScaleMeters;
      *(v29 - 3) = 0.0;
      v32 = pPoly->pVertices;
      v33 = v32[v28 + 1].y;
      *(v29 - 2) = v32[v28 + 1].x * g_PhysicsUnits.unitScaleMeters;
      *(v29 - 1) = -(float)(v32[v28 + 1].z * g_PhysicsUnits.unitScaleMeters);
      *v29 = v33 * g_PhysicsUnits.unitScaleMeters;
      v29[1] = 0.0;
      v34 = pPoly->pVertices;
      v35 = v34[v28 + 2].y;
      v29[2] = v34[v28 + 2].x * g_PhysicsUnits.unitScaleMeters;
      v29[3] = -(float)(v34[v28 + 2].z * g_PhysicsUnits.unitScaleMeters);
      v29[4] = v35 * g_PhysicsUnits.unitScaleMeters;
      v29[5] = 0.0;
      v36 = pPoly->pVertices;
      v37 = v36[v28 + 3].y;
      v29[6] = v36[v28 + 3].x * g_PhysicsUnits.unitScaleMeters;
      v29[7] = -(float)(v36[v28 + 3].z * g_PhysicsUnits.unitScaleMeters);
      v29[8] = v37 * g_PhysicsUnits.unitScaleMeters;
      v29[9] = 0.0;
      v28 += 4;
      v29 += 16;
      --v84;
    }
    while ( v84 != 0 );
    v27 = nSharedEdgeIndex;
    v26 = pPoints;
  }
  if ( v27 < ia )
  {
    nSharedEdgeIndex = 12 * v27;
    v38 = (int)&v26[v27].k[2];
    ib = ia - v27;
    v39 = v27;
    do
    {
      v40 = pPoly->pVertices;
      v41 = v40[v39].y;
      *(float *)(v38 - 8) = v40[v39].x * g_PhysicsUnits.unitScaleMeters;
      *(float *)(v38 - 4) = -(float)(v40[v39].z * g_PhysicsUnits.unitScaleMeters);
      *(float *)v38 = v41 * g_PhysicsUnits.unitScaleMeters;
      *(_DWORD *)(v38 + 4) = 0;
      ++v39;
      v38 += 16;
      --ib;
    }
    while ( ib != 0 );
    v26 = pPoints;
  }
  v42 = *((_DWORD *)v25 + 2) & 0xF0;
  *(_DWORD *)v25 = (char *)v26 - (char *)v25;
  *((_WORD *)v25 + 6) = nTriangleCount;
  *((_DWORD *)v25 + 2) = v42 & 0xFFFFFFFC | (v24 >> 4 << 8) | 4;
  *((_DWORD *)v25 + 1) = -(int)v25;
  ic = 0;
  pPoints = nullptr;
  if ( pPoly->iPolygonCount != 0 )
  {
    v84 = 0;
    do
    {
      v43 = (unsigned __int16 *)((char *)&pPoly->pPolygons->iFirstIndex + v84);
      v44 = v43[1];
      v45 = v44 + *v43;
      v46 = v44 - 2;
      pIndices = pPoly->pIndices;
      nPolyTris = v46;
      v48 = &pIndices[v45 - 1];
      iEndPointIndex = v48->iEndPointIndex;
      nTriangleCount = v48->iLineIndex;
      nPointIndex0 = pPoly->pLines[nTriangleCount].iPointIndices[iEndPointIndex];
      v50 = (int)&v25[16 * ic + 20];
      v51 = (16 * ic + 4) >> 2;
      nSharedEdgeIndex = -1;
      j = (int)v48;
      if ( edgeIndex.m_Memory.m_pMemory != nullptr )
      {
        v52 = edgeIndex.m_Memory.m_pMemory[nTriangleCount];
        v48 = (Polyhedron_IndexedLineReference_t *)j;
      }
      else
      {
        v52 = nTriangleCount;
      }
      nPointIndex1 = v52;
      if ( v52 >= 0 )
      {
        v53 = v52 - v51;
        v54 = (v51 - nPointIndex1) << 16;
        *(_DWORD *)v50 ^= (*(_DWORD *)v50 ^ (v53 << 16)) & 0x7FFF0000;
        v55 = (2 * *(_DWORD *)v50) >> 17;
        v56 = *(_DWORD *)(v50 + 4 * v55) ^ v54;
        v57 = (_DWORD *)(v50 + 4 * v55);
        *v57 ^= v56 & 0x7FFF0000;
        nTriangleCount = (int)v57;
      }
      else
      {
        edgeIndex.m_Memory.m_pMemory[nTriangleCount] = v51;
        v48 = (Polyhedron_IndexedLineReference_t *)j;
      }
      j = 0;
      if ( nPolyTris > 0 )
      {
        v58 = (unsigned __int16 *)&v48[-1];
        nTriangleCount = -12 - (_DWORD)v25;
        do
        {
          v59 = pPoints;
          *(_DWORD *)(v50 - 4) ^= ((unsigned __int16)ic ^ (unsigned __int16)*(_DWORD *)(v50 - 4)) & 0xFFF;
          *(_DWORD *)(v50 - 4) ^= (*(_DWORD *)(v50 - 4)
                                 ^ (polyTriangleStart.m_Memory.m_pMemory[polyOpposite.m_Memory.m_pMemory[(_DWORD)v59]] << 12))
                                & 0xFFF000;
          pLines = pPoly->pLines;
          v61 = *((unsigned __int8 *)v58 - 2);
          nPointIndex1 = pLines[*v58].iPointIndices[*((unsigned __int8 *)v58 + 2)];
          LOWORD(pLines) = pLines[*(v58 - 2)].iPointIndices[v61];
          v62 = nSharedEdgeIndex;
          *(_WORD *)v50 = nPointIndex0;
          *(_WORD *)(v50 + 4) = nPointIndex1;
          *(_WORD *)(v50 + 8) = (_WORD)pLines;
          if ( v62 >= 0 )
          {
            v63 = (nTriangleCount + v50 - 4) >> 2;
            *(_DWORD *)v50 ^= (*(_DWORD *)v50 ^ ((v62 - v63) << 16)) & 0x7FFF0000;
            *(_DWORD *)(v50 + 4 * ((2 * *(_DWORD *)v50) >> 17)) ^= (*(_DWORD *)(v50 + 4 * ((2 * *(_DWORD *)v50) >> 17))
                                                                  ^ ((v63 - v62) << 16))
                                                                 & 0x7FFF0000;
          }
          v64 = *v58;
          v65 = (v50 + nTriangleCount) >> 2;
          nSharedEdgeIndex = v64;
          if ( edgeIndex.m_Memory.m_pMemory != nullptr )
            v64 = edgeIndex.m_Memory.m_pMemory[v64];
          if ( v64 >= 0 )
          {
            *(_DWORD *)(v50 + 4) ^= (*(_DWORD *)(v50 + 4) ^ ((v64 - v65) << 16)) & 0x7FFF0000;
            *(_DWORD *)(v50 + 4 * ((2 * *(_DWORD *)(v50 + 4)) >> 17) + 4) ^= (*(_DWORD *)(v50
                                                                                        + 4
                                                                                        * ((2 * *(_DWORD *)(v50 + 4)) >> 17)
                                                                                        + 4)
                                                                            ^ ((v65 - v64) << 16))
                                                                           & 0x7FFF0000;
          }
          else
          {
            edgeIndex.m_Memory.m_pMemory[nSharedEdgeIndex] = v65;
          }
          v66 = (v50 + nTriangleCount + 4) >> 2;
          nSharedEdgeIndex = v66;
          if ( j == nPolyTris - 1 )
          {
            v67 = *(v58 - 2);
            nPointIndex1 = v67;
            if ( edgeIndex.m_Memory.m_pMemory != nullptr )
              v67 = edgeIndex.m_Memory.m_pMemory[v67];
            if ( v67 >= 0 )
            {
              *(_DWORD *)(v50 + 8) ^= (*(_DWORD *)(v50 + 8) ^ ((v67 - v66) << 16)) & 0x7FFF0000;
              *(_DWORD *)(v50 + 4 * ((2 * *(_DWORD *)(v50 + 8)) >> 17) + 8) ^= (*(_DWORD *)(v50
                                                                                          + 4
                                                                                          * ((2 * *(_DWORD *)(v50 + 8)) >> 17)
                                                                                          + 8)
                                                                              ^ ((v66 - v67) << 16))
                                                                             & 0x7FFF0000;
            }
            else
            {
              edgeIndex.m_Memory.m_pMemory[nPointIndex1] = v66;
            }
          }
          ++ic;
          v50 += 16;
          v58 -= 2;
          ++j;
        }
        while ( j < nPolyTris );
        v25 = pMem;
      }
      v68 = pPoly->iPolygonCount;
      v84 += 16;
      pPoints = (IVP_Compact_Poly_Point *)((char *)pPoints + 1);
    }
    while ( (int)pPoints < v68 );
  }
  m_pMemory = edgeIndex.m_Memory.m_pMemory;
  edgeIndex.m_Size = 0;
  if ( edgeIndex.m_Memory.m_nGrowSize >= 0 )
  {
    if ( edgeIndex.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: edgeIndex.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      edgeIndex.m_Memory.m_pMemory = nullptr;
    }
    edgeIndex.m_Memory.m_nAllocationCount = 0;
  }
  edgeIndex.m_pElements = m_pMemory;
  if ( edgeIndex.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      edgeIndex.m_Memory.m_pMemory = nullptr;
    }
    edgeIndex.m_Memory.m_nAllocationCount = 0;
  }
  v70 = polyOpposite.m_Memory.m_pMemory;
  polyOpposite.m_Size = 0;
  if ( polyOpposite.m_Memory.m_nGrowSize >= 0 )
  {
    if ( polyOpposite.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: polyOpposite.m_Memory.m_pMemory);
      v70 = nullptr;
      polyOpposite.m_Memory.m_pMemory = nullptr;
    }
    polyOpposite.m_Memory.m_nAllocationCount = 0;
  }
  polyOpposite.m_pElements = v70;
  if ( polyOpposite.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v70 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v70);
      polyOpposite.m_Memory.m_pMemory = nullptr;
    }
    polyOpposite.m_Memory.m_nAllocationCount = 0;
  }
  v71 = polyTriangleStart.m_Memory.m_pMemory;
  polyTriangleStart.m_Size = 0;
  if ( polyTriangleStart.m_Memory.m_nGrowSize >= 0 )
  {
    if ( polyTriangleStart.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: polyTriangleStart.m_Memory.m_pMemory);
      v71 = nullptr;
      polyTriangleStart.m_Memory.m_pMemory = nullptr;
    }
    polyTriangleStart.m_Memory.m_nAllocationCount = 0;
  }
  polyTriangleStart.m_pElements = v71;
  if ( polyTriangleStart.m_Memory.m_nGrowSize >= 0 && v71 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v71);
  return (IVP_Compact_Ledge *)v25;
}
