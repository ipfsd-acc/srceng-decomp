// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mdllib/mdllib_preparemodelps3.cpp
// Functions: 12
// ============================================================

#include "mdllib\mdllib_preparemodelps3.h"

//------------------------------------------------------------------------------
// Address: 0x100010C0
// Name: Helper_SwapOptimizedIndexBufferMarkup_forPs3
// Source: json
//------------------------------------------------------------------------------
void __thiscall Helper_SwapOptimizedIndexBufferMarkup_forPs3(OptimizedModel::OptimizedIndexBufferMarkupPs3_t *pMarkup)
{
  unsigned int v1; // edx
  _WORD *v2; // eax
  __int16 v3; // si
  __int16 v4; // si
  __int16 v5; // si
  __int16 v6; // si
  __int16 v7; // si
  __int16 v8; // si
  __int16 v9; // si
  __int16 v10; // si
  unsigned int v11; // eax
  _WORD *v12; // edx
  __int16 v13; // si
  __int16 m_numPartitions; // ax
  __int16 m_numIndicesTotal; // ax
  __int16 m_numVerticesTotal; // ax
  __int16 m_nEdgeDmaInputOffsetPerStripGroup; // ax
  __int16 m_nEdgeDmaInputSizePerStripGroup; // ax

  v1 = 0;
  if ( pMarkup->m_numPartitions != 0 )
  {
    v2 = (_WORD *)&pMarkup->m_partitions[0].m_nIoBufferSize + 1;
    do
    {
      v3 = *(v2 - 5);
      *(v2 - 5) = *(v2 - 4);
      *(v2 - 4) = v3;
      v4 = *(v2 - 3);
      *(v2 - 3) = *(v2 - 2);
      *(v2 - 2) = v4;
      v5 = *(v2 - 1);
      *(v2 - 1) = *v2;
      *v2 = v5;
      v6 = v2[1];
      v2[1] = v2[2];
      v2[2] = v6;
      v7 = v2[3];
      v2[3] = v2[4];
      v2[4] = v7;
      v8 = v2[5];
      v2[5] = v2[6];
      v2[6] = v8;
      v9 = v2[7];
      v2[7] = v2[8];
      v2[8] = v9;
      v10 = v2[9];
      v2[9] = v2[10];
      v2[10] = v10;
      ++v1;
      v2 += 16;
    }
    while ( v1 < pMarkup->m_numPartitions );
  }
  v11 = 0;
  v12 = (_WORD *)&pMarkup->m_uiHeaderCookie + 3;
  do
  {
    v13 = *((_WORD *)&pMarkup->m_uiHeaderCookie + v11);
    *((_WORD *)&pMarkup->m_uiHeaderCookie + v11) = *v12;
    *v12 = v13;
    ++v11;
    --v12;
  }
  while ( v11 < 2 );
  m_numPartitions = pMarkup->m_numPartitions;
  LOWORD(pMarkup->m_numPartitions) = HIWORD(pMarkup->m_numPartitions);
  HIWORD(pMarkup->m_numPartitions) = m_numPartitions;
  m_numIndicesTotal = pMarkup->m_numIndicesTotal;
  LOWORD(pMarkup->m_numIndicesTotal) = HIWORD(pMarkup->m_numIndicesTotal);
  HIWORD(pMarkup->m_numIndicesTotal) = m_numIndicesTotal;
  m_numVerticesTotal = pMarkup->m_numVerticesTotal;
  LOWORD(pMarkup->m_numVerticesTotal) = HIWORD(pMarkup->m_numVerticesTotal);
  HIWORD(pMarkup->m_numVerticesTotal) = m_numVerticesTotal;
  m_nEdgeDmaInputOffsetPerStripGroup = pMarkup->m_nEdgeDmaInputOffsetPerStripGroup;
  LOWORD(pMarkup->m_nEdgeDmaInputOffsetPerStripGroup) = HIWORD(pMarkup->m_nEdgeDmaInputOffsetPerStripGroup);
  HIWORD(pMarkup->m_nEdgeDmaInputOffsetPerStripGroup) = m_nEdgeDmaInputOffsetPerStripGroup;
  m_nEdgeDmaInputSizePerStripGroup = pMarkup->m_nEdgeDmaInputSizePerStripGroup;
  LOWORD(pMarkup->m_nEdgeDmaInputSizePerStripGroup) = HIWORD(pMarkup->m_nEdgeDmaInputSizePerStripGroup);
  HIWORD(pMarkup->m_nEdgeDmaInputSizePerStripGroup) = m_nEdgeDmaInputSizePerStripGroup;
}

//------------------------------------------------------------------------------
// Address: 0x100011D0
// Name: public: static bool CDefOps<unsigned char __near *>::LessFunc(unsigned char __near * const __near &,unsigned char __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CDefOps<unsigned char *>::LessFunc(unsigned __int8 *const *lhs, unsigned __int8 *const *rhs)
{
  return *lhs < *rhs;
}

//------------------------------------------------------------------------------
// Address: 0x100011F0
// Name: public: static bool CDefOps<struct ModelBatchKey_t>::LessFunc(struct ModelBatchKey_t const __near &,struct ModelBatchKey_t const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CDefOps<ModelBatchKey_t>::LessFunc(const ModelBatchKey_t *lhs, const ModelBatchKey_t *rhs)
{
  return _V_memcmp(m1: lhs, m2: rhs, count: 24) < 0;
}

//------------------------------------------------------------------------------
// Address: 0x10001210
// Name: public: void CUtlMemory<unsigned short,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<unsigned short,int>::Grow(CUtlMemory<unsigned short,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  unsigned __int16 *m_pMemory; // edx
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
        m_nAllocationCount = 16;
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
    v7 = 2 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (unsigned __int16 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (unsigned __int16 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100012A0
// Name: public: char const __near * studiohdr_t::pszName(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall studiohdr_t::pszName(studiohdr_t *this)
{
  int studiohdr2index; // eax
  int v2; // edx
  char *v3; // eax
  int v4; // ecx

  studiohdr2index = this->studiohdr2index;
  if ( studiohdr2index == 0 )
    return this->name;
  v2 = *(_DWORD *)&this->name[studiohdr2index + 8];
  v3 = (char *)this + studiohdr2index;
  if ( v2 == 0 || &v3[v2] == nullptr )
    return this->name;
  v4 = *((_DWORD *)v3 + 5);
  if ( v4 != 0 )
    return &v3[v4];
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100012D0
// Name: public: void CByteswap::SwapBufferToTargetEndian<unsigned short>(unsigned short __near *,unsigned short __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<unsigned short>(
        CByteswap *this,
        unsigned __int8 *outputBuffer,
        unsigned __int8 *inputBuffer,
        int count)
{
  int v4; // ebx
  unsigned __int8 *v5; // esi
  int v6; // edi
  unsigned __int8 v7; // dl
  unsigned __int8 v8; // cl

  v4 = count;
  if ( count > 0 && outputBuffer != nullptr )
  {
    v5 = inputBuffer;
    if ( inputBuffer == nullptr )
      v5 = outputBuffer;
    if ( (*(_BYTE *)this & 1) != 0 )
    {
      v6 = outputBuffer - v5;
      do
      {
        v7 = v5[1];
        count = *(unsigned __int16 *)&v5[v6];
        v8 = *v5;
        LOBYTE(count) = v7;
        BYTE1(count) = v8;
        _V_memcpy(dest: &v5[v6], src: &count, count: 2);
        v5 += 2;
        --v4;
      }
      while ( v4 != 0 );
    }
    else if ( v5 != nullptr && outputBuffer != v5 )
    {
      memcpy(dst: outputBuffer, src: v5, count: 2 * count);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001350
// Name: private: void CVarBitVecBase<int>::ReallocInts(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVarBitVecBase<int>::ReallocInts(CVarBitVecBase<int> *this, int numInts)
{
  CVarBitVecBase<int> *m_pInt; // eax
  unsigned int *p_m_iBitStringStorage; // edi
  unsigned int *v5; // eax
  unsigned int v6; // ecx

  if ( numInts != 0 )
  {
    m_pInt = (CVarBitVecBase<int> *)this->m_pInt;
    p_m_iBitStringStorage = &this->m_iBitStringStorage;
    if ( m_pInt == (CVarBitVecBase<int> *)&this->m_iBitStringStorage )
    {
      if ( numInts != 1 )
      {
        v5 = (unsigned int *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * numInts);
        v6 = *p_m_iBitStringStorage;
        this->m_pInt = v5;
        *v5 = v6;
      }
    }
    else if ( numInts == 1 )
    {
      *p_m_iBitStringStorage = m_pInt->m_numBits;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pInt);
      this->m_pInt = p_m_iBitStringStorage;
    }
    else
    {
      this->m_pInt = (unsigned int *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pInt, a3: 4 * numInts);
    }
  }
  else
  {
    if ( this->m_numInts > 1 )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pInt);
    this->m_pInt = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001400
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<struct ModelBatchKey_t,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<ModelBatchKey_t,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<ModelBatchKey_t,int,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<ModelBatchKey_t,int,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
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
        m_nAllocationCount = 1;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 36 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<ModelBatchKey_t,int,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<ModelBatchKey_t,int,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001520
// Name: public: void CVarBitVecBase<int>::Resize(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVarBitVecBase<int>::Resize(CVarBitVecBase<int> *this, int resizeNumBits, bool bClearAll)
{
  int m_numInts; // ecx
  int v5; // edi
  unsigned int *v6; // eax
  unsigned int *p_m_iBitStringStorage; // eax
  unsigned __int8 *m_pInt; // eax
  unsigned int *v9; // eax

  m_numInts = this->m_numInts;
  v5 = (resizeNumBits + 31) / 32;
  if ( v5 != m_numInts )
  {
    if ( this->m_pInt != nullptr )
    {
      CVarBitVecBase<int>::ReallocInts(this, numInts: (resizeNumBits + 31) / 32);
      if ( !bClearAll && resizeNumBits >= this->m_numBits )
      {
        v6 = &this->m_pInt[this->m_numInts - 1];
        *v6 &= `GetEndMask'::`2'::bitStringEndMasks[this->m_numBits % 32];
        memset(dst: (unsigned __int8 *)&this->m_pInt[this->m_numInts], value: 0, count: 4 * (v5 - this->m_numInts));
      }
    }
    else
    {
      if ( v5 != 0 )
      {
        if ( v5 == 1 )
          p_m_iBitStringStorage = &this->m_iBitStringStorage;
        else
          p_m_iBitStringStorage = (unsigned int *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * v5);
        this->m_pInt = p_m_iBitStringStorage;
      }
      bClearAll = true;
    }
    this->m_numInts = v5;
    if ( !bClearAll )
      goto LABEL_15;
    goto LABEL_13;
  }
  if ( bClearAll )
  {
LABEL_13:
    m_pInt = (unsigned __int8 *)this->m_pInt;
    if ( m_pInt != nullptr )
      memset(dst: m_pInt, value: 0, count: 4 * v5);
LABEL_15:
    this->m_numBits = resizeNumBits;
    return;
  }
  if ( resizeNumBits < this->m_numBits )
    goto LABEL_15;
  v9 = this->m_pInt;
  if ( v9 == nullptr )
    goto LABEL_15;
  v9[m_numInts - 1] &= `GetEndMask'::`2'::bitStringEndMasks[this->m_numBits % 32];
  this->m_numBits = resizeNumBits;
}

//------------------------------------------------------------------------------
// Address: 0x10002800
// Name: public: CMemoryMovingTracker::CMemoryMovingTracker(enum CMemoryMovingTracker::MemoryMovingPolicy_t)
// Source: json
//------------------------------------------------------------------------------
CMemoryMovingTracker *__thiscall CMemoryMovingTracker::CMemoryMovingTracker(
        CMemoryMovingTracker *this,
        CMemoryMovingTracker::MemoryMovingPolicy_t ePolicy)
{
  this->m_map.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(unsigned __int8 *const *, unsigned __int8 *const *))CDefOps<unsigned char *>::LessFunc;
  this->m_map.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_map.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_map.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_map.m_Tree.m_Root = -1;
  this->m_map.m_Tree.m_NumElements = 0;
  this->m_map.m_Tree.m_FirstFree = -1;
  this->m_map.m_Tree.m_LastAlloc.index = -1;
  this->m_map.m_Tree.m_pElements = this->m_map.m_Tree.m_Elements.m_pMemory;
  this->m_ePolicy = ePolicy;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10002840
// Name: public: CMdlStripInfo::~CMdlStripInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMdlStripInfo::~CMdlStripInfo(CMdlStripInfo *this)
{
  this->__vftable = (CMdlStripInfo_vtbl *)&CMdlStripInfo::`vftable';
  CUtlVector<CMdlStripInfo::Ps3studioBatch_t *,CUtlMemory<CMdlStripInfo::Ps3studioBatch_t *,int>>::PurgeAndDeleteElements(this: &this->m_ps3studioBatches);
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::~CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>(this: &this->m_vtxMdlOffsets);
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::~CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>(this: (CUtlVector<CMdlStripInfo::MdlRangeItem,CUtlMemory<CMdlStripInfo::MdlRangeItem,int> > *)&this->m_ps3studioStripGroupHeaderBatchOffset);
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::~CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>(this: (CUtlVector<CMdlStripInfo::MdlRangeItem,CUtlMemory<CMdlStripInfo::MdlRangeItem,int> > *)&this->m_ps3studioBatches);
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::~CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>(this: (CUtlVector<CMdlStripInfo::MdlRangeItem,CUtlMemory<CMdlStripInfo::MdlRangeItem,int> > *)&this->m_vtxIndices);
  if ( this->m_vtxVerts.m_numInts > 1 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_vtxVerts.m_pInt);
  this->m_vtxVerts.m_pInt = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100028A0
// Name: public: virtual bool CMdlLib::PrepareModelForPs3(class CUtlBuffer __near &,class CUtlBuffer __near &,class CUtlBuffer __near &,class IMdlStripInfo __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMdlLib::PrepareModelForPs3(
        CMdlLib *this,
        unsigned int mdlBuffer,
        CUtlBuffer *vvdBuffer,
        unsigned int vtxBuffer,
        signed int ppStripInfo)
{
  int m_Get; // ecx
  int v6; // ebx
  studiohdr_t *v7; // esi
  unsigned __int8 *v8; // edi
  unsigned int checksum; // ecx
  OptimizedModel::FileHeader_t *v10; // eax
  OptimizedModel::FileHeader_t *v11; // ecx
  CMdlStripInfo *v12; // eax
  CMdlStripInfo *v13; // eax
  int v14; // ecx
  int v15; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  unsigned int v20; // eax
  bool v21; // cc
  _DWORD *v22; // edi
  unsigned int v23; // esi
  unsigned int v24; // eax
  unsigned int v25; // edx
  unsigned int v26; // edx
  int v27; // eax
  CMdlStripInfo *v28; // esi
  int m_Size; // ebx
  OptimizedModel::StripGroupHeader_t *v30; // edi
  int m_nAllocationCount; // eax
  unsigned int *m_pMemory; // ecx
  int v33; // eax
  signed int *v34; // ebx
  int *v35; // ebx
  int v36; // edi
  OptimizedModel::OptimizedIndexBufferMarkupPs3_t **v37; // ecx
  int v38; // eax
  int v39; // eax
  void *(__thiscall *Alloc_2)(IMemAlloc *, unsigned int); // edx
  unsigned int v41; // edi
  int v42; // eax
  int v43; // esi
  int v44; // eax
  IMdlStripInfo **v45; // eax
  int v46; // eax
  _DWORD *v47; // eax
  int v48; // eax
  unsigned int v49; // ecx
  CUtlMemory<OptimizedModel::OptimizedIndexBufferMarkupPs3_t *,int> *v50; // edi
  int v51; // ebx
  int v52; // eax
  OptimizedModel::OptimizedIndexBufferMarkupPs3_t **v53; // ecx
  int v54; // eax
  int *v55; // eax
  unsigned __int16 v56; // ax
  unsigned __int16 v57; // dx
  unsigned int v58; // ecx
  UtlRBTreeNode_t<CUtlMap<ModelBatchKey_t,int,unsigned short>::Node_t,unsigned short> *v59; // eax
  unsigned int v60; // esi
  int v61; // edx
  VectorByValue *v62; // ecx
  CUtlMap<ModelBatchKey_t,int,unsigned short>::Node_t *p_m_Data; // esi
  _DWORD *v64; // eax
  _DWORD *v65; // esi
  int *v66; // edi
  int v67; // ebx
  int v68; // eax
  int v69; // ecx
  int v70; // eax
  _DWORD *v71; // ebx
  unsigned int *m_numTrianglesPerPartition; // ebx
  unsigned int *v73; // eax
  unsigned int v74; // eax
  unsigned __int8 *v75; // edi
  void *v76; // eax
  int v77; // edi
  int v78; // ebx
  int v79; // edi
  void **v80; // ebx
  unsigned int v81; // edx
  int v82; // ebx
  int v83; // edi
  void **v84; // ebx
  int v85; // ebx
  int v86; // edi
  void **v87; // ebx
  unsigned int v88; // ebx
  int v89; // edi
  int v90; // eax
  unsigned __int8 *v91; // ecx
  int v92; // eax
  _WORD *v93; // edi
  unsigned int *v94; // eax
  unsigned int v95; // eax
  CUtlMemory<OptimizedModel::OptimizedIndexBufferMarkupPs3_t *,int> *v96; // edi
  OptimizedModel::OptimizedIndexBufferMarkupPs3_t **v97; // edx
  OptimizedModel::OptimizedIndexBufferMarkupPs3_t **v98; // eax
  unsigned int *m_numUniqueVertexesPerPartition; // edx
  CUtlMemory<OptimizedModel::OptimizedIndexBufferMarkupPs3_t *,int> *v100; // ebx
  IMdlStripInfo **v101; // ecx
  OptimizedModel::OptimizedIndexBufferMarkupPs3_t **v102; // esi
  int v103; // eax
  OptimizedModel::OptimizedIndexBufferMarkupPs3_t **v104; // ecx
  int v105; // eax
  signed int *v106; // esi
  OptimizedModel::OptimizedIndexBufferMarkupPs3_t **v107; // esi
  int v108; // eax
  int v109; // eax
  VectorByValue **v110; // eax
  unsigned int *v111; // eax
  VectorByValue *v112; // ecx
  VectorByValue *v113; // ecx
  VectorByValue *v114; // ecx
  unsigned int v115; // eax
  unsigned int v116; // ecx
  IMdlStripInfo_vtbl *v117; // edi
  IMdlStripInfo_vtbl *v118; // ebx
  bool (__thiscall *Serialize)(IMdlStripInfo *, CUtlBuffer *); // esi
  int v120; // ecx
  unsigned int v121; // eax
  int v122; // edx
  char *v123; // eax
  int *v124; // eax
  int v125; // ecx
  OptimizedModel::StripGroupHeader_t *v126; // esi
  signed int *v127; // eax
  char *v128; // ecx
  char *v129; // ecx
  signed int v130; // ebx
  int v131; // esi
  int v132; // edi
  unsigned __int16 v133; // ax
  CMdlStripInfo::Ps3studioBatch_t *v134; // edx
  int v135; // ecx
  unsigned int v136; // eax
  CMdlStripInfo::Ps3studioPartition_t **v137; // eax
  unsigned int v138; // ecx
  unsigned int v139; // eax
  int v140; // ecx
  _DWORD *v141; // eax
  int v142; // edx
  _DWORD *v143; // ecx
  int i; // edx
  mstudiomodel_t *v145; // ecx
  OptimizedModel::MeshHeader_t *v146; // esi
  int v147; // eax
  unsigned __int8 *v148; // eax
  Vector4D *v149; // ecx
  unsigned __int8 *v150; // ebx
  int v151; // eax
  unsigned __int8 *v152; // edi
  bool v153; // zf
  int v154; // ecx
  int v155; // edx
  unsigned int v156; // ebx
  unsigned int v157; // eax
  unsigned int v158; // esi
  OptimizedModel::MeshHeader_t *v159; // edi
  OptimizedModel::StripGroupHeader_t *v160; // esi
  int v161; // eax
  int v162; // edi
  _QWORD *v163; // ebx
  char *v164; // edi
  unsigned int v165; // eax
  int v166; // eax
  int *v167; // eax
  int v168; // ecx
  _DWORD *v169; // ecx
  unsigned int v170; // eax
  unsigned __int16 v171; // ax
  CMdlStripInfo::Ps3studioBatch_t *v172; // eax
  unsigned __int16 *v173; // esi
  unsigned __int8 *v174; // edi
  int v175; // edi
  OptimizedModel::StripGroupHeader_t *v176; // eax
  Vector4D *v177; // edi
  int v178; // ecx
  int v179; // ecx
  _QWORD *v180; // eax
  signed int v181; // edx
  int v182; // ecx
  __int64 v183; // xmm0_8
  int v184; // ecx
  OptimizedModel::MeshHeader_t *v185; // edx
  Vector4D *v186; // eax
  char *v187; // esi
  char v188; // cl
  char v189; // dl
  unsigned int v190; // edx
  int v191; // ecx
  unsigned __int8 *v192; // eax
  unsigned int v194; // ebx
  _DWORD *v195; // eax
  mstudiomodel_t *v196; // eax
  OptimizedModel::MeshHeader_t *v197; // eax
  signed int *v198; // esi
  unsigned int v199; // eax
  unsigned int v200; // edi
  unsigned int v201; // edx
  unsigned __int8 *v202; // edi
  int v203; // ebx
  unsigned __int16 v204; // ax
  CMdlStripInfo::Ps3studioBatch_t *v205; // ecx
  int v206; // edx
  int v207; // eax
  unsigned int v208; // edx
  int v209; // edi
  CMdlStripInfo::Ps3studioPartition_t **v210; // edi
  int v211; // eax
  int v212; // edi
  int v213; // eax
  CMdlStripInfo::Ps3studioPartition_t *v214; // edi
  OptimizedModel::StripHeader_t *v215; // eax
  unsigned int v216; // eax
  int v217; // eax
  signed int v218; // edi
  OptimizedModel::MeshHeader_t *v219; // ecx
  int v220; // eax
  int v221; // edi
  int NumBytesRegistered; // eax
  int v223; // edi
  int v224; // eax
  int *v225; // edi
  int v226; // eax
  int *v227; // edi
  int v228; // ebx
  char *v229; // esi
  int v230; // eax
  unsigned __int8 *v231; // eax
  OptimizedModel::StripHeader_t *v232; // ebx
  int *v233; // edi
  int *v234; // esi
  _DWORD *v235; // edi
  int v236; // ebx
  int v237; // eax
  int v238; // ecx
  int v239; // ebx
  int v240; // eax
  int v241; // eax
  int v242; // eax
  int v243; // eax
  int v244; // eax
  int v245; // eax
  _DWORD *v246; // ecx
  unsigned int v247; // esi
  int v248; // eax
  unsigned __int8 *m_p; // ecx
  unsigned __int8 *v250; // esi
  int m; // eax
  char *v252; // eax
  char *v253; // eax
  int *v254; // eax
  OptimizedModel::MeshHeader_t *v255; // ecx
  OptimizedModel::OptimizedIndexBufferMarkupPs3_t **v256; // edi
  OptimizedModel::StripHeader_t *v257; // esi
  unsigned __int16 v258; // ax
  CMdlStripInfo::Ps3studioBatch_t *v259; // ebx
  int v260; // esi
  unsigned int v261; // edi
  signed int v262; // eax
  unsigned int v263; // edi
  unsigned int *v264; // ecx
  CMdlStripInfo::Ps3studioPartition_t *v265; // eax
  unsigned int m_nEdgeDmaInputIdx; // edx
  int v267; // edx
  unsigned int v268; // edi
  unsigned int v269; // eax
  char *v270; // eax
  unsigned int v271; // ebx
  unsigned int v272; // esi
  unsigned __int16 v273; // ax
  unsigned int v274; // ecx
  char *v275; // eax
  int v276; // esi
  unsigned int v277; // ebx
  unsigned int v278; // eax
  CMdlStripInfo::Ps3studioPartition_t *v279; // ebx
  unsigned int n; // edi
  int v281; // esi
  int v282; // eax
  int studiohdr2index; // ecx
  int v284; // edx
  char *v285; // ecx
  int v286; // edx
  int v287; // eax
  int v288; // ecx
  char *v289; // eax
  int v290; // ecx
  char *name; // eax
  CMdlLib::PrepareModelForPs3::__l31::EdgeGeomFreeMemoryTracker_t *v292; // ecx
  unsigned int v293; // [esp-Ch] [ebp-584h]
  char *v294; // [esp-Ch] [ebp-584h]
  int v295; // [esp-8h] [ebp-580h]
  int v296; // [esp-8h] [ebp-580h]
  unsigned int v297; // [esp-4h] [ebp-57Ch]
  unsigned int v298; // [esp-4h] [ebp-57Ch]
  unsigned int v299; // [esp-4h] [ebp-57Ch]
  int v300; // [esp-4h] [ebp-57Ch]
  int v301; // [esp-4h] [ebp-57Ch]
  int v302; // [esp-4h] [ebp-57Ch]
  unsigned int v303; // [esp-4h] [ebp-57Ch]
  int v304; // [esp-4h] [ebp-57Ch]
  EdgeGeomSpuVertexFormat edgeGeomSpuVertexFmt; // [esp+Ch] [ebp-56Ch] BYREF
  CMdlStripInfo msi; // [esp+314h] [ebp-264h] BYREF
  EdgeGeomPartitionerInput egpi; // [esp+394h] [ebp-1E4h] BYREF
  EdgeGeomPartitionerOutput egpo; // [esp+3E0h] [ebp-198h] BYREF
  CUtlMap<ModelBatchKey_t,int,unsigned short>::Node_t dest; // [esp+3F8h] [ebp-180h] BYREF
  CMemoryMovingTracker vtxMemMove; // [esp+414h] [ebp-164h] BYREF
  CUtlMap<ModelBatchKey_t,int,unsigned short> mapMBI; // [esp+448h] [ebp-130h] BYREF
  unsigned __int16 *vtxIdx; // [esp+464h] [ebp-114h]
  unsigned int numEdgeDmaInputBytesTotal; // [esp+468h] [ebp-110h]
  EdgeGeomPartitionerOutput egpoConsumable; // [esp+46Ch] [ebp-10Ch]
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > arrStripLocalEdgeInputIndex; // [esp+484h] [ebp-F4h] BYREF
  CUtlVector<OptimizedModel::OptimizedIndexBufferMarkupPs3_t *,CUtlMemory<OptimizedModel::OptimizedIndexBufferMarkupPs3_t *,int> > arrGroupMarkups; // [esp+498h] [ebp-E0h] BYREF
  int vtxLength; // [esp+4ACh] [ebp-CCh] BYREF
  unsigned int numVhvOriginalModelVertices; // [esp+4B0h] [ebp-C8h]
  CGrowableBitVec arrTouchedOriginalVerts; // [esp+4B4h] [ebp-C4h] BYREF
  CMdlLib::PrepareModelForPs3::__l31::EdgeGeomFreeMemoryTracker_t ps3edgeGeomFreeMemoryTracker; // [esp+4C4h] [ebp-B4h] BYREF
  ModelBatchKey_t mbk; // [esp+4D8h] [ebp-A0h] BYREF
  int k; // [esp+4F0h] [ebp-88h]
  OptimizedModel::StripHeader_t *vtxStrip; // [esp+4F4h] [ebp-84h]
  studiohdr_t *mdlHdr; // [esp+4F8h] [ebp-80h]
  OptimizedModel::MeshHeader_t *vtxMesh; // [esp+4FCh] [ebp-7Ch]
  unsigned int vtxOffIndexBufferEnd; // [esp+500h] [ebp-78h]
  bool bEmitIndices; // [esp+507h] [ebp-71h]
  unsigned int uiRunningOriginalVertexId; // [esp+508h] [ebp-70h]
  int update_studiomesh_numvertices; // [esp+50Ch] [ebp-6Ch]
  float edgeGeomAttributeIndexSpuVB; // [esp+510h] [ebp-68h] BYREF
  int iOrigVert; // [esp+514h] [ebp-64h]
  unsigned int uiSkipVerts; // [esp+518h] [ebp-60h]
  unsigned int vtxOffVertexBufferEnd; // [esp+51Ch] [ebp-5Ch]
  int numCumulativeMeshVertices; // [esp+520h] [ebp-58h]
  unsigned int uiStipGroupFilledVerts; // [esp+524h] [ebp-54h] BYREF
  OptimizedModel::ModelHeader_t *vtxModel; // [esp+528h] [ebp-50h]
  mstudiomodel_t *mdlModel; // [esp+52Ch] [ebp-4Ch]
  int vtxStripGroup_idx; // [esp+530h] [ebp-48h]
  OptimizedModel::StripGroupHeader_t *vtxStripGroup; // [esp+534h] [ebp-44h]
  OptimizedModel::FileHeader_t *vtxHdr; // [esp+538h] [ebp-40h]
  int vtxMesh_idx; // [esp+53Ch] [ebp-3Ch] BYREF
  OptimizedModel::BodyPartHeader_t *vtxBodyPart; // [esp+540h] [ebp-38h]
  int vtxStrip_idx; // [esp+544h] [ebp-34h]
  int vtxModel_idx; // [esp+548h] [ebp-30h]
  CMdlStripInfo *pMsi; // [esp+54Ch] [ebp-2Ch]
  float *pEdgeTriangleCentroids; // [esp+550h] [ebp-28h] BYREF
  int j; // [esp+554h] [ebp-24h]
  int vtxLod_idx; // [esp+558h] [ebp-20h]
  unsigned int uiModelIndexOffset; // [esp+55Ch] [ebp-1Ch]
  unsigned int uiNumIndicesInStripGroupUpdate; // [esp+560h] [ebp-18h]
  int mdlMesh_idx; // [esp+564h] [ebp-14h]
  unsigned int uiRunningEdgeDmaInputEnd; // [esp+568h] [ebp-10h]
  Vector4D *vvdTangentNew; // [esp+56Ch] [ebp-Ch]
  CArrayAutoPtr<unsigned char> memTempVVD; // [esp+570h] [ebp-8h]
  unsigned int iMesh; // [esp+574h] [ebp-4h] BYREF
  unsigned int iBatchEnd; // [esp+580h] [ebp+8h]
  signed int iBatchEnda; // [esp+580h] [ebp+8h]
  signed int iBatchEndb; // [esp+580h] [ebp+8h]
  unsigned int iBatchEndc; // [esp+580h] [ebp+8h]
  unsigned int iBatchEndd; // [esp+580h] [ebp+8h]
  unsigned int iBatchEnde; // [esp+580h] [ebp+8h]
  bool iBatchEnd_3; // [esp+583h] [ebp+Bh]
  CMdlStripInfo::Ps3studioBatch_t *batch; // [esp+584h] [ebp+Ch]
  CMdlStripInfo::Ps3studioBatch_t *batcha; // [esp+584h] [ebp+Ch]
  CMdlStripInfo::Ps3studioBatch_t *batchb; // [esp+584h] [ebp+Ch]
  unsigned int iPartition; // [esp+588h] [ebp+10h]
  unsigned int iPartitiona; // [esp+588h] [ebp+10h]

  m_Get = vvdBuffer->m_Get;
  vtxOffIndexBufferEnd = vvdBuffer->m_Put - m_Get;
  v6 = *(_DWORD *)(vtxBuffer + 12);
  vtxLength = *(_DWORD *)(vtxBuffer + 16) - v6;
  v7 = (studiohdr_t *)(*(_DWORD *)mdlBuffer + *(_DWORD *)(mdlBuffer + 12));
  v8 = &vvdBuffer->m_Memory.m_pMemory[m_Get];
  checksum = v7->checksum;
  v10 = (OptimizedModel::FileHeader_t *)(v6 + *(_DWORD *)vtxBuffer);
  mdlHdr = v7;
  vtxMesh = (OptimizedModel::MeshHeader_t *)v8;
  vtxHdr = v10;
  iBatchEnd = checksum;
  if ( checksum == *((_DWORD *)v8 + 2) && checksum == v10->checkSum )
  {
    v7->checksum = checksum ^ (123333 * checksum);
    v11 = vtxHdr;
    *((_DWORD *)v8 + 2) ^= 123333 * *((_DWORD *)v8 + 2);
    v11->checkSum ^= 123333 * v11->checkSum;
    j = v7->checksum;
    CMdlStripInfo::CMdlStripInfo(this: &msi);
    if ( ppStripInfo != 0 )
    {
      if ( *(_DWORD *)ppStripInfo != 0 )
      {
        pMsi = *(CMdlStripInfo **)ppStripInfo;
        CMdlStripInfo::Reset(this: pMsi);
      }
      else
      {
        v12 = (CMdlStripInfo *)operator new(nSize: 0x80u);
        if ( v12 != nullptr )
        {
          pMsi = CMdlStripInfo::CMdlStripInfo(this: v12);
          *(_DWORD *)ppStripInfo = pMsi;
        }
        else
        {
          pMsi = nullptr;
          *(_DWORD *)ppStripInfo = 0;
        }
      }
    }
    else
    {
      pMsi = &msi;
    }
    v13 = pMsi;
    v14 = j;
    pMsi->m_lChecksumOld = iBatchEnd;
    v13->m_lChecksumNew = v14;
    v7->flags &= ~0x400000u;
    if ( *((_DWORD *)v8 + 12) == 0 )
      *((_DWORD *)v8 + 13) = 0;
    if ( v7->numbones != 1 )
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_ModelLib, a2: 0) != 0 )
        _LoggingSystem_Log(
          a1: LOG_ModelLib,
          a2: 0,
          a3: "No special stripping - the model has %d bone(s).\n",
          v7->numbones);
      goto LABEL_17;
    }
    v15 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v15 + 40))(a1: v15, a2: "-mdllib_ps3_noedge") != 0 )
    {
LABEL_17:
      pMsi->m_eMode = 4;
      CMdlStripInfo::~CMdlStripInfo(this: &msi);
      return 1;
    }
    v17 = _CommandLine();
    bEmitIndices = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v17 + 40))(
                     a1: v17,
                     a2: "-mdllib_ps3_edgeidxbuf") != 0;
    v18 = _CommandLine();
    v19 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v18 + 40))(
            a1: v18,
            a2: "-mdllib_ps3_edgeidxbufUncompressed");
    pMsi->m_eMode = 3;
    iBatchEnd_3 = v19 != 0;
    uiStipGroupFilledVerts |= 3u;
    v7->flags |= 0x400000u;
    vtxOffVertexBufferEnd = (unsigned int)&v8[*((_DWORD *)v8 + 14)];
    memset(&ps3edgeGeomFreeMemoryTracker, 0, sizeof(ps3edgeGeomFreeMemoryTracker));
    mapMBI.m_Tree.m_LessFunc.m_LessFunc = CDefOps<ModelBatchKey_t>::LessFunc;
    memset(&mapMBI.m_Tree.m_Elements, 0, sizeof(mapMBI.m_Tree.m_Elements));
    *(_DWORD *)&mapMBI.m_Tree.m_Root = 0xFFFF;
    *(_DWORD *)&mapMBI.m_Tree.m_FirstFree = -1;
    mapMBI.m_Tree.m_pElements = nullptr;
    numVhvOriginalModelVertices = 0;
    for ( uiRunningEdgeDmaInputEnd = 0;
          (signed int)uiRunningEdgeDmaInputEnd < vtxHdr->numBodyParts;
          ++uiRunningEdgeDmaInputEnd )
    {
      v20 = mdlHdr->bodypartindex + 16 * uiRunningEdgeDmaInputEnd;
      vtxBodyPart = (OptimizedModel::BodyPartHeader_t *)((char *)vtxHdr
                                                       + 8 * uiRunningEdgeDmaInputEnd
                                                       + vtxHdr->bodyPartOffset);
      v21 = vtxBodyPart->numModels <= 0;
      j = (int)mdlHdr + v20;
      mdlMesh_idx = 0;
      if ( !v21 )
      {
        do
        {
          v22 = (int *)((char *)&vtxBodyPart[mdlMesh_idx].numModels + vtxBodyPart->modelOffset);
          v23 = j + *(_DWORD *)(j + 12) + 148 * mdlMesh_idx;
          v24 = *(_DWORD *)(v23 + 84) / 0x30u;
          v25 = *(_DWORD *)(v23 + 84) % 0x30u;
          vtxStrip_idx = (int)v22;
          uiSkipVerts = v23;
          if ( v25 != 0 || ((v26 = *(_DWORD *)(v23 + 88)) & 0xF) != 0 || v24 != v26 >> 4 )
            _Error(a1: "PrepareModelForPs3: invalid model setup [mdlModel_idx=%d]!\n", mdlMesh_idx);
          v21 = *v22 <= 0;
          uiModelIndexOffset = *(_DWORD *)(v23 + 84) / 0x30u;
          vtxLod_idx = 0;
          if ( !v21 )
          {
            do
            {
              v21 = *(_DWORD *)(vtxStrip_idx + *(_DWORD *)(vtxStrip_idx + 4) + 12 * vtxLod_idx) <= 0;
              uiNumIndicesInStripGroupUpdate = vtxStrip_idx + *(_DWORD *)(vtxStrip_idx + 4) + 12 * vtxLod_idx;
              vtxModel_idx = 0;
              if ( !v21 )
              {
                do
                {
                  v27 = *(_DWORD *)(uiSkipVerts + 76) + 116 * vtxModel_idx;
                  memTempVVD.m_p = (unsigned __int8 *)(*(_DWORD *)(uiNumIndicesInStripGroupUpdate + 4)
                                                     + vtxModel_idx
                                                     + uiNumIndicesInStripGroupUpdate
                                                     + 8 * vtxModel_idx);
                  v21 = *(_DWORD *)memTempVVD.m_p <= 0;
                  uiRunningOriginalVertexId = uiSkipVerts + v27;
                  vtxStripGroup_idx = 0;
                  if ( !v21 )
                  {
                    do
                    {
                      v28 = pMsi;
                      m_Size = pMsi->m_ps3studioStripGroupHeaderBatchOffset.m_Size;
                      v30 = (OptimizedModel::StripGroupHeader_t *)&memTempVVD.m_p[33 * vtxStripGroup_idx
                                                                                + *((_DWORD *)memTempVVD.m_p + 1)];
                      ppStripInfo = pMsi->m_ps3studioBatches.m_Size;
                      m_nAllocationCount = pMsi->m_ps3studioStripGroupHeaderBatchOffset.m_Memory.m_nAllocationCount;
                      vtxStripGroup = v30;
                      if ( m_Size + 1 > m_nAllocationCount )
                        CUtlMemory<int,int>::Grow(
                          this: (CUtlMemory<OptimizedModel::OptimizedIndexBufferMarkupPs3_t *,int> *)&pMsi->m_ps3studioStripGroupHeaderBatchOffset,
                          num: m_Size - m_nAllocationCount + 1);
                      ++v28->m_ps3studioStripGroupHeaderBatchOffset.m_Size;
                      m_pMemory = v28->m_ps3studioStripGroupHeaderBatchOffset.m_Memory.m_pMemory;
                      v33 = v28->m_ps3studioStripGroupHeaderBatchOffset.m_Size - m_Size - 1;
                      v28->m_ps3studioStripGroupHeaderBatchOffset.m_pElements = m_pMemory;
                      if ( v33 > 0 )
                        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v33);
                      v34 = (signed int *)&v28->m_ps3studioStripGroupHeaderBatchOffset.m_Memory.m_pMemory[m_Size];
                      if ( v34 != nullptr )
                        *v34 = ppStripInfo;
                      v21 = v30->numStrips <= 0;
                      vtxModel = nullptr;
                      if ( !v21 )
                      {
                        vvdTangentNew = (Vector4D *)(vtxOffVertexBufferEnd + 4 * uiModelIndexOffset);
                        do
                        {
                          v35 = (int *)((char *)&vtxStripGroup->numVerts
                                      + 35 * (_DWORD)vtxModel
                                      + vtxStripGroup->stripOffset);
                          if ( *v35 % 3 != 0 )
                            _Error(a1: "PrepareModelForPs3: invalid number of indices/3! [%d]\n", *v35);
                          v36 = *v35;
                          v37 = nullptr;
                          v38 = 0;
                          memset(&arrGroupMarkups, 0, sizeof(arrGroupMarkups));
                          memset(&arrStripLocalEdgeInputIndex, 0, 16);
                          if ( v36 != 0 )
                          {
                            if ( v36 > 0 )
                            {
                              CUtlMemory<int,int>::Grow(this: &arrGroupMarkups.m_Memory, num: v36);
                              v38 = arrGroupMarkups.m_Size;
                              v37 = arrGroupMarkups.m_Memory.m_pMemory;
                            }
                            if ( v38 > 0 && v36 > 0 )
                              _V_memmove(dest: &v37[v36], src: v37, count: 4 * v38);
                          }
                          v39 = *v35;
                          if ( *v35 > 0 )
                          {
                            Alloc_2 = _g_pMemAlloc->Alloc_2;
                            arrStripLocalEdgeInputIndex.m_Memory.m_nAllocationCount = *v35;
                            arrStripLocalEdgeInputIndex.m_Memory.m_pMemory = (unsigned int *)Alloc_2(
                                                                                               this: _g_pMemAlloc,
                                                                                               a2: 4 * v39);
                          }
                          arrStripLocalEdgeInputIndex.m_pElements = arrStripLocalEdgeInputIndex.m_Memory.m_pMemory;
                          ppStripInfo = 0;
                          if ( *v35 > 0 )
                          {
                            do
                            {
                              iOrigVert = (int)vtxStripGroup + 2 * ppStripInfo + 2 * v35[1] + vtxStripGroup->indexOffset;
                              v41 = *(_DWORD *)(uiRunningOriginalVertexId + 12)
                                  + *(unsigned __int16 *)((char *)&vtxStripGroup->vertOffset
                                                        + 9 * *(unsigned __int16 *)iOrigVert
                                                        + vtxStripGroup->vertOffset);
                              arrGroupMarkups.m_Memory.m_pMemory[ppStripInfo] = (OptimizedModel::OptimizedIndexBufferMarkupPs3_t *)v41;
                              if ( arrStripLocalEdgeInputIndex.m_Size <= v41 )
                              {
                                v42 = arrStripLocalEdgeInputIndex.m_Size;
                                v43 = v41 - arrStripLocalEdgeInputIndex.m_Size + 1;
                                if ( v43 <= 0 )
                                {
                                  if ( v43 < 0 )
                                    arrStripLocalEdgeInputIndex.m_Size = v41 + 1;
                                }
                                else
                                {
                                  iMesh = arrStripLocalEdgeInputIndex.m_Size;
                                  mdlModel = (mstudiomodel_t *)(v41 + 1);
                                  if ( (int)(v41 + 1) > arrStripLocalEdgeInputIndex.m_Memory.m_nAllocationCount )
                                  {
                                    CUtlMemory<int,int>::Grow(
                                      this: (CUtlMemory<OptimizedModel::OptimizedIndexBufferMarkupPs3_t *,int> *)&arrStripLocalEdgeInputIndex,
                                      num: v41 + 1 - arrStripLocalEdgeInputIndex.m_Memory.m_nAllocationCount);
                                    v42 = arrStripLocalEdgeInputIndex.m_Size;
                                  }
                                  arrStripLocalEdgeInputIndex.m_Size = v43 + v42;
                                  arrStripLocalEdgeInputIndex.m_pElements = arrStripLocalEdgeInputIndex.m_Memory.m_pMemory;
                                  v44 = v42 - iMesh;
                                  if ( v44 > 0 )
                                    _V_memmove(
                                      dest: &arrStripLocalEdgeInputIndex.m_Memory.m_pMemory[(_DWORD)mdlModel],
                                      src: &arrStripLocalEdgeInputIndex.m_Memory.m_pMemory[iMesh],
                                      count: 4 * v44);
                                }
                              }
                              v45 = (IMdlStripInfo **)(ppStripInfo + 1);
                              arrStripLocalEdgeInputIndex.m_Memory.m_pMemory[v41] = *(unsigned __int16 *)iOrigVert;
                              ppStripInfo = (signed int)v45;
                            }
                            while ( (int)v45 < *v35 );
                          }
                          pEdgeTriangleCentroids = nullptr;
                          edgeGeomComputeTriangleCentroids(
                            a1: &vvdTangentNew->x,
                            numFloatsPerVertex: 0xCu,
                            positionAttributeIndex: 4u,
                            a4: (const unsigned int *)arrGroupMarkups.m_Memory.m_pMemory,
                            numTriangles: *v35 / 3,
                            a6: &pEdgeTriangleCentroids);
                          egpi.m_numTriangles = *v35 / 3;
                          egpi.m_triangleList = (unsigned int *)arrGroupMarkups.m_Memory.m_pMemory;
                          egpi.m_numInputAttributes = 1;
                          egpi.m_numOutputAttributes = 0;
                          egpi.m_inputVertexStride[0] = 12;
                          memset(&egpi.m_inputVertexStride[1], 0, 16);
                          egpi.m_skinningMatrixFormat = kMatrix4x4RowMajor;
                          v46 = _CommandLine();
                          egpi.m_cacheOptimizerCallback = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v46 + 40))(
                                                            a1: v46,
                                                            a2: "-mdllib_ps3_edgenokcache") == 0
                                                        ? (void (__cdecl *)(const unsigned int *, unsigned int, void *, unsigned int *))edgeGeomKCacheOptimizerHillclimber
                                                        : nullptr;
                          egpi.m_cacheOptimizerUserData = &arrTouchedOriginalVerts;
                          arrTouchedOriginalVerts.m_numBits = 400;
                          arrTouchedOriginalVerts.m_numInts = 0;
                          arrTouchedOriginalVerts.m_iBitStringStorage = 1;
                          arrTouchedOriginalVerts.m_pInt = nullptr;
                          egpi.m_customDataSizeCallback = nullptr;
                          egpi.m_triangleCentroids = pEdgeTriangleCentroids;
                          memset(&egpi.m_skinningMatrixIndexesPerVertex, 0, 20);
                          edgeGeomPartitioner(dataOut: (_LARGE_INTEGER *)&egpi, mask: &egpo);
                          v47 = operator new(nSize: 0x1Cu);
                          if ( v47 != nullptr )
                          {
                            *v47 = 0;
                            v47[1] = 0;
                            v47[2] = 0;
                            v47[3] = 0;
                            v47[4] = 0;
                            update_studiomesh_numvertices = (int)v47;
                          }
                          else
                          {
                            update_studiomesh_numvertices = 0;
                          }
                          v48 = update_studiomesh_numvertices;
                          v49 = numVhvOriginalModelVertices;
                          v50 = (CUtlMemory<OptimizedModel::OptimizedIndexBufferMarkupPs3_t *,int> *)pMsi;
                          *(_DWORD *)(update_studiomesh_numvertices + 20) = uiModelIndexOffset;
                          *(_DWORD *)(v48 + 24) = v49;
                          v51 = (int)v50[6].m_pMemory;
                          v52 = v50[5].m_nAllocationCount;
                          if ( v51 + 1 > v52 )
                            CUtlMemory<int,int>::Grow(this: v50 + 5, num: v51 - v52 + 1);
                          ++v50[6].m_pMemory;
                          v53 = v50[5].m_pMemory;
                          v54 = (int)v50[6].m_pMemory - v51 - 1;
                          v50[6].m_nAllocationCount = (int)v53;
                          if ( v54 > 0 )
                            _V_memmove(dest: &v53[v51 + 1], src: &v53[v51], count: 4 * v54);
                          v55 = (int *)&v50[5].m_pMemory[v51];
                          if ( v55 != nullptr )
                            *v55 = update_studiomesh_numvertices;
                          _V_memset(dest: &mbk, fill: 0, count: 24);
                          mbk.iBodyPart = uiRunningEdgeDmaInputEnd;
                          mbk.iMesh = vtxModel_idx;
                          mbk.iModel = mdlMesh_idx;
                          mbk.iLod = vtxLod_idx;
                          mbk.iStripGroup = vtxStripGroup_idx;
                          mbk.iStrip = (int)vtxModel;
                          _V_memset(&dest, fill: 0, count: 24);
                          _V_memcpy(&dest, src: &mbk, count: 24);
                          dest.elem = v51;
                          iMesh = 0xFFFF;
                          HIBYTE(ppStripInfo) = 0;
                          CUtlRBTree<CUtlMap<ModelBatchKey_t,int,unsigned short>::Node_t,unsigned short,CUtlMap<ModelBatchKey_t,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ModelBatchKey_t,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
                            this: &mapMBI.m_Tree,
                            insert: &dest,
                            parent: (unsigned __int16 *)&iMesh,
                            leftchild: (bool *)&ppStripInfo + 3);
                          v56 = CUtlRBTree<CUtlMap<ModelBatchKey_t,int,unsigned short>::Node_t,unsigned short,CUtlMap<ModelBatchKey_t,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ModelBatchKey_t,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this: &mapMBI.m_Tree);
                          v57 = iMesh;
                          v58 = v56;
                          v59 = mapMBI.m_Tree.m_Elements.m_pMemory;
                          v60 = v58;
                          mapMBI.m_Tree.m_Elements.m_pMemory[v60].m_Right = -1;
                          v59[v60].m_Left = -1;
                          v59[v60].m_Tag = 0;
                          v59[v60].m_Parent = v57;
                          if ( v57 == 0xFFFF )
                          {
                            mapMBI.m_Tree.m_Root = v58;
                          }
                          else
                          {
                            v61 = v57;
                            if ( HIBYTE(ppStripInfo) != 0 )
                              v59[v61].m_Left = v58;
                            else
                              v59[v61].m_Right = v58;
                          }
                          CUtlRBTree<CUtlMap<ModelBatchKey_t,int,unsigned short>::Node_t,unsigned short,CUtlMap<ModelBatchKey_t,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ModelBatchKey_t,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
                            this: &mapMBI.m_Tree,
                            elem: v58);
                          ++mapMBI.m_Tree.m_NumElements;
                          p_m_Data = &mapMBI.m_Tree.m_Elements.m_pMemory[v60].m_Data;
                          if ( p_m_Data != nullptr )
                          {
                            _V_memcpy(dest: p_m_Data, src: &dest, count: 24);
                            p_m_Data->elem = dest.elem;
                          }
                          for ( egpoConsumable = egpo;
                                egpoConsumable.m_numPartitions != 0;
                                egpoConsumable.m_numUniqueVertexesPerPartition = v111 + 1 )
                          {
                            --egpoConsumable.m_numPartitions;
                            v64 = operator new(nSize: 0x68u);
                            if ( v64 != nullptr )
                            {
                              *v64 = 0;
                              v64[1] = 0;
                              v64[2] = 0;
                              v64[3] = 0;
                              v64[4] = 0;
                              v64[5] = 0;
                              v64[6] = 0;
                              v64[7] = 0;
                              v64[8] = 0;
                              v64[9] = 0;
                              v64[10] = 0;
                              v64[11] = 0;
                              v64[12] = 0;
                              v64[13] = 0;
                              v64[14] = 0;
                              v65 = v64;
                            }
                            else
                            {
                              v65 = nullptr;
                            }
                            v66 = (int *)update_studiomesh_numvertices;
                            v67 = *(_DWORD *)(update_studiomesh_numvertices + 12);
                            v68 = *(_DWORD *)(update_studiomesh_numvertices + 4);
                            if ( v67 + 1 > v68 )
                              CUtlMemory<int,int>::Grow(
                                this: (CUtlMemory<OptimizedModel::OptimizedIndexBufferMarkupPs3_t *,int> *)update_studiomesh_numvertices,
                                num: v67 - v68 + 1);
                            ++v66[3];
                            v69 = *v66;
                            v70 = v66[3] - v67 - 1;
                            v66[4] = *v66;
                            if ( v70 > 0 )
                              _V_memmove(
                                dest: (void *)(v69 + 4 * v67 + 4),
                                src: (const void *)(v69 + 4 * v67),
                                count: 4 * v70);
                            v71 = (_DWORD *)(*v66 + 4 * v67);
                            if ( v71 != nullptr )
                              *v71 = v65;
                            m_numTrianglesPerPartition = egpoConsumable.m_numTrianglesPerPartition;
                            v73 = egpoConsumable.m_ioBufferSizePerPartition + 1;
                            v65[15] = *egpoConsumable.m_ioBufferSizePerPartition;
                            egpoConsumable.m_ioBufferSizePerPartition = v73;
                            v74 = *m_numTrianglesPerPartition;
                            if ( v65[1] < (signed int)*m_numTrianglesPerPartition && (int)v65[2] >= 0 )
                            {
                              v75 = (unsigned __int8 *)*v65;
                              v65[1] = v74;
                              v297 = 2 * v74;
                              if ( v75 != nullptr )
                                v76 = _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: v75, a3: v297);
                              else
                                v76 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v297);
                              *v65 = v76;
                            }
                            v65[4] = *v65;
                            edgeGeomMakeIndexBuffer(result: (CLoggingSystem *)egpoConsumable.m_triangleListOut);
                            v77 = ps3edgeGeomFreeMemoryTracker.m_Size;
                            ppStripInfo = v65[19];
                            v78 = ps3edgeGeomFreeMemoryTracker.m_Size;
                            if ( ps3edgeGeomFreeMemoryTracker.m_Size + 1 > ps3edgeGeomFreeMemoryTracker.m_Memory.m_nAllocationCount )
                            {
                              CUtlMemory<int,int>::Grow(
                                this: (CUtlMemory<OptimizedModel::OptimizedIndexBufferMarkupPs3_t *,int> *)&ps3edgeGeomFreeMemoryTracker,
                                num: ps3edgeGeomFreeMemoryTracker.m_Size
                              - ps3edgeGeomFreeMemoryTracker.m_Memory.m_nAllocationCount
                              + 1);
                              v77 = ps3edgeGeomFreeMemoryTracker.m_Size;
                            }
                            v79 = v77 + 1;
                            ps3edgeGeomFreeMemoryTracker.m_Size = v79;
                            ps3edgeGeomFreeMemoryTracker.m_pElements = ps3edgeGeomFreeMemoryTracker.m_Memory.m_pMemory;
                            if ( v79 - v78 - 1 > 0 )
                              _V_memmove(
                                dest: &ps3edgeGeomFreeMemoryTracker.m_Memory.m_pMemory[v78 + 1],
                                src: &ps3edgeGeomFreeMemoryTracker.m_Memory.m_pMemory[v78],
                                count: 4 * (v79 - v78 - 1));
                            v80 = &ps3edgeGeomFreeMemoryTracker.m_Memory.m_pMemory[v78];
                            if ( v80 != nullptr )
                              *v80 = (void *)ppStripInfo;
                            vtxMesh_idx = 1;
                            LOWORD(edgeGeomAttributeIndexSpuVB) = 4;
                            _V_memset(dest: &edgeGeomSpuVertexFmt, fill: 0, count: 776);
                            edgeGeomSpuVertexFmt.m_numAttributes = 1;
                            edgeGeomSpuVertexFmt.m_attributeDefinition[0].m_attributeId = EDGE_GEOM_ATTRIBUTE_ID_POSITION;
                            edgeGeomSpuVertexFmt.m_attributeDefinition[0].m_fixedPointBitDepthFractional[0] = 16;
                            edgeGeomSpuVertexFmt.m_attributeDefinition[0].m_fixedPointBitDepthFractional[1] = 16;
                            edgeGeomSpuVertexFmt.m_attributeDefinition[0].m_fixedPointBitDepthFractional[2] = 16;
                            v81 = *egpoConsumable.m_numUniqueVertexesPerPartition;
                            memset(&edgeGeomSpuVertexFmt.m_attributeDefinition[0].m_byteOffset, 0, 16);
                            edgeGeomSpuVertexFmt.m_vertexStride = 6;
                            edgeGeomSpuVertexFmt.m_attributeDefinition[0].m_type = kSpuAttr_FixedPoint;
                            edgeGeomSpuVertexFmt.m_attributeDefinition[0].m_count = 3;
                            edgeGeomMakeSpuVertexBuffer(
                              a1: &vvdTangentNew->x,
                              numFloatsPerSourceVertex: 0xCu,
                              sourceAttributeIds: (ILoggingListener)&edgeGeomAttributeIndexSpuVB,
                              a4: (const enum EdgeGeomAttributeId *)&vtxMesh_idx,
                              numSourceAttributes: 1u,
                              a6: egpoConsumable.m_originalVertexIndexesPerPartition,
                              numUniqueVertexes: v81,
                              a8: (VectorByValue *)&edgeGeomSpuVertexFmt,
                              a9: (unsigned __int8 **)v65 + 21,
                              a10: (unsigned __int16 *const)v65 + 46,
                              outFixedPointOffsets: (ILoggingListener *)v65 + 22,
                              outFixedPointOffsetsSize: v65 + 25);
                            ppStripInfo = v65[21];
                            v82 = v79;
                            if ( v79 + 1 > ps3edgeGeomFreeMemoryTracker.m_Memory.m_nAllocationCount )
                            {
                              CUtlMemory<int,int>::Grow(
                                this: (CUtlMemory<OptimizedModel::OptimizedIndexBufferMarkupPs3_t *,int> *)&ps3edgeGeomFreeMemoryTracker,
                                num: v79 - ps3edgeGeomFreeMemoryTracker.m_Memory.m_nAllocationCount + 1);
                              v79 = ps3edgeGeomFreeMemoryTracker.m_Size;
                            }
                            v83 = v79 + 1;
                            ps3edgeGeomFreeMemoryTracker.m_pElements = ps3edgeGeomFreeMemoryTracker.m_Memory.m_pMemory;
                            ps3edgeGeomFreeMemoryTracker.m_Size = v83;
                            if ( v83 - v82 - 1 > 0 )
                              _V_memmove(
                                dest: &ps3edgeGeomFreeMemoryTracker.m_Memory.m_pMemory[v82 + 1],
                                src: &ps3edgeGeomFreeMemoryTracker.m_Memory.m_pMemory[v82],
                                count: 4 * (v83 - v82 - 1));
                            v84 = &ps3edgeGeomFreeMemoryTracker.m_Memory.m_pMemory[v82];
                            if ( v84 != nullptr )
                              *v84 = (void *)ppStripInfo;
                            ppStripInfo = v65[22];
                            v85 = v83;
                            if ( v83 + 1 > ps3edgeGeomFreeMemoryTracker.m_Memory.m_nAllocationCount )
                            {
                              CUtlMemory<int,int>::Grow(
                                this: (CUtlMemory<OptimizedModel::OptimizedIndexBufferMarkupPs3_t *,int> *)&ps3edgeGeomFreeMemoryTracker,
                                num: v83 - ps3edgeGeomFreeMemoryTracker.m_Memory.m_nAllocationCount + 1);
                              v83 = ps3edgeGeomFreeMemoryTracker.m_Size;
                            }
                            ps3edgeGeomFreeMemoryTracker.m_Size = v83 + 1;
                            v86 = v83 - v85;
                            ps3edgeGeomFreeMemoryTracker.m_pElements = ps3edgeGeomFreeMemoryTracker.m_Memory.m_pMemory;
                            if ( v86 > 0 )
                              _V_memmove(
                                dest: &ps3edgeGeomFreeMemoryTracker.m_Memory.m_pMemory[v85 + 1],
                                src: &ps3edgeGeomFreeMemoryTracker.m_Memory.m_pMemory[v85],
                                count: 4 * v86);
                            v87 = &ps3edgeGeomFreeMemoryTracker.m_Memory.m_pMemory[v85];
                            if ( v87 != nullptr )
                              *v87 = (void *)ppStripInfo;
                            while ( *egpoConsumable.m_numTrianglesPerPartition != 0 )
                            {
                              --*egpoConsumable.m_numTrianglesPerPartition;
                              for ( ppStripInfo = 3; ppStripInfo != 0; --ppStripInfo )
                              {
                                v88 = *egpoConsumable.m_triangleListOut++;
                                if ( v88 > 0xFFFE )
                                  _Error(a1: "PrepareModelForPs3: index in partition exceeding 0xFFFE! [%u]\n", v88);
                                v89 = v65[3];
                                v90 = v65[1];
                                if ( v89 + 1 > v90 )
                                  CUtlMemory<unsigned short,int>::Grow(
                                    this: (CUtlMemory<unsigned short,int> *)v65,
                                    num: v89 - v90 + 1);
                                ++v65[3];
                                v91 = (unsigned __int8 *)*v65;
                                v92 = v65[3] - v89 - 1;
                                v65[4] = *v65;
                                if ( v92 > 0 )
                                  _V_memmove(dest: &v91[2 * v89 + 2], src: &v91[2 * v89], count: 2 * v92);
                                v93 = (_WORD *)(*v65 + 2 * v89);
                                if ( v93 != nullptr )
                                  *v93 = v88;
                              }
                            }
                            v94 = egpoConsumable.m_numTrianglesPerPartition;
                            --*egpoConsumable.m_numTrianglesPerPartition;
                            egpoConsumable.m_numTrianglesPerPartition = v94 + 1;
                            v95 = *egpoConsumable.m_numUniqueVertexesPerPartition;
                            v96 = (CUtlMemory<OptimizedModel::OptimizedIndexBufferMarkupPs3_t *,int> *)(v65 + 5);
                            if ( v65[6] < (signed int)*egpoConsumable.m_numUniqueVertexesPerPartition
                              && (int)v65[7] >= 0 )
                            {
                              v97 = v96->m_pMemory;
                              v65[6] = v95;
                              v298 = 4 * v95;
                              if ( v97 != nullptr )
                                v98 = (OptimizedModel::OptimizedIndexBufferMarkupPs3_t **)_g_pMemAlloc->Realloc_2(
                                                                                            this: _g_pMemAlloc,
                                                                                            a2: v97,
                                                                                            a3: v298);
                              else
                                v98 = (OptimizedModel::OptimizedIndexBufferMarkupPs3_t **)_g_pMemAlloc->Alloc_2(
                                                                                            this: _g_pMemAlloc,
                                                                                            a2: v298);
                              v96->m_pMemory = v98;
                            }
                            v62 = (VectorByValue *)v96->m_pMemory;
                            m_numUniqueVertexesPerPartition = egpoConsumable.m_numUniqueVertexesPerPartition;
                            v65[9] = v65[5];
                            if ( *m_numUniqueVertexesPerPartition != 0 )
                            {
                              v100 = (CUtlMemory<OptimizedModel::OptimizedIndexBufferMarkupPs3_t *,int> *)(v65 + 10);
                              do
                              {
                                --*egpoConsumable.m_numUniqueVertexesPerPartition;
                                v101 = (IMdlStripInfo **)*egpoConsumable.m_originalVertexIndexesPerPartition;
                                v102 = v96[1].m_pMemory;
                                ++egpoConsumable.m_originalVertexIndexesPerPartition;
                                v103 = v96->m_nAllocationCount;
                                ppStripInfo = (signed int)v101;
                                if ( (int)v102 + 1 > v103 )
                                  CUtlMemory<int,int>::Grow(this: v96, num: (int)v102 - v103 + 1);
                                ++v96[1].m_pMemory;
                                v104 = v96->m_pMemory;
                                v105 = (char *)v96[1].m_pMemory - (char *)v102 - 1;
                                v96[1].m_nAllocationCount = (int)v96->m_pMemory;
                                if ( v105 > 0 )
                                  _V_memmove(dest: &v104[(_DWORD)v102 + 1], src: &v104[(_DWORD)v102], count: 4 * v105);
                                v106 = (signed int *)&v96->m_pMemory[(_DWORD)v102];
                                if ( v106 != nullptr )
                                  *v106 = ppStripInfo;
                                v107 = v100[1].m_pMemory;
                                v108 = v100->m_nAllocationCount;
                                if ( (int)v107 + 1 > v108 )
                                  CUtlMemory<int,int>::Grow(this: v100, num: (int)v107 - v108 + 1);
                                ++v100[1].m_pMemory;
                                v62 = (VectorByValue *)v100->m_pMemory;
                                v109 = (char *)v100[1].m_pMemory - (char *)v107 - 1;
                                v100[1].m_nAllocationCount = (int)v100->m_pMemory;
                                if ( v109 > 0 )
                                  _V_memmove(dest: &v62->y + (_DWORD)v107, src: &v62->x + (_DWORD)v107, count: 4 * v109);
                                v110 = (VectorByValue **)&v100->m_pMemory[(_DWORD)v107];
                                if ( v110 != nullptr )
                                {
                                  v62 = (VectorByValue *)arrStripLocalEdgeInputIndex.m_Memory.m_pMemory[ppStripInfo];
                                  *v110 = v62;
                                }
                              }
                              while ( *egpoConsumable.m_numUniqueVertexesPerPartition != 0 );
                            }
                            v111 = egpoConsumable.m_numUniqueVertexesPerPartition;
                            --*egpoConsumable.m_numUniqueVertexesPerPartition;
                          }
                          edgeGeomFreeEx(this: v62, a2: (const VectorByValue *)pEdgeTriangleCentroids);
                          edgeGeomFreeEx(
                            this: (VectorByValue *)egpo.m_numTrianglesPerPartition,
                            a2: (const VectorByValue *)egpo.m_numTrianglesPerPartition);
                          edgeGeomFreeEx(this: v112, a2: (const VectorByValue *)egpo.m_triangleListOut);
                          edgeGeomFreeEx(
                            this: v113,
                            a2: (const VectorByValue *)egpo.m_originalVertexIndexesPerPartition);
                          edgeGeomFreeEx(
                            this: (VectorByValue *)egpo.m_numUniqueVertexesPerPartition,
                            a2: (const VectorByValue *)egpo.m_numUniqueVertexesPerPartition);
                          edgeGeomFreeEx(this: v114, a2: (const VectorByValue *)egpo.m_ioBufferSizePerPartition);
                          if ( arrStripLocalEdgeInputIndex.m_Memory.m_nGrowSize >= 0
                            && arrStripLocalEdgeInputIndex.m_Memory.m_pMemory != nullptr )
                          {
                            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: arrStripLocalEdgeInputIndex.m_Memory.m_pMemory);
                          }
                          if ( arrGroupMarkups.m_Memory.m_nGrowSize >= 0
                            && arrGroupMarkups.m_Memory.m_pMemory != nullptr )
                          {
                            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: arrGroupMarkups.m_Memory.m_pMemory);
                          }
                          vtxModel = (OptimizedModel::ModelHeader_t *)((char *)vtxModel + 1);
                        }
                        while ( (int)vtxModel < vtxStripGroup->numStrips );
                      }
                      numVhvOriginalModelVertices += vtxStripGroup->numVerts;
                      ++vtxStripGroup_idx;
                    }
                    while ( vtxStripGroup_idx < *(_DWORD *)memTempVVD.m_p );
                  }
                  ++vtxModel_idx;
                }
                while ( vtxModel_idx < *(_DWORD *)uiNumIndicesInStripGroupUpdate );
              }
              ++vtxLod_idx;
            }
            while ( vtxLod_idx < *(_DWORD *)vtxStrip_idx );
          }
          ++mdlMesh_idx;
        }
        while ( mdlMesh_idx < vtxBodyPart->numModels );
      }
    }
    v115 = 0;
    edgeGeomAttributeIndexSpuVB = 0.0;
    if ( pMsi->m_ps3studioBatches.m_Size > 0 )
    {
      v116 = pMsi->m_ps3studioBatches.m_Size;
      ppStripInfo = (signed int)pMsi->m_ps3studioBatches.m_Memory.m_pMemory;
      iMesh = v116;
      do
      {
        if ( *(int *)(*(_DWORD *)ppStripInfo + 12) > 0 )
        {
          v117 = **(IMdlStripInfo_vtbl ***)ppStripInfo;
          v118 = *(IMdlStripInfo_vtbl **)(*(_DWORD *)ppStripInfo + 12);
          do
          {
            Serialize = v117->Serialize;
            v120 = *((_DWORD *)v117->Serialize + 8);
            LODWORD(edgeGeomAttributeIndexSpuVB) += v120;
            v121 = (v115 + 15) & 0xFFFFFFF0;
            if ( iBatchEnd_3 )
              v122 = 2 * *((_DWORD *)Serialize + 3);
            else
              v122 = *((unsigned __int16 *)Serialize + 40) + *((unsigned __int16 *)Serialize + 41);
            v115 = (((v122 + v121 + 15) & 0xFFFFFFF0) + 12 * v120 + 15) & 0xFFFFFFF0;
            v117 = (IMdlStripInfo_vtbl *)((char *)v117 + 4);
            v118 = (IMdlStripInfo_vtbl *)((char *)v118 - 1);
          }
          while ( v118 != nullptr );
        }
        ppStripInfo += 4;
        --iMesh;
      }
      while ( iMesh != 0 );
    }
    numEdgeDmaInputBytesTotal = (v115 + 255) & 0xFFFFFF00;
    numCumulativeMeshVertices = 0;
    mdlMesh_idx = 0;
    if ( vtxHdr->numBodyParts > 0 )
    {
      vvdTangentNew = nullptr;
      do
      {
        v123 = (char *)vvdTangentNew + mdlHdr->bodypartindex;
        mdlModel = (mstudiomodel_t *)((char *)vtxHdr + 8 * mdlMesh_idx + vtxHdr->bodyPartOffset);
        v21 = *(_DWORD *)mdlModel->name <= 0;
        j = (int)&v123[(_DWORD)mdlHdr];
        uiRunningEdgeDmaInputEnd = 0;
        if ( !v21 )
        {
          memTempVVD.m_p = nullptr;
          do
          {
            vtxModel = (OptimizedModel::ModelHeader_t *)((char *)mdlModel
                                                       + 8 * uiRunningEdgeDmaInputEnd
                                                       + *(_DWORD *)&mdlModel->name[4]);
            v124 = (int *)&memTempVVD.m_p[*(_DWORD *)(j + 12) + j];
            v125 = 16 * numCumulativeMeshVertices;
            uiNumIndicesInStripGroupUpdate = (unsigned int)v124;
            vtxStrip_idx = 0;
            v124[21] = 48 * numCumulativeMeshVertices;
            v124[22] = v125;
            ppStripInfo = 0;
            if ( v124[18] > 0 )
            {
              vtxBodyPart = nullptr;
              vtxMesh_idx = 0;
              do
              {
                v126 = (OptimizedModel::StripGroupHeader_t *)(uiNumIndicesInStripGroupUpdate
                                                            + vtxMesh_idx
                                                            + *(_DWORD *)(uiNumIndicesInStripGroupUpdate + 76)
                                                            + 52);
                uiRunningOriginalVertexId = uiNumIndicesInStripGroupUpdate
                                          + vtxMesh_idx
                                          + *(_DWORD *)(uiNumIndicesInStripGroupUpdate + 76);
                update_studiomesh_numvertices = 0;
                _V_memset(dest: v126, fill: 0, count: 32);
                vtxModel_idx = 0;
                if ( vtxModel->numLODs > 0 )
                {
                  vtxStripGroup_idx = 0;
                  vtxStripGroup = v126;
                  do
                  {
                    v127 = (int *)((char *)&vtxModel->numLODs + vtxStripGroup_idx + vtxModel->lodOffset);
                    if ( *v127 > ppStripInfo )
                    {
                      v128 = (char *)vtxBodyPart + v127[1];
                      pEdgeTriangleCentroids = nullptr;
                      v129 = &v128[(_DWORD)v127];
                      v21 = *(_DWORD *)v129 <= 0;
                      iOrigVert = (int)v129;
                      if ( !v21 )
                      {
                        vtxLod_idx = 0;
                        do
                        {
                          v130 = 0;
                          vtxOffVertexBufferEnd = iOrigVert + vtxLod_idx + *(_DWORD *)(iOrigVert + 4);
                          uiModelIndexOffset = 0;
                          if ( *(int *)(vtxOffVertexBufferEnd + 16) > 0 )
                          {
                            do
                            {
                              _V_memset(dest: &mbk, fill: 0, count: 24);
                              mbk.iLod = vtxModel_idx;
                              mbk.iBodyPart = mdlMesh_idx;
                              mbk.iModel = uiRunningEdgeDmaInputEnd;
                              mbk.iMesh = ppStripInfo;
                              mbk.iStripGroup = (int)pEdgeTriangleCentroids;
                              mbk.iStrip = v130;
                              _V_memset(&dest, fill: 0, count: 24);
                              _V_memcpy(&dest, src: &mbk, count: 24);
                              v131 = 0;
                              v132 = 0;
                              v133 = CUtlRBTree<CUtlMap<ModelBatchKey_t,int,unsigned short>::Node_t,unsigned short,CUtlMap<ModelBatchKey_t,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ModelBatchKey_t,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                                       this: &mapMBI.m_Tree,
                                       search: &dest);
                              v134 = pMsi->m_ps3studioBatches.m_Memory.m_pMemory[mapMBI.m_Tree.m_Elements.m_pMemory[v133].m_Data.elem];
                              v135 = v134->m_arrPartitions.m_Size;
                              v136 = 0;
                              uiSkipVerts = 0;
                              iMesh = 0;
                              if ( v135 >= 2 )
                              {
                                v137 = v134->m_arrPartitions.m_Memory.m_pMemory;
                                v138 = ((unsigned int)(v135 - 2) >> 1) + 1;
                                iMesh = 2 * v138;
                                do
                                {
                                  v131 += (*v137)->m_arrVertOriginalIndices.m_Size;
                                  v132 += v137[1]->m_arrVertOriginalIndices.m_Size;
                                  v137 += 2;
                                  --v138;
                                }
                                while ( v138 != 0 );
                                v136 = uiSkipVerts;
                                v130 = uiModelIndexOffset;
                              }
                              if ( (signed int)iMesh < v134->m_arrPartitions.m_Size )
                                v136 = v134->m_arrPartitions.m_Memory.m_pMemory[iMesh]->m_arrVertOriginalIndices.m_Size;
                              v139 = v132 + v131 + v136;
                              vtxStripGroup->numVerts += v139;
                              update_studiomesh_numvertices += v139;
                              uiModelIndexOffset = ++v130;
                            }
                            while ( v130 < *(_DWORD *)(vtxOffVertexBufferEnd + 16) );
                          }
                          vtxLod_idx += 33;
                          pEdgeTriangleCentroids = (float *)((char *)pEdgeTriangleCentroids + 1);
                        }
                        while ( (int)pEdgeTriangleCentroids < *(_DWORD *)iOrigVert );
                      }
                    }
                    vtxStripGroup_idx += 12;
                    vtxStripGroup = (OptimizedModel::StripGroupHeader_t *)((char *)vtxStripGroup + 4);
                    ++vtxModel_idx;
                  }
                  while ( vtxModel_idx < vtxModel->numLODs );
                }
                v140 = update_studiomesh_numvertices;
                v141 = (_DWORD *)uiRunningOriginalVertexId;
                v142 = vtxStrip_idx;
                numCumulativeMeshVertices += update_studiomesh_numvertices;
                *(_DWORD *)(uiRunningOriginalVertexId + 12) = vtxStrip_idx;
                v141[2] = v140;
                vtxStrip_idx = v140 + v142;
                v143 = v141 + 20;
                for ( i = 7; i != 0; --i )
                {
                  *(v143 - 1) += *v143;
                  --v143;
                }
                if ( v141[14] == 0 )
                  v141[14] = v141[13];
                if ( v141[15] == 0 )
                  v141[15] = v141[14];
                if ( v141[16] == 0 )
                  v141[16] = v141[15];
                if ( v141[17] == 0 )
                  v141[17] = v141[16];
                if ( v141[18] == 0 )
                  v141[18] = v141[17];
                if ( v141[19] == 0 )
                  v141[19] = v141[18];
                if ( v141[20] == 0 )
                  v141[20] = v141[19];
                vtxMesh_idx += 116;
                vtxBodyPart = (OptimizedModel::BodyPartHeader_t *)((char *)vtxBodyPart + 9);
                ++ppStripInfo;
              }
              while ( ppStripInfo < *(_DWORD *)(uiNumIndicesInStripGroupUpdate + 72) );
            }
            v145 = mdlModel;
            memTempVVD.m_p += 148;
            *(_DWORD *)(uiNumIndicesInStripGroupUpdate + 80) = vtxStrip_idx;
            ++uiRunningEdgeDmaInputEnd;
          }
          while ( (signed int)uiRunningEdgeDmaInputEnd < *(_DWORD *)v145->name );
        }
        ++vvdTangentNew;
        ++mdlMesh_idx;
      }
      while ( mdlMesh_idx < vtxHdr->numBodyParts );
    }
    v146 = vtxMesh;
    uiRunningEdgeDmaInputEnd = (unsigned int)vtxMesh + *(int *)((char *)&vtxMesh[6].numStripGroups + 2);
    v147 = *(int *)((char *)&vtxMesh[6].stripGroupHeaderOffset + 2);
    if ( v147 != 0 )
      ppStripInfo = (signed int)vtxMesh + v147;
    else
      ppStripInfo = 0;
    if ( *(int *)((char *)&vtxMesh[5].numStripGroups + 3) != 0 )
    {
      v148 = (unsigned __int8 *)operator new(nSize: vtxOffIndexBufferEnd);
      v149 = (Vector4D *)&v148[*(int *)((char *)&v146[6].stripGroupHeaderOffset + 2)];
      v150 = &v148[*(int *)((char *)&v146[6].numStripGroups + 2)];
      v21 = *(int *)((char *)&v146[5].numStripGroups + 3) <= 0;
      memTempVVD.m_p = v148;
      v151 = *(int *)((char *)&v146[5].stripGroupHeaderOffset + 3);
      vvdTangentNew = v149;
      mdlModel = nullptr;
      if ( !v21 )
      {
        v152 = &v146->flags + v151;
        do
        {
          memcpy(
            dst: v150,
            src: (unsigned __int8 *)(uiRunningEdgeDmaInputEnd + 48 * *((_DWORD *)v152 - 1)),
            count: 48 * *(_DWORD *)v152);
          v150 += 48 * *(_DWORD *)v152;
          if ( ppStripInfo != 0 )
          {
            memcpy(
              dst: (unsigned __int8 *)vvdTangentNew,
              src: (unsigned __int8 *)(ppStripInfo + 16 * *((_DWORD *)v152 - 1)),
              count: 16 * *(_DWORD *)v152);
            vvdTangentNew += *(_DWORD *)v152;
          }
          v152 += 12;
          mdlModel = (mstudiomodel_t *)((char *)mdlModel + 1);
        }
        while ( (int)mdlModel < *(int *)((char *)&v146[5].numStripGroups + 3) );
      }
      if ( uiRunningEdgeDmaInputEnd != 0 )
        memcpy(
          dst: (unsigned __int8 *)uiRunningEdgeDmaInputEnd,
          src: &memTempVVD.m_p[*(int *)((char *)&v146[6].numStripGroups + 2)],
          count: 48 * *(int *)((char *)&v146[1].stripGroupHeaderOffset + 3));
      if ( ppStripInfo != 0 )
        memcpy(
          dst: (unsigned __int8 *)ppStripInfo,
          src: &memTempVVD.m_p[*(int *)((char *)&v146[6].stripGroupHeaderOffset + 2)],
          count: 16 * *(int *)((char *)&v146[1].stripGroupHeaderOffset + 3));
      free(pMem: memTempVVD.m_p);
      free(pMem: nullptr);
    }
    *(int *)((char *)&v146[6].numStripGroups + 2) -= (12 * *(int *)((char *)&v146[5].numStripGroups + 3) + 15)
                                                   & 0xFFFFFFF0;
    v153 = v146->numStripGroups == 1448297545;
    *(int *)((char *)&v146[5].numStripGroups + 3) = 0;
    if ( !v153 )
      _Error(a1: "PrepareModelForPs3: unsupported VVD structure!\n");
    if ( ppStripInfo != 0 )
      v154 = 16 * LODWORD(edgeGeomAttributeIndexSpuVB);
    else
      v154 = 0;
    v155 = *(int *)((char *)&v146[6].numStripGroups + 2);
    v156 = numEdgeDmaInputBytesTotal;
    j = 48 * LODWORD(edgeGeomAttributeIndexSpuVB);
    v157 = (48 * LODWORD(edgeGeomAttributeIndexSpuVB) + v154 + v155 + 255) & 0xFFFFFF00;
    v158 = v157 >> 8;
    mdlMesh_idx = v157;
    uiSkipVerts = v157 + numEdgeDmaInputBytesTotal;
    if ( ((v157 >> 8) & 0xFF0000) != 0 )
      _Error(a1: "PrepareModelForPs3: VVD buffer DMA offset too large!\n");
    if ( (v156 & 0xFF800000) != 0 )
      _Error(a1: "PrepareModelForPs3: VVD buffer DMA size too large!\n");
    if ( (_BYTE)v156 != 0 )
      _Error(a1: "PrepareModelForPs3: VVD buffer DMA size incorrect!\n");
    v159 = vtxMesh;
    v299 = uiSkipVerts;
    *(int *)((char *)&vtxMesh[5].stripGroupHeaderOffset + 3) = v158 | ((v156 | 0xFF800000) << 8);
    v160 = (OptimizedModel::StripGroupHeader_t *)operator new(nSize: v299);
    v161 = LODWORD(edgeGeomAttributeIndexSpuVB);
    *(float *)((char *)&v159[1].stripGroupHeaderOffset + 3) = edgeGeomAttributeIndexSpuVB;
    *(int *)((char *)&v159[2].numStripGroups + 2) = v161;
    *(int *)((char *)&v159[2].stripGroupHeaderOffset + 2) = v161;
    *(int *)((char *)&v159[3].numStripGroups + 1) = v161;
    *(int *)((char *)&v159[3].stripGroupHeaderOffset + 1) = v161;
    v159[4].numStripGroups = v161;
    v159[4].stripGroupHeaderOffset = v161;
    *(_DWORD *)&v159[4].flags = v161;
    v295 = *(int *)((char *)&v159[6].numStripGroups + 2);
    vtxStripGroup = v160;
    _V_memcpy(dest: v160, src: v159, count: v295);
    v162 = *(int *)((char *)&v159[6].numStripGroups + 2);
    vtxMesh = (OptimizedModel::MeshHeader_t *)((char *)v160 + v162 + j);
    v21 = vtxHdr->numBodyParts <= 0;
    v163 = (_QWORD *)((char *)&v160->numVerts + v162);
    v164 = (char *)v160 + mdlMesh_idx;
    vtxStripGroup_idx = 0;
    if ( !v21 )
    {
      iMesh = 0;
      do
      {
        v165 = iMesh + mdlHdr->bodypartindex;
        vtxOffVertexBufferEnd = (unsigned int)vtxHdr + 8 * vtxStripGroup_idx + vtxHdr->bodyPartOffset;
        v21 = *(_DWORD *)vtxOffVertexBufferEnd <= 0;
        numEdgeDmaInputBytesTotal = (unsigned int)mdlHdr + v165;
        vtxModel_idx = 0;
        if ( !v21 )
        {
          uiModelIndexOffset = 0;
          do
          {
            vtxModel = (OptimizedModel::ModelHeader_t *)(*(_DWORD *)(vtxOffVertexBufferEnd + 4)
                                                       + vtxOffVertexBufferEnd
                                                       + 8 * vtxModel_idx);
            v166 = uiModelIndexOffset + numEdgeDmaInputBytesTotal + *(_DWORD *)(numEdgeDmaInputBytesTotal + 12);
            vtxLod_idx = 0;
            v21 = *(_DWORD *)(v166 + 72) <= 0;
            k = v166;
            if ( !v21 )
            {
              update_studiomesh_numvertices = 0;
              do
              {
                v21 = vtxModel->numLODs <= 0;
                numCumulativeMeshVertices = 0;
                if ( !v21 )
                {
                  pEdgeTriangleCentroids = nullptr;
                  do
                  {
                    v167 = (int *)((int)pEdgeTriangleCentroids + vtxModel->lodOffset + (_DWORD)vtxModel);
                    if ( *v167 > vtxLod_idx )
                    {
                      v168 = update_studiomesh_numvertices + v167[1];
                      vtxBodyPart = nullptr;
                      v169 = (int *)((char *)v167 + v168);
                      v21 = *v169 <= 0;
                      uiRunningOriginalVertexId = (unsigned int)v169;
                      if ( !v21 )
                      {
                        vtxMesh_idx = 0;
                        do
                        {
                          v170 = *(_DWORD *)(uiRunningOriginalVertexId + 4) + uiRunningOriginalVertexId + vtxMesh_idx;
                          vtxStrip_idx = 0;
                          v21 = *(_DWORD *)(v170 + 16) <= 0;
                          vtxStrip = (OptimizedModel::StripHeader_t *)v170;
                          if ( !v21 )
                          {
                            do
                            {
                              _V_memset(dest: &mbk, fill: 0, count: 24);
                              mbk.iBodyPart = vtxStripGroup_idx;
                              mbk.iMesh = vtxLod_idx;
                              mbk.iModel = vtxModel_idx;
                              mbk.iLod = numCumulativeMeshVertices;
                              mbk.iStripGroup = (int)vtxBodyPart;
                              mbk.iStrip = vtxStrip_idx;
                              _V_memset(&dest, fill: 0, count: 24);
                              _V_memcpy(&dest, src: &mbk, count: 24);
                              v171 = CUtlRBTree<CUtlMap<ModelBatchKey_t,int,unsigned short>::Node_t,unsigned short,CUtlMap<ModelBatchKey_t,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ModelBatchKey_t,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                                       this: &mapMBI.m_Tree,
                                       search: &dest);
                              v172 = pMsi->m_ps3studioBatches.m_Memory.m_pMemory[mapMBI.m_Tree.m_Elements.m_pMemory[v171].m_Data.elem];
                              v21 = v172->m_arrPartitions.m_Size <= 0;
                              uiNumIndicesInStripGroupUpdate = (unsigned int)v172;
                              memTempVVD.m_p = nullptr;
                              if ( !v21 )
                              {
                                do
                                {
                                  v173 = *(unsigned __int16 **)(*(_DWORD *)uiNumIndicesInStripGroupUpdate
                                                              + 4 * (int)memTempVVD.m_p);
                                  v174 = (unsigned __int8 *)vtxStripGroup
                                       + ((v164 - (char *)vtxStripGroup + 15) & 0xFFFFFFF0);
                                  vtxIdx = v173;
                                  *((_DWORD *)v173 + 16) = v174 - (unsigned __int8 *)vtxStripGroup - mdlMesh_idx;
                                  if ( iBatchEnd_3 )
                                  {
                                    CByteswap::SwapBufferToTargetEndian<unsigned short>(
                                      this: (CByteswap *)&uiStipGroupFilledVerts,
                                      outputBuffer: v174,
                                      inputBuffer: *(unsigned __int8 **)v173,
                                      count: *((_DWORD *)v173 + 3));
                                    v175 = (int)&v174[2 * *((_DWORD *)v173 + 3)];
                                  }
                                  else
                                  {
                                    _V_memcpy(dest: v174, src: *((const void **)v173 + 19), count: v173[40] + v173[41]);
                                    v175 = (int)&v174[v173[40] + v173[41]];
                                  }
                                  v176 = vtxStripGroup;
                                  v177 = (Vector4D *)((char *)vtxStripGroup
                                                    + ((v175 - (_DWORD)vtxStripGroup + 15) & 0xFFFFFFF0));
                                  *((_DWORD *)v173 + 17) = (char *)v177 - (char *)vtxStripGroup - mdlMesh_idx;
                                  v178 = 0;
                                  iOrigVert = 0;
                                  if ( *((int *)v173 + 8) > 0 )
                                  {
                                    do
                                    {
                                      v179 = *(_DWORD *)(uiNumIndicesInStripGroupUpdate + 20)
                                           + *(_DWORD *)(*((_DWORD *)v173 + 5) + 4 * v178);
                                      v180 = (_QWORD *)(48 * v179 + uiRunningEdgeDmaInputEnd);
                                      v181 = ppStripInfo;
                                      *v163 = *v180;
                                      v163[1] = v180[1];
                                      v163[2] = v180[2];
                                      v163[3] = v180[3];
                                      v163[4] = v180[4];
                                      v163[5] = v180[5];
                                      v163 += 6;
                                      if ( v181 != 0 )
                                      {
                                        v182 = 16 * v179;
                                        v183 = *(_QWORD *)(v182 + v181);
                                        v184 = v181 + v182;
                                        v185 = vtxMesh;
                                        *(_QWORD *)&vtxMesh->numStripGroups = v183;
                                        *(_QWORD *)&v185->flags = *(_QWORD *)(v184 + 8);
                                        vtxMesh = (OptimizedModel::MeshHeader_t *)((char *)v185 + 16);
                                      }
                                      v186 = (Vector4D *)(v180 + 2);
                                      if ( v177 != nullptr )
                                      {
                                        if ( v186 == nullptr )
                                          v186 = v177;
                                        if ( (uiStipGroupFilledVerts & 1) != 0 )
                                        {
                                          vvdTangentNew = v177;
                                          v187 = (char *)&v186->x + 2;
                                          for ( mdlModel = (mstudiomodel_t *)3;
                                                mdlModel != nullptr;
                                                mdlModel = (mstudiomodel_t *)((char *)mdlModel - 1) )
                                          {
                                            v188 = v187[1];
                                            v189 = *v187;
                                            edgeGeomAttributeIndexSpuVB = vvdTangentNew->x;
                                            LOBYTE(edgeGeomAttributeIndexSpuVB) = v188;
                                            BYTE2(edgeGeomAttributeIndexSpuVB) = *(v187 - 1);
                                            BYTE1(edgeGeomAttributeIndexSpuVB) = v189;
                                            HIBYTE(edgeGeomAttributeIndexSpuVB) = *(v187 - 2);
                                            _V_memcpy(dest: vvdTangentNew, src: &edgeGeomAttributeIndexSpuVB, count: 4);
                                            vvdTangentNew = (Vector4D *)((char *)vvdTangentNew + 4);
                                            v187 += 4;
                                          }
                                          v173 = vtxIdx;
                                        }
                                        else if ( v177 != v186 )
                                        {
                                          *(_QWORD *)&v177->x = *(_QWORD *)&v186->x;
                                          v177->z = v186->z;
                                        }
                                      }
                                      v178 = iOrigVert + 1;
                                      v177 = (Vector4D *)((char *)v177 + 12);
                                      iOrigVert = v178;
                                    }
                                    while ( v178 < *((_DWORD *)v173 + 8) );
                                    v176 = vtxStripGroup;
                                  }
                                  v190 = uiNumIndicesInStripGroupUpdate;
                                  v164 = (char *)v176 + (((char *)v177 - (char *)v176 + 15) & 0xFFFFFFF0);
                                  v191 = v164 - (char *)v176 - mdlMesh_idx;
                                  v192 = memTempVVD.m_p + 1;
                                  *((_DWORD *)v173 + 18) = v191;
                                  memTempVVD.m_p = v192;
                                }
                                while ( (int)v192 < *(_DWORD *)(v190 + 12) );
                              }
                              ++vtxStrip_idx;
                            }
                            while ( vtxStrip_idx < *(_DWORD *)&vtxStrip->numBones );
                          }
                          vtxMesh_idx += 33;
                          vtxBodyPart = (OptimizedModel::BodyPartHeader_t *)((char *)vtxBodyPart + 1);
                        }
                        while ( (int)vtxBodyPart < *(_DWORD *)uiRunningOriginalVertexId );
                      }
                    }
                    pEdgeTriangleCentroids += 3;
                    ++numCumulativeMeshVertices;
                  }
                  while ( numCumulativeMeshVertices < vtxModel->numLODs );
                }
                update_studiomesh_numvertices += 9;
                ++vtxLod_idx;
              }
              while ( vtxLod_idx < *(_DWORD *)(k + 72) );
            }
            uiModelIndexOffset += 148;
            ++vtxModel_idx;
          }
          while ( vtxModel_idx < *(_DWORD *)vtxOffVertexBufferEnd );
        }
        iMesh += 16;
        ++vtxStripGroup_idx;
      }
      while ( vtxStripGroup_idx < vtxHdr->numBodyParts );
      v160 = vtxStripGroup;
    }
    v194 = uiSkipVerts;
    CUtlBuffer::EnsureCapacity(this: vvdBuffer, num: uiSkipVerts + vvdBuffer->m_Get);
    _V_memcpy(dest: &vvdBuffer->m_Memory.m_pMemory[vvdBuffer->m_Get], src: v160, count: v194);
    CUtlBuffer::SeekPut(this: vvdBuffer, type: SEEK_HEAD, offset: v194 + vvdBuffer->m_Get);
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_ModelLib, a2: 0) != 0 )
      _LoggingSystem_Log(a1: LOG_ModelLib, a2: 0, a3: " Increased VVD size by %d bytes.\n", v194 - vtxOffIndexBufferEnd);
    if ( ppStripInfo != 0 )
      *(_DWORD *)&vvdBuffer->m_Memory.m_pMemory[vvdBuffer->m_Get + 60] = j
                                                                       + *(_DWORD *)&vvdBuffer->m_Memory.m_pMemory[vvdBuffer->m_Get + 56];
    free(pMem: v160);
    free(pMem: nullptr);
    vtxMemMove.m_map.m_Tree.m_Root = -1;
    vtxMemMove.m_map.m_Tree.m_FirstFree = -1;
    vtxMemMove.m_map.m_Tree.m_LastAlloc.index = -1;
    j = -1;
    uiSkipVerts = -1;
    vtxMemMove.m_map.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(unsigned __int8 *const *, unsigned __int8 *const *))CDefOps<unsigned char *>::LessFunc;
    memset(&vtxMemMove.m_map.m_Tree.m_Elements, 0, sizeof(vtxMemMove.m_map.m_Tree.m_Elements));
    vtxMemMove.m_map.m_Tree.m_NumElements = 0;
    vtxMemMove.m_map.m_Tree.m_pElements = nullptr;
    vtxMemMove.m_ePolicy = MEMORY_MODIFY;
    vtxOffIndexBufferEnd = 0;
    vtxOffVertexBufferEnd = 0;
    for ( uiRunningEdgeDmaInputEnd = 0;
          (signed int)uiRunningEdgeDmaInputEnd < vtxHdr->numBodyParts;
          ++uiRunningEdgeDmaInputEnd )
    {
      iBatchEnda = 0;
      v21 = *(int *)((char *)&vtxHdr->version + 8 * uiRunningEdgeDmaInputEnd + vtxHdr->bodyPartOffset) <= 0;
      vtxLod_idx = (int)vtxHdr + 8 * uiRunningEdgeDmaInputEnd + vtxHdr->bodyPartOffset;
      if ( !v21 )
      {
        do
        {
          v195 = (_DWORD *)(*(_DWORD *)(vtxLod_idx + 4) + vtxLod_idx + 8 * iBatchEnda);
          pEdgeTriangleCentroids = nullptr;
          v21 = *v195 <= 0;
          iOrigVert = (int)v195;
          if ( !v21 )
          {
            mdlMesh_idx = 0;
            do
            {
              v196 = (mstudiomodel_t *)(mdlMesh_idx + iOrigVert + *(_DWORD *)(iOrigVert + 4));
              vtxMesh_idx = 0;
              v21 = *(_DWORD *)v196->name <= 0;
              mdlModel = v196;
              if ( !v21 )
              {
                numCumulativeMeshVertices = 0;
                do
                {
                  v197 = (OptimizedModel::MeshHeader_t *)&mdlModel->name[*(_DWORD *)&mdlModel->name[4]
                                                                       + numCumulativeMeshVertices];
                  vtxStrip_idx = 0;
                  v21 = v197->numStripGroups <= 0;
                  vtxMesh = v197;
                  if ( !v21 )
                  {
                    vtxBodyPart = nullptr;
                    do
                    {
                      v198 = (int *)((char *)&vtxBodyPart->numModels + (_DWORD)vtxMesh + vtxMesh->stripGroupHeaderOffset);
                      v199 = (unsigned int)v198 + v198[3] + 2 * v198[2] - (_DWORD)vtxHdr;
                      v200 = (unsigned int)v198 + v198[1] - (_DWORD)vtxHdr;
                      v201 = (unsigned int)v198 + v198[1] + 9 * *v198 - (_DWORD)vtxHdr;
                      if ( (unsigned int)v198 + v198[3] - (_DWORD)vtxHdr < j )
                        j = (int)v198 + v198[3] - (_DWORD)vtxHdr;
                      if ( v199 > vtxOffIndexBufferEnd )
                        vtxOffIndexBufferEnd = v199;
                      if ( v200 < uiSkipVerts )
                        uiSkipVerts = v200;
                      if ( v201 > vtxOffVertexBufferEnd )
                        vtxOffVertexBufferEnd = v201;
                      ppStripInfo = 0;
                      uiNumIndicesInStripGroupUpdate = 0;
                      vvdTangentNew = nullptr;
                      if ( v198[4] > 0 )
                      {
                        memTempVVD.m_p = nullptr;
                        do
                        {
                          v202 = &memTempVVD.m_p[(unsigned int)v198 + v198[5]];
                          _V_memset(dest: &mbk, fill: 0, count: 24);
                          mbk.iBodyPart = uiRunningEdgeDmaInputEnd;
                          mbk.iMesh = vtxMesh_idx;
                          mbk.iModel = iBatchEnda;
                          mbk.iLod = (int)pEdgeTriangleCentroids;
                          mbk.iStripGroup = vtxStrip_idx;
                          mbk.iStrip = (int)vvdTangentNew;
                          _V_memset(&dest, fill: 0, count: 24);
                          _V_memcpy(&dest, src: &mbk, count: 24);
                          iMesh = 0;
                          uiModelIndexOffset = 0;
                          uiStipGroupFilledVerts = 0;
                          v203 = 0;
                          v204 = CUtlRBTree<CUtlMap<ModelBatchKey_t,int,unsigned short>::Node_t,unsigned short,CUtlMap<ModelBatchKey_t,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ModelBatchKey_t,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                                   this: &mapMBI.m_Tree,
                                   search: &dest);
                          v205 = pMsi->m_ps3studioBatches.m_Memory.m_pMemory[mapMBI.m_Tree.m_Elements.m_pMemory[v204].m_Data.elem];
                          v206 = 32 * v205->m_arrPartitions.m_Size;
                          vtxIdx = (unsigned __int16 *)((char *)v198 + 2 * *((_DWORD *)v202 + 1) + v198[3]);
                          *((_DWORD *)v202 + 2) = 0;
                          vtxStrip = nullptr;
                          v207 = v205->m_arrPartitions.m_Size;
                          v208 = 6 * ((v206 + 37) / 6u);
                          v209 = 0;
                          if ( v207 >= 2 )
                          {
                            v210 = v205->m_arrPartitions.m_Memory.m_pMemory;
                            uiRunningOriginalVertexId = ((unsigned int)(v207 - 2) >> 1) + 1;
                            batch = (CMdlStripInfo::Ps3studioBatch_t *)v210;
                            k = 2 * uiRunningOriginalVertexId;
                            do
                            {
                              v203 += *((_DWORD *)batch->m_arrPartitions.m_Memory.m_pMemory + 3);
                              uiModelIndexOffset += *((_DWORD *)batch->m_arrPartitions.m_Memory.m_pMemory + 8);
                              v211 = batch->m_arrPartitions.m_Memory.m_nAllocationCount;
                              v212 = *(_DWORD *)(v211 + 12);
                              v213 = *(_DWORD *)(v211 + 32);
                              iMesh += v212;
                              uiStipGroupFilledVerts += v213;
                              batch = (CMdlStripInfo::Ps3studioBatch_t *)((char *)batch + 8);
                              --uiRunningOriginalVertexId;
                            }
                            while ( uiRunningOriginalVertexId != 0 );
                            v209 = k;
                          }
                          if ( v209 >= v205->m_arrPartitions.m_Size )
                          {
                            v215 = vtxStrip;
                          }
                          else
                          {
                            v214 = v205->m_arrPartitions.m_Memory.m_pMemory[v209];
                            v215 = (OptimizedModel::StripHeader_t *)v214->m_arrLocalIndices.m_Size;
                            ppStripInfo += v214->m_arrVertOriginalIndices.m_Size;
                          }
                          ppStripInfo += uiStipGroupFilledVerts + uiModelIndexOffset;
                          v216 = (unsigned int)v215 + iMesh + v203;
                          uiNumIndicesInStripGroupUpdate += (bEmitIndices ? v216 : 0) + (v208 >> 1);
                          if ( bEmitIndices )
                            v217 = 0;
                          else
                            v217 = 2 * v216;
                          CMemoryMovingTracker::RegisterBytes(this: &vtxMemMove, pos: vtxIdx, length: v208 - v217);
                          memTempVVD.m_p += 35;
                          vvdTangentNew = (Vector4D *)((char *)vvdTangentNew + 1);
                        }
                        while ( (int)vvdTangentNew < v198[4] );
                      }
                      v218 = ppStripInfo;
                      CMemoryMovingTracker::RegisterBytes(
                        this: &vtxMemMove,
                        pos: (char *)v198 + v198[1],
                        length: 9 * (ppStripInfo - *v198));
                      v219 = vtxMesh;
                      vtxBodyPart = (OptimizedModel::BodyPartHeader_t *)((char *)vtxBodyPart + 33);
                      v220 = vtxStrip_idx + 1;
                      v198[2] = uiNumIndicesInStripGroupUpdate;
                      *v198 = v218;
                      vtxStrip_idx = v220;
                    }
                    while ( v220 < v219->numStripGroups );
                  }
                  numCumulativeMeshVertices += 9;
                  ++vtxMesh_idx;
                }
                while ( vtxMesh_idx < *(_DWORD *)mdlModel->name );
              }
              mdlMesh_idx += 12;
              pEdgeTriangleCentroids = (float *)((char *)pEdgeTriangleCentroids + 1);
            }
            while ( (int)pEdgeTriangleCentroids < *(_DWORD *)iOrigVert );
          }
          ++iBatchEnda;
        }
        while ( iBatchEnda < *(_DWORD *)vtxLod_idx );
      }
    }
    v221 = *(_DWORD *)(vtxBuffer + 12);
    NumBytesRegistered = CMemoryMovingTracker::GetNumBytesRegistered(this: &vtxMemMove);
    CUtlBuffer::EnsureCapacity(this: (CUtlBuffer *)vtxBuffer, num: vtxLength + v221 + NumBytesRegistered);
    v223 = *(_DWORD *)(vtxBuffer + 12);
    v224 = CMemoryMovingTracker::GetNumBytesRegistered(this: &vtxMemMove);
    CUtlBuffer::SeekPut(this: (CUtlBuffer *)vtxBuffer, type: SEEK_HEAD, offset: vtxLength + v223 + v224);
    v225 = (int *)(*(_DWORD *)vtxBuffer + *(_DWORD *)(vtxBuffer + 12));
    batcha = (CMdlStripInfo::Ps3studioBatch_t *)v225;
    CMemoryMovingTracker::RegisterBaseDelta(this: &vtxMemMove, pOldBase: vtxHdr, pNewBase: v225);
    CInsertionTracker::Finalize(this: (CMdlLib *)&vtxMemMove);
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_ModelLib, a2: 0) != 0 )
    {
      v226 = CMemoryMovingTracker::GetNumBytesRegistered(this: &vtxMemMove);
      _LoggingSystem_Log(a1: LOG_ModelLib, a2: 0, a3: " Increased VTX size by %d bytes.\n", v226);
    }
    iBatchEndb = 0;
    if ( v225[5] > 0 )
    {
      do
      {
        v227 = (int *)((char *)batcha + 8 * iBatchEndb + batcha->m_uiVhvIndexOffset);
        v228 = 0;
        if ( *v227 > 0 )
        {
          ppStripInfo = 0;
          do
          {
            v229 = (char *)v227 + v227[1] + ppStripInfo;
            v230 = CMemoryMovingTracker::ComputeOffset(this: &vtxMemMove, ptrBase: v229, off: *(_DWORD *)(v229 + 2));
            ppStripInfo += 6;
            ++v228;
            *(_DWORD *)(v229 + 2) = v230;
          }
          while ( v228 < *v227 );
        }
        v227[1] = CMemoryMovingTracker::ComputeOffset(this: &vtxMemMove, ptrBase: v227, off: v227[1]);
        ++iBatchEndb;
      }
      while ( iBatchEndb < (signed int)batcha->m_uiModelIndexOffset );
      v225 = (int *)batcha;
    }
    v21 = v225[7] <= 0;
    uiNumIndicesInStripGroupUpdate = 0;
    if ( !v21 )
    {
      do
      {
        v21 = *(int *)((char *)&batcha->m_arrPartitions.m_Memory.m_pMemory
                     + 8 * uiNumIndicesInStripGroupUpdate
                     + batcha[1].m_arrPartitions.m_Memory.m_nAllocationCount) <= 0;
        memTempVVD.m_p = (unsigned __int8 *)batcha
                       + 8 * uiNumIndicesInStripGroupUpdate
                       + batcha[1].m_arrPartitions.m_Memory.m_nAllocationCount;
        vvdTangentNew = nullptr;
        if ( !v21 )
        {
          do
          {
            v231 = &memTempVVD.m_p[8 * (_DWORD)vvdTangentNew + *((_DWORD *)memTempVVD.m_p + 1)];
            vtxOffVertexBufferEnd = 0;
            v21 = *(_DWORD *)v231 <= 0;
            uiStipGroupFilledVerts = (unsigned int)v231;
            if ( !v21 )
            {
              uiModelIndexOffset = 0;
              do
              {
                v232 = (OptimizedModel::StripHeader_t *)(uiModelIndexOffset
                                                       + uiStipGroupFilledVerts
                                                       + *(_DWORD *)(uiStipGroupFilledVerts + 4));
                uiSkipVerts = 0;
                v21 = v232->numIndices <= 0;
                vtxStrip = v232;
                if ( !v21 )
                {
                  iMesh = 0;
                  do
                  {
                    v233 = (int *)((char *)&v232->numIndices + iMesh + v232->indexOffset);
                    vtxOffIndexBufferEnd = 0;
                    v21 = *v233 <= 0;
                    k = (int)v233;
                    if ( !v21 )
                    {
                      iBatchEndc = 0;
                      do
                      {
                        v234 = (int *)((char *)v233 + iBatchEndc + v233[1]);
                        j = 0;
                        if ( v234[4] > 0 )
                        {
                          ppStripInfo = 0;
                          do
                          {
                            v235 = (int *)((char *)v234 + v234[5] + ppStripInfo);
                            v236 = CMemoryMovingTracker::ComputeOffset(
                                     this: &vtxMemMove,
                                     ptrBase: v234,
                                     off: v234[3] + v235[1]);
                            v237 = CMemoryMovingTracker::ComputeOffset(this: &vtxMemMove, ptrBase: v234, off: v234[3]);
                            v238 = v235[3];
                            v235[1] = v236 - v237;
                            v239 = CMemoryMovingTracker::ComputeOffset(
                                     this: &vtxMemMove,
                                     ptrBase: v234,
                                     off: v234[1] + v238);
                            v240 = CMemoryMovingTracker::ComputeOffset(this: &vtxMemMove, ptrBase: v234, off: v234[1]);
                            v300 = *(_DWORD *)((char *)v235 + 23);
                            v235[3] = v239 - v240;
                            v241 = CMemoryMovingTracker::ComputeOffset(this: &vtxMemMove, ptrBase: v235, off: v300);
                            ppStripInfo += 35;
                            *(_DWORD *)((char *)v235 + 23) = v241;
                            ++j;
                          }
                          while ( j < v234[4] );
                          v233 = (int *)k;
                          v232 = vtxStrip;
                        }
                        v242 = CMemoryMovingTracker::ComputeOffset(this: &vtxMemMove, ptrBase: v234, off: v234[1]);
                        v301 = v234[3];
                        v234[1] = v242;
                        v234[3] = CMemoryMovingTracker::ComputeOffset(this: &vtxMemMove, ptrBase: v234, off: v301);
                        v243 = CMemoryMovingTracker::ComputeOffset(this: &vtxMemMove, ptrBase: v234, off: v234[5]);
                        v302 = *(int *)((char *)v234 + 29);
                        v234[5] = v243;
                        iBatchEndc += 33;
                        *(int *)((char *)v234 + 29) = CMemoryMovingTracker::ComputeOffset(
                                                        this: &vtxMemMove,
                                                        ptrBase: v234,
                                                        off: v302);
                        ++vtxOffIndexBufferEnd;
                      }
                      while ( (int)vtxOffIndexBufferEnd < *v233 );
                    }
                    v244 = CMemoryMovingTracker::ComputeOffset(this: &vtxMemMove, ptrBase: v233, off: v233[1]);
                    iMesh += 9;
                    v233[1] = v244;
                    ++uiSkipVerts;
                  }
                  while ( (signed int)uiSkipVerts < v232->numIndices );
                }
                v245 = CMemoryMovingTracker::ComputeOffset(this: &vtxMemMove, ptrBase: v232, off: v232->indexOffset);
                v246 = (_DWORD *)uiStipGroupFilledVerts;
                uiModelIndexOffset += 12;
                v232->indexOffset = v245;
                ++vtxOffVertexBufferEnd;
              }
              while ( (signed int)vtxOffVertexBufferEnd < *v246 );
            }
            v247 = uiStipGroupFilledVerts;
            v248 = CMemoryMovingTracker::ComputeOffset(
                     this: &vtxMemMove,
                     ptrBase: (void *)uiStipGroupFilledVerts,
                     off: *(_DWORD *)(uiStipGroupFilledVerts + 4));
            m_p = memTempVVD.m_p;
            *(_DWORD *)(v247 + 4) = v248;
            vvdTangentNew = (Vector4D *)((char *)vvdTangentNew + 1);
          }
          while ( (int)vvdTangentNew < *(_DWORD *)m_p );
        }
        v250 = memTempVVD.m_p;
        *((_DWORD *)v250 + 1) = CMemoryMovingTracker::ComputeOffset(
                                  this: &vtxMemMove,
                                  ptrBase: memTempVVD.m_p,
                                  off: *((_DWORD *)memTempVVD.m_p + 1));
        ++uiNumIndicesInStripGroupUpdate;
      }
      while ( (signed int)uiNumIndicesInStripGroupUpdate < (int)batcha[1].m_arrPartitions.m_Memory.m_pMemory );
    }
    batcha->m_uiVhvIndexOffset = CMemoryMovingTracker::ComputeOffset(
                                   this: &vtxMemMove,
                                   ptrBase: batcha,
                                   off: batcha->m_uiVhvIndexOffset);
    batcha[1].m_arrPartitions.m_Memory.m_nAllocationCount = CMemoryMovingTracker::ComputeOffset(
                                                              this: &vtxMemMove,
                                                              ptrBase: batcha,
                                                              off: batcha[1].m_arrPartitions.m_Memory.m_nAllocationCount);
    CMemoryMovingTracker::MemMove(this: &vtxMemMove, ptrBase: batcha, length: &vtxLength);
    CUtlBuffer::SeekPut(this: (CUtlBuffer *)vtxBuffer, type: SEEK_HEAD, offset: vtxLength + *(_DWORD *)(vtxBuffer + 12));
    for ( m = 0; m < 3; ++m )
    {
      *((_BYTE *)&arrTouchedOriginalVerts.m_numInts + m) = m;
      *((_BYTE *)&arrTouchedOriginalVerts.m_iBitStringStorage + m + 2) = 0;
    }
    HIBYTE(arrTouchedOriginalVerts.m_numInts) = 1;
    iPartition = 0;
    vtxModel_idx = 0;
    if ( (int)batcha[1].m_arrPartitions.m_Memory.m_pMemory > 0 )
    {
      vtxModel = nullptr;
      do
      {
        v252 = (char *)vtxModel + mdlHdr->bodypartindex;
        iOrigVert = (int)batcha + 8 * vtxModel_idx + batcha[1].m_arrPartitions.m_Memory.m_nAllocationCount;
        v21 = *(_DWORD *)iOrigVert <= 0;
        k = (int)&v252[(_DWORD)mdlHdr];
        vtxLod_idx = 0;
        if ( !v21 )
        {
          vtxStripGroup = nullptr;
          do
          {
            numCumulativeMeshVertices = *(_DWORD *)(iOrigVert + 4) + iOrigVert + 8 * vtxLod_idx;
            mdlModel = (mstudiomodel_t *)((char *)vtxStripGroup + k + *(_DWORD *)(k + 12));
            uiRunningOriginalVertexId = 0;
            mdlMesh_idx = 0;
            if ( mdlModel->nummeshes > 0 )
            {
              vtxStripGroup_idx = 0;
              pEdgeTriangleCentroids = nullptr;
              do
              {
                v253 = &mdlModel->name[mdlModel->meshindex + (_DWORD)pEdgeTriangleCentroids];
                vtxBodyPart = nullptr;
                iMesh = (unsigned int)v253;
                if ( *(int *)numCumulativeMeshVertices > 0 )
                {
                  vtxMesh_idx = 0;
                  do
                  {
                    v254 = (int *)(*(_DWORD *)(numCumulativeMeshVertices + 4) + numCumulativeMeshVertices + vtxMesh_idx);
                    if ( *v254 > mdlMesh_idx )
                    {
                      v255 = (OptimizedModel::MeshHeader_t *)((char *)v254 + v254[1] + vtxStripGroup_idx);
                      uiNumIndicesInStripGroupUpdate = 0;
                      v21 = v255->numStripGroups <= 0;
                      vtxMesh = v255;
                      if ( !v21 )
                      {
                        vtxStrip_idx = 0;
                        do
                        {
                          v256 = nullptr;
                          iBatchEndd = (unsigned int)vtxMesh + vtxStrip_idx + vtxMesh->stripGroupHeaderOffset;
                          uiStipGroupFilledVerts = 0;
                          uiRunningEdgeDmaInputEnd = iPartition;
                          memset(&arrGroupMarkups, 0, sizeof(arrGroupMarkups));
                          vvdTangentNew = nullptr;
                          if ( *(int *)(iBatchEndd + 16) > 0 )
                          {
                            memTempVVD.m_p = nullptr;
                            do
                            {
                              vtxStrip = (OptimizedModel::StripHeader_t *)&memTempVVD.m_p[iBatchEndd
                                                                                        + *(_DWORD *)(iBatchEndd + 20)];
                              v257 = vtxStrip;
                              _V_memset(dest: &mbk, fill: 0, count: 24);
                              mbk.iBodyPart = vtxModel_idx;
                              mbk.iMesh = mdlMesh_idx;
                              mbk.iModel = vtxLod_idx;
                              mbk.iLod = (int)vtxBodyPart;
                              mbk.iStripGroup = uiNumIndicesInStripGroupUpdate;
                              mbk.iStrip = (int)vvdTangentNew;
                              _V_memset(&dest, fill: 0, count: 24);
                              _V_memcpy(&dest, src: &mbk, count: 24);
                              v258 = CUtlRBTree<CUtlMap<ModelBatchKey_t,int,unsigned short>::Node_t,unsigned short,CUtlMap<ModelBatchKey_t,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ModelBatchKey_t,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                                       this: &mapMBI.m_Tree,
                                       search: &dest);
                              v259 = pMsi->m_ps3studioBatches.m_Memory.m_pMemory[mapMBI.m_Tree.m_Elements.m_pMemory[v258].m_Data.elem];
                              v260 = *(_DWORD *)(iBatchEndd + 12) + iBatchEndd + 2 * v257->indexOffset;
                              v261 = 6 * ((32 * v259->m_arrPartitions.m_Size + 37) / 6u);
                              ppStripInfo = v260;
                              CUtlVector<OptimizedModel::OptimizedIndexBufferMarkupPs3_t *,CUtlMemory<OptimizedModel::OptimizedIndexBufferMarkupPs3_t *,int>>::InsertBefore(
                                this: &arrGroupMarkups,
                                elem: arrGroupMarkups.m_Size,
                                src: (OptimizedModel::OptimizedIndexBufferMarkupPs3_t *const *)&ppStripInfo);
                              *(_DWORD *)v260 = -65538;
                              *(_DWORD *)(v260 + 4) = -65538;
                              *(_WORD *)(v260 + 8) = 1;
                              *(_WORD *)(v260 + 10) = v261;
                              v262 = 0;
                              *(_DWORD *)(v260 + 12) = v259->m_arrPartitions.m_Size;
                              *(_DWORD *)(v260 + 16) = 0;
                              *(_DWORD *)(v260 + 20) = 0;
                              ppStripInfo = v261 >> 1;
                              v263 = 0;
                              *(_DWORD *)(v260 + 24) = iPartition;
                              *(_DWORD *)(v260 + 28) = 0;
                              uiSkipVerts = 0;
                              vtxOffVertexBufferEnd = 0;
                              if ( v259->m_arrPartitions.m_Size > 0 )
                              {
                                v264 = (unsigned int *)(v260 + 36);
                                do
                                {
                                  v265 = v259->m_arrPartitions.m_Memory.m_pMemory[v262];
                                  *(v264 - 1) = ppStripInfo;
                                  *v264 = v263;
                                  v264[1] = v265->m_nIoBufferSize;
                                  v264[2] = v265->m_arrLocalIndices.m_Size;
                                  v264[3] = v265->m_arrVertOriginalIndices.m_Size;
                                  m_nEdgeDmaInputIdx = iPartition;
                                  if ( uiRunningEdgeDmaInputEnd == iPartition )
                                  {
                                    m_nEdgeDmaInputIdx = v265->m_nEdgeDmaInputIdx;
                                    iPartition = m_nEdgeDmaInputIdx;
                                    *(_DWORD *)(v260 + 24) = m_nEdgeDmaInputIdx;
                                  }
                                  v264[4] = v265->m_nEdgeDmaInputIdx - m_nEdgeDmaInputIdx;
                                  v264[5] = v265->m_nEdgeDmaInputVtx - m_nEdgeDmaInputIdx;
                                  v264[6] = v265->m_nEdgeDmaInputEnd - m_nEdgeDmaInputIdx;
                                  uiRunningEdgeDmaInputEnd = v265->m_nEdgeDmaInputEnd;
                                  *(_DWORD *)(v260 + 16) += v264[2];
                                  *(_DWORD *)(v260 + 20) += v264[3];
                                  if ( bEmitIndices )
                                  {
                                    v267 = 0;
                                    j = 0;
                                    if ( v265->m_arrLocalIndices.m_Size > 0 )
                                    {
                                      vtxOffIndexBufferEnd = v260 + 2 * ppStripInfo;
                                      do
                                      {
                                        v268 = vtxOffIndexBufferEnd;
                                        *(_WORD *)vtxOffIndexBufferEnd = v265->m_arrLocalIndices.m_Memory.m_pMemory[v267];
                                        v267 = j + 1;
                                        j = v267;
                                        vtxOffIndexBufferEnd = v268 + 2;
                                      }
                                      while ( v267 < v265->m_arrLocalIndices.m_Size );
                                    }
                                    ppStripInfo += v265->m_arrLocalIndices.m_Size;
                                  }
                                  v263 = v265->m_arrVertOriginalIndices.m_Size + uiSkipVerts;
                                  v262 = vtxOffVertexBufferEnd + 1;
                                  v264 += 8;
                                  uiSkipVerts = v263;
                                  vtxOffVertexBufferEnd = v262;
                                }
                                while ( v262 < v259->m_arrPartitions.m_Size );
                              }
                              vtxStrip->numIndices = ppStripInfo;
                              v269 = *(_DWORD *)iBatchEndd;
                              HIBYTE(ppStripInfo) = 0;
                              if ( v263 > v269 )
                              {
                                v303 = v269;
                                v270 = studiohdr_t::pszName(this: mdlHdr);
                                _Warning(a1: "WARNING: %s: VTX strip group overflow %d/%d\n", v270, v263, v303);
                                HIBYTE(ppStripInfo) = 1;
                              }
                              if ( v263 != 0 )
                              {
                                v271 = iMesh;
                                v272 = uiRunningOriginalVertexId;
                                uiModelIndexOffset = 9 * uiStipGroupFilledVerts;
                                for ( j = v263; j != 0; --j )
                                {
                                  v273 = v272 - *(_WORD *)(v271 + 12);
                                  LOWORD(arrTouchedOriginalVerts.m_iBitStringStorage) = v273;
                                  if ( HIBYTE(ppStripInfo) == 0 )
                                  {
                                    v274 = *(_DWORD *)(v271 + 12);
                                    if ( v272 < v274
                                      || (v271 = iMesh, v273 != v272 - v274)
                                      || *(_DWORD *)(iMesh + 8) <= (int)v273 )
                                    {
                                      v304 = *(_DWORD *)(v271 + 8);
                                      v296 = v273;
                                      v293 = v274;
                                      v275 = studiohdr_t::pszName(this: mdlHdr);
                                      _Warning(
                                        a1: "WARNING: %s: VTX vertex indirection overflow id=%d, off=%d, idx=%d/%d\n",
                                        v275,
                                        v272,
                                        v293,
                                        v296,
                                        v304);
                                      HIBYTE(ppStripInfo) = 1;
                                    }
                                  }
                                  ++v272;
                                  _V_memcpy(
                                    dest: (void *)(uiModelIndexOffset + iBatchEndd + *(_DWORD *)(iBatchEndd + 4)),
                                    src: &arrTouchedOriginalVerts.m_numInts,
                                    count: 9);
                                  uiModelIndexOffset += 9;
                                }
                                uiRunningOriginalVertexId = v272;
                              }
                              uiStipGroupFilledVerts += v263;
                              memTempVVD.m_p += 35;
                              vvdTangentNew = (Vector4D *)((char *)vvdTangentNew + 1);
                            }
                            while ( (int)vvdTangentNew < *(_DWORD *)(iBatchEndd + 16) );
                            v256 = arrGroupMarkups.m_Memory.m_pMemory;
                          }
                          v276 = 0;
                          if ( arrGroupMarkups.m_Size > 0 )
                          {
                            v277 = uiRunningEdgeDmaInputEnd - iPartition;
                            do
                            {
                              v256[v276]->m_nEdgeDmaInputSizePerStripGroup = v277;
                              Helper_SwapOptimizedIndexBufferMarkup_forPs3(pMarkup: v256[v276++]);
                            }
                            while ( v276 < arrGroupMarkups.m_Size );
                          }
                          iPartition = uiRunningEdgeDmaInputEnd;
                          CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::~CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>(this: (CUtlVector<CMdlStripInfo::MdlRangeItem,CUtlMemory<CMdlStripInfo::MdlRangeItem,int> > *)&arrGroupMarkups);
                          vtxStrip_idx += 33;
                          ++uiNumIndicesInStripGroupUpdate;
                        }
                        while ( (signed int)uiNumIndicesInStripGroupUpdate < vtxMesh->numStripGroups );
                      }
                    }
                    vtxMesh_idx += 12;
                    vtxBodyPart = (OptimizedModel::BodyPartHeader_t *)((char *)vtxBodyPart + 1);
                  }
                  while ( (int)vtxBodyPart < *(_DWORD *)numCumulativeMeshVertices );
                }
                pEdgeTriangleCentroids += 29;
                vtxStripGroup_idx += 9;
                ++mdlMesh_idx;
              }
              while ( mdlMesh_idx < mdlModel->nummeshes );
            }
            vtxStripGroup = (OptimizedModel::StripGroupHeader_t *)((char *)vtxStripGroup + 148);
            ++vtxLod_idx;
          }
          while ( vtxLod_idx < *(_DWORD *)iOrigVert );
        }
        vtxModel += 2;
        ++vtxModel_idx;
      }
      while ( vtxModel_idx < (int)batcha[1].m_arrPartitions.m_Memory.m_pMemory );
    }
    memset(&arrTouchedOriginalVerts, 0, sizeof(arrTouchedOriginalVerts));
    iMesh = 0;
    for ( ppStripInfo = 0; iMesh < pMsi->m_ps3studioStripGroupHeaderBatchOffset.m_Size; ++iMesh )
    {
      if ( iMesh >= pMsi->m_ps3studioStripGroupHeaderBatchOffset.m_Size - 1 )
        v278 = pMsi->m_ps3studioBatches.m_Size;
      else
        v278 = pMsi->m_ps3studioStripGroupHeaderBatchOffset.m_Memory.m_pMemory[iMesh + 1];
      iBatchEnde = v278;
      if ( v278 >= pMsi->m_ps3studioBatches.m_Size )
      {
        v278 = pMsi->m_ps3studioBatches.m_Size;
        iBatchEnde = v278;
      }
      if ( ppStripInfo < v278 )
      {
        do
        {
          batchb = pMsi->m_ps3studioBatches.m_Memory.m_pMemory[ppStripInfo];
          for ( iPartitiona = 0; iPartitiona < batchb->m_arrPartitions.m_Size; ++iPartitiona )
          {
            v279 = batchb->m_arrPartitions.m_Memory.m_pMemory[iPartitiona];
            for ( n = 0;
                  n < v279->m_arrVertOriginalIndices.m_Size;
                  arrTouchedOriginalVerts.m_pInt[v281 >> 5] |= 1 << (v281 & 0x1F) )
            {
              v281 = batchb->m_uiVhvIndexOffset + v279->m_arrStripLocalOriginalIndices.m_Memory.m_pMemory[n];
              if ( v281 >= arrTouchedOriginalVerts.m_numBits )
                CVarBitVecBase<int>::Resize(this: &arrTouchedOriginalVerts, resizeNumBits: v281 + 1, bClearAll: false);
              ++n;
            }
          }
          ++ppStripInfo;
        }
        while ( ppStripInfo < iBatchEnde );
      }
    }
    if ( arrTouchedOriginalVerts.m_numBits == numVhvOriginalModelVertices )
    {
      v282 = 0;
      if ( numVhvOriginalModelVertices != 0 )
      {
        while ( v282 < arrTouchedOriginalVerts.m_numBits
             && ((1 << (v282 & 0x1F)) & arrTouchedOriginalVerts.m_pInt[v282 >> 5]) != 0 )
        {
          if ( ++v282 >= numVhvOriginalModelVertices )
            goto LABEL_409;
        }
        studiohdr2index = mdlHdr->studiohdr2index;
        if ( studiohdr2index != 0
          && (v284 = *(_DWORD *)&mdlHdr->name[studiohdr2index + 8], v285 = (char *)mdlHdr + studiohdr2index, v284 != 0)
          && &v285[v284] != nullptr )
        {
          v286 = *((_DWORD *)v285 + 5);
          if ( v286 != 0 )
            v294 = &v285[v286];
          else
            v294 = nullptr;
          _Warning(a1: "WARNING: %s: VHV source vertex %d/%d skipped\n", v294, v282, numVhvOriginalModelVertices);
        }
        else
        {
          _Warning(
            a1: "WARNING: %s: VHV source vertex %d/%d skipped\n",
            mdlHdr->name,
            v282,
            numVhvOriginalModelVertices);
        }
      }
    }
    else
    {
      v287 = mdlHdr->studiohdr2index;
      if ( v287 != 0
        && (v288 = *(_DWORD *)&mdlHdr->name[v287 + 8], v289 = (char *)mdlHdr + v287, v288 != 0)
        && &v289[v288] != nullptr )
      {
        v290 = *((_DWORD *)v289 + 5);
        if ( v290 != 0 )
          name = &v289[v290];
        else
          name = nullptr;
      }
      else
      {
        name = mdlHdr->name;
      }
      _Warning(
        a1: "WARNING: %s: VHV expected vertex count mismatch %d!=%d\n",
        name,
        arrTouchedOriginalVerts.m_numBits,
        numVhvOriginalModelVertices);
    }
LABEL_409:
    if ( arrTouchedOriginalVerts.m_numInts > 1 )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: arrTouchedOriginalVerts.m_pInt);
    CUtlRBTree<CUtlMap<unsigned char *,int,unsigned int>::Node_t,unsigned int,CUtlMap<unsigned char *,int,unsigned int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned char *,int,unsigned int>::Node_t,unsigned int>,unsigned int>>::~CUtlRBTree<CUtlMap<unsigned char *,int,unsigned int>::Node_t,unsigned int,CUtlMap<unsigned char *,int,unsigned int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned char *,int,unsigned int>::Node_t,unsigned int>,unsigned int>>(this: &vtxMemMove.m_map.m_Tree);
    CUtlRBTree<CUtlMap<ModelBatchKey_t,int,unsigned short>::Node_t,unsigned short,CUtlMap<ModelBatchKey_t,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ModelBatchKey_t,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<ModelBatchKey_t,int,unsigned short>::Node_t,unsigned short,CUtlMap<ModelBatchKey_t,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<ModelBatchKey_t,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &mapMBI.m_Tree);
    CMdlLib::PrepareModelForPs3_::_31_::EdgeGeomFreeMemoryTracker_t::_EdgeGeomFreeMemoryTracker_t(this: v292);
    msi.__vftable = (CMdlStripInfo_vtbl *)&CMdlStripInfo::`vftable';
    CUtlVector<CMdlStripInfo::Ps3studioBatch_t *,CUtlMemory<CMdlStripInfo::Ps3studioBatch_t *,int>>::PurgeAndDeleteElements(this: &msi.m_ps3studioBatches);
    CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::~CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>(this: &msi.m_vtxMdlOffsets);
    CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::~CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>(this: (CUtlVector<CMdlStripInfo::MdlRangeItem,CUtlMemory<CMdlStripInfo::MdlRangeItem,int> > *)&msi.m_ps3studioStripGroupHeaderBatchOffset);
    CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::~CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>(this: (CUtlVector<CMdlStripInfo::MdlRangeItem,CUtlMemory<CMdlStripInfo::MdlRangeItem,int> > *)&msi.m_ps3studioBatches);
    CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::~CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>(this: (CUtlVector<CMdlStripInfo::MdlRangeItem,CUtlMemory<CMdlStripInfo::MdlRangeItem,int> > *)&msi.m_vtxIndices);
    if ( msi.m_vtxVerts.m_numInts > 1 )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: msi.m_vtxVerts.m_pInt);
    return 1;
  }
  else
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_ModelLib, a2: 0) != 0 )
      _LoggingSystem_Log(a1: LOG_ModelLib, a2: 0, a3: "ERROR: [PrepareModelForPs3] checksum mismatch!\n");
    return 0;
  }
}
