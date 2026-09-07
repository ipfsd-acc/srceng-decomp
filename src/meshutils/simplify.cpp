// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: meshutils/simplify.cpp
// Functions: 18
// ============================================================

#include "meshutils\simplify.h"

//------------------------------------------------------------------------------
// Address: 0x00573D80
// Name: public: static bool CEdgeQueue::IsLowerPriority(struct edge_queue_entry_t const __near &,struct edge_queue_entry_t const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CEdgeQueue::IsLowerPriority(const edge_queue_entry_t *node1, const edge_queue_entry_t *node2)
{
  return node1->m_flError > node2->m_flError;
}

//------------------------------------------------------------------------------
// Address: 0x005741F0
// Name: public: void CQEMEdge::UpdateError(class Vector const __near &,class Vector const __near &,class CQuadricError const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CQEMEdge::UpdateError(
        CQEMEdge *this@<ecx>,
        float a2@<ebp>,
        const Vector *v0,
        const Vector *v1,
        const CQuadricError *pVertError)
{
  float v6; // xmm7_4
  const CQuadricError *v7; // eax
  float v8; // xmm0_4
  float v9; // xmm4_4
  float v10; // xmm2_4
  float v11; // xmm5_4
  float v12; // xmm6_4
  float v13; // xmm1_4
  float v14; // xmm3_4
  const CQuadricError *v15; // ecx
  float v16; // xmm7_4
  float z; // xmm1_4
  float y; // xmm3_4
  float x; // xmm2_4
  float v20; // xmm0_4
  float v21; // xmm4_4
  float v22; // xmm2_4
  float v23; // xmm3_4
  float v24; // xmm1_4
  float v25; // xmm0_4
  float v26; // xmm2_4
  float v27; // xmm1_4
  float v28; // xmm3_4
  float a22; // xmm7_4
  float a11; // xmm6_4
  float v31; // xmm4_4
  float a00; // xmm5_4
  float v33; // xmm2_4
  const Vector *v34; // eax
  float v35; // xmm3_4
  float v36; // xmm0_4
  float v37; // xmm4_4
  float m_flCurrentError; // xmm1_4
  double v39; // st7
  float v40; // xmm4_4
  float v41; // xmm5_4
  float v42; // xmm3_4
  float v43; // xmm6_4
  __int128 v44; // xmm0
  double v45; // st6
  double v46; // st7
  __int128 v47; // xmm0
  float v48; // xmm0_4
  float v49; // xmm0_4
  float v50; // xmm0_4
  float a10; // [esp+4h] [ebp-D0h]
  Cholesky3x3_t v52; // [esp+24h] [ebp-B0h] BYREF
  float v53[5]; // [esp+48h] [ebp-8Ch] BYREF
  Vector v54; // [esp+5Ch] [ebp-78h] BYREF
  Vector v55; // [esp+68h] [ebp-6Ch] BYREF
  float v56; // [esp+80h] [ebp-54h]
  float v57; // [esp+90h] [ebp-44h]
  float v58; // [esp+94h] [ebp-40h]
  float v59; // [esp+9Ch] [ebp-38h]
  float v60; // [esp+A0h] [ebp-34h]
  float v61; // [esp+A4h] [ebp-30h]
  __int128 v62; // [esp+A8h] [ebp-2Ch]
  Vector vTest; // [esp+B8h] [ebp-1Ch] BYREF
  Vector vEdge; // [esp+C4h] [ebp-10h]
  float retaddr; // [esp+D4h] [ebp+0h]

  vEdge.y = a2;
  vEdge.z = retaddr;
  v6 = pVertError[this->m_nVert[1]].m_coefficients[7];
  v7 = &pVertError[this->m_nVert[1]];
  v8 = v7->m_coefficients[0] + pVertError[this->m_nVert[0]].m_coefficients[0];
  v9 = v7->m_coefficients[4] + pVertError[this->m_nVert[0]].m_coefficients[4];
  v10 = v7->m_coefficients[2] + pVertError[this->m_nVert[0]].m_coefficients[2];
  v11 = v7->m_coefficients[5] + pVertError[this->m_nVert[0]].m_coefficients[5];
  v12 = v7->m_coefficients[6] + pVertError[this->m_nVert[0]].m_coefficients[6];
  v13 = v7->m_coefficients[1] + pVertError[this->m_nVert[0]].m_coefficients[1];
  v14 = v7->m_coefficients[3] + pVertError[this->m_nVert[0]].m_coefficients[3];
  v15 = &pVertError[this->m_nVert[0]];
  v52.m_inv00 = v6 + v15->m_coefficients[7];
  v52.m_inv11 = v7->m_coefficients[8] + v15->m_coefficients[8];
  v16 = v7->m_coefficients[9] + v15->m_coefficients[9];
  this->m_error.m_coefficients[0] = v8;
  this->m_error.m_coefficients[7] = v52.m_inv00;
  this->m_error.m_coefficients[8] = v52.m_inv11;
  this->m_error.m_coefficients[4] = v9;
  this->m_error.m_coefficients[2] = v10;
  this->m_error.m_coefficients[5] = v11;
  this->m_error.m_coefficients[6] = v12;
  this->m_error.m_coefficients[9] = v16;
  this->m_error.m_coefficients[1] = v13;
  this->m_error.m_coefficients[3] = v14;
  z = v0->z;
  y = v0->y;
  x = v0->x;
  v58 = z * y;
  v59 = z * z;
  vEdge.x = this->m_error.m_coefficients[9];
  v20 = (float)((float)((float)((float)((float)((float)((float)((float)((float)(this->m_error.m_coefficients[0]
                                                                              * (float)(x * x))
                                                                      + vEdge.x)
                                                              + (float)(this->m_error.m_coefficients[1] * (float)(y * x)))
                                                      + (float)(this->m_error.m_coefficients[2] * (float)(z * x)))
                                              + (float)(this->m_error.m_coefficients[3] * x))
                                      + (float)(this->m_error.m_coefficients[4] * (float)(y * y)))
                              + (float)(this->m_error.m_coefficients[5] * (float)(z * y)))
                      + (float)(this->m_error.m_coefficients[6] * y))
              + (float)(this->m_error.m_coefficients[7] * (float)(z * z)))
      + (float)(z * this->m_error.m_coefficients[8]);
  this->m_flCurrentError = v20;
  v21 = v1->y;
  v22 = v1->z;
  v23 = v1->x;
  v57 = v21 * v21;
  v58 = v22 * v21;
  v59 = v22 * v22;
  vEdge.x = this->m_error.m_coefficients[9];
  v24 = (float)((float)((float)((float)((float)((float)((float)((float)((float)(this->m_error.m_coefficients[0]
                                                                              * (float)(v23 * v23))
                                                                      + vEdge.x)
                                                              + (float)(this->m_error.m_coefficients[1]
                                                                      * (float)(v21 * v23)))
                                                      + (float)(this->m_error.m_coefficients[2] * (float)(v22 * v23)))
                                              + (float)(this->m_error.m_coefficients[3] * v23))
                                      + (float)(this->m_error.m_coefficients[4] * (float)(v21 * v21)))
                              + (float)(this->m_error.m_coefficients[5] * (float)(v22 * v21)))
                      + (float)(this->m_error.m_coefficients[6] * v21))
              + (float)(this->m_error.m_coefficients[7] * (float)(v22 * v22)))
      + (float)(v22 * this->m_error.m_coefficients[8]);
  this->m_nBestIndex = 0;
  if ( v20 <= v24 )
  {
    v25 = 0.0;
    this->m_vOptimal = *v0;
  }
  else
  {
    v25 = 1.0;
    this->m_vOptimal = *v1;
    this->m_nBestIndex = 1;
    this->m_flCurrentError = v24;
  }
  v26 = this->m_error.m_coefficients[6];
  v27 = this->m_error.m_coefficients[3];
  v28 = this->m_error.m_coefficients[5];
  a22 = this->m_error.m_coefficients[7];
  a11 = this->m_error.m_coefficients[4];
  v31 = this->m_error.m_coefficients[8];
  a00 = this->m_error.m_coefficients[0];
  this->m_flInterp = v25;
  v57 = v26 * 0.5;
  v33 = this->m_error.m_coefficients[2];
  v56 = v27 * 0.5;
  a10 = this->m_error.m_coefficients[1] * 0.5;
  v60 = v31 * 0.5;
  Cholesky3x3_t::Init(this: &v52, a00, a10, a11, a20: v33 * 0.5, a21: v28 * 0.5, a22);
  v55.x = v56;
  v55.y = v57;
  v55.z = v60;
  v34 = Cholesky3x3_t::SolveLeft(this: &v52, result: (const Vector *)&v53[1], b: &v55);
  Cholesky3x3_t::SolveRight(this: &v52, result: &v54, b: v34);
  v35 = -v54.z;
  v58 = (float)-v54.z * (float)-v54.y;
  v59 = v35 * v35;
  v36 = (float)((float)((float)((float)((float)-v54.x * (float)-v54.x) * this->m_error.m_coefficients[0])
                      + this->m_error.m_coefficients[9])
              + (float)(this->m_error.m_coefficients[1] * (float)((float)-v54.y * (float)-v54.x)))
      + (float)(this->m_error.m_coefficients[2] * (float)((float)-v54.z * (float)-v54.x));
  v37 = this->m_error.m_coefficients[3] * (float)-v54.x;
  *((float *)&v62 + 1) = -v54.x;
  *((float *)&v62 + 2) = -v54.y;
  *((float *)&v62 + 3) = -v54.z;
  m_flCurrentError = this->m_flCurrentError;
  v61 = (float)((float)((float)((float)((float)(v36 + v37)
                                      + (float)(this->m_error.m_coefficients[4]
                                              * (float)(*((float *)&v62 + 2) * *((float *)&v62 + 2))))
                              + (float)(this->m_error.m_coefficients[5] * (float)(v35 * *((float *)&v62 + 2))))
                      + (float)(*((float *)&v62 + 2) * this->m_error.m_coefficients[6]))
              + (float)(this->m_error.m_coefficients[7] * (float)(v35 * v35)))
      + (float)(v35 * this->m_error.m_coefficients[8]);
  if ( m_flCurrentError > v61 )
  {
    vTest.x = v1->x - v0->x;
    vTest.y = v1->y - v0->y;
    vTest.z = v1->z - v0->z;
    v39 = VectorNormalize(vec: &vTest);
    vEdge.x = v39;
    v40 = *((float *)&v62 + 2);
    v41 = *((float *)&v62 + 3);
    v42 = *((float *)&v62 + 1);
    v43 = vEdge.x;
    v44 = 0;
    *(float *)&v44 = fsqrt(
                       (float)((float)((float)(*((float *)&v62 + 2) - v0->y) * (float)(*((float *)&v62 + 2) - v0->y))
                             + (float)((float)(*((float *)&v62 + 3) - v0->z) * (float)(*((float *)&v62 + 3) - v0->z)))
                     + (float)((float)(*((float *)&v62 + 1) - v0->x) * (float)(*((float *)&v62 + 1) - v0->x)));
    v62 = v44;
    v45 = v39;
    v46 = *(float *)&v44;
    v47 = 0;
    *(float *)&v47 = fsqrt(
                       (float)((float)((float)(v40 - v1->y) * (float)(v40 - v1->y))
                             + (float)((float)(v41 - v1->z) * (float)(v41 - v1->z)))
                     + (float)((float)(v42 - v1->x) * (float)(v42 - v1->x)));
    *(_OWORD *)v53 = v47;
    if ( v45 > v46 || vEdge.x > v53[0] )
    {
      v48 = v61;
      this->m_vOptimal.x = v42;
      this->m_vOptimal.y = v40;
      this->m_vOptimal.z = v41;
      this->m_flCurrentError = v48;
      if ( v43 > 0.0 )
      {
        v49 = (float)((float)((float)((float)(this->m_vOptimal.y - v0->y) * vTest.y)
                            + (float)((float)(this->m_vOptimal.x - v0->x) * vTest.x))
                    + (float)((float)(this->m_vOptimal.z - v0->z) * vTest.z))
            * (float)(1.0 / v43);
        this->m_flInterp = v49;
        if ( v49 >= 0.0 )
        {
          if ( v49 > 1.0 )
            v49 = 1.0;
          this->m_flInterp = v49;
        }
        else
        {
          this->m_flInterp = 0.0;
        }
      }
    }
  }
  v50 = this->m_flCurrentError;
  if ( v50 >= 0.0 )
    this->m_flCurrentError = v50;
  else
    this->m_flCurrentError = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x00574890
// Name: public: void CUtlMemory<unsigned int,int>::ConvertToGrowableMemory(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<unsigned int,int>::ConvertToGrowableMemory(
        CUtlMemory<unsigned int,int> *this,
        int nGrowSize)
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
      this->m_pMemory = (unsigned int *)v5;
    }
    else
    {
      this->m_pMemory = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005748F0
// Name: public: bool CMeshVisit::IsValidCollapseVertex(int,int,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMeshVisit::IsValidCollapseVertex(
        CMeshVisit *this,
        int nVertCheck,
        int nVertOpposite,
        const Vector *vReplacePos)
{
  int m_nVertexStrideFloats; // edx
  float *m_pVertexBase; // esi
  CVertVisit *v6; // eax
  vertex_triangle_t *m_pMemory; // edi
  float v8; // xmm4_4
  float v9; // xmm1_4
  float v10; // xmm3_4
  unsigned int nV1; // ecx
  float v12; // xmm6_4
  __int64 vOld; // [esp+24h] [ebp-2Ch]
  float vOld_8; // [esp+2Ch] [ebp-24h]
  __int64 v2; // [esp+30h] [ebp-20h]
  float v2_8; // [esp+38h] [ebp-18h]
  __int64 v1; // [esp+3Ch] [ebp-14h]
  float v1_8; // [esp+44h] [ebp-Ch]
  int nTriCount; // [esp+48h] [ebp-8h]
  int i; // [esp+4Ch] [ebp-4h]
  int nV2; // [esp+58h] [ebp+8h]

  m_nVertexStrideFloats = this->m_nVertexStrideFloats;
  m_pVertexBase = this->m_pVertexBase;
  v6 = &this->m_vertList.m_Memory.m_pMemory[nVertCheck];
  vOld = *(_QWORD *)&m_pVertexBase[nVertCheck * m_nVertexStrideFloats];
  vOld_8 = m_pVertexBase[nVertCheck * m_nVertexStrideFloats + 2];
  nTriCount = v6->m_triangles.m_Size;
  i = 0;
  if ( nTriCount <= 0 )
    return 1;
  m_pMemory = v6->m_triangles.m_Memory.m_pMemory;
  v8 = m_pVertexBase[nVertCheck * m_nVertexStrideFloats + 2];
  v9 = m_pVertexBase[nVertCheck * m_nVertexStrideFloats + 1];
  v10 = m_pVertexBase[nVertCheck * m_nVertexStrideFloats];
  while ( 1 )
  {
    nV1 = m_pMemory->nV1;
    nV2 = m_pMemory->nV2;
    if ( m_pMemory->nV1 != nVertOpposite && nV2 != nVertOpposite )
    {
      v1_8 = m_pVertexBase[nV1 * m_nVertexStrideFloats + 2];
      v1 = *(_QWORD *)&m_pVertexBase[nV1 * m_nVertexStrideFloats];
      v2 = *(_QWORD *)&m_pVertexBase[nV2 * m_nVertexStrideFloats];
      v12 = *((float *)&v1 + 1) - v9;
      v2_8 = m_pVertexBase[nV2 * m_nVertexStrideFloats + 2];
      if ( (float)((float)((float)((float)((float)((float)(v2_8 - vReplacePos->z)
                                                 * (float)(*(float *)&v1 - vReplacePos->x))
                                         - (float)((float)(v1_8 - vReplacePos->z)
                                                 * (float)(*(float *)&v2 - vReplacePos->x)))
                                 * (float)((float)((float)(v2_8 - v8) * (float)(*(float *)&v1 - v10))
                                         - (float)((float)(v1_8 - v8) * (float)(*(float *)&v2 - v10))))
                         + (float)((float)((float)((float)(*((float *)&v2 + 1) - vReplacePos->y)
                                                 * (float)(v1_8 - vReplacePos->z))
                                         - (float)((float)(v2_8 - vReplacePos->z)
                                                 * (float)(*((float *)&v1 + 1) - vReplacePos->y)))
                                 * (float)((float)((float)(*((float *)&v2 + 1) - v9) * (float)(v1_8 - v8))
                                         - (float)((float)(v2_8 - v8) * v12))))
                 + (float)((float)((float)((float)(*((float *)&v1 + 1) - vReplacePos->y)
                                         * (float)(*(float *)&v2 - vReplacePos->x))
                                 - (float)((float)(*((float *)&v2 + 1) - vReplacePos->y)
                                         * (float)(*(float *)&v1 - vReplacePos->x)))
                         * (float)((float)((float)(*(float *)&v2 - v10) * v12)
                                 - (float)((float)(*((float *)&v2 + 1) - v9) * (float)(*(float *)&v1 - v10))))) < 0.0 )
        break;
      v10 = *(float *)&vOld;
      v9 = *((float *)&vOld + 1);
      v8 = vOld_8;
    }
    ++m_pMemory;
    if ( ++i >= nTriCount )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00574AD0
// Name: public: void CUtlPriorityQueue<struct edge_queue_entry_t,class CDefUtlPriorityQueueLessFunc<struct edge_queue_entry_t>,class CUtlMemory<struct edge_queue_entry_t,int>>::RemoveAtHead(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlPriorityQueue<edge_queue_entry_t,CDefUtlPriorityQueueLessFunc<edge_queue_entry_t>,CUtlMemory<edge_queue_entry_t,int>>::RemoveAtHead(
        CUtlPriorityQueue<edge_queue_entry_t,CDefUtlPriorityQueueLessFunc<edge_queue_entry_t>,CUtlMemory<edge_queue_entry_t,int> > *this)
{
  int m_Size; // ecx
  edge_queue_entry_t *m_pMemory; // eax
  int v4; // eax
  int v5; // edi
  int v6; // esi
  int v7; // eax
  bool v8; // zf
  int v9; // eax
  edge_queue_entry_t *v10; // eax
  float m_flError; // ecx
  edge_queue_entry_t *v12; // eax
  int m_nEdgeIndex; // [esp+Ch] [ebp-10h]
  int half; // [esp+10h] [ebp-Ch]
  int count; // [esp+14h] [ebp-8h]
  int child; // [esp+18h] [ebp-4h]
  int childa; // [esp+18h] [ebp-4h]

  m_Size = this->m_heap.m_Size;
  if ( m_Size > 0 )
  {
    if ( m_Size != 1 )
    {
      m_pMemory = this->m_heap.m_Memory.m_pMemory;
      m_pMemory->m_flError = this->m_heap.m_Memory.m_pMemory[m_Size - 1].m_flError;
      m_pMemory->m_nEdgeIndex = m_pMemory[m_Size - 1].m_nEdgeIndex;
    }
    --this->m_heap.m_Size;
  }
  v4 = this->m_heap.m_Size;
  v5 = 0;
  count = v4;
  if ( v4 != 0 )
  {
    v6 = 0;
    for ( half = v4 / 2; v6 < half; v5 = v6 )
    {
      v7 = 2 * v5 + 1;
      child = v7;
      if ( v7 < count )
      {
        v8 = !this->m_LessFunc(a1: &this->m_heap.m_Memory.m_pMemory[v5], a2: &this->m_heap.m_Memory.m_pMemory[v7]);
        v7 = child;
        if ( !v8 )
          v6 = child;
      }
      v9 = v7 + 1;
      childa = v9;
      if ( v9 < count
        && this->m_LessFunc(a1: &this->m_heap.m_Memory.m_pMemory[v6], a2: &this->m_heap.m_Memory.m_pMemory[v9]) )
      {
        v6 = childa;
      }
      if ( v6 == v5 )
        break;
      v10 = this->m_heap.m_Memory.m_pMemory;
      m_flError = this->m_heap.m_Memory.m_pMemory[v5].m_flError;
      m_nEdgeIndex = this->m_heap.m_Memory.m_pMemory[v5].m_nEdgeIndex;
      v10[v5].m_flError = v10[v6].m_flError;
      v10[v5].m_nEdgeIndex = v10[v6].m_nEdgeIndex;
      v12 = this->m_heap.m_Memory.m_pMemory;
      v12[v6].m_flError = m_flError;
      v12[v6].m_nEdgeIndex = m_nEdgeIndex;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00574C40
// Name: int CountUsedVerts(unsigned int const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CountUsedVerts(const unsigned int *pIndexList, int nIndexCount, int nVertexCount)
{
  unsigned __int8 *m_pMemory; // edi
  int m_Size; // eax
  int v5; // esi
  int i; // ecx
  unsigned int v7; // eax
  CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > used; // [esp+Ch] [ebp-14h] BYREF

  m_pMemory = nullptr;
  m_Size = 0;
  memset(&used, 0, sizeof(used));
  if ( nVertexCount != 0 )
  {
    if ( nVertexCount > 0 )
    {
      CUtlMemory<bool,int>::Grow(this: (CUtlMemory<bool,int> *)&used, num: nVertexCount);
      m_Size = used.m_Size;
      m_pMemory = used.m_Memory.m_pMemory;
    }
    if ( m_Size > 0 )
    {
      if ( nVertexCount <= 0 )
        goto LABEL_9;
      _V_memmove(dest: &m_pMemory[nVertexCount], src: m_pMemory, count: m_Size);
    }
    if ( nVertexCount > 0 )
      memset(dst: m_pMemory, value: 0, count: nVertexCount);
  }
LABEL_9:
  v5 = 0;
  for ( i = 0; i < nIndexCount; ++i )
  {
    v7 = pIndexList[i];
    if ( m_pMemory[v7] == 0 )
    {
      m_pMemory[v7] = 1;
      ++v5;
    }
  }
  if ( used.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00574CF0
// Name: public: void CUtlPriorityQueue<struct edge_queue_entry_t,class CDefUtlPriorityQueueLessFunc<struct edge_queue_entry_t>,class CUtlMemory<struct edge_queue_entry_t,int>>::Insert(struct edge_queue_entry_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlPriorityQueue<edge_queue_entry_t,CDefUtlPriorityQueueLessFunc<edge_queue_entry_t>,CUtlMemory<edge_queue_entry_t,int>>::Insert(
        CUtlPriorityQueue<edge_queue_entry_t,CDefUtlPriorityQueueLessFunc<edge_queue_entry_t>,CUtlMemory<edge_queue_entry_t,int> > *this,
        const edge_queue_entry_t *element)
{
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  edge_queue_entry_t *m_pMemory; // ecx
  int v6; // eax
  int v7; // esi
  edge_queue_entry_t *v8; // eax
  float m_flError; // ecx
  edge_queue_entry_t *v10; // eax
  int m_nEdgeIndex; // [esp+Ch] [ebp-4h]

  m_Size = this->m_heap.m_Size;
  m_nAllocationCount = this->m_heap.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CacheOptimizedKDNode,int>::Grow(
      (CUtlMemory<ResourceEntryInfo,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_heap.m_Size;
  m_pMemory = this->m_heap.m_Memory.m_pMemory;
  v6 = this->m_heap.m_Size - m_Size - 1;
  this->m_heap.m_pElements = this->m_heap.m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 8 * v6);
  this->m_heap.m_Memory.m_pMemory[m_Size] = *element;
  if ( m_Size != 0 )
  {
    do
    {
      v7 = (m_Size + 1) / 2 - 1;
      if ( this->m_LessFunc(a1: &this->m_heap.m_Memory.m_pMemory[m_Size], a2: &this->m_heap.m_Memory.m_pMemory[v7]) )
        break;
      v8 = this->m_heap.m_Memory.m_pMemory;
      m_flError = this->m_heap.m_Memory.m_pMemory[v7].m_flError;
      m_nEdgeIndex = this->m_heap.m_Memory.m_pMemory[v7].m_nEdgeIndex;
      v8[v7].m_flError = v8[m_Size].m_flError;
      v8[v7].m_nEdgeIndex = v8[m_Size].m_nEdgeIndex;
      v10 = this->m_heap.m_Memory.m_pMemory;
      v10[m_Size].m_flError = m_flError;
      v10[m_Size].m_nEdgeIndex = m_nEdgeIndex;
      m_Size = (m_Size + 1) / 2 - 1;
    }
    while ( v7 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00574DB0
// Name: public: void CMeshVisit::WriteMeshIndexList(class CUtlVector<unsigned int,class CUtlMemory<unsigned int,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMeshVisit::WriteMeshIndexList(CMeshVisit *this, CUtlMemory<S3RGBA,int> *indexOut)
{
  CMeshVisit *v2; // eax
  int m_Size; // edx
  int v4; // esi
  int v5; // edi
  int v6; // ebx
  unsigned int v7; // ecx
  int *p_m_Size; // eax
  unsigned int v9; // edx
  int v10; // edi
  bool v11; // zf
  int v12; // ebx
  int m_nAllocationCount; // eax
  unsigned int *m_pMemory; // ecx
  int v16; // eax
  unsigned int v17; // edi
  int v18; // eax
  int v19; // ebx
  CVertVisit *v20; // ecx
  int j; // edx
  int v22; // ecx
  bool v23; // cf
  unsigned int *v24; // ecx
  int v25; // [esp+Ch] [ebp-Ch]
  CMeshVisit *v26; // [esp+10h] [ebp-8h]
  unsigned int nCurrentVertexCount; // [esp+14h] [ebp-4h]
  unsigned int i; // [esp+20h] [ebp+8h]

  v2 = this;
  m_Size = this->m_vertList.m_Size;
  v4 = 0;
  v5 = 0;
  v6 = 0;
  v7 = 0;
  v26 = v2;
  nCurrentVertexCount = m_Size;
  if ( m_Size >= 2 )
  {
    p_m_Size = &v2->m_vertList.m_Memory.m_pMemory[1].m_triangles.m_Size;
    v9 = ((unsigned int)(m_Size - 2) >> 1) + 1;
    v7 = 2 * v9;
    do
    {
      v4 += *(p_m_Size - 5);
      v5 += *p_m_Size;
      p_m_Size += 10;
      --v9;
    }
    while ( v9 != 0 );
    m_Size = nCurrentVertexCount;
    v2 = v26;
  }
  if ( v7 < m_Size )
    v6 = v2->m_vertList.m_Memory.m_pMemory[v7].m_triangles.m_Size;
  v10 = v4 + v5;
  v11 = v10 + v6 == 0;
  v12 = v10 + v6;
  indexOut[1].m_pMemory = nullptr;
  if ( !v11 )
  {
    m_nAllocationCount = indexOut->m_nAllocationCount;
    if ( v12 > m_nAllocationCount )
    {
      CUtlMemory<HemiLightData_t *,int>::Grow(this: indexOut, num: v12 - m_nAllocationCount);
      m_Size = nCurrentVertexCount;
    }
    indexOut[1].m_pMemory = (S3RGBA *)((char *)indexOut[1].m_pMemory + v12);
    m_pMemory = (unsigned int *)indexOut->m_pMemory;
    v16 = (int)indexOut[1].m_pMemory - v12;
    indexOut[1].m_nAllocationCount = (int)indexOut->m_pMemory;
    if ( v16 > 0 && v12 > 0 )
    {
      _V_memmove(dest: &m_pMemory[v12], src: m_pMemory, count: 4 * v16);
      m_Size = nCurrentVertexCount;
    }
  }
  v17 = 0;
  v18 = 0;
  i = 0;
  if ( m_Size != 0 )
  {
    v19 = 0;
    v25 = 0;
    do
    {
      v20 = v26->m_vertList.m_Memory.m_pMemory;
      for ( j = 0; j < *(int *)((char *)&v20->m_triangles.m_Size + v19); ++j )
      {
        v22 = *(int *)((char *)&v20->m_triangles.m_Memory.m_pMemory + v19);
        v23 = *(_DWORD *)(v22 + 8 * j) < v17;
        v24 = (unsigned int *)(v22 + 8 * j);
        if ( !v23 && v24[1] >= v17 )
        {
          indexOut->m_pMemory[v18] = (S3RGBA)v17;
          indexOut->m_pMemory[v18 + 1] = (S3RGBA)*v24;
          v19 = v25;
          indexOut->m_pMemory[v18 + 2] = (S3RGBA)v24[1];
          v17 = i;
          v18 += 3;
        }
        v20 = v26->m_vertList.m_Memory.m_pMemory;
      }
      ++v17;
      v19 += 20;
      i = v17;
      v25 = v19;
    }
    while ( v17 < nCurrentVertexCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00574ED0
// Name: public: void CMeshVisit::RemapEdge(int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMeshVisit::RemapEdge(CMeshVisit *this, int nVertexRemove, int nVertexConnect, int nVertexKeep)
{
  int v4; // eax
  bool v7; // cc
  int v8; // ecx
  int v9; // eax
  unsigned int v10; // eax
  __int64 v11; // xmm0_8
  unsigned int m_nV1; // ecx
  char v13; // cl
  int v14; // eax
  int v15; // ecx
  int v16; // eax
  unsigned int v17; // edx
  unsigned int v18; // ecx
  unsigned int v19; // eax
  int v20; // eax
  unsigned int v21; // edi
  edge_hash_t tmp; // [esp+8h] [ebp-14h] BYREF
  edge_queue_entry_t element; // [esp+14h] [ebp-8h] BYREF
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF
  CUtlScalarHash<edge_hash_t,CDefaultHash32> *nVertexRemovea; // [esp+24h] [ebp+8h]

  v4 = nVertexConnect;
  tmp.m_nV0 = nVertexRemove;
  v7 = nVertexRemove <= nVertexConnect;
  if ( nVertexRemove < nVertexConnect
    || (tmp.m_nV0 = nVertexConnect, tmp.m_nV1 = nVertexRemove, nVertexRemove <= nVertexConnect) )
  {
    tmp.m_nV1 = nVertexConnect;
    v7 = nVertexRemove <= nVertexConnect;
  }
  v8 = nVertexRemove;
  if ( v7 )
  {
    v8 = nVertexConnect;
    v4 = nVertexRemove;
  }
  v9 = v8 ^ __ROL4__(v4, 16);
  tmp.m_pSharedEdge = nullptr;
  nVertexRemovea = &this->m_edgeHash;
  v10 = CUtlScalarHash<edge_hash_t,CDefaultHash32>::Find(
          this: &this->m_edgeHash,
          uiKey: v9 != -1 ? v9 : 0,
          dataRecord: &tmp);
  if ( v10 != -1 )
  {
    v11 = *(_QWORD *)&this->m_edgeHash.m_pData[v10].m_Data.m_pSharedEdge;
    m_nV1 = this->m_edgeHash.m_pData[v10].m_Data.m_nV1;
    *(_QWORD *)&tmp.m_pSharedEdge = v11;
    tmp.m_nV1 = m_nV1;
    v13 = 0;
    if ( *(_DWORD *)(v11 + 60) == nVertexRemove )
    {
      *(_DWORD *)(v11 + 60) = nVertexKeep;
      v13 = 1;
    }
    if ( *(_DWORD *)(v11 + 64) == nVertexRemove )
    {
      *(_DWORD *)(v11 + 64) = nVertexKeep;
    }
    else if ( v13 == 0 )
    {
      return;
    }
    CUtlScalarHash<edge_hash_t,CDefaultHash32>::Remove(this: nVertexRemovea, hHash: v10);
    v14 = *(_DWORD *)(v11 + 64);
    v15 = *(_DWORD *)(v11 + 60);
    if ( v15 == v14 )
      goto LABEL_16;
    CQEMEdge::UpdateError(
      this: (CQEMEdge *)v11,
      a2: COERCE_FLOAT(&savedregs),
      v0: (const Vector *)&this->m_pVertexBase[this->m_nVertexStrideFloats * v15],
      v1: (const Vector *)&this->m_pVertexBase[this->m_nVertexStrideFloats * v14],
      pVertError: this->m_errorVert.m_Memory.m_pMemory);
    v16 = (signed int)(v11 - (unsigned int)this->m_edgeList.m_Memory.m_pMemory) / 76;
    element.m_flError = *(float *)(v11 + 52);
    element.m_nEdgeIndex = v16;
    CUtlPriorityQueue<edge_queue_entry_t,CDefUtlPriorityQueueLessFunc<edge_queue_entry_t>,CUtlMemory<edge_queue_entry_t,int>>::Insert(
      this: &this->m_edgeQueue,
      &element);
    v17 = *(_DWORD *)(v11 + 60);
    v18 = *(_DWORD *)(v11 + 64);
    v19 = v17;
    tmp.m_nV0 = v17;
    tmp.m_nV1 = v18;
    if ( v17 > v18 )
    {
      v19 = v18;
      v18 = v17;
      tmp.m_nV0 = v19;
      tmp.m_nV1 = v17;
    }
    v20 = v18 ^ __ROL4__(v19, 16);
    v21 = v20 != -1 ? v20 : 0;
    if ( CUtlScalarHash<edge_hash_t,CDefaultHash32>::Find(this: nVertexRemovea, uiKey: v21, dataRecord: &tmp) == -1 )
      CUtlScalarHash<edge_hash_t,CDefaultHash32>::Insert(this: nVertexRemovea, uiKey: v21, data: &tmp);
    else
LABEL_16:
      *(_BYTE *)(v11 + 74) = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00575040
// Name: public: void CMeshVisit::Get1Ring(class CUniqueVertexList __near &,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMeshVisit::Get1Ring(CMeshVisit *this, CUniqueVertexList *list, int nVertex)
{
  unsigned int v3; // eax
  CUniqueVertexList *v4; // ebx
  int v5; // edx
  int m_Size; // ecx
  CUniqueVertexList *v7; // edi
  int v8; // esi
  int v9; // eax
  unsigned int *m_pMemory; // edx
  int v11; // ecx
  CUniqueVertexList *v12; // esi
  int v13; // eax
  unsigned int *v14; // edx
  int nTriCount; // [esp+0h] [ebp-Ch]
  unsigned int v16; // [esp+4h] [ebp-8h]
  CMeshVisit *v17; // [esp+8h] [ebp-4h]

  v3 = 20 * nVertex;
  v17 = this;
  v16 = 20 * nVertex;
  nTriCount = this->m_vertList.m_Memory.m_pMemory[nVertex].m_triangles.m_Size;
  nVertex = 0;
  if ( nTriCount > 0 )
  {
    v4 = list;
    while ( 1 )
    {
      v5 = *(int *)((char *)&this->m_vertList.m_Memory.m_pMemory->m_triangles.m_Memory.m_pMemory + v3);
      m_Size = v4->m_Size;
      v7 = *(CUniqueVertexList **)(v5 + 8 * nVertex);
      v8 = v5 + 8 * nVertex;
      v9 = 0;
      list = v7;
      if ( m_Size <= 0 )
        goto LABEL_10;
      m_pMemory = v4->m_Memory.m_pMemory;
      while ( (CUniqueVertexList *)*m_pMemory != v7 )
      {
        ++v9;
        ++m_pMemory;
        if ( v9 >= m_Size )
          goto LABEL_10;
      }
      if ( v9 == -1 )
LABEL_10:
        CUtlVector<unsigned int,CUtlMemoryFixedGrowable<unsigned int,32,int>>::InsertBefore(
          this: v4,
          elem: m_Size,
          src: (const unsigned int *)&list);
      v11 = v4->m_Size;
      v12 = *(CUniqueVertexList **)(v8 + 4);
      v13 = 0;
      list = v12;
      if ( v11 <= 0 )
        goto LABEL_17;
      v14 = v4->m_Memory.m_pMemory;
      while ( (CUniqueVertexList *)*v14 != v12 )
      {
        ++v13;
        ++v14;
        if ( v13 >= v11 )
          goto LABEL_17;
      }
      if ( v13 == -1 )
LABEL_17:
        CUtlVector<unsigned int,CUtlMemoryFixedGrowable<unsigned int,32,int>>::InsertBefore(
          this: v4,
          elem: v11,
          src: (const unsigned int *)&list);
      if ( ++nVertex >= nTriCount )
        break;
      this = v17;
      v3 = v16;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00575110
// Name: public: void CMeshVisit::CollapseEdge(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMeshVisit::CollapseEdge(CMeshVisit *this, unsigned int nCollapse)
{
  CQEMEdge *v3; // eax
  bool v4; // zf
  unsigned int v5; // ebx
  unsigned int v6; // edi
  float m_flInterp; // xmm0_4
  CQuadricError *m_pMemory; // eax
  float *m_coefficients; // edx
  int v10; // ecx
  float m_flIntegrationPenalty; // xmm0_4
  CQuadricError *v12; // eax
  float v13; // xmm1_4
  float *v14; // eax
  int m_Size; // edx
  int v16; // eax
  int v17; // ecx
  CVertVisit *v18; // edi
  int v19; // ecx
  int v20; // edx
  vertex_triangle_t *v21; // ecx
  unsigned int v22; // edi
  unsigned int nV2; // edx
  unsigned int nV1; // ecx
  int v25; // edi
  unsigned int v26; // edi
  unsigned __int8 *v27; // ebx
  unsigned int *v28; // edx
  int *v29; // ecx
  CVertVisit *v30; // edi
  int v31; // edx
  unsigned int v32; // edi
  int *v33; // eax
  int v34; // ecx
  int v35; // edx
  int v36; // edi
  CVertVisit *v37; // edx
  signed int v38; // eax
  int v39; // ecx
  CVertVisit *v40; // edi
  vertex_triangle_t *v41; // edx
  int v42; // eax
  int v43; // ebx
  CUtlMemory<ResourceEntryInfo,int> *v44; // edi
  int m_nAllocationCount; // eax
  ResourceEntryInfo *v46; // ecx
  int v47; // eax
  ResourceEntryInfo *v48; // ebx
  CVertVisit *v49; // edx
  int v50; // edx
  float *m_pVertexBase; // ecx
  float flLerp; // xmm0_4
  unsigned int v53; // edx
  unsigned int *v54; // eax
  unsigned int *v55; // eax
  CUniqueVertexList vertIndex; // [esp+14h] [ebp-15Ch] BYREF
  CUtlVectorFixedGrowable<unsigned int,32> removeList; // [esp+ACh] [ebp-C4h] BYREF
  int num; // [esp+144h] [ebp-2Ch]
  float flInterp; // [esp+148h] [ebp-28h]
  unsigned int v60; // [esp+14Ch] [ebp-24h]
  unsigned int v61; // [esp+150h] [ebp-20h]
  int v62; // [esp+154h] [ebp-1Ch]
  unsigned int nVertex; // [esp+158h] [ebp-18h]
  unsigned int nVertexRemove; // [esp+15Ch] [ebp-14h]
  vertex_triangle_t *tri; // [esp+160h] [ebp-10h]
  int nTrianglesRemoved; // [esp+164h] [ebp-Ch]
  int nRemoveCount; // [esp+168h] [ebp-8h]
  int j; // [esp+16Ch] [ebp-4h]
  unsigned int nVertexKeep; // [esp+178h] [ebp+8h]

  this->m_edgeList.m_Memory.m_pMemory[nCollapse].m_bCollapsed = true;
  v3 = &this->m_edgeList.m_Memory.m_pMemory[nCollapse];
  v4 = v3->m_nBestIndex == 1;
  v5 = v3->m_nVert[0];
  v6 = v3->m_nVert[1];
  m_flInterp = v3->m_flInterp;
  v60 = v5;
  v61 = v6;
  flInterp = m_flInterp;
  nVertexKeep = v5;
  nVertexRemove = v6;
  if ( v4 )
  {
    nVertexRemove = v5;
    nVertexKeep = v6;
    v5 = v6;
    v6 = nVertexRemove;
  }
  m_pMemory = this->m_errorVert.m_Memory.m_pMemory;
  m_coefficients = m_pMemory[v6].m_coefficients;
  v10 = v5;
  m_pMemory[v10].m_coefficients[0] = *m_coefficients + m_pMemory[v5].m_coefficients[0];
  m_pMemory[v10].m_coefficients[1] = m_coefficients[1] + m_pMemory[v5].m_coefficients[1];
  m_pMemory[v10].m_coefficients[2] = m_coefficients[2] + m_pMemory[v5].m_coefficients[2];
  m_pMemory[v10].m_coefficients[3] = m_coefficients[3] + m_pMemory[v5].m_coefficients[3];
  m_pMemory[v10].m_coefficients[4] = m_coefficients[4] + m_pMemory[v5].m_coefficients[4];
  m_pMemory[v10].m_coefficients[5] = m_coefficients[5] + m_pMemory[v5].m_coefficients[5];
  m_pMemory[v10].m_coefficients[6] = m_coefficients[6] + m_pMemory[v5].m_coefficients[6];
  m_pMemory[v10].m_coefficients[7] = m_coefficients[7] + m_pMemory[v5].m_coefficients[7];
  m_pMemory[v10].m_coefficients[8] = m_coefficients[8] + m_pMemory[v5].m_coefficients[8];
  m_pMemory[v10].m_coefficients[9] = m_coefficients[9] + m_pMemory[v5].m_coefficients[9];
  m_flIntegrationPenalty = this->m_flIntegrationPenalty;
  v12 = this->m_errorVert.m_Memory.m_pMemory;
  v13 = v12[v5].m_coefficients[0];
  v14 = v12[v5].m_coefficients;
  *v14 = v13 * m_flIntegrationPenalty;
  v14[1] = v14[1] * m_flIntegrationPenalty;
  v14[2] = v14[2] * m_flIntegrationPenalty;
  v14[3] = v14[3] * m_flIntegrationPenalty;
  v14[4] = v14[4] * m_flIntegrationPenalty;
  v14[5] = v14[5] * m_flIntegrationPenalty;
  v14[6] = v14[6] * m_flIntegrationPenalty;
  v14[7] = v14[7] * m_flIntegrationPenalty;
  v14[8] = v14[8] * m_flIntegrationPenalty;
  v14[9] = v14[9] * m_flIntegrationPenalty;
  vertIndex.m_Memory.m_nMallocGrowSize = 0;
  vertIndex.m_Size = 0;
  vertIndex.m_Memory.m_pMemory = vertIndex.m_Memory.m_pFixedMemory;
  vertIndex.m_Memory.m_nAllocationCount = 32;
  vertIndex.m_Memory.m_nGrowSize = -1;
  vertIndex.m_pElements = vertIndex.m_Memory.m_pFixedMemory;
  CMeshVisit::Get1Ring(this, list: &vertIndex, nVertex: v6);
  removeList.m_Memory.m_pMemory = removeList.m_Memory.m_pFixedMemory;
  m_Size = vertIndex.m_Size;
  v16 = 0;
  removeList.m_pElements = removeList.m_Memory.m_pFixedMemory;
  v17 = 0;
  nTrianglesRemoved = 0;
  removeList.m_Memory.m_nAllocationCount = 32;
  removeList.m_Memory.m_nGrowSize = -1;
  removeList.m_Memory.m_nMallocGrowSize = 0;
  removeList.m_Size = 0;
  tri = nullptr;
  if ( vertIndex.m_Size > 0 )
  {
    while ( 1 )
    {
      v18 = this->m_vertList.m_Memory.m_pMemory;
      nVertex = vertIndex.m_Memory.m_pMemory[v17];
      v19 = 0;
      v20 = 20 * nVertex;
      j = 0;
      nRemoveCount = 20 * nVertex;
      if ( v18[nVertex].m_triangles.m_Size > 0 )
        break;
LABEL_26:
      nTrianglesRemoved += v16;
      v31 = v16 - 1;
      for ( j = v16 - 1; v31 >= 0; j = v31 )
      {
        v32 = removeList.m_Memory.m_pMemory[v31];
        v33 = (int *)((char *)this->m_vertList.m_Memory.m_pMemory + nRemoveCount);
        v34 = v33[3];
        if ( v34 > 0 )
        {
          if ( v32 != v34 - 1 )
          {
            v35 = *v33;
            *(_DWORD *)(v35 + 8 * v32) = *(_DWORD *)(*v33 + 8 * v34 - 8);
            *(_DWORD *)(v35 + 8 * v32 + 4) = *(_DWORD *)(v35 + 8 * v34 - 4);
            v31 = j;
          }
          v5 = nVertexKeep;
          --v33[3];
        }
        --v31;
      }
      m_Size = vertIndex.m_Size;
      v17 = (int)&tri->nV1 + 1;
      v16 = 0;
      removeList.m_Size = 0;
      tri = (vertex_triangle_t *)v17;
      if ( v17 >= vertIndex.m_Size )
        goto LABEL_33;
    }
    while ( 1 )
    {
      v21 = &(*(vertex_triangle_t **)((char *)&this->m_vertList.m_Memory.m_pMemory->m_triangles.m_Memory.m_pMemory + v20))[v19];
      v22 = nVertexRemove;
      if ( v21->nV1 == nVertexRemove )
        break;
      if ( v21->nV2 == nVertexRemove )
        goto LABEL_9;
LABEL_25:
      v30 = this->m_vertList.m_Memory.m_pMemory;
      v19 = j + 1;
      j = v19;
      if ( v19 >= *(int *)((char *)&v30->m_triangles.m_Size + v20) )
        goto LABEL_26;
    }
    v21->nV1 = v5;
    v16 = removeList.m_Size;
LABEL_9:
    if ( v21->nV2 == v22 )
    {
      v21->nV2 = v5;
      v16 = removeList.m_Size;
    }
    nV2 = v21->nV2;
    nV1 = v21->nV1;
    if ( nV1 == nV2 || nV1 == nVertex || nV2 == nVertex )
    {
      v25 = v16;
      v62 = v16;
      if ( v16 + 1 > removeList.m_Memory.m_nAllocationCount )
      {
        num = v16 - removeList.m_Memory.m_nAllocationCount + 1;
        if ( removeList.m_Memory.m_nGrowSize < 0 )
        {
          removeList.m_Memory.m_nGrowSize = removeList.m_Memory.m_nMallocGrowSize;
          if ( removeList.m_Memory.m_nAllocationCount != 0 )
          {
            v26 = 4 * removeList.m_Memory.m_nAllocationCount;
            v27 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(
                                       this: _g_pMemAlloc,
                                       a2: 4 * removeList.m_Memory.m_nAllocationCount);
            memcpy(dst: v27, src: (unsigned __int8 *)removeList.m_Memory.m_pMemory, count: v26);
            v25 = v62;
            removeList.m_Memory.m_pMemory = (unsigned int *)v27;
            v5 = nVertexKeep;
          }
          else
          {
            removeList.m_Memory.m_pMemory = nullptr;
          }
        }
        CUtlMemory<HemiLightData_t *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&removeList, num);
        v16 = removeList.m_Size;
      }
      v28 = removeList.m_Memory.m_pMemory;
      removeList.m_Size = ++v16;
      removeList.m_pElements = removeList.m_Memory.m_pMemory;
      if ( v16 - v25 - 1 > 0 )
      {
        _V_memmove(
          dest: &removeList.m_Memory.m_pMemory[v25 + 1],
          src: &removeList.m_Memory.m_pMemory[v25],
          count: 4 * (v16 - v25 - 1));
        v16 = removeList.m_Size;
        v28 = removeList.m_Memory.m_pMemory;
      }
      v29 = (int *)&v28[v25];
      if ( v29 != nullptr )
      {
        *v29 = j;
        v16 = removeList.m_Size;
      }
    }
    v20 = nRemoveCount;
    goto LABEL_25;
  }
LABEL_33:
  v36 = 0;
  if ( m_Size > 0 )
  {
    do
      CMeshVisit::RemapEdge(this, nVertexRemove, nVertexConnect: vertIndex.m_Memory.m_pMemory[v36++], nVertexKeep: v5);
    while ( v36 < vertIndex.m_Size );
  }
  v37 = this->m_vertList.m_Memory.m_pMemory;
  v38 = 0;
  v39 = 20 * nVertexRemove;
  nRemoveCount = 0;
  nVertex = 0;
  j = 20 * nVertexRemove;
  if ( v37[nVertexRemove].m_triangles.m_Size > 0 )
  {
    do
    {
      v40 = this->m_vertList.m_Memory.m_pMemory;
      v41 = &(*(vertex_triangle_t **)((char *)&v40->m_triangles.m_Memory.m_pMemory + v39))[v38];
      tri = v41;
      if ( v41->nV1 == v5 || v41->nV2 == v5 )
      {
        ++nRemoveCount;
      }
      else
      {
        v42 = v5;
        v43 = v40[v5].m_triangles.m_Size;
        v44 = (CUtlMemory<ResourceEntryInfo,int> *)&v40[v42];
        m_nAllocationCount = v44->m_nAllocationCount;
        if ( v43 + 1 > m_nAllocationCount )
        {
          CUtlMemory<CacheOptimizedKDNode,int>::Grow(this: v44, num: v43 - m_nAllocationCount + 1);
          v41 = tri;
        }
        ++v44[1].m_pMemory;
        v46 = v44->m_pMemory;
        v47 = (int)v44[1].m_pMemory - v43 - 1;
        v44[1].m_nAllocationCount = (int)v44->m_pMemory;
        if ( v47 > 0 )
        {
          _V_memmove(dest: &v46[v43 + 1], src: &v46[v43], count: 8 * v47);
          v41 = tri;
        }
        v48 = &v44->m_pMemory[v43];
        if ( v48 != nullptr )
        {
          v48->eType = v41->nV1;
          v48->resData = v41->nV2;
        }
        v5 = nVertexKeep;
        v39 = j;
      }
      v49 = this->m_vertList.m_Memory.m_pMemory;
      v38 = nVertex + 1;
      nVertex = v38;
    }
    while ( v38 < *(int *)((char *)&v49->m_triangles.m_Size + v39) );
  }
  v50 = nRemoveCount + nTrianglesRemoved;
  *(int *)((char *)&this->m_vertList.m_Memory.m_pMemory->m_triangles.m_Size + v39) = 0;
  nTrianglesRemoved = v50;
  m_pVertexBase = this->m_pVertexBase;
  flLerp = flInterp;
  v53 = (int)(((unsigned __int64)(1431655765LL * v50) >> 32) - v50) >> 1;
  this->m_nTriangleCount += v53 + (v53 >> 31);
  LerpVertex(
    pOutput: &m_pVertexBase[v5 * this->m_nVertexStrideFloats],
    pLeft: &m_pVertexBase[v60 * this->m_nVertexStrideFloats],
    pRight: &m_pVertexBase[v61 * this->m_nVertexStrideFloats],
    flLerp,
    nFloats: this->m_nVertexStrideFloats);
  ++this->m_nCollapseIndex;
  v54 = removeList.m_Memory.m_pMemory;
  removeList.m_Size = 0;
  if ( removeList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( removeList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: removeList.m_Memory.m_pMemory);
      v54 = nullptr;
      removeList.m_Memory.m_pMemory = nullptr;
    }
    removeList.m_Memory.m_nAllocationCount = 0;
  }
  removeList.m_pElements = v54;
  if ( removeList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v54 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v54);
      removeList.m_Memory.m_pMemory = nullptr;
    }
    removeList.m_Memory.m_nAllocationCount = 0;
  }
  v55 = vertIndex.m_Memory.m_pMemory;
  vertIndex.m_Size = 0;
  if ( vertIndex.m_Memory.m_nGrowSize >= 0 )
  {
    if ( vertIndex.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vertIndex.m_Memory.m_pMemory);
      v55 = nullptr;
      vertIndex.m_Memory.m_pMemory = nullptr;
    }
    vertIndex.m_Memory.m_nAllocationCount = 0;
  }
  vertIndex.m_pElements = v55;
  if ( vertIndex.m_Memory.m_nGrowSize >= 0 && v55 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v55);
}

//------------------------------------------------------------------------------
// Address: 0x00575710
// Name: public: void CMeshVisit::ComputeVertListError(float,float,float,struct mesh_simplifyweights_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMeshVisit::ComputeVertListError(
        CMeshVisit *this,
        float flOpenEdgePenalty,
        float flMinArea,
        float flMaxArea,
        const mesh_simplifyweights_t *pWeights)
{
  CUtlVector<CQuadricError,CUtlMemory<CQuadricError,int> > *p_m_errorVert; // ebx
  int v7; // ecx
  int v8; // edx
  _QWORD *v9; // eax
  CVertVisit *m_pMemory; // eax
  vertex_triangle_t *v11; // edx
  signed int nV1; // edi
  bool v13; // cc
  int v14; // edx
  int v15; // eax
  int v16; // eax
  unsigned int v17; // eax
  int v18; // eax
  float *v19; // ecx
  __int64 v20; // xmm0_8
  int v21; // edx
  int v22; // eax
  int v23; // edx
  float v24; // xmm2_4
  float v25; // xmm3_4
  float v26; // xmm5_4
  float *v27; // eax
  float v28; // xmm7_4
  float v29; // xmm2_4
  float v30; // xmm1_4
  float v31; // xmm3_4
  float v32; // xmm4_4
  float v33; // xmm2_4
  float v34; // xmm1_4
  float *m_pVertexBase; // ecx
  int v36; // edx
  int m_nVertexStrideFloats; // ebx
  int v38; // eax
  float v39; // xmm1_4
  int v40; // ebx
  float v41; // xmm3_4
  float v42; // xmm0_4
  float v43; // xmm2_4
  float v44; // xmm4_4
  float v45; // xmm5_4
  float *v46; // edi
  double v47; // st7
  float v48; // xmm7_4
  float v49; // xmm0_4
  float v50; // xmm4_4
  float v51; // xmm1_4
  float v52; // xmm7_4
  float v53; // xmm2_4
  float v54; // xmm5_4
  float v55; // xmm6_4
  float v56; // xmm3_4
  float v57; // xmm4_4
  float v58; // xmm3_4
  float v59; // xmm1_4
  float v60; // xmm7_4
  float v61; // xmm4_4
  float v62; // xmm1_4
  float v63; // xmm0_4
  unsigned int v64; // edx
  float v65; // xmm0_4
  float *v66; // eax
  CQEMEdge *v67; // edi
  float m_flCurrentError; // xmm0_4
  int m_nInputVertCount; // [esp-4h] [ebp-DCh]
  float errorThisEdge_4; // [esp+1Ch] [ebp-BCh]
  float errorThisEdge_12; // [esp+24h] [ebp-B4h]
  float errorThisEdge_16; // [esp+28h] [ebp-B0h]
  float errorThisEdge_24; // [esp+30h] [ebp-A8h]
  float errorThisTri; // [esp+40h] [ebp-98h]
  float errorThisTri_12; // [esp+4Ch] [ebp-8Ch]
  float errorThisTri_24; // [esp+58h] [ebp-80h]
  __int64 v1; // [esp+74h] [ebp-64h]
  float v1_8; // [esp+7Ch] [ebp-5Ch]
  __int64 v2; // [esp+80h] [ebp-58h]
  float v2_8; // [esp+88h] [ebp-50h]
  edge_hash_t dataRecord; // [esp+8Ch] [ebp-4Ch] BYREF
  Vector vec; // [esp+98h] [ebp-40h] BYREF
  Vector vPlaneNormal; // [esp+A4h] [ebp-34h] BYREF
  edge_queue_entry_t element; // [esp+B0h] [ebp-28h] BYREF
  Vector v0; // [esp+B8h] [ebp-20h]
  int j; // [esp+C4h] [ebp-14h]
  int v87; // [esp+C8h] [ebp-10h]
  unsigned int v88; // [esp+CCh] [ebp-Ch]
  int i; // [esp+D0h] [ebp-8h]
  float flArea; // [esp+D4h] [ebp-4h]
  int savedregs; // [esp+D8h] [ebp+0h] BYREF
  int flMinAreaa; // [esp+E4h] [ebp+Ch]
  const mesh_simplifyweights_t *pWeightsa; // [esp+ECh] [ebp+14h]

  p_m_errorVert = &this->m_errorVert;
  m_nInputVertCount = this->m_nInputVertCount;
  this->m_errorVert.m_Size = 0;
  CUtlVector<CQuadricError,CUtlMemory<CQuadricError,int>>::InsertMultipleBefore(
    this: &this->m_errorVert,
    elem: 0,
    num: m_nInputVertCount);
  if ( pWeights != nullptr && pWeights->m_nVertexCount != this->m_nInputVertCount )
    pWeights = nullptr;
  v7 = 0;
  i = 0;
  if ( this->m_nInputVertCount > 0 )
  {
    v8 = 0;
    v87 = 0;
    v88 = 0;
    do
    {
      v9 = (_QWORD *)((char *)p_m_errorVert->m_Memory.m_pMemory->m_coefficients + v8);
      *v9 = 0;
      v9[1] = 0;
      v9[2] = 0;
      v9[3] = 0;
      v9[4] = 0;
      m_pMemory = this->m_vertList.m_Memory.m_pMemory;
      j = 0;
      if ( m_pMemory[v88 / 0x14].m_triangles.m_Size > 0 )
      {
        dataRecord.m_pSharedEdge = nullptr;
        do
        {
          v11 = this->m_vertList.m_Memory.m_pMemory[v88 / 0x14].m_triangles.m_Memory.m_pMemory;
          nV1 = v11[j].nV1;
          flArea = *(float *)&v11[j].nV2;
          dataRecord.m_nV0 = v7;
          v13 = v7 <= nV1;
          if ( v7 < nV1 || (dataRecord.m_nV0 = nV1, dataRecord.m_nV1 = v7, v7 <= nV1) )
          {
            dataRecord.m_nV1 = nV1;
            v13 = v7 <= nV1;
          }
          v14 = v7;
          if ( v13 )
          {
            v14 = nV1;
            v15 = v7;
          }
          else
          {
            v15 = nV1;
          }
          v16 = v14 ^ __ROL4__(v15, 16);
          v17 = CUtlScalarHash<edge_hash_t,CDefaultHash32>::Find(
                  this: &this->m_edgeHash,
                  uiKey: v16 != -1 ? v16 : 0,
                  &dataRecord);
          if ( v17 == -1 || this->m_edgeHash.m_pData[v17].m_Data.m_pSharedEdge->m_nReferences >= 2 )
          {
            m_pVertexBase = this->m_pVertexBase;
            v36 = LODWORD(flArea) * this->m_nVertexStrideFloats;
            m_nVertexStrideFloats = this->m_nVertexStrideFloats;
            v38 = i * m_nVertexStrideFloats;
            v39 = m_pVertexBase[v36 + 2] - m_pVertexBase[i * m_nVertexStrideFloats + 2];
            v40 = nV1 * m_nVertexStrideFloats;
            v41 = m_pVertexBase[v36 + 1] - m_pVertexBase[v38 + 1];
            v42 = m_pVertexBase[v40 + 1] - m_pVertexBase[v38 + 1];
            v43 = m_pVertexBase[v40 + 2] - m_pVertexBase[v38 + 2];
            v44 = m_pVertexBase[v40] - m_pVertexBase[v38];
            v45 = m_pVertexBase[v36] - m_pVertexBase[v38];
            v46 = &m_pVertexBase[v38];
            vec.x = (float)(v41 * v43) - (float)(v39 * v42);
            vec.y = (float)(v39 * v44) - (float)(v43 * v45);
            vec.z = (float)(v42 * v45) - (float)(v41 * v44);
            v47 = VectorNormalize(&vec) * 0.5;
            flArea = v47;
            if ( flMinArea <= v47 )
            {
              v48 = flArea;
            }
            else
            {
              v48 = flMinArea;
              flArea = flMinArea;
            }
            v27 = (float *)((char *)this->m_errorVert.m_Memory.m_pMemory->m_coefficients + v87);
            LODWORD(v49) = COERCE_UNSIGNED_INT((float)((float)(*v46 * vec.x) + (float)(vec.y * v46[1])) + (float)(v46[2] * vec.z))
                         ^ _mask__NegFloat_;
            errorThisTri = (float)(vec.x * vec.x) * v48;
            v50 = v48 * 2.0;
            errorThisTri_12 = (float)(vec.x * v49) * (float)(v48 * 2.0);
            v51 = (float)((float)(vec.y * vec.y) * v48) + v27[4];
            errorThisTri_24 = (float)(vec.y * v49) * (float)(v48 * 2.0);
            p_m_errorVert = &this->m_errorVert;
            v52 = (float)(vec.z * vec.y) * (float)(v48 * 2.0);
            v53 = vec.z * vec.z;
            v54 = (float)((float)(vec.y * vec.x) * v50) + v27[1];
            v55 = (float)((float)(vec.z * vec.x) * v50) + v27[2];
            v56 = (float)(vec.z * v49) * v50;
            v57 = *v27 + errorThisTri;
            v58 = v56 + v27[8];
            v27[4] = v51;
            v59 = v52 + v27[5];
            v60 = flArea;
            *v27 = v57;
            v61 = errorThisTri_12 + v27[3];
            v27[5] = v59;
            v62 = errorThisTri_24 + v27[6];
            v63 = (float)((float)(v49 * v49) * v60) + v27[9];
            v33 = (float)(v53 * v60) + v27[7];
            v27[1] = v54;
            v27[2] = v55;
            v27[3] = v61;
            v27[6] = v62;
            v27[8] = v58;
            v27[9] = v63;
          }
          else
          {
            v18 = this->m_nVertexStrideFloats;
            v19 = this->m_pVertexBase;
            v20 = *(_QWORD *)&v19[i * v18];
            v0.z = v19[i * v18 + 2];
            v21 = v18;
            v22 = LODWORD(flArea) * v18;
            v23 = nV1 * v21;
            *(_QWORD *)&v0.x = v20;
            v1 = *(_QWORD *)&v19[v23];
            v2 = *(_QWORD *)&v19[v22];
            v2_8 = v19[v22 + 2];
            v1_8 = v19[v23 + 2];
            *(float *)&element.m_nEdgeIndex = v1_8 - v0.z;
            v24 = (float)((float)(*((float *)&v1 + 1) - *((float *)&v20 + 1)) * (float)(*(float *)&v2 - *(float *)&v20))
                - (float)((float)(*((float *)&v2 + 1) - *((float *)&v20 + 1)) * (float)(*(float *)&v1 - *(float *)&v20));
            v25 = (float)((float)(*((float *)&v2 + 1) - *((float *)&v20 + 1)) * (float)(v1_8 - v0.z))
                - (float)((float)(v2_8 - v0.z) * (float)(*((float *)&v1 + 1) - *((float *)&v20 + 1)));
            *(float *)&v20 = (float)((float)(v2_8 - v0.z) * (float)(*(float *)&v1 - *(float *)&v20))
                           - (float)((float)(v1_8 - v0.z) * (float)(*(float *)&v2 - *(float *)&v20));
            vPlaneNormal.x = (float)((float)(*((float *)&v1 + 1) - v0.y) * v24)
                           - (float)((float)(v1_8 - v0.z) * *(float *)&v20);
            vPlaneNormal.y = (float)((float)(v1_8 - v0.z) * v25) - (float)(v24 * (float)(*(float *)&v1 - v0.x));
            vPlaneNormal.z = (float)(*(float *)&v20 * (float)(*(float *)&v1 - v0.x))
                           - (float)((float)(*((float *)&v1 + 1) - v0.y) * v25);
            flArea = VectorNormalize(vec: &vPlaneNormal) * 0.5 * flOpenEdgePenalty;
            v26 = flArea;
            v27 = (float *)((char *)p_m_errorVert->m_Memory.m_pMemory->m_coefficients + v87);
            LODWORD(v20) = COERCE_UNSIGNED_INT(
                             (float)((float)(vPlaneNormal.y * v0.y) + (float)(vPlaneNormal.x * v0.x))
                           + (float)(vPlaneNormal.z * v0.z))
                         ^ _mask__NegFloat_;
            errorThisEdge_4 = (float)(vPlaneNormal.y * vPlaneNormal.x) * (float)(flArea * 2.0);
            errorThisEdge_12 = (float)(vPlaneNormal.x * *(float *)&v20) * (float)(flArea * 2.0);
            errorThisEdge_16 = (float)(vPlaneNormal.y * vPlaneNormal.y) * flArea;
            v28 = (float)(vPlaneNormal.z * vPlaneNormal.x) * (float)(flArea * 2.0);
            v29 = (float)(vPlaneNormal.z * vPlaneNormal.y) * (float)(flArea * 2.0);
            errorThisEdge_24 = (float)(vPlaneNormal.y * *(float *)&v20) * (float)(flArea * 2.0);
            v30 = vPlaneNormal.z * vPlaneNormal.z;
            v31 = (float)(vPlaneNormal.z * *(float *)&v20) * (float)(flArea * 2.0);
            *v27 = *v27 + (float)((float)(vPlaneNormal.x * vPlaneNormal.x) * flArea);
            v27[1] = v27[1] + errorThisEdge_4;
            v27[2] = v27[2] + v28;
            v27[3] = v27[3] + errorThisEdge_12;
            v27[4] = v27[4] + errorThisEdge_16;
            v32 = v27[5] + v29;
            v27[6] = v27[6] + errorThisEdge_24;
            v33 = v27[7] + (float)(v30 * v26);
            v27[8] = v27[8] + v31;
            v34 = v27[9] + (float)((float)(*(float *)&v20 * *(float *)&v20) * v26);
            v27[5] = v32;
            v27[9] = v34;
          }
          v64 = v88;
          v27[7] = v33;
          v13 = j + 1 < *(int *)((char *)&this->m_vertList.m_Memory.m_pMemory->m_triangles.m_Size + v64);
          v7 = i;
          ++j;
        }
        while ( v13 );
        v8 = v87;
      }
      if ( pWeights != nullptr && pWeights->m_pVertexWeights != nullptr )
      {
        v65 = pWeights->m_pVertexWeights[v7];
        v66 = (float *)((char *)p_m_errorVert->m_Memory.m_pMemory->m_coefficients + v8);
        *v66 = *v66 * v65;
        v66[1] = v66[1] * v65;
        v66[2] = v66[2] * v65;
        v66[3] = v66[3] * v65;
        v66[4] = v66[4] * v65;
        v66[5] = v66[5] * v65;
        v66[6] = v66[6] * v65;
        v66[7] = v66[7] * v65;
        v66[8] = v66[8] * v65;
        v66[9] = v66[9] * v65;
      }
      v88 += 20;
      ++v7;
      v8 += 40;
      i = v7;
      v87 = v8;
    }
    while ( v7 < this->m_nInputVertCount );
  }
  if ( this->m_edgeList.m_Size > 0 )
  {
    pWeightsa = nullptr;
    flMinAreaa = this->m_edgeList.m_Size;
    do
    {
      v67 = (CQEMEdge *)((char *)pWeightsa + (unsigned int)this->m_edgeList.m_Memory.m_pMemory);
      CQEMEdge::UpdateError(
        this: v67,
        a2: COERCE_FLOAT(&savedregs),
        v0: (const Vector *)&this->m_pVertexBase[this->m_nVertexStrideFloats * v67->m_nVert[0]],
        v1: (const Vector *)&this->m_pVertexBase[this->m_nVertexStrideFloats * v67->m_nVert[1]],
        pVertError: p_m_errorVert->m_Memory.m_pMemory);
      m_flCurrentError = v67->m_flCurrentError;
      element.m_nEdgeIndex = v67 - this->m_edgeList.m_Memory.m_pMemory;
      element.m_flError = m_flCurrentError;
      CUtlPriorityQueue<edge_queue_entry_t,CDefUtlPriorityQueueLessFunc<edge_queue_entry_t>,CUtlMemory<edge_queue_entry_t,int>>::Insert(
        this: &this->m_edgeQueue,
        &element);
      pWeightsa = (const mesh_simplifyweights_t *)((char *)pWeightsa + 76);
      --flMinAreaa;
    }
    while ( flMinAreaa != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00575E20
// Name: public: int CMeshVisit::CountSharedVerts(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMeshVisit::CountSharedVerts(CMeshVisit *this, int nVert0, int nVert1)
{
  unsigned int *m_pMemory; // esi
  unsigned int *v5; // edi
  int v6; // edx
  int v7; // eax
  CUniqueVertexList vertIndex0; // [esp+Ch] [ebp-130h] BYREF
  CUniqueVertexList vertIndex1; // [esp+A4h] [ebp-98h] BYREF
  int nSharedCount; // [esp+144h] [ebp+8h]

  vertIndex0.m_Memory.m_pMemory = vertIndex0.m_Memory.m_pFixedMemory;
  vertIndex0.m_pElements = vertIndex0.m_Memory.m_pFixedMemory;
  vertIndex0.m_Memory.m_nGrowSize = -1;
  vertIndex1.m_Memory.m_nGrowSize = -1;
  vertIndex0.m_Memory.m_nAllocationCount = 32;
  vertIndex1.m_Memory.m_nAllocationCount = 32;
  vertIndex1.m_Memory.m_pMemory = vertIndex1.m_Memory.m_pFixedMemory;
  vertIndex0.m_Memory.m_nMallocGrowSize = 0;
  vertIndex0.m_Size = 0;
  vertIndex1.m_Memory.m_nMallocGrowSize = 0;
  vertIndex1.m_Size = 0;
  vertIndex1.m_pElements = vertIndex1.m_Memory.m_pFixedMemory;
  CMeshVisit::Get1Ring(this, list: &vertIndex0, nVertex: nVert0);
  CMeshVisit::Get1Ring(this, list: &vertIndex1, nVertex: nVert1);
  m_pMemory = vertIndex0.m_Memory.m_pMemory;
  v5 = vertIndex1.m_Memory.m_pMemory;
  v6 = 0;
  for ( nSharedCount = 0; v6 < vertIndex1.m_Size; ++v6 )
  {
    v7 = 0;
    if ( vertIndex0.m_Size > 0 )
    {
      while ( vertIndex0.m_Memory.m_pMemory[v7] != vertIndex1.m_Memory.m_pMemory[v6] )
      {
        if ( ++v7 >= vertIndex0.m_Size )
          goto LABEL_8;
      }
      if ( v7 != -1 )
        ++nSharedCount;
    }
LABEL_8:
    ;
  }
  vertIndex1.m_Size = 0;
  if ( vertIndex1.m_Memory.m_nGrowSize >= 0 )
  {
    if ( vertIndex1.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vertIndex1.m_Memory.m_pMemory);
      m_pMemory = vertIndex0.m_Memory.m_pMemory;
      v5 = nullptr;
      vertIndex1.m_Memory.m_pMemory = nullptr;
    }
    vertIndex1.m_Memory.m_nAllocationCount = 0;
  }
  vertIndex1.m_pElements = v5;
  if ( vertIndex1.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v5 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
      m_pMemory = vertIndex0.m_Memory.m_pMemory;
      vertIndex1.m_Memory.m_pMemory = nullptr;
    }
    vertIndex1.m_Memory.m_nAllocationCount = 0;
  }
  vertIndex0.m_Size = 0;
  if ( vertIndex0.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      m_pMemory = nullptr;
      vertIndex0.m_Memory.m_pMemory = nullptr;
    }
    vertIndex0.m_Memory.m_nAllocationCount = 0;
  }
  vertIndex0.m_pElements = m_pMemory;
  if ( vertIndex0.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  return nSharedCount;
}

//------------------------------------------------------------------------------
// Address: 0x00575FD0
// Name: public: bool CMeshVisit::IsValidCollapse(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMeshVisit::IsValidCollapse(CMeshVisit *this, int nMinEdge)
{
  int v4; // edi
  CQEMEdge *v5; // eax
  int v6; // ebx
  float z; // edx
  Vector vOptimal; // [esp+8h] [ebp-Ch] BYREF
  int nVert1; // [esp+1Ch] [ebp+8h]

  if ( nMinEdge < 0 )
    return true;
  v4 = nMinEdge;
  v5 = &this->m_edgeList.m_Memory.m_pMemory[nMinEdge];
  if ( v5->m_bNonManifold )
    return false;
  v6 = v5->m_nVert[0];
  nVert1 = v5->m_nVert[1];
  if ( CMeshVisit::CountSharedVerts(this, nVert0: v6, nVert1) > 2 )
    return false;
  z = this->m_edgeList.m_Memory.m_pMemory[v4].m_vOptimal.z;
  *(_QWORD *)&vOptimal.x = *(_QWORD *)&this->m_edgeList.m_Memory.m_pMemory[v4].m_vOptimal.x;
  vOptimal.z = z;
  return CMeshVisit::IsValidCollapseVertex(this, nVertCheck: v6, nVertOpposite: nVert1, vReplacePos: &vOptimal) != 0
      && CMeshVisit::IsValidCollapseVertex(this, nVertCheck: nVert1, nVertOpposite: v6, vReplacePos: &vOptimal) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x00576080
// Name: public: int CMeshVisit::FindMinErrorEdge(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMeshVisit::FindMinErrorEdge(CMeshVisit *this)
{
  edge_queue_entry_t *m_pMemory; // eax
  int m_nEdgeIndex; // esi
  CQEMEdge *v4; // ecx
  float entry; // [esp+Ch] [ebp-8h]

  if ( this->m_edgeQueue.m_heap.m_Size == 0 )
    return -1;
  while ( 1 )
  {
    m_pMemory = this->m_edgeQueue.m_heap.m_Memory.m_pMemory;
    m_nEdgeIndex = m_pMemory->m_nEdgeIndex;
    entry = m_pMemory->m_flError;
    CUtlPriorityQueue<edge_queue_entry_t,CDefUtlPriorityQueueLessFunc<edge_queue_entry_t>,CUtlMemory<edge_queue_entry_t,int>>::RemoveAtHead(this: &this->m_edgeQueue);
    v4 = &this->m_edgeList.m_Memory.m_pMemory[m_nEdgeIndex];
    if ( v4->m_flCurrentError == entry && !v4->m_bCollapsed && CMeshVisit::IsValidCollapse(this, nMinEdge: m_nEdgeIndex) )
      break;
    if ( this->m_edgeQueue.m_heap.m_Size == 0 )
      return -1;
  }
  return m_nEdgeIndex;
}

//------------------------------------------------------------------------------
// Address: 0x005760F0
// Name: public: void CMeshVisit::BuildFromMesh(class CMesh const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMeshVisit::BuildFromMesh(CMeshVisit *this, CMesh *input)
{
  int m_nIndexCount; // ecx
  int m_nVertexCount; // esi
  int v5; // edi
  int *v6; // esi
  IMemAlloc_vtbl *v7; // edx
  int v8; // eax
  int v9; // ecx
  bool v10; // zf
  CQEMEdge *m_pMemory; // edx
  CQEMEdge *v12; // eax
  unsigned int *m_pIndices; // ecx
  signed int v14; // edi
  signed int v15; // eax
  bool v16; // cc
  signed int v17; // ecx
  int v18; // eax
  unsigned int v19; // esi
  unsigned int v20; // eax
  int v21; // ecx
  int m_nAllocationCount; // eax
  CQEMEdge *v23; // edx
  int v24; // eax
  int v25; // ecx
  CQEMEdge *v26; // eax
  unsigned int m_nV0; // edx
  CQEMEdge *v28; // eax
  signed int m_nV1; // ecx
  CQEMEdge *m_pSharedEdge; // eax
  int v31; // eax
  CVertVisit *v32; // ecx
  int v33; // edi
  CUtlMemory<ResourceEntryInfo,int> *v34; // esi
  int v35; // eax
  ResourceEntryInfo *v36; // ecx
  int v37; // eax
  ResourceEntryInfo *v38; // edi
  unsigned int nV2; // eax
  const CMesh *v40; // edx
  int v41; // edi
  int v42; // eax
  float *v43; // ecx
  int v44; // eax
  float *v45; // esi
  unsigned int v46; // [esp-8h] [ebp-40h]
  edge_hash_t tmp; // [esp+8h] [ebp-30h] BYREF
  vertex_triangle_t tri; // [esp+14h] [ebp-24h]
  int nV1; // [esp+1Ch] [ebp-1Ch]
  int nInputIndexCount; // [esp+20h] [ebp-18h]
  int j; // [esp+24h] [ebp-14h]
  int m_Size; // [esp+28h] [ebp-10h]
  int v53; // [esp+2Ch] [ebp-Ch]
  int v54; // [esp+30h] [ebp-8h]
  int i; // [esp+34h] [ebp-4h]

  if ( CMesh::FindFirstAttributeOffset(this: input, nType: VERTEX_ELEMENT_POSITION) == 0 )
  {
    m_nIndexCount = input->m_nIndexCount;
    m_nVertexCount = input->m_nVertexCount;
    nInputIndexCount = m_nIndexCount;
    v5 = m_nIndexCount / 3;
    this->m_nTriangleCount = m_nIndexCount / 3;
    CUtlScalarHash<edge_hash_t,CDefaultHash32>::Init(this: &this->m_edgeHash, nBucketCount: 2 * m_nIndexCount);
    CUtlVector<cluster_portals_t,CUtlMemory<cluster_portals_t,int>>::RemoveAll(this: (CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *)&this->m_vertList);
    CUtlVector<CVertVisit,CUtlMemory<CVertVisit,int>>::InsertMultipleBefore(
      this: (CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *)&this->m_vertList,
      elem: this->m_vertList.m_Size,
      num: m_nVertexCount);
    if ( m_nVertexCount > 0 )
    {
      v54 = 0;
      v53 = m_nVertexCount;
      do
      {
        v6 = (int *)((char *)this->m_vertList.m_Memory.m_pMemory + v54);
        if ( v6[1] < 8 && v6[2] >= 0 )
        {
          v6[1] = 8;
          v7 = _g_pMemAlloc->__vftable;
          if ( *v6 != 0 )
            v8 = ((int (__stdcall *)(int, int))v7->Realloc_2)(a1: *v6, a2: 64);
          else
            v8 = ((int (__stdcall *)(int))v7->Alloc_2)(a1: 64);
          *v6 = v8;
        }
        v9 = *v6;
        v54 += 20;
        v10 = v53-- == 1;
        v6[4] = v9;
      }
      while ( !v10 );
    }
    if ( this->m_edgeList.m_Memory.m_nAllocationCount < 6 * v5 && this->m_edgeList.m_Memory.m_nGrowSize >= 0 )
    {
      m_pMemory = this->m_edgeList.m_Memory.m_pMemory;
      this->m_edgeList.m_Memory.m_nAllocationCount = 6 * v5;
      v46 = 456 * v5;
      if ( m_pMemory != nullptr )
        v12 = (CQEMEdge *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v46);
      else
        v12 = (CQEMEdge *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v46);
      this->m_edgeList.m_Memory.m_pMemory = v12;
    }
    v16 = nInputIndexCount <= 0;
    this->m_edgeList.m_pElements = this->m_edgeList.m_Memory.m_pMemory;
    i = 0;
    if ( !v16 )
    {
      do
      {
        v54 = 2;
        v53 = 4 * i;
        for ( j = 3; j != 0; --j )
        {
          m_pIndices = input->m_pIndices;
          v14 = *(unsigned int *)((char *)m_pIndices + v53);
          tmp.m_nV0 = v14;
          v15 = m_pIndices[i + (v54 - 1) % 3];
          nV1 = v15;
          v16 = v14 <= v15;
          if ( v14 < v15 || (tmp.m_nV0 = v15, tmp.m_nV1 = v14, v14 <= v15) )
          {
            tmp.m_nV1 = v15;
            v16 = v14 <= v15;
          }
          v17 = v14;
          if ( v16 )
          {
            v17 = v15;
            v15 = v14;
          }
          v18 = __ROL4__(v15, 16);
          v19 = (v17 ^ v18) != -1 ? v17 ^ v18 : 0;
          tmp.m_pSharedEdge = nullptr;
          v20 = CUtlScalarHash<edge_hash_t,CDefaultHash32>::Find(this: &this->m_edgeHash, uiKey: v19, dataRecord: &tmp);
          if ( v20 == -1 )
          {
            m_nAllocationCount = this->m_edgeList.m_Memory.m_nAllocationCount;
            m_Size = this->m_edgeList.m_Size;
            v21 = m_Size;
            if ( m_Size + 1 > m_nAllocationCount )
            {
              CUtlMemory<CQEMEdge,int>::Grow(this: &this->m_edgeList.m_Memory, num: m_Size - m_nAllocationCount + 1);
              v21 = m_Size;
            }
            ++this->m_edgeList.m_Size;
            v23 = this->m_edgeList.m_Memory.m_pMemory;
            v24 = this->m_edgeList.m_Size - v21 - 1;
            this->m_edgeList.m_pElements = this->m_edgeList.m_Memory.m_pMemory;
            if ( v24 > 0 )
            {
              _V_memmove(dest: &v23[v21 + 1], src: &v23[v21], count: 76 * v24);
              v21 = m_Size;
            }
            v25 = v21;
            v26 = &this->m_edgeList.m_Memory.m_pMemory[v25];
            if ( v26 != nullptr )
            {
              v26->m_flCurrentError = 0.0;
              *(_DWORD *)&v26->m_nBestIndex = 0;
              v26->m_nReferences = 0;
              v26->m_nVert[0] = 0;
              v26->m_nVert[1] = 0;
            }
            m_nV0 = tmp.m_nV0;
            v28 = &this->m_edgeList.m_Memory.m_pMemory[v25];
            m_nV1 = tmp.m_nV1;
            tmp.m_pSharedEdge = v28;
            if ( (int)tmp.m_nV0 >= (int)tmp.m_nV1 )
              m_nV0 = tmp.m_nV1;
            v28->m_nVert[0] = m_nV0;
            if ( (int)tmp.m_nV0 > m_nV1 )
              m_nV1 = tmp.m_nV0;
            v28->m_nVert[1] = m_nV1;
            v20 = CUtlScalarHash<edge_hash_t,CDefaultHash32>::Insert(this: &this->m_edgeHash, uiKey: v19, data: &tmp);
          }
          m_pSharedEdge = this->m_edgeHash.m_pData[v20].m_Data.m_pSharedEdge;
          ++m_pSharedEdge->m_nReferences;
          v31 = v14;
          v32 = this->m_vertList.m_Memory.m_pMemory;
          v33 = v32[v14].m_triangles.m_Size;
          v34 = (CUtlMemory<ResourceEntryInfo,int> *)&v32[v31];
          v35 = v34->m_nAllocationCount;
          tri.nV2 = input->m_pIndices[i + v54 % 3];
          if ( v33 + 1 > v35 )
            CUtlMemory<CacheOptimizedKDNode,int>::Grow(this: v34, num: v33 - v35 + 1);
          v36 = v34->m_pMemory;
          v37 = (int)++v34[1].m_pMemory - v33 - 1;
          v34[1].m_nAllocationCount = (int)v36;
          if ( v37 > 0 )
            _V_memmove(dest: &v36[v33 + 1], src: &v36[v33], count: 8 * v37);
          v38 = &v34->m_pMemory[v33];
          if ( v38 != nullptr )
          {
            nV2 = tri.nV2;
            v38->eType = nV1;
            v38->resData = nV2;
          }
          v53 += 4;
          ++v54;
        }
        i += 3;
      }
      while ( i < nInputIndexCount );
    }
    this->m_nInputVertCount = input->m_nVertexCount;
    v40 = input;
    v41 = v40->m_nVertexCount * v40->m_nVertexStrideFloats;
    this->m_vertData.m_Size = 0;
    if ( v41 != 0 )
    {
      v42 = this->m_vertData.m_Memory.m_nAllocationCount;
      if ( v41 > v42 )
      {
        CUtlMemory<HemiLightData_t *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&this->m_vertData, num: v41 - v42);
        v40 = input;
      }
      this->m_vertData.m_Size += v41;
      v43 = this->m_vertData.m_Memory.m_pMemory;
      v44 = this->m_vertData.m_Size - v41;
      this->m_vertData.m_pElements = v43;
      if ( v44 > 0 && v41 > 0 )
      {
        _V_memmove(dest: &v43[v41], src: v43, count: 4 * v44);
        v40 = input;
      }
    }
    v45 = this->m_vertData.m_Memory.m_pMemory;
    this->m_pVertexBase = v45;
    this->m_nVertexStrideFloats = v40->m_nVertexStrideFloats;
    _V_memcpy(dest: v45, src: v40->m_pVerts, count: 4 * v40->m_nVertexCount * v40->m_nVertexStrideFloats);
    this->m_nCollapseIndex = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00576470
// Name: void SimplifyMeshQEM2(class CMesh __near &,class CMesh const __near &,struct mesh_simplifyparams_t const __near &,struct mesh_simplifyweights_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SimplifyMeshQEM2(
        CMesh *meshOut,
        CMesh *input,
        const mesh_simplifyparams_t *params,
        const mesh_simplifyweights_t *pWeights)
{
  CMesh *v4; // ebx
  int m_nVertexCount; // eax
  signed int MinErrorEdge; // edi
  float i; // xmm0_4
  unsigned int *m_pMemory; // edx
  signed int m_Size; // edi
  signed int v10; // eax
  unsigned int v11; // ecx
  signed int j; // eax
  int k; // edi
  float *v14; // eax
  edge_queue_entry_t *v15; // eax
  CVertVisit *v16; // eax
  CQuadricError *v17; // eax
  CQEMEdge *v18; // eax
  CUtlVector<CQuadricError,CUtlMemory<CQuadricError,int> > errorEdge; // [esp+1Ch] [ebp-D4h] BYREF
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > indexOut; // [esp+30h] [ebp-C0h] BYREF
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > nIndexMap; // [esp+44h] [ebp-ACh] BYREF
  CMeshVisit visit; // [esp+58h] [ebp-98h] BYREF
  int nVertexCurrent; // [esp+E8h] [ebp-8h]
  int nInputVertCount; // [esp+ECh] [ebp-4h]
  int nOutputVertexCount; // [esp+100h] [ebp+10h]

  v4 = input;
  memset(&visit, 0, 96);
  visit.m_edgeQueue.m_LessFunc = CEdgeQueue::IsLowerPriority;
  memset(&visit.m_vertData, 0, sizeof(visit.m_vertData));
  CMeshVisit::BuildFromMesh(this: &visit, input);
  m_nVertexCount = input->m_nVertexCount;
  memset(&errorEdge, 0, sizeof(errorEdge));
  nInputVertCount = m_nVertexCount;
  CUtlVector<CQuadricError,CUtlMemory<CQuadricError,int>>::InsertMultipleBefore(
    this: &errorEdge,
    elem: 0,
    num: visit.m_edgeList.m_Size);
  visit.m_flIntegrationPenalty = params->m_flIntegrationPenalty;
  CMeshVisit::ComputeVertListError(
    this: &visit,
    flOpenEdgePenalty: params->m_flOpenEdgePenalty,
    flMinArea: 0.0,
    flMaxArea: 1.0,
    pWeights);
  MinErrorEdge = CMeshVisit::FindMinErrorEdge(this: &visit);
  nVertexCurrent = CountUsedVerts(
                     pIndexList: v4->m_pIndices,
                     nIndexCount: v4->m_nIndexCount,
                     nVertexCount: v4->m_nVertexCount);
  if ( MinErrorEdge >= 0 )
  {
    for ( i = visit.m_edgeList.m_Memory.m_pMemory[MinErrorEdge].m_flCurrentError;
          params->m_flMaxError > i
       || nVertexCurrent > params->m_nMaxVertexCount
       || visit.m_nTriangleCount > params->m_nMaxTriangleCount;
          i = visit.m_edgeList.m_Memory.m_pMemory[MinErrorEdge].m_flCurrentError )
    {
      CMeshVisit::CollapseEdge(this: &visit, nCollapse: MinErrorEdge);
      if ( --nVertexCurrent < 5 )
      {
        CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&errorEdge);
        CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&visit.m_vertData);
        CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&visit.m_edgeQueue);
        CUtlVector<cluster_portals_t,CUtlMemory<cluster_portals_t,int>>::~CUtlVector<cluster_portals_t,CUtlMemory<cluster_portals_t,int>>(this: (CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *)&visit.m_vertList);
        CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&visit.m_errorVert);
        free(pMem: visit.m_edgeHash.m_pData);
        CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&visit);
        return;
      }
      MinErrorEdge = CMeshVisit::FindMinErrorEdge(this: &visit);
      if ( MinErrorEdge < 0 )
        break;
    }
  }
  memset(&indexOut, 0, sizeof(indexOut));
  CMeshVisit::WriteMeshIndexList(this: &visit, (CUtlMemory<S3RGBA,int> *)&indexOut);
  memset(&nIndexMap, 0, sizeof(nIndexMap));
  CUtlVector<dfacebrushlist_t,CUtlMemory<dfacebrushlist_t,int>>::InsertMultipleBefore(
    this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&nIndexMap,
    elem: 0,
    num: nInputVertCount);
  m_pMemory = nIndexMap.m_Memory.m_pMemory;
  if ( nIndexMap.m_Size > 0 )
    memset(nIndexMap.m_Memory.m_pMemory, 0xFFu, 4 * nIndexMap.m_Size);
  m_Size = indexOut.m_Size;
  v10 = 0;
  nOutputVertexCount = 0;
  if ( indexOut.m_Size > 0 )
  {
    do
    {
      v11 = indexOut.m_Memory.m_pMemory[v10];
      if ( m_pMemory[v11] == -1 )
        m_pMemory[v11] = nOutputVertexCount++;
      indexOut.m_Memory.m_pMemory[v10++] = m_pMemory[v11];
    }
    while ( v10 < m_Size );
    v4 = input;
  }
  CMesh::AllocateMesh(
    this: meshOut,
    nVertexCount: nOutputVertexCount,
    nIndexCount: m_Size,
    nVertexStride: v4->m_nVertexStrideFloats,
    pAttributes: v4->m_pAttributes,
    nAtrributeCount: v4->m_nAttributeCount);
  for ( j = 0; j < m_Size; ++j )
    meshOut->m_pIndices[j] = indexOut.m_Memory.m_pMemory[j];
  for ( k = 0; k < nInputVertCount; ++k )
  {
    if ( nIndexMap.m_Memory.m_pMemory[k] != -1 )
      _V_memcpy(
        dest: &meshOut->m_pVerts[nIndexMap.m_Memory.m_pMemory[k] * meshOut->m_nVertexStrideFloats],
        src: &visit.m_pVertexBase[k * visit.m_nVertexStrideFloats],
        count: 4 * meshOut->m_nVertexStrideFloats);
  }
  if ( nIndexMap.m_Memory.m_nGrowSize >= 0 && nIndexMap.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: nIndexMap.m_Memory.m_pMemory);
  if ( indexOut.m_Memory.m_nGrowSize >= 0 && indexOut.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: indexOut.m_Memory.m_pMemory);
  if ( errorEdge.m_Memory.m_nGrowSize >= 0 && errorEdge.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: errorEdge.m_Memory.m_pMemory);
  v14 = visit.m_vertData.m_Memory.m_pMemory;
  visit.m_vertData.m_Size = 0;
  if ( visit.m_vertData.m_Memory.m_nGrowSize >= 0 )
  {
    if ( visit.m_vertData.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: visit.m_vertData.m_Memory.m_pMemory);
      v14 = nullptr;
      visit.m_vertData.m_Memory.m_pMemory = nullptr;
    }
    visit.m_vertData.m_Memory.m_nAllocationCount = 0;
  }
  visit.m_vertData.m_pElements = v14;
  if ( visit.m_vertData.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v14 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v14);
      visit.m_vertData.m_Memory.m_pMemory = nullptr;
    }
    visit.m_vertData.m_Memory.m_nAllocationCount = 0;
  }
  v15 = visit.m_edgeQueue.m_heap.m_Memory.m_pMemory;
  visit.m_edgeQueue.m_heap.m_Size = 0;
  if ( visit.m_edgeQueue.m_heap.m_Memory.m_nGrowSize >= 0 )
  {
    if ( visit.m_edgeQueue.m_heap.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: visit.m_edgeQueue.m_heap.m_Memory.m_pMemory);
      v15 = nullptr;
      visit.m_edgeQueue.m_heap.m_Memory.m_pMemory = nullptr;
    }
    visit.m_edgeQueue.m_heap.m_Memory.m_nAllocationCount = 0;
  }
  visit.m_edgeQueue.m_heap.m_pElements = v15;
  if ( visit.m_edgeQueue.m_heap.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v15 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v15);
      visit.m_edgeQueue.m_heap.m_Memory.m_pMemory = nullptr;
    }
    visit.m_edgeQueue.m_heap.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<cluster_portals_t,CUtlMemory<cluster_portals_t,int>>::RemoveAll(this: (CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int> >,int> > *)&visit.m_vertList);
  v16 = visit.m_vertList.m_Memory.m_pMemory;
  if ( visit.m_vertList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( visit.m_vertList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: visit.m_vertList.m_Memory.m_pMemory);
      v16 = nullptr;
      visit.m_vertList.m_Memory.m_pMemory = nullptr;
    }
    visit.m_vertList.m_Memory.m_nAllocationCount = 0;
  }
  visit.m_vertList.m_pElements = v16;
  if ( visit.m_vertList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v16 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v16);
      visit.m_vertList.m_Memory.m_pMemory = nullptr;
    }
    visit.m_vertList.m_Memory.m_nAllocationCount = 0;
  }
  v17 = visit.m_errorVert.m_Memory.m_pMemory;
  visit.m_errorVert.m_Size = 0;
  if ( visit.m_errorVert.m_Memory.m_nGrowSize >= 0 )
  {
    if ( visit.m_errorVert.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: visit.m_errorVert.m_Memory.m_pMemory);
      v17 = nullptr;
      visit.m_errorVert.m_Memory.m_pMemory = nullptr;
    }
    visit.m_errorVert.m_Memory.m_nAllocationCount = 0;
  }
  visit.m_errorVert.m_pElements = v17;
  if ( visit.m_errorVert.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v17 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v17);
      visit.m_errorVert.m_Memory.m_pMemory = nullptr;
    }
    visit.m_errorVert.m_Memory.m_nAllocationCount = 0;
  }
  free(pMem: visit.m_edgeHash.m_pData);
  v18 = visit.m_edgeList.m_Memory.m_pMemory;
  visit.m_edgeList.m_Size = 0;
  if ( visit.m_edgeList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( visit.m_edgeList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: visit.m_edgeList.m_Memory.m_pMemory);
      v18 = nullptr;
      visit.m_edgeList.m_Memory.m_pMemory = nullptr;
    }
    visit.m_edgeList.m_Memory.m_nAllocationCount = 0;
  }
  visit.m_edgeList.m_pElements = v18;
  if ( visit.m_edgeList.m_Memory.m_nGrowSize >= 0 && v18 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v18);
}

//------------------------------------------------------------------------------
// Address: 0x00576990
// Name: void SimplifyMesh(class CMesh __near &,class CMesh const __near &,struct mesh_simplifyparams_t const __near &,struct mesh_simplifyweights_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SimplifyMesh(
        CMesh *meshOut,
        CMesh *input,
        const mesh_simplifyparams_t *params,
        const mesh_simplifyweights_t *pWeights)
{
  SimplifyMeshQEM2(meshOut, input, params, pWeights);
}
