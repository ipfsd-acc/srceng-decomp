// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/vprof_record.cpp
// Functions: 73
// ============================================================

#include "engine\vprof_record.h"

//------------------------------------------------------------------------------
// Address: 0x100BD980
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx

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
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: 28 * m_nAllocationCount);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 28 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F7320
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned short,struct MatViewOverride::ViewParamsLast::VarMap,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
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
    v7 = 44 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016DF90
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned short,struct PropIndicesCollection_t,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx

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
        m_nAllocationCount = 3;
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
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: 14 * m_nAllocationCount);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 14 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AEF00
// Name: public: static bool CDefOps<struct netadr_s>::LessFunc(struct netadr_s const __near &,struct netadr_s const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CDefOps<netadr_s>::LessFunc(netadr_s *lhs, const netadr_s *rhs)
{
  return netadr_s::operator<(this: lhs, netadr: rhs);
}

//------------------------------------------------------------------------------
// Address: 0x101CEA00
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class CUtlSymbol,struct CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
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
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E85F0
// Name: public: CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(
        CUtlBuffer *this)
{
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F2050
// Name: public: void CCycleCount::SetMicroseconds(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCycleCount::SetMicroseconds(CCycleCount *this, unsigned int nMicroseconds)
{
  __int64 v2; // [esp-8h] [ebp-Ch]

  HIDWORD(v2) = HIDWORD(_g_ClockSpeed);
  LODWORD(v2) = _g_ClockSpeed;
  this->m_Int64 = (unsigned __int64)nMicroseconds * v2 / 0xF4240;
}

//------------------------------------------------------------------------------
// Address: 0x101F2090
// Name: public: static bool CDefOps<char __near *>::LessFunc(char __near * const __near &,char __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CDefOps<char *>::LessFunc(const char **lhs, const char **rhs)
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
// Address: 0x101F20F0
// Name: public: void CVProfRecorder::Stop(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfRecorder::Stop(CVProfRecorder *this)
{
  int m_Mode; // eax
  void *m_hFile; // edx

  m_Mode = this->m_Mode;
  if ( m_Mode == 1 || m_Mode == 2 )
  {
    m_hFile = this->m_hFile;
    if ( m_hFile != nullptr )
    {
      if ( m_Mode == 1 )
        ++this->m_nQueuedStops;
      g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: m_hFile);
    }
  }
  this->m_Mode = 0;
  this->m_hFile = nullptr;
  g_pVProfileForDisplay = *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled;
  this->m_iPlaybackTick = -1;
  this->m_bNodesChanged = true;
  CVProfile::Term(this);
}

//------------------------------------------------------------------------------
// Address: 0x101F2170
// Name: public: bool CVProfRecorder::Playback_ReadString(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVProfRecorder::Playback_ReadString(CVProfRecorder *this, char *pOut, int maxLen)
{
  int v4; // esi
  char v6; // [esp+Fh] [ebp-1h] BYREF

  v4 = 0;
  if ( g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: &v6, a3: 1, a4: this->m_hFile) != 0 )
  {
    while ( v6 != 0 )
    {
      if ( v4 < maxLen - 1 )
        pOut[v4++] = v6;
      if ( g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: &v6, a3: 1, a4: this->m_hFile) == 0 )
        goto LABEL_6;
    }
    pOut[v4] = 0;
    return 1;
  }
  else
  {
LABEL_6:
    CVProfRecorder::Stop(this);
    _Warning(a1: "VPROF PLAYBACK ASSERT (%s, line %d) - stopping playback.\n", "vprof_record.cpp", 402);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F2210
// Name: public: class CVProfNode __near * CVProfRecorder::FindVProfNodeByID_R(class CVProfNode __near *,int)
// Source: json
//------------------------------------------------------------------------------
CVProfNode *__thiscall CVProfRecorder::FindVProfNodeByID_R(CVProfRecorder *this, CVProfNode *pNode, int id)
{
  CVProfNode *result; // eax
  CVProfNode *m_pChild; // esi

  result = pNode;
  if ( pNode->m_iUniqueNodeID != id )
  {
    m_pChild = pNode->m_pChild;
    if ( m_pChild != nullptr )
    {
      while ( 1 )
      {
        result = CVProfRecorder::FindVProfNodeByID_R(this, pNode: m_pChild, id);
        if ( result != nullptr )
          break;
        m_pChild = m_pChild->m_pSibling;
        if ( m_pChild == nullptr )
          return nullptr;
      }
    }
    else
    {
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F2250
// Name: public: void CVProfRecorder::StartOrStop(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfRecorder::StartOrStop(CVProfRecorder *this)
{
  while ( this->m_nQueuedStarts > 0 )
  {
    --this->m_nQueuedStarts;
    if ( ++*(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4108) == 1 )
      CVProfNode::EnterScope(this: (CVProfNode *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4120));
  }
  while ( this->m_nQueuedStops > 0 )
  {
    --this->m_nQueuedStops;
    if ( (*(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4108))-- == 1 )
      CVProfNode::ExitScope(this: (CVProfNode *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4120));
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F22E0
// Name: vprof_record_stop
// Source: json
//------------------------------------------------------------------------------
void __cdecl vprof_record_stop()
{
  _Warning(a1: "Stopping vprof recording...\n");
  CVProfRecorder::Stop(this: &g_VProfRecorder);
}

//------------------------------------------------------------------------------
// Address: 0x101F2300
// Name: vprof_playback_stop
// Source: json
//------------------------------------------------------------------------------
void __cdecl vprof_playback_stop()
{
  _Warning(a1: "Stopping vprof playback...\n");
  CVProfRecorder::Stop(this: &g_VProfRecorder);
}

//------------------------------------------------------------------------------
// Address: 0x101F2320
// Name: void VProfRecord_StartOrStop(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VProfRecord_StartOrStop()
{
  CVProfRecorder::StartOrStop(this: &g_VProfRecorder);
}

//------------------------------------------------------------------------------
// Address: 0x101F2330
// Name: bool VProfRecord_IsPlayingBack(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl VProfRecord_IsPlayingBack()
{
  return g_VProfRecorder.m_Mode == 2;
}

//------------------------------------------------------------------------------
// Address: 0x101F2340
// Name: int VProfPlayback_GetCurrentTick(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl VProfPlayback_GetCurrentTick()
{
  return g_VProfRecorder.m_iPlaybackTick;
}

//------------------------------------------------------------------------------
// Address: 0x101F2350
// Name: float VProfPlayback_GetCurrentPercent(void)
// Source: json
//------------------------------------------------------------------------------
double __cdecl VProfPlayback_GetCurrentPercent()
{
  return (double)g_pFileSystem->Tell(this: &g_pFileSystem->IBaseFileSystem, a2: g_VProfRecorder.m_hFile)
       / (double)g_VProfRecorder.m_FileLen;
}

//------------------------------------------------------------------------------
// Address: 0x101F2390
// Name: void VProfRecord_Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VProfRecord_Shutdown()
{
  CVProfRecorder::Stop(this: &g_VProfRecorder);
}

//------------------------------------------------------------------------------
// Address: 0x101F23A0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char __near *,double,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char *,double,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short> *m_pMemory; // edx
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
    v7 = 24 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F2520
// Name: public: void CVProfRecorder::DumpAverages_R(class CUtlVector<class CVProfRecorder::CNodeAverage,class CUtlMemory<class CVProfRecorder::CNodeAverage,int>> __near &,class CVProfNode __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfRecorder::DumpAverages_R(
        CVProfRecorder *this,
        CUtlVector<CVProfRecorder::CNodeAverage,CUtlMemory<CVProfRecorder::CNodeAverage,int> > *averages,
        CVProfNode *pNode)
{
  int m_Size; // ecx
  int v4; // eax
  CVProfRecorder::CNodeAverage *m_pMemory; // edx
  CVProfRecorder::CNodeAverage *v6; // edi
  int m_Int64_high; // ecx
  unsigned int m_nCurFrameCalls; // edx
  CVProfNode *i; // esi

  m_Size = averages->m_Size;
  v4 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = averages->m_Memory.m_pMemory;
    while ( m_pMemory->m_pNode != pNode )
    {
      ++v4;
      ++m_pMemory;
      if ( v4 >= m_Size )
        goto LABEL_8;
    }
    v6 = &averages->m_Memory.m_pMemory[v4];
    if ( v6 != nullptr )
    {
      pNode->m_CurFrameTime.m_Int64 = v6->m_CurFrameTime_Total.m_Int64 / v6->m_nSamples;
      pNode->m_nCurFrameCalls = v6->m_nCurFrameCalls_Total / v6->m_nSamples;
    }
  }
LABEL_8:
  m_Int64_high = HIDWORD(pNode->m_CurFrameTime.m_Int64);
  m_nCurFrameCalls = pNode->m_nCurFrameCalls;
  LODWORD(pNode->m_PrevFrameTime.m_Int64) = pNode->m_CurFrameTime.m_Int64;
  HIDWORD(pNode->m_PrevFrameTime.m_Int64) = m_Int64_high;
  pNode->m_nPrevFrameCalls = m_nCurFrameCalls;
  for ( i = pNode->m_pChild; i != nullptr; i = i->m_pSibling )
    CVProfRecorder::DumpAverages_R(this, averages, pNode: i);
}

//------------------------------------------------------------------------------
// Address: 0x101F25C0
// Name: protected: void CVPROFToCSVConverter::WriteHeaders(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVPROFToCSVConverter::WriteHeaders(CVPROFToCSVConverter *this, char *szBuffer, int nBufferSize)
{
  int i; // esi

  V_strncpy(pDest: szBuffer, pSrc: "Tick Number,", maxLen: nBufferSize);
  for ( i = 0; i < this->m_labelVector.m_Size; ++i )
  {
    V_strncat(
      pDest: szBuffer,
      pSrc: this->m_labelVector.m_Memory.m_pMemory[i],
      destBufferSize: nBufferSize,
      max_chars_to_copy: -1);
    if ( i != this->m_labelVector.m_Size - 1 )
      V_strncat(pDest: szBuffer, pSrc: ",", destBufferSize: nBufferSize, max_chars_to_copy: -1);
  }
  V_strncat(pDest: szBuffer, pSrc: "\n", destBufferSize: nBufferSize, max_chars_to_copy: -1);
}

//------------------------------------------------------------------------------
// Address: 0x101F2640
// Name: public: void CVProfRecorder::Write<unsigned char>(unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfRecorder::Write<unsigned char>(CVProfRecorder *this, unsigned __int8 *pData)
{
  unsigned __int8 *v3; // eax
  unsigned __int8 src; // [esp+7h] [ebp-1h] BYREF

  if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
  {
    v3 = pData;
    if ( pData == nullptr )
      v3 = (unsigned __int8 *)&pData + 3;
    src = *v3;
    _V_memcpy(dest: (char *)&pData + 3, &src, count: 1);
    g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: (char *)&pData + 3, a3: 1, a4: this->m_hFile);
  }
  else
  {
    g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: pData, a3: 1, a4: this->m_hFile);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F26C0
// Name: public: void CVProfRecorder::Write<unsigned short>(unsigned short __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfRecorder::Write<unsigned short>(CVProfRecorder *this, unsigned __int16 **pData)
{
  unsigned __int16 **p_pData; // eax
  char v4; // dl
  char v5; // al
  _WORD src[2]; // [esp+4h] [ebp-4h] BYREF

  if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
  {
    p_pData = pData;
    if ( pData == nullptr )
      p_pData = (unsigned __int16 **)&pData;
    v4 = *((_BYTE *)p_pData + 1);
    v5 = *(_BYTE *)p_pData;
    src[1] = 0;
    LOBYTE(src[0]) = v4;
    HIBYTE(src[0]) = v5;
    _V_memcpy(dest: &pData, src, count: 2);
    g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: &pData, a3: 2, a4: this->m_hFile);
  }
  else
  {
    g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: pData, a3: 2, a4: this->m_hFile);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F2750
// Name: public: void CVProfRecorder::Write<unsigned long>(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfRecorder::Write<unsigned long>(CVProfRecorder *this, unsigned int *pData)
{
  unsigned int *p_swapped; // eax
  char v4; // dl
  char v5; // cl
  char v6; // dl
  char v7; // al
  unsigned int swapped; // [esp+4h] [ebp-4h] BYREF

  if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
  {
    p_swapped = pData;
    if ( pData == nullptr )
      p_swapped = &swapped;
    v4 = *((_BYTE *)p_swapped + 3);
    pData = (unsigned int *)swapped;
    v5 = *((_BYTE *)p_swapped + 2);
    LOBYTE(pData) = v4;
    v6 = *((_BYTE *)p_swapped + 1);
    v7 = *(_BYTE *)p_swapped;
    BYTE1(pData) = v5;
    BYTE2(pData) = v6;
    HIBYTE(pData) = v7;
    _V_memcpy(dest: &swapped, src: &pData, count: 4);
    g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: &swapped, a3: 4, a4: this->m_hFile);
  }
  else
  {
    g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: pData, a3: 4, a4: this->m_hFile);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F27F0
// Name: public: int CVProfRecorder::Read<unsigned char>(unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
int __userpurge CVProfRecorder::Read<unsigned char>@<eax>(
        CVProfRecorder *this@<ecx>,
        int a2@<esi>,
        unsigned __int8 *pData)
{
  bool v3; // zf
  int (__thiscall *Read)(IBaseFileSystem *, void *, int, void *); // edx
  void *m_hFile; // ecx
  int v6; // esi
  unsigned __int8 *v8; // [esp-Eh] [ebp-10h]
  CVProfRecorder *v9; // [esp-2h] [ebp-4h] OVERLAPPED BYREF

  v9 = this;
  v3 = (*(_BYTE *)&this->m_Byteswap & 1) == 0;
  Read = g_pFileSystem->Read;
  m_hFile = this->m_hFile;
  if ( v3 )
    return ((int (__thiscall *)(IBaseFileSystem *, unsigned __int8 *, int, void *, CVProfRecorder *))Read)(
             a1: &g_pFileSystem->IBaseFileSystem,
             a2: pData,
             a3: 1,
             a4: m_hFile,
             a5: v9);
  v6 = ((int (__thiscall *)(IBaseFileSystem *, char *, int, void *, int))Read)(
         a1: &g_pFileSystem->IBaseFileSystem,
         a2: (char *)&v9 + 3,
         a3: 1,
         a4: m_hFile,
         a5: a2);
  if ( pData != nullptr )
  {
    v8 = pData;
    HIBYTE(pData) = HIBYTE(v9);
    _V_memcpy(dest: v8, src: (char *)&pData + 3, count: 1);
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x101F2860
// Name: public: int CVProfRecorder::Read<unsigned short>(unsigned short __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
int __userpurge CVProfRecorder::Read<unsigned short>@<eax>(
        CVProfRecorder *this@<ecx>,
        int a2@<esi>,
        unsigned __int16 *pData)
{
  bool v3; // zf
  int (__thiscall *Read)(IBaseFileSystem *, void *, int, void *); // edx
  void *m_hFile; // ecx
  int v6; // esi
  unsigned __int16 *v7; // eax
  CVProfRecorder *tmp; // [esp+0h] [ebp-4h] OVERLAPPED BYREF

  tmp = this;
  v3 = (*(_BYTE *)&this->m_Byteswap & 1) == 0;
  Read = g_pFileSystem->Read;
  m_hFile = this->m_hFile;
  if ( v3 )
    return ((int (__thiscall *)(IBaseFileSystem *, unsigned __int16 *, int, void *, CVProfRecorder *))Read)(
             a1: &g_pFileSystem->IBaseFileSystem,
             a2: pData,
             a3: 2,
             a4: m_hFile,
             a5: tmp);
  v6 = ((int (__thiscall *)(IBaseFileSystem *, CVProfRecorder **, int, void *, int))Read)(
         a1: &g_pFileSystem->IBaseFileSystem,
         a2: &tmp,
         a3: 2,
         a4: m_hFile,
         a5: a2);
  v7 = pData;
  if ( pData != nullptr )
  {
    HIWORD(pData) = 0;
    LOBYTE(pData) = BYTE1(tmp);
    BYTE1(pData) = (_BYTE)tmp;
    _V_memcpy(dest: v7, src: &pData, count: 2);
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x101F28D0
// Name: public: int CVProfRecorder::Read<unsigned long>(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CVProfRecorder::Read<unsigned long>@<eax>(
        CVProfRecorder *this@<ecx>,
        int a2@<esi>,
        unsigned int *pData)
{
  bool v3; // zf
  int (__thiscall *Read)(IBaseFileSystem *, void *, int, void *); // edx
  void *m_hFile; // ecx
  int v6; // esi
  unsigned int *v7; // eax
  unsigned int tmp; // [esp+0h] [ebp-4h] BYREF

  tmp = (unsigned int)this;
  v3 = (*(_BYTE *)&this->m_Byteswap & 1) == 0;
  Read = g_pFileSystem->Read;
  m_hFile = this->m_hFile;
  if ( v3 )
    return ((int (__thiscall *)(IBaseFileSystem *, unsigned int *, int, void *, unsigned int))Read)(
             a1: &g_pFileSystem->IBaseFileSystem,
             a2: pData,
             a3: 4,
             a4: m_hFile,
             a5: tmp);
  v6 = ((int (__thiscall *)(IBaseFileSystem *, unsigned int *, int, void *, int))Read)(
         a1: &g_pFileSystem->IBaseFileSystem,
         a2: &tmp,
         a3: 4,
         a4: m_hFile,
         a5: a2);
  v7 = pData;
  if ( pData != nullptr )
  {
    LOBYTE(pData) = HIBYTE(tmp);
    BYTE1(pData) = BYTE2(tmp);
    BYTE2(pData) = BYTE1(tmp);
    HIBYTE(pData) = tmp;
    _V_memcpy(dest: v7, src: &pData, count: 4);
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x101F31A0
// Name: public: bool CVProfRecorder::Record_Start(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVProfRecorder::Record_Start(CVProfRecorder *this, int pFilename)
{
  char *v3; // edi
  int v4; // eax
  void *v5; // eax
  vgui::CTreeViewListControl *v7; // ecx
  ECommandTarget_t TraceType; // eax
  char tempFilename[512]; // [esp+8h] [ebp-204h] BYREF
  int nodeID; // [esp+208h] [ebp-4h] BYREF

  CVProfRecorder::Stop(this);
  v3 = (char *)pFilename;
  strchr(string: (unsigned __int8 *)pFilename, chr: 0x2Eu);
  if ( v4 == 0 )
  {
    V_snprintf(pDest: tempFilename, maxLen: 512, pFormat: "%s.vprof", v3);
    v3 = tempFilename;
  }
  this->m_iLastUniqueNodeID = -1;
  v5 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: v3, a3: "wb", a4: 0);
  this->m_hFile = v5;
  this->m_Mode = 1;
  if ( v5 == nullptr )
    return 0;
  pFilename = 1;
  CVProfRecorder::Write<unsigned long>(this, pData: (unsigned int *)&pFilename);
  nodeID = *(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4260);
  CVProfRecorder::Write<unsigned long>(this, pData: (unsigned int *)&nodeID);
  ++this->m_nQueuedStarts;
  TraceType = CTraceFilter::GetTraceType(this: v7);
  Cbuf_AddText(eTarget: TraceType, pText: "vprof_on\n", nTickDelay: 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101F3280
// Name: public: void CVProfRecorder::Record_MatchTree_R(class CVProfNode __near *,class CVProfNode const __near *,class CVProfile __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfRecorder::Record_MatchTree_R(
        CVProfRecorder *this,
        CVProfNode *pOut,
        const CVProfNode *pIn,
        CVProfile *pInProfile)
{
  const CVProfNode *v4; // edx
  CVProfNode *v5; // ebx
  CVProfNode *m_pChild; // ecx
  CVProfNode *v8; // eax
  CVProfNode *i; // esi
  bool v10; // zf
  int m_iUniqueNodeID; // edx
  struct CVProfNode *SubNode; // eax
  CVProfNode *v13; // esi
  const CVProfNode *j; // ebx
  int nodeID; // [esp+Ch] [ebp-14h] BYREF
  int budgetGroupID; // [esp+10h] [ebp-10h] BYREF
  int parentNodeID; // [esp+14h] [ebp-Ch] BYREF
  char v18[6]; // [esp+18h] [ebp-8h] BYREF
  char dest; // [esp+1Eh] [ebp-2h] BYREF
  char src; // [esp+1Fh] [ebp-1h] BYREF

  v4 = pIn;
  v5 = pOut;
  if ( pIn->m_pChild != nullptr )
  {
    while ( 1 )
    {
      m_pChild = v5->m_pChild;
      if ( m_pChild != nullptr && v4->m_pChild->m_iUniqueNodeID == m_pChild->m_iUniqueNodeID )
        break;
      v8 = v4->m_pChild;
      for ( i = nullptr; v8 != nullptr; v8 = v8->m_pSibling )
      {
        if ( m_pChild != nullptr && v8->m_iUniqueNodeID == m_pChild->m_iUniqueNodeID )
          break;
        i = v8;
      }
      v10 = (*(_BYTE *)&this->m_Byteswap & 1) == 0;
      m_iUniqueNodeID = v4->m_iUniqueNodeID;
      budgetGroupID = i->m_BudgetGroupID;
      parentNodeID = m_iUniqueNodeID;
      nodeID = i->m_iUniqueNodeID;
      v18[0] = 1;
      if ( v10 )
      {
        g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: v18, a3: 1, a4: this->m_hFile);
      }
      else
      {
        src = 1;
        _V_memcpy(&dest, &src, count: 1);
        g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: &dest, a3: 1, a4: this->m_hFile);
      }
      CVProfRecorder::Write<unsigned long>(this, pData: (unsigned int *)&parentNodeID);
      g_pFileSystem->Write(
        this: &g_pFileSystem->IBaseFileSystem,
        a2: i->m_pszName,
        a3: &i->m_pszName[strlen(i->m_pszName) + 1] - i->m_pszName,
        a4: this->m_hFile);
      CVProfRecorder::Write<unsigned long>(this, pData: (unsigned int *)&budgetGroupID);
      CVProfRecorder::Write<unsigned long>(this, pData: (unsigned int *)&nodeID);
      v5 = pOut;
      SubNode = CVProfNode::GetSubNode(
                  this: pOut,
                  a2: i->m_pszName,
                  a3: 0,
                  a4: *(const char **)(*(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4276)
                                 + 8 * i->m_BudgetGroupID),
                  a5: *(_DWORD *)(*(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4276)
                            + 8 * i->m_BudgetGroupID
                            + 4));
      SubNode->m_BudgetGroupID = i->m_BudgetGroupID;
      SubNode->m_iUniqueNodeID = i->m_iUniqueNodeID;
      v4 = pIn;
    }
  }
  v13 = v5->m_pChild;
  for ( j = v4->m_pChild; v13 != nullptr; j = j->m_pSibling )
  {
    if ( j == nullptr )
      break;
    CVProfRecorder::Record_MatchTree_R(this, pOut: v13, pIn: j, pInProfile);
    v13 = v13->m_pSibling;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F3430
// Name: public: void CVProfRecorder::Record_MatchBudgetGroups(class CVProfile __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfRecorder::Record_MatchBudgetGroups(CVProfRecorder *this, CVProfile *pInProfile)
{
  int i; // ebx
  bool v4; // zf
  CVProfile::CBudgetGroup *m_pBudgetGroups; // ecx
  char *m_pName; // edi
  int flags; // [esp+10h] [ebp-Ch] BYREF
  char v8[6]; // [esp+14h] [ebp-8h] BYREF
  char dest; // [esp+1Ah] [ebp-2h] BYREF
  char src; // [esp+1Bh] [ebp-1h] BYREF

  for ( i = CVProfile::GetNumBudgetGroups(this); i < CVProfile::GetNumBudgetGroups(this: pInProfile); ++i )
  {
    v4 = (*(_BYTE *)&this->m_Byteswap & 1) == 0;
    m_pBudgetGroups = pInProfile->m_pBudgetGroups;
    m_pName = m_pBudgetGroups[i].m_pName;
    flags = m_pBudgetGroups[i].m_BudgetFlags;
    v8[0] = 2;
    if ( v4 )
    {
      g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: v8, a3: 1, a4: this->m_hFile);
    }
    else
    {
      src = 2;
      _V_memcpy(&dest, &src, count: 1);
      g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: &dest, a3: 1, a4: this->m_hFile);
    }
    g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: m_pName, a3: strlen(m_pName) + 1, a4: this->m_hFile);
    CVProfRecorder::Write<unsigned long>(this, pData: (unsigned int *)&flags);
    CVProfile::AddBudgetGroupName(this, a2: m_pName, a3: flags);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F3540
// Name: public: void CVProfRecorder::Record_WriteTimings_R(class CVProfNode const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfRecorder::Record_WriteTimings_R(CVProfRecorder *this, int pIn)
{
  const CVProfNode *v2; // esi
  unsigned int v3; // eax
  unsigned int v5; // eax
  const CVProfNode *i; // esi
  unsigned __int64 v7; // [esp-Ch] [ebp-1Ch]
  unsigned int nMicroseconds; // [esp+8h] [ebp-8h] BYREF
  int curCalls; // [esp+Ch] [ebp-4h] BYREF

  v2 = (const CVProfNode *)pIn;
  v3 = *(_DWORD *)(pIn + 68);
  if ( v3 >= 0xFFFF )
  {
    curCalls = 0xFFFF;
    goto LABEL_3;
  }
  v3 = (unsigned __int16)v3;
  curCalls = v3;
  if ( (unsigned __int16)v3 >= 0xFFu )
  {
LABEL_3:
    HIBYTE(pIn) = -1;
    CVProfRecorder::Write<unsigned char>(this, pData: (unsigned __int8 *)&pIn + 3);
    CVProfRecorder::Write<unsigned short>(this, pData: (unsigned __int16 **)&curCalls);
    goto LABEL_6;
  }
  HIBYTE(pIn) = v3;
  CVProfRecorder::Write<unsigned char>(this, pData: (unsigned __int8 *)&pIn + 3);
LABEL_6:
  HIDWORD(v7) = HIDWORD(_g_ClockSpeed);
  LODWORD(v7) = _g_ClockSpeed;
  v5 = (unsigned int)(1000000 * v2->m_CurFrameTime.m_Int64 / v7) >> 2;
  nMicroseconds = v5;
  if ( v5 < 0xFFFF )
  {
    pIn = (unsigned __int16)v5;
    CVProfRecorder::Write<unsigned short>(this, pData: (unsigned __int16 **)&pIn);
  }
  else
  {
    pIn = 0xFFFF;
    CVProfRecorder::Write<unsigned short>(this, pData: (unsigned __int16 **)&pIn);
    CVProfRecorder::Write<unsigned long>(this, pData: &nMicroseconds);
  }
  for ( i = v2->m_pChild; i != nullptr; i = i->m_pSibling )
    CVProfRecorder::Record_WriteTimings_R(this, pIn: i);
}

//------------------------------------------------------------------------------
// Address: 0x101F3620
// Name: public: void CVProfRecorder::Record_Snapshot(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfRecorder::Record_Snapshot(CVProfRecorder *this)
{
  bool v2; // zf
  unsigned __int8 pData[4]; // [esp+Ch] [ebp-4h] BYREF

  CVProfile::Pause(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  pData[0] = 0;
  CVProfRecorder::Write<unsigned char>(this, pData);
  CVProfRecorder::Write<unsigned long>(this, pData: (unsigned int *)&g_ClientGlobalVariables.tickcount);
  CVProfRecorder::Record_MatchBudgetGroups(
    this,
    pInProfile: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  if ( this->m_iLastUniqueNodeID != CVProfNode::s_iCurrentUniqueNodeID )
    CVProfRecorder::Record_MatchTree_R(
      this,
      pOut: &this->m_Root,
      pIn: (const CVProfNode *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4120),
      pInProfile: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  pData[0] = 3;
  CVProfRecorder::Write<unsigned char>(this, pData);
  CVProfRecorder::Record_WriteTimings_R(this, pIn: *(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4120);
  pData[0] = 4;
  CVProfRecorder::Write<unsigned char>(this, pData);
  v2 = *(_BYTE *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4112) == 0;
  *(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4108) = *(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled
                                                                                          + 4272);
  if ( v2 )
    CVProfNode::Resume(this: (CVProfNode *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4120));
}

//------------------------------------------------------------------------------
// Address: 0x101F36D0
// Name: public: bool CVProfRecorder::Playback_ReadTimings_R(class CVProfNode __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CVProfRecorder::Playback_ReadTimings_R@<al>(
        CVProfRecorder *this@<ecx>,
        int a2@<esi>,
        unsigned int pNode)
{
  CVProfNode *v5; // edi
  CCycleCount *p_m_CurFrameTime; // esi
  int m_Int64_high; // edx
  CVProfNode *m_pChild; // edi
  __int64 v9; // [esp-10h] [ebp-20h]
  unsigned __int16 microsecondsToken; // [esp+4h] [ebp-Ch] BYREF
  unsigned __int16 curCalls[3]; // [esp+8h] [ebp-8h] BYREF
  unsigned __int8 token; // [esp+Fh] [ebp-1h] BYREF

  if ( CVProfRecorder::Read<unsigned char>(this, a2, pData: &token) != 1 )
    return 0;
  if ( token == 0xFF )
  {
    if ( CVProfRecorder::Read<unsigned short>(this, a2, pData: curCalls) != 2 )
      return 0;
    v5 = (CVProfNode *)pNode;
    *(_DWORD *)(pNode + 68) = curCalls[0];
  }
  else
  {
    v5 = (CVProfNode *)pNode;
    *(_DWORD *)(pNode + 68) = token;
  }
  v5->m_nPrevFrameCalls = v5->m_nCurFrameCalls;
  if ( CVProfRecorder::Read<unsigned short>(this, a2, pData: &microsecondsToken) != 2 )
    return 0;
  if ( microsecondsToken == 0xFFFF )
  {
    if ( CVProfRecorder::Read<unsigned long>(this, a2, pData: &pNode) != 4 )
      return 0;
    p_m_CurFrameTime = &v5->m_CurFrameTime;
    CCycleCount::SetMicroseconds(this: &v5->m_CurFrameTime, nMicroseconds: 4 * pNode);
  }
  else
  {
    HIDWORD(v9) = HIDWORD(_g_ClockSpeed);
    LODWORD(v9) = _g_ClockSpeed;
    p_m_CurFrameTime = &v5->m_CurFrameTime;
    v5->m_CurFrameTime.m_Int64 = (unsigned __int64)(4 * (unsigned int)microsecondsToken) * v9 / 0xF4240;
  }
  m_Int64_high = HIDWORD(p_m_CurFrameTime->m_Int64);
  LODWORD(v5->m_PrevFrameTime.m_Int64) = p_m_CurFrameTime->m_Int64;
  HIDWORD(v5->m_PrevFrameTime.m_Int64) = m_Int64_high;
  m_pChild = v5->m_pChild;
  if ( m_pChild == nullptr )
    return 1;
  while ( CVProfRecorder::Playback_ReadTimings_R(this, pNode: m_pChild) )
  {
    m_pChild = m_pChild->m_pSibling;
    if ( m_pChild == nullptr )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101F37F0
// Name: void VProf_StartRecording(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VProf_StartRecording(const char *pFilename)
{
  CVProfRecorder::Record_Start(this: &g_VProfRecorder, (int)pFilename);
}

//------------------------------------------------------------------------------
// Address: 0x101F3810
// Name: vprof_record_start
// Source: json
//------------------------------------------------------------------------------
void __cdecl vprof_record_start(const CCommand *args)
{
  if ( args->m_nArgc == 2 )
    CVProfRecorder::Record_Start(this: &g_VProfRecorder, pFilename: (int)args->m_ppArgv[1]);
  else
    _Warning(a1: "vprof_record_start requires a filename\n");
}

//------------------------------------------------------------------------------
// Address: 0x101F4860
// Name: public: void CVProfRecorder::UpdateAverages_R(class CUtlVector<class CVProfRecorder::CNodeAverage,class CUtlMemory<class CVProfRecorder::CNodeAverage,int>> __near &,class CVProfNode __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfRecorder::UpdateAverages_R(
        CVProfRecorder *this,
        CUtlVector<CVProfRecorder::CNodeAverage,CUtlMemory<CVProfRecorder::CNodeAverage,int> > *averages,
        CVProfNode *pNode)
{
  int m_Size; // ecx
  int v4; // eax
  CVProfRecorder::CNodeAverage *m_pMemory; // edx
  CVProfRecorder::CNodeAverage *v6; // eax
  int m_Int64; // ecx
  bool v8; // cf
  CVProfNode *i; // esi

  m_Size = averages->m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = averages->m_Memory.m_pMemory;
  while ( m_pMemory->m_pNode != pNode )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= m_Size )
      goto LABEL_7;
  }
  v6 = &averages->m_Memory.m_pMemory[v4];
  if ( v6 == nullptr )
  {
LABEL_7:
    v6 = &averages->m_Memory.m_pMemory[CUtlVector<CVProfRecorder::CNodeAverage,CUtlMemory<CVProfRecorder::CNodeAverage,int>>::InsertBefore(
                                         this: averages,
                                         elem: averages->m_Size)];
    *((_DWORD *)&v6->m_pNode + 1) = 0;
    LODWORD(v6->m_CurFrameTime_Total.m_Int64) = 0;
    HIDWORD(v6->m_CurFrameTime_Total.m_Int64) = 0;
    v6->m_nCurFrameCalls_Total = 0;
    v6->m_nSamples = 0;
    v6->m_pNode = pNode;
  }
  m_Int64 = pNode->m_CurFrameTime.m_Int64;
  v8 = __CFADD__(m_Int64, v6->m_CurFrameTime_Total.m_Int64);
  LODWORD(v6->m_CurFrameTime_Total.m_Int64) += m_Int64;
  HIDWORD(v6->m_CurFrameTime_Total.m_Int64) += HIDWORD(pNode->m_CurFrameTime.m_Int64) + v8;
  v6->m_nCurFrameCalls_Total += pNode->m_nCurFrameCalls;
  ++v6->m_nSamples;
  for ( i = pNode->m_pChild; i != nullptr; i = i->m_pSibling )
    CVProfRecorder::UpdateAverages_R(this, averages, pNode: i);
}

//------------------------------------------------------------------------------
// Address: 0x101F4A40
// Name: public: CVProfRecorder::CVProfRecorder(void)
// Source: json
//------------------------------------------------------------------------------
CVProfRecorder *__thiscall CVProfRecorder::CVProfRecorder(CVProfRecorder *this)
{
  CVProfile::CVProfile(this);
  this->m_PooledStrings.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_PooledStrings.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_PooledStrings.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_PooledStrings.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_PooledStrings.m_Elements.m_Tree.m_Root = -1;
  this->m_PooledStrings.m_Elements.m_Tree.m_NumElements = 0;
  this->m_PooledStrings.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_PooledStrings.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_PooledStrings.m_Elements.m_Tree.m_pElements = this->m_PooledStrings.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_PooledStrings.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_PooledStrings.m_Elements.m_Tree.m_LessFunc.m_LessFunc = CaselessStringLessThan;
  *(_DWORD *)&this->m_Byteswap &= 0xFFFFFFFC;
  this->m_Mode = 0;
  this->m_hFile = nullptr;
  this->m_nQueuedStarts = 0;
  this->m_nQueuedStops = 0;
  this->m_iPlaybackTick = -1;
  *(_DWORD *)&this->m_Byteswap &= 0xFFFFFFFC;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101F4AD0
// Name: protected: void CVPROFToCSVConverter::WriteNodeDataToDict(class CVProfNode __near *,class CUtlMap<char __near *,double,unsigned short> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVPROFToCSVConverter::WriteNodeDataToDict(
        CVPROFToCSVConverter *this,
        CVProfNode *pNode,
        CUtlMap<char *,double,unsigned short> *pTickDataMap)
{
  CVProfNode *v4; // edi
  char *m_pszName; // ebx
  CUtlMap<char *,int,unsigned short> *m_pTokenMap; // ecx
  int m_Size; // edi
  int v8; // eax
  char **m_pMemory; // ecx
  int m_nAllocationCount; // eax
  char **v11; // ecx
  int v12; // eax
  char **v13; // eax
  CVProfNode *m_pSibling; // eax
  CUtlMap<char *,double,unsigned short>::Node_t insert; // [esp+Ch] [ebp-18h] BYREF
  CUtlMap<char *,int,unsigned short>::Node_t search; // [esp+1Ch] [ebp-8h] BYREF

  while ( 1 )
  {
    v4 = pNode;
    m_pszName = (char *)pNode->m_pszName;
    if ( _V_strcmp(s1: pNode->m_pszName, s2: "Root") != 0 )
    {
      m_pTokenMap = this->m_pTokenMap;
      if ( m_pTokenMap == nullptr
        || m_pTokenMap->m_Tree.m_NumElements == 0
        || (search.key = m_pszName,
            CUtlRBTree<CUtlMap<char *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
              this: &m_pTokenMap->m_Tree,
              &search) != 0xFFFF) )
      {
        m_Size = this->m_labelVector.m_Size;
        v8 = 0;
        if ( m_Size <= 0 )
          goto LABEL_11;
        m_pMemory = this->m_labelVector.m_Memory.m_pMemory;
        while ( *m_pMemory != m_pszName )
        {
          ++v8;
          ++m_pMemory;
          if ( v8 >= m_Size )
            goto LABEL_11;
        }
        if ( v8 == -1 )
        {
LABEL_11:
          m_nAllocationCount = this->m_labelVector.m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<INetMessage *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: m_Size - m_nAllocationCount + 1);
          ++this->m_labelVector.m_Size;
          v11 = this->m_labelVector.m_Memory.m_pMemory;
          v12 = this->m_labelVector.m_Size - m_Size - 1;
          this->m_labelVector.m_pElements = this->m_labelVector.m_Memory.m_pMemory;
          if ( v12 > 0 )
            _V_memmove(dest: &v11[m_Size + 1], src: &v11[m_Size], count: 4 * v12);
          v13 = &this->m_labelVector.m_Memory.m_pMemory[m_Size];
          if ( v13 != nullptr )
            *v13 = m_pszName;
        }
        insert.key = m_pszName;
        insert.elem = CVProfNode::GetCurTime(this: pNode);
        CUtlRBTree<CUtlMap<char *,double,unsigned short>::Node_t,unsigned short,CUtlMap<char *,double,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char *,double,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
          this: &pTickDataMap->m_Tree,
          &insert);
        v4 = pNode;
      }
    }
    m_pSibling = v4->m_pSibling;
    if ( m_pSibling != nullptr )
      CVPROFToCSVConverter::WriteNodeDataToDict(this, pNode: m_pSibling, pTickDataMap);
    if ( v4->m_pChild == nullptr )
      break;
    pNode = v4->m_pChild;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F4BE0
// Name: private: char const __near * CVProfRecorder::PoolString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CVProfRecorder::PoolString(CVProfRecorder *this, const char *pStr)
{
  const char *v2; // edi
  int v4; // eax
  CUtlMap<char const *,int,int>::Node_t search; // [esp+8h] [ebp-8h] BYREF

  v2 = pStr;
  if ( pStr == nullptr
    || (search.key = pStr,
        (v4 = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
                this: &this->m_PooledStrings.m_Elements.m_Tree,
                &search)) == -1) )
  {
    pStr = nullptr;
    v4 = CUtlDict<int,int>::Insert(this: &this->m_PooledStrings, pName: v2, element: (const int *)&pStr);
  }
  return this->m_PooledStrings.m_Elements.m_Tree.m_Elements.m_pMemory[v4].m_Data.key;
}

//------------------------------------------------------------------------------
// Address: 0x101F4C40
// Name: public: bool CVProfRecorder::Playback_ReadAddNode(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVProfRecorder::Playback_ReadAddNode(CVProfRecorder *this)
{
  char result; // al
  int v3; // ebx
  CVProfNode *p_m_Root; // eax
  CVProfNode *m_pChild; // edi
  CVProfNode *v6; // edi
  const char *v7; // eax
  struct CVProfNode *SubNode; // eax
  char *m_pName; // [esp-10h] [ebp-220h]
  char nodeName[512]; // [esp+4h] [ebp-20Ch] BYREF
  int parentNodeID; // [esp+204h] [ebp-Ch] BYREF
  int nodeID; // [esp+208h] [ebp-8h] BYREF
  int budgetGroupID; // [esp+20Ch] [ebp-4h] BYREF

  CVProfRecorder::Read<unsigned long>(this, a2: (int)this, pData: (unsigned int *)&parentNodeID);
  result = CVProfRecorder::Playback_ReadString(this, pOut: nodeName, maxLen: 512);
  if ( result != 0 )
  {
    CVProfRecorder::Read<unsigned long>(this, a2: (int)this, pData: (unsigned int *)&budgetGroupID);
    CVProfRecorder::Read<unsigned long>(this, a2: (int)this, pData: (unsigned int *)&nodeID);
    v3 = parentNodeID;
    p_m_Root = &this->m_Root;
    if ( this->m_Root.m_iUniqueNodeID != parentNodeID )
    {
      m_pChild = this->m_Root.m_pChild;
      if ( m_pChild == nullptr )
      {
LABEL_8:
        CVProfRecorder::Stop(this);
        _Warning(a1: "VPROF PLAYBACK ASSERT (%s, line %d) - stopping playback.\n", "vprof_record.cpp", 469);
        return 0;
      }
      while ( 1 )
      {
        p_m_Root = CVProfRecorder::FindVProfNodeByID_R(this, pNode: m_pChild, id: v3);
        if ( p_m_Root != nullptr )
          break;
        m_pChild = m_pChild->m_pSibling;
        if ( m_pChild == nullptr )
          goto LABEL_8;
      }
    }
    v6 = p_m_Root;
    if ( p_m_Root == nullptr )
      goto LABEL_8;
    m_pName = this->m_pBudgetGroups->m_pName;
    v7 = CVProfRecorder::PoolString(this, pStr: nodeName);
    SubNode = CVProfNode::GetSubNode(this: v6, a2: v7, a3: 0, a4: m_pName, a5: 0);
    SubNode->m_BudgetGroupID = budgetGroupID;
    SubNode->m_iUniqueNodeID = nodeID;
    this->m_bNodesChanged = true;
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F4D30
// Name: public: bool CVProfRecorder::Playback_ReadTick(int,bool __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVProfRecorder::Playback_ReadTick(CVProfRecorder *this, int iDontGoPast, bool *pWouldHaveGonePast)
{
  bool *v3; // edi
  bool v5; // zf
  char v6; // al
  char result; // al
  char pOut[512]; // [esp+8h] [ebp-204h] BYREF
  int iPlaybackTick; // [esp+208h] [ebp-4h] BYREF

  v3 = pWouldHaveGonePast;
  if ( pWouldHaveGonePast != nullptr )
    *pWouldHaveGonePast = false;
  if ( this->m_Mode != 2 )
    return 0;
  v5 = CVProfRecorder::Read<unsigned char>(this, a2: (int)this, pData: (unsigned __int8 *)&pWouldHaveGonePast + 3) == 1;
  v6 = 5;
  if ( v5 )
    v6 = HIBYTE(pWouldHaveGonePast);
  if ( v6 == 5 )
  {
    _Msg(a1: "VPROF playback finished.\n");
    this->m_bPlaybackFinished = true;
    return 1;
  }
  if ( v6 != 0 )
  {
    CVProfRecorder::Stop(this);
    _Warning(a1: "VPROF PLAYBACK ASSERT (%s, line %d) - stopping playback.\n", "vprof_record.cpp", 554);
    return 0;
  }
  iPlaybackTick = this->m_iPlaybackTick;
  CVProfRecorder::Read<unsigned long>(this, a2: (int)this, pData: (unsigned int *)&iPlaybackTick);
  if ( iDontGoPast == -1 || iPlaybackTick <= iDontGoPast )
  {
    this->m_iPlaybackTick = iPlaybackTick;
    while ( 1 )
    {
      if ( CVProfRecorder::Read<unsigned char>(this, a2: (int)this, pData: (unsigned __int8 *)&pWouldHaveGonePast + 3) != 1 )
        HIBYTE(pWouldHaveGonePast) = 5;
      if ( SHIBYTE(pWouldHaveGonePast) == 4 )
        break;
      switch ( SHIBYTE(pWouldHaveGonePast) )
      {
        case 2:
          if ( CVProfRecorder::Playback_ReadString(this, pOut, maxLen: 512) == 0 )
            return 0;
          iDontGoPast = 0;
          CVProfRecorder::Read<unsigned long>(this, a2: (int)this, pData: (unsigned int *)&iDontGoPast);
          CVProfile::AddBudgetGroupName(this, a2: pOut, a3: iDontGoPast);
          break;
        case 1:
          result = CVProfRecorder::Playback_ReadAddNode(this);
          if ( result == 0 )
            return result;
          break;
        case 3:
          result = CVProfRecorder::Playback_ReadTimings_R(this, a2: (int)this, pNode: (unsigned int)&this->m_Root);
          if ( result == 0 )
            return result;
          break;
        default:
          CVProfRecorder::Stop(this);
          _Warning(a1: "VPROF PLAYBACK ASSERT (%s, line %d) - stopping playback.\n", "vprof_record.cpp", 595);
          return 0;
      }
    }
    return 1;
  }
  *v3 = true;
  g_pFileSystem->Seek(this: &g_pFileSystem->IBaseFileSystem, a2: this->m_hFile, a3: -5, a4: FILESYSTEM_SEEK_CURRENT);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101F4EC0
// Name: public: void CVProfRecorder::Playback_Average(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfRecorder::Playback_Average(CVProfRecorder *this, int nFrames)
{
  unsigned int v3; // eax
  int v4; // edi
  int m_iPlaybackTick; // ecx
  CUtlVector<CVProfRecorder::CNodeAverage,CUtlMemory<CVProfRecorder::CNodeAverage,int> > averages; // [esp+Ch] [ebp-1Ch] BYREF
  int iOldPlaybackTick; // [esp+20h] [ebp-8h]
  unsigned int seekPos; // [esp+24h] [ebp-4h]

  v3 = g_pFileSystem->Tell(this: &g_pFileSystem->IBaseFileSystem, a2: this->m_hFile);
  v4 = nFrames;
  m_iPlaybackTick = this->m_iPlaybackTick;
  seekPos = v3;
  iOldPlaybackTick = m_iPlaybackTick;
  memset(&averages, 0, sizeof(averages));
  if ( nFrames > 0 )
  {
    do
    {
      if ( this->m_bPlaybackFinished )
        break;
      CVProfRecorder::Playback_ReadTick(this, iDontGoPast: -1, pWouldHaveGonePast: nullptr);
      CVProfRecorder::UpdateAverages_R(this, &averages, pNode: &this->m_Root);
      --v4;
    }
    while ( v4 > 0 );
  }
  CVProfRecorder::DumpAverages_R(this, &averages, pNode: &this->m_Root);
  g_pFileSystem->Seek(this: &g_pFileSystem->IBaseFileSystem, a2: this->m_hFile, a3: seekPos, a4: FILESYSTEM_SEEK_HEAD);
  this->m_iPlaybackTick = iOldPlaybackTick;
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&averages);
}

//------------------------------------------------------------------------------
// Address: 0x101F4F80
// Name: vprof_playback_average
// Source: json
//------------------------------------------------------------------------------
void __cdecl vprof_playback_average(const CCommand *args)
{
  const char *v1; // eax
  int v2; // eax

  if ( args->m_nArgc < 2 )
  {
    _Warning(a1: "vprof_playback_average [# frames]\n");
    _Warning(a1: "If # frames is -1, then it will average all the remaining frames in the vprof file.\n");
  }
  else
  {
    v1 = defaultValue;
    if ( args->m_nArgc > 1 )
      v1 = args->m_ppArgv[1];
    v2 = atoi(nptr: v1);
    if ( v2 == -1 )
      v2 = 9999999;
    CVProfRecorder::Playback_Average(this: &g_VProfRecorder, nFrames: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F4FE0
// Name: void VProfRecord_Snapshot(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VProfRecord_Snapshot()
{
  if ( g_VProfRecorder.m_Mode == 1 )
  {
    CVProfRecorder::Record_Snapshot(this: &g_VProfRecorder);
  }
  else if ( g_VProfRecorder.m_Mode == 2 && !g_VProfRecorder.m_bPlaybackPaused )
  {
    CVProfRecorder::Playback_ReadTick(this: &g_VProfRecorder, iDontGoPast: -1, pWouldHaveGonePast: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F5020
// Name: public: bool CVProfRecorder::Playback_Start(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVProfRecorder::Playback_Start(CVProfRecorder *this, char *pFilename)
{
  char *v3; // edi
  int v4; // eax
  void *v5; // eax
  int v7; // eax
  void *m_hFile; // edx
  char tempFilename[512]; // [esp+8h] [ebp-204h] BYREF
  int nodeID; // [esp+208h] [ebp-4h] BYREF

  CVProfRecorder::Stop(this);
  v3 = pFilename;
  strchr(string: (unsigned __int8 *)pFilename, chr: 0x2Eu);
  if ( v4 == 0 )
  {
    V_snprintf(pDest: tempFilename, maxLen: 512, pFormat: "%s.vprof", v3);
    v3 = tempFilename;
  }
  this->m_iLastUniqueNodeID = -1;
  v5 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: v3, a3: "rb", a4: 0);
  this->m_hFile = v5;
  this->m_Mode = 2;
  this->m_bPlaybackPaused = true;
  if ( v5 != nullptr )
  {
    CVProfRecorder::Read<unsigned long>(this, a2: (int)this, pData: (unsigned int *)&pFilename);
    if ( pFilename == (char *)1 )
    {
      CVProfRecorder::Read<unsigned long>(this, a2: (int)this, pData: (unsigned int *)&nodeID);
      this->m_Root.m_iUniqueNodeID = nodeID;
      v7 = g_pFileSystem->Tell(this: &g_pFileSystem->IBaseFileSystem, a2: this->m_hFile);
      m_hFile = this->m_hFile;
      this->m_iSkipPastHeaderPos = v7;
      this->m_bPlaybackFinished = false;
      this->m_FileLen = g_pFileSystem->Size_2(this: &g_pFileSystem->IBaseFileSystem, a2: m_hFile);
      this->m_enabled = 1;
      CVProfRecorder::Playback_ReadTick(this, iDontGoPast: -1, pWouldHaveGonePast: nullptr);
      g_pVProfileForDisplay = this;
      return 1;
    }
    else
    {
      CVProfRecorder::Stop(this);
      _Warning(a1: "VPROF PLAYBACK ASSERT (%s, line %d) - stopping playback.\n", "vprof_record.cpp", 343);
      return 0;
    }
  }
  else
  {
    _Warning(a1: "vprof_playback_start: Open( %s ) failed.\n", v3);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F5170
// Name: public: void CVProfRecorder::Playback_Restart(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfRecorder::Playback_Restart(CVProfRecorder *this)
{
  int m_iSkipPastHeaderPos; // edx

  if ( this->m_Mode == 2 )
  {
    this->m_iPlaybackTick = -1;
    CVProfile::Term(this);
    m_iSkipPastHeaderPos = this->m_iSkipPastHeaderPos;
    this->m_bNodesChanged = true;
    g_pFileSystem->Seek(
      this: &g_pFileSystem->IBaseFileSystem,
      a2: this->m_hFile,
      a3: m_iSkipPastHeaderPos,
      a4: FILESYSTEM_SEEK_HEAD);
    CVProfRecorder::Playback_ReadTick(this, iDontGoPast: -1, pWouldHaveGonePast: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F51D0
// Name: public: int CVProfRecorder::Playback_SetPlaybackTick(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVProfRecorder::Playback_SetPlaybackTick(CVProfRecorder *this, int iTick)
{
  int m_iPlaybackTick; // eax
  int v5; // edi
  bool i; // cc

  if ( this->m_Mode != 2 )
    return 0;
  m_iPlaybackTick = this->m_iPlaybackTick;
  v5 = iTick;
  this->m_bNodesChanged = false;
  if ( v5 == m_iPlaybackTick )
    return 1;
  if ( v5 >= m_iPlaybackTick )
  {
    if ( m_iPlaybackTick < v5 )
      goto LABEL_10;
  }
  else
  {
    CVProfRecorder::Playback_Restart(this);
    for ( i = this->m_iPlaybackTick < v5; i; i = this->m_iPlaybackTick < v5 )
    {
LABEL_10:
      HIBYTE(iTick) = 0;
      if ( !CVProfRecorder::Playback_ReadTick(this, iDontGoPast: v5, pWouldHaveGonePast: (bool *)&iTick + 3) )
        return 0;
      if ( HIBYTE(iTick) != 0 || this->m_bPlaybackFinished )
        return this->m_bNodesChanged + 1;
    }
  }
  return this->m_bNodesChanged + 1;
}

//------------------------------------------------------------------------------
// Address: 0x101F5270
// Name: public: int CVProfRecorder::Playback_SeekToPercent(float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVProfRecorder::Playback_SeekToPercent(CVProfRecorder *this, float flWantedPercent)
{
  void *m_hFile; // edx

  if ( this->m_Mode != 2 )
    return 0;
  m_hFile = this->m_hFile;
  this->m_bNodesChanged = false;
  if ( (double)g_pFileSystem->Tell(this: &g_pFileSystem->IBaseFileSystem, a2: m_hFile) / (double)this->m_FileLen <= flWantedPercent
    || (CVProfRecorder::Playback_Restart(this), flWantedPercent > 0.0) )
  {
    if ( flWantedPercent > (double)g_pFileSystem->Tell(this: &g_pFileSystem->IBaseFileSystem, a2: this->m_hFile)
                         / (double)this->m_FileLen )
    {
      while ( CVProfRecorder::Playback_ReadTick(this, iDontGoPast: -1, pWouldHaveGonePast: nullptr) )
      {
        if ( this->m_bPlaybackFinished
          || flWantedPercent <= (double)g_pFileSystem->Tell(this: &g_pFileSystem->IBaseFileSystem, a2: this->m_hFile)
                              / (double)this->m_FileLen )
        {
          return this->m_bNodesChanged + 1;
        }
      }
      return 0;
    }
  }
  return this->m_bNodesChanged + 1;
}

//------------------------------------------------------------------------------
// Address: 0x101F5380
// Name: public: void CVPROFToCSVConverter::ConvertVPROJFileToCSVFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVPROFToCSVConverter::ConvertVPROJFileToCSVFile(
        CVPROFToCSVConverter *this,
        const char *szVPROJName,
        const char *szCSVName)
{
  int v4; // ebx
  CUtlMap<char *,double,unsigned short> *v5; // eax
  UtlRBTreeNode_t<CUtlMap<char *,double,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  CUtlMap<char *,double,unsigned short> **v9; // ecx
  int v10; // eax
  CUtlMap<char *,double,unsigned short> **v11; // ebx
  int v12; // edi
  CUtlMap<char *,double,unsigned short> *v13; // ecx
  unsigned __int16 v14; // ax
  char szBuffer[20]; // [esp+14h] [ebp-C40h] BYREF
  char szHeaders[1024]; // [esp+28h] [ebp-C2Ch] BYREF
  char szData[2048]; // [esp+428h] [ebp-82Ch] BYREF
  char szFloatValue[32]; // [esp+C28h] [ebp-2Ch] BYREF
  CUtlMap<char *,double,unsigned short> *szTickNum_8; // [esp+C60h] [ebp+Ch]
  int szTickNum_8a; // [esp+C60h] [ebp+Ch]

  v4 = 0;
  this->m_fileHandle = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: szCSVName, a3: "w", a4: 0);
  CVProfRecorder::Playback_Start(this: &g_VProfRecorder, pFilename: szVPROJName);
  for ( ; !g_VProfRecorder.m_bPlaybackFinished; v4 = 0 )
  {
    v5 = (CUtlMap<char *,double,unsigned short> *)MemAlloc_Alloc(nSize: 0x1Cu);
    if ( v5 != nullptr )
    {
      v5->m_Tree.m_LessFunc.m_LessFunc = CDefOps<char *>::LessFunc;
      v5->m_Tree.m_Elements.m_pMemory = nullptr;
      v5->m_Tree.m_Elements.m_nAllocationCount = 0;
      v5->m_Tree.m_Elements.m_nGrowSize = 0;
      m_pMemory = v5->m_Tree.m_Elements.m_pMemory;
      *(_DWORD *)&v5->m_Tree.m_Root = 0xFFFF;
      *(_DWORD *)&v5->m_Tree.m_FirstFree = -1;
      v5->m_Tree.m_pElements = m_pMemory;
      szTickNum_8 = v5;
    }
    else
    {
      szTickNum_8 = nullptr;
    }
    m_Size = this->m_dataVector.m_Size;
    m_nAllocationCount = this->m_dataVector.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<INetMessage *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&this->m_dataVector,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_dataVector.m_Size;
    v9 = this->m_dataVector.m_Memory.m_pMemory;
    v10 = this->m_dataVector.m_Size - m_Size - 1;
    this->m_dataVector.m_pElements = v9;
    if ( v10 > 0 )
      _V_memmove(dest: &v9[m_Size + 1], src: &v9[m_Size], count: 4 * v10);
    v11 = &this->m_dataVector.m_Memory.m_pMemory[m_Size];
    if ( v11 != nullptr )
      *v11 = szTickNum_8;
    CVPROFToCSVConverter::WriteNodeDataToDict(this, pNode: &g_VProfRecorder.m_Root, pTickDataMap: szTickNum_8);
    CVProfRecorder::Playback_ReadTick(this: &g_VProfRecorder, iDontGoPast: -1, pWouldHaveGonePast: nullptr);
  }
  CVPROFToCSVConverter::WriteHeaders(this, szBuffer, nBufferSize: 1024);
  g_pFileSystem->FPrintf(this: g_pFileSystem, a2: this->m_fileHandle, a3: "%s", szBuffer);
  v12 = 0;
  if ( this->m_dataVector.m_Size > 0 )
  {
    do
    {
      szTickNum_8a = v12 + 1;
      V_snprintf(pDest: &szFloatValue[28], maxLen: 16, pFormat: "%d", v12 + 1);
      V_strncpy(pDest: &szHeaders[1004], pSrc: &szFloatValue[28], maxLen: 2048);
      V_strncat(pDest: &szHeaders[1004], pSrc: ",", destBufferSize: 0x800u, max_chars_to_copy: -1);
      if ( this->m_labelVector.m_Size > 0 )
      {
        do
        {
          v13 = this->m_dataVector.m_Memory.m_pMemory[v12];
          *(_DWORD *)&szFloatValue[12] = this->m_labelVector.m_Memory.m_pMemory[v4];
          v14 = CUtlRBTree<CUtlMap<char *,double,unsigned short>::Node_t,unsigned short,CUtlMap<char *,double,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char *,double,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                  this: &v13->m_Tree,
                  search: (const CUtlMap<char *,double,unsigned short>::Node_t *)&szFloatValue[12]);
          if ( v14 != 0xFFFF )
          {
            V_snprintf(
              pDest: &szData[2028],
              maxLen: 32,
              pFormat: "%f",
              (double)this->m_dataVector.m_Memory.m_pMemory[v12]->m_Tree.m_Elements.m_pMemory[v14].m_Data.elem);
            V_strncat(pDest: &szHeaders[1004], pSrc: &szData[2028], destBufferSize: 0x800u, max_chars_to_copy: -1);
          }
          if ( v4 != this->m_labelVector.m_Size - 1 )
            V_strncat(pDest: &szHeaders[1004], pSrc: ",", destBufferSize: 0x800u, max_chars_to_copy: -1);
          ++v4;
        }
        while ( v4 < this->m_labelVector.m_Size );
      }
      V_strncat(pDest: &szHeaders[1004], pSrc: "\n", destBufferSize: 0x800u, max_chars_to_copy: -1);
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: this->m_fileHandle, a3: "%s", &szHeaders[1004]);
      ++v12;
      v4 = 0;
    }
    while ( szTickNum_8a < this->m_dataVector.m_Size );
  }
  g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: this->m_fileHandle);
  this->m_labelVector.m_Size = 0;
  CUtlVector<CUtlMap<char *,double,unsigned short> *,CUtlMemory<CUtlMap<char *,double,unsigned short> *,int>>::PurgeAndDeleteElements(this: &this->m_dataVector);
}

//------------------------------------------------------------------------------
// Address: 0x101F5620
// Name: vprof_to_csv
// Source: json
//------------------------------------------------------------------------------
void __cdecl vprof_to_csv(const CCommand *args)
{
  int m_nArgc; // eax
  int v2; // esi
  const char **v3; // edi
  const char *v4; // eax
  int v5; // eax
  unsigned __int16 v6; // ax
  unsigned __int16 v7; // dx
  unsigned __int16 v8; // cx
  int v9; // esi
  UtlRBTreeNode_t<CUtlMap<char *,int,unsigned short>::Node_t,unsigned short> *v10; // eax
  int v11; // edx
  CUtlMap<char *,int,unsigned short>::Node_t *p_m_Data; // esi
  int j; // esi
  char **m_pMemory; // eax
  CUtlMap<char *,double,unsigned short> **v15; // eax
  char **v16; // eax
  UtlRBTreeNode_t<CUtlMap<char *,int,unsigned short>::Node_t,unsigned short> *v17; // eax
  char **v18; // eax
  char szArgs[520]; // [esp+4h] [ebp-480h] BYREF
  char szVPROFFilename[260]; // [esp+20Ch] [ebp-278h] BYREF
  char szCSVFilename[260]; // [esp+310h] [ebp-174h] BYREF
  CUtlMap<char *,int,unsigned short>::Node_t insert; // [esp+414h] [ebp-70h] BYREF
  CVPROFToCSVConverter converter; // [esp+41Ch] [ebp-68h] BYREF
  int i; // [esp+44Ch] [ebp-38h]
  unsigned __int16 parent[2]; // [esp+450h] [ebp-34h] BYREF
  CUtlMap<char *,int,unsigned short> tokenMap; // [esp+454h] [ebp-30h] BYREF
  CUtlVector<char *,CUtlMemory<char *,int> > argsVector; // [esp+470h] [ebp-14h] BYREF

  m_nArgc = args->m_nArgc;
  if ( args->m_nArgc >= 2 )
  {
    v2 = 1;
    szArgs[0] = 0;
    if ( m_nArgc > 1 )
    {
      v3 = &args->m_ppArgv[1];
      do
      {
        if ( v2 < 0 || v2 >= m_nArgc )
          v4 = defaultValue;
        else
          v4 = *v3;
        V_strncat(pDest: szArgs, pSrc: v4, destBufferSize: 0x208u, max_chars_to_copy: -1);
        m_nArgc = args->m_nArgc;
        ++v2;
        ++v3;
      }
      while ( v2 < args->m_nArgc );
    }
    memset(&argsVector, 0, sizeof(argsVector));
    tokenMap.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(char *const *, char *const *))CDefOps<char *>::LessFunc;
    memset(&tokenMap.m_Tree.m_Elements, 0, sizeof(tokenMap.m_Tree.m_Elements));
    *(_DWORD *)&tokenMap.m_Tree.m_Root = 0xFFFF;
    *(_DWORD *)&tokenMap.m_Tree.m_FirstFree = -1;
    tokenMap.m_Tree.m_pElements = nullptr;
    V_SplitString(pString: szArgs, pSeparator: "|", outStrings: &argsVector);
    V_strncpy(pDest: szVPROFFilename, pSrc: *(const char **)argsVector.m_Memory.m_pMemory, maxLen: 260);
    free(pMem: *(void **)argsVector.m_Memory.m_pMemory);
    if ( argsVector.m_Size - 1 > 0 )
      _V_memmove(
        dest: argsVector.m_Memory.m_pMemory,
        src: argsVector.m_Memory.m_pMemory + 1,
        count: 4 * (argsVector.m_Size - 1));
    v5 = 0;
    --argsVector.m_Size;
    i = 0;
    if ( argsVector.m_Size > 0 )
    {
      do
      {
        insert.key = argsVector.m_Memory.m_pMemory[v5];
        insert.elem = 0;
        *(_DWORD *)parent = 0xFFFF;
        HIBYTE(args) = 0;
        CUtlRBTree<CUtlMap<char *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
          this: &tokenMap.m_Tree,
          &insert,
          parent,
          leftchild: (bool *)&args + 3);
        v6 = CUtlRBTree<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short,CUtlMap<int,enum ESocketIndex_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this: (CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&tokenMap);
        v7 = parent[0];
        v8 = v6;
        v9 = v6;
        v10 = &tokenMap.m_Tree.m_Elements.m_pMemory[v9];
        v10->m_Right = -1;
        v10->m_Left = -1;
        v10->m_Parent = v7;
        v10->m_Tag = 0;
        if ( v7 == 0xFFFF )
        {
          tokenMap.m_Tree.m_Root = v8;
        }
        else
        {
          v11 = v7;
          if ( HIBYTE(args) != 0 )
            tokenMap.m_Tree.m_Elements.m_pMemory[v11].m_Left = v8;
          else
            tokenMap.m_Tree.m_Elements.m_pMemory[v11].m_Right = v8;
        }
        CUtlRBTree<CUtlMap<char *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
          this: &tokenMap.m_Tree,
          elem: v8);
        ++tokenMap.m_Tree.m_NumElements;
        p_m_Data = &tokenMap.m_Tree.m_Elements.m_pMemory[v9].m_Data;
        if ( p_m_Data != nullptr )
          *p_m_Data = insert;
        v5 = i + 1;
        i = v5;
      }
      while ( v5 < argsVector.m_Size );
    }
    V_StripExtension(in: szVPROFFilename, out: szCSVFilename, outSize: 260);
    V_strncat(pDest: szCSVFilename, pSrc: ".csv", destBufferSize: 0x104u, max_chars_to_copy: -1);
    converter.m_pTokenMap = &tokenMap;
    memset(&converter, 0, 40);
    CVPROFToCSVConverter::ConvertVPROJFileToCSVFile(
      this: &converter,
      szVPROJName: szVPROFFilename,
      szCSVName: szCSVFilename);
    for ( j = 0; j < argsVector.m_Size; ++j )
      free(pMem: argsVector.m_Memory.m_pMemory[j]);
    m_pMemory = argsVector.m_Memory.m_pMemory;
    argsVector.m_Size = 0;
    if ( argsVector.m_Memory.m_nGrowSize >= 0 )
    {
      if ( argsVector.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: argsVector.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        argsVector.m_Memory.m_pMemory = nullptr;
      }
      argsVector.m_Memory.m_nAllocationCount = 0;
    }
    argsVector.m_pElements = m_pMemory;
    CUtlRBTree<CUtlMap<char *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &tokenMap.m_Tree);
    v15 = converter.m_dataVector.m_Memory.m_pMemory;
    converter.m_dataVector.m_Size = 0;
    if ( converter.m_dataVector.m_Memory.m_nGrowSize >= 0 )
    {
      if ( converter.m_dataVector.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: converter.m_dataVector.m_Memory.m_pMemory);
        v15 = nullptr;
        converter.m_dataVector.m_Memory.m_pMemory = nullptr;
      }
      converter.m_dataVector.m_Memory.m_nAllocationCount = 0;
    }
    converter.m_dataVector.m_pElements = v15;
    if ( converter.m_dataVector.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v15 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v15);
        converter.m_dataVector.m_Memory.m_pMemory = nullptr;
      }
      converter.m_dataVector.m_Memory.m_nAllocationCount = 0;
    }
    v16 = converter.m_labelVector.m_Memory.m_pMemory;
    converter.m_labelVector.m_Size = 0;
    if ( converter.m_labelVector.m_Memory.m_nGrowSize >= 0 )
    {
      if ( converter.m_labelVector.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: converter.m_labelVector.m_Memory.m_pMemory);
        v16 = nullptr;
        converter.m_labelVector.m_Memory.m_pMemory = nullptr;
      }
      converter.m_labelVector.m_Memory.m_nAllocationCount = 0;
    }
    converter.m_labelVector.m_pElements = v16;
    if ( converter.m_labelVector.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v16 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v16);
        converter.m_labelVector.m_Memory.m_pMemory = nullptr;
      }
      converter.m_labelVector.m_Memory.m_nAllocationCount = 0;
    }
    CUtlRBTree<CUtlMap<char *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &tokenMap.m_Tree);
    v17 = tokenMap.m_Tree.m_Elements.m_pMemory;
    tokenMap.m_Tree.m_FirstFree = -1;
    if ( tokenMap.m_Tree.m_Elements.m_nGrowSize >= 0 )
    {
      if ( tokenMap.m_Tree.m_Elements.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenMap.m_Tree.m_Elements.m_pMemory);
        v17 = nullptr;
        tokenMap.m_Tree.m_Elements.m_pMemory = nullptr;
      }
      tokenMap.m_Tree.m_Elements.m_nAllocationCount = 0;
    }
    tokenMap.m_Tree.m_LastAlloc.index = -1;
    if ( tokenMap.m_Tree.m_Elements.m_nGrowSize >= 0 )
    {
      if ( v17 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v17);
        tokenMap.m_Tree.m_Elements.m_pMemory = nullptr;
      }
      tokenMap.m_Tree.m_Elements.m_nAllocationCount = 0;
    }
    v18 = argsVector.m_Memory.m_pMemory;
    argsVector.m_Size = 0;
    if ( argsVector.m_Memory.m_nGrowSize >= 0 )
    {
      if ( argsVector.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: argsVector.m_Memory.m_pMemory);
        v18 = nullptr;
        argsVector.m_Memory.m_pMemory = nullptr;
      }
      argsVector.m_Memory.m_nAllocationCount = 0;
    }
    argsVector.m_pElements = v18;
    if ( argsVector.m_Memory.m_nGrowSize >= 0 && v18 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v18);
  }
  else
  {
    _Warning(a1: "vprof_to_csv requires an input filename (.VPROJ) and optional VPROF node names\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F59E0
// Name: vprof_playback_start
// Source: json
//------------------------------------------------------------------------------
void __cdecl vprof_playback_start(const CCommand *args)
{
  int m_nArgc; // eax
  int v2; // esi
  const char **v3; // edi
  const char *v4; // eax
  char fullFilename[512]; // [esp+4h] [ebp-200h] BYREF

  m_nArgc = args->m_nArgc;
  if ( args->m_nArgc >= 2 )
  {
    v2 = 1;
    fullFilename[0] = 0;
    if ( m_nArgc > 1 )
    {
      v3 = &args->m_ppArgv[1];
      do
      {
        if ( v2 < 0 || v2 >= m_nArgc )
          v4 = defaultValue;
        else
          v4 = *v3;
        V_strncat(pDest: fullFilename, pSrc: v4, destBufferSize: 0x200u, max_chars_to_copy: -1);
        m_nArgc = args->m_nArgc;
        ++v2;
        ++v3;
      }
      while ( v2 < args->m_nArgc );
    }
    CVProfRecorder::Playback_Start(this: &g_VProfRecorder, pFilename: fullFilename);
  }
  else
  {
    _Warning(a1: "vprof_playback_start requires a filename\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F5A70
// Name: void VProfPlayback_Step(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VProfPlayback_Step()
{
  CVProfRecorder::Playback_ReadTick(this: &g_VProfRecorder, iDontGoPast: -1, pWouldHaveGonePast: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101F5A80
// Name: int VProfPlayback_SeekToPercent(float)
// Source: json
//------------------------------------------------------------------------------
int __cdecl VProfPlayback_SeekToPercent(float percent)
{
  return CVProfRecorder::Playback_SeekToPercent(this: &g_VProfRecorder, flWantedPercent: percent);
}

//------------------------------------------------------------------------------
// Address: 0x101F5AA0
// Name: int VProfPlayback_StepBack(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VProfPlayback_StepBack()
{
  CVProfRecorder::Playback_SetPlaybackTick(this: &g_VProfRecorder, iTick: g_VProfRecorder.m_iPlaybackTick - 1);
}

//------------------------------------------------------------------------------
// Address: 0x10312D70
// Name: _dynamic_initializer_for__record_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__record_command__()
{
  ConCommand::ConCommand(
    this: &record_command,
    pName: "record",
    callback: (void (__cdecl *)())record,
    pHelpString: "Record a demo.",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__record_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10312DA0
// Name: _dynamic_initializer_for___record_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for___record_command__()
{
  ConCommand::ConCommand(
    this: &record_command,
    pName: "_record",
    callback: (void (__cdecl *)())record,
    pHelpString: "Record a demo incrementally.",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for___record_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10322420
// Name: _dynamic_atexit_destructor_for__record_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__record_command__()
{
  ConCommand::~ConCommand(this: &record_command);
}

//------------------------------------------------------------------------------
// Address: 0x10322430
// Name: _dynamic_atexit_destructor_for___record_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for___record_command__()
{
  ConCommand::~ConCommand(this: &record_command);
}

//------------------------------------------------------------------------------
// Address: 0x10312DD0
// Name: _dynamic_initializer_for__vtune_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__vtune_command__()
{
  ConCommand::ConCommand(
    this: &vtune_command,
    pName: "vtune",
    callback: (void (__cdecl *)())vtune_0,
    pHelpString: "Controls VTune's sampling.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vtune_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10312E00
// Name: _dynamic_initializer_for__playdemo_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__playdemo_command__()
{
  ConCommand::ConCommand(
    this: &playdemo_command,
    pName: "playdemo",
    callback: (void (__cdecl *)())CL_PlayDemo_f,
    pHelpString: "Play a recorded demo file (.dem ).",
    flags: 0,
    completionFunc: (int (__cdecl *)(const char *, char (*)[64]))g_playdemo_CompletionFunc);
  return atexit(func: dynamic_atexit_destructor_for__playdemo_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10312E30
// Name: _dynamic_initializer_for__timedemo_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__timedemo_command__()
{
  ConCommand::ConCommand(
    this: &timedemo_command,
    pName: "timedemo",
    callback: (void (__cdecl *)())CL_TimeDemo_f,
    pHelpString: "Play a demo and report performance info.",
    flags: 0,
    completionFunc: (int (__cdecl *)(const char *, char (*)[64]))g_timedemo_CompletionFunc);
  return atexit(func: dynamic_atexit_destructor_for__timedemo_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10312E60
// Name: _dynamic_initializer_for__timedemoquit_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__timedemoquit_command__()
{
  ConCommand::ConCommand(
    this: &timedemoquit_command,
    pName: "timedemoquit",
    callback: (void (__cdecl *)())CL_TimeDemoQuit_f,
    pHelpString: "Play a demo, report performance info, and then exit",
    flags: 0,
    completionFunc: (int (__cdecl *)(const char *, char (*)[64]))g_timedemoquit_CompletionFunc);
  return atexit(func: dynamic_atexit_destructor_for__timedemoquit_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10312E90
// Name: _dynamic_initializer_for__listdemo_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__listdemo_command__()
{
  ConCommand::ConCommand(
    this: &listdemo_command,
    pName: "listdemo",
    callback: (void (__cdecl *)())CL_ListDemo_f,
    pHelpString: "List demo file contents.",
    flags: 0,
    completionFunc: (int (__cdecl *)(const char *, char (*)[64]))g_listdemo_CompletionFunc);
  return atexit(func: dynamic_atexit_destructor_for__listdemo_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10312EC0
// Name: _dynamic_initializer_for__benchframe_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__benchframe_command__()
{
  ConCommand::ConCommand(
    this: &benchframe_command,
    pName: "benchframe",
    callback: (void (__cdecl *)())CL_BenchFrame_f,
    pHelpString: "Takes a snapshot of a particular frame in a time demo.",
    flags: 0,
    completionFunc: (int (__cdecl *)(const char *, char (*)[64]))g_benchframe_CompletionFunc);
  return atexit(func: dynamic_atexit_destructor_for__benchframe_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10312EF0
// Name: _dynamic_initializer_for__timedemo_vprofrecord_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__timedemo_vprofrecord_command__()
{
  ConCommand::ConCommand(
    this: &timedemo_vprofrecord_command,
    pName: "timedemo_vprofrecord",
    callback: (void (__cdecl *)())CL_TimeDemo_VProfRecord_f,
    pHelpString: "Play a demo and report performance info.  Also record vprof data for the span of the demo",
    flags: 0,
    completionFunc: (int (__cdecl *)(const char *, char (*)[64]))g_timedemo_vprofrecord_CompletionFunc);
  return atexit(func: dynamic_atexit_destructor_for__timedemo_vprofrecord_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10322440
// Name: _dynamic_atexit_destructor_for__vtune_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vtune_command__()
{
  ConCommand::~ConCommand(this: &vtune_command);
}

//------------------------------------------------------------------------------
// Address: 0x10322450
// Name: _dynamic_atexit_destructor_for__playdemo_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__playdemo_command__()
{
  ConCommand::~ConCommand(this: &playdemo_command);
}

//------------------------------------------------------------------------------
// Address: 0x10322460
// Name: _dynamic_atexit_destructor_for__timedemo_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__timedemo_command__()
{
  ConCommand::~ConCommand(this: &timedemo_command);
}

//------------------------------------------------------------------------------
// Address: 0x10322470
// Name: _dynamic_atexit_destructor_for__timedemoquit_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__timedemoquit_command__()
{
  ConCommand::~ConCommand(this: &timedemoquit_command);
}

//------------------------------------------------------------------------------
// Address: 0x10322480
// Name: _dynamic_atexit_destructor_for__listdemo_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__listdemo_command__()
{
  ConCommand::~ConCommand(this: &listdemo_command);
}

//------------------------------------------------------------------------------
// Address: 0x10322490
// Name: _dynamic_atexit_destructor_for__benchframe_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__benchframe_command__()
{
  ConCommand::~ConCommand(this: &benchframe_command);
}

//------------------------------------------------------------------------------
// Address: 0x103224A0
// Name: _dynamic_atexit_destructor_for__timedemo_vprofrecord_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__timedemo_vprofrecord_command__()
{
  ConCommand::~ConCommand(this: &timedemo_vprofrecord_command);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10093020
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned short,struct MatViewOverride::ViewParamsLast::VarMap,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
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
    v7 = 44 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016E130
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<unsigned short,struct PropIndicesCollection_t,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx

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
        m_nAllocationCount = 3;
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
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: 14 * m_nAllocationCount);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<unsigned short,PropIndicesCollection_t,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 14 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AF320
// Name: public: static bool CDefOps<struct netadr_s>::LessFunc(struct netadr_s const __near &,struct netadr_s const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CDefOps<netadr_s>::LessFunc(netadr_s *lhs, const netadr_s *rhs)
{
  return netadr_s::operator<(this: lhs, netadr: rhs);
}

//------------------------------------------------------------------------------
// Address: 0x101B6280
// Name: public: CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(
        CUtlBuffer *this)
{
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CEE20
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class CUtlSymbol,struct CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
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
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<CUtlSymbol,CSaveDirectory::file_t,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F2420
// Name: public: bool CVProfRecorder::Playback_ReadString(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVProfRecorder::Playback_ReadString(CVProfRecorder *this, char *pOut, int maxLen)
{
  int v4; // esi
  char v6; // [esp+Fh] [ebp-1h] BYREF

  v4 = 0;
  if ( g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: &v6, a3: 1, a4: this->m_hFile) != 0 )
  {
    while ( v6 != 0 )
    {
      if ( v4 < maxLen - 1 )
        pOut[v4++] = v6;
      if ( g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: &v6, a3: 1, a4: this->m_hFile) == 0 )
        goto LABEL_6;
    }
    pOut[v4] = 0;
    return 1;
  }
  else
  {
LABEL_6:
    CVProfRecorder::Stop(this);
    _Warning(a1: "VPROF PLAYBACK ASSERT (%s, line %d) - stopping playback.\n", "..\\engine\\vprof_record.cpp", 402);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F24C0
// Name: public: class CVProfNode __near * CVProfRecorder::FindVProfNodeByID_R(class CVProfNode __near *,int)
// Source: json
//------------------------------------------------------------------------------
CVProfNode *__thiscall CVProfRecorder::FindVProfNodeByID_R(CVProfRecorder *this, CVProfNode *pNode, int id)
{
  CVProfNode *result; // eax
  CVProfNode *m_pChild; // esi

  result = pNode;
  if ( pNode->m_iUniqueNodeID != id )
  {
    m_pChild = pNode->m_pChild;
    if ( m_pChild != nullptr )
    {
      while ( 1 )
      {
        result = CVProfRecorder::FindVProfNodeByID_R(this, pNode: m_pChild, id);
        if ( result != nullptr )
          break;
        m_pChild = m_pChild->m_pSibling;
        if ( m_pChild == nullptr )
          return nullptr;
      }
    }
    else
    {
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F2500
// Name: public: void CVProfRecorder::StartOrStop(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfRecorder::StartOrStop(CVProfRecorder *this)
{
  while ( this->m_nQueuedStarts > 0 )
  {
    --this->m_nQueuedStarts;
    if ( ++*(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4108) == 1 )
      CVProfNode::EnterScope(this: (CVProfNode *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4120));
  }
  while ( this->m_nQueuedStops > 0 )
  {
    --this->m_nQueuedStops;
    if ( (*(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4108))-- == 1 )
      CVProfNode::ExitScope(this: (CVProfNode *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4120));
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F2590
// Name: void VProfRecord_Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VProfRecord_Shutdown()
{
  CVProfRecorder::Stop(this: &g_VProfRecorder);
}

//------------------------------------------------------------------------------
// Address: 0x101F25A0
// Name: vprof_record_stop
// Source: json
//------------------------------------------------------------------------------
void __cdecl vprof_record_stop()
{
  _Warning(a1: "Stopping vprof recording...\n");
  CVProfRecorder::Stop(this: &g_VProfRecorder);
}

//------------------------------------------------------------------------------
// Address: 0x101F25E0
// Name: void VProfRecord_StartOrStop(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VProfRecord_StartOrStop()
{
  CVProfRecorder::StartOrStop(this: &g_VProfRecorder);
}

//------------------------------------------------------------------------------
// Address: 0x101F25F0
// Name: bool VProfRecord_IsPlayingBack(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl VProfRecord_IsPlayingBack()
{
  return g_VProfRecorder.m_Mode == 2;
}

//------------------------------------------------------------------------------
// Address: 0x101F2600
// Name: int VProfPlayback_GetCurrentTick(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl VProfPlayback_GetCurrentTick()
{
  return g_VProfRecorder.m_iPlaybackTick;
}

//------------------------------------------------------------------------------
// Address: 0x101F2610
// Name: float VProfPlayback_GetCurrentPercent(void)
// Source: json
//------------------------------------------------------------------------------
double __cdecl VProfPlayback_GetCurrentPercent()
{
  return (double)g_pFileSystem->Tell(this: &g_pFileSystem->IBaseFileSystem, a2: g_VProfRecorder.m_hFile)
       / (double)g_VProfRecorder.m_FileLen;
}

//------------------------------------------------------------------------------
// Address: 0x101F2650
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char __near *,double,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char *,double,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short> *m_pMemory; // edx
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
    v7 = 24 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlCachedFileData<CAudioSourceCachedInfo>::ElementType_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F27D0
// Name: public: void CVProfRecorder::DumpAverages_R(class CUtlVector<class CVProfRecorder::CNodeAverage,class CUtlMemory<class CVProfRecorder::CNodeAverage,int>> __near &,class CVProfNode __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfRecorder::DumpAverages_R(
        CVProfRecorder *this,
        CUtlVector<CVProfRecorder::CNodeAverage,CUtlMemory<CVProfRecorder::CNodeAverage,int> > *averages,
        CVProfNode *pNode)
{
  int m_Size; // ecx
  int v4; // eax
  CVProfRecorder::CNodeAverage *m_pMemory; // edx
  CVProfRecorder::CNodeAverage *v6; // edi
  int m_Int64_high; // ecx
  unsigned int m_nCurFrameCalls; // edx
  CVProfNode *i; // esi

  m_Size = averages->m_Size;
  v4 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = averages->m_Memory.m_pMemory;
    while ( m_pMemory->m_pNode != pNode )
    {
      ++v4;
      ++m_pMemory;
      if ( v4 >= m_Size )
        goto LABEL_8;
    }
    v6 = &averages->m_Memory.m_pMemory[v4];
    if ( v6 != nullptr )
    {
      pNode->m_CurFrameTime.m_Int64 = v6->m_CurFrameTime_Total.m_Int64 / v6->m_nSamples;
      pNode->m_nCurFrameCalls = v6->m_nCurFrameCalls_Total / v6->m_nSamples;
    }
  }
LABEL_8:
  m_Int64_high = HIDWORD(pNode->m_CurFrameTime.m_Int64);
  m_nCurFrameCalls = pNode->m_nCurFrameCalls;
  LODWORD(pNode->m_PrevFrameTime.m_Int64) = pNode->m_CurFrameTime.m_Int64;
  HIDWORD(pNode->m_PrevFrameTime.m_Int64) = m_Int64_high;
  pNode->m_nPrevFrameCalls = m_nCurFrameCalls;
  for ( i = pNode->m_pChild; i != nullptr; i = i->m_pSibling )
    CVProfRecorder::DumpAverages_R(this, averages, pNode: i);
}

//------------------------------------------------------------------------------
// Address: 0x101F2870
// Name: protected: void CVPROFToCSVConverter::WriteHeaders(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVPROFToCSVConverter::WriteHeaders(CVPROFToCSVConverter *this, char *szBuffer, int nBufferSize)
{
  int i; // esi

  V_strncpy(pDest: szBuffer, pSrc: "Tick Number,", maxLen: nBufferSize);
  for ( i = 0; i < this->m_labelVector.m_Size; ++i )
  {
    V_strncat(
      pDest: szBuffer,
      pSrc: this->m_labelVector.m_Memory.m_pMemory[i],
      destBufferSize: nBufferSize,
      max_chars_to_copy: -1);
    if ( i != this->m_labelVector.m_Size - 1 )
      V_strncat(pDest: szBuffer, pSrc: ",", destBufferSize: nBufferSize, max_chars_to_copy: -1);
  }
  V_strncat(pDest: szBuffer, pSrc: "\n", destBufferSize: nBufferSize, max_chars_to_copy: -1);
}

//------------------------------------------------------------------------------
// Address: 0x101F28F0
// Name: public: void CVProfRecorder::Write<unsigned long>(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfRecorder::Write<unsigned long>(CVProfRecorder *this, unsigned int *pData)
{
  unsigned int *p_swapped; // eax
  char v4; // dl
  char v5; // cl
  char v6; // dl
  char v7; // al
  unsigned int swapped; // [esp+4h] [ebp-4h] BYREF

  if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
  {
    p_swapped = pData;
    if ( pData == nullptr )
      p_swapped = &swapped;
    v4 = *((_BYTE *)p_swapped + 3);
    pData = (unsigned int *)swapped;
    v5 = *((_BYTE *)p_swapped + 2);
    LOBYTE(pData) = v4;
    v6 = *((_BYTE *)p_swapped + 1);
    v7 = *(_BYTE *)p_swapped;
    BYTE1(pData) = v5;
    BYTE2(pData) = v6;
    HIBYTE(pData) = v7;
    _V_memcpy(dest: &swapped, src: &pData, count: 4);
    g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: &swapped, a3: 4, a4: this->m_hFile);
  }
  else
  {
    g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: pData, a3: 4, a4: this->m_hFile);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F2990
// Name: public: void CVProfRecorder::Write<unsigned char>(unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfRecorder::Write<unsigned char>(CVProfRecorder *this, unsigned __int8 *pData)
{
  unsigned __int8 *v3; // eax
  unsigned __int8 src; // [esp+7h] [ebp-1h] BYREF

  if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
  {
    v3 = pData;
    if ( pData == nullptr )
      v3 = (unsigned __int8 *)&pData + 3;
    src = *v3;
    _V_memcpy(dest: (char *)&pData + 3, &src, count: 1);
    g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: (char *)&pData + 3, a3: 1, a4: this->m_hFile);
  }
  else
  {
    g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: pData, a3: 1, a4: this->m_hFile);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F2A10
// Name: public: void CVProfRecorder::Write<unsigned short>(unsigned short __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfRecorder::Write<unsigned short>(CVProfRecorder *this, unsigned __int16 **pData)
{
  unsigned __int16 **p_pData; // eax
  char v4; // dl
  char v5; // al
  _WORD src[2]; // [esp+4h] [ebp-4h] BYREF

  if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
  {
    p_pData = pData;
    if ( pData == nullptr )
      p_pData = (unsigned __int16 **)&pData;
    v4 = *((_BYTE *)p_pData + 1);
    v5 = *(_BYTE *)p_pData;
    src[1] = 0;
    LOBYTE(src[0]) = v4;
    HIBYTE(src[0]) = v5;
    _V_memcpy(dest: &pData, src, count: 2);
    g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: &pData, a3: 2, a4: this->m_hFile);
  }
  else
  {
    g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: pData, a3: 2, a4: this->m_hFile);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F2AA0
// Name: public: int CVProfRecorder::Read<unsigned long>(unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CVProfRecorder::Read<unsigned long>@<eax>(
        CVProfRecorder *this@<ecx>,
        int a2@<esi>,
        unsigned int *pData)
{
  bool v3; // zf
  int (__thiscall *Read)(IBaseFileSystem *, void *, int, void *); // edx
  void *m_hFile; // ecx
  int v6; // esi
  unsigned int *v7; // eax
  unsigned int tmp; // [esp+0h] [ebp-4h] BYREF

  tmp = (unsigned int)this;
  v3 = (*(_BYTE *)&this->m_Byteswap & 1) == 0;
  Read = g_pFileSystem->Read;
  m_hFile = this->m_hFile;
  if ( v3 )
    return ((int (__thiscall *)(IBaseFileSystem *, unsigned int *, int, void *, unsigned int))Read)(
             a1: &g_pFileSystem->IBaseFileSystem,
             a2: pData,
             a3: 4,
             a4: m_hFile,
             a5: tmp);
  v6 = ((int (__thiscall *)(IBaseFileSystem *, unsigned int *, int, void *, int))Read)(
         a1: &g_pFileSystem->IBaseFileSystem,
         a2: &tmp,
         a3: 4,
         a4: m_hFile,
         a5: a2);
  v7 = pData;
  if ( pData != nullptr )
  {
    LOBYTE(pData) = HIBYTE(tmp);
    BYTE1(pData) = BYTE2(tmp);
    BYTE2(pData) = BYTE1(tmp);
    HIBYTE(pData) = tmp;
    _V_memcpy(dest: v7, src: &pData, count: 4);
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x101F2B20
// Name: public: int CVProfRecorder::Read<unsigned char>(unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
int __userpurge CVProfRecorder::Read<unsigned char>@<eax>(
        CVProfRecorder *this@<ecx>,
        int a2@<esi>,
        unsigned __int8 *pData)
{
  bool v3; // zf
  int (__thiscall *Read)(IBaseFileSystem *, void *, int, void *); // edx
  void *m_hFile; // ecx
  int v6; // esi
  unsigned __int8 *v8; // [esp-Eh] [ebp-10h]
  CVProfRecorder *v9; // [esp-2h] [ebp-4h] OVERLAPPED BYREF

  v9 = this;
  v3 = (*(_BYTE *)&this->m_Byteswap & 1) == 0;
  Read = g_pFileSystem->Read;
  m_hFile = this->m_hFile;
  if ( v3 )
    return ((int (__thiscall *)(IBaseFileSystem *, unsigned __int8 *, int, void *, CVProfRecorder *))Read)(
             a1: &g_pFileSystem->IBaseFileSystem,
             a2: pData,
             a3: 1,
             a4: m_hFile,
             a5: v9);
  v6 = ((int (__thiscall *)(IBaseFileSystem *, char *, int, void *, int))Read)(
         a1: &g_pFileSystem->IBaseFileSystem,
         a2: (char *)&v9 + 3,
         a3: 1,
         a4: m_hFile,
         a5: a2);
  if ( pData != nullptr )
  {
    v8 = pData;
    HIBYTE(pData) = HIBYTE(v9);
    _V_memcpy(dest: v8, src: (char *)&pData + 3, count: 1);
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x101F2B90
// Name: public: int CVProfRecorder::Read<unsigned short>(unsigned short __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
int __userpurge CVProfRecorder::Read<unsigned short>@<eax>(
        CVProfRecorder *this@<ecx>,
        int a2@<esi>,
        unsigned __int16 *pData)
{
  bool v3; // zf
  int (__thiscall *Read)(IBaseFileSystem *, void *, int, void *); // edx
  void *m_hFile; // ecx
  int v6; // esi
  unsigned __int16 *v7; // eax
  CVProfRecorder *tmp; // [esp+0h] [ebp-4h] OVERLAPPED BYREF

  tmp = this;
  v3 = (*(_BYTE *)&this->m_Byteswap & 1) == 0;
  Read = g_pFileSystem->Read;
  m_hFile = this->m_hFile;
  if ( v3 )
    return ((int (__thiscall *)(IBaseFileSystem *, unsigned __int16 *, int, void *, CVProfRecorder *))Read)(
             a1: &g_pFileSystem->IBaseFileSystem,
             a2: pData,
             a3: 2,
             a4: m_hFile,
             a5: tmp);
  v6 = ((int (__thiscall *)(IBaseFileSystem *, CVProfRecorder **, int, void *, int))Read)(
         a1: &g_pFileSystem->IBaseFileSystem,
         a2: &tmp,
         a3: 2,
         a4: m_hFile,
         a5: a2);
  v7 = pData;
  if ( pData != nullptr )
  {
    HIWORD(pData) = 0;
    LOBYTE(pData) = BYTE1(tmp);
    BYTE1(pData) = (_BYTE)tmp;
    _V_memcpy(dest: v7, src: &pData, count: 2);
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x101F3450
// Name: public: bool CVProfRecorder::Record_Start(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVProfRecorder::Record_Start(CVProfRecorder *this, int pFilename)
{
  char *v3; // edi
  int v4; // eax
  void *v5; // eax
  vgui::CTreeViewListControl *v7; // ecx
  ECommandTarget_t TraceType; // eax
  char tempFilename[512]; // [esp+8h] [ebp-204h] BYREF
  int nodeID; // [esp+208h] [ebp-4h] BYREF

  CVProfRecorder::Stop(this);
  v3 = (char *)pFilename;
  strchr(string: (char *)pFilename, chr: 0x2Eu);
  if ( v4 == 0 )
  {
    V_snprintf(pDest: tempFilename, maxLen: 512, pFormat: "%s.vprof", v3);
    v3 = tempFilename;
  }
  this->m_iLastUniqueNodeID = -1;
  v5 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: v3, a3: "wb", a4: 0);
  this->m_hFile = v5;
  this->m_Mode = 1;
  if ( v5 == nullptr )
    return 0;
  pFilename = 1;
  CVProfRecorder::Write<unsigned long>(this, pData: (unsigned int *)&pFilename);
  nodeID = *(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4260);
  CVProfRecorder::Write<unsigned long>(this, pData: (unsigned int *)&nodeID);
  ++this->m_nQueuedStarts;
  TraceType = CTraceFilter::GetTraceType(this: v7);
  Cbuf_AddText(eTarget: TraceType, pText: "vprof_on\n", nTickDelay: 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101F3530
// Name: public: void CVProfRecorder::Record_MatchTree_R(class CVProfNode __near *,class CVProfNode const __near *,class CVProfile __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfRecorder::Record_MatchTree_R(
        CVProfRecorder *this,
        CVProfNode *pOut,
        const CVProfNode *pIn,
        CVProfile *pInProfile)
{
  const CVProfNode *v4; // edx
  CVProfNode *v5; // ebx
  CVProfNode *m_pChild; // ecx
  CVProfNode *v8; // eax
  CVProfNode *i; // esi
  bool v10; // zf
  int m_iUniqueNodeID; // edx
  struct CVProfNode *SubNode; // eax
  CVProfNode *v13; // esi
  const CVProfNode *j; // ebx
  int nodeID; // [esp+Ch] [ebp-14h] BYREF
  int budgetGroupID; // [esp+10h] [ebp-10h] BYREF
  int parentNodeID; // [esp+14h] [ebp-Ch] BYREF
  char v18[6]; // [esp+18h] [ebp-8h] BYREF
  char dest; // [esp+1Eh] [ebp-2h] BYREF
  char src; // [esp+1Fh] [ebp-1h] BYREF

  v4 = pIn;
  v5 = pOut;
  if ( pIn->m_pChild != nullptr )
  {
    while ( 1 )
    {
      m_pChild = v5->m_pChild;
      if ( m_pChild != nullptr && v4->m_pChild->m_iUniqueNodeID == m_pChild->m_iUniqueNodeID )
        break;
      v8 = v4->m_pChild;
      for ( i = nullptr; v8 != nullptr; v8 = v8->m_pSibling )
      {
        if ( m_pChild != nullptr && v8->m_iUniqueNodeID == m_pChild->m_iUniqueNodeID )
          break;
        i = v8;
      }
      v10 = (*(_BYTE *)&this->m_Byteswap & 1) == 0;
      m_iUniqueNodeID = v4->m_iUniqueNodeID;
      budgetGroupID = i->m_BudgetGroupID;
      parentNodeID = m_iUniqueNodeID;
      nodeID = i->m_iUniqueNodeID;
      v18[0] = 1;
      if ( v10 )
      {
        g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: v18, a3: 1, a4: this->m_hFile);
      }
      else
      {
        src = 1;
        _V_memcpy(&dest, &src, count: 1);
        g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: &dest, a3: 1, a4: this->m_hFile);
      }
      CVProfRecorder::Write<unsigned long>(this, pData: (unsigned int *)&parentNodeID);
      g_pFileSystem->Write(
        this: &g_pFileSystem->IBaseFileSystem,
        a2: i->m_pszName,
        a3: &i->m_pszName[strlen(i->m_pszName) + 1] - i->m_pszName,
        a4: this->m_hFile);
      CVProfRecorder::Write<unsigned long>(this, pData: (unsigned int *)&budgetGroupID);
      CVProfRecorder::Write<unsigned long>(this, pData: (unsigned int *)&nodeID);
      v5 = pOut;
      SubNode = CVProfNode::GetSubNode(
                  this: pOut,
                  a2: i->m_pszName,
                  a3: 0,
                  a4: *(const char **)(*(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4276)
                                 + 8 * i->m_BudgetGroupID),
                  a5: *(_DWORD *)(*(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4276)
                            + 8 * i->m_BudgetGroupID
                            + 4));
      SubNode->m_BudgetGroupID = i->m_BudgetGroupID;
      SubNode->m_iUniqueNodeID = i->m_iUniqueNodeID;
      v4 = pIn;
    }
  }
  v13 = v5->m_pChild;
  for ( j = v4->m_pChild; v13 != nullptr; j = j->m_pSibling )
  {
    if ( j == nullptr )
      break;
    CVProfRecorder::Record_MatchTree_R(this, pOut: v13, pIn: j, pInProfile);
    v13 = v13->m_pSibling;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F36E0
// Name: public: void CVProfRecorder::Record_MatchBudgetGroups(class CVProfile __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfRecorder::Record_MatchBudgetGroups(CVProfRecorder *this, CVProfile *pInProfile)
{
  int i; // ebx
  bool v4; // zf
  CVProfile::CBudgetGroup *m_pBudgetGroups; // ecx
  char *m_pName; // edi
  int flags; // [esp+10h] [ebp-Ch] BYREF
  char v8[6]; // [esp+14h] [ebp-8h] BYREF
  char dest; // [esp+1Ah] [ebp-2h] BYREF
  char src; // [esp+1Bh] [ebp-1h] BYREF

  for ( i = CVProfile::GetNumBudgetGroups(this); i < CVProfile::GetNumBudgetGroups(this: pInProfile); ++i )
  {
    v4 = (*(_BYTE *)&this->m_Byteswap & 1) == 0;
    m_pBudgetGroups = pInProfile->m_pBudgetGroups;
    m_pName = m_pBudgetGroups[i].m_pName;
    flags = m_pBudgetGroups[i].m_BudgetFlags;
    v8[0] = 2;
    if ( v4 )
    {
      g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: v8, a3: 1, a4: this->m_hFile);
    }
    else
    {
      src = 2;
      _V_memcpy(&dest, &src, count: 1);
      g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: &dest, a3: 1, a4: this->m_hFile);
    }
    g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: m_pName, a3: strlen(m_pName) + 1, a4: this->m_hFile);
    CVProfRecorder::Write<unsigned long>(this, pData: (unsigned int *)&flags);
    CVProfile::AddBudgetGroupName(this, a2: m_pName, a3: flags);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F38D0
// Name: public: void CVProfRecorder::Record_Snapshot(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfRecorder::Record_Snapshot(CVProfRecorder *this)
{
  bool v2; // zf
  unsigned __int8 pData[4]; // [esp+Ch] [ebp-4h] BYREF

  CVProfile::Pause(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  pData[0] = 0;
  CVProfRecorder::Write<unsigned char>(this, pData);
  CVProfRecorder::Write<unsigned long>(this, pData: (unsigned int *)&g_ClientGlobalVariables.tickcount);
  CVProfRecorder::Record_MatchBudgetGroups(
    this,
    pInProfile: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  if ( this->m_iLastUniqueNodeID != CVProfNode::s_iCurrentUniqueNodeID )
    CVProfRecorder::Record_MatchTree_R(
      this,
      pOut: &this->m_Root,
      pIn: (const CVProfNode *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4120),
      pInProfile: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  pData[0] = 3;
  CVProfRecorder::Write<unsigned char>(this, pData);
  CVProfRecorder::Record_WriteTimings_R(
    this,
    pIn: (const CVProfNode *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4120));
  pData[0] = 4;
  CVProfRecorder::Write<unsigned char>(this, pData);
  v2 = *(_BYTE *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4112) == 0;
  *(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4108) = *(_DWORD *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled
                                                                                          + 4272);
  if ( v2 )
    CVProfNode::Resume(this: (CVProfNode *)(*(_DWORD *)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled + 4120));
}

//------------------------------------------------------------------------------
// Address: 0x101F3980
// Name: public: bool CVProfRecorder::Playback_ReadTimings_R(class CVProfNode __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CVProfRecorder::Playback_ReadTimings_R@<al>(
        CVProfRecorder *this@<ecx>,
        int a2@<esi>,
        unsigned int pNode)
{
  CVProfNode *v5; // edi
  CCycleCount *p_m_CurFrameTime; // esi
  int m_Int64_high; // edx
  CVProfNode *m_pChild; // edi
  __int64 v9; // [esp-10h] [ebp-20h]
  unsigned __int16 microsecondsToken; // [esp+4h] [ebp-Ch] BYREF
  unsigned __int16 curCalls[3]; // [esp+8h] [ebp-8h] BYREF
  unsigned __int8 token; // [esp+Fh] [ebp-1h] BYREF

  if ( CVProfRecorder::Read<unsigned char>(this, a2, pData: &token) != 1 )
    return 0;
  if ( token == 0xFF )
  {
    if ( CVProfRecorder::Read<unsigned short>(this, a2, pData: curCalls) != 2 )
      return 0;
    v5 = (CVProfNode *)pNode;
    *(_DWORD *)(pNode + 68) = curCalls[0];
  }
  else
  {
    v5 = (CVProfNode *)pNode;
    *(_DWORD *)(pNode + 68) = token;
  }
  v5->m_nPrevFrameCalls = v5->m_nCurFrameCalls;
  if ( CVProfRecorder::Read<unsigned short>(this, a2, pData: &microsecondsToken) != 2 )
    return 0;
  if ( microsecondsToken == 0xFFFF )
  {
    if ( CVProfRecorder::Read<unsigned long>(this, a2, pData: &pNode) != 4 )
      return 0;
    p_m_CurFrameTime = &v5->m_CurFrameTime;
    CCycleCount::SetMicroseconds(this: &v5->m_CurFrameTime, nMicroseconds: 4 * pNode);
  }
  else
  {
    HIDWORD(v9) = HIDWORD(_g_ClockSpeed);
    LODWORD(v9) = _g_ClockSpeed;
    p_m_CurFrameTime = &v5->m_CurFrameTime;
    v5->m_CurFrameTime.m_Int64 = (unsigned __int64)(4 * (unsigned int)microsecondsToken) * v9 / 0xF4240;
  }
  m_Int64_high = HIDWORD(p_m_CurFrameTime->m_Int64);
  LODWORD(v5->m_PrevFrameTime.m_Int64) = p_m_CurFrameTime->m_Int64;
  HIDWORD(v5->m_PrevFrameTime.m_Int64) = m_Int64_high;
  m_pChild = v5->m_pChild;
  if ( m_pChild == nullptr )
    return 1;
  while ( CVProfRecorder::Playback_ReadTimings_R(this, pNode: m_pChild) )
  {
    m_pChild = m_pChild->m_pSibling;
    if ( m_pChild == nullptr )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101F3AA0
// Name: void VProf_StartRecording(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VProf_StartRecording(const char *pFilename)
{
  CVProfRecorder::Record_Start(this: &g_VProfRecorder, (int)pFilename);
}

//------------------------------------------------------------------------------
// Address: 0x101F3AC0
// Name: vprof_record_start
// Source: json
//------------------------------------------------------------------------------
void __cdecl vprof_record_start(const CCommand *args)
{
  if ( args->m_nArgc == 2 )
    CVProfRecorder::Record_Start(this: &g_VProfRecorder, pFilename: (int)args->m_ppArgv[1]);
  else
    _Warning(a1: "vprof_record_start requires a filename\n");
}

//------------------------------------------------------------------------------
// Address: 0x101F4B00
// Name: public: void CVProfRecorder::UpdateAverages_R(class CUtlVector<class CVProfRecorder::CNodeAverage,class CUtlMemory<class CVProfRecorder::CNodeAverage,int>> __near &,class CVProfNode __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfRecorder::UpdateAverages_R(
        CVProfRecorder *this,
        CUtlVector<CVProfRecorder::CNodeAverage,CUtlMemory<CVProfRecorder::CNodeAverage,int> > *averages,
        CVProfNode *pNode)
{
  int m_Size; // ecx
  int v4; // eax
  CVProfRecorder::CNodeAverage *m_pMemory; // edx
  CVProfRecorder::CNodeAverage *v6; // eax
  int m_Int64; // ecx
  bool v8; // cf
  CVProfNode *i; // esi

  m_Size = averages->m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = averages->m_Memory.m_pMemory;
  while ( m_pMemory->m_pNode != pNode )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= m_Size )
      goto LABEL_7;
  }
  v6 = &averages->m_Memory.m_pMemory[v4];
  if ( v6 == nullptr )
  {
LABEL_7:
    v6 = &averages->m_Memory.m_pMemory[CUtlVector<CVProfRecorder::CNodeAverage,CUtlMemory<CVProfRecorder::CNodeAverage,int>>::InsertBefore(
                                         this: averages,
                                         elem: averages->m_Size)];
    *((_DWORD *)&v6->m_pNode + 1) = 0;
    LODWORD(v6->m_CurFrameTime_Total.m_Int64) = 0;
    HIDWORD(v6->m_CurFrameTime_Total.m_Int64) = 0;
    v6->m_nCurFrameCalls_Total = 0;
    v6->m_nSamples = 0;
    v6->m_pNode = pNode;
  }
  m_Int64 = pNode->m_CurFrameTime.m_Int64;
  v8 = __CFADD__(m_Int64, v6->m_CurFrameTime_Total.m_Int64);
  LODWORD(v6->m_CurFrameTime_Total.m_Int64) += m_Int64;
  HIDWORD(v6->m_CurFrameTime_Total.m_Int64) += HIDWORD(pNode->m_CurFrameTime.m_Int64) + v8;
  v6->m_nCurFrameCalls_Total += pNode->m_nCurFrameCalls;
  ++v6->m_nSamples;
  for ( i = pNode->m_pChild; i != nullptr; i = i->m_pSibling )
    CVProfRecorder::UpdateAverages_R(this, averages, pNode: i);
}

//------------------------------------------------------------------------------
// Address: 0x101F4CE0
// Name: public: CVProfRecorder::CVProfRecorder(void)
// Source: json
//------------------------------------------------------------------------------
CVProfRecorder *__thiscall CVProfRecorder::CVProfRecorder(CVProfRecorder *this)
{
  CVProfile::CVProfile(this);
  this->m_PooledStrings.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_PooledStrings.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_PooledStrings.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_PooledStrings.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_PooledStrings.m_Elements.m_Tree.m_Root = -1;
  this->m_PooledStrings.m_Elements.m_Tree.m_NumElements = 0;
  this->m_PooledStrings.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_PooledStrings.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_PooledStrings.m_Elements.m_Tree.m_pElements = this->m_PooledStrings.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_PooledStrings.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_PooledStrings.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  *(_DWORD *)&this->m_Byteswap &= 0xFFFFFFFC;
  this->m_Mode = 0;
  this->m_hFile = nullptr;
  this->m_nQueuedStarts = 0;
  this->m_nQueuedStops = 0;
  this->m_iPlaybackTick = -1;
  *(_DWORD *)&this->m_Byteswap &= 0xFFFFFFFC;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101F4D70
// Name: protected: void CVPROFToCSVConverter::WriteNodeDataToDict(class CVProfNode __near *,class CUtlMap<char __near *,double,unsigned short> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVPROFToCSVConverter::WriteNodeDataToDict(
        CVPROFToCSVConverter *this,
        CVProfNode *pNode,
        CUtlMap<char *,double,unsigned short> *pTickDataMap)
{
  CVProfNode *v4; // edi
  char *m_pszName; // ebx
  CUtlMap<char *,int,unsigned short> *m_pTokenMap; // ecx
  int m_Size; // edi
  int v8; // eax
  char **m_pMemory; // ecx
  int m_nAllocationCount; // eax
  char **v11; // ecx
  int v12; // eax
  char **v13; // eax
  CVProfNode *m_pSibling; // eax
  CUtlMap<char *,double,unsigned short>::Node_t insert; // [esp+Ch] [ebp-18h] BYREF
  CUtlMap<char *,int,unsigned short>::Node_t search; // [esp+1Ch] [ebp-8h] BYREF

  while ( 1 )
  {
    v4 = pNode;
    m_pszName = (char *)pNode->m_pszName;
    if ( _V_strcmp(s1: pNode->m_pszName, s2: "Root") != 0 )
    {
      m_pTokenMap = this->m_pTokenMap;
      if ( m_pTokenMap == nullptr
        || m_pTokenMap->m_Tree.m_NumElements == 0
        || (search.key = m_pszName,
            CUtlRBTree<CUtlMap<char *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
              this: &m_pTokenMap->m_Tree,
              &search) != 0xFFFF) )
      {
        m_Size = this->m_labelVector.m_Size;
        v8 = 0;
        if ( m_Size <= 0 )
          goto LABEL_11;
        m_pMemory = this->m_labelVector.m_Memory.m_pMemory;
        while ( *m_pMemory != m_pszName )
        {
          ++v8;
          ++m_pMemory;
          if ( v8 >= m_Size )
            goto LABEL_11;
        }
        if ( v8 == -1 )
        {
LABEL_11:
          m_nAllocationCount = this->m_labelVector.m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<INetMessage *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: m_Size - m_nAllocationCount + 1);
          ++this->m_labelVector.m_Size;
          v11 = this->m_labelVector.m_Memory.m_pMemory;
          v12 = this->m_labelVector.m_Size - m_Size - 1;
          this->m_labelVector.m_pElements = this->m_labelVector.m_Memory.m_pMemory;
          if ( v12 > 0 )
            _V_memmove(dest: &v11[m_Size + 1], src: &v11[m_Size], count: 4 * v12);
          v13 = &this->m_labelVector.m_Memory.m_pMemory[m_Size];
          if ( v13 != nullptr )
            *v13 = m_pszName;
        }
        insert.key = m_pszName;
        insert.elem = CVProfNode::GetCurTime(this: pNode);
        CUtlRBTree<CUtlMap<char *,double,unsigned short>::Node_t,unsigned short,CUtlMap<char *,double,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char *,double,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
          this: &pTickDataMap->m_Tree,
          &insert);
        v4 = pNode;
      }
    }
    m_pSibling = v4->m_pSibling;
    if ( m_pSibling != nullptr )
      CVPROFToCSVConverter::WriteNodeDataToDict(this, pNode: m_pSibling, pTickDataMap);
    if ( v4->m_pChild == nullptr )
      break;
    pNode = v4->m_pChild;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F4E80
// Name: private: char const __near * CVProfRecorder::PoolString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CVProfRecorder::PoolString(CVProfRecorder *this, char *pStr)
{
  char *v2; // edi
  int v4; // eax
  CUtlMap<char const *,int,int>::Node_t search; // [esp+8h] [ebp-8h] BYREF

  v2 = pStr;
  if ( pStr == nullptr
    || (search.key = pStr,
        (v4 = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
                this: &this->m_PooledStrings.m_Elements.m_Tree,
                &search)) == -1) )
  {
    pStr = nullptr;
    v4 = CUtlDict<int,int>::Insert(this: &this->m_PooledStrings, pName: v2, element: (const int *)&pStr);
  }
  return this->m_PooledStrings.m_Elements.m_Tree.m_Elements.m_pMemory[v4].m_Data.key;
}

//------------------------------------------------------------------------------
// Address: 0x101F4EE0
// Name: public: bool CVProfRecorder::Playback_ReadAddNode(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVProfRecorder::Playback_ReadAddNode(CVProfRecorder *this)
{
  char result; // al
  int v3; // ebx
  CVProfNode *p_m_Root; // eax
  CVProfNode *m_pChild; // edi
  CVProfNode *v6; // edi
  const char *v7; // eax
  struct CVProfNode *SubNode; // eax
  char *m_pName; // [esp-10h] [ebp-220h]
  char nodeName[512]; // [esp+4h] [ebp-20Ch] BYREF
  int parentNodeID; // [esp+204h] [ebp-Ch] BYREF
  int nodeID; // [esp+208h] [ebp-8h] BYREF
  int budgetGroupID; // [esp+20Ch] [ebp-4h] BYREF

  CVProfRecorder::Read<unsigned long>(this, a2: (int)this, pData: (unsigned int *)&parentNodeID);
  result = CVProfRecorder::Playback_ReadString(this, pOut: nodeName, maxLen: 512);
  if ( result != 0 )
  {
    CVProfRecorder::Read<unsigned long>(this, a2: (int)this, pData: (unsigned int *)&budgetGroupID);
    CVProfRecorder::Read<unsigned long>(this, a2: (int)this, pData: (unsigned int *)&nodeID);
    v3 = parentNodeID;
    p_m_Root = &this->m_Root;
    if ( this->m_Root.m_iUniqueNodeID != parentNodeID )
    {
      m_pChild = this->m_Root.m_pChild;
      if ( m_pChild == nullptr )
      {
LABEL_8:
        CVProfRecorder::Stop(this);
        _Warning(a1: "VPROF PLAYBACK ASSERT (%s, line %d) - stopping playback.\n", "..\\engine\\vprof_record.cpp", 469);
        return 0;
      }
      while ( 1 )
      {
        p_m_Root = CVProfRecorder::FindVProfNodeByID_R(this, pNode: m_pChild, id: v3);
        if ( p_m_Root != nullptr )
          break;
        m_pChild = m_pChild->m_pSibling;
        if ( m_pChild == nullptr )
          goto LABEL_8;
      }
    }
    v6 = p_m_Root;
    if ( p_m_Root == nullptr )
      goto LABEL_8;
    m_pName = this->m_pBudgetGroups->m_pName;
    v7 = CVProfRecorder::PoolString(this, pStr: nodeName);
    SubNode = CVProfNode::GetSubNode(this: v6, a2: v7, a3: 0, a4: m_pName, a5: 0);
    SubNode->m_BudgetGroupID = budgetGroupID;
    SubNode->m_iUniqueNodeID = nodeID;
    this->m_bNodesChanged = true;
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F4FD0
// Name: public: bool CVProfRecorder::Playback_ReadTick(int,bool __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVProfRecorder::Playback_ReadTick(CVProfRecorder *this, int iDontGoPast, bool *pWouldHaveGonePast)
{
  bool *v3; // edi
  bool v5; // zf
  char v6; // al
  char result; // al
  char pOut[512]; // [esp+8h] [ebp-204h] BYREF
  int iPlaybackTick; // [esp+208h] [ebp-4h] BYREF

  v3 = pWouldHaveGonePast;
  if ( pWouldHaveGonePast != nullptr )
    *pWouldHaveGonePast = false;
  if ( this->m_Mode != 2 )
    return 0;
  v5 = CVProfRecorder::Read<unsigned char>(this, a2: (int)this, pData: (unsigned __int8 *)&pWouldHaveGonePast + 3) == 1;
  v6 = 5;
  if ( v5 )
    v6 = HIBYTE(pWouldHaveGonePast);
  if ( v6 == 5 )
  {
    _Msg(a1: "VPROF playback finished.\n");
    this->m_bPlaybackFinished = true;
    return 1;
  }
  if ( v6 != 0 )
  {
    CVProfRecorder::Stop(this);
    _Warning(a1: "VPROF PLAYBACK ASSERT (%s, line %d) - stopping playback.\n", "..\\engine\\vprof_record.cpp", 554);
    return 0;
  }
  iPlaybackTick = this->m_iPlaybackTick;
  CVProfRecorder::Read<unsigned long>(this, a2: (int)this, pData: (unsigned int *)&iPlaybackTick);
  if ( iDontGoPast == -1 || iPlaybackTick <= iDontGoPast )
  {
    this->m_iPlaybackTick = iPlaybackTick;
    while ( 1 )
    {
      if ( CVProfRecorder::Read<unsigned char>(this, a2: (int)this, pData: (unsigned __int8 *)&pWouldHaveGonePast + 3) != 1 )
        HIBYTE(pWouldHaveGonePast) = 5;
      if ( SHIBYTE(pWouldHaveGonePast) == 4 )
        break;
      switch ( SHIBYTE(pWouldHaveGonePast) )
      {
        case 2:
          if ( CVProfRecorder::Playback_ReadString(this, pOut, maxLen: 512) == 0 )
            return 0;
          iDontGoPast = 0;
          CVProfRecorder::Read<unsigned long>(this, a2: (int)this, pData: (unsigned int *)&iDontGoPast);
          CVProfile::AddBudgetGroupName(this, a2: pOut, a3: iDontGoPast);
          break;
        case 1:
          result = CVProfRecorder::Playback_ReadAddNode(this);
          if ( result == 0 )
            return result;
          break;
        case 3:
          result = CVProfRecorder::Playback_ReadTimings_R(this, a2: (int)this, pNode: (unsigned int)&this->m_Root);
          if ( result == 0 )
            return result;
          break;
        default:
          CVProfRecorder::Stop(this);
          _Warning(
            a1: "VPROF PLAYBACK ASSERT (%s, line %d) - stopping playback.\n",
            "..\\engine\\vprof_record.cpp",
            595);
          return 0;
      }
    }
    return 1;
  }
  *v3 = true;
  g_pFileSystem->Seek(this: &g_pFileSystem->IBaseFileSystem, a2: this->m_hFile, a3: -5, a4: FILESYSTEM_SEEK_CURRENT);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101F5160
// Name: public: void CVProfRecorder::Playback_Average(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfRecorder::Playback_Average(CVProfRecorder *this, int nFrames)
{
  unsigned int v3; // eax
  int v4; // edi
  int m_iPlaybackTick; // ecx
  CUtlVector<CVProfRecorder::CNodeAverage,CUtlMemory<CVProfRecorder::CNodeAverage,int> > averages; // [esp+Ch] [ebp-1Ch] BYREF
  int iOldPlaybackTick; // [esp+20h] [ebp-8h]
  unsigned int seekPos; // [esp+24h] [ebp-4h]

  v3 = g_pFileSystem->Tell(this: &g_pFileSystem->IBaseFileSystem, a2: this->m_hFile);
  v4 = nFrames;
  m_iPlaybackTick = this->m_iPlaybackTick;
  seekPos = v3;
  iOldPlaybackTick = m_iPlaybackTick;
  memset(&averages, 0, sizeof(averages));
  if ( nFrames > 0 )
  {
    do
    {
      if ( this->m_bPlaybackFinished )
        break;
      CVProfRecorder::Playback_ReadTick(this, iDontGoPast: -1, pWouldHaveGonePast: nullptr);
      CVProfRecorder::UpdateAverages_R(this, &averages, pNode: &this->m_Root);
      --v4;
    }
    while ( v4 > 0 );
  }
  CVProfRecorder::DumpAverages_R(this, &averages, pNode: &this->m_Root);
  g_pFileSystem->Seek(this: &g_pFileSystem->IBaseFileSystem, a2: this->m_hFile, a3: seekPos, a4: FILESYSTEM_SEEK_HEAD);
  this->m_iPlaybackTick = iOldPlaybackTick;
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&averages);
}

//------------------------------------------------------------------------------
// Address: 0x101F5220
// Name: vprof_playback_average
// Source: json
//------------------------------------------------------------------------------
void __cdecl vprof_playback_average(const CCommand *args)
{
  const char *v1; // eax
  int v2; // eax

  if ( args->m_nArgc < 2 )
  {
    _Warning(a1: "vprof_playback_average [# frames]\n");
    _Warning(a1: "If # frames is -1, then it will average all the remaining frames in the vprof file.\n");
  }
  else
  {
    v1 = defaultValue;
    if ( args->m_nArgc > 1 )
      v1 = args->m_ppArgv[1];
    v2 = atoi(nptr: v1);
    if ( v2 == -1 )
      v2 = 9999999;
    CVProfRecorder::Playback_Average(this: &g_VProfRecorder, nFrames: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F5280
// Name: void VProfRecord_Snapshot(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VProfRecord_Snapshot()
{
  if ( g_VProfRecorder.m_Mode == 1 )
  {
    CVProfRecorder::Record_Snapshot(this: &g_VProfRecorder);
  }
  else if ( g_VProfRecorder.m_Mode == 2 && !g_VProfRecorder.m_bPlaybackPaused )
  {
    CVProfRecorder::Playback_ReadTick(this: &g_VProfRecorder, iDontGoPast: -1, pWouldHaveGonePast: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F52C0
// Name: void VProfPlayback_Step(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VProfPlayback_Step()
{
  CVProfRecorder::Playback_ReadTick(this: &g_VProfRecorder, iDontGoPast: -1, pWouldHaveGonePast: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101F52D0
// Name: public: bool CVProfRecorder::Playback_Start(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVProfRecorder::Playback_Start(CVProfRecorder *this, char *pFilename)
{
  char *v3; // edi
  int v4; // eax
  void *v5; // eax
  int v7; // eax
  void *m_hFile; // edx
  char tempFilename[512]; // [esp+8h] [ebp-204h] BYREF
  int nodeID; // [esp+208h] [ebp-4h] BYREF

  CVProfRecorder::Stop(this);
  v3 = pFilename;
  strchr(string: pFilename, chr: 0x2Eu);
  if ( v4 == 0 )
  {
    V_snprintf(pDest: tempFilename, maxLen: 512, pFormat: "%s.vprof", v3);
    v3 = tempFilename;
  }
  this->m_iLastUniqueNodeID = -1;
  v5 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: v3, a3: "rb", a4: 0);
  this->m_hFile = v5;
  this->m_Mode = 2;
  this->m_bPlaybackPaused = true;
  if ( v5 != nullptr )
  {
    CVProfRecorder::Read<unsigned long>(this, a2: (int)this, pData: (unsigned int *)&pFilename);
    if ( pFilename == (char *)1 )
    {
      CVProfRecorder::Read<unsigned long>(this, a2: (int)this, pData: (unsigned int *)&nodeID);
      this->m_Root.m_iUniqueNodeID = nodeID;
      v7 = g_pFileSystem->Tell(this: &g_pFileSystem->IBaseFileSystem, a2: this->m_hFile);
      m_hFile = this->m_hFile;
      this->m_iSkipPastHeaderPos = v7;
      this->m_bPlaybackFinished = false;
      this->m_FileLen = g_pFileSystem->Size_2(this: &g_pFileSystem->IBaseFileSystem, a2: m_hFile);
      this->m_enabled = 1;
      CVProfRecorder::Playback_ReadTick(this, iDontGoPast: -1, pWouldHaveGonePast: nullptr);
      g_pVProfileForDisplay = this;
      return 1;
    }
    else
    {
      CVProfRecorder::Stop(this);
      _Warning(a1: "VPROF PLAYBACK ASSERT (%s, line %d) - stopping playback.\n", "..\\engine\\vprof_record.cpp", 343);
      return 0;
    }
  }
  else
  {
    _Warning(a1: "vprof_playback_start: Open( %s ) failed.\n", v3);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F5420
// Name: public: void CVProfRecorder::Playback_Restart(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVProfRecorder::Playback_Restart(CVProfRecorder *this)
{
  int m_iSkipPastHeaderPos; // edx

  if ( this->m_Mode == 2 )
  {
    this->m_iPlaybackTick = -1;
    CVProfile::Term(this);
    m_iSkipPastHeaderPos = this->m_iSkipPastHeaderPos;
    this->m_bNodesChanged = true;
    g_pFileSystem->Seek(
      this: &g_pFileSystem->IBaseFileSystem,
      a2: this->m_hFile,
      a3: m_iSkipPastHeaderPos,
      a4: FILESYSTEM_SEEK_HEAD);
    CVProfRecorder::Playback_ReadTick(this, iDontGoPast: -1, pWouldHaveGonePast: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F5480
// Name: public: int CVProfRecorder::Playback_SetPlaybackTick(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVProfRecorder::Playback_SetPlaybackTick(CVProfRecorder *this, int iTick)
{
  int m_iPlaybackTick; // eax
  int v5; // edi
  bool i; // cc

  if ( this->m_Mode != 2 )
    return 0;
  m_iPlaybackTick = this->m_iPlaybackTick;
  v5 = iTick;
  this->m_bNodesChanged = false;
  if ( v5 == m_iPlaybackTick )
    return 1;
  if ( v5 >= m_iPlaybackTick )
  {
    if ( m_iPlaybackTick < v5 )
      goto LABEL_10;
  }
  else
  {
    CVProfRecorder::Playback_Restart(this);
    for ( i = this->m_iPlaybackTick < v5; i; i = this->m_iPlaybackTick < v5 )
    {
LABEL_10:
      HIBYTE(iTick) = 0;
      if ( CVProfRecorder::Playback_ReadTick(this, iDontGoPast: v5, pWouldHaveGonePast: (bool *)&iTick + 3) == 0 )
        return 0;
      if ( HIBYTE(iTick) != 0 || this->m_bPlaybackFinished )
        return this->m_bNodesChanged + 1;
    }
  }
  return this->m_bNodesChanged + 1;
}

//------------------------------------------------------------------------------
// Address: 0x101F5520
// Name: public: int CVProfRecorder::Playback_SeekToPercent(float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVProfRecorder::Playback_SeekToPercent(CVProfRecorder *this, float flWantedPercent)
{
  void *m_hFile; // edx

  if ( this->m_Mode != 2 )
    return 0;
  m_hFile = this->m_hFile;
  this->m_bNodesChanged = false;
  if ( (double)g_pFileSystem->Tell(this: &g_pFileSystem->IBaseFileSystem, a2: m_hFile) / (double)this->m_FileLen <= flWantedPercent
    || (CVProfRecorder::Playback_Restart(this), flWantedPercent > 0.0) )
  {
    if ( flWantedPercent > (double)g_pFileSystem->Tell(this: &g_pFileSystem->IBaseFileSystem, a2: this->m_hFile)
                         / (double)this->m_FileLen )
    {
      while ( CVProfRecorder::Playback_ReadTick(this, iDontGoPast: -1, pWouldHaveGonePast: nullptr) != 0 )
      {
        if ( this->m_bPlaybackFinished
          || flWantedPercent <= (double)g_pFileSystem->Tell(this: &g_pFileSystem->IBaseFileSystem, a2: this->m_hFile)
                              / (double)this->m_FileLen )
        {
          return this->m_bNodesChanged + 1;
        }
      }
      return 0;
    }
  }
  return this->m_bNodesChanged + 1;
}

//------------------------------------------------------------------------------
// Address: 0x101F5630
// Name: public: void CVPROFToCSVConverter::ConvertVPROJFileToCSVFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVPROFToCSVConverter::ConvertVPROJFileToCSVFile(
        CVPROFToCSVConverter *this,
        char *szVPROJName,
        CUtlMap<char *,double,unsigned short> *szCSVName)
{
  int v4; // ebx
  CUtlMap<char *,double,unsigned short> *v5; // eax
  UtlRBTreeNode_t<CUtlMap<char *,double,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  CUtlMap<char *,double,unsigned short> **v9; // ecx
  int v10; // eax
  CUtlMap<char *,double,unsigned short> **v11; // ebx
  int v12; // edi
  CUtlMap<char *,double,unsigned short> *v13; // ecx
  unsigned __int16 v14; // ax
  char szHeaders[1024]; // [esp+20h] [ebp-C40h] BYREF
  char szData[2048]; // [esp+420h] [ebp-840h] BYREF
  char szFloatValue[32]; // [esp+C20h] [ebp-40h] BYREF
  CUtlMap<char *,double,unsigned short>::Node_t search; // [esp+C40h] [ebp-20h] BYREF
  char szTickNum[16]; // [esp+C50h] [ebp-10h] BYREF
  CUtlMap<char *,double,unsigned short> *pTickDataMap; // [esp+C6Ch] [ebp+Ch]
  CUtlMap<char *,double,unsigned short> *pTickDataMapa; // [esp+C6Ch] [ebp+Ch]

  v4 = 0;
  this->m_fileHandle = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: szCSVName, a3: "w", a4: 0);
  CVProfRecorder::Playback_Start(this: &g_VProfRecorder, pFilename: szVPROJName);
  for ( ; !g_VProfRecorder.m_bPlaybackFinished; v4 = 0 )
  {
    v5 = (CUtlMap<char *,double,unsigned short> *)MemAlloc_Alloc(nSize: 0x1Cu);
    if ( v5 != nullptr )
    {
      v5->m_Tree.m_LessFunc.m_LessFunc = CDefOps<char *>::LessFunc;
      v5->m_Tree.m_Elements.m_pMemory = nullptr;
      v5->m_Tree.m_Elements.m_nAllocationCount = 0;
      v5->m_Tree.m_Elements.m_nGrowSize = 0;
      m_pMemory = v5->m_Tree.m_Elements.m_pMemory;
      *(_DWORD *)&v5->m_Tree.m_Root = 0xFFFF;
      *(_DWORD *)&v5->m_Tree.m_FirstFree = -1;
      v5->m_Tree.m_pElements = m_pMemory;
      pTickDataMap = v5;
    }
    else
    {
      pTickDataMap = nullptr;
    }
    m_Size = this->m_dataVector.m_Size;
    m_nAllocationCount = this->m_dataVector.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<INetMessage *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&this->m_dataVector,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_dataVector.m_Size;
    v9 = this->m_dataVector.m_Memory.m_pMemory;
    v10 = this->m_dataVector.m_Size - m_Size - 1;
    this->m_dataVector.m_pElements = v9;
    if ( v10 > 0 )
      _V_memmove(dest: &v9[m_Size + 1], src: &v9[m_Size], count: 4 * v10);
    v11 = &this->m_dataVector.m_Memory.m_pMemory[m_Size];
    if ( v11 != nullptr )
      *v11 = pTickDataMap;
    CVPROFToCSVConverter::WriteNodeDataToDict(this, pNode: &g_VProfRecorder.m_Root, pTickDataMap);
    CVProfRecorder::Playback_ReadTick(this: &g_VProfRecorder, iDontGoPast: -1, pWouldHaveGonePast: nullptr);
  }
  CVPROFToCSVConverter::WriteHeaders(this, szBuffer: szHeaders, nBufferSize: 1024);
  g_pFileSystem->FPrintf(this: g_pFileSystem, a2: this->m_fileHandle, a3: "%s", szHeaders);
  v12 = 0;
  if ( this->m_dataVector.m_Size > 0 )
  {
    do
    {
      pTickDataMapa = (CUtlMap<char *,double,unsigned short> *)(v12 + 1);
      V_snprintf(pDest: szTickNum, maxLen: 16, pFormat: "%d", v12 + 1);
      V_strncpy(pDest: szData, pSrc: szTickNum, maxLen: 2048);
      V_strncat(pDest: szData, pSrc: ",", destBufferSize: 0x800u, max_chars_to_copy: -1);
      if ( this->m_labelVector.m_Size > 0 )
      {
        do
        {
          v13 = this->m_dataVector.m_Memory.m_pMemory[v12];
          search.key = this->m_labelVector.m_Memory.m_pMemory[v4];
          v14 = CUtlRBTree<CUtlMap<char *,double,unsigned short>::Node_t,unsigned short,CUtlMap<char *,double,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char *,double,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                  this: &v13->m_Tree,
                  &search);
          if ( v14 != 0xFFFF )
          {
            V_snprintf(
              pDest: szFloatValue,
              maxLen: 32,
              pFormat: "%f",
              (double)this->m_dataVector.m_Memory.m_pMemory[v12]->m_Tree.m_Elements.m_pMemory[v14].m_Data.elem);
            V_strncat(pDest: szData, pSrc: szFloatValue, destBufferSize: 0x800u, max_chars_to_copy: -1);
          }
          if ( v4 != this->m_labelVector.m_Size - 1 )
            V_strncat(pDest: szData, pSrc: ",", destBufferSize: 0x800u, max_chars_to_copy: -1);
          ++v4;
        }
        while ( v4 < this->m_labelVector.m_Size );
      }
      V_strncat(pDest: szData, pSrc: "\n", destBufferSize: 0x800u, max_chars_to_copy: -1);
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: this->m_fileHandle, a3: "%s", szData);
      ++v12;
      v4 = 0;
    }
    while ( (int)pTickDataMapa < this->m_dataVector.m_Size );
  }
  g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: this->m_fileHandle);
  this->m_labelVector.m_Size = 0;
  CUtlVector<CUtlMap<char *,double,unsigned short> *,CUtlMemory<CUtlMap<char *,double,unsigned short> *,int>>::PurgeAndDeleteElements(this: &this->m_dataVector);
}

//------------------------------------------------------------------------------
// Address: 0x101F58D0
// Name: vprof_to_csv
// Source: json
//------------------------------------------------------------------------------
void __cdecl vprof_to_csv(const CCommand *args)
{
  int m_nArgc; // eax
  int v2; // esi
  const char **v3; // edi
  const char *v4; // eax
  int v5; // eax
  unsigned __int16 v6; // ax
  unsigned __int16 v7; // dx
  unsigned __int16 v8; // cx
  int v9; // esi
  UtlRBTreeNode_t<CUtlMap<char *,int,unsigned short>::Node_t,unsigned short> *v10; // eax
  int v11; // edx
  CUtlMap<char *,int,unsigned short>::Node_t *p_m_Data; // esi
  int j; // esi
  char **m_pMemory; // eax
  CUtlMap<char *,double,unsigned short> **v15; // eax
  char **v16; // eax
  UtlRBTreeNode_t<CUtlMap<char *,int,unsigned short>::Node_t,unsigned short> *v17; // eax
  char **v18; // eax
  char szArgs[520]; // [esp+4h] [ebp-480h] BYREF
  char szVPROFFilename[260]; // [esp+20Ch] [ebp-278h] BYREF
  char szCSVFilename[260]; // [esp+310h] [ebp-174h] BYREF
  CUtlMap<char *,int,unsigned short>::Node_t insert; // [esp+414h] [ebp-70h] BYREF
  CVPROFToCSVConverter converter; // [esp+41Ch] [ebp-68h] BYREF
  int i; // [esp+44Ch] [ebp-38h]
  unsigned __int16 parent[2]; // [esp+450h] [ebp-34h] BYREF
  CUtlMap<char *,int,unsigned short> tokenMap; // [esp+454h] [ebp-30h] BYREF
  CUtlVector<char *,CUtlMemory<char *,int> > argsVector; // [esp+470h] [ebp-14h] BYREF

  m_nArgc = args->m_nArgc;
  if ( args->m_nArgc >= 2 )
  {
    v2 = 1;
    szArgs[0] = 0;
    if ( m_nArgc > 1 )
    {
      v3 = &args->m_ppArgv[1];
      do
      {
        if ( v2 < 0 || v2 >= m_nArgc )
          v4 = defaultValue;
        else
          v4 = *v3;
        V_strncat(pDest: szArgs, pSrc: v4, destBufferSize: 0x208u, max_chars_to_copy: -1);
        m_nArgc = args->m_nArgc;
        ++v2;
        ++v3;
      }
      while ( v2 < args->m_nArgc );
    }
    memset(&argsVector, 0, sizeof(argsVector));
    tokenMap.m_Tree.m_LessFunc.m_LessFunc = CDefOps<char *>::LessFunc;
    memset(&tokenMap.m_Tree.m_Elements, 0, sizeof(tokenMap.m_Tree.m_Elements));
    *(_DWORD *)&tokenMap.m_Tree.m_Root = 0xFFFF;
    *(_DWORD *)&tokenMap.m_Tree.m_FirstFree = -1;
    tokenMap.m_Tree.m_pElements = nullptr;
    V_SplitString(pString: szArgs, pSeparator: "|", outStrings: &argsVector);
    V_strncpy(pDest: szVPROFFilename, pSrc: *(const char **)argsVector.m_Memory.m_pMemory, maxLen: 260);
    free(pMem: *(void **)argsVector.m_Memory.m_pMemory);
    if ( argsVector.m_Size - 1 > 0 )
      _V_memmove(
        dest: argsVector.m_Memory.m_pMemory,
        src: argsVector.m_Memory.m_pMemory + 1,
        count: 4 * (argsVector.m_Size - 1));
    v5 = 0;
    --argsVector.m_Size;
    i = 0;
    if ( argsVector.m_Size > 0 )
    {
      do
      {
        insert.key = argsVector.m_Memory.m_pMemory[v5];
        insert.elem = 0;
        *(_DWORD *)parent = 0xFFFF;
        HIBYTE(args) = 0;
        CUtlRBTree<CUtlMap<char *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
          this: &tokenMap.m_Tree,
          &insert,
          parent,
          leftchild: (bool *)&args + 3);
        v6 = CUtlRBTree<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short,CUtlMap<int,enum ESocketIndex_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this: (CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&tokenMap);
        v7 = parent[0];
        v8 = v6;
        v9 = v6;
        v10 = &tokenMap.m_Tree.m_Elements.m_pMemory[v9];
        v10->m_Right = -1;
        v10->m_Left = -1;
        v10->m_Parent = v7;
        v10->m_Tag = 0;
        if ( v7 == 0xFFFF )
        {
          tokenMap.m_Tree.m_Root = v8;
        }
        else
        {
          v11 = v7;
          if ( HIBYTE(args) != 0 )
            tokenMap.m_Tree.m_Elements.m_pMemory[v11].m_Left = v8;
          else
            tokenMap.m_Tree.m_Elements.m_pMemory[v11].m_Right = v8;
        }
        CUtlRBTree<CUtlMap<char *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
          this: &tokenMap.m_Tree,
          elem: v8);
        ++tokenMap.m_Tree.m_NumElements;
        p_m_Data = &tokenMap.m_Tree.m_Elements.m_pMemory[v9].m_Data;
        if ( p_m_Data != nullptr )
          *p_m_Data = insert;
        v5 = i + 1;
        i = v5;
      }
      while ( v5 < argsVector.m_Size );
    }
    V_StripExtension(in: szVPROFFilename, out: szCSVFilename, outSize: 260);
    V_strncat(pDest: szCSVFilename, pSrc: ".csv", destBufferSize: 0x104u, max_chars_to_copy: -1);
    converter.m_pTokenMap = &tokenMap;
    memset(&converter, 0, 40);
    CVPROFToCSVConverter::ConvertVPROJFileToCSVFile(
      this: &converter,
      szVPROJName: szVPROFFilename,
      szCSVName: (CUtlMap<char *,double,unsigned short> *)szCSVFilename);
    for ( j = 0; j < argsVector.m_Size; ++j )
      free(pMem: argsVector.m_Memory.m_pMemory[j]);
    m_pMemory = argsVector.m_Memory.m_pMemory;
    argsVector.m_Size = 0;
    if ( argsVector.m_Memory.m_nGrowSize >= 0 )
    {
      if ( argsVector.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: argsVector.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        argsVector.m_Memory.m_pMemory = nullptr;
      }
      argsVector.m_Memory.m_nAllocationCount = 0;
    }
    argsVector.m_pElements = m_pMemory;
    CUtlRBTree<CUtlMap<char *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &tokenMap.m_Tree);
    v15 = converter.m_dataVector.m_Memory.m_pMemory;
    converter.m_dataVector.m_Size = 0;
    if ( converter.m_dataVector.m_Memory.m_nGrowSize >= 0 )
    {
      if ( converter.m_dataVector.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: converter.m_dataVector.m_Memory.m_pMemory);
        v15 = nullptr;
        converter.m_dataVector.m_Memory.m_pMemory = nullptr;
      }
      converter.m_dataVector.m_Memory.m_nAllocationCount = 0;
    }
    converter.m_dataVector.m_pElements = v15;
    if ( converter.m_dataVector.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v15 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v15);
        converter.m_dataVector.m_Memory.m_pMemory = nullptr;
      }
      converter.m_dataVector.m_Memory.m_nAllocationCount = 0;
    }
    v16 = converter.m_labelVector.m_Memory.m_pMemory;
    converter.m_labelVector.m_Size = 0;
    if ( converter.m_labelVector.m_Memory.m_nGrowSize >= 0 )
    {
      if ( converter.m_labelVector.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: converter.m_labelVector.m_Memory.m_pMemory);
        v16 = nullptr;
        converter.m_labelVector.m_Memory.m_pMemory = nullptr;
      }
      converter.m_labelVector.m_Memory.m_nAllocationCount = 0;
    }
    converter.m_labelVector.m_pElements = v16;
    if ( converter.m_labelVector.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v16 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v16);
        converter.m_labelVector.m_Memory.m_pMemory = nullptr;
      }
      converter.m_labelVector.m_Memory.m_nAllocationCount = 0;
    }
    CUtlRBTree<CUtlMap<char *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &tokenMap.m_Tree);
    v17 = tokenMap.m_Tree.m_Elements.m_pMemory;
    tokenMap.m_Tree.m_FirstFree = -1;
    if ( tokenMap.m_Tree.m_Elements.m_nGrowSize >= 0 )
    {
      if ( tokenMap.m_Tree.m_Elements.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tokenMap.m_Tree.m_Elements.m_pMemory);
        v17 = nullptr;
        tokenMap.m_Tree.m_Elements.m_pMemory = nullptr;
      }
      tokenMap.m_Tree.m_Elements.m_nAllocationCount = 0;
    }
    tokenMap.m_Tree.m_LastAlloc.index = -1;
    if ( tokenMap.m_Tree.m_Elements.m_nGrowSize >= 0 )
    {
      if ( v17 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v17);
        tokenMap.m_Tree.m_Elements.m_pMemory = nullptr;
      }
      tokenMap.m_Tree.m_Elements.m_nAllocationCount = 0;
    }
    v18 = argsVector.m_Memory.m_pMemory;
    argsVector.m_Size = 0;
    if ( argsVector.m_Memory.m_nGrowSize >= 0 )
    {
      if ( argsVector.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: argsVector.m_Memory.m_pMemory);
        v18 = nullptr;
        argsVector.m_Memory.m_pMemory = nullptr;
      }
      argsVector.m_Memory.m_nAllocationCount = 0;
    }
    argsVector.m_pElements = v18;
    if ( argsVector.m_Memory.m_nGrowSize >= 0 && v18 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v18);
  }
  else
  {
    _Warning(a1: "vprof_to_csv requires an input filename (.VPROJ) and optional VPROF node names\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F5C90
// Name: vprof_playback_start
// Source: json
//------------------------------------------------------------------------------
void __cdecl vprof_playback_start(const CCommand *args)
{
  int m_nArgc; // eax
  int v2; // esi
  const char **v3; // edi
  const char *v4; // eax
  char fullFilename[512]; // [esp+4h] [ebp-200h] BYREF

  m_nArgc = args->m_nArgc;
  if ( args->m_nArgc >= 2 )
  {
    v2 = 1;
    fullFilename[0] = 0;
    if ( m_nArgc > 1 )
    {
      v3 = &args->m_ppArgv[1];
      do
      {
        if ( v2 < 0 || v2 >= m_nArgc )
          v4 = defaultValue;
        else
          v4 = *v3;
        V_strncat(pDest: fullFilename, pSrc: v4, destBufferSize: 0x200u, max_chars_to_copy: -1);
        m_nArgc = args->m_nArgc;
        ++v2;
        ++v3;
      }
      while ( v2 < args->m_nArgc );
    }
    CVProfRecorder::Playback_Start(this: &g_VProfRecorder, pFilename: fullFilename);
  }
  else
  {
    _Warning(a1: "vprof_playback_start requires a filename\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F5D20
// Name: int VProfPlayback_SeekToPercent(float)
// Source: json
//------------------------------------------------------------------------------
int __cdecl VProfPlayback_SeekToPercent(float percent)
{
  return CVProfRecorder::Playback_SeekToPercent(this: &g_VProfRecorder, flWantedPercent: percent);
}

//------------------------------------------------------------------------------
// Address: 0x101F5D40
// Name: int VProfPlayback_StepBack(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VProfPlayback_StepBack()
{
  CVProfRecorder::Playback_SetPlaybackTick(this: &g_VProfRecorder, iTick: g_VProfRecorder.m_iPlaybackTick - 1);
}

//------------------------------------------------------------------------------
// Address: 0x102A7720
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx

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
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: 28 * m_nAllocationCount);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 28 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10312F50
// Name: _dynamic_initializer_for__record_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__record_command__()
{
  ConCommand::ConCommand(
    this: &record_command,
    pName: "record",
    callback: record,
    pHelpString: "Record a demo.",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__record_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10312F80
// Name: _dynamic_initializer_for___record_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for___record_command__()
{
  ConCommand::ConCommand(
    this: &record_command,
    pName: "_record",
    callback: record,
    pHelpString: "Record a demo incrementally.",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for___record_command__);
}

//------------------------------------------------------------------------------
// Address: 0x103225F0
// Name: _dynamic_atexit_destructor_for__record_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__record_command__()
{
  ConCommand::~ConCommand(this: &record_command);
}

//------------------------------------------------------------------------------
// Address: 0x10322600
// Name: _dynamic_atexit_destructor_for___record_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for___record_command__()
{
  ConCommand::~ConCommand(this: &record_command);
}

//------------------------------------------------------------------------------
// Address: 0x10312FB0
// Name: _dynamic_initializer_for__vtune_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__vtune_command__()
{
  ConCommand::ConCommand(
    this: &vtune_command,
    pName: "vtune",
    callback: vtune_0,
    pHelpString: "Controls VTune's sampling.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vtune_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10312FE0
// Name: _dynamic_initializer_for__playdemo_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__playdemo_command__()
{
  ConCommand::ConCommand(
    this: &playdemo_command,
    pName: "playdemo",
    callback: CL_PlayDemo_f,
    pHelpString: "Play a recorded demo file (.dem ).",
    flags: 0,
    completionFunc: g_playdemo_CompletionFunc);
  return atexit(func: dynamic_atexit_destructor_for__playdemo_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10313010
// Name: _dynamic_initializer_for__timedemo_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__timedemo_command__()
{
  ConCommand::ConCommand(
    this: &timedemo_command,
    pName: "timedemo",
    callback: CL_TimeDemo_f,
    pHelpString: "Play a demo and report performance info.",
    flags: 0,
    completionFunc: g_timedemo_CompletionFunc);
  return atexit(func: dynamic_atexit_destructor_for__timedemo_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10313040
// Name: _dynamic_initializer_for__timedemoquit_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__timedemoquit_command__()
{
  ConCommand::ConCommand(
    this: &timedemoquit_command,
    pName: "timedemoquit",
    callback: CL_TimeDemoQuit_f,
    pHelpString: "Play a demo, report performance info, and then exit",
    flags: 0,
    completionFunc: g_timedemoquit_CompletionFunc);
  return atexit(func: dynamic_atexit_destructor_for__timedemoquit_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10313070
// Name: _dynamic_initializer_for__listdemo_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__listdemo_command__()
{
  ConCommand::ConCommand(
    this: &listdemo_command,
    pName: "listdemo",
    callback: CL_ListDemo_f,
    pHelpString: "List demo file contents.",
    flags: 0,
    completionFunc: g_listdemo_CompletionFunc);
  return atexit(func: dynamic_atexit_destructor_for__listdemo_command__);
}

//------------------------------------------------------------------------------
// Address: 0x103130A0
// Name: _dynamic_initializer_for__benchframe_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__benchframe_command__()
{
  ConCommand::ConCommand(
    this: &benchframe_command,
    pName: "benchframe",
    callback: CL_BenchFrame_f,
    pHelpString: "Takes a snapshot of a particular frame in a time demo.",
    flags: 0,
    completionFunc: g_benchframe_CompletionFunc);
  return atexit(func: dynamic_atexit_destructor_for__benchframe_command__);
}

//------------------------------------------------------------------------------
// Address: 0x103130D0
// Name: _dynamic_initializer_for__timedemo_vprofrecord_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__timedemo_vprofrecord_command__()
{
  ConCommand::ConCommand(
    this: &timedemo_vprofrecord_command,
    pName: "timedemo_vprofrecord",
    callback: CL_TimeDemo_VProfRecord_f,
    pHelpString: "Play a demo and report performance info.  Also record vprof data for the span of the demo",
    flags: 0,
    completionFunc: g_timedemo_vprofrecord_CompletionFunc);
  return atexit(func: dynamic_atexit_destructor_for__timedemo_vprofrecord_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10322610
// Name: _dynamic_atexit_destructor_for__vtune_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vtune_command__()
{
  ConCommand::~ConCommand(this: &vtune_command);
}

//------------------------------------------------------------------------------
// Address: 0x10322620
// Name: _dynamic_atexit_destructor_for__playdemo_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__playdemo_command__()
{
  ConCommand::~ConCommand(this: &playdemo_command);
}

//------------------------------------------------------------------------------
// Address: 0x10322630
// Name: _dynamic_atexit_destructor_for__timedemo_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__timedemo_command__()
{
  ConCommand::~ConCommand(this: &timedemo_command);
}

//------------------------------------------------------------------------------
// Address: 0x10322640
// Name: _dynamic_atexit_destructor_for__timedemoquit_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__timedemoquit_command__()
{
  ConCommand::~ConCommand(this: &timedemoquit_command);
}

//------------------------------------------------------------------------------
// Address: 0x10322650
// Name: _dynamic_atexit_destructor_for__listdemo_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__listdemo_command__()
{
  ConCommand::~ConCommand(this: &listdemo_command);
}

//------------------------------------------------------------------------------
// Address: 0x10322660
// Name: _dynamic_atexit_destructor_for__benchframe_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__benchframe_command__()
{
  ConCommand::~ConCommand(this: &benchframe_command);
}

//------------------------------------------------------------------------------
// Address: 0x10322670
// Name: _dynamic_atexit_destructor_for__timedemo_vprofrecord_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__timedemo_vprofrecord_command__()
{
  ConCommand::~ConCommand(this: &timedemo_vprofrecord_command);
}

} // namespace engine_xlsp

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10313C60
// Name: _dynamic_initializer_for__vprof_remote_start_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_remote_start_command__()
{
  ConCommand::ConCommand(
    this: &vprof_remote_start_command,
    pName: "vprof_remote_start",
    callback: (void (__cdecl *)(const CCommand *))CColorBalanceUIPanel::Init,
    pHelpString: "Request a VProf data stream from the remote server (requires authentication)",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_remote_start_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10313C90
// Name: _dynamic_initializer_for__vprof_remote_stop_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_remote_stop_command__()
{
  ConCommand::ConCommand(
    this: &vprof_remote_stop_command,
    pName: "vprof_remote_stop",
    callback: (void (__cdecl *)(const CCommand *))CColorBalanceUIPanel::Init,
    pHelpString: "Stop an existing remote VProf data request",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_remote_stop_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031AA50
// Name: _dynamic_initializer_for__vprof_server_spike_threshold__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_server_spike_threshold__()
{
  ConVar::ConVar(
    this: &vprof_server_spike_threshold,
    pName: "vprof_server_spike_threshold",
    pDefaultValue: "999.0",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__vprof_server_spike_threshold__);
}

//------------------------------------------------------------------------------
// Address: 0x1031AA80
// Name: _dynamic_initializer_for__vprof_server_thread__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_server_thread__()
{
  ConVar::ConVar(this: &vprof_server_thread, pName: "vprof_server_thread", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__vprof_server_thread__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E6C0
// Name: _dynamic_initializer_for__vprof_dump_spikes__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_dump_spikes__()
{
  ConVar::ConVar(
    this: &vprof_dump_spikes,
    pName: "vprof_dump_spikes",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Framerate at which vprof will begin to dump spikes to the console. 0 = disabled, negative to reset after dump");
  return atexit(func: dynamic_atexit_destructor_for__vprof_dump_spikes__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E6F0
// Name: _dynamic_initializer_for__vprof_dump_spikes_terse__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_dump_spikes_terse__()
{
  ConVar::ConVar(
    this: &vprof_dump_spikes_terse,
    pName: "vprof_dump_spikes_terse",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Whether to use most terse output");
  return atexit(func: dynamic_atexit_destructor_for__vprof_dump_spikes_terse__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E720
// Name: _dynamic_initializer_for__vprof_dump_spikes_hierarchy__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_dump_spikes_hierarchy__()
{
  ConVar::ConVar(
    this: &vprof_dump_spikes_hierarchy,
    pName: "vprof_dump_spikes_hiearchy",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Set to 1 to get a hierarchy report whith vprof_dump_spikes");
  return atexit(func: dynamic_atexit_destructor_for__vprof_dump_spikes_hierarchy__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E750
// Name: _dynamic_initializer_for__vprof_dump_spikes_node__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_dump_spikes_node__()
{
  ConVar::ConVar(
    this: &vprof_dump_spikes_node,
    pName: "vprof_dump_spikes_node",
    pDefaultValue: defaultValue,
    flags: 0,
    pHelpString: "Node to start report from when doing a dump spikes");
  return atexit(func: dynamic_atexit_destructor_for__vprof_dump_spikes_node__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E780
// Name: _dynamic_initializer_for__vprof_dump_spikes_budget_group__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_dump_spikes_budget_group__()
{
  ConVar::ConVar(
    this: &vprof_dump_spikes_budget_group,
    pName: "vprof_dump_spikes_budget_group",
    pDefaultValue: defaultValue,
    flags: 0,
    pHelpString: "Budget gtNode to start report from when doing a dump spikes");
  return atexit(func: dynamic_atexit_destructor_for__vprof_dump_spikes_budget_group__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E7B0
// Name: _dynamic_initializer_for__vprof_dump_oninterval__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_dump_oninterval__()
{
  ConVar::ConVar(
    this: &vprof_dump_oninterval,
    pName: "vprof_dump_oninterval",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Interval (in seconds) at which vprof will batch up data and dump it to the console.");
  return atexit(func: dynamic_atexit_destructor_for__vprof_dump_oninterval__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E7F0
// Name: _dynamic_initializer_for__vprof_counters__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_counters__()
{
  ConVar::ConVar(this: &vprof_counters, pName: "vprof_counters", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__vprof_counters__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E820
// Name: _dynamic_initializer_for__vprof_counters_show_minmax__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_counters_show_minmax__()
{
  ConVar::ConVar(this: &vprof_counters_show_minmax, pName: "vprof_counters_show_minmax", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__vprof_counters_show_minmax__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E850
// Name: _dynamic_initializer_for__vprof_dump_counters_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_dump_counters_command__()
{
  ConCommand::ConCommand(
    this: &vprof_dump_counters_command,
    pName: "vprof_dump_counters",
    callback: vprof_dump_counters,
    pHelpString: "Dump vprof counters to the console",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_dump_counters_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E8B0
// Name: _dynamic_initializer_for__vprof_vtune_group_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_vtune_group_command__()
{
  ConCommand::ConCommand(
    this: &vprof_vtune_group_command,
    pName: "vprof_vtune_group",
    callback: vprof_vtune_group,
    pHelpString: "enable vtune for a particular vprof group (\"disable\" to disable)",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_vtune_group_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E8E0
// Name: _dynamic_initializer_for__vprof_dump_groupnames_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_dump_groupnames_command__()
{
  ConCommand::ConCommand(
    this: &vprof_dump_groupnames_command,
    pName: "vprof_dump_groupnames",
    callback: vprof_dump_groupnames,
    pHelpString: "Write the names of all of the vprof groups to the console.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_dump_groupnames_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E910
// Name: _dynamic_initializer_for__vprof_cachemiss_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_cachemiss_command__()
{
  ConCommand::ConCommand(
    this: &vprof_cachemiss_command,
    pName: "vprof_cachemiss",
    callback: vprof_cachemiss,
    pHelpString: "Toggle VProf cache miss checking",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_cachemiss_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E940
// Name: _dynamic_initializer_for__vprof_cachemiss_on_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_cachemiss_on_command__()
{
  ConCommand::ConCommand(
    this: &vprof_cachemiss_on_command,
    pName: "vprof_cachemiss_on",
    callback: vprof_cachemiss_on,
    pHelpString: "Turn on VProf cache miss checking",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_cachemiss_on_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E970
// Name: _dynamic_initializer_for__vprof_cachemiss_off_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_cachemiss_off_command__()
{
  ConCommand::ConCommand(
    this: &vprof_cachemiss_off_command,
    pName: "vprof_cachemiss_off",
    callback: vprof_cachemiss_off,
    pHelpString: "Turn off VProf cache miss checking",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_cachemiss_off_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E9A0
// Name: _dynamic_initializer_for__vprof_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_command__()
{
  ConCommand::ConCommand(
    this: &vprof_command,
    pName: "vprof",
    callback: vprof,
    pHelpString: "Toggle VProf profiler",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E9D0
// Name: _dynamic_initializer_for__vprof_on_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_on_command__()
{
  ConCommand::ConCommand(
    this: &vprof_on_command,
    pName: "vprof_on",
    callback: vprof_on,
    pHelpString: "Turn on VProf profiler",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_on_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031EA30
// Name: _dynamic_initializer_for__vprof_off_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_off_command__()
{
  ConCommand::ConCommand(
    this: &vprof_off_command,
    pName: "vprof_off",
    callback: vprof_off,
    pHelpString: "Turn off VProf profiler",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_off_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031EA60
// Name: _dynamic_initializer_for__vprof_reset_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_reset_command__()
{
  ConCommand::ConCommand(
    this: &vprof_reset_command,
    pName: "vprof_reset",
    callback: vprof_reset,
    pHelpString: "Reset the stats in VProf profiler",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_reset_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031EA90
// Name: _dynamic_initializer_for__vprof_reset_peaks_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_reset_peaks_command__()
{
  ConCommand::ConCommand(
    this: &vprof_reset_peaks_command,
    pName: "vprof_reset_peaks",
    callback: vprof_reset_peaks,
    pHelpString: "Reset just the peak time in VProf profiler",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_reset_peaks_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031EAC0
// Name: _dynamic_initializer_for__vprof_generate_report_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_generate_report_command__()
{
  ConCommand::ConCommand(
    this: &vprof_generate_report_command,
    pName: "vprof_generate_report",
    callback: vprof_generate_report,
    pHelpString: "Generate a report to the console.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_generate_report_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031EAF0
// Name: _dynamic_initializer_for__vprof_generate_report_budget_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_generate_report_budget_command__()
{
  ConCommand::ConCommand(
    this: &vprof_generate_report_budget_command,
    pName: "vprof_generate_report_budget",
    callback: vprof_generate_report_budget,
    pHelpString: "Generate a report to the console based on budget group.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_generate_report_budget_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031EB20
// Name: _dynamic_initializer_for__vprof_generate_report_hierarchy_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_generate_report_hierarchy_command__()
{
  ConCommand::ConCommand(
    this: &vprof_generate_report_hierarchy_command,
    pName: "vprof_generate_report_hierarchy",
    callback: vprof_generate_report_hierarchy,
    pHelpString: "Generate a report to the console.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_generate_report_hierarchy_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031EB50
// Name: _dynamic_initializer_for__vprof_generate_report_hierarchy_per_frame_and_count_only_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_generate_report_hierarchy_per_frame_and_count_only_command__()
{
  ConCommand::ConCommand(
    this: &vprof_generate_report_hierarchy_per_frame_and_count_only_command,
    pName: "vprof_generate_report_hierarchy_per_frame_and_count_only",
    callback: vprof_generate_report_hierarchy_per_frame_and_count_only,
    pHelpString: "Generate a minimal hiearchical report to the console.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_generate_report_hierarchy_per_frame_and_count_only_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031EB80
// Name: _dynamic_initializer_for__vprof_generate_report_AI_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_generate_report_AI_command__()
{
  ConCommand::ConCommand(
    this: &vprof_generate_report_AI_command,
    pName: "vprof_generate_report_AI",
    callback: vprof_generate_report_AI,
    pHelpString: "Generate a report to the console.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_generate_report_AI_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031EBB0
// Name: _dynamic_initializer_for__vprof_generate_report_AI_only_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_generate_report_AI_only_command__()
{
  ConCommand::ConCommand(
    this: &vprof_generate_report_AI_only_command,
    pName: "vprof_generate_report_AI_only",
    callback: vprof_generate_report_AI_only,
    pHelpString: "Generate a report to the console.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_generate_report_AI_only_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031EBE0
// Name: _dynamic_initializer_for__vprof_generate_report_map_load_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_generate_report_map_load_command__()
{
  ConCommand::ConCommand(
    this: &vprof_generate_report_map_load_command,
    pName: "vprof_generate_report_map_load",
    callback: vprof_generate_report_map_load,
    pHelpString: "Generate a report to the console.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_generate_report_map_load_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031ECB0
// Name: _dynamic_initializer_for__vprof_record_start_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_record_start_command__()
{
  ConCommand::ConCommand(
    this: &vprof_record_start_command,
    pName: "vprof_record_start",
    callback: vprof_record_start,
    pHelpString: "Start recording vprof data for playback later.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_record_start_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031ECE0
// Name: _dynamic_initializer_for__vprof_record_stop_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_record_stop_command__()
{
  ConCommand::ConCommand(
    this: &vprof_record_stop_command,
    pName: "vprof_record_stop",
    callback: vprof_record_stop,
    pHelpString: "Stop recording vprof data",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_record_stop_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031ED10
// Name: _dynamic_initializer_for__vprof_to_csv_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_to_csv_command__()
{
  ConCommand::ConCommand(
    this: &vprof_to_csv_command,
    pName: "vprof_to_csv",
    callback: vprof_to_csv,
    pHelpString: "Convert a recorded .vprof file to .csv.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_to_csv_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031ED40
// Name: _dynamic_initializer_for__vprof_playback_start_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_playback_start_command__()
{
  ConCommand::ConCommand(
    this: &vprof_playback_start_command,
    pName: "vprof_playback_start",
    callback: vprof_playback_start,
    pHelpString: "Start playing back a recorded .vprof file.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_playback_start_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031ED70
// Name: _dynamic_initializer_for__vprof_playback_stop_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_playback_stop_command__()
{
  ConCommand::ConCommand(
    this: &vprof_playback_stop_command,
    pName: "vprof_playback_stop",
    callback: vprof_playback_stop,
    pHelpString: "Stop playing back a recorded .vprof file.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_playback_stop_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031EDA0
// Name: _dynamic_initializer_for__vprof_playback_step_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_playback_step_command__()
{
  ConCommand::ConCommand(
    this: &vprof_playback_step_command,
    pName: "vprof_playback_step",
    callback: VProfPlayback_Step,
    pHelpString: "While playing back a .vprof file, step to the next tick.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_playback_step_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031EDD0
// Name: _dynamic_initializer_for__vprof_playback_stepback_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_playback_stepback_command__()
{
  ConCommand::ConCommand(
    this: &vprof_playback_stepback_command,
    pName: "vprof_playback_stepback",
    callback: VProfPlayback_StepBack,
    pHelpString: "While playing back a .vprof file, step to the previous tick.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_playback_stepback_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031EE00
// Name: _dynamic_initializer_for__vprof_playback_average_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_playback_average_command__()
{
  ConCommand::ConCommand(
    this: &vprof_playback_average_command,
    pName: "vprof_playback_average",
    callback: vprof_playback_average,
    pHelpString: "Average the next N frames.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_playback_average_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031F600
// Name: _dynamic_initializer_for__vprof_adddebuggroup1_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_adddebuggroup1_command__()
{
  ConCommand::ConCommand(
    this: &vprof_adddebuggroup1_command,
    pName: "vprof_adddebuggroup1",
    callback: vprof_adddebuggroup1,
    pHelpString: "add a new budget group dynamically for debugging",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_adddebuggroup1_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FF40
// Name: _dynamic_initializer_for__vprof_graph__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_graph__()
{
  ConVar::ConVar(
    this: &vprof_graph,
    pName: "vprof_graph",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Draw the vprof graph.");
  return atexit(func: dynamic_atexit_destructor_for__vprof_graph__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FF70
// Name: _dynamic_initializer_for__vprof_graphwidth__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_graphwidth__()
{
  ConVar::ConVar(this: &vprof_graphwidth, pName: "vprof_graphwidth", pDefaultValue: "512", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__vprof_graphwidth__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FFA0
// Name: _dynamic_initializer_for__vprof_graphheight__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_graphheight__()
{
  ConVar::ConVar(this: &vprof_graphheight, pName: "vprof_graphheight", pDefaultValue: "256", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__vprof_graphheight__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FFD0
// Name: _dynamic_initializer_for__vprof_siblingprev__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_siblingprev__()
{
  ConCommand::ConCommand(
    this: &vprof_siblingprev,
    pName: "vprof_prevsibling",
    callback: IN_VProfPrevSibling,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_siblingprev__);
}

//------------------------------------------------------------------------------
// Address: 0x10320000
// Name: _dynamic_initializer_for__vprof_siblingnext__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_siblingnext__()
{
  ConCommand::ConCommand(
    this: &vprof_siblingnext,
    pName: "vprof_nextsibling",
    callback: IN_VProfNextSibling,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_siblingnext__);
}

//------------------------------------------------------------------------------
// Address: 0x10320030
// Name: _dynamic_initializer_for__vprof_parent__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_parent__()
{
  ConCommand::ConCommand(
    this: &vprof_parent,
    pName: "vprof_parent",
    callback: IN_VProfParent,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_parent__);
}

//------------------------------------------------------------------------------
// Address: 0x10320060
// Name: _dynamic_initializer_for__vprof_child__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_child__()
{
  ConCommand::ConCommand(
    this: &vprof_child,
    pName: "vprof_child",
    callback: IN_VProfChild,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_child__);
}

//------------------------------------------------------------------------------
// Address: 0x10320090
// Name: _dynamic_initializer_for__vprof_verbose__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_verbose__()
{
  ConVar::ConVar(
    this: &vprof_verbose,
    pName: "vprof_verbose",
    pDefaultValue: "1",
    flags: 128,
    pHelpString: "Set to one to show average and peak times");
  return atexit(func: dynamic_atexit_destructor_for__vprof_verbose__);
}

//------------------------------------------------------------------------------
// Address: 0x103200C0
// Name: _dynamic_initializer_for__vprof_unaccounted_limit__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_unaccounted_limit__()
{
  ConVar::ConVar(
    this: &vprof_unaccounted_limit,
    pName: "vprof_unaccounted_limit",
    pDefaultValue: "0.3",
    flags: 128,
    pHelpString: "number of milliseconds that a node must exceed to turn red in the vprof panel");
  return atexit(func: dynamic_atexit_destructor_for__vprof_unaccounted_limit__);
}

//------------------------------------------------------------------------------
// Address: 0x103200F0
// Name: _dynamic_initializer_for__vprof_warningmsec__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_warningmsec__()
{
  ConVar::ConVar(
    this: &vprof_warningmsec,
    pName: "vprof_warningmsec",
    pDefaultValue: "10",
    flags: 128,
    pHelpString: "Above this many milliseconds render the label red to indicate slow code.");
  return atexit(func: dynamic_atexit_destructor_for__vprof_warningmsec__);
}

//------------------------------------------------------------------------------
// Address: 0x10320120
// Name: _dynamic_initializer_for__vprof_expand_all_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_expand_all_command__()
{
  ConCommand::ConCommand(
    this: &vprof_expand_all_command,
    pName: "vprof_expand_all",
    callback: vprof_expand_all,
    pHelpString: "Expand the whole vprof tree",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_expand_all_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10320150
// Name: _dynamic_initializer_for__vprof_collapse_all_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_collapse_all_command__()
{
  ConCommand::ConCommand(
    this: &vprof_collapse_all_command,
    pName: "vprof_collapse_all",
    callback: vprof_collapse_all,
    pHelpString: "Collapse the whole vprof tree",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_collapse_all_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10320180
// Name: _dynamic_initializer_for__vprof_expand_group_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_expand_group_command__()
{
  ConCommand::ConCommand(
    this: &vprof_expand_group_command,
    pName: "vprof_expand_group",
    callback: vprof_expand_group,
    pHelpString: "Expand a budget group in the vprof tree by name",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vprof_expand_group_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10320210
// Name: _dynamic_initializer_for__vprof_scope__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_scope__()
{
  ConVar::ConVar(
    this: &vprof_scope,
    pName: "vprof_scope",
    pDefaultValue: defaultValue,
    flags: 0,
    pHelpString: "Set a specific scope to start showing vprof tree",
    bMin: false,
    fMin: 0.0,
    bMax: false,
    fMax: 0.0,
    callback: ChangeVProfScopeCallback);
  return atexit(func: dynamic_atexit_destructor_for__vprof_scope__);
}

//------------------------------------------------------------------------------
// Address: 0x10322AD0
// Name: _dynamic_atexit_destructor_for__vprof_remote_start_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_remote_start_command__()
{
  ConCommand::~ConCommand(this: &vprof_remote_start_command);
}

//------------------------------------------------------------------------------
// Address: 0x10322AE0
// Name: _dynamic_atexit_destructor_for__vprof_remote_stop_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_remote_stop_command__()
{
  ConCommand::~ConCommand(this: &vprof_remote_stop_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325780
// Name: _dynamic_atexit_destructor_for__vprof_server_spike_threshold__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_server_spike_threshold__()
{
  ConVar::~ConVar(this: &vprof_server_spike_threshold);
}

//------------------------------------------------------------------------------
// Address: 0x10325790
// Name: _dynamic_atexit_destructor_for__vprof_server_thread__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_server_thread__()
{
  ConVar::~ConVar(this: &vprof_server_thread);
}

//------------------------------------------------------------------------------
// Address: 0x10326F70
// Name: _dynamic_atexit_destructor_for__vprof_dump_spikes__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_dump_spikes__()
{
  ConVar::~ConVar(this: &vprof_dump_spikes);
}

//------------------------------------------------------------------------------
// Address: 0x10326F80
// Name: _dynamic_atexit_destructor_for__vprof_dump_spikes_terse__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_dump_spikes_terse__()
{
  ConVar::~ConVar(this: &vprof_dump_spikes_terse);
}

//------------------------------------------------------------------------------
// Address: 0x10326F90
// Name: _dynamic_atexit_destructor_for__vprof_dump_spikes_hierarchy__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_dump_spikes_hierarchy__()
{
  ConVar::~ConVar(this: &vprof_dump_spikes_hierarchy);
}

//------------------------------------------------------------------------------
// Address: 0x10326FA0
// Name: _dynamic_atexit_destructor_for__vprof_dump_spikes_node__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_dump_spikes_node__()
{
  ConVar::~ConVar(this: &vprof_dump_spikes_node);
}

//------------------------------------------------------------------------------
// Address: 0x10326FB0
// Name: _dynamic_atexit_destructor_for__vprof_dump_spikes_budget_group__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_dump_spikes_budget_group__()
{
  ConVar::~ConVar(this: &vprof_dump_spikes_budget_group);
}

//------------------------------------------------------------------------------
// Address: 0x10326FC0
// Name: _dynamic_atexit_destructor_for__vprof_dump_oninterval__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_dump_oninterval__()
{
  ConVar::~ConVar(this: &vprof_dump_oninterval);
}

//------------------------------------------------------------------------------
// Address: 0x10326FD0
// Name: _dynamic_atexit_destructor_for__vprof_counters__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_counters__()
{
  ConVar::~ConVar(this: &vprof_counters);
}

//------------------------------------------------------------------------------
// Address: 0x10326FE0
// Name: _dynamic_atexit_destructor_for__vprof_counters_show_minmax__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_counters_show_minmax__()
{
  ConVar::~ConVar(this: &vprof_counters_show_minmax);
}

//------------------------------------------------------------------------------
// Address: 0x10326FF0
// Name: _dynamic_atexit_destructor_for__vprof_dump_counters_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_dump_counters_command__()
{
  ConCommand::~ConCommand(this: &vprof_dump_counters_command);
}

//------------------------------------------------------------------------------
// Address: 0x10327010
// Name: _dynamic_atexit_destructor_for__vprof_vtune_group_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_vtune_group_command__()
{
  ConCommand::~ConCommand(this: &vprof_vtune_group_command);
}

//------------------------------------------------------------------------------
// Address: 0x10327020
// Name: _dynamic_atexit_destructor_for__vprof_dump_groupnames_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_dump_groupnames_command__()
{
  ConCommand::~ConCommand(this: &vprof_dump_groupnames_command);
}

//------------------------------------------------------------------------------
// Address: 0x10327030
// Name: _dynamic_atexit_destructor_for__vprof_cachemiss_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_cachemiss_command__()
{
  ConCommand::~ConCommand(this: &vprof_cachemiss_command);
}

//------------------------------------------------------------------------------
// Address: 0x10327040
// Name: _dynamic_atexit_destructor_for__vprof_cachemiss_on_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_cachemiss_on_command__()
{
  ConCommand::~ConCommand(this: &vprof_cachemiss_on_command);
}

//------------------------------------------------------------------------------
// Address: 0x10327050
// Name: _dynamic_atexit_destructor_for__vprof_cachemiss_off_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_cachemiss_off_command__()
{
  ConCommand::~ConCommand(this: &vprof_cachemiss_off_command);
}

//------------------------------------------------------------------------------
// Address: 0x10327060
// Name: _dynamic_atexit_destructor_for__vprof_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_command__()
{
  ConCommand::~ConCommand(this: &vprof_command);
}

//------------------------------------------------------------------------------
// Address: 0x10327070
// Name: _dynamic_atexit_destructor_for__vprof_on_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_on_command__()
{
  ConCommand::~ConCommand(this: &vprof_on_command);
}

//------------------------------------------------------------------------------
// Address: 0x10327090
// Name: _dynamic_atexit_destructor_for__vprof_off_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_off_command__()
{
  ConCommand::~ConCommand(this: &vprof_off_command);
}

//------------------------------------------------------------------------------
// Address: 0x103270A0
// Name: _dynamic_atexit_destructor_for__vprof_reset_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_reset_command__()
{
  ConCommand::~ConCommand(this: &vprof_reset_command);
}

//------------------------------------------------------------------------------
// Address: 0x103270B0
// Name: _dynamic_atexit_destructor_for__vprof_reset_peaks_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_reset_peaks_command__()
{
  ConCommand::~ConCommand(this: &vprof_reset_peaks_command);
}

//------------------------------------------------------------------------------
// Address: 0x103270C0
// Name: _dynamic_atexit_destructor_for__vprof_generate_report_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_generate_report_command__()
{
  ConCommand::~ConCommand(this: &vprof_generate_report_command);
}

//------------------------------------------------------------------------------
// Address: 0x103270D0
// Name: _dynamic_atexit_destructor_for__vprof_generate_report_budget_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_generate_report_budget_command__()
{
  ConCommand::~ConCommand(this: &vprof_generate_report_budget_command);
}

//------------------------------------------------------------------------------
// Address: 0x103270E0
// Name: _dynamic_atexit_destructor_for__vprof_generate_report_hierarchy_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_generate_report_hierarchy_command__()
{
  ConCommand::~ConCommand(this: &vprof_generate_report_hierarchy_command);
}

//------------------------------------------------------------------------------
// Address: 0x103270F0
// Name: _dynamic_atexit_destructor_for__vprof_generate_report_hierarchy_per_frame_and_count_only_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_generate_report_hierarchy_per_frame_and_count_only_command__()
{
  ConCommand::~ConCommand(this: &vprof_generate_report_hierarchy_per_frame_and_count_only_command);
}

//------------------------------------------------------------------------------
// Address: 0x10327100
// Name: _dynamic_atexit_destructor_for__vprof_generate_report_AI_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_generate_report_AI_command__()
{
  ConCommand::~ConCommand(this: &vprof_generate_report_AI_command);
}

//------------------------------------------------------------------------------
// Address: 0x10327110
// Name: _dynamic_atexit_destructor_for__vprof_generate_report_AI_only_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_generate_report_AI_only_command__()
{
  ConCommand::~ConCommand(this: &vprof_generate_report_AI_only_command);
}

//------------------------------------------------------------------------------
// Address: 0x10327120
// Name: _dynamic_atexit_destructor_for__vprof_generate_report_map_load_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_generate_report_map_load_command__()
{
  ConCommand::~ConCommand(this: &vprof_generate_report_map_load_command);
}

//------------------------------------------------------------------------------
// Address: 0x103271C0
// Name: _dynamic_atexit_destructor_for__vprof_record_start_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_record_start_command__()
{
  ConCommand::~ConCommand(this: &vprof_record_start_command);
}

//------------------------------------------------------------------------------
// Address: 0x103271D0
// Name: _dynamic_atexit_destructor_for__vprof_record_stop_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_record_stop_command__()
{
  ConCommand::~ConCommand(this: &vprof_record_stop_command);
}

//------------------------------------------------------------------------------
// Address: 0x103271E0
// Name: _dynamic_atexit_destructor_for__vprof_to_csv_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_to_csv_command__()
{
  ConCommand::~ConCommand(this: &vprof_to_csv_command);
}

//------------------------------------------------------------------------------
// Address: 0x103271F0
// Name: _dynamic_atexit_destructor_for__vprof_playback_start_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_playback_start_command__()
{
  ConCommand::~ConCommand(this: &vprof_playback_start_command);
}

//------------------------------------------------------------------------------
// Address: 0x10327200
// Name: _dynamic_atexit_destructor_for__vprof_playback_stop_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_playback_stop_command__()
{
  ConCommand::~ConCommand(this: &vprof_playback_stop_command);
}

//------------------------------------------------------------------------------
// Address: 0x10327210
// Name: _dynamic_atexit_destructor_for__vprof_playback_step_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_playback_step_command__()
{
  ConCommand::~ConCommand(this: &vprof_playback_step_command);
}

//------------------------------------------------------------------------------
// Address: 0x10327220
// Name: _dynamic_atexit_destructor_for__vprof_playback_stepback_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_playback_stepback_command__()
{
  ConCommand::~ConCommand(this: &vprof_playback_stepback_command);
}

//------------------------------------------------------------------------------
// Address: 0x10327230
// Name: _dynamic_atexit_destructor_for__vprof_playback_average_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_playback_average_command__()
{
  ConCommand::~ConCommand(this: &vprof_playback_average_command);
}

//------------------------------------------------------------------------------
// Address: 0x10327560
// Name: _dynamic_atexit_destructor_for__vprof_adddebuggroup1_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_adddebuggroup1_command__()
{
  ConCommand::~ConCommand(this: &vprof_adddebuggroup1_command);
}

//------------------------------------------------------------------------------
// Address: 0x103277D0
// Name: _dynamic_atexit_destructor_for__vprof_graph__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_graph__()
{
  ConVar::~ConVar(this: &vprof_graph);
}

//------------------------------------------------------------------------------
// Address: 0x103277E0
// Name: _dynamic_atexit_destructor_for__vprof_graphwidth__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_graphwidth__()
{
  ConVar::~ConVar(this: &vprof_graphwidth);
}

//------------------------------------------------------------------------------
// Address: 0x103277F0
// Name: _dynamic_atexit_destructor_for__vprof_graphheight__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_graphheight__()
{
  ConVar::~ConVar(this: &vprof_graphheight);
}

//------------------------------------------------------------------------------
// Address: 0x10327800
// Name: _dynamic_atexit_destructor_for__vprof_siblingprev__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_siblingprev__()
{
  ConCommand::~ConCommand(this: &vprof_siblingprev);
}

//------------------------------------------------------------------------------
// Address: 0x10327810
// Name: _dynamic_atexit_destructor_for__vprof_siblingnext__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_siblingnext__()
{
  ConCommand::~ConCommand(this: &vprof_siblingnext);
}

//------------------------------------------------------------------------------
// Address: 0x10327820
// Name: _dynamic_atexit_destructor_for__vprof_parent__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_parent__()
{
  ConCommand::~ConCommand(this: &vprof_parent);
}

//------------------------------------------------------------------------------
// Address: 0x10327830
// Name: _dynamic_atexit_destructor_for__vprof_child__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_child__()
{
  ConCommand::~ConCommand(this: &vprof_child);
}

//------------------------------------------------------------------------------
// Address: 0x10327840
// Name: _dynamic_atexit_destructor_for__vprof_verbose__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_verbose__()
{
  ConVar::~ConVar(this: &vprof_verbose);
}

//------------------------------------------------------------------------------
// Address: 0x10327850
// Name: _dynamic_atexit_destructor_for__vprof_unaccounted_limit__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_unaccounted_limit__()
{
  ConVar::~ConVar(this: &vprof_unaccounted_limit);
}

//------------------------------------------------------------------------------
// Address: 0x10327860
// Name: _dynamic_atexit_destructor_for__vprof_warningmsec__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_warningmsec__()
{
  ConVar::~ConVar(this: &vprof_warningmsec);
}

//------------------------------------------------------------------------------
// Address: 0x10327870
// Name: _dynamic_atexit_destructor_for__vprof_expand_all_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_expand_all_command__()
{
  ConCommand::~ConCommand(this: &vprof_expand_all_command);
}

//------------------------------------------------------------------------------
// Address: 0x10327880
// Name: _dynamic_atexit_destructor_for__vprof_collapse_all_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_collapse_all_command__()
{
  ConCommand::~ConCommand(this: &vprof_collapse_all_command);
}

//------------------------------------------------------------------------------
// Address: 0x10327890
// Name: _dynamic_atexit_destructor_for__vprof_expand_group_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_expand_group_command__()
{
  ConCommand::~ConCommand(this: &vprof_expand_group_command);
}

//------------------------------------------------------------------------------
// Address: 0x103278C0
// Name: _dynamic_atexit_destructor_for__vprof_scope__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_scope__()
{
  ConVar::~ConVar(this: &vprof_scope);
}

//------------------------------------------------------------------------------
// Address: 0x10313CC0
// Name: _dynamic_initializer_for__rpt_screenshot_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__rpt_screenshot_command__()
{
  ConCommand::ConCommand(
    this: &rpt_screenshot_command,
    pName: "rpt_screenshot",
    callback: rpt_screenshot,
    pHelpString: defaultValue,
    flags: 131088,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__rpt_screenshot_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10313CF0
// Name: _dynamic_initializer_for__rpt_download_log_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__rpt_download_log_command__()
{
  ConCommand::ConCommand(
    this: &rpt_download_log_command,
    pName: "rpt_download_log",
    callback: rpt_download_log,
    pHelpString: defaultValue,
    flags: 131088,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__rpt_download_log_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031AAB0
// Name: _dynamic_initializer_for__g_MainThreadId__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DWORD dynamic_initializer_for__g_MainThreadId__()
{
  DWORD result; // eax

  result = GetCurrentThreadId();
  g_MainThreadId = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1031E7E0
// Name: _dynamic_initializer_for__g_VProfTargetThread__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DWORD dynamic_initializer_for__g_VProfTargetThread__()
{
  DWORD result; // eax

  result = GetCurrentThreadId();
  g_VProfTargetThread = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1031E880
// Name: _dynamic_initializer_for__spike_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__spike_command__()
{
  ConCommand::ConCommand(
    this: &spike_command,
    pName: "spike",
    callback: spike,
    pHelpString: "generates a fake spike",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__spike_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031EC10
// Name: _dynamic_initializer_for__g_VProfExport__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_VProfExport__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_VProfExport__);
}

//------------------------------------------------------------------------------
// Address: 0x1031EC20
// Name: _dynamic_initializer_for____g_CreateCVProfExportIVProfExport_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCVProfExportIVProfExport_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCVProfExportIVProfExport_reg,
           fn: _CreateCVProfExportIVProfExport_interface,
           pName: "VProfExport001");
}

//------------------------------------------------------------------------------
// Address: 0x1031F630
// Name: _dynamic_initializer_for__startshowbudget__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__startshowbudget__()
{
  ConCommand::ConCommand(
    this: &startshowbudget,
    pName: "+showbudget",
    callback: IN_BudgetDown,
    pHelpString: defaultValue,
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__startshowbudget__);
}

//------------------------------------------------------------------------------
// Address: 0x1031F660
// Name: _dynamic_initializer_for__endshowbudget__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__endshowbudget__()
{
  ConCommand::ConCommand(
    this: &endshowbudget,
    pName: "-showbudget",
    callback: IN_BudgetUp,
    pHelpString: defaultValue,
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__endshowbudget__);
}

//------------------------------------------------------------------------------
// Address: 0x103201B0
// Name: _dynamic_initializer_for__startshowvprof__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__startshowvprof__()
{
  ConCommand::ConCommand(
    this: &startshowvprof,
    pName: "+showvprof",
    callback: IN_VProfDown,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__startshowvprof__);
}

//------------------------------------------------------------------------------
// Address: 0x103201E0
// Name: _dynamic_initializer_for__endshowvprof__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__endshowvprof__()
{
  ConCommand::ConCommand(
    this: &endshowvprof,
    pName: "-showvprof",
    callback: IN_VProfUp,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__endshowvprof__);
}

//------------------------------------------------------------------------------
// Address: 0x10322AF0
// Name: _dynamic_atexit_destructor_for__rpt_screenshot_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__rpt_screenshot_command__()
{
  ConCommand::~ConCommand(this: &rpt_screenshot_command);
}

//------------------------------------------------------------------------------
// Address: 0x10322B00
// Name: _dynamic_atexit_destructor_for__rpt_download_log_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__rpt_download_log_command__()
{
  ConCommand::~ConCommand(this: &rpt_download_log_command);
}

//------------------------------------------------------------------------------
// Address: 0x10327000
// Name: _dynamic_atexit_destructor_for__spike_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__spike_command__()
{
  ConCommand::~ConCommand(this: &spike_command);
}

//------------------------------------------------------------------------------
// Address: 0x10327130
// Name: _dynamic_atexit_destructor_for__rpt_vprof_time__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__rpt_vprof_time__()
{
  ConVar::~ConVar(this: &rpt_vprof_time);
}

//------------------------------------------------------------------------------
// Address: 0x10327240
// Name: _dynamic_atexit_destructor_for__g_VProfRecorder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_VProfRecorder__()
{
  CUtlDict<int,int>::RemoveAll(this: &g_VProfRecorder.m_PooledStrings);
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>(this: &g_VProfRecorder.m_PooledStrings.m_Elements.m_Tree);
  CVProfile::~CVProfile(this: &g_VProfRecorder);
}

//------------------------------------------------------------------------------
// Address: 0x10327570
// Name: _dynamic_atexit_destructor_for__startshowbudget__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__startshowbudget__()
{
  ConCommand::~ConCommand(this: &startshowbudget);
}

//------------------------------------------------------------------------------
// Address: 0x10327580
// Name: _dynamic_atexit_destructor_for__endshowbudget__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__endshowbudget__()
{
  ConCommand::~ConCommand(this: &endshowbudget);
}

//------------------------------------------------------------------------------
// Address: 0x103278A0
// Name: _dynamic_atexit_destructor_for__startshowvprof__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__startshowvprof__()
{
  ConCommand::~ConCommand(this: &startshowvprof);
}

//------------------------------------------------------------------------------
// Address: 0x103278B0
// Name: _dynamic_atexit_destructor_for__endshowvprof__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__endshowvprof__()
{
  ConCommand::~ConCommand(this: &endshowvprof);
}

} // namespace engine_xlsp
