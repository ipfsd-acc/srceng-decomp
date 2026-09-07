// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mdllib/mdllib_stripmodel.cpp
// Functions: 11
// ============================================================

#include "mdllib\mdllib_stripmodel.h"

//------------------------------------------------------------------------------
// Address: 0x100023C0
// Name: _CMdlLib::PrepareModelForPs3_::_31_::EdgeGeomFreeMemoryTracker_t::_EdgeGeomFreeMemoryTracker_t
// Source: json
//------------------------------------------------------------------------------
void __usercall CMdlLib::PrepareModelForPs3_::_31_::EdgeGeomFreeMemoryTracker_t::_EdgeGeomFreeMemoryTracker_t(
        CMdlLib::PrepareModelForPs3::__l31::EdgeGeomFreeMemoryTracker_t *this@<ecx>,
        int a2@<esi>)
{
  int i; // edi
  const VectorByValue *v3; // eax
  bool v4; // sf
  void *v5; // eax

  for ( i = 0; i < *(_DWORD *)(a2 + 12); ++i )
  {
    v3 = *(const VectorByValue **)(*(_DWORD *)a2 + 4 * i);
    if ( v3 != nullptr )
      edgeGeomFreeEx((VectorByValue *)this, a2: v3);
  }
  v4 = *(int *)(a2 + 8) < 0;
  *(_DWORD *)(a2 + 12) = 0;
  if ( !v4 )
  {
    if ( *(_DWORD *)a2 != 0 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)a2);
      *(_DWORD *)a2 = 0;
    }
    *(_DWORD *)(a2 + 4) = 0;
  }
  v4 = *(int *)(a2 + 8) < 0;
  v5 = *(void **)a2;
  *(_DWORD *)(a2 + 16) = *(_DWORD *)a2;
  if ( !v4 )
  {
    if ( v5 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
      *(_DWORD *)a2 = 0;
    }
    *(_DWORD *)(a2 + 4) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005340
// Name: public: int CUtlSortVector<unsigned short,class CLessSimple<unsigned short>>::Find(unsigned short const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<unsigned short,CLessSimple<unsigned short>>::Find(
        CUtlSortVector<unsigned short,CLessSimple<unsigned short> > *this,
        unsigned __int16 *src)
{
  int v3; // esi
  int v4; // ecx
  unsigned __int16 *m_pMemory; // ebx
  unsigned __int16 v6; // di
  int result; // eax
  unsigned __int16 v8; // dx

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1\\UtlSortVector.h",
         215,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1\\UtlSortVector.h",
                            a2: 215,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1\\UtlSortVector.h",
      a2: 215);
  }
  v3 = 0;
  v4 = this->m_Size - 1;
  if ( v4 >= 0 )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = *src;
    do
    {
      result = (v4 + v3) >> 1;
      v8 = m_pMemory[result];
      if ( v6 <= v8 )
      {
        if ( v6 >= v8 )
          return result;
        v4 = result - 1;
      }
      else
      {
        v3 = result + 1;
      }
    }
    while ( v3 <= v4 );
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x100053F0
// Name: public: int CUtlSortVector<unsigned short,class CLessSimple<unsigned short>>::FindLess(unsigned short const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<unsigned short,CLessSimple<unsigned short>>::FindLess(
        CUtlSortVector<unsigned short,CLessSimple<unsigned short> > *this,
        const unsigned __int16 *src)
{
  int v3; // edx
  int result; // eax
  unsigned __int16 *m_pMemory; // esi
  int v6; // ecx

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1\\UtlSortVector.h",
         303,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1\\UtlSortVector.h",
                            a2: 303,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1\\UtlSortVector.h",
      a2: 303);
  }
  v3 = 0;
  result = this->m_Size - 1;
  if ( result >= 0 )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    do
    {
      v6 = (result + v3) >> 1;
      if ( m_pMemory[v6] >= *src )
        result = v6 - 1;
      else
        v3 = v6 + 1;
    }
    while ( v3 <= result );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10005490
// Name: public: int CUtlSortVector<struct CMdlStripInfo::MdlRangeItem,class CLessSimple<struct CMdlStripInfo::MdlRangeItem>>::FindLessOrEqual(struct CMdlStripInfo::MdlRangeItem const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<CMdlStripInfo::MdlRangeItem,CLessSimple<CMdlStripInfo::MdlRangeItem>>::FindLessOrEqual(
        CUtlSortVector<CMdlStripInfo::MdlRangeItem,CLessSimple<CMdlStripInfo::MdlRangeItem> > *this,
        const CMdlStripInfo::MdlRangeItem *src)
{
  int v3; // esi
  int v4; // ecx
  CMdlStripInfo::MdlRangeItem *m_pMemory; // ebx
  int m_offNew; // edi
  int result; // eax
  int v8; // edx

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1\\UtlSortVector.h",
         277,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1\\UtlSortVector.h",
                            a2: 277,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1\\UtlSortVector.h",
      a2: 277);
  }
  v3 = 0;
  v4 = this->m_Size - 1;
  if ( v4 >= 0 )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    m_offNew = src->m_offNew;
    do
    {
      result = (v4 + v3) >> 1;
      v8 = m_pMemory[result].m_offNew;
      if ( m_offNew <= v8 )
      {
        if ( m_offNew >= v8 )
          return result;
        v4 = result - 1;
      }
      else
      {
        v3 = result + 1;
      }
    }
    while ( v3 <= v4 );
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10008290
// Name: public: virtual bool CMdlLib::CreateNewStripInfo(class IMdlStripInfo __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMdlLib::CreateNewStripInfo(CMdlLib *this, IMdlStripInfo **ppStripInfo)
{
  CMdlStripInfo *v3; // eax
  CMdlStripInfo *v4; // eax

  if ( ppStripInfo == nullptr )
    return false;
  if ( *ppStripInfo != nullptr )
  {
    CMdlStripInfo::Reset(this: (CMdlStripInfo *)*ppStripInfo);
    return true;
  }
  else
  {
    v3 = (CMdlStripInfo *)operator new(nSize: 0x80u);
    if ( v3 != nullptr )
    {
      v4 = CMdlStripInfo::CMdlStripInfo(this: v3);
      *ppStripInfo = v4;
      return v4 != nullptr;
    }
    else
    {
      *ppStripInfo = nullptr;
      return false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100082F0
// Name: protected: static int CUtlSortVector<unsigned short,class CLessSimple<unsigned short>>::CompareHelper(void __near *,unsigned short const __near *,unsigned short const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CUtlSortVector<unsigned short,CLessSimple<unsigned short>>::CompareHelper(
        void *context,
        const unsigned __int16 *lhs,
        const unsigned __int16 *rhs)
{
  if ( *rhs <= *lhs )
    return *rhs < *lhs;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10008310
// Name: public: int CVarBitVecBase<int>::FindNextSetBit(int)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CVarBitVecBase<int>::FindNextSetBit(CVarBitVecBase<int> *this, int startBit)
{
  int v2; // esi
  int v3; // eax
  int v4; // edx
  int v5; // edi
  unsigned int *m_pInt; // ebx
  unsigned int v7; // ecx
  unsigned int v8; // ecx
  unsigned int v10; // edx
  int v11; // eax
  unsigned int *v12; // ecx
  unsigned int v13; // eax
  unsigned int *v14; // ecx
  unsigned int v15; // esi
  unsigned int *v16; // ecx
  unsigned int v17; // edx

  if ( startBit >= this->m_numBits )
    return -1;
  v2 = `GetStartBitMask'::`2'::g_StartMask[startBit & 0x1F];
  v3 = startBit >> 5;
  v4 = this->m_numInts - 1;
  v5 = this->m_numBits % 32;
  if ( v5 != 0 )
  {
    m_pInt = this->m_pInt;
    v7 = v2 & m_pInt[v3];
    if ( v3 == v4 )
    {
      v8 = `GetEndMask'::`2'::bitStringEndMasks[v5] & v7;
      if ( v8 != 0 )
      {
        _BitScanForward(&v8, v8);
        return v8 + 32 * v3;
      }
      return -1;
    }
    if ( v7 != 0 )
    {
      _BitScanForward(&v10, v7);
      return v10 + 32 * v3;
    }
    v11 = v3 + 1;
    if ( v11 >= v4 )
    {
LABEL_12:
      if ( (`GetEndMask'::`2'::bitStringEndMasks[v5] & m_pInt[v4]) != 0 )
      {
        _BitScanForward(&v13, `GetEndMask'::`2'::bitStringEndMasks[v5] & m_pInt[v4]);
        return v13 + 32 * v4;
      }
      return -1;
    }
    v12 = &m_pInt[v11];
    while ( *v12 == 0 )
    {
      ++v11;
      ++v12;
      if ( v11 >= v4 )
        goto LABEL_12;
    }
    _BitScanForward((unsigned int *)&v12, *v12);
    return (unsigned int)&v12[8 * v11];
  }
  else
  {
    v14 = this->m_pInt;
    v15 = v14[v3] & v2;
    v16 = &v14[v3];
    while ( v15 == 0 )
    {
      v15 = v16[1];
      ++v16;
      if ( ++v3 > v4 )
        return -1;
    }
    _BitScanForward(&v17, v15);
    return v17 + 32 * v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008410
// Name: public: void CUtlMemory<struct MdlLib::MdlVertex,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<MdlLib::MdlVertex,int>::Grow(CUtlMemory<MdlLib::MdlVertex,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  MdlLib::MdlVertex *m_pMemory; // edx
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
    v7 = 32 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (MdlLib::MdlVertex *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (MdlLib::MdlVertex *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100084A0
// Name: public: int CUtlSortVector<struct CMdlStripInfo::MdlRangeItem,class CLessSimple<struct CMdlStripInfo::MdlRangeItem>>::Insert(struct CMdlStripInfo::MdlRangeItem const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<CMdlStripInfo::MdlRangeItem,CLessSimple<CMdlStripInfo::MdlRangeItem>>::Insert(
        CUtlSortVector<CMdlStripInfo::MdlRangeItem,CLessSimple<CMdlStripInfo::MdlRangeItem> > *this,
        const CMdlStripInfo::MdlRangeItem *src)
{
  int LessOrEqual; // eax
  int m_nAllocationCount; // ecx
  int v5; // edi
  int m_Size; // eax
  CMdlStripInfo::MdlRangeItem *m_pMemory; // ecx
  int v8; // eax
  CMdlStripInfo::MdlRangeItem *v9; // eax

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1\\UtlSortVector.h",
         150,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1\\UtlSortVector.h",
                            a2: 150,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1\\UtlSortVector.h",
      a2: 150);
  }
  LessOrEqual = CUtlSortVector<CMdlStripInfo::MdlRangeItem,CLessSimple<CMdlStripInfo::MdlRangeItem>>::FindLessOrEqual(
                  this,
                  src);
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  v5 = LessOrEqual + 1;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CMdlStripInfo::MdlRangeItem,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size - v5 - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[v5 + 1], src: &m_pMemory[v5], count: 16 * v8);
  v9 = &this->m_Memory.m_pMemory[v5];
  if ( v9 != nullptr )
    *v9 = *src;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10008580
// Name: public: virtual bool CMdlLib::ParseMdlMesh(class CUtlBuffer __near &,class CUtlBuffer __near &,class CUtlBuffer __near &,struct MdlLib::MdlMesh __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMdlLib::ParseMdlMesh(
        CMdlLib *this,
        int mdlBuffer,
        vertexFileHeader_t *vvdBuffer,
        int vtxBuffer,
        Vector4D *mesh)
{
  int numLODs; // ecx
  unsigned __int8 *v6; // ebx
  unsigned __int8 *v7; // edi
  unsigned __int8 *m_p; // ecx
  unsigned int v9; // eax
  unsigned __int8 *v11; // edx
  int v12; // esi
  int v13; // ecx
  int *v14; // eax
  int v15; // ebx
  int v16; // eax
  OptimizedModel::BodyPartHeader_t *v17; // edx
  mstudiobodyparts_t *v18; // ecx
  int v19; // eax
  mstudiomodel_t *v20; // ebx
  OptimizedModel::ModelLODHeader_t *v21; // ecx
  int v22; // edx
  OptimizedModel::MeshHeader_t *v23; // eax
  int v24; // edx
  _DWORD *v25; // edi
  OptimizedModel::StripHeader_t *v26; // edx
  int x_low; // ebx
  int z_low; // eax
  unsigned int *y_low; // ecx
  int v30; // eax
  unsigned int *v31; // ebx
  int v33; // eax
  unsigned __int8 *v34; // esi
  unsigned __int8 *v35; // eax
  vertexFileHeader_t *v36; // ecx
  unsigned __int8 *v37; // edi
  _DWORD *v38; // esi
  unsigned __int8 *v39; // edi
  int v40; // esi
  int w_low; // eax
  MdlLib::MdlVertex *v42; // ecx
  int v43; // eax
  MdlLib::MdlVertex *v44; // esi
  __int64 vert; // [esp+8h] [ebp-78h]
  __int64 vert_8; // [esp+10h] [ebp-70h]
  __int64 vert_16; // [esp+18h] [ebp-68h]
  __int64 vert_24; // [esp+20h] [ebp-60h]
  unsigned int vvdLength; // [esp+28h] [ebp-58h]
  OptimizedModel::BodyPartHeader_t *vtxBodyPart; // [esp+2Ch] [ebp-54h]
  OptimizedModel::MeshHeader_t *vtxMesh; // [esp+30h] [ebp-50h]
  OptimizedModel::ModelLODHeader_t *vtxLod; // [esp+34h] [ebp-4Ch]
  unsigned int v53; // [esp+38h] [ebp-48h]
  mstudiomesh_t *mdlMesh; // [esp+3Ch] [ebp-44h]
  int k; // [esp+40h] [ebp-40h]
  int ka; // [esp+40h] [ebp-40h]
  mstudiovertex_t *vvdVertexSrc; // [esp+44h] [ebp-3Ch]
  mstudiovertex_t *vvdVertexSrca; // [esp+44h] [ebp-3Ch]
  int vtxMesh_idx; // [esp+48h] [ebp-38h]
  int vtxStripGroup_idx; // [esp+4Ch] [ebp-34h]
  mstudiomodel_t *mdlModel; // [esp+50h] [ebp-30h]
  int v62; // [esp+54h] [ebp-2Ch]
  int vtxStrip_idx; // [esp+58h] [ebp-28h]
  OptimizedModel::StripHeader_t *vtxStrip; // [esp+5Ch] [ebp-24h]
  mstudiobodyparts_t *mdlBodyPart; // [esp+60h] [ebp-20h]
  CArrayAutoPtr<unsigned char> memTempVVD; // [esp+64h] [ebp-1Ch]
  CArrayAutoPtr<unsigned char> memTempVVDa; // [esp+64h] [ebp-1Ch]
  int v68; // [esp+68h] [ebp-18h]
  int v69; // [esp+6Ch] [ebp-14h]
  int vtxModel_idx; // [esp+70h] [ebp-10h]
  int v71; // [esp+74h] [ebp-Ch]
  int v72; // [esp+78h] [ebp-8h]
  int v73; // [esp+7Ch] [ebp-4h]
  int mdlNumVertices; // [esp+88h] [ebp+8h]
  vertexFileHeader_t *vvdHdr; // [esp+8Ch] [ebp+Ch]
  int i; // [esp+90h] [ebp+10h]
  unsigned __int8 *ia; // [esp+90h] [ebp+10h]
  unsigned __int8 *vvdTangentNew; // [esp+94h] [ebp+14h]
  Vector4D *vvdTangentNewa; // [esp+94h] [ebp+14h]

  numLODs = vvdBuffer->numLODs;
  vvdLength = vvdBuffer->numLODVertexes[0] - numLODs;
  v6 = (unsigned __int8 *)(*(_DWORD *)mdlBuffer + *(_DWORD *)(mdlBuffer + 12));
  v7 = (unsigned __int8 *)(numLODs + vvdBuffer->id);
  m_p = (unsigned __int8 *)(*(_DWORD *)vtxBuffer + *(_DWORD *)(vtxBuffer + 12));
  v9 = *((_DWORD *)v6 + 2);
  vvdVertexSrc = (mstudiovertex_t *)v6;
  vvdHdr = (vertexFileHeader_t *)v7;
  memTempVVD.m_p = m_p;
  if ( v9 != *((_DWORD *)v7 + 2) || v9 != *((_DWORD *)m_p + 4) )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_ModelLib, a2: 0) != 0 )
      _LoggingSystem_Log(a1: LOG_ModelLib, a2: 0, a3: "ERROR: [ParseMdlMesh] checksum mismatch!\n");
    return 0;
  }
  if ( *((_DWORD *)v7 + 3) != 1 )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_ModelLib, a2: 0) != 0 )
    {
      _LoggingSystem_Log(
        a1: LOG_ModelLib,
        a2: 0,
        a3: "ERROR: [ParseMdlMesh] the model has %d lod(s).\n",
        *((_DWORD *)v7 + 3));
      return 0;
    }
    return 0;
  }
  LODWORD(mesh->x) = v9;
  mdlNumVertices = 0;
  if ( *((int *)v6 + 58) > 0 )
  {
    v11 = &v6[*((_DWORD *)v6 + 59) + 12];
    v12 = *((_DWORD *)v6 + 58);
    do
    {
      v13 = *((_DWORD *)v11 - 2);
      if ( v13 > 0 )
      {
        v14 = (int *)&v11[*(_DWORD *)v11 + 68];
        do
        {
          v15 = *v14;
          v14 += 37;
          --v13;
          mdlNumVertices = v15;
        }
        while ( v13 != 0 );
      }
      v11 += 16;
      --v12;
    }
    while ( v12 != 0 );
    v6 = (unsigned __int8 *)vvdVertexSrc;
    m_p = memTempVVD.m_p;
  }
  v16 = 0;
  mesh[1].x = 0.0;
  k = 0;
  if ( *((int *)m_p + 7) > 0 )
  {
    v68 = 0;
    do
    {
      v17 = (OptimizedModel::BodyPartHeader_t *)&m_p[8 * v16 + *((_DWORD *)m_p + 8)];
      vtxBodyPart = v17;
      v18 = (mstudiobodyparts_t *)&v6[v68 + *((_DWORD *)v6 + 59)];
      mdlBodyPart = v18;
      vtxModel_idx = 0;
      if ( v17->numModels > 0 )
      {
        v69 = 0;
        while ( 1 )
        {
          v19 = (int)&v17[vtxModel_idx] + v17->modelOffset;
          v20 = (mstudiomodel_t *)((char *)mdlBodyPart + v69 + v18->modelindex);
          v21 = (OptimizedModel::ModelLODHeader_t *)(v19 + *(_DWORD *)(v19 + 4));
          mdlModel = v20;
          vtxLod = v21;
          vtxMesh_idx = 0;
          if ( v21->numMeshes > 0 )
          {
            v71 = 0;
            v72 = 0;
            do
            {
              v22 = v71 + v20->meshindex;
              v20 = mdlModel;
              v23 = (OptimizedModel::MeshHeader_t *)((char *)v21 + v72 + v21->meshOffset);
              vtxMesh = v23;
              mdlMesh = (mstudiomesh_t *)&mdlModel->name[v22];
              vtxStripGroup_idx = 0;
              if ( v23->numStripGroups > 0 )
              {
                v73 = 0;
                do
                {
                  v24 = 0;
                  v25 = (int *)((char *)&v23->numStripGroups + v73 + v23->stripGroupHeaderOffset);
                  vtxStrip_idx = 0;
                  if ( (int)v25[4] > 0 )
                  {
                    v62 = 0;
                    do
                    {
                      v26 = (OptimizedModel::StripHeader_t *)((char *)v25 + v24 + v25[5]);
                      i = 0;
                      vtxStrip = v26;
                      if ( v26->numIndices > 0 )
                      {
                        do
                        {
                          x_low = LODWORD(mesh[1].x);
                          z_low = LODWORD(mesh->z);
                          v53 = (unsigned __int16)(LOWORD(mdlMesh->vertexoffset)
                                                 + *(_WORD *)((char *)v25
                                                            + 9
                                                            * *(unsigned __int16 *)((char *)v25
                                                                                  + 2 * i
                                                                                  + 2 * v26->indexOffset
                                                                                  + v25[3])
                                                            + v25[1]
                                                            + 4));
                          if ( x_low + 1 > z_low )
                          {
                            CUtlMemory<int,int>::Grow(
                              this: (CUtlMemory<OptimizedModel::OptimizedIndexBufferMarkupPs3_t *,int> *)&mesh->y,
                              num: x_low - z_low + 1);
                            v26 = vtxStrip;
                          }
                          ++LODWORD(mesh[1].x);
                          y_low = (unsigned int *)LODWORD(mesh->y);
                          v30 = LODWORD(mesh[1].x) - x_low - 1;
                          LODWORD(mesh[1].y) = y_low;
                          if ( v30 > 0 )
                          {
                            _V_memmove(dest: &y_low[x_low + 1], src: &y_low[x_low], count: 4 * v30);
                            v26 = vtxStrip;
                          }
                          v31 = (unsigned int *)(LODWORD(mesh->y) + 4 * x_low);
                          if ( v31 != nullptr )
                            *v31 = v53;
                          ++i;
                        }
                        while ( i < v26->numIndices );
                        v21 = vtxLod;
                        v23 = vtxMesh;
                      }
                      v24 = v62 + 35;
                      ++vtxStrip_idx;
                      v62 += 35;
                    }
                    while ( vtxStrip_idx < v25[4] );
                    v20 = mdlModel;
                  }
                  v73 += 33;
                  ++vtxStripGroup_idx;
                }
                while ( vtxStripGroup_idx < v23->numStripGroups );
                v7 = (unsigned __int8 *)vvdHdr;
              }
              v72 += 9;
              v71 += 116;
              ++vtxMesh_idx;
            }
            while ( vtxMesh_idx < v21->numMeshes );
            v17 = vtxBodyPart;
          }
          v69 += 148;
          if ( ++vtxModel_idx >= v17->numModels )
            break;
          v18 = mdlBodyPart;
        }
        v6 = (unsigned __int8 *)vvdVertexSrc;
      }
      m_p = memTempVVD.m_p;
      v68 += 16;
      v16 = k + 1;
      k = v16;
    }
    while ( v16 < *((_DWORD *)memTempVVD.m_p + 7) );
  }
  mesh[2].y = 0.0;
  v33 = *((_DWORD *)v7 + 15);
  v34 = &v7[*((_DWORD *)v7 + 14)];
  vvdVertexSrca = (mstudiovertex_t *)v34;
  if ( v33 != 0 )
    ia = &v7[v33];
  else
    ia = nullptr;
  if ( *((_DWORD *)v7 + 12) != 0 )
  {
    v35 = (unsigned __int8 *)operator new(nSize: vvdLength);
    v36 = vvdHdr;
    v37 = &v35[*((_DWORD *)v7 + 14)];
    vvdTangentNew = &v35[vvdHdr->tangentDataStart];
    memTempVVDa.m_p = v35;
    ka = 0;
    if ( vvdHdr->numFixups > 0 )
    {
      v38 = (int *)((char *)&vvdHdr->checksum + vvdHdr->fixupTableStart);
      do
      {
        memcpy(dst: v37, src: (unsigned __int8 *)&vvdVertexSrca[*(v38 - 1)], count: 48 * *v38);
        v37 += 48 * *v38;
        if ( ia != nullptr )
        {
          memcpy(dst: vvdTangentNew, src: &ia[16 * *(v38 - 1)], count: 16 * *v38);
          vvdTangentNew += 16 * *v38;
        }
        v36 = vvdHdr;
        v38 += 3;
        ++ka;
      }
      while ( ka < vvdHdr->numFixups );
      v34 = (unsigned __int8 *)vvdVertexSrca;
      v35 = memTempVVDa.m_p;
    }
    if ( v34 != nullptr )
    {
      memcpy(dst: v34, src: &v35[v36->vertexDataStart], count: 48 * mdlNumVertices);
      v36 = vvdHdr;
      v35 = memTempVVDa.m_p;
    }
    if ( ia != nullptr )
    {
      memcpy(dst: ia, src: &v35[v36->tangentDataStart], count: 16 * mdlNumVertices);
      v35 = memTempVVDa.m_p;
    }
    free(pMem: v35);
    free(pMem: nullptr);
  }
  if ( v34 < &v34[48 * mdlNumVertices] )
  {
    v39 = v34 + 20;
    vvdTangentNewa = (Vector4D *)((48 * mdlNumVertices - 1) / 0x30u + 1);
    do
    {
      v40 = LODWORD(mesh[2].y);
      w_low = LODWORD(mesh[1].w);
      vert = *(_QWORD *)(v39 - 4);
      vert_8 = *(_QWORD *)(v39 + 4);
      vert_16 = *(_QWORD *)(v39 + 12);
      vert_24 = *(_QWORD *)(v39 + 20);
      if ( v40 + 1 > w_low )
        CUtlMemory<MdlLib::MdlVertex,int>::Grow(
          this: (CUtlMemory<MdlLib::MdlVertex,int> *)&mesh[1].z,
          num: v40 - w_low + 1);
      ++LODWORD(mesh[2].y);
      v42 = (MdlLib::MdlVertex *)LODWORD(mesh[1].z);
      v43 = LODWORD(mesh[2].y) - v40 - 1;
      LODWORD(mesh[2].z) = v42;
      if ( v43 > 0 )
        _V_memmove(dest: &v42[v40 + 1], src: &v42[v40], count: 32 * v43);
      v44 = (MdlLib::MdlVertex *)(LODWORD(mesh[1].z) + 32 * v40);
      if ( v44 != nullptr )
      {
        *(_QWORD *)v44->position = vert;
        *(_QWORD *)&v44->position[2] = vert_8;
        *(_QWORD *)&v44->normal[1] = vert_16;
        *(_QWORD *)v44->texcoord = vert_24;
      }
      v39 += 48;
      vvdTangentNewa = (Vector4D *)((char *)vvdTangentNewa - 1);
    }
    while ( vvdTangentNewa != nullptr );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10008AC0
// Name: public: virtual bool CMdlLib::StripModelBuffers(class CUtlBuffer __near &,class CUtlBuffer __near &,class CUtlBuffer __near &,class IMdlStripInfo __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMdlLib::StripModelBuffers(
        CMdlLib *this,
        OptimizedModel::FileHeader_t *mdlBuffer,
        CUtlBuffer *vvdBuffer,
        CUtlBuffer *vtxBuffer,
        IMdlStripInfo **ppStripInfo)
{
  int m_Get; // ecx
  int m_Put; // esi
  int v7; // edx
  unsigned __int8 *m_pMemory; // edi
  unsigned __int8 *v9; // esi
  int v10; // eax
  unsigned __int8 *v11; // ebx
  OptimizedModel::FileHeader_t *v12; // edi
  CMdlStripInfo *v13; // ecx
  CMdlStripInfo *p_msi; // eax
  CMdlStripInfo *v15; // eax
  mstudiobodyparts_t *v16; // edx
  bool v18; // cc
  char *v19; // eax
  unsigned int v20; // eax
  OptimizedModel::MeshHeader_t *v21; // ecx
  int v22; // ecx
  _DWORD *v23; // esi
  unsigned int v24; // ebx
  IMdlStripInfo **v25; // eax
  int v26; // edi
  _DWORD *v27; // edx
  CVarBitVecBase<int> *v28; // esi
  CUtlSortVector<unsigned short,CLessSimple<unsigned short> > *v29; // ebx
  signed int i; // edi
  int m_Size; // esi
  int m_nAllocationCount; // eax
  unsigned __int16 *v33; // ecx
  int v34; // eax
  unsigned __int16 *v35; // esi
  signed int v36; // eax
  unsigned __int8 *v37; // eax
  int v38; // eax
  _DWORD *v39; // edi
  char IsChannelEnabled; // al
  int v41; // esi
  int v42; // edx
  int v43; // ecx
  _DWORD *v44; // esi
  int v45; // ecx
  int v46; // edx
  int v47; // eax
  int v48; // ecx
  int v49; // ecx
  unsigned int v50; // eax
  unsigned int v51; // esi
  int v52; // ecx
  int v53; // edx
  _DWORD *v54; // esi
  int v55; // eax
  unsigned __int8 *v56; // eax
  Vector4D *v57; // ecx
  int v58; // eax
  int *v59; // edi
  int v60; // eax
  int v61; // edi
  int v62; // ecx
  int v63; // edx
  char *v64; // ecx
  char *v65; // ecx
  unsigned int v66; // eax
  int v67; // edi
  int v68; // ecx
  int v69; // esi
  float *v70; // eax
  int v71; // edx
  unsigned __int8 *v72; // esi
  int v73; // ebx
  unsigned __int8 *v74; // ecx
  int v75; // eax
  int v76; // esi
  int v77; // edx
  IMdlStripInfo **v78; // esi
  _DWORD *v79; // eax
  _DWORD *v80; // esi
  unsigned __int8 *v81; // edi
  char *v82; // esi
  int v83; // ebx
  IMdlStripInfo **v84; // esi
  int v85; // edx
  OptimizedModel::FileHeader_t *v86; // ebx
  int v87; // eax
  OptimizedModel::MeshHeader_t *v88; // ecx
  char *v89; // eax
  int v90; // ecx
  unsigned int v91; // esi
  unsigned int v92; // edi
  int v93; // ecx
  OptimizedModel::ModelLODHeader_t *v94; // edx
  int v95; // ebx
  int v96; // ebx
  unsigned int *v97; // eax
  int v98; // esi
  int v99; // ebx
  unsigned int *v100; // eax
  int v101; // esi
  int v102; // ebx
  unsigned int *v103; // edi
  int v104; // esi
  unsigned int *v105; // eax
  int v106; // ebx
  int v107; // esi
  OptimizedModel::ModelLODHeader_t **v108; // eax
  OptimizedModel::FileHeader_t *v109; // ecx
  unsigned int v110; // edi
  unsigned int v111; // ebx
  int v112; // esi
  int v113; // eax
  void *(__thiscall *Alloc_2)(IMemAlloc *, unsigned int); // edx
  int *v115; // eax
  char *v116; // edx
  int v117; // eax
  int v118; // edi
  int *v119; // ebx
  int *v120; // edi
  _DWORD *v121; // edi
  int LessOrEqual; // eax
  IMdlStripInfo **v123; // ebx
  _WORD *v124; // edi
  int v125; // edi
  int *v126; // ebx
  int *v127; // edi
  unsigned __int8 *v128; // edi
  unsigned int *v129; // ebx
  unsigned int v130; // esi
  int v131; // eax
  int NumBytesRegistered; // eax
  char *v133; // edi
  int v134; // ebx
  char *v135; // esi
  char *v136; // eax
  unsigned __int8 *v137; // eax
  OptimizedModel::ModelLODHeader_t *v138; // ebx
  CUtlSortVector<unsigned short,CLessSimple<unsigned short> > *v139; // edi
  int v140; // esi
  char *v141; // edi
  char *v142; // ebx
  char *v143; // ebx
  char *v144; // eax
  char *v145; // eax
  char *v146; // eax
  char *v147; // eax
  char *v148; // eax
  char *v149; // eax
  char *v150; // eax
  unsigned __int8 *m_p; // edx
  unsigned __int8 *v152; // esi
  char *v153; // eax
  int *v154; // ecx
  int v155; // eax
  int v156; // esi
  int v157; // edi
  int v158; // eax
  UtlRBTreeNode_t<CUtlMap<unsigned char *,int,unsigned int>::Node_t,unsigned int> *v159; // eax
  CMdlStripInfo::MdlRangeItem *v160; // eax
  unsigned int *v161; // eax
  CMdlStripInfo::Ps3studioBatch_t **v162; // eax
  unsigned __int16 *v163; // eax
  unsigned __int16 *v164; // [esp-14h] [ebp-180h]
  unsigned __int8 *v165; // [esp-8h] [ebp-174h]
  int v166; // [esp-4h] [ebp-170h]
  CMdlStripInfo msi; // [esp+Ch] [ebp-160h] BYREF
  CMdlStripInfo::MdlRangeItem mdlRangeItem; // [esp+8Ch] [ebp-E0h] BYREF
  int vtxLength; // [esp+9Ch] [ebp-D0h] BYREF
  CMemoryMovingTracker vtxRemove; // [esp+A0h] [ebp-CCh] BYREF
  CUtlSortVector<unsigned short,CLessSimple<unsigned short> > *srcIndices; // [esp+D4h] [ebp-98h]
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > vtxOffVertex; // [esp+D8h] [ebp-94h] BYREF
  CUtlVector<int,CUtlMemory<int,int> > vtxIndexDeltas; // [esp+ECh] [ebp-80h] BYREF
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > vtxOffIndex; // [esp+100h] [ebp-6Ch] BYREF
  int vvdLength; // [esp+114h] [ebp-58h]
  int vtxStripGroup_idx; // [esp+118h] [ebp-54h]
  OptimizedModel::MeshHeader_t *vtxMesh; // [esp+11Ch] [ebp-50h]
  mstudiobodyparts_t *mdlBodyPart; // [esp+120h] [ebp-4Ch]
  unsigned int vtxOffVertexBuffer; // [esp+124h] [ebp-48h]
  int v180; // [esp+128h] [ebp-44h]
  int vtxBodyPart_idx; // [esp+12Ch] [ebp-40h]
  void *context; // [esp+130h] [ebp-3Ch] BYREF
  OptimizedModel::ModelLODHeader_t *vtxLod; // [esp+134h] [ebp-38h] BYREF
  int v184; // [esp+138h] [ebp-34h]
  int vtxMesh_idx; // [esp+13Ch] [ebp-30h]
  OptimizedModel::BodyPartHeader_t *vtxBodyPart; // [esp+140h] [ebp-2Ch]
  int vtxLod_idx; // [esp+144h] [ebp-28h]
  unsigned int vtxOffVertexBufferEnd; // [esp+148h] [ebp-24h]
  int mdlModel_idx; // [esp+14Ch] [ebp-20h] BYREF
  int vtxStrip_idx; // [esp+150h] [ebp-1Ch]
  unsigned int vtxOffIndexBufferEnd; // [esp+154h] [ebp-18h]
  int vtxModel_idx; // [esp+158h] [ebp-14h]
  unsigned int offVertex; // [esp+15Ch] [ebp-10h]
  Vector4D *vvdTangentNew; // [esp+160h] [ebp-Ch]
  CArrayAutoPtr<unsigned char> memTempVVD; // [esp+164h] [ebp-8h]
  int vtxMatList_idx; // [esp+168h] [ebp-4h]
  OptimizedModel::FileHeader_t *vtxHdr; // [esp+174h] [ebp+8h]

  m_Get = vvdBuffer->m_Get;
  m_Put = vtxBuffer->m_Put;
  vvdLength = vvdBuffer->m_Put - m_Get;
  v7 = vtxBuffer->m_Get;
  m_pMemory = vtxBuffer->m_Memory.m_pMemory;
  vtxLength = m_Put - v7;
  v9 = (unsigned __int8 *)(mdlBuffer->version + mdlBuffer->maxBonesPerVert);
  v10 = *((_DWORD *)v9 + 2);
  v11 = &vvdBuffer->m_Memory.m_pMemory[m_Get];
  v12 = (OptimizedModel::FileHeader_t *)&m_pMemory[v7];
  vtxOffVertexBufferEnd = (unsigned int)v9;
  vtxMatList_idx = (int)v11;
  vtxHdr = v12;
  vtxStrip_idx = v10;
  if ( v10 == *((_DWORD *)v11 + 2) && v10 == v12->checkSum )
  {
    *((_DWORD *)v9 + 2) = v10 ^ (123457 * v10);
    *((_DWORD *)v11 + 2) ^= 123457 * *((_DWORD *)v11 + 2);
    v12->checkSum ^= 123457 * v12->checkSum;
    mdlBodyPart = *((mstudiobodyparts_t **)v9 + 2);
    CMdlStripInfo::CMdlStripInfo(this: &msi);
    if ( ppStripInfo != nullptr )
    {
      v13 = (CMdlStripInfo *)*ppStripInfo;
      if ( *ppStripInfo != nullptr )
      {
        vtxOffIndexBufferEnd = (unsigned int)*ppStripInfo;
        CMdlStripInfo::Reset(this: v13);
        p_msi = (CMdlStripInfo *)vtxOffIndexBufferEnd;
      }
      else
      {
        v15 = (CMdlStripInfo *)operator new(nSize: 0x80u);
        if ( v15 != nullptr )
        {
          p_msi = CMdlStripInfo::CMdlStripInfo(this: v15);
          vtxOffIndexBufferEnd = (unsigned int)p_msi;
          *ppStripInfo = p_msi;
        }
        else
        {
          p_msi = nullptr;
          vtxOffIndexBufferEnd = 0;
          *ppStripInfo = nullptr;
        }
      }
    }
    else
    {
      vtxOffIndexBufferEnd = (unsigned int)&msi;
      p_msi = &msi;
    }
    v16 = mdlBodyPart;
    p_msi->m_lChecksumOld = vtxStrip_idx;
    p_msi->m_lChecksumNew = (int)v16;
    if ( (v9[152] & 0x10) == 0 )
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_ModelLib, a2: 0) != 0 )
        _LoggingSystem_Log(a1: LOG_ModelLib, a2: 0, a3: "No special stripping - the model is not a static prop.\n");
LABEL_21:
      *(_DWORD *)(vtxOffIndexBufferEnd + 4) = 1;
      CMdlStripInfo::~CMdlStripInfo(this: &msi);
      return 1;
    }
    if ( *((int *)v11 + 3) <= 1 )
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_ModelLib, a2: 0) != 0 )
        _LoggingSystem_Log(
          a1: LOG_ModelLib,
          a2: 0,
          a3: "No special stripping - the model has only %d lod(s).\n",
          *((_DWORD *)v11 + 3));
      goto LABEL_21;
    }
    if ( *((_DWORD *)v9 + 39) != 1 )
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_ModelLib, a2: 0) != 0 )
        _LoggingSystem_Log(
          a1: LOG_ModelLib,
          a2: 0,
          a3: "No special stripping - the model has %d bone(s).\n",
          *((_DWORD *)v9 + 39));
      goto LABEL_21;
    }
    p_msi->m_eMode = 2;
    v18 = v12->numBodyParts <= 0;
    memTempVVD.m_p = nullptr;
    if ( !v18 )
    {
      vvdTangentNew = nullptr;
      do
      {
        v19 = (char *)vvdTangentNew + *(_DWORD *)(vtxOffVertexBufferEnd + 236);
        offVertex = (unsigned int)vtxHdr + 8 * (int)memTempVVD.m_p + vtxHdr->bodyPartOffset;
        v18 = *(_DWORD *)offVertex <= 0;
        mdlBodyPart = (mstudiobodyparts_t *)&v19[vtxOffVertexBufferEnd];
        vtxLod_idx = 0;
        if ( !v18 )
        {
          vtxModel_idx = 0;
          do
          {
            v20 = offVertex + *(_DWORD *)(offVertex + 4) + 8 * vtxLod_idx;
            v21 = (OptimizedModel::MeshHeader_t *)((char *)mdlBodyPart + vtxModel_idx + mdlBodyPart->modelindex);
            vtxMesh_idx = 0;
            vtxMesh = v21;
            v18 = *(_DWORD *)(v20 + *(_DWORD *)(v20 + 4)) <= 0;
            mdlModel_idx = v20 + *(_DWORD *)(v20 + 4);
            if ( !v18 )
            {
              v184 = 0;
              v180 = 0;
              do
              {
                v22 = v184 + vtxMesh[8].stripGroupHeaderOffset;
                vtxBodyPart = (OptimizedModel::BodyPartHeader_t *)(mdlModel_idx + v180 + *(_DWORD *)(mdlModel_idx + 4));
                v18 = vtxBodyPart->numModels <= 0;
                vtxLod = (OptimizedModel::ModelLODHeader_t *)((char *)vtxMesh + v22);
                vtxStripGroup_idx = 0;
                if ( !v18 )
                {
                  vtxBodyPart_idx = 0;
                  do
                  {
                    v23 = (int *)((char *)&vtxBodyPart->numModels + vtxBodyPart_idx + vtxBodyPart->modelOffset);
                    vtxStrip_idx = 0;
                    if ( (int)v23[4] > 0 )
                    {
                      vtxOffVertexBuffer = 0;
                      do
                      {
                        v24 = vtxOffVertexBuffer + v23[5];
                        ppStripInfo = nullptr;
                        if ( *(int *)((char *)v23 + v24) > 0 )
                        {
                          v25 = ppStripInfo;
                          do
                          {
                            v26 = (unsigned __int16)(LOWORD(vtxLod[1].numMeshes)
                                                   + *(_WORD *)((char *)v23
                                                              + 9
                                                              * *(unsigned __int16 *)((char *)v23
                                                                                    + 2
                                                                                    * ((_DWORD)v25
                                                                                     + *(_DWORD *)((char *)v23 + v24 + 4))
                                                                                    + v23[3])
                                                              + v23[1]
                                                              + 4));
                            if ( v26 >= *(_DWORD *)(vtxOffIndexBufferEnd + 16) )
                            {
                              CVarBitVecBase<int>::Resize(
                                this: (CVarBitVecBase<int> *)(vtxOffIndexBufferEnd + 16),
                                resizeNumBits: v26 + 1,
                                bClearAll: false);
                              v25 = ppStripInfo;
                            }
                            v27 = (_DWORD *)(*(_DWORD *)(vtxOffIndexBufferEnd + 28) + 4 * (v26 >> 5));
                            v25 = (IMdlStripInfo **)((char *)v25 + 1);
                            ppStripInfo = v25;
                            *v27 |= 1 << (v26 & 0x1F);
                          }
                          while ( (int)v25 < *(_DWORD *)((char *)v23 + v24) );
                        }
                        vtxOffVertexBuffer += 35;
                        ++vtxStrip_idx;
                      }
                      while ( vtxStrip_idx < v23[4] );
                    }
                    vtxBodyPart_idx += 33;
                    ++vtxStripGroup_idx;
                  }
                  while ( vtxStripGroup_idx < vtxBodyPart->numModels );
                }
                v180 += 9;
                v184 += 116;
                ++vtxMesh_idx;
              }
              while ( vtxMesh_idx < *(_DWORD *)mdlModel_idx );
            }
            vtxModel_idx += 148;
            ++vtxLod_idx;
          }
          while ( vtxLod_idx < *(_DWORD *)offVertex );
        }
        ++vvdTangentNew;
        ++memTempVVD.m_p;
      }
      while ( (int)memTempVVD.m_p < vtxHdr->numBodyParts );
    }
    v28 = (CVarBitVecBase<int> *)vtxOffIndexBufferEnd;
    v29 = (CUtlSortVector<unsigned short,CLessSimple<unsigned short> > *)(vtxOffIndexBufferEnd + 32);
    v166 = *(_DWORD *)(vtxOffIndexBufferEnd + 16);
    srcIndices = (CUtlSortVector<unsigned short,CLessSimple<unsigned short> > *)(vtxOffIndexBufferEnd + 32);
    CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::EnsureCapacity(
      this: (CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *)(vtxOffIndexBufferEnd + 32),
      num: v166);
    for ( i = CVarBitVecBase<int>::FindNextSetBit(this: v28 + 1, startBit: 0);
          i >= 0;
          i = CVarBitVecBase<int>::FindNextSetBit(
                this: (CVarBitVecBase<int> *)(vtxOffIndexBufferEnd + 16),
                startBit: i + 1) )
    {
      m_Size = v29->m_Size;
      m_nAllocationCount = v29->m_Memory.m_nAllocationCount;
      v29->m_bNeedsSort = true;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<unsigned short,int>::Grow(this: &v29->m_Memory, num: m_Size - m_nAllocationCount + 1);
      ++v29->m_Size;
      v33 = v29->m_Memory.m_pMemory;
      v34 = v29->m_Size - m_Size - 1;
      v29->m_pElements = v29->m_Memory.m_pMemory;
      if ( v34 > 0 )
        _V_memmove(dest: &v33[m_Size + 1], src: &v33[m_Size], count: 2 * v34);
      v35 = &v29->m_Memory.m_pMemory[m_Size];
      if ( v35 != nullptr )
        *v35 = i;
    }
    if ( v29->m_bNeedsSort )
    {
      v36 = v29->m_Size;
      v29->m_bNeedsSort = false;
      if ( v36 > 1 )
      {
        context = v29->m_pLessContext;
        v164 = v29->m_Memory.m_pMemory;
        vtxLod = (OptimizedModel::ModelLODHeader_t *)((char *)&ppStripInfo + 3);
        qsort_s(
          base: v164,
          num: v36,
          width: 2u,
          comp: (int (__cdecl *)(void *, const void *, const void *))CUtlSortVector<unsigned short,CLessSimple<unsigned short>>::CompareHelper,
          &context);
      }
    }
    vtxModel_idx = 0;
    vtxStripGroup_idx = vtxOffIndexBufferEnd + 100;
    vtxBodyPart = nullptr;
    if ( *(int *)(vtxOffVertexBufferEnd + 232) > 0 )
    {
      memTempVVD.m_p = nullptr;
      do
      {
        v37 = &memTempVVD.m_p[*(_DWORD *)(vtxOffVertexBufferEnd + 236)];
        mdlModel_idx = 0;
        v38 = (int)&v37[vtxOffVertexBufferEnd];
        v18 = *(_DWORD *)(v38 + 4) <= 0;
        vtxMesh_idx = v38;
        if ( !v18 )
        {
          vvdTangentNew = nullptr;
          do
          {
            v39 = (_DWORD *)((char *)&vvdTangentNew->x + *(_DWORD *)(vtxMesh_idx + 12) + vtxMesh_idx);
            IsChannelEnabled = _LoggingSystem_IsChannelEnabled(a1: LOG_ModelLib, a2: 0);
            v41 = vtxMatList_idx;
            if ( IsChannelEnabled != 0 )
              _LoggingSystem_Log(
                a1: LOG_ModelLib,
                a2: 0,
                a3: " Stripped %d lod(s).\n",
                *(_DWORD *)(vtxMatList_idx + 12) - 1);
            if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_ModelLib, a2: 0) != 0 )
              _LoggingSystem_Log(
                a1: LOG_ModelLib,
                a2: 0,
                a3: " Stripped %d vertexes (was: %d, now: %d).\n",
                v39[20] - v29->m_Size,
                v39[20],
                v29->m_Size);
            v42 = v39[20];
            v39[20] = v29->m_Size;
            v43 = v41 + *(_DWORD *)(v41 + 56);
            vtxModel_idx = v42;
            v39[27] = v43;
            v18 = v39[18] <= 0;
            v39[28] = v41 + *(_DWORD *)(v41 + 60);
            offVertex = 0;
            if ( !v18 )
            {
              ppStripInfo = nullptr;
              do
              {
                v44 = (IMdlStripInfo **)((char *)ppStripInfo + (_DWORD)v39 + v39[19]);
                v45 = v44[3];
                v46 = v44[2];
                v44[12] = v39 + 27;
                mdlRangeItem.m_offOld = v45;
                mdlRangeItem.m_numOld = v46;
                vtxLod = (OptimizedModel::ModelLODHeader_t *)(unsigned __int16)(v46 + v45);
                v44[2] = CUtlSortVector<unsigned short,CLessSimple<unsigned short>>::FindLess(
                           this: v29,
                           src: (const unsigned __int16 *)&vtxLod);
                vtxLod = (OptimizedModel::ModelLODHeader_t *)*((unsigned __int16 *)v44 + 6);
                v47 = CUtlSortVector<unsigned short,CLessSimple<unsigned short>>::FindLess(
                        this: v29,
                        src: (const unsigned __int16 *)&vtxLod)
                    + 1;
                v44[2] += 1 - v47;
                v48 = v44[2];
                v44[3] = v47;
                mdlRangeItem.m_offNew = v47;
                mdlRangeItem.m_numNew = v48;
                CUtlSortVector<CMdlStripInfo::MdlRangeItem,CLessSimple<CMdlStripInfo::MdlRangeItem>>::Insert(
                  this: (CUtlSortVector<CMdlStripInfo::MdlRangeItem,CLessSimple<CMdlStripInfo::MdlRangeItem> > *)vtxStripGroup_idx,
                  src: &mdlRangeItem);
                v49 = v44[2];
                ppStripInfo += 29;
                v44[13] = v49;
                v44[14] = v44[2];
                v44[15] = v44[2];
                v44[16] = v44[2];
                v44[17] = v44[2];
                v44[18] = v44[2];
                v50 = offVertex;
                v44[19] = v44[2];
                v44[20] = v44[2];
                offVertex = v50 + 1;
              }
              while ( (signed int)(v50 + 1) < v39[18] );
            }
            vvdTangentNew = (Vector4D *)((char *)vvdTangentNew + 148);
            ++mdlModel_idx;
          }
          while ( mdlModel_idx < *(_DWORD *)(vtxMesh_idx + 4) );
        }
        memTempVVD.m_p += 16;
        vtxBodyPart = (OptimizedModel::BodyPartHeader_t *)((char *)vtxBodyPart + 1);
      }
      while ( (int)vtxBodyPart < *(_DWORD *)(vtxOffVertexBufferEnd + 232) );
    }
    v51 = vtxOffVertexBufferEnd;
    v52 = 0;
    if ( *(int *)(vtxOffVertexBufferEnd + 156) > 0 )
    {
      v53 = 0;
      do
      {
        *(_DWORD *)(v53 + *(_DWORD *)(v51 + 160) + v51 + 160) &= 0xFFFC07FF;
        ++v52;
        v53 += 216;
      }
      while ( v52 < *(_DWORD *)(v51 + 156) );
    }
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_ModelLib, a2: 0) != 0 )
      _LoggingSystem_Log(a1: LOG_ModelLib, a2: 0, a3: " Updated %d bone(s).\n", *(_DWORD *)(v51 + 156));
    v54 = (_DWORD *)vtxMatList_idx;
    *(_DWORD *)(vtxMatList_idx + 12) = 1;
    v54[4] = v29->m_Size;
    v54[5] = v29->m_Size;
    v54[6] = v29->m_Size;
    v54[7] = v29->m_Size;
    v54[8] = v29->m_Size;
    v54[9] = v29->m_Size;
    v54[10] = v29->m_Size;
    v54[11] = v29->m_Size;
    vtxOffVertexBufferEnd = (unsigned int)v54 + v54[14];
    v55 = v54[15];
    if ( v55 != 0 )
      ppStripInfo = (IMdlStripInfo **)((char *)v54 + v55);
    else
      ppStripInfo = nullptr;
    if ( v54[12] != 0 )
    {
      v56 = (unsigned __int8 *)operator new(nSize: vvdLength);
      vtxMatList_idx = (int)&v56[v54[14]];
      v57 = (Vector4D *)&v56[v54[15]];
      memTempVVD.m_p = v56;
      v58 = v54[13];
      vvdTangentNew = v57;
      offVertex = 0;
      if ( (int)v54[12] > 0 )
      {
        v59 = (_DWORD *)((char *)v54 + v58 + 8);
        do
        {
          memcpy(
            dst: (unsigned __int8 *)vtxMatList_idx,
            src: (unsigned __int8 *)(vtxOffVertexBufferEnd + 48 * *(v59 - 1)),
            count: 48 * *v59);
          v60 = *v59;
          vtxMatList_idx += 48 * *v59;
          if ( ppStripInfo != nullptr )
          {
            memcpy(
              dst: (unsigned __int8 *)vvdTangentNew,
              src: (unsigned __int8 *)&ppStripInfo[4 * *(v59 - 1)],
              count: 16 * v60);
            vvdTangentNew += *v59;
          }
          v59 += 3;
          ++offVertex;
        }
        while ( (signed int)offVertex < v54[12] );
      }
      v61 = vtxModel_idx;
      if ( vtxOffVertexBufferEnd != 0 )
        memcpy(dst: (unsigned __int8 *)vtxOffVertexBufferEnd, src: &memTempVVD.m_p[v54[14]], count: 48 * vtxModel_idx);
      if ( ppStripInfo != nullptr )
        memcpy(dst: (unsigned __int8 *)ppStripInfo, src: &memTempVVD.m_p[v54[15]], count: 16 * v61);
      free(pMem: memTempVVD.m_p);
      free(pMem: nullptr);
    }
    v54[14] -= (12 * v54[12] + 15) & 0xFFFFFFF0;
    v62 = v54[14];
    v63 = 0;
    v54[12] = 0;
    v64 = (char *)v54 + v62;
    if ( v29->m_Size > 0 )
    {
      v65 = v64 + 24;
      do
      {
        v66 = vtxOffVertexBufferEnd + 48 * v29->m_Memory.m_pMemory[v63++];
        *((_QWORD *)v65 - 3) = *(_QWORD *)v66;
        *((_QWORD *)v65 - 2) = *(_QWORD *)(v66 + 8);
        *((float *)v65 - 2) = *(float *)(v66 + 16);
        v65 += 48;
        *((float *)v65 - 13) = *(float *)(v66 + 20);
        *((float *)v65 - 12) = *(float *)(v66 + 24);
        *((float *)v65 - 11) = *(float *)(v66 + 28);
        *((float *)v65 - 10) = *(float *)(v66 + 32);
        *((float *)v65 - 9) = *(float *)(v66 + 36);
        *((float *)v65 - 8) = *(float *)(v66 + 40);
        *((float *)v65 - 7) = *(float *)(v66 + 44);
      }
      while ( v63 < v29->m_Size );
    }
    v67 = v54[14] + 48 * v29->m_Size;
    mdlBodyPart = (mstudiobodyparts_t *)vvdLength;
    vvdLength = v67;
    if ( ppStripInfo != nullptr )
    {
      v68 = 0;
      v54[15] = v67;
      if ( v29->m_Size > 0 )
      {
        v69 = (int)v54 + v67 + 8;
        do
        {
          v70 = (float *)&ppStripInfo[4 * v29->m_Memory.m_pMemory[v68++]];
          v69 += 16;
          *(float *)(v69 - 24) = *v70;
          *(float *)(v69 - 20) = v70[1];
          *(float *)(v69 - 16) = v70[2];
          *(float *)(v69 - 12) = v70[3];
        }
        while ( v68 < v29->m_Size );
      }
      v67 += 16 * v29->m_Size;
      vvdLength = v67;
    }
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_ModelLib, a2: 0) != 0 )
      _LoggingSystem_Log(a1: LOG_ModelLib, a2: 0, a3: " Stripped %d vvd bytes.\n", (char *)mdlBodyPart - v67);
    vtxRemove.m_map.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(unsigned __int8 *const *, unsigned __int8 *const *))CDefOps<unsigned char *>::LessFunc;
    memset(&vtxRemove.m_map.m_Tree.m_Elements, 0, sizeof(vtxRemove.m_map.m_Tree.m_Elements));
    vtxRemove.m_map.m_Tree.m_Root = -1;
    vtxRemove.m_map.m_Tree.m_NumElements = 0;
    vtxRemove.m_map.m_Tree.m_FirstFree = -1;
    vtxRemove.m_map.m_Tree.m_LastAlloc.index = -1;
    vtxRemove.m_map.m_Tree.m_pElements = nullptr;
    vtxRemove.m_ePolicy = MEMORY_REMOVE;
    v71 = 8 * vtxHdr->numLODs - 8;
    vtxStrip_idx = -1;
    vtxOffVertexBuffer = -1;
    v165 = (unsigned __int8 *)&vtxHdr->maxBonesPerStrip + vtxHdr->materialReplacementListOffset;
    vtxOffIndexBufferEnd = 0;
    vtxOffVertexBufferEnd = 0;
    memset(&vtxOffIndex, 0, sizeof(vtxOffIndex));
    memset(&vtxOffVertex, 0, sizeof(vtxOffVertex));
    CMemoryMovingTracker::RegisterBytes(this: &vtxRemove, pos: v165, length: v71);
    for ( vtxMatList_idx = 0; vtxMatList_idx < vtxHdr->numLODs; ++vtxMatList_idx )
    {
      v72 = (unsigned __int8 *)vtxHdr + 8 * vtxMatList_idx + vtxHdr->materialReplacementListOffset;
      if ( vtxMatList_idx != 0 )
      {
        CMemoryMovingTracker::RegisterBytes(
          this: &vtxRemove,
          pos: &v72[*((_DWORD *)v72 + 1)],
          length: 6 * *(_DWORD *)v72);
        v73 = 0;
        if ( *(int *)v72 > 0 )
        {
          ppStripInfo = nullptr;
          do
          {
            v74 = &v72[*((_DWORD *)v72 + 1)
                     + (_DWORD)ppStripInfo
                     + *(_DWORD *)&v72[*((_DWORD *)v72 + 1) + 2 + (_DWORD)ppStripInfo]];
            if ( v74 != nullptr )
            {
              vtxLod = (OptimizedModel::ModelLODHeader_t *)(v74 + 1);
              v75 = strlen((const char *)v74) + 1;
            }
            else
            {
              v75 = 0;
            }
            CMemoryMovingTracker::RegisterBytes(this: &vtxRemove, pos: v74, length: v75);
            ppStripInfo = (IMdlStripInfo **)((char *)ppStripInfo + 6);
            ++v73;
          }
          while ( v73 < *(_DWORD *)v72 );
        }
      }
    }
    v18 = vtxHdr->numBodyParts <= 0;
    vtxBodyPart_idx = 0;
    if ( !v18 )
    {
      do
      {
        v18 = *(int *)((char *)&vtxHdr->version + 8 * vtxBodyPart_idx + vtxHdr->bodyPartOffset) <= 0;
        vtxBodyPart = (OptimizedModel::BodyPartHeader_t *)((char *)vtxHdr + 8 * vtxBodyPart_idx + vtxHdr->bodyPartOffset);
        v180 = 0;
        if ( !v18 )
        {
          do
          {
            v76 = vtxBodyPart->modelOffset + 8 * v180;
            v77 = *(int *)((char *)&vtxBodyPart->modelOffset + v76);
            v78 = (IMdlStripInfo **)((char *)vtxBodyPart + v76);
            v166 = 12 * (_DWORD)*v78 - 12;
            ppStripInfo = v78;
            CMemoryMovingTracker::RegisterBytes(this: &vtxRemove, pos: (unsigned __int8 *)v78 + v77 + 12, length: v166);
            v18 = (int)*v78 <= 0;
            vtxLod_idx = 0;
            if ( !v18 )
            {
              v184 = 0;
              do
              {
                v79 = (IMdlStripInfo **)((char *)ppStripInfo + v184 + (_DWORD)ppStripInfo[1]);
                vtxModel_idx = (int)v79;
                if ( vtxLod_idx != 0 )
                {
                  v80 = v79;
                  CMemoryMovingTracker::RegisterBytes(
                    this: &vtxRemove,
                    pos: (unsigned __int8 *)v79 + v79[1],
                    length: 9 * *v79);
                  v18 = *v80 <= 0;
                  mdlModel_idx = 0;
                  if ( !v18 )
                  {
                    memTempVVD.m_p = nullptr;
                    do
                    {
                      v81 = &memTempVVD.m_p[vtxModel_idx + *(_DWORD *)(vtxModel_idx + 4)];
                      CMemoryMovingTracker::RegisterBytes(
                        this: &vtxRemove,
                        pos: &v81[*((_DWORD *)v81 + 1)],
                        length: 33 * *(_DWORD *)v81);
                      v18 = *(_DWORD *)v81 <= 0;
                      offVertex = 0;
                      if ( !v18 )
                      {
                        vvdTangentNew = nullptr;
                        do
                        {
                          v82 = (char *)vvdTangentNew + (_DWORD)v81 + *((_DWORD *)v81 + 1);
                          CMemoryMovingTracker::RegisterBytes(
                            this: &vtxRemove,
                            pos: (unsigned __int8 *)&v82[*((_DWORD *)v82 + 5)],
                            length: 35 * *((_DWORD *)v82 + 4));
                          v83 = 0;
                          if ( *((int *)v82 + 4) > 0 )
                          {
                            vtxMatList_idx = 0;
                            do
                            {
                              CMemoryMovingTracker::RegisterBytes(
                                this: &vtxRemove,
                                pos: (unsigned __int8 *)&v82[vtxMatList_idx
                                                      + *((_DWORD *)v82 + 5)
                                                      + *(_DWORD *)&v82[vtxMatList_idx + 23 + *((_DWORD *)v82 + 5)]],
                                length: 8 * *(_DWORD *)&v82[vtxMatList_idx + 19 + *((_DWORD *)v82 + 5)]);
                              vtxMatList_idx += 35;
                              ++v83;
                            }
                            while ( v83 < *((_DWORD *)v82 + 4) );
                          }
                          vvdTangentNew = (Vector4D *)((char *)vvdTangentNew + 33);
                          ++offVertex;
                        }
                        while ( (signed int)offVertex < *(_DWORD *)v81 );
                      }
                      memTempVVD.m_p += 9;
                      ++mdlModel_idx;
                    }
                    while ( mdlModel_idx < *(_DWORD *)vtxModel_idx );
                  }
                }
                v184 += 12;
                ++vtxLod_idx;
              }
              while ( vtxLod_idx < (int)*ppStripInfo );
            }
            v84 = ppStripInfo;
            v85 = 0;
            vtxModel_idx = 0;
            if ( (int)*ppStripInfo > 0 )
            {
              v86 = vtxHdr;
              do
              {
                v87 = (int)&v84[3 * v85] + (_DWORD)v84[1];
                vtxMesh_idx = 0;
                vtxLod_idx = v87;
                if ( *(int *)v87 > 0 )
                {
                  memTempVVD.m_p = nullptr;
                  do
                  {
                    v88 = (OptimizedModel::MeshHeader_t *)&memTempVVD.m_p[v87 + *(_DWORD *)(v87 + 4)];
                    vtxMesh = v88;
                    mdlModel_idx = 0;
                    if ( v88->numStripGroups > 0 )
                    {
                      vvdTangentNew = nullptr;
                      do
                      {
                        v89 = (char *)vvdTangentNew + (_DWORD)v88 + v88->stripGroupHeaderOffset;
                        v90 = *((_DWORD *)v89 + 3);
                        v91 = v90 + v89 - (char *)v86;
                        v92 = (unsigned int)&v89[2 * *((_DWORD *)v89 + 2) - (_DWORD)v86 + v90];
                        v93 = *((_DWORD *)v89 + 1);
                        offVertex = v93 + v89 - (char *)v86;
                        v94 = (OptimizedModel::ModelLODHeader_t *)&v89[9 * *(_DWORD *)v89 - (_DWORD)v86 + v93];
                        vtxLod = v94;
                        if ( v91 < vtxStrip_idx )
                          vtxStrip_idx = v91;
                        if ( v92 > vtxOffIndexBufferEnd )
                          vtxOffIndexBufferEnd = v92;
                        if ( offVertex < vtxOffVertexBuffer )
                          vtxOffVertexBuffer = offVertex;
                        if ( (unsigned int)v94 > vtxOffVertexBufferEnd )
                          vtxOffVertexBufferEnd = (unsigned int)v94;
                        if ( vtxModel_idx == 0 )
                        {
                          v95 = vtxOffIndex.m_Size;
                          vtxMatList_idx = vtxOffIndex.m_Size;
                          if ( vtxOffIndex.m_Size + 1 > vtxOffIndex.m_Memory.m_nAllocationCount )
                          {
                            CUtlMemory<int,int>::Grow(
                              this: (CUtlMemory<OptimizedModel::OptimizedIndexBufferMarkupPs3_t *,int> *)&vtxOffIndex,
                              num: vtxOffIndex.m_Size - vtxOffIndex.m_Memory.m_nAllocationCount + 1);
                            v95 = vtxOffIndex.m_Size;
                          }
                          v96 = v95 + 1;
                          vtxOffIndex.m_Size = v96;
                          vtxOffIndex.m_pElements = vtxOffIndex.m_Memory.m_pMemory;
                          if ( v96 - vtxMatList_idx - 1 > 0 )
                            _V_memmove(
                              dest: &vtxOffIndex.m_Memory.m_pMemory[vtxMatList_idx + 1],
                              src: &vtxOffIndex.m_Memory.m_pMemory[vtxMatList_idx],
                              count: 4 * (v96 - vtxMatList_idx - 1));
                          v97 = &vtxOffIndex.m_Memory.m_pMemory[vtxMatList_idx];
                          if ( v97 != nullptr )
                            *v97 = v91;
                          v98 = v96;
                          if ( v96 + 1 > vtxOffIndex.m_Memory.m_nAllocationCount )
                          {
                            CUtlMemory<int,int>::Grow(
                              this: (CUtlMemory<OptimizedModel::OptimizedIndexBufferMarkupPs3_t *,int> *)&vtxOffIndex,
                              num: v96 - vtxOffIndex.m_Memory.m_nAllocationCount + 1);
                            v96 = vtxOffIndex.m_Size;
                          }
                          v99 = v96 + 1;
                          vtxOffIndex.m_pElements = vtxOffIndex.m_Memory.m_pMemory;
                          vtxOffIndex.m_Size = v99;
                          if ( v99 - v98 - 1 > 0 )
                            _V_memmove(
                              dest: &vtxOffIndex.m_Memory.m_pMemory[v98 + 1],
                              src: &vtxOffIndex.m_Memory.m_pMemory[v98],
                              count: 4 * (v99 - v98 - 1));
                          v100 = &vtxOffIndex.m_Memory.m_pMemory[v98];
                          if ( v100 != nullptr )
                            *v100 = v92;
                          v101 = vtxOffVertex.m_Size;
                          v102 = vtxOffVertex.m_Size;
                          if ( vtxOffVertex.m_Size + 1 > vtxOffVertex.m_Memory.m_nAllocationCount )
                          {
                            CUtlMemory<int,int>::Grow(
                              this: (CUtlMemory<OptimizedModel::OptimizedIndexBufferMarkupPs3_t *,int> *)&vtxOffVertex,
                              num: vtxOffVertex.m_Size - vtxOffVertex.m_Memory.m_nAllocationCount + 1);
                            v101 = vtxOffVertex.m_Size;
                          }
                          v103 = vtxOffVertex.m_Memory.m_pMemory;
                          v104 = v101 + 1;
                          vtxOffVertex.m_Size = v104;
                          vtxOffVertex.m_pElements = vtxOffVertex.m_Memory.m_pMemory;
                          if ( v104 - v102 - 1 > 0 )
                            _V_memmove(
                              dest: &vtxOffVertex.m_Memory.m_pMemory[v102 + 1],
                              src: &vtxOffVertex.m_Memory.m_pMemory[v102],
                              count: 4 * (v104 - v102 - 1));
                          v105 = &v103[v102];
                          if ( v105 != nullptr )
                            *v105 = offVertex;
                          v106 = v104;
                          if ( v104 + 1 > vtxOffVertex.m_Memory.m_nAllocationCount )
                          {
                            CUtlMemory<int,int>::Grow(
                              this: (CUtlMemory<OptimizedModel::OptimizedIndexBufferMarkupPs3_t *,int> *)&vtxOffVertex,
                              num: v104 - vtxOffVertex.m_Memory.m_nAllocationCount + 1);
                            v104 = vtxOffVertex.m_Size;
                            v103 = vtxOffVertex.m_Memory.m_pMemory;
                          }
                          v107 = v104 + 1;
                          vtxOffVertex.m_Size = v107;
                          vtxOffVertex.m_pElements = v103;
                          if ( v107 - v106 - 1 > 0 )
                            _V_memmove(dest: &v103[v106 + 1], src: &v103[v106], count: 4 * (v107 - v106 - 1));
                          v108 = (OptimizedModel::ModelLODHeader_t **)&v103[v106];
                          if ( v108 != nullptr )
                            *v108 = vtxLod;
                        }
                        v88 = vtxMesh;
                        vvdTangentNew = (Vector4D *)((char *)vvdTangentNew + 33);
                        v86 = vtxHdr;
                        ++mdlModel_idx;
                      }
                      while ( mdlModel_idx < vtxMesh->numStripGroups );
                      v87 = vtxLod_idx;
                      v84 = ppStripInfo;
                      v85 = vtxModel_idx;
                    }
                    memTempVVD.m_p += 9;
                    ++vtxMesh_idx;
                  }
                  while ( vtxMesh_idx < *(_DWORD *)v87 );
                }
                vtxModel_idx = ++v85;
              }
              while ( v85 < (int)*v84 );
            }
            ++v180;
          }
          while ( v180 < vtxBodyPart->numModels );
        }
        ++vtxBodyPart_idx;
      }
      while ( vtxBodyPart_idx < vtxHdr->numBodyParts );
    }
    v109 = vtxHdr;
    v110 = (unsigned int)vtxHdr + vtxOffVertexBuffer;
    ppStripInfo = (IMdlStripInfo **)((char *)vtxHdr + vtxOffVertexBufferEnd);
    v111 = vtxOffVertexBufferEnd - vtxOffVertexBuffer;
    v112 = 0;
    v113 = (int)(vtxOffVertexBufferEnd - vtxOffVertexBuffer) / 9;
    memset(&vtxIndexDeltas, 0, 16);
    if ( v113 > 0 )
    {
      Alloc_2 = _g_pMemAlloc->Alloc_2;
      vtxIndexDeltas.m_Memory.m_nAllocationCount = (int)(vtxOffVertexBufferEnd - vtxOffVertexBuffer) / 9;
      v115 = (int *)Alloc_2(this: _g_pMemAlloc, a2: 4 * v113);
      v109 = vtxHdr;
      vtxIndexDeltas.m_Memory.m_pMemory = v115;
    }
    vtxIndexDeltas.m_pElements = vtxIndexDeltas.m_Memory.m_pMemory;
    vtxMatList_idx = 0;
    if ( v110 < (unsigned int)ppStripInfo )
    {
      vtxMesh = (OptimizedModel::MeshHeader_t *)(v110 - (_DWORD)v109);
      vtxLod = (OptimizedModel::ModelLODHeader_t *)(-4 - v110);
      ppStripInfo = (IMdlStripInfo **)(v110 + 4);
      offVertex = (v111 - 1) / 9 + 1;
      do
      {
        v116 = (char *)ppStripInfo + (_DWORD)vtxLod + (unsigned int)vtxMesh;
        v117 = 0;
        if ( vtxOffVertex.m_Size <= 0 )
        {
LABEL_172:
          CMemoryMovingTracker::RegisterBytes(this: &vtxRemove, pos: (unsigned __int8 *)ppStripInfo - 4, length: 9);
          v118 = v112;
          if ( v112 + 1 > vtxIndexDeltas.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<int,int>::Grow(
              this: (CUtlMemory<OptimizedModel::OptimizedIndexBufferMarkupPs3_t *,int> *)&vtxIndexDeltas,
              num: v112 - vtxIndexDeltas.m_Memory.m_nAllocationCount + 1);
            v112 = vtxIndexDeltas.m_Size;
          }
          v119 = vtxIndexDeltas.m_Memory.m_pMemory;
          vtxIndexDeltas.m_Size = ++v112;
          vtxIndexDeltas.m_pElements = vtxIndexDeltas.m_Memory.m_pMemory;
          if ( v112 - v118 - 1 > 0 )
            _V_memmove(
              dest: &vtxIndexDeltas.m_Memory.m_pMemory[v118 + 1],
              src: &vtxIndexDeltas.m_Memory.m_pMemory[v118],
              count: 4 * (v112 - v118 - 1));
          v120 = &v119[v118];
          if ( v120 != nullptr )
            *v120 = 0;
          ++vtxMatList_idx;
        }
        else
        {
          while ( (unsigned int)v116 < vtxOffVertex.m_Memory.m_pMemory[v117]
               || (unsigned int)v116 >= vtxOffVertex.m_Memory.m_pMemory[v117 + 1] )
          {
            v117 += 2;
            if ( v117 >= vtxOffVertex.m_Size )
              goto LABEL_172;
          }
          mdlRangeItem.m_offOld = 0;
          mdlRangeItem.m_numOld = 0;
          mdlRangeItem.m_numNew = 0;
          v121 = (_DWORD *)vtxStripGroup_idx;
          mdlRangeItem.m_offNew = ((int)ppStripInfo + (int)vtxLod) / 9;
          LessOrEqual = CUtlSortVector<CMdlStripInfo::MdlRangeItem,CLessSimple<CMdlStripInfo::MdlRangeItem>>::FindLessOrEqual(
                          this: (CUtlSortVector<CMdlStripInfo::MdlRangeItem,CLessSimple<CMdlStripInfo::MdlRangeItem> > *)vtxStripGroup_idx,
                          src: &mdlRangeItem);
          v123 = ppStripInfo;
          v124 = (_WORD *)(*v121 + 16 * LessOrEqual);
          mdlModel_idx = (unsigned __int16)(*v124 + *(_WORD *)ppStripInfo);
          *(_WORD *)v123 = CUtlSortVector<unsigned short,CLessSimple<unsigned short>>::Find(
                             this: srcIndices,
                             src: (unsigned __int16 *)&mdlModel_idx)
                         - v124[2];
          v125 = v112;
          if ( v112 + 1 > vtxIndexDeltas.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<int,int>::Grow(
              this: (CUtlMemory<OptimizedModel::OptimizedIndexBufferMarkupPs3_t *,int> *)&vtxIndexDeltas,
              num: v112 - vtxIndexDeltas.m_Memory.m_nAllocationCount + 1);
            v112 = vtxIndexDeltas.m_Size;
          }
          v126 = vtxIndexDeltas.m_Memory.m_pMemory;
          vtxIndexDeltas.m_Size = ++v112;
          vtxIndexDeltas.m_pElements = vtxIndexDeltas.m_Memory.m_pMemory;
          if ( v112 - v125 - 1 > 0 )
            _V_memmove(
              dest: &vtxIndexDeltas.m_Memory.m_pMemory[v125 + 1],
              src: &vtxIndexDeltas.m_Memory.m_pMemory[v125],
              count: 4 * (v112 - v125 - 1));
          v127 = &v126[v125];
          if ( v127 != nullptr )
            *v127 = vtxMatList_idx;
        }
        ppStripInfo = (IMdlStripInfo **)((char *)ppStripInfo + 9);
        --offVertex;
      }
      while ( offVertex != 0 );
      v109 = vtxHdr;
    }
    v128 = (unsigned __int8 *)v109 + vtxStrip_idx;
    ppStripInfo = (IMdlStripInfo **)((char *)v109 + vtxOffIndexBufferEnd);
    if ( (char *)v109 + vtxStrip_idx < (char *)v109 + vtxOffIndexBufferEnd )
    {
      v129 = vtxOffIndex.m_Memory.m_pMemory;
      v130 = v128 - (unsigned __int8 *)vtxHdr;
      do
      {
        v131 = 0;
        if ( vtxOffIndex.m_Size <= 0 )
        {
LABEL_193:
          CMemoryMovingTracker::RegisterBytes(this: &vtxRemove, pos: v128, length: 2);
        }
        else
        {
          while ( v130 < v129[v131] || v130 >= v129[v131 + 1] )
          {
            v131 += 2;
            if ( v131 >= vtxOffIndex.m_Size )
              goto LABEL_193;
          }
          *(_WORD *)v128 -= LOWORD(vtxIndexDeltas.m_Memory.m_pMemory[*(unsigned __int16 *)v128]);
        }
        v128 += 2;
        v130 += 2;
      }
      while ( v128 < (unsigned __int8 *)ppStripInfo );
    }
    CInsertionTracker::Finalize(this: (CMdlLib *)&vtxRemove);
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_ModelLib, a2: 0) != 0 )
    {
      NumBytesRegistered = CMemoryMovingTracker::GetNumBytesRegistered(this: &vtxRemove);
      _LoggingSystem_Log(a1: LOG_ModelLib, a2: 0, a3: " Stripped %d vtx bytes.\n", NumBytesRegistered);
    }
    v18 = vtxHdr->numLODs <= 0;
    vtxStrip_idx = 0;
    if ( !v18 )
    {
      do
      {
        v133 = (char *)vtxHdr + 8 * vtxStrip_idx + vtxHdr->materialReplacementListOffset;
        v134 = 0;
        if ( *(int *)v133 > 0 )
        {
          ppStripInfo = nullptr;
          do
          {
            v135 = &v133[*((_DWORD *)v133 + 1) + (_DWORD)ppStripInfo];
            v136 = CMemoryMovingTracker::ComputeOffset(
                     this: &vtxRemove,
                     ptrBase: (unsigned __int8 *)v135,
                     off: *(_DWORD *)(v135 + 2));
            ppStripInfo = (IMdlStripInfo **)((char *)ppStripInfo + 6);
            ++v134;
            *(_DWORD *)(v135 + 2) = v136;
          }
          while ( v134 < *(_DWORD *)v133 );
        }
        *((_DWORD *)v133 + 1) = CMemoryMovingTracker::ComputeOffset(
                                  this: &vtxRemove,
                                  ptrBase: (unsigned __int8 *)v133,
                                  off: *((_DWORD *)v133 + 1));
        ++vtxStrip_idx;
      }
      while ( vtxStrip_idx < vtxHdr->numLODs );
    }
    v18 = vtxHdr->numBodyParts <= 0;
    v184 = 0;
    if ( !v18 )
    {
      do
      {
        v18 = *(int *)((char *)&vtxHdr->version + 8 * v184 + vtxHdr->bodyPartOffset) <= 0;
        vtxLod_idx = (int)vtxHdr + 8 * v184 + vtxHdr->bodyPartOffset;
        vtxModel_idx = 0;
        if ( !v18 )
        {
          do
          {
            v137 = (unsigned __int8 *)(*(_DWORD *)(vtxLod_idx + 4) + vtxLod_idx + 8 * vtxModel_idx);
            vtxBodyPart = nullptr;
            v18 = *(_DWORD *)v137 <= 0;
            memTempVVD.m_p = v137;
            if ( !v18 )
            {
              vvdTangentNew = nullptr;
              do
              {
                v138 = (OptimizedModel::ModelLODHeader_t *)((char *)vvdTangentNew
                                                          + (unsigned int)&memTempVVD.m_p[*((_DWORD *)memTempVVD.m_p + 1)]);
                vtxMesh_idx = 0;
                v18 = v138->numMeshes <= 0;
                vtxLod = v138;
                if ( !v18 )
                {
                  vtxMatList_idx = 0;
                  do
                  {
                    v139 = (CUtlSortVector<unsigned short,CLessSimple<unsigned short> > *)((char *)v138
                                                                                         + v138->meshOffset
                                                                                         + vtxMatList_idx);
                    mdlModel_idx = 0;
                    v18 = (int)v139->m_Memory.m_pMemory <= 0;
                    srcIndices = v139;
                    if ( !v18 )
                    {
                      vtxStrip_idx = 0;
                      do
                      {
                        v140 = (int)v139 + vtxStrip_idx + v139->m_Memory.m_nAllocationCount;
                        offVertex = 0;
                        if ( *(int *)(v140 + 16) > 0 )
                        {
                          ppStripInfo = nullptr;
                          do
                          {
                            v141 = (char *)ppStripInfo + v140 + *(_DWORD *)(v140 + 20);
                            v142 = CMemoryMovingTracker::ComputeOffset(
                                     this: &vtxRemove,
                                     ptrBase: (unsigned __int8 *)v140,
                                     off: *((_DWORD *)v141 + 1) + *(_DWORD *)(v140 + 12));
                            *((_DWORD *)v141 + 1) = v142
                                                  - CMemoryMovingTracker::ComputeOffset(
                                                      this: &vtxRemove,
                                                      ptrBase: (unsigned __int8 *)v140,
                                                      off: *(_DWORD *)(v140 + 12));
                            v143 = CMemoryMovingTracker::ComputeOffset(
                                     this: &vtxRemove,
                                     ptrBase: (unsigned __int8 *)v140,
                                     off: *((_DWORD *)v141 + 3) + *(_DWORD *)(v140 + 4));
                            v144 = CMemoryMovingTracker::ComputeOffset(
                                     this: &vtxRemove,
                                     ptrBase: (unsigned __int8 *)v140,
                                     off: *(_DWORD *)(v140 + 4));
                            v166 = *(_DWORD *)(v141 + 23);
                            *((_DWORD *)v141 + 3) = v143 - v144;
                            v145 = CMemoryMovingTracker::ComputeOffset(
                                     this: &vtxRemove,
                                     ptrBase: (unsigned __int8 *)v141,
                                     off: v166);
                            ppStripInfo = (IMdlStripInfo **)((char *)ppStripInfo + 35);
                            *(_DWORD *)(v141 + 23) = v145;
                            ++offVertex;
                          }
                          while ( (signed int)offVertex < *(_DWORD *)(v140 + 16) );
                          v139 = srcIndices;
                          v138 = vtxLod;
                        }
                        v146 = CMemoryMovingTracker::ComputeOffset(
                                 this: &vtxRemove,
                                 ptrBase: (unsigned __int8 *)v140,
                                 off: *(_DWORD *)(v140 + 4));
                        v166 = *(_DWORD *)(v140 + 12);
                        *(_DWORD *)(v140 + 4) = v146;
                        v147 = CMemoryMovingTracker::ComputeOffset(
                                 this: &vtxRemove,
                                 ptrBase: (unsigned __int8 *)v140,
                                 off: v166);
                        v166 = *(_DWORD *)(v140 + 20);
                        *(_DWORD *)(v140 + 12) = v147;
                        v148 = CMemoryMovingTracker::ComputeOffset(
                                 this: &vtxRemove,
                                 ptrBase: (unsigned __int8 *)v140,
                                 off: v166);
                        vtxStrip_idx += 33;
                        *(_DWORD *)(v140 + 20) = v148;
                        ++mdlModel_idx;
                      }
                      while ( mdlModel_idx < (int)v139->m_Memory.m_pMemory );
                    }
                    v149 = CMemoryMovingTracker::ComputeOffset(
                             this: &vtxRemove,
                             ptrBase: (unsigned __int8 *)v139,
                             off: v139->m_Memory.m_nAllocationCount);
                    vtxMatList_idx += 9;
                    v139->m_Memory.m_nAllocationCount = (int)v149;
                    ++vtxMesh_idx;
                  }
                  while ( vtxMesh_idx < v138->numMeshes );
                }
                v150 = CMemoryMovingTracker::ComputeOffset(
                         this: &vtxRemove,
                         ptrBase: (unsigned __int8 *)v138,
                         off: v138->meshOffset);
                m_p = memTempVVD.m_p;
                vvdTangentNew = (Vector4D *)((char *)vvdTangentNew + 12);
                v138->meshOffset = (int)v150;
                vtxBodyPart = (OptimizedModel::BodyPartHeader_t *)((char *)vtxBodyPart + 1);
              }
              while ( (int)vtxBodyPart < *(_DWORD *)m_p );
            }
            v152 = memTempVVD.m_p;
            v153 = CMemoryMovingTracker::ComputeOffset(
                     this: &vtxRemove,
                     ptrBase: memTempVVD.m_p,
                     off: *((_DWORD *)memTempVVD.m_p + 1));
            v154 = (int *)vtxLod_idx;
            *((_DWORD *)v152 + 1) = v153;
            v155 = vtxModel_idx + 1;
            *(_DWORD *)v152 = 1;
            vtxModel_idx = v155;
          }
          while ( v155 < *v154 );
        }
        v156 = vtxLod_idx;
        *(_DWORD *)(v156 + 4) = CMemoryMovingTracker::ComputeOffset(
                                  this: &vtxRemove,
                                  ptrBase: (unsigned __int8 *)vtxLod_idx,
                                  off: *(_DWORD *)(vtxLod_idx + 4));
        ++v184;
      }
      while ( v184 < vtxHdr->numBodyParts );
    }
    vtxHdr->materialReplacementListOffset = (int)CMemoryMovingTracker::ComputeOffset(
                                                   this: &vtxRemove,
                                                   ptrBase: (unsigned __int8 *)vtxHdr,
                                                   off: vtxHdr->materialReplacementListOffset);
    vtxHdr->bodyPartOffset = (int)CMemoryMovingTracker::ComputeOffset(
                                    this: &vtxRemove,
                                    ptrBase: (unsigned __int8 *)vtxHdr,
                                    off: vtxHdr->bodyPartOffset);
    vtxHdr->numLODs = 1;
    CMemoryMovingTracker::MemMove(this: &vtxRemove, ptrBase: vtxHdr, length: &vtxLength);
    v157 = vvdLength;
    CUtlBuffer::SeekPut(this: vvdBuffer, type: SEEK_CURRENT, offset: vvdLength + vvdBuffer->m_Get - vvdBuffer->m_Put);
    CUtlBuffer::SeekPut(this: vtxBuffer, type: SEEK_CURRENT, offset: vtxLength + vtxBuffer->m_Get - vtxBuffer->m_Put);
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_ModelLib, a2: 0) != 0 )
    {
      v158 = CMemoryMovingTracker::GetNumBytesRegistered(this: &vtxRemove);
      _LoggingSystem_Log(
        a1: LOG_ModelLib,
        a2: 0,
        a3: " Reduced model buffers by %d bytes.\n",
        (char *)mdlBodyPart + v158 - v157);
    }
    if ( vtxIndexDeltas.m_Memory.m_nGrowSize >= 0 && vtxIndexDeltas.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vtxIndexDeltas.m_Memory.m_pMemory);
    if ( vtxOffVertex.m_Memory.m_nGrowSize >= 0 && vtxOffVertex.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vtxOffVertex.m_Memory.m_pMemory);
    if ( vtxOffIndex.m_Memory.m_nGrowSize >= 0 && vtxOffIndex.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vtxOffIndex.m_Memory.m_pMemory);
    CUtlRBTree<CUtlMap<unsigned char *,int,unsigned int>::Node_t,unsigned int,CUtlMap<unsigned char *,int,unsigned int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned char *,int,unsigned int>::Node_t,unsigned int>,unsigned int>>::RemoveAll(this: &vtxRemove.m_map.m_Tree);
    v159 = vtxRemove.m_map.m_Tree.m_Elements.m_pMemory;
    vtxRemove.m_map.m_Tree.m_FirstFree = -1;
    if ( vtxRemove.m_map.m_Tree.m_Elements.m_nGrowSize >= 0 )
    {
      if ( vtxRemove.m_map.m_Tree.m_Elements.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vtxRemove.m_map.m_Tree.m_Elements.m_pMemory);
        v159 = nullptr;
        vtxRemove.m_map.m_Tree.m_Elements.m_pMemory = nullptr;
      }
      vtxRemove.m_map.m_Tree.m_Elements.m_nAllocationCount = 0;
    }
    vtxRemove.m_map.m_Tree.m_LastAlloc.index = -1;
    if ( vtxRemove.m_map.m_Tree.m_Elements.m_nGrowSize >= 0 )
    {
      if ( v159 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v159);
        vtxRemove.m_map.m_Tree.m_Elements.m_pMemory = nullptr;
      }
      vtxRemove.m_map.m_Tree.m_Elements.m_nAllocationCount = 0;
    }
    msi.__vftable = (CMdlStripInfo_vtbl *)&CMdlStripInfo::`vftable';
    CUtlVector<CMdlStripInfo::Ps3studioBatch_t *,CUtlMemory<CMdlStripInfo::Ps3studioBatch_t *,int>>::PurgeAndDeleteElements(this: &msi.m_ps3studioBatches);
    v160 = msi.m_vtxMdlOffsets.m_Memory.m_pMemory;
    msi.m_vtxMdlOffsets.m_Size = 0;
    if ( msi.m_vtxMdlOffsets.m_Memory.m_nGrowSize >= 0 )
    {
      if ( msi.m_vtxMdlOffsets.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: msi.m_vtxMdlOffsets.m_Memory.m_pMemory);
        v160 = nullptr;
        msi.m_vtxMdlOffsets.m_Memory.m_pMemory = nullptr;
      }
      msi.m_vtxMdlOffsets.m_Memory.m_nAllocationCount = 0;
    }
    msi.m_vtxMdlOffsets.m_pElements = v160;
    if ( msi.m_vtxMdlOffsets.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v160 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v160);
        msi.m_vtxMdlOffsets.m_Memory.m_pMemory = nullptr;
      }
      msi.m_vtxMdlOffsets.m_Memory.m_nAllocationCount = 0;
    }
    v161 = msi.m_ps3studioStripGroupHeaderBatchOffset.m_Memory.m_pMemory;
    msi.m_ps3studioStripGroupHeaderBatchOffset.m_Size = 0;
    if ( msi.m_ps3studioStripGroupHeaderBatchOffset.m_Memory.m_nGrowSize >= 0 )
    {
      if ( msi.m_ps3studioStripGroupHeaderBatchOffset.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: msi.m_ps3studioStripGroupHeaderBatchOffset.m_Memory.m_pMemory);
        v161 = nullptr;
        msi.m_ps3studioStripGroupHeaderBatchOffset.m_Memory.m_pMemory = nullptr;
      }
      msi.m_ps3studioStripGroupHeaderBatchOffset.m_Memory.m_nAllocationCount = 0;
    }
    msi.m_ps3studioStripGroupHeaderBatchOffset.m_pElements = v161;
    if ( msi.m_ps3studioStripGroupHeaderBatchOffset.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v161 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v161);
        msi.m_ps3studioStripGroupHeaderBatchOffset.m_Memory.m_pMemory = nullptr;
      }
      msi.m_ps3studioStripGroupHeaderBatchOffset.m_Memory.m_nAllocationCount = 0;
    }
    v162 = msi.m_ps3studioBatches.m_Memory.m_pMemory;
    msi.m_ps3studioBatches.m_Size = 0;
    if ( msi.m_ps3studioBatches.m_Memory.m_nGrowSize >= 0 )
    {
      if ( msi.m_ps3studioBatches.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: msi.m_ps3studioBatches.m_Memory.m_pMemory);
        v162 = nullptr;
        msi.m_ps3studioBatches.m_Memory.m_pMemory = nullptr;
      }
      msi.m_ps3studioBatches.m_Memory.m_nAllocationCount = 0;
    }
    msi.m_ps3studioBatches.m_pElements = v162;
    if ( msi.m_ps3studioBatches.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v162 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v162);
        msi.m_ps3studioBatches.m_Memory.m_pMemory = nullptr;
      }
      msi.m_ps3studioBatches.m_Memory.m_nAllocationCount = 0;
    }
    v163 = msi.m_vtxIndices.m_Memory.m_pMemory;
    msi.m_vtxIndices.m_Size = 0;
    if ( msi.m_vtxIndices.m_Memory.m_nGrowSize >= 0 )
    {
      if ( msi.m_vtxIndices.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: msi.m_vtxIndices.m_Memory.m_pMemory);
        v163 = nullptr;
        msi.m_vtxIndices.m_Memory.m_pMemory = nullptr;
      }
      msi.m_vtxIndices.m_Memory.m_nAllocationCount = 0;
    }
    msi.m_vtxIndices.m_pElements = v163;
    if ( msi.m_vtxIndices.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v163 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v163);
        msi.m_vtxIndices.m_Memory.m_pMemory = nullptr;
      }
      msi.m_vtxIndices.m_Memory.m_nAllocationCount = 0;
    }
    if ( msi.m_vtxVerts.m_numInts > 1 )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: msi.m_vtxVerts.m_pInt);
    return 1;
  }
  else
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_ModelLib, a2: 0) != 0 )
      _LoggingSystem_Log(a1: LOG_ModelLib, a2: 0, a3: "ERROR: [StripModelBuffers] checksum mismatch!\n");
    return 0;
  }
}
